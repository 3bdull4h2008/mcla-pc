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
    uint32_t primType;         // Primitive topology (0=TriList, 1=TriStrip, etc.)
    uint32_t indexType;        // Index format (0=16-bit, 1=32-bit, 2=non-indexed)
    uint32_t startIndex;       // First index / vertex
    uint32_t indexCount;       // Number of indices / vertices
    int32_t  baseVertex;       // Base vertex offset
    uint32_t drawFlags;        // Raw flags passed from sub_82420BA8

    // ── Targets & Viewport ──────────────────────────────────────────────────
    uint32_t colorTargets[4];  // Surface-info descriptors for RT0..RT3
    uint32_t depthTarget;      // Surface-info descriptor for depth/stencil
    uint32_t viewportTL;       // Viewport top-left / scale
    uint32_t viewportBR;       // Viewport bottom-right / offset
    uint32_t scissorTL;        // Scissor top-left
    uint32_t scissorBR;        // Scissor bottom-right

    // ── Rasterizer & State ──────────────────────────────────────────────────
    uint32_t paClipCntl;       // PA_CL_CLIP_CNTL
    uint32_t paSuScModeCntl;   // PA_SU_SC_MODE_CNTL
    uint32_t paClVteCntl;      // PA_CL_VTE_CNTL

    // ── Shaders & Constants ─────────────────────────────────────────────────
    uint32_t sqVsProgram;      // SQ_VS_PROGRAM guest address
    uint32_t sqVsConst;        // SQ_VS_CONST guest address
    uint32_t sqPsProgram;      // SQ_PS_PROGRAM guest address
    uint32_t sqPsConst;        // SQ_PS_CONST guest address

    // ── Vertex Input ────────────────────────────────────────────────────────
    uint32_t vertexStreamCount;
    VertexStreamDesc vertexStreams[16];
    uint32_t indexBufferAddress;
    uint32_t indexBufferSize;

    // ── Textures ────────────────────────────────────────────────────────────
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
