#pragma once

// Phase 4 texture format/layout decoding for the MCLA native renderer.
//
// Xenos preserves a small set of "canonical" texture format codes (see
// the Xenos texture format TextureFormat) plus block-based tiled
// memory layouts. This module maps a Xenos texture format to the information a
// native D3D12 backend needs (host DXGI format, block size, bytes/block,
// compressed-ness), computes the Xenos tiled byte offset for 2D/3D block
// coordinates, and untiles guest textures into a linear host layout.
//
// It is intentionally standalone (no D3D12/SDK headers) so it is testable
// headlessly against the shader/capture corpus and against the legacy
// own implementations, which are exported by rexruntime.dll and used as the
// validation oracle.

#include <cstdint>
#include <vector>

namespace mcla::native {

// Layout metadata for one Xenos texture format, mirroring the SDK's FormatInfo
// (the texture format info) semantics. Kept as plain data with numeric
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
// which the legacy texture utility also implements; the validator cross-checks
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
// estimation. Mirror the legacy texture utility helpers:
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

// Why an untile produced nothing. `UntileTexture2D/3D` never read or write out
// of bounds, so a refusal has to be observable: the caller passes one of these
// and learns that the copy was skipped instead of trusting an all-zero output
// buffer. Defaulted out-params keep the pre-existing call sites (which pass
// only 3-4 arguments) source-compatible.
enum class TextureUntileRefusal : uint32_t {
    None = 0,
    NoFormatInfo,     // info.format == nullptr (unknown xenos format code)
    NullBuffer,       // src == nullptr or dst == nullptr
    ZeroPitch,        // inputPitch == 0
    ZeroBlockBytes,   // GetTextureBytesPerBlock() == 0
    RegionOutsideSurface,   // offset+extent steps past inputPitch/inputHeight
    NonPowerOfTwoBlock,      // bytes/block is not 1<<n (e.g. 32_32_32_FLOAT)
    BlockTooLarge,           // bytes/block > 64: outside the bpbLog2 range
    NoByteSizes,      // srcBytes/dstBytes == 0: the bounds guard cannot run
};

// Untile a 2D/stacked region. `src`/`dst` byte sizes must be provided
// (`srcBytes`/`dstBytes`); any pair of offsets that would step outside either
// buffer is skipped, never read or written. The region must lie inside the
// surface: requires offsetX+width <= inputPitch (overflow-checked).
//
// ENDIANNESS: this function is a pure block gather and is byte-exact - it
// never reorders bytes, because the detile math is defined on bytes and any
// swap inside it would corrupt the oracle-checked copy (see the untile
// round-trip in tools/validators/texture_decode_test.cpp:238-323). The
// Xenos `Endian` field of the fetch constant is honoured in exactly one other
// place, ConvertTextureEndianness() below, which runs on the *linear* buffer
// after untiling. Formats whose guest packing is byte-swapped relative to the
// host are therefore never silently imported un-swapped: PlanTextureImport()
// refuses (Refusal::EndianOnBlockCompressed) whenever a swap is requested for
// a block-compressed format, because Xenia's load shaders all read the block
// words little-endian and no captured evidence says a swap is legal there.
void UntileTexture2D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info,
                     TextureUntileRefusal* outRefusal = nullptr);

// Untile a 3D region slice-by-slice. `inputHeight` is the surface's block
// height (the tiled math indexes z by the height, not by the pitch), so it
// must be >= slice count * block rows; depth slices are contiguous in `dst`
// (each slice's output_pitch_v is `outputPitch`). `info.height` is the block
// height of the region.
void UntileTexture3D(const uint8_t* src, uint8_t* dst, const TextureUntileInfo& info,
                     uint32_t depth, TextureUntileRefusal* outRefusal = nullptr);

// ---------------------------------------------------------------------------
// Endianness conversion (the only byte-reordering step in this module).
// ---------------------------------------------------------------------------

// Xenos fetch-constant `Endian` values (xenos.h:193-198). These are the exact
// bit permutations GpuSwap() applies (xenos.h:1052-1069), reproduced here on
// bytes with explicit shifts - never a reinterpret_cast on guest data.
enum class GuestEndian : uint32_t {
    None = 0,
    EightIn16 = 1,     // swap bytes within each 16-bit half word
    EightIn32 = 2,     // swap bytes within each 32-bit word
    SixteenIn32 = 3,   // swap the two 16-bit half words of each 32-bit word
};

// True when `endianness` is one of the four architected values.
bool IsSupportedGuestEndian(uint32_t endianness);

// Apply the architected `endianness` permutation in place-safe fashion:
// `texelBytes` must be a multiple of 4 for EightIn16/SixteenIn32 to be exact,
// and 4 for EightIn32. Returns false (and copies nothing) for an unknown
// endianness code or a `texelBytes` the permutation cannot divide evenly.
bool ConvertTextureEndianness(uint32_t endianness, uint8_t* data, uint32_t bytes,
                              uint32_t texelBytes);

// ---------------------------------------------------------------------------
// Guest fetch constant (texture descriptor) - the 24-byte blob at
// DrawPacket::textureDescriptors[i].
// ---------------------------------------------------------------------------

enum class GuestTextureDimension : uint32_t {
    Invalid = 0,
    OneD = 0,
    TwoDOrStacked = 1,
    ThreeD = 2,
    Cube = 3,
};

enum class GuestClampMode : uint32_t {  // xenos.h:104-113
    Repeat = 0,
    MirroredRepeat = 1,
    ClampToEdge = 2,
    MirrorClampToEdge = 3,
    ClampToHalfway = 4,
    MirrorClampToHalfway = 5,
    ClampToBorder = 6,
    MirrorClampToBorder = 7,
};

enum class GuestTextureFilter : uint32_t {  // xenos.h:131-138
    Point = 0,
    Linear = 1,
    BaseMap = 2,      // mip filter only: no mip blending
    UseFetchConst = 3,
};

enum class GuestAnisoFilter : uint32_t {  // xenos.h:140-147
    Disabled = 0,
    Max1x1 = 1,
    Max2x1 = 2,
    Max4x1 = 3,
    Max8x1 = 4,
    Max16x1 = 5,
    UseFetchConst = 7,
};

enum class GuestTextureSign : uint32_t {  // xenos.h:121-128
    Unsigned = 0,
    Signed = 1,
    UnsignedBiased = 2,
    Gamma = 3,
};

// kTextureSubresourceAlignmentBytesLog2 (xenos.h:1132): the base/mip address
// fields store the address with this many low bits clear.
constexpr uint32_t kTextureSubresourceAlignmentBytesLog2 = 12;
constexpr uint32_t kTextureSubresourceAlignmentBytes =
    1u << kTextureSubresourceAlignmentBytesLog2;
constexpr uint32_t kTextureTileWidthHeightLog2 = 5;
constexpr uint32_t kTextureTileWidthHeight = 1u << kTextureTileWidthHeightLog2;
constexpr uint32_t kTextureLinearRowAlignmentBytesLog2 = 8;
constexpr uint32_t kTextureLinearRowAlignmentBytes =
    1u << kTextureLinearRowAlignmentBytesLog2;
constexpr uint32_t kTextureMaxMips = 15;  // 8192 texels, 13 bits + 2

// Decoded guest texture fetch constant. All fields are host-endian numeric
// values: DecodeGuestTextureDescriptor() reads the 24 big-endian bytes with
// explicit shifts, so nothing here is a reinterpret_cast of guest memory.
struct GuestTextureDesc {
    bool valid = false;
    uint32_t rawDwords[6] = {0, 0, 0, 0, 0, 0};

    GuestTextureSign sign[4] = {GuestTextureSign::Unsigned, GuestTextureSign::Unsigned,
                                GuestTextureSign::Unsigned, GuestTextureSign::Unsigned};
    GuestClampMode clampU = GuestClampMode::ClampToEdge;
    GuestClampMode clampV = GuestClampMode::ClampToEdge;
    GuestClampMode clampW = GuestClampMode::ClampToEdge;
    uint32_t pitchTexels = 0;   // field is pitch >> 5
    bool tiled = false;

    uint32_t xenosFormat = 0;
    uint32_t endianness = 0;    // raw bitfield, see GuestEndian
    uint32_t baseAddress = 0;   // reconstructed: (field << 12) | (addr & 0xFFF)
    uint32_t mipAddress = 0;

    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depthOrArraySize = 1;  // 1 for 1D/2D-unstacked, 6 for cube
    uint32_t depth = 1;             // only meaningful for 3D
    bool stacked = false;

    uint32_t swizzle = 0;      // XE_GPU_TEXTURE_SWIZZLE, x/r/y/g/z/b/w/a
    int32_t expAdjust = 0;
    GuestTextureFilter magFilter = GuestTextureFilter::Point;
    GuestTextureFilter minFilter = GuestTextureFilter::Point;
    GuestTextureFilter mipFilter = GuestTextureFilter::Point;
    GuestAnisoFilter anisoFilter = GuestAnisoFilter::Disabled;
    uint32_t mipMinLevel = 0;
    uint32_t mipMaxLevel = 0;
    int32_t lodBias = 0;       // 5 fractional bits; divide by 32 for LOD units
    int32_t anisoBias = 0;
    uint32_t borderColor = 0;  // Xenos BorderColor enum, xenos.h:150-162
    bool forceBcWToMax = false;
    bool packedMips = false;
    bool hasBase = false;      // base_address field is non-zero
    GuestTextureDimension dimension = GuestTextureDimension::Invalid;

    uint32_t mipCount = 1;     // mipMaxLevel + 1, clamped to the extents
    uint32_t arraySize = 1;    // 6 for cube
    uint32_t guestByteSize = 0;  // estimated bytes touched, 64-bit-safe
    const char* refusal = nullptr;  // non-null when valid == false
};

// Decode the 24-byte big-endian `xe_gpu_texture_fetch_t` (xenos.h:1184-1285)
// at `be24`. `valid == false` (with `refusal` set) when the bytes cannot
// describe a texture we may touch: an unknown format code, a zero extent, an
// address field whose low 12 bits are non-zero (the descriptor is not
// 4 KB-aligned, so the byte offset cannot be trusted), or packed mips (the
// packed-mip-tile layout is not implemented - see texture_util.cc:116-207 and
// the Refusal::PackedMipLayout case in PlanTextureImport).
bool DecodeGuestTextureDescriptor(const uint8_t* be24, GuestTextureDesc& out);

// Per-mip guest layout, so the backend knows what to upload per subresource
// instead of inventing a chain. Strides follow Xenia's GetGuestTextureLayout
// (.research/xenia/src/xenia/gpu/texture_util.cc:304-353): mip dimensions come
// from next_pow2 of the base extents shifted by the level, rows/slices are
// aligned to 32 blocks, linear non-base rows to 256 bytes, and every array
// slice to 4 KB.
struct TextureMipLevel {
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depthOrArraySize = 0;
    uint32_t blocksX = 0;
    uint32_t blocksY = 0;
    uint32_t rowPitchBytes = 0;         // one block row
    uint32_t sliceStrideBytes = 0;      // one array slice (all z for 3D)
    uint32_t byteSize = 0;              // whole level, all slices
    uint32_t guestOffset = 0;           // from the level's base/mip address
};

struct TextureMipChain {
    bool valid = false;
    uint32_t levelCount = 0;
    TextureMipLevel levels[kTextureMaxMips] = {};
    uint32_t totalBytes = 0;   // sum of level byteSize
};

// Build the guest mip chain for `desc`. Returns false (chain.valid == false)
// for packed mips, a zero extent, a level count above kTextureMaxMips, or a
// 64-bit overflow in the size accumulation - all cases where guessing would
// mean reading outside the guest allocation.
bool BuildGuestMipChain(const GuestTextureDesc& desc, TextureMipChain& out);

// ---------------------------------------------------------------------------
// Import plan: the format-expansion layer.
// ---------------------------------------------------------------------------

// How the untiled linear bytes reach the GPU.
enum class TextureUploadMode : uint32_t {
    Refused = 0,
    DirectBlockCopy,  // host DXGI format is a BC/CTX block format of the same
                      // block shape: the untiled block rows are copied verbatim
    ScalarCopy,       // host DXGI format is scalar and byte-identical per texel
    CpuExpand,        // ExpandTextureToImportBytes() must run first
};

enum class TextureRefusal : uint32_t {
    None = 0,
    UnknownFormatCode,   // xenos format > 63
    NoHostFormat,        // dxgi == 0 in the table and no exact expander exists
    NonPowerOfTwoBlock,  // 32_32_32_FLOAT (12 bpb) - not addressable by XGAddress
    ZeroExtent,
    ExtentTooLarge,
    PackedMipLayout,
    EndianOnBlockCompressed,
    DepthCubeNotUploadable,  // depth-stencil / cube: needs an RT, not a copy
    UntileRefused,
    ExpanderMismatch,    // the plan says expand but the payload is not a whole
                         // number of blocks (a caller bug, refused not clipped)
};

const char* TextureRefusalName(TextureRefusal refusal);

// The complete description of one texture import. `ok == false` means the
// import MUST NOT happen: every refusal below is a named, counted, bounded and
// logged event (see SetTextureRefusalCallback), never a dropped texture.
struct TextureImportPlan {
    bool ok = false;
    TextureUploadMode mode = TextureUploadMode::Refused;
    TextureRefusal refusal = TextureRefusal::None;

    uint32_t xenosFormat = 0;
    const char* formatName = "unknown";
    uint32_t nativeDxgiFormat = 0;  // the ideal host form, 0 when there is none
    uint32_t importDxgiFormat = 0;  // the form the current backend gate accepts
    uint32_t blockWidth = 1;
    uint32_t blockHeight = 1;
    uint32_t texelBytes = 0;     // bytes per block (compressed) or per texel
    uint32_t blockBytes = 0;     // GetTextureBytesPerBlock()
    uint32_t blocksX = 0;        // mip 0, per array slice
    uint32_t blocksY = 0;
    uint32_t arraySize = 1;      // 6 for cube
    uint32_t mipCount = 1;
    uint32_t linearByteSize = 0;  // bytes of the untiled mip-0 payload
    bool isBlockCompressed = false;
    bool isResolvable = false;
    bool needsByteSwap = false;   // fetch-constant endianness != None
    uint32_t guestEndianness = 0;
    bool isApproximation = false; // reserved; nothing sets it today
    const char* note = nullptr;
};

// Decide how one guest texture must be imported. Pure decision function: it
// reads no memory and allocates nothing, so it is safe to call from the draw
// path and to unit-test headlessly.
//
// `width`/`height` are texels of mip 0, `depthOrArraySize` is 1 for a plain 2D
// surface (6 for cube, N for stacked), `mipMaxLevel` is the fetch constant's
// mip_max_level (ignored when `packedMips`), `endianness` is the fetch
// constant's endianness field, `tiled` is the fetch constant's `tiled` bit and
// `is3D` the effective dimension.
TextureImportPlan PlanTextureImport(uint32_t xenosFormat, uint32_t width, uint32_t height,
                                    uint32_t depthOrArraySize, uint32_t mipMaxLevel,
                                    uint32_t endianness, bool tiled, bool packedMips,
                                    bool is3D, bool isDepthStencil);

// Expand a CpuExpand plan's payload into the bytes CreateDecodedTexture() can
// take. The expander is bit-exact, not approximate: it is the CPU twin of
// Xenia's kDXT1ToRGBA8 / kDXT3ToRGBA8 / kDXT5ToRGBA8 / kDXT5AToR8 / kDXNToRG8
// load shaders (.research/xenia/src/xenia/gpu/texture_cache.cc:102-106), and
// the same 5/6/5 and 1/5/5/5 scalar unpackers. `linear` must hold
// plan->linearByteSize bytes; a short or ragged payload is refused
// (Refusal::ExpanderMismatch), never partially written.
bool ExpandTextureToImportBytes(const TextureImportPlan& plan, const uint8_t* linear,
                                uint32_t linearBytes, std::vector<uint8_t>& out,
                                TextureRefusal* outRefusal = nullptr);

// ---------------------------------------------------------------------------
// F-647: the block-row pitch contract.
//
// THE D3D12 CONTRACT. A subresource's copy layout comes from
// GetCopyableFootprints (d3d12.h:9186), which fills
// D3D12_SUBRESOURCE_FOOTPRINT {Format, Width, Height, Depth, RowPitch}
// (d3d12.h:3315-3321). That call is the authority for the DESTINATION pitch and
// for the buffer layout; the caller's only remaining job is the SOURCE pitch,
// which is a property of the format and the extent alone. For a block-compressed
// format the row is whole BLOCKS, so
//
//     blocksX  = ceil(width  / 4)          (all BC formats are 4x4)
//     srcPitch = blocksX * bytesPerBlock
//
// and `width * bytesPerBlock` is wrong for every width that is not a multiple
// of 4. At width 5 with BC3 that is 80 bytes per row instead of 16, so every
// row after the first is read 64 bytes late: a sheared image, not an error.
// The destination side is additionally 256-byte aligned
// (D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, d3d12.h:1374) -- which is exactly why it
// must come from the API and never be re-derived.
//
// The three functions below are the single derivation of the source pitch, so
// the table this module hands out (blockWidth/blockHeight/bitsPerPixel) cannot
// drift away from the contract without failing a build: VerifyBlockRowPitchContract
// re-checks it at runtime and the equivalent constexpr form is static_asserted
// for widths 1..8 in texture_decode.cpp, in EVERY translation unit that
// compiles this file.
// ---------------------------------------------------------------------------

// Bytes in one source block row of a `width`-texel span, 0 for an unknown
// format or a zero width. Equals ceil(width/blockWidth) * bytesPerBlock.
uint32_t SourceBlockRowPitchBytes(uint32_t xenosFormat, uint32_t width);
// Block rows in a `height`-texel span (ceil(height/blockHeight)).
uint32_t SourceBlockRowCount(uint32_t xenosFormat, uint32_t height);
// srcPitch * rows: the bytes one mip of one array slice must actually supply.
// This is the number a short-payload refusal must compare against.
uint32_t SourceBlockSpanBytes(uint32_t xenosFormat, uint32_t width, uint32_t height);

// Re-check the whole block-compressed part of the format table against the D3D12
// BC contract at runtime: every block-compressed row must be 4x4, must carry a
// BC DXGI_FORMAT, and its bytes/block must be the D3D12 block size for that
// format (8 for BC1/BC4, 16 for BC2/BC3/BC5); then, for widths 1..8, the
// derived pitch must equal ceil(w/4)*bytesPerBlock. Returns false on the first
// disagreement and reports the offending format and width through the out-params
// (either may be null). A one-shot init check, not a per-upload cost.
bool VerifyBlockRowPitchContract(uint32_t* offenderFormat = nullptr,
                                 uint32_t* offenderWidth = nullptr);

// The D3D12 block byte size for a BC DXGI format, 0 for anything else. Exposed
// so a consumer that carries its own host-format table (d3d12_backend.cpp's
// HostFormatFootprint) can assert against this instead of a second hand-typed
// number -- the repo has twice shipped hand-written constant tables that
// disagreed with the platform, silently.
constexpr uint32_t D3D12BlockCompressedBytes(uint32_t dxgiFormat);

// ---------------------------------------------------------------------------
// Refusal reporting. This module is linked into headless validators that do
// not link the logger, so it cannot log; it counts and hands the backend a
// callback instead. Bounded: the callback fires at most
// kMaxRefusalCallbacksPerFormat (8) times per xenos format.
// ---------------------------------------------------------------------------

constexpr uint32_t kMaxRefusalCallbacksPerFormat = 8;

using TextureRefusalCallback = void (*)(void* user, const TextureImportPlan& plan);

void SetTextureRefusalCallback(TextureRefusalCallback fn, void* user);
void ClearTextureRefusalCallback();
// Total refusals recorded per reason since process start (index by enum value).
uint64_t TextureRefusalCount(TextureRefusal refusal);
// Called internally by PlanTextureImport(); exposed for tests.
void NoteTextureRefusal(const TextureImportPlan& plan);

// ---------------------------------------------------------------------------
// F-648: the per-format import census.
//
// WHY THIS EXISTS. `TEX-IMPORT` = 0 in a 120 s soak (docs/HANDOFF_NEXT_AGENT.md
// :148) was read as "the guest never issued a texture import". That reading is
// not supported: the literal `TEX-IMPORT` exists in NO translation unit under
// src/ or generated/ (only in that doc line), so its zero is a vacuous zero of
// the F-057(6) kind -- a marker that was never implemented. The same is true of
// `GRCFVF`: `DrawPacketAccumulator::OnDrawBuild` DOES populate
// `m_currentPacket.grcFvf` (src/capture_hooks.cpp:195-203) and emits no line
// for it, so "GRCFVF = 0" measures the absence of a log call, not the absence
// of a drawable.
//
// Separately, `DrawPacket::textureCount` / `textureDescriptors[16]`
// (src/renderer/trace_types.h:107-108) have NO writer anywhere in the tree: the
// only mentions outside that declaration are comments in this header, in
// texture_decode.cpp and in d3d12_backend.cpp, plus the consumer at
// d3d12_backend.cpp `F-639:` DrawPacket::textureDescriptors[] ->
// resident textures -> SRVs. So a texture descriptor the guest binds is never
// captured, and the import path is currently reachable only through the legacy
// scalar entry point above. That is a CAPTURE GAP, provable by grep, not a
// workload fact.
//
// These counters are the fix that does not need the file that writes the
// packet. PlanTextureImport() bumps them on every call, so a consumer that
// prints them gets the per-format breakdown a `TEX-IMPORT` line needs, without
// this module having to log (it is linked into validators that do not link the
// logger -- CMakeLists.txt:610-612 and 1049-1058).
//
// Fixed 64-entry table, no allocation, O(1): safe on the draw path.
// ---------------------------------------------------------------------------

// Called internally by PlanTextureImport() from its single success exit, and by
// NoteTextureRefusal() for every refusal. Exposed for tests; a consumer must not
// call it directly or the census double-counts.
void NoteTextureImport(const TextureImportPlan& plan);
// Total PlanTextureImport() calls recorded for `xenosFormat` (0..63), and the
// grand total across all formats. Counts BOTH accepted and refused plans, so a
// non-zero total is proof the guest reached the import path at all -- which is
// the question `TEX-IMPORT = 0` was supposed to answer.
uint64_t TextureImportCount(uint32_t xenosFormat);
uint64_t TextureImportCountTotal();
// Accepted plans only: the call got past every refusal and produced
// plan.ok == true. A zero here with a non-zero TextureImportCount means the
// title IS issuing texture imports and every one of them is being refused,
// which is the single most important distinction a soak can make here.
uint64_t TextureImportAcceptedCount(uint32_t xenosFormat);
uint64_t TextureImportAcceptedTotal();
// The upload mode of the most recent plan for `xenosFormat`, so a census line
// can report DirectBlockCopy vs CpuExpand vs ScalarCopy per format without
// re-deriving it. Refused plans report TextureUploadMode::Refused.
TextureUploadMode TextureImportLastMode(uint32_t xenosFormat);

// ---------------------------------------------------------------------------
// Resolve description (EDRAM resolve / copy-dest).
// ---------------------------------------------------------------------------

// Xenos CopySampleSelect (xenos.h:1000-1013). A resolve picks one sample, one
// of the pair-wise averages, or all four.
enum class GuestCopySampleSelect : uint32_t {
    Sample0 = 0, Sample1 = 1, Sample2 = 2, Sample3 = 3,
    Avg01 = 4, Avg23 = 5, AvgAll = 6,
};

struct TextureResolveDesc {
    bool valid = false;
    const char* refusal = nullptr;
    uint32_t xenosFormat = 0;
    const char* formatName = "unknown";
    uint32_t hostDxgiFormat = 0;   // 0 => no host resolve form
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depth = 1;
    uint32_t sampleSelect = 0;     // GuestCopySampleSelect
    uint32_t extent[3] = {0, 0, 0};  // resolve rectangle, 8x8 aligned
    uint32_t copyDestPitch = 0;    // texels, aligned to 32 by the guest
    uint32_t copyDestHeight = 0;   // texel rows
    bool endianSwap = false;
    bool swapRedBlue = false;
    bool clearSource = false;      // EDRAM copy-and-clear
    uint32_t srcSubresource = 0;
    uint32_t dstSubresource = 0;
    uint32_t guestBaseAddress = 0;  // RB_COPY_DEST_BASE, absolute
    bool isApproximation = false;
    // Depth resolve never converts format or averages samples (xenos.h:911-924),
    // so it needs its own D3D12 path; refused here rather than faked.
    bool isDepthResolve = false;
};

// Cross-check the format table's `isResolvable` column against Xenia's
// ColorFormat set (xenos.h:543-570) - the subset of TextureFormat an EDRAM
// resolve may target. The two must be the same set; if they are not, one of
// them is wrong and BuildResolveDesc's refusals would be wrong with it. Returns
// false on the first disagreement; pass `offender` to learn which format.
// A one-shot assertion, not a per-resolve cost: call it once at init.
bool VerifyResolvableColumnMatchesXeniaColorFormat(uint32_t* offender = nullptr);

// Describe one resolve of a guest EDRAM colour surface into a guest texture.
// Returns valid == false (with `refusal` set) when the format is not
// resolvable (the format table's isResolvable column), when the sample select
// is out of range, or when the destination format is 64 bpp while the source
// is 32 bpp (a 2x tile-count difference, texture_util.cc: GetSurfacePitchTiles).
TextureResolveDesc BuildResolveDesc(uint32_t xenosFormat, uint32_t width, uint32_t height,
                                    uint32_t sampleSelect, bool endianSwap, bool swapRedBlue,
                                    bool clearSource, uint32_t extentX, uint32_t extentY,
                                    uint32_t copyDestPitch, uint32_t copyDestHeight,
                                    uint32_t guestBaseAddress);

// ---------------------------------------------------------------------------
// Sampler state (guest fetch constant -> host sampler descriptor).
// ---------------------------------------------------------------------------

// D3D12_TEXTURE_ADDRESS_MODE / D3D12_FILTER / D3D12_COMPARISON_FUNC numeric
// values, restated here so this module stays D3D12-free (the same reason the
// DXGI codes are duplicated in texture_decode.cpp).
//
// F-642: the previous revision of this table was INVENTED, not read off the SDK,
// and the rot was silent because the only static_asserts were behind
// `#ifdef MCLA_ASSERT_TEXTURE_DECODE_TABLE`. Seven filter entries and the whole
// COMPARISON_FUNC run were wrong. Every value below was re-read out of the real
// header -- Windows Kits 10.0.26100.0, um/d3d12.h, `enum D3D12_FILTER`
// (D3D12_FILTER_MIN_MAG_MIP_POINT .. D3D12_FILTER_MAXIMUM_ANISOTROPIC) and
// `enum D3D12_COMPARISON_FUNC` -- and is checked twice, unconditionally:
//
//  1. HERE, against the SDK's documented ENCODING rather than a second copy of
//     the numbers: D3D12_FILTER is
//     `reduction << 7 | min << 4 | mag << 2 | mip [| 0x40 aniso]`
//     (d3d12.h: `D3D12_FILTER_REDUCTION_TYPE_SHIFT`, `D3D12_MIN_FILTER_SHIFT`,
//     `D3D12_MAG_FILTER_SHIFT`, `D3D12_ANISOTROPIC_FILTERING_BIT`, and the
//     `D3D12_ENCODE_BASIC_FILTER` macro), so every min/mag/mip field is 0
//     (POINT) or 1 (LINEAR) and nothing else. That legality assert is what the
//     old values would have failed: 0x034/0x038/0x03C/0x030/0x020/0x0B4 all
//     carry a min or mag field of 2 or 3, which `D3D12_FILTER_TYPE` does not
//     define. The 0x044 entry is the one that would have RENDERED: its bit
//     pattern is identical to D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT
//     (0x004), i.e. a point min filter in place of a linear one, silently.
//  2. In pipeline_cache.cpp -- the translation unit in this module that already
//     includes <d3d12.h> -- by comparing each constant to the SDK enumerator by
//     name. That is the only place both sides of the comparison can be seen, and
//     it is unconditional, so a future edit to this table that drifts fails the
//     build instead of the frame. (d3d12_backend.cpp:57-97 keeps its own
//     asserts; the five it asserts unconditionally were already right, and its
//     `#ifdef MCLA_ASSERT_TEXTURE_DECODE_TABLE` block is now redundant -- it can
//     be deleted whenever that file's owner next touches it.)
enum : uint32_t {
    // enum D3D12_TEXTURE_ADDRESS_MODE, d3d12.h (WRAP..MIRROR_ONCE).
    kD3D12AddressModeWrap = 1,
    kD3D12AddressModeMirror = 2,
    kD3D12AddressModeClamp = 3,
    kD3D12AddressModeBorder = 4,
    kD3D12AddressModeMirrorOnce = 5,
    // enum D3D12_FILTER, d3d12.h. NOTE the SDK spelling of the fourth entry:
    // `D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT` = 0x4. There is no
    // D3D12_FILTER_MIN_POINT_MAG_MIP_POINT; this constant is the mis-spelled
    // name this module has always used for that mode (min point, mag LINEAR,
    // mip point) and it is kept -- d3d12_backend.cpp and texture_decode.cpp
    // both refer to it by this name -- because the decoder emits exactly that
    // combination for a point-min/linear-mag sampler. The entry was NOT
    // removed; its value was wrong (0x030, an illegal filter) and is now 0x4.
    kD3D12FilterMinMagMipPoint = 0x000,
    kD3D12FilterMinMagPointMipLinear = 0x001,
    kD3D12FilterMinPointMagMipPoint = 0x004,  // SDK: ..._MIN_POINT_MAG_LINEAR_MIP_POINT
    kD3D12FilterMinPointMagMipLinear = 0x005,
    kD3D12FilterMinLinearMagMipPoint = 0x010,
    kD3D12FilterMinLinearMagMipLinear = 0x011,
    kD3D12FilterMinMagMipLinear = 0x015,
    kD3D12FilterAnisotropic = 0x055,
    // Same eight standard modes with D3D12_FILTER_REDUCTION_TYPE_COMPARISON
    // (d3d12.h defines one COMPARISON_ constant per standard mode; the set is
    // reduction << 7, so COMPARISON_X == X | 0x80).
    kD3D12FilterComparisonMinMagMipPoint = 0x080,
    kD3D12FilterComparisonMinMagPointMipLinear = 0x081,
    kD3D12FilterComparisonMinPointMagMipPoint = 0x084,
    kD3D12FilterComparisonMinPointMagMipLinear = 0x085,
    kD3D12FilterComparisonMinLinearMagMipPoint = 0x090,
    kD3D12FilterComparisonMinLinearMagMipLinear = 0x091,
    kD3D12FilterComparisonMinMagMipLinear = 0x095,
    kD3D12FilterComparisonAnisotropic = 0x0D5,
    // enum D3D12_COMPARISON_FUNC, d3d12.h: NONE, then NEVER..ALWAYS as a DENSE
    // 1..8 run. The previous table ran NEVER=0..ALWAYS=7, i.e. it dropped NONE
    // and was off by one over the whole run, so every one of its values named
    // the WRONG comparison.
    kD3D12ComparisonFuncNone = 0,
    kD3D12ComparisonFuncNever = 1,
    kD3D12ComparisonFuncLess = 2,
    kD3D12ComparisonFuncEqual = 3,
    kD3D12ComparisonFuncLessEqual = 4,
    kD3D12ComparisonFuncGreater = 5,
    kD3D12ComparisonFuncNotEqual = 6,
    kD3D12ComparisonFuncGreaterEqual = 7,
    kD3D12ComparisonFuncAlways = 8,
};

// --- F-642, assertion 1: the table against the SDK's ENCODING, not a copy ---
// D3D12_FILTER_TYPE is POINT(0) or LINEAR(1) and nothing else, and D3D12_FILTER
// packs min/mag/mip at shifts 4/2/0. A value whose min, mag or mip field is > 1
// is not a filter the SDK defines, which is the check the old table failed.
constexpr bool D3D12FilterBitsAreLegal(uint32_t filter) {
    return ((filter >> 4) & 0x3u) <= 1u && ((filter >> 2) & 0x3u) <= 1u &&
           (filter & 0x3u) <= 1u;
}
constexpr bool D3D12FilterIsComparison(uint32_t filter) {
    return ((filter >> 7) & 0x3u) == 1u;
}

static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinMagPointMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinPointMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinPointMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinLinearMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinLinearMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterMinMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterAnisotropic), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinMagPointMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinPointMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinPointMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinLinearMagMipPoint), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinLinearMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonMinMagMipLinear), "filter drift");
static_assert(D3D12FilterBitsAreLegal(kD3D12FilterComparisonAnisotropic), "filter drift");

// The COMPARISON_ family is the standard family with the comparison reduction
// bit set and nothing else changed, so a pair that has drifted apart is caught
// here rather than in the frame. Parenthesised on purpose: `X == Y | 0x80` is a
// precedence bug waiting to happen (and clang-cl warns about it).
static_assert(kD3D12FilterComparisonMinMagMipPoint ==
                  (kD3D12FilterMinMagMipPoint | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinMagPointMipLinear ==
                  (kD3D12FilterMinMagPointMipLinear | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinPointMagMipPoint ==
                  (kD3D12FilterMinPointMagMipPoint | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinPointMagMipLinear ==
                  (kD3D12FilterMinPointMagMipLinear | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinLinearMagMipPoint ==
                  (kD3D12FilterMinLinearMagMipPoint | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinLinearMagMipLinear ==
                  (kD3D12FilterMinLinearMagMipLinear | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonMinMagMipLinear ==
                  (kD3D12FilterMinMagMipLinear | 0x80u), "filter drift");
static_assert(kD3D12FilterComparisonAnisotropic ==
                  (kD3D12FilterAnisotropic | 0x80u), "filter drift");

// Distinctness: a table where two names share a value is a mapping that cannot
// be reasoned about, and a typo in one of these values would produce exactly
// that. Checked pairwise through a constexpr sum-of-squares of differences, so
// adding a mode cannot silently duplicate one.
namespace detail {
constexpr uint32_t kFilterTable[] = {
    kD3D12FilterMinMagMipPoint, kD3D12FilterMinMagPointMipLinear,
    kD3D12FilterMinPointMagMipPoint, kD3D12FilterMinPointMagMipLinear,
    kD3D12FilterMinLinearMagMipPoint, kD3D12FilterMinLinearMagMipLinear,
    kD3D12FilterMinMagMipLinear, kD3D12FilterAnisotropic,
    kD3D12FilterComparisonMinMagMipPoint, kD3D12FilterComparisonMinMagPointMipLinear,
    kD3D12FilterComparisonMinPointMagMipPoint, kD3D12FilterComparisonMinPointMagMipLinear,
    kD3D12FilterComparisonMinLinearMagMipPoint, kD3D12FilterComparisonMinLinearMagMipLinear,
    kD3D12FilterComparisonMinMagMipLinear, kD3D12FilterComparisonAnisotropic,
};
// A non-zero result means some pair of entries is equal; the exact pair is named
// in the assert message's call site by bisecting on it if it ever fires.
constexpr uint32_t FilterTableDuplicateScore() {
    uint32_t score = 0;
    for (uint32_t i = 0; i < sizeof(kFilterTable) / sizeof(kFilterTable[0]); ++i)
        for (uint32_t j = i + 1; j < sizeof(kFilterTable) / sizeof(kFilterTable[0]); ++j)
            score += (kFilterTable[i] == kFilterTable[j]) ? 1u : 0u;
    return score;
}
}  // namespace detail
static_assert(detail::FilterTableDuplicateScore() == 0,
              "two D3D12 filter constants in texture_decode.h share a value");

// The COMPARISON_FUNC run is dense 0..8 (NONE, then NEVER..ALWAYS); the old
// table's 0..7 was off by one over the whole run.
static_assert(kD3D12ComparisonFuncNone == 0 &&
                  kD3D12ComparisonFuncNever == 1 && kD3D12ComparisonFuncAlways == 8,
              "D3D12_COMPARISON_FUNC run is NONE=0 then a dense NEVER=1..ALWAYS=8");

// Host sampler description, D3D12_SAMPLER_DESC field for field.
// `borderColor` is ALREADY the resolved FLOAT[4] the host needs, not the Xenos
// BorderColor enum: the decoder turns the guest enum (0 = ABGR black,
// 1 = ABGR white, 2/3 = the YCbCr blacks D3D12 cannot express) into RGBA here
// and reports a refusal string for the two it drops -- that translation is the
// decoder's job, so the consumer must not repeat it, and a consumer that saw
// the guest enum would have to invent the same mapping.
// `comparisonFunc` is a D3D12_COMPARISON_FUNC. F-642: it defaults to NONE (0),
// not NEVER -- D3D12 requires NONE for a descriptor whose Filter is not a
// comparison filter, and DecodeGuestSamplerState never sets `comparison`, so
// NEVER would have been a false "this is a comparison sampler" claim. The
// backend's `comparisonFunc != 0` refusal (d3d12_backend.cpp, `BindGuestSampler`)
// still holds after this: it refuses any decoded non-zero comparison func
// rather than forwarding a value whose Xenos origin cannot be checked.
// `hash` is the cache key for the backend's sampler heap slot.
struct HostSamplerDesc {
    uint32_t filter = kD3D12FilterMinMagMipLinear;
    uint32_t addressU = kD3D12AddressModeClamp;
    uint32_t addressV = kD3D12AddressModeClamp;
    uint32_t addressW = kD3D12AddressModeClamp;
    uint32_t maxAnisotropy = 1;
    uint32_t comparisonFunc = kD3D12ComparisonFuncNone;
    float mipLodBias = 0.0f;
    float minLod = 0.0f;
    float maxLod = 0.0f;   // 3.402823466e+38f == D3D12_FLOAT32_MAX
    float borderColor[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    bool comparison = false;
    uint64_t hash = 0;
};

// Decode the fetch constant's sampler half into a host descriptor. Rules, all
// taken from Xenia's SamplerInfo::Prepare (gpu/sampler_info.cc:20-51) and
// the architected field meanings in xenos.h:
//   - LOD bias: lod_bias has 5 fractional bits, so LOD units = lod_bias / 32.
//   - min/mag/mip filter kUseFetchConst resolves to the field's own value
//     (the fetch constant IS the fetch constant, so the union member wins).
//   - kBaseMap mip filter is a 2D-only no-mip-blend: the host gets
//     MIN_MAG_MIP_POINT with MaxLOD = mipMinLevel, so LOD is pinned.
//   - clamp_to_border / mirror_clamp_to_border -> D3D12 BORDER with the
//     Xenos BorderColor (0 = ABGR black, 1 = ABGR white, 2/3 = the YCbCr
//     blacks, which D3D12 cannot express -> those get black and a refusal
//     count, not a guess).
//   - aniso: Disabled/1x1 -> 1, Max2x1 -> 2, Max4x1 -> 4, Max8x1 -> 8,
//     Max16x1 -> 16. Aniso forces D3D12_FILTER_ANISOTROPIC.
//   - mipMinLevel/mipMaxLevel clamp MaxLOD = mipMaxLevel.
// `refusal` (optional) receives a short string when something in the fetch
// constant had to be dropped.
HostSamplerDesc DecodeGuestSamplerState(const GuestTextureDesc& desc,
                                        const char** refusal = nullptr);

} // namespace mcla::native