#include "vfs_rpf.h"
#include "logging.h"
#include "guest_memory.h"

#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace mcla::vfs {

RpfVirtualFileSystem::RpfVirtualFileSystem() = default;

RpfVirtualFileSystem::~RpfVirtualFileSystem() {
    Unmount();
}

std::string RpfVirtualFileSystem::NormalizePath(const std::string& path) const {
    std::string result = path;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    std::replace(result.begin(), result.end(), '\\', '/');
    std::string result2;
    bool last_slash = false;
    for (char c : result) {
        if (c == '/') {
            if (!last_slash) {
                result2 += c;
                last_slash = true;
            }
        } else {
            result2 += c;
            last_slash = false;
        }
    }
    if (result2.size() > 1 && result2.back() == '/') {
        result2.pop_back();
    }
    return result2;
}

bool RpfVirtualFileSystem::Initialize(const std::string& extracted_cache_root) {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_mounted) {
        REXLOG_WARN("VFS: Already initialized");
        return true;
    }

    m_extracted_root = extracted_cache_root;

    std::filesystem::path root_path(extracted_cache_root);
    if (!std::filesystem::exists(root_path)) {
        REXLOG_ERROR("VFS: Extracted cache root does not exist: {}", extracted_cache_root);
        return false;
    }

    REXLOG_INFO("VFS: Initializing with extracted cache root: {}", extracted_cache_root);

    BuildIndex(extracted_cache_root);

    REXLOG_INFO("VFS: Indexed {} files/directories", m_file_index.size());

    Mount();
    return true;
}

void RpfVirtualFileSystem::Mount() {
    m_mounted = true;
    REXLOG_INFO("VFS: Mounted virtual t:\\ drive");
}

void RpfVirtualFileSystem::Unmount() {
    for (auto& [handle, file] : m_open_files) {
        if (file->handle) {
            CloseHandle(static_cast<HANDLE>(file->handle));
        }
    }
    m_open_files.clear();
    m_file_index.clear();
    m_mounted = false;
    REXLOG_INFO("VFS: Unmounted virtual t:\\ drive");
}

bool RpfVirtualFileSystem::IsVirtualPath(const std::string& path) const {
    std::string norm = NormalizePath(path);
    return (path.rfind("t:\\", 0) == 0 ||
            path.rfind("t:/", 0) == 0 ||
            path.rfind("t:\\mc4", 0) == 0 ||
            path.rfind("t:/mc4", 0) == 0 ||
            path.rfind("mc4/", 0) == 0);
}

std::string RpfVirtualFileSystem::GuestToVirtualPath(const std::string& guest_path) const {
    std::string path = guest_path;

    size_t pos = path.find("t:\\");
    if (pos != std::string::npos) {
        path = path.substr(pos + 3);
    } else if (path.rfind("t:/", 0) == 0) {
        path = path.substr(3);
    } else if (path.rfind("t:\\", 0) == 0) {
        path = path.substr(3);
    }

    for (char& c : path) {
        if (c == '\\') c = '/';
    }

    return NormalizePath(path);
}

void RpfVirtualFileSystem::BuildIndex(const std::string& root) {
    m_file_index.clear();

    FileEntry root_entry;
    root_entry.virtual_path = "";
    root_entry.physical_path = m_extracted_root;
    root_entry.is_directory = true;
    m_file_index[""] = root_entry;

    std::filesystem::path root_path(m_extracted_root);
    if (std::filesystem::exists(root_path)) {
        for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(root_path)) {
            std::filesystem::path rel = std::filesystem::relative(dir_entry.path(), root_path);
            std::string virtual_norm = NormalizePath(rel.generic_string());

            FileEntry entry;
            entry.virtual_path = virtual_norm;
            entry.physical_path = dir_entry.path().generic_string();
            entry.is_directory = dir_entry.is_directory();
            entry.size = dir_entry.is_directory() ? 0 : std::filesystem::file_size(dir_entry.path());

            m_file_index[virtual_norm] = entry;

            if (dir_entry.is_directory()) {
                std::string parent = virtual_norm;
                size_t last_slash = parent.find_last_of('/');
                if (last_slash != std::string::npos) {
                    parent = parent.substr(0, last_slash);
                    auto it = m_file_index.find(parent);
                    if (it != m_file_index.end()) {
                        it->second.children.push_back(dir_entry.path().filename().generic_string());
                    }
                }
            }
        }
    }
}

void RpfVirtualFileSystem::ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& entry) {
    (void)physical_root;
    (void)virtual_root;
    (void)entry;
}

bool RpfVirtualFileSystem::Exists(const std::string& virtual_path) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    return m_file_index.find(norm) != m_file_index.end();
}

bool RpfVirtualFileSystem::IsDirectory(const std::string& virtual_path) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    auto it = m_file_index.find(norm);
    return it != m_file_index.end() && it->second.is_directory;
}

uint64_t RpfVirtualFileSystem::GetFileSize(const std::string& virtual_path) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    auto it = m_file_index.find(norm);
    return (it != m_file_index.end()) ? it->second.size : 0;
}

bool RpfVirtualFileSystem::OpenFile(const std::string& virtual_path, OpenFileHandle& out_file) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    auto it = m_file_index.find(norm);
    if (it == m_file_index.end() || it->second.is_directory) {
        return false;
    }

    HANDLE handle = CreateFileA(it->second.physical_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE) {
        return false;
    }

    uint64_t handle_id = m_next_handle++;
    out_file.virtual_path = norm;
    out_file.physical_path = it->second.physical_path;
    out_file.size = it->second.size;
    out_file.position = 0;
    out_file.handle = handle;

    m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
    return true;
}

bool RpfVirtualFileSystem::ReadFile(OpenFileHandle& file, void* buffer, uint64_t size, uint64_t& bytes_read) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_open_files.find(reinterpret_cast<uint64_t>(file.handle));
    if (it == m_open_files.end()) {
        return false;
    }

    DWORD read = 0;
    BOOL result = ReadFile(static_cast<HANDLE>(file.handle), buffer, static_cast<DWORD>(size), &read, nullptr);
    bytes_read = read;
    file.position += read;
    return result != FALSE;
}

bool RpfVirtualFileSystem::CloseFile(OpenFileHandle& file) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (file.handle) {
        CloseHandle(static_cast<HANDLE>(file.handle));
        file.handle = nullptr;
    }
    return true;
}

bool RpfVirtualFileSystem::SeekFile(OpenFileHandle& file, int64_t offset, int whence) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!file.handle) return false;

    DWORD moveMethod = FILE_BEGIN;
    if (whence == 1) moveMethod = FILE_CURRENT;
    else if (whence == 2) moveMethod = FILE_END;

    DWORD newPos = SetFilePointer(static_cast<HANDLE>(file.handle), static_cast<LONG>(offset), nullptr, moveMethod);
    if (newPos == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR) {
        return false;
    }
    file.position = newPos;
    return true;
}

bool RpfVirtualFileSystem::ListDirectory(const std::string& virtual_path, std::vector<std::string>& entries) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    auto it = m_file_index.find(norm);
    if (it == m_file_index.end() || !it->second.is_directory) {
        return false;
    }
    entries = it->second.children;
    return true;
}

} // namespace mcla::vfs

// Hook implementations
namespace mcla::vfs::hooks {

bool NtCreateFileHook(uint32_t oa, mcla::native::GuestMemoryView& view, uint32_t& out_status) {
    (void)oa;
    (void)view;
    (void)out_status;
    return false;
}

bool NtReadFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t& bytes_read) {
    (void)file_handle;
    (void)buffer;
    (void)length;
    (void)bytes_read;
    return false;
}

bool NtQueryInformationFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class) {
    (void)file_handle;
    (void)buffer;
    (void)length;
    (void)info_class;
    return false;
}

bool NtQueryDirectoryFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class) {
    (void)file_handle;
    (void)buffer;
    (void)length;
    (void)info_class;
    return false;
}

bool NtCloseHook(uint32_t file_handle) {
    (void)file_handle;
    return false;
}

} // namespace mcla::vfs::hooks