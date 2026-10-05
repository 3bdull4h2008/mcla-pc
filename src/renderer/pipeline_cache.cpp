#include "pipeline_cache.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <d3d12.h>
#include <atomic>
#include "common/logging.h"
#include "dxc_runtime.h"
#include "texture_decode.h"
// NOTE: d3d12_backend.h is deliberately NOT included. It is needed for nothing
// here any more, and the offline validator targets (CMakeLists.txt:414-421)
// compile this file without the backend.

namespace mcla::renderer {

// ---------------------------------------------------------------------------
// F-642, assertion 2: native::'s D3D12 sampler table, against the SDK itself.
// ---------------------------------------------------------------------------
// renderer/texture_decode.h restates the D3D12 sampler enums as plain numbers
// so that module stays D3D12-free (its own header says so). That is a good
// property and also the reason the rot went unnoticed: the table's only
// cross-checks lived in d3d12_backend.cpp, six of them behind
// `#ifdef MCLA_ASSERT_TEXTURE_DECODE_TABLE`, so the build never saw them.
//
// This translation unit already includes <d3d12.h> (and is compiled by every
// target that builds this file, so the check cannot be configured away), which
// makes it the place where BOTH sides of the comparison are visible. The
// asserts are therefore unconditional and name the SDK enumerator, not a second
// hand-written copy of the value: if either side drifts, the build fails.
// Two spellings are passed because three of the SDK names carry an extra
// MAG_LINEAR/MAG_POINT word this module's constants do not.
// texture_decode.h additionally asserts the same table against d3d12.h's
// documented ENCODING (min/mag/mip at shifts 4/2/0, reduction at 7) in every
// translation unit that includes it, so the two checks fail independently.
#define MCLA_ASSERT_SDK_FILTER(nativeName, sdkName)                            \
    static_assert(                                                              \
        static_cast<uint32_t>(native::kD3D12Filter##nativeName) ==             \
            static_cast<uint32_t>(D3D12_FILTER_##sdkName),                     \
        "renderer/texture_decode.h kD3D12Filter" #nativeName                    \
        " disagrees with d3d12.h D3D12_FILTER_" #sdkName)
MCLA_ASSERT_SDK_FILTER(MinMagMipPoint, MIN_MAG_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(MinMagPointMipLinear, MIN_MAG_POINT_MIP_LINEAR);
// No D3D12_FILTER_MIN_POINT_MAG_MIP_POINT exists; the SDK spells this mode
// ..._MIN_POINT_MAG_LINEAR_MIP_POINT (0x4) and native:: keeps the older
// mis-spelled name because d3d12_backend.cpp and texture_decode.cpp both use it.
MCLA_ASSERT_SDK_FILTER(MinPointMagMipPoint, MIN_POINT_MAG_LINEAR_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(MinPointMagMipLinear, MIN_POINT_MAG_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(MinLinearMagMipPoint, MIN_LINEAR_MAG_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(MinLinearMagMipLinear, MIN_LINEAR_MAG_POINT_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(MinMagMipLinear, MIN_MAG_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(Anisotropic, ANISOTROPIC);
MCLA_ASSERT_SDK_FILTER(ComparisonMinMagMipPoint, COMPARISON_MIN_MAG_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(ComparisonMinMagPointMipLinear, COMPARISON_MIN_MAG_POINT_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(ComparisonMinPointMagMipPoint, COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(ComparisonMinPointMagMipLinear, COMPARISON_MIN_POINT_MAG_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(ComparisonMinLinearMagMipPoint, COMPARISON_MIN_LINEAR_MAG_MIP_POINT);
MCLA_ASSERT_SDK_FILTER(ComparisonMinLinearMagMipLinear, COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(ComparisonMinMagMipLinear, COMPARISON_MIN_MAG_MIP_LINEAR);
MCLA_ASSERT_SDK_FILTER(ComparisonAnisotropic, COMPARISON_ANISOTROPIC);
#undef MCLA_ASSERT_SDK_FILTER

// static_cast on BOTH sides: native::'s table is an unnamed enum and the SDK's
// is a named one, and comparing two different enumeration types directly is a
// deprecated clang construct that warns in every build.
#define MCLA_ASSERT_SDK_VALUE(constant, sdkName)                               \
    static_assert(static_cast<uint32_t>(constant) ==                           \
                      static_cast<uint32_t>(sdkName),                          \
                  "renderer/texture_decode.h " #constant " disagrees with "    \
                  "d3d12.h " #sdkName)
MCLA_ASSERT_SDK_VALUE(native::kD3D12AddressModeWrap, D3D12_TEXTURE_ADDRESS_MODE_WRAP);
MCLA_ASSERT_SDK_VALUE(native::kD3D12AddressModeMirror, D3D12_TEXTURE_ADDRESS_MODE_MIRROR);
MCLA_ASSERT_SDK_VALUE(native::kD3D12AddressModeClamp, D3D12_TEXTURE_ADDRESS_MODE_CLAMP);
MCLA_ASSERT_SDK_VALUE(native::kD3D12AddressModeBorder, D3D12_TEXTURE_ADDRESS_MODE_BORDER);
MCLA_ASSERT_SDK_VALUE(native::kD3D12AddressModeMirrorOnce, D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncNone, D3D12_COMPARISON_FUNC_NONE);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncNever, D3D12_COMPARISON_FUNC_NEVER);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncLess, D3D12_COMPARISON_FUNC_LESS);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncEqual, D3D12_COMPARISON_FUNC_EQUAL);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncLessEqual, D3D12_COMPARISON_FUNC_LESS_EQUAL);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncGreater, D3D12_COMPARISON_FUNC_GREATER);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncNotEqual, D3D12_COMPARISON_FUNC_NOT_EQUAL);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncGreaterEqual, D3D12_COMPARISON_FUNC_GREATER_EQUAL);
MCLA_ASSERT_SDK_VALUE(native::kD3D12ComparisonFuncAlways, D3D12_COMPARISON_FUNC_ALWAYS);
#undef MCLA_ASSERT_SDK_VALUE

// Simple 64-bit hash combiner (splitmix64-inspired).
static uint64_t CombineHash(uint64_t a, uint64_t b) {
    uint64_t h = a ^ (b + 0x9e3779b97f4a7c15ULL + (a << 6) + (a >> 2));
    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;
    h *= 0xc4ceb9fe1a85ec53ULL;
    h ^= h >> 33;
    return h;
}

static uint64_t HashBytes(const void* data, size_t len, uint64_t seed) {
    // FNV-1a over raw bytes. Reading padding is fine for a HASH (it is never an
    // identity), it is only wrong for operator==, which is field-wise above.
    const uint8_t* p = static_cast<const uint8_t*>(data);
    uint64_t h = seed ^ 0xcbf29ce484222325ULL;
    for (size_t i = 0; i < len; ++i) {
        h ^= p[i];
        h *= 0x100000001b3ULL;
    }
    return h;
}

static uint64_t HashState(const PipelineState& state) {
    uint64_t h = 0;
    for (uint32_t i = 0; i < kMaxRenderTargets; ++i)
        h = CombineHash(h, state.targetFormats[i]);
    h = CombineHash(h, state.depthStencilFormat);
    h = CombineHash(h, state.blendState);
    h = CombineHash(h, state.rasterState);
    h = CombineHash(h, state.depthStencilState);
    h = CombineHash(h, state.topology);
    h = CombineHash(h, state.sampleCount);
    h = CombineHash(h, state.derivation);
    h = CombineHash(h, state.flags);
    // The D3D12 state the PSO is actually built from must be part of the
    // identity: before this, two packets differing only in cull mode produced
    // the same key and therefore the same PSO.
    h = HashBytes(&state.d3d12.raster, sizeof(state.d3d12.raster), h);
    h = HashBytes(&state.d3d12.blend, sizeof(state.d3d12.blend), h);
    h = HashBytes(&state.d3d12.depthStencil, sizeof(state.d3d12.depthStencil), h);
    return h;
}

PipelineKey ComputePipelineKey(uint64_t vsHash, uint64_t psHash,
                               uint64_t vertexDeclHash, const PipelineState& state) {
    PipelineKey key;
    key.vsHash = vsHash;
    key.psHash = psHash;
    key.vertexDeclHash = vertexDeclHash;
    key.inputLayoutHash = 0;
    key.state = state;
    // A zero-initialised PipelineState is what a caller that never looked at the
    // packet produces (render_thread.cpp builds one by hand and zeroes the
    // three guest fingerprints). It cannot be told apart from "the guest really
    // wrote zero", so it refuses itself instead of silently keying a PSO whose
    // blend/cull/depth nobody derived.
    if (state.derivation == kStateDerivedNone) key.refuseMask |= kRefuseStateNotDerived;
    if (state.sampleCount == 0) key.refuseMask |= kRefuseStateNotDerived;
    return key;
}

PipelineKey ComputePipelineKeyForLayout(
        uint64_t vsHash, uint64_t psHash, uint64_t vertexDeclHash,
        const PipelineState& state,
        const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout) {
    PipelineKey key = ComputePipelineKey(vsHash, psHash, vertexDeclHash, state);
    key.inputLayoutHash = HashInputLayout(inputLayout);
    if (inputLayout.empty()) key.refuseMask |= kRefuseEmptyInputLayout;
    return key;
}

uint64_t HashPipelineKey(const PipelineKey& key) {
    uint64_t h = CombineHash(key.vsHash, key.psHash);
    h = CombineHash(h, key.vertexDeclHash);
    h = CombineHash(h, key.inputLayoutHash);
    h = CombineHash(h, HashState(key.state));
    h = CombineHash(h, key.refuseMask);
    return h;
}

std::size_t PipelineKeyHash::operator()(const PipelineKey& k) const noexcept {
    return static_cast<std::size_t>(HashPipelineKey(k));
}

// Stable 64-bit hash of shader bytecode (FNV-1a 64-bit).
static uint64_t Fnv1a64(const uint8_t* data, size_t len) {
    uint64_t hash = 0xcbf29ce484222325ULL;
    for (size_t i = 0; i < len; ++i) {
        hash ^= data[i];
        hash *= 0x100000001b3ULL;
    }
    return hash;
}

uint64_t HashShaderBytecode(const std::vector<uint8_t>& bytecode) {
    return Fnv1a64(bytecode.data(), bytecode.size());
}

uint64_t HashShaderBytecode(const std::string& hlsl) {
    return Fnv1a64(reinterpret_cast<const uint8_t*>(hlsl.data()), hlsl.size());
}

// ---------------------------------------------------------------------------
// Refusal text
// ---------------------------------------------------------------------------
void FormatPipelineRefusal(uint32_t mask, char* out, size_t outBytes) {
    if (!out || outBytes == 0) return;
    out[0] = '\0';
    struct Entry { uint32_t bit; const char* name; };
    static constexpr Entry kNames[] = {
        {kRefuseStateNotDerived,        "state-not-derived"},
        {kRefuseEmptyHlsl,              "empty-hlsl"},
        {kRefuseNoDevice,               "no-device"},
        {kRefuseNoRootSignature,        "no-root-signature"},
        {kRefuseEmptyInputLayout,       "empty-input-layout"},
        {kRefuseLayoutDeclHashMismatch, "layout-hash-mismatch"},
        {kRefuseUnsupportedPolyMode,    "unsupported-poly-mode"},
        {kRefuseTopologyUnknown,        "unsupported-topology"},
        {kRefuseOverTextureSlots,       "srv-outside-t0-t3"},
        {kRefuseSamplerRegister,        "sampler-not-s0"},
        {kRefuseRequiredDepthState,     "unmeasured-depth-state-required"},
        {kRefuseQueueSaturated,         "compile-queue-saturated"},
        // F-646: one name per missing guest register, carrying the Xenos index so
        // a grep finds the register file the producer has to wire.
        {kRefuseNoPaSuScModeCntl,       "no-0x2205-pa-su-sc-mode-cntl"},
        {kRefuseNoPaClipCntl,           "no-0x2204-pa-cl-clip-cntl"},
        {kRefuseNoPaClVteCntl,          "no-0x2206-pa-cl-vte-cntl"},
        {kRefuseViewportExtentsUnmeasured, "viewport-extents-unmeasured"},
        // D1: named by the register indices that are actually absent. The old
        // PC-POLYOFF line named RB_DEPTHF_INFO, which is not a register at all.
        {kRefuseNoPolyOffsetFront,  "no-0x2380-0x2381-pa-su-poly-offset-front"},
        {kRefuseNoPolyOffsetBack,   "no-0x2382-0x2383-pa-su-poly-offset-back"},
        {kRefuseNoDepthInfo,        "no-0x2002-rb-depth-info-depth-format"},
        // F-653: the rectangle-list geometry stage. Two names, never merged,
        // because "the device cannot do it" and "the stage was not derivable
        // from this program's VS" have nothing in common as follow-up work.
        {kRefuseGeometryStageUnsupported, "geom-stage-unsupported-at-this-feature-level"},
        {kRefuseGeometryShaderUnbuildable, "geom-stage-not-derivable-from-vs-signature"},
        // F-692/F-716: the name the PSO-creation failures were missing. It used
        // to print "empty-hlsl" for a cause with nothing to do with HLSL.
        {kRefusePsoCreateFailed,       "pso-create-failed"},
    };
    // Every bit in use must have a name here, or FormatPipelineRefusal renders
    // "unnamed-0x..." and a soak grepping for a reason name finds none -- which
    // is the failure the guard below exists to make impossible.
    static_assert(sizeof(kNames) / sizeof(kNames[0]) == kPipelineRefusalBitCount,
                  "kNames has one entry per PipelineRefusal bit, no more and no fewer");
    size_t used = 0;
    // D1 FIX: this guard used to sit HERE, before the loop, testing a `used`
    // that is unconditionally 0 at this point -- so it fired for every non-zero
    // mask and the loop below was dead. Every refusal in this file rendered as
    // "unnamed-0x%08X" on stderr and nothing else, which is fatal for the
    // project contract: a refusal's NAME is the only thing that says WHICH
    // register was absent, and a soak grepping for a reason name would have
    // found none. It has to test `used` AFTER the loop, where "the loop matched
    // nothing" is the condition it was written for. Found by a negative test
    // that asserted kRefuseNoPolyOffsetFront renders as a name.
    for (const auto& e : kNames) {
        if (!(mask & e.bit)) continue;
        const size_t n = std::strlen(e.name);
        const size_t need = used ? n + 1 : n;
        if (used + need + 1 >= outBytes) break;
        if (used) out[used++] = '|';
        std::memcpy(out + used, e.name, n);
        used += n;
        out[used] = '\0';
    }
    // No entry above matched: a bit with no name in kNames. Render something
    // greppable rather than an empty string a soak would read as "none"
    // (F-646's original intent, which the misplaced guard above defeated).
    if (used == 0 && mask != kRefuseNone) {
        std::snprintf(out, outBytes, "unnamed-0x%08X", mask);
        return;
    }
    if (used == 0) std::strncpy(out, "none", outBytes - 1);
}

// ---------------------------------------------------------------------------
// State derivation
// ---------------------------------------------------------------------------
namespace {

// --- D1: the Xenos absolute depth bias -> D3D12 relative DepthBias ----------
// A straight transcription of
// `.research/xenia/src/xenia/gpu/draw_util.h:206-225`
// (`GetD3D10IntegerPolygonOffset`), which is the only place the reference
// performs this conversion. Kept as host arithmetic on host floats: no guest
// pointer is read and no guest value is asserted on.
//
// The guest writes an ABSOLUTE floating-point offset (draw_util.h:118-119);
// D3D12 wants a RELATIVE one (draw_util.h:128-131), so the absolute value is
// multiplied by the depth format's minimum resolvable difference:
//   * fixed-point (kD24S8, the reference's default) --
//     kD3D10PolygonOffsetFactorUnorm24 = 2^24 - 1, draw_util.h:171-172;
//   * float24 (kD24FS8) -- kD3D10PolygonOffsetFactorFloat24 = 2^24,
//     draw_util.h:203-204, and then `<<= 3` because one float24 ULP is eight
//     float32 ULPs (draw_util.h:177-181, :221-223).
// `ceil` is the reference's choice and the reason is load-bearing: "more offset
// is better, especially if flooring would result in 0" (draw_util.h:209-211).
constexpr float kD3D10PolygonOffsetFactorUnorm24 =
    static_cast<float>((UINT32_C(1) << 24) - 1);            // draw_util.h:171-172
constexpr float kD3D10PolygonOffsetFactorFloat24 =
    static_cast<float>(UINT32_C(1) << (21 + 3));            // draw_util.h:203-204
// xenos.h:407 -- the slope scale's unit is 1/16 of a subpixel. Multiplied in at
// d3d12/pipeline_cache.cc:1502-1503, i.e. AFTER the selection, never before.
constexpr float kPolygonOffsetScaleSubpixelUnit = 1.0f / 16.0f;  // xenos.h:407

// `isFloat24` is RB_DEPTH_INFO.depth_format == kD24FS8 (xenos.h:367-371,
// registers.h:844). A format value outside {0,1} is impossible: the field is
// one bit, so this needs no range check and adds none.
int32_t D3D10IntegerPolygonOffset(bool isFloat24, float polygonOffset) {
    const float factor = isFloat24
            ? kD3D10PolygonOffsetFactorFloat24 * (1.0f / 8.0f)
            : kD3D10PolygonOffsetFactorUnorm24;
    int32_t v = static_cast<int32_t>(std::ceil(std::abs(polygonOffset) * factor));
    if (isFloat24) v <<= 3;  // draw_util.h:221-223
    return polygonOffset < 0 ? -v : v;  // draw_util.h:224
}

// Guest register bit fields, from the local Xenia checkout (never guessed):
//   PA_SU_SC_MODE_CNTL  .research/xenia/src/xenia/gpu/registers.h:456-489
//   PA_CL_CLIP_CNTL     .research/xenia/src/xenia/gpu/registers.h:534-563
//   PA_CL_VTE_CNTL      .research/xenia/src/xenia/gpu/registers.h:566-584
//   PolygonModeEnable / PolygonType  xenos.h:846-859
//   cull/fill lowering  d3d12/pipeline_cache.cc:1473-1490,
//                       vulkan/vulkan_pipeline_cache.cc:588-621
//   depth_clip          d3d12/pipeline_cache.cc:1508
//
// D2: bits 17-31 used to collapse into `rest : 15`. The 15 was ARITHMETICALLY
// CORRECT for the size (17 named + 15 = 32, which is what F-634 needed after a
// 33-bit field broke the assert) and CONTENT-WRONG for the register: the
// reference names five of those bits, and one of them -- provoking_vtx_last --
// changes which vertex a primitive's provoking attribute comes from, i.e. it
// changes the rasterised image. Naming them changes nothing behaviourally TODAY
// (nothing reads them yet), which is exactly why it had to be done
// deliberately: an unnamed bit is a bit nobody is obliged to check, and this is
// the register the whole rasteriser decodes out of. Each field carries its own
// reference DECLARATION line, per docs/ref/xenos_registers.md §0: declLine is
// the declaration, not the comment above it (registers.h:461 is the comment for
// `face`; registers.h:462 is its declaration).
struct SuScModeCntl {
    uint32_t cullFront       : 1;  // registers.h:459  bit 0
    uint32_t cullBack        : 1;  // registers.h:460  bit 1
    uint32_t face            : 1;  // registers.h:462  bit 2 (0: CCW, 1: CW)
    uint32_t polyMode        : 2;  // registers.h:467  bits 3-4
    uint32_t polyFrontType   : 3;  // registers.h:468  bits 5-7
    uint32_t polyBackType    : 3;  // registers.h:469  bits 8-10
    uint32_t polyOffFrontEn  : 1;  // registers.h:470  bit 11
    uint32_t polyOffBackEn   : 1;  // registers.h:471  bit 12
    uint32_t polyOffParaEn   : 1;  // registers.h:472  bit 13
    uint32_t _pad14          : 1;  // registers.h:473  bit 14
    uint32_t msaaEnable      : 1;  // registers.h:474  bit 15
    uint32_t vtxWindowOffset : 1;  // registers.h:475  bit 16
    uint32_t _pad17          : 2;  // registers.h:477  bits 17-18
    // --- D2: the five fields the reference names; all five were inside `rest` ---
    uint32_t provokingVtxLast  : 1;  // registers.h:478  bit 19
    uint32_t perspCorrDis      : 1;  // registers.h:479  bit 20
    uint32_t multiPrimIbEna    : 1;  // registers.h:480  bit 21 (VGT_MULTI_PRIM_
                                    //  IB_RESET_INDX exists, registers.h:343)
    uint32_t _pad22            : 1;  // registers.h:481  bit 22
    uint32_t quadOrderEnable   : 1;  // registers.h:482  bit 23
    uint32_t scOneQuadPerClock : 1;  // registers.h:483  bit 24
    uint32_t _pad25            : 7;  // registers.h:486  bits 25-31
    // Widths: 1+1+1+2+3+3+1+1+1+1+1+1 = 17 (bits 0-16); +2 (17-18) = 19;
    // +1+1+1 = 22 (bits 19-21); +1 (22) = 23; +1+1 = 25 (bits 23-24);
    // +7 = 32 (bits 25-31). The unconditional static_assert below is what holds
    // that arithmetic; it is not macro-guarded and must never become so (see the
    // note there on how a 33-bit field survived review behind this register).
};
// PA_CL_CLIP_CNTL (.research/xenia/src/xenia/gpu/registers.h:534-563).
// ucp_ena_0..5 +0..+5, _pad_6:8 +6..+13, ps_ucp_mode +14, clip_disable +16,
// ucp_cull_only_ena +17, boundary_edge_flag_ena +18, dx_clip_space_def +19,
// dis_clip_err_detect +20, vtx_kill_or +21, xy_nan_retain +22, z_nan_retain +23,
// w_nan_retain +24, _pad_25:7 +25..+31.
struct ClipCntl {
    uint32_t ucpEna0 : 1;
    uint32_t ucpEna1 : 1;
    uint32_t ucpEna2 : 1;
    uint32_t ucpEna3 : 1;
    uint32_t ucpEna4 : 1;
    uint32_t ucpEna5 : 1;
    uint32_t pad6    : 8;
    uint32_t psUcpMode : 2;
    uint32_t clipDisable : 1;  // +16
    uint32_t ucpCullOnly : 1;
    uint32_t boundaryEdge : 1;
    uint32_t dxClipSpaceDef : 1;
    uint32_t disClipErrDetect : 1;
    uint32_t vtxKillOr : 1;
    uint32_t xyNanRetain : 1;
    uint32_t zNanRetain : 1;
    uint32_t wNanRetain : 1;
    uint32_t pad25 : 7;
};

// PA_CL_VTE_CNTL. F-646: this struct DID NOT EXIST. The header listed
// paClVteCntl as an input and DerivePipelineState stored it as
// `depthStencilState`, but no overlay ever decoded it, so the viewport state was
// a fingerprint and nothing else. Layout from
// .research/xenia/src/xenia/gpu/registers.h:566-584, field by field:
//
//   vport_x_scale_ena  +0   vport_y_scale_ena  +2   vport_z_scale_ena  +4
//   vport_x_offset_ena +1   vport_y_offset_ena +3   vport_z_offset_ena +5
//   _pad_6 :2            +6..+7
//   vtx_xy_fmt  +8   vtx_z_fmt +9   vtx_w0_fmt +10   perfcounter_ref +11
//   _pad_12 :20         +12..31
struct ClVteCntl {
    uint32_t vportXScaleEn  : 1;  // +0
    uint32_t vportXOffsetEn : 1;  // +1
    uint32_t vportYScaleEn  : 1;  // +2
    uint32_t vportYOffsetEn : 1;  // +3
    uint32_t vportZScaleEn  : 1;  // +4
    uint32_t vportZOffsetEn : 1;  // +5
    uint32_t pad6           : 2;  // +6..7
    uint32_t vtxXyFmt       : 1;  // +8
    uint32_t vtxZFmt        : 1;  // +9
    uint32_t vtxW0Fmt       : 1;  // +10
    uint32_t perfcounterRef : 1;  // +11
    uint32_t rest           : 20; // +12..31
};

// F-646: all three size asserts are UNCONDITIONAL, kept in one contiguous block
// after the third overlay so no reader can believe any of them is macro-guarded.
// (The "asserts hidden behind a macro that was never defined" defect in this
// file was the TEXTURE FILTER block at the top, which F-642 already fixed; these
// three were never affected -- they were already unconditional -- but the group
// is deliberately kept together.) Each names the register it protects. A macro
// guard here is precisely how a 33-bit bitfield in a one-dword struct survives
// review, so the guard is not merely absent -- it is called out.
// D2 (width half): the five newly named fields add 1+1+1+1+1 = 5 bits, taken
// out of the old `rest : 15` -> `rest` is now `_pad25 : 7`, and the two padding
// runs 17-18 and 22 are named too. The total is still 32, so the assert above
// still holds -- which is the point: the assert was never the thing that was
// wrong. It held a register that was five fields short.
static_assert(sizeof(SuScModeCntl) == sizeof(uint32_t),
              "PA_SU_SC_MODE_CNTL overlay must stay exactly one dword "
              "(D2: 17 named + 2 (_pad17) + 3 named + 1 (_pad22) + 2 named + "
              "7 (_pad25) = 32)");
static_assert(sizeof(ClipCntl) == sizeof(uint32_t),
              "PA_CL_CLIP_CNTL overlay must stay exactly one dword");
static_assert(sizeof(ClVteCntl) == sizeof(uint32_t),
              "PA_CL_VTE_CNTL overlay must stay exactly one dword");

// F-646: the size assert is the COMPILE-TIME half of the guard. It is
// unconditional and it is what catches the specific rot class the previous audit
// found (a 33-bit bitfield in a struct asserted to be one dword): a width typo
// that pushes the total past 32 fails here at build time, in every target.
//
// It is NOT possible to make the bit POSITIONS compile-time checked, and that
// was measured rather than assumed, on the toolchain this project builds with
// (LLVM clang-cl, `-clang:-std=c++23`):
//   * `std::memcpy` into a bitfield struct -- "cannot constant evaluate
//     'memcpy' from object of type 'uint32_t' to object of type 'SuScModeCntl'".
//   * `__builtin_bit_cast(SuScModeCntl, raw)` -- "constexpr bit_cast involving
//     bit-field is not yet supported".
//   * a `union { uint32_t raw; SuScModeCntl s; }` pun -- "read of member of union
//     with active member 'raw' is not allowed in a constant expression".
// All three were tried; all three are rejected, so a `static_assert` over the
// positions is not available here. VerifyXenosRenderStateLayouts below is the
// runtime half and it is REAL -- do not delete it on the grounds that a
// static_assert would be nicer. The compile-time cross-check against the actual
// Xenia header needs an `#include "xenia/gpu/registers.h"`, which requires a
// `-I` for .research/xenia/src that none of the five targets carry (a
// CMakeLists.txt change this file does not own); the paste-ready version is
// reported instead of being faked here.
struct F646LayoutProbe {
    uint32_t raw;
    uint32_t expectCullFront, expectCullBack, expectFace, expectPolyMode;
    uint32_t expectPolyFrontType, expectPolyBackType, expectMsaa;
    uint32_t expectClipDisable;
    uint32_t expectVportXScaleEn, expectVtxXyFmt, expectVtxZFmt;
};
// Measured in build/w658.log (CP-DRAW-REGS, the guest's own draws):
//   r2204=0x00010000  -> bit 16 only  = clip_disable
//   r2205=0x00010000  -> bit 16 only  = vtx_window_offset_enable
//   r2206=0x00000300  -> bits 8,9     = vtx_xy_fmt, vtx_z_fmt
constexpr F646LayoutProbe kF646Measured = {
    /*raw*/ 0x00010000u,
    /*expectCullFront*/ 0u, /*expectCullBack*/ 0u, /*expectFace*/ 0u,
    /*expectPolyMode*/ 0u, /*expectPolyFrontType*/ 0u, /*expectPolyBackType*/ 0u,
    /*expectMsaa*/ 0u,
    /*expectClipDisable*/ 1u,  // bit 16, registers.h:547
    /*expectVportXScaleEn*/ 0u, /*expectVtxXyFmt*/ 0u, /*expectVtxZFmt*/ 0u,
};
// The viewport value differs from the other two, so it cannot share .raw; it is
// built from the documented shifts (registers.h:569-578) rather than from a
// second copy of the struct, which is the whole point of the check.
constexpr uint32_t kF646VteRaw = (1u << 8) | (1u << 9);  // vtx_xy_fmt + vtx_z_fmt

// --- D2: the probe values for bits 17-31 of PA_SU_SC_MODE_CNTL --------------
// The measured guest value (bit 16 only) says NOTHING about bits 17-31, so
// naming five fields there and never exercising them would be the same defect
// one level down: correct names, no evidence.
//
// ONE RAW VALUE PER FIELD, and that is measured, not stylistic. The first
// version of this probe set all five bits at once (17,18,19,20,21,23,24) and
// asserted all five fields read 1. That check PASSES on a struct where
// quad_order_enable and sc_one_quad_per_clock are SWAPPED, because both
// adjacent bits are set either way -- a negative test caught exactly that.
// Probing each bit ALONE, and requiring the other four named fields to read 0,
// is the only form that makes the names load-bearing. Each raw is one bit, so
// a mis-declared position, a wrong width, or a field absorbed into a pad all
// move a value and fail.
constexpr uint32_t kD2Pad17Raw  = (1u << 17) | (1u << 18);  // _pad_17, 2 bits
constexpr uint32_t kD2ProvokingVtxLastRaw = (1u << 19);
constexpr uint32_t kD2PerspCorrDisRaw     = (1u << 20);
constexpr uint32_t kD2MultiPrimIbEnaRaw   = (1u << 21);
constexpr uint32_t kD2Pad22Raw            = (1u << 22);
constexpr uint32_t kD2QuadOrderEnableRaw  = (1u << 23);
constexpr uint32_t kD2ScOneQuadPerClockRaw = (1u << 24);
constexpr uint32_t kD2Pad25Raw            = (1u << 25);

// Every field of the 17..31 run, read out of the overlay. Compared as a whole
// against an 8-tuple, so a probe cannot pass by matching only the field it was
// written for.
struct D2TailValues {
    uint32_t pad17, provokingVtxLast, perspCorrDis, multiPrimIbEna;
    uint32_t pad22, quadOrderEnable, scOneQuadPerClock, pad25;
};
static D2TailValues ReadSuScModeCntlTail(uint32_t raw) {
    SuScModeCntl s{};
    std::memcpy(&s, &raw, sizeof(s));
    return D2TailValues{s._pad17,  s.provokingVtxLast, s.perspCorrDis,
                        s.multiPrimIbEna, s._pad22,     s.quadOrderEnable,
                        s.scOneQuadPerClock, s._pad25};
}

}  // namespace

bool VerifyXenosRenderStateLayouts() {
    SuScModeCntl su{};
    std::memcpy(&su, &kF646Measured.raw, sizeof(su));
    if (su.cullFront != kF646Measured.expectCullFront) return false;
    if (su.cullBack != kF646Measured.expectCullBack) return false;
    if (su.face != kF646Measured.expectFace) return false;
    if (su.polyMode != kF646Measured.expectPolyMode) return false;
    if (su.polyFrontType != kF646Measured.expectPolyFrontType) return false;
    if (su.polyBackType != kF646Measured.expectPolyBackType) return false;
    if (su.msaaEnable != kF646Measured.expectMsaa) return false;
    // The 0x00010000 in PA_SU_SC_MODE_CNTL is bit 16 = vtx_window_offset_enable,
    // and must NOT land in any other named field. That is the discriminating
    // check: a one-bit value alone cannot tell 16 fields apart.
    if (su.vtxWindowOffset != 1u) return false;

    // --- D2: bits 17-31, the five fields the reference names ---------------
    // Eight raws, one per field, each compared against the WHOLE 8-tuple. The
    // bit positions are registers.h:477-486; the expected values are that same
    // table read literally, so a probe and a struct that disagree cannot both
    // be right. Reference cross-check on the use side: provoking_vtx_last has
    // no lowering in the reference at all (it is listed with no cross-check
    // column entry in docs/ref/xenos_registers.md §2.1), which is why these are
    // decoded for the log and not mapped.
    struct TailCase { uint32_t raw; D2TailValues expect; };
    static constexpr TailCase kD2Cases[] = {
        // _pad_17 is TWO bits (registers.h:477), so its probe sets both.
        {kD2Pad17Raw,             {3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}},
        {kD2ProvokingVtxLastRaw,  {0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u}},
        {kD2PerspCorrDisRaw,      {0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u}},
        {kD2MultiPrimIbEnaRaw,    {0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u}},
        {kD2Pad22Raw,             {0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u}},
        {kD2QuadOrderEnableRaw,   {0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u}},
        {kD2ScOneQuadPerClockRaw, {0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u}},
        // _pad_25 starts at bit 25 (registers.h:486). This is the case that
        // fails if sc_one_quad_per_clock is ever widened, and it is the case
        // that would fail if the D2 fix were reverted to `rest : 15` and the
        // five names silently re-disappeared into it.
        {kD2Pad25Raw,             {0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u}},
    };
    for (const TailCase& c : kD2Cases) {
        const D2TailValues got = ReadSuScModeCntlTail(c.raw);
        if (got.pad17 != c.expect.pad17 ||
            got.provokingVtxLast != c.expect.provokingVtxLast ||
            got.perspCorrDis != c.expect.perspCorrDis ||
            got.multiPrimIbEna != c.expect.multiPrimIbEna ||
            got.pad22 != c.expect.pad22 ||
            got.quadOrderEnable != c.expect.quadOrderEnable ||
            got.scOneQuadPerClock != c.expect.scOneQuadPerClock ||
            got.pad25 != c.expect.pad25)
            return false;
    }
    // The all-set case as well, so a field declared NARROWER than the reference
    // (spilling into its neighbour) is caught: bits 17-21 and 23-24 all set,
    // bit 22 clear.
    {
        constexpr uint32_t kD2AllNamedRaw = (1u << 17) | (1u << 18) | (1u << 19) |
                                            (1u << 20) | (1u << 21) | (1u << 23) |
                                            (1u << 24);
        const D2TailValues got = ReadSuScModeCntlTail(kD2AllNamedRaw);
        if (got.pad17 != 3u || got.provokingVtxLast != 1u || got.perspCorrDis != 1u ||
            got.multiPrimIbEna != 1u || got.pad22 != 0u || got.quadOrderEnable != 1u ||
            got.scOneQuadPerClock != 1u || got.pad25 != 0u)
            return false;
    }

    ClipCntl cl{};
    std::memcpy(&cl, &kF646Measured.raw, sizeof(cl));
    if (cl.clipDisable != kF646Measured.expectClipDisable) return false;
    if (cl.ucpEna0 || cl.ucpEna1 || cl.ucpEna2 || cl.ucpEna3 || cl.ucpEna4 ||
        cl.ucpEna5 || cl.psUcpMode || cl.ucpCullOnly || cl.boundaryEdge ||
        cl.dxClipSpaceDef || cl.disClipErrDetect || cl.vtxKillOr ||
        cl.xyNanRetain || cl.zNanRetain || cl.wNanRetain)
        return false;

    ClVteCntl vte{};
    std::memcpy(&vte, &kF646VteRaw, sizeof(vte));
    if (vte.vtxXyFmt != 1u) return false;
    if (vte.vtxZFmt != 1u) return false;
    if (vte.vtxW0Fmt != 0u) return false;
    if (vte.vportXScaleEn != 0u) return false;
    if (vte.vportYScaleEn != 0u) return false;
    if (vte.vportZScaleEn != 0u) return false;
    if (vte.vportXOffsetEn != 0u) return false;
    if (vte.vportYOffsetEn != 0u) return false;
    if (vte.vportZOffsetEn != 0u) return false;
    if (vte.perfcounterRef != 0u) return false;
    return true;
}

// The declared baseline D3D12 state: solid fill, no culling, depth clip on,
// blending off, depth/stencil off. Applied by both derivation entry points so a
// zeroed PipelineStateD3D12 can never reach CreateGraphicsPipelineState -- a
// zeroed D3D12_RASTERIZER_DESC has DepthClipEnable == FALSE, which clips
// everything away, and D3D12_BLEND_DESC has no implicit defaults at all.
static void ApplyBaselineD3D12State(PipelineState& s) {
    D3D12_RASTERIZER_DESC& r = s.d3d12.raster;
    r.FillMode = D3D12_FILL_MODE_SOLID;
    r.CullMode = D3D12_CULL_MODE_NONE;
    r.DepthClipEnable = TRUE;
    r.FrontCounterClockwise = TRUE;
    // F-634: no `DepthBiasEnable` field exists on D3D12_RASTERIZER_DESC --
    // depth bias is the three FLOATs set on the next three lines, and the only
    // BOOL near it is `DepthClipEnable` (set above). The invented assignment
    // broke the build; the real bias state is already zeroed below.
    r.DepthBias = 0;
    r.DepthBiasClamp = 0.0f;
    r.SlopeScaledDepthBias = 0.0f;
    // F-634: `ConservativeRaster` is a D3D12_CONSERVATIVE_RASTERIZATION_MODE,
    // not a BOOL -- assigning FALSE (int) is a type error.
    r.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    r.AntialiasedLineEnable = FALSE;
    r.MultisampleEnable = (s.sampleCount > 1) ? TRUE : FALSE;

    D3D12_BLEND_DESC& b = s.d3d12.blend;
    b.AlphaToCoverageEnable = FALSE;
    b.IndependentBlendEnable = FALSE;
    // F-634: `D3D12_COLOR_ATTACHMENT_COUNT` does not exist. The SDK note
    // beside `RenderTarget[8]` names the real one: D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT.
    for (UINT i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i) {
        b.RenderTarget[i].BlendEnable = FALSE;
        b.RenderTarget[i].LogicOpEnable = FALSE;
        b.RenderTarget[i].SrcBlend = D3D12_BLEND_ONE;
        b.RenderTarget[i].DestBlend = D3D12_BLEND_ZERO;
        b.RenderTarget[i].BlendOp = D3D12_BLEND_OP_ADD;
        b.RenderTarget[i].SrcBlendAlpha = D3D12_BLEND_ONE;
        b.RenderTarget[i].DestBlendAlpha = D3D12_BLEND_ZERO;
        b.RenderTarget[i].BlendOpAlpha = D3D12_BLEND_OP_ADD;
        b.RenderTarget[i].LogicOp = D3D12_LOGIC_OP_NOOP;
        b.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }

    D3D12_DEPTH_STENCIL_DESC& d = s.d3d12.depthStencil;
    d.DepthEnable = FALSE;
    d.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;
    d.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    d.StencilEnable = FALSE;
    d.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;
    d.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;
    d.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
    d.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
    d.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
    d.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    d.BackFace = d.FrontFace;
}

// kCountedPrimTypes covers the whole architected Xenos prim_type space that is
// NOT the explicit-major-mode range: 0x00..0x0F, i.e. every value up to and
// including kPolygon, and 0x10 (k2DCopyRectListV0 / kExplicitMajorModeForceStart)
// is the first value that belongs to the 2D/tessellation families. One extra
// slot catches everything above that so the counter never writes out of bounds.
static constexpr uint32_t kCountedPrimTypes = 17;  // 0x00..0x10 + "above"

// The architected name for a Xenos prim_type, read off
// .research/xenia/src/xenia/gpu/xenos.h `enum class PrimitiveType` (kNone=0x00
// .. kPolygon=0x0F, then kExplicitMajorModeForceStart/k2DCopyRectListV0=0x10).
// A refusal that prints "0x04" is a number; one that prints "kTriangleList" is
// something a soak can be grepped for and a reader can check against the header.
static const char* XenosPrimTypeName(uint32_t primType) {
    switch (primType) {
        case 0x00: return "kNone";
        case 0x01: return "kPointList";
        case 0x02: return "kLineList";
        case 0x03: return "kLineStrip";
        case 0x04: return "kTriangleList";
        case 0x05: return "kTriangleFan";
        case 0x06: return "kTriangleStrip";
        case 0x07: return "kTriangleWithWFlags";
        case 0x08: return "kRectangleList";
        case 0x0C: return "kLineLoop";
        case 0x0D: return "kQuadList";
        case 0x0E: return "kQuadStrip";
        case 0x0F: return "kPolygon";
        default:   return primType < 0x10 ? "kUndefined" : "k2DOrTessellation";
    }
}

// F-646: one counted line per register that did not arrive, so the refusal census
// answers "which register" without any reader decoding a state value. House
// pattern n <= K || (n % 200) == 0, and the counter is PER REGISTER so a soak
// can attribute a non-zero count to one missing register (F-054: a soak dominated
// by one repeating message is POISONED, so the counters must not be shared).
namespace {
void CountMissingRegister(const char* regName, const char* regIndex) {
    static std::atomic<uint32_t> s_missing{0};
    const uint32_t n = s_missing.fetch_add(1) + 1;
    if (n <= 4 || (n % 200) == 0)
        MCLA_LOG_WARN("PC-REG-MISSING #{} {} (0x{}) absent from the draw packet; "
                      "PSO refused, raster state NOT defaulted to zero",
                      n, regName, regIndex);
}
}  // namespace

DecodedXenosRenderState DecodeGuestRenderState(const PipelineStateInputs& in,
                                                uint32_t& refuseMask) {
    DecodedXenosRenderState d;
    // A missing register is REFUSED and counted by name; it is never decoded as
    // zero. The reason this is not cosmetic: 0x00000000 is a legal value for all
    // three registers and means something specific and different from "absent"
    // (see the GuestRegisterPresent comment in pipeline_cache.h).
    if (!(in.registersPresent & kGuestRegPaSuScModeCntl)) {
        refuseMask |= kRefuseNoPaSuScModeCntl;
        CountMissingRegister("PA_SU_SC_MODE_CNTL", "2205");
    } else {
        SuScModeCntl su;
        std::memcpy(&su, &in.paSuScModeCntl, sizeof(su));
        d.suPresent   = true;
        d.cullFront   = su.cullFront != 0u;
        d.cullBack    = su.cullBack != 0u;
        d.frontIsCw   = su.face != 0u;
        d.polyMode    = su.polyMode;
        d.polyFrontType = su.polyFrontType;
        d.polyBackType  = su.polyBackType;
        d.polyOffsetFrontEn = su.polyOffFrontEn != 0u;
        d.polyOffsetBackEn  = su.polyOffBackEn != 0u;
        d.polyOffsetParaEn  = su.polyOffParaEn != 0u;
        d.msaaEnable  = su.msaaEnable != 0u;
        d.vtxWindowOffsetEn = su.vtxWindowOffset != 0u;
        // D2: the five fields the reference names (registers.h:478-483). Decoded
        // but not lowered: none of them has a D3D12_RASTERIZER_DESC equivalent
        // this module can apply without a measurement it does not have, and
        // inventing one is exactly the degradation the charter forbids.
        d.provokingVtxLast  = su.provokingVtxLast != 0u;
        d.perspCorrDis      = su.perspCorrDis != 0u;
        d.multiPrimIbEna    = su.multiPrimIbEna != 0u;
        d.quadOrderEnable   = su.quadOrderEnable != 0u;
        d.scOneQuadPerClock = su.scOneQuadPerClock != 0u;
        // D1: bits 11-13 are the REQUEST. Whether the magnitude exists is a
        // separate question answered by registersPresent, because the magnitudes
        // are four other registers entirely.
        d.polyOffsetRequested = su.polyOffFrontEn != 0u || su.polyOffBackEn != 0u ||
                                su.polyOffParaEn != 0u;
    }

    if (!(in.registersPresent & kGuestRegPaClipCntl)) {
        refuseMask |= kRefuseNoPaClipCntl;
        CountMissingRegister("PA_CL_CLIP_CNTL", "2204");
    } else {
        ClipCntl cl;
        std::memcpy(&cl, &in.paClipCntl, sizeof(cl));
        d.clPresent   = true;
        d.ucpEnaMask  = (cl.ucpEna0 ? 1u : 0u) | (cl.ucpEna1 ? 2u : 0u) |
                        (cl.ucpEna2 ? 4u : 0u) | (cl.ucpEna3 ? 8u : 0u) |
                        (cl.ucpEna4 ? 16u : 0u) | (cl.ucpEna5 ? 32u : 0u);
        d.psUcpMode   = cl.psUcpMode;
        d.clipDisable = cl.clipDisable != 0u;
        d.ucpCullOnly = cl.ucpCullOnly != 0u;
    }

    if (!(in.registersPresent & kGuestRegPaClVteCntl)) {
        refuseMask |= kRefuseNoPaClVteCntl;
        CountMissingRegister("PA_CL_VTE_CNTL", "2206");
    } else {
        ClVteCntl vte;
        std::memcpy(&vte, &in.paClVteCntl, sizeof(vte));
        d.vtePresent   = true;
        d.vportXScaleEn  = vte.vportXScaleEn  != 0u;
        d.vportXOffsetEn = vte.vportXOffsetEn != 0u;
        d.vportYScaleEn  = vte.vportYScaleEn  != 0u;
        d.vportYOffsetEn = vte.vportYOffsetEn != 0u;
        d.vportZScaleEn  = vte.vportZScaleEn  != 0u;
        d.vportZOffsetEn = vte.vportZOffsetEn != 0u;
        d.vtxXyFmt = static_cast<uint8_t>(vte.vtxXyFmt);
        d.vtxZFmt  = static_cast<uint8_t>(vte.vtxZFmt);
        d.vtxW0Fmt = static_cast<uint8_t>(vte.vtxW0Fmt);
        // At least one of the six enables (registers.h:569-574). Measured state
        // in build/w658.log is 0x00000300, which sets NONE of them, so the title
        // bakes the transform into the vertex shader -- the D3D9-style case.
        d.vportTransformApplied = d.vportXScaleEn || d.vportXOffsetEn ||
                                  d.vportYScaleEn || d.vportYOffsetEn ||
                                  d.vportZScaleEn || d.vportZOffsetEn;
    }

    // F-646: the enables are measured; the EXTENTS are not (they are a different
    // register pair and no capture carries them yet). An identity viewport is the
    // right answer ONLY when the transform is off AND the target is the full
    // extent. With the transform on and no extents there is no honest answer at
    // all, so it is refused -- and a caller that DOES supply extents clears this
    // by supplying them, not by a flag.
    if (d.vportTransformApplied &&
        (in.viewportWidth == 0u || in.viewportHeight == 0u)) {
        refuseMask |= kRefuseViewportExtentsUnmeasured;
        static std::atomic<uint32_t> s_vport{0};
        const uint32_t n = s_vport.fetch_add(1) + 1;
        if (n <= 4 || (n % 200) == 0)
            MCLA_LOG_WARN("PC-VPORT-UNRESOLVED #{} PA_CL_VTE_CNTL says a viewport "
                          "transform IS applied but no extents were captured; "
                          "PSO refused rather than an identity viewport guessed",
                          n);
    }
    return d;
}

// F-653: the rectangle-offer counter lives at file scope because
// DerivePipelineState is a free function that runs BEFORE any cache exists, and
// "how many rectangles did the guest offer" has to be answerable even when every
// one of them is refused. Relaxed is sufficient and correct: it is a monotone
// tally read for reporting, not a synchronisation edge.
static std::atomic<uint32_t> s_rectangleDrawsOffered{0};

uint32_t RectangleDrawsOffered() {
    return s_rectangleDrawsOffered.load(std::memory_order_relaxed);
}

PipelineState DerivePipelineState(const PipelineStateInputs& in, uint32_t& refuseMask) {
    // F-646: the bit-layout self-check runs ONCE, on the first real derivation,
    // and speaks up only if it fails. A wrong bit here renders wrong geometry
    // with no error at all, so a silent failure is the one outcome this must
    // not have -- and the house throttle keeps it from flooding a soak.
    static std::atomic<uint32_t> s_layoutChecked{0};
    if (s_layoutChecked.fetch_add(1) == 0) {
        if (!VerifyXenosRenderStateLayouts()) {
            MCLA_LOG_ERROR("PC-REG-LAYOUT-BAD: a PA_SU_SC_MODE_CNTL / "
                           "PA_CL_CLIP_CNTL / PA_CL_VTE_CNTL overlay decodes the "
                           "MEASURED guest value incorrectly. Every shift below is "
                           "wrong somewhere; fix against registers.h:456-489 / "
                           ":534-563 / :566-584 and register_table.inc:540-542. "
                           "Geometry will render wrong with no error until this "
                           "is fixed.");
            refuseMask = kRefuseStateNotDerived;
            return PipelineState{};
        }
    }
    // `= {}` is load-bearing: an uninitialised BOOL reaching
    // CreateGraphicsPipelineState is undefined behaviour rather than "off".
    PipelineState s = {};
    refuseMask = kRefuseNone;
    s.sampleCount = 1;
    ApplyBaselineD3D12State(s);

    for (uint32_t i = 0; i < kMaxRenderTargets; ++i)
        s.targetFormats[i] = in.colorFormats[i];
    s.depthStencilFormat = in.depthStencilFormat;

    // Guest fingerprints, kept for provenance and key identity.
    s.blendState = in.paClipCntl;
    s.rasterState = in.paSuScModeCntl;
    s.depthStencilState = in.paClVteCntl;

    // Topology: only primitives that reach a D3D12 primitive type unchanged are
    // drawable here. A strip/fan/line-strip index buffer fed to the matching
    // primitive type is fine, but feeding it to TRIANGLE without rewriting the
    // indices draws WRONG TRIANGLES, which is the one failure mode a "looks
    // like it renders" mistake produces.
    //
    // F-645: in.primType is the XENOS prim type, and its value space is the
    // architected `xenos::PrimitiveType`
    // (.research/xenia/src/xenia/gpu/xenos.h, `enum class PrimitiveType`:
    // kNone=0x00, kPointList=0x01, kLineList=0x02, kLineStrip=0x03,
    // kTriangleList=0x04, kTriangleFan=0x05, kTriangleStrip=0x06,
    // kTriangleWithWFlags=0x07, kRectangleList=0x08, kLineLoop=0x0C,
    // kQuadList=0x0D, kQuadStrip=0x0E, kPolygon=0x0F, >=0x10 = explicit major
    // mode / 2D / tessellation). The previous table here read `0 -> triangle,
    // 2 -> line, 4 -> point`, which against that enum meant: kNone (0x00) drew a
    // triangle list, kPointList (0x01) was REFUSED, and kTriangleList (0x04) was
    // submitted as a point list -- i.e. every real triangle list lost its
    // triangles, and the type that has no geometry at all invented some. The
    // mapping is therefore spelled out per code here, the same way
    // D3D12Backend::MapXenosPrimType spells out the D3D_PRIMITIVE_TOPOLOGY
    // half, and both must be derived from the xenos.h enum above -- not from
    // DrawPacket::primType's own comment, which is stale.
    //
    // UNMEASURED PREMISE (do not read the refusal log as a bug without
    // checking this first): the value that reaches here is documented as
    // `DrawPacket::primType` (pipeline_cache.h, PipelineStateInputs::primType),
    // and the only writer of that field sets it to `ctx.r4.u32 & 7`
    // (capture_hooks.cpp, `OnDrawBuild`) -- THREE bits of a build descriptor,
    // not the 5+-bit VGT_DRAW_INITIATOR.prim_type, while
    // trace_types.h's `uint32_t primType` comment claims "0=TriList,
    // 1=TriStrip". Two in-repo premises disagree and neither was measured.
    // DerivePipelineState has no caller in src/ (measured 2026-09-28: the only
    // two hits for the symbol are its own declaration and definition), so the
    // architected mapping is the only defensible one to leave in the code; the
    // first soak that wires this up must read the refusal counter below to
    // learn which premise the guest actually satisfies. A non-zero count of
    // 0x04 (kTriangleList) refusals is the signature of the stale `drawFlags`
    // reading, not of a missing D3D12 topology.
    switch (in.primType) {
        case 0x04:  // kTriangleList
        case 0x05:  // kTriangleFan
        case 0x06:  // kTriangleStrip
            s.topology = kTopoTriangle; break;
        case 0x02:  // kLineList
        case 0x03:  // kLineStrip
            s.topology = kTopoLine; break;
        case 0x01:  // kPointList
            s.topology = kTopoPoint; break;
        case 0x08:  // kRectangleList
            // F-653: THIS USED TO BE A REFUSAL, and the reason it gave was
            // correct while the conclusion was wrong. The old note read "Xenos
            // emits two triangles per rectangle with a winding contract D3D12
            // does not have; TRIANGLELIST would draw them in the wrong order,
            // silently". That is exactly right about the CONTRACT and wrong
            // about the conclusion: a contract D3D12 cannot express in a
            // topology is a reason to CARRY A GEOMETRY STAGE, not a reason to
            // refuse. The reference satisfies it in hardware in exactly that
            // way -- the rectangle-list case of TranslateGeometryShader,
            // pipeline_cache.cc:2550-2695 -- and D3D12 has geometry shaders.
            //
            // Measured, not assumed. The shape of the expansion is the thing a
            // wrong port gets wrong, so each term is cited:
            //   * the stage's INPUT primitive is a TRIANGLE of THREE vertices,
            //     pipeline_cache.cc:2300-2301. A rectangle is THREE guest
            //     vertices, and the FOURTH is generated. (The 3-of-3 direction
            //     is what primitive_processor.cc:452's `primitive_count /= 3`
            //     independently agrees with.)
            //   * the generated vertex is v1 + v2 - v0, pipeline_cache.cc:2669-2673.
            //   * max output vertex count 4, pipeline_cache.cc:2303.
            // `topology` is therefore kTopoTriangle -- the input really is
            // triangles -- and the rectangle identity lives in `geometryStage`,
            // which IS key identity (pipeline_cache.h, kGeomStageRectangleList),
            // so a rectangle draw and a triangle draw over the same two shaders
            // are two different PSOs and cannot share one.
            s.topology = kTopoTriangle;
            s.geometryStage = kGeomStageRectangleList;
            {
                // F-653: "the guest OFFERED a rectangle draw" is the denominator
                // every other rectangle counter is read against. Bounded per the
                // F-054 lesson (a soak dominated by one repeating message is
                // POISONED): n <= 8 || n % 200 == 0.
                const uint32_t n = ++s_rectangleDrawsOffered;
                if (n <= 8 || (n % 200) == 0)
                    MCLA_LOG_INFO("PC-RECT-OFFERED #{} rectangle-list draw keyed with "
                                  "the expansion geometry stage (vs/ps unchanged)",
                                  n);
            }
            break;
        // Refused, each with its own name in the log rather than a nearest
        // neighbour (the contract in this file):
        //  0x00 kNone              -- not a geometry type at all; Xenia's
        //                             translation is a zero-index draw
        //  0x07 kTriangleWithWFlags -- per-triangle W flag, which D3D12 carries
        //                             in a PS, not in a topology
        //  0x08 kRectangleList     -- F-653: NO LONGER A REFUSAL. It is the case
        //                             above now. The note that used to sit here
        //                             said "Xenos emits two triangles per
        //                             rectangle with a winding contract D3D12
        //                             does not have; TRIANGLELIST would draw
        //                             them in the wrong order, silently". Every
        //                             clause of that was true and the conclusion
        //                             drawn from it was wrong: a winding contract
        //                             D3D12 has no topology for is precisely
        //                             what a geometry stage is for, and the
        //                             reference satisfies it in one.
        //  0x0C kLineLoop          -- D3D12 has no loop topology
        //  0x0D kQuadList, 0x0E kQuadStrip, 0x0F kPolygon -- no equivalent
        //  >= 0x10                  -- k2DCopyRectListV0 onwards: explicit
        //                             major mode / 2D rect fills / tessellation
        //                             patches, none of which is a D3D12
        //                             primitive type
        default: {
            s.topology = kTopoTriangle;
            refuseMask |= kRefuseTopologyUnknown;
            // Counted per value (not globally) so a soak can name WHICH
            // unmappable type the title actually emits; bounded logging so a
            // key-churning soak cannot launder the log (the F-054 lesson).
            static std::atomic<uint32_t> s_primRefusals[kCountedPrimTypes] = {};
            const uint32_t slot = in.primType < kCountedPrimTypes ? in.primType
                                                                  : kCountedPrimTypes;
            const uint32_t n = s_primRefusals[slot].fetch_add(1) + 1;
            if (n <= 4 || (n % 200) == 0)
                MCLA_LOG_WARN("PC-PRIM-REFUSED #{} xenos primType=0x{:02X} ({}) has no "
                              "D3D12 primitive type; PSO refused, not substituted",
                              n, in.primType, XenosPrimTypeName(in.primType));
            break;
        }
    }

    // MSAA: PA_SU_SC_MODE_CNTL.msaa_enable is decoded (xr.msaaEnable) and its
    // non-zero case is counted at the decode site below, but the sample COUNT is
    // not captured -- it comes from the render target descriptor. Keeping 1 for
    // every draw means the key cannot split a draw in two over a quantity nobody
    // measured; the real count is a follow-up. This must stay BEFORE the decode,
    // because ApplyBaselineD3D12State rewrites the whole rasterizer desc.
    s.sampleCount = 1;
    ApplyBaselineD3D12State(s);  // again, now that sampleCount is final

    D3D12_RASTERIZER_DESC& r = s.d3d12.raster;
    D3D12_DEPTH_STENCIL_DESC& d = s.d3d12.depthStencil;

    if (!in.haveRegisters) {
        // No registers => no derivation. Refuse rather than hand back a
        // plausible-looking default PSO.
        refuseMask |= kRefuseStateNotDerived;
        return s;
    }

    // memcpy rather than a union/reinterpret pun: reading a uint32_t through a
    // bitfield struct is an aliasing violation, and the byte order is the host's
    // for both sides so the copy is a no-op.
    //
    // F-646: the decode moved into DecodeGuestRenderState so the bit layouts have
    // exactly one owner and a validator can reach them. It also sets
    // kRefuseNoPaSuScModeCntl / kRefuseNoPaClipCntl / kRefuseNoPaClVteCntl for
    // every register whose presence bit is clear, which is why the `su`/`cl`
    // overlays are no longer built here: with a register absent, `d.*Present` is
    // false and the corresponding state below is left at the DECLARED BASELINE
    // (never at a decoded zero) and the key already refuses.
    uint32_t regRefusals = kRefuseNone;
    const DecodedXenosRenderState xr = DecodeGuestRenderState(in, regRefusals);
    refuseMask |= regRefusals;

    // Cull: cull_front/cull_back, the direct bit mapping Xenia uses
    // (vulkan_pipeline_cache.cc:588-590).
    // F-634: `D3D12_CULL_MODE_FRONT_BACK` does not exist -- d3d12.h defines
    // NONE / FRONT / BACK only, and culling *both* faces has no D3D12
    // equivalent. That case is LOSSY, not mapped, so it is counted: a soak
    // that shows a non-zero count is telling us the title uses dual-sided
    // primitive mode and the host cannot reproduce it.
    if (!xr.suPresent) {
        // Baseline (CULL_MODE_NONE) already applied by ApplyBaselineD3D12State.
        // No default is invented and no zero is decoded.
    }
    else if (xr.cullFront && xr.cullBack) {
        r.CullMode = D3D12_CULL_MODE_NONE;
        static std::atomic<uint32_t> s_cullBoth{0};
        const uint32_t n = s_cullBoth.fetch_add(1) + 1;
        if (n <= 4 || (n % 200) == 0)
            MCLA_LOG_WARN("PC-CULL-BOTH #{} no D3D12 equivalent, using NONE", n);
    }
    else if (xr.cullBack)             r.CullMode = D3D12_CULL_MODE_BACK;
    else if (xr.cullFront)            r.CullMode = D3D12_CULL_MODE_FRONT;
    else                            r.CullMode = D3D12_CULL_MODE_NONE;

    // face: 0 => front face is CCW (registers.h:461-462).
    if (xr.suPresent)
        r.FrontCounterClockwise = xr.frontIsCw ? FALSE : TRUE;

    // Fill: poly_mode 0 renders triangles, 1 (kDualMode) honours the per-face
    // polygon types, 2/3 are undefined (xenos.h:846-853). D3D12 has no point
    // fill mode, and picking lines instead of points is a guess, so anything
    // that is not "triangles" refuses rather than silently drawing a wireframe.
    if (xr.suPresent) {
        if (xr.polyMode == 0) {
            r.FillMode = D3D12_FILL_MODE_SOLID;
        } else if (xr.polyMode == 1) {
            uint32_t polygonType = 2;  // kTriangles
            if (!xr.cullFront) polygonType = std::min(polygonType, xr.polyFrontType);
            if (!xr.cullBack)  polygonType = std::min(polygonType, xr.polyBackType);
            if (polygonType == 2) {
                r.FillMode = D3D12_FILL_MODE_SOLID;
            } else {
                // kLines could be honoured as a wireframe; kPoints cannot be
                // honoured at all. Refuse both and let the log say why.
                refuseMask |= kRefuseUnsupportedPolyMode;
                r.FillMode = D3D12_FILL_MODE_SOLID;
            }
        } else {
            refuseMask |= kRefuseUnsupportedPolyMode;
        }
    }

    // --- D1: polygon / depth offset ----------------------------------------
    // WHAT THIS USED TO SAY, and why it was worse than being wrong:
    //   "Polygon offset: the enable bits are measured; the magnitudes come from
    //    RB_DEPTH_INFO (d3d12/pipeline_cache.cc:1496-1503) which is NOT
    //    captured, so the bias magnitudes stay 0"  ... and then, further down,
    //    "The Xenos poly-offset *magnitudes* live in RB_DEPTHF_INFO".
    // Two claims, and BOTH are structurally incapable of being true:
    //   * `RB_DEPTHF_INFO` IS NOT A REGISTER. `git grep "DEPTHF" --
    //     .research/xenia/src/xenia/gpu/` = 0 hits. Neither is `PA_SU_OFFSET_*`.
    //   * `RB_DEPTH_INFO` (0x2002, register_table.inc:482) has no bias
    //     magnitude either -- registers.h:835-848 is depth_base /
    //     depth_base_bit_11 / _pad_12 / depth_format / _pad_17. The reference
    //     reads RB_DEPTH_INFO exactly ONCE in this path, and only for
    //     `depth_format` (d3d12/pipeline_cache.cc:1500-1501).
    // The magnitudes are four kFloat registers: PA_SU_POLY_OFFSET_{FRONT,BACK}_
    // {SCALE,OFFSET} at 0x2380-0x2383 (register_table.inc:615-618), read by the
    // reference at draw_util.cc:103-104, :108-109 and :115-116. They are
    // ABSOLUTE floats (draw_util.h:118-119), which is why a host that wants a
    // RELATIVE bias has to convert (draw_util.h:128-131, d3d12/pipeline_cache
    // .cc:1500-1503).
    //
    // The old behaviour was the worst of the three options the defect brief
    // allowed: it drew the geometry anyway with a zero bias. That is a
    // degradation to a default -- coplanar geometry z-fights, and nothing says
    // so. So this now either answers the query from the four real registers or
    // REFUSES, naming the registers that are absent. It never renders a
    // requested bias as zero.
    //
    // STATED PREMISE (not measured here, and not a refusal): the reference wraps
    // this whole block in `if (!edram_rov_used)` (d3d12/pipeline_cache.cc:1496).
    // `edram_rov_used` is a host RENDER-TARGET-CACHE path choice
    // (`Path::kPixelShaderInterlock`, d3d12/pipeline_cache.cc:98-99), not a
    // Xenos register, so there is nothing for this module to read and no bit to
    // name. Xenos has no render-order-view hardware, so on this guest the
    // premise is expected to be constant-false; it is recorded rather than
    // asserted.
    if (xr.suPresent && xr.polyOffsetRequested) {
        // Selection rule, reproduced from draw_util.cc:93-121. `polygonal` is
        // the already-derived topology: anything the module refused has
        // kRefuseTopologyUnknown set, and a refused key never becomes a PSO.
        const bool polygonal = (s.topology == kTopoTriangle);
        bool useFront = false;
        if (polygonal) {
            useFront = xr.polyOffsetFrontEn && !xr.cullFront;
        } else {
            // Non-polygonal primitives use the FRONT pair, gated on
            // poly_offset_para_enable instead (draw_util.cc:111-117).
            useFront = xr.polyOffsetParaEn;
        }
        // BACK is the fallback for polygonal primitives only, and only when the
        // front pair was not selected (draw_util.cc:106-110).
        const bool useBack = polygonal && !useFront && xr.polyOffsetBackEn &&
                             !xr.cullBack;
        const uint32_t neededReg =
            useFront ? kGuestRegPolyOffsetFront
                     : (useBack ? kGuestRegPolyOffsetBack : 0u);
        const bool magnitudesPresent = neededReg != 0u &&
                                       (in.registersPresent & neededReg) != 0u;
        if (!magnitudesPresent) {
            // Say WHICH of the four real registers is missing. `neededReg == 0`
            // means the guest enabled a bias the selection rule does not turn
            // into a magnitude for this primitive (e.g. front enable with
            // cull_front), which is a real, honest no-op -- but it is still not
            // a reason to render a bias, so it is logged and the draw is left
            // at zero bias only because there IS no bias to apply.
            if (neededReg == 0u) {
                static std::atomic<uint32_t> s_polyOffInert{0};
                const uint32_t n = s_polyOffInert.fetch_add(1) + 1;
                if (n <= 4 || (n % 200) == 0)
                    MCLA_LOG_WARN("PC-POLYOFF #{} PA_SU_SC_MODE_CNTL bits 11-13 request a "
                                  "bias but draw_util.cc:93-121 selects no magnitude for a "
                                  "{} primitive (front={} back={} cullFront={} cullBack={} "
                                  "para={}); the Xenos hardware likewise applies none",
                                  n, polygonal ? "polygonal" : "non-polygonal",
                                  xr.polyOffsetFrontEn ? 1 : 0,
                                  xr.polyOffsetBackEn ? 1 : 0, xr.cullFront ? 1 : 0,
                                  xr.cullBack ? 1 : 0, xr.polyOffsetParaEn ? 1 : 0);
            } else {
                refuseMask |= useFront ? kRefuseNoPolyOffsetFront
                                       : kRefuseNoPolyOffsetBack;
                CountMissingRegister(useFront ? "PA_SU_POLY_OFFSET_FRONT_SCALE+OFFSET"
                                               : "PA_SU_POLY_OFFSET_BACK_SCALE+OFFSET",
                                     useFront ? "2380-2381" : "2382-2383");
            }
        } else if (!(in.registersPresent & kGuestRegDepthInfo)) {
            // The four magnitudes are here, but the absolute->relative
            // conversion has no factor without RB_DEPTH_INFO.depth_format
            // (draw_util.h:206-215). Guessing a format would put the bias in
            // the wrong units by a factor of 8, so it refuses by name.
            refuseMask |= kRefuseNoDepthInfo;
            CountMissingRegister("RB_DEPTH_INFO", "2002");
        } else {
            const float scale = useFront ? in.polyOffsetFrontScale
                                         : in.polyOffsetBackScale;
            const float offset = useFront ? in.polyOffsetFrontOffset
                                          : in.polyOffsetBackOffset;
            r.DepthBias = static_cast<float>(
                D3D10IntegerPolygonOffset(in.depthFormat == 1u, offset));
            r.SlopeScaledDepthBias = scale * kPolygonOffsetScaleSubpixelUnit;
            r.DepthBiasClamp = 0.0f;
        }
    }

    // depth_clip = !clip_disable (d3d12/pipeline_cache.cc:1508).
    // F-646: only when PA_CL_CLIP_CNTL actually arrived. The measured value is
    // 0x00010000, i.e. clip_disable = 1, so the honest answer for this title is
    // DepthClipEnable = FALSE -- geometry outside the clip volume is NOT
    // discarded, which is why decoding this as 0 (clipping on) would have
    // clipped geometry away and looked like a bug somewhere else entirely.
    if (xr.clPresent)
        r.DepthClipEnable = xr.clipDisable ? FALSE : TRUE;

    // MSAA: paSuScModeCntl.msaa_enable is MEASURED (decoded above into
    // xr.msaaEnable) but the sample COUNT is not -- it comes from the render
    // target descriptor, which is not captured. Keeping 1 for every draw means
    // the key cannot split a draw in two over a quantity nobody measured; the
    // real count is a follow-up. F-646: the enable is now at least named, so a
    // non-zero count is attributable to the register rather than to "someone
    // guessed 1".
    if (xr.suPresent && xr.msaaEnable) {
        static std::atomic<uint32_t> s_msaaEn{0};
        const uint32_t n = s_msaaEn.fetch_add(1) + 1;
        if (n <= 4 || (n % 200) == 0)
            MCLA_LOG_WARN("PC-MSAA-EN #{} PA_SU_SC_MODE_CNTL.msaa_enable=1 but the "
                          "sample COUNT is uncaptured -- keeping 1", n);
    }

    // Depth/stencil. The ztest lives in RB_DEPTHCONTROL (0x2200): stencil_enable
    // bit 0, z_enable bit 1, z_write_enable bit 2, zfunc bits 4-6,
    // backface_enable bit 7 (registers.h:802-808), read by the reference at
    // draw_util.cc:76 and lowered at d3d12/pipeline_cache.cc:1513-1519. It does
    // NOT live in RB_DEPTH_INFO or COLOR0_INFO -- this comment used to say so,
    // and it was wrong in the same way the poly-offset comment was: both names
    // are real registers, but neither carries an enable, a write bit or a
    // compare function. (RB_DEPTH_INFO is now captured for the bias conversion
    // only; see D1 above. Its `depth_format` is not a ztest.)
    // The renderer captures none of RB_DEPTHCONTROL, so there is no measured
    // source for DepthEnable/DepthFunc/StencilEnable here. Emitting Xenia's
    // documented "no depth info" state (always-pass, no writes) is a STATED
    // placeholder, flagged so it stays
    // countable; refusing by default would keep every real PSO permanently
    // unbuildable, which is a different lie.
    s.flags |= kStateFlagUnmeasuredDepth;
    if (in.requireMeasuredDepthState) refuseMask |= kRefuseRequiredDepthState;
    if (s.depthStencilFormat == 0) {
        // D3D12 forbids DepthEnable with no depth-stencil format; fold that into
        // the key so the PSO and the key cannot disagree.
        d.DepthEnable = FALSE;
        d.StencilEnable = FALSE;
    }

    s.derivation = kStateDerivedGuest;
    return s;
}

void SetDerivedPipelineState(PipelineState& state) {
    // Fills the D3D12 state with the declared baseline when the caller has not
    // written any, so "I am taking responsibility for this state" cannot turn
    // into "D3D12_RASTERIZER_DESC was zeroed, so DepthClipEnable == FALSE and
    // every primitive is clipped away".
    if (state.sampleCount == 0) state.sampleCount = 1;
    // F-634: D3D12 has no FILL_MODE_UNSPECIFIED or CULL_MODE_UNSPECIFIED --
    // d3d12.h defines SOLID/WIREFRAME and NONE/FRONT/BACK, and the zero value
    // of each IS the solid/none case. A zero-initialised PipelineState
    // therefore reads as SOLID + NONE, so the intent of the original test
    // ("the caller wrote no raster state at all") is preserved exactly by
    // comparing against the zero enumerators instead of a name that does not
    // exist. No behaviour change.
    if (state.d3d12.raster.DepthClipEnable == FALSE &&
        state.d3d12.raster.FillMode == D3D12_FILL_MODE_SOLID &&
        state.d3d12.raster.CullMode == D3D12_CULL_MODE_NONE) {
        ApplyBaselineD3D12State(state);
    }
    if (state.derivation == kStateDerivedNone) state.derivation = kStateDerivedExplicit;
}

// ---------------------------------------------------------------------------
// Authoritative vertex-input layout
// ---------------------------------------------------------------------------
bool BuildGrcFvfInputLayout(const native::GrcFvfDeclaration& decl,
                            std::vector<D3D12_INPUT_ELEMENT_DESC>& out,
                            uint64_t* outDeclHash) {
    out.clear();
    if (outDeclHash) *outDeclHash = 0;
    if (!decl.valid || decl.unknownChannel) return false;
    // A declared stride that disagrees with the decoded one means the decode is
    // incomplete (a packed/aligned channel we do not model) and the offsets this
    // builder hands to the PSO would read the wrong bytes.
    if (decl.sizeMismatch) return false;

    native::GrcFvfLayoutEntry entries[native::kGrcFvfChannelCount];
    uint32_t count = 0;
    if (!native::BuildGrcFvfLayout(decl, entries, count)) return false;

    out.reserve(count);
    for (uint32_t i = 0; i < count; ++i) {
        D3D12_INPUT_ELEMENT_DESC e = {};
        // Explicit byteOffset, never D3D12_APPEND_ALIGNED: APPEND would
        // 4-byte-align every element, which silently reinterprets the guest
        // stride (the previous builder used APPEND for all 16 lanes) whenever a
        // channel is 2 bytes wide.
        e.AlignedByteOffset = entries[i].byteOffset;
        e.Format = static_cast<DXGI_FORMAT>(entries[i].dxgiFormat);
        e.InputSlot = 0;
        e.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        e.InstanceDataStepRate = 0;
        // SemanticName is a pointer the PSO keeps for its lifetime, so it must
        // outlive the D3D12Backend::BuildInputLayoutFromGrcFvf temporary. The
        // names come from a static table (VertexUsageSemanticName) that lives for
        // the process, which is why the builder is not a local buffer of const
        // char* the way the old per-call switch produced.
        e.SemanticName = VertexUsageSemanticName(entries[i].usage);
        e.SemanticIndex = entries[i].usageIndex;
        out.push_back(e);
    }
    if (outDeclHash) *outDeclHash = native::HashGrcFvfDeclaration(decl);
    return !out.empty();
}

uint64_t HashInputLayout(const std::vector<D3D12_INPUT_ELEMENT_DESC>& layout) {
    uint64_t h = 0xcbf29ce484222325ULL;
    auto mix = [&h](const void* data, size_t size) {
        h = HashBytes(data, size, h);
    };
    for (const auto& e : layout) {
        const uint32_t fields[5] = {e.SemanticIndex, static_cast<uint32_t>(e.Format),
                                   e.AlignedByteOffset, e.InputSlot,
                                   static_cast<uint32_t>(e.InputSlotClass)};
        mix(fields, sizeof(fields));
        const uint32_t step = e.InstanceDataStepRate;
        mix(&step, sizeof(step));
        if (e.SemanticName) {
            const uint32_t len = static_cast<uint32_t>(std::strlen(e.SemanticName));
            mix(&len, sizeof(len));
            h = HashBytes(e.SemanticName, len, h);
        }
    }
    const uint32_t n = static_cast<uint32_t>(layout.size());
    mix(&n, sizeof(n));
    return h;
}

// ---------------------------------------------------------------------------
// Xenos constant bank
// ---------------------------------------------------------------------------
ConstantBankPack PackXenosConstantBank(const uint8_t* guestBeBytes, size_t guestBytes,
                                       uint8_t* dstBank, size_t dstBytes) {
    ConstantBankPack r = {};
    if (!dstBank || dstBytes < 16) return r;
    // Zeros first, so a short guest bank cannot leak whatever was in the
    // previous frame's upload ring.
    std::memset(dstBank, 0, dstBytes);

    const size_t usable = std::min(guestBytes, dstBytes);
    r.guestBytes = static_cast<uint32_t>(std::min(guestBytes, dstBytes));
    r.truncated = guestBytes > dstBytes;

    for (size_t off = 0; off + 16 <= usable; off += 16) {
        float f[4];
        for (uint32_t c = 0; c < 4; ++c) {
            // Explicit big-endian assembly per the project rule: a guest pointer
            // is a 32-bit guest VA and Xenos floats are stored big-endian, so
            // every 4-byte group is assembled by hand rather than aliased.
            const uint8_t* p = guestBeBytes + off + c * 4;
            const uint32_t be = (static_cast<uint32_t>(p[0]) << 24) |
                                (static_cast<uint32_t>(p[1]) << 16) |
                                (static_cast<uint32_t>(p[2]) << 8) |
                                 static_cast<uint32_t>(p[3]);
            uint32_t le;
            std::memcpy(&le, &be, sizeof(le));
            std::memcpy(&f[c], &le, sizeof(f[c]));
        }
        std::memcpy(dstBank + off, f, 16);
        ++r.registersPacked;
    }
    const size_t covered = static_cast<size_t>(r.registersPacked) * 16;
    r.zeroFilledBytes = static_cast<uint32_t>(dstBytes - covered);
    r.ok = true;
    return r;
}

ConstantBankBinding ResolveConstantBankBinding(const DxcRuntime::CbvBinding& cbv) {
    ConstantBankBinding b = {};
    b.shaderRegister = cbv.register_;
    b.space = cbv.space_;
    b.requiredBytes = cbv.byteSize;
    // F-644: the CBV is root parameter 2, not 1. CreateTestRootSignature
    // (d3d12_backend.cpp, symbol `CreateTestRootSignature`, `D3D12_ROOT_PARAMETER
    // rootParams[3]`) declares THREE root parameters: 0 = SRV descriptor table
    // t0..t3, 1 = SAMPLER descriptor table (1 descriptor, s0, space 0), 2 = CBV
    // b0 space 0. The sampler used to be a D3D12_STATIC_SAMPLER_DESC at s0
    // (NumStaticSamplers 1) and is now a descriptor table, which pushed the CBV
    // from 1 to 2; the draw path binds it with
    // SetGraphicsRootConstantBufferView(2, ...), so naming 1 here would make
    // every real PSO report an invalid binding and refuse (kRefuseNoRootSignature).
    // Nothing else in this file hardcodes the index, so there is no second site
    // to change: the worker never describes or creates a root signature of its
    // own. It is HANDED the backend's -- `PipelineCache::StartWorker`'s
    // `rootSignature` argument, which lands in `WorkerLoop` and is copied
    // straight into `psoDesc.pRootSignature = rootSignature.Get()` in the
    // compile block below. A future reader looking for a second edit here should
    // look at the draw path's SetGraphicsRootConstantBufferView index instead.
    if (cbv.space_ == 0 && cbv.register_ == kShaderConstantRootRegister) {
        b.rootParameter = kShaderConstantRootSlot;
        b.valid = 1;
    }
    return b;
}

// PipelineCache implementation

PipelineCache::PipelineCache(std::size_t maxEntries) : maxEntries_(maxEntries) {
    map_.reserve(maxEntries_);
    order_.reserve(maxEntries_);
}

PipelineCache::~PipelineCache() {
    StopWorker();
}

void PipelineCache::StartWorker(Microsoft::WRL::ComPtr<ID3D12Device> device,
                                Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature) {
    std::lock_guard<std::mutex> lock(queueMutex_);
    if (workerThread_.joinable()) return;

    device_ = device;
    rootSignature_ = rootSignature;
    stopWorker_ = false;
    workerThread_ = std::thread(&PipelineCache::WorkerLoop, this, device_, rootSignature_);
}

void PipelineCache::StopWorker() {
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        stopWorker_ = true;
        queueCv_.notify_all();
    }
    if (workerThread_.joinable()) {
        workerThread_.join();
    }
}

bool PipelineCache::RefuseOnce(const PipelineKey& key, uint32_t reason,
                               const char* caller, const char* detail) {
    uint64_t keyHash = HashPipelineKey(key);
    bool print = false;
    {
        std::lock_guard<std::mutex> lock(statsMutex_);
        ++stats_.refusals;
        for (uint32_t bit = 0; bit < 32; ++bit)
            if (reason & (1u << bit)) ++stats_.refusalsByReason[bit];
        // F-646: the two aggregates a future soak's gate reads, so the gate does
        // not have to sum bits itself and cannot disagree with the loop above.
        if (reason & (kRefuseNoPaSuScModeCntl | kRefuseNoPaClipCntl |
                      kRefuseNoPaClVteCntl))
            ++stats_.missingRegisters;
        if (reason & kRefuseViewportExtentsUnmeasured)
            ++stats_.viewportUnresolved;
        // D1: the depth-bias magnitudes are a different kind of gap from a
        // missing rasteriser register, and the gate reads them apart.
        if (reason & (kRefuseNoPolyOffsetFront | kRefuseNoPolyOffsetBack |
                      kRefuseNoDepthInfo))
            ++stats_.polyOffsetUnresolved;
        // Bounded: the set is capped so a key-churning soak cannot grow it, and
        // so a soak is never dominated by one repeating refusal line (the
        // F-054 lesson).
        if (refusedKeys_.size() < kMaxRefusalKeys)
            print = refusedKeys_.insert(key).second;
    }
    if (print) {
        char reasonText[256] = {};
        FormatPipelineRefusal(reason, reasonText, sizeof(reasonText));
        std::fprintf(stderr,
                     "PipelineCache: REFUSING pipeline key=%016llX vs=%016llX ps=%016llX "
                     "decl=%016llX layout=%016llX topo=%u reason=%s caller=%s%s%s\n",
                     static_cast<unsigned long long>(keyHash),
                     static_cast<unsigned long long>(key.vsHash),
                     static_cast<unsigned long long>(key.psHash),
                     static_cast<unsigned long long>(key.vertexDeclHash),
                     static_cast<unsigned long long>(key.inputLayoutHash),
                     key.state.topology, reasonText, caller ? caller : "?",
                     detail ? " -- " : "", detail ? detail : "");
    }
    return print;
}

namespace {

// ---------------------------------------------------------------------------
// Which PS input semantics does no earlier stage produce?
// ---------------------------------------------------------------------------
// F-692 measured on build/w693_err.log (sha256 566788266910bc57e...c98): the
// refusal there read `reason=empty-hlsl -- CreateGraphicsPipelineState failed`
// while the HLSL for both stages was present and DXC had returned
// `failed=0`. The refusal misdescribed its own cause, which is a defect in
// itself.
//
// The cause, measured offline with the real translator, the real DXC and a real
// D3D12 device (harness `h2`/`h3`/`h4` under
// %TEMP%\opencode\pso, 2026-10-02):
//   VS program AEAF1F096E09B347  decodes to TWO instructions:
//       FETCH VertexFetch vfmt=0x25 dst=0x000
//       ALU  vecDest=0x03E EXPORT=1 vwMask=0xF
//   -- one export, and its destination register is 0x3E = 62, the Xenos position
//   export. PS program 7B0032AD4C5B576D decodes to ONE instruction,
//   `vecDest=0x000 EXPORT=1` (colour 0), and its interpolator table -- derived
//   from its own instruction stream, `interpolatorsDerived=1` -- is
//   `{usage=5 usageIndex=0 address=0 reg=0}` i.e. one input semantic TEXCOORD0.
//   So the pixel shader reads an interpolator the vertex shader never exports.
//   D3D12 links stage signatures by semantic name+index, so that input has no
//   producer and CreateGraphicsPipelineState returns 0x80070057.
//
//   Attribution, one fact changed at a time, same descriptor, same device:
//       real VS + real PS                       -> 0x80070057  (fails)
//       real VS + real PS minus its TEXCOORD0   -> 0x00000000  (PSO returned)
//       real VS plus a TEXCOORD0 output + realPS-> 0x00000000  (PSO returned)
//
// THIS FUNCTION IS THE DIAGNOSTIC, not a fix. It reports the unproduced names so
// the refusal can name its cause instead of guessing at one. It NEVER edits a
// signature: the fix is to pair a vertex program that exports the interpolator
// the pixel program reads, which is a decision about the DRAW, not about this
// cache.
struct StageSemantics {
    // "NAME" for NAME in {SV_Position, TEXCOORD0, ...} -- the form D3D12 links
    // by. SV_* names are system values: D3D12 supplies SV_Position to a pixel
    // shader from the rasteriser and takes SV_Position from a vertex shader, so
    // they are never reported as unproduced.
    std::vector<std::string> names;
    bool has(const std::string& n) const {
        for (const auto& x : names) if (x == n) return true;
        return false;
    }
};

// Parse the `: NAME` out of one `in`/`out` parameter line. Only the shapes this
// project's own translator emits are recognised (shader_translator.cpp:676-681
// for the VS signature, :698-706 for the PS signature); an unrecognised line is
// NOT claimed as a semantic, so a parser change can only ever lose evidence.
bool SemanticFromParamLine(std::string_view line, std::string* out) {
    const size_t colon = line.rfind(':');
    if (colon == std::string_view::npos) return false;
    std::string_view tail = line.substr(colon + 1);
    while (!tail.empty() && (tail.front() == ' ' || tail.front() == '\t')) tail.remove_prefix(1);
    // Strip the trailing comma / brace / comment.
    size_t end = 0;
    while (end < tail.size() &&
           ((tail[end] >= 'A' && tail[end] <= 'Z') || (tail[end] >= 'a' && tail[end] <= 'z') ||
            (tail[end] >= '0' && tail[end] <= '9') || tail[end] == '_')) {
        ++end;
    }
    if (end == 0) return false;
    out->assign(tail.substr(0, end));
    return true;
}

StageSemantics CollectSemantics(std::string_view hlsl, bool vertexStage) {
    StageSemantics s;
    size_t pos = 0;
    while (pos < hlsl.size()) {
        const size_t eol = hlsl.find('\n', pos);
        const std::string_view line =
            hlsl.substr(pos, (eol == std::string_view::npos ? hlsl.size() : eol) - pos);
        pos = (eol == std::string_view::npos) ? hlsl.size() : eol + 1;
        // A parameter line, not a statement: it must start with in/out after
        // leading spaces, and must not contain '=' (a body line would).
        size_t i = 0;
        while (i < line.size() && (line[i] == ' ' || line[i] == '\t')) ++i;
        const bool isIn = line.compare(i, 3, "in ") == 0;
        const bool isOut = line.compare(i, 4, "out ") == 0;
        if (!isIn && !isOut) continue;
        if (line.find('=') != std::string_view::npos) continue;
        std::string name;
        if (!SemanticFromParamLine(line, &name)) continue;
        if (vertexStage && !isOut) continue;   // a VS's `in` is the input layout
        if (!vertexStage && !isIn) continue;    // a PS's `out` is the RT
        s.names.push_back(name);
    }
    return s;
}

bool IsSystemValue(const std::string& n) {
    return n.rfind("SV_", 0) == 0;
}

// Names a PS input that no earlier stage's output produces. `produced` is the
// union of the VS output set and, when a geometry stage is bound, the stage's
// own output set -- which this module writes from the VS's set verbatim
// (BuildRectangleGeometryShaderHlsl), so the VS set IS the GS set.
std::vector<std::string> UnproducedPixelInputs(const StageSemantics& vsOut,
                                               const StageSemantics& psIn) {
    std::vector<std::string> missing;
    for (const auto& n : psIn.names) {
        if (IsSystemValue(n)) continue;   // D3D12 supplies/withdraws these
        if (vsOut.has(n)) continue;
        missing.push_back(n);
    }
    return missing;
}

std::string JoinNames(const std::vector<std::string>& v) {
    if (v.empty()) return "none";
    std::string out;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) out += "|";
        out += v[i];
    }
    return out;
}

// ONE line, bounded (first 4 then every 200th) so a soak can count it without
// the log becoming the fault -- the F-054 lesson, applied to the new marker.
void LogPsoCreateFailed(HRESULT hr, size_t vsDxilBytes, size_t psDxilBytes,
                        size_t gsDxilBytes, bool wantGeomStage,
                        const std::vector<std::string>& unproduced,
                        const StageSemantics& vsOut, const StageSemantics& psIn) {
    static std::atomic<uint32_t> s_psoFail{0};
    const uint32_t n = s_psoFail.fetch_add(1) + 1;
    if (!(n <= 4 || (n % 200) == 0)) return;
    char hrText[16] = {};
    std::snprintf(hrText, sizeof(hrText), "0x%08lX", static_cast<unsigned long>(hr));
    MCLA_LOG_WARN("PC-PSO-CREATE-FAILED #{}: hr={} vsDxil={} psDxil={} gsDxil={} "
                  "geomStage={} psInputs={} vsOutputs={} unproduced={} -- "
                  "CreateGraphicsPipelineState rejected the pipeline. DXC "
                  "reported no diagnostic for either stage (PC-TRANSLATE "
                  "failed=0), so the cause is a D3D12 stage-signature link, not "
                  "a compile. Each name in unproduced is a pixel-shader INPUT "
                  "with no producing output in the vertex signature (or in the "
                  "geometry stage, whose output this module writes from that "
                  "same set). NOT patched here: pairing a vertex program that "
                  "exports the interpolator the pixel program reads is a "
                  "decision about the draw, and inventing either side would "
                  "fabricate guest data",
                  n, hrText, vsDxilBytes, psDxilBytes,
                  wantGeomStage ? gsDxilBytes : 0, wantGeomStage ? 1 : 0,
                  JoinNames(psIn.names), JoinNames(vsOut.names),
                  JoinNames(unproduced));
}

}  // namespace

void PipelineCache::WorkerLoop(Microsoft::WRL::ComPtr<ID3D12Device> device,
                               Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature) {
    // DXC COM compiler objects are not thread-safe; the worker owns one runtime
    // for its lifetime, lazily loaded on the first task.
    DxcRuntime dxc;
    bool dxcLoaded = false;
    // Latched on the first load failure so a missing dxcompiler.dll produces ONE
    // loud line instead of one full error text per queued draw.
    bool dxcDead = false;

    // F-716: publish liveness under queueMutex_, which is the only lock
    // GetOrCompile's waiter and this thread both take when reading/writing it.
    // Set BEFORE the first wait so a task queued immediately after StartWorker
    // does not see "not alive" and refuse a PSO that is about to exist.
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        workerAlive_ = true;
    }

    while (true) {
        CompileTask task;
        {
            std::unique_lock<std::mutex> lock(queueMutex_);
            queueCv_.wait(lock, [this] { return stopWorker_ || !taskQueue_.empty(); });
            if (stopWorker_ && taskQueue_.empty()) {
                // F-716: only now, with the queue provably drained, is it true
                // that no queued task will ever be fulfilled. Cleared under the
                // SAME lock the waiter reads, so the two cannot disagree.
                workerAlive_ = false;
                return;
            }
            if (taskQueue_.empty()) continue;
            task = std::move(taskQueue_.front());
            taskQueue_.pop();
        }

        // F-716: drop this key's in-flight future when the task ends, whatever
        // path it took. A waiter that already copied the shared_future keeps a
        // live reference, so erasing here cannot break a wait in progress; it
        // only stops the map growing for every key the run ever saw.
        struct DropInflightFuture {
            PipelineCache* self;
            PipelineKey key;
            ~DropInflightFuture() {
                std::lock_guard<std::mutex> lock(self->inflightMutex_);
                self->inflightFutures_.erase(key);
            }
        } dropInflightFuture{this, task.key};

        // Everything below is a refusal path or a success. A failure NEVER
        // reaches Insert() and never caches a null PSO: a cached failure would
        // make every later lookup of this key report a hit on nothing.
        auto failTask = [&](uint32_t reason, const char* detail) {
            RefuseOnce(task.key, reason, "pipeline_cache.cpp:WorkerLoop", detail);
            {
                std::lock_guard<std::mutex> lock(queueMutex_);
                pendingKeys_.erase(task.key);
            }
            task.promise.set_value(nullptr);
        };

        if (!device) {
            failTask(kRefuseNoDevice, "worker has no ID3D12Device (StartWorker device was null)");
            continue;
        }
        if (!rootSignature) {
            // The worker must NOT build a private root signature here. The
            // command list binds the backend's root signature at draw time
            // (d3d12_backend.cpp:1457 SetGraphicsRootSignature(m_rootSignature)),
            // so a PSO built against a different one describes descriptor tables
            // that do not exist when the draw executes.
            failTask(kRefuseNoRootSignature,
                     "StartWorker was given no root signature; refusing to fabricate one");
            continue;
        }
        if (task.vsHlsl.empty() || task.psHlsl.empty()) {
            failTask(kRefuseEmptyHlsl, "no translated HLSL for a stage");
            continue;
        }
        if (task.inputLayout.empty()) {
            failTask(kRefuseEmptyInputLayout, "no input layout for a VS-bearing pipeline");
            continue;
        }
        if (task.key.refuseMask != kRefuseNone) {
            failTask(task.key.refuseMask, "key carries a refusal from ComputePipelineKey");
            continue;
        }
        if (HashInputLayout(task.inputLayout) != task.key.inputLayoutHash) {
            // The layout handed to the PSO is not the layout the key hashed.
            failTask(kRefuseLayoutDeclHashMismatch,
                     "input layout changed after ComputePipelineKeyForLayout");
            continue;
        }

        if (!dxcLoaded && !dxcDead) {
            std::string usedDir, error;
            if (!dxc.Load("", usedDir, error)) {
                dxcDead = true;
                {
                    std::lock_guard<std::mutex> lock(statsMutex_);
                    ++stats_.dxcUnavailable;
                }
                // One loud, complete line: every real PSO for the rest of the
                // process will be missing, so this must not look like a
                // per-draw hiccup.
                std::fprintf(stderr,
                             "PipelineCache: FATAL no DXC runtime -- %s. Every real pipeline "
                             "will stay on the test PSO for the life of the process. Set "
                             "MCLA_DXC_DIR to a directory holding dxil.dll + dxcompiler.dll, "
                             "or place them beside mcla.exe (see dxc_runtime.h).\n",
                             error.c_str());
                std::fflush(stderr);
                failTask(kRefuseNoDevice, "DXC runtime unavailable (see the FATAL line above)");
                continue;
            }
            dxcLoaded = true;
            std::fprintf(stderr, "PipelineCache: DXC runtime loaded from %s\n", usedDir.c_str());
        }
        if (dxcDead) {
            failTask(kRefuseNoDevice, "DXC runtime unavailable (latched)");
            continue;
        }

        std::vector<uint8_t> vsDxil, psDxil;
        std::string error;
        // Compile WITH reflection data: the CBV slots drive both the constant
        // upload (PackXenosConstantBank) and the refusal when a shader binds a
        // resource the shared root signature does not declare.
        if (!dxc.Compile(task.vsHlsl, "main", DxcRuntime::kVertexProfile, vsDxil, error, true)) {
            {
                std::lock_guard<std::mutex> lock(statsMutex_);
                ++stats_.compileFailures;
            }
            RefuseOnce(task.key, kRefuseEmptyHlsl, "pipeline_cache.cpp:WorkerLoop(vs)",
                       error.c_str());
            {
                std::lock_guard<std::mutex> lock(queueMutex_);
                pendingKeys_.erase(task.key);
            }
            task.promise.set_value(nullptr);
            continue;
        }
        if (!dxc.Compile(task.psHlsl, "main", DxcRuntime::kPixelProfile, psDxil, error, true)) {
            {
                std::lock_guard<std::mutex> lock(statsMutex_);
                ++stats_.compileFailures;
            }
            RefuseOnce(task.key, kRefuseEmptyHlsl, "pipeline_cache.cpp:WorkerLoop(ps)",
                       error.c_str());
            {
                std::lock_guard<std::mutex> lock(queueMutex_);
                pendingKeys_.erase(task.key);
            }
            task.promise.set_value(nullptr);
            continue;
        }

        // Reflect CBV bindings from both stages and check them against the root
        // signature the draw path binds (t0..t3, b0, s0).
        std::vector<DxcRuntime::ResourceBinding> vsRes, psRes;
        if (!dxc.ReflectBindings(vsDxil, vsRes, error) ||
            !dxc.ReflectBindings(psDxil, psRes, error)) {
            std::fprintf(stderr, "PipelineCache: reflection failed: %s\n", error.c_str());
        }
        std::vector<ConstantBankBinding> bindings;
        uint32_t resourceRefusal = kRefuseNone;
        for (const std::vector<DxcRuntime::ResourceBinding>* stage : {&vsRes, &psRes}) {
            for (const auto& res : *stage) {
                if (res.type == DxcRuntime::kSitSampler) {
                    if (res.register_ != kShaderSamplerRegister || res.space_ != 0)
                        resourceRefusal |= kRefuseSamplerRegister;
                    continue;
                }
                if (res.type == DxcRuntime::kSitCbuffer) {
                    const ConstantBankBinding b =
                            ResolveConstantBankBinding(DxcRuntime::CbvBinding{
                                res.register_, res.space_, res.byteSize, res.firstVariableRegister});
                    if (!b.valid) {
                        resourceRefusal |= kRefuseNoRootSignature;
                    } else {
                        bindings.push_back(b);
                    }
                    continue;
                }
                // SRV (and anything else): must live inside the t0..t3 table.
                if (res.type == DxcRuntime::kSitTexture ||
                    res.type == DxcRuntime::kSitStructuredBuffer ||
                    res.type == DxcRuntime::kSitByteAddressBuffer) {
                    if (res.space_ != 0 || res.register_ >= kShaderTextureSlotCount)
                        resourceRefusal |= kRefuseOverTextureSlots;
                }
            }
        }
        if (resourceRefusal != kRefuseNone) {
            failTask(resourceRefusal,
                     "reflected resource is outside the shared root signature (t0..t3, b0, s0)");
            continue;
        }
        // A VS that declares no CBV still reads ShaderConstants in the generated
        // HLSL body, so the draw path always binds b0; record it so the bind
        // change is uniform.
        if (bindings.empty()) {
            bindings.push_back(ResolveConstantBankBinding(
                DxcRuntime::CbvBinding{kShaderConstantRootRegister, 0, 0, 0}));
        }

        // F-653: the geometry stage, if this key asks for one. Built and
        // compiled HERE, before the PSO, because a PSO that names a stage it
        // does not have is not a smaller mistake than no PSO at all: it is the
        // rectangle draw going through unexpanded, which is the exact outcome
        // the old 0x08 refusal was avoiding, except now with no log line.
        std::vector<uint8_t> gsDxil;
        const bool wantGeomStage = task.key.state.geometryStage != kGeomStageNone;
        if (wantGeomStage) {
            // F-653: the MEASURED device capability gates this, not an
            // assumption about the requested feature level. See
            // SetGeometryStageSupported: the default is false, so a cache nobody
            // told refuses rectangles rather than compiling a PSO the runtime
            // would reject.
            if (!geometryStageSupported_) {
                static std::atomic<uint32_t> s_noGs = {};
                const uint32_t n = s_noGs.fetch_add(1) + 1;
                if (n <= 4 || (n % 200) == 0)
                    MCLA_LOG_WARN("PC-RECT-GS-UNSUPPORTED #{}: this device was "
                                  "measured below the feature level a geometry "
                                  "stage requires (11_0), so the rectangle draw is "
                                  "REFUSED, not drawn unexpanded",
                                  n);
                failTask(kRefuseGeometryStageUnsupported,
                         "pipeline_cache.cpp:WorkerLoop(gs): device measured "
                         "without geometry-stage support");
                continue;
            }
            if (task.key.state.geometryStage != kGeomStageRectangleList) {
                // A geometryStage value this build does not implement. Refused
                // rather than treated as "no stage", because "no stage" is a
                // different pipeline and would be served from the wrong cache
                // entry without a word.
                failTask(kRefuseGeometryStageUnsupported,
                         "pipeline_cache.cpp:WorkerLoop(gs): unknown geometry stage");
                continue;
            }
            const std::string gsHlsl =
                BuildRectangleGeometryShaderHlsl(task.vsHlsl,
                                                 "pipeline_cache.cpp:WorkerLoop(gs)");
            if (gsHlsl.empty()) {
                {
                    std::lock_guard<std::mutex> lock(statsMutex_);
                    ++stats_.geomStageUnbuildable;
                }
                failTask(kRefuseGeometryShaderUnbuildable,
                         "pipeline_cache.cpp:WorkerLoop(gs): stage HLSL not derivable "
                         "from the translated VS output signature");
                continue;
            }
            std::string gsError;
            // kGeometryProfile is "gs_6_0" (pipeline_cache.h), NOT
            // DxcRuntime::kVertexProfile: handing dxc a vertex profile for a
            // shader that declares `maxvertexcount` compiles to something that
            // is not a geometry shader, or fails outright.
            if (!dxc.Compile(gsHlsl, "main", kGeometryProfile, gsDxil, gsError, true)) {
                {
                    std::lock_guard<std::mutex> lock(statsMutex_);
                    ++stats_.geomStageCompileFailed;
                }
                {
                    static std::atomic<uint32_t> s_gsFail = {};
                    const uint32_t n = s_gsFail.fetch_add(1) + 1;
                    if (n <= 4 || (n % 200) == 0)
                        MCLA_LOG_WARN("PC-RECT-GS-COMPILE-FAILED #{}: {} "
                                      "(-- profile {})",
                                      n, gsError, kGeometryProfile);
                }
                failTask(kRefuseGeometryShaderUnbuildable,
                         "pipeline_cache.cpp:WorkerLoop(gs): stage did not compile");
                continue;
            }
        }

        Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
        const PipelineState& st = task.key.state;
        {
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            // The root signature is the BACKEND'S, handed to StartWorker by
            // D3D12Backend::CreateTestRootSignature and threaded through
            // WorkerLoop; this module never describes or serialises one, so
            // F-644's parameter reorder needs no edit here -- only the index
            // ConstantBankBinding::rootParameter names has to move.
            psoDesc.pRootSignature = rootSignature.Get();
            psoDesc.VS = { vsDxil.data(), vsDxil.size() };
            psoDesc.PS = { psDxil.data(), psDxil.size() };
            // F-653: the expansion stage. Set only when the key named one, and
            // only from a blob that compiled above -- there is no path here that
            // binds a stage it does not hold, and no path that silently omits
            // one the key asked for.
            if (wantGeomStage) {
                psoDesc.GS = { gsDxil.data(), gsDxil.size() };
            }
            psoDesc.InputLayout = { task.inputLayout.data(),
                                    static_cast<UINT>(task.inputLayout.size()) };
            switch (st.topology) {
                case 1:  psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE; break;
                case 2:  psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT; break;
                default: psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; break;
            }
            // Target formats come from the KEY, not from a hardcoded
            // R8G8B8A8_UNORM: a PSO whose RT format disagrees with the RTV it is
            // used with is rejected by the runtime, and one that agrees by luck
            // is not something to rely on.
            UINT numRt = 0;
            for (UINT i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i) {
                psoDesc.RTVFormats[i] = static_cast<DXGI_FORMAT>(st.targetFormats[i]);
                if (psoDesc.RTVFormats[i] != DXGI_FORMAT_UNKNOWN) ++numRt;
            }
            if (numRt == 0) {
                // No render target in the key. Substituting a format here would
                // build a PSO the key does not name (and a D3D12 PSO with zero RTs
                // cannot be used with a bound RTV anyway).
                // F-692, FIRST SITE: this used to refuse as kRefuseEmptyHlsl, so
                // the log said `reason=empty-hlsl` for a key whose HLSL is
                // present and whose stages compiled (PC-TRANSLATE failed=0).
                // F-716 supplies the true bit: no PSO exists for this key.
                RefuseOnce(task.key, kRefusePsoCreateFailed, "pipeline_cache.cpp:WorkerLoop(pso)",
                           "key names no render target format: every entry of "
                           "D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT is "
                           "DXGI_FORMAT_UNKNOWN, so the PSO would declare zero RTs");
                {
                    std::lock_guard<std::mutex> lock(queueMutex_);
                    pendingKeys_.erase(task.key);
                }
                task.promise.set_value(nullptr);
                continue;
            }
            psoDesc.NumRenderTargets = numRt;
            psoDesc.DSVFormat = static_cast<DXGI_FORMAT>(st.depthStencilFormat);
            psoDesc.SampleDesc.Count = st.sampleCount ? st.sampleCount : 1;
            psoDesc.SampleMask = UINT_MAX;
            psoDesc.RasterizerState = st.d3d12.raster;  // verbatim from the key
            psoDesc.BlendState = st.d3d12.blend;
            psoDesc.DepthStencilState = st.d3d12.depthStencil;
            if (psoDesc.DSVFormat == DXGI_FORMAT_UNKNOWN &&
                psoDesc.DepthStencilState.DepthEnable) {
                // D3D12: DepthEnable must be FALSE with no depth format bound.
                // DerivePipelineState already folds this into the key, so a
                // mismatch here means a hand-built state: refuse rather than
                // silently patch the PSO into something the key does not name.
                // F-692, SECOND SITE: same defect as the site above -- a self-inconsistent
                // KEY, not missing HLSL. F-716 supplies the true bit.
                RefuseOnce(task.key, kRefusePsoCreateFailed, "pipeline_cache.cpp:WorkerLoop(pso)",
                           "key state has DepthEnable=TRUE with DSVFormat="
                           "DXGI_FORMAT_UNKNOWN, which D3D12 forbids; DerivePipelineState "
                           "folds this together, so the state was hand-built");
                {
                    std::lock_guard<std::mutex> lock(queueMutex_);
                    pendingKeys_.erase(task.key);
                }
                task.promise.set_value(nullptr);
                continue;
            }

            HRESULT hr = device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&pso));
            if (FAILED(hr) || !pso) {
                {
                    std::lock_guard<std::mutex> lock(statsMutex_);
                    ++stats_.compileFailures;
                    // F-653: a PSO that named a geometry stage and did not come
                    // back is a DIFFERENT failure from a PSO that named none --
                    // the stage is what the driver refused, most often because
                    // the device has no geometry stage at that feature level.
                    // Counted here so "stage created" and "stage refused" cannot
                    // be confused with "stage never attempted".
                    if (wantGeomStage) ++stats_.geomStageCompileFailed;
                }
                // F-692 fix. The reason this site used is the point of the fix:
                // both stages translated, DXC returned failed=0, and the blob it
                // produced was handed over -- so "empty-hlsl" was FALSE and the
                // refusal misdescribed its own cause. What is measured instead is
                // the stage-signature link, read out of the two HLSL sources
                // this task already holds.
                const StageSemantics vsOut = CollectSemantics(task.vsHlsl, true);
                const StageSemantics psIn = CollectSemantics(task.psHlsl, false);
                // A geometry stage writes its output names from the VS's own set
                // (BuildRectangleGeometryShaderHlsl), so the VS set is also the
                // GS set and the comparison below is the same either way.
                const std::vector<std::string> unproduced =
                    UnproducedPixelInputs(vsOut, psIn);
                LogPsoCreateFailed(hr, vsDxil.size(), psDxil.size(), gsDxil.size(),
                                   wantGeomStage, unproduced, vsOut, psIn);

                // F-692, THIRD SITE -- and the one the ledger entry is named for.
                // Every one of the 21 bits that existed before F-716 names a
                // CAUSE, and none of them is "CreateGraphicsPipelineState said
                // no". kRefuseEmptyHlsl is the closest by accident and is FALSE:
                // both HLSL sources are present and both compiled. So this line
                // used to print `reason=empty-hlsl` over a failure that has
                // nothing to do with HLSL. F-716 adds kRefusePsoCreateFailed
                // (pipeline_cache.h), which claims only what was measured -- the
                // PSO does not exist -- and leaves the diagnosis to this detail.
                //
                // The bit CHANGED, so a soak that gated on emptyHlsl for this
                // case was gating on a lie. psoCreateFailed is the new column and
                // a census must read it, not emptyHlsl.
                char detail[768] = {};
                if (unproduced.empty()) {
                    std::snprintf(detail, sizeof(detail),
                                  "CreateGraphicsPipelineState failed hr=0x%08lX; the "
                                  "VS output set and the PS input set both read as "
                                  "linkable, so the link is not the cause and the "
                                  "descriptor or the device is -- see "
                                  "PC-PSO-CREATE-FAILED",
                                  static_cast<unsigned long>(hr));
                } else {
                    std::snprintf(detail, sizeof(detail),
                                  "CreateGraphicsPipelineState failed hr=0x%08lX; "
                                  "pixel-shader input(s) with no producing output: "
                                  "%s (psInputs=%s vsOutputs=%s). Read "
                                  "PC-PSO-CREATE-FAILED",
                                  static_cast<unsigned long>(hr),
                                  JoinNames(unproduced).c_str(),
                                  JoinNames(psIn.names).c_str(),
                                  JoinNames(vsOut.names).c_str());
                }
                RefuseOnce(task.key, kRefusePsoCreateFailed,
                           "pipeline_cache.cpp:WorkerLoop(pso)", detail);
                {
                    std::lock_guard<std::mutex> lock(queueMutex_);
                    pendingKeys_.erase(task.key);
                }
                task.promise.set_value(nullptr);
                continue;
            }
        }

        {
            std::lock_guard<std::mutex> lock(statsMutex_);
            if (st.flags & kStateFlagUnmeasuredDepth) ++stats_.unmeasuredDepthState;
            // F-653: "the geometry stage WAS created". The single most
            // important rectangle number, because geomStageCreated == 0 with
            // rectangleDrawsOffered > 0 is a black rectangle area with nothing
            // in the log to say why -- the exact difference between "this device
            // has no geometry stage" and "this draw never bound one".
            if (wantGeomStage) ++stats_.geomStageCreated;
        }

        // Insert into cache, record the CBV slots for the draw path, clear the
        // in-flight marker and fulfil the promise.
        task.cbvBindings = bindings;
        Insert(task.key, pso);
        {
            std::lock_guard<std::mutex> lock(mapMutex_);
            cbvBindings_[task.key] = bindings;
        }
        {
            std::lock_guard<std::mutex> lock(queueMutex_);
            pendingKeys_.erase(task.key);
        }
        task.promise.set_value(pso);
    }
}

// F-653: how many vertices the rectangle stage emits per invocation.
//
// The reference emits FOUR (pipeline_cache.cc:2390, dcl_maxVertexCount 4,
// value from :2303) as a TRIANGLE STRIP.
//
// F-716 CORRECTION: the second sentence said the strip "is consumed by the
// primitive processor's builtin index buffer with primitive reset enabled
// (primitive_processor.cc:454-459, GetTwoTriangleStripIndexCount)". That is the
// VS-EXPANSION path, and D3D12 does not take it: expand_rectangle_lists_in_vs_
// is false for this backend (d3d12_primitive_processor.cc:31 ->
// primitive_processor.cc:125-126), so :392-397 is skipped, host_primitive_reset_
// enabled stays false (:441), and IBStripCutValue is
// D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED (pipeline_cache.cc:1372, :2836).
// The strip is assembled and terminated entirely inside the geometry stage, and
// the draw is a plain TRIANGLELIST of num_indices vertices
// (d3d12_command_processor.cc:2309, :2338-2339). Four out is right; the consumer
// named here was not the one this backend uses.
//
// D3D12 geometry stages CANNOT emit a strip. A D3D12 geometry shader's output
// topology is one of exactly three values -- POINT / LINE / TRIANGLE
// (D3D12_PRIMITIVE_TOPOLOGY_TYPE) -- and HLSL offers only PointStream,
// LineStream and TriangleStream as output primitives. There is no strip, and
// therefore there is nothing for a strip-restart index to restart. Measured, not
// assumed: see the dxc negative control in this wave's verification, which
// compiles this same shader with a strip output topology and gets a hard
// compile error naming the enum.
//
// So the strip is expanded HERE, in the stage, into the two triangles it
// denotes: strip 0,1,2,3 is triangles (0,1,2) and (1,2,3), i.e. six vertices.
// That is the same two triangles in the same winding as the reference's
// 4-index strip; only the addressing differs.
//
// The primitive RESTART is therefore not reproduced as a mechanism, because
// there is nothing left for it to do: one GS invocation is one rectangle and
// invocations are independent, where the reference's strip was a single shared
// buffer that consecutive rectangles had to be cut apart in. Cutting a per-
// primitive buffer between its own primitives is a no-op. This is the honest
// difference between the two, stated rather than papered over with an index
// buffer the project does not have.
constexpr int kRectGsMaxVertexCount = 6;

// F-653: the D3D12 required ceiling for GS output vertices per invocation is
// 1024 (D3D11/D3D12 functional spec, Geometry Shader). The arithmetic the brief
// asks for: we emit 6, so the headroom is 1018 vertices, a factor of 170. The
// reference needed 4 (pipeline_cache.cc:2303), a factor of 256 -- so this port
// is still two orders of magnitude inside the ceiling.
//
// Note what is NOT measured here: 1024 is a REQUIRED MINIMUM, and D3D12 exposes
// no feature-data field that reports an adapter's actual GS output ceiling. That
// is exactly why "geomStageCreated" in PipelineCacheStats is the counter that
// matters -- a PSO either came back with pGeometryShader bound or it did not,
// and CreateGraphicsPipelineState is the only authority on whether this
// particular device and driver accepted it.
static_assert(kRectGsMaxVertexCount <= 1024,
              "rectangle GS emits more vertices than the D3D12 required ceiling");

namespace {
// F-653: refuse with a name, bounded, and never with a default.
void RefuseGeometryShader(const char* caller, const char* what, uint32_t mask) {
    static std::atomic<uint32_t> s_unbuildable = {};
    const uint32_t n = s_unbuildable.fetch_add(1) + 1;
    if (n <= 8 || (n % 200) == 0)
        MCLA_LOG_WARN("PC-RECT-GS-REFUSED #{} [{}] {}: no geometry stage will be "
                      "bound for this pipeline; the rectangle draw is refused, "
                      "not drawn unexpanded",
                      n, caller ? caller : "?", what);
    (void)mask;
}
}  // namespace

std::string BuildRectangleGeometryShaderHlsl(std::string_view vsHlsl,
                                             const char* caller) {
    // ---- 1. Read the translated VS's OUTPUT signature --------------------
    //
    // WHY THE OUTPUT SIGNATURE AND NOT THE ELEMENT TABLE. The stage reads the
    // vertex shader's OUTPUT, never the vertex buffer, so the input layout is
    // not involved in this binding at all. The hazard the brief names -- a
    // stage bound to the wrong element shearing rectangles with no error --
    // cannot occur on this path, and it is worth being explicit about why: the
    // GS/VS and GS/PS links are made by SYSTEM-VALUE SEMANTIC between stage
    // signatures and are validated by CreateGraphicsPipelineState, not by an
    // input-layout slot index. There is no slot here to get wrong.
    //
    // The reference does exactly the same thing and never looks at the guest's
    // element table either: it AUTHORS the position input itself,
    // pipeline_cache.cc:2035 (`input_register_position = input_register_index`,
    // i.e. "the register after the interpolators") and declares it as a system
    // value at :2322-2324. The position is not discovered; it is placed.
    //
    // This project's translated VS already publishes the matching side of that
    // contract: `out float4 oPos : SV_Position` at shader_translator.cpp:676,
    // bound to guest export register 62 (the Xenos position export) at
    // shader_translator.cpp:756-757. So "which vertex element is POSITION" has
    // an answer, and it is not the one the brief expected: POSITION is the VS's
    // SV_Position OUTPUT. The four scalars the draw carries (CpVertexFormat,
    // render_queue.h:131-136) describe the FETCH format and are the right input
    // to a vertex layout; they are not, and need not be, the input to this stage.
    std::vector<uint32_t> interp;
    bool sawPosition = false;
    {
        static constexpr const char* kPos = "out float4 oPos : SV_Position";
        sawPosition = vsHlsl.find(kPos) != std::string_view::npos;
        static constexpr const char* kPrefix = "out float4 oTexCoord";
        size_t pos = 0;
        while (true) {
            const size_t hit = vsHlsl.find(kPrefix, pos);
            if (hit == std::string_view::npos) break;
            // MEASURED DEFECT THIS REPLACES: the skip was
            // `hit + sizeof(kPrefix) - 1`. `kPrefix` is a `const char*`, so
            // `sizeof` is the POINTER width -- 8 on x64 -- and not the string
            // length, which is 20. The scan therefore started 13 characters
            // early, INSIDE "float4", and the digit loop read 'a':
            //     sizeof(const char*) = 8 ; strlen(kPrefix) = 20 ; off by 13
            // (harness, `sizeof_probe`, against the real translated HLSL of
            // CP-SHADER-BODY #3). `digits` stayed false and EVERY VS that
            // emitted an interpolator took
            // RefuseGeometryShader("oTexCoord export with no index"), so
            // `BuildRectangleGeometryShaderHlsl` returned empty for all of
            // them. The refusal was TRUE in form and FALSE in fact: the
            // signature it claimed was unparsable is the one this module
            // writes itself, at shader_translator.cpp:723-724.
            //
            // CONFIRMED BY CONTROL, on the four live programs, calling the
            // real BuildRectangleGeometryShaderHlsl on the real
            // TranslateShaderPinned output:
            //   hash 00A089169A1B57E8 (declares oTexCoord0) -> EMPTY, refused
            //   hash D99385F5E67A3EB1 (declares oTexCoord0) -> EMPTY, refused
            //   hash AEAF1F096E09B347 (declares NO oTexCoord) -> 8171 bytes
            // The third is the control: with the prefix never matched, the
            // broken skip was never executed and the stage built.
            //
            // F-716, 2026-10-02: THE 8171 IS NOW 8244. The stage built for that
            // same program grew by 73 bytes because the comment INSIDE the emitted
            // shader was corrected -- it used to cite the Vulkan VS-expansion
            // builtin index buffer and primitive reset as the mechanism, which is
            // not what D3D12 does (see the long note above `std::string h`). No
            // HLSL CODE changed, only the comment text carried with it. Re-measured
            // on the real generator with a vertex shader in the translator's own
            // output shape (shader_translator.cpp:694-731): source 8244 B, and the
            // repo's own dxc.exe compiles it as gs_6_0 to 3680 B of DXIL with no
            // diagnostics. The earlier figure of 3708 B DXIL is likewise superseded.
            //
            // Anyone quoting "8171 B -> 3708 B DXIL" for this stage is quoting a
            // pre-correction artifact; the sizes are 8244 B -> 3680 B.
            //
            // So the parse is kept, `strlen` is used because <cstring> is
            // already included (pipeline_cache.cpp:7), and the refusal below is
            // kept as a real guard for a signature this module did not write.
            size_t p = hit + std::strlen(kPrefix);
            uint32_t n = 0;
            bool digits = false;
            while (p < vsHlsl.size() && vsHlsl[p] >= '0' && vsHlsl[p] <= '9') {
                n = n * 10u + static_cast<uint32_t>(vsHlsl[p] - '0');
                ++p;
                digits = true;
            }
            if (!digits) {
                RefuseGeometryShader(caller, "oTexCoord export with no index",
                                     kRefuseGeometryShaderUnbuildable);
                return std::string();
            }
            // The translator emits exactly " : TEXCOORD<n>" (shader_translator.cpp:723-724);
            // anything else is not a signature this module may reinterpret.
            //
            // THE TWO NUMBERING SCHEMES, MEASURED, AND WHY THE PASS-THROUGH
            // BELOW IS THE RIGHT BRIDGE RATHER THAN A NEW CORRESPONDENCE.
            //
            // Scheme A, the VS OUTPUT: the guest EXPORT REGISTER number. The
            // translator names the output `oTexCoord<vd> : TEXCOORD<vd>` for
            // vd in `vsExportDests_` (shader_translator.cpp:721-724), skipping
            // vd == 62 (position) and vd >= 16.
            // Scheme B, the PS INPUT: the DeclUsage `usageIndex`. The
            // translator names the input `i<usageVar><usageIndex> : <semantic>
            // <usageIndex>` (shader_translator.cpp:698-706) from
            // `prog_.interpolators[].usageIndex`, decoded at
            // xenos_shader_ir.cpp:213 (PS table, `word >> 0 & 0xF`).
            //
            // They are DIFFERENT fields in the guest's own tables: the VS
            // interpolator entry carries `reg` at `word >> 8 & 0xF`
            // (xenos_shader_ir.cpp:215) AND `usageIndex` at `word >> 0 & 0xF`,
            // independently. So nothing forces them to agree -- and the
            // reference does not rely on them agreeing either. It GUARANTEES
            // it: .research/xenia/src/xenia/gpu/d3d12/pipeline_cache.cc:1703-1704
            // asserts `vertex_shader_modification.vertex.interpolator_mask ==
            // pixel_shader_modification.pixel.interpolator_mask`, and the mask
            // is dense by construction
            // (.research/xenia/src/xenia/gpu/shader_translator.cc:340-344,
            // `(1 << interpolator_count) - 1`). Every signature is then emitted
            // with a DENSE ORDINAL: `semantic_index = i` for
            // i in [0, interpolator_count), on the GS input
            // (pipeline_cache.cc:2025), the GS output (:2186) and the VS/PS
            // signatures (dxbc_shader_translator.cc:1540-1545, :2843).
            //
            // THE REFERENCE THEREFORE NEVER READS THE VS SIGNATURE AT ALL, and
            // this module does not need a bridge either: because the ordinal is
            // dense, the ordinal EQUALS the guest's interpolator/export number
            // whenever the guest uses a 0..N-1 prefix, which is precisely what
            // scheme A already emits. Passing `n` through unchanged is the
            // reference's own numbering, not a correspondence invented here.
            //
            // MEASURED for the live pair, so the hazard is not merely argued:
            //   VS  D99385F5E67A3EB1 exports register 0  -> TEXCOORD0
            //   PS  7B0032AD4C5B576D usage=5 usageIndex=0 -> TEXCOORD0
            // They coincide at 0, so the GS links VS-out to PS-in through it.
            // UNRESOLVED and deliberately not asserted: this module cannot SEE
            // the PS, so it cannot check the reference's mask equality for a
            // program where the two schemes would differ. Such a draw would
            // fail at CreateGraphicsPipelineState with a signature mismatch --
            // loudly, and not by shearing a rectangle. See the handoff note.
            const std::string want = " : TEXCOORD" + std::to_string(n);
            if (vsHlsl.compare(p, want.size(), want) != 0) {
                RefuseGeometryShader(caller, "interpolator semantic is not TEXCOORD<n>",
                                     kRefuseGeometryShaderUnbuildable);
                return std::string();
            }
            for (uint32_t prior : interp) {
                if (prior == n) {
                    RefuseGeometryShader(caller, "duplicate interpolator index",
                                         kRefuseGeometryShaderUnbuildable);
                    return std::string();
                }
            }
            interp.push_back(n);
            pos = p;
        }
    }
    if (!sawPosition) {
        // A stage that could not find the position has nothing to expand, and a
        // stage invented without it would expand garbage -- which is worse than
        // not expanding, because it looks like it worked.
        RefuseGeometryShader(caller, "translated VS declares no `out float4 oPos : SV_Position`",
                             kRefuseGeometryShaderUnbuildable);
        return std::string();
    }

    // ---- 2. Emit the stage ----------------------------------------------
    //
    // F-716 CORRECTION TO A COMMENT INSIDE THE EMITTED SOURCE. The generated HLSL
    // used to carry, above the four appends, the sentence "its builtin index
    // buffer then draws the strip with primitive reset (primitive_processor.cc:
    // 454-459)". That is the VS-EXPANSION mechanism and D3D12 does not use it.
    // Measured, for THIS backend:
    //   d3d12_primitive_processor.cc:31 passes
    //     InitializeCommon(true, false, false, true, true, true) and the sixth
    //     argument is `rectangle_lists_supported_without_vs_expansion`
    //     (parameter order, primitive_processor.h:249-260);
    //   primitive_processor.cc:125-126 therefore sets expand_rectangle_lists_in_vs_
    //     = false, so the branch at primitive_processor.cc:392-397 is SKIPPED and
    //     host_vertex_shader_type stays kVertex (:377);
    //   host_primitive_reset_enabled therefore stays false
    //     (primitive_processor.cc:441), and d3d12/pipeline_cache.cc:1372 sets
    //     strip_cut_index = kNone, giving IBStripCutValue =
    //     D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED (:2836).
    // There is no builtin index buffer and no restart on this path. The draw is a
    // plain D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST of num_indices vertices
    // (d3d12_command_processor.cc:2309, :2338-2339) and the whole strip is
    // assembled and terminated INSIDE this stage.
    //
    // The conclusion was and remains right -- the cut gives triangles (0,1,2) and
    // (1,2,3) -- but the mechanism cited for it belonged to the other backend.
    //
    // WHY THE CORRECTION IS ALSO IN THE STRING, NOT ONLY HERE: an earlier pass of
    // this fix put the whole correction in a C++ comment above and left the false
    // sentence in the emitted shader. That is worse, not better: the shader is the
    // artifact a reader opens, and RULE 0 says a doc sentence asserting a guest
    // fact that is false is worse than one that is absent. So the string now
    // carries a short correct version, this comment carries the long version with
    // the citations, and the size figures are re-recorded where they are quoted
    // (see the AEAF1F096E09B347 note above).
    std::string h;
    h.reserve(2048 + interp.size() * 96);
    h +=
        "// F-653: the Xenos rectangle-list expansion, ported from the reference's\n"
        "// own direct3d-12 fallback. Every term below cites where it comes from.\n"
        "//\n"
        "// The reference builds this with a DXBC geometry shader. Where its TWO\n"
        "// transcriptions of this stage disagree -- the d3d12 one at\n"
        "// pipeline_cache.cc:2550-2695 and the vulkan one at\n"
        "// vulkan/pipeline_cache.cc:1406-1669 -- the terms below follow the\n"
        "// VULKAN one, and the block that differs says so at the line. One\n"
        "// structural difference is forced by D3D12 and is named where it\n"
        "// occurs:\n"
        "// difference is forced by D3D12 and is named where it occurs:\n"
        "//   - the reference's OUTPUT TOPOLOGY is a Triangle STRIP of 4\n"
        "//     (pipeline_cache.cc:2302-2303, kTriangleStrip and\n"
        "//     max_output_vertex_count = 4). D3D12 exposes streams rather than a\n"
        "//     strip topology, so this emits into a TriangleStream and closes the\n"
        "//     strip with os.RestartStrip() after the last append, which is the\n"
        "//     direct port of the reference's OpCutStream (pipeline_cache.cc:2694).\n"
        "//     Four appends in one strip: two triangles, (s0,s1,s2) and\n"
        "//     (s2,s1,s3), where s0..s2 are the three guest vertices in the\n"
        "//     order the longest-edge selection below chooses.\n"
        "//     kRectGsMaxVertexCount above is still 6, a legal cap for four appends\n"
        "//     and a mismatch against the reference's 4 -- reported, not changed,\n"
        "//     so this edit moves the rasterisation and nothing else.\n"
        "//\n"
        "// NOT PORTED, AND NOT INVENTED -- both are the reference conditioning on\n"
        "// state this project does not carry, so both are no-ops here rather than\n"
        "// guesses:\n"
        "//   - the point-coordinate output the reference writes 0.0 into\n"
        "//     (pipeline_cache.cc:2632-2634, 2665-2667), gated on\n"
        "//     key.has_point_coordinates. That key field is the guest's\n"
        "//     point-size/kill export 63, which this project's translator\n"
        "//     suppresses outright (shader_translator.cpp:755, \"The 63 write has\n"
        "//     no color output and is suppressed below\"), so the branch is not\n"
        "//     reachable and nothing stands in for it.\n"
        "//   - the clip/cull distance copies (pipeline_cache.cc:2638-2647,\n"
        "//     2675-2692) and the cull test (:2413-2435). This project's\n"
        "//     translated signatures carry no SV_ClipDistance/SV_CullDistance at\n"
        "//     all (shader_translator.cpp:676-681 emits only position and the\n"
        "//     TEXCOORD interpolators), so input_clip_distance_count is 0 and\n"
        "//     those loops are empty in the reference too.\n"
        "struct GSIn {\n"
        "    float4 pos : SV_Position;\n";
    for (uint32_t n : interp)
        h += "    float4 i" + std::to_string(n) + " : TEXCOORD" + std::to_string(n) + ";\n";
    h +=
        "};\n"
        "// GSOut's semantics are the VS's OUTPUT semantics verbatim, which is what\n"
        "// keeps the stage transparent: today the VS output links straight to the\n"
        "// PS input, and a stage that emitted any other name would move the link\n"
        "// from one hop to two and could fail with no diagnostic.\n"
        "struct GSOut {\n"
        "    float4 pos : SV_Position;\n";
    for (uint32_t n : interp)
        h += "    float4 o" + std::to_string(n) + " : TEXCOORD" + std::to_string(n) + ";\n";
    h += "};\n";
    h += "[maxvertexcount(" + std::to_string(kRectGsMaxVertexCount) + ")]\n";
    h += "void main(triangle GSIn v[3], inout TriangleStream<GSOut> os) {\n";
    h +=
        "    // Input is a TRIANGLE of 3 vertices -- pipeline_cache.cc:2300-2301\n"
        "    // (`input_primitive = dxbc::Primitive::kTriangle`,\n"
        "    // `input_primitive_vertex_count = 3`). A rectangle is 3 guest\n"
        "    // vertices; the 4th is generated. primitive_processor.cc:452's\n"
        "    // `primitive_count /= 3` is the console side agreeing.\n"
        "\n"
        "    // Discard the WHOLE primitive if any input position is NaN:\n"
        "    // pipeline_cache.cc:2401-2411. The reference tests it as\n"
        "    // `pos != pos` (OpNE of a register with itself, :2404-2405), which is\n"
        "    // true for every non-NaN and false for NaN, then ORs the results\n"
        "    // together and returns. `isnan` is the same predicate spelled\n"
        "    // directly. The reference's own comment notes NaN may also stand in\n"
        "    // for emulated vertex killing.\n"
        "    if (any(isnan(v[0].pos)) || any(isnan(v[1].pos)) || any(isnan(v[2].pos)))\n"
        "        return;\n"
        "\n"
        "    // Squared lengths of the three edges, into the reference's r0.xyz.\n"
        "    // vulkan/pipeline_cache.cc:1435-1471 reads component 0 and\n"
        "    // component 1 of each edge, which is what dot(e.xy, e.xy) below\n"
        "    // reproduces; the .xyz subtraction yields the same value, the\n"
        "    // swizzle only ever selecting the two components dot() reduces.\n"
        "    //     d12 = ||12||^2   from v2 - v1\n"
        "    //     d20 = ||20||^2   from v0 - v2\n"
        "    //     d01 = ||01||^2   from v1 - v0\n"
        "    // d3d12/pipeline_cache.cc:2579-2595 uses three DIFFERENT component\n"
        "    // pairs -- .xy for edge 12, .yz for 20, .zw for 01 -- because\n"
        "    // OpDP2 reduces components 0 and 1 of whatever its source swizzle\n"
        "    // selected (dxbc.h:1614-1617), so its r0.y and r0.z are NOT these\n"
        "    // numbers. With the guest\'s z=0, w=1 the two sets differ. See the\n"
        "    // note on that below.\n"
        "    float3 e12 = v[2].pos.xyz - v[1].pos.xyz;\n"
        "    float3 e20 = v[0].pos.xyz - v[2].pos.xyz;\n"
        "    float3 e01 = v[1].pos.xyz - v[0].pos.xyz;\n"
        "    float d12 = dot(e12.xy, e12.xy);\n"
        "    float d20 = dot(e20.xy, e20.xy);\n"
        "    float d01 = dot(e01.xy, e01.xy);\n"
        "\n"
        "    // The longest-edge selection. The predicate is the reference's own\n"
        "    // stated meaning: the comment at d3d12/pipeline_cache.cc:2558 says\n"
        "    // \"12 is the longest edge, strip 0123\", :2564 \"20 is the longest\n"
        "    // edge, strip 1203\", :2570 \"01 is the longest edge, strip 2013\".\n"
        "    // vulkan/pipeline_cache.cc:1479-1492 implements exactly that, as\n"
        "    // FOrdGreaterThan(edge12, edge20) && FOrdGreaterThan(edge12,\n"
        "    // edge01) -> 0, else FOrdGreaterThan(edge20, edge01) -> 1 else 2, and\n"
        "    // :1493-1505 rotates it into the other two slots.\n"
        "    //\n"
        "    // F-653 CORRECTION 2026-10-04. Two changes, and the SECOND is the\n"
        "    // one that decides the shape. `order` is now CONSUMED, and the\n"
        "    // comparison is now the vulkan one. Both were measured in the same\n"
        "    // untracked reference snapshot (.research/, gitignored, 0 files in\n"
        "    // HEAD, no recorded provenance), and the two d3d12/vulkan\n"
        "    // transcriptions of this stage disagree:\n"
        "    //\n"
        "    //  1. The d3d12 selection is DEAD. Written to r0.xyz at :2610 and\n"
        "    //     :2619-2620; the LAST line in the whole case (:2550-2695) that\n"
        "    //     touches r0 at all is :2619, so nothing in :2621-2695 reads\n"
        "    //     it. The emit loop indexes with the LITERAL i,\n"
        "    //     `dxbc::Index(0, i)` (:2626), and the fourth vertex is built\n"
        "    //     from the literal 0/1/2 (:2669-2673).\n"
        "    //  2. That d3d12 chain also INVERTS its own comment. :2599-2600\n"
        "    //     computes r0.w = (r0.y < r0.x) = (20 > 12) and :2602-2603\n"
        "    //     r0.x = (r0.z < r0.x) = (01 > 12), so :2605-2606 ANDs them\n"
        "    //     into \"12 is longest\" -- but that is 12 SHORTER than both,\n"
        "    //     the opposite of the comment it implements, and its else\n"
        "    //     arm (:2615-2620) swaps the other two cases as well. So that\n"
        "    //     chain cannot be taken as the statement of the predicate. It\n"
        "    //     is also silent in practice: it is dead, and because it is dead\n"
        "    //     nobody saw the inversion. Its agreement on any one input is\n"
        "    //     incidental -- on the measured draw below it does land on\n"
        "    //     (1,2,0), but it lands on (2,0,1)-needing orders wrongly too\n"
        "    //     (harness negative control).\n"
        "    //  3. The vulkan chain is not inverted and is not dead, and it\n"
        "    //     carries the identical comment block word for word\n"
        "    //     (:1407-1428 vs :2551-2572). So the comment, not the d3d12\n"
        "    //     chain, is the reference\'s own statement of this predicate,\n"
        "    //     and that is what the terms below follow.\n"
        "    //\n"
        "    // EDGE-LENGTH COMPONENTS, because the two files differ here too and\n"
        "    //     it matters for the numbers quoted below. d3d12 takes three\n"
        "    //     DIFFERENT component pairs -- .xy for edge 12, .yz for 20, .zw\n"
        "    //     for 01 (:2579-2595, with OpDP2 reducing components 0 and 1 per\n"
        "    //     dxbc.h:1614-1617); vulkan takes .x and .y for all three\n"
        "    //     (:1443-1461). With the guest\'s z=0, w=1 those give different\n"
        "    //     numbers, so this stage uses VULKAN\'s, matching the terms above.\n"
        "    //\n"
        "    // WHY IT DECIDES THE SHAPE. A rectangle\'s corners satisfy\n"
        "    // A + D = B + C, so which corner is v0 decides whether -v0 + v1 + v2\n"
        "    // closes the fourth corner or shears the quad. With the guest\'s\n"
        "    // MEASURED corners (build/w712.log:7913, VS-INPUT-STREAM #1)\n"
        "    // v0=(-0.5,-0.5) v1=(639.5,-0.5) v2=(639.5,359.5):\n"
        "    //     d12 = 360^2      = 129600\n"
        "    //     d20 = 640^2+360^2 = 539200   <- the longest, so the\n"
        "    //                                diagonal is 20\n"
        "    //     d01 = 640^2      = 409600\n"
        "    // first = 1, so order = (1,2,0) and\n"
        "    //     -v[order.x] + v[order.y] + v[order.z] = -v1 + v2 + v0\n"
        "    //         = (-0.5, 359.5)\n"
        "    // the rectangle\'s fourth corner. The literal 0/1/2 gave\n"
        "    // -v0 + v1 + v2 = (1279.5, 359.5): a parallelogram of the SAME\n"
        "    // AREA and twice the width, which is what w712.log recorded --\n"
        "    // changedPx=230400 and changedRows=360 already right, changedCols=\n"
        "    // 1278 instead of 640.\n"
        "    //\n"
        "    // No constant was moved to get that, and no edge length was\n"
        "    // rescaled: d12/d20/d01 above are dot(e.xy, e.xy) exactly as they\n"
        "    // were before this change. Only the comparison direction and the\n"
        "    // use of the result differ. Harness, which executes THIS emitted\n"
        "    // HLSL rather than a copy of it:\n"
        "    // %TEMP%\\opencode\\gs_rect_harness.py\n"
        "    bool twelveLongest = (d12 > d20) && (d12 > d01);\n"
        "    int first = twelveLongest ? 0 : ((d20 > d01) ? 1 : 2);\n"
        "    int3 order = int3(first, (first + 1) % 3, (first + 2) % 3);\n"
        "\n"
        "    // The fourth vertex: v3 = -v[order.x] + v[order.y] + v[order.z].\n"
        "    // The formula is pipeline_cache.cc:2669-2673 (OpAdd -v0+v1, then\n"
        "    // OpAdd that +v2) and vulkan/pipeline_cache.cc:1609-1627, which is\n"
        "    // the same linear combination over the SAME indices the vulkan\n"
        "    // select chain produced; the d3d12 file applies it to the literals\n"
        "    // 0/1/2 (:2670, :2671, :2673) because its selection is dead. This is\n"
        "    // also the same value as the comment's \"v3 = v0 + (v1 - v0) +\n"
        "    // (v2 - v0)\" at :2559.\n"
        "    // The same linear combination is applied to every interpolator, in\n"
        "    // the reference's r1 scratch register, :2655-2664.\n"
        "    GSOut o3;\n"
        "    o3.pos = v[order.y].pos - v[order.x].pos + v[order.z].pos;\n";
    for (uint32_t n : interp)
        h += "    o3.o" + std::to_string(n) + " = v[order.y].i" + std::to_string(n) +
             " - v[order.x].i" + std::to_string(n) + " + v[order.z].i" +
             std::to_string(n) + ";\n";
    h +=
        "\n"
    // The strip s0,s1,s2,s3, as the two triangles it denotes. The reference
    // emits three vertices (:2625-2649, one OpEmitStream per vertex at :2648;
    // vulkan :1520-1570), then the generated one (:2693; vulkan :1668-1669),
    // and CUTS the stream afterwards (OpCutStream, :2694). The cut TERMINATES
    // the 4-vertex strip; it does not separate s2 from s3, and a cut placed
    // after the third append would leave a 1-vertex strip covering NO triangle
    // at all. There is no index buffer and no primitive restart on this path
    // -- the draw is a plain TRIANGLELIST of num_indices vertices
    // (d3d12_command_processor.cc:2309, :2338-2339) and the whole strip is
    // assembled here.
        "    //\n"
        "    // Each output is built FIELD BY FIELD rather than by assigning the input\n"
        "    // vertex to an output variable. That is not a style choice: GSIn and GSOut\n"
        "    // are distinct struct types and HLSL does NOT implicitly convert between\n"
        "    // them even when their members are identical, so `o = v[0]; ostream.Append(o)`\n"
        "    // is a compile error (\"cannot implicitly convert from 'GSIn' to 'GSOut'\").\n"
        "    // Measured, not assumed: this was written the short way first and the dxc\n"
        "    // check rejected it at every Append site.\n"
        "    GSOut t;\n";
    // The emission order, as a table so the strip is legible in the output: the
    // three guest vertices in the order the longest-edge selection above chose,
    // then the generated v3.
    //
    // MEASURED DEFECT THIS TABLE PRECEDES. A TriangleStream appends into a
    // strip, and a strip of N vertices assembles N-2 triangles. This used to
    // append the six indices {0,1,2,1,2,3} with no restart, which is a
    // SIX-vertex strip and so FOUR triangles, where the reference's is two:
    //     i=0  v0,v1,v2   the reference's first triangle
    //     i=1  v1,v1,v2   zero area -- the table repeats v1
    //     i=2  v2,v1,v2   zero area -- the table repeats v2
    //     i=3  v1,v2,v3   the reference's second triangle
    // The repeats are what degenerate the middle pair, so the old form COVERED the
    // same two triangles as the reference: it did not draw the quad twice and it
    // did not reverse the second triangle's winding. What was wrong is that it
    // submitted two zero-area triangles per rectangle, duplicated v1 and v2 to do
    // it, and was described as a TRIANGLE LIST of 6 while this signature is a
    // TriangleStream. Four appends in one strip removes all three.
    //
    // F-653 2026-10-04: entries 0..2 are the SELECTION's indices, not the
    // literals 0,1,2 -- see the block above for the measurement. `nullptr` marks
    // the generated fourth vertex, which has no input index.
    static constexpr const char* kEmitIndex[4] = {"order.x", "order.y",
                                                  "order.z", nullptr};
    for (int k = 0; k < 4; ++k) {
        const char* idx = kEmitIndex[k];
        if (idx == nullptr) {
            h += "    os.Append(o3);\n";  // the generated vertex, already built
        } else {
            h += "    t.pos = v[" + std::string(idx) + "].pos;\n";
            for (uint32_t n : interp)
                h += "    t.o" + std::to_string(n) + " = v[" + idx + "].i" +
                     std::to_string(n) + ";\n";
            h += "    os.Append(t);\n";
        }
        // After the LAST append, NOT after the third: the reference cuts after
        // its fourth OpEmitStream (:2693), so the cut terminates the strip rather
        // than separating s2 from s3. Restarting after the third would leave the
        // trailing 1-vertex strip covering nothing, i.e. half the quad.
        if (k == 3)
            h += "    os.RestartStrip();\n";
    }
    h += "}\n";
    return h;
}


Microsoft::WRL::ComPtr<ID3D12PipelineState> PipelineCache::GetOrCompile(
    const PipelineKey& key,
    const std::string& vsHlsl,
    const std::string& psHlsl,
    const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
    const char* caller,
    bool* outCarriesGeometryStage) {

    // The carried geometry-stage capability starts FALSE and is only ever set on
    // the one path that can justify it (the cache hit below). Every early return
    // and the fallback therefore report "no stage", which is the safe answer: a
    // caller that maps prim_type 0x08 to a triangle list on this flag alone
    // cannot do so against a PSO nobody has proved carries the expansion.
    if (outCarriesGeometryStage) *outCarriesGeometryStage = false;

    {
        std::lock_guard<std::mutex> lock(statsMutex_);
        ++stats_.lookups;
    }

    // A key that carries a refusal is checked BEFORE the cache: such a key is
    // never inserted, so a lookup could only ever miss, and reporting it as a
    // miss would let it read like "one more compile pending".
    if (key.refuseMask != kRefuseNone) {
        RefuseOnce(key, key.refuseMask, caller,
                   "the key itself says this pipeline cannot be built honestly");
        return nullptr;
    }

    // Fast path: check cache first
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
    {
        std::lock_guard<std::mutex> lock(mapMutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            pso = it->second;
            if (pso) {
                std::lock_guard<std::mutex> slock(statsMutex_);
                ++stats_.hits;
                // THE ONE PATH THAT SETS THE CARRIED FLAG. The key names the
                // geometry stage as identity (PipelineState::geometryStage, and
                // the == operator at pipeline_cache.h), the worker is the only
                // writer of this map, and the worker binds pGeometryShader
                // exactly when the key named a stage (pipeline_cache.cpp
                // :1716-1718, and only from a blob that compiled at :1681).
                // So a hit on such a key IS a hit on a PSO that has the stage,
                // which is the fact D3D12 cannot be asked for directly.
                //
                // The converse is deliberately NOT asserted: a key with
                // kGeomStageNone could in principle be satisfied by a PSO that
                // has a stage, so the flag is the WEAKER claim (false) and is
                // safe when wrong. It can never be true when the stage is absent.
                if (outCarriesGeometryStage) {
                    *outCarriesGeometryStage =
                        (key.state.geometryStage == kGeomStageRectangleList);
                }
                return pso;
            }
            // A cached null can only exist if something bypassed Insert(); treat
            // it as a miss and let the refusal path below re-report it.
            map_.erase(it);
        }
    }

    {
        std::lock_guard<std::mutex> lock(statsMutex_);
        ++stats_.misses;
    }

    // Refusals. Each returns null on purpose; none of them is a cacheable miss.
    if (vsHlsl.empty() || psHlsl.empty()) {
        RefuseOnce(key, kRefuseEmptyHlsl, caller,
                   "no translated HLSL; a PSO cannot be compiled from nothing");
        return nullptr;
    }
    if (inputLayout.empty()) {
        RefuseOnce(key, kRefuseEmptyInputLayout, caller,
                   "empty input layout for a pipeline that consumes a VS");
        return nullptr;
    }
    if (HashInputLayout(inputLayout) != key.inputLayoutHash) {
        RefuseOnce(key, kRefuseLayoutDeclHashMismatch, caller,
                   "the layout does not match PipelineKey::inputLayoutHash");
        return nullptr;
    }
    if (!device_) {
        RefuseOnce(key, kRefuseNoDevice, caller, "PipelineCache::StartWorker was never called");
        return nullptr;
    }
    if (!rootSignature_) {
        RefuseOnce(key, kRefuseNoRootSignature, caller,
                   "no root signature: the worker cannot know what the draw will bind");
        return nullptr;
    }

    // Cache miss: grab the fallback PSO up front (may be null before SetFallback)
    Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback;
    {
        std::lock_guard<std::mutex> lock(fallbackMutex_);
        fallback = fallbackPso_;
    }

    // Queue an async compile task for this key. The worker compiles HLSL ->
    // DXIL and creates the PSO in the background; the fallback PSO is returned
    // so the draw never stalls. A key already queued or in flight is not
    // re-queued; the first task's completion populates the cache.
    CompileTask task;
    task.key = key;
    task.vsHlsl = vsHlsl;
    task.psHlsl = psHlsl;
    task.inputLayout = inputLayout;

    // F-716: hand this task's promise to whoever asks for the key next.
    //
    // CompileTask::promise was set on every worker path but read by nobody
    // (measured: `grep get_future src/` = 0 hits before this change), so the
    // future has to be taken HERE, before the task is moved into the queue --
    // std::promise::get_future may be called exactly once, and after a move the
    // promise object in `task` is a moved-from husk.
    //
    // A shared_future (not a future) because the worker owns the promise and can
    // never hand it back; two callers racing for the same in-flight key both get
    // the same state.
    std::shared_future<Microsoft::WRL::ComPtr<ID3D12PipelineState>> myFuture;
    bool queuedByMe = false;
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        if (pendingKeys_.size() >= kMaxInflight) {
            // Queue saturated. Previously this silently returned the fallback, so
            // a churn-heavy frame looked like a working cache. It is now a
            // counted refusal: the draw still happens (the backend's own default
            // applies) but the log says the compile queue is the problem.
            std::lock_guard<std::mutex> slock(statsMutex_);
            ++stats_.saturated;
            RefuseOnce(key, kRefuseQueueSaturated, caller,
                       "compile queue saturated (kMaxInflight=256); no task queued");
            return nullptr;
        }
        if (!pendingKeys_.insert(key).second) {
            {
                std::lock_guard<std::mutex> slock(statsMutex_);
                ++stats_.inFlightDuplicate;
            }
            // F-716: the key is ALREADY compiling (queued by an earlier draw this
            // frame, or by a previous one still in the worker). There is no
            // promise of ours to take, but there IS one to wait on, and for a
            // geometry-stage key waiting is the whole point -- see the wait below.
            std::lock_guard<std::mutex> ilock(inflightMutex_);
            auto it = inflightFutures_.find(key);
            if (it != inflightFutures_.end()) myFuture = it->second;
            return WaitForGeomStagePso(key, caller, fallback, myFuture,
                                       outCarriesGeometryStage);
        }
        myFuture = task.promise.get_future().share();
        queuedByMe = true;
        {
            std::lock_guard<std::mutex> ilock(inflightMutex_);
            inflightFutures_[key] = myFuture;
        }
        taskQueue_.push(std::move(task));
        queueCv_.notify_one();
        std::lock_guard<std::mutex> slock(statsMutex_);
        ++stats_.queued;
    }

    // F-716: a key that names a geometry stage cannot be drawn against the
    // fallback, so this one class of miss waits for its own PSO. Everything else
    // returns the fallback exactly as it always did -- no added latency for any
    // non-rectangle draw.
    (void)queuedByMe;
    return WaitForGeomStagePso(key, caller, fallback, myFuture,
                               outCarriesGeometryStage);
}

Microsoft::WRL::ComPtr<ID3D12PipelineState> PipelineCache::WaitForGeomStagePso(
    const PipelineKey& key, const char* caller,
    const Microsoft::WRL::ComPtr<ID3D12PipelineState>& fallback,
    const std::shared_future<Microsoft::WRL::ComPtr<ID3D12PipelineState>>& fut,
    bool* outCarriesGeometryStage) {
    if (outCarriesGeometryStage) *outCarriesGeometryStage = false;

    // Not a geometry-stage key: the historical behaviour, unchanged and unwaiting.
    if (key.state.geometryStage == kGeomStageNone) return fallback;
    // Nothing to wait for (the task's future could not be registered). Refuse
    // rather than hand back a GS-less PSO to a caller that is about to map 0x08.
    if (!fut.valid()) {
        {
            std::lock_guard<std::mutex> lock(statsMutex_);
            ++stats_.geomStageWaitFailed;
        }
        RefuseOnce(key, kRefuseGeometryStageUnsupported, caller,
                   "geometry-stage key with no in-flight compile to wait for; "
                   "refused rather than drawn against the GS-less fallback");
        return nullptr;
    }
    // If the worker has already exited, no task will ever be fulfilled. Checked
    // under queueMutex_ (workerAlive_ is written there too), NOT via
    // workerThread_.joinable(), which StopWorker mutates without that lock.
    bool workerAlive = false;
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        workerAlive = workerAlive_;
    }
    if (!workerAlive) {
        {
            std::lock_guard<std::mutex> lock(statsMutex_);
            ++stats_.geomStageWaitFailed;
        }
        RefuseOnce(key, kRefuseGeometryStageUnsupported, caller,
                   "the compile worker is not running, so this geometry-stage PSO "
                   "will never arrive; refused rather than drawn against the "
                   "GS-less fallback");
        return nullptr;
    }

    // WAIT HERE, with no lock held.
    //
    // The worker fulfils the promise on every path, including all six refusals
    // (failTask and the four inline set_value sites). A task pushed while the
    // worker is draining a stop request is still popped and fulfilled before it
    // returns, so this cannot block forever; kGeomStageWaitTimeoutMs is the
    // backstop for a wedged DXC.
    auto status = fut.wait_for(std::chrono::milliseconds(kGeomStageWaitTimeoutMs));
    if (status != std::future_status::ready) {
        static std::atomic<uint32_t> s_waitTimeout{0};
        const uint32_t n = s_waitTimeout.fetch_add(1) + 1;
        if (n <= 4 || (n % 200) == 0)
            MCLA_LOG_WARN("PC-RECT-PSO-WAIT-TIMEOUT #{}: waited {} ms for the "
                          "geometry-stage PSO of key=%016llX and it did not "
                          "arrive. The draw is REFUSED, not drawn against the "
                          "GS-less fallback. This is a new marker: no previous "
                          "line could report it, because nothing waited.",
                          n, static_cast<long>(kGeomStageWaitTimeoutMs),
                          static_cast<unsigned long long>(HashPipelineKey(key)));
        {
            std::lock_guard<std::mutex> lock(statsMutex_);
            ++stats_.geomStageWaitFailed;
        }
        return nullptr;
    }

    Microsoft::WRL::ComPtr<ID3D12PipelineState> pso = fut.get();
    if (!pso) {
        // The worker refused this key and said why on its own line. Returning the
        // fallback would put a stage-less PSO in the caller's hands on a key whose
        // identity says "rectangle"; nullptr routes the draw to the caller's
        // pso-refused branch, which names GetOrCompile's own refusal instead of
        // blaming the topology for it.
        {
            std::lock_guard<std::mutex> lock(statsMutex_);
            ++stats_.geomStageWaitFailed;
        }
        return nullptr;
    }

    // The claim, and exactly what backs it: this PSO came back from the task
    // whose key named kGeomStageRectangleList, and the worker binds
    // pGeometryShader only for such a key (pipeline_cache.cpp:1870-1872) and only
    // from a blob DXC compiled (:1835). No other writer inserts such a key, so
    // "this PSO carries the stage" is read off the artifact, not inferred from
    // the device.
    {
        std::lock_guard<std::mutex> lock(statsMutex_);
        ++stats_.geomStageWaited;
    }
    if (outCarriesGeometryStage) *outCarriesGeometryStage = true;
    return pso;
}

void PipelineCache::SetFallbackPipeline(Microsoft::WRL::ComPtr<ID3D12PipelineState> fallback) {
    std::lock_guard<std::mutex> lock(fallbackMutex_);
    fallbackPso_ = fallback;
}

bool PipelineCache::Find(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState>& pso) const {
    std::lock_guard<std::mutex> lock(mapMutex_);
    auto it = map_.find(key);
    if (it == map_.end()) return false;
    pso = it->second;
    return pso != nullptr;
}

void PipelineCache::Insert(const PipelineKey& key, Microsoft::WRL::ComPtr<ID3D12PipelineState> pso) {
    if (!pso) {
        std::lock_guard<std::mutex> lock(statsMutex_);
        ++stats_.nullInsertRejected;
        return;
    }

    std::lock_guard<std::mutex> lock(mapMutex_);

    // Evict if at limit (FIFO). Clear the evicted key's in-flight marker so a
    // later request can recompile it; a pending key is never in the map (the
    // worker clears pendingKeys_ right after Insert), so this is normally a
    // no-op and keeps lock order map_ -> queue_ consistent with the worker.
    if (order_.size() >= maxEntries_ && !order_.empty()) {
        const PipelineKey& oldest = order_.front();
        map_.erase(oldest);
        cbvBindings_.erase(oldest);
        order_.erase(order_.begin());
        {
            std::lock_guard<std::mutex> qlock(queueMutex_);
            pendingKeys_.erase(oldest);
        }
    }

    if (map_.count(key)) return;
    map_.emplace(key, pso);
    order_.push_back(key);
}

void PipelineCache::Clear() {
    std::lock_guard<std::mutex> lock(mapMutex_);
    map_.clear();
    cbvBindings_.clear();
    order_.clear();
}

PipelineCacheStats PipelineCache::Stats() const {
    PipelineCacheStats out;
    {
        std::lock_guard<std::mutex> lock(statsMutex_);
        out = stats_;
    }
    {
        std::lock_guard<std::mutex> lock(mapMutex_);
        out.size = static_cast<uint32_t>(map_.size());
    }
    {
        std::lock_guard<std::mutex> lock(queueMutex_);
        out.inflight = static_cast<uint32_t>(pendingKeys_.size());
    }
    return out;
}

std::vector<ConstantBankBinding> PipelineCache::ConstantBindingsFor(const PipelineKey& key) const {
    std::lock_guard<std::mutex> lock(mapMutex_);
    auto it = cbvBindings_.find(key);
    if (it == cbvBindings_.end()) return {};
    return it->second;
}

} // namespace mcla::renderer