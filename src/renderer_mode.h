#pragma once

#include <cstdint>
#include "cvar.h"

namespace mcla::renderer {

// The mode is intentionally conservative while the native renderer is built.
// See NATIVE_GPU_REBUILD_PLAN.md for the promotion criteria.
enum class RendererMode : uint8_t {
    Legacy,
    Capture,
    Native,
};

RendererMode GetRendererMode();
const char* RendererModeName(RendererMode mode);

// Control how much capture data is written. Mirrors the native_renderer_trace
// CVar. Tracing only takes effect when the renderer mode is Capture.
enum class TraceMode : uint8_t {
    Off,
    Frames,
    All,
};

TraceMode GetTraceMode();
const char* TraceModeName(TraceMode mode);

struct FrameCounters {
    uint64_t frames = 0;
    uint64_t stateSetups = 0;
    uint64_t drawBuilds = 0;
    uint64_t submits = 0;
    uint64_t swaps = 0;
    uint64_t invalidModeSelections = 0;
};

void RecordStateSetup();
void RecordDrawBuild();
void RecordSubmit();
void RecordFramePresented();
FrameCounters GetFrameCounters();

}  // namespace mcla::renderer

