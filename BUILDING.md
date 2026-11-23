# Building

## Requirements (not included)

- **MSVC 5.0 SP3** (cl 11.00.7022, LINK 5.10), laid out as `bin/`, `include/`, `lib/`, `redist/`.
- **Visual C++ 6.0** (`VC98/`). Provides `DINPUT.LIB` and `DXGUID.LIB`, which VC5 lacks, and the
  compiler for the few TUs that `tu.json` marks `vc6-8168`.
- **Your own GOG `Rayman2.exe`** (MD5 `ef4954015d8b67e3534c9dc40ca3ad6e`). It supplies the resources
  for the link, the original code image for byte comparison, and the bytes for the crack step.
- Python 3 with `capstone` (`pip install capstone`), on Windows (the toolchain is Win32).

The three paths are given once and then remembered in `local.json`.

## Build

```
python tools/build.py --vc5 <MSVC5 dir> --vc6 <VC6 dir> --gog <path to GOG Rayman2.exe> --crack
```

| Output | Contents |
|---|---|
| `build/Rayman2.exe` | The original image, copy protection included (the byte-match target) |
| `build/Rayman2_cracked.exe` | The same plus the GOG crack's behaviour (`--crack`). Copy it into the game folder to run it |
| `build/Rayman2.map` | LINK map |

## Byte matching

```
python tools/check.py                          # every function of status.json in the linked exe
python tools/byte_match.py NAME                # compile one function's TU, diff it against retail
python tools/byte_match.py NAME --asm          # side-by-side disassembly, retail | ours
python tools/byte_match.py NAME --flags G6     # try other compiler flags for the TU
```

`check.py` reports regressions of byte-exact functions and functions that became byte-exact.
Relocated operands (calls, globals) are masked; they are compared by address only once the whole
layout matches.

The crack step (`tools/crack.py`) reproduces each GOG crack patch at the owning function in our
layout. It reads every byte it copies from your GOG exe at run time.
