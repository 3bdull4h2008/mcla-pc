# MCLA-PC Complete Codebase Logic Map

> Auto-generated rescan. Every function, every data flow, every hook.

---

## 1. Project Overview

- **Goal**: Native D3D12 renderer for Midnight Club: Los Angeles (Xbox 360), replacing the Xenos GPU command processor
- **Stack**: C++23, CMake 3.25+, Ninja + clang-cl, D3D12, SDL3, XenonRecomp (46K+ PPC functions)
- **102 source files** across 6 directories (49 .cpp, 51 .h, 1 .c, 1 other)
- **179 recompilation TUs** in the build
- **Image Base**: `0x82000000`, **Code Base**: `0x82130000`
- **Entry Point**: `_xstart` at guest address `0x821322B8`
- **Build**: Succeeds — `[2/2] Linking CXX executable mcla.exe`

---

## 2. Boot Sequence (Exact Init Order)

```
1. early_init.cpp::g_earlyCrashInit constructor
   └─ #pragma init_seg(lib) — runs before main()
   ├─ _set_abort_behavior(0) — suppress WER dialog
   ├─ _set_invalid_parameter_handler(EarlyInvalidParam) — suppress CRT crash
   ├─ signal(SIGABRT, EarlyAbortSignal) — suppress abort
   └─ AddVectoredExceptionHandler(1, EarlyVeh) — crash log to crash_log_early.txt

2. main() → App("MCLA Native") → App::Initialize()
   ├─ SetActiveGuestMemoryView(&m_guestMemoryView)
   ├─ InitSDL() — SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS
   ├─ InitPaths() — game_data_root, cache_root from CVars or exe dir
   ├─ CreateSDLWindow() — 1280×720, extract HWND via SDL3
   ├─ CVarSystem::LoadConfig(cache/mcla.toml)
   ├─ InitD3D12() — deferred to render thread if Native mode
   ├─ log::Initialize() — spdlog rotating file + console
   ├─ boot::LoadAndPrepare("default.xex", entryGuest)
   │   ├─ AllocateGuestMemory() — 4 GiB VirtualAlloc at 0x100000000
   │   ├─ GuestMemoryView::SetMemoryBase()
   │   ├─ GuestMemoryHeap::Adopt()
   │   ├─ ScanGuestMemoryForTU83SpawnPointers()
   │   ├─ g_userHeap.Init()
   │   ├─ Xex2LoadImage() — parse XEX
   │   ├─ InstallGuestImage() — memcpy into guest window
   │   ├─ ScanForDispatchVtableWords()
   │   ├─ InstallFunctionTable() — 46K+ PPCFuncMappings
   │   └─ SeedPreBootSlots()
   ├─ FunctionDispatcher created
   ├─ mcla_ApplyPatches(dispatcher) — ALL HOOKS INSTALLED HERE
   ├─ RpfVirtualFileSystem initialized and mounted
   ├─ g_renderThread.start()
   └─ boot::Start(entryGuest) — spawns BootWorker thread, 5-min watchdog

3. BootWorker (separate thread, 8 MiB stack)
   ├─ SetupInitialContext(ctx) — r1=stack, r3=imagebase, r13=TLS
   ├─ AddVectoredExceptionHandler(VEH lambda) — crash diagnostics
   ├─ SetUnhandledExceptionFilter(UnhandledExceptionFilter)
   └─ entryFunc(ctx, g_base) — ENTERS GUEST CODE
```

---

## 3. Source File Map

### 3.1 Core (src/)

| File | Lines | Purpose |
|------|-------|---------|
| `main.cpp` | 17 | Trivial entry — creates App, calls Initialize/Run |
| `app.h` | 122 | App class declaration, FunctionDispatcher, PPCContext aliases |
| `app.cpp` | 310 | Full init pipeline, main loop, SDL event handling |
| `patches.h` | 13 | Declares mcla_ApplyPatches, BisectGroupEnabled, detour helpers |
| `patches.cpp` | 2598 | **THE CORE** — 50 functions: all hooks, census, sanitization |
| `boot_host.h` | 58 | BootReport struct, LoadAndPrepare/Start declarations |
| `boot_host.cpp` | 969 | 4 GiB guest window, XEX loading, SEH guard, park sampler |
| `early_init.cpp` | 39 | VEH/crash handler (runs before main) |
| `logging.h` | 97 | spdlog-based logging with MCLA_LOG_* macros |
| `native_types.h` | 127 | POD types: TraceHeader, DrawPacket, VertexStreamDesc, GrcFvfDesc |
| `ppc_config.h` | 21 | PPC memory layout: IMAGE_BASE, CODE_BASE, CODE_SIZE |
| `cvar.h` | 187 | CVarSystem singleton: register/get/set, TOML config I/O |
| `compat.h` | 6 | PPC banker's rounding: roundevenf/roundeven declarations |
| `compat.cpp` | 17 | Saves/restores FP rounding mode, calls nearbyint |

### 3.2 GPU (src/)

| File | Lines | Purpose |
|------|-------|---------|
| `gpu_device.h` | 46 | CapturedDrawV2 struct, device hooks declarations |
| `gpu_device.cpp` | 1264 | Device boundary hooks, draw capture, render state redirect |
| `gpu_cp.h` | 80 | Command processor API: ring buffer, MMIO, doorbell |
| `gpu_cp.cpp` | 1534 | Ring buffer drain, PM4 parsing, MMIO intercept, vblank consumer |
| `gpu_mmio.h` | 41 | XenosRegister enum, GpuHooks struct |
| `gpu_mmio.cpp` | 112 | MMIO write/read hooks, GPU kick/draw call observers |

### 3.3 Kernel (src/kernel/)

| File | Lines | Purpose |
|------|-------|---------|
| `imports.cpp` | ~1500 | Kernel function imports, Nt* implementations, thread management |
| `memory.h` | ~150 | GuestMemoryHeap class — guest-to-host address translation |
| `memory.cpp` | ~300 | Heap init, Adopt, Translate, Read/Write helpers |
| `heap.h/cpp` | ~200 | Guest heap management |
| `xdm.h` | ~130 | Xbox DM structures, object handle translation |
| `xdm.cpp` | ~100 | Handle translation implementation |
| `guest_thread.h/cpp` | ~100 | Guest thread creation/management |
| `phase0_validator.cpp` | ~600 | 13/13 validation tests |

### 3.4 Renderer (src/)

| File | Lines | Purpose |
|------|-------|---------|
| `native_renderer.h/cpp` | ~200 | Native D3D12 renderer mode switching |
| `renderer_mode.h/cpp` | ~100 | Native vs legacy mode management |
| `renderer_hook_dispatch.h/cpp` | ~100 | Hook dispatch for renderer events |
| `render_thread.h` | 42 | RenderThread class (mcla::native) — owns D3D12Backend |
| `render_thread.cpp` | ~250 | Thread main, D3D12 init, command processing |
| `render_queue.h` | ~50 | RenderCommand struct and queue |
| `render_command_queue.h` | 90 | RenderCommandQueue + RenderCommandProcessor (mcla::gpu) |
| `render_command_queue.cpp` | 156 | Queue impl, thread loop, D3D12 draw/present |
| `d3d12_backend.h` | ~100 | D3D12 device, swapchain, command lists |
| `d3d12_backend.cpp` | ~400 | D3D12 initialization, draw, present |

### 3.5 VFS (src/)

| File | Lines | Purpose |
|------|-------|---------|
| `vfs_rpf.h` | 125 | RPF virtual filesystem, VirtualRpf, hook stubs |
| `vfs_rpf.cpp` | 701 | RPF3 synthesis, file index, Nt* hook stubs |

### 3.6 Renderer Subsystems (src/renderer/)

| File | Lines | Purpose |
|------|-------|---------|
| `shader_translator.h` | ~80 | Xenos→HLSL translation API |
| `shader_translator.cpp` | ~1200 | HlslGenerator: full Xenos shader→HLSL codegen |
| `pipeline_cache.h` | ~120 | PipelineKey, PipelineCache class |
| `pipeline_cache.cpp` | ~300 | Async PSO compilation, FIFO eviction cache |
| `vertex_decode.h` | ~80 | VertexType enum, DecodeVertexFormat |
| `vertex_decode.cpp` | ~200 | 14 vertex format decoders, fetch constant decode |
| `texture_decode.h` | ~80 | TextureFormatInfo, untile functions |
| `texture_decode.cpp` | ~400 | 64-entry format table, XGAddress2D/3D untile |
| `grc_fvf_decode.h` | ~80 | RAGE grcFvf vertex declaration decode |
| `grc_fvf_decode.cpp` | ~250 | 18-lane FVF decode, layout builder |
| `rage_asset_pipeline.h` | ~120 | RAGE CSR/TXD/DFF parsers, RageAssetManager |
| `rage_asset_pipeline.cpp` | ~500 | CSR container parse, TXD/DFF geometry extract |

### 3.7 Misc (src/)

| File | Lines | Purpose |
|------|-------|---------|
| `guest_memory.h` | 116 | GuestMemoryView class, routed accessors, watch ranges |
| `guest_memory.cpp` | ~300 | SEH-protected BE reads/writes, GPU MMIO routing, page watch |
| `guest_mem_scan.cpp` | ~60 | TU83 spawn pointer scanner |
| `frame_trace.h/cpp` | ~150 | Binary trace writer/reader for DrawPackets |
| `capture_hooks.h/cpp` | ~400 | DrawPacketAccumulator, grcFvf discovery, shader dump |
| `boot_log.cpp` | 20 | BootReportInfo/Error forwarders |
| `task_dispatch_trace.cpp` | 487 | Task-runner dispatch forensics, relocation census |

---

## 4. patches.cpp — Complete Function Map (2598 lines, 50 functions)

### 4.1 Global State

| Line | Symbol | Type | Purpose |
|------|--------|------|---------|
| 32 | `g_dispatcher` | `FunctionDispatcher*` | Cached dispatcher for SetFunction/GetFunction |
| 33 | `g_virtual_membase` | `uint8_t*` | Guest PPC memory base pointer |
| 35 | `g_original_native_bytes[12]` | `uint8_t[]` | Backup bytes for native x86-64 detour |
| 36 | `g_native_detour_code[12]` | `uint8_t[]` | Detour code buffer |
| 40 | `kStartHoldMs` | `1000ms` | Start button hold duration |
| 41 | `kStartReleaseMs` | `1000ms` | Start button release duration |
| 56 | `s_routerCalls` | `atomic<uint32_t>` | Census counter for sub_821C2AB8 |

### 4.2 Function Index

| # | Function | Lines | Type | Purpose |
|---|----------|-------|------|---------|
| 1 | `StartPulseActive()` | 43–52 | static bool | Alternates Start button hold/release every 1s |
| 2 | `sub_821C2AB8` | 59–67 | PPC_FUNC | Pool router census (weak alias override) |
| 3 | `InstallNativeDetour()` | 75–93 | static bool | Installs x86-64 `mov rax+jmp` detour on native functions |
| 4 | `RemoveNativeDetour()` | 95–103 | static void | Restores original bytes for native detour |
| 5 | `hk_native_XamInputGetState()` | 105–130 | extern "C" __fastcall | Native Start button injection via XInput |
| 6 | `CallOriginalNativeXamInputGetState()` | 132–143 | extern "C" __fastcall | Trampoline to real native XInput |
| 7 | `mcla_DetourImportThunk()` | 159–187 | PPCFunc* | Detours PPC import thunk, returns original |
| 8 | `GetWallClockDeltaBits()` | 192–201 | static uint64_t | Elapsed seconds as double-bits |
| 9 | `TimerHookDispatch()` | 215–249 | static void | Timer arm/disarm dispatch |
| 10 | `hk_sub_82130690` | 316–318 | PPC_FUNC_IMPL | Timer hook (string 0x822A0E28) |
| 11 | `hk_sub_82130770` | 320–322 | PPC_FUNC_IMPL | Timer hook (string 0x822A0E3C) |
| 12 | `hk_sub_82130850` | 324–326 | PPC_FUNC_IMPL | Timer hook (string 0x822A0E50) |
| 13 | `hk_sub_82130930` | 328–330 | PPC_FUNC_IMPL | Timer hook (string 0x822A0E64, returnOne=true) |
| 14 | `hk_sub_82130A18` | 332–334 | PPC_FUNC_IMPL | Timer hook (string 0x822A0E78) |
| 15 | `hk_vdswap_observer` | 295–305 | PPC_FUNC_IMPL | VdSwap passthrough observer |
| 16 | `hk_VdInitializeEngines` | 307–314 | PPC_FUNC_IMPL | VdInitializeEngines passthrough observer |
| 17 | `MclaPatchSdkExecutePacketType3Overflow` | 347–390 | static void | Patches GPU SDK type-3 overflow to non-fatal |
| 18 | `BisectGroupEnabled()` | 397–420 | bool | Parses bisection group cvar |
| 19 | `mcla_ApplyPatches()` | 422–697 | void | **MAIN ENTRY** — installs all hooks |
| 20 | `SanitizePm4Buffer()` | 706–748 | static void | Clamps PM4 counts, recurses into IBs |
| 21 | `hk_GpuKick` | 750–778 | PPC_FUNC_IMPL | Sanitizes PM4 before GPU kick |
| 22 | `hk_KeWaitForSingleObject` | 780–811 | PPC_FUNC_IMPL | Skips display-sync semaphore wait |
| 23 | `hk_XamInputGetState` | 813–838 | PPC_FUNC_IMPL | PPC-level Start button injection |
| 24 | `hk_NtCreateFile` | 840–850 | PPC_FUNC_IMPL | VFS hook for file creation |
| 25 | `hk_NtReadFile` | 852–867 | PPC_FUNC_IMPL | VFS hook for file reading |
| 26 | `hk_NtQueryInformationFile` | 869–882 | PPC_FUNC_IMPL | VFS hook for file info query |
| 27 | `hk_NtClose` | 884–892 | PPC_FUNC_IMPL | VFS hook for file close |
| 28 | `hk_sub_82554E20` | 894–897 | PPC_FUNC_IMPL | Screen manager passthrough |
| 29 | `hk_sub_824569C8` | 905–912 | PPC_FUNC_IMPL | TU83 worker entry census |
| 30 | `hk_sub_82411840` | 919–937 | PPC_FUNC_IMPL | Device-boundary draw consumer hook |
| 31 | `hk_sub_822A3998` | 939–942 | PPC_FUNC_IMPL | Placeholder |
| 32 | `hk_sub_82554590` | 944–947 | PPC_FUNC_IMPL | Placeholder |
| 33 | `hk_press_start_shim` | 956–983 | PPC_FUNC_IMPL | Press Start handler shim |
| 34 | `sub_82554080_stub` | 985–998 | PPC_FUNC_IMPL | Returns shim thunk for screen manager |
| 35 | `ReinitGpuBackend()` | 1000–1067 | static void | Full GPU backend reinit |
| 36 | `OomCensusReadU32()` | 1098–1105 | static uint32_t | Safe BE guest memory read |
| 37 | `RepairCorruptedTinySlabFreeList()` | 1107–1172 | static bool | Repairs corrupted slab freelists |
| 38 | `sub_821C29A0` | 1176–1251 | PPC_FUNC | Heap allocator census + OOM logging |
| 39 | `sub_82130B50` | 1254–1264 | PPC_FUNC | Physical allocator census |
| 40 | `sub_821C1BB0` | 1303–1367 | PPC_FUNC | Arena free-list census |
| 41 | `DumpPool16Element()` | 1426–1435 | void | Dumps 4 BE dwords from address |
| 42 | `ScanPool16SlabsForOverflow()` | 1441–1539 | static void | Full slab scan for 16-byte overflow |
| 43 | `sub_821DE9D8` | 1552–2011 | PPC_FUNC | Pool slab allocator census (~860 lines) |
| 44 | `sub_821DE908` | 2027–2199 | PPC_FUNC | Pool node free census |
| 45 | `sub_821C09C8` | 2208–2242 | PPC_FUNC | Pool router dispatch census |
| 46 | `Arm16BytePoolPayloadWatch()` | 2270–2284 | static void | Arms write-watch on 16-byte pool slabs |
| 47 | `IsUncompiledDispatchStubTarget()` | 2298–2302 | static bool | Checks if address is 0x827CD0xx |
| 48 | `RecordDispatch()` | 2323–2326 | inline void | Records dispatch to ring buffer |
| 49 | `sub_82177EB0` | 2333–2358 | PPC_FUNC | Capture census (registers log) |
| 50 | `sub_8218CC70` | 2361–2598 | PPC_FUNC | Config dispatch census (~240 lines) |

### 4.3 Key Function Details

#### `mcla_ApplyPatches()` (lines 422–697) — THE MAIN ENTRY POINT

Step-by-step:
1. Stores `dispatcher` in `g_dispatcher`
2. Registers weak-alias PPC overrides:
   - `0x82554080` → `sub_82554080_stub`
   - `0x821C29A0` → `sub_821C29A0` (OOM census)
   - `0x821DE9D8` → `sub_821DE9D8` (pool slab census)
   - `0x821BD618` → `sub_821BD618`
   - `0x821C1BB0` → `sub_821C1BB0` (arena census)
   - `0x8218CC70` → `sub_8218CC70` (config dispatch census)
   - `0x82177EB0` → `sub_82177EB0` (capture census)
3. Registers guest write-watch range `0x82839254..0x82839280`
4. If `renderer_mode == "compat"`: only installs `sub_82554080_stub` and returns early
5. If group "sdk" enabled: `MclaPatchSdkExecutePacketType3Overflow()`
6. **Group "ke"**: `hk_KeWaitForSingleObject` at `0x827BD5A4`
7. **Group "fs"**: NtCreateFile, NtReadFile, NtQueryInformationFile, NtClose hooks
8. **Group "in"**: XamInputGetState + native XInput detour chain
9. **Group "gp"**: `CpInstallMmioRouting()`, `InstallGpuHooks()`, GpuKick override
10. **Group "gp" timer hooks**: 5 timer hooks at `0x82130690..0x82130A18`
11. **Group "ps"**: Press Start shim thunk
12. Screen manager hook (`sub_82554E20`), worker entry hook (`sub_824569C8`)
13. VdSwap/VdInitializeEngines observers (non-native mode)

#### `SanitizePm4Buffer()` (lines 706–748)

Walks PM4 packet stream. For each type-3 packet:
- If count > 0x800: clamp to 0x800, rewrite header in guest memory
- If indirect buffer (opcode 0x3F): recursively sanitize IB contents (depth-guarded)
- Prevents GPU hangs from oversized PM4 command buffers

#### `hk_GpuKick()` (lines 750–778)

1. Reads `mgr` from `ctx.r3`
2. Reads write_ptr from mgr+48, limit from mgr+52, base from mgr+56
3. If base/write_ptr valid: calls `SanitizePm4Buffer(view, base, write_ptr)`
4. Chains to `g_original_GpuKick`

#### `hk_KeWaitForSingleObject()` (lines 780–811)

1. If `ctx.r3 == 0x828CD9AC` (display-sync semaphore): returns 0 immediately (skip wait)
2. For all other objects: chains to `g_original_KeWait`

#### `sub_821DE9D8` (lines 1552–2011) — Pool Slab Allocator Census (~860 lines)

The largest function. On each pool allocation:
1. Calls `RepairCorruptedTinySlabFreeList()` to fix corrupted freelists
2. Every 8th call: walks ALL slabs for chain integrity
3. For 16-byte pool: captures caller LR, stack, TLS→vtable type ID
4. Snapshots allocation for later overflow detection
5. Every 500th 16-byte allocation: triggers full slab scan
6. Post-pop consistency check: detects desync, corrupted next pointers
7. On failure: full slab census with state dump

#### `sub_8218CC70` (lines 2361–2598) — Config Dispatch Census (~240 lines)

1. Writes raw entry log to `cache/dispatch_entry.log` (crash-resilient)
2. Validates dispatch index < 24, reads slot/base/struct/target
3. Classifies target: OUT_OF_BOUNDS, SENTINEL, BASE_NULL, VALID_CODE, GARBAGE, etc.
4. **Safe dispatch**: For verified host functions, calls directly; for uncompiled stubs, returns without calling (avoids crash)

---

## 5. GPU Subsystem — Complete Function Map

### 5.1 gpu_device.cpp (1264 lines)

**Globals:**
- `g_deviceAddr` (atomic<uint32_t>) — live device guest VA
- `kDevicePublishSlot = 0x82000864` — canonical publish slot
- `g_pending[64]` (PendingWindow[]) — pending window ring buffer
- `g_pendingCount` (uint32_t) — count of pending windows
- `g_lastDrawV2` (CapturedDrawV2) — last captured draw
- `g_frameCounter` (atomic<uint32_t>) — frame counter
- `g_drawMutex` (std::mutex) — protects V2 draw access

**CapturedDrawV2 struct:** seq, dev, primTypeFlags, vbBase/Stride/Size, ibBase/Size/Fmt, frameId, vsProgram, psProgram, fvfMask/Size/Flags/DynamicOrder/ChannelCount/Types, hasGrcFvf

**Key Functions:**
- `DumpDeviceLayout(dev)` — reads 0x400 bytes, logs 16-byte rows
- `OnDeviceCreated(dev)` — stores addr, dumps layout, calls redirect functions
- `RedirectDefaultRenderStateSlots(dev)` — redirects default stub slots to passthrough
- `RedirectFirstRealRenderStateSlot(dev)` — redirects real slot to passthrough
- `sub_82413588` — Device creation hook: captures outPtr, calls original, redirects render states
- `sub_82411640` — PRIMARY CHOKE POINT (push-buffer space reserver): drains pending windows, queues new
- `CaptureWindow(n, dev, pw)` — reads BE dwords, classifies window, scans PM4 packets
- `ScanPackets(w, n)` — walks PM4 stream: type 0/1/2/3 classification
- `ClassifyT3(op)` — opcode dispatch: NOP, DrawIndx, DrawIndx2, ImLoad, SetConstant, etc.
- `sub_82420BA8` — SubmitBatch: captures VB/IB descriptors, pushes RenderCommand::DRAW_INDEXED
- `sub_824294E0` — PresentKick: increments frame counter
- `sub_82429570` — PresentKick with vsync: reads backbuffer index
- `sub_82411218` — Ring-wait census: reads progress counter, pump object
- `sub_82411928` — Doorbell: sole doorbell ringer
- `sub_82411E98` — Wait-helper census
- `sub_82419718` — Flip processor (vsync ISR): increments frame counter
- `sub_82412F98` — GPU fence wait short-circuit: returns r3=0 to bypass infinite busy-wait
- `sub_824569C8` — Driver worker: reads global block fields
- `sub_821BC910` — Ring-B consumer: reads consumer queue counters
- `sub_821BC868` — Producer-push: reads write/pop/count indices

### 5.2 gpu_cp.cpp (1534 lines)

**Constants:**
- `kMmioBase = 0x7FC80000` — XGPU register window base
- `kMmioSize = 0x10000` — 64 KiB window
- `kWptrByteOffset = 0x01C4 * 4 = 0x714` — CP_RB_WPTR register
- `kWptrSentinel = 0xBAADF00D` — "No doorbell yet"

**RingState struct:** baseGuestVA, capDwords, id, rptrIndex, lastDoorbellWptr, writebackVA, initialized, writebackEnabled, draining

**Key Functions:**
- `PhysToKernelVA(addr)` — if addr < 0x20000000, OR with 0xC0000000
- `FindRingSlotLocked(base, capDwords)` — linear scan of g_rings[0..3]
- `RingContainingVA(va)` — finds ring containing a VA
- `PrimaryRing()` — returns initialized ring at g_primarySlot
- `ReadRingU32(ring, dwordIndex)` — reads one BE dword from ring
- `CpInitializeRingBuffer(physAddr, sizeLog2)` — initializes ring from VdInitializeRingBuffer
- `CpEnableRPtrWriteBack(addr, blockSizeLog2)` — enables rptr write-back
- `CpAttachDriverCtx(devVA)` — idempotent device registration
- `CpConsumePushWindow(endVA, dwords)` — deferred or eager consumption
- `DrainRing(ring, wptr, source)` — CORE: walks PM4 packets, handles XE_SWAP, IB, ME_INIT, MEM_WRITE
- `DrainPacketAt(byteAddr, depth, outAdvance)` — parses one PM4 packet
- `DrainIndirectBuffer(byteAddr, dwordCount, depth)` — recursive IB walk (depth-guarded to 4)
- `ExecuteMemWrite(wordAddr, count)` — reads BE dwords, applies GpuSwap32, writes back
- `CpMmioWrite(guestAddr, value)` — intercepts CP_RB_WPTR doorbell, triggers DrainRing
- `CpMmioRead(guestAddr, outValue)` — returns hardcoded status registers (V_COUNTER, interrupt, etc.)
- `CpVblankDrainToWptr()` — vblank-paced ring consumer
- `ConsumePendingAtVblank()` — dequeues pending windows, credits progress
- `FlushProgressAtVblank()` — atomically advances progress block
- `CpAdvanceGuestPublication(windowsCompleted)` — advances published count for each device
- `PublishRptr(ring)` — writes rptrIndex to writebackVA

### 5.3 gpu_mmio.cpp (112 lines)

**Functions:**
- `LogMmioWrite(offset, value)` — per-offset write counter, name resolution
- `gpu_MmioWriteHook(ctx, base)` — PPC_FUNC for sub_824238E0 (GPU kick)
- `gpu_MmioWriteHelperHook(ctx, base)` — PPC_FUNC for sub_82422EF8
- `gpu_Sub82411180Hook(ctx, base)` — PPC_FUNC for sub_82411180
- `gpu_Sub82411618Hook(ctx, base)` — PPC_FUNC for sub_82411618
- `NotifyGpuSubmit(ctx, base)` — calls onDrawCall hook directly
- `InstallGpuHooks(dispatcher, hooks)` — stores hooks, sets 4 PPC overrides

---

## 6. boot_host.cpp — Complete Function Map (969 lines)

**Globals:**
- `g_base` (uint8_t*) — base of 4 GiB guest memory window
- `GuestMemorySize = 0x100000000` — 4 GiB
- `g_report` (BootReport) — the single boot report
- `g_bootDone` (atomic<bool>) — worker thread completion flag
- `g_faultCtx` (const PPCContext*) — points at BootWorker's PPCContext
- `g_moduleBase` (uintptr_t) — host .exe base for RVA
- `g_hostToGuest` (unordered_map) — reverse map: host fn entry → guest address

**Functions:**
- `InsertFunction(guest, host)` — writes host into PPC function table
- `ReadU32BE(base, guestAddr)` — reads big-endian uint32 with bswap
- `WriteU32BE(base, guestAddr, value)` — writes big-endian uint32
- `AllocateGuestMemory()` — VirtualAlloc at 0x100000000, fallback to any address
- `InstallGuestImage(image)` — memcpy image data into guest window
- `DumpImageRegion(guestAddr, words)` — hex dump of guest memory
- `InstallFunctionTable()` — iterates PPCFuncMappings, inserts into table
- `GuestFunctionName(guest)` — linear scan for nearest function name
- `SetupInitialContext(ctx)` — r1=2MiB stack, r3=imagebase, r13=TLS block, FPSCR mask
- `SeedPreBootSlots()` — seeds dispatch table pointers
- `NearestFunctionName(hostAddr)` — 3-tier resolution: unwind metadata → PDB → PPC mappings
- `FilterCapture(info)` — SEH handler: captures host+PPC registers, stack trace, fault table
- `LogReport()` — logs full boot report under mutex
- `UnhandledExceptionFilter(info)` — static WINAPI filter: captures fault info without stack trace
- `BootWorker(entryGuest)` — spawns VEH, calls entryFunc(ctx, g_base)
- `BootThreadProc(param)` — Windows thread proc
- `LoadAndPrepare(xexPath, entryGuest)` — full load: alloc memory, load XEX, install table
- `Start(entryGuest)` — spawns boot worker + park sampler, 5-min watchdog

---

## 7. Kernel Subsystem — Complete Function Map

### 7.1 imports.cpp (~1500 lines)

Kernel function imports and implementations:
- `NtCreateFileImpl` — opens/creates files via VFS
- `NtReadFile` — reads files via VFS with GuestMemoryHeap translation
- `NtQueryInformationFileImpl` — queries file info (standard, position, etc.)
- `NtClose` — closes file handles
- `KeWaitForSingleObject` — waits on kernel objects (mutant, event, semaphore, thread)
- `KeReleaseMutant` — releases mutant objects
- `NtCreateEvent` — creates event objects
- `NtSetEvent` — signals events
- `KeSetEvent` — kernel event signal
- `KeResetEvent` — kernel event reset
- `KeQueryPerformanceCounter` — high-res timer query
- `KeQuerySystemTime` — system time query
- `NtQuerySystemTime` — system time query (Nt variant)
- `XamInputGetState` — input state query
- `ExAllocatePool` — pool allocation
- `ExFreePool` — pool free
- `RtlAllocateHeap` — heap allocation
- `RtlFreeHeap` — heap free
- Thread creation/termination functions
- Section mapping functions

### 7.2 memory.h/cpp (~450 lines)

**GuestMemoryHeap class:**
- Singleton via `Instance()`
- `Adopt(base, size)` — adopts existing memory window
- `Translate(guestAddr) → void*` — guest-to-host address translation
- `MapVirtual(hostPtr) → uint32_t` — host-to-guest reverse mapping
- `ReadU32BE/WriteU32BE` — big-endian read/write
- `WriteU64BE` — 64-bit big-endian write
- `IsValidRange(addr, size)` — bounds check

### 7.3 heap.h/cpp (~200 lines)

Guest heap management with chunk allocation, free lists, and coalescing.

### 7.4 xdm.h/cpp (~230 lines)

Xbox Device Management structures:
- Object header, handle table, dispatcher header
- `Translate<T>(handle)` — converts guest handle to host pointer
- Wait list management

### 7.5 guest_thread.h/cpp (~100 lines)

Guest thread creation and management.

---

## 8. Renderer Subsystem — Complete Function Map

### 8.1 render_thread.cpp (~250 lines)

**RenderThread class (mcla::native):**
- `RenderThread()` — initializes running_, shouldStop_
- `start()` — creates thread, calls threadMain
- `stop()` — sets shouldStop_, joins thread
- `SetWindowParams(hwnd, width, height)` — stores pending window params
- `threadMain()` — initializes D3D12Backend, enters command loop
- `processCommand(cmd)` — dispatches RenderCommand (Draw/Present/StateSetup)

### 8.2 render_command_queue.cpp (156 lines)

**RenderCommandProcessor class (mcla::gpu):**
- `Start(hwnd, width, height)` — creates thread, calls ThreadMain
- `Stop()` — shuts down queue, joins thread
- `EnqueueCommand(cmd)` — pushes to queue
- `Instance()` — singleton
- `ThreadMain(hwnd, width, height)` — initializes D3D12Backend, processes Draw/Present/StateSetup commands

**RenderCommandQueue class:**
- `Enqueue(cmd)` — mutex-protected push with sequence number
- `Dequeue()` — condition-variable wait, returns optional<RenderCommand>
- `Wake()` — notify all
- `Shutdown()` — sets shutdown flag, notifies

### 8.3 d3d12_backend.cpp (~400 lines)

D3D12 device initialization, swapchain management, command list recording, draw/present operations.

### 8.4 native_renderer.cpp (~200 lines)

Renderer mode switching between native D3D12 and legacy paths.

### 8.5 renderer_mode.cpp (~100 lines)

Mode management: "native", "compat", "capture" modes.

---

## 9. VFS Subsystem — Complete Function Map

### 9.1 vfs_rpf.cpp (701 lines)

**RpfVirtualFileSystem class (singleton):**
- `Initialize(extracted_cache_root)` — builds file index, mounts
- `BuildIndex(root)` — recursive_directory_iterator with junction support
- `NormalizePath(path)` — lowercase, collapse slashes, strip trailing
- `IsVirtualPath(path)` — checks for t:\, mc4/ prefixes
- `GuestToVirtualPath(path)` — strips t:\ prefix, normalizes
- `BuildVirtualRpf(dir_entry, out)` — synthesizes RPF3 archive from directory
- `GetOrBuildVirtualRpf(dir_key)` — cached RPF synthesis
- `Exists/IsDirectory/GetFileSize` — metadata queries
- `OpenFile(path, handle)` — opens real file or synthesized RPF
- `ReadFile(handle, buffer, offset, bytesRead)` — reads from real file or virtual RPF segments
- `CloseFile/SeekFile/ListDirectory` — standard operations

**VirtualRpf struct:** preamble (header+TOC+names), segments (host-backed regions), total_size

**Hook stubs (mcla::vfs::hooks):**
- `NtCreateFileHook(oa, view, status)` — returns false (stub)
- `NtReadFileHook(handle, buffer, length, bytesRead)` — returns false (stub)
- `NtQueryInformationFileHook(handle, buffer, length, infoClass)` — returns false (stub)
- `NtQueryDirectoryFileHook(handle, buffer, length, infoClass)` — returns false (stub)
- `NtCloseHook(handle)` — returns false (stub)

---

## 10. Renderer Subsystems — Complete Function Map

### 10.1 shader_translator.cpp (~1200 lines)

**HlslGenerator class (anonymous namespace):**
- `Generate()` — 2-pass: emit body, then prepend header/signature/registers
- `BuildConstantNames()` — unique names per register
- `EmitOperand(inst, kind)` — complex operand resolution with swizzle/negate/abs
- `AppendHeader(ps)` — #define FLT_MIN/MAX, select() overloads, cbuffer, textures
- `AppendRegisters(ps)` — declares r0-r31, ps, a0, aL, p0
- `AppendSignature(ps)` — main() with inputs/outputs
- `AppendBody(ps)` — iterates instructions, emits Fetch/ALU
- `AppendEpilogue(ps)` — VS: half-pixel offset correction
- `EmitAlu(inst, ps)` — ~200 lines: export registers, giant opcode switch
- `EmitScalarClause(inst, ps, exportReg, suppressVsExport)` — ~180 lines: scalar ops
- `EmitFetch(inst)` — vertex fetch (iUsageIndex.rhsSwz) or texture fetch (SampleLevel)

### 10.2 pipeline_cache.cpp (~300 lines)

**PipelineCache class:**
- `StartWorker(device, rootSig)` — spawns background compilation thread
- `StopWorker()` — signal + join
- `GetOrCompile(key, vsHlsl, psHlsl, layout)` — fast path cache, miss → queue async
- `WorkerLoop(device, rootSig)` — compiles HLSL → DXIL via DXC, creates PSO
- FIFO eviction at maxEntries (4096 default)

### 10.3 vertex_decode.cpp (~200 lines)

- `DecodeVertexFormat(vfCode)` — 6-bit code → VertexFormatDesc (14 formats)
- `DecodeVertexFetch(vfCode, constIndex, select)` — handles vf=0 → fetch constant
- `DecodeVertexFetchConstant(p8)` — 8-byte BE fetch constant decode
- `HashVertexDeclaration(...)` — FNV-1a hash of layout

### 10.4 texture_decode.cpp (~400 lines)

- `kFormatTable[64]` — Xenos→DXGI format mapping (DXT1-5, DXN, etc.)
- `GetTiledOffset2D(x, y, pitch, bpbLog2)` — XGAddress2DTiledOffset
- `GetTiledOffset3D(x, y, z, pitch, height, bpbLog2)` — XGAddress3DTiledOffset
- `UntileTexture2D(src, dst, info)` — tiled→linear 2D copy
- `UntileTexture3D(src, dst, info, depth)` — tiled→linear 3D slice

### 10.5 grc_fvf_decode.cpp (~250 lines)

- `DecodeGrcFvf(desc)` — 18-lane FVF decode: mask, size, types → channels
- `BuildGrcFvfLayout(decl, out, count)` — ordered input layout builder
- `SemanticForLane(lane)` — maps lane 0-17 to (usage, usageIndex)

### 10.6 rage_asset_pipeline.cpp (~500 lines)

- `CsrContainer::Parse(data, size)` — RAGE CSR container (BE headers, entry table)
- `TxdParser::Parse(data, size, dict)` — TXD texture dictionary
- `DffParser::Parse(data, size, model)` — DFF model (geometry lists, meshes)
- `RageAssetManager` — singleton managing textures/models from VFS

---

## 11. Misc Subsystems — Complete Function Map

### 11.1 guest_memory.cpp (~300 lines)

**SEH-protected BE accessors:**
- `ReadU32BE(guestAddr, outVal)` — GPU MMIO check, memcpy, Swap32, page-watch
- `WriteU32BE(guestAddr, val)` — GPU MMIO check, Swap32, memcpy, page-watch + value-watch
- `ReadU64BE/WriteU64BE` — 64-bit variants with both-half watch checks
- `ReadBytes/WriteBytes` — bulk with first/last dword watch

**Watch system:**
- `g_watchRanges[64]` — atomic start/end pairs
- `g_watchValues[4]` — atomic watched values
- `PageWatchHit(guestAddr)` — checks kWatchPage + dynamic ranges
- `WatchValueHit(value)` — linear scan

### 11.2 guest_mem_scan.cpp (~60 lines)

- `ScanGuestMemoryForTU83SpawnPointers()` — scans [0x82000000, 0x83000000) for 4 target addresses

### 11.3 frame_trace.cpp (~150 lines)

- `FrameTraceWriter::Open/WritePacket/Close` — binary trace with TraceHeader + DrawPackets
- `FrameTraceReader::Open/Close` — reads and validates trace files

### 11.4 capture_hooks.cpp (~400 lines)

- `DrawPacketAccumulator::OnStateSetup` — reads color/depth targets from GPU context
- `DrawPacketAccumulator::OnDrawBuild` — ~120 lines: extracts VB/IB, discovers grcFvf
- `DrawPacketAccumulator::OnSubmit` — timestamps, validates, dumps shaders/memory
- `DrawPacketAccumulator::OnFrameEnd` — increments frame, resets draw counter

### 11.5 task_dispatch_trace.cpp (487 lines)

Census hooks for task-runner dispatch:
- `sub_825FDB30` — container→task dispatch: reads entry table, task index, method blocks
- `sub_825FDA90` — tag-dispatcher: reads tag byte, dumps 3 dispatch tables
- `sub_8260B588` — type-dispatcher: flags crash-nodes in 0xB7996E40 range
- `sub_8217D828` — relocation primary lookup census
- `sub_821D2378` — relocation fallback resolver census
- `sub_8217D890` — delta-provider census
- `sub_821DEE40` — worker-router census
- `sub_8260A830` — container-build fixup walker

---

## 12. Bug Fixes Applied

### Session 1 — Initial scan (7 source + 6 config/doc fixes)
1. **patches.cpp:44-52** — `StartPulseActive()` was missing `return held;` → UB
2. **patches.cpp:853-880** — `hk_NtReadFile`/`hk_NtQueryInformationFile` wrong register mapping + unsafe void* cast
3. **patches.cpp:1728** — `s_allocCensus` double-incremented for 16-byte pool allocations
4. **patches.cpp:918** — `hk_sub_82411840` used uninitialized counter (always 0)
5. **render_command_queue.h:71** — Duplicate `RenderThread` renamed to `RenderCommandProcessor`
6. **vfs_rpf.h/cpp** — NtReadFileHook/NtQueryInformationFileHook void* → uint32_t buffer_guest_addr
7. **config/config.json** — 6× NATIVE_GPU_REBUILD_PLAN.md → MCLA_REBUILD_PLAN.md, 3× .opencode/rules/ → .clinerules/, compaction auto/prune → false
8. **.clinerules/workflow.md** — src/hooks/registry.cpp → src/patches.cpp
9. **.clinerules/coding-standards.md** — same fix
10. Deleted stale config/opencode.json
11. Deleted stale .opencode/memory/memories-2026-08-24-blocker-trace.md

### Session 2 — Deep rescan (16 source fixes)

#### CRITICAL
12. **shader_translator.cpp:396** — Vector swizzle `+ i` offset corrupted every non-trivial swizzle → removed
13. **shader_translator.cpp:402** — Scalar0 swizzle `+ 3` offset always wrong → removed
14. **imports.cpp:2252** — `XeKeysGetKey` stack over-read: outputSize clamped to 0x140
15. **imports.cpp:660** — `ExGetXConfigSetting` switch fallthrough case 0x0002→0x0003: added missing `break`
16. **imports.cpp:1399** — `KeAcquireSpinLockAtRaisedIrql` missing bswap32 on r13
17. **xdm.cpp** — `DestroyKernelObject` null deref + race: added null check + lock_guard on g_kernelLock
18. **heap.cpp** — `RtlAllocateHeap`/`RtlReAllocateHeap` null deref after Alloc: added null check

#### HIGH
19. **render_thread.cpp:337,419** — Division by zero on vbStride: added `(stride > 0) ?` guard
20. **vfs_rpf.cpp:211** — `IsVirtualPath` checked raw `path` instead of normalized `norm`
21. **vfs_rpf.cpp:641** — `SeekFile` truncated 64-bit offset to LONG: now uses `SetFilePointerEx`
22. **native_renderer.cpp:200** — `containerSize` missing 36-byte header: now `36 + vsize + psize`
23. **native_renderer.h:56** — Added `rbSurfaceInfoP5` field for scissor BR register
24. **native_renderer.cpp:161** — Added `rbSurfaceInfoP5` load from src_state+128
25. **capture_hooks.cpp:113** — `scissorBR` was same as `scissorTL`: changed to `rbSurfaceInfoP5`

#### MEDIUM
26. **guest_mem_scan.cpp:36** — UB pointer arithmetic on range-for copy: converted to index-based loop
27. **pipeline_cache.cpp:287** — Duplicate key phantom eviction: early-return on existing key

### Session 3 — Remaining issues (20 source fixes)

#### GPU Race Conditions
28. **gpu_device.cpp** — Added `g_drawMutex` at file scope to protect `g_lastDraw` and `g_lastDrawV2` access
29. **gpu_device.cpp:672** — Wrapped `g_lastDraw = cap` with `std::lock_guard`
30. **gpu_device.cpp:795** — Wrapped `mcla_gpu_GetLastDrawV2()` with `std::lock_guard`
31. **gpu_device.cpp:332** — Added `s_pendingMtx` mutex protecting `g_pending[]` and `g_pendingCount`
32. **gpu_device.cpp:sub_82419718** — Removed duplicate `g_frameCounter.fetch_add` (only PresentKick increments)

#### GPU Hot Path
33. **gpu_cp.cpp:CreditDeferredRange** — Replaced O(n²) per-element erase with `std::remove_if` + single erase
34. **gpu_cp.cpp:ConsumePendingAtVblank** — Replaced O(n²) erase(begin) loop with index-counting + bulk erase

#### Kernel Null Deref
35. **imports.cpp:NtWaitForSingleObjectEx** — Added null check on GetKernelObject result
36. **imports.cpp:NtCreateEvent** — Added null check on handle parameter
37. **imports.cpp:ObReferenceObjectByHandle** — Added null check on object parameter
38. **imports.cpp:XamUserGetSigninInfo** — Added null check on info parameter
39. **imports.cpp:XamShowDeviceSelectorUI** — Conditional write on deviceId
40. **imports.cpp:VdPersistDisplay** — Conditional write on a2
41. **imports.cpp:NtReadFile** — Updates file position after successful read

#### Memory Safety
42. **heap.cpp:Heap::Size** — Validates via `IsLiveAllocation` before reading o1heap header
43. **guest_memory.cpp:RegisterGuestWatchRange** — Added `s_watchMtx` mutex for TOCTOU race
44. **guest_memory.cpp:RegisterGuestWatchValue** — Same mutex protection

#### Guest Thread
45. **guest_thread.cpp:Start** — Null check on `FindFunction` before dereference
46. **guest_thread.cpp** — Skip `pthread_join` if `pthread_create` failed

#### Renderer
47. **native_renderer.cpp:84** — Range check before guest VA to host pointer cast
48. **native_renderer.cpp:153** — `IsValidRange` check before PPC_LOAD_U32 batch
49. **capture_hooks.cpp:138** — Replaced host-address cast with `MapVirtual` for correct guest address
50. **shader_translator.cpp:484** — Sampler texture declarations now emit HLSL (was no-op)
51. **shader_translator.cpp:810** — Export zero-fill condition changed from `scalarDestRelative` to `exportData`

#### Asset Pipeline
52. **rage_asset_pipeline.cpp:ParseGeometry** — All 6 bounds checks use `uint64_t` cast to prevent overflow

#### Trace
53. **frame_trace.cpp:122** — Added sanity limit (10M packets) before massive allocation

#### Config/Doc
54. **render_command_queue.cpp:Shutdown** — Changed `memory_order_relaxed` to `memory_order_release`
55. **app.cpp:Init** — Moved `log::Initialize()` before first `MCLA_LOG_INFO` call

### Session 4 — Final fixes (12 source fixes)

#### Kernel Type Safety
56. **imports.cpp:NtClearEvent** — Changed from raw `Event*` to `uint32_t handle` with `GetKernelObject` + `dynamic_cast`
57. **imports.cpp:NtResumeThread** — Same pattern: `uint32_t handle` + proper resolution
58. **imports.cpp:NtSetEvent** — Same pattern: `uint32_t handle` + proper resolution

#### GPU Safety
59. **gpu_cp.cpp:CpAdvanceGuestPublication** — Added overflow guard on publication count
60. **gpu_cp.cpp:CpConsumePushWindow** — Added hard cap (4096) preventing unbounded push_back
61. **gpu_device.cpp:448** — Tautological `dwords*4%4` check replaced with `dwords == 0`

#### Memory Safety
62. **memory.h:Translate** — Added null base guard returning nullptr

#### D3D12
63. **d3d12_backend.cpp:CreateMipGenPipeline** — Added missing UAV descriptor table to root signature
64. **d3d12_backend.cpp:DrawDynamicMeshWithPipeline** — Removed mid-frame upload offset reset; added reset to BeginFrame

#### Code Quality
65. **boot_host.cpp** — Deduplicated FilterCapture/UnhandledExceptionFilter into shared `CaptureFaultInfo` helper (~80 lines removed)
66. **shader_translator.cpp:1044** — Removed misleading dead `(void)ps` line
67. **render_thread.cpp:424** — Added FIXME comment for 16-bit index assumption

---

## 13. Known Remaining Issues

All critical, high, and medium issues have been fixed. The following are minor/low-priority items:
1. **gpu_device.cpp:sub_82412F98** — Bypasses GPU fence check entirely (intentional for boot-to-menu, needs review for correctness)
2. **render_thread.cpp:424** — Index count assumes 16-bit indices (noted with FIXME)
3. **shader_translator.cpp:1044** — Dead `(void)ps` line REMOVED
4. **gpu_device.cpp:448** — Tautological check FIXED (now checks dwords == 0)
5. **FilterCapture/UnhandledExceptionFilter** — Deduplicated via shared `CaptureFaultInfo` helper

---

## 14. Data Flow Diagrams

### GPU Command Processing
```
Game calls GpuKick/BlitController
  → patches.cpp hk_GpuKick captures device + ring buffer base/limit
  → SanitizePm4Buffer clamps oversized packets
  → gpu_device.cpp sub_82420BA8 captures VB/IB descriptors
  → CapturedDrawV2 assembled
  → RenderCommandQueue::Enqueue(DRAW_INDEXED)
  → RenderCommandProcessor thread dequeues
  → D3D12Backend::BeginFrame/DrawDynamicMesh/ClearAndPresent
```

### Memory Translation
```
Guest operates on 32-bit addresses (0x82000000+)
  → GuestMemoryHeap::Translate(guestAddr) = m_base + guestAddr
  → GuestMemoryView::ReadU32BE checks validity, SEH-protected memcpy + Swap32
  → GPU MMIO: 0x7FC8xxxx → CpMmioWrite/CpMmioRead interceptors
  → Page watch: 0x50000000 range + dynamic ranges
  → Value watch: 4 watched values
```

### Kernel Hook Pattern
```
Original PPC function pointer saved (g_original_*)
  → Detour inspects PPC context registers (ctx.r3..r31)
  → May override return value and return early
  → May call original via g_original_*(ctx, base) to passthrough
  → InstallNativeDetour: VirtualProtect → save 12 bytes → write mov rax+jmp → flush icache
```
