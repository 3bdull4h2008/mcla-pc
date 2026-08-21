#pragma once

#define NOMINMAX

#if defined(_WIN32)
#include <windows.h>
#include <ShlObj_core.h>
#include <wrl/client.h>

using Microsoft::WRL::ComPtr;
#endif

#include <algorithm>
#include <mutex>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <chrono>
#include <span>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <set>
#include <fmt/core.h>
#include <list>
#include <semaphore>
#include <numeric>
#include <charconv>

#include "ppc_context.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include <toml++/toml.hpp>
// #include <zstd.h>  // TODO: install zstd
// #include <stb_image.h>
// #include <blockingconcurrentqueue.h>
#include <SDL3/SDL.h>
// #include <SDL3/SDL_mixer.h>
// #include <imgui.h>
// #include <imgui_internal.h>
// #include <backends/imgui_impl_sdl2.h>
#include <o1heap.h>
#include <cstddef>
#include <smolv.h>
#include <set>
#include <fmt/core.h>
#include <list>
#include <semaphore>
#include <numeric>
#include <charconv>

#include "framework.h"
#include "mutex.h"

#ifndef _WIN32
#include <sys/mman.h>
#endif