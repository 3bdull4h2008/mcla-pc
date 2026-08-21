#include <stdafx.h>
#include "xam.h"
#include "xdm.h"
#include <cpu/guest_thread.h>
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
    if (state)
    {
        state->dwPacketNumber = 0;
        memset(&state->Gamepad, 0, sizeof(state->Gamepad));
        // Simulate START button pressed
        state->Gamepad.wButtons = XAMINPUT_GAMEPAD_START;
    }
    return 0;
}

uint32_t XamInputSetState(uint32_t userIndex, uint32_t flags, XAMINPUT_VIBRATION* vibration)
{
    return 0;
}