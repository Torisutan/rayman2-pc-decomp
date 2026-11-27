"""PE / link-map helpers shared by build.py, crack.py and check.py.

The original image: the GOG Rayman2.exe keeps an untouched copy of the original .text in its .extra
section (.extra VA X + 0x116000 + 0x1000 == .text VA X). Overlaying it onto .text gives the code
Ubisoft compiled, which is what our build is compared against. The crack's edits are the byte runs
where the two differ.
"""
import re
import struct

GOG_MD5 = "ef4954015d8b67e3534c9dc40ca3ad6e"
MERGE_GAP = 16


def pe_layout(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    opt_size = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    secs = []
    for i in range(nsec):
        o = opt + opt_size + 40 * i
        name = data[o:o + 8].rstrip(b"\0").decode("latin-1")
        vsize, rva, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        ch = struct.unpack_from("<I", data, o + 36)[0]
        secs.append({"name": name, "hdr": o, "vsize": vsize, "rva": rva, "rawsize": rawsize,
                     "rawptr": rawptr, "writable": bool(ch & 0x80000000)})
    return {"pe": pe, "opt": opt, "opt_size": opt_size, "base": struct.unpack_from("<I", data, opt + 28)[0],
            "salign": struct.unpack_from("<I", data, opt + 32)[0],
            "falign": struct.unpack_from("<I", data, opt + 36)[0],
            "hdrsize": struct.unpack_from("<I", data, opt + 60)[0], "secs": secs}


def va_to_off(lay, va):
    rva = va - lay["base"]
    for s in lay["secs"]:
        if s["rva"] <= rva < s["rva"] + max(s["vsize"], s["rawsize"]) and rva - s["rva"] < s["rawsize"]:
            return s["rawptr"] + rva - s["rva"]
    raise ValueError("VA 0x%08X not in a raw section" % va)


def align(v, a):
    return (v + a - 1) // a * a


class Image:
    """Read access to a PE by VA (bytes past a section's raw data read as zero)."""

    def __init__(self, data):
        self.data = bytes(data)
        self.lay = pe_layout(self.data)

    def read(self, va, n):
        base = self.lay["base"]
        for s in self.lay["secs"]:
            lo = base + s["rva"]
            if lo <= va < lo + max(s["vsize"], s["rawsize"]):
                off = va - lo
                b = self.data[s["rawptr"] + off:s["rawptr"] + min(off + n, s["rawsize"])] if off < s["rawsize"] else b""
                return b + b"\0" * (n - len(b))
        return b""

    def cstr(self, va, cap=256):
        return self.read(va, cap).split(b"\0", 1)[0]

    def section_at(self, va):
        base = self.lay["base"]
        return next((s for s in self.lay["secs"]
                     if base + s["rva"] <= va < base + s["rva"] + max(s["vsize"], s["rawsize"])), None)

    def is_text(self, va):
        s = self.section_at(va)
        return bool(s) and s["name"] == ".text"


def original_image(gog):
    """GOG exe bytes -> (original image bytes, crack runs [(va, len)])."""
    data = bytearray(gog)
    secs = {s["name"]: s for s in pe_layout(data)["secs"]}
    base = pe_layout(data)["base"]
    text, extra = secs[".text"], secs[".extra"]
    if extra["rva"] - text["rva"] != 0x116000 or extra["rawsize"] < text["rawsize"] + 0x1000:
        raise SystemExit("unexpected .extra layout: is this the GOG Rayman2.exe (MD5 %s)?" % GOG_MD5)
    n = text["rawsize"]
    t = bytes(data[text["rawptr"]:text["rawptr"] + n])
    x = bytes(data[extra["rawptr"] + 0x1000:extra["rawptr"] + 0x1000 + n])
    runs, i = [], 0
    while i < n:
        if t[i] != x[i]:
            last, j = i, i
            while j < n and j - last <= MERGE_GAP:
                if t[j] != x[j]:
                    last = j
                j += 1
            runs.append((base + text["rva"] + i, last + 1 - i))
            i = last + 1
        else:
            i += 1
    data[text["rawptr"]:text["rawptr"] + n] = x
    return bytes(data), runs


def pe_imports(data):
    """IAT slot VA -> imported function name."""
    out = {}
    lay = pe_layout(data)
    base = lay["base"]
    imp_rva = struct.unpack_from("<I", data, lay["opt"] + 96 + 8)[0]

    def off(rva):
        for s in lay["secs"]:
            if s["rva"] <= rva < s["rva"] + max(s["vsize"], s["rawsize"]):
                return s["rawptr"] + rva - s["rva"]
        return None
    p = off(imp_rva)
    while p is not None:
        oft, _, _, _, ft = struct.unpack_from("<IIIII", data, p)
        if not ft:
            break
        names = off(oft or ft)
        k = 0
        while names is not None:
            v = struct.unpack_from("<I", data, names + 4 * k)[0]
            if not v:
                break
            h = None if v & 0x80000000 else off(v)
            if h is not None:
                out[base + ft + 4 * k] = data[h + 2:data.index(b"\0", h + 2)].decode("ascii", "replace")
            k += 1
        p += 20
    return out


def norm(sym):
    """COFF symbol -> comparable base name. None for section/anonymous symbols."""
    if not sym or sym.startswith((".", "?", "$")):
        return None
    s = sym
    if s.startswith("__imp_"):
        s = s[len("__imp_"):]
    s = s.split("$", 1)[0]
    if s.startswith(("_", "@")):
        s = s[1:]
    s = s.split("@", 1)[0]
    return s or None


_MAP_RE = re.compile(r"^\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(?:f\s+)?(?:i\s+)?(\S+)")


def read_map(path):
    """LINK map -> base name -> [(va, object file)]."""
    by_name = {}
    for ln in open(path, encoding="latin-1"):
        m = _MAP_RE.match(ln)
        if not m:
            continue
        n = norm(m.group(1))
        if n:
            by_name.setdefault(n, []).append((int(m.group(2), 16), m.group(3).split(":")[-1].lower()))
    return by_name


def our_va(by_name, name, obj_base):
    hits = by_name.get(norm(name) or "", [])
    if not hits:
        hits = by_name.get(name.split("@", 1)[0], [])
    for va, ob in hits:     # a static of the same name may exist in several TUs: prefer the entry's own
        if ob == obj_base:
            return va
    return hits[0][0] if len(hits) == 1 else None
