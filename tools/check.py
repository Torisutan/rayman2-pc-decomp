#!/usr/bin/env python3
"""Check every function of Rayman2.exe/status.json inside the LINKED exe (run tools/build.py first)
against the original image from your GOG exe: the function's bytes at our link address equal the
retail bytes, relocation sites (from the TU's .obj) masked.

Reports how many functions are byte-exact and every function whose result disagrees with its
status.json verdict (a regression of an EXACT row, or a MISMATCH row that now matches).
This checks code bytes only; whether each relocated operand points at the right symbol is not
checked here.

Usage: python tools/check.py [--gog EXE] [--build build] [--verbose]
Exit: 0 no EXACT row regressed, 1 otherwise.
"""
import argparse
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import build  # noqa: E402
import objfn  # noqa: E402
import retail  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    build.add_path_args(ap)
    ap.add_argument("--build", default=build.BUILD)
    ap.add_argument("--verbose", action="store_true")
    a = build.resolve_paths(ap.parse_args(), need=("gog",))
    out = os.path.abspath(a.build)
    by_name = retail.read_map(os.path.join(out, "Rayman2.map"))
    ours = retail.Image(open(os.path.join(out, "Rayman2.exe"), "rb").read())
    orig = retail.Image(retail.original_image(open(a.gog, "rb").read())[0])
    rows = json.load(open(os.path.join(build.EXE_DIR, "status.json")))
    exact, regressed, improved, errors = 0, [], [], []
    for row in rows:
        obj = build.obj_path(out, row["src"])
        try:
            raw, relocs, _ = objfn.extract(obj, row["name"])
        except (OSError, ValueError) as ex:
            errors.append((row, str(ex)))
            continue
        length = row["len"]
        fixed = [i for i in range(length) if not any(r["off"] <= i < r["off"] + 4 for r in relocs)]
        va = retail.our_va(by_name, row["name"], os.path.basename(obj).lower())
        if va is None:
            # /OPT:ICF folded this copy into an identical body: take the hit whose bytes equal ours
            for cand, _ob in by_name.get(retail.norm(row["name"]) or "", []):
                got = ours.read(cand, length)
                if all(got[i] == raw[i] for i in fixed if i < len(raw)):
                    va = cand
                    break
        if va is None:
            errors.append((row, "not in the linked exe"))
            continue
        g, w = ours.read(va, length), orig.read(int(row["addr"], 16), length)
        ok = all(g[i] == w[i] for i in fixed)
        exact += ok
        if row["verdict"] == "EXACT" and not ok:
            regressed.append(row)
        elif row["verdict"] != "EXACT" and ok:
            improved.append(row)
    print("%d/%d functions byte-exact in the linked exe (relocations masked)" % (exact, len(rows)))
    for r in regressed:
        print("  REGRESSED %s %s (%s)" % (r["addr"], r["name"], r["src"]))
    for r in improved:
        print("  now exact %s %s (%s)" % (r["addr"], r["name"], r["src"]))
    for r, why in errors:
        if a.verbose or r["verdict"] == "EXACT":
            print("  ERROR %s %s: %s" % (r["addr"], r["name"], why))
    return 1 if regressed or any(r["verdict"] == "EXACT" for r, _ in errors) else 0


if __name__ == "__main__":
    sys.exit(main())
