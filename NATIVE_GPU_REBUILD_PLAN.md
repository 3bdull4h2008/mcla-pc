# MCLA Native PC GPU Rebuild Plan

## Purpose

Replace the current Xenos-command-processor rendering path with a native PC
renderer. The goal is **not** to emulate the Xbox 360 GPU more efficiently.
The game should continue to run as recompiled PPC code, but its rendering
intent should be captured at the high-level draw boundary and executed as
Direct3D 12 work using native resources, shaders, and pipelines.

This document is written as an execution handoff. Follow phases in order.
Do not remove the compatibility renderer until the validation gates say it is
safe.

## Execution Status

**Xenon Smoke Harness Boot Progress (2026-08-13):**
- **XTL Import Chain Resolved:** Implemented the guest r13 thread block (0x8F200000) and import dispatch chain (sub_82130528 family, slot 7 = offset 28) in SetupInitialContext, backed by guest alloc/free stubs registered in the function table via InsertFunction. The dispatch resolves through: *(r13) → table base P; *(P+28) → descriptor E; *E → func block F; *(F+8) alloc stub, *(F+12) free stub.
- **Global Table Pointer Initialized:** Added pre-boot initialization for the global table pointer at 0x8288E5AC (read by sub_82388598), pointing it to a scratch table region (0x8F207000).
- **Boot Milestone:** xenon_smoke.exe now successfully boots past the allocation thunks and table lookups, reaching initialization trap sub_821BD618 (int 3 / breakpoint). 17 distinct kernel imports are now logged (previously 15 before the table ptr fix).
- **Status:** native mode render path (hasGrcFvf=1) still shows the fallback meshed triangle (renderer_mode default remains legacy per phase gates); the boot chain advance represents the new session's headway toward later phases.

Phase 0 is implemented and builds as of 2026-08-04. The implementation adds
the `renderer_mode` CVar (default: `legacy`), low-noise frame counters, a
single-owner submit-hook dispatcher, context-layout assertions, and a debug
ordering assertion for submit observers. `sub_82420BA8` is now passthrough
again: the experimental direct `CommandProcessor::IssueDraw` call no longer
executes. The `capture` and `native` mode values are configuration placeholders
until their corresponding implementation phases are complete; both currently
preserve the legacy rendering path.

Phase 3 component groundwork is implemented and validated headlessly as of
2026-08-06:

- `src/renderer/vertex_decode.*` decodes the Xenos VFETCH format codes and
  index formats; `src/renderer/resource_cache.*` provides address+size+layout+
  version-keyed resource caching with FIFO eviction. Both are D3D12-free and
  validated by `phase3_validator.exe` against the **real** 551-container shader
  corpus extracted from the game data (`mcla extracted cache/shaders/`):
  **CLEAN** (0 unsupported vertex-fetch codes; all 762 fetches are
  fetch-constant-relative via `const[31]`, as documented). See the research
  addendum entry dated 2026-08-06 for the full real-data run.
- `src/renderer/test_shaders.h` embeds a deterministic VS/PS pair compiled to
  DXIL with the vendored DXC (shader model 6.0).
- `src/d3d12_backend.*` gained the native draw path: a per-frame upload arena,
  empty root signature, test PSO, and `DrawTestMeshedTriangle()` which issues a
  real `DrawIndexedInstanced` with 16-bit indices and a full viewport, then
  presents. `backend_validator.exe` exercises device/root-signature/PSO
  creation against the embedded blobs on hardware/WARP: **CLEAN** (verified on
  an RTX 3070).
- `renderer_mode=native` now calls the meshed draw path at `VdSwap` instead of
  the flat clear, with a 120-frame aggregate log line. This still uses the
  fixed test geometry — not yet guest vertex data.
- The static test index buffer is now created once, cached through
  `ResourceCache` (keyed `Buffer / synthetic addr / 12 bytes /
  DXGI_FORMAT_R16_UINT / version 1`), and reused every frame: unchanged data is
  **not** re-uploaded (Phase 3 gate 2). The vertex data stays in the per-frame
  upload arena. `backend_validator` mirrors the insert/find/version-bump flow
  and the runtime log now reports `cache_hits` / `cache_misses`.
- Backend hardening slice (2026-08-06): `DrawTestMeshedTriangle` body is
  guarded by the backend recursive mutex so it cannot race `Resize()` /
  `Shutdown()`; per-frame uploads are staged **before** any command-list work,
  dropping the frame cleanly on arena exhaustion; `CreateDevice` WARP fallback
  was fixed (the loop always left the adapter non-null, so WARP was dead code);
  `Shutdown()` now unmaps and releases the upload arena, static index buffer,
  root signature, PSO, and clears the resource cache so a
  `Shutdown()` → `Initialize()` recovery path has no dangling `m_uploadMap`.
  The single upload arena is split into `kBufferCount` per-frame regions indexed
  by back-buffer so `BeginFrame()`'s existing fence wait already guarantees the
  region is safe to rewrite. `mcla.exe` and both validators rebuild clean;
  `backend_validator` and `phase3_validator` both report **CLEAN**.
- Synthetic Phase-3 geometry fixture (2026-08-08, user-approved scope
  decision): `backend_validator` step 7 draws the deterministic test quad
  through the exact `DrawTestMeshedTriangle` command sequence into an
  offscreen 1280×720 BGRA8 target and reads back the pixels. Verified on an
  RTX 3070 with the D3D12 debug layer (zero messages): **CLEAN**, exit 0 —
  clear fill, both R16-indexed triangles rasterized, viewport/scissor band
  correct, distinct per-triangle interpolated colors. Explicitly **host-side
  synthetic, non-game data** (satisfies Phase-3 Implement step 5); it does not
  substitute for the "selected capture replays" gate, which stays blocked on a
  real draw capture. No guest memory is touched, so no security-auditor pass
  is needed. See the addendum dated 2026-08-08 for details.
- Capture-time guest-memory evidence slice (2026-08-06): `capture_hooks` now
  dumps the raw guest bytes referenced by each captured draw to
  `<trace>/guestmem/vb_<addr>_<size>.bin` and `<trace>/guestmem/ib_<addr>_<size>.bin`,
  deduplicated by (address,size) through the checked `GuestMemoryView`. This is
  the unblocker for Phase 3 guest-vertex wiring: the live corpus confirms every
  VFETCH is `vf=0`/fetch-constant-relative, so format+stride must be recovered
  from guest fetch-constant descriptors — the dumps give the evidence to prove
  those offsets instead of guessing them. A new standalone
  `capture_dump_validator.exe` cross-checks a `.mclatrace` against its dumps
  (header/packet integrity, per-stream coverage vs `stride*indexCount`, and
  aggregated (format,stride) layout evidence); its built-in self-test and
  directory scan mode both report **CLEAN**, and `mcla.exe` / all three
  validators rebuild clean.

**Standalone `.xtr` trace walker resolved (2026-08-07, gpu-engineer).**
`src/renderer/xtr_dump_validator.cpp` now parses the captured
`build\capture_out\545407F8_stream.xtr` (14,693,579 B) cleanly, **no
desync** — previously it treated `base_ptr`/`count` in the three *Start*
commands as the entire body and skipped only 8 bytes. The correct layout is
12-byte header (`type + base_ptr + count`) **followed by `count` inline dwords
of the command body**, i.e. each start command consumes `12 + count*4` bytes.
With that fix the full 14.7 MB stream parses to exactly EOF with zero errors:

  - primary buffer start/end **45 / 44**, indirect **90 / 89**,
  - secondary buffer start/end **12 / 12**, indirect **27 / 27**,
  - scaler buffer start/end **9 / 9**, indirect **18 / 18**.

The validator also emits a full command-type histogram and frame-delimiter
check; both **CLEAN**. No further XTR work is required before Phase 4.

Phase 4 (native vertex/index wiring) is the next active gate.

### Phase 4 Plan: Guest Vertex/Index Capture & Native Draw

Goal: replace the synthetic `DrawTestMeshedTriangle` with real guest vertex
data captured at the `sub_82420BA8` draw boundary and executed through the
native D3D12 pipeline.

| Step | Description | Verification |
|------|-------------|--------------|
| 1 | Wire `sub_82420BA8` (draw submit) to capture **all** guest VB/IB pointers, strides, formats, counts, and VFETCH descriptors (already dumped by `capture_hooks`). | Replay a single captured draw through `phase4_validator.exe` against the same data used by the legacy path; pixel hash must match. |
| 2 | Extend `ResourceCache` with a per-draw key that includes the resolved vertex format (from VFETCH constants) and index format (from `D3DPT_` codes). | `phase4_validator` cache hit/miss stats; zero re-uploads for repeated draws. |
| 3 | Implement native `DrawIndexedInstanced` path in `src/d3d12_backend.cpp` using the captured descriptors, root signature, and PSO per draw. | `backend_validator` + `phase4_validator` CLEAN on real capture data. |
| 4 | Add a `capture` CVar value to `renderer_mode` that replays captured draws without presenting. | `renderer_mode=capture` runs headless, logs per-draw stats, zero D3D12 debug messages. |
| 5 | Select 3–5 representative captures from the corpus and prove they rasterize identically to the legacy path (pixel diff < 1 pixel). | Comparison report in `build/phase4_validation/`. |

**Phase 4 Gates:**
- **G1:** `phase4_validator.exe` processes the entire capture corpus (headless) with **0 OOB reads, 0 unsupported formats**.
- **G2:** `backend_validator.exe` creates real PSOs and draws the captured geometry on HW/WARP with **0 D3D12 debug messages**.
- **G3:** First live frame with `hasGrcFvf=1` in `renderer_mode=native` renders correctly (pixel-accurate vs legacy).

### Assumption / unresolved
- Import-slot resolution (patching `0x822FFEA0`-style thunks to real
  kernel-stub pointers) is not implemented; boot stops at the first unpatched
  import. Researching the XEX import-table layout is the next step if a deeper
  boot is wanted.
- `--function` mode proves single-function call/return only; multi-call
  function graphs (e.g. a small guest function that calls another) are the
  next coverage step.

- Stub bodies return 0 / do nothing, so any guest logic that depends on a
  kernel import's return value (e.g. `XexCheckExecutablePrivilege` → r3=0)
  takes the "falsy" branch. Fine for reachability evidence; not for
  behavior-correctness claims.

### Session: 2026-08-13 XTL dispatch chain and r13 thread block
- **XTL Import Chain Resolved:** Guest r13 thread block (0x8F200000) and import dispatch chain (sub_82130528 family, slot 7 = offset 28) built in SetupInitialContext (xenon_smoke.cpp), backed by alloc/free stubs (__xtl_alloc, __xtl_free) registered in the function table via InsertFunction. Dispatch resolves through: *(r13) → table base P; *(P+28) → descriptor E; *E → func block F; *(F+8) alloc stub, *(F+12) free stub. Stub Alloc calls SmokeAllocPhysical(size, 16); Free is a no-op.
- **Global Table Pointer Initialized:** Pre-boot initialization at 0x8288E5AC (read by sub_82388598) pointing to scratch table region (0x8F207000). Without this, the read produced 0 and faulted at guest 0x100000000. With it, boot reaches sub_821BD618 (int 3 / breakpoint).
- **Boot Milestone:** xenon_smoke.exe now boots past allocation thunks and table lookups to the initialization trap, with 17 distinct kernel imports logged (previously 15 before the table ptr fix).
- **Status:** native mode render path (hasGrcFvf=1) still renders the fallback meshed triangle; renderer_mode defaults to legacy per phase gates. This session's XTL dispatch and r13 thread block work represents headway toward later phases.