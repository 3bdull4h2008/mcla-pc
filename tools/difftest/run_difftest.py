#!/usr/bin/env python3
"""Differential test: recompiled PowerPC vs. a third-party reference corpus.

Subject
    The real translator -- the prebuilt
    .research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe driven through
    its own TestRecompiler path (test_recompiler.cpp:35), i.e. the same
    recompiler.cpp the 176 generated/ppc_xenon translation units came from.

Reference
    Xenia's own PowerPC codegen corpus, .research/xenia/src/xenia/cpu/ppc/testing.
    It carries the raw machine words (`.long 0x...`) next to the expected
    architectural register state (`#_ REGISTER_OUT`).  For the VMX128 opcodes
    those words are hand-coded *because no assembler could encode them* (see
    the header of instr_vupkd3d128.s), which makes this the strongest reference
    reachable offline: a third party's encoding, not our re-derivation.

    It is a CORPUS, not an interpreter.  There is no permissively-licensed
    PowerPC interpreter anywhere in this tree (.research/ has XenonRecomp,
    Xenia, XenosRecomp, UnleashedRecomp, 360tools -- none is an interpreter),
    and this box has no working web search (verified) and no PowerPC backend in
    clang (verified), so nothing could be fetched or assembled.  Coverage is
    therefore bounded by how much of the corpus is machine-word-decodable
    without an assembler; corpus.py reports exactly how much that is.

Pipeline per suite
    1. corpus.py      parse the .s -> (words, REGISTER_IN, REGISTER_OUT)
    2. elfgen.py      words -> big-endian ELF32 PPC .o  (+ .dis label map)
    3. XenonRecomp    .o  -> <stem>.cpp (translated) + main.cpp (driver)
    4. clang-cl       compile both, link, run        (flags harvested from
                      build/compile_commands.json -- no CMake needed)
    5. parse          `... EXPECTED 0x.. ACTUAL 0x..` lines -> pass/fail

Nothing outside tools/difftest/ is written.  Nothing in src/, generated/,
build/ or .research/ is modified.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)

import corpus  # noqa: E402
import elfgen  # noqa: E402

RECOMPILER = os.path.join(ROOT, ".research", "XenonRecomp", "build-clang",
                          "XenonRecomp", "XenonRecomp.exe")
COMPILE_COMMANDS = os.path.join(ROOT, "build", "compile_commands.json")
CORPUS_DIR = os.path.join(ROOT, ".research", "xenia", "src", "xenia", "cpu",
                          "ppc", "ppc", "testing")
CORPUS_DIR = os.path.join(ROOT, ".research", "xenia", "src", "xenia", "cpu",
                          "ppc", "testing")

# our driver reports a mismatch as
#   CASE <case> <expr> EXPECTED 0x.. ACTUAL 0x..
RESULT_RE = re.compile(r"^\s*CASE\s+(\S+)\s+(\S+)\s+EXPECTED\s+(\S+)\s+ACTUAL\s+(\S+)\s*$")
# The recompiler reports a guest opcode it could not translate at all.
UNIMPL_RE = re.compile(r"^Function ([0-9A-F]+) in (\S+) has unimplemented instructions")
# ... and a corpus label whose function it never emitted.
NOSYM_RE = re.compile(r"^Found no symbol for (\S+)")


def split_cmd(cmd: str):
    """Split a recorded MSVC-style command line, keeping backslashes intact.

    shlex.split() is wrong here: it eats '\\' as an escape, which silently
    turns /FoCMakeFiles\\mcla.dir\\... into /FoCMakeFilesmcla.dir... and then
    leaks a real build object into the link.
    """
    out, cur, inq = [], "", False
    for ch in cmd:
        if ch == '"':
            inq = not inq
        elif ch.isspace() and not inq:
            if cur:
                out.append(cur)
                cur = ""
        else:
            cur += ch
    if cur:
        out.append(cur)
    return out


def harvest_flags():
    """Pull a real clang-cl command line out of build/compile_commands.json.

    Using the project's own recorded command is what keeps this honest: the
    headers under -imsvc (MSVC STL, fmt) are the exact ones the 176 real
    translation units compiled against.
    """
    with open(COMPILE_COMMANDS, "r", encoding="utf-8") as fh:
        entries = json.load(fh)
    for e in entries:
        if e["file"].endswith("ppc_recomp.79.cpp"):
            argv = split_cmd(e["command"])
            out = []
            for a in argv:                         # argv[0] is clang-cl itself
                low = a.lower()
                # Any /Fo /Fd /Fe /Fm /Fp (either spelling) points the compiler
                # at a real build artifact.  Leaving the project's own through
                # would make the linker pull build/CMakeFiles\...\
                # ppc_recomp.79.obj -- and with it the whole guest runtime --
                # into the test binary.
                if low[:3] in ("/fo", "-fo", "/fd", "-fd", "/fe", "-fe",
                               "/fm", "-fm", "/fp", "-fp"):
                    continue
                # compile-only and pdb/debug + MT noise are irrelevant here.
                # `--` MUST go: it ends option parsing, so every flag we add
                # afterwards (including -c) is then read as an input filename.
                if a in ("--",) or a[1:].lower() in ("c", "zi", "z7", "mt", "clang:"):
                    continue
                # the recorded command's own source file: we supply our own
                if low.endswith((".cpp", ".c", ".cc")):
                    continue
                out.append(a)
            if not out:
                raise SystemExit("difftest: could not parse compile_commands entry")
            # The recorded command has -I<src> ahead of the XenonRecomp dirs, so
            # the emitted `#include <ppc_context.h>` would pick up MCLA's
            # src/ppc_context.h -- a different header, with different macros,
            # from the one recompiler.cpp was written against.  Put the
            # upstream XenonUtils include first so the test builds the same
            # context the translator emits for.
            upstream = os.path.join(ROOT, ".research", "XenonRecomp", "XenonUtils")
            simde = os.path.join(ROOT, ".research", "XenonRecomp", "thirdparty", "simde")
            out.insert(1, "-I" + upstream)
            out.insert(2, "-I" + simde)
            return out, e["directory"]
    raise SystemExit("difftest: no ppc_recomp entry in compile_commands.json")


def prepare(work, suite, cases):
    """Write <work>/<stem>.s, <work>/obj/<stem>.o, <work>/obj/<stem>.dis.

    Returns (stem, byte-offsets).  The offset of each case is the ELF symbol
    the translator will emit: TestRecompiler::Analyse names every function
    "{stem}_{base:X}" (test_recompiler.cpp:25) and Recompile names the C++
    symbol from the matching image symbol (recompiler.cpp:2526-2534), so the
    base -- which is the byte offset into .text, because we set the single
    PT_LOAD p_vaddr and the .text sh_addr both to 0 -- is the handle the driver
    needs.
    """
    stem = suite
    os.makedirs(os.path.join(work, "obj"), exist_ok=True)
    os.makedirs(os.path.join(work, "out"), exist_ok=True)

    # The .s is copied VERBATIM -- it is the reference, and we must not be the
    # ones reformatting it.
    shutil.copyfile(os.path.join(CORPUS_DIR, stem + ".s"),
                    os.path.join(work, stem + ".s"))

    words, entries, offsets = [], [], []
    for c in cases:
        entries.append((4 * len(words), c.name))
        offsets.append(4 * len(words))
        words.extend(c.words)

    with open(os.path.join(work, "obj", stem + ".o"), "wb") as fh:
        fh.write(elfgen.build_elf(words))
    with open(os.path.join(work, "obj", stem + ".dis"), "w", encoding="ascii",
              newline="\n") as fh:
        fh.write(elfgen.build_dis(entries))
    return stem, offsets


def translate(stem, work):
    """Run the real recompiler in test mode. Returns (rc, stdout, stderr)."""
    p = subprocess.run([RECOMPILER, os.path.join(work, "obj"),
                        os.path.join(work, "out")],
                       capture_output=True, text=True, errors="replace")
    return p.returncode, (p.stdout or "") + (p.stderr or "")


def gen_driver(stem, cases, offsets):
    """Emit our own test driver from the corpus annotations.

    Upstream ships one of these (test_recompiler.cpp:100-290) but wires it up
    through a `.dis` label->symbol sidecar whose line format is not documented
    and which did not resolve against the ELF we emit, so we generate the same
    scaffolding ourselves.  Nothing semantic changes: every REGISTER_IN /
    REGISTER_OUT value below is lifted verbatim out of Xenia's .s file, and the
    instruction words are whatever the translator emitted.  We are building a
    test rig, not deciding what the right answer is.

    The one thing worth being explicit about: the recompiler's test mode emits
    `#define __builtin_debugtrap()` with an empty body, so a guest opcode the
    translator has no case for becomes a silent no-op instead of a host int3.
    That is precisely what makes the VMX128 cases below a real differential
    signal rather than a crash.
    """
    L = []
    w = L.append
    w("#define PPC_CONFIG_H_INCLUDED")
    w('#include <ppc_context.h>')
    w('#ifdef _WIN32')
    w("#include <Windows.h>")
    w("#else")
    w("#include <sys/mman.h>")
    w("#endif")
    w("")
    # PPC_EXTERN_FUNC / PPC_FUNC come from the header we just included, so the
    # declarations match the definitions the translator emitted.
    for (c, off) in zip(cases, offsets):
        w("PPC_EXTERN_FUNC(%s_%X);" % (stem, off))
    w("")
    w('#include <cstdio>')
    w('#include <cstdint>')
    w('#include <cstdlib>')
    w('#include <cstring>')
    w("")
    w("static int g_fail = 0;")
    w("static int g_checks = 0;")
    w("")
    w("static void chk_u(const char* cs, const char* name, const char* expr,")
    w("                uint64_t got, uint64_t want) {")
    w("    ++g_checks;")
    w("    if (got != want) {")
    w('        printf("CASE %s %s EXPECTED 0x%llX ACTUAL 0x%llX\\n", cs, expr,')
    w("               (unsigned long long)want, (unsigned long long)got);")
    w("        ++g_fail;")
    w("    }")
    w("}")
    w("")

    for (c, off) in zip(cases, offsets):
        w("static void run_%s_%X(uint8_t* base) {" % (c.name, off))
        w("    PPCContext ctx{};")
        w("    ctx.fpscr.loadFromHost();")
        for reg, v in c.mem_in.items():
            base_vaddr = int(reg, 16)
            for i, byte in enumerate(v):
                w("    base[0x%X + 0x%X] = 0x%02X;" % (base_vaddr, i, byte))
        for reg, v in c.reg_in.items():
            if reg.startswith("v"):
                # Xenia writes vectors as [w3, w2, w1, w0] -- most significant
                # word first.  Its own generator maps element 0 -> u32[3]
                # (test_recompiler.cpp:165-168); match that or every vector case
                # comes out byte-reversed and every diff is our bug, not the
                # translator's.
                for i, w32 in enumerate(v):
                    w("    ctx.%s.u32[%d] = 0x%08X;" % (reg, 3 - i, w32))
            else:
                w("    ctx.%s.u64 = %d;" % (reg, v & 0xFFFFFFFFFFFFFFFF))
        w("    %s_%X(ctx, base);" % (stem, off))
        for reg, v in c.reg_out.items():
            if reg.startswith("v"):
                for i, w32 in enumerate(v):
                    w("    chk_u(\"%s\", \"vec\", \"ctx.%s.u32[%d]\","
                      " ctx.%s.u32[%d], 0x%08XULL);" % (c.name, reg, 3 - i, reg, 3 - i, w32))
            else:
                w("    chk_u(\"%s\", \"%s\", \"ctx.%s.u64\", ctx.%s.u64, %dULL);"
                  % (c.name, reg, reg, reg, v & 0xFFFFFFFFFFFFFFFF))
        for reg, v in c.mem_out.items():
            base_vaddr = int(reg, 16)
            for i, byte in enumerate(v):
                w("    chk_u(\"%s\", \"mem\", \"base[0x%X+0x%X]\","
                  " base[0x%X + 0x%X], 0x%02XULL);"
                  % (c.name, base_vaddr, i, base_vaddr, i, byte))
        w("}")
        w("")

    w("int main() {")
    w("#ifdef _WIN32")
    w("    uint8_t* base = (uint8_t*)VirtualAlloc(nullptr, 0x100000000ull,")
    w("                                            MEM_RESERVE | MEM_COMMIT,")
    w("                                            PAGE_READWRITE);")
    w("#else")
    w("    uint8_t* base = (uint8_t*)mmap(nullptr, 0x100000000ull,")
    w("                                    PROT_READ | PROT_WRITE,")
    w("                                    MAP_ANON | MAP_PRIVATE, -1, 0);")
    w("#endif")
    w("    if (!base) { printf(\"HARNESS alloc failed\\n\"); return 2; }")
    for (c, off) in zip(cases, offsets):
        w("    run_%s_%X(base);" % (c.name, off))
    w('    printf("SUMMARY cases=%%d checks=%%d failed=%%d\\n", %d, g_checks, g_fail);'
      % len(cases))
    w("    return g_fail ? 1 : 0;")
    w("}")
    return "\n".join(L) + "\n"


TRAP_SITE_RE = re.compile(r"^\s*__builtin_debugtrap\(\)\s*;\s*$")
FUNC_DEF_RE = re.compile(r"PPC_WEAK_FUNC\((\w+)\)")


def trapping_functions(cpp_path):
    """Map emitted function name -> True if its body traps.

    A trap is a host `int3` with no handler, so a guest function that contains
    one will kill the process the moment the game reaches it.  In the
    recompiler's *test* mode the trap is #defined away to nothing
    (test_recompiler.cpp:54), which is what lets us observe the consequence --
    a silently wrong result -- instead of a crash.  Note the emitted file
    contains the line `#define __builtin_debugtrap()`; matching that would
    inflate every count by one, hence the anchored pattern.
    """
    out = {}
    cur = None
    try:
        with open(cpp_path, "r", encoding="utf-8", errors="replace") as fh:
            for line in fh:
                m = FUNC_DEF_RE.search(line)
                if m:
                    cur = m.group(1)
                    out.setdefault(cur, False)
                elif cur and TRAP_SITE_RE.match(line):
                    out[cur] = True
    except OSError:
        pass
    return out


def build_and_run(stem, work, flags, cwd, timeout_s=600):
    """Compile the emitted <stem>.cpp + our driver, link, execute.

    Deliberately two-stage (compile each source, then link the objects) so no
    /Fo ever appears on the link line.  Feeding sources straight to clang-cl
    with a fused /Fo either errors out ("cannot specify /Fo when compiling
    multiple source files") or drags build/'s own .obj into the link.
    """
    outdir = os.path.join(work, "out")
    srcs = [os.path.join(outdir, stem + ".cpp"), os.path.join(work, stem + "_driver.cpp")]
    for s in srcs:
        if not os.path.exists(s):
            return None, f"recompiler did not emit {os.path.basename(s)}", []

    objdir = os.path.join(work, "cc")
    os.makedirs(objdir, exist_ok=True)
    objs = []
    for s in srcs:
        obj = os.path.join(objdir, os.path.basename(s) + ".obj")
        cp = subprocess.run(list(flags) + ["-c", s, "-Fo" + obj],
                            capture_output=True, text=True,
                            errors="replace", cwd=cwd, timeout=timeout_s)
        if cp.returncode != 0 or not os.path.exists(obj):
            return None, ("COMPILE FAILED: " + os.path.basename(s) + "\n"
                          + (cp.stdout or "")[-3000:] + (cp.stderr or "")[-3000:]), []
        objs.append(obj)

    exe = os.path.join(work, stem + ".exe")
    cp = subprocess.run(list(flags) + objs + ["-Fe" + exe],
                        capture_output=True, text=True,
                        errors="replace", cwd=cwd, timeout=timeout_s)
    if cp.returncode != 0 or not os.path.exists(exe):
        return None, ("LINK FAILED\n" + (cp.stdout or "")[-3000:]
                      + (cp.stderr or "")[-3000:]), []

    try:
        rp = subprocess.run([exe], capture_output=True, text=True,
                            errors="replace", timeout=180)
        return rp.returncode, "", (rp.stdout or "").splitlines()
    except subprocess.TimeoutExpired:
        return -1, "TIMEOUT: the recompiled function did not terminate", []


def run_suite(suite, flags, cwd, keep, verbose):
    cases = [c for c in corpus.parse_suite(os.path.join(CORPUS_DIR, suite + ".s"))
             if c.usable]
    if not cases:
        return None

    work = keep or tempfile.mkdtemp(prefix="difftest_" + suite + "_")
    try:
        stem, offsets = prepare(work, suite, cases)
        with open(os.path.join(work, stem + "_driver.cpp"), "w",
                  encoding="utf-8", newline="\n") as fh:
            fh.write(gen_driver(stem, cases, offsets))
        rc, log = translate(stem, work)

        unimplemented = {}
        for line in log.splitlines():
            m = UNIMPL_RE.match(line.strip())
            if m:
                unimplemented.setdefault(m.group(2), set()).add(m.group(1))
        nosym = [m.group(1) for m in
                 (NOSYM_RE.match(l.strip()) for l in log.splitlines()) if m]

        run_rc, err, lines = build_and_run(stem, work, flags, cwd)
        if run_rc is None:
            return {"suite": suite, "status": "HARNESS_ERROR", "cases": len(cases),
                    "passed": 0, "failed": 0, "error": err,
                    "unimplemented": {k: sorted(v) for k, v in unimplemented.items()},
                    "no_symbol": nosym}

        by_case = {}
        ran = set()
        for ln in lines:
            m = RESULT_RE.match(ln)
            if not m:
                continue
            case, expr, exp, act = m.groups()
            by_case.setdefault(case, []).append(
                {"check": expr, "expected": exp, "actual": act})

        # A case is "ran" if it was invoked at all: count the SUMMARY line's
        # case total so a case that legitimately has no REGISTER_OUT check is
        # not silently reported as a failure.
        summary = next((l for l in lines if l.startswith("SUMMARY")), "")
        m = re.search(r"cases=(\d+)\s+checks=(\d+)\s+failed=(\d+)", summary)
        if m:
            ran_count, checks, failed_checks = (int(m.group(1)), int(m.group(2)),
                                                int(m.group(3)))
        else:
            ran_count, checks, failed_checks = 0, 0, 0

        passed = failed = 0
        failures = []
        trapmap = trapping_functions(os.path.join(work, "out", stem + ".cpp"))
        n_trap_sites = sum(1 for v in trapmap.values() if v)
        for c, off in zip(cases, offsets):
            fn = "%s_%X" % (stem, off)
            traps = bool(trapmap.get(fn))
            mism = by_case.get(c.name, [])
            if mism:
                failed += 1
                failures.append({"case": c.name, "guest_fn": fn, "traps": traps,
                                 "words": ["0x%08X" % w for w in c.words],
                                 "mismatches": mism})
            else:
                passed += 1
        for case, mism in by_case.items():
            if all(c.name != case for c in cases):
                failures.append({"case": case, "guest_fn": "?", "traps": None,
                                 "words": [], "mismatches": mism})

        by_trap = sum(1 for f in failures if f.get("traps"))
        beyond = len(failures) - by_trap

        return {"suite": suite, "status": "ran", "cases": len(cases),
                "checks": checks, "ran": ran_count,
                "emitted_functions": len(trapmap),
                "emitted_trap_sites": n_trap_sites,
                "failures_from_traps": by_trap,
                "failures_beyond_traps": beyond,
                "passed": passed, "failed": failed, "failures": failures,
                "unimplemented": {k: sorted(v) for k, v in unimplemented.items()},
                "no_symbol": nosym, "recompiler_log": log if verbose else None}
    finally:
        if not keep:
            shutil.rmtree(work, ignore_errors=True)


def sharp_edges(results, suites_run):
    """Name the four sharp edges the audit flagged, and say which are covered.

    Printed every run so a later session can see the holes without reading the
    source.  "GAP" lines are not excuses -- each carries the mechanical reason,
    which is the thing to go and fix.
    """
    by_suite = {r["suite"]: r for r in results if r.get("status") == "ran"}
    vmx = [s for s in ("instr_vupkd3d128", "instr_vpkd3d128", "instr_vpermwi128")
           if s in by_suite]
    vmx_fail = sum(by_suite[s]["failed"] for s in vmx)
    vmx_cases = sum(by_suite[s]["cases"] for s in vmx)
    print("SHARP-EDGE COVERAGE")
    print("-" * 78)
    if vmx:
        print(f"  [COVERED] VMX128 trap-site class  -- {vmx_cases} cases across"
              f" {len(vmx)} suite(s), {vmx_fail} failing")
        for s in vmx:
            r = by_suite[s]
            print(f"              {s}: {r['emitted_trap_sites']} trapping"
                  f" function(s), {r['failed']} failing"
                  f" ({r['failures_beyond_traps']} beyond the trap)")
    else:
        print("  [GAP] VMX128 trap-site class -- no VMX128 suite decodable")
    print("  [GAP] reservation / ABA (lwarx+stwcx.) -- no corpus case exists and")
    print("         no reference is available offline; needs either a corpus case")
    print("         or a PPC assembler.  See tools/difftest/README.md.")
    print("  [GAP] jump-table dispatch -- the only corpus case")
    print("         (.research/xenia/.../seq_jumptable_constants.s) is written with")
    print("         local labels and `.long .case_N` relocations, so it needs an")
    print("         assembler; 1 of 1481 corpus cases is even assemblable here.")
    print("  [GAP] non-local (callee-saved) register carriage -- STRUCTURALLY")
    print("         untestable on this path: XenonRecomp's test mode")
    print("         (test_recompiler.cpp:45-50) leaves RecompilerConfig default,")
    print("         so savegprlr_14_address etc. are 0, no __savegprlr_14 is")
    print("         emitted, and PPC_FUNC_PROLOGUE() degrades to an alignment")
    print("         __builtin_assume.  Exercising it needs the TOML path over the")
    print("         real .xex, i.e. the guest executor, not this harness.")
    print()


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--suite", action="append",
                    help="corpus suite to run (repeatable); default = every "
                         "suite that is fully machine-word-decodable")
    ap.add_argument("--json", help="write the full result set here")
    ap.add_argument("--keep", action="store_true",
                    help="keep the scratch workdir (for debugging)")
    ap.add_argument("--workdir", help="use this directory as the scratch workdir")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)

    if not os.path.exists(RECOMPILER):
        print(f"difftest: recompiler not found: {RECOMPILER}", file=sys.stderr)
        return 2

    suites, allcases = corpus.load_corpus(CORPUS_DIR)
    if args.suite:
        want = args.suite
    else:
        want = sorted(s for s, cs in suites.items()
                      if cs and all(c.usable for c in cs))

    usable = [c for c in allcases if c.usable]
    print("DIFFERENTIAL HARNESS -- recompiled PowerPC vs. Xenia codegen corpus")
    print("=" * 78)
    print(f"reference        : {CORPUS_DIR}")
    print(f"                   (a GOLDEN CORPUS, not an interpreter -- see header)")
    print(f"subject          : {RECOMPILER}")
    print(f"corpus suites    : {len(suites)}   cases: {len(allcases)}")
    print(f"decodable cases  : {len(usable)}  ({100.0 * len(usable) / max(1, len(allcases)):.1f}% of the corpus)")
    print(f"suites runnable  : {len(want)} -> {', '.join(want)}")
    print()

    flags, cwd = harvest_flags()
    results = []
    for s in want:
        r = run_suite(s, flags, cwd, args.workdir or (args.keep or None), args.verbose)
        if r is None:
            continue
        results.append(r)
        if r["status"] != "ran":
            print(f"[{s}] HARNESS ERROR ({r['cases']} cases): {r['error'][:800]}")
            continue
        print(f"[{s}] {r['cases']} cases  ran={r.get('ran')}  checks={r.get('checks')}"
              f"  passed={r['passed']}  failed={r['failed']}")
        print(f"    emitted {r.get('emitted_functions')} guest function(s),"
              f" {r.get('emitted_trap_sites')} containing a __builtin_debugtrap")
        print(f"    failures attributable to those traps : {r.get('failures_from_traps')}")
        print(f"    failures BEYOND the traps (semantic) : {r.get('failures_beyond_traps')}")
        if r["unimplemented"]:
            for k, v in r["unimplemented"].items():
                print(f"    recompiler: {len(v)} function(s) with unimplemented "
                      f"instructions, e.g. {v[:4]}")
        for f in r["failures"][:12]:
            tag = "TRAP" if f.get("traps") else "SEMANTIC"
            print(f"    FAIL[{tag}] {f['case']}  guest_fn={f['guest_fn']}"
                  f"  words={' '.join(f['words'])}")
            for mm in f["mismatches"][:6]:
                print(f"         {mm['check']}: expected {mm['expected']}  got {mm['actual']}")
        if len(r["failures"]) > 12:
            print(f"    ... {len(r['failures']) - 12} more failing cases (see --json)")
        print()

    tot_c = sum(r.get("cases", 0) for r in results)
    tot_p = sum(r.get("passed", 0) for r in results)
    tot_f = sum(r.get("failed", 0) for r in results)
    tot_t = sum(r.get("emitted_trap_sites", 0) for r in results)
    tot_ft = sum(r.get("failures_from_traps", 0) for r in results)
    tot_fb = sum(r.get("failures_beyond_traps", 0) for r in results)
    print("-" * 78)
    print(f"TOTAL differential cases: {tot_c}   passed: {tot_p}   failed: {tot_f}")
    print(f"  of the failures: {tot_ft} trace to a __builtin_debugtrap in the emitted"
          f" C++ ({tot_t} trapping functions), {tot_fb} are semantic and survive"
          " removing the trap")
    print()
    sharp_edges(results, want)

    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump({"reference_kind": "golden-corpus",
                       "reference_path": CORPUS_DIR,
                       "corpus_cases_total": len(allcases),
                       "corpus_cases_decodable": len(usable),
                       "suites": results,
                       "totals": {"cases": tot_c, "passed": tot_p, "failed": tot_f}},
                      fh, indent=1)
        print(f"results written: {args.json}")
    return 0 if tot_f == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
