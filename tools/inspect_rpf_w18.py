#!/usr/bin/env python3
"""w18: inspect xarchive_cache.rpf header/TOC + hunt RSC5/XCompress package heads."""
import struct
import os
import sys

p = r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
if not os.path.exists(p):
    print("MISSING", p)
    sys.exit(1)

print("size", os.path.getsize(p))

with open(p, "rb") as f:
    f.seek(0x800)
    hdr = f.read(0x80)
print("hdr@0x800", hdr[:32].hex())
print("hdr ascii", hdr[:16])

with open(p, "rb") as f:
    f.seek(0x1000)
    for i in range(16):
        e = f.read(16)
        w = struct.unpack(">4I", e)
        print("toc[%02d]" % i, ["%08X" % x for x in w])

with open(p, "rb") as f:
    f.seek(0x1000 + 16 * 64)
    names = f.read(512)
# extract printable C strings
s = []
cur = b""
for b in names:
    if 32 <= b < 127:
        cur += bytes([b])
    else:
        if len(cur) >= 3:
            s.append(cur.decode("ascii", "replace"))
        cur = b""
print("names", s[:40])

magic_rsc = bytes.fromhex("05435352")
magic_xc = bytes.fromhex("0FF512EF")

# scan first 4MB densely
with open(p, "rb") as f:
    chunk = f.read(0x400000)
for mag, name in ((magic_rsc, "RSC5"), (magic_xc, "XC")):
    hits = []
    off = 0
    while True:
        i = chunk.find(mag, off)
        if i < 0:
            break
        hits.append(i)
        off = i + 1
        if len(hits) >= 40:
            break
    print(name, "in first 4MB:", ["0x%X" % x for x in hits])

# focused window 0x40000-0x200000
with open(p, "rb") as f:
    f.seek(0x40000)
    window = f.read(0x1C0000)
hits2 = []
off = 0
while True:
    i = window.find(magic_rsc, off)
    if i < 0:
        break
    hits2.append(0x40000 + i)
    off = i + 1
print("RSC5 in 0x40000-0x200000:", ["0x%X" % x for x in hits2[:30]])

# sample bytes at known serve offsets
for off in (0x60000, 0x68000, 0xA0000, 0xA8000, 0x1000, 0x800, 0):
    with open(p, "rb") as f:
        f.seek(off)
        b = f.read(16)
    be = struct.unpack(">I", b[:4])[0] if len(b) >= 4 else 0
    print("off=0x%X headBE=%08X ascii=%r" % (off, be, b[:8]))
