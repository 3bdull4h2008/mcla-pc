#!/usr/bin/env python3
"""Authoritative offline host decode of the UI .xsf (RSC5 + XMem/raw-LZX).

THE RULE IS THE CONTAINER'S FRAME CHAIN -- and only the frame chain.
There is no "single continuous stream" shortcut: it fed the chain headers to
the LZX decoder as compressed data, so everything after the first 32768-byte
frame boundary was garbage (measured: raceeditor 102,219 wrong bytes from
offset 32768; garage raises "Invalid LZX block type: 4"; legals decodes to a
head of 00 00 00 00). build/xmem_golden/raceeditor.bin WAS that corrupt
output, so the UIXSF-GOLDEN-* checks were self-referential.

Container format (measured against build/game_data/xarchive_cache.rpf and
against the console's own reader, guest sub_82461010):
  RSC5 header: +0 0x05435352, +4 header len 0x1B, +12 0x0FF512EF (XComp),
                +16 uncLen (BE)  <- the DECLARED UNCOMPRESSED LENGTH
  +20 the frame chain. One frame header per frame:
        byte0 == 0xFF -> 5-byte header: uncompressed = u16BE(+1),
                                         compressed   = u16BE(+3)
        else          -> 2-byte header: compressed   = u16BE(+0),
                                         uncompressed = 32768 (0x8000)
  window_bits = 17, LZX frame size 32768.

The decoder is .research/360tools/tools/lzx_decompress.py -- an INDEPENDENT
implementation of the MS-LZX algorithm, used here unmodified.  It is driven
ONE CHAIN FRAME AT A TIME, which is what the console does (the bit buffer is
re-initialised from each frame's first bytes; the LZX block state and the
sliding window persist across frames).  The reference class keeps its own
`window_pos` and copies its output out of window[0..], so the caller rotates
the window ring so that the next absolute output position lands at index 0
and sets window_pos = 0 -- then ONE call decodes exactly ONE chain frame.

Usage:  python tools/xmem_decode.py        # decode all five; write missing
                                           # goldens, compare against existing
         python tools/xmem_decode.py gen    # force (over)write all five goldens
"""
from __future__ import annotations

import os
import struct
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(_HERE)
ARCHIVE = os.path.join(ROOT, "build", "game_data", "xarchive_cache.rpf")
GOLDEN_DIR = os.path.join(ROOT, "build", "xmem_golden")
RSC5 = 0x05435352
XCOMP = 0x0FF512EF
DIU = b"\x44\x49\x55\x00"
WB = 17
MASK = (1 << WB) - 1

TOOLS = os.path.join(ROOT, ".research", "360tools", "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)
from lzx_decompress import LZXDecoder  # noqa: E402

CONTAINERS = {
    "raceeditor": 0x64CB0000,
    "garage":     0x64980000,
    "policecam":  0x64CA3000,
    "credits":    0x6496F000,
    # F-806 (2026-10-21): legals was the only UI container with NO byte-level
    # coverage anywhere (build/agents/audit_swf.md C8). Its retail container is
    # the RSC5/XCompress blob at archive offset 0x000A0000 (TOC76-XSF #92
    # pkgFromToc=000A0000); measured decode = 196553 B, head 44 49 55 00.
    "legals":     0x000A0000,
}


def be32(b, i):
    return struct.unpack(">I", b[i:i + 4])[0]


def chain(pkg, start=20):
    """Walk the container's frame chain. Returns [(hdr_off, hdr_len, unc, pay)]."""
    src, frames = start, []
    while src + 2 <= len(pkg):
        b0 = pkg[src]
        if b0 == 0xFF:
            if src + 5 > len(pkg):
                break
            hdr = 5
            unc = (pkg[src + 1] << 8) | pkg[src + 2]
            pay = (pkg[src + 3] << 8) | pkg[src + 4]
        else:
            hdr = 2
            unc = 0x8000
            pay = (b0 << 8) | pkg[src + 1]
        if pay == 0:
            break
        frames.append((src, hdr, unc, pay))
        src += hdr + pay
    return frames


def decode_chain(pkg, unc, frames=None):
    """Decode the frame chain. Returns (bytes, nframes_used)."""
    if frames is None:
        frames = chain(pkg)
    dec = LZXDecoder(window_bits=WB)
    ring = bytearray(1 << WB)     # window ring, indexed by absolute position
    abspos = 0
    out = bytearray()
    used = 0
    for (so, hdr, fu, pl) in frames:
        if abspos >= unc:
            break
        want = min(fu, unc - abspos)
        p = abspos & MASK
        dec.window = bytearray(ring[p:] + ring[:p])   # index 0 == abspos
        dec.window_pos = 0
        o = dec.decompress(pkg[so + hdr:so + hdr + pl], want)
        produced = dec.window_pos          # want + match overshoot
        for i in range(produced):
            ring[(abspos + i) & MASK] = dec.window[i]
        abspos += produced
        out += o
        used += 1
        if len(o) < want:
            break
    return bytes(out), used


def main():
    gen = "gen" in sys.argv[1:]
    with open(ARCHIVE, "rb") as f:
        for name, off in CONTAINERS.items():
            f.seek(off)
            pkg = f.read(0x400000)
            assert be32(pkg, 0) == RSC5 and be32(pkg, 12) == XCOMP, name
            unc = be32(pkg, 16)
            frames = chain(pkg)
            out, used = decode_chain(pkg, unc, frames)
            gpath = os.path.join(GOLDEN_DIR, f"{name}.bin")
            if gen or not os.path.isfile(gpath):
                os.makedirs(GOLDEN_DIR, exist_ok=True)
                with open(gpath, "wb") as g:
                    g.write(out)
                print(f"[{name:11}] wrote golden ({len(out)} bytes, "
                      f"{used}/{len(frames)} chain frames used)")
                continue
            with open(gpath, "rb") as g:
                gold = g.read()
            ok = out == gold
            print(f"[{name:11}] path=chain produced={len(out)}/{unc} "
                  f"frames={used}/{len(frames)} head={out[:4].hex(' ')} "
                  f"match={'EXACT' if ok else 'DIFF'}")


if __name__ == "__main__":
    main()
