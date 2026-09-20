# ROOT-CAUSE VALIDATION — MCLA PC Rebuild (method + report + findings ledger)

> **Compressed 2026-09-20.** Part 1 = the audit method. Part 2 = the report as written at audit
> close (session 78b), with a short "what later superseded it" note. Part 3 = the **append-only
> evidence ledger F-001…F-039**, entries compacted to claim + evidence (F-numbers, titles,
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

# PART 3 — FINDINGS LEDGER (F-001 … F-039; append-only from here)

> **Compact format:** `F-### — title` then `type · class · priority` and the claim + evidence.
> Compressed 2026-09-20 (entries de-verbed; F-numbers, titles, classes, priorities and all
> addresses/evidence preserved). **Append new findings below F-039 — never rewrite old ones.**
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

*Ledger continues with F-040+. Keep the format; keep every claim tied to a log line, raw file words
or `file:line`.*


