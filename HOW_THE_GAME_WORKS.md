# How MCLA Native PC Works — Senior Engineer's End-to-End Guide

*Scope: the current codebase (Phases 0–9 partial, `renderer_mode` default
`legacy`). Where a component is a placeholder or not yet wired, the guide says
so explicitly. External research is cited where it informs the design
(XenonRecomp/XenosRecomp/Xenia, Xenos hardware, RAGE engine, D3D12 production
practice).*

Companion docs: `NATIVE_GPU_REBUILD_PLAN.md` (renderer phases),
`BOOT_REBUILD_PLAN.md` (boot reachability), `MCLA_GPU_CONTEXT_STRUCT.md`
(guest state layout), `MCLA_GPU_REVERSE_ENGINEERING.md` (hook forensics).

---

## 1. Executive summary — what this project actually is

Midnight Club: LA runs on the Xbox 360 as PowerPC guest code talking to the
Xenos GPU through a Direct3D 9-style driver *inside the game executable*. On
PC we do **not** emulate that GPU. We do three things:

1. **Recompile the CPU.** XenonRecomp statically translates the entire PPC
   code image to C++ (`generated/`), which we compile into a Windows exe.
2. **Fake the kernel.** Host-side stubs answer the ~246 kernel/Xam imports the
   game makes, so the guest logic can actually run.
3. **Re-express rendering intent natively.** At the high-level draw boundary we
   intercept the game's draw submission, snapshot every draw into a
   self-contained `DrawPacket`, and replay it as D3D12 work — real buffers,
   real pipelines, real shaders compiled from the game's Xenos microcode.

The name of the game is **fidelity at the draw boundary, not fidelity to
hardware**. We don't need to reproduce the Xenos command processor, the 10 MB
EDRAM, or its MSAA resolve semantics — because the game's *output* is what
matters, and modern GPUs can express the same intent far more cheaply. This is
exactly the philosophy that made Unleashed Recompiled feasible, and it's the
single most important design decision in this project.

> **Why "intent" and not "PM4"?** Emulating the command stream means re-deriving
> GPU state from raw register writes, handling every hardware quirk (EDRAM
> tiling, Hi-Z, predication), and paying emulation overhead on the frame path.
> Capturing the *high-level* intent (index buffer, vertex declaration, shader,
> constants, targets) lets the native renderer do what a modern engine does:
> upload, bind, draw. Xenia's own `PM4_XE_SWAP` special-case shows even the
> emulator thinks in these terms.

---

## 2. The guest machine — what the recompiler had to translate

### 2.1 The Xenon CPU

Three cores, two threads each, 3.2 GHz, PPC64 (book-E-ish, but really a
special Xenon variant), with:

- 32 GPRs (`r0..r31`), 32 FPRs (`f0..f31`), 32×128-bit VMX/Altivec registers
  (`v0..v127` at the architecture level), and the special registers `lr`,
  `ctr`, `xer`, `cr`, `fpscr`, `msr`.
- In-order issue, no out-of-order execution — which is why the guest code is
  full of explicit scheduling by the compiler.
- Big-endian memory, but **little-endian register data**. The recompiler lives
  in the gap between those two facts.

### 2.2 What XenonRecomp emits

For every function in the XEX, XenonRecomp emits a C++ function whose signature
is fixed by the runtime ABI:

```cpp
void sub_82420BA8(PPCContext& __restrict ctx, uint8_t* base);
```

- `ctx` holds all CPU state (`r[32]`, `f[32]`, `vsr[64]`, `lr`, `ctr`, `xer`,
  `cr`, `pc`, `fpscr`).
- `base` is the guest memory base. **Guest pointer `g` maps to host address
  `base + g`** — generated code dereferences guest addresses directly. No
  bounds checks, by design (the guest is trusted; the host-side capture path is
  where bounds enforcement lives).
- A function table `PPCFuncMapping PPCFuncMappings[] = { {addr, &fn}, ... }`
  with a null sentinel maps every guest address to its host function.

The recompiler's output is deliberately not human-readable decompilation; it
is a *faithful instruction-by-instruction translation*. The docs for
XenonRecomp state this plainly: "Making the game work is your responsibility."
It does **not** provide a runtime — no kernel, no GPU, no CRT beyond what the
generated code needs.

### 2.3 Three hard translation problems

**Endianness.** The instructions operate on little-endian values (host
native). Memory loads must therefore swap BE→LE, stores LE→BE. Every load/store
is marked `volatile` in the generated code to stop Clang reordering them
around each other (the guest depends on exact memory ordering). Host code that
reads guest data must do the same swapping explicitly — that's why the project
rule is "no `reinterpret_cast` on guest data", and why `GuestMemoryView` has
`ReadU16BE`/`ReadU32BE`/`ReadF32BE`.

**Vector register endianness.** VMX registers are 128-bit. The recompiler
doesn't swap the 4 lanes; it **reverses the whole 16-byte vector**. Then every
VMX instruction must account for that reversed order: dot products use `WZYX`
instead of `XYZW`, pack instructions take reversed arguments, etc. This is a
constant source of subtle bugs in any recomp — and it's why the existing
vertex/texture decode code is so careful about lane order.

**FPU vs VMX denormal handling.** The scalar FPU keeps denormals unmodified;
VMX always flushes them. The recompiler toggles the host FPU's denormal-flush
mode before executing each instruction, storing the current FP state in
`ctx.fpscr`. The smoke host seeds `ctx.fpscr.csr` from the real host MXCSR at
boot precisely because a zero-initialized cache would unmask host FPU
exceptions (`0xC000008F STATUS_FLOAT_MULTIPLE_FAULTS`) the first time guest
float-heavy code ran.

### 2.4 The dispatch table ("perfect hash")

Indirect calls (`PPC_CALL_INDIRECT_FUNC`) resolve through a table the runtime
builds at boot. In this project it's the **flat `PPC_LOOKUP_FUNC` macro**:

```cpp
PPC_LOOKUP_FUNC(base, addr) = *(PPCFunc**)(base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
                                         + (addr - PPC_CODE_BASE) * 2);
// IMAGE_BASE 0x82000000, IMAGE_SIZE 0x9E0000, CODE_BASE 0x82130000
```

46,041 mappings are installed by the smoke host at boot. The table lives *in*
guest address space (right after the image), so the generated code's indirect
calls are just dereferences — no hash, no indirection cost.

### 2.5 Hooks and ABI assumptions

The generated functions follow the guest ABI (r3..r10 are arguments/volatile,
r1 stack pointer, r13 thread pointer, etc.). The recompiler lets you **alias a
guest function to a custom implementation** and mark the original weakly
linked — that's the mechanism the project's hook system exploits. It also
supports **mid-asm hooks** inserted at specific instruction addresses.

> **Why the "generated code is input, never patched" rule matters.** The whole
> point of recompilation is that the guest code is a *black box we run*, not
> source we edit. If we patch `generated/`, we can't regenerate cleanly, we
> create divergent copies, and we lose the guarantee that the translated code
> matches the real game. Every fix goes in the *host* layer: a hook, a stub
> return value, a memory setup. The one exception is XenonRecomp itself (the
> tool), which we'd modify only for codegen bugs.

---

## 3. Boot — the smoke host (`tools/xenon_smoke/`)

The smoke host is the cheapest possible way to prove the recompiled guest
actually runs. No GPU, no window, no D3D12 — just guest code + kernel stubs +
SEH fault capture, on a worker thread under a watchdog.

### 3.1 Guest memory layout

```text
host: VirtualAlloc 4 GiB at 0x100000000, 32-byte aligned (recomp needs base % 32 == 0)

guest 0x00000000 ┐
                 │ unified arena; guest addr g → host base+g
guest 0x40000000 │ default game heap   (real NtAllocateVirtualMemory stubs)
guest 0x82000000 ├─ XEX image (default.xex), entry _xstart 0x821322B8
guest 0x829E0000 │   image end (IMAGE_BASE+IMAGE_SIZE)
guest 0x8F000000 │ smoke stack 2 MiB, grows down  (r1 init = 0x8F000000)
guest 0x8F200000 │ r13 thread block (TEB + XTL import chain)
                 └
```

The image is decompressed by `Xex2LoadImage` and memcpy'd to `base + image.base`
(`0x82000000`). The stack and thread block are carved out of regions clear of
the image. Everything below `0x82000000` is heap space for the guest allocator.

### 3.2 Kernel import stubs — the real boot work

The game imports ~246 kernel functions. Each import slot in the XEX points at a
first-thunk address; the smoke host patches those slots to host stub functions
(`kernel_stubs_body.inc`) that log the call and return. **The return values are
the load-bearing part.** A stub that returns garbage `r3` makes guest branches
misfire — that's how boot gets driven into the "dirty disc" error handler
(`sub_82130678 → sub_82131C58 → sub_821324A0 → XamLoaderLaunchTitle`).

Three stubs are implemented for real rather than stubbed:

- `NtAllocateVirtualMemory` — guest-VA allocator carving
  `[0x40000000, 0x7EFFFFFF]` (Xenia's 64 KB-page range). The guest ABI differs
  from Windows: no process handle, `r3=&base` in/out, `r4=&size` in/out,
  `r5=alloc_type` (`0x60001000` COMMIT / `0x60002000` RESERVE),
  `r6=protect`, returns NTSTATUS in `r3`.
- `NtQueryVirtualMemory` — fills the 28-byte big-endian `X_MEMORY_BASIC_INFORMATION`.
- `NtFreeVirtualMemory`.

Without these, the game's boot-time heap creation (`sub_821342B8`) could never
produce a region, and the buffer-pool allocator walked a free-list head of 0
and faulted at guest `0xFFFFFFFF`.

### 3.3 The r13 thread block and XTL dispatch

The guest's XTL allocation thunks (`sub_82130528/550/588`) resolve through the
thread register `r13`:

```text
r13 → [0] table base P → [+28] descriptor E → [0] func block F
   → F[+8]  = alloc fn guest address
   → F[+12] = free  fn guest address
```

The smoke host builds this chain in guest memory and registers `__xtl_alloc` /
`__xtl_free` in the function table so the indirect calls resolve. The same
thread block also serves other `r13` consumers the game uses: `+0x100` TEB
pointer (last-error at TEB+0x160), `+0x10C` CPU number, `+0x150` "doesn't want
errors" flag — mirroring UnleashedRecomp's `guest_thread.cpp` layout.

### 3.4 The proven boot chain

```text
_xstart 0x821322B8
 → sub_82132740 → sub_827A7688 → sub_82131228 → sub_821C2E60   (large init)
 → sub_821BD618   (import slot dispatcher; reads slot @0x8285FEA0)
 → PPC_LOOKUP_FUNC(target) → callee → … → VdSwap (boot finish, not reached)
```

Pre-boot the host seeds static slots the guest reads: `0x8285FEA0` (a dispatch
slot) → landing `0x82130678`, and global table pointer `0x8288E5AC` → scratch
table `0x8F207000`. Without these two, boot faults immediately (`READ @0x0` at
the slot dispatch, or a load from a NULL table pointer).

**Current status:** boot advances through heap creation, `NtCreateFile` data
opens, Xam/net init, thread creation, and Vd ring-buffer init, then **spins in
the GPU command-processor fence wait** `sub_82412F98` (`[cpobj+10941] & 2`).
That spin is the game waiting for hardware that doesn't exist in the smoke host
— and it's *exactly* the sync path the native plan replaces. Reaching it is a
success milestone; the next milestone is reaching `VdSwap`.

### 3.5 Fault triage methodology

Boot runs under `__try/__except`. On fault, `FilterCapture` records:

- host RIP + a 24-frame host backtrace (`RtlCaptureStackBackTrace`), resolved
  to guest functions via `g_hostToGuest` (built from the function table),
- guest regs the context exposes (`r1`, `r3..r10`, `r13`, `lr`) — the rest are
  *compile-time locals* in the generated functions and can't be read back,
- the dispatch-table entry for the faulting slot, to distinguish "NULL table
  entry" (fault in the dispatcher) from "non-NULL entry" (fault inside the
  callee),
- guest saved-LR / backchain / caller-LR walks, and raw fault bytes.

> **Warning — ICF attribution is unreliable.** Identical-code folding merges
> host functions, so the unwind table can attribute the faulting RIP to the
> wrong guest function. Resolve ambiguity by guest LR + instruction bytes, not
> by trusting the unwind map to the byte. The BOOT_REBUILD_PLAN investigation
> record is where this evidence lives.

### 3.6 Why not just run the whole game in the smoke host?

Reachability first. The smoke host's non-goals are explicit: no kernel
emulation beyond what boot needs, no GPU, no rendering. It exists to prove the
*chain* works so that when `mcla.exe` boots the same path it's a known-quantity
port. This keeps the D3D12/live-capture pipeline decoupled from boot debugging.

---

## 4. The game host (`mcla.exe`)

### 4.1 App lifecycle

```text
main → mcla::App("MCLA Native")
App::Initialize
  InitSDL → InitPaths → CreateWindow (SDL3, HWND pulled from SDL props)
  → InitD3D12 (only in native mode; otherwise lazy)
  → CVarSystem::LoadConfig(mcla.toml)      // renderer_mode, patch groups, paths
  → mcla_ApplyPatches(dispatcher)          // installs all guest hooks
  → VFS Initialize + Mount                 // RPF city art
App::Run → MainLoop(events → frame callback → 1 ms sleep)
```

### 4.2 FunctionDispatcher — the hook registry

A `std::unordered_map<guestAddr, PPCFunc>` plus thunk allocation. This is the
**single ownership point for hooks** (Golden Rule 1): a guest address is
hooked at most once, and installers must check `GetFunction` before
`SetFunction`. `patches.cpp` and `native_renderer.cpp` both go through it, so
hook ownership is auditable.

### 4.3 renderer_mode CVar

```text
legacy   (default) — Xenos/PM4 path runs untouched; game renders via emulated GPU
capture           — legacy path + DrawPacket capture to .mclatrace (+ trace mode)
native            — hooks active; D3D12 backend initialized eagerly
```

`native` today is a **working vertical slice only**: it renders a fixed
host-side test triangle through the full D3D12 path. It is not claimed as real
game rendering until Phase 4/5 gates pass. This is deliberate: it proves every
layer (device, upload, PSO, index buffer, viewport, draw, present) works before
real guest data enters the pipe.

### 4.4 Hook inventory (single owner each)

| Guest addr   | Name                    | Role |
|--------------|-------------------------|------|
| `0x8241BD08` | `GfxCmdBufSubmit`       | command-buffer submission; submit observers fire here (`NotifyGpuSubmit`) |
| `0x82420BA8` | draw builder            | per-draw capture point |
| `0x8241ABB8` | state setup             | state snapshot point |
| `0x827BD6E4` | `VdSwap`                | frame boundary; swap/present |

Install is gated by `renderer_mode != compat` and `BisectGroupEnabled("native")`.
`GfxCmdBufSubmit` is registered through `renderer_hook_dispatch`
(`AddBeforeSubmitObserver`) so multiple observers can subscribe without
multiple hook owners — the composable-dispatcher pattern from the golden rules.

---

## 5. The Xenos GPU — the thing we replace

To capture intent correctly, you must understand the hardware the game was
written against. This section is background; it's what the *legacy* path
emulates and what the native path must faithfully abstract.

### 5.1 Command processing (PM4)

The Xenos is a ATI R5xx-family GPU. Games submit work through a **ring buffer
in system memory** filled with **PM4 packets** (the ATI command format). A
`CP` (command processor) reads packets from the ring; the game writes the
write-pointer register (`CP_RB_WPTR`) to kick it.

Packet types (from Xenia's `packet_disassembler.cc`):

- **Type-0 (`PM4_TYPE0`)** — write N consecutive dwords to N consecutive
  registers starting at `base_index`.
- **Type-3 (`PM4_TYPE3`)** — opcode-driven commands. The ones that matter:
  - `PM4_DRAW_INDX` / `PM4_DRAW_INDX_2` — indexed / auto-index draws. `dword1`
    packs `index_count` (high 16), `prim_type` (low 6 bits), `src_sel`
    (`0`=indexed, `2`=auto), `index_32bit` flag. Indexed draws carry a guest
    address + size (with endianness in the top 2 bits of the size word).
  - `PM4_SET_CONSTANT` — writes a run of shader constants to the register file.
    The first dword selects the sub-block: ALU constants at `+0x4000`, FETCH
    (vertex/texture) at `+0x4800`, BOOL at `+0x4900`, LOOP at `+0x4908`,
    REGISTERS at `+0x2000`.
  - `PM4_LOAD_ALU_CONSTANT` — loads constants *from guest memory*.
  - `PM4_IM_LOAD` / `PM4_IM_LOAD_IMMEDIATE` — uploads shader microcode (guest
    memory or inline).
  - `PM4_INDIRECT_BUFFER` — branch to a second command buffer (the game's
    "secondary" buffers).
  - `PM4_WAIT_REG_MEM`, `PM4_REG_RMW`, `PM4_COND_WRITE`, `PM4_EVENT_WRITE_EXT`
    — sync/conditional ops.
  - `PM4_XE_SWAP` — **Xenia-specific**: `VdSwap` posts this instead of a real
    swap, telling the host to present. The native project's equivalent is the
    `VdSwap` hook at `0x827BD6E4`.

The project's `.xtr` trace walker (`xtr_dump_validator`) parses exactly these
packets from a real 14.7 MB capture — the concrete proof the command stream is
understood to the byte (primary/indirect/secondary/scaler buffers parse to EOF
with no desync).

### 5.2 The register file

Xenia models a `RegisterFile` of 0x5003 32-bit values. The capture path in this
project doesn't model all of them — it models the subset in `MclaGpuContext`
that the draw boundary needs (`flagsBitmask`, `cmdEntries`, `rbSurfaceInfo`,
`sqVsConst/sqPsConst/sqVsProgram/sqPsProgram`, `pa*` rasterizer regs,
`rsaMirror`, `drawVertexCount`). Each offset is `static_assert`-checked.

### 5.3 EDRAM — the 10 MB framebuffer

The 360's render targets live in **on-chip eDRAM**, not main RAM:

- 2048 tiles of **80×16 32bpp MSAA samples**. 1×MSAA = 80×16 pixels/tile,
  2× = 80×8, 4× = 40×8.
- Render targets are **addressed in tiles** (base + pitch in tiles), pitch
  rounded to tile width (a 256-wide 1× surface stores as 320).
- 1280×720 1× fits; 1280×720 2× needs 2 tiles-worth; 1080p 4× needs 4 — hence
  **tiled rendering**: draw region A, **resolve** (copy+MSAA-average) to main
  RAM, draw region B, etc. The game manages this explicitly.
- Depth buffers are stored with **even/odd 40-sample column halves swapped**
  relative to color — games even write depth *through* color targets when
  re-uploading evicted depth.
- EDRAM addressing is **circular** (tile 2048 wraps to 0) — games rely on it.

**What this means for a native renderer:** the game's draw boundary includes
*resolve* draws (EDRAM→texture copies) that have no meaning on a desktop GPU.
The native path must recognize these as *copy/resolve operations* and translate
them to `CopyResource`/`ResolveSubresource`, not to a shader draw. This is a
known work item the capture layer must distinguish. (See also Phase 4 texture
path in the backend.)

### 5.4 Texture tiling

Main-RAM textures use a **32×32-texel (or 32×32-block for compressed) tiling**
layout with a micro-address XOR function. Pitch is aligned to 32 blocks, and
textures of size 33×33, 63×33, 64×33, 64×64 all occupy the same tiled space
(padding is implicit). The tiled address XORs X/Y/Z bits into the byte address;
the exact function depends on bytes-per-block (1bpb→8 blocks/row, 2→8, 4→4,
8→2, 16→1), with per-BPB group sizes and macro-tile XORs that the 
`texture_decode` module in this project implements (oracle-validated).

Untiling is required for every texture upload to D3D12, whether it came from
game assets or from an EDRAM resolve. D3D12-native renderers typically until
on CPU for static textures and on GPU (compute) for dynamic/render-to-texture.
Xenia does it on GPU for everything since the console stores *all* textures
tiled; this project's current path is CPU untiling in `texture_decode`.

### 5.5 Shader model

Xenos shaders are **Xenos microcode** — ATI R5xx-style SQ instructions, packed
in triples of 32-bit words. There are CF (control-flow) instructions
(ADDR/CNT pairs, jump/label/loop), ALU instructions (vector+scalar fused),
FETCH instructions (`tfetch`, `vfetch`), and EXP (export) instructions that
write color/depth. Register banks: `r#` temporaries, `c#` constants, `aL`/
`a0` addressing. Constant spaces: VS 256×float4 (4096 B), PS 224×float4
(3584 B), plus fetch constants (vertex/texture descriptors).

This is the XenosRecomp/Xenia problem space in miniature, and the reason
shader translation (§8) is its own sub-pipeline with offline corpus gates.

---

## 6. Capture — from guest state to a DrawPacket

### 6.1 The boundary

At `0x82420BA8` (draw builder), the game has decided what it's drawing: which
vertex streams, which index buffer, which shaders, which targets. The capture
hook snapshots all of it *before* the game submits PM4, so the native path
never needs to reverse-engineer raw register writes. This is the "high-level
draw boundary" the project is built on.

### 6.2 DrawPacket — the snapshot

`src/native_types.h` defines a **POD, trivially-copyable** `DrawPacket` (trace
version 2). Everything the native path needs to re-express one draw:

```text
identity:      frameIndex, sequenceNum, drawInFrame, cpuTimestamp
draw intent:   primType, indexType, startIndex, indexCount, baseVertex, drawFlags
targets:       colorTargets[4] (surface-info descs), depthTarget
viewport/scissor: TL/BR pairs (guest packed)
rasterizer:    paClipCntl, paSuScModeCntl, paClVteCntl
shaders:       sqVsProgram, sqVsConst, sqPsProgram, sqPsConst (guest addrs)
vertex input:  vertexStreamCount, vertexStreams[16] {guestAddress,stride,offset,format}
index:         indexBufferAddress, indexBufferSize
textures:      textureCount, textureDescriptors[16]
integrity:     stateHash, isValid, validationFlags
RAGE decl:     GrcFvfDesc grcFvf (fvfMask, fvfSize, flags, dynamicOrder,
               channelCount, types) + hasGrcFvf
```

The `GrcFvfDesc` is the RAGE drawable's vertex declaration: a 16-bit lane mask
(which semantics are bound) + 16×4-bit type codes + declared stride. The
capture site must **big-endian convert before storing** (`ReadU32BE`/`ReadU64BE`),
so the struct holds plain host-endian values.

### 6.3 The checked memory view

All guest reads go through `GuestMemoryView`:

```cpp
bool IsValidRange(guestAddr, size);         // bounds against the 4 GiB arena
bool ReadU8/U16BE/U32BE/U64BE/F32BE(...);   // explicit endianness
bool ReadBytes(guestAddr, dst, size);       // the general form
```

The packet never retains guest pointers — it stores **addresses + sizes**, and
the host re-reads data via the view when it needs the actual bytes. This is the
"GuestPtr/address+bounds, never raw host pointers" golden rule in action, and
it's why guest data changes (streaming, dynamic VB) are visible on replay.

### 6.4 Serialization and evidence dumps

- `FrameTraceWriter` serializes packets to `.mclatrace` (magic `'MCLA'`, v2).
- Guest VB/IB bytes are dumped to `<trace>/guestmem/vb_<addr>_<size>.bin` /
  `ib_<addr>_<size>.bin`, deduplicated by `(address, size)`.

Those dumps are the **evidence corpus** that Phase 3/4 format recovery is
validated against. The corpus proves every VFETCH is `vf=0`,
fetch-constant-relative via `const[31]` — so format+stride must be recovered
from guest fetch-constant descriptors, not assumed. `capture_dump_validator`
cross-checks a trace against its dumps (header/packet integrity, per-stream
coverage vs `stride*indexCount`, aggregated `(format,stride)` evidence).

### 6.5 State hash

`stateHash` is a deterministic hash of the packet's state fields. It serves
three masters: dedup in the trace, `ResourceCache` keys, and change detection
("did anything actually change for this draw?"). For static city geometry
(unchanged every frame), this is what makes "never re-upload unchanged
buffers" achievable.

---

## 7. The native D3D12 backend

### 7.1 Backend ownership

`NativeRenderer` is the **only** component that creates D3D12 resources,
command lists, or PSOs. Hooks *capture and normalize* state; they never touch
D3D12. `D3D12Backend` is the single implementation of the D3D12 device
management, and everything graphics goes through it. This keeps the guest-capture
path testable headlessly (no device needed to capture) and keeps the D3D12
surface area in one auditable place.

### 7.2 Device and frame lifecycle

```text
Initialize(hwnd, w, h)
  CreateDevice (hardware, WARP fallback — fixed so the fallback actually runs)
  CreateSwapChain(3 back buffers) → RTV heap → render targets
  CreateCommandObjects (allocators ×3, one list) → CreateSyncObjects (fence)
  CreateUploadHeap (per-frame arenas) → CreateTestRootSignature → CreateTestPipeline
BeginFrame
  WaitForCurrentFrameGpu()          // fence wait for THIS back buffer's prior frame
  reset allocator + command list    // → guarantees upload region is safe to rewrite
  draw work (test triangle | dynamic mesh | pipeline-bound draws)
EndFrame → present → signal fence → advance frame index
```

Concurrency: the draw path is guarded by a **recursive mutex** so it cannot
race `Resize()` or `Shutdown()`. `Shutdown()` unmaps and releases *everything*
(upload arena, static IB, root signature, PSO, resource cache) so a
`Shutdown() → Initialize()` recovery path has no dangling upload map.

### 7.3 The upload arena — a linear allocator

Static buffers are uploaded once and cached (see §7.4). Dynamic/per-frame data
goes through a **per-frame upload arena** split into `kBufferCount` (3)
regions, one per back buffer. `BeginFrame`'s fence wait on the current back
buffer already guarantees that region's GPU work from two frames ago is done —
so rewriting it is safe, no extra sync. On arena exhaustion the frame drops
cleanly (no GPU-visible corruption). This is the classic ring-buffer allocation
idiom used by production D3D12 renderers (see the Activision renderer
architecture talk): fence at coarse granularity, linear alloc per region.

### 7.4 ResourceCache — the memory versioner

`src/renderer/resource_cache.*` (D3D12-free, headless-testable):

```cpp
struct ResourceKey {
    ResourceKind kind;       // Buffer/Texture/RenderTarget/Upload
    uint32_t guestAddress;
    uint32_t byteSize;
    uint32_t formatLayout;   // DXGI format code or 0
    uint64_t dataVersion;    // bumped when guest contents change
};
```

A resource is **not** keyed by guest address alone — address+size+format+
version together decide whether a host resource can be reused. `ResourceEntry`
tracks `uploadedVersion` so the backend can answer `NeedsUpload(key)` (version
changed → re-upload; else reuse the cached handle). FIFO eviction, 8192
entries. The backend mirrors the insert/find/version-bump flow in its own
buffer handling so unchanged data is never re-uploaded (Phase 3 gate 2).

This is exactly the RAGE-engine philosophy of "surface index → dense arrays,
versioned, never copied if unchanged", transplanted to D3D12.

### 7.5 PipelineCache — shader hash → PSO

`src/renderer/pipeline_cache.*`: a program-hash → pipeline-state cache with a
**background compile worker**, so PSO creation happens off the frame path
(no hitches). This mirrors the UnleashedRecomp insight: pipeline compilation is
integrated into asset loading / background workers, not a runtime stutter.
The cache is keyed by the stable shader `programHash` (from the parsed IR, §8)
plus render state — the same hash the trace uses.

### 7.6 Draw paths

- `DrawTestMeshedTriangle` — Phase 3 slice: static R16 index buffer (cached),
  per-frame vertex upload, full viewport, `DrawIndexedInstanced`. Proves
  buffer/index/viewport/topology/RTV end-to-end. The `backend_validator` draws
  the same quad into an offscreen BGRA8 target and reads pixels back — CLEAN
  on an RTX 3070 with the D3D12 debug layer (zero messages).
- `DrawDynamicMesh` / `DrawDynamicMeshWithPipeline` — generic indexed /
  non-indexed draw of caller-supplied host vertex bytes with a declared input
  layout. This is the consumption target for a captured `DrawPacket` whose
  layout provably matches the PSO input layout.

### 7.7 Later-phase scaffolding already in the backend

The backend carries forward-looking plumbing (present but not all wired to
guest data):

- **RenderPassDesc / BeginRenderPass / EndRenderPass** — RTV/DSV sets, clears,
  viewport, scissor, with resource-state transitions.
- **Resource state tracking + `TransitionResource`** — automatic barrier
  insertion from a resource→state map.
- **RenderGraphBuilder** — declarative passes (name, resource accesses with
  before/after states, execute lambda), dependency topo-sort, transient
  resource allocation/recycling across frames.
- **Sampler caching** — static samplers baked into root signatures, plus a
  shader-visible sampler descriptor heap (2048 entries, `GetOrCreateSamplerDescriptor`).
- **Texture path** — `CreateDecodedTexture` (uploads host-linear untiled
  pixels → DEFAULT texture + shader-visible SRV at t0), RTV/DSV helpers,
  `ResolveRenderTarget` (the EDRAM-resolve analog), mipmap-generation compute
  pipeline.

---

## 8. Codegen — the shader pipeline

### 8.1 The chain

```text
guest .fxc container (big-endian; contains CF/ALU/FETCH/EXP microcode)
  → container parse                              (shader_translator.cpp)
  → xenos_shader_ir decode                       (xenos_microcode → IR)
  → HLSL emitter (SM 6.0)                        (shader_translator.cpp)
  → DXC → DXIL                                   (dxc_runtime, at runtime)
  → PipelineCache: programHash → PSO
```

### 8.2 IR and microcode decode

`xenos_microcode.*` holds the Xenos instruction table: fetch, ALU (vector+
scalar fused), export, control-flow opcodes. The decoder walks the packed
dword triples and reports `unknown`/`unsupported` counts. **A decoder fix is
not claimable until the corpus run shows `0 unknown, 0 OOB`.** The normalized IR
(`xenos_shader_ir`) feeds the stable `programHash`, vertex-input reflection, and
stage info.

### 8.3 Control flow — the hard part

Xenos microcode uses labels, jumps, and loop instructions. HLSL has no `goto`.
The established technique (XenosRecomp, Xenia) is:

- **Flatten** simple control flow (DXC can then optimize aggressively).
- Otherwise emit a `while(true)` loop with an internal `switch(pc)` — each CF
  label becomes a case, jumps set `pc` and continue.

This project's translator is expected to follow the same shape; the corpus gate
(`shader_pipeline_validator`) exists precisely because complex control flow is
the main correctness risk.

### 8.4 Constants and vertex input

- VS constants: 256 float4 (4096 B), PS: 224 float4 (3584 B). On D3D12,
  **root constant buffers** (uploaded via the linear allocator, GPU-addressable)
  are the natural mapping — the same approach XenosRecomp uses. Out-of-bounds
  dynamic constant accesses must be clamped to 0 (hardware guarantees; D3D12
  doesn't).
- **Vertex input:** the game's VFETCH reads through fetch constants. The
  translator resolves `ReferencedVertexInputs` — the exact `(usage, usageIndex)`
  the generated VS entry consumes, plus `(format, stride, offset)` from the
  first vertex fetch that resolves to it — so the host can build a real D3D12
  input layout. This removes runtime shader permutation by vertex declaration
  (XenosRecomp's key decision).

### 8.5 Special cases native renderers must handle

Xenos-specific vertex formats and behaviors don't exist on desktop D3D12
(these are documented in XenosRecomp as Unleashed-specific but the classes of
problem are universal):

- **R11G11B10** vertex format — no desktop equivalent → manual unpack in VS
  (a specialization flag).
- **Endian-swapped vertex data** — swapping buffers as 32-bit ints swizzles
  8/16-bit element order (16-bit becomes YXWZ) → a `g_SwappedTexcoords` bitmask
  fixes TEXCOORD semantics.
- **Alpha test** — no fixed-function alpha test on desktop → a "less-than-alpha-
  threshold discard" at the end of the PS (specialization flag).
- **Instancing** — the 360 does instancing manually: the index buffer is
  passed as a *vertex stream* and shaders fetch per-instance data via
  `g_IndexCount`. Game-specific handling required.
- **Cube sampling** — the `cube` instruction computes face+2D coords; emulated
  via a local direction array + `TextureCube` (DXC optimizes the array away).

The offline `shader_pipeline_validator` compiles **every** container in the
corpus with DXC, so "generated HLSL compiles" is guaranteed before any runtime
path trusts it.

### 8.6 DXC at runtime

`dxc_runtime.*` loads `dxcompiler.dll` + `dxil.dll` at runtime (never linked
into `mcla.exe`), resolved from an explicit dir → `MCLA_DXC_DIR` → the vendored
`.research/XenosRecomp/thirdparty/dxc-bin/bin/x64` → exe dir. DXC COM compiler
objects aren't thread-safe — one `DxcRuntime` per compiling thread (the
background PSO worker). `shader_dxc_compile.cpp` is the DXC-linked offline
compile path used by validators.

---

## 9. Vertex and texture decode

### 9.1 Vertex decode (`vertex_decode.*`)

Decodes Xenos VFETCH format codes and index formats. Validated against the
real corpus: all 762 fetches are `vf=0`, fetch-constant-relative via
`const[31]`. `grc_fvf_decode.*` decodes the captured RAGE `GrcFvfDesc` into
concrete semantic/type/offset info the input-layout builder consumes.

### 9.2 Texture decode (`texture_decode.*`)

The untiling problem from §5.4, implemented CPU-side:

- oracle-validated format table (Xenos format code → host format, bytes/block),
- bounds-guarded tiled-offset math for the 32×32 micro-tile + macro-XOR
  addressing, per bytes-per-block,
- 2D and 3D (slices) support,
- `texture_decode_test` validates against the oracle byte-exactly.

`resource_cache.h::ComputeTextureLayout` sizes a texture from Xenos format +
extents using the same table, so the cache and the decode path never disagree.

---

## 10. Assets — RPF, TXD, DFF (RAGE formats)

`renderer_mode` has nothing to do with assets; the asset pipeline serves both
modes. MCLA on 360 is 1280×720 (PS3 was 960×720) and its world data ships in
RAGE's container format.

- `src/vfs_rpf.*` — `RpfVirtualFileSystem`: mounts the extracted game data
  (`mcla extracted cache`) and serves hash-addressable reads. RAGE addresses
  resources by **hash**, not path — the VFS is the lookup layer.
- `src/rage_asset_pipeline.*`:
  - `CsrContainer` — the `"CSR"` container header (version 0x05, magic,
    size/flags, entries with hash/offset/size/type). Resource types include
    TextureDictionary (TXD), Model (DFF), Texture, Geometry, Animation,
    Collision, Audio.
  - `TxdParser` — texture dictionaries (hash, w/h, format, mips, raw data).
  - `DffParser` — models (positions/normals/uvs/indices + material hash).
  - `RageAssetManager` — singleton cache, can create D3D12 textures/buffers
    for the native renderer.

The RAGE `grcVertexBufferD3D`/`grcVertexFormat` structure (16-bit lane mask +
4-bit type codes + stride) is the same family of layout the `GrcFvfDesc`
captures — cross-reference with open-source RAGE-format converters (fivem's
`rage-formats-x`, RAGE-Console-Resource-Converter for MCLA/RDR) to validate
parse assumptions. Phase 9 committed the parsers; the validation gap (parse
correctness vs real in-game assets) is recorded as still open.

---

## 11. Verification — validators and gates

Headless console tools under `build/`, each over the shared renderer TUs. Run
all after every renderer change.

| Validator | Purpose | Gate |
|---|---|---|
| `phase3_validator` | vertex fetch + resource/texture decode | CLEAN = 0 unsupported formats |
| `xenos_decode_validator` | raw microcode decode over corpus | 0 unknown, 0 OOB |
| `shader_pipeline_validator` | parse + translate every container, compile via DXC | no unknown/unsupported/empty HLSL |
| `texture_decode_test` | tiled decode vs oracle | byte-exact |
| `capture_dump_validator` | `.mclatrace` vs guestmem dumps | header/packet integrity + per-stream coverage |
| `xtr_dump_validator` | `.xtr` PM4 stream parse | parses to EOF, no desync |
| `backend_validator` | D3D12 device/PSO/offscreen raster | 0 debug messages + pixel readback correct |

Phase gates are named in `NATIVE_GPU_REBUILD_PLAN.md` (Phase 4 G1: whole corpus
processed with 0 OOB reads; G2: PSOs draw on HW/WARP with 0 debug messages; G3:
first live `hasGrcFvf=1` frame in `native` renders pixel-accurate vs legacy).
**No gate is claimed passed until its validator reports CLEAN on the real
corpus/data.**

---

## 12. Build & run

```text
# main host + validators
cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build
build/mcla.exe                       # renderer_mode=legacy by default

# smoke host (BOTH compilers clang-cl; delete build-smoke when switching compilers)
cmake -S tools/xenon_smoke -B build-smoke -G Ninja ^
  -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl ^
  -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build-smoke
build-smoke\xenon_smoke.exe build\game_data\default.xex   # boot
build-smoke\xenon_smoke.exe --function=0x82130000         # single TU call
```

Details:

- Requires VS BuildTools `vcvars64.bat` on PATH.
- `clang-cl` for **both** C and CXX (MSVC C + clang-cl CXX fails); lld linker.
- `/GS- /EHa` on the mcla target (matches the recompiled-code assumptions),
  `NOMINMAX`, `/utf-8`, `__builtin_isnan=_isnan` shim.
- `roundevenf` provided for the CRT (simde math fallback used by generated TUs).
- DXC is compiled into validator targets only; `mcla.exe` loads it at runtime.

---

## 13. Golden rules (load-bearing, repeated deliberately)

1. **One hook owner per guest address** — the dispatcher is the only registry;
   never install the same address twice.
2. **Hooks capture state only** — no D3D12 calls, no `rex::graphics::RegisterFile`
   dependency, from a hook.
3. **Guest pointers are 32-bit addresses + bounds** — never raw host pointers;
   reads go through `GuestMemoryView` with explicit endianness.
4. **No invented draw data** — unknown capture data is researched, not
   defaulted; every `MclaGpuContext` field is evidence-backed.
5. **`generated/` is input** — never patched; validate before trusting a field.
6. **`renderer_mode` stays `legacy`** until the gates pass.
7. **A path is native only if it never calls the Xenos command processor,
   submits PM4, or uses guessed draw data.**

---

## 14. Performance engineering (senior-dev lens)

The capture/native split exists precisely so the frame path can be *fast and
stable*, not just correct. The right mental model, taken from production D3D12
renderers:

- **Pre-compute what you can offline.** Shader translation and PSO creation
  are *not* frame work. The corpus gate guarantees HLSL compiles; the
  background pipeline worker guarantees PSOs are ready before their first
  draw. Unchanged static city geometry must compile its pipelines during asset
  load (the RAGE streaming workers are the natural place — this is the
  UnleashedRecomp "no stutter" trick).
- **Freeze data early, reference don't copy.** The `DrawPacket` is the frozen
  snapshot. The render graph references resources (transient recycling), the
  resource cache keys by version. Per-draw costs must be: lookup, bind, draw —
  no hashing, no allocation, no barriers if already in the right state.
- **Allocators: one ring + linear per-owner.** GPU-visible constant/vertex
  data rides the per-frame upload arena (fenced at back-buffer granularity).
  The render graph's transient allocator recycles across frames at pass
  granularity. Avoid per-draw heap allocations entirely.
- **Batch the static world.** Once a mesh+buffer+PSO combo is stable, the
  native path should emit *multi-draw/indirect* command lists, not one
  `DrawIndexedInstanced` per draw — the Activision-renderer lesson is that
  tightly-sorted indirect execution beats per-draw API calls by a wide margin.
- **Barriers are the tax.** The state tracker + render graph exist so barriers
  are emitted once at the right granularity, not spuriously. When profiling,
  watch barrier count and descriptor-heap churn before CPU frame time.

None of this is implemented yet beyond the scaffolding — the plan phases
explicitly defer it until correctness is proven (the perf-engineer agent owns
the Tracy-driven validation).

---

## 15. Where the project stands — honest status

```text
Phases 0–3   complete   hooks, capture, vertex decode, resource cache,
                         D3D12 test draw, capture dumps      validators CLEAN
Phase 4      next gate  real guest VB/IB → native draw, renderer_mode=capture
                         replay, pixel-diff vs legacy
Phase 5+     groundwork IR→HLSL→DXIL + async PSO cache
Phase 9      partial    VFS/RPF + TXD/DFF parsers; validation gap open
Boot smoke   reaches GPU fence wait (expected: no GPU); VdSwap path next
```

Honest summary: **boot reachability is proven part-way; rendering is still the
legacy Xenos/PM4 path; native mode renders a test triangle, not the game.** Each
remaining step is gated and validator-backed. The plan docs (`NATIVE_GPU_...`,
`BOOT_REBUILD_PLAN.md`) carry the per-phase investigation records; the phase-gate
skill (`mcla-phase-gate`) enforces the discipline before starting any plan task.