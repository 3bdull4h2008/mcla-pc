# MCLA Xbox 360 GPU Context Structure

Base address: r3 parameter in all GfxCmdBuf* / CommandBuffer* / RenderState* functions.
Total size: ~13 KB (0x3300+ bytes confirmed, likely up to ~0x3400 or more).

## Offset Map Legend

| Marking | Meaning |
|---------|---------|
| [V]     | Verified via multiple independent functions |
| [C]     | Confirmed by call chain context |
| [I]     | Inferred from usage pattern |
| [REF]   | Cross-referenced with analysis doc |

---

## 1. Header (0x000 - 0x03F)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0x00  | 4    | u32* | **(inferred)** | vtable pointer |
| +0x04  | 4    | u32  | **(inferred)** | reference count / flags |
| +0x08  | 4    | u32  | **(inferred)** | allocator context pointer |
| +0x0C  | 4    | u32  | **(inferred)** | allocator size/type |
| +0x10 (+16) | 8 | u64 | GfxCmdBufSubmit_Next [V] | sync/lock value (loaded & stored back as barrier) |
| +0x28 (+40) | 8 | u64 | BeginRenderPass, GfxCmdBufSubmit_Next [V] | flags bitmask — ANDed against render pass param bits; bits 57+ checked |
| +0x30 (+48) | 4 | u32 | BeginRenderPass, AllocSegment [V] | current command buffer write position |
| +0x34 (+52) | 4 | u32 | AllocSegment [V] | predicted next write position (= current + 160) |
| +0x38 (+56) | 4 | u32 | BeginRenderPass, AllocSegment [V] | last committed/available write position |

---

## 2. Command Buffer Entry Array (0x5D8 - 0x858)

Base at +0x5D8 (+1496), 32 entries × 20 bytes = 640 bytes total.

### Per-entry format (20 bytes = 5 × u32):

| Entry Offset | Field |
|-------------|-------|
| +0 | u32 cmd/packet type |
| +4 | u32 param0 |
| +8 | u32 param1 |
| +12 | u32 param2 |
| +16 | u32 param3 / terminator (-1 = end) |

### Management counters (stored relative to base+0x5D8):

| Absolute Offset | Relative to base | Type | Description |
|----------------|-----------------|------|-------------|
| +0x858 (+2136) | +0x280 (640) | u32 | entry count (number of valid entries, max 32) |
| +0x85C (+2140) | +0x284 (644) | u32 | write index (current slot, incremented per push) |
| +0x860 (+2144) | +0x288 (648) | u32 | remaining capacity (32 - entry_count, init=32, decr per push) |

Used by: CommandBuffer_Push (+0x822578F8) [V]

---

## 3. Texture / Shader Constant Area (0x84C - 0x8D4)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0x84C (+2124) | 4 | u32 | Gpu_UploadMatrixConstants [C] | matrix constant destination pointer / base |
| +0x868 (+2152) | 4 | u32 | Gpu_UploadMatrixConstants [C] | matrix count |
| +0x878 (+2168) | 4 | u32 | Gpu_UploadMatrixConstants [C] | matrix constant offset |
| +0x8D4 (+2260) | 4 | u32 | Texture_Create, Gpu_UploadMatrixConstants [V] | texture/shader constant base pointer |

Note: Gpu_UploadMatrixConstants may use r31 computed as (base | 5088), so offsets are relative to a sub-struct, not the GPU context base.

---

## 4. Shader Constant Storage (0xED4)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0xED4 (+3796) | 4 | u32 | ShaderConstInit, GfxObjectInit, RenderObject_InitDefaults [C] | shader constant storage heap/address |

---

## 5. Device / Command Buffer Context (0x25F4 - 0x2AC0)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0x25F4 (+9716) | 4 | u32* | CmdBuf_Resize [V] | global state/device pointer |
| +0x2A90 (+10896) | 4 | u32* | CmdBuf_Resize [V] | buffer state pointer (dereferenced for content) |
| +0x2A9C (+10908) | 4 | u32 | CmdBuf_Resize [V] | buffer length/remaining |
| +0x2AB4 (+10932) | 4 | u32 | GfxCmdBufSubmit, GfxCmdBufSubmit_Next [V] | flag word 1 |
| +0x2AB8 (+10936) | 4 | u32 | GfxCmdBufSubmit, GfxCmdBufSubmit_Next [V] | flag word 2 |

### Flags Bytes (+0x2ABC - +0x2ABF)

All 3 flag bytes used across multiple functions:

| Offset | Functions | Bit Usage |
|--------|-----------|-----------|
| +0x2ABC (+10940) u8 | CmdBuf_Resize, GfxCmdBufSubmit, *Submit_Next, BeginRenderPass [V] | bit 7(0x80)=force_resize, bit 6(0x40)=state_override, bit 5(0x20)=render_mode, bit 4(0x10)=state_flag, bit 3(0x08)=submit_flag, bit 2(0x04)=submit_flag2, bit 0=dirty |
| +0x2ABD (+10941) u8 | AllocSegment, CmdBuf_Resize [V] | bit 5(0x20)=allocation_failed |
| +0x2ABF (+10943) u8 | GfxCmdBufSubmit_Next, BeginRenderPass [V] | bit 5(0x20)=render_state_active |

---

## 6. Render Target Area (0x2E4C - 0x2EE4)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0x2E4C (+11852) | 4 | u32 | GfxCmdBufSubmit_Next, BeginRenderPass [V] | render target handle / dimension (bits 12-14 checked for format) |
| +0x2EE4 (+12012) | 4 | u32 | Texture_Create [C] | texture object pointer |

---

## 7. Render State Flags (0x2F9B)

| Offset | Size | Type | Accessing Functions | Description |
|--------|------|------|--------------------|-------------|
| +0x2F9B (+12187) | 1 | u8 | GfxCmdBufSubmit, *Submit_Next [V] | render state dirty flag (checked for zero) |

---

## 8. Render State Arrays (0x3098 - 0x31DC)

Three contiguous groups of render state values, written as PM4 register packets.

### Group A (0x3098 - 0x30A8): 5 × u32 — Render State VALUES

Pairs with Group C[6-10] (+0x31C8-+0x31D8) via value copy in GfxCmdBufSubmit_Next.
Group A holds the VALUES; Group C[6-10] holds the corresponding register ADDRESSES.

| Offset | Type | Functions | Confirmed Xenos Register (index) |
|--------|------|-----------|--------------------------------|
| +0x3098 (+12440) | u32 | GfxCmdBufSubmit, *Submit_Next, BeginRenderPass [V] | **RB_SURFACE_INFO** (0x2000) |
| +0x309C (+12444) | u32 | same [V] | **RB_DEPTH_INFO** (0x2002) |
| +0x30A0 (+12448) | u32 | same [V] | **PA_SC_WINDOW_OFFSET/SCISSOR** (0x2080-0x2082) |
| +0x30A4 (+12452) | u32 | same [V] | **PA_CL_VPORT_*SCALE/*OFFSET** (0x210F-0x2114) |
| +0x30A8 (+12456) | u32 | same [V] | **PA_SC_SCREEN_SCISSOR_TL/BR** (0x200E-0x200F) |

### Group B (0x317C - 0x3190): 4 × u32 — Shader Program Pointers

| Offset | Type | Functions | Confirmed Xenos Register |
|--------|------|-----------|-------------------------|
| +0x317C (+12676) | u32 | GfxCmdBufSubmit_Next [V] | **SQ_VS_CONST** (0x2307) / SQ_PGM_START_VS |
| +0x3180 (+12680) | u32 | GfxCmdBufSubmit_Next [V] | **SQ_PS_CONST** (0x2308) / SQ_PGM_START_PS |
| +0x3184 (+12684) | u32 | GfxCmdBufSubmit_Next [V] | **SQ_VS_PROGRAM** (0x21F7) |
| +0x3188 (+12688) | u32 | GfxCmdBufSubmit_Next [V] | **SQ_PS_PROGRAM** (0x21F6) |

### Group C (0x31B4 - 0x31DC): 11 × u32 — Combined Register Addrs + Values

Entries [0-4] (+0x31B4-+0x31C4) hold register ADDRESSES for PM4 register-set packets.
Entries [5-9] (+0x31C8-+0x31D8) hold VALUE mirrors of Group A, copied by GfxCmdBufSubmit_Next.
Entry [10] (+0x31DC) holds draw vertex count.

| Offset | Type | Functions | Purpose | Xenos Reg |
|--------|------|-----------|---------|-----------|
| +0x31B4 (+12708) | u32 | GfxCmdBufSubmit [V] | register address 0 | **PA_CL_CLIP_CNTL** (0x2204) |
| +0x31B8 (+12712) | u32 | GfxCmdBufSubmit [V] | register address 1 | **PA_SU_SC_MODE_CNTL** (0x2205) |
| +0x31BC (+12716) | u32 | GfxCmdBufSubmit [V] | register address 2 (cleared before submit) | **PA_CL_VPORT_XSCALE** (0x210F) |
| +0x31C0 (+12720) | u32 | GfxCmdBufSubmit_Next [V] | register address 3 / cache target | **PA_CL_VPORT_XOFFSET** (0x2110) |
| +0x31C4 (+12724) | u32 | GfxCmdBufSubmit_Next [V] | register address 4 / VTE control | **PA_CL_VTE_CNTL** (0x2206) |
| +0x31C8 (+12728) | u32 | same as Group A [V] | **value mirror: Group A[0]** → RB_SURFACE_INFO |
| +0x31CC (+12732) | u32 | same [V] | **value mirror: Group A[1]** → RB_DEPTH_INFO |
| +0x31D0 (+12736) | u32 | same [V] | **value mirror: Group A[2]** → WINDOW/SCISSOR |
| +0x31D4 (+12740) | u32 | same [V] | **value mirror: Group A[3]** → VIEWPORT |
| +0x31D8 (+12744) | u32 | same [V] | **value mirror: Group A[4]** → SCREEN_SCISSOR |
| +0x31DC (+12748) | u32 | GfxCmdBufSubmit_Next [V] | **draw vertex/index count** (from param r5) |

---

## 9. Vertex Buffer / Stream State (0x31BC alias, 0x31D4)

| Offset | Size | Description |
|--------|------|-------------|
| +0x31D4 (+12756) | 10×16=160B | vertex buffer entries (10 entries × 16 bytes each? or variable) |
| +0x31FC (+12764) | 32×8=256B | packed vertex buffer state (32 entries × 8 bytes) paired with write mask array |
| +0x32C4 (+12996) | 32×8=256B | write mask array (32 entries × 8 bytes, masks & 0xFFFFFFE0) |
| +0x31D0 (+12752) | | possible stream count |

Note: In GfxCmdBufSubmit_Next, +12748 (vertex count) is written from r5(r27). Then a loop copies 16-byte chunks from r22 input to +12756 area, while also writing 8-byte masked values to +12996 array.

---

## 10. State Cache (0x3374 - 0x343C)

Miscellaneous cached state values flushed as PM4 packets:

| Offset | Type | Functions | Description |
|--------|------|-----------|-------------|
| +0x3374 (+13172) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 0 |
| +0x3378 (+13176) | u32 | GfxCmdBufSubmit_Next, BeginRenderPass [V] | cached state entry 1 |
| +0x337C (+13180) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 2 |
| +0x3380 (+13184) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 3 |
| +0x3384 (+13188) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 4 |
| +0x3390 (+13200) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 5 |
| +0x3398 (+13208) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 6 |
| +0x33A0 (+13216) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 7 |
| +0x33A4 (+13220) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 8 |
| +0x33B0 (+13232) | u32 | AllocSegment, CmdBuf_Resize [V] | buffer capacity flag / segment count (0=unbounded) |
| +0x3450 (+13368) | var | CmdBuf_Resize [REF] | source buffer for segment copy |
| +0x3470 (+13376) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 9 |
| +0x3474 (+13380) | u32 | GfxCmdBufSubmit_Next [V] | cached state entry 10 |

---

## 11. Command Buffer Ring (0x3A38 - ~0x3CB8)

### Ring Management (0x3A38 - 0x3A5C)

| Offset | Type | Functions | Description |
|--------|------|-----------|-------------|
| +0x3A38 (+14904) | u32* | AllocSegment [V] | ring buffer start address (beginning of allocatable area) |
| +0x3A3C (+14908) | u32* | AllocSegment [V] | ring buffer write pointer (grows upward, used as copy source) |
| +0x3A40 (+14912) | ? | — | (gap, not observed) |
| +0x3A44 (+14916) | u32* | AllocSegment [V] | last write pointer copy (= previous +14908 value) |
| +0x3A48 (+14920) | ? | — | (gap, not observed) |
| +0x3A4C (+14924) | u32* | AllocSegment [V] | ring buffer end address (wrap point) |
| +0x3A54 (+14932) | u32 | AllocSegment [V] | current byte offset from buffer start |
| +0x3A58 (+14936) | u32 | AllocSegment [V] | buffer capacity (max offset before flush or wrap) |
| +0x3A8C (+14988) | u32 | Gpu_UploadMatrixConstants, Render_Update [C] | current output / write destination pointer |

### Ring Buffer Slot Format

Command buffer ring: 32 slots × 20 bytes/slot = 640 bytes starting at +14904.

Each 20-byte slot:
| Slot Offset | Description |
|-------------|-------------|
| +0 | base/start address (u32*) |
| +4 | current write pointer (u32*) |
| +8 | (reserved) |
| +12 | last flushed pointer (u32*) |
| +16 | segment end (u32*) |

---

## 12. Additional State (0x3A30, 0x2ABF+)

| Offset | Size | Type | Functions | Description |
|--------|------|------|-----------|-------------|
| +0x3A30 (+14884) | 4 | u32 | RenderStateInit [C] | initial render state configuration value |

---

---
## 13. PM4 Packet Construction (BeginRenderPass)

BeginRenderPass precomputes packet headers and emits PM4 register writes for each MRT:

```
lis r8, -16384      # r8 = 0xC0000000
lis r7, -16384      # r7 = 0xC0000000
lis r6, -16383      # r6 = 0xC0010000
lis r5, 4           # r5 = 0x00040000

ori r21, r8, 24832  # r21 = 0xC0006100 — Type3 opcode 0x6100, count=0
ori r27, r7, 24576  # r27 = 0xC0006000 — Type3 opcode 0x6000, count=0
ori r25, r6, 11521  # r25 = 0xC0012D01 — Type3 opcode 0x2D01, count=1
ori r22, r5, 515    # r22 = 0x00040203 — Type0 base=0x0203, 5 regs
```

MMIO register address reference (from `src/gpu_mmio.h:XenosRegister`, byte offsets from 0x7FC80000):
| Name | Offset (byte) | Purpose |
|------|--------------|---------|
| CP_RB_WPTR | 0x0714 | Ring buffer write pointer (KICK) |
| CP_RB_BASE | 0x0700 | Ring buffer base address |
| VGT_DRAW_INITIATOR | 0x3008 | Draw call trigger |
| SQ_ALU_CONST_CACHE | 0x4800 | ALU constant cache |
| SQ_TEX_SAMPLER_WORD0_0 | 0x6000 | Texture sampler state |
| SQ_TEX_RESOURCE_WORD0_0 | 0x6100 | Texture resource state |
| CB_COLOR0_BASE | 0x7000 | Color buffer base address |
| CB_DEPTH_BASE | 0x7100 | Depth buffer base address |
| SQ_PGM_START_VS | 0x8000 | Vertex shader program start |
| SQ_PGM_START_PS | 0x8004 | Pixel shader program start |

The game builds PM4 packets inline within the GPU context struct's header area (starting at +0x04), using `stwu` post-increment writes. The write pointer is tracked at +0x30 (+48) and checked against +0x38 (+56) for buffer capacity.

---

## Cross-Reference: Functions by Offset Accessed

| Function | Address | File:Line | Confirmed GPU Context Offsets |
|----------|---------|-----------|------------------------------|
| CmdBuf_Resize | 0x82412710 | 25:41825 | +9716, +10896, +10908, +10940, +10941, +13232 |
| CommandBuffer_AllocSegment | 0x82411840 | 25:39567 | +10941, +13232, +13516, +14904, +14908, +14916, +14924, +14932, +14936 |
| CommandBuffer_BeginRenderPass | 0x824231B0 | 26:26071 | +40, +48, +56, +10368, +10460, +10940, +10943, +11852, +12440-+12748, +13176 |
| CommandBuffer_Push | 0x822578F8 | 9:56248 | +1496, +2136, +2140, +2144 |
| GfxCmdBufSubmit | 0x8241BD08 | 26:8110 | +10932, +10936, +10940, +12187, +12440-+12456, +12708-+12716, +12728-+12744 |
| GfxCmdBufSubmit_Next | 0x8241BE78 | 26:8323 | +16, +40, +10368, +10932-+10940, +10943, +11852, +12187, +12440-+12456, +12676-+12688, +12708-+12748, +12756, +12764, +12996, +13172-+13380 |

---

## C++ Representation

```cpp
struct MclaGpuContext {
    // 0x000 - 0x03F: Header
    /* +0x00 */ void* vtable;
    /* +0x04 */ uint32_t refCount_flags;
    /* +0x08 */ void* allocator;
    /* +0x0C */ uint32_t allocSize;
    /* +0x10 */ uint64_t syncValue;       // memory barrier value

    // 0x028 - 0x03F
    /* +0x28 */ uint64_t flagsBitmask;    // render pass bit flags
    /* +0x30 */ uint32_t cmdBufWritePos;  // current write position
    /* +0x34 */ uint32_t cmdBufNextPos;   // predicted next (+160)
    /* +0x38 */ uint32_t cmdBufAvailPos;  // last committed position

    // Padding up to 0x5D8
    /* +0x5D8 */ uint32_t cmdEntries[32][5]; // 32 entries × 20 bytes

    // Command buffer entry management
    /* +0x858 */ uint32_t cmdEntryCount;     // valid entries
    /* +0x85C */ uint32_t cmdWriteIndex;     // current slot
    /* +0x860 */ uint32_t cmdRemaining;      // capacity remaining

    // Shader / texture constants
    /* +0x84C */ void* shaderConstBase;
    /* +0x868 */ uint32_t matrixCount;
    /* +0x878 */ uint32_t shaderConstOffset;
    /* +0x8D4 */ void* textureShaderBase;

    // Shader constant storage
    /* +0xED4 */ void* shaderConstantHeap;

    // Device / command buffer context
    /* +0x25F4 */ void* devicePtr;
    /* +0x2A90 */ void* bufferState;
    /* +0x2A9C */ uint32_t bufferLength;
    /* +0x2AB4 */ uint32_t flagWord1;
    /* +0x2AB8 */ uint32_t flagWord2;

    // Flag bytes
    /* +0x2ABC */ uint8_t flags0;    // bit7=resize, bit6=override, bit5=mode, bit4=state, bit3=submit1, bit2=submit2
    /* +0x2ABD */ uint8_t flags1;    // bit5=alloc_failed
    /* +0x2ABE */ uint8_t pad1;
    /* +0x2ABF */ uint8_t flags2;    // bit5=active

    // Render target
    /* +0x2E4C */ uint32_t renderTargetHandle;
    /* +0x2EE4 */ void* texturePtr;

    // Render state dirty
    /* +0x2F9B */ uint8_t stateDirty;

    // Render State Array A (5 registers)
    /* +0x3098 */ uint32_t rbSurfaceInfo;      // RB_SURFACE_INFO
    /* +0x309C */ uint32_t rbColorDepthInfo;   // RB_COLOR/DEPTH_INFO
    /* +0x30A0 */ uint32_t rbScissor;          // RB_SCISSOR/WINDOW
    /* +0x30A4 */ uint32_t rbViewport;         // RB_VIEWPORT/ZMASK
    /* +0x30A8 */ uint32_t rbScreenScissor;    // PA_SC_SCREEN_SCISSOR

    // Render State Array B (4 shader registers)
    /* +0x317C */ uint32_t sqVsConstBase;      // SQ_VS_CONST
    /* +0x3180 */ uint32_t sqPsConstBase;      // SQ_PS_CONST
    /* +0x3184 */ uint32_t sqVsProgram;        // SQ_VS_PROGRAM
    /* +0x3188 */ uint32_t sqPsProgram;        // SQ_PS_PROGRAM

    // Render State Array C (11 registers)
    /* +0x31B4 */ uint32_t paClipCntl;         // PA_CL_CLIP_CNTL
    /* +0x31B8 */ uint32_t paSuScModeCntl;     // PA_SU_SC_MODE_CNTL
    /* +0x31BC */ uint32_t paScVportScale;     // PA_SC_VPORT_SCALE
    /* +0x31C0 */ uint32_t paScVportOffset;    // PA_SC_VPORT_OFFSET
    /* +0x31C4 */ uint32_t paClVteCntl;        // PA_CL_VTE_CNTL
    /* +0x31C8 */ uint32_t sqConstPs;          // SQ_CONSTANT_PS
    /* +0x31CC */ uint32_t sqAluConst;         // SQ_ALU_CONSTANT
    /* +0x31D0 */ uint32_t sqVtxConst;         // SQ_VTX_CONSTANT
    /* +0x31D4 */ uint32_t sqBoolConst;        // SQ_BOOL_CONSTANT
    /* +0x31D8 */ uint32_t sqLoopConst;        // SQ_LOOP_CONSTANT
    /* +0x31DC */ uint32_t drawParamCount;     // vertex/element count

    // Vertex buffer state
    /* +0x31D4 */ uint32_t vbEntries[10][4];   // 10 vertex buffer entries × 16 bytes
    /* +0x31FC */ uint32_t vbPackedState[32][2]; // 32 packed entries × 8 bytes
    /* +0x32C4 */ uint32_t vbWriteMask[32][2]; // 32 write masks × 8 bytes

    // State cache
    /* +0x3374 */ uint32_t cacheEntry[11];     // indices 0-10
    /* +0x33B0 */ uint32_t bufferCapacity;     // segment count (0=unbounded)
    /* +0x3450 */ uint8_t  segmentCopySrc[?];  // source for segment copy
    /* +0x3470 */ uint32_t cacheEntry[2];      // indices 9-10 (or continuation)

    // Command buffer ring (32 slots × 20 bytes = 640 bytes)
    /* +0x3A38 */ CmdBufferSlot ringBuffer[32];
    /* +0x3A8C */ void* currentOutput;
} __attribute__((packed));
```
