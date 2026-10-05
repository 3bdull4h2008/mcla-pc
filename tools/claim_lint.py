#!/usr/bin/env python3
"""Mechanical gate for the findings ledger -- the machine behind the five review rules.

An adversarial review of one session's work found five ways a finding can be
wrong while looking cited, and the project's own history shows written advice
does not survive a 20,000-line investigation. So each rule is checked, not
restated. Nothing here pattern-matches the ledger for the *string* of a tool
name and calls it evidence: rule 1 READS the cited source lines, rule 2 RUNS
`tools/ppc_xrefs.py fn` and compares its output to the sentence that made the
claim. A linter that only greps its own input is a rubber stamp.

    R1  NO COUNTER IS REASONED ABOUT BEFORE ITS PRODUCER IS READ.
        Every number a finding reasons from must carry a `file:line` in the
        EMITTING statement. This check resolves every `file.ext:N[-M]` citation
        in the entry -- bare filenames included, via a basename index over
        src/ generated/ config/ tools/ docs/, with AMBIGUOUS (two files, same
        name) reported rather than guessed -- and grades the cited range:
          FAIL  RANGE-OF-FILE      the citation is past EOF and the file has
                                   not changed since the entry was written
          FAIL  PRODUCER-MISSING   the sentence's attribution token appears
                                   nowhere within +-40 lines of the citation,
                                   and the file has not moved since
          UNVER  PRODUCER-DRIFT     it is within +-40 lines
          UNVER  PRODUCER-ROTTED    the file was edited after the entry, so
                                   re-cite the current line; the report prints
                                   where the token is NOW
          UNVER  NO-CITATION       a number reasoned from with no file:line in
                                   its own paragraph
          FAIL  STALE-ARTIFACT     a `build/mcla.map`-class artifact NEWER
                                   than the log it explains (see below)
        The FAIL/UNVERIFIABLE split is the whole design. `src/` moves several
        times a day; a rule that calls every stale line an error grades 384 of
        593 findings and gets switched off, so R1's FAIL arm is reserved for a
        file that has NOT changed. `.md`/`.log` citations get the range check
        only -- a doc is not a producer. The F-630 case this exists for:
        `PHYS-CENSUS total=46.0MB` read as live occupancy, while the producer
        is `s_totalBytes.fetch_add(size+0x420)` (src/kernel/imports.cpp:3473 at
        20:04 on 09-28; it was 3202 an hour earlier -- the symbol does not move,
        the line does, which is why the report prints where the token is NOW) --
        cumulative REQUESTED bytes, reset above 200 MB (:3484), success path
        only (:3476). A number whose producer cannot be located is UNVERIFIABLE,
        never a pass.

    R2  NO `lr` IS NAMED AS A FUNCTION WITHOUT RESOLUTION IN THE SAME ENTRY.
        Any `lr=<hex>` in an entry needs a `ppc_xrefs.py ... fn <hexVA>`
        invocation in that same entry, and THE TOOL IS RUN on those addresses:
        an output of `sub_XXXXXXXX +0xNN` with NN != 0 is a return address
        inside a function, so a sentence calling that lr "the function" /
        "the caller" / "the writer" is FAIL LR-RETURN-ADDRESS. A sentence that
        says the opposite ("a return address is not a function") is exempt, or
        the rule would fail F-631 for writing down the lesson. The F-630 case
        is `lr=821C667C`, which is `sub_821C6658 +0x24`, a return address
        inside a `memset(ptr,0,n*12)` helper. Default scope is the rule as
        briefed (ANY bare `lr=`); pass `--attributed-only` for the narrow
        version that fires only when the sentence attributes the lr.

    R3  A FINDING THAT REORDERS PRIORITY GETS A REFUTATION PASS FIRST.
        Priority language (`outranks`, `ROOT CAUSE`, `the blocker`, `unblocks`,
        plus two declared below) requires a LATER entry in the same file that
        both cites the id and carries a verdict. No such entry -> FAIL
        UNREFUTED. A hit inside another finding's possessive ("F-630's
        'outranks everything' framing") is not this entry's claim and is
        skipped, or every refutation would have to answer for the claim it
        demolished. "A different actor" is NOT in the ledger as data, so it is
        reported, not checked: see ACTOR_GAP. `--as-of <id>` truncates the
        ledger AT `<id>`, which is how the review's question is re-asked
        ("had anyone ruled on F-630 by then?") without editing history.

    R4  AN INSTRUMENT IS RE-CHECKED AGAINST THE LEDGER'S OWN PRIOR VERDICTS.
        Every instrument in an entry (`PARK-SAMPLE`, `PHYS-CENSUS`,
        `F375-HEAPSTORE`, `total=`, a counter field, ...) is looked up in a
        verdict index built from the EARLIER entries: a PROHIBITION word
        (stale/lies/blind/unusable/cumulative/reset/success-path/capped/...)
        in the instrument's own prose paragraph. If one exists, the new entry
        must cite the entry that said so, or repeat the verdict beside the
        name; otherwise FAIL CONTRADICTED. Two narrowings are load-bearing and
        both were forced by measurement: pasted LOG ROWS are data, not
        verdicts (32 of the first hits were `PHYS-CENSUS` rows whose own help
        text says "blind"), and the lookback is bounded (`--r4-window`, default
        60 entries ~ one day) because "some earlier entry said something bad
        about this name" is a property of a 593-entry corpus, not of a finding.
        The F-630 case is exactly this: F-572 had already written that
        PHYS-CENSUS `bytes` is the CUMULATIVE total, and F-630 read
        `total=46.0MB` as live occupancy without citing it.

    R5  EVERY SAMPLE-WINDOW COUNT STATES ITS WINDOW.
        A count of stores/rows/events that co-occurs with a bounded-watch token
        must be accompanied, in the SAME PARAGRAPH, by the window's byte width
        or by LOWER-BOUND language. F-630's "eight header U32 stores" came from
        `F375-HEAPSTORE` rows, a 0x240-byte watch over a ~5.2 MB memset, so 8
        was a lower bound presented as a total.

Usage:
    python tools/claim_lint.py                     # whole ledger
    python tools/claim_lint.py F-630               # one finding (or an id prefix)
    python tools/claim_lint.py docs/OTHER.md       # another ledger
    python tools/claim_lint.py --strict            # UNVERIFIABLE also exits 1
    python tools/claim_lint.py --as-of F-630       # the ledger as it stood then
    python tools/claim_lint.py --selftest          # one FAIL + one control/rule

Exit: 0 clean, 1 on any FAIL, 1 on UNVERIFIABLE with --strict. Reads only --
this file never writes anything, and --selftest's fixtures go to the system
temp dir, never under the repo.
"""

from __future__ import annotations

import argparse
import io
import re
import subprocess
import sys
import tempfile
from collections import Counter
from datetime import datetime
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
DEFAULT_LEDGER = REPO / "docs" / "ROOT_CAUSE_VALIDATION.md"
XPREFS = REPO / "tools" / "ppc_xrefs.py"

# The ledger is UTF-8 (mojibake and all) and Windows consoles are cp1252, so
# printing a finding that quotes an arrow or a box-drawing character dies with
# UnicodeEncodeError halfway through the report -- which reads as "the tool is
# broken" rather than "the finding is old". Reconfigure once, replace what still
# will not encode.
for _s in (sys.stdout, sys.stderr):
    try:
        _s.reconfigure(encoding="utf-8", errors="replace")
    except (AttributeError, ValueError):
        pass

# ---------------------------------------------------------------- entry model

# An entry starts at `### F-630 (...)` (long form) or `**F-001 - ...**` (the
# compressed region). Both are the ledger's own two shapes, so both are read;
# a heading may name a range (`### F-617/F-618`), in which case the first id is
# primary and the rest are aliases that also select the entry.
ENTRY_LONG = re.compile(r"^#{2,4} .*\bF-\d", re.M)
ENTRY_BOLD = re.compile(r"^\*\*F-\d+\b", re.M)
F_ID = re.compile(r"\bF-(\d{3,4})\b")

CITE = re.compile(
    r"(?<![\w./\\-])((?:[\w.-]+[\\/])*[\w.-]+\.(?:cpp|cc|c|h|hpp|inc|cxx|toml|py|ps1|bat|cmd|md|log|map|cfg|txt|json|xml|xex|rpf|xex)"
    r"(?::\d+(?:-\d+)?)+)")
BARE_COLON = re.compile(r"(?<![\w:/]):(\d{1,5})\b")
# An instrument is a SCREAMING-HYPHEN name or a lower-case `field=` of a log row
# (the brief's "a counter name"). `2026-09-28` cannot match: it starts with a
# digit. `F375-HEAPSTORE`, `PARK-SAMPLE`, `C6D90-GROW`, `HEAPLEAK-SUM` do.
INSTRUMENT = re.compile(r"\b([A-Z][A-Z0-9]{1,}(?:-[A-Z0-9]{2,})+)\b")
FIELD_INSTRUMENT = re.compile(r"\b([a-z][a-z0-9_]{2,15})=(?![=])")
# `off=`, `trip=`, `obj=`, `r3=` are structure of a row, not an instrument: F-630
# tripped R4 on six of them before this list existed, which is how a gate gets
# read as noise. A FIELD is an instrument when its name reads like a quantity.
FIELD_SKIP = {
    "off", "trip", "obj", "want", "val", "size", "sp", "lr", "tid", "nop", "raw",
    "inc", "dst", "src", "arg", "par", "ppc", "ctx", "mem", "ptr", "mod", "sec",
    "ms", "idx", "num", "cnt", "len", "tag", "str", "buf", "img", "sym", "rva",
    "rip", "pid", "tid", "seq", "dev", "obj", "key", "name", "type", "file",
}
# Instrument names that are host/tooling nouns, not measurements. Kept tiny and
# greppable: a suppression is itself a claim about the ledger.
INSTRUMENT_SKIP = {
    "ROOT-CAUSE", "PART-3", "TASK-JOIN", "MSYS", "READ-ONLY", "LOAD-BEARING",
    "METHOD-RULES", "READ-ONLY-ONLY",
}
PRIORITY = re.compile(
    r"outranks|\broot cause\b|\bthe blocker\b|\bunblocks?\b"
    r"|worth more than every other|\breorders the (?:whole )?project"
    r"|\bthis is the boot\b|\bthe whole project\b", re.I)
# A negated or hypothetical priority phrase is not a priority claim. F-588
# writes "**Not a root cause yet.**", F-608 "so skipping it cannot unblock a
# downstream stall", F-446 "The predicate was never the blocker", and F-584 sets
# a criterion ("If a write site exists but never fires, that IS the root cause").
# Three of R3's six hits were the rule punishing the entry for saying the words
# while refusing the claim; a gate that does that is a gate nobody runs twice.
NOT_PRIORITY = re.compile(
    r"\b(not|never|no|cannot|can't|nor|if|would|should|could|must|unless)\b[^.]{0,30}$", re.I)
PRIORITY_DECLARED = PRIORITY.pattern.count("|") + 1  # the four briefed + two declared
VERDICT = re.compile(r"\b(refuted|upheld|weakened|reversed|confirmed|retracted|"
                     r"superseded|void|overturned|false|corrected)\b", re.I)
# R4: what makes a prior sentence a VERDICT ON AN INSTRUMENT rather than a
# description of it. "cumulative" and "reset" are here because the PHYS-CENSUS
# error was not a word the earlier entry used against itself -- it was the
# arithmetic, written down and not re-read. The tuple is the vocabulary: it is
# the list a session should extend, and R4's rebuttal test greps the first
# eight, so a new word is one edit, not two.
VERDICT_WORDS = ("stale", "lies", "lied", "lying", "blind", "unusable", "unreliable",
                 "broken", "falsified", "refuted", "cumulative", "reset", "poisoned",
                 "over-read", "overread", "retracted", "no longer", "lower bound")
VERDICT_WORD = re.compile(
    r"\b(" + "|".join(VERDICT_WORDS) + r")\b"
    r"|not (?:live|evidence|usable|a (?:live|real) )|never (?:compute|read|treat|use|cite)"
    r"|must not|success[- ]path|only on the success|capped\b", re.I)
# R4 fires on PROHIBITIONS, not on every adjective. With the broad vocabulary the
# rule flagged 333 of 593 entries, most of them nonsense -- the ledger is a
# 593-entry conversation about ~200 instruments, so almost any instrument has an
# earlier sentence somewhere near the word "broken". A gate that fires on 56% of
# the corpus is a gate that gets switched off. These are the words that
# actually say an instrument may not be read as what its name suggests; the broad
# set stays available behind --r4-any-verdict for auditing the vocabulary itself.
PROHIBITION = re.compile(
    r"\b(stale|lies|lied|lying|blind|unusable|unreliable|falsified|refuted|cumulative"
    r"|reset|poisoned|retracted|superseded)\b"
    r"|not (?:live|evidence|usable)|never (?:compute|read|treat|use|cite|as)"
    r"|must not|do not use|cannot be used|success[- ]path|only on the success"
    r"|capped\b|dead tracker|lower bound|not a (?:count|total|measurement)", re.I)
WATCH = re.compile(
    r"watch(point)?\b|heapsstore|heapstore|heapwin|heapext|hw watchpoint"
    r"|\bdr-?bp\b|\bwindow\b|saturated|breakpoint", re.I)
COUNT = re.compile(
    r"\b(\d{1,3}(?:,\d{3})+|\d+)\s+(?:consecutive\s+|guest\s+|u32\s+|dword\s+)*"
    r"(stores?|rows?|events?|entries|iterations?)\b"
    r"|\b(one|two|three|four|five|six|seven|eight|nine|ten|eleven|twelve|sixteen|"
    r"eighteen|twenty)\s+(?:consecutive\s+|guest\s+|u32\s+|dword\s+)*"
    r"(stores?|rows?|events?|entries)\b", re.I)
# A window's width, as the entry must state it. Deliberately narrow: an earlier
# draft accepted any "bytes" within 24 characters of any hex literal, which made
# F-630's "48 bytes per iteration (0x6f1e0...)" count as a stated window and
# silently passed the very rule that exists to catch it. A width is a quantity
# ATTACHED to a watch.
WIDTH = re.compile(
    r"\b(?:watch\w*|window)\b[^.]{0,90}?\b0x[0-9a-f]{3,8}\b"
    r"|\b0x[0-9a-f]{3,8}\b[^.]{0,40}?\b(?:byte|bytes|KB|KiB|MB)\b"
    r"|\b\d[\d,]*\s*(?:bytes?|KB|KiB|MB|MiB)\b[^.]{0,50}?\b(?:watch|window)\b"
    r"|\b(?:watch|window)\w*\b\s*(?:is|of|=|covers)?\s*\d[\d,]*\s*(?:bytes?|KB|MiB)\b",
    re.I)
# "at least", "a lower bound", "N of ~M" -- a fraction with TWO numbers. The
# first draft allowed a bare "37 of", which F-630 uses about park samples, and
# that is a share of samples, not a truncation of a watch.
LOWER_BOUND = re.compile(
    r"lower[- ]bound|\bat least\b|\bnot the (?:complete|total|whole)\b|\bnot a total\b"
    r"|\btruncat|\bsampled\b|\bsubset\b"
    r"|\b\d[\d,]*\s+of\s+(?:~?[\d][\d,.KMG]*\b|\d)\b", re.I)
LR = re.compile(r"\blr\s*=\s*(0x)?([0-9A-Fa-f]{8})\b")
FN_CALL = re.compile(r"ppc_xrefs\.py[^\n]{0,24}?\bfn\s+((?:0x)?[0-9A-Fa-f]{8}(?:\s+(?:0x)?[0-9A-Fa-f]{8})*)")
XREFS_TOOL = re.compile(r"ppc_xrefs\.py")
# "the function that issued", "the writer", "the caller", "the owner",
# "sub_821C6658". `inside` and `chain` were in the first draft and had to go:
# F-627 says "lr=82131AF8, which is *not* the call site inside sub_821F3988" and
# was graded for naming a function, which is the opposite of what it did.
ATTR = re.compile(r"\bfunction\b|\bcaller\b|\bowner\b|\bwriter\b|sub_[0-9A-Fa-f]{8}", re.I)
# ... and the sentence that says the opposite. F-631's own method note is
# "**A return address is not a function.** `lr=821C667C` was `sub_821C6658 + 0x24`",
# which contains "function" and "return address"; grading that as a violation is
# how a linter gets switched off.
NOT_ATTR = re.compile(
    r"not (?:a|the|an) (?:function|caller|owner|writer)|return address"
    r"|rather than a function|not a function", re.I)
TOOL_OUT = re.compile(r"(0x)?([0-9a-f]{8})\s*->\s*(sub_[0-9A-Fa-f]{8})\s*\+?(0x)?([0-9a-f]*)", re.I)

SOURCE_EXT = (".cpp", ".cc", ".c", ".h", ".hpp", ".inc", ".cxx", ".toml", ".py", ".bat", ".ps1")
DOC_EXT = (".md", ".log", ".map", ".txt", ".cfg", ".json", ".xml", ".xex", ".rpf")
ACT = "ACTOR_GAP"


class Finding:
    """One ledger entry: its id, where it starts, its text, its aliases.

    `when` is the date/time in the heading, parsed when present. It is what
    separates "this citation was wrong" from "this file changed under the
    citation": `src/` churns several times a day, and a rule that cannot tell
    those apart trains its readers to dismiss it. The project's own idiom for
    this is F-631's "heap.cpp mtime 18:34 > w654.log 18:14".
    """

    __slots__ = ("ids", "primary", "line", "end", "text", "head", "order", "when", "ceil")

    def __init__(self, ids, primary, line, end, text, head, order, when=None, ceil=None):
        self.ids, self.primary, self.line, self.end = ids, primary, line, end
        self.text, self.head, self.order = text, head, order
        self.when, self.ceil = when, ceil

    @property
    def short(self):
        t = re.sub(r"[*`#]", "", self.head).strip()
        return (t[:96] + " ...") if len(t) > 96 else t

    def rotted(self, p):
        """True if `p` was written after this entry could have been written, so a
        citation into it may have been correct at the time.

        `src/` is edited several times a day, and a rule that cannot tell "wrong
        citation" from "the file moved under the citation" grades every old
        finding as an error and gets switched off. R1's FAIL arm is therefore
        reserved for a cited file that has not changed since; a moved file
        reports UNVERIFIABLE, which `--strict` still fails on.

        The bracket matters because only 162 of 593 entries carry a clock in
        their heading. An undated entry is bracketed by its DATED NEIGHBOURS:
        the ledger is append-only, so it was written at or after the entry above
        it and at or before the entry below it. No excuse at all if neither
        neighbour is dated.
        """
        if p is None or self.when is None:
            return False
        try:
            return p.stat().st_mtime > (self.ceil if self.ceil else self.when)
        except OSError:
            return False


WHEN = re.compile(r"(\d{4})-(\d{2})-(\d{2})[ T](\d{1,2}):(\d{2})")
CLOCK = re.compile(r"\b(\d{1,2}):(\d{2}):(\d{2})\b")


def parse_when(head, body=""):
    """Heading timestamp, else the heading's DATE plus the entry's first log
    clock. F-630's heading carries a date and no time, and without the body's
    18:12:58 it would be treated as undated -- i.e. given no benefit of the doubt
    on a citation that the tree has since moved under."""
    m = WHEN.search(head)
    if m:
        try:
            return datetime(int(m.group(1)), int(m.group(2)), int(m.group(3)),
                            int(m.group(4)), int(m.group(5))).timestamp()
        except ValueError:
            return None
    d = re.search(r"(\d{4})-(\d{2})-(\d{2})", head)
    c = CLOCK.search(body)
    if d and c:
        try:
            return datetime(int(d.group(1)), int(d.group(2)), int(d.group(3)),
                            int(c.group(1)), int(c.group(2))).timestamp()
        except ValueError:
            return None
    return None


def split_findings(raw: str):
    """Return [(start_offset, heading_line_text)] for every entry, in doc order."""
    starts = []
    for rx in (ENTRY_LONG, ENTRY_BOLD):
        for m in rx.finditer(raw):
            starts.append((m.start(), raw[m.start():raw.find("\n", m.start())]))
    starts.sort()
    out, seen = [], set()
    for off, head in starts:
        if off in seen:
            continue
        seen.add(off)
        out.append((off, head))
    return out


def load_findings(path: Path):
    raw = path.read_text(encoding="utf-8", errors="replace")
    marks = split_findings(raw)
    lines = raw.splitlines()
    out = []
    for i, (off, head) in enumerate(marks):
        end = marks[i + 1][0] if i + 1 < len(marks) else len(raw)
        body = raw[off:end]
        ids = []
        for m in F_ID.findall(head):         # "### F-617/F-618" names two
            if f"F-{m}" not in ids:
                ids.append(f"F-{m}")
        if not ids:
            continue
        line = raw.count("\n", 0, off) + 1
        out.append(Finding(ids, ids[0], line, raw.count("\n", 0, end) + 1, body, head,
                           len(out), parse_when(head, body)))
    # Bracket every undated entry between its dated neighbours (see rotted()).
    for i, f in enumerate(out):
        if f.when is not None:
            continue
        floor = next((out[j].when for j in range(i - 1, -1, -1) if out[j].when), None)
        ceil = next((out[j].when for j in range(i + 1, len(out)) if out[j].when), None)
        if floor is not None and ceil is not None:
            f.when, f.ceil = floor, ceil
        elif floor is not None:
            f.when, f.ceil = floor, floor      # no upper bound: the file cannot be newer
    return out, lines


# ------------------------------------------------------------ source reading

class SourceIndex:
    """Line-addressable reader with a byte budget, because `generated/` is 424 MB.

    A file that fits the per-file cap is cached whole; a bigger one is read
    ONCE per distinct file with a streaming window that keeps only the lines a
    citation asked for. Memory is O(asked-for lines), not O(file).

    Citations in this ledger are mostly BARE filenames ("heap.cpp:920",
    "o1heap.c:306"), so a basename index is built once over the source trees.
    One match resolves; several are AMBIGUOUS and say so instead of guessing,
    because picking the first is how a wrong file:line becomes load-bearing --
    `ppc_recomp.14.cpp` exists in BOTH generated/ppc/ and generated/ppc_xenon/,
    and the two are not the same code.
    """

    CAP = 4 << 20
    BUDGET = 48 << 20
    TREES = ("src", "generated", "config", "tools", "docs")

    def __init__(self, root: Path):
        self.root = root
        self._lines = {}
        self._bytes = 0
        self._base = None
        self._anywhere = {}

    def by_basename(self, rel):
        if "/" in rel.replace("\\", "/"):
            return [rel]
        if self._base is None:
            idx = {}
            for t in self.TREES:
                d = self.root / t
                if not d.is_dir():
                    continue
                for p in d.rglob("*"):
                    if p.is_file() and p.suffix.lower() in SOURCE_EXT:
                        idx.setdefault(p.name, []).append(p.relative_to(self.root).as_posix())
            self._base = {k: sorted(v) for k, v in idx.items()}
        return self._base.get(rel, [])

    def path(self, rel: str):
        p = (self.root / rel.replace("\\", "/")).resolve()
        try:
            p.relative_to(self.root)
        except ValueError:
            return None          # a citation that climbs out of the repo
        return p

    def resolve(self, rel):
        """(path, note) -- note is non-empty when the citation is not usable."""
        p = self.path(rel)
        if p is not None and p.is_file():
            return p, ""
        cands = self.by_basename(rel)
        if len(cands) == 1:
            return self.path(cands[0]), ""
        if len(cands) > 1:
            return None, ("AMBIGUOUS-BASENAME: " + ", ".join(cands[:4])
                          + (f" (+{len(cands) - 4} more)" if len(cands) > 4 else ""))
        return None, "not in the tree"

    def nlines(self, p):
        """Line count, or None if too big to be worth counting."""
        if p is None or not p.is_file():
            return None
        try:
            if p.stat().st_size > self.CAP:
                return None
        except OSError:
            return None
        return len(self._all(p))

    def _all(self, p):
        k = str(p)
        if k not in self._lines:
            txt = p.read_text(encoding="utf-8", errors="replace").splitlines()
            self._lines[k] = txt
            self._bytes += sum(len(x) for x in txt)
            while self._bytes > self.BUDGET and len(self._lines) > 1:
                kk = max(self._lines, key=lambda z: len(self._lines[z]))
                self._bytes -= sum(len(x) for x in self._lines[kk])
                del self._lines[kk]
        return self._lines[k]

    def window(self, p, lo, hi):
        """{lineno: text} for lo..hi inclusive, or {} if the file is absent."""
        if p is None or not p.is_file():
            return {}
        hi = min(hi, lo + 400)               # a range is a range, not a whole file
        try:
            if p.stat().st_size <= self.CAP:
                txt = self._all(p)
                return {i + 1: txt[i] for i in range(lo - 1, min(hi, len(txt))) if lo - 1 <= i}
        except OSError:
            return {}
        return self._stream_window(p, lo, hi)

    def _stream_window(self, p, lo, hi):
        want = {}
        with p.open("r", encoding="utf-8", errors="replace") as fh:
            for n, line in enumerate(fh, 1):
                if n >= lo:
                    want[n] = line.rstrip("\n")
                    if n >= hi:
                        break
        return want

    def find_anywhere(self, p, token):
        """1-based line of `token` anywhere in the file, or None. One pass."""
        key = (str(p), token)
        if key in self._anywhere:
            return self._anywhere[key]
        got = None
        try:
            if p.stat().st_size <= self.CAP:
                for n, line in enumerate(self._all(p), 1):
                    if token in line:
                        got = n
                        break
            else:
                with p.open("r", encoding="utf-8", errors="replace") as fh:
                    for n, line in enumerate(fh, 1):
                        if token in line:
                            got = n
                            break
        except OSError:
            got = None
        self._anywhere[key] = got
        return got

    def search(self, p, token, lo, hi, pad):
        """1-based line of `token` within [lo-pad, hi+pad], or None."""
        a, b = max(1, lo - pad), hi + pad
        w = self.window(p, a, b)
        for n in sorted(w):
            if token in w[n]:
                return n
        return None


# --------------------------------------------------------------- R2: the tool

class Xref:
    """Runs `tools/ppc_xrefs.py fn` for real, ONCE for the whole ledger.

    ppc_xrefs.py reads build/cache/mcla_pe.bin relative to CWD, so the
    subprocess runs with cwd=REPO; without that it exits 1 on a missing image
    and the rule would silently grade every lr as UNVERIFIABLE. Per-entry
    invocations were 155 separate spawns (46 s of a 59 s run) for an answer that
    is a pure function of the address, so every address in the pass is collected
    first and resolved in one `fn a b c ...` call -- the tool takes a list.
    """

    def __init__(self, enabled=True):
        self.enabled = enabled
        self.cache = {}
        self.runs = 0
        self.why = None
        self._bulk = None

    def prefetch(self, addrs):
        addrs = sorted(set(addrs))
        if not addrs or self._bulk is not None or not self.enabled:
            return
        self._bulk = self._spawn(addrs)

    def _spawn(self, addrs):
        self.runs += 1
        argv = [a if isinstance(a, str) else "0x%08X" % a for a in addrs]
        try:
            cp = subprocess.run([sys.executable, str(XPREFS), "fn", *argv],
                                cwd=str(REPO), capture_output=True, text=True, timeout=300)
        except (OSError, subprocess.SubprocessError) as e:
            return None, f"spawn failed: {e}"
        if cp.returncode != 0:
            tail = (cp.stdout + cp.stderr).strip().splitlines()
            return None, (tail[-1] if tail else f"exit {cp.returncode}")
        res = {}
        for line in cp.stdout.splitlines():
            m = TOOL_OUT.search(line)
            if m:
                res[int(m.group(2), 16)] = (m.group(3),
                                            int((m.group(4) or "") + (m.group(5) or "0"), 16))
        return res, None

    def fn(self, addrs):
        key = tuple(sorted(addrs))
        if key in self.cache:
            return self.cache[key]
        if not self.enabled:
            self.cache[key] = (None, "disabled")
            return self.cache[key]
        if not XPREFS.is_file():
            self.cache[key] = (None, "tools/ppc_xrefs.py missing")
            return self.cache[key]
        if self._bulk is not None:
            res, why = self._bulk
            if res is None:
                self.cache[key] = (None, why)
            else:
                self.cache[key] = ({a: res[a] for a in key if a in res}, None)
            return self.cache[key]
        res, why = self._spawn(key)
        self.cache[key] = (res, why)
        return self.cache[key]


# ------------------------------------------------------------------- helpers

def para(t):
    return re.split(r"\n\s*\n", t)


def snippet(s, n=118):
    s = re.sub(r"\s+", " ", s).strip()
    return s if len(s) <= n else s[:n - 3] + "..."


def row(sev, code, msg, snip=""):
    """One graded line: (severity, code, detail). The offending text is part of
    the detail because a verdict without the sentence it is about is useless."""
    return (sev, code, f"{msg}  |  {snippet(snip)}" if snip else msg)


def instrument_names(text):
    names = set()
    for m in INSTRUMENT.finditer(text):
        n = m.group(1)
        if n in INSTRUMENT_SKIP or n.startswith("F-") or len(n) > 34:
            continue
        names.add(n)
    for m in FIELD_INSTRUMENT.finditer(text):
        if m.group(1) not in FIELD_SKIP and len(m.group(1)) >= 4:
            names.add(m.group(1) + "=")
    return names


def citations(text):
    """[(path, lo, hi, sentence)] for every `file.ext:N[-M]` in the entry.

    A bare ``:NNN`` is a carry-forward the house style uses constantly
    ("registered at `:534`"), so it inherits the last path named in the same
    paragraph. Dropping that form would leave most citations unchecked.
    """
    out = []
    for p in para(text):
        last = None
        for chunk in re.split(r"(?<=[.;])\s+|\n", p):
            for m in CITE.finditer(chunk):
                s = m.group(1)
                nums = re.findall(r":(\d+)(?:-(\d+))?", s)
                lo = int(nums[0][0])
                hi = int(nums[0][1] or nums[0][0])
                last = re.sub(r"(:\d+(?:-\d+)?)+$", "", s)   # strip the :N tail
                out.append((last, lo, hi, chunk))
            for m in BARE_COLON.finditer(chunk):
                if last:
                    out.append((last, int(m.group(1)), int(m.group(1)), chunk))
    return out


def nearby_tokens(chunk):
    """Tokens in the sentence that could be the thing the citation produces.

    The SEARCH key of a `field=` instrument is the bare field name: the source
    prints `total={:.1f}MB`, so looking for the literal `total=` would miss the
    very line that emits it -- a linter that fails the correct citation is worse
    than no linter, because the author learns to ignore it.
    """
    toks = set()
    for m in INSTRUMENT.finditer(chunk):
        toks.add(m.group(1))
    for m in FIELD_INSTRUMENT.finditer(chunk):
        toks.add(m.group(1))
    toks.update(re.findall(r"\bsub_[0-9A-Fa-f]{8}\b", chunk))
    toks.update(re.findall(r"`?\b([A-Za-z_][A-Za-z0-9_]{4,})\(" , chunk))  # call names
    toks.update(re.findall(r"\b([a-z][a-z0-9_]{2,15})=`?\d", chunk))      # field=rvalue
    toks.discard("build")
    return {t for t in toks if len(t) >= 4}


# --------------------------------------------------------------------- rules

def rule1(f, idx, deep_logs):
    """Producer-before-reasoning. FAIL / UNVERIFIABLE, never a silent pass."""
    out, checked = [], 0
    cites = citations(f.text)
    exts_ok = 0
    for rel, lo, hi, chunk in cites:
        ext = ("." + rel.rsplit(".", 1)[-1]) if "." in rel else ""
        if ext in DOC_EXT or (ext == ".log" and not deep_logs):
            continue
        if ext not in SOURCE_EXT:
            continue
        exts_ok += 1
        p, note = idx.resolve(rel)
        if p is None:
            out.append(row("UNVERIFIABLE", "MISSING-FILE",
                           f"{rel}:{lo} -- {note}", chunk))
            continue
        rot = f.rotted(p)
        n = idx.nlines(p)
        if n is not None and lo > n:
            out.append(row("UNVERIFIABLE" if rot else "FAIL", "RANGE-OF-FILE",
                           f"{rel}:{lo} but {rel} has {n} lines"
                           + (f"; {rel} was edited after this entry, so the line may have "
                              f"existed when it was written" if rot else ""), chunk))
            continue
        toks = nearby_tokens(chunk)
        hit = None
        for t in sorted(toks, key=len, reverse=True):
            if idx.search(p, t, lo, hi, 0) is not None:
                hit = (t, lo)
                break
        if hit:
            checked += 1
            continue
        # Not in the range. Look +-40: that is the "the file moved under us"
        # zone, which is a fact about the tree, not about the finding.
        near = None
        for t in sorted(toks, key=len, reverse=True)[:6]:
            got = idx.search(p, t, lo, hi, 40)
            if got is not None:
                near = (t, got)
                break
        if near:
            out.append(row("UNVERIFIABLE", "PRODUCER-DRIFT",
                           f"{rel}:{lo}-{hi} misses `{near[0]}`; it is at {rel}:{near[1]}"
                           + (" (the file also moved since this entry)" if rot else ""),
                           chunk))
        elif toks:
            listed = ", ".join("`" + t + "`" for t in sorted(toks, key=len, reverse=True)[:4])
            if rot:
                # Say where it is NOW, so re-citing is a copy-paste, not a hunt.
                hint = ""
                for t in sorted(toks, key=len, reverse=True)[:2]:
                    got = idx.find_anywhere(p, t)
                    if got:
                        hint = f"; `{t}` is at {rel}:{got} today"
                        break
                out.append(row("UNVERIFIABLE", "PRODUCER-ROTTED",
                               f"{rel}:{lo}-{hi} contains none of {listed}{hint}; {rel} was "
                               f"edited {rot_gap(f, p)} AFTER this entry, so re-cite the "
                               f"current line (a doc line is a hypothesis -- AGENTS.md)",
                               chunk))
            else:
                out.append(row("FAIL", "PRODUCER-MISSING",
                               f"{rel}:{lo}-{hi} contains none of {listed}, and {rel} has "
                               f"not changed since this entry was written", chunk))
    # A number with no citation in its own paragraph is UNVERIFIABLE, not a
    # pass: the rule says the EMITTING statement must carry file:line.
    for p in para(f.text):
        if not COUNT.search(p) and not re.search(r"\b\d[\d,.]*\s*(MB|GB|KB|%|rows?|stores?)\b", p):
            continue
        has = CITE.search(p)
        if has is None:
            out.append(row("UNVERIFIABLE", "NO-CITATION",
                           "a number is reasoned from with no file:line in its paragraph", p))
    out += stale_artifact(f, idx)
    return out, exts_ok, len(cites)


# The project resolves a HOST address out of `build/mcla.map`, and the house
# rule for that tool is "pass the map from the SAME build as the log" (AGENTS.md
# tools table: the control is a known symbol resolving at +0x0). A relink
# rewrites the map, so an artifact newer than the log it explains cannot be the
# producer of that log's addresses -- F-627/F-628 resolved `rawrip` out of a map
# that had been relinked since `w654`, and the ledger says so itself 40 lines
# earlier. mtime is a proxy for "which link", and the proxy is exact enough:
# both files are written by the same build the entry names.
ARTIFACT = re.compile(r"\b(build/[\w./-]+\.(?:map|exe|pdb|dll))\b")
# A log is named with or without its `build/` prefix, and usually in the entry's
# HEADING ("soak `w654.log` 120 s") while the map is named mid-sentence, so the
# pairing is done per ENTRY, not per sentence. Chunk scope found nothing on
# F-627/F-628, which is the case the rule exists for.
LOGREF = re.compile(r"\b(?:build/)?((?:w|smoke_|boot_)?[\w]*\d[\w]*\.log)\b")
SAME_BUILD = re.compile(r"same (?:build|exe|link)|= the same|map \d\d?:\d\d:\d\d", re.I)


def stale_artifact(f, idx):
    out = []
    arts = ARTIFACT.findall(f.text)
    logs = [n if n.startswith("build/") else "build/" + n for n in LOGREF.findall(f.text)]
    if not arts or not logs:
        return out
    for a in dict.fromkeys(arts):
        pa = idx.path(a)
        if pa is None or not pa.is_file():
            continue
        for lg in dict.fromkeys(logs):
            pl = idx.path(lg)
            if pl is None or not pl.is_file():
                continue
            ta, tl = pa.stat().st_mtime, pl.stat().st_mtime
            if ta > tl and not SAME_BUILD.search(f.text):
                out.append(row("FAIL", "STALE-ARTIFACT",
                               f"{a} was written {ta - tl:.0f}s after {lg} -- the project's own "
                               f"rule for host_rva_resolve.py is the map from the SAME build "
                               f"as the log (AGENTS.md tools table), and this entry does not "
                               f"claim one", ""))
    return out[:2]


def rot_gap(f, p):
    """How long after this entry could have been written the file was touched."""
    try:
        d = p.stat().st_mtime - (f.ceil or f.when)
    except (OSError, TypeError):
        return "?"
    for unit, div in (("d", 86400), ("h", 3600), ("m", 60)):
        if d >= div:
            return f"{int(d / div)}{unit}"
    return f"{int(d)}s"


def rule2(f, xr, attributed_only):
    out = []
    lrs = [(int(m.group(2), 16), m.group(0), _sentence(f.text, m.start()))
           for m in LR.finditer(f.text)]
    if not lrs:
        return out, 0
    invoked = set()
    for m in FN_CALL.finditer(f.text):
        for a in re.findall(r"(?:0x)?([0-9A-Fa-f]{8})", m.group(1)):
            invoked.add(int(a, 16))
    if not invoked:
        addrs = sorted({a for a, _, _ in lrs})
        res, why = xr.fn(addrs)
        if XREFS_TOOL.search(f.text):
            # a ppc_xrefs.py line is cited but no `fn <VA>`: the tool is still
            # run (the comparison has to be real), and the missing invocation
            # itself is UNVERIFIABLE rather than FAIL -- the author may have
            # resolved it in a session whose command line is not in the ledger.
            out += _compare(res, why, lrs, "UNVERIFIABLE", attributed_only)
            return out, len(lrs)
        res, why = xr.fn(addrs)
        out += _compare(res, why, lrs, "FAIL", attributed_only)
        # The summary row is the broad reading. Under --attributed-only it needs
        # an attributed lr to exist at all, or every entry that quotes a log row
        # would fail and the narrow flag would measure nothing.
        hits = [s for _, _, s in lrs if not attributed_only or
                (ATTR.search(s) and not NOT_ATTR.search(s))]
        if hits:
            out.append(row("FAIL", "LR-UNRESOLVED",
                           f"{len(lrs)} `lr=` in this entry, none of them resolved here; the "
                           f"project's own rule is `tools/ppc_xrefs.py fn <VA>` in the SAME "
                           f"entry", hits[0]))
        return out, len(lrs)
    res, why = xr.fn(sorted(invoked))
    out += _compare(res, why, lrs, "FAIL", attributed_only)
    return out, len(lrs)


def _window(text, pos, n=200):
    """A char window around a hit. The ledger hard-wraps at ~120 columns, so a
    LINE-scoped sentence cut the instrument name away from the verdict word that
    judged it ("the PHYS-CENSUS latch" on one line, "CUMULATIVE total" on the
    next) and the index came back empty for the exact case it was built for."""
    return text[max(0, pos - n): pos + n]


def _sentence(text, pos):
    a = max(0, text.rfind("\n", 0, pos) + 1)
    b = text.find("\n", pos)
    b = len(text) if b < 0 else b
    return text[a:b]


def _compare(res, why, lrs, sev, attributed_only):
    """Grade one lr against what ppc_xrefs.py ACTUALLY printed for it."""
    out = []
    for addr, raw, sent in lrs:
        attributed = bool(ATTR.search(sent)) and not NOT_ATTR.search(sent)
        if attributed_only and not attributed:
            continue
        if res is None:
            out.append(row("UNVERIFIABLE", "LR-NOT-RUN",
                           f"{raw}: ppc_xrefs.py fn did not run ({why})", sent))
        elif addr not in res:
            out.append(row(sev, "LR-NOT-IN-INVOCATION",
                           f"{raw} is not among the addresses this entry's `fn` names", sent))
        else:
            name, off = res[addr]
            if off == 0:
                continue                  # a real function start: the claim agrees
            if attributed:
                out.append(row("FAIL", "LR-RETURN-ADDRESS",
                               f"{raw} = {name} +0x{off:x} per ppc_xrefs.py fn, and the "
                               f"sentence names it a function/owner", sent))
            else:
                out.append(row("UNVERIFIABLE", "LR-OFFSET",
                               f"{raw} = {name} +0x{off:x} per ppc_xrefs.py fn -- a return "
                               f"address; the sentence does not name it a function", sent))
    return out


def rule3(f, later):
    out = []
    # A priority hit whose window names a DIFFERENT finding belongs to that
    # finding: F-631 quotes F-630's "outranks everything" framing in order to
    # demolish it, and must not be made to answer for the priority claim it just
    # refuted. Every hit is attributed before any of them can trigger the rule.
    mine = []
    for m in PRIORITY.finditer(f.text):
        lead = f.text[max(0, m.start() - 24): m.start()]
        if F_ID.search(lead):
            continue
        if NOT_PRIORITY.search(f.text[max(0, m.start() - 60): m.start()]):
            continue
        w = _window(f.text, m.start(), 60)
        if [i for i in F_ID.findall(w) for i in (f"F-{i}",) if i not in f.ids]:
            continue
        mine.append(m)
    if not mine:
        return out
    trig = snippet(_window(f.text, mine[0].start(), 90))
    rulings = []
    for g in later:
        if not any(i in g.text or i in g.head for i in f.ids):
            continue
        if VERDICT.search(g.text[:4000] + g.head):
            rulings.append(g)
    if rulings:
        out.append(("ok", "REFUTED-OR-UPHELD",
                    f"{', '.join(g.primary for g in rulings[:4])} rules on it "
                    f"({ACT}: someone ruled, not who)"))
    else:
        out.append(row("FAIL", "UNREFUTED",
                       f"priority language ({trig}) with no later entry citing "
                       f"{'/'.join(f.ids[:2])} and carrying a verdict", f.head))
    return out


def _para_span(text, pos):
    """(start, end) of the paragraph around pos. The ledger hard-wraps at ~120
    columns, so a CHAR window either cuts an instrument away from the word that
    judged it or reaches into the next paragraph; the paragraph is the unit the
    author actually wrote in."""
    a = text.rfind("\n\n", 0, pos)
    a = 0 if a < 0 else a + 2
    b = text.find("\n\n", pos)
    return a, (len(text) if b < 0 else b)


# A line that is DATA, not an author's verdict. The ledger embeds raw soak rows
# in fences, and those rows carry the prohibition words by accident --
# "selftests MUST be 1, else this probe is blind" is the probe's own help text,
# not a verdict on the census, and it was the single largest source of R4 hits
# (32 of them, all PHYS-CENSUS log rows).
LOGROW = re.compile(r"\[(info|warning|error|critical|debug)\]")


def verdict_hits(s, limit=200, rx=VERDICT_WORD):
    """True if `s` carries a verdict word that is NOT negated, within `limit`
    characters.

    F-630 satisfied the first draft of R4 by accident, twice: "the PHYS-CENSUS
    ... (not blind)" is a rebuttal OF a blindness charge, and "destroyed/poisoned
    allocator" 250 characters later is its own conclusion, not a verdict on the
    counter. So: a negated verdict word is skipped, the word has to be CLOSE --
    the ledger hard-wraps, 200 characters is about one and a half lines, which is
    where a charge and its verdict sit -- and a word inside a LOG ROW is data.
    """
    for m in rx.finditer(s, 0, limit):
        lead = s[max(0, m.start() - 12): m.start()].lower()
        if re.search(r"(not|never|n't)\s+$", lead):
            continue
        ls = s.rfind("\n", 0, m.start()) + 1
        if LOGROW.search(s[ls: ls + 200]):
            continue
        return True
    return False


def _in_log_row(text, pos):
    """True if `pos` sits in pasted soak output, including a WRAPPED
    continuation: a raw row is one long line that the ledger's own hard-wrap
    splits, so `[warning]` can be four lines above the field."""
    ls = text.rfind("\n", 0, pos) + 1
    for back in range(3):
        a = text.rfind("\n", 0, max(0, ls - 1)) + 1
        if LOGROW.search(text[a: a + 200]):
            return True
        if ls == 0:
            break
        ls = a
    return False


def indicts(text, name, rx=VERDICT_WORD):
    """Does a PROSE paragraph naming `name` indict it?

    The line the name sits on must not be log output. A fence of raw soak rows
    mentions every marker in the tree and carries the prohibition words in the
    probes' own help text ("selftests MUST be 1, else this probe is blind"), so
    without this the index indicts instruments out of pasted data -- which is
    where 32 of the first R4 hits came from, all of them PHYS-CENSUS log rows.
    """
    for m in re.finditer(r"(?<![\w-])" + re.escape(name), text):
        if _in_log_row(text, m.start()):
            continue
        _, pend = _para_span(text, m.end())
        if verdict_hits(text[m.end(): pend], rx=rx):
            a = max(0, text.rfind("\n", 0, m.start()) + 1)
            b = text.find("\n", m.end())
            b2 = text.find("\n", b + 1) if b > 0 else -1
            return snippet(text[a: b2 if b2 > 0 else (b if b > 0 else len(text))])
    return None


def build_verdict_index(findings, rx=PROHIBITION):
    """instrument -> [(entry order, finding, the text that indicted it)].

    A verdict is a verdict word in the instrument's own PARAGRAPH, at or after
    the name. Direction matters: the charge is written after the thing charged
    -- "the PHYS-CENSUS latch ... `bytes` is the CUMULATIVE total" -- whereas a
    word 200 characters earlier belongs to the previous sentence.
    """
    idx = {}
    for f in findings:
        for name in instrument_names(f.text):
            shown = indicts(f.text, name, rx)
            if shown:
                idx.setdefault(name, []).append((f.order, f, shown))
    return idx


def rule4(f, vind, r4_any=False, window=60):
    """An instrument already indicted by an earlier entry must be re-checked.

    The enforceable form is a CITATION: the new entry has to name the entry that
    ruled on the instrument, or repeat the verdict in its own paragraph. The
    first draft accepted a verdict word anywhere in the next 140 characters,
    which F-630 satisfied by accident -- "selftests=1 (not blind)" is 135
    characters after `PHYS-CENSUS` and is the opposite of a verdict on it.

    `window` is the RECENCY bound, and it is the part the rule needs: the whole
    ledger is a 593-entry conversation about ~300 shared instruments, so "some
    earlier entry said something bad about this name" is a property of the
    corpus, not of the finding -- with no bound the rule fires on half the
    ledger. The failure it exists for is "reused a field the day's own findings
    had just indicted", so the default bound is 60 entries, about one day of
    work at this ledger's rate. `--r4-window 0` is the unbounded form.
    """
    out = []
    for name in sorted(instrument_names(f.text)):
        prior = [(o, g, s) for (o, g, s) in vind.get(name, []) if o < f.order]
        if window:
            near = [(o, g, s) for (o, g, s) in prior if f.order - o <= window]
            if near:
                prior = near
        if not prior:
            continue
        # Cite ANY entry that ruled on the instrument, not only the newest:
        # `prior[-1]` alone let an unrelated id in the same paragraph
        # discharge the obligation by accident.
        if any(i in f.text for g in {gg.primary: gg for _, gg, _ in prior}.values() for i in g.ids):
            continue
        # The instrument must be USED AS A MEASUREMENT here, not merely named.
        # Without this the rule fires on every entry that lists a marker in a
        # gate or a work item -- instruments are this ledger's shared
        # vocabulary, and a rule that fires on the vocabulary is noise. The
        # F-630 shape is "reads `total=46.0MB`", i.e. a number out of the field.
        reads = False
        for m in re.finditer(r"(?<![\w-])" + re.escape(name), f.text):
            if _in_log_row(f.text, m.start()):
                continue                      # pasted log data is not a use
            _, pend = _para_span(f.text, m.end())
            if re.search(r"\d", f.text[m.end(): pend]):
                reads = True
                break
        if not reads:
            continue
        if indicts(f.text, name, PROHIBITION if not r4_any else VERDICT_WORD):
            continue
        o, g, s = prior[-1]
        earlier = ", ".join(sorted({gg.primary for _, gg, _ in prior[:-1]}))
        out.append(("FAIL", "CONTRADICTED",
                    f"`{name}` was already ruled on by {g.primary}"
                    + (f" (and {earlier})" if earlier else "")
                    + f" -- {s} -- and this entry neither cites them nor repeats that "
                      f"verdict next to the name"))
    return out


def rule5(f):
    """A count off a bounded watch, with the window stated in the SAME paragraph.

    Paragraph scope, not entry scope: an unrelated "5.2 MB" elsewhere in a long
    entry must not launder a count taken through a 576-byte window.
    """
    out = []
    for p in para(f.text):
        hits = [c for c in re.split(r"(?<=[.;])\s+|\n", p)
                if COUNT.search(c) and WATCH.search(c)]
        if not hits:
            continue
        if WIDTH.search(p) or LOWER_BOUND.search(p):
            continue
        for c in hits[:2]:
            out.append(row("FAIL", "WINDOW-UNSTATED",
                           "a count attributed to a bounded watch, with no window width and "
                           "no LOWER-BOUND label in the same paragraph", c))
    return out


# ---------------------------------------------------------------------- main

def grade(f, findings, idx, xr, vind, deep_logs, attributed_only, r4_any=False, r4_window=60):
    later = [g for g in findings if g.order > f.order]
    r1, nsrc, ncite = rule1(f, idx, deep_logs)
    r2, nlr = rule2(f, xr, attributed_only)
    r3 = rule3(f, later)
    r4 = rule4(f, vind, r4_any, r4_window)
    r5 = rule5(f)
    applies = []
    if r1 or (ncite == 0 and re.search(r"\d", f.text)):
        applies.append(1)
    if nlr:
        applies.append(2)
    if PRIORITY.search(f.text):
        applies.append(3)
    if r4 or any(n in vind for n in instrument_names(f.text)):
        applies.append(4)
    if r5:
        applies.append(5)
    if not applies:
        applies = [1]
    rows = {1: r1, 2: r2, 3: r3, 4: r4, 5: r5}
    return applies, rows, (nsrc, ncite, nlr)


def report(f, applies, rows, meta, show_all, width):
    nsrc, ncite, nlr = meta
    bad = [(r, s, c, d) for r in applies for (s, c, d) in rows[r] if s == "FAIL"]
    unver = [(r, s, c, d) for r in applies for (s, c, d) in rows[r] if s == "UNVERIFIABLE"]
    verdict = "FAIL" if bad else ("UNVERIFIABLE" if unver else "PASS")
    if not show_all and verdict == "PASS":
        return None
    head = f"{f.primary:<7} {verdict:<13} rules {','.join(str(r) for r in applies):<9} " \
           f"src-cites {nsrc:<3} lr {nlr:<3} {f.head[3:][:width] if f.head.startswith('###') else f.head[:width]}"
    out = [head]
    for r in applies:
        got = rows[r]
        if not got:
            out.append(f"   R{r} ok      -")
            continue
        # one line per rule, with the worst finding of that rule first
        got = sorted(got, key=lambda x: (x[0] != "FAIL", x[1]))
        s, c, d = got[0]
        extra = f"  (+{len(got)-1} more)" if len(got) > 1 else ""
        out.append(f"   R{r} {s:<12} {c}{extra}")
        if d:
            out.append(f"        {d}")
        for s2, c2, d2 in got[1:3]:
            out.append(f"        {s2}: {c2}  |  {d2}")
    return "\n".join(out), verdict


def lint(ledger: Path, sel, as_of, deep_logs, attributed_only, show_all, width, strict=False,
         r4_any=False, r4_window=60):
    everything, _ = load_findings(ledger)
    findings = everything
    if as_of:
        cut = [f for f in findings if f.primary == as_of]
        if not cut:
            print(f"claim_lint: no entry {as_of}", file=sys.stderr)
            return 2
        # Up to AND INCLUDING the entry: "grade F-630 as of the moment it was
        # written", i.e. with no later entry available to have refuted it. That
        # is the question the review asked, and it cannot be asked against a
        # ledger that already contains the answer.
        findings = findings[: cut[0].order + 1]
        everything = findings
    if sel:
        want = sel.upper()
        findings = [f for f in findings if any(i == want or i.startswith(want)
                                              for i in f.ids) or want in f.head]
    idx = SourceIndex(REPO)
    xr = Xref()
    # The verdict index and the "later entry" set are built from the WHOLE
    # ledger, not from the selection: a prior verdict is history, and selecting
    # one entry must not delete the evidence that condemns it (the first version
    # graded F-630 clean under `claim_lint.py F-630` for exactly that reason).
    vind = build_verdict_index(everything,
                               VERDICT_WORD if r4_any else PROHIBITION)
    tally = {r: {"FAIL": 0, "UNVERIFIABLE": 0, "ok": 0, "PASS": 0} for r in range(1, 6)}
    rejects, unv, shown = 0, 0, 0
    codes = Counter()
    # One tool run for every address the whole pass will ask about.
    need = set()
    for f in findings:
        need.update(int(m.group(2), 16) for m in LR.finditer(f.text))
        for m in FN_CALL.finditer(f.text):
            need.update(int(a, 16) for a in re.findall(r"(?:0x)?([0-9A-Fa-f]{8})", m.group(1)))
    xr.prefetch(need)
    for f in findings:
        applies, rows, meta = grade(f, everything, idx, xr, vind, deep_logs,
                                    attributed_only, r4_any, r4_window)
        # Per-rule verdicts are that RULE's own rows. The first version tallied
        # the entry-level verdict into every rule that applied, so R1 appeared
        # to fail 361 entries off 117 bad citations and the report was a lie by
        # aggregation.
        for a in applies:
            sevs = {s for (s, _, _) in rows[a]}
            if "FAIL" in sevs:
                tally[a]["FAIL"] += 1
            elif "UNVERIFIABLE" in sevs:
                tally[a]["UNVERIFIABLE"] += 1
            else:
                tally[a]["ok"] += 1
            for (s, c, _) in rows[a]:
                if s != "ok":
                    codes[(a, s, c)] += 1
        r = report(f, applies, rows, meta, show_all, width)
        if r is None:
            continue
        text, verdict = r
        print(text)
        shown += 1
        if verdict == "FAIL":
            rejects += 1
        elif verdict == "UNVERIFIABLE":
            unv += 1
    n = len(findings)
    print()
    print("=" * 78)
    print(f"entries linted: {n}   file: {ledger.relative_to(REPO) if ledger.is_relative_to(REPO) else ledger}")
    for r_, name in ((1, "producer-before-reasoning"), (2, "lr-needs-fn-resolution"),
                     (3, "priority-needs-refutation"), (4, "instrument-vs-prior-verdict"),
                     (5, "window-count-needs-width")):
        print(f"  R{r_} {name:<31} FAIL {tally[r_]['FAIL']:>3}   "
              f"UNV {tally[r_]['UNVERIFIABLE']:>3}   clean {tally[r_]['ok']:>3}"
              + ("  (attributed lrs only)" if r_ == 2 and attributed_only else ""))
    print("  codes: " + ", ".join(f"R{a}/{c}={k}" for (a, _, c), k in codes.most_common(12)))
    print(f"  R4 vocabulary: {'ANY verdict word' if r4_any else 'prohibitions only'}, "
          + (f"lookback {r4_window} entries" if r4_window else "UNBOUNDED lookback"))
    print(f"REJECTED {rejects} of {n} entries   UNVERIFIABLE-ONLY {unv}"
          f"   ppc_xrefs.py fn invocations run: {xr.runs}")
    print(f"not checked: {ACT} -- 'a different actor' is not a field in this ledger, so R3 "
          f"verifies that SOMEONE ruled, not who.")
    return 1 if (rejects or (strict and unv)) else 0


# ----------------------------------------------------------------- selftest

def _emitter_line():
    """The line that PRINTS `PHYS-CENSUS`, read from the tree.

    The R1 control case must not hard-code it: `src/kernel/imports.cpp` was
    edited at 20:04 on 09-28 and `s_totalBytes` moved 3199 -> 3470, which turned
    the control into a second FAIL and would have taught a reader that a
    correct citation gets flagged. A control that depends on a moving line is a
    broken control, and the R1 rule's own docstring says the same thing.
    """
    idx = SourceIndex(REPO)
    p, _ = idx.resolve("src/kernel/imports.cpp")
    n = idx.find_anywhere(p, "PHYS-CENSUS") or 1
    m = idx.find_anywhere(p, "OB-DEREF") or max(1, n - 800)
    return n, m


_EMIT, _WRONG = _emitter_line()

SYNTH = {
    "R1": [
        ("FAIL", "PRODUCER-MISSING", dict(body=f"F-900 (test) - reads a census as occupancy.\n\n"
                           f"The `PHYS-CENSUS` field is cited at src/kernel/imports.cpp:{_WRONG} "
                           f"and the live total climbs to 46.0 MB.\n")),
        ("PASS", "", dict(body=f"F-901 (test) - cites the real producer.\n\n"
                           f"`PHYS-CENSUS total=` is emitted at src/kernel/imports.cpp:{_EMIT} "
                           f"and is cumulative requested bytes, so 46.0 MB is not occupancy.\n")),
    ],
    "R2": [
        ("FAIL", "LR-RETURN-ADDRESS", dict(body="F-902 (test) - names an lr as the function.\n\n"
                           "The writer is `lr=821C667C`, which is the function that issued the "
                           "request, per `ppc_xrefs.py fn 0x821C667C`.\n")),
        ("FAIL", "LR-UNRESOLVED", dict(body="F-903 (test) - no resolution at all.\n\n"
                           "The writer is `lr=821C667C` and it issued the request.\n")),
        ("PASS", "", dict(body="F-904 (test) - resolved correctly.\n\n"
                           "`tools/ppc_xrefs.py fn 0x821C667C` resolves to `sub_821C6658 +0x24`, "
                           "a return address inside a memset, not a function.\n")),
    ],
    "R3": [
        ("FAIL", "UNREFUTED", dict(head="### F-905 (test) - **ROOT CAUSE OF THE BOOT: the wedge.** "
                           "This outranks every other open item.\n\nClaim.\n",
                      body="### F-905 (test) - **ROOT CAUSE OF THE BOOT: the wedge.** "
                           "This outranks every other open item.\n\nClaim.\n")),
        ("PASS", "", dict(head="### F-906 (test) - **ROOT CAUSE: the wedge, outranks all.**\n\nClaim.\n",
                      body="### F-906 (test) - **ROOT CAUSE: the wedge, outranks all.**\n\nClaim.\n",
                      extra="\n### F-907 (test) - review of F-906.\n\n**F-906 IS REFUTED** on five counts.\n")),
    ],
    "R4": [
        ("FAIL", "CONTRADICTED", dict(head="### F-908 (test) - uses an already-indicted counter.\n\n",
                      body="### F-908 (test) - uses an already-indicted counter.\n\n"
                           "`PHYS-CENSUS total=46.0MB` shows live occupancy, so the pool is fine.\n",
                      extra="\n### F-909 (earlier) - the counter is cumulative.\n\n"
                            "`PHYS-CENSUS total=` is CUMULATIVE requested bytes, reset to 0 above\n"
                            "200 MB, so it is never live occupancy.\n",
                      order_extra_first=True)),
        ("PASS", "", dict(head="### F-910 (test) - cites the rebuttal.\n\n",
                      body="### F-910 (test) - cites the rebuttal.\n\n"
                           "`PHYS-CENSUS total=46.0MB` is cumulative per F-909, so it is not live.\n",
                      extra="\n### F-909 (earlier) - the counter is cumulative.\n\n"
                            "`PHYS-CENSUS total=` is CUMULATIVE requested bytes, reset to 0 above\n"
                            "200 MB, so it is never live occupancy.\n",
                      order_extra_first=True)),
    ],
    "R5": [
        ("FAIL", "WINDOW-UNSTATED", dict(body="### F-911 (test) - the header is destroyed.\n\n"
                           "`F375-HEAPSTORE #1..#8`: eight consecutive guest U32 stores of value 0.\n")),
        ("PASS", "", dict(body="### F-912 (test) - the header is destroyed.\n\n"
                           "`F375-HEAPSTORE #1..#8`: eight consecutive guest U32 stores of value 0,\n"
                           "through a 0x240-byte watch -- a lower bound, not the total.\n")),
    ],
}


def selftest(verbose=False):
    """Each rule gets a synthetic that must FAIL **for its own reason**, plus a
    control that must PASS. Checking the verdict alone is not enough: a case can
    fail for the wrong rule and still read `FAIL`, which is how a linter test
    suite ends up green over a dead check. So each case carries the code it is
    supposed to raise, the run's own output is searched for it, and a PASS case
    additionally has to be free of every FAIL code.

    A rule whose FAIL case cannot be built is a finding about the rule, not
    about the test, so the case list above is the whole claim being tested.
    """
    fails = 0
    for rule, cases in SYNTH.items():
        for want, code_wanted, spec in cases:
            with tempfile.TemporaryDirectory() as td:
                p = Path(td) / "SYNTH.md"
                head = spec.get("head") or "### F-9%02d (test) - a finding.\n" % (10 + fails)
                parts = [head, "\n", spec["body"]]
                if spec.get("extra"):
                    if spec.get("order_extra_first"):
                        parts = [spec["extra"], "\n", head, "\n", spec["body"]]
                    else:
                        parts = parts + [spec["extra"]]
                p.write_text("".join(parts), encoding="utf-8")
                buf = io.StringIO()
                old, sys.stdout = sys.stdout, buf
                try:
                    code = lint(p, None, None, False, False, True, 60, False)
                finally:
                    sys.stdout = old
                out = buf.getvalue()
                got = "FAIL" if code else "PASS"
                why_ok = (got == want) and (code_wanted in out if want == "FAIL" else True)
                tag = "ok  " if why_ok else "BAD "
                if not why_ok:
                    fails += 1
                if verbose or not why_ok:
                    print(f"{tag} {rule} want={want}/{code_wanted or '-'} got={got}")
                    if not why_ok:
                        print(out)
    print(f"selftest: {sum(len(v) for v in SYNTH.values())} cases, {fails} unexpected")
    print(f"  R1 {len(SYNTH['R1'])} R2 {len(SYNTH['R2'])} R3 {len(SYNTH['R3'])} "
          f"R4 {len(SYNTH['R4'])} R5 {len(SYNTH['R5'])}")
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("target", nargs="?", default=None,
                    help="finding id / id prefix, or a ledger .md (default: the whole ledger)")
    ap.add_argument("--strict", action="store_true",
                    help="exit 1 on UNVERIFIABLE too, not only on FAIL")
    ap.add_argument("--as-of", metavar="ID",
                    help="grade as the ledger stood when ID was written: truncate to it, "
                         "so a later refutation cannot retroactively pass it")
    ap.add_argument("--all", action="store_true", help="print passing findings too")
    ap.add_argument("--attributed-only", action="store_true",
                    help="R2 fires only when the sentence names the lr a function/owner "
                         "(the narrow reading; default is the briefed any-lr= reading)")
    ap.add_argument("--deep-logs", action="store_true",
                    help="also range-check .log citations (counts lines up to 4 MB)")
    ap.add_argument("--r4-any-verdict", action="store_true",
                    help="R4 fires on any verdict adjective, not only the prohibition "
                         "set (333/593 entries vs 96; use it to audit the vocabulary)")
    ap.add_argument("--r4-window", type=int, default=60,
                    help="R4 only looks back this many entries (~1 day of work at this "
                         "ledger's rate; 0 = the whole ledger, which fires on half of it)")
    ap.add_argument("--width", type=int, default=96, help="headline width")
    ap.add_argument("--selftest", action="store_true", help="synthetic cases, run and exit")
    ap.add_argument("-v", "--verbose", action="store_true", help="selftest detail")
    a = ap.parse_args()
    if a.selftest:
        return selftest(a.verbose)
    ledger = DEFAULT_LEDGER
    sel = None
    if a.target:
        p = Path(a.target)
        if p.suffix == ".md" and p.is_file():
            ledger = p
        else:
            sel = a.target
    if not ledger.is_file():
        print(f"claim_lint: no ledger at {ledger}", file=sys.stderr)
        return 2
    return lint(ledger, sel, a.as_of, a.deep_logs, a.attributed_only, a.all, a.width,
                a.strict, a.r4_any_verdict, a.r4_window)


if __name__ == "__main__":
    sys.exit(main())
