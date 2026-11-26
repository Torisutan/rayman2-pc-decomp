# rayman2-pc-decomp

A decompilation of the PC version of **Rayman 2: The Great Escape** (`Rayman2.exe`, GOG release,
MD5 `ef4954015d8b67e3534c9dc40ca3ad6e`). The goal is C source that rebuilds a **byte-identical**
`Rayman2.exe` with the original toolchain (MSVC 5.0 SP3, LINK 5.10, x87).

## Status

**`Rayman2.exe`**: the census of the retail code section (0x00401000..0x0049C000, 2026-11-26) finds **3166 functions**. 65 are library code (C runtime, import thunks) that the linker supplies; the other **3101 are game code, and all of them have C source**. **2687 are byte-exact** (86.6%; 60% of the 595,410 bytes of game code) and 414 are not yet.

The source holds 3267 C functions (`Rayman2.exe/status.json`): where the linker folded identical functions into one retail function, each C function is listed with that address.

| Module | Functions | Byte-exact |
|---|---:|---:|
| GAM | 743 | 687 |
| AI | 703 | 660 |
| SND | 417 | 405 |
| GLI | 344 | 248 |
| MEC | 117 | 88 |
| MMG | 91 | 51 |
| IPT | 86 | 74 |
| GEO | 81 | 71 |
| SAI | 68 | 64 |
| HIE | 67 | 48 |
| AGO | 52 | 26 |
| INO | 45 | 30 |
| FIL | 42 | 30 |
| MGT | 39 | 28 |
| COL | 34 | 31 |
| POS | 30 | 30 |
| INT | 29 | 23 |
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

**`WAVMWBVR.dll`** (the sound driver the game loads on any MMX CPU): every one of its 767 C functions has source and the hand-written MMX mixer is reassembled from MASM; **758 are byte-exact** (88% of 42,930 C code bytes) and 9 are not yet (per-function list: `WAVMWBVR.dll/status.json`). The data layout and headers match the original; the DLL builds with the retail toolchain.

**`APMmxBVR.dll`** (the ADPCM sound driver: decodes the `.APM` music and voices for the WAV driver): every one of its 161 C functions has source and the hand-written MMX block is reassembled from MASM; **156 are byte-exact** (90% of 16,634 C code bytes) and 5 are not yet (per-function list: `APMmxBVR.dll/status.json`). The DLL builds with the retail toolchain and plays the game's music.

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

## GliDX6vf.dll

Rayman 2 draws through a separate renderer DLL. `GliDX6vf.dll` is its Direct3D 6 driver (DirectDraw 4
surfaces, a Direct3D 3 device, `DrawPrimitive` with transformed and lit vertices). The game loads it
from `DLL/GliDX6vf.dll` with `LoadLibrary` and resolves the exported `GLI_DRV_*` functions by name:
that export set is the whole interface between exe and driver. The exe tells the driver which
helpers and buffers to use through `GLI_DRV_lSetCommonData` / `GLI_DRV_lSetCommonFct` and then
drives it frame by frame.

Which renderer the game uses is set in its `ubi.ini`; the exe loads `DLL/<GLI_DllFile>vf.dll`. To use
this one:

```
GLI_DllFile=GliDX6
GLI_Dll=DirectX6
GLI_Driver=display
GLI_Device=Direct3D HAL
```

On Windows 10 with the native DirectDraw, the game only finds its 16-bit display modes when started
with the compatibility layer `DWM8And16BitMitigation` (for example `set __COMPAT_LAYER=DWM8And16BitMitigation`
before launching it); a DirectDraw wrapper works too.

| Source | Contents |
|---|---|
| `GliDX6vf.dll/src/driver/` | The `GLI_DRV_*` entry points: init/close, activation, display modes, DLL info, common data from the exe |
| `GliDX6vf.dll/src/device/` | DirectDraw / Direct3D device: creation and reset, surfaces, caps, clear, flip, lock, windowed/full-screen |
| `GliDX6vf.dll/src/texture/` | Texture formats, upload (with mipmaps, palettes, colour keys), pixel conversion, texture memory cost |
| `GliDX6vf.dll/src/render/` | Scene begin/end, cached render states (Z, fog, blending, alpha), fog, black polygons |
| `GliDX6vf.dll/src/clip/` | The clipping pipeline (near plane and screen edges), triangle/sprite/line submission, the sorted list of transparent polygons |
| `GliDX6vf.dll/src/core/` | Global state |
| `GliDX6vf.dll/include/GliDX6vf/` | Exports and internal prototypes, global state, Direct3D constants |

`tools/build_glidx6.py` builds the original driver with the retail toolchain; copy the result over
`DLL/GliDX6vf.dll` (keep a backup) to run the game with it ([BUILDING.md](BUILDING.md)). Code under
`#ifdef GLI_DX6_FIXES` is not part of the original driver (Windows 10 activation handling, NULL
guards, a display-mode fallback, an optional diagnostic log); the byte-match build leaves it out.

## WAVMWBVR.dll

All game sound goes through a sound driver DLL that the exe picks from `DLL/SND_CPA.INI`: on any CPU
with MMX that is `WAVMWBVR.dll` (software mixer, the 3D sample layer, `waveOut` output on its own
thread). The exe resolves its exported `SND_fn_*SxdWave` functions by name; the DLL in turn calls
back into the exe's exported sound library through `GetProcAddress`.

| Source | Contents |
|---|---|
| `WAVMWBVR.dll/src/snddll.c` | Stubs for the exe's sound library entry points, loaded with `GetProcAddress` |
| `WAVMWBVR.dll/src/Win95/` | Streamed samples and transition streaming |
| `WAVMWBVR.dll/src/sndvirt.c` | Virtual voices |
| `WAVMWBVR.dll/src/sndwave.c` | Sample layer: voices, mix loops, reverb filter design, the `waveOut` thread, buffer clients |
| `WAVMWBVR.dll/src/pc_mixervol.c` | Volume through the Windows mixer |
| `WAVMWBVR.dll/src/Sndxd.c`, `sndxdwav.c` | The 3D sample layer and the exported `*SxdWave` interface |
| `WAVMWBVR.dll/src/mixer/` | The MMX mixer, hand-written assembly (MASM) |
| `WAVMWBVR.dll/src/WAVMWBVR.rc` | Version resource |

`tools/build_wavmw.py` builds it with the retail toolchain (plus ML 6.1x for the mixer); copy the
result over `DLL/WAVMWBVR.dll` (keep a backup) to run the game with it ([BUILDING.md](BUILDING.md)).
Several names of uninitialized globals end in a number: the linker orders those globals by the
compiler's name hash, and the suffix reproduces the original data layout.

## APMmxBVR.dll

Music and voices are `.APM` files (IMA ADPCM). The exe hands them to the ADPCM driver
`APMmxBVR.dll` (picked from `DLL/SND_CPA.INI` on MMX CPUs), which decodes them and feeds the result to
the WAV driver as buffer voices. Like the WAV driver it exports `SND_fn_*SxdADPCM` functions and calls
back into the exe through `GetProcAddress`.

| Source | Contents |
|---|---|
| `APMmxBVR.dll/src/SndAdpcm.c` | ADPCM sample layer: up to 30 voices from memory or streamed from disk, themes (transitions with fade), resource loaders |
| `APMmxBVR.dll/src/pc_sndxdadpcm.c` | The exported `*SxdADPCM` interface |
| `WAVMWBVR.dll/src/snddll.c` | Shared with the WAV driver (one source, two DLLs; `APMmxBVR.dll/include` holds the differences) |
| `APMmxBVR.dll/src/mmx/` | The MMX decoder/mixer kernels and the IMA ADPCM tables, hand-written assembly (MASM) |
| `APMmxBVR.dll/src/APMmxBVR.rc` | Version resource |

`tools/build_apmmx.py` builds it with the retail toolchain (plus ML 6.11d); copy the result over
`DLL/APMmxBVR.dll` (keep a backup) to run the game with it ([BUILDING.md](BUILDING.md)).

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
| `WAVMWBVR.dll/src/`, `include/` | The sound driver DLL the game loads (`DLL/WAVMWBVR.dll`) |
| `WAVMWBVR.dll/tu.json`, `status.json` | Its link order, compiler/assembler/linker flags and libraries; each function's retail address, size, source file and verdict |
| `APMmxBVR.dll/src/`, `include/`, `tu.json`, `status.json` | The ADPCM sound driver DLL (`DLL/APMmxBVR.dll`), the same way |
| `tools/build.py` | Retail-toolchain build (`--crack` also writes a runnable cracked copy) |
| `tools/build_glidx6.py` | Retail-toolchain build of `GliDX6vf.dll` (`--check` compares it with your DLL) |
| `tools/build_wavmw.py` | Retail-toolchain build of `WAVMWBVR.dll` (`--check` compares it with your DLL) |
| `tools/build_apmmx.py` | Retail-toolchain build of `APMmxBVR.dll` (`--check` compares it with your DLL) |
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
