# rayman2-pc-decomp

A decompilation of the PC version of **Rayman 2: The Great Escape** (`Rayman2.exe`, GOG release,
MD5 `ef4954015d8b67e3534c9dc40ca3ad6e`). The goal is C source that rebuilds a **byte-identical**
`Rayman2.exe` with the original toolchain (MSVC 5.0 SP3, LINK 5.10, x87).

## Status

**`Rayman2.exe`**: the census of the retail code section (0x00401000..0x0049C000, 2026-11-24) finds **3166 functions**. 65 are library code (C runtime, import thunks) that the linker supplies; the other **3101 are game code, and all of them have C source**. **2685 are byte-exact** (86.6%; 59% of the 595,053 bytes of game code) and 416 are not yet.

The source holds 3267 C functions (`Rayman2.exe/status.json`): where the linker folded identical functions into one retail function, each C function is listed with that address.

| Module | Functions | Byte-exact |
|---|---:|---:|
| GAM | 743 | 691 |
| AI | 703 | 658 |
| SND | 417 | 405 |
| GLI | 344 | 247 |
| MEC | 117 | 88 |
| MMG | 91 | 51 |
| IPT | 86 | 74 |
| GEO | 81 | 72 |
| SAI | 68 | 64 |
| HIE | 67 | 48 |
| AGO | 52 | 26 |
| INO | 45 | 30 |
| FIL | 42 | 30 |
| MGT | 39 | 27 |
| COL | 34 | 31 |
| POS | 30 | 28 |
| INT | 29 | 22 |
| SCT | 28 | 22 |
| GMT | 17 | 17 |
| MOR | 15 | 8 |
| MTH | 11 | 7 |
| PRT | 9 | 6 |
| ERM | 8 | 8 |
| RND | 7 | 7 |
| TMR | 7 | 7 |
| DNM | 6 | 6 |
| FON | 3 | 3 |
| PIC | 1 | 1 |
| SPO | 1 | 1 |

**`GliDX6vf.dll`** (the Direct3D 6 renderer the game loads): every one of its 130 functions has C source; **103 are byte-exact** (43% of its 41,153 code bytes), 1 is a recorded floor (the shipped DLL was patched after linking: the C reproduces the linked original) and 26 are not yet byte-exact (per-function list: `GliDX6vf.dll/status.json`). The DLL builds with the retail toolchain and runs the game.

The full program builds, links and runs. It is not yet byte-identical to retail.

## How it works

- Every function is written in C and compiled with the retail toolchain; the tools compare its
  bytes with the same function in your GOG `Rayman2.exe` (or `GliDX6vf.dll`), with relocated operands
  (calls, globals) masked. *Byte-exact* means identical instruction bytes.
- The source follows the original engine's module layout and names (AI, GAM, GLI, MTH, SND, ...);
  `/* 0x00XXXXXX */` comments tie each function and global to its retail address.
- The retail exe carries copy protection. The build reproduces the original image with it; the
  crack step then applies the GOG release's patches to a copy so it runs. It reads every byte it
  copies from your exe, so nothing from the game is stored here.
- A byte-identical exe needs the remaining functions first, then the retail layout (link order,
  data order).

## Layout

| Path | Contents |
|---|---|
| `Rayman2.exe/src/` | Translation units, one engine module per directory (AI, GAM, GLI, MTH, SND, ...) |
| `Rayman2.exe/include/` | Module headers |
| `Rayman2.exe/shim/` | `stdint.h` / `intrin.h` stand-ins for the VC5 compiler |
| `Rayman2.exe/tu.json` | Link order plus compiler flags and toolchain for each TU |
| `Rayman2.exe/status.json` | Each function's retail address, size, source file and match verdict |
| `Rayman2.exe/exports.txt` | The retail export table, which the sound plugin DLLs import from the exe |
| `Rayman2.exe/crack.json` | Translation tables for the post-link crack step |
| `GliDX6vf.dll/src/`, `include/` | The Direct3D 6 renderer DLL the game loads (`DLL/GliDX6vf.dll`) |
| `GliDX6vf.dll/tu.json`, `status.json` | The DLL's link order and flags; each function's retail address, size, source file and verdict |
| `tools/build.py` | Retail-toolchain build (`--crack` also writes a runnable cracked copy) |
| `tools/build_glidx6.py` | Retail-toolchain build of `GliDX6vf.dll` (`--check` compares it with your DLL) |
| `tools/check.py`, `tools/byte_match.py` | Byte comparison against retail: whole exe, or one function with an asm diff |
| `tools/crack.py` | Post-link crack step |

`/* 0x00XXXXXX */` comments give the retail address of the function or global they sit next to
(`/* 0x1000XXXX */` in the DLL).

## Documentation

- [BUILDING.md](BUILDING.md): toolchain, build, byte-matching tools
- [docs/architecture.md](docs/architecture.md): engine structure, toolchain and link facts, method

## Legal

This repository contains no game data, executables or toolchain binaries. Building and running
it needs your own copy of the game. Rayman is a trademark of Ubisoft. This project is not
affiliated with or endorsed by Ubisoft.
