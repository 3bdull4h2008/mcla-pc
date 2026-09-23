#!/usr/bin/env python3
"""Marker census for MCLA PC boot soaks -- the machine behind `mcla-log-census`.

Counts every documented log marker and prints new-vs-baseline columns with
deltas. Counts are matching LINES, case-insensitive -- byte-for-byte what
`grep -ic MARKER log` returns, so any number here can be re-checked by hand.
Overlapping markers (`INFLATE` and `INFLATE-SKIP`) both count, exactly as with
grep; subtract the more specific row when you need the exclusive number.

The marker list is DERIVED from docs/PROGRAM_GUIDE.md sec 9 (the marker
inventory) so this tool cannot drift from the documented vocabulary; the
frontier battery that sec 9 does not cover (exception codes, GFx, fatals,
DRAW_INDEXED) is appended explicitly below.

Usage:
    python tools/soak_census.py build/w38a.log
    python tools/soak_census.py build/w38a.log build/smoke_long2.log
    python tools/soak_census.py build/w38a.log --markers GFx,UILOAD
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
GUIDE = REPO / "docs" / "PROGRAM_GUIDE.md"

# Markers that gate a claim but are not part of the sec 9 hook vocabulary: host
# exception codes, the UI/GFx frontier, guest fatal dispatch, and the draw path.
FRONTIER = [
    "C0000005", "C0000003", "C000001D", "C000008E", "80000003", "406D1388",
    "GFx", "GFX-CTOR", "GFX-CTOR-VT-MISMATCH", "GFX-BLOCK", "GFX-ALLOC",
    "W34-NOGFX", "W34-GFX-CENSUS", "FACTORY", "Fatal error", "fatal", "assert",
    "boot-worker AV", "VEH", "PRESENT",
    "DRAW_INDEXED", "PRESENT-FB", "rptrWB", "MmAllocatePhysicalMemoryEx",
    "swfCMD", "PUT=",
]

# The crash-path signals: one marker per thing the handler can DO with a fault.
# Regenerated 2026-09-20 21:45 from the live format strings, because the previous
# list carried 8 markers that exist nowhere in src/ (T38.3(a) deleted those paths)
# and omitted the one park that does -- so "all recovery markers are 0" was a
# tautology, not a verdict (F-057(6)). `dead_tracked()` below now fails loudly
# instead of letting that happen again.
VEH_PATHS = [
    "VEH-NEUTRAL",          # handler declined -> EXCEPTION_CONTINUE_SEARCH (honest)
    "VEH W0: parking thread",  # src/boot_host.cpp:1064, the generic park
]


def src_blob() -> str:
    """`src/` plus the recompiler output, lower-cased, for the marker-truth check.

    A marker can legitimately live outside `src/` (guest-produced text), so this
    covers every tree that can emit a log line.
    """
    out = []
    for root in ("src", "generated/ppc_xenon"):
        for pat in ("**/*.cpp", "**/*.h"):
            for p in (REPO / root).glob(pat):
                try:
                    out.append(p.read_text(encoding="utf-8", errors="replace"))
                except OSError:
                    pass
    return "\n".join(out).lower()


def marker_tokens(marker: str) -> list[str]:
    """The literal alternatives a doc-style marker name stands for.

    `PROGRAM_GUIDE` sec 9 writes names like `BUDDY76-*`, `GEN76-ALLOC/FREE` and
    `TEXINSERT(2)`; matching those verbatim against the source is a false negative.
    """
    out = []
    for part in re.split(r"[/,]", marker):
        part = part.strip()
        if not part:
            continue
        if part.endswith("-*"):
            out.append(part[:-2])
        elif part.endswith("*"):
            out.append(part[:-1])
        else:
            out.append(re.sub(r"\(\d+\)$", "", part))
    return [t for t in out if t]


def dead_tracked(markers: list[str]) -> list[str]:
    """Tracked markers with no literal anywhere in `src/` or `generated/`.

    Their zero is only *suspicious*, not automatically meaningless: a marker can
    name text the guest itself prints. So report it as a question, never a verdict.
    """
    blob = src_blob()
    return [m for m in markers
            if m and not any(t.lower() in blob for t in marker_tokens(m))]


# Mirrors the short-circuit labels in PROGRAM_GUIDE sec 7. Curated rather than
# parsed out of that prose, because prose would also yield junk tokens (`SEH`,
# `pow2`, `NtReleaseSemaphore`). If sec 7 gains a label, add it here.
SHORT_CIRCUITS_TRACKED = [
    "KDELAY", "FENCE", "ClearTaskJoinBusy", "TASKJOIN", "REBASE-POISON",
    "P10-PRE", "INFLATE-SKIP", "INFLATE-EMPTY", "INFLATE-PENDING",
    "TEXCREATE-SC", "BLIT-OOB-GUARD", "SLOT-READY", "DISCCHK", "DICT-HYDRATE",
    "PARK-SAMPLE", "FATAL-SOFT", "-GATE", "fallback advance", "skip fatal",
]

# Lines matching this are a host short-circuit intercepting a guest failure.
# Presence means "mitigation fired", never "fixed" — see PROGRAM_GUIDE §7.
SHORT_CIRCUIT = re.compile(
    r"skip fatal|delta-0|FATAL-SOFT|fallback advance|-GATE\b|short-circuit"
    r"|advancing RIP|Nuclear advance|patch applied, continuing"
    r"|permanently disabled|already physical|host-serve|REBASE-POISON|PARK-SAMPLE",
    re.IGNORECASE,
)

GUEST_LR = re.compile(r"\blr=([0-9A-Fa-f]{8})\b")
TS_PREFIX = re.compile(r"^\[[0-9:.]+\]\s*(?:\[\w+\]\s*)?")
NUM = re.compile(r"0x[0-9A-Fa-f]+|\d+")
CP_RING = re.compile(r"put=(\d+)\s+rptrWB=([0-9A-Fa-f]+)")
# The waiter line's put/rptrWB pair is NOT the CP's state: `rptrWB` was read from
# a hard-coded address for soaks on end (F-057(1), fixed by T40.4). These two are
# the producer's own words and are the only honest ring signals.
CP_DRAIN = re.compile(r"CP: RING \w DRAIN .*?rptr ([0-9A-Fa-f]{4})->([0-9A-Fa-f]{4})")
CP_PUB = re.compile(r"CP: GUEST-PUB #\d+ dev=[0-9A-Fa-f]+ pub (\d+)->(\d+) put=(\d+)")
LEVEL = re.compile(r"\[(error|warning)\]")
# A line is only evidence of a fault if it reports one. Two exclusions matter:
# hot polling paths (the 30 ms KWFSO/GPU poller at lr=8242FC1C) also carry `lr=`
# and would dominate the census, and mitigation lines that merely *mention*
# fatality (`skip fatal`, `FATAL-SOFT`) are a host short-circuit absorbing a
# guest failure, not a fault report. The 703 baseline VEH events still match,
# because those lines carry `VEH`/`AV` in their own right.
FAULT_LINE = re.compile(
    r"code=0xC0000005|code=0xC0000003|code=0xC000001D|code=0xC000008E"
    r"|code=0x80000003|access violation|\bAV\b"
    r"|\bVEH\b|parking|Fatal error",
    re.IGNORECASE,
)

# An NTSTATUS-looking hex is not an exception. `80000003` counted +1 in w38m.log
# and read as "a new VMX debugtrap", but its only occurrence is a PM4 packet
# argument: `CP-T3-CENSUS op=0x58 … args=80000003 071D82C0 DEADBEEF`. Every real
# fault line in this project prints `code=0x…` (measured over w38n.log:
# C0000005 1/1, 406D1388 1/1, 80000003 0/1), so the codes below are only counted
# in that context. do-not #22 / T41.4.
EXC_CODES = ("C0000005", "C0000003", "C000001D", "C000008E", "80000003",
             "406D1388")


def markers_from_guide(path: Path) -> list[str]:
    """Pull backticked marker tokens out of the §9 inventory table's first column."""
    if not path.exists():
        return []
    text = path.read_text(encoding="utf-8", errors="replace")
    start = text.find("## 9. Census / marker inventory")
    if start < 0:
        return []
    end = text.find("\n## ", start + 1)
    section = text[start:end if end > 0 else len(text)]

    found: list[str] = []
    for line in section.splitlines():
        if not line.startswith("|"):
            continue
        first_cell = line.split("|")[1]
        if "Marker" in first_cell or "---" in first_cell:
            continue
        for tok in re.findall(r"`([^`]+)`", first_cell):
            # Cells like `GETDEV` (+`-E0`/`-E1`) yield suffix fragments; only
            # keep tokens that look like a standalone marker.
            tok = tok.strip()
            if tok and not tok.startswith(("-", "/")) and re.match(r"^[A-Za-z]", tok):
                found.append(tok)
    return found


def shape(ln: str) -> str:
    """A log line with its timestamp and numbers collapsed, so one repeating
    message counts as one shape regardless of its counters and addresses."""
    return NUM.sub("#", TS_PREFIX.sub("", ln)).strip()


def census(path: Path, markers: list[str]) -> dict:
    """Per-marker matching-LINE counts (grep -ic semantics) plus the side censuses."""
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    lower = [ln.lower() for ln in lines]

    def hits(m: str) -> int:
        ml = m.lower()
        if m in EXC_CODES:  # only in an exception-shaped line, see do-not #22
            return sum(1 for ln in lines
                       if ml in ln.lower() and f"code=0x{ml}" in ln.lower())
        return sum(1 for ln in lower if ml in ln)

    by_marker = {m: hits(m) for m in markers}

    rings = CP_RING.findall(text)

    return {
        "path": path,
        "lines": len(lines),
        "bytes": path.stat().st_size,
        "markers": by_marker,
        "lr": Counter(GUEST_LR.findall(text)),
        "lr_fault": Counter(lr for ln in lines if FAULT_LINE.search(ln)
                            for lr in GUEST_LR.findall(ln)),
        "short_circuits": sum(1 for ln in lines if SHORT_CIRCUIT.search(ln)),
        "levels": Counter(m.group(1) for m in LEVEL.finditer(text)),
        "ring_first": rings[0] if rings else None,
        "ring_last": rings[-1] if rings else None,
        "drains": CP_DRAIN.findall(text),
        "pubs": CP_PUB.findall(text),
        "shapes": Counter(shape(ln) for ln in lines if ln.strip()),
    }


def quality(c: dict) -> list[str]:
    """Flag a log that is mostly one repeating host message.

    A mitigation that launders its own fault produces a log whose counts are all
    that mitigation: `w38e.log` was 175 MB of one VEH recovery firing 616,824
    times in 31.7 s, and read naively it looks like a boot that got 616,825
    exceptions further than its predecessor (F-054). Domination by a benign
    poller is reported too but is NOT a defect -- marker counts stay exact.
    """
    out = []
    total = max(c["lines"], 1)
    for s, n in c["shapes"].most_common(3):
        share = n / total
        if share < 0.02:
            continue
        kind = ("MITIGATION/VEH LINE" if SHORT_CIRCUIT.search(s)
                or any(v.lower() in s.lower() for v in VEH_PATHS) else "recurring line")
        out.append(f"{share:.0%} of lines ({n:,}) share one shape [{kind}]: {s[:96]}")
        if kind == "MITIGATION/VEH LINE" and share >= 0.02:
            out.append("  -> POISONED as a measurement of the guest: this log mostly "
                       "records a host loop. Do not name it as a baseline or a delta "
                       "reference; compare the fault-line lr census and the guest "
                       "frontier markers only, and say so in the claim.")
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log", type=Path, help="new soak log")
    ap.add_argument("baseline", type=Path, nargs="?",
                    help="baseline log to compare against (name it in any claim)")
    ap.add_argument("--markers", help="comma-separated subset instead of the full battery")
    ap.add_argument("--unchanged", action="store_true", help="hide markers with no delta")
    ap.add_argument("--top-lr", type=int, default=8, help="guest lr values to show")
    args = ap.parse_args()

    for p in (args.log, args.baseline):
        if p is not None and not p.exists():
            print(f"error: no such log: {p}", file=sys.stderr)
            return 2

    if args.markers:
        ordered = [m.strip() for m in args.markers.split(",") if m.strip()]
        source = "--markers"
    else:
        ordered = list(dict.fromkeys(
            FRONTIER + VEH_PATHS + SHORT_CIRCUITS_TRACKED + markers_from_guide(GUIDE)))
        source = f"frontier + {GUIDE.name} sec 7/9 batteries"

    new = census(args.log, ordered)
    old = census(args.baseline, ordered) if args.baseline else None

    print(f"# soak census -- {new['path'].name}")
    print(f"#   {new['lines']:,} lines / {new['bytes']:,} bytes")
    print(f"#   markers from: {source} ({len(ordered)} tracked)")
    print("#   counts are matching LINES, case-insensitive (grep -ic compatible)")
    for line in quality(new):
        print(f"#   LOG QUALITY: {line}")
    for m in sorted(set(dead_tracked(VEH_PATHS + SHORT_CIRCUITS_TRACKED
                                     + FRONTIER + markers_from_guide(GUIDE)))):
        print(f"#   MARKER NOT IN SRC: '{m}' -- no such literal in src/ or generated/; its zero is unexplained (F-057(6))")
    if old:
        print(f"#   baseline: {old['path'].name} ({old['lines']:,} lines)")
        for line in quality(old):
            print(f"#   BASELINE QUALITY {old['path'].name}: {line}")
    print()

    name_w = max(max((len(m) for m in ordered), default=10), 7)
    if old:
        print(f"{'MARKER':<{name_w}}  {'NEW':>8}  {'BASE':>8}  {'DELTA':>8}")
    else:
        print(f"{'MARKER':<{name_w}}  {'COUNT':>8}")

    shown = 0
    for m in ordered:
        n = new["markers"][m]
        if old:
            o = old["markers"][m]
            d = n - o
            if args.unchanged and d == 0:
                continue
            mark = "" if d == 0 else ("  <<" if d > 0 else "  >>")
            print(f"{m:<{name_w}}  {n:>8,}  {o:>8,}  {d:>+8,}{mark}")
        else:
            if args.unchanged and n == 0:
                continue
            print(f"{m:<{name_w}}  {n:>8,}")
        shown += 1
    if shown == 0:
        print("(no marker changed)")

    print()
    print(f"[error] lines:   {new['levels'].get('error', 0):,}"
          + (f"   (baseline {old['levels'].get('error', 0):,})" if old else ""))
    print(f"[warning] lines: {new['levels'].get('warning', 0):,}"
          + (f"   (baseline {old['levels'].get('warning', 0):,})" if old else ""))
    print(f"host short-circuit lines (mitigations firing, NOT fixes): {new['short_circuits']:,}"
          + (f"   (baseline {old['short_circuits']:,})" if old else ""))

    if new["drains"] or new["pubs"]:
        last_drain = new["drains"][-1][1] if new["drains"] else "-"
        if new["pubs"]:
            pub, put = new["pubs"][-1][1], new["pubs"][-1][2]
            state = "caught up" if pub == put else f"LAGGING by {int(put) - int(pub)}"
            print(f"CP truth  drains={len(new['drains'])} last_rptr={last_drain}"
                  f"   pub={pub} put={put} ({state})")
        else:
            print(f"CP truth  drains={len(new['drains'])} last_rptr={last_drain}"
                  "   pub=<never published>")
    elif new["ring_last"]:
        print(f"CP ring  first put={new['ring_first'][0]} rptrWB={new['ring_first'][1]}"
              f"   last put={new['ring_last'][0]} rptrWB={new['ring_last'][1]}")
        print("  no `CP: RING DRAIN`/`GUEST-PUB` line exists in this soak -- the"
              " waiter's rptrWB field is not evidence of a consumer (F-057(1)).")


    if new["lr_fault"]:
        total = sum(new["lr_fault"].values())
        print(f"\nfault-line guest lr ({total:,} events, {len(new['lr_fault'])} distinct)"
              f" -- top {args.top_lr}:")
        for lr, n in new["lr_fault"].most_common(args.top_lr):
            print(f"  {n:>7,}  lr={lr}")
        top_lr, top_n = new["lr_fault"].most_common(1)[0]
        if top_n > 50:
            print(f"  !! lr={top_lr} accounts for {top_n:,} fault events -- check whether a")
            print("     host mitigation is laundering one fault into many (F-040 pattern).")
    else:
        print("\nfault-line guest lr: none (no line matched the fault filter)")

    if new["lr"]:
        print("\nhottest guest lr over ALL lines (includes benign polling):")
        for lr, n in new["lr"].most_common(args.top_lr):
            print(f"  {n:>7,}  lr={lr}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
