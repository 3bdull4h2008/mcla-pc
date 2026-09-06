# Session 60-61 Handoff — P5′ Shader Pipeline Complete; Guest Parks Before Draws

**Date:** 2026-09-06
**Mode:** Continuation sessions S60/S61 (Cline)

## What was done

### S60 — P5′ B9/B10/B11 code-complete
- **B9 PSO cache:** `PipelineCache` + async DXC worker, keyed by
  (VS hash, PS hash, blend/depth/raster state). Wired in `render_thread.cpp`:
  on `DrawIndexedCommand`, reads guest shader container, runs
  `TranslateShader` (Xenos microcode → HLSL), builds input layout, calls
  `GetOrCompile` — first call MISS→async compile, HIT after.
- **B10 root signature:** rewritten to match translator HLSL contract:
  SRV descriptor table t0–t3 (visibility ALL — Xenos VS can tfetch),
  root CBV b0 (visibility ALL), static sampler s0 (visibility ALL).
  Shared between the Phase-3 test PSO and the PipelineCache worker
  (`InitPipelines` passes `m_rootSignature` to `StartWorker`).
  `CreateSrvHeap` widened to 4 descriptors, all pre-filled null SRVs;
  2D texture SRV lands in slot 1 (`t1` = `Texture2D`).
  `DrawDynamicMeshWithPipeline` binds a zero-filled 4 KiB constant bank
  (256 × float4, Xenos constant-file size) from the per-frame upload arena
  so translated shaders have defined constants.
  `BindDecodedTexture` always binds the (possibly null) SRV table.
- **B11 vertex input layout:** `grcFvf` decode → `BuildInputLayoutFromGrcFvf`,
  with VS-reflection fallback (was already mostly there from S59).
- **app.cpp bugfix (real):** CVar `LoadConfig(m_cacheRoot/"mcla.toml")` moved
  **before** `InitD3D12()`. Previously config loaded after, so
  `renderer_mode` was always the default `"legacy"` and native mode never
  initialized D3D12. This is why the earlier "native" run silently stayed
  legacy.
- TODO.md updated: B9/B10/B11 CODE DONE (S60); `config/mcla_manifest.toml`
  restored byte-identical (renderer_mode=legacy, node-owned file).

### Validation
- Build clean (clang-cl/Ninja, EXIT=0).
- **Native run** (`build/cache/mcla.toml: renderer_mode = native`):
  D3D12 init on RTX 3070 OK — new root signature accepted, test pipeline
  created, null-SRV heap OK, PipelineCache worker started, zero crashes,
  D3D12 debug layer silent.
- **Legacy sanity run:** normal boot, no regression.

## The blocker that matters now

**The guest parks before ever issuing a draw command.** 25-minute native
run (`run_long.txt`, 69,647 lines, started 05:50):

- Boot proceeds normally; loading/allocation activity continues the whole
  time (POOL16 allocator activity, P10/P9 task census — game threads alive).
- **`WAIT[KWFSO]` #7253 @ 06:15:29** — thread tid=0x69C0
  (`start=0x8242FB88` = driver worker, handoff S11 thread #12/#13)
  busy-loops: `NtWaitForSingleObject(obj@40004D7C, reason=3, to=30ms)` →
  timeout → immediately re-enter wait. Last logged state:
  `put=11 rptrWB=001F pc=005A0E10` — **frozen for the entire run.**
- GPU-side census at last CP activity (~05:54:17, then silence):
  `VDRAIN-CENSUS #7 def=0 gpuCtx=40002080 ctx+30=C601C5CC doorbells=2
   drains=2 swaps=0 exits[noCtx=2 noCtx30=0 noRing=4 sameWptr=0 busy=0
   rejected=0] A[base=C600C480 cap=8192 rptr=0019 db=00000019 wb=C701C4BC]`
  → guest used the ring twice; our CP drained both (rptr tracked the
  doorbell 0x19); then **no more doorbells, no drains, no fences, no
  presents** for 20+ minutes.
- `FENCE sub_821E5640` fired exactly 2× (05:54:36, tags 0x4 / 0x8004).

**Interpretation:** the driver worker waits on the GPU consuming work
(read-pointer writeback at its private ring slot), the ring shows drained
(rptr == db == 0x19), yet the waiter never sees its expected condition
(`rptrWB=0x1F` ≠ expected) and the game never submits more work.
`rptrWB=001F` > put=11 suggests the writeback location contains garbage/a
different ring's value — i.e., our CP writeback goes to `wb=C701C4BC` but
the guest's waiter reads a different address, or the wait-object semaphore
is never signaled with the right payload.

## Next session (stale-ring park → first draw)

1. **Decompile `sub_8242FB88` / the loop calling `8242FC1C`** (the parked
   waiter): what exactly does it compare after the wait? Identify the
   writeback address it polls (`rptrWB`), and what must be stored there.
2. **Trace our CP writeback path**: confirm where the drained rptr is
   written (wb=C701C4BC?) and whether the value format matches what
   8242FC1C's loop expects (packet count vs byte offset is a classic 4×
   mismatch: put=11, rptrWB=1F — check both units).
3. Check whether the waiter's semaphore (obj@40004D7C) should be signaled
   on drain completion and isn't.
4. Only after the park unblocks: first `DrawIndexedCommand` → PSO MISS →
   async compile → draw (B9–B11 get their first real exercise).

## Files touched (S60)

- `src/d3d12_backend.h`, `src/d3d12_backend.cpp` (root sig, SRV heap,
  CBV binding)
- `src/render_thread.cpp` (pipeline wiring — pre-existing S59 work kept)
- `src/app.cpp` (CVar load ordering)
- `src/renderer/pipeline_cache.h` (pre-existing; unchanged)
- `TODO.md` (B9/B10/B11 status), this handoff
