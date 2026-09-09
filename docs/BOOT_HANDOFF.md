# BOOT HANDOFF - updated 2026-09-06 (session 64 — VSYNC-ISR deadlock fixed)

## Current state
- **Guest park blocker CLOSED.** Driver worker wakes (status=0) and the
  game runs 10+ min in loading screens with zero crashes.
- **Phase gates:** P1-P3 done; P4' steps 1-3 done; P4.5' done; P5' code
  complete, runtime test ongoing (see session 64 handoff).

## Session 64 — VSYNC-ISR Deadlock Fix (DONE)
Two root causes, both fixed (full evidence:
`docs/handoffs/2026-09-06-session64-vsync-deadlock-fix.md`):
1. **Spinlock poison:** `VdInitializeEngines` seeded gpuCtx+0x4148/+0x4158
   with 1, but `KfAcquireSpinLock` is 0=unlocked. The vblank ISR
   (`sub_82411478` r3=0 → `sub_82419718` when bit0 of 0x7FC86544 set)
   spun forever on the phantom holder (38.6M spins observed), wedging the
   vsync thread at ~frame 4 — so `SignalSchedulerTick()` never ran. Fixed:
   seeds are 0 now. `KfAcquireSpinLock` also stores BE r13 and has a 5s
   lock-recovery steal net (`KFSPIN-RECOVERY`).
2. **Phantom kernel-object wrappers:** `QueryKernelObject` trusted the
   guest header's Flink/Blink for wrapper identity; the guest driver
   rewrites them, so wait and release resolved DIFFERENT host Semaphore
   instances (wake-loss). Fixed: durable host-side identity map
   (`WrapperIdentityMap()` in xdm.h, keyed by header guest addr + Type).
- Verification: phase0_validator 13/13 PASS; ISR runs indefinitely;
  TICK-PROBE release every cycle; CP drains doorbells==drains, rptr==db.
- **Multiple waiters** share tick sem 0x40004D7C (main thread + worker):
  ~30ms release cadence consumed by race winner; ~7.5s successful wakes
  per waiter is EXPECTED (HW-like 30ms timeout pacing), not a bug.

## Session 63 — Scheduler Tick Semaphore Fix (DONE, superseded by S64)
- **Root cause of guest park:** `SignalSchedulerTick()` wrote to raw guest
  memory at offset 0x10 in the XKSEMAPHORE struct, but `KeWaitForSingleObject`
  resolves the object to a **host-side `Semaphore` wrapper** whose `Wait()`
  polls a separate `std::atomic<uint32_t> count` — never synced from guest
  memory. The signal never reached the waiter, parking the driver worker
  thread forever in a 30ms timeout loop (`NtWaitForSingleObject` on
  `obj@0x40004D7C`), preventing all GPU work submission after the initial
  2 doorbell drains.
- **Fix:** `SignalSchedulerTick()` now calls `QueryKernelObject<Semaphore>()`
  to resolve the host wrapper and `sem->Release(1, nullptr)`, which increments
  the host atomic AND calls `notify_all()` to wake the waiter.
- **Build: 2/2 files, 0 errors, linked.**
- **Next: runtime test** — verify the guest unblocks and draws reach the
  pipeline. Expect to see new log activity from DRAW_INDEXED handler and
  PipelineCache.

## Session 57 — P4′ Step 3: Render Thread (DONE)
- Render thread now owns ALL D3D12 calls.

## Session 58 — P4.5′: Copy Queue + Frame Pacing + Queue Depth (DONE)
- Copy queue, 30fps frame pacing, queue depth monitoring (warn 30, drop 60).

## Session 60-61 — P5′ Shader Pipeline (CODE DONE) + Park Identified
- PSO cache + async worker, root signature matching translator contract,
  grcFvf input layout — all wired (B9/B10/B11 code-complete). Details:
  `docs/handoffs/2026-09-06-session61-p5-shader-pipeline-and-park.md`.
- **Blocker now:** guest parks at ~t=4-7min in `WAIT[KWFSO]` loop
  (tid=0x69C0, lr=0x8242FC1C, obj@0x40004D7C, put=11 rptrWB=001F frozen);
  no draws ever reach B9-B11. Decode `sub_8242FB88`'s wait condition next.
- app.cpp: CVar LoadConfig now before InitD3D12 (native mode actually
  initializes D3D12 now).

## Session 59 — P5′: First Native Draw Wired (DONE)
- **DRAW_INDEXED now actually renders.** `sub_82420BA8` capture pushes
  `DrawIndexedCommand` with `{vbAddr, ibAddr, vbSize, ibSize, vbStride,
  ibFormat, indexCount}` to the render queue. Render thread reads guest
  memory, uploads VB/IB to D3D12, calls `DrawDynamicMesh()`.
- Added `vbSize` and `ibSize` fields to `DrawIndexedCommand` (read from
  VB descriptor at r5+8 and IB descriptor at r6+4).
- Index format auto-detected from `ibFormat` bit 0: 0=16-bit, 1=32-bit.
- **This should produce visible geometry** when VB/IB data is valid.

## Next: P5′ continued — PSO Management + Shader Pipeline
1. **PSO cache** — create D3D12 graphics pipeline state objects from Xenos
   shader hashes. Cache by `(VS hash, PS hash, blend/depth/rasterizer state)`.
2. **Root signature** — currently hardcoded test root sig; need to match
   Xenia's register layout (CBVs, SRVs, samplers).
3. **Vertex input layout** — decode Xenos FVF vertex declarations into
   D3D12 input element descriptions.

## Session 55 — Dispatch Fix (DONE)
- **Root cause:** Function table has non-NULL garbage (`0x0c800c800c800c800`)
  for uncompiled functions. When `sub_8218CC70` dispatches an uncompiled index,
  the garbage pointer was treated as a valid function address.
- **Fix:** Built `compiledFuncs` map from authoritative `PPCFuncMappings[]`
  (46029 entries, null-terminated). Dispatch hook checks map first; if not
  compiled, logs and returns without calling. If compiled, uses `targetFn & ~3u`
  masking (all targets misaligned with bit0 set).
- **Secondary fixes:** spdlog format strings (`%08X`/`%zu`/`%d` → `{}` format),
  reverted safety gates in ppc_recomp.10.cpp to original.

## Session 56 — Writer-Attribution Census (DONE)
- **Census v3 implemented:** dense logging, ring buffer (32768 snapshots),
  dispatch_entry.log, validity tracking
- **Free-time check:** Compares element first4 at alloc vs free — ALL 64
  detections are false positives (snapFirst4=CDCDCDCD fill pattern, curFirst4
  = initialized string data like "mcAmbientPath", "mcTrigger*", "vehTune*")
- **Slab scan:** `ScanPool16SlabsForOverflow()` found 0 actual overflows —
  freelist chain integrity intact across all slabs
- **Conclusion:** The 16-byte pool overflow is either (a) no longer occurring
  with current patches, or (b) the census approach doesn't detect the actual
  overflow pattern (writes past element boundary into adjacent elements)
- **Raw output:** `build/cache/pool16_writers.log`

## Next: P5′ continued — Runtime Test + Root Signature
1. **Runtime test** — run and verify PSO cache wiring works end-to-end
2. **Root signature** — if PSO creation fails (shader CBVs not in root sig),
   add CBV root parameters for VS/PS constant buffers (b0/b1)
3. **G-CORPUS-* gates** — verify all 1,264+ existing ucode shader dumps compile

## Run Receipt — 2026-09-09 06:02 (semaphore census, session 66)

- **Build:** `cb0de39` (census instrumentation `4a5c4cf` + ISR-lambda compile fix
  `cb0de39`). phase0_validator 13/13 PASS. imports.cpp.obj + mcla.exe relinked 06:01:17.
- **Effective mode: `native`** (log line 06:05:27 `mode=native`). Source =
  `build/cache/mcla.toml` (`renderer_mode = native`, deliberate per S64 "keep
  for runs"). `config/mcla_manifest.toml` is NOT consumed at runtime (zero src
  readers); its flip to `legacy` (`131c35f`) is documentation-only. Run kept in
  native to stay comparable with the S64 baseline.
- **Commits:** `131c35f` docs+toml audit resync · `4a5c4cf` census
  instrumentation · `cb0de39` mispasted TYPE-CENSUS block removed from
  VdSetGraphicsInterruptCallback ISR lambda (referenced KeWaitForSingleObject
  locals — would not compile). stash@{0} untouched.
- **Static read:** 5 wait paths (Nt→typed `obj->Wait`; Nt→unrecognized handle
  STATUS_TIMEOUT; KWFSO case 4 map-hit-Sem→fallback-Event; KWFSO case 5
  QueryKernelObject<Sem>; KWFSO default timeout-return). Removed asserts in
  `0adc159`: `timeout==0||INFINITE` ×2, `"Unrecognized kernel object type."`,
  `hThread != CURRENT_THREAD` (kept, renamed `th`).
- **Census (90s soak):** DWELL[KWFSO] 58/60 `<30ms` (timeout-paced), 1 `<1s`,
  1 `<1ms`, zero `>=1s`. TYPE-CENSUS 60× `type=00` (semaphore): obj=`40004D7C`
  dominant (timeout=0x1E=30ms, lr=`8242FC1C`) + one INFINITE wait on
  `40004DCC`. TICK-PROBE **60/60 `path=release`** — no guard bounce; release
  cadence 20.8ms early → ~44ms mid-load, consistent with S64's documented
  ~30ms timeout pacing (S64-era raw logs rotated out; receipt cites handoff
  numbers). RING probes ×40. Zero fatals/crashes in window.
- **Instrumentation follow-up:** `res=` always logs `pending` (census fires
  before wait resolution is set) — move the res field into the DWELL log next
  census. DWELL[NTWFSO] silent (guest uses the Ke path).
- **Queue:** S1–S3 deletion remains deferred post-stall (single-hook-owner
  verify + code-reviewer/security-auditor; S4 shrinks to patches.cpp GpuKick
  after that sweep). Manifest generator: **no node tooling exists in-repo**
  (zero .js/package.json) — the "Generated by node tooling" header is
  unverifiable here; previous `native` value was almost certainly a hand edit
  (matches S61's flip-and-restore pattern).

## Key Tables


| Address | Purpose |
|---------|---------|
| `0x827D5CC0` | Callback data table (written by `sub_82189E80`) |
| `0x827D5E40` | Registration table (written by `sub_82189E20`) |
| `0x827D6010` | Dispatch offset table (24 entries, sentinel at 23) |
| `0x82839254` | basePtr (set to `0x40002080` — GPU physical memory) |
| `0x82839270` | kConfigGlobal — always zero, unused/reserved BSS slot |
| `0x82830DB8` | 16-byte pool classHead (elemsize=16, capacity=1018) |

## Warnings
- `rexgpu-xenos.dll not loaded` — GPU emulation skipped per user directive
- stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening' REGRESSES
  boot (stalls ~5s) and hardcodes AUDLO answers - salvage individually, never pop.
- generated/default is a STALE second regen - only generated/ppc_xenon is
  compiled (CMakeLists). Do not decode from generated/default.
- Freeze line: no PM4, no manual GPU seeding, no opcode expansion.
- Census work in patches.cpp (sessions 37-56) was committed as part of the
  session-65 rescan checkpoint; no outstanding patches.cpp edits expected.
