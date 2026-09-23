#!/usr/bin/env python3
"""Offline reader for the MCLA RPF3 archives and their in-guest TOC dumps.

Everything here is read-only and needs no AES break: the TOC record array (file
offset 0x800, length given by the header) is a flat table of 16-byte records whose
names are Jenkins one-at-a-time hashes ("GtaO", docs/MCLA_RPF3_Technical_Reference.txt
section 10), so members can be located by hashing a candidate path.

  python tools/rpf_offline.py header   [archive ...]     header fields + TOC size
  python tools/rpf_offline.py names    <toc_dump.bin>    name-hashed records of a dump
  python tools/rpf_offline.py find     <path> [archive]  TOC record(s) for a path/leaf
  python tools/rpf_offline.py member   <off> <len>      bytes at an archive offset
  python tools/rpf_offline.py islands  <lo> <hi>        plaintext + entropy map

Record schema (F-098/F-099): file {GtaO(leaf), size, file_offset, 0x40000000|index};
directory {GtaO(name), 0, 0x8000xxxx, child_count}.
"""
import array
import math
import re
import struct
import sys
from collections import Counter

IMAGE = "build/cache/mcla_pe.bin"
IMAGE_BASE = 0x82000000
TOC_OFF = 0x800
DEFAULT_ARCHIVE = "build/game_data/xarchive_cache.rpf"


def gtao(b):
    if isinstance(b, str):
        b = b.encode()
    h = 0
    for c in b:
        h = (h + c) & 0xFFFFFFFF
        h = (h + (h << 10)) & 0xFFFFFFFF
        h ^= h >> 6
    h = (h + (h << 3)) & 0xFFFFFFFF
    h ^= h >> 11
    return (h + (h << 15)) & 0xFFFFFFFF


def be_words(buf):
    a = array.array("I")
    a.frombytes(buf[: len(buf) // 4 * 4])
    if sys.byteorder == "little":
        a.byteswap()
    return a


def name_corpus():
    """Every plausible path/name token in the decompressed guest image."""
    try:
        img = open(IMAGE, "rb").read()
    except OSError:
        sys.exit(f"missing {IMAGE} (decompressed guest image; see PROGRAM_GUIDE section 4)")
    out = {}
    for tok in re.findall(rb"[A-Za-z0-9_./\\:-]{3,64}", img):
        for key in (tok, tok.rsplit(b"/", 1)[-1], tok.rsplit(b"\\", 1)[-1]):
            out.setdefault(gtao(key), key.decode(errors="replace"))
    return out


def header(argv):
    for path in argv or [DEFAULT_ARCHIVE]:
        with open(path, "rb") as f:
            hdr = f.read(64)
            size = f.seek(0, 2)
        magic = hdr[:4]
        # Header dwords are little-endian (PE-style) while the TOC records are
        # big-endian -- the guest asks for exactly this length at 0x800 (F-099).
        toc_len, w8, w12 = struct.unpack_from("<III", hdr, 4)
        print(f"{path}\n  magic={magic!r} size={size} ({size / 2**20:.0f} MiB)")
        print(f"  +4 TOC length={toc_len} (0x{toc_len:X} LE; BE-reading gives {struct.unpack_from('>I', hdr, 4)[0]:X})"
              f" -> TOC spans {TOC_OFF:#x}..{TOC_OFF + toc_len:#x}")
        print(f"  +8={w8:08X} +12={w12:08X} head={hdr[16:32].hex(' ')}")


def names(argv):
    path = argv[0] if argv else "build/toc_parsed.bin"
    dump = open(path, "rb").read()
    corpus = name_corpus()
    words = be_words(dump)
    print(f"{path}: {len(dump)} bytes, {len(words)} words, "
          f"corpus={len(corpus)} name hashes (chance of a hit ~{len(words) * len(corpus) / 2**32:.2f})")
    for i, w in enumerate(words):
        nm = corpus.get(w)
        if not nm:
            continue
        off = i * 4
        rec = struct.unpack_from(">4I", dump, off) if off + 16 <= len(dump) else (w,)
        kind = "dir " if len(rec) == 4 and rec[2] & 0x80000000 else "file"
        extra = (f"size={rec[1]} off={rec[2]:#x} idx={rec[3] & 0x0FFFFFFF}"
                 if kind == "file" else
                 f"child={rec[2] & 0x7FFFFFF:#x} count={rec[3]}")
        print(f"  {off:#08x} {kind} {nm:34s} {extra}")


def find(argv):
    if not argv:
        sys.exit("find <path> [archive|toc_dump]")
    want, src = argv[0], argv[1] if len(argv) > 1 else DEFAULT_ARCHIVE
    leaf = want.replace("\\", "/").rsplit("/", 1)[-1]
    blob = open(src, "rb").read()
    if blob[:4] == b"RPF3":
        toc_len = struct.unpack_from("<I", blob, 4)[0]
        toc = blob[TOC_OFF:TOC_OFF + toc_len]
        note = ("raw archive: its TOC is encrypted, so 0 records here is EXPECTED "
                "even when the in-guest copy resolves (F-099)")
    else:
        toc = blob
        note = "raw TOC dump (in-guest copy)"
    targets = {gtao(leaf): leaf}
    if want != leaf:
        targets[gtao(want)] = want
    words = be_words(toc)
    print(f"{src}: searching {len(toc)} bytes ({note})")
    hits = 0
    for i, w in enumerate(words):
        if w in targets:
            off = i * 4
            rec = struct.unpack_from(">4I", toc, off)
            kind = "dir " if rec[2] & 0x80000000 else "file"
            print(f"  {off:#08x} {kind} {targets[w]:24s} "
                  f"{rec[0]:08X} {rec[1]:08X} {rec[2]:08X} {rec[3]:08X}")
            hits += 1
    print(f"  {hits} record(s); the TOC stores leaf hashes, not paths, so a dir/file "
          f"pair can share one word")


def member(argv):
    if len(argv) < 2:
        sys.exit("member <off> <len> [archive]")
    off, ln = int(argv[0], 0), int(argv[1], 0)
    archive = argv[2] if len(argv) > 2 else DEFAULT_ARCHIVE
    with open(archive, "rb") as f:
        f.seek(off)
        b = f.read(ln)
    asc = sum(1 for c in b if 32 <= c < 127)
    print(f"{archive} {off:#x}+{len(b)}: printable {asc}/{len(b)} "
          f"({100 * asc // max(1, len(b))}%)")
    print(f"  head {b[:64].hex(' ')}")
    for o, r in [(m.start(), m.group()) for m in re.finditer(rb"[ -~\r\n]{8,}", b)][:20]:
        print(f"  {off + o:#x} {r.decode('latin1')[:96]!r}")


def islands(argv):
    if len(argv) < 2:
        sys.exit("islands <lo> <hi> [archive]")
    lo, hi = int(argv[0], 0), int(argv[1], 0)
    archive = argv[2] if len(argv) > 2 else DEFAULT_ARCHIVE
    with open(archive, "rb") as f:
        f.seek(lo)
        b = f.read(hi - lo)
    print(f"{archive} {lo:#x}..{hi:#x}")
    for m in re.finditer(rb"[ -~\r\n\t]{12,}", b):
        print(f"  text {lo + m.start():#x} {m.group().decode('latin1')[:110]!r}")
    blocks = [(lo + i, ent(b[i:i + 512])) for i in range(0, len(b) - 512, 512)]
    quiet = [(o, e) for o, e in blocks if e < 6.5]
    print(f"  {len(quiet)} of {len(blocks)} 512B blocks below 6.5 bits/byte")
    for o, e in quiet[:30]:
        print(f"    {o:#x} {e:.2f}")


def ent(blk):
    n = len(blk)
    if not n:
        return 0.0
    return -sum((v / n) * math.log2(v / n) for v in Counter(blk).values())


def main():
    if len(sys.argv) < 2 or sys.argv[1] not in ("header", "names", "find", "member", "islands"):
        print(__doc__)
        return 2
    globals()[sys.argv[1]](sys.argv[2:])
    return 0


if __name__ == "__main__":
    sys.exit(main())
