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


