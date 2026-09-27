#!/usr/bin/env python3
"""Guest-address ownership index -- the machine behind rule 4 ("one owner per
guest address").

Scans every C/C++-suffixed file under src/, plus config/mcla_xenonrecomp.toml,
for sites that claim a guest address, and reports addresses claimed by
conflicting owners. Only *literal* macro text is matched, so a hook installed
through a project macro (MCLA_BISECT_HOOK in src/gpu_device.cpp expands to
PPC_FUNC_IMPL(...) + PPC_FUNC(...)) is invisible here: the site counts this tool
prints are a floor, never a ceiling.

A duplicate SetFunction pair is silent at build time and the later registration
wins at runtime -- App::FunctionDispatcher::SetFunction in src/app.cpp assigns
m_functions[addr] and re-inserts the same address into the dispatch table --
which is how a hook ends up dead without anyone noticing.

Recognised sites:
    PPC_FUNC(sub_X) { ... }             override  the host body -- CLAIMS
    GUEST_FUNCTION_HOOK(sub_X, Name)    hook      binds a host function -- CLAIMS
    SetFunction(0xX, func)              set       runtime dispatch override -- CLAIMS
    PPC_FUNC_IMPL(__imp__sub_X);        orig      declares the *generated* body so an
                                                  override can tail-call it -- no claim
    PPC_FUNC(sub_X);                    fwd       forward declaration -- no claim
    GetFunction(0xX)                    get       reads the current owner -- no claim
    (config/mcla_xenonrecomp.toml)      toml:<sec>  `address = 0xX` or
                                                    `jump_address = 0xX` -- no claim
    (generated/ppc_xenon/               map         a row `{ 0xX, body }` -- no
     ppc_func_mapping.cpp)                          claim, and listed only while
                                                    src/ and the toml are silent

The `{`-vs-`;` distinction is what separates a real override from a declaration;
without it every `PPC_FUNC_IMPL(...);` extern looks like a second owner. Both hex
patterns key on that brace, so `PPC_FUNC_IMPL(sub_X) {` also reads as an
`override`, and both only match a *hex* name -- symbol-named forms are picked up
by SYMBOL_PATTERNS below.

Two claims are only a violation when they genuinely conflict. The
save-original-then-hook idiom --

    SetFunction(A, plain);   g_orig = GetFunction(A);   SetFunction(A, hk_plain);

-- is deliberate and is reported as a note, not a violation. `set` claims in
*different files* are a violation, because nothing in the tree states which one
wins; they usually turn out to be guarded by mutually exclusive bisect modes,
and that guard needs writing down. `--gates <addr>` prints each claim site's
candidate conditions verbatim so the guard can be read rather than guessed at,
and the boot log decides which installer actually ran. classify() itself does no
reachability analysis, so a pair a human already cleared keeps printing:
`0x827BD6E4` / VdSwap is exactly that case -- F-053 in
`docs/ROOT_CAUSE_VALIDATION.md` concluded its registration sites cannot co-fire,
yet the address still reports a cross-file violation on every run.

Usage:
    python tools/addr_owners.py                      # violations + summary
    python tools/addr_owners.py --check 0x822FBAF8   # who owns this address
    python tools/addr_owners.py --check VdSwap       # a symbol / host body name
    python tools/addr_owners.py --gates 0x827BD6E4   # each claim's gate text
    python tools/addr_owners.py --all                # append the full index
    python tools/addr_owners.py --notes              # include advisory notes
    python tools/addr_owners.py --tsv build/addr_owners.tsv

Exit status is 1 when a violation was found (in --check/--gates mode, for any of
the addresses looked up), 0 otherwise.
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
TOMLS = [REPO / "config" / "mcla_xenonrecomp.toml"]
SKIP_DIRS = {"generated", ".research", "build", ".git", ".qoder"}
SRC_SUFFIXES = {".h", ".hpp", ".cpp", ".cc", ".cxx", ".inl"}

ADDR = r"(?:__imp__)?(?:sub_)?([0-9A-Fa-f]{6,8})"
NAME = r"([A-Za-z_][\w:]*)"

# (kind when followed by '{', kind when followed by ';', regex). Both key on
# ADDR, i.e. a 6-8 digit hex name with an optional `sub_`/`__imp__` prefix -- a
# host-named `PPC_FUNC_IMPL(hk_foo) {` does not match here.
BODY_PATTERNS = [
    ("override", "orig",
     re.compile(r"PPC_FUNC_IMPL\(\s*" + ADDR + r"\s*\)\s*(\{|;)")),
    ("override", "fwd",
     re.compile(r"\bPPC_FUNC\(\s*" + ADDR + r"\s*\)\s*(\{|;)")),
]
# Address-shaped sites without a body: the binder macro and the two dispatcher
# calls. The `0x` prefix is optional on both of the latter. `get` is non-claiming
# -- reading the current owner is exactly what the save-then-hook idiom does.
PLAIN_PATTERNS = [
    ("hook", re.compile(r"GUEST_FUNCTION_HOOK\(\s*" + ADDR + r"\s*,\s*" + NAME)),
    ("set", re.compile(r"\bSetFunction\(\s*(?:0x)?" + ADDR + r"\s*,\s*" + NAME)),
    ("get", re.compile(r"\bGetFunction\(\s*(?:0x)?" + ADDR + r"\s*\)")),
]

# Line-based toml pass: a section header sets the label the next address line
# inherits, so the kind that reaches the index is `toml:<section>` (both
# `[[double]]` and `[single]` brackets are accepted by TOML_SECTION).
TOML_ADDR = re.compile(r"^\s*(?:jump_)?address\s*=\s*0x([0-9A-Fa-f]{6,8})")
TOML_SECTION = re.compile(r"^\s*\[\[?(.+?)\]\]?\s*$")

# Named XEX imports (`PPC_FUNC(__imp__VdSwap) { ... }`) are guest functions too,
# but their address comes from the import table at runtime, so they cannot be
# indexed by hex. They are indexed under `sym:<name>` and cross-referenced
# against hex claims whose bound host function name shares the whole symbol --
# that is how the VdSwap case at 0x827BD6E4 becomes visible: the named-import
# override in src/kernel/imports.cpp plus the two `SetFunction` sites in
# src/native_renderer.cpp and src/patches.cpp. File:line numbers are deliberately
# not quoted -- they have drifted once already -- `--check 0x827BD6E4` prints the
# current ones.
#
# `PPC_FUNC_IMPL(hk_foo) { ... }` looks similar but is the *definition of a host
# function*, not a claim on a guest address; it is indexed as `body:<name>` (or,
# for a body named after an address, under that address -- see scan_source) so a
# `set` or `hook` binding can be traced to where it is implemented.
IMPORT_SYM = r"(__imp__[A-Za-z0-9_]+|__xtl_[a-z]+)"
SYMBOL_PATTERNS = [
    ("sym-override", re.compile(r"\bPPC_FUNC\(\s*" + IMPORT_SYM + r"\s*\)\s*\{")),
    ("sym-hook", re.compile(r"GUEST_FUNCTION_HOOK\(\s*" + IMPORT_SYM + r"\s*,\s*" + NAME)),
    ("body", re.compile(r"\bPPC_FUNC_IMPL\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*\{")),
]
# Tokens too generic to imply two sites touch the same guest function.
STOP_TOKENS = {"sub", "hook", "hooked", "hk", "impl", "imp", "orig", "census",
               "guest", "host", "the", "fn", "func", "stub", "observer",
               "native", "patch", "ppc", "ctx", "base", "shim"}

# Kinds that assert ownership of the guest function. Everything else (`orig`,
# `fwd`, `get`, `toml:*`, `map`, `body`) is index context only: it shows up under
# --check and can never, on its own, make a violation.
CLAIMING = {"override", "hook", "set", "sym-override", "sym-hook"}


def strip_comments(text: str) -> str:
    """Blank out // and /* */ comments, preserving offsets and newlines.

    The preserving part is load-bearing: scan_source() reads its line numbers out
    of this same string (count the newlines before the match) and is_hook_idiom()
    orders sites by byte offset, so each blank has to be exactly as wide, and
    contain exactly as many newlines, as the text it replaced.

    String literals are copied out verbatim so an address inside a log format
    string stays visible; the patterns above all require a macro call shape, so
    plain prose cannot produce a false owner. Two consequences of the
    left-to-right scan, both accepted rather than handled: the comment test comes
    before the quote test, so a `//` inside a string (a URL, say) blanks the rest
    of that line, and `'` counts as a string delimiter too.
    """
    out: list[str] = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        nxt = text[i + 1] if i + 1 < n else ""
        if c == "/" and nxt == "/":
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c == "/" and nxt == "*":
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in text[i:j]))
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(text[i:j])
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


class Owner:
    __slots__ = ("kind", "addr", "name", "path", "line", "off")

    def __init__(self, kind: str, addr: str, name: str, path: Path, line: int, off: int):
        self.kind = kind
        self.addr = addr
        self.name = name
        self.path = path
        self.line = line
        self.off = off

    @property
    def where(self) -> str:
        try:
            rel = self.path.relative_to(REPO).as_posix()
        except ValueError:
            rel = str(self.path)
        return f"{rel}:{self.line}"

    def __str__(self) -> str:
        return f"{self.kind:<9} {self.name or '-':<32} {self.where}"


def norm(addr: str) -> str:
    """Canonical `0x%08X`. Raises ValueError on a non-hex string, which is how
    main() tells an address argument from a symbol argument."""
    return f"0x{int(addr, 16):08X}"


# The trailing hex inside a host function name: `hk_sub_82554E20` -> 82554E20.
# The `(?:_|$)` guard is what stops a 6-8 char hex run sitting *inside* a longer
# word from being read as an address.
HEX_TAIL = re.compile(r"(?:sub_)?([0-9A-Fa-f]{6,8})(?:_|$)")


def tokens(name: str) -> set[str]:
    """Lowercase identifier words, split only on `_` and `:`; words of two
    characters or fewer, and STOP_TOKENS, are dropped.

    Deliberately does NOT split camelCase: sub-word agreement made the symbol
    cross-check useless (it paired names as different as ExCreateThread and
    SetThreadNameImpl on the shared word "thread"). Agreement on a whole
    underscore-separated word is the only signal precise enough to print.
    """
    return {t for t in (p.lower() for p in re.split(r"[_:]+", name))
            if len(t) > 2 and t not in STOP_TOKENS}


def import_symbol(name: str) -> str:
    """`__imp__VdSwap` -> `VdSwap` so it can be compared against host names.
    Leading underscores are stripped with it, so a `__xtl_*` name keeps its
    suffix and loses only the `__`; the original is returned if that empties."""
    return re.sub(r"^__imp__+", "", name).lstrip("_") or name


def scan_source(path: Path) -> list[Owner]:
    """All the claim shapes above, applied to one file after comment-stripping.

    Line numbers are counted in the stripped text, which is why strip_comments()
    has to keep newlines. Note that `override`/`orig`/`fwd` sites carry no host
    name, so they can never take part in the symbol cross-matching that
    symbol_crosscheck() and the --check "related" list do."""
    try:
        text = strip_comments(path.read_text(encoding="utf-8", errors="replace"))
    except OSError:
        return []
    out: list[Owner] = []
    for on_body, on_semi, pat in BODY_PATTERNS:
        for m in pat.finditer(text):
            kind = on_body if m.group(2) == "{" else on_semi
            out.append(Owner(kind, norm(m.group(1)), "", path,
                             text.count("\n", 0, m.start()) + 1, m.start()))
    for kind, pat in PLAIN_PATTERNS:
        for m in pat.finditer(text):
            name = m.group(2) if m.lastindex and m.lastindex >= 2 else ""
            out.append(Owner(kind, norm(m.group(1)), name, path,
                             text.count("\n", 0, m.start()) + 1, m.start()))
    for kind, pat in SYMBOL_PATTERNS:
        for m in pat.finditer(text):
            sym = m.group(1)
            name = m.group(2) if m.lastindex and m.lastindex >= 2 else ""
            if kind == "body":
                # A host function definition, not a guest claim. Bodies named
                # after an address (`hk_sub_82554E20`) are indexed under that
                # address so `--check` shows where a binding is implemented.
                tail = HEX_TAIL.search(sym)
                if tail:
                    key, label = norm(tail.group(1)), sym
                else:
                    key, label = f"body:{sym}", sym
            else:
                key = f"sym:{import_symbol(sym)}"
                label = import_symbol(sym)
                if name == sym:
                    # Both capture groups read the same text; restate it as the
                    # bare symbol so the cross-check compares like with like.
                    # No site in src/ takes this branch today.
                    name = label
            out.append(Owner(kind, key, name or label, path,
                             text.count("\n", 0, m.start()) + 1, m.start()))
    return out


def scan_toml(path: Path) -> list[Owner]:
    """Line-based codegen pass: the last section header labels the address rows
    under it (`toml:<section>`), and `off` carries the line number rather than a
    byte offset. A missing file is not an error -- it returns nothing."""
    if not path.exists():
        return []
    out: list[Owner] = []
    section = "?"
    for i, line in enumerate(path.read_text(encoding="utf-8",
                                            errors="replace").splitlines(), 1):
        sm = TOML_SECTION.match(line)
        if sm:
            section = sm.group(1).strip()
            continue
        am = TOML_ADDR.match(line)
        if am:
            out.append(Owner(f"toml:{section}", norm(am.group(1)), "", path, i, i))
    return out


# One row of the generated table: `{ 0x827BDC64, __imp__XamInputGetState }`.
MAP_ROW = re.compile(r"\{\s*(0x[0-9A-Fa-f]{6,8})\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\}")


def scan_mapping(path: Path) -> list[Owner]:
    """The generated address -> body table, read as fallback context.

    This is the one ownership record that lives outside src/, and its absence was
    the blind spot: without it `--check` called an import slot "unclaimed", so a
    new `SetFunction` there looked legal while shadowing the body the generated
    table already registers (the `XamInputGetState` case, F-092).

    How the row is used is deliberately second-class, though: collect() keeps it
    only while no earlier site -- from src/ or the toml -- was indexed under that
    hex address, and `map` is not in CLAIMING, so a row can never be one half of a
    violation. Do not read it as "the table says X owns this" -- it says no source
    file claimed it.

    generated/ needs no exclusion here: collect() only walks src/, so the 176
    ppc_recomp.*.cpp TUs beside this file are never parsed. The `generated` entry
    in SKIP_DIRS is checked against the path parts of files found *under src/*,
    and no such directory exists there today; it is a guard, not the mechanism.
    """
    out: list[Owner] = []
    if not path.exists():
        return out
    try:
        text = path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return out
    line = 1
    pos = 0
    NL = chr(10)
    for m in MAP_ROW.finditer(text):
        line += text.count(NL, pos, m.start())
        pos = m.start()
        out.append(Owner("map", norm(m.group(1)), m.group(2), path, line,
                         m.start() - text.rfind(NL, 0, m.start())))
    return out


def collect() -> list[Owner]:
    owners: list[Owner] = []
    for path in sorted(SRC.rglob("*")):
        if path.suffix not in SRC_SUFFIXES:
            continue
        if SKIP_DIRS & set(path.relative_to(REPO).parts):
            continue
        owners.extend(scan_source(path))
    for t in TOMLS:
        owners.extend(scan_toml(t))
    # Fallback only: a generated table row survives when no earlier site was
    # indexed under the same hex key -- an src claim, an `orig`/`fwd` extern, a
    # toml address or an address-named host body. That keeps an ordinary src hook
    # reading as itself instead of as a claim + table row pair. Because the filter
    # is the hex key, a site recorded only as `sym:<name>` does not suppress the
    # row, and the first row for an address wins over later ones.
    claimed = {o.addr for o in owners}
    for o in scan_mapping(REPO / "generated" / "ppc_xenon"
                          / "ppc_func_mapping.cpp"):
        if o.addr not in claimed:
            claimed.add(o.addr)
            owners.append(o)
    return owners


def is_hook_idiom(hits: list[Owner]) -> bool:
    """True when the `set` claims are the save-original-then-hook idiom.

    Three conditions, all read off the byte offsets scan_source recorded: at least
    two `set` sites, every one of them in the same file, and at least one `get`
    strictly between the first and the last. A `get` outside that span does not
    count, so an overwrite that saves the original somewhere else still reports as
    a violation."""
    sets = [o for o in hits if o.kind == "set"]
    gets = [o for o in hits if o.kind == "get"]
    if len(sets) < 2 or len({o.path for o in sets}) != 1:
        return False
    lo, hi = min(o.off for o in sets), max(o.off for o in sets)
    return any(lo < g.off < hi for g in gets)


def classify(hits: list[Owner]) -> tuple[list[str], list[str]]:
    """The rule-4 verdict for one address: (violations, advisory notes).

    Only kinds in CLAIMING can raise a violation, and the violations it does raise
    are: more than one `override` body; more than one `set`, either from different
    files or in one file with no `get` between them; and `hook` beside any other
    claiming kind. Coexisting toml input and an address named by several toml
    sections are notes, not violations.

    What it does not report, by construction rather than oversight: two claiming
    kinds that are simply *different* -- the mixed-mechanism rule fires only when a
    plain hex `hook` is one of the kinds, so an `override` body plus a `set`, or a
    `sym-hook` plus a `sym-override`, passes silently -- and any address left with
    one claiming site or fewer. Nor does it judge reachability: two gated
    installers that cannot co-fire still read as a violation, which is exactly why
    --gates exists."""
    claims = sorted((o for o in hits if o.kind in CLAIMING), key=lambda o: o.off)
    tomls = [o for o in hits if o.kind.startswith("toml")]
    violations: list[str] = []
    notes: list[str] = []

    overrides = [o for o in claims if o.kind == "override"]
    if len(overrides) > 1:
        violations.append(f"{len(overrides)} PPC_FUNC host bodies for one address: "
                          + ", ".join(o.where for o in overrides))

    sets = [o for o in claims if o.kind == "set"]
    if len(sets) > 1:
        files = sorted({o.where.rsplit(":", 1)[0] for o in sets})
        names = sorted({o.name for o in sets})
        if len(files) > 1:
            violations.append(
                f"SetFunction in {len(files)} different files ({', '.join(files)}) "
                f"binding {', '.join(names)} -- unresolved: run --gates on this "
                f"address and read the boot log to see which installer fired")
        elif is_hook_idiom(hits):
            notes.append("save-original-then-hook idiom (GetFunction between the two "
                         "SetFunction calls) -- deliberate, single file")
        else:
            violations.append(f"SetFunction twice in one file with no GetFunction "
                              f"between them: {', '.join(o.where for o in sets)}")

    mixed = {o.kind for o in claims}
    if "hook" in mixed and len(mixed) > 1:
        violations.append("GUEST_FUNCTION_HOOK plus "
                          + "/".join(sorted(mixed - {"hook"}))
                          + " on the same address -- two independent binding "
                            "mechanisms claim one guest function")

    if tomls and claims:
        notes.append(f"codegen input ({', '.join(sorted({o.kind for o in tomls}))}) "
                     f"plus a host claim -- expected when hooking a recompiled "
                     f"function, but confirm the toml is still the intended owner")
    if len({o.kind for o in tomls}) > 1:
        notes.append("named by more than one toml section: "
                     + ", ".join(sorted({o.kind for o in tomls})))
    return violations, notes


GATEISH = re.compile(r"^\s*(?:\}\s*)?(?:else\s+)?(?:if|for|while|switch)\s*\(|\breturn\b")
MAX_GATE_LINES = 40


def candidate_gates(site: Owner) -> tuple[str, list[tuple[int, str]], bool]:
    """Verbatim text of the conditions that gate one claim -- NOT interpreted.

    Two claims on one address are only a real conflict if both sites can run in
    the same process. The mechanics: re-read the *raw* file, walk up from the
    claim to the first column-0 line that is not noise (that is the crude
    enclosing-statement anchor), then return every GATEISH line strictly between
    the anchor and the claim -- so a `BisectGroupEnabled` or `renderer_mode`
    early-return above the site is visible. Truncation keeps the last
    MAX_GATE_LINES, i.e. the ones nearest the claim.

    GATEISH is a shape test, not a parser: the branch/loop alternative is anchored
    to the line start (an optional `}` or `else` in front is allowed) while
    `return` matches anywhere in the line. And because the raw file is what gets
    scanned here -- unlike scan_source, which strips comments first -- a `return`
    inside a comment or a string prints as a gate too.

    The tool deliberately does not decide reachability: a C++ gate analyzer that
    quietly concluded "these two cannot co-fire" would hide a rule-4 bug the first
    time it was wrong. What settles it is the boot log line the installer itself
    prints.
    """
    try:
        lines = site.path.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return ("(unreadable)", [], False)
    idx = site.line - 1
    if not 0 <= idx < len(lines):
        return ("(line out of range)", [], False)
    anchor = ""
    start = 0
    for i in range(idx - 1, -1, -1):
        raw = lines[i]
        stripped = raw.strip()
        # Keep walking through anything that cannot start a definition: an
        # indented line (the usual case, since the claim sits inside a body), a
        # blank, a preprocessor line, a lone brace -- the `}` that closes a
        # namespace or an extern block -- `else`, access labels and case arms.
        if (raw[:1] in (" ", "\t", "") or stripped in ("}", "{", "};", "")
                or stripped.startswith(("#", "else", "public:", "private:",
                                        "protected:", "case ", "default:"))):
            continue
        anchor = f"{i + 1}: {stripped}"
        start = i + 1
        break
    gates = [(i + 1, lines[i].strip())
             for i in range(start, idx) if GATEISH.search(lines[i])]
    truncated = len(gates) > MAX_GATE_LINES
    if truncated:
        gates = gates[-MAX_GATE_LINES:]
    return (anchor or "(no column-0 anchor above the site)", gates, truncated)


def report_gates(addr: str, hits: list[Owner]) -> None:
    """One block per CLAIMING site -- non-claiming kinds are never shown -- sorted
    by file then offset, followed by the standing advice on how to settle the pair.
    Called for --gates only, and fed the same hits+related list --check printed."""
    claims = sorted((o for o in hits if o.kind in CLAIMING), key=lambda o: (o.path, o.off))
    print(f"\n{addr} -- candidate gates for {len(claims)} claiming site(s) "
          f"(verbatim, NOT interpreted)")
    for o in claims:
        anchor, gates, truncated = candidate_gates(o)
        print(f"\n  {o}")
        print(f"    enclosing: {anchor}")
        if truncated:
            print(f"    ... (showing the last {MAX_GATE_LINES} of the gate-shaped lines above)")
        for ln, text in gates:
            print(f"    {ln:>6}: {text}")
    if len(claims) >= 2:
        print("\n  Decide by evidence, not by reading: grep the newest build/*.log for the"
              "\n  log line each installer prints. A site whose message never appears did"
              "\n  not run, so the other owner is the live one and this is not a violation.")
    else:
        print("  (nothing to tie-break -- one or zero claiming sites at this address)")


def symbol_crosscheck(index: dict[str, list[Owner]]) -> list[tuple[str, list[Owner], list[Owner]]]:
    """Pair named-import owners with hex-address owners of the same guest function.

    Matched on whole `_`/`:`-separated words (tokens()), so `sym:VdSwap` pairs with
    `Hooked_VdSwap` and `hk_vdswap_observer` but `sym:ExCreateThread` does not pair
    with `SetThreadNameImpl`. Only the hex side needs a name, and only CLAIMING
    kinds qualify, so an `override` body of an address is invisible to this. The
    output is headed "overlaps", not violations: still a heuristic -- the import
    table resolves the real address at runtime -- so it is a lead to confirm, not a
    verdict.
    """
    hexed = [(a, hits) for a, hits in index.items()
             if not a.startswith(("sym:", "body:"))]
    out = []
    for sym_key, sym_hits in sorted(index.items()):
        if not sym_key.startswith("sym:"):
            continue
        want = tokens(sym_key[4:])
        if not want:
            continue
        matched = [o for _, hits in hexed for o in hits
                   if o.kind in CLAIMING and o.name and tokens(o.name) & want]
        if matched:
            out.append((sym_key[4:], sym_hits, matched))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", help="comma-separated guest addresses to look up")
    ap.add_argument("--gates", help="comma-separated addresses: print each claim site's "
                                     "candidate gating conditions verbatim")
    ap.add_argument("--all", action="store_true", help="print the full index")
    ap.add_argument("--notes", action="store_true", help="also print advisory notes")
    ap.add_argument("--tsv", type=Path, help="write addr/kind/name/where TSV here")
    args = ap.parse_args()

    owners = collect()
    index: dict[str, list[Owner]] = defaultdict(list)
    for o in owners:
        index[o.addr].append(o)

    if args.check or args.gates:
        rc = 0
        # Only args.check is read here, so with both flags given the loop -- and
        # the gate report inside it -- runs over the --check list.
        for raw in (a.strip() for a in (args.check or args.gates).split(",")):
            if not raw:
                continue
            keys = []
            try:
                keys.append(norm(raw))
            except ValueError:
                # Not hex -- treat it as a named import or host body symbol.
                keys += [f"sym:{import_symbol(raw)}", f"body:{raw}", raw]
            hits = [o for k in keys for o in index.get(k, [])]
            hits = sorted({(o.kind, o.where, o.name): o for o in hits}.values(),
                          key=lambda o: (o.path, o.off))
            # Pull in named-import owners that refer to the same guest function,
            # so `--check 0x827BD6E4` also shows `PPC_FUNC(__imp__VdSwap)`. The
            # join runs one way only: `--check VdSwap` prints the sym site and not
            # the hex addresses whose bound name shares the token.
            want = {t for o in hits if o.name for t in tokens(o.name)}
            seen = {(o.kind, o.where, o.name) for o in hits}
            related = [o for k, rh in index.items() if k.startswith("sym:")
                       for o in rh
                       if (tokens(k[4:]) & want) and (o.kind, o.where, o.name) not in seen]
            print(f"\n{raw} -- {len(hits)} site(s)"
                  + (f" + {len(related)} named-import site(s)" if related else ""))
            for o in hits:
                print(f"  {o}")
            for o in related:
                print(f"  {o}   (named import, same guest function)")
            violations, notes = classify(hits + related)
            for v in violations:
                print(f"  VIOLATION: {v}")
            for n in notes:
                print(f"  note: {n}")
            # A generated `map` row counts as a hit, so this prints only for an
            # address absent from src/, the toml and the generated table alike.
            if not hits:
                print("  (unclaimed in src/ and config/ -- if it shows up in a log "
                      "it is guest code running unhooked)")
            if args.gates:
                report_gates(raw, hits + related)
            rc |= bool(violations)
        return int(rc)

    bad, noted = [], []
    for addr, hits in sorted(index.items()):
        # An address is listed once: if classify() returned both a violation and
        # notes here, only the violation survives into the report.
        violations, notes = classify(hits)
        if violations:
            bad.append((addr, hits, violations))
        elif notes:
            noted.append((addr, hits, notes))

    kinds = defaultdict(int)
    for o in owners:
        kinds[o.kind.split(":")[0]] += 1
    claiming = sum(1 for o in owners if o.kind in CLAIMING)

    print("# guest-address ownership index")
    n_sym = sum(1 for a in index if a.startswith("sym:"))
    n_body = sum(1 for a in index if a.startswith("body:"))
    n_hex = len(index) - n_sym - n_body
    print(f"#   {len(owners)} sites, {claiming} of them claiming")
    print(f"#   {n_hex} hex guest addresses, {n_sym} named imports, "
          f"{n_body} unaddressed host bodies")
    print("#   " + "  ".join(f"{k}={v}" for k, v in sorted(kinds.items())))
    print()

    if bad:
        print(f"RULE-4 VIOLATIONS: {len(bad)} guest function(s) with conflicting owners\n")
        for addr, hits, violations in bad:
            print(addr)
            for v in violations:
                print(f"  VIOLATION: {v}")
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                print(f"    {o}")
            print()
    else:
        # Read this as "no conflict classify() could detect", not "every address is
        # owned": the bulk of the index keys carry zero claiming sites at all -- a
        # bare `map` row, or an `orig` extern with nothing over it -- and they too
        # fall through to this branch.
        print("RULE-4 VIOLATIONS: none -- every guest address has one owner\n")

    if args.notes and noted:
        print(f"advisory notes: {len(noted)} address(es)\n")
        for addr, hits, notes in noted:
            print(addr)
            for n in notes:
                print(f"  note: {n}")
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                print(f"    {o}")
            print()

    overlaps = symbol_crosscheck(index)
    if overlaps:
        print(f"NAMED-IMPORT / HEX-ADDRESS OVERLAPS: {len(overlaps)} "
              f"(heuristic -- confirm by hand)\n")
        for sym, sym_hits, matched in overlaps:
            files = {o.where.rsplit(":", 1)[0] for o in sym_hits + matched}
            print(f"{sym}  ({len(files)} files involved)")
            for o in sorted(sym_hits + matched, key=lambda o: (o.path, o.off)):
                print(f"    {o}")
            if len(files) > 1:
                print("    -> several files claim what is probably one guest "
                      "function; --gates shows each site's conditions, the log "
                      "shows which installer ran")
            print()

    if args.all:
        print("full index:")
        for addr, hits in sorted(index.items()):
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                print(f"{addr}\t{o.kind}\t{o.name}\t{o.where}")

    if args.tsv:
        args.tsv.parent.mkdir(parents=True, exist_ok=True)
        with args.tsv.open("w", encoding="utf-8", newline="") as fh:
            fh.write("address\tkind\tname\twhere\n")
            for addr, hits in sorted(index.items()):
                for o in sorted(hits, key=lambda o: (o.path, o.off)):
                    fh.write(f"{addr}\t{o.kind}\t{o.name}\t{o.where}\n")
        print(f"wrote {args.tsv} ({len(owners)} rows)")

    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
