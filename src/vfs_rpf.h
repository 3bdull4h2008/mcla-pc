#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <mutex>
#include <filesystem>

#include "guest_memory.h"

namespace mcla::vfs {

// Synthesized RPF3 archive served over an extracted directory tree.
// Layout follows MCLA_RPF3_Technical_Reference.txt: zero page, BE header at
// 0x800 ("RPF3"), TOC at 0x1000, filename section, then STORED file data
// (file_size == uncompressed so no XMem LZX decode is needed on our side).
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
    bool CloseFile(OpenFileHandle& file);
    bool SeekFile(OpenFileHandle& file, int64_t offset, int whence);
    bool ListDirectory(const std::string& virtual_path, std::vector<std::string>& entries) const;

private:
    void BuildIndex(const std::string& root);
    void ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& entry);
    std::string NormalizePath(const std::string& path) const;
    bool BuildVirtualRpf(const FileEntry& dir_entry, VirtualRpf& out);
    std::shared_ptr<VirtualRpf> GetOrBuildVirtualRpf(const std::string& dir_key);

    std::string m_extracted_root;
    std::unordered_map<std::string, FileEntry> m_file_index;
    std::unordered_map<uint64_t, std::unique_ptr<OpenFileHandle>> m_open_files;
    std::unordered_map<std::string, std::shared_ptr<VirtualRpf>> m_virtual_rpfs;
    uint64_t m_next_handle = 1;
    mutable std::mutex m_mutex;
    bool m_mounted = false;
};

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
bool NtReadFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t& bytes_read);
bool NtQueryInformationFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class);
bool NtQueryDirectoryFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class);
bool NtCloseHook(uint32_t file_handle);

} // namespace hooks

} // namespace mcla::vfs
