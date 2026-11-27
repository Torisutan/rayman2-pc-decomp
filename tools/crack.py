#!/usr/bin/env python3
"""Post-link crack step: apply the GOG crack's behaviour to our linked Rayman2.exe.

Our build is the original image, copy protection included. This step reproduces what each GOG
crack run does, at the owning function in OUR layout (through the LINK map), and writes a patched
copy. Every byte it copies comes from your own GOG exe at run time; the repo holds only addresses
and the translation tables (Rayman2.exe/crack.json).

Translations:
  entry_ret    a protection function whose GOG entry is `ret` / `ret n`: same bytes at our entry
  semantic     a hand-written replacement at our entry
  at_offset    GOG bytes at the same offset, where our instruction layout equals the original's
  call_nop     NOP every call of one callee in our function
  transplant   the cracked GOG body is copied into a new .crack section, re-addressed to our
               symbols, and our entry jumps there
  crack_block / crack_data   crack-authored code and data, copied whole

Needs: pip install capstone
Usage: python tools/crack.py --gog Rayman2.exe [--exe build/Rayman2.exe] [--map build/Rayman2.map]
                             [--out build/Rayman2_cracked.exe]
"""
import argparse
import bisect
import json
import os
import struct
import sys

import capstone
from capstone import x86 as cx

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import retail  # noqa: E402

EXE_DIR = os.path.join(ROOT, "Rayman2.exe")
CRACK_SECTION = b".crack\0\0"


def _md():
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    return md


def load_tables():
    t = json.load(open(os.path.join(EXE_DIR, "crack.json")))
    ints = lambda d: {int(k, 16): v for k, v in d.items()}  # noqa: E731
    return {k: ints(v) for k, v in t.items()}


def ledger_by_addr():
    rows = json.load(open(os.path.join(EXE_DIR, "status.json")))
    return {int(r["addr"], 16): (r["name"], r) for r in rows}


def our_symbol_va(by_name, name, src):
    return retail.our_va(by_name, name, os.path.splitext(os.path.basename(src.strip()))[0].lower() + ".obj")


def transplant_body(fn, end, sec_va, gog_bytes, resolve):
    """GOG bytes [fn, end) re-addressed for placement at sec_va. -> (code, data_tail, unresolved)."""
    code = bytearray(gog_bytes(fn, end - fn))
    data, unresolved = bytearray(), []

    def at(v, size=4):
        if fn <= v < end:
            return sec_va + (v - fn)
        r = resolve(v, size)
        if r is None:
            unresolved.append("0x%08X" % v)
            return 0
        if isinstance(r, bytes):    # retail constant data with no symbol of ours: append to the section
            o = (end - fn) + len(data)
            data.extend(r)
            return sec_va + o
        return r

    def jump_table(table):
        """Copy a switch table that follows the body into the data tail, entries re-addressed."""
        while ((end - fn) + len(data)) % 4:
            data.append(0xCC)
        o = (end - fn) + len(data)
        n = 0
        while True:
            t = struct.unpack("<I", gog_bytes(table + 4 * n, 4))[0]
            if not fn <= t < end:
                break
            data.extend(struct.pack("<I", sec_va + (t - fn)))
            n += 1
        if not n:
            unresolved.append("jump table 0x%08X" % table)
        return sec_va + o
    for i in _md().disasm(bytes(code), fn):
        o = i.address - fn
        rel = i.group(capstone.CS_GRP_JUMP) or i.group(capstone.CS_GRP_CALL)
        for op in i.operands:
            if op.type == cx.X86_OP_IMM and rel and i.imm_size == 4:
                t = op.imm & 0xFFFFFFFF
                if not fn <= t < end:
                    struct.pack_into("<i", code, o + i.imm_offset, at(t) - (sec_va + o + i.size))
            elif op.type == cx.X86_OP_IMM and not rel and i.imm_size == 4 and 0x400000 <= (op.imm & 0xFFFFFFFF) < 0x600000:
                struct.pack_into("<I", code, o + i.imm_offset, at(op.imm & 0xFFFFFFFF))
            elif op.type == cx.X86_OP_MEM and 0x400000 <= (op.mem.disp & 0xFFFFFFFF) < 0x600000:
                disp = op.mem.disp & 0xFFFFFFFF
                if i.group(capstone.CS_GRP_JUMP) and op.mem.index and op.mem.scale == 4 and op.mem.base == 0:
                    struct.pack_into("<I", code, o + i.disp_offset, jump_table(disp))
                else:
                    struct.pack_into("<I", code, o + i.disp_offset, at(disp, op.size))
    return bytes(code), bytes(data), unresolved


def add_section(data, name, raw, characteristics=0x60000020):
    """Append a section to the PE in `data` (bytearray). -> its VA."""
    lay = retail.pe_layout(data)
    pe, opt = lay["pe"], lay["opt"]
    nsec = len(lay["secs"])
    hdr = opt + lay["opt_size"] + 40 * nsec
    if hdr + 40 > min(s["rawptr"] for s in lay["secs"] if s["rawptr"]):
        raise ValueError("no room for another section header")
    last = max(lay["secs"], key=lambda s: s["rva"])
    rva = retail.align(last["rva"] + max(last["vsize"], last["rawsize"]), lay["salign"])
    rawptr = retail.align(len(data), lay["falign"])
    rawsize = retail.align(len(raw), lay["falign"])
    data.extend(b"\0" * (rawptr - len(data)))
    data.extend(raw + b"\0" * (rawsize - len(raw)))
    struct.pack_into("<8sIIIIIIHHI", data, hdr, name, len(raw), rva, rawsize, rawptr, 0, 0, 0, 0, characteristics)
    struct.pack_into("<H", data, pe + 6, nsec + 1)
    struct.pack_into("<I", data, opt + 56, retail.align(rva + len(raw), lay["salign"]))   # SizeOfImage
    return lay["base"] + rva


def same_layout(our, orig, base_our, base_orig):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    a = [(i.mnemonic, i.size) for i in md.disasm(bytes(our), base_our)]
    b = [(i.mnemonic, i.size) for i in md.disasm(bytes(orig), base_orig)]
    return a == b and sum(s for _m, s in a) == len(our)


def make_resolver(by_name, byaddr, our_imports, orig, gog, names):
    """(retail VA, operand size) -> our VA (int), bytes to append to the crack section, or None."""
    ret_imports = retail.pe_imports(gog)
    ours_by_name = {}
    for va, nm in our_imports.items():
        ours_by_name.setdefault(nm, []).append(va)
    our_starts = sorted({h[0] for hs in by_name.values() for h in hs})
    text = next(s for s in orig.lay["secs"] if not s["writable"])
    text_lo = orig.lay["base"] + text["rva"]
    text_hi = text_lo + max(text["vsize"], text["rawsize"])

    def names_at(v):
        return set(names.get(v, ()))

    def sym_va(nm):
        # a CRT name maps to both its import thunk and its IAT slot: keep the thunk
        keys = (retail.norm("_" + nm) or nm, "_" + nm)
        hits = next(([h for h in by_name[k] if h[0] not in our_imports] for k in keys if k in by_name), [])
        return hits[0][0] if len(hits) == 1 else None

    def named(v):
        if v in byaddr:
            name, e = byaddr[v]
            return our_symbol_va(by_name, name, e["src"])
        cands = {sym_va(n) for n in names_at(v)} - {None}
        return cands.pop() if len(cands) == 1 else None

    def our_iat(slot):
        hits = ours_by_name.get(ret_imports.get(slot), [])
        return hits[0] if len(hits) == 1 else None

    def resolve(v, size=4):
        if v in ret_imports:
            return our_iat(v)
        r = named(v)
        if r is not None:
            return r
        if text_lo <= v < text_hi:
            b = orig.read(v, 6)
            if b[:2] == b"\xFF\x25":            # CRT thunk jmp [IAT]: same thunk on our IAT slot
                slot = our_iat(struct.unpack_from("<I", b, 2)[0])
                return b"\xFF\x25" + struct.pack("<I", slot) if slot else None
            return None
        for back in range(1, 0x100):           # inside an array/struct of ours: base + offset
            base = named(v - back)
            if base is None and (v - back in byaddr or names_at(v - back)):
                break                          # the nearest retail label bounds the object
            if base is not None:
                i = bisect.bisect_right(our_starts, base)
                nxt = our_starts[i] if i < len(our_starts) else base
                return base + back if base + back + size <= nxt else None
        s = orig.cstr(v)                       # string literal: copy it
        if s and len(s) >= 2 and all(32 <= c < 127 for c in s):
            return bytes(s) + b"\0"
        sec = orig.section_at(v)
        if sec and not sec["writable"]:        # read-only retail constant: copy it
            return bytes(orig.read(v, size))
        return None
    return resolve


def plan(by_name, gog, our_image=None, sec_va=None, our_imports=None):
    """-> (patches [(our_va, bytes, record)], records, crack-section bytes)."""
    tables = load_tables()
    SEMANTIC, AT_OFFSET, CALL_NOP = tables["semantic"], tables["at_offset"], tables["call_nop"]
    TRANSPLANT, CRACK_BLOCKS, CRACK_DATA = tables["transplant"], tables["crack_blocks"], tables["crack_data"]
    orig_bytes, runs = retail.original_image(gog)
    orig = retail.Image(orig_bytes)
    glay = retail.pe_layout(gog)
    byaddr = ledger_by_addr()
    starts = sorted(byaddr)
    patches, recs = [], []
    section, transplanted = bytearray(), {}

    def gog_bytes(va, n):
        o = retail.va_to_off(glay, va)
        return gog[o:o + n]
    resolve = make_resolver(by_name, byaddr, our_imports or {}, orig, gog, tables["names"]) if sec_va else None
    if resolve:
        base_resolve, remap = resolve, []    # [(retail lo, retail hi, section va of lo)]

        def resolve(v, size=4):
            for lo, hi, at in remap:
                if lo <= v < hi:
                    return at + (v - lo)
            return base_resolve(v, size)
        for lo, (hi, why) in sorted(CRACK_DATA.items()):
            remap.append((lo, hi, sec_va + len(section)))
            section.extend(gog_bytes(lo, hi - lo))
            section.extend(b"\0" * (-len(section) % 0x1000))
            recs.append(dict(retail_fn="0x%08X" % lo, action="crack_data", applied=True, reason=why))
        blocks, o = [], len(section)          # reserve every block's place first: blocks may cross-reference
        for lo, (hi, why) in sorted(CRACK_BLOCKS.items()):
            remap.append((lo, hi, sec_va + o))
            blocks.append((lo, hi, why, o))
            o += hi - lo + (-(hi - lo) % 16)
        for lo, hi, why, o in blocks:
            code, tail, unres = transplant_body(lo, hi, sec_va + o, gog_bytes, resolve)
            if tail or unres:
                raise ValueError("crack block 0x%08X: unresolved %s / data tail" % (lo, unres))
            section.extend(code + b"\xCC" * (-len(code) % 16))
            recs.append(dict(retail_fn="0x%08X" % lo, action="crack_block", applied=True, reason=why))

    def sym_va(nm):
        hits = by_name.get(retail.norm("_" + nm) or nm, [])
        return hits[0][0] if len(hits) == 1 else None

    def do_transplant(run, fa, end, why):
        name, e = byaddr[fa]
        ova = our_symbol_va(by_name, name, e["src"])
        rec = dict(run=run, retail_fn="0x%08X" % fa, fn=name, action="transplant", applied=False, reason=why)
        if resolve and ova:
            at = sec_va + len(section)
            code, tail, unres = transplant_body(fa, end, at, gog_bytes, resolve)
            if unres:
                rec["reason"] += " NOT APPLIED: unresolved %s" % ", ".join(sorted(set(unres)))
            else:
                section.extend(code + tail)
                section.extend(b"\xCC" * (-len(section) % 16))
                rec.update(applied=True)
                patches.append((ova, b"\xE9" + struct.pack("<i", at - (ova + 5)), rec))
        transplanted[fa] = rec
        recs.append(rec)

    def crack_authored_end(fa, run_end):
        """End of a GOG function lying wholly inside a crack run (first ret followed by int3)."""
        b = gog_bytes(fa, run_end - fa)
        if not b or b[0] in (0xCC, 0xC3, 0xC2):
            return None
        for i in capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(b, fa):
            nxt = i.address + i.size
            if i.mnemonic == "ret" and nxt < run_end and b[nxt - fa] == 0xCC:
                return nxt
        return None

    for va0, n0 in runs:
        run = "0x%08X" % va0
        owner = max((fa for fa in starts if fa <= va0), default=None)
        authored = False
        for fa in [a for a in starts if va0 <= a < va0 + n0 and a not in TRANSPLANT and a not in transplanted]:
            end = crack_authored_end(fa, va0 + n0)
            if end:
                do_transplant(run, fa, end, "the crack rewrote this whole function inside run %s" % run)
                authored = True
        if owner in CALL_NOP:
            callee, why = CALL_NOP[owner]
            name, e = byaddr[owner]
            ova = our_symbol_va(by_name, name, e["src"])
            cva = our_symbol_va(by_name, byaddr[callee][0], byaddr[callee][1]["src"]) if callee in byaddr else None
            rec = dict(run=run, retail_fn="0x%08X" % owner, fn=name, action="call_nop", applied=False, reason=why)
            if ova and cva and our_image is not None:
                starts_ours = sorted({h[0] for hs in by_name.values() for h in hs})
                nxt = starts_ours[bisect.bisect_right(starts_ours, ova)]
                body = our_image(ova, nxt - ova)
                sites = [i.address for i in capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(body, ova)
                         if i.mnemonic == "call" and i.size == 5 and body[i.address - ova] == 0xE8
                         and int(i.op_str, 16) == cva]
                for s in sites:
                    patches.append((s, b"\x90" * 5, rec))
                rec.update(applied=bool(sites))
            recs.append(rec)
            continue
        if owner in TRANSPLANT:
            if owner not in transplanted:
                do_transplant(run, owner, *TRANSPLANT[owner])
            continue
        done = authored
        for fa in starts:
            if not va0 <= fa < va0 + n0:
                continue
            g = gog_bytes(fa, 3)
            if g[0] == 0xC3:
                code = b"\xC3"
            elif g[0] == 0xC2:
                code = bytes(g[:3])
            else:
                continue
            name, e = byaddr[fa]
            ova = our_symbol_va(by_name, name, e["src"])
            rec = dict(run=run, retail_fn="0x%08X" % fa, fn=name, action="entry_ret", applied=bool(ova),
                       reason="protection function entry -> %s" % code.hex())
            recs.append(rec)
            if ova:
                patches.append((ova, code, rec))
            done = True
        if owner in SEMANTIC:
            tmpl, why = SEMANTIC[owner]
            name, e = byaddr[owner]
            ova = our_symbol_va(by_name, name, e["src"])
            code = bytearray()
            ok = ova is not None
            for t in tmpl:
                if isinstance(t, list):
                    a = sym_va(t[1])
                    ok = ok and a is not None
                    code += struct.pack("<I", a or 0)
                else:
                    code.append(t)
            rec = dict(run=run, retail_fn="0x%08X" % owner, fn=name, action="semantic", applied=ok, reason=why)
            recs.append(rec)
            if ok:
                patches.append((ova, bytes(code), rec))
            done = True
        if owner in AT_OFFSET and not done:
            off, n_bytes, (v0, v1), why = AT_OFFSET[owner]
            name, e = byaddr[owner]
            ova = our_symbol_va(by_name, name, e["src"])
            code = gog_bytes(owner + off, n_bytes)
            ok = False
            if ova is not None and our_image is not None:
                ok = same_layout(our_image(ova + v0, v1 - v0), orig.read(owner + v0, v1 - v0), ova + v0, owner + v0)
            rec = dict(run=run, retail_fn="0x%08X" % owner, fn=name, action="at_offset", applied=ok,
                       reason=why if ok else why + " NOT APPLIED: our layout differs there")
            recs.append(rec)
            if ok:
                patches.append((ova + off, code, rec))
            done = True
        if not done:
            recs.append(dict(run=run, len=n0, retail_fn=("0x%08X" % owner) if owner else None,
                             action="not_translated", applied=False, reason="not needed for boot so far"))
    return patches, recs, bytes(section)


def apply(exe_path, out_path, map_path, gog_path):
    by_name = retail.read_map(map_path)
    data = bytearray(open(exe_path, "rb").read())
    gog = open(gog_path, "rb").read()
    lay = retail.pe_layout(data)

    def our_image(va, n):
        o = retail.va_to_off(lay, va)
        return bytes(data[o:o + n])
    last = max(lay["secs"], key=lambda s: s["rva"])
    sec_va = lay["base"] + retail.align(last["rva"] + max(last["vsize"], last["rawsize"]), lay["salign"])
    patches, recs, section = plan(by_name, gog, our_image, sec_va, retail.pe_imports(bytes(data)))
    for va, code, _rec in patches:
        o = retail.va_to_off(lay, va)
        data[o:o + len(code)] = code
    if section and add_section(data, CRACK_SECTION, section) != sec_va:
        raise AssertionError("crack section VA moved")
    with open(out_path, "wb") as f:
        f.write(data)
    return patches, recs


def main():
    build = os.path.join(ROOT, "build")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--gog", required=True, help="your GOG Rayman2.exe")
    ap.add_argument("--exe", default=os.path.join(build, "Rayman2.exe"))
    ap.add_argument("--map", default=os.path.join(build, "Rayman2.map"))
    ap.add_argument("--out", default=os.path.join(build, "Rayman2_cracked.exe"))
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args()
    patches, recs = apply(a.exe, a.out, a.map, a.gog)
    if a.verbose:
        for va, code, rec in patches:
            print("patched 0x%08X %-40s %-11s %s" % (va, rec["fn"], rec["action"], code.hex()[:32]))
    failed = [r for r in recs if r["action"] != "not_translated" and r.get("applied") is False]
    for r in failed:
        print("NOT APPLIED %s %s: %s" % (r["retail_fn"], r.get("fn"), r["reason"]))
    print("crack: %d patches -> %s" % (len(patches), a.out))
    return 0


if __name__ == "__main__":
    sys.exit(main())
