#include "fs/rpf3_nested.h"
#include "logging.h"
#include "raw_inflate.h"

#include <algorithm>
#include <cctype>
#include <cstdio>

namespace mcla::vfs {

namespace {

std::string LowerAscii(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return out;
}

// Positional read of a whole packfile member. `pread` semantics via OVERLAPPED:
// the packfile handle is shared across threads and the guest issues concurrent
// NtReadFile on the same handle (see the ReadFileAt comment in vfs_rpf.cpp), so
// a seek+read would race. Kept local rather than reusing vfs_rpf.cpp's
// PreadHost because that one is in an anonymous namespace and this file must
// not grow a dependency on the VFS singleton's lock ordering.
bool PreadRange(const std::string& path, uint64_t offset, uint8_t* dst,
                size_t size) {
    if (size == 0) return true;
    HANDLE h = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    OVERLAPPED ov{};
    ov.Offset = static_cast<DWORD>(offset);
    ov.OffsetHigh = static_cast<DWORD>(offset >> 32);
    DWORD got = 0;
    const bool ok =
        ::ReadFile(h, dst, static_cast<DWORD>(size), &got, &ov) != FALSE &&
        got == size;
    CloseHandle(h);
    return ok;
}

}  // namespace

bool NestedRpfArchive::Materialize() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (materialized_) return true;
    if (error_.empty() == false) return false;  // failed once; do not retry

    if (logical_length_ == 0 || stored_length_ == 0) {
        error_ = "no guest-published size (logical=0 or stored=0)";
        return false;
    }
    // The inflated image cannot be larger than the guest said, and the upper
    // bound keeps a corrupt w1 from asking for a multi-gigabyte allocation.
    if (logical_length_ > (64u << 20)) {
        error_ = "logical length implausible";
        return false;
    }

    // w3&0x00FFFFFF is the STORED length; the stream is shorter than or equal
    // to it (a DEFLATE final block ends the stream and the rest of the
    // allocated span is padding). Read a little past it so a truncated stored
    // field still inflates.
    const uint64_t want = static_cast<uint64_t>(stored_length_) + 64u;
    std::vector<uint8_t> stored(static_cast<size_t>(want));
    if (!PreadRange(source_path_, stored_offset_, stored.data(), stored.size())) {
        error_ = "pread of the member from the outer packfile failed";
        return false;
    }

    std::vector<uint8_t> out;
    if (!RawInflate(stored.data(), stored.size(), out,
                    static_cast<size_t>(logical_length_) + 4096u) ||
        out.empty()) {
        error_ = "RawInflate of the member failed (not raw DEFLATE)";
        return false;
    }
    // Measured contract: the inflated length EQUALS the guest's w1 for all
    // three nested packfiles (425,984 / 720,896 / 294,912). A mismatch means
    // the words we were handed are not {logical, stored} for this member, so
    // refuse rather than serve a wrong-length image under a decompressed-name
    // contract.
    if (out.size() != logical_length_) {
        error_ = "inflated length " + std::to_string(out.size()) + " != guest w1 " +
                 std::to_string(logical_length_);
        return false;
    }
    if (!ParseRpf3Header(out.data(), out.size(), &header_)) {
        error_ = "inflated member has no RPF3 header";
        return false;
    }

    image_.swap(out);
    materialized_ = true;
    MCLA_LOG_WARN("NESTED-RPF-MOUNT name='{}' outer='{}' storedOff={:08X} "
                  "stored={} logical={} tocLen={} entries={}",
                  name_, source_path_, stored_offset_, stored_length_,
                  logical_length_, header_.toc_length, header_.entry_count);
    return true;
}

bool NestedRpfArchive::Read(uint64_t offset, void* buffer, size_t size) const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!materialized_ || buffer == nullptr) return false;
    if (offset >= image_.size()) return false;
    const size_t n = std::min(size, image_.size() - static_cast<size_t>(offset));
    std::memcpy(buffer, image_.data() + offset, n);
    return n == size;
}

void NestedRpfArchive::RecordMember(const std::string& relative_path,
                                    uint32_t logical, uint32_t stored) {
    if (logical == 0) return;
    std::lock_guard<std::mutex> lock(mutex_);
    Member m;
    m.logical = logical;
    m.stored = stored;
    members_[LowerAscii(relative_path)] = m;
}

const NestedRpfArchive::Member* NestedRpfArchive::FindMember(
    const std::string& relative_path) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = members_.find(LowerAscii(relative_path));
    if (it == members_.end()) return nullptr;
    return &it->second;
}

}  // namespace mcla::vfs
