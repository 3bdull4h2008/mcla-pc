#include "vfs_rpf.h"

#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstring>

#include "guest_memory.h"
#include <rex/logging.h>

namespace mcla::vfs {

RpfVirtualFileSystem::RpfVirtualFileSystem() = default;

RpfVirtualFileSystem::~RpfVirtualFileSystem() {
    Unmount();
}

std::string RpfVirtualFileSystem::NormalizePath(const std::string& path) const {
    std::string result = path;
    // Convert to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    // Convert backslashes to forward slashes
    std::replace(result.begin(), result.end(), '\\', '/');
    // Remove duplicate slashes
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
    // Remove trailing slash unless it's root
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
    
    // Check if root exists
    std::filesystem::path root_path(extracted_cache_root);
    if (!std::filesystem::exists(root_path)) {
        REXLOG_ERROR("VFS: Extracted cache root does not exist: {}", extracted_cache_root);
        return false;
    }
    
    REXLOG_INFO("VFS: Initializing with extracted cache root: {}", extracted_cache_root);
    
    // Build the file index
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
    // Close all open files
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
    // Check if path starts with known virtual prefixes
    return (path.rfind("t:\\", 0) == 0 || 
            path.rfind("t:/", 0) == 0 ||
            path.rfind("t:\\mc4", 0) == 0 ||
            path.rfind("t:/mc4", 0) == 0 ||
            path.rfind("mc4/", 0) == 0);
}

std::string RpfVirtualFileSystem::GuestToVirtualPath(const std::string& guest_path) const {
    std::string path = guest_path;
    
    // Convert t:\... to mc4/...
    size_t pos = path.find("t:\\");
    if (pos != std::string::npos) {
        path = path.substr(pos + 3);
    } else if (path.rfind("t:/", 0) == 0) {
        path = path.substr(3);
    } else if (path.rfind("t:\\", 0) == 0) {
        path = path.substr(3);
    }
    
    // Convert backslashes to forward slashes
    for (char& c : path) {
        if (c == '\\') c = '/';
    }
    
    // Normalize
    return NormalizePath(path);
}

void RpfVirtualFileSystem::BuildIndex(const std::string& root) {
    m_file_index.clear();
    
    // Add root entry
    FileEntry root_entry;
    root_entry.virtual_path = "";
    root_entry.physical_path = m_extracted_root;
    root_entry.is_directory = true;
    m_file_index[""] = root_entry;
    
    // Scan the extracted cache directory
    std::filesystem::path root_path(m_extracted_root);
    if (std::filesystem::exists(root_path)) {
        for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(root_path)) {
            std::filesystem::path rel = std::filesystem::relative(dir_entry.path(), root_path);
            std::string virtual_path = rel.generic_string(); // uses forward slashes
            std::string virtual_norm = NormalizePath(rel.generic_string());
            
            FileEntry entry;
            entry.virtual_path = virtual_norm;
            entry.physical_path = dir_entry.path().generic_string();
            entry.is_directory = dir_entry.is_directory();
            entry.size = dir_entry.is_directory() ? 0 : std::filesystem::file_size(dir_entry.path());
            entry.is_directory = dir_entry.is_directory();
            
            m_file_index[virtual_norm] = entry;
            
            // Add to parent's children
            std::string parent = virtual_norm;
            size_t pos = virtual_norm.find_last_of('/');
            if (pos != std::string::npos) {
                std::string parent_path = virtual_norm.substr(0, pos);
                auto it = m_file_index.find(NormalizePath(parent_path));
                if (it != m_file_index.end()) {
                    it->second.children.push_back(virtual_norm.substr(pos + 1));
                }
            } else {
                // Root level
                auto it = m_file_index.find("");
                if (it != m_file_index.end()) {
                    it->second.children.push_back(virtual_norm);
                }
            }
        }
    }
    
    REXLOG_INFO("VFS: Built index with {} entries", m_file_index.size());
}

void RpfVirtualFileSystem::ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& parent_entry) {
    std::filesystem::path phys(physical_root);
    if (!std::filesystem::exists(phys)) return;
    
    for (const auto& dir_entry : std::filesystem::directory_iterator(phys)) {
        std::filesystem::path rel = std::filesystem::relative(dir_entry.path(), std::filesystem::path(physical_root));
        std::string virtual_path = NormalizePath(rel.generic_string());
        
        FileEntry entry;
        entry.virtual_path = virtual_root + (virtual_root.empty() ? "" : "/") + dir_entry.path().filename().generic_string();
        entry.virtual_path = NormalizePath(entry.virtual_path);
        entry.physical_path = dir_entry.path().generic_string();
        entry.is_directory = dir_entry.is_directory();
        entry.size = dir_entry.is_directory() ? 0 : std::filesystem::file_size(dir_entry.path());
        entry.is_directory = dir_entry.is_directory();
        
        m_file_index[virtual_path] = entry;
        
        if (entry.is_directory) {
            ScanDirectory(entry.physical_path, virtual_path, m_file_index[virtual_path]);
        }
    }
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
    if (it != m_file_index.end()) {
        return it->second.size;
    }
    return 0;
}

bool RpfVirtualFileSystem::OpenFile(const std::string& virtual_path, OpenFileHandle& out_file) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);
    
    auto it = m_file_index.find(norm);
    if (it == m_file_index.end() || it->second.is_directory) {
        return false;
    }
    
    HANDLE handle = CreateFileA(it->second.physical_path.c_str(),
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                nullptr,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
                                nullptr);
    
    if (handle == INVALID_HANDLE_VALUE) {
        REXLOG_ERROR("VFS: Failed to open file: {} (error={})", 
                     it->second.physical_path, GetLastError());
        return false;
    }
    
    uint64_t handle_id = m_next_handle++;
    auto file = std::make_unique<OpenFileHandle>();
    file->virtual_path = it->first;
    file->physical_path = it->second.physical_path;
    file->size = it->second.size;
    file->position = 0;
    file->handle = handle;
    
    out_file = *file;
    m_open_files[handle_id] = std::move(file);
    
    return true;
}

bool RpfVirtualFileSystem::ReadFile(OpenFileHandle& file, void* buffer, uint64_t size, uint64_t& bytes_read) {
    if (!file.handle) return false;
    
    // Seek to current position
    LARGE_INTEGER offset;
    offset.QuadPart = file.position;
    if (!SetFilePointerEx(static_cast<HANDLE>(file.handle), offset, nullptr, FILE_BEGIN)) {
        return false;
    }
    
    DWORD bytes_read_dw = 0;
    BOOL result = ::ReadFile(static_cast<HANDLE>(file.handle), buffer, static_cast<DWORD>(size), &bytes_read_dw, nullptr);
    bytes_read = bytes_read_dw;
    file.position += bytes_read;
    return result != FALSE;
}

bool RpfVirtualFileSystem::CloseFile(OpenFileHandle& file) {
    if (file.handle) {
        CloseHandle(static_cast<HANDLE>(file.handle));
        file.handle = nullptr;
    }
    return true;
}

bool RpfVirtualFileSystem::SeekFile(OpenFileHandle& file, int64_t offset_val, int whence) {
    if (!file.handle) return false;
    
    DWORD move_method = FILE_BEGIN;
    switch (whence) {
        case SEEK_SET: move_method = FILE_BEGIN; break;
        case SEEK_CUR: move_method = FILE_CURRENT; break;
        case SEEK_END: move_method = FILE_END; break;
    }
    
    LARGE_INTEGER offset;
    offset.QuadPart = offset_val;
    LARGE_INTEGER new_pos;
    if (!SetFilePointerEx(static_cast<HANDLE>(file.handle), offset, &new_pos, move_method)) {
        return false;
    }
    file.position = new_pos.QuadPart;
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

// Hook implementations
namespace hooks {

bool NtCreateFileHook(uint32_t oa, mcla::native::GuestMemoryView& view, uint32_t& out_status) {
    mcla::native::GuestMemoryView view_copy = view;
    uint32_t oa_copy = oa;
    
    // Read the object attributes
    uint32_t ansi_str = 0;
    uint16_t str_len = 0;
    uint32_t str_ptr = 0;
    
    if (oa && view.ReadU32BE(oa + 4, &ansi_str) && ansi_str &&
        view.ReadU16BE(ansi_str + 0, &str_len) &&
        view.ReadU32BE(ansi_str + 4, &str_ptr) && str_len > 0 &&
        str_len <= 1024 && str_ptr) {
        
        std::vector<char> buf(str_len);
        if (view.ReadBytes(str_ptr, buf.data(), str_len)) {
            std::string guest_path(buf.data(), str_len);
            
            // Check if this is a t:\ path that we should handle
            std::string path = guest_path;
            std::transform(path.begin(), path.end(), path.begin(), 
                           [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
            std::replace(path.begin(), path.end(), '\\', '/');
            
            if (path.rfind("t:/mc4/", 0) == 0 || path.rfind("t:/mc4", 0) == 0) {
                // This is a request for our virtual t:\ drive
                RpfVirtualFileSystem& vfs = RpfVirtualFileSystem::Instance();
                
                std::string vpath = guest_path;
                if (path.rfind("t:/", 0) == 0) {
                    path = path.substr(3);
                } else if (path.rfind("t:\\", 0) == 0) {
                    path = path.substr(3);
                }
                
                std::replace(path.begin(), path.end(), '\\', '/');
                
                // Check if file exists in our VFS
                if (RpfVirtualFileSystem::Instance().Exists(path)) {
                    // File exists in our VFS - we would need to create a handle here
                    // For now, let the original handle it (will fail if file doesn't exist in host FS)
                    // TODO: Implement proper handle creation
                }
            }
        }
    }
    
    return false; // Let original handle it
}

bool NtReadFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t& bytes_read) {
    return false; // Not implemented yet
}

bool NtQueryInformationFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class) {
    return false; // Not implemented yet
}

bool NtQueryDirectoryFileHook(uint32_t file_handle, void* buffer, uint32_t length, uint32_t info_class) {
    return false; // Not implemented yet
}

} // namespace hooks

} // namespace mcla::vfs