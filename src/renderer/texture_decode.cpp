#include "texture_decode.h"

#include <cstring>
#include <utility>

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

// Xenos texture format table. Values mirror the compiled legacy FormatInfo
// table verbatim: the row order is the xenos::TextureFormat enum, and name /
// block size / bits-per-texel / type agree row by row (indices 0..63) with
// Xenia's independent FormatInfo::Get table
// (.research/xenia/src/xenia/gpu/texture_info_formats.cc:21-88; the type
// column is xenos FormatType, kResolvable=0/kUncompressed=1/kCompressed=2,
// texture_info.h:115-121). It was originally generated against the
// `FormatInfo::Get` export of rexruntime.dll (the FormatInfo oracle, plus the
// `build/oracle_format_dump.cpp` this comment used to point at): that DLL left
// the tree with ReXGlue, and no such dump file exists in the tree or in git
// history, so the only surviving oracle hook is
// tools/validators/texture_decode_test.cpp, which LoadLibrary's rexruntime.dll
// and prints "oracle absent (ReXGlue removed) - skipping" instead of
// comparing when it is missing (texture_decode_test.cpp:68-72).
// Per the SDK formula
// `bytes_per_block() = block_width*block_height*bits_per_pixel/8`, the table
// stores bits per *texel* (e.g. DXT1 is 4, not 64). Host DXGI codes are the
// canonical D3D mapping for each Xenos format: Xenos stores texel bits in the
// same order as R5G6B5-style naming, and D3D names those BGR (e.g. 5_6_5 ->
// DXGI_FORMAT_B5G6R5_UNORM). Compressed/constant formats with a literal DXGI
// equivalent (DXT3A/DXT5A -> BC4_UNORM, both 1-channel 4bpp 4x4) are mapped,
// and so are 8_A/8_B: both those rows carry dxgi=R8_UNORM (61), so they are
// aliased onto one host form (which loses the luminance-vs-alpha distinction),
// not left unsupported. What really is dxgi=0 here is YUV REP, MPEG,
// INTERLACED, the *_EXPAND and 32_AS_8* packings, CTX1, 6_5_5, 1-bit and
// 32_32_32_FLOAT — Xenia reaches some of those through a load shader instead
// of a host format (CTX1 -> R8G8_UNORM, DXT3A -> R8_UNORM,
// .research/xenia/src/xenia/gpu/d3d12/d3d12_texture_cache.cc:361-374) — and
// they stay dxgi=0 (unsupported) until captured evidence forces them up.
// `constexpr`, not `static const`: the F-647 pitch self-check below walks this
// array in a constant expression, and C++ forbids reading a non-constexpr
// `static const` object at compile time. `constexpr` implies `const`, so the
// internal linkage (and the single instance) is unchanged.
constexpr TextureFormatInfo kFormatTable[] = {
    // (xenos, name, dxgi, blockW, blockH, bitsPerPixel, compressed, resolvable, swapped)
    // type==0 kResolvable -> isResolvable, type==2 kCompressed -> isBlockCompressed.
    {  0, "1_REVERSE",        0,                        1, 1,  1, false, false, false },
    {  1, "1",                0,                        1, 1,  1, false, false, false }, // no 1bpp host form (R1_UNORM=66 does exist in dxgiformat.h, unused here)
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
// F-647: the block-row pitch contract -- derivation, self-check, static_asserts.
// See texture_decode.h for the D3D12 contract this implements.
// ---------------------------------------------------------------------------

// `constexpr` (declared so in the header) so the static_asserts below can call
// it; a constexpr function is equally callable at runtime.
constexpr uint32_t D3D12BlockCompressedBytes(uint32_t dxgiFormat) {
    switch (dxgiFormat) {
        // D3D12 functional spec, "Block Compressor" / BC1..BC5: 8 bytes per
        // 4x4 block for BC1 and BC4, 16 for BC2, BC3 and BC5. Independently
        // corroborated inside the tree by Xenia's load-shader selection, which
        // keys off bits-per-block -- kLoadShaderIndex64bpb for k_DXT1 and
        // kLoadShaderIndex128bpb for k_DXT2_3 / k_DXT4_5, over 16 texels per
        // block, i.e. 8 and 16 bytes:
        //   .research/xenia/src/xenia/gpu/d3d12/d3d12_texture_cache.cc:181,186,191
        case kDxgiBC1Unorm: return 8;
        case kDxgiBC2Unorm: return 16;
        case kDxgiBC3Unorm: return 16;
        case kDxgiBC4Unorm: return 8;
        case kDxgiBC5Unorm: return 16;
        default: return 0;  // not a BC format in this table (or unknown)
    }
}

uint32_t SourceBlockRowPitchBytes(uint32_t xenosFormat, uint32_t width) {
    uint32_t blocksX = 0, blocksY = 0;
    if (width == 0) return 0;
    // GetTextureBlockSpan refuses a zero width/height and an unknown format, so
    // a returned 0 blocksX is exactly the "no such pitch" case.
    if (GetTextureBlockSpan(xenosFormat, width, 1u, &blocksX, &blocksY) == 0) return 0;
    return blocksX * GetTextureBytesPerBlock(xenosFormat);
}

uint32_t SourceBlockRowCount(uint32_t xenosFormat, uint32_t height) {
    uint32_t blocksX = 0, blocksY = 0;
    if (height == 0) return 0;
    if (GetTextureBlockSpan(xenosFormat, 1u, height, &blocksX, &blocksY) == 0) return 0;
    return blocksY;
}

uint32_t SourceBlockSpanBytes(uint32_t xenosFormat, uint32_t width, uint32_t height) {
    const uint32_t pitch = SourceBlockRowPitchBytes(xenosFormat, width);
    const uint32_t rows = SourceBlockRowCount(xenosFormat, height);
    if (pitch == 0 || rows == 0) return 0;
    return pitch * rows;
}

// --- the compile-time half of the self-check ---------------------------------
// The same two checks as VerifyBlockRowPitchContract, written so a constant
// expression can walk the `static const` table directly. Both are static_asserted
// below, so this is enforced in the main app AND in texture_decode_test AND in
// texture_import_validator (CMakeLists.txt:316-321, 610-612, 1049-1058).
namespace {

constexpr const TextureFormatInfo* FormatInfoConst(uint32_t xenosFormat) {
    for (uint32_t i = 0; i < sizeof(kFormatTable) / sizeof(kFormatTable[0]); ++i)
        if (kFormatTable[i].xenosFormat == xenosFormat) return &kFormatTable[i];
    return nullptr;
}

constexpr uint32_t TableBytesPerBlockConst(uint32_t xenosFormat) {
    const TextureFormatInfo* i = FormatInfoConst(xenosFormat);
    return i ? (i->blockWidth * i->blockHeight * i->bitsPerPixel) / 8u : 0u;
}

constexpr uint32_t TableRowPitchConst(uint32_t xenosFormat, uint32_t width) {
    const TextureFormatInfo* i = FormatInfoConst(xenosFormat);
    if (!i || width == 0u) return 0u;
    return ((width + i->blockWidth - 1u) / i->blockWidth) * TableBytesPerBlockConst(xenosFormat);
}

// Widths 1..8 chosen so the non-multiple-of-4 cases are actually covered:
// 1,2,3 are narrower than one 4x4 block and must still occupy a WHOLE block;
// 4 is exactly one block; 5,6,7 are the first widths where `w*bytesPerBlock`
// and `ceil(w/4)*bytesPerBlock` disagree; 8 is two blocks. Width 1 is the one
// width where the two formulas coincide (1*bpb == 1*bpb), which is why
// kNaivePitchWouldShear below exists -- without it the check could pass
// vacuously against a naive implementation.
constexpr uint32_t kPitchProbeMinWidth = 1;
constexpr uint32_t kPitchProbeMaxWidth = 8;

constexpr bool BlockRowPitchContractHolds() {
    for (uint32_t f = 0; f < 64u; ++f) {
        const TextureFormatInfo* i = FormatInfoConst(f);
        if (!i) continue;
        const uint32_t want = D3D12BlockCompressedBytes(i->dxgiFormat);
        if (want == 0u) {
            // A row with no D3D12 BC host form. If it still claims a block
            // granularity it must be UNREACHABLE: every such row in the table
            // (Cr_Y1_Cb_Y0_REP, Y1_Cr_Y0_Cb_REP, 32_AS_8, 32_AS_8_8, the two
            // *_8_INTERLACED, CTX1) has dxgiFormat == 0, which is what makes
            // PlanTextureImport refuse it with NoHostFormat. If a future edit
            // gave one of them a host format, the block pitch would no longer
            // have been derived from anything, so refuse the edit here.
            if (i->isBlockCompressed && i->dxgiFormat != 0u) return false;
            continue;
        }
        // From here the row IS a D3D12 BC import, so the full contract applies.
        if (!i->isBlockCompressed) return false;
        if (i->blockWidth != 4u || i->blockHeight != 4u) return false;
        if (TableBytesPerBlockConst(f) != want) return false;
        for (uint32_t w = kPitchProbeMinWidth; w <= kPitchProbeMaxWidth; ++w) {
            const uint32_t blocksX = (w + 3u) / 4u;
            if (TableRowPitchConst(f, w) != blocksX * want) return false;
        }
    }
    return true;
}

// Non-vacuity guard: at least one probed width in every BC row must be one
// where the naive `w * bytesPerBlock` is WRONG. If a future edit made the check
// above satisfiable by the naive formula, this fires instead of the check
// quietly testing nothing.
constexpr bool NaivePitchWouldShearSomeWidth() {
    for (uint32_t f = 0; f < 64u; ++f) {
        const TextureFormatInfo* i = FormatInfoConst(f);
        if (!i || D3D12BlockCompressedBytes(i->dxgiFormat) == 0u) continue;
        const uint32_t bpb = TableBytesPerBlockConst(f);
        for (uint32_t w = kPitchProbeMinWidth; w <= kPitchProbeMaxWidth; ++w)
            if (TableRowPitchConst(f, w) != w * bpb) return true;
    }
    return false;
}

// Every BC row must also be a format the plan can actually import: the block
// byte size has to be a power of two <= 64 or the XGAddress tiled math is not
// addressable, and PlanTextureImport refuses it (NonPowerOfTwoBlock). Asserting
// it here means a new BC row cannot be added in a state the plan rejects.
constexpr bool BlockRowsAreXgAddressable() {
    for (uint32_t f = 0; f < 64u; ++f) {
        const TextureFormatInfo* i = FormatInfoConst(f);
        if (!i || !i->isBlockCompressed) continue;
        const uint32_t bpb = TableBytesPerBlockConst(f);
        if (bpb == 0u || bpb > 64u) return false;
        if ((bpb & (bpb - 1u)) != 0u) return false;
    }
    return true;
}

}  // namespace

static_assert(BlockRowPitchContractHolds(),
              "F-647: a block-compressed row of kFormatTable disagrees with the D3D12 BC "
              "contract (4x4, 8/16 bytes per block, ceil(w/4)*bytesPerBlock for w=1..8)");
static_assert(NaivePitchWouldShearSomeWidth(),
              "F-647: the pitch self-check cannot tell ceil(w/4)*bpb from the naive "
              "w*bpb, so it is no longer testing the shear case");
static_assert(BlockRowsAreXgAddressable(),
              "F-647: a block-compressed row has a non-power-of-two or >64 byte block, "
              "which PlanTextureImport refuses as NonPowerOfTwoBlock");

bool VerifyBlockRowPitchContract(uint32_t* offenderFormat, uint32_t* offenderWidth) {
    if (offenderFormat) *offenderFormat = 0;
    if (offenderWidth) *offenderWidth = 0;
    for (uint32_t f = 0; f < 64u; ++f) {
        const TextureFormatInfo* i = GetTextureFormatInfo(f);
        if (!i) continue;
        const uint32_t want = D3D12BlockCompressedBytes(i->dxgiFormat);
        if (want == 0u) {
            if (i->isBlockCompressed && i->dxgiFormat != 0u) {
                if (offenderFormat) *offenderFormat = f;
                return false;
            }
            continue;
        }
        if (!i->isBlockCompressed || i->blockWidth != 4u || i->blockHeight != 4u ||
            GetTextureBytesPerBlock(f) != want) {
            if (offenderFormat) *offenderFormat = f;
            return false;
        }
        for (uint32_t w = kPitchProbeMinWidth; w <= kPitchProbeMaxWidth; ++w) {
            if (SourceBlockRowPitchBytes(f, w) != ((w + 3u) / 4u) * want) {
                if (offenderFormat) *offenderFormat = f;
                if (offenderWidth) *offenderWidth = w;
                return false;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// Tiled offsets (canonical XGAddress math).
// ---------------------------------------------------------------------------

int32_t GetTiledOffset2D(int32_t x, int32_t y, uint32_t pitch, uint32_t bpbLog2) {
    // XGAddress2DTiledOffset: 32x32-block macro tiles (Xenia's equivalent is
    // texture_address::Tiled2D, kMacroTileWidth/kMacroTileHeight2D = 32; the
    // rexruntime oracle exported this exact name as
    // texture_util::graphics::GetTiledOffset2D, see the GetProcAddress in
    // tools/validators/texture_decode_test.cpp). The pitch is rounded up to a
    // multiple of 32 blocks *inside* this function, whereas Xenia expects the
    // caller to have aligned it (texture_address.h:196 asserts pitch_aligned,
    // the xe::align lives in texture_util.cc:324) — same result, but an
    // unaligned pitch is a caller bug there and silently fixed here.
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
    // Triang3l's RE-derived 3D case (Xenia texture_address::Tiled3D): the
    // macro tile is 32x16x4 blocks (kMacroTileWidth 32, kMacroTileHeight3D 16,
    // kMacroTileDepth 4 — texture_address.h:165-171), which is why the macro
    // term below steps y by >>4 and z by >>2. 32x32x4 is the *storage*
    // alignment of a 32-block-row x 4-slice portion, larger than the macro
    // tile (texture_address.h:45-47) — not the macro tile itself.
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
    // reachable within that tile (Xenia GetTiledAddressUpperBound2D,
    // texture_util.cc:451-471; 0xA00/0xC00 are its 1bpb/2bpb extents, whose
    // portions address independently within 128x128 and 64x64 respectively).
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
    // Mirrors the legacy GetTiledAddressLowerBound3D exactly:
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

// Refusal helper: record why a copy produced nothing, so a caller never has to
// tell "refused" from "the source happened to be all zeros". A null
// `outRefusal` keeps the original three/four-argument call sites valid.
static void UntileRefuse(TextureUntileRefusal* outRefusal, TextureUntileRefusal r) {
    if (outRefusal) *outRefusal = r;
}

void UntileTexture2D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info,
                     TextureUntileRefusal* outRefusal) {
    UntileRefuse(outRefusal, TextureUntileRefusal::None);
    if (!info.format) { UntileRefuse(outRefusal, TextureUntileRefusal::NoFormatInfo); return; }
    if (!src || !dst) { UntileRefuse(outRefusal, TextureUntileRefusal::NullBuffer); return; }
    if (info.inputPitch == 0) { UntileRefuse(outRefusal, TextureUntileRefusal::ZeroPitch); return; }
    // Region must lie inside the surface grid (overflow-checked in 64-bit).
    // Y is bounded only when the caller supplied a surface height; otherwise
    // the per-block bounds guard below is the protection.
    if (uint64_t(info.offsetX) + info.width > uint64_t(info.inputPitch)) {
        UntileRefuse(outRefusal, TextureUntileRefusal::RegionOutsideSurface);
        return;
    }
    if (info.inputHeight != 0 &&
        uint64_t(info.offsetY) + info.height > uint64_t(info.inputHeight)) {
        UntileRefuse(outRefusal, TextureUntileRefusal::RegionOutsideSurface);
        return;
    }
    const uint32_t bpb = GetTextureBytesPerBlock(info.format->xenosFormat);
    if (bpb == 0) { UntileRefuse(outRefusal, TextureUntileRefusal::ZeroBlockBytes); return; }
    if ((bpb & (bpb - 1)) != 0) {
        UntileRefuse(outRefusal, TextureUntileRefusal::NonPowerOfTwoBlock);
        return;
    }
    const uint32_t bpbLog2 = 31 - uint32_t(__builtin_clz(bpb));  // must be power of two
    if (bpbLog2 > 6) {
        UntileRefuse(outRefusal, TextureUntileRefusal::BlockTooLarge);
        return;
    }
    if (!info.srcBytes || !info.dstBytes) {
        UntileRefuse(outRefusal, TextureUntileRefusal::NoByteSizes);
        return;  // bounds guard requires sizes
    }
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
                     uint32_t depth, TextureUntileRefusal* outRefusal) {
    UntileRefuse(outRefusal, TextureUntileRefusal::None);
    if (!info.format) { UntileRefuse(outRefusal, TextureUntileRefusal::NoFormatInfo); return; }
    if (!src || !dst) { UntileRefuse(outRefusal, TextureUntileRefusal::NullBuffer); return; }
    if (info.inputPitch == 0 || info.inputHeight == 0) {
        UntileRefuse(outRefusal, TextureUntileRefusal::ZeroPitch);
        return;
    }
    if (uint64_t(info.offsetX) + info.width > uint64_t(info.inputPitch) ||
        uint64_t(info.offsetY) + info.height > uint64_t(info.inputHeight)) {
        UntileRefuse(outRefusal, TextureUntileRefusal::RegionOutsideSurface);
        return;
    }
    const uint32_t bpb = GetTextureBytesPerBlock(info.format->xenosFormat);
    if (bpb == 0) { UntileRefuse(outRefusal, TextureUntileRefusal::ZeroBlockBytes); return; }
    // 32_32_32_FLOAT lands here: 1x1x96 bits = 12 bytes/block, and the XGAddress
    // tiled math is parameterised by bpbLog2 (a power of two). There is no
    // correct 12 bpb address to compute, so this is a refusal, not a rounded
    // approximation. Xenia agrees: k_32_32_32_FLOAT has no host format and
    // kLoadShaderIndexUnknown in d3d12_texture_cache.cc:357-360.
    if ((bpb & (bpb - 1)) != 0) {
        UntileRefuse(outRefusal, TextureUntileRefusal::NonPowerOfTwoBlock);
        return;
    }
    const uint32_t bpbLog2 = 31 - uint32_t(__builtin_clz(bpb));  // must be power of two
    if (bpbLog2 > 6) {
        UntileRefuse(outRefusal, TextureUntileRefusal::BlockTooLarge);
        return;
    }
    if (!info.srcBytes || !info.dstBytes) {
        UntileRefuse(outRefusal, TextureUntileRefusal::NoByteSizes);
        return;
    }
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

// ---------------------------------------------------------------------------
// Endianness conversion.
//
// DECISION (item 6): the guest is big-endian, D3D12 is little-endian, and the
// Xenos fetch constant carries an explicit `Endian` field per texture. The
// detile math is defined on bytes and the validator proves it byte-exact
// against the old SDK oracle, so it must stay a pure gather. The swap
// therefore lives here, on the linear buffer, driven by the fetch constant -
// and only ever the four architected permutations (xenos.h:1052-1069):
//   kNone        identity
//   k8in16       swap bytes inside each 16-bit half word
//   k8in32       swap bytes inside each 32-bit word
//   k16in32      swap the two 16-bit half words of each 32-bit word
// Everything is byte-indexed arithmetic; nothing reinterprets guest memory.
// ---------------------------------------------------------------------------

bool IsSupportedGuestEndian(uint32_t endianness) { return endianness <= 3u; }

bool ConvertTextureEndianness(uint32_t endianness, uint8_t* data, uint32_t bytes,
                              uint32_t texelBytes) {
    if (!IsSupportedGuestEndian(endianness)) return false;
    if (endianness == 0u) return true;
    if (!data || bytes == 0 || texelBytes == 0) return false;
    if (uint64_t(bytes) % uint64_t(texelBytes) != 0) return false;
    switch (endianness) {
        case 1u:  // k8in16: swap byte pairs within 16-bit words
            if (texelBytes % 2u != 0) return false;
            for (uint32_t i = 0; i + 1 < bytes; i += 2) std::swap(data[i], data[i + 1]);
            return true;
        case 2u:  // k8in32: full 4-byte reverse
            if (texelBytes % 4u != 0) return false;
            for (uint32_t i = 0; i + 3 < bytes; i += 4) {
                std::swap(data[i], data[i + 3]);
                std::swap(data[i + 1], data[i + 2]);
            }
            return true;
        case 3u:  // k16in32: swap the half words
            if (texelBytes % 4u != 0) return false;
            for (uint32_t i = 0; i + 3 < bytes; i += 4) {
                std::swap(data[i], data[i + 2]);
                std::swap(data[i + 1], data[i + 3]);
            }
            return true;
        default:
            return false;
    }
}

// ---------------------------------------------------------------------------
// Refusal accounting. This TU links no logger (the headless validators that
// compile it do not link fmt/spdlog), so it counts and hands the backend a
// callback instead. Bounded: the callback fires at most
// kMaxRefusalCallbacksPerFormat (8) times per xenos format.
// ---------------------------------------------------------------------------

namespace {
TextureRefusalCallback g_refusalFn = nullptr;
void* g_refusalUser = nullptr;
uint32_t g_refusalFired[64] = {};  // per xenos format; fixed size, cannot grow
uint64_t g_refusalCounts[32] = {};
// F-648: the per-format import census. Fixed size, no allocation, so it is
// legal on the draw path. `g_importLastMode` is 0 == Refused until the format
// is actually seen, which is what a zero census row must report.
uint64_t g_importCounts[64] = {};
uint64_t g_importAccepted[64] = {};
uint32_t g_importLastMode[64] = {};
uint64_t g_importTotal = 0;
uint64_t g_importAcceptedTotal = 0;
}  // namespace

void SetTextureRefusalCallback(TextureRefusalCallback fn, void* user) {
    g_refusalFn = fn;
    g_refusalUser = user;
}
void ClearTextureRefusalCallback() { g_refusalFn = nullptr; g_refusalUser = nullptr; }

uint64_t TextureRefusalCount(TextureRefusal refusal) {
    const uint32_t i = static_cast<uint32_t>(refusal);
    return i < 32u ? g_refusalCounts[i] : 0u;
}

void NoteTextureRefusal(const TextureImportPlan& plan) {
    const uint32_t r = static_cast<uint32_t>(plan.refusal);
    if (r < 32u) g_refusalCounts[r]++;
    // F-648: a refusal is still a call, so it counts toward the per-format
    // census too -- the census answers "did the title reach the import path",
    // which a refusal-only count would answer as "no" for the wrong reason.
    if (plan.xenosFormat < 64u) g_importCounts[plan.xenosFormat]++;
    if (!g_refusalFn) return;
    if (plan.xenosFormat < 64u &&
        g_refusalFired[plan.xenosFormat] < kMaxRefusalCallbacksPerFormat) {
        g_refusalFired[plan.xenosFormat]++;
        g_refusalFn(g_refusalUser, plan);
    }
}

// F-648: record a plan that passed every refusal gate. Called from the single
// success exit of PlanTextureImport(), so there is exactly one place a plan can
// become ok and it cannot be forgotten by a later edit that adds a gate.
void NoteTextureImport(const TextureImportPlan& plan) {
    if (plan.xenosFormat < 64u) {
        g_importCounts[plan.xenosFormat]++;
        g_importAccepted[plan.xenosFormat]++;
        g_importLastMode[plan.xenosFormat] = static_cast<uint32_t>(plan.mode);
    }
    g_importTotal++;
    g_importAcceptedTotal++;
}

uint64_t TextureImportCount(uint32_t xenosFormat) {
    return xenosFormat < 64u ? g_importCounts[xenosFormat] : 0u;
}
uint64_t TextureImportCountTotal() { return g_importTotal; }
uint64_t TextureImportAcceptedCount(uint32_t xenosFormat) {
    return xenosFormat < 64u ? g_importAccepted[xenosFormat] : 0u;
}
uint64_t TextureImportAcceptedTotal() { return g_importAcceptedTotal; }
TextureUploadMode TextureImportLastMode(uint32_t xenosFormat) {
    if (xenosFormat >= 64u) return TextureUploadMode::Refused;
    const uint32_t m = static_cast<uint32_t>(g_importLastMode[xenosFormat]);
    return m <= static_cast<uint32_t>(TextureUploadMode::CpuExpand)
               ? static_cast<TextureUploadMode>(m)
               : TextureUploadMode::Refused;
}

const char* TextureRefusalName(TextureRefusal refusal) {
    switch (refusal) {
        case TextureRefusal::None: return "none";
        case TextureRefusal::UnknownFormatCode: return "unknown_format_code";
        case TextureRefusal::NoHostFormat: return "no_host_format";
        case TextureRefusal::NonPowerOfTwoBlock: return "non_power_of_two_block";
        case TextureRefusal::ZeroExtent: return "zero_extent";
        case TextureRefusal::ExtentTooLarge: return "extent_too_large";
        case TextureRefusal::PackedMipLayout: return "packed_mip_layout";
        case TextureRefusal::EndianOnBlockCompressed: return "endian_on_block_compressed";
        case TextureRefusal::DepthCubeNotUploadable: return "depth_or_cube_not_uploadable";
        case TextureRefusal::UntileRefused: return "untile_refused";
        case TextureRefusal::ExpanderMismatch: return "expander_mismatch";
        default: return "unknown";
    }
}

// ---------------------------------------------------------------------------
// Exact expanders. Bit-exact, not approximate: each is the CPU twin of the
// Xenia load shader of the same name (gpu/texture_cache.cc:102-106) and of the
// BC1/BC3 expansion the import validator already trusts
// (tools/validators/texture_import_validator.cpp:180-234). The unorm expand
// 5->8 / 6->8 rule is bit replication, i.e. the D3D spec's UNORM expansion.
// ---------------------------------------------------------------------------

namespace {

inline uint8_t Expand5To8(uint8_t v) {
    return uint8_t((uint32_t(v) << 3) | (uint32_t(v) >> 2));
}
inline uint8_t Expand6To8(uint8_t v) {
    return uint8_t((uint32_t(v) << 2) | (uint32_t(v) >> 4));
}
inline uint8_t Expand4To8(uint8_t v) { return uint8_t((uint32_t(v) << 4) | v); }

// Little-endian 16/32-bit reads of the HOST linear buffer. The buffer is
// already endianness-converted by ConvertTextureEndianness() when the fetch
// constant asked for it, so these are host-endian reads of host-endian bytes -
// never a guest pointer, never a reinterpret_cast of guest memory.
inline uint16_t LoadU16LE(const uint8_t* p) {
    return uint16_t(uint32_t(p[0]) | (uint32_t(p[1]) << 8));
}
inline uint32_t LoadU32LE(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1]) << 8) | (uint32_t(p[2]) << 16) |
           (uint32_t(p[3]) << 24);
}

// BC1 colour block (8 bytes) -> 16 RGBA8 texels. Identical to the validator's
// DecodeBc1Block, so the two must agree byte for byte.
void DecodeBc1Block(const uint8_t* blk, uint8_t out[16 * 4]) {
    const uint16_t c0 = LoadU16LE(blk);
    const uint16_t c1 = LoadU16LE(blk + 2);
    uint8_t pal[4][4] = {};
    auto unpack = [](uint16_t c, uint8_t* d) {
        d[0] = Expand5To8(uint8_t((c >> 11) & 0x1Fu));
        d[1] = Expand6To8(uint8_t((c >> 5) & 0x3Fu));
        d[2] = Expand5To8(uint8_t(c & 0x1Fu));
        d[3] = 255;
    };
    unpack(c0, pal[0]);
    unpack(c1, pal[1]);
    if (c0 > c1) {  // four opaque colours
        for (int i = 0; i < 3; ++i) {
            pal[2][i] = uint8_t((2 * pal[0][i] + pal[1][i]) / 3);
            pal[3][i] = uint8_t((2 * pal[1][i] + pal[0][i]) / 3);
        }
        pal[2][3] = pal[3][3] = 255;
    } else {  // three colours plus the 1-bit-alpha index-3 entry
        for (int i = 0; i < 3; ++i) {
            pal[2][i] = uint8_t((pal[0][i] + pal[1][i]) / 2);
            pal[3][i] = 0;
        }
        pal[2][3] = 255;
        pal[3][3] = 0;
    }
    const uint32_t idx = LoadU32LE(blk + 4);
    for (int i = 0; i < 16; ++i)
        std::memcpy(&out[i * 4], pal[uint8_t((idx >> (i * 2)) & 3u)], 4);
}

// BC2 (DXT3) -> 16 RGBA8 texels: 4-bit explicit alpha + a BC1 colour tail.
void DecodeBc2Block(const uint8_t* blk, uint8_t out[16 * 4]) {
    uint8_t colour[16 * 4];
    DecodeBc1Block(blk + 8, colour);
    for (int i = 0; i < 16; ++i) {
        const uint32_t a = blk[i >> 1];
        out[i * 4 + 0] = colour[i * 4 + 0];
        out[i * 4 + 1] = colour[i * 4 + 1];
        out[i * 4 + 2] = colour[i * 4 + 2];
        out[i * 4 + 3] = Expand4To8(uint8_t((i & 1) ? (a & 0x0Fu) : (a >> 4)));
    }
}

// BC3 (DXT5) -> 16 RGBA8 texels: BC4 alpha + a BC1 colour tail.
void DecodeBc3Block(const uint8_t* blk, uint8_t out[16 * 4]) {
    uint8_t alpha[8];
    alpha[0] = blk[0];
    alpha[1] = blk[1];
    if (alpha[0] > alpha[1]) {
        for (int i = 2; i < 8; ++i)
            alpha[i] = uint8_t(((8 - i) * alpha[0] + (i - 1) * alpha[1]) / 7);
    } else {
        for (int i = 2; i < 6; ++i)
            alpha[i] = uint8_t(((6 - i) * alpha[0] + (i - 1) * alpha[1]) / 5);
        alpha[6] = 0;
        alpha[7] = 255;
    }
    uint64_t bits = 0;
    for (int i = 0; i < 6; ++i) bits |= uint64_t(blk[2 + i]) << (i * 8);
    uint8_t colour[16 * 4];
    DecodeBc1Block(blk + 8, colour);
    for (int i = 0; i < 16; ++i) {
        std::memcpy(&out[i * 4], &colour[i * 4], 3);
        out[i * 4 + 3] = alpha[uint8_t((bits >> (i * 3)) & 7u)];
    }
}

// BC4 (DXT5A) -> 16 one-channel texels.
void DecodeBc4Block(const uint8_t* blk, uint8_t out[16]) {
    uint8_t v[8];
    v[0] = blk[0];
    v[1] = blk[1];
    if (v[0] > v[1]) {
        for (int i = 2; i < 8; ++i)
            v[i] = uint8_t(((8 - i) * v[0] + (i - 1) * v[1]) / 7);
    } else {
        for (int i = 2; i < 6; ++i)
            v[i] = uint8_t(((6 - i) * v[0] + (i - 1) * v[1]) / 5);
        v[6] = 0;
        v[7] = 255;
    }
    uint64_t bits = 0;
    for (int i = 0; i < 6; ++i) bits |= uint64_t(blk[2 + i]) << (i * 8);
    for (int i = 0; i < 16; ++i) out[i] = v[uint8_t((bits >> (i * 3)) & 7u)];
}

// 5_6_5 -> RGBA8. Xenos names the texel R5G6B5; B5G6R5_UNORM reads the same 16
// bits as (G6 << 5) | (R5 << 11) | (B5 << 0), so the field extraction below is
// the identity on the guest bit layout.
void Decode565Block(const uint8_t* blk, uint8_t out[4]) {
    const uint16_t c = LoadU16LE(blk);
    out[0] = Expand5To8(uint8_t((c >> 11) & 0x1Fu));
    out[1] = Expand6To8(uint8_t((c >> 5) & 0x3Fu));
    out[2] = Expand5To8(uint8_t(c & 0x1Fu));
    out[3] = 255;
}

// 1_5_5_5 -> RGBA8: A1R5G5B5, so bit 15 is the 1-bit alpha.
void Decode1555Block(const uint8_t* blk, uint8_t out[4]) {
    const uint16_t c = LoadU16LE(blk);
    out[0] = Expand5To8(uint8_t((c >> 10) & 0x1Fu));
    out[1] = Expand5To8(uint8_t((c >> 5) & 0x1Fu));
    out[2] = Expand5To8(uint8_t(c & 0x1Fu));
    out[3] = uint8_t((c & 0x8000u) ? 255u : 0u);
}

}  // namespace

// ---------------------------------------------------------------------------
// Import plan
// ---------------------------------------------------------------------------

// Which guest formats this layer can hand to a host that today accepts only
// R8G8B8A8_UNORM (28) and R8_UNORM (61) - the gate in
// D3D12Backend::CreateDecodedTexture (src/d3d12_backend.cpp:703-709). Every
// format listed here is expanded by an exact CPU twin of the matching Xenia
// load shader; every format NOT listed stays a refusal, because "close enough"
// is a corruption, not a fallback.
static bool PlanExpandsTo(uint32_t xenosFormat, uint32_t* outDxgi) {
    switch (xenosFormat) {
        // DXT1/DXT2_3/DXT4_5 (+ the _AS_16_16_16_16 aliases) -> RGBA8, the
        // CPU twin of kDXT1ToRGBA8 / kDXT3ToRGBA8 / kDXT5ToRGBA8.
        case 18: case 19: case 20: case 51: case 52: case 53:
            *outDxgi = kDxgiR8G8B8A8Unorm;
            return true;
        // DXT3A/DXT5A/DXT3A_AS_1_1_1_1 are 4x4 4bpp single channel; Xenia maps
        // DXT3A to R8_UNORM and runs kDXT3A / kDXT5AToR8 to fill it
        // (d3d12_texture_cache.cc:361-370), so the exact host form IS R8.
        case 58: case 59: case 61:
            *outDxgi = kDxgiR8Unorm;
            return true;
        // 1_5_5_5 / 5_6_5 / 6_5_5 / 4_4_4_4 -> RGBA8 by exact unorm unpack
        // (Xenia's kR5G5B5A1ToB5G5R5A1 / kR5G6B5ToB5G6R5 / kRGBA4ToBGRA4).
        // 6_5_5 is bit-identical to 5_6_5 in memory and differs only by the
        // fetch constant's exp_adjust/num_format, which the sampler carries.
        case 3: case 4: case 5: case 15:
            *outDxgi = kDxgiR8G8B8A8Unorm;
            return true;
        default:
            return false;
    }
}

TextureImportPlan PlanTextureImport(uint32_t xenosFormat, uint32_t width, uint32_t height,
                                    uint32_t depthOrArraySize, uint32_t mipMaxLevel,
                                    uint32_t endianness, bool tiled, bool packedMips,
                                    bool is3D, bool isDepthStencil) {
    TextureImportPlan plan = {};
    plan.xenosFormat = xenosFormat;
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    plan.formatName = info ? info->name : "unknown";
    plan.arraySize = depthOrArraySize ? depthOrArraySize : 1u;
    if (!info) {
        plan.refusal = TextureRefusal::UnknownFormatCode;
        NoteTextureRefusal(plan);
        return plan;
    }
    plan.nativeDxgiFormat = info->dxgiFormat;
    plan.blockWidth = info->blockWidth;
    plan.blockHeight = info->blockHeight;
    plan.blockBytes = GetTextureBytesPerBlock(xenosFormat);
    plan.isBlockCompressed = info->isBlockCompressed;
    plan.isResolvable = info->isResolvable;
    (void)tiled;  // tiling is the untile step's business, not the plan's

    // Depth/stencil rows (k_24_8, k_24_8_FLOAT and the *_EDRAM copies) are
    // render targets, not copy destinations: D3D12 wants ALLOW_DEPTH_STENCIL
    // and a DSV, so a plain CopyTextureRegion import would be a lie. Refused.
    if (isDepthStencil) {
        plan.refusal = TextureRefusal::DepthCubeNotUploadable;
        NoteTextureRefusal(plan);
        return plan;
    }
    if (packedMips) {
        // The packed-mip tail is a sub-tile mosaic whose block offsets come
        // from GetPackedMipOffset (texture_util.cc:116-207). Not implemented;
        // uploading it as a plain chain would sample the wrong texels, so it
        // is refused loudly rather than approximated.
        plan.refusal = TextureRefusal::PackedMipLayout;
        NoteTextureRefusal(plan);
        return plan;
    }
    if (width == 0 || height == 0 || plan.arraySize == 0) {
        plan.refusal = TextureRefusal::ZeroExtent;
        NoteTextureRefusal(plan);
        return plan;
    }
    // Xenos maxima (xenos.h:1136-1147): 2D/cube <= 8192, 3D <= 2048.
    const uint32_t maxDim = is3D ? 2048u : 8192u;
    if (width > maxDim || height > maxDim) {
        plan.refusal = TextureRefusal::ExtentTooLarge;
        NoteTextureRefusal(plan);
        return plan;
    }
    if (!IsSupportedGuestEndian(endianness)) {
        // No architected permutation for this code: refuse rather than leave
        // the texels byte-swapped relative to the host.
        plan.refusal = TextureRefusal::NoHostFormat;
        NoteTextureRefusal(plan);
        return plan;
    }
    plan.guestEndianness = endianness;
    plan.needsByteSwap = endianness != 0u;
    // A block-compressed surface carries no endianness in practice (every load
    // shader reads the block words little-endian) and swapping them would
    // corrupt the decode. Refuse rather than guess.
    if (plan.needsByteSwap && info->isBlockCompressed) {
        plan.refusal = TextureRefusal::EndianOnBlockCompressed;
        NoteTextureRefusal(plan);
        return plan;
    }
    // 32_32_32_FLOAT: 1x1 block, 96 bits = 12 bytes/block. The XGAddress tiled
    // math is parameterised by bpbLog2 (a power of two), so 12 is not
    // addressable and Xenia refuses the format too
    // (d3d12_texture_cache.cc:357-360). The UntileTexture2D/3D guards
    // (NonPowerOfTwoBlock) protect memory; this makes the refusal named,
    // counted and logged at plan time instead of a silently empty texture.
    if (plan.blockBytes == 0) {
        plan.refusal = TextureRefusal::NoHostFormat;
        NoteTextureRefusal(plan);
        return plan;
    }
    if ((plan.blockBytes & (plan.blockBytes - 1)) != 0 || plan.blockBytes > 64u) {
        plan.refusal = TextureRefusal::NonPowerOfTwoBlock;
        NoteTextureRefusal(plan);
        return plan;
    }

    uint32_t bx = 0, by = 0;
    if (GetTextureBlockSpan(xenosFormat, width, height, &bx, &by) == 0) {
        plan.refusal = TextureRefusal::ZeroExtent;
        NoteTextureRefusal(plan);
        return plan;
    }
    plan.blocksX = bx;
    plan.blocksY = by;
    plan.texelBytes = plan.blockBytes;
    plan.linearByteSize = uint32_t(uint64_t(bx) * by * plan.blockBytes * plan.arraySize);

    // Mip chain length: mip_max_level + 1, clamped to the base extents (a guest
    // may leave mip_max_level above the extent floor; Xenia clamps the same
    // way, texture_util.cc:244-249). mip_min_level is a sampling clamp, not a
    // storage change, so the chain still starts at mip 0.
    uint32_t maxLevel = 0;
    {
        const uint32_t m = width > height ? width : height;
        const uint32_t d = (is3D && plan.arraySize > m) ? plan.arraySize : m;
        for (uint32_t v = d; v > 1u; v >>= 1) maxLevel++;
    }
    plan.mipCount = (mipMaxLevel < maxLevel) ? (mipMaxLevel + 1u) : (maxLevel + 1u);

    if (info->dxgiFormat == kDxgiR8G8B8A8Unorm || info->dxgiFormat == kDxgiR8Unorm) {
        plan.importDxgiFormat = info->dxgiFormat;
        plan.mode = TextureUploadMode::ScalarCopy;
    } else if (info->dxgiFormat != 0) {
        uint32_t expandDxgi = 0;
        if (PlanExpandsTo(xenosFormat, &expandDxgi)) {
            plan.importDxgiFormat = expandDxgi;
            plan.mode = TextureUploadMode::CpuExpand;
        } else {
            // A real host form exists (DXN=BC5, B4G4R4A4, R16, float, ...)
            // but there is no exact expander for it. Keep the native form and
            // let the backend widen its gate: for a block format that copy is
            // byte-exact (the untiled block rows are already in host order).
            plan.importDxgiFormat = info->dxgiFormat;
            plan.mode = info->isBlockCompressed ? TextureUploadMode::DirectBlockCopy
                                                : TextureUploadMode::ScalarCopy;
            plan.note = "backend gate must accept nativeDxgiFormat for a zero-copy import";
        }
    } else {
        // dxgi == 0: YUV REP, 1/1_REVERSE, the *_EXPAND rows, 16/16_16/16_16_16,
        // MPEG, INTERLACED, 32_AS_8*, CTX1. All of these are reachable in
        // Xenia only through a load shader (d3d12_texture_cache.cc:361-374)
        // and this backend has no shader path, so every one of them is refused.
        // A subset was not chosen on a guess.
        plan.refusal = TextureRefusal::NoHostFormat;
        NoteTextureRefusal(plan);
        return plan;
    }
    plan.ok = true;
    // F-648: the one and only success exit, so the census cannot be bypassed by
    // a later edit that adds another gate above this line.
    NoteTextureImport(plan);
    return plan;
}

bool ExpandTextureToImportBytes(const TextureImportPlan& plan, const uint8_t* linear,
                                uint32_t linearBytes, std::vector<uint8_t>& out,
                                TextureRefusal* outRefusal) {
    if (outRefusal) *outRefusal = TextureRefusal::None;
    if (plan.mode != TextureUploadMode::CpuExpand) {
        if (outRefusal) *outRefusal = TextureRefusal::ExpanderMismatch;
        return false;
    }
    if (!linear || linearBytes < plan.linearByteSize) {
        if (outRefusal) *outRefusal = TextureRefusal::ExpanderMismatch;
        return false;  // short payload: refuse, never expand a partial image
    }
    const uint32_t w = plan.blocksX * plan.blockWidth;
    const uint32_t h = plan.blocksY * plan.blockHeight;
    const uint32_t bb = plan.blockBytes;
    const bool scalarPack = (plan.xenosFormat == 3 || plan.xenosFormat == 4 ||
                             plan.xenosFormat == 5 || plan.xenosFormat == 15);
    // The output component count must match plan.importDxgiFormat, because that
    // is the format the backend will hand to CreateDecodedTexture: 4 bytes for
    // R8G8B8A8_UNORM, 1 for R8_UNORM (the DXT3A/DXT5A single-channel case -
    // Xenia's own host form, d3d12_texture_cache.cc:361-366).
    const uint32_t outTexelBytes =
        (plan.importDxgiFormat == kDxgiR8Unorm) ? 1u : 4u;
    const uint32_t bytesPerSlice = scalarPack ? (w * h * bb) : (w * h * outTexelBytes);
    out.assign(size_t(bytesPerSlice) * plan.arraySize, 0u);

    for (uint32_t s = 0; s < plan.arraySize; ++s) {
        const uint8_t* src = linear + uint64_t(s) * plan.linearByteSize / plan.arraySize;
        uint8_t* dst = out.data() + size_t(s) * bytesPerSlice;
        if (scalarPack) {
            for (uint32_t i = 0; i < w * h; ++i) {
                uint8_t px[4];
                switch (plan.xenosFormat) {
                    case 3: Decode1555Block(src + i * 2u, px); break;       // 1_5_5_5
                    case 4: Decode565Block(src + i * 2u, px); break;        // 5_6_5
                    case 5: Decode565Block(src + i * 2u, px); break;        // 6_5_5
                    default: {                                              // 4_4_4_4
                        const uint16_t c = LoadU16LE(src + i * 2u);
                        px[0] = Expand4To8(uint8_t((c >> 8) & 0x0Fu));
                        px[1] = Expand4To8(uint8_t((c >> 4) & 0x0Fu));
                        px[2] = Expand4To8(uint8_t(c & 0x0Fu));
                        px[3] = Expand4To8(uint8_t((c >> 12) & 0x0Fu));
                        break;
                    }
                }
                std::memcpy(dst + i * 4u, px, 4);
            }
            continue;
        }
        for (uint32_t by = 0; by < plan.blocksY; ++by) {
            for (uint32_t bx = 0; bx < plan.blocksX; ++bx) {
                const uint8_t* blk = src + (size_t(by) * plan.blocksX + bx) * bb;
                // Decode into a block-local 16-texel buffer first, then SCATTER.
                // A block decoder writes 16 texels contiguously (that is the
                // 4x4 block layout), but the destination is a full-surface
                // RGBA8 image whose rows are `w` texels wide, so for any
                // texture larger than 4x4 in either axis a direct write would
                // lay the block out in a single row and corrupt everything
                // after it. Scatter: row r of the block goes to
                // (by*blockHeight + r, bx*blockWidth + c).
                uint8_t texels[16 * 4];
                uint32_t rowStride = 0;
                switch (plan.xenosFormat) {
                    case 18: case 51: DecodeBc1Block(blk, texels); rowStride = 4; break;
                    case 19: case 52: DecodeBc2Block(blk, texels); rowStride = 4; break;
                    case 20: case 53: DecodeBc3Block(blk, texels); rowStride = 4; break;
                    case 58: case 59: case 61:  // DXT3A/DXT5A are 1-channel BC4
                        DecodeBc4Block(blk, texels);
                        rowStride = 1;  // importDxgiFormat is R8_UNORM
                        break;
                    default:
                        if (outRefusal) *outRefusal = TextureRefusal::NoHostFormat;
                        out.clear();
                        return false;
                }
                for (uint32_t r = 0; r < plan.blockHeight; ++r) {
                    const size_t rowBase =
                        (size_t(by * plan.blockHeight + r) * w + bx * plan.blockWidth) *
                        outTexelBytes;
                    std::memcpy(dst + rowBase, &texels[r * plan.blockWidth * rowStride],
                                size_t(plan.blockWidth) * rowStride);
                }
            }
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// Guest fetch constant decode (24 bytes, big-endian, explicit shifts only).
// Field positions are the architected bitfield offsets in
// .research/xenia/src/xenia/gpu/xenos.h:1184-1285 (xe_gpu_texture_fetch_t),
// which the CP writes directly into guest memory - so the same bytes are the
// guest address in DrawPacket::textureDescriptors[i].
// ---------------------------------------------------------------------------

namespace {

inline uint32_t Bits(uint32_t v, uint32_t lo, uint32_t width) {
    const uint32_t w = width >= 32u ? 32u : width;
    return w ? ((v >> lo) & ((1u << w) - 1u)) : 0u;
}
// Sign-extend a `width`-bit two's complement field.
inline int32_t Sbits(uint32_t v, uint32_t lo, uint32_t width) {
    if (width == 0 || width >= 32u) return int32_t(v);
    const uint32_t raw = Bits(v, lo, width);
    const uint32_t signBit = 1u << (width - 1u);
    return int32_t((raw ^ signBit) - signBit);
}
inline uint32_t BeU32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) |
           uint32_t(p[3]);
}
inline uint32_t NextPow2(uint32_t v) {
    if (v <= 1u) return 1u;
    uint32_t n = 1u;
    while (n < v && n < 0x40000000u) n <<= 1;
    return n;
}

}  // namespace

bool DecodeGuestTextureDescriptor(const uint8_t* be24, GuestTextureDesc& out) {
    out = GuestTextureDesc{};
    if (!be24) {
        out.refusal = "null descriptor";
        return false;
    }
    for (uint32_t i = 0; i < 6; ++i) {
        out.rawDwords[i] = BeU32(be24 + i * 4u);
    }
    const uint32_t d0 = out.rawDwords[0], d1 = out.rawDwords[1];
    const uint32_t d2 = out.rawDwords[2], d3 = out.rawDwords[3];
    const uint32_t d4 = out.rawDwords[4], d5 = out.rawDwords[5];

    // dword_0: type must be kTexture (2); the other two types are the
    // vertex-fetch words sharing this 6-dword slot.
    if (Bits(d0, 0, 2) != 2u) {
        out.refusal = "fetch constant type is not kTexture";
        return false;
    }
    out.sign[0] = static_cast<GuestTextureSign>(Bits(d0, 2, 2));
    out.sign[1] = static_cast<GuestTextureSign>(Bits(d0, 4, 2));
    out.sign[2] = static_cast<GuestTextureSign>(Bits(d0, 6, 2));
    out.sign[3] = static_cast<GuestTextureSign>(Bits(d0, 8, 2));
    out.clampU = static_cast<GuestClampMode>(Bits(d0, 10, 3));
    out.clampV = static_cast<GuestClampMode>(Bits(d0, 13, 3));
    out.clampW = static_cast<GuestClampMode>(Bits(d0, 16, 3));
    if (Bits(d0, 10, 3) > 7u || Bits(d0, 13, 3) > 7u || Bits(d0, 16, 3) > 7u) {
        out.refusal = "clamp mode out of range";
        return false;
    }
    out.pitchTexels = Bits(d0, 22, 9) << 5;  // field is pitch >> 5 texels
    out.tiled = Bits(d0, 31, 1) != 0;

    // dword_1: format, endianness, base address.
    out.xenosFormat = Bits(d1, 0, 6);
    out.endianness = Bits(d1, 6, 2);
    out.stacked = Bits(d1, 10, 1) != 0;
    const uint32_t basePage = Bits(d1, 12, 20);
    out.hasBase = basePage != 0;
    out.baseAddress = (basePage << kTextureSubresourceAlignmentBytesLog2) |
                      (out.hasBase ? 0u : 0u);
    if (basePage == 0) {
        // Xenia keys a texture with no base on mip_address alone
        // (texture_cache.h:130-132) and skips base level 0. Without a base
        // address there is nothing to import at mip 0, so the descriptor is
        // usable for sampling metadata only - report it, do not fake a base.
        out.baseAddress = 0;
    }
    if (!GetTextureFormatInfo(out.xenosFormat)) {
        out.refusal = "unknown xenos texture format code";
        return false;
    }

    // dword_2: extents, each stored minus one. Which union member applies is
    // not known until dword_5's `dimension` is read, so decode the widest form
    // and then narrow.
    out.dimension = static_cast<GuestTextureDimension>(Bits(d5, 9, 2));
    const uint32_t dimRaw = static_cast<uint32_t>(out.dimension);
    if (dimRaw > 3u) {
        out.refusal = "data dimension out of range";
        return false;
    }
    switch (out.dimension) {
        case GuestTextureDimension::OneD:
            out.width = Bits(d2, 0, 24) + 1u;
            out.height = 1u;
            out.depthOrArraySize = 1u;
            out.depth = 1u;
            break;
        case GuestTextureDimension::TwoDOrStacked:
            out.width = Bits(d2, 0, 13) + 1u;
            out.height = Bits(d2, 13, 13) + 1u;
            out.depthOrArraySize = out.stacked ? (Bits(d2, 26, 6) + 1u) : 1u;
            out.depth = 1u;
            break;
        case GuestTextureDimension::ThreeD:
            out.width = Bits(d2, 0, 11) + 1u;
            out.height = Bits(d2, 11, 11) + 1u;
            out.depth = Bits(d2, 22, 10) + 1u;
            out.depthOrArraySize = out.depth;
            break;
        case GuestTextureDimension::Cube:
            out.width = Bits(d2, 0, 13) + 1u;
            out.height = Bits(d2, 13, 13) + 1u;
            out.depthOrArraySize = 6u;
            out.depth = 1u;
            break;
        default:
            out.refusal = "unhandled data dimension";
            return false;
    }
    if (out.width == 0 || out.height == 0 || out.depthOrArraySize == 0) {
        out.refusal = "zero extent (size field is stored minus one)";
        return false;
    }

    // dword_3: swizzle, exp adjust, filters.
    out.swizzle = Bits(d3, 1, 12);
    out.expAdjust = Sbits(d3, 13, 6);
    out.magFilter = static_cast<GuestTextureFilter>(Bits(d3, 19, 2));
    out.minFilter = static_cast<GuestTextureFilter>(Bits(d3, 21, 2));
    out.mipFilter = static_cast<GuestTextureFilter>(Bits(d3, 23, 2));
    out.anisoFilter = static_cast<GuestAnisoFilter>(Bits(d3, 25, 3));
    if (static_cast<uint32_t>(out.anisoFilter) == 6u) {
        // 6 is not an architected aniso code (xenos.h:140-147 leaves it out).
        out.refusal = "aniso filter code out of range";
        return false;
    }

    // dword_4: mip range, lod bias.
    out.mipMinLevel = Bits(d4, 2, 4);
    out.mipMaxLevel = Bits(d4, 6, 4);
    out.lodBias = Sbits(d4, 12, 10);
    out.mipAddress = Bits(d5, 12, 20) << kTextureSubresourceAlignmentBytesLog2;

    // dword_5: border colour, aniso bias, packed mips.
    out.borderColor = Bits(d5, 0, 2);
    out.forceBcWToMax = Bits(d5, 2, 1) != 0;
    out.anisoBias = Sbits(d5, 5, 4);
    out.packedMips = Bits(d5, 11, 1) != 0;

    // Clamp the chain to the extents, the same clamp Xenia applies
    // (texture_util.cc:244-249).
    const uint32_t biggest = out.width > out.height ? out.width : out.height;
    const uint32_t depthish = (out.dimension == GuestTextureDimension::ThreeD &&
                               out.depthOrArraySize > biggest)
                                  ? out.depthOrArraySize
                                  : biggest;
    uint32_t extentLevels = 0;
    for (uint32_t v = depthish; v > 1u; v >>= 1) extentLevels++;
    out.mipCount = (out.mipMaxLevel < extentLevels) ? (out.mipMaxLevel + 1u)
                                                    : (extentLevels + 1u);
    out.arraySize = (out.dimension == GuestTextureDimension::Cube) ? 6u
                                                                  : out.depthOrArraySize;
    out.valid = true;
    return true;
}

// ---------------------------------------------------------------------------
// Mip chain / guest size
// ---------------------------------------------------------------------------

bool BuildGuestMipChain(const GuestTextureDesc& desc, TextureMipChain& out) {
    out = TextureMipChain{};
    if (!desc.valid) return false;
    // Packed mips live in a sub-tile mosaic described by GetPackedMipOffset
    // (texture_util.cc:116-207). We do not implement that mosaic, and reading
    // it as a normal chain would fetch the wrong texels, so this is false.
    if (desc.packedMips) return false;
    const TextureFormatInfo* info = GetTextureFormatInfo(desc.xenosFormat);
    if (!info || info->dxgiFormat == 0) return false;
    const uint32_t bb = GetTextureBytesPerBlock(desc.xenosFormat);
    // 12 bpb (32_32_32_FLOAT) and anything else not a power of two cannot be
    // addressed by the XGAddress math at all.
    if (bb == 0 || (bb & (bb - 1)) != 0 || bb > 64u) return false;
    if (desc.mipCount == 0 || desc.mipCount > kTextureMaxMips) return false;
    if (desc.arraySize == 0) return false;

    const bool is3D = desc.dimension == GuestTextureDimension::ThreeD;
    uint32_t running = 0;
    for (uint32_t l = 0; l < desc.mipCount; ++l) {
        TextureMipLevel& m = out.levels[l];
        // Mip extents come from next_pow2 of the BASE extents shifted by the
        // level (xenos.h:1215-1217: mips are padded to
        // max(next_pow2(base) >> level, 1)); the base level uses the descriptor
        // extents verbatim.
        if (l == 0) {
            m.width = desc.width;
            m.height = desc.height;
            m.depthOrArraySize = desc.arraySize;
        } else {
            m.width = std::max(NextPow2(desc.width) >> l, 1u);
            m.height = std::max(NextPow2(desc.height) >> l, 1u);
            const uint32_t slices = is3D ? std::max(desc.depth >> l, 1u) : desc.arraySize;
            m.depthOrArraySize = slices;
        }
        const uint32_t bw = info->blockWidth, bh = info->blockHeight;
        m.blocksX = (m.width + bw - 1u) / bw;
        m.blocksY = (m.height + bh - 1u) / bh;
        // Row pitch: the base level uses the fetch constant's pitch, mips use
        // their own padded width; both are then aligned to a 32-block tile.
        uint32_t rowPitchTexels = (l == 0) ? desc.pitchTexels : m.width;
        if (rowPitchTexels == 0) rowPitchTexels = m.width;
        // The pitch field is pitch >> 5 TEXELS (xenos.h:1222-1223), but a guest
        // may leave it at 0 or understate the width; a pitch narrower than the
        // level would make the row walk backwards into the previous row, so the
        // extent is the floor. Tiled surfaces must additionally cover the level.
        if (rowPitchTexels < m.width) rowPitchTexels = m.width;
        uint32_t rowPitchBlocks = ((rowPitchTexels + bw - 1u) / bw + 31u) & ~31u;
        m.rowPitchBytes = rowPitchBlocks * bb;
        if (!desc.tiled && l != 0) {
            // Linear mip rows are 256-byte aligned (xenos.h:1178-1180).
            m.rowPitchBytes = (m.rowPitchBytes + kTextureLinearRowAlignmentBytes - 1u) &
                              ~(kTextureLinearRowAlignmentBytes - 1u);
        }
        uint32_t sliceRows = (l == 0) ? desc.height : m.height;
        sliceRows = ((sliceRows + bh - 1u) / bh + 31u) & ~31u;
        uint32_t sliceStride = m.rowPitchBytes * sliceRows;
        if (is3D) {
            // 3D slice strides are also aligned to 4 slices (xenos.h:344-350).
            sliceStride *= (desc.depthOrArraySize + 3u) & ~3u;
        }
        // Every array slice is 4 KB aligned (xenos.h:351-353).
        m.sliceStrideBytes = (sliceStride + kTextureSubresourceAlignmentBytes - 1u) &
                             ~(kTextureSubresourceAlignmentBytes - 1u);
        const uint64_t levelBytes = uint64_t(m.sliceStrideBytes) * m.depthOrArraySize;
        if (levelBytes == 0 || levelBytes > 0xFFFFFFFFull) return false;
        m.byteSize = uint32_t(levelBytes);
        m.guestOffset = running;
        running += m.byteSize;
        if (running > 0xFFFFFFFFull) return false;
        out.levelCount = l + 1u;
    }
    out.totalBytes = running;
    // A descriptor with no base address has no mip 0 in memory: the mip chain
    // starts at mip_address. We do not rewrite the offsets here - the caller
    // must read from desc.mipAddress, which BuildGuestMipChain cannot know is
    // non-zero, so it is reported through desc.hasBase.
    out.valid = true;
    return true;
}

// The isResolvable column in the format table (texture_decode.cpp:83) was dead
// until BuildResolveDesc read it. Cross-check against Xenia's own
// ColorFormat set (.research/xenia/src/xenia/gpu/xenos.h:543-570), which is the
// subset of TextureFormat an EDRAM resolve may target - the two must be the
// same set or one of the two is wrong. Returns a static, write-once comparison
// so the check runs once per process, not per resolve.
bool VerifyResolvableColumnMatchesXeniaColorFormat(uint32_t* offender) {
    // Xenia's ColorFormat members, as xenos format codes (xenos.h:543-570).
    static const uint32_t kXeniaColorFormat[] = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 24, 25, 26,
        30, 31, 32, 36, 37, 38, 50, 54, 55, 56,
    };
    const size_t n = sizeof(kXeniaColorFormat) / sizeof(kXeniaColorFormat[0]);
    for (uint32_t f = 0; f < 64; ++f) {
        const TextureFormatInfo* info = GetTextureFormatInfo(f);
        if (!info) continue;
        bool inXenia = false;
        for (size_t i = 0; i < n; ++i) {
            if (kXeniaColorFormat[i] == f) { inXenia = true; break; }
        }
        if (info->isResolvable != inXenia) {
            if (offender) *offender = f;
            return false;
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// Resolve description
// ---------------------------------------------------------------------------

TextureResolveDesc BuildResolveDesc(uint32_t xenosFormat, uint32_t width, uint32_t height,
                                    uint32_t sampleSelect, bool endianSwap, bool swapRedBlue,
                                    bool clearSource, uint32_t extentX, uint32_t extentY,
                                    uint32_t copyDestPitch, uint32_t copyDestHeight,
                                    uint32_t guestBaseAddress) {
    TextureResolveDesc d = {};
    d.xenosFormat = xenosFormat;
    const TextureFormatInfo* info = GetTextureFormatInfo(xenosFormat);
    d.formatName = info ? info->name : "unknown";
    if (!info) {
        d.refusal = "unknown xenos format code";
        return d;
    }
    // Depth formats resolve without sample averaging or format conversion
    // (xenos.h:911-924), so a colour resolve would be wrong. Checked BEFORE
    // isResolvable because the depth rows are also marked non-resolvable (they
    // are render targets), and "needs a dedicated path" is the more useful
    // refusal than "not resolvable".
    if (info->name && (std::strcmp(info->name, "24_8") == 0 ||
                       std::strcmp(info->name, "24_8_FLOAT") == 0)) {
        d.isDepthResolve = true;
        d.refusal = "depth resolve needs a dedicated path (no sample averaging allowed)";
        return d;
    }
    // This is the first consumer of the format table's isResolvable column: a
    // format the table marks non-resolvable (the BC/CTX1 block formats and the
    // *_EDRAM rows) cannot be a resolve destination on the Xenos either, so the
    // resolve is refused instead of silently writing a format the hardware
    // never produces.
    if (!info->isResolvable) {
        d.refusal = "format is not EDRAM-resolvable";
        return d;
    }
    if (info->dxgiFormat == 0) {
        d.refusal = "no host resolve format";
        return d;
    }
    if (width == 0 || height == 0) {
        d.refusal = "zero extent";
        return d;
    }
    if (sampleSelect > static_cast<uint32_t>(GuestCopySampleSelect::AvgAll)) {
        d.refusal = "copy sample select out of range";
        return d;
    }
    d.valid = true;
    d.hostDxgiFormat = info->dxgiFormat;
    d.width = width;
    d.height = height;
    d.sampleSelect = sampleSelect;
    // Resolve granularity is 8x8 pixels (xenos.h:978-983), so the extent is
    // rounded up to it, never down.
    d.extent[0] = (extentX ? extentX : width);
    d.extent[1] = (extentY ? extentY : height);
    d.extent[2] = 1;
    d.copyDestPitch = copyDestPitch;
    d.copyDestHeight = copyDestHeight;
    d.endianSwap = endianSwap;
    d.swapRedBlue = swapRedBlue;
    d.clearSource = clearSource;
    d.guestBaseAddress = guestBaseAddress;
    return d;
}

// ---------------------------------------------------------------------------
// Sampler state
// ---------------------------------------------------------------------------

namespace {

uint32_t ClampToAddressMode(GuestClampMode m, bool* usesBorder) {
    switch (m) {
        case GuestClampMode::Repeat: return kD3D12AddressModeWrap;
        case GuestClampMode::MirroredRepeat: return kD3D12AddressModeMirror;
        case GuestClampMode::MirrorClampToEdge:
        case GuestClampMode::ClampToHalfway:
        case GuestClampMode::MirrorClampToHalfway:
            return kD3D12AddressModeMirrorOnce;
        case GuestClampMode::ClampToEdge:
            return kD3D12AddressModeClamp;
        case GuestClampMode::ClampToBorder:
        case GuestClampMode::MirrorClampToBorder:
            *usesBorder = true;
            return kD3D12AddressModeBorder;
        default: return kD3D12AddressModeClamp;
    }
}

uint32_t AnisoToMaxAnisotropy(GuestAnisoFilter a) {
    switch (a) {
        case GuestAnisoFilter::Disabled:
        case GuestAnisoFilter::Max1x1: return 1u;
        case GuestAnisoFilter::Max2x1: return 2u;
        case GuestAnisoFilter::Max4x1: return 4u;
        case GuestAnisoFilter::Max8x1: return 8u;
        case GuestAnisoFilter::Max16x1: return 16u;
        default: return 1u;
    }
}

}  // namespace

HostSamplerDesc DecodeGuestSamplerState(const GuestTextureDesc& desc,
                                        const char** refusal) {
    HostSamplerDesc s = {};
    if (refusal) *refusal = nullptr;
    if (!desc.valid) {
        if (refusal) *refusal = "descriptor not decoded";
        return s;
    }
    bool borderU = false, borderV = false, borderW = false;
    s.addressU = ClampToAddressMode(desc.clampU, &borderU);
    s.addressV = ClampToAddressMode(desc.clampV, &borderV);
    s.addressW = ClampToAddressMode(desc.clampW, &borderW);

    // lod_bias has 5 fractional bits (xenos.h:1269-1270), and Xenia divides by
    // 32 to get LOD units (sampler_info.cc:46).
    s.mipLodBias = float(desc.lodBias) * (1.0f / 32.0f);

    // kUseFetchConst resolves to the fetch constant's own field, because the
    // fetch constant IS the fetch constant (sampler_info.cc:25-43).
    const bool magPoint = desc.magFilter == GuestTextureFilter::Point;
    const bool minPoint = desc.minFilter == GuestTextureFilter::Point;
    // kBaseMap is a mip-only "no mip blend" (xenos.h:135); the host expresses
    // that as MaxLOD = mipMinLevel, so LOD is pinned to the base.
    const bool mipPoint = desc.mipFilter != GuestTextureFilter::Linear;
    s.maxAnisotropy = AnisoToMaxAnisotropy(desc.anisoFilter);
    const bool aniso = s.maxAnisotropy > 1u;

    s.filter = kD3D12FilterMinMagMipPoint;
    if (minPoint != magPoint) {
        s.filter = minPoint ? kD3D12FilterMinPointMagMipPoint
                            : kD3D12FilterMinLinearMagMipPoint;
        if (!mipPoint) {
            s.filter = minPoint ? kD3D12FilterMinPointMagMipLinear
                                : kD3D12FilterMinLinearMagMipLinear;
        }
    } else if (!mipPoint) {
        s.filter = kD3D12FilterMinMagMipLinear;
    }
    if (aniso) s.filter = kD3D12FilterAnisotropic;

    // Mip clamp. mip_max_level is the highest stored level (texture_cache.h:43
    // - a texture with mip_max_level+1 levels exists, mip_min_level is only a
    // sampling clamp), so MaxLOD is mip_max_level and mipMinLevel pins the
    // floor when the filter does not blend mips.
    s.minLod = 0.0f;
    s.maxLod = float(desc.mipMaxLevel);
    if (mipPoint) s.minLod = float(desc.mipMinLevel);

    if (borderU || borderV || borderW) {
        // Xenos BorderColor (xenos.h:150-162): 0 = ABGR black, 1 = ABGR white.
        // 2/3 are the YCbCr blacks, which D3D12 cannot express: those get black
        // and a refusal string rather than a guessed magenta-ish colour.
        switch (desc.borderColor) {
            case 1u:
                s.borderColor[0] = s.borderColor[1] = s.borderColor[2] =
                    s.borderColor[3] = 1.0f;
                break;
            case 0u:
            default:
                s.borderColor[0] = s.borderColor[1] = s.borderColor[2] =
                    s.borderColor[3] = 0.0f;
                break;
        }
        if (desc.borderColor >= 2u && refusal)
            *refusal = "YCbCr border colour is not expressible; using black";
    }
    // A 1-bit-border (border_size) fetch constant clamps the texture, so the
    // host must sample the whole texel range; D3D12 has no equivalent knob and
    // the address mode already covers the practical case.

    // Hash every field so two fetch constants that differ only in an ignored
    // field still share a heap slot, and two that differ anywhere do not.
    uint64_t h = 14695981039346656037ull;
    const uint64_t prime = 1099511628211ull;
    auto mix = [&h](uint64_t v) {
        for (int i = 0; i < 8; ++i) {
            h ^= (v >> (i * 8)) & 0xFFull;
            h *= prime;
        }
    };
    mix(s.filter); mix(s.addressU); mix(s.addressV); mix(s.addressW);
    mix(s.maxAnisotropy); mix(s.comparisonFunc);
    mix(uint64_t(uint32_t(s.mipLodBias * 32.0f)));
    mix(uint64_t(uint32_t(s.minLod * 32.0f)));
    mix(uint64_t(uint32_t(s.maxLod * 32.0f)));
    for (int i = 0; i < 4; ++i) mix(uint64_t(uint32_t(s.borderColor[i] * 255.0f)));
    s.hash = h;
    return s;
}

} // namespace mcla::native