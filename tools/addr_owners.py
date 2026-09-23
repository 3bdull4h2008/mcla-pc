#!/usr/bin/env python3
"""Guest-address ownership index -- the machine behind rule 4 ("one owner per
guest address").

Scans src/ and config/mcla_xenonrecomp.toml for every site that claims a guest
address and reports addresses claimed by conflicting owners. A duplicate claim
is silent at build time and last-one-wins at runtime, which is how a hook ends
up dead without anyone noticing.

Recognised sites:
    PPC_FUNC(sub_X) { ... }             override  the host body -- CLAIMS
    GUEST_FUNCTION_HOOK(sub_X, Name)    hook      binds a host function -- CLAIMS
    SetFunction(0xX, func)              set       runtime dispatch override -- CLAIMS
    PPC_FUNC_IMPL(__imp__sub_X);        orig      declares the *generated* body so an
                                                  override can tail-call it -- no claim
    PPC_FUNC(sub_X);                    fwd       forward declaration -- no claim
    GetFunction(0xX)                    get       reads the current owner -- no claim
    config/*.toml  address = 0xX        toml      codegen input -- no claim

The `{`-vs-`;` distinction is what separates a real override from a declaration;
without it every `PPC_FUNC_IMPL(...);` extern looks like a second owner.

Two claims are only a violation when they genuinely conflict. The
save-original-then-hook idiom --

    SetFunction(A, plain);   g_orig = GetFunction(A);   SetFunction(A, hk_plain);

-- is deliberate and is reported as a note, not a violation. Claims in
*different files* are a violation, because nothing in the tree states which one
wins; they usually turn out to be guarded by mutually exclusive bisect modes,
and that guard needs writing down. `--gates <addr>` prints each claim site's
candidate conditions verbatim so the guard can be read rather than guessed at,
and the boot log decides which installer actually ran. Resolved cases are
recorded in `docs/ROOT_CAUSE_VALIDATION.md` (0x827BD6E4 / VdSwap -> F-053).

Usage:
    python tools/addr_owners.py                      # violations + summary
    python tools/addr_owners.py --check 0x822FBAF8   # who owns this address
    python tools/addr_owners.py --gates 0x827BD6E4   # each claim's gate text
    python tools/addr_owners.py --notes              # include advisory notes
    python tools/addr_owners.py --tsv build/addr_owners.tsv
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

# (kind when followed by '{', kind when followed by ';', regex)
BODY_PATTERNS = [
    ("override", "orig",
     re.compile(r"PPC_FUNC_IMPL\(\s*" + ADDR + r"\s*\)\s*(\{|;)")),
    ("override", "fwd",
     re.compile(r"\bPPC_FUNC\(\s*" + ADDR + r"\s*\)\s*(\{|;)")),
]
PLAIN_PATTERNS = [
    ("hook", re.compile(r"GUEST_FUNCTION_HOOK\(\s*" + ADDR + r"\s*,\s*" + NAME)),
    ("set", re.compile(r"\bSetFunction\(\s*(?:0x)?" + ADDR + r"\s*,\s*" + NAME)),
    ("get", re.compile(r"\bGetFunction\(\s*(?:0x)?" + ADDR + r"\s*\)")),
]

TOML_ADDR = re.compile(r"^\s*(?:jump_)?address\s*=\s*0x([0-9A-Fa-f]{6,8})")
TOML_SECTION = re.compile(r"^\s*\[\[?(.+?)\]\]?\s*$")

# Named XEX imports (`PPC_FUNC(__imp__VdSwap) { ... }`) are guest functions too,
# but their address comes from the import table at runtime, so they cannot be
# indexed by hex. They are indexed by symbol and cross-referenced against hex
# claims whose bound host function name shares the whole symbol -- that is how
# the VdSwap triple-owner at 0x827BD6E4 (imports.cpp:3469 + native_renderer.cpp
# :254 + patches.cpp:678) becomes visible.
#
# `PPC_FUNC_IMPL(hk_foo) { ... }` looks similar but is the *definition of a host
# function*, not a claim on a guest address; it is indexed as `body:` so a `set`
# or `hook` binding can be traced to where it is implemented.
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

CLAIMING = {"override", "hook", "set", "sym-override", "sym-hook"}


def strip_comments(text: str) -> str:
    """Blank out // and /* */ comments, preserving offsets and newlines.

    String literals are left intact so that addresses inside log format strings
    are still visible; the patterns above all require a macro call shape, so
    plain prose cannot produce a false owner.
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
    return f"0x{int(addr, 16):08X}"


HEX_TAIL = re.compile(r"(?:sub_)?([0-9A-Fa-f]{6,8})(?:_|$)")


def tokens(name: str) -> set[str]:
    """Lowercase identifier words, split only on `_` and `:`.

    Deliberately does NOT split camelCase: sub-word matching made this
    cross-check useless (159 "overlaps", e.g. ExCreateThread vs
    SetThreadNameImpl agreeing on the word "thread"). Whole-symbol agreement is
    the only signal precise enough to be worth printing.
    """
    return {t for t in (p.lower() for p in re.split(r"[_:]+", name))
            if len(t) > 2 and t not in STOP_TOKENS}


def import_symbol(name: str) -> str:
    """`__imp__VdSwap` -> `VdSwap` so it can be compared against host names."""
    return re.sub(r"^__imp__+", "", name).lstrip("_") or name


def scan_source(path: Path) -> list[Owner]:
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
                    name = label
            out.append(Owner(kind, key, name or label, path,
                             text.count("\n", 0, m.start()) + 1, m.start()))
    return out


def scan_toml(path: Path) -> list[Owner]:
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


MAP_ROW = re.compile(r"\{\s*(0x[0-9A-Fa-f]{6,8})\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\}")


def scan_mapping(path: Path) -> list[Owner]:
    """The generated dispatch table is the authoritative address -> body map.

    `SKIP_DIRS` excludes `generated/` so this tool cannot mis-parse 176 TUs, but
    that also hid the one file that decides who owns a guest address:
    `ppc_func_mapping.cpp` maps e.g. `{ 0x827BDC64, __imp__XamInputGetState }`.
    Without it, `--check` reported that import slot as "unclaimed" and a new
    `SetFunction` there would have looked legal while silently shadowing the
    real implementation (F-092).
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
    # Fallback only: the generated table row is reported when nothing in src/
    # or config/ claims the address, so an ordinary src hook still reads as
    # itself rather than as a src claim + a table row pair.
    claimed = {o.addr for o in owners}
    for o in scan_mapping(REPO / "generated" / "ppc_xenon"
                          / "ppc_func_mapping.cpp"):
        if o.addr not in claimed:
            claimed.add(o.addr)
            owners.append(o)
    return owners


def is_hook_idiom(hits: list[Owner]) -> bool:
    """True when the `set` claims are the save-original-then-hook idiom."""
    sets = [o for o in hits if o.kind == "set"]
    gets = [o for o in hits if o.kind == "get"]
    if len(sets) < 2 or len({o.path for o in sets}) != 1:
        return False
    lo, hi = min(o.off for o in sets), max(o.off for o in sets)
    return any(lo < g.off < hi for g in gets)


def classify(hits: list[Owner]) -> tuple[list[str], list[str]]:
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
    the same process. This walks up to the nearest column-0 line (a crude
    enclosing-statement anchor) and returns every loop/branch/return line below
    it, so the reader can see whether a `BisectGroupEnabled` or `renderer_mode`
    early-return stands between the anchor and the claim. The tool deliberately
    does not decide reachability: a C++ gate analyzer that quietly concluded
    "these two cannot co-fire" would hide a rule-4 bug the first time it was
    wrong. What settles it is the boot log line the installer itself prints.
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
        # Column-0 noise that is not a definition: blank, preprocessor, lone
        # braces, `else`, access labels, namespace/extern closers.
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

    Matched on whole identifier words only, so `sym:VdSwap` pairs with
    `Hooked_VdSwap` and `hk_vdswap_observer` but `sym:ExCreateThread` does not
    pair with `SetThreadNameImpl`. Still a heuristic -- the import table resolves
    the real address at runtime -- so this is a lead to confirm, not a verdict.
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
            # so `--check 0x827BD6E4` also shows `PPC_FUNC(__imp__VdSwap)`.
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
            if not hits:
                print("  (unclaimed in src/ and config/ -- if it shows up in a log "
                      "it is guest code running unhooked)")
            if args.gates:
                report_gates(raw, hits + related)
            rc |= bool(violations)
        return int(rc)

    bad, noted = [], []
    for addr, hits in sorted(index.items()):
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
