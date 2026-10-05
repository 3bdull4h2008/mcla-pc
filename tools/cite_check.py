#!/usr/bin/env python3
"""Anchor verifier for `file:line` citations -- the complement to claim_lint.py R1.

WHY THIS EXISTS
---------------
An audit resolved 34 `file:line` citations in the ledger against the source and
got 7 right (21%). The dominant cause is mechanical, not intellectual: the files
are edited constantly, so a bare line number is a POSITION, not a FACT. The
measured drift was +226 lines in one file, +605 in another, and BACKWARDS in a
third -- a number that is "close" is not closer than one that is far.

One cited line is unrecoverable outright: it existed only in an uncommitted
state of `src/kernel/heap.cpp` that was later overwritten, so `git show` and
`git blame` both return nothing. That is the case no amount of re-derivation
fixes, and it is why the project adopted an anchor convention:

    every `file:line` must ALSO carry a backticked symbol or literal that
    exists at that site, e.g.  src/kernel/heap.cpp:626 `HEAPLEAK-SUM`

Line numbers name a position; anchors name content.

WHAT THIS CHECKS, AND WHAT IT DELIBERATELY DOES NOT
--------------------------------------------------
`claim_lint.py` rule R1 already grades a cited RANGE. R1 derives its search
keys heuristically from the sentence (it guesses that the "thing the citation
produces" is one of the instruments, `sub_` names, call names or `field=`
tokens in the prose) and looks +-40 lines. R1 skips `.md`/`.log` targets
entirely. R1 also only reads the ledger.

So the two overlap on purpose and the split is clean:

  * R1 owns "does the cited RANGE contain a plausible producer token, in a
    SOURCE file, in the ledger".  It re-derives what the anchor should be.
  * THIS owns "is the anchor the AUTHOR wrote there present at that site",
    in docs, skills, CMakeLists comments, src/ comments and tools docstrings.

An author-written anchor is a stronger signal than a guessed one precisely
because a human had to commit to it, and because it is the only form that
survives an edit. This tool therefore does NOT fuzzy-match: if the anchor
string is not a substring of some line, the citation is ANCHOR-MISSING, full
stop. A resolver that "almost" matches is how a wrong citation becomes
load-bearing -- and a linter that fails a correct citation is worse than no
linter, because the author learns to ignore it.

Two further deliberate non-features:
  * NO-ANCHOR is graded but does NOT fail by default. Bare `file:line` is the
    MAJORITY of existing citations; a gate that fails the majority on day one
    gets switched off. `--strict` turns it into a failure, which is how the
    convention gets adopted incrementally.
  * A fix is never emitted without an anchor. A proposed line number with no
    anchor is a guess, and a guess that rewrites a ledger entry whose MEANING
    changed is worse than the wrong number it replaces. So NO-ANCHOR gets a
    `hint` column (a candidate anchor, for the author to accept or reject) and
    never a fix line.

GRADES
------
  ANCHOR-OK                file exists, anchor present at/inside the cited
                           range +-WINDOW
  ANCHOR-DRIFT             anchor present, but at another line. Both lines
                           are reported. RECOVERABLE, and the common case.
  ANCHOR-REGION-AMBIGUOUS  anchor occurs MORE THAN ONCE in the file and the
                           cited line is near none of them: the anchor is
                           unambiguous, the REGION is not, so no fix is
                           proposed (see R5 below)
  ANCHOR-MISSING           file exists, the anchor string is in no line of it
  FILE-MISSING             the path resolves to nothing
  AMBIGUOUS                the basename matches >1 file. `ppc_recomp.14.cpp`
                           exists in BOTH `generated/ppc/` and
                           `generated/ppc_xenon/` and those are not the same
                           code, so a guess here is a coin flip
  NO-ANCHOR                bare `file:line`, no anchor, not graded

R5 is the ANCHOR-REGION-AMBIGUOUS case and it is measured, not hypothetical: a
helper macro or a repeated `MCLA_LOG_WARN("HEAPLEAK-SUM ...")` site both make
"the anchor occurs twice" ordinary rather than exotic. Picking occurrence #1
when the cited line is 600 lines from both is how a recovery turns into a new
wrong citation -- so the tool reports the candidate lines and stops.

EXIT CODES
----------
  0  no unrecoverable citation found (the default run is informational)
  1  an unrecoverable grade was found: ANCHOR-MISSING, ANCHOR-REGION-AMBIGUOUS,
     or FILE-MISSING.  `--strict` adds ANCHOR-DRIFT, AMBIGUOUS and NO-ANCHOR.
  2  bad arguments / no documents found
  3  --selftest failed

SCOPE AND BOUNDS
----------------
Containers scanned: `docs/**.md`, `AGENTS.md`, `.qoder/skills/**.md`, the
`#` comments of `CMakeLists.txt`, the C/C++ comments of `src/**`, and the
docstrings + `#` comments of `tools/*.py`. Source comments are not optional:
one of the worst known citations in this project lives in
`src/kernel/heap.cpp`, not in the ledger, and claim_lint.py cannot see it.

`generated/**` is NOT a container (it is ~400 MB across three near-duplicate
trees) but IS a valid citation TARGET. Targets are read whole under a 4 MiB
per-file cap with a 48 MiB total budget, and streamed one pass at a time
above the cap, so memory is O(asked-for lines) and not O(tree). A target above
--max-stream MB is reported BOUNDED-SKIP rather than silently passed.

Nothing here writes to the repository. `--fix` is a DRY RUN and prints a
paste-ready list; it never edits a file, because rewriting a ledger is another
stream's job and a silently "corrected" citation is how an error becomes
invisible.
"""

from __future__ import annotations

import argparse
import ast
import io
import json
import os
import re
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

# --------------------------------------------------------------- citation form

# Same target grammar claim_lint.py CITE uses, so the two tools agree on what a
# citation IS. The trailing `(?::\d+(?:-)?)+` allows carry-forward tails such
# as `heap.cpp:531,538` and `:932-938`, which is the house style.
CITE_RE = re.compile(
    r"(?<![\w./\\-])"
    r"((?:[\w.-]+[\\/])*[\w.-]+"
    r"\.(?:cpp|cc|cxx|c|h|hpp|inc|m|toml|py|ps1|bat|cmd|md|txt|log|map|cfg|"
    r"json|xml|cmake|patch|sln|def|rc)"
    r"(?::\d+(?:-\d+)?)+)"
)

# What may sit between the citation and an anchor: the citation's own closing
# backtick, whitespace, and light punctuation. Deliberately short -- a wide
# window would let the tool pair a citation with a symbol from a later clause,
# which is the guessing R1 already does.
#
# TWO patterns, tried in order, and NEVER merged into one with an optional
# leading tick. A single pattern with `[`']?` backtracks: when the citation is
# already inside backticks and no anchor follows, the optional tick matches
# nothing, the engine then re-reads the citation's OWN closing tick as the
# anchor's opening tick, and swallows the next clause of prose as the "anchor"
# (measured on this tree: 578 ANCHOR-MISSING, of which the large majority were
# English fragments like `is a bare` and `, regression-clean (`). Anchors are
# content, and a regex that reads prose as content is worse than no regex.
TRAIL_CLOSED = re.compile(r"`[^\S\n]{0,4}`([^\`\n]{1,64})`")
TRAIL_BARE = re.compile(r"[^\S\n]{0,4}`([^\`\n]{1,64})`")
# A run of backticked tokens on the citation's own line, for the NO-ANCHOR hint.
HINT_RE = re.compile(r"`([^\`\n]{2,48})`")
# `w657.log:19:19:22` is a clock in a citation's clothing. Two-or-more colons
# after the extension is a timestamp, not a line, and grading it as a line is
# how a tool reports a line number nobody wrote.
CLOCK = re.compile(r":\d+:\d+")

BAD_ANCHOR = re.compile(r"^[0-9\s.:/*#-]+$")
# Two or more whitespace-separated purely-lowercase words is a clause of
# English, not a symbol. Suppressed and COUNTED rather than silently accepted,
# because an ANCHOR-MISSING on prose is a false alarm that teaches the author
# to ignore the grade.
PROSE_ANCHOR = re.compile(r"(?:^|\s)[a-z]{2,}\s+[a-z]{2,}\b")
# An anchor with an ellipsis in it is not a literal, and cannot be matched by
# construction. Reported, not excused.
PARAPHRASE = re.compile(r"\.\.\.|\u2026")

# Grades, and which of them end the run.
UNRECOVERABLE = ("ANCHOR-MISSING", "ANCHOR-REGION-AMBIGUOUS", "FILE-MISSING")
STRICT_EXTRA = ("ANCHOR-DRIFT", "AMBIGUOUS", "NO-ANCHOR")
GRADES = ("ANCHOR-OK", "ANCHOR-DRIFT", "ANCHOR-REGION-AMBIGUOUS", "ANCHOR-MISSING",
          "FILE-MISSING", "AMBIGUOUS", "NO-ANCHOR", "BOUNDED-SKIP")

# Extensions that are container-only (never worth resolving as a target).
CONTAINER_ONLY = {".md"}

# Basename index trees. claim_lint's SourceIndex.TREES plus `cmake`, plus
# `build` for LOG/MAP artifacts ONLY -- 600 of this tree's citations name a
# soak log by basename (`w657.log:722`) and excluding build/ reported every one
# of them FILE-MISSING, which is a false alarm about the least stable part of
# the tree. Restricting build/ to .log/.map keeps it out of source resolution.
INDEX_TREES = ("src", "generated", "config", "tools", "docs", "cmake", ".qoder")
INDEX_TREES_EXTRA = {"build": (".log", ".map")}


# ------------------------------------------------------------------ the target

class Target:
    """Line-addressable file reader with a byte budget, because generated/ is 400 MB.

    Small files are cached whole under a 48 MiB budget; anything larger is
    streamed one pass per (file, anchor) and only the requested occurrence line
    numbers are kept. Memory is O(asked-for lines), never O(tree).
    """

    CAP = 4 << 20
    BUDGET = 48 << 20
    MAX_OCC = 64          # occurrences kept per anchor; beyond this it is "many"
    MAX_STREAM = 96 << 20  # a target bigger than this is reported, not streamed

    def __init__(self, root: Path, max_stream: int = MAX_STREAM):
        self.root = root
        self.max_stream = max_stream
        self._lines = {}
        self._bytes = 0
        self._base = None
        self._occ = {}
        self._nlines = {}
        self.streamed = set()
        self.skipped = set()

    # -- basename index -------------------------------------------------
    def _index(self):
        if self._base is None:
            idx = defaultdict(list)
            for t in INDEX_TREES:
                d = self.root / t
                if not d.is_dir():
                    continue
                for p in d.rglob("*"):
                    if p.is_file() and p.suffix.lower() not in CONTAINER_ONLY:
                        idx[p.name].append(p.relative_to(self.root).as_posix())
            for t, exts in INDEX_TREES_EXTRA.items():
                d = self.root / t
                if not d.is_dir():
                    continue
                for p in d.rglob("*"):
                    if p.is_file() and p.suffix.lower() in exts:
                        idx[p.name].append(p.relative_to(self.root).as_posix())
            self._base = {k: sorted(v) for k, v in idx.items()}
        return self._base

    def _rel(self, rel: str):
        p = (self.root / rel.replace("\\", "/")).resolve()
        try:
            p.relative_to(self.root)
        except ValueError:
            return None                      # climbs out of the repo
        return p

    def resolve(self, rel: str):
        """(path, kind, note). kind is 'ok' | 'missing' | 'ambiguous'."""
        p = self._rel(rel)
        if p is not None and p.is_file():
            return p, "ok", ""
        if "/" in rel or "\\" in rel:
            return None, "missing", "path not in the tree"
        cands = self._index().get(rel, [])
        if len(cands) == 1:
            return self._rel(cands[0]), "ok", ""
        if len(cands) > 1:
            shown = ", ".join(cands[:4])
            extra = f" (+{len(cands) - 4} more)" if len(cands) > 4 else ""
            return None, "ambiguous", f"{len(cands)} files share this basename: {shown}{extra}"
        return None, "missing", "no such file, and no file of that basename in the tree"

    # -- reading --------------------------------------------------------
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

    def _cached(self, p):
        try:
            return p.stat().st_size <= self.CAP
        except OSError:
            return False

    def nlines(self, p):
        if p is None or not p.is_file():
            return None
        k = str(p)
        if k not in self._nlines:
            if self._cached(p):
                self._nlines[k] = len(self._all(p))
            else:
                self._nlines[k] = -1          # unknown; do not count, do not guess
        return self._nlines[k] or None

    def line(self, p, n):
        if p is None or not self._cached(p):
            return ""
        txt = self._all(p)
        return txt[n - 1] if 0 < n <= len(txt) else ""

    def occurrences(self, p, anchor):
        """(state, count, [line numbers], over_cap) for `anchor` in a line.

        `state` is 'ok' or 'unsearched'. 'unsearched' means the file is past
        the stream bound and was NOT read, which is a fact about the tree and
        not a verdict about the citation -- reporting it as ANCHOR-MISSING
        would invent 578 wrong citations out of nine large soak logs.

        No normalisation, no case folding, no fuzzy fallback. A half-match
        rescue is precisely the laundering this tool exists to prevent.
        """
        key = (str(p), anchor)
        if key in self._occ:
            return self._occ[key]
        hit = []
        count = 0
        over = False
        if self._cached(p):
            for i, s in enumerate(self._all(p), 1):
                if anchor in s:
                    count += 1
                    if len(hit) < self.MAX_OCC:
                        hit.append(i)
                    else:
                        over = True
            res = ("ok", count, hit, over)
        else:
            try:
                size = p.stat().st_size
            except OSError:
                size = 0
            if size > self.max_stream:
                self.skipped.add(p.name)
                res = ("unsearched", 0, [], False)
            else:
                self.streamed.add(p.name)
                with p.open("r", encoding="utf-8", errors="replace") as fh:
                    for n, s in enumerate(fh, 1):
                        if anchor in s:
                            count += 1
                            if len(hit) < self.MAX_OCC:
                                hit.append(n)
                            else:
                                over = True
                res = ("ok", count, hit, over)
        self._occ[key] = res
        return res

    def in_range(self, p, anchor, lo, hi, pad):
        """Line number of `anchor` within [lo-pad, hi+pad], or None.

        For a file too big to cache this is a SECOND read of the file, after
        the one `occurrences` already did. Two 900 MB reads is a minute of
        somebody's afternoon, so `occurrences` records whether it already saw
        a hit in the window and this short-circuits on it.
        """
        a, b = max(1, lo - pad), hi + pad
        if not self._cached(p):
            state, count, hits, over = self.occurrences(p, anchor)
            if state == "unsearched":
                return None
            for h in hits:
                if a <= h <= b:
                    return h
            return None
        for n in range(a, b + 1):
            s = self.line(p, n)
            if s and anchor in s:
                return n
        return None


# ----------------------------------------------------------------- the grading

class Citation:
    __slots__ = ("doc", "doc_line", "raw", "rel", "lo", "hi", "anchor",
                 "grade", "detail", "at", "cands", "hint")

    def __init__(self, doc, doc_line, raw, rel, lo, hi, anchor, hint):
        self.doc = doc
        self.doc_line = doc_line
        self.raw = raw
        self.rel = rel
        self.lo = lo
        self.hi = hi
        self.anchor = anchor
        self.hint = hint
        self.grade = "NO-ANCHOR"
        self.detail = ""
        self.at = None
        self.cands = []

    def where(self):
        return f"{self.doc}:{self.doc_line}"

    def as_dict(self):
        return dict(doc=self.doc, doc_line=self.doc_line, cite=self.raw,
                    target=self.rel, lo=self.lo, hi=self.hi, anchor=self.anchor,
                    grade=self.grade, detail=self.detail, at=self.at,
                    candidates=self.cands, hint=self.hint)


def grade(cite: Citation, tgt: Target, window: int = 2):
    """Grade one citation against the tree. Never guesses a fix without an anchor."""
    p, kind, note = tgt.resolve(cite.rel)
    if kind == "missing":
        cite.grade = "FILE-MISSING"
        cite.detail = note
        return cite
    if kind == "ambiguous":
        cite.grade = "AMBIGUOUS"
        cite.detail = note + "; add the directory to the citation"
        return cite

    if not cite.anchor:
        cite.grade = "NO-ANCHOR"
        cite.detail = "bare file:line -- the new convention wants an anchor here"
        return cite

    # --- anchored ------------------------------------------------------
    n = tgt.nlines(p)
    if not tgt._cached(p):
        # One streaming pass does both jobs: the window check and the
        # occurrence census. Two passes over a 900 MB soak log is a minute
        # of somebody's afternoon for an answer the first pass already had.
        state, count, hits, over = tgt.occurrences(p, cite.anchor)
        if state == "unsearched":
            cite.grade = "BOUNDED-SKIP"
            cite.detail = (f"{cite.rel} is past the --max-stream bound, so "
                           f"`{cite.anchor}` was not searched for; raise the bound")
            return cite
        a, b = max(1, cite.lo - window), cite.hi + window
        at = next((h for h in hits if a <= h <= b), None)
    else:
        at = tgt.in_range(p, cite.anchor, cite.lo, cite.hi, window)
    if at is not None:
        cite.grade = "ANCHOR-OK"
        cite.at = at
        cite.detail = (f"`{cite.anchor}` is at line {at}"
                       + ("" if at == cite.lo else f" (cited {cite.lo})"))
        return cite

    state, count, hits, over = tgt.occurrences(p, cite.anchor)
    if state == "unsearched":
        cite.grade = "BOUNDED-SKIP"
        cite.detail = (f"{cite.rel} is past the --max-stream bound, so "
                       f"`{cite.anchor}` was not searched for; raise the bound "
                       f"to check it")
        return cite
    if count == 0:
        cite.grade = "ANCHOR-MISSING"
        cite.detail = (f"the file exists, but no line of {cite.rel} contains "
                       f"`{cite.anchor}`")
        if PARAPHRASE.search(cite.anchor):
            # A real and separate defect: the author wrote a PARAPHRASE of the
            # site, not a literal. It cannot be matched by construction, and
            # quoting it back verbatim into a correction is how a paraphrase
            # becomes a fabricated citation.
            cite.detail += ("; the anchor contains an ellipsis, so it is a "
                            "PARAPHRASE, not a literal -- quote the real line")
        return cite
    if count > 1:
        # R5. The anchor is unambiguous; the region is not. No fix is proposed.
        cite.grade = "ANCHOR-REGION-AMBIGUOUS"
        cite.cands = hits
        cite.detail = (f"`{cite.anchor}` occurs {count}{'+' if over else ''} times in "
                       f"{cite.rel}, nearest at {_nearest(hits, cite.lo)}: "
                       f"{', '.join(map(str, hits[:6]))}"
                       + (" ..." if len(hits) > 6 else "") + " -- no fix proposed")
        return cite

    cite.grade = "ANCHOR-DRIFT"
    cite.at = hits[0]
    delta = hits[0] - cite.lo
    cite.detail = (f"cited {cite.lo}, `{cite.anchor}` is at {hits[0]} "
                   f"({delta:+d})" + (f"; {cite.rel} has {n} lines" if n else ""))
    return cite


def _nearest(hits, lo):
    return min(hits, key=lambda h: abs(h - lo))


# ------------------------------------------------------------- container scan

def _read(p: Path) -> str:
    try:
        return p.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return ""


def c_comment_lines(text: str):
    """[(lineno, comment text)] for // and /* */, skipping string/char literals.

    A citation inside a string literal is a printf of a path, not a claim about
    the tree; grading it would inflate the counts. This is a small state machine
    rather than a regex because a regex cannot tell `"// not a comment"` from
    a comment.
    """
    out = []
    i, n, line, blk = 0, len(text), 1, None
    while i < n:
        c = text[i]
        if c == "\n":
            if blk is not None:
                out.append((line, "".join(blk)))
                blk = []
            line += 1
            i += 1
            continue
        if c == '"' or c == "'":
            q, i = c, i + 1
            while i < n and text[i] != "\n":
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == q:
                    i += 1
                    break
                i += 1
            continue
        if c == "/" and i + 1 < n and text[i + 1] == "/":
            j = text.find("\n", i)
            if j < 0:
                j = n
            piece = text[i + 2:j]
            if blk is not None:
                out.append((line, "".join(blk) + " " + piece))
                blk = None
            else:
                out.append((line, piece))
            i = j
            continue
        if c == "/" and i + 1 < n and text[i + 1] == "*":
            blk = []
            i += 2
            continue
        if blk is not None:
            blk.append(c)
        i += 1
    if blk is not None:
        out.append((line, "".join(blk)))
    return out


def hash_comment_lines(text: str):
    """[(lineno, comment text)] for `#` comments, CMake-style. Line-scoped."""
    out = []
    for n, s in enumerate(text.splitlines(), 1):
        i = s.find("#")
        if i >= 0 and s[:i].count('"') % 2 == 0:
            out.append((n, s[i + 1:]))
    return out


def py_docstring_lines(text: str):
    """[(lineno, docstring text)] via ast, so line numbers are real line numbers.

    Tools/ is where this matters: a tools/*.py docstring is a live claim about
    the tree, and it is prose-shaped exactly like a .md. Scanned as text it
    would also pick up the `--help` strings; ast keeps the two apart.
    """
    out = []
    try:
        tree = ast.parse(text)
    except (SyntaxError, ValueError):
        return out
    lines = text.splitlines()

    def walk(node):
        body = getattr(node, "body", None)
        if isinstance(body, list):
            for st in body:
                if isinstance(st, ast.Expr) and isinstance(st.value, ast.Constant) \
                        and isinstance(st.value.value, str) \
                        and getattr(st, "lineno", None):
                    s, e = st.lineno, getattr(st, "end_lineno", st.lineno) or st.lineno
                    for k in range(s, e + 1):
                        if k - 1 < len(lines):
                            out.append((k, lines[k - 1]))
        for ch in ast.iter_child_nodes(node):
            walk(ch)

    walk(ast.parse(text))
    return out


CONTAINERS = (
    # (label, glob, extractor)
    ("doc", "docs/*.md", None),
    ("doc", "AGENTS.md", None),
    ("doc", ".qoder/skills/**/*.md", None),
    ("doc", "*.md", None),                      # root .md other than the two above
    ("cmake", "CMakeLists.txt", hash_comment_lines),
    ("cmake", "cmake/**/*.cmake", hash_comment_lines),
    ("src", "src/**/*.cpp", c_comment_lines),
    ("src", "src/**/*.h", c_comment_lines),
    ("src", "src/**/*.c", c_comment_lines),
    ("src", "src/**/*.hpp", c_comment_lines),
    ("tools", "tools/*.py", py_docstring_lines),
    ("tools", "tools/*.py", hash_comment_lines),
)

DOC_CLASSES = ("doc", "cmake", "src", "tools")


def containers(roots):
    """[(class, path)] for every container under `roots` (default: the repo)."""
    seen = set()
    out = []
    for base in roots:
        for label, pattern, _ in CONTAINERS:
            for p in sorted(base.glob(pattern)):
                if p.is_file() and p not in seen and p.name != "cite_check.py":
                    seen.add(p)
                    out.append((label, p))
    return out


def pieces_for(label, path, text):
    """[(lineno, line_text)] -- the carrier lines of one container file.

    A .md is prose end to end. Everything else is reduced to its COMMENTS or
    DOCSTRINGS first, because a `file:line` inside a live string literal is a
    printf of a path, not a claim about the tree, and grading it would inflate
    every count in the report. `tools/*.py` is scanned twice on purpose: a
    docstring is prose about the tree and a `#` comment is a note in it, and
    claim_lint.py reads neither.
    """
    if label == "doc":
        return [(n, s) for n, s in enumerate(text.splitlines(), 1)]
    out = []
    for l, pat, fn in CONTAINERS:
        if l == label and fn is not None and path.match(pat):
            out.extend(fn(text))
    return sorted(out, key=lambda z: z[0])


def take_anchor(line, end):
    """The backticked symbol/literal immediately after a citation, or ''.

    Ordered, not a single regex: if the character at `end` closes the
    citation's own backticks then ONLY the closed form is legal, because the
    bare form would read that closing tick as an opening one and take the next
    clause of prose for an anchor.
    """
    if end < len(line) and line[end] == "`":
        m = TRAIL_CLOSED.match(line, end)
    else:
        m = TRAIL_BARE.match(line, end)
    if not m:
        return ""
    cand = m.group(1).strip()
    if not cand or BAD_ANCHOR.match(cand) or not re.search(r"[A-Za-z_]", cand):
        return ""
    if CITE_RE.search(cand) or PROSE_ANCHOR.search(cand):
        return ""
    return cand


def extract(label, path, rel_name):
    """[Citation] from one container file."""
    text = _read(path)
    cites = []
    for n, line in pieces_for(label, path, text):
        for m in CITE_RE.finditer(line):
            raw = m.group(1)
            if CLOCK.search(raw):
                continue                     # `w657.log:19:19:22` is a timestamp
            # `(?:-(\d+))?` and NOT `(?:-(\d+)?)`: on CPython 3.14 a nested
            # optional quantifier with a capture inside it matches NOTHING
            # (measured, 3.14.6) and the whole number silently disappears, so
            # the tool would have reported every citation in the tree as having
            # no line at all. Written the other way it is a plain optional group.
            nums = re.findall(r":(\d+)(?:-(\d+))?", raw)
            lo = int(nums[0][0])
            hi = int(nums[0][1] or nums[0][0])
            rel = re.sub(r"(:\d+(?:-\d+)?)+$", "", raw).replace("\\", "/")
            # An anchored citation is wrapped:  `file:line` `ANCHOR`
            anchor = take_anchor(line, m.end())
            hint = ""
            if not anchor:
                for hm in HINT_RE.finditer(line):
                    if hm.group(1).strip() and not CITE_RE.search(hm.group(1)):
                        hint = hm.group(1).strip()
                        break
            cites.append(Citation(rel_name, n, raw, rel, lo, hi, anchor, hint))
    return cites


# -------------------------------------------------------------------- the run

def run(targets, window=2, strict=False, want_json=False, do_fix=False,
        quiet=False, width=96, max_stream=Target.MAX_STREAM):
    tgt = Target(REPO, max_stream=max_stream)
    all_c = []
    for label, path in containers(targets):
        name = path.relative_to(REPO).as_posix() if path.is_relative_to(REPO) else str(path)
        all_c.extend((label, c) for c in extract(label, path, name))
    for label, c in all_c:
        grade(c, tgt, window=window)

    tally = Counter(c.grade for _, c in all_c)
    by_class = defaultdict(Counter)
    for label, c in all_c:
        by_class[label][c.grade] += 1

    # Per-container bad rate. "bad" excludes NO-ANCHOR because a bare cite is
    # not verifiable, not wrong -- folding it in would let a file with 50 bare
    # cites and 1 correct one report 0%.
    per_doc = defaultdict(Counter)
    for label, c in all_c:
        per_doc[(label, c.doc)][c.grade] += 1
    def _anchored(v):
        return sum(n for g, n in v.items() if g != "NO-ANCHOR")

    def _bad(v):
        return sum(n for g, n in v.items() if g not in ("ANCHOR-OK", "NO-ANCHOR"))

    worst = sorted(
        ((k, v) for k, v in per_doc.items() if _anchored(v) >= 3),
        # Rate first, then the COUNT OF ANCHORED citations -- the same
    # denominator the rate is printed over. Ranking a 72-citation file above
    # a 109-citation one at an identical 100% because it also happens to have
    # more BARE citations is a tiebreak that reports the wrong offender.
        key=lambda kv: (-(_bad(kv[1]) / max(1, _anchored(kv[1]))), -_anchored(kv[1])))
    if not want_json and not quiet:
        report(all_c, by_class, tally, worst, per_doc, tgt, window, do_fix, width)
    if want_json:
        print(json.dumps({
            "root": str(REPO),
            "window": window,
            "totals": dict(tally),
            "by_container_class": {k: dict(v) for k, v in by_class.items()},
            "worst": [{"container": f"{k[0]}:{k[1]}",
                       "grades": dict(v),
                       "total": sum(v.values())} for k, v in worst[:15]],
            "streamed_targets": sorted(tgt.streamed),
            "skipped_targets": sorted(tgt.skipped),
            "citations": [c.as_dict() for _, c in all_c],
        }, indent=1))

    return _rc(tally, strict=strict)


def _print_fix(cites):
    """The --fix body: a paste-ready list, printed and never applied.

    Only ANCHOR-DRIFT qualifies, and ANCHOR-DRIFT by construction means the
    anchor occurs at exactly ONE line, so the proposal is a fact and not a
    guess. ANCHOR-REGION-AMBIGUOUS never proposes: several sites, no basis for
    choosing, and picking one would manufacture a new wrong citation.
    """
    dr = [c for c in cites if c.grade == "ANCHOR-DRIFT"]
    if not dr:
        return "  (no unambiguous ANCHOR-DRIFT to fix)\n"
    out = []
    for c in dr:
        out.append(f"  {c.doc}:{c.doc_line}\n"
                   f"    - {c.raw}\n"
                   f"    + {c.rel}:{c.at} `{c.anchor}`\n")
    out.append(f"  {len(dr)} proposed\n")
    return "".join(out)


def report(all_c, by_class, tally, worst, per_doc, tgt, window, do_fix, width):
    out = io.StringIO()
    w = out.write
    rec = tally["ANCHOR-DRIFT"]
    unre = sum(tally[g] for g in UNRECOVERABLE)
    anchored = sum(tally[g] for g in GRADES if g not in ("NO-ANCHOR", "BOUNDED-SKIP"))
    bare = tally["NO-ANCHOR"]

    w("=" * width + "\n")
    w(f"cite_check  anchor verifier   repo {REPO}   window +-{window} lines\n")
    w("=" * width + "\n")
    checked = sum(tally[g] for g in GRADES
                  if g not in ("NO-ANCHOR", "BOUNDED-SKIP", "AMBIGUOUS"))
    w(f"citations found: {len(all_c)}   bare (NO-ANCHOR): {bare}   "
      f"anchored but unresolvable (AMBIGUOUS): {tally['AMBIGUOUS']}\n")
    w(f"anchors actually CHECKED against a file: {checked}\n")
    for g in GRADES:
        if tally[g]:
            w(f"  {g:<24} {tally[g]:>5}\n")
    w(f"\nRECOVERABLE  (ANCHOR-DRIFT: add the anchor, update the number)  {rec:>5}"
      f"   {100.0 * rec / max(1, checked):.0f}% of checked\n")
    w(f"UNRECOVERABLE (FILE-MISSING + ANCHOR-MISSING + ANCHOR-REGION-AMBIGUOUS)"
      f"  {unre:>5}   {100.0 * unre / max(1, checked):.0f}% of checked\n")
    w(f"  AMBIGUOUS  {tally['AMBIGUOUS']:>5}   recoverable by adding the directory to "
      f"the citation; NOT counted in either split\n")

    w("\n-- by container class (where the claim lives) ----------------\n")
    for cls in DOC_CLASSES:
        if cls not in by_class:
            continue
        v = by_class[cls]
        t = sum(v.values())
        bad = sum(n for g, n in v.items() if g not in ("ANCHOR-OK", "NO-ANCHOR"))
        w(f"  {cls:<7} total {t:>5}   ok {v['ANCHOR-OK']:>4}   drift {v['ANCHOR-DRIFT']:>4}"
          f"   unrecoverable {sum(v[g] for g in UNRECOVERABLE):>4}"
          f"   bare {v['NO-ANCHOR']:>4}\n")
    in_src = sum(sum(by_class[c].values()) for c in ("src", "cmake", "tools"))
    w(f"  citations living in SOURCE COMMENTS (not documents): {in_src}"
      f"   -- no ledger linter sees these\n")

    w("\n-- worst containers by bad-citation rate (>=3 anchored) ----\n")
    for (cls, doc), v in worst[:8]:
        tot = sum(n for g, n in v.items() if g != "NO-ANCHOR")
        bad = sum(n for g, n in v.items() if g not in ("ANCHOR-OK", "NO-ANCHOR"))
        w(f"  {bad:>4}/{tot:<4} {100.0 * bad / max(1, tot):>3.0f}%  {doc}"
          f"   [bare {v['NO-ANCHOR']}]\n")

    # A second ranking, because "bad rate" is dominated by FILE-MISSING and
    # hides the grade that actually indicts an author: an anchor that is
    # nowhere in the file it is cited from. That is the fabricated case.
    fab = sorted(((k, v) for k, v in per_doc.items() if v["ANCHOR-MISSING"]),
                 key=lambda kv: -kv[1]["ANCHOR-MISSING"])
    if fab:
        w("\n-- ANCHOR-MISSING by container: the fabricated-citation list ----\n")
        for (cls, doc), v in fab[:10]:
            w(f"  {v['ANCHOR-MISSING']:>4}  {doc}\n")

    dr = [(c, lbl) for lbl, c in all_c if c.grade == "ANCHOR-DRIFT"]
    if dr:
        w("\n-- ANCHOR-DRIFT: recoverable, anchor in hand --------------\n")
        for c, lbl in dr[:40]:
            w(f"  {c.where()}\n      {c.raw}  ->  {c.rel}:{c.at}   ({c.detail})\n")
        if len(dr) > 40:
            w(f"  ... {len(dr) - 40} more\n")

    unrec = [c for _, c in all_c if c.grade in UNRECOVERABLE]
    if unrec:
        w("\n-- UNRECOVERABLE: needs a human, not a number -----------\n")
        for c in unrec[:40]:
            w(f"  {c.grade:<23} {c.where()}  {c.raw}\n      {c.detail}\n")
        if len(unrec) > 40:
            w(f"  ... {len(unrec) - 40} more\n")

    amb = [c for _, c in all_c if c.grade == "AMBIGUOUS"]
    if amb:
        w("\n-- AMBIGUOUS: the same basename, two different code ----\n")
        for c in amb[:10]:
            w(f"  {c.where()}  {c.raw}\n      {c.detail}\n")

    if do_fix:
        w("\n-- DRY RUN: paste-ready corrections (nothing was written) ----\n")
        w("   A line number is proposed only where the anchor names exactly one\n"
          "   line in the file. Everything else is deliberately left alone: a fix\n"
          "   without an anchor is a guess, and a guess that changes a citation's\n"
          "   MEANING is worse than the wrong number it replaces.\n")
        w(_print_fix([c for _, c in all_c]))
        w("  0 files written (this tool never writes to the repo)\n")

    w("\nnot checked: `generated/**` is resolved and anchor-searched as a TARGET\n"
      "  but is not a CONTAINER -- ~400 MB across three near-duplicate trees.\n"
      "  A target above the stream bound is reported BOUNDED-SKIP, never as a\n"
      "  miss: an unchecked citation is a gap in the sweep, not a wrong claim.\n")
    if tgt.streamed:
        w(f"  streamed (anchor scan, not cached whole): {len(tgt.streamed)} file(s): "
          f"{', '.join(sorted(tgt.streamed)[:4])}{' ...' if len(tgt.streamed) > 4 else ''}\n")
    if tgt.skipped:
        w(f"  NOT READ, past --max-stream: {len(tgt.skipped)} file(s): "
          f"{', '.join(sorted(tgt.skipped)[:4])}{' ...' if len(tgt.skipped) > 4 else ''}\n")
    sys.stdout.write(out.getvalue())


# ------------------------------------------------------------------ selftest

SCRATCH = Path(os.environ.get("TEMP", tempfile.gettempdir())) / "opencode"


def _mk(root: Path, rel: str, lines):
    p = root / rel
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text("\n".join(lines) + "\n", encoding="utf-8")


UNIT = [
    # (file lines) -- 12 lines so a +N drift is easy to state
    ["// line 1", "// line 2", "// line 3", "// line 4", "// line 5", "// line 6",
     "// MARKER-ALPHA is here", "// line 8", "// line 9", "// line 10",
     "// line 11", "// line 12"],
    ["// MARKER-BETA is here", "// filler", "// filler", "// filler"],
]
GEN_A = ["// ppc_a body", "// MARKER-GEN in ppc", "// filler"]
GEN_B = ["// ppc_xenon body", "// MARKER-GEN in ppc_xenon", "// filler"]

HEAP = "src/kernel/heap.cpp"
DUPF = "src/kernel/dup.cpp"
PPCA = "generated/ppc/ppc_recomp.1.cpp"
PPCB = "generated/ppc_xenon/ppc_recomp.1.cpp"

# MARKER-DUP at 3 and 9 of 16. The two sites are 6 apart, so a case citing 15
# is outside the +-2 window of BOTH: the anchor is found, it is found twice,
# and there is no basis for choosing. That is R5, and it is the only way to
# get it is to make the occurrences genuinely ambiguous rather than adjacent.
DUP = ["// filler", "// filler", "// MARKER-DUP first", "// filler", "// filler",
       "// filler", "// filler", "// filler", "// MARKER-DUP second", "// filler",
       "// filler", "// filler", "// filler", "// filler", "// filler", "// filler"]
DUP_ONE = ["// filler", "// filler", "// MARKER-DUP first", "// filler",
           "// filler", "// filler", "// filler", "// filler", "// filler",
           "// filler", "// filler", "// filler", "// filler", "// filler",
           "// filler", "// filler"]


def _tree(root: Path, drop=(), heap=UNIT[0], dup=DUP):
    """(Re)build a synthetic tree. `drop` REMOVES, it does not skip.

    A skip left the file from the previous pass on disk and the mutation
    silently did nothing -- the first version of this selftest reported
    AMBIGUOUS as 'survived its own mutation' for exactly that reason, which is
    a test bug wearing a checker's clothes.
    """
    (root / "docs").mkdir(parents=True, exist_ok=True)
    files = {HEAP: heap, DUPF: dup, PPCA: GEN_A, PPCB: GEN_B}
    for rel, lines in files.items():
        if rel in drop:
            f = root / rel
            if f.is_file():
                f.unlink()
            continue
        _mk(root, rel, lines)
    return root


# Each case: a doc, the grade it MUST raise, the grades it must NOT raise, and
# a mutation that removes the fact the case is asserting. If the grade survives
# the mutation, the case is not testing anything and is reported BAD.
#
# The mutation is on the INPUT, not on the grader. A "disable the check" flag
# in the grader would only prove the flag is read; changing the tree proves the
# check reads the tree.
SYNTH = [
    dict(name="ANCHOR-OK", want="ANCHOR-OK",
         absent=["ANCHOR-DRIFT", "ANCHOR-MISSING", "FILE-MISSING",
                 "ANCHOR-REGION-AMBIGUOUS"],
         doc=f"The marker is at `{HEAP}:7` `MARKER-ALPHA`.\n",
         mutate=dict(heap=["// nothing here", "// at all"])),
    dict(name="ANCHOR-DRIFT", want="ANCHOR-DRIFT",
         absent=["ANCHOR-OK", "ANCHOR-MISSING", "FILE-MISSING"],
         doc=f"The marker is at `{HEAP}:4` `MARKER-ALPHA`.\n",
         mutate=dict(heap=["// nothing here", "// at all"])),
    dict(name="ANCHOR-MISSING", want="ANCHOR-MISSING",
         absent=["ANCHOR-OK", "ANCHOR-DRIFT"],
         doc=f"The marker is at `{HEAP}:3` `MARKER-NOT-PRESENT`.\n",
         mutate=dict(doc=f"The marker is at `{HEAP}:3` `MARKER-ALPHA`.\n")),
    dict(name="FILE-MISSING", want="FILE-MISSING",
         absent=["ANCHOR-OK", "ANCHOR-DRIFT", "ANCHOR-MISSING"],
         doc=f"The marker is at `src/kernel/nope.cpp:3` `MARKER-ALPHA`.\n",
         mutate=dict(new_file="src/kernel/nope.cpp")),
    dict(name="AMBIGUOUS", want="AMBIGUOUS",
         absent=["ANCHOR-OK", "ANCHOR-DRIFT", "ANCHOR-MISSING"],
         doc="The marker is at `ppc_recomp.1.cpp:2` `MARKER-GEN`.\n",
         mutate=dict(drop=(PPCB,))),
    dict(name="ANCHOR-REGION-AMBIGUOUS", want="ANCHOR-REGION-AMBIGUOUS",
         absent=["ANCHOR-OK", "ANCHOR-DRIFT"],
         doc=f"The marker is at `{DUPF}:15` `MARKER-DUP`.\n",
         mutate=dict(dup=DUP_ONE)),
    dict(name="NO-ANCHOR", want="NO-ANCHOR", absent=["ANCHOR-OK", "ANCHOR-DRIFT"],
         doc=f"The marker is at `{HEAP}:7`.\n",
         mutate=dict(doc=f"The marker is at `{HEAP}:7` `MARKER-ALPHA`.\n")),
    dict(name="ANCHOR-OK-in-range", want="ANCHOR-OK", absent=["ANCHOR-DRIFT"],
         doc=f"The marker is in `{HEAP}:5-9` `MARKER-ALPHA`.\n",
         mutate=dict(doc=f"The marker is in `{HEAP}:10-12` `MARKER-ALPHA`.\n")),
]


def _grades(root: Path, doc_text: str, spec: dict, window=2):
    _tree(root,
          drop=spec.get("drop", ()),
          heap=spec.get("heap", UNIT[0]),
          dup=spec.get("dup", DUP))
    if spec.get("new_file"):
        _mk(root, spec["new_file"], UNIT[0])
    d = root / "docs" / "T.md"
    d.write_text(doc_text, encoding="utf-8")
    cites = extract("doc", d, "docs/T.md")
    for c in cites:
        grade(c, Target(root), window=window)
    return cites


def selftest(verbose=False):
    """Every grade must fire for its own reason, and must be breakable.

    Each case is run TWICE against a synthetic tree built in scratch:

      1. as written, and it must raise `want` and raise NONE of `absent`;
      2. with the fact it asserts REMOVED from the tree or the doc, and it must
         then grade differently. A case that survives its own mutation is
         decoration -- it would keep passing if the checker were deleted, which
         is the failure mode that lets a broken gate ship green.
    """
    SCRATCH.mkdir(parents=True, exist_ok=True)
    fails = 0
    for spec in SYNTH:
        with tempfile.TemporaryDirectory(dir=str(SCRATCH)) as td:
            root = Path(td) / "repo"
            got = Counter(c.grade for c in _grades(root, spec["doc"], {}))
            pass1 = got.get(spec["want"], 0) >= 1 and not (set(got) & set(spec["absent"]))

            mut = dict(spec.get("mutate", {}))
            mdoc = mut.pop("doc", spec["doc"])
            mut.setdefault("drop", ())
            got2 = Counter(c.grade for c in _grades(root, mdoc, mut))
            pass2 = got2.get(spec["want"], 0) == 0
            # and the mutation must land SOMEWHERE, not just fail to parse
            pass2 = pass2 and sum(got2.values()) >= 1

            why = pass1 and pass2
            if not why:
                fails += 1
            if verbose or not why:
                print(f"{'ok  ' if why else 'BAD '} {spec['name']:<24} "
                      f"want={spec['want']:<23} got={dict(got)}  "
                      f"mutated={dict(got2)}"
                      + ("" if pass1 else "  <- did not raise the wanted grade")
                      + ("" if pass2 else "  <- SURVIVED its own mutation"))
                if not why:
                    print(f"     doc: {spec['doc']!r}\n     mut: {mut!r} -> {mdoc!r}")

    # ---- invariants that are BEHAVIOUR, not grades -------------------
    n_inv = 3
    with tempfile.TemporaryDirectory(dir=str(SCRATCH)) as td:
        root = Path(td) / "repo"
        (root / "docs").mkdir(parents=True)
        _mk(root, HEAP, UNIT[0])
        d = root / "docs" / "T.md"
        d.write_text("A bare cite: `%s:3` and a wrong one: `%s:2` `MARKER-NOT-PRESENT`.\n"
                     % (HEAP, HEAP), encoding="utf-8")
        cites = extract("doc", d, "docs/T.md")
        for c in cites:
            grade(c, Target(root))
        tally = Counter(c.grade for c in cites)
        checks = [
            ("a wrong ANCHOR-MISSING fails the DEFAULT run",
             _rc(tally, strict=False) == 1, ""),
            ("NO-ANCHOR alone does NOT fail the default run",
             _rc(Counter({"NO-ANCHOR": 9}), strict=False) == 0, ""),
            ("--strict makes NO-ANCHOR fail",
             _rc(Counter({"NO-ANCHOR": 9}), strict=True) == 1, ""),
        ]
        for label, ok, _ in checks:
            if not ok:
                print(f"BAD  {label}")
                fails += 1
            elif verbose:
                print(f"ok   {label}")

    # --fix is a dry run: the file must be byte-identical afterwards, and the
    # proposal must be printed. A --fix that edits is a --fix that launders.
    with tempfile.TemporaryDirectory(dir=str(SCRATCH)) as td:
        root = Path(td) / "repo"
        (root / "docs").mkdir(parents=True)
        _mk(root, HEAP, UNIT[0])
        d = root / "docs" / "T.md"
        body = f"The marker is at `{HEAP}:4` `MARKER-ALPHA`.\n"
        d.write_text(body, encoding="utf-8")
        before = d.read_bytes()
        cites = extract("doc", d, "docs/T.md")
        for c in cites:
            grade(c, Target(root))
        fixtext = _print_fix(cites)
        if d.read_bytes() != before:
            print("BAD  grading or --fix WROTE to the file; it is read-only")
            fails += 1
        elif f"{HEAP}:7" not in fixtext:
            print(f"BAD  --fix did not print the corrected line: {fixtext!r}")
            fails += 1
        elif verbose:
            print("ok   --fix is a dry run: file unchanged, correction printed")

    n = len(SYNTH) + n_inv
    print(f"selftest: {n} cases, {fails} unexpected")
    print("  each case carries the grade it must raise, the grades it must NOT, "
          "and a mutation that removes the fact it asserts -- a case that "
          "survives its own mutation is reported BAD, not passed.")
    return 1 if fails else 0


def _rc(tally, strict=False):
    fatal = list(UNRECOVERABLE) + (list(STRICT_EXTRA) if strict else [])
    return 1 if any(tally[g] for g in fatal) else 0


def main():
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("paths", nargs="*", type=Path,
                    help="subtrees or files to read (default: the whole repo)")
    ap.add_argument("--strict", action="store_true",
                    help="also exit 1 on ANCHOR-DRIFT, AMBIGUOUS and NO-ANCHOR")
    ap.add_argument("--json", action="store_true", help="machine-readable dump")
    ap.add_argument("--fix", action="store_true",
                    help="DRY RUN: print paste-ready corrections for ANCHOR-DRIFT. "
                         "Never writes a file.")
    ap.add_argument("--window", type=int, default=2,
                    help="lines either side of the cited range that still count as "
                         "ANCHOR-OK (default 2)")
    ap.add_argument("--max-stream", type=int, default=Target.MAX_STREAM,
                    help="MB; a citation target larger than this is reported "
                         "BOUNDED-SKIP instead of being read (build/ holds "
                         "9.9 GB of soak logs, one of them 909 MB)")
    ap.add_argument("--selftest", action="store_true", help="synthetic cases, run and exit")
    ap.add_argument("-v", "--verbose", action="store_true", help="selftest detail")
    a = ap.parse_args()
    if a.selftest:
        return selftest(a.verbose)
    roots = a.paths or [REPO]
    if not any(containers([r]) for r in roots):
        print("cite_check: no documents found", file=sys.stderr)
        return 2
    return run(roots, window=a.window, strict=a.strict, want_json=a.json,
               do_fix=a.fix, max_stream=a.max_stream << 20)


if __name__ == "__main__":
    sys.exit(main())
