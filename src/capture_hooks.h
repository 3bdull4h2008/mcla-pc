#pragma once

namespace rex::memory { class Memory; }

#include "guest_memory.h"
#include "frame_trace.h"
#include "native_types.h"
#include "native_renderer.h"

#include <rex/ppc/context.h>
#include <filesystem>
#include <unordered_set>
#include <memory>

namespace mcla::native {

class DrawPacketAccumulator {
public:
    DrawPacketAccumulator();
    ~DrawPacketAccumulator();

    void Initialize(rex::memory::Memory* memory = nullptr);
    void SetCaptureEnabled(bool enabled, const std::filesystem::path& tracePath = {});

    // Called from sub_8241ABB8 hook (viewport / render target capture)
    void OnStateSetup(::MclaGpuContext* gpuCtx, uint32_t srcStateAddr);

    // Called from sub_82420BA8 hook (draw call builder capture)
    void OnDrawBuild(::MclaGpuContext* gpuCtx, ::PPCContext& ctx);

    // Called from sub_8241BD08 hook (GfxCmdBufSubmit kick)
    void OnSubmit(::MclaGpuContext* gpuCtx, uint32_t r4Param);

    // Called from VdSwap (end of frame)
    void OnFrameEnd();

    uint64_t GetCapturedDrawCount() const { return m_totalCapturedDraws; }
    uint64_t GetValidPacketCount() const { return m_validPackets; }
    uint64_t GetInvalidPacketCount() const { return m_invalidPackets; }
    uint64_t GetDroppedPacketCount() const { return m_droppedPackets; }

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

    // Transient context state captured between setup and draw
    DrawPacket m_currentPacket{};
    bool m_lastCaptureFailed = false;

    // Runtime shader-microcode dumping (Phase 1 / Phase 5 research aid).
    // Each unique VS/PS program guest address is dumped once, so captured
    // draws can be re-parsed offline with XenosRecomp-style container structs.
    void DumpShaderIfNew(uint32_t guestAddr, bool isVertex, const std::filesystem::path& dir);
    std::unordered_set<uint32_t> m_dumpedVs;
    std::unordered_set<uint32_t> m_dumpedPs;
    std::filesystem::path m_shaderDumpDir;
};

DrawPacketAccumulator* GetDrawAccumulator();

} // namespace mcla::native





