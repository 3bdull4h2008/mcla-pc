#pragma once

// Phase 9: RPF Archive Virtual File System
// Implements t:\ virtual drive mapping to xarchive_cache.rpf/xarchive_audio.rpf
// Since original RPF files are not available, this implements a virtual file system
// that serves files from the extracted cache.

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

// RPF Archive Virtual File System
// Provides t:\ virtual drive mapping to extracted RPF content
class RpfVirtualFileSystem {
public:
    struct FileEntry {
        std::string virtual_path;      // e.g., "mc4/art/city/city.occluder"
        std::string physical_path;     // e.g., "E:/mcla pc/mcla extracted cache/city/sc/city.occluder"
        uint64_t size = 0;
        bool is_directory = false;
        std::vector<std::string> children; // for directories
    };

    struct OpenFileHandle {
        std::string virtual_path;
        std::string physical_path;
        uint64_t size = 0;
        uint64_t position = 0;
        void* handle = nullptr; // host file handle
    };

    RpfVirtualFileSystem();
    ~RpfVirtualFileSystem();

    static RpfVirtualFileSystem& Instance() {
        static RpfVirtualFileSystem instance;
        return instance;
    }

    // Initialize the VFS with the extracted cache root path
    bool Initialize(const std::string& extracted_cache_root);

    // Mount the virtual t:\ drive
    void Mount();

    // Unmount
    void Unmount();

    // Check if a path is under our virtual t:\ drive
    bool IsVirtualPath(const std::string& path) const;

    // Convert guest path (t:\...) to virtual path (mc4/...)
    std::string GuestToVirtualPath(const std::string& guest_path) const;

    // File operations
    bool Exists(const std::string& virtual_path) const;
    bool IsDirectory(const std::string& virtual_path) const;
    uint64_t GetFileSize(const std::string& virtual_path) const;

    // Open/Close/Read
    bool OpenFile(const std::string& virtual_path, OpenFileHandle& out_file);
    bool ReadFile(OpenFileHandle& file, void* buffer, uint64_t size, uint64_t& bytes_read);
    bool CloseFile(OpenFileHandle& file);
    bool SeekFile(OpenFileHandle& file, int64_t offset, int whence);

    // Directory operations
    bool ListDirectory(const std::string& virtual_path, std::vector<std::string>& entries) const;

private:
    void BuildIndex(const std::string& root);
    void ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& entry);
    std::string NormalizePath(const std::string& path) const;

    std::string m_extracted_root;
    std::unordered_map<std::string, FileEntry> m_file_index;
    std::unordered_map<uint64_t, std::unique_ptr<OpenFileHandle>> m_open_files;
    uint64_t m_next_handle = 1;
    mutable std::mutex m_mutex;
    bool m_mounted = false;
};

// Helper to convert guest Windows path to virtual path
inline std::string GuestPathToVirtual(const std::string& guest_path) {
    std::string path = guest_path;
    // Convert t:\mc4\... to mc4/...
    size_t pos = path.find("t:\\");
    if (pos != std::string::npos) {
        path = path.substr(pos + 3); // skip "t:\"
    }
    // Convert backslashes to forward slashes
    for (char& c : path) {
        if (c == '\\') c = '/';
    }
    return path;
}

// Hook entry points for NtCreateFile, NtReadFile, etc.
namespace hooks {

bool NtCreateFileHook(uint32_t oa, mcla::native::GuestMemoryView& view, uint32_t& out_status);
bool NtReadFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t& bytes_read);
bool NtQueryInformationFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class);
bool NtQueryDirectoryFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class);

} // namespace hooks

} // namespace mcla::vfs