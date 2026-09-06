# Session 64 Handoff — VSYNC-ISR Deadlock Root-Caused & Fixed; Guest Unblocked

**Date:** 2026-09-06
**Mode:** Continuation session S64 (Cline, gpu-engineer)

## What was done

### 1. Runtime test of the S63 scheduler-tick fix → park STILL present (run A)
- Built clean, ran 25 min (native mode via `build/cache/mcla.toml`).
- Worker still parked: `WAIT[KWFSO]` 30ms loop, tid=0x43FC, lr=**0x8242FCB0**
  (NOT 8242FC1C — there are TWO wait sites in `sub_8242FB88`; both call
  `KeWaitForSingleObject(r26+32 /*sem*/, reason=3, mode=1, alertable=0,
  timeout)`. 30ms = the `0xFFFB6C20` BE int32 stack timeout ≈ -30.3ms).
- put/rptrWB now ADVANCE (11→15, 0x1F→0x2B) vs S61's frozen run → S63 fix
  partially worked (work flows), but semaphore never satisfies the waiter.
- Zero successful `WAKE[KWFSO]` in 6,663 waits.

### 2. Guest worker loop decoded (`generated/ppc_xenon/ppc_recomp.80.cpp`
lines 32081+, `sub_8242FB88`)
- Periodic maintenance ticker: wait on sem → on STATUS_TIMEOUT (258) run
  maintenance at loc_8242FC3C (RtlEnterCriticalSection on
  `[[r24=0x82000000-deref]+2148]+14944`, flag check +10942 bit1,
  `sub_82419E90/98`) → re-wait at loc_8242FCB0 → loop.
- Escapes only when wait returns != 258 → KeResetEvent(r26+32) →
  [r25+4]==0 ? return 0 : sub_8242F870(r26) → loop head.

### 3. Instrumented vsync ISR (session 64 probes, all still in code)
- `VSYNC-ISR enter/exit f={} spin={:08X} flips={}/{} cb={:08X}` — every
  frame, plus GPU-ctx diagnostics (+16712 spinlock, +16700/16704 flip
  cur/tgt, +16544 flip-done cb).
- `KFSPIN-CONTENDED lock@{:08X} holder_r13be={:08X} spins={} lr={:08X}` in
  KfAcquireSpinLock + `KFSPIN-RECOVERY` 5s steal net.
- `TICK-PROBE #{} path={}` in SignalSchedulerTick (invalid/translate/
  no-sem/release).
- `KOBJ-TYPEFLIP` in QueryKernelObject (header Type byte rewrite detector).

### 4. ROOT CAUSE #1 (deadlock): our own spinlock seed poisoned the vblank ISR
- `KfAcquireSpinLock` protocol: **0 = unlocked** (CAS expected 0), stores
  holder r13.
- Our `VdInitializeEngines` seeded `gpuCtx+0x4148` and `+0x4158` with **1**
  ("TU83 expects non-zero" heuristic) → phantom permanent holder.
- Evidence: `KFSPIN-CONTENDED lock@400061C8 holder_r13be=01000000
  spins=38627328 lr=82419734` — the vblank handler `sub_82419718` (called
  from ISR `sub_82411478` r3==0 path when bit0 of **0x7FC86544** set — the
  old "bit0 park" address) spins forever on 0x01000000 = BE-encoded 1.
- ISR wedged on ~frame 4 → vsync thread dead → SignalSchedulerTick never
  ran → worker park. This ALSO retroactively explains S61's frozen ring
  (ISR ran ~4 min there, then wedged the same way).
- **FIX:** `VdInitializeEngines` now seeds both spinlocks with **0**.

### 5. ROOT CAUSE #2 (wake-loss): phantom kernel-object wrappers
- `QueryKernelObject` keyed wrapper identity in the GUEST header
  (Flink==OBJECT_SIGNATURE / Blink=wrapper). The guest driver owns its
  headers and rewrites Flink/Blink → wait path and release path resolved
  DIFFERENT host Semaphore instances (releases landed on orphaned wrapper,
  count climbed 1..7 unconsumed — seen in SEMA-release probes).
- **FIX:** durable host-side identity map `WrapperIdentityMap()` in
  `xdm.h` — keyed by (header guest address, header Type byte);
  `QueryKernelObject`/`TryQueryKernelObject` consult it first;
  `DestroyKernelObject` erases (`KernelObject::identityHdrAddr` added).
- **FIX:** `KfAcquireSpinLock` now stores byte-swapped (BE) r13 so guest
  inline BE readers see coherent values; + 5s LOCK-RECOVERY steal net.

### 6. Verification (runs C/D/E)
- phase0_validator: **13/13 PASS** with the identity map.
- ISR runs indefinitely (frame 2040+ / 8124+ per run), zero
  KFSPIN-RECOVERY, spin=00000000 every frame.
- TICK-PROBE `path=release` every cycle (~30ms cadence — sleep(16ms) +
  ISR + drain ≈ 30ms; NOTE: release cadence is 30ms not 60fps).
- Worker wakes with `status=00000000` (12+ wakes/run) — park GONE.
- **Multiple waiters share the tick semaphore** (main thread + driver
  worker both wait obj@0x40004D7C): 1 release per ~30ms is consumed by
  whichever waiter wins → each waiter still times out ~99% of the time
  and wakes successfully every ~7.5s. This matches HW semantics where the
  30ms timeout is the real pacing; not a bug.
- CP healthy: `VDRAIN-CENSUS` doorbells=32 drains=32, rptr==db every
  census, noRing-only exits, swaps=0. Guest submits, we drain instantly.
- Game survives 10+ min (was: wedged ISR at frame 4).

## Current state / next front
- The boot blocker (async/fence park) is CLOSED. Game runs in loading
  screens (VdSwap = loading flips, ~1/15s), P10 allocator churn continues.
- **Next gate:** game never reaches gameplay rendering — no
  `DRAW_INDEXED`/`PipelineCache` lines yet. Next front is the GPU-progress
  gate downstream: decode what the guest waits on after loading (fences /
  kick completion / subctx publication). Suggested mode: `gate-cracker`.
- Probe hygiene: VSYNC-ISR/KFSPIN-CONTENDED/TICK-PROBE probes are verbose
  (20-50k lines/run); demote before perf work (rate-limit to first 60 +
  every 5000).

## Files touched (S64)
- `src/kernel/imports.cpp`: VSYNC-ISR probe; KfAcquireSpinLock (BE store,
  contention probe, 5s recovery); VdInitializeEngines spinlock seeds 1→0;
  SignalSchedulerTick TICK-PROBE.
- `src/kernel/xdm.h`: WrapperIdentityMap + QueryKernelObject/
  TryQueryKernelObject rewrite + KOBJ-TYPEFLIP probe + identityHdrAddr.
- `src/kernel/xdm.cpp`: DestroyKernelObject erases map entry.
- `build/cache/mcla.toml`: created (renderer_mode=native) — keep for runs,
  node-owned manifest untouched.

## Warnings
- `<bit>`/std::byteswap NOT available in this clang-cl config — use
  `__builtin_bswap32` (helper `bswap32` at file scope in imports.cpp).
- run_commands tool kills foreground builds; use
  `launcher_build.bat` + `start /min` for builds, poll `build_out.txt`
  for `EXIT=`.
- cmd AutoRun in this environment prints `'vcvars64.bat' is not
  recognized` — cosmetic, ignore.
