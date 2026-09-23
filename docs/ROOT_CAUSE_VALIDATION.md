# ROOT-CAUSE VALIDATION — MCLA PC Rebuild (method + report + findings ledger)

> **Compressed 2026-09-20.** Part 1 = the audit method. Part 2 = the report as written at audit
> close (session 78b), with a short "what later superseded it" note. Part 3 = the **append-only
> evidence ledger F-001…F-063**, entries compacted to claim + evidence (F-numbers, titles,
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

**F-056 — 2026-09-20 21:30. F-055 is wrong twice, and the residual AV is now named to the source
line: an unchecked `stvx128` in the *caller* `sub_822F3BD8`, not the leaf.** FACT · H · P0. Supersedes
F-055's bullet 4 (both its facts) and closes its "next step" premise. Established by a 22-agent
read-only sweep of every `src/`, `docs/` and `tools/` file against `build/w38g.log`, then re-verified
here against raw words and `generated/`.

- **(1) The address is `0x8287E334`, not `0x8288E334`.** Raw words (`build/cache/mcla_pe.bin`,
  offset = VA − 0x82000000): `822FA958 3D608288 lis r11,8288` → `r11=0x82880000`;
  `822FA96C 816BE334 lwz r11,-7372(r11)` → D-field `0xE334` sign-extends to **−7372**, so
  EA = `0x82880000 − 0x1CCC` = **`0x8287E334`**. F-055 dropped the sign extension. Neither spelling
  appears as a literal anywhere in `src/` or `generated/` (`grep -i` → 0 hits each), so the value is
  computed — the "no `stw` with `0xE334`" half of F-055 survives, the addressing half does not.
  This is the `lis` sign-extension trap the `mcla-guest-raw-decode` skill warns about; the skill's
  own worked example is still wrong (see the tool-rot note in F-057).
- **(2) The fault is `stvx128 v33,r31,r7` with `r31 = 0` → guest EA `0xE0`, and it is a *raw*
  (unchecked) store.** `generated/ppc_xenon/ppc_recomp.49.cpp:2660-2661`:
  `// stvx128 v33,r31,r7` → `simde_mm_store_si128((__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), …)`
  — no `IsValidRange`, unlike `PPC_STORE_U32`. `r31` is a translator-local, not a `ctx` register.
  `ppc_recomp.49.cpp:2614-2615` `// addi r10,r31,16` → `ctx.r10.s64 = r31.s64 + 16`, and the dump
  prints `r10=00000010` ⇒ **`r31 = 0`** at the fault. `ctx.r7 = 224` comes from
  `// li r7,224` at `:2583-2585`, matching the dump's `r7=000000E0`. The faulting host RIP
  `0x7ff6ccde774a` (`w38g.log:4359`) is that line.
- **(3) F-055's leaf attribution is refuted, and so is its `r7`/`r10` "signature" reading.** The
  line at `:2661` sits inside `PPC_FUNC_IMPL(__imp__sub_822F3BD8)` which opens at
  `ppc_recomp.49.cpp:500` — the *caller*, not `__imp__sub_822FA958` (`:18143`). F-055's two
  candidate signatures (`r7=0xE0` ⇔ `0x822F44E8 addi r7,r1,224` with `r1=0`;
  `r10=0x10` ⇔ `0x822FA978 add r10,r10,r11` with `r11=0`) are both wrong: the dump's `r1=8EFFE590`
  is non-null, and `sub_822FA958`'s own `lis r11,0x8288`/`add r10,r10,r11` would give
  `r10≈0x13EC2280`, `r7=0x827E2978` (`822FA960/68` raw words above) — neither matches.
- **(4) `lr=822F44E0` is sticky (do-not #14), not the faulting call's return address.** F-055 called
  `lr` "honest" here; it is the return address set at `ppc_recomp.49.cpp:1965-1966` immediately
  before `sub_822FA958(ctx, base)`. That is *why* the sweep first blamed the leaf — the sticky `lr`
  and the `rip owner=` line agreed with each other and with nothing else.
- **Consequence for T38.3f:** the seeds are gone and the unseeded guest gate still dies at the same
  single instruction (`w38g.log:4331-4359`, one `C0000005`, `tag=forced-boot-gate`), so F-055's
  causal hypothesis ("seeding `[0x8288E6F0]=1` skipped the allocator's init and left a null table")
  is **not** what the surviving fault tests. The guest reaches `sub_822F3BD8` with a null VMX scratch
  base in a translator-local regardless of the flags. Next measurement, not next fix: print
  `report.faultBytes` + `SymFromAddr`/`SymGetLineFromAddr64` of `g_report.faultHost`
  (`src/boot_host.cpp:615-618`, `:641+`) so the soak names the store line itself instead of us
  reconstructing it from registers. Acceptance: next soak prints a `base + (…)` store form and
  `rva=0x14D774A` is unchanged.

**F-057 — 2026-09-20 21:30. Five load-bearing "starvation" readings are measurement bugs, and the
dark-blue screen is host-generated — proven with pixels, not inference.** FACT · H · P0.
Supersedes the "downstream is starved" half of F-050/F-052 and every §0 line that reads
`rptrWB=0000` / `put=11` / "boot thread parks" as evidence of a stalled pipeline.

- **(1) `rptrWB=0000` in `WAIT[KWFSO]` is a wrong-address read.** `src/kernel/imports.cpp:2117`
  polls hard-coded `0xC71D81BCu`; the CP publishes to `PhysToKernelVA(0x071D82BC)` = **`C71D82BC`**
  (`src/gpu_cp.cpp:934`, `:951-953` `vaForm`), as the soak itself says:
  `w38g.log:794` `VdEnableRingBufferRPtrWriteBack: writeback=0x071D82BC` and `:795`
  `CP: RING A rptr writeback raw=071D82BC (phys) -> publish @ C71D82BC (kernel VA)`. Every
  `DRAIN` line prints `wb=C71D82BC published=true`; only the waiter's census line reads the word 4
  bytes to the left, so it can only ever print 0. The `wb@C71D81BC=` field added at w18 (see the
  comment at `imports.cpp:2112-2116`) is off by the same 4 bytes.
- **(2) The CP ring is not frozen — it drained 8× and the host is fully caught up.**
  `w38g.log:865,874,1787,1794` then a ring reinit and `:2952,2959,3178,3186`:
  `rptr 0000→0016→0019→001C→001F`, `consumed=22/3/3/3`, `src=doorbell`, `lr=82411220`.
  Publication tracks production exactly: `CP: GUEST-PUB #5 … pub 9->11 put=11` (`w38g.log:3185`,
  `src/gpu_cp.cpp:752-790`), so `put=11` in the waiter line is the guest's own word at
  `gpuCtx+10908` and the host has matched it. "No consumer" is dead. What is actually missing is
  *content*: `DrainIndirectBuffer` is called with a raw phys `listPtr` at `src/gpu_cp.cpp:664-666`
  while `PhysToKernelVA` exists at `:202-204` and is used exactly once (`:951`), so an IB at phys
  `0x06258300` is walked as `0x06258300` instead of `0xC6258300` → zero packets, zero draws.
  That, not the crash, is the `DRAW_INDEXED=0` cause.
- **(3) The boot thread does not park on `40004D7C`.** `grep -ic "parking thread" w38g.log` = **0**
  (and `src/` has exactly one such line, `src/boot_host.cpp:1064`), and the **2,852**
  `WAIT[KWFSO] … obj@40004D7C` lines all carry `tid=00000C90 lr=8242FC1C` — a different thread, and a
  *satisfied* 16 ms heartbeat (2,851 × `WAKE[KWFSO] … status=00000000`). The boot worker
  (`tid=19552`, `tag=forced-boot-gate`) has its **last** line at `w38g.log:4335`/`:4359`:
  the handler **declined** (`recovery disabled, declining`) and the thread went silent. It was never
  parked; it was abandoned mid-gate by our own honest handler.
- **(4) The dark blue is 100 % host, and the window really is showing it.** Pixel capture of the
  live window during `build/w38h_screen2.log` (`build/screen_shot.png`, 33 s into a boot):
  `AVG_RGB=16,26,56`, 79/81 grid samples `0F1938`, title `MCLA Native`, client area empty.
  `16,26,56` = `0.06,0.10,0.22` × 255 — the hard-coded host colour at `src/render_thread.cpp:85`
  (initial clear, logged `RenderThread: initial clear+present (dark blue)`), `:444` (per-present
  default) and `:505-507` (black-FB override), reached every heartbeat because
  `PRESENT #n … fb=00000000` ⇒ `blitVA=0` ⇒ `if (!blitOk) ClearAndPresent(cr,cg,cb)`
  (`:535-539`) at ~30 Hz. Guest `PRESENT-FB sample rgb=(0.06,0.10,0.22)` ×4 (`w38g.log:3496,3845,
  3852,3860`) is *not* a guest pixel reading: `:503-507` substitutes that exact triple whenever the
  sampled framebuffer sums below 0.02, so the four guest presents had **black/zero framebuffers**
  and the log line is the override, while `PresentBgra` blits the real (black) buffer. Two follow-on
  defects, both unfixed: the Present HRESULT is never checked or logged anywhere in
  `src/render_thread.cpp`, and `:572-574` calls `ClearAndPresent(0,0,0.02)` *after*
  `DrawDynamicMesh` inside the same `BeginFrame` block, so a captured draw is cleared by the very
  call that presents it.
- **(5) "The extracted cache is empty so no asset can load" is only half true.** `VFS: Indexed 1
  files/directories` (`src/fs/vfs_rpf.cpp:173`) is real, but both call sites walk the same empty
  directory, so fixing the index alone yields nothing; a real-archive reader already exists at
  `src/fs/vfs_rpf.cpp:443-459`. **38 distinct `path='…'` strings** appear in `w38g.log` and the UI ones
  are really served — 5 × `.xsf` + 1 × `.xtd` under `resources/ui/` (`credits`, `garage`, `legals`,
  `policecam`, `raceeditor`, `meshtextures`), 5 × `shaders/*/preload.list`, `globaltex.list`, with
  **57** `XSF-OPEN` lines returning `ret=0` (`w38g.log:2787+`, `lr=821CCF78`) — and
  `xarchive_cache.rpf` is intact (RPF3 magic at offset 0, `0x7F008000`, zero-padding after
  `0x5C000000` — not truncated). The blocker is that the package offset is chosen by a
  **path string match**: `MclaPreferredPkgOffForPath` returns hard-coded `0xA0000` for
  `.xsf`/`.xtd`/`resources/ui` and `0x60000` for `meshtextures` (`src/gpu_device.cpp:285-296`),
  bypassing the TOC-derived `MclaPkgOffFromTocW2` (`:272-282`) that already reads the real offset
  out of the TOC w2 word. Every served UI file is therefore read from the wrong window.
- **(6) Tool / skill rot found by the same sweep** (each is a future false conclusion, so fix before
  trusting the next soak): `tools/soak_census.py`'s `VEH_PATHS` holds 9 markers and **8 do not exist
  anywhere in `src/`** (`parking boot worker`, `advancing RIP`, `Nuclear advance`,
  `patch applied, continuing`, `permanently disabled`, `patched sub_82`, `cleared MXCSR`,
  `UILOAD context` — measured by grepping each literal against every `src/**.{cpp,h}`) while the one
  path that *does* fire, `VEH W0: parking thread` (`src/boot_host.cpp:1064`), is absent from the list —
  so its recovery rows are structurally zero; `tools/mitigation_audit.py` self-reports
  **626 label-shaped tokens → 81 mitigation-shaped, 64 census-shaped, 481 unclassified**, i.e. it
  never flags a suffix-less short-circuit; the `mcla-log-census` skill's marker table cites
  `rptrWB=0000` as "no consumer", which (1) above now forbids, and **all 7** of the named recovery
  paths its "reading discipline" section tells us to count (`advancing RIP`, `Nuclear advance`,
  `permanently disabled`, `patched sub_82`, `parking boot worker`, `fallback advance`,
  `cleared MXCSR`) measure **0 in `src/` and 0 in `w38g.log`** — they are F-040/F-051 leftovers, so a
  "all zero → honest soak" verdict from that list is vacuous rather than reassuring.
  *UNVERIFIED, do not act on it:* the sweep also claimed `tools/ppc_disasm.py` prints RS/RA swapped
  for `ori`/`rlwinm`. Re-checked here — `548A1838 → rlwinm r10,r4,sh=3,mb=0,me=28` and
  `6129FFFF → ori r9,r9,FFFF` are both correct, and no `ori` with `rt != ra` was found in the sampled
  8 KB, so the claim is unsupported; the tool's real gap is that it decodes no FP/VMX
  (`C0092978 → ?op48:`, `13E100CF → float/ps`).

**F-058 — 2026-09-20 21:55. T40.3 + T40.4 are IN and the CP now decodes real packets — but F-057(5)
is void: the "wrong package window" blocker never existed.** FIX + FACT · H/F · P0. Soak
`build/w38j.log` (11,120 lines, `BOOT_RC=124`, exe 21:45, `build/w38i_build2.log` `BUILD_RC=0`)
against baseline `build/w38g.log`.

- **T40.3 fixed and measured.** `PhysToKernelVA` is now applied to the PM4 `INDIRECT_BUFFER` list
  pointer at both call sites (`src/gpu_cp.cpp:454` nested, `:666` ring). Before, the walk ran over the
  phys form (`w38g.log:858-872` printed eight `CP[IB]: TYPE0 base=000 count=1` — a zero header decodes
  as Type-0 base 0, count 1, so it was stepping over uninitialised memory one dword at a time). After,
  the same eight packets carry **real Xenos register offsets** (`w38j.log:858-872`:
  `base=A31`, `A2F`, `D02`, `A02`, `1DD`, `1DC`, `5C8`, `D04`) and the entry lines read
  `CP: INDIRECT_BUFFER @ C62582C0` / `C61D8280` (`w38j.log:857,866`). Three **nested** IBs are now
  reached that `w38g` never saw: `@ C71DA800 dwords=74 depth=1`, `C71DB540 dwords=13`,
  `C71DC180 dwords=48` (`w38j.log:873-875`) — proof the outer stream is being parsed as packets rather
  than zeros.
- **`DRAW_INDEXED` is still 0, and the reason is now specific rather than inferred.** The only Type-3
  opcodes this CP implements are `0x3F INDIRECT_BUFFER`, `0x3D MEM_WRITE`, `0x48 ME_INIT`, `0x64`
  (host-invented swap) — `src/gpu_cp.cpp:361-363`, `:43`. The draw packets are **`0x22 PM4_DRAW_INDX`**
  and `0x36 PM4_DRAW_INDX_2` (`.research/xenia/src/xenia/gpu/xenos.h:1600-1601`), and neither has a
  handler. The one Type-3 the soak does hit is `0x3C` = `PM4_WAIT_REG_MEM` (`xenos.h:1581`), logged
  once as `CP: skipping TYPE3 opcode=0x3C count=5 (unimplemented)` (`w38j.log`). So the next draw work
  is T37.6's Wave C (register-stream state + `DRAW_INDX`), **not** another pipeline bug — and it is a
  wave, not a one-liner: it needs the Type-0/Type-2 register writes decoded into RT/shader state first.
- **T40.4 fixed and measured.** The waiter's census now asks the CP for its own publish target
  (new `CpPrimaryWritebackVA()`, `src/gpu_cp.cpp:986`, used at `src/kernel/imports.cpp:2112-2122`), so
  the line prints `wb@C71D82BC=<value>` instead of the two hard-codes `C71D81BC`/`C701C4BC`.
  `tools/soak_census.py` gained `dead_tracked()` (reports a tracked marker whose literal exists in
  neither `src/` nor `generated/`) and its `rptrWB → "no CP consumer"` verdict line is deleted, replaced
  by `CP truth drains=N last_rptr=X pub=P put=Q (caught up|LAGGING)` — on this soak:
  **`drains=8 last_rptr=001F pub=11 put=11 (caught up)`**. It currently flags 4 suspicious markers
  (`boot-worker AV`, `fallback advance` = genuinely deleted; `swfCMD`, `VECTORED exception code=…` =
  names that never existed as literals, `swfCMD` nonetheless fires 2× so it is guest-produced).
- **F-057(5)'s last sentence is VOID — "every served UI file is read from the wrong window" is
  unsupported, and T40.1 as written is therefore not a fix to make.** Checked before implementing:
  `MclaPreferredPkgOffForPath` and `MclaPkgOffFromTocW2` **agree** where the log lets us compare. The
  only served file whose TOC flag word is printed is `resources/ui/meshtextures.xtd`
  (`w38j.log` `READWRAP-SERVE #1 … r5=40060000`), and `40060000 & 0x00FFF000 = 0x60000` — exactly the
  value the path branch returns for `meshtextures` (`src/gpu_device.cpp:291`). Both call sites already
  *prefer* the path value and fall back to the TOC (`:534`, `:9549-9551`), so inverting them would
  change nothing for that file. And the hard-code is a **deliberate, documented** choice, not sloppiness:
  `:521-523` says the TOC-derived bodies for `.xtd`/`.xsf` are often AES ciphertext and the plaintext
  package window is served instead. What is actually unproven is whether that ciphertext claim is true —
  that, not the offset, is the question worth a census. **Do not spend a session "fixing" T40.1.**
- **Everything else is unchanged, as it should be:** `C0000005` 1 → **1** (same instruction,
  `lr=822F44E0`, `hostRip` moved with the link), `GFx` 9 → 9, `PRESENT` 68 → 68, `PRESENT-FB` 4 → 4,
  `Fatal error` 1 → 1, short-circuit lines 185 → 178, `[error]` lines 58 → 58, and `fault-line guest
  lr` still **1 event / 1 distinct**. Two apparent deltas are not faults: the census's `VEH` 1 → 2 is
  the substring in `ser**ve H**ead` on a new line (below), not a second AV.
- **One genuinely new serve, plausibly downstream of T40.3 (unattributed):**
  `READWRAP-SERVE #1 path='resources/ui/meshtextures.xtd' r5=40060000 … pos=0->32768
  serveHead=[05435352 0FF512EF] lr=821BC334` (`w38j.log:2289`) — **0 occurrences in `w38g.log`**. It
  fires 2.4 s after the first real-packet IB drain and hands the guest a valid RSC5/XC container head.
  Not claimed as caused by the CP fix: one event, no second soak, and `lr=821BC334` is a census `lr`
  (do-not #14). Reproduce it before attributing it.

**F-059 — 2026-09-20 22:10. The guest DOES submit draws: 24 real `PM4_DRAW_INDX_2` packets decoded.
The CP's own logger was hiding them by collapsing the whole draw opcode range.** FIX · A/H · P0.
T40.6 steps 1-2. Soaks `build/w38k.log` (census only) and `build/w38m.log` (decode) vs baseline
`build/w38j.log`; exe 22:05, `build/w38m_build.log` `BUILD_RC=0`, both `BOOT_RC=124`.

- **What was blocking the observation:** `LogUnknownOpcode` reported each opcode `< 0x20` once and
  collapsed **every** opcode `>= 0x20` into a single line — the exact range the draws live in
  (`PM4_DRAW_INDX = 0x22`, `PM4_DRAW_INDX_2 = 0x36`, `xenos.h:1600-1601`). One `skipping TYPE3
  opcode=0x3C` line in `w38j` was therefore the maximum the old code could say. Replaced by
  `LogType3Unhandled` (`src/gpu_cp.cpp:351-367`): first 3 hits per opcode with their argument dwords,
  then a running total.
- **The stream's real contents, named (`w38k.log`, 13 distinct unhandled opcodes):** `0x21 REG_RMW`,
  `0x2B IM_LOAD_IMMEDIATE`, `0x3B INVALIDATE_STATE`, `0x3C WAIT_REG_MEM`, `0x45 COND_WRITE`,
  `0x46 EVENT_WRITE`, `0x54 INTERRUPT`, `0x58 EVENT_WRITE_SHD`, `0x60/0x61 SET_BIN_MASK_LO/HI`,
  `0x62/0x63 SET_BIN_SELECT_LO/HI` (names from `.research/xenia/src/xenia/gpu/xenos.h`).
  `0x36` has left the list since the decode landed (`w38m.log` shows 12).
- **Draw decode shipped:** `case kPm4DrawIndx / kPm4DrawIndx2` in `DrainPacketAt`
  (`src/gpu_cp.cpp:496-531`), reading `VGT_DRAW_INITIATOR` per
  `.research/xenia/src/xenia/gpu/registers.h:311-326` (prim_type +0/6, source_select +6/2,
  index_size +11/1, num_indices +16/16) and `VGT_DMA_BASE`/`VGT_DMA_SIZE` for `kDMA` only.
- **Measured result — the guest submits 24 draws in one buffer:** `CP-DRAW #1…#24` in `w38m.log`, every
  one `op=0x36 src=2 prim=1 numIdx=1 idxSize=0 initiator=00010081 hdr=C0003600`, at
  `C71DC180 → C71DC238` in a strict 8-byte stride. `src=2` = `SourceSelect::kAutoIndex`
  (`xenos.h:743-747`), `prim=1` = `kPointList` (`xenos.h:46`). The stride × 24 packets × 2 dwords =
  48 dwords, which is exactly the buffer's declared length
  (`CP: INDIRECT_BUFFER @ C71DC180 dwords=48 depth=1`) — the whole nested IB is a draw list.
- **The misaligned-walk alternative was tested and refuted, not assumed:** if the walk were parsing data
  as packets, the "headers" would be arbitrary. They are not — `hdr=C0003600` is a well-formed Type-3
  header (`bits31-30 = 0b11`, opcode field `0x36`, count field 0 → 1 argument dword) at every one of the
  24 addresses, and the census line reports no `#64`, so the total is bounded to `[24, 63]`.
- **`DRAW_INDEXED` is still 0 and this entry does not claim otherwise.** Decoding a submission is not
  rendering one: the CP models no Xenos register file, so there is no VB/IB/shader state to build a
  draw from. The separate host-side path (`src/gpu_device.cpp:1793-1803`, which *does* enqueue
  `RenderCommand::DRAW_INDEXED`) is starved for its own documented reason — the `sub_82420BA8` hook
  only ever sees dummy `li r5=0` submits because the guest's D3D9 draw chain
  (`sub_8217A470 → sub_8241BE78 → sub_8241C308 → sub_82420BA8`) never runs
  (`src/gpu_device.cpp:1829-1835`). Two independent paths to a pixel, both still short.
- **No regression anywhere:** `C0000005` 1 → 1, `GFx` 9 → 9, `UILOAD` 1 → 1, `PRESENT` 68 → 68,
  `Fatal error` 1 → 1, `VEH W0: parking thread` 0 → 0, short-circuit lines 178 → 177. The `rptrWB`/`PUT=`
  `+165` is heartbeat-count drift over the log window, not ring state (`CP truth` still
  `drains=8 pub==put`).
- **Open, unattributed:** 24 identical 1-point auto-indexed draws is an odd submission — a point-splat
  overlay, a cursor, or a driver stub are all consistent with it. Do not treat it as the menu. The next
  measurement is which of them is true, and it needs the register writes around the draws
  (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`) decoded, not more draw logging.

**F-060 — 2026-09-20 22:40. The last surviving `C0000005` is a null SINGLETON with exactly one
writer in the whole image — and that writer is a message handler that is never dispatched. Not a
gate argument, not an allocator-table failure.** FACT · D/G · P0. Supersedes the "the forced gate
passes `r3=0`" framing that `LONG_TODO_MASTER` §0 (22:45) put on T41.3, and closes F-056's
"translator-local `r31 = 0`" down to its producer. Established with IDA attached to the **live**
`idalib-mcp` RPC (T41.1) + generated-code text + raw words; rule-4 `addr_owners --check` run on all
five addresses (all unclaimed).

- **(1) The `this` is guest `[0x8287E26C]`.** `sub_822F3BD8` has **one** code caller in
  `generated/ppc_xenon/`: `ppc_recomp.50.cpp:6063`, inside `__imp__sub_823045E0` (opens `:6044`). That
  thunk is five instructions: `lis r11,-32120` → `r11 = 0x82880000`;
  `lwz r3,-7572(r11)` → `0x82880000 − 0x1D94` = **`0x8287E26C`** (the D-field sign-extends — the
  F-056(1) trap, applied in the correct direction this time); `bl 0x822f3bd8`.
- **(2) One writer, nowhere else.** `grep -rn "STORE_U32(.*+ -7572" generated/ppc_xenon/*.cpp` →
  **3 hits**, and only one is to the global: `ppc_recomp.48.cpp:27313` `stw r3,-7572(r11)` with
  `r11.s64 = -2105016320` at `:27311`, inside `__imp__sub_822F38C0` (opens `:27283`). The other two
  are struct-relative (`r31.u32 + -7572` at `:20187`, `ctx.r10.u32 + -7572` at `:27328`). Raw-image
  confirmation is the same arithmetic (`0x8210DA98` holds `0x822F38C0`).
- **(3) What that function is: the object's factory, and it can also publish 0 deliberately.**
  `ppc_recomp.48.cpp:27283-27339`: `li r3,14720` → `bl 0x82130528` (the XTL alloc thunk — host
  override at `src/gpu_device.cpp:11783`, ABI `r4 = r3`, align 16, **it does honour `r3`**) →
  `cmplwi cr6,r3,0` → `beq 0x822f38f8`, and that branch **stores 0 into the same global**
  (`:27328` region). Non-null path: `bl 0x822f3498` (the ctor) then publish `r3`. So there are two
  candidate mechanisms — the factory never runs, or it ran and its allocation failed — and they are
  told apart by the new `MSGCHAIN` census, not by argument.
- **(4) Both ends of the chain are `(handler, msgid)` table entries, i.e. the guest reaches them by
  message, not by call.** Raw words (identity-mapped `mcla_pe.bin`): `0x8210DA98 = 0x822F38C0` /
  `0x8210DA9C = 0x40001503` (the creator), `0x8210DED8 = 0x823045E0` / `+4 = 0x40000B03` (the
  consumer that faults), `0x82102AC0 = 0x82131008` / `+4 = 0x40003B03` (**the boot gate the host has
  been hand-calling since W36d is itself msg `0x40003B03`**), `0x8210DEF0 = 0x823047D8` /
  `+4 = 0x4000EA03`, `0x8210DAA8 = 0x822F3BD8` / `+4 = 0x4004A207`. This is the shape
  `PROGRAM_GUIDE` §8 already documents ("loaders reachable only by messages, `(handler,msgid)` tables
  in `.rdata`; boot loads arrive as msg `0x40003803`", `src/gpu_device.cpp:9421`). **`src/` has zero
  references to this table region** (`grep -rn "0x8210D|82102AC0" src/` → nothing but that one
  comment), so no host code walks it.
- **(5) Why F-056 could not see this.** The dump's `r3=828609E0` (`w38m.log:4358`) is *not* the entry
  value — inside `sub_822F3BD8`, `r31` is `mr r31,r3` at `:592`, spilled `std r31,176(r1)` at `:1986`
  and reloaded `ld r31,176(r1)` at `:2338`, and the only other `r31` write between is `:2076`
  (`r31 = r30+r11`), which is *after* the spill and never re-stored. So the faulting
  `:2660 stvx128 v33,r31,r7` dereferences the **entry `r3`**, and the entry `r3` is the global from
  (1). This is do-not #17's rule with a converse worth stating: the dump's registers can be useless
  while the generated code's register *provenance* is decisive.
- **(6) One global, two starved subsystems.** IDA `get_xrefs_to 0x8287E26C` lists readers in
  `sub_822112A8`, **`sub_82227428` (`+0x4c`, `+0x1b0`)** — the draw dispatcher of
  `PROGRAM_GUIDE` §8 — and `sub_82232938`/`sub_82232AF8`/`sub_82232C78` among others. If that is
  right, the missing object is in front of both the crash and `DRAW_INDEXED`; `sub_82227428` counts
  **0** in every soak to date (`DRAWDISP`=0, `w38m.log`), so this is a hypothesis with a named
  verification, not a claim: bl-scan the readers (rule 3/§10) and re-census `DRAWDISP` after the
  factory runs.
- **Consequence for the queue.** T41.3 is re-scoped from "give the gate its real arguments" to
  **"dispatch msg `0x40001503` the way the guest's own message system does"**; `w38m.log:3885`
  (`W35-BOOT-GATE #00001 r3=00000000`) is *not* the null source, and the "0 `DPC` lines" fact still
  stands (`grep -ic "dpc|8242FD00" w38m.log` = 0). Next action: read `build/w38n.log`'s `MSGCHAIN`
  rows.

**F-061 — 2026-09-20 23:15. The boot's real blocker is `sub_822FBAF8` — the `star_glow` effect
init — which never returns, so the tail of `sub_823047D8` (including F-060's singleton factory) is
unreached. And F-055's "no producer of `[0x8287E334]`" is wrong: it is two lines inside that same
function.** FIX + FACT · D/G · P0. Supersedes the mechanism F-060's "consequence" bullet implied
(the inline gate dispatch was NOT why the factory never ran — tested and refuted), and closes
F-055 §2 / F-056(1)'s open half. Soaks `build/w38n.log`…`build/w38q.log` vs baseline
`build/w38m.log`; new census `MSGCHAIN`/`MSGBISECT`/`GATE-WAIT`/`GATE-STACK` at
`src/gpu_device.cpp:9450-9530`.

- **(1) `sub_822FBAF8` never returns.** `w38q.log` has `MSGBISECT 5-822FBAF8 star_glow-init #1`
  (entry, `lr=823048D0` = its call site inside `sub_823047D8`) and **0** occurrences of the matching
  `RETURN` line, 0 for the two hooks that follow it in that function (`sub_823074B0`,
  `sub_822F96E0`), 0 for `MSGCHAIN creator-822F38C0`, and `GATE-WAIT [8287E26C]=00000000 after 500 ms`
  (`after 5000 ms` in `w38p.log`) — the singleton is not merely late, it is never produced.
- **(2) What that function is.** IDA (`get_metadata` verified `default.xex` @ `0x82000000`, attached
  to the live `:8745` RPC) decompiles `0x822FBAF8` as the `star_glow` effect constructor:
  alloc 104 → `[0x8287E334] = sub_822F9FA8()`; 3 × `sub_821B4838` render targets (13824/3072 B);
  then at **`0x822FBC24`** `(*(*[0x82839F68] + 4))([0x82839F68], "star_glow", 0, 0)` → `[0x8287E318]`;
  then `(*(*[0x8287E318] + 12))(..., "star_glow", 0, 0)`; then the parameter/technique lookups
  `DepthMap`, `CentrePosition`, `StarTexture`, `draw_starglow`, `draw_glow`, `draw_trail`,
  `draw_glow_notap`; then `(*(*[0x82839D70] + 12))(..., "star_glow", 0)`. **`0x822FBC28` is the
  historic `lr` of the 703-fault era** (F-040/F-043/F-046) — this is the same function, and it is
  still the frontier.
- **(3) The host is standing in for its very first step.** `w38q.log` puts
  `FIX-821873E8 #1 TLSDEAD r13=8F200000 tlsTable=8F201000 slot12=00000000 lr=822FBC28` at the
  `0x822FBC24` call — i.e. the shader-record allocator (`T38.3(d)`, `src/gpu_device.cpp:1044`, which
  fabricates a 16 B allocator object + vtable and a zero-filled 72 B object, then calls the guest
  ctor `sub_82188CF8`). The step after it dereferences **that fabricated object's vtable+12**, and the
  census says the function never gets past this region. Same instant, `w38q.log:3882`:
  `GETDEV #45 path='embedded:/fxl_final/star_glow.fxc'` → `GETDEV-RET ret=827D838C vt=82012918` (the
  memory device). **The star_glow shader load is still the blocker; 10 days of "fixed" it has moved
  from fatal → absorbed-by-host → never-returning.**
- **(4) F-055's negative scan is refuted.** `ppc_recomp.49.cpp:20994-20996`, inside
  `__imp__sub_822FBAF8`: `lis r11,-32120` (`r11 = 0x82880000`) + `stw r3,-7372(r11)` →
  `PPC_STORE_U32(r11.u32 + -7372, ctx.r3.u32)` — i.e. **`[0x8287E334] = sub_822F9FA8()`**. F-055
  searched for an immediate of `0xE334` and concluded no producer exists; F-056 fixed the *address*
  but never re-ran the *producer* search. Do-not #16's lesson again: a `lis`+signed-`d` pair must be
  decoded, not string-matched. `sub_822FBAF8` therefore **is** the writer F-055 said was missing, and
  `[0x8287E334]` is not a mystery global — it is `sub_822F9FA8`'s return value.
- **(5) The control-flow hijack was real but was not the cause.** `FIX-821873E8` used to force
  `sub_82131008` **inline**, from inside the guest's own allocator hook, on the stack of the thread that
  was mid-`sub_823047D8` (`w38o.log:3866→:3868→:3869`), so the AV the gate provoked killed that thread
  too. That is now moved to its own thread with its own 256 KB guest stack (`GATE-STACK`), which is a
  correctness fix on its own terms — but (1) proves the init stalls identically without it, so the
  hypothesis in F-060's last bullet is **refuted by test, not by argument**.
- **(6) One new, previously-masked defect exposed by the fix.** `w38p.log:3922-3926` /
  `w38q.log:3888-3890`: three `AllocPhysical: o1heapAllocate returned null size=0xca71d3xx`
  (**0** in `w38m.log`), one ms after `D3070-SKIP #2 obj=8EFFEE20 +8=CA71D5A8 r4=00008000
  lr=8218C89C`. A 3.4 GB "size" is a **pointer used as a length**: the buffer object at guest
  `0x8EFFEE20` holds uninitialised stack, because its initialiser is downstream of the stalled init.
  The old inline gate kept its own frames in exactly that stack window
  (`reserve=8EFFE920` ⊃ `8EFFEE20`) and so wrote something there by accident — the baseline's
  `D3070-SKIP #1 obj=8EFFF7F0 +8=82839580` was only "healthy" because of that overlap. Do-not #13's
  shape: a mitigation was covering a hole.
- **Consequence for the queue.** New #1 = **T41.3a: make the `star_glow` effect init complete** — the
  acceptance is `MSGBISECT 5-822FBAF8 RETURN` with `[8287E318]`/`[8287E334]` non-zero, after which
  F-060's singleton factory and therefore `BOOT-GATE-RETURN`/`UILOAD-ret` become reachable.
  `PLAN_VMX128`/Route B stays parked. Next baseline: `build/w38q.log`.

**F-062 — 2026-09-20 23:25. TLS is not one thing. The tree already has a real per-thread TLS
implementation (`src/kernel/guest_thread.cpp`, 0x100 = exactly the 64 slots the XEX declares) and boot
**bypasses** it for a hand-fabricated fixed block at `0x8F200000` in which **one** of 64 slots is
filled and which **every** guest thread shares. Two candidate causes of `slot12=00000000` are refuted
outright; the third was not reachable statically, and (7) names the one-soak measurement that settles
it.** FACT + NEGATIVE RESULTS · D · P1. Read-only session, no `src/` change, no soak taken (a
concurrent session held the tree: exe 23:03, `w38q.log` 23:05, this file 23:09). Baseline
`build/w38q.log`. Evidence: `mcla_pe.bin` raw words, `default.xex` header parse, `generated/` text,
`.research/xenia/` `file:line`.

- **(1) What `sub_821873E8` actually is — a per-thread scratch allocator, in full.**
  `generated/ppc_xenon/ppc_recomp.9.cpp:4749-4800`:
  `lwz r11,0(r13)` → `r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0)`; `li r10,12`; `li r6,0`; `li r5,16`;
  `li r4,72`; `lwzx r3,r10,r11` → **`r3 = TLS[12]`**; `lwz r9,0(r3)`; `lwz r8,8(r9)`; `mtctr r8`;
  `bctrl` → **`TLS[12] -> vtable[+8](TLS[12], 72, 16, 0)`**; `cmplwi cr6,r3,0` / `beq` → return 0;
  else `bl 0x82188cf8` (the ctor). This is why the T38.3(d) substitution's *shape* was right (F-045) —
  16 B object + vtable + 72 B block — and adds what F-045 could not: the semantic, a thread allocator
  taking `(size=72, align=16, flags=0)`.
- **(2) The XEX's own TLS contract, parsed.** Header layout per
  `.research/xenia/src/xenia/kernel/util/xex2_info.h:548-557` (magic@0, module_flags@4, header_size@8,
  reserved@0xC, security_offset@0x10, **header_count@0x14**, entries@0x18); `default.xex` gives
  `header_count = 15`. `XEX_HEADER_TLS_INFO = 0x00020104` (`xex2_info.h:294`, struct `:419-424`) →
  file `0x11D4` → **`slot_count = 64`, `raw_data_address = 0x8294A800`, `data_size = 0x94`,
  `raw_data_size = 0x94`**. Entry: optional header `0x00010100 -> 0x821322B8`, and the decoded PE
  independently agrees (`build/cache/mcla_pe.bin`: MZ@0, PE sig@0x108, machine `0x1F2`,
  `ImageBase 0x82000000`, `AddressOfEntryPoint` RVA `0x1322B8`) ⇒ **entry = `0x821322B8` = `_xstart`**
  (`generated/ppc_xenon/ppc_func_mapping.cpp:93`).
- **(3) REFUTED — "slot 12 is a load-time TLS initialiser the host forgot to copy."** Raw words at the
  template (`mcla_pe.bin`, offset `VA − 0x82000000 = 0x94A800`, rule 3): of its 37 dwords **all are 0
  except slot 14 = `0xFFFFFFFF`**. `[tlsTable+12] == 0` at thread start is therefore *correct*
  behaviour — Xenia's own sequence (allocate `slot_count*4`, zero-fill, then copy `data_size` from
  `raw_data_address`; `.research/xenia/src/xenia/kernel/xthread.cc:289-321`) yields the same zeros.
  **No fix of the form "copy the TLS template" can produce slot 12.** (This entry's own first
  hypothesis, tested and killed.)
- **(4) REFUTED — "`_xstart` / the CRT never runs".** `w38q.log:38` `image base 0x82000000 size
  0x9E0000 entry 0x821322B8`, `:86`, `:129`, and `:131` `BootWorker: calling entry point 0x821322B8`.
  The comment at `src/boot_host.cpp:312-314` ("our boot host jumps at the game entry and those inits
  never run") is about the **`.CRT$XCU` registration arrays**, not about the entry point, and must not
  be read as "the entry is skipped".
- **(5) NOT REFUTED — the structural defect: two thread-block implementations, and the fabricated one
  wins.** `src/kernel/guest_thread.cpp:9-30` builds a real per-thread layout (`TLS_SIZE = 0x100`,
  `[thread+0]` = TLS pointer, `[thread+0x100]` = TEB pointer, thread-id at `TEB+0x14C`) — `0x100`
  bytes = exactly the 64 slots (2) declares. But `src/boot_host.cpp:260-286` instead fabricates a
  **fixed** block: `ThreadBlock = 0x8F200000`, `TableBase = ThreadBlock + 0x1000`,
  `storeU32(ThreadBlock + 0x000, TableBase)`, and **exactly one** table slot —
  `storeU32(TableBase + 28, Descriptor)` for the XTL alloc/free chain. `r13 = 0x8F200000` is then
  hard-set at **25 sites** (`src/gpu_device.cpp` 21, `src/kernel/imports.cpp` 2, `src/apu/audio.cpp` 1,
  `src/boot_host.cpp` 1), so **every guest thread aliases one TLS array whose other 63 slots are
  permanently 0**. `src/gpu_device.cpp:1071-1090` closes the resulting null by *writing a fabricated
  allocator object into `tlsTable + 12`* — so the shared block ends up carrying a host-made "per-thread"
  singleton that all threads read as their own. That is a labelled mitigation, not a fix, and it is the
  one F-061(3) observed firing.
- **(6) NEGATIVE RESULT on the static hunt — record it so nobody re-spends a session.** No TLS[12]
  producer was located in `generated/`, and all three attempts failed as *instrument* errors, not as
  facts about the image: (a) a whole-file scan with no per-function scope reported **5,826** "producers"
  (translator-locals `r11`/`r30` are reused across every pointer); (b) a scope-correct scan for
  `PPC_STORE_U32(base + 12, …)` reported **0** because the real idiom is *indexed* — `stwx r10,r11,r9`
  with `li r9,12`, exactly the form (1) reads with; (c) the indexed scan then printed **159** sites, 6 at
  offset 12, and reading those 6 shows struct/list insertion, not TLS (`sub_821BBEA8` at
  `ppc_recomp.14.cpp:18364-18378` stores at 12/16/24 off a container pointer). **Do not read "0
  producers" as "the guest never writes it"** — same class as do-not #16/#20: a scanner artifact is not a
  negative result. `sub_821BBEA8`, `sub_821BBF00`, `sub_821C91C0`, `sub_8218C1C0`, `sub_82131228` all
  count **0** in `w38q.log`; only `sub_821C91C8` appears (13×) and it is already owned by
  `src/gpu_device.cpp` + `src/kernel/imports.cpp`.
- **(7) The measurement that settles it, in one soak.** The producer is cheap to find *dynamically*:
  put an x86 hardware watchpoint (DR0) on the guest dword `TableBase + 12` (host `g_base +
  0x8F20100C`) inside the existing VEH (`src/boot_host.cpp`) and log guest PC/`lr` + value for every
  writer. Either it names the guest function that installs the thread allocator — which is what
  T41.3/T41.3a have been standing in for — or it proves no guest code ever writes it, which is itself
  the finding F-060 was waiting for. It simultaneously answers a question nobody has measured: whether
  **any** thread other than the boot worker uses TLS at all. ⇒ new **T42.1**; do not pair it with any
  change to `tlsTable + 12`'s value in the same soak.
- **(8) Addendum, 23:30 — the hook that stands in for `sub_821873E8` is also a control-flow hijack, and
  it will confound any `star_glow` measurement until the two jobs are separated.** `src/gpu_device.cpp`
  (read at 23:26; line numbers drift under a live session): `:1096-1099` states it plainly — *"After
  chain init, dispatch the REAL boot-gate (`sub_82131008`) on this thread"* — and `:1111-1112` does
  `MCLA_LOG_WARN("FIX-821873E8 dispatching BOOT-GATE … on its own thread"); std::thread([caller = ctx]()
  mutable { … })` closing in `.detach()` at `:1271`. So a guest call whose entire semantics are
  `TLS[12]->alloc(72, 16, 0)` (§1) additionally (i) **captures the caller's live `PPCContext`**, which is
  exactly why `w38q.log:4011` prints `BOOT-GATE-ENTER 82131008 … lr=822FBC28` — the gate carrying
  star_glow's own return address — and (ii) runs it on a **detached** thread while `:1219` logs
  `BOOT-GATE started on boot worker thread`, which is not what the code does. Consequence for whoever
  holds #1: `MSGBISECT 5-822FBAF8 RETURN` cannot appear while the gate is forked from inside that call,
  because the frame that would print the return is not the frame the gate runs on; and every census of
  star_glow progress is a census of **two** threads sharing one `r13` (§5). Suggested split, small and
  carrying no behaviour claim: let the hook do only its own job (return the 72 B block per §1) and
  trigger the gate where the guest triggers it — F-060's `(handler,msgid)` table, msg `0x40003B03`.
- **(9) §7's status after F-063 (same tree, other session, so recorded here rather than as a new
  entry):** F-063's `MSGBISECT 8-822F9FA8 e334-producer` names the producer of `[0x8287E334]`, **not** of
  `TLS[12]`, so **T42.1 survives unchanged** — it is still the only measurement that can say whether the
  guest ever installs its own per-thread allocator. But F-063 also puts `sub_822FBAF8` one technique
  lookup from returning, which **demotes** T42.1 below that, and creates a fork worth deciding in the
  open: if `sub_822FBAF8` returns while `TLS[12]` is still the `src/gpu_device.cpp:1071-1090` fabrication
  in a block shared by every thread (§5), then that fabrication is **load-bearing for the boot path** and
  belongs in `PROGRAM_GUIDE` §7 as a named mitigation with this entry as its evidence — do-not #9's
  disclosure arm, not a quiet keep.

**F-063 — 2026-09-20 23:28. The `D3070` guard skipped the `star_glow` shader's own 32 KB buffer: its
skip condition tested a caller's flag bit as if it described the request. Removing that clause is the
first change of this era that makes the guest do MORE, and it takes the tree from 177 host
short-circuit lines to 96.** FIX + FACT · D · P0. Closes F-061's "why", and runs — for the first time
in the project's history — the `[0x8287E334]` producer F-055 said had none. Soak `build/w38s.log` vs
`build/w38r.log` (same tree minus this one condition). Parallel to **F-062** (another session, TLS
structure) and it answers part of that entry's §7 — see the last bullet.

- **The defect, at `src/gpu_device.cpp:11516-11545`:** `PPC_FUNC(sub_821D3070)` returned `r3 = 0`
  whenever `(ctx.r4 & 0x8000) != 0`, alongside the legitimate null-object guards. The comment above it
  says where the bit comes from — "8C760 magic-accept path does `ori r4,r4,0x8000` then D3070" — i.e.
  **bit 15 of `r4` is a flag the *caller* sets**, not a property of the request, so every call from that
  path was dropped even with a perfectly good object:
  `D3070-SKIP #2 obj=8EFFEE20 +8=CA71D5A8 r4=00008000 lr=8218C89C` (`w38r.log:3937`) — non-null `obj`,
  non-null block pointer. The guard's stated purpose (the `0x7E780000` TLS-null AV) is served by the
  four object/field tests alone.
- **Measured consequence of running it (`w38s.log`):** `D3070-SKIP` **0** (was 2);
  `TSLAB-OWNER #16 size=32768 align=16 lr=821D30B4` — the shader's 32 KB buffer is really allocated;
  `MSGBISECT 8-822F9FA8 e334-producer #1 r3=CA53C700 lr=822FBB34` — **the producer exists and now runs**
  (F-061(4)); then 9, 10, 11 ×6 (the three render-target pairs `r3=0x3600`/`0xC00`),
  **12 `sub_82188CF8` shader-obj-ctor `r3=A0021270`**, then 13/14 param+technique lookups against
  `r3=CA71D388`, a real object.
- **`o1heapAllocate returned null size=0xca71d380` ×3 → 0.** F-061(6)'s pointer-as-length is confirmed
  downstream of this skip rather than independent: the guest asks for that absurd size only when the
  buffer call before it was silently dropped.
- **Host short-circuit lines 177 → 96, `[error]` 61 → 51** — the largest mitigation reduction the tree
  has had, and it came from *deleting* a guard rather than adding one.
- **What did NOT advance, exactly:** `MSGBISECT 5-822FBAF8 RETURN` is still **0** and `[0x8287E26C]` is
  still **0** at every sample. Last step reached:
  `MSGBISECT 14-8218B688 technique-lookup #6 r3=CA71D388 r4=8200934C` (`w38s.log:3980`, 23:19:13.745) =
  IDA's line 39, `"draw_starglow"`. The next guest statement is line 40, the `"draw_glow"` lookup at
  `0x822FBCFC`. **One technique lookup from completing** — so F-060's singleton and F-061's stall are
  consequences, not the disease. Next: why that lookup does not return, which is the shader-dict INSERT
  path `PROGRAM_GUIDE` §8 already documents as NULL on PC
  (`82189438/88E50 → 8218C760 → resolver 821BDF20 → 821CB488`); do-not #8 still applies to
  `DICT-HYDRATE`.
- **Two marker drops that are not lost guest progress** (F-051's test, applied honestly):
  `GFx 9 → 1` — the 8 lost lines are the host's own stand-in prints (`GFX-BLOCK`, `GFX-ALLOC`,
  `GFX-CTOR-FN/entering/done/VT-MISMATCH`, `W34-GFX-CENSUS`, `W34-NOGFX`); the only guest-produced one,
  `GFXINIT-census sub_82177948`, survives. `UILOAD 1 → 0` — the forced gate's **only** trigger was the
  `FIX-821873E8` TLSDEAD branch, which now never fires, so `sub_82131008` is not dispatched at all.
  The stand-in was carrying UILOAD; **T41.6 must find its real trigger** (F-060(4): msg `0x40003B03`,
  table entry `0x82102AC0`).
- **New frontier, unattributed:** one fault 3 s in — `code=0xC0000005 Param[1]=0x100000040` (= guest
  EA **0x40** through a null base), `ppc ctx=nil tag=none`,
  `rip owner=host 0x7ff7a7fcc0a0, not a mapped guest fn`, and the handler **parked** it
  (`VEH W0: parking thread` 0 → 1; `w38s.log:5804`/`:5825`). No published guest context ⇒ nothing in the
  dump is attributable (do-not #17), so **T40.5** (symbolise the faulting host address) is on the
  critical path for the first time.
- **Cross-read with F-062 (same hour, other session).** That entry's §7 asked whether any thread other
  than the boot worker ever uses TLS. In `w38s.log` the answer for this path is measured: the
  shader-record call at `0x822FBC24` reached the **guest's own** `sub_821873E8` body
  (`FIX-821873E8` fires **0** times, 0 `TLSDEAD` lines) and constructed through it at
  `sub_82188CF8 r3=A0021270` — a `A0001010..A2E81000` simple-pool address, not a host `CAxxxxxx` one —
  so the single shared fabricated TLS block at `0x8F201000` **did** have slot 12 live by then (armed by
  one of the three sites F-062(5) enumerates). That is consistent with F-062's structural complaint
  rather than against it: one shared array works only because every thread aliases it, and T42.1 is
  still the right fix. Baseline for the next soak: **`build/w38s.log`**.

**F-064 — 2026-09-20 23:32. `sub_822FBAF8` does stop at the `"draw_glow"` lookup, and it stops with a
GUEST FATAL: `'drawblit technique is old and busted, rename to blit_draw.'` The bytes it parsed are
not a shader — the host is serving a 5258-byte name-list blob as `star_glow.fxc`.** FACT · C/E/G · P0.
Answers T41.3b's question in one soak and names the next one. Evidence: `build/w38s.log:3857`,
`:3860`, `:3870-3892`, `:3978-3990`.

- **The terminal event is a guest fatal, not a hang.** Immediately after
  `MSGBISECT 14-8218B688 technique-lookup #6 r3=CA71D388 r4=8200934C lr=8218875C`
  (`w38s.log:3980`, 23:19:13.745) comes `w38s.log:3981`
  `Fatal error dispatcher invoked - terminating game`,
  `lr=0x82188770 r1=0x8EFFF330 r3=0x8200B15C`, `slot 0x8285FEA0 = 0x82130678`,
  **`fatal message: 'drawblit technique is old and busted, rename to blit_draw.'`** So F-063's "never
  returns" is answered: the technique lookup does not return *normally*, it raises. (The process
  survives — `NATIVE-PRESENT`/`PRESENT` continue after it, and this is the 1 `Fatal error` the census
  has been reporting all day: it is **this** message, not the old `star_glow` load failure.)
- **What it was handed instead of a shader.** `w38s.log:3857`
  `AFB8-IN #4 r3=827D838C r4=CA71D500 path='embedded:/fxl_final/star_glow.fxc' lr=821BDF5C` →
  `AFB76-MISS` → **`AFB76-FALLBACK #4 path='embedded:/fxl_final/star_glow.fxc' serve rage_im
  buf=827D2DD0 size=5258 stream=00000008`** (`:3860`), then the guest reads 76 bytes of it in four
  slot-serving steps (`BE710-SLOT #50..53 … served=4/16/16/40`, `:3870`-`:3892`). Per
  `PROGRAM_GUIDE` §8 / the session-78 ledger row, `0x827D2DD0` size `0x148A` = **5258** is the
  **embedded name-list buffer** (`SeedEmbeddedNameList: node 0x828495B8, name 0x820093D4,
  buf 0x827D2DD0, size 0x148A`) — a name table, not shader code. The three sites that keep it that way
  are `src/gpu_device.cpp:3409`, `:8355`, `:9203`.
- **Why that is now on the critical path and was not before.** While the TLS-dead substitution was
  firing, the shader path never got far enough to parse technique names. F-063 let it get there, and
  the first thing it parses is a fabricated body. This is the same class as do-not #9/#13: a
  stand-in that was covering a hole, now exposed by progress on the step before it.
- **What is NOT concluded.** It is not established that `star_glow.fxc` exists in the retail content
  we are allowed to read: the `xarchive_cache.rpf` TOC is encrypted (`0xB116A6AB` @ 0x800, guest
  decrypts), so **grepping the archive proves nothing** — the honest measurement is the guest's own
  `TOC76`/`TOC76-RET` census for `fxl_final/star_glow.fxc`, plus whether the `a:/archive/…` fallback
  in the session-78 cascade (`EXECUTION_PHASES.md` §A1: `GETDEV #41/#42/#43` all missed) is even
  reachable, given F-034's "the non-archive Mount chain never executes".
- **Next (T41.3b step 1, one soak, census only):** log which path names reach `TOC76` and what they
  return, and whether the guest *would* have asked the archive device if `AFB76-FALLBACK` did not
  answer first. Do **not** swap in a different blob, do not patch `byte_827D5C70`, do not stub the
  fatal (do-not #3, §11 rule 4).

**F-065 — 2026-09-20 23:35. The `(handler, msgid)` table is real and its bounds are the PE data
directory, but **no code in the guest image computes a pointer into it** — so T41.3 step 2 cannot be
answered by finding a `lis/addi` walker, and two plausible leads are closed. FACT + NEGATIVE RESULTS · D
· P1. Read-only session (concurrent session held the tree; no build, no soak — see the file-mtime note
in F-062's header). Evidence: `build/cache/mcla_pe.bin` raw words (rule 3), `generated/` text, one
whole-corpus scan of 176 TUs.

- **(1) F-060(4) confirmed independently, and the array is bigger than claimed.** `0x82102A00` holds
  consecutive `{handler, msgid}` dwords with monotonically ascending handler VAs:
  `82130048/40005703`, `821301A8/40001403`, `821301F8/40001805`, then at `0x82102AC0`
  `82131008/40003B03` (the boot gate F-060 identified), `821310F8/40002A03`, `821311A0/40002104`; and
  at `0x8210DA98` `822F38C0/40001503`, `822F3918/4000A305`, `822F3BD8/4004A207`. Shape is
  unambiguous — the ids are all `0x400xxxxx` and the handlers are adjacent functions.
- **(2) The region's bounds are not a guess: they are the PE data directory.** `mcla_pe.bin` optional
  header dir **EXCEPTION = rva `0x102A00`, size `0x00027338`** → VA `0x82102A00`..`0x82129D38` =
  **12,902 eight-byte records**. `IMAGE_DIRECTORY_ENTRY_EXCEPTION` is where a PPC PE keeps its function
  table; this title's directory instead holds the handler/msgid pairs, so a loader reaches them through
  the **directory**, not through a literal address. (The same parse gives `IMPORT` at `0x82950000`,
  `BASERELOC` at `0x82960200`, `TLS` dir at `0x820DB8D8`, `IAT` at `0x82000600`, and
  `AddressOfEntryPoint` RVA `0x1322B8` — see F-062(2).)
- **(3) NEGATIVE, and it retargets T41.3 step 2.** Whole-corpus scan of `generated/ppc_xenon/*.cpp`
  for every `lis` whose page overlaps that directory (`0x82100000`/`0x82110000`/`0x82120000`/
  `0x82130000`) plus a following `addi`: **14 sites in 11 functions**, and **all 14 land in the tail
  `0x82128020`–`0x82129840`** (`sub_82131790`, `sub_8265BF20`, `sub_82689200`, `sub_82143C48`,
  `sub_821E63F0`, `sub_821F28D0`, `sub_822365B8`, `sub_822B8F48`, `sub_8235AF90`, `sub_823B59A8`,
  `sub_823C8218`, `sub_823DEDD8`) — **zero** reach the pair area where F-060's creator/consumer/gate
  live. So the table is not entered by an in-image address materialisation. Either its base is loaded
  from a *global* that the PE-directory read writes (see (5)), or nothing walks it — and "find the
  `lis/addi`" is now the wrong method, which is exactly what T41.3 step 2 told the next agent to do.
- **(4) Two false leads closed.** (a) The 10 `lis 0x82100000` sites are all in
  `sub_823DE730`/`sub_823DE738`/`sub_823DEDD0`/`sub_823DEDD8`/`sub_823DEF0C` and point at
  `+10092`/`+10076`/`+10220` = `0x8210276C`/`77C`/`7A0C` — a **different structure in the same page**
  (`00000000 823DE658 | 00000000 8210277C | 00000003 8210278C`, i.e. `{0, handler}` + `{count, ptr}`
  records), reached as `sub_823E5B70(r3 = obj+88, r4 = &records)`. (b) `sub_823E5B70` is therefore not
  a message registrar: its body (`ppc_recomp.71.cpp:21263+`) builds a 32-byte descriptor via
  `sub_823DA950(&r1[80], 0x820EDEF0, 32)`, stores `obj`/`table` at `r1+104/108`, tests **bit 3 of
  `table[0]`** and writes the constant `0x01004000` — reflection-descriptor shape, matching
  `PROGRAM_GUIDE` §8's `fwReflected`/`fgDesriptor` family. Do not spend a session on either as "the
  dispatcher".
- **(5) One concrete missing capability, measured rather than assumed.** The API by which a guest reads
  XEX/PE image fields is `RtlImageXexHeaderField`, and it is a **stub that returns nothing**:
  `src/kernel/imports.cpp:1377` `void RtlImageXexHeaderField() { LOG_UTILITY("!!! STUB !!!"); }`
  (hooked at `:3452`). The guest really calls it — **5 sites**: `ppc_recomp.0.cpp:7206`,
  `ppc_recomp.80.cpp:9435`, `ppc_recomp.81.cpp:4532`, `:9384`, `:9703` — and it fires **0** times in
  `build/w38s.log`, so those callers are not yet reached: **this is not today's blocker.** It is,
  however, the only in-image route to (2)'s directory and to `TLS_INFO` (F-062(2)), so when any of the
  five callers is reached the stub silently hands back zero, and the failure will look like a null
  global, exactly like F-060's. Register it in §7 as a known stub now; do not implement it speculatively
  (rule 1) — implementing it *is* cheap and correct (`XexGetModuleHeaderField`-style: return the value
  for the key from the table in F-062(2)), but a fix nobody has seen called has no acceptance signal.
- **Consequence for the queue.** T41.3 **step 2 is re-scoped by (3)**: stop looking for a literal table
  base; instead ask who *writes* a pointer to `0x82102A00` into a global — i.e. find the store of the
  directory value, which is (5)'s stub or an `IMPORT`-table walk — and census the 5 `RtlImageXexHeaderField`
  call sites' enclosing functions to learn what the guest expected back. **T41.3a/T41.3 step 1 stay
  ahead of this** (F-063 has the guest one technique lookup from returning); F-065 is a
  search-space narrowing, not a new #1.

**F-066 — 2026-09-20 23:38. The current terminal fatal is produced by a documented host mitigation that
**cannot ever succeed**: `AFB76-FALLBACK` answers the missing `fxl_final/star_glow.fxc` with the body of
`fxl_final/rage_im.fxc`, and `rage_im` necessarily contains the obsolete `drawblit` technique that the
guest then rejects. The real `star_glow` body is absent from the entire embedded set — measured over all
15 blobs, not inferred. Corrects F-063's identification of the sixth lookup argument.** FACT + FIX
DIRECTION · C/E/G · P0. Supersedes F-063's `r4=8200934C` = `"draw_starglow"` and completes F-064's
"what it was handed". Read-only session (a concurrent session held the tree — no build, no soak).
Evidence: `build/cache/mcla_pe.bin` raw words (rule 3) + `src/boot_host.cpp:319-364` + `src/gpu_device.cpp:3405-3410`.

- **(1) What the embedded device actually contains — the authoritative list.** The 15 `{name,buf,size}`
  triples the host seeds (`src/boot_host.cpp:328-344`, "decoded from every `bl 0x821d22e8`", pushed at
  `0x82860AF8`) have name strings that are **full archive paths**, read straight from the image:
  `fxl_final/rage_im.fxc` (5258 @ `0x827D2DD0`), `fxl_final/rage_fastmipmap.fxc` (5406),
  `fxl_final/rage_spotlightfog.fxc` (10331), `fxl_final/rage_bink.fxc` (3187),
  `fxl_final/rmptfx_default.fxc` (3612), `fxl_final/rmptfx_litsprite.fxc` (8133),
  `dcl/rmptfx_default.dcl` (138), `dcl/rmptfx_litsprite.dcl` (138),
  `fxl_final/rage_atmoscatt_clouds.fxc` (32280), `fxl_final/rage_perlinnoise.fxc` (5713),
  `fxl_final/rmptfx_collision.fxc` (4564), `fxl_final/rage_shadowcollector.fxc` (5112),
  `fxl_final/rage_shadowdepth.fxc` (4347), `fxl_final/rage_blendshadows.fxc` (18323),
  `fxl_final/rage_postfx.fxc` (48). **`star_glow.fxc` is not among them** — so `AFB76-MISS`
  (`w38s.log:3857`→`:3860`) is a *correct* miss, not a lookup bug.
- **(2) Negative over the whole permitted set, measured per blob.** Searched each of the 15 bodies for
  every key the guest's `sub_822FBAF8` looks up (F-061(2): `star_glow`, `draw_starglow`, `draw_glow`,
  `draw_trail`, `draw_glow_notap`, `StarTexture`, `CentrePosition`, plus `blit_draw`): **no blob
  contains any of them.** Those names exist in the image only as `.rdata` lookup keys, contiguous at
  `0x82040EAB`-`0x82040F0C` (`$/textures/effects`, `draw_glow_notap`, `draw_trail`, `draw_glow`,
  `draw_starglow`, `StarTexture`, `CentrePosition`, `star_glow`). Two blobs carry `DepthMap`
  (`rage_im`, `rmptfx_default`/`_litsprite`) and exactly one carries `drawblit`: **`rage_im`, at
  `0x827D4135` = buf+`0x1365`** — inside the body being served.
- **(3) The chain, closed.** `AFB8-IN path='embedded:/fxl_final/star_glow.fxc'` → `AFB76-MISS` →
  `AFB76-FALLBACK serve rage_im buf=827D2DD0 size=5258` → the guest's `rgxa` magic test passes (that is
  the fallback's stated purpose, `src/gpu_device.cpp:3405-3410`: *"keep the AFB76-FALLBACK (serves the
  known-good rage_im blob at 827D2DD0) so the guest's own compare passes on real content"*) → the parse
  reaches `rage_im`'s own `drawblit` technique → `Fatal error dispatcher invoked`,
  `r3=0x8200B15C` = `'drawblit technique is old and busted, rename to blit_draw.'`
  (`w38s.log:3981`). **The host chose a body whose content guarantees the fatal.** F-064's
  "a stand-in that was covering a hole, now exposed by progress" is exactly right, one layer further:
  this stand-in does not cover a hole, it *is* the hole.
- **(4) CORRECTION to F-063, by raw words.** F-063 reads
  `MSGBISECT 14-8218B688 technique-lookup #6 r3=CA71D388 r4=8200934C` as IDA's line 39
  `"draw_starglow"`. `0x8200934C` is the 8-byte string **`drawblit`**; `draw_starglow` is at
  `0x82040EE0`. So lookup #6 was the obsolete-technique check against the served `rage_im` content, and
  `sub_822FBAF8` **never reached its first real `star_glow` lookup** — which is also why "one technique
  lookup from completing" overstates the progress. F-063's D3070 fix and its marker deltas are
  unaffected.
- **(5) Why the obvious alternative was already tried and also fataled.** `src/gpu_device.cpp:8355` and
  `:9203` register the inflated **preload pack** (`A47FD000`) instead; the `rgxa` first-word compare
  (`kRgxaMagic = 0x61786772` = `'rgxa'` BE, effect-loader check at `sub_8218C844`) rejects it →
  `FATAL-SOFT "Old version of rage effect"` at `lr=8218C864`. So the tree has two host bodies for this
  request and **both terminate**; there is no third blob to swap in (per (2)), which is what makes the
  honest-miss experiment the only untried branch and satisfies F-064's "do not swap in a different blob".
- **(6) Next action — T41.3d (queue): make the miss honest, one soak.** At `src/gpu_device.cpp:11181` let a path
  whose name is not in the seeded list **miss** instead of serving `rage_im`, and census what the guest
  does with a genuinely-absent effect: does it ask the archive device (`GETDEV`/`READWRAP` for
  `fxl_final/star_glow.fxc`), take its own not-found branch, or fatal the same way? Acceptance is a
  named delta vs **`build/w38s.log`**: `AFB76-FALLBACK` for that path → 0, plus the first
  `GETDEV`/`READWRAP` row for the same path (0 today) and the `drawblit` fatal → 0 **or** replaced by a
  *different*, named guest error — which is also a valid and informative result. **Forbidden:** stubbing
  the fatal or patching the technique name (do-not #3), and any new blob substitution (F-064).

- **(7) One measured calibration, so a future session does not re-run this scan.** A full pass over all
  2,130,739,200 bytes of `build/game_data/xarchive_cache.rpf` for four needles returns **0 hits for
  `fxl_final`, `star_glow`, `.fxc` and — decisively — `resources/ui/legals`**, a path the guest resolves
  from that same archive 22× in `w38s.log` (`TOC76 #1..`, `lr=821CCED0`). So no name string in that
  archive is plaintext: **a name grep there is uninformative in both directions**, which quantifies
  F-064's warning instead of asserting it. It also shows the host's `RpfVirtualFileSystem` is not what
  serves those `.xsf` files — it indexes the on-disk `mcla extracted cache`, verified **empty** (0
  files; `src/fs/vfs_rpf.cpp:144-160` therefore contributes nothing) — the guest's own decrypted TOC is.
  Consequence: (5)/(6) cannot be settled offline, and with (2) ruling out every embedded body and (7)
  ruling out inspection, **T41.3d is the only branch whose outcome is unknown** — whether
  `fxl_final/star_glow.fxc` exists in the archive is answerable only by letting the guest ask.

**F-067 — 2026-09-20 23:49. T41.3d run: deleting the `star_glow`→`rage_im` substitution removes every
access violation in a 120 s soak (`C0000005` 2 → **0**, first soak in the project's recorded history with
none), releases the parked thread, and moves the guest from the effect-loader fatal back to the SWF-parse
stage. It also disproves F-066's framing of the archive route: the guest **does** ask the archive device,
and `GETDEV` answers `0` for that one path while answering the *same* prefix for UI files.** FIX + FACT ·
D/G · P0. Soak `build/w38t.log` (exe 23:45, `BUILD_RC=0`, `BOOT_RC=124`, 11,072 lines) vs baseline
`build/w38s.log`; rule-11 check first (no `mcla`/`ninja`, newest log 25 min old). Change is one deleted
block at `src/gpu_device.cpp:11174-11189`, now labelled with this entry.

- **(1) The change, and why it was allowed.** The `AFB76-FALLBACK` branch that served
  `fxl_final/rage_im.fxc` for any `star_glow` request is deleted; a miss now logs
  `AFB76-MISS-HONEST` and falls through to the pre-existing `r3 = 0xFFFFFFFF` not-found return that every
  other missed path already used. No new mitigation, no invented data (do-not #9 is satisfied by
  *removing* one), and per F-066(2) the substitution could not succeed on any input.
- **(2) Measured: the fault family is gone.** `C0000005` **2 → 0**; `VEH W0: parking thread` **1 → 0**;
  `tools/soak_census.py` prints *"fault-line guest lr: none (no line matched the fault filter)"* — i.e.
  not one access violation in 120 s, where every baseline since W36 has had ≥1. `[error]` lines 51 → 41.
  Host short-circuit lines 96 → 98 (**+2**, not a reduction: the guest now reaches two more
  resource-absorbing paths), and `DRAW_INDEXED`/`DRAWDISP`/`CP-DRAW 24`/`PRESENT 68`/`FRAME-END 3`
  unchanged.
- **(3) Where the guest went instead.** It retries the effect through three more names and then raises
  its own error: `embedded:/dcl/star_glow.dcl` (`AFB76-MISS-HONEST #3`, `:3843`),
  `embedded:/star_glow.dcl` (`#4`, `:3851`), then
  **`GETDEV #48 path='a:/archive/fxl_final/star_glow.fxc' → GETDEV-RET ret=00000000 vt=00000000`**
  (`:3891`-`:3893`) → `Fatal error dispatcher invoked`,
  `lr=0x82189270 r3=0x8200B358 r4=0x82040F0C`,
  **`fatal message: 'Unable to load shader '%s', it probably wasn't preloaded properly.'`, aux
  r4 = 'star_glow'** (`0x82040F0C`, F-049's string — the same address `w38b.log` pointed at 700 faults a
  day). `FATAL-SOFT` absorbs it (`:3894`), execution continues, and **1.2 s later the guest is parsing
  SWF**: `swfCMD` **0 → 2** — `'swfCMD::Fixup - unknown type %d'` at `lr=8260A8CC` (`:5433`, `:5441`),
  which is T38.4's long-standing frontier. So the run returns to the UI-parsing stage instead of dying in
  the effect loader.
- **(4) F-066(5)/(6) framing corrected — measured, not argued.** The archive *is* tried, and the failure
  is path-specific, not mount-specific: `MOUNT76 #1 dev=C60ABD08` and `#2 dev=C60AC180` both mount the
  **same** prefix `a:/archive/` with the same vtable `82012BDC` (`:617`, `:706`), and in the *same*
  lookup array the calls that follow `GETDEV #48` still resolve
  `a:/archive/resources/ui/{raceeditor,garage}.xsf → ret=C60AC180` (`:1903`, `:1920`). 94 `GETDEV` lookups
  use `a:/archive/`; only `fxl_final/*` comes back `0`. Two candidate readings, both untested: the effects
  archive needs a mount that never happens (`MOUNT76 #3` = 0), or `fxl_final/star_glow.fxc` is not in the
  archives the guest opened (`game:/xarchive_cache.rpf`, `game:/xarchive_audlo.rpf`) and the real source is
  the **preload** the message names — `it probably wasn't preloaded properly` + `shaders/effects/preload.list`
  being resolved 8× in this very soak. Preload, not archive, is the cheaper hypothesis.
- **(5) Census trap found and named — do not claim UILOAD from this soak.** The `UILOAD` **0 → 1** delta
  is **false**: the single match is the substring inside the host's own
  `W34-NOGFX #1 — no GFx loader objects (vt 0x82073xxx) in scan bands; UILOAD/EF220 never armed after
  inflate` (`w38t.log:5637`). `UILOAD` is **0** in substance, and the same marker read 1 in older soaks only
  when the forced gate ran. Do-not #22's class again, one row over: a bare identifier in a host sentence is
  not a guest event. `tools/soak_census.py` should scope the `UILOAD` row to `UILOAD-enter|ret|param` the
  way T41.4 scoped exception codes — folded into T41.4's remaining work, not a new task.
- **Consequence.** The deletion **stays** (it removed every AV and advanced the guest). New #1 =
  **T41.3e: answer the shader-preload question**, not the archive one — census what
  `shaders/effects/preload.list` (already served) is parsed into and whether `star_glow` is expected in
  it; `GETDEV` for `fxl_final/*` returning 0 while `resources/ui/*` returns a device is the same
  measurement's control. Baseline for the next soak: **`build/w38t.log`**.


**F-068 — 2026-09-20 23:53. Every shader **preload list** the guest is served is undecipherable bytes,
while package reads in the same soak land on valid XCompress containers — so F-067's
`it probably wasn't preloaded properly` fatal has a named, measured proximate cause, and T41.3e is
re-scoped from "find star_glow" to "why do `.list` reads miss the container format".** FACT · C/E · P0.
`build/w38t.log` (same soak as F-067, no new build); rule-3 raw-word comparison of served heads against
`kXCompressMagic = 0x0FF512EF` (`src/gpu_device.cpp:3403`).

- **(1) Six for six.** Every `GLOBTEX-BODY` line for a `*.list` in `w38t.log` has a head that is not a
  container: `shaders/ui/preload.list` len=260 `7D8DC10A C2300C86`; `shaders/effects/preload.list`
  len=368 `7590416E 03310845`; `shaders/city/preload.list` len=1246 `6D94E16E 9C300CC7`;
  `shaders/cars/preload.list` len=1108 `7D93DB92 9B300C86`; `shaders/characters/preload.list` len=496
  `8D905D0A C3201084`; `textures/global/cars/globaltex.list` len=575 `75914D4E C4300C85`. Their ASCII is
  unprintable (`u.An.1.E..r..`), i.e. **not a name list**, which is what a `.list` must be for the guest
  to preload anything from it.
- **(2) The control, in the same soak.** A valid container head is `05435352` followed by `0FF512EF`
  (`READWRAP-SERVE`/`serveHead=`, and `INFLATE #1 magic=05435352` at `:2231`), and `0FF512EF` appears on
  **20 lines** of `w38t.log` with `INFLATE` running 387 times — so the inflater and the container format
  are working for the paths that find them. **0 of the 31 `XSF-HOSTSERVE` lines has the magic in its
  head**, so the divergence is not "encryption everywhere": some serve paths reach containers and the
  `.list` path does not.
- **(3) The discriminator to test (hypothesis, named so it can be killed cheaply).** The `.list` bodies
  are served at the **TOC word +8** offset — `XSF-HOSTSERVE path='shaders/effects/preload.list'
  off=00304E12` — after the host **forces bit 30 on that very word**: `XSF-OPEN-GATE … +8 00304E12 ->
  40304E12 (set bit30 so Open proceeds)` (`w38t.log:3742`; same for ui at `:3312`). If bit 30 of that
  word is a *format/encryption flag* rather than part of the offset — as the `4000007E`/`400000BC`
  fourth words suggest — then both the offset used and the body interpretation are wrong for every `.list`,
  while the `.xsf`/`.xtd` bodies that come via the path-window route (`0x60000`/`0xA0000`, F-057(5)/F-058)
  land correctly. **This is F-058's open census question, one layer down**: F-058 retracted "wrong
  window" for `meshtextures.xtd` on the single case where both routes were comparable, and never
  addressed the `.list` class at all.
- **Consequence.** T41.3e is re-scoped: do not hunt for `star_glow`'s body. Read the `.list` entries the
  guest expects (a plaintext name list is a *data* question with a checkable answer — a correct body
  should contain ASCII names like `star_glow`, `drawblit`, `rage_im`), and settle what TOC word +8 bit 30
  means before touching any serve offset. Forbidden as ever: patching `byte_827D5C70`, stubbing the
  fatal, or inventing a list body (do-not #3/#9). If bit 30 turns out to be an encryption flag, the
  honest finding is **the archive's `.list` members are encrypted and the tree has no decryptor** —
  which is a bigger but real answer than another substitution.


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


**F-071 — 2026-09-20 21:06. CORRECTION to F-068/F-069/F-070's fix shape, and a bigger finding: the
guest inflates archive members **itself**, so "the host must inflate-then-slice" is wrong; and every byte
of guest content funnels through **one host hook that rewrites the inflater's pointers through five
stacked heuristics (waves w20→w28)**, which is live right now. This is the tree's densest mitigation
cluster and the real gate on content loading.** FACT + FIX OF MY OWN REASONING · D/G · P0. Supersedes
F-070(5) and F-069(3)'s "inflate then slice" conclusion; F-070(1)-(4)'s archive measurements stand as
data. Evidence: `generated/ppc_xenon/ppc_recomp.14.cpp:19080-19140`, `src/gpu_device.cpp:6789-6860+`,
`build/w38t.log`.

- **(1) The guest's own read+inflate loop, decoded from generated text (rule 3).** Inside
  `__imp__sub_821BC140`: `r11=[r3]` (vtable) → `r10=[r11+28]` → `mtctr/bctrl` with `r5 = [r1+80]` loaded as
  **`PPC_LOAD_U64`** — a 64-bit file position — then `r3`(bytes read) is compared to the request, the
  position is advanced (`r6 = extsw(r3) + [r1+80]`, `std r6,80(r1)`), the remainder recomputed
  (`subf r7,r29,r3`), and the chunk is handed to **`bl 0x821d5e10`** with `lr=0x821BC380`
  (`ppc_recomp.14.cpp:19134`). `sub_821D5E10` is `zlibInflater::InflateBegin` (the host's own comment at
  `src/gpu_device.cpp:3391-3393` says so). ⇒ compressed bytes at a member offset are **expected input**, so
  F-068(1)'s "six garbage heads" is not itself the defect, and F-070(5)'s conclusion was the wrong fix
  shape. The heads are still not an XCompress/RSC5 block start (F-069(5)), so the *position* question in
  F-070(5) remains open — but it is now a question about what the guest is fed, not about who inflates.
- **(2) Where the interception is, and how loaded it is.** The host hooks `sub_821D5E10` at
  `src/gpu_device.cpp:6789` and then **rewrites the inflater's own state** through five stacked
  conditions in one `if`: `badMagic`, `stackWalk`, `j2NeedRepoint`, `stackPkgHead` (`:6838-6860`), under
  comments naming six accumulated waves — **w20, w21, w22, w24, w27, w28** — including
  *"stack-hosted RSC5/XC head is a PLANTED HEAD (READWRAP-SERVE copies ≤256B to stack dest), NOT the full
  compressed body"* and a *"w27 regression"* note. So the tree does not merely serve bytes: it plants
  256-byte container heads on the guest stack and re-points `st+0`/`st+4` at a **host-chosen**
  guest-heap package bounce (`0xA0000`-class) so that `XMem`/the inflater produces something.
- **(3) Measured as live, not dead (`w38t.log`).** `INFLATE` 387 lines over ≤16 numbered events
  (max seq `#16`), **`REFORCE` 32**, `W27-XC-FULL` 5, `J2-DIST` 21, `READWRAP-SERVE` 1, and
  `INFLATE-SKIP`/`INFLATE-EMPTY`/`CORRUPT`/`W28-XC-J1CONV` 0. The re-point machinery is therefore carrying
  real work today — deleting it blind would regress boot, and adding to it is do-not #9 in its purest form.
- **(4) Why this matters for "a working game" more than `star_glow` does.** Shaders, UI packages,
  textures and (post-menu) the world are all archive members, so **all of them traverse this hook**;
  F-047's 81-unregistered-label debt is concentrated here, and none of the w20→w28 branches is in
  `PROGRAM_GUIDE` §7's table. Each per-file serve hack (including any new `.list` handling) increases the
  coupling. The order that actually shortens the path to a menu is: make this hook's behaviour observable
  and honest **first**, then let the `.list`/shader questions fall out of it.
- **(5) Next action — T41.3e2, logging-only, one soak.** The hook already has `st`, `inPtr`, `magic`,
  `outPtr`, `consumed`, `produced` in hand; the existing `INFLATE`/`REFORCE` lines just don't say **which
  path or member** they belong to, so no soak can currently attribute an inflate to a file. Add the
  path/`tocEntry` (and which of the five branches was taken) to those lines, soak, and answer two
  questions with it: does a `.list` read ever reach `sub_821D5E10` at all, and if so which branch rewrites
  it? Only after that should any serve offset or `isList` behaviour change. Acceptance: a named branch +
  path per inflate vs baseline `build/w38t.log`, with every other marker unchanged (logging-only ⇒ the
  census must be identical, and F-067's `C0000005 0` must stay 0).


**F-072 — 2026-09-20 21:18. A/B/A over four soaks and three builds: the boot's **per-marker** counts are
bit-reproducible, but `host short-circuit lines` and the other aggregates swing by **±80 between runs of
identical source**, so several headline numbers the project has been comparing (including F-063's
"177 → 96") are inside that band and cannot carry a causal claim. Also answers F-071(5)'s question about
which inflate branches fire. FACT (methodology) · D · P0.** Soaks `build/w38t.log`, `w38u.log`,
`w38v.log`, `w38w.log`; builds 23:45 (T41.3d), 00:06 (+1 census block), 00:13 (block reverted ⇒ source
identical to the 23:45 build, exe size restored to 97,362,944). All four `BOOT_RC=124`, 120 s.

- **(1) Bit-stable across all four runs (the valid acceptance set).** `C0000005` **0**, `GFx` **3**,
  `Fatal error` **2**, `PRESENT` **68**, `DRAW_INDEXED` **0**, `swfCMD` **2**, `GETDEV` **185**,
  `CP-DRAW` **24**, `MSGBISECT` **35**, `UILOAD` **1** (the host-text false positive of F-067(5), stable),
  `PKG-SUBST` **19**, `GLOBTEX-SERVE-DONE` **13**, the `star_glow` "wasn't preloaded" fatal **2**,
  `CP truth drains=8 pub==put=11`, and *"fault-line guest lr: none"* — identical in every run. **F-067's
  T41.3d result therefore reproduces**: four runs, zero access violations, and a stable frontier at the
  `swfCMD::Fixup` stage.
- **(2) Not reproducible (the aggregates).** `host short-circuit lines` = **98 (w38t) → 166 (w38u) →
  172 (w38v) → 176 (w38w)**; `[warning]` 2,929 → 3,360 → 3,360 → 3,325; `INFLATE` 387 → 503 → (n/a) →
  463; `WAIT`/`WAKE`/`rptrWB`/`PUT=` ±20 between the two same-exe runs; `PARK-SAMPLE` ±6;
  `[error]` 41 → 39. Spread on identical source: **78 lines of short-circuit count**.
- **(3) The observer-effect hypothesis was tested and is NOT the explanation.** The 00:06 build added one
  throttled `MCLA_LOG_WARN` in the inflate hook (40 lines emitted, no control-flow change); reverting it
  in the 00:13 build did **not** return to 98 but moved further to **176**. So the ordering tracks
  wall-clock/thread interleaving, not the instrumentation, and **`w38t` is the outlier** (its 11,072
  lines vs ~11.5k in the others). Practical rule established here: *read per-marker counts (1), and treat
  aggregate mitigation totals as a gauge with ±80 noise; a claim needs the marker table, and a
  same-source repeat run to say anything about the aggregate.* F-063's and F-067's aggregate sentences
  should be re-read under that rule (their marker tables do hold up).
- **(4) F-071(5)'s question, answered by the reverted-away census (`w38u.log`, 40 samples).** Of the five
  stacked conditions on the `sub_821D5E10` hook, **30/40 fire none** (`bad=false walk=false j2=false
  pkghead=false zero=false repoint=false` — the inflater proceeds unmodified), **8/40 fire
  `bad+walk+zero ⇒ repoint`**, and **1/40 `pkghead ⇒ repoint`**. The `magic` word at the inflate source is
  `0FF512EF` in **1 of 40** and `05435352` in **0**; the rest are `DD7E8AC4`×11, `6655A8B1`×11,
  `5AECD510`×8, `00000000`×8 — i.e. **the guest's own inflater is being entered almost always with data
  that is not an XCompress/RSC5 head**, which is consistent with F-070(2)'s gap result from the other
  side. The re-point heuristics are *not* the main path; the main path is feeding the guest non-containers.
  Caveat stated: only the first 40 entries were logged and attribution to a path is by adjacency, so this
  is a strong signal, not a census of all 387+.
- **(5) Tree state after this entry.** The census block is **reverted**; `src/gpu_device.cpp` carries only
  T41.3d (F-067) among my edits, exe = 00:13 build = the w38t source, `mcla.exe` killed, and
  `build/w38w.log` is a fresh same-source reproduce of F-067's result. If the branch census is wanted
  again, re-add it as its own experiment with a same-source control run, per (3).


**F-073 — 2026-09-20 21:24. The archive's non-package member layout is decoded, and it pins the content
gate to one wrong length field: for the six `.list` members `w[1]` is the **expanded** size and
`w[3]&0xFFFF` is the **stored LZX length** (ratios 1.96-3.76, all six inside the `0xD0000..0x35A000` gap,
no overlaps), while `XsfOffsetCandidates` serves the list form with `szs = w[1]` — expanded-length bytes
read from a compressed position and never inflated.** FACT + FIX SPEC · C/E · P0. Offline check over the
12 distinct `TOC76-XSF` quads in `build/w38w.log` + `src/gpu_device.cpp:473-530`, `:495-512`. No build,
no soak; this is the read-only half of T41.3e3.

- **(1) The layout, with the numbers.** Per member (values as logged, i.e. after `XSF-OPEN-GATE` sets bit
  30 in `w[2]`; subtract `0x40000000` to recover the stored position):
  `shaders/ui/preload.list` w1=260, w2=`0x1DD11C`, csz=126 (2.06x);
  `shaders/effects/preload.list` 368 / `0x304E12` / 188 (1.96x);
  `shaders/city/preload.list` 1246 / `0x1F4A3B` / 452 (2.76x);
  `shaders/cars/preload.list` 1108 / `0x27E5CF` / 460 (2.41x);
  `shaders/characters/preload.list` 496 / `0x2DB961` / 132 (3.76x);
  `textures/global/cars/globaltex.list` 575 / `0xD0000` / 236 (2.44x).
  **All six `w[3]` carry bit 30 in the guest's own TOC** (`openGateBit30=0` on the first read), so bit 30
  of `w[3]` is a *stored-is-compressed* flag, not part of a size — F-068(3)'s open question answers in the
  affirmative and F-070(2)'s gap is its consequence. Every position lies inside the
  `0xCFFE9..0x35A000` gap ⇒ **that region is the archive's non-package member area, holding headerless LZX
  blocks whose sizes are out-of-band in the TOC**, which is exactly why F-072(4) found a container magic at
  the inflate source in only 1 of 40 samples.
- **(2) Why 19 of the 31 serves work.** For the six `.xsf`/`.xtd`, `w[1]` is **32768 for every one** — a
  window size, matching `dSz=32768` in `W27-XC-FULL` and `in=32768` in `INFLATE` — and their `w[2]`/`w[3]`
  are not offsets in this reading at all. Those paths work only because `PKG-SUBST` swaps in a whole real
  RSC5 window (`0x60000`/`0xA0000`), so the guest's *package* reader handles them. A `.list` has no
  package to substitute, hence 12/12 raw reads.
- **(3) Codec identity, corrected mid-entry.** My first guess was headerless Xpress; the tree's own
  comment refutes it — `src/gpu_device.cpp:2203-2205`: *"XMemDecompress (RPF3 LZX) - the real unsquish for
  archive … `8244FF20` = XMemDecompress dispatcher (codec must be 1/LZX)"*. So **the guest already owns
  the decoder**; the host must not grow one. Deliver the stored bytes at the stored length and let
  `sub_8244FF20` run. No offline decode was attempted (LZX is out of scope and unnecessary).
- **(4) The defect is one field.** `src/gpu_device.cpp:500-506`, the "w18 list-form" branch, sets
  `offs[n] = w2 & 0xFFFFFF; szs[n] = w1;` — the **expanded** size at the **compressed** position —
  over-reading by `w1 - csz` (180 of 368 bytes for the effects list, into the neighbouring member) and
  then presenting the result as finished content. The enclosing function is a five-branch guesser over the
  four TOC words (it opens with `(void)w0; (void)w3;` and its own comment says *"NOT always
  {off,size,uncomp}"*), which is why the semantics were never pinned down. Under (1) the list branch wants
  `offs = w2 & ~0xC0000000` (stored position, host-set bit 30 excluded), `szs = w3 & 0xFFFF`, gated on
  `w3 & 0x40000000`.
- **(5) Fix spec, ordered so it stays attributable.** Step 1 is *not* the length change: re-add the
  F-071(5) census and additionally print the stored fields and whether `sub_8244FF20`/`XMemDecompress` is
  reached for a `.list` at all (prediction: it is not, because the host hands the guest what looks like a
  finished body). Step 2, only on that evidence: set the list length to `w3 & 0xFFFF` **and stop the
  no-magic passthrough treating a flagged-compressed member as already-inflated**
  (`src/gpu_device.cpp:6838-6841`'s `badMagic` must not imply "copy through"). Acceptance: a
  `GLOBTEX-BODY ascii=` field that is actually a name list (`star_glow`, `rage_im`, `.fxc` are the
  witnesses), then the `Unable to load shader 'star_glow', it probably wasn't preloaded properly` fatal
  disappearing because the preload has entries. Per F-072, run a same-source control beside it — the
  aggregate gauges cannot show this; the per-marker table and the `ascii=` content can.
- **(6) Scope, stated honestly.** This explains the **preload** family (the shader/texture lists) and
  therefore the effect-loader fatal that has gated the path since F-061. It does **not** by itself reach a
  menu: the `.xsf` UI packages arrive by the substituted package route, and `swfCMD::Fixup` (T38.4) is
  still downstream and unfixed. What changes is that the largest unexplained item in the content path now
  has a mechanism, a one-field defect site, and a log-readable acceptance test.

**F-074 — 2026-09-20 21:31. The RPF3 format reference that the VFS was written against has been
recovered from git and it names the false assumption directly: `src/fs/vfs_rpf.h:16-18` claims archive file
data is **STORED** ("`file_size == uncompressed` so no XMem LZX decode is needed on our side"), while the
restored §7/§8 rule is *compressed iff those two differ* — and all six `.list` members from F-073 differ,
by 1.96-3.76x. The guest's LZX decoder is already working (`XMEM` 22x, **all `ret=0`**); it is simply
never handed these members.** FACT + RECOVERY · C/E · P0. Closes the citation half of T39.3/T41.14 for
this file and gives T41.3e4 its mechanism.

- **(1) The document was destroyed, not missing-by-design.** `docs/MCLA_RPF3_Technical_Reference.txt`
  (27,073 B, 591 lines) existed through `82cb758` and was deleted by **`5fbc08e` "remove docs, build
  artifacts, and AI tooling files"** — the same data-loss event whose `.gitignore` hole `5eb9932` later
  closed. `HANDOFF_NEXT_AGENT.md:350` (session **75g**, 09-11) records the loss ("lost to the gitignore;
  folded into …"), but three live citations survived and one was never re-checked:
  `src/fs/vfs_rpf.h:16` and `src/gpu_device.cpp:2204` both still point at the missing path. **Restored
  into `docs/` this session** (`git check-ignore` rc=1 ⇒ not ignored; `git add` will track it normally).
- **(2) The authoritative layout, which the host never had while guessing.** §3/§4/§5:
  zero page → header at `0x800` (`RPF3`, `toc_size`, `entry_count`, **big-endian**) → TOC at `0x1000`,
  entries **exactly 16 B**: `{name_offset INT24 | type_flags, data_offset, file_size /*compressed*/,
  uncompressed}`, `data_offset` **absolute from file start**, `byte[3] & 0x80` = directory; §6 names are
  null-terminated ASCII in a section at `0x1000 + toc_size`; §7 the deciding rule
  **`file_size != uncompressed ⇒ compressed`**; §8 the codec is **XMem LZX** (`XMEMCODEC_LZX = 1`, block
  `0x10000`), with raw-zlib as the documented fallback; §9 the **TOC block itself is AES-CBC encrypted**,
  key inside the game image; §10 RAGE uses two custom **filename hashes**.
- **(3) Three prior findings are now explained rather than merely measured.** (i) F-066(7)'s
  whole-archive grep finding no plaintext path name, and F-064's `B116A6AB @ 0x800` high-entropy "TOC
  decrypts at runtime" — that is §9's AES-CBC TOC, documented. (ii) F-070's "the `.list` offsets fall in
  a gap between RSC5 packages" is not a mystery: per §5 `data_offset` is absolute into a region that
  legitimately holds plain member data between packages. (iii) `w[0] = 0x0DB1C876` being discarded by
  `XsfOffsetCandidates` (`(void)w0;`) is correct — it is a §10 hash / name offset, never a number to
  seek by. Conversely the same function's five-branch guessing over `w[1..3]` exists *because* the layout
  in §5 was unavailable to whoever wrote it; §5 now supersedes it.
- **(4) The false assumption, in the source's own words.** `src/fs/vfs_rpf.h:16-18`:
  *"… filename section, then **STORED file data** (file_size == uncompressed so no XMem LZX decode is
  needed on our side)".* F-073(1) measured six members for which the two sizes **differ**, and §7 says
  those are compressed. Meanwhile `sub_8244FF20` (the guest's `XMemDecompress`) fires 22x in
  `build/w38w.log` **every one `ret=00000000`** on 7,179,936→7,179,940-byte calls — corroborating
  session 75h's row (`HANDOFF_NEXT_AGENT.md:349`: "XMemDecompress works … all `ret=0`"). So decoding is
  not the missing capability; **routing the compressed members to it is**.
- **(5) Consequences for T41.3e4, now that the format is documented.** (a) The list branch of
  `XsfOffsetCandidates` should be replaced by a §5-shaped read of the *guest's decrypted* TOC entry
  (the object at `entry=C60F9530`), i.e. use the documented `{data_offset, file_size, uncompressed}`
  triple rather than candidate arithmetic over four dwords — the guest already has the AES-CBC key
  working, so the host should consume its parse, never re-implement §9. (b) Where `file_size !=
  uncompressed`, the host must hand the guest `file_size` **stored** bytes and let `sub_8244FF20`
  inflate — which means the `badMagic` → "copy through as uncompressed" short-circuit at
  `src/gpu_device.cpp:6838-6841` is wrong for exactly this class (a headerless LZX member legitimately
  has no `0FF512EF` at its start, per §8; F-072(4) measured a container magic in 1 of 40 entries).
  (c) The `vfs_rpf.h:16-18` comment must be corrected as part of any such change — a later session
  reading it will otherwise re-infer "everything is stored", which is what this entry exists to kill.
- **(6) Not yet done, stated as the boundary.** No emulator behaviour was changed by this entry; the
  restore is documentation-only and `src/` still carries only T41.3d among my edits. §5's field order
  still has to be matched against the *guest's in-memory* entry (the host's `w[]` quad does not line up
  1:1 with it: `entry+8` holds `0x304E12`, which §5 would call `file_size`), so (5a) needs one census,
  not a blind rewrite.

**F-075 — 2026-09-20 21:40. T41.3e4 tested and REFUTED: serving the `.list` members at the stored
(compressed) length instead of the expanded length changes nothing in the guest. The reason is
instructive — both readings seek to the *same position*, so the experiment never varied the variable it
was designed to vary. `w[2]`-as-data-position is therefore still unproven, exactly as F-074(6) warned,
and the branch has been reverted rather than left as a sixth guess.** NEGATIVE RESULT · C/E · P1. Change
built (`build/w38x_build.log` `BUILD_RC=0`, exe 00:36) and soaked 120 s (`build/w38x.log`,
`BOOT_RC=124`, 11,487 lines) vs the same-source-except-this control `build/w38w.log`; then reverted and
rebuilt so the exe matches the source. Per-marker comparison (F-072's rule), not aggregates.

- **(1) The change did land and was observable.** Served lengths became the stored ones for all six
  members: `shaders/effects/preload.list off=00304E12 size=188`, `ui 126`, `city 452`, `cars 460`,
  `characters 132`, `globaltex 236` (was 368/260/1246/1108/496/575) — i.e. F-073's `w[3] & 0xFFFF`
  reading was implemented exactly, and the census proves the new candidate was taken.
- **(2) Nothing else moved.** `C0000005` 0 = 0, `GFx` 3 = 3, `Fatal error` 2 = 2, `PRESENT` 68 = 68,
  `DRAW_INDEXED` 0 = 0, `swfCMD` 2 = 2, `TOC76` 238 = 238, `INFLATE` 463 = 463, `MSGBISECT` 35 = 35,
  `XMEM` 28 = 28, `GLOBTEX-SERVE-DONE` 13 = 13, `BE710-SLOT` 49 = 49, `noneObj` 14 = 14,
  `wasn't preloaded properly` **2 = 2**. Only `GETDEV` moved, 185 → 169. The `GLOBTEX-SERVE-DONE
  lists=N inserted=M` ladder is byte-for-byte the same shape (16/8/40/35/9/13 with every second pass 0).
- **(3) Why the test could not have detected what it looked for — the design flaw in my own experiment.**
  The first four bytes at the served position are unchanged between the two builds (effects list head is
  `7590416E 03310845` in both `w38w.log` and `w38x.log`), because the *position* was identical and only
  the length differed; and the guest decodes nothing at either length. So this run refutes "**length** is
  the bug", not "position is right". Per §7 of the restored reference the two are inseparable — a correct
  `{data_offset, file_size}` pair is required — and only the length half was varied. Recorded so nobody
  reads (2) as "the archive path is fine".
- **(4) What is now actually supported.** The bytes at `w[2]` are high-entropy and are **not** an
  XCompress/RSC5 head (F-072(4): container magic in 1 of 40 inflate entries), no plaintext name fragment
  exists anywhere in the 2.13 GB archive (`shaders`, `.xsf`, `globaltex`, `preload.list`,
  `star_glow.fxc` all 0 hits — a *positive* result now, since §6 says names are stored as leaf fragments
  and those fragments are absent too), and §9 documents AES-CBC on the TOC. **The simplest reading of all
  three is that this archive's member data is encrypted as well as its TOC**, which would make every
  host-side serve-by-offset futile and would explain five weeks of `serveHead=`/`pkgSubst`/`REFORCE`
  accretion in `src/gpu_device.cpp`. Untested, and testable: `XMEM` already returns `ret=0` for the
  7 MB pack bodies, so *some* data is plainly LZX-decodable — the discriminator is whether the `.list`
  positions decode at all under the guest's own `sub_8244FF20`, which needs the position question settled
  first (F-074(5)(i): map §5's triple against the guest's decrypted entry, not against its guesses).
- **(5) Tree state.** The candidate branch is **reverted**; `src/gpu_device.cpp` carries only T41.3d
  among my edits; exe rebuilt to match. `w38x.log` is retained as the falsifying soak, and per rule 5 it
  is a new name, not an overwrite. Consequence for the queue: **T41.3e4 is closed as refuted**, and the
  live item is T41.3e5(i) — the mapping census — which must vary the *position*, not the length.

---


*Ledger continues with F-076+. (`F-050` was held open for the T38.2b answer and is now filled;
`F-051`/`F-052` were taken by the tooling session out of chronological order, `F-053` supersedes
half of `F-048`, and `F-054` quantifies what `F-051` measured the absence of.) Keep the format; keep
every claim tied to a log line, raw file words or `file:line`.*


