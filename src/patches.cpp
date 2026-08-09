#include "patches.h"
#include "gpu_mmio.h"
#include "native_renderer.h"
#include "guest_memory.h"
#include "generated/default/mcla_init.h"
#include <rex/logging.h>
#include <rex/runtime.h>
#include <rex/graphics/graphics_system.h>
#include <rex/graphics/register_file.h>
#include <rex/system/xthread.h>
#include <rex/system/thread_state.h>
#include <rex/filesystem/vfs.h>
#include <rex/filesystem/entry.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <unordered_set>
#include <vector>

#include <windows.h>

static rex::runtime::FunctionDispatcher* g_dispatcher = nullptr;
static uint8_t* g_virtual_membase = nullptr;  // guestâ†’host translation base

// Save original bytes of native XamInputGetState for detour
static uint8_t g_original_native_bytes[12];
static uint8_t g_native_detour_code[12];

// â”€â”€ Pulsed Start input injection â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
// The Press Start screen waits for a genuine press EDGE, not a permanently
// held button.  Holding Start continuously never transitions it.  Pulse the
// injection: hold the button for |kStartHoldMs|, release for |kStartReleaseMs|,
// repeat.  Wall-clock based so both the PPC import-thunk hook and the native
// detour stay coherent regardless of which path the game polls.
namespace {
constexpr std::chrono::milliseconds kStartHoldMs(1000);
constexpr std::chrono::milliseconds kStartReleaseMs(1000);

bool StartPulseActive() {
    static bool held = false;
    static auto phase_end = std::chrono::steady_clock::now() + kStartHoldMs;
    const auto now = std::chrono::steady_clock::now();
    if (now >= phase_end) {
        held = !held;
        phase_end = now + (held ? kStartHoldMs : kStartReleaseMs);
    }
    return held;
}
}  // namespace

// The native XamInputGetState hook â€” overwrites the DLL function entry to
// intercept ALL call paths (generated code, JIT, and syscall).
// Prototype: the native function is called as __fastcall (RCX=port, RDX=buffer).
// We save/restore the original bytes to call through, then reapply the hook.
static void* g_native_XamInputGetState_func = nullptr;

// â”€â”€ Native function detour helpers â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
// Saves |size| bytes from |target| into |save_buf| and writes a 12-byte
// "mov rax, hook; jmp rax" detour over |target|.  Returns true on success.
static bool InstallNativeDetour(void* target, void* hook,
                                uint8_t* save_buf, size_t size) {
    if (!target || size < 12) return false;
    DWORD old;
    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old))
        return false;
    memcpy(save_buf, target, 12);
    uint8_t* p = (uint8_t*)target;
    p[0] = 0x48;   // REX.W
    p[1] = 0xB8;   // MOV RAX, imm64
    memcpy(p + 2, &hook, sizeof(void*));
    p[10] = 0xFF;  // JMP
    p[11] = 0xE0;  // RAX
    FlushInstructionCache(GetCurrentProcess(), target, size);
    DWORD dummy;
    VirtualProtect(target, size, PAGE_EXECUTE_READ, &dummy);
    return true;
}

// Restores |size| bytes of |target| from |save_buf| (removes the detour).
static void RemoveNativeDetour(void* target, const uint8_t* save_buf,
                               size_t size) {
    DWORD old;
    VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old);
    memcpy(target, save_buf, size < 12 ? size : 12);
    FlushInstructionCache(GetCurrentProcess(), target, size);
    DWORD dummy;
    VirtualProtect(target, size, PAGE_EXECUTE_READ, &dummy);
}

// The native detour hook.  Called from the overwritten function entry.
// The real XamInputGetState takes (DWORD port, XINPUT_STATE* state).
// We inject Start into the output buffer and return success.
// NOTE: We're NOT calling through to the original â€” returning 0 with
// just Start set should be sufficient for the Press Start handler.
extern "C" DWORD __fastcall hk_native_XamInputGetState(DWORD port, void* state) {
    static int callCount = 0;
    callCount++;
    
    if (callCount <= 10) {
        REXLOG_INFO("hk_native_XamInputGetState[{}]: port={} state=0x{:p}", 
                    callCount, port, state);
    }
    
    if (state) {
        // Pulsed injection: only press Start while the pulse is active.
        uint16_t* buttons = (uint16_t*)((uint8_t*)state + 4);
        uint16_t old = *buttons;
        if (StartPulseActive()) {
            *buttons |= 0x0010;   // XINPUT_GAMEPAD_START
        } else {
            *buttons &= static_cast<uint16_t>(~0x0010u);  // release
        }
        if (callCount <= 5) {
            REXLOG_INFO("hk_native_XamInputGetState[{}]: Start held={} (old=0x{:04X} new=0x{:04X})", 
                        callCount, StartPulseActive(), old, *buttons);
        }
    }
    return 0;  // ERROR_SUCCESS
}

// Trampoline wrapper that restores original bytes, calls the real function,
// re-applies the hook, and returns the result.  Called from the PPC hook
// when it needs to pass through to the real DLL function.
// NOTE: This is safely used from the PPC hook path because g_original_XamInputGetState
// returns the hotpatch thunk address (the original JMP), so the PPC hook's call
// to g_original_XamInputGetState already goes through the hotpatch thunk, not through
// the actual function entry where our detour is applied.
extern "C" DWORD __fastcall CallOriginalNativeXamInputGetState(DWORD port, void* state) {
    void* target = g_native_XamInputGetState_func;
    if (!target) return 0;
    
    RemoveNativeDetour(target, g_original_native_bytes, 12);
    DWORD ret = ((DWORD(__fastcall*)(DWORD, void*))target)(port, state);
    InstallNativeDetour(target, (void*)hk_native_XamInputGetState,
                        g_original_native_bytes, 12);
    return ret;
}

// The generated recompiled code calls __imp__KeWaitForSingleObject
// via a DIRECT relative call to the import-library JMP thunk, which
// does jmp qword ptr [IAT_entry].  SetFunction only intercepts
// INDIRECT calls through the dispatcher table; direct calls bypass
// it entirely.  We overwrite the JMP thunk itself with a detour
// so ALL calls (direct and indirect) hit our hook.
static PPCFunc* g_original_KeWait = nullptr;
static PPCFunc* g_original_XamInputGetState = nullptr;
static PPCFunc* g_original_NtCreateFile = nullptr;

// Overwrite an import-library JMP thunk ("jmp [rip+disp]") with a
// 12-byte "mov rax, imm64; jmp rax" detour and return the target
// of the original JMP (the real function in the DLL).
// Returns nullptr on failure.
PPCFunc* mcla_DetourImportThunk(uint8_t* thunk, PPCFunc* hook) {
    if (!thunk) return nullptr;
    // The standard MSVC import jmp thunk: FF 25 xx xx xx xx
    // Reads the target address from IAT at [thunk+6+xx].
    if (thunk[0] != 0xFF || thunk[1] != 0x25) {
        REXLOG_ERROR("DetourImportThunk: unexpected thunk bytes at %p: %02X %02X",
                     (void*)thunk, thunk[0], thunk[1]);
        return nullptr;
    }
    int32_t disp = *reinterpret_cast<int32_t*>(thunk + 2);
    void** iat_entry = reinterpret_cast<void**>(thunk + 6 + disp);
    void* original_func = *iat_entry;
    if (!original_func) return nullptr;

    DWORD old;
    VirtualProtect(thunk, 12, PAGE_EXECUTE_READWRITE, &old);
    thunk[0] = 0x48;  // REX.W
    thunk[1] = 0xB8;  // MOV RAX, imm64
    memcpy(thunk + 2, &hook, sizeof(void*));
    thunk[10] = 0xFF; // JMP
    thunk[11] = 0xE0; // RAX
    FlushInstructionCache(GetCurrentProcess(), thunk, 12);
    VirtualProtect(thunk, 12, PAGE_EXECUTE_READ, &old);

    REXLOG_INFO("DetourImportThunk: 0x{:p} -> 0x{:p} (original DLL func = 0x{:p})",
                (void*)thunk, (void*)hook, original_func);
    return reinterpret_cast<PPCFunc*>(original_func);
}

// Wall-clock start time for physics timer decoupling.
// All 4 timer DPCs compute delta = REX_QUERY_TIMEBASE() - stored_timebase (fixed at boot).
// When VSync is removed the guest CPU runs faster, so the timebase advances faster
// per wall-clock second, causing physics overspeed.  We replace the timebase delta
// with actual wall-clock elapsed seconds.
static const std::chrono::steady_clock::time_point g_wallClockStart = std::chrono::steady_clock::now();

// Returns a uint64 containing the IEEE 754 double bits of (float)elapsed_seconds,
// matching the format the game's timer handlers expect (fcfidâ†’frspâ†’fmuls chain).
static uint64_t GetWallClockDeltaBits() {
    auto now = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(now - g_wallClockStart).count();
    float elapsedF = static_cast<float>(elapsed);
    double result = static_cast<double>(elapsedF);
    uint64_t bits;
    std::memcpy(&bits, &result, sizeof(bits));
    return bits;
}

// Timer name string constants used by the game's 4 kernel timer DPCs.
// Loaded from *(base + 0x822A0xxx) in the original code via lis+addi.
static constexpr uint32_t TIMER_STR_30690 = 0x822A0E28;
static constexpr uint32_t TIMER_STR_30770 = 0x822A0E3C;
static constexpr uint32_t TIMER_STR_30850 = 0x822A0E50;
static constexpr uint32_t TIMER_STR_30930 = 0x822A0E64;
static constexpr uint32_t TIMER_STR_30A18 = 0x822A0E78;

// Timer-manager object pointer.  The game reads this at sub_82130690
// via "lwz r10,2448(r11)" where r11 = 0x82C30000 (lis -32125).
// Non-null â†’ timers are armed and sub_821BE860 is used as handler.
// Null     â†’ timers are disarmed and sub_823D9750 is used instead.
static constexpr uint32_t TIMER_OBJ_PTR  = 0x82C30990;
static constexpr uint32_t TIMEBASE_STORE = 0x82C30AB0;  // stored_timebase at *(r9+2736)

// Forward declaration for the "Press Start bypassed" flag
static bool g_press_start_bypassed;

// Shared helper for the 4 timer-DPC hooks.
static void TimerHookDispatch(PPCContext& ctx, uint8_t* base,
                              uint32_t nameStr, bool returnOne) {
    uint32_t timerObj = REX_LOAD_U32(TIMER_OBJ_PTR);
    uint64_t deltaBits = GetWallClockDeltaBits();

    // Keep stored_timebase in sync so any non-hooked code also gets
    // reasonable deltas when it reads timebase_now - stored_timebase.
    REX_STORE_U64(TIMEBASE_STORE, REX_QUERY_TIMEBASE());

    static int timerCount = 0;
    timerCount++;

    if (timerObj) {
        if (timerCount <= 10) {
            REXLOG_INFO("Timer ARMED: obj=0x{:08X} name=0x{:08X} deltaBits=0x{:016X}",
                        timerObj, nameStr, deltaBits);
        }
        ctx.r3.u64 = timerObj;
        ctx.r4.u64 = nameStr;
        ctx.r5.u64 = deltaBits;
        sub_821BE860(ctx, base);
        if (returnOne)
            ctx.r3.u64 = 1;
    } else {
        if (timerCount <= 10) {
            REXLOG_INFO("Timer UNARMED: name=0x{:08X} deltaBits=0x{:016X} origR3=0x{:08X}",
                        nameStr, deltaBits, ctx.r3.u32);
        }
        uint32_t origR3 = ctx.r3.u32;
        ctx.r3.u64 = nameStr;
        ctx.r4.u64 = deltaBits;
        ctx.r5.u64 = origR3;
        sub_823D9750(ctx, base);
    }
}

// Forward declarations
void hk_KeWaitForSingleObject(PPCContext& ctx, uint8_t* base);
void hk_XamInputGetState(PPCContext& ctx, uint8_t* base);
void hk_NtCreateFile(PPCContext& ctx, uint8_t* base);
void hk_sub_82130690(PPCContext& ctx, uint8_t* base);
void hk_sub_82130770(PPCContext& ctx, uint8_t* base);
void hk_sub_82130850(PPCContext& ctx, uint8_t* base);
void hk_sub_82130930(PPCContext& ctx, uint8_t* base);
void hk_sub_82130A18(PPCContext& ctx, uint8_t* base);
void hk_sub_822A3998(PPCContext& ctx, uint8_t* base);
void hk_sub_82554E20(PPCContext& ctx, uint8_t* base);
static PPCFunc* g_orig_sub_82554E20 = nullptr;

// â”€â”€ Kernel Timer DPC hooks â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
// All four follow the same structure:
//   delta = REX_QUERY_TIMEBASE() - stored_timebase  â†’  (float)delta * freq
// We replace the timebase delta with wall-clock elapsed seconds so physics
// runs at the correct speed regardless of guest-CPU execution rate.

REX_FUNC(hk_sub_82130690) {
    TimerHookDispatch(ctx, base, TIMER_STR_30690, false);
}

REX_FUNC(hk_sub_82130770) {
    TimerHookDispatch(ctx, base, TIMER_STR_30770, false);
}

REX_FUNC(hk_sub_82130850) {
    TimerHookDispatch(ctx, base, TIMER_STR_30850, false);
}

REX_FUNC(hk_sub_82130930) {
    TimerHookDispatch(ctx, base, TIMER_STR_30930, true /* returns r3=1 */);
}

REX_FUNC(hk_sub_82130A18) {
    TimerHookDispatch(ctx, base, TIMER_STR_30A18, false);
}

static uint32_t g_press_start_shim_thunk = 0;

void mcla_ApplyPatches(rex::runtime::FunctionDispatcher* dispatcher) {
    g_dispatcher = dispatcher;

    // Register function table entry for 0x82554080 (start button handler).
    // This address is not in the auto-generated function table, so it must
    // be explicitly added to prevent a fatal dispatch error.
    dispatcher->SetFunction(0x82554080, sub_82554080_stub);

    // Hook KeWaitForSingleObject to skip the display-sync semaphore wait.
    // The game's VSync handler (sub_823EC8C8) waits on semaphore at
    // 0xFFFF8234D9B8; when it's the wait-object, return immediately so
    // the game loop runs at uncapped speed.  All other waits pass through.
    //
    // The generated recompiled code calls __imp__KeWaitForSingleObject
    // via a DIRECT relative call (not through the dispatcher table), so
    // SetFunction alone does NOT intercept these calls.  We overwrite
    // the import-library JMP thunk itself with a detour so that BOTH
    // direct calls (generated code) and indirect calls (dispatcher) hit
    // our hook.
    //
    // Also set the dispatcher entry so indirect calls route correctly.
    dispatcher->SetFunction(0x827BD5A4, hk_KeWaitForSingleObject);
    g_original_KeWait = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(&__imp__KeWaitForSingleObject)),
        hk_KeWaitForSingleObject);
    if (!g_original_KeWait) {
        REXLOG_ERROR("Failed to detour __imp__KeWaitForSingleObject");
    }

    // Hook NtCreateFile to unblock the RAGE city-art FS wedge.  The guest
    // opens t:\mc4\art\city\*.loc (RPF3 archives) that the host game_data
    // tree cannot serve, so the VFS returns 0xc000000f and boot wedges on
    // the splash.  We detour the import thunk (same approach as KeWait:
    // direct generated-code calls hit the detour, dispatcher calls hit the
    // SetFunction entry) so we can materialize empty host stubs under the
    // update: root before the real NtCreateFile runs.  This is a
    // game-data/legacy-path accommodation, not native-GPU work.
    dispatcher->SetFunction(0x827BD934, hk_NtCreateFile);
    g_original_NtCreateFile = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(&__imp__NtCreateFile)),
        hk_NtCreateFile);
    if (!g_original_NtCreateFile) {
        REXLOG_ERROR("Failed to detour __imp__NtCreateFile");
    }
    
    // Hook XamInputGetState â€” same approach as KeWait: overwrite the
    // import-library JMP thunk so ALL calls (direct generated-code calls,
    // dispatcher calls, and JIT calls) intercept through our hook.
    // The hook calls the original then injects Start button press.
    dispatcher->SetFunction(0x827BDC64, hk_XamInputGetState);
    g_original_XamInputGetState = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(&__imp__XamInputGetState)),
        hk_XamInputGetState);
    if (!g_original_XamInputGetState) {
        REXLOG_ERROR("Failed to detour __imp__XamInputGetState");
    } else {
        // Capture membase for guestâ†’host address translation
        auto* ks = rex::system::kernel_state();
        if (ks) {
            g_virtual_membase = ks->memory()->virtual_membase();
        }

        // The IAT entry points to a HOTPATCH thunk: E9 xx xx xx xx (jmp rel32).
        // Follow the JMP to find the ACTUAL native function for our detour.
        uint8_t* hotpatch_thunk = (uint8_t*)g_original_XamInputGetState;
        if (hotpatch_thunk[0] == 0xE9) {
            int32_t rel = *reinterpret_cast<int32_t*>(hotpatch_thunk + 1);
            g_native_XamInputGetState_func = (void*)(hotpatch_thunk + 5 + rel);
            REXLOG_INFO("XamInputGetState hotpatch thunk at 0x{:p} -> actual func at 0x{:p}",
                        (void*)hotpatch_thunk, g_native_XamInputGetState_func);
            
            // Dump first 128 bytes of actual function to find the CALL
        // to the real native XamInputGetState inside the wrapper.
        uint8_t* af = (uint8_t*)g_native_XamInputGetState_func;
        REXLOG_INFO("Actual func first 128 bytes: "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                    "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X}",
                    af[0], af[1], af[2], af[3], af[4], af[5], af[6], af[7],
                    af[8], af[9], af[10], af[11], af[12], af[13], af[14], af[15],
                    af[16], af[17], af[18], af[19], af[20], af[21], af[22], af[23],
                    af[24], af[25], af[26], af[27], af[28], af[29], af[30], af[31],
                    af[32], af[33], af[34], af[35], af[36], af[37], af[38], af[39],
                    af[40], af[41], af[42], af[43], af[44], af[45], af[46], af[47],
                    af[48], af[49], af[50], af[51], af[52], af[53], af[54], af[55],
                    af[56], af[57], af[58], af[59], af[60], af[61], af[62], af[63],
                    af[64], af[65], af[66], af[67], af[68], af[69], af[70], af[71],
                    af[72], af[73], af[74], af[75], af[76], af[77], af[78], af[79],
                    af[80], af[81], af[82], af[83], af[84], af[85], af[86], af[87],
                    af[88], af[89], af[90], af[91], af[92], af[93], af[94], af[95],
                    af[96], af[97], af[98], af[99], af[100], af[101], af[102], af[103],
                    af[104], af[105], af[106], af[107], af[108], af[109], af[110], af[111],
                    af[112], af[113], af[114], af[115], af[116], af[117], af[118], af[119],
                    af[120], af[121], af[122], af[123], af[124], af[125], af[126], af[127]);
        } else {
            REXLOG_WARN("XamInputGetState target does NOT start with E9 (jmp). "
                        "Using thunk address directly.");
            g_native_XamInputGetState_func = (void*)hotpatch_thunk;
        }

        // The function at g_native_XamInputGetState_func is a PPC-translation
        // wrapper.  From the 128-byte dump, E8 is at byte offset 69:
        //   ... 89 C2 E8 A6 CE FF FF 89 C0 ...
        //                ^^ call real_XamInputGetState
        // Resolve the call target and point our detour there instead.
        if (g_native_XamInputGetState_func) {
            uint8_t* wrap = (uint8_t*)g_native_XamInputGetState_func;
            // E8 at byte 69, rel32 at bytes 70-73:
            int32_t rel = *reinterpret_cast<int32_t*>(wrap + 70);
            void* real_func = wrap + 74 + rel; // instruction_addr(69) + 5 + rel
            REXLOG_INFO("Translation wrapper calls real XamInputGetState at 0x{:p}", real_func);
            
            // Dump first 16 bytes of the REAL function
            uint8_t* rf = (uint8_t*)real_func;
            REXLOG_INFO("Real XamInputGetState func first 16 bytes: "
                        "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} "
                        "{:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X}",
                        rf[0], rf[1], rf[2], rf[3], rf[4], rf[5], rf[6], rf[7],
                        rf[8], rf[9], rf[10], rf[11], rf[12], rf[13], rf[14], rf[15]);
            
            // Install native detour on the REAL function
            REXLOG_INFO("Installing native XamInputGetState detour on REAL func at 0x{:p} ...",
                        real_func);
            if (InstallNativeDetour(real_func,
                                    (void*)hk_native_XamInputGetState,
                                    g_original_native_bytes, 12)) {
                REXLOG_INFO("Native XamInputGetState (real func) detour installed successfully");
            } else {
                REXLOG_ERROR("Failed to install native XamInputGetState detour on real func");
            }
        }
    }
    
    // Install GPU MMIO hooks with passthrough to originals
    mcla::gpu::InstallGpuHooks(dispatcher);
    
    // Install native renderer (wraps GfxCmdBufSubmit to capture state)
    if (dispatcher) {
        mcla::native::InstallNativeRenderer(dispatcher);
    }

    // Hook the 4 kernel timer DPCs to decouple physics delta-time from guest
    // CPU speed.  The originals use REX_QUERY_TIMEBASE() which runs at guest
    // CPU speed â€” when VSync is removed the guest spins faster and timebase
    // advances too quickly, making physics run at super-speed.  Our hooks
    // replace the timebase delta with wall-clock elapsed seconds.
    dispatcher->SetFunction(0x82130690, hk_sub_82130690);
    dispatcher->SetFunction(0x82130770, hk_sub_82130770);
    dispatcher->SetFunction(0x82130850, hk_sub_82130850);
    dispatcher->SetFunction(0x82130930, hk_sub_82130930);
    dispatcher->SetFunction(0x82130A18, hk_sub_82130A18);
    
    // Allocate a thunk for the Press Start shim and register it with the
    // dispatcher so REX_CALL_INDIRECT_FUNC can route to it.  Then make
    // 0x82554080 (Press Start screen getter) return the thunk address
    // instead of the original jump-table value (0x812A1100, a native handler
    // in a read-only code page that we cannot overwrite).
    // The shim sets r31+12 = 1 to trigger the screen transition, bypassing
    // the native input-check entirely.
    {
        g_press_start_shim_thunk = dispatcher->AllocateThunk(hk_press_start_shim, 0x82554080);
        // AllocateThunk writes the JIT trampoline but does NOT register it
        // in the function table â€” REX_CALL_INDIRECT_FUNC would try to JIT
        // the x86 thunk bytes as PPC code and crash.  Register explicitly.
        if (!dispatcher->SetFunction(g_press_start_shim_thunk, hk_press_start_shim)) {
            REXLOG_ERROR("Press Start shim: SetFunction(0x{:08X}) FAILED â€” "
                         "thunk may not be reachable", g_press_start_shim_thunk);
        }
        REXLOG_INFO("Press Start shim thunk allocated+registered at 0x{:08X}", g_press_start_shim_thunk);
    }

    // Screen manager hook â€” log first few calls for debugging
    g_orig_sub_82554E20 = dispatcher->GetFunction(0x82554E20);
    if (g_orig_sub_82554E20) {
        dispatcher->SetFunction(0x82554E20, hk_sub_82554E20);
        REXLOG_INFO("Screen manager (sub_82554E20) hooked");
    } else {
        REXLOG_ERROR("sub_82554E20 not found in dispatcher");
    }
    
    // Log the sub_82554590 callback address (used when handler is NULL)
    if (g_virtual_membase) {
        uint32_t cb2 = *(uint32_t*)(g_virtual_membase + 0x828DA3C4);
        REXLOG_INFO("sub_82554590 callback at 0x828DA3C4 = 0x{:08X}", cb2);
    }

    REXLOG_INFO("MCLA patches applied (1 entry + 5 GPU hooks + 5 timer hooks + native renderer + screen hooks)");
}

/// Re-initialise the GPU backend after a save/load so the freshly-loaded
/// native DLL has the same callback + ring-buffer state as the guest
/// code expects.  Must be called from a REX_FUNC (so that `ctx` and
/// `base` are available).
static void ReinitGpuBackend(PPCContext& ctx, uint8_t* base) {
    uint32_t gfx_ctx_guest = REX_LOAD_U32(0x82839254);
    if (!gfx_ctx_guest || gfx_ctx_guest >= 0x90000000) {
        REXLOG_ERROR("Invalid GPU context ptr 0x{:08X} from [0x82839254]", gfx_ctx_guest);
        return;
    }

    // 1. VdInitializeEngines â€” reset GPU backend internal state.
    //    Parameters match the boot-time call in sub_82426468.
    REXLOG_WARN("Calling VdInitializeEngines (ctx=0x{:08X})", gfx_ctx_guest);
    {
        auto saved_lr = ctx.lr;
        ctx.r3.u64 = 0x1B530000;   // engine flags
        ctx.r4.u64 = 0x82425D78;   // config struct
        ctx.r5.u64 = 0;
        ctx.r6.u64 = 0x82066110;   // init params
        ctx.r7.u64 = 0x82066590;   // init params
        REX_CALL_INDIRECT_FUNC(0x827BD784);
        ctx.lr = saved_lr;
    }

    // 2. VdSetGraphicsInterruptCallback â€” re-register the game's VSync
    //    handler so the GPU backend delivers interrupts to sub_82411478.
    REXLOG_WARN("Calling VdSetGraphicsInterruptCallback");
    {
        auto saved_lr = ctx.lr;
        ctx.r3.u64 = 0x82411478;   // VSync handler address
        ctx.r4.u64 = gfx_ctx_guest; // user_data = GPU context
        REX_CALL_INDIRECT_FUNC(0x827BD774);
        ctx.lr = saved_lr;
    }

    // 3. Initialise the ring buffer so the GPU backend can process PM4 commands.
    uint32_t ring_buf = REX_LOAD_U32(gfx_ctx_guest + 14836);
    if (ring_buf) {
        REXLOG_WARN("Calling VdInitializeRingBuffer (ring=0x{:08X})", ring_buf);
        auto saved_lr = ctx.lr;
        ctx.r3.u64 = ring_buf;          // virtual address
        REX_CALL_INDIRECT_FUNC(0x827BD5F4); // MmGetPhysicalAddress â†’ r3 = phys addr
        ctx.r4.u64 = 12;                // size log2 (4096 bytes)
        REX_CALL_INDIRECT_FUNC(0x827BD6B4); // VdInitializeRingBuffer(r3=phys, r4=log2)
        ctx.lr = saved_lr;
    }

    // 4. Re-init the GPU sub-context (96 bytes at context+10896) for
    //    VdEnableRingBufferRPtrWriteBack.
    uint32_t sub_ctx = REX_LOAD_U32(gfx_ctx_guest + 10896);
    if (sub_ctx) {
        auto saved_lr = ctx.lr;
        ctx.r3.u64 = sub_ctx + 60;
        REX_CALL_INDIRECT_FUNC(0x827BD5F4); // MmGetPhysicalAddress
        ctx.r4.u64 = 19;
        REX_CALL_INDIRECT_FUNC(0x827BD6A4); // VdEnableRingBufferRPtrWriteBack
        ctx.lr = saved_lr;
    }

    // 5. Seed the register file from saved context so the freshly-reset
    //    GPU backend has valid render-target state for the first draw call
    //    after resume.  Also serves as a speed signal: without this seed
    //    the game's main thread loafs at ~1s/tick; with it the game loops
    //    at CPU speed (despite PM4 errors from stale context values).
    {
        MclaGpuContext* gpuCtx = reinterpret_cast<MclaGpuContext*>(base + gfx_ctx_guest);
        auto* runtime = rex::Runtime::instance();
        auto* gs = runtime ? static_cast<rex::graphics::GraphicsSystem*>(runtime->graphics_system()) : nullptr;
        auto* rf = gs ? gs->register_file() : nullptr;
        if (rf) {
            mcla::native::WriteGpuContextToRegisterFile(gpuCtx);
            REXLOG_WARN("Register file seeded from saved context (rbSurf0=0x{:08X})", gpuCtx->rbSurfaceInfoP0);
        }
    }

    // 6. Clear the 0x0BADF00D sentinel from the VSync control struct's
    //    callback field.  sub_82411478 checks *(*(context+10900)+16) and
    //    traps if it equals 0x0BADF00D.
    uint32_t ctrl_struct = REX_LOAD_U32(gfx_ctx_guest + 10900);
    if (ctrl_struct) {
        uint32_t callback = REX_LOAD_U32(ctrl_struct + 16);
        if (callback == 0x0BADF00D) {
            REXLOG_WARN("Clearing 0x0BADF00D from ctrl_struct+16 (ctrl=0x{:08X})", ctrl_struct);
            REX_STORE_U32(ctrl_struct + 16, 0);
        }
    }
}

// Hook: KeWaitForSingleObject â€” skip the display-sync semaphore wait.
// The game's VSync handler (sub_823EC8C8) waits on semaphore
// 0xFFFF8234D9B8.  When that object is the target, return immediately
// so the entire VSync processing loop runs at uncapped speed.
// All other waits chain to the original kernel implementation.
REX_FUNC(hk_KeWaitForSingleObject) {
    // r3 = object pointer (guest virtual address).
    // The VSync handler (sub_823EC8C8) waits on semaphore at r29.
    // Observed addresses (from KeWait log):
    //   0x828CD9AC â€” polled at very high frequency (dozens/ms), this IS the
    //                display sync semaphore (not 0x8234D9AC as originally
    //                guessed â€” the base page is 0x828C, not 0x8234).
    //   0x40004D7C â€” polled at ~30 ms intervals on the main thread (must NOT
    //                be skipped; it's a scheduler tick, not VSync-related).

    // Log the very first call unconditionally to verify hook fires
    {
        static bool firstCall = true;
        if (firstCall) {
            firstCall = false;
            REXLOG_WARN("KeWait FIRST CALL: obj=0x{:08X} (tid={})", ctx.r3.u32, GetCurrentThreadId());
        }
    }

    static constexpr uint32_t kDisplaySyncSem = 0x828CD9AC;
    static constexpr uint32_t kSchedulerTick   = 0x40004D7C;

    static int waitCount = 0;
    waitCount++;

    if (ctx.r3.u32 == kDisplaySyncSem) {
        if (waitCount <= 5) {
            REXLOG_INFO("KeWait[{}] DISPLAY-SYNC SEM 0x{:08X} -> SKIPPED", waitCount, ctx.r3.u32);
        }
        ctx.r3.u64 = 0; // STATUS_SUCCESS
        return;
    }

    if (ctx.r3.u32 != kSchedulerTick && waitCount <= 200) {
        REXLOG_INFO("KeWait[{}] obj=0x{:08X} -> chaining to original", waitCount, ctx.r3.u32);
    }

    // All other waits pass through to the real implementation
    // (g_original_KeWait points to the function inside rexruntime.dll,
    //  bypassing the JMP thunk we overwrote)
    if (g_original_KeWait) {
        g_original_KeWait(ctx, base);
    }
}

// Hook: XamInputGetState â€” inject a Start button press so the game
// advances past the "Press Start" screen.  This PPC-level hook handles
// the import-thunk path (generated code calls).  We do NOT call through
// to g_original_XamInputGetState because it now goes through the native
// detour on the actual DLL function and would receive wrong parameters.
// Instead, we directly inject Start into the guest output buffer.
//
// IMPORTANT: The handler checks the RETURN VALUE (r3).  Zero means
// success.  We MUST set ctx.r3 = 0 or the handler ignores the buffer.
//
// The native detour (hk_native_XamInputGetState) handles the syscall
// path separately, but logs show it never fires â€” the handler at
// 0x812A1100 calls through the import thunk (not syscall).
REX_FUNC(hk_XamInputGetState) {
    static int callCount = 0;
    callCount++;

    uint32_t port = ctx.r3.u32;
    uint32_t buf  = ctx.r5.u32;

    // Log first 10 calls for debugging
    if (callCount <= 10) {
        REXLOG_INFO("XamInputGetState[{}]: port={} buf=0x{:08X} held={}",
                    callCount, port, buf, StartPulseActive());
    }

    // Pulsed Start injection: hold for kStartHoldMs, release for
    // kStartReleaseMs, repeat.  The Press Start handler waits on a press
    // EDGE, so a permanently-held Start never transitions it.
    if (buf >= 0x10000000) {
        if (StartPulseActive()) {
            REX_STORE_U16(buf + 4, 0x0010);  // XINPUT_GAMEPAD_START
        } else {
            REX_STORE_U16(buf + 4, 0x0000);  // release
        }
        if (callCount <= 5) {
            REXLOG_INFO("XamInputGetState[{}]: Start held={} buf=0x{:08X}",
                        callCount, StartPulseActive(), buf);
        }
    }

    // CRITICAL: return ERROR_SUCCESS so the handler reads the buffer
    ctx.r3.u64 = 0;
}

// â”€â”€ NtCreateFile FS-wedge accommodation â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
// The RAGE city-art loader opens t:\mc4\art\city\*.loc (RPF3 archives) that
// live inside xarchive_cache.rpf on the disc.  The recomp's host game_data
// tree has no mc4\art\city directory, so the VFS ResolvePath fails with
// STATUS_NO_SUCH_FILE (0xc000000f) and boot wedges on the splash.  Per the
// 2026-08-08 decision (NATIVE_GPU_REBUILD_PLAN.md "On-window run"), this is
// a game-data/legacy-path accommodation, NOT native-GPU work: we materialize
// EMPTY host stub files under update_data_root (the host root the update:
// device serves, which the t: symlink resolves to) so the real NtCreateFile
// returns real empty-stream handles.  NtReadFile on them yields EOF (0 bytes).
//
// The stubs are created BEFORE the runtime mounts the VFS, in
// MCLAApp::OnConfigurePaths â†’ MclaPrecreateArtCityStubs (see mcla_app.h).
// rexruntime's HostPathDevice keeps an in-memory entry tree populated at
// mount time and cached; files created later on the host disk are never
// inserted into that tree, so post-mount creation cannot fix the open.  This
// hook only logs the concrete city-art opens (deduplicated) for evidence.
//
// Guest ABI (r3-r6): NtCreateFile(handle*, desired_access, OBJECT_ATTRIBUTES*,
// IO_STATUS_BLOCK*, ...).  r5 â†’ X_OBJECT_ATTRIBUTES{root_directory@0,
// name_ptr@4 (PANSI_STRING â†’ X_ANSI_STRING), attributes@0xC}.  X_ANSI_STRING
// {length@0 u16, maximum_length@2 u16, pointer@4 u32}.
static void StubNtCreateFileCityLoc(const std::string& guest_path) {
    // Normalize for matching: lowercase, backslash â†’ slash.
    std::string norm = guest_path;
    std::transform(norm.begin(), norm.end(), norm.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    std::replace(norm.begin(), norm.end(), '\\', '/');

    const std::string kCityMarker = "mc4/art/city";
    if (norm.find(kCityMarker) == std::string::npos) return;
    auto dot = norm.find_last_of('.');
    if (dot == std::string::npos || norm.compare(dot, 5, ".loc") != 0) return;

    static std::unordered_set<std::string> s_seen;
    if (s_seen.insert(norm).second) {
        REXLOG_WARN("NtCreateFile city-art: {} (pre-mounted stub, expected to resolve)",
                    guest_path);
    }
}

REX_FUNC(hk_NtCreateFile) {
    // r5 = X_OBJECT_ATTRIBUTES* (guest).  Read name_ptr â†’ X_ANSI_STRING.
    mcla::native::GuestMemoryView view;
    uint32_t oa = ctx.r5.u32;
    uint32_t ansi_str = 0;
    uint16_t str_len = 0;
    uint32_t str_ptr = 0;
    if (oa && view.ReadU32BE(oa + 4, &ansi_str) && ansi_str &&
        view.ReadU16BE(ansi_str + 0, &str_len) &&
        view.ReadU32BE(ansi_str + 4, &str_ptr) && str_len > 0 &&
        str_len <= 1024 && str_ptr) {
        std::vector<char> buf(str_len);
        if (view.ReadBytes(str_ptr, buf.data(), str_len)) {
            std::string guest_path(buf.data(), str_len);
            StubNtCreateFileCityLoc(guest_path);
        }
    }

    if (g_original_NtCreateFile) {
        g_original_NtCreateFile(ctx, base);
    }
}

// Hook: sub_822A3998 â€” input device getter.
// The original reads *(manager + offset_from_port) from the device table.
// We return a non-null pointer for port 0 so the game sees a connected
// controller even when one is not physically present.
static uint32_t s_fakeInputDeviceAddr = 0;

REX_FUNC(hk_sub_822A3998) {
    // r3 = manager pointer (0xBDB818C0), r4 = port index
    uint32_t manager  = ctx.r3.u32;
    uint32_t port     = ctx.r4.u32;

    if (port == 0) {
        // Allocate a fake device structure on first call.
        // Use the screen object heap area (writable user space).
        if (!s_fakeInputDeviceAddr) {
            // Overwrite the semaphore's upper bytes with a zero-filled
            // XINPUT_STATE (packetNum=0, wButtons=0).  The semaphore at
            // 0x828CD9AC is 4 bytes â€” we write 12 bytes into the
            // following padding.
            for (int i = 0; i < 12; i++) {
                REX_STORE_U8(0x828CD9AC + i, 0);
            }
            s_fakeInputDeviceAddr = 0x828CD9AC;
            REXLOG_WARN("sub_822A3998(port=0): fake device at 0x{:08X} (allocated on semaphore page)",
                        s_fakeInputDeviceAddr);
        }
        ctx.r3.u64 = s_fakeInputDeviceAddr;

        static int callCount = 0;
        callCount++;
        if (callCount <= 3) {
            REXLOG_INFO("sub_822A3998(port=0): returning 0x{:08X}", ctx.r3.u32);
        }
        return;
    }

    // For non-zero ports, chain to original (if we want to preserve them)
    // Fall through to the original recompiled implementation.
    // Since we can't easily call the original, just return 0 for now.
    if (manager && port) {
        ctx.r3.u64 = 0;
    }
}

// Hook: sub_82554E20 â€” screen manager main entry point.
// For the Press Start screen: patches the inline bytecode data to
// redirect the handler from 0x812A1100 (native XAM code we can't hook)
// to our shim thunk (hk_press_start_shim).  The shim sets flag=2 and
// calls sub_82554590 so the screen transitions to the main menu.
REX_FUNC(hk_sub_82554E20) {
    static int callCount = 0;
    callCount++;

    uint32_t screenObj = ctx.r3.u32;

    // Log ALL screen objects (first few calls each)
    static uint32_t s_loggedScreens[16] = {};
    bool alreadyLogged = false;
    for (int i = 0; i < 16; i++) {
        if (s_loggedScreens[i] == screenObj) { alreadyLogged = true; break; }
        if (s_loggedScreens[i] == 0) { s_loggedScreens[i] = screenObj; break; }
    }

    if (!alreadyLogged && callCount <= 20) {
        uint32_t flag = REX_LOAD_U32(screenObj + 12);
        uint32_t cnt  = REX_LOAD_U32(screenObj + 24);
        uint32_t lst  = REX_LOAD_U32(screenObj + 80);
        REXLOG_WARN("sub_82554E20[{}]: obj=0x{:08X} flag={} count={} list=0x{:08X}",
                    callCount, screenObj, flag, cnt, lst);
    }

    // Press Start screen: patch bytecode instead of forcing flag=2
    if (screenObj == 0xBD3AFCB0) {
        uint32_t flag = REX_LOAD_U32(screenObj + 12);
        bool patched = false;
        if (flag == 0) {
            // Patch the bytecode data: find 0x812A1100 and replace with our thunk
            // so the opcode-44 handler call redirects to hk_press_start_shim.
            if (g_press_start_shim_thunk) {
                uint32_t saved_r3 = ctx.r3.u32;
                uint32_t screen8 = REX_LOAD_U32(screenObj + 8);
                REXLOG_WARN("  PressStart: screen[8]=0x{:08X}", screen8);
                ctx.r3.u64 = screen8;
                sub_825578B8(ctx, base);
                uint32_t res = ctx.r3.u32;
                uint32_t bc = res ? REX_LOAD_U32(res + 8) : 0;
                REXLOG_WARN("  PressStart: sub_825578B8(screen[8])=0x{:08X}, bc=0x{:08X}",
                            res, bc);
                if (bc) {
                    // Search for handler 0x812A1100 in opcode 44 targets
                    // Opcode 44 computes address in LITTLE-ENDIAN: (b5<<24)|(b4<<16)|(b3<<8)|b2
                    int found_le = -1;
                    for (int i = 0; i < 65536 - 5; i++) {
                        if (REX_LOAD_U8(bc + i) != 0x2C) continue;
                        uint32_t addr = (REX_LOAD_U8(bc+i+5) << 24) |
                                        (REX_LOAD_U8(bc+i+4) << 16) |
                                        (REX_LOAD_U8(bc+i+3) << 8)  |
                                        REX_LOAD_U8(bc+i+2);
                        if (addr == 0x812A1100) {
                            found_le = i;
                            REXLOG_WARN("  PressStart: FOUND 0x812A1100 as LE at bc+{}", i);
                            break;
                        }
                    }
                    if (found_le < 0) {
                        REXLOG_WARN("  PressStart: 0x812A1100 NOT FOUND in bytecode");
                    } else {
                        // Store thunk address in LITTLE-ENDIAN format:
                        // r11 = (b5<<24)|(b4<<16)|(b3<<8)|b2
                        uint32_t thunk = g_press_start_shim_thunk;
                        REX_STORE_U8(bc + found_le + 2, (thunk >> 0) & 0xFF);   // b2 = LSB
                        REX_STORE_U8(bc + found_le + 3, (thunk >> 8) & 0xFF);   // b3
                        REX_STORE_U8(bc + found_le + 4, (thunk >> 16) & 0xFF);  // b4
                        REX_STORE_U8(bc + found_le + 5, (thunk >> 24) & 0xFF);  // b5 = MSB
                        patched = true;
                    }
                } else {
                    REXLOG_WARN("  PressStart: bytecode lookup failed (res=0x{:08X})", res);
                }
                ctx.r3.u64 = saved_r3;
            }
        }

        // If the bytecode redirect could not be installed, force the screen
        // transition directly: run the same completion path the shim would
        // (sub_82554590 + flag=2) so the game does not stall on the native
        // XAM input check at 0x812A1100.
        if (flag == 0 && !patched) {
            REXLOG_WARN("  PressStart: forcing flag=2 via sub_82554590");
            {
                uint32_t saved_r3 = ctx.r3.u32;
                uint32_t saved_r4 = ctx.r4.u32;
                ctx.r3.u64 = screenObj;
                ctx.r4.u64 = 0x82017D0C;
                sub_82554590(ctx, base);
                ctx.r3.u64 = saved_r3;
                ctx.r4.u64 = saved_r4;
            }
            REX_STORE_U32(screenObj + 12, 2);
        }

        // Chain to original â€” it will execute bytecodes and call our shim
        if (g_orig_sub_82554E20) {
            g_orig_sub_82554E20(ctx, base);
        }
        return;
    }

    // Other screens: chain to original
    if (g_orig_sub_82554E20) {
        g_orig_sub_82554E20(ctx, base);
    }
}

// Shim: Press Start handler â€” sets flag=2 to trigger transition,
// then calls sub_82554590 for screen-completion processing.
// Called from bytecode opcode 44 (handler dispatch) instead of the
// original XAM handler at 0x812A1100.
// At call time:  r31 = screenObj (set by sub_82554E20 prologue)
//                r3  = stack[176] (opaque struct built by bytecode)
REX_FUNC(hk_press_start_shim) {
    static int count = 0;
    count++;

    uint32_t screenObj = ctx.r31.u32;
    uint32_t old = REX_LOAD_U32(screenObj + 12);

    // Call sub_82554590 â€” signals screen completion (writes flag=2)
    {
        uint32_t saved_r3 = ctx.r3.u32;
        uint32_t saved_r4 = ctx.r4.u32;
        ctx.r3.u64 = screenObj;
        ctx.r4.u64 = 0x82017D0C;
        sub_82554590(ctx, base);
        ctx.r3.u64 = saved_r3;
        ctx.r4.u64 = saved_r4;
    }

    // Ensure flag=2
    REX_STORE_U32(screenObj + 12, 2);

    if (count <= 3) {
        uint32_t cb = REX_LOAD_U32(0x8200A3C4);
        REXLOG_WARN("hk_press_start_shim[{}]: screenObj=0x{:08X} old=0x{:08X} "
                    "cb=0x{:08X} -> flag=2",
                    count, screenObj, old, cb);
    }
}

REX_FUNC(sub_82554080_stub) {
    static int count = 0;
    count++;
    g_press_start_bypassed = true;

    // Return the shim thunk address so the screen manager calls our
    // handler (hk_press_start_shim) instead of the original XAM handler
    // at 0x812A1100.  This covers a second code path (jump-table
    // lookup) that the bytecode interpreter uses to resolve handlers.
    ctx.r3.u64 = g_press_start_shim_thunk;
    if (count <= 3) {
        REXLOG_WARN("sub_82554080 stub[{}]: r31=0x{:08X} -> returning thunk 0x{:08X}",
                    count, ctx.r31.u32, ctx.r3.u32);
    }
}
