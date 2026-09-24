# ROOT-CAUSE VALIDATION — MCLA PC Rebuild (method + report + findings ledger)

> **Compressed 2026-09-20.** Part 1 = the audit method. Part 2 = the report as written at audit
> close (session 78b), with a short "what later superseded it" note. Part 3 = the **append-only
> evidence ledger F-001…F-054**, entries compacted to claim + evidence (F-numbers, titles,
> classes and priorities preserved; nothing was dropped, only de-verbed).
> Pre-compression text: `git show 8f07a39:docs/ROOT_CAUSE_VALIDATION.md`.
> Live queue: `docs/LONG_TODO_MASTER.md`; current frontier: top of `HANDOFF_NEXT_AGENT.md`.
> Former names merged here: `ROOT_CAUSE_VALIDATION_PLAN.md` (Part 1),
> `..._REPORT.md` (Part 2), `..._FINDINGS.md` (Part 3).

---

# PART 1 — THE AUDIT METHOD

**Objective.** Determine the **FIRST REAL DIVERGENCE** between the original Xbox 360 execution
path and the PC/recompiled path, and answer one question with evidence:

> Is the boot blocker actually missing runtime functionality, or are we repairing a symptom
> produced by incorrect XenonRecomp/generated code?

**Hard rule (audit mode).** No code changes anywhere (`src/`, `generated/`, `config/`,
`CMakeLists.txt`, `.research/`); no symptom fixes; regeneration for comparison goes to an
isolated scratch dir. Success outcomes: XenonRecomp implicated → stop implementation and write a
codegen-repair subplan; XenonRecomp cleared → write the implementation subplan for the real root
cause.

**Investigation order (the phases that produced the ledger):**

| Phase | What it does |
|---|---|
| 1 | Reconstruct the current failure: read handoff + logs, name the exact first fatal (address, function, caller, args, memory, timestamp), build the call chain |
| 2 | XenonRecomp integrity audit: raw image vs generated code for every critical function on the path (branches, calls, returns, LR/CTR) |
| 3 | Function-boundary / control-flow audit: `bctr`/`bctrl`/`bclr`, jump tables, inline data treated as code, split/merged functions |
| 4 | Generated-code completeness census: TODO / UNIMPLEMENTED / placeholders / trap paths / fake default returns / unknown opcodes |
| 5 | Critical instruction semantics (reachable `frsqrte`, `vsel128`, VMX128 pack/unpack family, …) |
| 6 | Guest memory / ABI audit: pointer conversion, EA math, ranges, alignment, endianness, struct layout, arg passing, stack layout, import ABI |
| 7 | Shader preload path trace: `preload.list` → archive/device lookup → dictionary → `embedded:/…` → shader |
| 8 | Embedded-device hypothesis validation (prove or kill the "missing `memory:` mount" theory) |
| 9 | Disc/IO path audit: `NtReadFile` → completion → event/APC → caller → archive streaming |
| 10 | Kernel/runtime stub audit: expected Xbox behavior vs ours, per import on the critical path |
| 11 | Differential validation: original PPC vs generated vs runtime on small targeted examples |
| 12 | Classification: exactly one A–I class per finding |
| 13 | First-divergence timeline: BOOT → … → FIRST DIVERGENCE → downstream symptoms → current fatal |
| 14 | Root-cause graph: ROOT CAUSE → direct effect → secondary effect → current failure (symptoms marked) |
| 15 | Prioritization P0–P4 (no time on P2–P4 fixes during the audit) |

**Classification:** **A** codegen bug · **B** generated-code semantic bug · **C** guest ABI /
memory translation bug · **D** kernel/runtime implementation bug · **E** filesystem/device
missing · **F** GPU/shader translation bug · **G** original game behavior / expected failure ·
**H** instrumentation false positive · **I** unknown/insufficient evidence.

**Priorities:** **P0** proven first divergence / root cause · **P1** highly likely contributor ·
**P2** reachable but not currently causal · **P3** unreachable before the current failure ·
**P4** future/shipping issue.

**Deliverable (Part 2).** 20 sections: executive summary · current boot failure · exact first
fatal event · critical call chain · XenonRecomp integrity · function-boundary/CFG · generated-code
completeness · critical instructions · ABI/guest memory · shader preload trace · embedded-device
verification · disc/IO · kernel/runtime · differential validation · root-cause graph ·
findings classification · P0–P4 ranking · evidence table · recommended next investigation ·
explicit "DO NOT FIX YET" list.

---

# PART 2 — AUDIT REPORT (session 78b close; section-by-section result)

> Written at audit close. **Later superseded in three places** (marked ⚠ below): the dictionary
> *address* was corrected (F-024), the dictionary bug was actually the un-hydrated hash table
> (Phase 0 fix), and the "embedded device never registered" conclusion was extended by the Mount
> chain trace (F-033/F-034). Part 3 holds the current evidence.

**§1 Executive summary.** The boot stall is **not** a codegen defect. Generated code on the
executed path matches the binary; the first real divergence is a **missing device/dictionary
registration** in the runtime: preload lists are read and inflated, but shader names never reach
the dictionary, so the lookup falls through to the fatal. Class **D** (kernel/runtime
implementation) at **P0**.

**§2 Current boot failure.** Clean guest fatal (exit 3) ~5 s in, at the shader preload step:
`'Unable to load shader 'star_glow', it probably wasn't preloaded properly.'`

**§3 Exact first fatal event.** `build/boot_stdout_78.log` @19:13:04.763: GETDEV #40–#43 all
miss (`embedded:/fxl_final/star_glow.fxc`, then three mangled archive paths), fatal dispatcher
`sub_821BD618` → slot `0x8285FEA0` = `0x82130678`, `lr=0x82189270` (later proven real — F-023),
message + aux `star_glow`.

**§4 Critical call chain.** `sub_8218C9D8` (load-by-name wrapper) → device dispatch → GETDEV
`sub_821CB488` → vtable+4 `sub_821CAFB8` (accepts only `memory:`) → INSERT `sub_821BDF20` →
lookup `sub_82189138` → −1 → fatal. (See `EXECUTION_PHASES.md` Part A §A2.)

**§5 XenonRecomp integrity results — PASS.** 153 distinct LR values extracted from the fatal
soak; **all** map to known functions, 0 unmapped (F-021). Spot-checked functions
(`sub_82189138`, `sub_8218C9D8`, `sub_823DE150`, string/strstr helpers, inflate wrapper) match
the raw image (F-015, F-016).

**§6 Function-boundary / CFG results — PASS** on the executed path (F-014 corrected an earlier
mis-identification: `sub_8218C650` is not a standalone function; the shader lookup is
`sub_82189138`).

**§7 Generated-code completeness.** 44,707 functions; ~33 % carry a stub marker; **0 executed
stubs** on the fatal path (F-022). The systemic jump-table gap (1557 sites / 873 targets) was
found later (session 76y) and fixed in session 77 — see `HANDOFF_NEXT_AGENT.md` ledger.

**§8 Critical instruction results.** Not applicable — no critical instruction defect found; the
shader lookup uses ordinary load/compare/branch/call code.

**§9 ABI / guest memory results — PASS.** Register conventions, stack frames and effective-address
math on the executed path all match the binary.

**§10 Shader preload trace.** GETDEV #28–#37 read
`a:/archive/shaders/{ui,city,cars,characters,effects}/preload.list`; INFLATE #1–#7 confirm the
parser ran and decompressed the 512 KB dict bodies; the names then never register.

**§11 Embedded-device hypothesis — ⚠ OVERTURNED as stated (F-020).** The device registry at
`0x82860844` had `count=1` throughout — only the `a:/archive/` type; the "E1 embedded holder" is
empty-but-allocated. (Later: F-034 proved the whole non-archive Mount chain never executes, so
the device is never even created.)

**§12 Disc/IO findings.** Not causal at audit time: preload lists ARE read and inflated; the
failure is the dictionary registration step.

**§13 Kernel/runtime findings.** Fatal handler correctly intercepted by the host (F-006); CRT
no-op `sub_821305B8` correctly stubbed (F-007); no other defect on the executed path. Class **D**
risk items are the device registration (F-020) and the dictionary hash table (⚠ F-024 corrected
the address; Phase 0 landed the hydration fix).

**§14 Differential validation.** `sub_82189138` diffed in detail: branch targets PASS, call args
PASS, LR/CTR behavior PASS (F-015).

**§15 Root-cause graph.**

```
SHADER DICTIONARY POPULATION FAILURE            (class D, P0)  [⚠ resolved by Phase 0]
  -> names never registered in the hash table
     -> sub_82189138 lookup returns -1
        -> sub_8218C9D8 shader load fails
           -> fatal dispatcher 'Unable to load shader star_glow'
DEVICE REGISTRATION NEVER HAPPENS               (class D/E, P1)
  -> memory:/embedded: Mount chain never executes (F-033/F-034)
     -> embedded:/ paths resolve to nothing
        -> same lookup failure, later in boot
```

**§16 Classification of findings** (full ledger in Part 3): **D** — F-006 (fatal interceptor),
F-012/F-013/F-020 (device/flag/dictionary runtime gaps); **A** — F-014…F-022 (codegen checks,
all pass); **H** — F-001/F-008/F-023 (instrumentation artifacts and their corrections);
**I** — F-003/F-004/F-005 in their pre-correction form.

**§17 P0–P4 ranking (at close).** **P0** F-020/F-011 — shader dictionary population failure
(proven first divergence, D). **P1** F-012 — device registration never happened (D/E).
**P2** F-011/F-019 — preload lookups miss; MOUNT76/EMB76 never fire (evidence). **P3** later
ledger entries (F-036+). **P4** nothing shipped-blocking.

**§18 Evidence table (key rows).** P0/D — `0x827C9F70`⚠ dictionary (`ppc_recomp.9.cpp:9591`):
expected star_glow present, actual empty; evidence GETDEV #38–#43 + fatal @0x82189270. P1/D —
`0x82860844` device registry: expected embedded type registered, actual count=1; evidence
MOUNT76=2 in all boots. P1/H — `0x8285FEA0` fatal slot: expected host interceptor, actual
`0x82130678` (real fn); evidence F-006/F-007.

**§19 Recommended next investigation (as written).** Trace the shader preload registration path
end-to-end; determine why names never register despite the lists being read. → Executed as
Phase 0 (hash-table hydration) and Phases 1/2 (Mount chain, executor fetch).

**§20 "DO NOT FIX YET" list.** Dictionary population via patching the fatal or the switch
(masks the root cause; `byte_827D5C70` is F-013 and has zero runtime writers); F-027
GETDEV-redirect to the archive (rejected: unreachable EMB76, wrong device semantics, hides the
missing registration); any "zero the field at the use-site" fix for CDCDCDCD; stubbing the fatal
dispatcher.

---

# PART 3 — FINDINGS LEDGER (F-001 … F-043; append-only from here)

> **Compact format:** `F-### — title` then `type · class · priority` and the claim + evidence.
> Compressed 2026-09-20 (entries de-verbed; F-numbers, titles, classes, priorities and all
> addresses/evidence preserved). **Append new findings below F-043 — never rewrite old ones.**
> Full pre-compression text: `git show 8f07a39:docs/ROOT_CAUSE_VALIDATION.md`.

**F-001 — Fatal caller attribution in the handoff is WRONG (lr is stale garbage).** FACT · H · P1
· *corrected by F-023.* Claim was: raw PPC in `sub_82189138` shows `0x8218926c` = `stw r9,0xC(r3)`,
`0x82189270` = `add r9,r6,r9`, no `bl`/`bctrl` sets that LR (fatal reached via `bctr`), and the fmt
string `0x8200B358` is referenced only at `0x8218ca68` inside `sub_8218C9D8` → any conclusion built
on "caller = 0x82189138" was declared invalid. **Overturned by F-023.**

**F-002 — TRUE fatal chain solved (guest-native, working as coded).** FACT · G · P0-context.
`sub_8218C9D8` → `sub_8218C650("embedded:/…")==-1` AND `sub_8218C650(name)==-1` →
`byte_827D5C70!=0` → fatal dispatch → indirect call `[0x8285FEA0]` → host fatal dump (this chain was
first written as `bl sub_821C0E18`; **F-008 corrected that** — the word at `0x8218ca6c` is `stw`).
Evidence: IDA decompiles of `sub_8218C9D8` (xref `0x8218ca68`) and `sub_821C0E18`
(`if (dword_8285FEA0) dword_8285FEA0(fmt); while(1);`), plus `slot 0x8285FEA0 = 0x82130678` and the
GETDEV #40–#43 cascade @19:13:04.763. The open question is why BOTH lookups return −1.

**F-003 — Fatal handler target `0x82130678` is a zero pad-hole in the image.** FACT · I · P1.
`read_memory_bytes(0x82130678,16)` = all zero, IDA has no function there, yet a formatted fatal
dump appeared → a host override owns the address. On Xbox, `[0x8285FEA0]` must be populated by some
writer; if that writer never ran, THAT is an upstream first-divergence candidate.
**Superseded by F-007.**

**F-004 — EMB76 census never fired in the fatal boot.** FACT · I · P1. `grep -c EMB76
build/boot_stdout_78.log` → 0 while `mcla_patch_groups='all'` and GETDEV/MOUNT76/INFLATE/TSLAB/
REBASE censuses all printed → the embedded-device path never executed (or the hook's trigger never
happened).

**F-005 — Fallback device holder is empty-but-allocated at fatal time.** FACT · I · P1.
GETDEV-E1 lines: `hold=A0084028 dcnt=0000 dcap=0001 d0=CDCDCDCD vt0=00000000`, identical at
#40–#43. Capacity allocated, count 0, slot never written → consistent with *both* "never
registered" and "registration writes vanished".

**F-006 — Fatal dispatcher host interceptor identified (`sub_821BD618`).** FACT · D · P1.
`patches.cpp:441` `dispatcher->SetFunction(0x821BD618, sub_821BD618)`; host impl
`imports.cpp:2818-2873` reads slot `0x8285FEA0`, prints message + regs + stack chain, then
`ExitProcess(0x80000003)`. Raw PPC: `lis r11,0x8286; lwz r10,-0x160(r11)`; `cmplwi r10,0; beq;
mtctr r10; bctrl; b .`.

**F-007 — Plan correction: `0x82130678` is NOT zeros — it's a function prologue.** FACT · I · P1
(corrects F-003). Real prologue `7D8802A6 9181FFF8 9421FFA0 38600000` (`li r3,0`) — confirmed
in F-023.

**F-008 — Plan correction: the `bl` at `0x8218ca6c` is NOT a call to `sub_821C0E18`.** FACT · H ·
P1 (corrects F-002's call-site). Raw word is `912A0000` (`stw`), so the fatal is invoked through
the indirect `bctrl` on slot `0x8285FEA0` — confirmed in F-023.

**F-009 — EMB76 hook decoded: hooks `sub_821CB070` (embedded-device method).** FACT · I. The
census sits on the vtable+16 method, which is why `EMB76` staying 0 says "the embedded device's
table-insert was never called", not "the hook is broken".

**F-010 — E1 fallback device holder confirmed empty across ALL 43 GETDEV calls.** FACT · I ·
`hold=A0084028 dcnt=0000 dcap=0001 d0=CDCDCDCD` every time.

**F-011 — Preload lists read but every star_glow lookup misses.** FACT · I · P0. GETDEV #28–#37 read
`a:/archive/shaders/{ui,city,cars,characters,effects}/preload.list`; INFLATE #1–#7 decompressed —
yet `embedded:/dcl/star_glow.dcl`, `embedded:/star_glow.dcl`, `embedded:/fxl_final/star_glow.fxc`
and the mangled archive path all miss.

**F-012 — Fork F1 resolved: AUDIT_FOCUS=DEVICE (star_glow was NOT preloaded).** FACT · D/E · P0.
Preload never registered the name → the defect is the device/registration path, not the lookup
implementation.

**F-013 — `byte_827D5C70` = compile-time constant `0x01`; never written at runtime.** FACT · D ·
P1. It is a device/status flag baked into the image, not a runtime variable — **patching it cannot
be a fix** (masking the symptom).

**F-014 — `sub_8218C650` is NOT a standalone function; the real lookup is `sub_82189138`.** FACT ·
A · P1 (corrected the plan's target). Confirmed again in F-023.

**F-015 — Generated `sub_82189138` matches the binary (shader-lookup integrity PASS).** FACT · A ·
P0. Instantiated diff of the generated body vs the raw image: branch targets, call arguments and
LR/CTR behavior all correct → codegen cleared for the lookup path.

**F-016 — Generated `sub_8218C9D8` is a device-dispatch wrapper, NOT the shader lookup.** FACT · A.
Corrected the assumed role of the function the handoff called the "shader load-by-name wrapper".

**F-017 — Device memory layout decoded — E0 holder populated, E1 empty.** FACT · A · P0. Handler
table entry holds a `Device**` array with devices `d0=A007D398`, `d1=A007D810` (both
`vt=82012BDC`, `pfx=0x0B` = "a:/archive/"); the E1 slot is uninitialized (`flag=0xCDCD`,
`d0=CDCDCDCD`).

**F-018 — Device vtable addresses decoded.** FACT · A. Memory-device vtable `0x82012918`
(`+0` AE50 exists/size, `+4` AFB8 open, `+16` CB070 insert, `+80` CB400); base fiDevice vtable
`0x8201206C` (open slot = stub `0x82762480`); packfile vtable `0x82012BDC`; embedded vtable
`0x82012B44`.

**F-019 — Device registration census — MOUNT76 and EMB76 never fired.** FACT · A · P1. In the audit
boot only the two `a:/archive/` mounts appear; no embedded/memory registration event at all.

**F-020 — Device registry holds only ONE type — the embedded device type is never registered.**
FACT · D · P0 (first-divergence candidate). Handler table `0x82860844`: `cnt=1, cap=16`, single
entry `a:/archive/`; the supposed embedded holder E1 is empty-but-allocated (F-005/F-010).

**F-021 — Executed-path reachability join — all 153 LRs map to known functions.** FACT · A · P1.
153 distinct LR values extracted from the fatal soak; 0 unmapped → no missing-function suspicion on
the executed path (the "codegen hole" theory loses its base there).

**F-022 — Generated-code completeness census — 33 % stubs overall, 0 executed stubs.** FACT · A ·
P1. Census over all 44,707 functions: stub-marked functions exist, but none on the executed path →
stub returns are not the current blocker (they became one later, session 76y: jump tables).

**F-023 — Heavy-model verification pass: F-001 OVERTURNED, F-007/F-008/F-014 CONFIRMED.** FACT · H ·
P1. File bytes (offset = guest − 0x82000000): `0x82189268=386BB358` (`addi r3,r11,0xB358` → fmt
`0x8200B358`), `0x8218926C=480343AD` (**`bl 0x821BD618`**), return `0x82189270` = the logged lr;
`0x82189408`/`0x8218947C` = `bl` into `0x82189138`; `0x8218ca6c=912A0000` (`stw`, not `bl`);
`0x82130678=7D8802A6 9181FFF8 9421FFA0 38600000` (real prologue, not zeros);
`patches.cpp:441` SetFunction. **F-001 was wrong — the planning model's IDA disassembly was
misaligned; the executor's raw-file reads are ground truth. Rule for all future work: verify IDA
claims against raw file bytes before trusting them.**

**F-024 — GETDEV full dispatch traced — 8-prefix fallback to handler-table scan.** FACT · H · P0.
`ppc_recomp.17.cpp:1015-1417`: `sub_821CB488` checks `"memory:"` (7) and `"embedded:/"` (10) first —
both return the **dead pointer `0x827D838C`** — then `"tcpip"` (6) → `sub_821D5F58`, more hardcoded
prefixes, then a fall-through scan of the handler table `0x82860844` (276-byte entries), then the
global `0x827D8380` set by MOUNT76. Handler table has `cnt=1, cap=16` ("a:/archive/") with devices
`d0=A007D398`, `d1=A007D810` (both `vt=82012BDC`, `pfx=0x0B`); E1 uninitialized (`flag=0xCDCD`,
`d0=CDCDCDCD`).

**F-025 — Handler table structure identified — 276-byte entries with nested vectors.** FACT · H · P0.
Header: `+0` Device** array, `+4` u16 count, `+6` u16 capacity. Entry (276 B): `+0` name[262],
`+262` flag, `+264` nameLen, `+268` Device** array, `+272` device_count, `+274` device_capacity.
Census GETDEV-E0: `name='a:/archive/' flag=1 len=11 hold=A0018028 dcnt=0002 dcap=0002`.

**F-026 — Census hook traced for all key functions.** FACT · H · P1. GETDEV census reads the handler
table, `lockFlag` `0x82855A0C` (=FFFFFFFF), per-entry name/flag/len/hold/dcnt/dcap and per-device
`vt`/`pfx` (via `d0+36`/`d1+36`); MOUNT76 census logs path/dev/vt/flag/lr. Both pass-through.
MOUNT76 shows `lr=821CBF54` for both archive mounts; GETDEV returns the dead `0x827D838C` for
`memory:`/`embedded:`.

**F-027 — GETDEV redirect fix REJECTED — three fatal flaws.** FACT · H · P0. The applied redirect
(dead pointer → `s_archiveDevice`) was reverted because (1) `EMB76>0` becomes unreachable (archive
device methods are not embedded-device methods), (2) star_glow content lives in inflated RAM
buffers, not at `a:/archive/` paths, (3) it does not address the policecam stall (a `TOC76` on the
archive path). **The dead pointer is a symptom; the cause is that inflated dictionaries are never
mounted.**

**F-028 — Post-inflate code flow traced — the callback at `[r26+1548]` is key.** FACT · H · P0.
`ppc_recomp.14.cpp:19321-19390` after the inflate loop: vtable+124 call, `sub_821CE100` ×2 cleanup,
then the callback `[r26+1548]` with `r3=[r26+1552]` (archive device), `r4=[r26+8]` (data/buffer),
`r5=[r26+1544]` (inflated size), `r6=0`, then `sub_821C31B8`. Hypothesis (later killed by F-032):
this is where the memory mount should happen.

**F-029 — All boots show MOUNT76=2 — a memory mount never happens in ANY configuration.** FACT · H ·
P0. `boot_stdout_78.log`, `_79`, `_80`, `_p0d1` (post-hydration-fix) all show exactly 2 MOUNT76
calls, both `a:/archive/`. Inflation works (INFLATE #1–#7 / #1–#15) but the mount that would expose
the inflated data as a device never happens — the hash-table hydration fix did not change this
(different code path).

**F-030 — PHASE1 §0 "IO slot never completes" is OVERTURNED (p1b).** FACT · H · P0. `p0d1`
`WAKE[KWFSO] status=00000000` fires constantly on the same `obj@40004D7C` wait (`tid=000063E8`); the
WAIT line's `put`/`rptrWB` are GPU CP metrics (`gpuCtx+10908`, `0xC701C4BC`), not fields of the
waited object. Guest `sub_8242FB88` is a driver poller (30 ms timeout, `KeResetEvent` on success) —
designed behavior. Do not treat that wait loop as the stall.

**F-031 — p0d1 `TOC76 #22` hang is FLAKY; the real terminal frontier is the star_glow fatal.** FACT ·
H · P0. `boot_stdout_p1b.log`: `TOC76-RET #22 ret=A008F950 dt=0ms`, boot continues to `TOC76 #80`
then the fatal (same as baseline 78). p0d1 stopped at the #22 entry with no RET — the hang only
stopped the boot *before* star_glow. Hydration (`DICT-HYDRATE` 10/10) does NOT prevent the fatal: it
only hydrates factory names (draw/Copy/…); the "hydration works" claim was an artifact of the hang.

**F-032 — The post-inflate callback is a SEMAPHORE RELEASE, not a memory mount.** FACT · H · P0.
`cbPtr=821BC548` is `b sub_821C9108` (tail call); `sub_821C9108` only uses r3 →
`sub_8244ED10(h,1,0)`, ignoring `r4=bufPtr` and `r5=inflSize`. Runtime `RELSEMA sub_821C9108 #40
h=C98B9800 lr=821BC538` matches `arcDev`. **Overturns F-028's hypothesis — the Mount must be
elsewhere.**

**F-033 — Only 3 Mount call sites; the non-archive ones never run.** FACT · H · P0 (raw-byte
verified). `bl sub_821CB9D8` exists only at `sub_821CBF28` (fires 2× archive), `sub_821399E0`
@`82139B58` (zero xrefs in `ppc_xenon`), `sub_82139BE0` @`82139EF4` (only from `sub_82135E48`);
raw prologue `7d8802a6` at all three starts. T4a (F-034) proves the non-archive chain is never
entered. Still: do not GETDEV-redirect (F-027).

**F-034 — T4a: the entire non-archive Mount chain never executes (branch 3).** FACT · H · P0.
Censuses on `sub_8213AB78`, `sub_82135E48`, `sub_82139BE0`, `sub_82144B90`, `sub_82144D30`,
`sub_82144EB0` all fire **0 times** through the star_glow fatal; the only MOUNT76 site that runs is
`sub_821CBF28` (2× `a:/archive/`). `memory:` string references live in `sub_821CB740` (fmt
`"memory:$%p,%d,%d:%s"`) and the GETDEV prefix checks `0x821C9ACC..0x821CB4A0`. Registration is not
via these Mount sites on our boot → next: census `sub_821CB740`/`760` callers + device ctors.
**Do NOT implement a host `memory:` device until that census lands (T4b forbidden until the report).**

**F-035 — `memory:` format string located.** FACT · H · P1. `mcla_pe.bin`: `0x820127D8` = `"memory:"`,
`0x82012A28` = `"memory:$%p,%d,%d:%s"`; `lis`/`addi` → `sub_821CB740` @`0x821CB754` (tail-calls
`sprintf` `sub_82137A08`). Several callers across `ppc_recomp.4/15/43/61/90/122/128` — these are the
real memory-path producers to census.

**F-036 — p2f: preload `.xsf`/`.xtd` stream containers are never filled (CDCD).** FACT · H · P0.
`boot_stdout_p2f/p2g`: `BUDDY76-ALLOC A47FD000(0x2000)`, `B7B41000(0x20000)` CDCD-filled; ctor
`821D2970` writes vtable `0x820131A4` into `[obj+0]` only — payload arrays `[+12]`/`[+16]` stay
`CDCDCDCD`. Preload task `821BC140` inflates 14 XCompress chunks (229 KB, magic `0x0FF512EF` real)
of `legals.xsf`, completes, RELSEMA `C9B36F00` — but the PLACE pass (`825EF100` family: `825FDBF8`
build, re-walk via `8217D890`/P10, per-entry `825FDA90`) runs against containers whose entry arrays
were never populated. Root suspicion: the archive read path (`evt=0` NtReadFile reads, page-cache
slots stuck `state=1`) never delivered the `.xsf` TOC/data. vtable `0x8208521C` family = swfC
(CLIP_FRAME, PlaySound strings; `8211E250` runtime reg table `{func,flags}`); `8260A830` = "Invalid
fixup" walker.

**F-037 — p2f: `GetKernelObject` raw-cast fallback + `dynamic_cast` = host AV.** FACT · H · P0.
Crash-2 (`E06D7363` after `C0000005 rva=0x322E8AD`, `__RTDynamicCast` + `NtReleaseSemaphore+0x2B9`):
the guest release of sema `C9B36F00` hit `imports.cpp` `NtReleaseSemaphore` → `GetKernelObject`
raw-cast fallback returned **guest memory as a `KernelObject*`** → `dynamic_cast<Semaphore*>` on it
→ AV. Fixes: `NtReleaseSemaphore` resolves like Wait, and `Heap::IsPhysicalArenaPtr` guards raw-cast
fallbacks (never `dynamic_cast` on guest memory).

**F-038 — p2f: three-guard neutralization of poison container walks.** FIX · H · P1. Boot now runs
240 s+ (2.2 MB log vs 79 KB at rgxa). Guards: (1) `FDBF8-BUILD POISON-SKIP` (`825FDBF8` hook):
`vt/arr=CDCD` → null `[+12]`, zero `[+16]`, skip body; (2) `FIXWALK-SKIP` (`8260A830` hook): CDCD
bucket base → return 0, no body; (3) `FB0D8-DTOR guard` (`825FB0D8` hook): child vtable not in image
range → skip dispatch; (4) `FDB30-DEAD` (`825FDB30` hook): `[cont+12]=CDCD` → empty dispatch.
Remaining: 13 caught AVs in 4 min from deep original-body reads (`sub_825FDB30+0x1C6` via FB0D8
`vt+16` dispatch on place-pass containers) — noisy but harmless. The upstream fix was F-039, not the
read path.

**F-039 — p2p: `NtCreateSemaphore` identity handle never registered — Release woke a phantom
wrapper (T5 root cause).** FACT · H · P0. `p2o` log: `RINGB-CONSUMER tid=570C WAIT C5000280`
08:53:08.460 → `RELSEMA+SIGNAL C5000280` 08:53:12.703, `PUSH wIdx=1 cnt=1`, **no WAKE for
tid=570C**, `INLINE-EXEC 821BC140 count=0`, `INFLATE count=0`, containers stayed CDCD. Root cause:
`NtCreateSemaphore` did `CreateKernelObject` + `GetKernelHandle` (identity = `MapVirtual(host
Semaphore*)`) but **never registered it in `WrapperIdentityMap`**; Wait (`NtWaitForSingleObjectEx`)
uses `GetKernelObject` → Translate → the raw host `Semaphore*` (correct), while Release
(`NtReleaseSemaphore`) `TryQueryKernelObject` missed and then **minted a second wrapper over the
same guest VA** and released *that* — the waiter slept forever on the original. Same class as the
session-72 wake-loss, still present for `NtCreate*` products.
**Fix:** `CreateRegisteredKernelObject<T>()` + `LookupIdentityKernelObject()` in `xdm.h`;
`NtCreateSemaphore`/`NtCreateEvent` register at create; `NtReleaseSemaphore`/`NtSetEvent`/
`NtClearEvent`/`NtWaitForSingleObjectEx`/`NtReadFile` event-signal resolve identity-first and never
mint over an identity handle; `Heap::IsPhysicalArenaPtr` guards raw-cast fallbacks.
**After the fix** (`boot_stdout_p2p.log`, 90 s): `WAIT C5000280` → `PUSH #1` → `INLINE-EXEC #1` same
tid; `PRELOAD-CTX #1 streamCnt=7 buf=A47FD000`; `INFLATE #1-#14` magic `0FF512EF` consumed 229356
(XCompress OK); `COMPLETE 821C31B8 #1`; POST-EXEC-START reached; `INLINE-EXEC #2 buf=B7B41000`;
`INFLATE-SKIP magic=525DE064` (job #2 stream not XCompress — next investigation); `FRAME-END #1-#2`,
`P4'-PRESENT #1-#3`, `LOADING-GATE put=9` (GPU put 7→9); `draw_indx=0` still.
**Notes:** the T5 "`evt=0` NtReadFile page-cache" theory was an upstream symptom; the real T5
blocker was the ring-B semaphore wake-loss — the archive VFS/TOC/open path was already delivering
(TOC76 hits, real packfiles opened).

---

**F-040 — w37a: the VEH AV ladder was laundering ONE fault site, not many.** FACT · H · P0.
`src/boot_host.cpp` AV-recovery branch (the `count==1 → Rip+=16 / count==2 → Rip+=64 / else →
fabricated return with RAX=0` ladder) replaced with a diagnostic + `EXCEPTION_CONTINUE_SEARCH`,
built clean, 120 s soak `build/w37a.log` (`BOOT_RC=124`, process survived). Result: baseline
`build/smoke_long2.log` logged **703** `VEH boot-worker AV` lines and all 703 shared a single guest
`lr=822FBC28`; neutralised, the count is **1** (`w37a.log:3989`) and **0** recovery lines. So the
ladder never faced a storm of distinct faults — it converted one hard fault into a 703-iteration
retry loop on the boot-worker thread. This is `PLAN_VMX128.md` risk R5 in host form (skipping the
instruction "looks like progress") and it is absent from `PROGRAM_GUIDE.md` §7's short-circuit table.
**Boot did NOT advance and did NOT crash earlier** after the decline: the boot-worker thread simply
goes silent from `w37a.log:3989`, the rest of the log is the healthy GPU-worker tick
(`lr=8242FC1C`, obj `40004D7C` — F-030) plus the GFx place-walk, and CP is still
`put=11 rptrWB=0000`. Marker deltas vs baseline are ±1 (`GFx` 0→1, `UILOAD` 2→1, `INFLATE` 315→325,
`PARK` 114→117); `DRAW_INDEXED`/`DRAWDISP` stay 0.
**Conclusion: the recovery was not the park cause; the fault itself is.**

**F-041 — w37a: the true fault is a virtual call into `sub_821873E8` (raw-decoded).** FACT · D · P0.
Fault line (`w37a.log:3969-3988`): `code=0xC0000005` `Param[0]=0` (read) `Param[1]=0x7E780000` =
guest-0 dereference (documented signature, `src/gpu_device.cpp:1035-1041`), guest
`lr=822FBC28 r3=C8A22D00 r4=82040F0C r5=0 r8=821873E8 r9=8200AE8C r10=82040000 r13=8F200000`.
Raw words (`mcla_pe.bin`, offset = VA − 0x82000000) at the caller:
```
822FBC10  806B9F68   lwz   r3, -0x6098(r11)     -> C8A22D00  (global allocator instance)
822FBC18  81230000   lwz   r9, 0(r3)            -> 8200AE8C  (vtable, in-image)
822FBC1C  81090004   lwz   r8, 4(r9)            -> 821873E8  (= dump r8, so caller frame is current)
822FBC20  7D0903A6   mtctr r8
822FBC24  4E800421   bclrl                      -> JSR; LR = 822FBC28 = the logged lr
```
`0x8200AE8C` is a real 4-slot vtable: `+0 82187698`, `+4 821873E8`, `+8 82187450`, `+12 82187600`
(words at `0x8200AE88..0x8200AE98`). So the logged `lr` is the return address of a **real virtual
call into the TLS-allocator dispatcher `sub_821873E8`**, and the guest-0 read happens inside it (or
deeper — `sub_82187450` is the same-shaped thunk, `li r4,0x50` + `bl 0x82193870`).
**Corrections to record:** `src/gpu_device.cpp:1035-1038` describes the callee as
`r3=[r11+12] … bctrl`; the raw words are `r11=[r13]`, an **indexed store** (`XO 0x2AE` family) with
`rA=r10=12, rB=r11` (i.e. it *writes* r3 into TLS slot +12), then `r9=[r3]`, `r8=[r9+8]`,
`bclrl`. The host override's chain shape therefore rests on a mis-transcription and must be
re-derived before any further fix. **OPEN:** which register held guest 0 at the fault — the ctx dump
is post-fault and the leaf-call/sticky-value ambiguity (F-023 caution) prevents attribution from the
dump alone; needs a census hook on `sub_821873E8`/`82187450`, not another RIP hack.

**F-042 — w37a: the `swfCMD::Fixup - unknown type` fatal is pre-existing, not experiment fallout.**
FACT · H · P1. `w37a.log:6077-6083`: `Fatal error dispatcher` `lr=0x8260A8CC r3=0x82088854
r4=0x000000B7 r5=0xB7B6D9B4`, message `'swfCMD::Fixup - unknown type %d'`, then `FATAL-SOFT` +
`FATAL-SOFT-RESOURCE-PARK #1` (host soft-park, guest retries). The identical pair is in
`build/smoke_blue2.log:11129,11143` (14:50, **before** the neutralisation build) with the same
`lr=8260A8CC`. `0x8260A830` = the "Invalid fixup" walker already noted in F-036; the preceding line
`P9-B588 #00003 node=B7B6D9B4 type=B7` shows the type byte. So `Fatal error 1 vs 0` in the marker
diff is a **flaky pre-existing frontier in the GFx place-walk**, not a consequence of removing the
AV ladder.

---

**F-043 — w37a: F-041's attribution is superseded — the fault site is a `PPC_CALL_INDIRECT_FUNC`
probe, and the global is `0x82839F68`, not a device.** FACT · D · P0. Raw decode of
`0x822FBC10..0x822FBC24` via `generated/ppc_xenon/ppc_recomp.49.cpp:21103-21125` (the recompiler's
own text, so no hand `lis` arithmetic):

```
lis   r11,-32124            r11.s64 = -2105278464  -> u32 0x82840000
lis   r10,-32252            -> u32 0x82040000 ; addi r31,r10,3852 -> 0x82040F0C  (= dump r4/r31)
li    r6,0 ; li r5,0
lwz   r3,-24728(r11)        ctx.r3 = PPC_LOAD_U32(0x82839F68)   -> dump r3 = C8A22D00
mr    r4,r31
lwz   r9,0(r3)   lwz   r8,4(r9)   mtctr r8   ctx.lr = 0x822FBC28   PPC_CALL_INDIRECT_FUNC(ctr)
```

Three corrections to F-041 and to the 17:05 backlog text:
1. The global is **`0x82839F68`** — the dword directly below the shader-dictionary hash table
   `0x82839F70` (F-024), i.e. dictionary-adjacent state, and `src/` has **no reader, writer or
   census** for it (verified: `grep -rn 82839F68 src/ docs/ tools/` → 0 hits). The `0x82859F68`
   in `LONG_TODO_MASTER.md` T38.0 step 3 is a sign-extension slip.
2. The `0x822FBC28` in the log is `ctx.lr` written by the recompiler **immediately before**
   `PPC_CALL_INDIRECT_FUNC`, and the dump's `r9=8200AE8C / r8=821873E8` are the caller's values.
   The vtable+4 identity is therefore `0x821873E8` (confirmed: `[0x8200AE90] = 0x821873E8`), but
   "vtable+4 is `rage::fiDevice::open`" is **not supported by the raw words** — `0x8200AE8C` is a
   4-slot table `{82187698, 821873E8, 82187450, 82187600}` whose members all re-read `[r13]` +
   slot +12 and tail-`bclrl` a `[obj+8]` method with `li r4` = 0x48/0x50 — allocator-shaped, not
   device-shaped.
3. `src/ppc_context.h:124` defines
   `PPC_LOOKUP_FUNC(x,y) = *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE + (uint32_t(y) − PPC_CODE_BASE)*2)`
   and `PPC_CALL_INDIRECT_FUNC(x) = PPC_LOOKUP_FUNC(base,x)(ctx,base)`. The fault is a **read**
   (`Param[0]=0`) of host `0x7E780000` = `g_base + 0`, i.e. the lookup-table probe landed at offset
   0 → the CTR value at the probe was **not** `0x821873E8`, or `base`/window constants are wrong for
   this address. `src/dispatch_guard.cpp:37` already recomputes this same expression to guard bad
   indirect targets, so the class is known; what is NOT known is which value CTR held.
   **This is the one item the post-fault ctx dump cannot settle** (the dump never prints `ctr`,
   `xer`, `r11` or `r30`) — see T38.1: extend the crash dump with `ctr` and the guest→host lookup
   address, which is a pure logging change and ends the guessing.

**Also:** `sub_821873E8`'s host override (`src/gpu_device.cpp:1035-1041`) transcribes the guest as
`r3=[r11+12] … bctrl`; the words are `lwz r11,0(r13)`, `add r3,r10,r11` (**r3 = &tlsTable[12]**, an
address not a load), `lwz r9,0(r3)`, `lwz r8,8(r9)`, `bclrl`. The override's fabricated 16-byte
object stores the callable at `vtable+8` with `vtable` at `obj+0`, but the guest reads
**`[obj+8]` directly with no vtable indirection** → if the fabricated object is ever what slot 12
points at, `[obj+8]` is the host-completed `0` and the indirect call probes guest 0.
`w37a.log:3786` shows exactly one `FIX-821873E8 #1 TLSDEAD … slot12=00000000 → host-complete`
hit at 17:15:27.811, i.e. **the fabrication did run on this thread 1.1 s before the only AV**. Prime
suspect, not proven (the AV could equally be the caller's own `[0x82839F68]` being stale) —
T38.1's `ctr` dump distinguishes them in one soak.

**F-044 — 2026-09-20 17:57. The GFx "vtable mismatch" is a host-side false gate, and `W34-NOGFX` is
reporting a true fact: the guest never constructs a loader in this soak.**
Class G (our own mitigation/detector misread as a guest defect) + C (missing guest progress). Source:
T38.1 census, raw image only (`build/cache/mcla_pe.bin`, 10,354,688 B @ 17:14), no code change, no
rebuild.

1. `0x8206DFAC` has **exactly one producer in the whole image** — a sliding `lis`+`addi` scan over all
   0x9E0000 bytes yields `0x82482020` (`lis r10,0x8207 ; addi r9,r10,-8276`), stored by
   `stw r9,0(r3)` at `0x82482028`, i.e. **`sub_82482008` is a vtable-installing ctor**, and we never
   write that value from `src/` (`grep -rn 8206DFAC src/` → 0 hits). It is not corruption and not a
   host fabrication.
2. The loader ctor's own words confirm the host's "want" values are genuine and the calling
   convention is right: `0x824C6F1C mr r31,r3` (so **`this` = r3**, as `src/gpu_device.cpp:1148`
   passes it), `0x824C6F28 addi r9,r11,14044` → `0x820736DC`, `0x824C6F30 stw r9,0(r31)`,
   `0x824C6F2C addi r8,r10,14000` → `0x820736B0`, `0x824C6F38 stw r8,672(r31)`.
3. **But the ctor then overwrites them.** After its own stores it calls `bl 0x8252F840`
   (`r3 = this+808`) and then **`bl 0x82482008` twice** (`0x824C6F48`, `0x824C6F50`), and by (1) each
   of those writes `0x8206DFAC` at `[arg+0]`. So `GFX-CTOR done vt0=8206DFAC vt672=8206DFAC`
   (`w37a.log:3794`) is the **expected post-construction state**, and the
   `GFX-CTOR-VT-MISMATCH` check at `src/gpu_device.cpp:1156` compares a *mid*-construction snapshot
   against *post*-construction state. It has no diagnostic value and should not be treated as a
   defect signal.
4. `0x820736DC`/`0x820736B0` are also produced by three other guest sites — `0x824CA7E4`,
   `0x824CA868`, `0x824CA8CC`, `0x824CA960`, `0x824CA964` — i.e. the class has re-typing methods
   (`0x824CA948`'s body stores both vtables), so "vtable == 0x82073xxx" is not a stable loader
   identity anyway.
5. **The decisive census result:** in `build/w37a.log`, `82482F78` — the guest's own movie-ctor
   wrapper that `src/task_dispatch_trace.cpp:1495` names as the real caller of `824C6F08` — appears
   **0 times**, while `824C6F08` appears **once**, and that one is the forced host call inside the
   `GFX-BLOCK` (`w37a.log:3791-3794`). The guest therefore never reaches its own GFx loader
   construction, so the scan at `src/gpu_device.cpp:5251-5254` (accepts only
   `w0 & 0xFFFFF000 == 0x82073000`) correctly finds nothing and `W34-NOGFX` (`:5541`, log `:5842`) is
   an honest observation, not a broken detector.

**Consequences, in order.** (a) The `§0` "GFx vtable mismatch = #1 blocker" ranking is **void** — the
frontier is why the guest never reaches `sub_82482F78`, and the boot-gate thread dying after two
`GATE-STAGE` lines (`w37a.log:3797-3798`, AV at `:3969`) is the sufficient explanation on the table.
(b) The whole `GFX-BLOCK` (`src/gpu_device.cpp:1131-1165`: `mem.Alloc(1024)` + zero-fill + forced
ctor + vtable expectation) is a **fabricated stand-in for guest progress** and belongs in the T38.3
mitigation catalogue; it cannot make UI appear, because a loader the guest never asked for has no
package, no movie and no `[loader+4]` factory (cf. `W34-NOMOVIE` wording at `:5533`). (c) F-041's
core claim is **partly restored** by the `r9=8200AE8C / r8=821873E8` pair in the same dump — the
virtual call *does* dispatch into `sub_821873E8` (`[0x8200AE90] = 821873E8`, verified word) — while
F-043's corrections stand (global is `0x82839F68`; "+4 = `rage::fiDevice::open`" unsupported; the
dump still omits `ctr`). What (c) does **not** settle is whether the AV is in the caller's probe or
in the callee with sticky `ctx.lr` — still one `ctr`-inclusive dump away (T38.2).

**Do not** "fix" (3) by writing `0x820736DC`/`0x820736B0` into the object after the ctor returns;
that would defeat (1) and (5) and re-launders a real signal, exactly the F-040 failure mode.

**F-045 — 2026-09-20 18:00. F-043's "shape bug in the `sub_821873E8` override" is FALSE — the raw
words show vtable indirection through slot +8, which is exactly what the fabricated chain fills.**
Class G (a wrong finding about our own code, caught by re-reading bytes). Raw disassembly of
`0x821873E8` (`tools/ppc_disasm.py 821873E8 16`):

```
821873F4  816D0000  lwz   r11,0(r13)        r11 = *tls_ptr            (tlsTable)
821873F8  3940000C  li    r10,12
82187404  38800048  li    r4,72             (alloc 72) ; r5=16 (align), r6=0
82187408  7C6A582E  lwzx  r3,r10,r11        r3 = *(tlsTable + 12)      (allocator obj)
8218740C  81230000  lwz   r9,0(r3)          r9 = [obj+0]               (vtable)
82187410  81090008  lwz   r8,8(r9)          r8 = [vtable + 8]
82187414  7D0903A6  mtctr r8
82187418  4E800421  bclrl                   tail-JSR ctr ; cmpli r3,0 / bl 82188CF8 follow
```

Corrections to F-043, point by point: (i) `7C6A582E` is **`lwzx r3,r10,r11`**, not `add`
(XO=13 with OE set) — so `r3` is the *loaded* allocator object, as the override's own comment at
`src/gpu_device.cpp:1035-1041` already said; F-043's "`r3 = &tlsTable[12]`, an address not a load"
is wrong. (ii) The guest therefore **does** go through a vtable (`r9 = [obj+0]`) and reads **slot
+8** — so the fabricated chain's `vtable+8 = 0x82130528` + `allocatorObj+0 = vtable`
(`src/gpu_device.cpp:1080-1085`) is the **right shape**, and F-043's "prime suspect" (fabricated
object can only yield a null call target) is **void**. Do not spend a session on it.

What remains open, and it is narrower than F-043 made it look: at the AV the dumped
`r3=C8A22D00 / r9=8200AE8C / r8=821873E8` are the **caller's** (`sub_822FBAF8`) values, so the body
above had not yet written them → either the callee never ran (the override took a host branch) or
`ctx.lr=822FBC28` is sticky from the caller's `bctrl`. `Param[1]=0x7E780000` is
`(0x82000000 + 0x9E0000 + (0 − 0x82130000)*2) mod 2^32`, i.e. the `PPC_LOOKUP_FUNC` slot for
**guest 0** (`rcx = 0xFFFFFFFEFBDA0000` is that same product) — a null `ctr` did reach a `bctrl`.
Only `ctr` in the dump, plus the faulting host RIP mapped to a symbol, separates the two. → T38.2,
write the answer as **F-046**.

**F-046 — 2026-09-20 19:10. The residual `0x7E780000` AV is a null indirect-call target reached
*inside the host-forced BOOT-GATE*, and the crash dump's GPRs belong to a different `PPCContext` —
so the register triple that F-044(c)/F-045 were interpreted from is a stale snapshot.** FACT+INFER
· G · P1. Answer to T38.2, from `build/w38b.log` (120 s, `BOOT_RC=124`, 11138 lines) and the
probe block added at `src/boot_host.cpp:736-760` / `:861-890`.

Three things settle it, in evidence order:

1. **The fault address is uniquely the function-table slot for guest target 0.** `w38b.log:4023`
   `probe y=00000000 -> off32=0x7E780000 == Param[1]`, while `:4024` `probe y=821873E8 ->
   off32=0x82A8E7D0` (no match) and `:4027` `y=822FBC28 -> 0x82D77850` (no match). With
   `g_base=0x100000000`, `table=0x1829E0000` (`:4022`): `PPC_LOOKUP_FUNC` (`src/ppc_context.h:124`)
   gives `0x1829E0000 + (uint64(uint32_t(y) − 0x82130000) * 2)`, and for any `y ≥ PPC_CODE_BASE`
   that is ≥ `0x182A8E7D0` — far above the 32-bit-looking `Param[1]`. For `y < PPC_CODE_BASE` the
   product sign-extends (host `rcx=0xFFFFFFFEFBDA0000` = exactly `(0 − 0x82130000)*2`, host
   `rax=0x182000000` = `base + PPC_IMAGE_BASE`) and the sum wraps to `0x7E780000 + 2y`, which equals
   `Param[1]` **only at y = 0**. So a `PPC_CALL_INDIRECT_FUNC` executed with a **null call target**,
   and there is no 32-bit-truncation bug in the arithmetic — the earlier truncation hypothesis is
   **void**, and the stale comment at `src/boot_host.cpp:88-89` should stop claiming one.
2. **How a null becomes a call instead of an earlier fault:** `ReadGuestU32`
   (`src/guest_memory.h:82-86`) initialises `val = 0`, calls
   `GetActiveGuestMemoryView().ReadU32BE(...)` and **discards the validity bool**;
   `PPC_LOAD_U32` *is* that helper (`src/ppc_context.h:57`). So the standard
   `lwz r9,0(r3)` / `lwz r8,N(r9)` / `mtctr r8` / `bctrl` chain on a null `r3` produces
   `r9=0, r8=0` **silently**, and the only visible fault is the host table probe 2.1 GiB below the
   window. That is the mechanism behind the whole `0x7E780000` family, and it is why no guest-side
   AV ever surfaces at the cause. Census support: `dispatch_guard.cpp:36-37` guards exactly **one**
   site (`0x8218CC94`, wired via `config/mcla_xenonrecomp.toml:73-78` → `generated/ppc_xenon/
   ppc_recomp.9.cpp:19167`) and treats its slot as a *guest* address — the other ~14.8k indirect
   sites are unguarded, so item 2 is the general path, not an exception.
3. **The dump is the wrong context.** `g_faultCtx = &ctx` (`src/boot_host.cpp:706`) publishes only
   the boot worker's *root* `PPCContext`, but the forced gate calls every guest stage on a separate
   local `PPCContext g{}` (`src/gpu_device.cpp:1121-1127`, stages at `:1187-1236`, volatile-clearing
   lambda at `:1189-1193`) which is never published. Proof in one pair of lines:
   `w38b.log:3864` `FIX-821873E8 #1 TLSDEAD r13=8F200000 tlsTable=8F201000 slot12=00000000
   lr=822FBC28` at 06.137, and `:4021` `ppc r1=8EFFF920 lr=822FBC28 r3=C8A22D00 … r8=821873E8
   r9=8200AE8C` at 07.181 — **the same lr and the same r3/r8/r9, 1.044 s and one whole GFX-BLOCK
   (`:3868-3873`) plus two gate stages (`:3875-3876`) later**, because nothing in between writes the
   root ctx. The faulting frame lives in `g`.

**Consequences.** (a) do-not #14 is upgraded: sticky `lr` was the warning, but the dump can be
*contextually* wrong — `lr` **and** every GPR in it — so a guest-frame attribution from a VEH dump
needs the faulting thread's innermost context first. F-044(c)'s "the `r9`/`r8` pair shows the call
does dispatch into `sub_821873E8`" and F-045's closing paragraph are **void** as attributions (their
raw-word and vtable facts stand — the caller-consistency that convinced them was coincidence).
(b) "one `ctr`-inclusive dump away" is unreachable and was never the fix: `src/ppc_config.h:9-10`
(`PPC_CONFIG_NON_ARGUMENT_AS_LOCAL`, `_NON_VOLATILE_AS_LOCAL`) means `r11` and `r14`-`r31` are host
locals, and `:5` does the same for `ctr`/`xer` — 14 build errors proved it. The substitute probe
design (identity-test `Param[1]` against `PPC_LOOKUP_FUNC`) is what worked and should be copied to
`tools/`. (c) Since the AV is inside gate-driven execution on a synthetic context, it is a
**mitigation artifact, not guest progress lost** — do not arm another value to silence it (rule 1,
do-not #9). **→ T38.2b**: publish the innermost context (set `g_faultCtx` at each guest-function
entry / on `SetPPCContext`, or run the gate stages on the caller's ctx), one soak, and only then
name the faulting site.

---

**F-047 — the §7 short-circuit registry covers 13 of the 81 mitigation-shaped labels actually in
`src/`; 69 are unregistered.** FACT · H · P1. (F-046 is reserved for the T38.2 answer, so this
starts at F-047.) Measured by `tools/mitigation_audit.py` (new, 2026-09-20 19:00), which diffs the
`PROGRAM_GUIDE` §7 prose against label-shaped tokens in `src/` and classifies them by suffix into
mitigation vs census vs unclassified: `624` label-shaped tokens → `81` mitigation-shaped, `64`
census-shaped, `479` unclassified; §7 registers `13`. **STALE = none** — every §7 label still occurs
in `src/`, so the registry is incomplete, not outdated. Two of the 69 read and confirmed as genuine
behaviour changes, not log lines: `BE710-DEAD` (`src/gpu_device.cpp:11451-11460`) writes magic
`0x61786772` into guest memory at `ctx.r4`, forces `ctx.r3 = 1` and returns — or forces
`ctx.r3 = -1` and returns when the stream lookup fails, i.e. it fabricates the guest function's
result either way; `FATAL-SOFT` (`src/kernel/imports.cpp:2987-2995`) soft-parks a guest fatal and
**returns** so the guest retries instead of taking the permanent park. Consequence: do-not #9
("never stack short-circuits") is enforced against §7, and §7 cannot see 69 of them — the pile is
~6× larger than the registry admits. This is the input list for **T38.0c**. Suffix classification is
a triage aid, so each of the 69 must be read before being called a mitigation; the two above were.

**F-048 — one live instance of the VdSwap dead-hook bug class: `hk_XamInputGetState` replaces the
import outright, so the compile-time hook never runs.** FACT · D · P3. **[1 of 2 SUPERSEDED by
F-053 — the "three owners of VdSwap / hard rule-4 violation" half below is false; the
`hk_XamInputGetState` half stands.]** Found by
`tools/addr_owners.py` (new, 2026-09-20), which indexes every guest-address claim in `src/` +
`config/mcla_xenonrecomp.toml`: `678` sites, `409` claiming, `251` hex addresses + `207` named
imports. It reports **1** hard rule-4 violation and **8** named-import/hex overlaps. The mechanism:
`GUEST_FUNCTION_HOOK` expands to `PPC_FUNC(subroutine) { HostToGuestFunction<f>(ctx, base); }`
(`src/kernel/function.h:351-352`) — a compile-time override of the import thunk — while
`SetFunction` is a runtime dispatch override that *does* win at runtime (`src/patches.cpp:317-319`
states the map used to be dead and was fixed to write the real dispatch table). So when both exist
for one import, the runtime one decides. Of the 8 overlaps, 6 chain correctly (their `hk_*` bodies
tail-call the `g_original_*` captured by `GetFunction` immediately before: `NtClose`
`src/patches.cpp:899`, `NtCreateFile` `:855`, `NtReadFile` `:867`, `NtQueryInformationFile` `:884`,
`VdInitializeEngines` `:321`) and `hk_KeWaitForSingleObject` (`:794-825`) chains too except on the two
semaphores it deliberately short-circuits — that is the registered **KDELAY-SC**, not a new bug.
`hk_XamInputGetState` (`src/patches.cpp:827-853`) is the exception: it synthesises the result itself
(`PPC_STORE_U16(buf + 4, …)`, then `ctx.r3.u64 = 0`) and never calls a saved original, so the
compile-time `GUEST_FUNCTION_HOOK(__imp__XamInputGetState, XamInputGetState)` at
`src/kernel/imports.cpp:3537` is **dead** whenever `BisectGroupEnabled("in")` is true
(`src/patches.cpp:516`). Benign today — the replacement is a superset — but it is the same shape as
the bug already documented at `src/kernel/imports.cpp:3464-3467`, where a `GUEST_FUNCTION_HOOK` no-op
"prevent[ed] Hooked_VdSwap at 0x827BD6E4 from ever executing". The hard violation is that same
address: **three** owners of guest VdSwap — `PPC_FUNC(__imp__VdSwap)` forwarding to `Hooked_VdSwap`
(`src/kernel/imports.cpp:3469`), `SetFunction(0x827BD6E4, Hooked_VdSwap)`
(`src/native_renderer.cpp:254`), and `SetFunction(0x827BD6E4, hk_vdswap_observer)`
(`src/patches.cpp:678`, having captured the previous owner at `:677`). INFERENCE: it works only
because `native_renderer.cpp` registers first and the observer tail-calls the captured original
(`src/patches.cpp:316-317`); nothing in the tree states that ordering requirement, and
`src/patches.cpp:676` gates its registration on `mode != "compat" && !BisectGroupEnabled("native")`
while `src/native_renderer.cpp:254` is ungated. Both tools exit non-zero on findings, so either can
gate a commit.

---

**F-049 — 2026-09-20 19:20. The guest frame that the (stale) dump names is `sub_822FBAF8`'s preload
loop, and its load chain *completed* — which is the second, independent proof of F-046(3). Global
`0x82839F68` = the shader/preload-list manager singleton; `r4` at the dump is the ASCII string
`"star_glow"`, not a pointer to structure.** FACT · H · P2. Raw words + generated code
(`generated/ppc_xenon/ppc_recomp.49.cpp:21108-21125`), image `build/cache/mcla_pe.bin` (rule 3).

- The site whose return address is the dumped `lr=0x822FBC28` disassembles to:
  `lis r11,0x8284` · `lis r10,0x8204` · `li r6,0` · `addi r31,r10,3852` · `li r5,0` ·
  `lwz r3,-24728(r11)` → **`r3 = [0x82839F68]`** · `mr r4,r31` · `lwz r9,0(r3)` · **`lwz r8,4(r9)`**
  (slot **+4** here, *not* the +8 F-045 read in a different function) · `mtctr r8` · `bctrl`.
  Every dumped value matches that chain: `r10=82040000`, `r4=82040F0C` (= `r10+3852`),
  `r3=C8A22D00`, `r9=8200AE8C`, `r8=821873E8`.
- `0x8200AE8C` is a real vtable in the image: `[+0]=82187698`, `[+4]=821873E8`, `[+8]=82187450`,
  `[+12]=82187600`, and the bytes immediately after it are ASCII — `"preload.list file missing in
  '%s'"`, `".shader"`, `".fx"`, `".fx2"`, `"Preloading shaders f"`. So the class is the
  **shader/preload-list manager singleton**, adjacent to but distinct from F-024's hash table at
  `0x82839F70`. `[0x8200AE90] = 821873E8` (verified word) ⇒ slot +4 **is** the function the host
  overrides at `src/gpu_device.cpp:1044`, i.e. the fabricated TLS chain is consumed by this loop.
- `r4 = 0x82040F0C` decodes to `star_glow\0` in the raw image (a name string, and the block above
  walks a 12-entry structure: `cmpwi cr6,r31,12` / `blt 0x822FBBC0` at
  `ppc_recomp.49.cpp:21103-21107`), while `w38b.log` shows the same call shape carrying `ui`, `city`,
  `cars`, `characters`, `effects`. So this is the per-category preload pass, and `0xC8A22D00` is a
  **live** object, not garbage: `src/kernel/heap.cpp:126-127` puts the physical arena at
  `0xA0000000–0xFFFFFFFF`, and that address appears 5× in `w38b.log`.
- **Therefore the frame whose lr is `0x822FBC28` cannot have faulted on its own table probe** — its
  `mtctr` had `0x821873E8` in hand, and `w38b.log:4024` shows the probe for that value does not
  match `Param[1]`. Read together with F-046(3) this retires the "caller-consistent register set"
  reading of F-044(c)/F-045 for good.
- Owner census (rule 4): global `0x82839F68` has **0** owners in `src/` and 47 generated sites; its
  only *writers* in the image are `sub_821879D8` (factory: `bl 0x82130528` to alloc, sets
  `[obj+0] = 0x8200AE8C`, then `stw r3` into the global) and `sub_82187698` (destructor:
  `if ([0x82839F68] == this) [0x82839F68] = 0`). Image bytes `0x82839F5C…78` are all zero (bss), so
  a null there at runtime means the factory never ran on that path — the exact condition F-046(2)
  turns into a silent null call.
- `sub_822FBAF8` itself: `ppc_recomp.49.cpp:20945-21334` (692 B), **five**
  `PPC_CALL_INDIRECT_FUNC(ctr.u32)` sites (return addrs `822FBB20`, `822FBC28`, `822FBC60`,
  `822FBD78`, `822FBDA4`) — so "null target while executing `sub_822FBAF8`" has five candidates, not
  one; single caller chain `sub_823047D8 → sub_822C2EA8 → sub_82131508`; **0** hits in `src/`; the
  `s_skipSub822FA958` host flag near it is **inert** (never read). Zero `__builtin_debugtrap` in
  `ppc_recomp.49.cpp:18143-22082` re-confirms Route B is off the critical path.

**Do not** re-derive the crash site from `lr` until T38.2b publishes the faulting context; and treat
`0x82839F68` as an *observed* bss singleton, not something to pre-arm.

**F-051 — 2026-09-20 19:40. T38.3's crash-path mitigations are provably dead: 0 firings across both
honest soaks, so they can be deleted with a census-delta of zero as the proof. And the census battery
itself carried a dead marker.** FACT · H · P2. (`F-050` stays reserved for the T38.2b answer per §2.)

- The paths still exist in `src/boot_host.cpp` after T38.0a removed the 16/64/4096 escalation:
  float-div-0 → `0xC3` over `sub_823D91F8`'s host entry + park `:1026-1045`; `isKnownCrashSite` →
  `s_skipSub822FA958` + `0xC3` over `sub_822FA958` + park `:1065-1102`; and **two surviving
  `Rip += 256MB` advances** at `:1057` (illegal-instruction, UILOAD thread) and `:1094`
  ("Nuclear advance", `s_inUILoad`). T38.3 listed them at `~:932-951 / :960-1003 / :971-994` — those
  numbers had drifted by ~90 lines; grep for the strings, not the line numbers.
- Fires, counted as matching lines case-insensitively, `build/w38b.log` (11,138) vs
  `build/w37a.log` (11,232) vs the laundered `build/smoke_long2.log`:
  `advancing RIP` **0 / 0 / 2**, `Nuclear advance` **0 / 0 / 0**, `patch applied, continuing`
  **0 / 0 / 0**, `permanently disabled` **0 / 0 / 0**, `patched sub_82` **0 / 0 / 0**, `cleared
  MXCSR` **0 / 0 / 0**, `UILOAD context` **0 / 0 / 0**, `parking boot worker` **0 / 0 / 0**,
  `fallback advance` **0 / 0 / 692**. Both soaks' entire VEH output is
  `VEH-NEUTRAL … recovery disabled, declining` = **1 line each** (2 `VEH` lines in `w38b` counting
  the follow-up), versus **1,405** `VEH` lines in `smoke_long2`.
- So the handler is honest in a way that is now checkable *per path*, and all five sites above are
  **unreachable in the current boot**. Deletion is therefore provably behaviour-neutral *for these two
  soaks* — which is not the same as proven dead in general: each is gated on `glr` values
  (`0x822F44E0`, `0x82133440`) that F-046/F-049 just showed belong to the **root** context, not the
  faulting one, so a gate-driven fault can hit or miss them unpredictably. Delete, but verify with a
  behaviour-census run (`w38c` vs `w38b`, every marker equal), not with a comment.
  Note (d)/(e) of T38.3 are *not* covered here — the `sub_821873E8` substitution and the `GFX-BLOCK`
  both fire (`GFX-BLOCK` 1, `GFX-CTOR` 4, `GFX-CTOR-VT-MISMATCH` 1 in `w38b.log`).
- **Instrumentation defect found while checking this:** the battery carried `"parking thread"`, a
  string no soak has ever emitted (the real message is "parking boot worker thread"), so a marker can
  read 0 and mean either "never fired" or "never matched". Fixed in `tools/soak_census.py`: dropped,
  and a `VEH_PATHS` list added so each path above gets its own line (107 → 115 markers), plus the
  `SHORT_CIRCUIT` line-count now recognises the RIP-advance messages (baseline short-circuit lines
  782 → 784, i.e. the two real `advancing RIP` events). Same shape of mistake as rule 13's
  case-sensitivity miss: **a zero count is only evidence if the pattern is known to match something —
  prove that by firing it once in a log that contains it.**

**F-052 — 2026-09-20 19:45. T38.2b's gate is met in `w38c.log` and the faulting call is named: it is
the `bctrl` of `sub_82304348` at guest `0x82304368`, and every register the new dump shows is
consistent with a call made through a null object pointer.** FACT (the numbers, the decode) · A/D · P1.
**This satisfies the acceptance criterion §2 set for F-050** — whoever ran `w38c` should fold or
supersede rather than duplicate.

- Published context changed what the dump reports (`tools/soak_census.py build/w38c.log
  build/w38b.log`, counts are matching lines, case-insensitive): lines 9,726 vs 11,138; `C0000005`
  **1 = 1**; `VEH` 2 → **1**; short-circuit lines 172 → 190; and the fault-line `lr` census moved
  `822FBC28` → **`8230436C`** — 1 event, 1 distinct both sides. Register dump, verbatim:
  `w38b.log:4030` `r1=8EFFF920 lr=822FBC28 r3=C8A22D00 r4=82040F0C … r10=82040000 r13=8F200000` vs
  `w38c.log:4090` `r1=8EFFF7C0 lr=8230436C r3=00000000 r4=00000000 r5…r10=00000000 r13=8F200000`.
  **`r1` differs**, which is the exact gate §2 asked for, so F-046(3) is confirmed operationally: the
  old frame was the root context's and is now replaced.
- The `probe` block still identifies the index as **guest target 0** (`w38c.log:4092-4095`
  `probe y=00000000 -> off32=0x7E780000 == Param[1]`), and `y=8230436C` explicitly does not match
  (`:4096` → `0x82D886D8`). Fault line: `:4113` `VEH-NEUTRAL guest AV: lr=8230436C read of host addr
  0x7e780000 … declining` — declined, not recovered (F-051's path battery all 0).
- Raw words at `0x82304364…7C` (`build/cache/mcla_pe.bin`, rule 3): `80630004 38800000 81630000
  814B0010 7D4903A6 4E800421` = `lwz r3,4(r3)` · `li r4,0` · `lwz r11,0(r3)` · `lwz r10,16(r11)` ·
  `mtctr r10` · `bctrl`. The generated code agrees and pins the return address:
  `generated/ppc_xenon/ppc_recomp.50.cpp:5615` `PPC_FUNC_IMPL(__imp__sub_82304348)`, `:5632`
  `ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4)`, `:5636` `r11 = PPC_LOAD_U32(ctx.r3 + 0)`, `:5638`
  `ctx.r10 = PPC_LOAD_U32(r11 + 16)`, `:5642` **`ctx.lr = 0x8230436C;`**, `:5643`
  `PPC_CALL_INDIRECT_FUNC(ctr.u32)`. So `lr=0x8230436C` is *this* call's own return address — not
  sticky, not stale (the one exception §2's do-not #14 allows for). `sub_82304348` has **0 owners** in
  `src/` + `config/` (`tools/addr_owners.py --check 82304348`): pure guest code running unhooked.
- **The null was in `r3` on entry — CONFIRMED in `src/`, no soak needed.** `src/gpu_device.cpp:1203-1206`
  calls guest `sub_82304348` (`FindFunction(0x82304348)` → `fn82304348(g, base)`) on the
  value-initialised `PPCContext g{}` at `:1123`, and the only register prep is `freshVolatiles()`
  (`:1193-1196`) which zeroes **`r5`-`r10` only — never `r3`, never `r4`**. `r3` is first assigned at
  `:1211` (`event1-821C0750` → `g.r3.u32 = 0x82830ACC`), i.e. *after* this call, so at `:1206` `r3=0`.
  The dump says exactly that: `r3=00000000 r4=00000000 r5…r10=00000000`. Then
  `lwz r3,4(r3)` → `lwz r11,0(r3)` → `lwz r10,16(r11)` each fail on a null pointer and each is
  silently answered with 0 by the helper that swallows validity (`PPC_LOAD_U32` = `ReadGuestU32`,
  `src/ppc_context.h:57` / `src/guest_memory.h:82-86`, F-046(2)) — the null rides into `ctr` and only
  detonates at the `bctrl`. Three laundered loads, one visible fault.
- **So the "blocker" is a host call the guest never made**: the gate invents a call frame with a zero
  `this`. The author already knew the rule two stages later — `:1236-1239` *skips*
  `sub_82304398` precisely because it "needs guest this, not UILOAD ret" — `sub_82304348` (and
  `sub_823043F8` at `:1198-1201`, called the same way with `r3=0`) are the sites where that rule was
  missed. Fix candidates, in the project's order: **(i)** T38.3(e) — delete the host-forced
  gate/`GFX-BLOCK` that stages guest calls at all, and this AV is expected to vanish with it;
  **(ii)** if the gate stays, either skip `sub_82304348`/`823043F8` the way `82304398` is skipped, or
  make `freshVolatiles` clear `r3`/`r4` *and log loudly* that a stage is entering guest code with a
  null `this` (a silent zero is how this took three sessions to see). Do **not** arm
  `0x82839F68`, `0x82830ACC` or a vtable slot to make the fault pretty — do-not #9; that would
  fabricate the object the host failed to pass.

**F-050 — 2026-09-20 19:55. T38.2b CLOSED — the causal summary §2 reserved this number for, plus the
two facts F-052 does not carry: the `+0x144` in the new dump is a **host** offset and decoding it as a
guest PC gives a *false* chain, and the block it falsely points at owns a fourth bss singleton.**
FACT · H · P1. Fold-read with **F-052** (which names the call site and the null `this`); do not
re-derive that from here.

- **Gate verdict:** met. `w38c.log:4089` `ppc ctx=0x8a7b2fefc0 tag=forced-boot-gate tid=11632
  (registers below belong to THIS context)` and the register set moved (`r1` `8EFFF920`→`8EFFF7C0`,
  `lr` `822FBC28`→`8230436C`) — F-046(3) is now operationally closed: every pre-`w38c` dump in every
  older soak named the **root** context, so `lr`/GPR readings from them (F-044(c), F-045) are void as
  attributions. The fault is *declined*, not recovered (`:4113` `VEH-NEUTRAL … recovery disabled`), and
  `C0000005` stayed at **1** with no guest advance (`GFx` 9→9, `UILOAD` 1→1, `DRAW_INDEXED`/`DRAWDISP`
  0) — as expected for a diagnostic-only change.
- **TRAP (new, and it bit inside this session):** `w38c.log:4088` `rip owner=guest 0x82304348 +0x144`
  is `hostAddr − RtlLookupFunctionEntry().BeginAddress` — a **host code** offset from the start of the
  translated function, *not* a guest PC displacement. `0x82304348 + 0x144 = 0x8230448C` is a **different
  guest block that never executed**, and reading the line that way produces a confident, wrong
  attribution (a compacted summary of this session did exactly that, and pointed the fault at the
  wrong singleton). Only the *function* half of that line is evidence; the offset half is a hint about
  where in the host body the RIP sat. Message text at `src/boot_host.cpp:547` now reads
  `guest 0x… (host+0x…)` — applied and built green (`build/w38d_build.log`, `BUILD_RC=0`, exe mtime
  19:52); **not soaked**, so `w38c.log:4088` keeps the old wording and the next soak prints the new.
- **The block the trap points at, recorded so it stops being a temptation — NOT the fault chain**
  (raw words, `build/cache/mcla_pe.bin`, rule 3; `tools/ppc_disasm.py 82304470 12`):
  `3D608284` `lis r11,0x8284` · `806B9D70` `lwz r3,-25232(r11)` → **`[0x82839D70]`** · `81430000`
  `lwz r10,0(r3)` (vtable) · `812A0018` `lwz r9,24(r10)` · `7D2903A6` `mtctr r9` · `4E800421` `bclr`.
  Same three-silently-laundered-loads-then-`bctrl` shape as the real site (F-052), which is why the
  false reading is so plausible. `0x82839D70` (and `8D`/`94` neighbours) = `00000000` in the image,
  **0 owners** in `src/`+`config/`. Writers, found by scanning for `stw …,-25232(r11)` — exactly four:
  - `0x82180390` in `sub_82180370` (`ppc_recomp.8.cpp:13376-13402`) — **dtor**: `*this = 0x82009D34`,
    then `if ([0x82839D70] == this) [0x82839D70] = 0`.
  - `0x821809FC` in `sub_821809C8` (`ppc_recomp.8.cpp:14440`+) — same dtor shape with the C2 delete
    flag (`bl sub_82130588` when `r4 & 1`).
  - `0x82186150` in `sub_82186110` (`ppc_recomp.9.cpp:1823`+) — **constructing**: `sub_82130528(76)` →
    `sub_82185D80` → publishes the object iff the incoming `r3 & 0xFF` (static-registrar flag).
  - `0x82186240` in `sub_821861E8` (`ppc_recomp.9.cpp:1973`+) — `sub_82130528(4)` → `sub_82180360` →
    `*obj = 0x8200AAF4` → publishes the same way.
  So `0x82839D70` is a `rage` static-instance singleton with two vtables (`0x82009D34` dtor-set /
  `0x8200AAF4` the 4-byte one). Interesting later; **irrelevant to this AV**, and still not something
  to arm (do-not #9).
- **Frontier unchanged, now unblocked:** the residual `C0000005` is a call frame the *host* invented —
  `src/gpu_device.cpp:1203-1206` enters guest `sub_82304348` with `r3 = 0` on a value-initialised
  `PPCContext` (F-052). Next action is **T38.3**: delete the host-forced gate driver + `GFX-BLOCK`
  (F-051 shows the crash-path mitigations are provably dead, 0 firings) and expect this AV to vanish
  with the gate, verified by a full marker census vs `w38c.log` — not by the absence of the AV alone.

---

**F-053 — 2026-09-20 20:10. F-048(1) is FALSE. `0x827BD6E4` does not have three competing owners —
it has one owner *body* in every possible configuration, and all three registration sites reach
that same body.** Supersedes the "hard rule-4 violation / three owners of VdSwap" half of F-048
(its `hk_XamInputGetState` half, F-048(2), stands unchanged and is still the only live instance of
the dead-hook class). FACT · D · P3. Found while wiring `tools/addr_owners.py --gates`, i.e. by
reading the enclosing functions instead of the `SetFunction` lines.

- **What F-048 asserted, verbatim:** "the two runtime installers … `native_renderer.cpp:254` is
  ungated … it works only because `native_renderer.cpp` registers first and the observer tail-calls
  the captured original; nothing in the tree states that ordering requirement". Both halves of that
  are wrong: `native_renderer.cpp:254` *is* gated (by two early returns 90 lines above it, in the
  same function), and no ordering requirement exists because the two sites cannot co-fire.
- **The address is now proven, not inferred:** `generated/ppc_xenon/ppc_func_mapping.cpp:44910`
  `{ 0x827BD6E4, __imp__VdSwap }` and `generated/default/mcla_register.cpp:29810`
  `registrar->SetFunction(0x827BD6E4, __imp__VdSwap)` — so the *generated* registrar installs the
  named-import override there first, and `src/kernel/imports.cpp:3469`
  `PPC_FUNC(__imp__VdSwap) { Hooked_VdSwap(ctx, base); }` is that override's body. The earlier proof
  for that address was only the comment at `src/kernel/imports.cpp:3466`.
- **All three configurations, exhaustively** (`mode` = `renderer_mode` CVar, `N` =
  `BisectGroupEnabled("native")`, gates at `src/native_renderer.cpp:191`, `:197` and
  `src/patches.cpp:676`):
  | config | generated registrar | `patches.cpp:678` observer | `native_renderer.cpp:254` | live body |
  |---|---|---|---|---|
  | `mode == "compat"` | installs `__imp__VdSwap` | skipped (`:676` needs `mode != "compat"`) | skipped (`:191` returns) | `Hooked_VdSwap` |
  | `mode != "compat"`, `N` false | installs `__imp__VdSwap` | **installs**, and `GetFunction` at `:677` captures the forwarding body it then tail-calls (`src/patches.cpp:309-318`) | skipped (`:197` returns) | observer → `Hooked_VdSwap` |
  | `mode != "compat"`, `N` true | installs `__imp__VdSwap` | skipped (`:676` needs `!N`) | **installs** `Hooked_VdSwap` | `Hooked_VdSwap` |
  `PPC_FUNC_IMPL(Hooked_VdSwap)` (`src/native_renderer.cpp:162-182`) is the only code that ever runs
  on a VdSwap call in any of the three. Call order is `src/app.cpp:84` (`mcla_ApplyPatches`) then
  `:89` (`InstallNativeRenderer`) and is irrelevant, because the branches are mutually exclusive.
- **Which branch is live, from the log (not from the code):** `mcla_patch_groups = 'all'`
  (`w38c.log:88`) ⇒ `N` true (`src/patches.cpp:413-414`); `w38c.log:119` "Native renderer: VdSwap
  registered INERT" = **1**; "VdSwap observer installed" = **0**; "COMPAT mode" = **0**; and the
  body itself fired — `VdSwap[1]`/`VdSwap[2]` at `w38c.log:2858`/`:3143`. Runtime owner =
  `native_renderer.cpp:254`.
- **Effective CVar state, since it is easy to get wrong:** `build/cache/mcla.toml` **does not exist**
  (`w38c.log:6` pins the cache root to `E:\mcla pc\build\cache`; only
  `src/app.cpp:56` `LoadConfig(m_cacheRoot / "mcla.toml")` feeds CVars), so both CVars run at their
  compiled defaults: `renderer_mode = "native"` (`src/renderer_mode.cpp:8`) and
  `mcla_patch_groups = "all"` (`src/patches.cpp:406`). Two stale statements follow from that:
  the comment at `src/app.cpp:85-87` claims the default is `"legacy"`, and
  `config/mcla_manifest.toml:16` sets `renderer_mode = "legacy"` while **no file in `src/` reads
  `mcla_manifest.toml`** (grep: zero hits) — that manifest key is inert. Neither affects this
  finding (`compat` is false under every one of them), but do not cite either as "the configured
  mode" without re-checking.
- **Tooling change that came out of it (`tools/addr_owners.py`):** the two causal assertions the tool
  used to print — "the winner depends on which registration path runs; no single owner is stated
  anywhere" and "registration order decides the winner" — are **removed**, because the tool never
  verified either. New mode `--gates <addr>` prints each claiming site's enclosing-function
  branch/return lines *verbatim* ("NOT interpreted"), and the footer tells the reader the tie is
  broken by grepping the boot log for the installer's own message. Deliberate limitation: the tool
  still reports this address as a violation and still exits 1. It cannot see CVar values at runtime,
  and a reachability analyzer that quietly concluded "not a conflict" would hide a genuine rule-4
  bug the first time its guess was wrong — worse than an over-report it has to read a doc to clear.
- **Do not** re-file VdSwap as a rule-4 violation, and do not add a fourth registration site for it;
  the real open question here is not ownership but whether `Hooked_VdSwap` being **INERT** (surface
  candidate only, present owned by `sub_824294E0`/`sub_82419E90`) is correct — that is a rendering
  question, untouched by this entry.

---

**F-054 — 2026-09-20 20:20. `build/w38e.log` is not a measurement of anything guest-side, and the
reason is a number: the crash-path recovery F-051/T38.3 deleted fired **616,824 times in 31.7
seconds** and produced **66% of a 1,860,449-line, 175 MB log.** FACT (the counts) · H · P1 — a
mitigation laundering its own fault, caught in the act.** Read while the run was still on disk; no
`src/` file was opened for this entry beyond `grep`.

- **What the log says (one `awk` pass over `w38e.log`, case-insensitive, matching LINES):**
  `VEH: permanently disabled sub_822FA958 (lr=822F44E0)` = **616,824**, and its paired
  `VEH: UILOAD context crash at lr=822F44E0, patch applied, continuing` = **616,824** — i.e. exactly
  1:1, one iteration per fault. `C0000005` = **616,825** (against **1** in `w38c.log`), the
  `VEH[n] (capped)` counter reaches **616825** by the last line at `20:02:44.490`, and the log ends
  mid-loop. First iteration `20:02:12.822` ⇒ **~19,400 fabricated continuations per second**, ~51 µs
  apart, forever. `VEH-NEUTRAL … recovery disabled, declining` = **0** — this run predates the decline
  path (see the provenance bullet).
- **It is a host loop, not guest progress.** The same run reaches the *same* guest frontier as the
  baseline it should be compared against: `GFx` = 9 (w38c: 9), `VdSwap[` = 2 (w38c: 2 at
  `:2858`/`:3143`), `GATE-STAGE` = 6. Nothing after those markers can be read from it, because 2 of
  every 3 lines are this one pair. **Do not use `w38e.log` as a baseline, a delta reference, or a
  "did the change advance the guest" datapoint for anything.** A census on it is only meaningful
  against a fault-line filter — which is the `tools/soak_census.py` lr-split and `VEH_PATHS` rows
  existing for; the whole-file counts here are the case they were built for.
- **Provenance (INFERENCE, from mtimes and the strings, not from a narrative):** those two message
  strings do not exist anywhere in the working tree today (`grep -rn "permanently disabled" src/` →
  no match) but do exist at `git show HEAD:src/boot_host.cpp` → **:977**. `src/boot_host.cpp` mtime
  **20:10**, `build/w38e_build.log` **20:00** (links, `[2/2]`), `build/mcla.exe` **20:10**, first
  `w38f.log` bytes **20:11**. So `w38e` ran the pre-deletion binary, and this entry is the
  measurement of what the deleted path did when it was reachable — the direct quantification of the
  F-051 concern ("provably dead" was true of the *previous* soaks; at the first soak where the site
  is live it is a runaway). It does **not** say the 20:00 `gpu_device.cpp` edit caused the fault at
  `lr=822F44E0`; it says the fault became a loop instead of a stop, which is the whole problem.
- **Why the number matters more than the bug:** 703 was the previous worst case of this shape (the
  `Rip += 4096` fallback, F-051). This is **877×** that, in a fifth of the wall time, and it stayed
  *silent* about itself — the fault it was hiding was one AV. Any future mitigation in this path needs
  a firing counter *and* a cap that logs the cap once, or the next 175 MB soak is a repeat of this.
- **Do not** re-add a `patch applied, continuing` style recovery in this path under any name, and do
  not treat a `C0000005` count as comparable across runs unless the `permanently disabled` /
  `patch applied` / `advancing RIP` rows are all zero in both (they are 0/0/0 in `w38b`, `w38c`).

---

**F-055 — 2026-09-20 20:35. Deleting the two gate stages our own flag-seed tells the guest to skip
made the driver reach **UILOAD** for the first time in the project's history; the one remaining
genuine fault is a **write to guest `0xE0`** through the atArray allocator chain that a deleted
mitigation had been masking since W36.** FACT · H · P0 (frontier-changing) — with a bounded
attribution and one instrumentation limit (new do-not #19).

- **The change** (`src/gpu_device.cpp:1197-1247`, exe 20:00; plus the mitigation deletions in
  `src/boot_host.cpp`, exe 20:10 — both built green, `BUILD_RC=0`, rule 12 checked by mtime): the
  forced driver's stages 1-2 (`sub_823043F8`, `sub_82304348` with `r3=0`, F-050/F-052) and stage 6
  (`sub_821FC008`) are **removed**, because the driver seeds the very flags that make the guest skip
  them — it writes `[0x8288E6F0]=1` (`:1105`) and `[0x82830B14]=0` (`:1113`). Guest truth, raw words
  (rule 3, `tools/ppc_disasm.py 82131008 40`): `0x82131020 lwz r11,4(r29)` (`r29=0x8288E6EC` from
  `0x8213101C addi r29,r11,-6420`) / `cmpli cr6,r11,0` / `beq -> 0x8213103C` skips
  `bl 0x823043F8` + `bl 0x82304348`, whose real `this` is `r3=[0x8288B9AC]` (image bss
  `00000000`); `0x821310C0 lwz r11,2836(r11)` / `beq -> 0x821310D0` skips `bl 0x821FC008`;
  `0x821310D0` re-reads the same flag before the tail `sub_82304398` (which the driver already
  skipped, correctly). Faithful parts kept and improved: the guest seeds both event out-params to -1
  (`0x8213103C li r11,-1` + `stw r11,80(r1)`/`stw r11,84(r1)`) before `bl 0x821C0750` and afterwards
  compares them against `[0x827D7500+44]` (`0x82131064 addi r31,r11,29952`) — the driver never wrote
  the -1, so `sub_821C0750`'s out-param was stack residue; now seeded (`evtOut1`/`evtOut2`, and the
  r4 values `0x82830ACC`/`0x82830AB8` were already faithful to `0x82131050`/`0x82131088`).
- **UILOAD is entered, deterministically.** `build/w38f.log:3885-3890` (same shape at
  `w38e.log:3876-3881`): `event1-821C0750` → `event1-ret r3=00000000` → `event2` →
  `event2-ret r3=00000000` → `UILOAD-enter r3=[82830998]` → **`UILOAD-param r3=C9A24500`**. Those
  four marker lines are first-ever: in every soak before this one the driver died at the null-`this`
  stage 2 (F-052), so `event*-ret`/`UILOAD-enter`/`UILOAD-param` had **0** occurrences in
  `w38b`/`w38c`/`smoke_long*`. Still absent: `UILOAD-ret` ⇒ the fault is inside `sub_822C0980`'s
  chain. This qualifies F-054's "w38e is not a measurement of anything guest-side": its 6 `GATE-STAGE`
  lines *are* the first evidence of the gate passing its event checks — the rest of that log is
  unusable, as F-054 says.
- **Mitigation deletion verified the way F-051 asked** (behaviour census, not a comment):
  `tools/soak_census.py build/w38f.log build/w38c.log` → lines 10,001 vs 9,726; `C0000005` **1 = 1**;
  `VEH` 1 = 1; `VEH-NEUTRAL` 1 = 1; `advancing RIP` / `Nuclear advance` / `patch applied, continuing`
  / `permanently disabled` / `patched sub_82` / `cleared MXCSR` / `UILOAD context` / `parking boot
  worker` / `fallback advance` all **0** in both; `GFx` 9 = 9, `GFX-BLOCK`/`GFX-CTOR`/`GFX-ALLOC`
  unchanged, `UILOAD` 1 = 1, `TOC76` 238 = 238, `INFLATE` 463 = 463, `swfCMD` 2 = 2, `Fatal error`
  1 = 1; moving rows are only ring/service cadence (`rptrWB` 2,088→2,229, `PUT=` 2,086→2,226,
  `PARK-SAMPLE` 78→68) and `CP` is still `put=11 rptrWB=0000`, `DRAW_INDEXED` **0**, `DRAWDISP` **0**
  ⇒ **reaching UILOAD did not yet unstarve the GPU.** The dead `extern std::atomic<bool>
  s_skipSub822FA958` declaration went with the branch; its definition stays in
  `generated/ppc_recomp.49.cpp:18142`, untouched per do-not #1.
- **The surviving fault, honestly labelled:** `w38f.log:4416-4421` — `Param[0]=0x1` (**write**),
  `Param[1]=0x1000000E0` = `g_base + 0xE0` ⇒ a guest **store to guest `0xE0`**;
  `tag=forced-boot-gate` so the registers are the faulting frame's:
  `r1=8EFFF510 lr=822F44E0 r3=828609E0 r4=827D8450 r5=827D8460 r6=828608C0 r7=000000E0 r8=8EFFF5F0
  r9=827E0000 r10=00000010 r13=8F200000` (identical in `w38e.log:4094+` ⇒ deterministic). Raw words
  pin the `lr`: `0x822F44DC bl 0x822FA958` returns to `0x822F44E0`, and **`sub_822FA958` is exactly
  the function the just-deleted mitigation patched with `0xC3`** — `src/gpu_device.cpp:8381` names
  the same thing "the broken atArray allocator chain". So W36's "known crash site" and today's
  residual fault are the *same call*, now unmasked: the mask is off it and it is the frontier.
- **Two negative results bound the attribution.** (i) `sub_822FA958` is a 22-instruction leaf
  (mapping span `0x822FA958`→`0x822FA9B0`, read from `generated/ppc_xenon/ppc_func_mapping.cpp`) whose
  only stores are `stfs f0,10616(r9)`, `stfs f0,4(r7)`, `stfs f0,0x28DC(r6)` with `r9`/`r6` =
  `0x827E0000` globals — none can yield EA `0xE0`. (ii) A scan of the *whole* span of the function
  the dump blames, `sub_822F3BD8` (`0x822F3BD8`-`0x822F4E5F`), for every store form (`stw sth stb
  stwu stfs` + `stwx sthx stbx stdx stfsx stdux`) with `d16==0xE0`, base `r7`, base `r0` or base
  `r10`+`0xD0` returns **zero** candidates. ⇒ the dump's `rip owner=guest 0x822F3BD8 (host+0xF59A)`
  is **not** a guest-PC attribution and the fault is in neither function.
- **Instrumentation limit → do-not #19:** `GuestFnAtHostAddr` uses `RtlLookupFunctionEntry`, which
  answers with the enclosing *unwind* entry; an MSVC `.pdata` range can cover several following
  `__imp__sub_` bodies, so the line names *a* function that contains the RIP in host-image terms and
  bounds nothing. To make it pin a guest PC it must check the next mapping's host start (or resolve
  the printed `rva=` against a link map). Until then: use `lr` (F-052/F-055 both times it was honest,
  because the faulting call's own return address was set by the translator) and treat `rip owner` as
  a weak hint only.
- **Next, in the project's order (rule 1, do-not #9):** do **not** arm `[0x8288E334]` — it *is* the
  allocator table base (`0x822FA96C lwz r11,-7372(r11)` → `[0x8288E334]`, image bss `00000000`, and
  **no `stw` with immediate `0xE334` exists anywhere in `0x82130000`-`0x82800000`**, so it is
  published by a computed store). Note the two register signatures that fit a null base exactly:
  `r7=000000E0` ⇔ `0x822F44E8 addi r7,r1,224` with `r1=0`, `r10=00000010` ⇔ `0x822FA978 add
  r10,r10,r11` with `r11=0`. The hypothesis is that this is *caused by the same lie as the deleted
  stages*: `[0x8288E6F0]=1` claims "init already ran", so the allocator's globals are never built and
  UILOAD's chain stores through `null + 0xE0`. The follow-on step is therefore to stop seeding the
  gate's flags and let `sub_82131008` run its own init (the remainder of **T38.3(e)** — the whole
  forced driver is a stand-in), not to fill in the globals the guest was supposed to build.

---

*Ledger continues with F-056+. (`F-050` was held open for the T38.2b answer and is now filled;
`F-051`/`F-052` were taken by the tooling session out of chronological order, `F-053` supersedes
half of `F-048`, and `F-054` quantifies what `F-051` measured the absence of.) Keep the format; keep
every claim tied to a log line, raw file words or `file:line`.*






---

## Part 3 addendum - 2026-09-20 22:19, INCIDENT + RECONSTRUCTION (this file was zeroed by a volume fault)

**Incident.** Between ~00:54 and 22:15 the E: volume silently lost written data, then refused it: this file,
`docs/LONG_TODO_MASTER.md` and `src/gpu_device.cpp` survived as their old byte sizes filled with NUL and then
became unreadable (`Errno 22` / "No such device"); new files could not be created in `build/` at all
(`WinError 433 - a device which does not exist was specified`); most `.git` objects became unreadable; and
`build/mcla.exe` was left 97,368,576 bytes with **no MZ header** while `ninja_build.bat` printed `BUILD_RC=0`.
**Three rules come out of that and they are project rules now:** (i) `BUILD_RC=0` plus a moved exe mtime is NOT
proof of a valid binary - check the MZ header (extends rule 12); (ii) verify an important write by re-reading it
from a **separate process** - size, mtime, `du` and rc 0 all lie, and never silence a copy's stderr; (iii) an
`fsync`/`Errno 22` error from a tool is a volume alarm, not a retry-me prompt. Everything below was restored
from HEAD `4280c9d` (remote `https://github.com/3bdull4h2008/mcla-pc.git`); an emergency copy of the tree plus
all 155 logs is at `C:\mcla-emergency-20260921-0112`.

**What was learned tonight, reconstructed. Full prose exists only in session transcripts; the surviving soak
logs are the primary evidence.**

- **`sub_821873E8` is `TLS[12]->vtable[+8](TLS[12], 72, 16, 0)`** - a per-thread scratch allocator
  (`generated/ppc_xenon/ppc_recomp.9.cpp:4749`), so T38.3(d)'s fabricated 16 B object + 72 B block has the right
  *shape*. Two candidate causes of `slot12 = 0` were **refuted**: the XEX TLS template
  (`TLS_INFO` at file `0x11D4`: `slot_count=64`, `raw_data_address=0x8294A800`, `data_size=0x94`) is **all
  zeros except slot 14 = `FFFFFFFF`**, so copying it cannot yield slot 12 (Xenia's own
  allocate-zero-fill-then-copy sequence, `xthread.cc:289-321`, gives the same zeros); and `_xstart`
  (`0x821322B8`, agreed by the XEX optional header and the PE `AddressOfEntryPoint`) **is** called
  (`w38q.log:131`). **The standing defect:** `src/kernel/guest_thread.cpp:9-30` already builds real per-thread
  TLS (`TLS_SIZE = 0x100` = exactly the 64 slots the XEX declares), but `src/boot_host.cpp:260-286` substitutes
  a fixed block at `0x8F200000` with **one** of 64 slots filled, aliased by **25** hard-set
  `r13 = 0x8F200000` sites, and `src/gpu_device.cpp:1071-1090` writes a fabricated allocator into the shared
  `tlsTable + 12`.
- **The `{handler, msgid}` table is real; its walker is not a literal.** Confirmed pairs with ascending handler
  VAs at `0x82102A00` (`82130048/40005703`, `821301A8/40001403`, `821301F8/40001805`, `82131008/40003B03`,
  `821310F8/40002A03`) and `0x8210DA98` (`822F38C0/40001503`, `822F3BD8/4004A207`); the region **is** the PE
  `EXCEPTION` directory (`VA 0x82102A00`, size `0x27338` = 12,902 eight-byte records). A whole-corpus scan of
  all 176 TUs for `lis` bases overlapping that range found **14 sites in 11 functions, every one landing in the
  `0x82128xxx` tail - none in the pair area**, so "find the `lis/addi` that materialises a table base" is the
  wrong method and **T41.3 step 2 is retired**. `sub_823E5B70` is a reflection-descriptor builder
  (`sub_823DA950(&r1[80], 0x820EDEF0, 32)`, tests bit 3 of `table[0]`, stores the constant `0x01004000`), not a
  message registrar - false lead, closed. `RtlImageXexHeaderField` is a host stub
  (`src/kernel/imports.cpp:1377`) with **5** guest call sites (`ppc_recomp.0.cpp:7206`, `.80:9435`,
  `.81:4532/9384/9703`) that fired **0** times: a known gap, not the blocker.
- **The shipped improvement and the plateau.** Deleting the `star_glow` -> `rage_im` substitution (the
  `AFB76-FALLBACK` branch, whose own comment said it existed "so the guest's own compare passes on real
  content") took **`C0000005` 2 -> 0** - the first soak in the project with no access violation - plus parked
  thread 1 -> 0 and `[error]` 51 -> 41, and the guest got back as far as **`swfCMD::Fixup - unknown type`**
  (`swfCMD` 0 -> 2). Why the substitution could never have worked: `star_glow.fxc` is genuinely absent from the
  15 embedded `fxl_final/*` bodies (names are full archive paths read from the image - `rage_im` 5258,
  `fastmipmap` 5406, `spotlightfog` 10331, `rage_bink` 3187, `rmptfx_default` 3612, `rmptfx_litsprite` 8133,
  2 x `dcl` 138, `atmoscatt_clouds` 32280, `perlinnoise` 5713, `rmptfx_collision` 4564, `shadowcollector` 5112,
  `shadowdepth` 4347, `blendshadows` 18323, `rage_postfx` 48), **none contains any `star_glow` key name**, and
  `rage_im` necessarily contains `drawblit` at `buf+0x1365` - which is the very fatal it then triggered.
  Corrected by raw words: `r4 = 8200934C` is the string **`drawblit`**, not `draw_starglow` (`0x82040EE0`), so
  the init never reached its first real star_glow lookup.
- **Measurement rule, learned by running controls.** Four soaks across three builds - including two runs of one
  exe and a revert-and-rebuild - show **per-marker counts are bit-reproducible** (`C0000005` 0, `GFx` 3,
  `Fatal error` 2, `PRESENT` 68, `DRAW_INDEXED` 0, `swfCMD` 2, `GETDEV` 185, `CP-DRAW` 24, `MSGBISECT` 35,
  `PKG-SUBST` 19) while **`host short-circuit lines` swings 98 / 166 / 172 / 176 on identical source**
  (+-78; `[warning]` +-431, `INFLATE` +-116). Aggregate mitigation totals are therefore a noisy gauge and
  cannot carry a causal claim - which retroactively weakens the "177 -> 96" headline. Two needle hazards
  surfaced the same way: `UILOAD 0 -> 1` was the substring inside the host's own
  `W34-NOGFX ... UILOAD/EF220 never armed` line, and a needle list containing the empty string matches every
  padded dword (`0x00000000`), which fabricated a "113 hash hits" reading.
- **The archive, and the way forward.** A `.list` TOC quad behaves as `{_, expanded, position, flag|stored}`:
  six members give expanded 260/368/1246/1108/496/575 against stored 126/188/452/460/132/236 (1.96-3.76x),
  bit 30 set, positions all inside the `0xCFFE9..0x35A000` region. Context: **1,617** RSC5 packages
  (`05435352` header, `0FF512EF` at `+0xC`) cover **70.6 %** of the 2,130,739,200-byte archive, and the two at
  `0x60000`/`0xA0000` are exactly what `MclaPreferredPkgOffForPath` hard-codes - which is why 19 of 31 serves
  work and the 12 that fail are precisely the six lists served twice. **Serving the stored length instead of the
  expanded one changed nothing at all**: both readings seek to the same position, so that experiment never
  varied the variable it was built to test - the *position* is the unknown, and T41.3e4 is closed as refuted.
  Codec is **LZX** (`XMemDecompress` = `sub_8244FF20`, 22 calls all `ret=0` on 7 MB bodies), so the host must
  not grow a decoder; it must supply right bytes at a right position. **Breakthrough:** `w[0]` of a decrypted
  TOC entry is `GtaO(leaf_filename)` - Jenkins one-at-a-time, `h+=c; h+=h<<10; h^=h>>6`, then `h+=h<<3;
  h^=h>>11; h+=h<<15` - matched on five `preload.list` entries (`0DB1C876`) and on `globaltex.list`
  (`3D9B8154`). There is **no plaintext TOC** (12 known name-hashes x BE/LE across the whole archive = 8 hits
  against ~3 expected by chance), so the route is to match hashes inside the **guest's already-decrypted** TOC
  in guest memory; the census that does this is compile-verified and preserved at
  `C:\mcla-emergency-20260921-0112\T41_3e5_census_snippet.txt`. The recovered
  `docs/MCLA_RPF3_Technical_Reference.txt` - lost earlier in the `5fbc08e` docs purge while still cited by
  `src/fs/vfs_rpf.h:16` - supplies §5 layout, §7 "compressed iff the two sizes differ", §8 LZX, §9 AES-CBC TOC,
  §10 the hashes, and thereby exposes the false premise in that VFS comment: it assumes all member data is
  STORED.
- **New suspect on the UI path, from the safed logs (`w38w.log:6116-6132`).** The SWF place-walk census shows
  the fatal node differing from its healthy siblings **in the kind of pointer it holds**: healthy
  `node=B7B41000 type=00 [0]=8208521C` and `node=B7982758 type=00 [0]=820880BC` point into the **image**
  (`0x82xxxxxx`), while the fatal one is `node=B7B6D9B4 type=B7 [0]=B7982758` - a **guest-heap** pointer - and it
  sits among `node=CDCDCDCD`, `7CDCB2EA`, `4F91EB3F` (debug-fill / garbage). So
  `swfCMD::Fixup - unknown type 0xB7` is probably **not** an unsupported tag type - which is what T38.4 assumed
  when it asked which types the walker handles - but a partly-uninitialised chain being walked, the same
  content-corruption class as the shader path. Cheap test on the next soak: print `[0] [4] [8]` for every node
  visited and classify each pointer as image / host-heap / guest-heap / debug-fill; if the `type=00` nodes are
  the image-pointing ones, the defect is upstream of `swfCMD`.
- **Unchanged blockers, and what is NOT achieved.** `UILOAD` never runs in substance: the forced gate's only
  trigger was the `FIX-821873E8` TLSDEAD branch, which no longer fires, so `sub_82131008` is dispatched by
  nobody - re-arm it through the `(handler,msgid)` table or delete the stand-in. No guest GFx loader,
  `DRAW_INDEXED` 0, no authored pixels, no input, no audio. **Next baseline:
  `C:\mcla-emergency-20260921-0112\logs\w38w.log`** - the copies under E:`\build` may be corrupt.


---

## Part 3 addendum — session of 2026-09-21 (shell clock), on the relocated C: working copy

**F-069 — 2026-09-20 23:57. Why the `.list` bodies are garbage, measured offline: a `.list` TOC `w[2]` is
**not page-aligned and is not a package head**, and the host seeks to it as a raw file offset — so it can
only ever hand the guest compressed bytes. The host's own comment on that path ("Lists never take a
package substitute (their name bodies work)") is therefore false, and F-068's six-for-six result is its
measurement.** FACT · C/E · P0. Offline scan of `build/game_data/xarchive_cache.rpf` (2,130,739,200 B =
`0x7F008000`) + `src/gpu_device.cpp:506-575`. No build, no soak; F-068's soak numbers are the on-line
half. Corrects nothing in F-068, supplies its mechanism.

- **(1) What a package head actually is.** `05435352` (`CSR`) occurs **1,617** times, always 4 KB
  aligned, each with `0FF512EF` at `+0xC` and a count at `+0x04`. First two, verbatim:
  `0x60000: 05435352 00000009 DC2C0810 0FF512EF 0003AB93 08EADF20 E60C7BCC 00500000`
  `0xA0000: 05435352 0000001B D454283D 0FF512EF 0002FFC9 10F8B820 4940954D 00506200`
  ⇒ `+0x04` entry count (9, 27), `+0x10` payload size (240,531 / 196,553), `+0x1C` = `0x50000`-class
  window size. **These are the two addresses `MclaPreferredPkgOffForPath` hard-codes** (`0x60000`,
  `0xA0000`, F-057(5)/F-058) — so that hard-code is pointing at real containers, which is why the UI
  `.xsf`/`.xtd` route works at all.
- **(2) The `.list` words are a different kind of value.** `shaders/effects/preload.list` `w=[0DB1C876
  00000170 00304E12 400000BC]` and `shaders/ui/preload.list` `w=[0DB1C876 00000104 001DD11C 4000007E]`
  (`w38t.log:3723`, `:3299`). `w[1]` = 368 / 260 = the exact served length (so `w[1]` is the
  **uncompressed** size) and `w[3]&0xFFFF` = 188 / 126 = **compressed** size (~2× shrink) with bit 30 set
  — i.e. these members are stored compressed, and their `w[2]` (`0x304E12`, `0x1DD11C`) is **not** 4 KB
  aligned and **not** one of the 1,617 heads. Both lie inside the *file span* of the container at
  `0xA0000` (`0xA0000`..`0x35A000`), past its `+0x10` payload end.
- **(3) The mechanism of the defect.** `src/gpu_device.cpp` serves the list by seeking to `w[2]` as a
  file offset and copying `w[1]` bytes (`serveOff = offs[c]`, `XSF-HOSTSERVE … off=00304E12`), and then
  deliberately **skips any package/inflate handling for it**: `isList = strstr(path,".list") || "globaltex"
  || "preload"` gates out `PKG-SUBST` with the comment *"their name bodies work"*. Compressed bytes cannot
  be a plaintext name list, so that comment is the bug's statement of belief and F-068(1) is its refutation.
  F-068(3)'s bit-30 guess is **not** the mechanism: bit 30 sits in `w[3]` (the compressed-size/flag word),
  and `XSF-OPEN-GATE` sets it in `w[2]` for the guest's `Open` gate (`00304E12 -> 40304E12`) — the serve
  path masks it back off, so the served bytes are what a raw seek yields, not a mis-decoded flag.
- **(4) Next measurement, and it is a small one.** The address space of `w[2]` for a *compressed member*
  is unresolved offline and resolving it is a **decode question, not a seek question**: read the guest's
  own open/read chain for these members — `XSF-OPEN lr=821CCFF0` → `TOC76 lr=821CCED0` → the
  `sub_821BC380`/`821BC868` inflate worker (`INFLATE #1 st=006D8F20 in=32768 out=8192 magic=05435352`,
  `w38t.log:2231`) — and answer what the guest computes `w[2]` against (a member-table base inside the
  inflated stream, most likely, given `w[1]`/`w[3]` are sizes). `build/cache/mcla_pe.bin` +
  `tools/ppc_disasm.py` are operable; `ida-pro` must be attached to the live `:8745` RPC, not re-launched.
  If the answer is "inflate the containing package, then slice at `w[2]`-within-stream", the tree already
  has every part (working inflater, `MclaLoadPkgWindow`, `PackageSizeAt`) and this closes the whole
  preload family, not just `star_glow`.
- **Consequence.** T41.3e's first sub-step is now (4), and it is a read-only decode — do it before any
  change to a serve path. `isList`'s comment is the thing to delete once (4) answers; until then every
  `.list` the guest reads is compressed bytes, which is why nothing preloads and why the shader fatal
  fires for `star_glow` specifically (F-067(3)).


- **(5) Offline base-guessing is exhausted — recorded so nobody re-probes it.** The RPF header is
  `RPF3 00D80500 7B5D0000 00000000` + zeros (`+0x10` = `FFFFFFFF`), giving no usable `data_start`; and
  for each of the two member offsets, a ±`0x800` window contains **neither** `0FF512EF` **nor**
  `05435352`, while candidate bases `0x1000`/`0x2000`/`0x10000`/`0x20000`/`0x40000` put the computed file
  position on high-entropy bytes and `0x4000`/`0x8000` land in a **zero-padded** region. Combined with the
  whole-archive scans (0 plaintext hits for `fxl_final`, `star_glow`, `.fxc` and even
  `resources/ui/legals`, F-066(7)), the conclusions that survive are: `.list` members are
  **compressed** (`w[1]` = 368/260 uncompressed vs `w[3]&0xFFFF` = 188/126, ~2×, and `w[3]` bit 30 set),
  and their `w[2]` is **not** a file-linear seek value. So the answer can only come from the guest's own
  TOC→seek arithmetic in (4) — and the fix shape is inflate-then-slice, not another offset constant.
  `tools/probe_toc_off_w18.py` is a prior attempt at exactly this; check it before writing a fourth probe.

**F-070 — 2026-09-20 21:01. The `.list` member offsets point into a **gap between RSC5 packages**, and the
reason the UI packages work is now measured: `PKG-SUBST` substitutes a *real* container for them and has
nothing to substitute for a list. This also kills the obvious cheap fix before anyone spends a soak on
it.** FACT + PREDICTED-NO-OP · C/E · P0. Offline computation over `xarchive_cache.rpf` (1,617 RSC5
headers, payload length read from each header's `+0x10`) + `build/w38t.log`. Follows F-069; same tree.

- **(1) Coverage, measured.** The 1,617 RSC5 packages' spans cover **1,504,450,533 of 2,130,739,200
  bytes = 70.6 %** of the archive. So most of the file is package data, and the rest is gaps of
  non-package content.
- **(2) Both sampled list members sit in the SAME gap.** Package `0x60000` = 240,531 B ⇒ ends `0x9BAB3`;
  package `0xA0000` = 196,553 B ⇒ ends **`0xCFFE9`**; the next package head is `0x35A000`. The gap
  `0xCFFE9..0x35A000` is **2,661,399 B**, and it contains both
  `shaders/ui/preload.list w[2]=0x1DD11C` and `shaders/effects/preload.list w[2]=0x304E12`. It is the
  second-largest gap in the archive. So `w[2]` for a `.list` is not "a byte inside a package" either —
  it addresses the non-package region, whose bytes are high-entropy with **no** `05435352`/`0FF512EF`
  within ±`0x800` (F-069(5)) and no plaintext anywhere in the whole file (F-066(7)).
- **(3) Why the UI path works and the list path cannot, in one line each.** `resources/ui/*.xsf` and
  `meshtextures.xtd`: `PKG-SUBST` fires (**19** of the 31 `XSF-HOSTSERVE` lines have `pkgSubst!=0`),
  serving a window that *begins with a valid RSC5 header* (`0x60000`/`0xA0000`, confirmed INSIDE a real
  package at (1)) — the guest's own container reader then does the work. The 12 lines with
  `pkgSubst=00000000` are **exactly** the 6 `.list` files ×2 serves, i.e. 100 % of list serves are the
  raw gap read, and 0 % carry any container magic.
- **(4) PREDICTED NO-OP — do not spend a soak removing `isList`.** Dropping the `isList` exclusion at
  `src/gpu_device.cpp:~517` would let lists take `pkgOff = pathPkg ? pathPkg : tocPkg`, but for a list
  `MclaPreferredPkgOffForPath` returns 0 (paths are `shaders/…`, not `resources/ui/…`), so it falls to
  `MclaPkgOffFromTocW2(w[2])` = `0x304E12 & ~0xFFF` = `0x304000`, which is inside the gap and has no
  header — and `PKG-SUBST`'s own guard (`pbe == 0x05435352 || pbe == 0x0FF512EF`) then rejects it. The
  change compiles, logs nothing new, and cannot alter a byte. Stated as a prediction, to be falsified by
  whoever runs it.
- **(5) What actually has to be answered, and where to look.** How does the guest fetch a *non-package*
  member at all? The answer is in its own archive-read path, not in the file: `INFLATE #1 st=006D8F20
  in=32768 out=8192 consumed=0 magic=05435352 lr=821BC380 … chain[ f0=821BC940 … ]`
  (`w38t.log:2231`) — so **`sub_821BC380` / `sub_821BC940`** are the inflate-driver frames, and the
  function that turns a TOC entry into a read request upstream of them is the one that knows whether
  `w[2]` is package-relative, gap-relative, or a logical-cluster index. Decode those two with IDA
  attached to the live `:8745` RPC (**do not** launch `ida-bridge.py`, it `taskkill`s the session) and
  `mcla_pe.bin` words, then re-derive the offset from the guest's own arithmetic rather than from a
  base guess. Honest alternative outcome, which F-069(5) already makes likely: the gap region is
  encrypted and there is no host-side route to it at all — in which case the finding is that
  **`.list`/non-package members need the guest's own key path**, and the substitute should be deleted
  rather than extended.


### F-077 — The build moved to `C:\mcla-pc` and the first post-incident soak reproduces the plateau, but `AFB76` is never reached and **T41.3f was applied to the wrong branch**.

**Claim 1 — measurement is possible again, off E:.** `E:\mcla pcuild` never accepted a new file again
(create "succeeds", file absent on fresh-process read-back), so the tree was copied to **`C:\mcla-pc`**
(sha256-verified; `src docs tools config cmake generated third_party .qoder` + the three `.research` trees
`CMakeLists.txt` compiles; `.research/xenia` and `generated/default` are **not** compiled, so their dead
files are harmless) and 5.5 GB of rpfs/`default.xex`/`.bik` were copied to `build\game_data`.
`cmake -S . -B build -G Ninja` configured in 12.1 s and `ninja` completed `[227/227] Linking CXX executable
mcla.exe` with **rc 0**; `build/mcla.exe` is 56,825,856 B with a valid `MZ` (rule 12 satisfied). Two
runtime gaps had to be closed: `E:\mcla pcuild\SDL3.dll` is itself poisoned (`Errno 22`), so
`SDL3.dll` was taken from `third_party/SDL3/SDL3-3.2.6/lib/x64/` (2,450,944 B, identical size); and
`src/gpu_device.cpp` + `src/fs/vfs_rpf.h` became unreadable on E: **during** the sync, so they were
reconstructed on C: from the saved HEAD blob + the verified 2-hunk patch (499,855 B, `AFB76-MISS-HONEST`
and `hostServeList` markers present). Provenance caveat: `generated/ppc_xenon/ppc_recomp.30.cpp` and
`.163.cpp` on C: predate E:'s last state (E: refused to read them), so this tree is **not** byte-identical
to the one that produced `w38w.log`.

**Claim 2 — the soak plateaus at the same known place, and the single AV is F-056's site, not a new one.**
`C:\mcla-pcuild\w41a.log` (18,907 lines / 2,199,122 B, `BOOT_RC=124` = survived the 120 s timeout) vs
baseline `w38w.log` (11,286 lines): `PRESENT` 73 vs 68, `GLOBTEX` 98 = 98, `PKG-SUBST` 19 = 19,
`CP-DRAW` 24 = 24, `UILOAD` 1 = 1, `swfCMD` 2 = 2, `DRAW_INDEXED` 0 = 0, `Fatal` 41 vs 57,
`C0000005` **1 vs 0**. The one AV (`w41a.log:4460-4470`) is `rip owner=guest 0x82304348 (host+0xDC)` with
`r7=FFFFFFFF`, `r8=821873E8` and the sticky `lr=822FBC28` — i.e. exactly the raw-`simde_mm_store_si128`
site named in F-056, and it lands at `INFLATE #116`/`W29-RSC5-SPIN`, *before* the stage where the baseline's
three `AFB76` star_glow lookups happen (`AFB76-MISS-HONEST` 0 here vs 3 in `w38w.log`). The most probable
cause of reaching the AV earlier is not my two edits but the peer session's **destroyed** uncommitted work —
it included the `D3070` guard deletion — which is absent from *both* trees; `tools/soak_census.py` confirms
this by printing `MARKER NOT IN SRC` for `D3070-RUN`, `GATE-STACK`, `GATE-WAIT`, `MSGBISECT`, `MSGCHAIN`.
**Consequence: `w41a.log` is the new baseline for the C: tree.** Do not A/B against `w38w.log` — the source
provenance differs in at least three respects (2 stale TUs, lost peer instrumentation, my 2 edits).

**Claim 3 — T41.3f is refuted as ineffective, and the real `.list` serving site is now named.** The gate I
added (`src/gpu_device.cpp:11030-11034`, `hostServeList` + `if (uiBody && !hostServeList)`) did **not** stop
the six name-list paths from being host-served: `w41a.log` still shows, for
`textures/global/cars/globaltex.list`, `TOC76-XSF … [3D9B8154 0000023F 000D0000 400000EC]
openGateBit30=0` then `XSF-OPEN #20 … ret=0` then **`XSF-HOSTSERVE … off=000D0000 size=575`** and
**`XSF-POSTOPEN-SERVE … buf=C9C9EE80 size=575 dev=C60AC100 handle=0`**. So the boot-gate `uiBody` branch is
not the server: the serving happens in `HostServeUiBody` (`src/gpu_device.cpp:568`) reached from the
`XSF-POSTOPEN-SERVE` site (`:10400`), plus `XSF-OPEN-GATE` at `:10353`. Note the decoded TOC words agree
with the F-073 reading: `w[1]=0x23F=575` is the **stored** (compressed) size and `w[2]=0x000D0000` the
offset, and we hand the guest 575 raw stored bytes as if they were the member body.

**Action (queued as T41.3g):** gate `HostServeUiBody`/`XSF-POSTOPEN-SERVE` on the same
`*.list`/`preload`/`globaltex` predicate (and revert the ineffective `:11030` gate so only one mechanism
exists), then re-soak and check whether the guest's own read path either (a) produces ASCII names in
`GLOBTEX-BODY`, or (b) fails visibly — both outcomes are decisive for the encrypted-vs-keyless question.
Until then T41.3f is **VOID as a no-op**, not as a wrong theory: the "position and bytes are host-chosen"
analysis stands, only the edit missed its target.


### F-078 — `GLOBTEX` was never a guest event, and the `*.list` member offset is wrong (proved by a controlled A/B on the C: tree).

**Experiment.** T41.3g added one gate in `HostServeUiBody` (`src/gpu_device.cpp:473-485`, marker
`HOSTSERVE-BLOCKED … (T41.3g/F-077)`) so list-class paths are no longer host-served, and deleted the
no-op `:11030` gate. Incremental rebuild (`NINJA_RC=0`, `[2/2] Linking`, `mcla.exe` 56,825,856 B,
mtime moved to 02:01:54, `MZ` verified from a fresh process), 120 s soak into
`C:\mcla-pc\build\w41b.log` (18,873 lines), baseline `w41a.log` — **same source except that one gate**.

**Result — behaviour is isolated to the intended paths.** `HOSTSERVE-BLOCKED` 0 → 12, `XSF-HOSTSERVE`
31 → 19 (exactly the 12 blocked), `XSF-POSTOPEN-SERVE` 31 = 31 (now `buf=00000000 size=0` for lists).
Everything else identical: `C0000005` 1 = 1, `GFx` 9 = 9, `GFX-CTOR` 4 = 4, `PRESENT` 73 = 73,
`CP-DRAW` 24 = 24, `DRAW_INDEXED` 0 = 0, `Fatal` 41 = 41, `swfCMD` 2 = 2, `REBASE-POISON` 3 = 3.

**Finding 1 — `GLOBTEX` 98 → 2 is a do-not #20 artifact, retro-voiding every past use of it.** The 98
lines were produced while *we* walked the buffer we had just served; with the serve blocked the guest's
own read yields `GLOBTEX-BOOT inserted=0 noneObj=C8A07D00` and `GLOBTEX-SERVE-DONE lists=0 inserted=0`.
So "the guest received 98 global-texture names" was never true — no session's claim may cite that counter
as a guest event. The boot is not worse without it (all markers above unchanged), so the substitution was
cosmetic.

**Finding 2 — the `*.list` member position we compute is wrong, not merely undecoded.** For
`textures/global/cars/globaltex.list` the TOC words are `[3D9B8154 0000023F 000D0000 400000EC]` and we
serve 575 B from `0x000D0000`, whose first word is `75914D4E` — no known container magic. The `.xsf`
serves from the *same* machinery (`off=000A0000 size=32768`) all start with `05435352` (**RSC5**), i.e. the
reader and the archive are fine and the `.xsf` offsets are right. So the difference is per-entry, not
global: the list entries' offset field is being read from the wrong place (or those members really are
encrypted — F-076(2) already proved the TOC is AES-CBC).

**Finding 3 — a second stand-in is on this path and must be removed before the offset question can be
settled.** `XSF-OPEN-GATE path='…globaltex.list' entry=C60F79C0 +8 000D0000 -> 400D0000 (set bit30 so
Open proceeds)` (`src/gpu_device.cpp:10353`) ORs bit 30 into **`entry+8`** — but on the decoded word set
above, `+8` holds `000D0000`, the value we ourselves use as the *offset*. The host is therefore both
fabricating the guest's open-gate flag and consuming the same dword as a file offset, which cannot both be
true: at most one of the two readings matches the real entry layout.

**Action (T41.3h).** Delete the `XSF-OPEN-GATE` bit-30 write and the list-branch of `HostServeUiBody`
together, and dump the **raw 32 bytes of the decrypted TOC entry** (`TOC76-XSF` already prints 4 words —
print 8, with `entry+0/4/8/C` labelled) for one `.xsf` and one `.list`, so the entry layout is read from
guest-visible bytes instead of guessed. This is the last measurement that does not require a new key.


### F-079 — The `XSF-OPEN-GATE` stand-in writes bit 30 into the *offset* dword, and the guest then reads our fabrication back as its own "loaded" flag.

**Evidence (read-only dump, no behaviour change).** `w41c.log` (`TOC76-LAYOUT`, 78 lines, `NINJA_RC=0`,
exe 56,828,928 B `MZ`, boot markers all identical to `w41b`: `PRESENT` 73, `CP-DRAW` 24, `C0000005` 1,
`GLOBTEX` 2, `HOSTSERVE-BLOCKED` 12) shows the *same* entry twice with exactly one differing bit:

```
#57 globaltex.list  entry=C60F79C0 +4=[0000023F 000D0000 400000EC ...]   <- before our write
#58 globaltex.list  entry=C60F79C0 +4=[0000023F 400D0000 400000EC ...]   <- after our write
#67 preload.list    entry=C60F7D10 +4=[00000104 001DD11C 4000007E ...]
#68 preload.list    entry=C60F7D10 +4=[00000104 401DD11C 4000007E ...]
```

**What it means.** `src/gpu_device.cpp:10353` (`XSF-OPEN-GATE … +8 000D0000 -> 400D0000 (set bit30 so Open
proceeds)`) ORs bit 30 into the dword the host *also* uses as the member offset. The guest's second TOC
lookup therefore sees a flag **we** fabricated, and F-076's "proceeds when bit 30 of [entry+8] is set" was
measuring our own write — the gate was never the guest's state. So the whole `Open gate (CCEA0)` reading is
void as an account of guest behaviour (its raw words stand).

**Corollary, and the reason `*.list` bodies were never decodable.** `+8` is not a pure byte offset: the good
`.xsf`/`.xtd` entries carry non-zero low bits — `meshtextures.xtd` `00060009`, `legals.xsf` `000A001B`,
`globaltex.list` `000D0000` — so the field packs offset + flags/low-bits, and our serve masks to
`0x…0000` (`off=000A0000 size=32768` yields RSC5 `05435352` for `.xsf`, but `0x000D0000`/575 B yields
`75914D4E` for the list). `+4` (575, 0x104) is the stored size and `+C` (`4C84317A`, `6D1F986C`) looks like
a per-entry key/hash, not a name pointer.

**Next measurement (the second half of T41.3h, now precisely specified).** Make `XSF-OPEN-GATE` log-only
(delete the write), so the guest's *own* flag transitions become observable: if the guest sets bit 30 (or
a different bit) itself after a real read, the entry layout is decoded from guest bytes; if the entry never
changes and `Open` returns non-zero, the archived member region is opaque without a key and this is a
crypto problem, not an offset problem. Both outcomes are decisive. Keep T41.3g in place.


### F-080 — Deleting the bit-30 write changes nothing and `Open` returns 0 with the bit clear: the "Open gate" premise is refuted, so the `*.list` blocker is the **body read**, not the open.

**Experiment.** Commented out the only write at `src/gpu_device.cpp:10378`
(`(void)memR.WriteU32BE(it->second.entry + 8, e8 | 0x40000000u);`, log renamed
`XSF-OPEN-GATE-SKIPPED`), rebuilt (`NINJA_RC=0`, zero error lines, exe 56,828,928 B, mtime 02:10 = moved),
soaked `C:\mcla-pc\build\w41d.log`, compared with `w41c.log` (same source apart from that write).

**Result — behaviour identical, so the mitigation was doing nothing.** `PRESENT` 73 = 73, `GFx` 9 = 9,
`CP-DRAW` 24 = 24, `C0000005` 1 = 1, `Fatal error` 1 = 1, `DRAW_INDEXED` 0 = 0, `GLOBTEX` 2 = 2,
`TOC76-LAYOUT` 78 = 78; only `XSF-OPEN` 57 → 64 (guest re-tries 7 more opens) and the gate branch fires 21×
instead of 8× (nothing sets the bit any more).

**Decisive sub-measurement.** In `w41c.log` two consecutive lookups of the same entry differed by exactly
one bit (`000D0000` → `400D0000`); in `w41d.log` `TOC76-LAYOUT` #57 and #58 are **byte-identical**
(`+4=[0000023F 000D0000 400000EC 4C84317A]` twice) — **the guest never sets bit 30**, and
`XSF-OPEN … globaltex.list ret=0` / `preload.list ret=0` succeed with it clear. F-076's
"Open proceeds when bit 30 of [entry+8] is set" was therefore measuring the host's own write
(do-not #20 class), and `[entry+8]`'s low bits (`00060009`, `000A001B`) are not a gate field either.

**Consequence.** The `.list` failure is *downstream of* open: the guest opens successfully, asks for the
body, and gets nothing usable (`GLOBTEX-BOOT inserted=0`, `GLOBTEX-SERVE-DONE lists=0`). The next census is
the read path on an already-open handle — **T41.3i**. Three stand-ins are now removed on this tree, each
measured behaviour-neutral: the `rage_im` substitution for `star_glow` (T41.3d), the host serve of `*.list`
bodies (T41.3g), and the bit-30 open-gate write (this finding). Baseline chain: `w41a` → `w41b` → `w41c` →
`w41d`.


### F-081 — T40.6 step 3 landed: the CP now models a Xenos register file, and decoding it **raises `CP-DRAW` from 24 to 52** — the old `default:` advance was desyncing the stream at `0x21 REG_RMW`.

**Change (`src/gpu_cp.cpp`, T40.6 step 3).** Added a 13-bit register file
(`g_xenosReg[0x2000]` + `CpRegPeek/CpRegPoke`, mirrored into `g_regShadow` where indices alias the MMIO
window), routed the **Type-0 payload dwords that were previously logged and discarded** into it (linear
reads on the IB path at `:541`, `ReadRingU32((rptr+1+i)%cap)` on the circular ring path at `:859`), and
implemented the two packets that had no handler: `0x21 PM4_REG_RMW` (xenia `command_processor.cc:927-948`:
`info/and_mask/or_mask`, `value &= reg|imm`, `value |= reg|imm`, write back to `info & 0x1FFF`) and
`0x2B PM4_IM_LOAD_IMMEDIATE` (`:1135-1161`: `type`, `start<<16|size_dwords`, inline microcode).
`CP-DRAW-STATE` reports the file at each draw. Build `NINJA_RC=0`, `mcla.exe` 56,839,168 B mtime 02:25.

**Measurement — `w41g.log` (20,071 lines) vs `w41d.log`, one variable (the register file).**
`CP-REG-T0` 0 → **1,171**, `CP-REG-RMW` 0 → 5, `CP-IM-LOAD` 0 → 8, `CP-DRAW-STATE` 0 → 28, and
**`CP-DRAW` 24 → 52**. Boot state is otherwise unchanged: `PRESENT` 73 = 73, `GFx` 9 = 9, `C0000005` 1 = 1,
`Fatal error` 1 = 1, and `DRAW_INDEXED` 0 = 0 (state is captured; nothing renders yet).

**Why the draw count moved — a new root cause.** `0x21` and `0x2B` used to fall into
`LogType3Unhandled`, which advances `count + 1`; the correct `REG_RMW` consumption is **4 dwords**
(header + 3 payload), so every `REG_RMW` desynchronised the packet stream and the rest of that buffer
decoded as junk. Fixing the consumption length is what exposed 28 more real draws. This retro-invalidates
the "the guest submits 24 draws" reading of F-059: **the true count is at least 52**.

**First real register evidence at a draw** (`w41g.log`):
`CP-DRAW-STATE #1 initiator=00010081 writes=31 r08B=0 r08C=0 r0DD=0 r0D2=0 r0A2=0 r1DC=00020037
r1DD=071D8380` — `initiator=0x00010081` decodes as `prim=1`, `source_select=2 (kAutoIndex)`, `numIdx=1`,
and `r1DD=0x071D8380` is a **physical address inside the same 0x071Dxxxx window as the CP ring/writeback**
(`C71D82BC`, F-057(1)), i.e. the guest really programs buffer addresses through Type-0 and the file now
retains them. `CP-IM-LOAD #1 shader_type=0 size_dwords=24` and `#2 shader_type=1 size_dwords=9` are the
first shader uploads ever observed by this CP (type 0 = vertex, 1 = pixel).

**Next (T40.6 step 4).** Render: bind the register-derived state to the D3D12 path — the existing
`DRAW_INDEXED` producer (`src/gpu_device.cpp:1793-1803`) is starved because it hangs off the host-side
`sub_82420BA8` chain; feed it from `CP-DRAW`/`CP-DRAW-STATE` instead (index buffer via `r1DC/r1DD`, vertex
decl via the shader program registers), and name the register indices from the spec rather than the probe
list used here (which was chosen to be *observable*, not to be semantically labelled — do not cite
`r08B/r0DD/...` as named registers).

**Reproducibility check (F-081, same binary re-soaked).** `w41h.log` (19,638 lines, built tree unchanged,
exe mtime 02:25) vs `w41g.log`: `CP-DRAW` **52 = 52**, `CP-REG-T0` **1,171 = 1,171**, `CP-IM-LOAD` **8 = 8**,
`CP-DRAW-STATE` **28 = 28**, `GFx` 9 = 9, `C0000005` 1 = 1, `Fatal error` 1 = 1; only `PRESENT` 72 vs 73,
consistent with the ±1-ish timing swing on that counter (F-072). So the register-file draw count is a
reproducible measurement, not a one-run artifact. Baseline for the next task = **`w41g.log`** (or `w41h`).


### F-082 — Re-applying the peer's F-063 `D3070` clause removal gives the **first zero-AV soak on this tree** (`C0000005` 1 → 0) and moves the stop one step earlier, onto a guest **fatal** instead.

**Change.** `(ctx.r4.u32 & 0x8000u) != 0` deleted from the `PPC_FUNC(sub_821D3070)` skip condition
(`src/gpu_device.cpp:11375-11378`); the null-`obj`/null-`+8` clauses are kept. Bit 15 of `r4` is a flag the
`8C760` magic-accept path ORs in, not a size — so skipping on it starved the shader's own 32 KB buffer.
This had been a documented fix (F-063) whose **code was destroyed** by the E: volume failure at ~00:54;
only the prose in `HANDOFF_NEXT_AGENT.md` survived, and `soak_census.py`'s `MARKER NOT IN SRC: D3070-RUN`
was the tell that it was missing from `src/`. Build `NINJA_RC=0`, exe mtime 02:32, soak `w41i.log`.

**Measurement vs `w41g.log` (one clause).** `C0000005` **1 → 0**, `D3070-SKIP` 1 → 0,
`CP-DRAW` 52 = 52, `CP-REG-T0` 1,171 = 1,171, `PRESENT` 73 = 73, `DRAW_INDEXED` 0 = 0. But
`GFx` 9 → 3, `GFX-CTOR` 4 → 0, `TSLAB-OWNER` 73 → 15, `Fatal error` 1 → 2.

**Reading.** So the F-056 `0x82304348` AV was indeed a **downstream symptom** of that starvation (exactly
what the peer's F-060/F-064 chain predicted): with the shader buffer served, the guest no longer faults —
it stops one step earlier on its own fatal path instead, so the GFx loader is now reached *less* far, not
more. **The blocker is therefore no longer an access violation at all**: it is the guest's own fatal, and
that is the next thing to name from `w41i.log` (F-064 documented a `'drawblit technique is old and busted'`
fatal at this exact position, which T41.3d removed the stand-in for — if that is what `w41i.log` shows,
the remaining work is to make the real `star_glow` rgxa body available, not to patch registers).

**Tree state parked.** `C:\mcla-pc` builds clean and is at: T41.3d + T41.3g + F-080 gate deletion +
T40.6 step 3 register file + F-063 re-applied. Baseline for the next task = **`w41i.log`** (`w41g`/`w41h`
predate it).

**Correction to F-082's last paragraph (measured, not speculated).** The stop in `w41i.log` is **not** the
`drawblit` fatal. It is: three `REBASE-POISON` lines zeroing `0xCDCDCDCD` (uninitialized) elements at
`A47FD004`/`A47FD008`/`A0021274` with `prod=N elem=00000000 es=0 prodLr=00000000` — i.e. a producer that
**never ran** — immediately followed by `Fatal error dispatcher invoked - terminating game`
(`w41i.log:…02:33:04.404`). So T41.3j is: find who must fill that array (the `prod=N`/`prodLr=0` fields are
the existing census hook's own "who should have produced this" reporting), not how to rename a technique.
`REBASE-POISON` count 3 = same as `w41g` (3), so this chain is not new — only its terminal symptom is.


### F-083 — Named the terminal fatal: it is the guest's `Resource 'meshtextures'` lookup missing on an **alloc-poisoned field**, so the boot blocker is UI-resource loading (T41.3i family), not the register file.

**Read from source, not inferred.** The `REBASE-POISON` line is emitted by
`PPC_FUNC(sub_821B5A60)` (`src/task_dispatch_trace.cpp:497-521`): the guest calls
`sub_821B5A60(&addr)` → `sub_8217D890(group, *addr)`, and when `*addr` has the `0xCD` fill byte the lookup
**misses and the guest raises the fatal `Resource 'meshtextures'`** (stated verbatim in the code comment at
`:490-495`). The host short-circuit at `:514` zeroes `*param` to skip that D890 fatal, which is why
`w41i.log` shows 3 poison lines and then `Fatal error dispatcher invoked - terminating game` — the
short-circuit covers one call site, not the later real lookup.

**Attribution result.** `prod=N elem=00000000 es=0 prodLr=00000000` means `mcla_SlimTslabFind()` has **no
allocation record** for that parameter: the poisoned word was never handed out by the traced simple-pool
path, so it is not a use-after-free of something we produce — the field is simply never written during
boot.

**Consequence for the queue.** This connects the terminal fatal to the **UI resource chain** already
queued: `meshtextures` is one of the six named UI packages the earlier sessions found opening but serving
wrong (F-057(5), F-078, T41.3i). So the priority order from here is: (1) T41.3i — census the read path on
an open `*.list`/`meshtextures` handle to settle whether the member is decompressible or keyless;
(2) whichever way that falls, populate the resource-dict entry so `sub_8217D890` finds it;
(3) then T40.6 step 4 (render from the register file, which is now measuring 52 draws). The register file
is **not** what is stopping the boot today — `DRAW_INDEXED=0` is a rendering gap, and the process never
reaches a frame because it dies on this fatal first.


### F-084 — CORRECTION to F-083 (my attribution was wrong) and the fatal is now named to the string: `Unable to load shader '%s', it probably wasn't preloaded properly.` — and the failing step is **`GETDEV` for the `a:` device**, not a TOC lookup and not a key.

**What the baseline actually says.** `w41i.log` ends with
`Fatal error dispatcher invoked - terminating game` / `fatal-dispatch regs: lr=0x82189270 r3=0x8200B358`.
Reading `r3` out of `build/cache/mcla_pe.bin` at file offset `0x8200B358 - 0x82000000` gives
**`Unable to load shader '%s', it probably wasn't preloaded properly.`** The offset arithmetic is validated
by a positive control in the same read: `0x8200B15C` → `drawblit technique is old and busted, rename to
blit_draw.`, which is exactly the string F-064 recorded. So this is a *shader-load* fatal, raised
**immediately after** `GETDEV-RET #43 path='a:/archive/fxl_final/star_glow.fxc' ret=00000000` (and the
sibling `#41`/`#42` attempts for `star_glow/dcl/...` and `a:/archive/dcl/star_glow.dcl`, also `ret=0`),
while `#38`-`#40` on the `embedded:/` forms returned the memory device `827D838C` successfully.
**F-083's `Resource 'meshtextures'` attribution is void**: `meshtextures.xtd` opens, host-serves RSC5 and
is consumed 60 lines earlier; it is not the terminal failure.

**Why the host cannot answer "is the asset in the archive?" directly (measured, with controls).**
The RPF's name section is not plaintext — a scan of all 2,032 MB of `xarchive_cache.rpf` finds **zero**
ASCII hits for `star_glow`, `fxl_final`, `meshtextures`, `rage_im` or even `.fxc`. Hashing instead
(GtaO, whose implementation re-validates against three live oracles: `preload.list`→`0DB1C876`,
`globaltex.list`→`3D9B8154`, `meshtextures.xtd`→`0597F7BB`, all **MATCH**), the 4-byte pattern for
`star_glow.fxc` occurs once — at `0x8FE9839`, **misaligned by 9 bytes** from any 16-byte entry boundary,
with high-entropy neighbours, so it is a coincidence, not an entry. And the *known-real* decrypted entry
words `[0DB1C876 00000104 001DD11C 4000007E]` are **not present anywhere in the file** — independent
confirmation of F-076(2) that the on-disk TOC is encrypted. Conclusion: the only party that can answer the
question is the guest, through the decrypted TOC — and it does answer: its `TOC76` lookups by path succeed
for other archives, so the archive is readable; what fails is the step *before* it.

**Real next step (replaces T41.3j's premise).** `GETDEV` resolves `a:/archive/textures/global/cars/globaltex.list`
at `#26` from the very same device array (`arr=C60B4E00 cnt=1 cap=16`) yet returns **0** for
`a:/archive/fxl_final/star_glow.fxc` at `#43`. Census the `fiDevice` registration list at the moment of
`#41`-`#43` (the array contents, each entry's prefix length, and which mount owns `a:/archive/`) rather than
chasing decryption: the guest is not finding a device for those paths, which is why it falls back to
`embedded:/` (where the CRT seed list has no `star_glow`) and fatals. `star_glow.fxc` was already shown
(F-066/F-067) to be absent from all 15 embedded `fxl_final/*` bodies, so a device that can serve the real
archive path is the only honest route — do not re-introduce a stand-in body.


---

### F-085 — Prediction→evidence audit of **Phase 0** (`EXECUTION_PHASES.md`): the hash-table address is now raw-verified, but Stage B's causal chain and Stage D's "fatal ABSENT" are both **refuted** — the only boot that ever got past `star_glow` did it by serving `rage_im.fxc` bytes as `star_glow`.

- Task: prediction→evidence audit, Phase 0 (user request 2026-09-21 ~05:56: "analyzing the predictions and
  switch them to evidence? start from the very start, from phase 0")
- Type: FACT + CORRECTION (confirms F-024; refutes the Stage B reading of F-025 and all of Phase 0 Stage D)
- Class: H (premise/instrumentation false positive) — mechanism is a do-not #9 fabrication
- Priority: P1
- Evidence: raw words from `build/cache/mcla_pe.bin`; `build/w41i.log`; `w38s.log` (survives only in
  `C:/mcla-emergency-20260921-0112/logs/`); `src/gpu_device.cpp` line cites. No build, no soak this pass.

**(1) CONFIRMED — F-024's address, by raw instruction decode.** Positive control first: file offset `0xB358`
(= VA `0x8200B358`) in the 10,354,688-byte image decodes to
`Unable to load shader '%s', it probably wasn't preloaded pro…`, so the `offset = VA − 0x82000000` mapping is
sound. At `sub_82188E50` (the INSERT, F-025) the words at VA `0x82188E5C` / `0x82188E60` are `3D608284` =
`lis r11,0x8284` (SIMM `0x8284` = −32124 signed — exactly the pattern F-024 quotes) and `3B8B9F70` =
`addi r28,r11,0x9F70` (signed −0x6090) → r28 = `0x82840000 − 0x6090` = **`0x82839F70`**. The superseded
`0x827C9F70` cannot be produced by this pair. F-024 stands, and is now raw-verified rather than IDA-asserted;
the table is materialised inside the INSERT function, as claimed.

**(2) CONFIRMED — Stage A's factory census, with one instability worth recording.** `w41i.log:1058-1119`: ten
`TEXDICT-CALLER sub_8218B000 #1..#10`, every one with `lr=8218BFE0` (= `sub_8218BF20`+0xC0, the factory) and
`r4=82860C18`; ten matching `DICTFACT-census` lines (`w41i.log:1092-1118`), each reporting `name[0]=''`.
**But "×10" is not an invariant:** `w38s.log` has **20** `DICTFACT-census` hits. The hydration trigger is a
hard-coded `if (n == 10)` (`src/gpu_device.cpp:2159`), so it fires on the first batch either way — no bug
today, but any future claim of the form "the factory makes exactly ten entries" is tree-dependent.

**(3) REFUTED — Stage B: "the hash table at `0x82839F70` is never populated → `sub_82189138` returns −1 →
`star_glow` fatal."** Two independent measurements kill it:
- `w38s.log:3975` — `DICTLOOKUP-OK #1 name='star_glow' (82040F0C) slot=10 lr=82189480`. The lookup
  **succeeded** (return 10, not −1), called from `sub_82189438`+0x48 exactly as A2 predicts. Six lines later
  the game fataled on a **different** message: `drawblit technique is old and busted, rename to blit_draw.`
  (`r3=0x8200B15C`, `lr=0x82188770`). A successful dictionary lookup neither prevents nor causes that fatal,
  and a −1 return was never observed in any surviving log.
- `w41i.log` — `DICTLOOKUP` count = **0**. `sub_82189138` is never called in the current boot, yet the
  `star_glow` fatal occurs (`w41i.log:4520-4524`). The dictionary lookup is therefore **not on the fatal path
  at all** in this tree; the fatal comes from the file-resolve path (`GETDEV #43 → ret=00000000`,
  `BDF20 #19 … ret=0`), as F-084 established.
- Also note the returned value `10` is **not** one of the ten slots hydration filled (0..9), so on the face of
  the log the hydrated entries are not what satisfied that lookup.

**(4) Stage C's hydration is unproven and structurally inert.** It runs identically on both trees:
`w41i.log:1132-1142` and `w38s.log:1167-1177` carry the same ten entry pointers
`A0028280/A00282A0/A00282C0/A00282E0/A0028300/A0028320/A0028350/A00283A0/A00283F0/A0028440`, the same leading
words `[00000000 00000000 00000000 00000001]` … `[00000002 00000000 00000000 00000007]`, and the same
`done: 10/10`. Two consequences: (a) **every entry's +4 word is zero**, so if the guest compares a name hash
at entry+4 — the assumption written in our own comment at `src/gpu_device.cpp:2093` — none of the ten can ever
match any name; (b) the objects live at `0xA002xxxx`, the range the do-not list calls guest scratch, and
`DICTFACT-census` reports `name[0]=''` for all ten, i.e. they carry no name at registration time. Nothing
measured shows these are shader-dictionary entries. Same category as the stand-ins removed earlier this
session (F-078/F-080): host-side writes with no measured effect on the guest.

**(5) REFUTED and re-attributed — Stage D: "fixed boots (`80`/`p0d1`) = fatal ABSENT, boot alive past the old
crash point."** The only surviving log that ever got past `star_glow` is `w38s.log`, and it got there by
**fabrication**:

```
w38s.log:1006  AFB76-HIT #1 path='embedded:/fxl_final/rage_im.fxc'        buf=827D2DD0 size=5258
w38s.log:3848  AFB76-FALLBACK #3 path='embedded:/dcl/star_glow.dcl'       serve rage_im buf=827D2DD0 size=5258
w38s.log:3860  AFB76-FALLBACK #4 path='embedded:/fxl_final/star_glow.fxc' serve rage_im buf=827D2DD0 size=5258
```

The host handed the guest the 5,258-byte `rage_im.fxc` body in answer to `star_glow` requests. The shader
"loaded", the dictionary lookup succeeded, and the boot advanced to `drawblit technique is old and busted` —
which is precisely what you would expect from parsing **rage_im's** technique table while believing it is
`star_glow`. That is a do-not #9 violation (a short-circuit stacked without root cause) and it is the actual
reason Phase 0 recorded the fatal as absent. **The hydration did not do it.**

**(6) Therefore the current tree is not regressed — it is honest.** T41.3d deleted that stand-in this session;
`src/gpu_device.cpp:11030` now emits `AFB76-MISS-HONEST` and returns `0xFFFFFFFF`. `w41i.log` shows
`AFB76-MISS-HONEST` ×3 and **zero** `serve rage_im` lines for `star_glow`, and the boot consequently stops at
the real blocker. **Do not "restore" the w38s frontier** — it is not a reachable state, it is invented content.
Any future log that gets past `star_glow` must show a real device serving `a:/archive/…`, never an
`AFB76-FALLBACK`.

**(7) `w38s.log` is not reproducible from any tree that still exists.** It contains `MSGBISECT` markers
(`w38s.log:3977-3980`); `MSGBISECT` appears **0 times in current `src/`** and 0 times in `w41i.log`. That
census was the concurrent session's uncommitted work destroyed by the E: failure. Treat `w38s.log` as evidence
*about a dead tree*: usable for what the guest did, unusable as a baseline or a target.

**(8) CONFIRMED — the A1 capsule is still verbatim accurate.** `w41i.log:4470-4524` reproduces A1's
`GETDEV #40 embedded:/fxl_final/star_glow.fxc`, the mangled
`#41 a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl`, `#42`, `#43 a:/archive/fxl_final/star_glow.fxc`,
then `lr=0x82189270 r3=0x8200B358 r4=0x82040F0C`, `slot 0x8285FEA0 = 0x82130678`, the message and the aux
`star_glow`. Only `r5`/`r6` drift (A1: `r5=0x16 r6=0x02CB3970`; `w41i`: both `0xCA73BEA8`) — stack-address
noise, not a semantic change. A2's chain is confirmed up to and including `sub_82189438 → sub_82189138`
(`lr=82189480`) and **refuted at its last link**: the lookup does not lead to the fatal.

**What this changes operationally.** Phase 0 must now be read as: hash-table address = fact; factory census =
fact; "the empty hash table causes the fatal" = **false**; "hydration removed the fatal" = **false**. The
frontier is unchanged and remains F-084's: why does `GETDEV` return 0 for `a:/archive/fxl_final/star_glow.fxc`
from the same array (`arr=C60B4E00 cnt=1 cap=16`) that serves `a:/archive/textures/…` at `#26` — queued as
**T41.3k**. Second-order cleanup is now justified by measurement rather than taste:
`HydrateShaderHashTable` (`src/gpu_device.cpp:2054-2090`) and its `n == 10` trigger are candidates for the
same removal as the other neutral stand-ins, but only in a change measured behaviour-neutral on its own
(soak ×2, diff `DICT-HYDRATE`/`DICTLOOKUP`/the fatal block) and **not** bundled into a T41.3k run.


---

### F-086 — Prediction→evidence audit of the **A-capsule + Phase 1**: A2's vtable is raw-verified and A2's *behaviour* is right but its *named functions* are wrong; F-030's cited word does not exist in the image; F-031/F-033/F-035 confirmed; F-034's conclusion is superseded; A5's Q3 is answered.

- Task: prediction→evidence audit, continued from F-085 (Phase 0) into `EXECUTION_PHASES.md` Part A
  capsule + Phase 1.
- Type: FACT + CORRECTION
- Class: H (premise false positive) / partial confirmations
- Priority: P1
- Evidence: `build/cache/mcla_pe.bin` raw words + `tools/ppc_disasm.py` output; `build/w41i.log`;
  `generated/ppc_xenon/ppc_func_mapping.cpp`. No build, no soak this pass.

**(1) CONFIRMED by raw bytes — A2's "vtable+4 = `sub_821CAFB8`".** `w41i.log:4473/4483/4493` report
`GETDEV-RET … ret=827D838C vt=82012918` for every `embedded:/` path. The raw words at VA `0x82012918` are
`821CAE50 821CAFB8 8249B538 82762480 821CB070 821CB158 821CB030 82762480` — so **vt[1] (vtable+4) =
`0x821CAFB8`**, exactly as A2 claims, and vt[0] = `0x821CAE50`. The two words immediately before the table
(`0x82012910`/`0x82012914` = `820DDDC8 821D61F8`) are an RTTI locator + `type_info`, i.e. this is a genuine
C++ vtable rather than a coincidental pointer run. The device object `0x827D838C` that answers every
`embedded:/` request therefore dispatches slot0 → `sub_821CAE50`, slot1 → `sub_821CAFB8` (our `AFB76-*` hook).

**(2) CONFIRMED by raw bytes — the `memory:`-only acceptance test, but in a different function than A2 says.**
`tools/ppc_disasm.py 821CB488` gives:
```
821CB494  lis  r11,8201
821CB49C  li   r5,7                      ; 7 = strlen("memory:")
821CB4A0  addi r4,r11,10200              ; 0x82010000 + 0x27D8 = 0x820127D8 = "memory:"
821CB4A4  mr   r3,r25
821CB4A8  bl   823DD800                  ; compare
821CB4AC  cmpi cr6,r3,0
821CB4B0  bc   -> 821CB4C4               ; not equal -> reject path
```
The source address is **F-035's exact literal** (raw read: `0x820127D8 -> b'memory:'`), and the length 7
matches it. So a `memory:` prefix test is real. But it lives in **`sub_821CB488`**, not in vtable+4
`sub_821CAFB8` as A2 states — and `src/gpu_device.cpp:2042-2043` describes `sub_821CB488` as a "resource
handler lookup … which returns NULL". That description is **measured false**: it is a 7-byte `memory:` string
comparator. Phase 0's Stage-B root-cause comment is built on it and must not be trusted (see §10).

**(3) REFUTED — A2's named wrapper `sub_8218C9D8`.** A2 says it "builds `"embedded:/"` + name on the stack".
The image contains four `embedded:/` literals: `0x82009130` `embedded:/rage_im`, `0x82009DE0`
`embedded:/rage_fastmipmap`, `0x8200B39C` `embedded:/`, `0x8206ABC8` `embedded:/rage_bink`. Scanning 0x1000
bytes of `sub_8218C9D8`'s body for any `lis` capable of forming any of those four addresses: **zero hits**. The
actual builders of the bare `embedded:/` literal are:
- **`sub_82189138`+0xA8** (`0x821891E0`) — `addi r3,r1,80` (dst = stack buffer), `addi r4,r11,-19556` →
  `0x82010000 − 0x4C64` = **`0x8200B39C`**, `li r5,11` (10 chars + NUL), `bl 823DA950`. This is Phase 0's own
  "lookup-or-insert" function, and it is building a path, not merely scanning a hash table.
- **`sub_821CAE50`+0x20** (`0x821CAE70`) — i.e. **the device vtable's slot 0**: zeroes sp+80/sp+84,
  `li r5,10`, `addi r4,r11,-19556` → same literal. Slot 0 is the device's `embedded:/` prefix method.
- `sub_821CB488`+0x3C also references `0x8200B39C`.
So A2's *description* of the behaviour is accurate and its *attribution* is not. The measured caller of
`sub_821BDF20` on the star_glow shader path is **`sub_8218C760`** (`w41i.log:4498`
`BDF20 #16 path='embedded:/fxl_final/star_glow.fxc' … lr=8218C7F4`, and `0x8218C7F4` lies inside
`sub_8218C760`, a raw-verified prologue `7D8802A6 4824CA95 9421FE60`), with `lr=821CA708` for the two `.dcl`
forms (`BDF20 #14/#15`).

**(4) A5's Q3 ANSWERED — `sub_8218C650` is not a standalone function.** It is absent from
`generated/ppc_xenon/ppc_func_mapping.cpp`, whose neighbouring entries are `0x8218C638` (`:2536`) and
`0x8218C6AC` (`:2537`); therefore `0x8218C650` = **`sub_8218C638 + 0x18`**. Its raw words
`389F0020 48046BA5 38610050 …` decode to `addi r4,r31,32; bl …` — not a prologue. Any document citing
`sub_8218C650` as a function is citing a mid-function address.

**(5) F-030's conclusion stands, its citation is void.** The word `40004D7C` occurs **0 times** in the
10,354,688-byte image, so it is not an instruction from this binary and cannot be quoted as one. Disassembling
the two hot `lr` sites shows both are the return address of the **same** call:
```
8242FC08  li   r6,0                 ; Alertable = FALSE
8242FC0C  li   r5,1                 ; WaitMode  = 1 (UserMode)
8242FC10  li   r4,3                 ; WaitReason = 3
8242FC18  bl   827BD5A4             ; = KeWaitForSingleObject
8242FC1C  mfmsr r10 / mtsr / lwarx r11,r0,r31 / addi r11,r11,-1 / stwcx. / mtsr / bc -> 8242FC1C
```
`0x827BD5A4` is `KeWaitForSingleObject` (`generated/ppc_xenon/ppc_func_mapping.cpp:44890`; host hook installed
at `src/patches.cpp:481-483`). The code after the wait is an MSR-guarded `lwarx/stwcx.` **atomic decrement
retry loop** on the word at `[r31]` — a refcount release. The identical shape repeats at `0x8242FCAC`, giving
the second `lr` `0x8242FCB0`. Both `lr` values appear **13,237 times** in `w41i.log`, so F-030's operative
conclusion — "this is a healthy wait, not the load stall the Phase-1 §0 text claimed" — is **confirmed**. The
label "GPU-worker tick" and the word `40004D7C` are unsupported; nothing here identifies the waiter as
GPU-related.

**(6) CONFIRMED exactly — F-033's mount census.** `w41i.log` contains precisely **2** `MOUNT76` lines
(`:601`, `:663`), both `path='a:/archive/'`, both `lr=821CBF54` (inside `sub_821CBF28`, the wrapper F-033
named), `dev=C60ABC88` then `dev=C60AC100`, both `vt=82012BDC flag=1`.

**(7) F-034: observation holds, conclusion superseded.** Only the two archive mounts above ever run, so
"BRANCH 3 — the entire non-archive Mount chain never executes" is still true. But its stated consequence, "so
no `memory:` device is ever registered", is **false on this tree**: `827D838C` appears 12× in `w41i.log` as the
`ret=` for every `embedded:/` `GETDEV`, with the vtable proven in (1). Phase 2 p2b's `MakeMemoryStream`
guest-slot-table insert supplies it. Read F-034 as: *the guest's own mount chain for it never runs; the host
provides the device.*

**(8) CONFIRMED and strengthened — F-031.** `TOC76` reaches **#80** across 316 lines in `w41i.log`; there is no
`#22` hang. The "TOC76 #22 hang" was never a real terminal event.

**(9) CONFIRMED by raw bytes — F-035.** `0x82012A28 -> b'memory:$%p,%d,%d:%s'` and `0x820127D8 -> b'memory:'`,
both exact.

**(10) What must change in the tree.** The Stage-B comment block at `src/gpu_device.cpp:2039-2043` asserts two
things now measured false: that `sub_82189138` merely "scans the empty hash table" (it also builds an
`embedded:/` path at +0xA8), and that `sub_821CB488` is a "resource handler lookup … returns NULL" (it is a
7-byte `memory:` comparator). Per F-085 the same block's causal claim is already refuted. The comment is
corrected in place in this pass, citing F-085/F-086 — a comment-only change, no behaviour, no rebuild needed
for correctness of the record.


---

### F-087 — Prediction→evidence audit of **`LONG_TODO_MASTER.md` §0 (the "verified 2026-09-20 20:40" state block)**: F-049's vtable claim is raw-verified, but F-055's "no `stw` with immediate `0xE334` exists" negative scan is **false**, the address it names is **off by 0x10000**, and §0's headline frontier (UILOAD reached, `C0000005` 1, `rptrWB=0000`) does not reproduce on `w41i`.

- Task: prediction→evidence audit, continued from F-085/F-086.
- Type: FACT + CORRECTION
- Class: H (premise false positive) — one genuine confirmed fact, one refuted negative, five stale numbers
- Priority: **P0** (this is the block `AGENTS.md` tells every agent to read first)
- Evidence: raw words from `build/cache/mcla_pe.bin`; `build/w41i.log`; `tools/ppc_disasm.py`.

**(1) CONFIRMED by raw bytes — F-049's singleton vtable.** The words at VA `0x8200AE8C` are
`82187698 821873E8 82187450 82187600 821874B8 82187700`, so **slot +4 = `0x821873E8`** exactly as claimed.
A whole-image scan for the word `0x821873E8` returns only **two** sites: `0x8200AE90` (that slot) and
`0x82104868`. So `sub_821873E8` is reachable through exactly one vtable slot plus one other pointer — a useful
constraint for T41.3x work. (Note the word before the table is `0x6F757000` = ASCII `oup\0`, i.e. this table
is not preceded by an RTTI pair; `0x8200AE8C` is the table start.)

**(2) REFUTED — F-055's negative scan.** §0 asserts: *"**no `stw` with immediate `0xE334` exists anywhere in
`0x82130000`–`0x82800000`**, two negative scans"*. A direct scan of that range finds **22** instructions in
opcodes 24..63 whose 16-bit field is `0xE334`, of which **three are `stw` (opcode 36)**: `0x822FA2BC`
(`917FE334`), `0x822FBB38` (`906BE334`), `0x822FBB48` (`916AE334`); plus seven `lwz` (`0x822F3358`,
`0x822F33B4`, `0x822FA298`, `0x822FA334`, `0x822FA350`, `0x822FA96C`, `0x826AB5A8`) and ten `lfs`
(`0x82730634` … `0x827315BC`). Two of the three stores are **proven to target the singleton**, with the base
register set two instructions earlier:
```
822FBB34  3D608288  lis  r11,0x8288          -> r11 = 0x82880000
822FBB38  906BE334  stw  r3,-0x1CCC(r11)     -> EA = 0x8287E334
822FBB40  3D408288  lis  r10,0x8288          -> r10 = 0x82880000
822FBB44  39600000  li   r11,0
822FBB48  916AE334  stw  r11,-0x1CCC(r10)    -> EA = 0x8287E334  (stores ZERO)
```
The third (`0x822FA2BC`, `stw r11,-0x1CCC(r31)`) has an unproven base, so no EA is claimed for it. The
inference §0 drew from the false negative — "the field is permanently 0, therefore do not arm it" — loses its
evidence. The **policy** still stands on its own footing (do-not #9: no arming without root cause), but the
premise "nothing writes it" is now known to be wrong, and there is an explicit guest writer that stores zero.
The real question becomes whether `0x822FBB34`-`0x822FBB48` ever executes in a boot — a census, not a scan.

**(3) CORRECTED — the address is `0x8287E334`, not `0x8288E334`.** In the very function §0 cites,
`sub_822FA958`, the access is:
```
822FA958  3D608288  lis  r11,0x8288          -> r11 = 0x82880000
822FA96C  816BE334  lwz  r11,-0x1CCC(r11)    -> EA = 0x82880000 - 0x1CCC = 0x8287E334
```
PPC sign-extends the displacement, so `0xE334` is `-0x1CCC`. §0's `0x8288E334` is what you get by treating the
field as **unsigned** — off by exactly `0x10000`. Both addresses lie inside the 10,354,688-byte (`0x9E0000`)
image and both read as zeros there, so the file cannot discriminate; the arithmetic does. Every past and future
claim about "the `[0x8288E334]` singleton" should be read as `[0x8287E334]`.

**(4) CONFIRMED — `sub_822FA958` really is a 22-instruction float leaf.** It spans `0x822FA958`..`0x822FA9AC`
inclusive = 22 instructions, contains no `bl`, and ends `4E800020` (`blr`). Its body is one bss `lwz`, a
`lis r9,0x827E` / `addi r7,r9,0x2978` constant, three `lfs`, three `fadds`-class ops (opcode 59) and three
`stfs` (opcode 52). §0's shape description holds; only its address and its writer-negative were wrong.

**(5) STALE — §0's frontier numbers do not reproduce on the current baseline `w41i.log`.**

| §0 claim (2026-09-20 20:40) | `w41i.log` (2026-09-21 02:33) | verdict |
|---|---|---|
| "the boot worker now reaches UILOAD for the first time"; `UILOAD-enter` + `UILOAD-param`, no `UILOAD-ret` | `UILOAD-enter` **0**, `UILOAD-param` **0**, `UILOAD-ret` **0**; instead `w41i.log:6400` `W34-NOGFX #1 — no GFx loader objects (vt 0x82073xxx) in scan bands; UILOAD/EF220 never armed after inflate` | **not reproducible** |
| `C0000005` **1 → 1** | `C0000005` **0** | superseded by F-082 |
| boot-gate stages run ("dies after 2 `GATE-STAGE` lines") | `GATE-STAGE` **0** | the gate driver no longer runs |
| CP ring `put=11 rptrWB=0000` | `put=11 rptrWB=001F` | **advanced** — attributable to F-081's register file |
| `DRAW_INDEXED`/`DRAWDISP` still **0** | `DRAW_INDEXED` **0**, `DRAWDISP` **0** | confirmed, still the blocker |
| — | `CP-DRAW` **52** | F-081 baseline holds |

§0's frame ("#1 = the atArray allocator chain behind the one surviving fault") is therefore doubly void: there
is no surviving AV, and the terminal event is the guest fatal named in F-084 (`Unable to load shader
'star_glow'` after `GETDEV #43 a:/archive/fxl_final/star_glow.fxc -> ret=00000000`). `rptrWB=001F` is the one
place where §0 is *behind* reality rather than wrong about it — the CP now writes its read pointer back, which
is consistent with F-081 and is the only forward movement in this table.

**Action taken this pass.** A superseding dated state block (§0c) is inserted above §0a in
`LONG_TODO_MASTER.md`, carrying these six measured numbers and the corrected address, so the next agent's
mandatory first read is not the stale one. Nothing in `src/` changed for F-087 (F-085/F-086 already corrected
the two false comments at `src/gpu_device.cpp:2039-2047` and `:2092-2096`).


---

### F-088 — Corrections to F-085/F-086/F-087 issued by this session's own memory and the reconstructed ledger: the `40004D7C` "void citation" verdict was a **category error**, `rptrWB` is a **host-published gauge** (do-not #20), and the `rage_im` mechanism was **already F-066's**.

- Task: self-audit of the F-085/F-086/F-087 pass, after re-reading `project-boot-blocker.md` and
  `C:\mcla-emergency-20260921-0112\LEDGER-ADDENDUM.md`.
- Type: CORRECTION (of my own three preceding entries)
- Class: H
- Priority: P1
- Evidence: `build/w41i.log:19927`, `src/gpu_cp.cpp:161`/`:423-424`, `LEDGER-ADDENDUM.md:45-54`.

**(1) WITHDRAWN — F-086 §5's "`40004D7C` occurs 0 times in the image, therefore the citation is void" is a
category error and F-030's citation is sound.** `40004D7C` is nowhere offered as an instruction word:
`w41i.log:19927` prints it as the **wait object** —
`WAIT[KWFSO] #06588! tid=0000423C obj@40004D7C reason=3 to=30ms lr=8242FC1C put=11 rptrWB=001F wb@C71D82BC=0000001F`.
`0x4000_0000` is outside the `0x8200_0000` code image that `build/cache/mcla_pe.bin` covers, so "0 occurrences
in the image" proved nothing and was the wrong search space — exactly the failure mode
`project-boot-blocker.md` warns about. F-030's parenthetical names the waited-on object, which is a legitimate
way to identify a wait.
**What survives of F-086 §5, and it is the part that matters:** the raw decode of both hot `lr` sites is
independently corroborated by that same log line — `reason=3` matches `8242FC10 li r4,3`, and `to=30ms`
matches the timeout argument — and the callee is `8242FC18 bl 0x827BD5A4` = `KeWaitForSingleObject`
(`generated/ppc_xenon/ppc_func_mapping.cpp:44890`; host hook `src/patches.cpp:481-483`), followed by the
MSR-guarded `lwarx/stwcx.` decrement retry. So F-030's conclusion stands on better evidence than before; only
the "GPU-worker" label remains unverified (the log gives the object address, not its owner).

**(2) RETRACTED — the `rptrWB` "advance" in F-087 §5 and §0c is a do-not #20 misread.** I reported
`rptrWB=0000` (§0) → `rptrWB=001F` (`w41i.log`) as the CP ring's read pointer finally moving. It is not guest
progress: `writebackVA` is declared at `src/gpu_cp.cpp:161` as the host's "**publish target** (guest-VA form)"
and is written by the host at `:423-424` under `writebackEnabled`, with comments at `:1076`, `:1090`, `:1095`
and `:1135` describing it as what the host publishes in order to **unpark the guest's `KWFSO` poll**. The log's
`wb@C71D82BC=0000001F` is a read-back of the value the host wrote there. It is a counter measuring our own
servicing — the precise trap already recorded twice in this project. **No claim of CP-ring advance stands on
it.** The only non-self-referential draw numbers in `w41i.log` remain `CP-DRAW` **52** (F-081) against
`DRAW_INDEXED` **0**.

**(3) PRIOR CREDIT — the `star_glow` → `rage_im` mechanism was already established as F-066, and F-062 had
already refuted F-055's negative scan.** `LEDGER-ADDENDUM.md:45-54` (the C: reconstruction of the F-056…F-076
range that E: destroyed) already records "deleting the `star_glow` → `rage_im` substitution", and that
"`rage_im` necessarily contains `drawblit` at `buf+0x1365` — which is the very fatal it then triggered". So
F-085 §5's mechanism is a re-derivation with the log lines pinned down, not a new discovery; the genuinely new
content of F-085 is only (a) that this is what `EXECUTION_PHASES.md` **Phase 0 Stage D** mis-credited to the
hydration — now corrected in that file — and (b) the `DICTLOOKUP-OK … slot=10` measurement
(`w38s.log:3975`) plus `sub_82189138` at **0** calls in `w41i.log`. Likewise `project-boot-blocker.md` already
states that F-055's "no `stw` with immediate `0xE334`" scan was refuted by F-062 for string-matching `0xE334`
instead of decoding `lis` + signed `d`, and already lists `0x8287E334` vs `0x8288E334` as the same
sign-extension error — so F-087 §2/§3 are a **re-verification**, not a first refutation. They stay because the
ledger text is still wrong where it was restored: `ROOT_CAUSE_VALIDATION.md:1046-1047` still asserts
"`0x822FA96C lwz r11,-7372(r11)` → `[0x8288E334]`", which F-087 §3 shows is `[0x8287E334]`.

**Method lesson (why one pass produced three errors at once).** F-085/F-086/F-087 were run read-only against
docs and logs *without first re-reading* `project-boot-blocker.md` and the C: reconstruction — which is the one
thing that memory tells me to do before claiming a refutation. The measurements themselves all hold: every raw
word, log line and `file:line` cited in the three entries was taken from the current tree and re-read. But three
of their *interpretations* were mine, and two of those three are traps this project has already been caught in.
**Before converting a prediction into evidence, search the ledger and `LEDGER-ADDENDUM.md` for whether that
prediction has already been put to the test.**

### F-089 — T41.3k closed by measurement: `sub_821CB488` is a prefix chain plus a per-device `vtable+4` TOC probe, and the archive answers "star_glow.fxc is not here" honestly

- Task:        T41.3k (census the `fiDevice` array at `GETDEV #41-#43`), executed as **T41.3m** — one log-only census edit, one build, one soak `build/w42a.log` vs baseline `build/w41i.log`
- Type:        FACT (+1 instrument-class FIX, +1 WITHDRAWAL of my own mid-pass claim)
- Class:       E for the content conclusion (§5, §8) · H for §1's correction of the A2/F-086 attribution and for §6/§7
- Priority:    P0
- Evidence:    raw words of `build/cache/mcla_pe.bin` (offset = VA − 0x82000000) · `w42a.log:4414, 4420, 4437, 4443, 4461, 4467` · `w42a.log:4404-4472` · `w41i.log:611-616, 978-992, 4470-4518` · `src/gpu_device.cpp:102-110` `:10287-10288` `:10355-10373`

**1. The lookup is fully decoded and it is not a comparator.** `sub_821CB488` (0x821CB488) is
`fiDeviceManager::GetDevice(path)`: a chain of `bl 0x823DD800(path, literal, n)` prefix tests, each
`n` taken from `li r5,n`, landing on static device objects in bss. Literals read from the raw image
(addresses corrected for PPC sign-extension — `addi r4,r11,-19556` from `lis r11,0x8201` is
**0x8200B39C**, not 0x8201B39C; the project's own `lis` trap, caught live):
`memory:`(7)@820127D8 → **0x827D838C** · `embedded:/`(10)@**8200B39C** → **0x827D838C** ·
`tcpip:`(6)@82012A18 → tail `bl 0x821D5F58` · `cache:`(6)@82012A10, `cache1:`(7)@82012A08,
`game:`(5)@82012A00, `dvd:`(4)@820129F8 → **0x827D8388** · `dlc`(3)@820129F4 with `path[4]==':'` →
**0x827D8388** · anything else → dynamic registry search @`0x821CB5B0`. This *explains every
`GETDEV-RET` in the baseline*: `game:/xarchive_*` → `827D8388` (`w41i.log:577`), all five
`embedded:/` attempts → `827D838C` (`:980, :4473-4493`). F-086's "`sub_821CB488` is a 7-byte
`memory:` comparator" was true of the first test only; A2's vtable `0x82012918` belongs to that
static memory device, **not** to the mounted archive.

**2. The dynamic search, and why our case takes the two-device branch.** `0x821CB5B0` loads
`r27 = 0x82860844`, `r29 = lhz[r27+4]` (count), `r6 = lwz[r27]` (array), entry stride **276**,
matching via `bl 0x821CAA28(entry, path, 3)` and keeping a best index in `r30` (init −1; still −1 at
`0x821CB618` → branch to the no-device return at `0x821CB6F0`). On a hit: `lhz[entry+272]` is the
device count — **if 1, return `lwz[lwz[entry+268]]`** (holder slot 0) at `0x821CB634-63C`; **if >1,
`0x821CB648-0x821CB66C` loads each device, reads `[[dev]+4]` and calls it** (`mtctr`/`bclr`). The
baseline registry is exactly one entry with `dcnt=2` (`w41i.log:611, 978`:
`name='a:/archive/' len=11 hold=C6177E00 dcnt=0002 d0=C60ABC88 d1=C60AC100 vt0=vt1=82012BDC`), so
the two-device probe branch is the one that runs. This also re-confirms the census' own 276-byte
entry layout and F-033's "exactly two Mounts".

**3. `vtable+4` of the archive device strips the mount prefix.** `0x82012BDC` =
[`822C3588`, **`821CDB88`**, `821CC570`, `8249B538`, `82762480`, `82762480`, `821CD348`, `821CC6F0`].
`sub_821CDB88` is three instructions: `lwz r11,36(r3)` · `add r4,r11,r4` · `b 0x821CCEA0`. So
**device+36 is the mount-prefix length** (11 = strlen("a:/archive/") — the `pfx0` census field is
correctly named after all), and GetDevice asks the packfile by *stripping the prefix and tail-calling
`sub_821CCEA0`*, which calls the TOC lookup `sub_821CBFC0` at `0x821CCECC` (`lr=821CCED0`, the same
`lr` every `TOC76` line carries). Therefore **GetDevice's answer for `a:/archive/<rel>` is literally
the guest's own archive TOC answer for `<rel>`** — and the 0-returns at #41-#43 are that answer.

**4. Measured at runtime, in this session's soak.** `w42a.log` — six lines, two per requested path
(= the two devices of §2's loop), every one a miss, and the paths arrive in the *stripped* form §3
predicts:
`TOC76-SG #81/#82 path='star_glow/dcl/star_glow/dcl/star_glow.dcl' ret=00000000 lr=821CCED0`,
`#83/#84 'dcl/star_glow.dcl' ret=00000000`, `#85/#86 'fxl_final/star_glow.fxc' ret=00000000`
(`#81`'s path is `a:/archive/star_glow/dcl/...` minus 11 chars, verbatim). Census neutrality proved by
diff against `w41i.log`: `DRAW_INDEXED 0→0` · `CP-DRAW 52→52` · `GETDEV 168→168` ·
`DICT-HYDRATE 11→11` · `TEXDICT-CALLER 11→11` · `C0000005 0→0` · `GFx 3→3` · `[error] lines 39→39`;
the only deltas are `TOC76 +18` / `TOC76-RET +6` (exactly the new prints) and `WAKE/WAIT[KWFSO]`
poll noise (+22/+23 in `rptrWB`/`PUT=`, a host-published gauge — do-not #20). Fatal unchanged at
`w42a.log:4476-4480`.

**5. T41.3k's premise is void, and the queue's question is answered.** The task asked why "the same
array serves `a:/archive/textures/…` but returns 0 for `a:/archive/fxl_final/star_glow.fxc`". Answer:
the array never varies — `arr=C60B4E00 cnt=1 cap=16` and one 276-byte entry with `dcnt=2`,
byte-identical across all 41 logged lookups — and the difference is made by the **archive's own TOC
lookup, which says the file is absent**. There is no device-registry defect to fix here.

**6. WITHDRAWN (my own confound, caught before writing §5's conclusion).** Mid-pass I built a table
showing "43/43: every `GETDEV-RET` ≠ 0 path has a `TOC76-XSF` line, every `=0` path has none" and was
about to record that as gating evidence. It is a **print-window artifact**: the census gate is
`hot = (n <= 80) || policecam` (`src/gpu_device.cpp:10287-10288`) and the last `TOC76` line in
`w41i.log` is **#80**, one millisecond before the three star_glow lookups. Absence of a line from a
capped printer is not a negative result — the question needed a build, and §4 is what the build said.
Same family as do-not #20/#22.

**7. Instrument FIX (log-only, class H): the archive census could never see the fatal's file.**
`PathLooksLikeArchiveContent` (`src/gpu_device.cpp:102-110`) matches
`.xsf .xtd .list globaltex preload shaders/ textures/ resources/` — **no** branch of it can match
`fxl_final/star_glow.fxc` or `dcl/star_glow.dcl`, so every `TOC76-XSF`/`LAYOUT`/serve decision in the
project's history is blind at precisely the file the boot dies on. I did *not* extend the predicate:
it also drives `ui` inside the `sub_821CCEA0` hook (`:10373`), which **writes** the Open-gate bit into
guest memory and routes bodies through `XsfTocCache` — extending it would have been a serve, not a
census (do-not #9). Instead the run adds (a) `star_glow` to the `hot` gate so the header/return lines
print, and (b) an uncapped read-only `TOC76-SG` line. Both are print-only.

**8. New static fact about `star_glow` itself (class G/E, and it reframes the blocker).** In the
whole 10,354,688-byte decompressed image, `star_glow` occurs **exactly once**, at **`0x82040F0C`** —
and that value is the fatal's own `r4`/aux argument (`w42a.log:4476` `r4=0x82040F0C`, F-08x's
`MEMPARSE-C9AB0 #4 r3=82040F0C`). Its neighbourhood is a name table, not a path list
(`mcla_pe.bin` 0x40EE0): `draw_starglow\0`, `StarTexture\0` `CentrePosition\0` `star_glow\0` then
IEEE-754 constants (`???UU<<??MC)` …) then `mcLi`. Meanwhile the only *complete* `.fxc` path literal
image-wide is **`fxl_final/rage_im.fxc` @`0x820093DE`**, sitting among
`ati / pixannotation / hdr / colorexpbias / debugshaders` (@0x820093C0), and
`preload.list file missing in '%s'` @`0x8200AEAC` is immediately preceded by a vtable whose slot 0 is
`0x821873E8` (`821873E8 82187450 82187600 821874B8 82187700 821877B8 82187820`). ⇒ `star_glow` is a
**hard-coded render-effect/technique name** (with its own `draw_starglow` technique and
`StarTexture`/`CentrePosition` semantics), and the guest *synthesises* `fxl_final/<name>.fxc` from a
pattern because only `rage_im` is spelled out. "It probably wasn't preloaded properly" is therefore
the literal truth: the binary was expected to be already resident, not looked up by path.

**9. What is now genuinely open (and one escalation).** No log in this project's history has ever
printed a preload-list **body**: 12 `HOSTSERVE-BLOCKED` in both `w41i.log` and `w42a.log` (T41.3g/F-077,
which was the right call), and `grep` for `fxl_final|star_glow` outside GETDEV/BDF20/TOC76-SG/AFB76
across every `build/*.log` = **0 hits**. The known TOC entries for the six lists are in the log (e.g.
effects: `0DB1C876 00000170 00304E12 400000BC`, `w41i.log:4405`), and five `preload.list` entries share
`w[0]` but differ in size/offset — so the archive distinguishes them by full path, and leaf-name-only
hashing is refuted. Next: **T41.3n** (census the guest's own read of one list body). If the lists name
shaders whose `.fxc` bodies are absent from `xarchive_cache.rpf`, then *which* archive carries the
shader bodies is a **user/content-policy decision**, because `AGENTS.md` forbids `mc4/art` and only
permits `xarchive_cache.rpf` + audio/music — I am not going to resolve that by silently mounting
forbidden art.

### F-090 — 15-agent audit of the un-audited docs landed a real GPU fix (the Xenos register file was 24 % of its proper width) and invalidated four numbers I wrote down today

- Task:        fleet audit of `EXECUTION_PHASES` Phase 2 + `PROGRAM_GUIDE` §7/§9 + `LONG_TODO_MASTER` §2 + ledger F-001…F-084 citation integrity + the CP→draw and archive frontiers; the fix is T40.6 step 3b, soaked as `build/w43a.log` vs `build/w42a.log`
- Type:        FIX (1) + FACT (5) + CORRECTION (4, all of my own or F-081's text) + ESCALATION-CLOSED (1)
- Class:       D/F for the register file · H for every capped-printer and label-mixing item · E for the archive verdict
- Priority:    P0 (items 1, 5, 6) · P1 (2, 3, 4, 8, 9) · P2 (7, 10)
- Evidence:    `src/gpu_cp.cpp:52` (pre-edit) · `E:\mcla pc\.research\xenia\src\xenia\gpu\register_file.h:40` · `command_processor.cc:1050-1065` · `w43a.log` `CP-REG-HI #1-#22` · label counts in `w41i`/`w42a`/`w43a` · raw words `0x82188E54`-`0x82188E68` · `build/game_data` inventory · `src/boot_host.cpp:332-344`

**1. FIX (P0, class D) — the Xenos register file was too narrow, and it swallowed every 3D register write.**
`src/gpu_cp.cpp:52` declared `kXenosRegCount = 0x2000u` while a type-0 header index is 14-bit
(`header & 0x3FFFu`, `:72`) and upstream's file is `0x5003` dwords (`register_file.h:40`, read from the
local checkout). `CpRegPoke` returned **before** bumping `g_xenosRegWrites` (`:62-64`), so the drops were
invisible in every log this project has ever produced. Raised to `0x5003u`. Proof-of-widen is a new
`CP-REG-HI` line that is deduplicated by base and deliberately **not** counter-capped: `w43a.log` prints
22 distinct bases at/above the old bound (`hiWrites` ≥ 220) — `200D 2007 2080 2100(val 0000FFFF) 2104
2180(val 1000000E) 2200 2203 2204(val 00010000) 2208(val 00000004) 2280(val 00080008) 2293 2302 2312(val
0000FFFF) 231B`. Note `1000000E` is the same value the boot's oldest surviving crash line carried as
`Param[1]` (F-055's "`0x1000000E`"), i.e. that dword is a register value, not a parameter. **Register
names are NOT asserted here**: `grep` of the local `xenos.h` for `RB_MODECONTROL` / `0x21FC` returns 0
hits, so the fleet's names (`SCRATCH_UMSK`/`SCRATCH_ADDR` from `register_table.inc:39-40`,
`VGT_DRAW_INITIATOR = 0x21FC`) are unverified against this checkout — cite indices until `registers.h` is
read. **Measured effect on the boot: none** (`DRAW_INDEXED 0→0`, `DRAWDISP 0→0`, `SUBMIT 48→48`,
`GETDEV 168→168`, `TOC76-SG 6→6`, `HOSTSERVE-BLOCKED 12→12`, `C0000005 0→0`, fatal verbatim at
`w43a.log:4513`). Necessary, not sufficient — see item 5. `kMmioRegCount` (`= 0x10000/4 = 0x4000`) still
guards the shadow copy, so indices `0x4000+` land in `g_xenosReg` only; that is upstream's shape too.

**2. CORRECTION to F-081 and to my own §0c/§0d text — "CP-DRAW 52" was never a draw count.**
It is two labels: `CP-DRAW #` = **24** lines and `CP-DRAW-STATE #` = **28** lines, identically in
`w41i.log`, `w42a.log` and `w43a.log`, and `CP-DRAW #`'s own printer is capped
(`src/gpu_cp.cpp:613` `n <= 24 || (n % 64) == 0`), so #25-28 were hidden. The honest sentence is
"roughly 28 draw packets reach the CP, of which `DRAW_INDEXED` = 0". F-081's "`CP-DRAW` is ≥52, not 24"
is void, and every doc that quotes 52 as progress is quoting a label sum.

**3. CORRECTION — the `0x82839F70` raw citation everyone quotes is misattributed and off by one word.**
The words are `3D608284` (`lis r11,0x8284`) at **`0x82188E5C`** and `3B8B9F70` (`addi r28,r11,-0x6090`)
at **`0x82188E64`** — `0x82188E60` holds an unrelated `li` between them, so "at `0x82188E5C/E60`" is
wrong. The value `0x82839F70` itself stands. But **F-024's entry contains no such address**: the entry
that measured it is F-085(1), yet §0c, §0d, `HANDOFF_NEXT_AGENT.md:65` and `LONG_TODO_MASTER.md:100` all
credit "F-024's". Same class of error as F-088: a correct fact with a rotted pointer.

**4. CORRECTION to F-086 §5 and to F-089's own pointers.** "Both hot `lr` sites appear 13,237 times" —
only `lr=8242FC1C` does (13,237); `0x8242FCB0` appears **0** times in `w41i`/`w42a`. And F-089's src
cites have drifted: `:11030` → `:11054` (`AFB76-MISS-HONEST`), `:2054` → `:2053`
(`HydrateShaderHashTable`), `:10287` → `:10293` (the `TOC76` `hot` gate). Still unfixed from F-088 §3:
`ROOT_CAUSE_VALIDATION.md:1046-1047` asserts `[0x8288E334]` where the correct singleton is
`[0x8287E334]`.

**5. FACT (P0) — why item 1's fix is not yet enough for a pixel.** There is **no** CP→D3D12 path in the
tree: `grep -c "g_commandQueue|RenderCommand|DrawIndexedCommand" src/gpu_cp.cpp` = **0**. The only push
is `src/gpu_device.cpp:1843`, reachable only from `PPC_FUNC(sub_82420BA8)` (`:1717`), and that function
is entered **exactly 2×** per boot (`w42a.log:3582`, `:4027`) both times with `plausible=0`, because its
caller hard-zeros the stream arguments — raw: `0x8217BB00 li r7,0` · `0x8217BB04 li r5,0` ·
`0x8217BB08 lwzx r6,r11,r27` · `0x8217BB0C bl 0x82420BA8`. So T40.6 step 4 as written ("drive the host
enqueue from `CP-DRAW`") is not a wiring job: an honest enqueue additionally needs vertex/index buffer
bases and a **bound shader**, and `CpExecImLoad` (`src/gpu_cp.cpp:114-130`) currently decodes the
microcode and then discards it. `LONG_TODO_MASTER`'s `src/gpu_device.cpp:1793-1803` pointer is also stale
(the region is now `:1838-1844`). Next census, three lines, all log-only: (a) accepted-high-pokes (done —
`CP-REG-HI`), (b) `CP-SHADER` at `CpExecImLoad` printing type + whether microcode was retained, (c) one
coalesced count of the `base=000 n=1 val=00000000` writes that dominate `CP-REG-T0` (1,131 of 1,171
samples are that one padding shape — `CP-REG-T0 1171` is a *sample* count under `n % 250`, not 1,171
writes; `n` itself reaches six figures).

**6. ESCALATION CLOSED — the content-policy question I queued in §0d does not need asking.**
`mc4/art` — the tree `AGENTS.md` forbids — is **two 0-byte `.loc` files** on E: and an empty directory
tree on C:, so mounting it buys literally nothing. Independently: `default.xex` declares **0**
resource-directory entries (no embedded filesystem), and `embedded:/` is not an archive at all — it is
15 hard-coded CRT static blobs registered at `src/boot_host.cpp:332-344`, none of which is `star_glow`.
And there is **no on-disk RPF TOC parser anywhere in `src/`**: the host's TOC knowledge is fed only from
the guest's decrypted in-memory entries (`src/gpu_device.cpp:10328` → `g_xsfToc`), gated by
`PathLooksLikeArchiveContent` (`:102-113`) which cannot match `.fxc`/`.dcl`. So "the archive lacks
star_glow" is a statement about the *guest's* answer only (F-089 §4). Net: no allowed-content route to
that shader body exists; the only routes are the guest's own preload path (**T41.3n**) or accepting the
fatal. One real loss surfaced alongside it: `xarchive_music.rpf` is a **0-byte `.part`** on C: against
**780,304,384 B** on E: — worth restoring on its own merits, though it is audio, not shaders.

**7. FLEET-REPORTED, NOT VERIFIED BY ME — do not act on this until re-read.** One agent decoded the
archive TOC entry as `+4 = expanded size`, `+8 = absolute byte position`, `+C low-30 = stored length`
(with the top two bits as flags), and claims `sub_821CCEA0` bails when **bit 30 of `+8` is SET** — i.e.
the comment at `src/gpu_device.cpp:10349` states the gate inverted — and that `XSF-OPEN ret=` is a
*handle index*, not a status, which would make the `ret == 0` serve condition at `:10428` wrong. If true
this rewrites F-079/F-080. It is a single agent's raw decode, so re-read `0x821CCEED`-`0x821CCFF0`
directly before changing anything.

**8. ENVIRONMENT (P1) — `git` is dead in `C:\mcla-pc` and E: now reads.** `.git/HEAD`, the index and
`.gitignore` are absent and `objects/` is empty (`git` → "not a repository", rc 128), so (a) every
`git show 8f07a39:docs/<file>` instruction in `AGENTS.md` and the skills is unusable — the only
pre-compression text is `C:\mcla-emergency-20260921-0112\`; (b) the session-start `git status` ` M`
lines could only have come from the E: copy; (c) a lost log or file is permanently lost. Conversely
**E: answers reads today** (`.research/xenia` read fine this session), which is how item 1's upstream
constant was checked — it still refused writes on 09-21, so build and soak only on C:. `C:\mcla-pc\.git`
repair (`git index-pack` from the backup `dot-git`) remains user-side.

**9. LEDGER HOLE (P1).** No numbered `### F-0NN` entries exist between **F-056 and F-077**: that week
survives only as unnumbered prose at `ROOT_CAUSE_VALIDATION.md:1071-1166` (byte-identical to
`LEDGER-ADDENDUM.md` in the emergency backup), while **seven** F-numbers are cited from `src/` with
nothing to resolve to — F-057 (`gpu_cp.h:30`, `kernel/imports.cpp:2113`), F-058 (`gpu_cp.cpp:828`),
F-063 (`gpu_device.cpp:11397`), F-066/F-067 (`:11047`, `:11054`), F-073 (`fs/vfs_rpf.h:18`), F-076
(`vfs_rpf.h:20`). Consequence for anyone using the ledger: a grep that finds nothing does **not** mean a
citation is fabricated. Do not renumber; restore stubs, or cite the prose block's line numbers.

**10. Also settled by the audit, cheaply.** (a) F-063's `D3070` clause removal is **already applied**
(`src/gpu_device.cpp:11397-11401`, comment "F-063 re-applied"), so `HANDOFF_NEXT_AGENT.md:591-594`'s
"re-apply it" instruction is obsolete — and `C0000005` is 0 in both baselines, so no build is owed.
(b) `tools/mitigation_audit.py` → exit 1: §7 registers 13 mitigations against **80** mitigation-shaped
labels in `src/` (68 undocumented), 50 of them within ±26 lines of a guest-memory mutation; 5 of the 12
§7-mapped labels fire zero lines. (c) `tools/soak_census.py` tracks **116** markers (not 115), 9 of them
dead text plus 2 false-live (`assert`, `ClearTaskJoinBusy`), and ~49 of the 107 live markers print behind
counter caps the tool cannot see; `TOC76-SG` — the one real gain of this session — is **untracked**, so
it is invisible in the census table. (d) The 5 project skills carried 10 `cd "E:/mcla pc"` instructions
and `mcla-boot-cycle` prescribed `ninja_build.bat`, which hard-codes `cd /d "E:\mcla pc"` and therefore
builds nothing here; `mcla-finding-ledger` documents a `**F-0NN —**` format the file does not use; and
`mcla-recompiler-regen` step `tail -n +4 generated/… > src/ppc_context.h` is irreversible with no VCS.
All four fixed on the C: copy of the skills (E:'s copy is what this session loads, and E: takes no
writes). (e) Upstream Xenia has **no `fi` module** — the analogues are `vfs::VirtualFileSystem` /
`vfs::Device`, whose `ResolvePath` prefix-matches and hands the caller-stripped relative path to exactly
ONE device; so F-089's `dcnt>1 → per-device vtable+4` probe is a title-side design with no upstream
twin, and the local `command_processor.cc:1050-1065` `& 0x1FFF` RMW mask confirms ours is already right.

### F-091 — The preload-list bodies are now printed for the first time: they are real non-ASCII bytes (so the guest's reads work and the "opaque" branch is the answer), the project's own disassembler had been printing every computed CALL as a RETURN, and there is a live host fabrication injecting a `legals.xsf` body into all five shader lists

- Task:        T41.3n (preload-list body census, landed as `build/w44c.log`), plus the 7-agent second fleet pass over `AGENTS.md`, `PROGRAM_GUIDE` §3/§4/§5/§8/§11, §7/§9 inventories, `generated/**` integrity, the kernel stub table, the archive/frontier questions and repo recovery
- Type:        FACT (5) + FIX (3: the read census, the disassembler, my own census bug) + CORRECTION (2 of my own writes today) + ESCALATION (1)
- Class:       H (the disassembler, the two blind printers, my post-call register read) · E/D (the body and the injection) · F/G (the generated-code verdict)
- Priority:    P0 (items 1, 2, 3, 6) · P1 (4, 5, 7, 8) · P2 (9)
- Evidence:    `w44c.log` `RD-BUF #1-#16` · `w43a.log:629`, `:999`, `:3145`, `:4558` · `src/gpu_device.cpp:9899-9952`, `:668-690`, `:9209`, `:8348`, `:10470`, `:10401` · `src/kernel/imports.cpp:1047-1108`, `:3540` · `src/patches.cpp:516`, `:827`, `:51` · `tools/ppc_disasm.py` · `E:\mcla pc\.research\xenia\src\xenia\gpu\register_file.h:40`

**1. THE MEASUREMENT (P0) — a read buffer's content has never been printed in this project, and it
refutes the zero-fill suspicion while confirming the "opaque" branch.** New `RD-BUF` line at the
`PPC_FUNC(sub_8244F4C0)` return (`src/gpu_device.cpp:9911+`), uncapped, read-only:
`#1 buf=8EFFF070 cnt=20 read=1 head=[RPF3.H..>.......]` and `#3 head=[RPF3....{]......]` — the guest
reads the **RPF3 header** itself; `#4 buf=C60B7700 cnt=382976 read=1` non-ASCII — the **382,976-byte
TOC** into the same `inner=C60B7700` object the `TOC76` lines name; `#5-#16` = the 12 page reads of the
six lists (`32768` each, buffers cycling `C6137A80/C6147B00/C6157B80/C6167C00`), every one `read=1`
(the host read succeeded, full length: `out=00008000`) and **`nz=16/16`, `ascii=4-10/16`** — high-
entropy binary, not names. Consequences: (a) `NtReadFile`'s `memset+SUCCESS` branch
(`src/kernel/imports.cpp:1103-1108`) is **not** what the list reads take — `C60B7600` is a real
`CreateKernelObject<FileObject>` handle (`w43a.log:629` `NtCreateFile: 'xarchive_cache.rpf' opened,
handle=C60B7600`) so they hit the VFS branch `:1084-1102` and receive real RPF bytes; (b) F-077's stated
discriminator resolves to **"the payload is opaque"** — the bytes at those positions are not ASCII, so
the lists are (as F-073 said) compressed members whose **decompression never happens**: the only
`XMEM`/`XMEM-OUT` lines in the soak carry `srcSz=7179936` (the 7 MB preload job), never a ~126-460-byte
list member. So the chain is now: real page bytes in hand → no decoder call → no names → nothing
preloaded → `star_glow` fatal.

**2. FIX (P0, class H) — `tools/ppc_disasm.py`, the tool every raw decode in the project used, printed
every computed CALL as a RETURN.** It dispatched op-19 on `xo9 = (i>>1)&0x1FF`, but `528 & 0x1FF == 16`,
so `bctr`/`bctrl` (XO 528) aliased onto `blr` (XO 16) and both printed as `bclr` — and it misspelled
`blr` as "bclr" on top. Also: `ori/oris/xori/xoris` printed `(RA,RT)` reversed; `mr` was emitted for
XO 444 unconditionally (so a genuine 3-operand `or` silently lost RB); `nand` was keyed to XO 476
(real 478); `nor`(124)/`eqv`(56)/`orc`(284) were missing and printed as raw `op31:` fields. All fixed and
regression-checked (`blr`/`bctr`/`bctrl`/`blrl`/`ori r3,r6`/`nor r11,r10,r11` now correct).
**Re-audit of F-089 with the fixed tool: its conclusions stand and one is now firmer** — the
`sub_821CB488` multi-device probe at `0x821CB668-6C` is `mtctr r9` + **`bctrl`**, i.e. a real *call*
(F-089 §2 read it as a call from context; the bytes now say so). Anything in older docs that reads a
`bclr` line as a return should be re-checked.

**3. FIX (P0, class E/H) — a live host fabrication injects a wrong body into all five shader lists.**
`MclaFindServedBody` falls back to a `(dev, handle)` key and then to a `flagWord ≈ TOC w2 with the low
byte cleared` match (`src/gpu_device.cpp:668-690`), so a body registered for one member is returned for
*another* file on the same device+handle. `w43a.log` shows `BE8D8-PACK #2-#6 … path='resources/ui/legals/
legals.xsf'` firing against the five `preload.list` loads (`SLOT-REG #3-#7`): the guest is offered a
**`legals.xsf` copy as the body of `shaders/*/preload.list`**. It is currently unconsumed (the reads
above still return real RPF bytes) but it is live, unregistered in §7, invisible to `soak_census.py`, and
exactly the class of stand-in that produced F-066's fake `rage_im` body. Removing it is queued as
**T41.3o** under a revert gate, not bundled into this soak.

**4. ADJUDICATED — F-090 §7's four unverified claims, tested from raw words.** (a) CONFIRMED bytes,
inferred meaning: `sub_821CDB88` = `lwz r11,36(r3); add r4,r11,r4; b 0x821CCEA0`; the sibling thunk at
`0x821CDB98` jumps to `0x821CCEA0` with **no** `+36` add, so "+36 = mount prefix length" is inference
from the runtime-stripped paths (F-089 §4), not from the code. (b) The TOC-lookup call is **indirect**:
`0x821CCEC0 lwz r11,0(r31)` · `821CCEC4 lwz r10,144(r11)` · `mtctr` · `bctrl` → identity comes from data
(`0x82012BDC+144 = 0x82012C6C = 0x821CBFC0`); `+8` = archive byte position (log-corroborated: reads land
at `pos & ~0x7FFF`) — **but `+4` is contaminated by us**: `src/gpu_device.cpp:10470` writes
`WriteU32BE(tocEntry+4, xsz)` (XSF-OPEN #1 `+4=00022EF1` → #2 `00008000`). (c) **REFUTED**: the
"Open bails when bit30 of `+8` is SET" claim rests on `821CCEE0 7D6A58F8`, which is **`nor r11,r10,r11`**
(XO 124, not nand) and whose result is dead — the very next `lbz r11,1128(r31)` overwrites it; the
following `rlwinm r9,r10,1,31,31` tests bit30 of **r10**, a call-clobbered register. (d) **Gate
CONFIRMED, return-value claim REFUTED**: the real gate is `[entry+12]` — `821CCF78 rlwinm r10,r11,0,1,1`
(bit31), `821CCF88 rlwinm r11,r11,0,0,0` (bit30) → if 0 proceed, `821CCF9C rlwinm r11,r11,0,24,31`
(low byte) → `821CCFA4 beq 821CCFF0` where `stw r27,0(r31)` stores the entry; `r3` is never assigned, so
`XSF-OPEN ret=` at `src/gpu_device.cpp:10424` is **the residue of an inner call**, not a status and not a
handle index — and the host's `if (ret == 0)` serve test at `:10434` is wrong on that basis. (e) REFUTED:
no `entry+8 & 0x7FFF` indexing exists in `0x821CBE00-0x821CD900`; the only `&0x7FFF` is page chunking of
a *position argument* (`821CCB48/CCB54/CCB68`). **F-079/F-080 need exactly one sentence rewritten**: move
the Open gate from `[entry+8]`bit30 to `[entry+12]` bit30-clear + low-byte-zero; keep `+8 = position`.
Also settled (the two fleet agents disagreed): the `XSF-OPEN-GATE-SKIPPED` write is **commented out**
(`:10401`, T41.3h), while `DISCCHK`'s `WriteU32BE(dev + 12, flags | 0x80000000)` at `:9958` is **active**.

**5. CLEAN FOUNDATION (P1) — the recompiled code on the executed path is faithful.** An agent verified
**all 200** executed-path functions (20,217 instructions, 11,182 register/immediate/branch-target field
comparisons incl. 1,634 sign-extended, plus 169 float load/store checks): **0 mismatches**. Whole-tree
stub census: `TODO`/`UNIMPLEMENTED`/`ERROR: 0x`/`assert(false)`/empty-body markers = **0**, and the
`// .long 0x0` entries (14,877, "33 % stubs" in the old docs) are **1-word inter-function padding** —
raw-verified as `00000000` between a `blr` and the next `mflr`, with 0 static code xrefs and **0 of them on
the executed path**. So the Phase-0 fear that the boot is running on stubs is closed. The `45,190` vs
`44,707` mapping discrepancy is explained: `src/boot_host.cpp:1282` prints every installed row
(44,707 `sub_XXXXXXXX` + 236 `__save/__restgpr` prologue helpers + `_xstart` + 246 `__imp__*` imports);
`PROGRAM_GUIDE.md:21` counts only the `sub_` shape. One genuine class-A truncation exists **off** the
path: `sub_82134378`/`sub_8213437C` (`ppc_recomp.0.cpp:12510/12518`, body cut short of the raw stream).

**6. KERNEL (P1) — even past the fatal, input cannot reach the guest today.** `XamInputGetState` is
called **0** times, is **double-owned** (`src/kernel/imports.cpp:3540` hooks the import while
`src/patches.cpp:516` `SetFunction(0x827BDC64, hk_XamInputGetState)`), and **both** native detour
attempts failed at runtime: `w43a.log:93` `DetourImportThunk: unexpected thunk bytes` → `:94`
`XamInputGetState thunk detour failed`, and the shadowing hook at `patches.cpp:827` zeroes `wButtons`
unless a synthetic `StartPulseActive()` timer (`patches.cpp:51`, no host input behind it) is high. Also
newly inventoried: **63 `GUEST_FUNCTION_STUB` sites expand to an empty body that leaves `r3` = arg0**
(incl. `XamTaskSchedule`, `XamAlloc`, `XamUserGetXUID`, `NtCreateTimer`, `NtDeviceIoControlFile`), and
`NtSetInformationFile`/`NtQueryDirectoryFile`/`NtQueryVolumeInformationFile`/`NtReadFileScatter` return
SUCCESS having done nothing. Zero `XAudio*`/`XMA*` calls (so no audio path is exercised), and the idle
signal that dominates every soak (`WAIT[KWFSO]` 6,577) is driven by our own `KDELAY-SC` short-circuit at
`src/gpu_device.cpp:3106` — a counter of our servicing, not of guest progress (do-not #20).

**7. INVENTORY (P1) — §7/§9 are far more wrong than F-047 recorded.** Measured against `w43a.log`
(19,948 lines, 1,116 literal printers, **422 fired / 330 distinct labels**): §7 registers 13 mitigations
vs **80** mitigation-shaped labels in `src/`, and **135 guest-affecting lines per soak belong to
mitigations that are in NEITHER §7 NOR `soak_census.py`'s tracked list** — `BE710-SLOT` 49, `XSF-POSTOPEN-SERVE`
31, `P5-PHYS` 24, `JOB2-PKG-SERVE` 22, `PKG-SUBST` 19, `W30-ARR-FIX` 2, `D2308-INS-SKIP` 2,
`W31-ARR-FIX`/`PLACE-ARR-PRE`/`PLACE-ARR-FIX`/`AFB76-HIT` 1 each. `soak_census.py` tracks **116** markers,
9 of them dead text and 2 false-live (`assert`, `ClearTaskJoinBusy`), ~49 of 107 live markers print behind
counter caps, and **226 fired labels (4,660 lines) have no tracked token at all** — including `CP-REG-T0`
(1,171), `CP-REG-HI` (22), `TOC76-SG` (6) and `RD-BUF` (16), i.e. this session's own gains are invisible
in the census table. Both tables are rewritten as **T39.8**; the dangerous-intersection list above is the
part to read first.

**8. ESCALATION TO THE USER (P0, one action, not a code question).** `C:\mcla-pc` has **no working git**
(no `HEAD`/index, empty `objects/`, rc 128) and today's proof exists only there: `w42a`/`w43a`/`w44a`/
`w44b`/`w44c.log` + `src`/`docs`/`.qoder` changes are single-copy (~7 MB of logs, 158 files).
`E:\mcla pc` **has** a healthy repo (HEAD `4280c9d`, 158 commits, 2,528,584,865-byte pack, 16 dirty paths,
6 commits ahead of origin) — but E:'s tree is **older** (`src/gpu_device.cpp` 509,214 B @09-21 00:39 vs
C:'s 504,497→502,717 B @09-23) and **the ledger is split across the two volumes**: C: holds F-077…F-091,
E: holds **F-061, F-065, F-068-F-071, F-074, F-075 plus ~26 queue items (T40.1-T40.5, T41.1-T41.15, T42.2)
that exist in neither C: nor E:'s committed HEAD**. So: copy C:'s `src`+`docs`+`tools`+`.qoder`+`build/*.log`
to a third volume now, then commit from E: and push — do **not** copy C: over E: (it would delete those 8
findings). Also restorable from E:: `xarchive_music.rpf` **780,304,384 B** (C: has a 0-byte `.part`) —
though it is audio, not shaders. `git show 8f07a39:docs/…` works only from E:, so AGENTS.md's recovery
instruction is half-true; the emergency `dot-git` is **not** rebuildable (pack truncated to 131,072 B,
`.idx` 0 B, 78 of 173 loose objects 0 B).

**9. Also measured, cheap.** `default.xex` declares **0** resource-directory entries (no embedded
filesystem); the `embedded:/` device is backed by `SeedEmbeddedNameList()`'s closed 15-entry table of CRT
static blobs (`src/boot_host.cpp:319-364`, log `embed-seed 15 CRT triples`) holding the 13 in-image `rgxa`
`.fxc` + 2 `.dcl`, so `AFB76-HIT size=5258 buf=827D2DD0` for `rage_im` is a **legit guest `.data` blob**
(raw word at `0x827D2DD0` = `rgxa`) and NOT a stand-in — `NO-STAND-IN-ALIVE` for `star_glow`, whose name
exists only as the tune string at `0x82040F0C`; `STAR-GLOW-SEED` (`:9209`) and `D2308-INS-SKIP` (`:8348`)
both fire *after* the fatal (`17:09:43.055` vs `:4488` at `.052`) and neither writes anything (blocked by
`BufLooksLikeRgxa`), so they contaminate nothing; `mc4/art` is two 0-byte files on both volumes; and
`PROGRAM_GUIDE` §3's build command (`ninja_build.bat`) and §5's `XenonRecomp.exe` are both dead ends —
the recompiler binary does not exist, so no generated-code regeneration is possible today, and
`generated/ppc` (179 TUs) + `generated/default` are decoys that nothing references.

### F-092 — The `XamInputGetState` detour could never have succeeded; had it succeeded it would have overwritten a live host function -- and deleting it exposed the second owner that had shadowed the real SDL input path all along

- Task:        user-directed fix of the `XamInputGetState` detour failure. Three soaks: `build/w45a.log` (detour deleted), `build/w45b.log` (duplicate owner removed). Tooling: `tools/addr_owners.py`.
- Type:        FIX (3) + FACT (1)
- Class:       D (kernel/input) + H (the blind logger, the tool gap)
- Priority:    P0 (items 1, 2) · P2 (3, 4)
- Evidence:    `src/patches.cpp:492` (the removal note) · `src/kernel/function.h:351-352` · `generated/ppc_xenon/ppc_func_mapping.cpp:44998` · `src/kernel/imports.cpp:3540` · `src/kernel/xam.cpp:261,318` · `src/app.cpp:337-341` · `src/boot_host.cpp:1279` · `w44c.log:93-94` vs `w45a.log` · `w45b.log`

**1. FIX (P0) — the detour was a category error, and its success mode was self-corruption.** `mcla_DetourImportThunk` (`src/patches.cpp:167`, now deleted) required the first two bytes of its argument to be `FF 25` (`jmp [rip+disp32]`, an x86 IAT thunk) and otherwise logged and returned null. It was being handed `&__imp__XamInputGetState` — but `GUEST_FUNCTION_HOOK(subroutine, function)` (`src/kernel/function.h:351`) expands to `PPC_FUNC(__imp__XamInputGetState) { HostToGuestFunction<XamInputGetState>(...) }`, i.e. the **address of our own compiled host stub**, whose prologue is never `FF 25`. So the `[error]` in every log ever produced (`w44c.log:93`) was structural, not a regression — and if the check had passed, the function would have `VirtualProtect`d 12 bytes and written `48 B8 <ptr> FF E0` (`movabs rax,hook; jmp rax`) **over the entry point of a live emulator function**. Everything downstream (the `E9` hotpatch analysis, two 128-byte hex dumps, `InstallNativeDetour` on a "real func" at `wrap+70+rel`) sat unreachable behind that impossible condition, and none of it had a consumer except more logging. Guest-side interception in this emulator is `dispatcher->SetFunction` — which the next item is about. Deleted: the call site, the dead `else` block (85 lines), `g_original_XamInputGetState`, and the helper + its `patches.h` declaration (30 lines); `g_virtual_membase` is assigned **before** the deleted block and is still read at `src/patches.cpp:~550`, so it was preserved. Proof of neutrality: `[error]` lines 39 → 38 (exactly this line), exe 56,848,384 → 56,824,832 B, and `DRAW_INDEXED 0→0`, `CP-DRAW 52→52`, `GETDEV 168→168`, `RD-BUF 16→16`, `CP-REG-HI 22→22`, `Fatal error 2→2`, `C0000005 0→0`, `GFx 1→1`.

**2. FIX (P0) — the same slot had a second owner, and it had been beating the real input path since it was added.** `generated/ppc_xenon/ppc_func_mapping.cpp:44998` maps `{ 0x827BDC64, __imp__XamInputGetState }`, which routes to `kernel::XamInputGetState` (`src/kernel/xam.cpp:261`) — a working SDL keyboard→pad mapping whose own comment says it exists "so menus can be driven". `src/patches.cpp` then called `dispatcher->SetFunction(0x827BDC64, hk_XamInputGetState)`, and `SetFunction` **overwrites** `m_functions[addr]` *and* calls `kernel::g_memory.InsertFunction` (`src/app.cpp:337-341`), while `mcla_ApplyPatches` runs **after** `InstallFunctionTable()` (`src/boot_host.cpp:1279`) — so the later, fake registration always won. `hk_XamInputGetState` writes `pad+4 = 0x0010` only while `StartPulseActive()` (`src/patches.cpp:51`, a synthetic timer with no host input behind it) is high, and `0x0000` otherwise: the guest was reading a controller that is hard-wired to "nothing pressed". This is also the rule-4 condition the tool exists to catch (two owners of one guest address). The shadow line is gone; `hk_XamInputGetState` and `StartPulseActive()` are left in tree unreferenced so the synthetic pulse can be reinstated deliberately rather than by accident.
**NOT YET EXERCISED — say it plainly:** `XamInputGetState` is called **0** times in `w45a` and `w45b`, because the boot still dies at the `star_glow` fatal before any input loop. This change is therefore proven *behaviour-neutral* (`w45b` vs `w45a`: `DRAW_INDEXED 0→0`, `CP-DRAW 52→52`, `GETDEV 168→168`, `RD-BUF 16→16`, `CP-REG-HI 22→22`, `Fatal error 2→2`, `C0000005 0→0`, `GFx 1→1`, `XamInputGetState 0→0`) and *structurally* correct (one owner, and it is the real one), but it buys no measurable progress yet. The acceptance signal when the boot reaches input: `xam.cpp:318`'s `XamInputGetState[n] port= buttons= lx= ly=` line, not `patches.cpp`'s `XamInputGetState[n]: port= buf= held=`.

**3. FACT (P2, class H) — the failure message could not print its own arguments, and 28 more loggers have the same defect.** `MCLA_LOG_ERROR("DetourImportThunk: unexpected thunk bytes at %p: %02X %02X", ...)` used printf specifiers against an fmt-style logger, so `w44c.log:93` contains the format string **verbatim** — the thunk bytes that would have shown *why* it failed were never visible, and the same call would have been a memory-safety bug if it had ever run (it dereferences `thunk[0]/thunk[1]` before any range check, which is fine for a mapped host symbol and not otherwise). Survey: 29 `MCLA_LOG_*` calls carry `%`-style specifiers, of which the live risks are `src/d3d12_backend.cpp:2192,2266,2276,2281,2340,2347,2381,2385,2404` (`BuildInputLayoutFromGrcFvf`, `UploadPacketGeometry`) and `src/gpu_mmio.cpp:38,54`. None of them fired in `w45a`/`w45b` (all 0 counts), so no past conclusion is invalidated — but every one sits on the vertex-layout and MMIO path that T42.1 is about to walk. Queued as **T39.9**.

**4. TOOL FIX (P2, class H) — `tools/addr_owners.py` could not see the authoritative owner table.** `SKIP_DIRS` excludes `generated/`, which is right for 176 TUs but also hid `ppc_func_mapping.cpp`; so immediately after item 2 removed the shadow, `--check 0x827BDC64` printed **"unclaimed in src/ and config/"** — an invitation for the next session to install another `SetFunction` there and re-break input. It now consults the generated table **as a fallback only** (an address is reported as `map` when nothing in `src/`/`config/` claims it), which keeps normal verdicts unchanged. Verified: `0x827BDC64` → `map __imp__XamInputGetState generated/ppc_xenon/ppc_func_mapping.cpp:44998` (+ the named-import line); `0x821CBFC0` and `0x82420BA8` still report their 2 src sites with no added row; the full-tree run still exits **1** on the real duplicate (`VdSwap`, three files); runtime 0.8 s.

### F-093 — T41.3o executed on E-primary: the loose-match it targeted is already superseded, but the census names the real stop chain and the change is a safe keep.

- **Experiment.** Disabled all three loose branches of `MclaFindServedBody` (`(dev,handle)` slot map, `flagWord & 0xFFFFFF00` family loop, bare-`dev` last-body scan) as log-only `T413O-SKIP` census, `src/gpu_device.cpp:663+` (site shifted post-merge; F-091 cited `:668-690`). Built `build_on_e.bat` (rc 0, `[2/2]` link, 21:55), soaked `build/w47.log` 120 s vs baseline `build/w46.log`.
- **Result: frontier bit-identical** — `Fatal error 2/2`, `GFx 3/3`, `GETDEV 168/168`, `PRESENT 68/68`, `C0000005 0/0`, `DRAW_INDEXED 0/0`. The star_glow fatal fires at the same chain position (w47 `:5316`).
- **Why the premise was stale:** the `.list` reads never reach the loose path anymore — both logs show `HOSTSERVE-BLOCKED path='textures/global/cars/globaltex.list' (T41.3g/F-077)` immediately after `XSF-OPEN ret=0`/`openGateBit30=0`. F-091's legals.xsf-as-list-body account describes the pre-T41.3g serve chain. The skip census instead caught a live loose hit for `flagWord=0x00060000` -> `meshtextures.xtd size=32768` (58 hits) — the family mask is effectively "any ~32 KB body", and it is now inert.
- **Named stop chain (the point of the run):** `globaltex.list: TOC76-XSF openGateBit30=0 -> XSF-OPEN ret=0 -> HOSTSERVE-BLOCKED -> no member is ever fed to the guest decoder sub_8244FF20 (F-091 T41.3n2) -> preload table lacks star_glow -> embedded:/-fallback walk -> TOC76 #86 'fxl_final/star_glow.fxc' ret=0 -> guest fatal`. Getting past star_glow requires exactly one of: (a) T41.3n2 — get one list body through the guest's own LZX, or (b) the DISCCHK bit31 forcing being replaced by whatever the guest sets on real hardware (21:00 peer thread). Translator is not implicated (zero PSO/DXC/TRANSLATE markers in w45b+w46+w47; the offline `shader_dxc_compile` validator history is a different stage).
- **Keep.** `git` provenance: T41.3o change + this entry land on top of `7a75147`. Revert is one `git revert` if a later soak shows the meshtextures loose-serve was load-bearing — w46 vs w47 says it is not.

### F-094 — T41.3n2 CLOSED by criterion (b): the guest image has exactly ONE XMemDecompress call site, it sits in a container-walker the *.list path never enters, and the list windows' bytes are neither plaintext nor container — "inflate a member with the guest's own decoder" is structurally impossible as shipped.

- **Method (plan T41.3n2 S1–S4b, no steps skipped).** S1/S2 instrument fix: the old XMEM census read `lr` after the callee (trap #1) and capped at `n<=16|n%100`; new `T413N2-XMEM` (gpu_device.cpp:2240 area) captures pre-call lr + every call, dedup `(src>>16,srcSz)`. S3 (w48): 14 decoder calls boot-wide, ALL `srcSz=7179936` streamables — zero list feeds, now instrument-clean. S4b walk: `T413N2-PUMP1/2` + `T413N2-PAGER` entry censuses (gpu_device.cpp ~:10170+), plus whole-image static scans.
- **E1 — the read path is honest.** PUMP2 entry args (w49 #5–#8): `r3=827D8388` (a: device), `r5=0x60000/0x68000/0xD0000/0xD8000` — windows at real member-file offsets; RD-BUF #5 buffer `C6157B80` head `75 91 4D 4E …` == `xarchive_cache.rpf` bytes @0xD0000 **byte-for-byte**; 64 zero bytes exactly at 0xD023F (=0xD0000+0x23F) — raw-file read, no decryption applied by us or them, and NOT CBC ciphertext there (ciphertext cannot be zeros → if members are encrypted, their pages are decrypted elsewhere/never).
- **E2 — descriptor encoding.** Page-loop (sub_821CC970 @821CC9E4–0x821CCA28): descriptors are 12B `{gate, offset/16, next}` (`stw r30,8(r30)` chain; `srdi/sldi ×16` at 821CC9FC/821CCA08); `item[0]==0` ends the loop; per-page call = stream vtable `lwz r9,28(r10); bctrl` → PUMP2. Pager gated on `[r13+52]` (TLS byte 52) and `[0x8286073C]` — both read at entry, `T413N2-PAGER #1` showed `[TLS+52]=0`.
- **E3 — the lone door.** Static scan of all 0x868000 code words for `bl → 0x8244FF20`: **exactly one site, 0x821D5EB8**. Its host (0x821D5E60+) advances a cursor 8–12 bytes per block (`addi r8,r10,-8; stw r9,4(r31)`), computes `end-start` block sizes and passes `&stack[80]/[84]` in/out params — the canonical **XMem 12-byte-block container walker** (the 7 MB streamables path, `lr=82460420` wrapper). No branch in the *whole image* routes any `a:` window-pager read into it. "No member is ever fed to the guest decoder" (F-091 §1) is therefore not a timing artifact but a structural property of this build.
- **E4 — what the members' bytes are not.** globaltex.list window [0xD0000,0xE0000): 575 B at base = 15% printable; sub-offset `entry+12 & 0x3FFFFFFF = 0xEC` → all zeros (refuted as in-page offset); best 256 B run in the window = 51% printable at 0xDEDC0, sample high-entropy. So: not plaintext names, not an XMem container, not reachable to the one inflate door. §7 of `MCLA_RPF3_Technical_Reference.txt` ("file_size != uncompressed ⇒ XMem LZX") does NOT describe how this image consumes these six members — F-073's stored/expanded compression inference is hereby superseded for the *.list set.
- **Named blocking field.** The runtime TOC-entry **`+8` word** (globaltex: `0x000D0000`): treated by the page loop as a file offset (×16 encoding confirmed) — but the bytes it designates are uninterpretable by any consumer code in the image. The six *.list entries lack the flag bit that the other 36 `openGateBit30=1` entries carry at `+8` (w48 count) — which is exactly what DISCCHK stand-in forces (21:00 peer thread): **DISCCHK is load-bearing for reaching the star_glow fatal, and the fatal is DOWNSTREAM of a member payload this prototype never decrypts/inflates in the paths we see.** On retail/devkit hardware these bytes must be transformed before parse by a stage NOT present in this image slice — the honest next discriminator is whether any other consumer reads buffers `C6157B80/C6167C00` (watchpoint via VEH, per project rule), or whether the archive answer for these six members is simply 'absent-but-TOC-lies' territory.
- **Instruments kept** (all log-only, zero frontier delta w48/w49/w50 vs w47: `C0000005 0`, `Fatal error 2`, `star_glow 41`). T41.3o skip-census (F-093) additionally proved the loose-match family mask `0xFFFFFF00` was live only for `meshtextures.xtd` reads.

### F-095 — B1 discriminator LANDED: zero DR-watchpoint hits across boot ⇒ the globaltex.list member pages are never read by ANY consumer after the fill; the "missing decrypt stage" world is refuted for the post-read position, and `HOSTSERVE-BLOCKED` is confirmed as the sole reason the preload table is empty.

> **VOID — see F-100.** The zero is the instrument's, not the guest's: the `B1-ARM … ok=true`
> self-report cited below proves `SetThreadContext` *accepted* the call, and a positive control in
> `w59` shows the registers were never live (a host read of the watched bytes on an "armed" thread
> tripped nothing). Do not use this entry to close a fork; B1 was re-run on a working
> guard-page instrument and is answered in **F-101** (pages *are* consumed, as-is, no decoder).

- **Instrument.** `boot_host.cpp` B1 block (F-094 plan B1): `Dr0/Dr1` watchpoints (RW, len 8) on host VAs `g_base+0xC6157B80` / `+0xC6167C00` — the two globaltex.list member-page destinations stable across w47-w50 — armed on the boot worker + every `GuestThreadFunc` start (`B1-ARM tid=… ok=true dr0=1C6157B80`, 6 threads in `w52.log`), handled at the TOP of the existing VEH (`code==0x80000004 && Dr6 bits 0/1` → log + `EXCEPTION_CONTINUE_EXECUTION`), budget 48 then self-disarm. Instrument verified by the B1-ARM self-report; `w51` (pre-verify run) discarded, not cited.
- **Result.** `w52.log`: `B1-WATCH` count **0**. Frontier unchanged (`C0000005 0`, `Fatal error 2`, `star_glow 41`, `PRESENT 50` — identical to w47-w50). Known limit stated honestly: len-8 windows watch only the first 8 bytes of each page; a consumer that skips the head and reads deeper is invisible to it (accepted: parsers read the head for magic/counts, and F-094 already proved via whole-image call-edge scan that the ONLY XMemDecompress call site in the image is unreachable from this path).
- **What this kills.** The "there is a decrypt/inflate stage downstream that will consume these pages later" world (F-094 option (a)) for the READ-AFTER position: after `NtReadFile` fills the window, NOTHING ever reads its head — not a decoder, not a parser, not a copier. The bytes sit unread.
- **What this means for the fatal.** Combined with F-094 E1/E3: the `a:` preload read of globaltex.list is fire-and-forget bookkeeping (sub_821C91C0 registers → pager → returns 0); the table the star_glow gate consults is NOT built by parsing these windows post-read on this path at all. `HOSTSERVE-BLOCKED` (T41.3g) — our correctly-refused junk serve — is therefore the live discriminator upstream: either the list content must arrive BEFORE/AROUND this read through a stage the guest runs earlier (the TOC-parse-time path of RAGE resource system), or the prototype genuinely never consumed globaltex.list at this point and star_glow's absence is a content-absence fact (F-089), i.e. **B2 must now attack the preload TABLE producer, not the page consumer**. Next concrete S-step (B2a): find who writes the preload table entries — watchpoint the star_glow name-table VA 0x82040F0C region for writers/readers plus census the table the GETDEV-fatal path consults (sub_821CB488 answer chain), and check `RD-BUF #5/#6` timestamp ordering vs the table query at the fatal.

### F-096 — F-089's "the archive honestly answers star_glow is not here" is SUPERSEDED: the entry IS present in the guest's own parsed RPF TOC (d1 table) with gate bit30 SET; the fatal's lookup used the mount's d0 device, whose 18 KB index contains none of the game's names. The stop is an INDEX-POPULATION failure on device d0, not content absence.

- **How the dumps were taken (B2a, two revisions).** One-shot census dumps of the two archive-view buffers the TOC76 census itself names: raw-fill-time dump (`toc_decrypted.bin`/`early_decrypted.bin` @ RD-BUF, w53) showed the fill is still opaque at read time — lesson: hashed entries appear only after the guest parses. Query-time dump anchored on the first live TOC76-XSF entry read (`toc_parsed.bin` @ gpu_device.cpp:10669 block, w55) captured the parsed table; frontier unchanged in w53/w55 (`C0000005 0`, `Fatal 2`).
- **E1 — star_glow.fxc IS in the table.** `toc_parsed.bin` (base C60B7780) at +0x41FC0: record `A5EA667B 00002ABC 00306000 40000E79` = GtaO('star_glow.fxc') (=A5EA667B, python reimpl validated against F-090's two known pairs), stored 0x2ABC=10,940, data word 0x00306000, flag word bit30 SET. Its sibling `A84F6A07 … 40000EA8` follows at 16B stride. globaltex.list (0x402C0) and preload.list (0x40610/…) same layout — this is the complete RPF member table, decrypted AND parsed by the guest by t=22:09:59.
- **E2 — the failing lookup used the other device.** GETDEV-E0 (w48:5056 etc.): mount `a:/archive/` has `dcnt=2`: d0=C60ABD08, d1=C60AC180, both `vt=82012BDC`. Texture-list queries run against **d1** (`TOC76 obj=C60AC180 inner=C60B7780` → FOUND, e.g. #57). The star_glow queries run against **d0** (`TOC76 #86 obj=C60ABD08 inner=C60ACE00 start=80000001 cnt=00000002` → ret=0). d0's entire index is 18,432 B (`early_decrypted.bin`) and a GtaO join against a 100k+-token name pool from `mcla_pe.bin` finds **zero** game names in it — d0's table is empty-of-content, while d1's answers 313 directory/file names (preload, shaders, textures, anim, raceeditor, script_obj… record classes: dir nodes `{hash,0,8000xxxx,nchildren}`, file records `{hash,size,offset,40000xxx}`).
- **E3 — why the chain never retries on d1 with the clean path.** The fallback walk (w48:5061-5116) tries `embedded:/dcl/star_glow.dcl`, `embedded:/star_glow.dcl`, `embedded:/fxl_final/star_glow.fxc` (embedded 15-name list, honest miss), then arrives at a **path-building corruption**: `GETDEV #41 path='a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl'` — the leaf is re-prepended 3× — and the `fxl_final/star_glow.fxc` attempt that does happen (#86) lands on d0. The request that would hit d1's real entry never runs. Two defects stack: (i) d0 index unpopulated, (ii) the retry chain builds a mangled path instead of re-issuing against d1.
- **Verdict for B2.** Not content-absence (F-089's framing retired). The archive carries star_glow.fxc; the guest's RPF parser works; the mount's first device is the broken one. Open question (B2b next, cheap): what normally populates d0's index — candidate is an RSC5/XSF package header the guest reads at mount, cf. the `RSC 173 hits` cluster in gpu_device.cpp; the 2-entry `cnt=0x2` at #86 says SOMETHING was parsed. Evidence path: census sub_821CBE18's other caller set + d0-inner creation (`TOC76 #1..#2` window in w55 covers the first queries; their inner base is C60ACE00 already at boot-time #5033 region).
- **Also fixes a method trap (rule 14/15 cousin):** a fill-time dump of a table the guest parses LATER is a picture of the input, not the structure — the first verdict (w53) was nearly written as 'names absent' from exactly that wrong-time capture.

### F-097 — B2b interim: both mount devices answer "absent" for the CLEAN `a:/archive/fxl_final/star_glow.fxc` on the table that demonstrably CONTAINS it; the search's d0 inner reads ran off their bounds into pointer junk. Device selection exonerated (F-096's d0-shadow framing retired); the defect is inside the guest TOC search's table bounds.

- **DEVCLAIM census (w56, `sub_821CDB88` = vtable[+4] claim fn, hook at gpu_device.cpp after PAGER block).** The device loop (sub_821CB650, decoded: advances ONLY while r4==-1) asked BOTH devices the clean path: `#48 dev=C60AC180 … r3=FFFFFFFF` and `#49 dev=C60ABD08 … r3=FFFFFFFF` (r3=-1 = not-mine) — d1 with the full parsed table said NOT FOUND for star_glow.fxc even though its record is provably inside that very table (see below). Loop-termination theory (d0 shadow hiding d1) refuted; F-096's title claim is hereby narrowed to "entry present", not "wrong device asked".
- **Entry presence re-proved from the query-time dump:** record schema cracked offline — `{GtaO(leaf), size, dir<<16|(offset/100), 0x40000000|index}`: `globaltex.list` = dir13/idx236/offset 0xD0000 (byte-exact vs the earlier window match), `star_glow.fxc` = `A5EA667B 00002ABC 00306000 40000E79` at +0x41FC0 → **dir 48, idx 3705, offset 0x306000, size 10,940**; `fxl_final` hash present as its own record. A 24-member dir cluster around the leaf was enumerated. So the parsed table HAS the leaf under its directory.
- **The search overrun, from the census the guest itself gave us:** TOC76 #86 (d1 query for 'fxl_final/star_glow.fxc'): `e8=A39DCA00 e12=5F770000` — A39DCA00 is GtaO('resources') appearing as a POINTER, 5F770000 is ASCII junk as a POINTER. The probe list ran off the end of a small table into foreign data. Contrast #57 (globaltex, SAME d1-style flow) which landed on a real entry. Leading hypothesis for next step: search is directory-walk (split path on '/'), and root/intermediate lookup for `fxl_final` resolves through a per-dir child array whose count field the host serve path never filled (mount-time structure), so the leaf probe starts from wrong bounds.
- **Method notes.** Offline join recovered 313 names in the full table with `token+ext` GtaO synthesis (rule 15 discipline: aligned-dword set, exact strings, no text grep). Unicorn-style guest code replay ruled out (no ppc emulator installed; inventing one is a detour, recorded per plan-discipline). Frontier UNCHANGED w55→w56 (C0000005 0, Fatal 2; DEVCLAIM log is read-only). `w56` baseline; instruments now: XMEM-honest, PUMP1/2, PAGER, B1 watchpoints, DEVCLAIM, TOC-DUMP2 query-time.

- **F-097 addendum (same session, static):** `sub_821CCEA0` is a vtable SETTER (`stw 0x82012BDC` then `bl sub_821CBEB0`), not the search — the `lr=821CCED0` on TOC76 lines is a return into this ctor. `sub_821CBEB0` decoded: a TABLE RESET/release — frees obj+0x20 via its vtable[+52] only when `[obj+0xC] != -1`, then zeroes +8/+4/+0x20 and writes sentinel `-1` to +0xC. A healthy-but-empty device inner must read `e12=FFFFFFFF`; #86 read `e12=5F770000` (bit30-set junk) ⇒ d0's inner object was **never initialized through this reset path at all** (or was overwritten after) — it is not merely empty, it is foreign/never-owned memory being searched as a table. Next static target (B2b-3): find callers of `sub_821CBEB0` and of the sibling init at `sub_821CB9D8` (r5=1) — whoever resets d1's inner at mount must have a skipped-for-d0 branch; that branch is the fix site, and it is inside RAGE mount code, so the answer is a path/flag difference in OUR mount call, likely the RSC5/XSF header serve the devices read at 22:09:06 (#1/#2 RD-BUFs) — ties back to the DISCCHK flag family.


### F-098 — B2 converged: the search, the table, and the devices are ALL exonerated — `star_glow.fxc` lives under `shaders/{ui,characters,cars,effects,city}/fxl_final/`, but the effect loader queries root-relative `fxl_final/star_glow.fxc` (template literal in-image), and that root-relative form has no root entry. Only the five `shaders/*/preload.list` (the never-decoded, never-read members) can supply the real prefix. This is why the retail `wasn't preloaded properly` fatal exists, and it is the whole of B2.

- **The search is fine.** Same query minute: `TOC76 #85 obj=C60AC180 inner=C60B7780` ran the FULL-table search for `fxl_final/star_glow.fxc` (d1 DID get asked — DEVCLAIM #48; F-097's device-selection confusion retired) and returned not-found; while `#57` found `textures/global/cars/globaltc.list` **by full path through the same table in the same style**. Root table = 14 nodes (`ui@0x30 textures@0x80 shaders@0x70 legals.xsf@0x3a0 …`); `fxl_final` is NOT a root child (verified: all 5 occurrences at 0x40640/0x40a30/0x412a0/0x41b30/0x41dd0, each in a shaders/<sub> cluster, dir-node form `{D7E10D83,0,8000xxxx,count 16..67}`, adjacent to `ui/characters/cars/effects/city` nodes at 0x405c0-0x40600 and the five `preload.list` records 0x40610-0x41db0). `star_glow.fxc` record itself = dir 48, idx 3705, size 10,940, offset-word 0x306000 (BE-only occurrence ×1, LE ×0 — not a pointer collision).
- **The loader's path is the defect carrier.** Template strings `fxl_final/…` exist at 0x820093D4/0x8200A06C/0x82041 8B0/0x8206ABDC/0x8206DD30… (8+), name-table cluster at 0x82040EC0 confirmed (`draw_starglow/StarTexture/star_glow/mcLightStreakTune`). Root-relative query + empty group table = exactly the code path that raises 'wasn't preloaded properly'. F-094 (no decode feed) + F-095 (no reader) + F-098 (path prefix only knowable from the lists) triangulate: **nothing downstream of the lists can ever succeed; the lists ARE the blocker**, and the archive layout proves the game must have consumed them at mount somehow.
- **New lead for B2c (first byte checked):** disk 0x60000 (inside the first read window pair 0x60000/0x68000) begins `05 43 53 52 00 00 00 09` = **'CSR' package magic family** — the RSC5/PKG parse cluster in the host (gpu_device.cpp ~247 mentions) is the likely retail consumer route: preload lists are members of RSC5 packages whose header the package parser mounts. Next: census who parses the 0x60000 CSR header in-guest, and whether the host PKG cluster ever hands it a valid stream (ties F-058's 'wrong package window' thread with the retire-DISCCHK B3 goal).
- Method: pure offline joins per rule 14/15 (GtaO synthesis over ~1.4M image-name candidates; BE/LE disambiguation; dir-node vs file-record shapes) — ZERO new instruments, ZERO soaks; frontier unchanged. Scratch scanners deleted; census code unchanged this round.

### F-099 — B2c CLOSED BY IDENTITY, NOT BY DEFECT: device d0 is `xarchive_audlo.rpf` and d1 is `xarchive_cache.rpf`, the guest's own two-archive mount list at `0x8203966C` is executed exactly, BOTH TOCs decrypt and parse, and the fatal's complete candidate list is now on the record — six paths, none of them ever containing `shaders/`. F-096's "index-population failure on d0" and F-098's "CSR@0x60000 package lead" are both retired.

- **d0 = audlo, d1 = cache (log, not inference).** `w58.log:627` `MOUNT76 #1 path='a:/archive/' dev=C60ABD08` and `:732` `MOUNT76 #2 … dev=C60AC180`; the buffers those devices search were filled at `:623` `NFS-CENSUS[Read] #0004 h=C60ACD00 len=18432 off=0x800` (handle `C60ACD00` = `game:\xarchive_audlo.rpf`, opened `:606-608`) and `:662` `#0006 h=C60B7680 len=382976 off=0x800` (`game:\xarchive_cache.rpf`). TOC-DUMP3 confirms from the query side: `w58.log:5319` `TOC-DUMP3 d0 wrote=1 okread=1 inner=C60ACE00` — `C60ACE00` is the audlo read destination, and `TOC76 #82 obj=C60ABD08 inner=C60ACE00 … e8=A39DCA00` (`:5298`) shows that table's first child really is `GtaO("resources")`. **So "d0 has no shader names" is correct behaviour for an audio archive, not a defect** — F-096's index-population framing is retired, and the 18 KB table decodes to exactly audio/paint content: 38 GtaO hits vs chance ≈0.04 (`resources`, `audio`, `music`, `story/cut_intro`, `bike`, 18 `vp_*` vehicle paints, `agro/roar/garage/grip/pulse/zone/lookback/mirror/stop/reverse/animation/player/opponent`), and zero hits for `shaders 938B83B2`, `fxl_final D7E10D83`, `star_glow.fxc A5EA667B`, `star_glow.dcl D8DABDFA`, `preload.list 0DB1C876`.
- **The mount phase is complete for this stage — nothing is missing from it.** Image literal `game:/xarchive_audlo.rpf;game:/xarchive_cache.rpf` @`0x8203966C`, sitting with `a:/archive/` @`0x82039344`, `Cannot mount archive '%s' at 'a:/archive/'` @`0x82039350`, `Mounted archive %s` @`0x82039650`. Only those two `.rpf` files are ever opened in the whole boot (`NtCreateFile` yields exactly two packfile names), both mount under one 11-char prefix (`pfx=0000000B`) as `dcnt 1 → 2`. Other mount lists exist for later phases and are NOT yet exercised: `game:/xarchive_audio.rpf;game:/xarchive_music.rpf;game:/xarchive_cache.rpf` @`0x82000F48` (audio+music ARE on disk and ARE policy-allowed) and `$/preload/xarchive_bootscripts.rpf;$/preload/xarchive_cameratune.rpf;$/preload/xarchive_carconfigs.rpf` @`0x82000EE0` (these three are NOT on disk; do not chase them — no phase has asked yet).
- **The guest's whole candidate enumeration for the fatal is now on the record** (`w58.log:5255-5328`, GETDEV #38-#43): `embedded:/dcl/star_glow.dcl` → `embedded:/star_glow.dcl` → `embedded:/fxl_final/star_glow.fxc` → `a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl` → `a:/archive/dcl/star_glow.dcl` → `a:/archive/fxl_final/star_glow.fxc`. **No candidate ever carries a `shaders/<group>/` prefix**, and the doubled-path #41 is the guest's own enumeration (clean forms bracket it on both sides), not a host concat. The archive's own records for those names are `star_glow.dcl` @TOC `0x41ed0` {…,89,0x305F0C,idx 0x53} and `star_glow.fxc` @`0x41fc0` {…,0x2ABC,0x306000,idx 0xE79}, both inside the fifth `fxl_final` cluster whose `preload.list` is @`0x41db0` {0x170 bytes,0x304E12} — i.e. the group prefix is only knowable from that 368-byte list, exactly as F-098 concluded, now with the record addresses attached.
- **The archive subsystem is exonerated end-to-end (a fact worth money later).** `tools/rpf_offline.py header` shows both archives' header dwords are LITTLE-endian while their TOC records are BIG-endian, and the +4 field IS the TOC length the guest asks for: cache `382976 (0x5D800)` → read `len=382976 off=0x800`; audlo `18432`, audio `30720`, music `2048`. The on-disk TOC is opaque (`0x800` = `b1 16 a6 ab 95 7c e9 f9 …`) while the in-guest copy is a clean **hash-sorted** record array (`00000000 0000000E 80000001 0000000E` then `097D1470/0A802776/1B2D32DB/26AD3FE0/3529E9DA/4049095C/938B83B2/A26A72DD/A39DCA00` ascending). So decrypt→parse→sort works for both tables, and F-076's "no greppable TOC" is explained by *hashing + AES*, both of which the guest already defeats for us in memory. Trap recorded: an in-guest dump is NOT the on-disk format — `find` against the raw archive returns 0 records for a path that resolves in the dump (the tool now says so in its own output).
- **F-098's CSR lead is retired as self-referential (do-not #20 again).** `headBE=05435352` at disk `0x60000` reached the guest only because `INFLATE-HOSTSERVE` chose that offset itself: `w58.log:3584` `INFLATE-CORRUPT #1 in=0xfffffff4 (signed -12)` (the guest's own inflate state asked for a *negative* input), `:3586` `DEST-PKG outPtr=A47FD000 -> off=00060000 (job1/other)` (host infers the offset from the OUTPUT pointer), `:3589` `INFLATE-HOSTSERVE #1 off=00060000 got=32768 headBE=05435352`, `:3595` `INFLATE-RSC5 #2 … — skip 12B header`. `src/gpu_device.cpp:6887-6899` is the active re-point ("REFORCES … re-points st+0/st+4 at remaining guest-heap package bytes"), i.e. the RSC5/CSR narrative downstream of that point measures the host, not the guest. Any B2 claim must therefore come from *outside* this chain; `-12` at `st+0` is itself the honest observation (a 0-length member minus a 12-byte header).
- No-offline-shortcut result (so nobody re-tries it): the list member's bytes at `0x304E12+0x170` and the `.fxc` body at `0x306000` are 32%/27% printable with no path text, and a 122 MB plaintext scan `0x200000..0x7A00000` finds **0** hits for `star_glow`, `fxl_final`, `.fxc`, `preload.list`, `legals.xsf`, `shaders/`. The only >12-char plaintext in that window is `; (version 2) see grcore/fvfchannels.h for bit values` twice (`0x304ECD`, `0x310EE4`) — real member text in an otherwise transformed region, i.e. per-member compression, not a uniform stream. Conclusion: the group prefix is unreachable offline; it must come from the guest decoding its own list member.
- Instruments this round: `TOC-DUMP3` in `src/gpu_device.cpp` (`sub_821CBFC0` hot branch, anchored `obj==0xC60ABD08` + `star_glow` in the path, query-time, writes `build/d0_parsed.bin`), and `tools/rpf_offline.py` (`header`/`names`/`find`/`member`/`islands`) as the durable form of the GtaO join. Frontier unchanged: `w58` vs `w46` — C0000005 0/0, `Fatal error` 2/2, `DRAW_INDEXED` 0/0, `CP-DRAW` 52/52, `GETDEV` 168/168, `TOC76` 334/334, `PRESENT` 68/68. The `star_glow` label moves 41 → 48 and EVERY line of that delta is ours: +6 `DEVCLAIM` (F-097 instrument), +1 `TOC-DUMP3`, and the guest's own six candidates appear 6× each under `GETDEV`/`GETDEV-RET`/`BDF20`/`TOC76`/`TOC76-SG` in BOTH soaks — a per-label split, not a `+1`, is the only honest way to quote a census that has accumulated printer lines across four findings (do-not #20, again). Next: B2's remaining choice is the read→decode seam itself (why no list member is ever handed to `sub_8244FF20`, F-094) *without* going through INFLATE-HOSTSERVE, or B2 records criterion-(b).

### F-100 — B1's VERDICT IS VOID: the DR watchpoints never worked (`SetThreadContext` accepts and silently drops `CONTEXT_DEBUG_REGISTERS` on a running thread), so "no consumer touches the .list pages" was never established — AND B2's stop point is located in our own code: `HOSTSERVE-BLOCKED` gives every `shaders/*/preload.list` open a null serve (`buf=0 size=0 handle=0`), while F-098's "only the lists know the prefix" is corrected: the guest already resolves all five group paths by full name and `star_glow` sits in `shaders/effects/`.

- **The control that killed B1.** `w59.log` armed 18 threads, each printing `B1-ARM tid=… ok=true dr0=1C6157B80 dr1=1C6167C00` (`g_base + va`, and the guest heap IS mapped at host `0x100000000` — `src/kernel/memory.cpp:10-17`, `src/boot_host.cpp:67-68`), and logged **0** `B1-WATCH`. The same threads then executed `GuestMemoryHeap::ReadBytes(buf, raw, 16)` on exactly `buf=C6157B80` inside the RD-BUF census (`src/gpu_device.cpp:10144-10146`, 16 `RD-BUF` lines with `read=1`) — a *host read of the watched 8 bytes with RW-armed watchpoints*, which is inescapable if the registers were live. It produced nothing. So the arming is inert: Windows honours debug-register context only for a suspended or debugged thread, and `ok=true` is not evidence of effect (the B1-ARM self-report added for F-095's audit proved *acceptance*, never *effect* — the trap generalises: an instrument's own success flag is a hypothesis until something known to happen is shown to happen).
- **Consequence.** F-095's "zero hits ⇒ no consumer reads the member pages ⇒ the missing-decrypt world is refuted" is retracted; the fork F-094 opened is **still open**, and B1 must be re-run on a live instrument. The failed fix is recorded so nobody re-tries it: arming from inside the VEH via `__debugbreak()` was built and soaked (`w60.log`) and **killed the boot at the first arm** — 128 lines, exit 3, last line `PARK-SAMPLE` right after `[boot] starting guest worker thread`, i.e. the int3 was not consumable as designed here. Both edits were reverted (`src/boot_host.cpp` back to its committed form, the read-site arm call removed from `src/gpu_device.cpp`); nothing from that experiment is in the tree, and `w60` is not a baseline.
- **B2's stop point is ours, and it is a *correct* block that was never finished.** `w58.log:4527-4554`, first pass of `shaders/ui/preload.list`: `GETDEV #28` → `TOC76 #61` **finds** the entry (`ret=C60F7D90 toc=[0DB1C876 00000104 001DD11C 4000007E]`) → `XSF-OPEN #24 ret=0` → **`HOSTSERVE-BLOCKED path='shaders/ui/preload.list' (T41.3g/F-077)`** → `XSF-POSTOPEN-SERVE … buf=00000000 size=0 dev=C60AC180 handle=0` → `DEVCLAIM #24 → r3=00000000` → `BDF20 #4 ret=C2C2…`. The same shape repeats for all five groups and 185 `preload.list` lines in one soak are that loop turning. T41.3g's reason stands verbatim (`src/gpu_device.cpp:477-487`: the `.list` members are *compressed*, stored 126-460 vs expanded 260-1246, and raw-serve "bypasses the guest's own TOC arithmetic") — deleting the block would reinstate a stand-in. **The unfinished part is the faithful route: give the guest a real handle for an archive member and let its own read position/length come from its own TOC entry.**
- **F-098 overreached in one particular, and the correction is useful.** The guest is NOT missing the group prefixes: `TOC76-XSF` in one soak resolves `shaders/ui/preload.list`, `shaders/characters/…`, `shaders/cars/…`, `shaders/effects/…`, `shaders/city/…`, `resources/ui/legals/legals.xsf` and `textures/global/cars/globaltex.list` — six full paths, all found. The image carries the roots and names next to each other in `.data`: `effects`@`0x82041D6C`, `characters`@`0x82041D74`, `cars`@`0x82041D80`, `$/shaders`@`0x82041D88`, `$/textures/global/cars`@`0x82041D94`, and `$`-rooted mount lists at `0x82000EE0`/`0x82000F48`. What the empty preload table costs is the **effect→group association** (which of the five owns `star_glow`) plus the member bodies, not the directory vocabulary.
- **`star_glow` is in `shaders/effects/`, and the record arithmetic that proves it is now pinned.** A TOC `child` field is a *16-byte-record index*: `shaders` @0x70 = `{938B83B2,0,8000_405C,5}` → 5 records at byte `0x405c0` = `ui`(child 0x4061→`0x40610`, n=4), `characters`(0x41b1→`0x41b10`, n=3), `cars`(0x4128→`0x41280`, n=3), `effects`(0x41db→`0x41db0`, n=3), `city`(0x4085→`0x40850`, n=38). The `effects` cluster is `preload.list`@`0x41db0` {0x170 B,0x2DB9A1}, `dcl`@`0x41dc0` (child 0x41de→`0x41de0`, 18 records → `0x41de0..0x41ee0`) and `fxl_final`@`0x41dd0` (child 0x41f0→`0x41f00`, 18 records → `0x41f00..0x42020`). `star_glow.dcl`@`0x41ed0` falls in the `dcl` array and `star_glow.fxc`@`0x41fc0` in the `fxl_final` array, so the archive's real paths are `shaders/effects/dcl/star_glow.dcl` and `shaders/effects/fxl_final/star_glow.fxc` — the guest's own candidates with exactly one prefix missing, and the 18/18 counts say each `dcl` has a matching `.fxc`.
- Method + state: one control soak (`w59`) and one failed-instrument soak (`w60`, discarded); the F-099 instrument is unchanged in behaviour, `w59` == `w58` == `w46` on every guest marker; scratch scanners deleted (`tools/_*.py` gone), `tools/rpf_offline.py` reused, no new census code survives this round. Next in plan order: rebuild B1's discriminator on an instrument that can be *shown* to fire (first-access page-guard + restore in the existing VEH, with the census read as the built-in positive control), and in parallel the faithful member-open route above is what actually gates B2.

### F-101 — B1 ANSWERED ON A WORKING INSTRUMENT: the member windows ARE touched right after the fill, twice by guest code landing exactly on the buffer head (`sub_821CBE18+0x78` copies out, `sub_821E0FF0+8` byte-walks a header), and never by a decoder — so F-094's fork resolves to "the prototype consumes the bytes as-is", and the "silent unread pages" premise of F-095 is dead. Instrument: guard-page watchpoint with a mandatory self-test; `w64` is behaviour-neutral (`C0000005 0/0`, `Fatal error 2/2`, `GETDEV 168/168`, `TOC76 334/334`, `CP-DRAW 52/52`, `PRESENT 68/68` vs `w58`).

- **How the instrument was made trustworthy (rule 19 applied).** `B1GuardArm(va)` (`src/boot_host.cpp`, exported via `src/boot_host.h`, called from the RD-BUF census at `src/gpu_device.cpp:10206-10212`) sets the buffer's page to `PAGE_NOACCESS`, then deliberately reads one dword: the SELFTEST trip must appear or the arm is worthless. 14 arms ⇒ 15 `tag=SELFTEST` lines ⇒ every `ACCESS`/`LATE` trip below is earned. Handler `B1GuardHandle` claims by *page ownership list*, restores `PAGE_READWRITE`, and returns `EXCEPTION_CONTINUE_EXECUTION` so the accessor re-executes untouched.
- **Two prior versions of this instrument were wrong, and both are recorded so nobody repeats them.** `w62` (claim only while an `armed` flag is set) and `w63` (claim only if `VirtualQuery` still shows `PAGE_NOACCESS`) both let a *second* thread's in-window fault escape to the park machinery: `VEH W0: parking thread … code=0xC0000005` on a live guest thread, and the frontier moved — `C0000005 0→3`, `GETDEV 168→116`, `TOC76 334→260`, `Fatal error 2→0` (the star_glow fatal was never reached). **An instrument that parks a thread is not a witness.** The fix (claim every fault on a page we ever armed) costs a masking risk on those specific cache pages, which is why the armed set is capped at 32 pages and the tag distinguishes `ACCESS` (watch still live) from `LATE` (already consumed).
- **The trips, attributed by raw decode (rule 3, `tools/ppc_disasm.py`).** `w64` logs 10 `ACCESS` + 1 `LATE` on the archive buffers:
  - `trip 2/4 addr=TOC+4 guestLR=821E0FF8` → `sub_821E0FF0+8`, whose first instruction is `lbz r9,4(r3)` — a **byte-walk of the decrypted TOC header** at exactly +4 of `C60ACE00`/`C60B7780`. The guest reads the tables it decrypted (independent confirmation of F-099's parse claim).
  - `trip 6 addr=C6157B80 (exact buffer head) guestLR=821CBE94` → inside `sub_821CBE18` at +0x78: `lwz r11,8(r31) / add r4,r11,r29 / bl 823DA950` — the fiDevice read path **copies out of the member window with a computed (base+offset) address**, and no `XMemDecompress` (`sub_8244FF20`) fires between the fill and that copy (F-094's lone door). This is the direct refutation of F-095's "NOTHING ever reads its head — not a decoder, not a parser, not a copier": a *copier* does, at the head, in the device layer.
  - `trip 9/16/25 addr=C61378A0/C6137980 guestLR=821CCA28` → `sub_821CC970+0xB4`, i.e. the known pager frame right after its `lwz r10,0(r3); lwz r9,28(r10); mtctr r9; bctrl` (**vtable[+28]**) — the faulting accesses are *below* the armed buffer start, so they are in-page neighbours, not member bytes (limit stated below).
  - `trip 12/14/20/22 addr=C6167B80/C6157B00 guestLR=8244ED20 / 82135DF8` → `sub_8244ED10+0xC` and `sub_82135DC0+0x34`, both immediately after `bl 827BD984` / `bl 827BD034` — `0x827BDxxx` are XEX **import slots** (F-092), so these trips are our own host import implementations touching the page, not guest consumers.
- **Verdict for the plan's B1 fork.** "Missing decrypt stage" is NOT the world: the window is read/copied by the guest's own device path in its stored form and no decoder is entered (`sub_8244FF20` census unchanged, all calls still the 7 MB job). The surviving world is **"the prototype tolerates the bytes as-is"**, and it is now narrowed to a specific mechanism: `sub_821CBE18` copies from `base+offset` where `offset = [r31+8]`, so whatever consumes the copy decides the payload's meaning — that copy target is the next thing to name, and it is *not* the preload table's absence that keeps the table empty; it is the reader's own interpretation. B2 therefore proceeds on: (i) the faithful member-open route from F-100 (`HOSTSERVE-BLOCKED` ⇒ null serve is our own stop), and (ii) who receives `sub_821CBE18`'s copy.
- **Instrument limits, honestly.** Page granularity: a 32 KB window spans 8 pages and each page carries foreign heap data, so `ACCESS` proves *the page* was touched, not that member bytes were — two trips (TOC+4, buffer head) are exact and are the ones the verdict rests on; the other nine are neighbours or host imports. Watch is one-shot per arm (re-armed at every fill), budget 48 log lines, and it is log-only: `w64` proves zero frontier delta, so it stays in the tree rather than being reverted.

### F-102 — the preload chain is now NAMED end to end: `sub_823047D8` (the `$/shaders` consumer) makes five hard-coded per-group calls into the list loader `sub_82187820` (which owns 'preload.list file missing in %s'), all five run and none crashes, and the fatal sits one call from a single decision point — `sub_82187700+0x9C → sub_82189310+0xF8 → sub_82189138`, the function that holds BOTH 'using fallback %s' and 'wasn't preloaded properly' 64 bytes apart. New tool `tools/ppc_xrefs.py` makes this reproducible without IDA.

- **The tool needed its own positive control first (rule 19 again).** The first version reported 0 sites for `a:/archive/` — because `lis` is *`addis rT,0,IMM`* (primary opcode 15), not opcode 60, so the modelled `lis` branch never fired. After the fix: `a:/archive/` @`0x82039344` → 5 sites, and the mount-list string `game:/xarchive_audlo.rpf;game:/xarchive_cache.rpf` @`0x8203966C` → **exactly one**, `sub_822C4630+0x20C` — so `sub_822C4630` is the archive mount routine (a `.data` string with a single reference can only mean one caller), five sites in the same function family that F-099's log line (`MOUNT76 … lr=821CBF54`) shows calling the device layer.
- **One message, one site — the whole shader-preload vocabulary:**
  | message (VA) | materialising site |
  |---|---|
  | `Unable to load shader '%s', it probably wasn't preloaded properly.` @`0x8200B358` | `sub_82189138+0x130` |
  | `Unable to load shader '%s', using fallback '%s'` @`0x8200B2DC` | `sub_82189138+0x194` |
  | `Need to preload template '%s'!` @`0x8200B3A8` | `sub_82189438+0x5C` |
  | `preload.list file missing in '%s'` @`0x8200AEAC` | `sub_82187820+0x17C` |
  | `$/shaders` @`0x82041D88` | `sub_823047D8+0x28` (its only caller: `sub_822C2EA8+0xDC`) |
  `sub_82189138` (the fatal/fallback reporter) has two callers, `0x82189408` inside `sub_82189310` and `0x8218947C` inside `sub_82189438`; `sub_82189310` has exactly one, `sub_82187700+0x9C`. **So the fatal is a binary choice already present in the guest**: fallback vs fatal, inside one function — the 'fallback' arm is what `AFB76-FALLBACK` was built around (F-066 deleted a bad instance of it; the *guest's own* fallback path is a different thing and is now addressable).
- **The five loader calls, corrected and post-called (`w65`, `src/gpu_device.cpp` BOOTPATH census).** The old line printed a scrambled `path=` because it dereferenced each `desc[]` word — but `r4` is not a pointer array: `r4=82041D80` *is* the bytes `cars\0\0\0\0$/shaders`, so the record carries its strings inline. Fixed to render 24 bytes of the record plus the return value. Result: five calls, five **distinct** return addresses inside `sub_823047D8` (`lr=82304844/64/84/A4/C4`) — hard-coded per group, not a loop — for records `ui`@`0x8201F30C`, `city`@`0x82034C9C`, `cars`@`0x82041D80`, `characters`@`0x82041D74`, `effects`@`0x82041D6C`, each shaped `{name, 0|'$', ptr, ptr, "!!%s", "!!"}`. **All five return `r3=82860714`** — the same global that the star_glow init receives as `this` (`MSGBISECT 5-822FBAF8 r3=82860714`, `w58.log:5172`). So the loader is entered, does not crash, and still leaves the table empty; and each call's own `GETDEV 'a:/archive/shaders/<group>/preload.list'` is interleaved at the same millisecond (`w58.log:4522` BOOTPATH #1 → `:4527` GETDEV #28 → `:4540` `HOSTSERVE-BLOCKED`).
- **What this leaves for B2, stated as one experiment rather than a menu.** The guest's own pager read of the member *does* happen even with the serve refused (the 32 KB windows at `0x1D8000/0x1F0000/0x278000/0x2D8000/0x300000` are the five lists' regions, `w58` RD-SUBMIT #7-#16), and F-101 shows the head is copied out with no decoder entered. So the only remaining question with gate power is: **does `sub_82187820` parse what it copied, and reject it because `GetSize` reports the *stored* length where an expanded one is expected?** Test: publish the archive's own stored size for these members (never an invented one) and let the loader's open complete, so the loader sees exactly the bytes and length the archive states — if the table still stays empty, B2 records criterion-(b): this image's list path cannot consume a compressed member, so the retail expectation must come from a stage that is not in this image, and the fatal's gate is legitimate.
- Frontier unchanged by both this round's tools: `w65` == `w58` — `C0000005 0/0`, `Fatal error 2/2`, `GETDEV 168/168`, `TOC76 334/334`, `CP-DRAW 52/52`, `PRESENT 68/68`, `DRAW_INDEXED 0/0`.

### F-103 — B2 first experiment: the plan's "feed the *stored* bytes at the *right position*" branch is TESTED and does NOT clear the gate. Deleting T41.3g's refusal gives the loader real archive bytes at the archive's own offset and length, two of the four `DEVCLAIM`s now succeed (`r3=1`, was `0` in every prior soak) — and the star_glow fatal fires unchanged. **B2 stays open; criterion-(b) is NOT earned**, because the plan's other half ("transformed bytes") is untested. Change reverted, tree back at F-102 (`w68` == `w58` on every marker).

- **The single variable.** `src/gpu_device.cpp:475-487` (the `HOSTSERVE-BLOCKED` early return for `.list`/`preload`/`globaltex`) deleted; nothing else touched. `w66.log`: `HOSTSERVE-BLOCKED` count **0**, and `XSF-POSTOPEN-SERVE path='shaders/ui/preload.list' buf=C9CAE400 size=260 … toc=[0DB1C876 00000104 001DD11C 4000007E]` (city: `size=1246`, toc `[0DB1C876 000004DE 001F41FB 400001C4]`) — 260/1246 are the TOC's own stored lengths, `0x1DD11C`/`0x1F41FB` its own offsets, and the package-substitution path was already excluded for lists (`:544-549`), so no invented framing and no foreign bytes.
- **It changed the flow, and not toward the gate.** `w66.log:5024` `Fatal error dispatcher invoked - terminating game`, `:5027` fatal message `Unable to load shader '%s', it probably wasn't preloaded properly.` — same fatal, `star_glow` 48 lines as `w58`/`w65`. The five loader calls still all return `r3=82860714`. But `GETDEV` fell 168 → 43: with a body bound, the loader stops retrying instead of looping the refused open, so the *symptom* changed shape while the *outcome* did not. Two of four ui `DEVCLAIM`s returned `r3=00000001` (never before) — the open genuinely succeeded, which is what makes the negative informative rather than "the path was never reached".
- **Second probe, and the instrument lesson from it.** Widening the F-101 witness to the served arena (`(buf & 0xF0000000) == 0xC0000000` plus `B1GuardArm(xbuf)` at the serve site) produced trips on the served ui-list page itself (`w67`: `tag=ACCESS addr=1C9CAE400 want=R`, `1C9CB3080`, 9 trips at `1C9…`) — but the soak collapsed to 4,613 lines, so **`w67` is not citable and the change is reverted**. Recorded limit: the guard-page witness is safe on the archive page-cache arena (14 arms, zero frontier delta in `w64`) and unsafe on the served-body arena, which takes constant host writes; a witness there needs the write side excluded, not just a wider mask.
- **What B2 therefore still needs, named exactly.** The plan's option (i) has two halves and only one is done: stored-at-right-position ✗ (this entry), **transformed**-at-right-position untested. The transform is real work, not a wrapper: the lists are 575→~944 and 368→~752 style expansions (a `[entry+12]` low field of 236/188 reads as an *entry count* of 4-byte hashes, not a size), and F-094's lone-door proof says the only `XMemDecompress` call site in the image sits behind a 12-byte container header these members do not carry. So the remaining faithful options are (a) a host LZX/XMem inflate of the member (decoding real bytes, publishing the expanded length) — reference semantics available locally in `.research/xenia`, hours of work; or (b) reaching the guest's own *fallback* arm, which F-102 localized precisely (`sub_82189138` chooses fallback at +0x194 vs fatal at +0x130 — one branch, 100 bytes apart, and the branch's input is the preload-table lookup that just failed). Option (b) is the smaller experiment and does not require inventing content; option (a) is the one that would make the retail path actually run.
- **Sequencing consequence, stated rather than assumed.** B3 (retire DISCCHK) does not depend on this — and F-103 sharpens it: if a list member's `[entry+12]` low field is an entry count, then bit30-without-bit31 on exactly the six `.list` records is a *format* flag for "name-array member", not a readiness ack, which is the kind of answer B3 asks for. B4/B5 as written assume the fatal lifts; if B2 closes on option (a) they run unchanged, and if it closes on (b) or criterion-(b), the plan needs the user's re-approval before their gates are reworded (plan-discipline rule 14/18 note in `AGENTS.md`/memory).

### F-104 — B2's real blocker is an emulation gap, not a payload question: the preload-list loader `sub_82187820` is a **line reader**, it branches to 'preload.list file missing' purely on `sub_821BE8D8` returning 0, and even with T41.3g's refusal lifted and real 260/1246-byte bodies bound (`w71`) its line loop is never entered — because `BE8D8` is host-completed only for **memory-device** streams (`dev == 0x827D838C`, handle = slot < 16) while the archive post-open serve binds the wrapper to `{archive dev, open-ret}`. Compressed-vs-text is not yet reachable; the missing piece is the stream contract the `.xsf` path already implements.

- **What the loader's code actually is** (`tools/ppc_disasm.py` on `sub_82187820`, rule 3): `bl 821D1CE8(r3=r1+208)` sets up a reader, then a loop `bl 821CFAA8(r3=r1+208, r4=r1+80, r5=128)` pulls one 128-byte **line**, three `bl 823DB730` calls tokenize it, `stb r24,0(r31)` with `r24=0` writes NUL terminators, and each line goes to `bl 82188E50(r3=r1+80)`. The 'file missing' message at `+0x17C` sits on the branch taken when `cmpli cr6,r3,0` after `bl 821BE8D8` is true. So: text format, one line at a time, and **the only gate before the first line is a stream open**.
- **New instrument, and its deterministic result.** `LISTLINE` (a census on `sub_82188E50`, the per-line handler; `src/gpu_device.cpp`) prints the line buffer, `r4`, and the caller `lr`. It fires **exactly twice** in `w69`, `w70` (same binary — a repeatability control) and `w71`, both from inside the fatal function `sub_82189138`: `lr=82189234 text='embedded:/star_glow'` and `lr=82189248 r3=82040F0C text='star_glow'`. Zero calls from the loader in any configuration tried ⇒ the line loop is never entered. Side benefit: `0x82040F0C` — the "star_glow name-table VA" F-095 planned to watch — is simply where the bare string `star_glow` lives, now proven by reading it.
- **The un-blocked run proves the point rather than the payload (`w71`).** With the `.list` refusal temporarily removed: `XSF-POSTOPEN-SERVE path='shaders/ui/preload.list' … size=260`, `XSF-OPEN` ret goes 0,0,**1,1** per group and `DEVCLAIM → r3=00000001` for the 3rd/4th claim of every group (never seen before), `BDF20` returns `0xC2C2…` poison. Yet no line is read and the fatal is identical (`w71.log:5004/5007`, `Fatal error dispatcher invoked` + the same message). So the archive bytes being stored-compressed is NOT the current binding constraint — the guest never gets to look at them.
- **The named mechanism gap, with the fix already present elsewhere in the tree.** `src/gpu_device.cpp:11639` host-completes `BE8D8` only `if (dev == kMemDeviceObj && h < kGuestSlotCount)` (memory device `0x827D838C`, slot table `0x82860740`), and the working `.xsf` serve does exactly that: `MakeMemoryStream(kMemDeviceObj, xbuf, xsz)` + `MclaRegisterServedBody(..., kMemDeviceObj, st, ...)` (`:11512-11542`). The archive post-open serve instead writes `0x82860C18` with `{dev, open-ret}` (`:10936-10938`) — i.e. a packfile device with a garbage handle — so `BE8D8` falls through to the guest's own archive stream code, which fails. **B2's next experiment is therefore a completion of our own emulation, not of guest data: hand an archive member the same memory-stream contract.**
- **Codec probe, recorded so it is not re-run blindly** (scratch, deleted): the six list members at their TOC offsets measure 3.88-7.15 bits/byte, contain **no** 4-byte-aligned word that is any hash the archive TOC itself uses (0 non-zero hits; the apparent hits are zero-words), one is 55% zero words (173 of 311), and none is ASCII. Neither "plaintext hash array" nor "AES ciphertext" fits; but per the above this is currently moot.
- State: `w69`/`w70` (LISTLINE only) == `w58` on every guest marker — `C0000005 0/0`, `Fatal error 2/2`, `GETDEV 168/168`, `TOC76 334/334`, `CP-DRAW 52/52`, `PRESENT 68/68`, `DRAW_INDEXED 0/0`. `w71` (temporary un-block) and `w70`-binary-identity are documented above; the un-block is reverted, T41.3g's refusal is back, and `w72` re-confirms the final tree.

### F-105 — B2's transform is identified and validated: all six `*.list` members are headerless raw-DEFLATE (RFC1951) streams that expand to CRLF shader/texture NAME LISTS, the guest carries zlib 1.2.3 but never calls it for them, and feeding the expanded bytes at the ARCHIVE layer makes the guest parse the list and open all eight named textures — which is the first time this boot consumes list content, and it ends in a page-retry wedge that is now the named blocker. Supersedes F-073's stored/expanded numbers and F-104's "missing stream contract".

- Task:        T41.3p/3q (B2), logs `build/w74.log` (host-serve seam), `build/w75.log`–`w77.log` (archive seam), `build/w78.log` (reverted state)
- Type:        FACT (the transform) + two labelled mechanism changes (the seams)
- Class:       E (filesystem/archive) with G (the game's own loader behaviour)
- Priority:    P0
- Evidence:    `build/cache/mcla_pe.bin` file `0x17F00` = VA `0x82017F00` " inflate 1.2.3 Copyright 1995-2005 Mark Adler ", `length_base` u16-BE @`0x82017F30`, `dist_base` @`0x82017FB0`, `z_errmsg` pointer array @`0x82017ED0`; `w74.log:4562` `LIST-INFLATE path='shaders/ui/preload.list' tocOff=001DD11C stored=260 expanded=260 nl=15`; `w76.log:4475` `MEMBER-EXPAND off=000D0000 stored=575 expanded=575 nl=17`; `w76.log:4479` `GLOBTEX-BODY ... ascii='__noise 2dnoise3..__coloredNoise'`; `w77.log:4434` `TOC76-XSF #59 ... 'textures/global/cars/globaltex/2dnoise3.dds' [4C8E54E9 000155D5 000D1000 4001258B]`; `w77.log:5323` `NtReadFile: FAIL h=C60B7680 off=0x158000 len=32768 got=0 status=C000000D`; `src/raw_inflate.h`, `src/fs/vfs_rpf.cpp:646,683`, `src/gpu_device.cpp:488,854,10814`

- **The transform, measured twice independently.** `src/raw_inflate.h` (new, self-contained RFC1951 inflater — no zlib in this tree and zstd's wrapper needs it) was run over each member at its own TOC offset and reproduced Python `zlib.decompressobj(-15)` byte for byte: `ui 0x1DD11C 260→260 /15 lines`, `city 0x1F41FB 1246→1246 /78`, `cars 0x27F1AF 1108→1108 /61`, `characters 0x2DB9A1 496→496 /18`, `effects 0x304E12 368→368 /17`, `globaltex 0xD0000 575→575 /17`. Every stream is ONE final dynamic-Huffman block (`bfinal=1, btype=2`), `eof=True`, nothing unconsumed.
- **CORRECTION — supersedes F-073's size claim.** F-073's "stored 126-460 vs expanded 260-1246 (1.96-3.76x)" is wrong about the archive: recompressing each decoded text at level 9 yields exactly 126/132/188/236/452, so those were a host-side recompression measurement, not stored lengths. The archive stores each member at a span whose length EQUALS its expanded length (the packer pads the Huffman coding to the TOC slot), and the TOC's `[entry+4]` size is that length. `src/fs/vfs_rpf.h`'s header comment carried the old numbers and is corrected in the same commit. Consequence for the reader: a member's `stored != expanded` heuristic cannot detect compression in this archive — the deflate block type can.
- **CORRECTION — supersedes F-104's diagnosis.** F-104 concluded the blocker was the missing `BE8D8` stream contract for archive devices. It is not: with T41.3g's refusal lifted, `BE8D8-PACK` delivers all five preload bodies + `globaltex.list` to the loader with correct sizes and the loader's own `lr` (`w74.log:5036+`, and `w71` before it), and the line reader `sub_82188E50` still fires exactly twice, both from the fatal function. The contract was already fine; the payload was the blocker.
- **Seam 1 (host-served body expanded) — neutral, and that is a result.** `HostServeUiBody` refuses list paths since T41.3g; the refusal is retired (`src/gpu_device.cpp:473-500`) and the body served expanded. Frontier markers identical to `w72`/`w58` (`C0000005 0/0`, `Fatal error 2/2`, `GFx 3/3`, `GETDEV 168/168`, `TOC76 334/334`, `CP-DRAW 52/52`, `DRAW_INDEXED 0/0`): the guest's loader does not read what the host-completed `BE8D8` hands it. Serving the *right bytes at the wrong position* changes nothing, exactly as the plan predicted for that half.
- **Seam 2 (expanded at the archive layer) — the guest consumes the content.** `RpfVirtualFileSystem::ReadFileAt` is the single funnel for both the guest's page pump (`NtReadFile` → `src/kernel/imports.cpp:1092`) and host-serve; substituting the expanded span there (`src/fs/vfs_rpf.cpp:646`, registered from the guest's own TOC words at `src/gpu_device.cpp:10814`) makes the guest's page-cache copy readable text, and it then acts on it: `GLOBTEX-BODY ascii='__noise 2dnoise3...'` and 8 named `.dds` members resolved by TOC (`2dnoise3`, `2dnoise4`, `anisodir`, `billettanmap`, `cf_bump2`, `dmg_scrape`, `no_damage`, `powerup_beam`), 14 lookups each. **This is the plan's B2 "feed the correct transformed bytes at the right position" earned for the texture list** — the position is the archive read, not the served body.
- **And the named blocker, which is B2's remaining half.** After those opens the guest re-issues `NtReadFile(h=C60B7680, off=0x158000, len=32768)` → `got=0 status=C000000D`, then 1339 attempts at `off=0x0`, 798,411 log lines, and the `star_glow` fatal never fires. So `w75`–`w77` are POISONED soaks (regression signal, not progress signal) and the default keeps the archive seam OFF (`kExpandListInArchive = false`). Note the read at `0x158000` lies inside the `0xD1000` texture member the list just named, so the wedge is the follow-on paging of named content — the next census, not a new short-circuit.
- **Instrument lesson (rule 19 applied to our own census).** `RD-BUF`'s `h=` field is read AFTER `__imp__sub_8244F4C0` returns (`src/gpu_device.cpp:10204`), so the spin's `h=00000000` is post-call clobber (the F-057 family), not a null file handle — the real handle is `C60B7680`, visible in `RD-SUBMIT a0=` and `NFS-CENSUS[Read]`. Reading it the other way round would have produced a "guest submits with a null object" claim.
- **Refuted sub-hypothesis, recorded so it is not retried.** "The host stand-in and the guest's own parse collide" was tested by switching both GLOBTEX name-injection stand-ins off (`kHostGlobaltexNameInjection`, `src/gpu_device.cpp:854`): the spin is unchanged (`w77` = 798,411 lines, same failing read). The stand-ins are therefore back on; they remain labelled stand-ins, and B3's DISCCHK retirement is untouched by this entry.
- **Predicate hazard found on the way (why `w75` exists).** Matching the list set by substring (`"globaltex" in path`) also matched `textures/global/cars/globaltex/*.dds` and registered 87,509-byte spans as expandable; combined with applying the substitution in the synthesized-`VirtualRpf` branch (a different address space) that run wedged too. Both fixed: the predicate is now a `.list` *suffix* test (`src/gpu_device.cpp:488`) and the substitution requires the physical `xarchive_cache.rpf` (`IsCachePackfile`).
- **State.** `w78` (default tree, archive seam off, host seam live) == `w72` on every guest marker above; deltas are `PRESENT 67/68`, `fatal 57/58`, `INFLATE-PENDING 0→3`, i.e. run-length jitter plus the extra served bodies.


### F-106 — The `w75`–`w77` read-retry spin was OUR OWN F-101 guard-page witness: `PAGE_NOACCESS` on an archive page-cache buffer makes a host-side `::ReadFile` FAIL with `ERROR_NOACCESS` (gle 998) instead of raising the exception the VEH handles, so every page the guest re-reads fails forever; retiring the arming (B1's verdict was already earned) and leaving the archive-level expansion on moved the guest's archive walk for the first time in the project's history — `GETDEV 168→680`, `TOC76 334→1176`, all six `*.list` members expanded, zero failed reads — and named the two next blockers.

- Task:        T41.3r (B2), logs `build/w79.log` (cause), `build/w80.log` (seam ON, arming OFF), `build/w81.log` (default tree)
- Type:        FACT + FIX (instrument retirement, labelled at its `file:line`)
- Class:       H (instrument artifact) for the spin; E/G for what the corrected run revealed
- Priority:    P0
- Evidence:    `w79.log:5199` `NtReadFile: FAIL h=C60B7680 off=0x158000 len=32768 got=0 status=C000000D lr=8244F548 (#1) [pos=1 rawHandle=00000A64 gle=998 path='xarchive_cache.rpf']`; `w80.log` `MEMBER-EXPAND off=… ×6`, `NtReadFile: FAIL` = 0, `GETDEV 680`, `TOC76 1176`, `-GATE 320`, `DISCCHK 16`, `BLIT-CAP 22`; `w80.log` `Vectored exception: code=0xC0000005 addr=0x7ff7f2f50564 rva=0x58D0564` + `Param[1]=0x100000e17` + `ppc lr=821BE508 r3=82860C68`; `w81.log` == `w78`/`w72` on every guest marker. Implem: `src/gpu_device.cpp:10242` (`kB1GuardArmFromReads = false`), `src/gpu_device.cpp:10824` (`kExpandListInArchive = false`), census in `src/kernel/imports.cpp` NtReadFile.

- **The instrument bug, with the number that names it.** `w76`/`w77` printed 1339 failed reads but could not say why: the census conflated "no `byteOffset`" with "position 0" and mapped every host error to `C000000D`. Adding `pos=`, `rawHandle=`, `gle=` and `path=` to that line (`src/kernel/imports.cpp`, T41.3r) produced `gle=998` = `ERROR_NOACCESS` on `path='xarchive_cache.rpf'`, `pos=1`, at a fixed `rawHandle` — the destination buffer was a page our own witness had marked `PAGE_NOACCESS`. A guard page hit by a *host* `ReadFile` does not raise the exception the VEH is built to service; the call simply fails, so the guest's retry re-enters the same poisoned page and the loop never ends. F-101's verdict was earned on 14 arms/15 self-tests; the arming is now off (`kB1GuardArmFromReads`, `src/gpu_device.cpp:10242`) while the instrument itself stays in `src/boot_host.cpp`.
- **Rule-19 lesson, generalized and worth keeping.** A witness that changes the behaviour of the thing it observes must be re-validated *whenever the access pattern changes*, not only at introduction: `w64`/`w68`/`w72` proved the guard neutral while the guest read each archive page once, and that proof silently expired the moment the expansion made the guest re-read them. The tell was not a frontier delta but a `got=0` count.
- **What the corrected run proves (seam ON = `w80`).** With the expansion live and the witness off, all six list members register and expand (`ui 0x1DD11C`, `city 0x1F41FB`, `cars 0x27F1AF`, `characters 0x2DB9A1`, `effects 0x304E12`, `globaltex 0xD0000`), no read fails, and the guest's archive activity roughly quadruples — `GETDEV 168→680`, `TOC76 334→1176`, `-GATE 75→320`, `DISCCHK 6→16`, `BLIT-CAP 5→22`. That is the archive/preload phase actually running, which every prior soak skipped. **This is the recommended working branch for B2/B3**, and `w80` is its baseline, not `w72`.
- **Two blockers named by that branch, neither masked.** (i) The boot still ends at the same guest fatal: `fatal-dispatch regs: lr=0x82189270 r3=0x8200B358` — `0x8200B358` is the `'wasn't preloaded properly'` string (F-102), so B2's gate is NOT yet cleared even with the content consumed. (ii) A new host AV appears 5×: `rva=0x58D0564` reading `Param[1]=0x100000e17` = `g_base + 0xE17`, i.e. a guest pointer of `0x00000E17`, with `ppc lr=821BE508 r3=82860C68` — inside the stream-wrapper family the host already completes (`BE610`/`BE8D8`, `kBdf20Wrap+0x50`). So a wrapper field we or the guest left near-null is being dereferenced at the point where the newly-parsed lists hand members to the loader.
- **Default state (verified).** Both new switches are OFF in the committed tree; `w81` census vs `w78`: `C0000005 0/0`, `Fatal error 2/2`, `GFx 3/3`, `GETDEV 168/168`, `TOC76 334/334`, `TOC76-RET 86/86`, `CP-DRAW 52/52`, `DRAW_INDEXED 0/0`, `DISCCHK 6/6` (and `w81` == `w72` on the same set). The read-failure census improvement is kept ON — it is pure instrumentation and it is what made this entry possible.
- **Supersede note.** F-105's "the wedge is the follow-on paging of named content" is half right and now corrected: the paging itself works (zero failed reads in `w80`); the wedge was the guard-page witness. `w75`–`w77`, `w79` stay classified as poisoned/cause-finding soaks, not baselines.


### F-107 — B2's mechanism is CONFIRMED end to end: with the archive-level expansion on, the preload-list loader `sub_82187820` reads 77 real shader names through its own line reader (`CityDefault … CityTunnel* … Character_visor_norm`, two lists consumed), which no soak in this project's history ever produced — and the remaining gap is now narrow and named: the loader stops before `shaders/effects/preload.list` (where `star_glow.fx` lives), and the only read that falls through to the guest's own `Read()` is a 25,286-byte request against the sibling wrapper `0x82860C68`, whose unbound fields are what the `w80` host AV follows.

- Task:        T41.3s (B2), logs `build/w82.log` (wrapper census), `build/w84.log` (wide LISTLINE), `build/w83.log` (default tree)
- Type:        FACT + FIX (census only; the expansion switch itself is F-105/F-106)
- Class:       E/G (archive + the game's own loader), with the AV as D (wrapper/kernel-side state we never bound)
- Priority:    P0
- Evidence:    `w84.log` 77 × `LISTLINE sub_82188E50 #1..#77 … lr=82187958` with `text='CityDefault'`…`text='Character_plastic_no…'` (that `lr` is inside `sub_82187820`, the loader F-102/F-104 named); `#78/#79` are the fatal reporter's own reads (`lr=82189234/48`, `text='embedded:/star_glow'`, `text='star_glow'`) — unchanged from baseline; `w84.log:9404` first `Vectored exception: code=0xC0000005` at 02:54:28.949, i.e. **between** loader lines (02:54:26.6→30.4), and reading continues after it; `w82.log` single `BE250-GUEST #400 obj=82860C68 dev=C60AC180 h=1 dst=CA715B80 count=25286 +8=82862DF8 +16=00000000 +24=00000000 +28=00000000 +32=00001000 lr=821BE93C`. Census sites: `src/gpu_device.cpp` `BE250-GUEST` (in the existing `sub_821BE250` owner, no new hook, rule 4), LISTLINE cap widened `n <= 40` → `n <= 600 || (n % 500) == 0`.

- **What changed in the instrument, and why the old number was unreadable.** `LISTLINE`'s `n <= 40` cap was still in force when the loader started producing names, so w80/w82 printed exactly 40 lines — indistinguishable from "exactly 40 lines exist". Raising it gives 77 loader lines: a count that matches the list content itself (city 1246 B / 78 newlines, characters 496 B / 18) and proves the loader consumed two whole members. F-089 §6's cap lesson applies to our own markers, including ones we wrote this week.
- **The reader is the guest's, not ours.** The 77 lines come out of `sub_82188E50` called from `sub_82187958`, i.e. the guest's own line loop, over the buffer the archive layer filled. `GLOBTEX-SERVE`/`MclaBootstrapGlobaltex*` (the host stand-ins, still on) are a *separate* mechanism and are not what produced these lines — they insert by a different route and log `inserted=`.
- **Where it still stops, stated precisely.** Names are read for `city` then `characters`; `shaders/effects/preload.list` (the member whose text holds `rain_system.fx`, `star_glow.fx`, `SoftPtx.fx` — measured in F-105) is never line-read, and the boot still ends at `lr=0x82189270 r3=0x8200B358` = `'wasn't preloaded properly'`. **So B2's gate is NOT yet cleared**, but the criterion is now "why does the loader stop after the second list", not "does the payload reach the loader".
- **The one fall-through, and its shape.** Of 400+ `sub_821BE250` calls exactly one reaches the guest's real `Read()`: `obj=0x82860C68` (a sibling of the `0x82860C18` wrapper our post-open serve binds at `XSF-POSTOPEN-SERVE`), `dev=0xC60AC180`, `h=1`, `count=25286`, with `+8=0x82862DF8` buffer / `+32=0x1000` capacity / `+24`=+28 position `0`. A 25 KB request against a 4 KB buffer through a wrapper the host never initialised is the `w80` AV's neighbourhood (`Param[1]=0x100000e17` = guest `0xE17`); the guest's buffered-refill path is the code that dereferences it. Next item is therefore to serve that wrapper (or bind it the way `0x82860C18` is bound) — a completion of our emulation, not a short-circuit — and then re-count LISTLINE to see whether `effects` is reached.
- **Default state (verified, no regression claim made from a capped marker).** `kExpandListInArchive = false` and the guard arming stays retired; `w85`/`w83` == `w81` on every marker (`PRESENT 67` vs `68` is run jitter): `C0000005 0/0`, `Fatal error 2/2`, `GFx 3/3`, `GETDEV 168/168`, `TOC76 334/334`, `TOC76-RET 86/86`, `CP-DRAW 52/52`, `PRESENT 68/68`, `DISCCHK 6/6`, `DRAW_INDEXED 0/0`. The two additions in this commit are log-only: at seam-OFF the LISTLINE count is 2 (`n<=600` prints the same two lines as `n<=40`), `w85` (final default tree, LISTLINE 2 = the reporter's own, unchanged) and `w83` both print `BE250-GUEST` 0 times: with the seam off no `sub_821BE250` call falls through, so the new census is silent by construction.
- **Baseline naming for the branch.** `w84` (seam ON, wide LISTLINE) supersedes `w80` as the seam-ON baseline: same frontier movement plus the loader-line evidence. `w80`/`w82` remain valid for their own markers.


### F-108 — The `w80` AV is NOT a stale wrapper field: the object that falls through to the guest's own `Read()` is fully coherent (`dev=C60AC180 h=1 buf=82862DF8 cap=1000`, every other word zero, and `0xE17` appears nowhere in it), so the fault address is computed downstream in the device path — and the seam-ON branch reproduces exactly (LISTLINE 77 loader lines in both `w84` and `w86`, zero failed reads in both), leaving B2 with two open items rather than one.

- Task:        T41.3s2 (B2), logs `build/w86.log` (seam ON, object dump), `build/w87.log` (default tree)
- Type:        FACT (refutation of F-107's stated next-step hypothesis) + census
- Class:       H (hypothesis killed by a measurement) → G/D for what remains
- Priority:    P1
- Evidence:    `w86.log` `BE250-OBJ #400 obj=82860C68 words=[C60AC180 00000001 82862DF8 00000000 ×5 00000000 … 00001000 @+0x20, zeros to +0x5C] boundWrapper=82860C18 …` (single occurrence; the fall-through count is 1 in `w82` and 1 in `w86`); `w86` `NtReadFile: FAIL|SHORT` = 0, `LISTLINE` = 79 (77 loader + 2 reporter) == `w84`; `w87` == `w81` on every guest marker with `BE250-OBJ`/`BE250-GUEST` = 0.

- **What was expected and what the dump shows.** F-107 proposed that `0x100000e17` came from an uninitialised field of the sibling wrapper, and the fix would be "bind it like `0x82860C18`". The 24-word dump refutes that: the wrapper holds exactly what a buffered `fiFile` should — device `C60AC180`, handle `1`, buffer `82862DF8` (a `.data` static), capacity `0x1000` at `+0x20`, positions zero — and the value `0xE17` is not in the object at all. So the faulting address is derived inside the guest's refill arithmetic or a device-vtable callee, not read out of this structure. Do not bind this wrapper on the strength of F-107's guess.
- **Two open items for B2, restated.** (i) The loader consumes `city` and `characters` line by line (77 names, reproducible) but never reaches `shaders/effects/preload.list`, where `star_glow.fx` is named — so the fatal's condition still holds. (ii) Five host AVs at `rva=0x58D0564` reading guest `0xE17`, occurring *between* loader lines and not stopping them, origin now known to be non-wrapper. Neither is a reason to expand the seam into the default tree yet: `kExpandListInArchive` stays `false` and `w84`/`w86` stay the branch baselines.
- **Census kept, cheap and silent by default.** `BE250-GUEST` + `BE250-OBJ` print only on a fall-through; at the default (seam OFF) there are none in `w83`/`w87`, so the markers are 0 without hiding anything (the fall-through count itself is uncapped — `n <= 40 || (n % 200) == 0` on the call index, and the calls that matter here were #400, printed by the modulo arm).


### F-109 — The `star_glow` fatal is a MISSING GROUP PREFIX, not missing content: the cache archive does hold the per-shader assets at group-prefixed paths (`shaders/city/dcl/CityDefault.dcl` → `ret=1 toc=[B8A98D20 0000006D 001F43BF 40000062]`, `shaders/city/fxl_final/CityDefault.fxc` → `ret=1 toc=[858AE657 00005CFF 001F5000 40001D9A]`; 379 resolved vs 140 empty-TOC `.dcl/.fxc` opens in `w88`), and the guest reaches those forms only for the ONE group whose list it actually line-reads — `shaders/city/preload.list` (77 of its 78 lines). For `star_glow` it never tries `shaders/effects/…` at all; every attempt is prefix-less (`dcl/star_glow.dcl`, `fxl_final/star_glow.fxc`, `embedded:/…`) or the doubled `star_glow/dcl/star_glow/dcl/star_glow.dcl`. So B2's remaining question is now exactly one: why do four of the five delivered lists never get read.

- Task:        T41.3t (B2), logs `build/w88.log` (seam ON + delivered-content census), `build/w89.log` (default tree)
- Type:        FACT (+ one labelled census change)
- Class:       G (the game's own loader behaviour) with E (archive paths/TOC)
- Priority:    P0
- Evidence:    `w88.log` five `BE8D8-PACK` deliveries, each with the new `head=[..] ascii='..'` field proving plaintext (`ui size=260 head=[416C7068] ascii='AlphaModulate.fx..Arrow.fx..'`, `city size=1246 '// Shaders listed here are real '`, `cars size=1108 'WheelRubber.fx..WheelBrakeRotor.'`, `characters size=496 'Character.fx..'`, `effects size=368 '// Shaders listed here are real '`); per-`BOOTPATH` line counts `ui 0, city 58, cars 0, characters 19, effects 0` (the 58+19 are one continuous read of the city list — its tail is `Character_visor_norm`/`Character_plastic_norm`, both city-group names); loop head disassembled at `0x82187920-0x82187984`: two `bl 823DB730` (insert), `stb r24,0(r31)`, `bl 82188E50` (the LISTLINE site), then `r5=128; bl 821CFAA8` = the actual 128-byte line read whose `r3==0` ends the loop at `0x821878F0`, and `bl 821BE610` = GetSize per name.

- **What is now excluded.** (a) payload/transform — every delivered body is plaintext of the right length (the `ascii=` field is the witness); (b) "the assets are not in this archive" — the city group's `.dcl` and `.fxc` records exist and open successfully; (c) F-099's "the group prefix cannot come from the lists" — it does: the only group whose prefixed asset forms were ever attempted is the one whose list was line-read, which is exactly what F-098's correction pointed at.
- **The one remaining shape of the failure.** The effects list is *delivered* (`BE8D8-PACK #83`, plaintext, 368 B / 17 lines) but its line loop is never entered, so `star_glow` is later requested with no group prefix and every candidate misses → `sub_82189138` prints `'wasn't preloaded properly'` (`r3=0x8200B358`). Same for `ui`, `cars`, `characters`.
- **Page-residency hypothesis: TESTED AND REFUTED in the same log.** If registration were too late, a member's page would have been pumped in before its `MEMBER-EXPAND-MARK`; the timestamps say otherwise for every group — `ui mark 03:15:21.296 / expanded 21.296`, `city 21.300/21.300`, `cars 25.061/25.062`, `characters 25.071/25.074`, `effects 25.204/25.205`, `globaltex 21.210/21.210` (and a page read for globaltex at 21.211). So the expanded bytes were in place for all six, in both routes (pump page and served body), and four lists still yield no lines.
- **What the parsed lines have in common, and what does not.** Every line the loader ever produced is an extension-less name (`CityDefault`, `CityGrime*`, `CityRoad*`, `CityTunnel*`, `Character_visor_norm`, `Character_plastic_norm`) — all of them from `shaders/city/preload.list` (77 of its 78 lines; the 58 + 19 split across two `BOOTPATH` windows is one continuous read, its tail simply names character-ish city shaders). The four dead lists begin with `AlphaModulate.fx` / `WheelRubber.fx` / `Character.fx` / `// Shaders listed here…`+`rain_system.fx`, so "first line is a comment" does NOT separate them: city and effects both start with the same comment line and only city is read. The discriminator is therefore inside the loader, not in the content shape.
- **Next census (named, not guessed).** The loop head at `0x82187920` calls `sub_823DB730` twice and its `r3` decides whether `sub_82188E50`/`bl 821CFAA8` are reached at all (`0x8218792C cmpi r3,0` → `0x82187934`, `0x82187940/44` → skip to `0x82187958`). Log that call's argument and both return values per group (`ui`/`cars`/`characters`/`effects` vs `city`) and the table cursor it maintains — that is where four of five groups diverge. Do not widen the expansion, and do not add a per-group stand-in.
- **Cost of the alternative reading.** If the discriminator comes back negative (page read after registration and still no lines), then the block is inside the loader's own per-group state — `sub_823DB730` (the insert called twice at the loop head) is the first thing to census, because its `r3` selects whether the loop reaches `sub_82188E50`/`821CFAA8` at all.
- **Default state.** `kExpandListInArchive=false` again after this diagnostic; `w89` census vs `w81`/`w72`. The delivered-content `ascii=` field on `BE8D8-PACK` is kept (log-only, prints on every packfile delivery, useful whenever a body-vs-TOC claim is on the table).


### F-110 — B2's remaining question is ANSWERED by measurement, and it is our ordering, not the game's: the loader tokenizes the member through the guest's OWN page-cache copy, and that copy is expanded only for the group whose span happened to be registered before its page was pumped — `ui`'s tokenizer buffer held binary garbage (`buf='??pP??5h'`, `'}??'`) while `city`'s held the expanded text word by word (`'//'`, `'Shaders'`, `'listed'`, `'here'`, `'are'`, `'real'`). F-109's "page-residency refuted" was itself an artifact: the read census used to test it is capped at `n <= 20 || (n % 100) == 0`, so its silence proved nothing (rule 19, aimed at my own instrument). Fix named, with a general key found in the same soak: all five `preload.list` records share leaf hash `0DB1C876` and `globaltex.list` has `3D9B8154`, so the spans can be registered from the decrypted TOC at mount instead of at first query.

- Task:        T41.3u/3u2/3u3/3u4 (B2), logs `build/w90.log` (token compare), `build/w91.log` (reader state), `build/w92.log`/`build/w93.log` (gate + slot), `build/w95.log` (buffer content — the answer); `build/w94.log` is VOID (stale exe)
- Type:        FACT (the cause) + FIX (four log-only censuses) + self-correction of F-109
- Class:       H (instrument artifact, twice: the capped read census and the stale exe) → E (archive/page ordering) for the cause
- Priority:    P0
- Evidence:    `w95.log` `CFAA8-LOADER #1..#5` group word `8201F30C`='ui' with `buf='??pP??5h'`/`'}??'`/`'?0?'` and `ret=3,10,61,1E,0`, vs `#6..#18` group word `82034C9C`='city' with `buf=''`,`'//'`,`'Shaders'`,`'listed'`,`'here'`,`'are'`,`'real'`,`'game'`,`'production'`,`'ones'`,`'CityDefault'` and `ret=2,7,6,4,3,4,4,10,4,14,13,11`; `w95.log` `TOC76-XSF … path='shaders/{ui,city,cars,characters,effects}/preload.list' [0DB1C876 …]` (same w0 for all five) and `'textures/global/cars/globaltex.list' [3D9B8154 …]`; reader identity: `sub_821CFAA8`'s own body compares a char against 32/9/10/13/0 (`0x821CFAC4-0x821CFAF0`) = a whitespace token split, not I/O; loader loop read verbatim at `0x821878F0-0x82187968` (`li r4,46; bl 823DB6D0` = find '.', `cmpli r31,0` gate, two `bl 823DB730` against `.shadert`@`0x8200AED0` / `.fx`@`0x8200AF00`, `stb r24,0(r31)`, `bl 82188E50`). Censuses: `src/gpu_device.cpp` `DB730-LOADER`, `CFAA8-LOADER` (stream words + wrapper + slot + `buf=`), `A490-LOADER`.

- **What each dead group was actually handed.** `sub_821CFAA8` is not a stream reader at all — its body classifies a character against space/tab/LF/CR/NUL, i.e. it splits the NEXT WORD out of the caller's 128-byte stack buffer (`dst=8EFFF6C0` = `r1+80`). So the `w92` framing ("the reader hits end-of-stream early"; its `0xFFFFFFFF` cursor word is the tokenizer's own state) was the wrong level: the bytes in that buffer are what matter, and for `ui` they are not the list.
- **The `w92` candidate is refuted.** "BE8D8's host completion clears the slot, so the loader's second open reads a dead slot" — the slot dump shows `slot[2]=[CA5C7200 00000104 0 0]` IDENTICAL for the ui and the city reads, and the wrapper `wrap@82860C40=[C60AC180,0]` likewise. The two groups differ only in the bytes they tokenize; slot reuse is not the mechanism.
- **Two instrument faults of my own.** (1) F-109's refutation of page-residency rested on `NFS-CENSUS[Read]` showing "none" for the relevant offsets — that printer is capped (`src/kernel/imports.cpp:1034`, `n <= 20 || (n % 100) == 0`), so absence of a line was absence of *printing*; a capped printer cannot support a negative (F-089 §6's lesson, re-learned one entry later). (2) `w94` is void: the build had failed with `error: expected expression` (a `'\n'` mangled into a raw newline by a patch script — rule 17's own class of bug), the soak silently ran the previous exe, and `w94` duly lacks the `buf=` field it introduced. Confirm `build_ninja.log` + exe mtime before naming a log.
- **Cause, once: registration is lazy, the pump is eager.** `MarkMemberExpanded` is reached from the `TOC76-XSF` census, i.e. the first time the guest *asks* for a path; the guest may have pumped that member's 32 KB page long before (ui/cars/effects/characters), so its page-cache copy stays DEFLATE and the loader tokenizes binary. `city`'s page happened to be first read after its mark — which is the only reason this project has any preload lines at all. The same laziness is why F-101's witness saw the pages consumed "as-is" with no decoder: those consumers read the pre-registration copy.
- **The fix, general rather than hardcoded.** Every `preload.list` record carries leaf hash `0DB1C876` in `[entry+0]` and `globaltex.list` carries `3D9B8154`, so scanning the decrypted TOC for those two hashes finds all six spans without naming an offset or a size. That scan belongs at the first moment the decrypted TOC is visible in guest memory, and which site that is must be MEASURED, not assumed: candidates are the existing one-shot TOC dump inside the read census (`src/gpu_device.cpp`, the `dumpOnce(0xC60B7780, 382976, ...)` call — which runs on the first pump read and may therefore itself be late) and the mount routine (`sub_822C4630`, the `+0x20C` site named in F-099). Choose by comparing their log timestamps against the first member-page pump in the diagnostic soak.
- **Prediction to test next (T41.3v).** With mount-time registration, `ui`/`cars`/`characters`/`effects` should tokenize real names and `LISTLINE` should jump from 77 toward the sum of the members' line counts (15+78+61+18+17 = 189 for the five preload lists); and — the actual B2 gate — the effects names should make the guest try `shaders/effects/dcl/star_glow.dcl` / `shaders/effects/fxl_final/star_glow.fxc` instead of the prefix-less forms, which F-109 showed it never does today.
- **Default state after this entry.** The four censuses are kept (log-only, filtered to the loader's `lr`); `kExpandListInArchive` returns to `false`, so the committed tree is the frontier again, re-verified by `w96` against `w81`/`w72`. `w95` supersedes `w88` as the seam-ON branch baseline (it carries the buffer field that produced this answer).


### F-111 — **B2's gate is met.** Registering the six `*.list` spans at the guest's first archive I/O (instead of lazily at the first TOC query, which F-110 proved races the page pump) makes the guest read five of the six lists and request `star_glow` in its **group-prefixed** form: `'wasn't preloaded properly'` disappears (`Fatal error 2 → 1`, and the surviving one, `'swfCMD::Fixup - unknown type %d'`, already existed in the old frontier), `LISTLINE` goes 79 → 167 with `ui`/`cars`/`characters`/`effects` now producing names, and `shaders/effects/dcl/star_glow.dcl` is opened 12× per run (`w97`/`w98` reproduce identically). The committed default is now this state, and it costs the `C0000005 0` invariant: **50 access violations in the host-completed stream-wrapper path are the new top blocker**, at the same site as F-108's `0xE17` fault (now guest `0xC61`), i.e. more files reaching the same unfinished emulation.

- Task:        T41.3v (B2), logs `build/w97.log` (first run) and `build/w98.log` (reproducibility) vs `build/w96.log` (the previous default)
- Type:        FIX (default-tree change, labelled at its `file:line`) + gate verdict
- Class:       E (archive/page ordering) → D (the wrapper fault it exposes)
- Priority:    P0
- Evidence:    `w98.log` `MEMBER-EXPAND-MARK-EARLY ×6`, `MEMBER-EXPAND off=… ×6`, `LISTLINE 167`, `grep -c 'not preloaded properly' = 0`, `Fatal error 1` with `fatal message: 'swfCMD::Fixup - unknown type %d'`, `GETDEV 205`/`TOC76 89` per-run lines with `shaders/effects/dcl/star_glow.dcl` opened 12×, `C0000005 50` all `rva=0x58D5384` reading `Param[1]=0x100000c61` with `ppc lr=821BE508 r3=82860C68`. Census: `w98` vs `w96` — `Fatal error 2→1`, `C0000005 0→50`, `VEH 0→123`, `GFx 3→3`, `PRESENT 67→68`, `DRAW_INDEXED 0→0`, log quality clean (top repeated shape 11%). Implementation: `src/gpu_device.cpp` `kExpandListInArchive = true` (file scope, ~line 526), `kListMemberSpans[]`, `MclaMarkKnownListMembers()` called from `sub_8244F4C0` when `n == 1` (before `__imp__`), plus the still-live lazy `TOC76-XSF` registration.

- **Why this is the gate and not a proxy for it.** The plan's B2 gate is 'the GETDEV walk for star_glow no longer falls through to `not preloaded properly`'. That exact message is now emitted zero times while the *same* GETDEV walk runs 3.4× more archive lookups and ends on a different, previously co-existing fatal. Nothing is suppressed: `FATAL-SOFT` moves 3 → 2 in step with the one removed fatal, and `using fallback %s` prints 0 times in both `w96` and `w98`, so no new masking was introduced to get this result.
- **The trade is explicit, and it is a trade.** The committed tree now shows `C0000005 50`, breaking the invariant `w47`–`w96` all held. Chosen deliberately: the faults are logged by name, are one site, and are the next task — whereas hiding the gate-clearing state behind a default-off switch would make every later session re-derive this session's whole result. Reverting is one constant (`kExpandListInArchive = false` → the `w96` frontier).
- **The new top blocker, named.** Every one of the 50 AVs is `rva=0x58D5384` (host code, not a mapped guest fn) dereferencing guest `0x00000C61`, with `ppc lr=821BE508`, `r3=0x82860C68` — the *sibling* stream wrapper F-108 already localised, whose fields are individually sane (`dev`/`handle`/`buf=0x82862DF8`/`cap=0x1000`) but whose `0xC61`-style fault address is computed downstream. F-108's wrapper-field theory is not revived: the value differs per run (`0xE17` in `w80`, `0xC61` now) so it is derived, most plausibly `cursor + remaining` or a size read as a pointer, inside the guest's buffered-refill path. Census it as a data-flow question at `sub_821BE508`'s callee chain, and fix the emulation there — not by clamping the pointer.
- **And the asset is there.** `shaders/effects/dcl/star_glow.dcl` now opens **successfully**: `ret=1 toc=[D8DABDFA 00000059 00305F0C 40000053]` (89 bytes at `0x305F0C`) in `w98` — so the whole chain list-name → group-prefixed record → open works for `star_glow` for the first time; what is left of B2 is that the 89-byte `.dcl` body then has to reach the shader/DCL consumer, which today dies at the `swfCMD::Fixup` fatal and the wrapper AVs. DISCCHK is untouched (6 firings in both trees). B4's first item now has a reason to exist: the boot reaches `swfCMD::Fixup`, i.e. Scaleform content, so the renderer feed work is unblocked once the wrapper fault is fixed.
- **Also fixed on the way (F-101's wording).** `sub_823DA950`, called from `sub_821CBE18+0x78`, is an `eieio` + backward-walking cache-invalidate loop (`addi r9,-1` pairs over `r3`/`r5`), not a copy-out. F-101's conclusion (the pages ARE touched right after fill, with no decoder between) stands — the touch is the device's cache op over the DMA target — but its 'copies out' description was wrong.


### F-112 — **B3 answered:** the DISCCHK "error flag" word is the RPF3 TOC record's 4th dword, bit30 is set on *every* cache-packfile record, and bit31 is the guest's own read-completion marker — so the forced ack is not an ack at all, it is "pretend the bytes are already resident", and it suppresses the guest's read submission for every file it touches.

- Task:        T41.3w (B3), `build/w100.log` (ack OFF), `build/w101.log` (ack OFF + DISCCHK2 census), `build/w102.log` (ack ON + census = new committed default)
- Type:        FACT + FIX (mitigation retained, now labelled and sited)
- Class:       D (kernel/runtime implementation) + E (filesystem/device)
- Priority:    P1 — it is the mechanism B4's texture/shader feed depends on
- Evidence:    `build/w102.log` `DISCCHK2 #1 strm=C60AC1A8 fobj=C60AC180 len=1000 rec=C60F7A40 size=23F offs=D0000 flags=400000EC route=guest-disc-read`; `build/w99.log` `entry=C60F7A40 +4=[0000023F 000D0000 400000EC 4C84317A]` for `path='textures/global/cars/globaltex.list'`; `build/w101.log` `DISCCHK2-RES wait returned r3=4294967293 (guest fatals on ==1)`; `generated/ppc_xenon/ppc_recomp.17.cpp:3114-3175` + `:3229-3260`; `src/gpu_device.cpp:10443` (hook) and `src/task_dispatch_trace.cpp:934-957` (census).

**The word is a TOC dword, not a device status.** `rec=C60F7A40` is the in-guest TOC record for
`textures/global/cars/globaltex.list`, whose 16-byte record our own XSF census dumps as
`[3D9B8154 0000023F 000D0000 400000EC]` — GtaO hash, size 0x23F (= 575 = the *stored* length F-105
measured for that member), archive offset 0xD0000, and the 4th dword `0x400000EC`, which is exactly
the value `sub_821CC1E0` tests. Fourteen further records line up the same way in `w99`
(`2dnoise3.dds` → `C60F7AA0 … 4001258B`, `2dnoise4.dds` → `C60F7AE0 … 40010DEF`, `cf_bump2.dds` →
`C60F7B30 … 4000A6F2`). **Every one of them has bit30 set**, which retires any reading of bit30 as
"this file errored".

**What the executed code does with it** (`generated/ppc_xenon/ppc_recomp.17.cpp:3114` ff — the
recompiled body, which is what actually runs):

| guest VA | executed statement | consequence |
|---|---|---|
| `0x821CC1F0` | `r31 = ctx.r4` | the read-request object arrives in **r4** (see F-113) |
| `0x821CC200/04` | `r11 = [r31]`, `r10 = [r11+12]` | the TOC record, then its 4th dword |
| `0x821CC208/10` | `if (!(r10 & 0x40000000)) → 0x821CC224` | bit30 clear ⇒ `r10 = r25 = 0` ⇒ normal path |
| `0x821CC214/20` | `if (r10 & 0x80000000) → 0x821CC228` with `r10 = 1` | bit30 set **and** bit31 clear ⇒ `1 & 0xFF ≠ 0` ⇒ falls into the `0x821CC234` block |
| `0x821CC230` | `if (r10 & 0xFF) == 0 → 0x821CC35C` | bit30 set **and** bit31 set ⇒ normal path |

so the block runs **iff bit30 set && bit31 clear** — session 75z's model was right, and the census
now prints that decision as `route=`. Inside the block the guest *performs the read it was told to
do*: it computes a chunk (`len=1000` = 4096 in `#1`, clamped by `size-pos`), issues the device
virtual call (`bctrl` at `0x821CC2B8`, slot `[{{[r30+32]}+0}+28]`), stores the caller-stack IO block
(`stw r1+80 → [r31+12]`), then `bl 0x821DEE40(r31+12, 2)` and keys the outcome on its result:
`r29 == 1` → return normally, `r29 == 0 || r29 > 1` → retry the chunk, **`r29 < 0` →
`sub_821BD618` = `'Fatal disc error'`**. `w101` measured `r3 = 0xFFFFFFFD = -3` — the guest fataled
because *its own completion call reported a negative result*, not because an "error was unacknowledged".

**Therefore bit31 means "the record's bytes have been read in", and the missing step is the
completion, not an ack flag.** With the forced write ON the guest never submits those reads at all;
with it OFF, boot dies at 4,528 lines (`w100`/`w101`) versus 17,868 (`w99`) — census: `TOC76 232` vs
`2,079`, `GETDEV 100` vs `694`, `LISTLINE 0` vs `167`. The mitigation is therefore **retained and
load-bearing**, now labelled at its site (`src/gpu_device.cpp:10443`, `kDiscChkForcedAck`), and its
cost is named: every file whose data the guest wanted at this stage is silently declared resident,
so any content that path would have produced arrives (if at all) only through the host serve path.
That is a standing hazard for B4 — the conversion target is to make `sub_821DEE40(io, 2)` return 1
for a served record instead of -3, which retires the forced bit without a skip.

**Cap disclosure (rule 19):** `DISCCHK2` prints at `n <= 40 || (n % 200) == 0`, so `w102`'s 41 lines
are 40 consecutive head samples plus `#200`; the true per-run total is ≥ 200 and < 400 and the
sample is a *head* sample, not a random one. `DISCCHK2-WAIT`/`-RES` are uncapped but can only fire
while the ack is OFF (they live inside the block the ack skips), so in the committed configuration
they print zero — a zero that means "the mitigation is working", not "the path is dead".

### F-113 — Instrument post-mortem: `tools/ppc_disasm.py` prints `bc` as raw `bo=/bi=` with no polarity and prints `mr A,B` in the *opposite* operand order from what the recompiler emits; a "refutation" of the bit31 model assembled from it was wrong, and `PPCContext` has no `r14`–`r31` members at all, so a `PPC_FUNC` hook structurally cannot read a callee-saved register.

- Task:        T41.3w (B3), discovered while compiling `src/gpu_device.cpp`
- Type:        FACT (tool + API constraint)
- Class:       H (instrumentation artifact)
- Priority:    P1 — it nearly put a false "the old model is refuted" finding into the ledger
- Evidence:    `build/ninja_b3b.log:116,119` (`error: no member named 'r31' in 'PPCContext'`, `no member named 'r29'`); `src/ppc_context.h:327-366` (r14…r31 inside `#ifndef PPC_CONFIG_NON_VOLATILE_AS_LOCAL`); `generated/ppc_xenon/ppc_recomp.17.cpp:3139-3141` vs `python tools/ppc_disasm.py 821CC1E0 32` line 5; `docs/ROOT_CAUSE_VALIDATION.md` F-112.

Three traps in one instrument, all of them silent:

1. **`mr` operand order.** The word at `0x821CC1F0` is `7C9F2378`. `ppc_disasm.py` prints
   `mr r4,r31` (i.e. "r4 = r31"); the recompiler emits `r31.u64 = ctx.r4.u64` under the comment
   `// mr r31,r4`. Only one can be what runs — and the recompiler's is the correct reading: the ISA
   macro is `mr A,B` = `or B,A,B`, so `RT=4, RA=31, RB=4` *is* `mr r31,r4` (cross-check the
   canonical `mr r1,r30` = `7FC1F378`, which likewise has `RT=30, RA=1, RB=30`). Behaviour agrees:
   with `r31 = ctx.r4` the census reads a coherent TOC record, while a body that *read* an unassigned
   `r31` would load from guest address 0 and AV on the first call. The tool collapses
   `or RT,RA,RB` with `RB==RT` and prints it as `mr RT,RA` — the reverse direction.
2. **`bc` polarity.** The tool prints `bc bo=12 bi=26 -> target` and leaves the meaning to the
   reader. `bo=12` with `bi=EQ` is **`beq`** — cross-check the canonical `beq +20` = `41820014`
   (`BO=0b01100, BI=2`), and the recompiler writes our branch as `if (cr6.eq) goto …`. Reading it as
   "branch if condition false" inverts every control-flow conclusion in a function; that is what
   produced the (now-withdrawn) claim that `0x821CC234` was the normal path and that
   `[dev+12] & 0x3FFFFFFF` was a size the check ignored.
3. **No callee-saved registers in `PPCContext`.** `r14`–`r31` are compiled away by
   `PPC_CONFIG_NON_VOLATILE_AS_LOCAL`, so *any* hypothesis of the form "the object is in r31" is
   untestable from a hook, and the correct move is to find which **argument register** the
   recompiler assigns that object from — here `r4`, which the old hook already used correctly.

**Rule to keep:** for executed semantics the authority is the generated body
(`generated/ppc_xenon/ppc_recomp.NN.cpp`, `if (cr6.eq)` / `if (!cr6.lt)` lines are unambiguous);
`ppc_disasm.py` is for opcode and immediate fields only. Do not assert a branch's direction or an
`mr`'s source from it. Supersedes nothing — F-112 records the corrected conclusion.

### F-111 correction (dated 09-24 04:55, T41.3w)

F-111's last sentence says the new default "**costs the `C0000005 0` invariant: 50 access
violations**". That 50 is a **line count** from `soak_census`, which counts matching lines: `w99` has
50 `C0000005` lines and 48 `VEH[` lines, but only **2** distinct `Vectored exception:
code=0xC0000005` events — the two host-completed stream-wrapper faults already named in F-108/F-110
(`rva=0x58D5384`, `lr=821BE508`, guest `0xC61`), each re-reported per attempt. The blocker is real
but it is 2 faults, not 50; the per-fault count is a retry multiplier and must not be quoted as an
event count. `w102` reproduces the same 50 lines / 2 events, and `DRAW_INDEXED` is still 0.

### F-114 — B4's first measurement: the `PRESENT` marker was counting our own 33 ms timer, not the guest (2,880 heartbeats vs **0** guest presents on that counter; the guest's 4 real swaps show as `NATIVE-PRESENT`), and no draw can reach the backend at all because the builder is invoked with a null vertex-stream pointer and `streams=0` — `SETSTREAMS-census` has never fired in any soak.

- Task:        T41.4b (B4), `build/w103.log` vs baseline `build/w99.log` (and `build/w102.log` for the pre-change census)
- Type:        FIX (present hygiene) + FACT (where the draw feed actually breaks)
- Class:       F (GPU/shader translation) + H (marker semantics)
- Priority:    P0 — it is the gate for every remaining plan step
- Evidence:    `build/w99.log` has **34** `RenderThread: PRESENT #…` lines and `build/w103.log` has **0**, replaced by 34 `RenderThread: HB-FLICKER #…` lines the last of which reads `HB-FLICKER #2880 frame=0 obj=00000000 fb=00000000 surf=00000000` (≈33 ms × 120 s); `w103` `NATIVE-PRESENT #1 obj=40002080 fb=C71D82C0 surf=00000000 q=1` … `#4 … fb=C71D82CC q=3`; `w102:4409` `SUBMIT-census sub_82420BA8 #2 dev=40002080 flags=0 lr=8217BB10 streams=0 vb0=[00000000,00000000,00000000] r5=00000000 [...] r6=4000DF60 [00100003 00000002 ...] plausible=0 dummy=1`; `w102` marker counts `DRAW-GATE plausible 0`, `DRAW-GATE dummy 2`, `SETSTREAMS-census 0`, `41C308 0`, `DRAW_INDEXED 0`.

**Fixes landed (both are B4's named items, and both are behaviour-visible):**
`render_thread.cpp:392-399` no longer calls `ClearAndPresent()` after a draw —
`D3D12Backend::DrawDynamicMesh*` already closes, executes, **presents** and advances the frame index
(`d3d12_backend.cpp:1487-1503`), so the old call was a second `Present` of the same frame whose first
act is `ClearRenderTargetView`, i.e. it erased whatever had just been drawn. And the PRESENT-case log
line now splits heartbeat presents (`{frameNumber=0, obj=0, swapInfo=0}`, `render_thread.cpp:112-125`)
onto the `HB-FLICKER` marker. `w103` shows the consequence: the render-thread counter printed **34
heartbeat lines in `w99` and zero in `w103`** (`soak_census`'s own `PRESENT` marker fell 68 → 34 only
because it matches those lines as a substring — its remaining 34 are `NATIVE-PRESENT`/`PRESENT-FB`/
`W31-PRESENT-CENSUS`/`PRESENT-BLIT-SYNTH`, *not* render-thread events), while
`C0000005 50`, `VEH 123`, `GFx 3`, `Fatal error 1`, `swfCMD 2`, `NATIVE-PRESENT 4`, `PRESENT-FB 4`,
`LISTLINE 167`, `'not preloaded properly' 0` and `CP truth pub=11 put=11 (caught up)` all hold — i.e.
**the guest issued zero presents on the render-thread counter for the whole 120 s soak**, and every
previous "PRESENT is advancing" reading was our timer. Its real swap traffic is the 4
`NATIVE-PRESENT` entries against swap-table slots `C71D82C0…C71D82CC` (`surf=004E0D30` on #2-#4).

**Where B4 actually stops:** the draw-feed gap is upstream of the renderer, not in it. The two builder
calls in the whole boot (`sub_82420BA8`, from `lr=8217BB10`) arrive with **`r5 = NULL`** (the vertex
stream descriptor), **`dev+12748 streams = 0`** and `vb0 = [0,0,0]`, so `plausible` is false at
`src/gpu_device.cpp:1948` and nothing is queued — `DRAW-GATE plausible 0`. The session-75b hypothesis
chain (`sub_8217A470 → sub_8241BE78 SetStreams → sub_8241C308 → sub_82420BA8`) is **not** the path this
boot takes: `SETSTREAMS-census` and any `41C308` marker print 0 lines in `w99`/`w102`/`w103`, and the
marker literals are present in `src/` (`gpu_device.cpp:1989-1999`), so per F-057(6) that zero is real:
`sub_8241BE78` is never called at this stage. Meanwhile the CP ring does publish draws
(`CP-DRAW op=0x36 … numIdx=1 idxSize=0 dmaBase=00000000`, 26 of them, `writes=54` register writes each,
`r08B/r08C/r0DD/r0D2/r0A2` all zero, `r1DC=00020037 r1DD=071D8380`) — trivial one-index submissions
with no DMA buffer attached, i.e. the shape of a clear/setup pass, not menu geometry.

**Consequence for the plan.** `DRAW_INDEXED >= 1` from a non-zero constant bank cannot be reached by
renderer work alone while (a) the only surviving fatal (`'swfCMD::Fixup - unknown type %d'`,
`FATAL-SOFT`-masked) still stops the guest before its UI build, and (b) no vertex-stream binding has
ever been observed. So the next B4 step is the *feed*: identify what binds streams on this path (the
`writes=54` register batch at `rptr` around `C71DC180`, and/or the caller at `lr=8217BB10`), and lift
the `swfCMD` fatal — the constant-bank capture has nothing to bind to until one of those lands. Zero
`PRESENT`-counter events is now the honest baseline for B5's "non-fallback PRESENT-FB" criterion, which
also still samples the `rgb=(0.06,0.10,0.22)` fallback for all 4 framebuffer reads.

### F-115 — Two B4 blockers named with their evidence: (a) our own `plausible` gate can never open for the draws this boot issues, because the guest calls the builder with a **literal `li r5,0`** for AUTO-source vertex draws (`CP-DRAW src=2`) — the vertex location is in the CP register batch, not the argument; (b) the surviving `'swfCMD::Fixup - unknown type %d'` fatal reads its "type" (`0xB7`) out of a B7-heap node our own rebase/alloc path installed, i.e. a pointer's top byte consumed as a type field.

- Task:        T41.4c (B4), static read of `generated/` + existing lines in `build/w102.log` / `build/w103.log`
- Type:        FACT (two blockers, one of them a design error in our own gate)
- Class:       D (our runtime/gate) + G (the game's coded behavior) + F (GPU feed)
- Priority:    P0
- Evidence:    (a) `generated/ppc_xenon/ppc_recomp.8.cpp:1120-1152` — the site whose return address is the observed `lr=0x8217BB10`: `li r10,0 / li r9,0 / li r8,0 / li r7,0 / li r5,0 / lwzx r6,r11,r27 / bl 0x82420ba8`, i.e. **r5 is a compile-time zero**; `build/w102.log:4409` `SUBMIT-census … r5=00000000 … plausible=0 dummy=1`; `build/w102.log` `CP-DRAW #1 op=0x36 src=2 prim=1 numIdx=1 idxSize=0 dmaBase=00000000`; gate at `src/gpu_device.cpp:1948`. (b) `build/w103.log:14607-14613` `P5-MISSFIX #00017 desc=CA5E0800 a4=82009840 old=B7B6D9B4 lr=8260A8B0 r13=8F200000` → `P5-PHYS #00017 old=B7B6D9B4 … already physical, skip fatal (caller takes delta-0 path)` → `P9-B588 #00003 node=B7B6D9B4 type=B7 [0]=B7982758` → `fatal-dispatch regs: lr=0x8260A8CC r1=0x006D8D10 r3=0x82088854 r4=0x000000B7 r5=0xB7B6D9B4` → `'swfCMD::Fixup - unknown type %d'`.

**(a) The gate contradicts the calling convention it is guarding.** `src=2` in the CP packet is the
AUTO vertex source, and the executed caller really does pass `NULL` for the vertex-stream descriptor —
four of its argument registers are literal zeroes and only r3 (device), r4 (primitive/flags) and r6 (a
`lwzx`-loaded index-buffer word) carry data. Our check requires
`dic.vbAddr >= 0x10000 && dic.vbSize && dic.vbStride && dic.ibAddr && dic.ibSize && dic.indexCount`,
where all three VB fields are read from `[r5+0/4/8]` — so for every AUTO-source draw the gate is
structurally closed and `DRAW-GATE plausible` must stay 0 forever. The VB base/stride for such a draw
lives in the register batch the packet writes (the draw carries `writes=54`, and the census shows
`r08B=r08C=r0DD=r0D2=r0A2=0`, `r1DC=00020037 r1DD=071D8380` — the last two look like a {size<<16|…,
base} pair pointing at guest `0x071D8380`/`0xC71D8380`, the swap-table region family). **Next action:**
dump the whole 54-write batch for the first draw and match ids to Xenia's `PM4_REGISTER_OFFSETS`
(`.research/xenia`), then feed AUTO draws from registers instead of from `[r5]`. This is not a
short-circuit request — it is completing the decode the plan already names ("UR-style dev+offset
decode"). Do not widen the `plausible` test to accept VB-less draws: that would push garbage geometry
into a PSO and produce a fake pass of B4's gate.

**(b) The last fatal consumes a node our own rebase/allocation machinery produced.** The chain in
`w103` is: `W30-ARR-FIX obj=B7B41000 arr=00000000->B7B6D9B4 n=1 cnt 0->1` (05:01:22.760) on a block
that `J2-DIST-ARR`/`W25-ARR-DUMP` show as **all `CDCDCDCD`** at that moment, then two seconds later
`P5-MISSFIX #00017 … old=B7B6D9B4` → `P5-PHYS … already physical, skip fatal (caller takes delta-0
path)` (predicate at `src/task_dispatch_trace.cpp:600-604`, which is deliberate for the `0x50…`→`0xB7…`
rewrites our RSC-NEST walk performs) → `P9-B588 node=B7B6D9B4 type=B7 [0]=B7982758` → the fatal with
`r4=0x000000B7`. The `swfCMD::Fixup` "type" therefore equals the **top byte of a rewritten pointer**,
which is the signature of a consumer reading a pointer field as a type byte (or of a rewrite landing in
a non-pointer field) — the same object family that `FB0D8-DTOR … child=B7B41000 +4=CDCDCDCD` reports in
`w100`. Not yet root-caused: the open question is one field offset, so the next census must print the
node's first 8 words *at* the `swfCMD::Fixup` entry (`sub_8260A8CC`'s callee, `lr=8260A8B0` is the
fixup walker's return site) rather than 2 s earlier. This supersedes the loose treatment in F-111
("the surviving one … already existed in the old frontier") by naming its consumption chain — it does
**not** license tightening the `alreadyPhys` predicate, which is load-bearing for the RSC-NEST design.

**Addendum to F-115(b), same session (measured, not inferred).** The Fixup callee is
`sub_8260B588(group=r3, node=r4)` and its type is `u8[node+4]` (`src/task_dispatch_trace.cpp:434-445`).
Across the 8 firings in `w103` the healthy nodes read `type=00` (`node=B7B41000 [0]=8208521C`,
`node=B7982758 [0]=820880BC`, twice each) while the fatal one reads `type=B7` (`node=B7B6D9B4`) — and
`RSC-CHILD-WORD B7B6D9B4[1] = CDCDCDCD poison` at 05:01:22 shows that same `[node+4]` dword was still
uninitialised two seconds earlier. So `0xB7` is not "the top byte of a rewritten pointer" read *as* the
type: it is the **MSB of a B7-heap pointer that was stored into the node's type dword**, i.e. the
`swfCMD` dispatcher was handed a heap block where it expected a command node — a type confusion one
level up, in whatever fills the fixup list the walker iterates (`lr=8260A8B0` in `sub_8260A830`, whose
P5 census reports the identical value as `old=B7B6D9B4`). Next question is therefore *which list entry
produced that node*, not how to mask the type.

### F-116 — B4(a) measured: the AUTO-source draw's whole 3D state IS in our Xenos register file at the moment of the packet (54 pokes, of them 10 in the `0x2xxx` shader/const region, render-target-shaped value `r01DD=071D8380`), so the missing piece is not data — it is that nothing on the render side reads the register file.

- Task:        T41.4c (B4), `build/w104.log` (census-only build; `w103` = pre-census baseline)
- Type:        FACT + FIX (log-only census added; no behaviour change)
- Class:       F (GPU/shader translation)
- Priority:    P1
- Evidence:    `src/gpu_cp.cpp:64-82` (the 64-entry poke ring) + `:679-695` (the dump); `build/w104.log` `CP-DRAW-REGS #1 [00/54] r0A31=01000000` … `[08/54] r01DD=071D8380`, `[09/54] r01DC=00020037`, `[03/54] r0D02=00010800`, `[04/54] r0A02=C0100000 PTR?`, `[05/54] r0A03=07F00000`, `[06/54] r0A04=C0000000 PTR?`, `[07/54] r0A05=00100000`, `[17/54] r057C=0BADF00D`, `[13/54] r0081=80010000 PTR?`, and the `0x2xxx` group `r2082=00100010`, `r2100=0000FFFF`, `r2180=1000000E`, `r2204=00010000`, `r2205=00010000`, `r2206=00000300`, `r2208=00000004`, `r2280=00080008`, `r2302=00000004`, `r2312=0000FFFF`; frontier unchanged (`LISTLINE 167`, `'not preloaded properly' 0`, `Fatal error 1`, `C0000005 50` lines, `NATIVE-PRESENT 4`, `DRAW_INDEXED 0`, `CP truth pub=11 put=11`).

**What the batch says.** Every one of the three sampled draws is preceded by the same 54 accepted
register pokes (non-zero subset printed; `writes=54` in `CP-DRAW-STATE` is the total), so the guest *is*
programming 3D state through the CP — it just does it through registers, not through the
`sub_82420BA8` descriptor arguments our builder reads (F-115a: `li r5,0`). The values fall into three
recognisable shapes, stated here as raw id/value pairs because the names are not yet cross-checked:

- **A surface pair.** `r01DD=0x071D8380` with `r01DC=0x00020037` — the only `0x071Dxxxx` in the batch,
  and `+0xC0000000 = 0xC71D8380` is exactly the swap-table/surface family that `NATIVE-PRESENT`
  reports (`fb=C71D82C0…C71D82CC`) and that the `WAKE/WAIT` census polls at `wb@C71D82BC`. So this pair
  is where the drawn frame is expected to land.
- **Four `0xA02..0xA05` values forming signed-looking 16.16 pairs** (`C0100000 / 07F00000`,
  `C0000000 / 00100000`) — consistent with a window/scissor/extents quad, and the reason F-115a's
  `plausible` gate cannot be satisfied from `[r5]`.
- **Ten writes in the `0x2000+` region** — the band F-090 widened the file for, and the one B4's
  "real float-constant capture" must read. Each appears before all three draws with identical values,
  i.e. they were programmed once and reused, not per-draw.

`r057C=0BADF00D` is worth noting as its own question: that is a sentinel-shaped value sitting in the
batch, and until it is named we cannot assume every register in the batch is real guest state.

**Cap disclosure (rule 19).** `CP-DRAW-REGS` prints for `n <= 3` only, over a ring of the last 64
pokes, and drops zero values — so `[k/54]` indices are contiguous but printed slots are a subset, and a
register written earlier than the last 64 pokes is invisible here. Zero for a register id not shown
means "not among the last 64 pokes", not "never written".

**Next step (unchanged from F-115a, now with the address space in hand):** name these ids against the
local Xenia tree (`.research/xenia/src/xenia/gpu/` — `xenos.h`/`packet_disassembler` in this checkout;
there is no `reg_base.h` and no `REG_OFFSET` macro, so the offset enum must be located first), then
decode the VB/IB + float-constant state from the register file instead of from `[r5]`, and bind that
into the CBV at `src/d3d12_backend.cpp:1462`. Not a mitigation: this completes the decode the plan
names. `DRAW_INDEXED` must stay 0 until a real constant bank exists, so nothing was widened here.

### F-117 — **The boot's last fatal was manufactured by our own host-synthesized call into the guest's fixup walker.** Retiring that fabricated execution gives the first soak in this project's history with `Fatal error 0` and `FATAL-SOFT 0` (`w107`), and triples CP draw traffic (`CP-DRAW 52 → 166` lines). The frontier is now a *wait*, not a death: the guest parks in a 30 ms kernel-object loop on `obj@40004D7C` (`lr=8242FC1C`).

- Task:        T41.4d (B4 precondition / B5 criterion 3), `build/w107.log` vs baseline `build/w103.log`; commit `5094d56`
- Type:        FIX (removal of host-fabricated execution — not a mitigation, nothing is masked)
- Class:       H (our own instrumentation/host artifact) + D
- Priority:    P0
- Evidence:    chain in `build/w103.log` line-for-line — `6204 W30-ARR-FIX obj=B7B41000 arr=00000000->B7B6D9B4 n=1 cnt 0->1 vt0=82085364` → `6328 W30-PLACE obj=B7B41000 arr=B7B6D9B4 — re-dispatch 825EF100 after ARR-FIX` → `6464 P5-MISSFIX #1 … lr=8260A8B0 r13=8F200000` → `14607 P5-MISSFIX #17 … old=B7B6D9B4` → `14609 P9-B588 #3 node=B7B6D9B4 type=B7 [0]=B7982758` → `14613 fatal message: 'swfCMD::Fixup - unknown type %d'` → `14683 W30-PLACE-DONE arr=B7B6D9B4 [arr]=B7982758 cnt=2`. Code: `src/gpu_device.cpp:4560` (`arrSlot = 0xB7B6D9B4u`, hard-coded), `:4594-4596` (publishes it into `obj+12`), `:4601-4616` (synthetic `PPCContext p{ r1=0x006D8EC0, r13=0x8F200000 }` then `place(p, base)`); the guest's own reading of that field is `generated/ppc_xenon/ppc_recomp.122.cpp:34186-34193` (`lwz r4,0(r29)` → `bl 0x8260b588`), and `sub_8260B588`'s discriminator is `type = u8[node+4]` (`src/task_dispatch_trace.cpp:434-445`).

**Mechanism.** `W30-ARR-FIX` treats `obj+12` as "pointer to a child array" and writes an address it
hard-coded from a 15-day-old `w9` RSC-REBASE observation. The guest's consumer treats `obj+12` as a
**node pointer**, so the fixup dispatcher dereferences `B7B6D9B4` as a command node and reads its type
from `[node+4]` — which is the top byte of the array entry *we* stored there. `0xB7` is therefore a
byte of our own pointer, printed by the game's `%d`. Then `FATAL-SOFT` masked it and paused the thread,
which is why every log up to `w103` recorded this as a game-side fatal. Crucially the walker only runs
at all because `W30-PLACE` **re-enters guest code** (`sub_825EF100`) on a hand-built context: the guest
never reaches that path with `obj+12 != 0`. That is fabricated execution of the same class whose
removal an earlier session recorded for the VEH RIP-advance recovery (PLAN_VMX128 risk R5), so the
execution was deleted rather than its symptom masked (rule 1).

**Measured after the removal** (`w107`, 120 s, log md5 `ee217a7045ac` stable across two fresh reads):
`Fatal error 1 → 0`, `swfCMD 2 → 0`, **`FATAL-SOFT 2 → 0`** — B5's third acceptance criterion, met by
deletion rather than by a switch. Frontier-preserving: `LISTLINE 167`, `'not preloaded properly' 0`,
`-GATE 582` vs `588`, `NATIVE-PRESENT 4`, `PRESENT-FB 4`, `CP truth pub=11 put=11 (caught up)`,
`DRAW_INDEXED 0`. Activity rose: `CP-DRAW 52 → 166` lines, `WAKE +95`/`WAIT +96`, host short-circuit
lines `704 → 690`.

**The new frontier is a wait, not a crash.** `w107`'s last 400 lines are 199 copies of
`WAIT[KWFSO] … obj@40004D7C reason=3 to=30ms lr=8242FC1C put=11 rptrWB=001F wb@C71D82BC=0000001F`
each preceded by a `WAKE`, i.e. the guest is being *timed out* rather than signalled, from the same
`lr` that owns the CP writeback (`wb@C71D82BC` is the swap-table/writeback family `NATIVE-PRESENT`
also reports). No `XamInput*`/menu activity appears (`xaminput 0`, `menu 0`). So the next blocker is
**who is expected to satisfy `0x40004D7C`** — a vsync/interrupt-style event we appear to service only
by expiry. That is the concrete next question for B4's `DRAW_INDEXED ≥ 1` gate, and it is consistent
with the F-116 correction below: the guest has not yet programmed vertex/index buffers.

**Artifact caveat, recorded because it changed what is citable.** The first run of this configuration
(`w105`) was written while the E: volume's flush path was failing; after `taskkill /F` its log became
`OSError 22`-unreadable, later "readable" with a *different* byte count and inconsistent marker counts
(`LISTLINE 1`, `star_glow 0` against `167`/`58` reported by the census that had read it while the
buffer was still live). **`w105` is therefore void and nothing here cites it**; `w107` is a clean
re-run reproducing the same numbers, and `soak_census`/`grep` counts should be treated as unreliable
for any log whose size changes between reads.

## Correction to F-116 (dated 09-24 05:55, from the register table — supersedes F-116's naming, not its measurement)

F-116 read `r01DD=071D8380`/`r01DC=00020037` as "a surface pair … where the drawn frame lands".
Naming the batch's ids against `.research/xenia/src/xenia/gpu/register_table.inc` refutes that (the
`0x0081` seen in the batch has no entry in that table, so it is not named here):

| id | Xenia name | `w104` value |
|---|---|---|
| `0x01DC` / `0x01DD` | `SCRATCH_UMSK` / `SCRATCH_ADDR` | `00020037` / `071D8380` |
| `0x057C` | `CALLBACK_ADDRESS` | `0BADF00D` |
| `0x05C8` | `WAIT_UNTIL` | `00020000` (×3) |
| `0x0A2F`/`30`/`31` | `COHER_SIZE_HOST`/`COHER_BASE_HOST`/`COHER_STATUS_HOST` | `00801000` / `061D8000` / `01000000` |
| `0x0A02`…`0x0A05` | `UNKNOWN_0A02`…`0A05` | `C0100000 07F00000 C0000000 00100000` |
| `0x0C85` | `PA_CL_ENHANCE` | `00000003` |
| `0x0D00`/`0x0D01`/`0x0D02` | `SQ_GPR_MANAGEMENT` / `SQ_FLOW_CONTROL` / `SQ_INST_STORE_MANAGMENT` | `00040401` / `04000000` / `00010800` |
| `0x0E42` / `0x0F01` | `UNKNOWN_0E42` / `RB_BC_CONTROL` | `00001F60` / `0000200E` |
| `0x2082` | `PA_SC_WINDOW_SCISSOR_BR` | `00100010` |
| `0x2100` | `VGT_MAX_VTX_INDX` | `0000FFFF` |
| `0x2180` | `SQ_PROGRAM_CNTL` | `1000000E` |
| `0x2204`/`05`/`06` | `PA_CL_CLIP_CNTL` / `PA_SU_SC_MODE_CNTL` / `PA_CL_VTE_CNTL` | `00010000` / `00010000` / `00000300` |
| `0x2208` | `RB_MODECONTROL` | `00000004` |
| `0x2280`/`0x2302`/`0x2312` | `PA_SU_POINT_SIZE` / `PA_SU_VTX_CNTL` / `PA_SC_AA_MASK` | `00080008` / `00000004` / `0000FFFF` |

So the batch is CP housekeeping (`SCRATCH_*`, `WAIT_UNTIL`, `COHER_*`, `CALLBACK_ADDRESS`) plus a
*shallow* 3D control set (window scissor, clip, point size, VTX/VTE_CNTL, `RB_MODECONTROL`) — and **no
vertex- or index-buffer base register appears anywhere in it**. That absence is measured, not a cap
artifact: the trace ring holds the last 64 pokes and only 54 existed at draw #1, so all of them were
visible. F-116's headline ("the AUTO draw's 3D state IS in the file") is therefore only true of draw
*controls*; the buffer addresses are not there, which means `DRAW_INDEXED ≥ 1` requires the guest to
reach real scene setup — per F-117 now gated behind the `40004D7C` wait — and not merely a decoder on
our side. `r057C = CALLBACK_ADDRESS = 0BADF00D` is unexplained and is its own open item.

### F-118 — With the fatal gone the frontier is a **thread stall, and it is pre-existing**: `w103` and `w107` both end with ~2.6 k identical GPU-worker waits and `swaps=0` for the whole run. Also fixed a sampling instrument that hid this: `PARK-SAMPLE` printed only when the host RIP *changed* and only for the first 60 s, so a permanently parked main thread looked like silence.

- Task:        T41.5a (B4/B5 — what blocks the guest after the fatal lifted), `build/w107.log`, `build/w108.log` vs `build/w103.log`
- Type:        FACT + FIX (instrument only; log-only change, no guest-visible behaviour)
- Class:       H (instrument artifact) + D (thread/kernel behavior)
- Priority:    P0 — this is the blocker now standing between the frontier and a rendered menu
- Evidence:    `build/w107.log` `THREAD-CREATE #12 start=8242FB88 ctx=40004D5C … lr=82460348`, `#13 start=8242FB88 ctx=40004DAC`, 13× `THREAD-CREATE start=821C91C8 ctx=8285FEA8|8285FED4 flags=00000001`; `WAIT[KWFSO] … obj@40004D7C reason=3 to=30ms lr=8242FC1C put=11 rptrWB=001F wb@C71D82BC=0000001F` ×2,716 (`w103` ×2,620 — same loop, same counts order, and **`swaps=` never leaves 0 in either**: `RING: ctx+30=C62D84BC ctx+38=C635841C head=00000000 00000000 rptrWB=00000000 drains=8 swaps=0`, `CP: VDRAIN-CENSUS #2500 … doorbells=8 drains=8 swaps=0`); `WAITHELP` stops at `#88` (05:50:43) although its cap is `n <= 400`, so the instrumented waits genuinely ended; `w108` `PARK-SAMPLE rawrip=7ff7b0489021 … vbl=1` ×57 of 122 samples, last at 06:03:08 (i.e. ~2 min after boot start). Code: sampler defect at `src/boot_host.cpp:1518` (loop bound `i < 120`, 500 ms) and the dedup `if (!ok || tc.Rip == lastRip) continue;` at `:1541`.

**What the guest is doing.** After the F-117 fix the boot reaches a stable configuration: 15 guest
threads exist, of which 13 run `sub_821C91C8` (a worker pool created with `flags=1`) and 2 run
`sub_8242FB88` — which I read as the CP/queue consumer: it waits on the event embedded at
`[[wait_block]+0] + 44` (hence `obj@40004D7C` = `0x40004D50+44`), with a 64-bit relative timeout of
`0xFFFB6C20` = −300,000 × 100 ns = **30 ms**, and re-loops while `[wait_block+56] ==
[wait_block+60]` (empty queue). So the visible tail of the log is *idle workers timing out*, not the
main thread. The main thread is not in `sub_82135DC0` (that census stopped firing at 05:50:43) and not
in `sub_82460270`; `PARK-SAMPLE` now shows it sitting on one host RIP for minutes, with guest frames
resolving to `0x82131008` (the `0x8213xxxx` kernel-wait block) and `0x8244D150`.

**Why this is a plateau and not a regression.** `w103` (fatal present) and `w107` (fatal removed) share
the identical end state — same wait object, same two `start=8242FB88` workers, `swaps=0`, `drains=8`.
So F-117 deleted a fatal *and its `FATAL-SOFT` pause* without losing progress; the thing that has
always stopped a rendered menu is that **no buffer swap is ever requested and the main thread waits
indefinitely** — which is where B4/B5 must now work.

**Instrument lessons (both are rule 19 about our own tooling):**
1. *A change-gated printer cannot evidence absence.* `PARK-SAMPLE` skipped every sample whose host RIP
   equalled the previous one, so the single most diagnostic state — a thread that stops moving — was
   exactly what it never printed. Fixed: the loop now runs 600 × 500 ms and prints every 4th sample
   (2 s heartbeat) regardless of change (`src/boot_host.cpp:1512-1548`); `w108` shows 122 sample lines
   spanning the whole soak where `w107` stopped at 05:50:44.
2. *Host RIPs are not nameable in this build.* `build/mcla.pdb` does not exist (link emits no PDB), so
   `llvm-symbolizer --obj=build/mcla.exe 0x59021` returns `??` and the log prints `nf=host 0x…`. Naming
   the parked host function needs either a PDB-reachable link or a `.map`; until then host-side
   stall claims must be phrased as RVAs, not functions.
3. *Caveat for anyone reading `w108` as a frontier:* the heartbeat suspends/resumes the boot worker
   every 500 ms for the whole run, and `w108` vs `w107` does show timing-sensitive markers moving
   (`PAGESLOT 9 → 0`, `JOIN 34 → 10`, `INFLATE 358 → 301`). Use `w107` (2-second-capped sampler) for
   frontier claims and `w108`-style logs only for thread-state questions.

**Next step (T41.5b), stated as a question with an instrument for it:** name what the main thread waits
on by dumping its *guest* stack chain (the sampler already has `Rsp`, `g_faultCtx->lr`, and the saved
`lr/r30/r31` slots) every heartbeat, and resolve the innermost guest return address to a mapped
`PPC_FUNC` — then ask who is supposed to satisfy that wait, and whether that is the same thing the 13
`sub_821C91C8` pool workers are waiting for.

### F-119 — **T41.5b answered: the boot worker is not idle, it is blocked in the guest's device layer waiting for an IO completion** — 62 of 97 heartbeat samples over the whole tail read `sub_821BD7C0 → sub_82131790+0x284 → sub_822C4630+0x424 → sub_821CD7A0+0x298`, current `lr=0x821E0FF8`. It also corrects F-118: the reason those fields printed zero was a `thread_local` read from the wrong thread, not an absent context.

- Task:        T41.5b (B4 gate / B5 menu), `build/w110.log` vs baseline `build/w107.log`; instrument fix in `src/boot_host.cpp`
- Type:        FACT + FIX (log-only census + a cross-thread read fix; no guest-visible behaviour change)
- Class:       H (instrument artifact, corrected) + D (device/IO behavior)
- Priority:    P0 — this is the blocker in front of every remaining gate
- Evidence:    `build/w110.log` `[06:19:19.715] PARK-STACK sp=8EFFECB0 lr=821E0FF8: f0=00000000 f1=821CDA38 f2=822C47B0 f3=82131A14 f4=821BD810 f5=82132454` (and 62 matching samples, spanning 06:19:19 → 06:20:22, i.e. the whole post-boot tail); `PARK-STACK` printed 97 times where `w109` printed it **0** times; frame→function map computed from `generated/ppc_xenon/ppc_func_mapping.cpp` (`0x821CDA38 = sub_821CD7A0+0x298`, `0x822C4A54 = sub_822C4630+0x424`, `0x82131A14 = sub_82131790+0x284`).

**The instrument correction first, because it invalidates a prior reading.** `g_faultCtx` is
`thread_local` **by design** (F-046: a process-wide pointer printed the boot thread's context for a
fault on another thread). The consequence nobody had checked is the mirror image: a reader on
*another* thread — the `PARK-SAMPLE` heartbeat, and `GetBootWorkerReg()` when called off-thread —
sees its own null copy. So every `r3= / lr= / [r1-8]=` field in `w108`/`w109`'s `PARK-SAMPLE` lines was
`0` because of *that*, and F-118's "the sampler already has `g_faultCtx->lr` and the saved slots" was
wrong as a plan. Fixed with a deliberate process-wide mirror of the boot worker's context
(`g_bootWorkerCtx`, published where `g_faultCtx` is set/cleared at `src/boot_host.cpp:~896`/`:~1263`,
read at the heartbeat) — the VEH path keeps its thread-local copy untouched. Positive control
(rule 19): the same census that printed 0 lines in `w109` prints 97 in `w110`.

**What the boot worker is doing.** It is inside guest code (not a host queue), and its frames say a
device-layer call under a kernel wait: `sub_82131790` (the `0x8213xxxx` kernel block that also holds
the slot-park and the worker-router) → `sub_822C4630` → `sub_821CD7A0`, whose `+0x298` return site is
in the same `0x821CDxxx` neighbourhood as the functions we already know (`sub_821CBFC0` TOC lookup,
`sub_821CBE18` page-slot wait, `sub_821CCEA0` Open, `sub_821CC1E0` the F-112 disc-read). Current `lr`
is `0x821E0FF8`, i.e. execution is parked around the `0x821E0Fxx` region one level deeper. So the
state is: **the main thread issued a device request and is waiting for a completion that never
arrives** — the same missing completion F-112 identified and that `kDiscChkForcedAck` papers over for
the records it touches. This is why `swaps` never leaves 0 (F-118): the guest never gets to the frame
that would present.

Secondary chains, for completeness (`w110`, counts of 97): 12× `f0=FFFFFFFF f2=8218C7DC f3=82188EF4`
(the `sub_8218C1xx`/`sub_82188E50` package-read family — the same region as F-107's preload-list
loader), 7× `f0=827B85D0 f1=821BD7F8 f2=82132454` (thread bodies), 4×
`f0=821C2F30 f1=82131410 f2=823E3CD0` (`sub_821C2E60` + the `sub_823E3CB8` family seen at F-089's
name table). `f0=00000000` on the dominant chain means that frame's saved-lr slot is zero, so the
innermost function name is `lr=0x821E0FF8`'s owner, not `f0` — the next census should print the
function containing the *current* `lr` rather than stopping at the frame chain.

**Next (T41.5c), no short-circuit proposed.** Decode `sub_821CD7A0` (raw bytes, `0x821CD7A0-0x82000000`
in `build/cache/mcla_pe.bin`) and the `0x821E0Fxx` site to identify the request it submits and the
object it waits on; then make *that* completion fire in the host device path. Retiring
`kDiscChkForcedAck` (F-112's conversion target) and reaching `DRAW_INDEXED ≥ 1` both depend on this
same site, which is the strongest reason to fix it rather than route around it.

### F-120 — **Correction to F-119, and the blocker sharpens: the boot worker is not *blocked* in the device layer, it is *spinning* there.** Its host program counter sits on `std` atomic-load helpers (40 + 7 + 5 + 4 of 88 samples) reached from the guest device poll loop — i.e. the guest is busy-waiting on a register/bit that never changes. Enabled by adding `/MAP` to the link, which makes host PCs nameable at last.

- Task:        T41.5c (B4/B5), `build/w111.log` vs `build/w110.log`; `CMakeLists.txt:404-410`
- Type:        FACT + FIX (build-observability; no guest-visible behaviour change)
- Class:       H (instrument) + D (device poll/IO behavior)
- Priority:    P0
- Evidence:    `build/w111.log` `PARK-SAMPLE` host rips resolved through `build/mcla.map` (149,080 symbols) against `PARK-SAMPLE base=7FF64E350000`: rva `059021` ×40 and `058FF0` ×4 inside `?_Check_load_memory_order@std@@YAXW4memory_order@1@@Z`, rva `094DBB` ×7 / `094D88` ×5 inside `?load@?$_Atomic_storage@I$03@std@@QEBAIW4memory_order@2@@Z`, plus `?PageWatchHit@@YA_NI@Z` ×5 and the `BootWorker` VEH lambda ×5; 29 distinct rips over 88 samples. Guest side unchanged from F-119: dominant chain `sub_821BD7C0 → sub_82131790+0x284 → sub_822C4630+0x424 → sub_821CD7A0+0x298`, `lr=821E0FF8` in 52 of 97 `PARK-STACK` lines.

**Why F-119's wording needs correcting.** F-119 concluded "blocked in the guest's device layer waiting for an IO completion". A blocked thread's PC would sit in one kernel wait stub; instead the samples land on **`std::atomic<unsigned int>::load` and its memory-order check helper**, at several distinct sites, across the whole tail — that is a loop reading a value repeatedly. So the device-layer call is *polling*: the guest issued its request and is now spinning on state our host never advances. `swaps=0` with `CP truth pub=11 put=11 (caught up)` (F-118) is the matching host-side fact: nothing more is being published, so whatever bit the guest polls cannot change.

**The observability fix, which is the reusable part.** `target_link_options(mcla PRIVATE /OPT:NOREF /MAP)` in `CMakeLists.txt` emits `build/mcla.map` (19.7 MB, 149,080 public symbols) from a **link-only** change — no compile-flag churn, so no exposure to the known clang-19/STL toolchain fragility. Resolving a log line is now: `rva = rip - <PARK-SAMPLE base>` then the greatest symbol rva ≤ it. This retires F-118's "host RVAs are not nameable" constraint; `NearestFunctionName` in the log still prints `host 0x…` because it does not read the map, so offline resolution is the path for now.

**Next (T41.5c), one census then one fix.** Record *which* register indices the poll loop reads: count `CpRegPeek(index)` calls per index (and the value returned) in a small ring/map, dumped at the `PARK-SAMPLE` heartbeat. That names the exact bit the guest waits on — most likely a CP/ring or vblank-ish status given `pub=put` and `swaps=0` — and the fix is then to advance it in the host device path, which is simultaneously F-112's conversion target for retiring `kDiscChkForcedAck` and the precondition for B4's `DRAW_INDEXED ≥ 1`. No short-circuit is proposed or added here.

### F-121 — **The named top blocker: the boot worker takes ~50 access violations inside a guest `memcpy` at `lr=0x821BE508` (host PC = `MoveSmall1`), the VEH declines them by design, and the thread ends up parked — which is why nothing renders.** It also corrects two of my own earlier statements: the "2 events, not 50" note in F-111's addendum was wrong, and F-120's "spinning on device-register loads" was the handler path, not a device poll.

- Task:        T41.5c (B4/B5), `build/w111.log` (the first soak whose host PCs are symbolizable) + `build/w107.log`; map `build/mcla.map` from the same link
- Type:        FACT (+ two dated corrections)
- Class:       D (kernel/runtime path) + E (device/filesystem serve path) + H (marker semantics)
- Priority:    P0 — this is the blocker in front of `swaps`, `DRAW_INDEXED` and the menu
- Evidence:    `build/w111.log`: `Vectored exception: code=0xC0000005 addr=0x7ff653c27974 rva=0x58D7974 … thread=3276`, and the 50 `VEH-NEUTRAL` lines all carry **`lr=821BE508`** with `read of host addr 0x100000c61`** — the guest VA is `0xC61`, i.e. a **NULL base plus a 0xC61 field offset**, not an unmapped heap block; the separate `VEH[N]` printer contributes 48 lines and does not print `lr`; resolving that build's rva through the matching map gives **`MoveSmall1+0x0`** (the MSVC copy helper), i.e. the fault is inside a memory copy. Thread identity: `B1-ARM tid=3276` at line 128 is immediately followed by `BootWorker: calling entry point 0x821322B8` (line 131) — tid 3276 **is** the boot worker. Decline path: `src/boot_host.cpp:1096` (capped `VEH[N]` printer) and `:1225` (`VEH-NEUTRAL guest AV … recovery disabled, declining`, the F-106-era removal of the RIP-advance recovery), with the generic park after it. Guest site: `sub_821BE250` (the buffered file Read documented at F-107: object `+08` buffer, `+18` cur, `+1C` end, `+20` cap; `buf=82862DF8 cap=1000` per F-108's dump), faulting operand read from guest `0xC61xxxxx`.

**Corrections, stated plainly.**
1. *Against my F-111 addendum (09-24 04:55):* I wrote that the 50 `C0000005` lines were "2 faults, not 50" because only two `Vectored exception:` lines existed. That inference was wrong — the `VEH[N]` counter in the same log reaches **50** and every line names the same `lr`, so there really are ~50 fault events on the boot worker (the `Vectored exception:` summary printer is the thing that is deduplicated). The event count is the 50; the *sites* are one.
2. *Against F-120:* the sampled host PCs in `std::_Check_load_memory_order` / `_Atomic_storage<unsigned>::load` + `PageWatchHit` + the `BootWorker` VEH lambda are the **exception-handler path**, not the guest polling a device register. F-120's "busy-polling a device value" reading is superseded by this: the thread is looping on faults, and the atomics are what the handler touches.

**Why this is very likely our own doing, and the test that proves or kills it.** The faulting access is a read through a **null object pointer** (offset `0xC61`) inside the guest's buffered file read, on a path whose descriptor our own F-108 dump showed as coherent except for downstream-computed pointers — and F-111 recorded that this site appears **with the `.list` seam ON** (`w96`, seam OFF, had `C0000005 0`). The mechanism that tells the guest "this record's bytes are already resident" is exactly F-112's `kDiscChkForcedAck` — it skips the guest's own read submission for every cache-packfile record — and F-111 already recorded that this AV site appeared **with the `.list` seam ON** (`w96`, seam OFF, had `C0000005 0`). So the hypothesis is: the guest believes data is resident, `sub_821BE250` copies from the address it never filled, and the copy faults. **Test (T41.5d), diagnostic only:** one soak with `kExpandListInArchive = false` (and, if needed, a second with `kDiscChkForcedAck = false`) and compare `VEH[N]`/`C0000005` counts plus `LISTLINE`/`TOC76`. A single run is not to be read as a fix — reverting either switch restores the known frontier, and neither is a short-circuit being stacked.

**Reusable method win:** `/MAP` (F-120) turns any logged host `rva` into a symbol, so a fault can be attributed to the exact CRT/recompiled-guest routine instead of guessed. Two rules came out of using it: resolve **only with the map from the same link** (the first attempt against an older log produced a confidently wrong `_log_special_common`), and prefer the faulting thread's `lr` + the guest site over host PCs when the two disagree.

### F-122 — **The 50 access violations were ours, not the guest's: `MemoryStreamServeRead` reads a guest-native buffered wrapper with the MakeMemoryStream field layout, its source address wraps into the deliberate null guard page, and `IsValid` waves the copy through anyway. Naming both takes `C0000005` to 0 for the first time — with the whole frontier intact.**

- Task:        T41.6 (B4 feed), `build/w115.log` vs named baseline `build/w107.log`; `build/w113.log` re-confirms F-121's seam-ON frontier; `build/w114.log` is VOID (see control)
- Type:        FIX (two code changes) + dated correction to F-121 + a void-soak control
- Class:       D (host kernel memory helper) + E (device serve path) + H (fault attribution)
- Priority:    P0 — this was the blocker F-121 named in front of `swaps`/`DRAW_INDEXED`
- Code:        `src/kernel/memory.cpp:321` (`IsValid` now rejects the guard page), `src/gpu_device.cpp:11677/11700/11705` (`MemoryStreamServeRead` refuses a guard-page source and names the wrapper as `BE250-MEM-BADPTR`)
- Evidence:    the host stack of the fault, resolved through `build/mcla.map` from the same link (F-120's method): `MoveSmall1 ← MemoryStreamServeRead+0x23B ← sub_821BE250 (our PPC_FUNC)+0x278 ← __imp__sub_821BE4F0+0xD6 ← __imp__sub_8218C1C0+0x216 ← __imp__sub_8218C760+0x725 ← __imp__sub_82188E50+0xFC9`. The faulting `memcpy` is **inside our helper**, reached from our hook — the recompiled guest body never appears below it. Guest-native layout, `generated/ppc_xenon/ppc_recomp.14.cpp:24080` ff: `lwz r11,8(r31)` (buffer) … `lwz r10,24(r31)` (cursor) … `add r4,r11,r10` → `bl 0x823da950` (the copy), so the source the guest itself uses is `[obj+8]+[obj+24]`; `w115`: `BE250-MEM-BADPTR #1 obj=82860C68 +4=FFFFFFFF +8=82862DF8 +24=00000C62 src=00000C61 dst=8EFFF100 count=1 lr=821BE508`, and `#6` with `+24=00000001 → src=00000000`. `0xFFFFFFFF + 0xC62` truncated to 32 bits is `0xC61` — the arithmetic is a wrap, not a wild heap pointer.

**The mechanism, in order.**
1. Our `sub_821BE250` hook routes any wrapper whose `[obj+0]` is `0`/`0xCDCDCDCD` into `MemoryStreamServeRead`, which assumes the `MakeMemoryStream` shape we create ourselves: `[+4]=buf`, `[+8]=size`, `[+24]=cursor`.
2. `0x82860C68` is *not* one of ours — it is the sibling of the wrapper `XSF-POSTOPEN-SERVE` binds (`0x82860C18`) and it uses the guest's buffered shape, where `[+4]` is a handle (`0xFFFFFFFF` = invalid), `[+8]` is the buffer (`0x82862DF8`, the 4 KB buffer F-108 dumped) and `[+24]/[+28]/[+32]` are cursor/end/cap.
3. So `buf = 0xFFFFFFFF`, `pos = 0xC62`, and `buf + pos` lands on the **first guest page** — which `GuestMemoryHeap::Initialize` deliberately makes `PAGE_NOACCESS` (`src/kernel/memory.cpp:218`; `boot_host.cpp:309` mirrors it for its own view).
4. `IsValid` (`:311`) only tested `guestAddr < m_size` against the flat 4 GB window, so it returned *true* for a guard-page address, `ReadBytes`'s `memcpy` faulted, the handler's own `__try/__except` swallowed it and returned false, and the helper handed the guest `-1`. The AVs were therefore already harmless **functionally**; what they cost was ~1,000 log lines per soak and 1,529 WAKE/WAIT pairs of churn while 50 exceptions walked the chain.
5. Both halves are now fixed: `IsValid` no longer calls the guard page "valid", and the serve helper refuses the shape mismatch *with the object's name in the log*, so the same soak that removes the faults also says which wrapper was misread.

**Census (`w115` vs `w107`, `soak_census`).** Faults: `C0000005 50 → 0`, `VEH-NEUTRAL 50 → 0`, `VEH 123 → 25`, `[error] lines 119 → 15`, and the fault-line `lr` section now prints **"none (no line matched the fault filter)"** — the first soak with zero access violations. Positive control for the instrument: `BE250-MEM-BADPTR 55` (≈ the 50 faults it replaced). Frontier held on every invariant: `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `GFx 3`, `CP-DRAW 166`, `DISCCHK2 41`, `GETDEV 694`, `TOC76 2,079`/`TOC76-RET 89`, `CP truth drains=8 last_rptr=001F pub=11 put=11 (caught up)`. Movement in the right direction: `INFLATE 358 → 419`, `PAGESLOT 9 → 27`, `JOIN 34 → 83`, `READWRAP 276 → 376`, `WAIT 3,164 → 1,635`, `WAKE 2,836 → 1,307`. Unchanged at zero: `DRAW_INDEXED`, `swfCMD`, `SETSTREAMS`, `DRAWDISP` — so **B4's gate is still unmet**, but the thing standing in front of it is no longer an exception storm.

**Control that kept this honest (rule 19 applied to myself).** The first soak after the change, `w114`, read as a catastrophe: 920 lines, `TOC76 0`, `INFLATE 0`, `DISCCHK2 0`, `GETDEV 12`, `CP-DRAW 0`, and `BE250-MEM-BADPTR 0`. Its own timeline showed the *pre-guest* phases stretched (image load 35 s vs 19 s in `w113`) and only 4 disc-read submissions in 100 s, i.e. throughput collapse before any guest code could reach my new branch. Re-soaking the **same exe** as `w115` reproduced the frontier exactly, so `w114` is VOID — host I/O contention, not the change. Rule worth keeping: if a soak's log lines *before* the guest starts are stretched relative to the baseline, repeat it before believing anything about the guest.

**Correction to F-121 (dated 09-24 06:5x).** F-121 said the 50 faults were "access violations inside a guest `memcpy` at `lr=0x821BE508`" and hypothesised the guest copying from data `kDiscChkForcedAck` had pretended was resident. Two parts of that were wrong and the third is now moot: (a) `lr=0x821BE508` is not a copy site — `generated/ppc_xenon/ppc_recomp.14.cpp:24496` sets that LR for `li r5,1; addi r4,r1,80; bl 0x821be250`, i.e. a **one-byte** read whose destination is a stack slot (which is why `count=1` and `dst=8EFFF100`); (b) the copy that faulted was `MemoryStreamServeRead`'s, i.e. host code called from our hook, reached *before* the guest body could set its own LR; (c) with the shape mismatch named, F-121's `kDiscChkForcedAck` hypothesis is not needed for this site. F-121's T41.5d test did run and its result stands as recorded in the `kExpandListInArchive` comment: seam OFF (`w112`) removes the faults only because the guest never reaches the read — `LISTLINE 167 → 2` and the `'…wasn't preloaded properly'` fatal returns — so seam ON remains the committed frontier.

**Next (T41.6b), narrowed to one address.** `0x82860C68` sits 0x50 past the wrapper our post-open serve does bind, and arrives with `[+0]=0` and `[+4]=FFFFFFFF`. Either bind that sibling at the same site with the guest-native fields (buffer `[+8]`, cursor `[+24]`, end `[+28]`, cap `[+32]=0x1000`) so the guest's own `sub_821BE250` serves it, or hand it to the guest body with a live device pointer. That is F-121's "ask who was supposed to write it", now pointed at one object instead of a fault.

### F-123 — **The `.fxc` shader bodies are missing because the guest's own Open answers `1` (pending) and our host-serve only fires on `0`; making it fire does clear the read storm — and then breaks the boot a different way, which pins the next question. Also: F-122's "w114 was I/O contention" verdict was wrong, and the real hazard is a bimodal soak.**

- Task:        T41.7 / T41.7b (B4 feed, B3 conversion direction), `build/w117.log` (the measurement) + `build/w116.log`/`w118.log`/`w119.log` (stalled) vs baseline `build/w115.log`
- Type:        FACT + a refuted implementation attempt (reverted) + a dated correction to F-122
- Class:       E (device/archive serve path) + H (soak reliability / attribution)
- Priority:    P1 — this is the fork that decides whether the UI shaders can ever load, and the hazard that decides whether any single soak is citable

**(1) The measured fork at the guest's Open.** Counting every printed `XSF-OPEN … ret=` in `w115`:
`ret = -1` × 332, `ret = 0` × 33, `ret = 1` × 876 (498 of them `*.fxc`). The host-serve block
(`src/gpu_device.cpp:11199`) fires only on `ret == 0`, so exactly the 33 successful opens get a body —
`XSF-POSTOPEN-SERVE` prints 33 times, all `.xsf`/`.list` paths — and every shader answer gets nothing.
The consequence chain is fully logged, one file at a time (`shaders/ui/fxl_final/AlphaModulate.fxc`):
`BE8D8-PACK-MISS #3 … tocEntry=C60F7F90 toc+4=00000C62 (no served body)` → `CD3C8 ret=3170` (the size
is known) → `DISCCHK2 #23 … route=guest-disc-read` → the guest allocates its own buffer
(`MEMFMT-sub_821CB740 r5=CA5DF680`) and re-opens it as `BE0C8 pth='memory:$CA5DF680,3170,1:unavailable'`
— the literal word **`unavailable`** comes from the guest, not from us — → `SLOT-REG idx=3` /
`BE0C8-RET stream=3` → then ~600 one-byte reads (`BE250-MEM-BADPTR`, F-122's instrument) on a wrapper
whose `[+4]` handle is `0xFFFFFFFF`. So the read storm F-122 stopped is the *symptom*; the cause is that
the pending opens never receive a body.

**(2) T41.7 — serve the pending opens too. Both predictions hit, and the boot broke anyway.** With
`serveThisOpen = (ret == 0 || ret == 1)` (`w117`, 11,137 lines): `BE8D8-PACK-MISS 21 → 0`,
`BE250-MEM-BADPTR 600 → 0`, `XSF-BIND-REGONLY`/`XSF-OPEN-PEND` confirm one inflate per TOC entry.
But `LISTLINE 167 → 1`, `Fatal error 0 → 1`, `FATAL-SOFT 0 → 1`, and the decisive line: the guest's own
Open answer for `AlphaModulate.fxc` **changed from 1 to 2** (`XSF-OPEN #68 … ret=2` immediately followed
by `Fatal error dispatcher invoked`, `fatal-dispatch regs: lr=0x8218C864`). So the serve is not inert —
the writes it performs are read back by the guest and alter its state machine.
Reverted; `src/` is back at `7c125b4`.

**(3) What that pins.** Two guest-visible writes live in that block: `WriteU32BE(tocEntry + 4, xsz)`
(publishing the served size over the TOC record's size dword) and the `kBdf20Wrap = 0x82860C18`
`{dev, handle}` bind (which points the *global* BDF20 stream wrapper at whichever file was served
last — the same loose-match hazard §7 already registers for the `(dev,handle)` fallback, and the
likely reason the preload lists went from 167 lines to 1). Registering the body alone should be
harmless, because the guest already reads the size from `[tocEntry+4]` itself — `TOC76-LAYOUT #105`
shows `+4=[00000C62 …]` in the guest's copy with no help from us. **T41.7b** (registration only,
`return` before both writes when `ret != 0`) is written but **unmeasured**: the three soaks run after it
(`w116`, `w118`, `w119`) all hit (4) below, so it neither passed nor failed — do not treat it as
validated. Re-run it when the harness is trustworthy; if it holds `LISTLINE 167` and `Fatal 0` while
`BE8D8-PACK-MISS` stays 0, it converts F-112's forced-ack direction into delivered bytes for shaders.

**(4) Correction to F-122's control claim (dated 09-24 07:35).** F-122 recorded that `w114` (920 lines,
`TOC76 0`, `GETDEV 12`) was host I/O contention, proven because the *same exe* produced `w115`. That
explanation is now refuted by repetition: `w116` (920), `w118` (903) and `w119` (912) all stall at the
identical site, on binaries that also produced full boots (`w115`, `w117`). The site is the fourth disc
read — `RD-SUBMIT sub_8244F4C0 #4 a0=C60B7680 a1=C60B7780 a2=0005D800` /
`NFS-CENSUS[Read] #0006 h=C60B7680 len=382976 off=0x800 evt=00000000 apc=00000000` (no event, no APC) —
after which only `RenderThread: queue depth …` lines appear for the remaining ~70 s. The volume is fine
(128 MB/s sequential read, 32 MB write+fsync in 1.16 s, `git hash-object -w` clean), and
`queue depth` warnings occur in the good soaks too, so neither disk nor a full render queue explains
the bimodality. **What is true:** this boot has a reproducible early stall at the 382,976-byte TOC read
that hits roughly half the runs, and the read is submitted with `evt=0`, so completion depends on a poll
we do not currently observe. **Consequence for method (this is the load-bearing part of the finding):**
a single soak is not citable in this state — every claim needs either a repeat or the
`LISTLINE`/`CP-DRAW`-nonzero signature that distinguishes a real frontier from a stalled run. F-122's
`w114`-vs-`w115` control established its conclusion by accident, not by diagnosis. **The crisp
discriminator that came out of it:** `RD-SUBMIT` separates the modes exactly — `w116`=4, `w118`=4,
`w119`=4 (all stalled, `LISTLINE` 0) versus `w115`=24, `w117`=24 (reached the frontier). `RD-SUBMIT == 4`
means the soak is void before any conclusion can be drawn from it; `>= 24` means the guest got past the
archive TOC read.

**(5) Untouched by all of this:** `DRAW_INDEXED` is still 0 in every run, good or stalled, so B4's gate
remains unmet. The stalled soaks also never reach `LISTLINE`, so they cannot be used to judge anything.

### F-124 — **The stalled soaks are not deadlocks: the boot worker sits inside one guest unpacker (`sub_821E0FF0`, which assembles `0x81C1xxxx` pointers from rotated bytes) and in the stalled mode it never finishes; every other guest thread goes silent (`WAKE=0`). This is what makes half of today's measurements impossible.**

- Task:        T41.7b's measurement attempt (blocked), `build/w119.log` (stalled) vs `build/w115.log` (frontier); `w114`/`w116`/`w118`/`w120`/`w121` are the same mode
- Type:        FACT (mechanism named, root cause not yet established) + method consequence
- Class:       D (kernel/thread path) + H (soak reliability)
- Priority:    P0 for *measurement* — until it is understood, any single soak can be silently void
- Evidence:    `w119` (912 lines, ends 07:34:15) vs `w115` (16,491 lines): **`WAIT[KWFSO]` 8 vs 1,309 and `WAKE[KWFSO]` 0 vs 1,307**, and `w119`'s last WAIT is at 07:32:55.9 while its log runs 80 s longer — so after the stall **no guest thread ever enters or leaves a logged wait**. The host side is alive throughout (`VSYNC-ISR`/`TICK-PROBE #60`/`RING … drains=2 swaps=0` keep printing, and the sampler keeps taking `PARK-SAMPLE`s). Where the boot worker actually is in that window: `lr=821E0FF8` in **93 of its park samples** (plus 11 × `8244D158`, 10 × `821BD668`), with the frame chain `f1=821CDA38 f2=822C4A54 f3=82131A14 f4=821BD810 f5=_xstart+0x19C`. `821E0FF8` is not a wait site — it is the elided-prologue LR write of `sub_821E0FF0` (`generated/ppc_xenon/…`: `ctx.lr = 0x821E0FF8` for the omitted `bl 0x823d91c0`), i.e. the thread is *inside that function body*, which reads bytes at `[r3+4]`, `[r3+5]`, `[r3+8]`, `rotlwi`s them by 8 and merges them against `lis r11,-32255` = **`0x81C10000`** — an unpacker that reassembles guest pointers out of stored bytes. The same function dominates the *good* `w113` too (64 samples), so it is normal work; the stalled mode simply never gets out of it.

**What is ruled out, with the measurement that rules it out.**
1. *Not an access-violation regression:* `C0000005 0`, `VEH-NEUTRAL 0`, `BE250-MEM-BADPTR 0` in the stalled runs — the F-122 fix holds there too.
2. *Not the E: volume:* 128 MB/s sequential read, 32 MB write + `fsync` in 1.16 s, `mkdir`/`rmdir` 0.000 s, `git hash-object -w` clean — all measured during the stalled window (this corrects F-122's "contention" guess, already superseded by F-123).
3. *Not a full render queue:* `RenderThread: queue depth` warnings appear 5-8 times in the good runs as well as the stalled ones.
4. *Not my T41.7b change:* `XSF-BIND-REGONLY` prints **0** times in `w120`/`w121`, because the stall happens at the archive-TOC read, before any `*.fxc` open reaches the serve block. The change is therefore still unmeasured, and `src/` is back at the committed frontier.

**The open question, in one line:** `sub_821E0FF0` is bounded by something it reads out of guest memory (a count or a linked-structure length, assembled from the bytes it merges with `rotlwi`); in the good mode that bound is reached in seconds, in the stalled mode it is not reached in 80 s. So the next instrument is *not* another thread dump — it is a bounded census of that loop (iteration count + the two or three guest words that feed the bound, printed every N iterations with a hard cap), plus the identity of the writer of those words. The existing B1 guard-page/DR0-DR3 machinery is the right tool for the writer question.

**Consequences to apply now (already written into PROGRAM_GUIDE §9):** treat `RD-SUBMIT == 4` as the void-soak signature; a claim needs either `RD-SUBMIT >= 24` or a repeat. This also means the frontier number `w115` stands, but every *single-run* conclusion made during 06:4x-07:4x today (mine included) should be re-checked against a mode-valid soak before being built on.

### F-125 — **A log-only `PPC_FUNC` on `sub_821E0FF0` is not observationally neutral: it brings the F-117-cleared `swfCMD::Fixup` fatal straight back (0 → 52 lines / 104 soft-parks, identical in two runs). The block is also entered ≥401k times and always returns, and its real arguments are now named — so the next instrument for F-124 must not be a hook.**

- Task:        T41.8 (F-124 follow-on), `build/w122.log` + `build/w123.log` (both good-mode: `RD-SUBMIT 24`, `LISTLINE 167`) vs baseline `build/w115.log`; hook reverted, `src/` = `666aed1`
- Type:        FACT + instrument rejection (reverted) + correction of one F-124 inference
- Class:       H (instrument semantics) + D (recompiler/dispatch behavior)
- Evidence:    the hook printed `E0FF0 #…` 2,047 times and `E0FF0-RET #…` 2,047 times in *both* runs, the last numbered line being **`#401400` in `w122` and in `w123`** (cap `n <= 40 || (n % 200) == 0`), so this block is entered ≥401k times per boot — one of the hottest guest routines on the boot path — and entry count == return count says it never fails to come back. Front markers under the hook (`w123` vs `w115`): `LISTLINE 167`, `CP-DRAW 166`, `C0000005 0`, `VEH-NEUTRAL 0`, `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `GETDEV 694`, `TOC76 2,079`, `DISCCHK2 41`, `DRAW_INDEXED 0`, `CP truth drains=8 pub=11 put=11` — all unchanged — but **`Fatal error 0 → 52` and `FATAL-SOFT 0 → 104`**, message `'swfCMD::Fixup - unknown type %d' lr=8260A8CC`, the exact fatal F-117 deleted (`INFLATE 419 → 325` too). Reproduced identically in `w122`, so it is deterministic fallout, not soak noise.

**Why a "census" hook changed the guest here (inference, labelled as such).** `0x821E0FF0` is a recompiler *block* entry, and the generated body's first act is the elided-prologue artifact `ctx.lr = 0x821E0FF8` for an omitted `bl 0x823d91c0` — i.e. code reaches it by branch/tail-call rather than as a standalone callee. Overriding the weak `sub_821E0FF0` symbol inserts a host frame at exactly that seam, and under `PPC_CONFIG_NON_VOLATILE_AS_LOCAL` the block's `r14`–`r31` are its own fresh zero-initialised host locals (`PPCRegister r26{}` … in `__imp__sub_821E0FF0`), so any value a preceding block was carrying in them is gone. What is *measured* is only the correlation — hook present ⇒ the `swfCMD` fixup fatal returns; hook absent ⇒ it stays at 0. The mechanism is a hypothesis, and it is testable independently of F-124 (e.g. hook a sibling block that is entered only by real `bl`).

**What the unpacker is actually handed (fact, from the 40 uncapped prints).** `r3 == r4`, and both point into the `0xC60AC000` device-array region — `C60ACE00`, `C60ACE10`, `C60ACE20` (0x10 stride; also `C6114DE0/E70/EA0`), i.e. the same array that holds `dev=C60AC180`/`strm=C60AC1EC` from F-112's DISCCHK dump. `r5 = 0x8EFFEE80` is the boot worker's own guest stack, with `[r5+480] = 14`. **This refutes the guess in F-124 that `[r5+240..252]` are the loop bounds**: those read as `3111024327/2547330740/3772047468/3270684590`, which are stack locals, not counts. So the bound that behaves differently in the stalled mode is still unnamed.

**Method consequence (the usable part):** for this site the observation must not be a `PPC_FUNC` hook. Two hooks-free options already exist in the tree: the B1 guard-page / `DR0`–`DR3` watchpoint machinery (`src/boot_host.cpp`, thread-agnostic, fires on access not on call), and `midasm_hook` inside the recompiled stream (no dispatch seam). Either can answer "how many iterations, and who wrote the bound" without changing what the guest does. And since `w122`/`w123` both reached the frontier while `w116`/`w118`/`w119`/`w120`/`w121` stalled, the F-123 mode check (`RD-SUBMIT == 4` ⇒ void) remains mandatory — roughly 2 of every 5 runs are void right now.

### F-126 — **Serving the 876 pending archive opens is refuted in three variants (the `.list` walk dies every time), and the reason is NOT the registry key — but the key was genuinely wrong anyway: the served-body map was indexed by the TOC record's FLAGS dword, which 52 different records share. That index is now gone, with the frontier intact.**

- Task:        T41.7c (B4 feed / B3 conversion direction), `build/w127.log` vs baseline `build/w115.log`; refuted variants `build/w117.log` (T41.7), `build/w124.log` (T41.7b), `build/w125.log` (T41.7b + w3 key retired)
- Type:        FIX (one, measured) + three refuted attempts (reverted) + a registered-hazard correction
- Class:       E (archive serve path) + H (identity keys / attribution)
- Code:        `src/gpu_device.cpp` — `MclaRegisterServedBody` no longer indexes `w[3]`, and neither lookup path consults it; the maps and both `find` sites are deleted, F-091's `T413O-SKIP` log-only pattern retained
- Priority:    P2 on its own, but it clears the false explanation of the T41.7 fallout, which is what the next attempt needs

**(1) The w3 key was not an identity (fact).** `MclaRegisterServedBody` did `if (w[3]) g_servedByW3[w[3]] = b;` and `MclaFindServedBody` served from it (twice — once on the `w3` argument, once treating `flagWord` as w3). Counting the TOC records printed in `w115`: **363 distinct record addresses produce 389 distinct w3 values, and single values repeat across records — `40000061` on 52 records, `40000057` on 26, `4000004E` on 22, `40000066`/`4000006A` on 16 each.** For `shaders/ui/fxl_final/AlphaModulate.fxc` the record is `[A3883550 00000C62 001DD1E8 C00004FA]` = {hash, size, offset, flags}, so w3 is the flags word: any two records of the same family collide, last registration wins, and one file's bytes are handed to another. That is exactly the contamination F-091 documented for the `(dev,handle)` key, one level deeper — so §7's "loose match returns one file's body for another" now has the second instance removed rather than just demoted.

**(2) The three refuted variants (all measured, all reverted).** Every one delivers the bodies and destroys the list walk:

| variant | what changed | `BE8D8-PACK-MISS` | `BE250-MEM-BADPTR` | `unavailable` | **`LISTLINE`** | `Fatal error` | `GETDEV` |
|---|---|---|---|---|---|---|---|
| `w115` baseline | — | 21 | 55 | 166 | **167** | 0 | 694 |
| T41.7 `w117` | serve `ret==1` fully | 0 | 0 | — | **1** | 1 | 694 |
| T41.7b `w124` | serve `ret==1`, skip both guest-visible writes | 0 | 0 | 0 | **1** | 1 | 196 |
| T41.7b+no-w3 `w125` | as above with the w3 index deleted | 0 | 0 | 0 | **1** | 1 | 196 |
| **T41.7c `w127`** | **only** the w3 index deleted | 21 | 55 | 166 | **167** | **0** | **694** |

So the cross-serve explanation for T41.7's collapse is **wrong** (row 4 behaves like row 3 with the bad key removed), and so is the "two guest-visible writes" explanation (row 2 vs row 3). What all three failing rows share is that a host-inflated body is *registered for a pending open at all*: the paths served are the `textures/global/cars/globaltex/*.dds` members (`XSF-BIND-REGONLY` shows `window_detail_mask.dds`, `tmp_underbody_n.dds`, `powerup_beam.dds`, …), and after that `sub_82188E50`'s line-by-line read of the `.list` body stops at one line instead of 167, `GETDEV` drops 694 → 196, and one fatal comes back. **Next hypothesis to test, named but not yet supported by any measurement:** `HostServeUiBody` allocates guest memory for each inflated body, and the globaltex `.list` text the seam expands lives in that same arena — i.e. the pending-open inflates are overwriting the list bytes the walk is reading. The direct test is to log the allocation address range per `HostServeUiBody` call and compare against the list body pages (`C6157B80`/`C6167C00`, the B1 watch targets) before serving anything.

**(3) What `w127` proves about the committed fix.** Only the w3 deletion is in the tree, and every gate marker is unchanged from `w115`: `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0` (`fault-line lr: none`), `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `GFx 3`, `CP-DRAW 166`, `DISCCHK2 41`, `GETDEV 694`, `TOC76 2,079`, `BE8D8-PACK 5` (no serve lost), `unavailable 166`, `[error] lines 15`, `CP truth drains=8 pub=11 put=11`. Counters that moved are throughput-shaped and I am **not** claiming them either way: `INFLATE 419 → 358`, `JOIN 83 → 34`, `PAGESLOT 27 → 9`, `READWRAP 376 → 276`, `fatal 21 → 19`, `rptrWB/PUT +~870` (the run is 18,108 lines vs 16,491). The consistency argument for keeping the change is that no consumer of the w3 index can be *missed* without a serve marker changing, and none did.

**(4) Still true after all of this:** `DRAW_INDEXED 0` in every run, so B4's gate remains unmet, and B2's gate is still met only through the seam + forced-ack path (F-111/F-112), not through delivered bodies.

### F-127 — **The pending-open "regressions" were an advance: serving real archive `.fxc` bodies takes the boot to a gate it had never reached — the rage-effect magic check — and the current frontier only passes that gate because we write the expected word ourselves.**

- Task:        T41.7d (B4 feed / B3 honesty), read from `build/w117.log`/`w124.log`/`w125.log` (serve on) vs `build/w107.log`/`w113.log`/`w115.log`/`w127.log` (frontier, serve off); no behaviour change committed — the mitigation is now labelled in place
- Type:        FACT + a dated correction to F-123 and F-126 + a mitigation registration (B3-style)
- Class:       E (shader/effect serve path) + H (reading a "regression" as such)
- Code:        `src/gpu_device.cpp:12336` (`BE710-DEAD` → the `0x61786772` write), now carrying a `MITIGATION, load-bearing (F-127)` comment; registered in PROGRAM_GUIDE §7

**(1) The gate, decoded from the generated body (executed-semantics authority, rule 3).** `sub_8218C760` does:

```
// addi r4,r1,80 / mr r3,r30 / li r5,1
// bl 0x821be710                 <- read ONE word through the stream
// lis r9,24952   -> 0x61780000
// lwz r7,80(r1)  / ori r8,r9,26482 (0x6772) -> r8 = 0x61786772
// cmpw cr6,r7,r8 / beq cr6,0x8218c878       <- the ONLY way forward
// else: addi r3, <msg> / bl 0x821bd618 (Fatal), lr=0x8218C864
```

`0x61786772` is `'axgr'` — the `rgxa` effect-package magic byte-swapped. So this is a **magic/version gate on the `fxl_final/rage_im.fxc` stream**: the first word read from it must be the magic. In `w127`/`w115` the guest opens it as `GETDEV #5 path='embedded:/fxl_final/rage_im.fxc' ret=827D838C vt=82012918` (an `embedded:` device, not the archive one).

**(2) Why the frontier passes it today (the mitigation).** `BE710-DEAD` fires when that stream's object has a dead device (`[obj+0] == 0`), and the handler answers the 1-word read by **writing `0x61786772` into the caller's destination buffer itself** and returning 1 (`src/gpu_device.cpp:12336-12340`, `BE710-MAGIC #68 wrote 61786772` in every soak). The guest's `cmpw` then succeeds and `loc_8218C878` runs. This is load-bearing: without it the boot hits the fatal that F-117-era soaks never reached. It was **not** in §7 (only `BE710-SLOT` was) — it is now, and it is labelled at the site with its conversion target: make the `rage_im` stream deliver the magic word at the read position instead of having the host write it.

**(3) The correction (this is the part that changes the plan).** F-123/F-126 recorded the pending-open serve (`ret==1` opens host-served) as three refuted attempts because `LISTLINE 167→1` and `GETDEV 694→196`. The counts are right, the reading was wrong: in exactly those three soaks (`w117`, `w124`, `w125`) the log reaches a site that appears **nowhere else** —

| soak | `Old version of rage effect` | lines with `lr=8218C864` |
|---|---|---|
| `w107` / `w113` / `w115` / `w127` (frontier) | **0** | **0** |
| `w117` / `w124` / `w125` (serve on) | 2 | 31 / 33 / 33 |

So the serve **advances** the guest past everything the frontier does and stops it at the rage-effect gate; `LISTLINE`/`GETDEV` fall because the walk downstream of that gate never runs, not because list bytes were corrupted. The two explanations I offered for the collapse are both dead: the w3 registry key (F-126 row 4 behaves like row 3 with the key deleted) and allocation overlap (the served bodies occupy `C9BD7C80…CBBF2C62`, a 32 MB run far above the seam's list pages `C6157B80`/`C6167C00` — measured against `w124`, zero overlap).

**(4) Why it still is not the committed frontier.** It converts a silent starvation into `Fatal error 0 → 1` / `FATAL-SOFT 0 → 1`, which breaks B5's third criterion (zero FATAL-SOFT masking), and `DRAW_INDEXED` stays 0 — so it advances the *site* but meets no gate. `w127`'s state (AV-free, fatals 0, no masking) stays committed.

**(5) Next step, named precisely (T41.9).** Make the magic arrive as data rather than as a host write, then re-run the pending-open serve on top: read the word the guest's `embedded:`/`memory:$` `rage_im` stream actually holds at the position `sub_821BE710` reads, and either (a) show that the archive `fxl_final/rage_im.fxc` member carries `rgxa`/`axgr` at its head and fix our read position, or (b) record as a finding that this prototype's compiled shaders genuinely disagree with the embedded effect runtime, in which case the UI shader feed must come from the `embedded:` family and not from `xarchive_cache.rpf`. The discriminator is one census (the word at the read position vs `0x61786772`) plus one `kExpandListInArchive`-style off/on soak, and the pass condition is `lr=8218C864` reaching the frontier with `BE710-MAGIC` disabled.

### F-128 — **The control proves it: withholding the `BE710-MAGIC` word — a single 4-byte store, once — stops the boot dead at the rage-effect gate. And the write is not 2 calls per boot but 166, every served effect body, all through one reused stream slot.**

- Task:        T41.9 / T41.9b (B4 feed, B3 honesty), `build/w128.log` (census, write ON) + `build/w130.log` (write OFF) vs baseline `build/w127.log`
- Type:        CONTROL (a mitigation proved load-bearing by removal) + FACT (the 166-call shape) + a correction to F-127's fire count + a null result recorded as null
- Class:       E (shader/effect serve path) + H (instrument/citation accuracy)
- Code:        `src/gpu_device.cpp:12326` ff — new read-only `BE710-MAGIC-CENSUS` line and the labelled switch `kBe710MagicWrite` (`true` committed; `false` was `w130`). §7's row corrected.
- Evidence:    `w128` (write ON): `BE710-MAGIC-CENSUS` **166 lines**, `BE710-MAGIC` 166, `LISTLINE 167`, `Fatal error 0`, `C0000005 0`, `CP-DRAW 166` — the frontier, unchanged by the census. `w130` (write OFF, one build flag): `BE710-MAGIC-OFF` **1 line**, then immediately `fatal message: '%s: Old version of rage effect found. You need to recompile your shaders!'`, `Fatal error 0 → 1`, `FATAL-SOFT 0 → 1`, `LISTLINE 167 → 1`, `GETDEV 694 → 196`, `DISCCHK2 41 → 23`; `C0000005 0` and `CP-DRAW 166` held.

**(1) Load-bearing, now proved by removal (rule 19 / B3's own standard).** One withheld word, at the first of those calls, ends the shader path. So the statement "the frontier passes the rage-effect gate only because the host writes the expected `0x61786772`" is no longer an inference from F-127's decode — it is a measured off/on pair on the same tree. B3-style labelling is now backed by a control, and the conversion target stands: the `rage_im`/effect stream must deliver the magic itself.

**(2) The shape is far bigger than F-127 recorded (correction).** `BE710-MAGIC` fires **166 times per boot**, not twice — §7 said "2", which I had copied from an adjacent row instead of counting; the census count is the correction. Every one of those 166 has `obj=82860C68` and `stream=82905500` (constant), while `sbuf` changes each time — i.e. `MakeMemoryStream` keeps overwriting the *same* wrapper slot, and the guest validates the **first word of every effect body it is handed**. The measured heads, with the served sizes: `3170 → 696D6541`, `16482 → ED5B0F70`, `3125 → 95564D6C`, `20882 → ED5C0D70`, `19328 → ED5C0D70`, `14981 → ED5B0D8C`. None is the magic, and the repeated `ED5x0D7x`/`ED5x0F7x` family looks like a compressed or otherwise transformed stream, exactly the state list members were in before F-105's expansion. So the effect bodies we deliver are **not** in the container format this guest validates, and the frontier hides that by stamping the magic 166 times.

**(3) A null result, labelled as one.** Searching the 2,130,739,200-byte `build/game_data/xarchive_cache.rpf` for `rgxa`, `axgr`, `RSC5` and `XComp` returns **0 occurrences** — which proves nothing, because the archive's TOC and payload are encrypted on disk (F-099); the plaintext is only visible through `RpfVirtualFileSystem`, which is where the census above reads it. Do not quote that zero as evidence that the shaders lack the container.

**(4) Consequence for B4, stated plainly.** Getting to `DRAW_INDEXED >= 1` needs effect bodies whose header validates, i.e. the **transform** applied to `.fxc`/effect members the way F-105's expansion applied to `.list` members — not more host-written words. Next concrete step (T41.10, census first, no behaviour change): print the first 32 bytes + an ASCII rendering of one served effect body (the `BE8D8-PACK … head=[…] ascii='…'` pattern already exists for list bodies) and decide whether the bytes are raw DEFLATE (then `MarkMemberExpanded` covers them the way it covers the three list spans) or a genuinely different container. Pass condition for that step: a body that begins `rgxa` after the host's own pipeline, with `kBe710MagicWrite = false` and the frontier markers intact.

**(5) Restore note.** `kBe710MagicWrite` is back to `true` and rebuilt; the committed binary is therefore semantically identical to `w128`'s build (same constexpr value, only a comment differs), and `w128` is that configuration's soak evidence (`LISTLINE 167`, `Fatal error 0`, `C0000005 0`).

### F-129 — **What the rage-effect gate is actually handed: a shader *name list* read from the middle of a string, and undecrypted archive bytes whose first 8 bytes repeat across two different members. Two named host defects, both upstream of `DRAW_INDEXED`.**

- Task:        T41.10 (B4 feed), `build/w132.log` (new read-only `BE710-BODY` census; frontier confirmed equal to `w128`) vs baseline `build/w128.log`
- Type:        FACT (the transform question is answered; F-128 §4's open question closes) + committed census, no behaviour change
- Class:       E (archive serve path)
- Evidence:    `w132` `BE710-BODY` for the six earliest gated reads —

```
#68 sbuf=C9DC6100 size=3170  [696D6541 6C706861 2E66780D 0A556E6C …] 'imeAlpha.fx..UnlitRuntimeColor.f'
#69 sbuf=C9DD7480 size=16482  [ED5B0F70 14E7757F DFEEDE3F E9905620 …] high entropy
#70 sbuf=C9DEF800 size=3125   [95564D6C 1B55109E 5DC78E7F D68E5322 …] high entropy
#71 sbuf=C9E00B80 size=20882  [ED5C0D70 1BC7757E 7B3FC01D F807CA94 …]
#72 sbuf=C9E18F80 size=19328  [ED5C0D70 1BC7757E 7B7700EE 008A0465 …]   ^ same first 8 bytes as #71
#73 sbuf=C9E31380 size=14981  [ED5B0D8C 54D7753E F7BD377F BBC3EE5B …]
```

**Defect 1 — the candidate offset is inside a name table.** The body that the rage-effect gate validates (`#68`, the read whose word our mitigation stamps) begins mid-string: `'imeAlpha.fx' CRLF 'UnlitRuntimeColor.f…'`. So the 3,170-byte member the host delivered is *name-list text*, sliced from a point that is not a record start — and `HostServeUiBody`'s only sanity filter on a candidate is `be != 0 && be != 0xCDCDCDCD && be != 0xFFFFFFFF`, which any text or ciphertext word passes. `XsfOffsetCandidates` can therefore return a body that is the wrong file's bytes at the wrong offset, and nothing in the pipeline notices (this is the same family as F-053's "one file's body for another", now caught by content instead of by inference).

**Defect 2 — the archive members are not decrypted.** `#71` (20,882 B) and `#72` (19,328 B) are different members with the **identical first 8 bytes** `ED5C0D70 1BC7757E`, and all five non-text bodies are high-entropy with no zlib header (`78 9C/01/DA`). Compression does not reproduce an 8-byte prefix across unrelated payloads; a keystream/XOR with the same nonce does. So what the host VFS hands the guest for these members is still encrypted/undecoded image data — while the three `.list` spans that F-105's `MarkMemberExpanded` mechanism covers do come out as plaintext. Coverage of that expansion, not the read position, is the gap: F-128 §4's question is answered as "both a wrong candidate and a missing decode", and the missing decode is the one that affects every non-list member.

**Frontier check for the census.** `w132` vs `w128`: `C0000005 0`, `Fatal error 0`, `FATAL-SOFT 0`, `GETDEV 694`, `TOC76 2,079`, `DISCCHK2 41`, `CP-DRAW 166`, `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `GFx 3`, `[error] lines 15`, `CP truth drains=8 pub=11 put=11`, `LISTLINE 167` — all equal, so the census is observationally neutral (unlike F-125's hook, which was not).

**Next (T41.11), with the pass condition stated.** The gate's pass condition is unchanged and now mechanical: with `kBe710MagicWrite = false`, a body whose first word is `0x61786772` must appear from the host pipeline. Two candidate moves, in the order the evidence supports: (1) make `HostServeUiBody`'s candidate acceptance *content-based* rather than sentinel-based — for a member the guest opens as an effect/rage container, require the container magic, and log the reject (`-BLOCKED`-style) so a wrong candidate cannot silently ship; (2) find the decode the `.list` spans get and are missing elsewhere — the `ED5C0D70 1BC7757E` repetition is the fingerprint to chase (a fixed keystream start means the key/nonce is constant per archive, so the guest's own decryption routine, reachable by `tools/ppc_xrefs.py find-str` on the archive header strings, is where to look). Do not stack a host-written word on top of either: F-128 proved that word is what currently hides this layer from us.

### F-130 — **Why no archive effect body ever arrived with a container header: the span expansion in `vfs_rpf.cpp` can only substitute a member that fits whole inside one read window, so a page-straddling member is handed over still DEFLATE-compressed. Inflating the candidate in `HostServeUiBody` fixes it — and that is what exposes F-131.**

- Task:        T41.10 / T41.11 (B4 feed), `build/w134.log` + `build/w136.log` vs baseline `build/w132.log`
- Type:        FIX (candidate acceptance + per-candidate inflate, inert at the frontier) + FACT
- Class:       E (archive serve path) + H (an instrument that cannot fire)
- Code:        `src/gpu_device.cpp` — `XsfOffsetCandidates` results are now filtered by content: pass 0 accepts only a candidate whose first word is `rgxa`/`RSC5`/`XCompress`, and a non-magic candidate is fed through `mcla::RawInflate` (the same helper the VFS uses) before the decision; `XSF-INFLATE` logs the acceptance. `raw_inflate.h` is now included here.
- Evidence:    the mechanism was invisible because `MEMBER-EXPAND` printed for exactly **6** offsets in every soak (`000D0000`, `001DD11C`, `001F41FB`, `0027F1AF`, `002DB9A1`, `00304E12`) and `MEMBER-EXPAND-FAIL`/`-SIZE` printed **0** times — i.e. the cross-page members were never even attempted (`ApplyExpandedSpans` skips a span unless `s.off + s.storedLen` lies inside the window). `w134` confirmed the consequence: `pass=0` **0** hits, all 34 serves via `pass=1`, `72677861` nowhere in the log. After the inflate: `w136` shows `XSF-INFLATE path='shaders/ui/fxl_final/AlphaModulate.fxc' off=001DD1E8 stored=3170 expanded=3170 head=9556CD6F->72677861` and the magic appearing 4 times.

### F-131 — **The archive-shader route is CLOSED by a version mismatch measured offline, not by a host bug: this prototype's effect runtime is `rgxa 03 ff 03 10`, the retail archive's compiled effects are `rgxa 01 ff 01 12`. Feeding archive `.fxc` bodies can therefore never reach a draw, and `BE710-MAGIC` is what has been hiding the disagreement.**

- Task:        B2/B4's "record why it cannot" branch, measured from `build/cache/mcla_pe.bin` and `build/game_data/xarchive_cache.rpf` directly (rule 3: raw bytes, no emulator), with the soak consequence in `w117`/`w124`/`w125`/`w134`/`w136` vs frontier `w127`/`w138`
- Type:        FACT (a closed route) + revert of the pending-open serve + a correction to F-127/F-129's framing
- Class:       E (content vintage) — not a kernel or emulator defect
- Evidence:    at guest `0x827D2DD0` (the blob our own `BE0C8-FIX`/`AFB76-FALLBACK` hand to the guest as `fxl_final/rage_im.fxc`, and which the guest opens as `embedded:/fxl_final/rage_im.fxc` → `GETDEV-RET #5 ret=827D838C vt=82012918`) the image holds

```
72 67 78 61 03 ff 03 10 56 53 5f 54 72 61 6e 73 66 6f 72 6d 4c 69 74 …   'rgxa' VS_TransformLit
```

  and the archive's own member, inflated at its TOC offset `0x1DD1E8`/`0xC62`, begins

```
72 67 78 61 01 ff 01 12 56 53 5f 55 6e 6c 69 74 54 …                     'rgxa' VS_UnlitTransform
```

  `rgxa` in both, **different version fields** (`03 ff 03 10` vs `01 ff 01 12`). `sub_8218C760` reads the container and reports exactly that difference: `'%s: Old version of rage effect found. You need to recompile your shaders!'` (`lr=8218C864`). The image carries **13** `rgxa` containers (`0x827d2dd0`, `0x827d4458`, `0x827e2cb0`, `0x827f3c48`, `0x827f5380`, `0x827f61a0`, `0x827f9ce8`, `0x82801b00`, …), i.e. the embedded family is self-consistent and v3; `xarchive_cache.rpf`'s compiled effects are v1. So this prototype XEX cannot consume the retail cache's shaders at all.
- Consequence, stated as the plan requires: **B4's shader feed cannot come from `xarchive_cache.rpf`.** Every attempt to serve those bodies (F-123's T41.7, F-126's T41.7b, this turn's T41.11 with correct inflate + magic-preferred candidates) ends at the same fatal with `LISTLINE 167 → 1`, `GETDEV 694 → 196`, `FATAL-SOFT 0 → 1` — and with the *correct* body delivered (`w136`) it still fails, which is what proves it is content vintage and not our decoding. The UI shader path must therefore come from the XEX's own `embedded:` containers, which the guest already opens (`AFB8-IN #1 path='embedded:/fxl_final/rage_im.fxc'`).
- Reverted: the pending-open serve (`ret == 1`) and the two blocks it needed — this file no longer contains `g_servedOnce`/`XSF-BIND-REGONLY`. Kept, because they are correct and inert at the frontier: the magic-preferred candidate pass, the per-candidate inflate, `BE710-MAGIC-CENSUS`/`BE710-BODY`, and `kBe710MagicWrite` (true).
- Frontier after this commit: `build/w138.log` — `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0`, `CP-DRAW 166`, `GETDEV 694`, `DISCCHK2 41`, `PRESENT-FB 4`, `GFx 3`, `XSF-INFLATE 0`, `DRAW_INDEXED 0`.
- Corrects F-129's closing hypothesis: the missing decode is real (F-130) but delivering the decoded bytes does not unblock B4 — the version gate does the blocking, and `BE710-MAGIC` has been stamping over it 166 times a boot.

### F-132 — **The frontier's last deterministic guest event is named, and it is not a stall we mis-read: `LISTLINE #167` → open `embedded:/fxl_final/rage_postfx.fxc` → a physical allocation of `size=0xffffffff` that fails → silence. The "321 MB of poison copied" is what the guest's own buffered-stream refill does *after* that, and my `BE250-HUGEREF` probe probed a quantity that cannot exist. Both corrected here.**

Evidence (all lines re-measured this session; `build/w138.log` = committed baseline, `build/w140.log` = 305 s soak, `build/w141.log` = 245 s soak with the reverted probe):

- The frontier tail is identical in every run, so the state is not run-dependent:
  - `w138:12543` `LISTLINE sub_82188E50 #167 … 09:06:31.286` → `w138:12554` `BDF20 #532 path='embedded:/fxl_final/rage_postfx.fxc' flags=1 ret=-2105144256 lr=8218C7F4` → `w138:12555` `AllocPhysical: o1heapAllocate returned null #1 size=0xffffffff align=0x10` at `09:06:31.287`.
  - `w140:13056`/`w140:13057` print the same pair at `09:11:30.313`. The fired-once-per-boot count (`#1`) is the same in `w138`, `w140`, `w141`.
  - After that, only `WAIT[KWFSO] … to=30ms` / `WAKE[KWFSO]` (`put=11 rptrWB=001F`, `pc=005A0E10:0`) and the host's own `RING:`/`HB-FLICKER` heartbeats. `w138` ends 29 s into that state (1779 wait lines, last at `09:07:00`) — the baseline was killed inside the same parked loop, which is why it never showed the fill below.
- What the guest is doing during the long silences (only visible in the longer soaks): poison stores through the guest's own memcpy.
  - First `lr=821BE3BC` store `w140:22344` `CDCD-FILL #000020000 @ 1D7B0DBC` at `09:12:43.045` — 73 s after the failed allocation; then `w140:23420` `@ 217A0B50`, and the last line `w140:32610` `#080340000 @ 352CF350` at `09:13:40.367`. The counter is decimal (`{:09}`), so that is 80,340,000 four-byte stores ≈ 321 MB, at scattered (not contiguous) destinations.
  - Statically identified, no guesswork: `generated/ppc_xenon/ppc_recomp.14.cpp:24266-24300` is `sub_821BE250`'s refill tail — `ctx.lr = 0x821BE3BC` (`:24287`) then `sub_823DA950(ctx, base)` (`:24288`, the guest memcpy) with `r3=r29`, `r4=[obj+8]+[obj+24]`, `r5=r30`, and `r30` clamped by `cmpw cr6,r30,(r11-[obj+24])` (`:24269-24276`), followed by `[obj+24] += r30` (`:24295`). So the copy length is bounded by the **caller's requested count**, and the cursor advance is real.
- Null result, and why the probe was wrong: `BE250-HUGEREF` (span `[obj+28]-[obj+24] > 0x10000` at hook entry) fired **0** times in `w141` while `CDCD-FILL` printed 4012 lines. `w140:11459` shows the reason in the same log family — `BE250-GUEST #1200 obj=82860C68 dev=C60AC180 h=1 dst=CB0D1A80 count=20754 +8=82862DF8 +24=00000000 +28=00000000 +32=00001000 lr=821BE93C` — `end == cur == 0`, `cap = 0x1000`: the span the probe tested can never exceed 0x10000 for this object. The probe is reverted in this commit (rule: an instrument that cannot fire on the quantity it names is dead weight, F-125).
- Caller of the `0xffffffff` allocation is **still unnamed**, and the candidate set is now closed to two:
  - `MmAllocatePhysicalMemoryEx` (`src/kernel/imports.cpp:1978-1998`) is **ruled out** — it logs its own `MmAllocatePhysicalMemoryEx: FAILED size=… lr=…` on every null return and that string appears 0 times in `w138`/`w140`/`w141`.
  - Remaining: the guest import `sub_831CC9C8` → `XAllocMem(size, flags)` (`src/kernel/heap.cpp:507-518`, registered at `:534`), whose physical branch passes `align = 1 << ((flags>>24)&0xF)` — `align=0x10` means nibble 4, consistent; or one of our own `GuestMemoryHeap::Alloc(x, 16)` host sites (`src/kernel/memory.cpp:334-339` → same print).
- Latent host defect found while reading that function, independent of who called it: `src/kernel/heap.cpp:513-514` runs `memset(ptr, 0, size)` when `(flags & 0x40000000)` **before** checking `ptr`, with `assert(ptr)` only afterwards — with the arena exhausted (this alloc asked for 4 GB−1) that is a null-pointer memset of `0xFFFFFFFF` bytes on the guest's own thread. Not yet observed to fire (the `0x40000000` bit's state is unknown — that is exactly what the next probe must print).
- Next step taken in this commit: a store-level, therefore bypass-proof, census `CDCD-RUN` in `src/gpu_cp.cpp` (`PageWatchOnWrite`, inside the existing `value == 0xCDCDCDCDu` branch): per-thread contiguous-run tracking that logs at 64 KB / 1 MB / 16 MB / 64 MB / 1 GB of one run, with the run's base address and the writer's in-flight `r1,r3..r10` — the fields that name the buffer and the bound. Experiment: `build/w142.log`.

### F-133 — **The store-level census names the number: the guest's memcpy length register at the poison store is `r5 = 0xFFFFFFFF` — the *same* value as the physical allocation that failed 55 seconds earlier at the frontier, on the same stack slot. And the census that proved it is itself not frontier-neutral, so it is reverted here.**

`CDCD-RUN` (9 lines in `build/w142.log`), the shape of every one of them:

- `w142:29294` `start=1D79F44C now=1D7AF448 len=65536 lr=821BE3BC r1=8EFFEA70 r3=1D79F3F8 r4=A00011F0 r5=FFFFFFFF r6=CDCDCDCD r7=CDCDCDCD r8=CDCDCDCD r9=00000408 r10=00000008`
- `w142:35032` `start=2279F208 now=2679F204 len=67108864 … r4=A5000FF0 r5=FFFFFFFF …` — one contiguous run of **64 MB**, still growing when the milestone printed.
- `w142:45782` `start=3516F208 … len=65536 … r4=B79D0FF0` — same shape at a different base, 26 s later.

What that fixes, and what it rules out:

- The copy length is `0xFFFFFFFF` in `r5`, i.e. the guest's `sub_823DA950` (memcpy) is called with `n = 4 GB − 1`, not with a plausible file size and not with a value derived from `[obj+28]-[obj+24]` (F-132's refuted hypothesis). The clamp at `ppc_recomp.14.cpp:24269-24276` can only shrink `r30` toward `r11-[obj+24]`, so the `0xFFFFFFFF` entered `sub_821BE250` from its **caller** as the requested count.
- `r1 = 0x8EFFEA70` is byte-identical to the frontier's own park record in the baseline (`w140:13079` `PARK-STACK sp=8EFFEA70 lr=821BE3BC: f0=FFFFFFFF f1=00000000 f2=8218C7DC f3=82188EF4 …`) — same thread, same stack frame, and that frame's `f0` is the *other* `0xFFFFFFFF`. So the storm and the parked main thread are the same invocation, and `0xFFFFFFFF` appears both as a stack word and as the copy length.
- The value equals the frontier's failed allocation size exactly (`w138:12555` / `w140:13057` `AllocPhysical: o1heapAllocate returned null #1 size=0xffffffff align=0x10`, one per boot) — so the single wrong number to chase is now one, not two.
- Sources `r4` are in the guest's *physical* range (`A00011F0`, `A4000FF0`, `A5000FF0`, `B79D0FF0`) — `0xAxxxxxxx` is where `PHYS-OVERRUN`/`TSLAB-OWNER` look, so the copy reads a physical pointer + `0xFF0` offset while writing into the low virtual heap (`0x1D7…`–`0x35…`). No allocation we handed out covers those bases (`PHYS-OVERRUN 0` in `w142` — the check is `>= 0xA0000000`, and the *destinations* are below that line).
- Instrument cost, stated honestly: `soak_census build/w142.log build/w138.log` keeps the whole frontier (`LISTLINE #167` 1, `GETDEV 694`, `DISCCHK2 41`, `CP-DRAW 166`, `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `TOC76 2079`, `C0000005 0`, `FATAL-SOFT 0`, `swfCMD 0`, `DRAW_INDEXED 0`, and `RD-SUBMIT 24` so it is not a VOID soak — F-123's mode check) **but** four markers that fired in all three earlier runs of the identical tree stop: `P5-PHYS … skip fatal` 18 (w138) / 14 (w140) / 15 (w141) → **0**, `W34-NOGFX` 1→0, `W34-GFX-CENSUS` 1→0, `GFx` 3→1. Per F-125 that makes the instrument uncitable as a standing probe, and per F-054 a poisoned soak is worse than no soak: the census is **removed from `src/gpu_cp.cpp` in this commit**. The numbers above stand as one-shot evidence only because each of them is corroborated by a baseline line (`w138:12555`, `w140:13079`) that was recorded without the instrument.
- Replacement probe, in the same commit: `XALLOC-HUGE` in `src/kernel/heap.cpp` (`XAllocMem`, registered as the guest import `sub_831CC9C8` at `:534`) — logs `size`, `flags`, `lr`, `r3/r4/r5` and 8 guest stack words once per huge request. It sits on a host path that runs once per boot, so it cannot perturb a per-store or per-frame timing; it is the probe that names the caller of the `0xFFFFFFFF`. Experiment: `build/w143.log`.

### F-134 — **The `0xFFFFFFFF` is not data at all: it is the guest's own `GetSize` *error return*, and the reason it fires is that our `MakeMemoryStream` had run out of slots and went back to handing the guest a raw pointer as a handle. Every link is now closed by a log line or a raw word.**

Attribution, step by step, each with its own evidence:

1. `build/w143.log` (130 s, `XALLOC-HUGE` census in `src/kernel/heap.cpp:507`): the frontier's `AllocPhysical: o1heapAllocate returned null #1 size=0xffffffff align=0x10` fires (09:45:32.997, right after `BDF20 #532 path='embedded:/fxl_final/rage_postfx.fxc'`) while **`XALLOC-HUGE` prints 0 lines**. With `MmAllocatePhysicalMemoryEx` already excluded (its own `FAILED` line appears 0× in `w138`/`w140`/`w141`/`w143`), the only remaining caller of `Heap::AllocPhysical` is `GuestMemoryHeap::Alloc` (`src/kernel/memory.cpp:334-344`), whose only guest-facing entry point is **`__xtl_alloc`** (`src/kernel/imports.cpp:51-57`). `w143` frontier intact (`RD-SUBMIT 24`, `P5-PHYS 14`) ⇒ the probe is frontier-neutral and its zero is citable.
2. Why `align=0x10` fits: the XTL import thunk `sub_82130528` (`generated/ppc_xenon/ppc_recomp.0.cpp:864-889`) is `lwz r11,0(r13); li r10,28; mr r4,r3; li r6,0; li r5,16; lwzx r3,r10,r11; …; bctr` — it moves the caller's r3 (the size) into **r4** and pins **r5 = 16**, exactly matching `__xtl_alloc`'s reading of `r4`/`r5`. No argument-mapping bug in our shim.
3. Who passed -1 down: `sub_821BE8D8` (`ppc_recomp.15.cpp:199-236`) computes `size = [[dev]+56](dev, handle)`, then `mr r3,r30; bl 0x82130528` (allocate) and `sub_821BE250(wrapper, buf, size)` — **with no check for an error return**. `BE8D8`'s own caller at the frontier is the rage-effect loader: `bl 0x821be8d8` with `ctx.lr = 0x8218C804` (`ppc_recomp.9.cpp:18394-18396`).
4. The two `GetSize` implementations, decoded from `build/cache/mcla_pe.bin` (rule 3, `offset = VA − 0x82000000`), both return `li r3,-1` on a bad handle:
   - archive device (vtable `0x82012BDC`, slot +56) = **`0x821CD3C8`**: `cmpi r4,0` → -1; `cmpi r4,16` → -1; `toc=[dev+40+h*68]`, `cmpli toc,0` → -1; else `[toc+4]`. So `0xFFFFFFFF` is an **error code**, which corrects F-132's "a size field read as garbage" framing.
   - embedded/memory device (`0x827D838C`, vtable `0x82012918`, slot +56) = **`0x821CABB8`**: sizes the stream by calling `[[this]+44]` (Seek) with whence 1 then 2 — and `+44` is `sub_821CB2A0`, which *we* install (`src/gpu_device.cpp:11538`), the very function whose `if (h < 0 || h >= 16) return -1` this file already documents at `:11641-11647`.
5. The census proves which call and which handle. `BE8D8-RAGESZ` (fires only on `lr=0x8218C804`, and only when the guest's own GetSize will answer -1, or the wrapper is not the reused `0x82860C68`) printed **exactly one line in the whole boot** — `build/w145.log` 09:56:37.522: `n=173 obj=82860C40 dev=827D838C vt=82012918 h=0x82905500 getSz=821CABB8 toc=0 doomed=1`.
   - `obj=0x82860C40` **is** the wrapper the frontier's open returned: `BDF20 #532 … ret=-2105144256` = `0x82860C40` (and `BDF20 #1` returned `0x82860C18` — these are static wrappers 0x28 apart, and `kBdf20Wrap` at `:11277` binds only the latter).
   - `h=0x82905500` **is** the value our own serve printed for that same file: `AFB76-HIT #4 path='embedded:/fxl_final/rage_postfx.fxc' buf=8281BB00 size=38024 stream=82905500`. A *pointer* sat in the handle field, so the device's Seek rejected it, so `GetSize` returned -1.
6. Why a pointer: `MakeMemoryStream` returns a slot **index** only while `GuestSlotTableInsert` succeeds, and its fallback (`:11708-11709`) returns the `.data` slot object pointer. `w145` shows the exhaustion in order: `SLOT-REG #1…#16 idx=1…15` (the table holds indices 1..15 — 0 is reserved as the open-success sentinel), then `SLOT-TABLE-FULL #1 (16/16 in use)` at 09:56:36.820, then the doomed `BE8D8` 0.7 s later. Nothing in the file releases a slot except the one `BE8D8` memory-device path that writes `[slot+0]=0` (`:12024`), so every served body after the fifteenth got a pointer handle. That is the whole frontier: 15 slots, no recycle, then `-1` → 4 GB alloc (`w138:12555`) → 4 GB read (`w142`, F-133) → park (`w138` tail, F-132).
7. Logging defect noted so nobody re-reads it wrong: `XSF-POSTOPEN-SERVE`'s `handle={}` field prints `ret`, which in that block is the Open **status** (always 0, since the block is gated on `ret == 0`), and the same 0 is passed to `MclaRegisterServedBody` as its handle argument (`:11269-11270`). Not the cause of the 21 `BE8D8-PACK-MISS` lines — F-126 established that only `tocEntry` is an exact key — but the field name is misleading and must not be read as a handle.

### F-135 — **The fix holds and the frontier moves for the first time in this chain: giving the guest a real slot index instead of a pointer kills the `0xFFFFFFFF` allocation, kills the 321 MB poison storm, and carries the `.list` walk from `#167` to `#171` — four more embedded effects load, and the boot now dies inside the *renderer* (`grmShaderGroupVar 'skinningData' not found`). Two iterations were needed, and the first one is recorded as insufficient.**

What was changed, in `src/gpu_device.cpp` `GuestSlotTableInsert` (the function F-134 showed had no release path):

- Iteration 1 (`build/w146.log`) — recycle a slot only when the guest has read it to its last byte (`[slot+8] pos >= [slot+4] size`). **Insufficient and measured so:** it fired exactly once (`SLOT-RECYCLE #1 idx=1 … size=13908`) and the table still filled (`SLOT-TABLE-FULL #1…#8`), the doomed `BE8D8` still happened (`w146:12649 … h=2190497024 doomed=1`) and the 4 GB alloc still failed (`w146:12650`). Reason, from the same log: these bodies are consumed through the served-registry path, not through `SlotTableServeRead`, so `slot pos` never advances and the criterion can almost never match.
- Iteration 2 (`build/w147.log`, kept) — before the pointer fallback, reuse the index **this same host path handed out last**. Justification is in the code comment and is not a guess: `MakeMemoryStream` describes *every* stream with one shared static object (`kMemStreamSlot = 0x82905500`), so an older handle from this path already aliases the newer body whether or not the slot table does — the pointer fallback bought nothing. Labelled `MITIGATION` at its `file:line` (do-not #9) and registered in `PROGRAM_GUIDE` §7 as `SLOT-RECYCLE-SHARED`.

Verification — `tools/soak_census.py build/w147.log build/w138.log` (205 s soak, `w138` = the committed baseline):

| marker | w138 | w147 |
|---|---|---|
| `AllocPhysical … size=0xffffffff` | 1 | **0** |
| `BE8D8-RAGESZ … doomed=1` | 1 | **0** |
| `SLOT-TABLE-FULL` | 8 | **0** |
| `SLOT-RECYCLE-SHARED` | 0 | 24 |
| `LISTLINE` lines | 167 | **171** |
| `CDCD-FILL` lines | 24¹ | **24** (no storm) |
| `C0000005` / `swfCMD` | 0 / 0 | 0 / 0 |
| `GETDEV` / `CP-DRAW` / `PRESENT` / `PRESENT-FB` | 694 / 166 / 34 / 4 | 694 / 166 / 34 / 4 |
| `Fatal error` / `FATAL-SOFT` | 0 / 0 | **10 / 18** |
| `RD-SUBMIT` | 24 | 24 (not a VOID soak, F-123) |

¹ The `CDCD-FILL` comparison has to be made against the *longer* soaks, not `w138`: `w138` was killed 29 s into the park and never reached the storm either. At comparable duration the storm is gone — `w140` (305 s) 4,041 lines / store `#080,340,000`, `w141` (245 s) 4,012 lines, `w147` (205 s) **24** lines.

- The advance is the four extra `.list` lines, and their text names them: `w147` ends the walk at `#168 'embedded:/rage_shadowdepth'`, `#169 'embedded:/rage_blendshadows'`, `#170 'embedded:/rage_shadowcollector'`, `#171 'embedded:/rmptfx_collision'`. `w138` stops at `#167 'embedded:/rage_postfx'`. So the loader now reads the embedded effect bodies it previously could not size — exactly what F-131 said B4 needs (v3 containers from the XEX, not the archive).
- Cost, stated, not hidden: `FATAL-SOFT 0 → 18` and `Fatal error 0 → 10`, so B5's third acceptance criterion is **no longer met** by this build. These are the guest's own hard errors, soft-parked by the existing dispatcher mitigation, and they are *new* gates rather than the old one — see below. `w147` is also flagged `POISONED` by the census for log quality (7,990 `P5-LOOKUP … POISON` lines), so only the frontier markers above are citable from it, not its volume.
- The new frontier, named from the guest's own registers (no new instrument): `w147` 10:11:35.646 `fatal-dispatch regs: lr=0x82193BA0 r1=0x8EFFF8A0 r3=0x8200C4C4 r4=0x8204A408 r5=0x00000001`, and those words decode from `mcla_pe.bin` as `r3 = "Required grmShaderGroupVar '%s' not found."`, `r4 = 'skinningData'` — i.e. a **shader-group variable lookup**, inside the renderer, after the shader files loaded. Immediately before it: `P5-LOOKUP #014185 r3=8EFFF170 r4=CDCDCDCD -> FFFFFFFF lr=8224C074 POISON` (the lookup key itself is poison, 14,185 attempts). The other two soft-parked fatals are `Resource 'Invalid fixup, address is neither virtual nor physical'` (`lr=82184514`, strings at `0x82013168`/`0x82009840`) and `Bad resource type %d in grcTextureFactoryXenon::PlaceTexture` (`lr=8217EC4C`).
- Next step, on-plan (B4): take the `P5-LOOKUP` poison key as the target — name what should have written the handle at `lr=8224C074`'s caller, because `grmShaderGroupVar 'skinningData'` is the same lookup failing one level up. `BE710-MAGIC` doubled (166 → 332) with the fix, consistent with more served bodies going through the slot path, and it is still the mitigation that must be retired once real v3 bytes satisfy the gate on their own.

### F-136 — **The gate F-135 uncovered is a content fact, not a host bug: the shader variable `skinningData` is required by code but defined by NO shader data resident in this XEX. Measured offline with a fired positive control on the same test.**

The new frontier, named statically (no new instrument was needed — the fatal dump already carries the registers):

- `build/w147.log:94881` `fatal message: 'Required grmShaderGroupVar '%s' not found.'`, with the register dump on the next line: `lr=82193BA0 r1=0x8EFFF8A0 r3=0x8200C4C4 r4=0x8204A408 r5=0x00000001`, and the soft-park line `FATAL-SOFT: 'Required grmShaderGroupVar '%s' not found.' lr=82193BA0`. Decoded from `mcla_pe.bin`: `r3` = the format string at `0x8200C4C4`, `r4` = the literal `'skinningData'` at `0x8204A408`.
- The site is `sub_82193AF8` (`ppc_recomp.10.cpp:17708`): a loop over `r29` group variables calls `sub_8218A568` per entry and counts matches in `r26`; at `loc_82193B7C` it checks a "required" flag byte (`clrlwi r11,r25,24`; `beq → skip`) and **fatals when the flag is set and `r26 == 0`** — i.e. this is a required-variable binding failure, not a corrupted pointer.
- Its caller is the game's material setup `sub_82507FE0` (`ppc_recomp.102.cpp:1156`, call at `:1516` `bl 0x82193af8`), which iterates `r24` entries of a **name array** (`lwz r4,0(r28); mr r3,r22; r28 += 4`) — so the group is bound against a fixed list of required variable names taken from code, and `'skinningData'` is one element of that list (its neighbours at `0x8204A3FC`/`0x8204A418` are `effectFade` and `entity.type`).
- **The content measurement.** Searching all of `build/cache/mcla_pe.bin` (10,354,688 bytes = 9.875 MiB, rule-3 identity map): `skinningData` occurs **exactly once** — at `0x8204A408`, the code-side name itself. `effectFade` once (`0x8204A3FC`), `worldView` once (`0x8204A1B8`). None of them occurs inside the embedded `rgxa` family (span `0x827D2DD0`–`0x82820000`, 13 containers: `0x827d2dd0 0x827d4458 0x827e2cb0 0x827f3c48 0x827f5380 0x827f61a0 0x827f9ce8 0x82801b00 0x82803540 0x82813908 0x82814d00 0x82815e48 0x8281bb00`).
- **Positive control on that same test** (so "not found" means something): the container name tables are plaintext, not hashed — `VS_TransformLit` occurs 2× and **both inside** the container span (`0x827d2dd8`, `0x827d2e70`), and `Texture` occurs 161× with 106 of those inside it. A name that existed in a container would have shown up.
- **The control is now proved by the code, not just by the statistics** (`sub_8218A568` decoded, `ppc_recomp.*` — the resolver the loop calls): it normalises the requested name through `sub_821C9790` — `lbz/extsb`, skip on `c-34`, and the `65 … 90` range test — i.e. it **case-folds and returns a pointer into the original string**, then walks `lhz [entry+12]` sub-entries. There is no hash anywhere on this path, so "the plaintext name is not in the containers" is exactly the guest's own test.
- Layout worth keeping for the next probe: the group's **variable count is the halfword at `[group+12]`** and its pointer array at `[group+8]` (`lhz r27,12(r23)` / `lwz r11,8(r23)` in `sub_82193AF8`), and `count <= 0` branches **straight to the fatal check** (`ble cr6,0x82193b7c`, `ppc_recomp.10.cpp:17765-17766`) — so "group has no variables" and "group has different variables" both end at this same message. Which of the two it is cannot be told from the fatal dump, because `r23` is a callee-saved register and r14-r31 are host locals in this build (no `PPCContext` slot).
- Consequence, stated as the plan requires: **the variable this gate demands is not defined by any shader data currently resident**, so no serve of bytes we already hand to the loader can satisfy it — the definition has to arrive with a resource this boot never reads. Two candidate sources, and the difference is the next question, not this finding: (a) the archive's compiled-effect family, which F-131 proved is `rgxa v1` while this runtime demands v3; (b) a material/shader-group resource that is resident but whose load we short-circuit or fail earlier (the `PlaceTexture` / `P10-PRE` poison around the same window is consistent with that, and is *not* proven either way). Either way **B4's renderer feed cannot be reached through the `skinningData` binding as things stand**: it must be driven from a shader group whose variables ARE populated in this boot, or B4 records that it cannot be reached from the content available.
- Supporting counts in `w147` for the surrounding state (not the gate itself): `P10-PRE 5,812` (`id=CDCDCDCD`, `group=0x8EFFF150 table=0x8EFFF170`), `P5-LOOKUP 7,990` (store #014,185 of the same poison-id lookup, `lr=8224C074`), `P10-GATE 4,030`, `REBASE-POISON 26` (params in our own synthesised `0xB71110xx` region), `grmShaderGroupVar` fatal 2 lines, `PlaceTexture` 2 lines. Per the instrument's own comment (`src/task_dispatch_trace.cpp:575-580`) the original `sub_8217D890` body **fatals and never returns** on `id=0xCDCDCDCD`, which is why the poison-id path is a mitigation already in place, not a new one.
- Not claimed: that the poison `id` values cause this fatal. The `sub_82193AF8` check is an independent "required var absent" verdict, and the group's variable list being unpopulated may be a consequence of the same missing content rather than of the rebase misses.
- Addendum, measured before anyone chases it: **the `P10-GATE` delta-0 mitigation does not explain the `Bad resource type 0x6643 in grcTextureFactoryXenon::PlaceTexture` gate.** Histogram of the 4,030 `P10-GATE` hits in `w147` by caller: `lr=821D2AD0` 3,923, `lr=825EE56C` 83, `lr=8217EC24` (the `PlaceTexture` rebase, `ppc_recomp.*`: `lwz r4,0(r31); bl 0x8217d890; r5 = delta + [r31]; stw r5,0(r31)`) only **6**, `lr=826050D0` 3. And the ids behind those misses are small integers (`000000C0` 128×, `00000001` 104×, `00000080` 84×, `000001FF`/`00000082`/`00000040` 80× each), i.e. that population is an id/handle use of `sub_8217D890`, not pointer sliding. `PlaceTexture`'s own type field therefore still has no cause assigned — it is the next gate to name, not this one.
- **How much the F-135 fix actually bought, measured**: the file walk advanced but the **renderer feed did not**. `tools/soak_census`-style counts are identical in `w138` and `w147` — `PKT-CAP summary 15 / 15`, `CP-REG-T 1171 / 1171`, `INDIRECT_BUFFER 11 / 11`, `DRAW-SEAM 10 / 10`, `CP-DRAW 166 / 166`, `DRAW_INDEXED 0 / 0` — and **no CP marker appears after the `skinningData` fatal line** (`w147:94881`; last CP activity `10:11:30.860`, the fatal `10:11:35.646`). So the four extra `.list` lines are real guest progress but do not yet reach the 3D state B4's gate is about, and this gate sits on the path to it.

### F-137 — **The two renderer fatals are one 2 ms window, and both are the same defect class: a resource *pointer* slot holds a small integer. Decoded from raw bytes: `sub_82185190` is a type dispatcher that accepts only types 0/1/2, and at the fatal its own descriptor argument was `0x00020037` â€" which is not an address. Cause not assigned; the honest state is "named, with the value in hand".**

From `build/w147.log` (all four lines inside 2 ms):

- `101701` `CP: MMIO write reg=0081 offset=0207 value=80010000` (10:12:29.685)
- `101702` `P5-84458-CENSUS #00008 obj=80010000 vt=00000000 +24=00000000 +28=00000000 res+32=00000000 arr=00000000 [arr]=00000000 rsc=0 lr=8217EC4C`
- `101720-23` fatal `lr=82184514` â€" `'Resource '%s': %s (ptr=%p)'` with `r4=00000000`, `r5=82009840` = `'Invalid fixup, address is neither virtual nor physical'` (both strings decoded from the image at `0x82013168`/`0x82009840`)
- `101730` fatal `lr=8217EC4C` â€" `'Bad resource type %d in grcTextureFactoryXenon::PlaceTexture'` with `r4=00006643`, `r5=00020037`

What the raw bytes say about the second one (`sub_82185190`, the function that holds the string; the string has exactly one referencing instruction, `addi r3,r10,-22744` at `0x821851B4`):

```
82185190  mr   r5,r3            ; r5 keeps the descriptor pointer for the print
82185194  lhz  r11,12(r3)       ; type = halfword at [desc+12]
82185198  cmpli cr6,r11,1
8218519C  bc   LT -> 821851C0   ; type 0  -> tail b 82184458  (the fixup above)
821851A0  blr  EQ               ; type 1  -> return, nothing to do
821851A4  cmpli cr6,r11,3
821851A8  bc   LT -> 821851BC   ; type 2  -> tail b 8218FBB0
821851AC..B8                    ; else    -> fatal "Bad resource type %d", r4=type
```

- So the accepted set is **{0, 1, 2}** and the observed type is `0x6643` = 26,179. But `mr r5,r3` at entry means the fatal's `r5 = 0x00020037` **is the descriptor pointer itself** â€" a 17-bit integer, not an address (above the 4 KB guard, below any arena). Reading `lhz [0x20037+12]` then returns whatever the flat guest heap happens to hold there, which is how a "type" of 26,179 appears. The type is not corrupt; the **pointer slot is**.
- The same shape one step earlier: the fixup ran on `obj=0x80010000` (`P5-84458-CENSUS`), and `0x80010000` is *also* the value the guest OR-wrote into CP register `0x81` (`CP-REG-RMW #1 idx=081 and=FFFFFFFF or=80010000` at `10:11:28.346`, already tagged `PTR?` by our own `CP-DRAW-REGS #1 [13/54] r0081=80010000`). `grep` for `0x80010000` in `src/` returns **nothing**, so we do not synthesise it: the guest put it there.
- Consistent-with (not proof): the `P10-GATE` population F-136 measured is also small integers (`0xC0`, `1`, `0x80`, `0x1FF`), so "an index/flag stands where this code wants an address" is a pattern in more than one place at this frontier, not a one-off.
- Not claimed: which stage should have written a real address into `r31`/register `0x81`, and whether it is the same stage that leaves the `skinningData` group unpopulated. That is the next measurement.

### F-138 — **Where those two non-addresses come from: they are pokes in the AUTO draw's own CP register batch, so the missing piece is the register decode, not a corrupted resource.**

`build/w147.log` `CP-DRAW-REGS #1` prints all 54 pokes of draw #1 (10:11:28.347); the two values F-137 needed are in it verbatim:

- `[09/54] r01DC=00020037` — bit-identical to the `PlaceTexture` fatal's descriptor (`r5=0x00020037`, which `sub_82185190`'s entry instruction `mr r5,r3` proves is its `r3` argument). So the renderer's "resource descriptor" pointer **is CP register 0x1DC's value**.
- `[13/54] r0081=80010000 PTR?` — bit-identical to the fixup census's `obj=80010000`, and to the `CP: MMIO write reg=0081 value=80010000` one minute later. Our census already tags it `PTR?`, and `grep 0x80010000 src/` is empty, so it is guest-authored.
- Context in the same batch: `[08/54] r01DD=071D8380` is the 28-bit-truncated form of `0xC71D8380`, which lies in the CP scratch/writeback region the same logs name (`sc=C71D8280`, `wb@C71D82BC`), and `[04/54] r0A02=C0100000 PTR?` / `[06/54] r0A04=C0000000 PTR?` / `[10/54] r05C8=00020000` (three times). So the batch mixes truncated GPU addresses with small index-shaped values, and the path that dies picks an index-shaped one and dereferences it.
- What is NOT yet claimed: that any specific register is "the" texture/vertex base. Naming registers 0x1DC/0x1DD/0x081 (which PM4 op wrote them, and whether the guest expects a base or a `base + index*stride` computation) is the next step, and the data for it is already captured offline: `PKT-CAP #0005 dev=40002080 f=2 a=32 win=C6258340 n=131072` printed the batch's raw dwords.
- Why this is the plan's B4 item and not a new one: B4's wording is "real float-constant capture from the GuestDevice/register state (**UR-style dev+offset decode**, `grc_fvf` already live)". This is exactly that decode being absent: the register file answers with raw pokes, and the consumer treats one of them as an address.

### F-139 — **B4's premise is now measured rather than assumed: this boot emits no shader-constant op and no indexed-draw op at all, so "capture the real constants" has nothing to capture until the renderer-side gates in F-136/F-137 fall.**

Counted over the whole of `build/w147.log` (the post-fix frontier soak), from our own `PKT-CAP summary` lines -- 15 captured packets, and every field is uniform:

- `set_const=0` in 15/15, `load_alu=0` in 15/15, `draw_indx=0` in 15/15, `draw_indx2=0` in 15/15.
- Same in the committed baseline `w138` (`DRAW_INDEXED 0`), so this is not a regression from F-135 -- it is the state that has been there all along, now separated from the 4 GB storm that used to hide it.
- What the 15 packets *do* carry: `desc`/`dw`/`descBatch`/`indirect`/`rawEnv`/`t0` counts (e.g. `desc=15 dw=904 descBatch=4 indirect=8 rawEnv=3 t0=435`), i.e. the guest submits register batches and indirect buffers (the AUTO draw F-116 census named) but never a `SET_CONSTANT`/indexed draw.
- Consequence for the plan, stated plainly: B4's gate ("first soak with `DRAW_INDEXED >= 1` whose PSO was built from a non-zero constant bank") cannot be met by working on the capture side (`d3d12_backend.cpp:1460`) at all -- the zero-filled bank is zero because the guest never wrote one. The blocking work is upstream of it: the `grmShaderGroupVar` content wall (F-136) and the resource-pointer/register-decode gap (F-137, F-138).

### F-140 — **The rebase map is populated and still cannot answer a single lookup at this frontier: 17 regions, all in the `0x50000000-0x70000000` PSTREAM class, and `P10-MAP` matches 0 of the ~4,030 delta requests -- because what the renderer passes is not in that address class at all.**

- The map is filled at exactly one place (`src/gpu_device.cpp:8377-8397`), seeded from the Job-2 `REQDUMP` whose `d[0] & 0xFFFF == 0x8004`, filtered by `MclaIsPstreamVirtual(p)` = `0x50000000 <= p < 0x70000000` (`:3585-3588`). `build/w147.log` shows it did run: `W25-J2-EARLY-DIST reqdump#2 nmap=17` (and `REQDUMP` with that tag appears exactly once, so the map is seeded once and never re-seeded).
- Yet `P10-MAP` (the hit branch of `sub_8217D890`'s host resolver) prints **0** lines in the same soak, while `P10-GATE` prints 4,030. The ids in that population are `0xC0`, `01`, `0x80`, `0x1FF`, `0x82`, `0x40`, plus F-137's `0x00020037` and F-138's `0x80010000` -- every one of them below `0x50000000`, i.e. structurally outside the only class the map can hold.
- And the producer is now pinned to the guest's packet builder: `0x80010000` reaches register `0x81` as a **packet immediate**, not as a translated value. `CpExecRegRmw` (`src/gpu_cp.cpp:~2700`, the PM4 REG_RMW executor) decodes `info=0x00000081` with bit31=0 and bit30=0, meaning "AND with the immediate `andMask`, OR with the immediate `orMask`" -- and `w147` prints exactly `idx=081 and=FFFFFFFF or=80010000`. Nothing in the host computed or fetched that number; the packet carried it. So "who writes a real address into 0x81" is a guest-side question (which game structure the packet builder read), and no host register-write path can be blamed for it.
- Also measured, and it removes a tempting wrong inference: the fixup `sub_82184458` does *not* even try to slide this object. Its two slide sites are both conditional (`lwz r4,24(r31); cmpli r4,0; beq-skip` and the same at `+28`), and `P5-84458-CENSUS` reads `+24=00000000 +28=00000000` -- so no delta was requested for the object at `0x80010000`. **The object pointer itself, not a field inside it, is the unusable value.**
- Therefore the open question is narrowed to one: which step normally writes a real address into CP register `0x81` (and `0x1DC`) before this consumer reads them. It is not `XAllocMem` (0 fires in `w143`), not `MmAllocatePhysicalMemoryEx` (0 `FAILED` lines in four soaks), and not the rebase map (0 matches here). Next step is to read the PM4 op that carried `and=FFFFFFFF or=80010000` (its batch is captured: `PKT-CAP #0005 ... win=C6258340`), because that names the producer inside the guest rather than in our host.

### F-141 — **The value watch names who stores the two renderer-breaking values, and it also corrects F-137: `0x00020037` is not an index in a register, it is a `0x20000 | 0x37` composite that the guest's own draw path reads out of the CP scratch area, while every real draw-state register in the same batch is ZERO.**

Census: `RegisterGuestWatchValue(0x80010000)` + `(0x00020037)` (`src/boot_host.cpp:1368-1377`, using the session-27 value watch) reported by `RSC-REF-STORE` in `src/gpu_cp.cpp` (`PageWatchOnWrite`, with its own counter because the generic `PAGEWATCH W` report is capped at 16 shared hits). Reproduced identically in `build/w148.log` and `build/w149.log` (same tree, six hits, same addresses, same `lr`s):

- `@ C61D82A8 = 00020037  lr=82411220` (`sub_82411218`, the CP ring-drain path) - twice.
- `@ C61D82D0 = 80010000  lr=824304C8` (`sub_824304C0`) and `@ C71DE998 = 80010000` (same `lr`) - the two stores of the value F-138 found in register `0x81`.
- `@ 00412454 = 80010000  lr=821BC998 sp=006E0FC0` and `@ 00412480 = 80010000` (stride `0x2C`) - `sub_821BC910`, run by the thread our `INLINE-EXEC` census shows at `sub_821BC140 #N a0=82849B2C ... r1=006E0FC0`.

What that changes:

1. **Correction to F-137's wording.** I called `0x00020037` "a 17-bit integer, not an address". Two things are now measured instead: (a) the guest *does* live in the low address class - a worker thread runs with `r1=0x006E0FC0` and stores to `0x00412454`/`0x00412480`, and `0x00000000-0x3FFFFFFF` is a real heap class in the reference design (`.research/xenia/src/xenia/memory.cc:42`, "virtual 4k pages"); (b) the value is a **composite**, `0x20000 | 0x37`, and `r05C8=00020000` (three times in the same batch) is the `0x20000` half. So "index mistaken for a pointer" is not established; what IS established is that the consumer `sub_82185190` reads `[desc+12]` of something that is not an object.
2. **Our own pointer validators have no class for that range.** `MclaPtrIsKnownPhys(p)` is `p >= 0x80000000` (`src/gpu_device.cpp:3683-3687`) and the rebase map's class is `0x50000000-0x70000000` (`:3684` `MclaIsPstreamVirtual`), so `MclaPtrIsGateBad(0x00020037)` returns **true** (`:3692-3705`) - a legitimate low-class pointer is indistinguishable, in our code, from a wild one. (Whether any *specific* mis-gate causes a wrong outcome is not claimed; `0x20037` appears in `P10-GATE`/`P5-LOOKUP` **0** times, so the delta path is not where this value is being mis-handled.)
3. **The draw state is empty, which is the B4-relevant fact.** `CP-DRAW-STATE #1..#28 initiator=00010081 writes=54 r08B=00000000 r08C=00000000 r0DD=00000000 r0D2=00000000 r0A2=00000000 r1DC=00020037 r1DD=071D8380`: every register our own draw census names is zero in all 28 batches, and `r1DD=071D8380` is the 28-bit form of the CP scratch/writeback address `0xC71D8380` that the same logs print as `sc=`/`wb=`. Combined with F-139 (`set_const=0`, `draw_indx=0` in 15/15 packets), the AUTO "draw" is a register-batch the guest emits without any 3D object bound - so B4's non-zero constant bank cannot exist until something binds them.
4. **Run-to-run variance, measured rather than assumed**: across `w138/w143/w144/w145/w146` the counts of `Bad resource type`/`grmShaderGroupVar`/`Fatal error`/`FATAL-SOFT` are `0/0/0/0` (LISTLINE 167), `w147` is `2/2/10/18` (LISTLINE 171), and `w148`+`w149` (same tree, both controls) are `0/2/1/1` (LISTLINE 171). So the `skinningData` gate is stable and caused by the F-135 advance, while the `Bad resource type` fatal and the 8-hit `FATAL-SOFT-RESOURCE-PARK` retry storm in `w147` are **not reproduced** - they were a one-run artifact, and the census did not cause the change. The value watch is kept (frontier-neutral across two controls, and its `RSC-REF-STORE` output is the only attribution we have for these two values).

### F-142 — **Correction, on my own claim: F-136 overstated its control. The shader-group variable lookup is by 32-bit HASH (`cmplw`), not by string, so the plaintext absence of `skinningData` in the resident containers does NOT prove the variable is absent from them. The content-wall verdict is withdrawn to "unproven", and my attempt to reproduce the hash offline failed its own positive control.**

What the code actually does (read from `generated/`, then raw bytes):

- `sub_8218A568(entry=r3, wantedName=r4)`: `mr r3,r4` then `bl 0x821c9790` → **the name is converted to a value**, and the loop at `0x8218A598` walks `r9 = lhz [entry+12]` records of 32 bytes starting at `[entry+8]+12`, comparing with `cmplw cr6, r8, r3` on `[r11+4]` and `[r11+0]` — integer compares, not byte compares. So variables are matched by hash.
- `sub_821C9790(s, seed)`: folds `'A'-'Z'` by `+32`, maps `''`(92) to `'/'`(47), and accumulates with the `rlwinm(r,10,0,21)` / `rlwinm(r,26,6,31)` / `xor` chain finalized by `rlwinm(r,3,0,28)` then `rlwinm(r,15,0,16)` (`0x821C97B8`-`0x821C9848`).

The failed control, recorded because it is the interesting part:

- I reimplemented that routine from the disassembly and searched all 10,354,688 bytes of `mcla_pe.bin` for its output. For `skinningData` it yields `0x4DD5D186`, which occurs 0 times (either byte order) — but **the same test on 400 plaintext names taken from inside the container span itself also produced 0 hits**, so the implementation (or the seed/termination semantics) is wrong and the `skinningData` result is meaningless. A test that cannot find names known to be present finds nothing.
- Therefore F-136's bullet "the control is now proved by the code, not just by the statistics" is **false as written** and F-136's "positive control" only supported the weaker claim that container *name tables are plaintext* — which is still true and still useful (it is what makes the strings searchable at all), but it does not settle where `skinningData` is defined. The gate's status is: reached, named, and **not** shown to be a content wall.
- What settles it instead is the variable count of the group the guest searches: `sub_82193AF8` reads `nvars = lhz [group+12]` and `nvars == 0` jumps straight to the fatal (`ppc_recomp.10.cpp:17765-17766`). An empty group is our serve/parse; a non-empty group whose names differ is a content/identity question. That is what `SHGRP-VARS` was built to print.

The instrument and its first result:

- `PPC_FUNC(sub_82193AF8)` added at `src/gpu_device.cpp:12360`-ff (rule 4 checked first: `addr_owners --check 0x82193AF8` → only `ppc_func_mapping.cpp:2764`, no owner). Read-only; calls through to `__imp__sub_82193AF8`.
- **`build/w150.log`: the marker printed 0 times while the fatal inside that same function printed twice.** The only filter was `group && group != 0xCDCDCDCDu`, so either the hook is not on the path that runs, or every call carries a null/poison group — and the second possibility is itself the answer F-136 needs. The filter was removed (log unconditionally, including `r3 == 0`) and `build/w151.log` is the discriminating run: 0 lines again ⇒ the hook is not on the executed path (revert it, per F-125); lines with `nvars=0` ⇒ empty group, i.e. our side; lines with `nvars>0` ⇒ the group has variables and the wanted name genuinely is not among them.

### F-143: the `skinningData` group is `[object+8]`, not the allocation — and the P10-PRE short-circuit is firing 59,505 times in the runs that reach this fatal

**Claim.** The `Required grmShaderGroupVar '%s' not found.` fatal that ends w147-w151 is raised
because the entity-type registry's parent lookup for `"entity.type"` returns nothing, *not* because
of a failed allocation and *not* because a container is missing a `skinningData` entry. The group
passed to `sub_82193AF8` is a member field that the guest's own constructor deliberately initialises
to zero, so `group=00000000` is the value the ctor left behind.

**Evidence chain (all rule-3 raw-byte / `generated/**` reads, not IDA).**

1. `build/w151.log` — the first and only firing of the now-unconditional census:
   `SHGRP-VARS #1 group=00000000 vt=00000000 arr=00000000 nvars=0 req=1 want='skinningData'
   e0=00000000/'' e1=00000000/'' lr=82379D04`, immediately followed by
   `Fatal error dispatcher invoked` with `fatal-dispatch regs: lr=0x82193BA0 ... r4=0x8204A408`
   and `fatal aux r4: 'skinningData'`. `nvars=0` is not a read of a real group — `group` is 0, so
   every `ReadU32BE(group+n)` fails and the fields stay zeroed.
2. `sub_82379C68` (`generated/ppc_xenon/ppc_recomp.58.cpp:3914`-ff) is the *entity-type
   constructor*, and the value it hands `sub_82193AF8` is **not** the object it allocated:
   - `sub_821CA540(r3=0x827D7770, r4=0x8204A424)` — intern the name being registered.
   - `li r3,128; bl 0x82130528` → `cmplwi cr6,r3,0; beq → li r3,0` (the branch that F-142's
     successor reading (this session, before the raw-body read below) turned into "the
     128-byte alloc failed" - that hypothesis is refuted by points 3 and 4 and is NOT a
     finding).
   - `stw r3,-8108(r11)` → `[0x8288E054] = object`; then the **virtual** `lwz r11,0(r3) /
     lwz r9,20(r11) / bctrl` = `0x826113A8(this=object, r4=0x8204A418, r5=0, r6=1)` — and its
     return value is **discarded** (`mr r3,r30; bl sub_821C9A90` follows).
   - `lwz r11,0(r31)` with r31=`0x8288E054` → `lwz r3,8(r11)` → `sub_82193AF8([object+8], ...)`.
     So the printed `group` is `[object+8]`.
3. The constructor `sub_82611298` (`ppc_recomp.123.cpp:14340`-ff) writes that field itself:
   `li r11,0 / stw r11,8(r31)` and `stw r11,12(r31)`, plus `stw r9,0(r31)` with
   `r9 = 0x82089554` (vtable). **`[object+8] == 0` is the constructed state**, so no allocation
   failure is needed to explain w151.
4. The allocation did *not* fail: at `loc_82379CB0` the instruction right after the store is
   `lwz r11,0(r3)`, which with `r3 == 0` reads guest `0x00000000` — the deliberate `PAGE_NOACCESS`
   null guard (`src/kernel/memory.cpp:316`-ff, the same page F-122's 50 AVs came from) — and w151
   reports `C0000005 0`. So the ctor ran, the object is live, and `sub_826113A8` was entered.
5. `sub_826113A8` (`generated/ppc_xenon/ppc_recomp.123.cpp:14515`-ff) has exactly two exits:
   - `sub_821CA6A8(r3=0x827D7770, r4="entity.type", r5=0x8200CC1C, r6=0, r7=1)` → if that returns 0,
     `loc_8261143C: li r3,0; return` — **without touching `[object+8]`**;
   - otherwise it builds a stack temp (`sub_821D1CD0(sp+80)`, `sub_821CF7B8(sp+80, name, record)`)
     and tail-calls the other virtual `[[object]+16] = 0x82611018(object, &temp, r5, r6)`.
   `sub_821CA6A8` (`ppc_recomp.16.cpp:14210`) is a scan: `count = [manager+3076]`, and for each
   index it calls `sub_821CA2F8(manager, buf, 256, name, typeName, i, ...)` then
   `sub_821BDF20(buf, required)`. **An empty or unpopulated registry yields 0 with no other
   observable difference** — which is precisely the F-111/F-112 shape one boot stage further on.
6. Strings read straight from `build/cache/mcla_pe.bin` (identity map, VA-0x82000000):
   `0x8204A3FC = "effectFade"`, `0x8204A408 = "skinningData"`, `0x8204A418 = "entity.type"`,
   `0x8204A424 = "vehicle/shared_utility/sst_trail"`, `0x8200CC1C = "type"` (in a table
   `"type","name","template","PostSave","PreLoad",…`). Vtables containing the slot
   `0x826113A8`: `0x82054928`, `0x82089568`, `0x8211e778` (raw word scan). So this fatal is
   *type registration for `vehicle/shared_utility/sst_trail`*, and `sub_82193AF8`'s
   "grmShaderGroupVar" wording describes the parent type's variable group.

**Measurement hazard this pass uncovered (F-123/F-054 class).** `P10-PRE`
(`src/task_dispatch_trace.cpp:780`-ff) fires **59,505 times in w150/w151** (5,812 in w147, 13 in
w148/w149), is 39 % of w151's lines per `soak_census` LOG QUALITY, and every firing is a
**short-circuit**, not a census: `(oldAddr & 0xFF) == 0xCD || oldAddr == 0xFFFFFFFF` ⇒
`ctx.r3 = 0; return;` — the guest's relocation-delta provider `sub_8217D890` never runs. The logged
arguments are `id=CDCDCDCD group=CDCBA900 table=CA0F9F00 lr=821D2AD0`: a poison *group* pointer
being used as a table handle 59k times. Any frontier claim from a run in this mode has to state the
`P10-PRE` count next to it.

**Control, not coincidence.** The fatal is the stable frontier and is not produced by the new hook:
w148 and w149 (binary without the census) both print
`fatal message: 'Required grmShaderGroupVar '%s' not found.'`, and all five soaks w147-w151 are the
same mode (`RD-SUBMIT 24`, `LISTLINE 171`, `C0000005 0`, `DRAW_INDEXED 0`).

**Instrument for the verdict.** `PPC_FUNC(sub_826113A8)` census (`TYPINIT` / `TYPINIT-RET`,
`src/gpu_device.cpp:12476`-ff): read-only, cap 24, prints `self`, its vtable, `[self+8]`,
`[self+12]`, the requested parent name as ASCII, `r5`/`r6`, `[0x827D7770+3072]`,
`[0x827D7770+3076]` (the registry's own count), `[0x8288E054]` and the return value with
`[self+8]` re-read after the call. Rule 4 checked first: `addr_owners --check 0x826113A8` →
only `ppc_func_mapping.cpp:31569`, no owner.

**Discrimination (w152).** `TYPINIT-RET ... r3=00000000` with `+8` still 0 ⇒ the parent-type lookup
failed: the blocker is *upstream* (whoever must register `"entity.type"`), and the fix target is the
registry, not the shader code. `r3 != 0` with `+8` still 0 ⇒ the lookup succeeded and the realize
`sub_82611018` ran without publishing the group ⇒ read `sub_82611018`. `cnt=0` on any line is the
registry-empty case stated directly.

### F-144: `0x827D7770` is the resource *path* manager, not a type registry - `entity` and `entity.type` are **files** the guest composes and opens, and the composing loop has exactly **one** candidate mount

*Corrects F-143's framing:* F-143 called `sub_821CA540`/`sub_821CA6A8` a "type
registry" and its scan bound a "count of registered types". The strings settle it
the other way - see point 2. F-143's structural findings (points 2-5: the group is
`[object+8]`, the ctor zeroes it, `sub_826113A8` is the only writer, the alloc did
not fail) all stand.

**w152 measurement - `TYPINIT`/`TYPINIT-RET` (8 lines, cap 24, so 4 entries total):**

```
TYPINIT #1 self=CE719680 vt=82089554 +8=00000000 +12=00000000 name='entity'      r5=00000000 r6=00000001 mgr=[00000001] cnt=1 obj@[8288E054]=00000000 lr=822E72F0
TYPINIT-RET #1 self=CE719680 -> r3=00000000 +8=00000000
TYPINIT #2 self=CE721780 vt=82089554 ... name='entity' ... cnt=1 obj@[8288E054]=00000000 lr=822E7344
TYPINIT-RET #2 self=CE721780 -> r3=00000000 +8=00000000
TYPINIT #3 self=CE729880 vt=82089554 ... name='entity' ... cnt=1 obj@[8288E054]=00000000 lr=822E7398
TYPINIT-RET #3 self=CE729880 -> r3=00000000 +8=00000000
TYPINIT #4 self=D1163D00 vt=82089554 ... name='entity.type' ... cnt=1 obj@[8288E054]=D1163D00 lr=82379CDC
TYPINIT-RET #4 self=D1163D00 -> r3=00000000 +8=00000000
```

#4 is F-143's case verbatim: the census object `D1163D00` **is** `[0x8288E054]`
(so the allocation succeeded, as F-143 point 4 argued), `+8` entered as the ctor's
zero and left as zero, and the function returned 0. Three earlier callers
(`sub_822E70D8`, `lr=822E72F0/7344/7398`) failed the same way on `'entity'`. The
manager's scan bound (`[0x827D7770+3076]`, printed as `cnt`) is **1** on every line.

**1. What the manager really is.** The pre-existing `LogBisect` hook
(`src/gpu_device.cpp:9756`-ff, `MCLA_BISECT_HOOK(sub_821CA540, "3-821CA540
name-insert")`) already recorded the inserts; w152's eight lines all carry
`r3=827D7770` and these `r4` name pointers, decoded from
`build/cache/mcla_pe.bin` at `VA-0x82000000`:

| `#` | `r4` | string | `lr` of the inserter |
|---|---|---|---|
| 1,2 | `0x8201BB2C` | `$/resources/ui` | 821FE4F4, 821FE5E0 |
| 3,4 | `0x820CA5FC` | `$/resources/ui/` | 8272019C, 82720720 |
| 5 | `0x82041D94` | `$/textures/global/cars` | 821822A4 |
| 6 | `0x8200A060` | `globaltex` | 82182300 |
| 7 | `0x827D5ED8` | `$/tune/shaders/lib` | **82304820** |
| 8 | `0x8201F30C` | `ui` | 82187840 |

Path prefixes, not entity types. `lr=0x82304820` is inside `sub_823047D8` - the
same function whose `+0x374` (`0x82304B4C`) is the **only** caller of
`sub_82379C68` (F-143's `sst_trail` ctor). So the mount insert and the failing
lookup are two steps of one sequence in one function.

**2. The lookup composes and OPENS a file.** `sub_821CA6A8`'s scan loop
(`generated/ppc_xenon/ppc_recomp.16.cpp:14210`-ff) is
`sub_821CA2F8(mgr, sp+80, 256, name, typeName, i)` then
`bl 0x821bdf20` with **`ctx.lr = 0x821CA708`**, and `sub_821BDF20` is the
file-resolve helper we already census (`src/gpu_device.cpp:12008`-ff, rule-4
owner): GETDEV (`sub_821CB488`) then `[[dev]+4](dev, name, flags)` = an open.
`'entity.type'` is therefore a file name, and `'type'` (the `r5` argument, string
at `0x8200CC1C` in a table `"type","name","template","PostSave","PreLoad",...`) is
the resource class passed alongside it.

**3. The guest agrees.** Raw strings: `0x820CC164` = `'%s/entity.type'` and
`0x820CC178` = `'Expecting fragment array to be sized optimally.  Count: %d,
Capacity: %d.  One of the props is probably missing an entity.type file.'` - a
missing `entity.type` **file** is a failure mode the prototype itself names.

**4. The file layer is not broken in general.** w152's existing `BDF20` census
prints 553 opens, and they succeed against real archive members:
`a:/archive/shaders/cars/AmbientBlackMatte/dcl/AmbientBlackMatte/dcl/AmbientBlackMatte.dcl`
(hundreds of `cars/*` and `characters/*` `.dcl`s), `a:/archive/resources/ui/garage/garage.xsf`,
`credits.xsf`, `legals.xsf`, `policecam.xsf`, `raceeditor.xsf`, `meshtextures.xtd`.
So this is one lookup path failing, not "the archive cannot be read".

**5. Still open, and the next measurement.** Either (a) the scan bound of 1 is
correct and the composed `entity.type` path genuinely is not in what we mount
(consistent with the "retail content only: `xarchive_cache.rpf` + audio/music"
constraint - `$/tune/...` and `entity.type` files may live in a table/script
archive we never mount), or (b) the ≥8 prefix inserts do not feed the array the
loop indexes, so only one candidate is ever composed. `PATHMGR-OPEN`
(`src/gpu_device.cpp:12037`-ff, inside the existing BDF20 census, so rule 4 is
already satisfied) prints the composed path and the guest's open result for every
open whose caller is `0x821CA708` - which separates (a) from (b) in one line.

**Frontier check (F-123 mode rule).** w152 vs w151/w148: same mode
(`RD-SUBMIT 24`, `LISTLINE 171`), `C0000005 0`, `DRAW_INDEXED 0`,
`Fatal error 1` / `FATAL-SOFT 1` - w151's 2/2 belongs to the `P10-PRE` 59,505 mode
(w152: 495), whose second fatal is `Bad resource type %d in
grcTextureFactoryXenon::PlaceTexture`. The `SHGRP-VARS` + `TYPINIT` censuses moved
no frontier marker.

### F-145: `a:/archive/vehicle/shared_utility/sst_trail/entity.type` **opens successfully** - so the blocker is one step later, inside the realize `sub_82611018`, and not the path manager F-144 suspected

**w154 (`PATHMGR-OPEN`, cap 60 + unconditional for any path containing `entity`/`.type`).**
Four candidate paths are composed for the `entity.type` requests, all from
`lr=821CA708` (inside `sub_821CA6A8`'s per-mount loop), and all four come back with a
non-zero return:

```
#384 a:/archive/vehicle/shared_utility/ao_shadow/entity.type  ret=0x82864048
#385 a:/archive/vehicle/shared_utility/ao_sphere/entity.type  ret=0x82864048
#386 a:/archive/vehicle/shared_utility/ao_cone/entity.type    ret=0x82864048
#406 a:/archive/vehicle/shared_utility/sst_trail/entity.type  ret=0x82864048
```

`0x82864048` is a guest `.data` address, and it is the *same* value `sub_821BDF20`
returned for the files we know load: `a:/archive/textures/global/cars/globaltex.list`
and `a:/archive/shaders/ui/preload.list` (w153 #1, #20) - the two whose contents
produce `LISTLINE` lines. The other observed value is `0x82864068`, which the short-form
`.dcl` candidates return (w153 #22/#24/..., e.g. `a:/archive/shaders/ui/dcl/AlphaModulate.dcl`),
while the long-form candidate for the same file (`.../AlphaModulate/dcl/AlphaModulate/dcl/AlphaModulate.dcl`)
returns `0`. So `ret` is a static stream-object pointer, `0` = that candidate missed, and
**`ret=0` on the long form is not an error** - it is the two-shape fallback pair. Reading
one shape in isolation would have produced the wrong verdict, which is why §9 now says so.

**The whole failing sequence is one millisecond wide** (w154, 11:58:52.147-148), and
nothing between the open and the return carries a census line:

```
TYPINIT #4  self=D1163D00 vt=82089554 +8=00000000 +12=00000000 name='entity.type' cnt=1 obj@[8288E054]=D1163D00 lr=82379CDC
PATHMGR-OPEN #406 path='a:/archive/vehicle/shared_utility/sst_trail/entity.type' ret=-2105144256 lr=821CA708
TYPINIT-RET #4 self=D1163D00 -> r3=00000000 +8=00000000
SHGRP-VARS #1 group=00000000 ... want='skinningData' lr=82379D04
Fatal error dispatcher invoked - terminating game   (FATAL-SOFT masks it)
```

So F-144's fork resolves *against* both of its branches: the path manager is not
mount-starved (its one candidate composed a correct `a:/archive/...` path) and the file
is not missing (the open returned a stream). `sub_821CA6A8` returned that stream,
`sub_826113A8` therefore did **not** take its `loc_8261143C: li r3,0` early exit, and
the zero return came out of the realize `sub_82611018` (`ppc_recomp.123.cpp:13892`-ff),
whose body is:

1. `sub_821CFE80(r3 = temp, r4 = 0x82089564, r5 = 0)` → **if `(r3 & 0xFF) == 0` jump to
   the `return 0` tail** (this is the only check that can fail with no I/O at all);
2. `[[temp]+8](temp, sp+80, 128)` - a 128-byte read;
3. `[[temp]+20](temp, 1)` must return **103**, else `sub_82130000(0x82089538,
   [temp+4])` prints the guest's own `...version (%i)` and returns 0;
4. only on 103: `[[object]+24](object, temp, r5, r6)` = `sub_82611448`, which is what
   can publish `[object+8]`.

**Next measurement (w155):** an `lr`-gated census on `sub_821CFE80` (rule 4:
`addr_owners --check 0x821CFE80` → only `ppc_func_mapping.cpp:4506`, no owner) printing
`r3`/`r4`/`r5` on entry and `r3` after, restricted to `lr == 0x82611048` (the call site
inside `sub_82611018`). If that fires with `(r3 & 0xFF) == 0`, the realize dies on its
type/dynamic_cast check over the object `sub_821CF7B8` built from our stream - not on
file content. If it fires non-zero and no 128-byte read follows, the failure moved to
step 2/3 and the `version (%i)` print is the thing to chase.

**Frontier (F-123 mode rule).** w154 vs w153/w152: `RD-SUBMIT 24`, `LISTLINE 171`,
`C0000005 0`, `DRAW_INDEXED 0`, `Fatal error 1`, `FATAL-SOFT 1`, `TYPINIT 8`,
`SHGRP-VARS 1` - the `PATHMGR-OPEN` census (64 lines) changed nothing.

### F-146: the realize dies on `sub_821CFE80(reader, "Version:", 0)` - a *token read* from the opened `entity.type` - and that function's own body shows what it asks for: `[reader.vt+8](reader, buf, 512)`, then a string compare against the key

**w155 `REALIZE-CAST` (lr-gated census on `sub_821CFE80`, `src/gpu_device.cpp:12530`-ff), 4
firings - exactly the 4 `TYPINIT` calls, and nothing else:**

```
obj=8EFFF620 vt=8201302C +4=8203E960 ti=82089544 flag=0 -> r3=00000000 (byte=0)   x3   [+4 = 'entity']
obj=8EFFF6F0 vt=8201302C +4=8204A418 ti=82089544 flag=0 -> r3=00000000 (byte=0)        [+4 = 'entity.type']
```

`+4` is the name the caller (`sub_821CF7B8`) stored into the reader, and it matches the
`TYPINIT` request on the same line, so this is the same four objects. `ti` = the key:
`0x82089544` decodes to `Version:` (raw bytes at `0x82089530`:
``'ted version (%i)' + 4 NULs + 'Version:' + 4 NULs + <vtable 0x82089554>` - the `...ted version (%i)`
string is the *neighbour*, which is why F-144 mis-scaled it; `0x82090000-27324 =
0x82089544`, not `...564`). **Every one of them returns 0.**

**What that call is** (`generated/ppc_xenon/ppc_recomp.17.cpp:12904`-ff):

```
mr r31,r3 (reader) ; mr r30,r4 (key) ; mr r28,r5
stb r10(=0),80(r1)              ; zero the 1-byte out-flag
lwz r11,0(r31) ; lwz r29,16(r31) ; lwz r9,8(r11) ; bctrl  -> [reader.vt+8](reader, sp+80, 512)
mr r5,r3 ; cmpwi cr6,r5,0 ; beq -> loc_821CFF24         ; nothing read -> fail
<byte-by-byte compare of sp+80 against r30 ("Version:")>
```

So `sub_821CFE80` = "pull the next <=512-byte token out of the reader and test whether it is
`Version:`", and the realize's first gate is literally **the `entity.type` file must start with
a `Version:` token**. F-145's step-1 hypothesis is confirmed and the version/103 check (step 3)
was never reached: `[object+8]` is therefore never published, `sub_82193AF8` gets group 0, and
`Required grmShaderGroupVar 'skinningData' not found.` is fatal #1 - the same failure for
`ao_shadow`, `ao_sphere`, `ao_cone` (all three `'entity'` requests, `+4=8203E960`).

Two readings remain, and they need different fixes: (a) we serve bytes for
`vehicle/shared_utility/*/entity.type` that have no `Version:` token (wrong member, undecrypted,
or truncated - a serve defect); (b) the read at `[reader.vt+8]` returns 0 because the *stream*
our open handed back has nothing positionable in it (the F-127/F-128 binding defect class).
`tools/rpf_offline.py find vehicle/shared_utility/sst_trail/entity.type` cannot answer this
(0 records is EXPECTED against the encrypted on-disk TOC, F-099). The discriminator is the
reader's own state: `reader+16` (what `sub_821CF7B8` stored, presumably the stream/pos) plus the
`[reader.vt+8]` return value, which is the next census.

**Frontier.** w155 = w154 = w153 = w152 mode: `RD-SUBMIT 24`, `LISTLINE 171`, `C0000005 0`,
`DRAW_INDEXED 0`, `Fatal error 1`, `FATAL-SOFT 1`, `TYPINIT 8`, `PATHMGR-OPEN 64`;
`REALIZE-CAST` 4. Read-only census, no marker moved.

### F-147: correction to F-145 - the non-zero `PATHMGR-OPEN` return is one of two *static stream wrappers* (0x82860C40 / 0x82860C68), and no `TOC76`/`XSF-OPEN` line exists for any `entity.type` path in the whole log, so "the file opens" is not established

**What w157 adds** (`REALIZE-CAST` extended to dump the reader object,
`src/gpu_device.cpp:12530`-ff):

```
obj=8EFFF6F0 vt=8201302C name=8204A418 stream=82860C40 +8=1 +20=2 cur=20 cnt=6 key=82089544 flag=0 -> r3=0 (byte=0) buf='Pu.......{...{........vR......o-' hex=50 75 00 00 00 00 04 B0 D0 7B E0 00 | tok='uP.n.'
```
and for the three `entity` requests the same shape with `stream=82860C40`,
`cnt=119/27/43` and a high-entropy `buf` (`47 99 0F A9 6B 74 BE 5E ...`,
`CF 24 85 52 36 ED A5 6B ...`, `4A 67 77 FE 31 37 59 4A ...`).

1. **`stream` = `0x82860C40`** - not a fresh allocation. That address is one of the
   three *static* wrapper objects F-122 named (`0x82860C18`/`0x82860C40`/`0x82860C68`,
   image `.data`, 40-byte stride), and its image contents are all zero at boot.
   `sub_821BDF20`'s return value is therefore "which static wrapper I filled", and
   the census sees exactly two of them across all `PATHMGR-OPEN` lines:
   `0x82860C40` (`ret=-2105144256`) for `.list` and `entity.type`, and
   `0x82860C68` (`ret=-2105144216`) for the short-form `.dcl` candidates. A miss is
   `ret=0`. So F-145's "the open returned the same static stream object the loading
   `.list` files return" is right about the value and wrong about what it proves:
   `.list` files *do* load (`LISTLINE 171`), so this wrapper is not itself proof of a
   successful member read.
2. **No archive activity for the name.** `grep -i entity build/w157.log` returns only
   this session's three markers (`PATHMGR-OPEN`, `TYPINIT`, `REALIZE-CAST`). There is
   **no** `TOC76*`, `XSF-OPEN`, `XSF-HOSTSERVE`, `XSF-POSTOPEN-SERVE` or `AFB76` line for
   any `entity.type` path, while the same minute of the same log carries all five for
   `resources/city/SC/trash.xrn` (`TOC76-XSF #1365`, `XSF-OPEN #1323`, whose own `ret` field is a different convention from
   `PATHMGR-OPEN`'s,
   `XSF-HOSTSERVE ... off=0035A000 size=32768 head=05435352`). The packfile device path
   is instrumented end-to-end and did not fire for this open.
3. The bytes the tokenizer then produced are not text and not a `Version:` keyword,
   and the same wrapper is heavily reused - `BE710-SLOT #971..978 obj=82860C40 h=1
   words=1 served=4` - so "leftover bytes from an earlier read of a different member"
   is at least as good a description of `buf` as "the entity.type body". F-146's
   either/or (ciphertext vs wrong keyword) therefore does not resolve; both branches
   assumed the bytes came from this file, and that assumption is what F-147 withdraws.

**Consequence for the plan.** The blocker chain is now: `grmShaderGroupVar 'skinningData'`
<- `[object+8]` never published <- realize bails on the `Version:` token <- the token comes
out of static wrapper `0x82860C40` <- **whether that wrapper was ever loaded with
`entity.type` bytes is unresolved**. The bounded next datum is F-122's own dead-wrapper
test applied at the moment of this open: `[wrapper+0]` (device), `+4` (handle), `+8` (buf),
`+24/+28/+32` (cur/end/cap for the guest-native shape). Device+handle live and
`end > cur` => a real read happened and the answer is content/decode; device dead =>
the guest got a stale wrapper, which is the F-127/F-128 bind-and-serve defect class
showing up on a new path, and the fix belongs there.

**Also newly visible, from a concurrent session (rule 5, not mine):** `FIXWALK-GATE ...
bucket=... buildCtx=D111B980 lr=825FDC64 bucketGate=1 nodeGate=0 - delta-0 skip`
(`src/task_dispatch_trace.cpp:1048`) fires ~38,800 times per soak and is a
**short-circuit** (it skips the guest's fixup for delta-0 buckets). It is interleaved with
every line of this failing sequence, so B5's "zero FATAL-SOFT masking" criterion now has a
second masking source to account for beyond `FATAL-SOFT` itself.

**Frontier.** w157 = w156 = w155 = w154 mode and counts: `RD-SUBMIT 24`, `LISTLINE 171`,
`C0000005 0`, `DRAW_INDEXED 0`, `Fatal error 1`, `FATAL-SOFT 1`, `TYPINIT 8`,
`PATHMGR-OPEN 64`, `REALIZE-CAST 4`.

### F-148: PROVEN at byte level - the `entity.type` member is served to the guest **verbatim as stored in `xarchive_cache.rpf`**, and the stored bytes are transformed; that is F-129's defect 2 sitting on the critical path to the menu

**The chain, closed in three lines of evidence.**

1. **The read happens and delivers the member's exact size.** w158 `REALIZE-WRAP`
   (new census field, `src/gpu_device.cpp:12541`-ff) reads the wrapper F-147 identified:
   `wrap=82860C40 dev=C60AC080 h=0 buf=82861DF8 cur=0x67|0x2B|0x06 end=0x1E2|0x1E1|0x1E0
   cap=0x1000` - and `0x1E0`, `0x1E1`, `0x1E2` are *member sizes in the archive TOC*
   (point 3). So the wrapper is not stale and not empty; it holds one `entity.type` body.
   (The first `entity` request is `cur=0 end=0 avail=0` - that one call really does see
   nothing, consistent with the tokenizer draining it before this read.)
2. **The guest's own device path is reached, and `DEVCLAIM`'s `r3=0` is NOT a decline.**
   Extending a peer-owned census's print predicate (census-only, `src/gpu_device.cpp:10405`
   -ff, `n <= 96 || path contains "entity" || ".type"`) shows w159 lines #1277-#1325:
   `DEVCLAIM #1324 dev=C60AC080 path='a:/archive/vehicle/shared_utility/sst_trail/entity.type'
   -> r3=00000000 r4=D1163E00 lr=821CCFF0` (twice per path, the two `a:/archive/` devices).
   The hook's own header comment states the caller loop stops on `r4 != -1`, not on `r3` -
   `r4` is the stream object and is non-(-1), so the open proceeds. An earlier reading of
   `r3=0` as "the device declined the file" is wrong and is not what this finding rests on.
3. **The bytes are the stored bytes.** `build/toc_parsed.bin` (a *working* in-guest TOC dump -
   control passes: `find trash.xrn` = 1 record, whose archive offset `0x35A042` the same soak
   prints in `TOC76-XSF #1365`) yields **12 `entity.type` file records**, sizes
   `0x1E5 0x1E2 0x1E1 0x1E0 0x1E9 0x1EC 0x288 0x22B 0x21E 0x225 0x21A 0x1B3`. Reading those
   offsets straight out of `xarchive_cache.rpf`:

   | member off | size | first 16 stored bytes |
   |---|---|---|
   | `0x32C000` | `0x1E5` | `75 50 3b 6f 83 30 10 9e 8d c4 7f 38 b1 07 db 4d` |
   | `0x32C729` | `0x1E2` | `75 50 3b 6f c2 30 10 9e 1d 29 ff e1 94 9d 38 b4` |
   | `0x32E767` | `0x1E1` | `75 50 4b 4f 84 30 10 3e 97 84 ff d0 70 97 16 d4` |
   | `0x35CA43` | `0x1E0` | `75 50 cd 6e 84 20 10 3e 63 b2 ef 40 bc 57 d0 d5` |

   and w157's `REALIZE-CAST` token for the matching calls:
   `tok='uPKO.0.>....p...'` (`75 50 4B 4F 84 30 ... 30 ...`) for the `0x1E1` case and
   `tok='uP.n.'` (`75 50 CD 6E`) for the sst_trail `0x1E0` case - **byte-identical to the
   stored member.** F-145's "opens successfully" survives in a corrected form: the guest
   really does get this file's body; it gets it *untransformed-by-us*.

**So the missing stage, named.** `Version:` is the first token `sub_82611018` requires, the
stored body starts `75 50 ...`, and the `.list` spans are the only members our pipeline
expands (F-105 `MarkMemberExpanded`, F-129 defect 2). This is therefore not a shader-content
question (F-136/F-142), not the path manager (F-144), not an allocation (F-143) and not a
missing file: **the frontier fatal is caused by delivering `entity.type` still in its stored
transform.** F-129 predicted exactly this and its pass condition was "locate the guest's own
archive decode"; it is now on the critical path with a name.

**Keystream fingerprint, reconfirmed on a new family** (the same signature F-129 saw on the
effect bodies): `0x32C000` and `0x32C729` - different members, different offsets - share their
first 4 stored bytes `75 50 3b 6f` and again bytes 5-7 (`83 30 10 9e` vs `c2 30 10 9e`), while
everything from byte 8 diverges; every member starts `75 5x`. A position-independent repeating
prefix cannot come from DEFLATE (which would start `78 9c`/`78 01`/`78 5e`) - it is a stream
cipher keyed per member (or per header block), so `P1 ^ P2 = C1 ^ C2` is available offline and
is the cheapest route to the transform. Note `0x7F000EBA` (`size 0x1B3`) is 16 zero bytes -
either a genuinely-zero member or a hole; do not build on it.

**Offline route, corrected:** `tools/rpf_offline.py find` against `build/toc_decrypted.bin`
returns 0 records even for `trash.xrn` (control fails - that dump is not the record array the
tool's schema assumes), while the **same tool against `build/toc_parsed.bin` is sound**. Always
run the control before citing a `find` negative.

**Frontier.** w159 (with the `DEVCLAIM` predicate extension): `RD-SUBMIT 24`, `LISTLINE 171`,
`C0000005 0`, `DRAW_INDEXED 0`, `TYPINIT 8`, `PATHMGR-OPEN 64`, `REALIZE-CAST 4`,
`REALIZE-WRAP 4`, `DEVCLAIM 104` (= 96 cap + 8 entity paths, by design). `Fatal error 2` /
`FATAL-SOFT 3` - the second is `Resource '%s': %s (ptr=%p)`, i.e. this soak drew a different
post-fatal mode (`P10-PRE 494`, as in w152/w153/w156/w157), not a new regression; the
`skinningData` fatal is still exactly 1.

### F-149: THE FIX - raw-inflating the `entity.type` members lifts the `skinningData` fatal with **nothing masked** (`Fatal error 1->0`, `FATAL-SOFT 1->0`, `SHGRP-VARS 1->0`), and exposes the next blocker: a guest null-deref at `0x821BE568` inside the parse

**Change** (`src/gpu_device.cpp:537`-ff): F-105's expanded-span mechanism is
extended from the six `.list` members to the ten `entity.type` members whose
offset/logical-size pairs came out of the guest's own decrypted TOC dump
(`kTypeMemberSpans`, `kExpandTypeMembersInArchive = true`), marked at the same
place - the first archive I/O (`sub_8244F4C0` n==1 -> `MclaMarkKnownListMembers`).
No host-written word, no gate weakened: the guest is now handed the same bytes its
own inflate would have produced.

**Proof it reaches the guest** (`build/w160.log`, 12:47:05.062, the first
`entity` request):
```
REALIZE-CAST obj=8EFFF620 vt=8201302C name=8203E960 stream=82860C40 +8=1 +20=2 cur=20 cnt=9 key=82089544 flag=0 -> r3=00000001 (byte=1) buf='isreV.....)....' | tok='Version:'
```
The compared token is literally `Version:` and `sub_821CFE80` returns **1** where
w155..w157 returned 0. (`buf` reads `isreV` because the tokeniser stores into
`reader+count` with `count` descending - same reversal F-147 saw as `50 75` vs
`75 50`.) `MEMBER-EXPAND-MARK-TYPE` prints 10 lines; `MEMBER-EXPAND` 47 -> 51.

**Frontier moved, measured against `w159` (same mode: `RD-SUBMIT 24`,
`LISTLINE 171`):**

| marker | w159 | w160 |
|---|---|---|
| `Fatal error` | 1 | **0** |
| `FATAL-SOFT` | 1 | **0** |
| `SHGRP-VARS` (the skinningData raise) | 1 | **0** |
| `TYPINIT` lines | 8 | 1 |
| `REALIZE-CAST` | 4 (all r3=0) | 1 (**r3=1**) |
| `C0000005` | 0 | **1** |
| `VEH-NEUTRAL` | 0 | **1** |
| `PRESENT` / `NATIVE-PRESENT` / `CP-DRAW` / `GETDEV` / `DRAW_INDEXED` | 34 / 4 / 166 / 694 / 0 | unchanged |

`Fatal error 0` + `FATAL-SOFT 0` together for the first time since `w138` means
B5's third criterion (no soft-fatal masking) is met at this instant, and F-136's
"content wall" (withdrawn by F-142) is now definitively dead: the variable the
guest asked for was never the problem - the file describing it was compressed.

**New blocker, named honestly.** The one AV:
```
Vectored exception: code=0xC0000005 addr=0x7ff7722ea05d rva=0x8FA05D Param[1]=0x7E780000
rip owner=guest 0x821BE568 (host+0x31D)  ppc r1=8EFF1800 lr=821BE5F4 r3=0 r4=0 r5=0 r8=82860000 r13=8F200000
probe y=00000000 -> off32=0x7E780000 == Param[1] (base contributed 0)
```
`0x7E780000` is where guest address **0** lands, so the guest itself dereferenced a
null object pointer at `0x821BE568` - inside `sub_821BE250`'s read/copy region, i.e.
in the same buffered-stream code F-122 root-caused. It is VEH-neutralized and the
boot continues (the log runs 22 s past it), but only one of the four entity
registrations is ever entered (`TYPINIT` 8 -> 1 line, no `-RET`), so type
registration stops there. **`C0000005 0` is the invariant this breaks, and it is
the next thing to root-cause** - not paper over: `r3=r4=r5=0` at entry to that
block says the caller passed nothing, so the question is which caller handed a null
to the read of the now-parseable `entity.type` body.

### F-151: the AV F-149 exposed is **our own Open contract** - `sub_821CAFB8` returns a slot *index* where this caller dereferences a stream *object*

`w161` (read-only `SEEK-DEAD` census on `sub_821BE568`, `src/gpu_device.cpp:12660`-ff, one
checked read per call) catches the whole failure in four lines at 13:04:11.351:

```
BE0C8 #179 r3=8EFF1750[6D656D6F] r4=827D838C[82012918] vt+4=821CAFB8 pth='memory:$CE83A580,11487,1:unavailable' r5=1 lr=821BE988
SLOT-RECYCLE #6 idx=1 took buf=CE83A580 size=11487 from exhausted slot (pos>=size)
BE0C8-RET stream=00000001 buf=CE83A580 size=11487
SEEK-DEAD obj=00000001 dev=00000000 h=00000000 cur=0 end=00000000 cap=00000000 seekto=00000000 lr=82191100
```

Chain, all resolved from `build/mcla.map` (same link, F-120) and `generated/**`:
`sub_821864C0+0x71 -> sub_82192448+0x2E8 -> sub_82191040` whose body is
`sub_821CA6A8(mgr,name,'type',0,1)` -> `sub_821BE8D8` (load-whole-file) -> keep the return in
`r31` -> `sub_821BE4F0(r31)` (a resource-type code; 26 = the text/reader branch) -> **else**
`sub_821BE568(r31, 0)` (Seek) -> `loc_821BE5D0: lwz r3,0(r31) / lwz r4,4(r31) /
lwz r11,0(r3) / lwz r10,44(r11) / bctrl` -> **r3 = [stream+0] = 0** -> fault on guest 0.

The "stream" is `1` because `PPC_FUNC(sub_821CAFB8)` (`src/gpu_device.cpp:11946`-ff) - the
memory/embedded device **Open**, vtable `0x82012918+4`, which `sub_821BE0C8` calls - ends with
`ctx.r3.u32 = MakeMemoryStream(kMemDeviceObj, buf, size)` and `MakeMemoryStream`
(`src/gpu_device.cpp:11782`-ff) deliberately **returns the slot index** ("the guest treats an
open handle as a slot index - return the INDEX", the F-132/F-135 fix). So two different guest
callers of the same Open want two different shapes:

* `sub_821BE8D8`'s `vt+56` GetSize path wants a slot index (that is what F-134/F-135 fixed, and
  it is why `LISTLINE` is 171);
* `sub_82191040`/`sub_821BE568` want a stream **object** it can do `[obj+0]`/`[obj+4]` on.

F-122's read hook hides the mismatch for `Read` (`MemoryStreamServeRead` serves from the
wrapper fields when `[obj+0]` is dead); **Seek has no such equivalent**, so the index is
dereferenced. It only fires now because F-149's expansion let `entity.type` parse far enough to
reach this load.

**Fix under test (next soak).** Make the object and the index agree instead of choosing between
them: fill the shadow wrapper at `kMemStreamSlot` in the *guest-native* shape
(`+0 = kMemDeviceObj`, `+4 = slotIdx`, `+8 = buf`, `+24 = cur`, `+28 = end`, `+32 = cap` -
`EnsureMemoryDeviceVtable()` already installs `+44 = sub_821CB2A0` Seek on that vtable) and
return that address from `sub_821CAFB8` **only** on the `sub_821BE0C8` re-open (gate
`lr == 0x821BE988`), leaving every other open on today's index contract. Pass condition, stated
before running it: `SEEK-DEAD` 1 -> 0, `C0000005` 1 -> 0, `TYPINIT` 1 -> more lines with
`TYPINIT-RET r3 != 0`, `LISTLINE 171` and `RD-SUBMIT 24` held, and `Fatal error 0` /
`FATAL-SOFT 0` not bought back by a new fatal. If `LISTLINE` or `BE8D8` regresses, the change is
reverted, not tuned.

**Frontier.** w161 = w160 on every marker (`RD-SUBMIT 24`, `LISTLINE 171`, `Fatal error 0`,
`FATAL-SOFT 0`, `SHGRP-VARS 0`, `DRAW_INDEXED 0`, `C0000005 1`, `VEH-NEUTRAL 1`, `TYPINIT 1`,
`REALIZE-CAST 1`) - the `SEEK-DEAD` census is measurement only.

### F-152: F-151's proposed fix was built, measured **inert**, and reverted - and the measurement relocates the defect: the `memory:$` re-open never enters our Open hook, and the `1` is the guest's own `sub_821BE0C8` return

Implemented exactly as F-151 declared (`sub_821CAFB8`'s `ParseMemoryDollar` branch returns a
guest-native-shaped object at a fresh allocation when `lr == 0x821BE988`), built green, soaked
`build/w162.log`:

```
AFB76-MEM$-OBJ  0 lines        (the new branch never executed)
SEEK-DEAD       obj=00000001   (unchanged)
RD-SUBMIT 24  LISTLINE 171  Fatal error 0  FATAL-SOFT 0  C0000005 1  VEH-NEUTRAL 1  TYPINIT 1  DRAW_INDEXED 0
```

so identical to `w161` everywhere - no progress, no regression. Reverted (the comment stays at the
site; `SEEK-DEAD` stays as the instrument).

**Why it was inert, and that is the datum.** `PPC_FUNC(sub_821CAFB8)` fired **16 times in the whole
soak**, every one with `lr=821BDF5C` (the `sub_821BDF20` INSERT path) and every `path` an
`embedded:/` name - e.g. `AFB8-IN #16 r3=827D838C r4=CE582980 path='embedded:/fxl_final/rmptfx_collision.fxc' lr=821BDF5C`.
Its own print condition includes `path[0] == 'm'`, so a `memory:$...` open through this function
could not have been silent. Therefore **`sub_821BE0C8`'s re-open does not call
`sub_821CAFB8`**: the `vt+4=821CAFB8` on the `BE0C8` census line is that census reading
`[vtable+4]`, not evidence of a call (the same trap F-151 warned about for `DEVCLAIM`'s `r3`).

**And the `1` is the guest's own.** No file in `src/` contains `memory:$` or `:unavailable`
(`grep -rn` over `src/**` = 0 hits), so `memory:$CE71A380,11487,1:unavailable` is composed by the
guest (F-134 already attributed the format to `sub_821CB740`), and `BE0C8-RET stream=1` is the
guest's `sub_821BE0C8` returning the third field of its own path string.

**Corrected blocker statement.** `sub_82191040` does
`sub_821CA6A8` -> `sub_821BE8D8` -> keep r31 -> `sub_821BE4F0(r31)` and branches on the result:
**==26** takes the reader branch (`sub_821CF7B8(sp+656, name, r31)` + `sub_8219F030` +
`sub_821BE610`, returns 1 = success) - the same reader family that `REALIZE-CAST` proved works on
the expanded text; anything **else** falls to `loc_821910EC`, which calls
`sub_821BE568(r31, 0)` (Seek) unless the code is 13. So the AV is one level *up*: the value the
guest re-opened with is not a stream object, and `sub_821BE4F0` does not classify it as the 26
kind. Chasing the Seek's null guard would be do-not #1 territory.

**Next measurement, declared before running.** A read-only census on `sub_821BE4F0` printing the
handle it was given, the code it returns and `lr` (cap 24). Outcomes: returns something other than
26 for a body that F-149 expanded correctly => the classifier reads a header/field our serve does
not fill (and the fill is the fix, discovered from that function); returns 26 everywhere and the
AV belongs to a *different* load => `SEEK-DEAD`'s `lr=82191100` plus `BE0C8`'s path identifies
which resource, and that resource's serve is the gap.

### F-154: `w163` was a STALE-EXE soak (the build had failed and I read its log anyway) - and `w164` measures the object-shaped re-open as a **net loss**, so it is reverted; the fact it revealed is that the memory device owns a SECOND handle table at `0x82861740`

**Process defect, stated plainly.** The `w163` command chained build + soak and I read the
log without checking `BUILD_RC`: it was **1** (`gpu_device.cpp:12398` - `use of undeclared
identifier lr`), so `w163` ran the 13:22 exe, i.e. the *reverted* tree. Its numbers
(`Fatal 0`, `FATAL-SOFT 0`, `C0000005 1`, `SEEK-DEAD 1`, `TYPINIT 1`) are therefore a clean
**reproduction of `w161`** - which is worth having (the post-revert state is deterministic
across two runs) - but it proved nothing about the experiment. This is rule 12 biting again
in the same session; the fix is procedural: read `BUILD_RC` and the exe mtime before the log.

**w164 (the experiment, correctly built: exe 13:33:23, `BUILD_RC=0`).** Returning a
guest-native object from `sub_821BE0C8` (`+0 = kMemDeviceObj`, `+4 = slot index`,
`+8 = buf`, `+24 = 0`, `+28 = +32 = size`), gated to the `memory:$` re-open whose `lr` is
`0x821BE988`:

| marker | w161 (baseline) | w164 |
|---|---|---|
| `BE0C8-OBJ` | - | 167 |
| `SEEK-DEAD` | 1 | **0** |
| `C0000005` | 1 | **0** |
| `Fatal error` / `FATAL-SOFT` | 0 / 0 | 0 / 0 |
| `LISTLINE` | 171 | **167** |
| `TYPINIT` / `REALIZE-CAST` | 1 / 1 | **0 / 0** |
| `RD-SUBMIT` | 24 | 24 |
| `DRAW_INDEXED` | 0 | 0 |

So it removed the fault **and** lost the four embedded-effect loads F-135 bought plus the whole
`entity.type` text progress - the pass condition in F-151 was "LISTLINE 171 and RD-SUBMIT 24
held", so per that pre-declared rule it is reverted (kept as a cited comment at
`src/gpu_device.cpp:12373`-ff).

**Why - and this is the useful part.** A *live* `[obj+0]` sends the guest's own device methods
after the handle, and the memory device indexes **its own** table: `sub_821CB2A0` is
`base = 0x82861740` (from `lis r10,-32122` = `0x82861000`, `addi r10,r10,1856`),
`entry = base + handle*16`, and it **returns -1 when `[entry+0] == 0`** - which is the state for
every body our host-serve path registers, because `GuestSlotTableInsert` writes
`kGuestSlotTable = 0x82860740` (F-132/F-135's table, 16-byte stride, `{buf,size,pos,flag}`).
Two parallel 16-byte tables, one per device, and only the `0x82860740` one is fed by us. The same
`sub_821CB2A0` also *frees* `[entry+0]` when its byte `+12` is non-zero and then stores 0 there,
so it is a Close-shaped routine, not a Seek - the `vt+44` slot my F-153 comment called "Seek" is
`0x82860740`-space's Close for the *memory* device.

**Next step, narrowed by that.** Either (a) register host-served bodies into the memory
device's table as well (write `{buf,size,pos,flag}` at `0x82861740 + idx*16` **and** keep
`flag = 0` so nothing is freed), then the object-shaped return of F-153 should give
`C0000005 0` **with** `LISTLINE 171` and the `Version:` progress; or (b) leave the index contract
and give `sub_821BE568`'s caller an object whose device vtable routes `+44` to a slot the memory
device does own. (a) is a 5-line extension of `GuestSlotTableInsert`'s call site and is the one
to try; it is also the first time F-132's "the guest treats an open handle as a slot index"
finding has to be applied to the *second* table, which is likely why F-134 saw `GetSize` answer
-1 for these handles at all.

**Addendum (13:45, written docs-only because a peer session is mid-experiment right now - their
`texture_import_validator` target in `CMakeLists.txt` plus `build/texval_run.log` at 13:44).** The
F-154 next step was implemented and then **parked uncommitted** to keep the shared tree at the
known-compiling HEAD while they build: the patch is
`docs/f154_staged_be0c8_object.patch` (57 lines, one hunk in `src/gpu_device.cpp`, the
`sub_821BE0C8` `memory:$` branch). It writes `{buf,size,pos=0,flag=0}` at
`0x82861740 + handle*16` and returns the guest-native object, and it carries the pass condition in
its own comment. Apply it with `git apply docs/f154_staged_be0c8_object.patch`, build with
`build_on_e.bat build`, **check `BUILD_RC` and the exe mtime before reading the soak** (F-154's
slip), and soak as `w165`.

### F-155: `CreateDecodedTexture` had **zero producers** in the whole tree, and the decoded 2D texture binds at **t1**, not the `t0` its own log line and header comment claim

- Task:        external asset-import slice (not on the T41.x boot queue); `build/texval_run.log`, `build/texval_star.log`, `build/texval_dxt5.log`
- Type:        FACT
- Class:       F
- Priority:    P2
- Evidence:    `src/d3d12_backend.h:105` ("creates a shader-visible SRV at t0"), `src/d3d12_backend.cpp:834` (log string `"+ SRV t0"`), against `src/d3d12_backend.h:354` (`kTexture2DSlot = 1`), `src/d3d12_backend.cpp:825` (`srvHandle.ptr += kTexture2DSlot * m_srvDescriptorSize`), `src/renderer/shader_translator.cpp:478` (`Texture2D t2D : register(t1);`). Producer census: `grep -rn "CreateDecodedTexture(" src/ tools/` -> decl `d3d12_backend.h:108`, def `d3d12_backend.cpp:695`, and until today **nothing else**; the only call site in the tree is now `tools/validators/texture_import_validator.cpp:379`.

**The consumer half of the Phase 4 texture path was built and never fed.** `BindDecodedTexture()` has
always been wired into the draw (`src/d3d12_backend.cpp:1472`), but no code ever called
`CreateDecodedTexture`, so the SRV table only ever held the null descriptors prefilled at
`:419`-ff. `backend_validator.cpp:546` replicates the resource/barrier/descriptor sequence by hand and
says so in its own comment - "*minus an actual sampling shader (none can be compiled headlessly)*" - so
the sampling half has never been exercised by anything until now.

**The slot is t1.** The new validator's PS declares `Texture2D t2D : register(t1)`
(`tools/validators/shaders/texture_quad_ps.hlsl`) and the GPU readback comes back byte-exact, which is
the empirical form of the same fact the constants give. The `"+ SRV t0"` log string at `:834` and the
header comment at `:105` are therefore wrong text, not wrong behaviour: `BindDecodedTexture` passes the
**heap base** as the descriptor-table start, and the table's range begins at t0, so an offset-1 CPU
descriptor is correctly reached by a shader reading t1. Fix the text, not the code.

**Measured, not asserted.** `build/texval_run.log` -> `== 8 passed, 0 failed ==`; with a real asset
`build/texval_star.log` -> `== 10 passed, 0 failed ==`, `asset sampled == asset decoded (byte-exact
import round trip) (65536/65536 texels exact)`. Three controls keep that from being vacuous: a baseline
case with nothing imported returns **1 unique colour / 0 non-black** (so the compare can fail), the
offscreen clear colour `(0,255,0)` appears in no chart, and a second chart differing from the first
everywhere round-trips at `262144/262144` too, so a stale texture cannot pass either case.

**Two build facts worth keeping.** (1) A `CopyTextureRegion` *destination* cannot sit on a
`D3D12_HEAP_TYPE_UPLOAD` buffer - the debug layer says so verbatim (`build/texval_run.log`, first run:
"The destination resource cannot be on a D3D12_HEAP_TYPE_UPLOAD heap"), which is why the validator
allocates its readback on `HEAP_TYPE_READBACK`; the backend's own UPLOAD staging at `:757`-ff is legal
because it is a copy *source*. (2) A full-viewport clip-space quad maps screen pixel centre `p` to
`uv = (p+1)/W`, i.e. onto a **texel boundary**, so the backend's `MIN_MAG_MIP_LINEAR` static sampler
(`:879`) blends two texels 50/50; the VS subtracts `0.5/texelsize` (derived via `GetDimensions`, so it
holds for any asset size) and only then is linear sampling exact.

**This proves nothing about boot.** The target is outside `mcla.exe`, opens its own window, and cannot
touch a `CP-DRAW`/`DRAW_INDEXED` counter. Do not cite it as frontier movement.

### F-156: real retail `.dds` textures are reachable **offline** at the offsets the guest publishes in `TOC76-XSF`, and the `01B`/`009` low bytes of those offsets are an **`RSC5` container header length**, not flag bits

- Task:        asset supply for the host texture path (feeds F-155's validator); `tools/extract_rpf_member.py`
- Type:        FACT
- Class:       E
- Priority:    P1
- Evidence:    `python tools/extract_rpf_member.py build/w160.log .dds` -> **24 members written to `build/assets/`**, each inflated to *exactly* its TOC-declared length. Positive controls first, per the F-149 hazard: `globaltex.list` @`0x000D0000` -> 575 B `"__noise 2dnoise3
"`, `entity.type` @`0x0035CA43` -> 480 B `"Version: 103
shadinggroup {"`, `shaders/ui/preload.list` @`0x001DD11C` -> 260 B `"AlphaModulate.fx
"` - all three match the spans registered in `src/gpu_device.cpp:515`-ff and `:558`-ff. Offset decode: `python tools/rpf_offline.py find meshtextures.xtd build/toc_parsed.bin` -> `0597F7BB 0003ABA7 00060009 DC2C0810`, and the archive at `0x60000` reads `05 43 53 52 | 00 00 00 09` = `RSC5` + BE header length 9, so the data really does start at `0x60009`; `legals.xsf` @`0x000A0000` reads `RSC5` + `0x1B`, matching its published `0x000A001B`.

**The texture supply question is answered without a soak.** 24 `.dds` members - including
`textures/effects/star_glow.dds`, which the preload chain has been chasing since F-063 - sit in
`xarchive_cache.rpf` as headerless raw DEFLATE, the same family F-105 established for the `.list`
members and F-149 for `entity.type`. Of the 368 distinct paths the guest publishes in `TOC76-XSF`
lines, **356 inflate**; the 12 that do not are 5 `.xsf`, 1 `.xtd` and 6 `.dcl`.

**Format, reconciled not assumed.** The readable ones are plain little-endian DDS holding **DXT1 and
DXT5 with a full linear mip chain** - `star_glow.dds` is `128 + 32768 + 8192 + 2048 + 512 + 128 + 32 +
8 + 8 + 8 == 43832`, exactly the TOC `size` word - so *these* members need no untile, and
`texture_decode`'s tiled path stays covered separately by `backend_validator.cpp` section 8. Because
`CreateDecodedTexture` accepts only scalar formats ("1 block/texel so the row-pitch copy is exact",
`src/d3d12_backend.cpp:692`-ff), the BC1/BC3 expansion happens host-side in the validator before the
import. Both a DXT1 and a DXT5 asset round-trip byte-exact (`build/texval_star.log` 65536/65536,
`build/texval_dxt5.log` 262144/262144).

**Withdraw the `01B` reading.** An earlier pass treated the low bytes of `0x64CB001B` / `0x000A001B`
as flag bits and looked for the member at `off & ~0xFFF`. That was wrong: they are the `RSC5` header
length, and the published offset is already the absolute data offset. Records whose *fourth* word
carries bit31 remain what F-149 called them - unresolved encoding, not a negative result.

**Still open, stated as open:** `meshtextures.xtd` (the UI texture dictionary the guest actually opens,
`build/w160.log` `a:/archive/resources/ui/meshtextures.xtd`) is reachable at the right offset behind a
9-byte `RSC5` header but its payload does **not** raw-inflate, and no XRN/XTD container parser exists
in `src/` or `tools/` (`grep -rn "xrtr|XNHD|XPRM" src/ tools/` -> one comment at
`src/gpu_device.cpp:543`). So the `.dds` route above is a real-asset route, not yet the route the
guest itself uses for UI textures.


### F-157: the object-shaped return of `sub_821BE0C8` is a measured loss in **three independent builds**, and F-154's "memory device owns a second handle table at `0x82861740`" mechanism is withdrawn - no instruction in the guest image forms that address

- Task:    T41.5 (stream-contract line) / builds `w165`, `w166` against baseline `w161`
- Type:    FACT (refutation of F-154's mechanism) + measurement
- Class:   E (filesystem/device) with H (instrumentation) residue
- Priority: P1 - it closes the re-open-shape question that F-151..F-154 spent four waves on
- Evidence: `generated/ppc_xenon/ppc_recomp.10.cpp:10912-10993`; raw addis+addi census of
  `build/cache/mcla_pe.bin` (method below); `src/gpu_device.cpp:12372` (the reverted branch),
  `:12129-12160` (our `sub_821BE8D8` host return); `build/w161.log:15128-15141`, `:15733`, `:15761`

**The refutation.** F-154 explained w164's loss by claiming the guest's memory device keeps its own
16-byte handle table at `0x82861740`, and that w164's object return sent the guest's device methods
there where host-served bodies had never written. That address does not exist in the guest. Re-run
method: scan every word of `build/cache/mcla_pe.bin` for `addis rT,0,0x8286` and fold any `addi` /
`ori` / `addic` on the same register within the next four words. The `0x8286xxxx` constants the image
actually forms are `82860280, 828606F4, 82860700, 82860714, 82860740, 82860844, 82860850, 82860864,
82860880, 82860890, 828608A0, 828608C0..82860A60, 82860AD4, 82860B00, 82860C04, 82860C18, 82860DF8,
82868460, 8286FEA8` - the only handle-table base is **`0x82860740`**, addis at `0x821CAF50` + addi at
`0x821CAF58`, i.e. the table `GuestSlotTableInsert` already writes. There is no second table, so
F-154's "host-served bodies never populate it" is false and its `0x82861740` writes went into
unowned `.data`.

**The measurement, with that confound removed.** Two further builds isolate the return shape alone:

| marker | `w161` (index, committed) | `w164` (object + phantom writes) | `w165` (object, no writes) | `w166` (object, one pooled alloc) |
|---|---|---|---|---|
| `C0000005` | 1 | 0 | 0 | 0 |
| `SEEK-DEAD` | 1 | 0 | 0 | 0 |
| `LISTLINE` | **171** | 167 | 167 | 167 |
| `TYPINIT` | **1** | 0 | 0 | 0 |
| `FACTORY` | **1** | 0 | 0 | 0 |
| `DICTLOOKUP` | **14** | 2 | 2 | 2 |
| `DICTFACT` | 48 | 40 | 40 | 40 |
| `GETDEV` / `CP-DRAW` / `PRESENT` / `RD-SUBMIT` | 694/166/34/24 | same | same | same |
| `Fatal error` / `FATAL-SOFT` | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 |

`w165` and `w166` are byte-for-byte the same verdict (the four lost `LISTLINE` tokens are always
`embedded:/rage_shadowdepth`, `rage_blendshadows`, `rage_shadowcollector`, `rmptfx_collision` - the
last four of the sequence and exactly the set F-135 recovers), so the loss is not the phantom writes
and not the guest-heap footprint (167 `mem.Alloc(64,16)` calls in `w165` vs one `Alloc(8*64,16)` pool
in `w166`). The object shape itself costs the ground. Reverted per F-151's own stated condition; the
tree is back to code-identical-to-HEAD (`git diff` after the revert carries comment lines only).

**Where the fault actually comes from (corrects F-151, extends F-152).** `sub_82191040` does
`bl 0x821be8d8` / `ctx.lr = 0x82191070` then `mr r31,r3` - `r31` is **`sub_821BE8D8`'s return**, not
the open's - and then uses `r31` as a stream object at four sites: `sub_821BE4F0` (kind byte,
`mr r3,r31`), `sub_821CF7B8` (text-reader ctor, `mr r5,r31`), `sub_821BE610` (`mr r3,r31`) and
`sub_821BE568` (`mr r3,r31; ctx.lr = 0x82191100`, the `cmpwi cr6,r3,13 / beq` skip-guard). So the
`lwz r11,0(r3)` on `1` faults because *our host `sub_821BE8D8` returns the slot index as its own
return value* (`src/gpu_device.cpp:12160` `ctx.r3.u32 = st`, printed by `BE8D8-HOST` as
`stream=00000001`), and `w161:15141` `SEEK-DEAD obj=00000001 lr=82191100` is that call. Changing
`sub_821BE0C8`'s branch was one layer too far upstream: the value `sub_821BE0C8` returns is the one
the *serving* side needs as an index, which is why every object variant of it loses ground.

**Consequence for the plan.** The single VEH-masked `C0000005` at `lr=821BE5F4` is not on the
critical path: with the index return the boot still reaches `TYPINIT` (`w161:15128`,
`name='entity'`), `REALIZE-CAST` with `end=0x1E5` (the F-149 inflated `entity.type` body) and
`LISTLINE 171`. Do not re-open the "return an object from BE0C8" idea, and do not treat the AV as
B4's blocker - B4's gate is still `DRAW_INDEXED 0` at all four builds. If the fault is revisited it
must be at `sub_821BE8D8`'s return, and it then has to satisfy both consumers, which means the
index/object duality in `MakeMemoryStream` has to go, not be routed around.


### F-158: B5's acceptance criterion 1 names a file that does not exist (`src/xam.cpp`); the two `XamInputGetState` printers are **indistinguishable by marker name**, and neither fires at the frontier

- Task:    B5 acceptance test, checked before it is claimed
- Type:    FACT (plan-wording correction + measurement)
- Class:   H (instrumentation) / D (kernel runtime)
- Priority: P2 - it costs a session a false gate claim otherwise
- Evidence: `ls src/xam.cpp` -> No such file; `src/kernel/xam.cpp:318`, `src/patches.cpp:744`,
  `src/patches.cpp:119`/`:132`; `build/w161.log` (`grep -ic xaminput` = 0, and
  `grep -ic "GetState"` = 0)

**Where the real one is.** The plan text says "xam.cpp's real `XamInputGetState` line fires (not
patches.cpp's synthetic)". There is no `src/xam.cpp`; the implementations are `src/kernel/xam.cpp`
(the XAM syscall the guest imports, `src/kernel/xam.h`, registered via `src/kernel/imports.cpp`) and
`src/patches.cpp` (a native detour `hk_native_XamInputGetState` at `:113`, plus the PPC-side
`hk_XamInputGetState` at `:236`).

**The discriminator, because the marker name cannot serve.** Both print the same prefix
`XamInputGetState[` at **INFO** level, so a name-based census counts them together:

| printer | file:line | shape of the line | cap |
|---|---|---|---|
| real (kernel) | `src/kernel/xam.cpp:318` | `XamInputGetState[N] port= buttons=XXXX lx= ly=` | `N <= 8 or N % 2000` |
| synthetic (patch) | `src/patches.cpp:744` | `XamInputGetState[N]: port= buf=0xXXXXXXXX held= lr=` (note the colon) | `N <= 100 or N % 1000` |

So B5 criterion 1 is `grep -c "XamInputGetState\[.* buttons=" build/wNN.log` >= 1 - the `buttons=`
field, not the marker name. Both caps are low, so a small count is not a small number of calls.

**Measured state.** In `w161` (the frontier) *neither* fires: `XamInput`, `GetState`, `xam` all count
0 lines. Input is therefore not polled at all before the menu, which is consistent with the guest
never having reached a UI loop - criterion 1 is blocked by B4's feed, not by an instrument gap. Do
not read the zero as "input is broken" until a soak exists that draws a menu.


### F-159: B4's premise is **empty, measured three independent ways** - the guest has submitted no geometry at this frontier, so there is nothing for the constant-capture step to capture; and F-139/F-140's `draw_indx=0` was a 904-dword sample, not a property of the packet stream

- Task:    B4 gate analysis (`DRAW_INDEXED >= 1` from a non-zero constant bank), builds `w161`/`w166`
- Type:    FACT (refutation of a plan premise) + correction of F-139/F-140's evidence
- Class:   F (GPU/shader translation)
- Priority: P0 - it decides what the next task can be
- Evidence: `build/w161.log` / `build/w166.log` (`SUBMIT-census sub_82420BA8`, `DRAW-GATE dummy`,
  `CP-DRAW #1..#24`, `PKT-CAP summary`, `PARK-SAMPLE`, `HB-FLICKER`); `src/gpu_device.cpp:1962-1968`,
  `:1986-2021`, `:1574`; `src/gpu_cp.cpp:639-696`; `src/d3d12_backend.cpp:1459-1467`,
  `src/d3d12_backend.h:356`; `.research/xenia/src/xenia/gpu/register_table.inc:493-571`

**1. The API draw path carries no vertex stream.** `sub_82420BA8` is the only producer of
`DRAW_INDEXED` (`src/gpu_device.cpp:2027-2028`, consumer `src/render_thread.cpp:240`), and it is
called **twice per boot**: `SUBMIT-census sub_82420BA8 #1 dev=40002080 flags=0 lr=8217BB10 streams=0
vb0=[00000000,00000000,00000000] r5=00000000 ... r6=40000770` then `DRAW-GATE dummy #1
vb=00000000/0 ib=00100003/2 stride=0 cnt=1280`. `streams` is read from the device at `dev+12748`
(`:1963-1967`) and is **0**, and `r5` - the vertex-stream descriptor `:1986-1990` reads `vbAddr`/
`vbStride`/`vbSize` from - is 0. So the `plausible` gate at `:2019-2021` fails on the vertex side
while the index side half-decoded (`cnt=1280`). Two calls, both dummy, `plausible` counter never
incremented.

**2. The CP path's draws have no geometry operands either.** 24 AUTO draws
(`op=0x36 source_select=2`, `src/gpu_cp.cpp:639-696`) all read
`CP-DRAW #N op=0x36 src=2 prim=1 numIdx=1 idxSize=0 dmaBase=00000000 dmaSize=00000000
initiator=00010081 hdr=C0003600 at C71DC180` - a 1-index, zero-size, null-DMA submission. And that
site is census-only by design ("it does NOT render", `src/gpu_cp.cpp:643-647`): `g_commandQueue`
appears 0 times in `gpu_cp.cpp`.

**3. The register file contains no VB/IB/constant state to decode.** F-116's "10 of 54 pokes are
`0x2xxx`" is true but those pokes are **raster and backend state only**. All 22 distinct high ids in
`CP-REG-HI #1..#22`, named against the local Xenia register table:

| id | name | id | name |
|---|---|---|---|
| `2000` | RB_SURFACE_INFO (16 writes) | `2202` | RB_COLORCONTROL |
| `2007` | COHER_DEST_BASE_1 | `2203` | RB_HIZCONTROL |
| `200D` | COHER_DEST_BASE_7 | `2204` | PA_CL_CLIP_CNTL |
| `2080` | PA_SC_WINDOW_OFFSET | `2208` | RB_MODECONTROL |
| `2100` | VGT_MAX_VTX_INDX (`0000FFFF`) | `2280` | PA_SU_POINT_SIZE |
| `2104` | RB_COLOR_MASK | `2293` | PA_SC_VIZ_QUERY |
| `210D` | RB_STENCILREFMASK | `2300` | PA_SC_LINE_CNTL (38 writes) |
| `2180` | SQ_PROGRAM_CNTL (`1000000E`) | `2301` | PA_SC_AA_CONFIG |
| `2200` | RB_DEPTHCONTROL | `2302` | PA_SU_VTX_CNTL |
| `2201` | RB_BLENDCONTROL0 | `2312` / `2318` / `231B` | PA_SC_AA_MASK / RB_COPY_CONTROL / RB_COPY_DEST_INFO |

`.research/xenia/src/xenia/gpu/register_table.inc:493` (`0x200D`), `:501` (`0x2100`), `:523`
(`0x2180`), `:571` (`0x2300`). No vertex-buffer offset/stride register, no index-buffer address, no
float-constant bank. `CpRegPoke` (`src/gpu_cp.cpp:82`) is pure storage with **no semantic decode**,
and no `CpRegPeek` call site ever reads an id `>= 0x2000` (only `0x08B/0x08C/0x0DD/0x0D2/0x0A2/
0x1DC/0x1DD`, all log-only). PM4 `0x2D SET_CONSTANT` / `0x2F LOAD_ALU_CONST` are **not
implemented** in `DrainPacketAt` (`src/gpu_cp.cpp:606-702` implements `0x3F/0x48/0x3D/0x22/0x36/
0x21/0x2B`; the rest hits `LogType3Unhandled`), and `CpExecImLoad` (`:161-180`) reads the shader
upload header and **discards the microcode** - it fires 8 times with real payloads
(`CP-IM-LOAD #1 shader_type=0 size_dwords=24`).

**Correction to F-139/F-140's evidence.** Their conclusion came from `PKT-CAP`, which scans only the
windows `sub_82411640` hands it, clamped to `kPktCapMaxDwords = 256`
(`src/gpu_device.cpp:1574`) - cumulative `PKT-CAP summary: desc=15 dw=904`, while the same boot
requests windows of `n=131072`/`n=131086` dwords, and it never reads the `C71DC1xx` region where the
real draws decode. So `draw_indx=0 set_const=0 load_alu=0` was a **904-dword sample**, never a
statement about the guest's packet stream. (It happens to point the same way as items 1-3, because
of item 2's direct packet fields - but it could not have established them.)

**Consequence, stated plainly.** The zero-filled bank at `src/d3d12_backend.cpp:1463-1466` has no
producer anywhere (`kShaderConstantBytes` is referenced only there and at
`src/d3d12_backend.h:356`; `DynamicMeshDesc` has no constant field), and B4's capture work is
downstream of a draw that the guest has not made. All 34 `PRESENT` lines are heartbeat
(`HB-FLICKER #2880 frame=0`), and `RenderThread: PRESENT` - the guest-kicked present - is **0 lines**.
The boot is parked in `NtDelayExecution` on a 30 ms poll (`WAIT[KWFSO] ... reason=3 to=30ms`,
`PARK-SAMPLE nf=NtDelayExecution+0x14`, 130 identical samples) with the CP caught up
(`pub=11 put=11`, `drains=8`). So the blocker between this frontier and a rendered menu is no longer
"the renderer is fed zeros" - it is **why the guest stops submitting anything**, and B4's gate is
only reachable through that.


### F-160: the guest's own slot-release routine is decoded, was **never called** by anything until now, and routing our one consumption point through it is frontier-neutral but does NOT retire the recycle mitigation (6 releases vs 173 bodies served)

- Task:    B3-style mitigation retirement on the F-135 slot table; builds `w167` (census only) and `w168` (the change)
- Type:    FACT + FIX (emulation replaced by the discovered mechanism)
- Class:   E (filesystem/device)
- Priority: P1
- Evidence: raw words at `0x821CB2A0` in `build/cache/mcla_pe.bin` (offset `0x1CB2A0`, listed below); `src/gpu_device.cpp:12727`-ff (the new census hook), `:12153`-ff (the replaced clear); `build/w167.log`, `build/w168.log`

**Decode.** `sub_821CB2A0(r3=wrapper, r4=h)`: `cmpi cr6,r4,0` + `bc 12,24` reject, `cmpi cr6,r4,16` +
`bc 4,24` reject - so **the 16-entry bound is the guest's own**, not our `kGuestSlotCount`; then
`rlwinm r11,r4,sh=4` (h*16) + `lis r10,8286` / `addi r10,r10,1856` = `0x82860740` (again confirming
F-157's phantom refutation), `lwzx r9,r11,r10` / reject if `[entry+0]==0`, `lbz r11,12(r31)` / if the
**flag byte is non-zero** call `821BBEA8`, `lwz r3,0(r31)`, `82130588`, `821BBF00` (a free), and
finally `li r11,0 / li r3,0 / stw r11,0(r31)` - the only store in the image that releases a table
entry - then the epilogue. It is a **Close**, which corrects F-135/F-153's "device Seek at vtable+44".

**w167 (census only, installed first per rule 1).** `SLOT-CLOSE` = **0 lines**, and the census is
provably frontier-neutral: `LISTLINE 171`, `TYPINIT 1`, `C0000005 1`, `SEEK-DEAD 1`, `GETDEV 694`,
`BE0C8 358`, `CP-DRAW 166`, `PRESENT 34`, `RD-SUBMIT 24`, `SLOT-REG 24`, `SLOT-RECYCLE 30`,
`SLOT-RECYCLE-SHARED 24`, `[error] 42` - every one identical to `w161`. So the 15-entry leak that
F-135's two recycle tiers exist to cover is not the guest being slow to close; **nothing calls the
close at all on host-served bodies**. Our `sub_821BE8D8` host path had been *emulating* the release
with a hand-written `mem.WriteU32BE(slot + 0, 0)` (`:12154-12155`, comment: "guest close semantics:
CB2A0 clears the slot").

**The change (w168).** That hand-written clear is replaced by a call through the guest's own routine:
`ctx.r1` is moved down 256 bytes first (the routine stores LR at `-8(r1)` and r31 at `-96(r1)`
*before* its own `stwu`, so it must not inherit the caller's live frame), `r4 = h`, call, restore
`r1`/`r4`. The flag byte stays 0, so the routine's free path is not taken and our buffer survives.

**Positive control passed.** `BE8D8-CLOSE #1 h=1 slot=82860750 entry0_after=00000000` and
`SLOT-CLOSE #1 r3=82860C18 h=1 slot=[buf=827D2DD0,size=5258,pos=0,flag=00] lr=8218C804` - the hook is
live, the entry really is cleared by guest code, and `lr=8218C804` is the same site F-135 named as
the open-success check after `BE8D8`. `SLOT-CLOSE` fires **6** times per boot (1 ours + 5 that only
appeared once the first release let the walk continue), against **173** `BE8D8-HOST` bodies served.

**Stated plainly: the mitigation is still load-bearing.** `SLOT-RECYCLE 30`,
`SLOT-RECYCLE-SHARED 24`, `SLOT-TABLE-FULL 0` are all unchanged from `w167`/`w161`, and every other
frontier marker is identical - so this retires one *emulation* and proves the mechanism exists, but
it does not yet retire F-135/F-135b. Doing that needs the release to happen for every consumed body
(the `sub_821BE250`/`SlotTableServeRead` path and the `PACK` path, not just the memory-device host
path), and `pos` reaching `size` is not currently tracked for most bodies (F-135b measured that the
`pos >= size` test recycled only 1 of 15 slots).


### F-161: releasing a slot at the **read** sites when `pos` reaches `size` is catastrophic (measured, reverted) - while `SLOT-RECYCLE-SHARED` aliases one index across consecutive bodies, a "consumed" slot IS the one still in use, and that is exactly why F-135b's `pos >= size` tier recycles so little

- Task:    B3-style mitigation retirement, step 2 of F-160; build `w169` against baseline `w168`
- Type:    FACT (refutation of the obvious next fix) + FIX reverted
- Class:   E (filesystem/device)
- Priority: P1 - it is the blocker to retiring F-135/F-135b, and the shape of the real fix follows from it
- Evidence: `build/w169.log` vs `build/w168.log` (census below); `src/gpu_device.cpp:11727`-ff (`pos >= size` tier), `:11757`-ff (`SLOT-RECYCLE-SHARED`), `:12153`-ff (the one safe point); the reverted form is recorded in the comment at that site

F-160 established that the guest's own Close (`sub_821CB2A0`) is the only releaser and that nothing
calls it. The obvious step 2 was to call it wherever a body finishes being served, using F-135 tier-1's
own condition (`slot pos >= size`). `SlotTableServeRead` already advances `pos`, so the signal existed;
the change added an `outExhausted` flag and released at both read sites (`sub_821BE250`,
`sub_821BE710`).

| marker | `w168` (release at copy-out only) | `w169` (+ release at read sites) |
|---|---|---|
| `Fatal error` | 0 | **2** |
| `FATAL-SOFT` | 0 | **3** |
| fatal-shaped lines | 37 | **5,946** |
| `INFLATE` | 358 | **168** |
| `[error]` lines | 42 | **61** |
| `SLOT-CLOSE` | 6 | 12 |
| `LISTLINE` / `TYPINIT` / `GETDEV` / `CP-DRAW` / `PRESENT` / `DRAW_INDEXED` | 171 / 1 / 694 / 166 / 34 / 0 | unchanged |

The frontier counters that usually move did **not** move, which is what makes this informative rather
than just bad: the file walk still completed, but 190 inflate calls disappeared and two new fatals
appeared with the soft-masking tier firing. The mechanism is the aliasing F-135b introduced:
`SLOT-RECYCLE-SHARED` returns the *same* index for consecutive bodies (legitimately, because every
body this path serves is described by the one shared static `kMemStreamSlot`), so a slot that reads as
"consumed" is by definition the slot some other live handle is still aliasing - releasing it revokes a
body that is still being read. `w169` shows 6 of the 12 releases landing on `h=15` repeatedly, the
recycled index.

**Consequence, and the shape of the real fix.** The copy-out site is the only place a body is
provably dead, because the bytes have already been duplicated into `dst`. Retiring F-135/F-135b
therefore cannot be done by releasing better - it requires each served body to own a distinct slot
until it is genuinely finished, i.e. the shared-static `kMemStreamSlot` aliasing has to go first (the
16-entry bound itself is the guest's, decoded at `0x821CB2B0`-`0x821CB2BC`, so it is not the limit).
Reverted; `src/gpu_device.cpp` is byte-identical to HEAD except for the comment that records this.


### F-163: THE FIX (B4 unblock) - scoping the stream-object return to the one caller that dereferences it makes the entity-type registration **complete** for the first time: `TYPINIT` 4 enters / 4 returns, `C0000005 1->0`, `SEEK-DEAD 1->0`, `INFLATE 358->17,220` - and the group is no longer null

- Task:    T41.6 / B4's feed, `build/w171.log` against baselines `build/w170.log` (census build) and `w168` (frontier)
- Type:    FIX
- Class:   C (guest ABI/pointer semantics)
- Priority: P0
- Evidence: `build/w171.log` (`BE8D8-CALLER #4`, `BE0C8-OBJ #179..#182`, `TYPINIT`, `TYPINIT-RET`, `SHGRP-VARS #1`, `Fatal error`); `generated/ppc_xenon/ppc_recomp.10.cpp:10912-10993`; `src/gpu_device.cpp` (the latch at the `sub_821BE8D8` fallthrough, the object build in `sub_821BE0C8`'s `memory:$` branch)

**Why the previous three attempts failed and this one didn't.** F-153/F-155/F-156 (w164/w165/w166)
changed the return shape of *every* `memory:$` re-open - and `w170`'s new caller tally shows all 179
of them arrive from one site (`lr=821BE988`, inside the guest's own `sub_821BE8D8` tail), so a blanket
change re-shaped 178 consumers that legitimately store the value as a slot handle. The caller that
dereferences it is **one** - `sub_82191040`, `BE8D8-CALLER #4 lr=82191070 first at n=190` - so the
shape is now chosen per caller: the `sub_821BE8D8` hook latches a flag around a call made with
`lr == 0x82191070`, and `sub_821BE0C8` builds the guest-shaped object
(`+0 kMemDeviceObj, +4=slot index, +8=buf, +28/+32=size`, from a pool allocated once) only for that
call. It fired 4 times (`BE0C8-OBJ #179..#182`) - once per entity realization, not 179 times.

**Measured, against the census build `w170` (which is the committed frontier's marker-for-marker twin):**

| marker | `w170` | `w171` | |
|---|---|---|---|
| `C0000005` / `VEH-NEUTRAL` | 1 / 1 | **0 / 0** | the AV is gone, nothing masked to remove it |
| `SEEK-DEAD` | 1 | **0** | |
| `TYPINIT` (lines) / `TYPINIT-RET` | 1 / 0 | **4 enters / 4 returns** | the registration completes |
| `INFLATE` | 358 | **17,220** | |
| `DICTLOOKUP` / `REQ` | 14 / 135 | **23 / 154** | |
| `BLIT-SRC` | 27 | 36 | |
| `[error]` lines | 42 | **28** | |
| `LISTLINE` / `GETDEV` / `CP-DRAW` / `PRESENT` / `RD-SUBMIT` / `DRAW_INDEXED` | 171 / 694 / 166 / 34 / 24 / 0 | unchanged | |
| `Fatal error` / `FATAL-SOFT` | 0 / 0 | **1 / 1** | cost, stated below |

**The cost, stated: B5's criterion 3 (zero `FATAL-SOFT`) regresses 0 -> 1**, and the new fatal is the
*old* gate - `Required grmShaderGroupVar 'skinningData' not found.` (`lr=0x82193BA0`, `r4='skinningData'`).
It is not a regression of a working state: it is a gate that was previously unreachable because the
registration never got far enough to look the variable up. Same shape as F-149, which also exposed a
new blocker and was kept.

**Why this is the B4 unblock rather than another dead end: the shader group is now a real object.**
`SHGRP-VARS #1 group=A003CA30 vt=8200C4C0 arr=A003CA80 nvars=1 req=1 want='skinningData'
e0=A003CA90/'' e1=00000000/'' lr=82379D04` - through w138..w168 this binder was only ever reached with
`group=0` (F-142/F-144). It now arrives with a live group, a live var array, and **one declared
variable** whose name reads back empty. So F-136's "the content does not declare skinningData" is dead
a second time, and the next question is narrow and instrumented: what is in the var descriptor at
`A003CA90`, and is its name at an offset the census does not read.

**Known weakness, kept honest:** the pool is indexed by slot index, and because
`SLOT-RECYCLE-SHARED` keeps handing out `idx=1`, all four objects landed on the same address
(`obj=CE83E5C0`) - i.e. the four live realizations alias one object. 4/4 still returned, so no
evidence of damage this boot, but the aliasing F-161 identified is the reason that is luck rather
than design; per-body slots remain the cleanup that would retire F-135/F-135b.


### F-164: after F-163 the `skinningData` gate is a real CONTENT gate one level up - the entity's own `.type` text declares `Template "RimMain"` / `blackmatte`, and the `.mtlgeo` material files that carry the variable list are **not in `xarchive_cache.rpf`** - plus two instrument hazards this step measured

- Task:    B4's feed, after the F-163 unblock; builds `w172`/`w173` (census variants) against `w171`
- Type:    FACT
- Class:   G (the game's own coded content) + H (instrumentation)
- Priority: P0 - it retires the last "our parser is wrong" reading of the skinningData gate
- Evidence: `build/game_data/xarchive_cache.rpf` inflated offline at the ten `kTypeMemberSpans`
  offsets (all ten inflate, 480-648 B each, every one starting
  `Version: 103

shadinggroup {

ShadingGroup

{

	Shaders N`);
  `python tools/rpf_offline.py find ext_matteblack.mtlgeo build/toc_parsed.bin` -> 0 records
  (positive control in the same run: `find .../entity.type` -> 12 records);
  `build/w172.log` / `build/w173.log` `SHGRP-VARS #1`

**What the content actually says.** The four `entity.type` files the boot opens
(`ao_cone`, `ao_shadow`, `ao_sphere`, `sst_trail`) each declare a shading group whose shaders are
*material references*, e.g. `Shaders 1 { Vers: 2 "T:/mc4/art/veh/materials/default_mtl/
ext_matteblack.mtlgeo" Template "BlackMatte" Bucket 0 blackmatte 0 { } }`, and the six-shader one
declares its single real parameter inline (`RimMain 1 { shaderMaterialId { int 2 } }`). None of the
ten contains the string `skinningData`. So the variable the game requires comes from the **material
template**, and `ext_matteblack.mtlgeo` / `RimMain` / `BlackMatte` have no TOC record in the retail
cache archive at all. That is also consistent with `agents.md`'s content rule (that tree is
`mc4/art`, which we never serve).

**In-guest agreement.** The binder now reaches its lookup with a live group
(`SHGRP-VARS #1 group=A003CA30 arr=A003CA80 nvars=1 req=1 want='skinningData' lr=82379D04`) whose one
var's name pointer is non-null but points at sixteen 0x00 bytes
(`name=CA711488:[00000000...]`, address differs per run - it is heap). An unnamed placeholder var is
exactly what a group built from an unresolvable template looks like. So F-136's original "content
wall" verdict is restored *in a corrected form*: the wall is real, but it is one file higher than
F-136 thought (the material template, not the `.type`), and F-149's compression defect was a genuine
defect that F-136's framing had hidden.

**Hazard 1 - this census moved the frontier, twice, and I reverted it.** Adding a second log line
plus 22 extra per-call reads to `sub_82193AF8` changed `Fatal error 1->4`, `FATAL-SOFT 1->7`,
`INFLATE 17,220->7,597`; the trimmed version (one extra read, folded into the existing line) still
gave `INFLATE ->5,022` and `fatal-shaped lines 76->5,587` while every structural counter held. Both
census builds are reverted; `src/gpu_device.cpp` is the F-163 code again (rebuilt exe is byte-size
identical to the `w171` binary, 97,553,408 B).

**Hazard 2 - `INFLATE` and the `fatal`-substring line count are NOT stable signals at this frontier**
(358 / 17,220 / 7,597 / 5,022 across four consecutive boots, two of them the same binary). Cite them
only as order-of-magnitude context, never as a gain. F-163's evidence stands on the deterministic
counters only: `C0000005 1->0`, `SEEK-DEAD 1->0`, `TYPINIT 4 enters / TYPINIT-RET 4` (reproduced in
`w172` and `w173`), `DICTLOOKUP 14->23`, `[error] 42->28`.

**Consequence for the plan.** B4's gate cannot be met through the vehicle-material groups - the
content that would declare their variables is not in the archive we serve. The remaining routes are
the ones that do not need those templates: the UI/GFx path (the boot already shows `GFx 3`,
`UILOAD 1`, `swfCMD 0`), or a group whose vars are declared inline (the `RimMain 1 { shaderMaterialId
{ int 2 } }` shape above shows that form exists in this content).


### F-165: the menu's actual blocker, found - **every RSC5-framed member is bound at exactly 32768 bytes**, while non-RSC5 members get their true sizes; all UI content is RSC5-framed, and the GFx side shows the consequence

- Task:    B5 (menu on screen) / the route F-164 left open; measured entirely from `build/w171.log`
- Type:    FACT (a structural defect in our own serve path, not content)
- Class:   E (filesystem/device)
- Priority: P0 - it is the first hard blocker on the menu path that is ours to fix
- Evidence: `build/w171.log` (`XSF-BIND`, `PKG-SUBST`, `XSF-HOSTSERVE`, `TOC76-XSF`,
  `W32-CONSTRUCT-CENSUS`, `W34-NOGFX`); `src/gpu_device.cpp:307`-`:313`, `:689`-`:700`;
  `python tools/rpf_offline.py find legals.xsf build/toc_parsed.bin` -> 1 record (control in the
  same run: `entity.type` -> 12, `ext_matteblack.mtlgeo` -> 0)

**The measurement.** `XSF-BIND ... size=` for every member the boot binds, grouped by path:

| bound at | members |
|---|---|
| **`size=32768`** | `resources/ui/credits/credits.xsf`, `.../garage/garage.xsf`, `.../policecam/policecam.xsf`, `.../raceeditor/raceeditor.xsf`, `resources/ui/meshtextures.xtd`, `resources/city/SC/trash.xrn` - **every one of them `head=05435352`, i.e. the `RSC5` container magic**, and every `PKG-SUBST` maps them to one shared `pkg` base (`000A0000` for all four `.xsf`, `00060000` for the `.xtd`, `0035A000` for the `.xrn`) |
| true size | `shaders/city/preload.list 1246`, `textures/effects/fog.dds 3,268,608`, `textures/effects/rain.dds 824`, `textures/effects/star_glow.dds 3,235,840`, `.../dmg_test_3.dds 3,346,432`, `.../tire_track.dds 3,338,240` |

So this is not "the serve path is broken" - plain and `.dds` members are served at full length (and
the peer's F-156 validator round-trips `.dds` byte-exact). It is the **RSC5 framing** specifically:
the length handed to the bind is the `0x8000` walk window from `src/gpu_device.cpp:309-311`
(`uint32_t n = want ? want : 0x8000u; if (n > 0x8000u) n = 0x8000u;`, with `pkgSz` floored to
`0x8000` at `:689-690`), not the member's own length, and `resources/ui/legals/legals.xsf` - the
first screen the boot asks for - appears in `PKG-SUBST` but never reaches `XSF-BIND` at all.

**The consequence, visible in the same log.** The Scaleform side is constructed but empty:
`W32-CONSTRUCT-CENSUS #2 obj=B7B41000 vt=82085364 +24=CDCDCDCD arr=00000000 nPtr=0 nValidTag=0
nSwfLike=0 nDest=0` and `W26-PLUS24-NODE ... swfc=0`, with
`W34-NOGFX #1 - no GFx loader objects (vt 0x82073xxx) in scan bands; UILOAD/EF220 never armed after
inflate`. `swfCMD` is 0 across every soak at this frontier. That is what a UI whose container was cut
to 32 KB looks like from the inside.

**The control that makes this citable.** The ten `entity.type` members F-149 fixed are *also* served
from the same archive and *also* needed a length correction - and there the fix was to take the length
from the TOC's own word (the inflated size), which made them parse. The same class of defect is now
identified on the UI path with the sizes on the table above.

**Next step, stated as a testable task:** take the real length for RSC5 members (the TOC record's size
word, or the length the `RSC5` header itself declares - F-156 established the header carries one)
instead of the `0x8000` window, bind that, and the pass condition is `XSF-BIND size=` for the `.xsf`
paths becoming their true lengths, `W32-CONSTRUCT-CENSUS nValidTag > 0` (or any `swfCMD` line) firing
for the first time, with `LISTLINE 171` / `TYPINIT 4`/`TYPINIT-RET 4` / `C0000005 0` unchanged. B4's
`DRAW_INDEXED` gate is downstream of this, because a UI draw is the most likely first indexed draw.


### F-166: correction to F-165's stated next step - the UI members' TOC offsets do **not** point at RSC5 headers, so "bind the TOC length" is wrong; the real defect is that `MclaPreferredPkgOffForPath` maps **every** `.xsf` to one placeholder package at `0xA0000` by path substring

- Task:    B5 (menu) - same thread as F-165, measured before writing any code
- Type:    FACT (refutes part of F-165) - and it re-scopes the fix
- Class:   E
- Priority: P0
- Evidence: `build/game_data/xarchive_cache.rpf` read at each `tocOff` published by
  `build/w171.log` `TOC76-XSF`; `src/gpu_device.cpp:288-301`
  (`MclaPreferredPkgOffForPath`), `:303-332` (`MclaLoadPkgWindow`), `BuildRscPackageTable`

**What is at the TOC offsets (32 bytes read at each, from the archive directly):**

| member | `tocOff` | first bytes there | RSC5 (`05 43 53 52`)? |
|---|---|---|---|
| `resources/ui/credits/credits.xsf` | `000073EB` | `d3 f5 e7 27 94 67 3c 9f ...` | no |
| `resources/ui/garage/garage.xsf` | `0010445D` | `c3 1e 27 64 2c 1b f4 eb ...` | no |
| `resources/ui/legals/legals.xsf` | `0002FFDD` | `02 a1 bb 88 ff bc 58 34 ...` | no |
| `resources/ui/policecam/policecam.xsf` | `00004B9D` | `fb 1e 8d 11 da 20 53 59 ...` | no |
| `resources/ui/raceeditor/raceeditor.xsf` | `00022EF1` | `94 9d ee e9 b2 ec 55 41 ...` | no |
| `resources/ui/meshtextures.xtd` | `0003ABA7` | `d1 0b f8 91 ae 75 ee cb ...` | no |
| `resources/city/SC/trash.xrn` | `00002A43` | `b0 e5 6e 68 a8 ec b1 20 ...` | no |

All high-entropy, none a container header. The offsets the boot actually serves from (`0xA0000` for
all five UI `.xsf`, `0x60000` for the `.xtd`, `0x35A000` for the `.xrn`) DO begin with RSC5
(`head=05435352` in `PKG-SUBST`) - because they are *packages*, and the UI members' bytes live
**inside** them.

**So F-165's prescription is withdrawn**: taking the TOC record's own size/offset would serve those
high-entropy bytes and change nothing. The defect that stands is narrower and clearer:
`MclaPreferredPkgOffForPath` (`src/gpu_device.cpp:288`-`:301`) is a placeholder that picks a package
by path substring - `meshtextures` -> `0x60000`, and *any* `.xsf`/`.xtd`/`resources/ui` -> `0xA0000`,
with everything else returning 0 (no substitution). Five different UI files therefore receive the same
32 KB window of one package, and the `0x8000` clamp at `:309-313` bounds even that. The `Rpf3` model
already builds a package table (`BuildRscPackageTable`, called at `:305`); what is missing is the
member -> (package, entry) resolution through it.

**Restated next step (this one is a work order, not a guess):** enumerate the RSC5 packages' entry
tables, match the requested leaf name (`credits.xsf` etc.) to an entry, and serve that entry's data -
replacing the substring function, not adding to it. Pass condition stays the same and is measurable
without new instruments: `XSF-BIND size=` differing per path (today all six are 32768), then
`W32-CONSTRUCT-CENSUS nValidTag > 0` or any `swfCMD` line firing for the first time, with `LISTLINE
171` / `TYPINIT` 4-enters-4-returns / `C0000005 0` unchanged. If the entry table turns out to be
encrypted (the on-disk TOC is AES per F-099), then this is the content boundary and B5's menu needs a
different source - that is the branch point, and it is resolvable offline in one look at a package
header rather than a soak.


### F-167: the RSC5 package lookup is DECODED offline - a TOC record's word[2] is `(packageOffset & 0xFFFFF000) | headerLength` and word[3] is the package's own ID at `[pkg+8]`; it verifies for `legals.xsf` (the boot's first screen), `meshtextures.xtd` and `trash.xrn`, and the four remaining `.xsf` carry a `0x64…` prefix that is a volume selector, not an offset in this archive

- Task:    B5 (menu) - replaces F-165's placeholder path-substring mapping with a decode
- Type:    FACT (discovered mechanism; makes the next step a coding task, not a guess)
- Class:   E
- Priority: P0
- Evidence: `build/game_data/xarchive_cache.rpf` (size `0x7F008000`) read at the offsets below,
  cross-checked against `build/w171.log` `TOC76-XSF` record words; `src/gpu_device.cpp:288`-`:301`
  (the function this replaces), `:329` (it already knows the `0x0FF512EF` Xcompress magic)

**The test and the result.** For each UI record, take `pkg = w2 & 0xFFFFF000`, `hdrLen = w2 & 0xFFF`,
read `[pkg+0]` (expect RSC5 `05 43 53 52`) and `[pkg+8]` (expect `== w3`):

| member | `w2` | `pkg` | `hdrLen` | magic at pkg | `[pkg+8]` vs `w3` |
|---|---|---|---|---|---|
| `resources/ui/legals/legals.xsf` | `000A001B` | `0x000A0000` | 27 | RSC5 | `D454283D` == `D454283D` **MATCH** |
| `resources/ui/meshtextures.xtd` | `00060009` | `0x00060000` | 9 | RSC5 | `DC2C0810` == `DC2C0810` **MATCH** |
| `resources/city/SC/trash.xrn` | `0035A042` | `0x0035A000` | 66 | RSC5 | `C0001814` == `C0001814` **MATCH** |
| `credits.xsf` / `garage.xsf` / `policecam.xsf` / `raceeditor.xsf` | `6496F01B` / `6498001B` / `64CA301B` / `64CB001B` | `0x649…`-`0x64CB…` | 27 | all `00000000` (unstored) | no match |

Masking those four down into the file (`& 0x0FFFFFFF` -> `0x049…`) was tried and is wrong too - the
bytes there are neither RSC5 nor their ID - so the `0x6000_0000` bits are a selector for another
volume, not a clampable offset. That is a separate, later question.

**Header layout, from the 27-byte `legals.xsf` package at `0xA0000`:**
`05 43 53 52` magic | `00 00 00 1B` header length | `D4 54 28 3D` package ID (== TOC word[3]) |
`0F F5 12 EF` the Xcompress magic this file's own loader already recognizes
| `00 02 FF C9` | `10 F8 B8 20 49 40 95 4D` (reads as a Windows FILETIME) | then payload.
`meshtextures.xtd`'s package declares `hdrLen 9` and `trash.xrn`'s `66`, so the length field is real
and per-package - which is what F-156 read as "the `01B`/`009` low bytes are an RSC5 header length".

**What this changes.** `MclaPreferredPkgOffForPath` (`src/gpu_device.cpp:288`) can be replaced by a
decode of the record the guest already handed us: the UI members that DO live in this archive resolve
with a verified ID instead of being collapsed onto one placeholder package by substring, and the four
that do not can be reported as a volume mismatch rather than silently served wrong bytes. The
testable pass condition for that change is unchanged from F-165/F-166: `XSF-BIND size=` per path
(today six identical 32768s), then any `nValidTag > 0` / `swfCMD` line - and `legals.xsf` is the first
screen, so it is the member that matters for B5.


### F-168: the RSC5 header layout is settled and it proves the UI is **truncated, not mis-mapped** - `+0x00` magic, `+0x04` header length, `+0x08` package ID (== TOC word[3]), `+0x0C` `0x0FF512EF`, `+0x10` the UNCOMPRESSED size; three for three, and every one of them is bound at 32768

- Task:    B5 (menu) - continuation of F-167 from the archive bytes only
- Type:    FACT
- Class:   E
- Priority: P0
- Evidence: `build/game_data/xarchive_cache.rpf` at `0x000A0000`, `0x00060000`, `0x0035A000`
  (first 32 bytes of each printed below); `build/w171.log` `XSF-BIND`; `src/gpu_device.cpp:671`-`:705`
  (the substitute branch, which already computes the right offset), `:303`-`:332` (`MclaLoadPkgWindow`)

| package | `hdrLen` | ID at `+8` | `+0x0C` | **uncompressed size at `+0x10`** | what the boot binds |
|---|---|---|---|---|---|
| `legals.xsf` @ `0x000A0000` | 27 | `D454283D` = TOC `w3` | `0FF512EF` | **196,553** | 32,768 |
| `meshtextures.xtd` @ `0x00060000` | 9 | `DC2C0810` = TOC `w3` | `0FF512EF` | **240,531** | 32,768 |
| `trash.xrn` @ `0x0035A000` | 66 | `C0001814` = TOC `w3` | `0FF512EF` | **10,799** | 32,768 |

Raw first 32 bytes (legals): `05 43 53 52 | 00 00 00 1b | d4 54 28 3d | 0f f5 12 ef | 00 02 ff c9 | 10 f8 b8 20 | 49 40 95 4d | 00 50 62 00`.

**Two corrections this forces.** (1) F-165's framing was right about the symptom but its prescription
was wrong twice over: the TOC offset is not the data (F-166), and the substring map is *not* what
breaks `legals.xsf`/`meshtextures.xtd` - for those two `MclaPreferredPkgOffForPath` and the TOC decode
agree (F-167), and the code already prefers the substring (`uint32_t pkgOff = pathPkg ? pathPkg :
tocPkg;`, `:686`) so flipping the priority would change nothing. (2) F-126's "w[3] is the TOC record's
FLAGS dword, not a file identity" is now too strong: word[3] equals the package's ID word in 3 of 3
cases where the package is in this archive, and the 4 cases where it does not match are exactly the 4
whose word[2] prefix (`0x64…`) points outside this archive. Both statements need the same follow-up
(flip the priority *and* add the `+8 == w3` check) only once the size problem below is dealt with.

**The remaining question, precisely.** `+0x10` is the *uncompressed* length; the window we load is
capped at `0x8000` by `MclaLoadPkgWindow` (`:309-311`) and `pkgSz` is floored to the same value
(`:689-690`), while the inflate path at `:655` (`kHeadRsc5`/`kHeadXcmp` -> `XSF-INFLATE`) can only
expand bytes it was given. So either (a) the stored length is elsewhere in the header (the trailing
`00 50 62 00 74 13 00 70 00 00 ff 5f` is unexamined) or (b) loading a larger *stored* window and then
inflating is enough. That is answerable by one experiment: raise the window cap to a few hundred KB
keyed on the declared size and look at whether `XSF-INFLATE expanded=` reaches the declared number
and `XSF-BIND size=` stops being 32768. Pass condition as before: per-path sizes differing, then
`W32-CONSTRUCT-CENSUS nValidTag > 0` or any `swfCMD` line, with `LISTLINE 171` / `TYPINIT` 4/4 /
`C0000005 0` unchanged - and per F-164's hazard note, no new log lines and no per-call extra reads to
measure it.


### F-169: the RSC5 window fix is in (UI bodies now served at their declared length), AND the boot's outcome is **bimodal run to run** - `TYPINIT` 3-vs-4 and `Fatal error` 0-vs-1 are not effects of any change, which retro-softens several single-soak comparisons made today

- Task:    B5 (menu) - implement F-168's finding; four soaks of two binaries
- Type:    FIX + FACT (a measurement hazard)
- Class:   E + H
- Priority: P0 for the hazard, P1 for the fix
- Evidence: `build/w174.log` (raise variant), `build/w175.log`, `build/w176a.log`,
  `build/w176b.log` vs `build/w171.log`; `src/gpu_device.cpp` `MclaRsc5DeclaredSize`
  (new, ~`:303`), `MclaLoadPkgWindow`'s `kPkgWindowMax`, the `PKG-SUBST` branch (~`:700`-`:720`)

**The fix.** The substitute branch now reads the package's own header and uses its declared
uncompressed length as the window: `XSF-BIND size=` per path went from six identical `32768` to
`trash.xrn 10,799`, `credits/garage/policecam/raceeditor.xsf 196,553`, `meshtextures.xtd 240,531`,
with every non-container member unchanged (`preload.list 1246`, `fog.dds 3,268,608`). Two variants were
tested: taking `max(table, declared)` was wrong (the table sizes run to 2.8-4 MB, so the guest got
neighbouring archive data and `Fatal error 1->4`, `[error] 28->52`); **replacing** with the declared
length is the correct form and is what is committed.

**The hazard, and it matters more than the fix.** Three soaks of the *fixed* binary and one of the
pre-fix binary, same 120 s window:

| soak | binary | `TYPINIT` enters/returns | `Fatal error` | `FATAL-SOFT` | `[error]` | `LISTLINE` | `nValidTag`>0 |
|---|---|---|---|---|---|---|---|
| `w171` | pre-fix (F-163) | 4 / 4 | 1 | 1 | 28 | 171 | 6 |
| `w175` | fixed | 3 / 3 | 0 | 0 | 14 | 171 | 10 |
| `w176a` | fixed | 3 / 3 | 0 | 0 | 14 | 171 | 11 |
| `w176b` | **fixed** | **4 / 4** | **1** | **1** | **28** | 171 | 10 |

`w176b` is the fixed binary scoring exactly the pre-fix profile, so the boot flips between two
outcomes on its own: one entity realization either happens or does not, and when it does, the
`skinningData` fatal fires and the soft-mask tier counts 1. Consequences, stated plainly:
- **Do not read `TYPINIT`, `Fatal error`, `FATAL-SOFT` or `[error]` from a single soak as an effect.**
  Two soaks minimum, and prefer markers that cannot move: `C0000005`, `SEEK-DEAD`, `LISTLINE`,
  `XSF-BIND size=`, `GETDEV`, `CP-DRAW`, `PRESENT`, `DRAW_INDEXED`.
- This **softens F-163's table**: `C0000005 1->0`, `SEEK-DEAD 1->0` and `TYPINIT-RET 0->4` held in
  every post-fix soak (3 of 3, with `w176b` at 4), so the fix itself stands; but its
  `DICTLOOKUP 14->23` and `[error] 42->28` deltas are now unproven - they may be the other mode.
  It also means F-168's "the UI is 6x short" was real but is not yet shown to *buy* anything:
  `swfCMD` is still 0 in all four soaks.
- The 6-vs-10 `nValidTag` difference is likewise inside the noise band; my earlier reading of
  `nValidTag=0` came from looking only at the first census lines.

**Kept:** the size fix (it is correct by construction and degrades nothing), with the bimodality
recorded so the next session does not spend a cycle re-deriving it. B4's `DRAW_INDEXED` and B5's
guest-drawn `PRESENT-FB` are still unmet; the UI now has its real bytes, so the next question is what
the guest does with a full-length `.xsf`.


### F-170: the local xarchive_cache.rpf is a TRUNCATED COPY - 587,235,328 bytes (27.6%) past 0x5C000000 are zeros, and that tail is where four of the five UI .xsf packages live, so the menu is currently unreachable for a reason that is not in the emulator

- Task:    B5 (menu) - answers the question F-169 left open ("what does the guest do with a full-length .xsf")
- Type:    FACT (data-integrity blocker, found offline; no soak involved)
- Class:   E
- Priority: P0 - it is why swfCMD is 0 and the UI movie has no tags, and no code change can fix it
- Evidence: scan of build/game_data/xarchive_cache.rpf in 4 MB strides (size 2,130,739,200 =
  0x7F008000; last non-zero byte 1,543,503,872 = 0x5C000000); package offsets from the guest's own
  records in build/w176b.log (TOC76-XSF / TOC76-LAYOUT); build/w175.log XSF-HOSTSERVE head=05435352
  with XSF-INFLATE 0 in every soak today

**Record layout, corrected and complete.** A TOC record is {leafHash, SIZE, pkgOffset|headerLength,
pkgID}: the second word is the member size, not an offset. credits.xsf prints
[02313636 0002FFC9 6496F01B D4082813] = size 0x2FFC9 (196,553) and package 0x6496F01B & 0xFFFFF000 =
0x6496F000 - the field MclaPkgOffFromTocW2 already derives.

| member | package offset per its own record | state on this disk |
|---|---|---|
| resources/ui/legals/legals.xsf | 0x000A0000 | present (RSC5 magic + ID verified, F-167) |
| resources/ui/meshtextures.xtd | 0x00060000 | present |
| resources/city/SC/trash.xrn | 0x0035A000 | present |
| resources/ui/credits/credits.xsf | 0x6496F000 | ABSENT - zeros |
| resources/ui/garage/garage.xsf | 0x64980000 | ABSENT - zeros |
| resources/ui/policecam/policecam.xsf | 0x64CA3000 | ABSENT - zeros |
| resources/ui/raceeditor/raceeditor.xsf | 0x64CB0000 | ABSENT - zeros |

No other volume can hold those bytes (xarchive_audio.rpf is 1,615,757,312, smaller than
0x6496F000 = 1,687,353,344), so the 0x64... prefix is a cache-file offset inside the missing tail -
which corrects F-167's open inference that it was a volume selector.

**Why the placeholder exists.** MclaPreferredPkgOffForPath's "every .xsf -> 0xA0000" therefore points
the whole UI at the only .xsf package physically present (legals'). F-169's length fix makes those
paths carry 196,553 real legals bytes instead of 32,768 of them - more correct, still the wrong body
for four of five, and those four cannot be served at all until the file is whole.

**A second, independent blocker on the package that IS present.** Its payload is not deflate: every
plausible framing of +0x14..+0x2F was tried (length-then-data and data-only; raw windows -15/-12/15)
and nothing inflates. With 0x0FF512EF in the header and high entropy after it, the body is encrypted
or a codec we have not implemented - and XSF-INFLATE has fired 0 times today, so the guest is handed
container bytes and produces no tags (W32-CONSTRUCT-CENSUS nPtr=0, W34-NOGFX).

**Required action, stated as such.** Re-acquire xarchive_cache.rpf from the source and confirm it is
materialized through 0x7F008000 before any further menu work; the prime suspect is the recorded E:
volume trouble (2026-09-20 data loss, 2026-09-24 05:35 fsync failures), not a partial rip. Then
re-test: if the four packages appear, F-169's length fix becomes testable for real; if the payload
still will not inflate, the codec/keys question is the blocker and sub_821D5E10's inflate hook is
where to look.

### F-171: THE FIX (UI feed) - a container member is now served from the package its OWN TOC record names, validated by header magic + package ID, and the local archive has been replaced with a complete copy so all seven of those packages physically exist

- Task:    B5 (menu) - executes the action F-170 required and retires F-166's placeholder mapping as the primary selector
- Type:    FIX
- Class:   E
- Priority: P0 - it is the difference between the UI being fed one shared placeholder body and being fed its own body
- Evidence: `src/gpu_device.cpp:278` (`MclaPkgOffFromTocW2`), `:702`-`730` (candidate + validation + labelled fallback), `:310`/`:320` (`kPkgWindowMax`, `MclaRsc5DeclaredSize`); soaks `build/w180.log` and `build/w181.log` (same binary, 16:16/16:18); `build/game_data/xarchive_cache.rpf` = 2,130,739,200 bytes with `last_nonzero = 2,130,710,477`, truncated original kept beside it as `xarchive_cache.rpf.truncated-20260924`

**Two limits hid the offset, both now removed.** `MclaPkgOffFromTocW2` masked with `0x00FFF000`,
which is a 20-bit offset: `credits.xsf`'s word[2] `0x6496F01B` decoded to `0x96F000`, not
`0x6496F000`, so no package above 16 MB could ever be named. And it required membership in the
package table, which `BuildRscPackageTable` builds by scanning only `kScan = 0x2000000` from 0 - so
even a correct candidate was rejected for being outside the scan. Now `return w2 & 0xFFFFF000u;`
and the **caller** validates: an RSC5 magic at `pkg+0` **and** `[pkg+0x08] == record word[3]`.
That pair is what makes the unvalidated guess safe - a wrong offset cannot pass both, so there is
no need for a scan-bounded table at all.

**The archive is whole, and that is what made the fix testable.** F-170's required action was taken:
the local copy was replaced with a complete 2,130,739,200-byte copy from
`E:\MCLA-Standalone\game_data\xarchive_cache.rpf` (9.088 s copy; the old file is preserved, not
deleted). Re-measured offline, all seven UI/cache containers now carry an RSC5 header whose ID word
equals the TOC record's word[3]:

| package | offset | `[pkg+8]` ID | declared size (RSC5 +0x10) |
|---|---|---|---|
| legals.xsf | 0x000A0000 | D454283D | 196,553 |
| meshtextures.xtd | 0x00060000 | DC2C0810 | 240,531 |
| trash.xrn | 0x0035A000 | C0001814 | 10,799 |
| credits.xsf | 0x6496F000 | D4082813 | 29,655 |
| garage.xsf | 0x64980000 | D574B032 | 1,066,057 |
| policecam.xsf | 0x64CA3000 | D41D2810 | 19,337 |
| raceeditor.xsf | 0x64CB0000 | D4343015 | 143,069 |

**Measured at the draw-in (w180 and w181 are identical, so this is not the bimodality F-169 found):**
`PKG-SUBST` names **seven distinct packages** (00060000 ×5, 000A0000 ×37, 0035A000 ×5, 6496F000 ×3,
64980000 ×3, 64CA3000 ×3, 64CB0000 ×3) where before every `.xsf` received legals' body;
`XSF-BIND` per path is now the file's own declared length - credits 29,655 / garage 1,066,057 /
policecam 19,337 / raceeditor 143,069 - instead of all four at legals' 196,553.

**Frontier counters are unchanged or better, which is the point of a serve-path fix:**
`Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0`, `SEEK-DEAD 0`, `LISTLINE 171`, `GETDEV 694`,
`CP-DRAW 166`, `PRESENT 34`, `DICTLOOKUP 22`, `[error] 14`, `TYPINIT` entered/returned 3/3,
GFx 4→5. F-163's registration and F-169's length fix both survive; `DRAW_INDEXED` is still 0.

**What this does NOT fix - the remaining blocker on this route is the payload codec.** `XSF-INFLATE`
fires 0 times and `swfCMD` is 0, exactly as before, so the guest is still handed container bytes it
cannot turn into tags. That is now decidable offline against these seven whole packages with no soak
in the loop: start from the guest's own inflate entry `sub_821D5E10` and the
`0x0FF512EF` (XEX/Xcompress-family) magic at `RSC5+0x0C`. F-170 already recorded that every
plausible raw-deflate framing of `+0x14..+0x2F` fails to inflate.

**Open asymmetry, recorded rather than silently carried.** The read/continuation site
(`src/gpu_device.cpp:10032`-`10036`, `sub_821CC6F0` region) still consults
`MclaPreferredPkgOffForPath` **first** and falls back to `MclaPkgOffFromTocW2`, and it does no
magic/ID validation, so it can still bind a member to the substring-mapped package. The substring
map is now only a labelled fallback at the census site (`:730`
`// MITIGATION fallback (pre-F-171 substring map)`); retiring it at `:10032` is the follow-up, and
`CC6F0-PKGSUBST` lines are the instrument to watch when it is done.

### F-172: the UI containers are never inflated because the guest's own inflate loop is entered with a **byte count of 0** - every `XMem`/`INFLATE-ENTER` line at this frontier is our re-point machinery feeding it a bounce buffer whose address is a **semaphore handle**, so "the RSC5 payload will not decode" was never actually tested (read-site window hypothesis REFUTED, code reverted)

- Task:    B5 (menu) / B4's feed - the codec question F-170/F-171 left open; answers it
- Type:    FACT (root cause) + INFERENCE (what to fix) + a recorded refutation of my own prior hypothesis
- Class:   G (the game's coded behaviour) with a D/E component (what our device returns)
- Priority: P0 - it is the single blocker on the UI route, and it says the blocker is ours to remove, not a cipher
- Evidence: `build/w182.log` (new soak, binary `3584fca` + one reverted edit) lines 3972/3985/3990 and the `READWRAP`/`INFLATE-ENTER` pair; `generated/ppc_xenon/ppc_recomp.14.cpp:19040-19140` (`sub_821BC140`'s priming block and its `bl InflateBegin`); `ppc_recomp.18.cpp:10831`-ff (`sub_821D5E10` = `zlibInflater::InflateBegin`, register-accurate); `build/cache/mcla_pe.bin` strings `0x82015770`/`0x820157AC`/`0x820157D4`; `src/gpu_device.cpp:7067`-ff (the hook) and `:3646`-ff (its own comment)

**What the guest's own code requires, read off the generated listing.** `sub_821BC140` is the only
caller of `zlibInflater::InflateBegin` (`tools/ppc_xrefs.py calls 0x821D5E10` -> one site,
`0x821BC37C`). Its loop does:

```
r30 = [r28 + 4]                     // the byte count still to inflate
r31 = min(r30, 32768)               // 0x821BC2D4-0x821BC2DC: cmplwi r30,32768 / mr r31,r30
r3 = [r28+8] -> [[r3]+28](r3, r20, cursor@(r1+80), dst = r1+128, r7 = r31)   // device Read
if ([r27+1852] == 0 && r3 == r31) {          // ONLY on an exactly-full read
    [r1+96] = r3 - r29                        // inflater st+0  (remaining INPUT)
    [r1+100] = (r1+128) + r29                 // inflater st+4  (input pointer)
    cursor += r3
}
InflateBegin(r3 = r24, r4 = r1 + 96)          // the state is a STACK object
```
`InflateBegin` then requires `st+8 == 0`, compares `*st+4` against **`0x0FF512EF`**
(`lis r10,0FF5` + `ori r9,r10,12EF`, `ppc_recomp.18.cpp:10865`-ff) - failing that it prints
`zlibInflater::InflateBegin - not in XCompress format` - consumes 8 bytes (magic + size at src+4)
and calls `sub_8244FF20` = **XMemDecompress** (`XMemCreateDecompressionContext`, same string block).
So the RSC5 header's `+0x0C` magic / `+0x10` size pair is the XCompress sub-header, and the LZX
stream starts at **`pkg+0x14`**. The magic occurs exactly once per package in the archive, always at
`pkg+0x0C` (measured over each package's whole declared range), which confirms the framing.

**Why it never runs.** `READWRAP sub_821CC6F0 #1 ... r5=00060000 r6=006D8F40 r7=0 ... ret=00000000
lr=821BC334` - the read that feeds the inflate is asked for **`r7 = 0` bytes** (`r7` is the count,
`r6` the caller's stack destination), because `[r28+4]` is 0. An exactly-full read of zero still
satisfies `r3 == r31`, so the guest primes the stack state anyway and computes
`st+0 = 0 - 12 = 0xFFFFFFF4` and `st+4 = (r1+128) + 12 = 0x006D8F4C` - **which is exactly what
`INFLATE-ENTER #1 st=006D8F20 in=4294967284 inPtr=006D8F4C consumed=0` prints** (st = r1+96, and
`r1 = 006D8EC0` is visible in the same log as `r1in=`). Two independent derivations agreeing to the
dword: the count is 0 before we ever touch it.

**What our code then does with it.** `PPC_FUNC(sub_821D5E10)` (`src/gpu_device.cpp:7067`-ff)
re-points `st+0`/`st+4` at a host bounce whenever the magic is absent (its own comment at
`:3646`-ff calls this a short-circuit), and the resulting XMem calls are ours, with our constants:
every one of the 34 `XMEM` lines carries `srcSz=7179936 destSz=7179940`, the hard-coded
`j1SrcSz`/`j1DestSz` at `src/gpu_device.cpp:4322`-`4323`, and `ret=00000000`. The `src=` of the first
is `CA327114` - **`CA327100` is a semaphore** (`SEMA-CREATE #31 h=CA327100 init=0 max=32767`,
`PRELOAD-CTX #1 ... arcDev=CA327100`), so we are handing the guest's LZX decoder a kernel object's
memory and reading "XMem produced nothing" as a property of the archive. It is not.
**Consequence, stated plainly: F-091/F-102's "the only inflate door was reached and produced 0" and
F-170's "the payload is encrypted or an unimplemented codec" are both unsupported - the door was
never fed real bytes.**

**My own prior hypothesis, refuted in the same soak.** I changed the `sub_821CC6F0` read site to
(a) prefer the record's own validated package over the path-substring map (F-171's recorded open
item) and (b) size the bounce by the declared length. `w182` is **identical to `w181` on every
counter** (`LISTLINE 171`, `TYPINIT 3/3`, `Fatal 0`, `FATAL-SOFT 0`, `C0000005 0`, `SEEK-DEAD 0`,
`GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `DICTLOOKUP 22`, `[error] 14`, `INFLATE-ENTER 149`,
`XSF-INFLATE 0`, `swfCMD 0`, `DRAW_INDEXED 0`) - because **`CC6F0-PKGSUBST` and `CC6F0-PKGCONT` fire
0 times**, i.e. that substitution branch is dead at this frontier. So F-171's "open asymmetry" is
inert, the 32 KB read-window clamp is not what bounds the inflate, and the edit is reverted (tree
back to `3584fca`). The only durable product of that build is the negative result.

**The next step, named and bounded.** Find who is supposed to fill `[r28+4]` (the inflate byte
count) for a container member and why it is 0 while the TOC entry carries the right size
(`TOC76-LAYOUT` prints `+4=[0002FFDD 000A001B D454283D 0040626E]` for legals). `r28`'s `+8` is the
device and `+4` the count, and the census serve already publishes a size through
`XSF-POSTOPEN-SERVE`/the `CDE/Open (CCEA0)` wire at `src/gpu_device.cpp:800`-ff - so this is a
field-transfer question inside code we own, answerable by reading `sub_821BC140`'s entry block
(`r28`'s provenance) rather than by adding another instrument. When the count is real, the guest's
own `InflateBegin` will either decode (LZX works, UI follows) or print `not in XCompress format`
through its own path - **both are answers, and neither has ever been tried on real bytes.**

### F-173: the zero inflate count has a single, named source - `sub_82187150` is the ONLY caller of the streamer's request registrar and it calls it with a zero scalar twice per boot; `REQFILL` proves it with a census whose frontier delta is exactly zero

- Task:    B5 (menu) - continues F-172 up the same chain to its origin
- Type:    FACT (census) + correction of F-172's stated next step
- Class:   G
- Priority: P1 - it names the exact call to interrogate next, and retires one guess
- Evidence: `build/w183.log` (`REQFILL` x2, and all 17 frontier counters identical to `build/w182.log`); `src/gpu_device.cpp:8403`-ff (the census, registers-only); `generated/ppc_xenon/ppc_recomp.9.cpp:4565`-`4596` (the argument setup at `sub_82187150+0x1A8`); `tools/ppc_xrefs.py calls 0x821867A0` -> **1 site**; `tools/ppc_xrefs.py fn 0x821872FC` -> `sub_82187150 +0x1ac`; `ppc_recomp.14.cpp:18873`/`:18966` with no intervening write to `r28` (which is what re-confirms F-172's `[slot+4]` reading)

**The chain, end to end, each link cited.** `sub_821BC140` (our `INLINE-EXEC`) computes
`r28 = [0x8203D190+52] + [task+0] * 28` at `ppc_recomp.14.cpp:18873` and takes its transfer length
from `r30 = [r28+4]` at `:18966`, with **no write to `r28` in between** (checked over
`18860`-`18970`) - so F-172's claim that the count is a field of the 28-byte request slot stands, and
my own momentary doubt about it (the surface-size-looking arithmetic right after `:18966` reads
`[r28+8]`/`[r28+16]`, i.e. other fields of the same slot) is recorded here as resolved, not as a
retraction.

Who writes that slot? `sub_821867A0` - four `stw rT,4(entry)` sites after `mulli rN,rN,28`, all
inside it (`ppc_recomp.9.cpp:3029`, `:3222`, `:3273`, `:3568`), plus a branch that writes the
**literal 6** into `[entry+4]` when bit 1 of the request's own flags is set (`:3017`-`3022`,
`li r28,6` / `stw r28,4(r11)`). It has exactly **one** caller:

```
REQFILL sub_821867A0 #1 r3=8EFFF1E0 r4=8EFFF980 r5=00000000 r6=8EFFF170 r7=8EFFF178 -> r3=00000003 lr=821872FC
REQFILL sub_821867A0 #2 r3=8EFFF020 r4=8EFFF7D0 r5=00000000 r6=8EFFEFB0 r7=8EFFEFB8 -> r3=00000004 lr=821872FC
```
- It runs **twice per boot** and returns slot ids **3** and **4**; `REQDUMP #1`'s task carries
  `[task+0] = 4`, so the inflate loop reads the slot that `REQFILL #2` registered.
- Four of the five arguments are **stack pointers** (`0x8EFFFxxx`, and `r6`/`r7` are 8 bytes apart =
  two locals the callee writes back). `r5` is the only scalar, and it is **0** on both calls. At the
  call site `sub_82187150+0x1A8` (`ppc_recomp.9.cpp:4565`-`4596`) the same four are `r1+128/132/136`
  and `r1+224 + idx*28` - so `r5` is a computed value the caller decided, not an out-parameter.
- `sub_82187150`'s own callers are `0x8219F964`, `0x821A0E60`, `0x821A0FF4`, `0x821A1428`,
  `0x822EAD44` and **`0x822FBBA0`** - the last being inside `sub_822FBAF8`, whose
  `MSGBISECT 5-822FBAF8 RETURN` line is this project's marker for "the star_glow effect init
  completed" (PROGRAM_GUIDE §9). So the request registrar is reached from the same init/message
  chain the frontier already proves is running.

**Admissibility of the instrument (F-125/F-133 satisfied by measurement, not by claim).** `w183` vs
`w182`, matched-line counts: `LISTLINE 171/171`, `Fatal error 0/0`, `FATAL-SOFT 0/0`,
`C0000005 0/0`, `SEEK-DEAD 0/0`, `TYPINIT 6/6`, `GETDEV 694/694`, `CP-DRAW 166/166`, `PRESENT 34/34`,
`DICTLOOKUP 22/22`, `[error] 14/14`, `INFLATE-ENTER 149/149`, `XSF-INFLATE 0/0`, `swfCMD 0/0`,
`DRAW_INDEXED 0/0`, `INLINE-EXEC 3/3`, `PRELOAD-CTX 3/3`. The hook is registers-only by design (the
`ENQ sub_821BCB10` note at `src/gpu_device.cpp:8404`-ff records a census **in this same subsystem**
that AV'd its consumer by reading guest memory), so it stays.

**What is NOT claimed here.** That `r5` *is* the byte count. It is the only scalar at the call, and
the slot's `[+4]` is 0 whenever the streamer reads it, so it is the prime candidate - but the field
transfer inside `sub_821867A0` (which of its four `[entry+4]` stores runs, and from which input) is
not yet traced. The next step, named: read `sub_821867A0`'s body for the store that reaches
`[slot+4]` and match it to a register, then check that register's producer in
`sub_82187150+0x140`-`0x1AC`. Both are static reads of `generated/`, no build required.

**Also true and worth repeating:** the three streamer tasks per boot carry `{src, dst, size}` tables
in their own descriptors (`REQDUMP #1 a0=82849B2C d=[00000004 50000000 A47FD000 00002000 60000000
B7A01000 00080000 ...]` = 3-dword records `{virtual source, destination, size}`, sizes 0x2000 and
0x80000), so **the guest does know the lengths** - they simply do not reach the request slot.

### F-174: two corrections to the last two entries - the streamer control block is `0x8283D190` (not `0x8203D190`; `lis` immediate sign), and `sub_821867A0` is NOT the writer of the zero-count slot (supersedes F-173's mechanism, keeps its facts)

- Task:    B5 (menu) - self-correction of F-172's cited address and F-173's stated writer
- Type:    FACT (correction) - the F-172 *conclusion* survives, the F-173 *mechanism* does not
- Class:   H (an attribution artifact of mine, caught statically, before it cost a build)
- Priority: P1 - so nobody builds a fix on the wrong function
- Evidence: `generated/ppc_xenon/ppc_recomp.14.cpp` prologue of `sub_821BC140` (`lis r10,-32124` ->
  `-2105278464` = `0x82840000`; `addi r19,r10,-11888` -> **`0x8283D190`**);
  `tools/ppc_xrefs.py xref 0x8283D190` (5 sites) and `xref 0x8283D1C4` (1 site);
  `ppc_recomp.9.cpp:2902`-`3620` (every store base inside `sub_821867A0` derives from `r22 = r3`) and
  `ppc_recomp.9.cpp:4565`-`4596` (the sole caller passes `addi r3,r1,224` + `mulli r11,r30,28`)

**1. The address in F-172 was mis-signed.** I computed the control block as `0x8203D190` by taking
`-32124 << 16` wrongly; the generated listing's own value is `-2105278464` = `0x82840000`, so
`r19 = 0x82840000 - 0x2E70` = **`0x8283D190`**, the request-array base is at `[0x8283D1C4]` and the
capacity-minus-one mask at `[0x8283D1A8]`. Everything else in F-172 is unaffected: the length the
inflate loop uses is still `[r28+4]` with `r28 = [r19+52] + [task+0]*28`, it is still 0, and the
`r7=0` / `st+0=-12` / `st+4=stack+12` arithmetic match still holds. Same lesson as F-157's phantom
`0x82861740`, caught here before a build instead of after three.

**2. F-173's writer claim is withdrawn.** `sub_821867A0` fills whatever 28-byte array it is *handed*:
inside it every store base is `r22 = r3` or `idx*28 + r22`, and its one call site
(`sub_82187150+0x1A8`) passes `r1 + 224 + idx*28` - a **caller-local buffer**, confirmed by the
`REQFILL` log itself (`r3=8EFFF1E0`, `r6/r7` 8 bytes apart in the same frame). So the `r5 = 0` it
passes is **not** the origin of the zero `[slot+4]` that `sub_821BC140` reads. The census facts stand
(2 firings/boot, returns ids 3 and 4, single caller, registers-only with a zero frontier delta) and
`REQFILL` stays in the tree as a bound on what that function does - but PROGRAM_GUIDE's `REQFILL` row
must not be read as "the registrar of the streamer's request pool".

**3. What the corrected neighborhood actually is.** Only five sites materialise `0x8283D190`:
`sub_821BC140+0x24` (the inflate executor), three reads inside `sub_821BC6xx`
(`0x821BC674`/`680`/`694`), and `sub_821BCB10+0x44` (the enqueue-chooser our `ENQ` census already
watches). Exactly one site materialises the array base `[0x8283D1C4]`: **`sub_821BCE68+0x2C`**, which
is not hooked. So the manager is small and closed, and the question "who allocates and fills the
request array, and who should set a slot's `[+4]`" now has a single named starting point:
`sub_821BCE68` (and the three reads at `0x821BC674`-`0x821BC694`, which are in the same page of code
as the inflate loop and may be its completion path). Static reading of those, not another instrument.

### F-175: the subsystem has a name - `sub_821BCE68` is **`pgStreamer::Open`** and it is the only code that indexes the handle array whose `[+4]` the inflate loop reads, so "who sets the length" now has one address to interrogate

- Task:    B5 (menu) - terminates the F-172/F-174 chain at a named owner
- Type:    FACT (static, from the guest's own assert strings)
- Class:   G
- Priority: P1 - the next experiment is one registers-only census here, or a pure read of this body
- Evidence: `build/cache/mcla_pe.bin` strings `0x82010FF0` = `pgStreamer::Open - out of handles` and
  `0x82011014` = `You forgot to call pgStreamer::InitClass.`, both referenced from
  `sub_821BCE68` (`generated/ppc_xenon/ppc_recomp.14.cpp`, `PPC_FUNC_IMPL(__imp__sub_821BCE68)`;
  `addi r3,r11,4080` / `addi r3,r11,4116` with `lis r11,-32255` = `0x82010000`); the control-block
  addresses decode from the raw immediates: `lis -32124` = `0x82840000`, so `addi -11888` ->
  **`0x8283D190`** (the class static `sub_821BC140`/`sub_821BCB10` use), `addi -11836` ->
  **`0x8283D1C4`** (= that static `+0x34`, the handle-array base `pgStreamer::Open` reads), and
  `addi -11804` -> `0x8283D1E4` (the lock/mutex member passed to `sub_821C8FE0`).

`ppc_xrefs.py xref 0x8283D1C4` returns exactly one site, `sub_821BCE68+0x2C`, and `xref 0x8283D190`
returns five, all inside `sub_821BC140` / `sub_821BC674`-`0x821BC694` / `sub_821BCB10`. So the
`pgStreamer` class static and its handle array have one allocator-side door and a handful of
consumers, and **the door is the function that would record a request's length**: it asserts if the
class was never initialised, and it reports `out of handles`, which is allocator behaviour. The
`sub_821BC674`-`0x821BC694` reads sit in the same page of code as the inflate loop and are its most
likely completion path.

Consequences for the plan, stated plainly:
1. F-172's blocker is now `pgStreamer`-shaped, not codec-shaped. The guest's LZX decoder
   (`sub_8244FF20` = XMemDecompress, reachable through `zlibInflater::InflateBegin`) is in the image
   and the container framing is understood (`RSC5 +0x0C` magic, `+0x10` length, stream at `+0x14`);
   what is missing is a streamer request whose `[+4]` is non-zero.
2. The next move is one of two, both cheap: read `sub_821BCE68`'s body to see which field it writes
   from which argument (static, no build), or census it registers-only at `0x821BCE68` - it is
   currently **un-owned** (checked with `addr_owners`/grep; `sub_821BC140` is already ours, so a hook
   there would need rule 4 re-checked).
3. Do not re-attach the "encrypted payload" or "host needs an LZX implementation" ideas: the guest
   carries the decoder, so a correctly-lengthed request is all that is missing. If a correctly
   lengthed request still yields no tags, *that* is the point at which the container itself is in
   question - and it has never been reached.


**Addendum to F-175, same session (2026-09-24 ~17:30) - stated precisely, because the headline above
over-reaches.** Reading the rest of `pgStreamer::Open`'s body
(`ppc_recomp.14.cpp`, the span after the `InitClass` assert): it does **not** demonstrably write the
consumer's array. What it actually does is

```
lwz  r11,0(r24)          // r24 = 0x8283D1A4  -> loads [0x8283D1A4], NOT [0x8283D1C4]
mulli r10,r10,28
add  r29,r10,r11         // r29 = a 28-byte record in the array based at [0x8283D1A4]
stw  r25,16(r29)         // r25 = 0
...  helper calls at 0x823DD800 / 0x823DD7F0 / 0x823DD850 on r30 (= its name-ish arg,
     and on r30+6, and with a length cap of 44) - CRT-region addresses, name/string work
stw  r25,8(r29); stw r25,20(r29); stw r11,4(r29)   // r11 = (helper result) + r31
```
So the correct statements are: (a) `Open` computes the **address** `0x8283D1C4` (which is the field
`sub_821BC140` reads its array base from) and separately indexes a 28-byte array through the
*neighbouring* field `0x8283D1A4` - the two are 0x30 apart in the same `pgStreamer` class static;
(b) the value it puts in `[record+4]` is built from string helpers applied to its argument, which is
**not** the shape of a byte count; and (c) therefore `Open` is a strong candidate for the *owner and
initialiser* of the handle arrays (consistent with the `pgStreamer::InitClass` assert and the
`out of handles` message), but it is **not** established as the writer of the specific field the
inflate loop consumes.

Why the field is nevertheless certainly a count *at the consumer*: `sub_821BC140` loads
`r30 = [r28+4]` (`ppc_recomp.14.cpp:18967`), clamps it (`cmplwi r30,32768`), and passes the clamp as
the device Read's count argument (`r7 = r31`, indirect call at `0x821BC334`) - and **no write to `r28`
occurs between `:18873` (where it is formed) and `:19052`**, re-checked over that whole span, not just
part of it. The measured consequence in `w182` is the 0-byte read with `lr=821BC334`, so the field's
*role* is proven by the log even while its *writer* is still unnamed.

Corrected next step, still static and still one address wide: find what stores into
`[0x8283D1C4]` (the array-base field) and what writes `[record+4]` in **that** array - i.e. trace the
users of the base rather than assuming `Open` is one. `xref 0x8283D1C4` gives the single computation
site above, so the search is for stores through pointers derived from it, which means reading
`sub_821BC674`-`sub_821BC694` (the three reads of the class static that sit inside the same function
family as the inflate loop) and `sub_821BCB10+0x44` (our `ENQ` chooser). If neither writes it, the
array is filled by `pgStreamer::InitClass` sizing plus a per-request insert elsewhere, and a
registers-only census at `sub_821BC140`'s *caller* (`sub_821BC910`, the enqueue path that produced
`INLINE-EXEC #n`) is the cheapest admissible way to see the request as it is handed over.

### F-176: the handle id that selects the zero-length record is the value `sub_821867A0` returned - `REQFILL #2 -> r3=00000004` and `ENQ a0=00000004` / `REQDUMP d[0]=00000004` are the same number, so F-173's builder and F-172's zero are now joined by a measured identity, not by an inferred field path

- Task:    B5 (menu) - continues F-174/F-175's static trace and fixes what is and is not known
- Type:    FACT (three-way log identity) + FACT (listing-derived structure) + an explicit open question
- Class:   G
- Priority: P1
- Evidence: `build/w183.log`: `REQFILL sub_821867A0 #2 … -> r3=00000004`, `ENQ sub_821BCB10 #1 a0=00000004 cb=821BC548 -> r3=82849B2C`, `REQDUMP #1 a0=82849B2C d=[00000004 …]`, `INLINE-EXEC sub_821BC140 #1 a0=82849B2C`; `generated/ppc_xenon/ppc_recomp.14.cpp` (`sub_821BC910` body, `sub_821BCB10` prologue, `sub_821BC140+0x24`)

**The queue record is 1556 bytes, confirmed from the listing.** `sub_821BC910` computes
`r31 = instance*24948 + <static base>`, then `r30 = r31 + ([r31+24932] * 1556)`, and calls
`sub_821BC140(r3 = r30, r4 = instance)` **only when `[r30+1548] != 0`**. So the request the inflate
loop executes is a 1556-byte (0x614) queue slot - which is what Session 75n's `REQDUMP` comment
asserted from the other direction, and it is why `d[0]` of that dump is the value `sub_821BC140`
multiplies by 28. The ring head at `[r31+24932]` wraps at **16** (`cmpwi r11,16`), so this queue holds
sixteen outstanding requests, and the three `INLINE-EXEC` firings correspond to three `ENQ` firings
whose `a0` values are `4`, `0x8004`, `0x10004`.

**The identity.** `sub_821BCB10` (`ENQ`, registers-only, 3 firings) takes those values as its first
argument and returns the queue object; `sub_821BC140` then uses the same low half (`4`) as its
handle index; and `REQFILL` records that `sub_821867A0`'s **second** call returned exactly
`r3 = 00000004`. So the number that selects the record whose `[+4]` is 0 is the number that
`sub_821867A0` handed back. That is a measured three-way match across `REQFILL` / `ENQ` / `REQDUMP`,
not an inferred field path, and it is the strongest link so far between the builder and the zero.

**What is still NOT known, stated so nobody over-reads this.** `sub_821BCB10` only *searches* the
`[0x8283D1C4]`-based 28-byte array (`mulli r11,r30,28` / `lwzx r9,r11,r26` / compare against
`record+0`), and `sub_821867A0` writes the record array it is *handed* (F-174). Whether the builder's
local record is then copied into the global pool - which the matching id would suggest - is not
established, and neither is the store that would put a **length** rather than the string-derived value
seen in `pgStreamer::Open` into `[global record+4]`. The two candidate next reads, both static:
(a) the tail of `sub_821867A0` after its four `[entry+4]` stores, looking for a copy loop into a
pool whose base comes from `[0x8283D1C4]`; (b) `sub_821BC674`-`0x821BC694`, the three reads of the
same class static inside the inflate family, which are the most likely completion path that would
*advance* a record's `[+4]` as bytes are consumed.

**Plan state unchanged by this entry:** B1/B2/B3 closed; B4's gate `DRAW_INDEXED >= 1` unmet
(still 0 in `w182`/`w183`); B5 criteria 1-2 unmet, criterion 3 met. What changed is the shape of the
remaining work: the UI route is a streamer-request question with a named identity chain, and the
"implement a host LZX decoder"/"find the key" framings are withdrawn (F-172).

### F-177: the zero inflate length is produced by a **vtable slot we never implemented** - `pgStreamer::Open` sets `record.length := obj->vtable[+84](obj)`, and slot +84 of the `memory:` device is the shared stub `0x821A5CC0` that 13 other slots also point at

- Task:    B5 (menu) - the root cause F-172 named and F-176 narrowed
- Type:    FACT (census + static derivation)
- Class:   C (guest ABI/vtable slot) with an E component (what our device answers)
- Priority: P0
- Evidence: `build/w185.log` (`STREAM-OPEN` x7; all 17 frontier counters identical to
  `build/w183.log`, incl. `READWRAP 278/278` and `INFLATE-ENTER 149/149`, so the census is
  admissible); `generated/ppc_xenon/ppc_recomp.14.cpp:21190`-`21250` (the store in
  `sub_821BCE68`); `ppc_recomp.17.cpp:1016`-ff (`sub_821CB488`); raw vtable words at
  `0x82012918` in `build/cache/mcla_pe.bin`; string `memory:` at `0x820127D8`

**`pgStreamer::Open`'s length store, verbatim from the listing** (`sub_821BCE68`, +0x13C..+0x170):
```
lwz  r10,-11824(r11)     // [0x8283D1F0] = a factory fnptr registered at InitClass
mtctr r11 ; bctrl        // call it with r3 = local -> creates the stream
bl 0x821cb488 (r3=local, r4=1) -> r31 = the OBJECT
stw  r31,8(r29)          // record+8  = object
lwz  r11,0(r31)          // its vtable
lwz  r10,84(r11)         // ★ slot +84
mtctr r10 ; bctrl        // obj->vt[+84](obj)
stw  r3,4(r29)           // ★ record+4 = that call's return  == the length BC140 reads
```
`sub_821BC140`'s `r30 = [record+4]` (F-172) is therefore **whatever slot +84 returns**, and
`sub_821BCB10` only searches these records by `record[0]` (F-176), so nothing else writes the field.

**Measured: `Open` runs, seven times, and the lengths are 0.** `w185`:
```
#1 r3=8EFFF770 r4=8EFFF760 r5=0000001B -> r3=00000000 lr=821E29C4
#2 .. r5=0000001B -> r3=00000001      #3 .. r5=0000001B -> r3=00000002
#4 .. r5=0000001B -> r3=00000003      #5 r3=8EFFEEB0 r4=0 r5=00000009 -> r3=00000004
#6 r3=8EFFEFD0 r4=0 r5=0000001B -> r3=00008004      #7 r3=8EFFEDC0 r4=0 r5=00001542 -> r3=0010004
```
`r3` on return is the handle id, and the executed requests carry `record[0] = 4`, `0x8004`,
`0x10004` (`REQDUMP d[0]`, F-176) - so **these three Opens are the ones the inflate loop consumes**,
and the loop then reads their `record+4` as 0.

**`r5` settles the RSC5 header argument for free.** The seven `r5` values are
`27, 27, 27, 27, 9, 27, 5442` = exactly the `+0x04` word of the seven RSC5 packages measured
offline (`legals/credits/garage/policecam/raceeditor` 27, `meshtextures.xtd` 9, `trash.xrn` 5442), and
`#5`'s `r5=9` pairs with the `READWRAP … r5=00060000` cursor that F-172 saw for meshtextures. So the
guest parses `RSC5+0x04` and hands it to `pgStreamer::Open` as a parameter - it is **not** a header
length in the "bytes of header" sense F-168 guessed; whatever it selects, the guest agrees with our
offline reading of the field, which independently validates F-171's package selection.

**Why slot +84 answers nothing.** `sub_821CB488(name, 1)` compares the first 7 characters against
`"memory:"` (string at `0x820127D8`) and on a match returns `0x827D838C` - `kMemDeviceObj`, the
device **whose vtable we install** (`kMemVtable = 0x82012918`). The raw vtable words are:
```
+0 AE50  +4 AFB8  +44 CB2A0 (Close)  +56 CABB8 (GetSize)  +80 CB400  +108 CB480  +116 CAC38
+8 249B538   +12/+28 82762480   +128 82130000
+48,+60,+64,+68,+72,+76,+84,+88,+96,+104,+112,+124  all = 0x821A5CC0   ← one shared stub
```
So slot +84 is one of **thirteen** slots pointing at the same function `0x821A5CC0` - the image's
"unimplemented virtual" thunk. If the object is the memory device, `record.length` is that stub's
return value, which is what F-172 measured as 0 and F-173/174 chased through the wrong array.

**Consequences, stated without over-reach.** (a) The UI/menu blocker is now a *missing device
capability* - answer `vt+84` on the stream object with the real size and the request gets a length,
the guest's own `InflateBegin`/XMem path gets bytes, and `swfCMD`/`XSF-INFLATE` become testable.
(b) It is NOT yet proven that the seven Opens took the `memory:` branch nor that
`0x821A5CC0` returns 0 - both are one registers-only census away: `sub_821CB488`
(`r3` = name pointer, `r4` = flag, `-> r3` = the object) and, if needed, `sub_821A5CC0` capped and
deduped by `lr` because it is a shared stub any vtable miss can reach. (c) Whatever the answer, the
fix belongs in the device vtable, not in the archive serve path - F-169/F-171 already made the
served bytes whole.

## Continuation, same session - the two devices differ at exactly this slot, and our own override is what forces the zero

Reading the two device vtables side by side from `build/cache/mcla_pe.bin` (rule 3, raw words):

| slot | packfile/archive device `0x82012BDC` | `memory:` device `0x82012918` |
|---|---|---|
| +44 | `821CD400` | `821CB2A0` (Close, the routine F-160 uses) |
| +56 | `821CD3C8` (GetSize -> `[tocEntry+4]`) | `821CABB8` |
| **+80** | **`821A5CC0` = the no-op stub** | `821CB400` (real) |
| **+84** | **`821CC498` (real)** | **`821A5CC0` = the no-op stub** |
| +88 | `821CC410` (`ld r3,16(r3); blr`) | `821A5CC0` |
| +124 | `82656BF8` | `821A5CC0` |

`sub_821CC498` decodes to `r10=[dev+0]; r11=[dev+36]; r4=r11+r4; call [r10+144](r3,r4)` - a real
sized query on the inner file object, and `pgStreamer::Open` stores **its** return into `record+4`.
The memory device answers the same slot with `sub_821A5CC0`, which is `li r3,0; blr` (4 bytes,
verified from the image). **So the archive device can supply the length and the `memory:` device
structurally cannot.**

And we make it worse: `src/gpu_device.cpp:12642`-`12646` is a **strong override of that stub** -
`PPC_FUNC(sub_821A5CC0) { ctx.r3.u32 = 0; }` with no chain to `__imp__` - installed because
`sub_8218C760` called `device+88` after GETDEV and AV'd on a null slot. It pins **all thirteen**
slots that share the stub to 0, including the archive-relevant `+84` on the `memory:` device.
Separately, our `sub_821CB488` (= `fiDevice::GetDevice`, per the Session 76j census comment at
`src/gpu_device.cpp:10990`-ff) is documented in-code as "return the memory device so the vtable+88
no-op can run" (`:10992`-`10994`) - i.e. we route some opens at the device whose +84 is a zero.

**Root cause, stated as one sentence:** `pgStreamer::Open` asks the stream's device for its size via
`vtable[+84]`; for the `memory:` device (which our own `GetDevice` override hands out, and whose
names genuinely start with `"memory:"` per the guest's own `strncmp(name, "memory:", 7)` at
`sub_821CB488+0x14`) that slot is the shared `li r3,0` stub which we additionally force to 0, so
`record.length = 0`, so the inflate loop issues a 0-byte read, so nothing ever reaches the guest's
working XMem/LZX decoder.

**Fix design (this is an implementation, not a mitigation, and is testable in one build):** give the
memory device a real `+84`. It cannot be done inside `sub_821A5CC0` (thirteen slots share it and the
address carries no information), so the options are (a) install a distinct function pointer at
`kMemVtable + 84` (`0x82012918+84`) that returns the served body's size for the handle the stream
carries - `MakeMemoryStream` already knows `{buf,size}` and `XSF-BIND` already publishes the same
number; or (b) stop handing the memory device to opens that name an archive member. (a) is the
smaller change and does not disturb F-163's re-open path. Pre-declared success criterion for F-178:
`READWRAP` with `r7=0 lr=821BC334` becomes a non-zero count, `INFLATE-ENTER`'s `st+0` stops being
`0xFFFFFFF4`, `XMEM` calls appear with per-file sizes instead of our constant 7,179,936, and only
then `swfCMD`/`XSF-INFLATE` become meaningful. Revert if `LISTLINE`/`C0000005`/`SEEK-DEAD` regress.

### F-178: F-177's last step is REFUTED by measurement - `pgStreamer::Open`'s vtable call never reaches the pinned `li r3,0` stub (its four callers are elsewhere), and this soak also proves `INFLATE-ENTER`/`READWRAP` are **timed-spin counters** that must not be used as frontier evidence

- Task:    B5 (menu) - tests F-177's inference and retires it; corrects the admissibility method used in F-173/F-177
- Type:    FACT (refutation) + FACT (measurement hazard)
- Class:   H
- Priority: P1
- Evidence: `build/w186.log` (`STUB-SLOT` 18 lines, `STREAM-OPEN` 7) vs `build/w185.log`;
  raw vtable words at `0x82012BDC`/`0x82012918` in `build/cache/mcla_pe.bin`;
  `generated/ppc_xenon/ppc_recomp.14.cpp:21231`-`21241`; `src/gpu_device.cpp:12642`-ff (the stub
  override, now with the `STUB-SLOT` tally), `:11141`-ff (the `+144` hook)

**What was predicted.** F-177 argued: `Open` stores `dev->vt[+84](dev)` into `record.length`; the
`memory:` device's `+84` is the shared `li r3,0; blr` stub at `0x821A5CC0`; and we additionally pin
that stub to 0, so the length is 0 by our own hand.

**What was measured.** A per-`lr` tally inside the stub (`STUB-SLOT`, one line per new caller, cap
16, first 12 calls) shows **exactly four distinct call sites per boot**:
```
#1 lr=8217784C r3=82008F3C r4=A00011CC r5=00000040
#2 lr=8218C82C r3=827D838C r4=C81E0A80 r5=0000000A     ← the sub_8218C760 device+88 case the override was built for
#3 lr=821BE67C r3=827D838C r4=00000001 r5=0000000C     ← BE8D8/BE610 family
#4 lr=82177EF8 r3=82830B18 r4=000002D0 r5=00000001     ← hot (the remaining ~1754 calls)
```
**None of them is inside `sub_821BCE68` (0x821BCE68..~0x821BD094).** So `Open`'s `+84` call does not
land on the stub, and F-177's "the zero is our pinned no-op" conclusion is **wrong**. The inference
was reasonable and the *store site* it rests on (`stw r3,4(r29)` after `lwz r10,84(r11)`) is still
correct - only the claim about which function answers slot +84 failed.

**What the archive device's +84 actually is.** `0x82012BDC+84 = 0x821CC498` decodes to
`r10=[dev+0]; r11=[dev+36]; r4=r11+r4; call [r10+144](dev, r4)` - i.e. it forwards to **slot +144
with a name pointer built as `[dev+36] + arg`**, and slot +144 of that vtable is `0x821CBFC0` - the
packfile TOC lookup we already hook (`src/gpu_device.cpp:11141`-ff, whose `TOC76`/`TOC76-XSF` census
prints `ret=C60B7B20` = **a TOC entry pointer**). So `record+4` is fed by that lookup, and its value
in the executed records is 0 either because the name at `[dev+36]+arg` doesn't resolve on this
device, or because the field is a union that another phase overwrites. **That is the open question
now, and it is one careful read of `sub_821BCE68`+0x100..+0x180 (which value reaches the `+84` call's
`r4`) plus one `TOC76` line correlation - not another instrument.**

**The method correction, which costs nothing to keep.** `w186` vs `w185`: all 17 *structural*
counters are identical (`LISTLINE 171`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0`, `SEEK-DEAD 0`,
`TYPINIT 6`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `DICTLOOKUP 22`, `[error] 14`,
`STREAM-OPEN 7`, `DRAW_INDEXED 0`) - but `INFLATE-ENTER 149 → 82` and `READWRAP 278 → 138`. Those two
count the *same repeating spin* whose iteration count depends on how much wall-clock the 120 s timeout
allows, so a per-line logging footprint changes them **without changing guest progress**. Therefore:
- `INFLATE-ENTER` and `READWRAP` are **not** admissibility evidence and not progress evidence. They join
  `INFLATE`, `fatal`-substring and `nValidTag` on the run-unstable list (F-169/F-164).
- F-173's and F-177's admissibility claims were built partly on them. Those claims still hold because
  the *structural* counters also matched in both cases - but the method was wrong and is corrected here.

**Both censuses stay** (`STREAM-OPEN`, `STUB-SLOT`): each is registers-only/`lr`-keyed, bounded, and
shows zero delta on the structural frontier. `STUB-SLOT` is the only instrument that names which
vtable misses the stub is actually absorbing, which is what the eventual `+84` implementation has to
avoid breaking.

### F-179: `pgStreamer::Open` succeeds for all seven UI containers and `record+4` is a TOC **entry pointer**, not a length - so F-172's attribution of the zero to `[record+4]` is also wrong; the real byte counter is `sub_821BC140`'s `r21`, and the `cmplwi r30,32768` I read as a clamp is the branch that *selects* `r21`

- Task:    B5 (menu) - supersedes part of F-172 and completes F-177/F-178's test
- Type:    FACT (correction + measurement)
- Class:   H
- Priority: P0 - the previous two entries' "next step" was aimed at the wrong field
- Evidence: `build/w186.log` lines 3609-4192 + 16917 (seven `TOC76`/`TOC76-RET`/`TOC76-XSF` triples
  with `lr=821CC4BC`), `build/cache/mcla_pe.bin` decode at `0x821CC4B8` (`bctrl`) /
  `0x821CC4BC` (`cmpli cr6,r3,0`) - the return point inside `sub_821CC498`, the archive device's
  vtable+84; `generated/ppc_xenon/ppc_recomp.14.cpp:19040`-`19060`

**The path is alive and it works.** `sub_821BC140`'s `+84` question forwards (through
`sub_821CC498` → device slot `+144` = `sub_821CBFC0`) into the packfile TOC lookup, and **all seven**
`RSC5` containers resolve there - exactly matching `STREAM-OPEN`'s seven firings:

| path | `TOC76-RET` | record words | `openGateBit30` |
|---|---|---|---|
| `resources/ui/raceeditor/raceeditor.xsf` | `C60BF0F0` | `221B297A 00022EDD 64CB001B D4343015` | 1 |
| `resources/ui/garage/garage.xsf` | `C60BF0A0` | `FCC35320 00104449 6498001B D574B032` | 1 |
| `resources/ui/policecam/policecam.xsf` | `C60BF0D0` | `D7F64D61 00004B89 64CA301B D41D2810` | 1 |
| `resources/ui/credits/credits.xsf` | `C60BF070` | `02313636 000073D7 6496F01B D4082813` | 1 |
| `resources/ui/meshtextures.xtd` | `C60B7970` | `0597F7BB 0003AB93 00060009 DC2C0810` | 0 |
| `resources/ui/legals/legals.xsf` | `C60B7B20` | `260847AB 0002FFC9 000A001B D454283D` | 0 |
| `resources/city/SC/trash.xrn` | `C60C03D0` | `AD0A8B94 00002A2F 0035A042 C0001814` | 0 |

Three independent confirmations in one table: the sizes are the F-168/F-171 declared lengths
(`00022EDD` = 143,069; `00104449` = 1,066,057; `00004B89` = 19,337; `000073D7` = 29,655), the package
words are the F-171 per-record offsets (`64CB001B` → `0x64CB0000`), and **every lookup returned a
non-null entry pointer**. So `record+4` = that pointer, and F-177/F-178's search for "who zeroes
`record+4`" was aimed at a field that is not a counter.

**What that means for F-172's model.** `sub_821BC140` does
```
lwz r30,4(r28)            ; r30 = record+4 = a TOC ENTRY POINTER (non-null, per the table)
mr  r31,r21               ; candidate count = r21
cmplwi r30,32768
bge  loc_821BC2F0         ; pointer >= 32768  → KEEP r31 = r21      ← this is the taken branch
mr  r31,r30               ; (else the small value would be the count)
...
r7 = r31 → device Read(dst = r1+128, count = r7)
```
I read the comparison as a clamp of `[record+4]` and concluded the length came from that field. In
fact the comparison *dispatches on the field's type* (pointer vs count), and because the entry
pointer is always ≥ 0x10000, **the count is `r21`** - so `READWRAP … r7 = 0` means **`r21 == 0`**.
The rest of F-172 survives: the 0-byte read is measured, and the derived `st+0 = 0xFFFFFFF4` /
`st+4 = stack+12` arithmetic still explains `INFLATE-ENTER #1` exactly.

**Also confirmed by this table:** the four UI `.xsf` entries carry `openGateBit30=1` while
`legals`/`meshtextures`/`trash` carry 0 - the bit our `XSF-OPEN-GATE-SKIPPED` mitigation exists
around - and `r5` in `STREAM-OPEN` (27/9/5442) equals each package's `+0x04` word, so the guest reads
that field and hands it to Open as a parameter.

**Corrected next step (static, one function, no instrument).** Trace `r21` in
`sub_821BC140`'s prologue (`ppc_recomp.14.cpp:18805`-`19040`) to its source field in the 1556-byte
queue record. `REQDUMP #1` shows that record's `{src, dst, size}` triples carry non-zero sizes
(`50000000 A47FD000 00002000`, then `… 00080000`), so either `r21` is a *cursor* that was already
advanced past the end, or it is a per-stream remainder the completion path never seeded. Whichever it
is, the fix lands in what we hand the streamer, not in the container and not in a vtable stub.

### F-180: measured at last - the streamer record is one slot at `C9A24970`, `record[+4]` really is a byte count (240,531 / 10,799), and it is **0 on the legals request**; F-179's reversal was wrong and F-172's mechanism is restored, now with the record's full field layout

- Task:    B5 (menu) - settles F-172 vs F-179 by reading the record instead of inferring it
- Type:    FACT (direct measurement) + correction of F-179
- Class:   G
- Priority: P0
- Evidence: `build/w187.log` `BC140-REC #1..#3` (exe 97,570,304 @ 17:53; **16 structural counters
  identical to `build/w186.log`** - `LISTLINE 171`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0`,
  `SEEK-DEAD 0`, `TYPINIT 6`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `DICTLOOKUP 22`,
  `[error] 14`, `STREAM-OPEN 7`, `INLINE-EXEC 3`, `swfCMD 0`, `XSF-INFLATE 0`, `DRAW_INDEXED 0` - so
  the two-checked-read census is free); `src/gpu_device.cpp` `PPC_FUNC(sub_821BC140)` `BC140-REC`
  block; cross-checked against the F-179 table in the same log

**The three rows** (base = `[[0x8283D190+52]]` = `C9A24900`, capacity 0x8000, `mask = cap-1 = 0x7FFF`):
```
#1 slot=82849B2C id=00000004 rec=C9A24970 [00000004 0003AB93 C60AC180 00000001 DC2C0810 000000C0 00060000]
#2 slot=8284A140 id=00008004 rec=C9A24970 [00010004 00000000 C60AC180 00000004 D454283D 00000140 000A0000]
#3 slot=8284A754 id=00010004 rec=C9A24970 [00010004 00002A2F C60AC180 00000001 C0001814 000006B4 0035A000]
```
`rec` is the **same address every time** - all three ids reduce to index 4 (`id & 0x7FFF`), and the
high bits are a generation counter (`4`, `0x8004`, `0x10004` = index 4, generations 0/1/2). So this
ring reuses one record, and the record's own fields identify which container it currently describes:

| field | #1 | #2 | #3 | meaning, cross-checked |
|---|---|---|---|---|
| `+0` | `00000004` | `00010004` | `00010004` | index 4 + generation in bits 15+ |
| **+4** | **`0003AB93` = 240,531** | **`00000000`** | **`00002A2F` = 10,799** | **the byte count** - equals the `RSC5+0x10`/TOC size of `meshtextures.xtd` and `trash.xrn` |
| `+8` | `C60AC180` | `C60AC180` | `C60AC180` | the packfile device (`GETDEV-RET ret=`) |
| `+12` | `1` | **`4`** | `1` | differs exactly on the zero-length request |
| `+16` | `DC2C0810` | `D454283D` | `C0001814` | the package IDs of meshtextures / **legals** / trash (TOC word[3]) |
| `+20` | `C0` | `140` | `6B4` | entry-relative offset (`C60B7B20-legals` is one of these entries) |
| `+24` | `00060000` | `000A0000` | `0035A000` | the package offsets F-171 selects per record |

**What this decides.** (a) F-172 was right: `sub_821BC140` takes its length from `record[+4]`, the
`cmplwi r30,32768` test is a magnitude test on that count, and a **0** there is exactly what produces
`READWRAP … r7=0 lr=821BC334`. (b) F-179's inference ("it must be a TOC entry pointer, so F-172 was
wrong") is **withdrawn** - the entry pointer is what the lookup *returns elsewhere*; this field is a
count. (c) F-175/F-177's suspicion that `pgStreamer::Open` fills this array is now confirmed: the
record at index 4 is `C9A24900 + 4*28`, and its `+4`/`+16`/`+24` are precisely the values Open's
`vt[+84]` and its package words carry.

**The bug, narrowed to one request.** Two of the three generations get the correct size; the
**legals** generation gets `+4 = 0` (with `+12 = 4` instead of 1) even though the same log shows
legals resolving through the same path at `lr=821CC4BC` with entry `C60B7B20` and size word
`0002FFC9` = 196,553. So the archive is fine, the TOC is fine, the vtable path is fine - one specific
Open leaves its record's length at 0, and because the ring reuses index 4, the request that carries
the boot's first screen executes with a zero-length read and then spins.

**Next measurement, already scoped and cheap.** Extend the `STREAM-OPEN` census with two checked
reads of `[0x8283D190+52] + (returnedId & 0x7FFF)*28` and print `record[+4]`/`[+12]` right after each
of the seven Opens returns. That distinguishes "Open never wrote a length for legals" from "a later
phase zeroed it", and `F-178`'s timing lesson means the admissibility check is the 16 structural
counters, not `INFLATE-ENTER`/`READWRAP`.
