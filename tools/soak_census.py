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

# The five crash/TLS-path mitigations of T38.3, one marker each. They all begin
# with "VEH", which the battery above already counts, so without these the census
# cannot tell a *declined* fault (honest) from a recovered one (a short-circuit).
# Verified against the format strings at src/boot_host.cpp:1043-1101 (2026-09-20).
# "parking thread" is NOT one of them -- no soak has ever emitted it; the real
# string is "parking boot worker thread".
VEH_PATHS = [
    "VEH-NEUTRAL", "parking boot worker", "advancing RIP", "Nuclear advance",
    "patch applied, continuing", "permanently disabled", "patched sub_82",
    "cleared MXCSR", "UILOAD context",
]

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
LEVEL = re.compile(r"\[(error|warning)\]")
# A line is only evidence of a fault if it reports one. Two exclusions matter:
# hot polling paths (the 30 ms KWFSO/GPU poller at lr=8242FC1C) also carry `lr=`
# and would dominate the census, and mitigation lines that merely *mention*
# fatality (`skip fatal`, `FATAL-SOFT`) are a host short-circuit absorbing a
# guest failure, not a fault report. The 703 baseline VEH events still match,
# because those lines carry `VEH`/`AV` in their own right.
FAULT_LINE = re.compile(
    r"C0000005|C0000003|C000001D|C000008E|80000003|access violation|\bAV\b"
    r"|\bVEH\b|parking|Fatal error",
    re.IGNORECASE,
)


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

    by_marker = {m: sum(1 for ln in lower if m.lower() in ln) for m in markers}

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

    if new["ring_last"]:
        print(f"CP ring  first put={new['ring_first'][0]} rptrWB={new['ring_first'][1]}"
              f"   last put={new['ring_last'][0]} rptrWB={new['ring_last'][1]}")
        if new["ring_last"][1].strip("0") == "":
            print("  rptrWB never advanced -> no CP consumer; guest is parked on the ring")

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
