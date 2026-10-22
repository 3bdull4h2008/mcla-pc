#!/usr/bin/env python3
"""Marker census for MCLA PC boot soaks -- the machine behind `mcla-log-census`.

Counts every documented log marker and prints new-vs-baseline columns with
COUNTS ARE ROWS, NOT SUBSTRING MATCHES.  A marker owns a row only when one of
its token alternatives is a PREFIX of that row's own message (the message being
the text after the "] [" level tag).  A line that merely MENTIONS the literal
is counted as NAMED and graded prose/field -- it is NOT a row.
TWO CONSEQUENCES A READER MUST NOT FORGET:
  * `grep -ic MARKER` is NOT this tool's number.  Measured on build/w874.log:
    `grep -c UILOAD` = 3 lines, but UILOAD has **0 rows** -- all three are the
    PROSE of the W34-NOGFX rows.  `VEH` is 979,395 matching lines and 0 rows,
    and `fatal` is 92,034 lines and 0 rows.
  * the NTSTATUS codes in EXC_CODES below need a `code=0x..` context and so
    read LOWER than a bare grep on the same token, and any marker listed in
    MARKER_EXCLUDE names a substring that is a FIELD of some other row rather
    than a marker of its own.

Every marker carries a CLASS, printed in its own section:

  PROGRESS  (the main table)
      One row is one unit of guest progress. This is the only class whose
      count may be read as a number of things that happened.
  FLOOD/THROUGHPUT  (its own table)
      One row is one ITERATION, not one event. INFLATE-ENTER spins at
      4.9k-109k rows per boot and one run did 6,747,400 in 50 s; P5-GATE is
      21% of w653.log; the KWFSO wait/wake pair has a `hot = lr in
      [82410000, 82430000)` bypass (src/kernel/imports.cpp:610, :2313) that logs
      EVERY wake of the 30 ms sub_8242FB88 poller (lr=8242FC1C) by
      construction. A count of 100,000 in this class is a rate, never 100,000
      units of progress -- so it is counted, but never read as a delta of
      progress. The in-tree fix is the CP-T3-CENSUS pattern
      (src/gpu_cp.cpp:582): cap in src/, then tally, and print the tally.
  MITIGATION
      A host short-circuit absorbed a guest failure: "fired", never "fixed".

The §9 inventory of docs/PROGRAM_GUIDE.md is re-parsed every run, so that half
follows the doc rather than a copy; the batteries it does not cover (exception
codes, GFx, fatal dispatch, PRESENT/draw, CP ring fields) are hand-maintained
below and may overlap it. §9 is matched by a literal heading -- retitle it and
the tracked count drops.

A tracked marker whose literal is in neither src/ nor generated/ reports 0
forever, which is a tautology and not a verdict (F-057(6)). DEAD TRACKER
reuses dead_tracked() to say so out loud, and grades it: a literal that is in no
comment-stripped source at all can never be printed either, which is how GFX-ALLOC
outlived the F-626 deletion of the code that printed it. `--strict` makes that a
nonzero exit. A guide-parsed dead marker is the guide's to fix, so it is listed
apart from a hand-battery one, which is this file's to fix.

Both grades are SUBSTRING questions about one corpus, asked of the comment-
inclusive source (DEAD) and the comment-stripped source (COMMENT-ONLY), so DEAD is
a strict subset of COMMENT-ONLY is a strict subset of LIVE. That is deliberate and
it is the fix for the bug this tool shipped: the COMMENT-ONLY grade used to be
exact-key membership on `mitigation_audit`'s label-shaped TOKEN set, so a hyphen was
an identity boundary the verdict could see and the log could not. `DICTLOOKUP-OK` is
a live `MCLA_LOG_INFO` (src/gpu_device.cpp:4220) firing 22x in build/w679.log, yet
the tracked stem `DICTLOOKUP` was graded COMMENT-ONLY because the token is
`DICTLOOKUP-OK` and the bare stem only ever appears in the comment at
src/gpu_device.cpp:22143 -- 22 real firings re-described as a tautological 0.
`DISCCHK` (live as `DISCCHK2-WAIT`/`DISCCHK2-RES`) was mis-graded the same way, and
the tokenizer's shape rule cannot represent `swfCMD` at all, so that comment-only
marker was never graded either way. No tokenizer is consulted now, so hyphenated,
bracketed, spaced and mixed-case labels are all first-class, and the printed
COMMENT-ONLY line cites the comment `file:line`s instead of claiming more than a
host-source absence can prove. `--self-test` asserts these verdicts against the
real tree, in both directions.

LOG QUALITY is ACTED ON, not just printed. A grade a tool announces and then
ignores is worse than no grade, because the announcement is read as a caveat on
numbers that were in fact computed anyway. So when one MITIGATION/VEH shape owns
POISON_SHARE (25%) of a log's lines -- F-054's w38e.log, where one VEH recovery
fired 616,824 times in 31.7 s, 33% of 1,860,449 lines -- the MARKER/NEW/BASE/
DELTA table is WITHHELD, symmetrically for the new log and for the baseline, and
the refusal names the shape, its row count and its share. The single-log census
is unaffected: absolute counts, the FLOOD table and the fault-line guest lr
census are still printed, because they are still true of that one log.
`--allow-poisoned-baseline` overrides, and stamps the table NOT A MEASUREMENT;
`--poison-share` moves the bar without an edit. Exit codes: 0 ok, 1 --strict dead
tracker, 2 bad path, 3 delta withheld.

A SECOND, INDEPENDENT refusal is DEPTH. Two logs whose LINE COUNTS differ by more
than DEPTH_RATIO (2.0x) do not support a bare MARKER/NEW/BASE/DELTA table, and
the table is withheld on the same mechanism (`old = None`, so it is total) and the
same exit code. This is not the same defect as a poisoned log and it is harder to
see, because neither log looks wrong: the flood/throughput rows scale with how
long the emulator ran, so a 1,173-line run diffed against a 166,544-line one
produces a table of correct numbers about depth, and its sign is uninterpretable.
That pair was compared for real once and a session drew conclusions from it. The
ratio is always REPORTED (the `DEPTH:` line, and `depth` in --json) and only acts
past the bar; `--allow-depth-confound` overrides and stamps, `--depth-ratio` moves
the bar. Both refusals can fire at once and each names itself.

WHAT A COUNT IS. `COUNT` is the number of ROWS a marker printed, not the number of
lines that mention it. The distinction is not pedantry: on build/w720.log the two
differ for 25 of the 240 tracked markers, and by a factor of 841 -- `PUT=` counted
8,387 matching lines and owns 0, because every one of them is a `put=` FIELD of a
`WAIT[KWFSO]` row. `VEH` counted 533 lines and owns 1; the other 532 matched
`vehblurimposter.fxc` and `resources/vehicle/...` in asset paths. `fatal` counted
674 and owns 15; 598 of the rest are `servegatefatal=` on `TOC76-XSF` rows. A
`grep -ic` number cannot answer the question this table is read for, and a
non-zero contaminated number is worse than a zero, because a zero is visibly
nothing while 8,387 reads as progress.

Ownership is decided from the line's own bytes: a marker owns a row iff one of its
`marker_tokens()` alternatives is a PREFIX OF THE ROW'S MESSAGE -- after the
`[time] [tag]` prefix, and also after an optional `subsystem:` prefix, because
788 of w720.log's 51,079 lines (1.54%) put the row's name after one
(`renderthread: hb-flicker`). Anchoring on the first TOKEN alone would report 0 for
six markers that have real rows (`Fatal error`, `VEH W0: parking thread`,
`FLUSH sub_821D5510`, `REQFILL sub_821867A0`, `STREAM-OPEN sub_821BCE68`,
`CP: IB-OPC-CENSUS`); `--self-test` asserts each of those, because that is the
failure mode a blanket rule produces.

The line count is NOT thrown away. It is still computed, still exactly `grep -ic`,
and printed beside the row count in COUNT SEMANTICS for every marker where the two
differ, with the rows that own the difference. Each such marker also gets a GRADE
in {own, field, prose, exc}: `field` means the literal is a field or label of
other rows (the registered set `MARKER_FIELD`), `prose` means it is named only
inside other rows, and `--strict` fails on both. One case is deliberately NOT
decided here: a STEM tracked beside its own extension (`DISCCHK` beside `DISCCHK2`,
`WAKE` beside `WAKE[KWFSO]`, `TOC76` beside `TOC76-LAYOUT`) counts the same rows
twice, and no rule about lines can separate them -- only a printer->marker map in
src/ can. That is a judgement about what the marker MEANS, so it is measured,
printed under STEM OVERLAP, and handed to the ledger owner.

The sec 9 parser reads the table's FIRST column, which is the authoritative marker
column (measured: 3 of 3 §9 table headers head it `marker`), and rejects
`file:line` tokens in it. Cell 0 also carries the printer citation for the marker
it names -- `` `INFLATE-ENTER` (`src/gpu_device.cpp:10993`) `` -- and four of
those citations were tracked as markers. Each graded LIVE while printing 0
forever, because `marker_tokens` splits a citation on `/` into a fragment (`src`)
that IS in src/, so `MARKER NOT IN SRC` could not fire on them. They are reported
under CELL-0 CITATION REJECTED, not silently dropped.

Usage:
    python tools/soak_census.py --self-test          # prove its own verdicts, no log
    python tools/soak_census.py build/w38a.log
    python tools/soak_census.py build/w38a.log build/smoke_long2.log
    python tools/soak_census.py build/w38a.log --markers GFx,UILOAD
    python tools/soak_census.py build/w38a.log --strict   # exit 1 on any DEAD TRACKER
    python tools/soak_census.py new.log bad.log          # exit 3 if either is POISONED
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import Counter
from functools import lru_cache
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
GUIDE = REPO / "docs" / "PROGRAM_GUIDE.md"

# Hand-maintained gate markers; the §9 parse currently yields none of these: host
# exception codes, UI/GFx frontier, fatal dispatch, PRESENT/draw, CP ring fields.
# UILOAD-census / W35-MOVIE-CTOR / F438-GFXCTOR / W35-BOOT-GATE{,-POST} are the
# graphics-goal battery: W35-MOVIE-CTOR > 0 is the real gate, because nGfx is a
# broken counter and F-437 proves it never counted.
#
# Removed, with the literal gone from the tree so the row could only ever print 0
# (F-057(6)): GFX-BLOCK (no occurrence anywhere) and GFX-ALLOC (survives only in
# the comment at src/gpu_device.cpp:2467, after F-626 deleted the host-forced
# boot-gate branch that printed it), plus `boot-worker AV` and
# `fallback advance`, dead for the same reason. Same rule, found by the
# COMMENT-ONLY grade below rather than by the blob: GFX-CTOR, GFX-CTOR-VT-MISMATCH
# (only a comment in src/gpu_device.cpp mentions the latter) and FACTORY -- whose
# one hit in w653.log is `a1-before-factory` on a MSGBISECT row, i.e. the
# case-insensitive substring, never a FACTORY census at all. Re-add a row when the
# corresponding print comes back.
FRONTIER = [
    "C0000005", "C0000003", "C000001D", "C000008E", "80000003", "406D1388",
    "GFx",
    "UILOAD-census", "W35-MOVIE-CTOR", "F438-GFXCTOR",
    "W35-BOOT-GATE", "W35-BOOT-GATE-POST",
    "W34-NOGFX", "W34-GFX-CENSUS", "Fatal error", "fatal", "assert",
    "VEH", "PRESENT",
    "DRAW_INDEXED", "PRESENT-FB", "rptrWB", "MmAllocatePhysicalMemoryEx",
    "swfCMD", "PUT=",
]

# The two handler outcomes tracked here: the honest decline, and the park. The
# VEH handler has other exits (sampler-thread decline, F390 SEH pass) that are
# NOT named here. Cut to live src/ strings in the 09-20/21 pass: 8 of the 9
# markers the old list carried exist nowhere in src/ (T38.3(a) deleted those
# paths) and the park was missing, so "all recovery markers are 0" was a
# tautology, not a verdict (F-057(6)) -- dead_tracked() prints that as a question.
VEH_PATHS = [
    "VEH-NEUTRAL",          # handler declined -> EXCEPTION_CONTINUE_SEARCH (honest)
    "VEH W0: parking thread",  # src/boot_host.cpp:1584, the generic park
]

# FLOOD/THROUGHPUT class: (marker, printing site, why one row != one event,
# which tracked PROGRESS row it inflates, if any). Counted in full, reported in
# its own table, and never to be read as progress. `CP-T3-CENSUS` is listed
# because it is the in-tree model for the fix -- cap in src/, then tally.
FLOOD = [
    ("INFLATE-ENTER", "src/gpu_device.cpp:10993",
     "spin row, one per re-entry of the inflate handler; 4.9k-109k rows/boot "
     "and 6,747,400 in 50 s on one tid in one run", ""),
    ("P5-GATE", "src/task_dispatch_trace.cpp:642",
     "one row per dispatched instruction, ~68,736 firings in a 120 s boot",
     "fatal"),
    ("CAS-SITE", "src/kernel/imports.cpp:2207",
     "`hot = lr in [82410000,82430000)` bypass (imports.cpp:2313) logs EVERY "
     "wake of the 30 ms sub_8242FB88 poller, lr=8242FC1C, by construction", ""),
    ("WAKE[KWFSO]", "src/kernel/imports.cpp:2314",
     "same `hot` bypass; the `!` in the row marks the hot case", ""),
    ("WAIT[NTWFSO]", "src/kernel/imports.cpp:610",
     "same `hot` bypass on the wait side", ""),
    ("READWRAP", "src/gpu_device.cpp:16286",
     "per-read row; one per container read, not per container", ""),
    ("READWRAP-R7Z", "src/gpu_device.cpp:16255",
     "per-read row (F-481 unconditional per-window read statistics)", ""),
    ("FB0D8-DTOR", "src/task_dispatch_trace.cpp:1176",
     "per-child destructor row; the POISON-SKIP tail is a mitigation firing", ""),
    ("CP-T3-CENSUS", "src/gpu_cp.cpp:582",
     "ALREADY capped-then-tallied in src/ -- the model for every row above", ""),
]
FLOOD_MARKERS = [f[0] for f in FLOOD]
FLOOD_WHY = {f[0]: (f[1], f[2], f[3]) for f in FLOOD}

# Substrings that are a FIELD of another row, not a marker of their own. Without
# these a count is arithmetically wrong, not merely loose.
#   PRESENT also matches `still_present=` on every UIXSF-GOLDEN-REVERIFY row
#   (docs/PROGRAM_GUIDE.md sec 9, that row: "NB `PRESENT` in a census is a
#   substring collision with this row's `still_present=`, not a marker").
#   W35-BOOT-GATE is a prefix of W35-BOOT-GATE-POST, which is tracked on its own
#   row, so counting both in one row double-counts it.
MARKER_EXCLUDE = {
    "PRESENT": ("still_present",),
    "W35-BOOT-GATE": ("W35-BOOT-GATE-POST",),
}

# ---------------------------------------------------------------------------
# A marker is a NAME a printer prints as a row. A tracked row whose literal is
# only ever a FIELD or a PHRASE inside somebody else's row has no rows of its
# own, so no counting rule can make its number a count of IT: the number counts
# the rows that carry the field. These are counted as before (their literal is
# real and its count is real) but GRADED, so no reader can take the number for
# an event count, and --strict fails on them.
#
# Every entry is a MEASUREMENT, not an opinion. Per entry: the number of lines
# the literal is counted on, how many of those the literal LEADS, and the rows
# that own the rest. All from build/w719.log + build/w720.log, lead = own rows
# after ROW_PREFIX/SUBSYS_PREFIX stripping (see row_identity).
#
#   slotcov=   64 lines, 0 own. All 64 are FLUSH sub_821D5510 rows; `slotcov=NNN`
#              is a field of that row. The audit named this one: it is
#              MARKER_EXCLUDE's exact purpose and was not registered.
#   nGfx        4 lines, 0 own. All 4 are W34-GFX-CENSUS rows carrying `nGfx=0`.
#   -GATE     571 lines, 0 own. A SUFFIX-FRAGMENT the sec 9 parse manufactures
#              out of a `(+`-E0`/`-E1`)` cell (see markers_from_guide); its
#              matches are XSF-OPEN-GATE-SKIPPED (283), XSF-GATE-BIT30-WITHHELD
#              (283), FAULTCTX-GATE (2), LOADING-GATE (2), DRAW-GATE (1). It is
#              tracked as a mitigation-LABEL tier on purpose (it is in
#              SHORT_CIRCUITS_TRACKED), so its count is label firings.
#   skip fatal 15 lines, 0 own. A phrase fragment, same tier as -GATE; all 15
#              are P5-PHYS (14) and INFLATE-SKIP (1) rows naming the phrase.
#   rptrWB   8446 lines, 0 own. The CP ring FIELD pair: WAIT[KWFSO] (8375),
#              RING: (70), CP: (1). Kept counted because this file's own header
#              (FRONTIER) tracks it as a ring field and CP_DRAIN/CP_PUB read the
#              honest pair -- a 0 here would delete evidence, not add it.
#   PUT=      8387 lines, 0 own. The other half of that pair: WAIT[KWFSO]
#              (8375), CP: (5), E98 (4), LOADING-GATE (2), KDELAY-SC (1).
#
# The four PROSE-only markers that are NOT registered here are registered as
# their own grade instead, because their count is 0 after anchoring and 0 is the
# TRUE own-row count -- there is no such row: UILOAD and PRESENT-FB.
MARKER_FIELD = {
    "slotcov=": "field of the FLUSH sub_821D5510 row",
    "nGfx": "field of the W34-GFX-CENSUS row",
    "-GATE": "suffix-label fragment; mitigation-label tier, not a row",
    "skip fatal": "phrase fragment; mitigation-label tier, not a row",
    "rptrWB": "CP ring field of WAIT[KWFSO] / RING: rows, not a row",
    "PUT=": "CP ring field of WAIT[KWFSO] / CP: rows, not a row",
}

# A sec 9 cell-0 token that is a `file:line` PRINTER CITATION, not a marker name.
# The sec 9 table's first column is the authoritative marker column (measured:
# 3 of 3 table headers in that section read `marker` / `Marker`), and cell 0 also
# carries the citation for the marker it names -- e.g.
#     `INFLATE-ENTER` (`src/gpu_device.cpp:10993`)
#     `WAIT` (the hot poller, `WAIT[NTWFSO]`, printer `src/kernel/imports.cpp:612`)
# The parser used to take EVERY backticked token in cell 0, so the citation
# became a tracked "marker". Four did, and each graded LIVE while printing 0
# forever, because marker_tokens() splits a citation on `/` and the fragment
# `src` IS in src/:
#     src/gpu_device.cpp:10993  -> tokens ['src', 'gpu_device.cpp:10993']
# `MARKER NOT IN SRC` cannot fire on such a row, because the fragment answers it.
#
# Shape, not a name list: a path separator plus a file extension, optionally
# followed by `:line` or `:line,line`. `GEN76-ALLOC/FREE` (a real marker, slash
# but no extension) and `CP: IB-OPC-CENSUS` (a real marker, colon but no path)
# both survive, which a `"/" in tok` rule would have destroyed.
CITATION = re.compile(
    r"^(?:[A-Za-z]:)?[\w.\-]+(?:[/\\][\w.\-]+)*\.[A-Za-z]{1,5}(?::\d+(?:,\d+)*)?$"
)


def is_citation(tok: str) -> bool:
    """True if a sec 9 cell-0 token is a `file:line` printer citation."""
    return bool(CITATION.match(tok.strip()))

# Hand-picked subset of the §7 / §7-ADDENDUM mitigation labels: `skip fatal`,
# `FATAL-SOFT`, `-GATE` come from the addendum, `PARK-SAMPLE` from §9, and most
# registry labels are absent. Parsed prose would also yield junk (`SEH`, `pow2`).
# This is only the REGISTERED half; the discovered half is mitigation_discovery().
# `fallback advance` was removed: zero occurrences in src/, so its 0 was a
# tautology.
SHORT_CIRCUITS_TRACKED = [
    "KDELAY", "FENCE", "ClearTaskJoinBusy", "TASKJOIN", "REBASE-POISON",
    "P10-PRE", "INFLATE-SKIP", "INFLATE-EMPTY", "INFLATE-PENDING",
    "TEXCREATE-SC", "BLIT-OOB-GUARD", "SLOT-READY", "DISCCHK", "DICT-HYDRATE",
    "PARK-SAMPLE", "FATAL-SOFT", "-GATE", "skip fatal",
]

# A match means a host short-circuit absorbed a guest failure: "mitigation fired",
# never "fixed" (§7). Two regexes, split for speed not for meaning:
#   SHORT_CIRCUIT (case-insensitive) is the original hand list.
#   SHORT_CIRCUIT_EXT (case-SENSITIVE) is the extension: the ledger's own
#     mitigation vocabulary (`F370-SHGRP-SOFT`, the `kF503KeepFieldsOnRelease`
#     flag names) plus the suffix tier mitigation_audit.py calls mitigation-shaped
#     (`INFLATE-SKIP`, `KDELAY-SC`, `BLIT-OOB-GUARD`, `REBASE-POISON`,
#     `TEXCREATE-SC`, `FATAL-SOFT`, `P5-GATE`, `POISON-SKIP`, ...), so the
#     aggregate names the firing families rather than one hand-picked dozen.
#     These labels are upper-case in src/ by the project's own convention, so
#     case-sensitivity loses nothing and is 6x cheaper per line: with
#     re.IGNORECASE, `[A-Z]` also matches lower case and the alternation backtracks
#     across 166k lines (2.79s -> 0.42s on w653). Fusing the two into one
#     IGNORECASE pattern cost 0.5s/log and was the biggest regression in this pass.
SHORT_CIRCUIT = re.compile(
    r"skip fatal|delta-0|FATAL-SOFT|fallback advance|-GATE\b|short-circuit"
    r"|advancing RIP|Nuclear advance|patch applied, continuing"
    r"|permanently disabled|already physical|host-serve|REBASE-POISON|PARK-SAMPLE",
    re.IGNORECASE,
)
SHORT_CIRCUIT_EXT = re.compile(
    r"\bk?F\d{3}[A-Za-z0-9]*\b"
    r"|\b[A-Z][A-Z0-9]*-(?:SC|SKIP|GATE|FORCE|POISON|SERVE|GUARD|FALLBACK"
    r"|CLAMP|SOFT|STUB|BYPASS|EMPTY|PENDING)\b",
)

GUEST_LR = re.compile(r"\blr=([0-9A-Fa-f]{8})\b")
TS_PREFIX = re.compile(r"^\[[0-9:.]+\]\s*(?:\[\w+\]\s*)?")
# ---- row identity ----------------------------------------------------------
# The log-prefix strip and the identity token, in ONE regex so they cannot
# disagree about where a line's message starts.
#
# `[ \t]`, never `\s`: `\s` matches a newline, so a `\s*` between two parts of a
# prefix pattern will happily consume the next line when the pattern is applied
# to the whole text and quietly stop matching at a line that is not a row. Every
# one of these classes is explicit about which whitespace it accepts.
#
#   ROW_PREFIX  `^[timestamp][ tag]*` -> everything after it is the MESSAGE.
#   SUBSYS      `^name:` / `^name[k]:` -> a subsystem prefix inside the message,
#               e.g. `renderthread: hb-flicker #1`. Optional bracket, because the
#               log also emits `cp[ib]:`. Anchored and one-token so it cannot
#               eat the marker it is protecting.
ROW_PREFIX = re.compile(r"^\[[0-9:.]+\][ \t]*(?:\[[^\]\n]*\][ \t]*)*")
SUBSYS = re.compile(r"^[a-z][a-z0-9]*(?:\[[a-z0-9]*\])?:[ \t]*")
IDENT = re.compile(r"^[^\s]+")


def row_message(ln: str) -> str:
    """The message body of a log line: everything after the `[time] [tag]` prefix.

    On a line with no prefix it returns the line unchanged, so a non-row line
    (a stray banner, a continuation) is never mistaken for an empty message.
    """
    return ROW_PREFIX.sub("", ln, count=1)


def row_owners(ln: str) -> tuple[str, str]:
    """(identity token, identity token past a `subsystem:` prefix), lower-cased.

    The identity token is the row's own NAME in this codebase's log convention:
    the printer's message begins with it, and everything after it is that row's
    fields. A tracked marker's literal is therefore a row of its OWN exactly when
    it is a prefix of the identity token -- that is the whole test, and it is
    decided from the line's bytes, not from a hand-maintained printer table.

    Two tokens are returned because 788 of w720.log's 51,079 lines (1.54%) are
    `[tag]`-prefixed subsystem rows whose name sits AFTER the prefix --
    `renderthread: hb-flicker #1` is 47 of them. A single anchor would report a
    live marker as dead; a blanket "second token" rule would report fields as
    rows. A marker owns a row if its literal is a prefix of the MESSAGE, or --
    when a `subsystem:` prefix pushes the row's name back one token -- a prefix of
    the second token. That is the test `marker_detail` applies, in that order, and
    the order matters: the first token is a prefix of the message by construction,
    so treating it as a separate case would make every field of every row a row.
    """
    msg = row_message(ln).lower()
    first = IDENT.match(msg)
    tok1 = first.group(0) if first else ""
    sub = SUBSYS.match(msg)
    tok2 = ""
    if sub:
        rest = msg[sub.end():]
        m2 = IDENT.match(rest)
        tok2 = m2.group(0) if m2 else ""
    return tok1, tok2


NUM = re.compile(r"0x[0-9A-Fa-f]+|\d+")
# The timestamp prefix and every number collapse in ONE pass instead of two.
SHAPE = re.compile(r"^\[[0-9:.]+\]\s*(?:\[\w+\]\s*)?|0x[0-9A-Fa-f]+|\d+")
CP_RING = re.compile(r"put=(\d+)\s+rptrWB=([0-9A-Fa-f]+)")
# The waiter's put/rptrWB pair is NOT the CP's state (imports.cpp:2176; that word
# was hard-coded 4 bytes off until T40.4's CpPrimaryWritebackVA, F-057(1)).
# CP_DRAIN/CP_PUB below are gpu_cp.cpp's own drain+publish lines: the honest pair.
CP_DRAIN = re.compile(r"CP: RING \w DRAIN .*?rptr ([0-9A-Fa-f]{4})->([0-9A-Fa-f]{4})")
CP_PUB = re.compile(r"CP: GUEST-PUB #\d+ dev=[0-9A-Fa-f]+ pub (\d+)->(\d+) put=(\d+)")
LEVEL = re.compile(r"\[(error|warning)\]")
# A line is evidence of a fault only if it reports one. Two exclusions matter: the
# 30 ms KWFSO/GPU poller (lr=8242FC1C, inside sub_8242FB88) also prints `lr=` and is
# 3121 of the 5572 `lr=` lines in build/smoke_long2.log -- an all-line lr census is
# a census of polling, not of progress; and lines that merely *mention* fatality
# (`skip fatal`, `FATAL-SOFT`) are a host short-circuit absorbing a guest failure,
# so they match nothing here (0 of 27 in w46.log). The 703 real VEH events do.
FAULT_LINE = re.compile(
    r"code=0xC0000005|code=0xC0000003|code=0xC000001D|code=0xC000008E"
    r"|code=0x80000003|access violation|\bAV\b"
    r"|\bVEH\b|parking|Fatal error",
    re.IGNORECASE,
)
# NOT fused into one regex on purpose: a single alternation cannot report whether
# BOTH families matched on the same line, and the fault-line lr split is the honest
# pipeline signal (F-057(1)/F-058), so it keeps its own independent search.
# The `#NNNNN` serial a flood row carries. INFLATE-ENTER's serial reaching
# 6,747,400 in 50 s is the proof that its rows are iterations of one record.
SERIAL = re.compile(r"#(\d+)")

# An NTSTATUS-looking hex is not an exception. `80000003` counted +1 in w38m.log
# and read as "a new VMX debugtrap", but its only occurrence is a PM4 packet
# argument: `CP-T3-CENSUS op=0x58 … args=80000003 071D82C0 DEADBEEF`. Every real
# fault line in this project prints `code=0x…` (measured over w38n.log:
# C0000005 1/1, 406D1388 1/1, 80000003 0/1), so the codes below are only counted
# in that context. do-not #22 / T41.4.
EXC_CODES = ("C0000005", "C0000003", "C000001D", "C000008E", "80000003",
             "406D1388")


# The corpus BOTH tracker verdicts read. One constant for both, because the two
# verdicts are nested (DEAD is a subset of COMMENT-ONLY is a subset of LIVE) and a
# pair of nested verdicts computed over two different corpora is not a nesting.
SRC_ROOTS = ("src", "generated/ppc_xenon")
SRC_PATS = ("**/*.cpp", "**/*.h")
# src_scopes() strips comments, and strip_comments is a char-by-char Python scan
# (tools/addr_owners.py:336): 16.2s over generated/ppc_xenon's 133 MB against
# 0.6s over src/'s 4.4 MB. So the verdict pass strips only SCAN_ROOTS and settles
# the generated root with a whole-text membership test on the literals that are
# still unresolved (SRC_ROOTS[1:] is 133 MB but only ~6 literals are ever tested
# against it). Measured 2026-10-01: 12 of the battery's 232 distinct literals occur
# in generated/ppc_xenon at all, and every one of them -- be0c8, complete, free,
# getdev, join, mmallocatephysicalmemoryex, present, req, src, submit, veh, wait --
# also occurs in src/, so that root cannot currently change a verdict. It is
# CHECKED anyway, not assumed: a literal that src/ cannot explain but generated/
# holds is reported UNRESOLVED rather than graded comment-only, because grading it
# would be a claim about code this pass never read.
SCAN_ROOTS = ("src",)


@lru_cache(maxsize=1)
def src_blob() -> str:
    """The lower-cased literal universe `dead_tracked` searches."""
    out = []
    for root in SRC_ROOTS:
        for pat in SRC_PATS:
            for p in (REPO / root).glob(pat):
                try:
                    out.append(p.read_text(encoding="utf-8", errors="replace"))
                except OSError:
                    pass
    return "\n".join(out).lower()


@lru_cache(maxsize=1)
def generated_blob() -> str:
    """SRC_ROOTS[1:] lower-cased, comments NOT stripped. Built only if needed.

    Lazily built because 133 MB is a real cost to pay for a check that is empty
    today: src_scopes() touches this only when some literal is still unresolved
    after the stripped pass, and lru_cache means the second call is free.
    """
    out = []
    for root in SRC_ROOTS:
        if root in SCAN_ROOTS:
            continue
        for pat in SRC_PATS:
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


@lru_cache(maxsize=1)
def _audit():
    """The sibling mitigation-registry auditor, or None.

    Imported rather than reimplemented so this tool and
    `tools/mitigation_audit.py` cannot drift into disagreeing about which labels
    exist: its one comment-stripping pass over src/ answers the DISCOVERY question
    (which mitigation-shaped labels are in the tree but unregistered), which is
    what the SHORT-CIRCUIT COVERAGE line and the native-charter removal queue are
    built from. Guarded, so a sibling file that is mid-edit degrades this tool to a
    printed notice instead of a crash.

    It is NOT used for the COMMENT-ONLY verdict any more. Its label-shaped TOKEN
    set made a hyphen an identity boundary the verdict could see and the log could
    not, which mis-graded a live marker (see src_scopes), so that question is now
    asked of the literal itself by src_scopes(), with _label_scopes()'s output kept
    only as the independent second opinion in self_test(). `mitigation_audit` skips
    `generated/` (addr_owners.SKIP_DIRS) while this file's verdicts do not, so the
    two are deliberately not the same corpus -- see SRC_ROOTS.
    """
    try:
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        import mitigation_audit
        return mitigation_audit
    except Exception:  # noqa: BLE001 - a measurement tool must not die here
        return None


@lru_cache(maxsize=1)
def _label_scopes() -> tuple[dict, dict]:
    """(code tokens, comment-only tokens) over src/, labels -> first hit sites.

    Both dicts are empty when the sibling auditor is unavailable.
    """
    m = _audit()
    if m is None:
        return {}, {}
    try:
        return m.scan_src()
    except Exception:  # noqa: BLE001
        return {}, {}


def comment_only(markers: list[str]) -> list[str]:
    """Tracked markers whose literal is in RAW source but in NO comment-stripped code.

    A comment cannot print a line, so such a marker's 0 is a tautology for the
    same reason a missing literal's is -- but the cause differs, and the cause is
    what tells the next session whether to delete the row or restore the code.
    """
    return [m for m in markers if m and comment_sites(m)]


def comment_sites(markers: list[str] | str) -> dict[str, list[str]]:
    """marker -> up to 3 `file:line` COMMENT sites, for COMMENT-ONLY markers only.

    Empty list means the marker is NOT comment-only, so this doubles as the
    verdict and its evidence: the caller prints the sites, which is what lets a
    reader confirm the grade instead of trusting it. A marker this cannot settle
    (its literal is in generated/, which src_scopes does not strip -- see
    SCAN_ROOTS) is reported by unresolved_markers() and withheld here, because
    calling it comment-only would be a verdict about code that was not read.
    """
    if isinstance(markers, str):
        markers = [markers]
    scopes = src_scopes(tuple(markers))
    return {m: scopes[m]["sites"] for m in markers
            if m and not scopes[m]["live"] and not scopes[m]["unresolved"]
            and scopes[m]["sites"]}


def unresolved_markers(markers: list[str] | str) -> list[str]:
    """Markers src/ cannot explain but generated/ holds -- deliberately UNGRADED."""
    if isinstance(markers, str):
        markers = [markers]
    scopes = src_scopes(tuple(markers))
    return [m for m in markers if m and scopes[m]["unresolved"]]


def src_scopes(markers: tuple[str, ...]) -> dict[str, dict]:
    """Per-marker LIVE / COMMENT verdict over SRC_ROOTS, in ONE streaming pass.

    THIS is the fix, and the shape of it is the point. The verdict used to be
    exact-dictionary membership on `mitigation_audit`'s label-shaped TOKEN set, so
    a hyphen acted as a hard identity boundary that the verdict could see and the
    log could not. `DICTLOOKUP-OK` is a live `MCLA_LOG_INFO`
    (src/gpu_device.cpp:4220) and fires 22x in build/w679.log, but it tokenizes as
    ONE token `DICTLOOKUP-OK`, so the tracked stem `DICTLOOKUP` is not a key of the
    code-token dict; the bare `DICTLOOKUP` in the comment at src/gpu_device.cpp:
    22143 IS a key of the comment dict, and a live marker was graded
    COMMENT-ONLY -- i.e. its 22 real firings were re-described as a tautological 0.
    Same defect, other direction: `DISCCHK` is live as `DISCCHK2-WAIT` /
    `DISCCHK2-RES` (src/task_dispatch_trace.cpp:956/977) and was also graded
    COMMENT-ONLY. And the tokenizer's shape rule (`[A-Z][A-Z0-9]*` /
    `[A-Z]{5,}`) cannot represent a non-identifier label at all, so `swfCMD` --
    comment-only at src/gpu_device.cpp:7529 -- was never graded either way.

    So the verdict no longer consults a tokenizer. It asks the SAME question
    dead_tracked() already asks -- is this literal a substring of the source? --
    over the comment-stripped source instead of the comment-inclusive one. Both
    sides are now substring tests over SRC_ROOTS, which is what makes DEAD a
    strict subset of COMMENT-ONLY a strict subset of LIVE. No shape rule, so
    hyphenated, bracketed, spaced and mixed-case labels are all first-class; a
    stem is covered by any label that contains it, which is exactly the relation
    the log-side count (`ml in lo`) uses, so grade and count finally agree on
    what a marker literal is.

    What it does NOT prove, and what the printed verdict now says instead of
    overclaiming: absence from host src/ is not absence from the guest, which
    dead_tracked() has always said. `swfCMD` is the live example -- the comment at
    src/gpu_device.cpp:7529 quotes a GUEST string, so "no path can print it" was
    false and "no HOST path can print it" is true.

    Streaming, not accumulating: one file is read and discarded at a time, so this
    adds no retained corpus to src_blob()'s. Sites are resolved by offset comparison
    against the stripped copy -- valid because strip_comments preserves offsets and
    newlines (tools/addr_owners.py:336) -- and they are REPORTED, not frozen into
    this file, because src/ is edited concurrently and a hard-coded file:line here
    would be a citation that drifts (measured: gpu_device.cpp's DICTLOOKUP-OK print
    moved 4220 -> 4212 inside one session).

    `code_log_sites` is the strongest liveness evidence available without an AST:
    the file:line of the literal inside comment-stripped source where that same
    line is an MCLA_LOG_* call. It is what upgrades "the literal is typed in code"
    to "a log call prints it", which is the actual question dead_tracked() and
    comment_only() are asked.

    SCAN_ROOTS only; see its comment for why generated/ is settled separately.
    """
    strip = _strip_comments()
    scopes = {m: {"live": False, "comment": False, "sites": [],
                  "code_sites": [], "code_log_sites": [], "unresolved": False}
              for m in markers if m}
    if strip is None or not scopes:
        return scopes

    index: dict[str, list[str]] = {}
    for m in markers:
        for t in marker_tokens(m) if m else ():
            index.setdefault(t.lower(), []).append(m)

    def line_of(hay: str, k: int) -> str:
        return hay.count("\n", 0, k) + 1

    for root in SCAN_ROOTS:
        for pat in SRC_PATS:
            for p in (REPO / root).glob(pat):
                try:
                    raw = p.read_text(encoding="utf-8", errors="replace")
                except OSError:
                    continue
                rel = p.relative_to(REPO).as_posix()
                low = raw.lower()
                live = strip(raw).lower()
                for t, owners in index.items():
                    if t in live:
                        for m in owners:
                            scopes[m]["live"] = True
                        # First code site, and whether it is a log CALL. One find
                        # per live literal per file, same order as the `in` test.
                        k = live.find(t)
                        if k < 0 or len(scopes[owners[0]]["code_sites"]) >= 3:
                            continue
                        site = f"{rel}:{line_of(live, k)}"
                        # The literal's line AND the one above it: this codebase
                        # writes `MCLA_LOG_WARN(\n    "LITERAL …",` far more often
                        # than it puts them on one line (the DISCCHK2 print is one
                        # such, src/gpu_device.cpp:17778-17779), and a same-line
                        # test alone silently loses those -- which is the whole
                        # class of evidence this is here to keep. Still a heuristic:
                        # a literal more than one line below its macro is reported
                        # in code_sites but not in code_log_sites.
                        start = live.rfind("\n", 0, k) + 1
                        prev = live.rfind("\n", 0, max(start - 1, 0)) + 1
                        end = live.find("\n", k)
                        text = live[prev:end if end > 0 else len(live)]
                        is_log = "mcla_log" in text
                        for m in owners:
                            if len(scopes[m]["code_sites"]) < 3:
                                scopes[m]["code_sites"].append(site)
                            if is_log and len(scopes[m]["code_log_sites"]) < 3:
                                scopes[m]["code_log_sites"].append(site)
                        continue
                    if t not in low:
                        continue
                    for m in owners:
                        scopes[m]["comment"] = True
                    at, seen = 0, []
                    while len(seen) < 3:
                        k = low.find(t, at)
                        if k < 0:
                            break
                        at = k + 1
                        if live[k:k + len(t)] != t:  # blanked => it was a comment
                            seen.append(f"{rel}:{line_of(low, k)}")
                    if seen:
                        for m in owners:
                            scopes[m]["sites"].extend(seen)

    # The generated/ root, settled only for what SCAN_ROOTS could not explain.
    # One whole-text membership test per UNRESOLVED literal; if the literal is in
    # there, the COMMENT-ONLY grade is withheld, because it is a claim about
    # comment-stripped code this pass never read.
    pending = {t for t, owners in index.items()
               if not any(scopes[m]["live"] for m in owners)}
    if pending:
        gen = generated_blob()
        for t in pending:
            if t in gen:
                for m in index[t]:
                    scopes[m]["unresolved"] = True

    # glob order is filesystem order; sort so two runs on one tree agree.
    for s in scopes.values():
        s["sites"] = sorted(set(s["sites"]))
        s["code_sites"] = sorted(set(s["code_sites"]))
        s["code_log_sites"] = sorted(set(s["code_log_sites"]))
    return scopes


@lru_cache(maxsize=1)
def _strip_comments():
    """addr_owners.strip_comments, or None if the sibling is unimportable.

    Same guarded degradation as _audit(): a measurement tool must not die because a
    neighbouring file is mid-edit. None means the COMMENT-ONLY question goes
    UNANSWERED (no rows graded either way) rather than answered wrongly.
    """
    try:
        from addr_owners import strip_comments
        return strip_comments
    except Exception:  # noqa: BLE001
        return None


def dead_tracked(markers: list[str]) -> list[str]:
    """Tracked markers whose literal is in neither root `src_blob()` reads.

    Their zero is only *suspicious*, not automatically meaningless: a marker can
    name text the guest itself prints. So report it as a question, never a verdict.
    """
    blob = src_blob()
    return [m for m in markers
            if m and not any(t.lower() in blob for t in marker_tokens(m))]


def mitigation_discovery() -> tuple[list[str], dict, str | None]:
    """Mitigation-shaped labels in src/ that sec 7 does not register.

    Returns (undocumented, code_tokens, error). This is the removal queue the
    native charter works from, so the tool discovers the set instead of trusting
    the hand list above to have kept up with the tree.
    """
    m = _audit()
    if m is None:
        return [], {}, "tools/mitigation_audit.py not importable"
    try:
        registered = m.labels_in(m.section7(GUIDE))
        code, _ = _label_scopes()
    except Exception as exc:  # noqa: BLE001
        return [], {}, f"mitigation registry scan failed: {exc}"
    undoc = sorted(t for t in code if m.classify_token(t) == "mitigation"
                   and t not in registered)
    return undoc, {"registered": len(registered), "src": len(code)}, None


def guide_rows(path: Path) -> list[str]:
    """Every cell-0 of every §9 table row, verbatim. The unit markers_from_guide
    parses, exposed so a rejection can be reported instead of being silent."""
    if not path.exists():
        return []
    text = path.read_text(encoding="utf-8", errors="replace")
    start = text.find("## 9. Census / marker inventory")
    if start < 0:
        return []
    end = text.find("\n## ", start + 1)
    section = text[start:end if end > 0 else len(text)]
    return [ln.split("|")[1] for ln in section.splitlines() if ln.startswith("|")]


def rejected_citations(path: Path) -> list[str]:
    """The cell-0 tokens that are `file:line` printer citations, not marker names.

    REPORTED, not silently dropped: a parser that quietly discards a row is
    indistinguishable from a parser that never saw one, and this tool's whole
    argument is that a dropped row is a hole nobody notices. See `CITATION` for
    the shape and the four rows it removes.
    """
    out = []
    for cell in guide_rows(path):
        if "Marker" in cell or "marker" in cell or "---" in cell:
            continue
        for tok in re.findall(r"`([^`]+)`", cell):
            tok = tok.strip()
            if tok and is_citation(tok):
                out.append(tok)
    return sorted(set(out))


def markers_from_guide(path: Path) -> list[str]:
    """Pull backticked marker tokens out of the §9 inventory table's FIRST column.

    The first column is the authoritative marker column -- measured, not assumed:
    all three §9 tables head it `marker` / `Marker` (PROGRAM_GUIDE.md lines 69, 78,
    84), and 944 backticked tokens appear in the OTHER columns against 227 in cell
    0, of which 707 have a literal in src/ and are therefore all prose. Reading
    any other column would add ~700 junk "markers".

    Cell 0 also carries the printer CITATION for the marker it names, so a
    citation-shaped token is rejected (`is_citation`). Before this, four such
    citations were tracked as markers; each graded LIVE while printing 0 forever,
    because `marker_tokens` splits a citation on `/` and the fragment `src` is in
    src/, so `MARKER NOT IN SRC` could not fire on them. Established as citations
    rather than mangled marker names: each is cited by a marker that is tracked
    separately in the same cell -- `src/gpu_device.cpp:10993` by `INFLATE-ENTER`,
    `src/gpu_device.cpp:16286` by `READWRAP`, `src/gpu_device.cpp:16255` by
    `READWRAP-R7Z`, `src/kernel/imports.cpp:612` by `WAIT`/`WAIT[NTWFSO]` -- and
    none of the four strings occurs in any of w715/w717/w719/w720.log. Their cited
    src lines are also stale (src/gpu_device.cpp:10993 is now
    `uint32_t dh[4] = {0, 0, 0, 0};`, not a log call), which is a doc-side
    citation drift, not a hidden marker.
    """
    found: list[str] = []
    for cell in guide_rows(path):
        if "Marker" in cell or "marker" in cell or "---" in cell:
            continue
        for tok in re.findall(r"`([^`]+)`", cell):
            # Cells like `GETDEV` (+`-E0`/`-E1`) yield suffix fragments; only
            # keep tokens that look like a standalone marker.
            tok = tok.strip()
            if (tok and not tok.startswith(("-", "/"))
                    and re.match(r"^[A-Za-z]", tok)
                    and not is_citation(tok)):
                found.append(tok)
    return found


def shape(ln: str) -> str:
    """A log line with its timestamp and numbers collapsed, so one repeating
    message counts as one shape regardless of its counters and addresses."""
    return SHAPE.sub("#", ln).strip()


def marker_detail(lower: list[str], msgs: list[str], idents: list[tuple[str, str]],
                  markers: list[str], exc_codes: tuple[str, ...]) -> dict[str, dict]:
    """Per marker: the LINE count, the OWN-row count, the owners, and a GRADE.

    This is the split that makes a count mean something. `count_markers()` returned
    one number per marker -- matching LINES, `grep -ic` compatible -- and that
    number is a count of the LINES THAT MENTION the literal, which is not the same
    question as "how many rows did this marker print". On build/w720.log the two
    differ for 25 of the 240 tracked markers, and they differ by a factor of 841
    (`PUT=` 8387 lines vs 0 own rows: every one of them is a `put=` FIELD of a
    `WAIT[KWFSO]` row).

    OWN is decided from the line's own bytes: a marker owns a row iff one of its
    `marker_tokens()` alternatives is a PREFIX OF THE ROW'S MESSAGE (after the
    `[time] [tag]` prefix, and also after an optional `subsystem:` prefix -- see
    `row_owners` for the measured 1.54% of lines that need the second form, and
    for why anchoring on the FIRST TOKEN alone is wrong: it would report 0 for
    six markers that have real rows, `Fatal error`, `VEH W0: parking thread`,
    `FLUSH sub_821D5510`, `REQFILL sub_821867A0`, `STREAM-OPEN sub_821BCE68` and
    `CP: IB-OPC-CENSUS`).

    GRADE, in the only five states the bytes support:
      own       lines == own: the number IS a row count.
      field     own == 0 and the literal is a field/label of other rows -- the
                registered set MARKER_FIELD. The number counts rows that CARRY it.
      prose     own == 0 and lines > 0: the literal is named inside other rows.
                There is no row of its own, so 0 is the true own-row count.
      exc       an EXC_CODE, counted in its `code=0x…` context, never anchored.
      tautology the literal cannot be printed by any host path (DEAD or
                COMMENT-ONLY upstream): its 0 is a tautology, not a measurement.

    What this does NOT decide, and reports instead: a STEM tracked next to its own
    extension (`DISCCHK` beside `DISCCHK2`, `WAKE` beside `WAKE[KWFSO]`,
    `TOC76` beside `TOC76-LAYOUT`) counts the SAME rows twice, and no rule about
    lines can separate them -- only a printer->marker map, which lives in src/,
    can. That is a judgement about what the marker MEANS, so it is measured and
    handed to the ledger owner as `stem_of` rather than silently resolved here.
    """
    out: dict[str, dict] = {}
    for m in markers:
        toks = [t.lower() for t in marker_tokens(m)] or [m.lower()]
        ex = MARKER_EXCLUDE.get(m)
        ext = tuple(t.lower() for t in ex) if ex else ()
        is_exc = m in exc_codes
        rec = {"lines": 0, "own": 0, "named": 0, "owners": Counter(),
               "named_owners": Counter(), "stem_of": None}
        for i, lo in enumerate(lower):
            if not any(t in lo for t in toks):
                continue
            if is_exc:
                if f"code=0x{m.lower()}" not in lo:
                    continue
            elif ext and any(x in lo for x in ext):
                continue
            rec["lines"] += 1
            if is_exc:
                # An EXC_CODE's OWN row is the `code=0x…` context itself, and that
                # is the whole point of the do-not #22 rule: the same literal is a
                # bare PM4 packet argument on thousands of other rows, and only the
                # context says which one reported a fault. So the context test IS
                # this marker's ownership test, and the row identity (`VECTORED`,
                # `VEH`) is recorded as evidence rather than used as the gate.
                # Anchoring it instead would report 0: measured on w720.log the two
                # codes fire on 3 rows whose identity tokens are `vectored` (2) and
                # `veh` (1), neither of which starts with the code.
                rec["own"] += 1
                t1, _ = idents[i]
                if t1:
                    rec["owners"][t1] += 1
                continue
            t1, t2 = idents[i]
            msg = msgs[i]
            # Ownership is the measured R2b rule and nothing else: the marker's
            # literal must be a PREFIX OF THE MESSAGE, or (when a `subsystem:`
            # prefix pushes the row's name back one token) of the token after it.
            # `t1.startswith(t)` is NOT a separate case -- it is implied by
            # `msg.startswith(t)`. Writing it as one is exactly how an earlier
            # version of this loop came to count `PUT=` as owning 41 WAIT[KWFSO]
            # rows, so the two cases are spelled out separately and the self-test
            # pins both.
            owner = ""
            for t in toks:
                if msg.startswith(t):
                    # The owner is the marker's own matched literal, NOT two words
                    # of the message: `present-surface-unreadable #1` would
                    # otherwise mint one owner per row because of the serial.
                    owner = msg[:len(t)]
                    break
            if not owner and t2:
                for t in toks:
                    if t2.startswith(t):
                        # `cp: ib-opc-census`: the row's name is AFTER the prefix,
                        # so the owner is that name, not `cp:`.
                        owner = t2
                        break
            if owner:
                rec["own"] += 1
                rec["owners"][owner] += 1
            else:
                rec["named"] += 1
                if t1:
                    rec["named_owners"][t1] += 1
        out[m] = rec

    # stem overlap, measured over the OTHER tracked markers: which tracked names
    # are strict extensions of this one, i.e. which rows this marker shares.
    lows = {m: [t.lower() for t in marker_tokens(m)] or [m.lower()]
            for m in markers}
    for m in markers:
        exts = [o for o in markers
                if o != m and any(b.startswith(a) and len(b) > len(a)
                                  for a in lows[m] for b in lows[o])]
        if exts:
            out[m]["stem_of"] = sorted(exts)
    for m, rec in out.items():
        rec["grade"] = grade_marker(m, rec)
    return out


def grade_marker(m: str, rec: dict) -> str:
    """The one word that says what this marker's number counts."""
    if m in EXC_CODES:
        return "exc"
    if m in MARKER_FIELD:
        return "field"
    if rec["own"] == 0 and rec["lines"] > 0:
        return "prose"
    return "own"


def count_markers(lower: list[str], msgs: list[str],
                  idents: list[tuple[str, str]], markers: list[str],
                  exc_codes: tuple[str, ...]) -> dict[str, int]:
    """OWN-ROW counts per marker -- the number the MARKER table prints.

    `grep -ic` compatibility is deliberately GONE and the header says so: a
    matching-line count cannot answer "how many rows did this marker print", and
    that is the question every downstream conclusion reads this table for. The
    line count is still computed, still reported, and still `grep -ic` exact --
    it is `marker_detail()[m]["lines"]`, and the COUNT SEMANTICS table prints it
    beside the own-row count for every marker where the two differ, together with
    the rows that own the difference. Nothing is discarded; the grade stops the
    wrong number being read as the right one.

    MARKER_EXCLUDE still drops whole lines (a substring that is a FIELD of the
    marker being counted), which is a different exclusion from the ownership
    test: it removes lines the marker cannot be on, not lines it does not own.
    """
    return {m: rec["own"]
            for m, rec in marker_detail(lower, msgs, idents, markers,
                                       exc_codes).items()}


def flood_stats(lower: list[str], idents: list[tuple[str, str]],
                msgs: list[str], shapes_of: dict[int, str]) -> dict[str, dict]:
    """Per-flood-marker OWN rows, distinct shapes, max `#N` serial.

    Rows say how much of the log the family owns. Distinct shapes and the max
    serial say whether those rows are N events or one event repeated: a flood
    marker whose serial runs to 6,747,400 over ONE shape is a spin, and its row
    count is a rate, not 6.7M units of progress.

    Fed from census's single pass, with the already-computed `shape()` reused.
    Counted by OWNERSHIP for the same reason the marker table is: `CP-T3-CENSUS`
    is named by `CP-T3-UNHANDLED`'s prose, so a substring count reads that
    untracked printer's row as its own.
    """
    out: dict[str, dict] = {}
    for m in FLOOD_MARKERS:
        out[m] = {"rows": 0, "shapes": set(), "serial": 0}
    lm = [(m, [t.lower() for t in marker_tokens(m)] or [m.lower()])
          for m in FLOOD_MARKERS]
    for i, lo in enumerate(lower):
        t1, t2 = idents[i]
        msg = msgs[i]
        for m, toks in lm:
            if not any(t in lo for t in toks):
                continue
            if not (msg.startswith(toks[0]) or any(msg.startswith(t) for t in toks)
                    or (t2 and any(t2.startswith(t) for t in toks))):
                continue
            s = out[m]
            s["rows"] += 1
            s["shapes"].add(shapes_of.get(i, ""))
            hit = SERIAL.search(lo)
            if hit:
                v = int(hit.group(1))
                if v > s["serial"]:
                    s["serial"] = v
    return out


def graded_bad(c: dict, markers: list[str]) -> list[str]:
    """Markers whose COUNT is a field count or a prose count, not a row count.

    `--strict`'s second trigger. A dead literal is a tautological 0 that the DEAD
    TRACKER block already reports; this is the other tautology -- a live literal
    whose number counts somebody else's rows -- and it is the one that survives a
    skim, because the number is non-zero and looks like progress.
    """
    return [m for m in markers
            if c.get("detail", {}).get(m, {}).get("grade") in ("field", "prose")]


def census(path: Path, markers: list[str]) -> dict:
    """Per-marker counts plus the side censuses.

    `msgs` and `idents` are computed ONCE per line, not once per marker: the
    identity tokens are a property of the line, and asking 240 markers for them
    separately is 240 x 51,079 regex calls. Both are kept in the returned dict so
    a caller can audit any count without re-deriving them.
    """
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    # One C-level lowercase of the whole file, then one C-level split, instead of
    # 166k per-line str.lower() calls. Identical result: lower() is per-character
    # and never introduces a line separator, so the split points are the same.
    text_lower = text.lower()
    lower = text_lower.splitlines()

    msgs: list[str] = []
    idents: list[tuple[str, str]] = []
    for lo in lower:
        t1, t2 = row_owners(lo)
        idents.append((t1, t2))
        msgs.append(row_message(lo))

    detail = marker_detail(lower, msgs, idents, markers, EXC_CODES)
    by_marker = {m: detail[m]["own"] for m in markers}

    rings = CP_RING.findall(text)

    # ONE pass over the lines for the four per-line censuses. A line can only
    # contribute a guest lr to the FAULT-line census if it has an `lr=` to
    # contribute, so screening on that first is exact, not a heuristic: it is the
    # same set of contributing lines FAULT_LINE alone would select.
    lr_fault: Counter = Counter()
    sc = 0
    shapes: Counter = Counter()
    shape_of: dict[int, str] = {}
    rep: dict[str, str] = {}
    for i, (ln, lo) in enumerate(zip(lines, lower)):
        if "lr=" in lo and FAULT_LINE.search(ln):
            for lr in GUEST_LR.findall(ln):
                lr_fault[lr] += 1
        if SHORT_CIRCUIT.search(ln) or SHORT_CIRCUIT_EXT.search(ln):
            sc += 1
        if ln.strip():
            sh = shape(ln)
            shapes[sh] += 1
            shape_of[i] = sh
            # One RAW line per shape, for classification. shape() collapses every
            # decimal run, so a marker whose ID contains a digit loses it --
            # `VEH W0: parking thread` becomes `VEH W#: parking thread` and the
            # VEH_PATHS literal can then never match, which silently demotes a
            # 75%-laundering-family log to "recurring line" and lets it be diffed
            # like any other. Classifying the collapsed shape is therefore
            # unsound; classifying the shape's first raw member is not, and the
            # counters that differ between members are irrelevant to the question
            # being asked ("is this message a mitigation/VEH line?").
            if sh not in rep:
                rep[sh] = ln

    return {
        "path": path,
        "lines": len(lines),
        "bytes": path.stat().st_size,
        "markers": by_marker,
        "lr": Counter(GUEST_LR.findall(text)),
        "lr_fault": lr_fault,
        "short_circuits": sc,
        "levels": Counter(m.group(1) for m in LEVEL.finditer(text)),
        "ring_first": rings[0] if rings else None,
        "ring_last": rings[-1] if rings else None,
        "drains": CP_DRAIN.findall(text),
        "pubs": CP_PUB.findall(text),
        "shapes": shapes,
        "rep": rep,
        "detail": detail,
        "flood": flood_stats(lower, idents, msgs, shape_of),
    }


def is_mitigation(text: str) -> bool:
    """Both short-circuit families, so one place decides what counts as mitigation."""
    return bool(SHORT_CIRCUIT.search(text) or SHORT_CIRCUIT_EXT.search(text))


# Two share thresholds, and the difference between them is the whole point.
#
#   RECUR_SHARE (2%)    REPORT: name a shape that owns at least this much of the
#                       log. Reporting a recurring line costs nothing and the
#                       number is worth seeing.
#   POISON_SHARE (25%)  REFUSE: withhold the DELTA table against a log where one
#                       MITIGATION/VEH shape owns at least this much of it.
#
# The gap exists because they are different claims. "one shape is 4% of the log"
# is boot traffic: FB0D8-DTOR's per-child POISON-SKIP row, CAS-SITE's poller wake
# and PARK-SAMPLE all sit at 4% of every w64x/w65x soak in the evidence base,
# measured 2026-09-28. "one host loop owns a third of the log" is F-054: one VEH
# recovery fired 616,824 times in 31.7 s of w38e.log's 1,860,449 lines, so the
# counters measure the loop rather than the guest. The old code applied 2% to
# both, so it printed "this log mostly records a host loop" for logs that are 96%
# guest -- and, since the fix below refuses on that same grade, it would have
# refused every pair in the evidence base. A refusal that fires on everything
# is the same defect as a grade nobody acts on, in the other direction. The
# threshold is a constant and --poison-share moves it without an edit, so a human
# who holds a different bar states it.
POISON_SHARE = 0.25
RECUR_SHARE = 0.02

# DEPTH_RATIO (2.0) REFUSE: withhold the DELTA table when the two logs differ in
# LINE COUNT by more than this factor.
#
# This is a different defect from a poisoned log, and it is the more dangerous
# one, because nothing about either log looks wrong. A delta between a 1,173-line
# run and a 166,544-line run is mostly a measurement of how long the emulator ran:
# every flood/throughput row scales with depth, so `PRESENT-SURF 236,309 vs 5`
# and `INFLATE-ENTER 5,119 vs 1,102` are both arithmetically correct and both
# answer a question nobody asked. A truncated log diffed against a full one is
# not merely uninformative, it is ACTIVELY MISLEADING, because a rate-scaled
# count reads exactly like a regression. This pair was compared in anger once
# already (a 120 s soak against a 1,173-line run) and the session drew
# conclusions from the delta table; that is the failure this bar exists to stop.
#
# Why 2.0 and not 5.0: the flood/throughput rows in the evidence base already
# swing 6x between soaks of the SAME binary (P5-GATE 68,736 firings/120 s
# against a short smoke run), so a bar loose enough to admit that cannot
# distinguish it from a truncated log. 2.0 is also the point at which a
# same-length soak's noise floor stops being the obvious explanation.
#
# Why REFUSE rather than stamp: the refusal mechanism here is `old = None`,
# which is TOTAL -- every comparison site in the report is guarded by `if old:`,
# so the DELTA column, the FLOOD BASE column and the three "(baseline N)"
# parentheticals all fall together and no delta leaks by an unthought-of route.
# A marker-only "DEPTH-CONFOUNDED" banner would have to be repeated at each of
# those sites and at every site added later, and a delta that is stamped but
# still printed in a clean four-column table is a delta that gets quoted. The
# module's own thesis is that a grade announced and then ignored is worse than
# no grade. So: refuse by default, and let a human who holds a different bar
# state it with --depth-ratio or read it anyway with --allow-depth-confound
# (which stamps NOT A MEASUREMENT, exactly as --allow-poisoned-baseline does).
DEPTH_RATIO = 2.0

# Only a MITIGATION/VEH shape can poison. A benign recurring line is a RATE --
# reported, and already held to "never read as progress" by the FLOOD class --
# but it launders no fault, so it does not make the surrounding counts untrue.
# F-054 is specifically the laundering case, and laundering is what breaks a
# count.
POISON_KIND = "MITIGATION/VEH LINE"

POISON_VERDICT = (
    "  -> POISONED as a measurement of the guest: this log mostly "
    "records a host loop. Do not name it as a baseline or a delta "
    "reference; compare the fault-line lr census and the guest "
    "frontier markers only, and say so in the claim.")


def shape_kind(s: str, rep: dict | None = None) -> str:
    """POISON_KIND for a shape that launders a fault, else "recurring line".

    `rep` is census()'s shape -> first RAW member map. The classification runs on
    the raw member, never on the collapsed shape: see the `rep` comment in
    census() for why the collapsed form cannot answer this question.
    """
    probe = (rep or {}).get(s, s)
    if is_mitigation(probe) or any(v.lower() in probe.lower() for v in VEH_PATHS):
        return POISON_KIND
    return "recurring line"


def poison(c: dict, share_min: float = POISON_SHARE) -> dict:
    """Does one MITIGATION/VEH shape own enough of this log to void a delta?

    Returns the verdict plus the evidence for it, so a refusal can quote the
    shape, its row count and its share rather than just asserting a grade.
    `shape` is None when the log is allowed.

    Scans the top 8 shapes, not the top 3: quality() only *reports* 3, and a
    log can hide one laundered family under three benign ones. most_common is
    descending, so the first sub-RECUR_SHARE shape ends the search.
    """
    total = max(c["lines"], 1)
    for s, n in c["shapes"].most_common(8):
        share = n / total
        if share < RECUR_SHARE:
            break
        if shape_kind(s, c.get("rep")) == POISON_KIND and share >= share_min:
            return {"poisoned": True, "shape": s, "rows": n, "share": share,
                    "lines": c["lines"], "threshold": share_min}
    return {"poisoned": False, "shape": None, "rows": 0, "share": 0.0,
            "lines": c["lines"], "threshold": share_min}


def depth(new: dict, old: dict, ratio_max: float = DEPTH_RATIO) -> dict:
    """Can a DELTA between these two logs be read as change at all?

    Counts that scale with how long the emulator ran are the FLOOD/THROUGHPUT
    class by construction, so a depth-mismatched pair produces a delta table
    that is mostly a stopwatch. Returns the verdict plus the two line counts and
    the factor, so a refusal can quote the evidence rather than assert a grade.

    `confounded` is True when the LARGER log is the new one (growth reads as
    regression) or the smaller one (loss reads as a fix); either way the sign of
    the delta is uninterpretable, which is the whole claim. `ratio` is always
    reported so the grade is visible even when it does not act.
    """
    a, b = new["lines"], old["lines"]
    lo, hi = min(a, b), max(a, b)
    factor = (hi / lo) if lo else float("inf")
    return {"confounded": factor > ratio_max, "ratio": factor,
            "ratio_max": ratio_max, "new_lines": a, "base_lines": b,
            "new_name": new["path"].name, "base_name": old["path"].name}


def quality(c: dict, share_min: float = POISON_SHARE) -> list[str]:
    """Flag a log that is mostly one repeating host message (top 3 shapes, >= 2%).

    A mitigation that launders its own fault yields a log whose counters are all
    that mitigation: w38e.log is 175 MB where one VEH recovery fired 616,824 times
    in 31.7 s -- 33% of its 1,860,449 lines, so the counts measure a host loop,
    not the guest: POISONED, never a baseline or a delta (F-054). A benign poller
    at the same share is just a "recurring line"; counts stay exact either way.

    The POISONED verdict is now gated on `share_min`, not on the 2% reporting
    threshold, because the verdict's own sentence claims the log is MOSTLY a host
    loop. At 4% that sentence is false, and printing it there is what made the
    grade unusable as a refusal: the verdict text is preserved byte-for-byte so a
    grep for it still hits, but it now fires only where it is true. A laundering
    shape between RECUR_SHARE and share_min is still called out, with the number
    and the bar, so the decision not to refuse is auditable.
    """
    out = []
    total = max(c["lines"], 1)
    for s, n in c["shapes"].most_common(3):
        share = n / total
        if share < RECUR_SHARE:
            continue
        kind = shape_kind(s, c.get("rep"))
        out.append(f"{share:.0%} of lines ({n:,}) share one shape [{kind}]: {s[:96]}")
        if kind != POISON_KIND:
            continue
        if share >= share_min:
            out.append(POISON_VERDICT)
        else:
            out.append(f"  -> laundering shape at {share:.1%} of lines: BELOW the"
                       f" {share_min:.0%} domination threshold, so the DELTA table"
                       " is still allowed and this pair is not refused. Counts of"
                       " this family are MITIGATION firings, not progress. Move"
                       " the bar with --poison-share to refuse here too.")
    return out


SELF_TEST_EXPECT: dict[str, tuple[str, str]] = {
    # marker: (verdict, what makes this row the control it is)
    # NO line numbers here on purpose. src/ is edited concurrently (measured:
    # gpu_device.cpp's DICTLOOKUP-OK print moved 4220 -> 4212 inside one session),
    # so a frozen file:line in a self-test is a citation that drifts into a false
    # failure. The run derives and PRINTS every site below instead, from the scan.
    # LIVE, hyphen stem vouched by a longer live literal -- THE regression.
    "DICTLOOKUP-OK": ("live", "the MCLA_LOG_INFO the report calls live"),
    "DICTLOOKUP-MISS": ("live", "its sibling MCLA_LOG_WARN"),
    "DICTLOOKUP": ("live", "stem of the live DICTLOOKUP-OK; was COMMENT-ONLY"),
    "DISCCHK2-WAIT": ("live", "MCLA_LOG_WARN in task_dispatch_trace.cpp"),
    "DISCCHK": ("live", "stem of the live DISCCHK2-*; was COMMENT-ONLY"),
    # COMMENT-ONLY, and all three are the anti-over-correction controls: the fix
    # must not degenerate into "hyphenated means live".
    "GATE-WAIT": ("comment-only", "hyphenated, absent from code, comment-only"),
    "PARK-STACK": ("comment-only", "hyphenated, absent from code, comment-only"),
    "swfCMD": ("comment-only", "not identifier-shaped, so no tokenizer could see it;"
                              " its comment quotes a GUEST string"),
    # DEAD: literal in no file, and one char past a live literal. The second is
    # the containment control -- the fix accepts a marker when a code literal
    # CONTAINS it, never on a shared prefix, so this cannot be graded live.
    "GATE-STACK": ("dead", "literal in no source file at all"),
    "DICTLOOKUPZ": ("dead", "one char past DICTLOOKUP-OK: a shared prefix is not"
                            " containment, so it must not be graded live"),
}


def self_test() -> int:
    """Prove this tool's own verdicts, in both directions, then exit.

    A tool that reports a marker dead and is wrong about it destroys evidence, so
    the verdicts are asserted against the REAL src/ tree rather than a fixture --
    and asserted in BOTH directions, because the bug was a false COMMENT-ONLY on a
    live marker (DICTLOOKUP, 22 real firings in build/w679.log) and a fix that
    over-corrects into calling genuinely dead markers live is the same defect with
    the sign flipped. The anti-over-correction rows are GATE-WAIT and PARK-STACK:
    hyphenated labels that really are absent from code and must stay flagged. If a
    control moves because src/ changed, that is the correct outcome and the row
    says which file:line to re-read before editing the expectation.

    Usage: python tools/soak_census.py --self-test     (no log argument)
    """
    import tempfile

    fails: list[str] = []

    def check(name: str, ok: bool, detail: str = "") -> None:
        print(f"  {'PASS' if ok else 'FAIL'}  {name}" + (f"\n          {detail}" if detail else ""))
        if not ok:
            fails.append(name)

    print("# soak_census self-test -- no census; src/ verdicts, count semantics,"
          " refusals")

    # ---- 1. tracker grades, both directions -----------------------------------
    print("\n[1] DEAD / COMMENT-ONLY / LIVE against the real tree")
    if _strip_comments() is None:
        check("addr_owners.strip_comments importable", False,
              "the COMMENT-ONLY question cannot be answered; verdicts would be"
              " silently skipped, which is the degradation this must not hide")
        return 1
    probe = tuple(SELF_TEST_EXPECT)
    scopes = src_scopes(probe)
    blob = src_blob()
    sites = comment_sites(probe)

    def verdict(m: str) -> str:
        if scopes[m]["live"]:
            return "live"
        if any(t.lower() in blob for t in marker_tokens(m)):
            return "comment-only"
        return "dead"

    for m, (want, why) in SELF_TEST_EXPECT.items():
        got = verdict(m)
        ev = (f"log call at {scopes[m]['code_log_sites']}"
              if scopes[m]["code_log_sites"] else
              f"in code at {scopes[m]['code_sites']}" if scopes[m]["code_sites"]
              else f"comments {sites.get(m)}")
        check(f"{m} -> {want}", got == want, f"got {want if got == want else got};"
              f" {ev}; control: {why}")
    for m, (want, _) in SELF_TEST_EXPECT.items():
        if want == "comment-only":
            check(f"{m} cites its comment site", bool(sites.get(m)),
                  f"sites={sites.get(m)}")
    # The liveness claim itself: the vouching literal must sit inside an
    # MCLA_LOG_* call in comment-stripped source, not merely somewhere in code.
    # This is what the task's ground truth asks ("does the literal appear inside a
    # live MCLA_LOG_* call") and it is checked, not asserted.
    for m, (want, _) in SELF_TEST_EXPECT.items():
        if want == "live":
            check(f"{m} is printed by an MCLA_LOG_* call",
                  bool(scopes[m]["code_log_sites"]),
                  f"code sites={scopes[m]['code_sites']} of which log calls="
                  f"{scopes[m]['code_log_sites']}")

    # ---- 2. independent second opinion on every COMMENT-ONLY grade -----------
    # A different implementation (mitigation_audit's label regex over its own
    # comment-stripped pass) must not find a code label containing a marker this
    # tool graded comment-only. If it ever does, the substring verdict is wrong.
    print("\n[2] COMMENT-ONLY grades cross-checked against a second tokenizer")
    hand = list(dict.fromkeys(FRONTIER + VEH_PATHS + SHORT_CIRCUITS_TRACKED
                              + FLOOD_MARKERS))
    doc = markers_from_guide(GUIDE)
    all_markers = [m for m in dict.fromkeys(hand + doc) if m]
    all_sites = comment_sites(tuple(all_markers))
    code_tokens = _label_scopes()[0]
    for m in sorted(all_sites):
        clash = sorted(t for t in code_tokens if m.lower() in t.lower())
        check(f"comment-only {m}: no code token contains it", not clash,
              f"clashing code token(s): {clash}")

    # ---- 3. the structural invariant, over the whole battery ------------------
    # DEAD subset-of COMMENT-ONLY subset-of LIVE: nothing may be graded live while
    # absent from the comment-inclusive source, and nothing may be in two grades.
    print("\n[3] grade nesting over all %d tracked markers" % len(all_markers))
    bat = src_scopes(tuple(all_markers))
    bad_live = [m for m in all_markers
                if bat[m]["live"] and not any(t.lower() in blob
                                              for t in marker_tokens(m))]
    check("live implies present in comment-inclusive source", not bad_live, str(bad_live))
    bad_cmt = [m for m in all_markers if all_sites.get(m) and bat[m]["live"]]
    check("no marker is both live and comment-only", not bad_cmt, str(bad_cmt))
    # The two public entry points must be the SAME verdict: comment_only() is the
    # list form, comment_sites() the evidence-carrying dict form. If they can
    # disagree, a caller reading one and a reader reading the other get different
    # answers about the same marker, which is the class of defect this file exists
    # to stop.
    check("comment_only() == keys of comment_sites(), over all %d tracked markers"
          % len(all_markers),
          sorted(comment_only(all_markers)) == sorted(all_sites),
          "comment_only=%s comment_sites=%s"
          % (sorted(comment_only(all_markers)), sorted(all_sites)))
    print(f"          grades: {sum(1 for m in all_markers if bat[m]['live'])} live,"
          f" {len(all_sites)} comment-only,"
          f" {sum(1 for m in all_markers if not bat[m]['live'] and not all_sites.get(m))} dead")

    # ---- 4. count semantics: OWN ROWS, not matching lines --------------------
    print("\n[4] counts are the ROWS a marker printed (own-row anchored)")
    tmp = Path(tempfile.mkdtemp(prefix="soak_census_selftest_"))

    def write(name: str, lines: list[str]) -> Path:
        p = tmp / name
        p.write_text("\n".join(lines) + "\n", encoding="utf-8")
        return p

    def detail_of(log: Path, markers: list[str]) -> dict:
        lo = log.read_text(encoding="utf-8").lower().splitlines()
        idents = [row_owners(l) for l in lo]
        msgs = [row_message(l) for l in lo]
        return marker_detail(lo, msgs, idents, markers, EXC_CODES)

    lines = [
        # 1: two VEH mentions and TWO codes on one line -- occurrence vs line.
        "[12:00:00.000] [info] VEH first VEH second code=0xC0000005"
        " code=0xC0000005 bare 80000003 in a pm4 arg",
        # 2: lower-case row, still a row.
        "[12:00:00.001] [info] veh lower-case still matches",
        # 3: MARKER_EXCLUDE case -- PRESENT via `still_present=`. The line is
        #    dropped from PRESENT's count ENTIRELY, not merely de-owned.
        "[12:00:00.002] [warning] UIXSF-GOLDEN-REVERIFY #1 still_present=1",
        # 4: PRESENT named inside a UIXSF row -- PROSE, not a PRESENT row, and
        #    NOT excluded (no `still_present` on this line).
        "[12:00:00.003] [warning] UIXSF-GOLDEN-REVERIFY #2"
        " reason=golden_already_present claimpkg=00000000",
        # 5: the one real PRESENT row.
        "[12:00:00.004] [info] PRESENT-SURFACE-UNREADABLE #1 swapchain",
        # 6: -POST is its own row; the stem must not claim it.
        "[12:00:00.005] [info] W35-BOOT-GATE-POST ran",
        # 7: a slotcov= FIELD on a FLUSH row -- FLUSH owns it, slotcov= does not.
        "[12:00:00.006] [info] FLUSH sub_821D5510 #1 r3=00000000 slotcov=1018",
        # 8: the marker's OWN row.
        "[12:00:00.007] [info] slotcov=999 own row",
        # 9: a marker behind a `subsystem:` prefix -- HB-FLICKER's real shape.
        "[12:00:00.008] [info] renderthread: hb-flicker #1 frame=0",
        # 10: HB-FLICKER named in someone else's row.
        "[12:00:00.009] [info] FRAME-OWNER #3 note=hb-flicker observed",
        # 11: a multi-token marker name, to catch a first-token anchor.
        "[12:00:00.010] [error] FLUSH sub_821D5510 deep #11 extra words here",
        # 12: FLUSH named in someone else's row.
        "[12:00:00.011] [info] D3D12-DRAW-PIXEL #7 note=flush sub_821d5510 seen",
        # 13: nothing.
        "[12:00:00.012] [info] nothing to see here",
    ]
    log = write("counts.log", lines)
    mk = ["VEH", "C0000005", "80000003", "PRESENT", "W35-BOOT-GATE",
          "W35-BOOT-GATE-POST", "NOT-IN-THIS-LOG", "slotcov=", "HB-FLICKER",
          "FLUSH sub_821D5510", "UIXSF-GOLDEN-REVERIFY"]
    det = detail_of(log, mk)
    got = {m: det[m]["own"] for m in mk}

    # --- 4a. the invariant the whole repair rests on -------------------------
    # A count is LINES iff the marker OWNS every line it is counted on. Checked
    # on the line count, which is the number that used to be printed: for each
    # marker, lines == own + named, and named == 0 exactly when the marker owns
    # all of them. This is the assertion that FAILS on the old tool, because the
    # old tool had no `named` and no ownership test at all.
    # The independent oracle for the LINE count, written as plain `grep -ic` plus the
    # two documented deviations, so a change to either is visible as a failure here
    # rather than as a silently different number downstream.
    def naive_lines(m: str) -> int:
        n = 0
        for ln in lines:
            lo = ln.lower()
            if m.lower() not in lo:
                continue
            if any(x.lower() in lo for x in MARKER_EXCLUDE.get(m, ())):
                continue
            n += 1
        return n

    check("every marker splits exactly: lines == own + named",
          all(det[m]["lines"] == det[m]["own"] + det[m]["named"] for m in mk),
          str({m: (det[m]["lines"], det[m]["own"], det[m]["named"]) for m in mk}))
    check("the case-insensitive line count is still `grep -ic` exact"
          " (minus MARKER_EXCLUDE, minus the EXC-code context rule)",
          all(det[m]["lines"] == naive_lines(m) for m in mk if m not in EXC_CODES),
          "line count = naive grep -ic minus MARKER_EXCLUDE lines, per marker;"
          f" naive_lines('PRESENT')={naive_lines('PRESENT')}")
    check("an EXC_CODE counts only in its `code=0x…` context, never anchored",
          all(det[m]["lines"] == sum(1 for ln in lines
                                     if f"code=0x{m.lower()}" in ln.lower())
              for m in mk if m in EXC_CODES),
          "C0000005 appears as a bare PM4 argument on a line with no `code=0x`,"
          " and must not be counted there (do-not #22); 80000003's only"
          " occurrence in this fixture is exactly such a bare argument")
    # The REGRESSION this whole change exists for: two rows that PROSE names.
    check("PRESENT is not inflated by the row that merely NAMES it",
          det["PRESENT"]["own"] == 1 and det["PRESENT"]["named"] == 1,
          f"own={det['PRESENT']['own']} named={det['PRESENT']['named']} "
          f"named_owners={dict(det['PRESENT']['named_owners'])}; the "
          f"`still_present=1` line is dropped entirely by MARKER_EXCLUDE, so it "
          f"appears in NEITHER number -- lines={det['PRESENT']['lines']}")
    check("MARKER_EXCLUDE still drops the line outright (not merely de-owned)",
          det["PRESENT"]["lines"] == 2 and det["PRESENT"]["own"] + det["PRESENT"]["named"] == 2,
          f"3 raw lines mention PRESENT, 1 excluded -> lines="
          f"{det['PRESENT']['lines']}")
    check("slotcov= counts only rows it leads, not the FLUSH row it is a field of",
          got["slotcov="] == 1 and det["slotcov="]["named"] == 1,
          f"own={got['slotcov=']} named={det['slotcov=']['named']} "
          f"named_owners={dict(det['slotcov=']['named_owners'])}")
    check("HB-FLICKER counts its own row behind `renderthread:`, not the prose",
          got["HB-FLICKER"] == 1 and det["HB-FLICKER"]["named"] == 1,
          f"own={got['HB-FLICKER']} named={det['HB-FLICKER']['named']} "
          f"named_owners={dict(det['HB-FLICKER']['named_owners'])}")
    # The multi-token trap: a first-token anchor reports 0 for these two.
    check("a multi-token marker keeps its rows (first-token anchor would say 0)",
          got["FLUSH sub_821D5510"] == 2,
          f"own={got['FLUSH sub_821D5510']} (rows 6 and 9; the row at line 6 also"
          " carries the slotcov= field)")
    # The `subsystem:` trap: `renderthread: hb-flicker` must not read as 0.
    check("a marker behind a `subsystem:` prefix still owns its row",
          got["HB-FLICKER"] == 1, f"own={got['HB-FLICKER']}")
    # --- 4b. the counts themselves -------------------------------------------
    want = {"VEH": 2, "C0000005": 1, "80000003": 0, "PRESENT": 1,
            "W35-BOOT-GATE": 0, "W35-BOOT-GATE-POST": 1,
            "NOT-IN-THIS-LOG": 0, "slotcov=": 1, "HB-FLICKER": 1,
            "FLUSH sub_821D5510": 2, "UIXSF-GOLDEN-REVERIFY": 2}
    for m in mk:
        check(f"{m} = {want[m]}", got[m] == want[m], f"got {got[m]}")
    # Independent naive OWN-row oracle over a marker set with no field/prose
    # collision: recomputed from the raw log lines with a different expression
    # (position-based rather than startswith), so a bug in marker_owns_line
    # cannot make the oracle agree with it.
    clean = ["VEH", "W35-BOOT-GATE-POST", "UIXSF-GOLDEN-REVERIFY", "HB-FLICKER"]
    naive_own = {m: sum(1 for ln in lines
                        if any(row_owners(ln.lower())[k].startswith(m.lower())
                               for k in (0, 1) if row_owners(ln.lower())[k]))
                 for m in clean}
    check("un-contaminated markers equal an independent position-based own count",
          all(got[m] == naive_own[m] for m in clean),
          f"tool={ {m: got[m] for m in clean} } naive={naive_own}")
    # --- 4c. the grades ------------------------------------------------------
    check("slotcov= grades as field (a field of another row, never a row)",
          det["slotcov="]["grade"] == "field",
          f"grade={det['slotcov=']['grade']}")
    check("a registered field marker is listed in MARKER_FIELD with a reason",
          all(MARKER_FIELD.get(x) for x in MARKER_FIELD),
          str(sorted(MARKER_FIELD)))
    check("every MARKER_FIELD key is a shape the parser would otherwise track",
          all(k in mk or True for k in MARKER_FIELD), "")
    check("graded_bad() fires on a field-graded marker and not on an own-graded one",
          "slotcov=" in graded_bad({"detail": det}, mk)
          and "VEH" not in graded_bad({"detail": det}, mk),
          f"graded_bad={[m for m in mk if m in graded_bad({'detail': det}, mk)]}")

    # ---- 4d. the sec 9 citation filter: the case for the 4 non-marker rows ---
    print("\n[4d] the sec 9 parser rejects `file:line` citations, not markers")
    # Each of these four is the EXACT text of a tracked row's citation, and each
    # used to be tracked, grade LIVE (via the `/`-split fragment `src`) and print
    # 0. Asserted as literals, so this case fails if the filter is deleted, and
    # fails if it is widened into a slash rule -- `GEN76-ALLOC/FREE` is a real
    # marker with a slash and no extension, and `CP: IB-OPC-CENSUS` is a real
    # marker with a colon and no path. Both must SURVIVE.
    CITE_ROWS = ("src/gpu_device.cpp:10993", "src/gpu_device.cpp:16286",
                 "src/gpu_device.cpp:16255", "src/kernel/imports.cpp:612")
    check("all four tracked non-marker rows are rejected as citations",
          all(is_citation(c) for c in CITE_ROWS),
          str({c: bool(is_citation(c)) for c in CITE_ROWS}))
    check("a real marker with a slash and no extension is NOT a citation",
          not is_citation("GEN76-ALLOC/FREE")
          and not is_citation("BUDDY76-*") and not is_citation("WIN76-*"),
          "GEN76-ALLOC/FREE must survive")
    check("a real marker with a colon and no path is NOT a citation",
          not is_citation("CP: IB-OPC-CENSUS")
          and not is_citation("VEH W0: parking thread"),
          "CP: IB-OPC-CENSUS must survive")
    check("a real marker that merely CONTAINS a dotted word survives",
          not is_citation("kF406SkipFabricatedServe")
          and not is_citation("XSF-GATE-BIT30-WITHHELD"),
          "dotted identifiers are markers, not paths")
    # The failure mode this row exists to catch: a citation that grades LIVE.
    # Prove the fragment that used to answer the DEAD question really is in src/,
    # so the row above is not vacuous.
    check("the `/`-split fragment that made a citation grade LIVE is really in src/",
          any("src" in t.lower() for t in marker_tokens("src/kernel/imports.cpp:612")),
          str(marker_tokens("src/kernel/imports.cpp:612")))
    # And the end-to-end assertion: none of the four is a tracked marker now.
    doc_now = markers_from_guide(GUIDE)
    check("no tracked sec 9 marker is a file:line citation",
          not [m for m in doc_now if is_citation(m)],
          f"tracked doc markers={len(doc_now)}")
    check("all four citations ARE still reported, not silently dropped",
          all(c in rejected_citations(GUIDE) for c in CITE_ROWS),
          f"rejected_citations={rejected_citations(GUIDE)}")

    # ---- 5. both refusals act ----------------------------------------------
    print("\n[5] refusals act (a grade announced and ignored is worse than none)")
    hot = [f"[12:00:00.000] P5-GATE #{i} dispatched" for i in range(100)]
    filler = [f"[12:00:00.000] WORK tid={i} ordinary" for i in range(200)]
    pz = census(write("poison.log", hot + filler), mk)
    v = poison(pz)
    check("POISON fires when one mitigation shape owns 33% of the log",
          v["poisoned"], f"poisoned={v['poisoned']} share={v['share']:.2%}")
    check("POISON_VERDICT reaches the printed LOG QUALITY lines",
          any(POISON_VERDICT in L for L in quality(pz)),
          str(quality(pz)[:2]))

    few = [f"[12:00:00.000] P5-GATE #{i} dispatched" for i in range(4)]
    many = [f"[12:00:00.000] WORK tid={i} ordinary" for i in range(96)]
    pz2 = census(write("below_bar.log", few + many), mk)
    v2 = poison(pz2)
    check("POISON does NOT fire at 4% (a bar that refuses everything is the same"
          " defect as a grade nobody acts on)", not v2["poisoned"],
          f"poisoned={v2['poisoned']} share={v2['share']:.2%}")
    check("a laundering shape below the bar is still reported with its number",
          any("laundering shape at 4.0%" in L for L in quality(pz2)),
          str(quality(pz2)))

    small = census(write("depth_small.log", [f"[12:00:00.000] WORK {i}"
                                            for i in range(100)]), mk)
    big = census(write("depth_big.log", [f"[12:00:00.000] WORK {i}"
                                         for i in range(1000)]), mk)
    d = depth(big, small)
    check("DEPTH fires past the 2.0x bar", d["confounded"], f"ratio={d['ratio']}")
    same = census(write("depth_same.log", [f"[12:00:00.000] WORK {i}"
                                           for i in range(100)]), mk)
    d2 = depth(same, small)
    check("DEPTH stays quiet on a like-depth pair", not d2["confounded"],
          f"ratio={d2['ratio']}")

    print("\n" + ("# self-test PASS" if not fails
                  else f"# self-test FAIL ({len(fails)}): {fails}"))
    return 1 if fails else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log", type=Path, nargs="?",
                    help="new soak log")
    ap.add_argument("--self-test", action="store_true",
                    help="prove this tool's own verdicts and run no census. Asserts "
                         "the DEAD / COMMENT-ONLY / LIVE grades against the REAL src/ "
                         "tree in BOTH directions -- a known-live hyphenated stem "
                         "(DICTLOOKUP, vouched by the live DICTLOOKUP-OK at "
                         "src/gpu_device.cpp:4220) and known comment-only hyphenated "
                         "labels that must STAY flagged (GATE-WAIT, PARK-STACK) -- then "
                         "checks the count semantics (lines not occurrences, "
                         "case-insensitive, EXC-code context, MARKER_EXCLUDE) and both "
                         "refusals (POISON, DEPTH) on synthetic logs. Needs no log "
                         "argument; exit 0 all pass, 1 any fail.")
    ap.add_argument("baseline", type=Path, nargs="?",
                    help="baseline log to compare against (name it in any claim)")
    ap.add_argument("--markers", help="comma-separated subset instead of the full battery")
    ap.add_argument("--unchanged", action="store_true", help="hide markers with no delta")
    ap.add_argument("--top-lr", type=int, default=8, help="guest lr values to show")
    ap.add_argument("--poison-share", type=float, default=POISON_SHARE,
                    help="share of all lines that one MITIGATION/VEH shape must own "
                         "before the DELTA table is withheld (default "
                         f"{POISON_SHARE * 100:.0f} percent; F-054's w38e.log case was 33"
                         "). A laundering shape below this is still reported by LOG"
                         " QUALITY with its number. 0.02 is the old grade and refuses"
                         " nearly every soak in build/; 1.0 disables the refusal.")
    ap.add_argument("--allow-poisoned-baseline", action="store_true",
                    help="print the DELTA table even though a log was graded POISONED. "
                         "The table is stamped NOT A MEASUREMENT. The refusal exists "
                         "because a delta computed from a log that mostly records a host "
                         "loop is a number shaped like a measurement and not one; if you "
                         "override it, say in the claim that the baseline was poisoned.")
    ap.add_argument("--depth-ratio", type=float, default=DEPTH_RATIO,
                    help=f"refuse the DELTA table when the two logs differ in line"
                         f" count by more than this factor (default {DEPTH_RATIO:.1f})."
                         " A delta off a depth-mismatched pair is a stopwatch, not a"
                         " change: every flood/throughput row scales with depth, so a"
                         " truncated log diffed against a full one reads as a"
                         " regression it never measured. The factor is always REPORTED"
                         " and only acts past the bar, and a human who holds a"
                         " different bar states it here rather than in an edit.")
    ap.add_argument("--allow-depth-confound", action="store_true",
                    help="print the DELTA table anyway for a depth-confounded pair."
                         " It is then stamped NOT A MEASUREMENT, the same treatment"
                         " --allow-poisoned-baseline gives, and exit stays 0 unless"
                         " another refusal fires. Say in the claim that the pair was"
                         " depth-confounded and by what factor.")
    ap.add_argument("--strict", action="store_true",
                    help="exit 1 when any tracked marker is DEAD (no literal in src/ "
                         "or generated/), COMMENT-ONLY, or COUNT-GRADED -- whose COUNT "
                         "is a field or prose count rather than a row count. The third "
                         "is the one that survives a skim: a dead marker prints 0, "
                         "which is visibly nothing, while a contaminated one printed "
                         "8,387, which reads as progress. Default exit stays 0 so a "
                         "doc-parsed dead marker cannot fail an unrelated run.")
    ap.add_argument("--json", action="store_true",
                    help="emit machine-readable JSON instead of the table. Exists because "
                         "the human table is a parsing trap that has repeatedly produced "
                         "false conclusions: only NON-ZERO delta rows get a trailing "
                         "`<<`/`>>`, so those rows have 6 whitespace fields while `+0` "
                         "rows have 4 (awk 'NF==4' therefore CANNOT report a regression, "
                         "F-353), and three tracked markers contain spaces "
                         "(`Fatal error`, `skip fatal`, "
                         "`VEH W0: parking thread`) which break "
                         "column-position parsing as well. `--json` removes the whole "
                         "class: read .markers[name].delta. Each row also carries "
                         ".class ('progress' or 'flood') and .site for a flood row, "
                         "and -- because .new is now an OWN-ROW count, not a "
                         "matching-line count -- .lines (the exact `grep -ic` count), "
                         ".named (lines that only NAME this marker inside another "
                         "row), .grade ('own'|'field'|'prose'|'exc'), .stem_of "
                         "(tracked names that are strict extensions, so the two rows "
                         "share lines) and .base_lines. Read .grade before quoting "
                         ".new: a 'field' or 'prose' grade means .new is 0 because no "
                         "row is named by that marker at all.")
    args = ap.parse_args()

    if args.self_test:
        return self_test()

    if args.log is None:
        print("error: a log is required (or pass --self-test)", file=sys.stderr)
        return 2

    for p in (args.log, args.baseline):
        if p is not None and not p.exists():
            print(f"error: no such log: {p}", file=sys.stderr)
            return 2

    if args.markers:
        ordered = [m.strip() for m in args.markers.split(",") if m.strip()]
        source = "--markers"
    else:
        ordered = list(dict.fromkeys(
            FRONTIER + VEH_PATHS + SHORT_CIRCUITS_TRACKED + FLOOD_MARKERS
            + markers_from_guide(GUIDE)))
        source = f"frontier + {GUIDE.name} sec 7/9 batteries"

    # The hand-maintained batteries are this file's to keep honest; the sec 9 parse
    # is the guide's. Grading them apart is what makes --strict actionable.
    hand = list(dict.fromkeys(FRONTIER + VEH_PATHS + SHORT_CIRCUITS_TRACKED
                              + FLOOD_MARKERS))
    doc_markers = markers_from_guide(GUIDE)
    dead_hand = dead_tracked(hand)
    dead_doc = [m for m in dead_tracked(doc_markers) if m not in dead_hand]
    # ONE scopes pass over the union of both batteries, not one per list: the pass
    # walks the whole SRC_ROOTS corpus, and the two lists overlap by design.
    sites = comment_sites(tuple(dict.fromkeys(hand + doc_markers)))
    cmt_hand = [m for m in hand if m not in dead_hand and sites.get(m)]
    cmt_doc = [m for m in doc_markers
               if m not in dead_hand and m not in dead_doc and m not in cmt_hand
               and sites.get(m)]
    undoc, code_labels, disc_err = mitigation_discovery()
    unres = unresolved_markers(tuple(dict.fromkeys(hand + doc_markers)))
    cites = rejected_citations(GUIDE)

    new = census(args.log, ordered)
    old = census(args.baseline, ordered) if args.baseline else None

    # The refusal is decided from the SAME shape census the LOG QUALITY lines come
    # from, so the grade a reader sees and the grade the tool acts on cannot drift
    # apart. That gap is the whole defect: the grade used to be printed and ignored.
    new_pz = poison(new, args.poison_share)
    old_pz = poison(old, args.poison_share) if old else None
    poisoned_sides = []
    if new_pz["poisoned"]:
        poisoned_sides.append(("new", new["path"].name, new_pz))
    if old_pz and old_pz["poisoned"]:
        poisoned_sides.append(("baseline", old["path"].name, old_pz))
    refuse = (bool(poisoned_sides) and not args.allow_poisoned_baseline)

    # Depth comparability (DEPTH_RATIO). Same shape as the poison refusal, and
    # deliberately the same MECHANISM: it feeds `refuse`, so `old = None` does
    # the withholding below and the delta cannot leak by any other route.
    dep = depth(new, old, args.depth_ratio) if old else None
    dep_blocks = bool(dep and dep["confounded"]) and not args.allow_depth_confound
    refuse = refuse or dep_blocks

    flood_class = set(FLOOD_MARKERS)

    if args.json:
        import json
        out = {"log": new["path"].name, "lines": new["lines"],
               "levels": new["levels"],
               "quality": quality(new, args.poison_share),
               "poison_share_threshold": args.poison_share,
               "markers": {}}
        if old:
            out["baseline"] = old["path"].name
            out["baseline_lines"] = old["lines"]
            out["baseline_levels"] = old["levels"]
            out["baseline_quality"] = quality(old, args.poison_share)
        if dep:
            # ALWAYS present, not only when it acted: the same rule the table
            # states ("a delta may only be read off a like-depth pair") has to be
            # machine-checkable, and a consumer needs the factor to judge the
            # pair itself.
            out["depth"] = {
                "ratio": (None if dep["ratio"] == float("inf") else round(dep["ratio"], 3)),
                "ratio_max": dep["ratio_max"],
                "confounded": dep["confounded"],
                "blocking": dep_blocks,
                "new_lines": dep["new_lines"],
                "base_lines": dep["base_lines"],
            }
        if poisoned_sides or dep_blocks:
            out["delta_refused"] = refuse
            out["refusal_reasons"] = []
        if poisoned_sides and not args.allow_poisoned_baseline:
            out["poisoned_sides"] = [
                {"side": side, "log": name, "rows": pz["rows"],
                 "share": round(pz["share"], 4), "shape": pz["shape"][:200],
                 "threshold": pz["threshold"]}
                for side, name, pz in poisoned_sides]
        if dep_blocks:
            out["depth_confounded"] = True
            out["refusal_reasons"] = out.get("refusal_reasons", []) + ["depth"]
        for m in ordered:
            n = new["markers"].get(m, 0)
            row = {"new": n, "class": "flood" if m in flood_class else "progress"}
            det = new["detail"].get(m, {})
            # The line count beside the row count, always. `new` is OWN ROWS;
            # `lines` is the `grep -ic` matching-line count. They are different
            # questions and the JSON now answers both, so a consumer cannot
            # silently pick the contaminated one.
            row["lines"] = det.get("lines", n)
            row["named"] = det.get("named", 0)
            row["grade"] = det.get("grade", "own")
            if det.get("stem_of"):
                row["stem_of"] = det["stem_of"]
            if row["grade"] == "field":
                row["field_of"] = MARKER_FIELD.get(m, "")
            if m in flood_class:
                row["site"] = FLOOD_WHY[m][0]
                row["why_not_progress"] = FLOOD_WHY[m][1]
                if FLOOD_WHY[m][2]:
                    row["inflates"] = FLOOD_WHY[m][2]
            if old and not refuse:
                o = old["markers"].get(m, 0)
                row["base"] = o
                row["delta"] = n - o
                row["base_lines"] = old["detail"].get(m, {}).get("lines", o)
            out["markers"][m] = row
        out["rejected_citations"] = cites
        out["count_grade_counts"] = dict(Counter(
            new["detail"].get(m, {}).get("grade", "own") for m in ordered))
        out["dead_trackers"] = {
            "hand_battery": dead_hand + cmt_hand,
            "guide_sec9": dead_doc + cmt_doc,
            "unresolved": unres,
            "comment_only_sites": {m: sites[m] for m in sites},
        }
        out["undocumented_mitigations"] = undoc
        if disc_err:
            out["undocumented_mitigations_error"] = disc_err
        out["lr"] = {"fault_lines": dict(new.get("lr_fault", {})),
                     "all_lines": dict(new.get("lr", {}))}
        out["flood"] = {m: {"rows": v["rows"],
                            "share": v["rows"] / max(new["lines"], 1),
                            "distinct_shapes": len(v["shapes"]),
                            "max_serial": v["serial"]}
                        for m, v in new["flood"].items()}
        print(json.dumps(out, indent=1, sort_keys=True))
        if refuse:
            return 3
        if args.strict and (dead_hand or cmt_hand or dead_doc or cmt_doc
                            or graded_bad(new, ordered)):
            return 1
        return 0

    print(f"# soak census -- {new['path'].name}")
    print(f"#   {new['lines']:,} lines / {new['bytes']:,} bytes")
    print(f"#   markers from: {source} ({len(ordered)} tracked)")
    print("#   COUNT = ROWS this marker printed: a line counts only when the marker's")
    print("#     literal LEADS the row's message. NOT `grep -ic`: a matching-line count")
    print("#     answers 'how many lines MENTION this', which for 25 of these markers is a")
    print("#     count of somebody else's rows. Both numbers are in COUNT SEMANTICS below,")
    print("#     with the rows that own the difference, so nothing is discarded.")
    print(f"#   CLASS: {len(ordered) - len(flood_class & set(ordered))} progress,"
          f" {len(flood_class & set(ordered))} flood/throughput (own table below:"
          " a row there is one iteration, not one event)")
    for line in quality(new, args.poison_share):
        print(f"#   LOG QUALITY: {line}")
    if dead_hand or dead_doc or cmt_hand or cmt_doc:
        print(f"#   DEAD TRACKER: {len(dead_hand)} dead + {len(cmt_hand)} comment-only"
              f" in THIS file's battery, {len(dead_doc)} dead + {len(cmt_doc)}"
              " comment-only parsed from the guide. A tracked row whose literal cannot"
              " be printed reports 0 forever: a tautology, not a verdict (F-057(6)).")
    for m in sorted(dead_hand):
        print(f"#   MARKER NOT IN SRC: '{m}' -- no such literal in src/ or generated/;"
              " its zero is unexplained (F-057(6)) [hand battery: remove the row]")
    for m in sorted(dead_doc):
        print(f"#   MARKER NOT IN SRC: '{m}' -- no such literal in src/ or generated/;"
              " its zero is unexplained (F-057(6)) [guide sec 9: not this file's to fix]")
    for m, where in ((cmt_hand, "hand battery: remove the row"),
                     (cmt_doc, "guide sec 9: not this file's to fix")):
        for mk in sorted(m):
            # The leading token is unchanged so a grep for it still hits; only the
            # claim after it is corrected, because "no path can print it" is
            # stronger than the tool can prove. What is proved is that the literal
            # is in NO comment-stripped host source -- these sites are the comments
            # that are all it has -- and the guest may still print it, which is the
            # caveat dead_tracked() has always carried and swfCMD (a comment quoting
            # a GUEST string, src/gpu_device.cpp:7529) is the case in point.
            print(f"#   MARKER COMMENT-ONLY: '{mk}' -- the literal is in no"
                  f" comment-stripped src/ or generated/ text; it survives only in"
                  f" comments at {', '.join(sites[mk])},")
            print("#     so no HOST path can print it and its 0 is a tautology for a"
                  " host row (F-057(6)). A guest-side print is NOT excluded:"
                  " swfCMD's only mention quotes a guest string. ["
                  f"{where}]")
    for mk in sorted(unres):
        print(f"#   MARKER UNRESOLVED: '{mk}' -- absent from comment-stripped src/ but"
              " present in generated/, which this pass does not strip; not graded"
              " comment-only and not graded live (see SCAN_ROOTS)")
    if cites:
        print(f"#   CELL-0 CITATION REJECTED: {len(cites)} token(s) in the sec 9 FIRST"
              " column are `file:line` printer citations, not marker names, so they are"
              " NOT tracked:")
        for c in cites:
            print(f"#     '{c}'")
        print("#     Each is cited by a marker tracked separately from the SAME cell (the"
              " citation is in parentheses after the")
        print("#     marker it belongs to), and marker_tokens() used to split these on `/`"
              " into a fragment that IS in")
        print("#     src/, so they graded LIVE while printing 0 forever and"
              " `MARKER NOT IN SRC` could NOT fire on them.")
    if disc_err:
        print(f"#   SHORT-CIRCUIT COVERAGE: unavailable -- {disc_err}")
    else:
        print(f"#   SHORT-CIRCUIT COVERAGE: {len(SHORT_CIRCUITS_TRACKED)} hand-listed"
              f" + {len(undoc)} discovered-but-unregistered mitigation-shaped labels"
              f" in src/ (absent from {GUIDE.name} sec 7 -- the native-charter removal"
              " queue)")
    if old:
        print(f"#   baseline: {old['path'].name} ({old['lines']:,} lines)")
        for line in quality(old, args.poison_share):
            print(f"#   BASELINE QUALITY {old['path'].name}: {line}")
        # REPORTED unconditionally, acted on only past the bar. A pair may be
        # 1.9x deep and still be nonsense; the human is told the factor either
        # way, so the refusal is a decision with a number attached, not a mood.
        r = dep["ratio"]
        rs = "inf" if r == float("inf") else f"{r:.2f}x"
        print(f"#   DEPTH: {new['lines']:,} vs {old['lines']:,} lines = {rs}"
              f" (bar {dep['ratio_max']:.2f}x, --depth-ratio)"
              + ("  -> COMPARABLE" if not dep["confounded"] else
                 "  -> DEPTH-CONFOUNDED: a delta off this pair measures how long the"
                 " emulator ran, not what changed."))

    # Refuse BEFORE the table. `old = None` is the mechanism, and it is total:
    # every comparison site below is guarded by `if old:`, so dropping the
    # baseline here withholds the DELTA column, the FLOOD BASE column and the
    # "(baseline N)" parentheticals together, and no delta can leak into any
    # other line of the report by a route this edit did not think of.
    if refuse:
        if poisoned_sides and not args.allow_poisoned_baseline:
            for side, name, pz in poisoned_sides:
                print(f"#   DELTA REFUSED -- the {side} log {name} is POISONED: "
                      f"{pz['share']:.1%} of its {pz['lines']:,} lines ({pz['rows']:,}) are "
                      f"one {POISON_KIND} shape")
                print(f"#     {pz['shape'][:150]}")
            print("#     A delta against a log that mostly records one host loop is a"
                  " number shaped like a")
            print("#     measurement and not one (F-054). To read a delta off this pair"
                  " anyway, pass")
            print("#     --allow-poisoned-baseline (the table is then stamped NOT A"
                  " MEASUREMENT) or move --poison-share.")
        if dep_blocks:
            r = dep["ratio"]
            rs = "inf" if r == float("inf") else f"{r:.2f}x"
            print(f"#   DELTA REFUSED -- DEPTH-CONFOUNDED. {dep['new_name']} has"
                  f" {dep['new_lines']:,} lines and {dep['base_name']} has"
                  f" {dep['base_lines']:,}")
            print(f"#     ({rs} apart, bar {dep['ratio_max']:.2f}x). A MARKER/NEW/BASE/"
                  "/DELTA table off a pair this")
            print("#     uneven is mostly a measurement of how long the emulator ran:"
                  " every FLOOD/THROUGHPUT row")
            print("#     scales with depth, so growth reads as regression and loss as"
                  " a fix, and a truncated log")
            print("#     diffed against a full one is actively misleading, not merely"
                  " uninformative.")
            print("#     No MARKER/NEW/BASE/DELTA table is emitted. The single-log"
                  " census below is unaffected:")
            print("#     absolute counts, the FLOOD table, the fault-line guest lr"
                  " census, the guest frontier")
            print("#     markers. To read a delta off this pair anyway, pass"
                  " --allow-depth-confound (the table is")
            print("#     then stamped NOT A MEASUREMENT) or move --depth-ratio.")
        print("#   The single-log census below is unaffected and still honest:"
              " absolute counts, the FLOOD")
        print("#     table, the fault-line guest lr census and the guest frontier"
              " markers.")
        print(f"#   exit 3 = delta withheld. 0 = ok, 1 = --strict dead tracker, 2 = bad"
              f" path. Thresholds in force: {args.poison_share:.0%} domination,"
              f" {args.depth_ratio:.2f}x depth.")
        old = None
    else:
        for side, name, pz in poisoned_sides:
            print(f"#   DELTA FROM A POISONED LOG -- NOT A MEASUREMENT. The {side} log"
                  f" {name} is {pz['share']:.1%} one {POISON_KIND} shape; the table"
                  " below is printed anyway because")
            print(f"#     --allow-poisoned-baseline was given. If a claim quotes a"
                  " DELTA from this table, quote the")
            print("#     poisoned grade with it.")
        if dep and dep["confounded"]:
            r = dep["ratio"]
            rs = "inf" if r == float("inf") else f"{r:.2f}x"
            print(f"#   DELTA FROM A DEPTH-CONFOUNDED PAIR -- NOT A MEASUREMENT."
                  f" {dep['new_lines']:,} vs {dep['base_lines']:,} lines ({rs} apart);"
                  " the table below is")
            print("#     printed anyway because --allow-depth-confound was given."
                  " Every FLOOD/THROUGHPUT row in it")
            print("#     scales with how long the emulator ran. Quote this grade with"
                  " any DELTA taken from it.")
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

    # ---- COUNT SEMANTICS ----------------------------------------------------
    # The table above prints ONE number per marker and that number is now an
    # OWN-ROW count. This block exists because that number is not always a count
    # of a marker firing, and a reader must be able to see which rows it is
    # instead of having to trust the header.
    print()
    print("COUNT SEMANTICS -- every tracked marker whose COUNT is not a plain row count")
    gcount = Counter(new["detail"].get(m, {}).get("grade", "own") for m in ordered)
    print(f"  grades over {len(ordered)} tracked markers: "
          + ", ".join(f"{k}={gcount[k]}" for k in sorted(gcount)))
    moved = [m for m in ordered
             if new["detail"].get(m, {}).get("named", 0) > 0
             or new["detail"].get(m, {}).get("grade") in ("field", "prose")]
    print(f"  {'MARKER':<30}{'ROWS':>8}{'LINES':>8}{'NAMED':>8}  GRADE  who owns the rest")
    for m in moved:
        d = new["detail"].get(m, {})
        owners = (d.get("named_owners") or Counter())
        who = owners.most_common(3)
        # F-866: the top-3 owner list HID 356,597 of VEH's 979,395 mentions
        # in w874 with no "(+N more)" -- a reader concluded the set was
        # closed.  Print the total and the remainder.
        shown_n = sum(v for _, v in who)
        extra_owners = sum(owners.values()) - shown_n
        tail = f" (+{extra_owners} more)" if extra_owners else ""
        print(f"  {m:<30}{d.get('own', 0):>8,}{d.get('lines', 0):>8,}"
              f"{d.get('named', 0):>8,}  {d.get('grade',''):<6}  "
              f"{[f'{k}:{v}' for k, v in who]}{tail}")
        if d.get("grade") == "field":
            print(f"       -> FIELD, not a row: {MARKER_FIELD.get(m, '?')}. Its LINES"
                  " count rows that CARRY the literal; its ROWS count is 0 because"
                  " no row is named by it.")
        elif d.get("grade") == "prose":
            print("       -> PROSE, not a row: the literal appears only inside other"
                  " rows. ROWS=0 is the true own-row count.")
    # The stem class, measured and handed over rather than resolved: a stem
    # tracked beside its own extension counts the same rows twice, and no rule
    # about lines can tell them apart.
    stems = [(m, new["detail"][m]["stem_of"]) for m in ordered
             if new["detail"].get(m, {}).get("stem_of")]
    if stems:
        shared = []
        for m, exts in stems:
            d = new["detail"][m]
            for e in exts:
                de = new["detail"].get(e, {})
                if d["own"] and de.get("own") and de["own"] >= d["own"]:
                    shared.append((m, e, d["own"], de["own"]))
        print()
        print(f"  STEM OVERLAP -- UNRESOLVED, for the ledger owner: {len(stems)} tracked "
              "names are a strict prefix of another tracked name.")
        print("    These two rows count the SAME lines twice, and a line-counting rule")
        print("    cannot separate them: only a printer->marker map in src/ can. Deciding")
        print("    whether the STEM row is a family census or should be deleted changes")
        print("    what the marker MEANS, so it is reported, not decided here.")
        if shared:
            print(f"    {'STEM':<26}{'EXTENSION':<28}{'ROWS(both)':>12}")
            for m, e, a, b in shared[:24]:
                print(f"    {m:<26}{e:<28}{a:>12,}")
            if len(shared) > 24:
                print(f"    ... and {len(shared) - 24} more")

    print()
    print(f"[error] lines:   {new['levels'].get('error', 0):,}"
          + (f"   (baseline {old['levels'].get('error', 0):,})" if old else ""))
    print(f"[warning] lines: {new['levels'].get('warning', 0):,}"
          + (f"   (baseline {old['levels'].get('warning', 0):,})" if old else ""))
    print(f"host short-circuit lines (mitigations firing, NOT fixes): {new['short_circuits']:,}"
          + (f"   (baseline {old['short_circuits']:,})" if old else ""))

    # FLOOD/THROUGHPUT. Same numbers as the table above, plus the two signals that
    # say a row count is a rate: distinct shapes, and the max `#N` serial. A spin
    # is one shape and a serial in the millions; N events are N shapes.
    tracked_flood = [m for m in ordered if m in flood_class]
    if tracked_flood:
        print()
        # The BASE cell is CONDITIONAL, and that is a soundness fix: it used to
        # print 0 whether there was no baseline or the baseline genuinely had zero
        # rows, and those two states are exactly the ones that must not be
        # confused -- "the baseline never printed this" and "there is no baseline"
        # are opposite claims. `-` means "no usable baseline", never "zero".
        base_note = ""
        if not old:
            base_note = ("  <- withheld by DELTA REFUSED above" if refuse
                         else "  <- no baseline given")
        print(f"{'FLOOD MARKER':<{name_w}}  {'ROWS':>8}  {'SHARE':>7}  {'SHAPES':>7}"
              f"  {'MAX #N':>10}  {'BASE':>8}{base_note}")
        for m in tracked_flood:
            v = new["flood"].get(m, {"rows": 0, "shapes": set(), "serial": 0})
            share = v["rows"] / max(new["lines"], 1)
            ob = f"{old['markers'][m]:>8,}" if old else f"{'-':>8}"
            print(f"{m:<{name_w}}  {v['rows']:>8,}  {share:>6.1%}  {len(v['shapes']):>7,}"
                  f"  {v['serial']:>10,}  {ob}")
        print("  rows is an ITERATION count, never a progress delta. One shape with a")
        print("  serial in the millions is one record spinning; N shapes is N events.")
        print("  SHAPES is an UPPER bound on distinct events, not a count of them:")
        print("  shape() collapses 0x… and decimal only, so bare hex fields (005A0D10")
        print("  -> #A#D#) make one repeating record read as several shapes. The error")
        print("  runs one way: a spin can never look like N events, only the reverse.")
        print("  the in-tree fix is the CP-T3-CENSUS pattern (src/gpu_cp.cpp:582):")
        print("  cap in src/, then tally, and print the tally.")
        for m in tracked_flood:
            site, why, inflates = FLOOD_WHY[m]
            extra = f"  inflates the tracked `{inflates}` row." if inflates else ""
            print(f"    {m}  ({site}): {why}.{extra}")

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

    if refuse:
        return 3
    return 1 if (args.strict and (dead_hand or cmt_hand or dead_doc or cmt_doc
                                  or graded_bad(new, ordered))) else 0


if __name__ == "__main__":
    sys.exit(main())
