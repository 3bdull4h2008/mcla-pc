#!/usr/bin/env python3
"""Scan xarchive_cache.rpf for UI .xsf path strings and RSC5 package heads."""
import os
import sys

path = sys.argv[1] if len(sys.argv) > 1 else r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
needles = [
    b"legals.xsf", b"garage.xsf", b"credits.xsf",
    b"policecam.xsf", b"raceeditor.xsf",
    b"resources/ui", b".xsf", b"meshtextures",
    b"legals", b"garage", b"policecam",
]
size = os.path.getsize(path)
print(f"file size={size}")
found = {n: [] for n in needles}
rsc5 = []
chunk_sz = 4 * 1024 * 1024
with open(path, "rb") as f:
    off = 0
    prev = b""
    while off < size:
        data = f.read(chunk_sz)
        if not data:
            break
        buf = prev + data
        base = off - len(prev)
        for n in needles:
            start = 0
            while True:
                i = buf.find(n, start)
                if i < 0:
                    break
                abs_i = base + i
                if len(found[n]) < 12:
                    found[n].append(abs_i)
                start = i + 1
        # RSC5 heads: 52 53 43 05 (LE on disk? or BE 05 43 53 52)
        start = 0
        while len(rsc5) < 40:
            i = data.find(b"\x05\x43\x53\x52", start)
            if i < 0:
                break
            rsc5.append(off + i)
            start = i + 1
        prev = data[-80:]
        off += len(data)
for n, hits in found.items():
    print(f"{n!r}: {hits}")
print(f"RSC5 heads (first 40): {rsc5}")
