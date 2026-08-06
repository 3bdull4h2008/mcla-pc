# MCLA Rendering Architecture & Native Interception Plan

## Overview

The Xbox 360 rendering stack has 4 layers:
```
Game Code → SceneGraph → D3DDevice Wrapper → GPU Context → Xenos GPU
                                                      ↓
                                              Command Buffer
                                              (PM4 packets)
```

Native rendering hooks will intercept at the GPU Context level, reading state and
translating PM4 commands to DirectX calls.

---

## Layer 1: D3DDevice (Xbox 360 XDK)

Global device: `*(0x821A9B1C)` via `RenderDevice_GetCurrent()`

### D3DDevice Structure (from Gpu_Op analysis)

| Offset | Size | Description |
|--------|------|-------------|
| +0x00  | 4    | vtable pointer |
| +0x04  | 4    | ref count |
| +0x08  | ?    | allocator? |
| +0x10 (+16) | 4 | Command buffer context (has own vtable) |
| +0x14 (+20) | ? | |
| +0x18 (+24) | ? | |
| +0x44 (+68) | 4 | Sub-context pointer (GPU state container) |
| +0x48 (+72) | 4 | width or display mode |
| +0x4C (+76) | 4 | height or display mode |
| +0x50 (+80) | 4 | related to width*stride |

### D3DDevice Sub-context (+68)

| Offset | Size | Description |
|--------|------|-------------|
| +0x0C (+12) | 4 (float) | some ratio/dimension |
| +0xEC (+236) | 4 | another context (has +16 float for comparison) |

### Texture Manager

Accessed from the GPU context path. Structure:
| Offset | Size | Description |
|--------|------|-------------|
| +0x80 (+128) | * | texture entry array (16 bytes/entry) |
| +0x84 (+132) | * | byte flags per slot |
| +0x88 (+136) | * | u32 state per slot |

---

## Layer 2: GPU Context

Full struct at `MCLA_GPU_CONTEXT_STRUCT.md`. Size ~13KB.
Passed as `r3` to all `GfxCmdBuf*` / `CommandBuffer*` functions.

### Key regions:

| Region | Offset | Size | Content |
|--------|--------|------|---------|
| Header | +0x00 | 0x3F | vtable, flags (u64 at +0x28), buffer counters (+0x30-+0x38) |
| Cmd Entries | +0x5D8 | 640B | 32 entries × 20 bytes |
| Cmd Mgmt | +0x858 | 12B | entry count, write index, remaining |
| Texture/Shader | +0x84C | ~80B | shader const base, texture base |
| Shader Storage | +0xED4 | 4B | shader constant heap ptr |
| Device Ctx | +0x25F4 | ~0x4C0 | buffer state, flags at +0x2ABC-+0x2ABF |
| Render Target | +0x2E4C | ~0xA0 | target handle (+0x2E4C), texture ptr (+0x2EE4) |
| State Dirty | +0x2F9B | 1B | render state dirty flag |
| Render State A | +0x3098 | 20B | 5 × u32 (RB_SURFACE_INFO etc) |
| Render State B | +0x317C | 16B | 4 × u32 (shader base addrs) |
| Render State C | +0x31B4 | 44B | 11 × u32 (clip, vport, consts) |
| Vertex State | +0x31D4 | 160B | vertex buffer entries |
| VB Packed | +0x31FC | 256B | packed vertex buffer state |
| Write Masks | +0x32C4 | 256B | per-entry write masks |
| State Cache | +0x3374 | ~0xC0 | cached state values |
| Cmd Ring | +0x3A38 | 640B | 32-slot command buffer ring |
| Output | +0x3A8C | 4B | current output buffer |

### Flags Byte (+0x2ABC):

| Bit | Meaning |
|-----|---------|
| 7   | Force resize / flush |
| 6   | State override enabled |
| 5   | Render mode |
| 4   | State flag |
| 3   | Submit flag 1 |
| 2   | Submit flag 2 |
| 0   | Dirty |

### Flags Byte (+0x2ABD):
| Bit | Meaning |
|-----|---------|
| 5   | Allocation failed |

### Flags Byte (+0x2ABF):
| Bit | Meaning |
|-----|---------|
| 5   | Render state active |

---

## Layer 3: Command Buffer

### Entry Buffer (32 × 20 bytes at +0x5D8)

Each entry:
```
+0: u32 cmd/packet type
+4: u32 param0
+8: u32 param1
+12: u32 param2
+16: u32 terminator (-1 = end)
```

Push mechanism: `CommandBuffer_Push` (0x822578F8)
- Increments write index, decrements remaining
- When full (index=32), resets and writes terminator

### Ring Buffer (32 slots × 20 bytes at +0x3A38)

Each slot:
```
+0: u32* base address
+4: u32* write pointer
+8: (reserved)
+12: u32* last flush
+16: u32* segment end
```

### PM4 Packet Generation

`CommandBuffer_BeginRenderPass` writes PM4 packets:
- Type-3 header: 0xC0006000 (opcode varies)
- Register writes: 0x4000C000 (SET_CONSTANT/LOAD_ALU_CONSTANT)
- WRITE_REG/INDIRECT_BUFFER variants

Key PM4 opcodes observed:
- 0x4000C000: TYPE-3 with 1 dword data
- 0x40006100: TYPE-3 register write
- 0x40002D01: TYPE-3 with ALU constant
- 0x00040203: register data value

---

## Layer 4: Render Pipeline Flow

### Frame Render Sequence

```
1. Render_Update (0x826FD508) [18 calls/frame]
   ├─ Load global state → get render context
   ├─ Call vtable[14] → returns active context handle
   └─ Call vtable[17] → render the context

2. SceneGraph Traversal
   ├─ SceneGraphTraverseChildren (0x8268F078)
   ├─ SceneNode_UpdateTransform (0x821E6800) [276 calls]
   └─ EntityScene_Update (0x821D2AA0) [222 calls]

3. Draw Call Preparation
   ├─ gfxGetVertexBuffer (0x82509B28) [13 calls]
   ├─ Gfx_InitVertexDeclaration (0x821F6C50)
   ├─ gfxSetupDrawParams (0x825286E8) [10 calls]
   └─ DrawCall_BuildParams (0x825749E8)

4. Command Buffer Operations
   ├─ CommandBuffer_Push (0x822578F8) [13 calls]
   ├─ CommandBuffer_BeginRenderPass (0x824231B0) [9 calls]
   ├─ GfxCmdBufSubmit (0x8241BD08) [16 calls]
   └─ GfxCmdBufSubmit_Next (0x8241BE78)

5. GPU State Sync
   ├─ GpuSetRenderState (0x82668660) [9 calls]
   ├─ Gpu_UploadMatrixConstants (0x822192F8) [10 calls]
   ├─ Gpu_TextureValidateSlot (0x82374B30) [10 calls]
   └─ Shader_BindDeviceContext (0x82637DD8)
```

---

## Native Rendering Strategy

### Primary Interception Point: GfxCmdBufSubmit (+0x8241BD08)

This is called 16 times/frame with the GPU context as r3.
At this point all render state arrays, shader constants, and vertex buffers
are populated.

Hook approach:
```cpp
// Patch the recomp function to call our native renderer
void Hooked_GfxCmdBufSubmit(uint32_t r3, uint32_t r4) {
    MclaGpuContext* ctx = (MclaGpuContext*)r3;
    
    // 1. Read render state from ctx
    //    - Viewport: ctx->renderStateA[0..4] (+0x3098)
    //    - Shaders: ctx->renderStateB[0..3] (+0x317C)
    //    - Pipeline state: ctx->renderStateC[0..10] (+0x31B4)
    
    // 2. Read command buffer entries (32 × 20B at +0x5D8)
    //    and translate to draw calls
    
    // 3. Call native D3D11/D3D12:
    //    - ID3D11DeviceContext::IASetVertexBuffers
    //    - ID3D11DeviceContext::IASetInputLayout
    //    - ID3D11DeviceContext::VSSetShader
    //    - ID3D11DeviceContext::PSSetShader
    //    - ID3D11DeviceContext::Draw/DrawIndexed
    
    // 4. Skip original PM4 flush (return without calling original)
}
```

### Secondary: Command Buffer Entry Interception

For more fine-grained control, intercept `CommandBuffer_Push` (+0x822578F8)
and translate each entry individually.

### Tertiary: PM4 Ring Buffer Flush

For maximum compatibility, intercept the ring buffer submission and
parse the actual PM4 packet stream.

---

## Next Steps

1. **Map D3DDevice-to-GPUContext connection** — how does Device(+68) →
   GPU context? Trace `Object_GetGfxContext` usage.

2. **Extract render state enums** — determine what the u32 values in the
   render state arrays mean (blend mode, depth test, culling, etc.)

3. **Map shader constants** — trace where vertex/pixel shader constants
   are uploaded and how they map to Xenos GPU SQ registers.

4. **Build PM4 decoder** — create a decoder for the command buffer entries
   that translates each to a D3D11/12 operation.

5. **Prototype hook** — implement the first native rendering hook on
   GfxCmdBufSubmit with D3D11 output.

Priority order: 1 → 2+3 (parallel) → 4 → 5
