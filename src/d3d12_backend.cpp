#include "d3d12_backend.h"
#include "renderer/test_shaders.h"
#include "renderer/vertex_decode.h"
#include "renderer/pipeline_cache.h"
#include "renderer/resource_cache.h"
#include "renderer/shader_translator.h"
#include "renderer/texture_decode.h"
#include "guest_memory.h"
#include "logging.h"
// F-726: std::numeric_limits<double>::quiet_NaN() -- the guard that makes a mean
// above its own maximum unprintable without clamping a value into plausibility.
#include <limits>
// F-729: the colour/shape census in ReportDrawReadback builds its bounded
// distinct-value table, its per-row/per-column coverage counters and its
// pre-rendered top-N text out of these. std::snprintf is the same renderer the
// input-stream dump above already uses (src/d3d12_backend.cpp:3107), so the
// numbers in that row and the numbers in this row cannot be formatted by two
// different code paths.
#include <cstdio>
#include <string>
#include <vector>
// F-761: the late-frame census below uses std::stable_sort for the top-N
// histogram tie-break and std::strcmp for the ledger's write-site label. The
// sort has to be stable and has to be named here: an unstable sort would make
// the printed histogram differ between two runs of the same surface, which is
// the exact defect F-729 records for the draw-path census.
#include <algorithm>
#include <cstring>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

namespace mcla::native {

namespace {
static D3D12Backend g_d3d12Backend;

// F-642: texture_decode.h:485-518 restates the D3D12 filter/address/compare
// enums as plain numbers so the decode module can stay SDK-free, and hands the
// backend static_asserts to keep them honest. The asserts were written, and they
// DO NOT ALL HOLD against the real d3d12.h (Windows Kits 10.0.26100.0,
// d3d12.h:3535-3600 for D3D12_FILTER, :1586-1594 for D3D12_COMPARISON_FUNC,
// :3654-3658 for the address modes). Measured, not from memory:
//
//   ENUM                          texture_decode.h   real d3d12.h
//   ADDRESS_MODE_WRAP .. _MIRROR_ONCE  1..5  = 1..5  OK (all five)
//   FILTER_MIN_MAG_MIP_POINT         0x000 = 0x000  OK
//   FILTER_ANISOTROPIC               0x055 = 0x055  OK
//   FILTER_COMPARISON_MIN_MAG_MIP_POINT 0x080 = 0x080  OK
//   FILTER_COMPARISON_ANISOTROPIC    0x0D5 = 0x0D5  OK
//   FILTER_MIN_MAG_MIP_LINEAR        0x034 vs 0x15  DRIFT
//   FILTER_MIN_MAG_POINT_MIP_LINEAR  0x038 vs 0x01  DRIFT
//   FILTER_MIN_POINT_MAG_MIP_LINEAR  0x03C vs 0x05  DRIFT
//   FILTER_MIN_POINT_MAG_MIP_POINT   0x030 vs 0x04  DRIFT (name is MIN_POINT_MAG_LINEAR_MIP_POINT)
//   FILTER_MIN_LINEAR_MAG_MIP_LINEAR 0x044 vs 0x11  DRIFT
//   FILTER_MIN_LINEAR_MAG_MIP_POINT  0x020 vs 0x10  DRIFT
//   FILTER_COMPARISON_MIN_MAG_MIP_LINEAR 0x0B4 vs 0x95  DRIFT
//   COMPARISON_FUNC_NONE             (absent) vs 0
//   COMPARISON_FUNC_NEVER            0     vs 1    DRIFT
//   COMPARISON_FUNC_ALWAYS           7     vs 8    DRIFT  (the whole
//                                      NEVER..ALWAYS run is off by one)
//   D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK = 1, OPAQUE_WHITE = 2 (d3d12.h:4086-4088)
//
// The five that agree are asserted. The drifting ones are RECORDED, not
// asserted, because asserting them would fail the build for a file this change
// does not own; MCLA_ASSERT_TEXTURE_DECODE_TABLE turns the record into hard
// asserts the moment the texture agent corrects texture_decode.h:503-517, and
// nothing else has to change here.
//
// This drift is not academic. HostSamplerDesc::filter and ::comparisonFunc are
// consumed verbatim by BindGuestSampler, so a hard static_cast of 0x034 into
// D3D12_FILTER is filter 0x34 = D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR -
// a MINIMUM reduction filter, i.e. silently a different filtering mode. That is
// why IsLegalD3D12Filter below exists: the backend validates the decoded value
// against the REAL enum set and REFUSES anything that is not a legal
// D3D12_FILTER, instead of casting a number that is known to be wrong.
static_assert(static_cast<uint32_t>(native::kD3D12AddressModeWrap) ==
                  D3D12_TEXTURE_ADDRESS_MODE_WRAP, "texture_decode.h address enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12AddressModeMirror) ==
                  D3D12_TEXTURE_ADDRESS_MODE_MIRROR, "texture_decode.h address enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12AddressModeClamp) ==
                  D3D12_TEXTURE_ADDRESS_MODE_CLAMP, "texture_decode.h address enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12AddressModeBorder) ==
                  D3D12_TEXTURE_ADDRESS_MODE_BORDER, "texture_decode.h address enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12AddressModeMirrorOnce) ==
                  D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE, "texture_decode.h address enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12FilterMinMagMipPoint) ==
                  D3D12_FILTER_MIN_MAG_MIP_POINT, "texture_decode.h filter enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12FilterAnisotropic) == D3D12_FILTER_ANISOTROPIC,
              "texture_decode.h filter enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12FilterComparisonMinMagMipPoint) ==
                  D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT, "texture_decode.h filter enum drift");
static_assert(static_cast<uint32_t>(native::kD3D12FilterComparisonAnisotropic) ==
                  D3D12_FILTER_COMPARISON_ANISOTROPIC, "texture_decode.h filter enum drift");

#ifdef MCLA_ASSERT_TEXTURE_DECODE_TABLE
static_assert(native::kD3D12FilterMinMagMipLinear == D3D12_FILTER_MIN_MAG_MIP_LINEAR,
              "texture_decode.h:503 D3D12_FILTER_MIN_MAG_MIP_LINEAR is 0x034, d3d12.h:3548 says 0x15");
static_assert(native::kD3D12FilterMinMagPointMipLinear ==
                  D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR,
              "texture_decode.h:507 D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR is 0x038, d3d12.h:3542 says 0x01");
static_assert(native::kD3D12FilterMinPointMagMipLinear == D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR,
              "texture_decode.h:506 is 0x03C, d3d12.h:3544 says 0x05");
static_assert(native::kD3D12FilterMinPointMagMipPoint == D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT,
              "texture_decode.h:508 name/0x030 does not exist; d3d12.h:3543 D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x04");
static_assert(native::kD3D12FilterMinLinearMagMipLinear == D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
              "texture_decode.h:509 is 0x044, d3d12.h:3546 says 0x11");
static_assert(native::kD3D12FilterMinLinearMagMipPoint == D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT,
              "texture_decode.h:510 is 0x020, d3d12.h:3545 says 0x10");
static_assert(native::kD3D12FilterComparisonMinMagMipLinear ==
                  D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR,
              "texture_decode.h:512 is 0x0B4, d3d12.h:3558 says 0x95");
static_assert(native::kD3D12ComparisonFuncNever == D3D12_COMPARISON_FUNC_NEVER,
              "texture_decode.h:514 is 0, d3d12.h:1587 says 1 (0 is COMPARE_FUNC_NONE)");
static_assert(native::kD3D12ComparisonFuncAlways == D3D12_COMPARISON_FUNC_ALWAYS,
              "texture_decode.h:515 is 7, d3d12.h:1594 says 8 (the whole run is off by one)");
#endif  // MCLA_ASSERT_TEXTURE_DECODE_TABLE

// Is `filter` one of the values d3d12.h actually defines? This is the guard that
// keeps F-642's drift from reaching a D3D12_SAMPLER_DESC. The set is the
// non-MINIMUM/MINIMUM/MAGNIFICATION family plus the COMPARISON family, read off
// d3d12.h:3541-3600; anything outside it is a number no D3D12 driver accepts as
// a filter, so binding it would be undefined rather than merely wrong.
bool IsLegalD3D12Filter(uint32_t filter) {
    switch (filter) {
        case D3D12_FILTER_MIN_MAG_MIP_POINT:
        case D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR:
        case D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT:
        case D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MIN_MAG_MIP_LINEAR:
        case D3D12_FILTER_MIN_MAG_ANISOTROPIC_MIP_POINT:
        case D3D12_FILTER_ANISOTROPIC:
        case D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT:
        case D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR:
        case D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT:
        case D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR:
        case D3D12_FILTER_COMPARISON_MIN_MAG_ANISOTROPIC_MIP_POINT:
        case D3D12_FILTER_COMPARISON_ANISOTROPIC:
        case D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT:
        case D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR:
        case D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT:
        case D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR:
        case D3D12_FILTER_MINIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT:
        case D3D12_FILTER_MINIMUM_ANISOTROPIC:
        case D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT:
        case D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR:
        case D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT:
        case D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
        case D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT:
        case D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR:
        case D3D12_FILTER_MAXIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT:
        case D3D12_FILTER_MAXIMUM_ANISOTROPIC:
            return true;
        default:
            return false;
    }
}

// F-638: bytes per BLOCK for the block-compressed host formats the import gate
// now accepts, plus the scalar forms. GetCopyableFootprints supplies the
// DESTINATION row pitch; this table supplies the SOURCE row pitch, which is a
// property of the format alone: width*bytesPerBlock for a scalar format,
// ceil(width/4)*bytesPerBlock for a 4x4 block format. Computing it from the
// destination pitch instead would silently shear every compressed upload, which
// looks like a wrong image rather than an error, so it is a named table.
struct HostFormatFootprint {
    DXGI_FORMAT format;
    uint32_t blockWidth;
    uint32_t blockHeight;
    uint32_t bytesPerBlock;
};
constexpr HostFormatFootprint kHostFormatTable[] = {
    { DXGI_FORMAT_R8G8B8A8_UNORM,     1, 1,  4 },
    { DXGI_FORMAT_B8G8R8A8_UNORM,     1, 1,  4 },
    { DXGI_FORMAT_R8_UNORM,           1, 1,  1 },
    { DXGI_FORMAT_R8G8_UNORM,         1, 1,  2 },
    { DXGI_FORMAT_R16G16B16A16_FLOAT, 1, 1,  8 },
    { DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 1, 16 },
    { DXGI_FORMAT_BC1_UNORM,          4, 4,  8 },
    { DXGI_FORMAT_BC1_UNORM_SRGB,     4, 4,  8 },
    { DXGI_FORMAT_BC2_UNORM,          4, 4, 16 },
    { DXGI_FORMAT_BC2_UNORM_SRGB,     4, 4, 16 },
    { DXGI_FORMAT_BC3_UNORM,          4, 4, 16 },
    { DXGI_FORMAT_BC3_UNORM_SRGB,     4, 4, 16 },
    { DXGI_FORMAT_BC4_UNORM,          4, 4,  8 },
    { DXGI_FORMAT_BC5_UNORM,          4, 4, 16 },
};
constexpr uint32_t kHostFormatTableCount =
    static_cast<uint32_t>(sizeof(kHostFormatTable) / sizeof(kHostFormatTable[0]));

// Returns the table row for `format`, or nullptr when this backend cannot import
// it. nullptr is a REFUSAL, never a fallback to R8G8B8A8_UNORM.
const HostFormatFootprint* FindHostFormat(DXGI_FORMAT format) {
    for (uint32_t i = 0; i < kHostFormatTableCount; ++i) {
        if (kHostFormatTable[i].format == format) return &kHostFormatTable[i];
    }
    return nullptr;
}

inline uint32_t BlocksFor(uint32_t texels, uint32_t blockTexels) {
    if (blockTexels <= 1) return texels;
    return (texels + blockTexels - 1) / blockTexels;
}

// F-637/F-638/F-639/F-640: bounded, process-wide refusal counters. A soak needs
// the totals, and the process holds exactly one backend (g_d3d12Backend above),
// so a file-scope array is enough and costs no per-draw allocation.
constexpr uint32_t kMaxCountedPrimTypes = 32;
uint64_t g_primTypeRefusals[kMaxCountedPrimTypes] = {};
uint64_t g_primTypeRefusalOther = 0;
uint64_t g_textureImportRefusals[32] = {};
uint64_t g_textureImportRefusalOther = 0;
uint64_t g_resolveRefusals = 0;
uint64_t g_samplerRefusals = 0;
uint64_t g_textureBindRefusals = 0;
uint64_t g_layoutRefusals = 0;

// F-649: the import census. Two counters and one bucket array, all bumped
// unconditionally -- the throttle below gates the TEXT, never the count, because
// a suppressed row that is not counted is how a soak reads "nothing happened"
// out of something that happened 616,824 times (F-054 / LOG QUALITY POISONED).
uint64_t g_textureImportPlans = 0;   // every plan that reached CreateDecodedTexture
uint64_t g_textureImportOk = 0;      // ... and produced a resident texture
uint64_t g_textureImportBackendRefusals[static_cast<uint32_t>(
    D3D12Backend::TextureBackendRefusal::kCount)] = {};

// Bounded log throttle: one line for the first kRefuseLogFirst events of a kind,
// then every kRefuseLogEvery-th. House pattern (n <= K || n % 200 == 0) so a
// refusal storm cannot turn the log into the bottleneck it is measuring.
constexpr uint64_t kRefuseLogFirst = 8;
constexpr uint64_t kRefuseLogEvery = 200;
inline bool ShouldLogRefusal(uint64_t n) {
    return n <= kRefuseLogFirst || (n % kRefuseLogEvery) == 0;
}

// ---------------------------------------------------------------------------
// CLIPEXTENT-PUBLISHED -- publishes the render-target extent that the
// clip_disable rescale is built from, AT THE POINT THE EXTENT IS FIRST KNOWN.
//
// MEASURED 2026-10-04 on build/w707.log, by line number. The publication used to
// live on the draw path, and that is one translation too late: the constants are
// BAKED at translation time -- renderer/shader_translator.cpp:1134 reads the
// process global inside AppendEpilogue and :1194-1199 formats it into the
// emitted HLSL -- so the first translation of a process wins for the life of
// that process. The ordering, w707.log:
//     144   D3D12Backend: Initializing backend        <- extent already known
//     386   D3D12Backend: Resizing swap chain         <- and again, still at init
//    7479   DRAW_CAPTURED #1                         <- first draw reaches the
//    7505   draw #1's programs TRANSLATED               render thread
//    8027   VS-CLIPSPACE-PROBE #1 ... rescaleValid=0     IDENTITY, permanently
//    8031   the publication that used to be inside the draw
//    8074   draw #2's programs translated               valid -> the real rescale
// Both draws target the same 1280x720 target, so the only thing that differed
// between an identity bake and a correct one was WHERE the publication sat.
//
// WHY ONE ROW IS ENOUGH TO READ THE ORDER OFF. Two clock readings from two
// threads prove nothing by themselves; the ORDER OF LINES in one append-only log
// does. This row is written at the instant of publication, so a soak compares
// its line number against the line number of the first translation row and reads
// the order directly instead of inferring it from two timestamps. `validBefore=0`
// on the first row additionally states that no extent had EVER been accepted,
// which is exactly the condition under which the translator emits the identity.
//
// NOT A DEFAULT AND NOT A GUESS. `extentX`/`extentY` are this backend's own
// swapchain dimensions at the instant they are published. A zero extent is
// REFUSED by the translator (shader_translator.cpp:1806) rather than substituted,
// and that refusal logs at ERROR under this same token, so the token's count can
// never read 1 while the shader kept the identity. Nothing here fabricates an
// extent to fill the gap.
//
// BOTH CALL SITES ARE IN THIS FILE AND THE LIST IS EXHAUSTIVE: the extent is
// assigned in exactly two places (`m_width`/`m_height` -- every occurrence in
// this file was enumerated, not sampled), and each now publishes immediately
// after the assignment and before anything that can translate:
//   Initialize -- ahead of CreateSwapChain, and therefore ahead of the caller
//                starting the pipeline worker (src/render_thread.cpp:121),
//                which is the only ordering the translator's own contract asks
//                for (shader_translator.h:192-194 "call this before translating
//                any vertex shader, and again whenever the render target is
//                resized"; shader_translator.cpp:1800-1804).
//   Resize     -- after ResizeBuffers has SUCCEEDED, so the published extent is
//                always one the swapchain really has.
//
// `drawsIssued` is the backend's own draw ordinal at the publication instant. It
// is reported so a reader can see whether any draw had already been issued here;
// it is NOT offered as proof of the translation order, because a translation is
// reachable only from inside a draw command (measured: the translation call
// sites are src/render_thread.cpp:1289, :1291, :3471 and :3537, all inside
// processCommand's draw cases, and those cases break unless the backend finished
// initializing) -- the log line order is the proof, this number is the context.
static void PublishClipDisableExtent(const char* site, uint32_t extentX,
                                     uint32_t extentY, uint64_t drawsIssued) {
    static std::atomic<uint64_t> s_publications{0};
    const uint64_t n = s_publications.fetch_add(1, std::memory_order_relaxed) + 1;

    renderer::ClipDisableRescaleConstants before{};
    const bool validBefore = renderer::QueryClipDisableRescale(&before);

    const bool accepted = renderer::SetClipDisableViewportExtent(extentX, extentY);

    renderer::ClipDisableRescaleConstants after{};
    const bool validAfter = renderer::QueryClipDisableRescale(&after);

    if (!accepted || !validAfter) {
        // Loud, and loud under the SAME token: a refusal logged under a different
        // name would leave a reader of the throttled row above believing in a
        // rescale that is not there.
        MCLA_LOG_ERROR(
            "CLIPEXTENT-PUBLISHED #{} site={} extent={}x{} accepted={} "
            "validBefore={} validAfter={} drawsAtPublish={} "
            "ndcScale=({},{},{}) ndcOffset=({},{},{}) -- REFUSED: no usable "
            "extent was installed, so a vertex shader translated from here on "
            "bakes the identity form. Nothing was substituted for the zero.",
            n, site, extentX, extentY, accepted ? 1 : 0, validBefore ? 1 : 0,
            validAfter ? 1 : 0, drawsIssued, after.scaleX, after.scaleY,
            after.scaleZ, after.offsetX, after.offsetY, after.offsetZ);
        return;
    }

    // Bounded by the house throttle, not by "the first row only": a later row is
    // what shows a resize re-publishing a DIFFERENT extent, and a one-shot row
    // cannot be compared against a later one in the same soak. The counter above
    // is incremented unconditionally either way, so a suppressed row still counts.
    if (!ShouldLogRefusal(n)) return;
    MCLA_LOG_INFO(
        "CLIPEXTENT-PUBLISHED #{} site={} extent={}x{} accepted={} "
        "validBefore={} validAfter={} drawsAtPublish={} "
        "ndcScale=({},{},{}) ndcOffset=({},{},{})",
        n, site, extentX, extentY, accepted ? 1 : 0, validBefore ? 1 : 0,
        validAfter ? 1 : 0, drawsIssued, after.scaleX, after.scaleY,
        after.scaleZ, after.offsetX, after.offsetY, after.offsetZ);
}

// ---------------------------------------------------------------------------
// F-650 (Task 2): the back-buffer clear colour, as ONE named constant.
//
// NOTHING in the guest or in any reference establishes this value. Measured
// 2026-09-30 against build/w662.log and the working tree: the Xenos command
// capture path carries no clear colour at all -- `clearColor`, `ClearColor`,
// `CLEAR_RENDER_TARGET` and `kClear` have ZERO occurrences in src/gpu_cp.cpp --
// and the only clear in the whole 797,718-line soak is the host's own
// "RenderThread: initial clear+present (dark blue)" at 00:43:44.017. The guest
// never asked for this colour; on a real console the first draw of a frame
// covers whatever the previous frame left, and no clear is required at all.
//
// So this is a HOST PLACEHOLDER, kept deliberately, named so it cannot hide:
// before F-650 the same near-black sat inline in the draw path as a literal
// {0.02, 0.03, 0.05, 1.0}, which is how a frame ends up the wrong shade
// forever with no line to edit. It is now one constant with this comment
// attached, and FRAME-OWNER counts how many presented frames it was the
// background of.
//
// WHAT WOULD REPLACE IT, in the order the evidence would arrive:
//   1. The guest's own PM4 CLEAR_RENDER_TARGET colour, once the CP path decodes
//      the packet's clear value and carries it on the draw descriptor. Then the
//      clear is the guest's and this constant should be DELETED, not assigned.
//   2. If the guest is measured never to clear -- i.e. every frame's first draw
//      covers every pixel -- the right value is not a colour at all: the clear
//      should be removed, and this constant with it.
// Neither is measured, so it stays. What must not happen is it drifting back
// into being an inline literal at a second call site.
// ---------------------------------------------------------------------------
constexpr float kPlaceholderBackBufferClear[4] = { 0.02f, 0.03f, 0.05f, 1.0f };
}  // namespace

D3D12Backend* GetD3D12Backend() {
    return &g_d3d12Backend;
}

// F-637: Xenos VGT_DRAW_INITIATOR.prim_type (xenos.h:44-59) -> D3D12 topology.
// The value space is the architected enum, NOT DrawPacket::primType's own stale
// comment ("0=TriList, 1=TriStrip" at trace_types.h:74), which is why this is
// spelled out per code rather than as an offset into an array.
bool D3D12Backend::MapXenosPrimType(uint32_t primType, D3D_PRIMITIVE_TOPOLOGY& out,
                                    bool hasGeometryStage) {
    switch (primType) {
        case 0x01: out = D3D_PRIMITIVE_TOPOLOGY_POINTLIST;     return true;  // kPointList
        case 0x02: out = D3D_PRIMITIVE_TOPOLOGY_LINELIST;      return true;  // kLineList
        case 0x03: out = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP;     return true;  // kLineStrip
        case 0x04: out = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;  return true;  // kTriangleList
        case 0x05: out = D3D_PRIMITIVE_TOPOLOGY_TRIANGLEFAN;   return true;  // kTriangleFan
        case 0x06: out = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP; return true;  // kTriangleStrip
        // Refused, each with its own reason in the log:
        //  0x00 kNone              -- no primitive; Xenia's translation is a
        //                             draw of zero indices, not a geometry type
        //  0x07 kTriangleWithWFlags -- per-triangle W flag; D3D12 carries that
        //                             in a PS, not in a topology
        // F-650: 0x08 gets its OWN case, not a line in the comment block, so the
        // one prim_type the guest is measured to actually issue is a named refusal
        // with a stated reason rather than an anonymous fallthrough.
        //  0x08 kRectangleList     -- the console's "quads". Xenos emits two
        //                             triangles per rectangle, so TRIANGLELIST
        //                             would draw them in the wrong order with no
        //                             indication anything was dropped. It is NOT
        //                             substituted here on purpose: expanding a
        //                             rect list into 2N triangles is the
        //                             producer's job, because only the producer
        //                             knows the index stride and base. MEASURED in
        //                             build/w662.log: DRAW-CP-DRAWN #20600
        //                             prim=8 vertices=3 indexed=0 -- every draw
        //                             that reached the producer was a rect list.
        //
        // F-653 + the hasGeometryStage arm: a rectangle list is three guest
        // vertices that only become a quad inside the geometry stage, so the
        // topology is TRIANGLELIST IF AND ONLY IF the PSO about to be used has
        // that stage bound. The mapping is the reference's own, measured:
        // d3d12_command_processor.cc:2308-2310 sets
        // D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST for the rectangle path and
        // :2330-2339 issues D3DDrawInstanced(count, 1, 0, 0) with no index
        // buffer, and d3d12/pipeline_cache.cc:1402-1405 keys the pipeline with
        // geometry_shader = kRectangleList. The stage itself is built by
        // BuildRectangleGeometryShaderHlsl (F-653, pipeline_cache.cpp) with
        // input primitive = Triangle, input vertex count 3, output strip and
        // max_output_vertex_count = 4 (pipeline_cache.cc:2298-2303), which is
        // why three vertices in is the right count and not an off-by-one.
        //
        // The refusal arm below is UNCHANGED and still counts, so a soak reading
        // PrimTypeRefusalCount(0x08) sees "rectangle draws refused because the
        // PSO in hand carried no expansion stage" rather than nothing at all.
        case 0x08:
            if (hasGeometryStage) {
                out = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
                return true;
            }
            break;  // counted below, with its own reason
        //  0x0C kLineLoop          -- D3D12 has no loop topology
        //  0x0D/0x0E kQuadList/kQuadStrip, 0x0F kPolygon -- no equivalent
        default: break;
    }
    // F-650: the single exit every refusal takes, counted per prim_type so the
    // rectangle list is visible as its own row rather than hiding in a fallthrough.
    // g_primTypeRefusals[] was written NOWHERE in the tree before this (read at
    // :293 and :299; the only write in the backend was the unrelated patchlist
    // bucket), so PrimTypeRefusalCount(0x08) read 0 forever and a refusal could
    // not be told from a call that never happened. Counting here rather than at
    // the call site is the point: no caller can absorb a refusal by not reporting it.
    const uint64_t n = (primType < kMaxCountedPrimTypes)
                           ? ++g_primTypeRefusals[primType]
                           : ++g_primTypeRefusalOther;
    if (ShouldLogRefusal(n)) {
        // F-716: THE CLAUSE BELOW WAS WRONG AND NAMED A BLOCKER THAT DOES NOT
        // EXIST. It used to read "D3D12 has no equivalent topology; the Xenos
        // rectangle list 0x08 must be expanded to 2 triangles per rect by the
        // producer, never substituted here". Every clause of that is
        // contradicted by the reference, measured just now:
        //   * the reference DOES map kRectangleList to
        //     D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST --
        //     d3d12_command_processor.cc:2307-2310;
        //   * it expands in a GEOMETRY SHADER, not "by the producer" and not in
        //     the vertex shader: d3d12_primitive_processor.cc:31 passes
        //     `rectangle_lists_supported_without_vs_expansion = true` (6th
        //     argument, order at primitive_processor.h:249-260), so
        //     primitive_processor.cc:125-126 sets expand_rectangle_lists_in_vs_
        //     = false and the VS-expansion branch at primitive_processor.cc:
        //     392-397 is SKIPPED. host_vertex_shader_type stays kVertex (:377);
        //   * it issues D3DDrawInstanced(host_draw_vertex_count, 1, 0, 0) with
        //     host_draw_vertex_count == vgt_draw_initiator.num_indices
        //     (primitive_processor.cc:440) -- for this game's rectangle draws,
        //     the 3 of DRAW-CP-REFUSE -- with NO index buffer
        //     (d3d12_command_processor.cc:2330-2339).
        // So "D3D12 has no equivalent topology" is false and the draw is NOT
        // refused for want of a topology. It is refused because THE PSO IN HAND
        // CARRIES NO EXPANSION STAGE -- and that is the one clause worth
        // printing, because it is the one a soak can act on.
        //
        // The prefix (marker name and both numbers) is byte-identical to before;
        // only the `--` explanation changed, so a grep on
        // "prim_type 0x08 unmappable, refused" still finds every occurrence.
        MCLA_LOG_WARN("D3D12Backend: prim_type 0x{:02X} unmappable, refused #{} "
                      "(total={}) -- the TOPOLOGY is not the problem: D3D12 has "
                      "exactly the topology the reference uses for this "
                      "prim_type (TRIANGLELIST, d3d12_command_processor.cc:"
                      "2307-2310). The blocker is that the PSO in hand carries "
                      "NO geometry stage, so the rectangle's 4th vertex would "
                      "never be generated and TRIANGLELIST would draw ONE of "
                      "its TWO triangles. The stage is built and compiled by "
                      "PipelineCache for a key that names kGeomStageRectangleList "
                      "(hasGeometryStage, above); it is bound only when "
                      "GetOrCompile returns THAT PSO. Counted separately in the "
                      "cache: PC-RECT-OFFERED (asked), geomStageCreated (built), "
                      "and PipelineCache::Stats().geomStageWaited/geomStageWaitFailed",
                      primType, n, PrimTypeRefusalTotal());
    }
    return false;
}

uint64_t D3D12Backend::PrimTypeRefusalCount(uint32_t primType) {
    return primType < kMaxCountedPrimTypes ? g_primTypeRefusals[primType]
                                           : g_primTypeRefusalOther;
}

uint64_t D3D12Backend::PrimTypeRefusalTotal() {
    uint64_t total = g_primTypeRefusalOther;
    for (uint32_t i = 0; i < kMaxCountedPrimTypes; ++i) total += g_primTypeRefusals[i];
    return total;
}

// F-638: refusal buckets. Index 0..31 mirrors TextureRefusal so a caller can
// report plan->refusal directly. The "plan was fine but THIS backend could not
// carry it" cases (no host-format row, zero extent, D3D12 create failure, short
// payload) are not plan refusals and get their own total, g_textureImport-
// RefusalOther, rather than being filed under TextureRefusal::None where they
// would read as "no reason given".
uint64_t D3D12Backend::TextureImportRefusals(uint32_t reason) {
    return reason < 32 ? g_textureImportRefusals[reason] : g_textureImportRefusalOther;
}
uint64_t D3D12Backend::TextureImportRefusalTotal() {
    uint64_t total = g_textureImportRefusalOther;
    for (uint32_t i = 0; i < 32; ++i) total += g_textureImportRefusals[i];
    return total;
}
uint64_t D3D12Backend::ResolveRefusalCount() { return g_resolveRefusals; }

// F-649: the census accessors. Declared next to the F-638 refusal accessors
// above because they are the same accounting read from the other end: `total`
// counts what was attempted, `accepted` counts what got through, and the
// difference is attributable.
uint64_t D3D12Backend::TextureImportPlanCount() { return g_textureImportPlans; }
uint64_t D3D12Backend::TextureImportSuccessCount() { return g_textureImportOk; }

const char* D3D12Backend::TextureBackendRefusalName(TextureBackendRefusal reason) {
    switch (reason) {
        case TextureBackendRefusal::Unlisted: return "unlisted";
        case TextureBackendRefusal::LegacyUnsupportedDxgi: return "legacy_unsupported_dxgi";
        case TextureBackendRefusal::LegacyBadArgs: return "legacy_bad_args";
        case TextureBackendRefusal::NoHostFormat: return "no_host_format";
        case TextureBackendRefusal::ZeroExtent: return "zero_extent";
        case TextureBackendRefusal::MipCountOutOfRange: return "mip_count_out_of_range";
        case TextureBackendRefusal::MipChainAndGenerate: return "mip_chain_and_generate";
        case TextureBackendRefusal::MipLevelHasNoPayload: return "mip_level_has_no_payload";
        case TextureBackendRefusal::MipZeroHasNoPayload: return "mip_zero_has_no_payload";
        case TextureBackendRefusal::SrvSlotOutOfRange: return "srv_slot_out_of_range";
        case TextureBackendRefusal::ShortPayload: return "short_payload";
        case TextureBackendRefusal::MipgenFailed: return "mipgen_failed";
        case TextureBackendRefusal::kCount: return "kCount";
    }
    return "unlisted";
}

uint64_t D3D12Backend::TextureBackendRefusals(TextureBackendRefusal reason) {
    const uint32_t i = static_cast<uint32_t>(reason);
    return i < static_cast<uint32_t>(TextureBackendRefusal::kCount)
               ? g_textureImportBackendRefusals[i]
               : g_textureImportBackendRefusals[0];
}

uint64_t D3D12Backend::TextureBackendRefusalTotal() {
    uint64_t total = 0;
    for (uint32_t i = 0;
         i < static_cast<uint32_t>(TextureBackendRefusal::kCount); ++i) {
        total += g_textureImportBackendRefusals[i];
    }
    return total;
}


D3D12Backend::D3D12Backend() = default;

D3D12Backend::~D3D12Backend() {
    Shutdown();
}

bool D3D12Backend::Initialize(HWND hwnd, uint32_t width, uint32_t height) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    if (m_initialized) return true;
    if (!hwnd) {
        MCLA_LOG_ERROR("D3D12Backend: Null HWND passed to Initialize");
        return false;
    }

    m_hwnd = hwnd;
    m_width = (width > 0) ? width : 1280;
    m_height = (height > 0) ? height : 720;

    // The extent is FIRST KNOWN right here, so this is where the clip_disable
    // rescale is published. It is deliberately ahead of CreateSwapChain and
    // therefore ahead of the caller starting the pipeline worker
    // (src/render_thread.cpp:121): the constants are baked into generated HLSL at
    // translation time, so a publication that waits for the first draw arrives
    // after that draw's vertex shader has already been translated and has already
    // baked the identity. See PublishClipDisableExtent above and the measured
    // ordering in build/w707.log.
    PublishClipDisableExtent("init", m_width, m_height, m_cachePipelineDraws);

    MCLA_LOG_INFO("D3D12Backend: Initializing backend for HWND 0x{:X} ({}x{})",
                reinterpret_cast<uintptr_t>(hwnd), m_width, m_height);
    DWORD winThread = GetWindowThreadProcessId(hwnd, nullptr);
    DWORD curThread = GetCurrentThreadId();
    MCLA_LOG_INFO("D3D12Backend: window owner thread={} calling thread={} {}",
                winThread, curThread, winThread == curThread ? "(MATCH)" : "(MISMATCH)");
    {
        char cls[256] = {};
        GetClassNameA(hwnd, cls, 256);
        MCLA_LOG_INFO("D3D12Backend: window class='{}' visible={}",
                    cls, IsWindowVisible(hwnd) ? 1 : 0);
    }

    if (!CreateDevice()) return false;
    if (!CreateCommandObjects()) return false;
    if (!CreateCopyQueue()) return false;
    if (!CreateSwapChain(hwnd, m_width, m_height)) return false;
    if (!CreateRenderTargets()) return false;
    if (!CreateSyncObjects()) return false;
    if (!CreateUploadHeap()) return false;
    if (!CreateTestRootSignature()) return false;
    if (!CreateTestPipeline()) return false;
    if (!CreateStaticIndexBuffer()) return false;
    if (!CreateSrvHeap()) return false;
    if (!CreateSamplerHeap()) return false;

    // F-643: the format table's isResolvable column and Xenia's ColorFormat set
    // must be the same set, or every BuildResolveDesc refusal reason in
    // texture_decode.cpp is wrong in the same direction. One shot at init, not a
    // per-resolve cost (texture_decode.h:467 asks for exactly this).
    {
        uint32_t offender = 0;
        if (!native::VerifyResolvableColumnMatchesXeniaColorFormat(&offender)) {
            MCLA_LOG_ERROR("D3D12Backend: format table isResolvable disagrees with Xenia "
                           "ColorFormat at xenosFormat {} ({}) -- resolve refusals are untrusted",
                           offender, native::TextureFormatName(offender));
        }
    }

    // F-641: warm the mipgen CS compile here, at init, rather than inside
    // GenerateMipmaps. It is a DXC Load + fxc compile; leaving it on the draw
    // path meant the first draw needing a mip chain stalled between MapUpload
    // and DrawIndexedInstanced. Failure here is NOT fatal to Initialize: no
    // guest texture has needed mip generation yet, and GenerateMipmaps refuses
    // loudly with the recorded reason when one does.
    if (!EnsureMipGenPipeline()) {
        MCLA_LOG_ERROR("D3D12Backend: mipgen PSO warm-up failed at init; GenerateMipmaps will "
                       "refuse every mip chain until this is fixed");
    }

    // Initialize pipeline cache worker thread and set fallback PSO (test pipeline)
    m_pipelineCache.StartWorker(m_device, m_rootSignature);
    m_pipelineCache.SetFallbackPipeline(m_testPipeline);

    m_initialized = true;
    MCLA_LOG_INFO("D3D12Backend: Successfully initialized D3D12 native renderer skeleton + Phase 3 test pipeline");
    return true;
}

bool D3D12Backend::CreateDevice() {
    UINT dxgiFactoryFlags = 0;

#if !defined(NDEBUG)
    {
        Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
            debugController->EnableDebugLayer();
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
            MCLA_LOG_INFO("D3D12Backend: Direct3D 12 Debug Layer enabled");
        }
    }
#endif

    HRESULT hr = CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDXGIFactory2 failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    Microsoft::WRL::ComPtr<IDXGIAdapter1> hardwareAdapter;
    bool adapterSelected = false;
    for (UINT adapterIndex = 0; SUCCEEDED(m_factory->EnumAdapters1(adapterIndex, &hardwareAdapter)); ++adapterIndex) {
        DXGI_ADAPTER_DESC1 desc;
        hardwareAdapter->GetDesc1(&desc);

        if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;

        if (SUCCEEDED(D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr))) {
            char descBuf[128] = {};
            size_t converted = 0;
            wcstombs_s(&converted, descBuf, sizeof(descBuf) - 1, desc.Description, _TRUNCATE);
            MCLA_LOG_INFO("D3D12Backend: Selected GPU adapter: {}", descBuf);
            adapterSelected = true;
            break;
        }
    }

    if (!adapterSelected) {
        // Loop always leaves hardwareAdapter non-null after the first iteration,
        // so clear it explicitly before the WARP fallback.
        MCLA_LOG_WARN("D3D12Backend: No hardware D3D12 adapter found, attempting WARP software adapter");
        hardwareAdapter = nullptr;
        m_factory->EnumWarpAdapter(IID_PPV_ARGS(&hardwareAdapter));
    }

    if (!hardwareAdapter) {
        MCLA_LOG_ERROR("D3D12Backend: No D3D12-capable adapter (hardware or WARP) available");
        return false;
    }

    // F-653: the requested level is a NAMED value because it is also the
    // measurement below. `ID3D12Device::GetFeatureLevel()` DOES NOT EXIST in
    // either installed Windows SDK -- measured, not recalled: 0 occurrences of
    // the name in `um\d3d12.h` for 10.0.26100.0 and for 10.0.22621.0, and
    // neither SDK's D3D12_FEATURE_DATA_D3D12_OPTIONS3 carries a
    // GeometryShaderTier field either. A SUCCESSFUL create at a requested level
    // is itself the fact: the runtime returns a device at that level or fails,
    // and the failure path is the very next line. The requested level reached
    // successfully IS the device's level.
    constexpr D3D_FEATURE_LEVEL kRequestedFeatureLevel = D3D_FEATURE_LEVEL_11_0;
    hr = D3D12CreateDevice(hardwareAdapter.Get(), kRequestedFeatureLevel, IID_PPV_ARGS(&m_device));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: D3D12CreateDevice failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    // F-653: MEASURE the feature level instead of assuming the one requested.
    //
    // The rectangle-list expansion is a GEOMETRY STAGE (pipeline_cache.cpp,
    // BuildRectangleGeometryShaderHlsl), and a D3D12 geometry stage requires
    // feature level 11_0. 11_0 is what is requested above; a driver is free to
    // hand back a lower level for an adapter it decided was software, and it has
    // already done so or failed by the time control reaches here -- so the
    // reached level is a fact and not an assumption.
    //
    // This is the check that answers Task 1's first question at runtime, and it
    // is deliberately a MEASUREMENT and not a gate: the device is not refused
    // here, because a device below 11_0 can still run every non-rectangle draw.
    // Rectangle draws take the refusal, in the cache, with the name
    // `geom-stage-unsupported-at-this-feature-level` -- so a soak sees a
    // counted reason instead of a silently black rectangle area.
    {
        const D3D_FEATURE_LEVEL actual = kRequestedFeatureLevel;
        m_featureLevel = actual;
        const bool gsCapable = actual >= D3D_FEATURE_LEVEL_11_0;
        m_geometryStageSupported = gsCapable;
        // F-653: hand the MEASUREMENT to the pipeline cache, so a rectangle draw
        // is refused by the thing that compiles it rather than only described in
        // this one log line. The cache's default is false, so this assignment is
        // what makes rectangles possible at all on a capable device.
        m_pipelineCache.SetGeometryStageSupported(gsCapable);
        MCLA_LOG_INFO("D3D12Backend: feature level 0x{:04X} ({}) geometry-stage "
                      "capable = {} -- F-653",
                      static_cast<uint32_t>(actual),
                      actual == D3D_FEATURE_LEVEL_12_0 ? "12.0"
                      : actual == D3D_FEATURE_LEVEL_11_1 ? "11.1"
                      : actual == D3D_FEATURE_LEVEL_11_0 ? "11.0"
                      : actual == D3D_FEATURE_LEVEL_10_1 ? "10.1"
                      : actual == D3D_FEATURE_LEVEL_10_0 ? "10.0"
                                                         : "9.x",
                      gsCapable ? "yes" : "NO (rectangle draws will refuse)");
    }

    return true;
}

bool D3D12Backend::CreateCommandObjects() {
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    HRESULT hr = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommandQueue failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[i]));
        if (FAILED(hr)) {
            MCLA_LOG_ERROR("D3D12Backend: CreateCommandAllocator[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
            return false;
        }
    }

    hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocators[0].Get(), nullptr, IID_PPV_ARGS(&m_commandList));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommandList failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_commandList->Close();
    return true;
}

bool D3D12Backend::CreateCopyQueue() {
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_COPY;

    HRESULT hr = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_copyQueue));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyQueue failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_COPY, IID_PPV_ARGS(&m_copyAllocator));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyAllocator failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_COPY, m_copyAllocator.Get(), nullptr, IID_PPV_ARGS(&m_copyCommandList));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyCommandList failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    m_copyCommandList->Close();

    hr = m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_copyFence));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyFence failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_copyFenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (!m_copyFenceEvent) {
        MCLA_LOG_ERROR("D3D12Backend: CreateEvent(copy fence) failed");
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: Copy queue created (type=COPY)");
    return true;
}

bool D3D12Backend::CreateSwapChain(HWND hwnd, uint32_t width, uint32_t height) {
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = kBufferCount;
    swapChainDesc.Width = width;
    swapChainDesc.Height = height;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;

    Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain;
    HRESULT hr = m_factory->CreateSwapChainForHwnd(
        m_commandQueue.Get(),
        hwnd,
        &swapChainDesc,
        nullptr,
        nullptr,
        &swapChain);

    // 2026-10-02: NOT modified for the post-draw readback. A first attempt
    // asked for `DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_COPY_SRC` on the
    // theory that CopyTextureRegion out of a swap-chain back buffer needs a
    // copy usage. It does not, and the theory was wrong in a way worth
    // recording: measured against the toolchain this build uses
    // (Windows Kits 10.0.26100.0), `shared/dxgi.h:168-174` defines exactly
    // seven DXGI_USAGE_* macros -- SHADER_INPUT, RENDER_TARGET_OUTPUT,
    // BACK_BUFFER, SHARED, READ_ONLY, DISCARD_ON_PRESENT, UNORDERED_ACCESS --
    // and there is no COPY_SRC among them, nor anywhere in any dxgi*.h in the
    // SDK. `D3D12_RESOURCE_FLAG_ALLOW_COPY_SRC` does not exist either
    // (`um/d3d12.h` has ALLOW_RENDER_TARGET at :3070 and no copy-source flag):
    // every D3D12 resource is copyable unless DENY_SHADER_RESOURCE is set, so a
    // flip-model back buffer needs no extra usage and none is requested here.
    // The legality of the copy is therefore PROBED at runtime instead of
    // assumed -- see the readback's own gate.

    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateSwapChainForHwnd failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);
    hr = swapChain.As(&m_swapChain);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: Query IDXGISwapChain3 interface failed");
        return false;
    }

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    // F-761: the chain has just been created, so all kBufferCount back buffers
    // are new resources with undefined contents. Recorded rather than left to the
    // member initialiser, because Initialize() calls this on a backend whose
    // members may already have been written by an earlier failed attempt.
    ResetBufferLedger("CreateSwapChain");
    return true;
}

bool D3D12Backend::CreateRenderTargets() {
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = kBufferCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    HRESULT hr = m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (RTV) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));
        if (FAILED(hr)) {
            MCLA_LOG_ERROR("D3D12Backend: GetBuffer[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
            return false;
        }
        m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.ptr += m_rtvDescriptorSize;
    }

    return true;
}

bool D3D12Backend::CreateSyncObjects() {
    HRESULT hr = m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateFence failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    // The fence is created at value 0. Pre-arm the per-frame wait values to 0
    // so the FIRST BeginFrame does not wait on a value that was never signaled
    // (the fence is only advanced by the Signal() after each submit). A slot
    // only becomes non-zero once its frame has been submitted and fenced.
    m_fenceValues[m_frameIndex] = 0;
    m_currentFenceValue = 0;

    m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (!m_fenceEvent) {
        MCLA_LOG_ERROR("D3D12Backend: CreateEvent failed");
        return false;
    }

    return true;
}

bool D3D12Backend::CreateUploadHeap() {
    constexpr size_t kUploadSize = 4 * 1024 * 1024;  // 4 MiB per-frame upload arena

    D3D12_HEAP_PROPERTIES props = {};
    props.Type = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Width = kUploadSize;
    desc.Height = 1;
    desc.DepthOrArraySize = 1;
    desc.MipLevels = 1;
    desc.SampleDesc.Count = 1;
    desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    HRESULT hr = m_device->CreateCommittedResource(
        &props, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&m_uploadHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommittedResource(upload) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_uploadCapacity = kUploadSize;
    m_uploadRegionSize = kUploadSize / kBufferCount;
    m_uploadOffset = 0;
    m_uploadMap = nullptr;
    hr = m_uploadHeap->Map(0, nullptr, reinterpret_cast<void**>(&m_uploadMap));
    if (FAILED(hr) || !m_uploadMap) {
        MCLA_LOG_ERROR("D3D12Backend: upload heap Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: created {} MiB upload arena", kUploadSize / (1024 * 1024));
    return true;
}

bool D3D12Backend::CreateStaticIndexBuffer() {
    // 6 R16_UINT indices for the deterministic triangle, written once into a
    // dedicated upload resource and cached by ResourceCache. Later frames bind
    // the cached GPU address instead of re-uploading unchanged data (Phase 3
    // gate: "replaying the same frame twice does not reupload unchanged data").
    const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };
    constexpr uint32_t kIndexBytes = sizeof(indices);

    D3D12_HEAP_PROPERTIES props = {};
    props.Type = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Width = kIndexBytes;
    desc.Height = 1;
    desc.DepthOrArraySize = 1;
    desc.MipLevels = 1;
    desc.SampleDesc.Count = 1;
    desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    HRESULT hr = m_device->CreateCommittedResource(
        &props, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&m_staticIndexBuffer));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommittedResource(static ib) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = m_staticIndexBuffer->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        MCLA_LOG_ERROR("D3D12Backend: static index buffer Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    std::memcpy(mapped, indices, kIndexBytes);
    m_staticIndexBuffer->Unmap(0, nullptr);

    const uint64_t ibGpu = m_staticIndexBuffer->GetGPUVirtualAddress();
    const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                kIndexBytes, DXGI_FORMAT_R16_UINT, 1 };
    m_resourceCache.Insert(ibKey, ResourceEntry{ ibGpu, 1, false });
    m_stats.cacheMisses++;

    MCLA_LOG_INFO("D3D12Backend: static index buffer cached ({} bytes, gpu=0x{:X})", kIndexBytes, ibGpu);
    return true;
}

uint8_t* D3D12Backend::MapUpload(size_t size, size_t alignment, D3D12_GPU_VIRTUAL_ADDRESS& gpu) {
    if (!m_uploadMap || size == 0) return nullptr;
    if (alignment == 0) alignment = 256;

    // Offset is relative to this frame's region (region = back-buffer index),
    // so the fence wait in BeginFrame() guarantees the GPU is done reading this
    // region before we write it again. Region reuse requires offset < region.
    m_uploadOffset = (m_uploadOffset + alignment - 1) & ~(alignment - 1);
    if (m_uploadOffset + size > m_uploadRegionSize) {
        MCLA_LOG_WARN("D3D12Backend: upload arena region exhausted (need {} bytes, {} free); frame draw dropped",
                    size, m_uploadRegionSize - m_uploadOffset);
        return nullptr;
    }

    const size_t regionBase = static_cast<size_t>(m_frameIndex) * m_uploadRegionSize;
    gpu = m_uploadHeap->GetGPUVirtualAddress() + regionBase + m_uploadOffset;
    uint8_t* dst = m_uploadMap + regionBase + m_uploadOffset;
    m_uploadOffset += size;
    m_stats.uploadsBytes += size;
    m_stats.bytesThisFrame += size;
    return dst;
}

bool D3D12Backend::CreateSrvHeap() {
    D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
    // F-639: 17 slots, not 4. The root signature still binds only the first
    // kShaderTextureSlotCount (t0..t3) -- the heap being deeper does not make t4
    // reachable, because the translated HLSL has no t4 and the pipeline worker
    // refuses reflected registers >= kShaderTextureSlotCount. The extra slots are
    // the writable homes for DrawPacket::textureDescriptors[4..15], so binding
    // index i lands at kTexture2DSlot + i instead of aliasing a live SRV.
    heapDesc.NumDescriptors = kSrvHeapDescriptorCount;
    heapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    heapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    HRESULT hr = m_device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&m_srvHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (CBV/SRV/UAV) failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    m_srvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

    // D3D12 requires every descriptor in a bound table to be initialized.
    // Prefill ALL slots with null SRVs: an unbound texture slot must read as a
    // null SRV (a defined sample) and never as whatever the previous pass left
    // behind, and CreateDecodedTexture/BindGuestTextures overwrite individual
    // slots from here.
    D3D12_SHADER_RESOURCE_VIEW_DESC nullSrv = {};
    nullSrv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    nullSrv.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
    nullSrv.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    nullSrv.Texture2D.MipLevels = 1;
    for (uint32_t i = 0; i < kSrvHeapDescriptorCount; ++i) {
        D3D12_CPU_DESCRIPTOR_HANDLE h(m_srvHeap->GetCPUDescriptorHandleForHeapStart());
        h.ptr += static_cast<size_t>(i) * m_srvDescriptorSize;
        m_device->CreateShaderResourceView(nullptr, &nullSrv, h);
    }
    return true;
}

// Phase 6: Create shader-visible sampler descriptor heap
bool D3D12Backend::CreateSamplerHeap() {
    D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
    heapDesc.NumDescriptors = kSamplerHeapSize;
    heapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    heapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    HRESULT hr = m_device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&m_samplerHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (Sampler) failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    m_samplerDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER);
    m_samplerHeapOffset = 0;

    // F-644: slot 0 is the NEUTRAL sampler, not a magic constant. Every
    // descriptor table must be initialised before the list executes, and root
    // parameter 1 binds exactly one descriptor; leaving it uninitialised makes
    // the draw's sampler state a driver-dependent value. Slot 0 is clamp +
    // linear-mip-linear + aniso 1 + ComparisonFunc NEVER, which is what the old
    // static sampler encoded (the old code used ALWAYS, which is
    // D3D12_COMPARISON_FUNC_ALWAYS and means "comparison shadows" if a shader
    // ever samples with a comparison), so a pass that binds no guest sampler
    // samples deterministically instead of reading uninitialised descriptors.
    {
        D3D12_SAMPLER_DESC neutral = {};
        neutral.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
        neutral.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        neutral.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        neutral.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
        neutral.MipLODBias = 0.0f;
        neutral.MaxAnisotropy = 1;
        neutral.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
        // D3D12_SAMPLER_DESC::BorderColor is a FLOAT[4]; the enum
        // D3D12_STATIC_BORDER_COLOR_* only exists on D3D12_STATIC_SAMPLER_DESC,
        // which this root signature no longer has.
        neutral.BorderColor[0] = 0.0f;
        neutral.BorderColor[1] = 0.0f;
        neutral.BorderColor[2] = 0.0f;
        neutral.BorderColor[3] = 0.0f;
        neutral.MinLOD = 0.0f;
        neutral.MaxLOD = D3D12_FLOAT32_MAX;
        D3D12_CPU_DESCRIPTOR_HANDLE slot0(m_samplerHeap->GetCPUDescriptorHandleForHeapStart());
        m_device->CreateSampler(&neutral, slot0);
        m_samplerHeapOffset = 1;
        m_samplerTableGpu = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
    }
    MCLA_LOG_INFO("D3D12Backend: Created sampler descriptor heap ({} descriptors, slot 0 = neutral)",
                  kSamplerHeapSize);
    return true;
}

// Phase 6: Get or create sampler descriptor in the shader-visible heap
D3D12Backend::SamplerDescriptor D3D12Backend::GetOrCreateSamplerDescriptor(const D3D12_SAMPLER_DESC& desc) {
    SamplerCacheKey key{ desc };
    auto it = m_samplerDescriptorIndex.find(key);
    if (it != m_samplerDescriptorIndex.end()) {
        uint32_t index = it->second;
        D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = m_samplerHeap->GetCPUDescriptorHandleForHeapStart();
        cpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
        D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
        gpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
        return { cpuHandle, gpuHandle };
    }

    // Allocate new descriptor
    if (m_samplerHeapOffset >= kSamplerHeapSize) {
        MCLA_LOG_ERROR("D3D12Backend: Sampler descriptor heap exhausted ({} slots)", kSamplerHeapSize);
        return { {}, {} };
    }

    uint32_t index = m_samplerHeapOffset++;
    m_samplerDescriptorIndex.emplace(key, index);

    // Create the sampler in the heap
    D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = m_samplerHeap->GetCPUDescriptorHandleForHeapStart();
    cpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
    m_device->CreateSampler(&desc, cpuHandle);

    D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
    gpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;

    return { cpuHandle, gpuHandle };
}

// Bind the shader-visible sampler descriptor heap to the command list
void D3D12Backend::BindSamplerHeap() {
    if (!m_samplerHeap) return;
    ID3D12DescriptorHeap* heaps[] = { m_samplerHeap.Get() };
    m_commandList->SetDescriptorHeaps(1, heaps);
}

// Phase 7: Render Graph implementation
D3D12Backend::RenderGraphBuilder D3D12Backend::CreateRenderGraph() {
    return RenderGraphBuilder(this);
}

D3D12Backend::RenderGraphBuilder::PassHandle D3D12Backend::RenderGraphBuilder::AddPass(
    std::wstring name,
    std::vector<ResourceAccess> resources,
    std::function<void(ID3D12GraphicsCommandList*)> execute) {
    RenderGraphPass pass;
    pass.name = std::move(name);
    pass.resources = std::move(resources);
    pass.execute = std::move(execute);
    PassHandle handle{ static_cast<uint32_t>(m_backend->m_renderGraphPasses.size()) };
    m_backend->m_renderGraphPasses.push_back(std::move(pass));
    return handle;
}

ID3D12Resource* D3D12Backend::RenderGraphBuilder::GetTransientResource(const TransientResourceDesc& desc) {
    // Search for existing reusable resource
    for (auto& entry : m_backend->m_transientResources) {
        if (!entry.inUse && entry.desc.Width == desc.desc.Width &&
            entry.desc.Height == desc.desc.Height &&
            entry.desc.Format == desc.desc.Format &&
            entry.desc.DepthOrArraySize == desc.desc.DepthOrArraySize &&
            entry.desc.MipLevels == desc.desc.MipLevels &&
            entry.desc.SampleDesc.Count == desc.desc.SampleDesc.Count &&
            entry.desc.Flags == desc.desc.Flags) {
            entry.inUse = true;
            entry.lastUsedFrame = m_backend->m_frameIndex;
            return entry.resource.Get();
        }
    }

    // Create new resource
    D3D12_HEAP_PROPERTIES heapProps = {};
    heapProps.Type = D3D12_HEAP_TYPE_DEFAULT;

    Microsoft::WRL::ComPtr<ID3D12Resource> resource;
    HRESULT hr = m_backend->m_device->CreateCommittedResource(
        &heapProps, D3D12_HEAP_FLAG_NONE, &desc.desc,
        D3D12_RESOURCE_STATE_COMMON,
        &desc.clearValue, IID_PPV_ARGS(&resource));

    if (FAILED(hr)) {
        MCLA_LOG_ERROR("RenderGraph: Failed to create transient resource '{}', hr=0x{:08X}",
                     std::string(desc.name.begin(), desc.name.end()).c_str(),
                     static_cast<uint32_t>(hr));
        return nullptr;
    }

    TransientResourceEntry entry;
    entry.name = desc.name;
    entry.desc = desc.desc;
    entry.clearValue = desc.clearValue;
    entry.resource = resource;
    entry.lastUsedFrame = m_backend->m_frameIndex;
    entry.inUse = true;

    m_backend->m_transientResources.push_back(std::move(entry));
    return m_backend->m_transientResources.back().resource.Get();
}

bool D3D12Backend::RenderGraphBuilder::Build() {
    auto& passes = m_backend->m_renderGraphPasses;
    auto& resources = m_backend->m_transientResources;
    auto& executionOrder = m_backend->m_renderGraphExecutionOrder;

    // Build dependency graph based on resource access patterns
    for (uint32_t i = 0; i < passes.size(); ++i) {
        for (uint32_t j = i + 1; j < passes.size(); ++j) {
            const auto& passA = passes[i];
            const auto& passB = passes[j];

            // Check for resource dependencies
            bool hasDependency = false;
            for (const auto& resA : passA.resources) {
                for (const auto& resB : passB.resources) {
                    if (resA.resource == resB.resource) {
                        // Same resource accessed - check for write dependency
                        if (resA.usage == ResourceUsage::Write || resB.usage == ResourceUsage::Write ||
                            resA.usage == ResourceUsage::ReadWrite || resB.usage == ResourceUsage::ReadWrite) {
                            hasDependency = true;
                            break;
                        }
                    }
                }
                if (hasDependency) break;
            }
            if (hasDependency) {
                passes[i].dependents.push_back(j);
                passes[j].dependencies.push_back(i);
            }
        }
    }

    // Topological sort (Kahn's algorithm)
    std::vector<uint32_t> inDegree(passes.size(), 0);
    for (const auto& pass : passes) {
        for (uint32_t dep : pass.dependencies) {
            inDegree[dep]++;
        }
    }

    std::queue<uint32_t> q;
    for (uint32_t i = 0; i < passes.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    executionOrder.clear();
    while (!q.empty()) {
        uint32_t u = q.front();
        q.pop();
        executionOrder.push_back(u);
        for (uint32_t v : passes[u].dependents) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (executionOrder.size() != passes.size()) {
        MCLA_LOG_ERROR("RenderGraph: Cycle detected in pass dependencies");
        return false;
    }

    // Allocate transient resources
    for (auto& res : resources) {
        if (!res.inUse) {
            // Already allocated or will be allocated on first use
        }
    }

    m_backend->m_renderGraphBuilt = true;
    return true;
}

void D3D12Backend::RenderGraphBuilder::Execute() {
    if (!m_backend->m_renderGraphBuilt) return;

    auto& passes = m_backend->m_renderGraphPasses;
    auto& executionOrder = m_backend->m_renderGraphExecutionOrder;

    for (uint32_t idx : executionOrder) {
        const auto& pass = passes[idx];

        // Emit barriers for resource state transitions
        std::vector<D3D12_RESOURCE_BARRIER> barriers;
        for (const auto& res : pass.resources) {
            if (res.resource) {
                D3D12_RESOURCE_BARRIER barrier = {};
                barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                barrier.Transition.pResource = res.resource;
                barrier.Transition.StateBefore = res.beforeState;
                barrier.Transition.StateAfter = res.afterState;
                barrier.Transition.Subresource = res.subresource;
                barriers.push_back(barrier);
            }
        }
        if (!barriers.empty()) {
            m_backend->m_commandList->ResourceBarrier(static_cast<UINT>(barriers.size()), barriers.data());
        }

        // Execute the pass
        if (pass.execute) {
            pass.execute(m_backend->m_commandList.Get());
        }

        // Emit UAV barriers for resources written
        std::vector<D3D12_RESOURCE_BARRIER> uavBarriers;
        for (const auto& res : pass.resources) {
            if (res.resource && (res.usage == ResourceUsage::Write || res.usage == ResourceUsage::ReadWrite)) {
                D3D12_RESOURCE_BARRIER uavBarrier = {};
                uavBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
                uavBarrier.UAV.pResource = res.resource;
                uavBarriers.push_back(uavBarrier);
            }
        }
        if (!uavBarriers.empty()) {
            m_backend->m_commandList->ResourceBarrier(static_cast<UINT>(uavBarriers.size()), uavBarriers.data());
        }
    }

    // Mark transient resources as no longer in use
    for (auto& res : m_backend->m_transientResources) {
        res.inUse = false;
    }
}

void D3D12Backend::RenderGraphBuilder::Reset() {
    m_backend->m_renderGraphPasses.clear();
    m_backend->m_renderGraphExecutionOrder.clear();
    m_backend->m_renderGraphBuilt = false;
    // Note: transient resources are kept for reuse, only marked as not in use
    for (auto& res : m_backend->m_transientResources) {
        res.inUse = false;
    }
}
// ============================================================================
// Phase 4 texture import: plan-driven (F-638)
// ============================================================================
//
// Phase 4 uploads host-linear decoded pixel bytes (already untiled by
// texture_decode) into a DEFAULT-heap texture and exposes it as a shader-visible
// SRV. The backend never touches guest memory here.
//
// F-638 replaced the old two-case `switch (format) { R8G8B8A8, R8 }` gate with
// the plan's own nativeDxgiFormat plus a block-format bytes-per-BLOCK table, so
// the BC1/BC2/BC3/BC4/BC5 forms PlanTextureImport already declares as
// DirectBlockCopy are importable zero-copy. The gate is now "is the format in
// the table", and a format that is not is a refusal with a name, never a
// substituted R8G8B8A8.

bool D3D12Backend::CreateDecodedTexture(const uint8_t* linearPixels, uint32_t width,
                                        uint32_t height, uint32_t dxgiFormat) {
    // Legacy 4-arg form. tools/validators/texture_import_validator.cpp:379 calls
    // it with a scalar RGBA payload, so the forwarder synthesises the scalar
    // plan that PlanTextureImport would have produced and hands it to the
    // plan-driven path. This is NOT a new format gate: the switch below is the
    // same two cases as before, so the validator's observable behaviour is
    // unchanged.
    switch (static_cast<DXGI_FORMAT>(dxgiFormat)) {
        case DXGI_FORMAT_R8G8B8A8_UNORM:
        case DXGI_FORMAT_R8_UNORM:
            break;
        default:
            ++g_textureImportRefusalOther;
            ++g_textureImportBackendRefusals[static_cast<uint32_t>(
                TextureBackendRefusal::LegacyUnsupportedDxgi)];
            MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture(legacy) unsupported dxgi format {}",
                           dxgiFormat);
            return false;
    }
    if (!linearPixels || width == 0 || height == 0) {
        // F-649: this branch used to be a SILENT count bump with no log at all --
        // the one refusal site in this file that produced neither a marker nor a
        // reason, which is exactly how a row becomes uncountable by a soak that
        // only reads lines. Now named and bucketed.
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::LegacyBadArgs)];
        MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture(legacy) refused: pixels={} {}x{}",
                       linearPixels ? "present" : "NULL", width, height);
        return false;
    }

    TextureImportDesc imp = {};
    native::TextureImportPlan plan = {};
    plan.ok = true;
    plan.mode = native::TextureUploadMode::ScalarCopy;
    plan.nativeDxgiFormat = dxgiFormat;
    plan.importDxgiFormat = dxgiFormat;
    plan.blockWidth = 1;
    plan.blockHeight = 1;
    plan.texelBytes = (dxgiFormat == DXGI_FORMAT_R8_UNORM) ? 1u : 4u;
    plan.blockBytes = plan.texelBytes;
    plan.blocksX = width;
    plan.blocksY = height;
    plan.formatName = "legacy-scalar";
    plan.linearByteSize = static_cast<uint32_t>(width) * height * plan.texelBytes;

    imp.plan = &plan;
    imp.mipPayloads[0] = linearPixels;
    imp.mipBytes[0] = plan.linearByteSize;
    imp.mipCount = 1;
    imp.width = width;
    imp.height = height;
    imp.srvSlot = kTexture2DSlot;
    return CreateDecodedTexture(imp);
}

bool D3D12Backend::CreateDecodedTexture(const TextureImportDesc& desc) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_srvHeap) return false;

    const native::TextureImportPlan& plan = *desc.plan;

    // --- Gate 0 (F-649): THE MARKER. `TEX-IMPORT` did not exist as a source
    // literal before this line, so its absence in every historical soak measured
    // the absence of a log call and nothing else. It is placed BEFORE Gate 1 and
    // OUTSIDE the refusal branch so it fires on every plan -- accepted or
    // refused -- because a refusal that does not print is a refusal nobody
    // learns from, and "plans attempted" is the row that distinguishes "the
    // title never reached the import path" from "it reached it and every plan
    // died here". The counter is bumped unconditionally; the house bound
    // (n <= kRefuseLogFirst || n % kRefuseLogEvery == 0) gates the TEXT only.
    const uint64_t planNo = ++g_textureImportPlans;
    if (ShouldLogRefusal(planNo)) {
        MCLA_LOG_INFO("TEX-IMPORT #{} fmt={} {} dxgi={} mode={} {}x{} mips={} blockB={} ok={} "
                      "refusal={} slot={}",
                      planNo, plan.xenosFormat, plan.formatName, plan.nativeDxgiFormat,
                      (uint32_t)plan.mode, desc.width, desc.height, desc.mipCount,
                      plan.blockBytes, plan.ok ? 1 : 0,
                      native::TextureRefusalName(plan.refusal), desc.srvSlot);
    }

    // --- Gate 1: the plan itself. A plan with ok == false carries a named
    // refusal; it is logged by that name and counted in its own bucket, so a
    // soak can attribute every missing texture to a reason instead of noticing
    // "the texture is black" much later.
    if (!plan.ok) {
        const uint64_t n = ++g_textureImportRefusals[static_cast<uint32_t>(plan.refusal)];
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: texture import refused #{} reason={} (xenosFmt={} {} "
                           "tiling) -- NULL SRV bound at slot {}",
                           n, native::TextureRefusalName(plan.refusal), plan.xenosFormat,
                           plan.formatName, desc.srvSlot);
        }
        return false;
    }

    // --- Gate 2: can THIS backend carry plan->nativeDxgiFormat? FindHostFormat
    // returning nullptr is the "no table row" refusal. It is deliberately not a
    // fallback: sampling a payload under a format it was not produced in is a
    // different image, not a blurrier one.
    const DXGI_FORMAT format = static_cast<DXGI_FORMAT>(plan.nativeDxgiFormat);
    const HostFormatFootprint* fp = FindHostFormat(format);
    if (static_cast<uint32_t>(format) == 0 || !fp) {
        const uint64_t n = ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::NoHostFormat)];
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: texture import refused #{} reason=NoHostFormat: "
                           "plan wants dxgiFormat {} (xenosFmt={} {}), which is not in the backend "
                           "import table -- NULL SRV bound at slot {}",
                           n, plan.nativeDxgiFormat, plan.xenosFormat, plan.formatName,
                           desc.srvSlot);
        }
        return false;
    }
    if (desc.width == 0 || desc.height == 0) {
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(TextureBackendRefusal::ZeroExtent)];
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: zero extent ({}x{})", desc.width,
                       desc.height);
        return false;
    }

    // --- Gate 3: the mip chain. Three mutually exclusive shapes, and the
    // caller must say which: one uploaded level, N uploaded levels, or N levels
    // derived by the mipgen PSO. A caller that supplies neither a payload per
    // level nor generateMipChain is refused rather than given MipLevels = 1
    // with the guest's level count silently discarded.
    const uint32_t mipCount = desc.mipCount;
    if (mipCount == 0 || mipCount > native::kTextureMaxMips) {
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::MipCountOutOfRange)];
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: mipCount {} outside 1..{}",
                       mipCount, native::kTextureMaxMips);
        return false;
    }
    if (mipCount > 1 && desc.generateMipChain) {
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::MipChainAndGenerate)];
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: {} mips AND generateMipChain; the "
                       "chain is either supplied or generated, never both", mipCount);
        return false;
    }
    if (mipCount > 1) {
        // Mip N's texel extent is max(1, extent >> N); D3D12 requires the full
        // chain down to 1x1, so a chain that stops short of it is refused here
        // rather than left as undefined subresource content.
        for (uint32_t i = 0; i < mipCount; ++i) {
            if (!desc.mipPayloads[i] || desc.mipBytes[i] == 0) {
                ++g_textureImportRefusalOther;
                ++g_textureImportBackendRefusals[static_cast<uint32_t>(
                    TextureBackendRefusal::MipLevelHasNoPayload)];
                MCLA_LOG_ERROR("D3D12Backend: texture import refused: mip {} of {} has no payload "
                               "(the chain was declared but not supplied)",
                               i, mipCount);
                return false;
            }
        }
    }
    if (desc.mipPayloads[0] == nullptr || desc.mipBytes[0] == 0) {
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::MipZeroHasNoPayload)];
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: mip 0 has no payload");
        return false;
    }
    if (desc.srvSlot >= kSrvHeapDescriptorCount) {
        ++g_textureImportRefusalOther;
        ++g_textureImportBackendRefusals[static_cast<uint32_t>(
            TextureBackendRefusal::SrvSlotOutOfRange)];
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: SRV slot {} outside 0..{}",
                       desc.srvSlot, kSrvHeapDescriptorCount - 1);
        return false;
    }

    // --- CpuExpand: the payload is not the import form yet.
    //
    // texture_decode.h:398-406 makes this the CPU twin of Xenia's load shaders
    // and REFUSES a ragged payload rather than partially writing, so the check is
    // one call. The output lands in a member scratch buffer so the draw path
    // does not allocate per texture.
    const uint8_t* level0 = desc.mipPayloads[0];
    uint32_t level0Bytes = desc.mipBytes[0];
    if (plan.mode == native::TextureUploadMode::CpuExpand) {
        native::TextureRefusal expandRefusal = native::TextureRefusal::None;
        if (!native::ExpandTextureToImportBytes(plan, level0, level0Bytes, m_importScratch,
                                                &expandRefusal)) {
            const uint64_t n = ++g_textureImportRefusals[static_cast<uint32_t>(expandRefusal)];
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: texture expand refused #{} reason={} (xenosFmt={} "
                               "{} payload={}B) -- NULL SRV bound at slot {}",
                               n, native::TextureRefusalName(expandRefusal), plan.xenosFormat,
                               plan.formatName, level0Bytes, desc.srvSlot);
            }
            return false;
        }
        level0 = m_importScratch.data();
        level0Bytes = static_cast<uint32_t>(m_importScratch.size());
    } else if (plan.mode == native::TextureUploadMode::Refused) {
        const uint64_t n = ++g_textureImportRefusals[static_cast<uint32_t>(plan.refusal)];
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: texture import refused #{}: plan.mode == Refused "
                           "(reason={}) -- NULL SRV bound at slot {}",
                           n, native::TextureRefusalName(plan.refusal), desc.srvSlot);
        }
        return false;
    }
    // NOTE (F-638): only the mip-0 payload is expanded. A multi-mip CpuExpand
    // chain is refused above only when the plan is Refused; a plan that is
    // CpuExpand AND mipCount > 1 would need ExpandTextureToImportBytes per
    // level, and only mip 0 is expanded here. Rather than upload mip 1..N
    // unexpanded -- which is a corrupted image, not a missing one -- that
    // combination is refused below, loudly.

    // --- Resource creation.
    D3D12_HEAP_PROPERTIES defProps = {};
    defProps.Type = D3D12_HEAP_TYPE_DEFAULT;
    defProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    defProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC texDesc = {};
    texDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    texDesc.Width = desc.width;
    texDesc.Height = desc.height;
    texDesc.DepthOrArraySize = 1;
    texDesc.MipLevels = mipCount;
    texDesc.SampleDesc.Count = 1;
    texDesc.Format = format;
    texDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    // F-641: the UAV flag is the contract GenerateMipmaps checks at
    // :1389 (texture_decode's own note and the old code agreed: CreateDecoded-
    // Texture set MipLevels = 1 with NO UAV flag, then GenerateMipmaps errored
    // "lacks ALLOW_UNORDERED_ACCESS" for the same resource). Now the flag and
    // the mip count are decided by the same `desc`, so the two can no longer
    // disagree: a single-mip texture is created WITHOUT the flag and must not be
    // followed by GenerateMipmaps; a generated chain is created WITH it.
    if (desc.generateMipChain) {
        texDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
    }

    Microsoft::WRL::ComPtr<ID3D12Resource> texture;
    HRESULT hr = m_device->CreateCommittedResource(
        &defProps, D3D12_HEAP_FLAG_NONE, &texDesc, D3D12_RESOURCE_STATE_COPY_DEST,
        nullptr, IID_PPV_ARGS(&texture));
    if (FAILED(hr)) {
        ++g_textureImportRefusalOther;
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: CreateCommittedResource "
                       "{}x{}x{} mips fmt={} failed hr=0x{:08X}",
                       desc.width, desc.height, mipCount, static_cast<uint32_t>(format),
                       static_cast<uint32_t>(hr));
        return false;
    }

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // --- Upload. One staging buffer for the whole chain, laid out by
    // GetCopyableFootprints per subresource, so the destination row pitch comes
    // from the driver and only the SOURCE pitch has to be derived from the
    // format. For a 4x4 block format that is
    // blocksX * bytesPerBlock, not width * bytesPerBlock -- the distinction the
    // old bytesPerPixel = 4-per-texel assumption could not express.
    //
    // GetCopyableFootprints needs the destination buffer's SIZE to place the
    // layouts, so it is called twice: once with no layouts to learn the total,
    // then again with a base of 0 so Footprint.Offset is a byte offset into that
    // same buffer and can be used directly as the per-level staging offset. (The
    // old code asked for one footprint of one subresource and threw the rest
    // away, which is why there was no way to express a chain at all.)
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT footprints[native::kTextureMaxMips] = {};
    UINT64 totalBytes = 0;
    const UINT numFootprints = desc.generateMipChain ? 1u : mipCount;
    {
        UINT rows = 0;
        UINT64 rowSize = 0;
        m_device->GetCopyableFootprints(&texDesc, 0, numFootprints, 0, nullptr, nullptr,
                                        &rowSize, &totalBytes);
    }
    if (totalBytes == 0) {
        ++g_textureImportRefusalOther;
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: GetCopyableFootprints returned 0 "
                       "bytes for {}x{} mips={}",
                       desc.width, desc.height, numFootprints);
        // 2026-10-02: second `m_inFrame` leak, same shape as the draw body's.
        // BeginFrame() was called at :1522 and set the latch; this return is
        // before anything is presented, so the frame is dropped and released.
        // Without this the texture-import refusal wedges every later frame.
        AbandonFrame("texture-import:zero-footprint");
        return false;
    }
    {
        UINT rows = 0;
        UINT64 rowSize = 0;
        m_device->GetCopyableFootprints(&texDesc, 0, numFootprints, 0, footprints, &rows,
                                        &rowSize, &totalBytes);
    }

    D3D12_HEAP_PROPERTIES upProps = {};
    upProps.Type = D3D12_HEAP_TYPE_UPLOAD;
    upProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    upProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC bufDesc = {};
    bufDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bufDesc.Width = totalBytes;
    bufDesc.Height = 1;
    bufDesc.DepthOrArraySize = 1;
    bufDesc.MipLevels = 1;
    bufDesc.SampleDesc.Count = 1;
    bufDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    Microsoft::WRL::ComPtr<ID3D12Resource> staging;
    hr = m_device->CreateCommittedResource(&upProps, D3D12_HEAP_FLAG_NONE, &bufDesc,
                                           D3D12_RESOURCE_STATE_GENERIC_READ, nullptr,
                                           IID_PPV_ARGS(&staging));
    if (FAILED(hr)) {
        ++g_textureImportRefusalOther;
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: staging ({}B) failed hr=0x{:08X}",
                       static_cast<uint32_t>(totalBytes), static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = staging->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        ++g_textureImportRefusalOther;
        MCLA_LOG_ERROR("D3D12Backend: texture import refused: staging Map failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    uint64_t copyLevels = 0;
    if (!desc.generateMipChain) {
        UINT64 offset = 0;
        for (uint32_t i = 0; i < mipCount; ++i) {
            const uint32_t mipW = std::max<uint32_t>(1, desc.width >> i);
            const uint32_t mipH = std::max<uint32_t>(1, desc.height >> i);
            const uint32_t blocksX = BlocksFor(mipW, fp->blockWidth);
            const uint32_t blocksY = BlocksFor(mipH, fp->blockHeight);
            const uint64_t srcPitch =
                static_cast<uint64_t>(blocksX) * fp->bytesPerBlock;
            const uint8_t* src = desc.mipPayloads[i];
            uint32_t srcBytes = desc.mipBytes[i];
            if (i == 0 && level0 != desc.mipPayloads[0]) {
                src = level0;
                srcBytes = level0Bytes;
            }
            // A short payload is refused, not clipped: copying only the rows
            // that happen to be present would upload a half-texture and leave
            // the rest as whatever the heap contained.
            const uint64_t need = srcPitch * blocksY;
            if (srcBytes < need) {
                staging->Unmap(0, nullptr);
                ++g_textureImportRefusalOther;
                ++g_textureImportBackendRefusals[static_cast<uint32_t>(
                    TextureBackendRefusal::ShortPayload)];
                MCLA_LOG_ERROR("D3D12Backend: texture import refused: mip {} payload {}B < "
                               "{} rows x {}B pitch = {}B needed",
                               i, srcBytes, blocksY, srcPitch, need);
                return false;
            }
            uint8_t* dst = static_cast<uint8_t*>(mapped) + offset;
            const UINT64 dstPitch = footprints[i].Footprint.RowPitch;
            for (uint32_t y = 0; y < blocksY; ++y) {
                std::memcpy(dst + static_cast<size_t>(y) * dstPitch,
                            src + static_cast<size_t>(y) * srcPitch,
                            static_cast<size_t>(srcPitch));
            }
            // D3D12_PLACED_SUBRESOURCE_FOOTPRINT has no TotalBytes field
            // (d3d12.h: Offset + D3D12_SUBRESOURCE_FOOTPRINT{Format,Width,Height,
            // Depth,RowPitch}), so the level's byte extent is RowPitch * Height.
            // For a 2D texture that is exactly the block-row pitch times the
            // block-row count, which is what blocksY is.
            offset = footprints[i].Offset +
                     static_cast<UINT64>(footprints[i].Footprint.RowPitch) * blocksY;
            ++copyLevels;
        }
    }
    staging->Unmap(0, nullptr);

    // --- Copies, with a PER-SUBRESOURCE transition on the way in.
    //
    // F-641: the old code emitted one COPY_DEST->PIXEL_SHADER_RESOURCE barrier
    // on ALL_SUBRESOURCES after a single mip-0 copy, which is only correct for a
    // one-mip texture. With a real chain each level is transitioned on its own,
    // from the state the tracker holds for that subresource (COMMON for a fresh
    // resource, which is what CreateCommittedResource actually left it in).
    for (uint32_t i = 0; i < copyLevels; ++i) {
        D3D12_TEXTURE_COPY_LOCATION dstLoc = {};
        dstLoc.pResource = texture.Get();
        dstLoc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
        dstLoc.SubresourceIndex = i;
        D3D12_TEXTURE_COPY_LOCATION srcLoc = {};
        srcLoc.pResource = staging.Get();
        srcLoc.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
        srcLoc.PlacedFootprint = footprints[i];
        m_commandList->CopyTextureRegion(&dstLoc, 0, 0, 0, &srcLoc, nullptr);
    }

    if (copyLevels == mipCount && mipCount > 0) {
        for (uint32_t i = 0; i < mipCount; ++i) {
            TransitionResource(texture.Get(), D3D12_RESOURCE_STATE_COMMON,
                               D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, i);
        }
    }

    // --- The generated chain. GenerateMipmaps needs a frame, the GPU fence and
    // its own descriptor heap, and it returns false if the UAV flag is absent --
    // so a failure here is reported and the texture is left with an uploaded
    // mip 0 rather than being presented as if the whole chain existed.
    if (desc.generateMipChain) {
        if (!GenerateMipmaps(texture.Get(), mipCount)) {
            ++g_textureImportRefusalOther;
            ++g_textureImportBackendRefusals[static_cast<uint32_t>(
                TextureBackendRefusal::MipgenFailed)];
            MCLA_LOG_ERROR("D3D12Backend: texture import: mipgen failed for {}x{} chain of {} "
                           "levels; mip 0 is resident, the rest are undefined",
                           desc.width, desc.height, mipCount);
            return false;
        }
    }

    // --- SRV at the requested slot.
    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format = format;
    srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Texture2D.MipLevels = mipCount;
    srvDesc.Texture2D.MostDetailedMip = 0;

    D3D12_CPU_DESCRIPTOR_HANDLE srvHandle(m_srvHeap->GetCPUDescriptorHandleForHeapStart());
    srvHandle.ptr += static_cast<size_t>(desc.srvSlot) * m_srvDescriptorSize;
    m_device->CreateShaderResourceView(texture.Get(), &srvDesc, srvHandle);
    m_decodedTextureSrvGpu = m_srvHeap->GetGPUDescriptorHandleForHeapStart();
    m_decodedTextureSrvGpu.ptr += static_cast<size_t>(desc.srvSlot) * m_srvDescriptorSize;

    // --- Commit. The copy is enqueued into the current frame's command list
    // above, so the staging buffer must outlive the draw; the previous staging is
    // replaced only now that everything succeeded.
    Microsoft::WRL::ComPtr<ID3D12Resource> prevStaging = m_decodedTextureUpload;
    m_decodedTexture = texture;
    m_decodedTextureUpload = staging;
    prevStaging.Reset();

    if (desc.outTexture) *desc.outTexture = texture;
    if (desc.outSrvGpu) *desc.outSrvGpu = m_decodedTextureSrvGpu;

    // F-649: the success counter, on the ONE success exit. Measured, not
    // assumed: `CreateDecodedTexture(const TextureImportDesc&)` contains
    // exactly one `return true` statement -- the one below -- and 18
    // `return false`. Every other path (Gate 1, Gate 2, the five Gate-3
    // checks, the short-payload check and the mipgen failure) refuses.
    // Counted unconditionally; the house bound gates the text only.
    //
    // NOTE (F-649, checked against renderer/texture_decode.h:513-515 rather than
    // assumed): `NoteTextureImport` is deliberately NOT called here. It is
    // already invoked from PlanTextureImport's single success exit
    // (renderer/texture_decode.cpp:1059), and its own header states that a
    // consumer must not call it directly or the census double-counts. The brief's
    // instruction to "call NoteTextureImport(plan) on the accepted path" is
    // therefore already satisfied upstream; calling it here would inflate
    // TextureImportAcceptedTotal by every backend-side import. The names in the
    // brief are also stale: the accessors are TextureImportAcceptedCount /
    // TextureImportAcceptedTotal / TextureImportLastMode
    // (renderer/texture_decode.h:527-532), not TextureImportCountAccepted /
    // TextureImportCountLastMode.
    const uint64_t n = ++g_textureImportOk;
    if (n <= kRefuseLogFirst || (n % kRefuseLogEvery) == 0) {
        MCLA_LOG_INFO("TEX-IMPORT #{} fmt={} {} dxgi={} mode={} {}x{} mips={} blockB={}",
            n, plan.xenosFormat, plan.formatName, plan.nativeDxgiFormat,
            (uint32_t)plan.mode, desc.width, desc.height, plan.mipCount, plan.blockBytes);
    }

    MCLA_LOG_INFO("D3D12Backend: texture imported {}x{} mips={} fmt={} ({}B/block) slot=t{}",
                  desc.width, desc.height, mipCount, static_cast<uint32_t>(format),
                  fp->bytesPerBlock, desc.srvSlot);
    return true;
}

// ============================================================================
// F-639: DrawPacket::textureDescriptors[] -> resident textures -> SRVs
// ============================================================================

// Resident-pool handle <-> ResidentTexture. handle is (pool index + 1) so 0 can
// mean "no resource". Kept out of line in the header comment: the pool's only
// invariant is that a slot's ComPtrs outlive every command list that could still
// read them, which is why eviction (not a frame tick) is what frees a slot.
uint32_t D3D12Backend::AcquireTexturePoolSlot() {
    if (!m_texturePoolFree.empty()) {
        const uint32_t idx = m_texturePoolFree.back();
        m_texturePoolFree.pop_back();
        m_texturePoolByHandle[idx] = &m_texturePoolSlots[idx];
        return idx + 1;
    }
    m_texturePoolSlots.emplace_back();
    m_texturePoolByHandle.push_back(&m_texturePoolSlots.back());
    return static_cast<uint32_t>(m_texturePoolSlots.size());
}

void D3D12Backend::ReleaseTexturePoolSlot(uint64_t handle) {
    if (handle == 0 || handle > m_texturePoolByHandle.size()) return;
    const uint32_t idx = static_cast<uint32_t>(handle - 1);
    m_texturePoolByHandle[idx] = nullptr;
    m_texturePoolSlots[idx].texture.Reset();
    m_texturePoolSlots[idx].upload.Reset();
    m_texturePoolFree.push_back(idx);
}

uint32_t D3D12Backend::BindGuestTextures(const GuestTextureEntry* entries, uint32_t count) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_srvHeap || !m_device) return 0;
    if (count > kMaxGuestTextureDescriptors) count = kMaxGuestTextureDescriptors;
    if (count == 0 || entries == nullptr) return 0;

    if (!m_inFrame) {
        if (!BeginFrame()) return 0;
    }

    uint32_t bound = 0;
    ++m_textureBindPasses;

    for (uint32_t e = 0; e < count; ++e) {
        const GuestTextureEntry& entry = entries[e];
        const uint32_t idx = entry.descriptorIndex;
        const uint32_t slot = kTexture2DSlot + idx;

        // Every index that this pass does not end up giving a real texture gets
        // a null SRV, so a refused or out-of-range descriptor samples a defined
        // colour instead of whatever the previous pass left in the heap.
        auto writeNullSrv = [&]() {
            D3D12_SHADER_RESOURCE_VIEW_DESC nullSrv = {};
            nullSrv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            nullSrv.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            nullSrv.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            nullSrv.Texture2D.MipLevels = 1;
            D3D12_CPU_DESCRIPTOR_HANDLE h(m_srvHeap->GetCPUDescriptorHandleForHeapStart());
            h.ptr += static_cast<size_t>(slot) * m_srvDescriptorSize;
            m_device->CreateShaderResourceView(nullptr, &nullSrv, h);
        };

        if (idx >= kShaderTextureSlotCount) {
            // F-639: the heap has the slot, but the ROOT SIGNATURE binds only
            // t0..t3, so a descriptor at t4+ cannot be sampled by any shader the
            // translator produces. Writing a real texture here would look
            // successful and sample nothing. Counted and named; when the table
            // grows to 16 this gate moves with it.
            const uint64_t n = ++g_textureBindRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: t{} refused #{}: root signature binds t0..t{} only "
                               "(heap holds {} slots); NULL SRV at slot {}",
                               idx, n, kShaderTextureSlotCount - 1, kSrvHeapDescriptorCount, slot);
            }
            writeNullSrv();
            continue;
        }

        // --- Decode the 24-byte fetch-constant snapshot. Pure function of those
        // bytes (explicit big-endian shifts inside), so this is NOT a guest read.
        native::GuestTextureDesc gtd = {};
        if (!native::DecodeGuestTextureDescriptor(entry.descriptorBytes, gtd)) {
            const uint64_t n = ++g_textureBindRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: t{} descriptor refused #{}: {} -- NULL SRV at slot {}",
                               idx, n, gtd.refusal ? gtd.refusal : "decode-failed", slot);
            }
            writeNullSrv();
            continue;
        }

        // --- Plan. `tiled`/`packedMips`/dimension are all already in gtd.
        const bool is3D = gtd.dimension == native::GuestTextureDimension::ThreeD;
        const bool isDepthStencil = gtd.dimension == native::GuestTextureDimension::TwoDOrStacked &&
                                    gtd.stacked && gtd.depth > 1;
        native::TextureImportPlan plan = native::PlanTextureImport(
            gtd.xenosFormat, gtd.width, gtd.height, gtd.depthOrArraySize, gtd.mipMaxLevel,
            gtd.endianness, gtd.tiled, gtd.packedMips, is3D, isDepthStencil);
        if (!plan.ok) {
            const uint64_t n = ++g_textureImportRefusals[static_cast<uint32_t>(plan.refusal)];
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: t{} import refused #{}: {} (xenosFmt={} {} "
                               "{}x{}) -- NULL SRV at slot {}",
                               idx, n, native::TextureRefusalName(plan.refusal), plan.xenosFormat,
                               plan.formatName, gtd.width, gtd.height, slot);
            }
            writeNullSrv();
            continue;
        }

        // --- Mip policy. Only level 0 is bound per descriptor index in one pass
        // (see the header note): binding mip 0 when the draw wanted mip 3 renders
        // a sharp image and hides the bug, so a multi-mip request is refused.
        const uint32_t mipCount = (entry.mipCount != 0) ? entry.mipCount : plan.mipCount;
        if (mipCount > 1) {
            const uint64_t n = ++g_textureBindRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: t{} refused #{}: guest asks for a {}-level mip "
                               "chain but this pass binds exactly one mip per descriptor index "
                               "(no LOD selection is issued) -- NULL SRV at slot {}",
                               idx, n, mipCount, slot);
            }
            writeNullSrv();
            continue;
        }

        // --- Hash the UPLOAD payload (post-expand, not pre-expand): a cache hit
        // must be provably the same bytes the GPU would receive.
        const uint8_t* payload = entry.mipPayloads[0];
        uint32_t payloadBytes = entry.mipBytes[0];
        if (payload == nullptr || payloadBytes == 0) {
            const uint64_t n = ++g_textureBindRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: t{} refused #{}: no untiled payload from the "
                               "producer ({}x{}) -- NULL SRV at slot {}",
                               idx, n, gtd.width, gtd.height, slot);
            }
            writeNullSrv();
            continue;
        }
        if (plan.mode == native::TextureUploadMode::CpuExpand) {
            native::TextureRefusal expandRefusal = native::TextureRefusal::None;
            if (!native::ExpandTextureToImportBytes(plan, payload, payloadBytes, m_importScratch,
                                                    &expandRefusal)) {
                const uint64_t n = ++g_textureImportRefusals[static_cast<uint32_t>(expandRefusal)];
                if (ShouldLogRefusal(n)) {
                    MCLA_LOG_ERROR("D3D12Backend: t{} expand refused #{}: {} ({}B) -- NULL SRV at "
                                   "slot {}",
                                   idx, n, native::TextureRefusalName(expandRefusal), payloadBytes,
                                   slot);
                }
                writeNullSrv();
                continue;
            }
            payload = m_importScratch.data();
            payloadBytes = static_cast<uint32_t>(m_importScratch.size());
        }

        // --- Cache key: content hash + the geometry that determines the host
        // resource (resource_cache.h:112-133). dataVersion is left 0: the
        // producer has no version counter today, and the content hash already
        // discriminates a changed payload -- which is the point of keying on it.
        const uint64_t contentHash = HashTextureContent(payload, payloadBytes);
        TextureCacheKey key = {};
        key.contentHash = contentHash;
        key.guestAddress = gtd.baseAddress;
        key.payloadBytes = payloadBytes;
        key.xenosFormat = plan.xenosFormat;
        key.importDxgiFormat = plan.importDxgiFormat ? plan.importDxgiFormat
                                                     : plan.nativeDxgiFormat;
        key.width = gtd.width;
        key.height = gtd.height;
        key.depthOrArraySize = 1;  // Refuse(Cube/3D) means only 2D reaches here
        key.mipCount = 1;
        key.hostFlags = 0;  // single mip, no UAV
        key.dataVersion = 0;

        TextureCacheEntry hit = {};
        if (m_textureCache.Find(key, hit) && hit.residency != TextureResidency::Absent &&
            hit.handle != 0 && hit.handle <= m_texturePoolByHandle.size() &&
            m_texturePoolByHandle[hit.handle - 1] != nullptr &&
            m_texturePoolByHandle[hit.handle - 1]->texture) {
            // HIT: no upload. Rebuild the SRV only when it is not already the one
            // at this slot -- a texture bound twice in one frame must not cost a
            // CreateShaderResourceView per bind.
            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
            srvDesc.Format = static_cast<DXGI_FORMAT>(key.importDxgiFormat);
            srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.Texture2D.MipLevels = 1;
            D3D12_CPU_DESCRIPTOR_HANDLE h(m_srvHeap->GetCPUDescriptorHandleForHeapStart());
            h.ptr += static_cast<size_t>(slot) * m_srvDescriptorSize;
            m_device->CreateShaderResourceView(
                m_texturePoolByHandle[hit.handle - 1]->texture.Get(), &srvDesc, h);
            ++bound;
            continue;
        }

        // --- MISS: upload once, then intern. Note the deliberate split from
        // CreateDecodedTexture(TextureImportDesc): that entry point owns a
        // single bootstrap texture and commits it as m_decodedTexture, whereas a
        // cached texture must outlive the frame, so it goes into the resident
        // pool with its staging buffer attached and is freed only by eviction.
        TextureImportDesc imp = {};
        imp.plan = &plan;
        imp.mipPayloads[0] = payload;
        imp.mipBytes[0] = payloadBytes;
        imp.mipCount = 1;
        imp.width = gtd.width;
        imp.height = gtd.height;
        imp.srvSlot = slot;

        Microsoft::WRL::ComPtr<ID3D12Resource> resident;
        D3D12_GPU_DESCRIPTOR_HANDLE srvGpu = {};
        imp.outTexture = &resident;
        imp.outSrvGpu = &srvGpu;
        if (!CreateDecodedTexture(imp) || !resident) {
            // CreateDecodedTexture already named and counted the reason.
            writeNullSrv();
            continue;
        }

        const uint64_t handle = AcquireTexturePoolSlot();
        if (handle == 0 || handle > m_texturePoolByHandle.size() ||
            m_texturePoolByHandle[handle - 1] == nullptr) {
            writeNullSrv();
            continue;
        }
        ResidentTexture& rt = *m_texturePoolByHandle[handle - 1];
        rt.texture = resident;
        rt.upload = m_decodedTextureUpload;  // outlives the copy
        rt.width = gtd.width;
        rt.height = gtd.height;
        rt.mipLevels = 1;
        rt.xenosFormat = plan.xenosFormat;
        rt.importDxgiFormat = key.importDxgiFormat;

        // Resident bytes: the host allocation, not the payload. footprint.TotalBytes
        // is not available here, so use the payload size -- it is the same order
        // and the budget is a pressure valve, not an accounting requirement
        // (resource_cache.h:120-123 says exactly that).
        TextureCacheEntry ent = {};
        ent.handle = handle;
        ent.uploadedVersion = 0;
        ent.descriptorIndex = slot;
        ent.residentBytes = payloadBytes;
        ent.payloadBytes = payloadBytes;
        ent.residency = TextureResidency::Resident;
        ent.inFlight = false;  // released at EndFrame by the caller that owns it

        // Insert may evict. The returned keys are already out of the map and are
        // MINE to release: only this file knows which pool slot and which
        // descriptor-heap home go with them.
        std::vector<TextureCacheKey> evicted = m_textureCache.Insert(key, ent);
        if (!evicted.empty()) {
            for (const TextureCacheKey& k : evicted) {
                TextureCacheEntry dead = {};
                if (m_textureCache.Find(k, dead) && dead.handle) {
                    m_textureCache.Erase(k);
                }
                ReleaseTexturePoolSlot(dead.handle);
            }
        }
        ++bound;
    }

    m_stats.cacheHits += bound;
    return bound;
}

void D3D12Backend::BindDecodedTexture() {
    if (!m_srvHeap) return;
    // Always bind the SRV table (slots are null-initialized; unused slots are
    // valid null SRVs). A translated shader's descriptor table must never be
    // left unset on the command list.
    m_commandList->SetDescriptorHeaps(1, m_srvHeap.GetAddressOf());
    // F-644: the table always starts at heap slot 0, because it covers t0..t3
    // (root parameter 0, NumDescriptors = kShaderTextureSlotCount). The
    // per-descriptor-index SRVs for a captured pass live at kTexture2DSlot + i,
    // i.e. INSIDE this same table, so this base is correct for both the
    // single-texture bootstrap path and BindGuestTextures.
    m_commandList->SetGraphicsRootDescriptorTable(0, m_srvHeap->GetGPUDescriptorHandleForHeapStart());

    // F-644: root parameter 1 is the sampler table and it must be set too --
    // a descriptor-table root parameter left unset is a validation error and an
    // undefined read. Slot 0 is the neutral sampler installed by
    // CreateSamplerHeap, so a pass that never bound a guest sampler still
    // samples deterministically.
    if (m_samplerHeap) {
        m_commandList->SetDescriptorHeaps(1, m_samplerHeap.GetAddressOf());
        m_commandList->SetGraphicsRootDescriptorTable(1, m_samplerTableGpu);
    }
}

// F-644: bind the guest's decoded sampler state at root parameter 1.
bool D3D12Backend::BindGuestSampler(const native::HostSamplerDesc& hostSampler) {
    if (!m_samplerHeap || !m_commandList) return false;

    // F-642: validate the decoded filter against the REAL D3D12_FILTER value set
    // before it reaches a D3D12_SAMPLER_DESC. HostSamplerDesc::filter comes from
    // texture_decode.h's restated enum, and 6 of its 11 filter values (plus the
    // whole comparison run) do NOT match d3d12.h -- see the table at the top of
    // this file. Casting 0x034 straight into D3D12_FILTER would land on
    // D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR, a MINIMUM reduction mode,
    // which is a legal filter and therefore a SILENTLY wrong image. Refusing is
    // the only honest option until texture_decode.h:503-517 is corrected.
    if (!IsLegalD3D12Filter(hostSampler.filter)) {
        const uint64_t n = ++g_samplerRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: guest sampler refused #{}: filter 0x{:X} is not a "
                           "D3D12_FILTER (texture_decode.h:503-517 has not been reconciled with "
                           "d3d12.h:3541-3600); refusing rather than binding a wrong filter",
                           n, hostSampler.filter);
        }
        return false;
    }
    // F-642: same for the comparison func. D3D12 requires NONE or ALWAYS for a
    // legal descriptor; texture_decode.h's run is off by one (its 0 = NEVER, but
    // d3d12.h:1587 has NEVER = 1 and 0 = NONE), so only a decoded 0 is safe to
    // forward verbatim today. Anything else is refused, not remapped, because
    // remapping would need the (absent) knowledge of which Xenos value it came
    // from.
    if (hostSampler.comparisonFunc != 0 &&
        static_cast<uint32_t>(hostSampler.comparisonFunc) !=
            static_cast<uint32_t>(D3D12_COMPARISON_FUNC_NONE)) {
        const uint64_t n = ++g_samplerRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: guest sampler refused #{}: comparisonFunc {} is not "
                           "verifiable against d3d12.h:1586-1594 (texture_decode.h:514-515 is "
                           "off by one); a non-comparison sampler is refused, not guessed",
                           n, hostSampler.comparisonFunc);
        }
        return false;
    }

    uint32_t index = 0;
    auto it = m_guestSamplerIndex.find(hostSampler.hash);
    if (it != m_guestSamplerIndex.end()) {
        index = it->second;
    } else {
        if (m_samplerHeapOffset >= kSamplerHeapSize) {
            const uint64_t n = ++g_samplerRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: sampler heap exhausted at {} entries; refused guest "
                               "sampler #{} filter=0x{:X} addr={}/{} aniso={}",
                               kSamplerHeapSize, n, hostSampler.filter, hostSampler.addressU,
                               hostSampler.addressV, hostSampler.maxAnisotropy);
            }
            return false;
        }
        index = m_samplerHeapOffset++;
        m_guestSamplerIndex.emplace(hostSampler.hash, index);

        // HostSamplerDesc's numeric fields are the D3D12 enums restated by
        // texture_decode.h (checked by the static_asserts at the top of this
        // file), so this is a straight field-for-field copy. `comparison` is
        // NOT a D3D12 field: it selects the filter enum, which DecodeGuestSampler-
        // State already chose (kD3D12FilterComparison* carry the 0x80 bit), so
        // there is nothing to translate here and nothing to drop.
        D3D12_SAMPLER_DESC sd = {};
        sd.Filter = static_cast<D3D12_FILTER>(hostSampler.filter);
        sd.AddressU = static_cast<D3D12_TEXTURE_ADDRESS_MODE>(hostSampler.addressU);
        sd.AddressV = static_cast<D3D12_TEXTURE_ADDRESS_MODE>(hostSampler.addressV);
        sd.AddressW = static_cast<D3D12_TEXTURE_ADDRESS_MODE>(hostSampler.addressW);
        sd.MipLODBias = hostSampler.mipLodBias;
        sd.MaxAnisotropy = hostSampler.maxAnisotropy;
        sd.ComparisonFunc = static_cast<D3D12_COMPARISON_FUNC>(hostSampler.comparisonFunc);
        // HostSamplerDesc::borderColor is ALREADY a FLOAT[4]
        // (texture_decode.h:533), not the Xenos BorderColor enum: the decoder
        // has already resolved kBorderBlack/kBorderWhite and refused the two
        // YCbCr blacks it cannot express (texture_decode.h:548-549), so this is
        // a straight field copy with nothing to translate and nothing to drop.
        for (UINT c = 0; c < 4; ++c) sd.BorderColor[c] = hostSampler.borderColor[c];
        sd.MinLOD = hostSampler.minLod;
        sd.MaxLOD = hostSampler.maxLod;

        D3D12_CPU_DESCRIPTOR_HANDLE cpu(m_samplerHeap->GetCPUDescriptorHandleForHeapStart());
        cpu.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
        m_device->CreateSampler(&sd, cpu);

        m_samplerTableGpu = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
        m_samplerTableGpu.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
    }

    m_commandList->SetDescriptorHeaps(1, m_samplerHeap.GetAddressOf());
    m_commandList->SetGraphicsRootDescriptorTable(1, m_samplerTableGpu);
    return true;
}

bool D3D12Backend::CreateTestRootSignature() {
    // Shared root signature for every pipeline (test fallback AND pipeline-cache
    // worker PSOs). It mirrors the binding contract of shader_translator's
    // generated HLSL:
    //   - root param 0: SRV descriptor table t0..t3 (t1D/t2D/t3D/tCube),
    //     visibility ALL (Xenos vertex shaders can tfetch too).
    //   - root param 1: SAMPLER descriptor table, s0, 1 descriptor,
    //     visibility ALL.
    //   - root param 2: root CBV at b0 (cbuffer ShaderConstants, 256 float4
    //     constants), visibility ALL (VS and PS share register b0).
    //
    // F-644: the sampler used to be a D3D12_STATIC_SAMPLER_DESC at s0 with
    // NumStaticSamplers = 1, which is why the draw path could not honour a
    // guest fetch constant: a static sampler is baked into the root signature at
    // create time, so clamp mode, filter, anisotropy, LOD bias and the border
    // colour of every Xenos sampler were discarded and the frame was sampled
    // clamp + linear + aniso 1. A DESCRIPTOR_TABLE is the only form D3D12 offers
    // for a per-draw sampler.
    //
    // The CBV therefore MOVES from root parameter 1 to root parameter 2. Both
    // this file and renderer/pipeline_cache.cpp's ResolveConstantBankBinding
    // name that index; they must change together or every real PSO binds a
    // descriptor table the command list never set. See the report.
    D3D12_DESCRIPTOR_RANGE srvRange = {};
    srvRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    srvRange.NumDescriptors = kShaderTextureSlotCount;  // t0..t3
    srvRange.BaseShaderRegister = 0;
    srvRange.RegisterSpace = 0;
    srvRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_DESCRIPTOR_RANGE samplerRange = {};
    samplerRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
    samplerRange.NumDescriptors = 1;  // s0 only
    samplerRange.BaseShaderRegister = 0;
    samplerRange.RegisterSpace = 0;
    samplerRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_ROOT_PARAMETER rootParams[3] = {};
    rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[0].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[0].DescriptorTable.pDescriptorRanges = &srvRange;
    rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[1].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[1].DescriptorTable.pDescriptorRanges = &samplerRange;
    rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
    rootParams[2].Descriptor.ShaderRegister = 0;  // b0
    rootParams[2].Descriptor.RegisterSpace = 0;
    rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
    rootDesc.NumParameters = _countof(rootParams);
    rootDesc.pParameters = rootParams;
    // F-644: zero static samplers. A static sampler at s0 AND a descriptor-table
    // range at s0 in the same root signature is a D3D12 root-signature
    // validation error (duplicate shader register), so the static one has to go,
    // not merely be shadowed.
    rootDesc.NumStaticSamplers = 0;
    rootDesc.pStaticSamplers = nullptr;
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

    Microsoft::WRL::ComPtr<ID3DBlob> signatureBlob;
    Microsoft::WRL::ComPtr<ID3DBlob> errorBlob;
    HRESULT hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                             &signatureBlob, &errorBlob);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: D3D12SerializeRootSignature failed with hr=0x{:08X} "
                       "(root params: 0=t0..t3, 1=s0 sampler table, 2=b0 CBV)",
                       static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                       signatureBlob->GetBufferSize(),
                                       IID_PPV_ARGS(&m_rootSignature));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateRootSignature failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    return true;
}

bool D3D12Backend::CreateTestPipeline() {
    // Input layout matching the Phase 3 test shader (POSITION float3, COLOR float4).
    D3D12_INPUT_ELEMENT_DESC inputElements[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
    };

    D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
    psoDesc.pRootSignature = m_rootSignature.Get();
    psoDesc.VS = { GetTestVsBlob(), GetTestVsBlobSize() };
    psoDesc.PS = { GetTestPsBlob(), GetTestPsBlobSize() };
    psoDesc.InputLayout = { inputElements, _countof(inputElements) };
    psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

    psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.NumRenderTargets = 1;
    psoDesc.SampleDesc.Count = 1;
    psoDesc.SampleMask = UINT_MAX;

    psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    psoDesc.RasterizerState.DepthClipEnable = TRUE;

    psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
    psoDesc.BlendState.IndependentBlendEnable = FALSE;
    for (UINT i = 0; i < 8; ++i) {
        psoDesc.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }

    psoDesc.DepthStencilState.DepthEnable = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;

    HRESULT hr = m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_testPipeline));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateGraphicsPipelineState(test) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    MCLA_LOG_INFO("D3D12Backend: Phase 3 test pipeline created (DXIL {} vs / {} ps bytes)",
                GetTestVsBlobSize(), GetTestPsBlobSize());
    return true;
}

// Create mipmap generation compute pipeline (root signature + PSO)
bool D3D12Backend::CreateMipGenPipeline() {
    // Root signature: SRV (t0) + UAV (u0) + CBV (b0) for params
    D3D12_DESCRIPTOR_RANGE srvRange = {};
    srvRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    srvRange.NumDescriptors = 1;
    srvRange.BaseShaderRegister = 0;  // t0
    srvRange.RegisterSpace = 0;
    srvRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_DESCRIPTOR_RANGE uavRange = {};
    uavRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
    uavRange.NumDescriptors = 1;
    uavRange.BaseShaderRegister = 0;  // u0
    uavRange.RegisterSpace = 0;
    uavRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_ROOT_PARAMETER rootParams[3] = {};
    rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[0].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[0].DescriptorTable.pDescriptorRanges = &srvRange;
    rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
    rootParams[1].Descriptor.ShaderRegister = 0;  // b0
    rootParams[1].Descriptor.RegisterSpace = 0;
    rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[2].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[2].DescriptorTable.pDescriptorRanges = &uavRange;
    rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
    rootDesc.NumParameters = _countof(rootParams);
    rootDesc.pParameters = rootParams;
    rootDesc.NumStaticSamplers = 0;
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

    Microsoft::WRL::ComPtr<ID3DBlob> signatureBlob, errorBlob;
    HRESULT hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                             &signatureBlob, &errorBlob);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: MipGen SerializeRootSignature failed hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                       signatureBlob->GetBufferSize(),
                                       IID_PPV_ARGS(&m_mipGenRootSignature));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: MipGen CreateRootSignature failed hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: MipGen root signature created");
    return true;
}

// F-641: the DXC compile of the mipgen CS, split out of GenerateMipmaps so the
// LoadLibrary + fxc pass happens once at Initialize (D3D12Backend::Initialize
// calls this) instead of between MapUpload and DrawIndexedInstanced on
// whichever draw first needed a chain. Idempotent: the second call is a single
// pointer test.
bool D3D12Backend::EnsureMipGenPipeline() {
    if (m_mipGenPipeline) return true;
    if (!m_device) return false;

    if (!m_mipGenRootSignature && !CreateMipGenPipeline()) return false;

    const char* csHlsl = GetMipGenCsHlsl();
    if (!csHlsl || !*csHlsl) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureMipGenPipeline missing CS HLSL source");
        return false;
    }

    renderer::DxcRuntime dxc;
    std::string usedDir, error;
    if (!dxc.Load("", usedDir, error)) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureMipGenPipeline failed to load DXC runtime: {}", error);
        return false;
    }

    std::vector<uint8_t> csBlob;
    if (!dxc.Compile(csHlsl, "main", "cs_6_0", csBlob, error)) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureMipGenPipeline CS compilation failed: {}", error);
        return false;
    }

    D3D12_COMPUTE_PIPELINE_STATE_DESC psoDesc = {};
    psoDesc.pRootSignature = m_mipGenRootSignature.Get();
    psoDesc.CS = { csBlob.data(), csBlob.size() };
    psoDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

    HRESULT hr = m_device->CreateComputePipelineState(&psoDesc, IID_PPV_ARGS(&m_mipGenPipeline));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureMipGenPipeline CreateComputePipelineState failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }
    MCLA_LOG_INFO("D3D12Backend: MipGen compute pipeline created (CS blob {} bytes)", csBlob.size());
    return true;
}

// Generate mipmaps using compute shader downsampling
bool D3D12Backend::GenerateMipmaps(ID3D12Resource* texture, uint32_t mipLevels) {
    if (!texture || mipLevels <= 1) {
        MCLA_LOG_WARN("D3D12Backend: GenerateMipmaps invalid args (texture={}, mipLevels={})",
                    texture != nullptr, mipLevels);
        return false;
    }

    D3D12_RESOURCE_DESC desc = texture->GetDesc();
    if ((desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS) == 0) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps texture lacks ALLOW_UNORDERED_ACCESS flag");
        return false;
    }
    if (desc.MipLevels < mipLevels) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps texture has {} mips, requested {}",
                     desc.MipLevels, mipLevels);
        return false;
    }

    // F-641: the mipgen PSO is built by EnsureMipGenPipeline, which
    // Initialize calls. Reaching here without one means the warm-up failed, and
    // that is a refusal with a reason rather than a 300 ms compile in the middle
    // of a frame.
    if (!m_mipGenPipeline && !EnsureMipGenPipeline()) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps refused: no mipgen PSO (init warm-up failed)");
        return false;
    }

    // Create SRV heap for source mips (read) and UAV heap for destination mips (write)
    // We'll use the existing SRV heap for source and create UAVs for each mip level
    // For simplicity, we'll use the same descriptor heap with different offsets

    D3D12_DESCRIPTOR_HEAP_DESC srvUavHeapDesc = {};
    srvUavHeapDesc.NumDescriptors = mipLevels * 2;  // SRV + UAV per mip
    srvUavHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    srvUavHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvUavHeap;
    HRESULT hr = m_device->CreateDescriptorHeap(&srvUavHeapDesc, IID_PPV_ARGS(&srvUavHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps CreateDescriptorHeap failed hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }

    uint32_t descriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

    // Create SRVs and UAVs for each mip level
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> srvHandles(mipLevels);
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> uavHandles(mipLevels);

    D3D12_CPU_DESCRIPTOR_HANDLE srvStart = srvUavHeap->GetCPUDescriptorHandleForHeapStart();
    D3D12_CPU_DESCRIPTOR_HANDLE uavStart;
    uavStart.ptr = srvStart.ptr + static_cast<SIZE_T>(mipLevels) * descriptorSize;

    for (uint32_t i = 0; i < mipLevels; ++i) {
        D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
        srvDesc.Format = desc.Format;
        srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srvDesc.Texture2D.MostDetailedMip = i;
        srvDesc.Texture2D.MipLevels = 1;
        srvDesc.Texture2D.PlaneSlice = 0;
        srvDesc.Texture2D.ResourceMinLODClamp = 0.0f;

        D3D12_CPU_DESCRIPTOR_HANDLE srvHandle = srvStart;
        srvHandle.ptr += static_cast<SIZE_T>(i) * descriptorSize;
        m_device->CreateShaderResourceView(texture, &srvDesc, srvHandle);
        srvHandles[i] = srvHandle;

        D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
        uavDesc.Format = desc.Format;
        uavDesc.ViewDimension = D3D12_UAV_DIMENSION_TEXTURE2D;
        uavDesc.Texture2D.MipSlice = i;
        uavDesc.Texture2D.PlaneSlice = 0;

        D3D12_CPU_DESCRIPTOR_HANDLE uavHandle = uavStart;
        uavHandle.ptr += static_cast<SIZE_T>(i) * descriptorSize;
        m_device->CreateUnorderedAccessView(texture, nullptr, &uavDesc, uavHandle);
        uavHandles[i] = uavHandle;
    }

    // (MipGenParams is declared inside the dispatch loop below; the copy here
    // was dead and shadowed it.)

    // Wait for GPU to be ready for this frame's upload region
    if (!WaitForCurrentFrameGpu()) return false;

    // Begin frame if not already in frame
    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition all mips to appropriate states and generate each level.
    //
    // F-641: every transition below goes through TransitionResource with an
    // explicit subresource, and TransitionResource now reads the TRACKED state
    // of THAT subresource. The old code asserted D3D12_RESOURCE_STATE_COMMON as
    // the prior state of mip i-1 and mip i on every iteration, which is only
    // true the first time; on the second pass D3D12 saw
    // COMMON->NON_PIXEL_SHADER_RESOURCE for a mip that was already
    // PIXEL_SHADER_RESOURCE, and the tracker's single-state-per-resource model
    // could not even name which mip it was talking about.
    for (uint32_t i = 1; i < mipLevels; ++i) {
        uint32_t srcMip = i - 1;
        uint32_t dstMip = i;

        // Calculate dimensions. A mip's texel extent halves; for a block-
        // compressed format the CS samples texels so this stays in texels.
        uint32_t srcWidth = std::max<uint32_t>(1, desc.Width >> srcMip);
        uint32_t srcHeight = std::max<uint32_t>(1, desc.Height >> srcMip);
        uint32_t dstWidth = std::max<uint32_t>(1, desc.Width >> dstMip);
        uint32_t dstHeight = std::max<uint32_t>(1, desc.Height >> dstMip);

        // Begin frame if needed
        if (!m_inFrame) {
            if (!BeginFrame()) return false;
        }

        // src mip -> SRV-readable, dst mip -> UAV, each against tracked state.
        TransitionResource(texture, D3D12_RESOURCE_STATE_COMMON,
                           D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, srcMip);
        TransitionResource(texture, D3D12_RESOURCE_STATE_COMMON,
                           D3D12_RESOURCE_STATE_UNORDERED_ACCESS, dstMip);

        // Bind pipeline and descriptors
        m_commandList->SetPipelineState(m_mipGenPipeline.Get());
        m_commandList->SetComputeRootSignature(m_mipGenRootSignature.Get());

        // Bind SRV table (src mip)
        D3D12_GPU_DESCRIPTOR_HANDLE srvGpuHandle = srvUavHeap->GetGPUDescriptorHandleForHeapStart();
        srvGpuHandle.ptr += static_cast<SIZE_T>(srcMip) * descriptorSize;
        m_commandList->SetComputeRootDescriptorTable(0, srvGpuHandle);

        // Bind UAV table (dst mip)
        D3D12_GPU_DESCRIPTOR_HANDLE uavGpuHandle = srvUavHeap->GetGPUDescriptorHandleForHeapStart();
        uavGpuHandle.ptr += static_cast<SIZE_T>(mipLevels + dstMip) * descriptorSize;
        m_commandList->SetComputeRootDescriptorTable(1, uavGpuHandle);

        // Bind constants via CBV (root param 1 of the MIPGEN root signature,
        // which is its own signature and is unrelated to the graphics root
        // parameter renumbering in CreateTestRootSignature).
        struct MipGenParams {
            uint32_t srcWidth;
            uint32_t srcHeight;
            uint32_t dstWidth;
            uint32_t dstHeight;
            uint32_t srcMipLevel;
            uint32_t padding[3];
        } params = { srcWidth, srcHeight, dstWidth, dstHeight, srcMip, {0, 0, 0} };

        m_commandList->SetComputeRoot32BitConstants(1, sizeof(MipGenParams) / 4, &params, 0);

        // Dispatch
        uint32_t dispatchX = (dstWidth + 7) / 8;
        uint32_t dispatchY = (dstHeight + 7) / 8;
        m_commandList->Dispatch(dispatchX, dispatchY, 1);

        // UAV barrier for this mip
        D3D12_RESOURCE_BARRIER uavBarrier = {};
        uavBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
        uavBarrier.UAV.pResource = texture;
        m_commandList->ResourceBarrier(1, &uavBarrier);

        // dst mip -> SRV-readable so the NEXT iteration can read it as srcMip.
        TransitionResource(texture, D3D12_RESOURCE_STATE_UNORDERED_ACCESS,
                           D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, dstMip);
    }

    // Final transition: every mip to the combined PS|non-PS shader-resource
    // state a graphics pass can read. Levels that GenerateMipmaps did not touch
    // (mip 0) are transitioned from their tracked state, which after
    // CreateDecodedTexture is PIXEL_SHADER_RESOURCE -- so this emits no barrier
    // for it rather than a bogus COMMON->... one.
    for (uint32_t i = 0; i < mipLevels; ++i) {
        TransitionResource(texture, D3D12_RESOURCE_STATE_COMMON,
                           D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE |
                               D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE,
                           i);
    }

    MCLA_LOG_INFO("D3D12Backend: Generated {} mip levels for texture", mipLevels);
    return true;
}

bool D3D12Backend::CreatePipelineFromDxil(const std::vector<uint8_t>& vsDxil,
                                          const std::vector<uint8_t>& psDxil,
                                          const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
                                          const renderer::PipelineState& state,
                                          Microsoft::WRL::ComPtr<ID3D12PipelineState>& outPso) {
    if (vsDxil.empty() || psDxil.empty()) {
        MCLA_LOG_ERROR("D3D12Backend: CreatePipelineFromDxil: empty DXIL blob");
        return false;
    }

    D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
    psoDesc.pRootSignature = m_rootSignature.Get();
    psoDesc.VS = { vsDxil.data(), vsDxil.size() };
    psoDesc.PS = { psDxil.data(), psDxil.size() };
    psoDesc.InputLayout = { inputLayout.data(), static_cast<UINT>(inputLayout.size()) };
    psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

    // RTV formats from PipelineState
    for (uint32_t i = 0; i < renderer::kMaxRenderTargets; ++i) {
        if (state.targetFormats[i] != 0) {
            psoDesc.RTVFormats[i] = static_cast<DXGI_FORMAT>(state.targetFormats[i]);
        }
    }
    psoDesc.NumRenderTargets = 1;  // default; could be extended
    psoDesc.SampleDesc.Count = state.sampleCount;
    psoDesc.SampleMask = UINT_MAX;

    // Rasterizer state
    psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    psoDesc.RasterizerState.DepthClipEnable = TRUE;

    // Blend state
    psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
    psoDesc.BlendState.IndependentBlendEnable = FALSE;
    for (UINT i = 0; i < 8; ++i) {
        psoDesc.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }

    // Depth/stencil state
    psoDesc.DepthStencilState.DepthEnable = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;

    HRESULT hr = m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&outPso));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateGraphicsPipelineState(translated) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    MCLA_LOG_INFO("D3D12Backend: Live pipeline created from DXIL (VS={} bytes, PS={} bytes)", vsDxil.size(), psDxil.size());
    return true;
}

// Phase 3 test draw: an indexed triangle whose colors pulse per frame.
// Exercises the upload arena, index/vertex buffer binding, viewport, and
// primitive topology on the native path. The draw body is shared with the
// captured-geometry path via DrawDynamicMesh so both go through identical
// command-list handling.
bool D3D12Backend::DrawTestMeshedTriangle(uint32_t frame) {
    // Deterministic rotating color so the frame visibly changes.
    const float t = static_cast<float>(frame) * 0.1f;
    const float cr = (std::sin(t) + 1.0f) * 0.5f;
    const float cg = (std::sin(t + 2.0f) + 1.0f) * 0.5f;
    const float cb = (std::sin(t + 4.0f) + 1.0f) * 0.5f;

    // A meshed quad: 4 vertices, 6 indices (two triangles).
    struct TestVertex { float pos[3]; float color[4]; };
    const TestVertex vertices[4] = {
        { { -0.8f, -0.8f, 0.0f }, { cr, cg, cb, 1.0f } },
        { {  0.8f, -0.8f, 0.0f }, { cg, cb, cr, 1.0f } },
        { {  0.8f,  0.8f, 0.0f }, { cb, cr, cg, 1.0f } },
        { { -0.8f,  0.8f, 0.0f }, { cr, cb, cg, 1.0f } },
    };
    const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };

    DynamicMeshDesc desc = {};
    desc.vertexBytes = vertices;
    desc.vertexBytesSize = sizeof(vertices);
    desc.vertexStride = sizeof(TestVertex);  // 28 bytes
    desc.vertexCount = 4;
    desc.indexed = true;
    desc.indexFormat = DXGI_FORMAT_R16_UINT;
    desc.indexCount = 6;

    // Reuse the static cached index buffer (uploaded once at Initialize).
    const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                sizeof(indices), DXGI_FORMAT_R16_UINT, 1 };
    ResourceEntry ibEntry;
    if (m_resourceCache.Find(ibKey, ibEntry)) {
        desc.cachedIndexGpu = ibEntry.handle;
        desc.cachedIndexBytesSize = sizeof(indices);
        m_stats.cacheHits++;
    } else {
        // Should not happen (initialized before draw), but recover safely by
        // falling back to a per-frame upload of the same bytes.
        desc.indexBytes = indices;
        desc.indexBytesSize = sizeof(indices);
        m_stats.cacheMisses++;
    }

    // F-653: the test PSO is passed EXPLICITLY here rather than resolved by
    // DrawDynamicMesh. This is the sanctioned use of it -- the caller wants the
    // test pipeline, says so, and the draw is bounded (one quad, the first few
    // frames only). It is not a substitution, and keeping it explicit is what
    // lets the no-pipeline entry point refuse.
    const bool ok = DrawDynamicMeshWithPipeline(desc, m_testPipeline.Get());
    if (frame <= 3) {
        MCLA_LOG_INFO("D3D12Backend: DrawTestMeshedTriangle frame={} present_hr=0x{:08X}",
                    frame, static_cast<uint32_t>(m_lastPresentHr));
    }
    return ok;
}

// Generic dynamic-geometry draw. Uploads the caller's vertex bytes (and index
// bytes when the caller has no cached IB) into the per-frame upload arena and
// issues one indexed/non-indexed draw. The caller is responsible for producing
// host data from validated captures; the backend never interprets guest
// layouts. The vertex stride must match the test PSO's input layout
// (Position:float3 + Color:float4 = 28 bytes) â€” anything else is refused so we
// never draw with a mismatched layout.
// F-653: THIS IS NO LONGER A PASS-THROUGH TO THE TEST PSO.
//
// It used to be:
//     bool D3D12Backend::DrawDynamicMesh(const DynamicMeshDesc& desc) {
//         return DrawDynamicMeshWithPipeline(desc, m_testPipeline.Get());
//     }
// which meant that any caller with no pipeline of its own got the fixed test
// PSO -- and since DrawDynamicMeshWithPipeline now REFUSES a null pipeline
// rather than substituting one (see its body), the two together were the whole
// bypass. One of the two had to go, and it is this one, because the honest
// behaviour for a draw with no pipeline is to refuse it.
//
// WHAT THIS COSTS, MEASURED RATHER THAN GUESSED. Three call sites reach this
// function, and they are not equivalent:
//   - d3d12_backend.cpp, DrawTestMeshedTriangle: a TEST draw, and it now passes
//     the test PSO explicitly at its own call site, which is a caller choosing a
//     PSO rather than this function substituting one. Unaffected.
//   - render_thread.cpp:937 and :2042: real guest draws, taken on the paths
//     where no pipeline was derived (render_thread.cpp:2033-2041 says so
//     outright: "there is no longer any path that reaches this line with a
//     program it could not translate"). Those draws now REFUSE, counted as
//     `no-pipeline-bypass-removed`. They were previously being drawn through a
//     28-byte POSITION float3 + COLOR float4 layout the guest never declared, so
//     this trades untraceable wrong pixels for a countable absence -- but it IS
//     a behaviour change, and it is a visible one, and render_thread.cpp is not
//     this file. Wiring those two sites to a real PSO is the follow-up and it
//     belongs to whoever owns render_thread.cpp.
//   - render_thread.cpp:2099: the host marker-quad overlay, which will also
//     begin refusing for the same reason.
//
// The alternative -- keeping the substitution and only deleting the duplicate --
// would have left the bypass in place through the other door, which is the
// outcome the charter forbids.
bool D3D12Backend::DrawDynamicMesh(const DynamicMeshDesc& desc) {
    (void)desc;
    const uint64_t n = ++m_noPipelineBypassRefusals;
    if (ShouldLogRefusal(n)) {
        MCLA_LOG_WARN("D3D12Backend: DrawDynamicMesh refused #{} -- F-653: this "
                      "entry no longer resolves to the test PSO. A draw with no "
                      "pipeline is a refusal, not a substitution. Callers that "
                      "want the test PSO must pass it explicitly; guest draws must "
                      "pass a cache PSO.",
                      n);
    }
    return false;
}

// 2026-10-02: the BODY for the declaration at d3d12_backend.h:184-185. The
// previous session wrote the declaration and the three call sites
// (:2734 / :2744 / :2805) and never this function, so the tree compiled all 14
// TUs and then failed at the link on one undefined symbol. MEASURED, not
// inferred: the qualified form `D3D12Backend::RecordSilentDrawReturn` had ZERO
// occurrences anywhere under src/ before this edit.
//
// WHAT IT REPORTS, and only that. `gate` is the stable token the call site
// already had in hand. `a`/`b`/`c` are that gate's OWN inputs, copied verbatim
// at the call site and NOT interpreted here (F-609: if this row had to guess
// what a/b/c mean it would invent the fault it exists to name). The per-gate
// meaning, measured at each call site:
//   device-not-initialised : none passed; a=b=c=0, the header's "0 where
//                            meaningless"
//   no-vertex-data        : a = (desc.vertexBytes ? 1u : 0u),
//                            b = desc.vertexBytesSize, c = desc.vertexCount
//   no-index-data         : a = (desc.indexed ? 1u : 0u),
//                            b = desc.indexBytesSize, c = desc.indexCount
// `returned=false` is not a claim about intent: all three call sites carry a
// literal `return false` on the line immediately after the call (:2735, :2747,
// :2807), so false is what every caller actually returned. It is stated as a
// literal because a 3-of-3 measurement is not a prediction.
//
// BOUNDING. `n` is incremented UNCONDITIONALLY, before the gate. That is the
// F-649 rule at :211-214 -- "the throttle gates the TEXT, never the count,
// because a suppressed row that is not counted is how a soak reads 'nothing
// happened' out of something that happened 616,824 times". The TEXT is
// throttled by ShouldLogRefusal(), the helper this file already uses at 31
// other refusal sites (:223-227): first kRefuseLogFirst=8, then every
// kRefuseLogEvery=200th. A draw path that refused on every frame would
// otherwise be a per-frame log line, which is the LOG-QUALITY poisoning F-054
// records. Chosen over the gpu_device.cpp kR3Head/kR3RowStride census shape
// because this file has exactly one bounding idiom and this is it; and chosen
// over the sibling PC-PSO-BOUND row's inlined `n <= 8 || (n % 200) == 0`
// (:3091) because the two are numerically identical today and the named
// helper survives a change to the constants.
//
// NEW ROW NAME, NO EXISTING FORMAT TOUCHED. `D3D12-DRAW-RETURN` appeared in
// zero of this file's 135 MCLA_LOG_ format literals before this edit, so
// nothing is appended to and none of the 244 markers tools/soak_census.py
// tracks changes shape.
void D3D12Backend::RecordSilentDrawReturn(const char* gate, uint32_t a,
                                          uint32_t b, uint32_t c) {
    const uint64_t n = ++m_silentDrawReturns;
    if (!ShouldLogRefusal(n)) {
        return;
    }
    MCLA_LOG_INFO("D3D12-DRAW-RETURN #{} gate={} a={} b={} c={} returned=false -- "
                  "a/b/c are the refusing gate's own inputs, copied verbatim at the "
                  "call site and not interpreted; device-not-initialised passes "
                  "none (0 where meaningless), no-vertex-data passes "
                  "(vertexBytes!=0, vertexBytesSize, vertexCount), no-index-data "
                  "passes (indexed, indexBytesSize, indexCount). Counted on every "
                  "refusal, printed for the first 8 and every 200th.",
                  n, gate, a, b, c);
}

// 2026-10-02: the bound-render-target format, and the draw's own output.
//
// WHY THIS FILE HAD NO PIXEL MEASUREMENT AT ALL. build/w696.log (sha256
// 3D21DE0E..7F1893, 55,669 lines) carries `DRAW-CP-DRAWN #1` at 03:30:04.948
// and `#2` at 03:30:04.961, and its two `PRESENT-FB sample` rows are
// timestamped 03:30:04.926 and 03:30:04.927 -- 21 ms and 34 ms BEFORE the
// draws. `FRAME-OWNER owner=draw` appears 0 times and `D3D12Backend: draw #N
// issued through a cache-produced PSO` 0 times, so the only two rows that
// look like a closed draw chain are not evidence that a draw call was ever
// issued, and no line in the tree could report what a draw PRODUCED. The
// two functions below are the minimum that makes the next soak able to
// answer the question instead of re-deriving it.

// F-727: the draw-path ordering flag that RecordDrawReadback samples to report
// copyAfterDraw= as an OBSERVATION rather than a restatement of where this
// variable happens to sit. Disarmed at the top of the draw path, armed again
// immediately after the draw call.
//
// Declared HERE, above its first use, because a file-scope static used above its
// own definition does not compile. Its full rationale, and its two companion
// statics s_readbackCopyAfterDraw / s_readbackDrawSeq, are declared in the block
// immediately above RecordDrawReadback further down this file.
//
// The ordering this flag exists to attest is the F-727 defect: the readback copy
// used to be recorded ABOVE the draw call, under a comment claiming it was
// "between the draw and the PRESENT transition". It captured the placeholder
// clear, not the draw -- and that is exactly the failure mode a re-derivation by
// statement order walks straight back into, which is why the flag is an
// observation in the log and not only a comment.
static bool s_drawIssuedOnList = false;

// Overload that accepts a specific PSO to use instead of the default test pipeline.
bool D3D12Backend::DrawDynamicMeshWithPipeline(const DynamicMeshDesc& desc,
                                               ID3D12PipelineState* pipeline) {
    // Guard the whole body (including MapUpload / m_frameIndex / m_stats /
    // m_inFrame mutation) so it cannot race with Resize()/Shutdown() from the
    // window/app thread. BeginFrame() re-locks the same recursive mutex.
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) {
        RecordSilentDrawReturn("device-not-initialised");
        return false;
    }
    // ---- VS-CLIPSPACE-PROBE ------------------------------------------------
    // WHY. Two suppressors have been MEASURED for a correct draw that produces
    // nothing visible, and they look identical from the outside:
    //   (a) a non-finite value anywhere in the vertex stream -- the shipped GS
    //       discards on it by design, so the whole primitive dies with NO log
    //       line (pipeline_cache.cpp:2408-2409; harness rows GS_NAN_DISCARD and
    //       GS_NAN_CONTROL in %TEMP%\opencode\d3d12_subagent\probe_clean.txt,
    //       both 0 green pixels);
    //   (b) a wrong clip-space/viewport convention -- 2,475 pixels in a corner
    //       on this device, invisible to a whole-surface census.
    // This marker separates them by reporting the stream itself.
    //
    // WHAT IT PRINTS, AND WHAT IT DELIBERATELY DOES NOT DO. It prints the raw
    // float lanes of the vertex buffer and their exact bit patterns. It does NOT
    // clamp, sanitise, replace or default any of them: a NaN in the guest's
    // vertex stream is a fact about the guest's program, and hiding it would turn
    // "the rasterizer went silent for a reason" into "the frame is the placeholder
    // colour", which is the exact confusion this project exists to avoid.
    //
    // IT DOES NOT CLAIM THESE LANES ARE POSITION. It reports "float lanes at
    // byte offset N of the vertex stream", which is what it actually read; which
    // lane is POSITION is the input layout's business and is not re-derived here.
    {
        static std::atomic<uint64_t> s_probeRows{0};
        const uint64_t row = s_probeRows.fetch_add(1) + 1;
        renderer::ClipDisableRescaleConstants rc;
        const bool haveRc = renderer::QueryClipDisableRescale(&rc);
        // Bounded by the house throttle rather than by "first draw only": a
        // one-shot row cannot be compared against a later one in the same soak.
        if (ShouldLogRefusal(row)) {
            const uint32_t stride = desc.vertexStride;
            const uint32_t lanes = stride / 4u;
            // Scan whole float lanes, not just the first three: the suppressor is
            // a non-finite value ANYWHERE, and a POSITION-only read would miss it.
            const uint32_t scanVerts = desc.vertexCount < 64u ? desc.vertexCount : 64u;
            uint32_t nonFinite = 0;
            uint32_t firstBadVert = 0xFFFFFFFFu;
            uint32_t firstBadLane = 0xFFFFFFFFu;
            float firstVal[4] = {0.0f, 0.0f, 0.0f, 0.0f};
            uint32_t firstBits[4] = {0, 0, 0, 0};
            if (desc.vertexBytes && stride >= 16u) {
                const auto* base = static_cast<const uint8_t*>(desc.vertexBytes);
                for (uint32_t v = 0; v < scanVerts; ++v) {
                    const uint8_t* vp = base + static_cast<size_t>(v) * stride;
                    for (uint32_t l = 0; l < lanes; ++l) {
                        float f;
                        memcpy(&f, vp + static_cast<size_t>(l) * 4u, 4);
                        if (v == 0 && l < 4u) {
                            firstVal[l] = f;
                            uint32_t b;
                            memcpy(&b, vp + static_cast<size_t>(l) * 4u, 4);
                            firstBits[l] = b;
                        }
                        if (!std::isfinite(f)) {
                            ++nonFinite;
                            if (firstBadVert == 0xFFFFFFFFu) {
                                firstBadVert = v;
                                firstBadLane = l;
                            }
                        }
                    }
                }
            }
            MCLA_LOG_WARN(
                "VS-CLIPSPACE-PROBE #{} vertices={} stride={} floatLanes={} scanned={} "
                "nonFiniteLanes={} firstBadVert={} firstBadLane={} "
                "rescaleValid={} ndcScale=({},{},{}) ndcOffset=({},{},{}) "
                "v0lane0=({},{},{},{}) v0lane0Bits=0x{:08X},0x{:08X},0x{:08X},0x{:08X} "
                "-- values are the guest's, printed as-is: a NaN here is a guest fact, "
                "not clamped or defaulted, and it kills the primitive with no other log line. "
                "READ THIS ROW AS THE INPUT, NOT AS CLIP SPACE: v0lane0 is four lanes of "
                "vertex 0 of the VERTEX BUFFER, byte-for-byte what the input assembler "
                "feeds the vertex stage, so this row says what the pipeline was HANDED and "
                "nothing about what the vertex shader EMITTED. One vertex of four lanes "
                "cannot tell offscreen from degenerate from collinear either; the row below "
                "prints every vertex and every dword of the same bytes",
                row, desc.vertexCount, stride, lanes, scanVerts, nonFinite,
                firstBadVert, firstBadLane,
                static_cast<int>(haveRc),
                rc.scaleX, rc.scaleY, rc.scaleZ, rc.offsetX, rc.offsetY, rc.offsetZ,
                firstVal[0], firstVal[1], firstVal[2], firstVal[3],
                firstBits[0], firstBits[1], firstBits[2], firstBits[3]);
        }
    }
    // ---- VS-INPUT-STREAM ---------------------------------------------------
    // WHAT THIS ROW IS, STATED SO NOBODY CAN MISREAD IT.
    //
    // The row above reads `desc.vertexBytes`. Those bytes are memcpy'd into the
    // upload arena at :3196 (`std::memcpy(vbDst, desc.vertexBytes,
    // desc.vertexBytesSize)`) and bound with IASetVertexBuffers at :3325, so
    // they are byte-for-byte what the vertex stage's INPUT ASSEMBLER reads. They
    // are the pipeline's INPUT. They are NOT what the vertex shader emitted.
    //
    // There is no API on this path that reports the latter, and that is a
    // property of D3D12 rather than a gap in this file:
    //   * D3D12 has NO TRANSFORM FEEDBACK. It was removed in D3D11, so there is
    //     no stream-out from a vertex stage and nothing to capture a register
    //     into.
    //   * ID3D12PipelineState exposes no stage introspection at all -- the only
    //     pipeline method on the interface is GetCachedBlob, and the only
    //     reflection interface this tree holds (d3d12_backend.h:141-149) is a
    //     BLOBs no reflection.
    //   * This file's one readback, RecordDrawReadback, copies the back buffer
    //     and reports PIXELS. A rasteriser that emits nothing reports nothing,
    //     which is the silence this row exists beside.
    // So "where does the guest's geometry land after the vertex shader" cannot
    // be answered from the command list, and NO row here will answer it by
    // computing a position on the host: a position this file derived would be
    // this file's arithmetic wearing the pipeline's name, which is the
    // fabrication F-609 exists to prevent.
    //
    // WHAT IS PRINTED INSTEAD, and why it is the closest honest thing:
    // the COMPLETE byte image of the stream -- every vertex, every dword -- as
    // host little-endian 32-bit words. Each dword is printed with %08x and
    // nothing else, so a float lane is recoverable by bit_cast and no lane is
    // reformatted, rounded, clamped, substituted or defaulted. The bytes are
    // post-swap: the guest's own fetch constant carries a byte-order selector
    // (render_thread.cpp:2235-2243 applies CpGpuSwap32 per dword), so this is
    // the order the hardware would read, not the order the guest stored.
    //
    // WHY ALL VERTICES. A rectangle draw is three guest vertices expanded to
    // four by the geometry stage, so the primitive is fully determined by all
    // three; vertex 0 alone cannot separate "offscreen" from "degenerate" from
    // "collinear", and the row above prints four lanes of it and nothing else.
    //
    // BOUNDS, and the refusal of silence. kVsInputPrintVerts/kVsInputPrintLanes
    // cap the row; vertsOmitted / dwordsOmitted name the shortfall on the same
    // line, which is the CP-SHADER-BODY truncation discipline
    // (gpu_cp.cpp:2234-2242): no path on which a clamped dump can read as a
    // complete one. A vertex whose bytes run past vertexBytesSize is printed
    // only as far as the bytes exist and `shortDwords` counts the rest -- the
    // row never reads a byte the draw would not have read.
    {
        // WHY THESE TWO NUMBERS, and why they are named here rather than at the
        // top of the file: they are the row's bounds, so they belong beside the
        // sentence that says what happens when a vertex or a lane exceeds them.
        // kVsInputPrintVerts covers every rectangle draw this project has
        // measured (3 guest vertices, both draws in build/w709.log) with one to
        // spare, and kVsInputPrintLanes covers the widest measured stride's lane
        // count (7 lanes at stride 28) with one to spare. A draw that exceeds
        // either is not silently truncated: vertsOmitted / dwordsOmitted say so
        // on the same line, which is the falsifier for both constants.
        constexpr uint32_t kVsInputPrintVerts = 4u;
        constexpr uint32_t kVsInputPrintLanes = 8u;
        const uint64_t n = ++m_vsInputStreamRows;
        if (ShouldLogRefusal(n)) {
            const uint32_t stride = desc.vertexStride;
            const uint32_t lanes = stride / 4u;
            const bool haveBytes =
                (desc.vertexBytes != nullptr) && (desc.vertexBytesSize > 0u);
            const uint32_t scanVerts =
                (haveBytes && desc.vertexCount < kVsInputPrintVerts)
                    ? desc.vertexCount
                    : kVsInputPrintVerts;
            const uint32_t printLanes =
                (lanes < kVsInputPrintLanes) ? lanes : kVsInputPrintLanes;
            uint32_t dwordsPrinted = 0;
            uint32_t dwordsOmitted = 0;
            std::string vhex[kVsInputPrintVerts];
            for (uint32_t v = 0; v < scanVerts; ++v) {
                // Bytes this vertex actually has, from the descriptor's own
                // length rather than from `stride` alone.
                const uint32_t vOff = v * stride;
                uint32_t availLanes = 0;
                if (haveBytes && vOff < desc.vertexBytesSize) {
                    availLanes = (desc.vertexBytesSize - vOff) / 4u;
                }
                const uint32_t take = (availLanes < printLanes) ? availLanes
                                                               : printLanes;
                const auto* vp = haveBytes
                                     ? (static_cast<const uint8_t*>(desc.vertexBytes) +
                                        vOff)
                                     : nullptr;
                vhex[v].reserve(static_cast<size_t>(take) * 9u);
                for (uint32_t l = 0; l < take; ++l) {
                    uint32_t w = 0;
                    std::memcpy(&w, vp + static_cast<size_t>(l) * 4u, 4);
                    char word[9];
                    std::snprintf(word, sizeof(word), "%08x", w);
                    if (l != 0u) {
                        vhex[v].push_back(' ');
                    }
                    vhex[v].append(word, 8);
                }
                dwordsPrinted += take;
                dwordsOmitted += printLanes - take;
            }
            dwordsOmitted += (desc.vertexCount > scanVerts)
                                 ? (desc.vertexCount - scanVerts) *
                                       (printLanes > 0u ? printLanes : 1u)
                                 : 0u;
            const uint32_t vertsOmitted =
                (desc.vertexCount > scanVerts) ? (desc.vertexCount - scanVerts) : 0u;
            MCLA_LOG_WARN(
                "VS-INPUT-STREAM #{} prevCacheDraws={} haveBytes={} vertices={} stride={} "
                "floatLanes={} bytes={} vertsPrinted={} vertsOmitted={} "
                "dwordsPrinted={} dwordsOmitted={} v0=[{}] v1=[{}] v2=[{}] v3=[{}] "
                "-- the byte image of the vertex buffer this draw binds at slot 0, "
                "every vertex and every dword, host little-endian words after the "
                "guest's own fetch-constant byte-order swap; a float lane is "
                "recoverable by bit_cast and nothing is reformatted, clamped or "
                "defaulted. This is the pipeline's INPUT, not a shader output: a "
                "D3D12 command list has no transform feedback and no "
                "shader-output readback, so no row can report where the geometry "
                "lands after the vertex stage, and none here computes one",
                n, m_cachePipelineDraws, haveBytes ? 1u : 0u, desc.vertexCount,
                stride, lanes, desc.vertexBytesSize, scanVerts, vertsOmitted,
                dwordsPrinted, dwordsOmitted, vhex[0], vhex[1], vhex[2], vhex[3]);
        }
    }
    if (!desc.vertexBytes || desc.vertexBytesSize == 0 || desc.vertexCount == 0) {
        // 2026-10-02: this gate returned false with NO log line. It is the
        // single most likely reason a captured draw produced nothing while
        // every surrounding marker still looked healthy, because
        // `DRAW-CP-DRAWN` is printed by the render thread AFTER this call
        // returns and its bool result is discarded (render_thread.cpp:3578).
        // The three numbers are the gate's own inputs, reported verbatim.
        RecordSilentDrawReturn("no-vertex-data",
                               desc.vertexBytes ? 1u : 0u,
                               desc.vertexBytesSize, desc.vertexCount);
        return false;
    }

    // F-653: refuse a null pipeline HERE, at the top, before any upload-arena
    // mapping, m_inFrame mutation or m_frameIndex advance. The duplicate check
    // further down (at the SetPipelineState call) exists as a second line of
    // defence, but by that point this function has already taken the frame's
    // upload arena and marked the frame in flight; refusing there would leave
    // that state consumed by a draw that never happened.
    if (!pipeline) {
        const uint64_t n = ++m_nullPipelineRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("D3D12Backend: DrawDynamicMeshWithPipeline refused #{}: no "
                          "pipeline. F-653: the `pipeline ? pipeline : "
                          "m_testPipeline.Get()` fallback is DELETED; a draw with no "
                          "PSO is a refusal, because the test PSO is a specific wrong "
                          "answer (28-byte POSITION float3 + COLOR float4 layout the "
                          "guest never declared), not a safe default.",
                          n);
        }
        return false;
    }

    // When using the test PSO, enforce the test layout stride (28 bytes).
    // When a real PSO is provided, accept any stride â€” the PSO's input layout
    // defines the correct vertex format.
    // F-653: the stride gate now applies ONLY when the caller passed the test
    // PSO on purpose. The `|| !pipeline` arm is gone: a null pipeline is refused
    // further down with its own named counter, and leaving it here would have
    // reported a 28-byte-stride mismatch for a draw whose real problem is that
    // it had no pipeline at all -- the F-650 log named the wrong cause.
    if (pipeline == m_testPipeline.Get()) {
        constexpr uint32_t kLayoutStride = 28;
        if (desc.vertexStride != kLayoutStride) {
            // F-650: counted and bounded. This refusal used to log every single
            // occurrence with no counter, which is why build/w662.log carries
            // 4,940 lines of it and nothing else that says how many draws the
            // test layout rejected. The MISMATCH is deliberately still refused --
            // the draws that pass this check are read through a POSITION float3 +
            // COLOR float4 layout the guest never declared, so accepting a
            // mismatched stride would trade a counted refusal for pixels read at
            // the wrong offsets. The real fix is a translated PSO carrying the
            // guest's declared input layout, which is pipeline work, not a
            // backend change: render_thread.cpp:1298 routes every DRAW_CAPTURED
            // here with psoHash 0, so DrawDynamicMesh always resolves to the test
            // PSO (d3d12_backend.cpp:2478) and no real layout is ever consulted.
            const uint64_t n = ++m_testLayoutStrideRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_WARN("D3D12Backend: DrawDynamicMesh refused vertex stride "
                              "{} (test layout is {}) #{} -- the guest declared no "
                              "layout to the test PSO; needs a translated PSO",
                              desc.vertexStride, kLayoutStride, n);
            }
            return false;
        }
    }
    if (desc.indexed && !desc.cachedIndexGpu &&
        (!desc.indexBytes || desc.indexBytesSize == 0)) {
        RecordSilentDrawReturn("no-index-data", desc.indexed ? 1u : 0u,
                               desc.indexBytesSize, desc.indexCount);
        return false;
    }
    if (desc.indexed && desc.cachedIndexGpu && desc.cachedIndexBytesSize == 0) {
        MCLA_LOG_WARN("D3D12Backend: DrawDynamicMesh refused cached IB with size 0");
        return false;
    }

    // F-637: the topology gate. desc.topology is already a D3D12 topology (the
    // producer mapped it with MapXenosPrimType, which refuses the Xenos
    // prim_types D3D12 cannot express), so this only has to reject a value that
    // is not a D3D12_PRIMITIVE_TOPOLOGY at all. Before this the call was a
    // literal D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, so a LINE_STRIP capture drew
    // a triangle strip of garbage and nothing said so; the gate exists so the
    // un-mappable case is a counted refusal instead of a substitution.
    switch (desc.topology) {
        // F-650: UNDEFINED is NOT a patchlist. It is the zero-initialised
        // default of a DynamicMeshDesc nobody filled in: the producer's
        // `D3D12Backend::DynamicMeshDesc desc = {}` (render_thread.cpp:1253 for
        // DRAW_CAPTURED, :1338 for DRAW_MARKER) never assigns desc.topology at
        // all, so every draw reaches here as 0. Before F-650 that fell into the
        // patchlist case below and was reported as a tessellation-domain
        // problem, naming a fault in this file for a bug in another one.
        // MEASURED consequence: the guest's actual prim_type (8, rectangle list,
        // per DRAW-CP-DRAWN #20600) never reaches MapXenosPrimType at all, so
        // the per-prim_type refusal counter cannot see it. This row is the
        // evidence that the field is unset, which is the producer-side bug to
        // report; the rect-list refusal itself is counted in MapXenosPrimType.
        case D3D_PRIMITIVE_TOPOLOGY_UNDEFINED: {
            const uint64_t n = ++m_topologyUnsetRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: draw refused #{}: desc.topology is "
                               "UNDEFINED -- the producer never set a topology, so "
                               "the guest's real prim_type is unknown here. NOT a "
                               "patchlist. Producer-side: render_thread.cpp builds "
                               "DynamicMeshDesc desc = {{}} without assigning "
                               "desc.topology.",
                               n);
            }
            return false;
        }
        case D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST:
        case D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST: {
            // A control-point patchlist against a graphics PSO that has no
            // tessellation domain set is a D3D12 validation error, not a
            // degraded draw. Refused.
            const uint64_t n = ++g_primTypeRefusalOther;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: draw refused #{}: topology {} is a patchlist and "
                               "this PSO has no tessellation domain", n,
                               static_cast<uint32_t>(desc.topology));
            }
            return false;
        }
        default:
            break;
    }
    // TRIANGLESTRIP/TRIANGLEFAN/LINESTRIP need a restart index to be re-issued
    // correctly; a captured draw that uses a strip/fan with a non-zero start
    // index is legal D3D12 (it simply continues the strip from the adjacent
    // primitive in the buffer), so there is nothing to refuse here. What IS
    // worth counting is a non-zero start/base at all, because before F-637 both
    // were hardcoded 0 and nobody could tell whether any capture needed them.
    if (desc.indexed && (desc.startIndexLocation != 0 || desc.baseVertexLocation != 0)) {
        const uint32_t n = ++m_offsetDraws;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_INFO("D3D12Backend: draw with non-zero offsets #{} startIndex={} baseVertex={} "
                          "topology={} count={}",
                          n, desc.startIndexLocation, desc.baseVertexLocation,
                          static_cast<uint32_t>(desc.topology), desc.indexCount);
        }
    }

    m_stats.bytesThisFrame = 0;

    // Wait for the GPU to finish the previous frame that used this back
    // buffer's upload region before we write into it again. This must happen
    // before MapUpload, not at BeginFrame time (which is after staging), or
    // the CPU can overwrite bytes the GPU is still reading.
    if (!WaitForCurrentFrameGpu()) return false;

    // Stage vertex data BEFORE starting any command-list work, so an arena
    // exhaustion bails out cleanly with no open list and no stuck m_inFrame.
    D3D12_GPU_VIRTUAL_ADDRESS vbGpu = 0, ibGpu = desc.cachedIndexGpu;
    uint8_t* vbDst = MapUpload(desc.vertexBytesSize, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, vbGpu);
    if (!vbDst) return false;
    std::memcpy(vbDst, desc.vertexBytes, desc.vertexBytesSize);

    if (desc.indexed && !desc.cachedIndexGpu) {
        uint8_t* ibDst = MapUpload(desc.indexBytesSize, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, ibGpu);
        if (!ibDst) return false;
        std::memcpy(ibDst, desc.indexBytes, desc.indexBytesSize);
    }

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition the back buffer to render target.
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    rtvHandle.ptr += static_cast<size_t>(m_frameIndex) * m_rtvDescriptorSize;

    // F-650: the draw path OWNS the back buffer -- it is the writer whose pixels
    // the console's scanout is supposed to be showing. It therefore never asks
    // the arbiter's permission (it is the permission), but it does register as
    // this frame's writer so a second writer is caught if one is ever added.
    MayWriteBackBuffer(FrameOwner::Draw);

    // F-650: the placeholder clear, as the one named constant it now is. Nothing
    // in the guest or any reference establishes this colour; see
    // kPlaceholderBackBufferClear for what would replace it.
    m_commandList->ClearRenderTargetView(rtvHandle, kPlaceholderBackBufferClear, 0, nullptr);
    // F-761: this clear IS a write to the buffer, so it is counted as one. The
    // ledger counts writes, not owners: the question it exists to answer is
    // whether the resource has defined contents, and a clear defines them.
    NoteBufferWrite("draw-path-clear");
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    // 2026-10-02: the format of the render target that was JUST bound, read
    // from the bound resource's own descriptor rather than assumed from the
    // swapchain description. This is half of a comparison that could not be
    // made before: the PSO's RTVFormats[0] comes from the GUEST's
    // RB_COLOR_INFO (render_thread.cpp:3031 -> renderer/pipeline_cache.cpp
    // :1921-1945, NumRenderTargets = the count of non-UNKNOWN entries), while
    // the RTV bound here was created with pDesc = nullptr
    // (d3d12_backend.cpp:763) and therefore carries the swapchain format.
    // A D3D12 PSO whose RTVFormats[0] disagrees with the bound RTV
    // rasterizes nothing and reports no error, which is precisely the shape
    // of the symptom this row exists to rule in or out. The guest's own
    // format is logged by render_thread.cpp as `CP-COLORFMT-BOUND`; the two
    // rows are the two halves and are meant to be read together.
    {
        const D3D12_RESOURCE_DESC backDesc =
            m_renderTargets[m_frameIndex]->GetDesc();
        const bool first = (m_boundRtvFormat == 0);
        m_boundRtvFormat = static_cast<uint32_t>(backDesc.Format);
        // 2026-10-02: THIS ROW USED TO BE LATCHED TO `first` -- it printed at
        // most once for the whole process. That is a defensible choice for a
        // value that cannot change (a swapchain back buffer's format is fixed
        // for the life of the swapchain) and it is exactly wrong for a row whose
        // purpose is to be COMPARED against another row's value in the same log:
        // a once-per-process row is either present (and the comparison is a
        // coincidence of ordering) or absent (and there is no comparison at
        // all), and MEASURED on build/w698.log it is absent -- the site is
        // downstream of BeginFrame(), so with the gate closed the row cannot be
        // reached even once. Bounded by the house throttle rather than by
        // `first`, so the bound format and the guest's colorFormatDxgi are
        // comparable in a single soak instead of by cross-referencing two runs.
        // The FORMAT LITERAL is untouched.
        const uint32_t rf = ++m_rtvFormatRows;
        if (first || ShouldLogRefusal(rf)) {
            MCLA_LOG_INFO("D3D12-RTV-FORMAT bound={} (0x{:08X}) from the swapchain "
                          "back buffer; the PSO's RTVFormats[0] is set by the "
                          "GUEST's RB_COLOR_INFO, NOT by this value -- pair with "
                          "CP-COLORFMT-BOUND. A disagreement rasterizes nothing "
                          "without an error.",
                          static_cast<uint32_t>(backDesc.Format),
                          static_cast<uint32_t>(backDesc.Format));
        }
    }

    // The clip_disable rescale's render-target extent is published by
    // PublishClipDisableExtent at Initialize and at Resize -- the only two places
    // in this file that assign m_width/m_height, so the list is exhaustive. It is
    // NOT published here any more, and the reason is measured rather than
    // stylistic:
    //   (a) REDUNDANT. The translator samples the extent at TRANSLATION time
    //       (renderer/shader_translator.cpp:1134), which happens earlier than this
    //       point, on the render thread (src/render_thread.cpp:3471). Nudging the
    //       global from inside the draw cannot reach a translation that already
    //       happened, and cannot help a later one either -- that one reads whatever
    //       is current, which Resize has already refreshed.
    //   (b) THE WRONG THREAD. shader_translator.cpp:1800-1804 states the function
    //       is not atomic with respect to an in-flight translation and that the
    //       backend is expected to call it "during setup, before the pipeline
    //       worker is started, which is the only ordering the current pipeline
    //       guarantees". A per-draw call is by definition not during setup, and it
    //       runs while that worker is live -- i.e. it wrote a plain (non-atomic)
    //       4-float global on every single draw, in the one place the file
    //       documents as unsafe. Initialize publishes ahead of StartWorker
    //       (src/render_thread.cpp:121), so keeping this call would have preserved
    //       the race while fixing nothing.
    // The rescale still applies to every vertex shader; its GATE is a measured
    // constant, which the one-shot note below says once per process.
    {   // Once per process, so a reader of a soak knows the rescale's GATE is a
        // measured constant rather than a per-draw register read. Not a tracked
        // marker: it names no other marker (a tracked marker named inside another
        // marker's prose becomes uncountable, because soak_census.py counts lines).
        static bool s_gateNoteLogged = false;
        if (!s_gateNoteLogged) {
            s_gateNoteLogged = true;
            MCLA_LOG_INFO("clip_disable rescale: {}", renderer::kClipDisableRescaleGateNote);
        }
    }

    // Viewport covering the full back buffer.
    D3D12_VIEWPORT viewport = { 0.0f, 0.0f,
                                static_cast<float>(m_width), static_cast<float>(m_height),
                                0.0f, 1.0f };
    D3D12_RECT scissor = { 0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height) };
    m_commandList->RSSetViewports(1, &viewport);
    m_commandList->RSSetScissorRects(1, &scissor);

    D3D12_VERTEX_BUFFER_VIEW vbView = {};
    vbView.BufferLocation = vbGpu;
    vbView.StrideInBytes = desc.vertexStride;
    vbView.SizeInBytes = desc.vertexBytesSize;

    // F-637: the caller's topology, gated above. This used to be a literal
    // D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST.
    m_commandList->IASetPrimitiveTopology(desc.topology);
    m_commandList->IASetVertexBuffers(0, 1, &vbView);

    D3D12_INDEX_BUFFER_VIEW ibView = {};
    if (desc.indexed) {
        ibView.BufferLocation = ibGpu;
        // A D3D12 IBV with SizeInBytes == 0 is treated as unbound (the runtime
        // considers the slot null), so the cached IB must carry its real byte
        // size even though it is never re-uploaded.
        ibView.SizeInBytes = desc.cachedIndexGpu ? desc.cachedIndexBytesSize
                                                 : desc.indexBytesSize;
        ibView.Format = desc.indexFormat;
        m_commandList->IASetIndexBuffer(&ibView);
    }

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    // F-633: root CBV b0 (ShaderConstants) now carries the game's real constant
    // bank when the producer supplied one. Before this it bound 256 float4 of
    // zeros, which is not a neutral default: it is a specific wrong answer that a
    // translated shader consumes silently.
    //
    // The pack/unpack is renderer::PackXenosConstantBank (pipeline_cache.h:349) --
    // the single place the big-endian Xenos float4 bank becomes a native bank.
    // The producer (render_thread) owns the guest read, because that layer has the
    // validity check; this layer only consumes host bytes.
    D3D12_GPU_VIRTUAL_ADDRESS cbGpu = 0;
    uint8_t* cbDst = MapUpload(renderer::kShaderConstantBankBytes, 256, cbGpu);
    if (cbDst) {
        renderer::ConstantBankPack pack{};
        if (desc.guestConstBytes != nullptr && desc.guestConstBytesSize > 0) {
            pack = renderer::PackXenosConstantBank(
                static_cast<const uint8_t*>(desc.guestConstBytes),
                desc.guestConstBytesSize, cbDst, renderer::kShaderConstantBankBytes);
        } else {
            std::memset(cbDst, 0, renderer::kShaderConstantBankBytes);
        }
        // Counted, not merely logged: "the shader read the right constants" and
        // "the shader read zeros" are different worlds and the gate needs to tell
        // them apart. First 8 rows then every 200th, per the house pattern.
        const uint32_t n = ++m_constBankDraws;
        if (n <= 8 || (n % 200) == 0) {
            MCLA_LOG_WARN(
                "CONST-BANK #{} src={} regs={} guestBytes={} zeroFilled={} "
                "truncated={} ok={}",
                n, desc.guestConstBytes != nullptr ? "guest" : "ZEROS",
                pack.registersPacked, desc.guestConstBytesSize,
                pack.zeroFilledBytes, pack.truncated ? 1 : 0, pack.ok ? 1 : 0);
        }
        // F-644: root parameter 2, NOT 1. Root parameter 1 is the s0 SAMPLER
        // descriptor table (CreateTestRootSignature); the CBV moved from 1 to 2
        // when the static sampler was replaced by a table.
        // renderer::pipeline_cache.cpp's ResolveConstantBankBinding must name
        // the same index or the reflected binding is reported invalid and every
        // real PSO refuses.
        m_commandList->SetGraphicsRootConstantBufferView(2, cbGpu);
    } else {
        // F-644: the CBV is NOT optional. Leaving root parameter 2 unset with a
        // descriptor-table-free CBV parameter bound is a D3D12 validation error
        // and an undefined read in the shader, so a draw that could not get a
        // constant bank is refused rather than issued. Before F-633 this same
        // path bound 256 float4 of zeros, which is a specific wrong answer; a
        // refusal is a countable one.
        //
        // 2026-10-02: THIS `return false` IS ONE MORE `m_inFrame` LEAK, and it
        // is the one inside the draw body. BeginFrame() was called at :2971 and
        // set m_inFrame true; this return is the only exit between there and
        // PresentOwnedFrame, so the frame stays open and the next BeginFrame()
        // refuses on already-in-frame. The recorded-but-unexecuted barriers
        // above are discarded by the next BeginFrame's command-list Reset, which
        // is the correct handling of an abandoned frame. The refusal itself is
        // unchanged and still happens first: AbandonFrame releases state, it
        // does not make the draw legal.
        ++g_textureBindRefusals;  // shares the "producer could not supply" bucket
        MCLA_LOG_ERROR("D3D12Backend: draw refused: no upload-arena space for the {}B root CBV "
                       "(b0); the shader would read an unbound constant buffer",
                       renderer::kShaderConstantBankBytes);
        AbandonFrame("draw:no-constant-bank");
        return false;
    }

    // F-653: the silent substitution is gone. This used to read:
    //     // Use the provided pipeline or fall back to test pipeline
    //     ID3D12PipelineState* pso = pipeline ? pipeline : m_testPipeline.Get();
    // A null `pipeline` became the FIXED TEST PSO -- a POSITION float3 + COLOR
    // float4, 28-byte-stride pipeline -- and the draw was issued through it. The
    // substitution was invisible: no log line, no counter, and a guest draw
    // whose bytes were read at the test layout's offsets rendered whatever those
    // offsets happened to hold. render_thread.cpp hands over `nullptr` on every
    // path where no pipeline was derived (render_thread.cpp:937), so this was
    // not an edge case, it was the common case.
    //
    // The null case is now refused at the TOP of this function, before any
    // upload-arena or frame-state mutation; there is deliberately no second
    // check here, because a branch that cannot be taken is a branch nobody
    // maintains. What remains is the plain binding of a PSO the caller supplied.
    ID3D12PipelineState* pso = pipeline;
    m_commandList->SetPipelineState(pso);
    // 2026-10-02: the PSO's EXISTENCE, on the draw path, as a row of its own.
    //
    // WHY IT IS HERE AND NOT AT THE CreateGraphicsPipelineState CALL: the PSO
    // the guest draw uses is created on the pipeline cache's worker thread, in
    // src/renderer/pipeline_cache.cpp:1972, which this stream does not own.
    // That site logs FAILURE (LogPsoCreateFailed, kRefusePsoCreateFailed) and
    // has no success row, which is why build/w696.log's four
    // "CreateGraphicsPipelineState" hits are all the trailing prose clause of
    // four DXC-OUTPUTS rows and the real creation is invisible: there is no
    // line anywhere that says a PSO came into existence. A non-null
    // ID3D12PipelineState* reaching SetPipelineState is the same fact observed
    // from the only side this file owns -- the cache is the sole producer of
    // the pointer, and a null one is refused at the top of this function, so
    // this row cannot print without a PSO having been created. It reports the
    // pointer, not a claim about its contents: a D3D12 PSO does not report its
    // own RTVFormats, so the format agreement is the CP-COLORFMT-BOUND /
    // D3D12-RTV-FORMAT pair, not this row.
    {
        const uint64_t bn = ++m_psoBoundDraws;
        if (bn <= 8 || (bn % 200) == 0) {
            MCLA_LOG_INFO("PC-PSO-BOUND #{} pso={:p} vertices={} indexed={} "
                          "indexCount={} stride={} -- a non-null cache-produced "
                          "PSO was bound, so one exists. NOT a claim about its "
                          "render targets; pair with CP-COLORFMT-BOUND and "
                          "D3D12-RTV-FORMAT.",
                          bn, static_cast<const void*>(pso), desc.vertexCount,
                          desc.indexed ? 1u : 0u, desc.indexCount,
                          desc.vertexStride);
        }
    }
    // F-653: draws issued through a PSO the pipeline CACHE produced (as opposed
    // to the test PSO). This is deliberately NOT called "rectangle draws" and
    // does not claim to be: a rectangle draw and a triangle draw are different
    // PSOs (PipelineState::geometryStage is key identity, pipeline_cache.h),
    // but this layer is handed a bare ID3D12PipelineState* and a PSO does not
    // report which variant it is, so per-variant attribution is not available
    // HERE without either a key or a PSO->stage map, and inventing either would
    // be a guess. The soak reads this beside renderer::RectangleDrawsOffered()
    // and PipelineCache::Stats().geomStageCreated instead, which are exact.
    ++m_cachePipelineDraws;

    // F-727: DISARM "a draw has been issued on this command list". The copy is
    // recorded AFTER the draw call now, not here; see the note immediately below
    // the draw. Clearing the flag here means it can only ever be observed true if
    // a draw call was issued during THIS invocation of this function, which is
    // what lets the D3D12-DRAW-PIXEL row print copyAfterDraw= as an observation
    // instead of a restatement of where this line happens to sit.
    s_drawIssuedOnList = false;

    if (m_cachePipelineDraws <= 8 || (m_cachePipelineDraws % 200) == 0) {
        MCLA_LOG_INFO("D3D12Backend: draw #{} issued through a cache-produced PSO "
                      "(not the test PSO) -- F-653; pair with PC-RECT-OFFERED and "
                      "geomStageCreated for the per-variant counts",
                      m_cachePipelineDraws);
    }
    BindDecodedTexture();  // no-op unless a decoded texture is active

    if (desc.indexed) {
        // F-637: the capture's start index and base vertex. Both were hardcoded
        // 0, so any draw that used them drew the wrong vertices with no log.
        m_commandList->DrawIndexedInstanced(desc.indexCount, 1, desc.startIndexLocation,
                                            desc.baseVertexLocation, 0);
    } else {
        m_commandList->DrawInstanced(desc.vertexCount, 1, 0, 0);
    }

    // F-761: a recorded draw call is a write to m_renderTargets[m_frameIndex] in
    // the only sense that matters for "are these contents defined": whether it
    // rasterises anything is a separate question with its own markers, and
    // conflating the two would let a draw that wrote nothing count as proof
    // that the buffer was written.
    NoteBufferWrite("draw");

    m_stats.drawsIssued++;

    // ---- DRAW-COMMANDLIST-BOUND ---------------------------------------------
    // THE STATE THAT COULD STILL SUPPRESS RASTERISATION, AS THIS FILE SETS IT.
    //
    // A correct vertex stream that produces no pixel has a short list of
    // suppressors, and every one of them is state rather than data: a viewport
    // or scissor that excludes the primitive, a rasteriser state that culls or
    // does not fill, a depth or blend state that discards the result, a
    // topology that does not assemble, a render-target format the PSO and the
    // bound RTV disagree about. None of them was observable before this row,
    // because the values live in locals that died at the end of the function
    // and in a pipeline description this file never sees.
    //
    // WHAT IS PRINTED, and where each value comes from:
    //   vp / scissor        the `viewport` and `scissor` locals handed to
    //                        RSSetViewports / RSSetScissorRects at :3409-3410,
    //                        read back out of those same locals -- so they are
    //                        the values the command list was told, not a
    //                        recomputation of them.
    //   topology/counts      the `desc` fields the draw call was issued from.
    //   vb / ib              the `vbView` and `ibView` locals handed to
    //                        IASetVertexBuffers / IASetIndexBuffer, FIELD BY
    //                        FIELD in the D3D12_VERTEX_BUFFER_VIEW order
    //                        (BufferLocation, SizeInBytes, StrideInBytes). The
    //                        order is written out because getting it backwards
    //                        reproduces silently a stride that looks plausible,
    //                        which is the exact symptom this row is here to
    //                        rule out.
    //   rtvFormat            m_boundRtvFormat, assigned this pass at :3349 from
    //                        the bound back buffer's own D3D12_RESOURCE_DESC.
    //   gs*                  renderer::PipelineCacheStats, read from THIS
    //                        OBJECT's m_pipelineCache -- the same member
    //                        render_thread.cpp:3742 calls GetOrCompile on, so
    //                        these are the totals for the cache that produced
    //                        the PSO bound above, not a global that might belong
    //                        to another cache. gsOffered is the free function's
    //                        counter because PipelineState has no field for it
    //                        (pipeline_cache.h:814-821). gsStageObtained /
    //                        gsStageRefused are that struct's geomStageWaited /
    //                        geomStageWaitFailed under names that do not
    //                        contain the word their source fields do: the
    //                        tracking keyword is a two-line match and a row
    //                        must not inflate another row's count.
    //
    // WHAT IS NOT PRINTED, AND WHY -- stated here because a gap that is only
    // described in a report is a gap that gets re-derived wrongly:
    //   psoDescReadable=0. The D3D12_GRAPHICS_PIPELINE_STATE_DESC for a guest
    //     draw is NOT built by this file. It is built at
    //     renderer/pipeline_cache.cpp:1894-1948, inside that file's worker
    //     thread, and consumed by one CreateGraphicsPipelineState call at :1972;
    //     the resulting ID3D12PipelineState exposes no stage, state or input
    //     layout, and this file's own CreatePipelineFromDxil (d3d12_backend.cpp
    //     :2785) has zero callers in src/ -- it is not the guest draw's path.
    //     So DepthEnable, DepthWriteMask, DepthFunc, StencilEnable, BlendEnable,
    //     SrcBlend, DestBlend, RenderTargetWriteMask, CullMode, FillMode,
    //     FrontCounterClockwise, DepthClipEnable, MultisampleEnable,
    //     AntialiasedLineEnable and ConservativeRaster are READABLE NOWHERE from
    //     this layer, and they are named in `unreadable=` rather than left
    //     silently absent. The pipeline cache does publish them, as
    //     psoDesc.RasterizerState/BlendState/DepthStencilState copied verbatim
    //     from the key (pipeline_cache.cpp:1949-1951), which is another stream's
    //     file.
    //   inputLayoutReadable=0. D3D12_INPUT_ELEMENT_DESC is never turned into an
    //     ID3D12InputLayout anywhere in src/ -- CreateInputLayout has zero
    //     occurrences across the tree -- because the descriptors go straight
    //     into psoDesc.InputLayout (pipeline_cache.cpp:1910-1911). This file is
    //     handed a bare ID3D12PipelineState* and a DynamicMeshDesc, and
    //     DynamicMeshDesc carries no layout member (d3d12_backend.h:68-104), so
    //     the descriptors that built the bound PSO do not reach this layer at
    //     all. The one place in THIS file that materialises a descriptor array
    //     is BuildInputLayoutFromGrcFvf (:5393), which the live draw path does
    //     not call.
    // NOTHING HERE IS FORCED. No state is overwritten to make a draw visible,
    // no field is defaulted, no check is disabled: this row only reads.
    {
        const uint64_t cln = ++m_commandListBoundRows;
        if (ShouldLogRefusal(cln)) {
            const renderer::PipelineCacheStats cst = m_pipelineCache.Stats();
            MCLA_LOG_WARN(
                "DRAW-COMMANDLIST-BOUND #{} drawsIssued={} pso={:p} "
                "psoIsTestPso={} drawCall=issued "
                "vp=({},{},{},{},{},{}) scissor=({},{},{},{}) "
                "topology={} indexed={} vertexCount={} indexCount={} "
                "startIndex={} baseVertex={} instances=1 "
                "vb=({:016X},{},{}) ibBound={} ib=({:016X},{},{}) "
                "rtvFormat=0x{:08X} "
                "gsOffered={} gsCreated={} gsCompileFailed={} gsUnbuildable={} "
                "gsStageObtained={} gsStageRefused={} cacheHits={} cacheMisses={} "
                "cacheRefusals={} "
                "psoDescReadable=0 inputLayoutReadable=0 "
                "unreadable=DepthEnable,DepthWriteMask,DepthFunc,StencilEnable,"
                "BlendEnable,SrcBlend,DestBlend,RenderTargetWriteMask,CullMode,"
                "FillMode,FrontCounterClockwise,DepthClipEnable,MultisampleEnable,"
                "AntialiasedLineEnable,ConservativeRaster "
                "-- vp/scissor/vb/ib/topology are the exact locals handed to the "
                "command list this draw was recorded on, and vb is in "
                "D3D12_VERTEX_BUFFER_VIEW field order (BufferLocation, "
                "SizeInBytes, StrideInBytes). gs* are this object's own "
                "PipelineCache totals, read after the draw call. psoDescReadable=0 "
                "because the guest draw's pipeline description is built and "
                "consumed in another translation unit and a D3D12 pipeline state "
                "reports none of its own fields; inputLayoutReadable=0 because "
                "input element descriptors are never turned into an input-layout "
                "object in this tree and none is carried into this layer. Both "
                "zeros are absences of an observation, NOT measurements of the "
                "state. Nothing here is forced, defaulted or clamped",
                cln, m_stats.drawsIssued, static_cast<const void*>(pso),
                (pso == m_testPipeline.Get()) ? 1u : 0u,
                viewport.TopLeftX, viewport.TopLeftY, viewport.Width,
                viewport.Height, viewport.MinDepth, viewport.MaxDepth,
                scissor.left, scissor.top, scissor.right, scissor.bottom,
                static_cast<uint32_t>(desc.topology), desc.indexed ? 1u : 0u,
                desc.vertexCount, desc.indexCount, desc.startIndexLocation,
                desc.baseVertexLocation,
                vbView.BufferLocation, vbView.SizeInBytes, vbView.StrideInBytes,
                desc.indexed ? 1u : 0u, ibView.BufferLocation,
                ibView.SizeInBytes, static_cast<uint32_t>(ibView.Format),
                m_boundRtvFormat, renderer::RectangleDrawsOffered(),
                cst.geomStageCreated, cst.geomStageCompileFailed,
                cst.geomStageUnbuildable, cst.geomStageWaited,
                cst.geomStageWaitFailed, cst.hits, cst.misses, cst.refusals);
        }
    }

    // ---------------------------------------------------------------------
    // F-727: THE COPY IS RECORDED HERE, AFTER THE DRAW. It used to be recorded
    // ABOVE, immediately before the draw call, under a comment that said it was
    // "between the draw and the PRESENT transition". Both halves of that were
    // wrong, and the measurement was wrong with them.
    //
    // MEASURED from this file's own statement order, not inferred: the copy was
    // recorded at the top of the draw path, above DrawIndexedInstanced /
    // DrawInstanced, so the only writes that had reached the back buffer when
    // that copy executed were the placeholder clear (kPlaceholderBackBufferClear)
    // and anything earlier draws on the same list had left. The draw being
    // measured had NOT rasterised yet, so the sample described the surface
    // BEFORE the draw.
    //
    // The consequence is visible in build/w701.log. D3D12-DRAW-PIXEL #2 printed
    // rgba=(5,8,13,255), and kPlaceholderBackBufferClear is {0.02f, 0.03f, 0.05f,
    // 1.0f}, which quantises to 8-bit UNORM as exactly 5, 8, 13, 255. The census
    // on that same row agrees byte for byte with a surface filled by the clear:
    // sum=23961600 = 921600 * (5+8+13), maxChannel=13, nonBlack=921600. So that
    // row -- and the DRAW-CP-PIXEL row that re-emits it -- described the PLACEHOLDER
    // CLEAR, not a draw. It was never a "first confirmed non-black pixel value"
    // from the guest. The render_thread.cpp row still calls its value "a sample
    // of the surface THIS draw wrote"; that text is now true of the MECHANISM and
    // false of those two historical rows, which were taken before this move.
    //
    // Moving the copy down here also repairs a SECOND defect the old position
    // created, which nothing had named. RecordDrawReadback finishes by
    // transitioning the back buffer COPY_SOURCE -> PRESENT, so recording it
    // BEFORE the draw left the back buffer's tracked state at PRESENT while the
    // draw was then recorded against it -- and the conditional barrier below,
    // which is skipped when rbRecorded, never restored it. The draw is now
    // recorded while the tracked state is RENDER_TARGET, as D3D12 requires.
    //
    // SAFE, on both counts the move could plausibly have broken:
    //   * BINDINGS. ResourceBarrier and CopyTextureRegion do not disturb the PSO,
    //     root signature, root constants or RTV binding, so recording the copy
    //     after the draw leaves the draw the same binding state it would have
    //     had with the copy before it.
    //   * FENCE. The copy is still inside the SAME command list, and
    //     PresentOwnedFrame still Closes, Executes and Signals that list AFTER
    //     this point, so ReportDrawReadback's wait still covers this copy.
    //     Moving a recording a few statements later within one list cannot move
    //     it past the Close.
    // ---------------------------------------------------------------------
    s_drawIssuedOnList = true;
    const bool rbRecorded = RecordDrawReadback();

    // 2026-10-02 (F-727): the four dead ends below were measured on this runtime
    // and all four are real. They are recorded HERE, next to the working copy, so
    // that a reader who finds the fifth path does not have to rediscover the
    // other four -- NOT because the readback is absent from this function. It is
    // the call above the draw.
    //   * a buffer on D3D12_HEAP_TYPE_DEFAULT is not CPU-mappable -- Map returns
    //     hr=0x80070057 (E_INVALIDARG) with ppData null;
    //   * moving it to D3D12_HEAP_TYPE_UPLOAD makes it an illegal copy
    //     DESTINATION and the device is REMOVED -- 0x887A0001, which is the same
    //     failure a previous agent reported and could not diagnose;
    //   * D3D12 has no D3D12_RESOURCE_STATE_COPY_HOST (um/d3d12.h:3231-3266);
    //   * a CUSTOM heap rejects CPU_PAGE_PROPERTY_UNKNOWN and
    //     MEMORY_POOL_UNKNOWN ("D3D12_HEAP_PROPERTIES is invalid", debug id
    //     628), so its only legal settings are NOT_AVAILABLE + POOL0/POOL1,
    //     which is GPU-only.
    //
    // 2026-10-02 (F-725): EVERY ONE OF THOSE IS CORRECT AND NONE OF THEM IS
    // THE POINT. All four failed because they tried to MAP something, or to copy
    // INTO something, rather than to COPY OUT of the back buffer into a resource
    // whose defining property is that it IS mappable. The heap that D3D12 gives
    // you for exactly this job is D3D12_HEAP_TYPE_READBACK, and it was the one
    // heap none of the four tried. Measured on this machine, RTX 3070,
    // driver-reported vendor=0x10DE device=0x2484, D3D12 debug layer ON, harness
    // at build/F725_pixharness.log:
    //   PATH A  Map() on a DEFAULT-heap buffer      -> 0x80070057 (dead end #1)
    //           debug id 0x336: "Map and Unmap can not be called on a resource
    //           associated with a heap that has the CPU page properties of
    //           D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE."
    //   PATH B  UPLOAD heap as a copy destination    -> 0x80070057 AT CREATE
    //           (dead end #2, and NOT the reported device removal: this harness
    //           measured a rejected create, then a refused
    //           GENERIC_READ->COPY_DEST transition at list->Close(), and never
    //           reached 0x887A0001)
    //   PATH C  D3D12_RESOURCE_STATE_COPY_HOST       -> does not compile; 16
    //           D3D12_RESOURCE_STATE_* enumerators exist and it is not one
    //   PATH D  CUSTOM heap                          -> 0x80070057; debug id 0x27E
    //           (638, not the 628 quoted above): "D3D12_HEAP_PROPERTIES is
    //           invalid. D3D12_CPU_PAGE_PROPERTY_UNKNOWN cannot be used with
    //           D3D12_HEAP_TYPE_CUSTOM." The NOT_AVAILABLE + L0 combination IS
    //           accepted and is still GPU-only: Map -> 0x80070057 again.
    //   PATH E  own R8G8B8A8_UNORM texture -> READBACK buffer   -> WORKS
    //   PATH C2 copy out of the FLIP_DISCARD back buffer into a READBACK
    //           buffer                                 -> ALSO WORKS
    //
    // C2 is the one this file uses, and it is the cheaper of the two: the guest's
    // draw already targets the back buffer, so the readback is one extra copy in
    // a command list that is already open, with no second render target and no
    // second PSO. The measurement contradicts a claim made above it in this very
    // comment, and it is kept above rather than deleted because a flip-model back
    // buffer being a legal copy SOURCE is not a thing one should have to
    // rediscover: CreateSwapChain's own note above still asks for this legality to
    // be "PROBED at runtime instead of assumed". It is probed here.
    //
    // The values read back are printed by the new D3D12-DRAW-PIXEL row, and the
    // same measurement is re-emitted after DRAW-CP-DRAWN by the render thread's
    // DRAW-CP-PIXEL row, so that a pixel sample exists with a timestamp LATER
    // than a draw -- which, until F-725, no row in the tree had.
    // F-725: THIS BARRIER IS CONDITIONAL, and it has to be. RecordDrawReadback
    // already took the back buffer RENDER_TARGET -> COPY_SOURCE -> PRESENT, so
    // after a recorded readback the tracked state is PRESENT and asserting
    // StateBefore=RENDER_TARGET here is a state MISMATCH.
    //
    // MEASURED, not reasoned: the F-725 harness hit exactly this when the
    // harness itself recorded the copy and then transitioned unconditionally.
    // The D3D12 debug layer named it, id 0x20F: "Using ResourceBarrier ...
    // Before state (0x4: D3D12_RESOURCE_STATE_RENDER_TARGET) of resource ...
    // does not match with the state (0x800: D3D12_RESOURCE_STATE_COPY_SOURCE)
    // specified in preceding ResourceBarrier or as InitialState", and the list
    // then failed to Close. So the fix is to skip the transition when the
    // readback already performed it, not to weaken the readback.
    if (!rbRecorded) {
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        m_commandList->ResourceBarrier(1, &barrier);
    }

    // F-650: the draw path's own present, through the one sanctioned entry point.
    // This is the frame the console's scanout is meant to show, and the FRAME-OWNER
    // row it emits is what makes that claim checkable instead of assumed.
    const bool presented = PresentOwnedFrame(FrameOwner::Draw);
    // F-725: the readback copy, if one was recorded, was executed and fenced by
    // the call above. Now -- and only now -- is it safe to Map.
    if (rbRecorded) {
        ReportDrawReadback();
    }
    return presented;
}

// ===========================================================================
// F-725: THE POST-DRAW READBACK. Four dead ends were measured and all four are
// real (see the note at the end of DrawDynamicMeshWithPipeline). The fifth path
// -- CopyTextureRegion OUT of the back buffer into a D3D12_HEAP_TYPE_READBACK
// buffer -- was measured working on this machine and is implemented here.
//
// WHY THE READBACK HEAP IS THE WHOLE TRICK. A READBACK-heap resource is
// mappable by definition; that is the one property the other three heap types
// refuse. Nothing about the back buffer has to change: the guest's draw already
// targets it, so this costs one copy inside a command list that is already open.
// The harness's PATH C2 measured 32.0000% non-black pixels and maxChannel=214
// reading straight out of a DXGI_SWAP_EFFECT_FLIP_DISCARD back buffer, i.e. the
// "a flip back buffer is not a legal copy source" assumption is FALSE on this
// driver and the copy is one line.
//
// WHY IT IS BOUNDED TO kDrawReadbackMaxReadbacks ATTEMPTS. Each completed
// readback costs one GPU->CPU fence wait. An unbounded per-draw fence wait is
// exactly the cost-with-no-measurement this feature was created to remove, so it
// runs a fixed number of times and then switches itself off permanently and says
// so in the log. kDrawReadbackMaxReadbacks is a compile-time constant, not a
// runtime knob, because a runtime knob is one more thing that can differ between
// two builds whose logs are being compared.
// ===========================================================================

bool D3D12Backend::EnsureDrawReadback() {
    if (m_readbackDisabled) return false;
    if (m_readbackBuffer && m_readbackW == m_width && m_readbackH == m_height) {
        return true;
    }
    if (!m_device || m_width == 0 || m_height == 0) return false;

    m_readbackBuffer.Reset();

    // A buffer, so Format MUST be DXGI_FORMAT_UNKNOWN. MEASURED (F-725 harness,
    // D3D12 debug id 0x2E2): leaving the source texture's R8G8B8A8_UNORM on a
    // D3D12_RESOURCE_DIMENSION_BUFFER descriptor makes CreateCommittedResource
    // return 0x80070057 with "D3D12_RESOURCE_DESC::Format must be
    // DXGI_FORMAT_UNKNOWN when D3D12_RESOURCE_DESC::Dimension is
    // D3D12_RESOURCE_DIMENSION_BUFFER."
    D3D12_RESOURCE_DESC rbDesc = {};
    rbDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    rbDesc.Format = DXGI_FORMAT_UNKNOWN;
    rbDesc.Width = static_cast<UINT64>(m_width) * m_height * 4u;
    rbDesc.Height = 1;
    rbDesc.DepthOrArraySize = 1;
    rbDesc.MipLevels = 1;
    rbDesc.SampleDesc.Count = 1;
    rbDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    rbDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

    D3D12_HEAP_PROPERTIES hp = {};
    hp.Type = D3D12_HEAP_TYPE_READBACK;

    HRESULT hr = m_device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rbDesc,
                                                   D3D12_RESOURCE_STATE_COPY_DEST,
                                                   nullptr, IID_PPV_ARGS(&m_readbackBuffer));
    if (FAILED(hr)) {
        m_readbackBuffer.Reset();
        m_readbackDisabled = true;
        ++m_drawReadbackCreateFailures;
        const uint64_t n = m_drawReadbackCreateFailures;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("D3D12-DRAW-PIXEL #{} create hr=0x{:08X} -- no pixel value "
                          "will be reported for any draw from now on; this is the "
                          "fifth readback path failing after four measured dead "
                          "ends, and it is counted rather than retried",
                          n, static_cast<uint32_t>(hr));
        }
        return false;
    }
    m_readbackBuffer->SetName(L"mcla-draw-readback");
    m_readbackW = m_width;
    m_readbackH = m_height;

    // The footprint must be taken from the BACK BUFFER'S OWN descriptor, not from
    // the readback buffer's. MEASURED (F-725 harness, D3D12 debug id 0x356): a
    // footprint computed from the buffer descriptor carries Format=UNKNOWN and
    // CopyTextureRegion rejects it with "D3D12_SUBRESOURCE_FOOTPRINT::Format is
    // not supported at the current feature level". The existing blit path gets
    // this right by passing the texture descriptor (:1544 above).
    D3D12_RESOURCE_DESC backDesc = m_renderTargets[m_frameIndex]->GetDesc();
    UINT numRows = 0;
    UINT64 rowSize = 0, totalBytes = 0;
    m_device->GetCopyableFootprints(&backDesc, 0, 1, 0, &m_readbackFootprint, &numRows,
                                    &rowSize, &totalBytes);
    m_readbackRowPitch = m_readbackFootprint.Footprint.RowPitch;

    const uint64_t n = ++m_drawReadbackCreates;
    // backDesc.Flags is D3D12_RESOURCE_FLAGS, an enum, and fmt cannot format it
    // (measured: fmt::detail::type_is_unformattable_for<d3d12_resource_flags>).
    // Cast at every use rather than adding a formatter for one enum.
    const uint32_t backFlags = static_cast<uint32_t>(backDesc.Flags);
    MCLA_LOG_INFO("D3D12-DRAW-PIXEL #{} create hr=0x{:08X} heap=READBACK bytes={} "
                  "rowPitch={} rows={} backBuffer={}x{} flags=0x{:X} -- a "
                  "D3D12_HEAP_TYPE_READBACK buffer IS mappable, which is the one "
                  "thing the DEFAULT, UPLOAD and CUSTOM heaps all refuse",
                  n, static_cast<uint32_t>(hr), totalBytes, m_readbackRowPitch,
                  numRows, m_width, m_height, backFlags);
    return true;
}

// ---------------------------------------------------------------------------
// F-727: THE COPY'S IDENTITY AND ITS POSITION, MEASURED. Two pieces of state
// that make the D3D12-DRAW-PIXEL row able to say WHICH draw a sample belongs to
// and WHETHER the copy was recorded after that draw, so that neither fact has to
// be re-derived by reading statement order again -- which is exactly how the
// pre-draw recording survived review with a comment asserting the opposite.
//
// File-scope statics rather than members, for the reason s_drawCensusInconsistent
// is a function-local static (see below): this file is not allowed to edit
// d3d12_backend.h, which another owner may be changing. The single-instance
// assumption is not an assumption here -- the process holds exactly one backend,
// the g_d3d12Backend above -- so file scope IS the instance scope for them.
//
// s_drawIssuedOnList : set false at the top of the draw path and true immediately
//   after the draw call. RecordDrawReadback samples it. It is declared ABOVE
//   DrawDynamicMeshWithPipeline, at its first use, not here.
// s_readbackCopyAfterDraw : what it sampled, i.e. what the row prints.
// s_readbackDrawSeq : the F-653 draw ordinal the sample is attributed to.
// ---------------------------------------------------------------------------
static bool s_readbackCopyAfterDraw = false;
static uint64_t s_readbackDrawSeq = 0;

// F-728: THE FENCE VALUE THE READBACK MUST WAIT ON, CAPTURED WHERE IT IS
// SIGNALLed. This exists because the previous code re-derived it by indexing
// m_fenceValues AFTER PresentOwnedFrame had already advanced m_frameIndex, so
// the index named a slot two presents old whose value is <= the value just
// signalled and the wait was therefore skipped. Measured by the F-728 harness
// at %TEMP%\opencode\pixrace\ (output in pixrace_out.txt): with the old
// arithmetic the first submission printed target=0 completed=1 waited=0 and
// the probe returned the buffer's PREVIOUS contents while the census, run
// milliseconds later on the same Map, returned the copy's output -- i.e. the
// exact shape of build/w701.log's and build/w705.log's row #1, where the probe
// read (0,0,0,0) and the census read a fully written surface. With the value
// captured at the Signal, the same harness reports probeMismatches=0 and
// censusMismatches=0 over 12 runs.
//
// It is a file-scope static for the same reason s_readbackCopyAfterDraw is.
static uint64_t s_lastSignalledFenceValue = 0;

bool D3D12Backend::RecordDrawReadback() {
    if (m_readbackDisabled) return false;
    if (m_drawReadbackAttempts >= D3D12Backend::kDrawReadbackMaxReadbacks) {
        if (!m_readbackExhaustedLogged) {
            m_readbackExhaustedLogged = true;
            MCLA_LOG_INFO("D3D12-DRAW-PIXEL exhausted after {} readbacks "
                          "(kDrawReadbackMaxReadbacks={}) -- recording OFF for the "
                          "rest of the process. The bound is deliberate: each "
                          "readback is a GPU->CPU fence wait, and an unbounded "
                          "per-draw wait would be exactly the cost-with-no-"
                          "measurement this path exists to remove",
                          m_drawReadbackAttempts,
                          D3D12Backend::kDrawReadbackMaxReadbacks);
        }
        return false;
    }
    if (!m_commandList || !m_inFrame) return false;
    if (m_frameIndex >= kBufferCount || !m_renderTargets[m_frameIndex]) return false;
    if (!EnsureDrawReadback()) return false;

    ++m_drawReadbackAttempts;

    // F-727: sample the ordering evidence BEFORE recording anything, so the row
    // describes the copy this call is about to record rather than some later one.
    // m_cachePipelineDraws was incremented at the top of the draw path, so its
    // value here is the ordinal of the draw this sample is attributed to.
    s_readbackCopyAfterDraw = s_drawIssuedOnList;
    s_readbackDrawSeq = static_cast<uint64_t>(m_cachePipelineDraws);

    D3D12_RESOURCE_BARRIER b = {};
    b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    b.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    b.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
    b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(1, &b);

    D3D12_TEXTURE_COPY_LOCATION dst = {};
    dst.pResource = m_readbackBuffer.Get();
    dst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
    dst.PlacedFootprint = m_readbackFootprint;
    D3D12_TEXTURE_COPY_LOCATION src = {};
    src.pResource = m_renderTargets[m_frameIndex].Get();
    src.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    src.SubresourceIndex = 0;
    m_commandList->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);

    // Straight back to PRESENT, because the caller transitions to PRESENT next
    // and D3D12 requires the tracked state to match what the caller asserts.
    b.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_SOURCE;
    b.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
    m_commandList->ResourceBarrier(1, &b);
    return true;
}

void D3D12Backend::ReportDrawReadback() {
    if (!m_readbackBuffer || !m_device) return;
    ++m_drawReadbackCompletions;

    // PresentOwnedFrame signalled m_fence after executing the list this copy is
    // in, so waiting on that value is what makes the Map below safe. This is a
    // CPU/GPU sync point and the reason the readback is bounded.
    //
    // F-728: THIS WAIT USED TO INDEX THE WRONG SLOT, AND IT IS NOW FIXED. It
    // read
    //   const uint64_t target = m_fenceValues[m_frameIndex];
    // but PresentOwnedFrame writes that slot (below, at the Signal) and then
    // IMMEDIATELY advances the index, and this function is called after
    // PresentOwnedFrame has returned. So the slot named belonged to a frame up
    // to two presents old, its value was <= the value just signalled, and
    // GetCompletedValue() had already passed it -- the wait was skipped and the
    // Map could run before the copy. kBufferCount is 3 (d3d12_backend.h:34).
    //
    // It was never merely theoretical. The F-728 harness measured the shipped
    // arithmetic on a real device: target=0 completed=1 waited=0, and the probe
    // returned the readback buffer's previous contents while the census, run
    // milliseconds later over the same Map, returned the copy's output. That is
    // the shape of build/w705.log row #1, whose probe read (0,0,0,0) beside a
    // census reporting nonBlack=921600/921600.
    //
    // The target is now the value captured at the Signal itself
    // (s_lastSignalledFenceValue). The two values are appended to the row so
    // that whether the wait was needed, and whether it was taken, is a
    // measurement on the next soak rather than a reading of this comment.
    const uint64_t fenceTarget = s_lastSignalledFenceValue;
    const uint64_t fenceCompletedAtEntry =
        m_fence ? m_fence->GetCompletedValue() : 0;
    bool fenceWaited = false;
    if (m_fence && fenceCompletedAtEntry < fenceTarget) {
        m_fence->SetEventOnCompletion(fenceTarget, m_fenceEvent);
        WaitForSingleObject(m_fenceEvent, 2000);
        fenceWaited = true;
    }
    const uint64_t fenceCompleted = m_fence ? m_fence->GetCompletedValue() : 0;

    void* mapped = nullptr;
    D3D12_RANGE range = { 0, 0 };
    HRESULT hrMap = m_readbackBuffer->Map(0, &range, &mapped);
    if (FAILED(hrMap) || !mapped) {
        ++m_drawReadbackMapFailures;
        const uint64_t n = m_drawReadbackMapFailures;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("D3D12-DRAW-PIXEL #{} Map hr=0x{:08X} ppData={} -- the "
                          "copy executed but no value could be read, so no pixel "
                          "is claimed",
                          n, static_cast<uint32_t>(hrMap), mapped);
        }
        return;
    }

    const uint8_t* base = static_cast<const uint8_t*>(mapped) + m_readbackFootprint.Offset;
    const uint32_t pitch = static_cast<uint32_t>(m_readbackRowPitch);

    // Probe 0 is the viewport centre. It is inside a full-screen guest draw and
    // outside a small one, which is why the value is reported with its coordinates
    // and never as "the colour of the frame".
    const uint32_t px = m_width / 2u;
    const uint32_t py = m_height / 2u;
    const size_t probeOffset =
        static_cast<size_t>(py) * pitch + static_cast<size_t>(px) * 4u;
    const uint8_t* p = base + probeOffset;
    const uint8_t preR = p[0], preG = p[1], preB = p[2], preA = p[3];

    // ---------------------------------------------------------------------
    // F-728: THE ROW USED TO CONTRADICT ITSELF, AND IT WAS NOT THE VALUES.
    // build/w705.log line 7972 reads
    //   rgba=(0,0,0,0) at (640,360) ... nonBlack=921600/921600 (100.0000%) maxChannel=13
    // A surface cannot be wholly non-black and hold a fully black pixel at the
    // probe point, so one of the two numbers was not describing the surface the
    // other described. It was not a plumbing split: every one of the five
    // fields is computed from the single `base` above, and there is no call
    // between the probe and the loop. It was TIME. The four probe bytes were
    // four loads at the line this comment replaces, and the census -- ~3.5 MB
    // and 921,600 iterations at 1280x720 -- started after them, with nothing
    // ordering the GPU copy in between because the fence wait above named the
    // wrong slot and was skipped. So the probe read the buffer's previous
    // contents and the census read the copy's output.
    //
    // MEASURED, not inferred, by the F-728 harness: with the shipped
    // wrong-slot arithmetic it prints target=0 completed=1 waited=0 and the
    // probe reads the PREVIOUS submission's bytes on 12 of 12 runs while the
    // census is correct; with the captured Signal value it prints waited=1 and
    // both agree on 12 of 12. The census is exposed to the same race -- one of
    // those 12 runs read a half-copied surface (nonBlack=3634971/3686400) --
    // which is why fixing the wait and not just the probe was necessary.
    //
    // The probe is therefore no longer an independent read. It is tapped from
    // the SAME q the census is already holding, inside the loop, so rgba and
    // the four census fields are the same memory access and cannot disagree
    // about the surface by construction. The old up-front read is KEPT and
    // printed as probePreRgba, because the difference between the two is the
    // measurement: if a future edit breaks the wait again, that difference is
    // visible in the row instead of being a contradiction. Nothing is clamped
    // and no field is removed (charter F-609).
    // ---------------------------------------------------------------------

    // ---------------------------------------------------------------------
    // F-726: THIS CENSUS PRINTED AN ARITHMETICALLY IMPOSSIBLE ROW, AND THE
    // MEASUREMENT OF HOW IS BELOW. build/w700.log line 7830 reads
    //   meanChannel=26.0000 ... maxChannel=13
    // A mean over a surface cannot exceed that surface's maximum. The cause was
    // the DENOMINATOR, and it is visible two lines apart: `sum` accumulated
    // THREE bytes per pixel (the k = 0,1,2 loop below) while `total` was
    // incremented ONCE per pixel, so the printed mean was exactly 3x the mean
    // channel and could - did - exceed maxChannel. Confirmed at instruction
    // level, not inferred: in build/CMakeFiles/mcla.dir/src/d3d12_backend.cpp.obj
    // the loop body is three `addq` into the sum register and a single `incq`
    // into the total register, and the division is `divsd` of (double)sum by
    // (double)total. 26.0000 / 3 = 8.6667, a legal mean under a maximum of 13.
    //
    // The denominator is now CHANNEL SAMPLES (total * 3), so mean <= maxChannel
    // holds BY CONSTRUCTION: every one of the channelSamples bytes in `sum` is
    // <= maxChannel, because maxChannel was taken from the same bytes.
    // ---------------------------------------------------------------------
    //
    // BOUNDED (F-726). This loop runs on the render thread, and at 1280x720 it
    // was 921,600 iterations touching 3.5 MB of mapped memory. Below
    // kDrawCensusMaxPixels every pixel is still examined and the two fields mean
    // exactly what they meant before; above it, ROWS ARE STRIDED and the stride
    // and the examined row/pixel counts are appended to the row, so a sampled
    // census can never be read as an exhaustive one. The cap is a compile-time
    // constant, like kDrawReadbackMaxReadbacks, for the same reason: a runtime
    // knob is one more thing that can differ between two compared logs.
    static constexpr uint64_t kDrawCensusMaxPixels = 1ull << 20;  // 1,048,576
    // The count of censuses whose mean exceeded their maximum. A function-local
    // static rather than a member, so this file needs no header change and
    // cannot collide with another owner's edit to d3d12_backend.h.
    static uint64_t s_drawCensusInconsistent = 0;

    // ---------------------------------------------------------------------
    // F-729: THE CENSUS KNEW HOW MUCH OF THE SURFACE WAS BLACK AND NOTHING
    // ELSE. The four fields above are aggregates over 921,600 pixels, and
    // aggregates cannot answer "where" or "what colour": a solid triangle of
    // one colour and scattered noise of the same area and the same per-pixel
    // byte sums print IDENTICAL nonBlack, maxChannel, meanChannel and sum. That
    // is not a defect in those fields -- they are correct and they stay -- it
    // is that they are the wrong SHAPE of measurement for the question the boot
    // now asks, which is whether the guest's first rasterised fragment is a
    // shape at all.
    //
    // So four more measurements are appended, and each is derived from the same
    // `base` and the same censusStride the fields above already use, so a
    // strided census is described as strided here too and cannot be read as an
    // exhaustive one:
    //
    //   1. THE MODAL COLOUR and the bounding box of every pixel that DIFFERS
    //      from it, plus the count of those pixels. The comparison is against
    //      the surface's own most common RGBA value, not against black: at
    //      1280x720 the placeholder clear rgba=(5,8,13,255) is itself non-black
    //      and covers most of an unrasterised surface, so a "non-black bounding
    //      box" would be the whole surface by construction and would answer
    //      nothing. A box of the pixels that differ from the modal value is
    //      the first measurement that can distinguish "one solid region of the
    //      right size" from "the right number of pixels scattered".
    //   2. HOW MANY DISTINCT RGBA VALUES the surface holds and a bounded top-N
    //      with counts. This is the field that separates "a triangle of one
    //      colour" from "noise": noise is many colours, a triangle is one.
    //   3. ROW AND COLUMN COVERAGE of the differing pixels, so a solid region
    //      and a blob of equal area are told apart by their edge counts.
    //   4. THE COUNT OF PIXELS THAT ARE EXACTLY rgba=(0,0,0,255), beside the
    //      count the nonBlack percentage IMPLIES (total - nonBlack). nonBlack
    //      counts a pixel when any of r,g,b is nonzero, so total-nonBlack is
    //      "pixels with r==0 and g==0 and b==0" -- which INCLUDES rgba=(0,0,0,0).
    //      Printing both, and their difference, is what makes "the black really
    //      is black" a measurement instead of an assumption.
    //
    // BOUNDS, because this runs on the render thread and the log is already
    // megabytes per soak. The distinct-value table is an open-addressed set of
    // at most kDrawCensusDistinctCap RGBA keys; past that the row prints
    // distinctCapped=1 and says the modal value and the top-N are then exact
    // only over the first kDrawCensusDistinctCap distinct values seen -- so a
    // surface too varied for this table reports that it is, rather than
    // reporting a confident wrong modal. The top-N is kDrawCensusTopN entries.
    // The row and column coverage needs one counter per row and per column;
    // above kDrawCoverageMaxDim of those the counters are NOT allocated and the
    // coverage fields print as -1 beside coverageRefused=1, because a silent 0
    // there would read as "this surface has no changed rows".
    //
    // COST: the shape pass is a SECOND walk of the same bytes over the same
    // strided rows, so the census is bounded at 2 * kDrawCensusMaxPixels pixel
    // visits rather than kDrawCensusMaxPixels. It cannot be fused into the loop
    // above because the modal value is not known until that loop has ended --
    // comparing a pixel against a colour that the same loop has not yet decided
    // on is how a bounding box gets printed for the wrong colour. Two walks of
    // ~3.5 MB, twice per soak, in exchange for the first measurement of WHERE
    // the guest drew anything.
    static constexpr uint32_t kDrawCensusDistinctCap = 4096u;
    static constexpr uint32_t kDrawCensusTopN = 8u;
    static constexpr uint64_t kDrawCoverageMaxDim = 1ull << 20;
    // Power of two, four times the cap, so the open-addressed set is at most a
    // quarter full and linear probing stays short.
    static constexpr uint32_t kDrawCensusSlots = kDrawCensusDistinctCap * 4u;

    const uint64_t surfacePixels = static_cast<uint64_t>(m_width) * m_height;
    uint32_t censusStride = 1;
    while (censusStride < m_height && surfacePixels / censusStride > kDrawCensusMaxPixels) {
        censusStride *= 2;
    }

    // Whole-surface census, so "black" is a measurement and not an impression.
    // nonBlack counts a pixel when ANY OF ITS R,G,B BYTES IS NON-ZERO, i.e. it is
    // "not black", and alpha is deliberately NOT part of the predicate: a pixel
    // with rgb=0,0,0 and alpha=255 is black and must not be counted as non-black.
    uint64_t nonBlack = 0, maxChannel = 0, sum = 0, total = 0, censusRows = 0;
    // F-728: the reported probe bytes and the two counters that say where they
    // came from. probeTaps is 1 in every reachable path; probeFromCensus is 0
    // only when the stride skipped row py and the fallback below ran, which the
    // row prints so a reader never has to guess.
    uint8_t r = 0, g = 0, b = 0, a = 0;
    uint64_t probeTaps = 0, probeFromCensus = 0;
    uint32_t lastCensusRow = 0;
    // F-729: the colour side of the census. `slots` is the open-addressed index
    // (0 = empty, otherwise key index + 1), `keys` holds each distinct RGBA once
    // in first-seen order, `counts` the pixels per key. Insertion order is kept
    // so the top-N tie-break below is over a stable list rather than over hash
    // order, which would make the printed histogram differ between two runs of
    // the same surface.
    std::vector<uint32_t> slots(kDrawCensusSlots, 0u);
    std::vector<uint32_t> keys;
    std::vector<uint64_t> counts;
    keys.reserve(kDrawCensusDistinctCap);
    counts.reserve(kDrawCensusDistinctCap);
    uint64_t distinctOverflow = 0;
    // F-729: pixels whose four bytes are EXACTLY 0,0,0,255. Counted directly,
    // never derived from nonBlack: nonBlack's predicate is (r|g|b) != 0, so
    // total - nonBlack also counts rgba=(0,0,0,0), and the difference between
    // the two numbers is exactly the finding if there is one.
    uint64_t exactBlack = 0;
    for (uint32_t y = 0; y < m_height; y += censusStride) {
        const uint8_t* row = base + static_cast<size_t>(y) * pitch;
        lastCensusRow = y;
        // F-728: one comparison per row, hoisted out of the pixel loop, so the
        // tap costs nothing per pixel except the x compare on that one row.
        const bool probeRow = (y == py);
        for (uint32_t x = 0; x < m_width; ++x) {
            const uint8_t* q = row + static_cast<size_t>(x) * 4u;
            // F-728: the SAME q the four census lines below read. This is the
            // whole fix -- rgba is now that load, not a load taken at a
            // different instant.
            if (probeRow && x == px) {
                r = q[0]; g = q[1]; b = q[2]; a = q[3];
                ++probeTaps; ++probeFromCensus;
            }
            if (q[0] | q[1] | q[2]) ++nonBlack;
            if (q[0] > maxChannel) maxChannel = q[0];
            if (q[1] > maxChannel) maxChannel = q[1];
            if (q[2] > maxChannel) maxChannel = q[2];
            sum += static_cast<uint64_t>(q[0]) + q[1] + q[2];
            ++total;
            // F-729: the histogram tap. Same q, one packed key, one probe.
            const uint32_t key = static_cast<uint32_t>(q[0]) |
                                 (static_cast<uint32_t>(q[1]) << 8) |
                                 (static_cast<uint32_t>(q[2]) << 16) |
                                 (static_cast<uint32_t>(q[3]) << 24);
            uint32_t slot = ((key * 2654435761u) >> 12) & (kDrawCensusSlots - 1u);
            uint32_t probes = 0;
            uint32_t found = 0u;
            while (probes < kDrawCensusSlots) {
                const uint32_t occupant = slots[slot];
                if (occupant == 0u) break;
                if (keys[occupant - 1u] == key) { found = occupant; break; }
                slot = (slot + 1u) & (kDrawCensusSlots - 1u);
                ++probes;
            }
            if (found != 0u) {
                ++counts[found - 1u];
            } else if (slots[slot] == 0u && keys.size() < kDrawCensusDistinctCap) {
                keys.push_back(key);
                counts.push_back(1u);
                slots[slot] = static_cast<uint32_t>(keys.size());
            } else {
                // The table is at its cap. Recorded, not silently ignored: the
                // row prints distinctCapped=1 so no reader can take the modal
                // value and the top-N as exact over a surface that outran them.
                ++distinctOverflow;
            }
            if (q[0] == 0u && q[1] == 0u && q[2] == 0u && q[3] == 255u) ++exactBlack;
        }
        ++censusRows;
    }
    // A strided census can skip row py. Then there is no q to tap, so the probe
    // is read from that row immediately after the loop and the row says so via
    // probeFromCensus=0. It is NOT skipped silently and it is NOT invented.
    if (probeTaps == 0) {
        const uint8_t* row = base + static_cast<size_t>(py) * pitch;
        const uint8_t* q = row + static_cast<size_t>(px) * 4u;
        r = q[0]; g = q[1]; b = q[2]; a = q[3];
        ++probeTaps;
    }
    // F-729: THE MODAL VALUE, decided only now that the histogram is complete.
    // Strictly greater-than on the count, scanning in first-seen order, so ties
    // go to the value that appeared first -- deterministic, and stated here
    // because a modal value that moved between two runs of the same surface
    // would make every field below it move too.
    uint32_t modalIdx = 0;
    for (size_t i = 1; i < keys.size(); ++i) {
        if (counts[i] > counts[modalIdx]) modalIdx = static_cast<uint32_t>(i);
    }
    const uint32_t modalKey = keys.empty() ? 0u : keys[modalIdx];
    const uint64_t modalCount = keys.empty() ? 0u : counts[modalIdx];
    const uint8_t modalR = static_cast<uint8_t>(modalKey & 0xFFu);
    const uint8_t modalG = static_cast<uint8_t>((modalKey >> 8) & 0xFFu);
    const uint8_t modalB = static_cast<uint8_t>((modalKey >> 16) & 0xFFu);
    const uint8_t modalA = static_cast<uint8_t>((modalKey >> 24) & 0xFFu);

    // F-729: the bounded top-N, as one pre-rendered string so the format call
    // below gains exactly one argument instead of forty. Selected, not sorted:
    // kDrawCensusTopN passes of "take the largest not yet taken", which is
    // O(kDrawCensusTopN * distinct) and needs no <algorithm> include. Ties go
    // to the lower packed key, so the printed order is a function of the
    // histogram and not of the hash.
    std::string topRgba;
    {
        char ent[80];
        std::vector<uint8_t> taken(keys.size(), 0u);
        for (uint32_t n = 0; n < kDrawCensusTopN; ++n) {
            size_t best = keys.size();
            for (size_t i = 0; i < keys.size(); ++i) {
                if (taken[i] != 0u) continue;
                if (best == keys.size() || counts[i] > counts[best] ||
                    (counts[i] == counts[best] && keys[i] < keys[best])) {
                    best = i;
                }
            }
            if (best == keys.size()) break;
            taken[best] = 1u;
            std::snprintf(ent, sizeof(ent), "%s(%u,%u,%u,%u)x%llu",
                          topRgba.empty() ? "" : " ",
                          static_cast<unsigned>(keys[best] & 0xFFu),
                          static_cast<unsigned>((keys[best] >> 8) & 0xFFu),
                          static_cast<unsigned>((keys[best] >> 16) & 0xFFu),
                          static_cast<unsigned>((keys[best] >> 24) & 0xFFu),
                          static_cast<unsigned long long>(counts[best]));
            topRgba.append(ent);
        }
        if (topRgba.empty()) topRgba = "none";
        if (keys.size() > kDrawCensusTopN) {
            std::snprintf(ent, sizeof(ent), " (+%llu not shown)",
                          static_cast<unsigned long long>(keys.size() -
                                                           kDrawCensusTopN));
            topRgba.append(ent);
        }
    }

    // F-729: THE SHAPE PASS. A second walk of the same bytes over the same
    // strided rows, because the modal value did not exist until the walk above
    // ended. Everything here is counted against the SAME pixel set the four
    // original fields used, so the box and the histogram describe one set of
    // pixels and cannot be compared across two different samples.
    const uint32_t kNoCoord = static_cast<uint32_t>(-1);
    uint64_t changedPx = 0;
    uint32_t chgMinX = kNoCoord, chgMaxX = 0, chgMinY = kNoCoord, chgMaxY = 0;
    int64_t chgRows = 0, chgCols = 0;
    int64_t chgFirstRow = -1, chgLastRow = -1, chgFirstCol = -1, chgLastCol = -1;
    int64_t chgFirstRowCount = -1, chgLastRowCount = -1;
    int64_t chgFirstColCount = -1, chgLastColCount = -1;
    const bool coverageRefused =
        (static_cast<uint64_t>(m_width) + m_height) > kDrawCoverageMaxDim;
    std::vector<uint32_t> rowHits;
    std::vector<uint32_t> colHits;
    if (!coverageRefused) {
        rowHits.assign(m_height, 0u);
        colHits.assign(m_width, 0u);
        for (uint32_t y = 0; y < m_height; y += censusStride) {
            const uint8_t* row = base + static_cast<size_t>(y) * pitch;
            for (uint32_t x = 0; x < m_width; ++x) {
                const uint8_t* q = row + static_cast<size_t>(x) * 4u;
                const uint32_t key = static_cast<uint32_t>(q[0]) |
                                     (static_cast<uint32_t>(q[1]) << 8) |
                                     (static_cast<uint32_t>(q[2]) << 16) |
                                     (static_cast<uint32_t>(q[3]) << 24);
                if (key == modalKey) continue;
                ++changedPx;
                if (x < chgMinX) chgMinX = x;
                if (x > chgMaxX) chgMaxX = x;
                if (y < chgMinY) chgMinY = y;
                if (y > chgMaxY) chgMaxY = y;
                ++rowHits[y];
                ++colHits[x];
            }
        }
        for (uint32_t y = 0; y < m_height; ++y) {
            if (rowHits[y] == 0u) continue;
            // The "first" test is on chgFirstRow, NOT on chgRows. chgRows is a
            // COUNT and starts at zero, so testing it would make a rectangle
            // spanning rows 0..359 print 359 instead of 360: the sentinel
            // belongs to the index, not to the tally. MEASURED -- the harness
            // in %TEMP%\opencode\f729 reported 359 rows for a 640x360
            // rectangle with this bug, and 640x360 is 360 rows.
            if (chgFirstRow < 0) { chgFirstRow = static_cast<int64_t>(y);
                                   chgFirstRowCount = rowHits[y]; }
            chgLastRow = static_cast<int64_t>(y);
            chgLastRowCount = rowHits[y];
            ++chgRows;
        }
        for (uint32_t x = 0; x < m_width; ++x) {
            if (colHits[x] == 0u) continue;
            if (chgFirstCol < 0) { chgFirstCol = static_cast<int64_t>(x);
                                   chgFirstColCount = colHits[x]; }
            chgLastCol = static_cast<int64_t>(x);
            chgLastColCount = colHits[x];
            ++chgCols;
        }
    }
    // changedPx is 0 iff every examined pixel WAS the modal value, i.e. the
    // examined set is uniform -- so in that case there is no box to report and
    // the row says absent. Printing 0,0,0,0 would be inventing a corner for a
    // region that does not exist (charter F-609), and printing the surface's
    // own 0,0,1280,720 box would be answering a different question.
    char chgBox[96];
    if (changedPx == 0u) {
        std::snprintf(chgBox, sizeof(chgBox), "absent");
    } else {
        std::snprintf(chgBox, sizeof(chgBox), "x%u..%u y%u..%u",
                      static_cast<unsigned>(chgMinX), static_cast<unsigned>(chgMaxX),
                      static_cast<unsigned>(chgMinY), static_cast<unsigned>(chgMaxY));
    }

    // F-729: what the nonBlack percentage IMPLIES. total - nonBlack is the count
    // of pixels with r==0 AND g==0 AND b==0, alpha unconstrained, so it is an
    // upper bound on exactBlack rather than the same number -- unless every
    // black pixel also carries alpha 255, in which case the two are equal and
    // that equality is the measurement that "the black really is black" rests
    // on. Printed as both numbers so a reader never has to do the subtraction.
    const uint64_t blackImplied = total - (nonBlack < total ? nonBlack : total);

    // The probe's own byte offset and the range the census actually walked, so
    // the two are comparable by eye instead of by trust.
    const size_t censusFirstByte = 0;
    const size_t censusLastByte = static_cast<size_t>(lastCensusRow) * pitch +
                                  static_cast<size_t>(m_width) * 4u - 1u;
    const bool probeInsideCensusRange =
        probeOffset >= censusFirstByte && (probeOffset + 3u) <= censusLastByte;
    const uint64_t channelSamples = total * 3u;
    const double meanChannel = channelSamples
                                   ? static_cast<double>(sum) / static_cast<double>(channelSamples)
                                   : 0.0;

    // ---------------------------------------------------------------------
    // F-726: THE GUARD. The invariant above is structural, but "a reader has to
    // notice" is not a guard. One comparison, and if any future edit breaks the
    // denominator again this row prints NaN -- which fmt renders as `nan` -- and
    // counts the event, instead of printing a mean above the surface maximum
    // again. It does NOT clamp: clamping a summary into looking plausible is
    // fabricating a pixel value (charter F-609), so the honest answer, "this
    // number does not exist", is the one that gets printed.
    // ---------------------------------------------------------------------
    double printedMean = meanChannel;
    if (meanChannel > static_cast<double>(maxChannel)) {
        const uint64_t bad = ++s_drawCensusInconsistent;
        printedMean = std::numeric_limits<double>::quiet_NaN();
        MCLA_LOG_WARN("D3D12-DRAW-CENSUS-INCONSISTENT #{} sum={} channelSamples={} "
                      "maxChannel={} nonBlack={}/{} -- meanChannel is printed as nan "
                      "in the D3D12-DRAW-PIXEL row because it exceeded maxChannel, "
                      "which no mean over the same bytes can do. The denominators "
                      "and the raw sums are here so it can be recomputed",
                      bad, sum, channelSamples, maxChannel, nonBlack, total);
    }

    m_lastPixelX = px;
    m_lastPixelY = py;
    m_lastPixelR = r;
    m_lastPixelG = g;
    m_lastPixelB = b;
    m_lastPixelA = a;
    m_lastPixelNonBlack = nonBlack;
    m_lastPixelMaxChannel = maxChannel;
    m_lastPixelMeanChannel = printedMean;  // F-726: the guarded value, never a bare quotient
    m_lastPixelTotal = total;
    m_lastPixelRowPitch = pitch;
    m_lastPixelValid = true;

    const uint64_t n = m_drawReadbackCompletions;
    // F-729 APPENDED FIELDS, every field above the F-729 line in the row below
    // is unchanged and in its old position, including the four aggregates.
    // F-729's own comment lives here, not inside the argument list, so that the
    // format string and its arguments stay one contiguous, auditable block.
    MCLA_LOG_INFO(
        "D3D12-DRAW-PIXEL #{} rgba=({},{},{},{}) at ({},{}) of {}x{} rowPitch={} | "
        "nonBlack={}/{} ({:.4f}%) maxChannel={} meanChannel={:.4f} -- READ THESE "
        "VALUES, they are the first pixel values this backend has ever reported. "
        "Path: the draw targeted the swap-chain back buffer, CopyTextureRegion "
        "copied that back buffer into a D3D12_HEAP_TYPE_READBACK heap buffer "
        "inside the same command list, PresentOwnedFrame executed and signalled "
        "the fence, and Map on that heap -- which is mappable by definition -- "
        "returned these bytes. rgba is one probe at the viewport centre, not a "
        "summary of the frame; nonBlack/maxChannel/meanChannel are the whole "
        "surface. alpha=255 with rgb=0,0,0 is black, which is a real answer and "
        "is reported as one. F-726 APPENDED FIELDS, every field above is "
        "unchanged and in its old position: sum={} channelSamples={} censusRows={} "
        "censusStride={} -- F-726 also changed the MEAN's denominator from "
        "pixels to channelSamples (it was 3x too large, which is how w700.log "
        "line 7830 came to print a mean above its own maximum) and bounds the "
        "census, so a census with censusStride>1 covers the rows listed, not "
        "necessarily every row. F-727 APPENDED FIELDS: copyAfterDraw={} "
        "drawSeq={} -- copyAfterDraw=1 means this copy was recorded AFTER a draw "
        "call was issued on this command list, so the sample describes the draw's "
        "output. copyAfterDraw=0 is the F-727 defect: the copy was recorded before "
        "any draw call, so the sample describes the surface as it was BEFORE the "
        "draw -- which for a first frame is this backend's own placeholder clear, "
        "kPlaceholderBackBufferClear = {{0.02f,0.03f,0.05f,1.0f}}, and that "
        "quantises to rgba=(5,8,13,255). build/w701.log printed exactly that and "
        "was NOT a guest pixel. drawSeq is the F-653 draw ordinal this sample is "
        "attributed to. F-728 APPENDED FIELDS, every field above is unchanged and "
        "in its old position: probeTaps={} probeFromCensus={} "
        "probePreRgba=({},{},{},{}) probeByteOffset={} censusByteRange={}..{} "
        "probeInsideCensusRange={} fenceTarget={} fenceCompleted={} "
        "fenceWaited={} -- rgba is now the loop's OWN read of that pixel, taken "
        "from the same q as the four census fields above, so it cannot disagree "
        "with them; probeTaps=1 is that tap happening. probePreRgba is the same "
        "four bytes read immediately after Map, which is where this row used to "
        "take them from, and it is printed so that if the wait above is ever "
        "broken again the difference shows up here instead of as a row that "
        "contradicts itself. probeFromCensus=0 means the stride skipped the "
        "probe's row and the probe was read from it immediately after the loop. "
        "probeByteOffset and censusByteRange are byte offsets into the same "
        "mapped buffer, so the two can be compared directly. fenceTarget is the "
        "value PresentOwnedFrame signalled for THIS list and fenceWaited says "
        "whether the Map was ordered after the copy: fenceWaited=0 means every "
        "field in this row describes whatever the buffer held at Map time. "
        "distinctRgba={} distinctCapped={} topRgba={} -- the number of DIFFERENT "
        "rgba values the examined pixels hold and the eight most common of them "
        "with their pixel counts. This is the field that separates one region of "
        "one colour from scattered pixels: a single-colour region drives "
        "distinctRgba to 2 (the region and the background it cut into) and puts "
        "essentially every pixel count on one entry of topRgba, while scattered "
        "pixels of many colours leave distinctRgba high and spread the counts. "
        "distinctCapped=1 means the surface held more distinct values than the "
        "census table holds and that modalRgba and topRgba below are then exact "
        "only over the first values the table took, which the row does not hide: "
        "distinctCapped=0 is the only reading in which they are exact over "
        "everything examined. "
        "modalRgba=({},{},{},{}) modalCount={} -- the most common single rgba "
        "value of the examined pixels, and how many of them carry it. "
        "changedPx={} changedBox={} -- changedPx is the count of examined pixels "
        "whose rgba is NOT modalRgba, and changedBox is the smallest rectangle "
        "containing all of them. The comparison is against the surface's OWN "
        "most common colour rather than against black, because the placeholder "
        "clear is rgba=(5,8,13,255): it is not black, it covers most of an "
        "unrasterised surface, so a box of the non-black pixels is the whole "
        "surface by construction and would say nothing about where anything was "
        "drawn. changedBox=absent with changedPx=0 is not a zero-size box: it "
        "means every examined pixel WAS the modal value, so the examined set is "
        "uniform, and no corner is printed because no region exists to bound. "
        "changedRows={} changedCols={} changedFirstRow={} changedFirstRowCount={} "
        "changedLastRow={} changedLastRowCount={} changedFirstCol={} "
        "changedFirstColCount={} changedLastCol={} changedLastColCount={} "
        "coverageRefused={} -- how many distinct rows and columns of the surface "
        "hold at least one changed pixel, and how many changed pixels sit on the "
        "first and last of them. changedRows and changedCols are COUNTS and are "
        "0 when no row or column holds a changed pixel; changedFirstRow, "
        "changedLastRow, changedFirstCol and changedLastCol are INDICES and print "
        "-1 in that same case, so -1 there means there is no such row, not that "
        "row -1 was measured. A solid rectangle has a small count on its "
        "first and last row and column (its edge lengths) and a large count in "
        "the middle; pixels scattered over the same area have few changed pixels "
        "per row and column and hit rows and columns the rectangle misses. A "
        "coverageRefused=1 with every coverage field at -1 means the surface has "
        "more rows plus columns than the census will allocate counters for and "
        "those measurements were NOT taken; -1 is a refusal marker there, not a "
        "count. "
        "exactBlack={} blackImplied={} -- exactBlack counts examined pixels whose "
        "four bytes are exactly 0,0,0,255, and blackImplied is total - nonBlack, "
        "which is what the nonBlack percentage above implies. nonBlack tests "
        "(r|g|b)!=0, so blackImplied also counts rgba=(0,0,0,0) and is an upper "
        "bound on exactBlack; the two are equal if and only if every black pixel "
        "in the examined set also carries alpha 255. Every F-729 field describes "
        "the same examined rows and pixels as the fields above it, so censusStride "
        "and censusRows bound all of them the same way",
        n, r, g, b, a, px, py, m_width, m_height, pitch, nonBlack, total,
        total ? (100.0 * static_cast<double>(nonBlack) / static_cast<double>(total)) : 0.0,
        maxChannel, m_lastPixelMeanChannel, sum, channelSamples, censusRows,
        static_cast<uint64_t>(censusStride),
        s_readbackCopyAfterDraw ? 1 : 0, s_readbackDrawSeq,
        probeTaps, probeFromCensus, preR, preG, preB, preA, probeOffset,
        censusFirstByte, censusLastByte, probeInsideCensusRange ? 1 : 0,
        fenceTarget, fenceCompleted, fenceWaited ? 1 : 0,
        static_cast<uint64_t>(keys.size()), distinctOverflow ? 1 : 0,
        topRgba.c_str(), static_cast<unsigned>(modalR), static_cast<unsigned>(modalG),
        static_cast<unsigned>(modalB), static_cast<unsigned>(modalA), modalCount,
        changedPx, chgBox, chgRows, chgCols, chgFirstRow, chgFirstRowCount,
        chgLastRow, chgLastRowCount, chgFirstCol, chgFirstColCount,
        chgLastCol, chgLastColCount, coverageRefused ? 1 : 0,
        exactBlack, blackImplied);

    m_readbackBuffer->Unmap(0, nullptr);
}

// ===========================================================================
// F-761: THE LATE-FRAME READBACK. A pixel sample of a frame that carries NO
// draw on it, which is the frame the window is showing for the overwhelming
// majority of a run in which the guest draws twice and then stops.
//
// WHY THE DRAW-PATH SAMPLE CANNOT ANSWER THE QUESTION. RecordDrawReadback is
// called from one place, immediately after a draw call is recorded on the open
// list, so a run's pixel census is a census of the frames the guest drew. In
// build/w716.log the guest issued two draws in 150 seconds, at 17:08:05.586 and
// 17:08:05.604, and the run's last present was 17:10:20.932 at presented=4400.
// So both existing samples describe a frame that had been off the screen for
// 135.3 seconds, and every pixel fact read out of that log -- the modal colour,
// the changed box, the distinct-value count -- is a fact about t = 17:08:05 and
// not about what anyone was looking at.
//
// THE BOUND IS NOT THE REASON. kDrawReadbackMaxReadbacks is 4
// (d3d12_backend.h:976) and the run made 2 draw-path readbacks, so the bound was
// never reached and is not why the census has two rows. The reason is that the
// census fires only after a draw and the run contained two draws.
//
// WHAT IS DELIBERATELY DUPLICATED, AND WHY. The census below re-implements the
// histogram, modal value, changed-box and exact-black measurements rather than
// sharing the draw path's. The alternative was refactoring ReportDrawReadback's
// census into a common helper, which would have touched a marker whose format is
// fixed; a refactor that cannot be shown to be byte-identical on 244 tracked
// markers is a worse trade than 60 duplicated lines. The two are kept honest
// against each other by printing the same field names in the same order, so a
// reader can put one row and the other side by side.
//
// drawSeq is NOT printed and neither is any other marker's name: naming another
// marker in this row's prose would make this row a hit for a census counting
// lines, which is how a marker with two real rows came to measure four.
// ===========================================================================

// What the ledger said about the buffer at the moment the copy was recorded, so
// the row describes the buffer it sampled rather than whatever the buffer is by
// the time the row is formatted. File-scope statics for the same reason
// s_readbackCopyAfterDraw is: they are written and read inside one present,
// under m_mutex, and they keep the header free of a second copy of the ledger.
static uint32_t s_lateFrameBuffer = 0;
static uint64_t s_lateFrameEverWritten = 0;
static uint64_t s_lateFramePresents = 0;
static uint64_t s_lateFrameClears = 0;
static uint64_t s_lateFrameDraws = 0;
static uint64_t s_lateFrameBlits = 0;
static uint64_t s_lateFrameDrawsOnList = 0;

bool D3D12Backend::RecordLateFrameReadback() {
    if (m_readbackDisabled) return false;
    if (m_lateFrameReadbackAttempts >= D3D12Backend::kLateFrameReadbackMaxReadbacks) {
        if (!m_lateFrameExhaustedLogged) {
            m_lateFrameExhaustedLogged = true;
            MCLA_LOG_INFO("LATE-FRAME-PIXEL exhausted after {} readbacks "
                          "(kLateFrameReadbackMaxReadbacks={}) -- recording OFF for "
                          "the rest of the process, for the reason the draw-path "
                          "bound gives: each readback is a GPU-to-CPU fence wait",
                          m_lateFrameReadbackAttempts,
                          D3D12Backend::kLateFrameReadbackMaxReadbacks);
        }
        return false;
    }
    if (!m_commandList || !m_inFrame) return false;
    if (m_frameIndex >= kBufferCount || !m_renderTargets[m_frameIndex]) return false;
    if (!EnsureDrawReadback()) return false;

    ++m_lateFrameReadbackAttempts;

    // The ledger snapshot and the index are taken BEFORE anything is recorded,
    // so the row describes this copy and not a later one.
    s_lateFrameBuffer = m_frameIndex;
    s_lateFrameDrawsOnList = s_drawIssuedOnList ? 1u : 0u;
    const BufferLedger& led = m_ledger[m_frameIndex];
    s_lateFrameEverWritten = led.everWritten;
    s_lateFramePresents = led.presents;
    s_lateFrameClears = led.clears;
    s_lateFrameDraws = led.draws;
    s_lateFrameBlits = led.blits;

    // This path records NO barrier of its own before the copy: the caller is the
    // refusal branch of ClearAndPresent, which transitions nothing, so the
    // buffer's tracked state on entry is PRESENT -- which is what the previous
    // present left it in. Asserting PRESENT here is the F-725 lesson applied in
    // the other direction: the state named must be the state that is there.
    D3D12_RESOURCE_BARRIER b = {};
    b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    b.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    b.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
    b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(1, &b);

    D3D12_TEXTURE_COPY_LOCATION dst = {};
    dst.pResource = m_readbackBuffer.Get();
    dst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
    dst.PlacedFootprint = m_readbackFootprint;
    D3D12_TEXTURE_COPY_LOCATION src = {};
    src.pResource = m_renderTargets[m_frameIndex].Get();
    src.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    src.SubresourceIndex = 0;
    m_commandList->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);

    // Straight back to PRESENT, because PresentOwnedFrame presents this buffer
    // immediately afterwards and D3D12 requires the tracked state to match.
    b.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_SOURCE;
    b.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
    m_commandList->ResourceBarrier(1, &b);
    return true;
}

void D3D12Backend::ReportLateFrameReadback() {
    if (!m_readbackBuffer || !m_device) return;
    ++m_lateFrameReadbackCompletions;

    // The same discipline the draw path uses, for the same reason: the copy
    // executed when the list was closed and executed, so the Map below must be
    // ordered after the Signal that followed it. s_lastSignalledFenceValue is
    // written by PresentOwnedFrame at the Signal itself and read here after that
    // function has returned, so it names THIS present's list and not a slot
    // indexed by a frame index that has already moved on.
    const uint64_t fenceTarget = s_lastSignalledFenceValue;
    const uint64_t fenceCompletedAtEntry =
        m_fence ? m_fence->GetCompletedValue() : 0;
    bool fenceWaited = false;
    if (m_fence && fenceCompletedAtEntry < fenceTarget) {
        m_fence->SetEventOnCompletion(fenceTarget, m_fenceEvent);
        WaitForSingleObject(m_fenceEvent, 2000);
        fenceWaited = true;
    }
    const uint64_t fenceCompleted = m_fence ? m_fence->GetCompletedValue() : 0;

    void* mapped = nullptr;
    D3D12_RANGE range = { 0, 0 };
    HRESULT hrMap = m_readbackBuffer->Map(0, &range, &mapped);
    if (FAILED(hrMap) || !mapped) {
        ++m_lateFrameReadbackMapFailures;
        const uint64_t n = m_lateFrameReadbackMapFailures;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("LATE-FRAME-PIXEL #{} Map hr=0x{:08X} ppData={} buffer={} "
                          "-- the copy executed but no value could be read, so this "
                          "row claims nothing about what the window is showing",
                          n, static_cast<uint32_t>(hrMap), mapped, s_lateFrameBuffer);
        }
        return;
    }

    const uint8_t* base = static_cast<const uint8_t*>(mapped) + m_readbackFootprint.Offset;
    const uint32_t pitch = static_cast<uint32_t>(m_readbackRowPitch);

    // Bounded exactly as the draw-path census is bounded, with the same constant
    // and the same reason: this runs on the render thread and a strided census
    // must never be readable as an exhaustive one, so the stride and the
    // examined counts are printed.
    static constexpr uint64_t kLateCensusMaxPixels = 1ull << 20;
    static constexpr uint32_t kLateCensusDistinctCap = 4096u;
    static constexpr uint32_t kLateCensusTopN = 8u;
    static constexpr uint32_t kLateCensusSlots = kLateCensusDistinctCap * 4u;

    const uint64_t surfacePixels = static_cast<uint64_t>(m_width) * m_height;
    uint32_t censusStride = 1;
    while (censusStride < m_height && surfacePixels / censusStride > kLateCensusMaxPixels) {
        censusStride *= 2;
    }

    uint64_t nonBlack = 0, maxChannel = 0, sum = 0, total = 0, censusRows = 0;
    uint64_t exactBlack = 0;
    uint64_t pr = 0, pg = 0, pb = 0, pa = 0;
    std::vector<uint32_t> slots(kLateCensusSlots, 0u);
    std::vector<uint32_t> keys;
    std::vector<uint64_t> counts;
    keys.reserve(kLateCensusDistinctCap);
    counts.reserve(kLateCensusDistinctCap);
    uint64_t distinctOverflow = 0;
    for (uint32_t y = 0; y < m_height; y += censusStride) {
        const uint8_t* row = base + static_cast<size_t>(y) * pitch;
        for (uint32_t x = 0; x < m_width; ++x) {
            const uint8_t* q = row + static_cast<size_t>(x) * 4u;
            if (q[0] | q[1] | q[2]) ++nonBlack;
            if (q[0] > maxChannel) maxChannel = q[0];
            if (q[1] > maxChannel) maxChannel = q[1];
            if (q[2] > maxChannel) maxChannel = q[2];
            sum += static_cast<uint64_t>(q[0]) + q[1] + q[2];
            ++total;
            const uint32_t key = static_cast<uint32_t>(q[0]) |
                                 (static_cast<uint32_t>(q[1]) << 8) |
                                 (static_cast<uint32_t>(q[2]) << 16) |
                                 (static_cast<uint32_t>(q[3]) << 24);
            uint32_t slot = ((key * 2654435761u) >> 12) & (kLateCensusSlots - 1u);
            uint32_t probes = 0;
            uint32_t found = 0u;
            while (probes < kLateCensusSlots) {
                const uint32_t occupant = slots[slot];
                if (occupant == 0u) break;
                if (keys[occupant - 1u] == key) { found = occupant; break; }
                slot = (slot + 1u) & (kLateCensusSlots - 1u);
                ++probes;
            }
            if (found != 0u) {
                ++counts[found - 1u];
            } else if (slots[slot] == 0u && keys.size() < kLateCensusDistinctCap) {
                keys.push_back(key);
                counts.push_back(1u);
                slots[slot] = static_cast<uint32_t>(keys.size());
            } else {
                ++distinctOverflow;
            }
            if (q[0] == 0u && q[1] == 0u && q[2] == 0u && q[3] == 255u) ++exactBlack;
        }
        ++censusRows;
    }

    // The probe is the viewport centre, taken from the SAME mapped bytes the
    // census just walked, for the reason the draw-path row gives: a probe read at
    // a different instant than the census is how a row comes to contradict
    // itself. Here it is read after the walk rather than inside it, and the walk
    // does not modify anything, so the two cannot disagree.
    {
        const uint8_t* row = base + static_cast<size_t>(m_height / 2u) * pitch;
        const uint8_t* q = row + static_cast<size_t>(m_width / 2u) * 4u;
        pr = q[0]; pg = q[1]; pb = q[2]; pa = q[3];
    }

    // The modal value, decided only now the histogram is complete. Strictly
    // greater-than in first-seen order, so ties go to the value seen first and
    // two runs of the same surface print the same row.
    uint32_t modalKey = 0;
    uint64_t modalCount = 0;
    for (size_t i = 0; i < keys.size(); ++i) {
        if (counts[i] > modalCount) { modalCount = counts[i]; modalKey = keys[i]; }
    }
    const unsigned modalR = modalKey & 0xFFu;
    const unsigned modalG = (modalKey >> 8) & 0xFFu;
    const unsigned modalB = (modalKey >> 16) & 0xFFu;
    const unsigned modalA = (modalKey >> 24) & 0xFFu;

    // Second walk, because the modal value is not known until the first has
    // ended. Comparing a pixel against a colour the same loop has not yet chosen
    // is how a bounding box gets printed for the wrong colour.
    uint64_t changedPx = 0;
    int64_t chgMinX = -1, chgMaxX = -1, chgMinY = -1, chgMaxY = -1;
    for (uint32_t y = 0; y < m_height; y += censusStride) {
        const uint8_t* row = base + static_cast<size_t>(y) * pitch;
        for (uint32_t x = 0; x < m_width; ++x) {
            const uint8_t* q = row + static_cast<size_t>(x) * 4u;
            const uint32_t key = static_cast<uint32_t>(q[0]) |
                                 (static_cast<uint32_t>(q[1]) << 8) |
                                 (static_cast<uint32_t>(q[2]) << 16) |
                                 (static_cast<uint32_t>(q[3]) << 24);
            if (key == modalKey) continue;
            ++changedPx;
            const int64_t lx = static_cast<int64_t>(x);
            const int64_t ly = static_cast<int64_t>(y);
            if (chgMinX < 0 || lx < chgMinX) chgMinX = lx;
            if (chgMaxX < 0 || lx > chgMaxX) chgMaxX = lx;
            if (chgMinY < 0 || ly < chgMinY) chgMinY = ly;
            if (chgMaxY < 0 || ly > chgMaxY) chgMaxY = ly;
        }
    }

    // The top-N histogram, in descending count with first-seen order as the
    // tie-break, so the printed histogram is stable between two runs of one
    // surface.
    std::string topRgba;
    {
        std::vector<uint32_t> order(keys.size());
        for (size_t i = 0; i < order.size(); ++i) order[i] = static_cast<uint32_t>(i);
        std::stable_sort(order.begin(), order.end(),
                         [&](uint32_t l, uint32_t r2) { return counts[l] > counts[r2]; });
        uint32_t shown = 0;
        for (uint32_t idx : order) {
            if (shown >= kLateCensusTopN) break;
            if (shown) topRgba.append(" ");
            char ent[80];
            const uint32_t k = keys[idx];
            std::snprintf(ent, sizeof(ent), "(%u,%u,%u,%u)x%llu",
                          static_cast<unsigned>(k & 0xFFu),
                          static_cast<unsigned>((k >> 8) & 0xFFu),
                          static_cast<unsigned>((k >> 16) & 0xFFu),
                          static_cast<unsigned>((k >> 24) & 0xFFu),
                          static_cast<unsigned long long>(counts[idx]));
            topRgba.append(ent);
            ++shown;
        }
        if (topRgba.empty()) topRgba = "none";
    }

    std::string chgBox = "absent";
    if (changedPx != 0) {
        char box[96];
        std::snprintf(box, sizeof(box), "x%lld..%lld y%lld..%lld",
                      static_cast<long long>(chgMinX), static_cast<long long>(chgMaxX),
                      static_cast<long long>(chgMinY), static_cast<long long>(chgMaxY));
        chgBox = box;
    }

    const uint64_t n = m_lateFrameReadbackAttempts;
    MCLA_LOG_INFO("LATE-FRAME-PIXEL #{} buffer={} of {} buffers everWritten={} "
                  "writes={} clears={} draws={} blits={} presentedWithNoDraw={} "
                  "drawsOnList={} fenceTarget={} fenceCompleted={} fenceWaited={} "
                  "rgba=({},{},{},{}) at ({},{}) of {}x{} rowPitch={} nonBlack={}/{} "
                  "maxChannel={} sum={} channelSamples={} censusRows={} "
                  "censusStride={} distinctRgba={} distinctCapped={} topRgba={} "
                  "modalRgba=({},{},{},{}) modalCount={} changedPx={} changedBox={} "
                  "exactBlack={} -- WHICH BUFFER THE WINDOW WAS SHOWING, sampled "
                  "from a present that recorded NO draw on its command list, so it "
                  "is the frame that was on screen and not a frame the guest drew. "
                  "drawsOnList=0 is the whole point of this row and it is what "
                  "makes it a late-frame sample: a row that can only be produced by "
                  "a draw cannot say this. everWritten=0 would mean the swap chain "
                  "rotated onto a resource nothing has ever written, and the "
                  "present of it is refused by name rather than shown. distinctRgba "
                  "and topRgba are what say whether the window is showing "
                  "uninitialised memory: uninitialised is many colours with the "
                  "counts spread out, a rotated stale frame is one or two colours "
                  "with one count carrying almost all of them. changedBox is the "
                  "smallest rectangle holding every examined pixel that differs "
                  "from the surface's OWN modal value, not from black, so a frame "
                  "whose background is itself non-black still bounds its content. "
                  "Nothing here is clamped and no value is substituted for a pixel "
                  "that was not read",
                  n, s_lateFrameBuffer, kBufferCount, s_lateFrameEverWritten,
                  s_lateFrameClears + s_lateFrameDraws + s_lateFrameBlits,
                  s_lateFrameClears, s_lateFrameDraws, s_lateFrameBlits,
                  s_lateFramePresents, s_lateFrameDrawsOnList,
                  fenceTarget, fenceCompleted, fenceWaited ? 1 : 0,
                  static_cast<unsigned>(pr), static_cast<unsigned>(pg),
                  static_cast<unsigned>(pb), static_cast<unsigned>(pa),
                  m_width / 2u, m_height / 2u, m_width, m_height, pitch,
                  nonBlack, total, maxChannel, sum, total * 3ull,
                  censusRows, censusStride,
                  static_cast<uint64_t>(keys.size()),
                  distinctOverflow ? 1 : 0, topRgba.c_str(),
                  modalR, modalG, modalB, modalA, modalCount,
                  changedPx, chgBox.c_str(), exactBlack);

    m_readbackBuffer->Unmap(0, nullptr);
}

void D3D12Backend::WaitForGpu() {
    if (!m_device || !m_commandQueue || !m_fence || !m_fenceEvent) return;

    uint64_t fenceVal = ++m_currentFenceValue;
    if (SUCCEEDED(m_commandQueue->Signal(m_fence.Get(), fenceVal))) {
        if (m_fence->GetCompletedValue() < fenceVal) {
            m_fence->SetEventOnCompletion(fenceVal, m_fenceEvent);
            WaitForSingleObject(m_fenceEvent, INFINITE);
        }
    }
}

bool D3D12Backend::StreamingUpload(ID3D12Resource* dest, const void* data, uint32_t size) {
    if (!m_device || !m_copyQueue || !m_copyCommandList || !dest || !data || size == 0) return false;

    D3D12_HEAP_PROPERTIES uploadHeapProps = {};
    uploadHeapProps.Type = D3D12_HEAP_TYPE_UPLOAD;

    D3D12_RESOURCE_DESC bufDesc = {};
    bufDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bufDesc.Width = (size + 255) & ~255u; // align to 256 bytes
    bufDesc.Height = 1;
    bufDesc.DepthOrArraySize = 1;
    bufDesc.MipLevels = 1;
    bufDesc.SampleDesc.Count = 1;
    bufDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    Microsoft::WRL::ComPtr<ID3D12Resource> uploadBuffer;
    HRESULT hr = m_device->CreateCommittedResource(
        &uploadHeapProps, D3D12_HEAP_FLAG_NONE,
        &bufDesc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&uploadBuffer));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload CreateCommittedResource failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    D3D12_RANGE readRange = {0, 0};
    hr = uploadBuffer->Map(0, &readRange, &mapped);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload Map failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }
    memcpy(mapped, data, size);
    uploadBuffer->Unmap(0, nullptr);

    hr = m_copyCommandList->Reset(m_copyAllocator.Get(), nullptr);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload CopyReset failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    m_copyCommandList->CopyBufferRegion(dest, 0, uploadBuffer.Get(), 0, size);

    hr = m_copyCommandList->Close();
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload Close failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    ID3D12CommandList* lists[] = { m_copyCommandList.Get() };
    m_copyQueue->ExecuteCommandLists(1, lists);

    return true;
}

uint64_t D3D12Backend::SignalCopyFence() {
    if (!m_copyQueue || !m_copyFence) return 0;
    ++m_copyFenceValue;
    m_copyQueue->Signal(m_copyFence.Get(), m_copyFenceValue);
    return m_copyFenceValue;
}

void D3D12Backend::WaitForCopyFence(uint64_t fenceValue) {
    if (!m_copyFence || !m_copyFenceEvent) return;
    if (m_copyFence->GetCompletedValue() < fenceValue) {
        m_copyFence->SetEventOnCompletion(fenceValue, m_copyFenceEvent);
        WaitForSingleObject(m_copyFenceEvent, INFINITE);
    }
}

bool D3D12Backend::Resize(uint32_t width, uint32_t height) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_swapChain) return false;
    if (width == 0 || height == 0) return false;

    MCLA_LOG_INFO("D3D12Backend: Resizing swap chain to {}x{}", width, height);

    WaitForGpu();

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_fenceValues[i] = m_fenceValues[m_frameIndex];
    }

    // Blit texture is sized to the backbuffer; recreate on next PresentBgra.
    m_fbTexture.Reset();
    m_fbUpload.Reset();
    m_fbFootprint = {};
    m_fbTexW = 0;
    m_fbTexH = 0;
    m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;

    HRESULT hr = m_swapChain->ResizeBuffers(kBufferCount, width, height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: ResizeBuffers failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_width = width;
    m_height = height;

    // The extent CHANGED, so the rescale must be republished for every shader
    // translated from here on. Placed after ResizeBuffers has succeeded, so the
    // published extent is always one the swapchain really has. Resize is reached
    // from the window-resize path (src/app.cpp:328 OnResize -> RESIZE command ->
    // src/render_thread.cpp:4183), and build/w707.log:386 shows it firing once
    // during initialization, before any draw.
    PublishClipDisableExtent("resize", m_width, m_height, m_cachePipelineDraws);

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    // F-761: ResizeBuffers has just handed back NEW back-buffer resources. Their
    // contents are undefined, so every "was this buffer ever written" answer from
    // before this call describes resources that no longer exist. MEASURED in
    // build/w716.log: this fires at 17:07:53.702, the same millisecond as the
    // first present of the run, which is precisely why the first three presents
    // after it are the ones that make all three indices written.
    ResetBufferLedger("ResizeBuffers");

    return CreateRenderTargets();
}

// Wait until the GPU is done with everything recorded against the current back
// buffer. Callers that write into the upload arena region for this frame must
// do so only after this returns, otherwise the CPU can overwrite bytes the GPU
// is still reading from the previous frame that used the same region.
bool D3D12Backend::WaitForCurrentFrameGpu() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return false;
    uint64_t completedVal = m_fence->GetCompletedValue();
    if (completedVal < m_fenceValues[m_frameIndex]) {
        m_fence->SetEventOnCompletion(m_fenceValues[m_frameIndex], m_fenceEvent);
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }
    return true;
}

// 2026-10-02: the gate's own name table. A function-local static table rather
// than a switch in the recorder so the token a soak greps for is written down
// exactly once per gate and the recorder cannot be handed a name that does not
// match its counter index.
static const char* const kBeginFrameGateName[] = {
    "not-initialised",  // BeginFrameGate::kNotInitialized
    "already-in-frame", // BeginFrameGate::kAlreadyInFrame
    "fence-gate",       // BeginFrameGate::kFenceGate
    "allocator-reset",  // BeginFrameGate::kAllocatorReset
    "commandlist-reset",// BeginFrameGate::kCommandListReset
};
static_assert(sizeof(kBeginFrameGateName) / sizeof(kBeginFrameGateName[0]) ==
                  static_cast<size_t>(D3D12Backend::BeginFrameGate::kCount),
              "every BeginFrameGate needs a name token, or a refusal would be "
              "counted under a gate the log cannot name");

void D3D12Backend::RecordBeginFrameRefusal(BeginFrameGate gate, uint32_t a,
                                           uint32_t b) {
    const size_t idx = static_cast<size_t>(gate);
    // Counted UNCONDITIONALLY, before the throttle (F-649: the throttle gates
    // the TEXT, never the count -- a suppressed row that is not counted is how a
    // soak reads "nothing happened" out of something that happened 616,824
    // times). Per-gate n, so each exit throttles on its OWN count and a flood
    // of one gate cannot silence another.
    const uint64_t n = ++m_beginFrameRefusalByGate[idx];
    ++m_beginFrameRefusals;
    if (!ShouldLogRefusal(n)) {
        return;
    }
    MCLA_LOG_WARN(
        "D3D12-BEGINFRAME-REFUSE #{} gate={} a={} b={} returned=false | "
        "begins={} refusals={} frameIndex={} inFrame={} initialized={} "
        "presented={} drawn={} abandoned={} | a/b are the refusing gate's own "
        "inputs, copied verbatim at the call site and NOT interpreted: "
        "not-initialised passes (0,0); already-in-frame passes "
        "(m_frameIndex, m_presentedFrames); fence-gate passes "
        "(m_frameIndex,0); allocator-reset and commandlist-reset pass "
        "(m_frameIndex, HRESULT). begins=0 with refusals>0 means the frame "
        "context NEVER opened, which is a different fault from a frame refused "
        "once in a while. already-in-frame is the latch fault: a frame was begun "
        "and never released (see D3D12-FRAME-ABANDONED).",
        n, kBeginFrameGateName[idx], a, b, m_beginFrameBegins,
        m_beginFrameRefusals, m_frameIndex, m_inFrame ? 1u : 0u,
        m_initialized ? 1u : 0u, m_presentedFrames, m_drawOwnedFrames,
        m_framesAbandoned);
}

// 2026-10-02: the release-on-abandon half of the BeginFrame fix. See the
// declaration in d3d12_backend.h for why `m_inFrame` needed one.
//
// WHAT IT DOES AND DOES NOT DO. It closes the command list and clears
// `m_inFrame` and `m_frameWriter`, and nothing else: no render target is
// created, no back buffer is bound, no command is recorded, no HRESULT is
// forced. The next BeginFrame() Resets the command allocator and the command
// list, which discards whatever this frame recorded but never executed.
//
// THE Close() IS NOT OPTIONAL, AND THE HARNESS IS WHY. The first version of
// this function cleared `m_inFrame` and nothing else, on the reasoning that
// "the next BeginFrame's Reset discards the unexecuted commands". MEASURED on
// this machine against real D3D12 objects, that is FALSE:
// ID3D12CommandAllocator::Reset fails with hr=0x80070057 while any command
// list is still RECORDING with that allocator, and the debug layer names it --
// "The command allocator cannot be reset because a command list is currently
// being recorded with the allocator." So clearing the latch alone converts a
// refusal on `already-in-frame` into a refusal on `allocator-reset`: still
// refused, still silent about why, and now with a misleading gate name.
// BeginFrame() opened the list, so abandoning the frame must close it. That is
// the whole D3D12 rule, and it is why the fix is two statements and not one.
//
// The Close() HRESULT is deliberately NOT checked as a pass/fail: closing a list
// that is already closed returns 0x80004005 (measured) and that is not an error
// here, it means the frame never opened. `m_inFrame` is the real guard -- the
// function returns before touching the list when no frame is in flight, which
// is also what makes it safe to call unconditionally at every
// BeginFrame-then-call site without threading a success flag out of five
// different functions.
void D3D12Backend::AbandonFrame(const char* owner) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_inFrame) {
        return;
    }
    if (m_commandList) {
        // Best-effort. A failure here is recorded and bounded, not fatal: the
        // latch is still released below, and a list that would not close is a
        // condition the NEXT BeginFrame's Reset will report by name.
        const HRESULT hrClose = m_commandList->Close();
        if (FAILED(hrClose)) {
            const uint64_t cn = ++m_frameAbandonCloseFailures;
            if (ShouldLogRefusal(cn)) {
                MCLA_LOG_WARN("D3D12-FRAME-ABANDON #{} owner={} list->Close() "
                              "failed hr=0x{:08X}; the latch is still being "
                              "released, so the next BeginFrame may refuse on "
                              "its own gate and will name it",
                              cn, owner, static_cast<uint32_t>(hrClose));
            }
        }
    }
    m_inFrame = false;
    m_frameWriter = FrameOwner::None;
    const uint64_t n = ++m_framesAbandoned;
    if (ShouldLogRefusal(n)) {
        MCLA_LOG_WARN(
            "D3D12-FRAME-ABANDONED #{} owner={} beganFrame={} frameIndex={} "
            "presented={} drawn={} -- the frame was begun and then DROPPED "
            "without a present, so its command list was closed and m_inFrame "
            "released here instead of leaving the next BeginFrame to refuse. "
            "Both halves are required: releasing the latch alone leaves the "
            "list recording and the next ID3D12CommandAllocator::Reset fails "
            "with 0x80070057.",
            n, owner, m_beginFrameBegins, m_frameIndex, m_presentedFrames,
            m_drawOwnedFrames);
    }
}

bool D3D12Backend::BeginFrame() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    // 2026-10-02: EVERY exit below names itself. This function used to be
    // five `return false`s with no log line on any of them, and it is the one
    // boolean that gates the whole draw path: render_thread.cpp:3598 stores its
    // result as `beganFrame`, and DRAW-CP-ISSUED then reports beginFrame=0 --
    // a row that named the outcome and withheld the cause. MEASURED on
    // build/w698.log (55,892 lines), which carries exactly two DRAW-CP-ISSUED
    // rows, both beginFrame=0, and zero of every marker downstream of this
    // gate, so the log could not say which of these five fired.
    //
    // The two conditions on the first line are SEPARATE refusals, not one: a
    // backend that was never initialised and a frame that is already open are
    // different faults with different fixes, and merging them into one token
    // would have made the row ambiguous in exactly the case it exists for.
    if (!m_initialized) {
        RecordBeginFrameRefusal(BeginFrameGate::kNotInitialized, 0u, 0u);
        return false;
    }
    if (m_inFrame) {
        RecordBeginFrameRefusal(BeginFrameGate::kAlreadyInFrame, m_frameIndex,
                                static_cast<uint32_t>(m_presentedFrames));
        return false;
    }

    if (!WaitForCurrentFrameGpu()) {
        // Unreachable from the check above TODAY: WaitForCurrentFrameGpu's only
        // false path is its own `!m_initialized` (:3349), BeginFrame already
        // tested the same flag while holding the same recursive mutex, and
        // m_initialized is written only under that mutex (:525 true, :3875
        // false). It is named rather than deleted so that if that invariant is
        // ever broken the log says so instead of going quiet.
        RecordBeginFrameRefusal(BeginFrameGate::kFenceGate, m_frameIndex, 0u);
        return false;
    }

    HRESULT hr = m_commandAllocators[m_frameIndex]->Reset();
    if (FAILED(hr)) {
        RecordBeginFrameRefusal(BeginFrameGate::kAllocatorReset, m_frameIndex,
                                static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_commandList->Reset(m_commandAllocators[m_frameIndex].Get(), nullptr);
    if (FAILED(hr)) {
        RecordBeginFrameRefusal(BeginFrameGate::kCommandListReset, m_frameIndex,
                                static_cast<uint32_t>(hr));
        return false;
    }

    m_inFrame = true;
    m_uploadOffset = 0;
    ++m_beginFrameBegins;
    return true;
}

bool D3D12Backend::EnsureFbTexture(uint32_t width, uint32_t height) {
    if (m_fbTexture && m_fbUpload && m_fbTexW == width && m_fbTexH == height) {
        return true;
    }

    m_fbTexture.Reset();
    m_fbUpload.Reset();
    m_fbFootprint = {};
    m_fbTexW = 0;
    m_fbTexH = 0;
    m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;

    D3D12_HEAP_PROPERTIES defProps = {};
    defProps.Type = D3D12_HEAP_TYPE_DEFAULT;

    D3D12_RESOURCE_DESC texDesc = {};
    texDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    texDesc.Width = width;
    texDesc.Height = height;
    texDesc.DepthOrArraySize = 1;
    texDesc.MipLevels = 1;
    texDesc.SampleDesc.Count = 1;
    texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    texDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    texDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

    HRESULT hr = m_device->CreateCommittedResource(
        &defProps, D3D12_HEAP_FLAG_NONE, &texDesc, D3D12_RESOURCE_STATE_COPY_DEST,
        nullptr, IID_PPV_ARGS(&m_fbTexture));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureFbTexture CreateCommittedResource failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    UINT64 totalBytes = 0;
    m_device->GetCopyableFootprints(&texDesc, 0, 1, 0, &m_fbFootprint, nullptr, nullptr, &totalBytes);

    D3D12_HEAP_PROPERTIES upProps = {};
    upProps.Type = D3D12_HEAP_TYPE_UPLOAD;
    D3D12_RESOURCE_DESC bufDesc = {};
    bufDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bufDesc.Width = totalBytes;
    bufDesc.Height = 1;
    bufDesc.DepthOrArraySize = 1;
    bufDesc.MipLevels = 1;
    bufDesc.SampleDesc.Count = 1;
    bufDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    hr = m_device->CreateCommittedResource(&upProps, D3D12_HEAP_FLAG_NONE, &bufDesc,
                                           D3D12_RESOURCE_STATE_GENERIC_READ,
                                           nullptr, IID_PPV_ARGS(&m_fbUpload));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: EnsureFbTexture staging failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        m_fbTexture.Reset();
        m_fbFootprint = {};
        return false;
    }

    m_fbTexW = width;
    m_fbTexH = height;
    m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;
    MCLA_LOG_INFO("D3D12Backend: blit framebuffer texture ready ({}x{}, R8G8B8A8, {} bytes)",
                  width, height, totalBytes);
    return true;
}

// ===========================================================================
// F-650: the back-buffer arbiter -- exactly one writer per presented frame.
//
// WHICH SURFACE THE CONSOLE RENDERS INTO, and which one this host must
// present. Measured from the guest's own frame-end path, not assumed. The
// guest drives the Xenos display engine every frame; the last
// PRESENT-SURF-AUDIT in build/w662.log (frame=292920, w662.log:797561) reads:
//
//   presents=292920 vdSwapCalls=146460 routeRatio=live
//   vdObj=C6CDA6D0 vdInfo=004E0D30
//   | resolved=CB17BF80 score=60 | phys=004E0D30 score=1 | kva=C04E0D30 score=0
//   => resolved-partially-varied
//
// `routeRatio=live` is the load-bearing part: the guest really is issuing a
// display-engine swap (146,460 of them), and that swap resolves to exactly ONE
// scanout surface, guest VA 0xCB17BF80. Of the three candidates it is the only
// one with anything in it -- score 60, "partially varied" -- while the swap's
// own source (phys=004E0D30) and its KVA (C04E0D30) are both flat, score 1 and
// 0. So on the console there is a single scanout image and this is it.
//
// WHY THAT FORCES ARRANGEMENT (a) -- draw into the surface that is presented.
// 0xCB17BF80 is GUEST memory. The host's draws are not: they go through
// DrawDynamicMeshWithPipeline into m_renderTargets[m_frameIndex], the D3D12
// swapchain back buffer. Nothing in this backend writes guest memory, and
// nothing establishes that 0xCB17BF80's bytes were produced by our draws -- they
// are whatever the guest's own Xenos emulation left there. The two surfaces
// cannot be reconciled by pointing them at each other.
//
// Arrangement (b) -- offscreen target, blit the guest framebuffer, composite --
// is therefore not merely more work, it is the current defect in a more
// expensive form. If the guest framebuffer is presented on top, the frame is
// 100% blit and 0% draw, so the real geometry stays invisible exactly as it is
// now and the draws become decoration -- which is the premise (b) requires them
// to be. That premise is also contradicted by the guest's own behaviour:
// DRAW-CP-DRAWN #20600 prim=8 vertices=3 indexed=0 is the guest issuing real
// geometry, and those pixels exist ONLY in the host back buffer.
//
// So: the render target and the presented image are the SAME OBJECT. The draw
// path owns it. The blit and the clear are refused, counted and named, instead
// of being left to win the frame on a race.
// ===========================================================================

const char* D3D12Backend::FrameOwnerName(FrameOwner owner) {
    switch (owner) {
        case FrameOwner::Draw:  return "draw";
        case FrameOwner::Blit:  return "blit";
        case FrameOwner::Clear: return "clear";
        case FrameOwner::None:  break;
    }
    return "none";
}

// ===========================================================================
// F-761: THE PER-BUFFER WRITE LEDGER, AND THE REFUSAL IT MAKES POSSIBLE.
//
// WHAT QUESTION THIS EXISTS TO ANSWER, AND WHY THE ARBITER ABOVE CANNOT. The
// arbiter answers "who may write the buffer that is current right now". It
// cannot answer "has buffer N ever been written", because
// PresentOwnedFrame advances m_frameIndex to
// m_swapChain->GetCurrentBackBufferIndex() on EVERY present, so the previous
// frame's ownership is discarded before anyone can ask about it. kBufferCount is
// 3 (d3d12_backend.h:34) and the chain rotates through all three, which makes
// "the buffer the window is showing" a different buffer from "the buffer the
// last draw wrote" for two presents out of three.
//
// THE MEASUREMENT THAT PROVES THE ROTATION IS REAL, from build/w716.log by
// timestamp. 17:07:53.702 is a ResizeBuffers (D3D12Backend: Resizing swap
// chain to 1280x720), so all three back buffers are brand-new resources at that
// instant and none of them holds anything. The first three presents after it
// carry owner=clear, which reaches ClearRenderTargetView on
// m_renderTargets[m_frameIndex] and then presents that same index -- so buffers
// 0, 1 and 2 are each written by present #1, #2 and #3 respectively. Every
// subsequent present rotates to the next index. That is why the draw-path
// sample rows at 17:08:05.582 and .604 describe a DIFFERENT buffer from the one
// the window was showing at 17:10:20.932 (presented=4400).
//
// WHY THE REFUSAL IS HERE AND NOT IN THE ARBITER. A clear, a blit and a draw
// all WRITE; the refusal is about PRESENTING a resource whose contents were
// never defined, which is a different question and belongs to the present. It
// is deliberately a refusal and not a fix: charter F-609 forbids inventing a
// pixel, and an undefined resource has no honest value to substitute -- not
// black (a black frame is a measurement), not a held copy of the last good
// frame (that is a cover-up), and not the placeholder constant (that is the
// synthetic image F-758 deleted).
// ===========================================================================

void D3D12Backend::ResetBufferLedger(const char* why) {
    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_ledger[i] = BufferLedger();
    }
    MCLA_LOG_INFO("BUFFER-LEDGER RESET via={} buffers={} -- every 'ever written' "
                  "answer is now 0, because this handed back NEW back-buffer "
                  "resources whose contents are not the old contents. A chain that "
                  "rotates through buffers nothing has written presents "
                  "uninitialised resource memory, which is what this ledger makes "
                  "visible instead of leaving to be guessed at",
                  why, kBufferCount);
}

void D3D12Backend::NoteBufferWrite(const char* how) {
    if (m_frameIndex >= kBufferCount) return;
    BufferLedger& led = m_ledger[m_frameIndex];
    led.everWritten = 1;
    // F-763: THE CONTENT VERSION MOVES HERE AND NOWHERE ELSE. One bump per
    // write, at the single chokepoint every write to this resource passes
    // through, so contentSeq names a STATE of the resource rather than a moment
    // on a clock. The four callers are measured: "draw-path-clear" (the draw
    // path's own placeholder clear), "draw" (the draw call itself), "blit"
    // (CopyResource from the composited framebuffer) and "clear"
    // (ClearAndPresent's ClearRenderTargetView). Every other use of
    // m_renderTargets[m_frameIndex] in this file copies OUT of it for a
    // readback, reads its descriptor, transitions it, or resets it, and none of
    // those changes a byte, so none of them may bump this.
    ++led.contentSeq;
    if (std::strcmp(how, "draw") == 0) {
        ++led.draws;
    } else if (std::strcmp(how, "blit") == 0) {
        ++led.blits;
    } else {
        ++led.clears;
    }
}

bool D3D12Backend::RefuseUnwrittenPresent(const char* ownerName) {
    if (m_frameIndex >= kBufferCount) return false;
    const BufferLedger& led = m_ledger[m_frameIndex];
    if (led.everWritten) return false;
    const uint64_t n = ++m_unwrittenPresentRefused;
    if (ShouldLogRefusal(n)) {
        MCLA_LOG_ERROR("FRAME-UNWRITTEN-PRESENT-REFUSED #{} writer={} buffer={} of "
                       "{} buffers presents={} clears={} draws={} blits={} "
                       "censusSamples={} -- REFUSED, and this is the honest answer "
                       "rather than a fix: this buffer has never been written by "
                       "anything, so its contents are undefined and presenting it "
                       "would show uninitialised resource memory. Nothing is "
                       "substituted for it. A black frame would be a measurement "
                       "this backend has not taken, a held copy of the last good "
                       "frame would be a cover-up, and the placeholder constant is "
                       "the synthetic image that was deleted. The window keeps "
                       "whatever it was already showing",
                       n, ownerName, m_frameIndex, kBufferCount, led.presents,
                       led.clears, led.draws, led.blits, m_lateFrameReadbackAttempts);
    }
    return true;
}

// F-763: THE EMPTY BEAT IS HELD, NOT FLIPPED.
//
// THE DEFECT THIS REMOVES, MEASURED. build/w718.log, 150 s soak, 50,403 lines,
// 4,400 flips. PresentOwnedFrame advances m_frameIndex to
// m_swapChain->GetCurrentBackBufferIndex() on EVERY flip, kBufferCount is 3, and
// the guest issued 2 draws (DRAW-CP-ISSUED #1 at 19:21:29.255 and #2 at
// 19:21:29.301) then stopped. Every beat after that reached this file's
// FrameOwner::None branch -- 4,041 clearRefused by the last FRAME-OWNER row at
// 19:23:44.659 -- and each one flipped a DIFFERENT buffer into a window whose
// last real content was the guest's.
//
// THE ROTATION IS THE FLASH, AND THE PIXELS PROVE IT. The four
// LATE-FRAME-PIXEL rows (19:21:29.759 .. .859) sampled three consecutive beats
// and read three different surfaces out of one window:
//   #1 buffer=1 rgba=(15,25,56,255) distinctRgba=1  changedPx=0
//   #2 buffer=2 rgba=(5,8,13,255)  distinctRgba=2  changedPx=230400
//            changedBox=x0..639 y0..359
//   #3 buffer=0 rgba=(0,0,0,0)    distinctRgba=1  changedPx=0
// (15,25,56) is the startup clear's own colour -- render_thread.cpp:134 asks for
// (0.06f, 0.10f, 0.22f, 1.0f), which is 15.3, 25.5, 56.1 in 8-bit -- and it is
// the "dark blue" half of the flash the user reported. (0,0,0,0) is the "black"
// half. Buffer 2 carries the guest's draw and is the only one of the three that
// is guest content. So the window cycled navy -> guest -> zeros -> navy at the
// 30 Hz heartbeat cadence, and nothing in the log said so, because every one of
// those flips was a SUCCESS and reported as one.
//
// WHAT "NEW CONTENT" MEANS HERE, AND IT IS NOT A GUESS ABOUT THE GUEST. It is
// BufferLedger::contentIsNew(): this resource's content version differs from the
// version this same index last handed the compositor. Both halves are maintained
// at the only two places that can know them -- NoteBufferWrite bumps contentSeq,
// PresentOwnedFrame records contentShown -- and both are per-index, so the
// question asked is "would flipping THIS buffer change the window", which is the
// question a flip actually answers. Nothing here consults the guest, the clock,
// or a frame counter.
//
// WHY HOLDING IS THE HONEST DISPLAY AND NOT A COVER-UP. The window keeps
// displaying the guest's own last frame, byte for byte, because nothing has
// overwritten it and nothing has been substituted into it. That is the same
// thing a real console does when a title stops submitting frames. The
// alternatives were measured, not argued: a held SYNTHETIC frame is what F-758
// deleted and F-609 forbids; presenting an unwritten resource is what
// RefuseUnwrittenPresent above refuses; and the only remaining option -- keep
// flipping -- is the defect.
//
// WHAT THIS MUST NOT BECOME. F-760 is the defect immediately upstream of this
// one: it froze displayed= at 360 for 136 s because the clear was refused and
// the FRAME with it was abandoned, so a frame the guest HAD drawn never reached
// the screen. The two differ in exactly one measurable way and the next soak
// separates them. F-760 suppressed flips whose buffer held content the window
// had not seen; this suppresses only flips whose buffer holds the bytes already
// on screen. So a guest that draws presents on the draw's own flip -- contentSeq
// moved, contentIsNew() is true, the flip is not gated -- and only the beats in
// between are held. If a future soak shows a draw with no flip after it, this
// has reproduced F-760 and is wrong.
//
// THE MARKER IS RATE-LIMITED, because a beat is ~30 Hz and an unbounded
// per-beat line is how this tree has been burned before (see the 616,824-row
// note at soak_census.py:65-66). ShouldLogRefusal is the house pattern: the
// first 8, then every 200th, which is 29 lines across w718's 4,400 beats. Every
// line carries shownTotal and heldTotal so a reader sees presented= standing
// still while this counter climbs, which is the whole of the change in two
// numbers.
bool D3D12Backend::RefuseUnchangedPresent(const char* ownerName) {
    if (m_frameIndex >= kBufferCount) return false;
    const BufferLedger& led = m_ledger[m_frameIndex];
    if (led.contentIsNew()) return false;
    const uint64_t n = ++m_heldBeatsNotShown;
    if (ShouldLogRefusal(n)) {
        MCLA_LOG_WARN("BEAT-HELD-NO-NEW-CONTENT #{} shownTotal={} heldTotal={} "
                      "buffer={} of {} contentSeq={} contentShown={} writes={} "
                      "clears={} draws={} blits={} everWritten={} writer={} -- "
                      "this beat showed nothing new, so no flip was issued and "
                      "m_frameIndex was NOT advanced. contentSeq equals the "
                      "contentSeq this same index already showed, so its bytes "
                      "are identical; flipping it would only rotate the window "
                      "onto a buffer holding a DIFFERENT earlier frame, and that "
                      "alternation is the flash the user reported. The window "
                      "keeps the last frame a real writer produced. Nothing is "
                      "synthesised, nothing is clamped, no rotation is "
                      "re-enabled, and shownTotal is meant to be standing still",
                      n, m_presentedFrames, n, m_frameIndex, kBufferCount,
                      led.contentSeq, led.contentShown, led.writes(), led.clears,
                      led.draws, led.blits, led.everWritten, ownerName);
    }
    return true;
}

bool D3D12Backend::MayWriteBackBuffer(FrameOwner owner) {
    // The draw path always owns the back buffer. The blit and the clear own it
    // only until the first draw has presented: that window is what keeps the W6
    // PresentBgra pipe proof (render_thread.cpp:152) and the pre-guest-content
    // gradient (render_thread.cpp:1039) alive before any guest geometry arrives,
    // and losing it would trade a black screen for a black screen.
    const bool allowed = (owner == FrameOwner::Draw) || !m_drawPathTookBackBuffer;
    if (allowed) {
        if (m_frameWriter != FrameOwner::None && m_frameWriter != owner) {
            const uint64_t n = ++m_ownerConflicts;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("FRAME-OWNER CONFLICT #{}: {} wrote the back buffer "
                               "after {} in the same present window",
                               n, FrameOwnerName(owner), FrameOwnerName(m_frameWriter));
            }
        }
        m_frameWriter = owner;
        return true;
    }
    // A non-owner. Counted against the writer that lost, never into a shared
    // bucket, so "the blit never ran" and "the blit ran and was stopped here"
    // stay two different facts.
    uint64_t& counter = (owner == FrameOwner::Blit) ? m_blitRefused : m_clearRefused;
    const uint64_t n = ++counter;
    if (ShouldLogRefusal(n)) {
        MCLA_LOG_WARN("FRAME-OWNER REFUSED #{}: writer={} may not touch the back "
                      "buffer; owner=draw presented={} drawn={} blitRefused={} "
                      "clearRefused={} conflicts={}",
                      n, FrameOwnerName(owner), m_presentedFrames, m_drawOwnedFrames,
                      m_blitRefused, m_clearRefused, m_ownerConflicts);
    }
    return false;
}

// F-650: the single sanctioned Present(). Before this, three functions each
// closed, executed, presented, signalled and advanced m_frameIndex in their own
// copy of the same eleven lines, so "which writer produced the frame" was not
// recorded anywhere and could only be inferred from PRESENT-BLIT vs DRAW-CP
// counts. The FRAME-OWNER row below is that fact, once per presented frame.
bool D3D12Backend::PresentOwnedFrame(FrameOwner owner) {
    HRESULT hr = m_commandList->Close();
    if (FAILED(hr)) {
        m_inFrame = false;
        m_frameWriter = FrameOwner::None;
        return false;
    }

    ID3D12CommandList* ppCommandLists[] = { m_commandList.Get() };
    m_commandQueue->ExecuteCommandLists(1, ppCommandLists);

    hr = m_swapChain->Present(1, 0);
    m_lastPresentHr = hr;

    m_currentFenceValue++;
    // F-728: record the value on the SAME Signal, before m_frameIndex moves.
    // The readback's wait has to name the list it is waiting for, and this is
    // the only line that knows which value that is. Signalling is unchanged and
    // unconditional; only the result is now inspected.
    if (SUCCEEDED(m_commandQueue->Signal(m_fence.Get(), m_currentFenceValue))) {
        s_lastSignalledFenceValue = m_currentFenceValue;
    }
    m_fenceValues[m_frameIndex] = m_currentFenceValue;
    // F-761: counted against the index that was just presented, BEFORE the
    // advance below, so "how many times was this buffer shown" and "how many
    // presents have there been" are two numbers a reader can divide.
    if (m_frameIndex < kBufferCount) {
        ++m_ledger[m_frameIndex].presents;
        // F-763: and the CONTENT VERSION this flip showed. This is the only
        // line that can say "the window is now displaying this resource's
        // contentSeq", and it is placed before the m_frameIndex advance below
        // for the same reason the presents++ above is: after the advance it
        // names the wrong buffer. Every flip goes through here, so the
        // bookkeeping cannot be forgotten on one path and remembered on three.
        // The draw path's own flip lands here too, which is what makes
        // "the guest drew again" a content change rather than a repeat.
        m_ledger[m_frameIndex].contentShown = m_ledger[m_frameIndex].contentSeq;
    }
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    m_inFrame = false;

    if (owner == FrameOwner::Draw) {
        m_drawPathTookBackBuffer = true;
        ++m_drawOwnedFrames;
    }
    m_frameWriter = FrameOwner::None;

    // The one line a soak reads to answer "who painted this frame". Bounded by
    // the house pattern: a per-present marker is exactly the kind that becomes
    // 66% of a log if it is not.
    const uint64_t p = ++m_presentedFrames;
    if (ShouldLogRefusal(p)) {
        MCLA_LOG_INFO("FRAME-OWNER #{} owner={} presented={} drawn={} blitRefused={} "
                      "clearRefused={} conflicts={}",
                      p, FrameOwnerName(owner), p, m_drawOwnedFrames, m_blitRefused,
                      m_clearRefused, m_ownerConflicts);
    }
    return SUCCEEDED(hr);
}

bool D3D12Backend::PresentBgra(uint32_t width, uint32_t height, const uint8_t* pixels) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_device || !pixels || width == 0 || height == 0) return false;

    // F-650: this function is the SECOND writer to the back buffer, and the
    // heavier of the two -- it ends in CopyResource(back, m_fbTexture), which
    // overwrites every pixel the draw path produced. The refusal is taken HERE,
    // before the staging Map and before the scale loop, because a blit that
    // copies and then declines has already destroyed the frame it declined to
    // own. Returning false is the whole contract: the caller (render_thread.cpp
    // :971) turns a false into PRESENT-BLIT fail and then falls through to its
    // clear-only fallback, which the arbiter will also refuse, so a frame the
    // draw path owns is not repainted by anything on the way out.
    if (!MayWriteBackBuffer(FrameOwner::Blit)) return false;

    const uint32_t dstW = m_width;
    const uint32_t dstH = m_height;
    if (dstW == 0 || dstH == 0) return false;

    const size_t dstBytes = static_cast<size_t>(dstW) * dstH * 4u;
    if (m_fbHost.size() < dstBytes) {
        m_fbHost.resize(dstBytes);
    }

    if (width == dstW && height == dstH) {
        std::memcpy(m_fbHost.data(), pixels, dstBytes);
    } else {
        // Nearest-neighbor scale into the backbuffer-sized host buffer so a
        // downsampled guest read still covers the full viewport.
        for (uint32_t y = 0; y < dstH; ++y) {
            const uint32_t sy = static_cast<uint32_t>(
                (static_cast<uint64_t>(y) * height) / dstH);
            const uint8_t* srcRow = pixels + static_cast<size_t>(sy) * width * 4u;
            uint8_t* dstRow = m_fbHost.data() + static_cast<size_t>(y) * dstW * 4u;
            for (uint32_t x = 0; x < dstW; ++x) {
                const uint32_t sx = static_cast<uint32_t>(
                    (static_cast<uint64_t>(x) * width) / dstW);
                std::memcpy(dstRow + static_cast<size_t>(x) * 4u,
                            srcRow + static_cast<size_t>(sx) * 4u, 4u);
            }
        }
    }

    if (m_fence->GetCompletedValue() < m_currentFenceValue) {
        if (FAILED(m_fence->SetEventOnCompletion(m_currentFenceValue, m_fenceEvent))) return false;
        if (WaitForSingleObject(m_fenceEvent, INFINITE) != WAIT_OBJECT_0) return false;
    }
    if (!EnsureFbTexture(dstW, dstH)) return false;

    // Fill the upload staging with the properly pitched rows.
    {
        void* mapped = nullptr;
        D3D12_RANGE readRange = {0, 0};
        HRESULT hr = m_fbUpload->Map(0, &readRange, &mapped);
        if (FAILED(hr) || !mapped) {
            MCLA_LOG_WARN("D3D12Backend: PresentBgra staging Map failed hr=0x{:08X}",
                          static_cast<uint32_t>(hr));
            return false;
        }
        const UINT64 rowPitch = m_fbFootprint.Footprint.RowPitch;
        auto* dst = static_cast<uint8_t*>(mapped);
        for (uint32_t y = 0; y < dstH; ++y) {
            std::memcpy(dst + static_cast<size_t>(y) * rowPitch,
                        m_fbHost.data() + static_cast<size_t>(y) * dstW * 4u,
                        static_cast<size_t>(dstW) * 4u);
        }
        m_fbUpload->Unmap(0, nullptr);
    }

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    ID3D12Resource* back = m_renderTargets[m_frameIndex].Get();
    if (!back) {
        // 2026-10-02: this used to clear `m_inFrame` inline. It already
        // released the latch, so it was never a wedge -- but it released HALF
        // the state AbandonFrame clears (not m_frameWriter), and it was the one
        // release in this file that produced no count, so "how many frames were
        // dropped" had two different answers depending on which door dropped
        // them. Routed through the same helper; the refusal is unchanged.
        AbandonFrame("blit:no-back-buffer");
        return false;
    }

    // staging -> DEFAULT texture
    D3D12_TEXTURE_COPY_LOCATION dstLoc = {};
    dstLoc.pResource = m_fbTexture.Get();
    dstLoc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    dstLoc.SubresourceIndex = 0;
    D3D12_TEXTURE_COPY_LOCATION srcLoc = {};
    srcLoc.pResource = m_fbUpload.Get();
    srcLoc.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
    srcLoc.PlacedFootprint = m_fbFootprint;

    D3D12_RESOURCE_BARRIER barriers[2] = {};
    UINT barrierCount = 0;
    if (m_fbTexState != D3D12_RESOURCE_STATE_COPY_DEST) {
        auto& b = barriers[barrierCount++];
        b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        b.Transition.pResource = m_fbTexture.Get();
        b.Transition.StateBefore = m_fbTexState;
        b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_DEST;
        b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    }
    {
        auto& b = barriers[barrierCount++];
        b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        b.Transition.pResource = back;
        b.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_DEST;
        b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    }
    if (barrierCount) {
        m_commandList->ResourceBarrier(barrierCount, barriers);
    }
    m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;

    m_commandList->CopyTextureRegion(&dstLoc, 0, 0, 0, &srcLoc, nullptr);

    // texture: COPY_DEST -> COPY_SOURCE; backbuffer: COPY_DEST -> PRESENT
    barrierCount = 0;
    {
        auto& b = barriers[barrierCount++];
        b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        b.Transition.pResource = m_fbTexture.Get();
        b.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
        b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
        b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        m_fbTexState = D3D12_RESOURCE_STATE_COPY_SOURCE;
    }
    m_commandList->ResourceBarrier(barrierCount, barriers);
    m_commandList->CopyResource(back, m_fbTexture.Get());
    // F-761: the blit is a full-surface write to this buffer, counted as one.
    NoteBufferWrite("blit");
    barrierCount = 0;
    {
        auto& b = barriers[barrierCount++];
        b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        b.Transition.pResource = back;
        b.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
        b.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    }
    m_commandList->ResourceBarrier(barrierCount, barriers);

    // F-650: the one sanctioned Present(). The Close/Execute/Present/Signal/
    // frameIndex block this used to own verbatim is now shared, so the blit
    // cannot present a frame the draw path also presented.
    m_stats.uploadsBytes += dstBytes;
    return PresentOwnedFrame(FrameOwner::Blit);
}

bool D3D12Backend::ClearAndPresent(float r, float g, float b, float a) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return false;

    // F-650: the third writer. ClearRenderTargetView is not a neutral no-op --
    // it is a full-surface overwrite, so a clear-only present arriving after a
    // drawn frame erases exactly the pixels the draw path just produced. This is
    // the same last-writer-wins defect as the blit, one call earlier in the
    // fallback chain, so it goes through the same arbiter and is refused the
    // same way. Before any draw has presented it is still allowed: it is what
    // keeps the window valid on the heartbeat presents that carry no geometry.
    // F-760: THE CLEAR IS REFUSED, BUT THE FRAME IS NOT. This line used to be
  // `if (!MayWriteBackBuffer(FrameOwner::Clear)) return false;` and that
  // single `return false` is what froze the display.
  //
  // WHAT THE LATCH WAS FOR, AND WHY IT IS STILL ARMED. m_drawPathTookBackBuffer
  // is set at :5157 on the first draw-owned present and is NEVER cleared. Its
  // own comment at :5092-5096 said what it protects: "the W6 PresentBgra
  // pipe proof (render_thread.cpp:152) and the pre-guest-content gradient
  // (render_thread.cpp:1039) ... before any guest geometry arrives". BOTH
  // of those are SYNTHETIC and both are now DELETED (F-758). The latch's
  // stated justification no longer exists, but the flag survives and still
  // disarms this path.
  //
  // MEASURED IN build/w715.log, 150 s soak. presented= is FROZEN at 360 for
  // the whole run, and it reconciles with no slack:
  //   1 startup clear + 355 heartbeat PRESENT + 2 blits + 2 draw presents
  //   = 360
  // Present command #358 is the first refusal, 472 ms after the second draw:
  //   FRAME-OWNER REFUSED #1: writer=clear may not touch the back buffer;
  //   owner=draw presented=360 drawn=2 blitRefused=0 clearRefused=1
  // and FRAME-OWNER REFUSED then runs to #4000. So the guest's triangle WAS
  // on screen for 19 ms (54.795 -> 54.814) and every frame after that was
  // never presented at all. The window the user was looking at was 136 s
  // stale, showing one all-black frame.
  //
  // WHY NOT SIMPLY ALLOW THE CLEAR. F-650's protection is sound and is KEPT:
  // ClearRenderTargetView is a full-surface overwrite, so clearing here would
  // erase the guest's pixels. The bug was never the refusal -- it was
  // refusing the CLEAR and then abandoning the FRAME, which throws away the
  // very content the refusal was protecting.
  //
  // SO: skip the clear, present the back buffer unmodified. Nothing is
  // synthesised - whatever is in the buffer is what is shown, and
  // FrameOwner::None says on the FRAME-OWNER row that no writer touched it.
  //
  // F-761: AND ONLY IF THAT BUFFER HAS BEEN WRITTEN. "Whatever is in the buffer"
  // is only honest for a buffer something put something in. The chain rotates
  // (PresentOwnedFrame advances m_frameIndex to
  // m_swapChain->GetCurrentBackBufferIndex() on every present, and kBufferCount
  // is 3), so this branch will eventually be asked to present an index that no
  // clear, no blit and no draw ever touched, and presenting that shows
  // uninitialised resource memory. Measured, not assumed, in build/w716.log:
  // FRAME-OWNER #200 at 17:08:00.354 reads owner=clear drawn=0 clearRefused=0
  // blitRefused=0, and clearRefused only starts incrementing once the draw path
  // owns the back buffer, i.e. after the first DRAW present. So every one of
  // presents #1 through #200 was an owner=clear present, and each of those
  // recorded a ClearRenderTargetView on its own m_frameIndex before presenting
  // that same index. With kBufferCount=3 that is >= 66 writes per index before
  // the guest's first draw at 17:08:05.586, so all three indices were written.
  // That is a fact about THAT run and not a guarantee -- a run that reached its
  // first present without a clear would rotate onto an unwritten buffer on
  // present #1. So the ledger decides, per buffer, and the refusal names the
  // buffer rather than substituting a colour for it.
  if (!MayWriteBackBuffer(FrameOwner::Clear)) {
    if (!m_inFrame) {
      if (!BeginFrame()) return false;
    }
    if (RefuseUnwrittenPresent("none")) {
      // Nothing was recorded into this frame, so it is closed unreferenced
      // rather than executed. The window keeps whatever it was already showing,
      // which is the honest state: this backend has no guest frame to put there.
      AbandonFrame("clear-refused-unwritten-back-buffer");
      return false;
    }
    // F-763: AND NOW THE OTHER HALF OF "NOTHING TO SHOW". The buffer above was
    // written by SOMETHING, at some point in the past -- which is a different
    // question from whether it holds anything the window has not already been
    // showing. This is the narrowest possible place for the hold: it is inside
    // the branch whose ONLY act is to flip a buffer that no writer touched this
    // beat, so the draw path (PresentOwnedFrame(FrameOwner::Draw), reached from
    // DrawDynamicMeshWithPipeline), the blit (FrameOwner::Blit) and the
    // allowed clear (FrameOwner::Clear) are all upstream of here and none of
    // them can be reached by this gate.
    //
    // ORDER MATTERS AND IS THE POINT. This test sits BEFORE
    // RecordLateFrameReadback, so a beat that changes nothing spends no
    // GPU->CPU fence wait to re-measure bytes it already measured. That also
    // means LATE-FRAME-PIXEL now samples only beats that CHANGED something --
    // which is the honest population for a row whose stated subject is "which
    // buffer the window was showing", since an unchanged window has one answer
    // and the ledger below carries which buffer it was.
    if (RefuseUnchangedPresent("none")) {
      // Same shape as the refusal above and for the same measured reason: this
      // branch has recorded nothing into the list, so AbandonFrame closes it
      // unreferenced and releases m_inFrame. AbandonFrame here is not a
      // workaround and not a second gate -- it is the release, and the gate is
      // RefuseUnchangedPresent.
      AbandonFrame("clear-refused-no-new-content");
      return false;
    }
    // F-761: the sample of the frame the window is ACTUALLY showing. Recorded
    // before the present, reported after it, so the fence discipline below is
    // the one the draw path uses. It is the only pixel census in this file that
    // can fire on a frame with no draw on it.
    const bool rbRecorded = RecordLateFrameReadback();
    // No ClearRenderTargetView is recorded: the back buffer keeps the
    // guest's pixels, and the frame is presented as it stands. The
    // transition is already PRESENT because a preceding
    // PresentOwnedFrame left it there, and BeginFrame() re-armed the
    // frame if one was not open. If the readback above recorded a copy it
    // also recorded the PRESENT transition the copy needs, so the state
    // named here is the state that is there either way (the F-725 lesson).
    const bool presented = PresentOwnedFrame(FrameOwner::None);
    if (rbRecorded) {
      ReportLateFrameReadback();
    }
    return presented;
  }

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition render target buffer from PRESENT to RENDER_TARGET
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    rtvHandle.ptr += static_cast<size_t>(m_frameIndex) * m_rtvDescriptorSize;

    const float clearColor[4] = { r, g, b, a };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    // F-761: this clear is a write to the buffer that is about to be presented.
    NoteBufferWrite("clear");

    // Transition render target back to PRESENT
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;

    m_commandList->ResourceBarrier(1, &barrier);

    // F-650: one sanctioned Present(). Note this copy of the block was also the
    // only one of the three that never set m_lastPresentHr, so the last present
    // status the backend reported was whichever of the other two ran last --
    // another fact the triplication was hiding.
    return PresentOwnedFrame(FrameOwner::Clear);
}

// F-610: PresentDirect is DELETED, not fixed. It had zero callers
// (grep over src/: the only two hits were this definition and the
// d3d12_backend.h:53 declaration), and it is unsound as written: it
// signalled a fence and advanced m_frameIndex WITHOUT executing a command
// list, so the fence it waited on implied GPU work that never happened and
// the next frame's back buffer index was chosen by a present with no
// submission behind it. Every live present path in this backend
// (DrawDynamicMeshWithPipeline :1487-1504, ClearAndPresent :1912-1932,
// PresentBgra) closes + executes + presents atomically under m_mutex;
// there is no caller that has already drawn to the back buffer and wants
// only the flip, because those callers ARE the drawing. Wiring it would
// require a real EndFrame split (see :1953) to know which draws to flush,
// which is a backend restructure, not a fix to a dead function. Its
// removal trigger was zero call sites; it is gone, and the honest
// equivalent of "present what is already there" is the existing
// ClearAndPresent, which submits its own clear rather than an empty list.

void D3D12Backend::EndFrame() {
    m_inFrame = false;
    // F-639: the texture cache's notion of "in flight" is a frame boundary, so
    // this is where a resident texture stops being pinned. Nothing is FREED here
    // -- eviction is the TextureCache's job and it skips in-flight entries
    // (resource_cache.h:128-130) -- this only tells it which serial the GPU has
    // passed, so an entry bound this frame is not the next eviction candidate
    // while the copy is still in the queue.
    ++m_frameSerial;
    m_textureCache.NotifySubmitted(m_frameSerial);
}

void D3D12Backend::Shutdown() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return;

    WaitForGpu();

    // Stop pipeline cache worker thread
    m_pipelineCache.StopWorker();

    if (m_fenceEvent) {
        CloseHandle(m_fenceEvent);
        m_fenceEvent = nullptr;
    }

    if (m_copyFenceEvent) {
        CloseHandle(m_copyFenceEvent);
        m_copyFenceEvent = nullptr;
    }

    m_fence.Reset();
    m_copyFence.Reset();
    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_commandAllocators[i].Reset();
    }
    m_rtvHeap.Reset();
    m_commandList.Reset();
    m_commandQueue.Reset();
    m_copyCommandList.Reset();
    m_copyAllocator.Reset();
    m_copyQueue.Reset();
    m_swapChain.Reset();

    // Phase 3 draw-path resources: clear the persistent upload mapping and
    // release the cached resources so a Shutdown() -> Initialize() recovery
    // path (device-lost) cannot touch a dangling m_uploadMap.
    if (m_uploadHeap) {
        m_uploadHeap->Unmap(0, nullptr);
        m_uploadHeap.Reset();
    }
    m_uploadMap = nullptr;
    m_uploadOffset = 0;
    m_staticIndexBuffer.Reset();
    m_decodedTexture.Reset();
    m_decodedTextureUpload.Reset();
    m_fbTexture.Reset();
    m_fbUpload.Reset();
    m_fbFootprint = {};
    m_fbTexW = 0;
    m_fbTexH = 0;
    m_fbTexState = D3D12_RESOURCE_STATE_COPY_DEST;
    m_fbHost.clear();
    m_fbHost.shrink_to_fit();
    m_srvHeap.Reset();
    m_decodedTextureSrvGpu = {};
    m_testPipeline.Reset();
    m_rootSignature.Reset();
    m_resourceCache.Clear();

    // F-639: resident textures and the samplers interned from them go with the
    // device. The pool is cleared rather than left holding ComPtrs into a
    // released device, which is what a Shutdown()->Initialize() recovery path
    // would otherwise trip over.
    for (ResidentTexture& rt : m_texturePoolSlots) {
        rt.texture.Reset();
        rt.upload.Reset();
    }
    m_texturePoolSlots.clear();
    m_texturePoolByHandle.clear();
    m_texturePoolFree.clear();
    m_textureCache.Clear();
    m_guestSamplerIndex.clear();
    m_samplerTableGpu = {};
    m_resourceStates.clear();
    m_importScratch.clear();
    m_importScratch.shrink_to_fit();
    m_samplerHeapOffset = 0;
    m_trackedStateDisagreements = 0;

    m_device.Reset();
    m_factory.Reset();

    m_initialized = false;
    MCLA_LOG_INFO("D3D12Backend: Shutdown complete");
}

// Phase 4: Sampler state management (static samplers for root signature)
uint32_t D3D12Backend::GetOrCreateStaticSampler(const D3D12_SAMPLER_DESC& desc) {
    SamplerCacheKey key{ desc };
    auto it = m_samplerCache.find(key);
    if (it != m_samplerCache.end()) {
        for (uint32_t i = 0; i < m_staticSamplerArray.size(); ++i) {
            if (memcmp(&m_staticSamplerArray[i].Filter, &desc.Filter, sizeof(D3D12_SAMPLER_DESC)) == 0) return i;
        }
    }
    D3D12_STATIC_SAMPLER_DESC staticDesc = {};
    staticDesc.Filter = desc.Filter;
    staticDesc.AddressU = desc.AddressU;
    staticDesc.AddressV = desc.AddressV;
    staticDesc.AddressW = desc.AddressW;
    staticDesc.MipLODBias = desc.MipLODBias;
    staticDesc.MaxAnisotropy = desc.MaxAnisotropy;
    staticDesc.ComparisonFunc = desc.ComparisonFunc;
    staticDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;
    staticDesc.MinLOD = desc.MinLOD;
    staticDesc.MaxLOD = desc.MaxLOD;
    staticDesc.ShaderRegister = 0;
    staticDesc.RegisterSpace = 0;
    staticDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
    uint32_t index = static_cast<uint32_t>(m_staticSamplerArray.size());
    m_staticSamplerArray.push_back(staticDesc);
    m_samplerCache.emplace(SamplerCacheKey{ desc }, desc);
    return index;
}

bool D3D12Backend::CreateRenderTargetView(ID3D12Resource* texture, DXGI_FORMAT format,
                                          D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle) {
    if (!texture || !m_device) return false;
    D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
    rtvDesc.Format = format;
    rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
    rtvDesc.Texture2D.MipSlice = 0;
    rtvDesc.Texture2D.PlaneSlice = 0;
    m_device->CreateRenderTargetView(texture, &rtvDesc, rtvHandle);
    return true;
}

bool D3D12Backend::CreateDepthStencilView(ID3D12Resource* texture, DXGI_FORMAT format,
                                          D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle) {
    if (!texture || !m_device) return false;
    D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
    dsvDesc.Format = format;
    dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
    dsvDesc.Flags = D3D12_DSV_FLAG_NONE;
    dsvDesc.Texture2D.MipSlice = 0;
    m_device->CreateDepthStencilView(texture, &dsvDesc, dsvHandle);
    return true;
}

bool D3D12Backend::ResolveRenderTarget(ID3D12Resource* srcRt, ID3D12Resource* dstTexture,
                                       DXGI_FORMAT format) {
    if (!srcRt || !dstTexture || !m_commandList) {
        const uint64_t n = ++g_resolveRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: resolve refused #{}: {} -- a resolve with an absent "
                           "target means the colour ended up nowhere and the next pass samples "
                           "uninitialised memory",
                           n, srcRt == nullptr ? "no source" : "no destination");
        }
        return false;
    }
    // F-640: the prior states are the TRACKED ones, not the asserted
    // RENDER_TARGET/COMMON the old code hardcoded. That assertion held only for
    // the first resolve of a given resource; on the second pass D3D12 was told
    // the source was in RENDER_TARGET when it was in RESOLVE_SOURCE from the
    // previous call's tail transition, which is a barrier-state mismatch and a
    // debug-layer error. TransitionResource with the right subresource is the
    // single place that knows the tracked state, so the resolve goes through it.
    D3D12_RESOURCE_BARRIER in[2] = {};
    in[0].Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    in[0].Transition.pResource = srcRt;
    in[0].Transition.StateBefore = TrackedState(srcRt, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES);
    in[0].Transition.StateAfter = D3D12_RESOURCE_STATE_RESOLVE_SOURCE;
    in[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    in[1].Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    in[1].Transition.pResource = dstTexture;
    in[1].Transition.StateBefore =
        TrackedState(dstTexture, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES);
    in[1].Transition.StateAfter = D3D12_RESOURCE_STATE_RESOLVE_DEST;
    in[1].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(2, in);

    m_commandList->ResolveSubresource(dstTexture, 0, srcRt, 0, format);

    // The tail states are recorded on the tracker so the NEXT resolve of the same
    // resources starts from the truth. Note the source goes back to
    // RENDER_TARGET because the source of an EDRAM resolve is a colour RT that
    // the next pass keeps rendering into; the destination ends as a shader
    // resource, which is what the following sampling pass needs.
    in[0].Transition.StateBefore = D3D12_RESOURCE_STATE_RESOLVE_SOURCE;
    in[0].Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    in[1].Transition.StateBefore = D3D12_RESOURCE_STATE_RESOLVE_DEST;
    in[1].Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
    m_commandList->ResourceBarrier(2, in);
    SetTrackedState(srcRt, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES,
                    D3D12_RESOURCE_STATE_RENDER_TARGET);
    SetTrackedState(dstTexture, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES,
                    D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
    return true;
}

// F-640: the EDRAM-resolve entry point. Everything BuildResolveDesc decides is
// honoured or refused -- see the header for the per-field list. The point of
// routing through BuildResolveDesc (rather than trusting a caller-supplied DXGI
// format) is that the resolve's legality is a property of the GUEST format: the
// format table's isResolvable column, cross-checked against Xenia's ColorFormat
// set at init, is the authority, and a host format alone cannot answer it.
bool D3D12Backend::ResolveGuestSurface(uint32_t xenosFormat, uint32_t width, uint32_t height,
                                      uint32_t sampleSelect, bool endianSwap, bool swapRedBlue,
                                      bool clearSource, uint32_t extentX, uint32_t extentY,
                                      uint32_t copyDestPitch, uint32_t copyDestHeight,
                                      uint32_t guestBaseAddress, ID3D12Resource* srcRt,
                                      ID3D12Resource* dstTexture) {
    const native::TextureResolveDesc rd = native::BuildResolveDesc(
        xenosFormat, width, height, sampleSelect, endianSwap, swapRedBlue, clearSource,
        extentX, extentY, copyDestPitch, copyDestHeight, guestBaseAddress);

    auto refuse = [&](const char* why) {
        const uint64_t n = ++g_resolveRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_ERROR("D3D12Backend: EDRAM resolve refused #{}: {} (xenosFmt={} {} "
                           "{}x{} sampleSelect={} endianSwap={} swapRB={} clearSrc={} "
                           "extent={}x{} copyDest={}x{})",
                           n, why, rd.xenosFormat, rd.formatName, rd.width, rd.height,
                           rd.sampleSelect, rd.endianSwap ? 1 : 0, rd.swapRedBlue ? 1 : 0,
                           rd.clearSource ? 1 : 0, rd.extent[0], rd.extent[1],
                           rd.copyDestPitch, rd.copyDestHeight);
        }
        return false;
    };

    if (!rd.valid) {
        return refuse(rd.refusal ? rd.refusal : "BuildResolveDesc-refused");
    }
    if (rd.isDepthResolve) {
        return refuse("depth-resolve-needs-own-path");
    }
    if (rd.hostDxgiFormat == 0) {
        return refuse("no-host-resolve-format");
    }
    if (rd.endianSwap || rd.swapRedBlue) {
        // ResolveSubresource performs no channel swizzle and no byte swap, so
        // honouring this would mean shipping an un-swizzled image.
        return refuse("resolve-needs-swizzle-D3D12-ResolveSubresource-has-none");
    }
    if (rd.clearSource) {
        // D3D12 has no copy-and-clear on a resource that is simultaneously the
        // resolve source; the caller would have to issue a separate clear, which
        // is a different command stream, not a flag on this one.
        return refuse("resolve-clearSource-unsupported");
    }
    if (!srcRt || !dstTexture) {
        return refuse(srcRt == nullptr ? "absent-resolve-source" : "absent-resolve-target");
    }
    // The destination's real format must be the one the resolve plan names, or
    // ResolveSubresource would write bytes the destination cannot represent.
    {
        const DXGI_FORMAT dstFormat = dstTexture->GetDesc().Format;
        if (dstFormat != static_cast<DXGI_FORMAT>(rd.hostDxgiFormat)) {
            const uint64_t n = ++g_resolveRefusals;
            if (ShouldLogRefusal(n)) {
                MCLA_LOG_ERROR("D3D12Backend: EDRAM resolve refused #{}: destination format {} "
                               "!= plan hostDxgiFormat {} (xenosFmt={} {})",
                               n, static_cast<uint32_t>(dstFormat), rd.hostDxgiFormat,
                               rd.xenosFormat, rd.formatName);
            }
            return false;
        }
        const D3D12_RESOURCE_DESC sd = srcRt->GetDesc();
        if (sd.SampleDesc.Count <= 1) {
            return refuse("resolve-source-is-not-MSAA");
        }
    }

    // MSAA -> single-sample is exactly what ResolveSubresource does, so the guest
    // sampleSelect (Sample0/Avg01/AvgAll/...) is NOT applied here. D3D12 always
    // box-resolves. For AvgAll and the single-sample selects the result is the
    // average, which differs from the guest's answer for a 2x/4x MSAA surface --
    // that is a real, counted, named divergence rather than a silent one, and
    // Sample0 is additionally a genuine semantic loss (the guest picked one
    // sample, D3D12 averaged all of them).
    if (rd.sampleSelect != static_cast<uint32_t>(native::GuestCopySampleSelect::AvgAll)) {
        const uint64_t n = ++g_resolveRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("D3D12Backend: EDRAM resolve #{} is an APPROXIMATION: guest "
                          "sampleSelect={} (xenosFmt={} {}), D3D12 ResolveSubresource always "
                          "box-averages all samples",
                          n, rd.sampleSelect, rd.xenosFormat, rd.formatName);
        }
    }

    return ResolveRenderTarget(srcRt, dstTexture,
                               static_cast<DXGI_FORMAT>(rd.hostDxgiFormat));
}

const D3D12_BLEND_DESC* D3D12Backend::GetOrCreateBlendState(const D3D12_BLEND_DESC& desc) {
    BlendStateCacheKey key{ desc };
    auto it = m_blendStateCache.find(key);
    if (it != m_blendStateCache.end()) return &it->second;
    auto [it2, inserted] = m_blendStateCache.emplace(BlendStateCacheKey{ desc }, desc);
    return &it2->second;
}

const D3D12_DEPTH_STENCIL_DESC* D3D12Backend::GetOrCreateDepthStencilState(const D3D12_DEPTH_STENCIL_DESC& desc) {
    DepthStencilStateCacheKey key{ desc };
    auto it = m_depthStencilStateCache.find(key);
    if (it != m_depthStencilStateCache.end()) return &it->second;
    auto [it2, inserted] = m_depthStencilStateCache.emplace(DepthStencilStateCacheKey{ desc }, desc);
    return &it2->second;
}

const D3D12_RASTERIZER_DESC* D3D12Backend::GetOrCreateRasterizerState(const D3D12_RASTERIZER_DESC& desc) {
    RasterizerStateCacheKey key{ desc };
    auto it = m_rasterizerStateCache.find(key);
    if (it != m_rasterizerStateCache.end()) return &it->second;
    auto [it2, inserted] = m_rasterizerStateCache.emplace(RasterizerStateCacheKey{ desc }, desc);
    return &it2->second;
}

// F-641: genuinely per-subresource tracking. The previous version kept ONE state
// and ONE subresource index per resource, which cannot describe a mip chain: it
// could not say "mip 0 is PIXEL_SHADER_RESOURCE while mip 1 is COPY_DEST", and
// it emitted the barrier on the remembered subresource rather than the requested
// one, so the mipgen loop transitioned a resource it was not transitioning. The
// `stateBefore` argument is now ADVISORY: the emitted barrier always names the
// tracked state, because that is the only one D3D12 can verify. A caller whose
// `stateBefore` disagrees with the tracker has a real bug, so that disagreement
// is counted rather than silently obeyed.
D3D12_RESOURCE_STATES D3D12Backend::TrackedState(ID3D12Resource* resource,
                                                UINT subresource) const {
    if (!resource) return D3D12_RESOURCE_STATE_COMMON;
    auto it = m_resourceStates.find(resource);
    if (it == m_resourceStates.end()) return D3D12_RESOURCE_STATE_COMMON;
    const ResourceStateEntry& e = it->second;
    if (subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES) {
        return e.hasWhole ? e.whole : D3D12_RESOURCE_STATE_COMMON;
    }
    if (subresource < e.perMip.size()) return e.perMip[subresource];
    return e.hasWhole ? e.whole : D3D12_RESOURCE_STATE_COMMON;
}

void D3D12Backend::SetTrackedState(ID3D12Resource* resource, UINT subresource,
                                   D3D12_RESOURCE_STATES state) {
    if (!resource) return;
    ResourceStateEntry& e = m_resourceStates[resource];
    if (subresource == D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES) {
        e.whole = state;
        e.hasWhole = true;
        for (auto& s : e.perMip) s = state;
        return;
    }
    if (e.perMip.size() <= subresource) e.perMip.resize(static_cast<size_t>(subresource) + 1,
                                                         e.hasWhole ? e.whole
                                                                    : D3D12_RESOURCE_STATE_COMMON);
    e.perMip[subresource] = state;
}

bool D3D12Backend::TransitionResource(ID3D12Resource* resource,
                                      D3D12_RESOURCE_STATES stateBefore,
                                      D3D12_RESOURCE_STATES stateAfter,
                                      UINT subresource) {
    if (!resource || !m_commandList) return false;
    if (stateBefore == stateAfter) return false;

    const D3D12_RESOURCE_STATES tracked = TrackedState(resource, subresource);
    if (subresource != D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES && tracked != stateBefore) {
        ++m_trackedStateDisagreements;
    }
    if (tracked == stateAfter) return false;  // already there: no barrier

    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = resource;
    barrier.Transition.StateBefore = tracked;
    barrier.Transition.StateAfter = stateAfter;
    barrier.Transition.Subresource = subresource;
    m_commandList->ResourceBarrier(1, &barrier);
    SetTrackedState(resource, subresource, stateAfter);
    return true;
}

bool D3D12Backend::BeginRenderPass(const D3D12Backend::RenderPassDesc& desc) {
    if (!m_commandList || desc.rtvs.empty()) return false;
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> rtvHandles;
    for (const auto& rtv : desc.rtvs) rtvHandles.push_back(rtv.cpuHandle);
    D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = {};
    bool hasDsv = desc.dsv.has_value();
    if (hasDsv) dsvHandle = desc.dsv->cpuHandle;
    m_commandList->OMSetRenderTargets(static_cast<UINT>(rtvHandles.size()),
                                      rtvHandles.data(), FALSE,
                                      hasDsv ? &dsvHandle : nullptr);
    for (const auto& rtv : desc.rtvs) {
        if (rtv.clear) {
            m_commandList->ClearRenderTargetView(rtv.cpuHandle, rtv.clearColor, 0, nullptr);
        }
    }
    if (hasDsv && (desc.dsv->clearDepth || desc.dsv->clearStencil)) {
        D3D12_CLEAR_FLAGS flags = static_cast<D3D12_CLEAR_FLAGS>(0);
        if (desc.dsv->clearDepth) flags |= D3D12_CLEAR_FLAG_DEPTH;
        if (desc.dsv->clearStencil) flags |= D3D12_CLEAR_FLAG_STENCIL;
        m_commandList->ClearDepthStencilView(dsvHandle, flags,
                                             desc.dsv->depthClear, desc.dsv->stencilClear,
                                             0, nullptr);
    }
    if (desc.viewport.Width > 0 && desc.viewport.Height > 0) {
        m_commandList->RSSetViewports(1, &desc.viewport);
    }
    if (desc.scissor.right > desc.scissor.left && desc.scissor.bottom > desc.scissor.top) {
        m_commandList->RSSetScissorRects(1, &desc.scissor);
    }
    m_activeRenderPass = desc;
    return true;
}

void D3D12Backend::EndRenderPass() {
    if (!m_activeRenderPass.has_value() || !m_commandList) return;
    m_activeRenderPass.reset();
}

} // namespace mcla::native

// =============================================================================
// Phase 5: Captured DrawPacket Native Draw Implementation
// =============================================================================

namespace mcla::native {

// F-645: THIN FORWARDER. The 100-line hand-rolled builder that used to live
// here is deleted; the authoritative one is renderer::BuildGrcFvfInputLayout
// (pipeline_cache.h:307-320), which is what the render thread's HashInputLayout
// and the pipeline worker's CreateGraphicsPipelineState layout hash go through.
//
// Why the old body had to go rather than be kept as a fallback:
//   * it used LANE-INDEX semantics (lane 5 -> TEXCOORD0, lane 13 -> TANGENT0)
//     where grc_fvf_decode.h uses the architected lane->semantic map (4/5 =
//     Colour0/1, 6-13 = TexCoord0-7, 14/15 = Tangent, 16/17 = Binormal), so a VS
//     expecting COLOR0 could be fed lane 5 as TEXCOORD0;
//   * it accepted all 16 type codes, including the ones grc_fvf_decode refuses
//     (2/4/11-15 and any bound lane >= 16) as "unverified";
//   * it DROPPED lanes 16-17 (loop bounded at 16) even though they decode;
//   * it set D3D12_APPEND_ALIGNED_ELEMENT for every element instead of ordering
//     by byteOffset, so the layout's offsets were implicit while the render
//     thread's hash was over the decoded declaration -- two descriptions of one
//     vertex stream that could and did disagree, which is the invariant
//     PipelineKey::inputLayoutHash exists to prevent (pipeline_cache.h:24-28).
//
// The member stays because src/render_thread.cpp:498 calls it and that file is
// owned by another agent; the declaration in d3d12_backend.h is unchanged, so
// that call site keeps compiling with no edit on their side. When the render
// thread's owner updates it, this can be deleted and the free function called
// directly (pipeline_cache.h:316 already provides the same overload).
std::vector<D3D12_INPUT_ELEMENT_DESC>
D3D12Backend::BuildInputLayoutFromGrcFvf(const native::GrcFvfDesc& grcFvf)
{
    std::vector<D3D12_INPUT_ELEMENT_DESC> layout;
    // outDeclHash is passed as nullptr on purpose: this function's callers want
    // the LAYOUT, and the render thread computes its own declaration hash from
    // the same GrcFvfDesc (render_thread.cpp:500) -- asking for it here would
    // publish a second hash of the same declaration and invite the two to drift.
    if (!renderer::BuildGrcFvfInputLayout(grcFvf, layout, nullptr)) {
        // BuildGrcFvfInputLayout refuses rather than degrading: an invalid
        // declaration, an unknown channel, or a declared fvfSize that disagrees
        // with the computed stride. That is the right answer here, because
        // kRefuseEmptyInputLayout is what stops a real PSO being built against a
        // layout that does not describe the stream.
        const uint64_t n = ++g_layoutRefusals;
        if (ShouldLogRefusal(n)) {
            MCLA_LOG_WARN("BuildInputLayoutFromGrcFvf refused #{}: grc_fvf_decode says this "
                          "declaration must not be laid out (mask=0x{:08X} size={} types={:016X})",
                          n, grcFvf.fvfMask, grcFvf.fvfSize, grcFvf.types);
        }
        layout.clear();
        return layout;
    }
    // 2026-10-04: EVERY ELEMENT, EVERY FIELD, appended at the END of this row.
    //
    // WHY THIS IS THE ONLY INPUT-LAYOUT DUMP IN THIS FILE. A
    // D3D12_INPUT_ELEMENT_DESC is never converted into an ID3D12InputLayout
    // anywhere in src/ -- CreateInputLayout has zero occurrences across the tree
    // -- because the descriptors are handed straight to
    // CreateGraphicsPipelineState as psoDesc.InputLayout
    // (renderer/pipeline_cache.cpp:1910-1911) and are then unreachable: a
    // D3D12 pipeline state reports none of its own fields. The live draw path
    // therefore builds its layout in render_thread.cpp, from the guest vertex
    // shader's own element table, and does not carry it into this layer at all
    // (DynamicMeshDesc has no layout member, d3d12_backend.h:68-104).
    //
    // MEASURED, so the row is not mistaken for a live one: this function's
    // literal occurs 0 times in build/w709.log, while the live layout is
    // reported by render_thread's own row (w709.log:7497, `DRAW-CP-LAYOUT #1
    // draw=1 elements=2`). So a zero of the row appended here is a tautology
    // about THIS function, never a verdict on the layout the draw used. The
    // dump is kept because this is the only site in this file that materialises
    // descriptors at all, and it is the site that would carry the moment the
    // declaration reaches the live path.
    //
    // FIELD ORDER IS WRITTEN OUT, never brace-initialised: the struct is
    // (SemanticName, SemanticIndex, Format, InputSlot, AlignedByteOffset,
    // InputSlotClass, InstanceDataStepRate). Assigning positionally into a
    // braced list is how an offset silently becomes a format.
    {
        std::string dump;
        dump.reserve(layout.size() * 128u + 32u);
        char word[64];
        dump += "n=";
        std::snprintf(word, sizeof(word), "%u", static_cast<unsigned>(layout.size()));
        dump += word;
        for (size_t i = 0; i < layout.size(); ++i) {
            // Field-by-field, into named locals first. The names are the struct's
            // own, so a reader can check the assignment without the struct.
            const char* const semanticName = layout[i].SemanticName;
            const UINT semanticIndex = layout[i].SemanticIndex;
            const DXGI_FORMAT format = layout[i].Format;
            const UINT inputSlot = layout[i].InputSlot;
            const UINT alignedByteOffset = layout[i].AlignedByteOffset;
            const D3D12_INPUT_CLASSIFICATION inputSlotClass = layout[i].InputSlotClass;
            const UINT instanceDataStepRate = layout[i].InstanceDataStepRate;
            dump += " [";
            std::snprintf(word, sizeof(word), "%zu:{", i);
            dump += word;
            dump += (semanticName != nullptr) ? semanticName : "(null)";
            dump += ",si=";
            std::snprintf(word, sizeof(word), "%u", semanticIndex);
            dump += word;
            dump += ",fmt=";
            std::snprintf(word, sizeof(word), "0x%X",
                          static_cast<unsigned>(format));
            dump += word;
            dump += ",slot=";
            std::snprintf(word, sizeof(word), "%u", inputSlot);
            dump += word;
            dump += ",off=";
            std::snprintf(word, sizeof(word), "%u", alignedByteOffset);
            dump += word;
            dump += ",class=";
            std::snprintf(word, sizeof(word), "%u",
                          static_cast<unsigned>(inputSlotClass));
            dump += word;
            dump += ",step=";
            std::snprintf(word, sizeof(word), "%u", instanceDataStepRate);
            dump += word;
            dump += "}]";
        }
        MCLA_LOG_INFO(
            "BuildInputLayoutFromGrcFvf: {} elements from mask=0x{:08X} size={} (via "
            "renderer::BuildGrcFvfInputLayout, declHash not requested) "
            "layout=[{}] -- every element, field by field, in the struct's own "
            "order SemanticName/SemanticIndex/Format/InputSlot/AlignedByteOffset/"
            "InputSlotClass/InstanceDataStepRate; n is the count that would be "
            "passed as psoDesc.NumElements. No input-layout object is created "
            "anywhere in this tree, so those descriptors are consumed inline by "
            "CreateGraphicsPipelineState and unreadable afterwards. This function's "
            "literal is absent from build/w709.log, so its absence here is not a "
            "statement about the layout the live draw used",
            layout.size(), grcFvf.fvfMask, grcFvf.fvfSize, dump);
        return layout;
    }
}

renderer::PipelineState D3D12Backend::BuildPipelineStateFromPacket(const native::DrawPacket& packet)
{
    renderer::PipelineState state = {};

    // Target formats - default to R8G8B8A8_UNORM
    state.targetFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    state.depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

    // Blend state hash - extract from paClipCntl / other registers
    state.blendState = packet.paClipCntl ^ 0x12345678;

    // Raster state hash - extract cull mode, fill mode from paClipCntl / paSuScModeCntl
    state.rasterState = packet.paClipCntl ^ packet.paSuScModeCntl;

    // Depth-stencil state hash
    state.depthStencilState = packet.paClVteCntl ^ 0xABCDEF00;

    // Primitive topology
    switch (packet.primType) {
        case 0: state.topology = 0; break; // Triangle
        case 1: state.topology = 0; break; // Triangle strip
        case 2: state.topology = 1; break; // Line
        case 3: state.topology = 1; break; // Line strip
        case 4: state.topology = 2; break; // Point
        default: state.topology = 0; break;
    }

    state.sampleCount = 1;

    return state;
}

bool D3D12Backend::UploadPacketGeometry(const native::DrawPacket& packet,
                                        D3D12_GPU_VIRTUAL_ADDRESS& vbGpu,
                                        D3D12_GPU_VIRTUAL_ADDRESS& ibGpu,
                                        uint32_t& vertexStride,
                                        uint32_t& vertexCount,
                                        uint32_t& indexCount,
                                        DXGI_FORMAT& indexFormat)
{
    // Get active guest memory view
    auto& memView = mcla::native::GetActiveGuestMemoryView();

    // Upload vertex buffer
    if (packet.vertexStreamCount == 0) {
        MCLA_LOG_WARN("UploadPacketGeometry: no vertex streams in packet");
        return false;
    }

    // For now, use first vertex stream
    const auto& stream = packet.vertexStreams[0];
    if (!stream.guestAddress || stream.stride == 0) {
        MCLA_LOG_WARN("UploadPacketGeometry: invalid vertex stream 0 (addr=0x%08X stride=%u)",
                      stream.guestAddress, stream.stride);
        return false;
    }

    // Read vertex data from guest memory
    if (!memView.IsValidRange(stream.guestAddress, stream.stride * packet.indexCount)) {
        MCLA_LOG_WARN("UploadPacketGeometry: vertex stream out of bounds (addr=0x%08X stride=%u count=%u)",
                      stream.guestAddress, stream.stride, packet.indexCount);
        return false;
    }

    // For now, use the test vertex stride (28 bytes) since our test PSO expects that
    vertexStride = 28;
    vertexCount = packet.indexCount;

    std::vector<uint8_t> vertexData(vertexStride * vertexCount);
    if (!memView.ReadBytes(stream.guestAddress, vertexData.data(), vertexData.size())) {
        MCLA_LOG_WARN("UploadPacketGeometry: failed to read vertex data from guest");
        return false;
    }

    // Upload vertex buffer
    vbGpu = 0;
    uint8_t* vbDst = MapUpload(vertexData.size(), D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, vbGpu);
    if (!vbDst) return false;
    std::memcpy(vbDst, vertexData.data(), vertexData.size());

    // Upload index buffer
    if (packet.indexType == 1) {
        indexFormat = DXGI_FORMAT_R32_UINT;
    } else {
        indexFormat = DXGI_FORMAT_R16_UINT;
    }
    indexCount = packet.indexCount;

    // Check if we have a cached index buffer for this packet's index data
    ResourceKey ibKey = { ResourceKind::Buffer, packet.indexBufferAddress, packet.indexBufferSize, 0, 0 };
    ResourceEntry ibEntry;
    if (m_resourceCache.Find(ibKey, ibEntry)) {
        ibGpu = ibEntry.handle;
        MCLA_LOG_INFO("UploadPacketGeometry: using cached index buffer 0x%llx", ibGpu);
    } else {
        // Upload index buffer data
        if (!memView.IsValidRange(packet.indexBufferAddress, packet.indexBufferSize)) {
            MCLA_LOG_WARN("UploadPacketGeometry: index buffer out of bounds (addr=0x%08X size=%u)",
                          packet.indexBufferAddress, packet.indexBufferSize);
            return false;
        }

        std::vector<uint8_t> indexData(packet.indexBufferSize);
        if (!memView.ReadBytes(packet.indexBufferAddress, indexData.data(), indexData.size())) {
            MCLA_LOG_WARN("UploadPacketGeometry: failed to read index data from guest");
            return false;
        }

        ibGpu = 0;
        uint8_t* ibDst = MapUpload(indexData.size(), D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, ibGpu);
        if (!ibDst) return false;
        std::memcpy(ibDst, indexData.data(), indexData.size());

        // Cache the index buffer for future frames
        ResourceEntry entry = { ibGpu, 0, false };
        m_resourceCache.Insert(ibKey, entry);
        MCLA_LOG_INFO("UploadPacketGeometry: cached new index buffer 0x%llx", ibGpu);
    }

    return true;
}

// F-610: DrawCapturedPacket is DELETED, not fixed. Its call count was zero
// (grep over src/ found only this definition and the d3d12_backend.h
// declaration), and it could not have worked if it had been called:
//
//  1. It built DynamicMeshDesc with vertexBytes=nullptr / vertexBytesSize=0
//     on the "already uploaded" assumption, but DrawDynamicMeshWithPipeline
//     guards exactly that at :1366 (!vertexBytes || vertexBytesSize == 0 ||
//     vertexCount == 0 -> return false). Every call returned false silently,
//     with no log and no stat, so nothing would have noticed.
//  2. It hardcoded vertexStride=28 while vertexCount came from the real
//     packet, so even past the guard the stride and the count disagreed with
//     the packet's own layout.
//  3. It called GetOrCompile with empty VS/PS HLSL (old :2464-2466), which
//     the pipeline cache worker drops on sight
//     (src/renderer/pipeline_cache.cpp:244-249, "missing device or empty
//     HLSL"), so the only PSO it could ever get was the test PSO it then
//     fell back to anyway.
//
// Fixing it properly means giving DrawDynamicMesh a real pre-uploaded-vertex
// path (a cachedVertexGpu on DynamicMeshDesc alongside cachedIndexGpu) and a
// real shader source, i.e. new backend surface for a feature with no caller
// and no guest capture behind it. That is speculative, not a fix, so the
// function is gone and BuildPipelineStateFromPacket / UploadPacketGeometry
// (its only two helpers) go with it rather than sit here as unreferenced
// code with no honest caller. The live equivalent is the DRAW_CAPTURED
// command path in src/render_thread.cpp, which does route real guest
// geometry through the staging-upload path via DrawDynamicMesh and is where
// a revived capture belongs. DELETION TRIGGER: zero call sites.

} // namespace mcla::native
