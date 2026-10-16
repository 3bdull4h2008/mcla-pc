#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <mutex>
#include <filesystem>

#include "guest_memory.h"
#include "fs/rpf3_nested.h"

namespace mcla::vfs {

// Synthesized RPF3 archive served over an extracted directory tree.
// Layout follows MCLA_RPF3_Technical_Reference.txt: header, TOC, filename
// section, then member data. The on-disk TOC is additionally AES-CBC encrypted
// (section 9, F-076(2)).
// F-105 CORRECTION (was F-073): the six *.list members are stored as
// headerless raw-DEFLATE streams whose EXPANDED length equals the TOC's stored
// length (260/1246/1108/575/496/368 in == out, all six verified by
// src/raw_inflate.h); the "126-460" numbers were level-9 recompression sizes,
// not offsets or lengths recorded in the archive.
struct VirtualRpfSegment {
    uint64_t virtual_offset = 0;   // absolute offset inside synthesized image
    uint64_t size = 0;
    std::string physical_path;
    void* host_handle = nullptr;   // lazily opened win32 HANDLE
};

struct VirtualRpf {
    std::vector<uint8_t> preamble;             // [0, data_start): header+TOC+names
    std::vector<VirtualRpfSegment> segments;   // stored file data regions
    uint64_t total_size = 0;

    ~VirtualRpf();
};

class RpfVirtualFileSystem {
public:
    struct FileEntry {
        std::string virtual_path;
        std::string physical_path;
        uint64_t size = 0;
        bool is_directory = false;
        std::vector<std::string> children;
    };

    struct OpenFileHandle {
        std::string virtual_path;
        std::string physical_path;
        uint64_t size = 0;
        uint64_t position = 0;
        void* handle = nullptr;
        std::shared_ptr<VirtualRpf> virtual_rpf;   // set for synthesized .rpf opens
        // F-628: set for a nested packfile open. Its bytes are the inflated
        // outer member (a REAL RPF3 image), so ReadFileAt serves the inner
        // archive and the guest's own inner-TOC decrypt runs unchanged.
        std::shared_ptr<NestedRpfArchive> nested_rpf;

        // F-645: RAW-POSITIONAL read. While set, this handle's reads return the
        // packfile's OWN bytes and are never passed through the expanded-span
        // table, so no span can write into them.
        //
        // CONTRACT, stated here because it is a property of the HANDLE and not
        // of any one call site: while this is set, ReadFileAt does not call
        // ApplyExpandedSpans on EITHER branch -- not the real-handle positional
        // read and not the shared-position fallback. A property that held on one
        // branch only would be exactly the half-true comment this flag exists to
        // make true. Set it only for a read whose purpose is to SEE THE FILE --
        // corroborating a member's own stored bytes before deciding what to serve
        // it as -- and never to make a read look clean.
        bool raw_positional = false;

        // F-645: the DATA OFFSET of the member the caller of this handle is
        // reading, or 0 when the caller did not say.
        //
        // WHY IT IS NEEDED: a member is registered with the span table AFTER the
        // read that published it -- MarkMemberExpandedIn is the six-step
        // corroboration's step 6 and the read is step 2 -- so at read time the
        // member being read is ABSENT from the table. Nothing in the table can
        // therefore say "this window head belongs to the member being read", and
        // without this field another member's logical tail can win the election
        // for it. Feeds ClassifyTailClaim's kReadMemberHead; 0 means unknown,
        // and that case is then unreachable.
        uint64_t read_member_off = 0;

        // T43.20 (2026-10-13): handle_id for proper cleanup in CloseFile.
        // Without this, the m_open_files entry is never removed, causing a
        // handle leak (observed as "Out of file handles" after ~957 opens).
        uint64_t handle_id = 0;
    };

    RpfVirtualFileSystem();
    ~RpfVirtualFileSystem();

    static RpfVirtualFileSystem& Instance() {
        static RpfVirtualFileSystem instance;
        return instance;
    }

    bool Initialize(const std::string& extracted_cache_root);
    void Mount();
    void Unmount();

    bool IsVirtualPath(const std::string& path) const;
    std::string GuestToVirtualPath(const std::string& guest_path) const;

    bool Exists(const std::string& virtual_path) const;
    bool IsDirectory(const std::string& virtual_path) const;
    uint64_t GetFileSize(const std::string& virtual_path) const;

    bool OpenFile(const std::string& virtual_path, OpenFileHandle& out_file);
    bool ReadFile(OpenFileHandle& file, void* buffer, uint64_t size, uint64_t& bytes_read);
    // Session 76d: positional read — no shared file position, safe for
    // concurrent NtReadFile callers (seek+read race served wrong bytes).
    bool ReadFileAt(OpenFileHandle& file, uint64_t offset, void* buffer,
                    uint64_t size, uint64_t& bytes_read);
    bool CloseFile(OpenFileHandle& file);
    bool SeekFile(OpenFileHandle& file, int64_t offset, int whence);
    bool ListDirectory(const std::string& virtual_path, std::vector<std::string>& entries) const;

    // F-628: the directory the real packfiles live in (the extracted cache
    // root's parent = build/game_data). The nested-archive registrar runs from
    // the guest-TOC census in gpu_device.cpp and has no VFS handle, so it needs
    // this; empty before Initialize.
    std::string GameDataRoot() const;

private:
    void BuildIndex(const std::string& root);
    void ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& entry);
    std::string NormalizePath(const std::string& path) const;
    bool BuildVirtualRpf(const FileEntry& dir_entry, VirtualRpf& out);
    std::shared_ptr<VirtualRpf> GetOrBuildVirtualRpf(const std::string& dir_key);

    std::string m_extracted_root;
    std::string m_game_data_root;
    std::unordered_map<std::string, FileEntry> m_file_index;
    std::unordered_map<uint64_t, std::unique_ptr<OpenFileHandle>> m_open_files;
    std::unordered_map<std::string, std::shared_ptr<VirtualRpf>> m_virtual_rpfs;
    uint64_t m_next_handle = 1;
    mutable std::mutex m_mutex;
    bool m_mounted = false;
};

// ---------------------------------------------------------------------------
// F-645: THE TAIL-CLAIM RULE, DECLARED. This contract used to exist only as a
// comment above an anonymous-namespace function in vfs_rpf.cpp, which is how the
// last two defects happened: a rule whose terms live in prose in another file is
// one edit away from being applied to nothing. Everything the rule needs is
// declared here, and each declaration states its own semantics.
//
// The rule, in one sentence: a span may write PAST its own on-disk extent only
// when it owns the window, and that ownership claim is VOID when the window's
// head byte is not the owner's byte to write. A logical tail is not a claim on
// the file at all -- the console's own decompressor writes it into a
// caller-owned destination sized by the declared uncompressed length and never
// over its source -- so the host spends the same freedom in the same currency.
//
// F-642's measurement and the two pre-F-645 void cases are written out at the
// definition (src/fs/vfs_rpf.cpp, immediately above ClassifyTailClaim); this
// block declares what that measurement is a measurement OF.
//
// One registered member. `storedLen` is the ON-DISK extent (w3 & 0x00FFFFFF),
// `logicalLen` the length the guest must see (w1); a member with the two equal
// is STORED UNCOMPRESSED and must be served verbatim, byte for byte.
struct ExpandedSpan {
    // Lowercased basename of the owning packfile, or empty for "any" (the
    // pre-F-628 single-packfile tables). The physical-path gate used to be a
    // hard `xarchive_cache.rpf` suffix test; keying on the packfile name keeps
    // the addressing honest now that more than one packfile is real, and an
    // empty key preserves the old single-packfile meaning exactly.
    std::string packfile;
    uint64_t off = 0;         // member data offset inside the packfile (w2)
    uint32_t storedLen = 0;   // on-disk length (w3 & 0x00FFFFFF)
    uint32_t logicalLen = 0;  // length the guest must see (w1); 0 = unknown
    std::vector<uint8_t> bytes;
    bool resolved = false;
    bool failed = false;
    bool uncompressed = false;  // stored == logical: TOC says store verbatim
    // F-638: set once this span has been NAMED as an uncorroborated extent, so
    // the marker is a per-member census line and not a per-window flood.
    bool named = false;
    // F-642: separate from `named`, which F-638 spends on MEMBER-SPAN-IMPLAUSIBLE.
    // Set once this span's expansion-over-its-stored-extent has been reported,
    // so MEMBER-EXPAND-OVERRUN is one line per member and not one per window.
    bool overrunNamed = false;
};

// The five verdicts. Only kInStoredRange and kContinuation are claims the owner
// may write on; the other three are VOIDS, and a void DEMOTES the owner to
// no-owner rather than clipping what it may write.
enum class TailClaim {
    kInStoredRange,   // head is a byte the member occupies on disk
    kContinuation,    // head is strictly inside the member's logical tail
    kBoundaryByte,    // head IS `off + storedLen`: the packer's next byte
    kNeighbour,       // a RESOLVED neighbour's stored range covers the head
    kReadMemberHead,  // head IS the member the caller is reading (F-645)
};

// Classify ONE window's head byte against the span `s` that was elected its
// owner.
//
//   spans          the whole span table. Entries that `failed` or have not
//                  `resolved` are ignored, and that resolved test is
//                  load-bearing rather than defensive: the six uncorroborated
//                  RSC5 UI containers imply 0.5-7.6 MB of extent and would
//                  otherwise void ~24 MB of honest claims.
//   packKey        lowercased packfile basename; an entry matches when its own
//                  key is empty or equal to this one.
//   readMemberOff  the data offset of the member the CALLER is reading, or 0
//                  (see OpenFileHandle::read_member_off).
//
// CONTRACT, and the order the tests run in -- this order IS the contract:
//
//   1. head <  s.off + s.storedLen                    -> kInStoredRange
//   2. head == s.off + s.storedLen                    -> kBoundaryByte
//   3. head inside a resolved neighbour's stored range -> kNeighbour
//   4. readMemberOff != 0 and head == readMemberOff
//      and head > s.off + s.storedLen                  -> kReadMemberHead
//   5. otherwise                                       -> kContinuation
//
// WHY TEST 4 IS LAST, and not promoted: it is strictly ADDITIVE. Tests 2 and 3
// name the same void for the same bytes, so an already-measured verdict keeps
// its name and its marker rows are unchanged, and test 4 fires only where no
// other test applied. It can also fire only on the FIRST window of a member
// read -- the sole window whose head equals readMemberOff -- and only when the
// owner's own on-disk extent does not reach that head. So a member's own first
// window, and every continuation window of every member, keep the pre-F-645
// verdict.
TailClaim ClassifyTailClaim(const std::vector<ExpandedSpan>& spans,
                            const ExpandedSpan& s, uint64_t head,
                            const std::string& packKey,
                            uint64_t readMemberOff = 0);

// T41.3p (F-105): register an archive member that the guest's own archive
// layer would hand out EXPANDED (the six raw-DEFLATE *.list name lists).
// Reads covering the whole span get the expanded bytes in place; the expansion
// is computed once from the stored bytes and cached. Called from the guest-TOC
// census (gpu_device.cpp) with the size/offset the guest itself published.
//
// F-628 GENERALIZATION. The old contract had two shapes for one idea and both
// were host guesses about which word meant what. The guest's TOC records are
// uniform and were measured against 370 of the 377 distinct members w653
// published (src/fs/rpf3_nested.h has the byte evidence):
//
//   w1           logical (inflated) size the guest must see
//   w2           member data offset inside the packfile
//   w3 & 0xFFFFFF stored (compressed) size   [bit30 is the open-gate flag,
//                                             the low 24 bits are the length]
//
// Of those 370: 364 satisfy inflate(stored bytes at w2) -> exactly w1 bytes
// (raw DEFLATE), and 6 have stored == w1, i.e. the member is STORED
// UNCOMPRESSED and must be served verbatim. The remaining 7 are the UI
// .xsf/.xtd XCompress/LZX containers, which this transform does not own.
//
// So the two old arguments collapse to one: offset (w2) plus stored (w3&0xFFFFFF)
// plus logical (w1). `storedLen` is now the ON-DISK length and the expanded
// bytes are produced once and cached; `MarkMemberExpanded` keeps its two-
// argument form for the existing registrars in gpu_device.cpp, which pass the
// length their span table holds.
//
// STRADDLING MEMBERS ARE NOW SERVED. Previously substitution was refused unless
// one read covered the whole span, so a member crossing a read-window boundary
// was served still-compressed. That is exactly the shape of the three nested
// packfiles, which are 296 KiB - 705 KiB and therefore never fit a 32 KiB
// read: all three straddle, and all three were therefore refused. Substitution
// is now a splice of the cached expanded bytes into the covered sub-range.
void MarkMemberExpanded(uint64_t offset, uint32_t storedLen);

// F-628: the full, unambiguous form. `packfile` is the host path of the
// archive the offset lives in (empty = any, which is what the pre-F-628
// single-packfile tables mean). Span table == the 16 hand-listed
// kListMemberSpans/kTypeMemberSpans in gpu_device.cpp; the guest publishes the
// same three words for every other member it opens, so the census can replace
// those tables wholesale.
void MarkMemberExpandedIn(const std::string& packfile, uint64_t offset,
                          uint32_t storedLen, uint32_t logicalLen);

// F-628: register an outer member that is itself a complete RPF3 archive, so
// the nested packfile becomes first-class instead of unserved. The member is
// inflated out of the outer packfile (it is a raw-DEFLATE stream on disk --
// measured, see src/fs/rpf3_nested.h), its real header is parsed, and its
// inner members can then be recorded with RegisterNestedMember below. This is
// NOT the F-458 contamination: the inner TOC stays AES ciphertext and the
// guest's own decrypt of it is untouched, because the host only ever moves
// bytes the retail packer wrote.
void RegisterNestedRpf(const std::string& packfile, const std::string& name,
                       uint64_t storedOffset, uint32_t storedLen,
                       uint32_t logicalLen);

// F-628: a member INSIDE a nested archive, as published by the guest's inner
// TOC census. `name` is the nested archive's own name.
void RegisterNestedMember(const std::string& name, const std::string& path,
                          uint32_t logicalLen, uint32_t storedLen);

// F-628: the mounted-nested-archive view, keyed by the guest path the archive
// is opened as (`preload/xarchive_cameratune.rpf`, `a:/archive/preload/...` and
// the device-stripped spelling all resolve to one key). Returns nullptr for an
// unmounted name.
std::shared_ptr<NestedRpfArchive> FindNestedRpf(const std::string& name);

// F-628: split a guest archive path into its nested-archive part and the path
// INSIDE that archive. `preload/xarchive_cameratune.rpf/tune/vehicle/
// vehicle0008.lst` -> {"preload/xarchive_cameratune.rpf",
// "tune/vehicle/vehicle0008.lst"}; a path with no `.rpf` component returns
// false. Exposed so the census in gpu_device.cpp can attribute an inner-TOC
// record to the right nested archive without duplicating this parse.
bool SplitNestedPath(const std::string& path, std::string* archive,
                     std::string* inner);

inline std::string GuestPathToVirtual(const std::string& guest_path) {
    std::string path = guest_path;
    size_t pos = path.find("t:\\");
    if (pos != std::string::npos) {
        path = path.substr(pos + 3);
    }
    // game: drive hosts the packfiles; strip the device prefix so paths land
    // in the extracted-content index (game:\xarchive_audlo.rpf -> xarchive_audlo.rpf)
    if (path.rfind("game:\\", 0) == 0) {
        path = path.substr(6);
    } else if (path.rfind("game:/", 0) == 0) {
        path = path.substr(6);
    } else if (path.rfind("game:", 0) == 0) {
        path = path.substr(5);
    }
    for (char& c : path) {
        if (c == '\\') c = '/';
    }
    return path;
}

namespace hooks {

bool NtCreateFileHook(uint32_t oa, mcla::native::GuestMemoryView& view, uint32_t& out_status);
bool NtReadFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t& bytes_read);
bool NtQueryInformationFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t info_class);
bool NtQueryDirectoryFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t info_class);
bool NtCloseHook(uint32_t file_handle);

} // namespace hooks

} // namespace mcla::vfs
