#include "fs/vfs_rpf.h"
#include "logging.h"
#include "guest_memory.h"
#include "raw_inflate.h"

#include <fstream>
#include <algorithm>
#include <atomic>
#include <cctype>
#include <cstring>
#include <map>

namespace mcla::vfs {

// F-628: declared here, defined after the registry block near the end of the
// file. Used by GetFileSize/OpenFile; the registry is a file-scope map so the
// census in gpu_device.cpp can reach it without the VFS singleton.
std::shared_ptr<NestedRpfArchive> FindNestedRpf(const std::string& name);

namespace {

// The synthetic image's own layout constants (BuildVirtualRpf), NOT the real
// on-disk one — that is mcla::vfs::kRpf3Magic / kRpf3HeaderOffset in
// fs/rpf3_nested.h, and the two differ: the synthetic TOC sits at 0x1000 with a
// zero preamble, the real header at 0 and the real TOC at 0x800. Both spell
// 'RPF3', hence the different names.
constexpr uint32_t kSynthRpf3Magic = 0x52504633u;
constexpr uint64_t kTocOffset = 0x1000;
constexpr uint64_t kHeaderOffset = 0x800;

// F-628: depth cap for BuildIndex. 64 is far above the deepest real path in
// this title (6 levels: shaders/ui/preload.list) and bounds a junction cycle.
constexpr unsigned kIndexMaxDepth = 64;

// F-628: the nested-packfile registry, file-scope so the census in
// gpu_device.cpp can reach it without the VFS singleton. Append-only for the
// life of a boot (cleared on Unmount), so a shared_ptr handed out under the
// lock can never be invalidated. Lock order: g_nestedMtx is always INNERMOST —
// nothing takes m_mutex while holding it.
std::mutex g_nestedMtx;
std::map<std::string, std::shared_ptr<NestedRpfArchive>> g_nested;

std::string NormalizeNestedKey(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    std::replace(out.begin(), out.end(), '\\', '/');
    // The guest reaches the same member under several spellings: the packfile
    // open is `preload/xarchive_cameratune.rpf` while the member open is
    // `a:/archive/preload/xarchive_cameratune.rpf`. Strip the archive-side
    // device prefixes so all of them resolve to one key.
    static const char* kPrefixes[] = {"a:/archive/", "game:/", "game:\\", "game:"};
    for (const char* pfx : kPrefixes) {
        const size_t n = std::strlen(pfx);
        if (out.size() > n && _strnicmp(out.c_str(), pfx, n) == 0) {
            out = out.substr(n);
            break;
        }
    }
    while (!out.empty() && out.back() == '/') out.pop_back();
    return out;
}

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

    // Scan the extracted cache. In the committed tree that directory is EMPTY
    // by design (PROGRAM_GUIDE §3: "must exist (empty OK)"), which is why every
    // pre-F-628 soak logged `VFS: Indexed 1 files/directories` and
    // `xarchive* entries=0`.
    BuildIndex(extracted_cache_root);

    // F-628: this pass used to be a no-op. BuildIndex ignored its argument
    // (cleared the index and walked m_extracted_root), so it re-walked the
    // empty cache and game_data was never indexed; OpenFile's real-packfile
    // branch was the only thing that reached the packs. BuildIndex now walks
    // the root it is given and merges, so the four real packfiles and the loose
    // .bik movies land in the index and the sample/probe lines below mean
    // something. m_game_data_root is the same directory, remembered because
    // OpenFile's real-packfile branch and the nested-archive registrar both
    // need it and neither has the extracted path.
    std::filesystem::path extracted_path(extracted_cache_root);
    std::filesystem::path game_data_root = extracted_path.parent_path();
    if (std::filesystem::exists(game_data_root)) {
        m_game_data_root = game_data_root.string();
        MCLA_LOG_INFO("VFS: Also scanning game_data root for loose files: {}",
                      m_game_data_root);
        BuildIndex(m_game_data_root);
    }

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

std::string RpfVirtualFileSystem::GameDataRoot() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_game_data_root;
}

void RpfVirtualFileSystem::Unmount() {
    for (auto& [handle, file] : m_open_files) {
        if (file->handle) {
            CloseHandle(static_cast<HANDLE>(file->handle));
        }
    }
    m_open_files.clear();
    m_file_index.clear();
    m_game_data_root.clear();
    m_mounted = false;
    // F-628: the nested packfile registry lives outside the VFS object (the
    // census in gpu_device.cpp reaches it without the singleton), so clear it
    // explicitly. Each entry holds an inflated member image of up to 705 KiB
    // (measured) plus its own mutex; dropping them here means a re-Initialize
    // re-materializes from the current on-disk pack instead of serving a stale
    // image.
    {
        std::lock_guard<std::mutex> lk(g_nestedMtx);
        g_nested.clear();
    }
    MCLA_LOG_INFO("VFS: Unmounted virtual t:\\ drive");
}

bool RpfVirtualFileSystem::IsVirtualPath(const std::string& path) const {
    std::string norm = NormalizePath(path);
    return (norm.rfind("t:\\", 0) == 0 ||
            norm.rfind("t:/", 0) == 0 ||
            norm.rfind("t:\\mc4", 0) == 0 ||
            norm.rfind("t:/mc4", 0) == 0 ||
            norm.rfind("mc4/", 0) == 0);
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

// F-628: BuildIndex HONOURS ITS ARGUMENT. It used to ignore `root` entirely --
// it cleared m_file_index and walked m_extracted_root -- so Initialize()'s
// second pass (src/fs/vfs_rpf.cpp:175-180) re-walked the same empty cache and
// game_data stayed un-indexed. That is why every soak logs
// `VFS: Indexed 1 files/directories` and `xarchive* entries=0`: the index holds
// the empty cache root and nothing else. The walk is now over `root`, and the
// roots are ADDITIVE (the old `clear()` is what made a second call destroy the
// first), so the game_data pass adds the real packfiles and the loose .bik
// movies instead of replacing the cache with them.
//
// Depth cap: game_data holds four 1.4-2.0 GiB packfiles plus whatever the
// extracted cache contains. A 64-level cap cannot truncate a real tree (the
// deepest path measured in this title is 6) but bounds a symlink/junction
// cycle, which the recursive iterator would otherwise walk forever. The walk
// also never follows into a file, so packfile size is a single stat.
void RpfVirtualFileSystem::BuildIndex(const std::string& root) {
    if (root.empty()) return;

    const std::filesystem::path root_path(root);
    std::error_code exists_ec;
    if (!std::filesystem::is_directory(root_path, exists_ec)) {
        MCLA_LOG_WARN("VFS: BuildIndex root '{}' is not a directory, skipped", root);
        return;
    }

    // The first root walked becomes the virtual "/" anchor; later roots are
    // merged under it (F-628: additive, see above).
    if (m_file_index.find("") == m_file_index.end()) {
        FileEntry root_entry;
        root_entry.virtual_path = "";
        root_entry.physical_path = root;
        root_entry.is_directory = true;
        m_file_index[""] = root_entry;
    }

    std::error_code iter_ec;
    // error_code overloads everywhere: one unreadable file must not abort the walk
    std::filesystem::recursive_directory_iterator it(
        root_path,
        // Kept for a populated cache: when the extracted cache is laid out per
        // pack the xarchive_* entries are junctions, and MSVC's recursive
        // iterator does not descend a reparse point without this flag. The
        // committed cache is empty (PROGRAM_GUIDE §3) and no soak has ever
        // logged an xarchive* entry, so today this guards nothing that exists.
        std::filesystem::directory_options::follow_directory_symlink |
            std::filesystem::directory_options::skip_permission_denied,
        iter_ec);
    std::filesystem::recursive_directory_iterator end_it;

    // manual virtual-path tracking: path arithmetic lies when junctions are
    // involved, but the iterator's depth never does
    std::vector<std::string> vstack;

    while (!iter_ec && it != end_it) {
        if (it.depth() > kIndexMaxDepth) {
            MCLA_LOG_WARN("VFS: BuildIndex depth cap {} hit under '{}', stopping",
                          kIndexMaxDepth, root);
            break;
        }
        const auto& dir_entry = *it;
        std::error_code ec;

        while (vstack.size() > it.depth()) {
            vstack.pop_back();
        }

        const std::string name = dir_entry.path().filename().generic_string();
        if (name.empty() || name == "." || name == "..") {
            it.increment(iter_ec);
            continue;
        }
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
    w32(kHeaderOffset + 0, kSynthRpf3Magic);
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

    // F-628: a nested packfile's size is its LOGICAL (inflated) size, which is
    // the guest's own w1. Serving the stored size here is what makes a nested
    // open report a stream too short to hold its own TOC.
    if (auto nested = FindNestedRpf(norm)) {
        return nested->logical_length();
    }

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

    // F-628: a NESTED packfile open (`preload/xarchive_cameratune.rpf`). The
    // name is resolved through the normalized form, so `a:/archive/preload/
    // xarchive_cameratune.rpf` and `preload/xarchive_cameratune.rpf` both land
    // here — the guest's own TOC hands the member the `preload/`-prefixed name
    // while the archive it lives in is the outer `xarchive_cache.rpf`.
    if (auto nested = FindNestedRpf(norm)) {
        const uint64_t handle_id = m_next_handle++;
        out_file.virtual_path = norm;
        out_file.physical_path.clear();
        out_file.size = nested->logical_length();
        out_file.position = 0;
        out_file.handle = nullptr;
        out_file.virtual_rpf.reset();
        out_file.nested_rpf = std::move(nested);
        m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
        MCLA_LOG_INFO("VFS: opened NESTED packfile '{}' logical={}", norm,
                      out_file.size);
        return true;
    }

    // synthesized .rpf opens: serve an RPF3 image built over the extracted dir
    if (norm.size() > 4 && norm.compare(norm.size() - 4, 4, ".rpf") == 0) {
        // PREFER the real packfile from the dump root (game_data\<name>.rpf) -
        // genuine TOC/data beats any reconstruction, exactly like Xenia's
        // HostPathDevice serving the mounted volume.
        std::error_code size_ec;
        const auto real_path = std::filesystem::path(m_extracted_root).parent_path() / norm;
        const uint64_t real_size = std::filesystem::file_size(real_path, size_ec);
        if (!size_ec) {
            HANDLE h = CreateFileA(real_path.string().c_str(), GENERIC_READ, FILE_SHARE_READ,
                                   nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (h != INVALID_HANDLE_VALUE) {
                const uint64_t handle_id = m_next_handle++;
                out_file.virtual_path = norm;
                out_file.physical_path = real_path.generic_string();
                out_file.size = real_size;
                out_file.position = 0;
                out_file.handle = h;
                out_file.virtual_rpf.reset();
                out_file.nested_rpf.reset();
                m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
                MCLA_LOG_INFO("VFS: opened REAL packfile '{}' ({} MB)", norm,
                              static_cast<int>(real_size >> 20));
                return true;
            }
        }

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
    out_file.nested_rpf.reset();

    m_open_files[handle_id] = std::make_unique<OpenFileHandle>(out_file);
    return true;
}

namespace {

// synchronous positional read helper (does not disturb any shared file pointer)
bool PreadHost(void* handle, uint64_t offset, void* buffer, size_t size) {
    if (size == 0) return true;
    if (!handle) {
        // no lazy open in this helper — a null handle is simply a failed read;
        // the caller (ReadFile) opens the segment handle before calling.
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

    if (!file.handle && !file.virtual_rpf) {
        // Pseudo-file (raw device like \Device\Harddisk0\partition0): behave
        // like an empty volume - reads succeed and return zeroed sectors.
        std::memset(buffer, 0, static_cast<size_t>(size));
        file.position += size;
        bytes_read = size;
        return true;
    }

    // F-628: a NESTED packfile on the shared-position path (the positional path
    // in ReadFileAt handles it directly and is what the guest uses).
    if (file.nested_rpf) {
        if (file.position >= file.nested_rpf->logical_length()) {
            return true;  // EOF
        }
        const uint64_t want = std::min<uint64_t>(
            size, file.nested_rpf->logical_length() - file.position);
        if (!file.nested_rpf->Materialize()) return false;
        file.position += want;
        bytes_read = want;
        return file.nested_rpf->Read(file.position - want, buffer,
                                     static_cast<size_t>(want));
    }

    DWORD read = 0;
    BOOL result = ::ReadFile(static_cast<HANDLE>(file.handle), buffer, static_cast<DWORD>(size), &read, nullptr);
    bytes_read = read;
    // F-628 DOUBLE-ADVANCE FIX. This used to be `file.position += read`, and
    // the only caller of the non-positional path adds the same amount again
    // right afterwards (src/kernel/imports.cpp:1123-1127:
    //   offset = fileObj->fileHandle.position;
    //   ok = vfs.ReadFile(fileObj->fileHandle, hostPtr, length, bytesRead);
    //   if (ok) fileObj->fileHandle.position += bytesRead;
    // ) so every non-positional NtReadFile advanced the stream by TWICE the
    // bytes it returned: a 32 KiB read left the file position 64 KiB on, and
    // the next read started one whole window past the data it had just
    // skipped. That is the same class of starvation as the F442-SECTION
    // starve (a reader that is given the wrong window), which is why the
    // tokenizer's own refill (sub_821BE4F0) reports -1 with pos==end.
    // ReadFileAt's fallback path sets file.position = offset before calling
    // here, so the same single advance is correct for it too.
    file.position += read;
    return result != FALSE;
}

namespace {
// F-628: the member-expansion registry, generalized.
//
// WHAT WAS WRONG, precisely. The pre-F-628 registry had one shape, gated to
// `IsCachePackfile` (xarchive_cache.rpf only), covering 16 hand-listed spans,
// with TWO incompatible meanings for its one length field: the six .list spans
// registered the stored length (F-105's correction to F-073, "in == out"), the
// ten entity.type spans registered the LOGICAL length (F-105's own header
// documents the third case). Substitution was refused unless ONE read covered
// the whole span.
//
// WHY THAT REFUSAL COST THE BOOT. The guest pages archive reads in 32 KiB
// windows (NFS-CENSUS[Read] `len=32768`, w653). The three nested packfiles are
// 296 KiB, 416 KiB and 705 KiB inflated, so no window can cover one whole:
//   preload/xarchive_cameratune.rpf  off=003F0000  logical=425,984
//   preload/xarchive_bootscripts.rpf off=00368000  logical=720,896
//   preload/xarchive_carconfigs.rpf  off=00448000  logical=294,912
// All three straddle, all three were therefore refused, and the guest got the
// raw DEFLATE stream. F-458 measured that as "the nested archives open but
// tune/vehicle/*.lst yields no stream" and concluded the host plant pre-empts
// the guest's decrypt -- but the F-458 control measurement (no second RPF3 in
// the first 64 MiB) was itself reading the wrong bytes. The bytes there ARE a
// nested RPF3: raw-inflating 0x3F0000 with the guest's own stored length
// (w3&0xFFFFFF = 0x503CF) yields 425,984 bytes beginning
// `52 50 46 33 00 38 00 00 18 03 00 00` = RPF3, TOC length 14,336, 792 entries.
// The same holds for 0x368000 -> 720,896 and 0x448000 -> 294,912. So the host
// was never pre-empting a decrypt; it was serving compressed bytes under a
// decompressed-name contract and the guest's RPF3 header parse of the inner
// archive therefore failed, which is what starved the `Vehicle` section walk
// (F442-SECTION: 14 rows, all hits=0).
//
// THE CONTRACT, measured over all 377 distinct members w653 published:
//   w1            logical length the guest must see
//   w2            member data offset in the packfile
//   w3 & 0xFFFFFF stored (compressed) length (bit30 is the open-gate flag)
//   inflate(stored bytes at w2) == w1        364 members
//   stored == w1 (member stored UNCOMPRESSED, serve verbatim)   6 members
//   neither (UI .xsf/.xtd XCompress/LZX containers, not raw DEFLATE)   7
// 370 of 377 are decided by that rule, with no name table at all.
// `ExpandedSpan` moved to src/fs/vfs_rpf.h (F-645): the tail-claim rule
// classifies it and its terms used to be prose in this file alone. The TABLE and
// its mutex stay file-local; only the shape of one row is now shared.
std::mutex g_expMtx;
std::vector<ExpandedSpan> g_expSpans;

// F-720 (2026-10-01). One key per (owner, victim) pair already named by
// MEMBER-SPAN-ALIAS, so that marker is a census line per collision and not a
// per-window flood -- the same one-shot discipline F-638's `named` and F-642's
// `overrunNamed` already keep for their own markers. Key is
// (ownerOff << 32) | victimOff; both are 32-bit packfile offsets (w2 &
// 0x7FFFFFFF), so the packing is lossless. Guarded by g_expMtx, which the
// caller already holds. REMOVAL TRIGGER: goes with the MEMBER-SPAN-ALIAS
// block in ApplyExpandedSpans.
std::vector<uint64_t> g_aliasNamed;

std::string PackKeyOf(const std::string& physical_path) {
    // basename, lowercased. A physical path is the only thing the read path
    // knows about a handle, and two packfiles can share a name only if they
    // are the same packfile.
    const size_t slash = physical_path.find_last_of("/\\");
    std::string name =
        (slash == std::string::npos) ? physical_path : physical_path.substr(slash + 1);
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return name;
}

bool SpanMatchesPack(const ExpandedSpan& s, const std::string& packKey) {
    return s.packfile.empty() || packKey.empty() || s.packfile == packKey;
}

// F-642 (2026-09-30). THE MEASUREMENT. Of the 120 distinct windows w673.log's
// MEMBER-SPAN-OWNER rows name, 98 are served from inside their owner's own
// stored range and 4 are served from its LOGICAL TAIL -- i.e. from a byte past
// the owner's own last file byte. Those 4 split on one bit and nothing else:
//
//   window [001E0000,001E8000) 32 KiB  owner 001DA000 stored 12572 -> head is
//                                                            12,004 past storedEnd
//   window [002E8000,002F0000) 32 KiB  owner 002E6000 stored  7572 -> 620 past
//   window [00350000,00358000) 32 KiB  owner 00340000 stored 47906 -> 17,630 past
//   window [0031504C,00315CEF) 3235 B  owner 00315000 stored    76 ->      0 past
//
// The last one is ScreenTint.fxc, and the owner is ScreenTint.dcl, whose stored
// extent is [00315000,0031504C) and whose LOGICAL extent is [00315000,0031504F).
// The guest asked for the .fxc. The window head 0031504C is the byte the packer
// put immediately after the .dcl's last file byte, so it is the .fxc's first
// byte and not the .dcl's. The .dcl inflated to 79 bytes over a 76-byte stored
// extent, its tail is `20 0d 0a`, and the W64 tail rule wrote those 3 bytes over
// the .fxc's head -- `TOCSERVE-EXPANDED leaf='ScreenTint.fxc' ... head=200D0A6C`,
// against the `72677861` the game compares to at 0x8218C848. Reproduced offline
// from the packfile's own bytes: 00315000 stored 76 inflates to 79 ending
// `...20 0d 0a`, and file[0031504F] = 6C, so 20 0d 0a 6c = 200D0A6C to the byte.
//
// So the split is not "deep tail" versus "shallow tail" and no threshold
// separates them: it is WHOSE byte the head is. A member's logical tail is not a
// claim on the file at all -- the console's own decompressor writes it into a
// caller-owned destination buffer sized by the declared uncompressed length and
// never over its source (xenia/src/xenia/cpu/lzx.h:22-24 takes `void* dest,
// size_t dest_len` beside `const void* lzx_data, size_t lzx_len`; lzx.cc:109
// opens `dest` with `dest_len` and lzx.cc:124 runs
// `lzxd_decompress(lzzd, (off_t)dest_len)` -- the output bound is the CALLER'S
// declared length and `lzx_len` never appears as one). The host has the same
// freedom and must spend it in the same currency: only the member being read may
// lay its tail into the window.
//
// Two cases void a tail claim, and both are statements about the FILE:
//
//   kBoundaryByte -- the head IS `off + storedLen`. That is the stored-end
//     boundary: by the member's own record the byte at that offset is not this
//     member's, it is whatever the packer placed next. Measured: the only window
//     in w673 that lands exactly here is the ScreenTint one.
//   kNeighbour -- a DIFFERENT span that has RESOLVED (so its `stored` field is
//     corroborated, per F-638) has the head inside its own stored range. The
//     resolved test is load-bearing: the six uncorroborated RSC5 containers
//     imply 0.5-7.6 MB of extent and would otherwise void 24 MB of honest
//     claims. This is why a claim that cannot be backed cannot win here either.
//
// A head inside the owner's own stored range (98 windows) and a head strictly
// inside a continuation (the three 32 KiB nested-packfile windows, which is how
// xarchive_soundbank.rpf's 294,912 logical bytes over 165,811 stored reassemble
// at all) are both UNTOUCHED. A window whose owner has a valid claim elects
// exactly as before; the veto can only turn an owner into no-owner, which is
// the F-638 no-owner path this file already uses and has already measured.
// F-645 (2026-09-30) adds the third void case below and changes NEITHER of these
// two, nor the boundary-bit test that separates them.
//
// F-645 (2026-09-30). THE THIRD VOID CASE, and the reason it is needed.
//
// THE MEASUREMENT (src/fs/vfs_rpf.h declares the rule; this is the evidence for
// one of its five verdicts). w674.log serves sixteen TOC members through
// MclaTocServeMember and fifteen of them print TOCSERVE-DEFLATE with the head
// their own bytes carry. The sixteenth does not:
//
//   TOCSERVE-EXPANDED leaf='PowerupTargetEffect.fxc' off=002B3000 stored=1864
//                     tocW1=4561 served=4561 head=6D2E7570
//
// `6D2E7570` is `PowerupShootEffect.fxc`'s own inflated body. That member is
// 16 TOCSERVE rows earlier, off=002B26E7 stored=2033, and inflates to 5976 --
// so its LOGICAL extent runs to 002B26E7+5976 = 002B3E3F, which is 2329 bytes
// PAST its own stored end 002B2E90 and swallows the next member's head
// 002B3000 whole. Step 2 of the corroboration then read a window at 002B3000,
// the election made the .fxc its owner, its tail wrote the head, and the
// inflate leg was SKIPPED because the bytes no longer looked like a bare
// DEFLATE stream -- it took TOCSERVE-EXPANDED instead and 6D2E7570 passed
// STEP5 only because 0x6D is a printable first byte. `72677861` ('rgxa') is the
// head the game compares to; offline, 002B3000 stored=1864 inflates to exactly
// 4561 == w1 and begins 72 67 78 61.
//
// WHY NEITHER PRE-EXISTING VOID FIRED, which is the whole point of the new one:
//   * kBoundaryByte needs head == off+storedLen, i.e. 002B2E90. The head is
//     2329 bytes further on.
//   * kNeighbour needs a RESOLVED span whose STORED range covers 002B3000 --
//     and the span that would supply it is PowerupTargetEffect.fxc ITSELF,
//     which is not in the table yet, because MarkMemberExpandedIn is step 6 and
//     this read is step 2. A member is registered AFTER the read that publishes
//     it, so for the one window that matters most the neighbour case is
//     structurally blind.
// That is why the fix is fed the read's OWN `rec.off` rather than a wider
// neighbourhood test, and why kNeighbour itself is left exactly as it is: five
// of the six fabricated container offsets are themselves window heads and the
// containment test covers 75-110 of 110 heads, so loosening it would void the
// ~24 MB of honest claims the comment above protects.
//
// The four verdicts kInStoredRange / kContinuation / kBoundaryByte /
// kNeighbour and the boundary-bit test that separates the two stored-range
// cases are UNCHANGED by this case; the declaration in src/fs/vfs_rpf.h states
// the full order and why the new test is last. The definition follows, at
// namespace scope, because the header declares it.

uint32_t CountNewlines(const std::vector<uint8_t>& v) {
    uint32_t n = 0;
    for (uint8_t b : v) {
        if (b == '\n') ++n;
    }
    return n;
}

uint32_t BeHead32(const std::vector<uint8_t>& v) {
    if (v.size() < 4) return 0;
    return (static_cast<uint32_t>(v[0]) << 24) | (static_cast<uint32_t>(v[1]) << 16) |
           (static_cast<uint32_t>(v[2]) << 8) | static_cast<uint32_t>(v[3]);
}

// A member's STORED bytes, read from the packfile BY POSITION and from nowhere
// else. This is the file's own content: no decode of any kind. It is the shared
// source for the verbatim branch, which has no inflate step to read through, and
// it is the same source, by the same mechanism, that the inflate branch reads
// through on its own.
//
// F-647 (2026-09-30). The window branch this used to try FIRST is the twin of
// the inflate-path defect F-646 corrected, on the path F-646 deliberately left
// alone so it could be handled here. THE MEASUREMENT, and it is not a
// hypothetical. build/w677.log line 38260:
//
//   MEMBER-EXPAND-VERBATIM off=002A25F9 stored=61 head=52656400
//
// is `shaders/cars/dcl/SpecMapGen.dcl` (registered at w677.log:11222).
// `52 65 64 00` is "Red" and is not this member's byte at any offset: the
// packfile's own 61 bytes at 0x002A25F9 begin `31 20 3B 20` ("1 ; "), measured
// against build/game_data/xarchive_cache.rpf. So do the other two verbatim rows
// in that log (0x00297F04 ShaderBlits.dcl, 0x00304ECE rain_system.dcl), which is
// why 2 of the 3 VERBATIM rows carry the right head and this one does not.
//
// `52 65 64 00` is the PREVIOUS ITERATION of ApplyExpandedSpans' own write
// loop, and the same log names it: w677.log:38254 resolved the window's owner
// `off=002A0000 stored=3208 expanded=10732`, and 0x002A25F9 is 0x25F9 = 9721
// bytes into that expansion. Reproduced offline: the packfile's bytes
// [0x2A0000, 0x2A0000+3208) inflate as one raw DEFLATE stream to EXACTLY 10732
// bytes, and their [0x25F9, 0x25F9+4) is `52 65 64 00` -- byte-identical to the
// logged head and different from the packfile's own. The window the read passed
// in had already been overwritten by the preceding span's memcpy, the window
// branch below read its 61 bytes back out of that expansion, and the guest was
// served a neighbouring member's inflated body as SpecMapGen.dcl.
//
// NOTHING could have caught it downstream, which is the point. The window branch
// produced exactly `storedLen` bytes by construction, so the length check in
// ResolveSpan compared 61 against 61 and passed. A length check is blind to this
// class for the same reason F-642 measured it blind to the tail claim: every
// length the host knows is correct and the bytes are still wrong. So the cure is
// the SOURCE, not a guard -- the same cure, on the same mechanism, as F-646's on
// the inflate side, and no check is added anywhere.
//
// `win` keeps exactly one legitimate role in this file and is untouched by that:
// it is the guest-visible window the span machinery WRITES into (the memcpy in
// ApplyExpandedSpans' second pass). It is removed as a byte SOURCE only, and
// removed by DELETING the parameter rather than by ignoring it, so no later
// reader can mistake an unchecked window read for this one.
bool LoadStoredBytes(const std::string& physicalPath, uint64_t off,
                     uint32_t storedLen, std::vector<uint8_t>& out) {
    if (storedLen == 0) return false;
    // F-647: no fallback and no second source. A span with no physical path has
    // no correct source at all -- see the note in ResolveSpan about a
    // SYNTHESIZED image, whose byte at `off` is a different file's byte -- so it
    // fails closed here and the span loses. That is the pre-F-647 outcome for
    // every member whose stored span did not happen to fit inside one window,
    // which is all but the ones this function is now for.
    if (physicalPath.empty()) return false;
    HANDLE h = CreateFileA(physicalPath.c_str(), GENERIC_READ, FILE_SHARE_READ,
                           nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return false;
    out.assign(storedLen, 0);
    OVERLAPPED ov{};
    ov.Offset = static_cast<DWORD>(off);
    ov.OffsetHigh = static_cast<DWORD>(off >> 32);
    DWORD got = 0;
    const bool ok = ::ReadFile(h, out.data(), storedLen, &got, &ov) != FALSE &&
                    got == storedLen;
    CloseHandle(h);
    if (!ok) out.clear();
    return ok;
}

// Expand one span, once. The source bytes are a POSITIONAL READ OF THE PACKFILE
// and nothing else. This is what makes a member larger than any single window
// work at all: the guest reads the inner archive in 32 KiB pieces, and the
// expansion is computed from the STORED bytes once and then spliced into every
// window that overlaps it.
//
// F-646: the source used to be EITHER the read window (when the window happened
// to contain the whole stored span) OR a pread, and the window was tried FIRST.
// That was a wrong source, not a fast one. ApplyExpandedSpans calls this from
// inside its own write loop (the second ResolveSpan call below), so by the time
// pass 2 reaches a span, an earlier iteration's memcpy has already written that
// member's INFLATED body over the victim's stored bytes. Inflating
// `win + (s.off - winOff)` therefore inflated the previous iteration's output:
// each pass inflated the contamination the last one left. RawInflate returns a
// bare bool -- true for ANY byte string that decodes as one complete final
// DEFLATE block -- so the contaminated inflate SUCCEEDED, the `!inflated` gate
// suppressed the clean pread that would have produced the right answer, and the
// corrupt copy won permanently. Reproduced offline against
// build/game_data/xarchive_cache.rpf: 2 clobbered bytes yield a 10,069-byte
// wrong expansion (mc4_rmptfx_projected, 00309000, MEMBER-EXPAND-SIZE expanded=10069).
//
// The packfile's own bytes at (off, stored) inflate to the guest's w1 exactly,
// 15/15 on probed .fxc. That is the source; the window never was.
//
// When there is no physical path there is no correct source -- `win` is then a
// window into a SYNTHESIZED image (GetOrBuildVirtualRpf clears physical_path,
// and the shared-position fallback still calls ApplyExpandedSpans), a different
// file whose byte at `s.off` is not this member's stored byte. Inflating it
// would be a claim with nothing behind it, so this fails closed and the span
// loses. That is the same outcome the pre-F-646 code reached in that case: the
// window branch needed the whole span inside the window, which a packfile offset
// essentially never is against a virtual-image window, so `inflated` was already
// false and MEMBER-EXPAND-FAIL already fired. Removing the window source drops
// a numerically-coincidental read of the wrong file, not a working one.
//
// F-647: the three `win*` parameters are RETAINED AND NO LONGER READ. Both
// branches now take their stored bytes from the packfile by position -- the
// inflate branch above through its own pread, the verbatim branch through
// LoadStoredBytes -- so nothing in this function consults the window any more.
// The parameters stay because ApplyExpandedSpans owns the window and both of its
// calls pass it, and deleting them from a function I am told not to restructure
// would change its two call sites for no gain. `win` is the guest-visible
// DESTINATION here, not a source: the only thing the span machinery does with it
// is write. Reintroducing it as a fallback would be a second short-circuit, and
// the rule that stops it is the one F-642 wrote down: a claim that cannot be
// backed cannot win, so a span that cannot read its own bytes back out of the
// file loses the window rather than taking the window's bytes as its own.
void ResolveSpan(ExpandedSpan& s, const std::string& physicalPath,
                 uint8_t* win, uint64_t winOff, uint64_t winLen) {
    if (s.resolved || s.failed) return;

    const uint32_t want = s.logicalLen != 0 ? s.logicalLen : s.storedLen;
    if (want == 0) {
        s.failed = true;
        return;
    }
    // 64 KiB of headroom for the case where the guest published only a stored
    // length (the 16 legacy registrars) and the real expansion is larger.
    const size_t cap = static_cast<size_t>(want) + 0x10000u;

    if (!s.uncompressed) {
        std::vector<uint8_t> out;
        bool inflated = false;
        // F-646: the packfile's own bytes at (s.off, s.storedLen), and only
        // those. The `win`-sourced inflate that used to be tried first is gone:
        // in pass 2 `win` already holds whatever this function's own write loop
        // put there, so it is not a source of the stored span, it is a record of
        // a previous expansion. See the note above this function.
        if (s.storedLen != 0 && !physicalPath.empty()) {
            // Positional read of the stored span, then inflate. A host read of
            // the packfile, not a guest-visible one -- the guest never sees
            // these bytes, only the expansion they produce.
            std::vector<uint8_t> stored(s.storedLen);
            HANDLE h = CreateFileA(physicalPath.c_str(), GENERIC_READ,
                                   FILE_SHARE_READ, nullptr, OPEN_EXISTING,
                                   FILE_ATTRIBUTE_NORMAL, nullptr);
            if (h != INVALID_HANDLE_VALUE) {
                OVERLAPPED ov{};
                ov.Offset = static_cast<DWORD>(s.off);
                ov.OffsetHigh = static_cast<DWORD>(s.off >> 32);
                DWORD got = 0;
                if (::ReadFile(h, stored.data(), static_cast<DWORD>(stored.size()),
                               &got, &ov) != FALSE &&
                    got == stored.size()) {
                    inflated = mcla::RawInflate(stored.data(), stored.size(), out, cap);
                }
                CloseHandle(h);
            }
        }
        if (!inflated || out.empty()) {
            s.failed = true;
            MCLA_LOG_WARN("MEMBER-EXPAND-FAIL off={:08X} stored={} logical={} "
                          "(not raw DEFLATE; served as stored)",
                          s.off, s.storedLen, want);
            return;
        }
        s.bytes.swap(out);
    }

    // F-632 / W64 (2026-09-30): the VERBATIM class. `storedLen == logicalLen`
    // means the TOC says the member is already on disk in the shape the guest
    // must see, so there is nothing to inflate -- the stored bytes ARE the
    // substitute. This branch did not exist: an `uncompressed` span fell
    // straight through the inflate block with `s.bytes` still EMPTY, so the
    // length check below compared 0 against a non-zero logical length and
    // refused the member with MEMBER-EXPAND-SIZE every time. Every
    // stored-uncompressed member was therefore never served from the archive
    // layer at all (6 of w653's 377 members; 2 of the 234 the w663 census
    // published -- the 61-byte `shaders/*/dcl/*.dcl` bodies, head
    // `31 20 3b 20` = "1 ; "). Harmless only because those members were also
    // readable straight off disk; wrong, because the span claimed the member
    // and then refused it.
    if (s.uncompressed) {
        std::vector<uint8_t> verbatim;
        // F-647: the packfile's own bytes at (s.off, s.storedLen), positionally,
        // and nothing else -- `win` is not a source on this branch either. The
        // window is the DESTINATION of the span machinery and never a source:
        // by the time pass 2 reaches a span, an earlier iteration's memcpy has
        // written that member's body over the victim's bytes, and for a stored-
        // uncompressed member nothing decodes the copy so nothing notices.
        if (!LoadStoredBytes(physicalPath, s.off, s.storedLen, verbatim)) {
            s.failed = true;
            MCLA_LOG_WARN("MEMBER-EXPAND-VERBATIM-READ-FAIL off={:08X} stored={} "
                          "(no positional read of the packfile and no other correct "
                          "source; the span loses rather than serve the window's "
                          "bytes)",
                          s.off, s.storedLen);
            return;
        }
        MCLA_LOG_WARN("MEMBER-EXPAND-VERBATIM off={:08X} stored={} head={:08X} "
                      "(stored == logical: served byte-for-byte, not inflated)",
                      s.off, verbatim.size(), BeHead32(verbatim));
        s.bytes.swap(verbatim);
    }

    // The length check is against what the guest asked to SEE, not against the
    // stored length. The pre-F-628 code compared out.size() to storedLen, which
    // is why every span whose stored and logical lengths differ (all ten
    // entity.type members, all three nested packfiles) was refused outright.
    if (s.logicalLen != 0 && s.bytes.size() != s.logicalLen) {
        s.failed = true;
        MCLA_LOG_WARN("MEMBER-EXPAND-SIZE off={:08X} stored={} expanded={} "
                      "logical={} (guest w1 not reproduced; served as stored)",
                      s.off, s.storedLen, s.bytes.size(), s.logicalLen);
        return;
    }
    if (s.logicalLen == 0) {
        // Legacy registration: the one length the caller published is the
        // length the substitute must produce, so accept an exact match and
        // refuse anything else rather than serving a wrong-length image.
        if (s.bytes.size() != s.storedLen) {
            s.failed = true;
            MCLA_LOG_WARN("MEMBER-EXPAND-SIZE off={:08X} stored={} expanded={} "
                          "(no guest w1; in-place refused)",
                          s.off, s.storedLen, s.bytes.size());
            return;
        }
        s.logicalLen = s.storedLen;
    }
    s.resolved = true;
    // F-642 (2026-09-30). EVERY expansion whose output exceeds its own stored
    // extent, named once per member, with the member and the overrun size.
    //
    // This is the check the class needs and cannot be a length check. A length
    // check is provably blind here: the .dcl's stored length (76), its logical
    // length (79) and the window it was written into (3235) were ALL CORRECT
    // when `20 0d 0a` landed on the .fxc's head. Every length the host knows
    // agreed; the three bytes were simply written at an offset the member does
    // not own. Only a test on the OVERRUN -- the distance between the two lengths
    // and the extent that may be written -- can see the class.
    //
    // The rate is not one member. Over the 8,165 members w673's census
    // published, 399 inflate to more bytes than they store (4.9% of the census,
    // and 87.1% of the 458 that decode as a clean DEFLATE member), overrun
    // median +3,353 bytes, maximum +188,026. So the 3-byte .dcl overrun is the
    // SMALL end of a common condition, and the content the guest has been served
    // has been carrying neighbouring members' inflated tails wherever a member's
    // logical range reached past its stored end into a window the guest was not
    // reading. Bounded: one line per member per boot, not one per window.
    if (!s.overrunNamed && s.bytes.size() > s.storedLen) {
        s.overrunNamed = true;
        MCLA_LOG_WARN("MEMBER-EXPAND-OVERRUN off={:08X} stored={} expanded={} "
                      "overrun={} logical={} packfile='{}' (this member's "
                      "expansion exceeds its own stored extent by {} byte(s): the "
                      "surplus is the member's LOGICAL TAIL, it is not the "
                      "member's byte at any file offset, and it may be written "
                      "into a window only when the member is the window's owner "
                      "-- see MEMBER-SPAN-TAIL-VETO for the windows where that "
                      "was not so)",
                      s.off, s.storedLen, s.bytes.size(),
                      s.bytes.size() - s.storedLen, s.logicalLen, s.packfile,
                      s.bytes.size() - s.storedLen);
    }
    // A span that crosses a 32 KiB read window (the size the guest pages
    // archive reads in, NFS-CENSUS[Read] len=32768) is the case the pre-F-628
    // code refused outright; log it so a soak shows the straddle count
    // separately from the plain whole-window count.
    const uint64_t w0 = s.off & ~static_cast<uint64_t>(0x7FFF);
    const uint64_t w1 = (s.off + s.logicalLen - 1) & ~static_cast<uint64_t>(0x7FFF);
    MCLA_LOG_WARN("MEMBER-EXPAND off={:08X} stored={} expanded={} nl={} "
                  "logical={} straddle32K={}",
                  s.off, s.storedLen, s.bytes.size(), CountNewlines(s.bytes),
                  s.logicalLen, w0 != w1 ? 1 : 0);
}

// Splice every overlapping expanded span into the read window.
//
// F-632 / W64 (2026-09-30). A span describes bytes IN THE FILE, so its extent
// end is `off + storedLen` -- `storedLen` is w3 & 0xFFFFFF, the number of
// bytes the member occupies in the packfile. `logicalLen` is w1, the length the
// GUEST must end up with: it is the SIZE OF THE SUBSTITUTE IMAGE, not the size
// of the region the substitute may write. The pre-W64 code took
//     spanEnd = s.off + (s.logicalLen != 0 ? s.logicalLen : s.storedLen);
// so every member with logical > stored wrote its expanded image
// (logical - stored) bytes past its own last file byte, over whatever members
// follow it. This function iterates the table in REGISTRATION order and a
// LATER registration wins, and the six name-list spans are registered first
// (MclaMarkKnownListMembers, gpu_device.cpp:1806) while the census members that
// clobber them are registered later, so the overshoot always landed on a list.
//
// MEASURED (reproduced offline against build/game_data/xarchive_cache.rpf with
// the 244 spans w663.log's own TOC76 census registers, in registration order):
//   CityWindowDirt.fxc            off 0027D000 stored 8623  logical 24034
//   bumper_subframe_n.dds         off 001DA000 stored 12572 logical 43832
//   Character_plastic_normalmap.fxc off 00303000 stored 7698 logical 24366
// each has a stored end that is EXACTLY a list's offset -- 0027F1AF (cars),
// 001DD11C (ui), 00304E12 (effects) -- and each overshoots it by 15,411 /
// 31,134 / 16,480 bytes. The three lists the game then received began
// 6000134C, AAAAAAAA and 50726F6A where they must begin 57686565 ("Whee"),
// 416C7068 ("Alph") and 2F2F2053 ("// S"), at the right length and with no
// marker saying so. The other three lists were reached by no overshoot at all
// and were already right, which is why the fault looked random.
//
// WHO MAY WRITE. One window, one owner. The window's owner is the member whose
// LOGICAL range covers the window's first byte, innermost wins (largest off),
// and ONLY the owner writes. The other half of the rule is the bound: a span
// that is not the owner may never write past `off + storedLen`, because those
// are not its bytes.
//
//   * Why the owner is allowed its logical range. The caller that reads a member
//     sizes the window from w1 (gpu_device.cpp:2058 `readLen = logicalLen`), so
//     the window holds the member's LOGICAL stream and the owner has to supply
//     all of it. Measured: that is the only way the cars list's 1,108 bytes
//     reach the guest intact -- the list's stored range is 460 bytes, so a
//     bound-at-storedLen substitution would leave 648 bytes of the next
//     member's file data in the body and `LIST-SERVE-VERIFY` would report
//     ok=0 at offset 460.
//   * Why the owner is decided by LOGICAL range and innermost-first. A member
//     larger than one read window arrives in pieces whose heads are inside its
//     own logical range but often past its own stored end -- the three nested
//     packfiles are the load-bearing case (13 / 22 / 9 windows of 32 KiB
//     reassembling 425,984 / 720,896 / 294,912 bytes beginning
//     `RPF3 00 38 00 00`). And where two members' logical ranges cover the
//     same head byte the innermost must win, or the cars-list read at 0027F1AF
//     is CityWindowDirt.fxc's (whose logical range is 0027D000..00282DE2) and
//     the F-632 fault returns one step removed.
//   * Why every other span is refused rather than bounded. The bytes past the
//     owner's stored end are the owner's logical tail, not a neighbour's file
//     data, so there is nothing for a neighbour to write there. Measured: the
//     city, characters and effects list windows each contain the next member's
//     stored range (shaders/city/dcl/CityDefault.dcl at 001F43BF,
//     shaders/characters/dcl/Character.dcl at 002DBA25,
//     shaders/effects/dcl/rain_system.dcl at 00304ECE -- each exactly the
//     list's stored end), and a bounded-but-allowed splice puts a foreign
//     61-109 byte island in the middle of a list body.
//   * Legal straddle vs starting inside a different member. A window that
//     BEGINS INSIDE THE OWNER'S OWN stored range is the continuation read and
//     is served (that is the nested-packfile case). A window that begins inside
//     a DIFFERENT member's stored range than the stream it is part of is two
//     members' on-disk extents overlapping -- 8 such pairs in the w663 census,
//     e.g. raceeditor.xsf [000B001B,003F3030) over globaltex.list
//     [000D0000,000D00EC) -- and it is refused, because the window head decides
//     which member is being read. Logged as MEMBER-SPAN-START-INSIDE.
//   * A window no member's logical range covers is a plain slice of the file.
//     Then each span writes only its own stored bytes and there is no owner.
//   * F-638 (2026-09-30): WHOSE CLAIM IS BELIEVED. Everything above decides
//     ownership from the RECORD -- the offsets and lengths the census published
//     -- and the record is not self-validating. w664 measured six registered
//     members whose `stored` field is not a stored length at all: the UI
//     .xsf/.xtd class, whose bodies are XCompress/LZX containers that the guest
//     decodes itself and that the host has no decoder for. Re-read offline from
//     build/game_data/xarchive_cache.rpf, with the six-list decode as the
//     passing control (each list's 126/452/460/132/188/236 bytes inflate to
//     exactly 260/1246/1108/496/368/575, eof, no unused data):
//
//       off       w3&0xFFFFFF   w1       decode of the bytes at that offset
//       00060009  2,885,648   240,551    not DEFLATE
//       000A001B  5,515,325   196,573    not DEFLATE
//       000A301B  1,910,800    19,357    not DEFLATE
//       000B001B  3,420,181   143,089    not DEFLATE (64..131,072-byte
//                                                 prefixes all fail too)
//       0016F01B    534,547    29,675    not DEFLATE
//       0018001B  7,647,282 1,066,077    not DEFLATE
//
//     The ratio column that used to stand here is GONE, and two earlier readings
//     of it were wrong. `0018001B` was first written as 0.72x (from a TRUNCATED
//     w2, 0x6498001B) and then corrected to 7.17x -- but the ratio is
//     meaningless for this class in the first place, because the column is not a
//     stored size:
//
//     F-641: these offsets are RSC5/XCompress CONTAINERS. Measured offline at
//     0x64CB0000: RSC5=05435352 hdrLen=0000001B pkgID=D4343015 XComp=0FF512EF
//     uncLen=00022EDD(143069). `w3` IS that container's own packageID field at
//     RSC5+0x08 (D4343015 / D574B032 / D41D2810 / D4082813, each matching the
//     `toc=[... ... ... w3]` in w664.log), so `stored = w3 & 0xFFFFFF` is a
//     FRAGMENT OF AN ID. And `w1` is NOT a logical length: it is the container's
//     on-disk extent = the fixed 20-byte five-word header plus the reserved
//     payload. The independent witness is the packfile's zero padding, which for
//     all four starts at container+w1 (zero runs of 20,751 / 15,267 / 1,123 /
//     3,093 bytes -- each exactly the distance to the next RSC5 head). The
//     container's own declared length uncLen=143069 is what the goldens decode
//     to (build/xmem_golden/raceeditor.bin = 143,069), so w1 exceeds it by 20.
//
//     CONSEQUENCE: the F-632 three-field discipline does NOT apply uniformly.
//     For the six DEFLATE lists it does. For this container class `w3` is an id
//     and `w1` is an extent, so a span built from them is fiction -- which is
//     what the table above is actually evidence of, and why no ratio could ever
//     have separated the good rows from the bad ones. The container's own
//     declared length (MclaRsc5DeclaredSize) is the authority for this class;
//     see gpu_device.cpp's SERVE-PROOF, which accepts a member only when an
//     actual decode reproduces the length the container declares for itself.
//
//     so their claimed on-disk extents are fiction -- between them they cover
//     24 MB of the packfile and swallow 54 other members' stored extents, which
//     is what MEMBER-SPAN-OVERLAP reported 48 times in w664. Under the W64 rule
//     above, `raceeditor.xsf` -- whose LOGICAL range is only 143 KB -- wins the
//     window at globaltex.list's offset, produces nothing for it, and in doing
//     so refuses every other span that could have (w664: six
//     MEMBER-SPAN-OWNER-UNRESOLVED rows, `refused=1`..`3`). A member must not be
//     able to claim a window it cannot produce bytes for, so ownership is now
//     decided only among spans that HAVE produced their own logical length, and
//     a claim that cannot be backed is named (MEMBER-SPAN-OWNER-BARRED) and
//     dropped, after which the window falls through to the no-owner path: each
//     span that did reproduce writes only its own stored bytes. That is exactly
//     the pre-regression behaviour for this class, because the host cannot
//     produce these bodies at all and the guest's own XCompress decoder must.
//
//     The corroboration test is the DECODE, not a length ratio, and it has to
//     be: `garage.xsf` stores LESS than its logical length (0.72x) and is exactly
//     as uncorroborated as the other five. No constant separates them.
//
//     MEASURED effect of the gate, offline, over the 22 spans w664's census
//     registered: it changes the owner of 425 modelled 32 KiB windows, every one
//     of which was owned by one of the six uncorroborated members and every one
//     of which now falls through to the no-owner path. It changes NOTHING at any
//     window a corroborated member's own bytes are at stake: all six preload
//     lists keep their own stored bytes under both rules, at their first
//     window, at their midpoint and at their last stored byte (0 of 18 windows
//     differ), and the three legitimate clobberers still cannot reach any list --
//     each one's stored end is EXACTLY a list's offset (0x0027F1AF, 0x001DD11C,
//     0x00304E12), so their extents are half-open against it.
// F-645: `readMemberOff` is the data offset of the member the caller is reading
// (OpenFileHandle::read_member_off), or 0 when the caller did not say. It is
// passed to ClassifyTailClaim ONLY, and only as the kReadMemberHead fact; it
// never enters the election, the owner test or the write limit below, so a caller
// that sets it cannot otherwise change this function's behaviour.
// F-721 (2026-10-04). THE ALIAS-OWNER TEST, IN ONE PLACE.
//
// "Is this member publishing an ADDRESS SPACE rather than a payload?" is decided
// by the first four bytes of the member's OWN expanded image: a nested RPF3
// archive, not a file body. Measured from the archive, not from a log field --
// all 163 spans the last boot registered were inflated out of
// build/game_data/xarchive_cache.rpf and exactly THREE of them begin `RPF3`:
//   00368000 preload/xarchive_bootscripts.rpf  stored 532870 -> 720896
//   003F0000 preload/xarchive_cameratune.rpf   stored 328655 -> 425984
//   00448000 preload/xarchive_carconfigs.rpf   stored 166323 -> 294912
// F-720's alias marker reports its `ownerImageIsArchive` field from this same
// expression; the value was hoisted here so the gate below and that marker can
// never drift apart. NOT a new field and NOT a new predicate: `ExpandedSpan::
// bytes` (src/fs/vfs_rpf.h:173) already carries the expanded image, and
// ResolveSpan has already filled it for any span that reached the election.
bool SpanImageIsRpf3(const ExpandedSpan& s) {
    return s.bytes.size() >= 4 && s.bytes[0] == 'R' && s.bytes[1] == 'P' &&
           s.bytes[2] == 'F' && s.bytes[3] == '3';
}

void ApplyExpandedSpans(const std::string& physical_path, uint8_t* win,
                        uint64_t winOff, uint64_t winLen,
                        uint64_t readMemberOff) {
    if (win == nullptr || winLen == 0 || g_expSpans.empty()) return;
    const std::string packKey = PackKeyOf(physical_path);
    const uint64_t winEnd = winOff + winLen;
    std::lock_guard<std::mutex> lk(g_expMtx);

    // Pass 1: the window's OWNER, i.e. the member whose LOGICAL stream this
    // window is part of. A read is addressed in the member's own logical
    // coordinates, so ownership is decided by the LOGICAL range, and where two
    // members' logical ranges cover the same head byte the INNERMOST one wins
    // (largest off). Both halves of that rule are load-bearing and both are
    // measured:
    //   * largest off, so the cars-list read at 0027F1AF is the cars list's and
    //     not CityWindowDirt.fxc's, whose logical range (0027D000..00282DE2)
    //     also covers that byte;
    //   * logical and not stored, because a member read arrives in 32 KiB
    //     pieces and the pieces past the member's STORED end are still its
    //     stream: xarchive_soundbank.rpf is 294,912 logical over 165,811
    //     stored, so its 9th window starts at 00488000, 26,493 bytes beyond
    //     004709B3. A stored-range test finds no owner there and the window
    //     would be served as raw file bytes -- measured, that is how the
    //     reassembly of all three nested packfiles breaks.
    const ExpandedSpan* owner = nullptr;
    const ExpandedSpan* headStored = nullptr;
    // F-642: the elected owner, IF its claim on this window's head byte is a
    // claim on bytes that are not its own. Decided after the election.
    //
    // F-721 CORRECTION (2026-10-04): this block used to add "so the election
    // itself, and therefore every window whose owner has a valid claim, is
    // bit-for-bit the pre-F-642 behaviour". That sentence is FALSE as of F-721
    // and is withdrawn here rather than left above live code. The veto is still
    // decided after the election, and for every window the election did not
    // change the two are still identical -- but the F-721 gate below runs
    // BETWEEN the election and this veto, so on the 4 windows it names the owner
    // this veto is handed is not the pass-1 owner.
    const ExpandedSpan* tailVeto = nullptr;
    TailClaim vetoClaim = TailClaim::kInStoredRange;
    // F-638: the member that CLAIMS this window (innermost by logical range)
    // but cannot produce a byte for it. See the F-638 block below.
    ExpandedSpan* barred = nullptr;
    for (auto& s : g_expSpans) {
        if (s.failed || !SpanMatchesPack(s, packKey)) continue;
        const uint64_t logicalEnd =
            s.off + (s.logicalLen != 0 ? s.logicalLen : s.storedLen);
        if (s.off <= winOff && winOff < logicalEnd) {
            // F-638: a candidate owner is only a candidate once it has been
            // shown it can produce the window's bytes. ResolveSpan is memoised
            // (`resolved`/`failed` short-circuit its first line), so this is a
            // one-off decode per span, not a per-window cost, and it is the very
            // decode pass 2 was already doing for the same span.
            ResolveSpan(s, physical_path, win, winOff, winLen);
            if (!s.resolved) {
                // It claimed the window and could not fill it. Keep scanning: a
                // smaller-offset member that CAN fill it is the honest owner.
                // Do NOT skip the stored-range test below -- a fabricated extent
                // that covers the head byte is precisely the conflict
                // MEMBER-SPAN-START-INSIDE exists to count, and a `continue`
                // here would hide it behind the very member that is barred.
                if (barred == nullptr || s.off > barred->off) barred = &s;
            } else if (owner == nullptr || s.off > owner->off) {
                owner = &s;
            }
        }
        if (s.off < winOff && winOff < s.off + s.storedLen) {
            if (headStored == nullptr || s.off > headStored->off) headStored = &s;
        }
    }

    // F-721 (2026-10-04). THE UN-ALIAS. THE ELECTION IS NOT BIT-FOR-BIT THE
    // PRE-F-642 BEHAVIOUR ANY MORE, AND THE COMMENT ABOVE IT (which claimed
    // otherwise) HAS BEEN CORRECTED IN PLACE.
    //
    // THE PREDICATE, IN ONE SENTENCE: when the member this window's pass-1
    // election elected is publishing a nested-archive image rather than a
    // payload -- SpanImageIsRpf3(owner), i.e. its expanded bytes begin `RPF3` --
    // re-run the election over a candidate set that additionally admits any
    // registered member whose DATA OFFSET falls strictly inside this window
    // (`winOff < s.off < winEnd`), under the same corroborated-span gate and the
    // same largest-offset-wins rule; otherwise the pass-1 result stands exactly
    // as it was, including when no member owned the window at all.
    //
    // WHY ONLY AN ARCHIVE IMAGE YIELDS. A member whose expanded body is a nested
    // RPF3 archive is not a file: it is a whole ADDRESS SPACE the console would
    // have mounted and paged, published here as a flat image over
    // [off, off+logical). Every other member's expanded body is that member's
    // own file content, so its logical tail IS the continuation of its own
    // stream and the pre-F-642 election is right to prefer it. That is not a
    // judgement about which stream the guest wanted -- see the F-745 note below.
    //
    // IT DOES NOT WEAKEN ANY REFUSAL. The F-638 barred path, the stored-range
    // test immediately above it, and the head-stored-owner marker at the end of
    // this function are all computed by the pass above, which this does not
    // touch; the write loop, `refused`, `firstRefused` and every refusal row are
    // untouched. What changes is only WHICH member is `owner`, and the refused
    // set is recomputed from the table as before -- so a demoted owner becomes a
    // REFUSED span, counted, not a silent one.
    //
    // WHAT IT COSTS, MEASURED (replay3.py, build/w719.log, 143 windows, the span
    // table read out of the log's own rows and inflated from the archive):
    //   4 of 143 windows change, 958,551 bytes.
    //     [00380000,00400000) 00368000 -> 003F0000   524,288 B
    //     [00400000,00480000) 003F0000 -> 00479000   368,727 B
    //     [00470000,00478000) 00448000 -> 00471000    32,768 B
    //     [00478000,00480000) 00448000 -> 00479000    32,768 B
    // An earlier offline replay reported "2 windows". That number was wrong
    // twice over and the two errors cancelled: the replay's `cur() is None`
    // branch added two windows its own header excluded, and its owner set was
    // read from the LOG's alias rows rather than from the archive, which named
    // only 00448000 and so missed bootscripts and cameratune. Both are
    // corrected above.
    //
    // F-745's "this is a representational impossibility, not a rule-selection
    // problem" is NOT refuted and NOT relied on here. That claim is about two
    // streams both claiming one flat window; this rule does not make both fit,
    // it makes the window the address the file has already assigned, and which
    // of the two the guest wanted there is NOT DETERMINABLE FROM THE BYTES.
    // NO LEDGER ID IS CLAIMED BY THIS BLOCK. The ledger's last `### F-` heading
    // measured at authoring time is F-764 and this text is not in it; whoever
    // owns the ledger assigns the number.
    //
    // THE FLAP, MEASURED ON build/w720.log (51,079 lines). ONE window address is
    // read FOUR times inside 130 ms while the guest is inside ONE tokenizer:
    // branch-read rows at log lines 24080 / 24237 / 24959 / 24985, i.e. 23:51:23
    // .327 / .377 / .447 / .449, and the last two are one .xcc registration
    // later than the one before. The owner elected for that single address ran
    // 00448000 -> 00471000 -> 00476615 -> 0047682B, and the bytes delivered at
    // window+0x1000 -- the first byte of tune/vehicle/vehicle.lst, whose own
    // expansion begins 4D616E75, "Manu" -- ran 3BB32E9C, 4D616E75, E59CDD52,
    // E59CDD52. Seven milliseconds after the last of those the guest raised
    // 'Unexpected EOF in fiBaseTokenizer::Pop' (log line 25005); its
    // r4=0x82862DF0 is the struct whose own stream row at log line 24232 named
    // 'Manufacturer'. Nothing here claims the parser died ON that byte: what is
    // measured is that the byte at that address changed three times inside the
    // parse and that the fatal follows it.
    //
    // THE PREDICATE THAT ADMITS EACH SUCCESSIVE OWNER. `startsInside` on the
    // line below -- `winOff < s.off && s.off < winEnd` -- reached only because
    // the pass-1 owner here is a nested RPF3 image, together with
    // `s.off > unaliased->off`, largest data offset wins, on the loop's last
    // line. 35 registered members hold a data offset strictly inside that one
    // window; 34 are .xcc, and every .xcc that arrives takes the address away
    // from whoever held it. The damage is exact and is not a length question: a
    // non-owner is REFUSED and writes nothing at all (:1825-1829), so the
    // moment an .xcc owns the window, vehicle.lst's own region is no longer
    // written by anything and falls back to the packfile's stored bytes, which
    // at 00471000 are E59CDD52 -- vehicle.lst's own DEFLATE, not its body.
    //
    // THE RULE. Among the candidates that BEGIN inside this window, the one with
    // the LOWEST data offset is the owner. Not the highest. A window is being
    // read for one member, and the file assigns addresses in increasing offset
    // order, so the member that begins first inside the window is the one whose
    // stream the window is a slice of; anything that arrives later sits above it
    // and therefore cannot take the address from it. That makes the owner a
    // function of the window address and of nothing that arrives afterwards,
    // which is the whole of the repair: the old tiebreak was a function of
    // REGISTRATION TIMING and the guest's read lands at a timing-dependent
    // moment.
    //
    // coversHead-only candidates are ranked exactly as they were -- largest
    // offset first -- so a window no member begins inside is bit-for-bit the
    // F-721 behaviour. Only the startsInside set is re-ordered, and only among
    // itself; when no candidate begins inside the window, `unaliased` stands.
    //
    // MEASURED FOOTPRINT. Replaying all 108 distinct windows and all 218 owner
    // rows of build/w720.log, with the span table read out of that log's own
    // registration rows and every expansion produced by a raw inflate of bytes
    // read straight out of build/game_data/xarchive_cache.rpf:
    //   * 1 of 108 windows changes its served bytes: [00470000,00478000),
    //     27,499 bytes of that one 32,768-byte window;
    //   * 2 of 218 owner rows change, both of them on that window;
    //   * 2 of the boot's 29 byte flips between consecutive reads of ONE address
    //     are eliminated; the other 27 are untouched and the other 107 windows
    //     serve byte-identical bytes under both rules;
    //   * the window's REMAINING first change, 00448000 -> 00471000, is not a
    //     flap and this rule deliberately leaves it: that read happened at
    //     23:51:23.327, before vehicle.lst had been registered at all, so the
    //     owner it elected was the only member that existed to elect.
    // The replay is CHECKED rather than assumed: it predicts all 218 owner rows
    // of w720.log exactly, and its window byte 0 reproduces the log's own head16
    // field on every one of those rows (3BB32E9C... under carconfigs,
    // F9DBB9A7... under vehicle.lst and under both .xcc owners).
    //
    // WHAT THIS DOES NOT FIX, NAMED SO NOBODY RE-PURPOSES THIS BLOCK. 27 of the
    // 29 boot-wide flips survive. They are a different shape: each is a nested
    // RPF3 archive taking over a window as the guest mounts it -- 00368000
    // bootscripts, 003F0000 cameratune, 00448000 carconfigs are the three
    // members measured to expand to an image beginning 'RPF3' -- and in those
    // the arriving member is the one the guest is reading. Separating that from
    // a member that arrives and steals an address it is not being read for needs
    // the identity of the member the CALLER wants, and that is not reachable
    // from this file. readMemberOff is 0 on every call that reaches here,
    // because both of its assignment sites (src/gpu_device.cpp:2945-2946 and
    // :22762-22763, each setting raw_positional on the immediately preceding
    // line) sit on the handle branch that returns at :2600 before the span table
    // runs, and this file's two call sites (:2593, :2637) are both under
    // `if (!file.raw_positional)`. THE RULE TO HAND OVER IS THAT ONE, and it
    // needs a second file.
    const bool unAliasGate = (owner != nullptr && SpanImageIsRpf3(*owner));
    // F-753 (2026-10-05). THE OWNERLESS WINDOW, and it is the live boot blocker.
    //
    // WHAT WAS MEASURED, from build/w722.log's own bytes, not from a document.
    // The tokenizer's buffer is 0x82862DF8 (the stream wrapper's +8; F456-STREAMID
    // names it as `base=`), the member is tune/vehicle/vehicle0002.lst at
    // off=0x7EF65487 with stored=494 and logical=2839 (TOC76-XSF #769
    // `[3CB91343 00000B17 7EF65487 400001EE]`, w1 = 0x0B17 = 2839), and the guest
    // read that window as NFS-CENSUS[Read] #0225 len=32768 off=0x7ef60000 -- a
    // window whose HEAD, 0x7EF60000, is 0x5487 bytes BELOW the member.
    //
    // At the fatal (`Unexpected EOF in fiBaseTokenizer::Pop`, w722.log:25658) the
    // host's own `fatal aux r4` dump of that buffer (imports.cpp:6351) is
    // byte-for-byte:
    //   * the first 494 bytes == inflate(xarchive_cache.rpf[0x7EF65487:+494]),
    //     the whole ORACLE, exactly 494 == the member's STORED length;
    //   * followed by 224 further bytes identical to
    //     xarchive_cache.rpf[0x7EF65675:], i.e. the packfile's OWN bytes, which
    //     then diverge only because the dump is a printf('%s') that ran on into
    //     whatever follows in guest memory.
    // So the buffer held 494 bytes of the member and 3602 bytes of something
    // else. 494 is precisely `storedEnd - off`, which is the limit this function
    // hands a span that is NOT the window's owner (:1838-1841).
    //
    // WHY THERE IS NO OWNER, and that is the defect and not the missing tail
    // grant. The pass-1 election above elects by LOGICAL range
    // (`s.off <= winOff && winOff < logicalEnd`, :1458): this member's logical
    // range is [0x7EF65487, 0x7EF65F9E), which does not contain the window head
    // 0x7EF60000, so it is not a candidate, and with 226 members registered in
    // w722.log no other member's logical range contains that head either -- the
    // window has NO owner at all. The un-alias above is gated on
    // `owner != nullptr && SpanImageIsRpf3(*owner)`, so with a null owner it never
    // runs and the member that BEGINS inside this window is never elected. The
    // F-642 veto and the W64 write limit then do exactly what they are written to
    // do: a non-owner writes only its own stored extent.
    //
    // This contradicts this file's OWN stated contract, quoted from the marker it
    // already prints (:1217-1227): the surplus of an expansion is "the member's
    // LOGICAL TAIL ... and it may be written into a window ONLY WHEN THE MEMBER
    // IS THE WINDOW'S OWNER". The member here IS the one being read -- its open is
    // what caused the read two log lines earlier -- and the election simply could
    // not name it. So this is the contract being applied to the wrong owner, and
    // the fix is to elect the member the window is a slice of, which is the rule
    // the block above already states and already applies to the RPF3 case.
    //
    // WHY IT NEEDS A GUARD AND WHAT IT COSTS, MEASURED OVER EVERY GUEST READ IN
    // w722.log (228 reads, span table rebuilt in log order, every expansion a
    // python `zlib` inflate of the archive's own bytes, every window baseline the
    // packfile's own bytes -- no vfs_rpf.cpp code on either side):
    //   * the UNGUARDED extension changes 15 reads, 7 of which write the tail over
    //     another registered member's stored range (41,954 bytes). That is the
    //     shape F-693 was reverted for, so the unguarded form is NOT shipped.
    //   * the GUARDED form below grants an owner on 7 of the 228 reads, 12,411
    //     bytes total, and on all 7 every changed byte lies inside the granted
    //     member's OWN [off, off+logical) extent -- 0 bytes outside, 0 windows
    //     that already had an owner, 0 previously-owned windows changed.
    //   * the guard refuses 5 windows the unguarded form would have damaged.
    //   * the same replay reproduces 219 of the log's 222 owner rows; the two
    //     sheared variants of the rule it is checked against score 217 and 0, so
    //     the replay can fail.
    //
    // WHAT IT DOES NOT DO. It does not invent a length: the bytes written are the
    // member's own expansion, ResolveSpan's product, and the extent they may
    // occupy is w1, the length the TOC publishes. It does not touch
    // ApplyExpandedSpans' other three refusals, the pass-1 election, the F-642
    // veto, the write loop's arithmetic, `refused`/`firstRefused`, or any existing
    // marker's format.
    const ExpandedSpan* ownerlessGrant = nullptr;
    if (owner == nullptr) {
        const ExpandedSpan* firstStart = nullptr;
        for (auto& s : g_expSpans) {
            if (s.failed || !SpanMatchesPack(s, packKey)) continue;
            if (!(winOff < s.off && s.off < winEnd)) continue;
            ResolveSpan(s, physical_path, win, winOff, winLen);
            if (!s.resolved) continue;
            if (firstStart == nullptr || s.off < firstStart->off) firstStart = &s;
        }
        if (firstStart != nullptr) {
            // THE GUARD. The grant raises this member's write limit from
            // off+stored to off+logical, so the tail may only be granted while no
            // other registered member's on-disk extent lies inside it. This is
            // the one predicate that separates the vehicle-list window from the
            // five the unguarded form would have damaged. It reads the same table
            // the owner election reads and needs no resolution of its own.
            const uint64_t tailLo = firstStart->off + firstStart->storedLen;
            const uint64_t tailHi =
                firstStart->off +
                (firstStart->logicalLen != 0 ? firstStart->logicalLen
                                             : firstStart->storedLen);
            bool tailClear = true;
            for (auto& s : g_expSpans) {
                if (&s == firstStart) continue;
                if (!SpanMatchesPack(s, packKey)) continue;
                // Deliberately NOT gated on `s.resolved`, and deliberately does
                // not call ResolveSpan: this test is about the ADDRESS RANGE the
                // file has already handed a member, which is a fact about the
                // table and not about whether that member decodes. Resolving here
                // would also publish MEMBER-EXPAND rows for members this window
                // would otherwise never touch, i.e. change a census for no gain.
                // Refusing on an uncorroborated neighbour is the conservative
                // direction: it can only withhold a grant.
                if (s.off < tailHi && tailLo < s.off + s.storedLen) {
                    tailClear = false;
                    break;
                }
            }
            if (tailClear) ownerlessGrant = firstStart;
        }
    }
    if (unAliasGate) {
        const ExpandedSpan* unaliased = nullptr;
        const ExpandedSpan* firstStart = nullptr;
        for (auto& s : g_expSpans) {
            if (s.failed || !SpanMatchesPack(s, packKey)) continue;
            const uint64_t logicalEnd =
                s.off + (s.logicalLen != 0 ? s.logicalLen : s.storedLen);
            const bool coversHead = (s.off <= winOff && winOff < logicalEnd);
            const bool startsInside = (winOff < s.off && s.off < winEnd);
            if (!coversHead && !startsInside) continue;
            ResolveSpan(s, physical_path, win, winOff, winLen);
            if (!s.resolved) continue;
            if (startsInside &&
                (firstStart == nullptr || s.off < firstStart->off))
                firstStart = &s;
            if (unaliased == nullptr || s.off > unaliased->off) unaliased = &s;
        }
        owner = (firstStart != nullptr) ? firstStart : unaliased;
    } else if (ownerlessGrant != nullptr) {
        // The ownerless path does NOT re-run the election: `ownerlessGrant` was
        // chosen by the same lowest-offset-wins rule over the same
        // startsInside set, and re-running it here would be able to replace the
        // guarded candidate with the unguarded `unaliased` one.
        owner = ownerlessGrant;
        MCLA_LOG_WARN(
            "SPAN-OWNERLESS-GRANT off={:08X} stored={} logical={} "
            "window=[{:08X},{:08X}) tailFrom={:08X} (this window's head is "
            "covered by NO registered member, and this member BEGINS inside "
            "it, so the pass-1 election could not name it and it would "
            "otherwise be served as its own stored extent alone -- "
            "src/fs/vfs_rpf.cpp ApplyExpandedSpans; the tail is granted only "
            "because no other registered member's stored range lies inside "
            "[off+stored, off+logical))",
            owner->off, owner->storedLen, owner->logicalLen, winOff, winEnd,
            owner->off + owner->storedLen);
    }

    // F-642: apply the veto. A tail claim that names another member's byte is
    // not a claim, so the owner is DEMOTED rather than bounded: demotion lands
    // in the F-638 no-owner path this file already has and has already
    // measured, where every span writes only its own stored bytes and a window
    // no member owns is served exactly as the file supplied it. For the
    // ScreenTint window that is the whole repair -- the .dcl's stored extent
    // ends at the window head, so it writes nothing at all and the window keeps
    // the packfile's own bytes, which are the .fxc's.
    if (owner != nullptr) {
        vetoClaim = ClassifyTailClaim(g_expSpans, *owner, winOff, packKey,
                                      readMemberOff);
        if (vetoClaim == TailClaim::kBoundaryByte ||
            vetoClaim == TailClaim::kNeighbour ||
            vetoClaim == TailClaim::kReadMemberHead) {
            tailVeto = owner;
            owner = nullptr;
        }
    }
    if (tailVeto != nullptr) {
        const uint32_t overrun = tailVeto->bytes.size() > tailVeto->storedLen
                                     ? static_cast<uint32_t>(tailVeto->bytes.size() -
                                                             tailVeto->storedLen)
                                     : 0u;
        const bool boundary = (vetoClaim == TailClaim::kBoundaryByte);
        const bool readHead = (vetoClaim == TailClaim::kReadMemberHead);
        MCLA_LOG_WARN("MEMBER-SPAN-TAIL-VETO off={:08X} stored={} logical={} "
                      "expanded={} overrun={} window=[{:08X},{:08X}) headBeyond="
                      "StoredEnd={} claim={} readMemberOff={:08X} (this member's "
                      "LOGICAL TAIL reached past its own last file byte into a "
                      "window the guest was reading for a different member: {} "
                      "-- the window is served from the file unchanged and no span "
                      "writes into it)",
                      tailVeto->off, tailVeto->storedLen, tailVeto->logicalLen,
                      tailVeto->bytes.size(), overrun, winOff, winEnd,
                      winOff - (tailVeto->off + tailVeto->storedLen),
                      boundary ? "boundary-byte"
                               : (readHead ? "read-member-head"
                                           : "neighbour-stored-range"),
                      readMemberOff,
                      boundary
                          ? "the head IS this member's stored-end boundary byte, "
                            "so it belongs to whatever the packer placed next"
                          : (readHead
                                 ? "the head is the FIRST BYTE of the member the "
                                   "caller is reading (this one is not yet "
                                   "registered -- MarkMemberExpandedIn is step 6 "
                                   "and this read is step 2), so a tail that "
                                   "reaches it is writing into another member's "
                                   "window and not into its own stream"
                                 : "a resolved neighbour's stored range covers "
                                   "the head"));
    }

    // F-720 (2026-10-01). THE ALIASING, NAMED. THIS CHANGES NO BYTE.
    //
    // MEASURED ROOT CAUSE of the boot's blocking fault (w689.log, six soaks
    // w684..w689 identical): `Fatal error dispatcher` /
    // `FATAL-SOFT: 'Unknown manufacturer %s in vehicle list file'` /
    // `fatal %%s arg: 'chevy'` at lr=0x823966E8. The guest's parse window never
    // receives tune/vehicle/vehicle.lst's body.
    //
    // The shape, every number below re-measured from
    // build/game_data/xarchive_cache.rpf (2,130,739,200 B == TOCWALK-SUMMARY's
    // packSz, the same file obj=B7311700 walks) and build/toc_leaves.csv
    // (22,068 rows):
    //
    //   preload/xarchive_carconfigs.rpf  off=0x448000 stored=166323 logical=294912
    //     inflate(stored) -> EXACTLY 294912 bytes, magic `RPF3` -- a real nested
    //     archive, not a payload. Its STORED extent ends at 0x4709B3, so the
    //     294,912-byte image is published over [0x448000,0x490000) = 128,589
    //     bytes PAST its own last on-disk byte.
    //   80 real outer members START inside that overflow and ALL 80 corroborate
    //     (raw DEFLATE at their own offset -> their own declared logical
    //     length, 80/80). tune/vehicle/vehicle.lst is at 0x471000 (2355 stored
    //     -> 22391, inflate head `Manufacturer\r\n{\r\n\tName\t\t`), and
    //     vehicle0001.lst at 0x479000.
    //   At 0x471000 the two disagree BYTE FOR BYTE: the file holds
    //     E59CDD52A44A12C7 (vehicle.lst's own DEFLATE), the published image
    //     holds 3BB32E9C8181FF86F05924B0052806A2.
    //
    // So this is ADDRESS ALIASING, not a tail-cap problem: two different real
    // byte streams are both addressed at 0x471000, and the file has already
    // assigned that address to vehicle.lst.
    //
    // WHY THIS IS A MARKER AND NOT A FIX. Every byte-moving rule was measured
    // against all 223 MEMBER-SPAN-OWNER windows of w689.log, replayed byte for
    // byte with the span table in registration order:
    //
    //   rule                                            windows   bytes
    //   byte-wise innermost (largest off, per BYTE)          41  1,536,628
    //   + victim.off >= owner storedEnd AND corroborated     41  1,695,413
    //   split only when the HEAD is in the owner's stored    39  1,515,050
    //   F-693's tail cap (MEASURED, REVERTED)                20    976,968
    //
    // All three are LARGER than the cap that was already implemented, measured
    // and reverted the same day, and none of them is separable from the other
    // two shapes -- 288 of 289 distinct victims corroborate, so corroboration
    // does not discriminate (build/census, 2026-10-01). Shipping any of them
    // blind on a 43-way-dirty tree with no soak available is how F-693 died.
    //
    // DIRECTION (a) IS STRUCTURALLY IMPOSSIBLE, measured, not assumed.
    // ClassifyTailClaim's kReadMemberHead (vfs_rpf.cpp:1760) requires
    // `head == readMemberOff`, where `head` is the WINDOW head. The guest's
    // reads in this extent are 0x470000 and 0x478000 (4 rows, READAT-BRANCH
    // #993/#994/#998/#999, all req=32768 raw_positional=0 span_ran=1
    // handle_nested=0) and vehicle.lst's off is 0x471000: the head sits 0x1000
    // BELOW the member, so `head == readMemberOff` is false on every one of the
    // 13 reads inside the published extent. 0 of 13 could fire it, even with
    // read_member_off threaded perfectly. (It is 0 today anyway: both
    // assignment sites, src/gpu_device.cpp:2841-2842 and :22096-22097, set
    // `raw_positional = true` on the preceding line, and ReadFileAt calls
    // ApplyExpandedSpans only under `if (!file.raw_positional)` -- so the
    // member identity is not merely unset, it is unreachable from every read
    // that runs this function. Threading it needs a second file.)
    //
    // NESTED-RPF ROUTE: measured DEAD for this member. NESTED-RPF-MOUNT = 0 and
    // NESTED-RPF-REGISTER = 0 in w689, and handle_nested=0 on all 13 reads, so
    // carconfigs is served through the OUTER packfile handle and the span table
    // IS on the read path (span_ran=1). The collision is therefore REACHABLE,
    // and the correct action is not "none".
    //
    // WHAT THIS MARKER IS FOR. It changes no byte and alters no control flow, so
    // every existing baseline is bit-for-bit preserved. It makes the aliasing
    // countable per (owner, victim) pair instead of inferable only from a
    // `refused=` count, so the next soak can be checked against a named row.
    //
    // REMOVAL TRIGGER: delete this block and the file-local g_aliasNamed
    // together once a rule that resolves the aliasing is landed and soaked.
    // It must not outlive that.
    if (owner != nullptr) {
        const uint64_t ownerEnd = owner->off +
                                 (owner->logicalLen != 0 ? owner->logicalLen
                                                         : owner->storedLen);
        for (auto& v : g_expSpans) {
            if (&v == owner || v.failed || v.off == owner->off) continue;
            if (!SpanMatchesPack(v, packKey)) continue;
            // A victim is a member whose DATA OFFSET the owner has painted over
            // with a decompressed image. Half-open on both ends.
            if (v.off < owner->off || v.off >= ownerEnd) continue;
            // ResolveSpan is `void` and reports through the span's own
            // `resolved`/`failed` flags (src/fs/vfs_rpf.cpp:1083), exactly as
            // the election loop uses it. It is memoised, so naming a victim
            // costs at most one decode per span per boot.
            ResolveSpan(v, physical_path, win, winOff, winLen);
            if (!v.resolved) continue;
            if (v.off >= winEnd) continue;
            const uint64_t key =
                (owner->off << 32) | (v.off & 0xFFFFFFFFull);
            if (std::find(g_aliasNamed.begin(), g_aliasNamed.end(), key) !=
                g_aliasNamed.end())
                continue;
            g_aliasNamed.push_back(key);
            // `ownerImageIsArchive` is read off the owner's OWN inflated bytes,
            // not asserted: 3 of 177 registered spans begin `RPF3` (bootscripts
            // 0x368000, cameratune 0x3F0000, carconfigs 0x448000), and those
            // are the members whose published extent is a whole address space
            // rather than a payload.
            const bool archive = SpanImageIsRpf3(*owner);
            MCLA_LOG_WARN(
                "MEMBER-SPAN-ALIAS owner={:08X} stored={} logical={} "
                "publishedEnd={:08X} victim={:08X} victimStored={} "
                "victimLogical={} window=[{:08X},{:08X}) "
                "ownerImageIsArchive={} (a DIFFERENT member's data offset "
                "falls inside this member's PUBLISHED logical extent, so the "
                "decompressed image is being served at an address the file has "
                "already assigned to that other member; the victim "
                "corroborated, its own stored bytes produce its own declared "
                "logical length, and the two disagree byte for byte at that "
                "address -- NAMED, NOT RESOLVED: no byte is changed here)",
                owner->off, owner->storedLen, owner->logicalLen, ownerEnd,
                v.off, v.storedLen, v.logicalLen, winOff, winEnd,
                archive ? 1 : 0);
        }
    }

    uint32_t refused = 0;
    uint64_t firstRefused = 0;
    uint32_t written = 0;
    // F-693 (2026-10-01): the owner's limit as the loop finally computes it,
    // reported as `tail=` on the MEMBER-SPAN-OWNER row. The tail cap that used
    // to lower this limit has been REVERTED (the record is at the assignment
    // below), so `tail` is the owner's own off+logical BY CONSTRUCTION now.
    // That is why the field is kept: a soak can assert `tail` == off+logical on
    // every MEMBER-SPAN-OWNER row, and any row where it does not is a cap that
    // came back.
    uint64_t ownerTailLimit = 0;
    for (auto& s : g_expSpans) {
        if (s.failed || !SpanMatchesPack(s, packKey)) continue;
        const bool isOwner = (&s == owner);
        // THE W64 RULE, and F-642's amendment to it. A span's ON-DISK extent
        // ends at `off + storedLen`. Only the window's owner may write past its
        // own stored bytes, because only the owner is being read: the caller
        // sized the window from w1 (gpu_device.cpp:2058 `readLen = logicalLen`),
        // so those bytes are the owner's logical tail. Every other span is
        // confined to the file bytes it actually occupies, and to the window's
        // own stream it is not allowed to write at all.
        //
        // F-642 (2026-09-30): the `isOwner` grant is now CONDITIONAL, and the
        // condition is applied above -- ClassifyTailClaim decides whether the
        // elected owner's claim on this window's HEAD is a claim on its own
        // bytes at all, and MEMBER-SPAN-TAIL-VETO demotes the owner to
        // no-owner when it is not. So `isOwner` below means "owner whose claim
        // on this window's head survived F-642", which is strictly narrower
        // than the raw W64 election. `owner == nullptr` is the demoted case and
        // takes the same path as any other window no member owns: every span
        // writes only its own stored bytes, and a window nothing owns is served
        // exactly as the file supplied it.
        const uint64_t storedEnd = s.off + s.storedLen;
        const uint64_t limit =
            isOwner ? s.off + (s.logicalLen != 0 ? s.logicalLen : s.storedLen)
                    : storedEnd;
        if (isOwner) ownerTailLimit = limit;
        // F-693 (2026-10-01). LANDED HERE, MEASURED, REVERTED THE SAME DAY. THE
        // CAP THAT USED TO SIT AT THIS POINT IS GONE. It was: when the elected
        // owner was not being read from its own offset (`winOff != s.off`),
        // lower `limit` to the lowest OTHER member's offset physically inside
        // the window. The record is kept because the reason it went is not
        // visible in a diff that only deletes code.
        //
        // MEASURED FOOTPRINT. build/f693_clip_replay.py replays all 564
        // MEMBER-SPAN-OWNER rows of build/w680.log byte for byte with the span
        // table in registration order: ungated 113 rows / 34 windows /
        // 1,735,792 bytes changed; as shipped (`winOff != s.off`) 68 rows /
        // 20 windows / 976,968 bytes. Both numbers reproduce on a re-run.
        //
        // 1. THE MECHANISM IT CLAIMED WAS FALSE. The rationale was that the bytes
        //    the cap leaves alone "ARE vehicle.lst's own stored bytes, already
        //    correct". They are that member's stored DEFLATE. Measured:
        //    inflate(xarchive_cache.rpf[0x471000 : 0x471000+2355]) -> 22391 bytes
        //    beginning `Manufacturer\r\n{\r\n\tName\t\t`, i.e. the member's
        //    LOGICAL body -- and w680.log:34024 had ALREADY delivered exactly
        //    that body (SERVE-PROOF off=00471000 stored=2355 logical=22391
        //    served=22391 head=4D616E75 listProved=1 proved=1), seven log lines
        //    BEFORE this window was served at w680.log:34031. So the cap
        //    substituted one wrong byte sequence for another in that window; it
        //    did not repair vehicle.lst, and "leaving them alone IS serving that
        //    member" was inverted.
        // 2. THE HOLE LANDS IN THE OWNER'S OWN LOGICAL STREAM. Capping
        //    [00470000,00478000) at 00471000 and [00478000,00480000) at 00479000
        //    leaves 57344 bytes of raw DEFLATE inside carconfigs' logical
        //    [00448000,00490000). build/f693_shipped_model.py prints
        //    "identical over the whole capped tail: True" for both windows,
        //    against the inflated image at the same logical offsets.
        // 3. NO DISCRIMINATOR EXISTS TO NARROW IT, MEASURED TWO WAYS.
        //    (a) The intended one, ClassifyTailClaim's kNeighbour (`t.off <=
        //    head && head < t.off + t.storedLen`, with head = the WINDOW head),
        //    is ABSENT from w680.log: 0 rows of MEMBER-SPAN-TAIL-VETO, and 0 of
        //    the 196 lines that contain the marker text carry a `claim=` field
        //    -- all 196 are MEMBER-EXPAND-OVERRUN prose. It could not have fired
        //    on the two carconfigs windows in any case: their heads (00470000,
        //    00478000) sit BELOW the victims' offsets (00471000, 00479000),
        //    which is exactly what that test rejects.
        //    (b) build/f693_discrim.py, re-run here, enumerates all 21 capped
        //    SHAPES over 20 distinct windows -- [001D8000,001E0000) caps twice,
        //    at two different victims. Of every field the MEMBER-SPAN-OWNER row
        //    and the span table can supply, the only value the two carconfigs
        //    shapes SHARE with collateral is the victim's distance from the
        //    window head (4096 for both), and [00150000,00158000) /
        //    sst_trail_tex.dds carries that too; the window size (32768) is
        //    shared by all 21. The only values unique to the two are the owner's
        //    own stored/logical lengths (166323/294912) -- i.e. the statement
        //    "the owner is preload/xarchive_carconfigs.rpf", which names one
        //    member rather than stating a rule. There is no predicate that is
        //    true for both blockers and false for the other 19 shapes.
        //
        // THE RIGHT DISCRIMINATOR IS NOT THIS FILE'S TO WIRE. `readMemberOff`
        // (OpenFileHandle::read_member_off) is the data offset of the member the
        // CALLER is reading, and it would cap exactly that member's own window.
        // Both of its assignment sites set `raw_positional = true` on the
        // preceding line (src/gpu_device.cpp:2483-2484 and :21420-21421), and
        // ReadFileAt calls ApplyExpandedSpans only when `raw_positional` is false
        // (below, `if (!file.raw_positional)`), so it is 0 on every call into
        // this function -- which is also why F-645's kReadMemberHead test, the
        // one place it is read, has never fired.
        if (limit <= winOff || s.off >= winEnd) continue;

        ResolveSpan(s, physical_path, win, winOff, winLen);
        if (!s.resolved) continue;

        if (owner != nullptr && !isOwner) {
            if (refused == 0) firstRefused = s.off;
            ++refused;
            continue;
        }

        // Intersect the region this span may write with the window, and never
        // read past the cached image whatever the arithmetic says.
        const uint64_t i0 = std::max(s.off, winOff);
        const uint64_t i1 = std::min(limit, winEnd);
        if (i0 >= i1) continue;
        const uint64_t src0 = i0 - s.off;
        uint64_t n = i1 - i0;
        if (src0 >= s.bytes.size()) continue;
        if (n > s.bytes.size() - src0) n = s.bytes.size() - src0;
        std::memcpy(win + (i0 - winOff), s.bytes.data() + src0,
                    static_cast<size_t>(n));
        ++written;
    }

    if (owner != nullptr && written != 0) {
        MCLA_LOG_WARN("MEMBER-SPAN-OWNER off={:08X} stored={} logical={} "
                      "window=[{:08X},{:08X}) bytes={} refused={} firstRefused="
                      "{:08X} tail={:08X} (one window, one owner: the window is "
                      "this member's logical stream, so no other span may write "
                      "into it; `tail` is the owner's write limit and is its own "
                      "off+logical on every row -- the F-693 tail cap is reverted, "
                      "so `tail` differing from off+logical means a cap is back)",
                      owner->off, owner->storedLen, owner->logicalLen, winOff,
                      winEnd, written, refused, firstRefused, ownerTailLimit);
    } else if (owner != nullptr) {
        MCLA_LOG_WARN("MEMBER-SPAN-OWNER-UNRESOLVED off={:08X} stored={} "
                      "logical={} window=[{:08X},{:08X}) refused={} (the owner "
                      "is registered but did not resolve; window served as it "
                      "stands)", owner->off, owner->storedLen,
                      owner->logicalLen, winOff, winEnd, refused);
    }

    // F-638: a CLAIM that could not be backed, named once per member per boot
    // (the count of affected windows is the BARRED row below, which is per
    // window). This is the "detected and named, not silently allowed to win"
    // half of the rule: the extent is still reported, still overlaps, and the
    // winner of the contested bytes is stated -- `winner` is what the window
    // actually got, so a soak reading these two lines together can tell a
    // suppressed conflict from a lost one.
    if (barred != nullptr && !barred->named) {
        barred->named = true;
        // The contested bytes are the window head; the winner is the innermost
        // span that DID reproduce its own logical length, or NONE.
        const ExpandedSpan* win2 = nullptr;
        for (const auto& s : g_expSpans) {
            if (s.failed || !s.resolved || !SpanMatchesPack(s, packKey)) continue;
            if (s.off <= winOff && winOff < s.off +
                    (s.logicalLen != 0 ? s.logicalLen : s.storedLen) &&
                (win2 == nullptr || s.off > win2->off)) {
                win2 = &s;
            }
        }
        MCLA_LOG_WARN("MEMBER-SPAN-IMPLAUSIBLE off={:08X} stored={} logical={} "
                      "ratio={} packfile='{}' window=[{:08X},{:08X}) winner={} "
                      "(stored length NOT corroborated: the stored bytes at this "
                      "offset do not produce this member's own logical length, "
                      "so the on-disk extent it implies is fiction. Barred from "
                      "owning; its file is served as it lies on disk, which is "
                      "all the host can do for a container it cannot decode)",
                      barred->off, barred->storedLen, barred->logicalLen,
                      (barred->logicalLen != 0)
                          ? (static_cast<double>(barred->storedLen) /
                             static_cast<double>(barred->logicalLen))
                          : 0.0,
                      barred->packfile, winOff, winEnd,
                      (win2 != nullptr) ? win2->off : 0ull);
        if (win2 == nullptr) {
            MCLA_LOG_WARN("MEMBER-SPAN-IMPLAUSIBLE-NOWINNER off={:08X} "
                          "window=[{:08X},{:08X}) (no member reproduced its own "
                          "logical length for this head byte: winner=NONE, the "
                          "window is served from the file unchanged)",
                          barred->off, winOff, winEnd);
        }
    }
    // F-638: per-window accounting for the same condition, so a soak can count
    // it the way it counts MEMBER-SPAN-START-INSIDE.
    if (barred != nullptr) {
        MCLA_LOG_WARN("MEMBER-SPAN-OWNER-BARRED barredOff={:08X} barredStored={} "
                      "barredLogical={} window=[{:08X},{:08X}) winner={} "
                      "refused={} (the innermost member whose logical range "
                      "covers this window head could not produce its own body, "
                      "so it is not the owner: the window falls through to the "
                      "no-owner path and every span that DID reproduce writes "
                      "only its own stored bytes)",
                      barred->off, barred->storedLen, barred->logicalLen, winOff,
                      winEnd, (owner != nullptr) ? owner->off : 0ull, refused);
    }
    // F-638: a chosen owner that yields no data is a REFUSAL with a reason, not
    // a short read that hands the guest zeros. The window is left exactly as the
    // file supplied it; nothing is written on the owner's account.
    if (owner != nullptr && written == 0) {
        MCLA_LOG_WARN("MEMBER-SPAN-REFUSE off={:08X} stored={} logical={} "
                      "window=[{:08X},{:08X}) bytes=0 (the owner is registered "
                      "and corroborated but nothing in its image covers this "
                      "window; served from the file unchanged, NOT zero-filled)",
                      owner->off, owner->storedLen, owner->logicalLen, winOff,
                      winEnd);
    }
    // The ILLEGAL shape, named separately: the window's first byte lies inside
    // a DIFFERENT member's stored range than the one whose stream it is. That
    // is two members' on-disk extents overlapping -- 8 such pairs in the w663
    // census, e.g. raceeditor.xsf [000B001B,003F3030) over globaltex.list
    // [000D0000,000D00EC) -- and the window head decides which one is being
    // read. The legal shape is the same test with the two members equal: the
    // window begins inside the OWNER's own stored range, which is the
    // continuation read of a member larger than one window.
    //
    // F-638: this row is now COUNTED on its own terms, not only on the side
    // effect that something was written. The overlap is a fact about the table
    // of contents, so it is reported whether or not this particular window
    // happened to be a continuation read -- and it is reported in the NO-OWNER
    // case too, which is the shape the F-638 gate creates (a barred member's
    // window falls through to the no-owner path with a foreign member's stored
    // range over the head). Both are logged, so a soak can count the marker and
    // see which shape it was.
    if (headStored != nullptr && headStored != owner) {
        MCLA_LOG_WARN("MEMBER-SPAN-START-INSIDE head={:08X} headStoredOwner="
                      "{:08X} stored={} logical={} windowOwner={:08X} logical={} "
                      "window=[{:08X},{:08X}) written={} refused={} (the window "
                      "begins inside a different member's stored range than the "
                      "stream it is part of: refused, src/fs/vfs_rpf.cpp "
                      "ApplyExpandedSpans)",
                      winOff, headStored->off, headStored->storedLen,
                      headStored->logicalLen, (owner != nullptr) ? owner->off : 0ull,
                      (owner != nullptr) ? owner->logicalLen : 0u, winOff, winEnd,
                      written, refused);
    }
}
}  // namespace

// F-645: the definition of the rule src/fs/vfs_rpf.h declares. It sits at
// namespace scope (not in the anonymous namespace above) because the header
// declares it -- an anonymous-namespace definition would be a DIFFERENT function
// with internal linkage and the header's declaration would never be satisfied.
// SpanMatchesPack stays file-local and is still reachable from here.
TailClaim ClassifyTailClaim(const std::vector<ExpandedSpan>& spans,
                            const ExpandedSpan& s, uint64_t head,
                            const std::string& packKey,
                            uint64_t readMemberOff) {
    const uint64_t storedEnd = s.off + s.storedLen;
    if (head < storedEnd) return TailClaim::kInStoredRange;
    if (head == storedEnd) return TailClaim::kBoundaryByte;
    for (const auto& t : spans) {
        if (&t == &s || t.failed || !t.resolved) continue;
        if (!SpanMatchesPack(t, packKey)) continue;
        if (t.off <= head && head < t.off + t.storedLen) return TailClaim::kNeighbour;
    }
    // F-645, test 4: the head is the FIRST byte of the member the caller is
    // reading, and it is past the owner's own on-disk extent, so the owner's
    // logical tail is reaching into a window that is not its own stream. This is
    // LAST, after the two pre-existing voids, so it can only name bytes that no
    // earlier test claimed -- see the declared order in src/fs/vfs_rpf.h.
    if (readMemberOff != 0 && head == readMemberOff && head > storedEnd) {
        return TailClaim::kReadMemberHead;
    }
    return TailClaim::kContinuation;
}

void MarkMemberExpanded(uint64_t offset, uint32_t storedLen) {
    MarkMemberExpandedIn(std::string(), offset, storedLen, storedLen);
}

void MarkMemberExpandedIn(const std::string& packfile, uint64_t offset,
                          uint32_t storedLen, uint32_t logicalLen) {
    if (offset == 0 || storedLen > 0x1000000u || logicalLen > 0x1000000u) return;
    if (storedLen == 0 && logicalLen == 0) return;
    std::lock_guard<std::mutex> lk(g_expMtx);
    const std::string key = PackKeyOf(packfile);
    for (auto& s : g_expSpans) {
        if (s.off == offset && SpanMatchesPack(s, key) &&
            (s.packfile == key || s.packfile.empty() || key.empty())) {
            // Re-registration from a later census: keep the richest contract
            // (a published logical length beats an assumed one).
            if (logicalLen != 0) {
                s.logicalLen = logicalLen;
                if (storedLen != 0) s.storedLen = storedLen;
                if (s.logicalLen == s.storedLen) s.uncompressed = true;
                s.resolved = false;
                s.bytes.clear();
            }
            return;
        }
    }
    ExpandedSpan e;
    e.packfile = key;
    e.off = offset;
    e.storedLen = storedLen != 0 ? storedLen : logicalLen;
    e.logicalLen = logicalLen;
    // A member whose stored length equals its logical length is stored
    // UNCOMPRESSED and must be served byte-for-byte: 6 of the 377 members w653
    // published are in this class (the 61-byte `shaders/*/dcl/*.dcl` bodies,
    // head `31 20 3b 20` = "1 ; ").
    e.uncompressed = (storedLen != 0 && storedLen == logicalLen);
    g_expSpans.push_back(std::move(e));

    // F-638: this registry's OWN overlap detector, over the real span table
    // (the census-side detector in src/gpu_device.cpp keeps its 48 w664 rows
    // untouched; this is the authoritative half because it reads the table the
    // serve path will actually use, and it is the half that can name a winner).
    //
    // A member's on-disk extent is [off, off+storedLen). Two members whose
    // stored extents intersect are a genuine conflict: at the shared byte only
    // one of them can be the member being read. This is measured, not
    // hypothetical -- the six uncorroborated UI containers in w664 imply
    // extents of 0.5-7.6 MB and overlap 54 other members' extents between them
    // (MEMBER-SPAN-OVERLAP new='resources/ui/raceeditor/raceeditor.xsf'
    // newOff=000B001B newStored=3420181 over='shaders/ui/preload.list'
    // overOff=001DD11C, and five rows like it).
    //
    // `winner` is the span that WILL be served those bytes: the innermost span
    // (largest off) whose logical range covers the first contested byte, i.e.
    // the owner ApplyExpandedSpans will elect. Whether that winner can actually
    // produce them is decided at the first read, not here, and the verdict is
    // reported by MEMBER-SPAN-IMPLAUSIBLE (member-level) and
    // MEMBER-SPAN-OWNER-BARRED (per window).
    const ExpandedSpan& n = g_expSpans.back();
    const uint64_t nEnd = n.off + n.storedLen;
    for (const auto& s : g_expSpans) {
        if (&s == &n) continue;
        if (!SpanMatchesPack(s, key)) continue;
        const uint64_t sEnd = s.off + s.storedLen;
        if (n.off >= sEnd || s.off >= nEnd) continue;
        const uint64_t first = std::max(n.off, s.off);
        const ExpandedSpan* w = nullptr;
        for (const auto& t : g_expSpans) {
            const uint64_t e = t.off + (t.logicalLen != 0 ? t.logicalLen
                                                          : t.storedLen);
            if (t.off <= first && first < e && (w == nullptr || t.off > w->off)) {
                w = &t;
            }
        }
        MCLA_LOG_WARN("MEMBER-SPAN-OVERLAP newOff={:08X} newStored={} "
                      "newLogical={} newPack='{}' overOff={:08X} overStored={} "
                      "overLogical={} overPack='{}' contestedFrom={:08X} "
                      "winner={:08X} (two registered members' on-disk extents "
                      "intersect; the serve rule gives the contested bytes to "
                      "the innermost span covering them, and the winner's "
                      "ability to produce them is verified at the first read -- "
                      "src/fs/vfs_rpf.cpp MarkMemberExpandedIn)",
                      n.off, n.storedLen, n.logicalLen, n.packfile, s.off,
                      s.storedLen, s.logicalLen, s.packfile, first,
                      (w != nullptr) ? w->off : 0ull);
    }
}

// ---------------------------------------------------------------------------
// F-628: nested packfile registry.
//
// THE ROOT FIX for the tune starvation, and what it is NOT: this does not
// decrypt anything. The nested archive's TOC at inner+0x800 stays AES
// ciphertext, and the guest's own decrypt of it is untouched — the host only
// moves bytes the retail packer wrote. F-458 recorded that planting the outer
// member's bytes "pre-empts" the guest's inner decrypt, but the measurement
// behind that reading was a serve at the WRONG OFFSET: F-458 s2 looked for a
// second `RPF3` magic in the first 64 MiB of xarchive_cache.rpf and found none,
// because the three nested packfiles are stored COMPRESSED and there is
// nothing to find until they are inflated. The correct offset is the guest's
// own w2 (0x3F0000 / 0x368000 / 0x448000) and the correct length is w3&0xFFFFFF
// (0x503CF / 0x82186 / 0x289B3), and inflating those three spans yields
// 425,984 / 720,896 / 294,912 bytes each beginning `52 50 46 33 00 ..` with a
// real header (TOC length 14,336 / 792 entries, and two more of the same
// shape). A fourth member at 0x27F1ED6D also carries the `RPF3` magic on disk
// — deep in the 2 GiB cache packfile, not in the first 64 MiB, which is the
// whole reason the F-458 control missed the real answer.
//
// F-463's abstain block (src/gpu_device.cpp:1935-1944) and
// kF463AbstainNestedRpf (:132) should be REMOVED once this is wired: they
// suppress the serve that would otherwise hand the guest the compressed
// window, and that suppression is the reason the inner archive's header never
// parses and the `Vehicle` section walk (F442-SECTION, 14 rows, hits=0) never
// raises a count. w465 vs w460 was "measured inert" only because the gate
// value it looked at (`BDF20 #600 ... ret=0`) is decided by the INNER TOC
// lookup, which cannot succeed while the inner image is DEFLATE.
// ---------------------------------------------------------------------------
namespace {

// F-628: inner-TOC records that arrived BEFORE the outer TOC named the archive
// that contains them. Measured ordering does happen: the census is one hook, so
// `a:/archive/tune/vehicle/vehicle0008.lst` can be logged before
// `preload/xarchive_cameratune.rpf` if the title reaches the tune walk first on
// some boot. Parked rather than dropped, and replayed by RegisterNestedRpf.
std::mutex g_orphanMtx;
std::map<std::string,
         std::vector<std::pair<std::string, std::pair<uint32_t, uint32_t>>>>
    g_orphanMembers;

}  // namespace

// F-628: the mounted-nested-archive view, for the VFS read path and for the
// census in gpu_device.cpp. Returns nullptr for an unmounted name. The
// reference is taken under g_nestedMtx and the map is append-only for the life
// of a boot, so a live shared_ptr can never be invalidated.
std::shared_ptr<NestedRpfArchive> FindNestedRpf(const std::string& name) {
    const std::string key = NormalizeNestedKey(name);
    std::lock_guard<std::mutex> lk(g_nestedMtx);
    auto it = g_nested.find(key);
    return (it == g_nested.end()) ? nullptr : it->second;
}

bool SplitNestedPath(const std::string& path, std::string* archive,
                     std::string* inner) {
    if (archive == nullptr || inner == nullptr) return false;
    const std::string norm = NormalizeNestedKey(path);
    const size_t dot = norm.rfind(".rpf");
    if (dot == std::string::npos) return false;
    // The archive component ends at the FIRST `.rpf` component: the rest is
    // the path INSIDE that archive.
    size_t slash = norm.find('/', dot);
    if (slash == std::string::npos) {
        *archive = norm;
        inner->clear();
        return !norm.empty();
    }
    *archive = norm.substr(0, slash);
    *inner = norm.substr(slash + 1);
    return !archive->empty();
}

void RegisterNestedRpf(const std::string& packfile, const std::string& name,
                       uint64_t storedOffset, uint32_t storedLen,
                       uint32_t logicalLen) {
    if (storedOffset == 0 || storedLen == 0 || logicalLen == 0) return;

    // The outer packfile path: an explicit one, else game_data\<packfile>.
    // F-628: the game_data root is only known after Initialize, so fall back
    // to the two relative spellings the emulator is actually launched with
    // (CWD = build/, so build/game_data/<packfile>) before giving up. A bare
    // name with no reachable file is logged and dropped rather than mounted
    // with an unresolvable source, because Materialize would then fail on the
    // first read instead of at the census line that named the member.
    std::string outer = packfile;
    if (outer.empty() || outer.find(':') == std::string::npos) {
        const std::string bare = outer;
        const std::string gd = RpfVirtualFileSystem::Instance().GameDataRoot();
        static const char* kFallbacks[] = {"game_data", "..", "."};
        std::error_code ec;
        if (!gd.empty() && std::filesystem::exists(
                                std::filesystem::path(gd) / bare, ec)) {
            outer = (std::filesystem::path(gd) / bare).generic_string();
        } else {
            for (const char* dir : kFallbacks) {
                const auto candidate = std::filesystem::path(dir) / bare;
                if (std::filesystem::exists(candidate, ec)) {
                    outer = candidate.generic_string();
                    break;
                }
            }
        }
    }
    if (outer.empty() || !std::filesystem::exists(outer)) {
        MCLA_LOG_WARN("NESTED-RPF-SKIP name='{}' outer='{}' (no host file; the "
                      "member cannot be inflated)",
                      name, outer);
        return;
    }

    const std::string key = NormalizeNestedKey(name);
    std::lock_guard<std::mutex> lk(g_nestedMtx);
    auto it = g_nested.find(key);
    if (it != g_nested.end()) {
        // Already mounted. Re-registration only fills in a richer contract;
        // the object is not assignable (it holds a mutex) so the fields are
        // updated in place through ResetContract.
        if (logicalLen != 0 && it->second->logical_length() == 0) {
            it->second->ResetContract(storedOffset, storedLen, logicalLen);
            (void)it->second->Materialize();
        }
        return;
    }
    auto archive = std::make_shared<NestedRpfArchive>(name, outer, storedOffset,
                                                     storedLen, logicalLen);
    // Materialize eagerly so a bad offset is reported at registration with the
    // census line that named it, not 20 frames later inside a read.
    if (!archive->Materialize()) {
        MCLA_LOG_WARN("NESTED-RPF-FAIL name='{}' outer='{}' off={:08X} "
                      "stored={} logical={}: {}",
                      name, outer, storedOffset, storedLen, logicalLen,
                      archive->error());
        // Keep it anyway: a later registration with a corrected contract can
        // still succeed, and OpenFile will then serve the archive.
    }
    g_nested[key] = std::move(archive);

    // Replay any inner members the census published before this archive was
    // named, so `tune/vehicle/*.lst` resolves from the first boot rather than
    // only after the first re-lookup.
    {
        std::lock_guard<std::mutex> olk(g_orphanMtx);
        auto it = g_orphanMembers.find(key);
        if (it != g_orphanMembers.end()) {
            MCLA_LOG_WARN("NESTED-MEMBER-REPLAY archive='{}' records={}", key,
                          it->second.size());
            for (const auto& rec : it->second) {
                g_nested[key]->RecordMember(rec.first, rec.second.first,
                                            rec.second.second);
            }
            g_orphanMembers.erase(it);
        }
    }
}

void RegisterNestedMember(const std::string& name, const std::string& path,
                          uint32_t logicalLen, uint32_t storedLen) {
    std::string archive;
    std::string inner;
    if (!SplitNestedPath(path, &archive, &inner) || inner.empty()) return;
    if (logicalLen == 0) return;

    std::lock_guard<std::mutex> lk(g_nestedMtx);
    auto it = g_nested.find(archive);
    if (it == g_nested.end()) {
        // The census reached the inner TOC before the outer TOC named the
        // archive. Park the record so RegisterNestedRpf can replay it rather
        // than losing it.
        std::lock_guard<std::mutex> olk(g_orphanMtx);
        g_orphanMembers[archive].push_back({inner, {logicalLen, storedLen}});
        return;
    }
    it->second->RecordMember(inner, logicalLen, storedLen);
    static std::atomic<uint32_t> s_nestedMembers{0};
    const uint32_t n = s_nestedMembers.fetch_add(1) + 1;
    if (n <= 8 || (n % 500) == 0) {
        MCLA_LOG_WARN("NESTED-MEMBER #{} archive='{}' inner='{}' logical={} "
                      "stored={}",
                      n, archive, inner, logicalLen, storedLen);
    }
}

namespace {

// F-696 (2026-10-01). WHICH BRANCH RAN. One row per ReadFileAt, emitted from a
// scope guard constructed at the single anchor the task names -- the
// `if (file.handle)` test, before the OVERLAPPED block -- so every exit is
// covered exactly once, INCLUDING the early returns (`size == 0`, a failed
// ::ReadFile, a failed Materialize) that no hand-placed call at the end of a
// branch would ever reach.
//
// WHY THIS EXISTS. w682.log ends the boot with `fatal %%s arg: 'chevy'` because
// the guest's manufacturer table at 0x828CD078 is never populated: the loop
// body at sub_823971D0 ran 0 times because `tune/vehicle/vehicle.lst` did not
// parse. Three-for-3 the discriminator is a SPAN-OWNERSHIP COLLISION --
// xarchive_carconfigs.rpf is stored=166,323 but LOGICAL=294,912, so its logical
// range [0x448000,0x490000) swallows vehicle.lst at 0x471000 and
// vehicle0001.lst at 0x479000, and the two are refused (w682.log:26735
// MEMBER-SPAN-OWNER ... window=[00470000,00478000) refused=1
// firstRefused=00471000). Only vehicle0002.lst, whose offset is outside, parses.
//
// The fix cannot be written because nobody knows WHICH BRANCH serves the guest's
// three 32 KiB reads at [0x470000,0x478000), [0x478000,0x480000) and
// [0x480000,0x488000) (RD-BUF #209/#210/#211, cnt=32768). Those are CARCONFIGS'
// windows, not vehicle.lst's offset, and the answer points the fix in opposite
// directions:
//   * served by the outer `file.handle` branch -> the span table ran on it, and
//     the fault is an expanded span registered for a member RegisterNestedRpf
//     already owns (gpu_device.cpp, not this file).
//   * served by `branch=nested` -> the span entry for the three packfiles should
//     never have existed at all.
// The same log already carries the reason this was not answerable by reading:
// XSF-HOSTSERVE prints pass=0 for all three nested packfiles (6 rows,
// bootscripts/cameratune/carconfigs x 2 opens) against pass=1 for the other 88,
// so their device open is REFUSED (OPEN-REFUSED-STATUS = 74) and the guest falls
// back to the outer packfile -- which is why a 294,912-byte image is being
// window-spliced into a 166,323-byte hole. That is evidence, not the branch
// name, and this marker is the branch name.
//
// WHAT THIS DELIBERATELY DOES NOT PRINT. A delivered-vs-re-read `firstDiff`
// column is NOT here, and must not be added. On the handle branch the span
// table is SUPPOSED to change the bytes, so firstDiff would read -1 on exactly
// the windows that are broken: the column would be a false all-clear. The
// branch name is the whole point.
//
// WHAT IT IS NOT. It is not a served-bytes claim. It samples the 16 bytes at the
// pointer actually handed back to the guest, AFTER every branch has finished
// writing -- not a re-read of the packfile, which would be a different file on
// the handle branch (the F-647 window-source defect in its purest form).
//
// RATE LIMIT. First 16 per virtual path, then every 4096th, plus a total every
// 4096 calls. A boot issues thousands of ReadFileAt calls and a hard cap once
// made a burst's LENGTH unmeasurable (F-054: a soak 66% one repeating
// mitigation line); a sample must never be mistaken for the whole, so the
// branch counters and READAT-TOTAL sit on the UNSAMPLED side and `call=` carries
// the unconditional per-call serial that no rate limit can hide.
//
// TWO EXEMPTIONS, and the second one exists because the first is not enough.
//
//  1. The three nested packfiles by PATH. `preload/xarchive_{bootscripts,
//     cameratune,carconfigs}.rpf` are the names the guest's own TOC publishes
//     (XSF-HOSTSERVE path='preload/xarchive_carconfigs.rpf', w682.log:26415) and
//     the names OpenFile stores in OpenFileHandle::virtual_path for a nested
//     open (src/fs/vfs_rpf.cpp:563), which NormalizePath has already lowercased,
//     so one substring test covers the `a:/archive/` and device-prefixed
//     spellings too.
//
//  2. ANY window whose head lies inside a REGISTERED SPAN'S LOGICAL RANGE on
//     this read's packfile -- i.e. exactly the windows ApplyExpandedSpans can
//     have an opinion about. This one is not decoration, and without it the
//     instrument does not answer its own question. The brief's own measurement
//     says the three 32 KiB reads at [0x470000,0x480000) are served OFF THE OUTER
//     packfile: XSF-HOSTSERVE prints pass=0 for all three nested packfiles (6
//     rows) against pass=1 for the other 88, and OPEN-REFUSED-STATUS is 74, so
//     their device open is refused and the guest falls back to
//     xarchive_cache.rpf -- whose virtual_path is `xarchive_cache.rpf` and is
//     therefore NOT matched by exemption 1. A path-only gate would sample away
//     precisely the three windows the whole marker exists to name, and that is
//     the F-054 mistake at a smaller scale: a sample mistaken for the whole.
//     The predicate is read from g_expSpans, the same table the serve path uses,
//     so it cannot drift from the behaviour it is reporting on; and it is
//     evaluated ONLY for a row the rate limit would otherwise drop, so it costs
//     nothing on the rows that print. Size, measured not guessed: w682.log has
//     569 MEMBER-SPAN-OWNER rows, so this exemption is on the order of a few
//     hundred extra rows in a 9.7 MB log.
//
// FALSIFIERS. (a) If a boot's READAT-BRANCH rows for `xarchive_cache.rpf` at
// off=00470000/00478000/00480000 are absent while MEMBER-SPAN-OWNER rows for
// those windows are present, exemption 2 is broken. (b) If every READAT-BRANCH
// row says branch=handle, the open question is settled in the direction the
// span-collision reading predicts, and the fix belongs in gpu_device.cpp; if the
// three carconfigs windows say branch=nested, the span entry should not exist.
// Both are read off the boot's log, not asserted here.
constexpr uint64_t kReadAtFirstN = 16;
constexpr uint64_t kReadAtEveryN = 4096;

// The three nested packfiles, matched on the virtual path only. `preload/
// xarchive_{bootscripts,cameratune,carconfigs}.rpf` are the names the guest's
// own TOC publishes (XSF-HOSTSERVE path='preload/xarchive_carconfigs.rpf',
// w682.log:26415); the device-prefixed and archive-prefixed spellings normalize
// to the same OpenFileHandle::virtual_path, so one substring test covers all.
bool IsAlwaysLoggedNestedPath(const std::string& vpath) {
    return vpath.find("xarchive_bootscripts.rpf") != std::string::npos ||
           vpath.find("xarchive_cameratune.rpf") != std::string::npos ||
           vpath.find("xarchive_carconfigs.rpf") != std::string::npos;
}

std::string Head16Hex(const void* buffer, uint64_t bytes) {
    static const char* kHex = "0123456789ABCDEF";
    std::string out;
    if (buffer == nullptr || bytes == 0) return out;
    const uint8_t* p = static_cast<const uint8_t*>(buffer);
    const uint64_t n = std::min<uint64_t>(16, bytes);
    out.reserve(static_cast<size_t>(n) * 2);
    for (uint64_t i = 0; i < n; ++i) {
        out.push_back(kHex[p[i] >> 4]);
        out.push_back(kHex[p[i] & 0x0F]);
    }
    return out;
}

// The census state. File-scope, like every other registry in this file, and
// never reset for the life of the process: a boot's totals must not be
// restartable by a re-Initialize, for the same reason the nested registry is
// append-only (see the F-628 note on g_nested).
std::atomic<uint64_t> g_readAtTotal{0};
std::atomic<uint64_t> g_readAtHandle{0};
std::atomic<uint64_t> g_readAtNested{0};
std::atomic<uint64_t> g_readAtFallback{0};
std::mutex g_readAtTraceMtx;
std::map<std::string, uint64_t> g_readAtPerPath;

// Exemption 2 (see the block comment). `head` is the window head the call passed
// in and `packKey` the lowercased basename of the packfile the handle is on --
// the same key ApplyExpandedSpans computes, so this test and the serve path read
// the same table under the same matching rule (SpanMatchesPack).
//
// LOGICAL range, not stored range, and that is the whole point: the three nested
// packfiles are the load-bearing case where the pieces past a member's own last
// file byte are still its stream (the F-642 note above ApplyExpandedSpans, and
// the reason a 294,912-byte image over 166,323 stored reassembles at all). A
// stored-range test would exempt only each member's FIRST window and drop
// exactly the continuation windows in question.
//
// Empty key returns false without touching the table: SpanMatchesPack treats an
// empty pack key as "any packfile", so a handle whose physical path is unknown
// must not silently exempt every window in the boot.
bool WindowInsideRegisteredSpan(const std::string& packKey, uint64_t head) {
    if (packKey.empty()) return false;
    std::lock_guard<std::mutex> lk(g_expMtx);
    for (const auto& s : g_expSpans) {
        if (s.failed || s.logicalLen == 0) continue;
        if (!SpanMatchesPack(s, packKey)) continue;
        if (s.off <= head && head < s.off + s.logicalLen) return true;
    }
    return false;
}

// The guard. It COPIES every field it reports out of the handle at the anchor,
// and keeps a POINTER to the buffer plus a REFERENCE to bytes_read.
//
// WHY COPIES AND NOT A HANDLE REFERENCE. The nested branch calls lock.unlock()
// before it reads, so a destructor that read `file.virtual_path` or `file.handle`
// afterwards would be reading a shared handle with no mutex held. Copying at the
// anchor -- where m_mutex IS held -- makes the row immune to that, and makes it
// an honest record of the state at the moment the branch was decided. bytes_read
// and buffer are deliberately NOT copied: they are the caller's own
// out-parameter and destination, and the row has to report what was actually
// handed back, not what it looked like on entry.
//
// BRANCH DERIVATION, and it is read off the handle rather than passed in. The
// constructor's `handle`/`nested` pair is `file.handle != nullptr` and
// `file.nested_rpf != nullptr` -- the SAME two conditions the function's own
// `if`s test, read at the anchor before either test has run. Passing them in as
// literals from three separate call sites was the first shape of this and it was
// wrong twice over: three places to keep in sync, and each literal was an
// assertion about which branch the call site believed it was in rather than a
// fact about the handle. Reading the handle means the row reports the branch the
// conditions select, which is the only claim that settles the open question.
//
// `spanRan` is NOT derivable here, because only the call site that actually
// invokes ApplyExpandedSpans knows it ran (and on the fallback branch it also
// depends on the read having succeeded). It is therefore set from that call
// site, never assumed.
class ReadAtBranchTrace {
public:
    explicit ReadAtBranchTrace(
        const RpfVirtualFileSystem::OpenFileHandle& file, uint64_t offset,
        uint64_t size, void* buffer, uint64_t& bytes_read)
        : vpath_(file.virtual_path),
          packKey_(PackKeyOf(file.physical_path)),
          offset_(offset), size_(size),
          handle_(file.handle != nullptr),
          nested_(file.handle == nullptr && file.nested_rpf != nullptr),
          rawPositional_(file.raw_positional),
          readMemberOff_(file.read_member_off),
          spanRan_(false), buffer_(buffer), bytes_read_(bytes_read) {}

    // Set from the ApplyExpandedSpans call site, because only that call site
    // knows the table ran -- and on the fallback branch it also depends on the
    // read having succeeded. Never assumed in the constructor.
    void set_span_ran(bool v) { spanRan_ = v; }

    ~ReadAtBranchTrace() {
        // The branch NAME. `handle_`/`nested_` were read off the handle at the
        // anchor, from the conditions the body then tests in this same order:
        //   handle   -> `if (file.handle)`      (the first test)
        //   nested   -> `if (file.nested_rpf)`  (the second, handle already null)
        //   fallback -> neither                 (the shared-position tail)
        const char* branch = handle_ ? "handle" : (nested_ ? "nested" : "fallback");
        const bool always = IsAlwaysLoggedNestedPath(vpath_);
        const uint64_t call = g_readAtTotal.fetch_add(1) + 1;

        // The per-path serial is incremented UNCONDITIONALLY, so `#` counts every
        // call on this path whether or not a row is printed. That is what makes a
        // printed `#` falsifiable against the total: if the last printed `#` for a
        // path is not below that path's call count, the rate limit is dropping
        // rows a reader would need.
        uint64_t seen = 0;
        {
            std::lock_guard<std::mutex> lk(g_readAtTraceMtx);
            seen = ++g_readAtPerPath[vpath_];
        }
        // The branch counters and the periodic total are on the UNSAMPLED side of
        // the rate limit: they are the measurement, the per-path rows are the
        // sample, and a soak must be able to tell the two apart.
        if (handle_) g_readAtHandle.fetch_add(1, std::memory_order_relaxed);
        else if (nested_) g_readAtNested.fetch_add(1, std::memory_order_relaxed);
        else g_readAtFallback.fetch_add(1, std::memory_order_relaxed);

        if ((call % kReadAtEveryN) == 0) {
            MCLA_LOG_WARN("READAT-TOTAL call={} handle={} nested={} fallback={} "
                          "(every {}th call, UNSAMPLED: the READAT-BRANCH rows are "
                          "rate-limited per path and a sample must not be read as "
                          "the whole -- F-054)",
                          call, g_readAtHandle.load(std::memory_order_relaxed),
                          g_readAtNested.load(std::memory_order_relaxed),
                          g_readAtFallback.load(std::memory_order_relaxed),
                          kReadAtEveryN);
        }

        // First 16 per path, then every 4096th. NOT a hard cap -- the F-054 rule.
        // The two exemptions (nested-packfile path, and a window inside a
        // registered span's logical range) bypass it entirely: those are the
        // answer, and rate-limiting the answer reproduces F-054 at a smaller
        // scale. The table scan happens ONLY on a row the limit would drop, so
        // it is never paid on the rows that print.
        if (!always && seen > kReadAtFirstN && (seen % kReadAtEveryN) != 0 &&
            !WindowInsideRegisteredSpan(packKey_, offset_)) {
            return;
        }

        MCLA_LOG_WARN("READAT-BRANCH #{} call={} branch={} path='{}' off={:08X} "
                      "req={} got={} raw_positional={} read_member_off={:08X} "
                      "handle_nested={} span_ran={} head16={} "
                      "(branch is derived from the function's own `if`s, in the "
                      "order it tests them: handle = file.handle non-null, nested "
                      "= nested_rpf non-null, fallback = neither. span_ran=1 means "
                      "ApplyExpandedSpans wrote into THIS buffer, so on the handle "
                      "branch these bytes are spliced BY DESIGN and a "
                      "delivered-vs-re-read firstDiff would read -1 on exactly the "
                      "broken windows -- the branch name is the measurement, not "
                      "the bytes. read_member_off is reported as it is found. The "
                      "blanket claim that used to stand here -- that it is 0 on "
                      "every call -- is FALSE and was measured false: on w720.log "
                      "54 of 292 rows carry a non-zero value and every one of "
                      "those 54 is raw_positional=1 with span_ran=0. What is true "
                      "is the narrower statement the span machinery rests on: it "
                      "is 0 on every call that RUNS the span table, because the "
                      "handle branch returns before the span table on exactly "
                      "those 54 rows -- both call sites here are under `if (!file."
                      "raw_positional)` -- and the two gpu_device.cpp sites that "
                      "assign it, :2946 and :22763, each set raw_positional on "
                      "the immediately preceding line",
                      seen, call, branch, vpath_, offset_, size_, bytes_read_,
                      rawPositional_ ? 1 : 0, readMemberOff_,
                      nested_ ? 1 : 0, spanRan_ ? 1 : 0,
                      Head16Hex(buffer_, bytes_read_));
    }

private:
    const std::string vpath_;
    const std::string packKey_;
    const uint64_t offset_;
    const uint64_t size_;
    const bool handle_;
    const bool nested_;
    const bool rawPositional_;
    const uint64_t readMemberOff_;
    bool spanRan_;
    const void* buffer_;
    uint64_t& bytes_read_;
};

}  // namespace

bool RpfVirtualFileSystem::ReadFileAt(OpenFileHandle& file, uint64_t offset,
                                      void* buffer, uint64_t size,
                                      uint64_t& bytes_read) {
    // unique_lock: the fallback path re-enters ReadFile (which locks
    // m_mutex itself) — std::mutex is non-recursive, so release first.
    std::unique_lock<std::mutex> lock(m_mutex);
    bytes_read = 0;
    // F-696 (2026-10-01). THE ANCHOR, and it is deliberately the only one. It
    // sits at the `if (file.handle)` test and BEFORE the OVERLAPPED block, so it
    // is passed by every call into this function regardless of which branch the
    // body's own tests then select -- and it is constructed before every early
    // return too, so `size == 0`, a failed ::ReadFile and a failed Materialize
    // are all counted rather than silently skipped.
    //
    // The branch is read from the two fields the body is about to test, in the
    // order it tests them:
    //   handle    -- file.handle != nullptr                (the first `if`)
    //   nested    -- file.handle == nullptr && file.nested_rpf != nullptr
    //   fallback  -- both null                             (the tail)
    // Neither field is written anywhere between here and the body's tests, so
    // reading them here cannot disagree with the branch actually taken. This is
    // a derivation from the function's own conditions, not a guess -- and the
    // emitted row names the branch so the next reader does not have to re-derive
    // it either.
    //
    // The destructor runs on EVERY exit, including the three early returns that
    // no call placed at the end of a branch could reach. It reads `bytes_read`
    // and `buffer` by reference, so what it prints is what the caller is about
    // to be handed back.
    ReadAtBranchTrace trace(file, offset, size, buffer, bytes_read);
    if (file.handle) {
        // positional read on the real packfile (OVERLAPPED, no seek)
        if (size == 0) return true;
        OVERLAPPED ov{};
        ov.Offset = static_cast<DWORD>(offset);
        ov.OffsetHigh = static_cast<DWORD>(offset >> 32);
        DWORD got = 0;
        if (!::ReadFile(static_cast<HANDLE>(file.handle), buffer,
                        static_cast<DWORD>(size), &got, &ov))
            return false;
        bytes_read = got;
        // F-645: `raw_positional` makes the F-655 step-2 claim TRUE. It is a
        // property of the HANDLE, so it is honoured here and on the fallback
        // branch below -- a raw-positional read that was still run through the
        // span table on one of the two branches would be the same half-true
        // comment this flag replaces. `read_member_off` is passed straight to
        // ClassifyTailClaim as the kReadMemberHead fact and nothing else.
        if (!file.raw_positional) {
            ApplyExpandedSpans(file.physical_path,
                               static_cast<uint8_t*>(buffer), offset, bytes_read,
                               file.read_member_off);
            // F-696: only now is it known whether the span table ran, and it is
            // set from this call site's own condition rather than assumed.
            trace.set_span_ran(true);
        }
        return got == size;
    }
    // F-628: positional read inside a NESTED packfile. The image is the
    // inflated outer member, i.e. a real RPF3 archive, so this is the same
    // addressing the outer packfile gets — the guest's own inner-TOC decrypt
    // then runs on these bytes exactly as it would on the real disk image.
    if (file.nested_rpf) {
        if (size == 0) return true;
        std::shared_ptr<NestedRpfArchive> nested = file.nested_rpf;
        lock.unlock();
        if (!nested->Materialize()) {
            MCLA_LOG_WARN("VFS: nested read of '{}' at {} failed: {}",
                          file.virtual_path, offset, nested->error());
            return false;
        }
        if (!nested->Read(offset, buffer, static_cast<size_t>(size))) {
            // A short read at the tail is EOF, which is a normal archive
            // boundary; report it as a short read, not a failure.
            bytes_read = 0;
            const uint64_t remaining =
                (offset < nested->image().size())
                    ? nested->image().size() - offset
                    : 0;
            if (remaining != 0 && remaining < size) {
                nested->Read(offset, buffer, static_cast<size_t>(remaining));
                bytes_read = remaining;
            }
            return bytes_read != 0;
        }
        bytes_read = size;
        return true;
    }
    // fallback: shared-position path (virtual rpf / pseudo files)
    lock.unlock();
    file.position = offset;
    const bool ok = ReadFile(file, buffer, size, bytes_read);
    if (ok && !file.raw_positional) {
        ApplyExpandedSpans(file.physical_path, static_cast<uint8_t*>(buffer),
                           offset, bytes_read, file.read_member_off);
        trace.set_span_ran(true);
    }
    return ok;
}

bool RpfVirtualFileSystem::CloseFile(OpenFileHandle& file) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (file.handle) {
        CloseHandle(static_cast<HANDLE>(file.handle));
        file.handle = nullptr;
    }
    file.virtual_rpf.reset();
    // F-628: the nested archive itself is shared and stays mounted (it is
    // keyed by name in the g_nested registry); only this handle's reference
    // drops.
    file.nested_rpf.reset();
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

    LARGE_INTEGER liOffset, liNewPos;
    liOffset.QuadPart = offset;
    if (!::SetFilePointerEx(static_cast<HANDLE>(file.handle), liOffset, &liNewPos, moveMethod)) {
        return false;
    }
    file.position = static_cast<uint64_t>(liNewPos.QuadPart);
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

bool NtReadFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t& bytes_read) {
    (void)file_handle;
    (void)buffer_guest_addr;
    (void)length;
    (void)bytes_read;
    return false;
}

bool NtQueryInformationFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t info_class) {
    (void)file_handle;
    (void)buffer_guest_addr;
    (void)length;
    (void)info_class;
    return false;
}

bool NtQueryDirectoryFileHook(uint32_t file_handle, uint32_t buffer_guest_addr, uint32_t length, uint32_t info_class) {
    (void)file_handle;
    (void)buffer_guest_addr;
    (void)length;
    (void)info_class;
    return false;
}

bool NtCloseHook(uint32_t file_handle) {
    (void)file_handle;
    return false;
}

} // namespace mcla::vfs::hooks
