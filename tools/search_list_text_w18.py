#!/usr/bin/env python3
"""Search RPF for plaintext .list-like content (globaltex / shader names)."""
import os
p = r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
needles = [b"globaltex", b"star_glow", b"preload", b".xtd", b".dcl", b"rage_im"]
# scan first 16MB in chunks
scan = 0x1000000
chunk_sz = 0x80000
with open(p, "rb") as f:
    hits = {n: [] for n in needles}
    for base in range(0, scan, chunk_sz):
        f.seek(base)
        buf = f.read(chunk_sz)
        for n in needles:
            off = 0
            while True:
                i = buf.find(n, off)
                if i < 0:
                    break
                hits[n].append(base + i)
                off = i + 1
                if len(hits[n]) >= 8:
                    break
for n, h in hits.items():
    print(n, ["0x%X" % x for x in h[:8]])

# dump a few bytes around first star_glow / globaltex hit
with open(p, "rb") as f:
    for n in needles:
        if hits[n]:
            off = hits[n][0]
            f.seek(max(0, off - 16))
            b = f.read(96)
            print("ctx", n, "at 0x%X" % off, b)
