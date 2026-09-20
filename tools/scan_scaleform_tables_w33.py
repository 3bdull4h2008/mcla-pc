"""w33: dump Scaleform FP tables and find parse dispatch callers."""
from __future__ import annotations
import struct
from pathlib import Path

PE = Path(r"E:\mcla pc\build\cache\mcla_pe.bin")
BASE = 0x82000000
data = PE.read_bytes()


def read_u32(va: int) -> int:
    off = va - BASE
    if off < 0 or off + 4 > len(data):
        return 0xFFFFFFFF
    return struct.unpack_from(">I", data, off)[0]


def dump_table(name: str, base: int, count: int):
    print(f"=== {name} @ {hex(base)} n={count} ===")
    for i in range(count):
        w = read_u32(base + i * 4)
        print("  [{:02X}] @{:08X} = {:08X}".format(i, base + i * 4, w))


# Function-pointer tables near factories
dump_table("FE00-unknown", 0x8202FDC0, 32)
dump_table("11DD50-place-area", 0x8211DD50, 24)
dump_table("11E230-swfC-vt-area", 0x8211E230, 24)
dump_table("82085200-swfC-vt", 0x82085200, 16)
dump_table("82085340-swfC-vt2", 0x82085340, 16)
dump_table("82086E00-CLIP", 0x82086E00, 16)

# Find bl xrefs to parse-ish functions near Scaleform
def bl_targets(target: int, maxn=30):
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


# Disasm 82299AA0 (tag-6 parent function) briefly via nearby known callees
print("--- callers of nearby Scaleform helpers ---")
for t in [
    0x822768D8,
    0x822999C4,
    0x82299A80,
    0x82299AA0,
    0x82299C14,
    0x8229770C,
    0x82487708,
    0x824C6ED0,
    0x824CAA8C,
    0x82275E60,
    0x82276800,
]:
    hits = bl_targets(t)
    print(f"bl {hex(t)}: n={len(hits)} first={list(map(hex, hits[:12]))}")

# Search for load of table base 0x8202FE00 / 0x8202FE10 / 0x8202FE20
# typical: lis rX, 0x8202; addi rY, rX, 0xFE10
print("--- lis 8202 + addi FE* sequences (table loads) ---")
count = 0
for off in range(0, len(data) - 16, 4):
    w = struct.unpack_from(">I", data, off)[0]
    if (w & 0xFFFF0000) != 0x3D600000 and (w >> 26) != 15:
        continue
    # lis rD, imm = op15
    if (w >> 26) != 15:
        continue
    imm = w & 0xFFFF
    if imm != 0x8202 and imm != 0x8211 and imm != 0x8208:
        continue
    rd = (w >> 21) & 0x1F
    for k in range(4, 24, 4):
        w2 = struct.unpack_from(">I", data, off + k)[0]
        if (w2 >> 26) != 14:  # addi
            continue
        simm = w2 & 0xFFFF
        if simm > 32767:
            simm -= 65536
        ra = (w2 >> 16) & 0x1F
        if ra != rd:
            continue
        full = (imm << 16) + simm
        if full in (
            0x8202FE00, 0x8202FE10, 0x8202FE20, 0x8202FDC0, 0x8202FDC4,
            0x8211DD60, 0x8211E248, 0x8211E250, 0x8211E258, 0x8211E5C8,
            0x82085200, 0x82085364, 0x82086E0C,
        ) or (0x8202FD00 <= full <= 0x8202FF00) or (0x8211DC00 <= full <= 0x8211E700):
            va = BASE + off
            print(f"  load {hex(full)} via lis r{rd},{imm:04X} addi @{hex(va+k)} site={hex(va)}")
            count += 1
print("table-load sites", count)

# Search guest string xrefs to CLIP_FRAME / MovieClip via absolute addresses
print("--- string constants ---")
for s, va in [(b"CLIP_FRAME", 0x82086E5C), (b"MovieClip", 0x82086E84)]:
    be = struct.pack(">I", va)
    hits = []
    start = 0
    while True:
        i = data.find(be, start)
        if i < 0:
            break
        hits.append(BASE + i)
        start = i + 4
        if len(hits) >= 16:
            break
    print(f"const {hex(va)} {s}: {list(map(hex, hits))}")
