# BOOT HANDOFF — 2026-09-09 (sessions 55-68)

## Current state
- **Semaphore fix: DONE.** Rung-3 verified (static read 5/5, census 58/60
  `<30ms` dwell, 60× `type=00`, phase0_validator 13/13, zero fatals/90s).
  All 5 wait/release paths use `QueryKernelObject`/`TryQueryKernelObject`;
  `ResolveCreatedObject` removed; Type=0 fallback safe. Closed, no revert.
- **Phase gates:** P1-P3 done; P4' steps 1-3 done; P4.5' done; P5' code
  complete (PSO cache, root sig, vertex layout, DRAW_INDEXED wired).
  Native renderer wired but not producing frames.
- **BLOCKER: STALL.** 14 threads parked INFINITE at `sub_82135DC0`
  (lr=82135DF8). Zero GPU hook hits. Screen manager never fires. The stall
  is the primary blocker — "stable for 2.5h" = "stalled for 2.5h."
- **Crash: STALE.** One access violation on 2026-09-01 binary
  (pre-semaphore-fix). Not reproduced on HEAD. Exit-code mismatch
  (`0x80000003` vs `0xC0000005`) unexplained. Background attribution only.

## Next — CRITICAL PATH (stall investigation)
1. **Ghidra decode of `sub_82135DC0`:** what event VA(s) do the 14 parked
   threads wait on? Who signals them? No guest signaller exists module-wide
   ⇒ kernel-role (session 9 finding).
2. **TODO R1:** HW kernel ISR → driver-event signaling research queue.
   Identify the missing signal source that would unblock the 14 waiters.
3. **Crash attribution (background only):** map host RIP `0x7FF699F3891D`
   via `mcla.pdb`; trace provenance of `0x829E0000` pointer; explain
   `0x80000003` vs `0xC0000005` mismatch. Do NOT reprioritize stall work.
4. **Once stall resolved:** verify GPU submission chain resumes (wptr advances,
   F98/E98 fire, VdSwap called, frames render).

## Session history

### Session 68 — Audit + Crash Disposition (2026-09-09)
- Semaphore fix closure accepted (rung-3 verified, not the regressor).
- Crash conclusion rejected — stale binary, weak attribution, not reproduced
  on HEAD. Do not treat as active blocker.
- Stall reframed as primary blocker. Named terminal state: STALLED.

### Session 66 — Semaphore Census (2026-09-09)
- Build: `cb0de39`. Effective mode: `native` (from `build/cache/mcla.toml`).
- Census v2: DWELL[KWFSO] 58/60 `<30ms` (timeout-paced), TYPE-CENSUS 60×
  `type=00` on `0x40004D7C`, TICK-PROBE 60/60 `path=release`, RING ×40.
- Static read: 5 wait paths verified; broken asserts removed in `0adc159`.
- Instrumentation follow-up: `res=` always `pending` (fires before wait
  resolution); DWELL[NTWFSO] silent (guest uses Ke path).
- Commits: `131c35f` docs+toml audit · `4a5c4cf` census · `cb0de39` ISR fix.

### Session 64 — VSYNC-ISR Deadlock Fix (DONE)
Two root causes, both fixed:
1. **Spinlock poison:** `VdInitializeEngines` seeded gpuCtx spinlocks with 1,
   but `KfAcquireSpinLock` is 0=unlocked. Vblank ISR spun forever (38.6M
   spins), wedging vsync thread. Fixed: seeds are 0, plus 5s recovery steal
   net (`KFSPIN-RECOVERY`).
2. **Phantom kernel-object wrappers:** `QueryKernelObject` trusted guest
   header Flink/Blink; guest rewrites them → different host wrappers for
   wait vs release → wake-loss. Fixed: `WrapperIdentityMap()` (xdm.h, keyed
   by guest addr+Type, under `g_kernelLock`).
- Multiple waiters share tick sem `0x40004D7C`: ~30ms release cadence,
  race-winner consumption, ~7.5s successful wakes per waiter is EXPECTED
  (HW-like timeout pacing).

### Session 63 — Scheduler Tick Semaphore Fix (superseded by S64)
- Root cause: `SignalSchedulerTick()` wrote to raw guest memory but
  `KeWaitForSingleObject` resolved a host-side wrapper whose `Wait()` polls
  a separate atomic — never synced. Fix: `QueryKernelObject<Semaphore>()`
  + `sem->Release(1, nullptr)`.

### Session 60-61 — P5' Shader Pipeline (CODE DONE)
- PSO cache + async DXC worker, root signature matching translator contract
  (SRV t0-t3, root CBV b0, sampler s0), grcFvf input layout — all wired.
- `DrawDynamicMeshWithPipeline` binds 4 KiB constant bank (256 × float4).
- `app.cpp`: CVar `LoadConfig` moved before `InitD3D12` (native mode now
  actually initializes).

### Session 59 — P5' First Native Draw Wired
- `sub_82420BA8` capture pushes `DrawIndexedCommand` with full VB/IB
  descriptors to render queue. Render thread uploads to D3D12, calls
  `DrawDynamicMesh()`. Should produce visible geometry when data valid.

### Session 58 — P4.5' Copy Queue + Frame Pacing
- Copy queue, 30fps frame pacing, queue depth monitoring (warn 30, drop 60).

### Session 57 — P4' Step 3: Render Thread
- Render thread owns ALL D3D12 calls.

### Session 56 — Writer-Attribution Census
- Census v3: 64 detections all false positives (CDCDCDCD fill pattern).
- Slab scan: 0 actual overflows. Pool overflow not occurring with current
  patches or not detectable by this method.

### Session 55 — Dispatch Fix
- Function table had garbage `0x0c800c800c800c800` for uncompiled functions.
- Fix: `compiledFuncs` map from `PPCFuncMappings[]` (46029 entries), dispatch
  hook checks map first. `targetFn & ~3u` masking (all misaligned, bit0 set).

## Key tables
| Address | Purpose |
|---------|---------|
| `0x827D5CC0` | Callback data table (written by `sub_82189E80`) |
| `0x827D5E40` | Registration table (written by `sub_82189E20`) |
| `0x827D6010` | Dispatch offset table (24 entries, sentinel at 23) |
| `0x82839254` | basePtr (`0x40002080` — GPU physical memory) |
| `0x82839270` | kConfigGlobal (zero, reserved BSS slot) |
| `0x82830DB8` | 16-byte pool classHead (elemsize=16, capacity=1018) |

## Warnings
- `rexgpu-xenos.dll not loaded` — GPU emulation skipped per user directive.
- stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening' REGRESSES
  boot (stalls ~5s) and hardcodes AUDLO answers — salvage individually, never pop.
- `generated/default` is STALE — only `generated/ppc_xenon` is compiled.
- Freeze line: no PM4, no manual GPU seeding, no opcode expansion.
- Manifest `renderer_mode` lives in `build/cache/mcla.toml` (runtime), not
  `config/mcla_manifest.toml` (docs-only, zero src readers).
