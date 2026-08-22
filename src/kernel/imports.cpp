#include <stdafx.h>
#include <cpu/ppc_context.h>
#include <cpu/guest_thread.h>
#include <apu/audio.h>
#include "function.h"
#include "heap.h"
#include "memory.h"
#include <memory>
#include "xam.h"
#include "xdm.h"
#include "kernel_objects.h"
#include "logging.h"
#include <gpu_cp.h>
#include <user/config.h>
#include <os/logger.h>

// Host thread id of the guest main thread (see xdm.h). Defined here; set by
// boot_host.cpp when the boot worker starts.
std::atomic<uint32_t> g_mainGuestThreadId{0};

static std::atomic<uint32_t> g_keSetEventGeneration;

// Forward declarations
void MmTrackAllocationSize(uint32_t guestAddress, uint32_t size);
void StartGpuContextPoller();

// XEX loader / crypto forward declarations (must precede hook registrations)
void XexLoadImage();
void XexLoadImageHeaders();
void XexUnloadImage();
void XexCheckExecutablePages();
void XeCryptBnQwBeSigVerify();
void XeCryptSha();
void XeCryptRotSumSha();
void XeKeysGetKey();
void sub_821305B8_NoOp();

// XTL allocator - used by guest code via r13 thread block
PPC_FUNC(__xtl_alloc)
{
    uint32_t align = ctx.r5.u32;
    if (align < 16 || (align & (align - 1)) != 0)
        align = 16;
    ctx.r3.u32 = mcla::kernel::GuestMemoryHeap::Instance().Alloc(ctx.r4.u32, align);
}

PPC_FUNC(__xtl_free)
{
    ctx.r3.u32 = 1;
}

// ---- File metadata queries (shared impls, called from the PPC_FUNC wrappers
// below; these were silent fake-success stubs which made packfile loading fail
// with "Cannot load archive" before a single byte was ever read) ----

static uint32_t NtQueryInformationFileImpl(uint32_t handle, uint32_t ioStatusAddr, uint32_t bufferAddr, uint32_t length, uint32_t infoClass)
{
    // X_FILE_STANDARD_INFORMATION (5): AllocationSize(8) EndOfFile(8)
    // NumberOfLinks(4) DeletePending(1) Directory(1)
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

    KernelObject* obj = nullptr;
    if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle))
    {
        KernelObject* o = GetKernelObject(handle);
        if (o && o->IsValid()) obj = o;
    }
    FileObject* fileObj = (obj && obj->IsValid()) ? dynamic_cast<FileObject*>(obj) : nullptr;

    if (infoClass == 34 && bufferAddr != 0 && length >= 52 && fileObj)
    {
        // X_FILE_NETWORK_OPEN_INFORMATION (NT NETWORK_OPEN_INFORMATION):
        // Creation/LastAccess/LastWrite/ChangeTime (8 each), AllocationSize(8),
        // EndOfFile(8), FileAttributes(4). The packfile loader gates on
        // EndOfFile being the REAL archive size.
        const uint64_t fileSize = fileObj->fileHandle.size;
        (void)mem.WriteU64BE(bufferAddr + 0, 0);            // CreationTime
        (void)mem.WriteU64BE(bufferAddr + 8, 0);            // LastAccessTime
        (void)mem.WriteU64BE(bufferAddr + 16, 0);           // LastWriteTime
        (void)mem.WriteU64BE(bufferAddr + 24, 0);           // ChangeTime
        (void)mem.WriteU64BE(bufferAddr + 32, fileSize);    // AllocationSize
        (void)mem.WriteU64BE(bufferAddr + 40, fileSize);    // EndOfFile
        (void)mem.WriteU32BE(bufferAddr + 48, 0x20);        // FILE_ATTRIBUTE_ARCHIVE
        if (ioStatusAddr)
        {
            (void)mem.WriteU32BE(ioStatusAddr, STATUS_SUCCESS);
            (void)mem.WriteU32BE(ioStatusAddr + 4, 52);
        }
        MCLA_LOG_INFO("NtQueryInformationFile: NETWORK_OPEN_INFO size={}", fileSize);
        return STATUS_SUCCESS;
    }

    if (infoClass == 5 && bufferAddr != 0 && length >= 24 && fileObj)
    {
        const uint64_t fileSize = fileObj->fileHandle.size;
        (void)mem.WriteU64BE(bufferAddr + 0, fileSize);
        (void)mem.WriteU64BE(bufferAddr + 8, fileSize);
        (void)mem.WriteU32BE(bufferAddr + 16, 1);
        (void)mem.WriteU16BE(bufferAddr + 20, 0);
        if (ioStatusAddr)
        {
            (void)mem.WriteU32BE(ioStatusAddr, STATUS_SUCCESS);
            (void)mem.WriteU32BE(ioStatusAddr + 4, 24);
        }
        return STATUS_SUCCESS;
    }

    // Xenia semantics: never fake-success with zeros - the game branches on
    // the returned data, so unsupported classes must fail loudly.
    if (infoClass != 5 && infoClass != 34)
    {
        MCLA_LOG_WARN("NtQueryInformationFile: class={} -> STATUS_INVALID_INFO_CLASS", infoClass);
        if (ioStatusAddr)
        {
            (void)mem.WriteU32BE(ioStatusAddr, STATUS_INVALID_INFO_CLASS);
            (void)mem.WriteU32BE(ioStatusAddr + 4, 0);
        }
        return STATUS_INVALID_INFO_CLASS;
    }

    MCLA_LOG_WARN("NtQueryInformationFile: class={} len={} handleValid={} -> INFO_LENGTH_MISMATCH",
                  infoClass, length, fileObj != nullptr);
    if (ioStatusAddr)
    {
        (void)mem.WriteU32BE(ioStatusAddr, STATUS_INFO_LENGTH_MISMATCH);
        (void)mem.WriteU32BE(ioStatusAddr + 4, 0);
    }
    return STATUS_INFO_LENGTH_MISMATCH;
}

// NtQueryVolumeInformationFile / NtQueryDirectoryFile: typed impls live below
// (near NtReadFile) and are GUEST_FUNCTION_HOOKed at the bottom of this file.

PPC_FUNC(__imp__NtQueryInformationFile)
{
    // r3=handle, r4=ioStatus, r5=buffer, r6=length, r7=infoClass
    ctx.r3.u32 = NtQueryInformationFileImpl(ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32);
}

void VdHSIOCalibrationLock()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeCertMonitorData()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XexExecutableModuleHandle()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ExLoadedCommandLine()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeDebugMonitorData()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ExThreadObjectType()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeTimeStampBundle()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XboxHardwareInfo()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XGetVideoMode()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t XGetGameRegion()
{
    if (Config::Language == ELanguage::Japanese)
        return 0x0101;

    return 0x03FF;
}

uint32_t XMsgStartIORequest(uint32_t App, uint32_t Message, XXOVERLAPPED* lpOverlapped, void* Buffer, uint32_t szBuffer)
{
    (void)App;
    (void)Message;
    (void)Buffer;
    (void)szBuffer;

    if (lpOverlapped)
    {
        // Queue the overlapped I/O request for completion
        // Signal the event when done
        if (lpOverlapped->hEvent)
        {
            // Store the overlapped for later completion
            lpOverlapped->Error.set(STATUS_SUCCESS);
            lpOverlapped->Length.set(szBuffer);
            
            // Signal the event immediately (synchronous completion for now)
            XKEVENT* event = (XKEVENT*)mcla::kernel::GuestMemoryHeap::Instance().Translate(lpOverlapped->hEvent);
            if (event)
            {
                QueryKernelObject<Event>(*event)->Set();
            }
        }
    }

    return STATUS_SUCCESS;
}

uint32_t XamUserGetSigninState(uint32_t userIndex)
{
    return true;
}

uint32_t XamGetSystemVersion()
{
    // Return 2.0.17559.0 as the system version (similar to Xenia)
    return 0x00021755;
}

uint32_t XamContentDelete(uint32_t userIndex, void* deviceId, XCONTENT_DATA* contentData, XXOVERLAPPED* overlapped)
{
    (void)userIndex;
    (void)deviceId;
    (void)contentData;
    (void)overlapped;
    return 0; // Success
}

uint32_t XamContentGetCreator(uint32_t userIndex, const XCONTENT_DATA* contentData, be<uint32_t>* isCreator, be<uint64_t>* xuid, XXOVERLAPPED* overlapped)
{
    if (isCreator)
        *isCreator = true;

    if (xuid)
        *xuid = 0xB13EBABEBABEBABE;

    return 0;
}

uint32_t XamContentGetDeviceState()
{
    return 0;
}

uint32_t XamUserGetSigninInfo(uint32_t userIndex, uint32_t flags, XUSER_SIGNIN_INFO* info)
{
    if (userIndex == 0)
    {
        memset(info, 0, sizeof(*info));
        info->xuid = 0xB13EBABEBABEBABE;
        info->SigninState = 1;
        strcpy(info->Name, "SWA");
        return 0;
    }

    return 0x00000525; // ERROR_NO_SUCH_USER
}

void XamShowSigninUI()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t XamShowDeviceSelectorUI
(
    uint32_t userIndex,
    uint32_t contentType,
    uint32_t contentFlags,
    uint64_t totalRequested,
    be<uint32_t>* deviceId,
    XXOVERLAPPED* overlapped
)
{
    XamNotifyEnqueueEvent(9, true);
    *deviceId = 1;
    XamNotifyEnqueueEvent(9, false);
    return 0;
}

void XamShowDirtyDiscErrorUI()
{
    // Don't show UI, just return - let boot continue
    MCLA_LOG_INFO("XamShowDirtyDiscErrorUI called (suppressed)");

    // Dump the guest call chain so we can find which media check routed us
    // here. EABI frames: back chain at [sp], saved LR at [sp+4].
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint64_t lr = g_ppcContext ? g_ppcContext->lr : 0;
    uint32_t sp = g_ppcContext ? g_ppcContext->r1.u32 : 0;
    for (int depth = 0; depth < 16; ++depth)
    {
        MCLA_LOG_INFO("  dirty-disc chain[{}]: lr=0x{:08X} sp=0x{:08X}", depth,
                      static_cast<uint32_t>(lr), sp);
        uint32_t nextSp = 0;
        uint32_t nextLr = 0;
        if (sp == 0 || !mem.ReadU32BE(sp, &nextSp) || !mem.ReadU32BE(sp + 4, &nextLr))
            break;
        if (nextSp <= sp || (nextSp & 3) != 0)
            break;
        lr = nextLr;
        sp = nextSp;
    }
    spdlog::default_logger()->flush();
}

void XamEnableInactivityProcessing()
{
    // No-op - inactivity processing not needed for headless boot
}

void XamResetInactivity()
{
    // No-op
}

uint32_t XamShowMessageBoxUIEx(uint32_t userIndex, uint32_t flags, void* title, void* text, uint32_t buttons, uint32_t defaultButton, uint32_t* result, XXOVERLAPPED* overlapped)
{
    (void)userIndex;
    (void)flags;
    (void)title;
    (void)text;
    (void)buttons;
    (void)defaultButton;
    (void)overlapped;
    if (result) *result = 1; // First button
    return 0;
}

void XamLoaderTerminateTitle()
{
    // No-op - don't terminate
    MCLA_LOG_INFO("XamLoaderTerminateTitle called");
    spdlog::default_logger()->flush();
}

void XamGetExecutionId()
{
    // No-op - execution ID not needed
}

void XamLoaderLaunchTitle()
{
    // No-op - don't launch another title
}

uint32_t XamLoaderMediaGetInfo(uint32_t mediaId, void* infoBuffer)
{
    // Xbox 360 media info query. Game expects valid game disc.
    // Returns XAM_MEDIA_TYPE_GAME_DVD (0x0C) on success.
    if (g_ppcContext && infoBuffer)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        // XAM_MEDIA_INFO structure: MediaType(4), MediaFlags(4), MediaId(4), etc.
        uint8_t info[16] = {};
        *reinterpret_cast<uint32_t*>(&info[0]) = __builtin_bswap32(0x0C); // XAM_MEDIA_TYPE_GAME_DVD
        *reinterpret_cast<uint32_t*>(&info[4]) = __builtin_bswap32(0x0);  // MediaFlags
        *reinterpret_cast<uint32_t*>(&info[8]) = __builtin_bswap32(0x0);  // MediaId
        *reinterpret_cast<uint32_t*>(&info[12]) = __builtin_bswap32(0x0); // SessionId
        (void)mem.WriteBytes(g_ppcContext->r4.u32, info, 16);
    }
    return 0; // ERROR_SUCCESS
}

uint32_t XamLoaderGetDvdTrayState()
{
    // Xbox 360 DVD tray state. Must return CLOSED (0) for valid boot.
    return 0; // XAM_LOADER_DVD_TRAY_STATE_CLOSED
}

uint32_t XGetLanguage()
{
    return (uint32_t)Config::Language;
}

uint32_t XGetAVPack()
{
    // Returns the A/V pack type. 3 = HDMI (widescreen/HD).
    // For 1280x720, return 3 (HDMI).
    return 3;
}

void NtOpenFile()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlInitAnsiString(XANSI_STRING* destination, char* source)
{
    const uint16_t length = source ? static_cast<uint16_t>(strlen(source)) : 0;
    
    destination->Length.set(length);
    destination->MaximumLength.set(length + 1);
    destination->Buffer = xpointer<char>(source);
}

uint32_t NtCreateFile
(
    be<uint32_t>* FileHandle,
    uint32_t DesiredAccess,
    XOBJECT_ATTRIBUTES* Attributes,
    XIO_STATUS_BLOCK* IoStatusBlock,
    uint64_t* AllocationSize,
    uint32_t FileAttributes,
    uint32_t ShareAccess,
    uint32_t CreateDisposition,
    uint32_t CreateOptions
)
{
    (void)DesiredAccess;
    (void)FileAttributes;
    (void)ShareAccess;
    (void)CreateDisposition;
    (void)CreateOptions;
    (void)AllocationSize;

    if (!FileHandle || !Attributes || !IoStatusBlock)
    {
        return 0xC000000D; // STATUS_INVALID_PARAMETER
    }

    // Get the object name from attributes
    XANSI_STRING* name = Attributes->Name.get();
    if (!name || !name->Buffer)
    {
        IoStatusBlock->Status.set(0xC0000034); // STATUS_OBJECT_NAME_INVALID
        return 0xC0000034;
    }

    // Read the ANSI string from guest memory
    char guestPath[260];
    uint16_t length = name->Length.get();
    if (length >= sizeof(guestPath)) length = sizeof(guestPath) - 1;
    
    void* srcPtr = mcla::kernel::GuestMemoryHeap::Instance().Translate(name->Buffer.ptr);
    if (!srcPtr)
    {
        IoStatusBlock->Status.set(0xC0000005); // STATUS_ACCESS_VIOLATION
        return 0xC0000005;
    }

    memcpy(guestPath, srcPtr, length);
    guestPath[length] = '\0';

    // Open file via VFS
    std::string virtualPath = mcla::vfs::GuestPathToVirtual(guestPath);
    MCLA_LOG_INFO("NtCreateFile: '{}' -> '{}'", guestPath, virtualPath);

    mcla::vfs::RpfVirtualFileSystem& vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
    mcla::vfs::RpfVirtualFileSystem::OpenFileHandle fileHandle;
    if (!vfs.OpenFile(virtualPath, fileHandle))
    {
        // Raw device opens (\Device\Harddisk0\partition0 etc) have no VFS
        // backing. The boot validation loop treats a failed open as fatal, so
        // hand back an empty pseudo-file instead.
        constexpr auto startsWithDevice = [](const char* p) {
            return std::strncmp(p, "\\Device\\", 8) == 0 || std::strncmp(p, "/Device/", 8) == 0;
        };
        const bool isRawDevice = startsWithDevice(guestPath);
        if (!isRawDevice)
        {
            MCLA_LOG_WARN("NtCreateFile: FAILED '{}' (guest '{}') -> STATUS_OBJECT_NAME_NOT_FOUND",
                          virtualPath, guestPath);
            IoStatusBlock->Status.set(0xC0000034); // STATUS_OBJECT_NAME_NOT_FOUND
            return 0xC0000034;
        }
        MCLA_LOG_INFO("NtCreateFile: raw device '{}' -> empty pseudo-file", guestPath);
        fileHandle = mcla::vfs::RpfVirtualFileSystem::OpenFileHandle{};
        fileHandle.virtual_path = virtualPath;
        fileHandle.size = 0;
        fileHandle.position = 0;
    }

    // Create kernel file object - MUST live in the guest physical heap so the
    // identity handle (its guest VA) round-trips through Translate(). Plain
    // `new` yields host pointers that MapVirtual cannot represent.
    auto* fileObj2 = CreateKernelObject<FileObject>(std::move(fileHandle));
    uint32_t kernelHandle = GetKernelHandle(fileObj2);
    FileHandle->set(kernelHandle);
    MCLA_LOG_INFO("NtCreateFile: '{}' opened, handle={:08X}", virtualPath, kernelHandle);

    IoStatusBlock->Status.set(STATUS_SUCCESS);
    IoStatusBlock->Information.set(1); // FILE_OPENED

    return STATUS_SUCCESS;
}

uint32_t NtClose(uint32_t handle)
{
    if (handle == GUEST_INVALID_HANDLE_VALUE)
        return 0xFFFFFFFF;

    if (IsKernelObject(handle))
    {
        KernelObject* obj = GetKernelObject(handle);
        MCLA_LOG_INFO("NtClose: handle={:08X} valid={}", handle, obj ? obj->IsValid() : false);
        if (obj && obj->IsValid())
        {
            // Try to close VFS file if it's a FileObject
            FileObject* fileObj = dynamic_cast<FileObject*>(obj);
            if (fileObj)
            {
                mcla::vfs::RpfVirtualFileSystem::Instance().CloseFile(fileObj->fileHandle);
            }
            DestroyKernelObject(obj);
        }
        // Handles we don't recognize as host wrappers (raw guest structs the
        // game treats as handles) are simply ignored - closing them must not
        // fault or tear down guest memory.
        return 0;
    }
    else
    {
        return 0;
    }
}


uint32_t NtSetInformationFile(uint32_t handle, XIO_STATUS_BLOCK* ioStatus, void* buffer, uint32_t length, uint32_t infoClass)
{
    (void)handle;
    (void)ioStatus;
    (void)buffer;
    (void)length;
    (void)infoClass;

    // Common info classes: FilePositionInformation (14), FileEndOfFileInformation (20)
    // For now, return success
    if (ioStatus) ioStatus->Status.set(STATUS_SUCCESS);
    return STATUS_SUCCESS;
}

uint32_t FscSetCacheElementCount()
{
    return 0;
}

uint32_t NtWaitForSingleObjectEx(uint32_t Handle, uint32_t WaitMode, uint32_t Alertable, be<int64_t>* Timeout)
{
    // MAIN-THREAD PARK PROBE
    {
        static std::atomic<uint32_t> s_parkLogs2{0};
        uint32_t mainId = g_mainGuestThreadId.load();
        if (mainId != 0 && GetCurrentThreadId() == mainId && s_parkLogs2.fetch_add(1) < 200)
        {
            MCLA_LOG_INFO("[main-park] NtWaitForSingleObjectEx handle={:08X} alertable={} lr={:08X}",
                          Handle, Alertable, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
        }
    }
    uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);
    assert(timeout == 0 || timeout == INFINITE);

    if (IsKernelObject(Handle))
    {
        return GetKernelObject(Handle)->Wait(timeout);
    }
    else
    {
        assert(false && "Unrecognized handle value.");
    }

    return STATUS_TIMEOUT;
}

uint32_t NtWriteFile(uint32_t handle, uint32_t event, uint32_t apcRoutine, uint32_t apcContext, XIO_STATUS_BLOCK* ioStatus, void* buffer, uint32_t length, be<uint64_t>* byteOffset, uint32_t* key)
{
    (void)handle;
    (void)event;
    (void)apcRoutine;
    (void)apcContext;
    (void)key;
    (void)byteOffset;

    if (buffer == nullptr || length == 0)
    {
        if (ioStatus) ioStatus->Status.set(STATUS_SUCCESS);
        return STATUS_SUCCESS;
    }

    auto& guestMem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t bufferAddr = guestMem.MapVirtual(buffer);
    void* hostPtr = (bufferAddr != 0) ? guestMem.Translate(bufferAddr) : nullptr;
    if (!hostPtr)
    {
        if (ioStatus) ioStatus->Status.set(0xC0000005);
        return 0xC0000005;
    }

    if (ioStatus)
    {
        ioStatus->Status.set(STATUS_SUCCESS);
        ioStatus->Information.set(length);
    }
    return STATUS_SUCCESS;
}

void vsprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t ExGetXConfigSetting(uint16_t Category, uint16_t Setting, void* Buffer, uint16_t SizeOfBuffer, be<uint32_t>* RequiredSize)
{
    uint32_t data[4]{};

    switch (Category)
    {
        // XCONFIG_SECURED_CATEGORY
        case 0x0002:
        {
            switch (Setting)
            {
                // XCONFIG_SECURED_AV_REGION
                case 0x0002:
                    data[0] = ByteSwap(0x00001000); // USA/Canada
                    break;

                default:
                    return 1;
            }
        }

        case 0x0003:
        {
            switch (Setting)
            {
                case 0x0001: // XCONFIG_USER_TIME_ZONE_BIAS
                case 0x0002: // XCONFIG_USER_TIME_ZONE_STD_NAME
                case 0x0003: // XCONFIG_USER_TIME_ZONE_DLT_NAME
                case 0x0004: // XCONFIG_USER_TIME_ZONE_STD_DATE
                case 0x0005: // XCONFIG_USER_TIME_ZONE_DLT_DATE
                case 0x0006: // XCONFIG_USER_TIME_ZONE_STD_BIAS
                case 0x0007: // XCONFIG_USER_TIME_ZONE_DLT_BIAS
                    data[0] = 0;
                    break;

                // XCONFIG_USER_LANGUAGE
                case 0x0009:
                    data[0] = ByteSwap((uint32_t)Config::Language);
                    break;

                // XCONFIG_USER_VIDEO_FLAGS
                case 0x000A:
                    data[0] = ByteSwap(0x00040000);
                    break;

                // XCONFIG_USER_RETAIL_FLAGS
                case 0x000C:
                    data[0] = ByteSwap(1);
                    break;

                // XCONFIG_USER_COUNTRY
                case 0x000E:
                    data[0] = ByteSwap(103);
                    break;

                default:
                    return 1;
            }
        }
    }

    *RequiredSize = 4;
    memcpy(Buffer, data, std::min((size_t)SizeOfBuffer, sizeof(data)));

    return 0;
}

void NtQueryVirtualMemory()
{
    LOG_UTILITY("!!! STUB !!!");
}

void MmQueryStatistics()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t NtCreateEvent(be<uint32_t>* handle, void* objAttributes, uint32_t eventType, uint32_t initialState)
{
    *handle = GetKernelHandle(CreateKernelObject<Event>(!eventType, !!initialState));
    return 0;
}

uint32_t XexCheckExecutablePrivilege()
{
    // Returns 1 if the executable has the required privilege (signed, valid signature, etc.)
    // For dev mode: always return success so the game proceeds past the XEX check
    return 1;
}

void DbgPrint()
{
    LOG_UTILITY("!!! STUB !!!");
}

void __C_specific_handler_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlNtStatusToDosError()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XexGetProcedureAddress()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XexGetModuleSection()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t RtlUnicodeToMultiByteN(char* MultiByteString, uint32_t MaxBytesInMultiByteString, be<uint32_t>* BytesInMultiByteString, const be<uint16_t>* UnicodeString, uint32_t BytesInUnicodeString)
{
    const auto reqSize = BytesInUnicodeString / sizeof(uint16_t);

    if (BytesInMultiByteString)
        BytesInMultiByteString->set(reqSize);

    if (reqSize > MaxBytesInMultiByteString)
        return STATUS_FAIL_CHECK;

    const be<uint16_t>* src = UnicodeString;
    if (!src)
        return STATUS_FAIL_CHECK;

    for (size_t i = 0; i < reqSize; i++)
    {
        uint16_t c = src[i].get();

        MultiByteString[i] = c < 256 ? static_cast<char>(c) : '?';
    }

    return STATUS_SUCCESS;
}

uint32_t KeDelayExecutionThread(uint32_t WaitMode, bool Alertable, be<int64_t>* Timeout)
{
    // We don't do async file reads.
    if (Alertable)
        return STATUS_USER_APC;

    uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);

    // MAIN-THREAD PARK PROBE: name where the guest main loop sleeps.
    {
        static std::atomic<uint32_t> s_parkLogs{0};
        uint32_t mainId = g_mainGuestThreadId.load();
        if (mainId != 0 && GetCurrentThreadId() == mainId && timeout >= 8 &&
            s_parkLogs.fetch_add(1) < 200)
        {
            MCLA_LOG_INFO("[main-park] KeDelayExecutionThread timeout={}ms lr={:08X}",
                          timeout, static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
        }
    }

#ifdef _WIN32
    Sleep(timeout);
#else
    if (timeout == 0)
        std::this_thread::yield();
    else
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
#endif

    return STATUS_SUCCESS;
}

void ExFreePool()
{
    LOG_UTILITY("!!! STUB !!!");
}

// NtQueryInformationFile: real typed implementation lives above (near
// NtCreateFile) - it answers X_FILE_STANDARD_INFORMATION with true sizes.

// NOTE: no-arg stubs for these three used to sit here UNWIRED - the game's
// metadata queries fell through to generated weak defaults returning garbage,
// which is exactly why packfile loading reported "Cannot load archive" without
// a single read. All three are typed + hooked now.

uint32_t NtQueryVolumeInformationFile(uint32_t handle, XIO_STATUS_BLOCK* ioStatus, void* fsInfo, uint32_t length, uint32_t infoClass)
{
    (void)handle;
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    MCLA_LOG_INFO("NtQueryVolumeInformationFile: class={} len={}", infoClass, length);
    if (fsInfo)
    {
        // zero-filled volume info = "empty fixed volume"; refine per class when
        // boot proves it matters
        const uint32_t addr = mem.MapVirtual(fsInfo);
        const uint32_t n = std::min<uint32_t>(length, 64);
        for (uint32_t off = 0; addr != 0 && off < n; off += 4) (void)mem.WriteU32BE(addr + off, 0);
    }
    if (ioStatus)
    {
        ioStatus->Status.set(STATUS_SUCCESS);
        ioStatus->Information.set(fsInfo ? std::min<uint32_t>(length, 64) : 0);
    }
    return STATUS_SUCCESS;
}

uint32_t NtQueryDirectoryFile(uint32_t handle, uint32_t event, uint32_t apcRoutine, uint32_t apcContext, XIO_STATUS_BLOCK* ioStatus, void* fileInformation, uint32_t length, uint32_t infoClass, uint32_t singleEntry, uint32_t dirIndex, uint32_t restartScan)
{
    (void)handle; (void)event; (void)apcRoutine; (void)apcContext;
    (void)fileInformation; (void)length; (void)infoClass; (void)singleEntry; (void)dirIndex; (void)restartScan;
    MCLA_LOG_INFO("NtQueryDirectoryFile: class={}", infoClass);
    if (ioStatus) ioStatus->Status.set(0x80000006); // STATUS_NO_MORE_FILES
    return 0x80000006;
}

uint32_t NtReadFile(uint32_t handle, uint32_t event, uint32_t apcRoutine, uint32_t apcContext, XIO_STATUS_BLOCK* ioStatus, void* buffer, uint32_t length, be<uint64_t>* byteOffset, uint32_t* key)
{
    (void)event;
    (void)apcRoutine;
    (void)apcContext;
    (void)key;

    if (buffer == nullptr || length == 0)
    {
        if (ioStatus) ioStatus->Status.set(STATUS_SUCCESS);
        return STATUS_SUCCESS;
    }

    auto& guestMem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t bufferAddr = guestMem.MapVirtual(buffer);
    void* hostPtr = (bufferAddr != 0) ? guestMem.Translate(bufferAddr) : nullptr;
    if (!hostPtr)
    {
        if (ioStatus) ioStatus->Status.set(0xC0000005);
        return 0xC0000005;
    }

    // SECURITY: clamp length so the write stays inside the guest window -
    // Translate() only validates the buffer START, a huge length would
    // otherwise write out-of-bounds host memory past the window end.
    {
        auto& heapForBounds = mcla::kernel::GuestMemoryHeap::Instance();
        const uint64_t winSize = heapForBounds.Size();
        const uint64_t bufOff = bufferAddr;
        if (bufOff < winSize && length > winSize - bufOff)
        {
            length = static_cast<uint32_t>(winSize - bufOff);
        }
    }

    // Resolve the kernel file object and serve real bytes from the VFS.
    FileObject* fileObj = nullptr;
    if (handle != GUEST_INVALID_HANDLE_VALUE && IsKernelObject(handle))
    {
        KernelObject* obj = GetKernelObject(handle);
        if (obj && obj->IsValid()) fileObj = dynamic_cast<FileObject*>(obj);
    }

    uint64_t bytesRead = 0;
    bool ok = false;
    if (fileObj)
    {
        auto& vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
        uint64_t offset = 0;
        if (byteOffset)
        {
            offset = byteOffset->get();
            vfs.SeekFile(fileObj->fileHandle, static_cast<int64_t>(offset), 0 /* FILE_BEGIN */);
        }
        else
        {
            offset = fileObj->fileHandle.position;
        }
        ok = vfs.ReadFile(fileObj->fileHandle, hostPtr, length, bytesRead);
        MCLA_LOG_DEBUG("NtReadFile: h={:08X} off={:#x} len={} -> {} bytes", handle, offset, length, bytesRead);
    }
    else
    {
        // Non-VFS handles (device opens etc): zero-fill keeps legacy behavior.
        std::memset(hostPtr, 0, length);
        bytesRead = length;
        ok = true;
    }

    if (ioStatus)
    {
        ioStatus->Status.set(ok ? STATUS_SUCCESS : 0xC000000D);
        ioStatus->Information.set(static_cast<uint64_t>(bytesRead));
    }
    return ok ? STATUS_SUCCESS : 0xC000000D;
}

uint32_t NtReadFileScatter()
{
    LOG_UTILITY("!!! STUB !!!");
    return STATUS_SUCCESS;
}

void NtDuplicateObject()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t NtAllocateVirtualMemory(be<uint32_t>* baseAddress, be<uint32_t>* regionSize, uint32_t allocationType, uint32_t protect)
{
    uint32_t base = baseAddress ? baseAddress->get() : 0;
    uint32_t size = regionSize ? regionSize->get() : 0;

    if (base != 0)
    {
        void* ptr = mcla::kernel::GuestMemoryHeap::Instance().Translate(base);
        if (ptr)
        {
            *regionSize = size;
            return 0;
        }
    }

    void* ptr = g_userHeap.AllocPhysical(size, 0x1000);
    uint32_t guestAddr = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(ptr);
    MmTrackAllocationSize(guestAddr, size);

    if (baseAddress) baseAddress->set(guestAddr);
    if (regionSize) regionSize->set(size);

    return 0;
}

uint32_t NtFreeVirtualMemory(be<uint32_t>* baseAddress, be<uint32_t>* regionSize, uint32_t freeType)
{
    uint32_t base = baseAddress ? baseAddress->get() : 0;
    if (base == 0)
    {
        return 0;
    }

    void* ptr = mcla::kernel::GuestMemoryHeap::Instance().Translate(base);
    if (ptr)
    {
        g_userHeap.Free(ptr);
    }

    return 0;
}

void ObDereferenceObject(uint32_t object)
{
    (void)object;
    // In the identity handle model, dereferencing is a no-op
    // The kernel object is managed by the handle table
    // Object lifetime is tied to handle count
}

void KeSetBasePriorityThread(GuestThreadHandle* hThread, int priority)
{
#ifdef _WIN32
    if (priority == 16)
    {
        priority = 15;
    }
    else if (priority == -16)
    {
        priority = -15;
    }

    SetThreadPriority(hThread == GetKernelObject(CURRENT_THREAD_HANDLE) ? GetCurrentThread() : hThread->thread.native_handle(), priority);
#endif
}

uint32_t ObReferenceObjectByHandle(uint32_t handle, uint32_t objectType, be<uint32_t>* object)
{
    *object = handle;
    return 0;
}

void KeQueryBasePriorityThread()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t NtSuspendThread(GuestThreadHandle* hThread, uint32_t* suspendCount)
{
    assert(hThread != GetKernelObject(CURRENT_THREAD_HANDLE) && hThread->GetThreadId() == GuestThread::GetCurrentThreadId());

    hThread->suspended = true;
    hThread->suspended.wait(true);

    return S_OK;
}

uint32_t KeSetAffinityThread(uint32_t Thread, uint32_t Affinity, be<uint32_t>* lpPreviousAffinity)
{
    if (lpPreviousAffinity)
        *lpPreviousAffinity = 2;

    return 0;
}

void RtlLeaveCriticalSection(XRTL_CRITICAL_SECTION* cs)
{
    int32_t recursionCount = cs->RecursionCount;
    if (recursionCount > 0)
    {
        recursionCount--;
        cs->RecursionCount = recursionCount;
    }

    if (recursionCount != 0)
        return;

    std::atomic_ref owningThread(cs->OwningThread);
    owningThread.store(0);
    owningThread.notify_one();
}

void RtlEnterCriticalSection(XRTL_CRITICAL_SECTION* cs)
{
    uint32_t thisThread = g_ppcContext->r13.u32;
    assert(thisThread != NULL);

    std::atomic_ref owningThread(cs->OwningThread);

    while (true)
    {
        uint32_t previousOwner = 0;

        if (owningThread.compare_exchange_weak(previousOwner, thisThread) || previousOwner == thisThread)
        {
            cs->RecursionCount++;
            return;
        }

        owningThread.wait(previousOwner);
    }
}

void RtlImageXexHeaderField()
{
    LOG_UTILITY("!!! STUB !!!");
}

void HalReturnToFirmware(uint32_t type)
{
    // Terminates, never returns - but MCLA calls it mid-boot and continues
    // Must return (not std::exit) or process dies
    MCLA_LOG_INFO("HalReturnToFirmware: type={}", type);
    // Return to caller - game will continue
}

void RtlFillMemoryUlong()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeBugCheckEx()
{
    __builtin_debugtrap();
}

uint32_t KeGetCurrentProcessType()
{
    return 1;
}

void RtlCompareMemoryUlong()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t RtlInitializeCriticalSection(XRTL_CRITICAL_SECTION* cs)
{
    cs->Header.Absolute = 0;
    cs->LockCount = -1;
    cs->RecursionCount = 0;
    cs->OwningThread = 0;

    return 0;
}

void RtlRaiseException_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KfReleaseSpinLock(uint32_t* spinLock)
{
    std::atomic_ref spinLockRef(*spinLock);
    spinLockRef = 0;
}

void KfAcquireSpinLock(uint32_t* spinLock)
{
    std::atomic_ref spinLockRef(*spinLock);

    while (true)
    {
        uint32_t expected = 0;
        if (spinLockRef.compare_exchange_weak(expected, g_ppcContext->r13.u32))
            break;

        std::this_thread::yield();
    }
}

uint64_t KeQueryPerformanceFrequency()
{
    return 49875000;
}

void MmFreePhysicalMemory(uint32_t type, uint32_t guestAddress)
{
    if (guestAddress != NULL)
        g_userHeap.Free(mcla::kernel::GuestMemoryHeap::Instance().Translate(guestAddress));
}

bool VdPersistDisplay(uint32_t a1, uint32_t* a2)
{
    *a2 = NULL;
    return false;
}

void VdSwap(uint32_t buf, uint32_t fetch, uint32_t unk2, uint32_t unk3, uint32_t unk4, uint32_t fbuf, uint32_t fmt, uint32_t cs, uint32_t w, uint32_t h)
{
    MCLA_LOG_INFO("VdSwap: buf=0x{:08X} fetch=0x{:08X} unk2=0x{:08X} unk3=0x{:08X} unk4=0x{:08X} fbuf=0x{:08X} fmt=0x{:08X} cs=0x{:08X} w={} h={}",
        buf, fetch, unk2, unk3, unk4, fbuf, fmt, cs, w, h);
    // Present callback - chain to native renderer hook
}

void VdGetSystemCommandBuffer(uint32_t p0, uint32_t p1)
{
    // Xenia: p0.Zero(0x94), write 0xBEEF0000@p0, 0xBEEF0001@p1
    if (p0)
    {
        static const uint8_t zeroBuf[0x94] = {0};
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteBytes(p0, zeroBuf, 0x94);
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(p0, 0xBEEF0000);
    }
    if (p1)
    {
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(p1, 0xBEEF0001);
    }
}

void KeReleaseSpinLockFromRaisedIrql(uint32_t* spinLock)
{
    std::atomic_ref spinLockRef(*spinLock);
    spinLockRef = 0;
}

void KeAcquireSpinLockAtRaisedIrql(uint32_t* spinLock)
{
    std::atomic_ref spinLockRef(*spinLock);

    while (true)
    {
        uint32_t expected = 0;
        if (spinLockRef.compare_exchange_weak(expected, g_ppcContext->r13.u32))
            break;

        std::this_thread::yield();
    }
}

void KeInitializeSpinLock(uint32_t* spinLock)
{
    // Spinlock init (guest memory) - zero the spinlock
    *spinLock = 0;
}

uint32_t KiApcNormalRoutineNop()
{
    return 0;
}

void VdEnableRingBufferRPtrWriteBack(uint32_t ringBuffer, uint32_t blockSizeLog2)
{
    // Xenia: r3 IS the read-pointer writeback address (CP_RB_RPTR_ADDR),
    // not a ring base. The host CP publishes the advanced dword index there.
    MCLA_LOG_INFO("VdEnableRingBufferRPtrWriteBack: writeback=0x{:08X} blockLog2={}", ringBuffer, blockSizeLog2);
    mcla::gpu::CpEnableRPtrWriteBack(ringBuffer, blockSizeLog2);
}

void VdInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2)
{
    // Xenia: r3=phys addr, r4=log2 size, ring size=1<<(log2+3), zero ring
    uint32_t ringSize = 1u << (sizeLog2 + 3);
    MCLA_LOG_INFO("VdInitializeRingBuffer: physAddr=0x{:08X} sizeLog2={} ringSize={}", physAddr, sizeLog2, ringSize);
    if (physAddr)
    {
        std::vector<uint8_t> zeroBuf(ringSize, 0);
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteBytes(physAddr, zeroBuf.data(), ringSize);
        mcla::gpu::CpInitializeRingBuffer(physAddr, sizeLog2);
    }
}

void VdSetSystemCommandBufferGpuIdentifierAddress(uint32_t gpuIdAddr)
{
    MCLA_LOG_INFO("VdSetSystemCommandBufferGpuIdentifierAddress: 0x{:08X}", gpuIdAddr);
    // GPU init plumbing - store the GPU identifier address
}

void _vsnprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void sprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ExRegisterTitleTerminateNotification()
{
    LOG_UTILITY("!!! STUB !!!");
}

void VdShutdownEngines()
{
    LOG_UTILITY("!!! STUB !!!");
}

void VdQueryVideoMode(XVIDEO_MODE* vm)
{
    memset(vm, 0, sizeof(XVIDEO_MODE));
    vm->DisplayWidth = 1280;
    vm->DisplayHeight = 720;
    vm->IsInterlaced = false;
    vm->IsWidescreen = true;
    vm->IsHighDefinition = true;
    vm->RefreshRate = 0x42700000;
    vm->VideoStandard = 1;
    vm->Unknown4A = 0x4A;
    vm->Unknown01 = 0x01;
}

void VdGetCurrentDisplayInformation()
{
    LOG_UTILITY("!!! STUB !!!");
}

void VdSetDisplayMode()
{
    LOG_UTILITY("!!! STUB !!!");
}

void VdSetGraphicsInterruptCallback(uint32_t callback, uint32_t userData)
{
    MCLA_LOG_INFO("VdSetGraphicsInterruptCallback: callback=0x{:08X} user=0x{:08X}", callback, userData);

    static std::atomic<uint32_t> s_vsyncCallback{0};
    static std::atomic<uint32_t> s_vsyncUserData{0};
    static std::atomic<bool> s_vsyncRunning{false};
    static uint32_t s_frameCounter = 0;

    s_vsyncCallback.store(callback);
    s_vsyncUserData.store(userData);

    if (!s_vsyncRunning.exchange(true))
    {
        std::thread([=]() {
            MCLA_LOG_INFO("VSync thread started: callback=0x{:08X}", callback);
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60fps
                uint32_t currentCallback = s_vsyncCallback.load();
                uint32_t currentUserData = s_vsyncUserData.load();
                if (currentCallback != 0)
                {
                    uint8_t* base = mcla::kernel::g_memory.base;
                    PPCFunc* fn = PPC_LOOKUP_FUNC(base, currentCallback);
                    if (fn)
                    {
                        PPCContext cbCtx{};
                        // r3 = INTERRUPT TYPE, not userData (decoded from
                        // generated sub_82411478): 0 = graphics interrupt ->
                        // runs the command-buffer processor Function_82419718,
                        // 1 = vsync event -> releases the frame semaphore.
                        // r4 carries the userData (GPU context pointer).
                        cbCtx.r3.u32 = 0;
                        cbCtx.r4.u32 = currentUserData; // GPU context pointer
                        cbCtx.r5.u32 = 0; // field counter
                        cbCtx.r13.u32 = 0x8F200000; // thread block pointer (from boot_host.cpp)
                        cbCtx.r1.u32 = 0x8F000000; // stack top (from boot_host.cpp)
                        cbCtx.lr = 0x00FFFFFF; // dummy LR
                        cbCtx.msr = 0x200A000;

                        // Publish this thread's context so guest imports can read TLS/TEB/r13
                        SetPPCContext(cbCtx);

                        MCLA_LOG_INFO("VSync: calling callback 0x{:08X} with userData=0x{:08X} (frame={})",
                                      currentCallback, currentUserData, s_frameCounter++);

                        // Ring-buffer submission probe: sample the head of the
                        // primary ring every ~2s (120 frames) to see whether
                        // the game ever writes PM4 packets for us to consume.
                        if ((s_frameCounter % 120) == 0)
                        {
                            auto& memProbe = mcla::kernel::GuestMemoryHeap::Instance();
                            uint32_t ctxPtr = 0;
                            if (memProbe.ReadU32BE(0x82839254, &ctxPtr) && ctxPtr != 0)
                            {
                                uint32_t p0 = 0, p1 = 0;
                                const bool p0Ok = memProbe.ReadU32BE(ctxPtr + 0x30, &p0);
                                const bool p1Ok = memProbe.ReadU32BE(ctxPtr + 0x38, &p1);
                                uint8_t head[8] = {};
                                bool headOk = true;
                                for (int bi = 0; bi < 8; ++bi)
                                    headOk &= memProbe.ReadU8(0xC6224480 + static_cast<uint32_t>(bi), &head[bi]);
                                if (p0Ok && p1Ok && headOk)
                                {
                                    MCLA_LOG_INFO("RING: ctx+30={:08X} ctx+38={:08X} head={:02X}{:02X}{:02X}{:02X} {:02X}{:02X}{:02X}{:02X}",
                                                  p0, p1, head[0], head[1], head[2], head[3],
                                                  head[4], head[5], head[6], head[7]);
                                }
                            }
                        }

                        fn(cbCtx, base);
                        MCLA_LOG_INFO("VSync: callback returned");
                    }
                }
            }
        }).detach();
    }
}

uint32_t VdInitializeEngines(uint32_t unk, uint32_t cb, uint32_t arg, uint32_t pfp, uint32_t me)
{
    MCLA_LOG_INFO("VdInitializeEngines: unk=0x{:08X} cb=0x{:08X} arg=0x{:08X} pfp=0x{:08X} me=0x{:08X}", unk, cb, arg, pfp, me);

    // Xenia: r3=0x4E810000, returns 2. Must fully init GPU context:
    // spinlocks at +0x4148, +0x4158, cmd buffer at +0x30/+0x38, present callback at +0x40A0
    // The GPU context is allocated by the game. We initialize the structure at the
    // address the game provides (typically via a global pointer).

    // The game stores the GPU context pointer at a known global address.
    // Based on Xenia and MCLA analysis, the GPU context pointer is at 0x82839254.
    constexpr uint32_t gpuCtxPtrAddr = 0x82839254;
    uint32_t gpuCtxPtr = 0;
    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtrAddr, &gpuCtxPtr);

    if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000)
    {
        // Initialize spinlocks at +0x4148 and +0x4158
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x4148, 0);
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x4158, 0);

        // Initialize command buffer pointers at +0x30 and +0x38
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x30, 0);
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x38, 0);

        // Present callback at +0x40A0 - will be set by VdSetGraphicsInterruptCallback chain
        // The game sets this up; we don't manually seed it here.
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x40A0, 0);
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0x40A4, 0);

        // State field at +0xD0 (checked by Function_824E37E0)
        (void)mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(gpuCtxPtr + 0xD0, 1);

        MCLA_LOG_INFO("VdInitializeEngines: initialized GPU context at 0x{:08X}", gpuCtxPtr);
    }
    else
    {
        MCLA_LOG_WARN("VdInitializeEngines: GPU context pointer not set at 0x82839254");
    }

    return 2;
}

// Manual GPU backend initialization - replicates ReinitGpuBackend logic
// Call this after boot to trigger graphics initialization
void InitGpuBackendManual(uint32_t gpuCtxPtr)
{
    MCLA_LOG_INFO("InitGpuBackendManual: Starting manual GPU backend initialization for GPU context 0x{:08X}", gpuCtxPtr);

    // Call VdInitializeEngines with same args as ReinitGpuBackend
    // r3=0x1B530000, r4=0x82425D78, r5=0, r6=0x82066110, r7=0x82066590
    VdInitializeEngines(0x1B530000, 0x82425D78, 0, 0x82066110, 0x82066590);

    // Call VdSetGraphicsInterruptCallback with VSync callback 0x82411478 and userData = GPU context
    VdSetGraphicsInterruptCallback(0x82411478, gpuCtxPtr);

    // Initialize ring buffer
    uint32_t ring_buf = 0;
    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtr + 14836, &ring_buf);
    if (ring_buf != 0)
    {
        MCLA_LOG_INFO("InitGpuBackendManual: Initializing ring buffer 0x{:08X}", ring_buf);
        VdInitializeRingBuffer(ring_buf, 12);
        VdEnableRingBufferRPtrWriteBack(ring_buf, 12); // blockSizeLog2=12 for 4KB blocks
    }

    // Initialize sub context
    uint32_t sub_ctx = 0;
    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtr + 10896, &sub_ctx);
    if (sub_ctx != 0)
    {
        MCLA_LOG_INFO("InitGpuBackendManual: Initializing sub context 0x{:08X}", sub_ctx);
        VdInitializeRingBuffer(sub_ctx + 60, 19);
        VdEnableRingBufferRPtrWriteBack(sub_ctx + 60, 19);
    }

    MCLA_LOG_INFO("InitGpuBackendManual: GPU backend initialization complete");
}

// Background poller for GPU context allocation
static std::atomic<bool> s_gpuInitDone{false};
static std::atomic<bool> s_gpuPollerRunning{false};

void StartGpuContextPoller()
{
    if (s_gpuPollerRunning.exchange(true))
        return;

    std::thread([]() {
        MCLA_LOG_INFO("GpuContextPoller: Started polling for GPU context at 0x82839254");
        while (!s_gpuInitDone.load())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
            constexpr uint32_t gpuCtxPtrAddr = 0x82839254;
            uint32_t gpuCtxPtr = 0;
            (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(gpuCtxPtrAddr, &gpuCtxPtr);
            
            if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000 && !s_gpuInitDone.load())
            {
                MCLA_LOG_INFO("GpuContextPoller: GPU context allocated at 0x{:08X}, initializing...", gpuCtxPtr);
                if (!s_gpuInitDone.exchange(true))
                {
                    InitGpuBackendManual(gpuCtxPtr);
                }
                break;
            }
        }
        MCLA_LOG_INFO("GpuContextPoller: Stopped");
    }).detach();
}

void VdQueryVideoFlags(uint32_t* flags)
{
    // Xenia: widescreen?1 | width>=1280?2 | width>=1920?4
    // 1280x720: widescreen=1, width>=1280=1 -> 1|2 = 3
    if (flags)
    {
        *flags = 3;
    }
    MCLA_LOG_INFO("VdQueryVideoFlags: returning 3 (widescreen|width>=1280)");
}

void VdCallGraphicsNotificationRoutines()
{
    LOG_UTILITY("!!! STUB !!!");
}

void VdInitializeScalerCommandBuffer()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeLeaveCriticalRegion()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t VdRetrainEDRAM()
{
    return 0;
}

void VdRetrainEDRAMWorker()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t VdIsHSIOTrainingSucceeded()
{
    // Return 1 (succeeded) to allow boot to continue
    return 1;
}

void VdGetCurrentDisplayGamma()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeEnterCriticalRegion()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t MmAllocatePhysicalMemoryEx
(
    uint32_t flags,
    uint32_t size,
    uint32_t protect,
    uint32_t minAddress,
    uint32_t maxAddress,
    uint32_t alignment
)
{
    LOGF_UTILITY("0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}, 0x{:x}", flags, size, protect, minAddress, maxAddress, alignment);
    void* ptr = g_userHeap.AllocPhysical(size, alignment);
    if (!ptr)
    {
        static std::atomic<uint32_t> s_allocFails{0};
        if (s_allocFails.fetch_add(1) < 50)
            MCLA_LOG_WARN("MmAllocatePhysicalMemoryEx: FAILED size={:#x} align={:#x} (count={})",
                          size, alignment, s_allocFails.load());
        return 0;
    }
    uint32_t guestAddr = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(ptr);
    MmTrackAllocationSize(guestAddr, size);
    return guestAddr;
}

uint32_t MmGetPhysicalAddress(uint32_t address)
{
    LOGF_UTILITY("0x{:x}", address);
    return address;
}

void ObDeleteSymbolicLink()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ObCreateSymbolicLink()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t MmQueryAddressProtect(uint32_t guestAddress)
{
    return PAGE_READWRITE;
}

void VdEnableDisableClockGating()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeBugCheck()
{
    __builtin_debugtrap();
}

void KeLockL2()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeUnlockL2()
{
    LOG_UTILITY("!!! STUB !!!");
}

bool KeSetEvent(XKEVENT* pEvent, uint32_t Increment, bool Wait)
{
    bool result = QueryKernelObject<Event>(*pEvent)->Set();

    ++g_keSetEventGeneration;
    g_keSetEventGeneration.notify_all();

    return result;
}

bool KeResetEvent(XKEVENT* pEvent)
{
    return QueryKernelObject<Event>(*pEvent)->Reset();
}

uint32_t KeWaitForSingleObject(XDISPATCHER_HEADER* Object, uint32_t WaitReason, uint32_t WaitMode, bool Alertable, be<int64_t>* Timeout)
{
    // MAIN-THREAD PARK PROBE
    {
        static std::atomic<uint32_t> s_parkLogs3{0};
        uint32_t mainId = g_mainGuestThreadId.load();
        if (mainId != 0 && GetCurrentThreadId() == mainId && s_parkLogs3.fetch_add(1) < 200)
        {
            MCLA_LOG_INFO("[main-park] KeWaitForSingleObject obj={:08X} reason={} lr={:08X}",
                          static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Object)), WaitReason,
                          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
        }
    }
    const uint32_t timeout = GuestTimeoutToMilliseconds(Timeout);
    assert(timeout == 0 || timeout == INFINITE);

    uint8_t type = Object->Type;

    switch (type)
    {
        case 0:
        case 1:
            QueryKernelObject<Event>(*Object)->Wait(timeout);
            break;

        case 5:
            QueryKernelObject<Semaphore>(*Object)->Wait(timeout);
            break;

        default:
            assert(false && "Unrecognized kernel object type.");
            return STATUS_TIMEOUT;
    }

    return STATUS_SUCCESS;
}

static std::vector<size_t> g_tlsFreeIndices;
static size_t g_tlsNextIndex = 0;
static Mutex g_tlsAllocationMutex;

static uint32_t& KeTlsGetValueRef(size_t index)
{
    // Having this a global thread_local variable
    // for some reason crashes on boot in debug builds.
    thread_local std::vector<uint32_t> s_tlsValues;

    if (s_tlsValues.size() <= index)
    {
        s_tlsValues.resize(index + 1, 0);
    }

    return s_tlsValues[index];
}

uint32_t KeTlsGetValue(uint32_t dwTlsIndex)
{
    return KeTlsGetValueRef(dwTlsIndex);
}

uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue)
{
    KeTlsGetValueRef(dwTlsIndex) = lpTlsValue;
    return TRUE;
}

uint32_t KeTlsAlloc()
{
    std::lock_guard<Mutex> lock(g_tlsAllocationMutex);
    if (!g_tlsFreeIndices.empty())
    {
        size_t index = g_tlsFreeIndices.back();
        g_tlsFreeIndices.pop_back();
        return index;
    }

    return g_tlsNextIndex++;
}

uint32_t KeTlsFree(uint32_t dwTlsIndex)
{
    std::lock_guard<Mutex> lock(g_tlsAllocationMutex);
    g_tlsFreeIndices.push_back(dwTlsIndex);
    return TRUE;
}

uint32_t XMsgInProcessCall(uint32_t app, uint32_t message, be<uint32_t>* param1, be<uint32_t>* param2)
{
    if (message == 0x7001B)
    {
        uint32_t param1_val = param1 ? param1->get() : 0;
        if (param1_val > 1)
        {
            uint32_t* ptr = reinterpret_cast<uint32_t*>(mcla::kernel::GuestMemoryHeap::Instance().Translate(param1_val + 1 * sizeof(uint32_t)));
            if (ptr)
            {
                ptr[0] = 0;
                ptr[1] = 0;
            }
        }
    }

    return 0;
}

void XamUserReadProfileSettings
(
    uint32_t titleId,
    uint32_t userIndex,
    uint32_t xuidCount,
    uint64_t* xuids,
    uint32_t settingCount,
    uint32_t* settingIds,
    be<uint32_t>* bufferSize,
    void* buffer,
    void* overlapped
)
{
    if (buffer != nullptr)
    {
        memset(buffer, 0, *bufferSize);
    }
    else
    {
        *bufferSize = 4;
    }
}

// NOTE: NetDll_* exports take a leading selector arg (generated wrappers pass
// r3=1 before the real WinSock args â€” see sub_8244A258 in generated code).
uint32_t NetDll_WSAStartup(uint32_t dllSelector, uint16_t versionRequested, void* wsaData)
{
    // WinSock 1.1-style WSADATA on 360 (Xenia xboxkrnl_net.cc semantics):
    // wVersion@0, wHighVersion@2, szDescription@4, szSystemStatus@261,
    // iMaxSockets@390, iMaxUdpDg@392, lpVendorInfo@396.
    // Evidence (generated sub_821E44A0): the game re-reads wVersion and only
    // accepts the exact word the caller passed (0x0002 here) â€” store it
    // verbatim, big-endian, no MAKEWORD reshuffling.
    const uint16_t reportedVersion = static_cast<uint16_t>(versionRequested);
    constexpr uint16_t kHighVersion = 0x0202;
    (void)dllSelector;

    if (wsaData)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        const uint32_t base = mem.MapVirtual(wsaData);
        if (base != 0)
        {
            (void)mem.WriteU16BE(base + 0, reportedVersion);   // wVersion = echoed request
            (void)mem.WriteU16BE(base + 2, kHighVersion);      // wHighVersion

            const char description[] = "MCLA native recomp winsock 2.2";
            (void)mem.WriteBytes(base + 4, description, sizeof(description));
            const char systemStatus[] = "Running";
            (void)mem.WriteBytes(base + 261, systemStatus, sizeof(systemStatus));

            (void)mem.WriteU16BE(base + 390, 1024);            // iMaxSockets
            (void)mem.WriteU16BE(base + 392, 64);              // iMaxUdpDg
            (void)mem.WriteU32BE(base + 396, 0);               // lpVendorInfo = NULL
        }
    }
    return 0; // SUCCESS
}

uint32_t NetDll_WSACleanup()
{
    return 0; // Success
}

uint32_t NetDll_socket(int af, int type, int protocol)
{
    (void)af;
    (void)type;
    (void)protocol;
    return 0xFFFFFFFF; // INVALID_SOCKET
}

uint32_t NetDll_closesocket(uint32_t s)
{
    (void)s;
    return 0; // Success
}

uint32_t NetDll_setsockopt(uint32_t s, int level, int optname, const char* optval, int optlen)
{
    (void)s;
    (void)level;
    (void)optname;
    (void)optval;
    (void)optlen;
    return 0; // Success
}

uint32_t NetDll_bind(uint32_t s, void* addr, int namelen)
{
    (void)s;
    (void)addr;
    (void)namelen;
    return 0; // Success
}

uint32_t NetDll_connect(uint32_t s, void* addr, int namelen)
{
    (void)s;
    (void)addr;
    (void)namelen;
    return 0; // Success
}

uint32_t NetDll_listen(uint32_t s, int backlog)
{
    (void)s;
    (void)backlog;
    return 0; // Success
}

uint32_t NetDll_accept(uint32_t s, void* addr, int* addrlen)
{
    (void)s;
    (void)addr;
    (void)addrlen;
    return 0xFFFFFFFF; // INVALID_SOCKET
}

uint32_t NetDll_select(int nfds, void* readfds, void* writefds, void* exceptfds, void* timeout)
{
    (void)nfds;
    (void)readfds;
    (void)writefds;
    (void)exceptfds;
    (void)timeout;
    return 0; // Success
}

uint32_t NetDll_recv(uint32_t s, void* buf, int len, int flags)
{
    (void)s;
    (void)buf;
    (void)len;
    (void)flags;
    return 0; // Success (0 bytes received)
}

uint32_t NetDll_send(uint32_t s, const void* buf, int len, int flags)
{
    (void)s;
    (void)buf;
    (void)len;
    (void)flags;
    return len; // Success (all bytes sent)
}

PPC_FUNC(__imp__NetDll_inet_addr)
{
    // r3 = cp (const char*)
    // Return INADDR_NONE (0xFFFFFFFF) in r3
    ctx.r3.u32 = 0xFFFFFFFF;
}

PPC_FUNC(__imp__NetDll___WSAFDIsSet)
{
    // r3 = fd, r4 = set
    // Return 0 (not set) in r3
    ctx.r3.u32 = 0;
}

void NetDll___WSAFDIsSet()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XMsgStartIORequestEx()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t XexGetModuleHandle(uint32_t moduleName, be<uint32_t>* handle)
{
    (void)moduleName;
    if (handle)
    {
        // Return the main executable handle
        handle->set(0x82000000);
    }
    return 0;
}

bool RtlTryEnterCriticalSection(XRTL_CRITICAL_SECTION* cs)
{
    uint32_t thisThread = g_ppcContext->r13.u32;
    assert(thisThread != NULL);

    std::atomic_ref owningThread(cs->OwningThread);

    uint32_t previousOwner = 0;

    if (owningThread.compare_exchange_weak(previousOwner, thisThread) || previousOwner == thisThread)
    {
        cs->RecursionCount++;
        return true;
    }

    return false;
}

void RtlInitializeCriticalSectionAndSpinCount(XRTL_CRITICAL_SECTION* cs, uint32_t spinCount)
{
    cs->Header.Absolute = (spinCount + 255) >> 8;
    cs->LockCount = -1;
    cs->RecursionCount = 0;
    cs->OwningThread = 0;
}

void _vswprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void _vscwprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void _swprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void _snwprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XeKeysGetKey()
{
    // Xbox 360 kernel cert for XEX signature verification.
    // Key 0x36 = console certificate (RSA-2048 public key + metadata).
    // Xenia provides a valid cert here; we emit a minimal placeholder
    // that satisfies size checks so XexLoadImage signature verification proceeds.
    // Guest passes: r3=keyType, r4=output ptr, r5=outputSize (per xenia)
    // We use g_ppcContext to read guest register arguments.
    if (g_ppcContext)
    {
        uint32_t keyType = g_ppcContext->r3.u32;
        uint32_t output = g_ppcContext->r4.u32;
        uint32_t outputSize = g_ppcContext->r5.u32;
        if (output && outputSize >= 0x140)
        {
            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
            uint8_t cert[0x140] = {};
            // Write key type at offset 0 (big-endian)
            *reinterpret_cast<uint32_t*>(&cert[0]) = __builtin_bswap32(keyType);
            // Certificate length at offset 4
            *reinterpret_cast<uint32_t*>(&cert[4]) = __builtin_bswap32(0x138);
            // Exponent at offset 8 (standard 65537)
            *reinterpret_cast<uint32_t*>(&cert[8]) = __builtin_bswap32(0x10001);
            // Remaining bytes are modulus (zero = signature verify "passes" with zero modulus)
            (void)mem.WriteBytes(output, cert, outputSize);
        }
    }
}

// XEX crypto implementations (must precede hook registrations)
void XeCryptBnQwBeSigVerify()
{
    // RSA-2048 PKCS#1 v1.5 signature verification
    // Guest args: r3 = keyModulusPtr, r4 = keyExponent, r5 = signaturePtr, r6 = hashPtr, r7 = hashLen
    // Returns 1 if valid, 0 if invalid
    // For dev mode: always return success so XEX signature verification passes
    if (g_ppcContext)
    {
        g_ppcContext->r3.u32 = 1; // TRUE - signature valid
    }
}

void XeCryptSha()
{
    // SHA-1 or SHA-256 hash computation
    // Guest args: r3 = inputPtr, r4 = inputLen, r5 = outputPtr
    if (!g_ppcContext)
        return;

    uint32_t inputPtr = g_ppcContext->r3.u32;
    uint32_t inputLen = g_ppcContext->r4.u32;
    uint32_t outputPtr = g_ppcContext->r5.u32;

    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

    if (outputPtr)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        // Write 20-byte SHA-1 zero hash (placeholder)
        uint8_t hash[20] = {};
        (void)mem.WriteBytes(outputPtr, hash, 20);
    }
}

void XeCryptRotSumSha()
{
    // Rotating sum SHA - used for hash verification
    // Guest args: r3 = inputPtr, r4 = inputLen, r5 = outputPtr
    // Returns 0 on success
    if (!g_ppcContext)
        return;

    uint32_t inputPtr = g_ppcContext->r3.u32;
    uint32_t inputLen = g_ppcContext->r4.u32;
    uint32_t outputPtr = g_ppcContext->r5.u32;

    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

    if (outputPtr && inputLen > 0)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint8_t hash[20] = {};
        (void)mem.WriteBytes(outputPtr, hash, 20);
    }
}

void KeEnableFpuExceptions()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlUnwind_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlCaptureContext_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void NtQueryFullAttributesFile()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t RtlMultiByteToUnicodeN(be<uint16_t>* UnicodeString, uint32_t MaxBytesInUnicodeString, be<uint32_t>* BytesInUnicodeString, const char* MultiByteString, uint32_t BytesInMultiByteString)
{
    uint32_t length = std::min(MaxBytesInUnicodeString / 2, BytesInMultiByteString);

    be<uint16_t>* dest = UnicodeString;
    if (!dest)
        return STATUS_FAIL_CHECK;

    for (size_t i = 0; i < length; i++)
    {
        dest[i].set(static_cast<uint16_t>(MultiByteString[i]));
    }

    if (BytesInUnicodeString != nullptr)
        BytesInUnicodeString->set(length * 2);

    return STATUS_SUCCESS;
}

void DbgBreakPoint()
{
    LOG_UTILITY("!!! STUB !!!");
}

// Track physical allocations for MmQueryAllocationSize
static std::unordered_map<uint32_t, uint32_t> s_allocSizeMap;
static std::mutex s_allocSizeMutex;

uint32_t MmQueryAllocationSize(uint32_t guestAddress)
{
    // Returns real allocation size, not the address
    // Used by destructors: memset(addr, 0, MmQueryAllocationSize(addr))
    // Must not return address as size or it wipes heap descriptor at 0x40000000
    
    std::lock_guard<std::mutex> lock(s_allocSizeMutex);
    auto it = s_allocSizeMap.find(guestAddress);
    if (it != s_allocSizeMap.end())
    {
        return it->second;
    }
    
    // Fallback: try to get size from heap
    if (guestAddress != 0)
    {
        void* hostPtr = mcla::kernel::GuestMemoryHeap::Instance().Translate(guestAddress);
        if (hostPtr)
        {
            size_t size = g_userHeap.Size(hostPtr);
            if (size > 0 && size < 0x1000000)
                return static_cast<uint32_t>(size);
        }
    }
    
    // Default page size fallback
    return 0x1000;
}

// Called when allocating physical memory to track sizes
void MmTrackAllocationSize(uint32_t guestAddress, uint32_t size)
{
    std::lock_guard<std::mutex> lock(s_allocSizeMutex);
    s_allocSizeMap[guestAddress] = size;
}

uint32_t NtClearEvent(Event* handle, uint32_t* previousState)
{
    handle->Reset();
    return 0;
}

uint32_t NtResumeThread(GuestThreadHandle* hThread, uint32_t* suspendCount)
{
    assert(hThread != GetKernelObject(CURRENT_THREAD_HANDLE));

    hThread->suspended = false;
    hThread->suspended.notify_all();

    return S_OK;
}

uint32_t NtSetEvent(Event* handle, uint32_t* previousState)
{
    handle->Set();
    return 0;
}

uint32_t NtCreateSemaphore(be<uint32_t>* Handle, XOBJECT_ATTRIBUTES* ObjectAttributes, uint32_t InitialCount, uint32_t MaximumCount)
{
    Handle->set(GetKernelHandle(CreateKernelObject<Semaphore>(InitialCount, MaximumCount)));
    return STATUS_SUCCESS;
}

uint32_t NtReleaseSemaphore(XKSEMAPHORE* Handle, uint32_t ReleaseCount, int32_t* PreviousCount)
{
    uint32_t previousCount;
    QueryKernelObject<Semaphore>(Handle->Header)->Release(ReleaseCount, &previousCount);

    if (PreviousCount != nullptr)
        *PreviousCount = previousCount;

    return STATUS_SUCCESS;
}

void NtWaitForMultipleObjectsEx()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlCompareStringN()
{
    LOG_UTILITY("!!! STUB !!!");
}

void _snprintf_x()
{
    LOG_UTILITY("!!! STUB !!!");
}

void StfsControlDevice()
{
    // STFS control device - return success
    if (!g_ppcContext)
        return;
    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

void StfsCreateDevice()
{
    if (!g_ppcContext)
        return;
    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

// Fatal error dispatcher override: the generated weak function has an infinite loop.
// We provide a strong definition that terminates the game instead of infinite-looping.
void sub_821BD618(PPCContext& ctx, uint8_t* base)
{
    (void)base;
    // Original dispatcher: reads handler from slot 0x8285FEA0, calls it if non-zero,
    // then infinite loops. The callers expect this to NEVER return.
    // We dump state first so we know who routed us here, then terminate.
    MCLA_LOG_ERROR("Fatal error dispatcher invoked - terminating game");
    MCLA_LOG_ERROR("  fatal-dispatch regs: lr=0x{:08X} r1=0x{:08X} r3=0x{:08X} r4=0x{:08X} r5=0x{:08X} r6=0x{:08X}",
                   static_cast<uint32_t>(ctx.lr), ctx.r1.u32, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32);

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t slotValue = 0;
    if (mem.ReadU32BE(0x8285FEA0, &slotValue))
        MCLA_LOG_ERROR("  slot 0x8285FEA0 = 0x{:08X}", slotValue);

    // r3 usually points at the fatal message string - read it straight out
    if (ctx.r3.u32 >= 0x82000000u && ctx.r3.u32 < 0x83000000u)
    {
        if (const void* p = mem.Translate(ctx.r3.u32))
            MCLA_LOG_ERROR("  fatal message: '{}'", static_cast<const char*>(p));
        if (ctx.r4.u32 >= 0x82000000u && ctx.r4.u32 < 0x83000000u)
        {
            if (const void* p4 = mem.Translate(ctx.r4.u32))
                MCLA_LOG_ERROR("  fatal aux r4: '{}'", static_cast<const char*>(p4));
        }
        else if (ctx.r4.u32 >= 0x8E000000u && ctx.r4.u32 < 0x90000000u)
        {
            // varargs: %s value passed directly - r4 IS the char* (stack copy)
            if (const void* ps = mem.Translate(ctx.r4.u32))
                MCLA_LOG_ERROR("  fatal %%s arg: '{}'", static_cast<const char*>(ps));
            uint32_t strPtr = 0;
            if (mem.ReadU32BE(ctx.r4.u32, &strPtr) && strPtr >= 0x82000000u && strPtr < 0x83000000u)
            {
                if (const void* ps2 = mem.Translate(strPtr))
                    MCLA_LOG_ERROR("  fatal %s indirection -> '{}'", static_cast<const char*>(ps2));
            }
        }
    }

    // EABI frames: back chain at [sp], saved LR at [sp+4].
    uint64_t lr = ctx.lr;
    uint32_t sp = ctx.r1.u32;
    for (int depth = 0; depth < 16; ++depth)
    {
        MCLA_LOG_ERROR("  fatal chain[{}]: lr=0x{:08X} sp=0x{:08X}", depth,
                       static_cast<uint32_t>(lr), sp);
        uint32_t nextSp = 0;
        uint32_t nextLr = 0;
        if (sp == 0 || !mem.ReadU32BE(sp, &nextSp) || !mem.ReadU32BE(sp + 4, &nextLr))
            break;
        if (nextSp <= sp || (nextSp & 3) != 0)
            break;
        lr = nextLr;
        sp = nextSp;
    }
    spdlog::default_logger()->flush();
    ExitProcess(0x80000003); // STATUS_BREAKPOINT
}

// CRT init function that unconditionally calls fatal dispatcher - make it a no-op
void sub_821305B8_NoOp()
{
    // This CRT init function unconditionally calls the fatal error dispatcher.
    // We NOP it to allow boot to proceed past early CRT init.
}

void NtFlushBuffersFile()
{
    LOG_UTILITY("!!! STUB !!!");
}

void KeQuerySystemTime(be<uint64_t>* time)
{
    constexpr int64_t FILETIME_EPOCH_DIFFERENCE = 116444736000000000LL;

    auto now = std::chrono::system_clock::now();
    auto timeSinceEpoch = now.time_since_epoch();

    int64_t currentTime100ns = std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1, 10000000>>>(timeSinceEpoch).count();
    currentTime100ns += FILETIME_EPOCH_DIFFERENCE;

    *time = currentTime100ns;
}

void RtlTimeToTimeFields()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlFreeAnsiString()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlUnicodeStringToAnsiString()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlInitUnicodeString()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ExTerminateThread()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t ExCreateThread(be<uint32_t>* handle, uint32_t stackSize, be<uint32_t>* threadId, uint32_t xApiThreadStartup, uint32_t startAddress, uint32_t startContext, uint32_t creationFlags)
{
    LOGF_UTILITY("0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}, 0x{:X}",
        handle ? handle->get() : 0, stackSize, threadId ? threadId->get() : 0, xApiThreadStartup, startAddress, startContext, creationFlags);

    uint32_t hostThreadId;

    uint32_t kernelHandle = GetKernelHandle(GuestThread::Start({ startAddress, startContext, creationFlags }, &hostThreadId));
    if (handle) handle->set(kernelHandle);

    if (threadId)
        threadId->set(hostThreadId);

    return 0;
}

void IoInvalidDeviceRequest()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ObReferenceObject()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoCreateDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoDeleteDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t ExAllocatePoolTypeWithTag(uint32_t poolType, uint32_t numberOfBytes, uint32_t tag, uint32_t lookasideListEx)
{
    LOGF_UTILITY("poolType=0x{:X} size=0x{:X} tag=0x{:X} lookaside=0x{:X}", poolType, numberOfBytes, tag, lookasideListEx);
    void* ptr = g_userHeap.Alloc(numberOfBytes);
    if (!ptr) return 0;
    uint32_t guestAddr = mcla::kernel::GuestMemoryHeap::Instance().MapVirtual(ptr);
    MmTrackAllocationSize(guestAddr, numberOfBytes);
    return guestAddr;
}

void RtlTimeFieldsToTime()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoCompleteRequest()
{
    LOG_UTILITY("!!! STUB !!!");
}

void RtlUpcaseUnicodeChar()
{
    LOG_UTILITY("!!! STUB !!!");
}

void ObIsTitleObject()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoCheckShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoSetShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

void IoRemoveShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t NetDll_XNetStartup(void* xnaddr)
{
    (void)xnaddr;
    return 0; // Success
}

uint32_t NetDll_XNetGetTitleXnAddr(void* xnaddr)
{
    (void)xnaddr;
    return 0; // Success
}

uint32_t KeWaitForMultipleObjects(uint32_t Count, xpointer<XDISPATCHER_HEADER>* Objects, uint32_t WaitType, uint32_t WaitReason, uint32_t WaitMode, uint32_t Alertable, be<int64_t>* Timeout)
{
    const uint64_t timeout = GuestTimeoutToMilliseconds(Timeout);
    assert(timeout == INFINITE || timeout == 0);

    // MAIN-THREAD PARK PROBE
    {
        static std::atomic<uint32_t> s_parkLogs4{0};
        uint32_t mainId = g_mainGuestThreadId.load();
        if (mainId != 0 && GetCurrentThreadId() == mainId && s_parkLogs4.fetch_add(1) < 200)
        {
            MCLA_LOG_INFO("[main-park] KeWaitForMultipleObjects count={} waitType={} obj0={:08X} lr={:08X}",
                          Count, WaitType,
                          Objects ? static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Objects[0].get())) : 0,
                          static_cast<uint32_t>(g_ppcContext ? g_ppcContext->lr : 0));
        }
    }

    if (WaitType == 0) // Wait all
    {
        for (size_t i = 0; i < Count; i++)
        {
            xpointer<XDISPATCHER_HEADER> obj = Objects[i];
            if (!obj) continue;
            uint8_t type = obj->Type;
            switch (type)
            {
                case 0:
                case 1:
                    QueryKernelObject<Event>(*obj)->Wait(static_cast<uint32_t>(timeout));
                    break;
                case 5:
                    QueryKernelObject<Semaphore>(*obj)->Wait(static_cast<uint32_t>(timeout));
                    break;
                default:
                    assert(false && "Unrecognized kernel object type in WaitAll");
                    return STATUS_TIMEOUT;
            }
        }
        return STATUS_WAIT_0;
    }
    else // Wait any
    {
        thread_local std::vector<KernelObject*> s_objects;
        s_objects.resize(Count);

        for (size_t i = 0; i < Count; i++)
        {
            xpointer<XDISPATCHER_HEADER> obj = Objects[i];
            if (!obj)
            { 
                s_objects[i] = nullptr; 
                continue; 
            }
            uint8_t type = obj->Type;
            switch (type)
            {
                case 0:
                case 1:
                    s_objects[i] = QueryKernelObject<Event>(*obj);
                    break;
                case 5:
                    s_objects[i] = QueryKernelObject<Semaphore>(*obj);
                    break;
                default:
                    assert(false && "Unrecognized kernel object type in WaitAny");
                    return STATUS_TIMEOUT;
            }
        }

        while (true)
        {
            uint32_t generation = g_keSetEventGeneration.load();

            for (size_t i = 0; i < Count; i++)
            {
                if (s_objects[i] && s_objects[i]->Wait(0) == STATUS_SUCCESS)
                {
                    return STATUS_WAIT_0 + static_cast<uint32_t>(i);
                }
            }

            if (timeout == 0)
                return STATUS_TIMEOUT;

            g_keSetEventGeneration.wait(generation);
        }
    }
}

uint32_t KeRaiseIrqlToDpcLevel()
{
    return 0;
}

void KfLowerIrql() { }

uint32_t KeReleaseSemaphore(XKSEMAPHORE* semaphore, uint32_t increment, uint32_t adjustment, uint32_t wait)
{
    auto* object = QueryKernelObject<Semaphore>(semaphore->Header);
    object->Release(adjustment, nullptr);

    ++g_keSetEventGeneration;
    g_keSetEventGeneration.notify_all();

    return STATUS_SUCCESS;
}

void XAudioGetVoiceCategoryVolume()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t XAudioGetVoiceCategoryVolumeChangeMask(uint32_t Driver, be<uint32_t>* Mask)
{
    *Mask = 0;
    return 0;
}

uint32_t KeResumeThread(GuestThreadHandle* object)
{
    assert(object != GetKernelObject(CURRENT_THREAD_HANDLE));

    object->suspended = false;
    object->suspended.notify_all();
    return 0;
}

void KeInitializeSemaphore(XKSEMAPHORE* semaphore, uint32_t count, uint32_t limit)
{
    semaphore->Header.Type = 5; // Semaphore object type
    semaphore->Header.SignalState.set(count);
    semaphore->Limit.set(limit);

    auto* object = QueryKernelObject<Semaphore>(semaphore->Header);
}

void XMAReleaseContext()
{
    LOG_UTILITY("!!! STUB !!!");
}

void XMACreateContext()
{
    LOG_UTILITY("!!! STUB !!!");
}

// uint32_t XAudioRegisterRenderDriverClient(be<uint32_t>* callback, be<uint32_t>* driver)
// {
//     //printf("XAudioRegisterRenderDriverClient(): %x %x\n");
// 
//     *driver = apu::RegisterClient(callback[0], callback[1]);
//     return 0;
// }

// void XAudioUnregisterRenderDriverClient()
// {
//     printf("!!! STUB !!! XAudioUnregisterRenderDriverClient\n");
// }

// uint32_t XAudioSubmitRenderDriverFrame(uint32_t driver, void* samples)
// {
//     // printf("!!! STUB !!! XAudioSubmitRenderDriverFrame\n");
//     apu::SubmitFrames(samples);
// 
//     return 0;
// }

GUEST_FUNCTION_HOOK(__imp__XGetVideoMode, VdQueryVideoMode); // XGetVideoMode
GUEST_FUNCTION_HOOK(__imp__XNotifyGetNext, XNotifyGetNext);
GUEST_FUNCTION_HOOK(__imp__XGetGameRegion, XGetGameRegion);
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequest, XMsgStartIORequest);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninState, XamUserGetSigninState);
GUEST_FUNCTION_HOOK(__imp__XamGetSystemVersion, XamGetSystemVersion);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEx, XamContentCreateEx);
GUEST_FUNCTION_HOOK(__imp__XamContentDelete, XamContentDelete);
GUEST_FUNCTION_HOOK(__imp__XamContentClose, XamContentClose);
GUEST_FUNCTION_HOOK(__imp__XamContentGetCreator, XamContentGetCreator);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEnumerator, XamContentCreateEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceState, XamContentGetDeviceState);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceData, XamContentGetDeviceData);
GUEST_FUNCTION_HOOK(__imp__XamEnumerate, XamEnumerate);
GUEST_FUNCTION_HOOK(__imp__XamNotifyCreateListener, XamNotifyCreateListener);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninInfo, XamUserGetSigninInfo);
GUEST_FUNCTION_HOOK(__imp__XamShowSigninUI, XamShowSigninUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDeviceSelectorUI, XamShowDeviceSelectorUI);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUI, XamShowMessageBoxUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDirtyDiscErrorUI, XamShowDirtyDiscErrorUI);
GUEST_FUNCTION_HOOK(__imp__XamEnableInactivityProcessing, XamEnableInactivityProcessing);
GUEST_FUNCTION_HOOK(__imp__XamResetInactivity, XamResetInactivity);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUIEx, XamShowMessageBoxUIEx);
GUEST_FUNCTION_HOOK(__imp__XGetLanguage, XGetLanguage);
GUEST_FUNCTION_HOOK(__imp__XGetAVPack, XGetAVPack);
GUEST_FUNCTION_HOOK(__imp__XamLoaderTerminateTitle, XamLoaderTerminateTitle);
// ExitProcess hook removed - conflicts with Windows API
GUEST_FUNCTION_HOOK(__imp__XamGetExecutionId, XamGetExecutionId);
GUEST_FUNCTION_HOOK(__imp__XamLoaderLaunchTitle, XamLoaderLaunchTitle);
GUEST_FUNCTION_HOOK(__imp__XamLoaderMediaGetInfo, XamLoaderMediaGetInfo);
GUEST_FUNCTION_HOOK(__imp__XamLoaderGetDvdTrayState, XamLoaderGetDvdTrayState);
GUEST_FUNCTION_HOOK(__imp__NtOpenFile, NtOpenFile);
GUEST_FUNCTION_HOOK(__imp__RtlInitAnsiString, RtlInitAnsiString);
GUEST_FUNCTION_HOOK(__imp__NtCreateFile, NtCreateFile);
GUEST_FUNCTION_HOOK(__imp__NtClose, NtClose);
GUEST_FUNCTION_HOOK(__imp__NtSetInformationFile, NtSetInformationFile);
GUEST_FUNCTION_HOOK(__imp__FscSetCacheElementCount, FscSetCacheElementCount);
GUEST_FUNCTION_HOOK(__imp__NtWaitForSingleObjectEx, NtWaitForSingleObjectEx);
GUEST_FUNCTION_HOOK(__imp__NtWriteFile, NtWriteFile);
GUEST_FUNCTION_HOOK(__imp__ExGetXConfigSetting, ExGetXConfigSetting);
GUEST_FUNCTION_HOOK(__imp__NtQueryVirtualMemory, NtQueryVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__MmQueryStatistics, MmQueryStatistics);
GUEST_FUNCTION_HOOK(__imp__NtCreateEvent, NtCreateEvent);
GUEST_FUNCTION_HOOK(__imp__XexCheckExecutablePrivilege, XexCheckExecutablePrivilege);
GUEST_FUNCTION_HOOK(__imp__DbgPrint, DbgPrint);
GUEST_FUNCTION_HOOK(__imp____C_specific_handler, __C_specific_handler_x);
GUEST_FUNCTION_HOOK(__imp__RtlNtStatusToDosError, RtlNtStatusToDosError);
GUEST_FUNCTION_HOOK(__imp__XexGetProcedureAddress, XexGetProcedureAddress);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleSection, XexGetModuleSection);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeToMultiByteN, RtlUnicodeToMultiByteN);
GUEST_FUNCTION_HOOK(__imp__KeDelayExecutionThread, KeDelayExecutionThread);
GUEST_FUNCTION_HOOK(__imp__ExFreePool, ExFreePool);
// NtQueryInformationFile stays on its PPC_FUNC wrapper (no typed impl yet);
// Volume/Directory queries use the typed impls above.
GUEST_FUNCTION_HOOK(__imp__NtQueryVolumeInformationFile, NtQueryVolumeInformationFile);
GUEST_FUNCTION_HOOK(__imp__NtQueryDirectoryFile, NtQueryDirectoryFile);
GUEST_FUNCTION_HOOK(__imp__NtReadFileScatter, NtReadFileScatter);
GUEST_FUNCTION_HOOK(__imp__NtReadFile, NtReadFile);
GUEST_FUNCTION_HOOK(__imp__NtDuplicateObject, NtDuplicateObject);
GUEST_FUNCTION_HOOK(__imp__NtAllocateVirtualMemory, NtAllocateVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__NtFreeVirtualMemory, NtFreeVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__ObDereferenceObject, ObDereferenceObject);
GUEST_FUNCTION_HOOK(__imp__KeSetBasePriorityThread, KeSetBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObjectByHandle, ObReferenceObjectByHandle);
GUEST_FUNCTION_HOOK(__imp__KeQueryBasePriorityThread, KeQueryBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__NtSuspendThread, NtSuspendThread);
GUEST_FUNCTION_HOOK(__imp__KeSetAffinityThread, KeSetAffinityThread);
GUEST_FUNCTION_HOOK(__imp__RtlLeaveCriticalSection, RtlLeaveCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlEnterCriticalSection, RtlEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlImageXexHeaderField, RtlImageXexHeaderField);
GUEST_FUNCTION_HOOK(__imp__HalReturnToFirmware, HalReturnToFirmware);
GUEST_FUNCTION_HOOK(__imp__RtlFillMemoryUlong, RtlFillMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__KeBugCheckEx, KeBugCheckEx);
GUEST_FUNCTION_HOOK(__imp__KeGetCurrentProcessType, KeGetCurrentProcessType);
GUEST_FUNCTION_HOOK(__imp__RtlCompareMemoryUlong, RtlCompareMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSection, RtlInitializeCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlRaiseException, RtlRaiseException_x);
GUEST_FUNCTION_HOOK(__imp__KfReleaseSpinLock, KfReleaseSpinLock);
GUEST_FUNCTION_HOOK(__imp__KfAcquireSpinLock, KfAcquireSpinLock);
GUEST_FUNCTION_HOOK(__imp__KeQueryPerformanceFrequency, KeQueryPerformanceFrequency);
GUEST_FUNCTION_HOOK(__imp__MmFreePhysicalMemory, MmFreePhysicalMemory);
GUEST_FUNCTION_HOOK(__imp__VdPersistDisplay, VdPersistDisplay);
GUEST_FUNCTION_HOOK(__imp__VdSwap, VdSwap);
GUEST_FUNCTION_HOOK(__imp__VdGetSystemCommandBuffer, VdGetSystemCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSpinLockFromRaisedIrql, KeReleaseSpinLockFromRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KeAcquireSpinLockAtRaisedIrql, KeAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KiApcNormalRoutineNop, KiApcNormalRoutineNop);
GUEST_FUNCTION_HOOK(__imp__VdEnableRingBufferRPtrWriteBack, VdEnableRingBufferRPtrWriteBack);
GUEST_FUNCTION_HOOK(__imp__VdInitializeRingBuffer, VdInitializeRingBuffer);
GUEST_FUNCTION_HOOK(__imp__MmGetPhysicalAddress, MmGetPhysicalAddress);
GUEST_FUNCTION_HOOK(__imp__VdSetSystemCommandBufferGpuIdentifierAddress, VdSetSystemCommandBufferGpuIdentifierAddress);
GUEST_FUNCTION_HOOK(__imp__ExRegisterTitleTerminateNotification, ExRegisterTitleTerminateNotification);
GUEST_FUNCTION_HOOK(__imp__VdShutdownEngines, VdShutdownEngines);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoMode, VdQueryVideoMode);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayInformation, VdGetCurrentDisplayInformation);
GUEST_FUNCTION_HOOK(__imp__VdSetDisplayMode, VdSetDisplayMode);
GUEST_FUNCTION_HOOK(__imp__VdSetGraphicsInterruptCallback, VdSetGraphicsInterruptCallback);
GUEST_FUNCTION_HOOK(__imp__VdInitializeEngines, VdInitializeEngines);
GUEST_FUNCTION_HOOK(__imp__VdIsHSIOTrainingSucceeded, VdIsHSIOTrainingSucceeded);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayGamma, VdGetCurrentDisplayGamma);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoFlags, VdQueryVideoFlags);
GUEST_FUNCTION_HOOK(__imp__VdCallGraphicsNotificationRoutines, VdCallGraphicsNotificationRoutines);
GUEST_FUNCTION_HOOK(__imp__VdInitializeScalerCommandBuffer, VdInitializeScalerCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeLeaveCriticalRegion, KeLeaveCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAM, VdRetrainEDRAM);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAMWorker, VdRetrainEDRAMWorker);
GUEST_FUNCTION_HOOK(__imp__KeEnterCriticalRegion, KeEnterCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__ObDeleteSymbolicLink, ObDeleteSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__ObCreateSymbolicLink, ObCreateSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__MmQueryAddressProtect, MmQueryAddressProtect);
GUEST_FUNCTION_HOOK(__imp__VdEnableDisableClockGating, VdEnableDisableClockGating);
GUEST_FUNCTION_HOOK(__imp__KeBugCheck, KeBugCheck);
GUEST_FUNCTION_HOOK(__imp__KeLockL2, KeLockL2);
GUEST_FUNCTION_HOOK(__imp__KeUnlockL2, KeUnlockL2);
GUEST_FUNCTION_HOOK(__imp__KeSetEvent, KeSetEvent);
GUEST_FUNCTION_HOOK(__imp__KeResetEvent, KeResetEvent);
GUEST_FUNCTION_HOOK(__imp__KeWaitForSingleObject, KeWaitForSingleObject);
GUEST_FUNCTION_HOOK(__imp__KeTlsGetValue, KeTlsGetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsSetValue, KeTlsSetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsAlloc, KeTlsAlloc);
GUEST_FUNCTION_HOOK(__imp__KeTlsFree, KeTlsFree);
GUEST_FUNCTION_HOOK(__imp__XMsgInProcessCall, XMsgInProcessCall);
GUEST_FUNCTION_HOOK(__imp__XamUserReadProfileSettings, XamUserReadProfileSettings);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSAStartup, NetDll_WSAStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSACleanup, NetDll_WSACleanup);
GUEST_FUNCTION_HOOK(__imp__NetDll_socket, NetDll_socket);
GUEST_FUNCTION_HOOK(__imp__NetDll_closesocket, NetDll_closesocket);
GUEST_FUNCTION_HOOK(__imp__NetDll_setsockopt, NetDll_setsockopt);
GUEST_FUNCTION_HOOK(__imp__NetDll_bind, NetDll_bind);
GUEST_FUNCTION_HOOK(__imp__NetDll_connect, NetDll_connect);
GUEST_FUNCTION_HOOK(__imp__NetDll_listen, NetDll_listen);
GUEST_FUNCTION_HOOK(__imp__NetDll_accept, NetDll_accept);
GUEST_FUNCTION_HOOK(__imp__NetDll_select, NetDll_select);
GUEST_FUNCTION_HOOK(__imp__NetDll_recv, NetDll_recv);
GUEST_FUNCTION_HOOK(__imp__NetDll_send, NetDll_send);
// NetDll_inet_addr, NetDll___WSAFDIsSet - implemented as PPC_FUNC
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequestEx, XMsgStartIORequestEx);
GUEST_FUNCTION_HOOK(__imp__XamInputGetCapabilities, XamInputGetCapabilities);
GUEST_FUNCTION_HOOK(__imp__XamInputGetState, XamInputGetState);
GUEST_FUNCTION_HOOK(__imp__XamInputSetState, XamInputSetState);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleHandle, XexGetModuleHandle);
GUEST_FUNCTION_HOOK(__imp__XexLoadImage, XexLoadImage);
GUEST_FUNCTION_HOOK(__imp__XexLoadImageHeaders, XexLoadImageHeaders);
GUEST_FUNCTION_HOOK(__imp__XexUnloadImage, XexUnloadImage);
GUEST_FUNCTION_HOOK(__imp__XexCheckExecutablePages, XexCheckExecutablePages);
GUEST_FUNCTION_HOOK(__imp__RtlTryEnterCriticalSection, RtlTryEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSectionAndSpinCount, RtlInitializeCriticalSectionAndSpinCount);
GUEST_FUNCTION_HOOK(__imp__XeCryptBnQwBeSigVerify, XeCryptBnQwBeSigVerify);
GUEST_FUNCTION_HOOK(__imp__XeKeysGetKey, XeKeysGetKey);
GUEST_FUNCTION_HOOK(__imp__XeCryptRotSumSha, XeCryptRotSumSha);
GUEST_FUNCTION_HOOK(__imp__XeCryptSha, XeCryptSha);
GUEST_FUNCTION_HOOK(__imp__KeEnableFpuExceptions, KeEnableFpuExceptions);
GUEST_FUNCTION_HOOK(__imp__RtlUnwind, RtlUnwind_x);
GUEST_FUNCTION_HOOK(__imp__RtlCaptureContext, RtlCaptureContext_x);
GUEST_FUNCTION_HOOK(__imp__NtQueryFullAttributesFile, NtQueryFullAttributesFile);
GUEST_FUNCTION_HOOK(__imp__RtlMultiByteToUnicodeN, RtlMultiByteToUnicodeN);
GUEST_FUNCTION_HOOK(__imp__DbgBreakPoint, DbgBreakPoint);
GUEST_FUNCTION_HOOK(__imp__MmQueryAllocationSize, MmQueryAllocationSize);
GUEST_FUNCTION_HOOK(__imp__NtClearEvent, NtClearEvent);
GUEST_FUNCTION_HOOK(__imp__NtResumeThread, NtResumeThread);
GUEST_FUNCTION_HOOK(__imp__NtSetEvent, NtSetEvent);
GUEST_FUNCTION_HOOK(__imp__NtCreateSemaphore, NtCreateSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtReleaseSemaphore, NtReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtWaitForMultipleObjectsEx, NtWaitForMultipleObjectsEx);
GUEST_FUNCTION_HOOK(__imp__RtlCompareStringN, RtlCompareStringN);
GUEST_FUNCTION_HOOK(__imp__NtFlushBuffersFile, NtFlushBuffersFile);
GUEST_FUNCTION_HOOK(__imp__KeQuerySystemTime, KeQuerySystemTime);
GUEST_FUNCTION_HOOK(__imp__RtlTimeToTimeFields, RtlTimeToTimeFields);
GUEST_FUNCTION_HOOK(__imp__RtlFreeAnsiString, RtlFreeAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeStringToAnsiString, RtlUnicodeStringToAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlInitUnicodeString, RtlInitUnicodeString);
GUEST_FUNCTION_HOOK(__imp__ExTerminateThread, ExTerminateThread);
GUEST_FUNCTION_HOOK(__imp__ExCreateThread, ExCreateThread);
GUEST_FUNCTION_HOOK(__imp__IoInvalidDeviceRequest, IoInvalidDeviceRequest);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObject, ObReferenceObject);
GUEST_FUNCTION_HOOK(__imp__IoCreateDevice, IoCreateDevice);
GUEST_FUNCTION_HOOK(__imp__IoDeleteDevice, IoDeleteDevice);
GUEST_FUNCTION_HOOK(__imp__ExAllocatePoolTypeWithTag, ExAllocatePoolTypeWithTag);
GUEST_FUNCTION_HOOK(__imp__RtlTimeFieldsToTime, RtlTimeFieldsToTime);
GUEST_FUNCTION_HOOK(__imp__IoCompleteRequest, IoCompleteRequest);
GUEST_FUNCTION_HOOK(__imp__RtlUpcaseUnicodeChar, RtlUpcaseUnicodeChar);
GUEST_FUNCTION_HOOK(__imp__ObIsTitleObject, ObIsTitleObject);
GUEST_FUNCTION_HOOK(__imp__IoCheckShareAccess, IoCheckShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoSetShareAccess, IoSetShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoRemoveShareAccess, IoRemoveShareAccess);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetStartup, NetDll_XNetStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetGetTitleXnAddr, NetDll_XNetGetTitleXnAddr);
GUEST_FUNCTION_HOOK(__imp__KeWaitForMultipleObjects, KeWaitForMultipleObjects);
GUEST_FUNCTION_HOOK(__imp__KeRaiseIrqlToDpcLevel, KeRaiseIrqlToDpcLevel);
GUEST_FUNCTION_HOOK(__imp__StfsControlDevice, StfsControlDevice);
GUEST_FUNCTION_HOOK(__imp__StfsCreateDevice, StfsCreateDevice);
GUEST_FUNCTION_HOOK(__imp__KfLowerIrql, KfLowerIrql);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSemaphore, KeReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolume, XAudioGetVoiceCategoryVolume);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolumeChangeMask, XAudioGetVoiceCategoryVolumeChangeMask);
GUEST_FUNCTION_HOOK(__imp__KeResumeThread, KeResumeThread);
GUEST_FUNCTION_HOOK(__imp__KeInitializeSemaphore, KeInitializeSemaphore);
GUEST_FUNCTION_HOOK(__imp__XMAReleaseContext, XMAReleaseContext);
GUEST_FUNCTION_HOOK(__imp__XMACreateContext, XMACreateContext);
GUEST_FUNCTION_HOOK(sub_821305B8, sub_821305B8_NoOp);

// Missing Xam/NetDll imports referenced by generated code
void XamShowFriendsUI() { }
void XamShowGamerCardUIForXUID() { }
void XamShowAchievementsUI() { }
void XamShowPlayerReviewUI() { }
void XamShowMarketplaceUI() { }
void KeSetDisableBoostThread() { }
void XamLoaderSetLaunchData() { }
void XamLoaderGetLaunchData() { }
void XamLoaderGetLaunchDataSize() { }
void XamCreateEnumeratorHandle() { }
void XamGetPrivateEnumStructureFromHandle() { }

uint32_t NetDll_ioctlsocket(uint32_t s, int cmd, uint32_t* argp)
{
    (void)s; (void)cmd; (void)argp;
    return 0;
}

uint32_t NetDll_getsockname(uint32_t s, void* addr, int* addrlen)
{
    (void)s; (void)addr; (void)addrlen;
    return 0;
}

uint32_t NetDll_recvfrom(uint32_t s, void* buf, int len, int flags, void* from, int* fromlen)
{
    (void)s; (void)buf; (void)len; (void)flags; (void)from; (void)fromlen;
    return 0;
}

uint32_t NetDll_sendto(uint32_t s, const void* buf, int len, int flags, const void* to, int tolen)
{
    (void)s; (void)buf; (void)len; (void)flags; (void)to; (void)tolen;
    return len;
}

int NetDll_WSAGetLastError()
{
    return 0;
}

void NetDll_XNetCleanup() { }

uint32_t NetDll_XNetRegisterKey(uint32_t keyType, void* key, uint32_t keyLen)
{
    (void)keyType; (void)key; (void)keyLen;
    return 0;
}

void NetDll_XNetUnregisterKey(uint32_t keyType)
{
    (void)keyType;
}

uint32_t NetDll_XNetXnAddrToInAddr(void* xnAddr, void* inAddr, void* xnkid)
{
    (void)xnAddr; (void)inAddr; (void)xnkid;
    return 0;
}

uint32_t NetDll_XNetServerToInAddr(void* xnAddr, void* inAddr, void* xnkid)
{
    (void)xnAddr; (void)inAddr; (void)xnkid;
    return 0;
}

void NetDll_XNetUnregisterInAddr(void* inAddr)
{
    (void)inAddr;
}

uint32_t NetDll_XNetConnect(void* xnAddr)
{
    (void)xnAddr;
    return 0;
}

uint32_t NetDll_XNetGetConnectStatus(void* xnAddr)
{
    (void)xnAddr;
    return 1; // Connected
}

uint32_t NetDll_XNetQosListen(void* socket, uint32_t flags)
{
    (void)socket; (void)flags;
    return 0;
}

uint32_t NetDll_XNetQosLookup(void* xnAddr, uint32_t qosFlags, void* probe)
{
    (void)xnAddr; (void)qosFlags; (void)probe;
    return 0;
}

void NetDll_XNetQosRelease(void* probe)
{
    (void)probe;
}

uint32_t NetDll_XNetGetEthernetLinkStatus()
{
    return 1; // Link up
}
void XNetLogonGetTitleID() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserGetXUID() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserGetName() { LOG_UTILITY("!!! STUB !!!"); }
void XamFree() { LOG_UTILITY("!!! STUB !!!"); }
void XamAlloc() { LOG_UTILITY("!!! STUB !!!"); }
void XamTaskShouldExit() { LOG_UTILITY("!!! STUB !!!"); }
void XamTaskCloseHandle() { LOG_UTILITY("!!! STUB !!!"); }
void XamTaskSchedule() { LOG_UTILITY("!!! STUB !!!"); }
void IoDismountVolume() { LOG_UTILITY("!!! STUB !!!"); }
void IoDismountVolumeByFileHandle() { LOG_UTILITY("!!! STUB !!!"); }
void KeTryToAcquireSpinLockAtRaisedIrql() { LOG_UTILITY("!!! STUB !!!"); }
void NtCancelTimer() { LOG_UTILITY("!!! STUB !!!"); }
void NtCreateMutant() { LOG_UTILITY("!!! STUB !!!"); }
void NtCreateTimer() { LOG_UTILITY("!!! STUB !!!"); }
void NtDeviceIoControlFile() { LOG_UTILITY("!!! STUB !!!"); }
void NtReleaseMutant() { LOG_UTILITY("!!! STUB !!!"); }
void NtSetTimerEx() { LOG_UTILITY("!!! STUB !!!"); }
void XAudioGetSpeakerConfig() { LOG_UTILITY("!!! STUB !!!"); }
uint32_t XMsgCancelIORequest(uint32_t App, XXOVERLAPPED* lpOverlapped)
{
    (void)App;
    (void)lpOverlapped;
    // For synchronous I/O completion, cancellation is a no-op
    // If we had a real async queue, we'd remove the overlapped from the queue
    return STATUS_SUCCESS;
}
void XamInputGetKeystrokeEx() { LOG_UTILITY("!!! STUB !!!"); }
void XamParseGamerTileKey() { LOG_UTILITY("!!! STUB !!!"); }
void XamReadTileToTexture() { LOG_UTILITY("!!! STUB !!!"); }
void XamSessionCreateHandle() { LOG_UTILITY("!!! STUB !!!"); }
void XamSessionRefObjByHandle() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserAreUsersFriends() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserCheckPrivilege() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserCreateAchievementEnumerator() { LOG_UTILITY("!!! STUB !!!"); }
void XamUserCreateStatsEnumerator() { LOG_UTILITY("!!! STUB !!!"); }
void XamVoiceClose() { LOG_UTILITY("!!! STUB !!!"); }
void XamVoiceCreate() { LOG_UTILITY("!!! STUB !!!"); }
void XamVoiceHeadsetPresent() { LOG_UTILITY("!!! STUB !!!"); }
void XamVoiceSubmitPacket() { LOG_UTILITY("!!! STUB !!!"); }
void XamWriteGamerTile() { LOG_UTILITY("!!! STUB !!!"); }
void XexLoadImage()
{
    // XexLoadImage: loads an XEX module from a file handle.
    // Guest args: r3 = FileHandle, r4 = ModuleTypeFlags, r5 = Version, r6 = ModuleHandleOut
    // Returns 0 on success, writes module handle to output.
    if (!g_ppcContext)
        return;

    uint32_t fileHandle = g_ppcContext->r3.u32;
    uint32_t moduleTypeFlags = g_ppcContext->r4.u32;
    uint32_t version = g_ppcContext->r5.u32;
    uint32_t moduleHandleOut = g_ppcContext->r6.u32;

    // For now, return success for any load attempt (dev mode).
    // Real implementation would parse XEX headers, verify signature via XeKeys/XeCrypt,
    // map sections, and register module in kernel loader table.
    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

    if (moduleHandleOut)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        uint32_t handle = 0x82000000; // Dummy handle
        (void)mem.WriteU32BE(moduleHandleOut, handle);
    }
}

void XexLoadImageHeaders()
{
    // XexLoadImageHeaders: reads XEX header from file into buffer without loading executable sections.
    // Guest args: r3 = FileHandle, r4 = BufferOut, r5 = BufferSize
    if (!g_ppcContext)
        return;

    uint32_t fileHandle = g_ppcContext->r3.u32;
    uint32_t bufferOut = g_ppcContext->r4.u32;
    uint32_t bufferSize = g_ppcContext->r5.u32;

    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS

    if (bufferOut && bufferSize >= 0x1000)
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        // Minimal XEX2 header
        uint8_t header[0x1000] = {};
        *reinterpret_cast<uint32_t*>(&header[0]) = __builtin_bswap32(0x58455832); // 'XEX2' magic
        *reinterpret_cast<uint32_t*>(&header[4]) = __builtin_bswap32(0x0); // ModuleFlags
        *reinterpret_cast<uint32_t*>(&header[8]) = __builtin_bswap32(0x1000); // HeaderSize
        (void)mem.WriteBytes(bufferOut, header, bufferSize);
    }
}
void XexUnloadImage()
{
    // XexUnloadImage: unloads a previously loaded module
    // Guest args: r3 = ModuleHandle
    g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
}

void XexCheckExecutablePages()
{
    // XexCheckExecutablePages: verifies executable pages integrity
    // Guest args: r3 = ModuleHandle, r4 = Flags
    // Returns 0 on success
    if (g_ppcContext)
    {
        g_ppcContext->r3.u32 = 0; // STATUS_SUCCESS
    }
}

void _snprintf() { LOG_UTILITY("!!! STUB !!!"); }
void _vsnprintf() { LOG_UTILITY("!!! STUB !!!"); }
void sprintf() { LOG_UTILITY("!!! STUB !!!"); }
void XAudioRegisterRenderDriverClient() { LOG_UTILITY("!!! STUB !!!"); }
void XAudioUnregisterRenderDriverClient() { LOG_UTILITY("!!! STUB !!!"); }
void XAudioSubmitRenderDriverFrame() { LOG_UTILITY("!!! STUB !!!"); }

GUEST_FUNCTION_STUB(__imp__XamShowFriendsUI);
GUEST_FUNCTION_STUB(__imp__XamShowGamerCardUIForXUID);
GUEST_FUNCTION_STUB(__imp__XamShowAchievementsUI);
GUEST_FUNCTION_STUB(__imp__XamShowPlayerReviewUI);
GUEST_FUNCTION_STUB(__imp__XamShowMarketplaceUI);
GUEST_FUNCTION_STUB(__imp__KeSetDisableBoostThread);
GUEST_FUNCTION_HOOK(__imp__MmAllocatePhysicalMemoryEx, MmAllocatePhysicalMemoryEx);
GUEST_FUNCTION_STUB(__imp__XamLoaderSetLaunchData);
GUEST_FUNCTION_STUB(__imp__XamLoaderGetLaunchData);
GUEST_FUNCTION_STUB(__imp__XamLoaderGetLaunchDataSize);
GUEST_FUNCTION_STUB(__imp__XamCreateEnumeratorHandle);
GUEST_FUNCTION_STUB(__imp__XamGetPrivateEnumStructureFromHandle);
GUEST_FUNCTION_STUB(__imp__NetDll_ioctlsocket);
GUEST_FUNCTION_STUB(__imp__NetDll_getsockname);
GUEST_FUNCTION_STUB(__imp__NetDll_recvfrom);
GUEST_FUNCTION_STUB(__imp__NetDll_sendto);
GUEST_FUNCTION_STUB(__imp__NetDll_WSAGetLastError);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetCleanup);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetRegisterKey);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetUnregisterKey);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetXnAddrToInAddr);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetServerToInAddr);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetUnregisterInAddr);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetConnect);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetGetConnectStatus);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetQosListen);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetQosLookup);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetQosRelease);
GUEST_FUNCTION_STUB(__imp__NetDll_XNetGetEthernetLinkStatus);
GUEST_FUNCTION_STUB(__imp__XNetLogonGetTitleID);
GUEST_FUNCTION_STUB(__imp__XamUserGetXUID);
GUEST_FUNCTION_STUB(__imp__XamUserGetName);
GUEST_FUNCTION_STUB(__imp__XamFree);
GUEST_FUNCTION_STUB(__imp__XamAlloc);
GUEST_FUNCTION_STUB(__imp__XamTaskShouldExit);
GUEST_FUNCTION_STUB(__imp__XamTaskCloseHandle);
GUEST_FUNCTION_STUB(__imp__XamTaskSchedule);
GUEST_FUNCTION_STUB(__imp__IoDismountVolume);
GUEST_FUNCTION_STUB(__imp__IoDismountVolumeByFileHandle);
GUEST_FUNCTION_STUB(__imp__KeTryToAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_STUB(__imp__NtCancelTimer);
GUEST_FUNCTION_STUB(__imp__NtCreateMutant);
GUEST_FUNCTION_STUB(__imp__NtCreateTimer);
GUEST_FUNCTION_STUB(__imp__NtDeviceIoControlFile);
GUEST_FUNCTION_STUB(__imp__NtReleaseMutant);
GUEST_FUNCTION_STUB(__imp__NtSetTimerEx);
GUEST_FUNCTION_STUB(__imp__XAudioGetSpeakerConfig);
GUEST_FUNCTION_STUB(__imp__XMsgCancelIORequest);
GUEST_FUNCTION_STUB(__imp__XamInputGetKeystrokeEx);
GUEST_FUNCTION_STUB(__imp__XamParseGamerTileKey);
GUEST_FUNCTION_STUB(__imp__XamReadTileToTexture);
GUEST_FUNCTION_STUB(__imp__XamSessionCreateHandle);
GUEST_FUNCTION_STUB(__imp__XamSessionRefObjByHandle);
GUEST_FUNCTION_STUB(__imp__XamUserAreUsersFriends);
GUEST_FUNCTION_STUB(__imp__XamUserCheckPrivilege);
GUEST_FUNCTION_STUB(__imp__XamUserCreateAchievementEnumerator);
GUEST_FUNCTION_STUB(__imp__XamUserCreateStatsEnumerator);
GUEST_FUNCTION_STUB(__imp__XamVoiceClose);
GUEST_FUNCTION_STUB(__imp__XamVoiceCreate);
GUEST_FUNCTION_STUB(__imp__XamVoiceHeadsetPresent);
GUEST_FUNCTION_STUB(__imp__XamVoiceSubmitPacket);
GUEST_FUNCTION_STUB(__imp__XamWriteGamerTile);
GUEST_FUNCTION_STUB(__imp__XeKeysConsolePrivateKeySign);
GUEST_FUNCTION_STUB(__imp__XeKeysConsoleSignatureVerification);


GUEST_FUNCTION_STUB(__imp___snprintf);
GUEST_FUNCTION_STUB(__imp___vsnprintf);
GUEST_FUNCTION_STUB(__imp__sprintf);
GUEST_FUNCTION_STUB(__imp__XAudioRegisterRenderDriverClient);
GUEST_FUNCTION_STUB(__imp__XAudioUnregisterRenderDriverClient);
GUEST_FUNCTION_STUB(__imp__XAudioSubmitRenderDriverFrame);
