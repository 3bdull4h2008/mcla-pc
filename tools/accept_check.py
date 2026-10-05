#!/usr/bin/env python3
"""Acceptance checker: turn a soak log into a pass/fail table.

Covers four acceptance batteries so a finding can be verified in seconds
instead of by hand:
  * F-412 acceptance markers (PARK-UNWIND + frames verdict, the F374/F388
    guard selftests and real trips, HEAPHDR-STORE addresses, the store/watch
    markers),
  * the objective (b) gate tuple from docs/LONG_TODO_MASTER.md T41.10,
  * clause (a) markers (UIXSF-GOLDEN-REVERIFY claimed/pct/first_bad, the
    F409 guard, the layout audit, BC140/LISTLINE/PSTREAM),
  * the regression / fatal markers.

COUNTING CONVENTION: matching LINES, case-insensitive -- byte-for-byte what
`grep -ic MARKER log` returns, i.e. tools/soak_census.py's convention. The
exception-code rows import soak_census.EXC_CODES and therefore count only in
`code=0x...` lines (do-not #22: a PM4 packet argument is not a fault).
Overlapping markers count on BOTH rows, exactly as with grep -- `Fatal error`
includes `Fatal error dispatcher`, `W35-BOOT-GATE` includes
`W35-BOOT-GATE-POST`. Subtract the more specific row when you need the
exclusive number.

One streaming pass per file (40 MB soaks stay fast). Exit code is 0 even when
the table is all FAIL -- this is a reporting tool, not a gate; it returns 2
only when a named log does not exist.

Usage:
    python tools/accept_check.py build/w430.log
    python tools/accept_check.py build/w430.log build/w423.log
    python tools/accept_check.py build/w430.log build/w423.log --json
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, namedtuple
from pathlib import Path

try:
    from soak_census import EXC_CODES
except ImportError:  # running the file by another route than `python tools/...`
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from soak_census import EXC_CODES

# ---------------------------------------------------------------- marker set
# Plain substring rows: one `grep -ic`-style count each, keyed by display label.
LABELS = [
    # F-412
    "PARK-UNWIND", "HEAPHDR-STORE", "F374-HEAPSTORE", "PARAM-STORE",
    "PAGEWATCH", "PHYS-OVERRUN", "LOWPOOL", "F388-PHYSGUARD-BT",
    # objective (b) gate tuple (T41.10)
    "W34-GFX-CENSUS", "W34-NOGFX", "UILOAD-census", "W35-BOOT-GATE",
    "W35-BOOT-GATE-POST", "BOOT-GATE-ENTER", "BOOT-GATE-RETURN", "XSF-INFLATE",
    # clause (a)
    "UIXSF-GOLDEN-REVERIFY", "F409-FILL-GUARD", "UIXSF-LAYOUT-AUDIT",
    "BC140-REC", "LISTLINE", "PSTREAM",
    # regression / fatal
    "Fatal error", "Fatal error dispatcher", "FATAL-SOFT", "REBASE-POISON",
]

# All patterns are matched against the LOWER-CASED line.
RX_FRAMES = re.compile(r"\bframes=(\d+)")
RX_F374_TRIP = re.compile(r"f374-heapguard(?:\s+selftest)?\s+trip=")
RX_F374_DONE = re.compile(r"f374-heapguard\s+selftest\s+done")
RX_F388_TRIP = re.compile(r"f388-physguard(?:\s+selftest)?\s+trip=")
RX_F388_DONE = re.compile(r"f388-physguard\s+selftest\s+done")
RX_SELFTESTS = re.compile(r"\bselftests=(\d+)")
RX_BT_BACKTRACE = re.compile(r"f388-physguard\s+trip=.*backtrace:")
RX_BT_FRAME = re.compile(r"\bframe=(\d+)/(\d+)\s+rva=([0-9a-f]+)\s+inmod=(\d+)")
RX_AT = re.compile(r"@\s*([0-9a-f]+)")           # `@ <HEX>` address
RX_NGFX = re.compile(r"\bngfx=(\d+)")
RX_PKG = re.compile(r"\bpkg=([0-9a-f]+)")
RX_CLAIMED = re.compile(r"\bclaimed=(\d+)")
RX_PCT = re.compile(r"\bpct=(\d+)")
RX_FIRST_BAD = re.compile(r"\bfirst_bad=([0-9a-f]+)")
RX_BASE_N = re.compile(r"\bn=([\d,]+)")
RX_CODE = {c: re.compile(rf"\bcode=0x{c.lower()}\b") for c in EXC_CODES}

Row = namedtuple("Row", "label kind values")


# ---------------------------------------------------------------- scanning
def sniff_encoding(path: Path) -> str:
    """UTF-16 soaks exist in build/ (findstr warns about them); reading one as
    UTF-8 would silently produce an all-zero table -- a zero nobody can tell
    from a clean boot (the F-057(6) trap)."""
    with path.open("rb") as fh:
        bom = fh.read(2)
    return "utf-16" if bom in (b"\xff\xfe", b"\xfe\xff") else "utf-8"


def scan(path: Path) -> dict:
    """Single streaming pass -> counts + everything the table derives."""
    needles = [(lbl, lbl.lower()) for lbl in LABELS]
    counts = dict.fromkeys(LABELS, 0)
    frames: Counter = Counter()
    ngfx: Counter = Counter()
    exc: Counter = Counter()
    trips = {"F374": 0, "F388": 0}
    real_trips = {"F374": 0, "F388": 0}
    done = {"F374": 0, "F388": 0}
    selftests = {"F374": None, "F388": None}
    golden: dict = {}
    hdr_first = hdr_last = None
    hdr_set: set = set()
    claimed_other = 0
    rebase_n = 0
    bt_traces: list = []
    cur_bt = None
    lines = 0

    with path.open("r", encoding=sniff_encoding(path),
                   errors="replace") as fh:
        for line in fh:
            lines += 1
            lo = line.lower()

            for lbl, nd in needles:
                if nd in lo:
                    counts[lbl] += 1

            for code, rx in RX_CODE.items():
                if rx.search(lo):
                    exc[code] += 1

            if "park-unwind" in lo:
                m = RX_FRAMES.search(lo)
                if m:
                    frames[int(m.group(1))] += 1

            if "f374-heapguard" in lo:
                if RX_F374_TRIP.search(lo):
                    trips["F374"] += 1
                    if "selftest=true" not in lo and "selftest trip=" not in lo:
                        real_trips["F374"] += 1
                if RX_F374_DONE.search(lo):
                    done["F374"] += 1
                    m = RX_SELFTESTS.search(lo)
                    if m:
                        selftests["F374"] = int(m.group(1))

            if "f388-physguard" in lo:
                if RX_F388_TRIP.search(lo):
                    trips["F388"] += 1
                    if "selftest=true" not in lo and "selftest trip=" not in lo:
                        real_trips["F388"] += 1
                if RX_F388_DONE.search(lo):
                    done["F388"] += 1
                    m = RX_SELFTESTS.search(lo)
                    if m:
                        selftests["F388"] = int(m.group(1))

            if "backtrace:" in lo and RX_BT_BACKTRACE.search(lo):
                # A backtrace belongs to the trip line that announces it; other
                # threads' lines interleave inside it, so trip lines -- not
                # adjacency -- delimit the traces (w423 interleaves 15 lines
                # into trace #1, which adjacency splitting read as 16 traces).
                if cur_bt is not None:
                    bt_traces.append(cur_bt)
                cur_bt = []
            elif "f388-physguard-bt" in lo:
                m = RX_BT_FRAME.search(lo)
                if cur_bt is None:
                    cur_bt = []
                if m:
                    cur_bt.append({"frame": int(m.group(1)),
                                   "rva": m.group(3),
                                   "inmod": int(m.group(4))})

            if "heaphdr-store" in lo:
                m = RX_AT.search(lo)
                if m:
                    addr = m.group(1).upper()
                    if hdr_first is None:
                        hdr_first = addr
                    hdr_last = addr
                    hdr_set.add(addr)

            if "w34-gfx-census" in lo:
                m = RX_NGFX.search(lo)
                if m:
                    ngfx[int(m.group(1))] += 1

            if "uixsf-golden-reverify" in lo:
                pkg = RX_PKG.search(lo)
                if pkg:
                    claimed = RX_CLAIMED.search(lo)
                    pct = RX_PCT.search(lo)
                    first_bad = RX_FIRST_BAD.search(lo)
                    golden[pkg.group(1).upper()] = {
                        "claimed": int(claimed.group(1)) if claimed else None,
                        "pct": int(pct.group(1)) if pct else None,
                        "first_bad": (first_bad.group(1).upper()
                                      if first_bad else None),
                    }

            if "f409-fill-guard" in lo and "claimed_other_unverified" in lo:
                claimed_other += 1

            if "rebase-poison" in lo:
                m = RX_BASE_N.search(lo)
                if m:
                    v = int(m.group(1).replace(",", ""))
                    if v > rebase_n:
                        rebase_n = v

    if cur_bt is not None:
        bt_traces.append(cur_bt)

    return {
        "path": str(path),
        "name": path.name,
        "bytes": path.stat().st_size,
        "lines": lines,
        "counts": counts,
        "frames": dict(sorted(frames.items())),
        "ngfx": dict(sorted(ngfx.items())),
        "exc": {c: exc.get(c, 0) for c in EXC_CODES},
        "trips": trips,
        "real_trips": real_trips,
        "done": done,
        "selftests": selftests,
        "golden": golden,
        "hdr_first": hdr_first,
        "hdr_last": hdr_last,
        "hdr_distinct": len(hdr_set),
        "claimed_other": claimed_other,
        "rebase_n": rebase_n,
        "bt_traces": bt_traces,
    }


# ---------------------------------------------------------------- rendering
def fmt(v) -> str:
    if v is None:
        return "-"
    if isinstance(v, int):
        return f"{v:,}"
    return str(v)


def dfmt(base, other) -> str:
    if isinstance(base, int) and isinstance(other, int):
        return f"{other - base:+,}"
    return "-"


def ranges(nums) -> str:
    """Lossless run-length rendering of a frame list: [0..15] -> `0-15`."""
    out, start, prev = [], None, None
    for n in sorted(set(nums)):
        if start is None:
            start = prev = n
        elif n == prev + 1:
            prev = n
        else:
            out.append(str(start) if start == prev else f"{start}-{prev}")
            start = prev = n
    if start is not None:
        out.append(str(start) if start == prev else f"{start}-{prev}")
    return ",".join(out) or "-"


def hist(counter: dict) -> str:
    return " ".join(f"{k}:{v}" for k, v in sorted(counter.items())) or "-"


def park_verdict(log: dict) -> str:
    if not log["frames"]:
        return "NO DATA"
    return "PASS" if max(log["frames"]) >= 3 else "FAIL"


def done_str(log: dict, key: str) -> str:
    st = log["selftests"][key]
    return f'{log["done"][key]} selftests={st if st is not None else "-"}'


def hdr_range(log: dict) -> str:
    if log["hdr_first"] is None:
        return "- dist=0"
    return (f'{log["hdr_first"]}..{log["hdr_last"]}'
            f' dist={log["hdr_distinct"]}')


def bt_list(log: dict) -> str:
    tr = log["bt_traces"]
    if not tr:
        return "-"
    return (f"{len(tr)} traces: "
            + " | ".join(ranges(e["frame"] for e in t) for t in tr))


def gate_b(log: dict) -> str:
    """T41.10's gate tuple: nGfx>0 + UILOAD/W35/W35-POST/XSF-INFLATE>0 +
    W34-NOGFX->0. Reported per log, never as an exit code."""
    fails = []
    if not any(k > 0 for k in log["ngfx"]):
        fails.append("gfx")
    if log["counts"]["UILOAD-census"] == 0:
        fails.append("uil")
    if log["counts"]["W35-BOOT-GATE"] == 0:
        fails.append("gate")
    if log["counts"]["W35-BOOT-GATE-POST"] == 0:
        fails.append("post")
    if log["counts"]["XSF-INFLATE"] == 0:
        fails.append("inf")
    if log["counts"]["W34-NOGFX"] != 0:
        fails.append("nogfx")
    return "PASS" if not fails else "FAIL(" + ",".join(fails) + ")"


def build_sections(logs: list) -> list:
    c = [l["counts"] for l in logs]

    f412 = [
        Row("PARK-UNWIND rows", "count", [c[i]["PARK-UNWIND"]
                                           for i in range(len(logs))]),
        Row("  frames histogram", "text", [hist(l["frames"]) for l in logs]),
        Row("  verdict (any frames>=3)", "text", [park_verdict(l)
                                                  for l in logs]),
        Row("F374-HEAPGUARD trip total", "count", [l["trips"]["F374"]
                                                   for l in logs]),
        Row("F374-HEAPGUARD SELFTEST done", "text", [done_str(l, "F374")
                                                     for l in logs]),
        Row("F374-HEAPGUARD real trips", "count", [l["real_trips"]["F374"]
                                                   for l in logs]),
        Row("F388-PHYSGUARD trip total", "count", [l["trips"]["F388"]
                                                   for l in logs]),
        Row("F388-PHYSGUARD SELFTEST done", "text", [done_str(l, "F388")
                                                     for l in logs]),
        Row("F388-PHYSGUARD real trips", "count", [l["real_trips"]["F388"]
                                                   for l in logs]),
        Row("F388-PHYSGUARD-BT frames", "count", [sum(map(len, l["bt_traces"]))
                                                  for l in logs]),
        Row("F388-PHYSGUARD-BT frame list", "text", [bt_list(l)
                                                     for l in logs]),
        Row("HEAPHDR-STORE rows", "count", [c[i]["HEAPHDR-STORE"]
                                            for i in range(len(logs))]),
        Row("HEAPHDR-STORE first/last/distinct", "text", [hdr_range(l)
                                                          for l in logs]),
    ]
    f412 += [Row(m, "count", [c[i][m] for i in range(len(logs))])
             for m in ("F374-HEAPSTORE", "PARAM-STORE", "PAGEWATCH",
                       "PHYS-OVERRUN", "LOWPOOL")]

    gate = [
        Row("W34-GFX-CENSUS rows", "count", [c[i]["W34-GFX-CENSUS"]
                                             for i in range(len(logs))]),
        Row("W34-GFX-CENSUS nGfx values", "text", [hist(l["ngfx"])
                                                   for l in logs]),
        Row("W34-NOGFX", "count", [c[i]["W34-NOGFX"] for i in range(len(logs))]),
        Row("UILOAD-census", "count", [c[i]["UILOAD-census"]
                                       for i in range(len(logs))]),
        Row("W35-BOOT-GATE", "count", [c[i]["W35-BOOT-GATE"]
                                       for i in range(len(logs))]),
        Row("W35-BOOT-GATE-POST", "count", [c[i]["W35-BOOT-GATE-POST"]
                                            for i in range(len(logs))]),
        Row("BOOT-GATE-ENTER", "count", [c[i]["BOOT-GATE-ENTER"]
                                         for i in range(len(logs))]),
        Row("BOOT-GATE-RETURN", "count", [c[i]["BOOT-GATE-RETURN"]
                                          for i in range(len(logs))]),
        Row("XSF-INFLATE", "count", [c[i]["XSF-INFLATE"]
                                     for i in range(len(logs))]),
        Row("gate (b) verdict", "text", [gate_b(l) for l in logs]),
    ]

    pkgs = sorted({p for l in logs for p in l["golden"]})
    clause = [
        Row("UIXSF-GOLDEN-REVERIFY rows", "count",
            [c[i]["UIXSF-GOLDEN-REVERIFY"] for i in range(len(logs))]),
    ]
    for pkg in pkgs:
        for field in ("claimed", "pct", "first_bad"):
            clause.append(Row(
                f"  pkg={pkg} {field}",
                "text" if field == "first_bad" else "count",
                [l["golden"].get(pkg, {}).get(field) for l in logs]))
    clause += [
        Row("F409-FILL-GUARD rows", "count",
            [c[i]["F409-FILL-GUARD"] for i in range(len(logs))]),
        Row("F409-FILL-GUARD CLAIMED_OTHER_UNVERIFIED", "count",
            [l["claimed_other"] for l in logs]),
        Row("UIXSF-LAYOUT-AUDIT rows", "count",
            [c[i]["UIXSF-LAYOUT-AUDIT"] for i in range(len(logs))]),
        Row("BC140-REC rows", "count", [c[i]["BC140-REC"]
                                        for i in range(len(logs))]),
        Row("LISTLINE rows", "count", [c[i]["LISTLINE"]
                                       for i in range(len(logs))]),
        Row("PSTREAM rows", "count", [c[i]["PSTREAM"]
                                      for i in range(len(logs))]),
    ]

    regress = [
        Row("C0000005", "count", [l["exc"]["C0000005"] for l in logs]),
        Row("Fatal error", "count", [c[i]["Fatal error"]
                                     for i in range(len(logs))]),
        Row("FATAL-SOFT", "count", [c[i]["FATAL-SOFT"]
                                    for i in range(len(logs))]),
        Row("REBASE-POISON rows", "count", [c[i]["REBASE-POISON"]
                                            for i in range(len(logs))]),
        Row("REBASE-POISON n= (max)", "count", [l["rebase_n"] for l in logs]),
        Row("Fatal error dispatcher", "count",
            [c[i]["Fatal error dispatcher"] for i in range(len(logs))]),
    ]

    return [
        ("== F-412 acceptance markers ==", f412),
        ("== objective (b) gate tuple (T41.10) ==", gate),
        ("== clause (a) markers ==", clause),
        ("== regression / fatal markers ==", regress),
    ]


def print_table(sections: list, logs: list) -> None:
    for title, rows in sections:
        labels = [title] + [r.label for r in rows]
        lab_w = max(len(x) for x in labels)

        cells = []
        for r in rows:
            row = [fmt(r.values[0])]
            for i in range(1, len(logs)):
                row.append(fmt(r.values[i]))
                row.append(dfmt(r.values[0], r.values[i]))
            cells.append(row)

        heads = [logs[0]["name"] if len(logs) == 1
                 else f"{logs[0]['name']}(BASE)"]
        for i in range(1, len(logs)):
            heads += [logs[i]["name"], "DELTA"]
        widths = [max([len(h)] + [len(row[j]) for row in cells])
                  for j, h in enumerate(heads)]

        print(f"{title:<{lab_w}}  "
              + "  ".join(h.rjust(w) for h, w in zip(heads, widths)))
        for r, row in zip(rows, cells):
            print((f"{r.label:<{lab_w}}  "
                   + "  ".join(c.rjust(w)
                               for c, w in zip(row, widths))).rstrip())
        print()


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="+", type=Path, metavar="LOG",
                    help="soak log(s); the FIRST one is the BASE column")
    ap.add_argument("--json", action="store_true",
                    help="emit machine-readable JSON instead of the table")
    args = ap.parse_args()

    missing = [p for p in args.logs if not p.is_file()]
    if missing:
        for p in missing:
            print(f"error: no such log: {p}", file=sys.stderr)
        return 2

    logs = [scan(p) for p in args.logs]
    sections = build_sections(logs)

    if args.json:
        out = {
            "tool": "tools/accept_check.py",
            "counting": ("case-insensitive matching lines (grep -ic / "
                         "tools/soak_census.py); exception codes only in "
                         "code=0x lines; overlapping markers count on both rows"),
            "base": logs[0]["path"],
            "logs": [{k: l[k] for k in
                      ("path", "name", "bytes", "lines")} for l in logs],
            "sections": [{"title": t,
                          "rows": [{"label": r.label, "kind": r.kind,
                                    "values": list(r.values),
                                    "delta": [None if i == 0 or not (
                                        isinstance(r.values[0], int)
                                        and isinstance(r.values[i], int))
                                        else r.values[i] - r.values[0]
                                        for i in range(len(logs))]}
                                   for r in rows]}
                         for t, rows in sections],
            "parsed": [{k: l[k] for k in
                        ("name", "frames", "ngfx", "trips", "real_trips",
                         "done", "selftests", "golden", "hdr_first",
                         "hdr_last", "hdr_distinct", "claimed_other",
                         "rebase_n", "bt_traces", "exc")} for l in logs],
        }
        print(json.dumps(out, indent=1, sort_keys=True))
        return 0

    print("# accept_check -- soak acceptance table")
    print("# counts = matching LINES, case-insensitive = `grep -ic MARKER log`"
          " (tools/soak_census.py convention);")
    print("#   exception codes count only in `code=0x...` lines (do-not #22);"
          " overlapping markers count on both rows")
    print("#   (`Fatal error` includes `Fatal error dispatcher`,"
          " `W35-BOOT-GATE` includes `W35-BOOT-GATE-POST`).")
    print("# first log is the BASE column; DELTA = log - BASE."
          " Exit 0 (report only); exit 2 if a log is missing.")
    for l in logs:
        print(f"# {l['name']}: {l['bytes']:,} bytes, {l['lines']:,} lines")
    print()
    print_table(sections, logs)
    return 0


if __name__ == "__main__":
    sys.exit(main())
