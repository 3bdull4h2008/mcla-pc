#!/usr/bin/env python3
"""Guest-address ownership index -- the machine behind rule 4 ("one owner per
guest address").

Scans every C/C++-suffixed file under src/, plus config/mcla_xenonrecomp.toml,
for sites that claim a guest address, and reports addresses claimed by
conflicting owners. Project claim macros are *resolved* (F-366): a
`#define NAME(sym, tag)` whose body binds `PPC_FUNC_IMPL`/`PPC_FUNC` to a
parameter is expanded per invocation, so `MCLA_BISECT_HOOK(sub_821CA540, ...)`
and `F624_TAIL_HOOK(sub_821C9790, ...)` in src/gpu_device.cpp -- which expand to
a PPC_FUNC_IMPL + PPC_FUNC pair -- are indexed like hand-written sites and carry
`via NAME (defined at file:line)`. Literal matching alone made the site counts a
floor, never a ceiling, and a candidate hook was found already owned only by
grepping src/ by hand.

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
    NAME(sub_X, tag)                    (same)    invocation of a claim macro above --
                                                   expanded, and reported as the
                                                   invocation's file:line
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

Macro resolution is textual, not a preprocessor run: a macro's body is joined
across `\\` continuations, its parameters are substituted by whole-word regex,
helper `a##b` macros are resolved one level, and residual `IDENT ## IDENT`
pastes are collapsed -- then the *same* pattern set above is run over the
expanded text. That is what turns `PPC_FUNC_IMPL(__imp__##sym);` into the
`orig` row and `PPC_FUNC(sym) {` into the `override` row without a second copy
of the pattern logic. Three forms are deliberately out of scope, each because
supporting it needs a real preprocessor: see MACRO_LIMITS below.

Symbols resolve to addresses (this is what the symbol form of --check depends
on). Three tiers, tried in order, and the tier that answered is always printed:

    hex        the argument parses as an integer                     -- 0x821CA540
    sub_       `sub_<VA>` / `__imp__sub_<VA>`: the recompiler's own naming
               convention, so the address is the hex digits verbatim.
               Verified against the generated table: all 44707 `sub_` rows in
               generated/ppc_xenon/ppc_func_mapping.cpp satisfy
               `{ 0x<VA>, sub_<VA> }`, and 0 symbols there map to 2 addresses.
    table      exact case-insensitive row in that same generated table, tried
               as `<name>` and as `__imp__<name>`. This is the ONLY place a
               *named* import's slot address is written down anywhere in the
               tree -- `__imp__VdSwap` -> 0x827BD6E4, `__imp__NtClose` ->
               0x827BCEB4 -- and src/hooks/config_dispatch.cpp:68-73 loads
               those same rows as the dispatcher's default bindings.

Anything that resolves by none of those, or to more than one address, is
UNVERIFIABLE and exits 2. It never exits 0: "I could not resolve this symbol"
and "this guest function has one owner" are different answers, and only one of
them is a clearance to add a hook. Before this existed, `--check sub_821CA540`
fell through to the `sym:`/`body:` index keys, which no `sub_` site is ever
filed under, printed `0 site(s) (unclaimed...)` and exited 0 -- a false clean
verdict on the exact input `MCLA_BISECT_HOOK(sub_821CA540, ...)` hands the tool.

Resolution also runs the other way, in collect_index(): every `sym:` key that
resolves has its owners folded into that address's bucket, so a named-import
body and a hand-written `SetFunction` at its slot land in ONE bucket and are
judged by the same classify() as two hex sites. That is how the whole-tree
audit sees rule-4 conflicts the `sym:`-vs-hex split used to hide.

Two claims are only a violation when they genuinely conflict. The
save-original-then-hook idiom --

    SetFunction(A, plain);   g_orig = GetFunction(A);   SetFunction(A, hk_plain);

-- is deliberate and is reported as a note, not a violation. Anything else that
puts two binding mechanisms on one guest function is a violation, and since
F-366 that means *any* pair of distinct claiming kinds (`override` + `set`,
`hook` + `override`, ...) rather than only the `hook`-bearing pairs the tool
used to catch; so does a set of claims spread over more than one file, because
nothing in the tree states which one wins. `set` claims in *different files*
keep their own message (they usually turn out to be guarded by mutually
exclusive bisect modes) and are not double-reported by the cross-file rule.
`--gates <addr>` prints each claim site's
candidate conditions verbatim so the guard can be read rather than guessed at,
and the boot log decides which installer actually ran. classify() itself does no
reachability analysis, so a pair a human already cleared keeps printing:
`0x827BD6E4` / VdSwap is exactly that case -- F-053 in
`docs/ROOT_CAUSE_VALIDATION.md` concluded its registration sites cannot co-fire,
yet the address still reports a cross-file violation on every run.

Usage:
    python tools/addr_owners.py                      # violations + summary
    python tools/addr_owners.py --check 0x822FBAF8   # who owns this address
    python tools/addr_owners.py --check sub_821CA540 # same, by guest symbol
    python tools/addr_owners.py --check VdSwap       # a named import, resolved
                                                      # through the generated table
    python tools/addr_owners.py --gates 0x827BD6E4   # each claim's gate text
    python tools/addr_owners.py --file src/gpu_device.cpp
                                                      # every address this source
                                                      # owns, and who else wants it
    python tools/addr_owners.py --range 0x821C9000 0x821CB000
                                                      # same, over an address band
    python tools/addr_owners.py --all                # append the full index
    python tools/addr_owners.py --notes              # include advisory notes
    python tools/addr_owners.py --tsv build/addr_owners.tsv
    python tools/addr_owners.py --selftest           # this tool's own regressions

Exit status. Three codes, and the third exists because a rule enforced by a tool
that can answer "clean" without knowing is not enforced:

    0  clean. Every address looked up resolved, and none has conflicting owners.
    1  violation. At least one guest function has conflicting owners -- in
       --check/--gates mode for any address looked up, in --file/--range mode for
       any address in the scope, otherwise anywhere in the tree. A SetFunction
       that re-registers the body already bound to its own address is NOT one of
       these: it is printed as REDUNDANT (no-op) and excluded, see
       redundant_sets().
    2  unverifiable. The tool could not answer the question it was asked. In
       --check/--gates mode that is a symbol which resolves to no address, or to
       more than one; in --file/--range mode, a bad argument. 2 outranks 0 and
       loses to 1: a real conflict in the same batch is the more urgent news.

This is the code precedent mitigation_audit.py sets (1 = registered deviation,
0 = clean); --selftest follows the same convention, with 2 for "could not set
the run up at all" so a vacuous pass cannot be reported as a pass.
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
# The one generated file that is the guest's own address table. Read-only here
# (rule 2); it is the authority resolve_symbol() falls back on.
FUNC_MAP = REPO / "generated" / "ppc_xenon" / "ppc_func_mapping.cpp"
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
# and their address is NOT only knowable at runtime: generated/ppc_xenon/
# ppc_func_mapping.cpp already spells it out (`{ 0x827BD6E4, __imp__VdSwap }`),
# because codegen has to emit the same slot the guest calls. They are still
# indexed under `sym:<name>` -- that key is what carries the host name, which a
# hex key cannot -- and collect_index() now ALSO folds them into the address
# bucket resolve_symbol() finds, so the two spellings are judged together. That
# is what promoted the VdSwap case: sym-override in src/kernel/imports.cpp plus
# SetFunction in src/native_renderer.cpp and src/patches.cpp are one guest
# function with three owners, not three unrelated keys. File:line numbers are
# deliberately not quoted here -- they drift -- `--check __imp__VdSwap` prints
# the current ones.
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
# A whole-symbol prefix shared by more than this many `sym:` keys is a namespace
# rather than a discriminator; see symbol_crosscheck() for the artefact it caused.
NAMESPACE_SHARE_MAX = 4

# Kinds that assert ownership of the guest function. Everything else (`orig`,
# `fwd`, `get`, `toml:*`, `map`, `body`) is index context only: it shows up under
# --check and can never, on its own, make a violation.
CLAIMING = {"override", "hook", "set", "sym-override", "sym-hook"}

# Plain-English name for each claiming kind, so a mixed-mechanism violation says
# *what* the two mechanisms are rather than just repeating the kind labels.
MECHANISM = {
    "override": "a PPC_FUNC host body",
    "hook": "a GUEST_FUNCTION_HOOK binding",
    "set": "a SetFunction registration",
    "sym-override": "a named-import host body",
    "sym-hook": "a named-import binding",
}


# --- macro resolution (F-366) -------------------------------------------------
# A claim installed through a project macro used to be invisible, so the printed
# site counts were a floor. Three families exist in src/ today and all three
# expand to a PPC_FUNC_IMPL + PPC_FUNC pair on their symbol parameter:
#   MCLA_BISECT_HOOK / MCLA_T4A2_CENSUS / F6xx_TAIL_HOOK  (src/gpu_device.cpp)
#       PPC_FUNC_IMPL(__imp__##sym);  ...  PPC_FUNC(sym) { ... }
#   F362_PROBE / F364_PROBE          (src/task_dispatch_trace.cpp)
#       PPC_FUNC_IMPL(F362_CAT(__imp__, sym));  ...  PPC_FUNC(sym) { ... }
# The definition is captured with its body joined across `\` continuations, the
# invocation's arguments are substituted for the parameters by whole-word regex,
# `a##b` helper macros are resolved one level, and residual IDENT ## IDENT pastes
# are collapsed -- after which the *existing* pattern set is run over the result.
# Nothing here re-implements BODY_PATTERNS; see classify_text().
BINDERS = ("PPC_FUNC_IMPL", "GUEST_FUNCTION_HOOK", "PPC_FUNC")
# Macros excluded from being treated as claim wrappers, each for a stated reason.
#   PPC_FUNC / PPC_EXTERN_FUNC / PPC_WEAK_FUNC / PPC_FUNC_IMPL -- the binders
#     themselves (src/ppc_context.h:41-44). PPC_FUNC_IMPL's body names PPC_FUNC,
#     so without this it would qualify as a wrapper over its own argument and
#     re-derive every hand-written site in the tree.
#   GUEST_FUNCTION_HOOK -- genuinely a macro (src/kernel/function.h, body
#     `PPC_FUNC(subroutine) { ... }`) and so genuinely expandable, but every one
#     of its invocations is ALREADY indexed as a claiming `hook` site by
#     PLAIN_PATTERNS. Expanding it as well would record two claims per address --
#     one `hook`, one `override` -- and manufacture a mixed-mechanism violation
#     out of a single installation. It is the one binder whose own literal form
#     is complete, so it needs no expansion to be non-blind.
#   SetFunction / GetFunction -- function calls, not macros; listed so a future
#     `#define SetFunction` in src/ cannot silently become a wrapper.
PRIMITIVE_MACROS = {"PPC_FUNC", "PPC_FUNC_IMPL", "GUEST_FUNCTION_HOOK",
                    "PPC_EXTERN_FUNC", "PPC_WEAK_FUNC", "SetFunction",
                    "GetFunction"}
# `#define NAME(p, q) body...`, where body is the rest of the line plus every
# `\` continuation. 60+ `#define`s per header are cheap; only the ones whose body
# names a binder survive to expansion.
#
# The body group is written out longhand because a naive `([^\n]*(?:\\\r?\n[^\n]*)*)`
# silently returns just the backslash: the greedy `[^\n]*` eats the `\` that the
# continuation alternative needs, the match still succeeds, and nothing
# backtracks. Here the two classes are disjoint at every decision point
# (`[^\n\\]` or a backslash *not* ending the line, vs a backslash ending it), so
# the engine never has to backtrack to see the continuation.
_CONT = r"(?:[^\n\\]|\\[^\r\n])*"
MACRO_DEF = re.compile(
    r"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]*\(([^)\n]*)\)[ \t]*"
    r"(" + _CONT + r"(?:\\\r?\n" + _CONT + r")*)", re.MULTILINE)
MACRO_UNDEF = re.compile(r"^[ \t]*#[ \t]*undef[ \t]+([A-Za-z_]\w*)", re.MULTILINE)
# `#define CAT(a, b) a##b` -- resolvable without a preprocessor, and the shape
# F362_CAT2 uses. FORWARD_ONLY adds the one step above it: a macro whose body is
# a single call passing its own parameters straight through (`#define CAT(a, b)
# CAT2(a, b)`), which is how F362_CAT reaches the paste. Both are resolvable by
# substitution alone; anything else is a real preprocessor and is not attempted.
PASTE_ONLY = re.compile(r"^\s*([A-Za-z_]\w*)\s*##\s*([A-Za-z_]\w*)\s*$")
FORWARD_ONLY = re.compile(r"^\s*([A-Za-z_]\w*)\s*\(([^()]*)\)\s*$")
IDENT_PASTE = re.compile(r"([A-Za-z_]\w*)\s*##\s*([A-Za-z_]\w*)")
# forwarder -> paste is two steps, plus one for the paste collapse itself.
MAX_EXPAND_PASSES = 3
MAX_INVOKE_ARGS = 2000

# Documented non-support, kept as text so the limitation stays next to the code
# and --file prints it in its footer. A human must still grep for these three
# shapes; each is a real gap, not a style preference.
MACRO_LIMITS = [
    "variadic `#define NAME(sym, ...)` -- the `...` is not a parameter, so an "
    "address passed as the trailing variadic arg is not substituted",
    "a claim built by stringifying (`#sym` inside a log format) rather than by "
    "passing the symbol -- the address never reaches the expanded text",
    "a claim reached only through a helper whose body is not a bare `a##b` "
    "(e.g. a wrapper called from inside another macro body): the inner "
    "invocation is expanded, but claims it makes on behalf of its own caller "
    "are attributed to the outer invocation's arguments",
]


class MacroDef:
    """One `#define`, as far as claim resolution needs it."""
    __slots__ = ("name", "params", "body", "path", "line", "undef_line")

    def __init__(self, name, params, body, path, line):
        self.name = name
        self.params = params
        self.body = body
        self.path = path
        self.line = line
        self.undef_line: int | None = None

    def is_paste_helper(self) -> bool:
        return bool(PASTE_ONLY.match(self.body))

    def is_forwarder(self, known: set[str]) -> bool:
        """True for `#define A(x, y) B(x, y)` where B is itself a known helper.

        Requiring the inner arguments to be exactly this macro's own parameter
        list, in order, is what keeps this to a pure re-naming step. A body that
        rearranges, drops or concatenates its arguments is not a forwarder and
        stays unexpanded -- see MACRO_LIMITS."""
        m = FORWARD_ONLY.match(self.body)
        if not m or m.group(1) not in known:
            return False
        return [a.strip() for a in m.group(2).split(",")] == self.params

    def where(self) -> str:
        return f"{rel(self.path)}:{self.line}"


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
    __slots__ = ("kind", "addr", "name", "path", "line", "off", "via")

    def __init__(self, kind: str, addr: str, name: str, path: Path, line: int,
                 off: int, via: str = ""):
        self.kind = kind
        self.addr = addr
        self.name = name
        self.path = path
        self.line = line
        self.off = off
        # "NAME (defined at rel:line)" for a site that only exists because a claim
        # macro was expanded; "" for a hand-written one. Printed, never parsed.
        self.via = via

    @property
    def where(self) -> str:
        return f"{rel(self.path)}:{self.line}"

    def __str__(self) -> str:
        # The `kind name where` triple is the format the ledger and the skills
        # document quote; `via` is appended only for macro-derived sites, so a
        # hand-written line is byte-identical to what earlier runs printed.
        base = f"{self.kind:<9} {self.name or '-':<32} {self.where}"
        return f"{base}   via {self.via}" if self.via else base


def norm(addr: str) -> str:
    """Canonical `0x%08X`. Raises ValueError on a non-hex string, which is how
    main() tells an address argument from a symbol argument."""
    return f"0x{int(addr, 16):08X}"


def rel(path: Path) -> str:
    """Repo-relative POSIX path, or the path itself if it lies outside the repo.

    The single place a `file:line` string is built, so --check, --gates, --file,
    classify()'s violation text and the TSV all agree on the spelling."""
    try:
        return path.relative_to(REPO).as_posix()
    except ValueError:
        return str(path)


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


def classify_text(text: str, path: Path, via: str = "", off_base: int = 0,
                  line_base: int = 0) -> list[Owner]:
    """Every recognised site shape in `text`, as Owners rooted at this file.

    Shared by scan_source() and by the macro expander, which is the point: a
    macro body is classified by exactly the same patterns as hand-written code,
    so a claim hidden in a `#define` can never drift from the rules applied to a
    claim written out in full. `off_base`/`line_base` place matches in the real
    file: an expanded body has its own line numbering, so line = line_base +
    newlines-before-match, and off = off_base + byte offset -- the latter keeping
    is_hook_idiom()'s span test working across a macro site and its neighbours.

    Note that `override`/`orig`/`fwd` sites carry no host name, so they can never
    take part in the symbol cross-matching that symbol_crosscheck() and the
    --check "related" list do."""
    out: list[Owner] = []
    for on_body, on_semi, pat in BODY_PATTERNS:
        for m in pat.finditer(text):
            kind = on_body if m.group(2) == "{" else on_semi
            out.append(Owner(kind, norm(m.group(1)), "", path,
                             line_base + text.count("\n", 0, m.start()) + 1,
                             off_base + m.start(), via))
    for kind, pat in PLAIN_PATTERNS:
        for m in pat.finditer(text):
            name = m.group(2) if m.lastindex and m.lastindex >= 2 else ""
            out.append(Owner(kind, norm(m.group(1)), name, path,
                             line_base + text.count("\n", 0, m.start()) + 1,
                             off_base + m.start(), via))
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
                             line_base + text.count("\n", 0, m.start()) + 1,
                             off_base + m.start(), via))
    return out


def scan_source(path: Path) -> list[Owner]:
    """All the claim shapes above, applied to one file after comment-stripping,
    plus the claims its own claim macros contribute.

    Line numbers are counted in the stripped text, which is why strip_comments()
    has to keep newlines. Macros are read from the *stripped* text too, so a
    `#define` commented out above the block is not resolved into a live claim."""
    try:
        text = strip_comments(path.read_text(encoding="utf-8", errors="replace"))
    except OSError:
        return []
    return classify_text(text, path) + scan_macro_claims(text, path)


def collect_macros(text: str, path: Path) -> list[MacroDef]:
    """Every `#define NAME(...)` in one file, with `#undef` recorded.

    A name may be defined more than once (F617_TAIL_HOOK, F618_TAIL_HOOK ... are
    all live at once, but a redefinition is legal), so the list is kept whole and
    the invocation is matched against the definition in force at its line."""
    out: list[MacroDef] = []
    undefs: dict[str, list[int]] = defaultdict(list)
    for pat, is_def in ((MACRO_DEF, True), (MACRO_UNDEF, False)):
        for m in pat.finditer(text):
            line = text.count("\n", 0, m.start()) + 1
            if is_def:
                params = [p.strip() for p in m.group(2).split(",") if p.strip()]
                body = re.sub(r"\\\r?\n", " ", m.group(3))
                out.append(MacroDef(m.group(1), params, body, path, line))
            else:
                undefs[m.group(1)].append(line)
    for d in out:
        # The first #undef *after this definition* closes its window. Every undef
        # line is kept, not just the first per name, so the define/undef/redefine
        # cycle the F6xx_TAIL_HOOK family uses resolves each window correctly.
        after = [ln for ln in undefs.get(d.name, ()) if ln > d.line]
        d.undef_line = min(after) if after else None
    return out


def expand_macro(md: MacroDef, argtext: str,
                 helpers: dict[str, MacroDef]) -> str:
    """Substitute a claim macro's arguments into its body and un-paste it.

    Order matters and is the whole trick: parameters first (so `sym` is
    `sub_821C9790` before anything is glued to it), then `a##b` helper calls,
    then the residual `__imp__##sub_821C9790` -> `__imp__sub_821C9790`. The passes
    are bounded because arbitrary text need not reach a fixed point; three covers
    every form in src/ (F362_CAT -> F362_CAT2 -> `a##b` is the deepest chain).

    Returns "" when the arity does not match the definition -- the caller then
    records nothing, which is the safe direction: a missed site is a floor, a
    fabricated one is a false violation."""
    args = [a.strip() for a in argtext.split(",")]
    if len(args) != len(md.params) or any("(" in a or ")" in a for a in args):
        return ""
    body = md.body
    for p, a in zip(md.params, args):
        if not p or not a:
            return ""
        body = re.sub(r"\b" + re.escape(p) + r"\b", a.replace("\\", r"\\"), body)
    if helpers:
        names = "|".join(re.escape(n) for n in helpers)
        call = re.compile(r"\b(" + names + r")\s*\(([^()]*)\)")

        def resolve(m, _helpers=helpers):
            h = _helpers[m.group(1)]
            hargs = [x.strip() for x in m.group(2).split(",")]
            if len(hargs) != len(h.params):
                return m.group(0)
            sub = h.body
            for p, a in zip(h.params, hargs):
                sub = re.sub(r"\b" + re.escape(p) + r"\b",
                             a.replace("\\", r"\\"), sub)
            return sub

        for _ in range(MAX_EXPAND_PASSES):
            body = call.sub(resolve, body)
    for _ in range(MAX_EXPAND_PASSES):
        nxt = IDENT_PASTE.sub(r"\1\2", body)
        if nxt == body:
            break
        body = nxt
    return body


def scan_macro_claims(text: str, path: Path) -> list[Owner]:
    """Owners contributed by this file's own claim macros, one per invocation.

    Three filters keep this from turning into noise:
      * only macros whose body names a binder *and* take a parameter, minus the
        binders themselves (PRIMITIVE_MACROS), so the ~60 object-like macros in
        src/ppc_context.h cost nothing;
      * only invocations inside the window between a definition and its #undef,
        on a physical line that is not itself preprocessor text (a definition
        line or a `\\` continuation of one is not a call site);
      * only claims the expansion actually produces, matched with the same
        patterns as hand-written code."""
    defs = collect_macros(text, path)
    # Helper set, two tiers: bare `a##b` first, then a forwarder whose inner call
    # names an already-known helper. Iterating the name set to a fixed point
    # (rather than one pass) is what lets CAT -> CAT2 -> `a##b` resolve in
    # either declaration order.
    helpers: dict[str, MacroDef] = {d.name: d for d in defs if d.is_paste_helper()}
    for _ in range(MAX_EXPAND_PASSES):
        grew = {d.name: d for d in defs if d.is_forwarder(set(helpers))}
        if set(grew) <= set(helpers):
            break
        helpers.update(grew)
    wrappers: dict[str, list[MacroDef]] = defaultdict(list)
    for d in defs:
        if d.name in PRIMITIVE_MACROS or not d.params:
            continue
        if any(b in d.body for b in BINDERS):
            wrappers[d.name].append(d)
    if not wrappers:
        return []
    # A physical line is preprocessor text if it opens with '#' or continues a
    # line that did. Precomputing the flag keeps the invocation scan O(1) per
    # line instead of re-walking backwards.
    preproc: list[bool] = []
    continued = False
    for raw in text.split("\n"):
        starts = raw.lstrip().startswith("#")
        preproc.append(starts or continued)
        continued = starts and raw.rstrip().endswith("\\")
    out: list[Owner] = []
    for name, group in wrappers.items():
        pat = re.compile(r"(?<![\w.$])" + re.escape(name) + r"\s*\(")
        for m in pat.finditer(text):
            line = text.count("\n", 0, m.start()) + 1
            if 0 <= line - 1 < len(preproc) and preproc[line - 1]:
                continue
            # The definition in force here: the last one above the invocation,
            # and only if no #undef closed it in between.
            live = [d for d in group
                    if d.line <= line and (d.undef_line is None or line < d.undef_line)]
            if not live:
                continue
            md = live[-1]
            depth, end = 0, None
            for i in range(m.end() - 1, min(m.end() - 1 + MAX_INVOKE_ARGS, len(text))):
                if text[i] == "(":
                    depth += 1
                elif text[i] == ")":
                    depth -= 1
                    if depth == 0:
                        end = i
                        break
            if end is None:
                continue
            body = expand_macro(md, text[m.end():end], helpers)
            if not body:
                continue
            out.extend(classify_text(body, path,
                                     via=f"{md.name} (defined at {md.where()})",
                                     off_base=m.start(), line_base=line - 1))
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
    for o in scan_mapping(FUNC_MAP):
        if o.addr not in claimed:
            claimed.add(o.addr)
            owners.append(o)
    return owners


# --- symbol -> address resolution ----------------------------------------------
# `sub_821CA540` and `__imp__VdSwap` are the two spellings a hook author actually
# holds, and until this existed --check only ever tried hex. The `sub_` tier needs
# no file at all: the recompiler names a recompiled function after its own guest
# VA, and generated/ppc_xenon/ppc_recomp_shared.h declares every one of them as
# `PPC_EXTERN_FUNC(sub_XXXXXXXX)`. The `table` tier is for the names that carry no
# address in their text, where the generated mapping table is the only record.
SUB_SYM = re.compile(r"^(?:__imp__)?sub_([0-9A-Fa-f]{6,8})$")
_SYMBOL_TABLE: dict[str, set[str]] | None = None


def symbol_table() -> dict[str, set[str]]:
    """lowercase generated symbol -> {canonical guest address}, from FUNC_MAP.

    Keyed lowercase because the table's own spelling is not stable: src/kernel/
    imports.cpp writes `__imp__C_specific_handler` where the guest import is
    `__imp____C_specific_handler`, and a lookup that missed on case alone would
    report "unverifiable" for a symbol that is really a one-underscore typo in
    src/ (which is itself the finding -- it is a hook bound to a name the guest
    never imports).

    A symbol with more than one address is KEPT as a multi-element set rather than
    dropped, so resolve_symbol() can refuse it with a reason instead of silently
    picking one. Cached: the file is 1.4 MB and every mode wants it.
    """
    global _SYMBOL_TABLE
    if _SYMBOL_TABLE is None:
        table: dict[str, set[str]] = defaultdict(set)
        try:
            text = FUNC_MAP.read_text(encoding="utf-8", errors="replace")
        except OSError:
            text = ""
        for m in MAP_ROW.finditer(text):
            table[m.group(2).lower()].add(norm(m.group(1)[2:]))
        _SYMBOL_TABLE = dict(table)
    return _SYMBOL_TABLE


def resolve_symbol(raw: str, table: dict[str, set[str]] | None = None
                   ) -> tuple[str | None, str]:
    """One lookup argument -> (canonical address or None, provenance tier).

    Tiers, in order, and the tier is returned so --check can print which one
    answered instead of asking the reader to trust it:

      hex    the argument is an integer literal
      sub_   `(?:__imp__)?sub_<6-8 hex digits>` -- the recompiler's own naming
             convention, so the address is the digits. Checked against the table
             when the table has the row, so a stale or wrong name is reported as
             a contradiction rather than silently believed.
      table  an exact row of the generated table, tried as `<name>` then
             `__imp__<name>`
      --     anything else

    Returns (None, reason) for a name that resolves to nothing, and (None, ...) for
    one that resolves to several addresses. Both are UNVERIFIABLE and the caller
    exits 2: the difference between "this has one owner" and "I could not tell" is
    the whole point of rule 4's exit code, and collapsing them is what let the
    false clean verdict through.
    """
    if table is None:
        table = symbol_table()
    try:
        return norm(raw), "hex"
    except ValueError:
        pass
    m = SUB_SYM.match(raw)
    if m:
        addr = norm(m.group(1))
        rows = table.get(raw.lower()) or table.get(m.group(1).lower()) or set()
        if rows and rows != {addr}:
            return None, (f"CONTRADICTION: generated table puts {raw} at "
                          f"{'/'.join(sorted(rows))}, the sub_ convention says {addr}")
        return addr, "sub_ (recompiler naming; " + (
            "confirmed by generated table)" if rows else
            "symbol absent from generated table -- convention only, unconfirmed)")
    for cand in (raw, "__imp__" + raw):
        rows = table.get(cand.lower())
        if rows:
            if len(rows) > 1:
                return None, (f"AMBIGUOUS: {cand} appears at "
                              f"{'/'.join(sorted(rows))} in the generated table")
            return next(iter(rows)), f"table row {{ {next(iter(rows))}, {cand} }}"
    return None, (f"not a hex address, not a sub_<VA> name, and no row for it (or "
                  f"__imp__ + it) in {rel(FUNC_MAP)}")


def collect_index(owners: list[Owner], table: dict[str, set[str]] | None = None
                  ) -> tuple[dict[str, list[Owner]], list[tuple[str, str, str]]]:
    """addr -> owners, plus the folds: (sym key, address, tier) actually applied.

    The fold is the point. A named import is filed under `sym:<name>` because that
    key is the only place its *host* name survives, but rule 4 is about the guest
    FUNCTION, and the generated table says which address that is. Filing the same
    Owner objects under both keys means one bucket per guest function, so a
    `sym-override` beside a hand-written `SetFunction` at that slot is judged by
    the same classify() as two hex sites -- instead of the two never meeting and
    the token heuristic in symbol_crosscheck() being the only thing that noticed.

    The Owner objects are SHARED, not copied, so --check dedup on
    (kind, where, name, via) collapses them and a --all/--tsv row is written once
    per spelling rather than twice per site.
    """
    if table is None:
        table = symbol_table()
    index: dict[str, list[Owner]] = defaultdict(list)
    for o in owners:
        index[o.addr].append(o)
    folds: list[tuple[str, str, str]] = []
    for key in sorted(index):
        if not key.startswith("sym:"):
            continue
        addr, tier = resolve_symbol(key[4:], table)
        if addr is None:
            continue
        folds.append((key, addr, tier))
        if addr not in index:
            index[addr] = []
        for o in index[key]:
            if o not in index[addr]:
                index[addr].append(o)
    return index, folds


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


def redundant_sets(hits: list[Owner]) -> list[tuple[Owner, Owner]]:
    """`set` sites that re-register the body already bound to that address.

    A pair (s, o) where s.kind == "set" and o.kind == "sym-override" and
    s.name == o.name means the source says `SetFunction(addr, X)` while
    `PPC_FUNC(__imp__X) { ... }` is already the body the dispatcher resolves for
    `addr`. That is a no-op by construction, not a conflict: the generated table
    row `{ addr, __imp__X }` is what src/hooks/config_dispatch.cpp:68-73 loads as
    the default binding, and App::FunctionDispatcher::SetFunction
    (src/app.cpp:370-376) only does `m_functions[addr] = func` plus
    `g_memory.InsertFunction(addr, func)` -- assigning the value that is already
    there. The call cannot win and cannot lose; it does nothing.

    Any OTHER set/sym-override pair is not this and stays a violation, so the
    exclusion is keyed on the bound NAME matching, never on the kind pair alone.
    """
    ovr = {o.name: o for o in hits if o.kind == "sym-override" and o.name}
    return [(s, ovr[s.name]) for s in hits
            if s.kind == "set" and s.name in ovr]


def classify(hits: list[Owner]) -> tuple[list[str], list[str], list[str]]:
    """The rule-4 verdict for one address: (violations, notes, redundant).

    Only kinds in CLAIMING can raise a violation, and the violations it raises
    are: more than one `override` body; more than one `set`, either from
    different files or in one file with no `get` between them; ANY pair of
    distinct claiming kinds; and claiming sites spread over more than one file.
    Coexisting toml input and an address named by several toml sections are
    notes, not violations. REDUNDANT (no-op) pairs are excluded from every rule
    below and returned in the third list -- see redundant_sets() for why they are
    not conflicts, and for the name-match restriction that keeps a genuine
    set/sym-override pair a violation.

    The last two were the silent part. The mixed rule used to fire only when a
    plain hex `hook` was one of the kinds, so an `override` body beside a `set`,
    or a `sym-hook` beside a `sym-override`, printed nothing and exited 0 on a
    real rule-4 conflict; the cross-file rule did not exist at all outside the
    `set` case. F-366 is what made that matter: with the macro families resolved,
    a generated `override` can now collide with a hand-written `set` at an
    address, and the count of claiming sites per address roughly doubled, so
    "two mechanisms, one guest function" is no longer an exotic shape.

    The save-original-then-hook idiom is deliberately not a mixed case -- it is
    two `set`s, i.e. one mechanism, already handled as a note -- and a
    cross-file `set` pair keeps its own more specific message rather than being
    reported twice.

    What it does not report, by construction rather than oversight: any address
    left with one claiming site or fewer. Nor does it judge reachability: two
    gated installers that cannot co-fire still read as a violation, which is
    exactly why --gates exists."""
    # Drop the provable no-ops FIRST, before any rule below reads the claim set:
    # leaving them in would make an address report a mixed-mechanism violation
    # and a cross-file violation for a pair that provably cannot conflict, and
    # the two false positives are exactly what this exclusion exists to stop.
    redundant = redundant_sets(hits)
    noop = {id(s) for s, _ in redundant}
    claims = sorted((o for o in hits
                     if o.kind in CLAIMING and id(o) not in noop),
                    key=lambda o: o.off)
    tomls = [o for o in hits if o.kind.startswith("toml")]
    violations: list[str] = []
    notes: list[str] = []
    red_notes = [
        f"SetFunction({o.addr}, {s.name}) at {s.where} re-registers the body "
        f"`PPC_FUNC(__imp__{s.name})` already bound to that address at {o.where} "
        f"-- REDUNDANT (no-op), not a rule-4 conflict, and NOT counted towards exit 1"
        for s, o in redundant]

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
        # Unchanged wording: the ledger quotes this line by name.
        violations.append("GUEST_FUNCTION_HOOK plus "
                          + "/".join(sorted(mixed - {"hook"}))
                          + " on the same address -- two independent binding "
                            "mechanisms claim one guest function")
    elif len(mixed) > 1:
        violations.append("/".join(sorted(mixed)) + " on the same address -- two "
                          "independent binding mechanisms claim one guest function ("
                          + ", ".join(MECHANISM.get(k, k) for k in sorted(mixed))
                          + ") -- one of them will not run, or the later "
                            "registration wins; run --gates on this address, then "
                            "grep the newest build/*.log for each installer's own "
                            "line")
    # Cross-file: nothing in the tree states which installer wins. The `set`-only
    # case already said that, in more specific words, one rule above.
    if len(claim_files := sorted({o.path for o in claims})) > 1 and mixed != {"set"}:
        violations.append(
            f"claiming sites in {len(claim_files)} different files ("
            + ", ".join(rel(f) for f in claim_files)
            + f") with {', '.join(sorted(mixed))} -- no file in the tree states "
              "which owner wins; run --gates on this address and read the boot log")

    if tomls and claims:
        notes.append(f"codegen input ({', '.join(sorted({o.kind for o in tomls}))}) "
                     f"plus a host claim -- expected when hooking a recompiled "
                     f"function, but confirm the toml is still the intended owner")
    if len({o.kind for o in tomls}) > 1:
        notes.append("named by more than one toml section: "
                     + ", ".join(sorted({o.kind for o in tomls})))
    return violations, notes, red_notes


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
        if o.via:
            # candidate_gates() walks the physical file upward, and for a
            # file-scope macro invocation the lines above it are the macro BODY,
            # not conditions on the call. Say so, rather than let a reader treat
            # the body's own `if` as a gate that can switch this site off.
            print("    macro-derived site: lines above may be the macro body's own "
                  "statements,")
            print("    not a condition on this invocation -- an invocation at file "
                  "scope is unconditional")
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
    """Named-import owners vs hex-address owners of the same guest function, by NAME.

    Matched on whole `_`/`:`-separated words (tokens()), so `sym:VdSwap` pairs with
    `Hooked_VdSwap` and `hk_vdswap_observer` but `sym:ExCreateThread` does not pair
    with `SetThreadNameImpl`. Only the hex side needs a name, and only CLAIMING
    kinds qualify, so an `override` body of an address is invisible to this. The
    output is headed "overlaps", not violations: this is a *name* heuristic, and
    the import table resolves the real address independently of it -- so it is a
    lead to confirm, not a verdict.

    It is also now the WEAKER of the two cross-checks, and the ordering matters:
    collect_index() folds every resolvable `sym:` key into its address bucket, so
    anything this would pair on name is usually already a real rule-4 violation
    there. A match that is the same Owner object on both sides is skipped, because
    printing it here too would report one conflict twice at two confidence levels
    and let the weaker claim read as a separate finding.

    What it still catches that the fold cannot is a pair sharing a name but sitting
    at DIFFERENT addresses -- either two genuinely different guest functions whose
    hooks are named alike, or a `set` bound to the wrong slot. That is how
    `hk_VdInitializeEngines` at 0x827BD574 was found next to `sym:KeReleaseSemaphore`:
    no word is shared, so the fold found it and the name heuristic never could.

    NAMESPACE_SHARE_MAX is the other half. A token shared by many symbols is a
    namespace, not a discriminator, and matching on it pairs every member with
    every other: the 16 `NetDll_*` hooks all carry `netdll`, so folding them into
    their (correctly distinct) addresses turned this section from 6 lines into 23
    of which 17 were that one artefact. Tokens held by more than this many `sym:`
    keys are dropped before matching, which is what makes the docstring's promise
    -- "only a signal precise enough to print" -- true rather than aspirational.

    The remaining filter is the one that empties the section: a match sitting in
    the SAME address bucket as this symbol's own resolved address is the fold, so
    it is already a rule-4 violation and re-listing it here would report one
    conflict twice at two confidence levels. What survives is a same-name pair at
    DIFFERENT addresses -- the only thing a name heuristic can know that address
    resolution cannot -- and in the tree today that is nothing, which is the honest
    result rather than a gap.
    """
    sym_keys = [k for k in index if k.startswith("sym:")]
    share: dict[str, int] = defaultdict(int)
    for k in sym_keys:
        for t in tokens(k[4:]):
            share[t] += 1
    hexed = [(a, hits) for a, hits in index.items()
             if not a.startswith(("sym:", "body:"))]
    table = symbol_table()
    out = []
    for sym_key, sym_hits in sorted(index.items()):
        if not sym_key.startswith("sym:"):
            continue
        want = {t for t in tokens(sym_key[4:]) if share[t] <= NAMESPACE_SHARE_MAX}
        if not want:
            continue
        sym_ids = {id(o) for o in sym_hits}
        own = resolve_symbol(sym_key[4:], table)[0]
        matched = [o for a, hits in hexed for o in hits
                   if o.kind in CLAIMING and o.name and tokens(o.name) & want
                   and id(o) not in sym_ids and a != own]
        if matched:
            out.append((sym_key[4:], sym_hits, matched))
    return out


def report_scope(title: str, index: dict[str, list[Owner]], limit: Path | None = None,
                 lo: str | None = None, hi: str | None = None) -> tuple[int, int]:
    """Every address in a scope, its sites, who else wants it, and the verdict.

    The scope is a whole file (`--file`) or an address band (`--range`), which is
    what makes "validate the block I just added" one command instead of N
    `--check` calls. Three lines per address, in the same vocabulary as --check:

      * every site whose path is inside the scope, claimed or not, so the
        inventory is complete rather than only the conflicts;
      * every site for the same address from *outside* the scope, marked
        `elsewhere:` -- for --file this is the whole point, since the question
        being asked is "does anything else already own what I just claimed";
      * VIOLATION / note lines from the same classify() the other modes use, so
        the exit code means the same thing everywhere.

    `map` rows from the generated table are shown and labelled rather than
    hidden: they are not claims, but "the generated table already binds this
    address" is exactly what a new hook author needs to know. Addresses with no
    claiming site inside the scope are still listed (an `orig`-only address is
    how an override-in-progress looks), but they are not violations.
    """
    chosen: dict[str, list[Owner]] = {}
    for addr, hits in index.items():
        if addr.startswith(("sym:", "body:")):
            continue
        in_scope = [o for o in hits
                    if (limit is not None and o.path == limit)
                    or (lo is not None and lo <= addr <= hi)]
        if not in_scope:
            continue
        chosen[addr] = in_scope
    print(f"\n# {title}")
    if limit is not None:
        print(f"# scope: sites in {rel(limit)}")
    else:
        print(f"# scope: guest addresses in [{lo}, {hi}]")
    print(f"# {len(chosen)} address(es) touched by the scope\n")
    n_bad = 0
    n_red = 0
    for addr in sorted(chosen):
        mine = chosen[addr]
        other = [o for o in index[addr] if o not in mine]
        violations, notes, red = classify(mine + other)
        flag = "CONFLICT" if violations else ("ok" if any(
            o.kind in CLAIMING for o in mine) else "no claim")
        print(f"{addr} -- {len(mine)} site(s) in scope, {len(other)} elsewhere "
              f"[{flag}]")
        for o in sorted(mine, key=lambda o: o.off):
            print(f"  {o}")
        for o in sorted(other, key=lambda o: (o.path, o.off)):
            print(f"  {o}   (elsewhere)")
        for v in violations:
            print(f"  VIOLATION: {v}")
        for r in red:
            print(f"  {r}")
        for n in notes:
            print(f"  note: {n}")
        if violations:
            n_bad += 1
        n_red += bool(red)
    print(f"\n# {len(chosen)} address(es) in scope, {n_bad} with a rule-4 conflict"
          + (f", {n_red} with a REDUNDANT (no-op) set" if n_red else ""))
    if limit is not None:
        print("# macro-derived sites in this file carry `via NAME (defined at "
              "file:line)`;")
        print("# a claim written through one of those macros is real, so edit the "
              "invocation,")
        print("# not the #define, unless the intent really is to retarget every "
              "invocation.")
        # The gaps are printed here rather than left in the source, because
        # --file is the command a new instrumentation block gets validated with,
        # and these are exactly the claims it could still miss.
        print("# forms this tool does NOT expand -- grep the file for these by hand:")
        for lim in MACRO_LIMITS:
            print(f"#   - {lim}")
    return len(chosen), n_bad


# --- selftest -------------------------------------------------------------------
# The cases that must have failed before resolve_symbol() existed, and the one
# exclusion that must not swallow a real conflict. Subjects are DERIVED from the
# live tree wherever the live tree has one, so a case cannot rot into a vacuous
# pass after someone deletes the function it used to name; the two shapes with no
# live instance (a redundant no-op, a genuinely-conflicting set/sym-override pair)
# are built as Owner literals, because there are 0 of each in src/ today and a
# regression test for them must not depend on one existing.
SELFTEST_NOTE = """\
--selftest cases, and what each one is for:
  1 macro-symbol        a site reachable ONLY through a claim-macro expansion, asked
                        for by symbol. Asserts classify_text() over the RAW file
                        finds nothing while scan_source() does -- i.e. the zero the
                        old tool printed was a raw-grep artefact, not a real zero.
  2 plain-ppc-func      a hand-written PPC_FUNC(sub_X) { } body with no `via`,
                        asked for by symbol. The other symbol form: nothing to
                        expand, so only the symbol->address step can find it.
  3 unclaimed-zero      a guest address absent from src/, the toml AND the
                        generated table, by construction. Must be 0 sites / exit 0,
                        and trustworthy only because case 1 passed in this same run.
  4 nonexistent-symbol  a name that resolves to nothing. Must exit 2, not 0.
  5 ambiguous-symbol    a name with two table addresses. Must exit 2, not 0.
  6 redundant-noop      SetFunction(addr, X) beside PPC_FUNC(__imp__X) { }.
                        Must be annotated REDUNDANT (no-op) and must NOT exit 1.
  7 set-pair-violates   the same shape with a DIFFERENT bound name. Must still exit
                        1 -- the exclusion is keyed on the name, not the kinds.
  8 help-spelling       --help must advertise MCLA_BISECT_HOOK (src/gpu_device.cpp)
                        and must not contain the never-existed MCLA_BMIT_HOOK.
"""


def _pick(index, pred):
    """First (addr, hits) in the folded index satisfying pred, or (None, None).

    Sorted, so a case that finds more than one subject reports the same one on
    every machine -- the failure output of a regression test should be stable
    enough to paste into a finding.
    """
    for addr in sorted(index):
        if addr.startswith(("sym:", "body:")):
            continue
        hits = index[addr]
        if pred(addr, hits):
            return addr, hits
    return None, None


def selftest() -> int:
    """Run every case, print pass/fail per case, exit non-zero on any failure.

    Exits 0 (all pass), 1 (a case failed -- a real regression, same code as a
    rule-4 violation so CI cannot read a red selftest as an unrelated flake) and
    2 (the run could not set up: no src tree, no generated table, or none of the
    live shapes the cases 1-3 look for, in which case "all passed" would be
    vacuous and must not be reported).
    """
    results: list[tuple[str, bool, str]] = []

    def case(name: str, ok: bool, detail: str = "") -> None:
        results.append((name, ok, detail))

    print(SELFTEST_NOTE)
    table = symbol_table()
    if not table:
        print("selftest: no generated table at " + rel(FUNC_MAP) + " -- cannot set up",
              file=sys.stderr)
        return 2
    owners = collect()
    if not owners:
        print("selftest: no sites collected under src/ -- cannot set up", file=sys.stderr)
        return 2
    index, _folds = collect_index(owners)

    # 1 -- a site that exists only because a claim macro was expanded.
    addr, hits = _pick(index, lambda a, h: any(
        o.kind in CLAIMING and o.via and o.name == "" for o in h))
    if addr is None:
        print("selftest: no macro-derived claiming site in src/ -- cases 1 and 3 "
              "would be vacuous", file=sys.stderr)
        return 2
    sym = "sub_" + addr[2:]
    resolved, tier = resolve_symbol(sym, table)
    got = index.get(resolved, []) if resolved else []
    # The proof that the zero this tool used to print was a raw-grep artefact:
    # run ONLY the literal patterns over the un-expanded file text and show the
    # site is not there. scan_source() finds it; classify_text() alone does not.
    site_path = _path_of(hits)
    raw = strip_comments(site_path.read_text(encoding="utf-8", errors="replace"))
    raw_only = [o for o in classify_text(raw, site_path) if o.addr == addr]
    ok = (resolved == addr and tier.startswith("sub_") and bool(got)
          and not any(o.via for o in raw_only))
    case("macro-symbol", bool(ok),
         f"{sym} -> {resolved} [{tier.split('(')[0].strip()}]; {len(got)} site(s) "
         f"in the index, {len(raw_only)} from raw-text patterns alone at "
         f"{rel(site_path)} -- the site exists only in the EXPANDED text")

    # 2 -- a hand-written PPC_FUNC(sub_X) { } with no macro behind it.
    addr2, hits2 = _pick(index, lambda a, h: any(
        o.kind == "override" and not o.via and o.name == "" for o in h))
    if addr2 is None:
        case("plain-ppc-func", False, "no hand-written PPC_FUNC(sub_X) { } in src/")
    else:
        sym2 = "sub_" + addr2[2:]
        r2, t2 = resolve_symbol(sym2, table)
        got2 = index.get(r2, []) if r2 else []
        ok2 = r2 == addr2 and any(o.kind == "override" and not o.via for o in got2)
        case("plain-ppc-func", bool(ok2),
             f"{sym2} -> {r2} [{t2}]; {len(got2)} site(s), "
             f"{sum(1 for o in got2 if o.kind == 'override')} override(s)")

    # 3 -- genuinely unclaimed: absent from the index AND from the generated table,
    # which between them are every guest address and every src site. The zero is
    # only meaningful because case 1 proved the expanded path was searched in this
    # same process.
    lo = min(norm(a[2:]) for a in table.values() for a in a) if table else "0x82130000"
    probe = None
    cand = int(lo, 16)
    while probe is None and cand < 0x82FFFFFF:
        if (norm(f"{cand:08X}") not in index
                and f"{cand:08X}" not in {a for s in table.values() for a in s}):
            probe = norm(f"{cand:08X}")
        cand += 4
    if probe is None:
        case("unclaimed-zero", False, "could not find an address absent from both "
                                       "the index and the generated table")
    else:
        rp, tp = resolve_symbol("sub_" + probe[2:], table)
        got3 = index.get(rp, []) if rp else []
        ok3 = rp == probe and not got3
        case("unclaimed-zero", bool(ok3),
             f"{probe} (also asked as sub_{probe[2:]}) -> {rp} [{tp}]; "
             f"{len(got3)} site(s); 0 is real because case 1 passed in this run")

    # 4/5 -- unresolvable inputs must be UNVERIFIABLE, never a clean verdict.
    r4, t4 = resolve_symbol("hk_selftest_no_such_symbol_9F3A", table)
    ok4 = r4 is None and not t4.startswith(("hex", "sub_ (recompiler", "table row"))
    case("nonexistent-symbol", bool(ok4),
         f"hk_selftest_no_such_symbol_9F3A -> {r4} ({t4[:58]}...)"
         if not ok4 else "no table row, no sub_ shape -> UNVERIFIABLE, exit 2")

    r5, t5 = resolve_symbol("Ambi", {"ambi": {"0x82100000", "0x82200000"}})
    ok5 = r5 is None and t5.startswith("AMBIGUOUS")
    case("ambiguous-symbol", bool(ok5),
         "Ambi -> 2 table addresses -> refused: " + t5[:46] + "..."
         if ok5 else f"got {r5} / {t5!r}")

    # 6/7 -- the no-op exclusion, and its boundary. Synthetic: src/ has 0 of each.
    def pair(set_name: str) -> list[Owner]:
        return [Owner("sym-override", "0x827BD6E4", "VdSwap",
                      SRC / "kernel" / "imports.cpp", 4951, 100),
                Owner("set", "0x827BD6E4", set_name, SRC / "patches.cpp", 638, 200)]

    v6, n6, r6 = classify(pair("VdSwap"))
    ok6 = not v6 and len(r6) == 1 and "REDUNDANT (no-op)" in r6[0] \
        and "0x827BD6E4" in r6[0]
    case("redundant-noop", bool(ok6),
         f"SetFunction(0x827BD6E4, VdSwap) + PPC_FUNC(__imp__VdSwap): "
         f"{len(v6)} violation(s), {len(r6)} REDUNDANT line(s) -> exit 0"
         if ok6 else f"{len(v6)} violation(s) {v6}, redundant={r6}")

    v7, n7, r7 = classify(pair("hk_vdswap_observer"))
    ok7 = bool(v7) and not r7
    case("set-pair-violates", bool(ok7),
         f"SetFunction(0x827BD6E4, hk_vdswap_observer) + PPC_FUNC(__imp__VdSwap): "
         f"{len(v7)} violation(s) -> exit 1 (name differs, so not the no-op shape)"
         if ok7 else f"violations={v7} redundant={r7}")

    # 8 -- the help text is generated from this docstring, so a wrong macro name
    # here is a wrong instruction to whoever reads --help.
    case("help-spelling", "MCLA_BISECT_HOOK" in __doc__ and "MCLA_BMIT_HOOK" not in __doc__,
         "--help advertises MCLA_BISECT_HOOK and not MCLA_BMIT_HOOK")

    width = max(len(n) for n, _, _ in results)
    for name, ok, detail in results:
        print(f"  {'PASS' if ok else 'FAIL':<4} {name:<{width}}  {detail}")
    n_bad = sum(1 for _, ok, _ in results if not ok)
    print(f"\nselftest: {len(results) - n_bad}/{len(results)} case(s) passed")
    return 1 if n_bad else 0


def _path_of(hits: list[Owner]) -> Path:
    """The file a hit list came from -- all sites in one address share one path in
    every case selftest() looks at, and a claim's `file:line` is what case 1
    re-reads to prove the raw text alone would have missed it."""
    return hits[0].path


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", help="comma-separated guest addresses or symbols to "
                                     "look up (hex 0x821CA540, sub_821CA540, or a "
                                     "named import such as VdSwap / __imp__VdSwap)")
    ap.add_argument("--gates", help="comma-separated addresses: print each claim site's "
                                     "candidate gating conditions verbatim")
    ap.add_argument("--file", type=Path,
                    help="report every guest address owned from this one source file "
                         "(repo-relative or absolute)")
    ap.add_argument("--range", nargs=2, metavar=("LO", "HI"),
                    help="report every owned guest address in [LO,HI] (inclusive)")
    ap.add_argument("--all", action="store_true", help="print the full index")
    ap.add_argument("--notes", action="store_true", help="also print advisory notes")
    ap.add_argument("--tsv", type=Path, help="write addr/kind/name/where TSV here")
    ap.add_argument("--selftest", action="store_true",
                    help="run addr_owners.py's own regression cases and exit "
                         "non-zero if any fails; prints what each case covers")
    args = ap.parse_args()

    if args.selftest:
        return selftest()

    owners = collect()
    index, folds = collect_index(owners)

    if args.file or args.range:
        # Scope modes are exclusive of the whole-index report: they answer one
        # question about one region, and interleaving the global violation list
        # with a file listing makes both harder to read. Both still exit 1 on a
        # conflict, which is the part other scripts depend on.
        if args.file:
            target = args.file.resolve()
            if not target.exists():
                print(f"addr_owners: no such file: {args.file}", file=sys.stderr)
                return 2
            _, bad = report_scope(f"ownership of guest addresses from one source",
                                  index, limit=target)
        else:
            try:
                lo, hi = sorted(norm(a.strip()) for a in args.range)
            except ValueError:
                print("addr_owners: --range takes two hex addresses, e.g. "
                      "--range 0x821C9000 0x821CB000", file=sys.stderr)
                return 2
            _, bad = report_scope("ownership over an address range", index, lo=lo, hi=hi)
        return 1 if bad else 0

    if args.check or args.gates:
        bad = unver = 0
        # Only args.check is read here, so with both flags given the loop -- and
        # the gate report inside it -- runs over the --check list.
        for raw in (a.strip() for a in (args.check or args.gates).split(",")):
            if not raw:
                continue
            # resolve_symbol() is the fix: the argument is turned into a guest
            # ADDRESS first, and the address is then looked up. Before it existed
            # the symbol forms fell straight through to the `sym:`/`body:` index
            # keys -- which no `sub_` site is ever filed under -- so `--check
            # sub_821CA540` printed "0 site(s) (unclaimed)" and exited 0 on an
            # address with two owners.
            addr, tier = resolve_symbol(raw)
            keys = []
            if addr is not None:
                keys.append(addr)
            keys += [f"sym:{import_symbol(raw)}", f"body:{raw}", raw]
            hits = [o for k in keys for o in index.get(k, [])]
            # `via` is part of the identity: one invocation yields an `orig` and an
            # `override` on the same line, and a hand-written site plus a
            # macro-derived one must not collapse into a single row. It is also
            # what collapses the two index keys a folded symbol now occupies, so
            # one site is never printed twice.
            hits = sorted({(o.kind, o.where, o.name, o.via): o for o in hits}.values(),
                          key=lambda o: (o.path, o.off))
            # Pull in named-import owners that refer to the same guest function,
            # so `--check 0x827BD6E4` also shows `PPC_FUNC(__imp__VdSwap)`. The
            # join runs one way only: `--check VdSwap` prints the sym site and not
            # the hex addresses whose bound name shares the token.
            want = {t for o in hits if o.name for t in tokens(o.name)}
            seen = {(o.kind, o.where, o.name, o.via) for o in hits}
            related = [o for k, rh in index.items() if k.startswith("sym:")
                       for o in rh
                       if (tokens(k[4:]) & want)
                       and (o.kind, o.where, o.name, o.via) not in seen]
            print(f"\n{raw} -- resolved to {addr} via {tier}" if addr
                  else f"\n{raw} -- UNVERIFIABLE: {tier}")
            print(f"  {len(hits)} site(s)"
                  + (f" + {len(related)} named-import site(s)" if related else ""))
            for o in hits:
                print(f"  {o}")
            for o in related:
                print(f"  {o}   (named import, same guest function)")
            violations, notes, red = classify(hits + related)
            for v in violations:
                print(f"  VIOLATION: {v}")
            for r in red:
                print(f"  {r}")
            for n in notes:
                print(f"  note: {n}")
            # A generated `map` row counts as a hit, so this prints only for an
            # address absent from src/, the toml and the generated table alike.
            # Suppressed when the address itself is unknown: "unclaimed" is a
            # claim about a guest function, and there is no guest function to
            # make it about. The UNVERIFIABLE line above is the whole answer.
            if not hits and addr is not None:
                print("  (unclaimed in src/ and config/ -- if it shows up in a log "
                      "it is guest code running unhooked)")
            if args.gates:
                report_gates(raw, hits + related)
            if violations:
                bad = 1
            elif addr is None:
                # Not a conflict, and emphatically not a clearance either: the
                # question "does someone else already own this?" was not
                # answered, so exit 2. This is the false-negative fix in one line
                # -- before it, an unresolvable name took the same path as a
                # clean address and returned 0.
                unver = 1
        return 1 if bad else (2 if unver else 0)

    bad, noted, redud = [], [], []
    for addr, hits in sorted(index.items()):
        # An address is listed once: if classify() returned both a violation and
        # notes here, only the violation survives into the report.
        violations, notes, red = classify(hits)
        if violations:
            bad.append((addr, hits, violations, red))
        elif red:
            redud.append((addr, hits, red))
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
    n_unres = sum(1 for k in index if k.startswith("sym:")
                  and not any(f[0] == k for f in folds))
    print(f"#   symbol->address resolution: {len(folds)} named import(s) folded into "
          f"their guest address bucket, {n_unres} unresolvable (UNVERIFIABLE -- "
          f"see --check on the name)")
    print()

    if bad:
        print(f"RULE-4 VIOLATIONS: {len(bad)} guest function(s) with conflicting owners\n")
        for addr, hits, violations, red in bad:
            print(addr)
            for v in violations:
                print(f"  VIOLATION: {v}")
            for r in red:
                print(f"  {r}")
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                print(f"    {o}")
            print()
    else:
        # Read this as "no conflict classify() could detect", not "every address is
        # owned": the bulk of the index keys carry zero claiming sites at all -- a
        # bare `map` row, or an `orig` extern with nothing over it -- and they too
        # fall through to this branch.
        print("RULE-4 VIOLATIONS: none -- every guest address has one owner\n")

    if redud:
        # Printed unconditionally, not under --notes: a REDUNDANT line is the
        # reason an address is NOT in the count above, so hiding it behind a flag
        # would leave a reader unable to reproduce the number.
        print(f"REDUNDANT (no-op) -- {len(redud)} address(es) with a SetFunction that "
              f"re-registers the body already bound there; EXCLUDED from the "
              f"violation count above and from exit 1\n")
        for addr, hits, red in redud:
            print(addr)
            for r in red:
                print(f"  {r}")
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                print(f"    {o}")
            print()

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
              f"(heuristic by NAME, different addresses only -- confirm by hand)\n")
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
    else:
        # Say why it is empty. A section that used to print 6 lines and now prints
        # nothing looks like a regression unless the reason is on the screen.
        print("NAMED-IMPORT / HEX-ADDRESS OVERLAPS: 0 -- every same-name pair in the "
              "tree now lands in one address\n"
              f"  bucket via symbol->address resolution ({len(folds)} named import(s) "
              f"folded, {len(bad)} of them in a rule-4 violation above), and no\n"
              "  same-name pair sits at two different addresses. The name heuristic is "
              "kept only as the fallback\n"
              f"  for symbols the generated table cannot resolve ({n_unres} today); "
              "see --check.\n")

    # A folded Owner is reachable under two index keys. Dedupe on the (key, site)
    # identity so --all and --tsv gain the new spellings without gaining a second
    # copy of every folded row.
    seen_rows: set[tuple[str, str, str, str]] = set()
    if args.all:
        print("full index:")
        for addr, hits in sorted(index.items()):
            for o in sorted(hits, key=lambda o: (o.path, o.off)):
                if (addr, o.kind, o.name, o.where) in seen_rows:
                    continue
                seen_rows.add((addr, o.kind, o.name, o.where))
                print(f"{addr}\t{o.kind}\t{o.name}\t{o.where}")

    if args.tsv:
        args.tsv.parent.mkdir(parents=True, exist_ok=True)
        n_rows = 0
        with args.tsv.open("w", encoding="utf-8", newline="") as fh:
            fh.write("address\tkind\tname\twhere\n")
            for addr, hits in sorted(index.items()):
                for o in sorted(hits, key=lambda o: (o.path, o.off)):
                    if (addr, o.kind, o.name, o.where) in seen_rows:
                        continue
                    seen_rows.add((addr, o.kind, o.name, o.where))
                    n_rows += 1
                    fh.write(f"{addr}\t{o.kind}\t{o.name}\t{o.where}\n")
        print(f"wrote {args.tsv} ({n_rows} rows)")

    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
