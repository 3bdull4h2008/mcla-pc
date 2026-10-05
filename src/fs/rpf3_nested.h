// Real RPF3 layout for the packfiles AS THEY ARE ON DISK — not the synthesized
// one src/fs/vfs_rpf.cpp:84 writes (that one has stored==uncompressed, no LZX,
// zero preamble and a DFS TOC, and is only reached when the real file is
// absent).
//
// Everything here is MEASURED, from the shipped archives, not assumed:
//
//   $ python tools/rpf_offline.py header build/game_data/xarchive_cache.rpf
//     magic=b'RPF3' size=2130739200  +4 TOC length=382976 (0x5D800)  +8=00005D7B
//   raw bytes @0x000: 52 50 46 33 | 00 d8 05 00 | 7b 5d 00 00 | 00 00 00 00
//   raw bytes @0x00C: ff ff ff ff 00 00 00 00 ...      (the open-gate word)
//   raw bytes @0x800: high-entropy ciphertext          (the AES-CBC TOC)
//
// So the header lives at offset 0 and the TOC at 0x800, ciphertext. The guest
// is the only decryptor (F-458: a nested open gives stream 0x82860C40 but
// `tune/vehicle/*.lst` yields stream 0 precisely because the host never gets to
// see a decryptable inner image), so the HOST READS THE HEADER AND NEVER THE
// NAMES. That is not a limitation of this file, it is the design: every offset
// and size the guest needs is published by the guest's own TOC, and the host's
// job is to move the right BYTES.
//
// NESTED ARCHIVES OBEY THE SAME LAYOUT, and that is the root fix for the tune
// starvation. The outer member at 0x3F0000 of xarchive_cache.rpf is a
// headerless raw-DEFLATE stream (TOC words w1=0x68000 logical, w2=0x3F0000
// offset, w3&0x00FFFFFF=0x503CF stored) whose 425,984 inflated bytes are
//
//   52 50 46 33 | 00 38 00 00 | 18 03 00 00 | 00 00 00 00 | ff ff ff ff 00 ...
//   RPF3            TOC len 14336    792 entries    open-gate
//
// i.e. a real, complete nested RPF3 archive. bootscripts (0x368000 -> 720,896
// bytes) and carconfigs (0x448000 -> 294,912) are the same shape. The host
// serve read those windows RAW and handed the guest DEFLATE bytes, so the
// guest's RPF3 header parse of the inner archive failed, its inner TOC decrypt
// never ran, and the `Vehicle` section walk in sub_82397060 found nothing
// (F442-SECTION: 14 rows, all hits=0). F-458 attributed that to "the host plant
// pre-empts the guest's decrypt", but the measurement that supports F-458
// ("no second RPF3 in the first 64 MiB") was itself the bug: the serve read
// at the wrong offset. There is no second RPF3 in the first 64 MiB *because the
// bytes there are compressed*, and inflating them is not emulation — it is
// recovering the archive the retail packer actually wrote.
#pragma once

#include <cstdint>
#include <cstring>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace mcla::vfs {

// Offsets of the real on-disk RPF3 header. See the measurement block above.
constexpr uint32_t kRpf3Magic = 0x52504633u;  // 'RPF3'
constexpr uint64_t kRpf3HeaderOffset = 0x0;
constexpr uint64_t kRpf3TocOffset = 0x800;
constexpr uint64_t kRpf3TocRecordSize = 16;

struct Rpf3Header {
    uint32_t magic = 0;        // kRpf3Magic
    uint32_t toc_length = 0;   // bytes of AES-CBC TOC at kRpf3TocOffset
    uint32_t entry_count = 0;  // TOC records
};

// Little-endian: measured, the +4/+8 words read LE (BE gives 0xD80500, which
// no archive in the tree produces).
inline uint32_t Rpf3ReadU32LE(const uint8_t *p) {
    return static_cast<uint32_t>(p[0]) | (static_cast<uint32_t>(p[1]) << 8) |
           (static_cast<uint32_t>(p[2]) << 16) | (static_cast<uint32_t>(p[3]) << 24);
}

// Parse the header of a REAL RPF3 image. `n` is the number of bytes available
// from the start of the image; the header is complete at 12 bytes. Fails on a
// wrong magic rather than guessing, because the synthetic image
// (BuildVirtualRpf) also writes a kRpf3Magic and must not be mistaken for a
// real one.
//
// The magic is compared as FOUR ASCII BYTES, not as a word. This was the one
// real bug in the first cut of this file: the neighbouring +4/+8 words are
// genuinely little-endian (0x3800 = 14,336 and 0x0318 = 792 both decode to
// plausible values), but the magic is the literal tag "RPF3", so a LE word read
// of it yields 0x33364652 and never matches. Do not "simplify" this into
// Rpf3ReadU32LE(bytes).
inline bool ParseRpf3Header(const uint8_t *bytes, size_t n, Rpf3Header *out) {
    if (bytes == nullptr || out == nullptr) return false;
    if (n < 12u) return false;
    if (std::memcmp(bytes + kRpf3HeaderOffset, "RPF3", 4) != 0) return false;
    out->magic = kRpf3Magic;
    out->toc_length = Rpf3ReadU32LE(bytes + kRpf3HeaderOffset + 4);
    out->entry_count = Rpf3ReadU32LE(bytes + kRpf3HeaderOffset + 8);
    return true;
}

// A member of an outer packfile that is itself a complete RPF3 archive.
//
// Host-addressable as a first-class packfile: the image is the inflated member
// (so it is a real archive, not the synthetic reconstruction), its header is
// parsed for real, and the members the GUEST's own inner-TOC census publishes
// are recorded against it so a path like `tune/vehicle/vehicle0008.lst`
// resolves to a real offset/length pair inside the nested image. The inner TOC
// itself is never decrypted here.
class NestedRpfArchive {
public:
    // `source_path` is the host path of the OUTER packfile, `stored_offset`
    // the member's archive offset and `stored_length` the number of stored
    // (compressed) bytes — the guest's own TOC words w2 and w3&0x00FFFFFF.
    NestedRpfArchive(std::string name, std::string source_path,
                     uint64_t stored_offset, uint32_t stored_length,
                     uint32_t logical_length)
        : name_(std::move(name)), source_path_(std::move(source_path)),
          stored_offset_(stored_offset), stored_length_(stored_length),
          logical_length_(logical_length) {}

    // Holds a std::mutex, so it is neither copyable nor assignable. A
    // re-registration with a richer contract replaces the whole object through
    // a shared_ptr swap rather than through assignment.
    NestedRpfArchive(const NestedRpfArchive&) = delete;
    NestedRpfArchive& operator=(const NestedRpfArchive&) = delete;

    // Replace the contract in place. Clears a failed/resolved state so the next
    // Materialize() re-reads the on-disk member.
    void ResetContract(uint64_t stored_offset, uint32_t stored_length,
                       uint32_t logical_length) {
        std::lock_guard<std::mutex> lock(mutex_);
        stored_offset_ = stored_offset;
        stored_length_ = stored_length;
        logical_length_ = logical_length;
        materialized_ = false;
        error_.clear();
    }

    const std::string& name() const { return name_; }
    uint64_t stored_offset() const { return stored_offset_; }
    uint32_t stored_length() const { return stored_length_; }
    uint32_t logical_length() const { return logical_length_; }
    const Rpf3Header& header() const { return header_; }
    const std::vector<uint8_t>& image() const { return image_; }
    bool materialized() const { return materialized_; }
    // Human-readable reason a materialize failed, for the log line.
    const std::string& error() const { return error_; }

    // Inflate the member out of the outer packfile and validate the real
    // header. Idempotent; safe under concurrent callers.
    bool Materialize();

    // Positional read inside the nested image. This is what makes a path like
    // `tune/vehicle/vehicle0008.lst` a first-class read: the caller resolves
    // the member through RecordMember() below and then reads it positionally,
    // exactly as it would read the outer packfile.
    bool Read(uint64_t offset, void *buffer, size_t size) const;

    // Record a member of THIS nested archive, as published by the guest's own
    // inner-TOC census: `logical` is the inflated length the guest must see,
    // `stored` the on-disk length inside the nested image. `logical == 0`
    // means the guest published a zero record and nothing is recorded.
    void RecordMember(const std::string &relative_path, uint32_t logical,
                      uint32_t stored);

    struct Member {
        uint32_t logical = 0;
        uint32_t stored = 0;
    };
    // Case-insensitive on the whole path, matching the VFS NormalizePath.
    const Member* FindMember(const std::string& relative_path) const;

private:
    std::string name_;
    std::string source_path_;
    uint64_t stored_offset_ = 0;
    uint32_t stored_length_ = 0;
    uint32_t logical_length_ = 0;
    Rpf3Header header_{};
    std::vector<uint8_t> image_;
    std::map<std::string, Member> members_;
    bool materialized_ = false;
    std::string error_;
    mutable std::mutex mutex_;
};

}  // namespace mcla::vfs
