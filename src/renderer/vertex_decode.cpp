#include "vertex_decode.h"

namespace mcla::native {

// DXGI_FORMAT numeric values (dxgiformat.h). Kept as integer constants so this
// module has no D3D12 header dependency and stays headlessly testable.
enum {
    kDxgiR32G32B32A32Float  = 2,
    kDxgiR32G32B32A32Uint   = 3,
    kDxgiR32G32B32Float     = 6,
    kDxgiR32G32B32Uint      = 7,
    kDxgiR16G16B16A16Float  = 10,
    kDxgiR16G16B16A16Unorm  = 11,
    kDxgiR16G16B16A16Uint   = 12,
    kDxgiR32G32Float        = 16,
    kDxgiR32G32Uint         = 17,
    kDxgiR32Float           = 41,
    kDxgiR32Uint            = 42,
    kDxgiR16G16Float        = 65,
    kDxgiR16G16Unorm        = 66,
    kDxgiR10G10B10A2Unorm   = 75,
    kDxgiR11G11B10Float     = 77,
    kDxgiR8G8B8A8Unorm      = 79,
    kDxgiR8G8B8A8Uint       = 81,
    kDxgiR8G8B8A8Snorm      = 82,
    kDxgiR8G8B8A8Sint       = 83,
};

// Xenos vertex format codes (see _archive/xenia_xenos.h VertexFormat).
// 6-bit "vf" field of a VFETCH instruction.
static VertexFormatDesc MakeDesc(bool valid, VertexType type, uint8_t comps,
                                 uint8_t compBytes, uint16_t totalBytes,
                                 uint32_t dxgi, bool isFloat,
                                 bool isNorm, bool isInt) {
    VertexFormatDesc d;
    d.valid = valid;
    d.type = type;
    d.componentCount = comps;
    d.componentBytes = compBytes;
    d.totalBytes = totalBytes;
    d.dxgiFormat = dxgi;
    d.isFloat = isFloat;
    d.isNormalized = isNorm;
    d.isInteger = isInt;
    return d;
}

VertexFormatDesc DecodeVertexFormat(uint32_t vfCode) {
    switch (vfCode) {
        case 6:   return MakeDesc(true, VertexType::Unorm8x4,       4, 1, 4,  kDxgiR8G8B8A8Unorm,     false, true,  false); // 8_8_8_8
        case 7:   return MakeDesc(true, VertexType::Unorm2_10_10_10,4, 4, 4,  kDxgiR10G10B10A2Unorm,  false, true,  false); // 2_10_10_10
        case 16:  return MakeDesc(true, VertexType::R11G11B10Float, 3, 4, 4,  kDxgiR11G11B10Float,    true,  false, false); // 10_11_11
        case 17:  return MakeDesc(true, VertexType::R11G11B10Float, 3, 4, 4,  kDxgiR11G11B10Float,    true,  false, false); // 11_11_10
        case 25:  return MakeDesc(true, VertexType::Unorm16,        2, 2, 4,  kDxgiR16G16Unorm,       false, true,  false); // 16_16
        case 26:  return MakeDesc(true, VertexType::Unorm16x4,      4, 2, 8,  kDxgiR16G16B16A16Unorm, false, true,  false); // 16_16_16_16
        case 31:  return MakeDesc(true, VertexType::Float16,        2, 2, 4,  kDxgiR16G16Float,       true,  false, false); // 16_16 FLOAT
        case 32:  return MakeDesc(true, VertexType::Float16x4,      4, 2, 8,  kDxgiR16G16B16A16Float, true,  false, false); // 16_16_16_16 FLOAT
        case 33:  return MakeDesc(true, VertexType::Int32,          1, 4, 4,  kDxgiR32Uint,           false, false, true);  // 32
        case 34:  return MakeDesc(true, VertexType::Int32x2,        2, 4, 8,  kDxgiR32G32Uint,        false, false, true);  // 32_32
        case 35:  return MakeDesc(true, VertexType::Int32x4,        4, 4, 16, kDxgiR32G32B32A32Uint,  false, false, true);  // 32_32_32_32
        case 36:  return MakeDesc(true, VertexType::Float32,        1, 4, 4,  kDxgiR32Float,          true,  false, false); // 32 FLOAT
        case 37:  return MakeDesc(true, VertexType::Float32x2,      2, 4, 8,  kDxgiR32G32Float,       true,  false, false); // 32_32 FLOAT
        case 38:  return MakeDesc(true, VertexType::Float32x4,      4, 4, 16, kDxgiR32G32B32A32Float, true,  false, false); // 32_32_32_32 FLOAT
        case 57:  return MakeDesc(true, VertexType::Float32x3,      3, 4, 12, kDxgiR32G32B32Float,    true,  false, false); // 32_32_32 FLOAT
        default:  return MakeDesc(false, VertexType::Unsupported,   0, 0, 0, 0, false, false, false);
}
}


VertexFormatDesc DecodeVertexFetch(uint32_t vfCode, uint32_t constIndex) {
    VertexFormatDesc d = DecodeVertexFormat(vfCode);
    if (d.valid) return d;
    // vf=0 in MCLA VFETCH means format/stride come from a runtime guest
    // fetch-constant descriptor indexed by constIndex; mark it as needing
    // that descriptor so the capture path resolves the real layout.
    if (vfCode == 0) {
        d.fromFetchConstant = true;
        d.fetchConstantIndex = constIndex & 0x1F;
    }
    return d;
}

const char* VertexFormatName(uint32_t vfCode) {
    switch (vfCode) {
        case 6:  return "8_8_8_8";
        case 7:  return "2_10_10_10";
        case 16: return "10_11_11";
        case 17: return "11_11_10";
        case 25: return "16_16";
        case 26: return "16_16_16_16";
        case 31: return "16_16_float";
        case 32: return "16_16_16_16_float";
        case 33: return "32";
        case 34: return "32_32";
        case 35: return "32_32_32_32";
        case 36: return "32_float";
        case 37: return "32_32_float";
        case 38: return "32_32_32_32_float";
        case 57: return "32_32_32_float";
        default: return "unsupported";
}
}


uint32_t IndexElementBytes(uint32_t indexType) {
    switch (indexType) {
        case 0: return 2;   // 16-bit
        case 1: return 4;   // 32-bit
        default: return 0;  // non-indexed / unknown
}
}


uint64_t HashVertexDeclaration(const uint32_t* vfCodes, const uint8_t* usages,
                               const uint8_t* usageIndices, uint32_t count) {
    uint64_t h = 14695981039346656037ULL; // FNV-1a 64-bit
    const uint64_t prime = 1099511628211ULL;
    auto mix = [&](uint8_t b) {
        h ^= uint64_t(b);
        h *= prime;
    };
    for (uint32_t i = 0; i < count; ++i) {
        VertexFormatDesc d = DecodeVertexFormat(vfCodes[i]);
        if (!d.valid) return 0;  // caller must not build a pipeline for unsupported input
        // Hash vfCode (4 bytes) + usage + usageIndex
        mix(uint8_t(vfCodes[i]));
        mix(uint8_t(vfCodes[i] >> 8));
        mix(uint8_t(vfCodes[i] >> 16));
        mix(uint8_t(vfCodes[i] >> 24));
        mix(usages ? usages[i] : 0);
        mix(usageIndices ? usageIndices[i] : 0);
        mix(uint8_t(d.componentCount));
        mix(uint8_t(d.totalBytes));
    }
    return h;
}

} // namespace mcla::native
