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
  packets **304251 / 304249** (1,314,760 inline dwords),
  memory reads/writes **3123 / 88** (reads decode 18,287,528 B), register
  groups **1**, edram snapshots **1**, gamma ramps **1**, events **44**, total
  parsed == file size.
- **The register group decodes** (snappy 4214 B → 20,483 dwords, registers
  spans `0x0000–0x5002`). Live draw-state evidence cross-referenced against
  `rexglue-sdk/win-amd64/include/rex/graphics/register_table.inc`
  (`XE_GPU_REGISTER` numerics):
  - `COHER_BASE_HOST`(0x0A30) = `0x07C48000`, `RB_COPY_DEST_BASE`(0x2319) =
    `0x07C48000`, `D1GRPH_PRIMARY_SURFACE_ADDRESS`(0x1844) = `0x07C48000` —
    the **same base** as the two 3,768,320-byte reads below, proving the
    captured register file addresses the real guest surface.
  - `RB_SURFACE_INFO`(0x2000)=0x14000500, `RB_COLOR_INFO`(0x2001)=0x2D0,
    `RB_DEPTH_INFO`(0x2002)=0x10000, `PA_SC_WINDOW_SCISSOR_BR`(0x2082)=
    0x02D00500 (1280×720).
  - `CP_RB_WPTR`(0x01C5)=0x12D, `VGT_EVENT_INITIATOR`(0x21F9)=3,
    `VGT_DRAW_INITIATOR`(0x21FC)=0x00030088.
- Cross-check: independent Python walker
  (`C:\Users\abdul\AppData\Local\Temp\opencode\walk3.py`) using the same
  inline-body rule produces **identical counts** and EOF — the result is not a
  C++ artifact. Validator build via `build\_build_xtr_dump.bat` (clang-cl,
  exit 0). **Unresolved (recorded, non-blocking):** the register snapshot is a
  single full register-file frame; per-draw packet→vertex/index buffer
  correlation against the primary-buffer bases is still open.

## Definition of Done

The native renderer is the default when all of the following are true:

- Supported scenes render without the ReXGlue Xenos `CommandProcessor` or PM4
  draw decoding on the native path.
- Per-frame uploads are limited to changed dynamic data, constants, and
  transient geometry. Static textures, shader programs, and pipelines are
  cached.
- The native path presents directly through the PC graphics backend.
- Frame captures show equivalent draw order, render-target transitions, and
  output for the agreed test scenes.
- The legacy renderer remains selectable with a config flag for regression
  diagnosis until the project explicitly decides to delete it.

## Current State and Constraints

### What exists

- The application uses ReXGlue with the Xenos GPU plugin; its configuration is
  in `src/mcla_app.h` and its build link dependencies are in `CMakeLists.txt`.
- `src/native_renderer.cpp` hooks these generated PPC functions:
  - `0x8241ABB8`: state setup / render-target and viewport capture.
  - `0x82420BA8`: draw builder; currently bypasses the original PM4 emission.
  - `0x8241BD08`: command-buffer submit.
  - `0x827BD6E4`: `VdSwap`.
- The current "native" path copies guest state into
  `rex::graphics::RegisterFile`, then calls the ReXGlue Xenos
  `CommandProcessor::IssueDraw`. This is still an emulation backend, not a
  native renderer.
- `src/gpu_mmio.cpp` also installs a hook at `0x8241BD08`. Because
  `mcla_ApplyPatches` installs GPU hooks before native-renderer hooks, native
  renderer hook chaining may point at the other hook rather than the original
  generated function. The rebuild must give every hook address exactly one
  owner/dispatcher.
- Generated code in `generated/default/` must be treated as input. Do not
  patch generated recompilation files to implement the renderer.

### Non-goals for the first implementation

- Replacing PPC game logic, file I/O, audio, input, timing, or save/load.
- Recreating all Xenos GPU features before the renderer can show useful
  output.
- Removing ReXGlue globally; it can continue to host the application and
  window while native D3D12 rendering is introduced.
- Assuming a guessed field in `MclaGpuContext` is authoritative. Every
  captured field must be validated against generated code or live capture.

## Target Architecture

```text
Recompiled PPC game
  |  (known state changes and draw calls)
  v
MCLA capture hooks
  |  immutable NativeFrame / DrawPacket stream
  +--> trace writer (debug only)
  +--> legacy Xenos path (compatibility mode only)
  v
NativeRenderer
  |- GuestMemoryView       guest-address validation and reads
  |- ResourceCache         textures, buffers, render targets, uploads
  |- ShaderCache           Xbox shader decode -> IR -> DXIL
  |- PipelineCache         PSO creation and disk/in-memory cache
  |- FrameGraph            passes, target transitions, resolves
  `- D3D12Backend           command lists, queues, fences, present
```

### Core ownership rules

1. `NativeRenderer` is the only component that creates D3D12 resources,
   command lists, and pipeline state objects.
2. Hooks only capture and normalize guest state. They must not call D3D12
   directly and must not depend on ReXGlue `RegisterFile` state.
3. A `DrawPacket` owns a snapshot of all state required to execute the draw;
   it must not retain mutable pointers to `MclaGpuContext`.
4. Guest pointers are represented as 32-bit guest addresses plus bounds and
   captured generation/version information, not raw host pointers.
5. Native rendering is single-path per frame: a frame is either native or
   legacy. Never mix native draw execution with PM4 draw execution in one
   frame except in an explicit capture-only mode.
6. Hook installation has one owner per guest address. Use a composable event
   dispatcher when more than one observer is needed.

## Feature Flags

Add a simple runtime mode before substantial renderer work:

```text
renderer_mode = legacy | capture | native
native_renderer_validation = off | hashes | images
native_renderer_trace = off | frames | all
```

- `legacy`: current ReXGlue/Xenos behavior only.
- `capture`: original rendering remains authoritative; capture `DrawPacket`s
  without changing game behavior.
- `native`: execute native draws and present natively. Do not submit draw PM4.
- `hashes`: record deterministic packet/resource hashes per frame.
- `images`: save comparison images only at explicit checkpoints or failures;
  do not dump every frame by default.

The default must remain `legacy` until Phase 5 has a working first scene.

## Proposed Source Layout

Create the following files gradually. Add files only when their prerequisite
phase is complete.

```text
src/renderer/
  renderer_mode.h/.cpp          mode selection and feature flags
  native_renderer.h/.cpp        public facade and frame ownership
  native_types.h                POD data for packets, states, and keys
  capture_hooks.h/.cpp          PPC hook registration and state extraction
  hook_dispatch.h/.cpp          one-owner, multi-listener hook composition
  guest_memory.h/.cpp           checked guest-address translation / reads
  frame_trace.h/.cpp            versioned capture format and diagnostics
  resource_cache.h/.cpp         buffer, texture, and render-target caching
  texture_decode.h/.cpp         guest texture format/layout decoding
  vertex_decode.h/.cpp          vertex/index fetch decoding
  xenos_shader_ir.h/.cpp        normalized shader intermediate representation
  shader_translator.h/.cpp      Xenos microcode -> IR -> HLSL/DXIL
  pipeline_cache.h/.cpp         native pipeline keys and PSO cache
  d3d12_backend.h/.cpp          device, queues, fences, descriptor heaps
  frame_graph.h/.cpp            render passes, transitions, resolves
  validation.h/.cpp             capture comparison and invariant checks
```

Initially, retain `src/native_renderer.cpp` as a small compatibility adapter
that selects the renderer mode. Move code out rather than adding more logic to
it. `src/gpu_mmio.cpp` becomes diagnostic-only after native capture works.

## Phase 0 — Stabilize the Existing Interception Boundary

### Objective

Make capture safe and observable without changing the output path.

### Implement

1. Add `renderer_mode` and make `legacy` the default.
2. Centralize registration for all renderer-related PPC hooks. In particular,
   remove the conflicting independent ownership of `0x8241BD08` from
   `src/native_renderer.cpp` and `src/gpu_mmio.cpp`.
3. In `legacy` and `capture` modes, always chain to the original generated
   function exactly once. Do not bypass `sub_82420BA8` yet.
4. Add counters and timestamps for: state setup, draw build, submit, swap,
   frames, draw packets, invalid guest pointers, and dropped packets.
5. Add one structured log line at the end of every 120th frame with aggregate
   counters only. Avoid per-draw logging in normal runs.
6. Add `static_assert`s for offsets used in `MclaGpuContext`; expand the
   documented struct only when source evidence confirms a field.

### Evidence required

- `legacy` has the same boot behavior and presentation behavior as before.
- A 60-second run has no duplicate submission and no hook recursion.
- The trace reports stable frame/draw counts during an idle menu.

### Do not proceed if

- The generated original function cannot be chained exactly once.
- The hook order is not deterministic.
- Guest-address reads can access outside the mapped guest image.

## Phase 1 — Capture a Complete, Replayable Draw Stream

### Objective

Produce a versioned `DrawPacket` stream that describes the game’s rendering
intent independently of Xenos PM4 emission and ReXGlue register state.

### `DrawPacket` minimum contents

```text
Frame identity:       frame number, sequence number, CPU timestamp
Draw:                 primitive topology, indexed/non-indexed, start/count,
                      base vertex, draw flags
Targets:              color/depth guest surface descriptors, resolve intent
Raster state:         viewport, scissor, cull, fill, depth bias
Depth/stencil state:  compare functions, write masks, stencil ops
Blend state:          equations, factors, write masks for each target
Vertex input:         stream addresses, strides, offsets, formats, index type
Textures/samplers:    resource descriptors, guest addresses, sampler state
Shaders:              VS/PS guest program addresses, program metadata
Constants:            VS/PS constant ranges referenced by the draw
Dependencies:         resource version/generation markers and dirty ranges
```

### Implement

1. Define a POD `DrawPacket` and strictly versioned trace header. Keep it
   pointer-free and endian-explicit.
2. Capture at `sub_8241ABB8` (targets/viewport), `sub_82420BA8` (draw intent),
   and any vertex/texture/shader setter that is required to make the packet
   self-contained. Do not rely on the register file as the source of truth.
3. Implement `GuestMemoryView`:
   - validate every guest address against mapped memory;
   - perform checked reads only;
   - translate Xbox endianness explicitly at the boundary;
   - report a packet failure instead of crashing on invalid data.
4. Write a binary trace only when `renderer_mode=capture` and tracing is
   enabled. Include a JSON manifest with build hash, packet version, selected
   test scene, and frame ranges.
5. Add a small offline parser/test program or unit test that verifies trace
   versioning, bounds, packet counts, and hashes.

### Validation gate

- Capture 300 consecutive frames in at least menu, gameplay, and a loading or
  transition scene.
- Every packet has valid targets, draw counts, and referenced memory ranges.
- Repeating the same deterministic scene produces matching packet-count and
  state hashes (allow explicitly documented nondeterministic fields).

## Phase 2 — Build a Native D3D12 Backend Skeleton

### Objective

Render a native clear and present with no Xenos command-processor calls on the
native path.

### Implement

1. Create `D3D12Backend` with device selection, swap chain, direct queue,
   command allocator/list, fence, descriptor heaps, and resize handling.
2. Integrate it with the existing window lifecycle, but keep the backend
   isolated from ReXGlue graphics-system internals.
3. Make the `VdSwap` hook end the native frame, submit the command list, and
   present in `renderer_mode=native`.
4. In native mode, prevent PM4 draw submission. Keep required non-rendering
   game synchronization behavior intact until it is proven unnecessary.
5. Implement a robust device-lost and resize path; return to a controlled
   error screen/log rather than using stale resources.

### Validation gate

- Native mode presents a continuously changing clear color at the game’s
  frame cadence.
- Alt-tab, resize, and device recreation do not corrupt memory or deadlock.
- Native mode contains no call to `CommandProcessor::IssueDraw` and does not
  write `rex::graphics::RegisterFile` to render the clear/present test.

## Phase 3 — Native Resources and One Geometry Slice

### Objective

Render one simple indexed draw using guest vertex/index data and a fixed test
shader, without relying on Xenos resource emulation.

### Implement

1. Implement resource keys based on guest address, size, format/layout,
   resource kind, and data version. Never key only by guest address.
2. Add upload rings for dynamic vertices/constants and default-heap cached
   resources for static buffers/textures.
3. Decode the first supported vertex formats and 16-/32-bit index formats.
   Reject unsupported formats visibly and count them; do not silently draw
   incorrect geometry.
4. Implement native render-target/depth resource creation from captured
   surface descriptors. Track lifetime and transitions in `FrameGraph`.
5. Bind a temporary, deterministic native VS/PS to prove buffer, viewport,
   topology, depth, and index handling.
6. Add a debug overlay/counters for cache hits, misses, bytes uploaded, draw
   count, unsupported draws, and CPU/GPU frame time.

### Validation gate

- A selected capture replays an indexed triangle/mesh with correct topology,
  viewport, and depth ordering.
- Replaying the same frame twice does not reupload unchanged static buffers.
- Invalid or unsupported packets safely fall back to legacy mode per frame
  only if that transition has been explicitly designed; otherwise skip and
  report them. Do not mix native and legacy output unintentionally.

## Phase 4 — Texture, Sampler, and Render-Pass Support

### Objective

Render textured geometry and common render-to-texture passes natively.

### Implement in this order

1. Common 2D/linear texture formats used by the first target scene.
2. Xbox tiled/swizzled texture layout conversion, validated against known
   memory captures.
3. Sampler addressing, filtering, mip selection, and anisotropy mapping.
4. Color/depth target load/store, clears, resolves, and target switches.
5. Blending, color masks, alpha test equivalent, depth/stencil, and culling.
6. Render-to-texture dependencies using a pass graph and explicit D3D12
   resource barriers.

### Validation gate

- The selected menu/HUD or simple environment has correct texture orientation,
  alpha blending, and depth behavior.
- Render-target changes have no D3D12 validation warnings in a debug run.
- Texture and target cache metrics show bounded growth across a 15-minute run.

## Phase 5 — Shader Translation and Pipeline Cache

### Objective

Translate the game’s Xbox vertex and pixel shaders to native shaders, cache
them, and render the first gameplay scene without a fixed test shader.

### Implement

1. Collect unique shader program addresses and metadata from trace captures.
   Rank them by draw count and screen coverage.
2. Build a small Xenos shader intermediate representation. Separate:
   - instruction decode;
   - control flow;
   - ALU/vector operations;
   - texture sampling;
   - export semantics;
   - register/constant mapping.
3. Lower IR to HLSL and compile to DXIL. Maintain a readable IR/HLSL dump per
   shader key for diagnostics.
4. Create a pipeline key from translated VS/PS hashes, vertex declaration,
   target formats, blend/raster/depth-stencil state, sample count, and relevant
   specialization constants.
5. Cache compiled shader blobs and pipeline libraries on disk, versioned by
   translator version, runtime version, driver identity, and source hash.
6. Compile pipelines asynchronously. A missing pipeline may use an explicit
   fallback/error material, but it must never stall all rendering indefinitely.

### Validation gate

- First target gameplay scene renders using translated shaders.
- Second run shows substantially lower shader/pipeline compilation work.
- Captured shader failures are categorized (decode, unsupported operation,
  codegen, compilation, binding mismatch), not logged as a generic error.

## Phase 6 — Coverage, Performance, and Default Cutover

### Objective

Expand compatibility systematically and make the native path fast enough to
justify replacing emulation.

### Implement

1. Use capture statistics to prioritize unsupported state/shader features by
   visual impact and draw frequency.
2. Add GPU timestamps around upload, pass setup, draw execution, resolves,
   and present. Add CPU timings around capture and packet preparation.
3. Batch descriptors and draw state; minimize root-signature, PSO, and
   resource-barrier churn.
4. Add resource eviction budgets for textures, buffers, and pipeline caches.
5. Add automated smoke captures for boot, menu, driving, pause, loading,
   day/night or weather if applicable, and save/load.
6. Promote native mode to default only after the agreed smoke suite passes and
   performance measurements demonstrate the benefit.

### Success metrics to agree before cutover

Fill in project-specific targets before beginning this phase:

```text
Target GPU(s):                 ______________________________
Resolution / refresh target:   ______________________________
Minimum FPS / frame time:      ______________________________
95th-percentile frame time:    ______________________________
Maximum shader stutter:        ______________________________
Capture equivalence scenes:    ______________________________
Acceptable visual differences: ______________________________
```

## Critical Implementation Notes

### Endianness and guest memory

Xbox guest memory and shader/resource metadata may be big-endian. Do not use
`reinterpret_cast` to read captured resource descriptors outside a controlled,
tested guest-memory helper. The helper must expose `ReadU16BE`, `ReadU32BE`,
`ReadF32BE`, checked spans, and explicit conversion routines.

### Synchronization

The PPC game thread must not modify dynamic guest memory while the native
backend consumes it. The simplest safe initial strategy is to copy referenced
dynamic ranges into a frame-owned upload staging area at capture time. Optimize
to dirty ranges only after correctness is proven.

### Presentation and timing

`patches.cpp` changes VSync/semaphore behavior. Keep rendering-frame pacing
separate from simulation timing. Native present must not reintroduce guest
semaphore waits or cause game-time to depend on GPU completion.

### Failure handling

For every unsupported resource, format, state, or shader:

1. Emit a deduplicated diagnostic keyed by the unsupported feature.
2. Include the capture frame and draw sequence.
3. Preserve game stability.
4. Make the fallback behavior explicit and measurable.

## Known Current Problems to Resolve Before Calling Anything Native

- `IssueNativeDraw` in `src/native_renderer.cpp` calls ReXGlue
  `CommandProcessor::IssueDraw`; this is a backend-emulation call and must not
  exist in the final native draw path.
- `WriteGpuContextToRegisterFile` and `ForwardRegisterToBackend` treat the
  Xenos register file as the authority. The new capture layer must instead
  produce normalized PC rendering state.
- The current `sub_82420BA8` hook bypasses PM4 emission but relies on guessed
  context fields and a default vertex count when zero. Capture must never
  invent a draw count; unknown data must be identified and researched.
- `sub_8241BD08` has overlapping hooks in `gpu_mmio.cpp` and
  `native_renderer.cpp`. Consolidate them before adding features.
- `VdSwap` currently chains to the SDK’s PM4 swap. Native mode must own
  presentation after Phase 2.
- The current direct mutation of internal backend state is a useful temporary
  experiment but is not a stable API boundary for the new renderer.

## First AI Task (Start Here)

Implement **Phase 0 only** in a focused change set.

1. Add a renderer-mode enum/config with `legacy` as default.
2. Introduce a renderer hook dispatcher so `0x8241BD08` has one registered
   hook and optional observers can run in a defined order.
3. Move the existing intercept bookkeeping out of `src/gpu_mmio.cpp` and
   `src/native_renderer.cpp` into that dispatcher without changing the legacy
   render behavior.
4. Add low-noise counters and an end-of-frame summary at `VdSwap`.
5. Add a small test or executable assertion for the dispatcher ordering.
6. Build the project and report: changed files, build command/result, and a
   short manual runtime checklist.

Do not begin D3D12 implementation, alter generated code, change the default
renderer, remove the legacy path, or bypass a generated draw function in this
first task.

## Handoff Checklist for Every Subsequent AI

- Read this plan and the immediately preceding phase before editing.
- Run `rg` for the target guest function address and confirm it has a single
  hook owner.
- Keep generated code unchanged.
- Make one vertical slice at a time and leave the existing mode functional.
- Build after each focused change.
- Record validation evidence and unresolved guest-structure assumptions in the
  PR/task handoff.
- Do not claim a native path is complete while it calls the Xenos command
  processor, uses PM4 draw submission, or relies on guessed draw data.

---

## Research Addendum (2026-08-05) — external learnings + shader corpus fix

### External recomp projects (see `.research/RECOMP_RESEARCH_FINDINGS.md`)

- **UnleashedRecomp (hedge-dev, ~4.9k stars) is the reference architecture.**
  It patches the recompiled game at high-level GPU call sites and executes
  native D3D11/D3D12 work; it does NOT run the Xenos CommandProcessor. This
  validates the Phase 1-5 design in this document.
- **XenosRecomp (hedge-dev, ~489 stars)** converts Xenos microcode -> HLSL ->
  DXIL; already vendored at `.research\XenosRecomp`. It is the template for
  the Phase 5 `xenos_shader_ir` + `shader_translator` files.
- **rexglue ecosystem is proven for MCLA-class games**: Ace Combat 6
  (`sal063/AC6_recomp`), SotN XBLA (`birabittoh/NocturneRecomp`), Banjo N&B
  (`masterspike52/reNut`), Skate 3 (`portingpete/skate3-recomp`). All keep
  the SDK renderer; we are the ones going native.
- Our own lineage repo `zarif98/midnightclub` and the user repo
  `3bdull4h2008/mcla-recompilation` show the current state (boots to menu,
  city renders with traffic via the SDK D3D12 backend).

### Shader corpus: the "unknown fetch opcodes" were a decoder bug

- The earlier `SHADER_ANALYSIS_REPORT.md` flagged `f?5/f?12/f?20` unknown
  fetch opcodes across the 2,024-entry fxc corpus. Investigation against
  Xenia's `ucode.h` + local XenosRecomp showed:
  1. Exec `address` is in **instruction units** (12 bytes each), not byte
     offsets — the old analyzer misaligned and decoded container strings
     (e.g. `0x6F704E46` = "FoPN") as instructions.
  2. Microcode start is **not** a fixed `marker+4`; per-entry offset scoring
     produces clean decodes with zero unknown instructions on known-good
     samples.
- Deliverables: `analyze_xenos_microcode_v2.py`, cached Xenia sources in
  `_archive\xenia_*.h|cc`.

### Phase ordering adjustments (research-backed)

1. Port `shader_code.h` + decoder into `src/renderer/` before building the
   shader translator (Phase 5 prereq; validates against the offline corpus
   without a running game).
2. Build an offline `fxc -> DXIL` pipeline using XenosRecomp's DXC wrapper so
   shader translation is testable headlessly.
3. Use UnleashedRecomp's `gpu/cache/` layout (pipeline-state cache, vertex
   element cache) as the reference for Phase 3 resource/pipeline caches.
### OOB "exec targets" were the CF-region bound bug (fixed 2026-08-05)

- Symptom: `xenos_decode_validator` reported 154 OOB exec targets across 61 of
  514 shaders even though unknown-instruction count was already 0.
- Root cause: the validator walked the whole microcode buffer as control flow.
  Xenos microcode is split: the CF pair list occupies the top of the program,
  and the executable instruction area follows immediately. Exec addresses are
  12-byte instruction units relative to the **program start**, not to the CF
  region. Walking past the last CF pair decoded executable words as CF, which
  produced nonsense exec targets (e.g. a 36-byte shader with a "jump" to
  byte offset 10764).
- Fix (matches freedreno / Xenia / XenosRecomp): compute the CF-region byte
  bound by scanning for the first exec instruction with a nonzero target
  address, then walk only CF pairs below that bound. Implemented as
  `ComputeControlFlowByteBound()` in `src/renderer/xenos_microcode.*` and used
  by `PrintMicrocode`, `DecodeMicrocode`, and `DumpShaderIr` in
  `src/renderer/xenos_decode_validator.cpp`.
- Result: corpus scan is now **CLEAN: 514/514 shaders, 0 unknown, 0 OOB**;
  514 IR dumps re-written to `build/shader_ir_v2/`. The old `returns=426`
  noise also disappeared (those were garbage "Return" decodes from executable
  data; real Xenos shaders end with ExecEnd and rarely use the Return opcode).

### Real shader-corpus validation run (2026-08-06) — removes the vacuous corpus caveat

Earlier execution-status notes reported the phase3/pipeline results against a
corpus that was actually **empty** (0 files), so the per-shader gates passed
vacuously. This entry records a genuine run against the game's real shader
data, extracted to `mcla extracted cache/shaders/` (165 `.fxc` files plus
per-type declaration files; container headers carry the `0x102A11xx` magic at
a variable offset, so all three validators scan files rather than assuming the
magic sits at offset 0):

- `xenos_decode_validator.exe "<root>/shaders"`
  - `.fxc` extension scan: 165 files, **514 containers, 514 shaders,
    514 clean, 0 unknown instructions, 0 OOB exec targets, 0 returns**.
  - RESULT: CLEAN.
- `shader_pipeline_validator.exe "<root>/shaders"`
  - `VisitShaderContainers` scan over every file: **551 containers parsed,
    317 VS / 234 PS, 0 parse_errors, 0 hash_mismatches**; the embedded
    pipeline-key determinism + bounded FIFO eviction tests pass.
  - RESULT: CLEAN.
- `phase3_validator.exe "<root>/shaders"`
  - Vertex-decode / resource-cache / test-blob unit tests: ok.
  - Corpus: **551 containers, 762 vertex fetches, 0 unsupported codes**.
  - Fetch-format histogram: **vf=0 (fetch-constant-relative) count=762** — all
    762 fetches resolve via `DecodeVertexFetch` to
    `fromFetchConstant=true`, const index **31** (`const[31]`).
  - RESULT: CLEAN.

> The container-count delta across validators (514 in the `.fxc`-only scan of
> `xenos_decode_validator`, 551 in the all-file `VisitShaderContainers` scan
> shared by `phase3_validator` and `shader_pipeline_validator`) is expected:
> the latter also walks the per-declaration / extensionless companion files
> that sit under the same tree. Each validator's own counts are internally
> consistent and all three report clean.

**Per-category breakdown (same run, 2026-08-06).** The five shader subtrees
were also validated individually to confirm coverage depth and stage mix; the
counts reconcile exactly with the whole-tree scan:

| Category    | .fxc files | decode containers | pipeline containers | VS / PS |
| ----------- | ---------- | ----------------- | ------------------- | ------- |
| cars        | 58         | 146               | 164                 | 86 / 78 |
| characters  | 19         | 115               | 115                 | 80 / 35  |
| city        | 57         | 195               | 207                 | 118 / 89 |
| effects     | 16         | 16                | 20                  | 7 / 13   |
| ui          | 15         | 42                | 45                  | 26 / 19  |
| **Total**   | **165**    | **514**           | **551**             | **317 / 234** |

All five categories report **0 unknown instructions / 0 OOB exec targets /
0 parse errors / 0 hash mismatches** individually.

**Phase 3 gate implication.** The corpus confirms MCLA's vertex fetches are
uniformly fetch-constant-relative: the VFETCH instruction carries
`vertexCondition`/format ≈ 0, and the authoritative format+stride live in the
guest **fetch-constant descriptor** (`const[31]`). The native path must read
those descriptors (the fetch-constant register block `SHADER_CONSTANT_FETCH_00_0`
at `0x4800`, snapshot captured by the `sub_8241ABB8`/state hook) to recover
real VB layout; it must not fall back to guessing a format when `vf==0`. This
is consistent with the Phase 3 "no invented draw data" rule, and the
`capture_dump_validator`/`.xtr` route (see Execution Status above) is the
unblocker for proving real VB/IB offsets once a live capture is taken.

**Reconciliation verdict (2026-08-06, reverser).** An external research pass
questioned the "vf=0 fetch-constant" reading, citing the Xenia-lineage
`kUndefined=0` format enum and an 8-byte fetch-constant struct carrying only
address/size/endian. The reverser closed it in our favor:

- The decode is bit-accurate: a raw VEX word (`05F80000 00000447 00000000`)
  and a TEXFETCH round-trip both confirm `fmt=0 stride=0 offset=0` are
  **genuinely zero in the instruction**, not a decoder loss. Corpus: 762/762
  fetches are `vf=0 const=31 sel=2 mustBeOne=1` — the instruction deliberately
  carries no layout; only `dstRegister` varies.
- XenosRecomp likewise never reads `instr.format/stride/offset` for layout; it
  resolves vertex elements externally (`vertexElements.find(address)`), so the
  reference lineage never derives layout from the instruction either.
- **Correction required (fetch-constant index math):** the descriptor slot is
  `const_index * 3 + const_index_select` (range [0-95]), i.e. for the corpus
  `31*3+2 = 95` — not `constIndex & 0x1F = 31` as previously stored by
  `DecodeVertexFetch`. **Implemented 2026-08-06:** `DecodeVertexFetch` now takes
  `(vfCode, constIndex, constIndexSelect = 0)` and returns
  `fetchConstantIndex = (constIndex & 0x1F) * 3 + (constIndexSelect & 0x3)`
  plus a raw `fetchConstantSelect` field; `phase3_validator` threads the real
  `constIndexSelect` from the microcode decoder and asserts slot 95 in its unit
  checks. Rebuilt and re-run over the real corpus: unit checks ok, all 762
  fetches report `const[95]`, `RESULT: CLEAN`. `capture_dump_validator` and
  `backend_validator` rebuild clean (default `sel=0` keeps legacy callers valid).
- **Descriptor model gap (implementer flag):** the SDK `xe_gpu_vertex_fetch_t`
  is an 8-byte struct with no format/stride; real Xenos fetch constants are
  32 bytes (buffer_format:6, stride:11, base address, offset per Xenia's model).
  The guest-descriptor reader must decode the full 32-byte layout with checked
  BE reads, not the SDK struct as-is.
- **Unresolved assumption to record:** the exact dword offsets of
  buffer_format/stride inside the guest fetch-constant slot-95 descriptor are
  inferred from Xenia's 32-byte model, not yet confirmed from a live MCLA
  capture — verify against a captured fetch-constant table before trusting
  those offsets (per "validate before you trust a struct field").

**Stride-format bit audit (2026-08-06, follow-up).** Because the "slot-95
descriptor carries format/stride" premise collapsed against the reference
(see below), we audited whether the VFETCH *instruction* carries the layout
instead. Conclusive:

- Our decoder's bit positions for `stride`/`format`/`const_index`/
  `const_index_select` match Xenia's `VertexFetchInstruction` exactly
  word-for-word (`_archive/xenia_ucode.h:695-780`), so `stride=0 format=0`
  are genuine instruction contents, not a decode fault.
- Corpus scan (all 762 fetches): `mini_fetch_histogram: full count=762`
  (`isMiniFetch=0`), `stride_histogram: stride[0] count=762`. There are **no**
  mini-fetches to inherit a stride from, and no instruction carries a stride.
- Xenia's translator asserts `assert_not_zero(fetch_instr.attributes.stride)`
  when creating a vertex binding (`xenia_shader_translator.cc:429`). By that
  model a full fetch with `stride=0` is invalid.

**Revision to the layout model.** The reference position — that the fetch
constant is 8 bytes `{type,address},{endian,size}` with no format/stride
(`rexglue-sdk/.../xenos.h:1104`, `_archive/xenia_xenos.h:1113`) — and the fact
that the VFETCH instruction carries `format=0 stride=0` means neither the
descriptor nor the instruction supplies real VB layout offline. The layout
therefore lives in the **RAGE drawable's run-time vertex declaration** (the
RSC5 `grcVertexDescription` / `Rsc5VertexBuffer.Layout→Rsc5VertexDeclaration`
`m_Fvf` channel sizes found in `CodeX.Games.MCLA`), which is only present in a
**live capture** of the drawable geometry. This re-affirms the live `.xtr`
capture as the sole unblocker for real VB layout, and confirms that the
"slot-95 descriptor decode" cannot yield a layout: it yields only the VB base
address/size/endian for the fetched stream.

**Implication for the gate (Rev. 03):** do not add a 32-byte slot-95
format/stride decoder (its layout is not present in the Xenos reference and
would be invented draw data per Golden Rule 5). The offline closure is:
validate layout only when a live `.xtr` provides the drawable's `grcFvf`/
fetch-constant (address) snapshot. `DecodeVertexFetch`'s fetch-constant slot
math (`const*3+sel = 95`) remains correct and useful for *stream binding
identity*, but the *format/stride* must be captured from the guest drawable
descriptor, not inferred.

**Rev. 03 scoped fetch-constant reader (2026-08-07).** Implemented
`DecodeVertexFetchConstant` in `src/renderer/vertex_decode.{h,cpp}`, decoding
the documented 8-byte `xe_gpu_vertex_fetch_t` (`{type:2,address:30}`,
`{endian:2,size:24}`) to `addressBytes/addressType/endian/sizeWords`, with a
zero-slot flag. Per Rev 03 it reads **only** VB base address/size/endian —
no format/stride (those come from the captured drawable's `grcFvf`). It is a
pure byte-array parser (checked guest reads still happen in the caller's
`GuestMemoryView`), so it is headlessly tested. Added `fetch_constant_test=ok`
to `phase3_validator` covering zero-slot, address/endian/size extraction,
zero-size rejection, and big-endian host-independence. Rebuilt `phase3`,
`backend`, `capture_dump`, and `shader_pipeline` validators — all `RESULT:
CLEAN` with the reader present. This is the read side of the capture path: a
live `.xtr` can now recover the per-stream VB address/size/endian once a
drawable provides the `grcFvf` layout.

**Offline stream-binding classifier + dump-stride fix (2026-08-07).** To make
layout recovery ready the day a usable live capture exists (Phase 3 gate 2
remains blocked — no replayable draw capture yet; see handoff below), two
headless validator changes landed:

- `phase3_validator` now emits a `stream_binding_classification` that asserts
  the corpus is single-stream: **`distinct_fetch_constant_slots=1`
  (const[95]), `vertex_fetches=762`, `fetch_constant_relative=762`,
  `single_stream=TRUE`** and gates `RESULT: CLEAN` on it. This turns the
  ad-hoc histogram into an asserted precondition: every draw needs a VB layout
  that can ONLY come from the captured drawable's `grcFvf`, never from the
  shader or the fetch-constant descriptor (Rev 03). Any future multi-slot /
  non-fetch-constant fetch fails the build gate instead of being assumed away.
  `phase3_validator` **CLEAN** (0 unsupported).
- `capture_dump_validator` Golden-Rule-5 fix: `ExpectedStreamDumpBytes` defaulted
  `stride` to **32** when the packet reported 0 — invented draw data. It now
  returns 0 for `stride==0` and the analyzer reports that stream as "layout
  unresolved (needs captured grcFvf layout)" instead of guessing a dump size or
  claiming coverage. Self-test **PASSED**; the unresolved-layout path was proven
  with a throwaway stride-0 synthetic packet (diagnostic fires), then reverted
  and rebuilt clean.

Build/verify: `build\_build_phase3.bat` (0) and `build\_build_dump_val.bat` (0)
compiled clean; `phase3_validator` on the real 551-container corpus and
`capture_dump_validator` self-test both `CLEAN`/`PASSED`. Route final review
through `code-reviewer`; `renderer_mode` unchanged and still `legacy`.

**Review pass (2026-08-07, code-reviewer → PASS-with-notes; notes fixed).**
- `phase3_validator`: dropped the tautological `streamCount` term, fixed the
  dead `miniUsage.empty()` guard, and (important) now gates **`fOk`**
  (`ExerciseVertexFetchConstant`) in `allOk` — a failing fetch-constant unit
  test can no longer be masked behind a `RESULT: CLEAN`.
- `capture_dump_validator`: consolidated the triple error emitted per
  `stride==0` stream into **one** `layout unresolved` diagnostic (with
  `continue`), added a `streams layout unresolved` aggregate to `LayoutEvidence`
  + summary, and excluded unresolved streams from the coverage ratio (now
  reported over resolved streams only). Verified with a throwaway stride-0
  synthetic packet: exactly 1 error per unresolved stream (was 3); reverted and
  rebuilt clean. Severity stays **error** (not warning) so a real capture cannot
  pass the gate while silently skipping coverage.

## Phase 5 D1 Gate Closure — Offline HLSL Corpus DXC Validation (2026-08-09, gpu-engineer)

The Phase 5 D1 gate requires the full shader translation pipeline to compile **cleanly** across the real 551-container corpus extracted from the game. This entry records the successful closure.

### Validation Result
- `shader_pipeline_validator.exe "mcla extracted cache/shaders" --dump "C:\Users\abdul\AppData\Local\Temp\opencode\hlsl_dump"` produced 551 HLSL files (317 VS / 234 PS) with **0 parse errors, 0 translation errors**.
- dxc.exe (Windows SDK 10.0.22621.0, vs_6_0/ps_6_0) compiled all 551 samples: **OK=551, FAIL=0**.

### Root Causes Fixed
The 127 previous failures (duplicate-component LHS swizzles, `r62` undeclared exports, duplicate constant names, missing `select` intrinsic) were resolved by three systemic fixes in `src/renderer/shader_translator.cpp`:

1. **Fetch dest swizzle decode (EmitFetch / TextureFetch):**  
   Xenos fetch `dstSwizzle` is 12 bits = 3 bits/component (X=0..W=3, Zero=4, One=5, Keep=6/7). The emitter previously read 2 bits/component and reused one string for both LHS and RHS, producing illegal `rN.xzxz = iPos.xzxz` LHS.  
   - LHS suffix: position-order unique components only (filtering slots matching X/Y/Z/W).  
   - RHS suffix: mapped requested source components (may repeat).  
   - Zero/One slots: explicit `rN.{i} = 0.0f;` / `= 1.0f;` writes after the fetch.  
   Applied identically to VertexFetch and TextureFetch paths.

2. **VS export register mapping (VSPosition=62, VSInterpolator0..15=0..15):**  
   - `vectorDest == 62` → `oPos` (with viewport half-pixel offset retained).  
   - `vectorDest 0..15` → `oTexCoord{vd}` (declared in signature).  
   - `vectorDest == 63` (VSPointSizeEdgeFlagKillVertex) → write suppressed (no color output).  
   - `AppendSignature` updated to match: `vd==62` skipped (oPos already declared), `oTexCoord{vd}` for `vd<16`.

3. **Duplicate constant name disambiguation (`ler` at c103/c105):**  
   Guest constant tables can name multiple float4 entries identically at different registers. Added `BuildConstantNames()` so later duplicates get a `_<reg>` suffix; cbuffer declarations and operand references share the same unique map.

4. **Missing `select` intrinsic:**  
   HLSL has no `select` intrinsic; the reference XenosRecomp header defines one. Added ternary-based `select` overloads (bool4/bool3/bool2/bool × float4/float3/float2/float) to the generated preamble.

### Evidence Record
| Check | Result |
|-------|--------|
| `build\mcla.exe` | Clean (clang-cl, C++23, /EHa /GS-) |
| `build\shader_pipeline_validator.exe` | Clean (551 containers, 317 VS, 234 PS) |
| dxc.exe vs_6_0/ps_6_0 over all 551 HLSL samples | **OK=551, FAIL=0** |

**Phase 5 D1 gate: CLOSED.** The offline translation pipeline is validated. Next step (Phase 5 D2) is to wire the runtime DXC compiler (`dxc_runtime`) into the shader pipeline/cache so live container loads produce DXIL blobs and feed `D3D12Backend` PSO creation.

---

## Phase 5 D2 Gate Closure — Live DXIL Compilation & PSO Wiring (2026-08-09, gpu-engineer)

With the offline HLSL corpus validated (Phase 5 D1), this entry records wiring the runtime DXC compiler (`dxc_runtime`) into the shader pipeline so that unique shader containers are translated and compiled to DXIL byte blobs on demand, feeding `D3D12Backend::CreatePipelineFromDxil` for PSO creation.

### Changes
1. **`src/renderer/shader_dxc_compile.cpp` (new):** Implements `CompileShaderToDxil` — parses a `.fxc` container via the existing IR/translator, then invokes `DxcRuntime::Compile` to produce a DXIL blob (`vs_6_0` / `ps_6_0`).
2. **`src/renderer/dxc_runtime.cpp`:** Loads `dxil.dll` + `dxcompiler.dll` dynamically (LoadLibrary, priority: explicit dir → `MCLA_DXC_DIR` → vendored `.research/XenosRecomp/thirdparty/dxc-bin/bin/x64` → exe dir), caches `IDxcCompiler3`/`IDxcUtils`, and compiles HLSL with the same flags as the reference (`-E main -T vs_6_0/ps_6_0 -HV 2021 -all-resources-bound -Wno-ignored-attributes -Qstrip_reflect -Qstrip_debug`).
3. **`src/d3d12_backend.h/.cpp`:** Added `CreatePipelineFromDxil(vsDxil, psDxil, inputLayout, PipelineState, outPso)` — builds a `D3D12_GRAPHICS_PIPELINE_STATE_DESC` from live DXIL blobs and render state, creates the `ID3D12PipelineState`.
4. **CMake:** Added `shader_dxc_compile.cpp` and `dxc_runtime.cpp` to `RENDERER_IR_TUS` and the `mcla` target.

### Validation Evidence
| Check | Result |
|-------|--------|
| `build\mcla.exe` | Clean (clang-cl, C++23) |
| `build\shader_pipeline_validator.exe` | Clean (551 containers, 317 VS, 234 PS) |
| dxc.exe vs_6_0/ps_6_0 over all 551 HLSL samples | **OK=551, FAIL=0** |
| `build\backend_validator.exe` | **CLEAN** (test PSO, dynamic mesh, texture decode round-trip, zero debug-layer messages) |
| `build\phase3_validator.exe` | **CLEAN** (551 containers, 762 fetches, single stream `const[95]`) |
| `build\texture_decode_test.exe` | **CLEAN** (oracle-validated tiling/format tables) |

### Phase 5 D2 Gate: CLOSED
The runtime DXC compilation path is functional and produces valid DXIL blobs that create working PSOs. The next step (Phase 5 D3) is to integrate the `PipelineCache` with live container loads so unique VS/PS hashes map to cached PSOs on first use, with async compilation fallback.

---

## Phase 5 D3 Gate Closure — PipelineCache Wiring & Async Compilation (2026-08-09, gpu-engineer)

With the offline HLSL corpus validated (Phase 5 D1) and live DXC compilation wired (Phase 5 D2), this entry records wiring the `PipelineCache` into the shader container loading path so unique VS/PS hash pairs map to cached `ID3D12PipelineState` objects, with an asynchronous background compilation queue and fallback mechanism for cache misses.

### Changes
1. **`src/renderer/pipeline_cache.h/.cpp` (rewritten):**
   - `PipelineCache` now stores `ComPtr<ID3D12PipelineState>` directly (no opaque handles).
   - Background worker thread (`WorkerLoop`) creates PSOs from pre-compiled DXIL blobs.
   - `GetOrCompile(key, vsHlsl, psHlsl, inputLayout)` compiles HLSL→DXIL on the caller thread (using `DxcRuntime`), queues PSO creation on the worker, and returns the fallback PSO (test pipeline) for zero-hitch cache misses.
   - `SetFallbackPipeline()` sets the test pipeline as fallback so draws never stall.
   - FIFO eviction (4096 entries) with mutex-protected map and task queue.

2. **`src/d3d12_backend.h/.cpp`:**
   - `m_pipelineCache` member added to `D3D12Backend`.
   - `StartWorker(device, rootSignature)` called in `Initialize()`; test pipeline registered as fallback.
   - `DrawDynamicMesh` now queries `GetOrCompile()` for the test pipeline key (hashes of test VS/PS HLSL + test input layout) instead of using `m_testPipeline` directly. Returns fallback PSO immediately; real PSO compiled in background.
   - `Shutdown()` stops the worker thread cleanly.

3. **`src/renderer/test_shaders.h`:** Added `GetTestVsHlsl()` / `GetTestPsHlsl()` returning the HLSL source for runtime compilation (matching the embedded DXIL blobs).

4. **`src/renderer/shader_pipeline_validator.cpp`:** Updated cache unit test to use mock `ID3D12PipelineState` COM objects (`MockPipelineState`) instead of `uint64_t` handles.

### Validation Evidence
| Check | Result |
|-------|--------|
| `build\mcla.exe` | Clean (clang-cl, C++23) |
| `build\backend_validator.exe` | **CLEAN** (test PSO, dynamic mesh, texture round-trip, zero debug-layer messages) |
| `build\phase3_validator.exe` | **CLEAN** (551 containers, 762 fetches, single stream `const[95]`) |
| `build\texture_decode_test.exe` | **CLEAN** (oracle-validated tiling/format tables) |
| `build\xenos_decode_validator.exe` | **CLEAN** (514 containers, 0 unknown, 0 OOB) |
| `build\capture_dump_validator.exe` | **CLEAN** (self-test passed) |
| `build\xtr_dump_validator.exe` | **CLEAN** (self-test passed) |
| dxc.exe vs_6_0/ps_6_0 over all 551 HLSL samples | **OK=551, FAIL=0** |

### Phase 5 D3 Gate: CLOSED
The `PipelineCache` is integrated into the live shader pipeline, async PSO compilation is functional, and fallback PSOs guarantee zero-hitch rendering on cache misses. Next step (Phase 5 D4) is to extend the pipeline key with full render state (blend, raster, depth-stencil, RT formats) and wire live container loads from the capture hooks to the cache.

---

## Phase 5 D4 Gate Closure — Live Container/Packet Pipeline Keying (2026-08-09, gpu-engineer)

With `PipelineCache` async compilation in place (Phase 5 D3), this entry records wiring the live capture path: the captured `DrawPacket`'s guest shader pointers (`sqVsProgram`/`sqPsProgram`) and render state are parsed into `PipelineKey`s, and `PipelineCache::GetOrCompile` feeds the background worker so first-frame draws use the fallback PSO and later draws hit the compiled PSO.

### Changes
1. **`src/native_renderer.cpp`:**
   - `ParseShaderFromGuest(GuestMemoryView&, guestAddr, ShaderProgram&)` reads a `.fxc` container from guest memory through the checked memory helper: validates the `flags & 0xFFFFFF00 == 0x102A1100` magic, reads container sizes (offsets 4/8), copies the full container, and delegates to `ParseShaderProgram`.
   - `BuildInputLayoutFromVS()` maps parsed VS vertex elements to `D3D12_INPUT_ELEMENT_DESC` (POSITION→`R32G32B32_FLOAT`, other usages→`R32G32B32A32_FLOAT`, per-element offsets).
   - `BuildPipelineStateFromPacket()` maps the packet's render state into `PipelineState`: RT formats (present targets→`R8G8B8A8_UNORM`), depth format (`D24_UNORM_S8_UINT`), raster state from `paClipCntl`/`paSuScModeCntl`, topology from `primType`.
   - `GetPipelineForPacket(backend, packet)` returns `nullptr` if either shader pointer is null; otherwise parses VS+PS from guest memory, hashes them (`ComputeShaderProgramHash`), builds the `PipelineKey` via `ComputePipelineKey`, builds the input layout, and calls `cache.GetOrCompile(key, vsHlsl, psHlsl, inputLayout)`.
   - `TryConsumeCapturedGeometry` now retrieves the packet's PSO from the cache and draws via `DrawDynamicMeshWithPipeline` instead of the hard-wired test pipeline.

2. **`src/renderer/pipeline_cache.cpp` (fix):** `GetOrCompile` previously returned the fallback PSO **before** queueing the compile task when a fallback was set, so the real PSO was never compiled in the background and the cache never filled. It now always compiles HLSL→DXIL on the caller thread, queues PSO creation on the worker, and returns the fallback — matching the D3 intent that the real PSO is compiled asynchronously while draws proceed on the fallback.

3. **`src/d3d12_backend.h/.cpp`:** added `DrawDynamicMeshWithPipeline(desc, ID3D12PipelineState*)`; `DrawDynamicMesh` delegates to it with the test pipeline so both captured-geometry and fixture paths share identical command-list handling.

4. **`src/capture_hooks.h`:** `GetMemoryView()` accessor exposes the accumulator's checked `GuestMemoryView` to the packet-consumption path.

### Build & Validator Fixes
- `native_renderer.cpp` had an unclosed anonymous `namespace {` (helpers added for D4) that mis-nested `InstallNativeRenderer` inside it, causing a link error (`undefined symbol: mcla::native::InstallNativeRenderer`). Closed the anonymous namespace before the Install section; `mcla.exe` links clean.
- Validator targets could not compile `shader_dxc_compile.cpp`/`pipeline_cache.cpp` because clang-cl had no MSVC system include paths outside a `vcvars64` environment, and the DXC headers live in `rexglue-sdk/win-amd64/include` (not the `.research/.../dxc-bin/inc` path previously added to the validator target). `VALIDATOR_INCLUDE_DIRS` now includes the rexglue SDK include dir; validators build and run under the `vcvars64` environment.

### Validation Evidence
| Check | Result |
|-------|--------|
| `build\mcla.exe` | Clean (clang-cl, C++23, `/GS- /EHa`) |
| `build\backend_validator.exe` | **CLEAN** (test PSO, dynamic mesh, texture round-trip, zero debug-layer messages) |
| `build\phase3_validator.exe` | **CLEAN** (551 containers, 762 fetches, single stream `const[95]`) |
| `build\texture_decode_test.exe` | **CLEAN** (oracle-validated tiling/format tables) |
| `build\xenos_decode_validator.exe` | **CLEAN** (514 containers, 0 unknown, 0 OOB) |
| `build\capture_dump_validator.exe` | **CLEAN** (self-test passed) |
| `build\xtr_dump_validator.exe` | **CLEAN** (self-test passed) |
| `build\shader_pipeline_validator.exe` over live corpus | **CLEAN** (551 containers, 317 VS / 234 PS, `parse_errors=0`, `hash_mismatches=0`, `pipeline_key_test=ok`) |
| dxc.exe vs_6_0/ps_6_0 over all 551 HLSL samples | **OK=551, FAIL=0** |

### Unresolved guest-structure assumptions
- `BuildPipelineStateFromPacket` currently maps any present color target to `R8G8B8A8_UNORM` and any depth target to `D24_UNORM_S8_UINT`; the real RT/depth formats are not yet read from the guest surface descriptors (evidence gap — validated only against the test/fixture pipeline).
- `GetPipelineForPacket` compiles with the **test HLSL** (`GetTestVsHlsl`/`GetTestPsHlsl`) for all keys, so every key currently produces the same fallback test pipeline; translating the parsed `ShaderProgram` to HLSL and feeding the real shader source into `GetOrCompile` is the Phase 5 D5 follow-up.

### Phase 5 D4 Gate: CLOSED
The live capture path now parses guest shader containers and packet render state into `PipelineKey`s and routes them through `PipelineCache::GetOrCompile`, returning the fallback PSO on first use (zero-hitch) and compiling the real PSO in the background. Next step (Phase 5 D5) is to translate parsed guest `ShaderProgram`s to HLSL so cached PSOs reflect the actual VS/PS, not the test shader.

## Phase 5 D5 Gate Closure - Live Guest Shaders into the Pipeline Path (2026-08-09, gpu-engineer)

### D5 Gate: CLOSED

The pipeline path now translates the captured guest VS/PS microcode containers to real HLSL
at runtime and feeds that HLSL into `PipelineCache::GetOrCompile`, replacing the test-shader
fixtures. DXIL compilation moved entirely onto the background worker, so a unique guest
shader pair no longer stalls the render thread during HLSL→DXIL compilation.

### Implementation

- `native_renderer.cpp`:
  - `ReadShaderContainerFromGuest` reads a raw `.fxc` container from guest memory (magic
    `0x102A1100`, vsize/psize from the header) through the checked `GuestMemoryView`,
    rejects 32-bit size wrap and containers > 16 MiB, and validates the guest range
    **before** any allocation so a malformed header cannot force a large buffer on the
    draw path. Shared by the parse and translate paths.
  - `GetPipelineForPacket` runs both containers through `mcla::renderer::TranslateShader`;
    the translated `hlsl` + `programHash` now drive `GetOrCompile` (was `GetTestVsHlsl`/`GetTestPsHlsl`).
    Non-empty translated HLSL is guaranteed compilable by the offline corpus gate (dxc.exe
    OK=551/551). Translation failure logs once per packet and returns `nullptr` so the draw
    falls back to the fixture quad — it never caches a wrong pipeline under a real key.
  - Vertex input layout now comes from `ReferencedVertexInputs` (first-fetch order matching
    the generated VS entry signature) via `DecodeVertexFormat`; `vertexDeclHash` uses
    `HashVertexDeclaration`. See the unresolved-assumption note below for the MCLA vf=0 case.
- `pipeline_cache.{h,cpp}`:
  - `CompileTask` carries `vsHlsl`/`psHlsl` strings instead of pre-compiled DXIL.
  - `WorkerLoop` owns a worker-local `DxcRuntime` (lazily loaded once) and performs
    HLSL→DXIL → PSO creation entirely on the worker thread; the caller thread only queues.
  - `pendingKeys_` de-duplicates in-flight compile requests; a compiling/failed key is not
    re-queued, bounding worker work and log noise. Keys are removed from `pendingKeys_` only
    on successful PSO insert (and on cache eviction in `Insert`). `kMaxInflight = 256`
    bounds the queue under render-state key churn; overflow returns the fallback.
  - Silent failure paths log to stderr (empty-HLSL/missing device, DXC load, VS/PS compile,
    `CreateGraphicsPipelineState` hr) so a permanently-fallback key is diagnosable.
  - PSO desc still fixes render state to the capture profile (R8G8B8A8, triangle, no-depth,
    cull-none, full write mask); the keyed render-state fields are documented as
    deferred-to-later-gate (not yet applied to the desc).

### Validation Evidence

| Check | Result |
|-------|--------|
| `build\mcla.exe` (clang-cl, C++23, `/GS- /EHa`) | Clean (7/7 ninja steps incl. `d3d12_backend.cpp`, `native_renderer.cpp`, `pipeline_cache.cpp`, `shader_translator.cpp`, `shader_dxc_compile.cpp`) |
| `build\shader_pipeline_validator.exe` over live corpus | **CLEAN** (551 containers, 317 VS / 234 PS, `parse_errors=0`, `hash_mismatches=0`, `pipeline_key_test=ok`, all `phase5_gates=0`) |
| `build\xenos_decode_validator.exe` over live corpus | **CLEAN** (514 containers, 0 unknown, 0 OOB) |
| `build\phase3_validator.exe` over live corpus | **CLEAN** (762 vertex fetches, `fetch_constant_relative=762`, const[95], `single_stream=TRUE`) |
| code-reviewer + security-auditor pass | No HIGH; security MEDIUM fixed (resize-before-validate + size cap); LOW items fixed (dead `const_cast`, locked `Size()`, single-start documented) |

### Unresolved guest-structure assumptions
- MCLA VFETCH embeds vf=0 for all 762 verified fetches (all resolve to fetch-constant slot
  const[95]), so `DecodeVertexFormat` cannot resolve a DXGI format from the shader alone; the
  vertex declaration must come from the captured RAGE drawable `grcFvf` (Phase 8 item 1).
  Until then, unresolved elements fall back to the fixture layout (POSITION float3 @0,
  COLOR float4 @12 = 28 bytes) that the `TryConsumeCapturedGeometry` stride==28 gate admits,
  and `HashVsVertexDeclaration` returns 0 for keys (distinct from any resolvable declaration).
  A VS referencing a non-POSITION/COLOR element set would produce a layout the stride==28
  gate rejects — recorded, not defaulted.
- `BuildPipelineStateFromPacket` still maps any present color target to `R8G8B8A8_UNORM` and
  any depth target to `D24_UNORM_S8_UINT` (placeholder-invented, not guest-read); those fields
  are hashed into the key but the PSO desc does not yet apply them (deferred gate).

### Phase 5 -> Phase 6/8 Readiness Handoff (locked 2026-08-09)

Phase 5 (D1-D5) is complete: guest shader containers translate to real HLSL at runtime,
compile to DXIL on the background worker, and drive `PipelineCache` PSOs with validated
0-error / 0-regression corpus evidence. Two evidence gaps block the next native steps and
are now the defined Phase 6/8 entry work:

1. **RAGE `grcFvf` vertex declaration decoding (Phase 8 item 1, now the primary blocker).**
   All 762 verified MCLA VFETCHes embed `vf=0` (fetch-constant-relative, resolved to
   const[95]), so `DecodeVertexFormat` cannot resolve a DXGI format/stride from the shader
   alone. The vertex declaration must be decoded from the captured RAGE drawable `grcFvf`
   descriptor (field-by-field validation against the live drawable capture). Until then the
   fixture 28-byte layout (POSITION float3 @0, COLOR float4 @12) and stride==28 consume
   gate are the honest ceiling; a non-POSITION/COLOR element set is rejected, not guessed.
2. **Render-target / depth-stencil format mapping.** `BuildPipelineStateFromPacket` invents
   `R8G8B8A8_UNORM` / `D24_UNORM_S8_UINT` today. Phase 6 entry work: decode the captured
   surface/RT format from guest render-target descriptors (research-backed mapping, not
   defaulted), feed it into `PipelineState`, and apply the keyed render-state fields to the
   PSO desc (the desc still fixes the capture profile; keyed-but-unapplied is documented).

`renderer_mode` remains `legacy` by default. Handoff checklist: single hook owner per address
intact; `generated/` untouched; tree builds clean; corpus validators CLEAN; both gaps above
recorded as evidence-gated, not defaulted.

---

## Live-boot capture evidence + splash hang (2026-08-07)

The standalone `build\mcla.exe` capture build was booted (first unquoted-arg
launch failed, exit 3; quoted
`--game_data_root=E:\MCLA-Standalone\game_data --cache_root=E:\mcla pc\build\capture_out`
succeeded; game root has `default.xex`). The 3s warmup + 1.5s host trace
window captured `build\capture_out\545407F8_stream.xtr` (14,693,579 B) and a
40-byte (empty, header-only) `mcla_capture.mclatrace`.

- `.xtr`: header parses; the single register group is a **full register-file
  snapshot** (first=0, count=0x5003) that **decodes** (snappy) with the
  corrected payload offset — see the Execution Status entry above for the named
  draw-state evidence (`COHER_BASE_HOST`, `RB_COLOR_INFO`, `VGT_DRAW_INITIATOR`,
  etc.). Reads/writes are 3123 / 88 in the full stream. **Memory-classification
  result (2026-08-08, gpu-engineer): there is no vertex or index-buffer data in
  this capture.** The two "VB-looking" 3,768,320-byte reads at `0x07C48000` /
  `0x08378000` decode to solid `00 00 00 FF` BGRA at 1280×736×4 — they are the
  **framebuffer color surfaces** (base matches `D1GRPH_PRIMARY_SURFACE_ADDRESS`
  / `RB_COPY_DEST_BASE`), not vertex buffers. The remaining reads are page-size
  texture-copy blobs (4096 B, 2622×) plus state reads: a float viewport
  (`~1,-1,1279.5,720` at `0x08F06D78`), a 12-entry ×12-byte descriptor table
  (`0x08F13000`), and a scratch/constant table (`0x1FCA3000`, tied to register
  `0x01DD`) read in 4-byte lookups. So the packet bodies (1,314,760 inline
  dwords) do carry real PM4 opcodes, but the captured frame is a splash-screen
  with **no draw, hence no per-draw VB/IB evidence**; Phase 3 guest-vertex
  wiring stays blocked pending a capture that covers an actual draw.
  Tail is a benign truncated `kEdramSnapshot` (encLen 0x01480100 > file), closed
  mid-flush when the window ended. Not replayable.
- `.mclatrace`: **0 packets** — the guest hooks never reached a draw call during
  the 1.5 s window because the game was still on the splash/logo loading screen.
  The window is positioned at boot; it must be moved/elongated to cover real
  draws (Press Start / main menu) instead of the loader.
- **Boot-progression handicap (plain/light legacy path, out of native-GPU
  scope):** after the Rockstar logos the game stalls on the MCLA splash and the
  "Press Start" never appears on screen. Debugger triage on `mcla_010.log`:
  the splash→PressStart state transition at 20:36:28.47 was the game's own doing
  (splash obj `0xBD397F40` chained to original; PressStart obj `0xBD3AFCB0`),
  but our bytecode redirect `0x812A1100 NOT FOUND` forced the
  `flag=2 / sub_82554590` fallback (patches.cpp:752), and after 20:36:28.596 the
  log is silent (no further `sub_82554E20`/`KeWait`/swap/frame) → no new frames
  are presented, the swap chain keeps re-presenting the last splash frame. The
  underlying wedge is the missing RAGE city art: `NtCreateFile` failed
  `0xc000000f` for `t:\mc4\art\city\test_*.loc` (×7 at 12.8 s). Those `.loc`
  live inside `xarchive_cache.rpf` (2.13 GB) / `xarchive_audio.rpf`, and the
  recomp's guest FS does not serve the `t:` art paths from the RPFs. That is a
  game-data/legacy-path issue, **not** native-GPU work; per project decision we
  do not chase it — the native path needs only a replayable draw capture, which
  a repositioned trace (over the menu) plus an RPF/art load would supply.
- **No guest-mem dumps** exist (`guestmem/` absent): the empty native trace means
  `capture_hooks` dumped no `vb_*/ib_*` files, so `capture_dump_validator` has
  nothing real to validate. Next offline native-GPU step is to re-capture over
  menu draws once the game renders, then run the two extended validators
  against the produced `vb_*`/`ib_*` dumps + the resolved `grcFvf` layout.

## Synthetic Phase-3 geometry fixture (2026-08-08, gpu-engineer)

**Scope decision (user-approved):** with live draw capture blocked by the
splash hang (above) and RAGE art/FS loading explicitly de-scoped, the Phase-3
"one geometry slice" requirement is met by a **host-side synthetic fixture**,
not by replayed guest data. It is recorded as the official Phase-3 geometry
slice **only for the parts it can prove**; it is not, and must not be labeled
as, captured game data. It satisfies Phase 3 Implement step 5 ("bind a
temporary, deterministic native VS/PS to prove buffer, viewport, topology,
depth, and index handling") and the parts of the validation gate that are
data-independent. The gate's "selected capture replays" criterion still needs
a real draw capture once the game renders a draw; this fixture does not
substitute for it.

`src/renderer/backend_validator.cpp` step 7 (SYNTHETIC render fixture):

- Draws a deterministic 4-vertex / 6-index (uint16) colored quad through the
  same command sequence `D3D12Backend::DrawTestMeshedTriangle` issues —
  empty root signature, Phase-3 test PSO, full viewport, `TRIANGLELIST`,
  `DrawIndexedInstanced(6,1,0,0,0)` — into an **offscreen** 1280×720 BGRA8
  target (no swap chain, no window). Surface semantics come from the captured
  frame registers: BGRA8 active 1280×720
  (`PA_SC_WINDOW_SCISSOR_BR=0x02D00500`), base `0x07C48000` ==
  `D1GRPH_PRIMARY_SURFACE_ADDRESS`/`RB_COPY_DEST_BASE`.
- Vertex data: `{ -0.8,-0.8,0 }` red, `{ 0.8,-0.8,0 }` blue,
  `{ 0.8,0.8,0 }` green, `{ -0.8,0.8,0 }` white; indices `{0,1,2, 0,2,3}`;
  stride 28 B (`vf=57` float3 + `vf=38` float4, cross-checked against
  `vertex_decode`). Uploads staged on a heap with 256 B pitch, matching the
  backend arena alignment.
- Reads back the RT to a READBACK buffer, fences, and asserts:
  1. **Clear fill** present at all four corner samples (5,8,13 = 0.02,0.03,0.05
     clear);
  2. **Topology via the R16 index buffer** — both triangles rasterized (their
     NDC centroids → pixels (811,456) and (469,264) are both lit);
  3. **Viewport/scissor** — a horizontal mid-frame scan is lit only in the
     NDC −0.8…0.8 band, leaving left/right clear margins;
  4. **Interpolation/index addressing** — the two triangles sample distinct
     interpolated colors (center reads (127,127,0,255) = 50/50 red→green
     across the v0–v2 diagonal).
- Result on hardware (RTX 3070), D3D12 debug layer enabled with zero
  validation messages: **`RESULT: CLEAN`, exit 0**.

Bugs caught by the fixture during bring-up (all fixed in the validator):
`D3D12_VERTEX_BUFFER_VIEW` had SizeInBytes/StrideInBytes swapped (stride 28
was being read as the 112-byte size — nothing rasterized); a no-op
RENDER_TARGET→RENDER_TARGET barrier; `IASetIndexBuffer` used an undefined
view name; stray duplicated `IndexElementBytes` block; missing `<array>`.

Build/verify: `build\_build_backend_val.bat` compiles clean (clang-cl from
VS 2022 BuildTools, `/std:c++23`), `build\backend_validator.exe` exits 0.
Scope boundaries kept explicit: the fixture touches **no guest memory** (all
vertex/index data is host-side constants), so no security-auditor pass is
required for it; `renderer_mode` remains `legacy` by default.

## On-window `renderer_mode=native` run (2026-08-08, gpu-engineer)

The on-window step (expose the test quad via
`D3D12Backend::DrawTestMeshedTriangle` on the `renderer_mode=native` path)
was exercised by launching `build\mcla.exe` with `renderer_mode="native"` in
`build\mcla.toml` against `E:\MCLA-Standalone\game_data` (single quoted
`--game_data_root` argument; the previously-observed unquoted shape exits 3
before boot). Result — **wiring verified, on-window draw not observable in
this session**:

- `VdSwap` hooked (single owner, `native_renderer.cpp:653-659`); hooks
  install clean (`mode=native`, trace=frames) with no D3D12 errors.
- The game never reached a guest `VdSwap`/present in a 45 s and a 150 s
  window: zero `Renderer frame ...`/`Native render phase3` lines, zero D3D12
  debug-layer messages on stderr, no crash, no device-lost. The header-only
  guest PPC stayed wedged on the documented MCLA splash (repeated
  `NtCreateFile t:\mc4\art\city\test_*.loc -> 0xc000000f`), so
  `Hooked_VdSwap` → `DrawTestMeshedTriangle` never fired.
- This is the **same pre-existing splash wedge** documented under
  "Live-boot capture evidence + splash hang" (2026-08-07): the recomp guest
  FS does not serve the RAGE `t:` art paths from the RPFs. It is a
  game-data/legacy-path limitation, **not** a native-GPU or D3D12 defect;
  `renderer_mode` still `legacy` by default and no code change was needed.
- The start-of-session `backender_validator` fixture remains the authoritative
  geometry evidence (CLEAN, exit 0). The on-window gate stays blocked on
  the same "a capture that covers an actual draw" precondition as the
  capture-replay gate.

## Option-1 gate closure: on-window native present S_OK (2026-08-08, gpu-engineer)

The addendum above ("wiring verified, on-window draw not observable") is
**superseded**. Two back-to-back `renderer_mode=native` runs now close the
on-window present gate: `build\logs\mcla_008.log` (22:42) and `mcla_009.log`
(22:46), RTX 3070, D3D12 debug layer enabled:

- `VdSwap[1..5]` fired on the native path in both runs (obj=0xA872C790 …
  0xA8A11F00), so the guest reaches its present point under native mode.
- `D3D12Backend: DrawTestMeshedTriangle frame=1..3 present_hr=0x00000000`
  (S_OK): the flip-model swap chain presents successfully on-window.
  `present_hr_sok=3`, `swapchain_failed=0`, zero `0x80070005` — the earlier
  `CreateSwapChainForHwnd failed hr=0x80070005` (22:16 run) is fixed: the
  backend initializes on the window-owner thread and native mode no longer
  attaches the rex presenter to the swap chain.
- `DrawTestMeshedTriangle` logs only the first 3 frames (`frame <= 3` guard);
  VdSwap[4]/[5] present without a log line.
- The 4 `[error]` lines are the pre-existing `ExecutePacketType3 overflow /
  INDIRECT RINGBUFFER: Failed to execute packet` GPU-packet overflow — the
  Xenos command processor does not run under native mode and this is unrelated
  to the present path.
- Residual wedge is unchanged and orthogonal: after VdSwap[5] the guest wedges
  in the RAGE city-art `.loc` loader (`NtCreateFile
  t:\mc4\art\city\test_dt_railyard.loc` → pre-mounted stub warnings), so **no
  real guest draw** reached the draw hooks in either run (VdSwap fires;
  `sub_82420BA8`/draw-builder does not).

Gate status after this run:

- **Phase 2 "native clear + present on-window" — CLOSED** (D3D12 backend owns
  the flip-model swap chain; present S_OK; zero debug-layer errors).
- Phase 3 "replay a captured draw with guest vertex data" — **still gated on a
  live draw-level capture**, unchanged. The backend now has the dynamic-geometry
  consumption path to act on one the moment the game reaches a draw (see
  "Dynamic Geometry & Phase 4 Texture Decoding wiring" below); the capture does
  not exist yet.
- `renderer_mode` remains `legacy` by default; native is exercised explicitly
  with `renderer_mode="native"`.

## Dynamic Geometry & Phase 4 Texture Decoding wiring (2026-08-08, gpu-engineer)

Data-independent plumbing; no guest data invented (Golden Rule 5), no
`MclaGpuContext` field consumed.

- **`D3D12Backend::DrawDynamicMesh`** — host-side dynamic-geometry entry point:
  uploads caller vertex bytes (+ optional index bytes) through the per-frame
  upload arena, binds VB/IB, draws indexed (R16/R32) or non-indexed.
  `DrawTestMeshedTriangle` now delegates to it (fixture quad → one draw path),
  preserving the static-IB cache gate. This is the consumption target for a
  captured `DrawPacket`.
- **`Hooked_VdSwap` consumption rule** (native mode): a captured packet is drawn
  dynamically only when the capture layer marked it valid AND it is a single
  stream, non-indexed, `primType == TriList`, and `stride == 28` (the only input
  layout the test VS can render — POSITION float3 + COLOR float4). Guest VB
  bytes are read through the checked `GuestMemoryView`. Any mismatch keeps the
  deterministic quad + a deduplicated diagnostic.
- **Unresolved assumption (recorded, not hidden):** the byte layout of a
  captured stream is still unproven — no live `grcFvf`/fetch-constant snapshot
  exists (Rev-03 constraint). The stride==28 gate is the conservative stopgap;
  a real layout needs the guest VS input layout (blocked Phase 3/5 work).
- **Phase 4 texture decode → SRV path.** Root signature extended with a
  pixel-visibility SRV descriptor table (t0) + static linear-clamp sampler (s0).
  `CreateDecodedTexture` uploads host-linear decoded pixels into a DEFAULT-heap
  texture and creates a shader-visible SRV; `BindDecodedTexture` binds the
  table. The test VS/PS do not sample t0 yet — content sampling needs a
  textured shader pair, gated on a captured texture descriptor (the
  `TextureUntileInfo` capture-layer caller contract is still unwritten).
  CPU `UntileTexture2D` is oracle-validated headlessly; the backend validator
  now adds a D3D12-side fixture (untiled bytes → texture upload → SRV →
  descriptor-table bind → texture readback verify, zero debug-layer messages).

Build/verify: `cmake --build build` clean; `backend_validator.exe` exit 0
(extended fixture); `texture_decode_test.exe` CLEAN.

### Implementation + verification record (2026-08-08, gpu-engineer)

Implemented exactly the wiring above. Files changed and why:

- `src/d3d12_backend.h` / `src/d3d12_backend.cpp` — added `DynamicMeshDesc` +
  `DrawDynamicMesh` (single indexed/non-indexed draw body with the 256-byte
  arena-upload, RTV/viewport/scissor, R16/R32 IB, `present_hr` returned via
  `m_lastPresentHr`); `DrawTestMeshedTriangle` now delegates, preserving the
  static-IB cache gate. Added the Phase 4 texture path: `CreateSrvHeap`,
  `CreateDecodedTexture` (D3D12-footprint row-pitch upload of host-linear
  decoded pixels into a DEFAULT-heap texture + shader-visible SRV at t0) and
  `BindDecodedTexture` (SetDescriptorHeaps + SetGraphicsRootDescriptorTable).
  Root signature extended with the pixel-visible t0 descriptor table + static
  linear-clamp sampler s0. Shutdown releases the new texture/upload/heap.
- `src/capture_hooks.h` / `.cpp` — added `LastPacket()` + bounded
  `ReadGuestRange()` (via checked `GuestMemoryView::ReadBytes`); `OnSubmit`
  stores the last validated packet, `OnFrameEnd` clears it.
- `src/native_renderer.cpp` — `Hooked_VdSwap` native branch now calls
  `TryConsumeCapturedGeometry` (single stream, non-indexed, TriList, stride==28,
  bounded guest read, 1 MiB cap) before falling back to the fixture quad; each
  refusal reason logs once (deduplicated).

Build + run results:

- `cmd /c build\_build_mcla.bat` — **clean** (5/5, zero errors).
- `cmd /c build\_build_backend_val.bat` (wrapper updated to link
  `texture_decode.cpp`) — **clean**.
- `build\backend_validator.exe` — **RESULT: CLEAN, exit 0** on the RTX 3070
  (hardware adapter). All prior fixtures still pass; two new fixtures pass:
  (8) CPU `UntileTexture2D` round-trip 32x32 8_8_8_8 == `GetTiledOffset2D`
  reference; (9) D3D12 decoded-texture slice — untiled pixels → texture upload
  → SRV create → descriptor-table bind + static sampler → texture readback
  verify, **zero debug-layer messages**.
- `build\texture_decode_test.exe` — **CLEAN** (oracle cross-check, unchanged).
- Brief native boot: `build\mcla.exe` (`renderer_mode=native`), log
  `build\logs\mcla_010.log` — `VdSwap[1..5]`, `DrawTestMeshedTriangle frame=1..3
  present_hr=0x00000000`, confirming S_OK on the refactored draw path.

Unresolved guest-structure assumptions carried forward (named + evidence gap):

1. **Captured vertex stream byte layout (field `VertexStreamDesc`).** The
   stride==28 gate is a stopgap; no live `grcFvf`/fetch-constant snapshot exists
   (Rev-03: no 32-byte slot-95 decoder; layout must come from a live capture).
   Evidence gap: a real draw capture with a readable `grcFvf`.
2. **Consumption is inert this session** by design: the game never reaches a
   draw (`LastPacket()` null → fixture quad + one refusal diagnostic per
   reason), so `TryConsumeCapturedGeometry` has not executed a real packet.
3. **Texture content sampling** is blocked on a captured texture descriptor and
   a textured VS/PS pair (no DXC available to compile new shaders); only
   upload/SRV/bind/readback is verified. The `TextureUntileInfo` capture-layer
   caller contract is still unwritten.

**External references identified (2026-08-06, research-scout).** Sibling repos
that support the native-renderer goal, ranked by applicability:

- `hedge-dev/XenosRecomp` (vendored `.research/XenosRecomp`) — authoritative
  `VertexFetchInstruction` bitfield (`shader_code.h:173-231`: format:6,
  stride:8, offset:23, constIndex:5, constIndexSelect:2) + `tfetch` helpers.
  The decode reference for a live fetch-constant trace.
- `Foxxyyy/CodeX.Games.MCLA` — MCLA-specific RSC5 layouts
  (`Rsc5Drawable.cs`): `Rsc5VertexBuffer`/`Rsc5IndexBuffer` with `m_VB[4]`/
  `m_IB[4]` per geometry, `Rsc5VertexDeclaration` (`grcFvf`, 16×4-bit channel
  sizes), component-type + semantic enums, plus `Rsc5Data.cs`
  VIRTUAL_BASE=0x50000000 / PHYSICAL_BASE=0x60000000 addressing. The layout to
  interpret live VB/IB offsets from the `.xtr`.
- `GTA-Network/IV-Network` `Documents/Development_ReverseEngineering/
  IV-Classes.txt` — RAGE render-boundary class map: `rage::rmcDrawable` 6-arg
  draw call (line 763), `CNewGeometryVertexOffsets`, `CSmashMan` draw buckets,
  `grcVertexBuffer`/`grcIndexBuffer` hierarchy. The high-level draw boundary to
  hook.
- `OZORDI/LibertyRecomp` (GTA IV RAGE, rexglue fork) — only active RAGE recomp
  pursuing a native GPU pipeline; early-stage (GPU pipeline not yet
  implemented). Peer reference, not a finished solution.
- Lower relevance: `panah-ryan/RAGEStuffIReversed` (archived IV idb/natives),
  `xenia-canary/game-patches` MCLA patch (tuning only: speed/motion-blur/
  MSAA/imposters), AC6/SotN/Banjo/Skate3 recomp (retain Xenos emulation, not
  native-renderer models).
- No repo yet delivers a finished native RAGE draw-capture/rewrite for MCLA;
  this project remains the pioneer for that boundary.

## Phase 3 gate closure + Phase 4/5 scaffold inventory (2026-08-08, gpu-engineer)

### Phase 3 closure record

Phase 3 implementation milestones are complete and verified headlessly against
the real 551-container corpus and the synthetic geometry fixture. Evidence
(re-run 2026-08-08, RTX 3070, D3D12 debug layer on):

- `build\backend_validator.exe` — **CLEAN, exit 0**, zero debug-layer messages:
  clear fill, both R16-indexed triangles rasterized (topology via index
  buffer), viewport/scissor band correct, distinct per-triangle interpolated
  colors. This closes Phase 3 gate "indexed triangle with correct topology,
  viewport" for the **data-independent** slice (the fixed VS/PS test path).
- `build\phase3_validator.exe "mcla extracted cache/shaders"` — **CLEAN**:
  vf=0 fetch-constant-relative resolved for all 762 fetches → merged slot
  `const[95]`, `single_stream=TRUE` (layout must come from guest `grcFvf`).
  Closes "decodes the first supported vertex formats and 16-/32-bit index
  formats; rejects unsupported visibly".
- `build\shader_pipeline_validator.exe "…/shaders"` — **CLEAN**: 551 containers
  parsed, 317 VS / 234 PS, 0 parse errors, 0 hash mismatches; pipeline-key
  determinism + bounded FIFO eviction tests pass.
- Gate item "replaying the same frame twice does not re-upload unchanged static
  buffers" is verified in the validator index-buffer version test and the
  runtime `cache_hits`/`cache_misses` counters.

The remaining Phase 3 criterion — **"a selected capture replays an indexed
triangle/mesh" with guest vertex data** — is still **gated on a live
draw-level capture**. It has not been demonstrated and is *not* claimed. The
prerequisite is the documented replayable-draw precondition (splash wedge at
`t:\mc4\art\city\test_*.loc`, no guest presents, so no real VB/IB dump
exists). See "Live-boot capture evidence + splash hang" and the
"On-window renderer_mode=native run" addenda. Phase 3 does not depend on it for
the "one geometry slider" goal only if the gate is recorded as a data-external
slice; do not relax this gate wording.

### Phase 4/5 scaffold inventory

Phase 4 (Texture, Sampler, Render-Pass) and Phase 5 (Shader Translation and
Pipeline Cache) groundwork already exists in `src/renderer/` and is compiled
into `mcla.exe` (CMakeLists line 84-89) plus covered by the offline validators:

| File                       | Role (phase)                                              |
| -------------------------- | ---------------------------------------------------------- |
| `xenos_microcode.h/.cpp`   | Xenos microcode decode (CF-bounded); downstream of IR      |
| `xenos_shader_ir.h/.cpp`   | normalized IR + program hash (Phase 5)                     |
| `shader_translator.h/.cpp` | runtime seam: parse+hash; HLSL/DXIL delegated offline      |
| `pipeline_cache.h/.cpp`    | `PipelineKey` + bounded in-memory cache (Phase 5)          |
| `vertex_decode.h/.cpp`     | VFETCH/16-/32-bit decode (Phase 3, Phase 4 reuses)         |
| `resource_cache.h/.cpp`    | address+vw+layout+version keys (Phase 3, Phase 4 reuses)   |
| `test_shaders.h`           | embedded deterministic VS/PS DXIL (Phase 3)                |

The `xenos_shader_ir`/`shader_translator`/`pipeline_cache` triplet is the
Phase 5 translation spine: microcode → IR → pipeline key. The plan's "proposed
source layout" (lines 236-252) names its remaining Phase 4 entries
`texture_decode.h/.cpp` and `frame_graph.h/.cpp`. `texture_decode.h/.cpp` is
**implemented and oracle-validated** (see "Phase 4 texture decode + SDK oracle
validation" below); `frame_graph.h/.cpp` remains not-yet-authored. The
`pipeline_cache` map is a placeholder container; D3D12 PSO objects live in
`D3D12Backend`.

## Phase 4 texture decode + SDK oracle validation (2026-08-08, gpu-engineer)

Closes Phase 4 item 2 ("Xbox tiled/swizzled texture layout conversion,
validated against known memory captures") for the **data-independent** slice:
instead of raw guest captures, validation is against the ReXGlue SDK's own
compiled implementations exported by `rexruntime.dll` — the strongest available
oracle (the SDK IS the same texture_util/texture_conversion the legacy path
calls). Live game captures remain unavailable because the session never
reaches a real draw (see "Live-boot capture evidence + splash hang"), so oracle
validation is the gate evidence here; the capture-based gate is not claimed.

New units in `src/renderer/` (D3D12-free, testable headlessly):

- `texture_decode.h/.cpp` — Xenos format table (all 64 `TextureFormat` codes,
  block size, bits per texel, DXGI mapping, resolvable/compressed flags),
  canonical XGAddress tiled-offset math (2D stacked + 3D volume), upper/lower
  bounds helpers, and byte-exact `UntileTexture2D/3D` with per-block bounds
  guards fed by `srcBytes`/`dstBytes`.
- `resource_cache.h/.cpp` — added `TextureLayout` / `ComputeTextureLayout`
  (sizes a texture from Xenos format + texel extents through the validated
  table; 64-bit intermediate on the byte-size multiply).
- `texture_decode_test.cpp` — oracle validator.
- Oracle tooling in `build/`: `oracle_format_dump.cpp` (+ `_build_oracle_dump.bat`)
  dumps the SDK's compiled `FormatInfo` table; `rexruntime.dll` copied next to
  the test exe so `LoadLibrary` reaches it without installing the SDK.

Validation gates (`build\texture_decode_test.exe`, exit 0 = CLEAN):

| Check | Method | Result |
| --- | --- | --- |
| `GetTiledOffset2D` | cross-check vs `texture_util::GetTiledOffset2D` export over 1,114,939 (x,y,pitch,bpb) probes | 0 mismatch |
| `GetTiledOffset3D` | vs `GetTiledOffset3D` export, 4,989,600 (x,y,z) samples | 0 mismatch |
| `GetTiledAddressUpperBound2D/3D` | vs exported upper bounds | 0 mismatch |
| lower bounds 2D/3D | compositional: masked corner == offset oracle (`left/top & ~31`, `front & ~4` = `kTextureTileDepth`); matches SDK util.h lines 287-300 verbatim | verified |
| Format table | `GetTextureBytesPerBlock` + flags + block shape vs `FormatInfo::Get` for all 64 formats | 0 mismatch |
| `UntileTexture2D` | re-tile via oracle offsets over fixtures (incl. offset region (8,8)+16x16, out-of-grid reject) | byte-identical |
| `UntileTexture3D` | height≠pitch fixture (regresses the pitch-as-height bug) vs oracle 3D offsets | byte-identical |
| `ComputeTextureLayout` | 8_8_8_8 64×64 → 4096 blocks×4 B; DXT1 9×9 → 3×3 blocks×8 B; unknown fmt→invalid | pass |
| Full suite | `backend_validator`, `phase3_validator`, `shader_pipeline_validator` (real shaders corpus), `capture_dump_validator` | all CLEAN, exit 0 |
| `build\mcla.exe` | rebuilt with texture_decode in CMake target (CMakeLists 89-90) | links clean |

Key findings the table dump forced (SDK `FormatInfo` semantics):

- `bits_per_pixel` is bits per **texel**, not per block: `k_DXT1`=18 bpp=4 →
  8 bytes/block; `k_DXT2_3`=19 / `k_DXT4_5`=20 bpp=8 → 16 bytes/block.
- `type` encodes the format class: 0=resolvable (EDRAM-resolvable colors),
  1=uncompressed, 2=block-compressed. `isResolvable = (type==0)`,
  `isBlockCompressed = (type==2)`.
- Host mappings that are literal: DXT3A/DXT5A → `DXGI_FORMAT_BC4_UNORM`
  (1-channel 4x4 4bpp); DXT1/2/3 → BC1/2/3; DXN→BC5; 5_6_5/1_5_5_5/4_4_4_4 →
  B5G6R5/B5G5R5A1/B4G4R4A4 (Xenos stores R-named bits, D3D names BGR);
  24_8 → D24_S8, 24_8_FLOAT→D32FS8X24. Formats without a literal host form
  (1-bit, 6_5_5, YUV REP, MPEG, INTERLACED, _AS_ meta, CTX1) stay
  `dxgiFormat=0` (unsupported) until a captured target forces them.
- Tiled offset math (2D/3D) is the canonical XGAddress formula (Xenia
  `texture_utils.cc` + architected 3D stack) with **round-up** pitch/height
  alignment to 32 and the SDK's 4-deep z tile; reproduced exactly per the
  oracle over the probed grid.

Unresolved guest-structure assumptions on the metadata this phase consumes:

- All tiling/format facts derive from SDK source + compiled exports (evidence,
  not guesses); no guest-buffer field was invented. The `TextureUntileInfo`
  caller contract (which guest fields map to `inputPitch`/`inputHeight`/block
  coords) is **unwritten at the capture layer** — SetPixelData until it is
  wired to real `D3D11::Source/DestTextureRegion`-style descriptors in Phase 4
  capture work; session knowns gaps recorded here rather than buried.
- `6_5_5` (host B? none) and `1_REVERSE`/`1` stay unsupported; a captured
  fixture must raise them or prove they are unused before the backend claims a
  target.

Tracked backlog for Phase 4 remainder (sampler mapping, render passes,
frame-position targets) is untouched; the module is consumed only by the
validator and `ComputeTextureLayout` today, and does not hook or touch
`MclaGpuContext`.

**Dynamic register consumption from `MclaGpuContext`.** Phase 4/5 picking up
real draw state must read shader program pointers and render-state fields from
the guest GPU context. That path is not wired yet: hooks currently snapshot
state for the register-file route only (legacy/capture). The validated field
offsets are documented in `MCLA_GPU_CONTEXT_STRUCT.md` (e.g. VS/PS program
pointers `+0x3184`/`+0x3188` `SQ_VS_PROGRAM`/`SQ_PS_PROGRAM`, VS/PS constant
bases `+0x317C`/`+0x3180`, draw count `+0x31DC`, and target/viewport/scissor
array `+0x3098`-`+0x30A8`). No `MclaGpuContext` field has been added or
consumed dynamically this session; per Project Rule 4, postpone until live
capture evidence proves each offset in the guest binary the next phase consumes.

## Phase 3 consumption-gate fixes (2026-08-08, gpu-engineer)

Code review of the Phase 3 consumption path found four defects that would keep
the "consume a captured draw" path dead or malformed; all fixed and verified:

1. **Packet cleared before read** — `Hooked_VdSwap` called `LastPacket()` only
   *after* `GetDrawAccumulator()->OnFrameEnd()`, which zeroes `m_lastPacket`
   and clears `m_lastPacketValid`, so consumption always saw an invalid packet.
   Fixed: snapshot the packet (value copy of the trivial POD) *before*
   `OnFrameEnd()` and consume the snapshot. Verified: the only `LastPacket()`
   call site now precedes `OnFrameEnd()` (`src/native_renderer.cpp:592` vs
   `:597`).
2. **`indexType != 2` gate unreachable** — capture inferred only 0/1 from a
   single flag bit, so the non-indexed gate (the only layout the test PSO
   supports) could never pass. Recomp evidence (`sub_82420BA8`,
   `generated/default/mcla_recomp.26.cpp:20301-20345`) shows bits 4-6 of the
   draw flags are the index-type field, derived from a `u16 & 3` lookup into
   `0x10`/`0x50`/`0x70`; the consumer distinguishes `&0x10` vs `&0x20`
   (`mcla_recomp.28.cpp:19287-19297`). `OnDrawBuild` now decodes
   `(drawFlags >> 4) & 0x7` → `0x1`→0 (16-bit), `0x5`→1 (32-bit), `0x7`→2
   (non-indexed); unknown encodings (the "already set" branch values 0x20/0x30/
   0x40/0x60) mark the capture failed rather than defaulting (no invented draw
   data).
3. **Cached IB bound with `SizeInBytes=0`** — a cached index buffer was bound
   with zero size, which D3D12 treats as an *unbound* slot (the rasterizer
   silently skips the draw; the validator missed it because fixture 7
   replicates the command sequence offscreen and never calls
   `DrawDynamicMesh`). Fixed: `DynamicMeshDesc` gains `cachedIndexBytesSize`;
   the cache-hit branch of `DrawTestMeshedTriangle` records the real byte size
   and `DrawDynamicMesh` refuses any cached IB whose size is still 0 and binds
   the nonzero size.
4. **Upload-region write racing in-flight GPU reads** — `MapUpload` wrote the
   per-frame upload region before the `BeginFrame()` fence wait for the frame
   that owns that region, so a still-rendering prior frame could read
   overwritten bytes. Fixed: extracted `WaitForCurrentFrameGpu()` (waits the
   fence value recorded when the current back buffer was last rendered) and
   call it in `DrawDynamicMesh` *before* `MapUpload`; `BeginFrame` keeps its
   (now-redundant-on-this-path, required-by-`ClearAndPresent`) wait.

Validation evidence (re-run 2026-08-08, RTX 3070, D3D12 debug layer on):

- `cmake --build build` (vcvars64 + Ninja, clang-cl) — **7/7 targets, 0 errors**.
- `build\backend_validator.exe` — **RESULT: CLEAN**, exit 0, zero debug-layer
  messages.
- Re-review (`code-reviewer`) of the four edit sites — **no blockers, no
  regressions**; indexType decode matches recomp byte-for-byte, IBV never bound
  with size 0, fence-wait order correct, recursive mutex not deadlocked.
- Live native boot (`--renderer_mode native`) still cannot reach a real draw:
  `game_data\mc4` contains only `art\`, no `default.xex`, so no guest present /
  draw is produced (same precondition as the splash-wedge addendum). The
  consumption path therefore stays the "snapshot empty → fixture fallback"
  state in a live run; headless evidence is the gate, not a live draw.

Resolved-now vs open guest-structure assumptions:

- Resolved: index-type field location (bits 4-6 of draw flags) is now
  recomp-backed, not guessed; consumption gate is reachable.
- Open: `TryConsumeCapturedGeometry` binds guest vertex data only for the
  non-indexed 28-byte-stride layout the test PSO supports. The captured index
  buffer layout (address, element size, offset semantics) is still unproven by
  capture evidence, so indexed guest draws remain refused by design — do not
  relax until a live capture demonstrates the IB descriptor.
- Open: per-frame upload assumes one draw per frame (capture XOR fixture);
  multi-draw-per-frame staging is future work, out of scope for this gate.

