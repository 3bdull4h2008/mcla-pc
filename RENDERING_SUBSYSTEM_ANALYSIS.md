# MCLA Rendering Subsystem Deep Analysis — Native Rendering Guide

## Overview

The rendering pipeline follows this flow each frame:

```
Game Loop
  └─ Render_Update (0x826FD508, 18 calls)
       └─ Gets global render context → validates → gets render device
       └─ Calls vtable+0x38 (r4=frame, r5=deltaTime)
            └─ SceneGraphTraverseChildren (0x8268F078, 9 calls)
                 └─ For each render node:
                      RenderNode_ClassifyType → sort opaque/transparent/UI
                      RenderNodeComp → sort by material/shader/depth
                      RenderObject_InitDefaults
                      → Vertex buffer setup (VBufCreate / Mesh_LockVertexBuffer)
                      → Texture bind (Texture_Create / Gpu_TextureValidateSlot)
                      → Shader bind (Shader_BindDeviceContext / ShaderConstInit)
                      → Shader constants upload (Gpu_UploadMatrixConstants)
                      → Render state setup (RenderState_Setup / RendState_SetVector)
                      → gfxSetupDrawParams → gfx_submit_draw_call
                           └─ sub_825749E8 (19KB stack!)
                                └─ Builds vertex/index buffer data (sub_825745D8)
                                └─ Calls draw (sub_8220DBD8)
       └─ GfxCmdBufSubmit (0x8241BD08) → flushes dirty state to GPU
```

## 1. GPU Command Buffer System

### 1.1 Ring Buffer (sub_822578F8 - CommandBuffer_Push)

The command buffer is a 32-slot **ring buffer** with 20-byte entries.

**Structure layout** (relative to command buffer object base):
```
Offset  Size  Field
+1496   640B  Command entry array (32 entries × 20 bytes)
+2136   4B    Write counter 1 (entry index)
+2140   4B    Write counter 2
+2144   4B    Capacity counter (starts at 32, decrements on push)
+640    4B    Sub-entry index (relative to +1496 base)
+644    4B    Sub-entry index 2
+648    4B    Sub-entry count (increments on push)
```

**20-byte command entry format** (5 × uint32):
```
+0   uint32  type/command ID (hash or enum)
+4   uint32  parameter 1
+8   uint32  parameter 2
+12  uint32  parameter 3
+16  uint32  terminator flag (-1 = active, 0 = free)
```

**Push behavior:**
1. Checks if current segment has capacity (+2144)
2. If segment full (32 entries used), clears sub-indices and resets
3. Calculates entry position: `index = sub_idx * 5 * 4` → 20-byte stride
4. Writes terminator = -1 at +16 (marks entry as active)
5. Copies 5 dwords (20 bytes) from source to entry

**Ring buffer wrap:**
- When +2136 or +2140 reaches 32, it wraps by storing 0 at +640/+644
- This is a fixed-capacity ring (32 entries × 20B = 640B total payload)

### 1.2 Command Types

The command types are identified by a hash/ID at +0. From `RenderState_Setup` (0x821C7128):
- The type field is the first dword of each 20-byte entry
- States use it as a **parameter name hash**
- The render state system (`RendState_SetVector`) writes 4 consecutive entries for vector states (RGBA, XYZW)

## 2. PM4 Packet System (sub_8241BD08 - GfxCmdBufSubmit)

This is the **critical function for native rendering interception**. It writes PM4 packets directly to the GPU push buffer.

### 2.1 Dirty State Tracking

The GPU context (~13KB structure) maintains 5 parallel arrays for deferred state management:

```
Offset  Array          Purpose          Comparison offset
+12440  current[0]    Render states     +12728  (committed)
+12444  current[1]    Texture stages    +12732
+12448  current[2]    Sampler states    +12736
+12452  current[3]    VS constants      +12740
+12456  current[4]    PS constants      +12744
+10940  flags (1B)    Dirty flag byte
+12187  toggle (1B)   Force-update flag
+10932  uint32        Submit type/context ID
+10936  uint32        Reserved
+12708  uint32        PM4 payload word (write target)
+12712  uint32        Reserved
+12716  uint32        Command buffer head pointer
```

**Flag byte at +10940 bits:**
- Bit 0 (0x01): submit with r4=0 path (flush without context)
- Bit 1 (0x02): unknown
- Bit 2 (0x04): Depth/stencil state dirty
- Bit 3 (0x08): Blend state dirty
- Bit 4 (0x10): Scissor/test state dirty
- Bit 5 (0x20): Any render state array dirty
- Bits 6-7: unused

### 2.2 Submit Flow (r4=0 path — flush all dirty)

```
GfxCmdBufSubmit(ctx, 0):
  if (!dirty_flags && !toggle_flag && arrays_match):
    return early  (nothing to do)

  writes PM4 packet header 0xC0006000
  writes payload from +12708 (0xFFFFFFFF = flush)
  clears bit 0 of dirty_flags
  resets +12716 = 0
```

### 2.3 Submit Flow (r4≠0 path — submit context)

```
GfxCmdBufSubmit(ctx, r4):
  stw r4, +12708       → payload = r4
  stw 1, +12716        → set head pointer
  clears bit 0 of dirty_flags

  resizes push buffer if needed (calls sub_82412710 if r3 > +56)

  writes PM4 packet: 0xC0006000
  writes payload: r4 (from +12708)
  updates push buffer pointer
```

### 2.4 PM4 Packet Format

The GPU push buffer receives type-3 PM4 packets:

```
Header:  0xC0006000
  Bits [31:30] = 11        → Type-3 packet
  Bits [29:16] = 0         → Count = 0 (1 dword following)
  Bits [15:0]  = 0x6000    → Opcode (likely DECODER_CNTL or similar)

Payload: [value from +12708]
  r4=0 path:  0xFFFFFFFF (flush/counter reset)
  r4≠0 path:  context submit token
```

For native rendering, intercept `0xC0006000` packets in the push buffer and translate to native API calls.

## 3. Draw Call Submission (sub_825749E8)

This is the **largest function on the GPU path** (19KB stack frame). It's called from `gfx_submit_draw_call` with:

### 3.1 Parameters
```
r3 = context/device ptr
r4 = vertex buffer data (SIMD v1)
r5 = index buffer data (SIMD v2)
r6-r10 = misc params
Stack: +252 = paramA, +260 = paramB
```

### 3.2 Internal Flow
1. Saves caller state (gprs 25-31, fpr31, v126-v127)
2. Allocates **19168 bytes** on stack — processing buffer
3. Calls `sub_821C8FE0` — initialization of local state
4. Calls `sub_825745D8` — **vertex data processing** (processes 4096B of vertex + 4096B of index data into stack buffers at +128)
5. Based on r10 flag (byte), branches:
   - non-zero: calls `sub_8257DF80` (indexed draw — with index buffer)
   - zero: calls `sub_8257DF18` (non-indexed draw)
6. Calls `sub_8220DBD8` — **actual draw submission** with packed params:
   - r4-r9: various draw parameters
   - r10 = 1 (force flag)
   - Uses the +128 processing buffer
7. Cleanup: releases temporary state, returns result (likely handle/draw_id)

### 3.3 For Native Rendering

The function `sub_825745D8` is the **vertex/index buffer builder** — it packs vertex data from game format into a known output format at stack+128.

The key sub-calls to investigate for native rendering:
- `sub_825745D8` (0x825745D8) — pack vertices/indices
- `sub_8220DBD8` (0x8220DBD8) — submit draw with packed data
- `sub_8257DF80` (0x8257DF80) — indexed draw helper
- `sub_8257DF18` (0x8257DF18) — non-indexed draw helper

## 4. Render State Management

### 4.1 Individual State Set (sub_821C7128 - RenderState_Setup)
- Called **73 times** — heavily used
- Creates a 4-byte state entry from parameter name/ID (r4) and float value (f1)
- Writes into context allocation buffer at +8

### 4.2 Vector State Set (sub_825832C8 - RendState_SetVector)
- Sets 4 consecutive float values (RGBA, XYZW)
- Called **18 times** for material colors, etc.

### 4.3 State Initialization
- `RenderStateInit` (0x825734B0): sets factory defaults
- `GfxStateInit` (0x825A2E00): full state object with blend/depth modes
- `GfxObjectInit` (0x8224C408): GPU object format info

## 5. Texture Pipeline

### 5.1 Lifecycle
```
Texture_Create (0x821F3628)
  → allocates GPU memory, sets format/w/h/mips, returns handle
  
Gpu_TextureValidateSlot (0x82374B30)
  → checks slot 0-15 is active, re-uploads if dirty

Gfx_UploadMipData (0x82761F20)
  → uploads one mip level, handles format conversion

texture_write_pixels (0x821C70C8)
  → writes raw pixel data via sub_821C6D90 allocation
```

### 5.2 GPU Format Info
- `Gfx_CalcTexturePageSize` (0x8240F220): page size from format + dims
- `Gfx_CalcTextureSize` (0x8240F3C8): total memory from format + w + h + mips
- `GfxFormat_ToElementSize` (0x8240F2A8): format enum → byte size
- `Gfx_GetFormatSize` (0x82349570): format byte size

## 6. Vertex Pipeline

### 6.1 Lifecycle
```
Gfx_InitVertexDeclaration (0x821F6C50)
  → element format, stride, offset, semantic

VBufCreate (0x821B3CC0)
  → allocates GPU buffer with size/format

Mesh_LockVertexBuffer (0x821B40D0)
  → locks for CPU write, returns DMA-able pointer

gfxGetVertexBuffer (0x82509B28)
  → retrieves GPU handle from mesh/resource
```

### 6.2 SIMD Vertex Processing
- `VBufCopyAltiVec` (0x821B4D20): Altivec lvx/stvx copy
- `VertexBufferTransformSIMD` (0x82219BA0): matrix transform with SIMD
- `Vec_SkinTransform` (0x822030E0): **86 call sites** — most-used vertex function
- `Vec_VertexUnpack` (multiple): vertex format unpacking

## 7. Shader System

### 7.1 Binding
```
Shader_BindDeviceContext (0x82637DD8)
  → sets vertex/pixel shader handles in device context

ShaderConstInit (0x82583708)
  → initializes constant table: identity matrices, zero vectors, default colors

Gpu_UploadMatrixConstants (0x822192F8)
  → uploads WVP matrix set to shader constant buffer
```

### 7.2 Shader Constants Format
The constant arrays (+12452/+12740 for VS, +12456/+12744 for PS) contain packed float4 constants. When dirty, they're flushed to GPU via the same PM4 path.

## 8. Skinned Mesh Pipeline

### 8.1 Bone Processing Flow
```
SkinData_GetOffset448 → gets 448B bone offset block
SkinnedMesh_GetBoneMatrix → bone world matrix
SkinMatrixBlend → blends with weights
Vec_SkinTransform (86 sites!) → vertex-level transform
```

### 8.2 Matrix Palette
- `Math_MatrixMultiply` (0x822A9930): Altivec 4×4 multiply
- `MatrixCopyAltiVec` (0x822BFF40): aligned 16-byte copy with SIMD
- `matrix_skin_deform` (0x82563018): applies bind-pose inverse
- `AnimInterp_WriteBoneData` (0x82578A38): interpolates + writes bone buffer

## 9. Native Rendering Strategy

### 9.1 Interception Points

To implement native rendering in the recompiler, intercept these functions:

| Priority | Function | Address | What to Intercept |
|----------|----------|---------|-------------------|
| **1** | `Render_Update` | 0x826FD508 | Frame entry: create native render pass |
| **2** | `GfxCmdBufSubmit` | 0x8241BD08 | PM4 packet emission: translate to native API calls |
| **3** | `gfx_submit_draw_call` | 0x82574C38 | Draw submission: capture vertex/index data |
| **4** | `RenderState_Setup` | 0x821C7128 | State changes: track for native state objects |
| **5** | `CommandBuffer_Push` | 0x822578F8 | High-level command: translate to native commands |

### 9.2 Architecture

```
PowerPC Emulation (existing recomp)
  ↓ intercept
Native Render Wrapper
  ├─ State Tracker: mirrors +12440/+12444/... dirty arrays
  ├─ Vertex/Index Buffer Manager: captures locked buffer data
  ├─ Texture Manager: intercepts Create/Upload/Bind
  ├─ Shader Manager: translates game shaders to native
  └─ Draw Dispatcher: emits native draw calls (D3D12/Vulkan)
```

### 9.3 Critical Structures to Map

1. **GPU context** (~13KB): full structure layout with all array offsets
2. **Command buffer** (32 × 20B entries): the ring buffer format
3. **Vertex formats**: enumeration values and sizes
4. **Texture formats**: mapping from game enums to native
5. **Render state IDs**: the hash/ID values used by RenderState_Setup

### 9.4 First Steps for Implementation

1. **Hijack `GfxCmdBufSubmit`**: Replace the PM4 write with native state tracking
2. **Intercept `gfx_submit_draw_call`**: Capture vertex/index data and emit native draw
3. **Map `RenderState_Setup` states**: Create a table mapping game state hashes to native render states
4. **Extract shader constants** from the +12452/+12456 arrays

## 10. Key Address Reference

```
Function                    Address       Calls  Purpose
─────────────────────────────────────────────────────────────
Render_Update               0x826FD508    18     Main frame entry
SceneGraphTraverseChildren  0x8268F078     9     Scene traversal
GfxCmdBufSubmit             0x8241BD08    16     PM4 flush (critical)
CommandBuffer_Push          0x822578F8    13     Ring buffer push
CommandBuffer_AllocSegment  0x82411840     4     Render pass alloc
CommandBuffer_BeginRenderPass 0x824231B0  9     Begins render pass
gfx_submit_draw_call        0x82574C38     1     Draw submission
gfxSetupDrawParams          0x825286E8    10     Draw param setup
render_target_bind          0x8258B6C8     1     EDRAM target bind
RenderDevice_HardwareInit   0x8265F428     1     GPU init (once)
RenderDevice_GetCurrent     0x82553A18     1     Current device
RenderState_Setup           0x821C7128    73     Per-state set
RendState_SetVector         0x825832C8    18     Vector state set
RenderStateInit             0x825734B0     9     Default states
GfxStateInit                0x825A2E00    15     Full state object
GpuSetRenderState           0x82668660     9     High-level state
Shader_BindDeviceContext    0x82637DD8     1     Shader binding
ShaderConstInit             0x82583708     9     Constants init
Gpu_UploadMatrixConstants   0x822192F8    10     WVP upload
Texture_Create              0x821F3628     4     Texture creation
Gpu_TextureValidateSlot     0x82374B30    10     Slot validation
Gfx_UploadMipData           0x82761F20     6     Mip upload
Gfx_CalcTextureSize         0x8240F3C8     1     Memory calc
Gfx_InitVertexDeclaration   0x821F6C50     1     Vertex decl
VBufCreate                  0x821B3CC0     -     VB creation
Mesh_LockVertexBuffer       0x821B40D0    10     VB lock
gfxGetVertexBuffer          0x82509B28    13     VB handle get
gfxLightInit                0x82582C08    10     Light init
gfxSetFogParams             0x8218F308     8     Fog set
SkinData_GetOffset448       0x8217C568    13     Bone data
Skinning_MatrixBlend        0x8217C148    13     Matrix palette blend
Vec_SkinTransform           0x822030E0    86     Vertex skin
Math_MatrixMultiply         0x822A9930    18     4×4 multiply
SceneNode_UpdateTransform   0x821E6800   276     Node xform
```
