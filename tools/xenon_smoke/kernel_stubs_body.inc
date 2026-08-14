PPC_FUNC(__imp__DbgBreakPoint) { s_StubCalled("__imp__DbgBreakPoint"); }
PPC_FUNC(__imp__DbgPrint) { s_StubCalled("__imp__DbgPrint"); }
PPC_FUNC(__imp__ExAllocatePoolTypeWithTag) { s_StubCalled("__imp__ExAllocatePoolTypeWithTag"); }
PPC_FUNC(__imp__ExCreateThread) { s_StubCalled("__imp__ExCreateThread"); }
PPC_FUNC(__imp__ExFreePool) { s_StubCalled("__imp__ExFreePool"); }
PPC_FUNC(__imp__ExGetXConfigSetting)
{
    const uint16_t category = (uint16_t)ctx.r3.u32;
    const uint16_t setting = (uint16_t)ctx.r4.u32;
    const uint32_t buffer = ctx.r5.u32;
    const uint16_t sizeOfBuffer = (uint16_t)ctx.r6.u32;
    const uint32_t requiredSize = ctx.r7.u32;

    uint32_t data[4]{};
    uint32_t code = 1; // failure unless matched

    switch (category)
    {
        // XCONFIG_SECURED_CATEGORY
        case 0x0002:
        {
            switch (setting)
            {
                // XCONFIG_SECURED_AV_REGION (USA/Canada)
                case 0x0002:
                    data[0] = 0x00001000;
                    code = 0;
                    break;
                default:
                    break;
            }
            break;
        }

        // XCONFIG_USER_CATEGORY
        case 0x0003:
        {
            switch (setting)
            {
                case 0x0001: // XCONFIG_USER_TIME_ZONE_BIAS
                case 0x0002: // XCONFIG_USER_TIME_ZONE_STD_NAME
                case 0x0003: // XCONFIG_USER_TIME_ZONE_DLT_NAME
                case 0x0004: // XCONFIG_USER_TIME_ZONE_STD_DATE
                case 0x0005: // XCONFIG_USER_TIME_ZONE_DLT_DATE
                case 0x0006: // XCONFIG_USER_TIME_ZONE_STD_BIAS
                case 0x0007: // XCONFIG_USER_TIME_ZONE_DLT_BIAS
                    data[0] = 0;
                    code = 0;
                    break;

                case 0x0009: // XCONFIG_USER_LANGUAGE (English)
                    data[0] = 1;
                    code = 0;
                    break;

                case 0x000A: // XCONFIG_USER_VIDEO_FLAGS
                    data[0] = 0x00040000;
                    code = 0;
                    break;

                case 0x000C: // XCONFIG_USER_RETAIL_FLAGS
                    data[0] = 1;
                    code = 0;
                    break;

                case 0x000E: // XCONFIG_USER_COUNTRY (USD)
                    data[0] = 103;
                    code = 0;
                    break;

                default:
                    break;
            }
            break;
        }

        default:
            break;
    }

    if (code == 0)
    {
        if (requiredSize != 0)
            SmokeStoreU32(requiredSize, 4);
        if (buffer != 0)
            memcpy(g_base + buffer, data, std::min((size_t)sizeOfBuffer, sizeof(data)));
    }

    ctx.r3.u32 = code;
}
PPC_FUNC(__imp__ExRegisterTitleTerminateNotification) { s_StubCalled("__imp__ExRegisterTitleTerminateNotification"); }
PPC_FUNC(__imp__ExTerminateThread) { s_StubCalled("__imp__ExTerminateThread"); }
PPC_FUNC(__imp__HalReturnToFirmware) { s_StubCalled("__imp__HalReturnToFirmware"); }
PPC_FUNC(__imp__IoCheckShareAccess) { s_StubCalled("__imp__IoCheckShareAccess"); }
PPC_FUNC(__imp__IoCompleteRequest) { s_StubCalled("__imp__IoCompleteRequest"); }
PPC_FUNC(__imp__IoCreateDevice) { s_StubCalled("__imp__IoCreateDevice"); }
PPC_FUNC(__imp__IoDeleteDevice) { s_StubCalled("__imp__IoDeleteDevice"); }
PPC_FUNC(__imp__IoDismountVolume) { s_StubCalled("__imp__IoDismountVolume"); }
PPC_FUNC(__imp__IoDismountVolumeByFileHandle) { s_StubCalled("__imp__IoDismountVolumeByFileHandle"); }
PPC_FUNC(__imp__IoInvalidDeviceRequest) { s_StubCalled("__imp__IoInvalidDeviceRequest"); }
PPC_FUNC(__imp__IoRemoveShareAccess) { s_StubCalled("__imp__IoRemoveShareAccess"); }
PPC_FUNC(__imp__IoSetShareAccess) { s_StubCalled("__imp__IoSetShareAccess"); }
PPC_FUNC(__imp__KeAcquireSpinLockAtRaisedIrql) { s_StubCalled("__imp__KeAcquireSpinLockAtRaisedIrql"); }
PPC_FUNC(__imp__KeBugCheck) { s_StubCalled("__imp__KeBugCheck"); }
PPC_FUNC(__imp__KeBugCheckEx) { s_StubCalled("__imp__KeBugCheckEx"); }
PPC_FUNC(__imp__KeDelayExecutionThread) { s_StubCalled("__imp__KeDelayExecutionThread"); }
PPC_FUNC(__imp__KeEnterCriticalRegion) { s_StubCalled("__imp__KeEnterCriticalRegion"); }
PPC_FUNC(__imp__KeGetCurrentProcessType) { s_StubCalled("__imp__KeGetCurrentProcessType"); }
PPC_FUNC(__imp__KeInitializeSemaphore) { s_StubCalled("__imp__KeInitializeSemaphore"); }
PPC_FUNC(__imp__KeLeaveCriticalRegion) { s_StubCalled("__imp__KeLeaveCriticalRegion"); }
PPC_FUNC(__imp__KeLockL2) { s_StubCalled("__imp__KeLockL2"); }
PPC_FUNC(__imp__KeQueryPerformanceFrequency) { s_StubCalled("__imp__KeQueryPerformanceFrequency"); }
PPC_FUNC(__imp__KeQuerySystemTime) { s_StubCalled("__imp__KeQuerySystemTime"); }
PPC_FUNC(__imp__KeRaiseIrqlToDpcLevel) { s_StubCalled("__imp__KeRaiseIrqlToDpcLevel"); }
PPC_FUNC(__imp__KeReleaseSemaphore) { s_StubCalled("__imp__KeReleaseSemaphore"); }
PPC_FUNC(__imp__KeReleaseSpinLockFromRaisedIrql) { s_StubCalled("__imp__KeReleaseSpinLockFromRaisedIrql"); }
PPC_FUNC(__imp__KeResetEvent) { s_StubCalled("__imp__KeResetEvent"); }
PPC_FUNC(__imp__KeResumeThread) { s_StubCalled("__imp__KeResumeThread"); }
PPC_FUNC(__imp__KeSetAffinityThread) { s_StubCalled("__imp__KeSetAffinityThread"); }
PPC_FUNC(__imp__KeSetBasePriorityThread) { s_StubCalled("__imp__KeSetBasePriorityThread"); }
PPC_FUNC(__imp__KeSetDisableBoostThread) { s_StubCalled("__imp__KeSetDisableBoostThread"); }
PPC_FUNC(__imp__KeSetEvent) { s_StubCalled("__imp__KeSetEvent"); }
PPC_FUNC(__imp__KeTlsAlloc) { ctx.r3.u32 = SmokeTlsAlloc(); }
PPC_FUNC(__imp__KeTlsFree) { ctx.r3.u32 = SmokeTlsFree(ctx.r3.u32); }
PPC_FUNC(__imp__KeTlsGetValue) { ctx.r3.u32 = SmokeTlsGetValue(ctx.r3.u32); }
PPC_FUNC(__imp__KeTlsSetValue) { SmokeTlsSetValue(ctx.r3.u32, ctx.r4.u32); ctx.r3.u32 = 1; }
PPC_FUNC(__imp__KeTryToAcquireSpinLockAtRaisedIrql) { s_StubCalled("__imp__KeTryToAcquireSpinLockAtRaisedIrql"); }
PPC_FUNC(__imp__KeUnlockL2) { s_StubCalled("__imp__KeUnlockL2"); }
PPC_FUNC(__imp__KeWaitForMultipleObjects) { s_StubCalled("__imp__KeWaitForMultipleObjects"); }
PPC_FUNC(__imp__KeWaitForSingleObject) { s_StubCalled("__imp__KeWaitForSingleObject"); }
PPC_FUNC(__imp__KfAcquireSpinLock) { s_StubCalled("__imp__KfAcquireSpinLock"); }
PPC_FUNC(__imp__KfLowerIrql) { s_StubCalled("__imp__KfLowerIrql"); }
PPC_FUNC(__imp__KfReleaseSpinLock) { s_StubCalled("__imp__KfReleaseSpinLock"); }
PPC_FUNC(__imp__KiApcNormalRoutineNop) { s_StubCalled("__imp__KiApcNormalRoutineNop"); }
PPC_FUNC(__imp__MmAllocatePhysicalMemoryEx)
{
    const uint32_t size = ctx.r4.u32;
    const uint32_t alignment = ctx.r8.u32;
    ctx.r3.u32 = SmokeAllocPhysical(size, alignment);
}
PPC_FUNC(__imp__MmFreePhysicalMemory) { s_StubCalled("__imp__MmFreePhysicalMemory"); }
PPC_FUNC(__imp__MmGetPhysicalAddress) { s_StubCalled("__imp__MmGetPhysicalAddress"); }
PPC_FUNC(__imp__MmQueryAddressProtect) { s_StubCalled("__imp__MmQueryAddressProtect"); }
PPC_FUNC(__imp__MmQueryAllocationSize) { s_StubCalled("__imp__MmQueryAllocationSize"); }
PPC_FUNC(__imp__NetDll___WSAFDIsSet) { s_StubCalled("__imp__NetDll___WSAFDIsSet"); }
PPC_FUNC(__imp__NetDll_accept) { s_StubCalled("__imp__NetDll_accept"); }
PPC_FUNC(__imp__NetDll_bind) { s_StubCalled("__imp__NetDll_bind"); }
PPC_FUNC(__imp__NetDll_closesocket) { s_StubCalled("__imp__NetDll_closesocket"); }
PPC_FUNC(__imp__NetDll_connect) { s_StubCalled("__imp__NetDll_connect"); }
PPC_FUNC(__imp__NetDll_getsockname) { s_StubCalled("__imp__NetDll_getsockname"); }
PPC_FUNC(__imp__NetDll_inet_addr) { s_StubCalled("__imp__NetDll_inet_addr"); }
PPC_FUNC(__imp__NetDll_ioctlsocket) { s_StubCalled("__imp__NetDll_ioctlsocket"); }
PPC_FUNC(__imp__NetDll_listen) { s_StubCalled("__imp__NetDll_listen"); }
PPC_FUNC(__imp__NetDll_recv) { s_StubCalled("__imp__NetDll_recv"); }
PPC_FUNC(__imp__NetDll_recvfrom) { s_StubCalled("__imp__NetDll_recvfrom"); }
PPC_FUNC(__imp__NetDll_select) { s_StubCalled("__imp__NetDll_select"); }
PPC_FUNC(__imp__NetDll_send) { s_StubCalled("__imp__NetDll_send"); }
PPC_FUNC(__imp__NetDll_sendto) { s_StubCalled("__imp__NetDll_sendto"); }
PPC_FUNC(__imp__NetDll_setsockopt) { s_StubCalled("__imp__NetDll_setsockopt"); }
PPC_FUNC(__imp__NetDll_socket) { s_StubCalled("__imp__NetDll_socket"); }
PPC_FUNC(__imp__NetDll_WSACleanup) { s_StubCalled("__imp__NetDll_WSACleanup"); ctx.r3.u32 = 0; }
PPC_FUNC(__imp__NetDll_WSAGetLastError) { s_StubCalled("__imp__NetDll_WSAGetLastError"); }
PPC_FUNC(__imp__NetDll_WSAStartup)
{
    // lpWSAData = r5. The net-init wrapper (sub_8244A300 -> sub_8244A258)
    // reads wVersion as a big-endian U16 at +0 and requires 2.0 (word 0x0002),
    // so write wVersion + wHighVersion only; the game reads nothing beyond it.
    if (ctx.r5.u32 != 0)
        SmokeStoreU32(ctx.r5.u32, 0x00020002);
    ctx.r3.u32 = 0;
    s_StubCalled("__imp__NetDll_WSAStartup");
}
PPC_FUNC(__imp__NetDll_XNetCleanup) { s_StubCalled("__imp__NetDll_XNetCleanup"); }
PPC_FUNC(__imp__NetDll_XNetConnect) { s_StubCalled("__imp__NetDll_XNetConnect"); }
PPC_FUNC(__imp__NetDll_XNetGetConnectStatus) { s_StubCalled("__imp__NetDll_XNetGetConnectStatus"); }
PPC_FUNC(__imp__NetDll_XNetGetEthernetLinkStatus) { s_StubCalled("__imp__NetDll_XNetGetEthernetLinkStatus"); }
PPC_FUNC(__imp__NetDll_XNetGetTitleXnAddr) { s_StubCalled("__imp__NetDll_XNetGetTitleXnAddr"); }
PPC_FUNC(__imp__NetDll_XNetQosListen) { s_StubCalled("__imp__NetDll_XNetQosListen"); }
PPC_FUNC(__imp__NetDll_XNetQosLookup) { s_StubCalled("__imp__NetDll_XNetQosLookup"); }
PPC_FUNC(__imp__NetDll_XNetQosRelease) { s_StubCalled("__imp__NetDll_XNetQosRelease"); }
PPC_FUNC(__imp__NetDll_XNetRegisterKey) { s_StubCalled("__imp__NetDll_XNetRegisterKey"); }
PPC_FUNC(__imp__NetDll_XNetServerToInAddr) { s_StubCalled("__imp__NetDll_XNetServerToInAddr"); }
PPC_FUNC(__imp__NetDll_XNetStartup)
{
    // The tail-jump wrapper (sub_8244A548 -> sub_8244A490) leaves the selector
    // (r3 = 1) in place; sub_821E44A0 treats a non-zero return as fatal and
    // halts via sub_821BD618. Return success explicitly.
    ctx.r3.u32 = 0;
    s_StubCalled("__imp__NetDll_XNetStartup");
}
PPC_FUNC(__imp__NetDll_XNetUnregisterInAddr) { s_StubCalled("__imp__NetDll_XNetUnregisterInAddr"); }
PPC_FUNC(__imp__NetDll_XNetUnregisterKey) { s_StubCalled("__imp__NetDll_XNetUnregisterKey"); }
PPC_FUNC(__imp__NetDll_XNetXnAddrToInAddr) { s_StubCalled("__imp__NetDll_XNetXnAddrToInAddr"); }
PPC_FUNC(__imp__NtAllocateVirtualMemory) { SmokeNtAllocateVirtualMemory(ctx); }
PPC_FUNC(__imp__NtCancelTimer) { s_StubCalled("__imp__NtCancelTimer"); }
PPC_FUNC(__imp__NtClearEvent) { s_StubCalled("__imp__NtClearEvent"); }
PPC_FUNC(__imp__NtCreateEvent) { s_StubCalled("__imp__NtCreateEvent"); }
PPC_FUNC(__imp__NtCreateFile)
{
    // r3 = PHANDLE out, r4 = access, r5 = POBJECT_ATTRIBUTES,
    // r6 = PIO_STATUS_BLOCK, r7 = alloc size, r8 = file attributes,
    // stack: share(0x24), disposition(0x28), options(0x2C).
    s_StubCalled("__imp__NtCreateFile");
    const uint32_t handleOut = ctx.r3.u32;
    const uint32_t objAttr = ctx.r5.u32;
    const uint32_t ioStatus = ctx.r6.u32;
    const uint32_t nameStr = objAttr ? SmokeLoadU32(objAttr + 4) : 0;
    const std::string guestPath = SmokeDecodeUnicodeString(nameStr);
    const std::string hostPath = std::string("build/game_data/") + SmokeMapGuestPath(guestPath);
    std::printf("[smoke] NtCreateFile(\"%s\") lr=0x%08x access=0x%08x -> \"%s\"\n",
                guestPath.c_str(), ctx.lr, ctx.r4.u32, hostPath.c_str());
    if (objAttr != 0)
    {
        std::printf("[smoke]   objattr: root=0x%08x name=0x%08x attrs=0x%08x\n",
                    SmokeLoadU32(objAttr + 0), nameStr, SmokeLoadU32(objAttr + 8));
        if (nameStr != 0)
        {
            const uint16_t len = SmokeLoadU16(nameStr);
            const uint32_t buf = SmokeLoadU32(nameStr + 4);
            std::printf("[smoke]   unicode: len=%u max=%u buf=0x%08x\n", len,
                        SmokeLoadU16(nameStr + 2), buf);
            if (buf != 0)
            {
                std::printf("[smoke]   bytes  :");
                for (int i = 0; i < 48 && i < len + 2; i++)
                    std::printf(" %02x", *(volatile uint8_t*)(g_base + buf + i));
                std::printf("\n");
            }
        }
    }
    // Absolute device/volume opens are satisfied as directory pseudo-handles
    // rooted at the smoke game-data directory so later root-relative file opens
    // resolve against real archives on disk.
    std::string lower = guestPath;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](char c) { return static_cast<char>((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c); });
    if (!lower.empty() && lower.rfind("\\device\\", 0) == 0)
    {
        const uint32_t handle = SmokeHostFileAddDir("build/game_data");
        if (handleOut != 0)
            SmokeStoreU32(handleOut, handle);
        if (ioStatus != 0)
        {
            SmokeStoreU32(ioStatus, 0);
            SmokeStoreU32(ioStatus + 4, 0);
        }
        ctx.r3.u32 = 0; // STATUS_SUCCESS
        return;
    }
    SmokeOpenResult res;
    if (!SmokeOpenMappedPath(guestPath, GENERIC_READ, res))
    {
        if (handleOut != 0)
            SmokeStoreU32(handleOut, 0);
        ctx.r3.u32 = 0xC0000034u; // STATUS_OBJECT_NAME_NOT_FOUND
        return;
    }
    const uint32_t handle = res.isDirectory ? SmokeHostFileAddDir(res.hostPath)
                                            : SmokeHostFileAdd(res.handle, res.endOfFile);
    if (handleOut != 0)
        SmokeStoreU32(handleOut, handle);
    if (ioStatus != 0)
    {
        SmokeStoreU32(ioStatus, 0);
        SmokeStoreU32(ioStatus + 4, 0);
    }
    ctx.r3.u32 = 0; // STATUS_SUCCESS
}
PPC_FUNC(__imp__NtOpenFile)
{
    // r3 = PHANDLE out, r4 = desired access, r5 = POBJECT_ATTRIBUTES,
    // r6 = PIO_STATUS_BLOCK, r7 = share access, r8 = open options.
    s_StubCalled("__imp__NtOpenFile");
    const uint32_t handleOut = ctx.r3.u32;
    const uint32_t objAttr = ctx.r5.u32;
    const uint32_t ioStatus = ctx.r6.u32;
    const std::string guestPath = SmokeDecodeUnicodeString(objAttr ? SmokeLoadU32(objAttr + 4) : 0);
    std::string lower = guestPath;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](char c) { return static_cast<char>((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c); });
    SmokeOpenResult res;
    if (!lower.empty() && lower.rfind("\\device\\", 0) == 0)
    {
        res.hostPath = "build/game_data";
        res.isDirectory = true;
    }
    else if (!SmokeOpenMappedPath(guestPath, GENERIC_READ, res))
    {
        if (handleOut != 0)
            SmokeStoreU32(handleOut, 0);
        ctx.r3.u32 = 0xC0000034u;
        return;
    }
    const uint32_t handle = res.isDirectory ? SmokeHostFileAddDir(res.hostPath)
                                            : SmokeHostFileAdd(res.handle, res.endOfFile);
    if (handleOut != 0)
        SmokeStoreU32(handleOut, handle);
    if (ioStatus != 0)
    {
        SmokeStoreU32(ioStatus, 0);
        SmokeStoreU32(ioStatus + 4, 0);
    }
    ctx.r3.u32 = 0; // STATUS_SUCCESS
}
PPC_FUNC(__imp__NtReadFile)
{
    // r3 = FileHandle, r7 = PIO_STATUS_BLOCK, r8 = Buffer, r9 = Length,
    // r10 = PLARGE_INTEGER ByteOffset (0 or -1 => current position).
    s_StubCalled("__imp__NtReadFile");
    const uint32_t handle = ctx.r3.u32;
    const uint32_t ioStatus = ctx.r7.u32;
    const uint32_t buffer = ctx.r8.u32;
    const uint32_t length = ctx.r9.u32;
    HostFileEntry fe{};
    if (!SmokeHostFileGet(handle, fe))
    {
        ctx.r3.u32 = 0xC0000008u; // STATUS_INVALID_HANDLE
        return;
    }
    if (ctx.r10.u32 != 0)
    {
        const int64_t offset = static_cast<int64_t>(SmokeLoadU64(ctx.r10.u32));
        if (offset >= 0)
        {
            LARGE_INTEGER o{};
            o.QuadPart = offset;
            SetFilePointerEx(fe.handle, o, nullptr, FILE_BEGIN);
        }
    }
    DWORD bytesRead = 0;
    if (buffer != 0 && length != 0)
    {
        if (!ReadFile(fe.handle, g_base + buffer, length, &bytesRead, nullptr))
        {
            if (ioStatus != 0)
            {
                SmokeStoreU32(ioStatus, 0);
                SmokeStoreU32(ioStatus + 4, 0);
            }
            ctx.r3.u32 = 0xC0000011u; // STATUS_END_OF_FILE
            return;
        }
    }
    if (ioStatus != 0)
    {
        SmokeStoreU32(ioStatus, 0);
        SmokeStoreU32(ioStatus + 4, bytesRead);
    }
    ctx.r3.u32 = 0; // STATUS_SUCCESS
}
PPC_FUNC(__imp__NtClose) { s_StubCalled("__imp__NtClose"); SmokeHostFileClose(ctx.r3.u32); ctx.r3.u32 = 0; }
PPC_FUNC(__imp__NtQueryFullAttributesFile)
{
    // r3 = POBJECT_ATTRIBUTES, r4 = PFILE_NETWORK_OPEN_INFORMATION (56 bytes).
    s_StubCalled("__imp__NtQueryFullAttributesFile");
    const uint32_t objAttr = ctx.r3.u32;
    const uint32_t info = ctx.r4.u32;
    const std::string guestPath = SmokeDecodeUnicodeString(objAttr ? SmokeLoadU32(objAttr + 4) : 0);
    SmokeOpenResult res;
    if (!SmokeOpenMappedPath(guestPath, GENERIC_READ, res))
    {
        ctx.r3.u32 = 0xC0000034u;
        return;
    }
    if (info != 0)
    {
        const uint64_t eof = res.isDirectory ? 0 : res.endOfFile;
        SmokeStoreU64(info + 32, eof);  // AllocationSize
        SmokeStoreU64(info + 40, eof);  // EndOfFile
        SmokeStoreU32(info + 48, 0x80); // FILE_ATTRIBUTE_NORMAL
    }
    if (res.handle != INVALID_HANDLE_VALUE)
        CloseHandle(res.handle);
    ctx.r3.u32 = 0;
}
PPC_FUNC(__imp__NtQueryInformationFile)
{
    // r3 = FileHandle, r4 = PIO_STATUS_BLOCK, r5 = buffer, r6 = length,
    // r7 = FileInformationClass (5 = FileStandardInformation,
    // 34 = FileNetworkOpenInformation).
    s_StubCalled("__imp__NtQueryInformationFile");
    const uint32_t handle = ctx.r3.u32;
    const uint32_t ioStatus = ctx.r4.u32;
    const uint32_t buffer = ctx.r5.u32;
    const uint32_t cls = ctx.r7.u32;
    HostFileEntry fe{};
    if (!SmokeHostFileGet(handle, fe) || buffer == 0)
    {
        ctx.r3.u32 = 0xC000000Du; // STATUS_INVALID_PARAMETER
        return;
    }
    if (cls == 5)
    {
        // FILE_STANDARD_INFORMATION: AllocationSize(8) EndOfFile(8)
        // NumberOfLinks(4) DeletePending(1) Directory(1).
        SmokeStoreU64(buffer + 0, fe.endOfFile);
        SmokeStoreU64(buffer + 8, fe.endOfFile);
        SmokeStoreU32(buffer + 16, 1);
        SmokeStoreU16(buffer + 20, 0);
    }
    else if (cls == 34)
    {
        // FILE_NETWORK_OPEN_INFORMATION: CreationTime(8) LastAccess(8)
        // LastWrite(8) ChangeTime(8) AllocationSize(8) EndOfFile(8)
        // FileAttributes(4) = 56 bytes. Game reads EndOfFile at +40.
        for (uint32_t off = 0; off < 40; off += 8)
            SmokeStoreU64(buffer + off, 0);
        SmokeStoreU64(buffer + 32, fe.endOfFile);
        SmokeStoreU64(buffer + 40, fe.endOfFile);
        SmokeStoreU32(buffer + 48, 0x80); // FILE_ATTRIBUTE_NORMAL
    }
    else
    {
        ctx.r3.u32 = 0xC000000Du;
        return;
    }
    if (ioStatus != 0)
    {
        SmokeStoreU32(ioStatus, 0);
        SmokeStoreU32(ioStatus + 4, cls == 5 ? 22 : 56);
    }
    ctx.r3.u32 = 0;
}
PPC_FUNC(__imp__RtlInitAnsiString)
{
    // r3 = PANSI_STRING out, r4 = char* source.
    s_StubCalled("__imp__RtlInitAnsiString");
    const uint32_t out = ctx.r3.u32;
    const uint32_t src = ctx.r4.u32;
    if (out == 0)
        return;
    if (src == 0)
    {
        SmokeStoreU32(out, 0);
        SmokeStoreU16(out + 4, 0);
        SmokeStoreU16(out + 6, 0);
        return;
    }
    uint32_t len = 0;
    while (len < 0x10000 && *(volatile uint8_t*)(g_base + src + len) != 0)
        len++;
    // ANSI_STRING: +0 USHORT Length, +2 USHORT MaximumLength, +4 PCHAR Buffer.
    SmokeStoreU16(out, static_cast<uint16_t>(len));
    SmokeStoreU16(out + 2, static_cast<uint16_t>(len));
    SmokeStoreU32(out + 4, src);
}
PPC_FUNC(__imp__NtCreateMutant) { s_StubCalled("__imp__NtCreateMutant"); }
PPC_FUNC(__imp__NtCreateSemaphore) { s_StubCalled("__imp__NtCreateSemaphore"); }
PPC_FUNC(__imp__NtCreateTimer) { s_StubCalled("__imp__NtCreateTimer"); }
PPC_FUNC(__imp__NtDeviceIoControlFile) { s_StubCalled("__imp__NtDeviceIoControlFile"); }
PPC_FUNC(__imp__NtDuplicateObject) { s_StubCalled("__imp__NtDuplicateObject"); }
PPC_FUNC(__imp__NtFlushBuffersFile) { s_StubCalled("__imp__NtFlushBuffersFile"); }
PPC_FUNC(__imp__NtFreeVirtualMemory) { SmokeNtFreeVirtualMemory(ctx); }
PPC_FUNC(__imp__NtQueryDirectoryFile)
{
    // Game convention (sub_8245FFF8): r3=FileHandle, r4-r6=0, r7=IoStatusBlock,
    // r8=FileInformation (FILE_DIRECTORY_INFORMATION), r9=Length, r10=FileName
    // (ANSI/UNICODE string header). Only the named file's entry is requested.
    s_StubCalled("__imp__NtQueryDirectoryFile");
    const uint32_t handle = ctx.r3.u32;
    const uint32_t ioStatus = ctx.r7.u32;
    const uint32_t info = ctx.r8.u32;
    const uint32_t nameStr = ctx.r10.u32;
    const std::string fileName = SmokeDecodeUnicodeString(nameStr);
    std::string hostDir;
    if (!SmokeHostDirGet(handle, hostDir))
    {
        ctx.r3.u32 = 0xC000000Du; // STATUS_INVALID_HANDLE
        return;
    }
    SmokeOpenResult res;
    if (!SmokeOpenMappedPath(fileName, GENERIC_READ, res))
    {
        ctx.r3.u32 = 0xC000000F; // STATUS_NO_SUCH_FILE
        return;
    }
    uint64_t eof = 0;
    FILETIME ftCreate{}, ftAccess{}, ftWrite{};
    if (res.isDirectory)
    {
        ftWrite.dwHighDateTime = 0;
        ftWrite.dwLowDateTime = 0;
    }
    else
    {
        eof = res.endOfFile;
        GetFileTime(res.handle, &ftCreate, &ftAccess, &ftWrite);
    }
    if (res.handle != INVALID_HANDLE_VALUE)
        CloseHandle(res.handle);
    if (info != 0 && nameStr != 0)
    {
        const uint64_t creation = (static_cast<uint64_t>(ftCreate.dwHighDateTime) << 32) | ftCreate.dwLowDateTime;
        const uint64_t lastAccess = (static_cast<uint64_t>(ftAccess.dwHighDateTime) << 32) | ftAccess.dwLowDateTime;
        const uint64_t lastWrite = (static_cast<uint64_t>(ftWrite.dwHighDateTime) << 32) | ftWrite.dwLowDateTime;
        SmokeStoreU32(info + 0, 0);  // NextEntryOffset
        SmokeStoreU32(info + 4, 0);  // FileIndex
        SmokeStoreU64(info + 8, creation);
        SmokeStoreU64(info + 16, lastAccess);
        SmokeStoreU64(info + 24, lastWrite);
        SmokeStoreU64(info + 32, lastWrite);
        SmokeStoreU64(info + 40, eof);        // EndOfFile
        SmokeStoreU64(info + 48, eof);        // AllocationSize
        SmokeStoreU32(info + 56, 0x80);       // FileAttributes
        SmokeStoreU32(info + 60, static_cast<uint32_t>(fileName.size()));
        for (size_t i = 0; i < fileName.size() && i + 64 < 328; i++)
            PPC_STORE_U8(info + 64u + (uint32_t)i, static_cast<uint8_t>(fileName[i]));
    }
    if (ioStatus != 0)
    {
        SmokeStoreU32(ioStatus, 0);
        SmokeStoreU32(ioStatus + 4, static_cast<uint32_t>(fileName.size() + 64));
    }
    ctx.r3.u32 = 0;
}
PPC_FUNC(__imp__NtQueryVirtualMemory) { SmokeNtQueryVirtualMemory(ctx); }
PPC_FUNC(__imp__NtQueryVolumeInformationFile) { s_StubCalled("__imp__NtQueryVolumeInformationFile"); }
PPC_FUNC(__imp__NtReadFileScatter) { s_StubCalled("__imp__NtReadFileScatter"); }
PPC_FUNC(__imp__NtReleaseMutant) { s_StubCalled("__imp__NtReleaseMutant"); }
PPC_FUNC(__imp__NtReleaseSemaphore) { s_StubCalled("__imp__NtReleaseSemaphore"); }
PPC_FUNC(__imp__NtResumeThread) { s_StubCalled("__imp__NtResumeThread"); }
PPC_FUNC(__imp__NtSetEvent) { s_StubCalled("__imp__NtSetEvent"); }
PPC_FUNC(__imp__NtSetInformationFile) { s_StubCalled("__imp__NtSetInformationFile"); }
PPC_FUNC(__imp__NtSetTimerEx) { s_StubCalled("__imp__NtSetTimerEx"); }
PPC_FUNC(__imp__NtWaitForMultipleObjectsEx) { s_StubCalled("__imp__NtWaitForMultipleObjectsEx"); }
PPC_FUNC(__imp__NtWaitForSingleObjectEx) { s_StubCalled("__imp__NtWaitForSingleObjectEx"); }
PPC_FUNC(__imp__NtWriteFile) { s_StubCalled("__imp__NtWriteFile"); }
PPC_FUNC(__imp__ObCreateSymbolicLink) { s_StubCalled("__imp__ObCreateSymbolicLink"); }
PPC_FUNC(__imp__ObDeleteSymbolicLink) { s_StubCalled("__imp__ObDeleteSymbolicLink"); }
PPC_FUNC(__imp__ObDereferenceObject) { s_StubCalled("__imp__ObDereferenceObject"); }
PPC_FUNC(__imp__ObIsTitleObject) { s_StubCalled("__imp__ObIsTitleObject"); }
PPC_FUNC(__imp__ObReferenceObject) { s_StubCalled("__imp__ObReferenceObject"); }
PPC_FUNC(__imp__ObReferenceObjectByHandle) { s_StubCalled("__imp__ObReferenceObjectByHandle"); }
PPC_FUNC(__imp__RtlCompareMemoryUlong) { s_StubCalled("__imp__RtlCompareMemoryUlong"); }
PPC_FUNC(__imp__RtlCompareStringN) { s_StubCalled("__imp__RtlCompareStringN"); }
PPC_FUNC(__imp__RtlEnterCriticalSection) { s_StubCalled("__imp__RtlEnterCriticalSection"); }
PPC_FUNC(__imp__RtlFillMemoryUlong) { s_StubCalled("__imp__RtlFillMemoryUlong"); }
PPC_FUNC(__imp__RtlImageXexHeaderField) { s_StubCalled("__imp__RtlImageXexHeaderField"); }
PPC_FUNC(__imp__RtlInitializeCriticalSection) { s_StubCalled("__imp__RtlInitializeCriticalSection"); }
PPC_FUNC(__imp__RtlLeaveCriticalSection) { s_StubCalled("__imp__RtlLeaveCriticalSection"); }
PPC_FUNC(__imp__RtlMultiByteToUnicodeN) { s_StubCalled("__imp__RtlMultiByteToUnicodeN"); }
PPC_FUNC(__imp__RtlNtStatusToDosError) { s_StubCalled("__imp__RtlNtStatusToDosError"); }
PPC_FUNC(__imp__RtlRaiseException) { s_StubCalled("__imp__RtlRaiseException"); }
PPC_FUNC(__imp__RtlTimeFieldsToTime) { s_StubCalled("__imp__RtlTimeFieldsToTime"); }
PPC_FUNC(__imp__RtlTimeToTimeFields) { s_StubCalled("__imp__RtlTimeToTimeFields"); }
PPC_FUNC(__imp__RtlTryEnterCriticalSection) { s_StubCalled("__imp__RtlTryEnterCriticalSection"); }
PPC_FUNC(__imp__RtlUnicodeToMultiByteN) { s_StubCalled("__imp__RtlUnicodeToMultiByteN"); }
PPC_FUNC(__imp__RtlUnwind) { s_StubCalled("__imp__RtlUnwind"); }
PPC_FUNC(__imp__RtlUpcaseUnicodeChar) { s_StubCalled("__imp__RtlUpcaseUnicodeChar"); }
PPC_FUNC(__imp__sprintf) { s_StubCalled("__imp__sprintf"); }
PPC_FUNC(__imp__StfsControlDevice) { s_StubCalled("__imp__StfsControlDevice"); }
PPC_FUNC(__imp__StfsCreateDevice) { s_StubCalled("__imp__StfsCreateDevice"); }
PPC_FUNC(__imp__VdCallGraphicsNotificationRoutines) { s_StubCalled("__imp__VdCallGraphicsNotificationRoutines"); }
PPC_FUNC(__imp__VdEnableDisableClockGating) { s_StubCalled("__imp__VdEnableDisableClockGating"); }
PPC_FUNC(__imp__VdEnableRingBufferRPtrWriteBack) { s_StubCalled("__imp__VdEnableRingBufferRPtrWriteBack"); }
PPC_FUNC(__imp__VdGetCurrentDisplayGamma) { s_StubCalled("__imp__VdGetCurrentDisplayGamma"); }
PPC_FUNC(__imp__VdGetCurrentDisplayInformation) { s_StubCalled("__imp__VdGetCurrentDisplayInformation"); }
PPC_FUNC(__imp__VdGetSystemCommandBuffer) { s_StubCalled("__imp__VdGetSystemCommandBuffer"); }
PPC_FUNC(__imp__VdInitializeEngines) { s_StubCalled("__imp__VdInitializeEngines"); }
PPC_FUNC(__imp__VdInitializeRingBuffer) { s_StubCalled("__imp__VdInitializeRingBuffer"); }
PPC_FUNC(__imp__VdInitializeScalerCommandBuffer) { s_StubCalled("__imp__VdInitializeScalerCommandBuffer"); }
PPC_FUNC(__imp__VdIsHSIOTrainingSucceeded) { s_StubCalled("__imp__VdIsHSIOTrainingSucceeded"); }
PPC_FUNC(__imp__VdPersistDisplay) { s_StubCalled("__imp__VdPersistDisplay"); }
PPC_FUNC(__imp__VdQueryVideoFlags) { s_StubCalled("__imp__VdQueryVideoFlags"); }
PPC_FUNC(__imp__VdQueryVideoMode) { s_StubCalled("__imp__VdQueryVideoMode"); }
PPC_FUNC(__imp__VdRetrainEDRAM) { s_StubCalled("__imp__VdRetrainEDRAM"); }
PPC_FUNC(__imp__VdRetrainEDRAMWorker) { s_StubCalled("__imp__VdRetrainEDRAMWorker"); }
PPC_FUNC(__imp__VdSetDisplayMode) { s_StubCalled("__imp__VdSetDisplayMode"); }
PPC_FUNC(__imp__VdSetGraphicsInterruptCallback) { s_StubCalled("__imp__VdSetGraphicsInterruptCallback"); }
PPC_FUNC(__imp__VdSetSystemCommandBufferGpuIdentifierAddress) { s_StubCalled("__imp__VdSetSystemCommandBufferGpuIdentifierAddress"); }
PPC_FUNC(__imp__VdShutdownEngines) { s_StubCalled("__imp__VdShutdownEngines"); }
PPC_FUNC(__imp__VdSwap) { s_StubCalled("__imp__VdSwap"); }
PPC_FUNC(__imp__XamAlloc) { s_StubCalled("__imp__XamAlloc"); }
PPC_FUNC(__imp__XamContentClose) { s_StubCalled("__imp__XamContentClose"); }
PPC_FUNC(__imp__XamContentCreateEnumerator) { s_StubCalled("__imp__XamContentCreateEnumerator"); }
PPC_FUNC(__imp__XamContentCreateEx) { s_StubCalled("__imp__XamContentCreateEx"); }
PPC_FUNC(__imp__XamContentGetDeviceData) { s_StubCalled("__imp__XamContentGetDeviceData"); }
PPC_FUNC(__imp__XamContentGetDeviceState) { s_StubCalled("__imp__XamContentGetDeviceState"); }
PPC_FUNC(__imp__XamCreateEnumeratorHandle) { s_StubCalled("__imp__XamCreateEnumeratorHandle"); }
PPC_FUNC(__imp__XamEnumerate) { s_StubCalled("__imp__XamEnumerate"); }
PPC_FUNC(__imp__XamFree) { s_StubCalled("__imp__XamFree"); }
PPC_FUNC(__imp__XamGetExecutionId) { s_StubCalled("__imp__XamGetExecutionId"); }
PPC_FUNC(__imp__XamGetPrivateEnumStructureFromHandle) { s_StubCalled("__imp__XamGetPrivateEnumStructureFromHandle"); }
PPC_FUNC(__imp__XamGetSystemVersion) { s_StubCalled("__imp__XamGetSystemVersion"); }
PPC_FUNC(__imp__XamInputGetCapabilities) { s_StubCalled("__imp__XamInputGetCapabilities"); }
PPC_FUNC(__imp__XamInputGetKeystrokeEx) { s_StubCalled("__imp__XamInputGetKeystrokeEx"); }
PPC_FUNC(__imp__XamInputGetState) { s_StubCalled("__imp__XamInputGetState"); }
PPC_FUNC(__imp__XamInputSetState) { s_StubCalled("__imp__XamInputSetState"); }
PPC_FUNC(__imp__XamLoaderGetLaunchData) { s_StubCalled("__imp__XamLoaderGetLaunchData"); }
PPC_FUNC(__imp__XamLoaderGetLaunchDataSize) { s_StubCalled("__imp__XamLoaderGetLaunchDataSize"); }
PPC_FUNC(__imp__XamLoaderLaunchTitle) { s_StubCalled("__imp__XamLoaderLaunchTitle"); }
PPC_FUNC(__imp__XamLoaderSetLaunchData) { s_StubCalled("__imp__XamLoaderSetLaunchData"); }
PPC_FUNC(__imp__XamLoaderTerminateTitle) { s_StubCalled("__imp__XamLoaderTerminateTitle"); }
PPC_FUNC(__imp__XamNotifyCreateListener) { s_StubCalled("__imp__XamNotifyCreateListener"); }
PPC_FUNC(__imp__XamParseGamerTileKey) { s_StubCalled("__imp__XamParseGamerTileKey"); }
PPC_FUNC(__imp__XamReadTileToTexture) { s_StubCalled("__imp__XamReadTileToTexture"); }
PPC_FUNC(__imp__XamSessionCreateHandle) { s_StubCalled("__imp__XamSessionCreateHandle"); }
PPC_FUNC(__imp__XamSessionRefObjByHandle) { s_StubCalled("__imp__XamSessionRefObjByHandle"); }
PPC_FUNC(__imp__XamShowAchievementsUI) { s_StubCalled("__imp__XamShowAchievementsUI"); }
PPC_FUNC(__imp__XamShowDeviceSelectorUI) { s_StubCalled("__imp__XamShowDeviceSelectorUI"); }
PPC_FUNC(__imp__XamShowDirtyDiscErrorUI) { s_StubCalled("__imp__XamShowDirtyDiscErrorUI"); }
PPC_FUNC(__imp__XamShowFriendsUI) { s_StubCalled("__imp__XamShowFriendsUI"); }
PPC_FUNC(__imp__XamShowGamerCardUIForXUID) { s_StubCalled("__imp__XamShowGamerCardUIForXUID"); }
PPC_FUNC(__imp__XamShowMarketplaceUI) { s_StubCalled("__imp__XamShowMarketplaceUI"); }
PPC_FUNC(__imp__XamShowMessageBoxUIEx) { s_StubCalled("__imp__XamShowMessageBoxUIEx"); }
PPC_FUNC(__imp__XamShowPlayerReviewUI) { s_StubCalled("__imp__XamShowPlayerReviewUI"); }
PPC_FUNC(__imp__XamShowSigninUI) { s_StubCalled("__imp__XamShowSigninUI"); }
PPC_FUNC(__imp__XamTaskCloseHandle) { s_StubCalled("__imp__XamTaskCloseHandle"); }
PPC_FUNC(__imp__XamTaskSchedule) { s_StubCalled("__imp__XamTaskSchedule"); }
PPC_FUNC(__imp__XamTaskShouldExit) { s_StubCalled("__imp__XamTaskShouldExit"); }
PPC_FUNC(__imp__XamUserAreUsersFriends) { s_StubCalled("__imp__XamUserAreUsersFriends"); }
PPC_FUNC(__imp__XamUserCheckPrivilege) { s_StubCalled("__imp__XamUserCheckPrivilege"); }
PPC_FUNC(__imp__XamUserCreateAchievementEnumerator) { s_StubCalled("__imp__XamUserCreateAchievementEnumerator"); }
PPC_FUNC(__imp__XamUserCreateStatsEnumerator) { s_StubCalled("__imp__XamUserCreateStatsEnumerator"); }
PPC_FUNC(__imp__XamUserGetName) { s_StubCalled("__imp__XamUserGetName"); }
PPC_FUNC(__imp__XamUserGetSigninInfo) { s_StubCalled("__imp__XamUserGetSigninInfo"); }
PPC_FUNC(__imp__XamUserGetSigninState) { s_StubCalled("__imp__XamUserGetSigninState"); }
PPC_FUNC(__imp__XamUserGetXUID) { s_StubCalled("__imp__XamUserGetXUID"); }
PPC_FUNC(__imp__XamUserReadProfileSettings) { s_StubCalled("__imp__XamUserReadProfileSettings"); }
PPC_FUNC(__imp__XamVoiceClose) { s_StubCalled("__imp__XamVoiceClose"); }
PPC_FUNC(__imp__XamVoiceCreate) { s_StubCalled("__imp__XamVoiceCreate"); }
PPC_FUNC(__imp__XamVoiceHeadsetPresent) { s_StubCalled("__imp__XamVoiceHeadsetPresent"); }
PPC_FUNC(__imp__XamVoiceSubmitPacket) { s_StubCalled("__imp__XamVoiceSubmitPacket"); }
PPC_FUNC(__imp__XamWriteGamerTile) { s_StubCalled("__imp__XamWriteGamerTile"); }
PPC_FUNC(__imp__XAudioGetSpeakerConfig) { s_StubCalled("__imp__XAudioGetSpeakerConfig"); }
PPC_FUNC(__imp__XAudioGetVoiceCategoryVolume) { s_StubCalled("__imp__XAudioGetVoiceCategoryVolume"); }
PPC_FUNC(__imp__XAudioGetVoiceCategoryVolumeChangeMask) { s_StubCalled("__imp__XAudioGetVoiceCategoryVolumeChangeMask"); }
PPC_FUNC(__imp__XAudioRegisterRenderDriverClient) { s_StubCalled("__imp__XAudioRegisterRenderDriverClient"); }
PPC_FUNC(__imp__XAudioSubmitRenderDriverFrame) { s_StubCalled("__imp__XAudioSubmitRenderDriverFrame"); }
PPC_FUNC(__imp__XAudioUnregisterRenderDriverClient) { s_StubCalled("__imp__XAudioUnregisterRenderDriverClient"); }
PPC_FUNC(__imp__XeCryptSha) { s_StubCalled("__imp__XeCryptSha"); }
PPC_FUNC(__imp__XeKeysConsolePrivateKeySign) { s_StubCalled("__imp__XeKeysConsolePrivateKeySign"); }
PPC_FUNC(__imp__XeKeysConsoleSignatureVerification) { s_StubCalled("__imp__XeKeysConsoleSignatureVerification"); }
PPC_FUNC(__imp__XexCheckExecutablePrivilege) { ctx.r3.u32 = 0; }
PPC_FUNC(__imp__XexGetModuleHandle) { s_StubCalled("__imp__XexGetModuleHandle"); }
PPC_FUNC(__imp__XexGetProcedureAddress) { s_StubCalled("__imp__XexGetProcedureAddress"); }
PPC_FUNC(__imp__XexLoadImage) { s_StubCalled("__imp__XexLoadImage"); }
PPC_FUNC(__imp__XexLoadImageHeaders) { s_StubCalled("__imp__XexLoadImageHeaders"); }
PPC_FUNC(__imp__XexUnloadImage) { s_StubCalled("__imp__XexUnloadImage"); }
PPC_FUNC(__imp__XGetAVPack) { ctx.r3.u32 = 6; }
PPC_FUNC(__imp__XGetGameRegion) { s_StubCalled("__imp__XGetGameRegion"); }
PPC_FUNC(__imp__XGetLanguage) { s_StubCalled("__imp__XGetLanguage"); }
PPC_FUNC(__imp__XGetVideoMode) { s_StubCalled("__imp__XGetVideoMode"); }
PPC_FUNC(__imp__XMACreateContext) { s_StubCalled("__imp__XMACreateContext"); }
PPC_FUNC(__imp__XMAReleaseContext) { s_StubCalled("__imp__XMAReleaseContext"); }
PPC_FUNC(__imp__XMsgCancelIORequest) { s_StubCalled("__imp__XMsgCancelIORequest"); }
PPC_FUNC(__imp__XMsgInProcessCall) { s_StubCalled("__imp__XMsgInProcessCall"); }
PPC_FUNC(__imp__XMsgStartIORequest) { s_StubCalled("__imp__XMsgStartIORequest"); }
PPC_FUNC(__imp__XMsgStartIORequestEx) { s_StubCalled("__imp__XMsgStartIORequestEx"); }
PPC_FUNC(__imp__XNetLogonGetTitleID) { s_StubCalled("__imp__XNetLogonGetTitleID"); }
PPC_FUNC(__imp__XNotifyGetNext) { s_StubCalled("__imp__XNotifyGetNext"); }
PPC_FUNC(__imp___snprintf) { s_StubCalled("__imp___snprintf"); }
PPC_FUNC(__imp___vsnprintf) { s_StubCalled("__imp___vsnprintf"); }
PPC_FUNC(__imp____C_specific_handler) { s_StubCalled("__imp____C_specific_handler"); }
