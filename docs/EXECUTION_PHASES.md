# EXECUTION PHASES — executor protocol + phase ledgers (Phase 0 / 1 / 2)

> **Compressed 2026-09-20.** Part A is the executor/auditor **protocol — still in force** for
> every phase (hard rules, ledger format, classification, escalation). Everything after it is a
> **phase ledger**: Phases 0/1/2 were executed and then superseded by the W36 series; do not
> restart them from this text. Live queue: `docs/LONG_TODO_MASTER.md` (T37.x).
> Pre-compression text (verbatim briefs + full run logs): `git show 8f07a39:docs/EXECUTION_PHASES.md`.
> Former names merged here: `CHEAP_MODEL_EXECUTION_PLAN.md` (Part A),
> `PHASE0_IMPLEMENTATION_SUBPLAN.md` / `PHASE0_EXECUTION_TASK.md` / `PHASE0_EXECUTION_LOG.md`,
> `PHASE1_EXECUTION_TASK.md` / `PHASE1_EXECUTION_LOG.md`.
>
> **One correction to the old Part A text:** its claim "the logged `lr=0x82189270` is GARBAGE /
> never build caller chains from census lr" was **overturned** by ledger finding F-023 (raw file
> bytes are ground truth; that lr is real). The general caution stands only for lr attribution
> *after* memset/leaf calls (sticky-LR artifact — `PROGRAM_GUIDE.md` §8 Misc).
> IDA claims still need raw-byte verification.

---

# PART A — EXECUTOR PROTOCOL

**You are the executor.** A heavier model did the reconstruction and proved several facts
already; everything you need is in this file and the ledger. Work the tasks in order, append
evidence to `docs/ROOT_CAUSE_VALIDATION.md` Part 3, then assemble the report. Do not re-derive
what is already established.

## Hard rules (violating any of these fails the audit)

1. **NO FIXES** in audit mode. Do not modify `src/`, `generated/`, `config/`, `CMakeLists.txt`
   or `.research/`. No edits to stubs, hooks, mounts, IO or the build. Diagnosis only.
2. **Allowed to write exactly two things:** the findings ledger (append-only) and the report
   (`ROOT_CAUSE_VALIDATION.md` Part 2, written once at the end).
3. **Never run the recompiler into the project tree.** If regeneration is needed for comparison,
   output to `build/xr_audit_tmp/`.
4. **Preserve all logs.** Read-only; copy a log before experimenting on it.
5. **Do not run the game binary expecting new behavior** unless a task says so — then always
   `timeout 120` into a **NEW** log name (never overwrite an existing soak).
6. **Escalate, don't guess.** Hit an escalate condition → stop that task, write the escalation
   note in the ledger, move to the next task.

## Context capsule (established facts — do NOT re-derive)

**A1. The canonical fatal event** (`build/boot_stdout_78.log` @19:13:04.763):

```
GETDEV #40 path='embedded:/fxl_final/star_glow.fxc'   -> miss
GETDEV #41 path='a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl' -> miss (mangled)
GETDEV #42 path='a:/archive/dcl/star_glow.dcl'        -> miss
GETDEV #43 path='a:/archive/fxl_final/star_glow.fxc'  -> miss
Fatal error dispatcher invoked - terminating game
  regs: lr=0x82189270 r3=0x8200B358 r4=0x82040F0C r5=0x16 r6=0x02CB3970
  slot 0x8285FEA0 = 0x82130678
  fatal message: 'Unable to load shader '%s', it probably wasn't preloaded properly.'
  fatal aux r4: 'star_glow'
```

**A2. True call chain** (reconstructed via IDA xrefs, *not* via lr): `sub_8218C9D8` (shader
load-by-name wrapper, builds `"embedded:/"` + name on the stack) → device dispatch →
`sub_821BDF20` (INSERT file-resolve) → GETDEV → **vtable+4** `sub_821CAFB8` (accepts only
`memory:` → −1 for `embedded:/`) → lookup-or-insert `sub_82189438`/`sub_82189138` → fatal.

**A3. Proven traps:** the `lr=0x82189270` attribution (see header note — F-023 settled it);
`EMB76` is never the acceptance signal (INSERT uses vtable+4); do not GETDEV-redirect to the
archive (F-027, rejected); do not write `0xA00xxxxx` guest scratch; do not patch
`byte_827D5C70`; do not stub the fatal; do not re-parse the PE. Full list: `PROGRAM_GUIDE.md`
§7 + `LONG_TODO_MASTER.md` §4 (do-not).

**A4. Runtime/harness facts:** census hooks (GETDEV/MOUNT76/EMB76/TOC76/TEXCTOR/GEN76-*/
BUDDY76/HEAP76/FFBT/BOOTPATH/WAIT/WAKE/TSLAB-*) live in `src/gpu_device.cpp` (+ some in
`src/patches.cpp`), all log-only; the line `mcla_patch_groups = 'all'` confirms they are armed.
Boot recipe and the MSYS/`taskkill` gotchas: `PROGRAM_GUIDE.md` §3.

**A5. Open questions the tasks answered** (kept as the audit's decision forks): Q1 was star_glow
ever preloaded, or was the lookup path itself defective; Q2 what writes `byte_827D5C70`; Q3 does
`sub_8218C650` exist as a standalone function; Q4 what registers an embedded/`memory:` device and
when. Answers: ledger F-001…F-035.

## Ledger format (Part 3 of `ROOT_CAUSE_VALIDATION.md`)

```
## F-###  <short title>
- Task:        T#
- Type:        FACT | INFERENCE | FIX
- Class:       A|B|C|D|E|F|G|H|I
- Priority:    P0|P1|P2|P3|P4
- Evidence:    log line / raw file words (offset = VA − 0x82000000) / file:line
- What it means / what it overturns
```

## Task list (the audit's T1–T12 — all executed; kept as the template)

| # | Task | One-line purpose |
|---|---|---|
| T1 | Decode the census hooks | learn how to read every log line (FFBT/MOUNT76/EMB76/GETDEV) |
| T2 | Was star_glow ever preloaded? | decision fork F1: preload defect vs lookup defect |
| T3 | `byte_827D5C70` | fatal-vs-fallback switch — is it a variable at all |
| T4 | `sub_8218C650` lookup semantics | plus integrity compare of `sub_82189138` vs raw bytes |
| T5 | Embedded/memory device registration hunt | who should register the device, why it never runs |
| T6 | Executed-path reachability join | map every executed LR to a known function |
| T7 | Generated-code completeness census | TODO/UNIMPLEMENTED/`ERROR: 0x` stubs across the tree |
| T8 | Integrity spot-check | sample executed-path functions vs the raw image |
| T9 | Boundary/CFG anomalies | jump-table/branch-boundary suspects |
| T10 | Disc/IO classification | read-only, from prior logs |
| T11 | Kernel/runtime stub risk table | expected Xbox behavior vs our implementation, per import |
| T12 | Assemble the final report | Part 2, 20-section skeleton |

## Classification tree (mechanical)

- Wrong instruction stream / branch target / skipped insn / bad boundary, proven by
  IDA-vs-generated diff → **A** (XenonRecomp/codegen).
- Generated code compiles but computes a wrong value (no A-level structural defect) → **B**.
  Guest ABI / pointer / endianness / stack error → **C**. Kernel/runtime implementation → **D**.
  Filesystem/device missing → **E**. GPU/shader translation → **F**. The game's own coded
  behavior → **G**. Instrumentation false positive → **H**. Unknown/insufficient evidence → **I**.
- Priorities: **P0** proven first divergence · **P1** highly likely contributor · **P2** reachable
  but not causal · **P3** unreachable before the current failure · **P4** future/shipping.

## Escalate to a heavy model when

- Any A-class finding is on the executed path (stop, capture evidence, skip to T12 — the report
  matters more than more breadth).
- IDA and generated code visibly disagree on control flow and you cannot tell which is right.
- A task gate requires a code change to proceed.

## Deliverables checklist

- [ ] Ledger exists with ≥1 entry per task T1–T11.
- [ ] Report with all 20 sections, filled from the ledger (findings → §16 classification,
      §17 ranking, §18 evidence table).
- [ ] Root-cause graph (§15) with symptoms explicitly marked as symptoms.
- [ ] "DO NOT FIX YET" list (§20) carries every proposed fix that would mask a root cause.

---

# PHASE 0 — shader dictionary population fix — **CLOSED (09-13)**

- **Ground-truth correction (F-024):** the dictionary hash table is **`0x82839F70`**
  (256 × 4 B), not `0x827C9F70` — the `lis r11,-32124` pattern decodes to `0x82840000`, the
  earlier capsule had it wrong. Active dict list head is `0x82839ED0`.
- **Stage A — factory chain (10 entries):** `sub_8218BF20` creates the entries, `sub_8218B000`
  registers them into the active list. Every function in the chain is reached by vtable /
  indirect dispatch — there are **zero direct `bl` callers**, which is why static "who calls
  this" searches kept coming up empty; census hooks on the mapped callers show factory ×10,
  TEXDICT-CALLER ×10.
- **Stage B — why lookups still miss:** the factory's entries are linked into the active list
  but the **hash table at `0x82839F70` is never populated**. `sub_82189438` (register entry) →
  `sub_82189138` (lookup-or-insert) therefore returns −1 → `star_glow` fatal.
- **Stage C — host-side fix (`HydrateShaderHashTable`, +105 lines in `src/gpu_device.cpp`, all
  additive):** the TEXDICT-CALLER census hook stores each factory entry pointer (r3); after the
  10th hit the host writes those pointers into the hash table (first-empty-slot policy matching
  the guest's own). Bypasses the broken INSERT path without touching guest semantics.
- **Stage D — verification:** baseline `boot_stdout_78.log` = fatal present; fixed boots
  (`80`/`p0d1`) = fatal ABSENT, boot alive past the old crash point with threads waiting on I/O
  (KWFSO waits, SEMA releases, TOC76-RET referencing `resources/ui/policecam/policecam.xsf`).
  Anti-cheat self-check answered: the fix only writes pointer values into addresses the PPC
  binary already uses.
- **Ledger additions:** F-024 (hash-table address), F-025 (`sub_82188E50` is the INSERT; fires
  on cache miss but fails because `sub_821CB488` returns NULL).
- **Do-not-fix carried forward:** `byte_827D5C70` (F-013) — patching it would mask the symptom.
- **Successor:** T5 ("remove hydration once INSERT works without it") stayed open on purpose;
  `DICT-HYDRATE` is still in tree (commit `3c8744e`).

> **CORRECTION 2026-09-21 (F-085) — read before trusting Stages B/C/D below.** Raw-byte and log
> measurement converted Phase 0's predictions into evidence. **Confirmed:** F-024's `0x82839F70`, decoded from
> `3D608284` (`lis r11,0x8284`) + `3B8B9F70` (`addi r28,r11,-0x6090`) at VA `0x82188E5C`/`0x82188E60` inside
> `sub_82188E50`; and Stage A's factory census. **Refuted:** Stage B's "empty hash table → `sub_82189138`
> returns −1 → `star_glow` fatal" — `w38s.log:3975` shows `DICTLOOKUP-OK … slot=10`, a *success*, followed by a
> *different* fatal, and `w41i.log` shows `sub_82189138` called **0 times** while the same fatal occurs, so the
> dictionary lookup is not on the fatal path. **Refuted:** Stage D's "fatal ABSENT". The only log that ever got
> past `star_glow` did so because the host served the `rage_im.fxc` body (5,258 B) in answer to `star_glow`
> requests (`w38s.log:3848`, `:3860`) — a do-not #9 fabrication, since removed by T41.3d
> (`src/gpu_device.cpp:11030`, `AFB76-MISS-HONEST`). **The present tree is not regressed, it is honest; do not
> restore that frontier.** Stage C's `HydrateShaderHashTable` runs identically on both trees and writes ten
> `0xA002xxxx` objects whose +4 word is `00000000` and whose names are empty — no measured effect. Full
> evidence: `ROOT_CAUSE_VALIDATION.md` **F-085**.

# PHASE 1 — IO completion gap / streaming stall — **CLOSED (09-13)**

- **Ground-truth correction (F-030):** the Phase-1 §0 claim "the IO slot never completes" is
  **overturned**. T1 decoded the wait at `lr=8242FC1C`/`8242FCB0` as the healthy GPU-worker tick
  (`40004D7C`), not a load stall.
- **T2/T3 (p1b):** the p0d1 "TOC76 #22 hang" is **flaky** (F-031) — the real terminal event is
  the star_glow fatal. Hydration DID run and is insufficient on its own; the star_glow load
  cascade was proven step by step.
- **Post-inflate callback is NOT a memory mount** (F-032) — it is a semaphore release. The
  "memory mount happens after inflate" theory died here.
- **Mount call sites (static, raw-verified):** only 3 (`sub_821CBF28` wrapper — fires 2× for
  `a:/archive/`; `sub_821399E0` — 0 xrefs; `sub_82139BE0` via `sub_82135E48`) (F-033).
- **T4a (p1c/p1d) — Mount-gate census: BRANCH 3 CONFIRMED** (F-034): the entire non-archive
  Mount chain never executes, so no `memory:` device is ever registered. The `memory:` format
  string was located (F-035: `"memory:$%p,%d,%d:%s"` @ `0x82012A28`, `"memory:"` @ `0x820127D8`).
- **Output of this phase = the Phase-2 brief** (below): hunt the fetch armer and the CDCD
  marathon, not more IO hooks.

> **CORRECTION 2026-09-21 (F-086) — A-capsule and Phase 1 re-measured.** **Confirmed by raw bytes:**
> A2's "vtable+4 = `sub_821CAFB8`" (words at `0x82012918` are `821CAE50 821CAFB8 …`, preceded by RTTI
> `820DDDC8 821D61F8`); F-035's two `memory:` literals; F-033's mount census (exactly 2 `MOUNT76`, both
> `a:/archive/`, both `lr=821CBF54`); F-031 (TOC76 reaches #80, no `#22` hang). **Refuted:** A2's wrapper
> `sub_8218C9D8` — 0x1000 bytes of its body contain no `lis` that can form any of the four `embedded:/`
> literals; the real builders are `sub_82189138`+0xA8, the device vtable's slot 0 `sub_821CAE50`+0x20, and
> `sub_821CB488`+0x3C, and the measured caller of `sub_821BDF20` on the shader path is `sub_8218C760`
> (`lr=8218C7F4`). The `memory:`-only test is real but lives in **`sub_821CB488`** (7-byte compare against
> `0x820127D8`), not in `sub_821CAFB8` — so the "resource handler lookup returns NULL" wording in
> `src/gpu_device.cpp:2042` is false. **Void citation:** F-030's `40004D7C` occurs **0 times** in the image;
> both hot `lr` sites are `bl 0x827BD5A4` = `KeWaitForSingleObject` followed by an `lwarx/stwcx.` refcount
> release, hit 13,237× per boot — F-030's conclusion survives, its label "GPU-worker tick" does not.
> **Answered (A5 Q3):** `sub_8218C650` is not a function; it is `sub_8218C638 + 0x18`. **Superseded:** F-034's
> "no `memory:` device is ever registered" — device `0x827D838C` is returned for every `embedded:/` GETDEV.
> Full evidence: `ROOT_CAUSE_VALIDATION.md` **F-086**.

# PHASE 2 — de-park the boot (CDCD fill marathon, executor fetch, TLS truth) — **CLOSED**

**§0 capsule (all log/raw-verified 2026-09-14, do not re-derive):** the full text is folded into
`HANDOFF_NEXT_AGENT.md` → "Durable facts" (TLS truth, CDCD marathon, executor fetch gate). The
tasks were:

| Task | Goal | Gate |
|---|---|---|
| T1 | Long soak (15–20 min) to classify the CDCD marathon: finite init / runaway / cyclic thrash | classification written with counts |
| T2 | Decode the 3-slot page cache + refill loop (`sub_8244F4C0` callers) | who arms batch-1 but not batch-2 |
| T3 | Executor fetch-gate decode | the missing fetch call identified |
| T4 | Deep TLS slot dumper (slot +12, FuncBlock+16) | never-armed vs armed-then-zeroed fork decided |
| T5 | Find the fetch armer for later batches | armer located or ruled out |
| T6 | Fix + verify at the boot loop | boot ×2, no new `[error]` class |

**§B execution log (compressed):**

| Step | Date | Result |
|---|---|---|
| p2a | 09-15 | Static-analysis pass: T2/T3/T5 decoded before any boot; no code changed |
| p2b | 09-15 | First fix: `MakeMemoryStream` inserts into the guest slot table |
| p2c | 09-15 | Second fix: BE8D8-HOST path + slot-0 guard |
| p2d | 09-15 | rgxa magic check decoded (F-036 family) |
| p2f | 09-15 07:00 | rgxa FIXED → new frontier `825FDC64` |
| p2f–p2o | 09-15 08:00–09:00 | Preload crash chain FIXED (three-guard neutralization of poison container walks, F-038; `GetKernelObject` raw-cast AV, F-037); boot stable 240 s+ |
| p2p | 09-15 11:20 | **F-039** identity-semaphore fix (`NtCreateSemaphore` handle never registered → Release woke a phantom wrapper, the T5 root cause); preload RUNS; GPU frames start |
| p2t | 09-17 | `sub_821873E8` fixed + guest-memory self-test PASS → star_glow frontier; handoff to W36 |

---

# TEMPLATE — adding the next phase

New phases append below with the same shape: **§0 ground-truth capsule** (log/raw-verified facts,
each with an evidence line), **§1 tasks** (each with a hard gate), **§2 escalation conditions**,
**§3 deliverables**, then **§B execution log** filled in as the phase runs. Keep gates honest:
no task is "done" without a soak-log line or a raw-word citation.

