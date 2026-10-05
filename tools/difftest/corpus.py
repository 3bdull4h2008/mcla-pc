"""Parse Xenia's PPC codegen corpus (.research/xenia/src/xenia/cpu/ppc/testing).

This is a NEW tool for the differential harness in tools/difftest/.  It does not
modify anything in .research/ -- it only reads the corpus.

The corpus is the reference side of the differential test.  It is not ours: it
is Xenia's own hand-written codegen suite, carrying the raw PowerPC machine
words (`` .long 0x...``) next to the expected architectural register state
(``#_ REGISTER_OUT``).  For the VMX128 opcodes the words are hand-coded
*because binutils could not assemble them at all* -- see the header comment of
instr_vupkd3d128.s.  That makes it the most trustworthy reference available
offline: a third party's encoding, not our re-derivation of one.

Decodability
------------
Upstream assembles the corpus with a custom binutils build that is not in this
tree, and there is no working web access to fetch one.  We therefore only accept
a test case when *every one of its machine words appears literally in the file
as a ``.long``*, plus the two pseudo-ops ``blr`` and ``nop``.  Nothing is
re-encoded from our own understanding of the PowerPC encoding: an instruction
we cannot lift verbatim is a test we skip, and we report the skip count.
"""

from __future__ import annotations

import os
import re
from dataclasses import dataclass, field

# The only non-.long tokens we are willing to lift.  Both are pinned to the
# encodings that the corpus itself and generated/ppc_xenon/ use, and are
# cross-checked by tools/ppc_disasm.py -- see check_pseudo_ops().
PSEUDO_OPS = {
    "blr": 0x4E800020,
    "nop": 0x60000000,
}

LONG_RE = re.compile(r"^\s*\.long\s+(0x[0-9A-Fa-f]+|\d+)\s*$")
LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*$")
REG_IN_RE = re.compile(r"^#_\s*REGISTER_IN\s+(\S+)\s+(.+?)\s*$")
REG_OUT_RE = re.compile(r"^#_\s*REGISTER_OUT\s+(\S+)\s+(.+?)\s*$")
MEM_IN_RE = re.compile(r"^#_\s*MEMORY_IN\s+(\S+)\s+(.+?)\s*$")
MEM_OUT_RE = re.compile(r"^#_\s*MEMORY_OUT\s+(\S+)\s+(.+?)\s*$")
PSEUDO_RE = re.compile(r"^\s*([a-z][a-z0-9.]*)\s*$")


@dataclass
class Case:
    """One `test_*` block: its words, its inputs, its expected outputs."""
    suite: str
    name: str
    words: list = field(default_factory=list)          # raw BE PPC words
    reg_in: dict = field(default_factory=dict)          # "r3" / "v3" -> value
    reg_out: dict = field(default_factory=dict)
    mem_in: dict = field(default_factory=dict)
    mem_out: dict = field(default_factory=dict)
    skipped: str = None      # why this case is unusable, or None

    @property
    def usable(self):
        return self.skipped is None and bool(self.words)


def _parse_reg(reg: str, value: str):
    """Normalise a REGISTER_IN/OUT annotation into a python value.

    Vector registers use Xenia's `[w3, w2, w1, w0]` hex-word form; scalars are a
    plain integer or an `0x...` hex.  Floats appear as `1.0f` / `nan` /
    `-1.5f`; those are left as strings for the generator to hand to strtof.
    """
    reg = reg.strip()
    v = value.strip()
    if reg.startswith("v"):
        if not (v.startswith("[") and v.endswith("]")):
            return None
        parts = [p.strip() for p in v[1:-1].split(",")]
        if len(parts) != 4:
            return None
        try:
            return [int(p, 16) for p in parts]
        except ValueError:
            return None
    # r<N> / f<N> : integer (decimal or 0x hex).  Reject anything non-integer so
    # we never guess at a float literal.
    try:
        return int(v, 0)
    except ValueError:
        return None


def _parse_mem(value: str):
    """MEMORY_IN/OUT: a run of hex byte pairs, e.g. `1a2b3c4d`."""
    v = value.strip()
    if len(v) % 2 or not re.fullmatch(r"[0-9A-Fa-f]+", v):
        return None
    return [int(v[i:i + 2], 16) for i in range(0, len(v), 2)]


def parse_suite(path: str):
    """Parse one .s corpus file into Case objects (usable and skipped alike)."""
    suite = os.path.splitext(os.path.basename(path))[0]
    cases = []
    cur = None
    body_words = []        # words since the current label
    phase = "body"         # body | after_regs
    reg_in = {}
    reg_out = {}
    mem_in = {}
    mem_out = {}
    bad = []               # reasons the current case cannot be lifted

    def flush():
        if cur is None:
            return
        c = Case(suite=suite, name=cur, words=list(body_words),
                 reg_in=dict(reg_in), reg_out=dict(reg_out),
                 mem_in=dict(mem_in), mem_out=dict(mem_out))
        if bad:
            c.skipped = "; ".join(sorted(set(bad)))
        elif not c.words:
            c.skipped = "no instructions"
        elif not c.reg_out:
            # e.g. instr_frsqrte.s, whose annotations are commented out with
            # "# _" (note the space) because the accuracy is CPU-dependent.
            # Counting it as a pass would be a vacuous green: nothing is
            # actually compared.  Refuse to call it a test.
            c.skipped = "no REGISTER_OUT annotation (case disabled in corpus)"
        cases.append(c)

    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            line = raw.split("#_")[0] if False else raw
            s = raw.rstrip("\n")
            # strip trailing comment (a ';' or '#' comment), but never touch the
            # "#_" annotation marker itself
            # A line is either an annotation ("#_ REGISTER_OUT ...") or code.
            # Split on the FIRST "#_": everything after it is the annotation,
            # everything before it is (usually empty) code.  Getting this
            # backwards silently drops every REGISTER_OUT and makes every case
            # vacuously pass, so the assertion below is deliberate.
            if "#_" in s:
                before, _, after = s.partition("#_")
                ann = "#_" + after
                s = before
            else:
                ann = ""
            body = s
            for cch in ("#", ";"):
                idx = body.find(cch)
                if idx >= 0:
                    body = body[:idx]
            body = body.strip()

            m = LABEL_RE.match(body)
            if m and m.group(1).startswith("test_"):
                flush()
                cur, body_words, phase = m.group(1), [], "body"
                reg_in, reg_out, mem_in, mem_out, bad = {}, {}, {}, {}, []
                continue

            if not ann:
                if not body or cur is None:
                    continue
                m = LONG_RE.match(body)
                if m:
                    if phase == "body":
                        body_words.append(int(m.group(1), 0) & 0xFFFFFFFF)
                    else:
                        # a .long after the REGISTER_OUT block: still code, but
                        # Xenia's generator expects it before the checks
                        body_words.append(int(m.group(1), 0) & 0xFFFFFFFF)
                    continue
                m = PSEUDO_RE.match(body)
                if m and m.group(1) in PSEUDO_OPS:
                    body_words.append(PSEUDO_OPS[m.group(1)])
                    continue
                if body:
                    bad.append(f"undecodable instruction {body!r}")
                continue

            # ann still carries its leading "#_"; drop it before splitting the
            # key from the value, or the key parses as "#_" and every
            # REGISTER_OUT is silently dropped (which makes every case vacuously
            # "pass" -- a false green that is worse than no test at all).
            key, _, val = ann[2:].strip().partition(" ")
            val = val.strip()
            if key not in ("REGISTER_IN", "REGISTER_OUT", "MEMORY_IN", "MEMORY_OUT"):
                bad.append(f"unknown annotation {ann!r}")
                continue
            parts = val.split()
            reg = parts[0] if parts else ""
            if key == "REGISTER_IN":
                parsed = _parse_reg(reg, " ".join(parts[1:]))
                if parsed is None:
                    bad.append(f"unparsed REGISTER_IN {val!r}")
                else:
                    reg_in[reg] = parsed
                phase = "body"
            elif key == "REGISTER_OUT":
                parsed = _parse_reg(reg, " ".join(parts[1:]))
                if parsed is None:
                    bad.append(f"unparsed REGISTER_OUT {val!r}")
                else:
                    reg_out[reg] = parsed
                phase = "after_regs"
            elif key == "MEMORY_IN":
                parsed = _parse_mem("".join(parts[1:]))
                if parsed is None:
                    bad.append(f"unparsed MEMORY_IN {val!r}")
                else:
                    mem_in[reg] = parsed
            elif key == "MEMORY_OUT":
                parsed = _parse_mem("".join(parts[1:]))
                if parsed is None:
                    bad.append(f"unparsed MEMORY_OUT {val!r}")
                else:
                    mem_out[reg] = parsed
    flush()
    return cases


def load_corpus(corpus_dir: str):
    suites = {}
    allcases = []
    for fn in sorted(os.listdir(corpus_dir)):
        if not fn.endswith(".s"):
            continue
        cases = parse_suite(os.path.join(corpus_dir, fn))
        suites[fn[:-2]] = cases
        allcases.extend(cases)
    return suites, allcases


if __name__ == "__main__":
    import sys
    root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    d = os.path.join(root, ".research", "xenia", "src", "xenia", "cpu", "ppc", "testing")
    suites, cases = load_corpus(d)
    usable = [c for c in cases if c.usable]
    print(f"suites            : {len(suites)}")
    print(f"cases total       : {len(cases)}")
    print(f"cases decodable   : {len(usable)}")
    print(f"cases skipped     : {len(cases) - len(usable)}")
    print()
    # Which suites are fully decodable -- those are the ones we can run.
    full = [s for s, cs in suites.items() if cs and all(c.usable for c in cs)]
    print(f"suites 100% decodable: {len(full)}/{len(suites)}")
    for s in sorted(full):
        print(f"  {s:28s} {len(suites[s]):4d} cases  "
              f"{sum(len(c.words) for c in suites[s]):6d} insns")
    print()
    from collections import Counter
    reasons = Counter(c.skipped for c in cases if c.skipped)
    print("top skip reasons:")
    for r, n in reasons.most_common(12):
        print(f"  {n:4d}  {r[:110]}")
    sys.exit(0)
