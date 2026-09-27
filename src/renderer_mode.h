#pragma once

#include <cstdint>
#include "cvar.h"

namespace mcla::renderer {

// The active mode comes from the renderer_mode CVar, whose registered default
// is "native" (src/renderer_mode.cpp:8); legacy/capture stay selectable as opts.
enum class RendererMode : uint8_t {
    Legacy,
    Capture,
    Native,
};

RendererMode GetRendererMode();
const char* RendererModeName(RendererMode mode);

// Control how much capture data is written. Reads the native_renderer_trace
// CVar, but that CVar is never registered, so GetTraceMode is always Off.
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

