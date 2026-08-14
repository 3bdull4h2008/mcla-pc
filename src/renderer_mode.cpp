#include "renderer_mode.h"
#include "cvar.h"

#include <atomic>
#include <string_view>

namespace mcla::renderer {
namespace {

std::atomic<uint64_t> g_frames = 0;
std::atomic<uint64_t> g_stateSetups = 0;
std::atomic<uint64_t> g_drawBuilds = 0;
std::atomic<uint64_t> g_submits = 0;
std::atomic<uint64_t> g_swaps = 0;
std::atomic<uint64_t> g_invalidModeSelections = 0;

}  // namespace

RendererMode GetRendererMode() {
    const std::string_view mode = MCLA_CVAR_GET_STRING(renderer_mode);
    if (mode == "legacy") return RendererMode::Legacy;
    if (mode == "capture") return RendererMode::Capture;
    if (mode == "native") return RendererMode::Native;

    g_invalidModeSelections.fetch_add(1, std::memory_order_relaxed);
    return RendererMode::Legacy;
}

const char* RendererModeName(RendererMode mode) {
    switch (mode) {
        case RendererMode::Legacy: return "legacy";
        case RendererMode::Capture: return "capture";
        case RendererMode::Native: return "native";
    }
    return "legacy";
}

TraceMode GetTraceMode() {
    const std::string_view mode = MCLA_CVAR_GET_STRING(native_renderer_trace);
    if (mode == "frames") return TraceMode::Frames;
    if (mode == "all") return TraceMode::All;
    return TraceMode::Off;
}

const char* TraceModeName(TraceMode mode) {
    switch (mode) {
        case TraceMode::Off: return "off";
        case TraceMode::Frames: return "frames";
        case TraceMode::All: return "all";
    }
    return "off";
}

void RecordStateSetup() {
    g_stateSetups.fetch_add(1, std::memory_order_relaxed);
}

void RecordDrawBuild() {
    g_drawBuilds.fetch_add(1, std::memory_order_relaxed);
}

void RecordSubmit() {
    g_submits.fetch_add(1, std::memory_order_relaxed);
}

FrameCounters GetFrameCounters() {
    return {
        g_frames.load(std::memory_order_relaxed),
        g_stateSetups.load(std::memory_order_relaxed),
        g_drawBuilds.load(std::memory_order_relaxed),
        g_submits.load(std::memory_order_relaxed),
        g_swaps.load(std::memory_order_relaxed),
        g_invalidModeSelections.load(std::memory_order_relaxed),
    };
}

void RecordFramePresented() {
    const uint64_t frame = g_frames.fetch_add(1, std::memory_order_relaxed) + 1;
    g_swaps.fetch_add(1, std::memory_order_relaxed);

    if (frame % 120 != 0) return;

    const FrameCounters counters = GetFrameCounters();
    REXLOG_INFO("Renderer frame {} mode={} state={} draws={} submits={} swaps={} invalid_modes={}",
                counters.frames, RendererModeName(GetRendererMode()),
                counters.stateSetups, counters.drawBuilds, counters.submits,
                counters.swaps, counters.invalidModeSelections);
}

}  // namespace mcla::renderer