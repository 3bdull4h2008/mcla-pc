#pragma once

// Compatibility shim (reorg Phase 0): the canonical header is
// <kernel/guest_thread.h> (has the threadCreated fix). New code must include
// that directly; this shim keeps the 3 legacy <cpu/guest_thread.h> users
// (apu/audio.cpp, kernel/imports.cpp, kernel/xam.cpp) building.
#include <kernel/guest_thread.h>
