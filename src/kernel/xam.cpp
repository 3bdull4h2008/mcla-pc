#include <stdafx.h>
#include "xam.h"
#include "xdm.h"
#include <cpu/guest_thread.h>
#include <cpu/ppc_context.h>
#include <ranges>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <tuple>
#include <vector>
#include <array>
#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstring>
#include <mutex>
#include <xxhash.h>
#include <SDL3/SDL.h>
#include "logging.h"
#include "memory.h"
#include "user/config.h"

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS 0x00000000L
#endif

struct xxHash
{
    using is_avalanching = void;
    uint64_t operator()(XXH64_hash_t const& x) const noexcept { return x; }
};

template<typename T>
using xxHashMap = std::unordered_map<XXH64_hash_t, T, xxHash>;

struct XamListener;

std::unordered_set<XamListener*> gListeners;

struct XamListener : KernelObject
{
    uint32_t id{};
    uint64_t areas{};
    std::vector<std::tuple<uint32_t, uint32_t>> notifications;

    XamListener()
    {
        gListeners.insert(this);
    }

    ~XamListener()
    {
        gListeners.erase(this);
    }

    XamListener(const XamListener&) = delete;
    XamListener& operator=(const XamListener&) = delete;
};

std::array<xxHashMap<XHOSTCONTENT_DATA>, 3> gContentRegistry{};
xxHashMap<std::string> gRootMap;

std::string_view XamGetRootPath(const std::string_view& root)
{
    const auto result = gRootMap.find(StringHash(root));

    if (result == gRootMap.end())
        return "";

    return result->second;
}

void XamRootCreate(const std::string_view& root, const std::string_view& path)
{
    gRootMap.emplace(StringHash(root), path);
}

XCONTENT_DATA XamMakeContent(uint32_t type, const std::string_view& name)
{
    XCONTENT_DATA data{ 1, type };

    strncpy(data.szFileName, name.data(), sizeof(data.szFileName));

    return data;
}

void XamRegisterContent(const XCONTENT_DATA& data, const std::string_view& root)
{
    const auto idx = data.dwContentType - 1;

    gContentRegistry[idx].emplace(StringHash(data.szFileName), XHOSTCONTENT_DATA{ data }).first->second.szRoot = root;
}

void XamRegisterContent(uint32_t type, const std::string_view name, const std::string_view& root)
{
    XCONTENT_DATA data{ 1, type, {}, "" };

    strncpy(data.szFileName, name.data(), sizeof(data.szFileName));

    XamRegisterContent(data, root);
}

uint32_t XamNotifyCreateListener(uint64_t qwAreas)
{
    auto* listener = CreateKernelObject<XamListener>();

    listener->areas = qwAreas;

    return GetKernelHandle(listener);
}

void XamNotifyEnqueueEvent(uint32_t dwId, uint32_t dwParam)
{
    for (const auto& listener : gListeners)
    {
        if (((1 << MSG_AREA(dwId)) & listener->areas) == 0)
            continue;

        listener->notifications.emplace_back(dwId, dwParam);
    }
}

bool XNotifyGetNext(uint32_t hNotification, uint32_t dwMsgFilter, be<uint32_t>* pdwId, be<uint32_t>* pParam)
{
    auto& listener = *GetKernelObject<XamListener>(hNotification);

    if (dwMsgFilter)
    {
        for (size_t i = 0; i < listener.notifications.size(); i++)
        {
            if (std::get<0>(listener.notifications[i]) == dwMsgFilter)
            {
                if (pdwId)
                    *pdwId = std::get<0>(listener.notifications[i]);

                if (pParam)
                    *pParam = std::get<1>(listener.notifications[i]);

                listener.notifications.erase(listener.notifications.begin() + i);
                return true;
            }
        }
        return false;
    }

    if (listener.notifications.empty())
        return false;

    if (pdwId)
        *pdwId = std::get<0>(listener.notifications[0]);

    if (pParam)
        *pParam = std::get<1>(listener.notifications[0]);

    listener.notifications.erase(listener.notifications.begin());
    return true;
}

uint32_t XamShowMessageBoxUI(
    uint32_t dwUserIndex,
    be<uint16_t>* wszTitle,
    be<uint16_t>* wszText,
    uint32_t cButtons,
    xpointer<be<uint16_t>>* pwszButtons,
    uint32_t dwFocusButton,
    uint32_t dwFlags,
    be<uint32_t>* pResult,
    XXOVERLAPPED* pOverlapped)
{
    static std::atomic<uint32_t> s_census{0};
    const uint32_t n = s_census.fetch_add(1) + 1;
    if (n <= 20 || (n % 100) == 0) {
      MCLA_LOG_INFO("XAM-CENSUS[MsgBoxUI] #{:04} user={} buttons={} flags=0x{:X} lr={:08X}", n,
                    dwUserIndex, cButtons, dwFlags,
                    static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
    }
    MCLA_LOG_INFO("XamShowMessageBoxUI: user={} buttons={} flags=0x{:X}", dwUserIndex, cButtons, dwFlags);

    if (pOverlapped)
        pOverlapped->InternalLow = 0;

    if (pResult)
        *pResult = 0;

    return 0;
}

uint32_t XamContentCreateEx(
    uint32_t dwUserIndex,
    const char* szRootName,
    const XCONTENT_DATA* pContentData,
    uint32_t dwTitleId,
    be<uint32_t>* pdwContentId,
    be<uint32_t>* pdwContentId2,
    uint32_t dwAttributes,
    uint64_t qwMaxSize,
    XXOVERLAPPED* pOverlapped)
{
    return 0;
}

uint32_t XamContentClose(const char* szRootName, XXOVERLAPPED* pOverlapped)
{
    return 0;
}

uint32_t XamContentGetDeviceData(uint32_t DeviceID, XDEVICE_DATA* pDeviceData)
{
    static std::atomic<uint32_t> s_cdd{0};
    const uint32_t n = s_cdd.fetch_add(1) + 1;
    if (n <= 8 || (n % 500) == 0)
        MCLA_LOG_WARN("XamContentGetDeviceData[{}] DeviceID={:08X} out={:08X} "
                      "(fills nothing — guest sees zeros)",
                      n, DeviceID, reinterpret_cast<uintptr_t>(pDeviceData));
    return 0;
}

uint32_t XamContentCreateEnumerator(
    uint32_t dwUserIndex,
    uint32_t DeviceID,
    uint32_t dwContentType,
    uint32_t dwContentFlags,
    uint32_t cItem,
    be<uint32_t>* pcbBuffer,
    be<uint32_t>* phEnum)
{
    static std::atomic<uint32_t> s_cce{0};
    const uint32_t n = s_cce.fetch_add(1) + 1;
    MCLA_LOG_WARN("XamContentCreateEnumerator[{}] user={} dev={:08X} "
                  "type={:08X} flags={:08X} cItem={}",
                  n, dwUserIndex, DeviceID, dwContentType, dwContentFlags,
                  cItem);
    return 0;
}

uint32_t XamEnumerate(
    uint32_t hEnum,
    uint32_t dwFlags,
    void* pvBuffer,
    uint32_t cbBuffer,
    be<uint32_t>* pcItemsReturned,
    XXOVERLAPPED* pOverlapped)
{
    static std::atomic<uint32_t> s_cen{0};
    const uint32_t n = s_cen.fetch_add(1) + 1;
    MCLA_LOG_WARN("XamEnumerate[{}] hEnum={:08X} flags={:08X} cb={} "
                  "(returns 0 items)",
                  n, hEnum, dwFlags, cbBuffer);
    return 0;
}

// ===========================================================================
// Xam input - real SDL3 gamepads, one per guest controller port, hot-plugged.
//
// F-609. The pre-fix body returned 0 for every port and filled the overlay
// from SDL_GetKeyboardState on the guest thread, so the title believed it
// held a wired 360 pad on all four ports at all times, forever, and never saw
// X / Y / BACK / either thumb button (those bits exist at src/kernel/xbox.h:
// 369-377 and were never written).
//
// THREADING MODEL - the entire design hangs off this. Do not "simplify" it:
//   * MAIN thread (App::HandleEvents) owns every SDL_Gamepad*. It drains the
//     SDL event queue, opens/closes pads on SDL_EVENT_GAMEPAD_ADDED/REMOVED,
//     and samples each pad into a POD snapshot. SDL_PollEvent is what drives
//     SDL_UpdateGamepads, so "sample immediately after the drain" is the only
//     point at which SDL's gamepad cache is guaranteed fresh.
//   * GUEST thread (XamInputGetState / GetCapabilities / SetState, and any
//     guest worker thread that polls input) makes NO SDL call at all: it
//     copies the snapshot under g_portLock and posts rumble requests through
//     atomics. The pre-fix read path called SDL_GetKeyboardState with no pump
//     of any kind (pre-fix src/kernel/xam.cpp:278), so it read whatever the
//     main loop last happened to leave in SDL's keyboard cache; there is no
//     SDL_PumpEvents equivalent that is legal off the main thread, which is
//     why the snapshot exists instead of a pump on the read path.
//     Rumble is therefore applied by the main thread up to one main-loop tick
//     (~1 ms, src/app.cpp:279) after the guest asks - far below the tens of
//     ms a real 360 pad takes to spin its motors up.
// ===========================================================================

namespace {

// Xbox 360 exposes four controller ports (XINPUT_USER_INDEX_MAX == 4).
constexpr uint32_t kNumPorts = 4;

// The keyboard fallback is bound to port 0 and only to port 0: the guest
// queries player 0 at boot, so any other slot would simply never be read.
constexpr uint32_t kKeyboardFallbackPort = 0;

// XInput's documented radial thumbstick dead zone, 7849 of 32767 - the figure
// the Xbox 360 control panel reports. A retail pad gates this in firmware, so
// skipping it would hand the guest the sub-1% drift a real pad never produces.
// SDL states the same thing from the other side: sticks sit "within ~8000 of
// zero" (third_party/SDL3/include/SDL3/SDL_gamepad.h:213).
constexpr int kStickDeadzone = 7849;

// X_ERROR_DEVICE_NOT_CONNECTED == 0x48F
// (.research/xenia/src/xenia/xbox.h:100).
constexpr uint32_t kXErrorDeviceNotConnected = 0x0000048F;

// Xenia's kInput flag decoding (.research/xenia/src/xenia/kernel/xam/
// xam_input.cc:28-29 for the constants, :93-102 for the use).
constexpr uint32_t kXInputFlagGamepad = 0x01;
constexpr uint32_t kXInputFlagAnyUser = 1u << 30;

// Xbox 360 controller rings: player 1 green, 2 red, 3 blue, 4 yellow.
constexpr uint8_t kPortLed[kNumPorts][3] = {
    { 0, 255, 0 }, { 255, 0, 0 }, { 0, 0, 255 }, { 255, 255, 0 }
};

// Guest is big-endian PPC and the overlay handed to these functions is a
// *host* view of guest RAM (Memory::Translate, src/kernel/function.h:335),
// so every multi-byte field is stored swapped. That discipline is unchanged.
constexpr uint16_t Bswap16(uint16_t v)
{
    return static_cast<uint16_t>((v >> 8) | (v << 8));
}
constexpr int16_t Bswap16s(int16_t v)
{
    return static_cast<int16_t>(Bswap16(static_cast<uint16_t>(v)));
}
constexpr uint32_t Bswap32(uint32_t v)
{
    return __builtin_bswap32(v);
}

enum class PadSource : uint8_t
{
    None     = 0,   // nothing on this port -> X_ERROR_DEVICE_NOT_CONNECTED
    Gamepad  = 1,   // a real SDL_Gamepad* is open on this port
    Keyboard = 2,   // LABELLED fallback, see SampleKeyboard()
};

struct Sample
{
    PadSource   source{PadSource::None};
    uint32_t    instance{0};       // SDL_JoystickID; 0 for the keyboard fallback
    uint16_t    buttons{0};        // host-order XAMINPUT_GAMEPAD_* bits
    uint8_t     ltrigger{0};
    uint8_t     rtrigger{0};
    int16_t     lx{0}, ly{0}, rx{0}, ry{0};
    bool        rumble{false};
    bool        led{false};
    const char* name{nullptr};
    const char* guid{nullptr};
};

// Main-thread-owned SDL handle. Never dereferenced off the main thread - the
// guest side only ever sees the PadSource/rumble/led facts copied into the
// snapshot below.
struct Pad
{
    SDL_Gamepad*   pad{nullptr};
    SDL_JoystickID id{0};
    bool           rumbleOk{false};
    bool           ledOk{false};
    char           name[64]{};
    char           guid[33]{};
};

// What the guest thread is allowed to see: plain host-order POD.
struct PortSnapshot
{
    PadSource source{PadSource::None};
    uint32_t  instance{0};
    uint32_t  generation{0};   // bumped whenever source/instance change
    uint32_t  packet{0};       // host order; strictly monotonic per port
    bool      seeded{false};   // packet has been published at least once
    bool      rumble{false};
    bool      led{false};
    uint16_t  buttons{0};
    uint8_t   ltrigger{0};
    uint8_t   rtrigger{0};
    int16_t   lx{0}, ly{0}, rx{0}, ry{0};
    char      name[64]{};
    char      guid[33]{};
};

std::mutex          g_portLock;
PortSnapshot        g_ports[kNumPorts];   // guarded by g_portLock
Pad                 g_pads[kNumPorts];    // MAIN THREAD ONLY
std::atomic<uint32_t> g_rumbleReq[kNumPorts];      // lo | hi<<16, guest -> main
std::atomic<bool>     g_rumblePending[kNumPorts];

// True when `p` and the `size` bytes after it are both inside the 4 GiB guest
// window. Every out-parameter arriving through GUEST_FUNCTION_HOOK is a
// translated host pointer, so it has to be bounds checked before it is
// written; the pre-fix GetState wrote 12 bytes wherever it was handed.
bool GuestRangeOk(const void* p, size_t size)
{
    const mcla::kernel::Memory& m = mcla::kernel::g_memory;
    if (!m.IsInMemoryRange(p))
        return false;

    const uintptr_t begin = reinterpret_cast<uintptr_t>(p);
    const uintptr_t end = begin + size;
    return end >= begin && end <= reinterpret_cast<uintptr_t>(m.base) + m.size;
}

// Xbox 360 bits (src/kernel/xbox.h:364-377) keyed by SDL's positional button
// enum. SDL is positional rather than lettered, so WEST->X and NORTH->Y is
// the Xbox layout, which is also the physical layout of the pad this guest was
// authored against. BACK is View/Back, not a menu escape. SDL_GAMEPAD_BUTTON_
// GUIDE is dropped on purpose: a wired 360 pad has no Guide button and the
// kInput button word has no bit for one.
struct ButtonMap { SDL_GamepadButton sdl; uint16_t guest; };
constexpr ButtonMap kButtonMap[] = {
    { SDL_GAMEPAD_BUTTON_DPAD_UP,        XAMINPUT_GAMEPAD_DPAD_UP        },
    { SDL_GAMEPAD_BUTTON_DPAD_DOWN,      XAMINPUT_GAMEPAD_DPAD_DOWN      },
    { SDL_GAMEPAD_BUTTON_DPAD_LEFT,      XAMINPUT_GAMEPAD_DPAD_LEFT      },
    { SDL_GAMEPAD_BUTTON_DPAD_RIGHT,     XAMINPUT_GAMEPAD_DPAD_RIGHT     },
    { SDL_GAMEPAD_BUTTON_START,          XAMINPUT_GAMEPAD_START          },
    { SDL_GAMEPAD_BUTTON_BACK,           XAMINPUT_GAMEPAD_BACK           },
    { SDL_GAMEPAD_BUTTON_LEFT_STICK,     XAMINPUT_GAMEPAD_LEFT_THUMB     },
    { SDL_GAMEPAD_BUTTON_RIGHT_STICK,    XAMINPUT_GAMEPAD_RIGHT_THUMB    },
    { SDL_GAMEPAD_BUTTON_LEFT_SHOULDER,  XAMINPUT_GAMEPAD_LEFT_SHOULDER  },
    { SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, XAMINPUT_GAMEPAD_RIGHT_SHOULDER },
    { SDL_GAMEPAD_BUTTON_SOUTH,          XAMINPUT_GAMEPAD_A              },
    { SDL_GAMEPAD_BUTTON_EAST,           XAMINPUT_GAMEPAD_B              },
    { SDL_GAMEPAD_BUTTON_WEST,           XAMINPUT_GAMEPAD_X              },
    { SDL_GAMEPAD_BUTTON_NORTH,          XAMINPUT_GAMEPAD_Y              },
};

// XInput radial dead zone, 7849/32767, rescaled to full range beyond it.
void ApplyDeadzone(int& x, int& y)
{
    const int64_t mag2 = static_cast<int64_t>(x) * x + static_cast<int64_t>(y) * y;
    const int mag = static_cast<int>(std::sqrt(static_cast<double>(mag2)));
    if (mag <= kStickDeadzone)
    {
        x = 0;
        y = 0;
        return;
    }

    const double scale = static_cast<double>(mag - kStickDeadzone) / (32767 - kStickDeadzone);
    x = std::clamp(static_cast<int>(x * scale), -32768, 32767);
    y = std::clamp(static_cast<int>(y * scale), -32768, 32767);
}

// SDL reports gamepad triggers as 0 (released) .. SDL_JOYSTICK_AXIS_MAX
// (32767, fully pressed) from SDL_GetGamepadAxis - and explicitly not the
// same range as the lower-level SDL_GetJoystickAxis
// (third_party/SDL3/include/SDL3/SDL_gamepad.h:216-218). XAMINPUT_GAMEPAD's
// triggers are 0..255. Pre-F-609 the only source was a binary U / O key, so
// a real pad's analog travel never reached the guest.
uint8_t TriggerToXInput(Sint16 v)
{
    if (v <= 0)
        return 0;
    return static_cast<uint8_t>((static_cast<uint32_t>(v) * 255u + 32767u / 2u) / 32767u);
}

// One stick, already in XInput orientation (+Y up) and dead-zoned.
void ReadStick(SDL_Gamepad* pad, SDL_GamepadAxis ax, SDL_GamepadAxis ay, int16_t& ox, int16_t& oy)
{
    // SDL stick Y is +down and XInput sThumbLY is +up, hence the negation -
    // the same inversion UnleashedRecomp applies at
    // .research/UnleashedRecomp/UnleashedRecomp/hid/driver/sdl_hid.cpp:95,99.
    int x = SDL_GetGamepadAxis(pad, ax);
    int y = -static_cast<int>(SDL_GetGamepadAxis(pad, ay));   // clamp after negate
    y = std::clamp(y, -32768, 32767);

    ApplyDeadzone(x, y);
    ox = static_cast<int16_t>(x);
    oy = static_cast<int16_t>(y);
}

void Publish(uint32_t port, const Sample& in)
{
    const std::lock_guard<std::mutex> lock(g_portLock);
    PortSnapshot& s = g_ports[port];

    // dwPacketNumber is the guest's edge detector, so it has to go strictly up
    // whenever the state it describes changes - and it must never be derived
    // from whatever the caller left in the overlay. The pre-fix line read the
    // guest-visible (uninitialised) host word and incremented that (pre-fix
    // src/kernel/xam.cpp:314), so the first poll returned a packet number
    // built out of uninitialised host memory.
    const bool identityChanged = s.source != in.source || s.instance != in.instance;
    const bool stateChanged = s.seeded &&
        (s.buttons != in.buttons || s.ltrigger != in.ltrigger || s.rtrigger != in.rtrigger ||
         s.lx != in.lx || s.ly != in.ly || s.rx != in.rx || s.ry != in.ry);

    if (!s.seeded)
    {
        s.seeded = true;
        s.packet = 1;             // never hand the guest a zero packet number
    }
    else if (identityChanged || stateChanged)
    {
        s.packet++;               // strictly monotonic per port
    }

    if (identityChanged)
    {
        s.source     = in.source;
        s.instance   = in.instance;
        s.generation++;
        // A reconnect restarts the guest's edge sequence but the number the
        // guest can see still only ever goes up, so a title that cached the
        // last packet number cannot be fooled into replaying a stale edge.
    }

    s.buttons   = in.buttons;
    s.ltrigger  = in.ltrigger;
    s.rtrigger  = in.rtrigger;
    s.lx = in.lx; s.ly = in.ly; s.rx = in.rx; s.ry = in.ry;
    s.rumble = in.rumble;
    s.led    = in.led;

    // Unconditional, so an empty Sample{} clears the identity too: a port
    // whose controller was just unplugged must not keep advertising its name.
    const char* name = in.name ? in.name : "";
    strncpy(s.name, name, sizeof(s.name) - 1);
    s.name[sizeof(s.name) - 1] = 0;

    const char* guid = in.guid ? in.guid : "";
    strncpy(s.guid, guid, sizeof(s.guid) - 1);
    s.guid[sizeof(s.guid) - 1] = 0;
}

PortSnapshot ReadPort(uint32_t port)
{
    const std::lock_guard<std::mutex> lock(g_portLock);
    return g_ports[port];
}

Sample SampleGamepad(const Pad& p)
{
    Sample s;
    s.source   = PadSource::Gamepad;
    s.instance = p.id;
    s.rumble   = p.rumbleOk;
    s.led      = p.ledOk;
    s.name     = p.name;
    s.guid     = p.guid;

    for (const ButtonMap& b : kButtonMap)
    {
        if (SDL_GetGamepadButton(p.pad, b.sdl))
            s.buttons |= b.guest;
    }

    s.ltrigger = TriggerToXInput(SDL_GetGamepadAxis(p.pad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER));
    s.rtrigger = TriggerToXInput(SDL_GetGamepadAxis(p.pad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER));

    ReadStick(p.pad, SDL_GAMEPAD_AXIS_LEFTX,  SDL_GAMEPAD_AXIS_LEFTY,  s.lx, s.ly);
    ReadStick(p.pad, SDL_GAMEPAD_AXIS_RIGHTX, SDL_GAMEPAD_AXIS_RIGHTY, s.rx, s.ry);
    return s;
}

// ---------------------------------------------------------------------------
// LABELLED INPUT FALLBACK (F-609, explicitly opted-in diagnostic affordance).
// A host keyboard is not a controller, but the guest was authored against a
// wired 360 pad and will not present a menu at all without one, so port 0 is
// served from SDL_GetKeyboardState when - and only when - no SDL_Gamepad is
// open on that port. This is the one place in the file that reports input
// which did not come from hardware: it is tagged PadSource::Keyboard, named
// "host keyboard (labelled fallback)" in the port map, and every XamInput*
// log line produced from it carries the KBD_FALLBACK marker so a soak census
// (tools/soak_census.py) can never mistake it for a real pad. It never claims
// rumble - there are no motors.
//
// The pre-F-609 key map is kept byte-for-byte so existing logs and muscle
// memory still apply. X, Y, BACK and both thumb buttons were absent because
// the guest-visible bits were never written before; they are C, V, B, 1, 2 -
// A/S/D/W already own the dpad-aliases and Q/E/I/J/K/L/U/O the rest.
// ---------------------------------------------------------------------------
Sample SampleKeyboard()
{
    int nkeys = 0;
    const bool* k = SDL_GetKeyboardState(&nkeys);
    if (!k || nkeys <= 0)
    {
        Sample s;
        s.source = PadSource::Keyboard;
        s.name   = "host keyboard (labelled fallback)";
        return s;
    }

    auto down = [&](SDL_Keycode sym) -> bool {
        const SDL_Scancode sc = SDL_GetScancodeFromKey(sym, nullptr);
        if (sc == SDL_SCANCODE_UNKNOWN || static_cast<int>(sc) >= nkeys)
            return false;
        return k[sc];
    };

    Sample s;
    s.source = PadSource::Keyboard;
    s.name   = "host keyboard (labelled fallback)";

    if (down(SDLK_UP)    || down(SDLK_W)) { s.buttons |= XAMINPUT_GAMEPAD_DPAD_UP;    s.ly = 32767;  }
    if (down(SDLK_DOWN)  || down(SDLK_S)) { s.buttons |= XAMINPUT_GAMEPAD_DPAD_DOWN;  s.ly = -32768; }
    if (down(SDLK_LEFT)  || down(SDLK_A)) { s.buttons |= XAMINPUT_GAMEPAD_DPAD_LEFT;  s.lx = -32768; }
    if (down(SDLK_RIGHT) || down(SDLK_D)) { s.buttons |= XAMINPUT_GAMEPAD_DPAD_RIGHT; s.lx = 32767;  }
    if (down(SDLK_RETURN)  || down(SDLK_SPACE))    s.buttons |= XAMINPUT_GAMEPAD_A;
    if (down(SDLK_ESCAPE)  || down(SDLK_BACKSPACE)) s.buttons |= XAMINPUT_GAMEPAD_B;
    if (down(SDLK_C)) s.buttons |= XAMINPUT_GAMEPAD_X;   // WEST on an Xbox pad
    if (down(SDLK_V)) s.buttons |= XAMINPUT_GAMEPAD_Y;   // NORTH on an Xbox pad
    if (down(SDLK_B)) s.buttons |= XAMINPUT_GAMEPAD_BACK;
    if (down(SDLK_1)) s.buttons |= XAMINPUT_GAMEPAD_LEFT_THUMB;
    if (down(SDLK_2)) s.buttons |= XAMINPUT_GAMEPAD_RIGHT_THUMB;
    if (down(SDLK_TAB)) s.buttons |= XAMINPUT_GAMEPAD_START;
    if (down(SDLK_Q)) s.buttons |= XAMINPUT_GAMEPAD_LEFT_SHOULDER;
    if (down(SDLK_E)) s.buttons |= XAMINPUT_GAMEPAD_RIGHT_SHOULDER;
    if (down(SDLK_I)) s.ry = 32767;
    if (down(SDLK_K)) s.ry = -32768;
    if (down(SDLK_J)) s.rx = -32768;
    if (down(SDLK_L)) s.rx = 32767;
    if (down(SDLK_U)) s.ltrigger = 255;
    if (down(SDLK_O)) s.rtrigger = 255;

    return s;
}

void ApplyPendingRumble(uint32_t port, const Pad& p)
{
    if (!g_rumblePending[port].exchange(false, std::memory_order_acquire))
        return;

    const uint32_t req = g_rumbleReq[port].load(std::memory_order_relaxed);
    const Uint16 lo = static_cast<Uint16>(req & 0xFFFFu);
    const Uint16 hi = static_cast<Uint16>(req >> 16);

    // duration_ms 0 == "run until changed or stopped", which is exactly the
    // XAMINPUT_VIBRATION contract: each call cancels the previous effect and
    // a 0/0 pair is the stop.
    if (!SDL_RumbleGamepad(p.pad, lo, hi, 0) && (lo || hi))
    {
        static std::atomic<uint32_t> s_fail{0};
        const uint32_t n = s_fail.fetch_add(1) + 1;
        if (n <= 4 || (n % 1000) == 0)
            MCLA_LOG_WARN("XamInputSetState[{}] SDL_RumbleGamepad(port={} lo={} hi={}) failed: {}",
                          n, port, lo, hi, SDL_GetError());
    }
}

uint32_t FindFreePort()
{
    for (uint32_t port = 0; port < kNumPorts; ++port)
    {
        if (!g_pads[port].pad)
            return port;
    }
    return kNumPorts;
}

void OpenPad(SDL_JoystickID id)
{
    if (SDL_GetGamepadFromID(id))
        return;                                   // already open on some port

    const uint32_t port = FindFreePort();
    if (port == kNumPorts)
    {
        MCLA_LOG_WARN("XamInputAdd: controller id={} ignored - all {} guest ports are taken",
                      id, kNumPorts);
        return;
    }

    SDL_Gamepad* pad = SDL_OpenGamepad(id);
    if (!pad)
    {
        MCLA_LOG_WARN("XamInputAdd: SDL_OpenGamepad(id={}) failed: {}", id, SDL_GetError());
        return;
    }

    Pad& p = g_pads[port];
    p.pad = pad;
    p.id  = id;

    const char* name = SDL_GetGamepadName(pad);
    strncpy(p.name, name ? name : "unknown gamepad", sizeof(p.name) - 1);
    p.name[sizeof(p.name) - 1] = 0;
    // This SDL build has no SDL_GetGamepadGUID(SDL_Gamepad*) - only the
    // ForID form (third_party/SDL3/include/SDL3/SDL_gamepad.h:626) - so the
    // GUID is taken from the instance id, which is the same device.
    SDL_GUIDToString(SDL_GetGamepadGUIDForID(id), p.guid, sizeof(p.guid));
    p.guid[sizeof(p.guid) - 1] = 0;

    // This SDL build exposes no SDL_GamepadHasRumble / SDL_GamepadHasLED
    // (neither appears anywhere under third_party/SDL3/include/SDL3/), so
    // capability is discovered by issuing the real call. A zero rumble is
    // SDL's "stop", which is a no-op on hardware that cannot do it, and the
    // Xbox 360 ring colour is this player's slot.
    p.rumbleOk = SDL_RumbleGamepad(pad, 0, 0, 0);
    p.ledOk    = SDL_SetGamepadLED(pad, kPortLed[port][0], kPortLed[port][1], kPortLed[port][2]);

    MCLA_LOG_INFO("XamInputAdd: port={} id={} name=\"{}\" guid={} sdl_type={} rumble={} led={} "
                  "(ring set to this slot's 360 player colour)",
                  port, id, p.name, p.guid,
                  static_cast<int>(SDL_GetGamepadType(pad)), p.rumbleOk, p.ledOk);
}

void ClosePad(SDL_JoystickID id)
{
    for (uint32_t port = 0; port < kNumPorts; ++port)
    {
        Pad& p = g_pads[port];
        if (!p.pad || p.id != id)
            continue;

        MCLA_LOG_INFO("XamInputRemove: port={} id={} name=\"{}\" - that port now reports "
                      "DEVICE_NOT_CONNECTED", port, id, p.name);
        SDL_CloseGamepad(p.pad);
        p = Pad{};

        // A rumble request must not survive an unplug: the device that asked
        // for it is gone, and the next pad to land on this port has to start
        // still.
        g_rumblePending[port].store(false, std::memory_order_relaxed);
        Publish(port, Sample{});
        return;
    }

    MCLA_LOG_WARN("XamInputRemove: no guest port holds controller id={}", id);
}

// Xenia's kInput trampolines pin user 0xFF and XINPUT_FLAG_ANY_USER to port 0
// and refuse a query whose low flag byte excludes gamepads
// (.research/xenia/src/xenia/kernel/xam/xam_input.cc:93-102). XamInputSetState
// takes `unk` in the flags slot and does not apply the flag-byte test there
// (xam_input.cc:110-124), so it is opt-in per caller.
bool ResolvePort(uint32_t userIndex, uint32_t flags, bool honourFlagByte, uint32_t& outPort)
{
    if (honourFlagByte && (flags & 0xFF) && (flags & kXInputFlagGamepad) == 0)
        return false;                        // "some device class, not a pad"

    uint32_t port = userIndex & 0xFF;
    if (port == 0xFF || (flags & kXInputFlagAnyUser))
        port = 0;                            // ANY_USER / wildcard user == player 0

    if (port >= kNumPorts)
        return false;                        // no such controller port exists

    outPort = port;
    return true;
}

} // anonymous namespace

void XamInputInit()
{
    // MAIN THREAD, after SDL_Init(SDL_INIT_GAMEPAD) and before the guest boot
    // thread starts. App::Initialize used to hand the guest a window in which
    // nothing had ever been sampled, so a title that probes its controller
    // port in the first few milliseconds would have been told "no controller".
    SDL_UpdateGamepads();

    int count = 0;
    SDL_JoystickID* ids = SDL_GetGamepads(&count);
    if (ids)
    {
        for (int i = 0; i < count; ++i)
            OpenPad(ids[i]);
        SDL_free(ids);
    }

    XamInputPoll();

    uint32_t open = 0;
    for (const Pad& p : g_pads)
    {
        if (p.pad)
            open++;
    }

    MCLA_LOG_INFO("XamInputInit: {} controller(s) open across {} guest ports",
                  open, kNumPorts);

    // The port map, dumped once so every soak records which physical
    // controller ended up on which guest bay - the assignment is dynamic
    // (lowest free slot at plug time) and a plug after boot moves it.
    for (uint32_t port = 0; port < kNumPorts; ++port)
    {
        const PortSnapshot s = ReadPort(port);
        MCLA_LOG_INFO("XamInputPortMap: port={} source={} instance={} dev=\"{}\" guid={}",
                      port,
                      s.source == PadSource::Gamepad ? "gamepad"
                          : s.source == PadSource::Keyboard ? "keyboard-fallback" : "empty",
                      s.instance, s.name, s.guid);
    }
}

void XamInputShutdown()
{
    for (Pad& p : g_pads)
    {
        if (!p.pad)
            continue;

        if (p.rumbleOk)
            SDL_RumbleGamepad(p.pad, 0, 0, 0);     // leave the motors off
        SDL_CloseGamepad(p.pad);
        p = Pad{};
    }

    for (uint32_t port = 0; port < kNumPorts; ++port)
        Publish(port, Sample{});
}

void XamInputGamepadAdded(uint32_t sdlJoystickId)
{
    OpenPad(static_cast<SDL_JoystickID>(sdlJoystickId));
}

void XamInputGamepadRemoved(uint32_t sdlJoystickId)
{
    ClosePad(static_cast<SDL_JoystickID>(sdlJoystickId));
}

void XamInputPoll()
{
    // MAIN THREAD ONLY. Call after the SDL_PollEvent drain - SDL_PollEvent is
    // what runs SDL_UpdateGamepads, so a sample taken before it is a frame
    // behind.
    for (uint32_t port = 0; port < kNumPorts; ++port)
    {
        if (g_pads[port].pad)
        {
            ApplyPendingRumble(port, g_pads[port]);
            Publish(port, SampleGamepad(g_pads[port]));
        }
        else if (port != kKeyboardFallbackPort)
        {
            Publish(port, Sample{});
        }
    }

    // Published exactly once per tick. The fallback port is skipped in the
    // loop above on purpose: publishing an empty sample and then the keyboard
    // sample would cross the None boundary twice per frame, and each crossing
    // is a dwPacketNumber increment the guest never earned.
    if (!g_pads[kKeyboardFallbackPort].pad)
        Publish(kKeyboardFallbackPort, SampleKeyboard());
}

uint32_t XamInputPortCount()
{
    return kNumPorts;
}

// The port map, for anything that needs to tell the title (or a native UI)
// which physical controller ended up on which guest port. Returns true only
// for a real device; the keyboard fallback reports false with a name, so a
// caller can still render "port 0: <host keyboard fallback>".
bool XamInputPortDevice(uint32_t port, char* outName, size_t cap, uint32_t* pInstance)
{
    if (port >= kNumPorts)
        return false;

    const PortSnapshot s = ReadPort(port);
    if (s.source == PadSource::None)
        return false;

    if (outName && cap)
    {
        strncpy(outName, s.name, cap - 1);
        outName[cap - 1] = 0;
    }
    if (pInstance)
        *pInstance = (s.source == PadSource::Gamepad) ? s.instance : 0;

    return s.source == PadSource::Gamepad;
}

uint32_t XamInputGetCapabilities(uint32_t userIndex, uint32_t flags, XAMINPUT_CAPABILITIES* caps)
{
    static std::atomic<uint32_t> s_calls{0};
    const uint32_t n = s_calls.fetch_add(1) + 1;

    // `unk` is the leading word the Ex variant carries and the non-Ex one does
    // not; Xenia's entry point ignores it (xam_input.cc:65-84) and so does this
    // F-804: arity corrected to match the guest (3 args, not 4).


    if (!caps)
        return STATUS_INVALID_PARAMETER;   // Xenia returns X_ERROR_BAD_ARGUMENTS
                                           // here (xam_input.cc:45-47)

    if (!GuestRangeOk(caps, sizeof(XAMINPUT_CAPABILITIES)))
    {
        MCLA_LOG_WARN("XamInputGetCapabilities[{}] caps={:p} is outside the guest window "
                      "- nothing written", n, static_cast<const void*>(caps));
        return STATUS_INVALID_PARAMETER;
    }

    uint32_t port = kNumPorts;
    if (!ResolvePort(userIndex, flags, /*honourFlagByte*/ true, port))
        return kXErrorDeviceNotConnected;

    const PortSnapshot s = ReadPort(port);
    if (s.source == PadSource::None)
    {
        // Pre-F-609 this returned success with a zeroed struct for every port
        // including 1..3 and including ports that do not exist, so a title
        // could not tell "no pad" from "pad at rest" (pre-fix
        // src/kernel/xam.cpp:248-259). The struct is left untouched, exactly as
        // on the GetState path.
        if (n <= 8 || (n % 200) == 0)
            MCLA_LOG_INFO("XamInputGetCapabilities[{}] ui={:08X} flags={:08X} port={} "
                          "DEVICE_NOT_CONNECTED (nothing open on that bay)",
                          n, userIndex, flags, port);
        return kXErrorDeviceNotConnected;
    }

    caps->Type    = XAMINPUT_DEVTYPE_GAMEPAD;
    caps->SubType = XAMINPUT_DEVSUBTYPE_GAMEPAD;
    // dwFlags: a wired 360 pad reports 0. There is no guest-visible name for
    // "has an LED ring", so it stays 0 rather than inventing a capability bit
    // the kInput contract never defined.
    caps->Flags   = 0;
    caps->Gamepad.wButtons     = Bswap16(s.buttons);
    caps->Gamepad.bLeftTrigger  = s.ltrigger;
    caps->Gamepad.bRightTrigger = s.rtrigger;
    caps->Gamepad.sThumbLX      = Bswap16s(s.lx);
    caps->Gamepad.sThumbLY      = Bswap16s(s.ly);
    caps->Gamepad.sThumbRX      = Bswap16s(s.rx);
    caps->Gamepad.sThumbRY      = Bswap16s(s.ry);

    // On real hardware Gamepad and Vibration are the *current* state, not a
    // capability list, so Vibration mirrors the motor speeds this port was
    // last driven with instead of a hardcoded zero pair.
    const uint32_t last = g_rumbleReq[port].load(std::memory_order_relaxed);
    caps->Vibration.wLeftMotorSpeed  = Bswap16(static_cast<uint16_t>(last & 0xFFFFu));
    caps->Vibration.wRightMotorSpeed = Bswap16(static_cast<uint16_t>(last >> 16));

    if (n <= 8 || (n % 500) == 0)
    {
        MCLA_LOG_INFO("XamInputGetCapabilities[{}] port={} dev=\"{}\" guid={} rumble={} led={}"
                      "{}{}",
                      n, port, s.name, s.guid, s.rumble, s.led,
                      s.source == PadSource::Keyboard ? " KBD_FALLBACK" : "",
                      s.source == PadSource::Keyboard ? " (no motors)" : "");
    }

    return 0;
}

uint32_t XamInputGetState(uint32_t userIndex, uint32_t flags, XAMINPUT_STATE* state)
{
    static std::atomic<uint32_t> s_calls{0};
    const uint32_t callCount = s_calls.fetch_add(1) + 1;

    // A NULL state pointer is upstream's documented probe case: "Games call
    // this with a NULL state ptr, probably as a query"
    // (.research/xenia/src/xenia/kernel/xam/xam_input.cc:91). It is answered
    // here with 0 = ERROR_SUCCESS and nothing written - NOT an error code,
    // and deliberately answered before the port is resolved: the probe asks
    // whether the subsystem exists, not whether a pad is plugged in.
    // X_ERROR_EMPTY is 0x10D2 and X_ERROR_DEVICE_NOT_CONNECTED is 0x48F
    // (.research/xenia/src/xenia/xbox.h:86,100,106).
    if (!state)
        return 0;

    if (!GuestRangeOk(state, sizeof(XAMINPUT_STATE)))
    {
        MCLA_LOG_WARN("XamInputGetState[{}] state={:p} is outside the guest window "
                      "- nothing written", callCount, static_cast<const void*>(state));
        return STATUS_INVALID_PARAMETER;
    }

    uint32_t port = kNumPorts;
    if (!ResolvePort(userIndex, flags, /*honourFlagByte*/ true, port))
        return kXErrorDeviceNotConnected;

    const PortSnapshot s = ReadPort(port);
    if (s.source == PadSource::None)
    {
        // Per-port honesty (F-609). Pre-F-609 every port - 0, 1, 2, 3 and
        // ports that do not exist - returned ERROR_SUCCESS carrying an
        // identical keyboard state, so a title that queries one specific
        // player slot could not distinguish a phantom pad from a real one and
        // could not implement "press A to continue". Ports with nothing
        // behind them now answer 0x48F and leave the overlay untouched, which
        // is what a retail Xbox 360 answers for an empty controller bay.
        if (callCount <= 8 || (callCount % 2000) == 0)
            MCLA_LOG_INFO("XamInputGetState[{}] port={} DEVICE_NOT_CONNECTED "
                          "(nothing open on that bay)", callCount, port);
        return kXErrorDeviceNotConnected;
    }

    // Guest is big-endian PPC and `state` is a host view of guest RAM, so
    // store the multi-byte fields swapped. dwPacketNumber comes from the
    // main-thread snapshot, never from reading back the overlay: the pre-fix
    // code incremented whatever uninitialised host word the caller's buffer
    // happened to hold (pre-fix src/kernel/xam.cpp:314), so the first poll
    // after boot reported a packet number built out of stack garbage. The
    // snapshot counter is seeded to 1 and then only ever increases on this
    // port.
    state->dwPacketNumber          = Bswap32(s.packet);
    state->Gamepad.wButtons        = Bswap16(s.buttons);
    state->Gamepad.bLeftTrigger    = s.ltrigger;
    state->Gamepad.bRightTrigger   = s.rtrigger;
    state->Gamepad.sThumbLX        = Bswap16s(s.lx);
    state->Gamepad.sThumbLY        = Bswap16s(s.ly);
    state->Gamepad.sThumbRX        = Bswap16s(s.rx);
    state->Gamepad.sThumbRY        = Bswap16s(s.ry);

    if (callCount <= 8 || (callCount % 2000) == 0)
    {
        // ui/flags are printed raw so a soak can prove the Xenia flag decode
        // above is not silently rejecting this title's queries - it was
        // ignored outright before F-609, so there is no prior measurement of
        // what this guest actually passes in the flags slot.
        MCLA_LOG_INFO("XamInputGetState[{}] ui={:08X} flags={:08X} port={} src={} packet={} "
                      "buttons={:04X} lt={} rt={} lx={} ly={} rx={} ry={}{}",
                      callCount, userIndex, flags, port,
                      s.source == PadSource::Gamepad ? "gamepad" : "keyboard",
                      s.packet, s.buttons, s.ltrigger, s.rtrigger,
                      s.lx, s.ly, s.rx, s.ry,
                      s.source == PadSource::Keyboard ? " KBD_FALLBACK" : "");
    }

    return 0; // ERROR_SUCCESS
}

uint32_t XamInputSetState(uint32_t userIndex, uint32_t flags, XAMINPUT_VIBRATION* vibration)
{
    static std::atomic<uint32_t> s_calls{0};
    const uint32_t n = s_calls.fetch_add(1) + 1;

    // Pre-F-609 this was a bare `return 0`: motor commands were accepted and
    // dropped, so no rumble ever reached a controller.
    uint32_t port = kNumPorts;
    if (!ResolvePort(userIndex, flags, /*honourFlagByte*/ false, port))
        return kXErrorDeviceNotConnected;

    if (!vibration)
        return STATUS_INVALID_PARAMETER;

    if (!GuestRangeOk(vibration, sizeof(XAMINPUT_VIBRATION)))
    {
        MCLA_LOG_WARN("XamInputSetState[{}] vibration={:p} is outside the guest window "
                      "- ignored", n, static_cast<const void*>(vibration));
        return STATUS_INVALID_PARAMETER;
    }

    // Guest RAM is big-endian, so the motor speeds are read back through the
    // checked, endian-explicit helper (src/kernel/memory.h:96) rather than
    // trusting the little-endian host view of the same bytes.
    const uint32_t guestVA = mcla::kernel::g_memory.MapVirtual(vibration);
    uint16_t left = 0, right = 0;
    mcla::kernel::GuestMemoryHeap& heap = mcla::kernel::GuestMemoryHeap::Instance();
    if (!heap.ReadU16BE(guestVA, &left) || !heap.ReadU16BE(guestVA + 2, &right))
    {
        MCLA_LOG_WARN("XamInputSetState[{}] XAMINPUT_VIBRATION @{:08X} is not a committed "
                      "guest range - ignored", n, guestVA);
        return STATUS_INVALID_PARAMETER;
    }

    const PortSnapshot s = ReadPort(port);
    if (s.source != PadSource::Gamepad)
    {
        // A keyboard-fallback port accepts and drops the command: the zeros it
        // advertises are honest, because there are no motors there. A port
        // with nothing at all behind it is a hard device error.
        if (s.source == PadSource::Keyboard)
        {
            if (n <= 8 || (n % 500) == 0)
                MCLA_LOG_INFO("XamInputSetState[{}] port={} KBD_FALLBACK lo={} hi={} dropped "
                              "(labelled fallback has no motors)", n, port, left, right);
            return 0;
        }
        return kXErrorDeviceNotConnected;
    }

    // Hand the request to the main thread rather than calling SDL here: the
    // SDL_Gamepad* it would use is main-thread-owned and can be closed by an
    // unplug at any moment. One main-loop tick of latency is irrelevant next
    // to a real pad's motor spin-up.
    g_rumbleReq[port].store(static_cast<uint32_t>(left) | (static_cast<uint32_t>(right) << 16),
                            std::memory_order_relaxed);
    g_rumblePending[port].store(true, std::memory_order_release);

    if (n <= 8 || (n % 500) == 0)
        MCLA_LOG_INFO("XamInputSetState[{}] port={} dev=\"{}\" left={} right={} queued",
                      n, port, s.name, left, right);

    return 0;
}