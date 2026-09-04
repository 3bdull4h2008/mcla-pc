# MCLA-PC: Comprehensive Project Guide

## Complete Technical Documentation & Implementation Reference

**Author:** Abdullah Atef Alrawashdeh (HTU Student)  
**Last Updated:** 2026-08-30  
**Project Root:** `E:\mcla pc`  
**Repository Status:** Phase 3 PASSED, Phase 4 IN PROGRESS

---

# TABLE OF CONTENTS

1. [Project Overview](#1-project-overview)
2. [Architecture Deep Dive](#2-architecture-deep-dive)
3. [Build System & Dependencies](#3-build-system--dependencies)
4. [Source Code Architecture](#4-source-code-architecture)
5. [Kernel Framework](#5-kernel-framework)
6. [GPU & Rendering Pipeline](#6-gpu--rendering-pipeline)
7. [Shader Translation Pipeline](#7-shader-translation-pipeline)
8. [Phase Plans & Implementation Status](#8-phase-plans--implementation-status)
9. [Agent System & Workflow](#9-agent-system--workflow)
10. [Validation & Testing Infrastructure](#10-validation--testing-infrastructure)
11. [Technical Reference: RPF3 Archives](#11-technical-reference-rpf3-archives)
12. [Technical Reference: PPC Recompilation](#12-technical-reference-ppc-recompilation)
13. [Debugging & Troubleshooting Guide](#13-debugging--troubleshooting-guide)
14. [Development Workflow & Rules](#14-development-workflow--rules)
15. [Appendices](#15-appendices)

---

# 1. PROJECT OVERVIEW

## 1.1 What is MCLA-PC?

MCLA-PC is a native Direct3D 12 renderer rebuild for **Midnight Club: Los Angeles** (Xbox 360). The core idea is:

1. **Recompile** the Xbox 360 PowerPC game code to x86-64 using XenonRecomp (46,000+ function mappings across 179 translation units)
2. **Run** the recompiled PPC game code untouched on Windows
3. **Intercept** rendering intent at the high-level draw boundary
4. **Replay** intercepted draws as real D3D12, bypassing the Xbox 360 Xenos GPU command processor entirely

The project does **NOT** emulate the Xbox 360 GPU. Instead, it captures what the game *wants* to draw and translates that into native PC rendering calls.

## 1.2 Core Philosophy

- **No PM4 in the native path**: The game's GPU command packets (PM4) are never read, written, drained, or depended upon in the native renderer
- **Device-method boundary**: Override the game's own D3D-class device methods rather than parsing packets
- **Guest code runs untouched**: The recompiled PPC code executes as-is; only the rendering boundary is intercepted
- **Offline shader cache**: Xenos microcode is pre-translated to HLSL/DXIL at build time
- **D3D12 only**: No rendering abstraction layer; Direct3D 12 is the sole API

## 1.3 Legal Notice

No game code or assets are included in the repository. Users must provide their own legally dumped copy of Midnight Club: Los Angeles (Xbox 360).

## 1.4 Current Status Summary

| Phase | Description | Status |
|-------|-------------|--------|
| Phase 1 | ABI Migration | ✅ COMPLETE |
| Phase 2 | Kernel Framework | ✅ COMPLETE (13/13 tests) |
| Phase 3 | Critical Imports (Boot) | ✅ PASSED (2026-08-22) |
| Phase 4' | Device-Boundary Takeover | 🔄 IN PROGRESS (Steps 1-2 done) |
| Phase 4.5' | Render Thread & Queues | ⏳ PENDING |
| Phase 5' | Real Draws via Device Boundary | ⏳ PENDING |
| Phase 6' | Native Default & Legacy Retirement | ⏳ PENDING |
| Phase 7' | Build Env Modernization | ⏳ PENDING |
| Phase 8' | Codegen Config Completion | ⏳ PENDING |
| Phase 9' | Kernel Surface Completion | ⏳ PENDING |

---

# 2. ARCHITECTURE DEEP DIVE

## 2.1 System Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                        MCLA-PC Architecture                      │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────────┐      │
│  │  default.xex │───>│  XenonRecomp │───>│  Generated   │      │
│  │  (Xbox 360)  │    │  (PPC→x86)   │    │  179 TUs     │      │
│  └──────────────┘    └──────────────┘    │  46K funcs   │      │
│                                          └──────┬───────┘      │
│                                                 │                │
│  ┌──────────────────────────────────────────────┼──────────────┐│
│  │               Boot Host (mcla.exe)           │              ││
│  │  ┌────────────┐  ┌────────────┐  ┌─────────▼─────────┐   ││
│  │  │   SDL3     │  │   Guest    │  │   PPC Context     │   ││
│  │  │   Init     │  │   Memory   │  │   (GPR/FPR/VMX)   │   ││
│  │  └────────────┘  │   Heap     │  └───────────────────┘   ││
│  │                   └────────────┘                          ││
│  │  ┌────────────────────────────────────────────────────┐  ││
│  │  │              Kernel Framework                      │  ││
│  │  │  ┌──────────┐ ┌──────────┐ ┌──────────┐          │  ││
│  │  │  │ Memory   │ │ Threads  │ │ Objects  │          │  ││
│  │  │  │ Manager  │ │ (Guest)  │ │ (Events, │          │  ││
│  │  │  │          │ │          │ │  Semas)  │          │  ││
│  │  │  └──────────┘ └──────────┘ └──────────┘          │  ││
│  │  │  ┌──────────┐ ┌──────────┐ ┌──────────┐          │  ││
│  │  │  │   VFS    │ │   XAM    │ │  Imports │          │  ││
│  │  │  │  (RPF3)  │ │ (Xbox    │ │  (Nt*,   │          │  ││
│  │  │  │          │ │  Live)   │ │   Ke*)   │          │  ││
│  │  │  └──────────┘ └──────────┘ └──────────┘          │  ││
│  │  └────────────────────────────────────────────────────┘  ││
│  │                                                          ││
│  │  ┌────────────────────────────────────────────────────┐  ││
│  │  │              GPU Subsystem                         │  ││
│  │  │  ┌──────────┐ ┌──────────┐ ┌──────────┐          │  ││
│  │  │  │ GPU MMIO │ │ GPU CP   │ │  Device  │          │  ││
│  │  │  │ Traps    │ │ (Legacy) │ │ Boundary │          │  ││
│  │  │  └──────────┘ └──────────┘ └──────────┘          │  ││
│  │  │  ┌──────────┐ ┌──────────┐ ┌──────────┐          │  ││
│  │  │  │ Renderer │ │ Capture  │ │ Native   │          │  ││
│  │  │  │  Mode    │ │  Hooks   │ │ Renderer │          │  ││
│  │  │  └──────────┘ └──────────┘ └──────────┘          │  ││
│  │  └────────────────────────────────────────────────────┘  ││
│  │                                                          ││
│  │  ┌────────────────────────────────────────────────────┐  ││
│  │  │              Shader Pipeline                       │  ││
│  │  │  Xenos Microcode → IR → HLSL → DXIL (DXC)        │  ││
│  │  │  1,264 shaders translated, 0 unknown opcodes      │  ││
│  │  └────────────────────────────────────────────────────┘  ││
│  │                                                          ││
│  │  ┌────────────────────────────────────────────────────┐  ││
│  │  │              D3D12 Backend                         │  ││
│  │  │  Device → PSO Cache → Command Lists → Present     │  ││
│  │  └────────────────────────────────────────────────────┘  ││
│  └──────────────────────────────────────────────────────────┘│
└─────────────────────────────────────────────────────────────────┘
```

## 2.2 Data Flow

1. **Boot**: `mcla.exe` → SDL3_Init → GuestMemory_Init → Boot Host (ReXGlue/XenonRecomp)
2. **PPC Start**: Guest entry at `0x821322B8` (_xstart) → game initialization
3. **Kernel Imports**: NtCreateEvent, ExCreateThread, NtQueryInformationFile, etc.
4. **VFS/RPF**: Load `xarchive_*.rpf` packfiles via RPF3 VFS
5. **GPU Context Init**: `sub_82413588` creates XGPU context, initializes command buffer
6. **VSync**: `VdSetGraphicsInterruptCallback` fires at 60fps
7. **CP Drain (FROZEN legacy)**: doorbell→ring→rptr writeback chain live but frozen — no opcode expansion, retired at P6′
8. **Capture Boundary (P4′ IN PROGRESS)**: device-method hooks live (create @sub_82413588, packet capture v2 @sub_82411640 — steps 1-2 done); idle until the boot OOM blocker closes
9. **D3D12 Present**: Native renderer produces frames via swap chain

## 2.3 Key Design Decisions

### No PM4 in Native Path
The MCLA rebuild plan explicitly states: "Frame production must not read, write, drain, or depend on the PM4 ring." This is a deliberate divergence from the legacy path.

### Device-Method Boundary
Instead of parsing PM4 packets, the project overrides the game's own device method function pointers. When the game calls `SetRenderState`, `DrawIndexedPrimitive`, etc., those calls are intercepted at the C++ virtual method boundary.

### Identity Handles (UnleashedRecomp Pattern)
Kernel objects use identity handles where the handle value IS the pointer to the object. This matches UnleashedRecomp's canonical framework and simplifies the kernel implementation.

### Typed-Argument Hooks
All import hooks use typed C++ function signatures instead of manual `ctx.rN` register reads. Example:
```cpp
// WRONG (old pattern):
GUEST_FUNCTION_HOOK(sub_82XXXXXX) {
    uint32_t param1 = ctx.r3;
    uint32_t param2 = ctx.r4;
}

// CORRECT (typed-arg pattern):
GUEST_FUNCTION_HOOK(sub_82XXXXXX, uint32_t handle, uint32_t info_class) {
    // Use handle and info_class directly
}
```

---

# 3. BUILD SYSTEM & DEPENDENCIES

## 3.1 Build Requirements

| Component | Version | Purpose |
|-----------|---------|---------|
| Visual Studio BuildTools | 2022 | MSVC runtime, vcvars64 |
| CMake | 3.25+ | Build system generator |
| Ninja | Latest | Build executor |
| clang-cl | LLVM/Clang | C++23 compiler (MSVC-compatible) |
| LLD | LLVM/Clang | Linker (`-fuse-ld=lld`) |
| DirectX Shader Compiler | Latest | HLSL → DXIL compilation |
| SDL3 | 3.2.6 | Window/input/audio framework |
| Node.js | LTS | Offline tooling (manifest, database) |

## 3.2 Build Commands

### Initial Configuration
```batch
cd "E:\mcla pc"
configure.bat
```

This runs:
```batch
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo
```

### Building
```batch
ninja_build.bat
```

This runs:
```batch
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
ninja -v -C build mcla.exe
```

### Running Validators
```batch
cd build
phase0_validator.exe
shader_pipeline_validator.exe
xenos_decode_validator.exe
phase3_validator.exe
backend_validator.exe
```

### Running Phase Gates
```powershell
powershell -ExecutionPolicy Bypass -File tools/run_phase_gates.ps1
```

## 3.3 CMakeLists.txt Structure

The CMakeLists.txt (505 lines) defines:

### Main Target: `mcla`
- **C++ Standard**: C++23
- **Compiler**: clang-cl with `/MT` (static MSVC runtime)
- **Linker**: LLD (`-fuse-ld=lld`)
- **Definitions**: `_CRT_SECURE_NO_WARNINGS`, `NOMINMAX`, `WIN32_LEAN_AND_MEAN`, `UNICODE`, `_UNICODE`
- **Includes**: `src/`, `generated/ppc_xenon/`, `third_party/` subdirectories

### Source Files (organized by subsystem):

**Core** (4 files):
- `src/main.cpp` - Entry point
- `src/app.cpp` - Application loop
- `src/early_init.cpp` - Early initialization
- `src/patches.cpp` - Function patches/hooks

**GPU/MMIO** (3 files):
- `src/gpu_mmio.cpp` - Memory-mapped I/O traps
- `src/gpu_cp.cpp` - Command processor emulation
- `src/gpu_device.cpp` - Device management

**Renderer** (4 files):
- `src/native_renderer.cpp` - Native D3D12 renderer
- `src/renderer_mode.cpp` - Renderer mode switching
- `src/renderer_hook_dispatch.cpp` - Hook dispatch
- `src/capture_hooks.cpp` - Draw capture hooks

**Guest Memory** (2 files):
- `src/guest_memory.cpp` - Guest memory management
- `src/guest_mem_scan.cpp` - Memory scanning

**VFS** (1 file):
- `src/vfs_rpf.cpp` - RPF3 archive VFS

**D3D12 Backend** (3 files):
- `src/d3d12_backend.cpp` - D3D12 device/PSO
- `src/render_command_queue.cpp` - Command queue
- `src/render_thread.cpp` - Render thread

**Kernel** (7 files):
- `src/kernel/memory.cpp` - Memory management
- `src/kernel/heap.cpp` - Heap allocator
- `src/kernel/o1heap.c` - O(1) heap
- `src/kernel/xdm.cpp` - Xbox Device Manager
- `src/kernel/guest_thread.cpp` - Guest thread management
- `src/kernel/imports.cpp` - Kernel imports (Nt*, Ke*, etc.)
- `src/kernel/xam.cpp` - XAM (Xbox Activity Manager)

**Boot** (2 files):
- `src/boot_host.cpp` - Boot host
- `src/boot_log.cpp` - Boot logging

**Renderer Subsystem** (10 files):
- `src/renderer/xenos_microcode.cpp` - Xenos microcode decoder
- `src/renderer/xenos_shader_ir.cpp` - Shader IR
- `src/renderer/shader_translator.cpp` - HLSL/DXIL translation
- `src/renderer/dxc_runtime.cpp` - DXC runtime
- `src/renderer/pipeline_cache.cpp` - PSO cache
- `src/renderer/vertex_decode.cpp` - Vertex decoding
- `src/renderer/grc_fvf_decode.cpp` - FVF decoding
- `src/renderer/rage_asset_pipeline.cpp` - RAGE assets
- `src/renderer/resource_cache.cpp` - Resource cache
- `src/renderer/texture_decode.cpp` - Texture decode

**Generated PPC Recompilation** (179 TUs):
- `generated/ppc_xenon/ppc_recomp.0..178.cpp`
- `generated/ppc_xenon/ppc_func_mapping.cpp` (46,029 lines)

**Third-Party** (3 files):
- `third_party/xxhash.c`
- `third_party/lzxd.c` (LZX decompression)
- `third_party/aes.c` (AES decryption)

### Validator Targets (8):
| Target | Purpose |
|--------|---------|
| `phase0_validator` | Kernel framework unit tests (13 tests) |
| `xenos_decode_validator` | Raw Xenos microcode decode |
| `shader_pipeline_validator` | Shader parse + translate |
| `phase3_validator` | Vertex fetch + resource decode |
| `texture_decode_test` | Tiled/Xenos texture decode |
| `capture_dump_validator` | DrawPacket vs guest memory |
| `xtr_dump_validator` | Standalone capture dumps |
| `backend_validator` | D3D12 device + PSO smoke test |

## 3.4 Third-Party Libraries

| Library | Location | Purpose |
|---------|----------|---------|
| SDL3 | `third_party/SDL3/` | Window management, input, audio |
| fmt | `third_party/fmt/` | String formatting (header-only) |
| spdlog | `third_party/spdlog/` | Logging (header-only) |
| toml++ | `third_party/toml++/` | TOML config parsing |
| xxHash | `third_party/xxhash.h` | Fast hashing |
| O1Heap | `third_party/o1heap.h` | O(1) heap allocator |
| DXC | `third_party/dxc/` | DirectX Shader Compiler headers |

## 3.5 Compiler Flags

```
/std:c++23 /MT /EHsc /nologo /W4 /WX
-D_CRT_SECURE_NO_WARNINGS
-DNOMINMAX
-DWIN32_LEAN_AND_MEAN
-DUNICODE -D_UNICODE
-DENABLE_XMVECTOR
-fuse-ld=lld
```

---

# 4. SOURCE CODE ARCHITECTURE

## 4.1 File Organization

```
src/
├── main.cpp                    # Entry point, SDL3 init
├── app.cpp                     # Main application loop
├── early_init.cpp              # Early boot initialization
├── patches.cpp                 # Function patches and hooks
├── gpu_mmio.cpp                # Memory-mapped I/O traps
├── gpu_cp.cpp                  # Command processor emulation
├── gpu_device.cpp              # Xbox 360 device management
├── native_renderer.cpp         # Native D3D12 renderer
├── renderer_mode.cpp           # Renderer mode switching
├── renderer_hook_dispatch.cpp  # Hook dispatch system
├── capture_hooks.cpp           # Draw capture hooks
├── guest_memory.cpp            # Guest memory management
├── guest_mem_scan.cpp          # Memory scanning
├── vfs_rpf.cpp                 # RPF3 archive VFS
├── d3d12_backend.cpp           # D3D12 backend
├── render_command_queue.cpp    # Command queue
├── render_thread.cpp           # Render thread
├── boot_host.cpp               # Boot host
├── boot_log.cpp                # Boot logging
├── kernel/
│   ├── memory.cpp              # Memory management
│   ├── heap.cpp                # Heap allocator
│   ├── o1heap.c                # O(1) heap implementation
│   ├── xdm.cpp                 # Xbox Device Manager
│   ├── guest_thread.cpp        # Guest thread management
│   ├── imports.cpp             # Kernel imports
│   └── xam.cpp                 # XAM (Xbox Activity Manager)
└── renderer/
    ├── xenos_microcode.cpp     # Xenos microcode decoder
    ├── xenos_shader_ir.cpp     # Shader intermediate representation
    ├── shader_translator.cpp   # HLSL/DXIL translation
    ├── dxc_runtime.cpp         # DXC runtime integration
    ├── pipeline_cache.cpp      # PSO cache management
    ├── vertex_decode.cpp       # Vertex data decoding
    ├── grc_fvf_decode.cpp      # FVF format decoding
    ├── rage_asset_pipeline.cpp # RAGE asset handling
    ├── resource_cache.cpp      # Resource caching
    └── texture_decode.cpp      # Texture decoding
```

## 4.2 Core Data Structures

### PPCContext (generated/ppc_xenon/ppc_context.h)
The central emulation context holding all PowerPC register state:

```cpp
struct PPCContext {
    // GPRs (32 general-purpose registers)
    PPCRegister gpr[32];
    
    // FPRs (32 floating-point registers)
    PPCRegister fpr[32];
    
    // VMX/AltiVec (128 vector registers)
    PPCVRegister vpr[128];
    
    // Special registers
    PPCRegister lr;      // Link Register
    PPCRegister ctr;     // Count Register
    PPCRegister reserved;// Reservation register
    PPCXERRegister xer;  // Exception register
    PPCCCRRegister cr;   // Compare register
    PPCFPSCRRegister fpscr; // FP status/control
    
    // Control registers
    uint64_t msr;        // Machine State Register
};
```

### GuestDevice (src/gpu_device.cpp)
Represents an Xbox 360 GPU device instance:

```cpp
struct GuestDevice {
    uint32_t dirtyFlags;
    // Ring buffer pointers
    uint32_t* ringPtr;
    // Render state function pointers (0x65 entries)
    void* setRenderStateFunctions[0x65];
    // Sampler table
    void* samplerTable;
};
```

### KernelObject (src/kernel/)
Base class for all kernel objects:

```cpp
class KernelObject {
public:
    virtual ~KernelObject() = default;
    // Identity handle = this pointer
    void* GetHandle() { return this; }
};
```

### RingState (src/gpu_cp.cpp)
Tracks the state of the GPU command processor ring buffer:

```cpp
struct RingState {
    uint32_t base;
    uint32_t size;
    uint32_t rptr;  // Read pointer
    uint32_t wptr;  // Write pointer
};
```

## 4.3 Key Functions

### Boot Sequence
1. `main()` → SDL3 initialization
2. `mcla::early_init()` → Memory layout setup
3. `mcla::boot_host()` → PPC context initialization
4. `mcla::start_ppc_host()` → Begin recompiled code execution
5. Guest entry at `_xstart` (address `0x821322B8`)

### Hook System
```cpp
// Install a hook at a guest address
GUEST_FUNCTION_HOOK(guest_address, typed_params...) {
    // Intercept guest function call
    // Capture state, don't make D3D12 calls
}
```

### Memory Access
```cpp
// Checked big-endian memory access
uint32_t val = mcla::native::ReadGuestU32(guest_addr);
mcla::native::WriteGuestU32(guest_addr, value);
```

---

# 5. KERNEL FRAMEWORK

## 5.1 Overview

The kernel framework emulates the Xbox 360 kernel API, providing:

- **Memory management** (NtAllocateVirtualMemory, MmAllocatePhysicalMemoryEx)
- **Thread management** (ExCreateThread, KeDelayExecutionThread)
- **Synchronization** (NtCreateEvent, NtCreateSemaphore, KeWaitForSingleObject)
- **File I/O** (NtReadFile, NtQueryInformationFile)
- **Xbox Live** (NetDll_WSAStartup)
- **Graphics** (Vd* imports)

## 5.2 Canonical Framework Rules

### Rule 1: Identity Handles
```cpp
// CORRECT: Handle IS the pointer
void* handle = new KernelObject();
// handle == 0x12345678 (the object's address)
// Return handle as the "handle" to the guest

// WRONG: Handle is an index into a table
uint32_t handle = g_handleTable.Allocate(object);
```

### Rule 2: QueryKernelObject Lazy-Wrap
```cpp
// When guest passes a handle, resolve it:
KernelObject* obj = QueryKernelObject(handle);
// If handle is valid pointer to KernelObject, return it
// Otherwise, return nullptr (invalid handle)
```

### Rule 3: Typed-Argument Hooks
```cpp
// CORRECT: Strongly-typed parameters
GUEST_FUNCTION_HOOK(sub_82413588, uint32_t device_type, uint32_t flags) {
    // device_type and flags are automatically extracted from ctx.r3, ctx.r4
}

// WRONG: Manual register extraction
GUEST_FUNCTION_HOOK(sub_82413588) {
    uint32_t device_type = ctx.r3;
    uint32_t flags = ctx.r4;
}
```

### Rule 4: Single-Parameter KernelObject::Wait
```cpp
// CORRECT: Single parameter (timeout or INFINITE)
obj->Wait(INFINITE);
obj->Wait(1000); // 1 second timeout

// WRONG: Separate wait/timeout parameters
obj->Wait(true, 1000);
```

### Rule 5: Generation Counter
```cpp
// For KeWaitForMultipleObjects, track generation:
std::atomic<uint64_t> g_keSetEventGeneration;

// When KeSetEvent is called:
g_keSetEventGeneration.fetch_add(1);

// Wait checks generation to detect spurious wakeups
```

### Rule 6: Critical Sections = std::atomic_ref
```cpp
// Xbox 360 critical section layout (28 bytes):
// +0x00: XDISPATCHER_HEADER (16 bytes)
// +0x10: LockCount (int32_t)
// +0x14: RecursionCount (int32_t)
// +0x18: OwningThread (uint32_t)

// Use std::atomic_ref on guest memory:
void EnterCriticalSection(uint32_t cs_addr) {
    auto lock_count = std::atomic_ref<int32_t>(ReadGuestU32(cs_addr + 0x10));
    // ...
}
```

### Rule 7: ExCreateThread = GuestThread::Start
```cpp
// ExCreateThread should use GuestThread::Start pattern
GuestThread::Start(entry_point, stack_size, priority);
```

### Rule 8: ObReferenceObjectByHandle
```cpp
// Returns handle as pointer (identity handle pattern)
KernelObject* obj = ObReferenceObjectByHandle(handle);
// obj IS the handle value (identity)
```

### Rule 9: First-Page NOACCESS Trap
```cpp
// Guest memory first page is NOACCESS to catch null pointer dereferences
VirtualAlloc(guest_membase, PAGE_SIZE, MEM_RESERVE, PAGE_NOACCESS);
```

### Rule 10: Vd Imports Match Xenia Semantics
All Vd* (Video Display) imports must match Xenia emulator semantics exactly.

## 5.3 Kernel Import Table

The kernel imports are implemented in `src/kernel/imports.cpp`:

| Import | Purpose | Status |
|--------|---------|--------|
| NtCreateEvent | Create synchronization event | ✅ |
| NtCreateSemaphore | Create semaphore | ✅ |
| NtWaitForSingleObject | Wait on single object | ✅ |
| NtWaitForMultipleObjects | Wait on multiple objects | ✅ |
| KeSetEvent | Signal event | ✅ |
| KeReleaseSemaphore | Release semaphore | ✅ |
| KeDelayExecutionThread | Sleep/delay | ✅ |
| ExCreateThread | Create guest thread | ✅ |
| NtAllocateVirtualMemory | Allocate virtual memory | ✅ |
| NtFreeVirtualMemory | Free virtual memory | ✅ |
| NtQueryInformationFile | Query file info | ✅ |
| NtReadFile | Read file data | ✅ |
| NtCreateFile | Create/open file | ✅ |
| MmAllocatePhysicalMemoryEx | Allocate physical memory | ✅ |
| MmQueryAllocationSize | Query allocation size | ✅ |
| NetDll_WSAStartup | Network initialization | ✅ |
| VdSetGraphicsInterruptCallback | VSync callback | ✅ |
| VdGetSystemCommandBuffer | Get command buffer | ✅ |
| HalReturnToFirmware | Firmware return | ✅ |

## 5.4 Thread Management

### GuestThread Pattern
```cpp
class GuestThread {
public:
    static void Start(uint32_t entry_point, uint32_t stack_size, int priority);
    
    // Thread runs recompiled PPC code
    void Run() {
        PPCContext ctx;
        // Set up stack, entry point
        // Call recompiled function
        sub_xxxx(&ctx, g_base);
    }
};
```

### Thread Synchronization
```cpp
// Event wait (with timeout)
NTSTATUS NtWaitForSingleObject(HANDLE handle, BOOLEAN alertable, PLARGE_INTEGER timeout) {
    KernelObject* obj = QueryKernelObject(handle);
    if (!obj) return STATUS_INVALID_HANDLE;
    
    if (timeout && timeout->QuadPart == 0) {
        // Poll (no wait)
        return obj->IsSignaled() ? STATUS_SUCCESS : STATUS_TIMEOUT;
    }
    
    // Timed wait
    return obj->Wait(timeout_ms);
}
```

## 5.5 Memory Management

### Guest Memory Layout
```
0x00000000 - 0x0FFFFFFF: Guest virtual memory (256MB)
  0x00000000 - 0x00000FFF: NOACCESS guard page
  0x00001000 - 0x0FFFFFFF: Guest usable memory
0x82000000 - 0x89FFFFFF: PPC image base
  0x82130000 - 0x89FFFFFF: Code section (~6.8MB)
```

### Memory Access Functions
```cpp
// Big-endian memory access (Xbox 360 is big-endian)
uint32_t ReadGuestU32(uint32_t address);
uint16_t ReadGuestU16(uint32_t address);
uint8_t  ReadGuestU8(uint32_t address);
void     WriteGuestU32(uint32_t address, uint32_t value);
void     WriteGuestU16(uint32_t address, uint16_t value);
void     WriteGuestU8(uint32_t address, uint8_t value);

// Block copy
void     ReadGuestBlock(uint32_t address, void* dst, size_t size);
void     WriteGuestBlock(uint32_t address, const void* src, size_t size);
```

---

# 6. GPU & RENDERING PIPELINE

## 6.1 Xbox 360 GPU (Xenos) Overview

The Xbox 360 GPU (Xenos) is a unified shader architecture with:
- **Command Processor (CP)**: Processes PM4 packets from the CPU
- **Ring Buffer**: CPU writes PM4 packets, CP reads and executes
- **Vertex/Pixel Shaders**: Unified shader architecture
- **Texture Cache**: Tiled, swizzled texture format
- **Frame Buffer**: 10MB eDRAM

## 6.2 PM4 Packets (Legacy Path)

PM4 packets are Xbox 360 GPU command packets:

```cpp
// PM4 packet header
struct PM4Packet {
    uint32_t header;  // Packet type + size
    // Type 0: NOP
    // Type 2: PM4_TYPE2 (filler)
    // Type 3: GPU command
};

// Common Type 3 packets:
// IT_NOP (0x10): No operation
// IT_SETulings (0x1E): Set predicate
// IT_WAIT_REG_MEM (0x3C): Wait for register/memory
// IT_SET_CONTEXT_REG (0x3D): Set context register
// IT_DRAW_INDX (0x82): Indexed draw
// IT_DRAW_INDX_2 (0x36): Indexed draw (variant)
```

## 6.3 Device Boundary Takeover (P4')

### Step 1: Device Creation Hook (DONE)
```cpp
// Hook the device creation function
GUEST_FUNCTION_HOOK(sub_82413588) {
    // This is the XGPUCreateContext equivalent
    // GuestDevice layout:
    // +0x00: dirtyFlags
    // +0x04: ring ptrs
    // +0x08: setRenderStateFunctions[0x65]
    // +0x??? : sampler table
    
    // Capture device pointer for future interception
    g_guest_device = /* captured device */;
}
```

### Step 2: FP-Table Redirect (DONE)
```cpp
// The device has a function pointer table for render state
// When game calls SetRenderState, it goes through:
// device->setRenderStateFunctions[index](args...)
//
// We redirect these to our capture functions
```

### Step 3: Render Thread & Queues (P4.5' - PENDING)
```cpp
// Create a dedicated render thread
class RenderThread {
    std::thread m_thread;
    CommandQueue m_queue;
    
    void Run() {
        while (m_running) {
            auto cmd = m_queue.WaitAndPop();
            ExecuteCommand(cmd);
        }
    }
    
    void ExecuteCommand(RenderCommand& cmd) {
        switch (cmd.type) {
            case CommandType::SetPipelineState:
                // Create/lookup PSO
                break;
            case CommandType::DrawIndexed:
                // Record D3D12 draw
                break;
        }
    }
};
```

## 6.4 Native Renderer Architecture

### Renderer Modes
```cpp
enum class RendererMode {
    Legacy,   // Original Xenos CP path (current default)
    Native,   // Native D3D12 path (target)
    Capture,  // Capture mode for debugging
};
```

### Capture Hooks
```cpp
// When in Capture mode, intercept draw calls:
void OnDrawIndexedPrimitive(uint32_t index_count, uint32_t start_index, uint32_t prim_type) {
    // Capture all state:
    // - Current PSO (shaders, blend, depth, rasterizer)
    // - Vertex buffers + layouts
    // - Index buffers
    // - Constant buffers (all 14 slots)
    // - Textures (all 16 slots)
    // - Viewport + scissor
    
    // Write to capture file for later replay
    CaptureWriter::WriteDrawPacket(packet);
}
```

## 6.5 D3D12 Backend

### Device Creation
```cpp
// Create D3D12 device
ComPtr<ID3D12Device> device;
D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

// Create command queue
ComPtr<ID3D12CommandQueue> queue;
D3D12_COMMAND_QUEUE_DESC desc = {};
desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
device->CreateCommandQueue(&desc, IID_PPV_ARGS(&queue));

// Create swap chain
ComPtr<IDXGISwapChain3> swap_chain;
// ... setup swap chain with SDL3 window
```

### PSO Cache
```cpp
class PipelineCache {
    std::unordered_map<PipelineKey, ComPtr<ID3D12PipelineState>> m_cache;
    
    ID3D12PipelineState* GetOrCreatePSO(const PipelineKey& key) {
        auto it = m_cache.find(key);
        if (it != m_cache.end()) return it->second.Get();
        
        // Create new PSO
        D3D12_GRAPHICS_PIPELINE_STATE_DESC desc = {};
        // ... fill desc from key
        
        ComPtr<ID3D12PipelineState> pso;
        device->CreateGraphicsPipelineState(&desc, IID_PPV_ARGS(&pso));
        m_cache[key] = pso;
        return pso.Get();
    }
};
```

## 6.6 Render Thread

The render thread runs on a dedicated thread, processing commands from a queue:

```cpp
class RenderThread {
public:
    void Start() {
        m_thread = std::thread(&RenderThread::Run, this);
    }
    
    void Run() {
        while (m_running) {
            RenderCommand cmd;
            if (m_queue.TryPop(cmd)) {
                ExecuteCommand(cmd);
            } else {
                // No work, sleep briefly
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
    }
    
private:
    void ExecuteCommand(const RenderCommand& cmd) {
        switch (cmd.type) {
            case RenderCommandType::BeginFrame:
                BeginFrame();
                break;
            case RenderCommandType::EndFrame:
                EndFrame();
                break;
            case RenderCommandType::SetPipelineState:
                SetPipelineState(cmd.pso_handle);
                break;
            case RenderCommandType::SetVertexBuffers:
                SetVertexBuffers(cmd.vb_handles, cmd.count);
                break;
            case RenderCommandType::DrawIndexed:
                DrawIndexed(cmd.index_count, cmd.start_index);
                break;
        }
    }
};
```

---

# 7. SHADER TRANSLATION PIPELINE

## 7.1 Overview

The shader translation pipeline converts Xbox 360 Xenos GPU microcode into DirectX 12 compatible shaders:

```
Xenos Microcode → Xenos IR → HLSL → DXIL (via DXC)
```

## 7.2 Xenos Microcode Format

Xbox 360 Xenos uses a custom instruction set for vertex and pixel shaders:

```cpp
// Xenos instruction format
struct XenosInstruction {
    uint32_t opcode : 5;     // Instruction type
    uint32_t dst : 6;        // Destination register
    uint32_t src0 : 8;       // Source 0
    uint32_t src1 : 8;       // Source 1
    uint32_t src2 : 8;       // Source 2 (for 3-src instructions)
    uint32_t modifiers : 3;  // Instruction modifiers
};
```

### Common Xenos Instructions
- `MOV`: Move/register copy
- `ADD`: Addition
- `MUL`: Multiply
- `MAD`: Multiply-add
- `DP3/DP4`: Dot product (3/4 component)
- `RCP`: Reciprocal
- `RSQ`: Reciprocal square root
- `LOG/EXP`: Logarithm/Exponential
- `CND/CNDGT`: Conditional moves
- `TEX/TEXLDF/TEXREG2AR/TEXREG2GB/TEXREG2PK`: Texture sampling
- `CALL/LOOP/BREAK/IF`: Control flow

## 7.3 Shader IR (Intermediate Representation)

The IR is a platform-independent representation:

```cpp
struct ShaderIR {
    std::vector<IRInstruction> instructions;
    std::vector<IRRegister> temps;
    std::vector<IRRegister> inputs;
    std::vector<IRRegister> outputs;
    ShaderType type; // Vertex or Pixel
};
```

## 7.4 HLSL Translation

The IR is translated to HLSL:

```hlsl
// Example HLSL output
cbuffer Constants : register(b0) {
    float4x4 worldviewproj;
};

struct VS_INPUT {
    float3 position : POSITION;
    float4 color : COLOR0;
};

struct VS_OUTPUT {
    float4 position : SV_POSITION;
    float4 color : COLOR0;
};

VS_OUTPUT main(VS_INPUT input) {
    VS_OUTPUT output;
    output.position = mul(float4(input.position, 1.0f), worldviewproj);
    output.color = input.color;
    return output;
}
```

## 7.5 DXIL Compilation

HLSL is compiled to DXIL using the DirectX Shader Compiler:

```cpp
#include <dxcapi.h>

ComPtr<IDxcCompiler> compiler;
DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(&compiler));

ComPtr<IDxcBlob> dxil_blob;
compiler->Compile(
    source_blob.Get(),      // HLSL source
    L"main",               // Entry point
    L"vs_5_0",             // Target profile
    nullptr, 0,            // Arguments
    nullptr, 0,            // Defines
    nullptr,               // Include handler
    &dxil_blob             // Output
);
```

**DXIL signing (verified 2026-09-03 vs DirectXShaderCompiler docs):** the public
DXIL validator **verifies and signs** the container — the D3D12 runtime rejects
unsigned DXIL. For the offline cache (P5.5′), the build must run dxc + dxil.dll
so every embedded blob stays signed; add a validator assert on the signature
flag so a toolchain regression fails offline, not at PSO creation.

**Specialization constants (upstream XenosRecomp technique):** DXIL has no
native specialization constants. Upstream compiles shaders as libraries with a
declared-but-unimplemented function returning the constant (e.g. alpha-test
flag, R11G11B10 NORMAL/TANGENT/BINORMAL unpack), then generates a tiny
implementation at runtime, compiles it, and LINKS it with the shader. Only
adopt if MCLA's corpus demands either behavior.

## 7.6 Shader Corpus

The project includes a complete shader corpus:

- **1,264 shader files** with raw Xenos microcode
- **0 unknown opcodes** (100% coverage)
- **1,612 translated shaders** (vertex + pixel)
- All shaders validated by `shader_pipeline_validator`

**Offline-cache blueprint (verified vs `hedge-dev/XenosRecomp` 2026-09-03):**
its directory-scan mode converts a whole corpus and exports the cache as a
**`.cpp` file embedded directly in the executable**; runtime lookup is a
**64-bit XXH3 hash** of the shader binary (`third_party/xxhash` already
vendored). DXIL compresses as-is with zstd (SPIR-V would be pre-compressed
with smol-v). Upstream does NOT implement memexport or point size — audit the
corpus for both before trusting the 0-unknown coverage number (see plan
Risk Register R4).

## 7.7 Pipeline Cache

Compiled shaders are cached to avoid recompilation:

```cpp
class PipelineCache {
    // Maps shader hash → compiled PSO
    std::unordered_map<uint64_t, ComPtr<ID3D12PipelineState>> m_cache;
    
    // Disk cache for offline compilation
    void SaveToDisk(const std::string& path);
    void LoadFromDisk(const std::string& path);
};
```

For the embedded corpus cache, use XXH3-64 over the raw microcode as the key
(same hash family upstream uses), not a custom hash — keeps our cache
diffable against XenosRecomp's tooling output.

---

# 8. PHASE PLANS & IMPLEMENTATION STATUS

## 8.1 Phase 1: ABI Migration ✅ COMPLETE

**Goal:** Migrate the codebase to use XenonRecomp's ABI.

**Completed Steps:**
- 1.1: Set up XenonRecomp build system
- 1.2: Configure clang-cl with C++23
- 1.3: Set up CMake with Ninja
- 1.4: Configure LLD linker
- 1.5: Set up compile_commands.json for clangd
- 1.6: Configure third-party libraries
- 1.7: Set up build scripts (configure.bat, ninja_build.bat)
- 1.8: Full build clean

**Validator Gate:** Build succeeds with zero errors.

## 8.2 Phase 2: Kernel Framework ✅ COMPLETE

**Goal:** Rewrite kernel framework to match UnleashedRecomp exactly.

**Completed Steps:**
- 2.1: Guest Physical Heap — NOACCESS Guard ✅
- 2.2: PPCContext Struct Layout ✅
- 2.3: GUEST_FUNCTION_HOOK + HostToGuestFunction ✅
- 2.4: KernelObject Hierarchy + Wait Signature ✅
- 2.5: Identity Handles + QueryKernelObject Lazy-Wrap ✅
- 2.6: TLS/PCR Emulation — GuestThread::Start ✅
- 2.7: DELETE kernel_stubs.cpp, kernel_stubs_body.inc ✅
- 2.8: g_keSetEventGeneration Counter ✅

**Validator Gate:** phase0_validator 13/13 PASS

**Violations Fixed:**
1. Handle model: host-heap index → identity handles
2. Import signatures: manual ctx.rN → typed-arg one-liners
3. Competing implementations deleted
4. Critical section layout: 24-byte → 28-byte
5. NOACCESS guard completed
6. Vd imports completed
7. ObReferenceObjectByHandle verified
8. Generation counter implemented
9. GuestThread pattern implemented

## 8.3 Phase 3: Critical Imports ✅ PASSED (2026-08-22)

**Goal:** Implement critical kernel imports to achieve boot.

**Key Breakthrough:**
The game boots into its main loop and RUNS. VSync callback fires at 60fps continuously (frame 2928+ observed = ~48s stable execution), zero fatals, zero crashes.

**Root Cause Fixed:**
`NtQueryInformationFile` had a raw PPC_FUNC strong definition at the top of imports.cpp that returned fake SUCCESS with EMPTY buffers, shadowing everything. The packfile loader queries class 34 = FileNetworkOpenInformation (len 56) and gates on EndOfFile == real archive size; zeros meant "empty file" → "Cannot load archive".

**Fix:** Implement the query for real.

**Validator Gate:** Boot survives main loop, archives load, VSync 60fps.

## 8.4 Phase 4': Device-Boundary Takeover 🔄 IN PROGRESS

**Goal:** Override the game's device method function pointers.

**Steps Completed:**
- Step 1: Device creation hook ✅
- Step 2: FP-table redirect ✅

**Current Status (refreshed 2026-09-05, sessions 33-37):**
- CP drain chain is live; capture hooks (create-hook + packet capture v2) armed but idle
- Boot blocker: intermittent OOM fatal ~T+15s in the guest churn heap
  (heap struct `0x82830CD8`, 46.5MB fixed cap, ~4% used at fatal)
- Prime suspect: class allocator `sub_821DE9D8` returning 0 on an
  inconsistent slab header (see `docs/BOOT_HANDOFF.md` for the live trail)
- Session 37 done: enhanced slab census (full chain dump on return-0, no sampling)

**Next Steps:**
- Session 38: Run gate soak → analyze POOL-CENSUS FAIL# → root-cause slab corruption
- Step 3: Render thread & queues (P4.5')
- Step 4: Resource model (P4.6')

## 8.5 Phase 4.5': Render Thread & Queues ⏳ PENDING

**Goal:** Build dedicated render thread with blocking queues.

**Key Decisions:**
- Guest thread → queue → render thread
- Render thread processes commands asynchronously
- D3D12 commands submitted on render thread only

## 8.6 Phase 5': Real Draws via Device Boundary ⏳ PENDING

**Goal:** Capture actual draw calls and replay as D3D12.

**Key Requirements:**
- Capture all draw state (PSO, VB, IB, CB, textures)
- Replay captured state as D3D12 draw calls
- Handle vertex format conversion (Xenos → D3D12)

## 8.7 Phase 5.5': Offline Shader Cache ⏳ PENDING

**Goal:** Pre-compile all shaders at build time.

**Benefits:**
- Zero runtime compilation stalls
- Predictable performance
- Smaller runtime binary

## 8.8 Phase 6': Native Default & Legacy Retirement ⏳ PENDING

**Goal:** Make native renderer the default, retire legacy path.

**Key Changes:**
- Switch default renderer mode to `native`
- Remove PM4 parsing code
- Remove CP emulation code
- Legacy path becomes optional (compile flag)

## 8.9 Phase 7': Build Env Modernization ⏳ PENDING

**Goal:** Modernize build environment.

**Tasks:**
- Update to latest LLVM/Clang
- Update CMake to latest stable
- Update third-party libraries
- Add CI/CD pipeline

## 8.10 Phase 8': Codegen Config Completion ⏳ PENDING

**Goal:** Complete codegen configuration.

**Tasks:**
- Verify all 46K functions recompile correctly
- Fix any remaining ABI mismatches
- Optimize generated code

## 8.11 Phase 9': Kernel Surface Completion ⏳ PENDING

**Goal:** Complete kernel API surface.

**Tasks:**
- Implement remaining kernel imports
- Add missing XAM functions
- Complete network stack stubs

---

# 9. AGENT SYSTEM & WORKFLOW

## 9.1 Agent Catalog

The project uses 14 specialized AI agents:

### Primary Agents
| Agent | Role | Mode |
|-------|------|------|
| `gpu-engineer` | D3D12 implementation (DEFAULT) | default |
| `reverser` | PPC/recomp analysis | subagent |
| `architect` | System-level design | primary |
| `perf-engineer` | Performance optimization | primary |

### Subagents
| Agent | Role |
|-------|------|
| `shader-translator` | Xenos microcode → HLSL/DXIL |
| `debugger` | Crash triage, validation warnings |
| `code-reviewer` | Strict diff review (read-only) |
| `security-auditor` | Memory safety audit (read-only) |
| `build-specialist` | Build system health |
| `test-engineer` | Offline verification |
| `docs-writer` | Documentation |
| `research-scout` | External references (read-only) |
| `node-tooling` | Node.js/better-sqlite3 tooling |
| `memory-steward` | Architecture brainmap |

## 9.2 Agent Permissions

Each agent has specific tool permissions:

```json
{
  "gpu-engineer": {
    "bash": true,
    "edit": true,
    "ghidra": true,
    "renderdoc": true,
    "pix": true
  },
  "reverser": {
    "bash": true,
    "edit": true,
    "ghidra": true,
    "renderdoc": true,
    "pix": false
  },
  "security-auditor": {
    "bash": false,
    "edit": false,
    "read_only": true
  }
}
```

## 9.3 Skills

| Skill | Purpose |
|-------|---------|
| `debugging-wizard` | D3D12 validation error debugging |
| `mcla-phase-gate` | Phase discipline enforcement |
| `second-brain` | Durable project memory |
| `spec-miner` | Undocumented Xenos microcode RE |
| `the-fool` | Adversarial review / pre-mortem |
| `mcla-stall-forensics` | Stall diagnosis methodology |

## 9.4 MCP Servers

| Server | Purpose |
|--------|---------|
| Ghidra MCP | PPC reverse engineering |
| IDA Pro MCP | Hex-Rays decompilation |
| RenderDoc MCP | GPU capture analysis |
| PIX MCP | GPU debugging |

## 9.5 Development Loop

1. **Search Before Acting** — Always search (web, grep, glob, Ghidra, RenderDoc) before writing code
2. **List Strategies & Plan** — First-principles decomposition, hypothesis-driven verification
3. **Implement** — Write code following golden rules
4. **Verify** — Run validators, check for regressions
5. **Document** — Update handoff files, architecture docs

---

# 10. VALIDATION & TESTING INFRASTRUCTURE

## 10.1 Offline Validators

### phase0_validator
- **Purpose:** Kernel framework unit tests
- **Tests:** 13 tests covering identity handles, lazy-wrap, critical sections, generation counter, thread management
- **Gate:** 13/13 PASS required

### xenos_decode_validator
- **Purpose:** Raw Xenos microcode decode
- **Input:** Shader corpus (1,264 files)
- **Gate:** Exit 0 (clean decode), exit 1 = tracked finding

### shader_pipeline_validator
- **Purpose:** Shader parse + translate
- **Input:** Shader corpus
- **Gate:** Exit 0, 0 unknown opcodes

### phase3_validator
- **Purpose:** Vertex fetch + resource/texture decode
- **Input:** Shader corpus
- **Gate:** Exit 0

### texture_decode_test
- **Purpose:** Tiled/Xenos texture decode vs oracle
- **Gate:** All test cases pass

### capture_dump_validator
- **Purpose:** Cross-check DrawPacket stream vs guest memory
- **Gate:** Exit 0

### xtr_dump_validator
- **Purpose:** Standalone capture dumps
- **Gate:** Exit 0

### backend_validator
- **Purpose:** D3D12 device + PSO smoke test
- **Gate:** Device created, PSO compiled

## 10.2 Phase Gate Runner

The `tools/run_phase_gates.ps1` script runs all validators and checks:

```powershell
# Run all gates
.\tools\run_phase_gates.ps1

# Output: build\gates\YYYY-MM-DD-gate-report.json
```

### Enforced Gates
| Gate | Description |
|------|-------------|
| G-BUILD | CMake build succeeds |
| G-VALIDATORS | All 8 validators pass |
| G-CORPUS-XENOS-DECODE | ≥1000 files scanned |
| G-XENOS-DECODE-CLEAN | Decoder exit 0 |
| G-CORPUS-shader_pipeline | Exit 0 |
| G-CORPUS-phase3 | Exit 0 |
| G-PHASE0 | 13/13 passed |
| G-BOOT-SOAK | Process alive + zero fatals (60s) |
| G-VSYNC-CHAIN | ≥1 VSync thread start |
| G-P4-CREATE-HOOK | Device create hook fires |

### Regression Detection
Compares against previous JSON report; any enforced gate going green→red = REGRESSION.

## 10.3 Boot Soak Test

```powershell
# Launch mcla.exe, wait 60s, kill, analyze log
$mcla = Start-Process -FilePath "build\mcla.exe" -PassThru
Start-Sleep -Seconds 60
$mcla | Stop-Process -Force
# Analyze log for fatal patterns, vsync, ring, device, self-test
```

## 10.4 Test Commands

```bash
# Build
configure.bat
ninja_build.bat

# Run individual validators
build\phase0_validator.exe
build\shader_pipeline_validator.exe
build\xenos_decode_validator.exe
build\phase3_validator.exe
build\backend_validator.exe

# Run all gates
powershell -ExecutionPolicy Bypass -File tools\run_phase_gates.ps1

# Boot test
build\mcla.exe
```

---

# 11. TECHNICAL REFERENCE: RPF3 ARCHIVES

## 11.1 RPF Format Overview

RPF (Rockstar Pack File) is Rockstar's archive format:

| Version | Game |
|---------|------|
| RPF0 | Table Tennis |
| RPF2 | GTA IV |
| RPF3 | GTA IV Audio + ALL MCLA archives |
| RPF4 | Max Payne 3 |
| RPF6 | RDR |
| RPF7 | GTA V |
| RPF8 | RDR2 |

## 11.2 RPF3 File Layout

```
Offset    Size    Description
0x0000    2048    Header padding (zeros)
0x0800    12      RPF header
            4     Magic (0x52504633 = "RPF3")
            4     TOC size
            4     Entry count
0x1000    Variable Table of Contents (TOC)
After TOC Variable Filename section (null-terminated ASCII)
After Names  Variable File data (absolute offsets)
```

## 11.3 TOC Entry Format (16 bytes each)

### Directory Entry
```
Offset  Size  Field
0x00    1     Name offset (bits 0-6)
0x01    1     Name offset (bits 7-13)
0x02    1     Name offset (bits 14-20)
0x03    1     Type flags (0x80 = directory)
0x04    4     First child index
0x08    4     Entry count
0x0C    4     Entry count (duplicate)
```

### File Entry
```
Offset  Size  Field
0x00    1     Name offset (bits 0-6)
0x01    1     Name offset (bits 7-13)
0x02    1     Name offset (bits 14-20)
0x03    1     Type flags (0x00 = file)
0x04    4     Data offset (absolute from file start)
0x08    4     File size
0x0C    4     Uncompressed size
```

## 11.4 Compression

MCLA RPF3 archives use XMem LZX (Microsoft's proprietary LZX variant):

```c
// Decompression via xcompress32.dll
#include <xcompress.h>

DWORD uncompressed_size;
XMEMDECOMPRESS_CONTEXT context;
XMemCreateDecompress(&context, 0, NULL, 0);
XMemDecompress(&context, output, &output_size, input, input_size);
XMemDestroyDecompress(&context, 0);
```

## 11.5 Encryption

MCLA RPF3 archives may have AES-encrypted TOC blocks:

```c
// AES key is hardcoded in the game executable
// Located at known offset in default.xex
uint8_t aes_key[16] = { /* extracted from XEX */ };

// Decrypt TOC block
AES_KEY decrypt_key;
AES_set_decrypt_key(aes_key, 128, &decrypt_key);
AES_decrypt(toc_block, toc_decrypted, &decrypt_key);
```

## 11.6 Filename Hashing

Two custom hash algorithms:

### GtaO (Jenkins one-at-a-time, case-sensitive)
```c
uint32_t GtaO_Hash(const char* str) {
    uint32_t hash = 0;
    for (int i = 0; str[i]; i++) {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}
```

### GtaQ (Jenkins variant, case-insensitive)
```c
uint32_t GtaQ_Hash(const char* str) {
    uint32_t hash = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}
```

## 11.7 MCLA-Specific File Types

| Extension | Description |
|-----------|-------------|
| .wtd | Texture dictionary |
| .wdr | 3D model (drawable) |
| .wdd | Drawable dictionary |
| .wft | Fragment types |
| .wbd | Collision data |
| .wpl | World placement |
| .ide | Item definitions |
| .sco | Script objects |
| .dat | Data files |
| .gxt | Localized strings |

---

# 12. TECHNICAL REFERENCE: PPC RECOMPILATION

## 12.1 XenonRecomp Overview

XenonRecomp recompiles Xbox 360 PowerPC code to x86-64 C++:

```
default.xex → XenonRecomp → 179 TUs (ppc_recomp.0..178.cpp)
                          → 46,029 function mappings
                          → 19,887 unique functions
```

## 12.2 Recompilation Config (mcla_xenonrecomp.toml)

```toml
[main]
file_path = "game_data/default.xex"
out_directory_path = "generated/ppc_xenon"
switch_table_file_path = ".research/XenonRecomp/XenonAnalyse/jump_tables.toml"

# Address ranges
savegprlr_14_address = 0x823D91C0
restgprlr_14_address = 0x823D9210
savefpr_14_address = 0x823DB9A0
restfpr_14_address = 0x823DB9EC
savevmx_14_address = 0x823DD2C0
restvmx_14_address = 0x823DD558
savevmx_64_address = 0x823DD354
restvmx_64_address = 0x823DD5EC

# Register optimizations
ctr_as_local = true
xer_as_local = true
reserved_as_local = true
cr_as_local = true
non_argument_as_local = true
non_volatile_as_local = true
```

## 12.3 Generated Code Structure

### ppc_config.h
```cpp
#define PPC_IMAGE_BASE 0x82000000
#define PPC_CODE_BASE 0x82130000
#define PPC_CODE_SIZE 0x69D054  // ~6.8MB
```

### ppc_context.h (740 lines)
- Memory access macros route through `mcla::native::ReadGuestU32()`
- Function signature: `PPC_FUNC(x) = void x(PPCContext& ctx, uint8_t* base)`
- SIMDE helpers for PPC-specific SIMD operations

### ppc_func_mapping.cpp (46,029 lines)
```cpp
PPCFuncMapping PPCFuncMappings[] = {
    { 0x82130000, sub_82130000 },
    { 0x82130004, sub_82130004 },
    // ... 46,029 entries
    { 0x821322B8, _xstart },  // Entry point
};
```

## 12.4 PPCContext Register Layout

```
Offset  Size  Register
0x0000  256   GPR[0-31] (PPCRegister each)
0x0100  8     LR
0x0108  8     CTR
0x0110  8     Reserved
0x0118  8     XER
0x0120  8     MSR
0x0128  32    CR0-CR7 (PPCCRRegister each)
0x0148  8     FPSCR
0x0150  256   FPR[0-31] (PPCRegister each)
0x0250  2048  VPR[0-127] (PPCVRegister each)
```

## 12.5 Memory Access Patterns

### Checked Access (Default)
```cpp
// Routes through guest_memory.cpp with bounds checking
uint32_t PPC_LOAD_U32(uint32_t address) {
    return mcla::native::ReadGuestU32(address);
}
```

### MMIO Access
```cpp
// Routes through gpu_mmio.cpp for device registers
uint32_t PPC_MMIO_READ(uint32_t address) {
    return mcla::gpu::ReadMMIO(address);
}
```

---

# 13. DEBUGGING & TROUBLESHOOTING GUIDE

## 13.1 Common Issues

### Build Failures

**Issue:** `clang-cl: error: unknown argument`
**Solution:** Ensure vcvars64.bat is called before cmake. Use `configure.bat`.

**Issue:** `lld-link: error: undefined symbol`
**Solution:** Check CMakeLists.txt includes all source files. Check third-party library paths.

### Runtime Crashes

**Issue:** `VEH exception: code=0xC0000005` (Access Violation)
**Solution:** 
1. Check guest memory bounds
2. Verify address is in guest memory range
3. Check NOACCESS guard page is set up

**Issue:** `STATUS_ACCESS_VIOLATION` in kernel imports
**Solution:**
1. Verify identity handles are working
2. Check QueryKernelObject returns valid pointer
3. Verify guest memory access is checked

### Boot Issues

**Issue:** Game doesn't boot past kernel init
**Solution:**
1. Run phase0_validator to check kernel framework
2. Check import hooks are installed correctly
3. Verify guest memory is allocated

**Issue:** Archives fail to load
**Solution:**
1. Check NtQueryInformationFile returns correct file size
2. Verify RPF3 VFS is working
3. Check xcompress32.dll is present

### Rendering Issues

**Issue:** No visible output
**Solution:**
1. Check D3D12 device creation succeeds
2. Verify swap chain is created
3. Check render thread is running
4. Verify VSync callback is firing

**Issue:** Corrupted rendering
**Solution:**
1. Check vertex format conversion
2. Verify shader translation is correct
3. Check texture decode is working
4. Use RenderDoc to capture frames

## 13.2 Debug Tools

### D3D12 Debug Layer
```cpp
// Enable in config.json or opencode.json
{
    "gpu": {
        "d3d12_debug_layer": true
    }
}
```

### PIX Integration
```bash
# Start PIX capture
start_ghidra_mcp.bat

# Or configure in opencode.json
{
    "mcp_servers": {
        "pix": {
            "command": "pix_server.exe",
            "args": ["--port", "31337"]
        }
    }
}
```

### RenderDoc Integration
```json
{
    "mcp_servers": {
        "renderdoc": {
            "command": "renderdoc_server.exe",
            "args": ["--port", "31338"]
        }
    }
}
```

### Ghidra Integration
```json
{
    "mcp_servers": {
        "ghidra": {
            "command": "ghidra_mcp_server.exe",
            "args": ["--project", "E:\\mcla pc\\.research\\findings\\ghidra"]
        }
    }
}
```

## 13.3 Logging

### Boot Log
```cpp
// Boot logging is in src/boot_log.cpp
// Output to build/mcla_boot.log
```

### Kernel Log
```cpp
// Kernel logging via spdlog
#include <spdlog/spdlog.h>

spdlog::info("NtCreateEvent called with handle={}", handle);
spdlog::warn("Unknown import: 0x{:08X}", address);
spdlog::error("Critical section corruption at 0x{:08X}", address);
```

### Crash Log
```
// crash_log_early.txt format:
VEH exception: code=0xC0000005 addr=0x00007FF9B7261B78
  param[0] = 0x1
  param[1] = 0x0
RIP=0x7FF9B7261B78 RSP=0xC0E09FDE90
```

## 13.4 Performance Profiling

### Tracy Integration
```cpp
#include <tracy/Tracy.hpp>

ZoneScopedN("RenderFrame");
// ... render code
FrameMark;
```

### Build with Profiling
```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTRACY_ENABLE=ON
```

---

# 14. DEVELOPMENT WORKFLOW & RULES

## 14.1 Golden Rules

1. **Search Before Acting** — Always search (web, grep, glob, Ghidra, RenderDoc) before writing code
2. **List Strategies & Plan** — First-principles decomposition, hypothesis-driven verification
3. **One Hook Owner Per Guest Address** — No conflicting hooks
4. **Hooks Only Capture State** — No D3D12 calls in hooks
5. **Guest Pointers Are 32-bit** — Never raw host pointers
6. **Endianness Is Explicit** — ReadU16BE, ReadU32BE, etc.
7. **No Invented Draw Data** — Only capture what the game provides
8. **Keep Generated Code unchanged** — Never modify ppc_recomp.*.cpp

## 14.2 Coding Standards

- **Language:** C++23
- **Compiler:** clang-cl
- **Exceptions:** Disabled (`/EHsc`)
- **RTTI:** Disabled (`/GR-`)
- **Logging:** spdlog + fmt
- **Formatting:** clang-format (LLVM style)
- **Memory:** Checked guest memory access
- **Headers:** Include what you use

## 14.3 Hook Development

### Step 1: Identify Guest Function
Use Ghidra to decompile the target function:
```
ghidra_get_function(address=0x82XXXXXX)
ghidra_get_instructions(address=0x82XXXXXX)
```

### Step 2: Understand Parameters
```cpp
// Check Xenia or reverse-engineer manually
// Xbox 360 calling convention: r3-r10 for first 8 params
GUEST_FUNCTION_HOOK(sub_82XXXXXX, uint32_t param1, uint32_t param2) {
    // param1 = ctx.r3, param2 = ctx.r4
}
```

### Step 3: Implement Hook
```cpp
GUEST_FUNCTION_HOOK(sub_82XXXXXX, uint32_t handle, uint32_t info_class) {
    // Capture state
    g_captured_handle = handle;
    g_captured_info_class = info_class;
    
    // Call original (if needed)
    // Note: Original runs as recompiled PPC code
}
```

### Step 4: Validate
```bash
# Build
ninja_build.bat

# Run boot test
build\mcla.exe

# Check logs for hook firing
grep "sub_82XXXXXX" build/mcla.log
```

## 14.4 Shader Translation Workflow

### Step 1: Extract Microcode
```bash
# Use XenosRecomp to extract shader microcode
# Output: .shader files in .research/findings/xenia/shader_dumps/
```

### Step 2: Translate to HLSL
```bash
# Run shader_pipeline_validator
build\shader_pipeline_validator.exe
# Output: HLSL files in build/shader_ir/
```

### Step 3: Compile to DXIL
```bash
# DXC compiles HLSL to DXIL
dxc.exe -T vs_5_0 -E main shader.hlsl -Fo shader.dxil
```

### Step 4: Validate
```bash
# Run phase3_validator
build\phase3_validator.exe
```

## 14.5 Documentation

### Handoff Files
After each session, update handoff files:
```
docs/handoffs/YYYY-MM-DD-*.md
```

### Architecture Updates
Keep architecture.md current:
```
docs/ARCHITECTURE.md
```

### Durable Memory Ledger
Append session evidence (schema per `.clinerules/skills/second-brain.md`):
```
.clinerules/memory/memories-*.md
```

### Phase Plan Updates
Update MCLA_REBUILD_PLAN.md with progress:
```
docs/MCLA_REBUILD_PLAN.md
```

---

# 15. APPENDICES

## Appendix A: File Inventory

### Source Files (51 files)
| File | Lines | Purpose |
|------|-------|---------|
| src/main.cpp | ~200 | Entry point |
| src/app.cpp | ~500 | Application loop |
| src/early_init.cpp | ~100 | Early init |
| src/patches.cpp | ~1000 | Function patches |
| src/gpu_mmio.cpp | ~800 | MMIO traps |
| src/gpu_cp.cpp | ~600 | Command processor |
| src/gpu_device.cpp | ~400 | Device management |
| src/native_renderer.cpp | ~1200 | Native renderer |
| src/renderer_mode.cpp | ~200 | Mode switching |
| src/renderer_hook_dispatch.cpp | ~300 | Hook dispatch |
| src/capture_hooks.cpp | ~500 | Capture hooks |
| src/guest_memory.cpp | ~600 | Guest memory |
| src/guest_mem_scan.cpp | ~200 | Memory scanning |
| src/vfs_rpf.cpp | ~800 | RPF3 VFS |
| src/d3d12_backend.cpp | ~1500 | D3D12 backend |
| src/render_command_queue.cpp | ~300 | Command queue |
| src/render_thread.cpp | ~400 | Render thread |
| src/boot_host.cpp | ~500 | Boot host |
| src/boot_log.cpp | ~200 | Boot logging |
| src/kernel/memory.cpp | ~400 | Memory mgmt |
| src/kernel/heap.cpp | ~300 | Heap allocator |
| src/kernel/o1heap.c | ~200 | O(1) heap |
| src/kernel/xdm.cpp | ~300 | Xbox Device Mgr |
| src/kernel/guest_thread.cpp | ~400 | Guest threads |
| src/kernel/imports.cpp | ~2000 | Kernel imports |
| src/kernel/xam.cpp | ~500 | XAM |
| src/renderer/xenos_microcode.cpp | ~1000 | Xenos decoder |
| src/renderer/xenos_shader_ir.cpp | ~800 | Shader IR |
| src/renderer/shader_translator.cpp | ~1200 | HLSL translation |
| src/renderer/dxc_runtime.cpp | ~300 | DXC runtime |
| src/renderer/pipeline_cache.cpp | ~400 | PSO cache |
| src/renderer/vertex_decode.cpp | ~500 | Vertex decode |
| src/renderer/grc_fvf_decode.cpp | ~300 | FVF decode |
| src/renderer/rage_asset_pipeline.cpp | ~400 | RAGE assets |
| src/renderer/resource_cache.cpp | ~300 | Resource cache |
| src/renderer/texture_decode.cpp | ~600 | Texture decode |

### Generated Files (183 files)
- `generated/ppc_xenon/ppc_recomp.0..178.cpp` (179 TUs)
- `generated/ppc_xenon/ppc_func_mapping.cpp` (46,029 lines)
- `generated/ppc_xenon/ppc_config.h`
- `generated/ppc_xenon/ppc_context.h` (740 lines)
- `generated/ppc_xenon/ppc_recomp_shared.h` (1654+ lines)

### Documentation Files (10+ files)
- `README.md`
- `docs/AGENTS.md`
- `docs/BOOT_HANDOFF.md`
- `docs/MCLA_REBUILD_PLAN.md` (1090+ lines)
- `docs/PHASE2_IMPLEMENTATION_PLAN.md` (335 lines)
- `docs/ARCHITECTURE.md`
- `docs/MCLA_RPF3_Technical_Reference.txt` (591 lines)
- `docs/handoffs/*.md` (6 files)
- `.clinerules/memory/memories-*.md` (durable ledger, canonical)

## Appendix B: Config Files

### opencode.json
- 10 plugins
- 14 agents
- 4 MCP servers (Ghidra, IDA, RenderDoc, PIX)
- 3 LSP servers (clangd, pyright, pylsp)
- Compaction disabled (mandatory context discipline)

### mcla_manifest.toml
- Game: Midnight Club: Los Angeles
- Title ID: 0x41560817
- Region: NTSC-U
- Renderer mode: legacy (default)
- D3D12 debug layer: true

### config.json
- Alternative OpenCode configuration
- Same 14 agents with detailed prompts
- DaVinci Resolve MCP (disabled)

## Appendix C: Build Outputs

### build/ Directory
- `mcla.exe` - Main executable
- `mcla.pdb` - Debug symbols
- 8 validator executables
- 35+ log files
- Gate reports (JSON)
- compile_commands.json

### third_party/
- SDL3 v3.2.6
- fmt v10.2.1
- spdlog v1.14.1
- toml++
- xxHash
- O1Heap
- DXC headers

## Appendix D: Research Directory

### .research/
- `360tools/` - Xbox 360 extraction tools
- `findings/ghidra/` - 19,887 functions decompiled
- `findings/xenia/` - Kernel logs, shader corpus
- `findings/renderdoc/` - PIX captures, screenshots
- `UnleashedRecomp/` - Reference SEGA project
- `XenonRecomp/` - PPC recompiler
- `XenosRecomp/` - Xenos GPU recompiler

## Appendix E: Skill Files

| Skill | Location | Lines |
|-------|----------|-------|
| debugging-wizard | `.clinerules/skills/debugging-wizard.md` | 35 |
| mcla-phase-gate | `.clinerules/skills/mcla-phase-gate.md` | 44 |
| second-brain | `.clinerules/skills/second-brain.md` | 50 |
| spec-miner | `.clinerules/skills/spec-miner.md` | 39 |
| the-fool | `.clinerules/skills/the-fool.md` | 54 |
| mcla-stall-forensics | `.clinerules/skills/mcla-stall-forensics/` | 60 |

## Appendix F: Handoff Files

| File | Date | Key Topics |
|------|------|------------|
| 2026-08-22-phase3-gate.md | 2026-08-22 | Phase 3 gate passed, VSync 60fps |
| 2026-08-22-session2-blockers.md | 2026-08-22 | Event/Semaphore wait fix |
| 2026-08-22-session3-device-boundary.md | 2026-08-22 | Device boundary captured |
| 2026-08-22-ur-vs-mcla-full-diff.md | 2026-08-22 | UR vs MCLA comparison |
| 2026-08-23-session4-packet-capture.md | 2026-08-23 | Packet capture, shader corpus |
| 2026-08-24-blocker-trace-investigation.md | 2026-08-24 | Stall diagnosis, RAGE recon |

---

# QUICK REFERENCE CARD

## Build Commands
```batch
configure.bat              # Configure CMake
ninja_build.bat            # Build mcla.exe
build\phase0_validator.exe # Run kernel tests
tools\run_phase_gates.ps1  # Run all gates
```

## Key Addresses
```
PPC_IMAGE_BASE:    0x82000000
PPC_CODE_BASE:     0x82130000
Entry Point:       0x821322B8 (_xstart)
Code Size:         0x69D054 (~6.8MB)
Mapped Functions:  46,029
Unique Functions:  19,887
```

## Key Files
```
src/kernel/imports.cpp    # All kernel hooks
src/gpu_device.cpp        # Device boundary
src/native_renderer.cpp   # D3D12 renderer
src/vfs_rpf.cpp           # RPF3 VFS
MCLA_REBUILD_PLAN.md      # Master plan
AGENTS.md                 # Agent rules
```

## Current Phase
- **Phase 3:** PASSED (2026-08-22)
- **Phase 4':** IN PROGRESS (Steps 1-2 done; hooks armed, idle pending boot blocker)
- **Blocker:** intermittent OOM fatal in guest churn heap (see docs/BOOT_HANDOFF.md)
- **Next:** Session 38 — run gate soak → analyze POOL-CENSUS FAIL# → root-cause slab corruption → render thread (P4.5')

---

*Document generated by MCLA-PC comprehensive analysis*  
*Total estimated pages: 120+*  
*Last updated: 2026-09-03 (doc resync: statuses, blocker, paths, validator counts)*
