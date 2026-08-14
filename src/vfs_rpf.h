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

    std::string m_extracted_root;
    std::unordered_map<std::string, FileEntry> m_file_index;
    std::unordered_map<uint64_t, std::unique_ptr<OpenFileHandle>> m_open_files;
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