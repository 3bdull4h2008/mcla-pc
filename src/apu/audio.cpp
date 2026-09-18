#include "audio.h"
#include "logging.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>

#include <generated/ppc_xenon/ppc_config.h>
#include <generated/ppc_xenon/ppc_context.h>
#include <cpu/ppc_context.h>
#include <generated/ppc_xenon/ppc_recomp_shared.h>
#include <kernel/memory.h>
#include <cpu/guest_thread.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>
#include <mutex>
#include <thread>
#include <vector>

// M5 minimal: open an SDL3 playback stream at boot and keep it alive.
// M6: host worker thread periodically invokes the guest XAudio render
// callback (UnleashedRecomp sdl2_driver pattern) so the guest fills a
// 6ch BE float32 x 256 frame and calls XAudioSubmitRenderDriverFrame.

namespace apu {

namespace {

// Xbox 360 XAudio render-driver frame (see UnleashedRecomp apu/audio.h):
//   48 kHz, 6 ch, 32-bit BE float, 256 samples/frame, channel-major.
constexpr int kGuestSampleHz = 48000;
constexpr int kGuestChannels = 6;
constexpr int kGuestSamplesPerFrame = 256;

// Host device format requested by M5: 48 kHz stereo s16.
constexpr int kHostHz = 48000;
constexpr int kHostChannels = 2;

// Guest callback period. 256 samples @ 48 kHz = 5.33 ms; use ~8 ms as a
// safe host-side cadence (queue absorbs jitter).
constexpr auto kCallbackPeriod = std::chrono::milliseconds(8);

// Blip: 440 Hz, ~80 ms, every 2 s, ~-26 dBFS.
constexpr double kBlipHz = 440.0;
constexpr uint64_t kBlipPeriodSamples =
    static_cast<uint64_t>(kHostHz) * 2; // 2 s
constexpr uint64_t kBlipLenSamples =
    static_cast<uint64_t>(kHostHz) * 80 / 1000; // 80 ms
constexpr float kBlipAmp = 0.05f;

// ~2 s of stereo s16 queued guest audio max (drop oldest past that).
constexpr size_t kMaxQueuedSamples =
    static_cast<size_t>(kHostHz) * 2 * kHostChannels;

// Same boot-time thread-block / stack VAs the vblank ISR thread uses
// (boot_host.cpp SetupInitialContext). Guest XAudio client code reads TLS
// through r13, so the worker must publish a context with these values.
constexpr uint32_t kAudioThreadR13 = 0x8F200000u;
constexpr uint32_t kAudioThreadR1 = 0x8F000000u;

std::mutex g_mutex;
SDL_AudioStream* g_stream = nullptr;
bool g_opened = false;
bool g_subsystemOwned = false;

std::atomic<uint32_t> g_frameCount{0};
std::atomic<bool> g_shuttingDown{false};

// Interleaved stereo s16 converted from guest frames.
std::vector<int16_t> g_queue;
size_t g_queueRead = 0;

// Sample clock for blip phasing (host frames played).
uint64_t g_sampleClock = 0;

// Guest XAudio client registration (set by RegisterClient).
std::atomic<uint32_t> g_clientCallback{0};
std::atomic<uint32_t> g_clientUserData{0};
std::atomic<bool> g_workerRunning{false};
std::thread g_workerThread;
std::atomic<uint32_t> g_workerTick{0};

float LoadBeFloat(const void* p) {
    uint32_t bits = 0;
    std::memcpy(&bits, p, sizeof(bits));
    bits = SDL_Swap32(bits);
    float f = 0.0f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

void ConvertGuestFrameStereoS16(const void* samples, std::vector<int16_t>& out) {
    // Guest layout: be<float> [ch * 256 + i], 6 channels.
    // UnleashedRecomp stereo downmix:
    //   L = ch0 + ch2*0.75 + ch4
    //   R = ch1 + ch2*0.75 + ch5
    const auto* src = static_cast<const uint8_t*>(samples);
    out.resize(static_cast<size_t>(kGuestSamplesPerFrame) * kHostChannels);
    for (int i = 0; i < kGuestSamplesPerFrame; ++i) {
        const float ch0 = LoadBeFloat(src + (0 * kGuestSamplesPerFrame + i) * 4);
        const float ch1 = LoadBeFloat(src + (1 * kGuestSamplesPerFrame + i) * 4);
        const float ch2 = LoadBeFloat(src + (2 * kGuestSamplesPerFrame + i) * 4);
        const float ch4 = LoadBeFloat(src + (4 * kGuestSamplesPerFrame + i) * 4);
        const float ch5 = LoadBeFloat(src + (5 * kGuestSamplesPerFrame + i) * 4);
        const float L = ch0 + ch2 * 0.75f + ch4;
        const float R = ch1 + ch2 * 0.75f + ch5;
        const float cl = std::clamp(L, -1.0f, 1.0f);
        const float cr = std::clamp(R, -1.0f, 1.0f);
        out[static_cast<size_t>(i) * 2 + 0] =
            static_cast<int16_t>(cl * 32767.0f);
        out[static_cast<size_t>(i) * 2 + 1] =
            static_cast<int16_t>(cr * 32767.0f);
    }
}

void SDLCALL AudioCallback(void* /*userdata*/, SDL_AudioStream* stream,
                           int additional_amount, int total_amount) {
    if (g_shuttingDown.load(std::memory_order_relaxed)) {
        return;
    }

    int wantBytes = additional_amount > 0 ? additional_amount : total_amount;
    if (wantBytes <= 0) {
        wantBytes = 256 * kHostChannels * static_cast<int>(sizeof(int16_t));
    }
    // Cap and align to stereo s16 frames.
    if (wantBytes > 64 * 1024) {
        wantBytes = 64 * 1024;
    }
    wantBytes &= ~3;
    if (wantBytes <= 0) {
        return;
    }

    const int wantSamples = wantBytes / static_cast<int>(sizeof(int16_t));
    const int wantFrames = wantSamples / kHostChannels;

    std::vector<int16_t> out(static_cast<size_t>(wantSamples), 0);
    bool hadGuest = false;

    {
        std::lock_guard<std::mutex> lock(g_mutex);
        const size_t avail = g_queue.size() - g_queueRead;
        const size_t n =
            (std::min)(avail, static_cast<size_t>(wantSamples));
        if (n > 0) {
            std::memcpy(out.data(), g_queue.data() + g_queueRead,
                        n * sizeof(int16_t));
            g_queueRead += n;
            if (g_queueRead >= g_queue.size()) {
                g_queue.clear();
                g_queueRead = 0;
            }
            hadGuest = true;
        }
    }

    // Blip only into silence so we never mask real guest audio.
    if (!hadGuest) {
        const uint64_t t0 = g_sampleClock;
        g_sampleClock += static_cast<uint64_t>(wantFrames);
        const double w =
            2.0 * 3.14159265358979323846 * kBlipHz / static_cast<double>(kHostHz);
        for (int f = 0; f < wantFrames; ++f) {
            const uint64_t t = t0 + static_cast<uint64_t>(f);
            const uint64_t pos = t % kBlipPeriodSamples;
            if (pos >= kBlipLenSamples) {
                continue;
            }
            const float env =
                (pos < 240)
                    ? (static_cast<float>(pos) / 240.0f)
                    : (pos > kBlipLenSamples - 240)
                          ? (static_cast<float>(kBlipLenSamples - pos) /
                             240.0f)
                          : 1.0f;
            const float s = kBlipAmp * env *
                            static_cast<float>(std::sin(w * static_cast<double>(t)));
            const int16_t v = static_cast<int16_t>(s * 32767.0f);
            const size_t base = static_cast<size_t>(f) * kHostChannels;
            out[base + 0] = v;
            out[base + 1] = v;
        }
    }

    SDL_PutAudioStreamData(stream, out.data(), wantBytes);
}

// Host worker: periodically invoke the guest XAudio render callback so it
// fills one 6ch BE float32 x 256 frame and calls SubmitRenderDriverFrame.
// Pattern matches the vblank ISR thread in imports.cpp (standalone PPCContext
// + PPC_LOOKUP_FUNC) rather than GuestToHostFunction, which requires an
// already-published context on the calling thread.
void WorkerMain() {
    MCLA_LOG_INFO("AUDIO-WORKER start");

    while (g_workerRunning.load(std::memory_order_relaxed) &&
           !g_shuttingDown.load(std::memory_order_relaxed)) {
        const uint32_t callback = g_clientCallback.load(std::memory_order_relaxed);
        const uint32_t userData = g_clientUserData.load(std::memory_order_relaxed);

        if (callback != 0) {
            uint8_t* base = mcla::kernel::g_memory.base;
            PPCFunc* fn = mcla::kernel::g_memory.FindFunction(callback);
            if (fn) {
                PPCContext cbCtx{};
                cbCtx.r3.u64 = userData; // XAudio device callback(user_data)
                cbCtx.r13.u64 = kAudioThreadR13;
                cbCtx.r1.u64 = kAudioThreadR1;
                cbCtx.lr = 0x00FFFFFF; // dummy LR: callback must not return-to
                cbCtx.msr = 0x200A000;
                SetPPCContext(cbCtx);
                fn(cbCtx, base);

                const uint32_t tick =
                    g_workerTick.fetch_add(1, std::memory_order_relaxed) + 1;
                if (tick <= 8 || (tick % 125) == 0) {
                    MCLA_LOG_INFO("AUDIO-WORKER tick #{} cb={:08X} ud={:08X}",
                                  tick, callback, userData);
                }
            } else {
                static std::atomic<bool> s_unresolved{false};
                if (!s_unresolved.exchange(true)) {
                    MCLA_LOG_WARN("AUDIO-WORKER: callback 0x{:08X} not in "
                                  "function table yet",
                                  callback);
                }
            }
        }

        std::this_thread::sleep_for(kCallbackPeriod);
    }

    MCLA_LOG_INFO("AUDIO-WORKER stop ticks={}",
                  g_workerTick.load(std::memory_order_relaxed));
}

void StopWorker() {
    g_workerRunning.store(false, std::memory_order_relaxed);
    if (g_workerThread.joinable()) {
        g_workerThread.join();
    }
    g_clientCallback.store(0, std::memory_order_relaxed);
    g_clientUserData.store(0, std::memory_order_relaxed);
}

} // namespace

uint32_t RegisterClient(uint32_t callback, uint32_t userData) {
    MCLA_LOG_INFO("apu::RegisterClient: callback=0x{:x}, userData=0x{:x}",
                  callback, userData);
    g_clientCallback.store(callback, std::memory_order_relaxed);
    g_clientUserData.store(userData, std::memory_order_relaxed);

    if (callback != 0 && !g_workerRunning.exchange(true)) {
        g_workerThread = std::thread(WorkerMain);
        MCLA_LOG_INFO("AUDIO-WORKER spawned");
    }
    return 0x41550001; // 'AU' magic | index 1, xenia-style driver id
}

void UnregisterClient() {
    MCLA_LOG_INFO("apu::UnregisterClient");
    StopWorker();
}

void SubmitFrames(void* samples) {
    const uint32_t n = g_frameCount.fetch_add(1, std::memory_order_relaxed) + 1;
    // Cap log so a 50 Hz submitter cannot flood the soak log.
    if (n <= 8 || (n % 50) == 0) {
        MCLA_LOG_INFO("AUDIO-FRAME #{} samples={}", n,
                      samples ? "yes" : "null");
    }
    if (!samples) {
        return;
    }

    std::vector<int16_t> converted;
    ConvertGuestFrameStereoS16(samples, converted);

    std::lock_guard<std::mutex> lock(g_mutex);
    // Drop oldest if the consumer is behind (~2 s cap).
    size_t queued = g_queue.size() - g_queueRead;
    if (queued > kMaxQueuedSamples) {
        const size_t drop = queued - kMaxQueuedSamples;
        g_queueRead += drop;
        queued = kMaxQueuedSamples;
    }
    if (g_queueRead > 0) {
        g_queue.erase(g_queue.begin(),
                      g_queue.begin() + static_cast<std::ptrdiff_t>(g_queueRead));
        g_queueRead = 0;
    }
    g_queue.insert(g_queue.end(), converted.begin(), converted.end());
}

void Init() {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        if (g_opened) {
            return;
        }
        g_shuttingDown.store(false, std::memory_order_relaxed);
        g_sampleClock = 0;

        if (!SDL_WasInit(SDL_INIT_AUDIO)) {
            if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
                MCLA_LOG_ERROR(
                    "AUDIO-OPEN failed: SDL_InitSubSystem(AUDIO): {}",
                    SDL_GetError());
                return;
            }
            g_subsystemOwned = true;
        }

        SDL_AudioSpec spec;
        SDL_zero(spec);
        spec.format = SDL_AUDIO_S16;
        spec.channels = static_cast<Uint8>(kHostChannels);
        spec.freq = kHostHz;

        g_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
                                             &spec, AudioCallback, nullptr);
        if (!g_stream) {
            MCLA_LOG_ERROR("AUDIO-OPEN failed: SDL_OpenAudioDeviceStream: {}",
                           SDL_GetError());
            if (g_subsystemOwned) {
                SDL_QuitSubSystem(SDL_INIT_AUDIO);
                g_subsystemOwned = false;
            }
            return;
        }

        if (!SDL_ResumeAudioStreamDevice(g_stream)) {
            MCLA_LOG_ERROR("AUDIO-OPEN failed: SDL_ResumeAudioStreamDevice: {}",
                           SDL_GetError());
            SDL_DestroyAudioStream(g_stream);
            g_stream = nullptr;
            if (g_subsystemOwned) {
                SDL_QuitSubSystem(SDL_INIT_AUDIO);
                g_subsystemOwned = false;
            }
            return;
        }

        g_opened = true;
        MCLA_LOG_INFO(
            "AUDIO-OPEN ok: {}Hz ch={} format=s16 blip=440Hz/2s stream={}",
            kHostHz, kHostChannels, static_cast<const void*>(g_stream));
    }

    // Worker may already be running if RegisterClient raced ahead of Init
    // (guest can register before the host opens the device). Only spawn if
    // a callback is already stored and no thread exists.
    if (g_clientCallback.load(std::memory_order_relaxed) != 0 &&
        !g_workerRunning.exchange(true)) {
        g_workerThread = std::thread(WorkerMain);
        MCLA_LOG_INFO("AUDIO-WORKER spawned (late, post-Init)");
    }
}

void Shutdown() {
    g_shuttingDown.store(true, std::memory_order_relaxed);
    StopWorker();

    SDL_AudioStream* s = nullptr;
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        s = g_stream;
        g_stream = nullptr;
        g_opened = false;
        g_queue.clear();
        g_queueRead = 0;
    }
    if (s) {
        SDL_PauseAudioStreamDevice(s);
        SDL_DestroyAudioStream(s);
    }
    if (g_subsystemOwned) {
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        g_subsystemOwned = false;
    }
    MCLA_LOG_INFO("apu::Shutdown frames={} ticks={}",
                  g_frameCount.load(std::memory_order_relaxed),
                  g_workerTick.load(std::memory_order_relaxed));
}

} // namespace apu
