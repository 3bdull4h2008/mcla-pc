# UR vs MCLA — Full Comparison (2026-08-22, session 3)

Three subagent reports merged (research-scout: architecture/assets/kernel/plan ·
build-specialist: toolchain/codegen/shader pipeline · reverser: generated source).
Raw details in session log; this file = durable distillation.

## 1. GAME / ENGINE
- UR = Sonic Unleashed, **Hedgehog engine**: C++ RTTI OO, typed `SWA::` headers
  (api/ empty locally, upstream-generated), ~40 named-address hooks valid for ONE xex rev.
- MCLA = **RAGE** (Rockstar): no typed headers; equivalents rederived via Ghidra
  (device publish slot 0x82000864, sub_82413588 create, sub_82420BA8 draw builder,
  sub_8241ABB8 state setup). Higher per-field verification cost, no shortcuts.

## 2. GPU TECHNIQUE (the big one)
- UR **never touches PM4**: `VdSwap` is an EMPTY STUB (kernel/imports.cpp:794);
  ring-buffer imports stubbed too. Boundary = game's own D3D9-class device layer
  (~40 overrides incl. CreateDevice/Present/SetTexture).
- UR flow: guest device calls → mutate Guest{Texture,Buffer,Surface} objects living
  IN GUEST HEAP (`g_userHeap.AllocPhysical`) → RenderCommand variants →
  moodycamel blocking queue → **dedicated render thread** (+ separate copy queue for
  streaming). Async PSO compile pool ((hw*2)/3 threads) fed by streaming-load discovery
  + boot-time precompiled list.
- UR shaders: OFFLINE XenosRecomp translates shader.ar microcode → HLSL → zstd-compressed
  embedded DXIL(+smol-v SPIRV), signed at build. Runtime does specialization via dxcompiler.dll
  library linking. plume RHI = D3D12+Vulkan.
- MCLA today: capture hooks at RAGE gfx layer exist (native mode bypasses PM4 emission),
  but draws are synthetic-only; runtime DXC on captured .fxc; no queues/render thread;
  monolithic d3d12_backend; legacy PM4 path still alive.

## 3. ASSETS / IO (inverted responsibility)
- UR: redirect paths (game:\ → install dirs), CRT wrappers XCreateFileA/XReadFile…,
  guest parses its own .ar/.arl archives. Host stays thin.
- MCLA: host PARSES RPF3 packfiles itself (vfs_rpf.cpp, "RPF3"@0x800, TOC@0x1000)
  served over extracted tree + junctions. Needed because RAGE IO wasn't proven;
  correctness risk lives host-side instead of kernel-side.

## 4. KERNEL SURFACE
- Similar scale: UR ≈275 GUEST_FUNCTION_HOOKs tree-wide vs MCLA 267 (imports.cpp alone).
- Framework identical (plan mandates exact mirror): typed-arg hooks, identity handles,
  QueryKernelObject lazy-wrap, single-param Wait, atomic_ref critsections, gen counter.
- UR ships FULL Xam content/save/achievement surface; MCLA mostly stubs.
- VdSwap semantics opposite by design (stub vs full Xenia-shaped PM4 writer).

## 5. BUILD ENVIRONMENT (gaps ranked)
1. Deps: UR=vcpkg manifest + submodules + presets; MCLA=hand-vendored + HARDCODED
   VS/SDK absolute paths (CMakeLists.txt:48-56) — non-reproducible.
2. No CMakePresets.json / pinned clang-cl version here.
3. Codegen not wired into build: UR regenerates ppc/ via add_custom_command from
   SWA.toml (261 TUs); ours manual (179 TUs enumerated by hand) → drift risk.
4. Build-time shader cache embedding (zstd DXIL + DXIL signer) absent; zstd not vendored.
5. `.xexp` patch-flow unsupported (probably N/A for MCLA dump).
6. `invalid_instructions` + explicit `functions` lists unverified for MCLA image.
7. simde not vendored (UR compiles guest TUs with it available).

## 6. GENERATED SOURCE / ABI
- Lookup formula byte-identical both sides (*2 stride table after image).
- MCLA missing `SKIP_LR`/`SKIP_MSR` config flags → ctx keeps lr/msr fields (layout
  diverges from UR template; fine but must be remembered when porting UR code).
- BUG A (gpr[N] aliasing) was MCLA-only hand-written defect; UR template has no gpr[].
- Hook macros + function.h ArgTranslator = verbatim port of UR's (r3-r10/f1-f13/
  stack@r1+0x54+(arg-8)*8 identical).
- Override density: UR 20 strong PPC_FUNC(sub_XXXX) + ~150 [[midasm_hook]] entries
  (instruction-level patching! conditional jumps, register capture) vs MCLA exactly 1
  strong override (sub_82413588). midasm_hook layer = biggest generated-source gap.
- setjmp/longjmp: UR redirects to HOST setjmp/longjmp at configured CRT addrs; MCLA
  verified ABSENT in image (left 0) ✓.
- Exception frame-handler ptrs must be declared invalid_instructions data — MCLA
  hasn't surveyed its own (UR listed 0x831B1C90/0x8324B3BC for SWA).
- Scale: MCLA 19,887 funcs / 46,041 mappings / 180 cpp verified. UR counts UNKNOWN locally.

## 7. PLAN / DISCIPLINE
- UR: no phase-gate doc; manual QA vs original HW; preserves known bugs; enhancements post-release.
- MCLA: gated ladder P1✅P2⚠️P3-P6 + verification ladder (rung≥2, maker≠checker).
  Adopt UR techniques; do NOT adopt evidentiary laxity.

## PORTING PRIORITY (merged, ranked)
1. Make native mode the ONLY frame producer; demote Vd*/PM4 to inert plumbing (P6 pull-forward).
2. Render thread + blocking command/copy queues (biggest structural gap).
3. Offline shader cache: corpus (1264 files) → zstd-embedded DXIL; kill runtime-JIT hitches.
4. Resource model maturity: Guest{Texture,Buffer,Surface} w/ deferred dtor, lock/unlock,
   copy tracking in guest heap (UR video.cpp:177-328 is the blueprint).
5. midasm_hook equivalent OR accept per-function overrides only (decide early — shapes codegen).
6. MSAA resolve path (RAGE heavy user; UR has 2x/4x/8x resolve shaders as reference).
7. Streaming-aware PSO precompilation (needs RAGE streaming RE - open item).
8. Survey invalid_instructions/functions coverage for our XEX; consider SKIP_LR/MSR flip
   only if we adopt midasm/config-driven patches that assume them.
