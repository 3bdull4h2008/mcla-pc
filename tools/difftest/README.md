# tools/difftest — differential test for the PowerPC → C++ recompiler

**Status: exists, runs, and finds real divergences.** Read the numbers at the
bottom before trusting it.

## What the gap was

`generated/ppc_xenon/` is ~176 translation units of translated C++ that
nothing ever executes in a test. The only checks on the generator were a
byte-reproducibility comparison against `config/mcla_xenonrecomp_baseline.toml`
and a stub census. `.research/XenonRecomp/XenonTests/` contains a
`.gitignore` and a `CMakeLists.txt` and no tests. A wrong translation was
found days later as a mysterious crash or a hang.

## What this is

| file | role |
|---|---|
| `corpus.py` | parses Xenia's PowerPC codegen corpus (`.research/xenia/src/xenia/cpu/ppc/testing/*.s`) into `(machine words, REGISTER_IN, REGISTER_OUT)` triples |
| `elfgen.py` | writes those words into a big-endian ELF32 PowerPC object, plus the `.dis` label sidecar |
| `run_difftest.py` | drives the **real, prebuilt** `XenonRecomp.exe` in its own test mode, compiles the C++ it emits, runs it, and diffs |

## The reference side is a CORPUS, not an interpreter

Stated plainly because it bounds everything below.

* There is **no permissively-licensed PowerPC interpreter in this tree.**
  `.research/` holds XenonRecomp, Xenia, XenosRecomp, UnleashedRecomp and
  360tools; none is an interpreter (Xenia's `xenia-cpu` is an HLE/JIT, and
  its prebuilt `xenia-cpu-ppc-tests.exe` needs a `bin/` of `.map`+`.bin`
  artifacts produced by a custom binutils build that is not present).
* **Web search does not work on this box** (verified: `websearch` returns
  "No search results found"), so nothing could be fetched.
* The vendored compiler **has no PowerPC backend** (verified:
  `clang --target=powerpc-unknown-linux-gnu` → `unknown target triple`), so
  the corpus cannot be assembled here either. There is no `llvm-mc`.

So the reference is Xenia's own hand-written codegen suite: raw machine words
(`.long 0x...`) sitting next to the expected architectural register state. For
the VMX128 opcodes those words are hand-coded *because binutils could not
assemble them at all* — see the header of `instr_vupkd3d128.s`. It is a third
party (BSD-2), it is not ours, and we did not re-derive it.

The consequence is stated in every run: only cases whose every machine word
appears literally in the corpus can be lifted, and `corpus.py` prints how many
that is. **1 of 1481 corpus cases (0.07%) is assemblable-free; 45 (3.0%) are
fully decodable.** Everything else is reported as skipped, never guessed at.

## How the subject is executed

`XenonRecomp.exe <dir>` falls into `TestRecompiler::RecompileTests`
(`.research/XenonRecomp/XenonRecomp/test_recompiler.cpp:35`) when the argument
is a directory rather than a TOML. It parses our ELF, finds function starts,
runs **the same `recompiler.cpp` that produced the 176 TUs**, and emits C++.

Compiler flags are harvested from `build/compile_commands.json` rather than
invented, so the test builds against the same MSVC STL and fmt as the real
translation units. **No CMake target is required**; the driver invokes
`clang-cl` directly.

Two deliberate deviations from upstream's driver:

* We generate our own `main` (upstream's `.dis` label->symbol format is
  undocumented and did not resolve against our ELF).
* We compile each source and link the objects, two-stage, so no `/Fo` ever
  reaches the link line.

The single most important property: upstream's test mode emits
`#define __builtin_debugtrap()` with an **empty body**
(`test_recompiler.cpp:54`). A guest opcode the translator has no case for
therefore becomes a silent no-op rather than a host `int3`, so we observe the
*consequence* — a wrong register value we can attribute — instead of a crash.

## Failure attribution

Each failing case is tagged `TRAP` (its emitted function contains
`__builtin_debugtrap()`) or `SEMANTIC` (it does not). That split is the
point: the trap census (`tools/trap_census.py`) only sees traps, and a `SEMANTIC`
failure is a mistranslation the census can never find.

## Sharp edges

`run_difftest.py` prints a coverage block every run. Summary:

* **VMX128 trap-site class — COVERED.** 43 cases, 26 failing.
* **Reservation / ABA (`lwarx`+`stwcx.`) — GAP.** No corpus case exists and no
  assembler is available. Needs a corpus case or `llvm-mc`.
* **Jump-table dispatch — GAP.** The one corpus case
  (`seq_jumptable_constants.s`) uses local labels and `.long .case_N`
  relocations, so it needs an assembler.
* **Non-local register carriage — STRUCTURALLY UNTESTABLE here.** Test mode
  leaves `RecompilerConfig` default (`test_recompiler.cpp:45-50`), so
  `savegprlr_14_address` is 0, no `__savegprlr_14` is emitted, and
  `PPC_FUNC_PROLOGUE()` degrades to an alignment `__builtin_assume`. Testing it
  needs the TOML path over the real `.xex` — i.e. a guest executor, which is
  the missing deliverable of the next pass.

## Running it

```sh
python tools/difftest/corpus.py                    # decodability census, no build
python tools/difftest/run_difftest.py              # full run; exit 1 on any failure
python tools/difftest/run_difftest.py --json r.json --keep
```

`--keep` preserves the scratch workdir (the emitted C++ is worth reading when a
case fails). Exit 0 = all differential cases matched, 1 = at least one
divergence or harness error, 2 = bad arguments.

## Third-party code

None vendored. `corpus.py` reads Xenia's BSD-2-licensed corpus read-only from
`.research/`; nothing is copied into this directory. No licence header is
required because no third-party source was vendored.
