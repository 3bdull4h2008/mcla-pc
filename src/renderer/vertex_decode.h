#pragma once

// Phase 3 vertex/index decode for the MCLA native renderer.
//
// Xenos vertex-fetch instructions carry a 6-bit vertex format code (the "vf"
// field decoded by xenos_microcode as DecodedInstruction::vertexFormat). This
// module maps that code to a component layout and a DXGI format for native
// pipeline/vertex-declaration creation, and resolves index format to a byte
// size. It is intentionally standalone (no D3D12 headers) so it is testable
// headlessly against the shader corpus.

#include <cstdint>

namespace mcla::native {

// Xenos vertex format categories (subset that affects layout/DXGI mapping).
enum class VertexType : uint8_t {
    Unsupported = 0,
    Unorm8x4,        // 8_8_8_8 UNORM
    Unorm2_10_10_10, // 2_10_10_10 UNORM
    R11G11B10Float,  // 10_11_11 / 11_11_10 float-packed
    Unorm16,         // 16_16 UNORM
    Unorm16x4,       // 16_16_16_16 UNORM
    Float16,         // 16_16 FLOAT
    Float16x4,       // 16_16_16_16 FLOAT
    Int32,           // 32
    Int32x2,         // 32_32
    Int32x4,         // 32_32_32_32
    Float32,         // 32 FLOAT
    Float32x2,       // 32_32 FLOAT
    Float32x3,       // 32_32_32 FLOAT
    Float32x4,       // 32_32_32_32 FLOAT
};

// Result of decoding one vertex format code.
struct VertexFormatDesc {
    bool valid = false;
    VertexType type = VertexType::Unsupported;
    uint8_t componentCount = 0;   // 1..4
    uint8_t componentBytes = 0;   // bytes per component (0 for packed 11/10)
    uint16_t totalBytes = 0;      // stride contribution of this element
    uint32_t dxgiFormat = 0;      // DXGI_FORMAT_* numeric value (0 if unsupported)
    bool isFloat = false;
    bool isNormalized = false;    // applies only to normalized types
    bool isInteger = false;
    // True when the vf code does not carry format/stride itself (MCLA
    // VFETCH instructions embed vf=0 and use a runtime guest fetch-constant
    // descriptor selected by constIndex). Callers must resolve the actual
    // format/stride from that descriptor at capture time.
    bool fromFetchConstant = false;
    uint32_t fetchConstantIndex = 0;  // fetch-constant slot [0-95] when fromFetchConstant
    uint32_t fetchConstantSelect = 0; // raw 2-bit constIndexSelect (field only, pre-merge)
};

// Decode a Xenos 6-bit vertex format code.
VertexFormatDesc DecodeVertexFormat(uint32_t vfCode);
// Decode a VFETCH with an explicit fetch-constant index/select. When vfCode
// is 0 (MCLA embeds 0), the descriptor fields (format/stride) must come from
// the guest fetch-constant table; this returns fromFetchConstant=true and sets
// fetchConstantIndex to the merged slot `(constIndex & 0x1F) * 3 +
// (constIndexSelect & 0x3)` (hardware range [0-95]; the 2-bit select selects
// one of three 32-byte constants per 5-bit const_index). pass 0 for
// constIndexSelect where only constIndex is known. When vfCode is non-zero it
// behaves like DecodeVertexFormat and ignores the index fields.
VertexFormatDesc DecodeVertexFetch(uint32_t vfCode, uint32_t constIndex,
                                   uint32_t constIndexSelect = 0);

// A single Xenos SHADER_CONSTANT_FETCH stream binding, decoded from the
// documented 8-byte `xe_gpu_vertex_fetch_t` layout
// (`_archive/xenia_xenos.h`, `rexglue-sdk/.../xenos.h`):
//   word0: { address_type: 2, address: 30 }   (address in DWORDs)
//   word1: { endian: 2,       size: 24 }      (size in WORDs per RX00)
// It carries ONLY the VB base address, size and endianness for a fetched
// stream. Per Rev 03 of the plan, format/stride are NOT present here (MCLA
// VFETCH embeds vf=0, stride=0) and must be recovered offline from the
// captured RAGE drawable's vertex declaration (grcFvf), never inferred here.
struct VertexFetchConstant {
    bool valid = false;
    bool isZero = false;      // whole 8 bytes zero (unwritten slot)
    uint16_t addressType = 0; // 2-bit raw
    uint32_t addressBytes = 0;// address field, converted to bytes = dwords*4
    uint16_t endian = 0;      // 2-bit raw (0x1C800?? encoding resolved by caller)
    uint32_t sizeWords = 0;   // 24-bit size field, in 16-bit words
};

// Decode an 8-byte big-endian fetch-constant entry into VertexFetchConstant.
// `p8` must point at a checked, in-bounds 8 bytes of guest data already
// fetched by the caller's GuestMemoryView (this parser never touches guest
// memory itself, keeping it headlessly testable). Sets valid only for a
// non-zero entry whose address/size are in range.
VertexFetchConstant DecodeVertexFetchConstant(const uint8_t* p8);

// Human-readable name (for debug/trace); "unsupported" when !valid.
const char* VertexFormatName(uint32_t vfCode);

// Byte size of one index for a captured index type.
//   indexType: 0 = 16-bit, 1 = 32-bit, 2 = non-indexed.
// Returns 0 for non-indexed or unknown types.
uint32_t IndexElementBytes(uint32_t indexType);

// Build a stable hash of a vertex-declaration layout from a sequence of
// (vfCode, usage, usageIndex) triples. Used as the PipelineKey vertexDeclHash
// component. Returns 0 if any element is unsupported.
uint64_t HashVertexDeclaration(const uint32_t* vfCodes, const uint8_t* usages,
                               const uint8_t* usageIndices, uint32_t count);

} // namespace mcla::native
