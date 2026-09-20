#!/usr/bin/env python3
"""w18: enumerate RSC5 package heads in xarchive_cache.rpf (first 32MB)."""
import os
import struct

p = r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
magic = bytes.fromhex("05435352")
xc = bytes.fromhex("0FF512EF")
scan = 0x2000000
with open(p, "rb") as f:
    chunk = f.read(scan)
hits = []
off = 0
while True:
    i = chunk.find(magic, off)
    if i < 0:
        break
    w4 = struct.unpack(">I", chunk[i + 4 : i + 8])[0] if i + 8 <= len(chunk) else 0
    w8 = struct.unpack(">I", chunk[i + 8 : i + 12])[0] if i + 12 <= len(chunk) else 0
    w12 = struct.unpack(">I", chunk[i + 12 : i + 16])[0] if i + 16 <= len(chunk) else 0
    hits.append((i, w4, w8, w12, w12 == 0x0FF512EF))
    off = i + 4
print("RSC5 count in first %d MB: %d" % (scan >> 20, len(hits)))
for h in hits[:40]:
    print("  off=0x%08X +4=%08X +8=%08X +12=%08X xc=%s" % h)

# also dump join-table-ish STRENT values if logged - skip
# sample sizes between consecutive RSC5
print("gaps:")
for a, b in zip(hits, hits[1:]):
    print("  0x%X -> 0%X delta=0x%X" % (a[0], b[0], b[0] - a[0]))
