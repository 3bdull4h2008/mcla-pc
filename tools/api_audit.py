#!/usr/bin/env python3
"""api_audit.py -- catch platform-API names that the compiler would reject, and
constant tables that the compiler would accept but the GPU would not honour.

    python tools/api_audit.py                 # audit src/ + tools/validators/
    python tools/api_audit.py --json          # machine-readable
    python tools/api_audit.py --strict        # UNRESOLVED is a failure too
    python tools/api_audit.py --selftest      # one case per check, no repo writes

WHAT IT CATCHES (each class was a real compile-breaking or silently-wrong edit
on this tree; the class, not the instance, is what is encoded here):

  PLATFORM-NAME      a `D3D12_*` / `DXGI_*` / `STATUS_*` / `ID3D12*` / Win32
                     name that no header in the build's include path defines.
  NOT-REACHABLE      a name defined in a project header that this translation
                     unit cannot see, because nothing in its include closure
                     pulls that header in. Compiles in isolation, breaks here.
  COM-METHOD         a method called on a COM interface that the interface does
                     not declare -- checked against the VENDORED header, not the
                     SDK's, because the two differ (the vendored
                     `third_party/dxc/inc/dxc/d3d12shader.h` has no
                     `ID3D12ShaderReflection::GetVariableDesc`).
  STRUCT-MEMBER      a member read at the wrong nesting level, or one the struct
                     does not have at all. Needs a resolved receiver type; when
                     the receiver type is not known the site is reported as
                     UNKNOWN, never guessed.
  ENUM-BOOL-ASSIGN   an enum-typed member assigned FALSE/TRUE/0/1.
  BITFIELD-SIZE      a bitfield struct whose declared width contradicts the
                     `static_assert(sizeof(X) == sizeof(T))` beside it, or
                     whose width overflows its base type.
  CONST-TABLE-VALUE  a hand-written constant that claims to mirror a platform
                     enumerator but does not have that enumerator's value.
  CONST-TABLE-ILLEGAL
                     the same table, where the value is not a value the platform
                     enum defines at all. This is the one that catches a value
                     which is bit-identical to a legal, different filter.
  MUTEX-NOT-MUTABLE  a non-`mutable` mutex locked from a `const` member function.

HOW NAMES ARE RESOLVED. Roots are the -I/-imsvc directories that
`build/compile_commands.json` records, plus third_party/{dxc,fmt,spdlog,SDL3};
when that file is absent the Windows Kits include tree is used directly. No name
list is hardcoded: every verdict comes from a header this machine actually has.
Per translation unit, only the #include closure of that TU is searched, so
"not reachable from this TU" is a real measurement and not a guess.

LIMITS, STATED (see "what this cannot do" in the module docstring of the
findings report): the header parser is regex over C++ declarations, not a real
front end. It reads flat `typedef struct {...} Name;` bodies, `enum {...} Name;`
bodies, MIDL_INTERFACE/DECLARE_INTERFACE bodies and `struct X : public Y { ... }`
bodies. It does NOT evaluate `#if`, does not expand macros, and reports UNKNOWN
rather than a verdict whenever a body contains a construct it cannot classify.
Over-approximating the #include set (all includes taken, not only live ones)
makes the tool miss some not-reachable cases; it never invents one.

Exit status: 0 clean, 1 at least one finding, 2 UNRESOLVED sites under
--strict, 3 usage/no roots, 4 --selftest failed.
"""

from __future__ import annotations

import argparse
import bisect
import hashlib
import json
import os
import pickle
import re
import sys
import time
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
CACHE = Path(os.environ.get("LOCALAPPDATA", r"C:\Users\abdul\AppData\Local")) / "Temp" / "opencode" / "api_audit"

SRC_SUFFIXES = (".h", ".hpp", ".hh", ".c", ".cc", ".cpp", ".cxx", ".inl")
HDR_SUFFIXES = (".h", ".hpp", ".hh", ".hxx", ".inl", ".inc")
# Bump when the header parser changes: the per-file parse cache is keyed on
# this, so a stale pick from before a parser fix is a wrong verdict, not a slow
# one. It is in the cache FILE NAME, so old entries are simply ignored.
PARSER_VERSION = 1

# ---------------------------------------------------------------- name shapes

# Platform constant/type families. A token is only a candidate when the WHOLE
# token is upper case: every D3D12/DXGI/STATUS symbol in the SDK is, and
# requiring it is what keeps `MyD3D12Thing` and `D3D12Foo` (camelCase, a project
# type) out of the candidate set.
PLAT_PREFIXES = (
    "D3D12_", "D3D11_", "D3D_", "DXGI_", "D3D12_RESOURCE_", "D3D12_RUNTIME_",
    "DXGI_STATUS_", "WIC_", "WINHTTP_", "STATUS_", "NTSTATUS", "HRESULT_",
    "ERROR_", "X_ERROR_", "WSA", "XAudio2_", "XINPUT_",
)
ALL_CAPS = re.compile(r"[A-Z0-9_]+\Z")
# COM interface families this project names. `I` + a known family, so ordinary
# locals like `Index`/`Icmp` are never candidates.
IFACE_RE = re.compile(
    r"I(?:D3D|D3D11|DXGI|WIC|WICimaging|Unknown|Base|AgileObject|Malloc|RunnableObject"
    r"|Stream|Storage|EnumWIC|ClassFactory|Persist)[A-Za-z0-9_]*\Z")
HANDLE_RE = re.compile(r"[A-Z][A-Z0-9]*_HANDLE\Z")
# Win32 entry points the brief names, plus the families. Kept explicit on
# purpose: a `Create*`/`Get*` shape rule alone is thousands of false positives.
WIN32_NAMES = frozenset("""
VirtualAlloc VirtualAllocEx VirtualFree VirtualProtect VirtualQuery
GetProcAddress LoadLibraryA LoadLibraryW LoadLibraryExA LoadLibraryExW
FreeLibrary GetModuleHandleA GetModuleHandleW GetModuleHandleExA
GetModuleFileNameA GetModuleFileNameW
WaitForSingleObject WaitForMultipleObjects Sleep SleepEx
CreateEventA CreateEventW CreateEvent CreateMutexA CreateMutexW
CreateFileA CreateFileW ReadFile WriteFile CloseHandle DuplicateHandle
SetEvent ResetEvent CreateSemaphoreA CreateSemaphoreW ReleaseSemaphore
HeapAlloc HeapFree HeapReAlloc GetProcessHeap GlobalAlloc GlobalFree
LocalAlloc LocalFree EnterCriticalSection LeaveCriticalSection
TryEnterCriticalSection InitializeCriticalSection DeleteCriticalSection
InitializeCriticalSectionAndSpinCount
TlsAlloc TlsFree TlsGetValue TlsSetValue
TerminateProcess ExitProcess IsDebuggerPresent OutputDebugStringA
OutputDebugStringW InterlockedIncrement InterlockedDecrement
InterlockedExchange InterlockedCompareExchange InterlockedExchangeAdd
QueryPerformanceCounter QueryPerformanceFrequency GetTickCount64 GetTickCount
WideCharToMultiByte MultiByteToWideChar GetLastError SetLastError
GetCurrentProcess GetCurrentThread GetCurrentThreadId GetCurrentProcessId
IsProcessorFeaturePresent
""".split())

BOOL_LITERALS = frozenset(("TRUE", "FALSE", "true", "false", "0", "1"))

# ------------------------------------------------------------------- scanning

_TOKEN = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


def strip_code(raw: str) -> str:
    """Blank comments, string and char literals in place, preserving every
    newline so line numbers survive. Handles line splices and raw strings; a
    token inside a string or a comment is not a use, which is the whole point:
    the F-634 repair notes name every one of the bad names, and counting those
    as uses would make the repaired tree look broken."""
    out = list(raw)
    i, n = 0, len(raw)
    while i < n:
        c = raw[i]
        if c == "\\" and i + 1 < n and raw[i + 1] == "\n":
            i += 2
            continue
        if c == "/" and i + 1 < n and raw[i + 1] == "/":
            j = raw.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        elif c == "/" and i + 1 < n and raw[i + 1] == "*":
            j = raw.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if raw[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j, quote, triple = i + 1, c, False
            if raw[i:i + 3] == c * 3:
                j, triple = i + 3, True
                end = raw.find(c * 3, j)
                j = n if end < 0 else end + 3
            else:
                while j < n:
                    if raw[j] == "\\":
                        j += 2
                        continue
                    if raw[j] == quote or raw[j] == "\n":
                        j += 1
                        break
                    j += 1
            del triple
            for k in range(i, j):
                if raw[k] != "\n":
                    out[k] = " "
            i = j
        else:
            i += 1
    return "".join(out)


class Txt:
    """Text with O(log n) line numbers and O(1) brace matching.

    Both were quadratic before (a `text.count('\\n', 0, off)` per token, a
    forward scan per brace), which is the difference between 6 s and 7 min on a
    33 MB header corpus. Braces are matched with one linear pass into a dict."""

    __slots__ = ("s", "_nl", "_br")

    def __init__(self, s: str):
        self.s = s
        self._nl: list[int] | None = None
        self._br: dict[int, int] | None = None

    def line(self, off: int) -> int:
        if self._nl is None:
            self._nl = [m.start() for m in re.finditer("\n", self.s)]
        return bisect.bisect_left(self._nl, off) + 1

    def close(self, ob: int) -> int:
        if self._br is None:
            pairs: dict[int, int] = {}
            stack: list[int] = []
            s = self.s
            for i, c in enumerate(s):
                if c == "{":
                    stack.append(i)
                elif c == "}" and stack:
                    pairs[stack.pop()] = i
            self._br = pairs
        return self._br.get(ob, -1)

    def sub(self, a: int, b: int) -> str:
        return self.s[a:b]


def line_of(text: str, off: int) -> int:
    return text.count("\n", 0, off) + 1


def snippet(raw: str, off: int, width: int = 96) -> str:
    ls = raw.rfind("\n", 0, off) + 1
    le = raw.find("\n", off)
    s = raw[ls:le if le > 0 else len(raw)].strip()
    return s[:width] + ("..." if len(s) > width else "")


# ------------------------------------------------------------ header parsing

_DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]*(.*)$", re.M)
_ENUM_HEAD = re.compile(r"\benum\b[ \t]*(?:(?:class|struct)[ \t]*)?([A-Za-z_]\w*)?[ \t\r\n]*\{")
_STRUCT_HEAD = re.compile(r"\b(struct|union|class)[ \t]+([A-Za-z_]\w*)[ \t\r\n]*(?::[^{;]{0,200}?)?\{")
# COM interface bodies carry no `struct` keyword: the SDK writes
#   MIDL_INTERFACE("uuid")\nID3D12Object : public IUnknown\n{ ... }
# and the vendored DXC writes
#   DECLARE_INTERFACE_(ID3D12ShaderReflection, IUnknown)\n{ ...
_IFACE_MIDL = re.compile(
    r"\bMIDL_INTERFACE\s*\(\s*\"[^\"]*\"\s*\)[ \t\r\n]*"
    r"([A-Za-z_]\w*)[ \t\r\n]*:[ \t\r\n]*public[ \t]+([A-Za-z_]\w*)[ \t\r\n]*\{")
# ... and the base-less form, which is how unknwn.h declares IUnknown itself.
_IFACE_MIDL_PLAIN = re.compile(
    r"\bMIDL_INTERFACE\s*\(\s*\"[^\"]*\"\s*\)[ \t\r\n]*([A-Za-z_]\w*)[ \t\r\n]*\{")
_IFACE_DXC_BASE = re.compile(
    r"\bDECLARE_INTERFACE_[ \t]*\([ \t]*([A-Za-z_]\w*)[ \t]*,[ \t]*([A-Za-z_]\w*)[ \t]*\)"
    r"[ \t\r\n]*\{")
_IFACE_DXC = re.compile(r"\bDECLARE_INTERFACE[ \t]*\([ \t]*([A-Za-z_]\w*)[ \t]*\)[ \t\r\n]*\{")
_METHOD_MACRO = re.compile(r"\b(STDMETHODCALLTYPE|STDMETHOD|PURE|virtual|override)\b")
_STD_METHOD_NAME = re.compile(r"\bSTDMETHOD_?\s*\(([^)]*)\)")
_FUNC_DECL = re.compile(
    r"([A-Za-z_]\w*)\s*\((?:[^()]|\([^()]*\))*\)\s*(?:const\s*)?"
    r"(?:override\s*)?(?:=\s*0\s*)?(?:PURE)?\s*$")
_MEMBER_PLAIN = re.compile(r"^(?P<type>[A-Za-z_][\w:<>,~ \t*&]*?)[ \t*&]+(?P<name>[A-Za-z_]\w*)$")
_MEMBER_ARRAY = re.compile(r"^(?P<type>[A-Za-z_][\w:<>,~ \t*&]*?)[ \t*&]+(?P<name>[A-Za-z_]\w*)[ \t]*\[[^\]]*\]$")
_MEMBER_BITS = re.compile(r"^(?P<type>[A-Za-z_][\w:<>,~ \t*&]*?)[ \t*&]+(?P<name>[A-Za-z_]\w*)[ \t]*:[ \t]*(?P<width>\d+)$")

SIZE_OF = {
    "uint8_t": 1, "int8_t": 1, "BYTE": 1, "char": 1, "bool": 1, "_Bool": 1,
    "uint16_t": 2, "int16_t": 2, "WORD": 2, "short": 2,
    "uint32_t": 4, "int32_t": 4, "DWORD": 4, "unsigned": 4, "UINT": 4,
    "int": 4, "long": 4, "float": 4, "HRESULT": 4, "ULONG": 4, "LONG": 4,
    "uint64_t": 8, "int64_t": 8, "ULONGLONG": 8, "LONGLONG": 8,
    "size_t": 8, "std::size_t": 8, "uintptr_t": 8, "intptr_t": 8, "SIZE_T": 8,
    "UINT64": 8, "UINTPTR_T": 8,
}


class Parsed:
    """What one file declares. Everything is optional; absence means UNKNOWN."""

    __slots__ = ("path", "defs", "macros", "enums", "enum_of", "structs",
                 "bases", "ifaces", "tags", "bitfields")

    def __init__(self, path: Path):
        self.path = path
        self.defs: dict[str, tuple[int, str]] = {}        # name -> (line, kind)
        self.macros: dict[str, tuple[str, int]] = {}     # name -> (value, line)
        self.enums: dict[str, dict[str, tuple[int, int]]] = {}   # enum -> member -> (value, line)
        self.enum_of: dict[str, tuple[str, int, int]] = {}       # member -> (enum, value, line)
        self.structs: dict[str, dict] = {}                # struct -> {members, complete, line}
        self.bases: dict[str, str] = {}
        self.ifaces: dict[str, dict] = {}                 # iface -> {methods, base, line}
        self.tags: set[str] = set()
        self.bitfields: dict[str, dict] = {}              # struct -> {bits, base, count}

    def note(self, name: str, line: int, kind: str) -> None:
        self.defs.setdefault(name, (line, kind))


def _matching_brace(text: str, open_at: int) -> int:
    depth = 0
    for i in range(open_at, len(text)):
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i
    return -1


def _split_statements(body: str) -> list[str]:
    out, depth, start = [], 0, 0
    for i, c in enumerate(body):
        if c in "{([":
            depth += 1
        elif c in "})]":
            depth -= 1
        elif c == ";" and depth == 0:
            out.append(body[start:i])
            start = i + 1
    tail = body[start:].strip()
    if tail:
        out.append(tail)
    return out


def _split_enum_items(body: str) -> list[str]:
    """Enums are comma-separated and `;`-free. d3d12.h separates with a TAB."""
    out, depth, start = [], 0, 0
    for i, c in enumerate(body):
        if c in "{([":
            depth += 1
        elif c in "})]":
            depth -= 1
        elif c == "," and depth == 0:
            out.append(body[start:i])
            start = i + 1
    tail = body[start:]
    if tail.strip():
        out.append(tail)
    return out


def _eval_int(expr: str, known: dict[str, int], macros: dict[str, tuple[str, int]]) -> int | None:
    e = expr.strip().rstrip(",").strip()
    e = re.sub(r"\b(0[xX][0-9a-fA-F]+|\d+)[uUlL]*\b", r"\1", e)
    e = e.replace("(", " ").replace(")", " ")
    for name, val in list(macros.items()):
        v = val[0].strip().rstrip("uUlL")
        if re.fullmatch(r"0[xX][0-9a-fA-F]+|\d+", v):
            e = re.sub(r"\b%s\b" % re.escape(name), v, e)
    if re.fullmatch(r"[0-9a-fA-FxX+\-*/|&<>~^ ]+", e) and e.strip():
        try:
            return int(eval(e, {"__builtins__": {}}, {}))  # arithmetic only, from a
        except Exception:                                   # digit-only whitelist
            return None
    parts = [p.strip() for p in e.split("|") if p.strip()]
    if len(parts) > 1:
        vals = []
        for p in parts:
            v = _eval_int(p, known, macros)
            if v is None:
                return None
            vals.append(v)
        acc = 0
        for v in vals:
            acc |= v
        return acc
    return known.get(parts[0]) if len(parts) == 1 else None


def _classify_statement(stmt: str) -> tuple[str, dict | None]:
    """-> ('member'|'method'|'skip'|'unknown', parsed dict)."""
    s = " ".join(stmt.split())
    if not s:
        return "skip", None
    if s.startswith("#"):
        return "skip", None
    for kw in ("typedef", "friend", "static_assert", "using ", "public:", "private:",
               "protected:", "return", "template", "operator"):
        if s.startswith(kw):
            return "skip", None
    if s.startswith(("struct ", "union ", "class ", "enum ")) and "{" not in s:
        return "skip", None
    if "(" in s:
        if _METHOD_MACRO.search(s) or s.startswith("virtual"):
            norm = _STD_METHOD_NAME.sub(lambda m: m.group(1).split(",")[-1].strip(), s)
            m = _FUNC_DECL.search(norm)
            if m:
                return "method", {"name": m.group(1)}
        return "skip", None  # function pointer member, ctor, operator: not modelled
    for rx, kind in ((_MEMBER_BITS, "bits"), (_MEMBER_ARRAY, "array"), (_MEMBER_PLAIN, "plain")):
        m = rx.match(s)
        if m:
            d = m.groupdict()
            d["type"] = (d.get("type") or "").strip()
            d["kind"] = kind
            if kind == "bits":
                d["width"] = int(d["width"])
            d["array"] = kind == "array"
            return "member", d
    return "unknown", None


def parse_file(path: Path, text: str | Txt) -> Parsed:
    """Parse one C/C++ header or source. `text` must already be comment-stripped."""
    t = text if isinstance(text, Txt) else Txt(text)
    p = Parsed(path)
    # --- macros (with line splices)
    for m in _DEFINE.finditer(t.s):
        name, rest = m.group(1), m.group(2)
        cont = rest
        k = m.end()
        while cont.endswith("\\") and k < len(t.s):
            nxt = t.s.find("\n", k)
            if nxt < 0:
                break
            cont = cont[:-1] + " " + t.s[k + 1:nxt]
            k = nxt + 1
        p.macros.setdefault(name, (cont.strip(), t.line(m.start())))
        p.note(name, p.macros[name][1], "macro")

    # --- enums
    for m in _ENUM_HEAD.finditer(t.s):
        ob = t.s.index("{", m.end() - 1)
        cb = t.close(ob)
        if cb < 0:
            continue
        name = m.group(1)
        body = t.s[ob + 1:cb]
        after = t.s[cb + 1:cb + 200]
        tm = re.match(r"\s*([A-Za-z_]\w*)\s*;", after)
        if tm and not name:
            name = tm.group(1)
        members, cur, pos = {}, 0, 0
        for raw in _split_enum_items(body):
            at = body.find(raw, pos)
            pos = max(at, 0) + len(raw)
            item = " ".join(raw.split())
            if not item:
                continue
            em = re.match(r"^([A-Za-z_]\w*)\s*(?:=\s*(.+?))?$", item)
            if not em:
                continue
            ename, eexpr = em.group(1), em.group(2)
            line = t.line(ob + 1 + max(at, 0)) if at >= 0 else 0
            if eexpr is None:
                val = cur
            else:
                val = _eval_int(eexpr, {k2: v[0] for k2, v in members.items()}, p.macros)
            if val is None:
                p.note(ename, line, "enumerator?")
                continue
            cur = val + 1 if eexpr is None else val
            members[ename] = (val, line)
            p.note(ename, line, "enumerator")
        if name:
            p.enums.setdefault(name, members).update(members)
            p.tags.add(name)
        for ename, (val, line) in members.items():
            p.enum_of[ename] = (name or "?", val, line)

    # --- structs / unions / classes / interfaces
    aliases: list[tuple[str, str]] = []

    seen_open: set[int] = set()

    def absorb(name: str, kind: str, ob: int, cb: int, base: str | None, is_iface: bool) -> None:
        if ob in seen_open:
            return
        seen_open.add(ob)
        body = t.s[ob + 1:cb]
        line = t.line(ob)
        p.tags.add(name)
        p.note(name, line, "interface" if is_iface else kind)
        members, methods, complete = {}, {}, True
        bits_total, bits_base, bits_count = 0, None, 0
        pos = 0
        for raw in _split_statements(body):
            kind2, d = _classify_statement(raw)
            at = body.find(raw, pos)
            pos = max(at, 0) + len(raw)
            rline = t.line(ob + 1 + max(at, 0)) if at >= 0 else line
            if kind2 == "member":
                d["line"] = rline
                members[d["name"]] = d
                if d["kind"] == "bits":
                    bits_total += d["width"]
                    bits_count += 1
                    bits_base = bits_base or d["type"].split("::")[-1]
            elif kind2 == "method":
                methods[d["name"]] = rline
            elif kind2 == "unknown":
                complete = False
        if methods and not members:
            p.ifaces[name] = {"methods": methods, "base": base or p.bases.get(name), "line": line}
        if base:
            p.bases[name] = base
        p.structs[name] = {"members": members, "methods": methods,
                           "complete": complete, "line": line}
        if bits_count:
            p.bitfields[name] = {"bits": bits_total, "base": bits_base, "count": bits_count}
        tm = re.match(r"[ \t\r\n]*([A-Za-z_]\w*)[ \t]*;", t.s[cb + 1:cb + 120])
        if tm and tm.group(1) != name:
            aliases.append((tm.group(1), name))

    for m in _STRUCT_HEAD.finditer(t.s):
        kind, name = m.group(1), m.group(2)
        if not name or name in ("if", "for", "while", "switch", "return", "sizeof"):
            continue
        ob = t.s.index("{", m.end() - 1)
        cb = t.close(ob)
        if cb < 0:
            continue
        bm = re.search(r":[ \t\r\n]*public[ \t]+([A-Za-z_]\w*)", t.s[m.end(2):ob])
        absorb(name, kind, ob, cb, bm.group(1) if bm else None, False)
    for rx, base_group in ((_IFACE_MIDL, 2), (_IFACE_DXC_BASE, 2), (_IFACE_DXC, None),
                          (_IFACE_MIDL_PLAIN, None)):
        for m in rx.finditer(t.s):
            name = m.group(1)
            ob = t.s.index("{", m.end() - 1)
            cb = t.close(ob)
            if cb < 0:
                continue
            base = m.group(base_group) if base_group else None
            absorb(name, "interface", ob, cb, base, True)

    # `typedef struct _X { ... } Y;` -- Y names the same type as _X
    for alias, target in aliases:
        if target in p.structs and alias not in p.structs:
            p.structs[alias] = p.structs[target]
            if target in p.bitfields:
                p.bitfields[alias] = p.bitfields[target]
            p.tags.add(alias)
            p.note(alias, p.structs[target]["line"], "typedef")

    # --- typedefs
    for m in re.finditer(r"\btypedef\b([^;]{0,400});", t.s):
        seg = " ".join(m.group(1).split())
        if not seg:
            continue
        mm = re.search(r"([A-Za-z_]\w*)[ \t]*(\[\s*\d+\s*\])?$", seg)
        if mm:
            p.note(mm.group(1), t.line(m.start()), "typedef")
    for m in re.finditer(
            r"\b(?:WINBASEAPI|WINAPI|APIENTRY|extern \"C\"|__declspec\([^)]*\))"
            r"[^;{}]{0,300}?([A-Za-z_]\w*)[ \t]*\([^;]{0,300}\)[^;]{0,80};", t.s):
        p.note(m.group(1), t.line(m.start()), "function")
    return p


# --------------------------------------------------------------- header index

class HeaderIndex:
    """Every declaration reachable from a set of include roots, resolved from the
    real headers on this machine. Nothing is hardcoded."""

    def __init__(self, roots: list[tuple[str, Path]], cache: Path, verbose: bool = False):
        self.roots = roots
        self.verbose = verbose
        self.cache = cache
        self.cache.mkdir(parents=True, exist_ok=True)
        self.files: list[Path] = []
        self.owner: dict[Path, str] = {}
        seen_files: set[str] = set()
        for label, root in roots:
            for f in sorted(root.rglob("*")):
                if f.is_file() and f.suffix.lower() in HDR_SUFFIXES:
                    key = os.path.normcase(str(f))
                    if key in seen_files:
                        continue
                    seen_files.add(key)
                    self.files.append(f)
                    self.owner[f] = label
        self._by_name: dict[str, list[Path]] = {}
        self._parsed: dict[Path, Parsed] = {}
        self._parsed_cache = self.cache / "parsed"
        self._parsed_cache.mkdir(parents=True, exist_ok=True)
        self.unparsed: set[Path] = set()
        self._blob: dict[Path, str] = {}

    # -- discovery -----------------------------------------------------------
    def candidates_for(self, names: set[str]) -> dict[Path, list[Path]]:
        low: dict[str, list[Path]] = defaultdict(list)
        for f in self.files:
            low[f.name.lower()].append(f)
        for n in names:
            low[n.lower()].append(None)  # keep the key alive
        return low

    def blob(self, path: Path) -> str:
        b = self._blob.get(path)
        if b is None:
            try:
                raw = path.read_bytes().decode("latin-1")
            except OSError:
                raw = ""
            b = strip_code(raw)
            self._blob[path] = b
        return b

    def parsed(self, path: Path) -> Parsed | None:
        if path in self._parsed:
            return self._parsed[path]
        if path in self.unparsed:
            return None
        try:
            st = path.stat()
        except OSError:
            self.unparsed.add(path)
            return None
        key = hashlib.sha1(str(path).encode()).hexdigest()[:16]
        cfile = self._parsed_cache / f"v{PARSER_VERSION}.{key}.{st.st_size}.{st.st_mtime_ns}.pkl"
        obj = None
        if cfile.exists():
            try:
                obj = pickle.loads(cfile.read_bytes())
            except Exception:
                obj = None
        if obj is None:
            try:
                obj = parse_file(path, self.blob(path))
            except Exception as exc:                      # a header this parser
                if self.verbose:                           # cannot read is UNKNOWN,
                    print(f"#   note: {path.name}: {exc}", file=sys.stderr)  # never FOUND
                self.unparsed.add(path)
                return None
            try:
                cfile.write_bytes(pickle.dumps(obj))
            except Exception:
                pass
        self._parsed[path] = obj
        return obj

    # -- the two indices -----------------------------------------------------
    def build_name_index(self, query: set[str], scope: list[Path], sig: str) -> dict[str, list[tuple[Path, int, str]]]:
        """name -> [(file, line, kind)] over `scope`, for the query set only."""
        cache = self.cache / f"names.{sig}.{hashlib.sha1('|'.join(sorted(query)).encode()).hexdigest()[:12]}.pkl"
        if cache.exists():
            try:
                return pickle.loads(cache.read_bytes())
            except Exception:
                pass
        idx: dict[str, list[tuple[Path, int, str]]] = defaultdict(list)
        qb = {n.encode("latin-1") for n in query}
        tok = re.compile(rb"[A-Za-z_][A-Za-z0-9_]*")
        for f in scope:
            try:
                data = f.read_bytes()
            except OSError:
                continue
            line = 1
            last = 0
            for m in tok.finditer(data):
                t = m.group(0)
                if t in qb:
                    name = t.decode("latin-1")
                    if len(idx[name]) < 4:
                        line += data.count(b"\n", last, m.start())
                        last = m.start()
                        idx[name].append((f, line, "token"))
        out = dict(idx)
        try:
            cache.write_bytes(pickle.dumps(out))
        except Exception:
            pass
        return out


class Tree:
    """The project's own declarations: what src/** defines, per file."""

    def __init__(self):
        self.by_file: dict[Path, Parsed] = {}
        self.global_defs: dict[str, list[tuple[Path, int, str]]] = defaultdict(list)

    def add(self, path: Path, p: Parsed) -> None:
        self.by_file[path] = p
        for name, (line, kind) in p.defs.items():
            self.global_defs[name].append((path, line, kind))


# ------------------------------------------------------------------ findings

class Finding:
    __slots__ = ("check", "name", "path", "line", "detail", "anchor", "snippet")

    def __init__(self, check, name, path, line, detail, anchor="", snippet=""):
        self.check = check
        self.name = name
        self.path = path
        self.line = line
        self.detail = detail
        self.anchor = anchor
        self.snippet = snippet

    def as_dict(self) -> dict:
        return {"check": self.check, "name": self.name, "file": str(self.path),
                "line": self.line, "detail": self.detail, "anchor": self.anchor,
                "snippet": self.snippet}

    def sort_key(self):
        return (self.check, str(self.path), self.line, self.name)


def rel(p: Path) -> str:
    try:
        return p.resolve().relative_to(REPO).as_posix()
    except Exception:
        try:
            return p.relative_to(REPO).as_posix()
        except Exception:
            return str(p)


# ------------------------------------------------------------- source model

class SrcModel:
    """Everything the checks need from src/**, gathered in one pass."""

    def __init__(self) -> None:
        self.candidates: dict[str, list[tuple[Path, int]]] = defaultdict(list)
        self.vars: dict[Path, dict[str, str]] = defaultdict(dict)      # file -> var -> type
        self.ambiguous: set[tuple[Path, str]] = set()
        self.members: dict[Path, dict[str, str]] = defaultdict(dict)   # file -> class -> field
        self.calls: list[tuple[str, Path, int, str, str]] = []          # method, file, line, recv, op
        self.chains: list[tuple[tuple[str, ...], Path, int]] = []       # member chain
        self.enum_assigns: list[tuple[str, str, str, Path, int]] = []   # recv, field, literal
        self.bitfield_asserts: list[tuple[str, str, Path, int]] = []    # struct, expected, file, line
        self.tables: list[tuple[str, str, int, Path, int]] = []         # name, value, enum, file, line
        self.mutex_cases: list[tuple[Path, int, str, str, int]] = []    # file, line, class, field, fnline
        self.unresolved_sites: list[tuple[str, Path, int, str]] = []
        self.file_text: dict[Path, str] = {}


# platform-name candidates, member chains, calls: regexes over the stripped text
_DECL_TYPE = re.compile(
    r"\b(?:const[ \t]+|constexpr[ \t]+|static[ \t]+)*(?:struct[ \t]+)?"
    r"(?P<type>[A-Z][A-Za-z0-9_]*(?:::\w+)*(?:<[^;(){}]{0,120}>)?)\s*[*&]?[ \t]*"
    r"(?<![A-Za-z0-9_])(?P<name>[a-z_]\w*)\s*(?=[=;,)\[])")
_CALL = re.compile(r"(?P<recv>[A-Za-z_]\w*)\s*(?P<op>->|\.)\s*(?P<method>[A-Za-z_]\w*)\s*\(")
_CHAIN = re.compile(r"(?P<base>[A-Za-z_]\w*)\s*(?P<rest>(?:(?:->|\.)\s*[A-Za-z_]\w*\s*(?:\[[^\]]*\])?\s*)+)")
_ASSIGN = re.compile(r"(?P<recv>[A-Za-z_]\w*)\s*(?:\.|->)\s*(?P<field>[A-Za-z_]\w*)\s*=\s*(?P<lit>TRUE|FALSE|true|false|0|1)\s*;")
_SIZEOF_ASSERT = re.compile(
    r"static_assert\s*\(\s*sizeof\s*\(\s*(?P<what>[A-Za-z_]\w*)\s*\)\s*==\s*sizeof\s*\(\s*(?P<type>[\w:]+)\s*\)")
_STATIC_ASSERT_EQ = re.compile(
    r"static_assert\s*\(\s*sizeof\s*\(\s*(?P<what>[A-Za-z_]\w*)\s*\)\s*==\s*(?P<num>\d+)")
_ENUM_ENTRY = re.compile(
    r"^[ \t]*(?P<name>[A-Za-z_]\w*)[ \t]*=[ \t]*(?P<value>0[xX][0-9a-fA-F]+|\d+)[uUlL]*[ \t]*(?:,|$)", re.M)
_TABLE_HEAD = re.compile(r"\benum\b[ \t]*(?:\:[ \t]*[A-Za-z_][\w:<>]*)?[ \t\r\n]*\{")
_LOCK_IN_CONST = re.compile(r"lock_guard\s*<[^>]*>\s*\w+\s*\(\s*(?P<field>[A-Za-z_]\w*)\s*\)")
_CONST_FN = re.compile(r"^[ \t]*(?P<ret>[\w:<>,* \t&]*?)\b(?P<name>[A-Za-z_]\w*)\s*\([^;{]*\)[ \t\r\n]*(?:const[ \t\r\n]*)?\{", re.M)
_COMMON_TMPL = re.compile(r"^[ \t]*(?:template\s*<[^>]*>\s*)?(?:class|struct)\s+([A-Za-z_]\w*)\s*\{", re.M)


def collect_src(files: list[Path], model: SrcModel) -> None:
    for path in files:
        try:
            raw = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        code = Txt(strip_code(raw))
        model.file_text[path] = raw
        s = code.s
        # 1. platform-shaped names
        for m in _TOKEN.finditer(s):
            t = m.group(0)
            if is_candidate(t):
                model.candidates[t].append((path, code.line(m.start())))
        # 2. declarations that give a variable a struct/interface type
        for m in _DECL_TYPE.finditer(s):
            ty, nm = m.group("type"), m.group("name")
            if nm in ("return", "sizeof", "if", "for", "while", "switch", "new", "delete",
                      "case", "else", "const", "static", "co_await", "operator"):
                continue
            tgt = model.vars[path]
            prev = tgt.get(nm)
            if prev is None:
                tgt[nm] = ty
            elif prev != ty:
                model.ambiguous.add((path, nm))
        # 3. member calls
        for m in _CALL.finditer(s):
            model.calls.append((m.group("method"), path, code.line(m.start()),
                                m.group("recv"), m.group("op")))
        # 4. member chains -- token-by-token, stopping at the first `(` so a
        #    method call is never mistaken for a field read (check 2 owns calls)
        for m in _CHAIN.finditer(s):
            steps = _chain_steps(m.group("rest"))
            if steps:
                model.chains.append(((m.group("base"),) + tuple(steps), path, code.line(m.start())))
        # 5. enum-typed member assigned a bool literal
        for m in _ASSIGN.finditer(s):
            model.enum_assigns.append((m.group("recv"), m.group("field"), m.group("lit"),
                                       path, code.line(m.start())))
        # 6. bitfield size asserts
        for m in _SIZEOF_ASSERT.finditer(s):
            model.bitfield_asserts.append((m.group("what"), SIZE_OF.get(m.group("type"), -1),
                                          path, code.line(m.start())))
        for m in _STATIC_ASSERT_EQ.finditer(s):
            model.bitfield_asserts.append((m.group("what"), int(m.group("num")),
                                          path, code.line(m.start())))
        # 7. constant tables
        for m in _TABLE_HEAD.finditer(s):
            cb = code.close(s.index("{", m.end() - 1))
            if cb < 0:
                continue
            body = s[m.end():cb]
            head = m.group(0)
            for em in _ENUM_ENTRY.finditer(body):
                model.tables.append((em.group("name"), em.group("value"), head.strip(),
                                     path, code.line(m.end() + em.start())))
        # 8. non-mutable mutex locked from a const member function
        for cm in _COMMON_TMPL.finditer(s):
            cls = cm.group(1)
            ob = s.index("{", cm.end() - 1)
            cb = code.close(ob)
            if cb < 0:
                continue
            body = s[ob + 1:cb]
            _MUTEX_MEM = re.compile(
                r"^(?P<all>[ \t]*(?:mutable[ \t]+)?)std::(?:mutex|shared_mutex|timed_mutex"
                r"|recursive_mutex)[ \t]+(?P<field>[A-Za-z_]\w*)[ \t]*;", re.M)
            bad = {mm.group("field") for mm in _MUTEX_MEM.finditer(body)
                   if "mutable" not in mm.group("all")}
            if not bad:
                continue
            for fm in _CONST_FN.finditer(body):
                if "const" not in fm.group(0):
                    continue
                seg_start = fm.end()
                cb2 = Txt(body).close(seg_start - 1)
                seg = body[seg_start:cb2 if cb2 > 0 else len(body)]
                for lm in _LOCK_IN_CONST.finditer(seg):
                    if lm.group("field") in bad:
                        model.mutex_cases.append((path, code.line(ob + 1 + seg_start + lm.start()),
                                                 cls, lm.group("field"),
                                                 code.line(ob + 1 + fm.start())))


def _chain_steps(rest: str) -> list[str]:
    """['a', 'b'] from `.a->b[3].c`, stopping before a method call."""
    steps: list[str] = []
    i, n = 0, len(rest)
    while i < n:
        if rest[i] == "." or rest.startswith("->", i):
            j = i + (2 if rest.startswith("->", i) else 1)
            while j < n and rest[j] in " \t":
                j += 1
            k = j
            while k < n and (rest[k].isalnum() or rest[k] == "_"):
                k += 1
            if k == j:
                return steps
            name = rest[j:k]
            while k < n and rest[k] in " \t":
                k += 1
            if k < n and rest[k] == "(":
                return steps                      # a call, not a field
            steps.append(name)
            if k < n and rest[k] == "[":
                depth = 0
                while k < n:
                    if rest[k] == "[":
                        depth += 1
                    elif rest[k] == "]":
                        depth -= 1
                        if depth == 0:
                            k += 1
                            break
                    k += 1
            i = k
        else:
            i += 1
    return steps


def is_candidate(tok: str) -> bool:
    if not ALL_CAPS.match(tok):
        if not IFACE_RE.match(tok):
            if tok in WIN32_NAMES or HANDLE_RE.match(tok):
                return True
            if tok in ("NTSTATUS", "HRESULT", "IUnknown"):
                return True
            return False
    for p in PLAT_PREFIXES:
        if tok.startswith(p):
            return len(tok) > len(p)
    return False


# ------------------------------------------------------------ name resolution

class Resolver:
    """Resolves a name for one TU: header closure + project files that TU sees."""

    def __init__(self, hidx: HeaderIndex, tree: Tree, include_map, root_dirs):
        self.hidx = hidx
        self.tree = tree
        self.include_map = include_map
        self.root_dirs = root_dirs
        self._closures: dict[Path, frozenset] = {}

    def closure(self, tu: Path, cap: int = 3000) -> tuple[frozenset, str | None]:
        if tu in self._closures:
            return self._closures[tu]
        seen: set[Path] = set()
        stack: list[tuple[Path, Path]] = [(tu, tu.parent)]
        note = None
        while stack:
            f, base = stack.pop()
            try:
                key = f.resolve()
            except OSError:
                continue
            if key in seen:
                continue
            if len(seen) >= cap:
                note = f"include closure capped at {cap} files"
                break
            seen.add(key)
            try:
                txt = f.read_text(encoding="utf-8", errors="replace")
            except OSError:
                continue
            for m in re.finditer(r'^[ \t]*#[ \t]*include[ \t]*[<"]([^">]+)[">]', txt, re.M):
                inc = m.group(1)
                cands = []
                cand = base / inc
                if cand.exists():
                    cands.append(cand)
                for d in self.root_dirs:
                    c = d / inc
                    if c.exists() and c not in cands:
                        cands.append(c)
                for c in self.include_map.get(Path(inc).name.lower(), []):
                    if c not in cands:
                        cands.append(c)
                for c in cands:
                    if c.suffix.lower() in HDR_SUFFIXES or c.suffix.lower() in SRC_SUFFIXES:
                        stack.append((c, c.parent))
                        break
        fs = frozenset(seen)
        self._closures[tu] = (fs, note)
        return fs, note


# ------------------------------------------------------------------- checks

def _members_of(parsed_map, name, depth=0):
    """members ∪ inherited members; None if any base is unknown."""
    out, seen = {}, set()
    cur, d = name, 0
    while cur and d < 6:
        p = parsed_map.get(cur)
        if p is None:
            return None
        st = p.structs.get(cur)
        if st is None:
            return None
        for k, v in st["members"].items():
            out.setdefault(k, (v, cur, p))
        seen.add(cur)
        cur = p.bases.get(cur)
        d += 1
    if cur:
        return None          # a base we never parsed -> UNKNOWN, not a verdict
    return out


def _methods_of(parsed_map, name, depth=0):
    out, cur, d, unresolved = {}, name, 0, False
    while cur and d < 6:
        p = parsed_map.get(cur)
        if p is None:
            return None, True
        iface = p.ifaces.get(cur)
        if iface is None:
            st = p.structs.get(cur)
            if st is None:
                return None, True
            for k, v in st["members"].items():
                out.setdefault(k, (v, cur, p))
        else:
            for k, v in iface["methods"].items():
                out.setdefault(k, (v, cur, p))
        cur = (iface or {}).get("base") or p.bases.get(cur)
        d += 1
    if cur:
        unresolved = True
    return out, unresolved


def _unwrap_type(ty: str) -> str:
    """ComPtr<T>/CComPtr<T>/Microsoft::WRL::ComPtr<T>/wil::com_ptr<T> -> T."""
    m = re.search(r"([A-Za-z_]\w*)\s*<\s*([A-Za-z_]\w*)\s*>$", ty.strip())
    if m and m.group(1).lower().endswith(("comptr", "com_ptr", "unique_ptr", "shared_ptr", "scoped_ptr")):
        return m.group(2)
    return ty


def _lookup_type(name: str, parsed_map, tree_scope) -> Parsed | None:
    return parsed_map.get(name)


# --------------------------------------------------------------- the auditor

class Audit:
    def __init__(self, hidx: HeaderIndex, tree: Tree, resolver: Resolver,
                 model: SrcModel, verbose: bool = False):
        self.hidx = hidx
        self.tree = tree
        self.res = resolver
        self.m = model
        self.verbose = verbose
        self.findings: list[Finding] = []
        self.stats = defaultdict(int)
        self.unresolved: list[tuple[str, Path, int, str]] = []
        self._defs_cache: dict[Path, dict[str, tuple[Path, int, str]]] = {}
        self._code_check: dict[tuple[Path, str], bool] = {}
        self._unreachable_reason: dict[Path, str] = {}
        self._query = set(getattr(hidx, "name_index", {})) | set(model.candidates)

    # -- name -> (verdict, file, line, kind) -------------------------------
    def _closure_defs(self, tu: Path) -> dict[str, tuple[Path, int, str]]:
        """{name: (file, line, kind)} for the query names, from this TU's closure."""
        cached = self._defs_cache.get(tu)
        if cached is not None:
            return cached
        closure, note = self.res.closure(tu)
        if note:
            self._unreachable_reason[tu] = note
            return {}
        out: dict[str, tuple[Path, int, str]] = {}
        for f in sorted(closure):
            pp = self.hidx.parsed(f)
            if pp is None:
                continue
            for name, (line, kind) in pp.defs.items():
                if name in self.hidx.name_index or name in self._query:
                    out.setdefault(name, (f, line, kind))
        self._defs_cache[tu] = out
        return out

    def resolve(self, name: str, tu: Path) -> tuple[str, object]:
        closure, note = self.res.closure(tu)
        if note:
            return "UNRESOLVED", note
        cd = self._closure_defs(tu)
        if name in cd:
            f, line, kind = cd[name]
            return "FOUND", (f, line, kind)
        for p, line, kind in self.tree.global_defs.get(name, []):
            if p in closure:
                return "FOUND", (p, line, kind)
            return "NOT-REACHABLE", (p, line, kind)
        hit = self.hidx.name_index.get(name)
        if hit:
            f, line, _ = hit[0]
            return ("NOT-REACHABLE" if self._in_code(f, name) else "NOT-IN-HEADER"), (f, line, "token")
        return "NOT-IN-HEADER", None

    def _in_code(self, f: Path, name: str) -> bool:
        """The name index reads raw bytes, so a header COMMENT counts as a hit.
        Confirm in comment-stripped text before blaming the TU. Bounded: only
        runs on the not-found path, and only over the first few candidates."""
        key = (f, name)
        if key in self._code_check:
            return self._code_check[key]
        res = False
        try:
            if f.stat().st_size <= 4_000_000:
                txt = self.hidx.blob(f)
                res = re.search(r"\b%s\b" % re.escape(name), txt) is not None
        except OSError:
            res = False
        self._code_check[key] = res
        return res

    def add(self, check, name, path, line, detail, anchor="", snip=""):
        self.findings.append(Finding(check, name, path, line, detail, anchor, snip))
        self.stats[check] += 1

    # -- check 1: invented platform names -----------------------------------
    def check_names(self):
        for name in sorted(self.m.candidates):
            sites = self.m.candidates[name]
            verdicts = {}
            for path, line in sites:
                v, info = self.resolve(name, path)
                verdicts.setdefault(v, []).append((path, line, info))
            if "FOUND" in verdicts:
                self.stats["found"] += 1
                continue
            if "UNRESOLVED" in verdicts:
                self.stats["unresolved"] += 1
                for path, line, info in verdicts["UNRESOLVED"]:
                    self.unresolved.append((name, path, line, str(info)))
                continue
            for v, entries in verdicts.items():
                for path, line, info in entries:
                    if v == "NOT-REACHABLE":
                        self.add("NOT-REACHABLE", name, path, line,
                                 f"defined in {rel(info[0])}:{info[1]} ({info[2]}), "
                                 f"not reachable from this translation unit",
                                 anchor=name, snip=snippet(self.m.file_text[path], 0) or "")
                    else:
                        self.add("PLATFORM-NAME", name, path, line,
                                 "no header in the include closure declares this name",
                                 anchor=name,
                                 snip=self._snip(path, name))
            self.stats["not-in-header"] += 1

    def _snip(self, path: Path, name: str) -> str:
        raw = self.m.file_text.get(path, "")
        i = raw.find(name)
        return snippet(raw, i) if i >= 0 else ""

    # -- check 2: COM method calls ------------------------------------------
    def check_com_methods(self):
        parsed_map = self._parsed_map()
        for method, path, line, recv, op in self.m.calls:
            ty = self._var_type(path, recv)
            if ty is None:
                self.stats["unknown-type"] += 1
                continue
            iface = self._find_iface(parsed_map, ty)
            if iface is None:
                continue
            methods, unresolved_base = _methods_of(parsed_map, iface)
            if methods is None or unresolved_base:
                self.stats["unknown-type"] += 1
                continue
            if method in methods:
                self.stats["method-found"] += 1
                continue
            owner = self._other_owner(parsed_map, method, skip=iface)
            where = methods_of_any(parsed_map, method, skip=iface)
            detail = (f"not a member of {iface}" +
                      (f"; it is a member of {', '.join(sorted(where)[:4])}" if where else
                       "; no parsed interface in the closure declares it"))
            self.add("COM-METHOD", method, path, line, detail, anchor=f"{recv}->{method}",
                     snip=self._snip(path, method))

    def _parsed_map(self) -> dict[str, Parsed]:
        pm: dict[str, Parsed] = {}
        for p in self.hidx._parsed.values():
            for t in p.tags:
                pm.setdefault(t, p)
        for p in self.tree.by_file.values():
            for t in p.tags:
                pm.setdefault(t, p)
        return pm

    def _find_iface(self, pm, ty: str) -> str | None:
        ty = _unwrap_type(ty)
        p = pm.get(ty)
        if p is None:
            return None
        if ty in p.ifaces:
            return ty
        return None

    def _other_owner(self, pm, method: str, skip: str) -> str:
        return methods_of_any(pm, method, skip=skip)

    def _var_type(self, path: Path, name: str) -> str | None:
        if (path, name) in self.m.ambiguous:
            return None
        t = self.m.vars.get(path, {}).get(name)
        if t is None:
            return None
        t = _unwrap_type(t)
        if t in ("auto", "const"):
            return None
        return t

    # -- check 3: struct members / wrong nesting ----------------------------
    def check_members(self):
        pm = self._parsed_map()
        for parts, path, line in self.m.chains:
            base = parts[0]
            ty = self._var_type(path, base)
            if ty is None:
                self.stats["unknown-type"] += 1
                continue
            curty = _unwrap_type(ty)
            ok = True
            for i, step in enumerate(parts[1:]):
                mems = _members_of(pm, curty) if curty in pm else None
                if mems is None:
                    self.stats["unknown-type"] += 1
                    ok = False
                    break
                if step in mems:
                    info = mems[step][0]
                    curty = info["type"].split("::")[-1].split("<")[0]
                    continue
                self._wrong_member(pm, mems, curty, step, parts, i, path, line)
                ok = False
                break
            if ok:
                self.stats["member-found"] += 1

    def _wrong_member(self, pm, mems, curty, step, parts, i, path, line) -> None:
        owners = self._struct_owner_of_member(pm, step)
        fam = curty.split("_")[0]
        near = sorted(o for o in owners if o.split("_")[0] == fam) or sorted(owners)
        detail = f"not a member of {curty}"
        down = None
        for mn, (minfo, mowner, _m) in mems.items():
            if minfo["type"].split("::")[-1].split("<")[0] in owners:
                down = (mowner, mn)
                break
        if down:
            detail += (f"; it is a member of {near[0]}, which is {down[0]}::{down[1]} "
                       f"-- one level down, so it needs {parts[0]}...{down[1]}[i].{step}")
        elif near:
            detail += f"; it is a member of {', '.join(near[:4])}"
        elif not owners:
            detail += "; no struct this parser understands declares it either"
        self.add("STRUCT-MEMBER", step, path, line, detail,
                 anchor=".".join(parts), snip=self._snip(path, step))

    def _struct_owner_of_member(self, pm, member: str) -> set[str]:
        out = set()
        for t, p in pm.items():
            st = p.structs.get(t)
            if st and member in st["members"]:
                out.add(t)
        return out

    # -- check 4: enum member assigned a bool -------------------------------
    def check_enum_assign(self):
        pm = self._parsed_map()
        for recv, field, lit, path, line in self.m.enum_assigns:
            ty = self._var_type(path, recv)
            if ty is None:
                self.stats["unknown-type"] += 1
                continue
            mems = _members_of(pm, _unwrap_type(ty)) if _unwrap_type(ty) in pm else None
            if mems is None or field not in mems:
                self.stats["unknown-type"] += 1
                continue
            info, owner, p = mems[field]
            mtype = info["type"].split("::")[-1]
            enum = p.enums.get(mtype)
            if not enum:
                other = self._enum_owner(pm, mtype)
                if not other:
                    self.stats["unknown-type"] += 1
                    continue
                enum = pm[other].enums.get(mtype) or {}
            self.add("ENUM-BOOL-ASSIGN", f"{recv}.{field}", path, line,
                     f"`{owner}::{mtype}` is an enum ({len(enum)} enumerators); "
                     f"assigned the literal `{lit}` -- use an enumerator",
                     anchor=f"{recv}.{field}", snip=self._snip(path, field))

    def _enum_owner(self, pm, name: str) -> str | None:
        for t, p in pm.items():
            if name in p.enums:
                return t
        return None

    # -- check 5: bitfield width vs static_assert ---------------------------
    def check_bitfields(self):
        structs: dict[str, tuple[Parsed, Path]] = {}
        for p in list(self.hidx._parsed.values()):
            for t in p.tags:
                structs.setdefault(t, (p, p.path))
        for path, p in self.tree.by_file.items():
            for t in p.tags:
                structs.setdefault(t, (p, path))
        for what, expected, path, line in self.m.bitfield_asserts:
            p, where = structs.get(what, (None, None))
            if p is None:
                self.stats["unknown-type"] += 1
                continue
            bf = p.bitfields.get(what)
            if not bf:
                self.stats["not-a-bitfield"] += 1
                continue
            base = SIZE_OF.get((bf["base"] or "").split("::")[-1], -1)
            if base <= 0:
                self.stats["unknown-type"] += 1
                continue
            cap = base * 8
            predicted = -(-bf["bits"] // cap) * base
            if predicted != expected:
                self.add("BITFIELD-SIZE", what, path, line,
                         f"{bf['count']} bitfields total {bf['bits']} bits over a "
                         f"{cap}-bit base -> sizeof == {predicted}, but the assert "
                         f"beside it says {expected}",
                         anchor=f"static_assert(sizeof({what})",
                         snip=snippet(self.m.file_text.get(path, ""), 0))
            elif bf["bits"] > cap:
                self.add("BITFIELD-SIZE", what, path, line,
                         f"{bf['bits']} bits declared over a {cap}-bit base type",
                         anchor=what, snip="")

    # -- check 6/7: constant tables -----------------------------------------
    def check_tables(self):
        enum_of: dict[str, tuple[str, int, int, str, int]] = {}
        for p in self.hidx._parsed.values():
            for ename, members in p.enums.items():
                for mname, (val, line) in members.items():
                    enum_of.setdefault(mname, (ename, val, line, str(p.path), line))
        for p in self.tree.by_file.values():
            for ename, members in p.enums.items():
                for mname, (val, line) in members.items():
                    enum_of.setdefault(mname, (ename, val, line, str(p.path), line))
        norm: dict[str, list[str]] = defaultdict(list)
        for mname in enum_of:
            norm[norm_name(mname)].append(mname)
        for name, value, head, path, line in self.m.tables:
            if not is_candidate(name) and not name.lower().startswith("k"):
                continue
            want = value.lower()
            got = int(want, 16) if want.startswith("0x") else int(want)
            target = match_enumerator(norm, norm_name(name))
            if not target:
                self.stats["table-unmatched"] += 1
                continue
            sdk_name = target
            sdk_enum, sdk_val, sdk_line, sdk_path, _l = enum_of[sdk_name]
            if sdk_val != got:
                self.add("CONST-TABLE-VALUE", name, path, line,
                         f"table says {want} but {sdk_name} ({sdk_enum}) is {sdk_val} "
                         f"[{rel(Path(sdk_path))}:{sdk_line}]",
                         anchor=name, snip=self._snip(path, name))
            legal = {info[1] for name2, info in enum_of.items() if info[0] == sdk_enum}
            if got not in legal:
                near = min(legal, key=lambda v: (bin(v ^ got).count("1"), v)) if legal else None
                self.add("CONST-TABLE-ILLEGAL", name, path, line,
                         f"{got:#x} is not a value any enumerator of {sdk_enum} has"
                         + (f"; nearest legal value is {near:#x}" if near is not None else ""),
                         anchor=name, snip=self._snip(path, name))
            else:
                self.stats["table-ok"] += 1

    # -- check 8: non-mutable mutex in a const reader -----------------------
    def check_mutex(self):
        for path, line, cls, field, fnline in self.m.mutex_cases:
            self.add("MUTEX-NOT-MUTABLE", f"{cls}::{field}", path, line,
                     f"`{field}` is a plain std::mutex locked from a const member "
                     f"function of {cls} (declared in the class body) -- it needs `mutable`",
                     anchor=field, snip=self._snip(path, field))

    def run(self):
        self.check_names()
        self.check_com_methods()
        self.check_members()
        self.check_enum_assign()
        self.check_bitfields()
        self.check_tables()
        self.check_mutex()
        self.findings.sort(key=lambda f: f.sort_key())
        return self.findings


def methods_of_any(pm: dict[str, Parsed], method: str, skip: str | None = None) -> set[str]:
    out = set()
    for t, p in pm.items():
        if t == skip:
            continue
        st = p.structs.get(t)
        if st and method in st["members"]:
            out.add(t)
        iface = p.ifaces.get(t)
        if iface and method in iface["methods"]:
            out.add(t)
    return out


def norm_name(name: str) -> str:
    n = name
    if n.startswith("k") and len(n) > 1 and n[1].isupper():
        n = n[1:]
    for p in ("D3D12_", "DXGI_", "D3D_", "D3D11_"):
        if n.startswith(p):
            n = n[len(p):]
            break
    return re.sub(r"[^a-z0-9]", "", n.lower())


def match_enumerator(norm: dict[str, list[str]], want: str) -> str | None:
    """`kD3D12FilterMinPointMagMipPoint` -> `D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT`.

    Exact normalized match first. Then a suffix match in either direction, since
    a project table drops the `TEXTURE_` half of
    `D3D12_TEXTURE_ADDRESS_MODE_WRAP` and keeps the rest. Ambiguity is refused
    rather than guessed: if more than one enumerator fits, the entry is reported
    as unmatched and counted, not checked."""
    exact = norm.get(want, [])
    if len(exact) == 1:
        return exact[0]
    if len(exact) > 1:
        return None
    cands = set()
    for key, names in norm.items():
        if len(key) < 5 or len(want) < 5:
            continue
        if key.endswith(want) or want.endswith(key):
            cands.update(names)
    if len(cands) == 1:
        return next(iter(cands))
    return None


# ------------------------------------------------------------------- driving

def discover_roots(extra: list[str] | None) -> list[tuple[str, Path]]:
    roots: list[tuple[str, Path]] = []
    seen: set[str] = set()

    def add(label: str, p: Path) -> None:
        key = os.path.normcase(str(p.resolve())) if p.exists() else os.path.normcase(str(p))
        if p.is_dir() and key not in seen:
            seen.add(key)
            roots.append((label, p))

    cc = REPO / "build" / "compile_commands.json"
    if cc.exists():
        try:
            entries = json.loads(cc.read_text(encoding="utf-8", errors="replace"))
        except Exception:
            entries = []
        for e in entries:
            cmd = e.get("command") or " ".join(e.get("arguments", []))
            for a in re.findall(r'(?:-I|/I|-imsvc)(?:"[^"]*"|[^\s"]+)', cmd):
                p = (a[len("-imsvc"):] if a.startswith("-imsvc") else a[2:]).strip('"')
                add("cc:" + Path(p).name, Path(p))
    else:
        kits = Path(r"C:\Program Files (x86)\Windows Kits\10\Include")
        if kits.is_dir():
            vers = sorted([d for d in kits.iterdir() if d.is_dir()], reverse=True)
            if vers:
                for sub in ("um", "shared", "ucrt", "winrt"):
                    add("sdk:" + sub, vers[0] / sub)
    for name in ("dxc/inc", "fmt", "spdlog/include", "SDL3/include", "toml++/include"):
        add("tp:" + name, REPO / "third_party" / name)
    for e in extra or []:
        add("cli:" + Path(e).name, Path(e))
    return roots


def gather_sources(paths: list[Path]) -> list[Path]:
    out = []
    for p in paths:
        if p.is_file():
            out.append(p)
        elif p.is_dir():
            out += [f for f in sorted(p.rglob("*"))
                    if f.is_file() and f.suffix.lower() in SRC_SUFFIXES]
    return out


def build(hidx: HeaderIndex, tree: Tree, model: SrcModel, srcs: list[Path],
          verbose: bool = False) -> Audit:
    include_map: dict[str, list[Path]] = defaultdict(list)
    for f in hidx.files:
        include_map[f.name.lower()].append(f)
    for p in srcs:
        include_map[p.name.lower()].append(p)
    roots_dirs = [r for _, r in hidx.roots]
    res = Resolver(hidx, tree, include_map, roots_dirs)
    return Audit(hidx, tree, res, model, verbose)


def run_audit(src_roots: list[Path], extra_roots: list[str] | None,
              cache: Path, verbose: bool = False):
    t0 = time.time()
    roots = discover_roots(extra_roots)
    if not roots:
        print("error: no include roots found (build/compile_commands.json missing "
              "and no Windows Kits); pass --root DIR", file=sys.stderr)
        sys.exit(3)
    hidx = HeaderIndex(roots, cache, verbose)
    srcs = gather_sources(src_roots)
    model = SrcModel()
    collect_src(srcs, model)
    t_collect = time.time() - t0

    # project-local declarations
    tree = Tree()
    for p in srcs:
        try:
            raw = p.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        tree.add(p, parse_file(p, strip_code(raw)))

    # which headers can each TU see? union, then one pass over that union.
    include_map: dict[str, list[Path]] = defaultdict(list)
    for f in hidx.files:
        include_map[f.name.lower()].append(f)
    for p in srcs:
        include_map[p.name.lower()].append(p)
    res = Resolver(hidx, tree, include_map, [r for _, r in roots])
    # IUnknown's method set is needed to answer "is this method on the interface?"
    # for every COM interface, so parse the headers that declare it up front. The
    # names are still read out of the file; only the FILE is named here.
    for base_hdr in ("unknwn.h", "combaseapi.h", "objbase.h", "capi.h"):
        for f in include_map.get(base_hdr, [])[:1]:
            hidx.parsed(f)
    scope: set[Path] = set()
    for tu in srcs:
        clo, _ = res.closure(tu)
        scope |= clo
    scope -= set(srcs)
    scope_list = sorted(scope)
    query = set(model.candidates)
    sig = hashlib.sha1("|".join(
        f"{p}:{p.stat().st_size}:{p.stat().st_mtime_ns}" for p in scope_list).encode()).hexdigest()[:12]
    hidx.name_index = hidx.build_name_index(query, scope_list, sig)
    t_index = time.time() - t0

    audit = build(hidx, tree, model, srcs, verbose)
    findings = audit.run()
    return audit, {"t_collect": t_collect, "t_index": t_index, "t_total": time.time() - t0,
                   "roots": roots, "srcs": srcs, "scope": scope_list, "sig": sig}


# ------------------------------------------------------------------- output

def report(audit: Audit, meta: dict, as_json: bool, strict: bool, tree_note: str) -> int:
    st = audit.stats
    if as_json:
        print(json.dumps({
            "roots": [{"label": l, "path": str(p)} for l, p in meta["roots"]],
            "files": len(meta["srcs"]),
            "header_files_searched": len(meta["scope"]),
            "candidates": len(audit.m.candidates),
            "checked": len(audit.m.candidates),
            "found": st.get("found", 0),
            "not_in_header": st.get("not-in-header", 0),
            "unresolved": st.get("unresolved", 0),
            "findings": [f.as_dict() for f in audit.findings],
            "unresolved_sites": [{"name": n, "file": rel(p), "line": l, "why": w}
                                 for n, p, l, w in audit.unresolved],
            "by_check": dict(st),
            "tree": tree_note,
        }, indent=2))
        rc = 1 if audit.findings else 0
        if strict and audit.unresolved:
            rc = 2
        return rc

    print("# api_audit -- platform names vs the headers actually on this machine")
    print(f"#   tree: {tree_note}")
    print(f"#   roots: {len(meta['roots'])} include dirs from build/compile_commands.json "
          f"+ third_party")
    for l, p in meta["roots"][:4]:
        print(f"#     {l:<28} {p}")
    if len(meta["roots"]) > 4:
        print(f"#     (+{len(meta['roots']) - 4} more)")
    print(f"#   searched {len(meta['scope'])} headers in the union of every TU's "
          f"#include closure")
    print(f"#   src files: {len(meta['srcs'])}   platform-shaped identifiers checked: "
          f"{len(audit.m.candidates)}")
    print(f"#   FOUND {st.get('found', 0)}   NOT-IN-HEADER {st.get('not-in-header', 0)}   "
          f"UNRESOLVED {st.get('unresolved', 0)}")
    print(f"#   member chains {st.get('member-found', 0)} resolved / "
          f"{st.get('unknown-type', 0)} sites UNKNOWN (no type inference)")
    print(f"#   const tables {st.get('table-ok', 0)} verified against the SDK, "
          f"{st.get('table-unmatched', 0)} unmatched")
    print(f"#   timing: collect {meta['t_collect']:.1f}s  index {meta['t_index']:.1f}s  "
          f"total {meta['t_total']:.1f}s\n")

    if audit.findings:
        cur = None
        for f in audit.findings:
            if f.check != cur:
                cur = f.check
                print(f"{f.check}")
            loc = f"{rel(f.path)}:{f.line}"
            print(f"  {loc:<52} {f.name}")
            print(f"      {f.detail}")
            if f.snippet:
                print(f"      | {f.snippet}")
            print(f"      anchor: {f.anchor or f.name}")
        print()
    else:
        print("no findings.\n")
    if audit.unresolved:
        print(f"UNRESOLVED -- {len(audit.unresolved)} sites could not be searched:")
        for n, p, l, why in audit.unresolved[:20]:
            print(f"  {rel(p)}:{l}  {n}   ({why})")
        if len(audit.unresolved) > 20:
            print(f"  (+{len(audit.unresolved) - 20} more)")
        print()
    rc = 1 if audit.findings else 0
    if strict and audit.unresolved:
        print("--strict: UNRESOLVED is a failure")
        rc = 2
    return rc


# ------------------------------------------------------------------ selftest

SELFTEST_BAD = r"""
// Each block reproduces one real failure from this project. Nothing here is a
// legal translation unit -- that is the point.
#include <d3d12.h>
#include <dxc/d3d12shader.h>
#include <mutex>
#include <vector>

struct LocalReg { int a; };

// (1) D3D12_RASTERIZER_DESC::DepthBiasEnable does not exist
void bad_depth_bias(D3D12_RASTERIZER_DESC& r) { r.DepthBiasEnable = TRUE; }
// (2) RenderTargetWriteMask lives on D3D12_RENDER_TARGET_BLEND_DESC, one level down
void bad_nesting(D3D12_BLEND_DESC& b) { b.RenderTargetWriteMask = 1; }
void bad_nesting2(D3D12_GRAPHICS_PIPELINE_STATE_DESC& p) { p.BlendState.RenderTargetWriteMask = 1; }
// (3) no D3D12_COLOR_ATTACHMENT_COUNT
void bad_macro(D3D12_GRAPHICS_PIPELINE_STATE_DESC& p) { (void)D3D12_COLOR_ATTACHMENT_COUNT; }
// (4) no D3D12_CULL_MODE_FRONT_BACK
void bad_cull(D3D12_RASTERIZER_DESC& r) { r.CullMode = D3D12_CULL_MODE_FRONT_BACK; }
// (5) no D3D12_FILL_MODE_UNSPECIFIED / D3D12_CULL_MODE_UNSPECIFIED
void bad_unspec(D3D12_RASTERIZER_DESC& r) { r.FillMode = D3D12_FILL_MODE_UNSPECIFIED; r.CullMode = D3D12_CULL_MODE_UNSPECIFIED; }
// (6) ConservativeRaster is an enum, not a BOOL
void bad_enum_assign(D3D12_RASTERIZER_DESC& r) { r.ConservativeRaster = FALSE; }
// (7) the vendored ID3D12ShaderReflection has neither method
void bad_reflect(ID3D12ShaderReflection* reflector) {
    D3D12_SHADER_VARIABLE_DESC vd = {};
    reflector->GetVariableDesc(0, &vd);
    reflector->GetVariableCount();
}
// (8) the vendored D3D12_SHADER_BUFFER_DESC has no VariableCount
void bad_bufferdesc() { D3D12_SHADER_BUFFER_DESC d = {}; d.VariableCount = 1; (void)d; }
// (9) STATUS_OBJECT_NAME_NOT_FOUND is not reachable from this TU
void bad_status() { volatile long s = STATUS_OBJECT_NAME_NOT_FOUND; (void)s; }
// (10) a std::mutex needs mutable to be locked from a const reader
struct Cache { std::mutex bad_;
               std::size_t Size() const { std::lock_guard<std::mutex> a(bad_); return 0; } };
// (11) SuScModeCntl was 33 bits wide behind a one-dword assert
struct SuScModeCntlBad {
    uint32_t cullFront : 1; uint32_t cullBack : 1; uint32_t face : 1;
    uint32_t polyMode : 2; uint32_t polyFrontType : 3; uint32_t polyBackType : 3;
    uint32_t polyOffFrontEn : 1; uint32_t polyOffBackEn : 1; uint32_t polyOffParaEn : 1;
    uint32_t _pad14 : 1; uint32_t msaaEnable : 1; uint32_t vtxWindowOffset : 1;
    uint32_t rest : 16;
};
static_assert(sizeof(SuScModeCntlBad) == sizeof(uint32_t), "one dword");
// (12) the invented sampler-filter table: 0x030 and 0x044 are not D3D12_FILTER values,
//      and 0x044 is 0x004 | 0x40 -- bit-identical to a legal, different filter.
enum : uint32_t {
    kD3D12FilterMinPointMagMipPoint = 0x030,
    kD3D12FilterMinMagMipLinear = 0x044,
};
"""

SELFTEST_GOOD = r"""
// The repaired forms of every one of the above must be clean.
#include <d3d12.h>
#include <dxc/d3d12shader.h>
#include <mutex>
struct GoodCache { mutable std::mutex good_; std::size_t Size() const { std::lock_guard<std::mutex> a(good_); return 0; } };
struct SuScModeCntlGood {
    uint32_t cullFront : 1; uint32_t cullBack : 1; uint32_t face : 1;
    uint32_t polyMode : 2; uint32_t polyFrontType : 3; uint32_t polyBackType : 3;
    uint32_t polyOffFrontEn : 1; uint32_t polyOffBackEn : 1; uint32_t polyOffParaEn : 1;
    uint32_t _pad14 : 1; uint32_t msaaEnable : 1; uint32_t vtxWindowOffset : 1;
    uint32_t rest : 15;
};
static_assert(sizeof(SuScModeCntlGood) == sizeof(uint32_t), "one dword");
enum : uint32_t {
    kD3D12FilterMinMagMipPoint = 0x000,
    kD3D12FilterMinPointMagMipPoint = 0x004,
    kD3D12FilterMinMagMipLinear = 0x015,
    kD3D12FilterAnisotropic = 0x055,
};
void good(D3D12_RASTERIZER_DESC& r, D3D12_BLEND_DESC& b,
          ID3D12ShaderReflection* reflector, D3D12_GRAPHICS_PIPELINE_STATE_DESC& p) {
    r.DepthBias = 1.0f; r.DepthBiasClamp = 0.0f; r.SlopeScaledDepthBias = 0.0f;
    r.DepthClipEnable = TRUE;
    r.CullMode = D3D12_CULL_MODE_BACK; r.FillMode = D3D12_FILL_MODE_SOLID;
    r.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    b.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    p.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    p.RTVFormats[0] = 1; (void)D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT;
    D3D12_SHADER_BUFFER_DESC cbDesc = {};
    (void)cbDesc.Size;
    ID3D12ShaderReflectionConstantBuffer* cbuf = reflector->GetConstantBufferByIndex(0);
    if (cbuf) { (void)cbuf->GetVariableByIndex(0); }
}
"""


def selftest(verbose: bool = False) -> int:
    tmp = CACHE / "selftest"
    bad_dir, good_dir = tmp / "bad", tmp / "good"
    bad_dir.mkdir(parents=True, exist_ok=True)
    good_dir.mkdir(parents=True, exist_ok=True)
    (bad_dir / "known12.cpp").write_text(SELFTEST_BAD, encoding="utf-8")
    (good_dir / "known12_fixed.cpp").write_text(SELFTEST_GOOD, encoding="utf-8")

    expected = [
        ("PLATFORM-NAME", "D3D12_COLOR_ATTACHMENT_COUNT"),
        ("PLATFORM-NAME", "D3D12_CULL_MODE_FRONT_BACK"),
        ("PLATFORM-NAME", "D3D12_FILL_MODE_UNSPECIFIED"),
        ("PLATFORM-NAME", "D3D12_CULL_MODE_UNSPECIFIED"),
        ("PLATFORM-NAME", "STATUS_OBJECT_NAME_NOT_FOUND"),
        ("COM-METHOD", "GetVariableDesc"),
        ("COM-METHOD", "GetVariableCount"),
        ("STRUCT-MEMBER", "DepthBiasEnable"),
        ("STRUCT-MEMBER", "RenderTargetWriteMask"),
        ("STRUCT-MEMBER", "VariableCount"),
        ("ENUM-BOOL-ASSIGN", "r.ConservativeRaster"),
        ("BITFIELD-SIZE", "SuScModeCntlBad"),
        ("CONST-TABLE-VALUE", "kD3D12FilterMinPointMagMipPoint"),
        ("CONST-TABLE-ILLEGAL", "kD3D12FilterMinPointMagMipPoint"),
        ("CONST-TABLE-ILLEGAL", "kD3D12FilterMinMagMipLinear"),
        ("MUTEX-NOT-MUTABLE", "Cache::bad_"),
    ]
    results = []
    for label, srcs in (("bad", [bad_dir]), ("good", [good_dir])):
        audit, meta = run_audit(srcs, None, CACHE, verbose)
        results.append((label, audit, meta))

    bad_audit = results[0][1]
    good_audit = results[1][1]
    pairs = [(f.check, f.name) for f in bad_audit.findings]
    ok = True
    print("# api_audit --selftest\n")
    for check, name in expected:
        hit = any(c == check and n == name for c, n in pairs)
        print(f"  {'PASS' if hit else 'FAIL'}  {check:<20} {name}")
        ok &= hit
    leaks = [(f.check, f.name) for f in good_audit.findings]
    print(f"  {'PASS' if not leaks else 'FAIL'}  negative control: repaired forms are clean"
          + ("" if not leaks else f" -> {leaks}"))
    ok &= not leaks
    # the 12-name acceptance test
    twelve = ["DepthBiasEnable", "RenderTargetWriteMask", "D3D12_COLOR_ATTACHMENT_COUNT",
              "D3D12_CULL_MODE_FRONT_BACK", "D3D12_FILL_MODE_UNSPECIFIED",
              "D3D12_CULL_MODE_UNSPECIFIED", "GetVariableDesc", "GetVariableCount",
              "VariableCount", "STATUS_OBJECT_NAME_NOT_FOUND", "bad_", "SuScModeCntlBad"]
    found_names = " ".join(f"{c}:{n}" for c, n in pairs)
    print("\n  acceptance: the 12 known invented names")
    for t in twelve:
        hit = t in found_names
        print(f"    {'caught  ' if hit else 'MISSED  '} {t}")
        ok &= hit
    print(f"\n  {'SELFTEST PASS' if ok else 'SELFTEST FAIL'}")
    return 0 if ok else 4


# ---------------------------------------------------------------------- main

def tree_note() -> str:
    try:
        head = os.popen('git -C "%s" rev-parse --short HEAD' % REPO).read().strip()
    except Exception:
        head = "?"
    n = len(gather_sources([REPO / "src", REPO / "tools" / "validators"]))
    return f"{n} C/C++ files, git {head}"


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--src", action="append", default=None,
                    help="source root or file (default: src/ and tools/validators/)")
    ap.add_argument("--root", action="append", default=[],
                    help="extra include root to search")
    ap.add_argument("--cache", default=str(CACHE), help="parsed-header cache dir")
    ap.add_argument("--strict", action="store_true",
                    help="UNRESOLVED sites are a failure (exit 2)")
    ap.add_argument("--json", action="store_true", help="machine-readable output")
    ap.add_argument("--selftest", action="store_true",
                    help="run the per-check cases against synthetic sources")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    if args.selftest:
        return selftest(args.verbose)

    src_roots = [Path(s) for s in args.src] if args.src else [
        REPO / "src", REPO / "tools" / "validators"]
    src_roots = [p for p in src_roots if p.exists()]
    if not src_roots:
        print("error: no --src path exists", file=sys.stderr)
        return 3
    audit, meta = run_audit(src_roots, args.root, Path(args.cache), args.verbose)
    return report(audit, meta, args.json, args.strict, tree_note())


if __name__ == "__main__":
    sys.exit(main())
