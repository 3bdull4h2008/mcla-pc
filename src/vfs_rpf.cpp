#include "vfs_rpf.h"
#include "logging.h"
#include "guest_memory.h"

#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace mcla::vfs {

namespace {

constexpr uint32_t kRpf3Magic = 0x52504633u; // "RPF3"
constexpr uint64_t kTocOffset = 0x1000;
constexpr uint64_t kHeaderOffset = 0x800;

void PushU32BE(std::vector<uint8_t>& v, uint32_t x) {
    v.push_back(static_cast<uint8_t>(x >> 24));
    v.push_back(static_cast<uint8_t>(x >> 16));
    v.push_back(static_cast<uint8_t>(x >> 8));
    v.push_back(static_cast<uint8_t>(x));
}

void PushU24BE(std::vector<uint8_t>& v, uint32_t x) {
    v.push_back(static_cast<uint8_t>(x >> 16));
    v.push_back(static_cast<uint8_t>(x >> 8));
    v.push_back(static_cast<uint8_t>(x));
}

struct RpfNode {
    std::string name;            // base name (root: "/")
    bool is_dir = false;
    uint64_t size = 0;
    std::string physical_path;
    std::vector<RpfNode> children;
};

void CollectTree(const std::filesystem::path& dir, RpfNode& out) {
    std::error_code ec;
    for (const auto& e : std::filesystem::directory_iterator(dir, ec)) {
        RpfNode child;
        child.name = e.path().filename().generic_string();
        child.is_dir = e.is_directory(ec);
        if (!child.is_dir) {
            child.size = std::filesystem::file_size(e.path(), ec);
        }
        child.physical_path = e.path().generic_string();
        if (child.is_dir) {
            CollectTree(e.path(), child);
        }
        out.children.push_back(std::move(child));
    }
}

struct TocEntry {
    uint32_t name_offset = 0;
    bool is_dir = false;
    uint32_t a = 0;   // dir: first_index | file: data_offset
    uint32_t b = 0;   // dir: child_count | file: stored size
    uint32_t c = 0;   // dir: child_count | file: uncompressed size
};

uint32_t AppendTree(std::vector<TocEntry>& entries, const RpfNode& node,
                    std::vector<uint8_t>& names, VirtualRpf& out,
                    uint64_t& data_cursor) {
    // Assign this subtree contiguously (DFS) so directory first_index/child_count stay valid.
    const uint32_t self_index = static_cast<uint32_t>(entries.size());

    TocEntry entry;
    entry.is_dir = node.is_dir;
    entry.name_offset = static_cast<uint32_t>(names.size());
    names.insert(names.end(), node.name.begin(), node.name.end());
    names.push_back(0);

    if (!node.is_dir) {
        VirtualRpfSegment seg;
        seg.virtual_offset = data_cursor;
        seg.size = node.size;
        seg.physical_path = node.physical_path;
        out.segments.push_back(seg);
        entry.a = static_cast<uint32_t>(data_cursor);
        entry.b = static_cast<uint32_t>(node.size);   // stored == uncompressed -> no LZX
        entry.c = static_cast<uint32_t>(node.size);
        data_cursor += (node.size + 15ull) & ~15ull;
    }

    entries.push_back(entry);

    if (node.is_dir) {
        const uint32_t first_child = static_cast<uint32_t>(entries.size());
        for (const auto& c : node.children) {
            AppendTree(entries, c, names, out, data_cursor);
        }
        const uint32_t count = static_cast<uint32_t>(entries.size()) - first_child;
        entries[self_index].a = first_child;
        entries[self_index].b = count;
        entries[self_index].c = count;
    }
    return self_index;
}

} // namespace

VirtualRpf::~VirtualRpf() {
    for (auto& seg : segments) {
        if (seg.host_handle) {
            CloseHandle(static_cast<HANDLE>(seg.host_handle));
            seg.host_handle = nullptr;
        }
    }
}

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
        MCLA_LOG_WARN("VFS: Already initialized");
        return true;
    }

    m_extracted_root = extracted_cache_root;

    std::filesystem::path root_path(extracted_cache_root);
    if (!std::filesystem::exists(root_path)) {
        MCLA_LOG_ERROR("VFS: Extracted cache root does not exist: {}", extracted_cache_root);
        return false;
    }

    MCLA_LOG_INFO("VFS: Initializing with extracted cache root: {}", extracted_cache_root);

    BuildIndex(extracted_cache_root);

    MCLA_LOG_INFO("VFS: Indexed {} files/directories", m_file_index.size());

    // probe: verify expected archive dirs made it into the index
    size_t dumped = 0;
    size_t xcount = 0;
    for (const auto& [key, e] : m_file_index) {
        if (dumped < 10 && !key.empty()) {
            MCLA_LOG_INFO("VFS: sample key='{}' is_dir={}", key, e.is_directory);
            ++dumped;
        }
        if (key.rfind("xarchive", 0) == 0) ++xcount;
    }
    MCLA_LOG_INFO("VFS: probe 'xarchive_audlo' count={} xarchive* entries={}",
                  m_file_index.count(std::string("xarchive_audlo")), xcount);

    Mount();
    return true;
}

void RpfVirtualFileSystem::Mount() {
    m_mounted = true;
    MCLA_LOG_INFO("VFS: Mounted virtual t:\\ drive");
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
    MCLA_LOG_INFO("VFS: Unmounted virtual t:\\ drive");
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
    std::error_code iter_ec;
    // error_code overloads everywhere: one unreadable file must not abort the walk
    std::filesystem::recursive_directory_iterator it(
        root_path,
        // the extracted cache uses NTFS junctions for the xarchive_* packs;
        // without this flag the iterator silently skips them entirely
        std::filesystem::directory_options::follow_directory_symlink |
            std::filesystem::directory_options::skip_permission_denied,
        iter_ec);
    std::filesystem::recursive_directory_iterator end_it;

    // manual virtual-path tracking: path arithmetic lies when junctions are
    // involved, but the iterator's depth never does
    std::vector<std::string> vstack;

    while (!iter_ec && it != end_it) {
        const auto& dir_entry = *it;
        std::error_code ec;

        while (vstack.size() > it.depth()) {
            vstack.pop_back();
        }

        const std::string name = dir_entry.path().filename().generic_string();
        std::string virtual_norm;
        for (const auto& part : vstack) {
            virtual_norm += part;
            virtual_norm += '/';
        }
        virtual_norm += name;
        virtual_norm = NormalizePath(virtual_norm);

        bool is_dir = dir_entry.is_directory(ec);
        uint64_t fsize = 0;
        if (!ec && !is_dir) {
            fsize = std::filesystem::file_size(dir_entry.path(), ec);
        }
        if (!ec) {
            FileEntry entry;
            entry.virtual_path = virtual_norm;
            entry.physical_path = dir_entry.path().generic_string();
            entry.is_directory = is_dir;
            entry.size = fsize;

            m_file_index[virtual_norm] = entry;

            std::string parent = virtual_norm;
            const size_t last_slash = parent.find_last_of('/');
            parent = (last_slash == std::string::npos) ? "" : parent.substr(0, last_slash);
            auto pit = m_file_index.find(parent);
            if (pit != m_file_index.end()) {
                pit->second.children.push_back(name);
            }

            if (is_dir) {
                vstack.push_back(name);
            }
        }
        it.increment(iter_ec);
    }
}

void RpfVirtualFileSystem::ScanDirectory(const std::string& physical_root, const std::string& virtual_root, FileEntry& entry) {
    (void)physical_root;
    (void)virtual_root;
    (void)entry;
}

bool RpfVirtualFileSystem::BuildVirtualRpf(const FileEntry& dir_entry, VirtualRpf& out) {
    RpfNode root;
    root.name = "/";
    root.is_dir = true;
    root.physical_path = dir_entry.physical_path;
    CollectTree(std::filesystem::path(dir_entry.physical_path), root);

    std::vector<TocEntry> entries;
    std::vector<uint8_t> names;
    uint64_t data_cursor = 0;   // relative to data start; rebased below

    AppendTree(entries, root, names, out, data_cursor);

    const uint64_t entry_count = entries.size();
    uint64_t toc_size = entry_count * 16ull;
    if (toc_size < 2048ull) toc_size = 2048ull;

    // data starts after TOC + names, aligned like the reference layout
    uint64_t names_offset = kTocOffset + toc_size;
    uint64_t data_start = (names_offset + names.size() + 2047ull) & ~2047ull;

    // rebase file offsets from data-relative to absolute
    for (auto& seg : out.segments) {
        seg.virtual_offset += data_start;
    }
    for (auto& e : entries) {
        if (!e.is_dir) {
            e.a = static_cast<uint32_t>(e.a + data_start);
        }
    }
    out.total_size = data_start + data_cursor;

    // preamble = zeros + header + TOC + names
    out.preamble.assign(static_cast<size_t>(data_start), 0);
    auto w32 = [&](uint64_t at, uint32_t v) {
        out.preamble[at + 0] = static_cast<uint8_t>(v >> 24);
        out.preamble[at + 1] = static_cast<uint8_t>(v >> 16);
        out.preamble[at + 2] = static_cast<uint8_t>(v >> 8);
        out.preamble[at + 3] = static_cast<uint8_t>(v);
    };
    w32(kHeaderOffset + 0, kRpf3Magic);
    w32(kHeaderOffset + 4, static_cast<uint32_t>(toc_size));
    w32(kHeaderOffset + 8, static_cast<uint32_t>(entry_count));

    uint64_t toc_at = kTocOffset;
    size_t byte_at = static_cast<size_t>(toc_at);
    for (const auto& e : entries) {
        if (byte_at + 16 > out.preamble.size()) break;
        out.preamble[byte_at + 0] = static_cast<uint8_t>(e.name_offset >> 16);
        out.preamble[byte_at + 1] = static_cast<uint8_t>(e.name_offset >> 8);
        out.preamble[byte_at + 2] = static_cast<uint8_t>(e.name_offset);
        out.preamble[byte_at + 3] = e.is_dir ? 0x80 : 0x00;
        auto put32 = [&](size_t at, uint32_t v) {
            out.preamble[at + 0] = static_cast<uint8_t>(v >> 24);
            out.preamble[at + 1] = static_cast<uint8_t>(v >> 16);
            out.preamble[at + 2] = static_cast<uint8_t>(v >> 8);
            out.preamble[at + 3] = static_cast<uint8_t>(v);
        };
        put32(byte_at + 4, e.a);
        put32(byte_at + 8, e.b);
        put32(byte_at + 12, e.c);
        byte_at += 16;
    }

    std::memcpy(out.preamble.data() + names_offset, names.data(), names.size());

    MCLA_LOG_INFO("VFS: synthesized RPF3 '{}' entries={} toc={} data@{:#x} total={}",
                  dir_entry.virtual_path, entry_count, toc_size, data_start, out.total_size);
    return true;
}

std::shared_ptr<VirtualRpf> RpfVirtualFileSystem::GetOrBuildVirtualRpf(const std::string& dir_key) {
    auto cached = m_virtual_rpfs.find(dir_key);
    if (cached != m_virtual_rpfs.end()) {
        return cached->second;
    }
    auto it = m_file_index.find(dir_key);
    if (it == m_file_index.end() || !it->second.is_directory) {
        return nullptr;
    }
    auto built = std::make_shared<VirtualRpf>();
    if (!BuildVirtualRpf(it->second, *built)) {
        return nullptr;
    }
    m_virtual_rpfs[dir_key] = built;
    return built;
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
    // synthesized packfile sizes
    if (norm.size() > 4 && norm.compare(norm.size() - 4, 4, ".rpf") == 0) {
        auto& self = const_cast<RpfVirtualFileSystem&>(*this);
        if (auto rpf = self.GetOrBuildVirtualRpf(norm.substr(0, norm.size() - 4))) {
            return rpf->total_size;
        }
    }
    return 0;
}

bool RpfVirtualFileSystem::OpenFile(const std::string& virtual_path, OpenFileHandle& out_file) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string norm = NormalizePath(virtual_path);

    // synthesized .rpf opens: serve an RPF3 image built over the extracted dir
    if (norm.size() > 4 && norm.compare(norm.size() - 4, 4, ".rpf") == 0) {
        const std::string dir_key = norm.substr(0, norm.size() - 4);
        auto idx_it = m_file_index.find(dir_key);
        MCLA_LOG_INFO("VFS: rpf open '{}' dir_key='{}' indexed={} is_dir={}",
                      norm, dir_key, idx_it != m_file_index.end(),
                      idx_it != m_file_index.end() ? idx_it->second.is_directory : false);
        if (auto rpf = GetOrBuildVirtualRpf(dir_key)) {
            const uint64_t handle_id = m_next_handle++;
            out_file.virtual_path = norm;
            out_file.physical_path.clear();
            out_file.size = rpf->total_size;
            out_file.position = 0;
            out_file.handle = nullptr;
            out_file.virtual_rpf = rpf;
            m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
            return true;
        }
    }

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
    out_file.virtual_rpf.reset();

    m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
    return true;
}

namespace {

// synchronous positional read helper (does not disturb any shared file pointer)
bool PreadHost(void* handle, uint64_t offset, void* buffer, size_t size) {
    if (size == 0) return true;
    if (!handle) {
        // open lazily on first use
        return false;
    }
    LARGE_INTEGER li{};
    li.QuadPart = static_cast<LONGLONG>(offset);
    OVERLAPPED ov{};
    ov.Offset = static_cast<DWORD>(offset);
    ov.OffsetHigh = static_cast<DWORD>(offset >> 32);
    DWORD got = 0;
    if (!::ReadFile(static_cast<HANDLE>(handle), buffer, static_cast<DWORD>(size), &got, &ov) ||
        got != size) {
        return false;
    }
    (void)li;
    return true;
}

} // namespace

bool RpfVirtualFileSystem::ReadFile(OpenFileHandle& file, void* buffer, uint64_t size, uint64_t& bytes_read) {
    std::lock_guard<std::mutex> lock(m_mutex);
    bytes_read = 0;

    if (file.virtual_rpf) {
        VirtualRpf& rpf = *file.virtual_rpf;
        if (file.position >= rpf.total_size) {
            return true;   // EOF
        }
        const uint64_t want = std::min<uint64_t>(size, rpf.total_size - file.position);
        uint8_t* dst = static_cast<uint8_t*>(buffer);
        uint64_t done = 0;

        while (done < want) {
            const uint64_t cur = file.position + done;
            if (cur < rpf.preamble.size()) {
                const uint64_t n = std::min<uint64_t>(want - done, rpf.preamble.size() - cur);
                std::memcpy(dst + done, rpf.preamble.data() + cur, static_cast<size_t>(n));
                done += n;
                continue;
            }

            VirtualRpfSegment* seg = nullptr;
            for (auto& s : rpf.segments) {
                if (cur >= s.virtual_offset && cur < s.virtual_offset + s.size) {
                    seg = &s;
                    break;
                }
            }
            if (!seg) {
                // gap between aligned files: zeros
                const uint64_t next = rpf.total_size;
                uint64_t n = want - done;
                for (const auto& s : rpf.segments) {
                    if (s.virtual_offset > cur) {
                        n = std::min<uint64_t>(n, s.virtual_offset - cur);
                        break;
                    }
                }
                (void)next;
                std::memset(dst + done, 0, static_cast<size_t>(n));
                done += n;
                continue;
            }

            if (!seg->host_handle) {
                HANDLE h = CreateFileA(seg->physical_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
                                       nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
                if (h == INVALID_HANDLE_VALUE) {
                    return false;
                }
                seg->host_handle = h;
            }
            const uint64_t local = cur - seg->virtual_offset;
            const uint64_t n = std::min<uint64_t>(want - done, seg->size - local);
            if (!PreadHost(seg->host_handle, local, dst + done, static_cast<size_t>(n))) {
                return false;
            }
            done += n;
        }

        file.position += done;
        bytes_read = done;
        return true;
    }

    DWORD read = 0;
    BOOL result = ::ReadFile(static_cast<HANDLE>(file.handle), buffer, static_cast<DWORD>(size), &read, nullptr);
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
    file.virtual_rpf.reset();
    return true;
}

bool RpfVirtualFileSystem::SeekFile(OpenFileHandle& file, int64_t offset, int whence) {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (file.virtual_rpf) {
        uint64_t base = 0;
        if (whence == 1) {
            base = file.position;
        } else if (whence == 2) {
            base = file.virtual_rpf->total_size;
        }
        file.position = static_cast<uint64_t>(static_cast<int64_t>(base) + offset);
        return true;
    }

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
