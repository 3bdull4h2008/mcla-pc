#!/usr/bin/env python3
"""Probe RPF at TOC-derived offsets for globaltex.list / preload.list."""
import struct, os
p = r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
offs = [0xD0000, 0x1DD11C, 0xEC, 0x23F, 0x104, 0x60000]
with open(p, "rb") as f:
    for off in offs:
        f.seek(off)
        b = f.read(64)
        be = struct.unpack(">I", b[:4])[0] if len(b) >= 4 else 0
        print("off=0x%X be=%08X head=%r" % (off, be, b[:32]))

# search for printable "globaltex" or "preload" nearby those offsets
with open(p, "rb") as f:
    for off in (0xD0000, 0x1DD11C):
        f.seek(max(0, off - 32))
        b = f.read(256)
        print("window@0x%X" % off, b[:80])
        # also try interpret as list text
        text = b.split(b"\x00")[0]
        print("  cstr", text[:80])
