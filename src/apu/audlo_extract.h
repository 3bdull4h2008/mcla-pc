#pragma once

// xarchive_audlo.rpf -> .xma members -> XMA packet blocks.
//
// Header-only, for the same reason as apu/xma_decoder.h: src/apu/audio.cpp is
// already in CMakeLists.txt:134 and CMakeLists.txt is not owned here, so a new
// .cpp would silently never be compiled.
//
// WHAT IS MEASURED vs WHAT IS AN ASSUMPTION -- read this before using the code.
//
// Measured (tools/rpf_offline.py header/islands/member against
// build/game_data/xarchive_audlo.rpf, 2026-09-28):
//
//   0x0000  52 50 46 33            'RPF3'
//   0x0004  00 48 00 00            tocSize   = 0x4800 = 18432  (LITTLE endian)
//   0x0008  3E 04 00 00            entries   = 0x043E = 1086    (LITTLE endian)
//   0x000C  00 00 00 00
//   0x0010  FF FF FF FF
//   0x0000..0x07FF  zero padding
//   0x0800..0x4FFF  high entropy, 34 of 35 512-byte blocks at ~8 bits/byte
//                    -> the TOC + filename section is AES ciphertext ON DISK.
//   size = 1463189504 (1395 MiB)
//
// Cross-check that pins the endianness: xarchive_cache.rpf has tocSize =
// 0x5D800 = 382976 and build/toc_parsed.bin -- the guest's own DECRYPTED copy
// of the cache TOC -- is exactly 382976 bytes. So (a) the header dwords are
// little-endian, and (b) the encrypted block is [0x800, 0x800 + tocSize).
// 1086 * 16 = 17376 records + 1056 bytes of filename section = 18432, exact.
//
// CONSEQUENCE, and it is the blocking one: the on-disk audlo TOC is ciphertext
// and the AES key is not available offline, so the set of .xma members in
// xarchive_audlo.rpf CANNOT be enumerated from the archive bytes alone. The
// only cleartext table is a dump of the guest's own parsed TOC (that is what
// build/toc_parsed.bin is for the cache archive, and no audlo equivalent
// exists yet). So this file is written to take that guest TOC dump as INPUT
// (TocDump below) and it parses the archive header itself. That is the honest
// shape: it is ready the moment someone dumps the audlo TOC, and it does not
// pretend to work today.
//
// The docs/MCLA_RPF3_Technical_Reference.txt copy disagrees with the measurement
// in two places and is NOT followed here: it puts the TOC at 0x1000 (measured:
// 0x800) and it says to read the header big-endian (measured: little-endian;
// the 'RPF3' magic is 4 raw bytes, which is why both readings "work" for the
// magic but only one works for the counts).

#include <xmem_lzx.h>

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

#include "xma_decoder.h"

namespace apu {
namespace audlo {

// ---------------------------------------------------------------------------
// Explicit little-endian reads.
//
// NOTE THE ASYMMETRY, it is deliberate and measured:
//   * RPF3 HEADER dwords            -> little-endian  (proof above)
//   * RPF3 TOC records              -> big-endian     (the guest runs on a
//                                     big-endian PPC and byte-swaps; see
//                                     tools/rpf_offline.py:62-72 be_words and
//                                     F-099)
//   * RIFF/WAVE chunk header/sizes  -> little-endian  (RIFF is LE by spec)
//   * XMA packets inside `data`     -> big-endian     (xma_helpers.h:30-31)
// Nothing here reinterpret_casts guest bytes.
// ---------------------------------------------------------------------------
inline uint16_t LeU16(const uint8_t* p) {
    return static_cast<uint16_t>(p[0] | (static_cast<uint16_t>(p[1]) << 8));
}
inline uint32_t LeU32(const uint8_t* p) {
    return static_cast<uint32_t>(p[0]) | (static_cast<uint32_t>(p[1]) << 8) |
           (static_cast<uint32_t>(p[2]) << 16) | (static_cast<uint32_t>(p[3]) << 24);
}
inline uint16_t BeU16R(const uint8_t* p) {
    return static_cast<uint16_t>((static_cast<uint16_t>(p[0]) << 8) | p[1]);
}

// ---------------------------------------------------------------------------
// Rockstar's Jenkins one-at-a-time hash of a member LEAF name.
//
// This is the only name form that exists: the RPF3 TOC record array holds no
// path text at all, it holds GtaO(leaf) (F-099, restated in
// tools/rpf_offline.py:4-8 and :24-27). Transcribed from
// tools/rpf_offline.py:42-59, which validates it against three leaf hashes the
// guest's parsed table shows (star_glow.fxc=A5EA667B, preload.list=0DB1C876,
// globaltex.list=3D9B8154). Case-sensitive.
// ---------------------------------------------------------------------------
inline uint32_t GtaOLeafHash(const char* leaf) {
    uint32_t h = 0;
    for (const char* q = leaf; *q; ++q) {
        h = (h + static_cast<uint8_t>(*q)) & 0xFFFFFFFFu;
        h = (h + (h << 10)) & 0xFFFFFFFFu;
        h ^= (h >> 6);
    }
    h = (h + (h << 3)) & 0xFFFFFFFFu;
    h ^= (h >> 11);
    return (h + (h << 15)) & 0xFFFFFFFFu;
}

// ---------------------------------------------------------------------------
// RPF3 header, measured above.
// ---------------------------------------------------------------------------
struct Rpf3Header {
    uint32_t tocSize = 0;
    uint32_t entryCount = 0;
    uint32_t unknown1 = 0;      // +0x0C
    uint32_t dataBaseAddress = 0;  // +0x10 (0xFFFFFFFF in both archives)
    static constexpr uint32_t kHeaderOffset = 0x0000;
    static constexpr uint32_t kTocOffset = 0x0800;
    static constexpr uint32_t kTocRecordBytes = 16;
    static constexpr uint32_t kMagic = 0x52504633u;  // 'RPF3', as 4 raw bytes

    static bool Parse(const uint8_t* archive, size_t size, Rpf3Header* out) {
        if (archive == nullptr || out == nullptr) return false;
        if (size < kTocOffset) return false;
        uint32_t magic = 0;
        for (int i = 0; i < 4; ++i) {
            magic = (magic << 8) | archive[kHeaderOffset + static_cast<size_t>(i)];
        }
        if (magic != kMagic) return false;
        out->tocSize = LeU32(archive + kHeaderOffset + 4);
        out->entryCount = LeU32(archive + kHeaderOffset + 8);
        out->unknown1 = LeU32(archive + kHeaderOffset + 12);
        out->dataBaseAddress = LeU32(archive + kHeaderOffset + 16);
        return true;
    }

    bool toc_in_range(size_t archiveSize) const {
        return static_cast<uint64_t>(kTocOffset) + tocSize <= archiveSize;
    }
};

// ---------------------------------------------------------------------------
// The guest's own cleartext TOC copy (F-099). 16-byte records, big-endian.
// The two record classes are told apart by bit31 of the THIRD word, which is
// exactly what the guest's own parser masks:
//
//   file       { GtaO(leaf), uncompressed_size, file_offset,        flag|index }
//   directory  { GtaO(name), 0,                0x8000'0000|child,  child_count }
//
// (schema from tools/rpf_offline.py:24-27; the third-word test is
// rec[2] & 0x80000000 and the index is rec[3] & 0x0FFFFFFF, so no flag bit is
// assumed on any record.)
// ---------------------------------------------------------------------------
struct TocRecord {
    uint32_t nameHash = 0;    // GtaO(leaf) for a file, GtaO(name) for a dir
    uint32_t a = 0;           // file: uncompressed size   dir: 0
    uint32_t b = 0;           // file: file offset         dir: 0x8000xxxx
    uint32_t c = 0;           // file: flag|index          dir: child_count
    bool is_directory = false;

    static TocRecord Parse(const uint8_t* rec) {
        TocRecord r;
        r.nameHash = xma::BeU32(rec + 0);
        r.a = xma::BeU32(rec + 4);
        r.b = xma::BeU32(rec + 8);
        r.c = xma::BeU32(rec + 12);
        r.is_directory = (r.b & 0x80000000u) != 0;
        return r;
    }
    uint32_t uncompressed_size() const { return a; }
    uint32_t file_offset() const { return b; }
    uint32_t index() const { return c & 0x0FFFFFFFu; }
};

// A guest TOC dump is exactly tocSize bytes (measured identity with
// build/toc_parsed.bin, 382976 == 0x5D800 for the cache archive), and only its
// first entryCount*16 bytes are records; the rest is the filename section,
// which carries no path text we can use (F-099).
class TocDump {
public:
    bool Load(const uint8_t* data, size_t size, uint32_t entryCount) {
        if (data == nullptr) return false;
        if (static_cast<uint64_t>(entryCount) * 16u > size) return false;
        records_.resize(entryCount);
        for (uint32_t i = 0; i < entryCount; ++i) {
            records_[i] = TocRecord::Parse(data + static_cast<size_t>(i) * 16u);
        }
        return true;
    }
    size_t size() const { return records_.size(); }
    const TocRecord& operator[](size_t i) const { return records_[i]; }
    const std::vector<TocRecord>& records() const { return records_; }

    // Find the record whose GtaO(leaf) matches. `foundDir` distinguishes a leaf
    // collision from a real hit, exactly like the guest's own lookup would.
    const TocRecord* FindLeaf(uint32_t leafHash, bool* foundDir = nullptr) const {
        for (const TocRecord& r : records_) {
            if (r.nameHash == leafHash) {
                if (foundDir) *foundDir = r.is_directory;
                return &r;
            }
        }
        if (foundDir) *foundDir = false;
        return nullptr;
    }

private:
    std::vector<TocRecord> records_;
};

// ---------------------------------------------------------------------------
// A `.xma` member resolved out of the archive.
// ---------------------------------------------------------------------------
struct XmaMember {
    uint32_t leafHash = 0;
    uint32_t fileOffset = 0;        // absolute, from the file start
    uint32_t storedSize = 0;        // bytes on disk for this member
    uint32_t uncompressedSize = 0;  // == storedSize when stored uncompressed
    uint32_t index = 0;
    bool storedUncompressed = false;
};

// Resolve every record in `toc` whose GtaO(leaf) is in `xmaLeafHashes`.
// `outStoredSize` must be able to hold one entry per leaf: the TOC record
// carries the UNCOMPRESSED size and the offset, but the on-disk length is
// (for a compressed member) not derivable from it -- see the note in
// MemberBytes() below. Pass nullptr only for an all-stored archive.
inline bool SelectXmaMembers(const TocDump& toc, const std::vector<uint32_t>& xmaLeafHashes,
                             std::vector<XmaMember>* out, uint32_t archiveSize) {
    if (out == nullptr) return false;
    out->clear();
    for (const TocRecord& r : toc.records()) {
        if (r.is_directory) continue;  // r.b & 0x80000000 -- the guest's own test
        bool wanted = false;
        for (uint32_t h : xmaLeafHashes) {
            if (h == r.nameHash) { wanted = true; break; }
        }
        if (!wanted) continue;
        XmaMember m;
        m.leafHash = r.nameHash;
        m.fileOffset = r.file_offset();
        m.uncompressedSize = r.uncompressed_size();
        // A member whose offset/size is already outside the archive cannot be
        // classified; skip it rather than report a range we cannot read.
        if (static_cast<uint64_t>(m.fileOffset) + m.uncompressedSize > archiveSize) continue;
        // Without the on-disk length we can only call a member STORED when its
        // offset is not inside the TOC block we already know about; see
        // MemberBytes() for the honest failure mode.
        m.storedSize = m.uncompressedSize;
        m.storedUncompressed = true;
        m.index = r.index();
        out->push_back(m);
    }
    return true;
}

// Classify a member's payload and hand back a pointer/length. Returns:
//   kOk             - `payload`/`payloadSize` are the member bytes verbatim.
//   kNeedsInflate   - the member is LZX-compressed; call
//                     MemberInflate() to expand it into your own buffer.
//   kOutOfRange     - offset/size fall outside the archive.
// The RPF3 "is it compressed" test is storedSize != uncompressedSize
// (tools/rpf_offline.py's `header` output reports the header fields; the
// comparison is the documented RPF3 rule). NOTE: because the record carries
// only the uncompressed size, the caller must supply the STORED size; pass the
// record's own `uncompressed_size` for a stored member, which is what
// SelectXmaMembers does.
enum class MemberStatus : int { kOk = 0, kNeedsInflate = 1, kOutOfRange = 2, kBadToc = 3 };

inline MemberStatus MemberBytes(const uint8_t* archive, size_t archiveSize,
                                const XmaMember& member, const uint8_t** payload,
                                size_t* payloadSize) {
    if (archive == nullptr || payload == nullptr || payloadSize == nullptr) {
        return MemberStatus::kBadToc;
    }
    if (member.storedUncompressed) {
        const uint64_t end =
            static_cast<uint64_t>(member.fileOffset) + member.uncompressedSize;
        if (end > archiveSize) return MemberStatus::kOutOfRange;
        *payload = archive + member.fileOffset;
        *payloadSize = member.uncompressedSize;
        return MemberStatus::kOk;
    }
    // Compressed: the on-disk length is not in the record. Report honestly
    // instead of guessing a length and reading the neighbour's bytes.
    return MemberStatus::kNeedsInflate;
}

// XMEM LZX expansion. Reuses the repo's existing host decoder
// (src/xmem_lzx.h, a faithful port of
// .research/360tools/tools/lzx_decompress.py). Header include only; no
// non-apu file is modified.
//
// ASSUMPTION, LABELLED: that decoder was written and validated for the RSC5
// .xsf UI containers (see its own header), NOT for RPF3 member payloads. RAGE
// uses the same XMEM/XComp family for archive members, so it is very likely
// correct here, but that is unverified -- MemberInflate is the single place to
// fix if the first real audlo member fails to inflate, and it is only ever
// reached on the kNeedsInflate path, so nothing else depends on the guess.
// `dst` receives exactly dstSize bytes; it must be the member's uncompressed
// size. The decoder appends into the vector, so pass an empty one.
inline bool MemberInflate(const uint8_t* src, size_t srcSize, std::vector<uint8_t>& dst,
                           size_t dstSize) {
    if (src == nullptr || dstSize == 0) return false;
    // window_bits=17 is the value the RAGE/XMEM containers in this project use
    // (src/xmem_lzx.h:10, "window_bits=17"). LABELED ASSUMPTION that RPF3
    // member payloads use the same window; it is the one knob here, and it is
    // the only thing to change if a real audlo member fails to inflate.
    mcla_lzx::Decoder d(/*window_bits=*/17);
    dst.clear();
    return d.decompress(src, srcSize, static_cast<uint32_t>(dstSize), dst);
}

// ---------------------------------------------------------------------------
// A `.xma` FILE is a RIFF/WAVE container: the XMA2 packet stream lives in the
// `data` chunk, and the XMA2 fmt extras carry the loop points the XMA context
// needs. Parsed here so a resolved member is one step from a
// xma::Decoder input block.
// ---------------------------------------------------------------------------
struct XmaFileView {
    // RIFF/WAVE are little-endian on disk; the XMA packets inside are not.
    static constexpr uint16_t kWavFormatXma1 = 0x000A;
    static constexpr uint16_t kWavFormatXma2 = 0x0165;
    // 18-byte WAVEFORMATEX + 14-byte XMA2 extras = the 34 bytes Xenia's
    // Xma2ExtraData is (xma_context.h:127-129, static_assert_size 34).
    static constexpr uint32_t kXma2FmtChunkBytes = 34;

    uint16_t formatTag = 0;
    uint16_t channels = 0;
    uint32_t sampleRate = 0;
    uint16_t loopBegin = 0;
    uint16_t loopEnd = 0;
    uint8_t loopCount = 0;
    uint8_t subframeData = 0;
    uint32_t packetBytes = 0;  // length of the packet block inside `data`
    uint32_t packetCount = 0;  // packetBytes / xma::kBytesPerPacket
    const uint8_t* packets = nullptr;

    // The XMA2 `sample_rate` extra is 24.8 fixed point and is the authoritative
    // rate (the RIFF `nSamplesPerSec` field is not always filled in). Returns
    // Hz, 0 if absent.
    uint32_t sample_rate_hz() const { return sampleRate; }

    inline bool Parse(const uint8_t* file, size_t size) {
        if (file == nullptr || size < 12) return false;
        if (std::memcmp(file, "RIFF", 4) != 0) return false;
        if (std::memcmp(file + 8, "WAVE", 4) != 0) return false;

        size_t pos = 12;
        bool haveFmt = false;
        while (pos + 8 <= size) {
            char id[5] = {0, 0, 0, 0, 0};
            std::memcpy(id, file + pos, 4);
            const uint32_t chunkBytes = LeU32(file + pos + 4);
            const size_t body = pos + 8;
            if (static_cast<uint64_t>(body) + chunkBytes > size) break;

            if (std::memcmp(id, "fmt ", 4) == 0) {
                if (chunkBytes < 18) return false;
                formatTag = LeU16(file + body + 0);
                channels = LeU16(file + body + 2);
                sampleRate = LeU32(file + body + 4);
                if (formatTag != kWavFormatXma1 && formatTag != kWavFormatXma2) {
                    return false;
                }
                if (formatTag == kWavFormatXma2 && chunkBytes >= kXma2FmtChunkBytes) {
                    loopBegin = LeU16(file + body + 20);
                    loopEnd = LeU16(file + body + 22);
                    loopCount = file[body + 24];
                    subframeData = file[body + 25];
                    // +26 is channel mask, +27..29 reserved, +30..33 sample_rate
                    // as 24.8 fixed point. The fixed-point form is the one the
                    // XMA hardware actually uses.
                    const uint32_t fixed = LeU32(file + body + 30);
                    if (fixed != 0) sampleRate = fixed >> 8;
                }
                haveFmt = true;
            } else if (std::memcmp(id, "data", 4) == 0) {
                if (!haveFmt) return false;  // fmt must precede data
                packets = file + body;
                packetBytes = chunkBytes;
            }

            // RIFF chunks are word-aligned: an odd length is followed by a pad
            // byte that is not part of the chunk.
            pos = body + chunkBytes + (chunkBytes & 1u);
        }
        if (!haveFmt || packets == nullptr || packetBytes == 0) return false;
        // An XMA packet stream is a whole number of 2048-byte packets
        // (xma_context.h:135; FFmpeg xma_parser.c:36 asserts the same).
        packetCount = packetBytes / xma::kBytesPerPacket;
        return packetCount > 0;
    }
};

// Fill a 64-byte XmaContextData from an XmaFileView so a Decoder context can be
// pointed at a member's packets. Mirrors the context-data field layout in
// apu/xma_decoder.h (transcribed from Xenia apu/xma_context.h:49-123).
inline void SeedContextFromFile(xma::ContextData* data, const XmaFileView& view,
                                uint32_t sampleRateEnum) {
    if (data == nullptr) return;
    std::memset(data, 0, sizeof(*data));
    data->set_input_buffer_0_valid(1);
    // packetCount is capped at 4095 by the 12-bit field
    // (xma_context.h:51-53: "Max 4095 packets").
    const uint32_t pkts =
        (view.packetCount > 4095u) ? 4095u : view.packetCount;
    data->set_input_buffer_0_packet_count(pkts);
    data->set_sample_rate(sampleRateEnum & 0x3u);
    data->set_is_stereo(view.channels >= 2 ? 1u : 0u);
    // loop_count 255 == XAUDIO2_LOOP_INFINITE (xma_context.cc:328-331), so an
    // XMA2 file with loop_count 0 ("no loop") becomes 255 only when the fmt
    // actually declares a loop region.
    if (view.loopCount != 0 && view.loopBegin != 0) {
        data->set_loop_count(view.loopCount);
    }
}

} // namespace audlo
} // namespace apu
