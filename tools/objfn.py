#!/usr/bin/env python3
"""Extract a function's code bytes + relocations from a COFF .obj by symbol name.

Seed of the Phase-2 reloc-aware byte_match tool. VC5 compiles each /Gy function into
its own COMDAT section; we locate the function symbol, read its section's raw bytes,
and list the relocation fixups (offset, target symbol, type) so callers/globals can be
masked rather than raw-compared.

Usage: python objfn.py <obj> <symbol>   (symbol without leading underscore; we try both)
"""
import struct
import sys

IMAGE_SYM_CLASS_EXTERNAL = 2


def _read_coff(path):
    with open(path, "rb") as f:
        data = f.read()
    machine, nsec, _ts, psym, nsym, opt, _ch = struct.unpack_from("<HHIIIHH", data, 0)
    sec_base = 20 + opt
    sections = []
    for i in range(nsec):
        off = sec_base + i * 40
        name = data[off:off + 8].rstrip(b"\x00")
        (vsize, vaddr, rawsize, prawdata, preloc, _plines,
         nreloc, _nlines, chars) = struct.unpack_from("<IIIIIIHHI", data, off + 8)
        sections.append(dict(idx=i + 1, name=name, vsize=vsize, rawsize=rawsize,
                             prawdata=prawdata, preloc=preloc, nreloc=nreloc, chars=chars))
    # string table follows the symbol table (each symbol = 18 bytes)
    strtab_off = psym + nsym * 18
    def sym_name(raw):
        if raw[:4] == b"\x00\x00\x00\x00":
            soff = struct.unpack_from("<I", raw, 4)[0]
            end = data.index(b"\x00", strtab_off + soff)
            return data[strtab_off + soff:end].decode("latin1")
        return raw[:8].split(b"\x00", 1)[0].decode("latin1")  # short name: 8 bytes, NUL-padded
    symbols = []
    i = 0
    while i < nsym:
        off = psym + i * 18
        raw = data[off:off + 18]
        value, secnum, typ, sclass, naux = struct.unpack_from("<iHHBB", raw, 8)
        symbols.append(dict(name=sym_name(raw), value=value, secnum=secnum,
                            typ=typ, sclass=sclass, idx=i))
        i += 1 + naux
    return data, sections, symbols


def list_functions(path):
    """Return the C names (leading underscore stripped) of defined function symbols in `path`."""
    _data, _sections, symbols = _read_coff(path)
    out = []
    for s in symbols:
        # EXTERNAL (class 2), defined (secnum>0), COFF function type (DT_FCN high nibble => typ 0x20)
        if s["sclass"] == 2 and s["secnum"] > 0 and s["typ"] == 0x20:
            out.append(s["name"][1:] if s["name"].startswith("_") else s["name"])
    return out


def extract(path, symbol):
    data, sections, symbols = _read_coff(path)
    cand = [symbol, "_" + symbol]
    sym = next((s for s in symbols if s["name"] in cand and s["secnum"] > 0), None)
    if sym is None:
        # Fallback: match by BASE name (strip leading '_', __fastcall's leading
        # '@' and the '@N' decoration) so a ledger key like "Foo", "_Foo@4",
        # "Foo@4" or "@Foo@12" all resolve to the same COFF symbol regardless
        # of calling convention.
        def _base(nm):
            return nm.lstrip("_@").split("@", 1)[0]
        want = _base(symbol)
        sym = next((s for s in symbols
                    if s["secnum"] > 0 and _base(s["name"]) == want), None)
    if sym is None:
        raise ValueError("symbol not found: %s (have %d symbols)" % (symbol, len(symbols)))
    sec = next(s for s in sections if s["idx"] == sym["secnum"])
    base = sec["prawdata"] + sym["value"]
    raw = data[base:sec["prawdata"] + sec["rawsize"]]
    # relocations for this section, expressed as offset-within-function
    relocs = []
    # symidx is a raw COFF symbol-table index (aux records count), NOT a position in `symbols`
    # (which skips aux records) — look it up by the stored raw index.
    by_idx = {s["idx"]: s for s in symbols}
    for r in range(sec["nreloc"]):
        roff = sec["preloc"] + r * 10
        vaddr, symidx, rtype = struct.unpack_from("<IIH", data, roff)
        tgt = by_idx[symidx]["name"] if symidx in by_idx else "?"
        relocs.append(dict(off=vaddr - sym["value"], type=rtype, target=tgt))
    return raw, relocs, sec


def main():
    if len(sys.argv) != 3:
        raise SystemExit(__doc__)
    raw, relocs, sec = extract(sys.argv[1], sys.argv[2])
    print("section=%s rawsize=%d relocs=%d" % (sec["name"].decode("latin1"),
                                               sec["rawsize"], len(relocs)))
    print("bytes=" + raw.hex())
    for rel in relocs:
        print("  reloc off=0x%x type=0x%x -> %s" % (rel["off"], rel["type"], rel["target"]))


if __name__ == "__main__":
    main()
