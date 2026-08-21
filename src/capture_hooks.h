#pragma once

#include "guest_memory.h"
#include "frame_trace.h"
#include "native_types.h"
#include "native_renderer.h"

#include <filesystem>
#include <unordered_set>
#include <memory>

namespace mcla::native {

class DrawPacketAccumulator {
public:
    DrawPacketAccumulator();
    ~DrawPacketAccumulator();

    void Initialize(uint8_t* memoryBase = nullptr, uint32_t memorySize = 0);
    void SetCaptureEnabled(bool enabled, const std::filesystem::path& tracePath = {});

    void OnStateSetup(::MclaGpuContext* gpuCtx, uint32_t srcStateAddr);
    void OnDrawBuild(::MclaGpuContext* gpuCtx, PPCContext& ctx);
    void OnSubmit(::MclaGpuContext* gpuCtx, uint32_t r4Param);
    void OnFrameEnd();

    uint64_t GetCapturedDrawCount() const { return m_totalCapturedDraws; }
    uint64_t GetValidPacketCount() const { return m_validPackets; }
    uint64_t GetInvalidPacketCount() const { return m_invalidPackets; }
    uint64_t GetDroppedPacketCount() const { return m_droppedPackets; }

    bool LastPacket(const DrawPacket*& outPacket) const {
        if (!m_lastPacketValid) return false;
        outPacket = &m_lastPacket;
        return true;
    }

    bool ReadGuestRange(uint32_t address, uint32_t size, void* dst) const {
        return m_memoryView.ReadBytes(address, dst, size);
    }

    GuestMemoryView& GetMemoryView() { return m_memoryView; }

private:
    uint64_t ComputeStateHash(const DrawPacket& packet) const;
    bool ValidatePacket(DrawPacket& packet) const;

    GuestMemoryView m_memoryView;
    FrameTraceWriter m_writer;
    bool m_captureEnabled = false;

    uint64_t m_frameIndex = 0;
    uint32_t m_sequenceNum = 0;
    uint32_t m_drawInFrame = 0;

    uint64_t m_totalCapturedDraws = 0;
    uint64_t m_droppedPackets = 0;
    uint64_t m_validPackets = 0;
    uint64_t m_invalidPackets = 0;

    DrawPacket m_currentPacket{};
    bool m_lastCaptureFailed = false;

    DrawPacket m_lastPacket{};
    bool m_lastPacketValid = false;

    void DumpShaderIfNew(uint32_t guestAddr, bool isVertex, const std::filesystem::path& dir);
    std::unordered_set<uint32_t> m_dumpedVs;
    std::unordered_set<uint32_t> m_dumpedPs;
    std::filesystem::path m_shaderDumpDir;

    struct GuestDumpKey {
        uint32_t address;
        uint32_t size;
        bool operator==(const GuestDumpKey&) const = default;
    };
    struct GuestDumpKeyHash {
        size_t operator()(const GuestDumpKey& k) const {
            return (static_cast<size_t>(k.address) << 20) ^ k.size;
        }
    };
    void DumpPacketGuestMemory(const DrawPacket& packet, const std::filesystem::path& dir);
    std::unordered_set<GuestDumpKey, GuestDumpKeyHash> m_dumpedRanges;
    std::filesystem::path m_memDumpDir;
};

DrawPacketAccumulator* GetDrawAccumulator();

} // namespace mcla::native