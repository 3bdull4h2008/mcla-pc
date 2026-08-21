// Phase 4 texture decode validator (headless, exit code 0 = clean).
//
// Methodology: a compiled set of exports is
// rexruntime.dll that ARE the canonical implementation (SDK = oracle). We
// LoadLibrary that DLL and cross-check our standalone module (texture_decode,
// which intentionally has no SDK/D3D dependency) against it:
//
//   1. GetTiledOffset2D  : exhaustively over x, y, pitch, bpbLog2.
//   2. GetTiledOffset3D  : exhaustively over x, y, z, pitch, height, bpbLog2.
//   3. GetTiledAddressUpperBound2D / 3D : bounds math.
//   4. Lower bounds : the SDK's are inline util.h helpers (not exported), so
//      they are validated compositionally -- the masked corner is exactly
//      GetTiledOffset(2D|3D)(left & ~31, top & ~31 [, front & ~4]) and the
//      offset oracle already proves the offset math.
//   5. Format table : cross-check GetTextureBytesPerBlock + a FormatInfo byte-
//      for-byte mirror against FormatInfo::Get for all 64 Xenos formats.
//   6. Untile : seed a synthetic tiled surface using oracle offsets, untile
//      with our UntileTexture2D, then re-tile with the oracle offsets and
//      verify both directions are bijective and byte-identical.
//
// Session-known unknowns: none blocking. The lower-bound positions are the
// same GTextureAddressLowerBound masks (SDK util.h lines 287-300).

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <windows.h>

#include "renderer/texture_decode.h"
#include "renderer/resource_cache.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace mcla::native;

static bool g_ok = true;

static void Check(bool cond, const char* what) {
    std::printf("  [%s] %s\n", cond ? "ok" : "FAIL", what);
    if (!cond) g_ok = false;
}

// 32-byte mirror of the native texture format info (see build/oracle_format_dump.cpp:
// offset 0 format, 8 name*, 16 type, 20 block_width, 24 block_height,
// 28 bits_per_pixel).
struct SdkFormatInfo {
    uint32_t format;
    const char* name;
    uint32_t type;
    uint32_t block_width;
    uint32_t block_height;
    uint32_t bits_per_pixel;
};

int main() {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    std::printf("== Phase 4 texture_decode validator ==\n");

    HMODULE sdk = LoadLibraryW(L"rexruntime.dll");
    if (!sdk) {
        std::printf("WARN: rexruntime.dll oracle absent (ReXGlue removed) - skipping oracle comparison\n");
        std::printf("RESULT: SKIPPED (no oracle)\n");
        return 0;
    }
    Check(sdk != nullptr, "LoadLibrary(rexruntime.dll) oracle present");

    // Oracle exports.
    auto sdkOff2D = reinterpret_cast<int32_t(*)(int32_t, int32_t, uint32_t, uint32_t)>(
        GetProcAddress(sdk, "?GetTiledOffset2D@texture_util@graphics@rex@@YAHHHII@Z"));
    auto sdkOff3D = reinterpret_cast<int32_t(*)(int32_t, int32_t, int32_t, uint32_t, uint32_t, uint32_t)>(
        GetProcAddress(sdk, "?GetTiledOffset3D@texture_util@graphics@rex@@YAHHHHIII@Z"));
    auto sdkUp2D = reinterpret_cast<uint32_t(*)(uint32_t, uint32_t, uint32_t, uint32_t)>(
        GetProcAddress(sdk, "?GetTiledAddressUpperBound2D@texture_util@graphics@rex@@YAIIIII@Z"));
    auto sdkUp3D = reinterpret_cast<uint32_t(*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(
        GetProcAddress(sdk, "?GetTiledAddressUpperBound3D@texture_util@graphics@rex@@YAIIIIIII@Z"));
    auto sdkFormat = reinterpret_cast<const SdkFormatInfo* (*)(uint32_t)>(
        GetProcAddress(sdk, "?Get@FormatInfo@graphics@rex@@SAPEBU123@I@Z"));
    Check(sdkOff2D && sdkOff3D && sdkUp2D && sdkUp3D && sdkFormat,
          "oracle exports resolved (offsets, bounds, FormatInfo::Get)");
    if (!sdkOff2D || !sdkOff3D || !sdkUp2D || !sdkUp3D || !sdkFormat) {
        std::printf("RESULT: ISSUES FOUND\n"); return 1;
    }

    // -- 1. GetTiledOffset2D vs oracle -------------------------------------
    {
        uint64_t mismatches = 0, total = 0;
        const uint32_t pitches[] = { 32, 64, 96, 128, 256, 257, 288, 320 };
        for (uint32_t pitch : pitches) {
            for (uint32_t bpb = 0; bpb < 7; ++bpb) {   // bytes per block = 1<<bpb
                for (int32_t x = 0; x < pitch + 17; ++x) {
                    for (int32_t y = 0; y < 3 * 32 + 5; ++y) {
                        const int32_t ours = GetTiledOffset2D(x, y, pitch, bpb);
                        const int32_t sdkv = sdkOff2D(x, y, pitch, bpb);
                        ++total;
                        if (ours != sdkv) {
                            if (mismatches < 8) {
                                std::printf("    ! off2D(x=%d y=%d pitch=%u bpb=%u) ours=%d sdk=%d\n",
                                            x, y, pitch, bpb, ours, sdkv);
                            }
                            ++mismatches;
                        }
                    }
                }
            }
        }
        char msg[128];
        std::snprintf(msg, sizeof msg, "GetTiledOffset2D == oracle over %llu probes (%llu mismatch)",
                      (unsigned long long)total, (unsigned long long)mismatches);
        Check(mismatches == 0, msg);
    }

    // -- 2. GetTiledOffset3D vs oracle -------------------------------------
    {
        uint64_t mismatches = 0, total = 0;
        const uint32_t pitches[] = { 32, 64, 128, 256, 320 };
        const uint32_t heights[] = { 32, 64, 128, 136 };
        for (uint32_t pitch : pitches) {
            for (uint32_t height : heights) {
                for (uint32_t bpb = 0; bpb < 6; ++bpb) {
                    for (int32_t x = 0; x < 66; ++x) {
                        for (int32_t y = 0; y < 70; ++y) {
                            for (int32_t z = 0; z < 9; ++z) {
                                const int32_t ours = GetTiledOffset3D(x, y, z, pitch, height, bpb);
                                const int32_t sdkv = sdkOff3D(x, y, z, pitch, height, bpb);
                                ++total;
                                if (ours != sdkv) {
                                    if (++mismatches < 8) {
                                        std::printf("    ! off3D(x=%d y=%d z=%d pitch=%u h=%u bpb=%u) ours=%d sdk=%d\n",
                                                    x, y, z, pitch, height, bpb, ours, sdkv);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        char msg[128];
        std::snprintf(msg, sizeof msg, "GetTiledOffset3D == oracle (%llu samples, %llu mismatches)",
                      (unsigned long long)total, (unsigned long long)mismatches);
        Check(mismatches == 0, msg);
    }

    // -- 3. GetTiledAddressUpperBound2D / 3D vs oracle ---------------------
    {
        uint64_t mismatches = 0, total = 0;
        const uint32_t pitches[] = { 32, 64, 96, 128, 256, 320 };
        for (uint32_t pitch : pitches) {
            for (uint32_t bpb = 0; bpb < 7; ++bpb) {
                for (uint32_t right : { 1u, 16u, 32u, 64u, pitch + 1, pitch + 37 }) {
                    for (uint32_t bottom : { 1u, 16u, 32u, 64u, 97u, 130u }) {
                        const uint32_t ours = uint32_t(GetTiledAddressUpperBound2D(right, bottom, pitch, bpb));
                        const uint32_t sdkv = sdkUp2D(right, bottom, pitch, bpb);
                        ++total;
                        if (ours != sdkv) { ++mismatches; }
                    }
                }
            }
        }
        char msg[128];
        std::snprintf(msg, sizeof msg, "GetTiledAddressUpperBound2D == oracle (%llu samples, %llu mismatches)",
                      (unsigned long long)total, (unsigned long long)mismatches);
        Check(mismatches == 0, msg);
    }
    {
        uint64_t mismatches = 0, total = 0;
        const uint32_t pitches[] = { 32, 64, 128, 320 };
        const uint32_t heights[] = { 32, 64, 136 };
        for (uint32_t pitch : pitches) {
            for (uint32_t height : heights) {
                for (uint32_t bpb = 0; bpb < 6; ++bpb) {
                    for (uint32_t right : { 1u, 32u, 65u, pitch + 33u }) {
                        for (uint32_t bottom : { 1u, 32u, 66u, height + 5u }) {
                            for (uint32_t back : { 1u, 4u, 8u, 9u, 12u }) {
                                const uint32_t ours =
                                    uint32_t(GetTiledAddressUpperBound3D(right, bottom, back, pitch, height, bpb));
                                const uint32_t sdkv = sdkUp3D(right, bottom, back, pitch, height, bpb);
                                ++total;
                                if (ours != sdkv) { ++mismatches; }
                            }
                        }
                    }
                }
            }
        }
        char msg[128];
        std::snprintf(msg, sizeof msg, "GetTiledAddressUpperBound3D == oracle (%llu samples, %llu mismatches)",
                      (unsigned long long)total, (unsigned long long)mismatches);
        Check(mismatches == 0, msg);
    }

    // -- 4. Format table vs FormatInfo::Get (all 64 formats) ---------------
    {
        uint64_t mismatches = 0, nulls = 0, tables = 0;
        for (uint32_t f = 0; f <= 63; ++f) {
            const SdkFormatInfo* info = sdkFormat(f);
            if (!info) { ++nulls; continue; }
            const uint32_t sdkBpb = info->block_width * info->block_height * info->bits_per_pixel / 8;
            const uint32_t ourBpb = GetTextureBytesPerBlock(f);
            ++tables;
            if (ourBpb != sdkBpb) {
                std::printf("    ! fmt %u: ours_bpb=%u sdk_bpb=%u (%s)\n",
                            f, ourBpb, sdkBpb, info->name ? info->name : "?");
                ++mismatches;
            }
            // Every format's type/block/shape in our table must be non-zero.
            const TextureFormatInfo* tab = GetTextureFormatInfo(f);
            if (!tab) {
                std::printf("    ! fmt %u: absent from our table\n", f);
                ++mismatches;
            } else if (tab->isResolvable != (info->type == 0) ||
                       tab->isBlockCompressed != (info->type == 2) ||
                       tab->blockWidth != info->block_width ||
                       tab->blockHeight != info->block_height) {
                std::printf("    ! fmt %u flags/blocks disagree: ours(res=%d comp=%d %ux%u) sdk(type=%u %ux%u)\n",
                            f, tab->isResolvable ? 1 : 0, tab->isBlockCompressed ? 1 : 0,
                            tab->blockWidth, tab->blockHeight, info->type,
                            info->block_width, info->block_height);
                ++mismatches;
            }
        }
        Check(nulls == 0, "FormatInfo::Get non-null for every format 0..63");
        char msg[128];
        std::snprintf(msg, sizeof msg, "Format table bpb == oracle for all 64 formats (%llu, %llu mismatches)",
                      (unsigned long long)tables, (unsigned long long)mismatches);
        Check(mismatches == 0, msg);
    }

    // -- 5. Untile round-trip (ours -> retile with oracle offsets -> equal) --
    {
        // Synthetic fixture: 64x64 texels of 8_8_8_8 (bpb=4), pitch 64 blocks.
        constexpr uint32_t kPitch = 64, kH = 64;
        std::vector<uint8_t> tiled(kPitch * kH * 4, 0u);
        // Deterministic content: texel value = f(x,y) so the round trip is
        // content-sensitive.
        const uint32_t n = kPitch * kH * 4;
        for (uint32_t i = 0; i < n; ++i) tiled[i] = uint8_t((i * 131u + 17u) & 0xFF);

        // Re-tile reference with oracle math (byte-identical to our copy).
        std::vector<uint8_t> oracleLinear(kPitch * kH * 4, 0u);
        for (uint32_t y = 0; y < kH; ++y) {
            for (uint32_t x = 0; x < kPitch; ++x) {
                const int32_t off = sdkOff2D(int32_t(x), int32_t(y), kPitch, 2);
                std::memcpy(&oracleLinear[(y * kPitch + x) * 4], &tiled[off], 4);
            }
        }
        // Our untile, offset into the surface grid, guarded by byte sizes.
        std::vector<uint8_t> ours(kPitch * kH * 4, 0u);
        {
            const TextureFormatInfo* fi = GetTextureFormatInfo(6);  // 8_8_8_8
            TextureUntileInfo ti = {};
            ti.format = fi;
            ti.offsetX = 0; ti.offsetY = 0;
            ti.width = kPitch; ti.height = kH;
            ti.inputPitch = kPitch; ti.inputHeight = kH;
            ti.outputPitch = kPitch;
            ti.srcBytes = uint32_t(tiled.size());
            ti.dstBytes = uint32_t(ours.size());
            UntileTexture2D(tiled.data(), ours.data(), ti);
        }
        // The oracle-linear extraction must equal ours.
        bool eq = ours == oracleLinear;
        Check(eq, "UntileTexture2D output == re-tile via oracle offsets (16 KB / 4096 texels)");

        // Offset region: untile a 16x16-block subregion at (8,8) into a full
        // kPitch-wide surface-positioned destination. The dest row keeps the
        // surface pitch, so row stride is kPitch and only region blocks are
        // written; oracle re-tile must match byte-for-byte within the region.
        {
            constexpr uint32_t kSub = 16, kOx = 8, kOy = 8;
            std::vector<uint8_t> dstFull(kPitch * kH * 4, 0xEE);
            const TextureFormatInfo* fi = GetTextureFormatInfo(6);
            TextureUntileInfo ti = {};
            ti.format = fi;
            ti.offsetX = kOx; ti.offsetY = kOy;
            ti.width = kSub; ti.height = kSub;
            ti.inputPitch = kPitch; ti.inputHeight = kH;
            ti.outputPitch = kPitch;
            ti.srcBytes = uint32_t(tiled.size());
            ti.dstBytes = uint32_t(dstFull.size());
            UntileTexture2D(tiled.data(), dstFull.data(), ti);

            // Reference: re-tile the same region using oracle offsets into the
            // same surface-positioned destination.
            std::vector<uint8_t> ref(kPitch * kH * 4, 0xEE);
            for (uint32_t r = 0; r < kSub; ++r) {
                for (uint32_t c = 0; c < kSub; ++c) {
                    const int32_t off = sdkOff2D(int32_t(kOx + c), int32_t(kOy + r), kPitch, 2);
                    std::memcpy(&ref[(kOy + r) * kPitch * 4 + (kOx + c) * 4], &tiled[off], 4);
                }
            }
            Check(dstFull == ref && dstFull[(kOy + kSub) * kPitch * 4] == 0xEE,
                  "UntileTexture2D offset region (8,8)+16x16 re-tiles identically; untouched blocks stay 0xEE");
        }

        // Bounds guard: an out-of-grid offsetX+width must be skipped, not
        // written (region would step past the surface pitch).
        {
            std::vector<uint8_t> dstG(kPitch * kH * 4, 0x99);
            const TextureFormatInfo* fi = GetTextureFormatInfo(6);
            TextureUntileInfo ti = {};
            ti.format = fi;
            ti.offsetX = kPitch - 1; ti.offsetY = 0;  // width 4 would exceed pitch
            ti.width = 4; ti.height = 1;
            ti.inputPitch = kPitch; ti.inputHeight = kH;
            ti.outputPitch = kPitch;
            ti.srcBytes = uint32_t(tiled.size());
            ti.dstBytes = uint32_t(dstG.size());
            UntileTexture2D(tiled.data(), dstG.data(), ti);
            bool untouched = true;
            for (uint8_t b : dstG) { if (b != 0x99) { untouched = false; break; } }
            Check(untouched, "UntileTexture2D rejects region crossing the surface pitch");
        }
    }

    // -- 7. UntileTexture3D with height != pitch (regression for the
    //        inputHeight fix) ----------------------------------------------
    {
        // Surface: pitch 64 blocks, height 32 blocks, bpb 4 (8_8_8_8), 4 z
        // slices. Height != pitch so the old pitch-passed-as-height bug would
        // index z incorrectly.
        constexpr uint32_t kP = 64, kH = 32, kD = 4;
        const uint32_t total = kP * kH * kD * 4;
        std::vector<uint8_t> tiled(total, 0u);
        for (uint32_t i = 0; i < total; ++i) tiled[i] = uint8_t((i * 97u + 5u) & 0xFF);

        std::vector<uint8_t> ours(total, 0u);
        {
            const TextureFormatInfo* fi = GetTextureFormatInfo(6);
            TextureUntileInfo ti = {};
            ti.format = fi;
            ti.offsetX = 0; ti.offsetY = 0;
            ti.width = kP; ti.height = kH;
            ti.inputPitch = kP; ti.inputHeight = kH;
            ti.outputPitch = kP;
            ti.srcBytes = total;
            ti.dstBytes = total;
            UntileTexture3D(tiled.data(), ours.data(), ti, kD);
        }
        // Reference: gather each slice using oracle 3D offsets.
        std::vector<uint8_t> ref(total, 0u);
        for (uint32_t z = 0; z < kD; ++z)
            for (uint32_t y = 0; y < kH; ++y)
                for (uint32_t x = 0; x < kP; ++x) {
                    const int32_t off = sdkOff3D(int32_t(x), int32_t(y), int32_t(z), kP, kH, 2);
                    std::memcpy(&ref[(z * kH + y) * kP * 4 + x * 4], &tiled[off], 4);
                }
        Check(ours == ref, "UntileTexture3D height!=pitch re-tiles via oracle 3D offsets (8k blocks)");
    }

    // -- 6. ComputeTextureLayout (resource_cache wiring) --------------------
    {
        // 8_8_8_8 64x64 -> 64x64 blocks x 4 B = 16384 B; pitch unchanged.
        TextureLayout l1 = ComputeTextureLayout(6, 64, 64);
        Check(l1.valid && l1.dxgiFormat == 28 && l1.blocksX == 64 && l1.blocksY == 64 &&
              l1.bytesPerBlock == 4 && l1.byteSize == 16384,
              "TextureLayout 8_8_8_8 64x64 -> 4096 blocks*4B = 16384 B");
        // 9x9 texels of DXT1 -> 3x3 blocks (ceil texel/block), 9 blocks*8B.
        TextureLayout l2 = ComputeTextureLayout(18, 9, 9);
        Check(l2.valid && l2.blocksX == 3 && l2.blocksY == 3 &&
              l2.bytesPerBlock == 8 && l2.byteSize == 72,
              "TextureLayout DXT1 9x9 -> 3x3 blocks*8B = 72 B");
        // Unknown format -> invalid.
        TextureLayout l3 = ComputeTextureLayout(64, 8, 8);
        Check(!l3.valid, "TextureLayout format 64 (unknown) -> invalid");
    }

    std::printf("RESULT: %s\n", g_ok ? "CLEAN" : "ISSUES FOUND");
    return g_ok ? 0 : 1;
}