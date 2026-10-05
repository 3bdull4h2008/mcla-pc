#!/usr/bin/env python3
"""AK: extract the WINWR census rows from a soak log.

Read-only. Written because `tools/soak_census.py` is owned by another agent and
WINWR-WATCH / WINWR-REC are not yet in its tracked list (measured: 0 mentions of
either name in soak_census.py), so there is no tracked counter for them yet.

COUNTING METHOD, per the project's own rule and not findstr: every count here is
a byte count over the lower-cased file, i.e. exactly
    open(f,'rb').read().lower().count(b'...')
Case-insensitive, matching LINES. Nothing is inferred and nothing is filtered.

WHAT IT ANSWERS:
  * how many rows each marker printed
  * the LAST row of each, which is the one that carries the running `tot=`
  * the distinct src8= values and which of the two candidates they are
  * the hit= / slots= distribution, so "the gate never matched" can be told
    apart from "the function was never entered"
  * an explicit verdict line per candidate

Usage:  python tools/ak_winwr_extract.py <soak.log> [more.log ...]
Exit:   0 always. It reports; it does not gate.
"""
import re
import sys

# The two candidate 8-byte sequences, from the measured window content.
CAND_DEFLATE = "507B5CED"   # the byte-swapped raw DEFLATE/zlib stream header
CAND_BODY = "61786772"      # 'rgxa', the word the fatal compares against


def read_bytes_lower(path):
    with open(path, "rb") as f:
        return f.read().lower()


def field(line, key):
    """Last `key=` token's value on a log line."""
    m = re.findall(re.escape(key) + r"=([^\s]*)", line)
    return m[-1] if m else None


def report(path):
    raw = read_bytes_lower(path)
    text = raw.decode("utf-8", "replace")
    lines = text.split("\n")

    print("=" * 78)
    print("LOG: %s" % path)
    print("  file bytes = %d" % len(raw))

    for marker in (b"winwr-watch", b"winwr-rec"):
        n = raw.count(marker)
        rows = [l for l in lines if marker.decode() in l]
        print("-" * 78)
        print("%s : byte-count = %d   matching lines = %d"
              % (marker.decode().upper(), n, len(rows)))
        if not rows:
            print("  NO ROWS. For WINWR-WATCH that means one of:")
            print("    (a) the gate never matched      -> check hit=/slots= below")
            print("    (b) sub_821CBE18 was never entered on this path. NOTE the")
            print("        call is CONDITIONAL: raw 0x821CCB7C/0x821CCB80 skip")
            print("        sub_821CBE18 unless [reader+296] == 0x8000, so a zero")
            print("        here is evidence about the CALL SITE, not the bytes.")
            print("    (c) the boot never got this far.")
            continue

        last = rows[-1]
        print("  LAST ROW (carries the running tot=):")
        print("    " + last.strip())

        tot = field(last, "tot")
        hit = field(last, "hit")
        slots = field(last, "slots")
        print("  tot=%s   hit=%s   slots=%s" % (tot, hit, slots))

        if marker == b"winwr-watch":
            srcs = {}
            for l in rows:
                v = field(l, "src8")
                srcs[v] = srcs.get(v, 0) + 1
            print("  src8 values seen:")
            for v, c in sorted(srcs.items(), key=lambda kv: -kv[1]):
                if v is None:
                    continue
                if v.upper().startswith(CAND_DEFLATE):
                    kind = "  <== CANDIDATE: SOURCE ALREADY DEFLATE (host buffer bug)"
                elif v.upper().startswith(CAND_BODY):
                    kind = "  <== CANDIDATE: SOURCE IS the inflated body (offset arithmetic)"
                else:
                    kind = ""
                print("    %-18s x%-4d%s" % (v, c, kind))
            cp = {}
            for l in rows:
                cp[field(l, "copied")] = cp.get(field(l, "copied"), 0) + 1
            print("  copied= distribution: %s" % cp)
            s0 = {}
            for l in rows:
                s0[field(l, "s0ok")] = s0.get(field(l, "s0ok"), 0) + 1
            print("  s0ok=   distribution: %s   (1 = the active guest view agrees "
                  "with the heap read)" % s0)
            da = {}
            for l in rows:
                da[field(l, "dstafter")] = da.get(field(l, "dstafter"), 0) + 1
            print("  dstAfter= distribution: %s" % da)
        else:
            for k in ("rec4", "rec8", "rec0", "rec12"):
                vals = {}
                for l in rows:
                    vals[field(l, k)] = vals.get(field(l, k), 0) + 1
                print("  %-5s values: %s" % (k, vals))
    print("")


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    for p in sys.argv[1:]:
        try:
            report(p)
        except OSError as e:
            print("CANNOT READ %s : %s" % (p, e))
    return 0


if __name__ == "__main__":
    sys.exit(main())
