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

