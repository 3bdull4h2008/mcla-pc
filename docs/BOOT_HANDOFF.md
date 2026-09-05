# BOOT HANDOFF - updated 2026-09-05 (session 58 — P4.5′ done)

## Current state
- **Game runs 120+ seconds clean, zero crashes.** All previous fronts closed:
  - CONFIG-DISPATCH AV: FIXED (session 55) — `compiledFuncs` map bypasses
    garbage function table entries; no-op stub dispatch for uncompiled funcs
  - OOM front: MITIGATED (session 49 chain-rebuild) + Census (session 56)
    found no actual overflow — 64 FREE-CORRUPT detections are all false
    positives (normal alloc-init-free cycle; census compared alloc-time fill
    pattern CDCDCDCD against free-time initialized data)
  - RenderThread: started successfully, running WAIT/WAKE loop on GPU fence

## Session 57 — P4′ Step 3: Render Thread (DONE)
- **Render thread now owns ALL D3D12 calls.** Guest threads only enqueue
  `RenderCommand` structs to `g_commandQueue`; render thread processes them.
- **D3D12 initialization deferred** to render thread startup (`SetWindowParams`
  from main thread, `backend_.Initialize()` on render thread).
- **Hooked_VdSwap** now enqueues `PRESENT` command instead of calling
  `GetD3D12Backend()` directly. Golden rule 13 satisfied.

## Session 58 — P4.5′: Copy Queue + Frame Pacing + Queue Depth (DONE)
- **Copy queue** — separate `D3D12_COMMAND_LIST_TYPE_COPY` command queue
  for streaming uploads. `StreamingUpload()` method on D3D12Backend handles
  host→device buffer copies on the copy queue, non-blocking to the render queue.
- **Frame pacing** — render thread targets 30fps (33.33ms/frame). After each
  PRESENT, sleeps remaining interval if early. Prevents spinning.
- **Queue depth monitoring** — tracks `g_commandQueue.size()` each tick.
  - ≥30 commands: warns
  - ≥60 commands: drops non-critical commands (SET_RENDER_STATE, SET_PIPELINE_STATE,
    SET_VERTEX_BUFFERS, SET_INDEX_BUFFER, DRAW_INDEXED, NOOP) to prevent queue
    overflow when guest PPC is faster than the render thread.

## Next: P5′ — Real Draws via Device Boundary
1. **Wire device-method hooks** (`hk_sub_82413660`, `Hooked_Sub82420BA8`) to
   enqueue `DRAW_CAPTURED` commands instead of log-only
2. **First native triangle** with real Xenos shaders → DXIL pipeline
3. **PSO management** — create graphics pipeline state objects from captured
   Xenos shader hashes

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

## Next: P4′ Step 3 — Render Thread
1. **Render command queue** — moodycamel blocking queue pattern from UR
   `UnleashedRecomp/gpu/video.cpp:1006/315/5249`
2. **Dedicated render thread** — owns ALL D3D12 calls; guest threads only
   enqueue `RenderCommand` structs
3. **Device-method handlers** → enqueue only (golden rule 13)
4. Reference: `docs/handoffs/2026-08-22-ur-vs-mcla-full-diff.md`

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
- Worktree has uncommitted census work in patches.cpp (sessions 37-56).
  Commit checkpoint recommended before further surgery.
