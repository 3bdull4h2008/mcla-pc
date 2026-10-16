# TASK_GPU — draw chain (one doc, no split)

> Chain (ownership: `src/rage/rage_ideal_flow.h:27-31`): guest owns bytes,
> backend owns pixels. Never fake the frame path — a placeholder pixel that
> reports success hides the real producer.

## The chain, in order

1. **Capture** — `src/capture_hooks.cpp:585-590` fills `grcFvf` (fvfMask,
   fvfSize, flags, dynamicOrder, channelCount, types) from guest words via
   `ReadU32BE` (`src/capture_hooks.cpp:453-457`). No reinterpret_cast.
2. **Vertex decode** — `src/renderer/vertex_decode.h` + `grc_fvf_decode`
   (authoritative lane map: `src/renderer/pipeline_cache.h:643`;
   separation note `src/renderer/grc_fvf_decode.h:29`). Input layout builder:
   `BuildInputLayoutFromGrcFvf` at `src/d3d12_backend.h:501`.
3. **Shader** — pinned entry `TranslateShaderPinned`; shared body at
   `src/renderer/shader_translator.cpp:2248`, fetch/semantic error at
   `:809`. Owner string: `src/rage/rage_ideal_flow.h:70`.
4. **Pipeline cache** — `src/renderer/pipeline_cache.cpp` (rect-list keying
   cited at `src/d3d12_backend.cpp:423`; constant-bank pack at
   `src/d3d12_backend.cpp:3482` → `PackXenosConstantBank`,
   `src/renderer/pipeline_cache.h:349`).
5. **Textures/samplers** — `BindGuestTextures` (`src/d3d12_backend.h:463`,
   impl `src/d3d12_backend.cpp:1910`); `BindGuestSampler`
   (`src/d3d12_backend.h:476`, impl `src/d3d12_backend.cpp:2175`).
   Guest path owns this; native `GetTextureData` REFUSES, see below.
6. **Draw** — `DrawDynamicMeshWithPipeline` (`src/d3d12_backend.h:175`,
   impl `src/d3d12_backend.cpp:2940`); refuses null pipeline by design
   (`src/d3d12_backend.cpp:2811`). Prim mapping: `MapXenosPrimType`
   (`src/d3d12_backend.h:155`, impl `src/d3d12_backend.cpp:387`).
7. **Resolve + present** — `ResolveGuestSurface` (`src/d3d12_backend.h:587`);
   `PresentOwnedFrame` is the ONLY sanctioned Present
   (`src/d3d12_backend.h:729-738`, impl `src/d3d12_backend.cpp:5679`).

## Refusal counters (prove with a soak, not a unit test)

- `DRAW-CP-DRAWN` (render thread, after draw; e.g. `src/d3d12_backend.cpp:3164`).
- `DRAW-CP-REFUSE` classes incl. vb-missing (`src/capture_hooks.cpp:793`,
  `src/d3d12_backend.cpp:472`).
- `RAGE-ASSET-REFUSE` (`src/rage/rage_asset_pipeline.cpp:510`) — native
  `GetTextureData` returns honest `false` (`:499-516`); guest path owns frames.
- Exotic prims / t4+ descriptors / depth-resolve variants: refuse + count in
  backend; parked until menu (MENU-GATE, `src/rage/rage_ideal_flow.h:56-61`).

## Gates

`DRAW_INDEXED`=0 and two presents ever is the standing baseline — move it only
with a soak whose `dstAfter=61786772`, `headIs=1`, `FATAL-SOFT=0`.
Current census baseline: w756 (see handoff doc).
