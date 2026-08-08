#include "texture_decode.h"

#include <cstring>

namespace mcla::native {

// DXGI_FORMAT numeric values (dxgiformat.h, Windows SDK 10.0.26100.0). Same
// values as vertex_decode.cpp; kept here so texture decode has no D3D12 header
// dependency.
enum {
    kDxgiUnknown              = 0,
    kDxgiR32G32B32A32Float    = 2,
    kDxgiR32G32B32A32Uint     = 3,
    kDxgiR32G32B32Float       = 6,
    kDxgiR32G32B32Uint        = 7,
    kDxgiR16G16B16A16Float    = 10,
    kDxgiR16G16B16A16Unorm    = 11,
    kDxgiR16G16B16A16Uint     = 12,
    kDxgiR32G32Float          = 16,
    kDxgiR32G32Uint           = 17,
    kDxgiR10G10B10A2Unorm     = 24,
    kDxgiR11G11B10Float       = 26,
    kDxgiR8G8B8A8Unorm        = 28,
    kDxgiR8G8B8A8Uint         = 30,
    kDxgiR8G8B8A8Snorm        = 31,
    kDxgiR8G8B8A8Sint         = 32,
    kDxgiR16G16Float          = 34,
    kDxgiR16G16Unorm          = 35,
    kDxgiR16G16Uint           = 36,
    kDxgiR8G8Unorm            = 49,
    kDxgiR8G8Uint             = 50,
    kDxgiR16Float             = 54,
    kDxgiR16Unorm             = 56,
    kDxgiR16Uint              = 57,
    kDxgiR32Float             = 41,
    kDxgiR32Uint              = 42,
    kDxgiR8Unorm              = 61,
    kDxgiR8Uint               = 62,
    kDxgiB5G6R5Unorm          = 85,
    kDxgiB5G5R5A1Unorm        = 86,
    kDxgiB8G8R8A8Unorm        = 87,
    kDxgiBC1Unorm             = 71,
    kDxgiBC2Unorm             = 74,
    kDxgiBC3Unorm             = 77,
    kDxgiBC4Unorm             = 80,
    kDxgiBC5Unorm             = 83,
    kDxgiB4G4R4A4Unorm        = 115,
    kDxgiD32FloatS8X24Uint    = 20,
    kDxgiD24UnormS8Uint       = 45,
};

// Xenos texture format table. Values mirror the ReXGlue SDK's compiled
// FormatInfo table verbatim — generated and cross-checked against the
// `FormatInfo::Get` export of rexruntime.dll (the FormatInfo oracle; see
// build/oracle_format_dump.cpp). Per the SDK formula
// `bytes_per_block() = block_width*block_height*bits_per_pixel/8`, the table
// stores bits per *texel* (e.g. DXT1 is 4, not 64). Host DXGI codes are the
// canonical D3D mapping for each Xenos format: Xenos stores texel bits in the
// same order as R5G6B5-style naming, and D3D names those BGR (e.g. 5_6_5 ->
// DXGI_FORMAT_B5G6R5_UNORM). Compressed/constant formats with a literal DXGI
// equivalent (DXT3A/DXT5A -> BC4_UNORM, both 1-channel 4bpp 4x4) are mapped;
// genuinely non-representable ones (YUV REP, MPEG, INTERLACED, CTX1, k_8_A vs
// k_8_B, 6_5_5, 1-bit) stay dxgi=0 (unsupported) until captured evidence
// forces them up.
static const TextureFormatInfo kFormatTable[] = {
    // (xenos, name, dxgi, blockW, blockH, bitsPerPixel, compressed, resolvable, swapped)
    // type==0 kResolvable -> isResolvable, type==2 kCompressed -> isBlockCompressed.
    {  0, "1_REVERSE",        0,                        1, 1,  1, false, false, false },
    {  1, "1",                0,                        1, 1,  1, false, false, false }, // host R1_UNORM not native
    {  2, "8",                kDxgiR8Unorm,             1, 1,  8, false, true,  false },
    {  3, "1_5_5_5",          kDxgiB5G5R5A1Unorm,       1, 1, 16, false, true,  true  },
    {  4, "5_6_5",            kDxgiB5G6R5Unorm,         1, 1, 16, false, true,  true  },
    {  5, "6_5_5",            0,                        1, 1, 16, false, true,  false },
    {  6, "8_8_8_8",          kDxgiR8G8B8A8Unorm,       1, 1, 32, false, true,  false },
    {  7, "2_10_10_10",       kDxgiR10G10B10A2Unorm,    1, 1, 32, false, true,  false },
    {  8, "8_A",              kDxgiR8Unorm,             1, 1,  8, false, true,  false },
    {  9, "8_B",              kDxgiR8Unorm,             1, 1,  8, false, true,  false },
    { 10, "8_8",              kDxgiR8G8Unorm,           1, 1, 16, false, true,  false },
    { 11, "Cr_Y1_Cb_Y0_REP",  0,                        2, 1, 16, true,  false, false }, // YUV, no DXGI
    { 12, "Y1_Cr_Y0_Cb_REP",  0,                        2, 1, 16, true,  false, false }, // YUV, no DXGI
    { 13, "16_16_EDRAM",      kDxgiR16G16Float,         1, 1, 32, false, false, false },
    { 14, "8_8_8_8_A",        kDxgiR8G8B8A8Unorm,       1, 1, 32, false, true,  false },
    { 15, "4_4_4_4",          kDxgiB4G4R4A4Unorm,       1, 1, 16, false, true,  true  },
    { 16, "10_11_11",         kDxgiR11G11B10Float,      1, 1, 32, false, true,  false },
    { 17, "11_11_10",         kDxgiR11G11B10Float,      1, 1, 32, false, true,  false },
    { 18, "DXT1",             kDxgiBC1Unorm,            4, 4,  4, true,  false, false },
    { 19, "DXT2_3",           kDxgiBC2Unorm,            4, 4,  8, true,  false, false },
    { 20, "DXT4_5",           kDxgiBC3Unorm,            4, 4,  8, true,  false, false },
    { 21, "16_16_16_16_EDRAM", kDxgiR16G16B16A16Float,  1, 1, 64, false, false, false },
    { 22, "24_8",             kDxgiD24UnormS8Uint,      1, 1, 32, false, false, false }, // depth/stencil
    { 23, "24_8_FLOAT",       kDxgiD32FloatS8X24Uint,   1, 1, 32, false, false, false },
    { 24, "16",               kDxgiR16Unorm,            1, 1, 16, false, true,  false },
    { 25, "16_16",            kDxgiR16G16Unorm,         1, 1, 32, false, true,  false },
    { 26, "16_16_16_16",      kDxgiR16G16B16A16Unorm,   1, 1, 64, false, true,  false },
    { 27, "16_EXPAND",        0,                        1, 1, 16, false, false, false }, // resampled format
    { 28, "16_16_EXPAND",     0,                        1, 1, 32, false, false, false },
    { 29, "16_16_16_16_EXPAND", 0,                      1, 1, 64, false, false, false },
    { 30, "16_FLOAT",         kDxgiR16Float,            1, 1, 16, false, true,  false },
    { 31, "16_16_FLOAT",      kDxgiR16G16Float,         1, 1, 32, false, true,  false },
    { 32, "16_16_16_16_FLOAT", kDxgiR16G16B16A16Float,  1, 1, 64, false, true,  false },
    { 33, "32",               kDxgiR32Uint,             1, 1, 32, false, false, false },
    { 34, "32_32",            kDxgiR32G32Uint,          1, 1, 64, false, false, false },
    { 35, "32_32_32_32",      kDxgiR32G32B32A32Uint,    1, 1,128, false, false, false },
    { 36, "32_FLOAT",         kDxgiR32Float,            1, 1, 32, false, true,  false },
    { 37, "32_32_FLOAT",      kDxgiR32G32Float,         1, 1, 64, false, true,  false },
    { 38, "32_32_32_32_FLOAT", kDxgiR32G32B32A32Float,  1, 1,128, false, true,  false },
    { 39, "32_AS_8",          0,                        4, 1,  8, true,  false, false }, // tiled layout, no host form
    { 40, "32_AS_8_8",        0,                        2, 1, 16, true,  false, false },
    { 41, "16_MPEG",          0,                        1, 1, 16, false, false, false },
    { 42, "16_16_MPEG",       0,                        1, 1, 32, false, false, false },
    { 43, "8_INTERLACED",     0,                        1, 1,  8, false, false, false },
    { 44, "32_AS_8_INTERLACED", 0,                      4, 1,  8, true,  false, false },
    { 45, "32_AS_8_8_INTERLACED", 0,                    1, 1, 16, true,  false, false },
    { 46, "16_INTERLACED",    0,                        1, 1, 16, false, false, false },
    { 47, "16_MPEG_INTERLACED", 0,                      1, 1, 16, false, false, false },
    { 48, "16_16_MPEG_INTERLACED", 0,                   1, 1, 32, false, false, false },
    { 49, "DXN",              kDxgiBC5Unorm,            4, 4,  8, true,  false, false },
    { 50, "8_8_8_8_AS_16_16_16_16", kDxgiR8G8B8A8Unorm, 1, 1, 32, false, true,  false },
    { 51, "DXT1_AS_16_16_16_16", kDxgiBC1Unorm,         4, 4,  4, true,  false, false },
    { 52, "DXT2_3_AS_16_16_16_16", kDxgiBC2Unorm,       4, 4,  8, true,  false, false },
    { 53, "DXT4_5_AS_16_16_16_16", kDxgiBC3Unorm,       4, 4,  8, true,  false, false },
    { 54, "2_10_10_10_AS_16_16_16_16", kDxgiR10G10B10A2Unorm, 1, 1, 32, false, true, false },
    { 55, "10_11_11_AS_16_16_16_16", kDxgiR11G11B10Float, 1, 1, 32, false, true,  false },
    { 56, "11_11_10_AS_16_16_16_16", kDxgiR11G11B10Float, 1, 1, 32, false, true,  false },
    { 57, "32_32_32_FLOAT",   kDxgiR32G32B32Float,      1, 1, 96, false, false, false },
    { 58, "DXT3A",            kDxgiBC4Unorm,            4, 4,  4, true,  false, false },
    { 59, "DXT5A",            kDxgiBC4Unorm,            4, 4,  4, true,  false, false },
    { 60, "CTX1",             0,                        4, 4,  4, true,  false, false }, // no native host form
    { 61, "DXT3A_AS_1_1_1_1", kDxgiBC4Unorm,            4, 4,  4, true,  false, false },
    { 62, "8_8_8_8_GAMMA_EDRAM", kDxgiR8G8B8A8Unorm,    1, 1, 32, false, false, false },
    { 63, "2_10_10_10_FLOAT_EDRAM", kDxgiR10G10B10A2Unorm, 1, 1, 32, false, false, false },
};

const TextureFormatInfo* GetTextureFormatInfo(uint32_t xenosFormat) {
    static const uint32_t kCount = sizeof(kFormatTable) / sizeof(kFormatTable[0]);
    for (uint32_t i = 0; i < kCount; ++i) {
        if (kFormatTable[i].xenosFormat == xenosFormat) return &kFormatTable[i];
    }
    return nullptr;
}

uint32_t GetTextureBytesPerBlock(uint32_t xenosFormat) {
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    if (!info) return 0;
    return (info->blockWidth * info->blockHeight * info->bitsPerPixel) / 8;
}

const char* TextureFormatName(uint32_t xenosFormat) {
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    return info ? info->name : "unknown";
}

uint32_t GetTextureBlockSpan(uint32_t xenosFormat, uint32_t width, uint32_t height,
                             uint32_t* outBlocksX, uint32_t* outBlocksY) {
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    if (!info || !outBlocksX || !outBlocksY || width == 0 || height == 0) {
        if (outBlocksX) *outBlocksX = 0;
        if (outBlocksY) *outBlocksY = 0;
        return 0;
    }
    uint32_t bx = (width + info->blockWidth - 1) / info->blockWidth;
    uint32_t by = (height + info->blockHeight - 1) / info->blockHeight;
    *outBlocksX = bx;
    *outBlocksY = by;
    return bx * by;
}

// ---------------------------------------------------------------------------
// Tiled offsets (canonical XGAddress math).
// ---------------------------------------------------------------------------

int32_t GetTiledOffset2D(int32_t x, int32_t y, uint32_t pitch, uint32_t bpbLog2) {
    // XGAddress2DTiledOffset: 32x32-block macro tiles. Pitch is rounded up to
    // a multiple of 32 blocks, as in Xenia's xe::align (GetTiledOffset2D),
    // which the SDK oracle also implements.
    pitch = (pitch + 31u) & ~31u;
    int32_t macro = ((x >> 5) + (y >> 5) * int32_t(pitch >> 5)) << (bpbLog2 + 7);
    int32_t micro = ((x & 7) + ((y & 0xE) << 2)) << bpbLog2;
    int32_t offset = macro + ((micro & ~0xF) << 1) + (micro & 0x0F) + ((y & 1) << 4);
    return ((offset & ~0x1FF) << 3) + ((y & 16) << 7) + ((offset & 0x1C0) << 2) +
           (((((y & 8) >> 2) + (x >> 3)) & 3) << 6) + (offset & 0x3F);
}

int32_t GetTiledOffset3D(int32_t x, int32_t y, int32_t z, uint32_t pitch,
                         uint32_t height, uint32_t bpbLog2) {
    pitch = (pitch + 31u) & ~31u;
    height = (height + 31u) & ~31u;
    // Triang3l TiledOffset3D: 32x32x4 macro-tile stacks.
    int32_t macro_outer =
        ((y >> 4) + (z >> 2) * int32_t(height >> 4)) * int32_t(pitch >> 5);
    int32_t macro = (((x >> 5) + macro_outer) << (bpbLog2 + 6)) & 0xFFFFFFF;
    macro <<= 1;  // equivalent: (((...) << (bpb + 6)) & 0xFFFFFFF) << 1
    int32_t micro = (((x & 7) + ((y & 6) << 2)) << (bpbLog2 + 6)) >> 6;
    int32_t offset_outer = ((y >> 3) + (z >> 2)) & 1;
    int32_t offset1 = offset_outer + ((((x >> 3) + (offset_outer << 1)) & 3) << 1);
    int32_t offset2 = ((macro + (micro & ~15)) << 1) + (micro & 15) +
                      ((z & 3) << (bpbLog2 + 6)) + ((y & 1) << 4);
    int32_t address = (offset1 & 1) << 3;
    address += (offset2 >> 6) & 7;
    address <<= 3;
    address += offset1 & ~1;
    address <<= 2;
    address += offset2 & ~511;
    address <<= 3;
    address += offset2 & 63;
    return address;
}

int32_t GetTiledAddressLowerBound2D(uint32_t left, uint32_t top, uint32_t pitch,
                                    uint32_t bpbLog2) {
    // Origin of the 32x32-block macro tile containing block (left, top).
    return GetTiledOffset2D(int32_t(left & ~31u), int32_t(top & ~31u), pitch, bpbLog2);
}

int32_t GetTiledAddressUpperBound2D(uint32_t right, uint32_t bottom, uint32_t pitch,
                                    uint32_t bpbLog2) {
    if (!right || !bottom) return 0;
    // Origin of the 32x32 tile containing the last block, then the maximum extent
    // reachable within that tile (per Xenia GTextureAddressUpperBound).
    int32_t origin = GetTiledOffset2D(int32_t((right - 1) & ~31u),
                                      int32_t((bottom - 1) & ~31u), pitch, bpbLog2);
    switch (bpbLog2) {
        case 0: origin += 0xA00; break;   // independent addressing, 0xA00 extent
        case 1: origin += 0xC00; break;   // independent addressing, 0xC00 extent
        default: origin += int32_t(UINT32_C(0x400) << bpbLog2); break;
    }
    return origin;
}

int32_t GetTiledAddressLowerBound3D(uint32_t left, uint32_t top, uint32_t front,
                                    uint32_t pitch, uint32_t height, uint32_t bpbLog2) {
    // Mirrors ReXGlue texture_util::GetTiledAddressLowerBound3D exactly:
    // x & ~kTextureTileWidthHeight (2D) / front & ~kTextureTileDepth (3D,
    // kTextureTileDepth = 4).
    return GetTiledOffset3D(int32_t(left & ~31u), int32_t(top & ~31u),
                            int32_t(front & ~4u), pitch, height, bpbLog2);
}

int32_t GetTiledAddressUpperBound3D(uint32_t right, uint32_t bottom, uint32_t back,
                                    uint32_t pitch, uint32_t height, uint32_t bpbLog2) {
    if (!right || !bottom || !back) return 0;
    // Origin of the 32x32x4 tile containing the last block, then the maximum
    // extent within that tile.
    int32_t origin = GetTiledOffset3D(int32_t((right - 1) & ~31u),
                                      int32_t((bottom - 1) & ~31u),
                                      int32_t((back - 1) & ~3u), pitch, height, bpbLog2);
    switch (bpbLog2) {
        case 0:
            // 64x32x8 portions have independent addressing.
            origin += int32_t(((pitch >> 6) << 12) + 0xC00 +
                              ((pitch & (1u << 5)) << (10 - 5)));
            break;
        default:
            // 32x32x8 portions have independent addressing.
            origin += int32_t(((pitch << (12 - 5 - 1)) + (0x1000 >> 1)) << bpbLog2);
            break;
    }
    return origin;
}

// ---------------------------------------------------------------------------
// Untile
// ---------------------------------------------------------------------------

// Bounds guard for one block copy. `tiled` is the (already-computed) byte
// offset into the source surface; a negative value means the request stepped
// outside the surface grid, and both the read and write ends are checked
// against the caller-provided buffer sizes before any access. Any pair that
// would step outside a buffer is skipped — never read or written.
static bool UntileProbeSafe(int32_t tiled, uint32_t srcBytes, uint64_t dstOffset,
                            uint32_t dstBytes, uint32_t bpb) {
    if (tiled < 0) return false;
    const uint64_t readEnd = uint64_t(tiled) + bpb;
    if (readEnd > srcBytes) return false;
    const uint64_t writeEnd = dstOffset + bpb;
    if (writeEnd > dstBytes) return false;
    return true;
}

void UntileTexture2D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info) {
    if (!info.format || !src || !dst || info.inputPitch == 0) return;
    // Region must lie inside the surface grid (overflow-checked in 64-bit).
    // Y is bounded only when the caller supplied a surface height; otherwise
    // the per-block bounds guard below is the protection.
    if (uint64_t(info.offsetX) + info.width > uint64_t(info.inputPitch)) return;
    if (info.inputHeight != 0 &&
        uint64_t(info.offsetY) + info.height > uint64_t(info.inputHeight)) return;
    const uint32_t bpb = GetTextureBytesPerBlock(info.format->xenosFormat);
    if (bpb == 0) return;
    const uint32_t bpbLog2 = 31 - uint32_t(__builtin_clz(bpb));  // must be power of two
    if ((bpb & (bpb - 1)) != 0 || bpbLog2 > 6) return;  // exotic size: caller must handle
    if (!info.srcBytes || !info.dstBytes) return;       // bounds guard requires sizes
    for (uint32_t y = 0; y < info.height; ++y) {
        const uint64_t dstRow = (uint64_t(info.offsetY + y) * info.outputPitch + info.offsetX);
        for (uint32_t x = 0; x < info.width; ++x) {
            const int32_t tiled = GetTiledOffset2D(int32_t(info.offsetX + x),
                                                   int32_t(info.offsetY + y),
                                                   info.inputPitch, bpbLog2);
            const uint64_t dstOffset = (dstRow + x) * bpb;
            if (!UntileProbeSafe(tiled, info.srcBytes, dstOffset, info.dstBytes, bpb)) continue;
            std::memcpy(dst + dstOffset, src + tiled, bpb);
        }
    }
}

void UntileTexture3D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info,
                     uint32_t depth) {
    if (!info.format || !src || !dst || info.inputPitch == 0 || info.inputHeight == 0) return;
    if (uint64_t(info.offsetX) + info.width > uint64_t(info.inputPitch) ||
        uint64_t(info.offsetY) + info.height > uint64_t(info.inputHeight)) return;
    const uint32_t bpb = GetTextureBytesPerBlock(info.format->xenosFormat);
    if (bpb == 0) return;
    const uint32_t bpbLog2 = 31 - uint32_t(__builtin_clz(bpb));  // must be power of two
    if ((bpb & (bpb - 1)) != 0 || bpbLog2 > 6) return;
    if (!info.srcBytes || !info.dstBytes) return;
    for (uint32_t z = 0; z < depth; ++z) {
        for (uint32_t y = 0; y < info.height; ++y) {
            const uint64_t dstRow =
                (uint64_t(z) * info.height + uint64_t(info.offsetY + y)) * info.outputPitch +
                info.offsetX;
            for (uint32_t x = 0; x < info.width; ++x) {
                const int32_t tiled = GetTiledOffset3D(int32_t(info.offsetX + x),
                                                       int32_t(info.offsetY + y),
                                                       int32_t(z),
                                                       info.inputPitch, info.inputHeight,
                                                       bpbLog2);
                const uint64_t dstOffset = (dstRow + x) * bpb;
                if (!UntileProbeSafe(tiled, info.srcBytes, dstOffset, info.dstBytes, bpb)) continue;
                std::memcpy(dst + dstOffset, src + tiled, bpb);
            }
        }
    }
}

} // namespace mcla::native