#!/usr/bin/env python3
"""Byte-match one function: compile its TU with the retail toolchain and diff its machine code
against the original image (from your GOG exe), relocated operands masked.

The function is looked up by name in Rayman2.exe/status.json (retail address, size, source file);
the TU's flags and toolchain come from Rayman2.exe/tu.json. Relocated operands (call rel32,
disp32 globals) are masked on both sides and their targets listed: they are compared by the
link, not here.

  --asm   side-by-side disassembly (retail | ours), aligned on instruction text, addresses masked
  --flags override the TU's flags for this compile (e.g. --flags G6), to try a configuration

Needs: pip install capstone (for --asm and the shape triage)
Usage: python tools/byte_match.py NAME [--asm [--all]] [--flags F1,F2] [--obj OBJ] [--quiet]
Exit: 0 EXACT, 1 MISMATCH, 2 error.
"""
import argparse
import difflib
import json
import os
import re
import struct
import sys
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import build  # noqa: E402
import objfn  # noqa: E402
import retail  # noqa: E402

REL32, DIR32 = 0x14, 0x06
WORK = os.path.join(build.BUILD, "work")


def derive_len(raw):
    n = len(raw)
    while n > 1 and raw[n - 1] in (0x90, 0xCC):
        n -= 1
    return n


def status_row(name):
    rows = json.load(open(os.path.join(build.EXE_DIR, "status.json")))
    hit = [r for r in rows if r["name"] == name] or \
          [r for r in rows if retail.norm(r["name"]) == retail.norm(name)]
    if not hit:
        sys.exit("%s is not in Rayman2.exe/status.json" % name)
    return hit[0]


def compile_tu(a, src, flags=None):
    tus, base = build.load_tus()
    tu = next((t for t in tus if t["src"] == src), None)
    if tu is None:
        sys.exit("%s is not a TU in tu.json" % src)
    _, obj, err = build.compile_one(a, base, tu, WORK, flags)
    if err:
        sys.exit("compile failed: %s" % err)
    return obj


def shape(ret, ours):
    """'same-shape' when both bodies have the same length and the same instructions modulo operands
    (register choice / order only); else 'structural' with the first reason."""
    if len(ret) != len(ours):
        return "structural", "length %d vs retail %d" % (len(ours), len(ret))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

    def mnems(b):
        out, n = [], 0
        for ins in md.disasm(bytes(b), 0):
            out.append(ins.mnemonic)
            n = ins.address + ins.size
        return out, n
    (mr, nr), (mo, no) = mnems(ret), mnems(ours)
    if nr != len(ret) or no != len(ours):
        return "structural", "undecodable tail"
    if sorted(mr) != sorted(mo):
        d = (Counter(mo) - Counter(mr)) + (Counter(mr) - Counter(mo))
        return "structural", "instructions differ: " + ", ".join(sorted(d))[:120]
    return "same-shape", "same length and instructions; registers/order differ"


def compare(obj, name, addr, length, orig):
    raw, relocs, _sec = objfn.extract(obj, name)
    got = bytearray(raw[:length])
    want = bytearray(orig.read(addr, length))
    sites = [r for r in relocs if r["off"] + 4 <= length]
    g, w = bytearray(got), bytearray(want)
    for r in sites:
        g[r["off"]:r["off"] + 4] = w[r["off"]:r["off"] + 4] = b"\0\0\0\0"
    diffs = [i for i in range(min(len(g), len(w))) if g[i] != w[i]]
    verdict = "FAIL" if len(got) < length else ("MISMATCH" if diffs else "EXACT")
    shp = (None, None)
    if verdict == "MISMATCH":
        ob = bytearray(raw[:derive_len(raw)])
        rb = bytearray(orig.read(addr, length))
        if len(rb) == len(ob):
            for r in relocs:
                if r["off"] + 4 <= len(ob):
                    rb[r["off"]:r["off"] + 4] = ob[r["off"]:r["off"] + 4] = b"\0\0\0\0"
        shp = shape(rb, ob)
    targets = []
    for r in sites:
        v = struct.unpack_from("<i", want, r["off"])[0]
        tgt = (addr + r["off"] + 4 + v) & 0xFFFFFFFF if r["type"] == REL32 else v & 0xFFFFFFFF
        targets.append((r["off"], {REL32: "rel32", DIR32: "dir32"}.get(r["type"], hex(r["type"])), tgt, r["target"]))
    return dict(raw=raw, relocs=relocs, got=got, want=want, diffs=diffs, verdict=verdict, shape=shp,
                targets=targets)


def asm_diff(ret, ret_addr, ours, relocs, show_all):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

    def listing(code, rel=None):
        out = []
        for ins in md.disasm(bytes(code), 0):
            txt = "%s %s" % (ins.mnemonic, ins.op_str)
            for r in rel or ():
                if ins.address <= r["off"] < ins.address + ins.size:
                    txt += "  ; " + r["target"]
            out.append((ins.address, txt))
        return out

    def key(t):
        return re.sub(r"0x[0-9a-f]{5,}", "ADDR", t.split("  ;")[0])
    lr, lo = listing(ret), listing(ours, relocs)
    sm = difflib.SequenceMatcher(None, [key(t) for _, t in lr], [key(t) for _, t in lo], autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal" and not show_all:
            print("   ... %d equal" % (i2 - i1))
            continue
        for k in range(max(i2 - i1, j2 - j1)):
            l = "%04x %-38s" % lr[i1 + k] if i1 + k < i2 else " " * 43
            r = "%04x %s" % lo[j1 + k] if j1 + k < j2 else ""
            print("%s %s | %s" % ("=" if tag == "equal" else "*", l, r))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name")
    build.add_path_args(ap)
    ap.add_argument("--flags", default=None, help="comma-separated cl flags instead of the TU's")
    ap.add_argument("--obj", help="use this .obj instead of compiling")
    ap.add_argument("--asm", action="store_true")
    ap.add_argument("--all", action="store_true", help="--asm: print equal lines too")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    build.resolve_paths(a, need=("gog",) if a.obj else ("vc5", "vc6", "gog"))
    row = status_row(a.name)
    addr, length = int(row["addr"], 16), row["len"]
    flags = [f for f in a.flags.split(",") if f] if a.flags is not None else None
    obj = a.obj or compile_tu(a, row["src"], flags)
    orig = retail.Image(retail.original_image(open(a.gog, "rb").read())[0])
    r = compare(obj, row["name"], addr, length, orig)
    if a.quiet:
        line = "%s %s %s len=%d relocs=%d diffs=%d" % (r["verdict"], row["name"], row["addr"], length,
                                                       len(r["targets"]), len(r["diffs"]))
        if r["diffs"]:
            line += " first=0x%x" % r["diffs"][0]
        if r["shape"][0]:
            line += " shape=%s (%s)" % r["shape"]
        print(line)
    else:
        print("function: %s @ %s  len=%d  src=%s  (status.json: %s)" % (row["name"], row["addr"], length,
                                                                     row["src"], row["verdict"]))
        print("retail  : " + r["want"].hex())
        print("ours    : " + r["got"].hex())
        for off, kind, tgt, sym in r["targets"]:
            print("  reloc +0x%-3x %-5s retail -> 0x%08X   ours -> %s" % (off, kind, tgt, sym))
        if r["diffs"]:
            print("diffs   : %d at %s" % (len(r["diffs"]), ", ".join("0x%x" % d for d in r["diffs"][:32])))
        if r["shape"][0]:
            print("shape   : %s (%s)" % r["shape"])
        print("RESULT: %s" % r["verdict"])
    if a.asm:
        ours = r["raw"][:derive_len(r["raw"])]
        asm_diff(orig.read(addr, length), addr, ours, r["relocs"], a.all)
    return {"EXACT": 0, "MISMATCH": 1}.get(r["verdict"], 2)


if __name__ == "__main__":
    sys.exit(main())
