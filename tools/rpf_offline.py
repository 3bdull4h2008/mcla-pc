#!/usr/bin/env python3
"""Offline reader for the MCLA RPF3 archives and their in-guest TOC dumps.

Read-only, and it never decrypts anything. The on-disk TOC (file offset 0x800,
length in the header dword at +4) is opaque ciphertext -- `toc_decrypted.bin`, a
fill-time dump of the guest's read buffer, is byte-identical to the archive at
0x800. The 16-byte-record table this tool parses only exists in a dump of the
guest's own copy taken AFTER the guest has parsed it: there the records are a
cleartext, hash-sorted array (F-099). Names are Jenkins one-at-a-time hashes of
the LEAF ("GtaO", docs/MCLA_RPF3_Technical_Reference.txt section 10), and the
record array holds no path text at all, so a member is looked up by hashing its
leaf, never by grepping a name.

  python tools/rpf_offline.py header   [archive ...]            header fields + TOC size
  python tools/rpf_offline.py names    [toc_dump.bin]           dump words that hit a name corpus
  python tools/rpf_offline.py find     <path> [archive|dump]    TOC record(s) for a leaf/path
  python tools/rpf_offline.py member   <off> <len> [archive]    bytes at an archive offset
  python tools/rpf_offline.py islands  <lo> <hi> [archive]      plaintext + entropy map

Defaults: archive build/game_data/xarchive_cache.rpf, dump build/toc_parsed.bin.
The name corpus comes from build/cache/mcla_pe.bin (read-only).

Record schema (cracked in F-096/F-097, restated by F-099): file {GtaO(leaf),
size, file_offset, flag|index}, directory {GtaO(name), 0, 0x8000xxxx,
child_count}. The two classes are told apart by bit31 of the third word, which
is exactly what the code masks (rec[2] & 0x80000000; the index is rec[3] &
0x0FFFFFFF, so no flag bit is assumed to be set on any given record).
"""
import array
import math
import re
import struct
import sys
from collections import Counter

IMAGE = "build/cache/mcla_pe.bin"
IMAGE_BASE = 0x82000000  # guest VA <-> file offset key; unused here -- every offset below is a file offset
TOC_OFF = 0x800          # on-disk TOC start -- the offset the guest's own TOC read asks for (F-099)
DEFAULT_ARCHIVE = "build/game_data/xarchive_cache.rpf"


def gtao(b):
    """Jenkins one-at-a-time over the bytes of `b` (str is UTF-8 encoded first).

    Case-sensitive, and validated against three leaf hashes the guest's own
    parsed table shows: star_glow.fxc=A5EA667B, preload.list=0DB1C876,
    globaltex.list=3D9B8154 (docs/MCLA_RPF3_Technical_Reference.txt section 10;
    the first two are quoted in the F-096/F-099 ledger entries).
    """
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
    """Every complete word of `buf` as a BIG-endian uint32 (byteswapped on an LE
    host, where array('I') must be 4 bytes). The trailing 1-3 bytes are dropped,
    so len(result) == len(buf) // 4 -- a hit on the last word of a short buffer
    therefore has no complete 16-byte record behind it (see names/find).
    """
    a = array.array("I")
    a.frombytes(buf[: len(buf) // 4 * 4])
    if sys.byteorder == "little":
        a.byteswap()
    return a


def name_corpus():
    """Every plausible path/name token in the decompressed guest image.

    Tokens are the 3-64-char runs of [A-Za-z0-9_./\\:-] in IMAGE, keyed by GtaO of
    the whole token and of its '/' and '\\' tails; setdefault keeps the first
    token that produced a given hash, so a printed name is a plausible source,
    not a proof. Only `names` uses this; it is what turns word 0 back into text.
    """
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
        # Measured on all four archives on disk: the RPF3 magic is at file offset
        # 0 (not 0x800) and the dwords after it are LITTLE-endian, while the TOC
        # RECORDS are BIG-endian (F-099). +4 is the length the guest itself reads
        # at off=0x800 -- cache 382976, audlo 18432, audio 30720, music 2048, all
        # exact multiples of the 16-byte record stride. docs/MCLA_RPF3_Technical_
        # Reference.txt sections 2-4 (all-big-endian header at 0x800, TOC at
        # 0x1000, 2048 bytes of leading zeros) do NOT describe these files; this
        # read does, and the BE value is printed alongside only to show the gap.
        # +8 is deliberately not decoded: it sits just under +4/16 (cache 23931
        # vs 23936) and the reference doc labels that slot entry_count.
        toc_len, w8, w12 = struct.unpack_from("<III", hdr, 4)
        print(f"{path}\n  magic={magic!r} size={size} ({size / 2**20:.0f} MiB)")
        print(f"  +4 TOC length={toc_len} (0x{toc_len:X} LE; BE-reading gives {struct.unpack_from('>I', hdr, 4)[0]:X})"
              f" -> TOC spans {TOC_OFF:#x}..{TOC_OFF + toc_len:#x}")
        print(f"  +8={w8:08X} +12={w12:08X} head={hdr[16:32].hex(' ')}")


def names(argv):
    """GtaO-join a TOC dump back to real names -- the only way to read a dump.

    Needs a dump of the PARSED in-guest table (see the module docstring): against
    ciphertext or a zero-filled capture every word simply misses and this prints
    nothing. A dump whose words are not records at all still prints whatever the
    corpus happens to contain, so judge the capture by the printed shapes.
    """
    path = argv[0] if argv else "build/toc_parsed.bin"
    dump = open(path, "rb").read()
    corpus = name_corpus()
    words = be_words(dump)
    # The "chance of a hit" figure is the expected number of FALSE positives of
    # this join (words x corpus / 2**32). It reproduces F-099's honest reading of
    # the 18 KB audio table: 4608 words against a ~38k corpus gives ~0.04 expected
    # hits, and the join actually returned 38 -- quote the two together or neither.
    print(f"{path}: {len(dump)} bytes, {len(words)} words, "
          f"corpus={len(corpus)} name hashes (chance of a hit ~{len(words) * len(corpus) / 2**32:.2f})")
    for i, w in enumerate(words):
        nm = corpus.get(w)
        if not nm:
            continue
        off = i * 4  # every word is tested, not only stride-16 record heads
        rec = struct.unpack_from(">4I", dump, off) if off + 16 <= len(dump) else None
        if rec is None:
            # Final partial word: the matched hash is real but its 4-word record
            # runs past EOF, so there is nothing further to decode.
            print(f"  {off:#08x} tail {nm:34s} (record truncated by EOF)")
            continue
        kind = "dir " if rec[2] & 0x80000000 else "file"
        extra = (f"size={rec[1]} off={rec[2]:#x} idx={rec[3] & 0x0FFFFFFF}"
                 if kind == "file" else
                 f"child={rec[2] & 0x7FFFFFF:#x} count={rec[3]}")
        print(f"  {off:#08x} {kind} {nm:34s} {extra}")


def find(argv):
    """Scan every word of a TOC for GtaO(leaf), plus GtaO(full path) when the
    argument carries a separator -- the records themselves store only the leaf.

    A zero here is not an answer until a control passes: run a leaf the boot
    provably opened (F-148: always run the control before citing a find
    negative). Against a parsed dump a hit prints as its 4 big-endian words.
    """
    if not argv:
        sys.exit("find <path> [archive|toc_dump]")
    want, src = argv[0], argv[1] if len(argv) > 1 else DEFAULT_ARCHIVE
    leaf = want.replace("\\", "/").rsplit("/", 1)[-1]
    blob = open(src, "rb").read()
    # The only test between archive and dump is the leading magic: an archive is
    # sliced to 0x800..0x800+LE(+4) (its TOC region), anything else is searched
    # whole as a dump. So a dump that begins with those four bytes is sliced too.
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
            if off + 16 > len(toc):
                # Hit on the last 1-3 words: no full 16-byte record fits, so report
                # the offset and the matching word without unpacking.
                print(f"  {off:#08x} tail {targets[w]:24s} {w:08X} (record truncated by EOF)")
                hits += 1
                continue
            rec = struct.unpack_from(">4I", toc, off)
            kind = "dir " if rec[2] & 0x80000000 else "file"
            print(f"  {off:#08x} {kind} {targets[w]:24s} "
                  f"{rec[0]:08X} {rec[1]:08X} {rec[2]:08X} {rec[3]:08X}")
            hits += 1
    print(f"  {hits} record(s); the TOC stores leaf hashes, not paths, so a dir/file "
          f"pair can share one word")


def member(argv):
    """Hexdump + printable-run report for one span of an archive.

    `off` is a raw file offset -- the same number names/find print as off=, so a
    record's third word can be read straight back out of the file. Low printable %
    is NOT evidence of absence: F-148 established that member bodies are stored
    transformed, so a present, correctly-offset member still reads as high-entropy
    bytes. A read past EOF is silently short, which is why the count prints len(b)
    rather than the requested length.
    """
    if len(argv) < 2:
        sys.exit("member <off> <len> [archive]")
    off, ln = int(argv[0], 0), int(argv[1], 0)
    archive = argv[2] if len(argv) > 2 else DEFAULT_ARCHIVE
    with open(archive, "rb") as f:
        f.seek(off)
        b = f.read(ln)
    asc = sum(1 for c in b if 32 <= c < 127)  # space..tilde only; CR/LF excluded here
    print(f"{archive} {off:#x}+{len(b)}: printable {asc}/{len(b)} "
          f"({100 * asc // max(1, len(b))}%)")
    print(f"  head {b[:64].hex(' ')}")
    for o, r in [(m.start(), m.group()) for m in re.finditer(rb"[ -~\r\n]{8,}", b)][:20]:
        print(f"  {off + o:#x} {r.decode('latin1')[:96]!r}")


def islands(argv):
    """Map where an archive span looks like plaintext: 12+ char text runs plus a
    per-512-byte-block entropy histogram.

    The block list covers COMPLETE 512-byte blocks only and never samples the
    final partial one, so a window of 512 bytes or less reports "0 of 0" blocks
    and says nothing about entropy; widen it before concluding. 6.5 bits/byte is
    the cut used to call a block quiet. A reversed range raises ValueError from
    f.read (and hi-lo of exactly -1 would read to EOF), so lo < hi is the
    caller's job.
    """
    if len(argv) < 2:
        sys.exit("islands <lo> <hi> [archive]")
    lo, hi = int(argv[0], 0), int(argv[1], 0)
    archive = argv[2] if len(argv) > 2 else DEFAULT_ARCHIVE
    with open(archive, "rb") as f:
        f.seek(lo)
        b = f.read(hi - lo)
    print(f"{archive} {lo:#x}..{hi:#x}")
    for m in re.finditer(rb"[ -~\r\n\t]{12,}", b):  # tab counts here, unlike member
        print(f"  text {lo + m.start():#x} {m.group().decode('latin1')[:110]!r}")
    blocks = [(lo + i, ent(b[i:i + 512])) for i in range(0, len(b) - 512, 512)]
    quiet = [(o, e) for o, e in blocks if e < 6.5]
    print(f"  {len(quiet)} of {len(blocks)} 512B blocks below 6.5 bits/byte")
    for o, e in quiet[:30]:
        print(f"    {o:#x} {e:.2f}")


def ent(blk):
    """Shannon entropy of the block in bits/byte (0.0 when empty). Declared after
    its only caller, islands(), which is fine -- the name is resolved at call
    time, not at def time."""
    n = len(blk)
    if not n:
        return 0.0
    return -sum((v / n) * math.log2(v / n) for v in Counter(blk).values())


def main():
    # Dispatch is by name through globals(), so a subcommand is exactly a function
    # name: renaming one silently removes it from the CLI. Exit codes: 0 ran
    # something (AGENTS.md's "informational"), 2 = missing/unknown subcommand (help
    # on stdout), and 1 via sys.exit(str) for the per-subcommand usage errors.
    if len(sys.argv) < 2 or sys.argv[1] not in ("header", "names", "find", "member", "islands"):
        print(__doc__)
        return 2
    globals()[sys.argv[1]](sys.argv[2:])
    return 0


if __name__ == "__main__":
    sys.exit(main())
