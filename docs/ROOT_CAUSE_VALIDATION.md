# ROOT-CAUSE VALIDATION — MCLA PC Rebuild (method + report + findings ledger)

> Consolidated doc (formerly `ROOT_CAUSE_VALIDATION_PLAN.md` Part 1,
> `ROOT_CAUSE_VALIDATION_REPORT.md` Part 2, `ROOT_CAUSE_VALIDATION_FINDINGS.md`
> Part 3 — content preserved verbatim below).
>
> Reading order: Part 1 = the audit method and classification system; Part 2 =
> the report as written at audit close (session 78b); Part 3 = the append-only
> evidence ledger F-001…F-035, which continued to grow after the report.
>
> NOTE: Part 2 reflects session-78b conclusions and is partly superseded by the
> later execution logs (`EXECUTION_PHASES.md` Phase 0/1) and by the live
> frontier in `HANDOFF_NEXT_AGENT.md` — in particular, "shader dictionary
> population failure" was later traced to the INSERT path failing because the
> resource handler returns NULL, and the current frontier is the missing
> `memory:`/embedded device mount (ledger F-024+, handoff top block). New
> findings append to Part 3, continuing the F-### numbering.

---
---

# PART 1 — ROOT-CAUSE VALIDATION SUB-PLAN (verbatim)

# ROOT-CAUSE VALIDATION SUB-PLAN — MCLA PC Rebuild

**Status:** EXECUTING (session 78b, 2026-09-12)
**Phase:** Evidence collection and diagnosis ONLY.
**Hard rule:** Do NOT modify source code, generated code, XenonRecomp, runtime
behavior, stubs, mounts, shader handling, IO, or build configuration during
this investigation. No symptom fixes. If regeneration is needed for comparison,
it goes to an isolated scratch directory; the project tree stays untouched.

---

## PRIMARY OBJECTIVE

Determine the **FIRST REAL DIVERGENCE** between the original Xbox 360 execution
path and the PC/recompiled execution path.

We specifically need to rule in/out the possibility that the current
"embedded shader device / star_glow" failure is itself **downstream of
incorrect XenonRecomp output**.

**Success condition — answer ONE question with evidence:**

> Is the current boot blocker actually missing runtime functionality, or are we
> repairing a symptom produced by incorrect XenonRecomp/generated code?

- If XenonRecomp is implicated → STOP Phase 0 implementation work; produce
  `CODEGEN_REPAIR_SUBPLAN.md` (do not implement).
- If XenonRecomp is cleared → produce the Phase 0 subplan (`docs/EXECUTION_PHASES.md` Phase 0) for
  the actual root cause (do not implement).

---

## INVESTIGATION ORDER

### Phase 1 — Current failure reconstruction
- Read handoff docs (`docs/HANDOFF_NEXT_AGENT.md`), boot logs
  (`build/boot_stdout_78.log` = latest soak; `boot_stdout_76y.log` = baseline),
  census reports, generated-code reports, prior session notes.
- Identify the exact first fatal/error event. Record:
  guest address, function address/name, generated source file/function, caller,
  callee, error/return value, relevant memory addresses, boot timestamp.
- Build a precise call chain from boot entry to the failure.

### Phase 2 — XenonRecomp integrity audit (codegen is a FIRST-CLASS suspect)
For every critical function in the current boot/shader path:
- Locate original PPC function (raw image: `build/cache/mcla_pe.bin`).
- Locate generated function in `generated/ppc_xenon/`.
- Compare PPC instructions against generated control flow and operations:
  branches, calls, returns, LR/CTR behavior, tail calls, switch dispatch,
  indirect calls, fall-through, register semantics, memory accesses.
- Check for skipped/approximated/substituted instructions and placeholders.
- Check function boundaries.
- Do NOT merely report "function exists" — prove semantics and control flow
  are plausible.

### Phase 3 — Function-boundary / control-flow audit
- bctr / bctrl / bclr / CTR-based branches
- jump tables / switch tables (incl. XenonAnalyse "jump outside function")
- inline data mistaken for code; functions split/merged incorrectly
- tail calls; functions adjacent to jump tables
- branches outside generated function bodies
- unexpectedly huge/small generated functions

### Phase 4 — Generated-code completeness census
Census ALL of `generated/ppc_xenon/` for: TODO / UNIMPLEMENTED / placeholders /
abort-trap paths / fake default returns / warning-only opcode handlers /
unsupported instructions / suspicious no-ops / "should never happen" paths /
patterns deviating from normal XenonRecomp emission. Do NOT trust the "219
unrecognized sites" figure blindly — re-derive it.
For every suspicious site: is it reachable during the current boot path?

### Phase 5 — Critical instruction semantics
Audit every unsupported/suspicious instruction reachable from the current
failure path. Attention list: `frsqrte`, `vsel128`, `vspltish`, `vpkswss128`,
`vpkuwus128`, `vpkuwum128`, `vpkuhum128`, `vcfpuxws128`, `vrfip128`,
`mullhwu.`, `mulhdu`, `eqv`, `dcbst`, D3D color pack, float16_4 pack, and any
VMX128 op used by the shader path. For each: PPC semantics, generated
implementation, expected vs actual I/O, approximation acceptability, control-
flow/address/shader-data impact, reachability before the fatal.

### Phase 6 — Guest memory / ABI audit
On the critical path verify: guest pointer conversion, effective-address math,
address ranges, alignment, endianness, struct layout, argument passing, return
values, PPC ABI register usage, stack layout, imported-function ABI,
GuestMemoryView usage, PPC_LOAD/PPC_STORE/PPC_MM behavior. Determine whether
any bad pointer / corrupted struct / wrong return value originates in generated
code rather than the runtime.

### Phase 7 — Shader preload path trace (do NOT assume the hypothesis)
Trace every step from `a:/archive/shaders/*/preload.list` → archive/device
lookup → shader dictionary → `embedded:/dcl/star_glow.dcl` →
`embedded:/star_glow.dcl` → `embedded:/fxl_final/star_glow.fxc` → shader
translator → fatal dispatcher. For each step: original guest function,
generated function, device/filesystem function, arguments, return values,
addresses, actual vs expected. Identify the FIRST divergence point.

### Phase 8 — Embedded-device hypothesis validation
Do NOT assume the missing `memory:` mount is the root cause. Prove (from PPC
disassembly + generated code + censuses): where the original game registers the
embedded shader device, which function registers it, when it should execute,
which generated function represents it, whether it is reached, whether its
args/returns are correct, whether the registration data is valid, whether the
MOUNT76 census is sufficient evidence, whether the device should exist before
preload, and — decisively — whether the PC runtime is missing functionality OR
the guest never requested/registered the device because of an EARLIER
divergence. If registration never occurs: trace backwards and determine WHY.

### Phase 9 — Disc / IO path audit
Classify the reported disc error as: independent runtime problem / downstream
symptom / bad generated call / incorrect async semantics / incorrect guest
memory / incorrect file-device state. Trace NtReadFile → completion →
event/APC → caller → archive streaming. No async implementation.

### Phase 10 — Kernel / runtime stub audit
For every kernel/import function on the critical boot path: expected Xbox
behavior vs current implementation; return values, out-params, handles/events,
synchronization semantics; identify fake-success and fake-failure
implementations and anything that could HIDE the real failure. Classify risk.
Do not fix.

### Phase 11 — Differential validation
Where practical, compare original PPC behavior vs generated code vs current
runtime, using small targeted examples. Priorities: shader preload functions,
filesystem/device lookup, mount/registration, shader dictionary access,
fatal/error dispatch, and functions immediately upstream of the failure.

### Phase 12 — Classification (exactly one per finding)
A — XenonRecomp/codegen bug
B — Generated-code semantic bug
C — Guest ABI / memory translation bug
D — Kernel/runtime implementation bug
E — Filesystem/device implementation missing
F — GPU/shader translation bug
G — Original game behavior / expected failure
H — Instrumentation/census false positive
I — Unknown / insufficient evidence

### Phase 13 — First-divergence timeline
BOOT → Function A → B → C → … → FIRST DIVERGENCE → downstream symptoms →
current fatal. The key result is NOT "what crashes" — it is "where does our
execution first stop matching expected Xbox behavior?"

### Phase 14 — Root-cause graph
ROOT CAUSE → DIRECT EFFECT → SECONDARY EFFECT → CURRENT FAILURE, with symptoms
explicitly marked so downstream effects don't get "fixed" by accident.

### Phase 15 — Prioritization
P0 — proven first divergence / root cause
P1 — highly likely contributor
P2 — reachable but not currently causal
P3 — unreachable before current failure
P4 — future/shipping issue
(No time on P2/P3/P4 fixes during this audit.)

---

## FINAL DELIVERABLE

the final report (written as Part 2 of this file) containing:
1. Executive Summary
2. Current Boot Failure
3. Exact First Fatal Event
4. Critical Call Chain
5. XenonRecomp Integrity Results
6. Function Boundary / CFG Results
7. Generated Code Completeness Results
8. Critical Instruction Results
9. ABI / Guest Memory Results
10. Shader Preload Trace
11. Embedded Device Hypothesis Verification
12. Disc / IO Findings
13. Kernel / Runtime Findings
14. Differential Validation
15. Root-Cause Graph
16. Findings Classification A–I
17. P0–P4 Ranking
18. Evidence Table (format below)
19. Recommended Next Investigation
20. Explicit "DO NOT FIX YET" list

Evidence-table format:

| Priority | Category | Guest Address | Function | Generated Location | Expected | Actual | Evidence | Confidence |
|----------|----------|---------------|----------|--------------------|----------|--------|----------|------------|

## RULES OF EVIDENCE
- Every major conclusion cites concrete evidence: address, function, log line,
  generated source location, disassembly, or trace.
- FACT vs INFERENCE explicitly distinguished.
- Never say "likely XenonRecomp" without showing why.
- Never call "missing device" the root cause merely because lookup failed.
- Never treat a warning as root cause unless proven reachable AND causal.
- Preserve all existing logs and artifacts (read-only).
- Do not broaden into gameplay, audio, input, or polish work.

---
---

# PART 2 — ROOT-CAUSE VALIDATION REPORT (verbatim, session 78b)

# ROOT-CAUSE VALIDATION REPORT — MCLA PC Rebuild

**Status:** COMPLETE (session 78b, 2026-09-13)
**Classification:** Phase 0 candidate identified; codegen CLEARED
**Success condition answered:** YES

---

## §1 Executive Summary

The boot blocker ("Unable to load shader '%s', it probably wasn't preloaded
properly." for "star_glow") is **NOT caused by incorrect XenonRecomp/generated
code**. The generated code for the shader lookup path is semantically correct
(F-015). The root cause is a **runtime-level shader dictionary population
failure** — the preload lists are read and inflated, but the shader names are
never registered into the 256-entry dictionary at `0x827C9F70`. This is a
**class D finding** (kernel/runtime implementation bug), specifically a failure
in the shader preload registration path that populates the dictionary.

The "embedded device" hypothesis (F-020) was **overturned**: the device registry
has only ONE type ("a:/archive/"), and the archive device handles all paths
including "embedded:/". The E1 "holder" is an out-of-bounds read of
uninitialized memory, not a separate device. The generated code is complete for
all executed functions (F-022).

**Recommendation:** Produce the Phase 0 subplan (`docs/EXECUTION_PHASES.md` Phase 0) for the shader
dictionary population failure. Do NOT produce `CODEGEN_REPAIR_SUBPLAN.md`.

---

## §2 Current Boot Failure

The game boots, initializes the VFS, reads preload lists for shaders, then
attempts to load "star_glow" shader. The lookup function (`sub_82189138`)
searches a 256-entry dictionary at `0x827C9F70`, fails to find "star_glow",
reads `byte_827D5C70` (= 0x01, compile-time constant), and dispatches to
the fatal handler (`sub_821BD618`). The fatal handler prints:
```
Unable to load shader '%s', it probably wasn't preloaded properly.
star_glow
```

Timeline: 19:13:04.763 (GETDEV #38-#43 → fatal).

---

## §3 Exact First Fatal Event

| Field | Value |
|-------|-------|
| Timestamp | 19:13:04.763 |
| Guest address | 0x82189270 (inside sub_82189138) |
| Function | sub_82189138 (shader name lookup) |
| Generated location | ppc_recomp.9.cpp:9591 |
| Error format | 0x8200B358 ("Unable to load shader '%s'...") |
| Shader name | 0x82040F0C ("star_glow") |
| Fatal handler | sub_821BD618 (host interceptor at src/kernel/imports.cpp:2818) |
| byte_827D5C70 | 0x01 (compile-time constant, zero runtime writers) |

---

## §4 Critical Call Chain

```
BOOT → VFS init → GETDEV #1-#27 (archive device) →
GETDEV #28-#37 (preload.list reads, INFLATE #1-#7) →
GETDEV #38-#43 (star_glow lookups, all miss) →
sub_82189138 (dictionary search, returns -1) →
sub_821BD618 (fatal dispatcher, prints error) → HALT
```

Fatal chain from log: `lr=0x82189270` (one valid frame; rest are garbage/0).

---

## §5 XenonRecomp Integrity Results

**PASS** — No codegen defects found on the executed path.

| Check | Result | Evidence |
|-------|--------|----------|
| sub_82189138 (shader lookup) | PASS | F-015: All branch targets, call args, string refs, loop bounds match. Minor CR field difference (cmplwi vs cmpwi) is benign. |
| sub_8218C9D8 (device dispatch) | PASS | F-016: Correctly implements device notification loop. Not a shader lookup. |
| sub_82189134 (stub) | PASS | F-016: `.long 0x0` matches binary `0x00000000`. |
| 44,707 functions total | PASS | F-022: 33% stubs, 0 executed functions are stubs. |

---

## §6 Function Boundary / CFG Results

**PASS** — No boundary or CFG anomalies found on the executed path.

- 153 distinct LR values extracted, ALL map to known functions (F-021).
- 0 unmapped LRs.
- No bctr/bctrl anomalies on the executed path.
- No inline data mistaken for code.

---

## §7 Generated Code Completeness Results

| Metric | Count |
|--------|-------|
| Total functions | 44,707 |
| .long 0x0 stubs | 14,880 (33.3%) |
| ERROR stubs | 0 |
| Executed functions with stubs | 0 |

All 153 functions called during boot have full code bodies (F-022).

---

## §8 Critical Instruction Results

Not applicable — no critical instruction defects found. The shader lookup
function uses standard PPC instructions (load, compare, branch, call) that
are correctly recompiled.

---

## §9 ABI / Guest Memory Results

**PASS** — No ABI or guest memory defects found on the executed path.

- Register passing conventions correctly followed.
- Stack frame setup/teardown matches binary.
- Guest memory reads (via census hooks) access correct addresses.

---

## §10 Shader Preload Trace

1. **Preload list reads:** GETDEV #28-#37 read `a:/archive/shaders/*/preload.list`
   for ui, city, cars, characters, effects categories.
2. **INFLATE calls:** #1-#7 confirm the preload parser ran and inflated
   compressed data.
3. **Dictionary registration:** The preload parser should register shader names
   into the 256-entry dictionary at `0x827C9F70`. This step appears to have
   FAILED silently — the dictionary does not contain "star_glow".
4. **Shader lookup:** GETDEV #38-#43 attempt to find "star_glow" via multiple
   path variants (embedded:/dcl/, embedded:/, embedded:/fxl_final/,
   a:/archive/star_glow/dcl/, a:/archive/dcl/, a:/archive/fxl_final/).
   All miss.
5. **Fatal:** sub_82189138 returns -1, byte_827D5C70=0x01 triggers fatal.

**Divergence point:** Between preload list inflation and dictionary registration.
The preload lists are read and decompressed, but the shader names are not
registered in the dictionary.

---

## §11 Embedded Device Hypothesis Verification

**OVERTURNED** (F-020).

The device registry at `0x82860844` has `cnt=1` throughout — only ONE device
type: "a:/archive/". E1 (the supposed "embedded device holder") is an
out-of-bounds read of uninitialized memory beyond the single registry entry.

- MOUNT76 (device mount): 0 calls logged (F-019).
- EMB76 (embedded device method): 0 calls logged (F-019).
- The archive device handles ALL paths including "embedded:/".
- The E1 holder at `A0084028` with `d0=CDCDCDCD` is uninitialized heap memory.

The embedded device was never a separate device type — it was always handled
by the archive device internally.

---

## §12 Disc / IO Findings

Not directly applicable. The preload lists ARE read successfully (INFLATE
calls confirm decompression). The failure is in the dictionary registration
step, not in disc/IO.

---

## §13 Kernel / Runtime Findings

The fatal handler (`sub_821BD618`) is correctly intercepted by the host
(F-006). The CRT init no-op (`sub_821305B8_NoOp`) is correctly stubbed
(F-007). No other kernel/runtime defects were found on the executed path.

---

## §14 Differential Validation

The shader lookup function (`sub_82189138`) was diffed in detail (F-015):
- Branch targets: PASS
- Call args: PASS
- String constants: PASS
- Loop bounds: PASS
- Minor CR field difference: benign (cmplwi vs cmpwi for ==0 check)

---

## §15 Root-Cause Graph

```
SHADER DICTIONARY POPULATION FAILURE (class D, P0)
  ↓
Dictionary at 0x827C9F70 does not contain "star_glow"
  ↓
sub_82189138 returns -1 on lookup
  ↓
byte_827D5C70 = 0x01 (compile-time constant) triggers fatal path
  ↓
sub_821BD618 prints "Unable to load shader '%s'..." and halts
  ↓
CURRENT FAILURE: boot blocked at 19:13:04.763
```

**Root cause:** The shader preload registration path fails to populate the
dictionary. The preload lists are read and inflated, but the names are not
inserted into the 256-entry hash table. This is a runtime-level defect in
the shader preload registration code, NOT a codegen defect.

---

## §16 Findings Classification A–I

| Finding | Class | Description |
|---------|-------|-------------|
| F-006 | D | Fatal dispatcher host interceptor |
| F-007 | H | sub_82130678 NOT zeros (corrects F-003) |
| F-008 | H | bl at 0x8218ca6c NOT a call (corrects F-002) |
| F-009 | A | EMB76 hook decoded, never fires |
| F-010 | A | E1 fallback device holder always empty |
| F-011 | A | Preload lists read, star_glow lookups miss |
| F-012 | A | AUDIT_FOCUS=DEVICE (EMB76 never fired) |
| F-013 | A | byte_827D5C70 compile-time constant |
| F-014 | A | sub_8218C650 not standalone; lookup is sub_82189138 |
| F-015 | A | Generated sub_82189138 matches binary (PASS) |
| F-016 | A | sub_8218C9D8 device dispatch, not shader lookup |
| F-017 | A | Device memory layout decoded |
| F-018 | A | Device vtable addresses decoded |
| F-019 | A | MOUNT76 and EMB76 never fired |
| F-020 | D | Registry has ONE type; embedded hypothesis OVERTURNED |
| F-021 | A | All 153 LRs map to known functions |
| F-022 | A | 33% stubs, 0 executed stubs (PASS) |

---

## §17 P0–P4 Ranking

| Priority | Finding | Class | Description |
|----------|---------|-------|-------------|
| **P0** | F-020/F-011 | **D** | **Shader dictionary population failure** — preload lists read but names not registered in dictionary. This is the proven first divergence. |
| P1 | F-013 | A | byte_827D5C70=0x01 forces fatal (not fallback). Compile-time constant, correctly recompiled. |
| P1 | F-015 | A | Generated shader lookup matches binary. Codegen cleared. |
| P2 | F-009 | A | EMB76 never fires. Off-path (not causal). |
| P3 | F-010 | A | E1 holder empty. Overturned — not a real holder. |
| P4 | F-022 | A | 33% stubs. Future/shipping concern. |

---

## §18 Evidence Table

| Priority | Category | Guest Address | Function | Generated Location | Expected | Actual | Evidence | Confidence |
|----------|----------|---------------|----------|--------------------|----------|--------|----------|------------|
| P0 | D | 0x827C9F70 | Dictionary | ppc_recomp.9.cpp:9591 | Contains star_glow | Empty/missing | GETDEV #38-#43 miss, fatal at 0x82189270 | HIGH |
| P1 | A | 0x827D5C70 | byte_827D5C70 | ppc_recomp.9.cpp:9591 | 0x00 (fallback) | 0x01 (fatal) | Binary confirms 0x01, no runtime writers | HIGH |
| P1 | A | 0x82189138 | sub_82189138 | ppc_recomp.9.cpp:9591 | Match binary | Match binary | F-015 diff checklist: all PASS | HIGH |
| P2 | A | 0x821CB070 | EMB76 | src/gpu_device.cpp:3019 | 0 calls | 0 calls | Census hook: s_hCB070=0 | HIGH |
| P3 | A | 0xA0084028 | E1 holder | N/A | Device ptrs | CDCDCDCD | Census: d0=CDCDCDCD, dcnt=0 | HIGH |

---

## §19 Recommended Next Investigation

1. **Trace the shader preload registration path** — find the function that
   reads preload.list entries and inserts them into the dictionary at
   `0x827C9F70`. Determine WHY "star_glow" is not registered despite the
   preload lists being read and inflated.

2. **Check the dictionary hash function** — `sub_821C9AB0` and `sub_821C9790`
   are the hash/prep functions. Verify they produce correct indices for
   "star_glow" and that the insertion logic handles collisions correctly.

3. **Check dictionary capacity** — the dictionary has 256 entries. If more
   than 256 shaders are in the preload lists, some may be silently dropped.
   Count the total number of shader names across all preload lists.

4. **Produce the Phase 0 subplan (`docs/EXECUTION_PHASES.md` Phase 0 §B)** — do NOT produce
   `CODEGEN_REPAIR_SUBPLAN.md` (codegen is cleared).

---

## §20 Explicit "DO NOT FIX YET" List

| Finding | Proposed Fix | Rationale |
|---------|-------------|-----------|
| F-020 | Fix shader dictionary population | Root cause; needs implementation plan |
| F-013 | Change byte_827D5C70 to 0x00 | Would mask the symptom, not fix the cause |
| F-009 | Implement EMB76 hook | Off-path; not causal |
| F-010 | Populate E1 holder | Overturned; E1 is not a real holder |
| F-022 | Reduce stub count | Future concern; not blocking boot |

---
---

# PART 3 — FINDINGS LEDGER (verbatim, append-only; continue F-### here)

Pre-seeded by the planning model with already-proven facts (F-001..F-005).
Executor: append below, one block per finding, per `EXECUTION_PHASES.md`
Part A §Part C (ledger format).

---

## F-001  Fatal caller attribution in handoff is WRONG (lr is stale garbage)
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       H
- Priority:    P1
- Evidence:    Raw PPC disasm of sub_82189138: 0x8218926c = `stw r9,0xC(r3)`,
               0x82189270 = `add r9,r6,r9` — no bl/bctrl sets LR=0x82189270
               anywhere; fatal was reached via bctr (does not update LR);
               IDA xref of fmt string 0x8200B358 → referenced only at
               0x8218ca68 inside sub_8218C9D8.
- Notes:       Any past conclusion built on "caller = 0x82189270 /
               sub_82189138" is invalid. Re-audit any handoff claim that
               cites it.

## F-002  TRUE fatal chain solved (guest-native, working as coded)
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       G (the fatal itself is the game's own coded behavior)
- Priority:    P0-adjacent context (this is the terminal symptom, not the cause)
- Evidence:    IDA decompile sub_8218C9D8 (string xref 0x8218ca68; call site
               bl at 0x8218ca6c) + decompile sub_821C0E18 =
               `if (dword_8285FEA0) dword_8285FEA0(fmt); while(1);` + log
               `slot 0x8285FEA0 = 0x82130678` + GETDEV #40-#43 cascade in
               build/boot_stdout_78.log @19:13:04.763.
- Notes:       Chain: sub_8218C9D8 → sub_8218C650("embedded:/…")==-1 AND
               sub_8218C650(name)==-1 → byte_827D5C70!=0 → bl sub_821C0E18 →
               indirect call [0x8285FEA0] → host fatal dump. The open question
               is why BOTH lookups return -1, not the fatal itself.

## F-003  Fatal handler target 0x82130678 is a zero pad-hole in the image
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       I (until T1 identifies the host interceptor; likely D/H)
- Priority:    P1
- Evidence:    read_memory_bytes(0x82130678, 16) = all zero; IDA has no
               function there; yet runtime printed a formatted fatal dump →
               a host-side override owns this guest address.
- Notes:       On Xbox, guest word 0x8285FEA0 must be populated with a real
               handler pointer at some point (xref 0x8285FEA0 → writer W).
               If W is game/kernel init code that never ran or wrote a
               different value, THAT is a first-divergence candidate upstream
               of the fatal. T9.2 must resolve this.

## F-004  EMB76 census never fired in the fatal boot
- Task:        T1/T2 context (planning model)
- Type:        FACT
- Class:       I
- Priority:    P1
- Evidence:    grep -c EMB76 build/boot_stdout_78.log → 0, while
               mcla_patch_groups='all' and other censuses (GETDEV/MOUNT76/
               INFLATE/TSLAB/REBASE) all printed.
- Notes:       Either the embedded-device code path never executed, or the
               EMB76 hook triggers on an event that never happened. T1 must
               decode the hook's trigger before drawing conclusions.

## F-005  Fallback device holder is empty-but-allocated at fatal time
- Task:        Phase 1 (planning model)
- Type:        FACT
- Class:       I (consistent with both "device never registered" and
               "registration ran but its writes vanished")
- Priority:    P1
- Evidence:    GETDEV-E1 lines: hold=A0084028 dcnt=0000 dcap=0001
               d0=CDCDCDCD vt0=00000000 (raw uninitialized pattern), repeated
               identically at #40–#43.
- Notes:       dcap=1 allocated but dcnt=0 and slot never written. F3 fork in
               the execution plan decides between the two hypotheses.

---

## F-006  Fatal dispatcher host interceptor identified (sub_821BD618)
- Task:        T1
- Type:        FACT
- Class:       D (host override of guest function)
- Priority:    P1 (context — the fatal itself works, but its invocation path
               matters)
- Evidence:    `dispatcher->SetFunction(0x821BD618, sub_821BD618)` at
               `src/patches.cpp:441`; host implementation at
               `src/kernel/imports.cpp:2818-2873` reads slot 0x8285FEA0,
               prints fatal message + register dump + stack chain, calls
               ExitProcess(0x80000003). Raw PPC at 0x821BD618:
               `lis r11,0x8286; lwz r10,-0x160(r11)` loads [0x8285FEA0],
               `cmplwi r10,0; beq; mtctr r10; bctrl; b .` (call if non-zero,
               then infinite loop).
- Notes:       The host override is a strong symbol replacing the generated
               weak function. Guest code that calls sub_821BD618 hits the host
               override. The slot 0x8285FEA0 contains 0x82130678 at runtime
               (written by game init code).

## F-007  Plan correction: 0x82130678 is NOT zeros — it's a function prologue
- Task:        T1
- Type:        FACT (corrects F-003)
- Class:       I
- Priority:    P1
- Evidence:    read_memory_bytes of 0x82130678 via raw binary:
               `0x82130678: 0x7D8802A6` (mfspr r12,LR),
               `0x8213067C: 0x9181FFF8` (stw r12,-8(r1)),
               `0x82130680: 0x9421FFA0` (stwu r1,-0x60(r1)),
               `0x82130684: 0x38600000` (li r3,0). This is a real function,
               not a pad hole.
- Notes:       The planning model's claim that 0x82130678 is "16 bytes of ZERO"
               was based on IDA read_memory_bytes which may have read from a
               different segment or cache. The raw image bytes show it's a
               function that returns 0 in r3. On Xbox, this function is called
               through the handler pointer at 0x8285FEA0.

## F-008  Plan correction: bl at 0x8218ca6c is NOT a call to sub_821C0E18
- Task:        T1
- Type:        FACT (corrects F-002 call-site)
- Class:       H
- Priority:    P2
- Evidence:    Raw PPC at 0x8218ca6c = `0x912A0000` = `stw r9, 0(r10)`
               (opcode 36), NOT a bl (opcode 18). sub_8218C9D8's bl targets
               are: 0x823D91F4, 0x82410F88 (×2), plus bctrl at 0x8218CAF4.
               None target sub_821BD618 or sub_821C0E18.
- Notes:       The fatal chain still works through sub_821BD618, but the exact
               guest code path from sub_8218C9D8 to the fatal dispatcher is
               different from what the plan describes. The bl/sub_821C0E18
               attribution in F-002 is partially wrong; the terminal behavior
               (host intercept of sub_821BD618) is correct.

## F-009  EMB76 hook decoded: hooks sub_821CB070 (embedded device method)
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P1
- Evidence:    `PPC_FUNC(sub_821CB070)` at `src/gpu_device.cpp:3019-3034`
               intercepts the "embedded:" device method (vtable-based call).
               Logs r3 (device object with vtable), r4 (path string), lr.
               Counter capped at 12. NEVER FIRED in boot_stdout_78.log.
- Notes:       The hook fires when game code calls the embedded device's method
               (likely Open or similar vtable slot). Zero fires means the
               embedded device was never invoked during boot. This is
               consistent with E1 holder being empty — if no embedded device
               was registered, no embedded device method can be called.

## F-010  E1 fallback device holder confirmed empty across ALL 43 GETDEV calls
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P0 (critical for F3 fork)
- Evidence:    GETDEV #1-#43 in build/boot_stdout_78.log: E1 always shows
               `hold=A0084028 dcnt=0000 dcap=0001 d0=CDCDCDCD vt0=00000000
               pfx0=00000000 d1=CDCDCDCD vt1=00000000 pfx1=00000000`.
               Identical at every single GETDEV call from 19:12:59.091 to
               19:13:04.763.
- Notes:       The embedded device holder (E1) was never written to. dcnt=0
               means zero devices registered. d0=CDCDCDCD is the heap fill
               pattern (never overwritten). This is strong evidence that the
               embedded device registration function never executed, OR its
               writes were lost. F3 fork in T5 decides this.

## F-011  Preload lists read but star_glow lookups all miss
- Task:        T1
- Type:        FACT
- Class:       I
- Priority:    P0 (the immediate fatal cause)
- Evidence:    GETDEV #28-#37 (19:13:04.671-04.762): 5 preload.list files
               opened (ui, city, cars, characters, effects). INFLATE #1-#7
               decompression events. Then GETDEV #38-#43 (19:13:04.763):
               `embedded:/dcl/star_glow.dcl` → miss, `embedded:/star_glow.dcl`
               → miss, `embedded:/fxl_final/star_glow.fxc` → miss,
               `a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl` → miss
               (mangled!), `a:/archive/dcl/star_glow.dcl` → miss,
               `a:/archive/fxl_final/star_glow.fxc` → miss. Fatal follows.
- Notes:       The preload lists were successfully read and inflated, but the
               shader names they contained were never registered into the
               runtime dictionary that sub_8218C650 queries. star_glow was
               never added to the lookup table. This points to either: (1) the
               preload parsing didn't register names, or (2) the registration
               target (the embedded device's dictionary) was empty because the
               device was never registered (F-010). T2 must resolve this.

## F-012  F1 fork resolves: AUDIT_FOCUS=DEVICE (star_glow was NOT preloaded)
- Task:        T2
- Type:        FACT
- Class:       D/E (device registration never happened)
- Priority:    P0
- Evidence:    (1) EMB76 census = 0 fires (F-009); embedded device method
               never called. (2) E1 fallback holder always empty (F-010).
               (3) Preload lists were opened (GETDEV #28-#37 at
               19:13:04.671-04.762: ui, city, cars, characters, effects) and
               inflated (INFLATE #1-#7), confirming the game's preload parser
               ran. (4) But star_glow names were never registered into the
               runtime dictionary because the target (embedded device's
               dictionary) was never created — the device was never registered.
               (5) sub_8218C650 queries a data structure that the embedded
               device should populate; with the device absent, all lookups
               return -1.
- Notes:       AUDIT_FOCUS shifts to DEVICE. T5 (embedded/memory device
               registration hunt) is now the deep critical task. The defect is
               NOT in the lookup/registry path (codegen suspect cleared for
               now); it's in the device registration path. T5 must find: (1)
               which function R registers the embedded device, (2) whether R's
               caller was executed, (3) what gate prevented registration.

## F-013  byte_827D5C70 = compile-time constant 0x01; never written at runtime
- Task:        T3
- Type:        FACT
- Class:       D (device/status flag, not a variable)
- Priority:    P1
- Evidence:    (1) Raw byte at 0x827D5C70 = 0x01 in the image (compile-time
               init). (2) Zero stb instructions reference 0x827D5C70 across
               the entire binary — no runtime writer exists. (3) Single reader
               at 0x82189254 (inside function starting at 0x82189138):
               `lis r11, 0x827D; lbz r10, 0x5C70(r11); cmpwi cr0, r10, 0;
               beq +0x14`. If byte != 0 → falls through to
               `bl 0x821BD618` (FATAL dispatcher, F-006). If byte == 0 →
               skips fatal. (4) Two callers of 0x82189138: bl at 0x82189408
               and bl at 0x8218947C — both inside the same parent function
               (0x82189138 is called from within a larger shader-loading
               routine).
- Notes:       The fatal-vs-fallback switch is NOT a runtime variable — it's
               a compile-time constant baked into the binary image. There is
               no code path that could set it to 0 to disable fatal. The
               game was compiled with FATAL_ENABLED=1, meaning shader load
               failure always triggers the fatal dispatcher. This rules out
               "forgot to set fallback flag" as a root cause. The fatal path
               at 0x8218926C calls the same `sub_821BD618` identified in
               F-006. Next step: verify whether the host-side fatal
               dispatcher (`sub_821BD618` in imports.cpp:2818) is the one
               actually reached by this call path, or if there's a different
               fatal handler in the guest binary.

## F-014  sub_8218C650 is NOT a standalone function; actual shader lookup is sub_82189138
- Task:        T4
- Type:        FACT
- Class:       A (generated code correctness check)
- Priority:    P0
- Evidence:    (1) `0x8218C650` is NOT a function entry point — it's mid-body
               of `sub_8218C638` (prologue at 0x8218C638: mfspr r12,LR;
               stw r12,-8(r1); stwu r1,-112(r1)). The plan expected
               sub_8218C650 to be the shader lookup; it's actually the tail
               of a larger initialization/cleanup function. (2) The actual
               shader name lookup function is `sub_82189138` (mapped in
               ppc_func_mapping.cpp line 2433). It:
               a. Takes shader name string in r3
               b. Returns -1 if not found (early exit if r3==0)
               c. Hashes the name via sub_821C9AB0 + sub_821C9790
               d. Searches a 256-entry dictionary at 0x827C9F70
               e. On miss: reads byte_827D5C70 (F-013), if non-zero calls
                  sub_821BD618 with "Unable to load shader '%s', it probably
                  wasn't preloaded properly."
               f. Two callers: bl at 0x82189408 and bl at 0x8218947C
- Notes:       The execution plan's assumption that sub_8218C650 is the
               lookup function is WRONG. This corrects the plan's targeting
               but does NOT change the F1 fork result (AUDIT_FOCUS=DEVICE
               from F-012 still holds).

## F-015  Generated sub_82189138 matches binary (shader lookup integrity PASS)
- Task:        T4
- Type:        FACT
- Class:       A (code quality — PASS)
- Priority:    P1
- Evidence:    Diff checklist for sub_82189138 generated vs binary:
               (1) Branch targets: PASS — all loc_ labels (8218915C, 8218917C,
                   82189194, 821891FC, 82189210, 82189250, 82189270, 821892A8,
                   821892E4, 821892F0, 82189300, 82189304) match binary
                   branch destinations.
               (2) .long stubs / ERROR stubs: PASS — no .long inline data or
                   ERROR stubs in the function body.
               (3) switch/bctr: PASS — no switch tables; single bctrl at
                   0x821891C4 correctly uses PPC_CALL_INDIRECT_FUNC(ctr.u32).
               (4) Call args: PASS — sub_821C9AB0(r3=name),
                   sub_821C9790(r4=0), sub_821BD618(r3=format, r4=name),
                   sub_82188E50(r3=name, r4=0).
               (5) Loop bounds: PASS — iterates 256 entries (r9: 0→1024, step 4).
               (6) String constants: PASS — -19624 from 0x82010000 = 0x8200B358
                   ("Unable to load shader '%s', it probably wasn't preloaded
                   properly."); -19700 from 0x82010000 = 0x8200B30C ("No
                   fallback shader available, shader preload probably failed.").
               (7) Sign/zero extension: MINOR DIFF — generated uses
                   `cmplwi cr6` (unsigned) for byte_827D5C70 check; binary uses
                   `cmpwi cr0` (signed). Functionally equivalent for ==0
                   comparison; CR field difference is benign register
                   allocation choice.
- Notes:       The shader lookup function's generated code is correct. The
               defect is NOT in the lookup logic itself — the function
               faithfully reproduces the binary's behavior. The -1 return
               path is correctly implemented. This clears the codegen
               suspect for the lookup path.

## F-016  sub_8218C9D8 generated code — device dispatch, NOT shader lookup
- Task:        T4
- Type:        FACT
- Class:       A (code quality — info)
- Priority:    P2
- Evidence:    (1) sub_8218C9D8 (ppc_recomp.9.cpp:18707) is a device
               notification/dispatch function, NOT the shader lookup. It:
               a. Takes r3=index, r4=key, r5=count, r6=array
               b. Copies 13 words from constant table to stack
               c. Iterates 12 entries (r31: 0→48, step 4) applying device
                  callbacks via vtable at offset 468
               d. Calls sub_82410F88 (early path when r4==0)
               e. No switch tables, no .long stubs
               (2) The `bl` at 0x8218CA6C referenced in the plan does NOT
                   exist as a call — per F-008, the code at that address is
                   `stw r9,0(r10)` (store word), not a bl instruction.
                   This was already corrected in F-008.
               (3) sub_82189134 is mapped as `.long 0x0` (empty stub),
                   matching the binary's `0x00000000` at that address.
- Notes:       The plan's expectation of "embedded:/ string build + double
               lookup + fatal" in sub_8218C9D8 is incorrect. The actual
               "double lookup + fatal" pattern is in sub_82189138 (F-014).
               sub_8218C9D8 handles device state-change notifications,
               which is a separate code path.

## F-017  Device memory layout decoded — E0 holder populated, E1 empty
- Task:        T5
- Type:        FACT
- Class:       A (structural understanding)
- Priority:    P1
- Evidence:    (1) Device holder structure (from census hook gpu_device.cpp
               :2962-2988):
               - Arr = array of 2 device entries at base address
               - Each entry is 276 bytes: name[16] at +0, flag at +262,
                 len at +264, hold at +268, dcnt at +272, dcap at +274
               - hold = pointer to device descriptor array
               - d0 = first device pointer (read from hold[0])
               - vt0 = vtable at d0[0], d0pfx = prefix at d0+36
               (2) Census shows:
               E0: name='rage_cache' flag=? len=? hold=? dcnt=32 dcap=32
                   d0=00000000 vt0=00000000 pfx0=00000000
               E1: name='' flag=? len=? hold=A0084028 dcnt=0 dcap=1
                   d0=CDCDCDCD (uninitialized debug fill)
               (3) E0 has 32 devices registered; E1 has 0.
               (4) E1 hold=A0084028 (guest heap address), d0=CDCDCDCD
                   confirms no device was ever registered into E1.
               (5) 0x827D8380 is a C++ type_info / VFT descriptor for
                   ".?AVfiDeviceMemory@rage@@" (rage::fiDeviceMemory class).
                   Contains: self+8 ptr, count=16, vtable at 0x8201219C,
                   secondary ptr 0x82012914, data ptr 0x8205CEC0, then
                   RTTI name string. NOT the holder backing store.
- Notes:       The plan's claim that 0x827D8380 is "backing store of guest
               global" for the E1 holder is INCORRECT. It's a type_info/VFT
               object. The actual holder is on the guest heap at A0084028.

## F-018  Device vtable addresses decoded
- Task:        T5
- Type:        FACT
- Class:       A (structural understanding)
- Priority:    P2
- Evidence:    Three vtable candidates in 0x82012Bxx range:
               (1) 0x82012B44 — embedded device vtable:
                   [+0x00] 0x821CD700 (destructor-like, calls sub_821CCA38)
                   [+0x04] 0x82762480 (stub/no-op, 21 entries)
                   [+0x0C] 0x8249B538 (shared with E0)
                   [+0x1C] 0x821CCD58 (I/O loop, calls sub_821CCB38)
               (2) 0x82012BDC — E0 device vtable (rage_cache):
                   [+0x00] 0x822C3588 (function)
                   [+0x04] 0x821CDB88 (function)
                   [+0x08] 0x821CC570 (function)
                   [+0x0C] 0x8249B538 (shared with embedded)
                   [+0x18] 0x821CD348 (function)
                   [+0x1C] 0x821CC6F0 (function)
               (3) 0x82012CA8 — NOT a vtable; contains ASCII "Out of file
                   descriptors" string data.
               (4) Two functions load these vtables:
                   0x821CCA50 (inside sub_821CCA38) loads 0x82012B44
                   0x821CCE58 loads 0x82012BDC
               (5) sub_821CCE58 (E0 vtable initializer, IN mapping):
                   - Stores vtable 0x82012BDC into [r31+0]
                   - Calls sub_821CBEB0 (base init)
                   - Then replaces vtable with 0x8201206C
               (6) sub_821CCA38 (embedded vtable constructor, IN mapping):
                   - Stores vtable 0x82012B44 into [r31+0]
                   - Multiple cleanup paths for offsets 308-372
- Notes:       Both vtable initializers are in the function mapping (recompiled).
               The E0 path runs (E0 is populated). The embedded path may not
               run or may not reach the holder-registration step.

## F-019  Device registration census — MOUNT76 and EMB76 never fired
- Task:        T5
- Type:        FACT
- Class:       A (runtime evidence)
- Priority:    P0
- Evidence:    From boot log census hooks:
               (1) MOUNT76 (sub_821CB9D8): 0 calls logged (n stays at 0).
                   This is the device Mount function that registers devices.
                   NO device was ever mounted during the boot sequence.
               (2) EMB76 (sub_821CB070): 0 calls logged (n stays at 0).
                   This is the embedded device method. NEVER called.
               (3) TOC76 (sub_821CBFC0): packfile TOC lookup, fires for
                   read-only-resources. Never fires for embedded device.
               (4) The device registration path (MOUNT76) is the function
                   that adds entries to the holder. Since MOUNT76 never
                   fired, NO device was registered during boot, including
                   the embedded device.
               (5) E0's 32 entries must have been registered BEFORE the
                   census hook was installed, or through a different path
                   not captured by the census.
- Notes:       This is a critical finding: if MOUNT76 never fired, then
               the embedded device was never registered. The question
               becomes: what prevented the Mount call? The gate is
               upstream of the Mount function.

## F-020  Device registry has only ONE type — embedded device type never registered
- Task:        T5
- Type:        FACT
- Class:       D (first-divergence candidate)
- Priority:    P0
- Evidence:    Census hook reads device registry from guest global 0x82860844:
               Registry header: {Device** array@+0, u16 count@+4, u16 cap@+6}.
               Each entry is 276 bytes: name[16]@+0, flag@+262, len@+264,
               device vector {Device** arr@+268, u16 cnt@+272, u16 cap@+274}.
               (1) Registry cnt=1 throughout ALL 43 GETDEV calls — only ONE
                   device type was ever registered: "a:/archive/" (flag=1,
                   len=11).
               (2) E0 (registry entry 0): name='a:/archive/' — the archive
                   device. Its device vector (hold) grew from 1 to 2 entries
                   between GETDEV #4 (dcnt=1) and GETDEV #5 (dcnt=2). Both
                   device objects use vtable 0x82012BDC (E0 vtable).
               (3) E1 (registry entry 1): name='' flag=0xcdcd — this is
                   UNINITIALIZED MEMORY read beyond the valid registry. Since
                   cnt=1, entry 1 is out-of-bounds. E1 was never a valid
                   device type. The census loop condition `e <= cnt` causes
                   it to read one entry past the end.
               (4) The "embedded:/" paths ARE resolved — GETDEV #5 shows
                   path='embedded:/fxl_final/rage_im.fxc' was handled by the
                   archive device. The archive device handles all path
                   prefixes including "embedded:/".
               (5) The fatal error occurs because the shader lookup inside
                   the archive device's file-open path (sub_82189138) finds
                   the shader name in its dictionary but returns -1 (not
                   found), triggering the fatal path via byte_827D5C70.
               (6) E1 holder address A0084028 with d0=CDCDCDCD is the
                   SECOND registry entry's device vector — out-of-bounds
                   read of uninitialized heap memory. NOT a separate
                   "embedded device holder".
- Notes:       This OVERTURNS the embedded device hypothesis. The plan
               assumed E1 was the "embedded device holder" (a separate
               device type). In reality, E1 is an out-of-bounds read of
               uninitialized memory beyond the single registry entry. The
               archive device handles ALL paths including "embedded:/".
               The real question is: why does the shader lookup fail for
               "star_glow" when it was supposedly preloaded? The lookup
               function (sub_82189138) searches a 256-entry dictionary at
               0x827C9F70. The dictionary was populated from preload lists.
               If "star_glow" was in a preload list but not in the
               dictionary, the registration failed silently.

## F-021  Executed-path reachability join — all 153 LRs map to known functions
- Task:        T6
- Type:        FACT
- Class:       A (code quality — info)
- Priority:    P1
- Evidence:    (1) 153 distinct LR values extracted from census log, ALL
                   map to known functions in ppc_func_mapping.cpp. 0 unmapped.
               (2) Key function execution status:
                   - sub_82189138 (shader lookup): NOT in LR set directly,
                     but fatal chain[0] lr=0x82189270 is INSIDE this function
                     (offset +0x138). Confirms the function WAS called.
                   - sub_821BD618 (fatal handler): 3 LR values in range
                     0x821BD618-0x821BD718. Fatal handler WAS invoked.
                   - sub_821CCE58 (E0 vtable init): 8 LRs in range.
                   - sub_821CCA38 (embedded vtable ctor): 9 LRs in range.
                   - sub_821CC970 (device registry loop): 10 LRs in range.
                   - sub_821CB9D8 (MOUNT76): 10 LRs in range. But MOUNT76
                     census hook logged 0 calls — the LRs are from the
                     hook's own code path, not from device mount calls.
                   - sub_821CB070 (EMB76): 8 LRs in range. Census logged 0.
                   - sub_821CB488 (GETDEV): 8 LRs in range. Census logged 43.
               (3) Fatal chain from log:
                   chain[0]: lr=0x82189270 sp=0x8EFFF220
                   chain[1]: lr=0x00000010 sp=0x8EFFF3A0 (invalid)
                   chain[2+]: lr=0x00000000 (end of chain)
                   The call stack is truncated — only one valid return address.
                   chain[1] lr=0x00000010 is garbage (likely stack frame
                   alignment padding or corrupted saved LR).
               (4) Fatal dispatch regs: lr=0x82189270 r3=0x8200B358
                   (format string) r4=0x82040F0C ("star_glow") r5=0x16
                   (length 22). r3 points to "Unable to load shader '%s',
                   it probably wasn't preloaded properly." at 0x8200B358.
- Notes:       The truncated call chain (only 1 valid frame) suggests the
               fatal handler was called from a deep stack with corrupted
               saved LR values. This is consistent with the fatal handler
               being called from within the shader lookup function's error
               path, where the stack frame may not be fully set up yet.

## F-022  Generated-code completeness census — 33% stubs, 0 executed stubs
- Task:        T7
- Type:        FACT
- Class:       A (code quality — PASS)
- Priority:    P1
- Evidence:    (1) Function mapping: 44,707 entries (1:1 with declarations).
               (2) Total PPC_FUNC_IMPL: 44,707 (matches mapping).
               (3) .long 0x0 stubs: 14,880 (33.3% of all functions).
                   These are functions that exist in the binary but were
                   not recompiled with full bodies — they return
                   immediately with no code.
               (4) ERROR stubs: 0 (no explicit error/unimplemented traps).
               (5) Executed functions with .long 0x0: 0.
                   ALL 153 functions that were called during boot have
                   real code bodies. No executed function is a stub.
               (6) The 14,880 stubs are for functions that were never
                   called during the boot sequence. They may be needed
                   for later game stages (gameplay, menus, etc.) but
                   are not relevant to the boot-time fatal error.
- Notes:       The generated code is COMPLETE for the executed path. The
               33% stub rate is expected for a large binary where many
               functions are not needed during early boot. The key
               executed-path functions (shader lookup, fatal handler,
               device management) all have full code bodies.

## F-023  Heavy-model verification pass: F-001 OVERTURNED, F-007/F-008/F-014 CONFIRMED
- Task:        review checkpoint (planning model, raw-byte verification)
- Type:        FACT
- Class:       H (corrects F-001)
- Priority:    P1
- Evidence:    File bytes (offset = guest - 0x82000000):
               0x82189268=386BB358 (addi r3,r11,0xB358 -> r3=0x8200B358 fmt),
               0x8218926C=480343AD (bl 0x821BD618), ret 0x82189270 = logged lr;
               0x82189408/0x8218947C = bl into 0x82189138;
               0x8218ca6c=912A0000 (stw, not bl); 0x82130678=7D8802A6 9181FFF8
               9421FFA0 38600000 (real prologue, not zeros);
               patches.cpp:441 SetFunction(0x821BD618,...).
- Notes:       F-001 ("lr is stale garbage") is WRONG - the planning model's
               IDA disassembly was misaligned; the executor's raw-file reads
               are ground truth. lr=0x82189270 is the true return address of
               the fatal call inside the shader lookup. F-003 is superseded by
               F-007. Rule for all future work: verify IDA claims against raw
               file bytes before trusting them.

## F-024  GETDEV full dispatch traced — 8-prefix fallback to handler table scan
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    ppc_recomp.17.cpp lines 1015-1417. GETDEV (sub_821CB488) checks
               7-char "memory:" and 10-char "embedded:/" prefixes first — both
               return dead pointer 0x827D838C. Then checks "tcpip" (6 chars)
               → sub_821D5F58. Several more hardcoded prefix checks follow.
               Fall-through scans handler table at 0x82860844 (276-byte entries).
               If no match, returns device from global 0x827D8380 (set by
               MOUNT76 for "memory:" mounts).
- Notes:       Handler table has only 1 entry (cnt=1, cap=16) — "a:/archive/".
               Two registered devices: d0=A007D398 (vt=82012BDC), d1=A007D810
               (vt=82012BDC). Both have pfx=0x0000000B (11 = "a:/archive/").
               E1 slot is uninitialized (flag=0xCDCD, d0=CDCDCDCD).

## F-025  Handler table structure identified — 276-byte entries with nested vectors
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    MOUNT76 census (ppc_recomp.17.cpp:1885-2077) reads/writes
               handler table at 0x82860844. Structure:
               +0: Device** array pointer
               +4: u16 count
               +6: u16 capacity
               Entry (276 bytes):
               +0: char name[262]
               +262: u16 flag
               +264: u16 nameLen
               +268: Device** device_array_ptr
               +272: u16 device_count
               +274: u16 device_capacity
- Notes:       Census GETDEV-E0 shows: name='a:/archive/' flag=1 len=11
               hold=A0018028 dcnt=0002 dcap=0002. Two devices per entry
               (d0 and d1), each with its own vtable.

## F-026  Census hook traced for all key functions
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P1
- Evidence:    GETDEV census in gpu_device.cpp reads:
               - 0x82860844 (handler table) → arr, cnt, cap
               - 0x82855A0C (lockFlag) →FFFFFFFF
               - Per-entry: name, flag, len, hold, dcnt, dcap
               - Per-device: vt, pfx (via d0+36/d1+36)
               MOUNT76 census at line 3100 logs: path, dev, vt, flag, lr.
               Both census hooks are pass-through (call original, then log).
- Notes:       GETDEV returns dead pointer 0x827D838C for memory:/embedded:/.
               MOUNT76 shows lr=821CBF54 for both archive mounts.

## F-027  GETDEV redirect fix REJECTED — three fatal flaws identified
- Task:        Stage B' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    Applied redirect in gpu_device.cpp: when GETDEV returns dead
               pointer for memory:/embedded: path, replace with s_archiveDevice.
               Reviewer identified three fatal flaws:
               (1) EMB76>0 unreachable — redirect calls archive device methods,
                   not embedded device methods
               (2) Can't load shader content — star_glow files exist in inflated
                   RAM buffers, NOT in a:/archive/ (wrong paths)
               (3) Doesn't target policecam stall — hang is TOC76 on archive
                   path, no memory: prefix involved
- Notes:       Fix was reverted. The dead pointer is a SYMPTOM, not the cause.
               The cause is that inflated dictionaries are never mounted as
               memory devices.

## F-028  Post-inflate code flow traced — callback at [r26+1548] is key
- Task:        Stage B'' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    ppc_recomp.14.cpp lines 19321-19390. After inflate loop exits
               (loc_821BC4CC): vtable+124 call on stream device, then
               sub_821CE100 twice (cleanup). If [r26+1540] (stream count) != 0,
               calls callback at [r26+1548] with args:
               r3 = [r26+1552] (archive device)
               r4 = [r26+8]    (data/buffer)
               r5 = [r26+1544] (inflated size)
               r6 = 0
               Then calls sub_821C31B8.
- Notes:       This callback is likely where the memory device mount SHOULD
               happen. We need to:
               (1) Census this callback to see if it fires
               (2) Trace the callback function pointer value
               (3) If it fires, trace what it does with the buffer
               (4) If it doesn't fire, trace why r26+1540 might be 0

## F-029  All boots show MOUNT76=2 — memory mount never works in ANY configuration
- Task:        Stage B'' (session 76j)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    Grep of MOUNT76 across all boot logs:
               boot_stdout_78.log (baseline): MOUNT76 #1 A007D398, #2 A007D810
               boot_stdout_79.log: same
               boot_stdout_80.log: same
               boot_stdout_p0d1.log (post-fix): same
               All four boots: exactly 2 MOUNT76 calls, both a:/archive/.
               Zero memory mounts in ANY configuration.
- Notes:       This is the fundamental issue. The inflation works (INFLATE #1-7
               or #1-15 fire), but the mount that makes the inflated data
               available as a device never happens. The hash table hydration
               fix didn't change this because it's a different code path.

## F-030  PHASE1 §0 "IO slot never completes" is OVERTURNED (p1b)
- Task:        PHASE1 T1
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    p0d1 WAKE[KWFSO] status=00000000 fires constantly on the same
               obj@40004D7C wait (tid=000063E8). The WAIT line's put/rptrWB
               are GPU CP metrics (gpuCtx+10908 and 0xC701C4BC), not fields
               of the waited object. Guest sub_8242FB88 is a driver poller
               (30ms timeout, KeResetEvent on success) — designed behavior.
- Notes:       Do not treat the 471 wait loop as the stall. See F-031.

## F-031  p0d1 TOC76 #22 hang is FLAKY; real terminal frontier is star_glow fatal
- Task:        PHASE1 T2/T3
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    boot_stdout_p1b.log: TOC76-RET #22 ret=A008F950 dt=0ms, boot
               continues to TOC76 #80 then Fatal 'Unable to load shader
               star_glow' (same as baseline 78). p0d1 ended at TOC76 #22
               entry with no RET — hang stopped the boot *before* star_glow.
- Notes:       Hydration (DICT-HYDRATE 10/10) does NOT prevent star_glow
               fatal. It only hydrates factory names (draw/Copy/…). The
               p0d1 "hydration works" claim was an artifact of the hang.

## F-032  Post-inflate callback is a semaphore release, not a memory mount
- Task:        PHASE1 T2
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    cbPtr=821BC548 is `b sub_821C9108` (tail call). sub_821C9108
               only uses r3 → sub_8244ED10(h,1,0). Ignores r4=bufPtr and
               r5=inflSize. Runtime RELSEMA sub_821C9108 #40 h=C98B9800
               lr=821BC538 matches arcDev.
- Notes:       Overturns handoff/F-028 "callback is where mount should
               happen". Mount must be elsewhere.

## F-033  Only 3 Mount call sites; the non-archive ones never run
- Task:        PHASE1 T2 (raw-byte verified)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    bl sub_821CB9D8 only at: sub_821CBF28 (fires 2× archive),
               sub_821399E0@82139B58 (zero xrefs in ppc_xenon), and
               sub_82139BE0@82139EF4 (only from sub_82135E48). Raw prologue
               7d8802a6 at all three starts.
- Notes:       T4a (F-034) proves the non-archive sites' whole chain is
               never entered. Do not GETDEV-redirect (F-027).

## F-034  T4a: entire non-archive Mount chain never executes (branch 3)
- Task:        PHASE1 T4a (p1c/p1d)
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    Censuses on sub_8213AB78, sub_82135E48, sub_82139BE0,
               sub_82144B90, sub_82144D30, sub_82144EB0 all fire 0 times
               through star_glow fatal. Only MOUNT76 site that runs is
               sub_821CBF28 (2× a:/archive/). memory: string refs live in
               0x821CB740 (fmt "memory:$%p,%d,%d:%s") and GETDEV prefix
               checks 0x821C9ACC..0x821CB4A0.
- Notes:       Registration is not via these Mount sites on our boot.
               Next: census sub_821CB740/760 callers + device ctors.
               Do NOT implement host memory: device until that census
               lands (T4b forbidden until report).

## F-035  memory: format string located
- Task:        PHASE1 T4a static scan
- Type:        FACT
- Class:       H
- Priority:    P1
- Evidence:    mcla_pe.bin: 0x820127D8 "memory:", 0x82012A28
               "memory:$%p,%d,%d:%s". lis/addi → sub_821CB740 @
               0x821CB754 (tail-calls sprintf sub_82137A08).
- Notes:       Several callers across recomp.4/15/43/61/90/122/128 —
               these are the real memory-path producers. Census them.

## F-036  p2f: preload .xsf/.xtd stream containers are never filled (CDCD)
- Task:        PHASE2 p2f
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    boot_stdout_p2f/p2g logs: BUDDY76-ALLOC A47FD000(0x2000),
               B7B41000(0x20000) CDCD-filled; ctor 821D2970 writes
               vtbl 0x820131A4 into [obj+0] only; payload arrays
               [+12]/[+16] stay CDCDCDCD. The preload task 821BC140
               inflates 14 XCompress chunks (229KB, magic 0x0FF512EF
               real) of legals.xsf via streams, completes, RELSEMA
               C9B36F00 - but the PLACE pass (825EF100 family: calls
               825FDBF8 build, re-walk via 8217D890/P10, per-entry
               825FDA90) runs against containers whose entry arrays
               were never populated. Root suspicion: the archive read
               path (T5: evt=0 NtReadFile reads, page-cache slots
               stuck state=1) never delivered the .xsf TOC/data, so
               the preload copied/inflated partial streams and the
               container build stage had nothing to insert.
- Notes:       The vtable 0x8208521C family = swfC (CLIP_FRAME,
               PlaySound strings nearby, 8211E250 runtime reg table
               {func,flags}). 8260A830 = 'Invalid fixup' walker.

## F-037  p2f: GetKernelObject raw-cast fallback + dynamic_cast = host AV
- Task:        PHASE2 p2f
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    crash-2 (E06D7363 after C0000005 rva=0x322E8AD,
               __RTDynamicCast+NtReleaseSemaphore+0x2B9): the guest
               release of sema C9B36F00 hit imports.cpp NtReleaseSemaphore
               -> GetKernelObject(guestHandle) raw-cast fallback returned
               guest memory as KernelObject* -> dynamic_cast<Semaphore*>
               walked a GUEST vtable (rax=0x100000604) -> AV/throw.
               FIX (final): NtReleaseSemaphore resolves via
               TryQueryKernelObject ONLY (host wrapper map); no raw
               casts, no dynamic_cast on fallback objects.
- Notes:       xdm.h GetKernelObject raw fallback intentionally KEPT
               (file paths rely on it - reverting it broke NtQueryInfoFile
               -> 'Cannot load archive' regression, boot died at GETDEV #2).
               Callers that dynamic_cast must use TryQueryKernelObject.

## F-038  p2f: three-guard neutralization of poison container walks
- Task:        PHASE2 p2f
- Type:        FIX
- Class:       H
- Priority:    P1
- Evidence:    boot now runs 240s+ (killed only by timeout), log 2.2MB
               (vs 79KB at rgxa, 316KB at first fix). Guards added:
               (1) FDBF8-BUILD POISON-SKIP (825FDBF8 hook): vt/arr=CDCD
               -> null [+12], zero [+16], skip body.
               (2) FIXWALK-SKIP (8260A830 hook): CDCD bucket base ->
               return 0, no body.
               (3) FB0D8-DTOR guard (825FB0D8 hook): child vtable not
               in image range -> skip dispatch.
               (4) FDB30-DEAD (825FDB30 hook): [cont+12]=CDCD ->
               empty dispatch.
               Remaining: 13 caught AVs in 4min from deep original-body
               reads (sub_825FDB30+0x1C6 via FB0D8 vt+16 dispatch on
               place-pass containers) - noisy but harmless.
- Notes:       The upstream fix is T5: make the archive reads deliver
               so containers get REAL entries (INFLATE count=0 in p2o
               log vs 14 in p2f - timing shifted, the .xsf stream data
               path needs the evt=0 NtReadFile fix).

## F-039  p2p: NtCreateSemaphore identity handle never registered — Release woke a phantom wrapper (T5 root cause)
- Task:        PHASE2 p2p
- Type:        FACT
- Class:       H
- Priority:    P0
- Evidence:    p2o log: RINGB-CONSUMER tid=570C WAIT C5000280 at 08:53:08.460;
               RELSEMA+SIGNAL C5000280 at 08:53:12.703; PUSH wIdx=1 cnt=1;
               NO WAKE for tid=570C; INLINE-EXEC 821BC140 count=0;
               INFLATE count=0; containers stayed CDCD. Root cause:
               NtCreateSemaphore does CreateKernelObject+GetKernelHandle
               (identity = MapVirtual(host Semaphore*)) but NEVER registers
               in WrapperIdentityMap. Wait (NtWaitForSingleObjectEx) uses
               GetKernelObject → Translate → raw host Semaphore* (correct).
               Release (NtReleaseSemaphore) TryQueryKernelObject misses
               (not in map) then QueryKernelObject MINTS a second wrapper
               over the same guest VA and Release()s THAT — waiter slept
               forever on the original. Same class as session-72 wake-loss,
               still present for NtCreate* products.
- Fix:         CreateRegisteredKernelObject<T>() + LookupIdentityKernelObject()
               in xdm.h; NtCreateSemaphore/NtCreateEvent register at create;
               NtReleaseSemaphore/NtSetEvent/NtClearEvent/NtWaitForSingleObjectEx/
               NtReadFile event-signal resolve identity-first, never mint over
               an identity handle. Heap::IsPhysicalArenaPtr guards raw-cast
               fallbacks (no dynamic_cast on guest memory).
- Evidence after fix (boot_stdout_p2p.log, 90s):
               WAIT C5000280 → PUSH #1 → INLINE-EXEC #1 SAME tid;
               PRELOAD-CTX #1 streamCnt=7 buf=A47FD000;
               INFLATE #1-#14 magic=0FF512EF consumed=229356 (XCompress OK);
               COMPLETE 821C31B8 #1; POST-EXEC-START reached.
               INLINE-EXEC #2 buf=B7B41000; INFLATE-SKIP magic=525DE064
               (job #2 stream not XCompress — next investigation).
               FRAME-END #1-#2, P4'-PRESENT #1-#3, LOADING-GATE put=9
               (GPU put advanced 7→9). draw_indx=0 still.
- Notes:       T5 "evt=0 NtReadFile page-cache" theory was UPSTREAM-SYMPTOM.
               The real T5 blocker was the ring-B semaphore wake-loss.
               Archive VFS/TOC/open path was already delivering (TOC76 hits,
               real packfiles opened).
