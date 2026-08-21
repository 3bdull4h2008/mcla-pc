#pragma once

#include "app.h"
#include <string_view>

void mcla_ApplyPatches(mcla::App::FunctionDispatcher* dispatcher);

bool BisectGroupEnabled(std::string_view group);

mcla::App::FunctionDispatcher::PPCFunc* mcla_DetourImportThunk(uint8_t* thunk, mcla::App::FunctionDispatcher::PPCFunc* hook);

extern "C" void sub_82554080_stub(mcla::PPCContext& ctx, uint8_t* base);
extern "C" void hk_press_start_shim(mcla::PPCContext& ctx, uint8_t* base);