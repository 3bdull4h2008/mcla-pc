#include "xenon_smoke.h"

#include <windows.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

#include "ppc_recomp_shared.h"

// Guest memory as a byte-swapped (big-endian) 32-bit store, matching
// PPC_STORE_U32 in ppc_context.h.
inline void SmokeStoreU32(uint32_t guestAddr, uint32_t value)
{
    *(volatile uint32_t*)(g_base + guestAddr) = __builtin_bswap32(value);
}

inline uint32_t SmokeLoadU32(uint32_t guestAddr)
{
    return __builtin_bswap32(*(volatile uint32_t*)(g_base + guestAddr));
}

inline void SmokeStoreU16(uint32_t guestAddr, uint16_t value)
{
    *(volatile uint16_t*)(g_base + guestAddr) = __builtin_bswap16(value);
}

inline uint16_t SmokeLoadU16(uint32_t guestAddr)
{
    return __builtin_bswap16(*(volatile uint16_t*)(g_base + guestAddr));
}

inline uint64_t SmokeLoadU64(uint32_t guestAddr)
{
    uint64_t v = 0;
    std::memcpy(&v, g_base + guestAddr, 8);
    return __builtin_bswap64(v);
}

inline void SmokeStoreU64(uint32_t guestAddr, uint64_t value)
{
    const uint64_t be = __builtin_bswap64(value);
    std::memcpy(g_base + guestAddr, &be, 8);
}

// Host-backed file service for the guest NT file API. Maps guest paths onto a
// host directory (build/game_data) and hands out opaque handle values so the
// game can open its RPF archives. Index+1 keeps 0 reserved for NULL.
namespace
{
    std::mutex g_hostFileMutex;
    struct HostFileEntry
    {
        HANDLE handle = nullptr;
        uint64_t endOfFile = 0;
        bool isDirectory = false;
        std::string hostDir; // directory pseudo-handle: host base for relative opens
    };
    std::vector<HostFileEntry> g_hostFiles;

    uint32_t SmokeHostFileAdd(HANDLE h, uint64_t eof)
    {
        std::scoped_lock lock(g_hostFileMutex);
        for (size_t i = 0; i < g_hostFiles.size(); i++)
        {
            if (g_hostFiles[i].handle == nullptr && !g_hostFiles[i].isDirectory)
            {
                g_hostFiles[i] = HostFileEntry{h, eof, false, {}};
                return static_cast<uint32_t>(i + 1);
            }
        }
        g_hostFiles.push_back(HostFileEntry{h, eof, false, {}});
        return static_cast<uint32_t>(g_hostFiles.size());
    }

    uint32_t SmokeHostFileAddDir(std::string hostDir)
    {
        std::scoped_lock lock(g_hostFileMutex);
        for (size_t i = 0; i < g_hostFiles.size(); i++)
        {
            if (g_hostFiles[i].handle == nullptr && !g_hostFiles[i].isDirectory)
            {
                g_hostFiles[i] = HostFileEntry{nullptr, 0, true, std::move(hostDir)};
                return static_cast<uint32_t>(i + 1);
            }
        }
        g_hostFiles.push_back(HostFileEntry{nullptr, 0, true, std::move(hostDir)});
        return static_cast<uint32_t>(g_hostFiles.size());
    }

    bool SmokeHostFileGet(uint32_t handle, HostFileEntry& out)
    {
        std::scoped_lock lock(g_hostFileMutex);
        if (handle == 0 || handle - 1 >= g_hostFiles.size())
            return false;
        out = g_hostFiles[handle - 1];
        return out.handle != nullptr;
    }

    // Directory pseudo-handle lookup (SmokeHostFileGet rejects dir entries).
    bool SmokeHostDirGet(uint32_t handle, std::string& hostDir)
    {
        std::scoped_lock lock(g_hostFileMutex);
        if (handle == 0 || handle - 1 >= g_hostFiles.size())
            return false;
        const HostFileEntry& e = g_hostFiles[handle - 1];
        if (!e.isDirectory)
            return false;
        hostDir = e.hostDir;
        return true;
    }

    void SmokeHostFileClose(uint32_t handle)
    {
        std::scoped_lock lock(g_hostFileMutex);
        if (handle == 0 || handle - 1 >= g_hostFiles.size())
            return;
        if (g_hostFiles[handle - 1].handle != nullptr)
            CloseHandle(g_hostFiles[handle - 1].handle);
        if (g_hostFiles[handle - 1].handle != nullptr || g_hostFiles[handle - 1].isDirectory)
            g_hostFiles[handle - 1] = HostFileEntry{};
    }

    std::string SmokeDecodeUnicodeString(uint32_t strAddr)
    {
        // UNICODE_STRING: +0 Length (u16 BE), +2 MaximumLength, +4 Buffer.
        // Xbox kernel device paths are frequently plain single-byte ASCII in
        // the buffer with Length == strlen; detect and use that directly.
        if (strAddr == 0)
            return {};
        const uint16_t length = SmokeLoadU16(strAddr);
        const uint32_t buffer = SmokeLoadU32(strAddr + 4);
        if (buffer == 0)
            return {};
        const uint32_t cap = std::min<uint32_t>(length, 1024);
        bool ascii = true;
        for (uint32_t i = 0; i < cap && ascii; i++)
        {
            const uint8_t b = *(volatile uint8_t*)(g_base + buffer + i);
            if (b == 0)
                break;
            if (b < 0x20 || b >= 0x7F)
                ascii = false;
        }
        if (ascii)
        {
            std::string out;
            for (uint32_t i = 0; i < cap; i++)
            {
                const uint8_t b = *(volatile uint8_t*)(g_base + buffer + i);
                if (b == 0)
                    break;
                out.push_back(static_cast<char>(b));
            }
            return out;
        }
        std::string out;
        for (uint32_t i = 0; i + 1 < cap; i += 2)
        {
            const uint16_t wc = __builtin_bswap16(*(volatile uint16_t*)(g_base + buffer + i));
            if (wc == 0)
                break;
            out.push_back((wc >= 0x20 && wc < 0x7F) ? static_cast<char>(wc) : '?');
        }
        return out;
    }

    std::string SmokeMapGuestPath(const std::string& path)
    {
        std::string p = path;
        for (auto& c : p)
        {
            if (c == '\\')
                c = '/';
        }
        std::string lower = p;
        std::transform(lower.begin(), lower.end(), lower.begin(),
                       [](char c) { return static_cast<char>((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c); });
        // Strip native device prefixes (e.g. \Device\Cdrom0\game:\foo).
        for (const char* pre : {"/device/cdrom0/", "/device/hdd0/", "/device/mu0/", "/device/mu1/", "/systemroot/"})
        {
            const size_t n = std::strlen(pre);
            if (lower.rfind(pre, 0) == 0)
            {
                p = p.substr(n);
                lower = lower.substr(n);
                break;
            }
        }
        // Map drive leaves (game:, d:, t:, cache:) to the relative path part.
        const size_t colon = p.find(':');
        if (colon != std::string::npos)
            p = p.substr(colon + 1);
        while (!p.empty() && (p.front() == '/' || p.front() == '\\'))
            p.erase(p.begin());
        return p;
    }

    struct SmokeOpenResult
    {
        HANDLE handle = INVALID_HANDLE_VALUE;
        uint64_t endOfFile = 0;
        bool isDirectory = false;
        std::string hostPath;
    };

    // Map a guest path to build/game_data/... and open it for read, allowing
    // directory opens (root pseudo-handles) via FILE_FLAG_BACKUP_SEMANTICS.
    bool SmokeOpenMappedPath(const std::string& guestPath, DWORD desiredAccess, SmokeOpenResult& out)
    {
        out.hostPath = std::string("build/game_data/") + SmokeMapGuestPath(guestPath);
        std::string p = out.hostPath;
        while (p.size() > std::string("build/game_data").size() && (p.back() == '/' || p.back() == '\\'))
            p.pop_back();
        const DWORD attr = GetFileAttributesA(p.c_str());
        const bool isDir = (attr != INVALID_FILE_ATTRIBUTES) && (attr & FILE_ATTRIBUTE_DIRECTORY);
        DWORD flags = FILE_ATTRIBUTE_NORMAL;
        if (isDir)
            flags |= FILE_FLAG_BACKUP_SEMANTICS;
        HANDLE h = CreateFileA(p.c_str(), desiredAccess,
                               FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                               OPEN_EXISTING, flags, nullptr);
        if (h == INVALID_HANDLE_VALUE)
            return false;
        out.handle = h;
        out.isDirectory = isDir;
        out.hostPath = p;
        if (!isDir)
        {
            LARGE_INTEGER size{};
            GetFileSizeEx(h, &size);
            out.endOfFile = static_cast<uint64_t>(size.QuadPart);
        }
        return true;
    }
} // namespace

namespace
{
    // Simple bump allocator over the guest physical region [0xA0000000, 4 GiB).
    // Mirrors UnleashedRecomp RESERVED_END (0xA0000000); the XEX image ends at
    // ~0x829E0000 and the smoke stack tops out at 0x8F000000, so this range is
    // clear of both.
    std::mutex g_physMutex;
    uint32_t g_physCursor = 0xA0000000u;

    uint32_t SmokeAllocPhysical(uint32_t size, uint32_t alignment)
    {
        if (alignment == 0)
            alignment = 0x1000;
        std::scoped_lock lock(g_physMutex);
        const uint32_t base = (g_physCursor + alignment - 1) & ~(alignment - 1);
        if (base + size < base || base + size >= 0x100000000u)
            return 0;
        g_physCursor = base + size;
        return base;
    }

    // TLS index allocator (indices 0..63).
    std::mutex g_tlsMutex;
    std::vector<uint32_t> g_tlsFreeIndices;
    uint32_t g_tlsNextIndex = 0;
    std::vector<uint32_t> g_tlsValues; // indexed by slot; global since the smoke host is single-threaded

    uint32_t SmokeTlsAlloc()
    {
        std::scoped_lock lock(g_tlsMutex);
        if (!g_tlsFreeIndices.empty())
        {
            const uint32_t index = g_tlsFreeIndices.back();
            g_tlsFreeIndices.pop_back();
            return index;
        }
        return g_tlsNextIndex++; // caller enforces 0..63 by construction
    }

    uint32_t SmokeTlsFree(uint32_t index)
    {
        std::scoped_lock lock(g_tlsMutex);
        g_tlsFreeIndices.push_back(index);
        return 1;
    }

    uint32_t SmokeTlsGetValue(uint32_t index)
    {
        std::scoped_lock lock(g_tlsMutex);
        return index < g_tlsValues.size() ? g_tlsValues[index] : 0;
    }

    void SmokeTlsSetValue(uint32_t index, uint32_t value)
    {
        std::scoped_lock lock(g_tlsMutex);
        if (g_tlsValues.size() <= index)
            g_tlsValues.resize(index + 1, 0);
        g_tlsValues[index] = value;
    }
} // namespace

// ---------------------------------------------------------------------------
// Guest virtual memory (NtAllocateVirtualMemory / NtQueryVirtualMemory /
// NtFreeVirtualMemory).
//
// The whole guest window is host-backed (VirtualAlloc 4 GiB, committed RW),
// so reserve/commit are bookkeeping only. Regions are carved from Xenia's
// 64 KB-page guest-virtual range [0x40000000, 0x7EFFFFFF] (X_MEM_LARGE_PAGES),
// clear of the image (0x82000000), smoke stack (0x8F000000), r13 thread block
// (0x8F200000) and the physical bump range (0xA0000000).
// ---------------------------------------------------------------------------
namespace
{
    struct SmokeVmRegion
    {
        uint32_t base;
        uint32_t size;
        uint32_t state; // X_MEM_COMMIT (0x1000) / X_MEM_RESERVE (0x2000) / X_MEM_FREE (0x10000)
        uint32_t protect; // X_PAGE_* (4 = X_PAGE_READWRITE)
    };

    constexpr uint32_t kSmokeVmBase = 0x40000000u;
    constexpr uint32_t kSmokeVmEnd = 0x7EFFFFFFu;

    std::mutex g_vmMutex;
    std::vector<SmokeVmRegion> g_vmRegions;

    uint32_t SmokeVmRoundSize(uint32_t size, uint32_t pageSize)
    {
        return (size + pageSize - 1) & ~(pageSize - 1);
    }

    // First-fit gap at least `size` bytes in [kSmokeVmBase, kSmokeVmEnd].
    // Caller must hold g_vmMutex.
    uint32_t SmokeVmFindGapLocked(uint32_t size, uint32_t alignment)
    {
        std::vector<SmokeVmRegion> sorted = g_vmRegions;
        std::sort(sorted.begin(), sorted.end(),
                  [](const SmokeVmRegion& a, const SmokeVmRegion& b) { return a.base < b.base; });
        uint32_t cursor = kSmokeVmBase;
        for (const auto& r : sorted)
        {
            const uint32_t aligned = (cursor + alignment - 1) & ~(alignment - 1);
            if (r.base >= aligned && r.base - aligned >= size)
            {
                if (aligned + size - 1 <= kSmokeVmEnd)
                    return aligned;
            }
            cursor = std::max(cursor, r.base + r.size);
        }
        const uint32_t aligned = (cursor + alignment - 1) & ~(alignment - 1);
        if (aligned + size - 1 <= kSmokeVmEnd)
            return aligned;
        return 0;
    }

    // Reserve a fresh region (base == 0) or reserve/commit an explicit range.
    // Returns the base address, or 0 on failure.
    uint32_t SmokeVmAlloc(uint32_t base, uint32_t size, uint32_t allocType, uint32_t protect)
    {
        const uint32_t pageSize = (allocType & 0x20000000u) ? 0x10000u : 0x1000u; // X_MEM_LARGE_PAGES
        size = SmokeVmRoundSize(size, pageSize);
        if (size == 0)
            return 0;
        std::scoped_lock lock(g_vmMutex);
        if (base == 0)
        {
            base = SmokeVmFindGapLocked(size, pageSize);
            if (base == 0)
                return 0;
        }
        else
        {
            base = base & ~(pageSize - 1);
        }
        // Drop any stale overlapping regions, then record the new one.
        g_vmRegions.erase(std::remove_if(g_vmRegions.begin(), g_vmRegions.end(),
                                         [&](const SmokeVmRegion& r) {
                                             return r.base < base + size && base < r.base + r.size;
                                         }),
                          g_vmRegions.end());
        g_vmRegions.push_back({base, size,
                               (allocType & 0x1000u) ? 0x1000u : 0x2000u, protect});
        return base;
    }

    uint32_t SmokeVmFree(uint32_t base, uint32_t size, uint32_t freeType)
    {
        const uint32_t pageSize = 0x10000u;
        size = SmokeVmRoundSize(size, pageSize);
        std::scoped_lock lock(g_vmMutex);
        if (size == 0 || size == pageSize)
        {
            g_vmRegions.erase(std::remove_if(g_vmRegions.begin(), g_vmRegions.end(),
                                             [&](const SmokeVmRegion& r) { return r.base == base; }),
                              g_vmRegions.end());
            return 0;
        }
        // Release: drop the region entirely.
        g_vmRegions.erase(std::remove_if(g_vmRegions.begin(), g_vmRegions.end(),
                                         [&](const SmokeVmRegion& r) {
                                             return r.base < base + size && base < r.base + r.size;
                                         }),
                          g_vmRegions.end());
        return 0;
    }

    // Fill a guest X_MEMORY_BASIC_INFORMATION (28 bytes, all big-endian u32):
    //   +0x00 base_address, +0x04 allocation_base, +0x08 allocation_protect,
    //   +0x0C region_size, +0x10 state, +0x14 protect, +0x18 type.
    // Returns true if the address is inside a tracked region.
    bool SmokeVmQuery(uint32_t address, uint32_t outInfo)
    {
        std::scoped_lock lock(g_vmMutex);
        for (const auto& r : g_vmRegions)
        {
            if (address >= r.base && address < r.base + r.size)
            {
                SmokeStoreU32(outInfo + 0x00, address & ~0xFFFFu);
                SmokeStoreU32(outInfo + 0x04, r.base);
                SmokeStoreU32(outInfo + 0x08, r.protect);
                SmokeStoreU32(outInfo + 0x0C, r.size);
                SmokeStoreU32(outInfo + 0x10, r.state);
                SmokeStoreU32(outInfo + 0x14, r.protect);
                SmokeStoreU32(outInfo + 0x18, 0x20000u); // X_MEM_PRIVATE
                return true;
            }
        }
        return false;
    }

    void SmokeNtAllocateVirtualMemory(PPCContext& ctx)
    {
        s_StubCalled("__imp__NtAllocateVirtualMemory");
        const uint32_t basePtr = ctx.r3.u32;
        const uint32_t sizePtr = ctx.r4.u32;
        const uint32_t allocType = ctx.r5.u32;
        const uint32_t protect = ctx.r6.u32;
        if (basePtr == 0 || sizePtr == 0)
        {
            ctx.r3.u32 = 0xC000000Du; // X_STATUS_INVALID_PARAMETER
            return;
        }
        uint32_t size = SmokeLoadU32(sizePtr);
        if (size == 0)
        {
            ctx.r3.u32 = 0xC000000Du; // X_STATUS_INVALID_PARAMETER
            return;
        }
        if ((int32_t)size < 0)
            size = (uint32_t)(-(int32_t)size);
        uint32_t base = SmokeLoadU32(basePtr);
        uint32_t allocated = SmokeVmAlloc(base, size, allocType, protect);
        if (allocated == 0)
        {
            ctx.r3.u32 = 0xC0000017u; // X_STATUS_NO_MEMORY
            return;
        }
        const uint32_t pageSize = (allocType & 0x20000000u) ? 0x10000u : 0x1000u;
        SmokeStoreU32(basePtr, allocated);
        SmokeStoreU32(sizePtr, SmokeVmRoundSize(size, pageSize));
        ctx.r3.u32 = 0; // X_STATUS_SUCCESS
    }

    void SmokeNtQueryVirtualMemory(PPCContext& ctx)
    {
        s_StubCalled("__imp__NtQueryVirtualMemory");
        const uint32_t address = ctx.r3.u32;
        const uint32_t outInfo = ctx.r4.u32;
        if (outInfo == 0)
        {
            ctx.r3.u32 = 0xC000000Du; // X_STATUS_INVALID_PARAMETER
            return;
        }
        if (SmokeVmQuery(address, outInfo))
            ctx.r3.u32 = 0; // X_STATUS_SUCCESS
        else
            ctx.r3.u32 = 0xC000000Du; // X_STATUS_INVALID_PARAMETER
    }

    void SmokeNtFreeVirtualMemory(PPCContext& ctx)
    {
        s_StubCalled("__imp__NtFreeVirtualMemory");
        const uint32_t basePtr = ctx.r3.u32;
        const uint32_t sizePtr = ctx.r4.u32;
        const uint32_t freeType = ctx.r5.u32;
        if (basePtr == 0 || sizePtr == 0)
        {
            ctx.r3.u32 = 0xC000000Du; // X_STATUS_INVALID_PARAMETER
            return;
        }
        uint32_t base = SmokeLoadU32(basePtr);
        uint32_t size = SmokeLoadU32(sizePtr);
        SmokeVmFree(base, size, freeType);
        SmokeStoreU32(basePtr, 0);
        SmokeStoreU32(sizePtr, 0);
        ctx.r3.u32 = 0; // X_STATUS_SUCCESS
    }
} // namespace

// XTL dispatch targets. The generated thunks sub_82130528/550/588 resolve the
// allocation import through the r13 thread block (slot 7 = offset 28):
//   r11 = *(r13); r3 = *(r11 + 28); r9 = *r3; fn = *(r9 + 8|12); call fn
// The allocator is called with r3=descriptor, r4=size, r5=alignment, r6=0 and
// must return the buffer guest address in r3; free with r3=descriptor, r4=ptr.
PPC_FUNC(__xtl_alloc)
{
    uint32_t align = ctx.r5.u32;
    if (align < 16 || (align & (align - 1)) != 0)
        align = 16;
    ctx.r3.u32 = SmokeAllocPhysical(ctx.r4.u32, align);
    s_StubCalled("__xtl_alloc");
}

PPC_FUNC(__xtl_free)
{
    // Bump allocator owns everything; nothing is reclaimed per-object.
    ctx.r3.u32 = 1;
    s_StubCalled("__xtl_free");
}

// Kernel import stubs (one per __imp__ symbol referenced by generated TUs).
// Generated from the TU import list; do not hand-edit without re-validating.
#include "kernel_stubs_body.inc"