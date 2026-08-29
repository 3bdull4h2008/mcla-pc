#pragma once

#include <cstdint>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <optional>
#include <array>

#include "native_types.h"
#include "guest_memory.h"

namespace mcla::gpu {

struct RenderCommand {
    enum class Type : uint8_t {
        Draw,
        Present,
        StateSetup,
    } type;

    uint32_t sequence = 0;
    uint32_t deviceVA = 0;

    struct DrawData {
        uint32_t primTypeFlags = 0;
        std::array<std::array<uint32_t, 4>, 2> vbDesc{};
        std::array<uint32_t, 4> ibDesc{};
        uint32_t ibBase = 0;
        uint32_t ibCounts = 0;
        uint32_t indexWidthBits = 0;
        std::array<uint32_t, 6> dirtyMask{};
        std::vector<uint32_t> shadowBlock;
    } draw;

    struct PresentData {
        uint32_t fbAddr = 0;
        uint32_t bbIdx = 0;
        uint32_t bbCount = 0;
        uint32_t bbBase = 0;
    } present;

    struct StateSetupData {
        uint32_t srcStateVA = 0;
        std::array<uint32_t, 5> rbSurfaceInfo{};
    } stateSetup;
};

class RenderCommandQueue {
public:
    RenderCommandQueue() = default;
    ~RenderCommandQueue();

    void Enqueue(RenderCommand&& cmd);
    std::optional<RenderCommand> Dequeue();
    void Wake();
    void Shutdown();

    size_t PendingCount() const;
    bool IsShutdown() const;

private:
    mutable std::mutex m_mutex;
    std::condition_variable m_cv;
    std::vector<RenderCommand> m_queue;
    std::atomic<bool> m_shutdown{false};
    std::atomic<uint32_t> m_sequence{0};
};

class RenderThread {
public:
    RenderThread();
    ~RenderThread();

    bool Start(void* hwnd, uint32_t width, uint32_t height);
    void Stop();
    void EnqueueCommand(RenderCommand&& cmd);

    static RenderThread& Instance();

private:
    void ThreadMain(void* hwnd, uint32_t width, uint32_t height);

    std::thread m_thread;
    std::atomic<bool> m_running{false};
    RenderCommandQueue m_queue;
};

} // namespace mcla::gpu