#pragma once

// Phase 5 pipeline-state key + in-memory pipeline cache with async compilation.
//
// A PipelineKey uniquely identifies a pipeline for native execution: the
// translated VS/PS program hashes, the vertex declaration, the color/depth
// target formats, the blend/raster/depth-stencil state, the topology and the
// sample count. Keys are POD and hashable so they can be used in an
// unordered_map. The cache stores ID3D12PipelineState objects directly and
// provides an async compilation queue for on-demand PSO creation.
//
// F-609 (native-only charter, no fakes). Four invariants this header now owns,
// each of which the previous revision violated:
//
//  1. A key can REFUSE. PipelineKey::refuseMask is set by ComputePipelineKey and
//     by DerivePipelineState; GetOrCompile turns any non-zero mask into a loud,
//     counted refusal (RefuseOnce) instead of a cacheable miss that quietly
//     degrades the frame onto the test PSO. A null PSO is NEVER inserted
//     (PipelineCache::Insert rejects it): a cached failure is a permanent lie.
//  2. The state in the key is the state the PSO is built from. PipelineState
//     carries the literal D3D12_RASTERIZER_DESC / BLEND_DESC /
//     DEPTH_STENCIL_DESC the worker applies (PipelineState::d3d12); before this
//     the key carried three opaque "hashes" the worker ignored entirely, so one
//     draw could produce two keys (backend hashed paClipCntl, render thread
//     zeroed it) and the PSO that came back matched neither.
//  3. Vertex-input layout and vertex-declaration hash come from ONE builder
//     (BuildGrcFvfInputLayout), so the layout handed to CreateGraphicsPipeline-
//     State and the hash in the key can no longer disagree.
//  4. DXC deploy is a stated requirement, not an environment accident; see
//     dxc_runtime.h.

#include <cstddef>
#include <cstring>
#include <cstdint>
#include <string>
#include <thread>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <future>
#include <memory>
#include <wrl/client.h>

#include <d3d12.h>

#include "renderer/grc_fvf_decode.h"
#include "renderer/shader_translator.h"
#include "renderer/dxc_runtime.h"

namespace mcla::renderer {

constexpr uint32_t kMaxRenderTargets = 8;
constexpr uint32_t kMaxVertexStreams = 16;

// Root-signature / constant-bank contract shared with d3d12_backend.h. The
// generated HLSL binds `cbuffer ShaderConstants : register(b0)`
// (shader_translator.cpp AppendHeader) and t0..t3 + s0; CreateTestRootSignature
// declares exactly that. These constants name the contract once so a future
// root-signature change has a single edit site.
// F-644: the root signature has THREE parameters -- 0 = t0..t3 SRV table,
// 1 = the s0 SAMPLER descriptor table, 2 = the b0 CBV. `kShaderConstantRootSlot`
// is the CBV's index in that array; the sampler table's index (1) is named here
// too so the two cannot drift apart again.
constexpr uint32_t kShaderTextureSlotCount = 4;   // t0..t3
constexpr uint32_t kShaderSamplerRegister = 0;    // s0
constexpr uint32_t kShaderSamplerRootSlot = 1;    // the s0 descriptor table
constexpr uint32_t kShaderConstantRootSlot = 2;   // the b0 CBV (F-644: was 1)
constexpr size_t kShaderConstantBankBytes = 256 * 16;  // 256 float4 == d3d12_backend.h kShaderConstantBytes
constexpr uint32_t kShaderConstantRootRegister = 0;     // b0

// ---------------------------------------------------------------------------
// F-646: where the render state actually lives, and how we know it arrived
// ---------------------------------------------------------------------------
// The three registers the rasteriser/clipper/viewport decoders need are Xenos
// register-space indices, not fields of any struct the host owns. The indices
// are NOT guessed and NOT derived from a name: they are the three consecutive
// entries in the generated Xenos register table,
// .research/xenia/src/xenia/gpu/register_table.inc:540-542 --
//   XE_GPU_REGISTER(0x2204, kDword, PA_CL_CLIP_CNTL)
//   XE_GPU_REGISTER(0x2205, kDword, PA_SU_SC_MODE_CNTL)
//   XE_GPU_REGISTER(0x2206, kDword, PA_CL_VTE_CNTL)
// 0x21FA/0x21FB/0x21FC (VGT_DMA_BASE/SIZE/DRAW_INITIATOR) sit immediately below
// and are poked by the same draw path, which is how the neighbourhood was
// confirmed rather than assumed.
//
// These names matter because the capture gap that is currently refusing every
// pipeline is a MISSING LINK, not missing data: the command processor DOES hold
// these values in its Xenos register file (measured, build/w658.log --
// `CP-DRAW-REGS` rows `r2204=00010000 r2205=00010000 r2206=00000300`), but that
// file is `g_xenosReg`, a file-scope array inside an anonymous namespace in
// src/gpu_cp.cpp (namespace opens at src/gpu_cp.cpp:24, array at
// src/gpu_cp.cpp:125), so nothing outside that translation unit can read it.
// PipelineStateInputs::registersPresent is therefore the contract: the producer
// states which registers it actually carried, and DerivePipelineState refuses
// the ones it did not instead of reading 0 and believing it.
constexpr uint32_t kXenosRegPaClipCntl     = 0x2204u;
constexpr uint32_t kXenosRegPaSuScModeCntl = 0x2205u;
constexpr uint32_t kXenosRegPaClVteCntl    = 0x2206u;

// D1: the polygon/depth-bias MAGNITUDES. `RB_DEPTHF_INFO` -- the register the
// old refusal message named -- IS NOT A REGISTER: `git grep "DEPTHF" --
// .research/xenia/src/xenia/gpu/` returns 0 hits. Neither is `PA_SU_OFFSET_*`.
// The real magnitudes are four kFloat registers,
// register_table.inc:615-618, read by the reference at draw_util.cc:103-104,
// :108-109 and :115-116:
//   XE_GPU_REGISTER(0x2380, kFloat, PA_SU_POLY_OFFSET_FRONT_SCALE)
//   XE_GPU_REGISTER(0x2381, kFloat, PA_SU_POLY_OFFSET_FRONT_OFFSET)
//   XE_GPU_REGISTER(0x2382, kFloat, PA_SU_POLY_OFFSET_BACK_SCALE)
//   XE_GPU_REGISTER(0x2383, kFloat, PA_SU_POLY_OFFSET_BACK_OFFSET)
// They are ABSOLUTE floating-point offsets, not bitfields (draw_util.h:118-119),
// and the enables are bits 11-13 of PA_SU_SC_MODE_CNTL, which we DO capture.
constexpr uint32_t kXenosRegPolyOffsetFrontScale  = 0x2380u;
constexpr uint32_t kXenosRegPolyOffsetFrontOffset = 0x2381u;
constexpr uint32_t kXenosRegPolyOffsetBackScale   = 0x2382u;
constexpr uint32_t kXenosRegPolyOffsetBackOffset  = 0x2383u;
// D1: RB_DEPTH_INFO 0x2002 (register_table.inc:482). It carries NO bias
// magnitude -- registers.h:835-848 has only depth_base/depth_base_bit_11/
// _pad_12/depth_format/_pad_17 -- but `depth_format` (ONE bit at +16,
// registers.h:844) is the input GetD3D10IntegerPolygonOffset needs to pick
// between the unorm24 and float24 factors (draw_util.h:206-215). So this
// register is required by the bias PATH, and never by the magnitude.
constexpr uint32_t kXenosRegDepthInfo = 0x2002u;

// Which of the three arrived with this draw. Bit i set == the corresponding
// register's value in PipelineStateInputs is the guest's, not a default. The
// distinction is load-bearing: a zeroed PA_SU_SC_MODE_CNTL is not "no special
// raster state", it is a legal register value that happens to say
// poly_mode=0 (solid triangles), cull_front=cull_back=0 (draw both faces),
// face=0 (CCW front) -- so accepting a default silently produces a plausible,
// WRONG rasteriser. Same for PA_CL_CLIP_CNTL=0 (clipping on, depth clip TRUE)
// and PA_CL_VTE_CNTL=0 (all six viewport-transform enables clear).
enum GuestRegisterPresent : uint32_t {
    kGuestRegNone            = 0u,
    kGuestRegPaSuScModeCntl  = 1u << 0,  // PA_SU_SC_MODE_CNTL  0x2205
    kGuestRegPaClipCntl      = 1u << 1,  // PA_CL_CLIP_CNTL     0x2204
    kGuestRegPaClVteCntl     = 1u << 2,  // PA_CL_VTE_CNTL      0x2206
    // D1: the bias MAGNITUDES, claimed as a pair per face because that is how
    // the reference selects them (draw_util.cc:93-121 picks the front PAIR
    // 0x2380/0x2381 or the back PAIR 0x2382/0x2383, never a mix).
    kGuestRegPolyOffsetFront = 1u << 3,  // 0x2380 + 0x2381 (front SCALE+OFFSET)
    kGuestRegPolyOffsetBack  = 1u << 4,  // 0x2382 + 0x2383 (back  SCALE+OFFSET)
    // D1: RB_DEPTH_INFO 0x2002, for depth_format only (the bias conversion).
    kGuestRegDepthInfo       = 1u << 5,
};

// ---------------------------------------------------------------------------
// Refusals
// ---------------------------------------------------------------------------
// Every reason GetOrCompile / the worker declined to produce a PSO. A key
// carrying any of these is never compiled and never cached; the reason is
// logged once per distinct key (bounded) and counted in PipelineCacheStats.
enum PipelineRefusal : uint32_t {
    kRefuseNone                    = 0u,
    kRefuseStateNotDerived         = 1u << 0,  // PipelineState was not built by DerivePipelineState
    kRefuseEmptyHlsl               = 1u << 1,  // no translated HLSL for a stage
    kRefuseNoDevice                = 1u << 2,
    kRefuseNoRootSignature         = 1u << 3,  // worker cannot know what the command list will bind
    kRefuseEmptyInputLayout        = 1u << 4,
    kRefuseLayoutDeclHashMismatch  = 1u << 5,  // layout hash != the hash in the key
    kRefuseUnsupportedPolyMode     = 1u << 6,  // paSuScModeCntl.poly_mode outside the mapped case
    kRefuseTopologyUnknown         = 1u << 7,  // primType outside the mapped set
    kRefuseOverTextureSlots        = 1u << 8,  // reflected SRV outside t0..t3
    kRefuseSamplerRegister         = 1u << 9,  // reflected sampler is not s0
    kRefuseRequiredDepthState      = 1u << 10, // caller demanded measured depth state; not captured
    kRefuseQueueSaturated          = 1u << 11, // kMaxInflight reached, no task queued
    // F-646: one bit PER register, so a soak can answer "which register did not
    // arrive" without reading the state values. Each names the guest register
    // whose absence forced the refusal, which is the only claim a future soak
    // can act on -- "the raster state was missing" is not actionable, "0x2205
    // PA_SU_SC_MODE_CNTL was not in the packet" is.
    kRefuseNoPaSuScModeCntl        = 1u << 12, // 0x2205 absent -> no cull/fill/poly-mode
    kRefuseNoPaClipCntl            = 1u << 13, // 0x2204 absent -> no clip_disable/depth_clip
    kRefuseNoPaClVteCntl           = 1u << 14, // 0x2206 absent -> no viewport-transform state
    // F-646: the VTE enables arrived but the viewport EXTENTS did not, so the
    // transform is known to be either pass-through or applied and there is no
    // way to tell which. See DecodedXenosRenderState::vportTransformApplied.
    kRefuseViewportExtentsUnmeasured = 1u << 15,
    // D1: the depth-bias magnitudes are four kFloat registers the renderer does
    // not capture (0x2380-0x2383), and the conversion additionally needs
    // RB_DEPTH_INFO.depth_format (0x2002). Each bit names the registers that
    // are actually MISSING, so a refusal can never again cite a register that
    // does not exist in the hardware -- which is what the old PC-POLYOFF line
    // did when it blamed RB_DEPTHF_INFO (0 occurrences in the reference).
    kRefuseNoPolyOffsetFront  = 1u << 16, // 0x2380/0x2381 absent -> front bias unknown
    kRefuseNoPolyOffsetBack   = 1u << 17, // 0x2382/0x2383 absent -> back bias unknown
    kRefuseNoDepthInfo        = 1u << 18, // 0x2002 absent -> depth_format unknown, so
                                         // the absolute->relative bias conversion
                                         // has no factor (draw_util.h:206-215)
    // F-653: the rectangle-list geometry stage could not be built. Two distinct
    // causes, because the difference between them is a black screen and a
    // compile error respectively, and a soak must be able to read them apart:
    //   kRefuseGeometryStageUnsupported -- the device feature level is below the
    //     one a geometry stage requires, so no PSO with pGeometryShader can be
    //     created at all. Counted by D3D12Backend at device creation.
    //   kRefuseGeometryShaderUnbuildable -- the stage's HLSL could not be
    //     derived from the translated vertex shader's own output signature, so
    //     there is no honest interpolator set to pass through. Never defaulted.
    kRefuseGeometryStageUnsupported = 1u << 19,
    kRefuseGeometryShaderUnbuildable = 1u << 20,
    // F-692 / F-716: NO PSO EXISTS FOR THIS KEY, and no HLSL is missing. Three
    // measured sites used kRefuseEmptyHlsl for it, so a PSO-creation failure
    // printed `reason=empty-hlsl` for a cause that has nothing to do with HLSL
    // (pipeline_cache.cpp, the three `WorkerLoop(pso)` refusals):
    //   * CreateGraphicsPipelineState rejected the pipeline (hr != S_OK). DXC
    //     had already compiled every stage (PC-TRANSLATE failed=0), so the cause
    //     is the descriptor or the stage-signature LINK, not a compile.
    //   * the key names no render target format, so the PSO would declare zero
    //     RTs and could not be used with a bound RTV anyway.
    //   * the key state sets DepthEnable with DSVFormat == DXGI_FORMAT_UNKNOWN,
    //     which D3D12 forbids outright.
    // The name claims exactly what was measured -- "the PSO could not be
    // created" -- and NOT which of the three it was, because that is what the
    // `--` clause and PC-PSO-CREATE-FAILED are for. kRefuseEmptyHlsl stays on
    // the DXC-compile-failure sites, where it is true.
    kRefusePsoCreateFailed         = 1u << 21,
};

// Number of named reasons; also the stride of
// PipelineCacheStats::refusalsByReason. A new bit above 1u<<22 must not silently
// index past it.
constexpr uint32_t kPipelineRefusalBitCount = 22u;

// The highest bit in use must be INSIDE the counted width, or a refusal would
// increment a counter the name table never covers. The previous version of this
// file had only the `refusalsByReason[32]` bound (below), which cannot catch a
// bit at 1u<<30 -- that still fits the array but is outside kPipelineRefusalBitCount.
static_assert(kRefusePsoCreateFailed < (1u << kPipelineRefusalBitCount),
              "PipelineRefusal has a bit above kPipelineRefusalBitCount");
static_assert(kRefuseGeometryShaderUnbuildable < (1u << kPipelineRefusalBitCount),
              "PipelineRefusal has a bit above kPipelineRefusalBitCount");
static_assert(kPipelineRefusalBitCount == 22u,
              "kPipelineRefusalBitCount must equal the number of assigned bits (0..21)");

// Renders a refusal mask as "name|name" into `out` (never allocates).
void FormatPipelineRefusal(uint32_t mask, char* out, size_t outBytes);

// The literal D3D12 state the worker applies to CreateGraphicsPipelineState and
// that the key therefore identifies. Trivially copyable PODs; `= {}` zeroes
// them, and every field is assigned by DerivePipelineState.
struct PipelineStateD3D12 {
    D3D12_RASTERIZER_DESC raster;
    D3D12_BLEND_DESC blend;
    D3D12_DEPTH_STENCIL_DESC depthStencil;
};

// F-653: WHICH GEOMETRY STAGE, if any, this pipeline carries.
//
// This is a separate axis from `topology` on purpose, and it is part of the key,
// because a rectangle draw and a triangle draw over the SAME two shaders and the
// SAME raster state are DIFFERENT pipelines: the rectangle one carries a geometry
// stage that expands the console's rectangle list, the triangle one does not.
// Keying them apart on `topology` alone is impossible, because both are
// triangles at the PSO level -- the expansion is a STAGE, not a topology (see
// the 0x08 case in DerivePipelineState) -- so a shared key would hand a triangle
// draw a stage that reorders its vertices, or hand a rectangle draw a pipeline
// with nothing to expand it. Either failure is silent: the driver has no way to
// object to a valid PSO that draws the wrong vertices.
//
// Declared ABOVE PipelineState because the struct member is initialised from
// kGeomStageNone; a default member initialiser cannot see a constant declared
// later in the file.
//
// The zero value is the only one DerivePipelineState may leave unset, and it
// means "no geometry stage", which is what every non-rectangle draw gets. There
// is deliberately no "unknown" value a caller could set by accident: a geometry
// stage is either named here or absent.
constexpr uint8_t kGeomStageNone = 0;
constexpr uint8_t kGeomStageRectangleList = 1;

// Render-state inputs to a pipeline key (subset relevant to PSO creation).
struct PipelineState {
    uint32_t targetFormats[kMaxRenderTargets] = {};
    uint32_t depthStencilFormat = 0;
    // Guest-register fingerprints, kept for provenance/log correlation and for
    // the (still correct) key identity: two packets with the same registers
    // must produce the same key regardless of which path asked. NOT used to
    // build the PSO any more -- see `d3d12`.
    uint32_t blendState = 0;      // paClipCntl
    uint32_t rasterState = 0;     // paSuScModeCntl
    // F-646: the comment on this member said "paClVteCntl", which was WRONG in a
    // way that mattered. PA_CL_VTE_CNTL is the *viewport transform engine*
    // control register (registers.h:565-584: vport_{x,y,z}_{scale,offset}_ena,
    // vtx_xy_fmt, vtx_z_fmt, vtx_w0_fmt) -- it says whether the hardware applies
    // a viewport transform and how it formats the output. It is NOT depth or
    // stencil state: the Xenos ztest lives in RB_DEPTH_INFO / COLOR0_INFO, which
    // this renderer does not capture at all (see the kStateFlagUnmeasuredDepth
    // comment in DerivePipelineState). Naming a viewport register
    // "depthStencilState" invited a reader to think depth state had been
    // measured. The field is KEPT (renaming it would break
    // d3d12_backend.cpp:3550, which assigns it) and re-labelled: it is a
    // provenance fingerprint of the viewport-transform register, and the
    // decoded viewport facts live in DecodedXenosRenderState.
    uint32_t depthStencilState = 0; // F-646: paClVteCntl = VIEWPORT transform control, NOT depth
    uint8_t topology = 0;         // primitive topology
    uint8_t sampleCount = 1;      // MSAA sample count
    // F-653: which geometry stage this pipeline carries (kGeomStage*). Part of
    // the key; see the constants above for why it cannot be folded into
    // `topology`.
    uint8_t geometryStage = kGeomStageNone;
    // Provenance of this state, set only by DerivePipelineState / SetDerived-
    // PipelineState. kStateDerivedNone (0) is the zero-initialised value and is
    // refused: a state nobody derived cannot be identified honestly.
    uint8_t derivation = 0;
    uint8_t flags = 0;            // see kStateFlag*
    PipelineStateD3D12 d3d12;
};

// `topology` is the PRIMITIVE TYPE identity a D3D12 graphics PSO can express,
// NOT a D3D_PRIMITIVE_TOPOLOGY and NOT the Xenos prim_type. D3D12 splits that
// idea in two: `D3D12_PRIMITIVE_TOPOLOGY_TYPE` is one of exactly three values
// (POINT / LINE / TRIANGLE, d3d12.h) and the list/strip/fan stride lives in the
// draw's IASetPrimitiveTopology instead -- so a strip is the SAME PSO state as
// the list it is a strip of, and collapsing them here is not a substitution.
// The three values are named because bare 0/1/2 in a switch is how the wrong
// guest mapping survived: the previous table read `0 -> triangle` straight off
// DrawPacket::primType's own stale comment and so mapped kNone to a triangle
// list. These are the numbers the worker's PSO switch (pipeline_cache.cpp,
// `switch (st.topology)` -> PrimitiveTopologyType) and the other writers of
// PipelineState (d3d12_backend.cpp `BuildPipelineStateFromPacket`,
// render_thread.cpp) all agree on -- do not renumber them.
constexpr uint8_t kTopoTriangle = 0;
constexpr uint8_t kTopoLine = 1;
constexpr uint8_t kTopoPoint = 2;

constexpr uint8_t kStateDerivedNone = 0;      // zero-initialised -> refused
constexpr uint8_t kStateDerivedGuest = 1;    // DerivePipelineState, from guest registers
constexpr uint8_t kStateDerivedExplicit = 2; // caller supplied D3D12 state directly

// Stamped into PipelineState::flags so a PSO built on the depth placeholder
// stays countable (PipelineCacheStats::unmeasuredDepthState).
constexpr uint8_t kStateFlagUnmeasuredDepth = 1u << 0;

inline bool operator==(const PipelineState& a, const PipelineState& b) {
    // Field-wise, never memcmp: PipelineState has always contained padding
    // (4 u32 + 2 u8 before the next member) and two value-equal states could
    // compare unequal because of uninitialised bytes. D3D12_BLEND_DESC carries
    // its own tail padding for the same reason.
    for (uint32_t i = 0; i < kMaxRenderTargets; ++i)
        if (a.targetFormats[i] != b.targetFormats[i]) return false;
    if (a.depthStencilFormat != b.depthStencilFormat) return false;
    if (a.blendState != b.blendState) return false;
    if (a.rasterState != b.rasterState) return false;
    if (a.depthStencilState != b.depthStencilState) return false;
    if (a.topology != b.topology) return false;
    if (a.sampleCount != b.sampleCount) return false;
    // F-653: the geometry stage is key identity. Without this line a rectangle
    // draw and a triangle draw with identical shaders and raster state would
    // share one PSO, and whichever was cached first would silently serve the
    // other -- shearing every rectangle or leaving them unexpanded, with no
    // error from the driver.
    if (a.geometryStage != b.geometryStage) return false;
    if (a.derivation != b.derivation) return false;
    if (a.flags != b.flags) return false;

    // F-634: three names here did not exist in the platform SDK and broke every
    // translation unit that includes this header (d3d12_backend.h -> app.h ->
    // renderer_hook_dispatch.h -> gpu_device.cpp), i.e. the whole build. Fixed
    // against the real `d3d12.h` (Windows Kits 10.0.26100.0), not from memory:
    //  - `D3D12_RASTERIZER_DESC` has no `DepthBiasEnable`. Depth bias is three
    //    FLOATs (`DepthBias`, `DepthBiasClamp`, `SlopeScaledDepthBias`) plus the
    //    BOOL `DepthClipEnable`; all four are compared below/above. The invented
    //    field was also redundant, so it is gone rather than renamed.
    //  - `RenderTargetWriteMask` is a member of `D3D12_RENDER_TARGET_BLEND_DESC`,
    //    NOT of `D3D12_BLEND_DESC`. The per-target compare in the loop below
    //    already covers it, so the stray top-level compare is removed.
    //  - There is no `D3D12_COLOR_ATTACHMENT_COUNT`. The SDK name is
    //    `D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT` (= 8), and the header says so
    //    in a comment next to `RenderTarget[8]`.
    const D3D12_RASTERIZER_DESC& r0 = a.d3d12.raster;
    const D3D12_RASTERIZER_DESC& r1 = b.d3d12.raster;
    if (r0.FillMode != r1.FillMode || r0.CullMode != r1.CullMode ||
        r0.DepthClipEnable != r1.DepthClipEnable ||
        r0.FrontCounterClockwise != r1.FrontCounterClockwise ||
        r0.DepthBias != r1.DepthBias ||
        r0.DepthBiasClamp != r1.DepthBiasClamp ||
        r0.SlopeScaledDepthBias != r1.SlopeScaledDepthBias ||
        r0.ConservativeRaster != r1.ConservativeRaster)
        return false;

    const D3D12_BLEND_DESC& b0 = a.d3d12.blend;
    const D3D12_BLEND_DESC& b1 = b.d3d12.blend;
    if (b0.AlphaToCoverageEnable != b1.AlphaToCoverageEnable ||
        b0.IndependentBlendEnable != b1.IndependentBlendEnable)
        return false;
    for (UINT i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
        if (b0.RenderTarget[i].BlendEnable != b1.RenderTarget[i].BlendEnable ||
            b0.RenderTarget[i].LogicOpEnable != b1.RenderTarget[i].LogicOpEnable ||
            b0.RenderTarget[i].SrcBlend != b1.RenderTarget[i].SrcBlend ||
            b0.RenderTarget[i].DestBlend != b1.RenderTarget[i].DestBlend ||
            b0.RenderTarget[i].BlendOp != b1.RenderTarget[i].BlendOp ||
            b0.RenderTarget[i].SrcBlendAlpha != b1.RenderTarget[i].SrcBlendAlpha ||
            b0.RenderTarget[i].DestBlendAlpha != b1.RenderTarget[i].DestBlendAlpha ||
            b0.RenderTarget[i].BlendOpAlpha != b1.RenderTarget[i].BlendOpAlpha ||
            b0.RenderTarget[i].LogicOp != b1.RenderTarget[i].LogicOp ||
            b0.RenderTarget[i].RenderTargetWriteMask !=
                b1.RenderTarget[i].RenderTargetWriteMask)
            return false;

    const D3D12_DEPTH_STENCIL_DESC& d0 = a.d3d12.depthStencil;
    const D3D12_DEPTH_STENCIL_DESC& d1 = b.d3d12.depthStencil;
    return d0.DepthEnable == d1.DepthEnable &&
           d0.DepthWriteMask == d1.DepthWriteMask &&
           d0.DepthFunc == d1.DepthFunc &&
           d0.StencilEnable == d1.StencilEnable &&
           d0.StencilReadMask == d1.StencilReadMask &&
           d0.StencilWriteMask == d1.StencilWriteMask &&
           d0.FrontFace.StencilFailOp == d1.FrontFace.StencilFailOp &&
           d0.FrontFace.StencilDepthFailOp == d1.FrontFace.StencilDepthFailOp &&
           d0.FrontFace.StencilPassOp == d1.FrontFace.StencilPassOp &&
           d0.FrontFace.StencilFunc == d1.FrontFace.StencilFunc &&
           d0.BackFace.StencilFailOp == d1.BackFace.StencilFailOp &&
           d0.BackFace.StencilDepthFailOp == d1.BackFace.StencilDepthFailOp &&
           d0.BackFace.StencilPassOp == d1.BackFace.StencilPassOp &&
           d0.BackFace.StencilFunc == d1.BackFace.StencilFunc;
}

struct PipelineKey {
    uint64_t vsHash = 0;          // translated vertex shader program hash
    uint64_t psHash = 0;          // translated pixel shader program hash
    uint64_t vertexDeclHash = 0;  // hash of the grcFvf declaration
    uint64_t inputLayoutHash = 0; // hash of the D3D12_INPUT_ELEMENT_DESC array
    PipelineState state;
    // Non-zero => this key must never be compiled and never cached; see
    // PipelineRefusal. Computed by ComputePipelineKey, carried by the worker as
    // a second line of defence.
    uint32_t refuseMask = kRefuseNone;
    uint32_t reserved = 0;        // keeps the struct 8-byte aligned for the map
};

inline bool operator==(const PipelineKey& a, const PipelineKey& b) {
    return a.vsHash == b.vsHash && a.psHash == b.psHash &&
           a.vertexDeclHash == b.vertexDeclHash &&
           a.inputLayoutHash == b.inputLayoutHash && a.state == b.state &&
           a.refuseMask == b.refuseMask;
}

struct PipelineKeyHash {
    std::size_t operator()(const PipelineKey& k) const noexcept;
};

// Guest registers the renderer actually captured, plus the native targets the
// PSO will be used with. DerivePipelineState is the ONLY way to turn this into
// a PipelineState; a zero-initialised PipelineState is refused so that "nobody
// derived this" can never be mistaken for "the defaults were fine".
struct PipelineStateInputs {
    uint32_t paClipCntl = 0;      // DrawPacket.paClipCntl
    uint32_t paSuScModeCntl = 0;  // DrawPacket.paSuScModeCntl
    uint32_t paClVteCntl = 0;     // DrawPacket.paClVteCntl
    uint32_t colorFormats[kMaxRenderTargets] = {};
    uint32_t depthStencilFormat = 0;
    // XENOS prim type, value space = xenos::PrimitiveType
    // (.research/xenia/src/xenia/gpu/xenos.h, `enum class PrimitiveType`:
    // kNone=0x00, kPointList=0x01 .. kPolygon=0x0F, >=0x10 explicit major mode /
    // 2D / tessellation). DerivePipelineState maps it against that enum and
    // refuses the values D3D12 cannot express (F-645).
    //
    // The field this arrives in, DrawPacket::primType, is documented by its only
    // writer as `ctx.r4.u32 & 7` (capture_hooks.cpp, `OnDrawBuild`) while
    // trace_types.h calls it "0=TriList, 1=TriStrip"; neither matches the Xenos
    // enum. Treated as a HYPOTHESIS, not a fact: F-645's comment in
    // pipeline_cache.cpp spells out how a soak settles it.
    uint8_t primType = 0;
    bool haveRegisters = false;   // false => kRefuseStateNotDerived
    // F-646: which of paSuScModeCntl / paClipCntl / paClVteCntl are the guest's
    // (GuestRegisterPresent). A cleared bit is a REFUSAL with its own name, never
    // a zero to decode: the measured value in build/w658.log was
    // 0x2205=0x00010000, 0x2204=0x00010000, 0x2206=0x00000300, and a packet
    // carrying 0/0/0 with no presence bits would silently build a different, and
    // also legal, rasteriser. Callers that only have the MclaGpuContext copies
    // (capture_hooks.cpp:103-105) must NOT claim presence for the CP register
    // file until the producer is actually wired -- see kGuestRegNone.
    uint32_t registersPresent = kGuestRegNone;
    // --- D1: the polygon/depth-bias magnitudes, as HOST floats -------------
    // These four are the Xenos kFloat registers 0x2380-0x2383 (see the constants
    // above). The producer is responsible for the guest-endianness conversion
    // before storing them, exactly as for the dword registers above -- this
    // struct holds host numbers, and nothing here reads a guest pointer.
    //
    // The pair that is actually used is selected by the reference's rule
    // (draw_util.cc:93-121), reproduced in DerivePipelineState: FRONT when
    // poly_offset_front_enable && !cull_front, else BACK when
    // poly_offset_back_enable && !cull_back, and for NON-polygonal primitives
    // FRONT gated on poly_offset_para_enable instead.
    float polyOffsetFrontScale  = 0.0f;  // 0x2380  (slope scale, 1/16 subpixels)
    float polyOffsetFrontOffset = 0.0f;  // 0x2381  (absolute depth offset)
    float polyOffsetBackScale   = 0.0f;  // 0x2382
    float polyOffsetBackOffset  = 0.0f;  // 0x2383
    // RB_DEPTH_INFO.depth_format, ONE bit at +16 (registers.h:844):
    // 0 = kD24S8 (fixed-point), 1 = kD24FS8 (float24) -- xenos.h:367-371.
    // It is the ONLY thing this module wants from RB_DEPTH_INFO, and only to
    // pick the conversion factor. Read it only when kGuestRegDepthInfo is set.
    uint32_t depthFormat = 0;
    // Viewport extents in pixels, from the render target the guest told the
    // pipeline about. F-646: PA_CL_VTE_CNTL tells us WHICH of the six
    // vport_*_ena bits are set, but the extents themselves are a different
    // register pair (and the packet already carries the guest's rbSurfaceInfo
    // corners as viewportTL/viewportBR). With the enables clear and the extents
    // unknown, "apply an identity viewport" is a GUESS that renders correctly
    // only when the render target happens to match; it is refused instead.
    uint32_t viewportWidth = 0;
    uint32_t viewportHeight = 0;
    // Set when the caller needs ztest/stencil to be MEASURED. The captured
    // packet carries paClVteCntl but not RB_DEPTHCONTROL, which is where the
    // Xenos ztest lives (z_enable bit 1, z_write_enable bit 2, zfunc bits 4-6,
    // backface_enable bit 7 -- registers.h:802-808; the reference reads it at
    // draw_util.cc:76), so the honest answer today is the documented
    // always-pass/no-write placeholder (kStateFlagUnmeasuredDepth) -- refuse
    // outright only when the caller says it cannot tolerate that.
    //
    // (This comment previously said the ztest lived in RB_DEPTH_INFO. It does
    // not: RB_DEPTH_INFO holds the EDRAM tile base and the depth FORMAT, and
    // carries no enable, no write bit and no compare function.)
    bool requireMeasuredDepthState = false;
};

// The decoded render state, with every field traceable to one Xenia register
// bit. Exists so there is exactly ONE owner of these bit layouts: DerivePipeline-
// State and any validator both go through DecodeGuestRenderState, so a layout
// cannot be right in the derivation and wrong in a test (or vice versa).
struct DecodedXenosRenderState {
    // --- PA_SU_SC_MODE_CNTL (0x2205) --------------------------------------
    bool suPresent = false;
    bool cullFront = false;        // cull_front       +0  registers.h:459
    bool cullBack = false;         // cull_back        +1  registers.h:460
    bool frontIsCw = false;        // face             +2  registers.h:462 (0 = CCW)
    uint32_t polyMode = 0;         // poly_mode        +3  registers.h:467 (xenos.h:846)
    uint32_t polyFrontType = 0;    // polymode_front_ptype +5  registers.h:468
    uint32_t polyBackType = 0;     // polymode_back_ptype  +8  registers.h:469
    bool polyOffsetFrontEn = false;// +11 registers.h:470
    bool polyOffsetBackEn = false; // +12 registers.h:471
    bool polyOffsetParaEn = false; // +13 registers.h:472
    bool msaaEnable = false;       // msaa_enable      +15 registers.h:474
    bool vtxWindowOffsetEn = false;// +16 registers.h:475
    // --- D2: these five used to be unnamed bits inside a `rest : 15` pad -----
    // Named deliberately even though nothing reads them yet: `provokingVtxLast`
    // in particular changes which vertex supplies the provoking attribute, so
    // a reader who "optimises" them back into a pad is discarding a fact about
    // the rasterised image. Decoded so the values are readable and countable.
    bool provokingVtxLast = false;// +19 registers.h:478
    bool perspCorrDis = false;     // +20 registers.h:479
    bool multiPrimIbEna = false;   // +21 registers.h:480
    bool quadOrderEnable = false;  // +23 registers.h:482
    bool scOneQuadPerClock = false;// +24 registers.h:483

    // --- D1: the polygon/depth-bias request -------------------------------
    // True when the guest asked for a bias at all (bits 11-13 are set). The
    // MAGNITUDES are not here: they live in the four kFloat registers
    // 0x2380-0x2383, which arrive on PipelineStateInputs and are either
    // converted into D3D12's integer DepthBias, or their absence is a refusal.
    bool polyOffsetRequested = false;

    // --- PA_CL_CLIP_CNTL (0x2204) -----------------------------------------
    bool clPresent = false;
    uint32_t ucpEnaMask = 0;       // ucp_ena_0..5     +0..+5 registers.h:539-544
    uint32_t psUcpMode = 0;        // ps_ucp_mode      +14 registers.h:546
    bool clipDisable = false;      // clip_disable     +16 registers.h:547
    bool ucpCullOnly = false;      // +17 registers.h:548

    // --- PA_CL_VTE_CNTL (0x2206) ------------------------------------------
    bool vtePresent = false;
    bool vportXScaleEn = false;    // vport_x_scale_ena  +0 registers.h:569
    bool vportXOffsetEn = false;   // vport_x_offset_ena +1 registers.h:570
    bool vportYScaleEn = false;    // vport_y_scale_ena  +2 registers.h:571
    bool vportYOffsetEn = false;   // vport_y_offset_ena +3 registers.h:572
    bool vportZScaleEn = false;    // vport_z_scale_ena  +4 registers.h:573
    bool vportZOffsetEn = false;   // vport_z_offset_ena +5 registers.h:574
    // F-646: True iff at least one of the six enables is set, i.e. the hardware
    // applies a viewport transform and the host must reproduce its extents. False
    // with all six clear is the D3D9-style case where the transform is baked
    // into the vertex shader and the host viewport must be pass-through -- which
    // is the measured state (0x00000300 sets only vtx_xy_fmt/vtx_z_fmt, bits 8-9,
    // and leaves every vport_*_ena clear).
    bool vportTransformApplied = false;
    // vtx_xy_fmt +8 / vtx_z_fmt +9 / vtx_w0_fmt +10 (registers.h:576-578). These
    // select the vertex output FORMAT the VTE produces, not a D3D12 concept; they
    // are decoded for the log only and never mapped.
    uint8_t vtxXyFmt = 0, vtxZFmt = 0, vtxW0Fmt = 0;
};

// Decodes the three registers named in `in.registersPresent`. Every register
// whose bit is CLEAR leaves its section zeroed AND contributes its own refusal
// bit, so a caller cannot mistake "arrived and was zero" for "never arrived".
// This function never reads a guest pointer and never asserts on a guest value;
// it decodes host bytes the producer has already validated.
DecodedXenosRenderState DecodeGuestRenderState(const PipelineStateInputs& in,
                                                uint32_t& refuseMask);

// Derives the pipeline state the backend will actually build, from the same
// guest registers for every caller, and fills `refuseMask` with anything it
// could not derive honestly. Bit layouts cited from the local Xenia checkout:
// PA_SU_SC_MODE_CNTL .research/xenia/src/xenia/gpu/registers.h:456-489,
// PA_CL_CLIP_CNTL registers.h:534-563, PA_CL_VTE_CNTL registers.h:566-584.
// Register INDICES: .research/xenia/src/xenia/gpu/register_table.inc:540-542.
// F-646: self-check for the three overlays above, against the values the guest
// actually wrote (build/w658.log: r2204=0x00010000, r2205=0x00010000,
// r2206=0x00000300). Returns false if any field lands at the wrong bit.
//
// This is a RUNTIME check, not a static_assert, and that is a measured limit of
// the toolchain rather than a shortcut: clang-cl rejects all three constexpr
// routes to inspect a bitfield's positions ("cannot constant evaluate 'memcpy'
// ... to object of type 'SuScModeCntl'", "constexpr bit_cast involving bit-field
// is not yet supported", and "read of member of union with active member is not
// allowed in a constant expression"). The compile-time half of the guard is the
// unconditional `static_assert(sizeof(...) == 4)` on each overlay, which does
// catch a width error. Callers should call this once and treat false as fatal.
bool VerifyXenosRenderStateLayouts();

PipelineState DerivePipelineState(const PipelineStateInputs& in, uint32_t& refuseMask);

// Derives the state for a caller that already holds native D3D12 state (no
// guest registers to map). Used by offline harnesses; still stamps
// kStateDerivedExplicit so the key is identifiable.
void SetDerivedPipelineState(PipelineState& state);

// Build a pipeline key from its inputs. `vertexDeclHash` is a caller-computed
// hash of the vertex stream layout (see vertex_decode in Phase 3); `state` must
// carry a derivation != kStateDerivedNone, otherwise the key refuses itself.
PipelineKey ComputePipelineKey(uint64_t vsHash, uint64_t psHash,
                               uint64_t vertexDeclHash, const PipelineState& state);

// Same, but also folds in the hash of the input layout the worker will use, so
// the key cannot claim one vertex declaration and hand the PSO another.
PipelineKey ComputePipelineKeyForLayout(uint64_t vsHash, uint64_t psHash,
                                        uint64_t vertexDeclHash,
                                        const PipelineState& state,
                                        const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout);

// Deterministic 64-bit hash of a PipelineKey (for debug/trace reporting).
uint64_t HashPipelineKey(const PipelineKey& key);

// Compute a stable 64-bit hash from shader bytecode (HLSL source or DXIL blob).
uint64_t HashShaderBytecode(const std::vector<uint8_t>& bytecode);
uint64_t HashShaderBytecode(const std::string& hlsl);

// ---------------------------------------------------------------------------
// Authoritative vertex-input layout (the single owner of lane->semantic)
// ---------------------------------------------------------------------------
// grc_fvf_decode.h is the authoritative mapping: lanes 0-17, 4/5 = Colour0/1,
// 6-13 = TexCoord0-7, 14/15 = Tangent0/1, 16/17 = Binormal0/1, and codes
// 2/4/11-15 (plus a bound lane >= 16) are UNKNOWN -> refuse. This function only
// orders by byteOffset and converts; it never re-decodes a type code.
//
// Why this exists: D3D12Backend::BuildInputLayoutFromGrcFvf (d3d12_backend.cpp:
// 2204-2304) re-implemented the mapping with LANE-INDEX semantics (lane 5 ->
// TEXCOORD0, lane 13 -> TANGENT0), accepted all 16 type codes including the
// unverified ones, dropped lanes 16-17, and used D3D12_APPEND_ALIGNED for
// every element while the render thread hashed with DecodeGrcFvf/HashGrcFvf
// Declaration. Hash and layout could therefore disagree, and a VS expecting
// COLOR0 could be fed lane 5 as TEXCOORD0.
//
// Returns false (and leaves `out` empty) when the declaration must not be
// laid out at all: invalid, unknownChannel, or a declared fvfSize that disagrees
// with the computed stride. `outDeclHash` receives HashGrcFvfDeclaration(decl)
// so the caller hashes the SAME declaration it laid out.
bool BuildGrcFvfInputLayout(const native::GrcFvfDeclaration& decl,
                            std::vector<D3D12_INPUT_ELEMENT_DESC>& out,
                            uint64_t* outDeclHash = nullptr);

// Convenience overload that decodes `raw` first. Inline on purpose: it calls
// DecodeGrcFvf, and pipeline_cache.cpp is linked into the offline validators
// (CMakeLists.txt:414-421) that do NOT link grc_fvf_decode.cpp. Declaring it
// here keeps that link edge with the callers that actually need it (the mcla
// target does link it, CMakeLists.txt:163).
inline bool BuildGrcFvfInputLayout(const native::GrcFvfDesc& raw,
                                   std::vector<D3D12_INPUT_ELEMENT_DESC>& out,
                                   uint64_t* outDeclHash = nullptr) {
    return BuildGrcFvfInputLayout(native::DecodeGrcFvf(raw), out, outDeclHash);
}

// Stable hash of an input layout array (semantic name + index + format +
// offset + slot + class + step rate). The same function feeds
// PipelineKey::inputLayoutHash, so layout and key can never drift apart.
uint64_t HashInputLayout(const std::vector<D3D12_INPUT_ELEMENT_DESC>& layout);

// ---------------------------------------------------------------------------
// Xenos constant bank (sqVsConst / sqPsConst)
// ---------------------------------------------------------------------------
// A slot of the shared root signature for one reflected CBV. rootParameter is
// the D3D12 root parameter index the draw must bind; for the generated HLSL's
// `ShaderConstants : register(b0)` under CreateTestRootSignature that is 2
// (F-644: root params are 0 = t0..t3 SRV table, 1 = the s0 SAMPLER table, 2 =
// the b0 CBV; the CBV was 1 while the sampler was a D3D12_STATIC_SAMPLER_DESC).
// Anything else must report valid == 0 rather than name a parameter that does
// not exist.
struct ConstantBankBinding {
    uint32_t shaderRegister = 0;
    uint32_t space = 0;
    uint32_t requiredBytes = 0;   // from shader reflection
    uint32_t rootParameter = 0;   // D3D12 root parameter index
    uint32_t valid = 0;
};

// Result of packing one guest constant bank.
struct ConstantBankPack {
    uint32_t registersPacked = 0;   // 16-byte Xenos float4 registers converted
    uint32_t zeroFilledBytes = 0;   // tail past the guest bank, zero-filled
    uint32_t guestBytes = 0;        // bytes actually present in the guest bank
    bool truncated = false;         // guest bank exceeded the native bank
    bool ok = false;
};

// Unpacks `guestBytes` of big-endian Xenos float4 registers (the layout
// SQ_VS_CONST / SQ_PS_CONST point at) into a native little-endian bank of
// kShaderConstantBankBytes. Guest pointers are 32-bit VAs read with explicit
// endianness; this helper is the only place that endian swap happens, and it
// never reinterpret_casts guest data.
//
// Short banks are zero-filled and the shortfall is reported in
// ConstantBankPack::zeroFilledBytes -- the caller logs it, because "the shader
// read zeros" and "the shader read the right constants" are not the same
// claim.
ConstantBankPack PackXenosConstantBank(const uint8_t* guestBeBytes, size_t guestBytes,
                                       uint8_t* dstBank, size_t dstBytes);

// Maps a reflected CBV to its root parameter in the shared root signature.
// Returns a ConstantBankBinding with valid == 0 when the register/space is not
// in the root signature, so the caller can refuse instead of binding garbage.
ConstantBankBinding ResolveConstantBankBinding(const DxcRuntime::CbvBinding& cbv);

// ---------------------------------------------------------------------------
// F-653: the rectangle-list geometry stage
// ---------------------------------------------------------------------------
// The D3D12 geometry shader model. Deliberately NOT DxcRuntime::kVertexProfile
// ("vs_6_0", dxc_runtime.h:44) and not kPixelProfile ("ps_6_0",
// dxc_runtime.h:45): a geometry stage is its own profile, "gs_6_0", and handing
// dxc a vertex profile for a shader that declares `maxvertexcount` produces a
// compile error rather than a geometry shader. It is the same 6.0 family the
// other two stages already use, which is what makes the stage legal on the
// feature level this backend requests (D3D_FEATURE_LEVEL_11_0,
// d3d12_backend.cpp:520).
constexpr const char* kGeometryProfile = "gs_6_0";

// Builds the geometry stage that expands a Xenos rectangle list, as HLSL.
//
// WHY IT IS BUILT HERE AND NOT BY THE CALLER: the stage's INPUT signature is
// not a choice, it is dictated by the vertex shader it is paired with. The
// translated guest VS writes `out float4 oPos : SV_Position` plus one
// `oTexCoord<n> : TEXCOORD<n>` per exported interpolator
// (src/renderer/shader_translator.cpp:676-681), so the stage must read exactly
// those semantics and emit exactly those, or the D3D12 pipeline will not link
// the VS to the stage or the stage to the PS. The set is per-program, and the
// only description of it that reaches this module is the translated VS source
// the caller already passes to GetOrCompile. So the stage is derived from that
// source here, where the worker already holds it, rather than by a caller that
// does not own the translator.
//
// `vsHlsl` is the TRANSLATED VERTEX SHADER TEXT, and it is parsed, not trusted:
// the output-signature lines are matched exactly and anything unexpected is a
// refusal (kRefuseGeometryShaderUnbuildable) with an empty return. There is no
// fallback signature, because a stage that guessed its interpolator set would
// link to the PS or fail to, with no error either way.
//
// The rule itself, and every term in it, is cited file:line in the definition
// (pipeline_cache.cpp, BuildRectangleGeometryShaderHlsl).
std::string BuildRectangleGeometryShaderHlsl(std::string_view vsHlsl,
                                             const char* caller);

// F-653: how many times a key has been DERIVED asking for the rectangle
// expansion stage, i.e. how many rectangle draws the guest has offered. This is
// the denominator for geomStageCreated: offers > 0 with geomStageCreated == 0
// is a black rectangle area. Read it beside PipelineCache::Stats() -- a single
// "one line" is `offers / created / refused`, and a soak should print both.
uint32_t RectangleDrawsOffered();

// ---------------------------------------------------------------------------
// Cache
// ---------------------------------------------------------------------------
// Async compilation task for background PSO creation. The worker thread owns
// the DXC runtime, compiles the HLSL source to DXIL, and creates the PSO; the
// calling thread only queues the task and returns the fallback PSO.
struct CompileTask {
    PipelineKey key;
    std::string vsHlsl;
    std::string psHlsl;
    std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
    // Reflected CBV slots, kept so the draw path can bind a real constant bank
    // for this PSO without re-reflecting (item 7).
    std::vector<ConstantBankBinding> cbvBindings;
    std::promise<Microsoft::WRL::ComPtr<ID3D12PipelineState>> promise;
};

// Counters for the bounded refusal/saturation reporting. All fields are
// process-lifetime totals; snapshot them with PipelineCache::Stats().
struct PipelineCacheStats {
    uint32_t lookups = 0;
    uint32_t hits = 0;
    uint32_t misses = 0;
    uint32_t queued = 0;
    uint32_t inFlightDuplicate = 0;   // key already compiling, fallback returned
    uint32_t refusals = 0;            // GetOrCompile returned nullptr on purpose
    uint32_t refusalsByReason[32] = {};  // indexed by bit in PipelineRefusal
    uint32_t saturated = 0;           // kMaxInflight reached -> refused
    uint32_t compileFailures = 0;     // DXC or CreateGraphicsPipelineState failed
    uint32_t dxcUnavailable = 0;      // DXC DLLs never loaded
    uint32_t nullInsertRejected = 0;  // Insert(key, nullptr) refused
    uint32_t unmeasuredDepthState = 0;// PSOs built on the depth placeholder
    uint32_t viewportUnresolved = 0;  // F-646: VTE transform on, extents absent
    uint32_t missingRegisters = 0;    // F-646: draws refused for an absent register
    // D1: draws refused because a depth-bias magnitude (0x2380-0x2383) or
    // RB_DEPTH_INFO.depth_format (0x2002) was not captured. Separate from
    // `missingRegisters` because the reason is a MISSING MAGNITUDE, not a
    // missing rasteriser register, and a soak gate should read them apart.
    uint32_t polyOffsetUnresolved = 0;
    // ---- F-653: the rectangle-list geometry stage -------------------------
    // Read these four APART. "The stage was never created" and "the stage was
    // created but never ran" differ by nothing observable on screen -- both are
    // a black rectangle area -- so a soak that only counts offers cannot tell a
    // device without geometry shaders from a draw path that never bound one.
    //   rectangleDrawsOffered  -- keys built asking for kGeomStageRectangleList
    //                             (i.e. the guest really does draw rectangles).
    //                             Counted in DerivePipelineState, which is a free
    //                             function with no cache to own a counter, so it
    //                             is read through RectangleDrawsOffered() rather
    //                             than from this struct -- a field here would
    //                             always read 0 and a soak could not tell that
    //                             from "no rectangles were ever offered".
    //   geomStageCreated       -- a PSO was created WITH pGeometryShader set.
    //   geomStageCompileFailed -- the stage's HLSL did not compile, or the PSO
    //                             carrying it was rejected by the runtime.
    //   geomStageUnbuildable   -- the stage HLSL could not be derived from the
    //                             translated VS output signature.
    // geomStageCreated == 0 with rectangleDrawsOffered > 0 is the black screen.
    uint32_t rectangleDrawsOffered = 0;
    uint32_t geomStageCreated = 0;
    uint32_t geomStageCompileFailed = 0;
    uint32_t geomStageUnbuildable = 0;
    // F-716: geometry-stage keys whose PSO GetOrCompile WAITED for instead of
    // returning the GS-less fallback. `geomStageWaited` counts waits that ended
    // with the real PSO (and therefore with the carried flag TRUE); a wait that
    // ended in a refusal or a timeout is in `geomStageWaitFailed` and NOT in
    // `geomStageWaited`, so the two cannot be conflated.
    uint32_t geomStageWaited = 0;
    uint32_t geomStageWaitFailed = 0;
    uint32_t size = 0;    uint32_t inflight = 0;
};
// F-646: a new reason bit above 1u<<kPipelineRefusalBitCount would index past
// refusalsByReason[] and corrupt an unrelated counter. Checked unconditionally
// in every translation unit that includes this header, so the enum and the array
// cannot drift apart.
static_assert(kPipelineRefusalBitCount <= 32u,
              "PipelineRefusal grew past PipelineCacheStats::refusalsByReason[32]");

// Bounded in-memory pipeline cache: key -> ID3D12PipelineState, with async
// compilation queue and fallback PSO for cache misses.
class PipelineCache {
public:
    explicit PipelineCache(std::size_t maxEntries = 4096);
    ~PipelineCache();

    // Start the background compilation worker thread. The worker lazily loads
    // its own DXC runtime on the first task. Must be called exactly once; a
    // second call after StopWorker is a no-op (the joined thread is not reset).
    //
    // `rootSignature` MUST be the root signature the command list will bind at
    // draw time. The worker uses it verbatim for CreateGraphicsPipelineState
    // and refuses (kRefuseNoRootSignature) when it is null, instead of
    // building a private one: a PSO created against a root signature nobody
    // binds is a PSO whose descriptor tables do not exist at draw time.
    void StartWorker(Microsoft::WRL::ComPtr<ID3D12Device> device,
                     Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature);

    // Stop the worker thread.
    void StopWorker();

    // Get or create a pipeline for the given key. `caller` is a short
    // "file:line" string for the refusal log (see the GetOrCompile overload
    // below for the default). Returns null -- deliberately, never the fallback
    // -- when the request cannot be honoured honestly:
    //   * key.refuseMask != 0                  (kRefuseStateNotDerived, ...)
    //   * vsHlsl or psHlsl is empty            (kRefuseEmptyHlsl)
    //   * inputLayout is empty                 (kRefuseEmptyInputLayout)
    //   * no device / no root signature        (kRefuseNoDevice/NoRootSignature)
    //   * kMaxInflight reached                 (saturated, counted)
    // A null return is NOT cached: the draw keeps whatever the caller had
    // (the backend's test PSO) and the reason is on the log. The fallback PSO is
    // returned only for a genuine miss whose compile is in flight.
    //
    // `outCarriesGeometryStage` (optional) is the CARRIED geometry-stage
    // capability, and it exists because the alternative is worse than a refusal.
    //
    // WHY IT CANNOT BE QUERIED. D3D12 offers no way to ask a PSO for its
    // geometry shader: ID3D12PipelineState has exactly one pipeline method,
    // GetCachedBlob, and GetGeometryShader is a D3D10-era interface that never
    // reached D3D12. So a caller holding a PSO cannot find out whether a stage
    // is bound to it. What it CAN know is which KEY produced it, and the key
    // carries the geometry stage as identity (PipelineState::geometryStage, in
    // the == operator above), so the answer is derivable here and nowhere else.
    //
    // WHY IT MUST NOT BE A DEVICE FLAG. GetOrCompile returns the GS-LESS
    // FALLBACK PSO on a genuine cache miss while the worker compiles (see
    // above). A caller that gated a rectangle draw on `GeometryStageSupported()`
    // -- the device capability, which the log shows as TRUE, F-653 -- would then
    // map prim_type 0x08 to TRIANGLELIST and issue a three-vertex draw against
    // a pipeline with no expansion stage: one of the rectangle's two triangles,
    // with nothing in the log saying anything was dropped. That is the F-609
    // fake this parameter exists to make impossible. So the rule is one-way:
    //   * cache HIT on a key that named a geometry stage -> the returned PSO is
    //     the one the worker built WITH pGeometryShader set (pipeline_cache.cpp
    //     :1716-1718), and no other code path inserts such a key -> true;
    //   * cache MISS (the fallback) -> the fallback carries no stage -> FALSE,
    //     unconditionally, whatever the device supports;
    //   * any refusal / null return -> false.
    // It is an OUT parameter, not a second mechanism, and it is initialised to
    // false on entry so a caller that ignores it is unaffected.
    //
    // F-716 -- THE RULE IS NOW: "the returned PSO carries the stage", NOT "there
    // was a cache hit". Those are different claims, and only the second one was
    // wrong. Measured on build/w695.log (sha256 84FB1AB3...A61CB0C): the two
    // rectangle draws were COLD MISSES (PC-TRANSLATE ran at 02:17:08.018, AFTER
    // both DRAW-CP-REFUSE lines at 02:17:08.008), so the hit-only rule left
    // `pipeHasGeomStage` false on the one and only draw of the pipeline and the
    // gate refused it. The flag was not conservative, it was permanently false
    // for a pipeline seen for the first time.
    //
    // So a MISS on a key whose state names a geometry stage now WAITS for its own
    // compile (bounded by kGeomStageWaitTimeoutMs) and returns the PSO the
    // worker built, with the flag set from what that PSO demonstrably is:
    //   * the worker bound pGeometryShader exactly when the key named a stage,
    //     from a blob DXC compiled (pipeline_cache.cpp:1870-1872, :1835), and
    //     no other code path inserts such a key -> true on success;
    //   * the worker refused (or the wait timed out, or the worker is gone) ->
    //     the fallback carries no stage -> false, and for a geometry-stage key
    //     the return is NULL rather than the fallback, because returning a
    //     GS-less PSO to a caller about to map 0x08 is the F-609 fake;
    //   * every other key (no geometry stage) behaves EXACTLY as before: a miss
    //     returns the fallback immediately with no wait at all, so this changes
    //     nothing for triangle/line/point draws.
    Microsoft::WRL::ComPtr<ID3D12PipelineState> GetOrCompile(
        const PipelineKey& key,
        const std::string& vsHlsl,
        const std::string& psHlsl,
        const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
        const char* caller = "pipeline_cache.h:undefined",
        bool* outCarriesGeometryStage = nullptr);

    // Set the fallback PSO used for cache misses while async compilation runs.
    void SetFallbackPipeline(Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback);

    // F-653: tell the cache what the DEVICE MEASURED, so the rectangle refusal
    // is driven by the measurement rather than only logged next to it.
    //
    // D3D12Backend calls this once, immediately after device creation, with the
    // result of ID3D12Device::GetFeatureLevel() (d3d12_backend.cpp, the
    // F-653 block in CreateDevice). A geometry stage requires feature level
    // 11_0; below that, every rectangle draw refuses with
    // kRefuseGeometryStageUnsupported instead of being compiled into a PSO the
    // runtime would reject -- or worse, accepted without a stage.
    //
    // The initial value is FALSE, not true. An un-told cache refuses rectangles,
    // because "nobody has confirmed this device can do it" and "it can" are
    // different claims and only one of them is safe to act on. The backend always
    // sets it, so this default is a fail-safe rather than a live path.
    void SetGeometryStageSupported(bool supported) { geometryStageSupported_ = supported; }
    bool GeometryStageSupported() const { return geometryStageSupported_; }

    // Returns true + fills `pso` if the key is present in the cache.
    bool Find(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState>& pso) const;

    // Insert a compiled PSO into the cache (called by the worker thread).
    // A null `pso` is REJECTED and counted: caching a failure makes every later
    // lookup of that key report a hit on nothing.
    void Insert(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState> pso);

    PipelineCacheStats Stats() const;

    std::size_t Size() const {
        std::lock_guard<std::mutex> lock(mapMutex_);
        return map_.size();
    }
    void Clear();

    // The layout + CBV slots the most recent successful compile registered, for
    // the draw path to bind. Empty until a PSO exists. Diagnostic/census only.
    std::vector<ConstantBankBinding> ConstantBindingsFor(const PipelineKey& key) const;

private:
    // Worker thread function.
    void WorkerLoop(Microsoft::WRL::ComPtr<ID3D12Device> device,
                    Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature);

    // F-716: the geometry-stage wait. `fut` is the task's promise for `key` (the
    // caller's own task, or one an earlier draw already queued). Returns the
    // fallback untouched for a key with no geometry stage -- that is the whole of
    // the old behaviour for every non-rectangle draw. For a key that names a
    // stage it returns the PSO the worker built and sets
    // *outCarriesGeometryStage, or nullptr when no stage-carrying PSO could be
    // had (worker refusal, timeout, or worker gone) -- never the fallback, which
    // carries no stage. Blocks the calling thread; see kGeomStageWaitTimeoutMs.
    Microsoft::WRL::ComPtr<ID3D12PipelineState> WaitForGeomStagePso(
        const PipelineKey& key, const char* caller,
        const Microsoft::WRL::ComPtr<ID3D12PipelineState>& fallback,
        const std::shared_future<Microsoft::WRL::ComPtr<ID3D12PipelineState>>& fut,
        bool* outCarriesGeometryStage);

    // One log line per distinct (reason, key) pair, plus a total, so a refusal
    // can never flood a soak. Returns true when it actually printed.
    bool RefuseOnce(const PipelineKey& key, uint32_t reason, const char* caller,
                    const char* detail);

    std::size_t maxEntries_;
    // Hard cap on compile tasks queued/in flight. Under render-state key churn
    // (per-draw raster state) unique keys could exceed maxEntries_, so this
    // bounds pendingKeys_/taskQueue_ memory; overflow is a counted refusal, not
    // a silent fallback.
    static constexpr std::size_t kMaxInflight = 256;

    // F-716: how long GetOrCompile will block for the PSO of a geometry-stage
    // key it just queued. Every worker path fulfils the task's promise, so a
    // wait is bounded by one VS + PS + GS compile plus CreateGraphicsPipelineState;
    // this is a backstop against a wedged DXC, not the expected cost. On expiry
    // the draw takes the SAME path it took before this parameter existed --
    // fallback returned, carried flag false, rectangle refused -- so the
    // timeout can only lose latency, never correctness.
    static constexpr long kGeomStageWaitTimeoutMs = 2000;
    std::vector<PipelineKey> order_;
    std::unordered_map<PipelineKey, Microsoft::WRL::ComPtr<ID3D12PipelineState>, PipelineKeyHash> map_;
    mutable std::mutex mapMutex_;

    // F-634: `mutable` for the same reason `mapMutex_` is (`:487`). `Stats()` is a
// const reader that locks both mutexes to report sizes; without `mutable` the
// member is a `const std::mutex` in that context and `std::lock_guard` has no
// matching constructor -- which is exactly the error this replaced.
mutable std::mutex queueMutex_;
    std::condition_variable queueCv_;
    std::queue<CompileTask> taskQueue_;
    bool stopWorker_ = false;
    std::thread workerThread_;

    Microsoft::WRL::ComPtr<ID3D12Device> device_;
    Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature_;

    Microsoft::WRL::ComPtr<ID3D12PipelineState> fallbackPso_;
    std::mutex fallbackMutex_;

    // PipelineKeys with a compile task queued or in flight. Prevents duplicate
    // background compiles for the same key (bounded by the unique shader-pair
    // count). Guarded by queueMutex_.
    std::unordered_set<PipelineKey, PipelineKeyHash> pendingKeys_;

    // F-716: CompileTask::promise already existed and was set on EVERY worker
    // path (pipeline_cache.cpp:1714/1728/1907/1935/2007/2035 and failTask),
    // but nothing in src/ ever called get_future -- measured 2026-10-02,
    // `grep get_future|shared_future|std::future src/` = 0 hits. So the worker
    // was announcing completion to nobody.
    //
    // WHY THAT MATTERS FOR THE FIRST PIXEL: on a cache MISS the worker is still
    // compiling, so GetOrCompile returned the GS-LESS fallback and
    // outCarriesGeometryStage stayed false -- see the rule in GetOrCompile's
    // comment. The draw therefore went to MapXenosPrimType(0x08, has=false)
    // and was refused on the FIRST draw of every rectangle pipeline, which is
    // the only draw the game issues in build/w695.log. A flag that is false
    // exactly when it is needed is the bug; the promise is the fix.
    //
    // This map hands the task's future to whichever thread asked for the key, so
    // a geometry-stage key can WAIT for its own PSO instead of drawing against
    // the fallback. Guarded by inflightMutex_, which is a LEAF: nothing is
    // acquired while it is held, so it cannot form a cycle with mapMutex_ or
    // queueMutex_. The entry is erased by the worker when the task completes.
    std::unordered_map<PipelineKey,
                       std::shared_future<Microsoft::WRL::ComPtr<ID3D12PipelineState>>,
                       PipelineKeyHash> inflightFutures_;
    mutable std::mutex inflightMutex_;

    // F-716: whether the worker thread is still running. Written by the worker
    // itself under queueMutex_ (set on entry, cleared immediately before it
    // returns). A waiter MUST consult this before blocking: if the worker has
    // already exited, no task will ever be fulfilled and waiting would hang the
    // render thread forever. Reading std::thread::joinable() instead would race
    // StopWorker's join(); this flag cannot, because both writers and the reader
    // hold queueMutex_.
    bool workerAlive_ = false;

    // Key -> reflected CBV slots, populated by the worker. Guarded by mapMutex_.
    std::unordered_map<PipelineKey, std::vector<ConstantBankBinding>, PipelineKeyHash> cbvBindings_;

    // Refusal log throttle + counters. refusedKeys_ is bounded by
    // kMaxInflight*2 so a key-churning soak cannot grow it without limit.
    std::unordered_set<PipelineKey, PipelineKeyHash> refusedKeys_;
    mutable std::mutex statsMutex_;
    PipelineCacheStats stats_;
    // F-653: what the device measured. Written once at device creation, before
    // the worker starts, and only read afterwards -- so it needs no lock of its
    // own. See SetGeometryStageSupported.
    bool geometryStageSupported_ = false;
    static constexpr std::size_t kMaxRefusalKeys = 512;
};

} // namespace mcla::renderer
