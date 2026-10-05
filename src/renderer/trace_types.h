#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace mcla::native {

// Magic identifier for MCLA trace streams ('MCLA' in ASCII / 0x414C434D)
constexpr uint32_t kTraceMagic = 0x414C434D;
// v2 adds the captured grcFvf vertex declaration to DrawPacket (packetSize
// guard). v1 traces are rejected by the reader (version mismatch).
constexpr uint32_t kTraceVersion = 2;

#pragma pack(push, 1)

// POD header for trace files
struct TraceHeader {
    uint32_t magic;            // Must be kTraceMagic
    uint32_t version;          // Must be kTraceVersion
    uint32_t headerSize;       // sizeof(TraceHeader)
    uint32_t packetSize;       // sizeof(DrawPacket)
    uint32_t packetCount;      // Number of DrawPackets in the stream
    uint32_t reserved;         // Padding / alignment
    uint64_t buildHash;        // Build configuration / commit hash identifier
    uint64_t startTimestamp;   // CPU timestamp at start of trace
};

struct VertexStreamDesc {
    uint32_t guestAddress;     // Guest base pointer for vertex data
    uint32_t stride;           // Element stride in bytes
    uint32_t offset;           // Offset within stream
    uint32_t format;           // Format/type descriptor
};

// Captured RAGE drawable vertex declaration (grcFvf), 16 bytes from the guest
// drawable descriptor:
//   +0 u32 fvfMask       bit i set = semantic lane i is bound
//   +4 u8  fvfSize       declared vertex stride in bytes
//   +5 u8  flags
//   +6 u8  dynamicOrder
//   +7 u8  channelCount   count of set mask bits (informational)
//   +8 u64 channelTypes   16 x 4-bit type codes, lane i at bits [i*4..i*4+3]
//
// ENDIANNESS: the guest block is big-endian; the capture site must convert
// with ReadU32BE (fvfMask) and ReadU64BE (channelTypes) BEFORE storing, so
// the fields here are plain host-endian numeric values. The decoder assumes
// exactly that layout (lane i at bits [i*4..i*4+3] of `types`). Lanes 16/17
// (Binormal0/1) have no type bits in the u64 and decode as unknown.
//
// Zero-valued when no live drawable capture provided the descriptor
// (DrawPacket.hasGrcFvf == 0). Decoded by grc_fvf_decode.
// No default member initializers: the struct must stay a trivial POD so
// DrawPacket remains trivially copyable (trace file I/O, value-init {} zeros
// any unwritten fields).
struct GrcFvfDesc {
    uint32_t fvfMask;
    uint8_t fvfSize;
    uint8_t flags;
    uint8_t dynamicOrder;
    uint8_t channelCount;
    uint64_t types;
};

// POD DrawPacket representing a complete, self-contained draw call
struct DrawPacket {
    // ── Frame Identity ──────────────────────────────────────────────────────
    uint64_t frameIndex;       // Global frame counter
    uint32_t sequenceNum;      // Draw sequence number within process lifetime
    uint32_t drawInFrame;      // 0-indexed draw number within current frame
    uint64_t cpuTimestamp;     // CPU high-resolution timestamp

    // ── Draw Intent ─────────────────────────────────────────────────────────
    // primType: D5/F-645. THE OLD COMMENT HERE WAS WRONG IN BOTH THE NAME AND
    // THE VALUE -- it read "0=TriList, 1=TriStrip", which is the decayed
    // 0/1/2/3/4 family. The architected value space is
    // `.research/xenia/src/xenia/gpu/xenos.h:44-93`, `enum class PrimitiveType`:
    // 0x00 kNone, 0x01 kPointList, 0x02 kLineList, 0x03 kLineStrip,
    // 0x04 kTriangleList, 0x05 kTriangleFan, 0x06 kTriangleStrip,
    // 0x07 kTriangleWithWFlags, 0x08 kRectangleList, 0x0C kLineLoop,
    // 0x0D kQuadList, 0x0E kQuadStrip, 0x0F kPolygon, >= 0x10 the 2D /
    // tessellation families (docs/ref/xenos_registers.md §5). It is reached as
    // `VGT_DRAW_INITIATOR.prim_type`, 6 bits at +0 (registers.h:315).
    //
    // MEASURED PRODUCER PREMISE, NOT A FACT ABOUT THE GUEST: the only writer
    // fills it with `ctx.r4.u32 & 7` (capture_hooks.cpp:227, `OnDrawBuild`) --
    // THREE bits of a RAGE build descriptor, not the 6-bit register field, and
    // the 3-bit value cannot express 0x08+. So the encoding this field
    // actually carries in a trace is UNVERIFIED against the Xenos enum; the
    // correct mapping downstream is
    // renderer::DerivePipelineState / D3D12Backend::MapXenosPrimType, and a soak
    // settles it by reading their per-value refusal counters.
    uint32_t primType;
    // indexType: the PROJECT'S OWN 3-value mapping of a RAGE descriptor field,
    // 0=16-bit, 1=32-bit, 2=non-indexed, taken from `(drawFlags >> 4) & 0x7`
    // with 0x1/0x5/0x7 (capture_hooks.cpp:235-243). This is NOT
    // `VGT_DRAW_INITIATOR.index_size`, which is a SINGLE bit meaning 16/32
    // (registers.h:324) and has no third value. The reference does not define
    // the RAGE field, so "which RAGE code means what" is UNVERIFIED.
    uint32_t indexType;
    uint32_t startIndex;       // First index / vertex
    uint32_t indexCount;       // Number of indices / vertices
    int32_t  baseVertex;       // Base vertex offset
    uint32_t drawFlags;        // ctx.r4.u32 verbatim -- the build descriptor the
                               // two fields above are sliced out of

    // ── Targets & Viewport ──────────────────────────────────────────────────
    // The next eight are copies of `MclaGpuContext` members (capture_hooks.cpp
    // :215-219, :262-265), NOT reads of Xenos registers. The registers they
    // STAND FOR are named for the benefit of a reader, and each is marked with
    // what the register actually contains -- do not read these as the register.
    uint32_t colorTargets[4];  // MclaGpuContext surface-info copies for RT0..RT3
                               // (guest state block +108..+120). The Xenos
                               // registers are RB_COLOR_INFO 0x2001 and
                               // RB_COLOR1/2/3_INFO 0x2003/0x2004/0x2005, whose
                               // `color_format` is 4 bits at +16
                               // (registers.h:745) and is SPARSE -- 8, 9, 11, 13
                               // are unassigned (xenos.h:299-319,
                               // docs/ref/xenos_registers.md §2.6/§6.2).
    uint32_t depthTarget;      // MclaGpuContext surface-info copy (guest state
                               // block +124). The Xenos register is
                               // RB_DEPTH_INFO 0x2002; `depth_format` is ONE bit
                               // at +16 (registers.h:844), 0 kD24S8 / 1 kD24FS8.
    uint32_t viewportTL;       // MclaGpuContext::rbSurfaceInfoP2 -- UNVERIFIED
    uint32_t viewportBR;       // MclaGpuContext::rbSurfaceInfoP3 -- UNVERIFIED
    uint32_t scissorTL;        // MclaGpuContext::rbSurfaceInfoP4 -- UNVERIFIED
    uint32_t scissorBR;        // MclaGpuContext::rbSurfaceInfoP5 -- UNVERIFIED
    // (The nearest Xenos register to the viewport pair is PA_SC_WINDOW_OFFSET
    // 0x2080, register_table.inc:497, applied only when
    // PA_SU_SC_MODE_CNTL.vtx_window_offset_enable -- bit 16 -- is set,
    // registers.h:475. The mapping from these four fields onto it is NOT
    // measured.)

    // ── Rasterizer & State ──────────────────────────────────────────────────
    // The three names below ARE Xenos registers, at the indices in the
    // generated table (register_table.inc:540-542). The VALUES here are
    // `MclaGpuContext` member copies (capture_hooks.cpp:246-248), NOT reads of
    // the command processor's register file -- that file is file-static in
    // src/gpu_cp.cpp. A consumer must therefore NOT set the matching
    // GuestRegisterPresent bit on the strength of these fields; see
    // renderer::kGuestRegNone in pipeline_cache.h.
    uint32_t paClipCntl;       // PA_CL_CLIP_CNTL,     index 0x2204
    uint32_t paSuScModeCntl;   // PA_SU_SC_MODE_CNTL,  index 0x2205
    uint32_t paClVteCntl;      // PA_CL_VTE_CNTL,      index 0x2206

    // ── Shaders & Constants ─────────────────────────────────────────────────
    // D5: the four names below were wrong in the same way. `SQ_VS_PROGRAM` and
    // `SQ_PS_PROGRAM` are NOT Xenos registers -- `register_table.inc` names no
    // register by either name (grep PROGRAM -> only SQ_PROGRAM_CNTL 0x2180 at
    // register_table.inc:523 and SQ_CF_PROGRAM_SIZE 0x2315 at :592). These are
    // MclaGpuContext copies of the guest's shader-program pointers.
    uint32_t sqVsProgram;      // MclaGpuContext::sqVsProgram -- NOT a register
    uint32_t sqPsProgram;      // MclaGpuContext::sqPsProgram -- NOT a register
    // `SQ_VS_CONST` and `SQ_PS_CONST` ARE registers -- 0x2307 and 0x2308,
    // kDword (register_table.inc:578-579) -- but they are NOT addresses. Their
    // fields are `base` 9 bits at +0 and `size` 9 bits at +12, the vec4 count
    // MINUS ONE, into the ALU constant bank (registers.h:259/:262, :273/:276).
    // The reference reads them that way at draw_util.cc:658-660. Reading
    // `sqVsConst` below as an ALU bank base would be a category error: these
    // two are MclaGpuContext copies (MclaGpuContext::sqVsConst, offset 0x317C).
    uint32_t sqVsConst;        // NOT the 0x2307 register; do not read as a bank base
    uint32_t sqPsConst;        // NOT the 0x2308 register; do not read as a bank base

    // ── Vertex Input ────────────────────────────────────────────────────────
    uint32_t vertexStreamCount;
    VertexStreamDesc vertexStreams[16];
    uint32_t indexBufferAddress;
    uint32_t indexBufferSize;

    // ── Textures ────────────────────────────────────────────────────────────
    // MEASURED: ALWAYS ZERO. The fetch-constant window these would come from
    // is not reachable from the capture translation unit, so
    // CaptureTextureDescriptors is called with fetchWindow == nullptr
    // (capture_hooks.cpp:255) and leaves textureCount == 0 after clearing both
    // it and the descriptor array (capture_hooks.cpp:106-107). Zero here means
    // "not captured", NOT "no textures bound" -- the accumulator keeps
    // attempts and successes in separate counters precisely so a soak can tell
    // the two apart.
    uint32_t textureCount;
    uint32_t textureDescriptors[16];

    // ── Integrity & Validation ──────────────────────────────────────────────
    uint64_t stateHash;        // Deterministic hash of draw state
    uint32_t isValid;          // 1 if all guest memory references are valid, 0 if error
    uint32_t validationFlags;  // Bitfield describing validation status

    // ── Vertex Declaration (grcFvf) ─────────────────────────────────────────
    GrcFvfDesc grcFvf;         // Captured RAGE drawable vertex declaration
    uint32_t hasGrcFvf;        // 1 when grcFvf was decoded from a live guest drawable
};

#pragma pack(pop)

static_assert(std::is_standard_layout_v<TraceHeader>);
static_assert(std::is_trivial_v<TraceHeader>);
static_assert(std::is_standard_layout_v<DrawPacket>);
static_assert(std::is_trivial_v<DrawPacket>);

} // namespace mcla::native
