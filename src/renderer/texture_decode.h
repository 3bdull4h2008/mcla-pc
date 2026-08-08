#pragma once

// Phase 4 texture format/layout decoding for the MCLA native renderer.
//
// Xenos preserves a small set of "canonical" texture format codes (see
// rexglue-sdk/.../rex/graphics/xenos.h TextureFormat) plus block-based tiled
// memory layouts. This module maps a Xenos texture format to the information a
// native D3D12 backend needs (host DXGI format, block size, bytes/block,
// compressed-ness), computes the Xenos tiled byte offset for 2D/3D block
// coordinates, and untiles guest textures into a linear host layout.
//
// It is intentionally standalone (no D3D12/SDK headers) so it is testable
// headlessly against the shader/capture corpus and against the ReXGlue SDK's
// own implementations, which are exported by rexruntime.dll and used as the
// validation oracle.

#include <cstdint>

namespace mcla::native {

// Layout metadata for one Xenos texture format, mirroring the SDK's FormatInfo
// (rexglue-sdk/.../texture/info.h) semantics. Kept as plain data with numeric
// host-format codes so the module stays D3D12-free.
struct TextureFormatInfo {
    uint32_t xenosFormat = 0;   // xenos::TextureFormat numeric value
    const char* name = nullptr;  // e.g. "8_8_8_8", "DXT1", "CTX1"
    uint32_t dxgiFormat = 0;     // DXGI_FORMAT numeric value (0 = unsupported)
    uint32_t blockWidth = 1;     // horizontal block size (1 = scalar)
    uint32_t blockHeight = 1;    // vertical block size (1 = scalar)
    uint32_t bitsPerPixel = 0;   // bits per texel
    bool isBlockCompressed = false; // BC/CTX1: copy granularity is a block
    bool isResolvable = false;      // may be produced by EDRAM resolve
    bool hasSwappedAxes = false;    // host format is BGR-named (B5G6R5 etc.)
};

// Return layout info for a numeric Xenos texture format code, or nullptr when
// the format is not in the supported table.
const TextureFormatInfo* GetTextureFormatInfo(uint32_t xenosFormat);

// Bytes-per-block for a format (blockWidth*blockHeight*bitsPerPixel/8).
// Returns 0 for unknown formats.
uint32_t GetTextureBytesPerBlock(uint32_t xenosFormat);

// Human-readable name; "unknown" when unsupported.
const char* TextureFormatName(uint32_t xenosFormat);

// Number of blocks a texture of `width`x`height` texels spans, per the
// format's block size. Width/height are not rounded up here; callers that need
// pitch alignment do it themselves.
uint32_t GetTextureBlockSpan(uint32_t xenosFormat, uint32_t width, uint32_t height,
                             uint32_t* outBlocksX, uint32_t* outBlocksY);

// ---------------------------------------------------------------------------
// Tiled (swizzled) addressing.
//
// Xenos textures in EDRAM/guest memory are stored in a 32x32-block macro tile
// layout when tiled. The two functions below reproduce the canonical
// XGAddress tiled offset math (Xenia texture_util.cc + architected 3D case)
// which ReXGlue's texture_util also implements; the validator cross-checks
// your implementation against rexruntime.dll's exported versions.
// ---------------------------------------------------------------------------

// Byte offset of block (x, y) in a tiled 2D/stacked surface whose block pitch
// is `pitch` blocks with `bpbLog2` = log2(bytes per block). Returns a byte
// offset; callers must bound 0 <= offset < pitch*height*bytesPerBlock.
int32_t GetTiledOffset2D(int32_t x, int32_t y, uint32_t pitch, uint32_t bpbLog2);

// Byte offset of block (x, y, z) in a tiled volume whose block pitch and
// block height are `pitch` and `height` with `bpbLog2` = log2(bytes per
// block).
int32_t GetTiledOffset3D(int32_t x, int32_t y, int32_t z, uint32_t pitch,
                         uint32_t height, uint32_t bpbLog2);

// Bounds in bytes that a region may touch in a tiled surface, for cache-range
// estimation. Mirror the ReXGlue texture_util helpers:
//   - lower bound: tiled offset at the macro-tile-aligned (left, top)
//     block corner (32x32-block tiles).
//   - upper bound: maximum tiled offset reachable within the region, allowing
//     right > pitch and bottom > height (for estimating how far addresses can
//     go even beyond the subresource stride).
int32_t GetTiledAddressLowerBound2D(uint32_t left, uint32_t top, uint32_t pitch,
                                    uint32_t bpbLog2);
int32_t GetTiledAddressUpperBound2D(uint32_t right, uint32_t bottom, uint32_t pitch,
                                    uint32_t bpbLog2);
int32_t GetTiledAddressLowerBound3D(uint32_t left, uint32_t top, uint32_t front,
                                    uint32_t pitch, uint32_t height, uint32_t bpbLog2);
int32_t GetTiledAddressUpperBound3D(uint32_t right, uint32_t bottom, uint32_t back,
                                    uint32_t pitch, uint32_t height, uint32_t bpbLog2);

// ---------------------------------------------------------------------------
// Untile: copy a tiled guest region to a linear host buffer.
// ---------------------------------------------------------------------------

struct TextureUntileInfo {
    const TextureFormatInfo* format = nullptr;  // block size / bpp
    uint32_t offsetX = 0;  // block coordinates of the region within the surface
    uint32_t offsetY = 0;
    uint32_t width = 0;    // region size in blocks
    uint32_t height = 0;   // region size in blocks
    uint32_t inputPitch = 0;   // surface block pitch (tiled grid width)
    uint32_t inputHeight = 0;  // surface block height (3D stacks, tiled grid rows)
    uint32_t outputPitch = 0;  // destination block pitch
    uint32_t srcBytes = 0;     // byte size of the source buffer (bounds guard)
    uint32_t dstBytes = 0;     // byte size of the destination buffer (bounds guard)
};

// Untile a 2D/stacked region. `src`/`dst` byte sizes must be provided
// (`srcBytes`/`dstBytes`); any pair of offsets that would step outside either
// buffer is skipped, never read or written. The region must lie inside the
// surface: requires offsetX+width <= inputPitch (overflow-checked). Byte-exact,
// endian preserved (no endianness conversion here).
void UntileTexture2D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info);

// Untile a 3D region slice-by-slice. `inputHeight` is the surface's block
// height (the tiled math indexes z by the height, not by the pitch), so it
// must be >= slice count * block rows; depth slices are contiguous in `dst`
// (each slice's output_pitch_v is `outputPitch`). `info.height` is the block
// height of the region.
void UntileTexture3D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info,
                     uint32_t depth);

} // namespace mcla::native