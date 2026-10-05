# MCLA PC — agent rules (auto-loaded; keep this file short — it costs tokens every session)

Xbox 360 (Xenon) → PC emulator: XenonRecomp static PPC→C++ recompiler + D3D12 backend, guest
`default.xex` (Midnight Club LA prototype). Goal: boot → menu → playable. Not a general game project:
**the guest binary is data, the raw bytes are the source of truth, the docs only about _intent_.** Any
doc sentence asserting a guest fact — address, layout, count, "never fires" — is a hypothesis until
re-measured. Cite the measurement, not the doc (F-458, F-463, F-446).

## ⛔ RULE 0 — NO GUESSING. MEASURE OR DECOMPILE. (added 2026-09-30; its own record re-audited 2026-10-01)

**Every statement about the guest binary, or about a log, is a hypothesis until a tool prints it.**
Reasoning about what the game "must want" is banned.

**On 09-30 the orchestrator asserted 11 things and agents killed them. The tiers matter more than the
anecdotes — a constitution citing a measurement that does not exist teaches readers citations are optional.**

- **LEDGERED — the heading is the only clearance.** A deleted exception that never existed (F-639:
  "REFUTES the widely-repeated claim … cite this heading instead"); "1,267 skipped constructors" is
  **withdrawn** (F-686) though 1,267 is a real count and the guest enters all of them (F-638); the
  brief's `101,600` allocation failures — cumulative `oom=` is **101,700**, and 1,025 is the
  *printed-row* count (F-651); "3 of 4 phantom markers" — `CP: RING A DRAIN` lives in the census skill,
  `CP-REG-TN` is the one genuine phantom (F-651).
- **LEDGERED, GLOSS NOT.** The `DISCCHK` 779→41 collapse is real; F-650 attributes it to the read-mode
  predicate `(w3&3)==2`. The "*log-print filter*" reading is **not** in F-650 — UNVERIFIED.
- **RECORDED OUTSIDE THE LEDGER — name the file, it is not an F-ID.** 299.5 MB vs 354 MB:
  `src/kernel/heap.cpp:950-951` ("299.5 MiB … `n=3 req=354.0MB`"). The 437 "real register writes" that
  were pure zeros: `docs/PROGRAM_GUIDE.md:727` — which credits the kill to "F-637", and F-637 is the
  *compaction census* (`ROOT_CAUSE_VALIDATION.md:14085`), not a kill record.
- **NO RECORD — do not quote as kills.** "a fix resting on n=3", "'six shaders' (57)", "'517 shaders
  compile'": **zero** ledger mentions each. What survives the third is not the anecdote but PROGRAM_GUIDE
  §9's `PC-TRANSLATE` rule — "an offline validator result is not a boot fact" (its ok-arm hardcodes `failed=0`).
- **WITHDRAWN AS INCORRECT — two of RULE 0's own glosses, kept so nobody re-imports them.**
  (a) The `0xC0000000` "placeholder payload that is really `0xC0006200` = `PM4_SET_BIN_SELECT_LO`":
  **no ledger entry contains `0xC0006200` or `BIN_SELECT`**, and F-653 records `v9[1] = 0xC0000000` —
  "Meaning unknown. Recorded, not interpreted." The reinterpretation is dead.
  (b) `walked == 2*t0` as "the signature of an empty buffer" is repudiated verbatim by **F-685**: "NOT
  'the signature of an empty buffer' … It holds 8/8, including on a 1,038,134-dword (4 MB) window, so it
  is a **TYPE degeneracy, not a size one**." A zero dword scores TYPE-0 because `hdr>>30==0`, so
  `walked == 2*t0` is what an all-zero buffer *must* produce. Load-bearing evidence is the raw
  `CP: INDIRECT_BUFFER` dump: 16 zero dwords where `PKT-CAP` read real bytes `0x20000000` lower — a
  *pointer-base* disagreement.

**The authority for a guest fact is `build/cache/mcla_pe.bin` (offset = VA − `0x82000000`), then IDA
decompilation. Never inference. Never a doc. Never a remembered number from an earlier session.**
Decompiler output is still a model. **Any mask claim is invalid until the raw word is read** — that part
was always right and it is the whole lesson. **But F-647's gloss is INVERTED and must not be followed.**

> **F-647 as previously recorded was WRONG, and acting on it corrupts the build.** It claimed "all three
> decompilers render PPC rotate-immediate masks backwards", citing raw `55 6A 00 42` = MB=1, ME=1 =
> "bit 1". **MB=1, ME=1 gives bit 30 → `0x40000000`** — which is exactly what the ISA gives, what
> `ComputeMask` (`recompiler.cpp:5-11`, called as `:1546`) gives, and what IDA *and*
> `generated/ppc_xenon/ppc_recomp.17.cpp` print. **The emitters were right; the record's gloss numbered
> MB from the LSB.** "bit 1" is MB=30, ME=30 — **never (1,1)**.
>
> **Settled 2026-10-05 by three independent implementations against the Xenia oracle: ISA 28/31,
> `ComputeMask` 28/31 — identical 28, identical 3 (all `MB>ME` wrap cases a 32-bit harness cannot
> model).** Both historically disputed words now agree: `MB=1,ME=1 → 0x40000000`;
> `MB=24,ME=31 → 0x000000FF` (`clrlwi` = *clear left*, retaining the low `32−n` bits).
> **The correct record is F-765, not F-647.** Populations reproduce exactly: 72,297 rotate-immediate
> words, 16,709 with MB=24/ME=31, 16,708 `& 0xFF;` sites, **0 non-rotate** — 100% rotate-family.
>
> ⚠️ **"Fixing" `generated/**` to `0xFF000000` inverts 16,709 sites across 176 translation units and
> makes the boot strictly worse.** Do not. `generated/**` is forbidden anyway (rule 2).

**Field notes, all measured, so you do not rediscover them the hard way:**
- ⚠️ **`ori`'s destination is `b25:21`, NOT `b20:16`. This note previously said the opposite and was
  wrong.** Authority: LLVM's own `PPCInstrFormats.td`, `class DForm_base` —
  `let Inst{6...10} = RST; let Inst{11...15} = RA;` ⇒ **destination at word bits 25:21**, source at
  20:16. Re-encode round-trip: `ori r9,r8,0x6772` → `0x61286772` **matches the guest byte**;
  `ori r8,r9,0x6772` → `0x61096772` **does not.** Five controls in the same function
  (`addi r4,r1,80`=`38810050`, `li r5,256`=`38A00100`, `lwz r7,80(r1)`=`80E10050`,
  `lis r9,0x6178`=`3D206178`) all agree.
- **The asymmetry is the trap, and it is what produced an hour of wasted work:** `b25:21` is correct
  for `or`/`and`/`xor`/`mr`/`cmp` (`0x7FC8F378`=`or r8,r30,r30`), and **`b20:16` is correct for
  `ori`/`addi`/`addis`/`lwz`/`stw`.** Both conventions are right — **for different opcodes.** Never
  generalise one from the other. **Extract nibble by nibble; shift-and-mask arithmetic has produced
  four wrong answers in this project.**
- 🔴 **`generated/ppc_xenon/` mis-emits `ori` immediate-form with SWAPPED operands** — proven at two
  sites (`0x8218C848`→`ppc_recomp.9.cpp:18434-18435`; `0x8213DC98`→`ppc_recomp.1.cpp:16207-16028`),
  and **localised, not a convention error**: in the 7-instruction window at `0x8213DC90`, six
  instructions decode identically under both readings and only the `ori` diverges. There are
  **3,415** `ori`-imm emissions, so a blanket inversion is implausible. **This is a real defect in
  generated code — do not "fix" it by hand; route it through `.qoder/skills/mcla-recompiler-regen`.**
- **`ori rA,r0,imm` round-trips as a no-op store to `r0` in Capstone 5.0.7** — a real defect in its
  or-immediate arm. Do not use it to settle operand order.
- **An `op18` branch target read as signed lands outside the image; `ppc_disasm.py` reads it unsigned
  and also lands outside.** Not resolvable under either convention — use `bc` (16-bit BD) targets.
- **`tools/ppc_xrefs.py calls` misleads.** It reported 20 "callers" of `0x821BE250` where a raw scan
  finds **0** direct call sites (vtable dispatch), and its `->` column names the *enclosing* function.
- **`tools/ppc_disasm.py` prints `mr` with RA/RT inverted** (F-112) and **cannot decode opcode-30
  `rldicl`/`rldicr` at all** — it falls back to a generic `rldic-family`. Use `generated/ppc_xenon/*.cpp`
  as the tiebreaker for those.
- **Do not trust operand ordering in `generated/ppc_recomp.*.cpp` comments** — four sources disagreed
  and the emitted code was the tiebreaker, not the comment.
- **A control with `MB=0` is symmetric under the MB↔ME swap and therefore has *some* power but not
  none** — measured: it discriminates five candidate wrong-models; only `ME=0` and `ME=31` are blind.
  A widely-circulated claim that it is *powerless* was itself false. **Establish the discriminating
  power of any control you rely on.**

**How to stop guessing — use these, not your memory:**
| need | tool |
|---|---|
| decompile guest functions | `python tools/ida_dump.py <dir> 0x821378B8 0x…` (bridge on :8745) |
| whole image as files, with raw bytes | `python tools/ida_bulk_export.py <dir>` |
| raw instruction truth | `tools/ppc_disasm.py` (offset = VA − `0x82000000`; prints raw fields, not mnemonics) |
| xrefs (use `calls`/`fn`, **not** `xref`) | `python tools/ppc_xrefs.py calls 0x824112C8` |
| who owns a guest address | `python tools/addr_owners.py --check 0x…` — hex **or** `sub_<VA>` both work |
| exact log counts | `open(f,'rb').read().lower().count(b'…')` — **not** `findstr` alone |

**Traps that have each produced a false reading:** `CALLERS (none)` is an IDA carving artifact, not
evidence. A marker absent from `src/` has a zero that means nothing — **prove the literal exists before
interpreting its count**. An offline validator result is **not** a boot fact (one `submitted=1` on
`PC-TRANSLATE` is the whole shader frontier and is **not** evidence a shader compiles).
`shlex(posix=False)` splits `/I"E:\mcla pc\src"` and invents 35 errors. `-c` is a substring of `-clang:-std=c++23`.

**When you must state something you have not measured, label it a prediction and say what would
falsify it.** Never state it as a fact. Per rule 14 a brief is not authority — and as of 09-30 that
includes this orchestrator's briefs.

## Read in this order (never skip step 1)

1. `docs/LONG_TODO_MASTER.md` — §0 dated state, §1 rules, §2 task queue, §4 do-not list.
2. `docs/HANDOFF_NEXT_AGENT.md` — live block + session ledger (what the last session actually saw).
3. `docs/PROGRAM_GUIDE.md` on demand — §3 build/run gotchas, §4 guest image, §5 recompiler pipeline, §7 host short-circuit table, §9 log-marker inventory, §10 RE tooling, §11 forbidden paths.
4. `docs/ROOT_CAUSE_VALIDATION.md` Part 3 — the append-only evidence ledger. **Never trust an ID range quoted anywhere, including here**: the top moves hourly (last heading `### F-719`, 575 headings, on 2026-10-01). **F-056…F-076 is a documented hole** (`:2098`; that week survives only as unnumbered prose at `:1071-1166`), so **F-057/F-058 resolve to nothing** and a grep that finds nothing does *not* prove a citation was fabricated. **F-629 has no `###` heading** (17 textual mentions, all references to the void); it was reconstructed as **F-635** — do not renumber or reuse it.

Older status text anywhere else = trail, not truth. Pre-compression doc text: `git show 8f07a39:docs/<file>`.

**Before asserting anything about the tree, re-census it** (`grep`, `ls -l`, `git log`). Three claims in one handoff were false purely because they were remembered from a compaction summary, not re-measured. That is rule 13 in practice: **cite a tool-printed log line or a `file:line`; a commit hash alone marks the claim UNVERIFIED until a soak reproduces it.**

## The 7 rules that keep costing sessions

**Rule numbers are namespaced — never expand a bare "rule N" without naming the file.** This file:
1–6, 14. `LONG_TODO_MASTER` §1 (`:970-990`, rules 1–19 — what a bare "rule 11/13" means): 5 = one new
log per experiment (`:976`), 6 = timeout every boot + kill `mcla.exe`, 7 = tree must always compile,
8 = retail content only, 9 = no framework rewrites while not booting, **10 = write the trail as you go**,
**12 = the stale-exe trap**. `PROGRAM_GUIDE` §11 (`:785-818`, rules 1–11) — **6/7/8/9/10 collide with
`LONG_TODO_MASTER` §1**, its 5 = do-not-stack-short-circuits (`:797`). So **"rule 5" is triple-valued**
(this file's concurrency rule, `LONG_TODO_MASTER.md:976`, `PROGRAM_GUIDE.md:797`) — write the file. Two
live miscites prove the cost: `ROOT_CAUSE_VALIDATION.md:8581` "agents.md rule 12" (that rule is
`LONG_TODO_MASTER` §1's stale-exe trap) and `HANDOFF_NEXT_AGENT.md:528` "AGENTS.md rule 5/6" (only
rule 5 is relevant there — this file's rule 6 is the E:-primary merge note).

1. **Census before fix.** No short-circuit without a root cause; never stack short-circuits (do-not #1/#9). A mitigation must be labelled and cited at its `file:line`.
   **1a (bisect attribution).** A `src/` change may not be named as a fault's cause unless the only build differing from the last known-good is that change, or a single-variable revert is shown; otherwise write "N-way" and name the other files still in the build. **A citation is not attribution.** *Check:* `git diff --name-only <last-good>..HEAD` ∩ `src/` = 1 file.
   **1b (new-symbol taint).** Any new `static`/`extern` host function or global in the working tree must be listed in the same claim; attribution stays provisional until a revert excludes or confirms it. *Check:* `git diff <last-good>..HEAD -- src/ | grep -E '^\+.*\b(static|extern)\b'`.
2. **Never edit `generated/**`, `.research/**`, `config/mcla_xenonrecomp.toml`, `src/ppc_context.h`, `src/ppc_config.h`, `src/dispatch_guard.cpp`** — full forbidden + default-modifiable lists: PROGRAM_GUIDE §11 (`:802-806`). Tool changes go through `.qoder/skills/mcla-recompiler-regen`.
3. **Raw-byte rule (F-023).** `build/cache/mcla_pe.bin`, offset = VA − 0x82000000, words big-endian; the PE section table lies; IDA is a hypothesis until the bytes agree.
4. **One owner per guest address.** `python tools/addr_owners.py --check <addr\|symbol>` before adding any hook (it reads `PPC_FUNC`/`GUEST_FUNCTION_HOOK`/`SetFunction`/`GetFunction`; **exit 1 = duplicate owners**, 2 = unresolvable symbol). grep is the fallback, not the check.
5. **Concurrent sessions are normal.** Before building/booting: `tasklist | grep -iE "mcla|ninja"` and the newest `build/*.log` >2 min old (= `LONG_TODO_MASTER` §1 **rule 11**). Before writing a doc: check its mtime and add a dated superseding block rather than editing someone else's.
6. **E: is primary again (merged 2026-09-23; pre-merge state = commit `35912f0`).** `C:\mcla-pc` is a retired **read-only** archive; provenance snapshot `E:\mcla-c-snapshot-20260923`. Verified then: the merged tree **built clean on E: (`build_on_e.bat`, 11/11, 0 errors) and `w46.log` reproduced `w45b`**. Do not start building on C: again; `diff -q` against the snapshot before trusting either side.
14. **Premises must be cited.** Every factual assertion in a task brief or a finding carries a `file:line` or a log line. No citation means verify before acting, not after. A brief is not authority; a measurement is. Briefing from this project's own records is a defect, not a shortcut.

## Project skills (`.qoder/skills/`) — use them, don't rediscover the gotchas

| Skill | When |
|---|---|
| `mcla-boot-cycle` | any src change to compile+boot (MSYS guards, kill-before-build, stale-exe trap, new log per run) |
| `mcla-guest-raw-decode` | attributing a fault `lr`, naming a vtable slot, checking an IDA address (`lis` sign-extension trap) |
| `mcla-log-census` | reading/comparing soaks or claiming a gate (case-insensitive counts vs named baseline) |
| `mcla-finding-ledger` | writing any conclusion down |
| `mcla-recompiler-regen` | VMX128 ops, stubs, jump tables, `midasm_hook` work |

## Project tools (`tools/*.py`) — the executable form of those skills, run them instead of re-deriving

| Tool | When | Exit code |
|---|---|---|
| `tools/soak_census.py <new.log> <baseline.log>` | reading or comparing any soak. Every tracked marker counted as matching **lines**, case-insensitive (= `grep -ic`); fault-line vs all-line `lr=` split; a **CP truth** line (`drains`/`last_rptr`/`pub` vs `put` — the only honest pipeline signal; a waiter's `rptrWB=` is not, F-057(1)/F-058, both in the ledger hole); and **LOG QUALITY**, which WITHHELDS the whole marker table when one mitigation shape owns a log (F-054: `w38e.log`, 616,824 firings = 33% of 1,860,449 lines, `soak_census.py:65-66`). Prints **MARKER NOT IN SRC** for any tracked marker whose literal is in neither `src/` nor `generated/` — its zero means nothing (F-057(6)). Reconcile a hand count with it before claiming it. | 0 |
| `tools/addr_owners.py` | rule 4, before adding **any** hook — guest address → `file:line` → hook name, plus which sites actually *claim* it. `--check <addr\|symbol>` for one site; `--gates <addr>` prints each claim's enclosing-function conditions **verbatim, uninterpreted**, so a conflict is resolved by reading the soak for the *installer's* own log line, never by guessing which registration wins (F-053). **`--check` takes hex OR `sub_<VA>`: the three-tier resolver documented at `tools/addr_owners.py:53-76` tries `hex`, `sub_`, then the generated table, prints which tier answered, and exits 2 rather than 0 when it cannot resolve. Measured 2026-10-01: `--check sub_821CA540` = 2 sites, exit 0 — the old "symbol form is broken, use hex" warning described a real bug that is now fixed; its history is the tool's own docstring at `:72-75`.** | **1 = duplicate owners**; 2 = unresolvable |
| `tools/mitigation_audit.py` | do-not #9 — diffs the PROGRAM_GUIDE §7 registry against the mitigation-shaped labels really in `src/`. Re-measured **2026-10-01**: **§7 = 92 registered, 4 stale; `src/` = 105 mitigation-shaped of 1,330 label tokens; 86 undocumented** (the old "13" was the F-047 reading). `--tiers`, `--label X`. | **1 = unregistered/stale** |
| `tools/ppc_xrefs.py` | static xrefs without IDA: `find-str <text>`, `xref <hexVA>` (`lis`=`addis rT,0,imm`! sliding per-register state), `calls`, `fn`. One-site messages are load-bearing attributions (F-102 named the whole preload chain this way). | 0 |
| `tools/rpf_offline.py` | archive forensics without a soak: `header` (RPF3 TOC length/endianness), `names <toc_dump>`, `find <path> [archive\|dump]`, `member <off> <len>`, `islands`. Raw-archive `find` returns 0 **by design** — the on-disk TOC is AES, the in-guest copy is a hash-sorted cleartext table (F-099). | 0 |
| `tools/host_rva_resolve.py build/mcla.map [--base <runtime image base>] <rva\|absolute>…` | names a **host** address from the VEH/PARK dumps (`rip owner=host …`, `rawrip=…`, the host stack lines) using the `/MAP` every link already writes (`CMakeLists.txt:577`; the old `§410` pointed at the `ppc_recomp.82..85` list) — this turned F-370's `C0000005` from "some host thread" into `memset ← GuestThreadContext ctor`. Control: a known symbol must resolve at `+0x0`, using the map from the SAME build as the log. | 0 |
| `build/soak_parallel.py` | **REFUSES to run more than one mcla** ("Single-instance bounded soak runner", docstring `:1`). The old N-affinity-pinned mode and its `time.sleep(5)` stagger (`:3-5`) were unsound: one window, one D3D12 device, one audio endpoint, one VFS cache, so a collision is a **synchronisation** bug pinning cannot fix (F-572). **Soaks run through `build/soak_run.py`** (`:41-43`). | 0 ran / **2 refused** |

## Project MCP servers — both `opencode.json` (gitignored, different schema) and the committed `.qoder/settings.json` declare the same **three** (first load shows a trust prompt; run `/mcp reload`)

| Server | What it is | Constraint |
|---|---|---|
| `ida-pro` | `python ~/.local/share/mcp/ida-bridge.py` → idalib on `build/game_data/default.xex`, RPC :8745 | it `taskkill`s `idalib-mcp.exe` on start — **never** launch it while another session's IDA session is open. If `tasklist` shows `idalib-mcp.exe`, **attach to `http://127.0.0.1:8745/mcp` instead** (POST, `Accept: application/json, text/event-stream`, keep `Mcp-Session-Id`) — verified working 09-20 22:2x: 47 tools, `get_metadata`, `decompile_function`, `get_xrefs_to` (PROGRAM_GUIDE §10) |
| `renderdoc` | `python -m renderdoc_mcp` + `C:\Program Files\RenderDoc` | for capture analysis only (W34/W35 GPU work); hooks must stay log-only, no RenderDoc in the boot path |
| `x64dbg` | headless x64dbg (`x64dbg_run` / `x64dbg_attach`) | launch-under-debugger only; never in the boot path |

Built-ins worth using: `node-repl` (the manifest TOMLs must be edited via node tooling, never by hand — PROGRAM_GUIDE §11), `browser-use`/`WebSearch` (Xenia/XenonRecomp upstream semantics — cite the file:line into `.research/xenia/` too, a local checkout). `qoder-qmind`/`sites`/`canvas` are irrelevant; don't spend turns on them.

## Known conflicts / hazards in this directory (full register: `LONG_TODO_MASTER` §8)

- **Two agent configs, same three servers, different schema** — keep them semantically identical and note which one you changed. `.gitignore` ignores `.mcp.json`, which **Qoder does not read**: don't create it.
- **`.qoder/` is NOT gitignored**, so `settings.json` and the skills are committed. They carry absolute machine paths (`C:\Users\abdul\...`) — fine for this single-user repo, but never add a secret/token here; use `.qoder/settings.local.json` for per-machine overrides.
- **NOT a duplicate — a prior "delete the root one" instruction here was WRONG (corrected 2026-09-28).** Root `CODE_OPTIMIZATION_PLAN.md` is the live **coding policy (Ponytail+)** + MCLA guardrails, "still in force" (`:1-8`); `docs/CODE_OPTIMIZATION_PLAN.md` is the 2026-09-20 **compressed task-status** list, "Subordinate to `docs/LONG_TODO_MASTER.md`" (`:1-4`), which cites the root file for the guardrails (`:22-23`). Complementary: docs/ wins on *task status*, root on *policy*. The VOID warning still stands as a rule: **never follow any Phase 0 that edits `generated/`.**
- **Two task queues.** `LONG_TODO_MASTER.md` §2 is the durable queue; the agent `TaskCreate` list is per-session scratch. Never let a queue item live in only one of them.
- **Root junk is mostly discharged, and `git add -A` is unsafe here** — stage named paths only. Two deliberate root residents: **`mcla_jts_regen.toml`** (the live jump-table regen config, read as `BASE_CONFIG` by `tools/fix_stubs_iter.py:20`) and `CODE_OPTIMIZATION_PLAN.md` above.
- **`docs/` is tracked since 09-20** (`.gitignore:9-12` says so; `git check-ignore docs/…` exits 1) — plain `git add` a new doc. Never re-ignore it.

## Non-negotiable project constraints

Retail content only (`xarchive_cache.rpf` + audio/music; never `mc4/art`). Guest pointers are 32-bit
guest VAs read through the checked helper with explicit endianness (`ReadU16BE`/`ReadU32BE`/`ReadF32BE`)
— no `reinterpret_cast` on guest data. Census hooks capture state only: no D3D12 calls, no
`RegisterFile` dependencies, no invented draw data. No ReXGlue SDK dependency — from
LARecomp/BadassBaboon take guest *facts* only (addresses, timings, quirks), never their architecture or
`rex::` runtime. Do not pop stash `session33-audlo-forensics-gpu-device-capture-hardening` (it regresses
boot). Commit only when asked.