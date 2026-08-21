#pragma once

// RAGE grcFvf vertex declaration decoding (Phase 8 item 1, headless-provable
// slice).
//
// MCLA VFETCH instructions embed vf=0, so the DXGI format/stride of every
// captured vertex stream can only come from the RAGE drawable's run-time
// vertex declaration (`grcVertexDescription` / Rsc5VertexDeclaration, field
// `m_Fvf`). This module decodes that 16-byte descriptor:
//
//   +0  u32 fvfMask       bit i set = semantic lane i is bound
//   +4  u8  fvfSize       declared vertex stride in bytes
//   +5  u8  flags
//   +6  u8  dynamicOrder
//   +7  u8  channelCount   count of set mask bits (informational; mask wins)
//   +8  u64 channelTypes   16 x 4-bit type codes, lane i at bits [i*4..i*4+3]
//
// Lane index is the RAGE semantic: 0 Position, 1 BlendWeights,
// 2 BlendIndices, 3 Normal, 4/5 Colour0/1, 6-13 TexCoord0-7, 14/15 Tangent0/1,
// 16/17 Binormal0/1. 4-bit type codes: 0 Nothing, 1 Half2, 3 Half4, 5 Float2,
// 6 Float3, 7 Float4, 8 UByte4, 9 Colour, 10 Dec3N. Codes 2, 4 and 11-15 have
// no corroborated size/format and are treated as UNKNOWN: a declaration using
// one decodes with unknownChannel=true and is refused for layout building
// (Golden Rule 5 - never invent draw data).
//
// The decoder is standalone (no D3D12, no GuestMemoryView - callers
// fetch the checked 16 guest bytes), so it is headlessly testable.
//
// It is intentionally separate from vertex_decode.{h,cpp}: vertex_decode maps
// Xenos 6-bit vertex-format codes; this module maps the RAGE drawable layout
// which MCLA's vf=0 fetches point at. The union of the two yields a real
// native input layout.

#include "native_types.h"

#include <cstdint>

namespace mcla::native {

// RAGE grcFvf semantic lanes the decoder addresses (0..17).
constexpr uint32_t kGrcFvfChannelCount = 18;

// 4-bit channel type codes.
enum class GrcFvfChannelType : uint8_t {
    Nothing   = 0,
    Half2     = 1,
    Half3     = 2,   // ambiguous in research ("FloatUnk/Half3"); size unverified
    Half4     = 3,
    FloatUnk  = 4,   // size/format unverified
    Float2    = 5,
    Float3    = 6,
    Float4    = 7,
    UByte4    = 8,
    Colour    = 9,
    Dec3N     = 10,
    Unk1      = 11, Unk2 = 12, Unk3 = 13, Unk4 = 14, Unk5 = 15,
};

// One decoded semantic lane of a declaration.
struct GrcFvfChannel {
    uint8_t type = 0;            // raw 4-bit code
    bool present = false;        // fvfMask bit set for this lane
    bool valid = false;          // present AND type has a corroborated size/format
    uint8_t componentCount = 0;  // 1..4
    uint8_t componentBytes = 0;  // bytes per component (0 for packed, e.g. Dec3N)
    uint8_t totalBytes = 0;      // byte contribution to the stride
    uint32_t dxgiFormat = 0;     // DXGI_FORMAT_* numeric value (0 when unknown)
    bool isFloat = false;
    bool isNormalized = false;
    bool isInteger = false;
    uint8_t usage = 0;           // DeclUsage (0 POSITION, 3 NORMAL, 5 TEXCOORD, 10 COLOR, ...)
    uint8_t usageIndex = 0;      // 0 for single; TexCoord/Colour/Tangent/Binormal index
    uint16_t byteOffset = 0;     // packed offset within the vertex
};

// Result of decoding a 16-byte grcFvf block.
struct GrcFvfDeclaration {
    bool valid = false;           // mask non-zero, >=1 present channel, no unknown types
    bool unknownChannel = false;  // a present lane has no corroborated size/format
    bool sizeMismatch = false;    // declared fvfSize != computedStride (renderer refuses when set)
    bool countMismatch = false;   // stored channelCount != popcount(mask) (informational)
    uint32_t fvfMask = 0;
    uint8_t fvfSize = 0;
    uint8_t flags = 0;
    uint8_t dynamicOrder = 0;
    uint8_t channelCount = 0;     // popcount(fvfMask)
    uint64_t typesRaw = 0;
    uint16_t computedStride = 0;  // sum of present channels' totalBytes
    GrcFvfChannel channels[kGrcFvfChannelCount];
};

// Decode a captured grcFvf descriptor (raw fields, big-endian guest layout).
// desc is zero-valued when the block was never captured (packet.hasGrcFvf==0).
GrcFvfDeclaration DecodeGrcFvf(const GrcFvfDesc& desc);

// A resolved input element for native layout creation.
struct GrcFvfLayoutEntry {
    uint8_t usage = 0;        // DeclUsage
    uint8_t usageIndex = 0;
    uint32_t dxgiFormat = 0;  // DXGI_FORMAT_* numeric value
    uint16_t byteOffset = 0;
    uint16_t stride = 0;      // this element's byte contribution
};

// Build the ordered input layout (ascending byteOffset) from a decoded
// declaration. Returns false when the declaration is not usable (invalid,
// unknown channel, or no present channels). `out` must hold at least
// kGrcFvfChannelCount entries; `count` receives the number written.
bool BuildGrcFvfLayout(const GrcFvfDeclaration& decl, GrcFvfLayoutEntry out[18],
                       uint32_t& count);

// Stable hash of a decoded declaration (mask/size/flags/dynamicOrder/types).
uint64_t HashGrcFvfDeclaration(const GrcFvfDeclaration& decl);

// Human-readable name for a 4-bit type code ("?" when out of range).
const char* GrcFvfChannelTypeName(uint8_t type);

} // namespace mcla::native
