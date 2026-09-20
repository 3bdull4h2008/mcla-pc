#!/usr/bin/env python3
"""w29: census UI .xsf TOC entries + package 0xA0000 internal structure.

Extracts TOC76-XSF / PKG-SUBST lines from a boot log and dumps package
headers + XC frame walk for 0x60000 / 0xA0000 so per-resource extract
can map TOC paths onto PSTREAM slots.
"""
import os
import re
import struct
import sys

LOG = sys.argv[1] if len(sys.argv) > 1 else r"E:\mcla pc\build\boot_stdout_w28.log"
RPF = sys.argv[2] if len(sys.argv) > 2 else r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
OUT = sys.argv[3] if len(sys.argv) > 3 else r"E:\mcla pc\build\ui_xsf_census_w29.txt"

toc_re = re.compile(
    r"TOC76-XSF #(\d+) ret=(\S+) path='([^']+)' "
    r"\[([0-9A-F]+) ([0-9A-F]+) ([0-9A-F]+) ([0-9A-F]+)\]"
)
pkg_re = re.compile(
    r"PKG-SUBST path='([^']+)' tocOff=([0-9A-F]+) tocHead=([0-9A-F]+) "
    r"-> pkg=([0-9A-F]+)"
)
pstream_re = re.compile(
    r"PSTREAM #(\d+) s\[(\d+)\] @\S+ vbase=([0-9A-F]+) pbase=([0-9A-F]+) size=([0-9A-F]+)"
)
xmem_re = re.compile(
    r"XMEM(?:-OUT)? #(\d+).*?dest=([0-9A-F]+).*?(?:head=([0-9A-F]+)|destSz=(\d+))"
)

lines = []
if os.path.exists(LOG):
    with open(LOG, "r", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()

toc = {}  # path -> first toc words
pkg = {}  # path -> (tocOff, pkg)
pstream = {}  # (job, idx) -> (vbase, pbase, size)
xmem_out = []

for ln in lines:
    m = toc_re.search(ln)
    if m:
        path = m.group(3)
        words = (m.group(4), m.group(5), m.group(6), m.group(7))
        if path not in toc:
            toc[path] = words
    m = pkg_re.search(ln)
    if m:
        path = m.group(1)
        if path not in pkg:
            pkg[path] = (m.group(2), m.group(4))
    m = pstream_re.search(ln)
    if m:
        key = (int(m.group(1)), int(m.group(2)))
        pstream[key] = (m.group(3), m.group(4), m.group(5))
    if "XMEM-OUT" in ln:
        xmem_out.append(ln.strip())

os.makedirs(os.path.dirname(OUT) or ".", exist_ok=True)
out = []
out.append("=== w29 UI .xsf TOC census (from %s) ===" % LOG)
out.append("n_paths=%d" % len(toc))
pkg_from_toc = {}
for path in sorted(toc):
    w = toc[path]
    w2 = int(w[2], 16)
    w3 = int(w[3], 16)
    cand = w2 & 0x00FFF000
    cand3 = w3 & 0x00FFF000
    # known package offs
    known = {0x60000, 0xA0000, 0x35A000}
    pkg_off = 0
    if cand in known:
        pkg_off = cand
    elif cand3 in known:
        pkg_off = cand3
    elif ".xsf" in path or "resources/ui" in path:
        pkg_off = 0xA0000
    elif "meshtextures" in path:
        pkg_off = 0x60000
    poc = pkg.get(path, ("?", "?"))
    out.append(
        "PATH %-48s toc=[%s %s %s %s] tocOff=%s pkgSubst=%s pkgFromToc=%s"
        % (path, w[0], w[1], w[2], w[3], poc[0], poc[1],
           ("0x%X" % pkg_off) if pkg_off else "0")
    )
    if pkg_off:
        pkg_from_toc.setdefault(pkg_off, []).append(path)

out.append("")
out.append("=== package -> paths ===")
for poff, paths in sorted(pkg_from_toc.items()):
    out.append("pkg=0x%X n=%d" % (poff, len(paths)))
    for pth in paths:
        out.append("  %s" % pth)

out.append("")
out.append("=== PSTREAM slots ===")
for key in sorted(pstream):
    vb, pb, sz = pstream[key]
    out.append("job#%d s[%d] vbase=%s pbase=%s size=%s (%d)" % (
        key[0], key[1], vb, pb, sz, int(sz, 16)))

out.append("")
out.append("=== XMEM-OUT (w28) ===")
for ln in xmem_out[:30]:
    out.append(ln)

out.append("")
out.append("=== package headers + XC frames ===")
if os.path.exists(RPF):
    with open(RPF, "rb") as f:
        for poff in (0x60000, 0xA0000, 0x35A000):
            f.seek(poff)
            hdr = f.read(64)
            if len(hdr) < 32:
                out.append("pkg 0x%X: short read" % poff)
                continue
            w = [struct.unpack(">I", hdr[i:i+4])[0] for i in range(0, 32, 4)]
            out.append(
                "pkg 0x%X head=[%08X %08X %08X %08X %08X %08X %08X %08X] "
                "+4=%d +16_unc=%d +28=%08X"
                % (poff, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7],
                   w[1], w[4], w[7])
            )
            # XC frames from +20
            f.seek(poff)
            blob = f.read(min(0x200000, 0x400000))
            off = 20
            frames = []
            for i in range(64):
                if off + 5 > len(blob):
                    break
                b0 = blob[off]
                if b0 == 0xFF:
                    uncomp = struct.unpack(">H", blob[off+1:off+3])[0]
                    plen = struct.unpack(">H", blob[off+3:off+5])[0]
                    hdrn = 5
                else:
                    uncomp = 0x8000
                    plen = struct.unpack(">H", blob[off:off+2])[0]
                    hdrn = 2
                frames.append((off, b0, uncomp, plen, hdrn))
                if plen == 0 and b0 != 0xFF:
                    break
                off += hdrn + plen
                if off > len(blob):
                    break
            out.append("  xc_frames@+20 n=%d end_off=0x%X" % (len(frames), off))
            for fr in frames[:24]:
                out.append(
                    "    off=0x%X b0=%02X uncomp=%d plen=%d hdr=%d"
                    % fr
                )
else:
    out.append("RPF missing: %s" % RPF)

text = "\n".join(out) + "\n"
with open(OUT, "w", encoding="utf-8") as f:
    f.write(text)
print(text)
print("WROTE", OUT)
