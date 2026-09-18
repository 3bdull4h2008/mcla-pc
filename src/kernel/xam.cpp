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
#include <cstring>
#include <xxhash.h>
#include <SDL3/SDL.h>
#include "logging.h"
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

uint32_t XamInputGetCapabilities(uint32_t unk, uint32_t userIndex, uint32_t flags, XAMINPUT_CAPABILITIES* caps)
{
    if (caps)
    {
        caps->Type = XAMINPUT_DEVTYPE_GAMEPAD;
        caps->SubType = XAMINPUT_DEVSUBTYPE_GAMEPAD;
        caps->Flags = 0;
        memset(&caps->Gamepad, 0, sizeof(caps->Gamepad));
        memset(&caps->Vibration, 0, sizeof(caps->Vibration));
    }
    return 0;
}

uint32_t XamInputGetState(uint32_t userIndex, uint32_t flags, XAMINPUT_STATE* state)
{
    static int callCount = 0;
    callCount++;
    if (!state)
        return 0; // ERROR_EMPTY / not connected

    // W3: map host keyboard → XInput pad so menus can be driven.
    //   arrows / WASD = dpad+left stick   Enter|Space=A   Esc|Backspace=B
    //   Tab=START   Q/E=LB/RB   IJKL=right stick   U/O=LT/RT
    int nkeys = 0;
    const bool *k = SDL_GetKeyboardState(&nkeys);
    auto down = [&](SDL_Keycode sym) -> bool {
        if (!k || nkeys <= 0) return false;
        const SDL_Scancode sc = SDL_GetScancodeFromKey(sym, nullptr);
        if (sc == SDL_SCANCODE_UNKNOWN || static_cast<int>(sc) >= nkeys)
            return false;
        return k[sc];
    };

    uint16_t buttons = 0;
    int16_t lx = 0, ly = 0, rx = 0, ry = 0;
    uint8_t lt = 0, rt = 0;

    if (down(SDLK_UP) || down(SDLK_W)) { buttons |= XAMINPUT_GAMEPAD_DPAD_UP; ly = 32767; }
    if (down(SDLK_DOWN) || down(SDLK_S)) { buttons |= XAMINPUT_GAMEPAD_DPAD_DOWN; ly = -32768; }
    if (down(SDLK_LEFT) || down(SDLK_A)) { buttons |= XAMINPUT_GAMEPAD_DPAD_LEFT; lx = -32768; }
    if (down(SDLK_RIGHT) || down(SDLK_D)) { buttons |= XAMINPUT_GAMEPAD_DPAD_RIGHT; lx = 32767; }
    if (down(SDLK_RETURN) || down(SDLK_SPACE)) buttons |= XAMINPUT_GAMEPAD_A;
    if (down(SDLK_ESCAPE) || down(SDLK_BACKSPACE)) buttons |= XAMINPUT_GAMEPAD_B;
    if (down(SDLK_TAB)) buttons |= XAMINPUT_GAMEPAD_START;
    if (down(SDLK_Q)) buttons |= XAMINPUT_GAMEPAD_LEFT_SHOULDER;
    if (down(SDLK_E)) buttons |= XAMINPUT_GAMEPAD_RIGHT_SHOULDER;
    if (down(SDLK_I)) ry = 32767;
    if (down(SDLK_K)) ry = -32768;
    if (down(SDLK_J)) rx = -32768;
    if (down(SDLK_L)) rx = 32767;
    if (down(SDLK_U)) lt = 255;
    if (down(SDLK_O)) rt = 255;

    // Guest is big-endian PPC — store multi-byte fields swapped.
    auto bswap16 = [](uint16_t v) -> uint16_t {
        return static_cast<uint16_t>((v >> 8) | (v << 8));
    };
    auto bswap16s = [&](int16_t v) -> int16_t {
        return static_cast<int16_t>(bswap16(static_cast<uint16_t>(v)));
    };
    state->dwPacketNumber = __builtin_bswap32(state->dwPacketNumber + 1);
    state->Gamepad.wButtons = bswap16(buttons);
    state->Gamepad.bLeftTrigger = lt;
    state->Gamepad.bRightTrigger = rt;
    state->Gamepad.sThumbLX = bswap16s(lx);
    state->Gamepad.sThumbLY = bswap16s(ly);
    state->Gamepad.sThumbRX = bswap16s(rx);
    state->Gamepad.sThumbRY = bswap16s(ry);

    if (callCount <= 8 || (callCount % 2000) == 0) {
        MCLA_LOG_INFO("XamInputGetState[{}] port={} buttons={:04X} lx={} ly={}",
                      callCount, userIndex, buttons, lx, ly);
    }
    return 0; // ERROR_SUCCESS
}

uint32_t XamInputSetState(uint32_t userIndex, uint32_t flags, XAMINPUT_VIBRATION* vibration)
{
    return 0;
}