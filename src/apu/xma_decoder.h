#pragma once

// XMA (Xbox 360 / WMA-v2) decoding, native.
//
// SCOPE — READ THIS FIRST.
//
// This file implements, completely and correctly, the two layers of XMA that
// the reference implementation implements by hand:
//
//   1. The XMA *container / framing* layer -- 2048-byte packet headers, the
//      15-bit frame-length walk, split-frame reassembly across a packet
//      boundary, loop rewind, and the 64-byte guest XMA context struct.
//      Mirrored from Xenia apu/xma_context.cc + apu/xma_helpers.h (file:line
//      citations are on every function).
//
//   2. The *bitstream* layer (Huffman/VLC subframe decode, windowing +
//      overlap-add, IMDCT, quantisation) is NOT here, because the reference
//      implementation does not contain it either: Xenia hands the assembled
//      frame straight to FFmpeg's AV_CODEC_ID_XMAFRAMES decoder
//      (.research/xenia/src/xenia/apu/xma_context.cc:67 avcodec_find_decoder,
//      :588 avcodec_send_packet, :594 avcodec_receive_frame). The actual
//      frame decoder lives in FFmpeg libavcodec/xma2dec.c, credited by Xenia
//      at xma_context.cc:34-35. That file is NOT in this repo's FFmpeg
//      checkout (.research/xenia/third_party/FFmpeg/libavcodec/ has
//      xma_parser.c but no xma2dec.c) and it is a 20-Huffman-table,
//      IMDCT/overlap-add codec that cannot be re-derived from memory without
//      producing noise. Per the "a wrong decoder is worse than no decoder"
//      rule, it is left out and the seam is explicit below
//      (SetFrameDecoder). With no decoder registered the framing layer
//      reports kNoBackend, consumes nothing, writes nothing, and never clears
//      output_buffer_valid -- i.e. it fails LOUDLY and STATIONARY, not
//      falsely-progressing.
//
// Everything is header-only on purpose: src/apu/audio.cpp is already listed
// in CMakeLists.txt:134, and CMakeLists.txt is not owned by this file's
// author, so a new .cpp here would silently never compile. Including this
// header guarantees the unit is built and type-checked.
//
// Guest data is big-endian; every multi-byte read below goes through
// BeU16/BeU32 helpers. There is no reinterpret_cast on guest bytes anywhere
// in this file (house rule; see also ReadU32BE in the rest of src/).

#include <algorithm>
#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <tuple>
#include <vector>

namespace apu {
namespace xma {

// ---------------------------------------------------------------------------
// Geometry constants. Mirrored from Xenia apu/xma_context.h:135-143 and
// apu/xma_helpers.h:21. Independently corroborated by the vendored FFmpeg
// parser, .research/xenia/third_party/FFmpeg/libavcodec/xma_parser.c:36-45
// (buf_size % 2048, and buf[packet*2048+3] as the skip count).
// ---------------------------------------------------------------------------
inline constexpr uint32_t kBytesPerPacket = 2048;   // xma_context.h:135
inline constexpr uint32_t kBitsPerPacket = 16384;   // xma_context.h:136 (2048 * 8)
inline constexpr uint32_t kBitsPerHeader = 33;      // xma_context.h:137
inline constexpr uint32_t kBytesPerSample = 2;      // xma_context.h:139
inline constexpr uint32_t kSamplesPerFrame = 512;   // xma_context.h:140
inline constexpr uint32_t kSamplesPerSubframe = 128;// xma_context.h:141
inline constexpr uint32_t kBytesPerFrameChannel =
    kSamplesPerFrame * kBytesPerSample;              // xma_context.h:142-143 -> 1024
inline constexpr uint32_t kBytesPerSubframeChannel =
    kSamplesPerSubframe * kBytesPerSample;           // xma_context.h:144-145 -> 256
inline constexpr uint32_t kMaxFrameLength = 0x7FFF;  // xma_helpers.h:21

// ---------------------------------------------------------------------------
// Explicit big-endian scalar reads (charter: never reinterpret_cast guest data)
// ---------------------------------------------------------------------------
inline uint16_t BeU16(const uint8_t* p) {
    return static_cast<uint16_t>((static_cast<uint16_t>(p[0]) << 8) | p[1]);
}

inline uint32_t BeU32(const uint8_t* p) {
    return (static_cast<uint32_t>(p[0]) << 24) | (static_cast<uint32_t>(p[1]) << 16) |
           (static_cast<uint32_t>(p[2]) << 8) | static_cast<uint32_t>(p[3]);
}

inline void StoreBeU32(uint8_t* p, uint32_t v) {
    p[0] = static_cast<uint8_t>(v >> 24);
    p[1] = static_cast<uint8_t>(v >> 16);
    p[2] = static_cast<uint8_t>(v >> 8);
    p[3] = static_cast<uint8_t>(v);
}

// ---------------------------------------------------------------------------
// BitReader: MSB-first bit cursor over a byte range.
//
// XMA is big-endian / MSB-first; the packet header field split in
// Xenia apu/xma_helpers.h:30-31 (((p[0]&3)<<13) | (p[1]<<5) | (p[2]>>3)) only
// reconstructs under MSB-first ordering, and the frame-length walk in
// xma_context.cc:258 reads a 15-bit length off the same cursor. Every read is
// bounds-checked and leaves the cursor unchanged on failure, so a truncated
// tail returns false instead of reading past the packet (Xenia asserts here;
// we return a status, because a guest-driven decoder cannot assert).
// ---------------------------------------------------------------------------
class BitReader {
public:
    BitReader() = default;
    BitReader(const uint8_t* data, size_t sizeBytes, size_t offsetBits = 0)
        : data_(data), sizeBits_(sizeBytes * 8), offset_(offsetBits) {}

    size_t offset_bits() const { return offset_; }
    size_t size_bits() const { return sizeBits_; }
    size_t bits_remaining() const { return offset_ < sizeBits_ ? sizeBits_ - offset_ : 0; }
    void set_offset(size_t bits) { offset_ = bits; }
    const uint8_t* data() const { return data_; }

    bool peek(uint32_t count, uint32_t* out) const {
        if (count > 32 || count > bits_remaining()) return false;
        uint32_t v = 0;
        size_t o = offset_;
        for (uint32_t i = 0; i < count; ++i) {
            const size_t bit = o + i;
            const uint32_t byteIdx = static_cast<uint32_t>(bit >> 3);
            const uint32_t bitIdx = 7u - static_cast<uint32_t>(bit & 7u);
            if (byteIdx >= (sizeBits_ >> 3)) return false;
            v = (v << 1) | ((data_[byteIdx] >> bitIdx) & 1u);
        }
        *out = v;
        return true;
    }

    bool read(uint32_t count, uint32_t* out) {
        if (!peek(count, out)) return false;
        offset_ += count;
        return true;
    }

    bool advance(uint32_t count) {
        if (count > bits_remaining()) {
            offset_ = sizeBits_;
            return false;
        }
        offset_ += count;
        return true;
    }

    // Copy `count` bits MSB-first into `dst` as whole bytes, zero-padding the
    // final byte. Returns the number of significant bits left in dst[0] at
    // the low end (Xenia's split_frame_padding_start_, xma_context.cc:546,
    // which is `offset` from BitStream::Copy there).
    uint32_t copy_bits(uint8_t* dst, uint32_t count) const {
        const uint32_t needed = (count + 7u) / 8u;
        std::memset(dst, 0, needed);
        uint32_t bitIdx = 0;
        for (uint32_t i = 0; i < count; ++i) {
            const size_t bit = offset_ + i;
            const uint32_t byteIdx = static_cast<uint32_t>(bit >> 3);
            const uint32_t shift = 7u - static_cast<uint32_t>(bit & 7u);
            if (byteIdx >= (sizeBits_ >> 3)) break;
            if ((data_[byteIdx] >> shift) & 1u) {
                dst[bitIdx >> 3] |= static_cast<uint8_t>(0x80u >> (bitIdx & 7u));
            }
            ++bitIdx;
        }
        return count & 7u;  // bits of padding at the end of the last byte
    }

private:
    const uint8_t* data_ = nullptr;
    size_t sizeBits_ = 0;
    size_t offset_ = 0;
};

// ---------------------------------------------------------------------------
// Packet header accessors. Mirrored verbatim from Xenia
// .research/xenia/src/xenia/apu/xma_helpers.h:24-44 (which wraps
// xma_context.cc's GetPacketFrameCount/GetPacketFrameOffset/GetPacketSkipCount
// uses). Packet 0 is `data`, a 2048-byte array, already byte-addressed by
// the caller -- the guest-visible struct is byte-addressed on the 360 too.
// ---------------------------------------------------------------------------

// Number of frames that BEGIN in this packet. xma_helpers.h:24-26.
inline uint32_t PacketFrameCount(const uint8_t* packet) {
    return static_cast<uint32_t>(packet[0] >> 2);
}

// Bit offset of the first frame's 15-bit length field, +32 for the header.
// xma_helpers.h:29-38 (Xenia's "if (val > kBitsPerPacket - kBitsPerHeader) return -1"
// guard is commented out there; the caller-side check lives in
// GetPacketFrameCount, xma_context.cc:799, and is reproduced below).
inline uint32_t PacketFrameOffset(const uint8_t* packet) {
    const uint32_t v = (static_cast<uint32_t>(packet[0] & 0x3u) << 13) |
                       (static_cast<uint32_t>(packet[1]) << 5) |
                       (static_cast<uint32_t>(packet[2]) >> 3);
    return v + 32;
}

// 3 bits at packet[2]. Always 1 for XMA2 / 0 for XMA1 -- see the sanity check
// in Xenia xma_context.cc:833. xma_helpers.h:40-42.
inline uint32_t PacketMetadata(const uint8_t* packet) {
    return static_cast<uint32_t>(packet[2] & 0x7u);
}

// packet[3]: packets to skip after this one. xma_helpers.h:44. Corroborated
// independently by FFmpeg xma_parser.c:42 (s->skip_packets = buf[...+3] + 1).
inline uint32_t PacketSkipCount(const uint8_t* packet) {
    return static_cast<uint32_t>(packet[3]);
}

// ---------------------------------------------------------------------------
// The 64-byte guest XMA context ("XMA_CONTEXT_DATA").
//
// Xenia declares it as a packed 32-bit bitfield struct and loads it by
// copy_and_swap of 16 words (xma_context.h:49-123, load at :111-115, store at
// :117-121). We keep the same 16-word layout and the same field bit positions,
// but as d[16] + named accessors rather than a C++ bitfield struct, for two
// reasons: (a) the byte order of every field is then an explicit BE read/write
// rather than a memcpy-and-byteswap of a struct, which is what the house rule
// asks for; (b) MSVC bitfield packing of a 64-bit struct is not something to
// re-verify per build. Field positions are transcribed from xma_context.h and
// the accessor comment carries the xma_context.h line it came from.
// ---------------------------------------------------------------------------
struct ContextData {
    uint32_t d[16] = {};

    static constexpr size_t kSizeBytes = 64;  // xma_context.h:123 static_assert_size

    // --- load/store the 16 big-endian words at a guest address -------------
    // Xenia xma_context.h:111-121.
    void load(const uint8_t* guest) {
        for (size_t i = 0; i < 16; ++i) d[i] = BeU32(guest + i * 4);
    }
    void store(uint8_t* guest) const {
        for (size_t i = 0; i < 16; ++i) StoreBeU32(guest + i * 4, d[i]);
    }

    // --- DWORD 0 (xma_context.h:51-60) -------------------------------------
    uint32_t input_buffer_0_packet_count() const { return d[0] & 0xFFFu; }
    void set_input_buffer_0_packet_count(uint32_t v) { d[0] = (d[0] & ~0xFFFu) | (v & 0xFFFu); }
    uint32_t loop_count() const { return (d[0] >> 12) & 0xFFu; }
    void set_loop_count(uint32_t v) { d[0] = (d[0] & ~(0xFFu << 12)) | ((v & 0xFFu) << 12); }
    uint32_t input_buffer_0_valid() const { return (d[0] >> 20) & 1u; }
    void set_input_buffer_0_valid(uint32_t v) { d[0] = (d[0] & ~(1u << 20)) | ((v & 1u) << 20); }
    uint32_t input_buffer_1_valid() const { return (d[0] >> 21) & 1u; }
    void set_input_buffer_1_valid(uint32_t v) { d[0] = (d[0] & ~(1u << 21)) | ((v & 1u) << 21); }
    uint32_t output_buffer_block_count() const { return (d[0] >> 22) & 0x1Fu; }
    void set_output_buffer_block_count(uint32_t v) {
        d[0] = (d[0] & ~(0x1Fu << 22)) | ((v & 0x1Fu) << 22);
    }
    uint32_t output_buffer_write_offset() const { return (d[0] >> 27) & 0x1Fu; }
    void set_output_buffer_write_offset(uint32_t v) { d[0] = (d[0] & ~(0x1Fu << 27)) | ((v & 0x1Fu) << 27); }

    // --- DWORD 1 (xma_context.h:63-75) -------------------------------------
    uint32_t input_buffer_1_packet_count() const { return d[1] & 0xFFFu; }
    void set_input_buffer_1_packet_count(uint32_t v) { d[1] = (d[1] & ~0xFFFu) | (v & 0xFFFu); }
    uint32_t loop_subframe_start() const { return (d[1] >> 12) & 0x3u; }
    void set_loop_subframe_start(uint32_t v) { d[1] = (d[1] & ~(0x3u << 12)) | ((v & 0x3u) << 12); }
    uint32_t loop_subframe_end() const { return (d[1] >> 14) & 0x7u; }
    void set_loop_subframe_end(uint32_t v) { d[1] = (d[1] & ~(0x7u << 14)) | ((v & 0x7u) << 14); }
    uint32_t loop_subframe_skip() const { return (d[1] >> 17) & 0x7u; }
    void set_loop_subframe_skip(uint32_t v) { d[1] = (d[1] & ~(0x7u << 17)) | ((v & 0x7u) << 17); }
    uint32_t subframe_decode_count() const { return (d[1] >> 20) & 0xFu; }
    void set_subframe_decode_count(uint32_t v) { d[1] = (d[1] & ~(0xFu << 20)) | ((v & 0xFu) << 20); }
    uint32_t subframe_skip_count() const { return (d[1] >> 24) & 0x7u; }
    void set_subframe_skip_count(uint32_t v) { d[1] = (d[1] & ~(0x7u << 24)) | ((v & 0x7u) << 24); }
    uint32_t sample_rate() const { return (d[1] >> 27) & 0x3u; }
    void set_sample_rate(uint32_t v) { d[1] = (d[1] & ~(0x3u << 27)) | ((v & 0x3u) << 27); }
    uint32_t is_stereo() const { return (d[1] >> 29) & 1u; }
    void set_is_stereo(uint32_t v) { d[1] = (d[1] & ~(1u << 29)) | ((v & 1u) << 29); }
    uint32_t output_buffer_valid() const { return (d[1] >> 31) & 1u; }
    void set_output_buffer_valid(uint32_t v) { d[1] = (d[1] & ~(1u << 31)) | ((v & 1u) << 31); }

    // --- DWORD 2 (xma_context.h:78-79) -------------------------------------
    uint32_t input_buffer_read_offset() const { return d[2] & 0x3FFFFFFu; }
    void set_input_buffer_read_offset(uint32_t v) { d[2] = (d[2] & ~0x3FFFFFFu) | (v & 0x3FFFFFFu); }

    // --- DWORD 3 (xma_context.h:82-84) -------------------------------------
    uint32_t loop_start() const { return d[3] & 0x3FFFFFFu; }
    void set_loop_start(uint32_t v) { d[3] = (d[3] & ~0x3FFFFFFu) | (v & 0x3FFFFFFu); }

    // --- DWORD 4 (xma_context.h:87-90) -------------------------------------
    uint32_t loop_end() const { return d[4] & 0x3FFFFFFu; }
    void set_loop_end(uint32_t v) { d[4] = (d[4] & ~0x3FFFFFFu) | (v & 0x3FFFFFFu); }
    uint32_t packet_metadata() const { return (d[4] >> 26) & 0x1Fu; }
    uint32_t current_buffer() const { return (d[4] >> 31) & 1u; }
    void set_current_buffer(uint32_t v) { d[4] = (d[4] & ~(1u << 31)) | ((v & 1u) << 31); }

    // --- DWORDs 5-8: physical pointers (xma_context.h:92-100) --------------
    uint32_t input_buffer_0_ptr() const { return d[5]; }
    void set_input_buffer_0_ptr(uint32_t v) { d[5] = v; }
    uint32_t input_buffer_1_ptr() const { return d[6]; }
    void set_input_buffer_1_ptr(uint32_t v) { d[6] = v; }
    uint32_t output_buffer_ptr() const { return d[7]; }
    void set_output_buffer_ptr(uint32_t v) { d[7] = v; }
    uint32_t work_buffer_ptr() const { return d[8]; }
    void set_work_buffer_ptr(uint32_t v) { d[8] = v; }

    // --- DWORD 9 (xma_context.h:102-106) -----------------------------------
    uint32_t output_buffer_read_offset() const { return d[9] & 0x1Fu; }
    void set_output_buffer_read_offset(uint32_t v) { d[9] = (d[9] & ~0x1Fu) | (v & 0x1Fu); }
    uint32_t stop_when_done() const { return (d[9] >> 30) & 1u; }
    uint32_t interrupt_when_done() const { return (d[9] >> 31) & 1u; }

    // sample_rate is a 2-bit enum, not Hz. Xenia xma_context.cc:213-226.
    uint32_t sample_rate_hz() const { return SampleRateHz(sample_rate()); }
    static uint32_t SampleRateHz(uint32_t id) {
        switch (id) {
            case 0: return 24000;
            case 1: return 32000;
            case 2: return 44100;
            case 3: return 48000;
            default: return 0;
        }
    }
};
static_assert(sizeof(ContextData) <= 64, "ContextData must not exceed the 64-byte guest struct");

// ---------------------------------------------------------------------------
// Framing walk over a block of XMA packets. Every function below is a direct
// port of the identically named Xenia static in
// .research/xenia/src/xenia/apu/xma_context.cc, with the difference that
// Xenia's assert_always() sites become a bool/0 return (a guest-driven walk
// cannot abort the host).
// ---------------------------------------------------------------------------

// Packet containing the frame at `bitOffset`. xma_context.cc:734-747.
inline int FramePacketNumber(size_t sizeBytes, uint64_t bitOffset) {
    const uint64_t sizeBits = static_cast<uint64_t>(sizeBytes) * 8;
    if (bitOffset >= sizeBits) return -1;
    return static_cast<int>((bitOffset >> 3) / kBytesPerPacket);
}

// (packet index, frame index within that packet). xma_context.cc:749-795.
inline std::tuple<int, int> FrameNumber(const uint8_t* block, size_t sizeBytes,
                                        uint32_t bitOffset) {
    const int packetIdx = FramePacketNumber(sizeBytes, bitOffset);
    if (packetIdx < 0 ||
        (static_cast<size_t>(packetIdx) + 1) * kBytesPerPacket > sizeBytes) {
        return {packetIdx, -2};
    }
    if (bitOffset == 0) return {packetIdx, -1};

    const uint8_t* packet = block + static_cast<size_t>(packetIdx) * kBytesPerPacket;
    const uint32_t firstFrameOffset = PacketFrameOffset(packet);
    BitReader stream(block, sizeBytes, static_cast<size_t>(packetIdx) * kBitsPerPacket +
                                              firstFrameOffset);

    int frameIdx = 0;
    while (true) {
        if (stream.bits_remaining() < 15) break;   // xma_context.cc:769
        if (stream.offset_bits() == bitOffset) break;
        uint32_t len = 0;
        if (!stream.read(15, &len)) break;
        if ((len - 15) > stream.bits_remaining()) break;  // xma_context.cc:778 (last frame)
        if (len == 0x7FFFu) break;                        // xma_context.cc:781 (invalid frame)
        if (!stream.advance(len - 16u)) break;            // xma_context.cc:786
        uint32_t more = 0;
        if (!stream.read(1, &more)) break;
        if (more == 0) break;                             // xma_context.cc:789
        ++frameIdx;
    }
    return {packetIdx, frameIdx};
}

// (frames in this packet INCLUDING the truncated tail one, isLastSplit).
// xma_context.cc:797-828.
inline std::tuple<int, bool> PacketFrameCountAndSplit(const uint8_t* packet) {
    const uint32_t firstFrameOffset = PacketFrameOffset(packet);
    // xma_context.cc:799 -- offset beyond packet end: nothing usable here.
    if (firstFrameOffset > kBitsPerPacket - kBitsPerHeader) return {0, false};

    BitReader stream(packet, kBytesPerPacket, firstFrameOffset);
    int count = 0;
    while (true) {
        ++count;
        if (stream.bits_remaining() < 15) return {count, true};  // xma_context.cc:810
        uint32_t len = 0;
        if (!stream.read(15, &len)) return {count, true};
        if ((len - 15) > stream.bits_remaining()) return {count, true};
        if (len == 0x7FFFu) return {count, true};
        if (!stream.advance(len - 16u)) return {count, true};
        uint32_t more = 0;
        if (!stream.read(1, &more)) return {count, true};
        if (more == 0) return {count, false};                    // xma_context.cc:824
    }
}

// Bit offset of the next frame; 0 = no further frame. Does NOT traverse
// packets. xma_context.cc:691-732.
inline uint32_t NextFrame(const uint8_t* block, size_t sizeBytes, uint32_t bitOffset) {
    const int packetIdx = FramePacketNumber(sizeBytes, bitOffset);
    BitReader stream(block, sizeBytes, bitOffset);

    if (stream.bits_remaining() < 15) return 0;  // xma_context.cc:702
    uint32_t len = 0;
    if (!stream.read(15, &len)) return 0;
    if ((len - 15) > stream.bits_remaining()) return 0;  // xma_context.cc:707 (TODO there)
    if (len >= kMaxFrameLength) return 0;                // xma_context.cc:713 (TODO there)

    if (!stream.advance(len - 16u)) return 0;  // xma_context.cc:721
    uint32_t more = 0;
    if (!stream.read(1, &more)) return 0;
    if (more == 0) return 0;  // xma_context.cc:723

    const uint32_t next = bitOffset + len;
    if (packetIdx < FramePacketNumber(sizeBytes, next)) return 0;  // xma_context.cc:728
    return next;
}

// Is `frameOffsetBits` a legal frame start in this block? xma_context.cc:228-276.
inline bool ValidFrameOffset(const uint8_t* block, size_t sizeBytes,
                             uint32_t frameOffsetBits) {
    const int packetNum = FramePacketNumber(sizeBytes, frameOffsetBits);
    if (packetNum < 0) return false;

    const uint8_t* packet = block + static_cast<size_t>(packetNum) * kBytesPerPacket;
    const uint32_t relativeOffsetBits = frameOffsetBits % kBitsPerPacket;
    const uint32_t firstFrameOffset = PacketFrameOffset(packet);
    if (firstFrameOffset > kBitsPerPacket) return false;  // xma_context.cc:241

    BitReader stream(packet, kBytesPerPacket, firstFrameOffset);
    while (true) {
        if (stream.offset_bits() == relativeOffsetBits) return true;
        if (stream.bits_remaining() < 15) return false;   // xma_context.cc:253
        uint32_t size = 0;
        if (!stream.read(15, &size)) return false;
        if ((size - 15) > stream.bits_remaining()) return false;  // xma_context.cc:259
        if (size == 0x7FFFu) return false;                       // xma_context.cc:262
        if (!stream.advance(size - 16u)) return false;
        uint32_t more = 0;
        if (!stream.read(1, &more)) return false;
        if (more == 0) return false;                             // xma_context.cc:270
    }
}

// ---------------------------------------------------------------------------
// The bitstream seam.
//
// Xenia's own frame decode is an FFmpeg AV_CODEC_ID_XMAFRAMES call
// (xma_context.cc:67, :588, :594); the XMA2 Huffman/IMDCT/overlap-add core is
// FFmpeg libavcodec/xma2dec.c, which is not in this repo (see the file header).
// We expose the identical shape -- a caller-supplied output buffer that the
// decoder fills -- so registering a real backend is a one-function change and
// nothing above this line has to move.
//
// Contract: `frame` is the assembled frame, `frameBytes` long, MSB-first,
// exactly as Xenia builds it in xma_frame_ (xma_context.cc:539-582): byte 0
// carries the XMA2 frame header whose top 3 bits are
// (bitsToEndOfFrame & 7) << 5 and whose next 3 are (bitsToEndOfBuffer & 7) << 2
// (xma_context.cc:581-582). `out` receives `kSamplesPerFrame * channels`
// INTERLEAVED float samples in [-1, 1] (Xenia produces planar
// AV_SAMPLE_FMT_FLTP, xma_context.cc:614, and interleaves in ConvertFrame,
// xma_context.cc:857-932; the seam hands over interleaved so the caller does
// not have to know about planar). Return 0 on success.
// ---------------------------------------------------------------------------
using FrameDecoderFn = int (*)(void* user, const uint8_t* frame, size_t frameBytes,
                               uint32_t sampleRateHz, uint32_t channels, float* out,
                               size_t outSampleCapacity);

enum class WorkStatus : int {
    kOk = 0,
    kNoWork = 1,       // not allocated / not kicked
    kNoBackend = 2,    // no FrameDecoderFn registered -- SEE FILE HEADER
    kNoOutputBuffer = 3,
    kNoInput = 4,
    kFramingError = 5, // offsets unusable; context is left untouched
    kDecodeError = 6,
};

// ---------------------------------------------------------------------------
// One XMA context: 64 bytes of guest state at guest_ptr, plus the host-side
// split-frame reassembly scratch that the guest never sees
// (xma_context.h:216-233).
// ---------------------------------------------------------------------------
class Context {
public:
    static constexpr uint32_t kStateBytes = 64;

    void setup(uint32_t id, uint8_t* guestPtr, uint32_t guestVa) {
        id_ = id;
        guestPtr_ = guestPtr;
        guestVa_ = guestVa;
        std::memset(scratch_.data(), 0, sizeof(scratch_));
        std::memset(pcm_.data(), 0, sizeof(pcm_));
        reset_split();
    }

    uint32_t id() const { return id_; }
    uint32_t guest_va() const { return guestVa_; }
    uint8_t* guest_ptr() const { return guestPtr_; }
    bool is_allocated() const { return allocated_; }
    bool is_enabled() const { return enabled_; }
    void set_allocated(bool v) { allocated_ = v; }
    void set_enabled(bool v) { enabled_ = v; }
    // Decoder (the owner) needs the lock for Enable/Disable/Clear so those
    // cannot race a Work() already in flight -- same invariant Xenia gets from
    // XmaContext::lock_ (xma_context.cc:94, :109, :137, :154, :161).
    std::mutex& mutex() { return lock_; }

    // --- host-side state accessors, all under `lock_` in Work() ------------
    ContextData read() const {
        ContextData c;
        if (guestPtr_) c.load(guestPtr_);
        return c;
    }
    void write(const ContextData& c) const {
        if (guestPtr_) c.store(guestPtr_);
    }

    // Xenia xma_context.cc:136-151 Clear().
    void Clear() {
        if (!guestPtr_) return;
        ContextData c;
        c.load(guestPtr_);
        c.set_input_buffer_0_valid(0);
        c.set_input_buffer_1_valid(0);
        c.set_output_buffer_valid(0);
        c.set_output_buffer_read_offset(0);
        c.set_output_buffer_write_offset(0);
        c.store(guestPtr_);
    }

    // Xenia xma_context.cc:159-167 Release() -- zero the whole 64 bytes.
    void Release() {
        if (guestPtr_) std::memset(guestPtr_, 0, kStateBytes);
        reset_split();
    }

    // Xenia xma_context.cc:125-134 Block().
    bool Block(bool poll) {
        if (!lock_.try_lock()) {
            if (poll) return false;
            lock_.lock();
        }
        lock_.unlock();
        return true;
    }

    void reset_split() {
        packetsSkip_ = 0;
        splitFrameLen_ = 0;
        splitFrameLenPartial_ = 0;
        splitFramePaddingStart_ = 0;
    }

    // Runs the framing + decode loop. Mirrors Xenia xma_context.cc:93-106
    // (Work) and :292-689 (Decode).
    //
    // `backend`/`backendUser` are the registered FrameDecoderFn pair. When the
    // function pointer is null the framing is NOT walked at all: we return
    // kNoBackend having touched neither the input read offset nor the output
    // ring, and without clearing output_buffer_valid. A half-walk that
    // consumed input without producing samples would desynchronise the guest's
    // loop bookkeeping and produce audible garbage -- the exact failure the
    // "no fakes" charter forbids.
    WorkStatus Work(FrameDecoderFn backend, void* backendUser, uint8_t* guestMemoryBase,
                    std::atomic<uint32_t>* framesDecoded) {
        if (backend == nullptr) return WorkStatus::kNoBackend;

        std::lock_guard<std::mutex> guard(lock_);
        if (!allocated_ || !enabled_) return WorkStatus::kNoWork;
        set_enabled(false);
        if (!guestPtr_ || guestMemoryBase == nullptr) return WorkStatus::kFramingError;

        ContextData data;
        data.load(guestPtr_);

        // xma_context.cc:317-325
        if (!data.output_buffer_valid()) return WorkStatus::kNoOutputBuffer;
        if (!data.input_buffer_0_valid() && !data.input_buffer_1_valid()) {
            data.set_output_buffer_valid(0);
            data.store(guestPtr_);
            return WorkStatus::kNoInput;
        }

        // xma_context.cc:337-343 -- input buffers are PHYSICAL pointers.
        const uint32_t in0va = data.input_buffer_0_valid() ? data.input_buffer_0_ptr() : 0;
        const uint32_t in1va = data.input_buffer_1_valid() ? data.input_buffer_1_ptr() : 0;
        const uint8_t* in0 = in0va ? guestMemoryBase + in0va : nullptr;
        const uint8_t* in1 = in1va ? guestMemoryBase + in1va : nullptr;
        const uint8_t* currentInput = data.current_buffer() ? in1 : in0;

        const size_t size0 =
            static_cast<size_t>(data.input_buffer_0_packet_count()) * kBytesPerPacket;
        const size_t size1 =
            static_cast<size_t>(data.input_buffer_1_packet_count()) * kBytesPerPacket;
        const size_t currentSize = data.current_buffer() ? size1 : size0;
        if (currentInput == nullptr || currentSize == 0) return WorkStatus::kNoInput;
        const size_t currentPacketCount = currentSize / kBytesPerPacket;

        // xma_context.cc:362-372 -- output ring is 256-byte blocks, physical.
        const uint32_t outva = data.output_buffer_ptr();
        if (outva == 0) return WorkStatus::kNoOutputBuffer;
        uint8_t* outBase = guestMemoryBase + outva;
        const size_t outCapacity =
            static_cast<size_t>(data.output_buffer_block_count()) * kBytesPerSubframeChannel;
        if (outCapacity == 0) return WorkStatus::kNoOutputBuffer;
        size_t outRead = static_cast<size_t>(data.output_buffer_read_offset()) *
                         kBytesPerSubframeChannel;
        size_t outWrite = static_cast<size_t>(data.output_buffer_write_offset()) *
                          kBytesPerSubframeChannel;
        if (outRead > outCapacity || outWrite > outCapacity) return WorkStatus::kFramingError;
        // Free window in the ring. NOTE read == write means FULL, not empty:
        // Xenia's RingBuffer::write_count() (xma_context.cc:370-377) is
        // (write - read), and a non-positive result has the capacity added back,
        // so the zero case yields the whole capacity. Getting this backwards
        // makes every freshly-kicked context decode nothing at all.
        size_t outRemaining = outWrite - outRead;
        if (outRemaining == 0) {
            outRemaining = outCapacity;
        } else if (outWrite < outRead) {
            outRemaining = outCapacity - outRead + outWrite;
        }
        const size_t frameBytes = kBytesPerFrameChannel << data.is_stereo();
        outRemaining -= outRemaining % frameBytes;  // xma_context.cc:379

        const uint32_t channels = data.is_stereo() ? 2u : 1u;
        WorkStatus result = WorkStatus::kOk;

        // xma_context.cc:388 -- decode until the output ring is full.
        while (outRemaining > 0) {
            if (!data.input_buffer_0_valid() && !data.input_buffer_1_valid()) break;

            // xma_context.cc:396
            const bool reuseInputBuffer = TrySetupNextLoop(&data, false);

            int packetIdx = 0;
            int frameIdx = 0;
            int frameCount = 0;
            bool frameLastSplit = false;
            const uint8_t* packet = nullptr;

            if (splitFrameLen_ != 0) {
                // xma_context.cc:434-470 -- continue a frame split over packets.
                packetIdx = FramePacketNumber(currentSize, data.input_buffer_read_offset());
                if (packetIdx < 0) {
                    result = WorkStatus::kFramingError;
                    break;
                }
                packet = currentInput + static_cast<size_t>(packetIdx) * kBytesPerPacket;
                std::tie(frameCount, frameLastSplit) = PacketFrameCountAndSplit(packet);
                frameIdx = -1;

                BitReader stream(currentInput,
                                 static_cast<size_t>(packetIdx + 1) * kBytesPerPacket,
                                 static_cast<size_t>(packetIdx) * kBitsPerPacket + 32);

                if (splitFrameLen_ > kMaxFrameLength) {
                    // xma_context.cc:447-458 -- the length word itself straddles
                    // the packet boundary; patch it back in.
                    const size_t at = stream.offset_bits();
                    stream.copy_bits(scratch_.data() + 1 +
                                         ((splitFrameLenPartial_ + splitFramePaddingStart_) / 8),
                                     15u - splitFrameLenPartial_);
                    stream.set_offset(at);
                    BitReader slen(scratch_.data() + 1, 15u + splitFramePaddingStart_);
                    slen.set_offset(splitFramePaddingStart_);
                    uint32_t nextLen = 0;
                    if (!slen.read(15, &nextLen)) {
                        result = WorkStatus::kFramingError;
                        break;
                    }
                    splitFrameLen_ = nextLen;
                }
                (void)frameCount;
                (void)frameLastSplit;
                stream.copy_bits(
                    scratch_.data() + 1 + ((splitFrameLenPartial_ + splitFramePaddingStart_) / 8),
                    splitFrameLen_ - splitFrameLenPartial_);
            } else {
                if (data.input_buffer_read_offset() % kBitsPerPacket == 0) {
                    // xma_context.cc:472-496 -- snap to a legal frame start.
                    const int packetNumber =
                        FramePacketNumber(currentSize, data.input_buffer_read_offset());
                    if (packetNumber < 0) {
                        result = WorkStatus::kFramingError;
                        break;
                    }
                    const uint32_t snap =
                        PacketFrameOffset(currentInput +
                                          static_cast<size_t>(packetNumber) * kBytesPerPacket) +
                        data.input_buffer_read_offset();
                    data.set_input_buffer_read_offset(snap);
                }

                if (!ValidFrameOffset(currentInput, currentSize,
                                      data.input_buffer_read_offset())) {
                    // xma_context.cc:498-504
                    SwapInputBuffer(&data);
                    result = WorkStatus::kFramingError;
                    break;
                }

                std::tie(packetIdx, frameIdx) =
                    FrameNumber(currentInput, currentSize, data.input_buffer_read_offset());
                if (packetIdx < 0 || frameIdx < 0) {
                    result = WorkStatus::kFramingError;
                    break;
                }
                packet = currentInput + static_cast<size_t>(packetIdx) * kBytesPerPacket;
                std::tie(frameCount, frameLastSplit) = PacketFrameCountAndSplit(packet);

                // xma_context.cc:528-547 -- size the frame, copy the partial
                // bytes, remember the bit padding.
                BitReader stream(currentInput,
                                 static_cast<size_t>(packetIdx + 1) * kBytesPerPacket,
                                 data.input_buffer_read_offset());
                splitFrameLenPartial_ = static_cast<uint32_t>(stream.bits_remaining());
                splitFrameLen_ = 0;
                if (splitFrameLenPartial_ >= 15) {
                    uint32_t len = 0;
                    if (!stream.peek(15, &len)) {
                        result = WorkStatus::kFramingError;
                        break;
                    }
                    splitFrameLen_ = len;
                } else {
                    splitFrameLen_ = kMaxFrameLength + 1;
                }

                std::memset(scratch_.data(), 0, sizeof(scratch_));
                splitFramePaddingStart_ = stream.copy_bits(
                    scratch_.data() + 1, (std::min)(splitFrameLen_, splitFrameLenPartial_));

                const bool frameIsSplit = frameLastSplit && (frameIdx >= frameCount - 1);
                if (frameIsSplit) {
                    // xma_context.cc:549-569 -- hop the skip packets and restart.
                    int skip = static_cast<int>(PacketSkipCount(packet)) + 1;
                    while (skip-- > 0) {
                        ++packetIdx;
                        if (packetIdx >= static_cast<int>(currentPacketCount)) {
                            if (!reuseInputBuffer && !TrySetupNextLoop(&data, true)) {
                                SwapInputBuffer(&data);
                            }
                            data.store(guestPtr_);
                            return WorkStatus::kOk;
                        }
                        packet += kBytesPerPacket;
                    }
                    data.set_input_buffer_read_offset(
                        static_cast<uint32_t>(packetIdx) * kBitsPerPacket);
                    continue;
                }
            }

            // --- assemble + decode one frame (xma_context.cc:573-624) ------
            const size_t frameTotalBits = splitFramePaddingStart_ + splitFrameLen_;
            const size_t packetBytes = 1u + ((frameTotalBits + 7u) / 8u);
            const size_t paddingEnd = packetBytes * 8u - (8u + frameTotalBits);
            scratch_[0] = static_cast<uint8_t>(((splitFramePaddingStart_ & 7u) << 5) |
                                                ((paddingEnd & 7u) << 2));
            reset_split();

            const int rc = backend(backendUser, scratch_.data(), packetBytes,
                                   data.sample_rate_hz(), channels, pcm_.data(),
                                   kSamplesPerFrame * 2);
            if (rc != 0) {
                result = WorkStatus::kDecodeError;
                break;
            }

            // xma_context.cc:622-626 -- write the BE int16 PCM into the ring.
            const size_t pcmBytes = frameBytes;
            const size_t bytesPerSample = 2u * channels;
            if (outWrite + pcmBytes <= outCapacity) {
                WritePcmBe(outBase + outWrite, pcm_.data(), channels);
            } else {
                // Wraps. outCapacity and outWrite are both multiples of 256
                // (the ring is sized in 256-byte blocks, xma_context.cc:363-368)
                // and 256 is a multiple of bytesPerSample, so the split lands on
                // a sample boundary and the division is exact.
                const size_t first = outCapacity - outWrite;
                WritePcmBe(outBase + outWrite, pcm_.data(), channels,
                           first / bytesPerSample);
                WritePcmBe(outBase, pcm_.data(), channels,
                           (pcmBytes - first) / bytesPerSample, first / bytesPerSample);
            }
            outWrite = (outWrite + pcmBytes) % outCapacity;
            outRemaining -= pcmBytes;
            data.set_output_buffer_write_offset(
                static_cast<uint32_t>(outWrite / kBytesPerSubframeChannel));
            if (framesDecoded) framesDecoded->fetch_add(1, std::memory_order_relaxed);

            // --- advance (xma_context.cc:630-677) ---------------------------
            uint32_t offset = NextFrame(currentInput, currentSize,
                                        data.input_buffer_read_offset());
            if (frameIdx + 1 >= frameCount) {
                int skip = static_cast<int>(PacketSkipCount(packet)) + 1;
                bool done = false;
                while (skip-- > 0) {
                    ++packetIdx;
                    if (packetIdx >= static_cast<int>(currentPacketCount)) {
                        if (!reuseInputBuffer && !TrySetupNextLoop(&data, true)) {
                            SwapInputBuffer(&data);
                        }
                        done = true;
                        break;
                    }
                    packet += kBytesPerPacket;
                }
                if (done) break;
                offset = PacketFrameOffset(packet) +
                         static_cast<uint32_t>(packetIdx) * kBitsPerPacket;
            }
            if (offset == 0 || frameIdx == -1) {
                if (packetIdx >= static_cast<int>(currentPacketCount)) {
                    if (!reuseInputBuffer && !TrySetupNextLoop(&data, true)) {
                        SwapInputBuffer(&data);
                    }
                    break;
                }
                offset = PacketFrameOffset(packet) +
                         static_cast<uint32_t>(packetIdx) * kBitsPerPacket;
            }
            data.set_input_buffer_read_offset(offset);
        }

        // xma_context.cc:686-688 -- only invalidate the output buffer if we
        // really wrote nothing into it. (The comparison is on the ring's byte
        // offsets, exactly as written there; note this is a different test from
        // the free-window computation above, which treats read == write as
        // FULL.)
        if (outWrite == static_cast<size_t>(data.output_buffer_read_offset()) *
                            kBytesPerSubframeChannel) {
            data.set_output_buffer_valid(0);
        }
        data.store(guestPtr_);
        return result;
    }

private:
    // Xenia xma_context.cc:169-178. No more frames in the current buffer.
    static void SwapInputBuffer(ContextData* d) {
        if (d->current_buffer() == 0) {
            d->set_input_buffer_0_valid(0);
        } else {
            d->set_input_buffer_1_valid(0);
        }
        d->set_current_buffer(d->current_buffer() ^ 1u);
        d->set_input_buffer_read_offset(0);
    }

    // Xenia xma_context.cc:180-197. loop_count 255 == XAUDIO2_LOOP_INFINITE
    // (see the comment at xma_context.cc:328-331), so it is not decremented.
    static bool TrySetupNextLoop(ContextData* d, bool ignoreInputBufferOffset) {
        if (d->loop_count() > 0 && d->loop_start() < d->loop_end() &&
            (ignoreInputBufferOffset ||
             d->input_buffer_read_offset() >= d->loop_end())) {
            d->set_input_buffer_read_offset(d->loop_start());
            if (d->loop_count() < 255) d->set_loop_count(d->loop_count() - 1);
            return true;
        }
        return false;
    }

    // float [-1,1] interleaved -> big-endian int16, saturating. Xenia
    // xma_context.cc:857-932 does the same on planar FFmpeg output; the
    // saturation is required because raw samples are not always in [-1,1]
    // (the comment at xma_context.cc:861-862 cites 1.095 in 5454082B).
    static void WritePcmBe(uint8_t* dst, const float* pcm, uint32_t channels,
                           size_t sampleCount = kSamplesPerFrame,
                           size_t sampleOffset = 0) {
        constexpr float kScale = 32767.0f;
        for (size_t i = 0; i < sampleCount; ++i) {
            for (uint32_t c = 0; c < channels; ++c) {
                float v = pcm[(sampleOffset + i) * channels + c] * kScale;
                if (v > 32767.0f) v = 32767.0f;
                if (v < -32768.0f) v = -32768.0f;
                const auto s = static_cast<int16_t>(v);
                dst[0] = static_cast<uint8_t>((static_cast<uint16_t>(s) >> 8) & 0xFFu);
                dst[1] = static_cast<uint8_t>(static_cast<uint16_t>(s) & 0xFFu);
                dst += 2;
            }
        }
    }

    uint32_t id_ = 0;
    uint32_t guestVa_ = 0;
    uint8_t* guestPtr_ = nullptr;
    std::mutex lock_;
    bool allocated_ = false;
    bool enabled_ = false;

    // Split-frame reassembly scratch. xma_context.h:229 is
    // std::array<uint8_t, 1 + 4096> xma_frame_ -- byte 0 is the XMA2 frame
    // header we synthesise, so 4097 here. kMaxFrameLength is 0x7FFF bits
    // = 4095.875 bytes, so 4097 covers the largest legal frame plus header.
    std::array<uint8_t, 1 + 4096> scratch_{};
    std::array<float, kSamplesPerFrame * 2> pcm_{};
    uint32_t packetsSkip_ = 0;
    uint32_t splitFrameLen_ = 0;
    uint32_t splitFrameLenPartial_ = 0;
    uint8_t splitFramePaddingStart_ = 0;
};

// ---------------------------------------------------------------------------
// The context array + the kick/lock/clear command surface.
//
// Mirrored from Xenia .research/xenia/src/xenia/apu/xma_decoder.cc:
//   kContextCount = 320                        xma_decoder.cc:83 / :130-136
//   GetContextId  (pointer -> index)           xma_decoder.cc:216-224
//   AllocateContext / ReleaseContext           xma_decoder.cc:226-247
//   BlockOnContext                             xma_decoder.cc:249-255
//   Enable / Disable / Clear per context       xma_decoder.cc:303-345
//
// The MMIO register file (xma_decoder.h:81 XmaRegisterFile, xma_decoder.cc:257-362
// ReadRegister/WriteRegister) is NOT reproduced: this build has no XMA MMIO
// aperture, and wiring one is a memory-region change outside src/apu/. What IS
// here is the same state machine driven programmatically, plus
// XMACreateContext/XMAReleaseContext semantics (item 2 of the task):
// the game-visible object is a 64-byte block of GUEST memory at a guest VA,
// exactly as xma_decoder.cc:122-136 sets up (SystemHeapAlloc of
// sizeof(XMA_CONTEXT_DATA) * kContextCount, 256-aligned, cached-less), and
// XMACreateContext hands back one of those VAs.
// ---------------------------------------------------------------------------
class Decoder {
public:
    // 320 contexts x 64 bytes = 20480 bytes, 256-aligned, carved out of the
    // host user heap at Setup() (xma_decoder.cc:122-125).
    static constexpr uint32_t kContextCount = 320;   // xma_decoder.cc:83
    static constexpr uint32_t kContextStride = 64;    // sizeof(XMA_CONTEXT_DATA)

    // `guestMemoryBase` is the base of the flat guest RAM image, so a context
    // pointer or an XMA physical buffer pointer is a direct offset into it
    // (xma_decoder.cc:101, :337-341, :362 all do TranslatePhysical into it).
    void Setup(uint8_t* guestMemoryBase, uint8_t* contextDataHost, uint32_t contextDataVa) {
        base_ = guestMemoryBase;
        dataHost_ = contextDataHost;
        dataVa_ = contextDataVa;
        for (uint32_t i = 0; i < kContextCount; ++i) {
            const uint32_t va = contextDataVa + i * kContextStride;
            contexts_[i].setup(i, contextDataHost + i * kContextStride, va);
        }
        framesDecoded_ = 0;
    }

    void Shutdown() {
        workerRunning_ = false;
        base_ = nullptr;
        dataHost_ = nullptr;
        dataVa_ = 0;
    }

    void set_frame_decoder(FrameDecoderFn fn, void* user) {
        backend_ = fn;
        backendUser_ = user;
    }
    bool has_frame_decoder() const { return backend_ != nullptr; }

    // First context VA of the array (xma_decoder.h:39-41 context_array_ptr).
    uint32_t context_array_ptr() const { return dataVa_; }

    // xma_decoder.cc:216-224.
    int ContextId(uint32_t guestPtr) const {
        const uint32_t first = dataVa_;
        const uint32_t last = dataVa_ + (kContextCount * kContextStride) - 1;
        if (guestPtr < first || guestPtr > last) return -1;
        if (guestPtr & 0x3Fu) return -1;  // xma_decoder.cc:222 assert_zero
        return static_cast<int>((guestPtr - first) >> 6);
    }

    // xma_decoder.cc:226-237. Returns the guest VA of the context, or 0 when
    // the array is full.
    uint32_t AllocateContext() {
        std::lock_guard<std::mutex> guard(allocLock_);
        for (uint32_t i = 0; i < kContextCount; ++i) {
            if (bitmap_[i]) continue;
            bitmap_[i] = 1;
            Context& ctx = contexts_[i];
            ctx.set_allocated(true);
            return ctx.guest_va();
        }
        return 0;
    }

    // xma_decoder.cc:239-247.
    void ReleaseContext(uint32_t guestPtr) {
        const int id = ContextId(guestPtr);
        if (id < 0) return;
        Context& ctx = contexts_[id];
        {
            std::lock_guard<std::mutex> guard(ctx.mutex());
            ctx.Release();
        }
        {
            std::lock_guard<std::mutex> guard(allocLock_);
            bitmap_[id] = 0;
        }
        ctx.set_allocated(false);
    }

    // xma_decoder.cc:249-255.
    bool BlockOnContext(uint32_t guestPtr, bool poll) {
        const int id = ContextId(guestPtr);
        if (id < 0) return false;
        return contexts_[id].Block(poll);
    }

    // xma_decoder.cc:310-319 (Context0Kick..Context9Kick) and :320-345
    // (Lock / Clear), reduced to "kick / lock / clear this one context" --
    // the bitmask fan-out over 10 registers x 32 bits is a pure decode of the
    // command word and the caller owns that word.
    void Enable(uint32_t guestPtr) {
        const int id = ContextId(guestPtr);
        if (id < 0) return;
        Context& ctx = contexts_[id];
        std::lock_guard<std::mutex> guard(ctx.mutex());
        ctx.set_enabled(true);
    }
    void Disable(uint32_t guestPtr) {
        const int id = ContextId(guestPtr);
        if (id < 0) return;
        Context& ctx = contexts_[id];
        std::lock_guard<std::mutex> guard(ctx.mutex());
        ctx.set_enabled(false);
    }
    void Clear(uint32_t guestPtr) {
        const int id = ContextId(guestPtr);
        if (id < 0) return;
        Context& ctx = contexts_[id];
        std::lock_guard<std::mutex> guard(ctx.mutex());
        ctx.Clear();
    }

    // xma_decoder.cc:155-189 WorkerThreadMain, minus the MMIO kick and minus
    // the pause fences (nothing in this build can pause the decoder).
    // Returns the number of contexts that did work.
    uint32_t WorkOnce() {
        uint32_t didWork = 0;
        for (uint32_t i = 0; i < kContextCount; ++i) {
            const WorkStatus st =
                contexts_[i].Work(backend_, backendUser_, base_, &framesDecoded_);
            if (st == WorkStatus::kOk) ++didWork;
        }
        return didWork;
    }

    uint32_t frames_decoded() const { return framesDecoded_.load(std::memory_order_relaxed); }
    bool worker_running() const { return workerRunning_; }
    void set_worker_running(bool v) { workerRunning_ = v; }

private:
    uint8_t* base_ = nullptr;
    uint8_t* dataHost_ = nullptr;
    uint32_t dataVa_ = 0;
    FrameDecoderFn backend_ = nullptr;
    void* backendUser_ = nullptr;
    std::array<Context, kContextCount> contexts_{};
    std::array<bool, kContextCount> bitmap_{};
    std::mutex allocLock_;
    std::atomic<uint32_t> framesDecoded_{0};
    bool workerRunning_ = false;
};

} // namespace xma
} // namespace apu
