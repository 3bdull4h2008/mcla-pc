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
  validated by `phase3_validator.exe` against the 551-container shader corpus:
  **CLEAN** (0 unsupported vertex-fetch codes; all 762 fetches are
  fetch-constant-relative via `const[31]`, as documented).
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

