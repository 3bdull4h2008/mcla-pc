#include "grc_fvf_decode.h"

#include <cstddef>

namespace mcla::native {

namespace {

struct TypeInfo {
    uint8_t comps;
    uint8_t compBytes;   // 0 = packed
    uint8_t totalBytes;
    uint32_t dxgiFormat;
    bool isFloat;
    bool isNormalized;
    bool isInteger;
};

// Corroborated 4-bit type table. Codes 2 (Half3/FloatUnk), 4 (FloatUnk) and
// 11-15 (Unk1-5) are intentionally absent: no research-backed size/format
// exists for them, and a declaration using one is refused rather than given
// an invented layout (Golden Rule 5). DXGI numbers: R32G32B32A32_FLOAT=2,
// R32G32B32_FLOAT=6, R16G16B16A16_FLOAT=11, R32G32_FLOAT=16,
// R10G10B10A2_UNORM=24, R8G8B8A8_UNORM=28, R8G8B8A8_UINT=30, R16G16_FLOAT=34.
bool TypeInfoFor(uint8_t code, TypeInfo& out) {
    switch (code) {
        case 1:  out = {2, 2, 4, 34, true,  false, false}; return true;  // Half2
        case 3:  out = {4, 2, 8, 11, true,  false, false}; return true;  // Half4
        case 5:  out = {2, 4, 8, 16, true,  false, false}; return true;  // Float2
        case 6:  out = {3, 4, 12, 6,  true,  false, false}; return true;  // Float3
        case 7:  out = {4, 4, 16, 2,  true,  false, false}; return true;  // Float4
        case 8:  out = {4, 1, 4, 30, false, false, true};  return true;  // UByte4
        case 9:  out = {4, 1, 4, 28, false, true,  false}; return true;  // Colour
        case 10: out = {4, 0, 4, 24, false, true,  false}; return true;  // Dec3N
        default: return false;  // 0 (Nothing) and unverified codes
    }
}

// Lane index -> DeclUsage + usage index, matching the DeclUsage semantic
// numbering VertexUsageSemanticName in shader_translator.cpp uses (POSITION=0,
// BLENDWEIGHT=1, BLENDINDICES=2, NORMAL=3, TEXCOORD=5, TANGENT=6, BINORMAL=7,
// COLOR=10) so a decoded channel can be fed straight into the input layout.
struct LaneSemantic {
    uint8_t usage;
    uint8_t usageIndex;
};

LaneSemantic SemanticForLane(uint32_t lane) {
    static constexpr LaneSemantic kLane[kGrcFvfChannelCount] = {
        {0, 0},  // 0  Position      -> POSITION 0
        {1, 0},  // 1  BlendWeights  -> BLENDWEIGHT 0
        {2, 0},  // 2  BlendIndices  -> BLENDINDICES 0
        {3, 0},  // 3  Normal        -> NORMAL 0
        {10, 0}, // 4  Colour0       -> COLOR 0
        {10, 1}, // 5  Colour1       -> COLOR 1
        {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, // 6-13 TexCoord0-7
        {6, 0}, {6, 1},  // 14-15 Tangent0/1
        {7, 0}, {7, 1},  // 16-17 Binormal0/1
    };
    if (lane >= kGrcFvfChannelCount) return {0, 0};
    return kLane[lane];
}

} // namespace

GrcFvfDeclaration DecodeGrcFvf(const GrcFvfDesc& desc) {
    GrcFvfDeclaration d{};
    d.fvfMask = desc.fvfMask;
    d.fvfSize = desc.fvfSize;
    d.flags = desc.flags;
    d.dynamicOrder = desc.dynamicOrder;
    d.typesRaw = desc.types;

    const uint8_t storedCount = desc.channelCount;

    uint8_t pop = 0;
    uint16_t offset = 0;
    for (uint32_t lane = 0; lane < kGrcFvfChannelCount; ++lane) {
        if (((d.fvfMask >> lane) & 1u) == 0) continue;  // lane not bound
        ++pop;

        const uint8_t code = (lane < 16)
                                 ? static_cast<uint8_t>((d.typesRaw >> (lane * 4)) & 0xF)
                                 : 0;
        GrcFvfChannel& ch = d.channels[lane];
        ch.type = code;
        ch.present = true;
        ch.byteOffset = offset;
        ch.usage = SemanticForLane(lane).usage;
        ch.usageIndex = SemanticForLane(lane).usageIndex;

        // Lanes 16/17 (Binormal0/1) carry no type bits in the u64 (it holds
        // only 16 codes); a bound lane there cannot be decoded. Refuse rather
        // than invent (Golden Rule 5).
        if (lane >= 16) {
            d.unknownChannel = true;
            continue;
        }
        if (code == static_cast<uint8_t>(GrcFvfChannelType::Nothing)) {
            d.unknownChannel = true;  // bound lane with a "Nothing" type
            continue;
        }
        TypeInfo ti;
        if (!TypeInfoFor(code, ti)) {
            d.unknownChannel = true;  // bound lane with an unverified type
            continue;
        }

        ch.valid = true;
        ch.componentCount = ti.comps;
        ch.componentBytes = ti.compBytes;
        ch.totalBytes = ti.totalBytes;
        ch.dxgiFormat = ti.dxgiFormat;
        ch.isFloat = ti.isFloat;
        ch.isNormalized = ti.isNormalized;
        ch.isInteger = ti.isInteger;
        offset = static_cast<uint16_t>(offset + ti.totalBytes);
    }

    d.channelCount = pop;
    d.computedStride = offset;
    if (d.fvfSize != 0 && d.computedStride != 0 && d.fvfSize != d.computedStride) {
        d.sizeMismatch = true;
    }
    if (storedCount != 0 && storedCount != pop) {
        d.countMismatch = true;
    }
    d.valid = (d.fvfMask != 0) && (pop > 0) && !d.unknownChannel;
    return d;
}

bool BuildGrcFvfLayout(const GrcFvfDeclaration& decl, GrcFvfLayoutEntry out[18],
                       uint32_t& count) {
    count = 0;
    if (!decl.valid) return false;

    for (uint32_t lane = 0; lane < kGrcFvfChannelCount; ++lane) {
        const GrcFvfChannel& ch = decl.channels[lane];
        if (!ch.present || !ch.valid) continue;
        if (count >= kGrcFvfChannelCount) return false;
        out[count].usage = ch.usage;
        out[count].usageIndex = ch.usageIndex;
        out[count].dxgiFormat = ch.dxgiFormat;
        out[count].byteOffset = ch.byteOffset;
        out[count].stride = ch.totalBytes;
        ++count;
    }
    return count > 0;
}

uint64_t HashGrcFvfDeclaration(const GrcFvfDeclaration& decl) {
    constexpr uint64_t kFnvOffset = 14695981039346656037ULL;
    constexpr uint64_t kFnvPrime = 1099511628211ULL;
    uint64_t hash = kFnvOffset;
    auto mix = [&hash](const void* data, size_t size) {
        const uint8_t* bytes = static_cast<const uint8_t*>(data);
        for (size_t i = 0; i < size; ++i) {
            hash ^= bytes[i];
            hash *= kFnvPrime;
        }
    };
    const uint32_t mask = decl.fvfMask;
    mix(&mask, sizeof(mask));
    mix(&decl.fvfSize, sizeof(decl.fvfSize));
    mix(&decl.flags, sizeof(decl.flags));
    mix(&decl.dynamicOrder, sizeof(decl.dynamicOrder));
    const uint64_t types = decl.typesRaw;
    mix(&types, sizeof(types));
    return hash;
}

const char* GrcFvfChannelTypeName(uint8_t type) {
    switch (type) {
        case 0:  return "Nothing";
        case 1:  return "Half2";
        case 2:  return "Half3(FloatUnk)";
        case 3:  return "Half4";
        case 4:  return "FloatUnk";
        case 5:  return "Float2";
        case 6:  return "Float3";
        case 7:  return "Float4";
        case 8:  return "UByte4";
        case 9:  return "Colour";
        case 10: return "Dec3N";
        case 11: return "Unk1";
        case 12: return "Unk2";
        case 13: return "Unk3";
        case 14: return "Unk4";
        case 15: return "Unk5";
        default: return "?";
    }
}

} // namespace mcla::native
