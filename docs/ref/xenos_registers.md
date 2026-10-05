# Xenos register layouts — decoded by hand, verified against the reference

> **Owner:** this file. Scanned tree: `HEAD = 8385925`, working tree **51 files changed, +35,286/−15,472**
> (uncommitted; `src/**` was being edited concurrently). Everything below was read from the
> `.research/xenia` checkout on 2026-09-28, not recalled.
>
> **Everything here is a cross-checked fact or is marked `UNVERIFIED`.** Each layout was read
> **twice**: once at the definition and once at a place the reference *uses* the bits
> (`draw_util.cc`, `d3d12/pipeline_cache.cc`, `vulkan/vulkan_pipeline_cache.cc`,
> `command_processor.cc`). A definition and its use that disagree are recorded as a finding.

## 0. Machine-checkable entry convention (tool-checkable)

Every field row in §1–§2 is emitted in this exact form so a validator can regex it:

```
<register>.<field> — `<file>:<declLine>` bit <lsb>, width <w>
```

* `file` is relative to `.research/xenia/src/xenia/gpu/` (or `gpu/../` for `memory.cc`).
* `declLine` is the **declaration line**, not the nearest comment. `registers.h:461` is the
  comment `// 0 - front is CCW, 1 - front is CW.`; the declaration is `registers.h:462`.
  A tool that anchors on the comment line will pass on a struct that has drifted by one line.
* `bit` is the LSB, `width` is the declared `:N`.
* Sum of widths per register **must** be exactly 32. Sum of `(bit + width)` must be 32.
* `PA_SU_SC_MODE_CNTL.face — registers.h:462 bit 2, width 1`

Lines that are context notes, not field rows, are prefixed `>` and a checker must skip them.

## 1. The register file: size, address map, aliases

### 1.1 Index space

| fact | value | anchor |
|---|---|---|
| register count | `0x5003` = 20,483 dwords | `register_file.h:40` |
| highest **active** table index | `0x5002` `SHADER_CONSTANT_FLUSH_FETCH_2` | `register_table.inc:2934` |
| `0x8D07 UNKNOWN_8D07` | **commented out**, not a register | `register_table.inc:2944` |
| type-0 base index field | 15 bits, `packet & 0x7FFF` | `command_processor.cc:651` |
| type-0 count field | 14 bits, `(packet >> 16) & 0x3FFF` | `command_processor.cc:641` |
| type-0 "write one reg" flag | bit 15 | `command_processor.cc:652` |
| type-1 fields | two 11-bit indices (`& 0x7FF`, `(>>11) & 0x7FF`) | `command_processor.cc:667-668` |
| type-2 | no-op | `command_processor.cc:677-683` |
| type-3 opcode / count | 7 bits at `(packet>>8)&0x7F`; 14-bit count; bit 0 = predicate | `command_processor.cc:687-688`, `xenos.h:1657-1663` |
| RMW index field | 13 bits, `& 0x1FFF` | `command_processor.cc:1050-1065` |

### 1.2 Banks (all indices are dwords; `register_table.inc` is authoritative)

| index range | bank | anchor | reached by |
|---|---|---|---|
| `0x0000–0x0FFF` | CP / BIF / RBBM / HZ / perfcounters (sparse: `0x0048`, `0x01DC`, `0x01DD`, `0x01E6-8`, `0x01F5`, `0x0395-A`, `0x0578`, `0x057F`, `0x0A31`) | `register_table.inc:34-91` | MMIO, PM4 |
| `0x1000–0x1FFF` | HZ + display/Avivo/D1/LUT (`0x1004-9`, `0x1838`, `0x1841`, `0x1844`, `0x1852`, `0x1921-30`, `0x1961-73`) | `register_table.inc:~380-470` | MMIO, PM4 |
| `0x2000–0x2FFF` | **3D rendering registers** (PA_SU / PA_CL / PA_SC / RB_ / VGT_ / SQ_) | `register_table.inc:480-645` | MMIO **and** PM4 `SET_CONSTANT` type 4 |
| `0x2300–0x23FF` | 3D sub-block: `PA_SU_VTX_CNTL`, `SQ_VS_CONST`, `SQ_PS_CONST`, `PA_SU_POLY_OFFSET_*`, `PA_CL_UCP_0..5_*` | `register_table.inc:563-645` | MMIO, PM4 |
| `0x4000–0x41FF` | **ALU constant bank** `SHADER_CONSTANT_000_X … 127_W` — 512 dwords = 128 vec4, all `kFloat` | `register_table.inc:648-1159` | **PM4 only** (`index += 0x4000`, `command_processor.cc:1439`) |
| `0x4800–0x48BF` | **FETCH / VB** `SHADER_CONSTANT_FETCH_00_0 … 31_5` — 192 dwords, 6 per slot, 32 slots | `register_table.inc:2697-2888` | **PM4 only** (`index += 0x4800`, `command_processor.cc:1442`) |
| `0x4900–0x4903` | **BOOL** `SHADER_CONSTANT_BOOL_000_031 … 096_127` — 128 bools, 32 packed per dword | `register_table.inc:2890-2893` | PM4 (`index += 0x4900`, `:1445`) |
| `0x4908–0x4927` | **LOOP** `SHADER_CONSTANT_LOOP_00 … 31` — 32 dwords | `register_table.inc:2899-2930` | PM4 (`index += 0x4908`, `:1448`) |
| `0x5000–0x5002` | `SHADER_CONSTANT_FLUSH_FETCH_0..2` | `register_table.inc:2932-2934` | **UNVERIFIED** — no `SET_CONSTANT` type yields this directly |

> **Trap (this is the whole `_SHADER_REGISTERS` question).** `SET_CONSTANT` (`0x2D`) and
> `LOAD_ALU_CONSTANT` (`0x2F`) take an `offset_type` dword and **add a per-type base to the
> index** (`command_processor.cc:1434-1457`, `:1481-1507`): type 0 ALU `+0x4000`, type 1 FETCH
> `+0x4800`, type 2 BOOL `+0x4900`, type 3 LOOP `+0x4908`, type 4 REGISTERS `+0x2000`. The index
> field is **11 bits** (`& 0x7FF`, `:1435`) for both packets, and the type byte is
> `(offset_type >> 16) & 0xFF`. An "11-bit index" means an offset into a bank, *not* a register
> index — the same dword `0x0000_0000` is `SHADER_CONSTANT_000_X` at type 0,
> `SHADER_CONSTANT_FETCH_00_0` at type 1, `SHADER_CONSTANT_BOOL_000_031` at type 2, and
> `RB_SURFACE_INFO` at type 4. **There is no `_SHADER_REGISTERS` symbol in this checkout**
> (`git grep _SHADER_REGISTERS -- src/` = 0 hits); the context-dependence is real but it is
> implemented as this type→base switch, not as a named mode. `SET_CONSTANT2` (`0x55`) has **no
> type split**: raw 16-bit index (`:1469`).
>
> `SET_CONSTANT2` and `SET_SHADER_CONSTANTS` (`0x56`) take `& 0xFFFF` (`:1469`, `:1519+`).

### 1.3 The two MMIO aliases — and the uncached-alias question

Xenia registers **exactly one** MMIO virtual range:

```
memory_->AddVirtualMappedRange(0x7FC80000, 0xFFFF0000, 0x0000FFFF, …)   graphics_system.cc:92-95
uint32_t r = (addr & 0xFFFF) / 4;                                        graphics_system.cc:182 (read), :208 (write)
```

Consequences that follow from those two lines alone:

1. The window is **64 KB**, so through MMIO only indices `0x0000–0x3FFF` are addressable.
   **Indices `≥ 0x4000` (ALU constants, the whole `0x4800` fetch block, BOOL, LOOP) are
   unreachable by a guest MMIO store** and exist only via PM4 packets. Any code that expects
   the guest to poke `0x4800` directly is wrong.
2. The register index is `(addr & 0xFFFF) / 4` — a **pure window offset**. There is no
   sub-block decode and no bank select in the address.
3. **The reference registers no uncached alias at all.** `graphics_system.cc:92` is the only
   `AddVirtualMappedRange` call for the GPU, and `git grep "FFC8" -- src/xenia/gpu/` = 0 hits.
   `Memory::LookupHeap` (`memory.cc:329-333`) puts `0xFFC80000` in the `vE0000000` **physical
   4 KB-page window** (`0xE0000000–0xFFCFFFFF`, `memory.cc:50`), i.e. `0xFFC80000` is a *guest
   virtual address backed by a physical 4 KB-page view*, not a GPU register aperture.

**The project's convention and what it should be.**

`src/gpu_cp.cpp:1175-1177`
```cpp
inline uint32_t PhysToKernelVA(uint32_t addr) {
  return addr < 0x20000000u ? (addr | 0xC0000000u) : addr;
}
```

* **Correct as far as it goes.** The reference memory map (`memory.cc:41-51`) documents three
  kernel aliases of the same physical space: `0xA0000000–0xBFFFFFFF` (64 KB pages),
  `0xC0000000–0xDFFFFFFF` (16 MB pages), `0xE0000000–0xFFCFFFFF` (4 KB pages).
  `phys | 0xC0000000` for `phys < 0x20000000` lands in the 16 MB-page window — a real alias.
  The `phys < 0x20000000` guard is a *project* restriction (it assumes the guest's low 512 MB
  is the only thing needing translation); the reference would alias anything in the physical
  range.
* **`0xC0000000` is one of three, not the only one.** `phys | 0xE0000000` (4 KB-page alias) is
  equally valid per `memory.cc:50` and **is the alias the GPU MMIO window itself lives on**
  (`0xFFC80000` sits in `vE0000000`). A `TranslatePhysical` that happens to hand back
  `0xE…` will be left unchanged by the project's function, which is a silent miss.
* **The uncached alias is unhandled, and the audit is right.** All four live gates are keyed on
  the **cached** window only:
  * `src/guest_memory.cpp:346` — `ReadU32BE` gate `(guestAddr & 0xFFFF0000u) == 0x7FC80000u`
  * `src/guest_memory.cpp:431` — `WriteU32BE` gate, identical test
  * `src/gpu_cp.cpp:2858` — `CpMmioWrite` re-gate `(guestAddr & kMmioMask) != kMmioBase`
  * `src/gpu_cp.cpp:2989` — `CpMmioRead` re-gate, identical
  A doorbell rung at `0xFFC80000 + 0x714` (`= 0xFFC80714`) is **dropped by all four**, and the
  ring never advances. Note `src/gpu_mmio.cpp:85-86` *does* test both windows — but that is
  `MmioAddrSpace`, a classifier inside a hook that `gpu_mmio.cpp:6-30` itself measures as
  **dead** (0 occurrences, no caller). So the project's only `0xFFC80000` handling is on a code
  path that never runs. That is the defect: the classifier knows about the alias and no gate does.
* **What the project should do:** widen each of the four gates to
  `(addr & 0xFFFF0000u) == 0x7FC80000u || (addr & 0xFFFF0000u) == 0xFFC80000u` and normalise
  `offset = (addr & 0xFFFF)` so both windows feed one `kMmioBase`-relative path. Do **not**
  widen `PhysToKernelVA`'s guard to fold `0x7FC80000` into it — `0x7FC80000 ≥ 0x20000000`, so
  the function must keep returning the MMIO window unchanged, and the two alias families are
  unrelated.
* **`UNVERIFIED`:** whether *this title* ever rungs the doorbell at `0xFFC80000`. The reference
  cannot answer it (no alias registered). The measurement that settles it: instrument the
  already-existing failing accessor, or watch the `kWatchRange`/page-watch path for stores into
  `0xFFC80000..0xFFC8FFFF` and count. Until measured, the widening is a cheap correct-by-the-map
  change, not a proven fix.

### 1.4 The doorbell register

`0x01C5` is **not in `register_table.inc`** — it is named only in a switch comment and handled
by the callback:

```
case 0x01C5:  // CP_RB_WPTR          graphics_system.cc:211
  command_processor_->UpdateWritePointer(value);
```
`UpdateWritePointer` honours the same sentinel the project uses: `write_ptr_index == 0xBAADF00D`
(`command_processor.cc:210`, `:229`). Project: `src/gpu_cp.cpp:30-40`
(`kMmioBase = 0x7FC80000`, `kWptrByteOffset = 0x01C5*4 = 0x714`, `kWptrSentinel = 0xBAADF00D`).
**Confirmed correct**, including the sentinel. Consequence of §1.3.1: because `0x01C5 < 0x4000`
the doorbell *is* MMIO-addressable — the guest rungs it with an ordinary store, not a packet.

## 2. Bit tables

### 2.1 `PA_SU_SC_MODE_CNTL` — index `0x2205` (`register_table.inc:541`)

| field | bits | width | meaning | anchor | cross-check |
|---|---|---|---|---|---|
| `cull_front` | 0 | 1 | cull front faces | `registers.h:459` | `d3d12/pipeline_cache.cc:1461-1465` → `kFront`; `draw_util.cc:102` gates front bias on it |
| `cull_back` | 1 | 1 | cull back faces | `registers.h:460` | `d3d12/pipeline_cache.cc:1466-1469` → `kBack` |
| `face` | 2 | 1 | 0 = front is CCW, 1 = CW | `registers.h:462` (comment `:461`) | `d3d12/pipeline_cache.cc:1460` region |
| `poly_mode` | 3–4 | 2 | `PolygonModeEnable` (`xenos.h:846-853`): 0 `kDisabled`=triangles, 1 `kDualMode`, 2/3 **undefined** | `registers.h:467` | `d3d12/pipeline_cache.cc:1488-1490` — `!= kDualMode` **clears** wireframe, so the ptype fields are read *only* in dual mode |
| `polymode_front_ptype` | 5–7 | 3 | `PolygonType` (`xenos.h:855-859`): 0 points, 1 lines, 2 triangles | `registers.h:468` | `d3d12/pipeline_cache.cc:1476-1479` — `!= kTriangles` ⇒ wireframe |
| `polymode_back_ptype` | 8–10 | 3 | as above, back | `registers.h:469` | `d3d12/pipeline_cache.cc:1483-1486` |
| `poly_offset_front_enable` | 11 | 1 | front depth-bias enable | `registers.h:470` | `draw_util.cc:101` |
| `poly_offset_back_enable` | 12 | 1 | back depth-bias enable | `registers.h:471` | `draw_util.cc:106` |
| `poly_offset_para_enable` | 13 | 1 | enables the front bias for **non-polygonal** primitives | `registers.h:472` | `draw_util.cc:111-117` |
| `_pad_14` | 14 | 1 | — | `registers.h:473` | — |
| `msaa_enable` | 15 | 1 | MSAA rasterise | `registers.h:474` | — |
| `vtx_window_offset_enable` | 16 | 1 | apply `PA_SC_WINDOW_OFFSET` | `registers.h:475` | — |
| `_pad_17` | 17–18 | 2 | — | `registers.h:477` | — |
| `provoking_vtx_last` | 19 | 1 | provoking vertex = last | `registers.h:478` | — |
| `persp_corr_dis` | 20 | 1 | perspective-correction disable | `registers.h:479` | — |
| `multi_prim_ib_ena` | 21 | 1 | multi-primitive IB | `registers.h:480` | `VGT_MULTI_PRIM_IB_RESET_INDX` exists (`registers.h:343`) |
| `_pad_22` | 22 | 1 | — | `registers.h:481` | — |
| `quad_order_enable` | 23 | 1 | quad ordering | `registers.h:482` | — |
| `sc_one_quad_per_clock` | 24 | 1 | one quad/clock | `registers.h:483` | — |
| `_pad_25` | 25–31 | 7 | — | `registers.h:486` | — |

> **Context-dependence:** `poly_mode` gates the meaning of the two `ptype` fields
> (`d3d12/pipeline_cache.cc:1476-1490`). Reading `ptype` without reading `poly_mode` is a
> definition-and-use disagreement, and the reference is explicit: `registers.h:463-466` records
> that title 4541096E sets `poly_mode = 2` (undefined) with `ptype = 0` and **still wants filled
> triangles** — so for any `poly_mode != kDualMode`, the ptype fields must be ignored.

### 2.2 `PA_CL_CLIP_CNTL` — index `0x2204` (`register_table.inc:540`)

| field | bits | width | meaning | anchor | cross-check |
|---|---|---|---|---|---|
| `ucp_ena_0` … `ucp_ena_5` | 0,1,2,3,4,5 | 1 ea | user clip plane 0..5 enable | `registers.h:539-544` | also exposed as a single 6-bit `ucp_ena` view, `registers.h:558-560` |
| `_pad_6` | 6–13 | 8 | — | `registers.h:545` | — |
| `ps_ucp_mode` | 14–15 | 2 | pixel-shader UCP mode | `registers.h:546` | — |
| `clip_disable` | 16 | 1 | **disable** clipping | `registers.h:547` | `d3d12/pipeline_cache.cc:1508` — `depth_clip = !clip_disable` |
| `ucp_cull_only_ena` | 17 | 1 | cull only, no clip | `registers.h:548` | — |
| `boundary_edge_flag_ena` | 18 | 1 | boundary-edge flag | `registers.h:549` | — |
| `dx_clip_space_def` | 19 | 1 | DirectX clip-space convention | `registers.h:550` | — |
| `dis_clip_err_detect` | 20 | 1 | disable clip-error detect | `registers.h:551` | — |
| `vtx_kill_or` | 21 | 1 | vertex kill OR | `registers.h:552` | — |
| `xy_nan_retain` | 22 | 1 | retain NaN in xy | `registers.h:553` | — |
| `z_nan_retain` | 23 | 1 | retain NaN in z | `registers.h:554` | — |
| `w_nan_retain` | 24 | 1 | retain NaN in w | `registers.h:555` | — |
| `_pad_25` | 25–31 | 7 | — | `registers.h:556` | — |

The reference registers the user clip planes from R3xx and notes title 4D5307E6 uses them
(`registers.h:537-538`).

### 2.3 `PA_CL_VTE_CNTL` — index `0x2206` (`register_table.inc:542`)

| field | bits | width | meaning | anchor | cross-check |
|---|---|---|---|---|---|
| `vport_x_scale_ena` | 0 | 1 | apply `PA_CL_VPORT_XSCALE` (0x210F) | `registers.h:569` | — |
| `vport_x_offset_ena` | 1 | 1 | apply `PA_CL_VPORT_XOFFSET` (0x2110) | `registers.h:570` | — |
| `vport_y_scale_ena` | 2 | 1 | `PA_CL_VPORT_YSCALE` (0x2111) | `registers.h:571` | — |
| `vport_y_offset_ena` | 3 | 1 | `PA_CL_VPORT_YOFFSET` (0x2112) | `registers.h:572` | — |
| `vport_z_scale_ena` | 4 | 1 | `PA_CL_VPORT_ZSCALE` (0x2113) | `registers.h:573` | — |
| `vport_z_offset_ena` | 5 | 1 | `PA_CL_VPORT_ZOFFSET` (0x2114) | `registers.h:574` | — |
| `_pad_6` | 6–7 | 2 | — | `registers.h:575` | — |
| `vtx_xy_fmt` | 8 | 1 | vertex xy format | `registers.h:576` | — |
| `vtx_z_fmt` | 9 | 1 | vertex z format | `registers.h:577` | — |
| `vtx_w0_fmt` | 10 | 1 | vertex w0 format | `registers.h:578` | — |
| `perfcounter_ref` | 11 | 1 | perfcounter reference | `registers.h:579` | — |
| `_pad_12` | 12–31 | 20 | — | `registers.h:580` | — |

> **This register carries no extents.** The six scale/offset *values* are six separate `kFloat`
> registers `0x210F–0x2114` (`register_table.inc:516-521`). The measured `0x2206 = 0x00000300`
> (`build/w658.log`, per `src/renderer/pipeline_cache.cpp:358-361`) is `vtx_xy_fmt | vtx_z_fmt`
> — all six viewport enables are **clear**, so this title does **not** apply a viewport
> transform through this path. A decoder that reads `0x00000300` as "viewport enabled" is wrong.

### 2.4 Depth-bias magnitudes — the names in the brief do not exist

**`RB_DEPTHF_INFO` and `PA_SU_OFFSET_*` are not Xenos registers.**
`git grep "DEPTHF\|PA_SU_OFFSET" -- src/xenia/gpu/` = 0 hits. The polygon/depth bias on Xenos is
**four `kFloat` registers**, and the enables are the three bits in §2.1:

| register | index | anchor | use |
|---|---|---|---|
| `PA_SU_POLY_OFFSET_FRONT_SCALE` | `0x2380` | `register_table.inc:615` | `draw_util.cc:103`, `:115` |
| `PA_SU_POLY_OFFSET_FRONT_OFFSET` | `0x2381` | `register_table.inc:616` | `draw_util.cc:104`, `:116` |
| `PA_SU_POLY_OFFSET_BACK_SCALE` | `0x2382` | `register_table.inc:617` | `draw_util.cc:108` |
| `PA_SU_POLY_OFFSET_BACK_OFFSET` | `0x2383` | `register_table.inc:618` | `draw_util.cc:109` |

They are **floats, absolute offsets**, not bitfields. `draw_util.h:121-138` is emphatic: D3D9/Xenos
polygon offset is an *absolute* floating-point value, and D3D10+ takes a *relative* one, so
lowering requires `GetD3D10IntegerPolygonOffset(regs.Get<reg::RB_DEPTH_INFO>().depth_format, …)`
(`d3d12/pipeline_cache.cc:1500-1503`) and the slope scale is converted by
`xenos::kPolygonOffsetScaleSubpixelUnit = 1/16` (`xenos.h:407`, `d3d12/pipeline_cache.cc:1503`).
**`RB_DEPTH_INFO` supplies the depth *format* for that conversion, never the bias magnitude.**

Selection rule (`draw_util.cc:93-121`), which is the second cross-check: for polygonal
primitives take FRONT if `poly_offset_front_enable && !cull_front`, else BACK if
`poly_offset_back_enable && !cull_back` and front yielded nothing; for **non**-polygonal take
FRONT gated on `poly_offset_para_enable` instead.

### 2.5 `RB_DEPTH_INFO` — index `0x2002` (`register_table.inc:482`)

| field | bits | width | meaning | anchor | cross-check |
|---|---|---|---|---|---|
| `depth_base` | 0–10 | 11 | depth EDRAM tile base (**tiles**, not bytes) | `registers.h:841` | `registers.h:838-840` explains the R400 12-bit field was split for Xenos' periodic 11-bit EDRAM addressing |
| `depth_base_bit_11` | 11 | 1 | the 12th address bit, split out | `registers.h:842` | same |
| `_pad_12` | 12–15 | 4 | — | `registers.h:843` | — |
| `depth_format` | 16 | 1 | `DepthRenderTargetFormat` (`xenos.h:367-371`): 0 `kD24S8`, 1 `kD24FS8` (20e4, range [0,2)) | `registers.h:844` | `d3d12/pipeline_cache.cc:1500-1501` |
| `_pad_17` | 17–31 | 15 | — | `registers.h:845` | — |

> **Do not read `depth_base` as a byte address.** 11 bits *of tiles*.

### 2.6 `RB_COLOR_INFO` — index `0x2001` (`register_table.inc:481`)

Same layout for `RB_COLOR1_INFO` `0x2003`, `RB_COLOR2_INFO` `0x2004`, `RB_COLOR3_INFO` `0x2005`
(`registers.h:750-751`).

| field | bits | width | meaning | anchor | cross-check |
|---|---|---|---|---|---|
| `color_base` | 0–10 | 11 | color EDRAM tile base (tiles) | `registers.h:742` | as §2.5 |
| `color_base_bit_11` | 11 | 1 | 12th address bit, split out | `registers.h:743` | — |
| `_pad_12` | 12–15 | 4 | — | `registers.h:744` | — |
| `color_format` | 16–19 | 4 | `ColorRenderTargetFormat` (`xenos.h:299-319`) — **note: 4 bits, sparse** | `registers.h:745` | `kColorRenderTargetFormatBits = 4` (`xenos.h:409`) |
| `color_exp_bias` | 20–25 | 6 | signed (int32) EDRAM exponent bias | `registers.h:746` | — |
| `_pad_26` | 26–31 | 6 | — | `registers.h:747` | — |

`ColorRenderTargetFormat` values: `0` `k_8_8_8_8`, `1` `k_8_8_8_8_GAMMA`, `2` `k_2_10_10_10`,
`3` `k_2_10_10_10_FLOAT` (7e3, RGB in [0,32), unorm alpha), `4` `k_16_16` (fixed, −32…32),
`5` `k_16_16_16_16`, `6` `k_16_16_FLOAT`, `7` `k_16_16_16_16_FLOAT`, `10`
`k_2_10_10_10_AS_10_10_10_10`, `12` `k_2_10_10_10_FLOAT_AS_16_16_16_16`, `14` `k_32_FLOAT`,
`15` `k_32_32_FLOAT`. **Values 8, 9, 11, 13 are unassigned** — 4 bits wide, 12 values used.
`GetStorageColorFormat` (`xenos.h:355-365`) strips the `AS_` precision modifiers; a host RT
must be created with the storage format or blending precision differs.

### 2.7 Blend — again, the brief's `PA_BLEND_*` does not exist

`git grep "PA_BLEND" -- src/xenia/gpu/` = 0 hits. The real names:

| register | index | anchor |
|---|---|---|
| `RB_BLENDCONTROL0` | `0x2201` | `register_table.inc:537` |
| `RB_BLENDCONTROL1` | `0x2209` | `register_table.inc:545` |
| `RB_BLENDCONTROL2` | `0x220A` | `register_table.inc:546` |
| `RB_BLENDCONTROL3` | `0x220B` | `register_table.inc:547` |
| `RB_BLEND_RED/GREEN/BLUE/ALPHA` | `0x2105–0x2108`, `kFloat` | `register_table.inc:506-509` |

`RB_BLENDCONTROL` layout (`registers.h:780-797`; `[0-3]` share it, `registers.h:793-795`):

| field | bits | width | meaning | anchor |
|---|---|---|---|---|
| `color_srcblend` | 0–4 | 5 | `BlendFactor` | `registers.h:783` |
| `color_comb_fcn` | 5–7 | 3 | `BlendOp` | `registers.h:784` |
| `color_destblend` | 8–12 | 5 | `BlendFactor` | `registers.h:785` |
| `_pad_13` | 13–15 | 3 | — | `registers.h:786` |
| `alpha_srcblend` | 16–20 | 5 | `BlendFactor` | `registers.h:787` |
| `alpha_comb_fcn` | 21–23 | 3 | `BlendOp` | `registers.h:788` |
| `alpha_destblend` | 24–28 | 5 | `BlendFactor` | `registers.h:789` |
| `_pad_29` | 29–31 | 3 | Adreno-only `BLEND_FORCE*` | `registers.h:790-791` |

`BlendFactor` (`xenos.h:708-725`): `0` kZero, `1` kOne, `4` kSrcColor, `5` kOneMinusSrcColor,
`6` kSrcAlpha, `7` kOneMinusSrcAlpha, `8` kDstColor, `9` kOneMinusDstColor, `10` kDstAlpha,
`11` kOneMinusDstAlpha, `12` kConstantColor, `13` kOneMinusConstantColor, `14` kConstantAlpha,
`15` kOneMinusConstantAlpha, `16` kSrcAlphaSaturate. **Values 2 and 3 are unassigned** in a
5-bit field. `BlendOp` (`xenos.h:727-733`): `0` kAdd, `1` kSubtract, `2` kMin, `3` kMax,
`4` kRevSubtract.

### 2.8 Depth/stencil state — `RB_DEPTHCONTROL` `0x2200` (`registers.h:799-820`)

| field | bits | width | anchor | note |
|---|---|---|---|---|
| `stencil_enable` | 0 | 1 | `registers.h:802` | |
| `z_enable` | 1 | 1 | `registers.h:803` | `draw_util.cc:75-81` additionally forces this **off** when `zfunc == kAlways` |
| `z_write_enable` | 2 | 1 | `registers.h:804` | |
| `_pad_3` | 3 | 1 | `registers.h:806` | Adreno `EARLY_Z_ENABLE`, never set by X360 titles |
| `zfunc` | 4–6 | 3 | `registers.h:807` | `CompareFunction` |
| `backface_enable` | 7 | 1 | `registers.h:808` | |
| `stencilfunc` | 8–10 | 3 | `registers.h:809` | |
| `stencilfail` | 11–13 | 3 | `registers.h:810` | `StencilOp` |
| `stencilzpass` | 14–16 | 3 | `registers.h:811` | |
| `stencilzfail` | 17–19 | 3 | `registers.h:812` | |
| `stencilfunc_bf` | 20–22 | 3 | `registers.h:813` | |
| `stencilfail_bf` | 23–25 | 3 | `registers.h:814` | |
| `stencilzpass_bf` | 26–28 | 3 | `registers.h:815` | |
| `stencilzfail_bf` | 29–31 | 3 | `registers.h:816` | |

`CompareFunction` (`xenos.h:685-694`): 0 kNever, 1 kLess, 2 kEqual, 3 kLessEqual, 4 kGreater,
5 kNotEqual, 6 kGreaterEqual, 7 kAlways. `StencilOp` (`xenos.h:696-705`): 0 kKeep, 1 kZero,
2 kReplace, 3 kIncrementClamp, 4 kDecrementClamp, 5 kInvert, 6 kIncrementWrap,
7 kDecrementWrap.

> **Per-face stencil is a same-width swap, not a different register.** `d3d12/pipeline_cache.cc:1522-1530`
> chooses `RB_STENCILREFMASK_BF` (`0x210C`) over `RB_STENCILREFMASK` (`0x210D`) on
> `backface_enable && cull_front`. `RB_STENCILREFMASK` layout (`registers.h:822-833`):
> `stencilref` 0–7, `stencilmask` 8–15, `stencilwritemask` 16–23, `_pad_24` 24–31.
> D3D12 cannot express both, so the reference **drops one** — the project must refuse, not pick.

### 2.9 The `SQ_*` constant-bank registers

| register | index | field | bits | width | meaning | anchor | use |
|---|---|---|---|---|---|---|---|
| `SQ_VS_CONST` | `0x2307` (`register_table.inc:578`) | `base` | 0–8 | 9 | first VS vec4 slot in the ALU bank | `registers.h:259` | `draw_util.cc:658-660` |
| | | `_pad_9` | 9–11 | 3 | — | `registers.h:260` | |
| | | `size` | 12–20 | 9 | vec4 count **minus one** | `registers.h:262` | |
| | | `_pad_21` | 21–31 | 11 | — | `registers.h:263` | |
| `SQ_PS_CONST` | `0x2308` (`register_table.inc:579`) | identical | | | | `registers.h:270-281` | |

Both are **9-bit, stored-minus-one** — the classic off-by-one. `size` = 0 means 1 vec4.
There is no `SQ_PS_CONST`/`SQ_VS_CONST` "count" elsewhere: `SQ_PROGRAM_CNTL.vs_num_reg` /
`.ps_num_reg` (`registers.h:134`, `:136`, 6-bit, minus one) is the **register** count for the
program, a different quantity. Do not cross-multiply them.

`SQ_PROGRAM_CNTL` `0x2180` (`register_table.inc:523`, `registers.h:127-150`):
`vs_num_reg` 0–5 (−1), `_pad_6` 6–7, `ps_num_reg` 8–13 (−1), `_pad_14` 14–15,
`vs_resource` 16, `ps_resource` 17, `param_gen` 18, `gen_index_pix` 19,
`vs_export_count` 20–23 (interpolator count −1), `vs_export_mode` 24–26, `ps_export_mode` 27–30,
`gen_index_vtx` 31. `registers.h:131-133` records that the 8-bit fields in Freedreno's
`a2xx.xml` are **wrong** — 6-bit, and games never set bits 7:6. Trust `yamato_registers.h`.

### 2.10 `VGT_DRAW_INITIATOR` `0x21FC` (`register_table.inc:533`, `registers.h:311-331`)

| field | bits | width | meaning | anchor |
|---|---|---|---|---|
| `prim_type` | 0–5 | 6 | `PrimitiveType` (§4) | `registers.h:315` |
| `source_select` | 6–7 | 2 | `SourceSelect`: 0 kDMA, 1 kImmediate, 2 kAutoIndex | `registers.h:316`, `xenos.h:743-747` |
| `major_mode` | 8–9 | 2 | `MajorMode` | `registers.h:322`, `xenos.h:750` |
| `_pad_10` | 10 | 1 | — | `registers.h:323` |
| `index_size` | 11 | 1 | 16/32-bit indices | `registers.h:324` |
| `not_eop` | 12 | 1 | suppress end-of-packet | `registers.h:325` |
| `_pad_13` | 13–15 | 3 | — | `registers.h:326` |
| `num_indices` | 16–31 | 16 | index count (or patch count under tessellation) | `registers.h:327` |

`registers.h:317-321`: on Xenos bit 8-9 is **MAJOR_MODE** (as on R600), *not* Adreno's
`FACENESS_CULL_SELECT`. `VGT_OUTPUT_PATH_CNTL` (`0x2284`) is **ignored** in implicit major mode
when tessellation is on.

`VGT_DMA_SIZE` `0x21FB` (`registers.h:301-309`): `num_words` 0–23 (24), `_pad_24` 24–29,
`swap_mode` 30–31 (`Endian`: 0 kNone, 1 k8in16, 2 k16in32, 3 k8in32 — `xenos.h:193-198`).
`VGT_DMA_BASE` `0x21FA` (`register_table.inc:531`).
`VGT_INDX_OFFSET` `0x2102`: `indx_offset` 0–23, 24-bit, unsigned (`registers.h:362-377`).
Order of operations is fixed: **primitive-restart index check → offsetting → clamping**
(`registers.h:340-341`).

## 3. The `0x4800–0x48BF` fetch/VB block — and the "fetch-shader program" premise

`SHADER_CONSTANT_FETCH_00_0` `0x4800` (`register_table.inc:2697`) …
`SHADER_CONSTANT_FETCH_31_5` `0x48BF` (`register_table.inc:2888`): **192 dwords, 32 slots × 6.**
Reached only by `SET_CONSTANT`/`LOAD_ALU_CONSTANT` type 1 (`command_processor.cc:1442`, `:1493`).
The index is 11 bits and the block base is `0x4800`, so an 11-bit offset can address the whole
block with no wrap.

### 3.1 Texture fetch slot — 6 dwords, `xe_gpu_texture_fetch_t` (`xenos.h:1184-…`)

| dword | field | bits within dword | width | meaning | anchor |
|---|---|---|---|---|---|
| 0 | `type` | 0–1 | 2 | `FetchConstantType`: 0 kInvalidTexture, 1 kInvalidVertex, 2 kTexture, 3 kVertex | `xenos.h:1194`, `xenos.h:1102-1107` |
| 0 | `sign_x/y/z/w` | 2–3, 4–5, 6–7, 8–9 | 2 ea | `TextureSign`: 0 kUnsigned, 1 kSigned, 2 kUnsignedBiased, 3 kGamma | `xenos.h:1202-1205`, enum `xenos.h:121-129` |
| 0 | `clamp_x/y/z` | 10–12, 13–15, 16–18 | 3 ea | `ClampMode` 0..7 | `xenos.h:1206-1208`, `xenos.h:104-113` |
| 0 | `_pad_0_19` | 19–21 | 3 | — | `xenos.h:1209` |
| 0 | `pitch` | 22–30 | 9 | base row pitch in **pixels** (not blocks) `>> 5` | `xenos.h:1222` |
| 0 | `tiled` | 31 | 1 | 0 = linear, 1 = tiled | `xenos.h:1223` |
| 1 | `format` | 0–5 | 6 | `TextureFormat` | `xenos.h:1225` |
| 1 | `endianness` | 6–7 | 2 | `Endian` | `xenos.h:1226` |
| 1 | `request_size` | 8–9 | 2 | bytes per element per request | `xenos.h:1227` |
| 1 | `stacked` | 10 | 1 | 2D array | `xenos.h:1228` |
| 1 | `nearest_clamp_policy` | 11 | 1 | d3d/opengl | `xenos.h:1229` |
| 1 | `base_address` | 12–31 | 20 | `>> 12` (12-bit subresource alignment) | `xenos.h:1230`, `xenos.h:1132` |
| 2 | `size_1d` / `size_2d` / `size_3d` | union | 24 / 32 / 32 | **each component stored minus one** | `xenos.h:1233-1250` |
| 3 | `num_format` | 0 | 1 | frac (0) / int (1) | `xenos.h:1252` |
| 3 | `swizzle` | 1–12 | 12 | xyzw, 3 bits ea (`XE_GPU_TEXTURE_SWIZZLE`) | `xenos.h:1254`, `xenos.h:1020-1036` |
| 3 | `exp_adjust` | 13–18 | 6 | signed | `xenos.h:1255` |
| 3 | `mag_filter` / `min_filter` / `mip_filter` | 19–20, 21–22, 23–24 | 2 ea | `TextureFilter`: 0 kPoint, 1 kLinear, 2 kBaseMap, 3 kUseFetchConst | `xenos.h:1256-1258`, `xenos.h:131-138` |
| 3 | `aniso_filter` | 25–27 | 3 | `AnisoFilter` | `xenos.h:1259`, `xenos.h:140` |
| 3 | `arbitrary_filter` | 28–30 | 3 | `ArbitraryFilter` | `xenos.h:1260`, `xenos.h:775` |
| 3 | `border_size` | 31 | 1 | — | `xenos.h:1261` |
| 4 | `vol_mag_filter` / `vol_min_filter` | 0, 1 | 1 ea | volume filters (1 = point) | `xenos.h:1263-1264` |
| 4 | `mip_min_level` / `mip_max_level` | 2–5, 6–9 | 4 ea | — | `xenos.h:1265-1266` |
| 4 | `mag_aniso_walk` / `min_aniso_walk` | 10, 11 | 1 | — | `xenos.h:1267-1268` |
| 4 | `lod_bias` | 12–21 | 10 | signed, 5 fractional bits | `xenos.h:1270` |
| 4 | `grad_exp_adjust_h/v` | 22–26, 27–31 | 5 ea | signed | `xenos.h:1272-1273` |
| 5 | `mip_retained`/remaining dword 5 fields | see `xenos.h:1275+` | | | |

### 3.2 Vertex fetch slot — 2 dwords, `xe_gpu_vertex_fetch_t` (`xenos.h:1113-1127`)

This is the layout the reference actually *reads* for a draw
(`register_file.h:52-58`, `GetVertexFetch`, which asserts `index < 96` — i.e. the fetch
window is treated as 96 two-dword slots, of which the table names 32 texture + others).

| dword | field | bits | width | meaning | anchor |
|---|---|---|---|---|---|
| 0 | `type` | 0–1 | 2 | `FetchConstantType` (3 = `kVertex`) | `xenos.h:1119` |
| 0 | `address` | 2–31 | 30 | **address in dwords** | `xenos.h:1120` |
| 1 | `endian` | 0–1 | 2 | `Endian` | `xenos.h:1122` |
| 1 | `size` | 2–25 | 24 | size in words | `xenos.h:1123` |
| 1 | `_pad_1_26` | 26–31 | 6 | — | `xenos.h:1124` |

`FetchConstantType::kVertex` is the discriminator: a slot whose `type & 3 == 3` describes a
vertex stream, anything else in this window is a texture/loop constant that happens to land
here. That is exactly the project's `g_bridgeNoVbFetchConst` refusal
(`src/gpu_cp.cpp:150-154`).

### 3.3 **There is no "fetch-shader program" in this reference, and no register-packet stream**

The brief's premise is false and the project has already recorded the correction
(`src/gpu_cp.cpp:200-224`, F-612). What the files say:

* `.research/xenia/src/xenia/gpu/xenos_graphics_processor.h` **does not exist** in this
  checkout (`git ls-files src/xenia/gpu/` — no such entry). The reference named by the brief
  is absent.
* Microcode is a stream of **triples of 32-bit words**, indexed `&ucode_[3 * n]`
  (`xenos.h:28-29`; `shader_interpreter.cc:96`).
* A control-flow packet's `sequence()` field, 2 bits per instruction, selects per executed
  instruction a **FETCH** packet or an **ALU** packet (`ucode.h:232`, `:274`;
  `shader_interpreter.cc:97-105` for fetch, `:115` for ALU).
* The fetch packet dispatches on `ucode::FetchOpcode::kVertexFetch` (`shader_interpreter.cc:105`).
* **There is no program header carrying "word count / register count / max register index".**
  `LoadShader` (`d3d12/pipeline_cache.cc:842-866`) takes a raw host pointer plus a dword count
  and hashes the whole thing; the register count comes from `SQ_PROGRAM_CNTL`
  (`d3d12/pipeline_cache.cc:879`, `:913`), never from a header in the program.
* Control-flow opcodes are a 4-bit field (`ucode.h:259`), values `0` kNop … `15`
  kMarkVsFetchDone (`ucode.h:92-165`). The `kExec*`/`kCondExec*` family is enumerated at
  `ucode.h:169-178`, the terminating family at `:182-187`, predicate-clean at `:190-194`.
* `ControlFlowExecInstruction` is 2 dwords: `address_` 0–11, `count_` 12–14, `is_yield_` 15,
  `sequence_` 16–27, `vc_hi_` 28–31, `vc_lo_` 0–1, `is_predicate_clean_` 10, `address_mode_` 14,
  `opcode_` 15–18 of word 1 (`ucode.h:238-261`).
* **The seam the project must refuse:** `stride()`, `offset()`, `data_format()` and
  `dest_swizzle()` live in `ucode::VertexFetchInstruction`, declared in
  `xenia/base/ucode/ucode.h` — **which is not in this checkout**
  (`.research/xenia/src/xenia/base/ucode` does not exist; `.gitmodules` lists only
  `third_party/*`). Their bit positions cannot be read here.
* What *is* derivable: the address-in-registers formula
  `vfetch_address_dwords = instr.stride() * vertex_index + fetch.address`
  (`shader_interpreter.cc:1013-1014`), read bounds `[fetch.address, fetch.address + fetch.size)`
  (`:1033`, `:1042`), endian swap at `:1048`.

**Verdict for the agent executing it:** there is no packet-type table to implement and no
header to parse. The honest deliverable is exactly what `CpNoteMicrocodeUnsupported`
(`src/gpu_cp.cpp`) already does — capture the program bytes by pointer, refuse **by name** at
the `VertexFetchInstruction` seam. Fabricating `stride`/`data_format` bit positions is the one
thing that would render wrong geometry silently.

## 4. Command-processor opcode set

Full enum with anchors: `xenos.h:1572-1634` (`enum Type3Opcode`). Header construction:
`xenos.h:1637-1664`.

### 4.1 Handled by Xenia (`command_processor.cc:718-…`) — and by this project

| op | name | `xenos.h` | Xenia handler | project `src/gpu_cp.cpp` |
|---|---|---|---|---|
| `0x10` | `PM4_NOP` | `:1575` | ✓ | skipped generically |
| `0x21` | `PM4_REG_RMW` | `:1587` | ✓ | `CpExecRegRmw` `:560` |
| `0x22` | `PM4_DRAW_INDX` | `:1600` | ✓ | `kPm4DrawIndx` `:1379`, `:1824` |
| `0x23` | `PM4_VIZ_QUERY` | `:1605` | ✓ | not implemented |
| `0x25` | `PM4_SET_STATE` | `:1606` | ✓ | not implemented |
| `0x26` | `PM4_WAIT_FOR_IDLE` | `:1580` | ✓ | not implemented |
| `0x27` | `PM4_IM_LOAD` | `:1611` | ✓ `:1528-1557` | `CpExecImLoad(…,false)` `:923` |
| `0x2B` | `PM4_IM_LOAD_IMMEDIATE` | `:1612` | ✓ `:1559-1590` | `CpExecImLoad(…,true)` `:925` |
| `0x2C` | `PM4_IM_STORE` | `:1626` | ✓ | not implemented |
| `0x2D` | `PM4_SET_CONSTANT` | `:1607` | ✓ `:1428-1463` | `CpExecSetConstant` `:927` |
| `0x2E` | `PM4_LOAD_CONSTANT_CONTEXT` | `:1613` | ✓ | not implemented |
| `0x2F` | `PM4_LOAD_ALU_CONSTANT` | `:1610` | ✓ `:1477-1515` | not implemented |
| `0x34` | `PM4_DRAW_INDX_BIN` | `:1602` | ✓ | not implemented |
| `0x35` | `PM4_DRAW_INDX_2_BIN` | `:1603` | ✓ | not implemented |
| `0x36` | `PM4_DRAW_INDX_2` | `:1601` | ✓ | `kPm4DrawIndx2` `:1380`, `:1825` |
| `0x37` | `PM4_INDIRECT_BUFFER_PFD` | `:1578` | ✓ | not implemented |
| `0x3B` | `PM4_INVALIDATE_STATE` | `:1614` | ✓ | not implemented |
| **`0x3C`** | **`PM4_WAIT_REG_MEM`** | **`:1581`** | **✓ `:735`, `:955-1067`** | **NOT handled** |
| `0x3D` | `PM4_MEM_WRITE` | `:1589` | ✓ `:1092-1108` | `kPm4MemWrite` `:1373`, `:1806` |
| **`0x3E`** | **`PM4_REG_TO_MEM`** | **`:1588`** | **✓ `:741`, `:1069-1090`** | **NOT handled** |
| `0x3F` | `PM4_INDIRECT_BUFFER` | `:1577` | ✓ | `kPm4IndirectBuffer` `:1372`, `:1783` |
| `0x44` | `PM4_COND_EXEC` | `:1591` | ✓ | not implemented |
| `0x45` | `PM4_COND_WRITE` | `:1592` | ✓ | not implemented |
| `0x46` | `PM4_EVENT_WRITE` | `:1594` | ✓ | not implemented |
| `0x48` | `PM4_ME_INIT` | `:1573` | ✓ | `kPm4MeInit` `:1371`, `:1798` |
| `0x4A` | `PM4_SET_SHADER_BASES` | `:1616` | ✓ | not implemented |
| `0x4B` | `PM4_SET_BIN_BASE_OFFSET` | `:1617` | ✓ | not implemented |
| `0x4F` | `PM4_MEM_WRITE_CNTR` | `:1590` | ✓ | not implemented |
| `0x50` | `PM4_SET_BIN_MASK` | `:1618` | ✓ `:815` | not implemented |
| `0x51` | `PM4_SET_BIN_SELECT` | `:1619` | ✓ | not implemented |
| `0x52` | `PM4_WAIT_REG_EQ` | `:1582` | ✓ | not implemented |
| `0x53` | `PM4_WAIT_REG_GTE` | `:1583` | ✓ | not implemented |
| `0x54` | `PM4_INTERRUPT` | `:1622` | ✓ | not implemented |
| `0x55` | `PM4_SET_CONSTANT2` | `:1608` | ✓ `:1465-1475` | `CpExecSetConstant(…,true)` `:929` |
| `0x56` | `PM4_SET_SHADER_CONSTANTS` | `:1609` | ✓ `:1517+` | not implemented |
| `0x58` | `PM4_EVENT_WRITE_SHD` | `:1595` | ✓ | not implemented |
| `0x59` | `PM4_EVENT_WRITE_CFL` | `:1596` | ✓ | not implemented |
| `0x5A` | `PM4_EVENT_WRITE_EXT` | `:1597` | ✓ | not implemented |
| `0x5B` | `PM4_EVENT_WRITE_ZPD` | `:1598` | ✓ | not implemented |
| `0x5C` | `PM4_WAIT_UNTIL_READ` | `:1584` | ✓ | not implemented |
| `0x5D` | `PM4_WAIT_IB_PFD_COMPLETE` | `:1585` | ✓ | not implemented |
| `0x5E` | `PM4_CONTEXT_UPDATE` | `:1621` | ✓ | not implemented |
| `0x60`–`0x63` | `PM4_SET_BIN_MASK_LO/HI`, `…SELECT_LO/HI` | `:1630-1633` | ✓ `:793-814` | not implemented |
| `0x64` | `PM4_XE_SWAP` | `:1624` | ✓ (Xenia-invented) | `kPm4XeSwap` `:954`, `:2103` |

### 4.2 The two the project does not handle — named

**`0x3C` = `PM4_WAIT_REG_MEM`** — "wait until a register or memory location is a specific value"
(`xenos.h:1581`). Layout, `command_processor.cc:955-1067`:

| arg | meaning | anchor |
|---|---|---|
| `wait_info` | `bit 4` = 1 ⇒ poll **memory** (a guest **physical** address) else poll a register index; `bits 2:0` = compare op | `:962`, `:968` |
| `poll_reg_addr` | register index, or physical address; low 2 bits are the **endian** for memory polls | `:963`, `:972-983` |
| `ref` | comparison reference | `:964` |
| `mask` | value mask, applied before compare | `:965` |
| `wait` | 0/1 — whether to spin | `:966` |

Compare op (`wait_info & 0x7`): `0` Never, `1` `<`, `2` `<=`, `3` `==`, `4` `!=`, `5` `>=`,
`6` `>` (`:990-1012`). Special case: if `poll_reg_addr == XE_GPU_REG_COHER_STATUS_HOST`
(`0x0A31`) the processor is made coherent first (`:985-988`).

**`0x3E` = `PM4_REG_TO_MEM`** — "reads register in chip and writes to memory"
(`xenos.h:1588`). Layout, `command_processor.cc:1069-1090`:

| arg | meaning | anchor |
|---|---|---|
| `reg_addr` | **register index**, must be `< 0x5003` | `:1075`, `:1080` |
| `mem_addr` | guest **physical** address; low 2 bits = `Endian` for the store | `:1076`, `:1083-1086` |

Both are **host-visible side effects on guest memory**, so a project that skips them leaves the
guest spinning or reading a register value that was never stored. Measured frequencies quoted by
the project for `build/w658.log`: `0x3E` ≈ **18,465** occurrences, `0x3C` ≈ **484**
(`src/gpu_cp.cpp:753`, `:1350`; the `CP-T3-CENSUS` table for that soak lists `0x3E`, `0x3C`,
`0x58`, `0x60`, `0x3B`, `0x54`, `0x46`, `0x62`, `0x61`, `0x63`, `0x7F`, `0x45`).
Note `0x7F` is not in `enum Type3Opcode` at all — it falls to `default:` and
`assert_unhandled_case` (`command_processor.cc:630-632`). **`0x3C` and `0x3E` are the only two
in that census that the reference implements and the project does not.**

## 5. `PrimitiveType` in full — and the decayed `0/1/2/3/4` table

`xenos.h:44-93`. **This is the architected enum; there is no other.**

| value | name | D3D12 | note |
|---|---|---|---|
| `0x00` | `kNone` | **refuse** | not a geometry type; Xenia lowers it to a zero-index draw |
| `0x01` | `kPointList` | `POINTLIST` | `d3d12_command_processor.cc:2298` |
| `0x02` | `kLineList` | `LINELIST` | `:2301` |
| `0x03` | `kLineStrip` | `LINESTRIP` | — |
| `0x04` | **`kTriangleList`** | `TRIANGLELIST` | `:2268`, `:2307` |
| `0x05` | `kTriangleFan` | `TRIANGLEFAN` | — |
| `0x06` | `kTriangleStrip` | `TRIANGLESTRIP` | `:2311` |
| `0x07` | `kTriangleWithWFlags` | **refuse** | per-triangle W flag; D3D12 carries it in a PS, not a topology |
| `0x08` | `kRectangleList` | **refuse** | Xenos emits 2 triangles per rectangle with a winding contract D3D12 lacks; `TRIANGLELIST` would draw them in the wrong order, silently |
| `0x0C` | `kLineLoop` | **refuse** | no D3D12 loop topology |
| `0x0D` | `kQuadList` | **refuse** | no equivalent |
| `0x0E` | `kQuadStrip` | **refuse** | no equivalent |
| `0x0F` | `kPolygon` | **refuse** | no equivalent |
| `0x10` | `kExplicitMajorModeForceStart` **and** `k2DCopyRectListV0` **and** `kLinePatch` | **refuse** | three enumerators share `0x10` — see below |
| `0x11` | `k2DCopyRectListV1` / `kTrianglePatch` | refuse | |
| `0x12` | `k2DCopyRectListV2` / `kQuadPatch` | refuse | |
| `0x13` | `k2DCopyRectListV3` | refuse | |
| `0x14` | `k2DFillRectList` | refuse | |
| `0x15` | `k2DLineStrip` | refuse | |
| `0x16` | `k2DTriStrip` | refuse | |

> **`0x10` is a genuine alias and must be resolved from `VGT_OUTPUT_PATH_CNTL`, not from the
> value alone.** `xenos.h:64` (`kExplicitMajorModeForceStart`) and `xenos.h:90`
> (`kLinePatch`) are both `0x10`; `0x11` is both `k2DCopyRectListV1` and `kTrianglePatch`;
> `0x12` likewise. `xenos.h:74-89`: tessellation patches are selected by
> `VGT_OUTPUT_PATH_CNTL::path_select == kTessellationEnable` (`xenos.h:836`).
> `xenos.h:59-63` also flags the R6xx-derived `0x10` boundary as **UNVERIFIED on Xenos**.
> `xenos.h:756-759`: `IsMajorModeImplicit()` is `prim_type < kExplicitMajorModeForceStart`.
> `VGT_OUTPUT_PATH_CNTL.path_select` is 2 bits at 0 (`registers.h:400-408`).

**The decayed table.** `src/renderer/trace_types.h:74`:
```cpp
uint32_t primType;         // Primitive topology (0=TriList, 1=TriStrip, etc.)
```
This is the stale `0/1/2/3/4` family. Under the architected enum `0` is `kNone` and `4` is
`kTriangleList` — **`0=TriList` is wrong in both the name and the value.** The rest of the
project is already correct and says so: `src/d3d12_backend.cpp:225-250`
(`MapXenosPrimType`, per-code, correct for `0x01`–`0x06`, refuses the rest) and
`src/renderer/pipeline_cache.cpp:667-706` (same mapping, with per-value refusal counters).
Both cite `trace_types.h:74` as the *known-bad* source. The stale comment is still live text in
a shipped header, and `capture_hooks.cpp:103-105` fills the field as `ctx.r4.u32 & 7` — a
3-bit value that cannot express `0x08`+ and does not match the enum; `pipeline_cache.h:348-352`
correctly labels that a hypothesis, not a fact.

## 6. `ColorFormat` and `ColorRenderTargetFormat` → host format

### 6.1 `ColorFormat` (full) — `xenos.h:543-570`

Subset of Adreno's `a2xx_sq_surfaceformat`, restricted to what render targets can **resolve
to**. 6 bits wide; the list is **sparse** (2…10, 14…17, 24…26, 30…32, 36…38, 50, 54…56).

| value | name | value | name |
|---|---|---|---|
| 2 | `k_8` | 25 | `k_16_16` |
| 3 | `k_1_5_5_5` | 26 | `k_16_16_16_16` |
| 4 | `k_5_6_5` | 30 | `k_16_FLOAT` |
| 5 | `k_6_5_5` | 31 | `k_16_16_FLOAT` |
| 6 | `k_8_8_8_8` | 32 | `k_16_16_16_16_FLOAT` |
| 7 | `k_2_10_10_10` | 36 | `k_32_FLOAT` |
| 8 | `k_8_A` | 37 | `k_32_32_FLOAT` |
| 9 | `k_8_B` | 38 | `k_32_32_32_32_FLOAT` |
| 10 | `k_8_8` | 50 | `k_8_8_8_8_AS_16_16_16_16` |
| 14 | `k_8_8_8_8_A` | 54 | `k_2_10_10_10_AS_16_16_16_16` |
| 15 | `k_4_4_4_4` | 55 | `k_10_11_11_AS_16_16_16_16` |
| 16 | `k_10_11_11` | 56 | `k_11_11_10_AS_16_16_16_16` |
| 17 | `k_11_11_10` | 24 | `k_16` |

`ColorFormat` is **not** a render-target format. It appears in exactly two places:
`RB_COPY_DEST_INFO.copy_dest_format` (6 bits at +7, `registers.h:876`) and
`xe_gpu_memexport_stream_t.format` (6 bits at +8 of dword 2, `xenos.h:1513`).

**Where the host mapping should be resolved — and the honest answer for the awkward three.**
There is **no `ColorFormat`→DXGI table in the reference.** The reference's own handling is
`draw_util.cc:674-696`: it validates `FormatInfo::Get(TextureFormat(...))->type ==
FormatType::kResolvable` (`:674-681`), and for `k_8_A`, `k_8_B`, `k_8_8_8_8_A` it emits
`"Memexport done to an unresearched format"` and **continues** (`:685-696`).
Those three plus `k_32_32_32_32_FLOAT` (`38`) and `k_10_11_11`/`k_11_11_10` (16/17) have **no
honest DXGI equivalent** and must be **refused, not approximated**:
* `k_8_A` (8), `k_8_B` (9) — two components of unequal semantic width; DXGI has no
  two-channel A/B-only format.
* `k_8_8_8_8_A` (14) — reference itself calls it **unresearched** (`draw_util.cc:688`).
* `k_32_32_32_32_FLOAT` (38) — 128 bpp, no DXGI 4×32FLOAT format.
* `k_10_11_11` (16) / `k_11_11_10` (17) — need a swizzle, which is a `copy_dest`/memexport
  concern, not a storage format. Resolvable only via an explicit swizzle, and Xenia ships a
  dedicated `texture_load_r10g11b11_rgba16*` family for the *read* side, not a DXGI surface.
DXGI resolutions that do exist: `k_8`→`R8_UNORM`, `k_16`→`R16_UNORM`, `k_32_FLOAT`→`R32_FLOAT`,
`k_5_6_5`→`B5G6R5_UNORM` (note **BGR order** on the host, `d3d12_texture_cache.cc:104-105`),
`k_1_5_5_5`→`B5G5R5A1_UNORM` (`:98-99`), `k_8_8_8_8`→`R8G8B8A8_UNORM` (`:115-116`),
`k_2_10_10_10`→`R10G10B10A2_UNORM` (`:120-121`), and the 16/32-bit float/unorm families via
`d3d12_texture_cache.cc`'s `kLoadShaderIndex*` rows. **The parallel platform-header stream owns
the platform side; this file owns the Xenos side and the refusal list above.**

### 6.2 `ColorRenderTargetFormat` → DXGI (authoritative, from the reference)

`xenos.h:299-319`; lowered in `d3d12_render_target_cache.cc:1680-1737`.

| Xenos value | resource DXGI (`GetColorResourceDXGIFormat`, `:1684-1716`) | draw DXGI (`GetColorDrawDXGIFormat`, `:1721-1736`) |
|---|---|---|
| `k_8_8_8_8` (0) | `R8G8B8A8_UNORM` | (falls through to resource) |
| `k_8_8_8_8_GAMMA` (1) | `R16G16B16A16_UNORM` if `gamma_render_target_as_unorm16_` else `R8G8B8A8_UNORM` | ″ |
| `k_2_10_10_10` (2) | `R10G10B10A2_UNORM` | ″ |
| `k_2_10_10_10_AS_10_10_10_10` (10) | `R10G10B10A2_UNORM` (same as 2) | ″ |
| `k_2_10_10_10_FLOAT` (3) | `R16G16B16A16_FLOAT` | ″ |
| `k_2_10_10_10_FLOAT_AS_16_16_16_16` (12) | `R16G16B16A16_FLOAT` (same as 3) | ″ |
| `k_16_16` (4) | `R16G16_TYPELESS` | `R16G16_SNORM` |
| `k_16_16_16_16` (5) | `R16G16B16A16_TYPELESS` | `R16G16B16A16_SNORM` |
| `k_16_16_FLOAT` (6) | `R16G16_TYPELESS` | `R16G16_FLOAT` |
| `k_16_16_16_16_FLOAT` (7) | `R16G16B16A16_TYPELESS` | `R16G16B16A16_FLOAT` |
| `k_32_FLOAT` (14) | `R32_TYPELESS` | `R32_FLOAT` |
| `k_32_32_FLOAT` (15) | `R32G32_TYPELESS` | `R32G32_FLOAT` |
| anything else | `DXGI_FORMAT_UNKNOWN` + `assert_unhandled_case` (`:1713-1715`) | ″ |

Two facts to carry forward: **values 8, 9, 11, 13 and 16…31 are unassigned in a 4-bit field**
(`kColorRenderTargetFormatBits = 4`, `xenos.h:409`) and the reference **asserts** on them —
so a guest value in a hole must be refused, not defaulted. And `_AS_` variants must use
`GetStorageColorFormat` (`xenos.h:355-365`) for the *resource*, while
`IsColorResolveFormatBitwiseEquivalent` (`xenos.h:575-600`) lists which `ColorFormat` may be
resolved into which RT format — it returns `false` for every case not listed, so
`k_16_16`/`k_16_16_16_16` (signed fixed-point) have **no** listed resolve partner and resolve
writes for them are *unsigned* (`xenos.h:572-574`). Refuse, do not approximate.

## 7. Discrepancies — the project's overlays vs. the reference

Ordered by severity. All project anchors are the tree as scanned (`HEAD 8385925` + uncommitted
batch; `src/**` moving).

### D1 — `RB_DEPTHF_INFO` does not exist; depth-bias magnitudes are four `kFloat` registers — **HIGH**
`src/renderer/pipeline_cache.cpp:818-837` refuses every polygon-offset draw, twice, citing
`RB_DEPTH_INFO` (`:819`) and then `RB_DEPTHF_INFO` (`:826`, `:836`).
* `RB_DEPTHF_INFO`: **no such register.** `git grep "DEPTHF" -- src/xenia/gpu/` = 0 hits.
* `RB_DEPTH_INFO` (`registers.h:835-849`) contains `depth_base`/`depth_format` and **no bias
  magnitude** — `:819` names the wrong register for the right reason.
* The magnitudes are `PA_SU_POLY_OFFSET_FRONT_SCALE` `0x2380`, `…_FRONT_OFFSET` `0x2381`,
  `…_BACK_SCALE` `0x2382`, `…_BACK_OFFSET` `0x2383` — all `kFloat`
  (`register_table.inc:615-618`), read at `draw_util.cc:103-104`, `:108-109`, `:115-116`.
* **Consequence:** the project renders every offset draw with zero bias while the enables are
  honoured, and blames a register that cannot carry the value. `pipeline_cache.h:374-377` makes
  the same substitution for depth state.
* **Fix:** read the four floats through `0x2380–0x2383` with the `draw_util.cc:93-121` selection
  rule, convert with `kPolygonOffsetScaleSubpixelUnit = 1/16` (`xenos.h:407`) and
  `GetD3D10IntegerPolygonOffset` semantics (`d3d12/pipeline_cache.cc:1500-1503`).

### D2 — `SuScModeCntl` drops 5 named fields into `rest : 15` — **MEDIUM**
`src/renderer/pipeline_cache.cpp:264` collapses bits 17–31. The reference names five of them:
`provoking_vtx_last` +19, `persp_corr_dis` +20, `multi_prim_ib_ena` +21,
`quad_order_enable` +23, `sc_one_quad_per_clock` +24 (`registers.h:478-483`).
The `15` is arithmetically correct for the *size* (17 named + 15 = 32, so F-634's fix to the
33-bit overflow is right), but the struct is now 5 fields short of the register and
`provoking_vtx_last` in particular changes rasterised geometry. **Fix:** name bits 17–18 and
22 as `_pad_17`/`_pad_22` and 25–31 as `_pad_25` (per `registers.h:477`, `:481`, `:486`) and
give the five real fields their own widths. `sizeof == 4` will still hold.

### D3 — five of the seven `CP-DRAW-STATE` peeks read registers the reference does not name — **MEDIUM**
`src/gpu_cp.cpp:1892-1894` reads indices `0x08B`, `0x08C`, `0x0DD`, `0x0D2`, `0x0A2`.
`register_table.inc` names **no register at any of those five indices** (the table jumps
`0x01F5 → 0x0395`; the only low-index entries are `0x0048`, `0x01DC`, `0x01DD`, `0x01E6-8`,
`0x01F5`, `0x0395-A`, `0x0578-7F`, `0x0A31`). Any register file that follows the reference
returns 0 for all five, forever. The project's own F-115a label ("a guess") is correct and
should be strengthened to "structurally always zero". `0x1DC`/`0x1DD` (`SCRATCH_UMSK`,
`SCRATCH_ADDR`, `register_table.inc:40`, `:39`) are real and the project's anchors are right.

### D4 — the uncached alias `0xFFC80000` is unhandled at all four MMIO gates — **MEDIUM**
`src/guest_memory.cpp:346`, `:431`; `src/gpu_cp.cpp:2858`, `:2989`. All keyed on
`0x7FC80000` only. The only project code that knows the alias —
`src/gpu_mmio.cpp:85-86` — is measured dead by that file's own header (`:6-30`, 0 occurrences,
no caller). The reference registers only `0x7FC80000` (`graphics_system.cc:92-95`), so **Xenia
would drop it too**: the project's gates are not wrong relative to the reference, they are
incomplete relative to the hardware, and the audit's "a doorbell rung there is never rung" is
correct. **Fix:** widen all four to accept both windows, normalise on `addr & 0xFFFF`.
`PhysToKernelVA` (`src/gpu_cp.cpp:1175-1177`) is **not** the place — `0x7FC80000 ≥ 0x20000000`
so it must keep returning the window unchanged, and the two alias families are unrelated.

### D5 — `src/renderer/trace_types.h:74` still carries the decayed `0/1/2/3/4` table — **MEDIUM**
`// Primitive topology (0=TriList, 1=TriStrip, etc.)` is wrong on both name and value
(`0` is `kNone`, `4` is `kTriangleList`; `1` is `kPointList`, not TriStrip). Both downstream
mappers are correct and cite this line as the known-bad source
(`src/d3d12_backend.cpp:225-228`, `src/renderer/pipeline_cache.cpp:635-666`), but the stale
comment is live text in a shipped header and the next reader of *that* header gets the wrong
table. **Fix:** point it at §5 of this file, or delete the parenthetical.

### D6 — three register names in the task brief do not exist — **LOW (documentation)**
`PA_SU_OFFSET_*` → the real names are `PA_SU_POLY_OFFSET_*` `0x2380–0x2383` (§2.4).
`RB_DEPTHF_INFO` → does not exist (§2.4, D1).
`PA_BLEND_*` → the real names are `RB_BLENDCONTROL0..3` `0x2201/0x2209/0x220A/0x220B` (§2.7).
Recorded so the next brief does not reintroduce them into `src/`.

### D7 — the file named as the fetch-shader source of truth does not exist — **LOW**
`.research/xenia/src/xenia/gpu/xenos_graphics_processor.h` is absent from this checkout, as is
`.research/xenia/src/xenia/base/ucode/ucode.h` where `VertexFetchInstruction` is declared.
The project already refuses at that seam by name (`src/gpu_cp.cpp:216-224`). Anyone told to
"port the packet types from `xenos_graphics_processor.h`" is being pointed at a file that is not
there.

### Verified-correct (no action)
* `ClipCntl` (`pipeline_cache.cpp:277-296`) — all 18 fields match `registers.h:539-556` exactly.
* `ClVteCntl` (`pipeline_cache.cpp:309-322`) — all 12 fields match `registers.h:569-580` exactly.
* `MapXenosPrimType` (`d3d12_backend.cpp:229-250`) — correct for `0x01`–`0x06`, refuses the rest.
* `CpExecSetConstant` (`gpu_cp.cpp:970-1008`) — `& 0x7FF` index, `(>>16) & 0xFF` type, all five
  bases match `command_processor.cc:1434-1457`; `SET_CONSTANT2`'s `& 0xFFFF` (`:979`) matches
  `:1469`.
* Every register index the project names: `0x01DC`/`0x01DD` (`register_table.inc:40`/`:39`),
  `0x0578`/`0x057F` (`:56`/`:63`), `0x0A31` (`:91`), `0x1922`/`:1923`/`:1924`/`:1925`/`:1927`
  (`:433`/`:440`/`:448`/`:452`/`:461`), `0x02102` = `VGT_INDX_OFFSET` (`:503`),
  `0x21FA`/`0x21FB`/`0x21FC` (`:531`/`:532`/`:533`), `0x2204`/`0x2205`/`0x2206`
  (`:540`/`:541`/`:542`), `0x4800`/`0x48BF` (`:2697`/`:2888`) — **all match**.
* `kXenosRegCount = 0x5003` (`gpu_cp.cpp:68`) matches `register_file.h:40` and the highest
  active table index `0x5002` (`register_table.inc:2934`).
* `kWptrSentinel = 0xBAADF00D` (`gpu_cp.cpp:40`) matches `command_processor.cc:210`, `:229`.
* The three unconditional `static_assert(sizeof == 4)` at `pipeline_cache.cpp:332-337` and the
  `constexpr` value probe at `:362-419` are the right shape of defence and should be kept.

## 8. Coverage — how much of this the project actually reads

115 textual call sites touch a Xenos register index or one of the three overlays
(`CpRegPeek` / `CpRegPoke` / `g_xenosReg[...]` / `SuScModeCntl` / `ClipCntl` / `ClVteCntl`),
across six files:

| file | sites | what it reads |
|---|---|---|
| `src/gpu_cp.cpp` | 27 | `0x01DC/1DD`, `0x0578-7F`, `0x0A31`, `0x1922-1927`, `0x21FA/FB/FC` poke, `0x2102`, the 7 unnamed low-index peeks, the `0x4800` slot scan (`:624-625`), the whole `0x5003` file |
| `src/renderer/pipeline_cache.cpp` + `.h` | 56 | `0x2204` / `0x2205` / `0x2206` overlays and `DecodedXenosRenderState` |
| `src/capture_hooks.cpp` | 3 | fills the three overlay inputs (unwired, per `pipeline_cache.h:355-363`) |
| `src/d3d12_backend.cpp` | 6 | `MapXenosPrimType` + refusal counters |
| `src/native_renderer.h` | 3 | the overlay inputs on the host struct |
| `src/renderer/trace_types.h` | 3 | the decayed `primType` comment (D5) |

`DrawPacket` also carries `colorFormats[4]` and `depthStencilFormat`
(`pipeline_cache.h:340-341`), i.e. `RB_COLOR_INFO.color_format` and
`RB_DEPTH_INFO.depth_format` — both documented in §2.5/§2.6, both **unvalidated** against the
`ColorRenderTargetFormat` / `DepthRenderTargetFormat` hole list in §6.2.

## 9. `UNVERIFIED` register

| item | what is missing | what would settle it |
|---|---|---|
| Whether *this title* ever stores the doorbell at `0xFFC80000` | the reference registers no uncached alias, so it cannot answer | a page-watch on `0xFFC80000..0xFFC8FFFF` counting stores, or widening the four gates and looking for a `CP: doorbell` line that never appeared before |
| Reachability of `0x5000–0x5002` `SHADER_CONSTANT_FLUSH_FETCH_*` | no `SET_CONSTANT` type yields these bases; the arithmetic (`0x5000` = type 4 + index `0x3000`) lands in 3D space and reads as plausible | grep a soak for `CpRegPoke(0x50xx)`; the `CP-SETC-CAP`/`F-610` index census is the right counter |
| Exact host lowering for `poly_offset_*` in this project's PS/ROV path | D3D12 has no `DepthBiasEnable`; whether the title's draws need per-sample bias in the PS is unmeasured | one instrumented draw logging `0x2380-0x2383` next to the derived `SlopeScaledDepthBias` |
| The bit layout of `ucode::VertexFetchInstruction` | `xenia/base/ucode/ucode.h` is not in the checkout | fetch a tree that has it, or read the IPR2015-00325 R400 sequencer spec; **do not guess** |
| Whether `IsMajorModeImplicit`'s `0x10` boundary is correct on Xenos | `xenos.h:59-63` marks it TODO on the Xenos specifically | a soak that logs `VGT_OUTPUT_PATH_CNTL.path_select` beside `prim_type` for every draw |
| `pc`/`Unreal` naming for `ColorFormat` holes 11–13, 18–23, 27–29, 33–35, 39–49, 51–53 | not in the reference's sparse enum | Adreno `a2xx_sq_surfaceformat` (`xenos.h:542` names the source); until then **refuse** |
