# MCLA Boot / XenonRecomp Smoke-Host Rebuild Plan

## Purpose

Prove the recompiled MCLA guest code boots end-to-end on PC: from XEX entry
(`_xstart`, `0x821322B8`) through CRT/init and import-slot resolution to the
game's main loop — first in the standalone smoke host
(`tools/xenon_smoke/`), later inside `mcla.exe`. This is a prerequisite for
the native renderer: the Phase 9 "boot to a frame" gate depends on guest code
reaching real game functions that call `VdSwap`/present.

The smoke host removes the game's SDK/XenonUtils runtime dependency so boot
reachability can be debugged headlessly, deterministically, and without the
D3D12/live-capture pipeline. This document is an execution handoff. Follow
phases in order; never claim deep boot until the gates in each phase pass.

## Execution Status

Boot currently enters real recompiled TUs, executes real kernel stubs, and
**successfully creates the game's default heap** — the previous `READ @0x0`
dirty-disc crash is fixed. The boot now advances through file-system open,
Xam/net init, and Vd (video driver) ring-buffer init, then **spins forever in
the GPU command-processor fence wait** (`sub_82412F98` busy-flag
`[cpobj+10941] & 2`), which is expected with no GPU emulation. The proven
chain and fix record are in "Investigation record"; the remaining work is
gated per phase below.

## Definition of Done

- Guest code reaches a real game function that calls `VdSwap` / presents in
  the smoke host, or reaches the documented boot-finish point, deterministically.
- No `READ @0x0` at slot-dispatch. `0x8285FEA0` resolves to a validated target
  before `sub_821BD618` dispatches, and every dispatched callee has a non-NULL
  `PPC_LOOKUP_FUNC` table entry.
- Kernel/import stubs return values consistent with their documented 360
  semantics (checked via `.research/` recomp projects), so guest branches off
  bad `r3` garbage stop firing the dirty-disc handler.
- Boot remains deterministic across runs; tree builds clean (ninja, clang-cl,
  RelWithDebInfo, zero errors); default `renderer_mode` stays `legacy`.

## Current State and Constraints

### What exists

- `tools/xenon_smoke/` standalone host: loads `default.xex` into a 4 GiB
  guest arena, installs all 46,041 `PPCFuncMappings`, installs 246 kernel
  import stubs, boots on a worker thread under SEH.
- Fault triage in `FilterCapture`: `RtlCaptureStackBackTrace(0,24,...)` host
  stack, `NearestFunctionName` via `RtlLookupFunctionEntry` + reverse
  host→guest map (unreliable under ICF — do not trust to the byte), guest PC
  attribution from unwind unwind `BeginAddress`.
- Pre-boot slot initialization: `0x8285FEA0` is written (big-endian) to the
  validated landing target `0x82130678` before `RunBoot`.
- `--function=<addr>` direct-call mode validating single TUs call/return
  (`0x82130000` pure `blr`, `0x82130008` `li r3,1; blr`, `0x821320D0`
  800-byte frame).
- Generated TUs under `generated/ppc_xenon/` (input only, never patched);
  authoritative recomp reference `.research/XenonRecomp/` (keep, customizations
  preserved). `tools/XenonRecomp/` is an unreferenced copy (cleanup candidate).

### Non-goals for the first implementation

- Emulating the Xbox 360 kernel or all XamAPIs. Reachability first;
  behavior-correctness only where the guest's boot branch depends on it.
- Rebuilding the game's SDK runtime beyond what the recompiled TUs need to
  reach `VdSwap`.
- Making the smoke host render; rendering stays in `mcla.exe` / the native
  renderer plan.

### Constraints / golden rules

- `generated/` is input. Never patch recompiled sources.
- One hook owner per guest address. (Smoke host owns its stubs and table;
  `mcla.exe` owns its live hooks — they are separate processes/paths.)
- No invented draw/boot data. Every struct field and return value is
  researched (`.research/`, live capture, generated code) before trust.
- Build: Ninja + clang-cl for **both** C and CXX (MSVC C + clang-cl CXX
  fails), RelWithDebInfo; requires VS BuildTools `vcvars64.bat` on PATH.
  Delete `build-smoke/` when switching compilers.

## Target Architecture (boot path)

```text
XEX default.xex
  |  Xex2LoadImage -> memcpy to g_base + 0x82000000
  v
_xstart 0x821322B8
  |  (proven host-stack chain)
  v
sub_82132740 -> sub_827A7688 -> sub_82131228 -> sub_821C2E60
  |  (large init / title setup; calls sub_821BC0F0, bl 0x823d91f8)
  v
sub_821BD618  [import slot dispatcher]
  |  slot @0x8285FEA0 ; if 0 -> spin 0x821BD640
  |  ctx.lr = 0x821BD640 ; PPC_CALL_INDIRECT_FUNC(ctr) ; spin forever after
  v
PPC_LOOKUP_FUNC(base, ctr)  table entry (46,041 mappings)
  |  *(PPCFunc**)(base + IMAGE_BASE + IMAGE_SIZE + (ctr-CODE_BASE)*2)
  v
callee (validated target) -> ... -> VdSwap (boot finish)
```

Error path observed when a stub returns garbage `r3`:

```text
sub_82130678  (li r3,0 ; bl sub_82388598 ; bl sub_82131C58)
sub_82131C58  (bl __imp__XamShowDirtyDiscErrorUI ; li r4,0 r3,0 ; bl sub_821324A0)
sub_821324A0  (r3==0 -> beq -> b __imp__XamLoaderLaunchTitle)   <- guest LR 0x82131C74
```

## Phase Plan

### Phase 0 — Resolve the `READ @0x0` at slot dispatch (in progress)

**Gate:** smoke boot produces no `READ @0x0`; the fault report prints a
non-NULL `PPC_LOOKUP_FUNC(g_base, 0x82130678)` entry and precise ctr value.

- Instrument the fault printout to dump the dispatch table entry for the
  slot target (`*(PPCFunc**)(g_base + 0x829E0000 + (target-0x82130000)*2)`) and
  the slot value as the guest saw it.
- Determine definitively whether the NULL read is the **table read in
  `sub_821BD618`** or a **callee-side deref** (guest LR `0x82131c74` vs host
  stack `0x821bd618` tension; ICF attribution is unreliable — resolve by
  instruction-level evidence, not unwind maps).
- Ship the host-stack + regs + PPC_LOOKUP_FUNC evidence into this plan's
  investigation record so no future session re-derives the chain.

### Phase 1 — Import-slot resolution

**Gate:** `sub_821BD618` dispatches to a non-NULL, correct callee and does not
spin; boot advances past the first import thunk without fault.

- Research the 360/XEX import-table layout (`.research/XenonRecomp`,
  Xenia) so slot targets can be resolved from the XEX import table instead of
  pre-seeded by hand.
- Replace the single hand-written `0x8285FEA0` seed with table-driven
  resolution; keep the seed as a controlled fallback in smoke mode only.

### Phase 2 — Kernel/import stub return values

**Gate:** stubs return documented semantics; branches off bad `r3` stop firing
the dirty-disc handler (stub order stops showing
`XamShowDirtyDiscErrorUI`/`XamLoaderLaunchTitle`).

- Give the dirty-disc-chain stubs correct returns:
  `XamShowDirtyDiscErrorUI`, `XamLoaderLaunchTitle` (`0` success),
  `XexCheckExecutablePrivilege`, `XGetAVPack`, `ExGetXConfigSetting`.
- Validate each semantic against `.research/` before writing `s_StubCalled`
  return values.

### Phase 2b — Guest virtual memory stubs (DONE 2026-08-14)

**Gate:** heap global `[0x8294A5A0] != 0`; boot no longer faults in the buffer
pool allocator.

- Implemented real `NtAllocateVirtualMemory`, `NtQueryVirtualMemory`,
  `NtFreeVirtualMemory` in `kernel_stubs.cpp` backed by a guest-VA region
  allocator carved from Xenia's 64 KB-page range `[0x40000000, 0x7EFFFFFF]`
  (clear of image 0x82000000 / smoke stack 0x8F000000 / thread block
  0x8F200000 / physical bump 0xA0000000).
- Xbox 360 ABI (from Xenia `xboxkrnl_memory.cc`): no process handle;
  `r3=&base` (in/out), `r4=&size` (in/out), `r5=alloc_type`
  (`0x60001000` COMMIT / `0x60002000` RESERVE, `0x20000000` LARGE_PAGES),
  `r6=protect`, `r7=debug_memory`; returns NTSTATUS in `r3` (0=success).
  `NtQueryVirtualMemory` fills the 28-byte big-endian
  `X_MEMORY_BASIC_INFORMATION` (base@0, alloc_base@4, alloc_protect@8,
  region_size@0xC, state@0x10, protect@0x14, type@0x18).
- Heap-create flow `sub_821342B8` (generated .0.cpp:10993) reserve-calls
  `0x60002000` then commit-calls `0x60001000`; with real stubs the default
  heap lands at `0x40000000`. Probe `[0x8294A5A0]=0x40000000` verified.

### Phase 3 — Dirty-disc / title-launch path exit

**Gate:** guest no longer enters `sub_82130678` → `sub_82131C58` →
`sub_821324A0`; LR at the previously faulting site advances past
`0x82131C74`.

- Confirm which check's garbage `r3` first selects the error path (MITM the
  key stub call site via direct-call mode if needed).
- If the error path is legitimately reachable at boot regardless, give
  `sub_821324A0` a valid dummy string buffer path so it completes instead of
  faulting, mirroring `.research/XenonRecomp` customizations without touching
  `generated/`.

### Phase 4 — Deep boot reachability in the smoke host

**Gate:** boot deterministically reaches a named real game function past the
init/unpack stage (multi-call function graphs execute, not just
single-function `--function` calls), and the `--trace-tramps` tracer emits
entries.

- Fix `--trace-tramps` silence (direct host calls bypass table wrappers —
  trace at the dispatch helper, not at the PPCFunc wrappers).
- Extend `--function` direct-call coverage to small multi-call graphs.
- Track the furthest guest PC per run and record it here.

### Phase 5 — Fold boot proof into `mcla.exe`

**Gate:** `mcla.exe` boots through the same path headlessly or with a render
window and reaches `VdSwap` (native plan Phase 9 gate), with `legacy` still
default.

- Port the proven boot fixes (slot resolution, stub returns, dispatch
  hardening) into `mcla.exe`'s boot hooks.
- Keep the smoke host as the headless regression harness.

## Investigation record

### Proven (2026-08-13)

- Crash chain (host stack, innermost first): `_xstart` `0x821322B8` →
  `sub_82132740` → `sub_827A7688` → `sub_82131228` → `sub_821C2E60` →
  `sub_821BD618`. **`sub_821305B8` is not in the crash chain** (earlier
  assumption retired).
- `PPC_LOOKUP_FUNC(x,y) = *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
  + (uint32_t(y)-PPC_CODE_BASE)*2)`. Constants: `IMAGE_BASE 0x82000000`,
  `IMAGE_SIZE 0x9E0000`, `CODE_BASE 0x82130000`.
- Slot at fault is correct: raw LE `0x78061382` = BE guest `0x82130678`
  (mapping `{ 0x82130678, sub_82130678 }` present, ppc_func_mapping.cpp:31).
- Fault regs (latest run): `r1=0x8efffaf0 r3=0 lr=0x82131c74`, `READ @0x0`.
  `lr=0x82131c74` is the `bl 0x821324a0` return site inside `sub_82131C58`.
- Host fault PC zone `RVA 0xf5902e` decodes (raw bytes) as the dispatch
  `call qword ptr [r8+rax]` (`41 FF 14 00`) with `r8` = movabs
  `0xFFFFFFFF7E780000` (= `-(2*CODE_BASE) + (IMAGE_BASE+IMAGE_SIZE)`),
  immediately preceded by `mov r8d,0x821BD640; mov [rcx+0x50],r8`
  (= `ctx.lr = 0x821BD640`). Byte at reported RVA is `0xCC` (int3/padding) —
  exact faulting instruction still ± a few bytes, alignment via
  `fileOffset = RVA - 0x1000 + 0x400` (PE: ImageBase `0x140000000`, `.text`
  VA `0x1000`, PointerToRawData `0x400`, VirtualSize `0x26E2646`, 7 sections).
- Error-handler bodies: `sub_82130678` (ppc_recomp.0.cpp:1146,
  `li r3,0; bl sub_82388598; bl sub_82131C58`); `sub_82131C58`
  (ppc_recomp.0.cpp:4634); `sub_821324A0` (ppc_recomp.0.cpp:6301, r3==0 →
  beq → `b 0x827bce54` = `__imp__XamLoaderLaunchTitle`).
- Crash-path caller: `sub_821C2E60` (ppc_recomp.16.cpp:11661) — large init,
  `stwu r1,-128`, object-layout stores, `bl 0x823d91f8`, calls
  `sub_821BC0F0`. `sub_82131228` calls `sub_821C2E60` (ppc_recomp.0.cpp:3104).
- Stubs are void/log-only (garbage `r3`): `kernel_stubs_body.inc` —
  `XamShowDirtyDiscErrorUI` (193), `XamLoaderLaunchTitle` (183),
  `XexCheckExecutablePrivilege` (226), `ExGetXConfigSetting` (6),
  `XGetAVPack`. Prime suspect for driving boot into the dirty-disc handler.
- `PPC_CONFIG_CTR_AS_LOCAL`/`PPC_CONFIG_NON_ARGUMENT_AS_LOCAL`: `ctr`/`r11`/
  `r12` are compile-time locals — cannot read `ctx.ctr`; the trampoline writes
  `ctx.lr` (context offset `0x50`).
- Build is clean with the documented `vcvars64` + Ninja path (clang-cl
  19.1.7, RelWithDebInfo); boot is deterministic across runs.

### Proven (2026-08-14) — heap crash root cause + fix

- Heap global `0x8294A5A0` was **0** at the buffer-pool fault in
  `sub_82133438` (READ AV at guest `0xFFFFFFFF` walking the large-bucket
  free-list head at `[pool+384]`). The old `0x8274A5A0` probe read image-gap
  opcode bytes and was a red herring.
- Root cause: `NtAllocateVirtualMemory` / `NtQueryVirtualMemory` /
  `NtFreeVirtualMemory` were no-op log stubs, so boot-time heap creation in
  `sub_821342B8` could not produce a region. Run10 stub log proved the
  heap-create path ran (`__imp__NtAllocateVirtualMemory` hit during boot).
- Fix: guest-VA region allocator + real stubs in
  `tools/xenon_smoke/kernel_stubs.cpp` (SmokeVmAlloc/Free/Query,
  `SmokeNtAllocateVirtualMemory`/`SmokeNtQueryVirtualMemory`/
  `SmokeNtFreeVirtualMemory`), bodies replaced in
  `kernel_stubs_body.inc` (lines 194/453/516). `[0x8294A5A0]=0x40000000`
  verified in run12/run13.
- Post-fix boot: no heap fault; advances through `NtCreateFile` game-data
  opens, Xam/net init, thread creation, `VdInitializeEngines`,
  `VdSetGraphicsInterruptCallback`, `VdInitializeRingBuffer`,
  `VdEnableRingBufferRPtrWriteBack`, `KiApcNormalRoutineNop`, then **spins in
  the GPU fence wait** `sub_82412F98` (busy flag `[cpobj+10941] & 2`, timeout
  gate `r30-[r31+12] >= 5000` where `r30` = timer `[[r13+256]+88]`, kick via
  `sub_82425C18`). Suspended-worker RIP sample = `NearestFunctionName`
  `0x82412F98`. This is expected without GPU emulation — it is the Xenos
  command-processor sync path the native plan replaces.

### Open questions

- Is the NULL read the **dispatch table entry** (entry NULL/stale) or the
  **callee deref** (dirty-disc chain)? Guest LR `0x82131c74` says the guest
  is inside the error handler; host-stack attribution to `0x821bd618` is
  ICF-unreliable.
- Which stub's garbage `r3` first selects the dirty-disc path?
- Does `.research/XenonRecomp` already customize any of these stubs/slots,
  and must we mirror it?

## Build + run

```text
cmake -S tools/xenon_smoke -B build-smoke -G Ninja ^
  -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl ^
  -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build-smoke
build-smoke\xenon_smoke.exe build\game_data\default.xex
build-smoke\xenon_smoke.exe --function=0x82130000   # direct TU call
```

Caveat: BOTH compilers must be clang-cl; delete `build-smoke/` when switching
compilers. VS BuildTools `vcvars64.bat` must be on PATH (call it before
building).

## Handoff checklist (every continuation)

- [ ] Single hook owner per guest address confirmed
- [ ] Generated code untouched
- [ ] Default `renderer_mode` still `legacy`; prior mode still functional
- [ ] Built cleanly; build command + result recorded here
- [ ] Fault/evidence (host stack, regs, PPC_LOOKUP_FUNC entry) recorded above
- [ ] Never claimed deeper boot than the gates prove

## Status legend

- **Phase 0** — done (2026-08-13: host-stack instrumentation, crash chain +
  slot semantics proven)
- **Phase 1** — in progress (2026-08-14: heap crash fixed via real
  NtAllocateVirtualMemory/NtQueryVirtualMemory/NtFreeVirtualMemory stubs;
  boot now reaches the GPU command-processor fence wait `sub_82412F98` and
  hangs waiting on hardware that does not exist in the smoke host)
- Phase 2–4 — not started
- Phase 5 — not started (depends on native plan Phase 9 entry)