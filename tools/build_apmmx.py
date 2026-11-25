#!/usr/bin/env python3
"""Build APMmxBVR.dll (the ADPCM sound driver: decodes .APM music and voices into voices of the WAV
driver) with the retail toolchain, and check it. Same build as tools/build_wavmw.py, for this DLL.

Toolchain: MSVC 5.0 SP3 cl (APMmxBVR.dll/tu.json base_flags: /O2 /Gy /MT, static C runtime), the MMX
decoder/mixer block (src/mmx/*.asm) assembled by ML 6.1x /coff, the version resource by VC5's rc,
LINK 5.10 /DLL at 0x10000000 against VC5's kernel32 (LIBCMT comes in through the objects). snddll.c is
WAVMWBVR.dll/src/snddll.c (one source, two DLLs; the differences come from APMmxBVR.dll/include, which
is searched before WAVMWBVR.dll/include). The original's Rich header lists no assembler: its asm objects
were built by an older ML without the @comp.id record, so that header differs.

The link time stamp comes from the link environment, not from the sources: with --apm it is copied
from your original DLL after linking (only that field), so the build can be compared whole.

Paths (given once, then remembered in local.json):
  --vc5 DIR     MSVC 5.0 SP3 (bin/, include/, lib/, redist/)
  --ml EXE      ml.exe 6.1x (for example VC98/Bin/ml.exe of Visual C++ 6.0 SP5 / the Processor Pack)
  --apm DLL     your game's APMmxBVR.dll (GOG install: DLL/APMmxBVR.dll), for --check and the time stamp

Output: build/APMmxBVR/APMmxBVR.dll and .map.
--check: every function of APMmxBVR.dll/status.json at its link address against the original DLL,
relocation sites (from the TU's .obj) masked, plus a whole-file comparison. Exit 1 if an EXACT row regressed.

Usage: python tools/build_apmmx.py [--vc5 DIR] [--ml EXE] [--apm DLL] [--check] [--out DIR]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_wavmw  # noqa: E402

if __name__ == "__main__":
    build_wavmw.configure("APMmxBVR", "apm")
    sys.exit(build_wavmw.main(__doc__))
