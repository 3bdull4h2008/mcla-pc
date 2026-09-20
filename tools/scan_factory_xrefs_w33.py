"""w33: raw bl-xref scan for SWF tag factories and GFx parse entry."""
from __future__ import annotations
import struct
from pathlib import Path

PE = Path(r"E:\mcla pc\build\cache\mcla_pe.bin")
BASE = 0x82000000
data = PE.read_bytes()
print("size", len(data))


def bl_targets(target: int):
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
    return hits


targets = [
    0x82275D88,
    0x82275DA8,
    0x82275DD0,
    0x82299C98,
    0x82297450,
    0x824EF220,
    0x825FDA90,
    0x825EF100,
    0x825FDBF8,
    0x825FDB30,
    0x825FDA18,
    0x825FDA8C,
    0x821D2970,
    0x8260A830,
    0x821C9788,
    0x82257678,
]
for t in targets:
    hits = bl_targets(t)
    print(f"bl {hex(t)}: n={len(hits)} first={list(map(hex, hits[:24]))}")

print("--- pointer constants ---")
for t in targets + [0x82275D8C, 0x82275DAC, 0x82299C20]:
    be = struct.pack(">I", t)
    hits = []
    start = 0
    while True:
        i = data.find(be, start)
        if i < 0:
            break
        hits.append(BASE + i)
        start = i + 4
        if len(hits) >= 12:
            break
    print(f"const {hex(t)}: {list(map(hex, hits))}")

# Find bl sites near known Scaleform strings
for s in [b"CLIP_FRAME", b"MovieClip", b"PlaySound", b"Couldn't find font", b"Invalid fixup"]:
    i = data.find(s)
    print("str", hex(BASE + i) if i >= 0 else None, s)

# Who calls the function containing 82299C20? Find function start by looking
# for typical prologue (mflr r12) backwards from 82299C10.
off = 0x82299C10 - BASE
for back in range(4, 0x200, 4):
    w = struct.unpack_from(">I", data, off - back)[0]
    if w == 0x7D8802A6:  # mflr r12
        va = BASE + off - back
        print(f"prologue candidate for 82299C20: {hex(va)}")
        # also check stwu r1
        w2 = struct.unpack_from(">I", data, off - back + 8)[0]
        if (w2 >> 26) == 37:  # stwu
            print("  stwu r1 confirms prologue")
        hits = bl_targets(va)
        print(f"  bl {hex(va)}: n={len(hits)} first={list(map(hex, hits[:16]))}")
        break

# Find callers of 82275D88/DA8 via any bl to those leaf functions.
# Also scan for lis+addi pairs that form 0x82275D88 etc.
print("--- nearby stb +8 factories (li 1..9 + stb 8) ---")
count = 0
for off_i in range(0, len(data) - 32, 4):
    w0 = struct.unpack_from(">I", data, off_i)[0]
    if (w0 & 0xFC000000) != 0x38000000:
        continue
    imm = w0 & 0xFFFF
    if imm > 32767:
        imm -= 65536
    if not (1 <= imm <= 9):
        continue
    rd = (w0 >> 21) & 0x1F
    for k in range(4, 40, 4):
        w1 = struct.unpack_from(">I", data, off_i + k)[0]
        if (w1 & 0xFC000000) == 0x98000000 and (w1 & 0xFFFF) == 8:
            rs = (w1 >> 21) & 0x1F
            if rs == rd:
                va = BASE + off_i
                # only print ones near known or with stride-12 pattern nearby
                win = data[off_i : off_i + 48]
                has12 = False
                for j in range(0, 44, 4):
                    ww = struct.unpack_from(">I", win, j)[0]
                    # rlwinm rX,rY,sh=1 or sh=2 me=29 often for *3/*12
                    if (ww & 0xFC0007FE) == 0x5400103A:  # rlwinm ...,2,mb=0,me=29
                        has12 = True
                    if (ww & 0xFC0007FE) == 0x5400083C:
                        has12 = True
                if has12 or abs(va - 0x82275D00) < 0x200 or abs(va - 0x82299C00) < 0x200:
                    print(f"  stb-tag @{hex(va)} li r{rd},{imm} stb @{hex(va+k)} stride12={has12}")
                    count += 1
                break
    if count >= 60:
        break
print("stb-tag stride sites", count)
