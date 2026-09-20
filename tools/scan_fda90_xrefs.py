"""Scan mcla_pe.bin for PPC bl xrefs to FDA90 / EF100 / type handlers.

Assumes raw image VA base 0x82000000 (Xenon title default for this dump).
Reports bl sites and nearby function labels we know.
"""
from __future__ import annotations

import struct
import sys
from collections import defaultdict

PE = r"E:\mcla pc\build\cache\mcla_pe.bin"
BASE = 0x82000000

KNOWN = {
    0x825FDA90: "FDA90 construct",
    0x825EF100: "EF100 place",
    0x825FDBF8: "FDBF8 build",
    0x8260A830: "A830 fixup",
    0x82609350: "t1",
    0x826078C8: "t3",
    0x82607098: "t4",
    0x826059B0: "t5",
    0x82604FF0: "t6",
    0x82605058: "t7",
    0x82606FB0: "t9",
    0x825EE798: "EE798",
    0x8217D890: "D890 rebase",
    0x821D2378: "D2378",
    0x8217D828: "D828",
    0x821D2970: "ctor 2970",
    0x825FB0D8: "FB0D8 dtor",
    0x825FDB30: "FDB30",
}


def load_pe():
    data = open(PE, "rb").read()
    return data


def bl_targets(data, target):
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


def looks_like_store_tag(data, va):
    """Scan a small window for stb rX,8(rY) after a li rX,1..9 pattern."""
    off = va - BASE
    window = data[off : off + 256]
    found = []
    for i in range(0, len(window) - 4, 4):
        w = struct.unpack_from(">I", window, i)[0]
        # stb rS, d(rA) = 0x98000000 | (S<<21) | (A<<16) | d
        if (w & 0xFC000000) == 0x98000000:
            d = w & 0xFFFF
            if d == 8:
                found.append((hex(va + i), hex(w)))
    return found


def main():
    data = load_pe()
    print("size", len(data))
    for s in [
        b"Invalid fixup",
        b"CLIP_FRAME",
        b"MovieClip",
        b"PlaySound",
        b"star_glow",
        b"font",
        b"swf",
        b"SWF",
    ]:
        i = data.find(s)
        print("str", hex(i) if i >= 0 else None, s)

    for tgt, name in KNOWN.items():
        hits = bl_targets(data, tgt)
        print(f"bl {hex(tgt)} {name}: count={len(hits)} first={list(map(hex, hits[:12]))}")

    # Callers of type handlers — candidate SWF object factories.
    print("--- type-handler callers ---")
    for tgt in [
        0x82609350,
        0x826078C8,
        0x82607098,
        0x826059B0,
        0x82604FF0,
        0x82605058,
        0x82606FB0,
        0x825FDBF8,
    ]:
        hits = bl_targets(data, tgt)
        print(f"  {hex(tgt)} {KNOWN.get(tgt,'?')}: {list(map(hex, hits[:20]))} n={len(hits)}")

    # Search for li rX, 1..9 followed within 32 bytes by stb rX, 8(rY)
    print("--- stb +8 near li 1..9 (sample) ---")
    count = 0
    for off in range(0, len(data) - 32, 4):
        w0 = struct.unpack_from(">I", data, off)[0]
        # li rD, SIMM = addi rD,0,SIMM = 0x38000000 | D<<21 | SIMM
        if (w0 & 0xFC000000) != 0x38000000:
            continue
        imm = w0 & 0xFFFF
        if imm > 32767:
            imm -= 65536
        if not (1 <= imm <= 9):
            continue
        rd = (w0 >> 21) & 0x1F
        for k in range(4, 32, 4):
            w1 = struct.unpack_from(">I", data, off + k)[0]
            if (w1 & 0xFC000000) == 0x98000000 and (w1 & 0xFFFF) == 8:
                rs = (w1 >> 21) & 0x1F
                if rs == rd:
                    va = BASE + off
                    print(f"  stb-tag @{hex(va)} li r{rd},{imm} stb @{hex(va+k)}")
                    count += 1
                    break
        if count >= 40:
            print("  ... truncated")
            break
    print("stb-tag sites", count)


if __name__ == "__main__":
    main()
