#!/usr/bin/env python3
"""Convert a validator .rgba dump (packed RGBA, no header) into a PNG.

The import validator writes both a .bmp (directly viewable) and a raw .rgba next to
it; this makes the PNG used as the evidence artifact.
"""
import os
import struct
import sys
import zlib


def png_from_rgba(path, w, h, out=None):
    with open(path, "rb") as f:
        raw = f.read()
    need = w * h * 4
    if len(raw) < need:
        sys.exit("%s: %d bytes, need %d for %dx%d" % (path, len(raw), need, w, h))
    out = out or os.path.splitext(path)[0] + ".png"
    stride = w * 4
    scanlines = b"".join(b"\x00" + raw[y * stride:(y + 1) * stride] for y in range(h))

    def chunk(tag, data):
        return (struct.pack(">I", len(data)) + tag + data +
                struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF))

    ihdr = struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0)
    with open(out, "wb") as f:
        f.write(b"\x89PNG\r\n\x1a\n")
        f.write(chunk(b"IHDR", ihdr))
        f.write(chunk(b"IDAT", zlib.compress(scanlines, 9)))
        f.write(chunk(b"IEND", b""))
    uniq = len(set(raw[i:i + 4] for i in range(0, need, 4)))
    nonzero = sum(1 for i in range(0, need, 4) if raw[i:i + 3] != b"\x00\x00\x00")
    print("%s -> %s  %dx%d  unique=%d non-black=%d/%d" %
          (os.path.basename(path), os.path.basename(out), w, h, uniq, nonzero, w * h))
    return out


if __name__ == "__main__":
    if len(sys.argv) < 4:
        sys.exit("usage: rgba_to_png.py <file.rgba> <width> <height> [out.png]")
    png_from_rgba(sys.argv[1], int(sys.argv[2]), int(sys.argv[3]),
                  sys.argv[4] if len(sys.argv) > 4 else None)
