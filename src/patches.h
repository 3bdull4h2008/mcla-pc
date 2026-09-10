#pragma once

#include "app.h"
#include <string_view>

void mcla_ApplyPatches(mcla::App::FunctionDispatcher* dispatcher);

bool BisectGroupEnabled(std::string_view group);

// Session 73: tiny-slab fill-on-alloc census. The guest allocator
// (sub_821DE9D8) memsets every returned element with 0xCD before handing it
// out, so a 0xCDCDCDCD field read later is a field its owner never wrote.
// This resolves which recorded allocation contains `addr` so poison
// use-sites can name the producer. Returns false when no recorded
// allocation covers addr (ring wrapped or not a tiny-slab object).
bool mcla_SlimTslabFind(uint32_t addr, uint32_t* outElem,
                        uint32_t* outCallerLr, uint32_t* outElemsize);

mcla::App::FunctionDispatcher::PPCFunc* mcla_DetourImportThunk(uint8_t* thunk, mcla::App::FunctionDispatcher::PPCFunc* hook);

extern "C" void sub_82554080_stub(mcla::PPCContext& ctx, uint8_t* base);
extern "C" void hk_press_start_shim(mcla::PPCContext& ctx, uint8_t* base);