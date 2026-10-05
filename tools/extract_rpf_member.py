#!/usr/bin/env python3
"""Extract a retail RPF3 member out of xarchive_cache.rpf without booting.

The TOC record array on disk is AES (F-099), but the guest publishes the
{leafHash, size, file_offset, flags} quadruple for every member it resolves in its
own `TOC76-XSF` lines. This takes those numbers from a soak log, reads the span,
raw-inflates it (the same headerless DEFLATE family as F-105's .list spans and
F-149's entity.type spans) and writes the member out.

  python tools/extract_rpf_member.py <log> [path-substring ...]

Members whose span does not inflate are reported and skipped rather than guessed at.
"""
import os
import re
import sys
import zlib

ARCHIVE = "build/game_data/xarchive_cache.rpf"
RECORD = re.compile(
    r"TOC76-XSF #\d+ ret=\w+ path='([^']+)' "
    r"\[([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8})")


def published(log):
    """path -> (hash, size, offset, flags); first record wins, as the guest saw it."""
    out = {}
    with open(log, "rb") as f:
        text = f.read().decode("utf8", "replace")
    for m in RECORD.finditer(text):
        path = m.group(1)
        if path in out:
            continue
        out[path] = tuple(int(m.group(i), 16) for i in range(2, 6))
    return out


def read_member(archive, off, size):
    """Raw-inflate `size` logical bytes starting at archive offset `off`."""
    with open(archive, "rb") as f:
        f.seek(off)
        raw = f.read(size + 0x4000)
    try:
        return zlib.decompressobj(-15).decompress(raw, size * 2 + 64)
    except zlib.error:
        return None


def main():
    log = sys.argv[1] if len(sys.argv) > 1 else "build/w160.log"
    pats = sys.argv[2:] or [""]
    recs = published(log)
    print("%d distinct published members in %s" % (len(recs), log))
    outdir = "build/assets"
    os.makedirs(outdir, exist_ok=True)
    got = 0
    for path, (h, size, off, flags) in sorted(recs.items()):
        if not any(p in path for p in pats):
            continue
        data = read_member(ARCHIVE, off, size)
        if data is None:
            print("  skip (no deflate) %-52s off=%08X size=%d" % (path, off, size))
            continue
        if len(data) != size:
            print("  skip (inflated %d != TOC %d) %s" % (len(data), size, path))
            continue
        name = path.replace("/", "_")
        with open(os.path.join(outdir, name), "wb") as f:
            f.write(data)
        print("  ok %-56s -> %s (%d B, off=%08X)" % (path, name, size, off))
        got += 1
    print("%d member(s) written to %s" % (got, outdir))
    return 0 if got else 1


if __name__ == "__main__":
    sys.exit(main())
