#!/usr/bin/env python3
"""Mitigation registry audit -- the machine behind rule 1 ("a mitigation must be
labelled and cited at its file:line").

PROGRAM_GUIDE sec 7 is the registry of host short-circuits that keep the boot
alive. It is prose, maintained by hand, and it drifts: a short-circuit gets
deleted from src/ but stays in sec 7, or a new one lands in src/ and nobody adds
it. Either way the next session reads a registry that lies about the tree.

This tool diffs the two sides, classifying src/ tokens by suffix so that
observability is not mistaken for life-support:

  MITIGATION-shaped (`-SKIP`, `-GATE`, `-SC`, `-FIX`, `-SERVE`, `-RET`, ...)
      changes guest behaviour. Missing from sec 7 -> UNDOCUMENTED, actionable.
  CENSUS-shaped (`-CENSUS`, `-DUMP`, `-SAMPLE`, `-ALLOC`, `-HIT`, ...)
      only logs state. Counted, not reported as violations.
  other: unclassified, counted only.

  sec 7 label with no occurrence in src/      -> STALE (documented, not in tree)
  MITIGATION-shaped src/ label not in sec 7   -> UNDOCUMENTED (in tree, not registered)

Labels are recognised by shape: hyphenated uppercase (`KDELAY-SC`,
`BLIT-OOB-GUARD`, `REBASE-POISON`) or all-caps of five letters or more
(`DISCCHK`). That shape rule is what keeps prose words like `SEH`, `pow2` and
`NtReleaseSemaphore` out of the label set. Suffix classification is a heuristic
on the name, so each UNDOCUMENTED entry must still be read to confirm it is a
behaviour change rather than a log line -- but the suffixes are the project's own
naming convention, and on the 2026-09-20 tree it separated 65 mitigations from
64 census markers cleanly.

Exit status is 1 when either side has entries, so this can gate a commit.

Usage:
    python tools/mitigation_audit.py                 # stale + undocumented mitigations
    python tools/mitigation_audit.py --tiers         # also list census/other tokens
    python tools/mitigation_audit.py --label KDELAY-SC
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from addr_owners import REPO, SKIP_DIRS, SRC, SRC_SUFFIXES, strip_comments  # noqa: E402

GUIDE = REPO / "docs" / "PROGRAM_GUIDE.md"
SEC7_HEADING = "## 7. Short-circuits in tree"

# Hyphenated uppercase, or a run of five or more capitals. Both must start with a
# letter so hex literals (`0x82839F70`) and commit hashes never qualify. A `/`
# is allowed only inside a hyphenated group so that the sec 7 shorthand
# `INFLATE-SKIP/EMPTY/PENDING` arrives whole and can be expanded into the three
# labels src/ actually uses.
LABEL = re.compile(r"\b(?:[A-Z][A-Z0-9]*(?:-[A-Z0-9/]+)+|[A-Z]{5,})\b")
# Words that are shaped like labels but are ordinary prose or guest API names.
NOT_LABELS = {
    "INSERT", "DELETE", "UPDATE", "SELECT", "RETURN", "SHADER", "SHADERS",
    "TEXTURE", "STREAM", "DEVICE", "MEMORY", "ARCHIVE", "PRELOAD", "FATAL",
    "ASSERT", "WINDOWS", "THREAD", "SEMAPHORE", "NULL", "TRUE", "FALSE",
    "UINT", "INT", "SIZE", "COUNT", "ERROR", "WARNING", "INFO", "DEBUG",
    "TRACE", "NOT", "AND", "THE", "WITH", "FROM", "THIS", "THAT", "WERE",
    "STAYS", "TILL", "CLEAN", "NEVER", "PATCH", "HOST", "GUEST", "FORCE",
}


# Suffix vocabulary the project itself uses. A mitigation-shaped name means the
# site probably changes guest behaviour; a census-shaped name means it probably
# only logs. Classification is by name, so it is a triage aid, not a verdict.
MITIGATION_SUFFIX = (
    "-SC", "-SKIP", "-GATE", "-FIX", "-FORCE", "-POISON", "-FALLBACK", "-CLAMP",
    "-SUBST", "-SERVE", "-HYDRATE", "-PRE", "-RET", "-DEAD", "-STUB", "-BYPASS",
    "-GUARD", "-READY", "-PARK", "-NOOP", "-SOFT", "-FAKE", "-BAKE", "-LIE",
    "-PATCH", "-HACK", "-REBUILD", "-EMPTY", "-PENDING", "-RETRY", "-BAIL",
    "-ACK", "-ZERO",
)
CENSUS_SUFFIX = (
    "-CENSUS", "-DUMP", "-SAMPLE", "-PROBE", "-TRACE", "-STATS", "-COUNT",
    "-ALLOC", "-FREE", "-HIT", "-MISS", "-REQ", "-FRAME", "-WORKER", "-MEM",
    "-SLOT", "-CALLER", "-ENTRY", "-EXIT", "-INFO", "-LOG",
)


def classify_token(tok: str) -> str:
    if tok.endswith(MITIGATION_SUFFIX):
        return "mitigation"
    if tok.endswith(CENSUS_SUFFIX):
        return "census"
    return "other"


def section7(path: Path) -> str:
    if not path.exists():
        return ""
    text = path.read_text(encoding="utf-8", errors="replace")
    start = text.find(SEC7_HEADING)
    if start < 0:
        print(f"error: {path} has no '{SEC7_HEADING}' section", file=sys.stderr)
        sys.exit(2)
    end = text.find("\n## ", start + 1)
    return text[start:end if end > 0 else len(text)]


def expand_family(label: str) -> list[str]:
    """`INFLATE-SKIP/EMPTY/PENDING` -> the three full labels."""
    if "/" not in label:
        return [label]
    head, *tails = label.split("/")
    stem = head.rsplit("-", 1)[0] if "-" in head else head
    out = [head]
    for t in tails:
        out.append(f"{stem}-{t}" if "-" in head else f"{head}{t}")
    return out


def labels_in(text: str) -> dict[str, int]:
    found: dict[str, int] = {}
    for m in LABEL.finditer(text):
        tok = m.group(0)
        if tok in NOT_LABELS or tok.isdigit():
            continue
        for part in expand_family(tok):
            found.setdefault(part, m.start())
    return found


def scan_src() -> tuple[dict[str, list[tuple[Path, int]]], dict[str, list[tuple[Path, int]]]]:
    """Return (code_tokens, comment_only_tokens) -> [(path, line)]."""
    code: dict[str, list[tuple[Path, int]]] = defaultdict(list)
    every_comment: dict[str, list[tuple[Path, int]]] = defaultdict(list)
    for path in sorted(SRC.rglob("*")):
        if path.suffix not in SRC_SUFFIXES:
            continue
        if SKIP_DIRS & set(path.relative_to(REPO).parts):
            continue
        try:
            raw = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        live = strip_comments(raw)
        for tok, off in labels_in(live).items():
            code[tok].append((path, live.count("\n", 0, off) + 1))
        for tok, off in labels_in(raw).items():
            every_comment[tok].append((path, raw.count("\n", 0, off) + 1))
    # A token that appears in code anywhere is a code token; only report comment
    # sites for tokens that never appear in code at all.
    comments = {t: s for t, s in every_comment.items() if t not in code}
    return code, comments


def show(sites: list[tuple[Path, int]], limit: int = 4) -> str:
    out = []
    for path, line in sites[:limit]:
        try:
            rel = path.relative_to(REPO).as_posix()
        except ValueError:
            rel = str(path)
        out.append(f"{rel}:{line}")
    if len(sites) > limit:
        out.append(f"(+{len(sites) - limit} more)")
    return "  ".join(out)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--label", help="look up one label on both sides")
    ap.add_argument("--tiers", action="store_true",
                    help="also list the census-shaped and unclassified tokens")
    ap.add_argument("--comments", action="store_true",
                    help="also report tokens that appear only in comments")
    ap.add_argument("--limit", type=int, default=4, help="sites shown per label")
    args = ap.parse_args()

    doc_labels = labels_in(section7(GUIDE))
    code, comments = scan_src()

    if args.label:
        tok = args.label.upper()
        print(f"\n{tok}   [{classify_token(tok)}-shaped]")
        print(f"  in {GUIDE.name} sec 7: {'yes' if tok in doc_labels else 'NO'}")
        print(f"  in src/ code:        {show(code[tok], args.limit) if code.get(tok) else 'none'}")
        if comments.get(tok):
            print(f"  in src/ comments:    {show(comments[tok], args.limit)}")
        return 0

    tiers: dict[str, list[str]] = defaultdict(list)
    for tok in code:
        tiers[classify_token(tok)].append(tok)
    for k in tiers:
        tiers[k].sort()

    stale = sorted(t for t in doc_labels if t not in code and t not in comments)
    undoc = [t for t in tiers["mitigation"] if t not in doc_labels]

    print("# mitigation registry audit")
    print(f"#   {GUIDE.name} sec 7: {len(doc_labels)} registered labels")
    print(f"#   src/: {len(code)} label-shaped tokens -- "
          f"{len(tiers['mitigation'])} mitigation-shaped, "
          f"{len(tiers['census'])} census-shaped, {len(tiers['other'])} unclassified")
    print()

    if stale:
        print(f"STALE -- registered in sec 7 but absent from src/ ({len(stale)})")
        for t in stale:
            print(f"  {t}")
        print("  -> removed or renamed; a stale label tells the next session that")
        print("     life-support is still there when it is not.\n")
    else:
        print("STALE -- none: every sec 7 label still appears in src/\n")

    if undoc:
        print(f"UNDOCUMENTED MITIGATIONS -- in src/, not registered in sec 7 ({len(undoc)})")
        for t in undoc:
            print(f"  {t:<30} {show(code[t], args.limit)}")
        print(f"\n  sec 7 registers {len(doc_labels)} short-circuits; src/ carries "
              f"{len(tiers['mitigation'])} mitigation-shaped labels.")
        print("  The do-not-stack rule is enforced against sec 7, so anything absent")
        print("  from it can be stacked on without anyone noticing. Suffix shape is a")
        print("  triage aid: read each site before treating it as a behaviour change.\n")
    else:
        print("UNDOCUMENTED MITIGATIONS -- none: sec 7 covers every "
              "mitigation-shaped label in src/\n")

    if args.tiers:
        for name in ("census", "other"):
            extra = [t for t in tiers[name] if t not in doc_labels]
            print(f"{name.upper()}-SHAPED tokens not in sec 7 ({len(extra)})")
            for t in extra:
                print(f"  {t:<30} {show(code[t], args.limit)}")
            print()

    if args.comments:
        extra = sorted(t for t in comments if t not in doc_labels)
        print(f"COMMENT-ONLY tokens not in sec 7 ({len(extra)})")
        for t in extra:
            print(f"  {t:<30} {show(comments[t], args.limit)}")
        print()

    return 1 if (stale or undoc) else 0


if __name__ == "__main__":
    sys.exit(main())
