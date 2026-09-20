# PLAN — implement the missing VMX128 D3D pack/unpack ops

**Status:** **Route A LANDED** — do not re-execute. The type-2 pack hooks live in
`config/mcla_xenonrecomp.toml` (`[[midasm_hook]]` @ `0x821B3814`, `0x821B3C2C`, `0x821B3E90`,
`0x821B4788`) with the host impl in `src/cpu/vmx128_pack.cpp` (pre-reorg path in older trail:
`src/vmx128_pack.cpp`). Gate met: zero `0x80000003` in the session-75 soaks.
**Caveat kept:** the `VMX128-PACK` counter never fired — not runtime-validated until a soak logs a
hit. Still open, only if the boot reaches them: type-2 unpack (§2.3), type-5 unpack (§2.2),
`vcmpbfp128` (§2.4).
**Compressed 2026-09-20** — full pre-compression text: `git show 8f07a39:docs/PLAN_VMX128.md`.
**Author:** session 74 (2026-09-11); landed session 75; spike corrections folded into §4.

---

## 1. The problem in one paragraph

XenonRecomp emits `__builtin_debugtrap()` for VMX128 pack/unpack *modes* it never implemented. The
guest reaches one during boot and dies on a host `EXCEPTION_BREAKPOINT` (`0x80000003`). The first one
hit was `vpkd3d128 v63,v0,2,1,0` at guest **`0x821B3814`**, inside `sub_821B3548` — the game's
**CPU-side vertex-fetch / vertex-format emulator**. Because that module builds vertex streams, this
is likely also why `DRAW_INDEXED` was 0.

## 2. Semantics — RESOLVED, do not re-derive

The mode selector is **`type = IMM >> 2`** (`IMM` = instruction bits 16-20) — the same field
XenonRecomp already switches on (it calls it `insn.operands[2]`). Confirmed against Xenia
`src/xenia/cpu/ppc/ppc_emit_altivec.cc`: `InstrEmit_vpkd3d128` at :2054, `InstrEmit_vupkd3d128` at
:2160.

| type | Xenia name | Format |
|---|---|---|
| 0 | `VPACK_D3DCOLOR` | 8_8_8_8 unorm — **already implemented** |
| 1 | `VPACK_NORMSHORT2` | 16_16 snorm — **already implemented** |
| **2** | `VPACK_NORMPACKED32` | **2_10_10_10 (w_z_y_x) — was MISSING → LANDED (pack)** |
| 3 | `VPACK_FLOAT16_2` | R16G16_FLOAT |
| 4 | `VPACK_NORMSHORT4` | 16_16_16_16 snorm |
| **5** | `VPACK_FLOAT16_4` | **R16G16B16A16_FLOAT — MISSING (unpack only)** |
| 6 | `VPACK_NORMPACKED64` | 4_20_20_20 |

For the **pack** there are two more fields: `pack = IMM & 0x3` (the `MB` operand) and `shift = ME`
(bits 6-7); they select a final byte permute that merges the result into the old `vD`. Xenia's full
permute tables are at `ppc_emit_altivec.cc:2092-2150`. XenonRecomp's D3DCOLOR case *simplifies* this
to `vD.u32[ME] = packed` — the landed type-2 hook follows the same simplification (risk R3).

### 2.1 `vpkd3d128` type 2 — pack to 2_10_10_10 (4 sites) — **LANDED**

Per `ARB_vertex_type_2_10_10_10_rev`: XYZ are 10-bit signed saturated, W is 2-bit unsigned
saturated, laid out MSB→LSB as `w(2) z(10) y(10) x(10)`. Scalar reference:

```c
uint32_t packed = (u2(vA.f32[3]) << 30) | (s10(vA.f32[2]) << 20)
                | (s10(vA.f32[1]) << 10) |  s10(vA.f32[0]);
// s10: clamp ±1, v = (int)(c * 512.0f)  TRUNCATE (risk R4), clamp ±511/-512, & 0x3FF
// u2 : clamp 0..1, v = (uint)(c * 3.0f), clamp 3
```

**The input is NOT raw [-1,1] floats** (corrected from this plan's first draft by the session-75
implementation): the guest pre-biases into the IEEE bits of a value near 3.0 — constant vectors at
`0x820100F0` = `{3,3,3,3}` and `0x82010100` = `{-2^-13,-2^-13,-2^-13,-3*2^-22}` with
`vnmsubfp v0,v12,v13,v0`. Xenia's `EmitUINT_2101010` clamps those bits to
`[0x403FFE01, 0x404001FF]` (XYZ) / `[0x40400000, 0x40400003]` (W) and ANDs with `0x3FF` / `0x3`.
**Host lane order is reversed** (D3DCOLOR convention): `host.f32[0]=W, [1]=Z, [2]=Y, [3]=X`. The
consumer after the trap (`stvx128` + `lwz 156(r1)` through `VectorMaskL`) reads **`vD.u32[0]`**, so
the `ME=0` write is sufficient. Emitted shape (verified in `build/xr_hooks/ppc_recomp.14.cpp`):

```
mcla_Vpkd3d128_type2(v63, ctx.v0);
goto loc_821B3818;          // skips the dead __builtin_debugtrap()
```

### 2.2 `vupkd3d128` type 5 — unpack FLOAT16_4 (94 sites, the big one) — OPEN

Xenia (`x64_seq_vector.cc:2595`, `:2606`): source is `[(x|y), (z|w), 0, 0]` — the four halves sit in
one 64-bit half — producing 4 × float32. With F16C Xenia does `vpshufb` to `0|0|0|0|W|Z|Y|X` then
`vcvtph2ps`. **Preferred implementation: the exact inverse of XenonRecomp's own working float16_4
pack** (`recompiler.cpp:2046-2068`), which writes `vD.u16[i + 2*ME]` with `ME` required to be 2 and
applies **no** `indices[]` reversal (unlike its D3DCOLOR case) — mirroring it avoids the whole
guest/host vector-reversal question:

```c
for (i = 0; i < 4; i++) vTemp.f32[i] = half2float(vA.u16[i + 4]);
vD = vTemp;
```

Hand-roll `half2float` (do not depend on F16C/`_cvtsh_ss`) so the emitted C++ stays portable.

### 2.3 `vupkd3d128` type 2 — unpack 2_10_10_10 (1 site, `0x821B43D8`) — OPEN

Exact inverse of §2.1: sign-extend the 10-bit fields and divide by 512; W is unsigned, divide by 3 —
reading *the dword the pack would have written*, respecting `ME`:

```c
vTemp.f32[0] = (float)(int32_t)((vA.u32[0]      ) & 0x3FF | ((vA.u32[0] & 0x200) ? ~0x3FFu : 0u)) / 512.0f;
vTemp.f32[1] = same with >> 10;  vTemp.f32[2] = same with >> 20;
vTemp.f32[3] = (float)((vA.u32[0] >> 30) & 0x3) / 3.0f;
```

### 2.4 `vcmpbfp128` (1 site, `0x825CEA2C`) — OPEN, lowest priority

Xenia `ppc_emit_altivec.cc:596`, per-lane, no arithmetic subtleties:

```c
gt = a.f32[i] >  b.f32[i];
lt = !(a.f32[i] >= -b.f32[i]);
vD.u32[i] = (gt ? 0x80000000u : 0u) | (lt ? 0x40000000u : 0u);
// Rc=1 -> UpdateCR6(gt | lt). NaN yields 0xC0000000 in that lane automatically.
```

Not on the current boot path — do it only if free.

## 3. Site census (verified two independent ways)

Counts from `grep -B1 __builtin_debugtrap() generated/ppc_xenon/*.cpp` **and** an independent opcode
scan of `build/cache/mcla_pe.bin` `.text`. They agree.

| Instruction + mode | traps | guest addresses |
|---|---|---|
| `vpkd3d128` SH=2 MB=1 ME=0 (type 2 pack) | **4** | `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` — **all hooked now** |
| `vupkd3d128` UIMM=20 (type 5 unpack) | **94** | first `0x822F1B80`, `0x822F1B9C`, `0x822F1C08`, `0x822F1C10`, `0x822F657C`, `0x822F66AC`, … all in `0x822Fxxxx` |
| `vupkd3d128` UIMM=8 (type 2 unpack) | **1** | `0x821B43D8` |
| `vcmpbfp128` | **1** | `0x825CEA2C` |

All 5 type-2 sites are inside the vertex-fetch emulator module (`0x821B35xx`–`0x821B47xx`). The 94
type-5 sites are a separate cluster in `0x822Fxxxx` and may not be reached during boot at all.
Raw-scan artifacts to **ignore**: `vpkd3d128 SH=3 MB=1 ME=3` (`0x82420A38`) and `SH=0 MB=3`
(`0x821746D4`, `0x825E2044`) match the opcode pattern but produce **no** debugtrap in `generated/`.

## 4. Routes

### Route A — `midasm_hook` in the tracked TOML — **TAKEN for type 2**

`generated/` is gitignored but `config/mcla_xenonrecomp.toml` is **tracked**, so hooks keep the whole
change in version control and leave the vendored recompiler pristine (`.research/` is gitignored too).

```toml
[[midasm_hook]]
name = "MclaVpkd3d128Type2MidAsmHook"
address = 0x821B3814
registers = ["v63", "v0"]
after_instruction = false
jump_address = 0x821B3818
```

The host function is emitted as a call taking the named registers **by C++ reference**;
`jump_address` skips the trapped instruction. Repeat per site (4 for type 2 — done; 94+1 for type 5
would not be maintainable → that is Route B territory).
**Verified before coding (session 74b):** `registers` accepts vector registers (`v0`/`v63`) — the
precedent is UnleashedRecomp's `SWA.toml:943` (`["v63","v62"]`; also `["v127","f24"]`,
`["r30","v61"]`, `["f0","v62"]`); `after_instruction=false` + `jump_address` really does bypass the
`__builtin_debugtrap()` (proven by the landed hooks); and the hook sees VMX128 registers
**reversed** relative to Altivec — log all four lanes at one site before trusting any math (R1).

### Route B — patch XenonRecomp and regenerate (needed if type 5 is reached)

Edit `.research/XenonRecomp/XenonRecomp/recompiler.cpp`: `case PPC_INST_VPKD3D128` at **:2011** (add
`case 2:`), `case PPC_INST_VUPKD3D128` at **:2203** (add `case 2:` and `case 5:`),
`case PPC_INST_VCMPBFP128` at **:1847** (replace the debugtrap). Then, in this order, gate at each
step:

1. **Save the patch** — `.research/` is gitignored: export
   `git -C .research/XenonRecomp diff > tools/xenonrecomp_vmx128.patch` and commit the **patch file**.
2. **Build the tool** — already built:
   `.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe` (plus `XenonAnalyse.exe`);
   `rebuild_clang.bat` = `cmake -S . -B build-clang -G Ninja -DCMAKE_CXX_COMPILER=clang-cl
   -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --build build-clang`. **No tool build needed as of
   session 74b.**
3. **Reproducibility gate (hard).** Run the **unmodified** tool with
   `config/mcla_xenonrecomp_baseline.toml` (a copy of the tracked config whose only change is
   `out_directory_path = "build/xr_baseline"`), then `diff -r build/xr_baseline generated/ppc_xenon`.
   Session 75 executed this: **181/183 files byte-identical**; `ppc_context.h` differed by a trailing
   newline only; `ppc_recomp.10.cpp` differs because it carries a **hand safety patch inside
   `sub_8218CC70`** (indirect-branch targetFn/basePtr validation) the recompiler does not emit —
   **never full-replace that file** or the session-38 null-dispatch AV returns. If a fresh regen does
   not reproduce byte-for-byte, STOP and fall back to Route A or C.
4. Apply the patch, regen into `generated/ppc_xenon`, rebuild, soak.
5. **Invocation gotchas.** The config path must be a **bare filename** run from the repo root
   (`recompiler_config.cpp:5` derives `directoryPath` from the path — with a separator the jump-table
   path resolves to `config/.research/…`, which does not exist). The header arg is `src/ppc_context.h`,
   reconstructed mechanically as
   `tail -n +4 generated/ppc_xenon/ppc_context.h > src/ppc_context.h` (the generated file prepends
   `#pragma once` + `#include "ppc_config.h"` + blank; the round-trip is `cmp`-clean). **TU count is
   176** (`CMakeLists.txt` hardcodes `ppc_recomp.0..175.cpp`) — the "179" figure in this plan's older
   text is stale; a regen that changes the count breaks the build.

### Route C — host `PPC_FUNC` override — fallback only

Override the affected guest functions host-side. **Zero existing hooks** on `821B3548` / `821A0800` /
`821917A8` / `82192150` / `82192448` (Golden Rule 1 satisfied), but `sub_821B3548` alone is ~1150
lines of recompiled code (`ppc_recomp.14.cpp:22989-24138`) and the 94 type-5 sites cannot be
hand-rewritten. Use only if A and B both fail.

## 5. Execution stages (0–1 done; 2–7 as the boot reaches them)

Do **not** implement everything up front — the boot dies at the *first* trap, so each fix reveals the
next blocker.

| Stage | Content | Status / gate |
|---|---|---|
| 0 | Baseline: build clean, reproduce the trap (`code=0x80000003 … lr=821B37F4 … [4] __imp__sub_821B3548 +0x172B`) | done (s74) |
| 1 | Type-2 pack for the 4 sites (Route A: 4 hook entries) | **done** — gate "no `0x80000003` at `0x821B3814`, record the new terminal event" |
| 2 | Re-triage: another VMX128 trap → next stage; a genuine assert/AV → new finding (write it up, don't paper over it); draws → compare `DRAW_INDEXED` / `SUBMIT r5` / `FRAME-END` / `NATIVE-PRESENT` against the session-74 baseline (`DRAW_INDEXED`=0, `SUBMIT`=14, `FRAME-END`=2, `NATIVE-PRESENT`=4, `SWAP-COMP`=9, `INFLATE-EMPTY`=8) | s75: no trap, `DRAW_INDEXED` still 0 |
| 3 | Type-2 unpack (§2.3, 1 site `0x821B43D8`) if reached | open |
| 4 | Type-5 unpack (§2.2, 94 sites) **only if the boot reaches `0x822Fxxxx`** → Route B | open |
| 5 | `vcmpbfp128` (§2.4, 1 site) | optional |
| 6 | Regression: `PHYS-OVERRUN`=0, o1heap AV=0, `MmAllocatePhysicalMemoryEx: FAILED`=0, `BLIT-OOB-GUARD` ≤2. If `BLIT-OOB-GUARD` moves, the vertex-fetch fix perturbed the surface path — investigate, don't accept | open |
| 7 | Docs: retire priority #1, record the new top blocker, add soak logs to the evidence table | done (this file + handoff ledger) |

## 6. Risks and gotchas

- **R1 — guest/host vector reversal.** XenonRecomp stores VMX128 registers reversed vs Altivec; its
  D3DCOLOR cases compensate with `indices[] = {3,0,1,2}` while its float16_4 pack applies no
  permutation. Get it wrong and every lane is silently swapped → **log all four lanes at one site
  before trusting any math.**
- **R2 — `.research/` and `generated/` are both gitignored.** Any fix living only there is invisible to
  the next clone: commit the TOML and/or the `.patch`.
- **R3 — the `pack`/`shift` permute.** XenonRecomp's D3DCOLOR case collapses Xenia's byte permute to
  `vD.u32[ME] = packed`. All 4 type-2 sites have `MB=1, ME=0` (= `MakePermuteMask(0,0,0,1,0,2,1,3)`
  over `(oldVD, packed)` in Xenia) — **not obviously** "write dword 0". Check what reads `v63` after
  `0x821B3814`; the site does `vor128 v63,v0,v0` first (scratch copy), in which case the simplification
  is safe, otherwise implement the permute.
- **R4 — rounding.** Xenia packs by masking/shifting IEEE float bits (truncation); the scalar sketch
  truncates too. If colours look banded/off-by-one, switch to round-to-nearest and compare.
- **R5 — do not "fix" a trap by skipping the instruction.** Returning without writing `vD` leaves a
  stale vector and silently wrong vertex data — far worse than a clean `int3`, and it looks like
  progress.
- **R6 — one hook owner per guest address.** Re-check before adding anything; the vertex-fetch
  functions were unowned at plan time but that may have changed.

## 7. Definition of done

- No `0x80000003` vectored exception in the soak log.
- Every added mode has a soak-log line proving it executed (handoff rule: *no gate claim without a
  soak-log line*) — add a counter + a throttled `MCLA_LOG_INFO` per new mode, like `BLIT-CAP`.
- `BLIT-OOB-GUARD` and the AV-storm numbers unchanged (Stage 6).
- The fix is in **tracked** files (TOML hook entries, or a committed `.patch` plus build/regenerate
  notes).
- `docs/HANDOFF_NEXT_AGENT.md` updated.

## 8. Reference locations

| What | Where |
|---|---|
| XenonRecomp pack/unpack cases | `.research/XenonRecomp/XenonRecomp/recompiler.cpp:2011, :2203, :1847` |
| XenonRecomp hook config parsing | `.research/XenonRecomp/XenonRecomp/recompiler_config.cpp:95-138` |
| XenonRecomp build script / exe | `.research/XenonRecomp/rebuild_clang.bat` → `build-clang/XenonRecomp/XenonRecomp.exe` |
| Project recompiler config (+ baseline copy) | `config/mcla_xenonrecomp.toml`, `config/mcla_xenonrecomp_baseline.toml` |
| Xenia opcode dispatch | `.research/xenia/src/xenia/cpu/ppc/ppc_emit_altivec.cc:2054, :2160, :596` |
| Xenia pack/unpack math | `.research/xenia/src/xenia/cpu/backend/x64/x64_seq_vector.cc:2230 (2101010), :2595 (float16_4)` |
| Xenia VMX128 notes | `docs/ppc/vmx128.txt` in the xenia repo (not yet read) |
| Trapping guest function | `generated/ppc_xenon/ppc_recomp.14.cpp:22989-24138` (`sub_821B3548`), trap at `:23432` |
| Fetch-instruction loop | `generated/ppc_xenon/ppc_recomp.12.cpp:27277` (`sub_821A0800`) |
| Guest image | `build/cache/mcla_pe.bin`, identity `offset = VA − 0x82000000`, instruction words **big-endian** |