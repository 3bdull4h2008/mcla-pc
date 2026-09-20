"""w33: xrefs for EF248 / 8260B740 / 82299CD8 / table-init path."""
from __future__ import annotations
import struct
from pathlib import Path

PE = Path(r"E:\mcla pc\build\cache\mcla_pe.bin")
BASE = 0x82000000
data = PE.read_bytes()


def bl_targets(target: int, maxn=24):
    hits = []
    for off in range(0, len(data) - 4, 4):
        w = struct.unpack_from(">I", data, off)[0]
        if (w & 0xFC000003) != 0x48000001:
            continue
        li = w & 0x03FFFFFC
        if li & 0x02000000:
            li -= 0x04000000
        va = BASE + off
        if va + li == target:
            hits.append(va)
            if len(hits) >= maxn:
                break
    return hits


for t in [
    0x825EF248,
    0x8260B740,
    0x82299CD8,
    0x825EF028,
    0x825EF0B0,
    0x82275D88,
    0x82275DA8,
    0x825EE798,
]:
    print(f"bl {hex(t)}: n={len(bl_targets(t))} first={list(map(hex, bl_targets(t)[:16]))}")

print("--- const ptrs ---")
for t in [0x825EF248, 0x8260B740, 0x82299CD8, 0x82275D88, 0x82275DA8]:
    be = struct.pack(">I", t)
    hits = []
    start = 0
    while True:
        i = data.find(be, start)
        if i < 0:
            break
        hits.append(BASE + i)
        start = i + 4
        if len(hits) >= 8:
            break
    print(f"const {hex(t)}: {list(map(hex, hits))}")
