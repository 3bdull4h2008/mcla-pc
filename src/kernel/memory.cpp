#include <stdafx.h>
#include "memory.h"
#include "heap.h"

mcla::kernel::Memory::Memory()
{
#ifdef _WIN32
    // First check if memory is already reserved or committed at the target address
    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery((void*)0x100000000ull, &mbi, sizeof(mbi)) == sizeof(mbi) && 
        (mbi.State == MEM_RESERVE || mbi.State == MEM_COMMIT))
    {
        base = (uint8_t*)0x100000000ull;
    }
    else
    {
        base = (uint8_t*)VirtualAlloc((void*)0x100000000ull, PPC_MEMORY_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (base == nullptr)
            base = (uint8_t*)VirtualAlloc(nullptr, PPC_MEMORY_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    if (base == nullptr)
        return;

    DWORD oldProtect;
    VirtualProtect(base, 4096, PAGE_NOACCESS, &oldProtect);
#else
    // On Linux, check if memory is already mapped at the target address
    // This is a simplified check; in practice, we'd need to parse /proc/self/maps
    base = (uint8_t*)mmap((void*)0x100000000ull, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE | MAP_FIXED_NOREPLACE, -1, 0);

    if (base == (uint8_t*)MAP_FAILED)
        base = (uint8_t*)mmap((void*)0x100000000ull, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (base == (uint8_t*)MAP_FAILED)
        base = (uint8_t*)mmap(NULL, PPC_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (base == nullptr)
        return;

    mprotect(base, 4096, PROT_NONE);
#endif

    // Record the window size; IsInMemoryRange/Translate bounds checks rely on
    // it and boot_host reuses this window based on it being fully reserved.
    size = PPC_MEMORY_SIZE;

    for (size_t i = 0; PPCFuncMappings[i].guest != 0; i++)
    {
        if (PPCFuncMappings[i].host != nullptr)
            InsertFunction(PPCFuncMappings[i].guest, PPCFuncMappings[i].host);
    }
}

void* MmGetHostAddress(uint32_t ptr)
{
    return mcla::kernel::g_memory.Translate(ptr);
}

// Checked, endian-explicit read/write helpers for GuestMemoryHeap
bool mcla::kernel::GuestMemoryHeap::ReadU8(uint32_t guestAddr, uint8_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint8_t)) || !outVal) return false;
    *outVal = *reinterpret_cast<const uint8_t*>(Translate(guestAddr));
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadU16BE(uint32_t guestAddr, uint16_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint16_t)) || !outVal) return false;
    const uint16_t beVal = *reinterpret_cast<const uint16_t*>(Translate(guestAddr));
    *outVal = Swap16(beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadU32BE(uint32_t guestAddr, uint32_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint32_t)) || !outVal) return false;
    const uint32_t beVal = *reinterpret_cast<const uint32_t*>(Translate(guestAddr));
    *outVal = Swap32(beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadU64BE(uint32_t guestAddr, uint64_t* outVal) const
{
    if (!IsValid(guestAddr, sizeof(uint64_t)) || !outVal) return false;
    const uint64_t beVal = *reinterpret_cast<const uint64_t*>(Translate(guestAddr));
    *outVal = Swap64(beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadF32BE(uint32_t guestAddr, float* outVal) const
{
    if (!IsValid(guestAddr, sizeof(float)) || !outVal) return false;
    uint32_t beVal;
    if (!ReadU32BE(guestAddr, &beVal)) return false;
    *outVal = *reinterpret_cast<const float*>(&beVal);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::ReadBytes(uint32_t guestAddr, void* outBuffer, uint32_t size) const
{
    if (!IsValid(guestAddr, size) || !outBuffer) return false;
    memcpy(outBuffer, Translate(guestAddr), size);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::WriteU8(uint32_t guestAddr, uint8_t val)
{
    if (!IsValid(guestAddr, sizeof(uint8_t))) return false;
    *reinterpret_cast<uint8_t*>(Translate(guestAddr)) = val;
    return true;
}

bool mcla::kernel::GuestMemoryHeap::WriteU16BE(uint32_t guestAddr, uint16_t val)
{
    if (!IsValid(guestAddr, sizeof(uint16_t))) return false;
    *reinterpret_cast<uint16_t*>(Translate(guestAddr)) = Swap16(val);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::WriteU32BE(uint32_t guestAddr, uint32_t val)
{
    if (!IsValid(guestAddr, sizeof(uint32_t))) return false;
    *reinterpret_cast<uint32_t*>(Translate(guestAddr)) = Swap32(val);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::WriteU64BE(uint32_t guestAddr, uint64_t val)
{
    if (!IsValid(guestAddr, sizeof(uint64_t))) return false;
    *reinterpret_cast<uint64_t*>(Translate(guestAddr)) = Swap64(val);
    return true;
}

bool mcla::kernel::GuestMemoryHeap::WriteBytes(uint32_t guestAddr, const void* src, uint32_t size)
{
    if (!IsValid(guestAddr, size) || !src) return false;
    memcpy(Translate(guestAddr), src, size);
    return true;
}

mcla::kernel::GuestMemoryHeap::~GuestMemoryHeap()
{
    Shutdown();
}

bool mcla::kernel::GuestMemoryHeap::Initialize()
{
    if (m_initialized)
        return true;

#ifdef _WIN32
    // First check if memory is already reserved/committed at the target address
    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery((void*)kBaseAddress, &mbi, sizeof(mbi)) == sizeof(mbi) && 
        (mbi.State == MEM_RESERVE || mbi.State == MEM_COMMIT))
    {
        m_base = (uint8_t*)kBaseAddress;
    }
    else
    {
        m_base = (uint8_t*)VirtualAlloc((void*)kBaseAddress, kSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (m_base == nullptr)
            m_base = (uint8_t*)VirtualAlloc(nullptr, kSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    if (m_base == nullptr)
        return false;

    DWORD oldProtect;
    VirtualProtect(m_base, 4096, PAGE_NOACCESS, &oldProtect);
#else
    // On Linux, check if memory is already mapped at the target address
    m_base = (uint8_t*)mmap((void*)kBaseAddress, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE | MAP_FIXED_NOREPLACE, -1, 0);

    if (m_base == (uint8_t*)MAP_FAILED)
        m_base = (uint8_t*)mmap((void*)kBaseAddress, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (m_base == (uint8_t*)MAP_FAILED)
        m_base = (uint8_t*)mmap(NULL, kSize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (m_base == nullptr)
        return false;

    mprotect(m_base, 4096, PROT_NONE);
#endif

    m_size = kSize;
    m_initialized = true;
    m_owned = true;
    return true;
}

bool mcla::kernel::GuestMemoryHeap::Adopt(uint8_t* base, uint64_t size)
{
    if (m_initialized)
        return true;

    if (!base || size < 4096)
        return false;

#ifdef _WIN32
    DWORD oldProtect;
    if (!VirtualProtect(base, 4096, PAGE_NOACCESS, &oldProtect))
        return false;
#else
    if (mprotect(base, 4096, PROT_NONE) != 0)
        return false;
#endif

    m_base = base;
    m_size = size;
    m_initialized = true;
    m_owned = false;
    return true;
}

void mcla::kernel::GuestMemoryHeap::Shutdown()
{
    if (!m_initialized)
        return;

    if (m_owned && m_base)
    {
#ifdef _WIN32
        VirtualFree(m_base, 0, MEM_RELEASE);
#else
        munmap(m_base, m_size);
#endif
    }

    m_base = nullptr;
    m_size = 0;
    m_initialized = false;
    m_owned = false;
}

void* mcla::kernel::GuestMemoryHeap::Translate(uint32_t guestAddr)
{
    if (!m_initialized || guestAddr >= m_size)
        return nullptr;
    return m_base + guestAddr;
}

const void* mcla::kernel::GuestMemoryHeap::Translate(uint32_t guestAddr) const
{
    if (!m_initialized || guestAddr >= m_size)
        return nullptr;
    return m_base + guestAddr;
}

uint32_t mcla::kernel::GuestMemoryHeap::MapVirtual(const void* hostPtr) const
{
    if (!m_initialized || !hostPtr)
        return 0;

    const uint8_t* base = static_cast<const uint8_t*>(hostPtr);
    if (base < m_base || base >= m_base + m_size)
        return 0;

    return static_cast<uint32_t>(base - m_base);
}

bool mcla::kernel::GuestMemoryHeap::IsValid(uint32_t guestAddr, size_t size) const
{
    if (!m_initialized || guestAddr == 0 || size == 0)
        return false;

    if (guestAddr >= m_size)
        return false;

    uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    if (end > m_size)
        return false;

    return true;
}

uint32_t mcla::kernel::GuestMemoryHeap::Alloc(size_t size, size_t alignment)
{
    if (!m_initialized)
        return 0;

    void* ptr = g_userHeap.AllocPhysical(size, alignment);
    if (!ptr)
        return 0;

    return MapVirtual(ptr);
}

void mcla::kernel::GuestMemoryHeap::Free(uint32_t guestAddr, size_t size)
{
    if (!m_initialized || guestAddr == 0)
        return;

    void* ptr = Translate(guestAddr);
    if (!ptr)
        return;

    g_userHeap.Free(ptr);
}

mcla::kernel::GuestMemoryHeap& mcla::kernel::GuestMemoryHeap::Instance()
{
    static GuestMemoryHeap instance;
    return instance;
}

mcla::kernel::Memory mcla::kernel::g_memory;
Heap g_userHeap;
