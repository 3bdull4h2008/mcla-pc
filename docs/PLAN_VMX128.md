# PLAN — implement the missing VMX128 D3D pack/unpack ops

**Status:** PLANNING ONLY. Nothing in this document has been executed.
**Author:** session 74 (2026-09-11). Read `docs/HANDOFF_NEXT_AGENT.md` §SESSION 74 first.
**Blocks:** handoff priority #1 (boot dies on host `int3`) and #2 (`DRAW_INDEXED`=0).

---

## 1. The problem in one paragraph

XenonRecomp emits `__builtin_debugtrap()` for VMX128 pack/unpack *modes* it never
implemented. The guest reaches one during boot and dies on a host
`EXCEPTION_BREAKPOINT` (`0x80000003`). The first one hit is
`vpkd3d128 v63,v0,2,1,0` at guest **`0x821B3814`**, inside `sub_821B3548` — the
game's **CPU-side vertex-fetch / vertex-format emulator**. Because that module is
what builds vertex streams, this is very likely also why `DRAW_INDEXED` is still 0.

## 2. Semantics — RESOLVED, do not re-derive

The mode selector is **`type = IMM >> 2`**, where `IMM` is instruction bits 16-20.
This is the *same* field XenonRecomp already switches on for both instructions
(it calls it `insn.operands[2]` for unpack, `insn.operands[2]`=SH for pack).
Confirmed against Xenia `src/xenia/cpu/ppc/ppc_emit_altivec.cc`:
`InstrEmit_vpkd3d128` at :2054, `InstrEmit_vupkd3d128` at :2160.

| type | Xenia name | Format |
|---|---|---|
| 0 | `VPACK_D3DCOLOR` | 8_8_8_8 unorm — **already implemented** |
| 1 | `VPACK_NORMSHORT2` | 16_16 snorm — **already implemented** |
| **2** | `VPACK_NORMPACKED32` | **2_10_10_10 (w_z_y_x) — MISSING** |
| 3 | `VPACK_FLOAT16_2` | R16G16_FLOAT |
| 4 | `VPACK_NORMSHORT4` | 16_16_16_16 snorm |
| **5** | `VPACK_FLOAT16_4` | **R16G16B16A16_FLOAT — MISSING (unpack only)** |
| 6 | `VPACK_NORMPACKED64` | 4_20_20_20 |

For the **pack** there are two more fields: `pack = IMM & 0x3` (the `MB` operand)
and `shift = ME` (bits 6-7). They select a final **byte permute** that merges the
packed result into the old `vD` content. Xenia's full permute tables are at
`ppc_emit_altivec.cc:2092-2150`. XenonRecomp's existing D3DCOLOR case *simplifies*
this to `vD.u32[ME] = packed` — follow the same simplification (see §6 risk R3).

### 2.1 `vpkd3d128` type 2 — pack to 2_10_10_10 (4 sites)

Per `ARB_vertex_type_2_10_10_10_rev` (Xenia cites it at `x64_seq_vector.cc:2231`):
XYZ are **10-bit signed saturated**, W is **2-bit unsigned saturated**, laid out
MSB→LSB as `w(2) z(10) y(10) x(10)`.

```c
// scalar reference; Xenia does the same with float-bit masking + shifts
static inline uint32_t s10(float f) {
  float c = f < -1.0f ? -1.0f : (f > 1.0f ? 1.0f : f);
  int32_t v = (int32_t)(c * 512.0f);            // TRUNCATE — see risk R4
  if (v >  511) v =  511;
  if (v < -512) v = -512;
  return (uint32_t)v & 0x3FF;
}
static inline uint32_t u2(float f) {
  float c = f < 0.0f ? 0.0f : (f > 1.0f ? 1.0f : f);
  uint32_t v = (uint32_t)(c * 3.0f);
  return v > 3u ? 3u : v;
}
uint32_t packed = (u2(vA.f32[3]) << 30) | (s10(vA.f32[2]) << 20)
                | (s10(vA.f32[1]) << 10) |  s10(vA.f32[0]);
```

**The input really is raw floats, not the "3.0 magic" encoding** — verified from
the trapping site's own lead-up (`ppc_recomp.14.cpp` around :23410):

```
lvx128   v13,r0,r23      // r23 = 0x82010100  (constant vector)
lvx128   v0,r0,r22       // r22 = 0x820100F0  (constant vector)
lvx128   v12,r30,r25     // r30+48 = caller's const floats
vnmsubfp v0,v12,v13,v0   // v0 = v0 - v12*v13   -> plain scale/bias
vor128   v63,v0,v0
stvx128  v0,r0,r11
vpkd3d128 v63,v0,2,1,0   // <-- TRAP
```

So unlike D3DCOLOR (where XenonRecomp clamps to `[3.0, 3.0+eps]` because the guest
pre-biased by 3.0), type 2 takes ordinary floats. **Do not copy the 3.0 clamp.**

Action before implementing: dump the two constant vectors at guest `0x820100F0`
and `0x82010100` (file offsets are the same, see §5) and confirm they look like a
scale/bias pair. Also dump the component-size table at `0x8200C0A0`
(`2,4,6,8 | 4,8,12,16 | 4,4,4,0…`) — `sub_821B3548` indexes it with
`lwzx r28,r9,r24` and it is what decides the format branch.

### 2.2 `vupkd3d128` type 5 — unpack FLOAT16_4 (94 sites, the big one)

Xenia (`x64_seq_vector.cc:2595`, `:2606`):

```c
// src = [(x|y), (z|w), 0, 0]   -> the four halves are in ONE 64-bit half
// dst = 4 x float32 (x,y,z,w)
for (i = 0; i < 4; i++) b[i] = half2float(a[VEC128_W(4 + i)]);
```

With F16C Xenia instead does `vpshufb` to `0|0|0|0|W|Z|Y|X` then `vcvtph2ps`.

**Preferred implementation: make it the exact inverse of XenonRecomp's own
already-working float16_4 *pack*** (`recompiler.cpp:2046-2068`). That pack writes
`vD.u16[i + 2*ME]` with `ME` required to be 2 — i.e. halves land at `u16[4..7]`,
and it applies **no** `indices[]` reversal (unlike its D3DCOLOR case, which uses
`indices[] = {3,0,1,2}`). Mirroring that exactly avoids the whole guest/host
vector-reversal question:

```c
for (i = 0; i < 4; i++) vTemp.f32[i] = half2float(vA.u16[i + 4]);
vD = vTemp;
```

Hand-roll `half2float` rather than depending on F16C/`_cvtsh_ss`, so the emitted
C++ stays portable — the pack side already hand-rolls its float→half conversion.

### 2.3 `vupkd3d128` type 2 — unpack 2_10_10_10 (1 site, `0x821B43D8`)

Exact inverse of §2.1:

```c
vTemp.f32[0] = (float)(int32_t)((vA.u32[0]      ) & 0x3FF | ((vA.u32[0] & 0x200) ? ~0x3FFu : 0u)) / 512.0f;
vTemp.f32[1] = same with >> 10
vTemp.f32[2] = same with >> 20
vTemp.f32[3] = (float)((vA.u32[0] >> 30) & 0x3) / 3.0f;
```

(sign-extend the 10-bit fields, divide by 512; W is unsigned, divide by 3.
Read the *dword the pack would have written*, respecting `ME`.)

### 2.4 `vcmpbfp128` (1 site, `0x825CEA2C`)

Xenia `ppc_emit_altivec.cc:596`. Per-lane, no arithmetic subtleties:

```c
gt = a.f32[i] >  b.f32[i];
lt = !(a.f32[i] >= -b.f32[i]);
vD.u32[i] = (gt ? 0x80000000u : 0u) | (lt ? 0x40000000u : 0u);
// Rc=1 -> UpdateCR6(gt | lt). The `.128` variant takes operands {VD128,VA128,VB128}.
```

NaN yields `0xC0000000` in that lane automatically. This site is **not** on the
current boot path — lowest priority, do it only if free.

## 3. Site census (verified two independent ways)

Counts from `grep -B1 __builtin_debugtrap() generated/ppc_xenon/*.cpp` **and** an
independent opcode scan of `build/cache/mcla_pe.bin` `.text`. They agree.

| Instruction + mode | traps | guest addresses |
|---|---|---|
| `vpkd3d128` SH=2 MB=1 ME=0 (type 2 pack) | **4** | `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` |
| `vupkd3d128` UIMM=20 (type 5 unpack) | **94** | first `0x822F1B80`, `0x822F1B9C`, `0x822F1C08`, `0x822F1C10`, `0x822F657C`, `0x822F66AC`, … all in `0x822Fxxxx` |
| `vupkd3d128` UIMM=8 (type 2 unpack) | **1** | `0x821B43D8` |
| `vcmpbfp128` | **1** | `0x825CEA2C` |

All 5 type-2 sites are inside the vertex-fetch emulator module (`0x821B35xx`–
`0x821B47xx`). The 94 type-5 sites are a separate cluster in `0x822Fxxxx` and may
not be reached during boot at all.

Raw-scan artifacts to **ignore**: `vpkd3d128 SH=3 MB=1 ME=3` (`0x82420A38`) and
`SH=0 MB=3` (`0x821746D4`, `0x825E2044`) match the opcode pattern but produce
**no** debugtrap in `generated/` — they are outside recompiled functions or are
misdecoded data.

## 4. Routes — pick ONE, in this order

### Route A (RECOMMENDED): `midasm_hook` in the tracked TOML

`generated/` is **gitignored** (`.gitignore:10`) but `config/mcla_xenonrecomp.toml`
is **tracked**. So a hook keeps the entire change in version control and leaves the
vendored recompiler pristine (`.research/` is also gitignored — `.gitignore:22`).

Hook shape, parsed at `recompiler_config.cpp:95-138`. `[[midasm_hook]]` is a
**top-level** array, not under `[main]`:

```toml
[[midasm_hook]]
name = "mcla_Vpkd3d128_type2"
address = 0x821B3814
registers = ["v63", "v0"]
after_instruction = false
jump_address = 0x821B3818
```

The host function is emitted as a call taking the named registers **by C++
reference**; `jump_address` skips over the trapped instruction. Repeat per site
(5 entries for type 2, or 94+1 if type 5 turns out to be needed — at that point
switch to Route B, 94 TOML entries is not maintainable).

**Verify first, before writing any code:**
- that `registers` accepts **vector** registers (`v0`/`v63`), not just GPRs —
  check `.research/UnleashedRecomp`'s SWA config for a precedent
  (`docs/MCLA_REBUILD_PLAN.md:415` cites ~150 hooks at `SWA.toml:84-1155`);
- that a hook emitted `after_instruction = false` + `jump_address` really does
  bypass the `__builtin_debugtrap()` rather than falling through to it;
- how the hook sees the vector: XenonRecomp stores guest VMX128 registers
  **reversed**, so `v0.u32[0]` in a hook may be guest lane 3. Confirm empirically
  with one `MCLA_LOG_*` of all four lanes before trusting any math.

### Route B: patch XenonRecomp and regenerate (needed if type 5 is reached)

Edit `.research/XenonRecomp/XenonRecomp/recompiler.cpp`:
- `case PPC_INST_VPKD3D128` at **:2011** — add `case 2:` to the inner switch
- `case PPC_INST_VUPKD3D128` at **:2203** — add `case 2:` and `case 5:`
- `case PPC_INST_VCMPBFP128` at **:1847** — replace the debugtrap

Then, **in this order, with a gate at each step:**

1. **Save the patch.** `.research/` is gitignored — export
   `git -C .research/XenonRecomp diff > tools/xenonrecomp_vmx128.patch` (or diff
   against a pristine copy) and commit **the patch file**, or the work is lost on
   the next clone.
2. **Build the tool.** No XenonRecomp binary exists — `build/` and `build-msvc/`
   have CMake caches + `build.ninja` but no `.exe`.
   `rebuild_clang.bat` does `cmake -S . -B build-clang -G Ninja
   -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --build build-clang`.
3. **PROVE REPRODUCIBILITY — hard gate.** Copy `config/mcla_xenonrecomp.toml` to a
   temp file with `out_directory_path = "build/xr_baseline"`, run the **unmodified**
   tool, and `diff -r build/xr_baseline generated/ppc_xenon`. If it does not
   reproduce byte-for-byte, **STOP** — the checked-in TUs came from a different
   revision and regenerating would swamp your change and probably regress boot.
   Fall back to Route A or to host `PPC_FUNC` overrides.
4. Only then apply the patch, regenerate into `generated/ppc_xenon`, rebuild
   `mcla.exe`, soak.
5. **Also verify how `generated/` is meant to be produced on a fresh clone** — it
   is gitignored, so there must be a CMake step or documented manual step. If
   there isn't, that is a pre-existing reproducibility hole worth recording.

Invocation: `XenonRecomp [input TOML file path] [PPC context header file path]`
(`XenonRecomp/main.cpp`). The header arg is the project's `ppc_context.h`.

### Route C (fallback): host `PPC_FUNC` override

Override the few affected guest functions host-side. **Zero existing hooks** on
`821B3548` / `821A0800` / `821917A8` / `82192150` / `82192448`, so all are free to
own (Golden Rule 1 satisfied). But `sub_821B3548` alone is ~1150 lines of
recompiled code (`ppc_recomp.14.cpp:22989-24138`) — hand-rewriting it is
error-prone, and the 94 type-5 sites in `0x822Fxxxx` cannot be rewritten by hand
at all. Use only if Routes A and B both fail.

## 5. Execution stages — stop and soak at every gate

Do **not** implement everything up front. The boot dies at the *first* trap, so
each fix reveals the next blocker.

**Stage 0 — baseline (5 min).** Confirm the tree builds and reproduce the trap:
`MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat`, then run
`build\mcla.exe > boot_stdout_vmx0.log 2> boot_stderr_vmx0.log`. Expect exit 3 and
`code=0x80000003 ... lr=821B37F4 ... [4] __imp__sub_821B3548 +0x172B`.
*Gate: that line must be present, or your baseline is not the same as ours.*

**Stage 1 — type 2 pack (the actual boot blocker).** Implement §2.1 for the 4
sites (Route A: 4 hook entries; Route B: one `case 2:`). Soak →
`boot_stdout_vmx1.log`.
*Gate: no `0x80000003` at `0x821B3814`. Record whatever the new terminal event is.*

**Stage 2 — re-triage.** Read the new failure. Three outcomes:
- another VMX128 trap → continue to the relevant stage;
- a genuine guest assert / AV → that is a *new* finding, write it up, do not
  paper over it;
- the boot progresses to draws → check `DRAW_INDEXED`, `SUBMIT r5`, `FRAME-END`,
  `NATIVE-PRESENT` counts against the session-74 baseline
  (`DRAW_INDEXED`=0, `SUBMIT`=14, `FRAME-END`=2, `NATIVE-PRESENT`=4,
  `SWAP-COMP`=9, `INFLATE-EMPTY`=8).

**Stage 3 — type 2 unpack** (§2.3, 1 site, `0x821B43D8`) if reached.

**Stage 4 — type 5 unpack** (§2.2, 94 sites) **only if the boot reaches
`0x822Fxxxx`.** If it does, Route A is no longer viable (94 entries) — go Route B.

**Stage 5 — `vcmpbfp128`** (§2.4, 1 site) — optional.

**Stage 6 — regression check.** The guard run's good numbers must not move:
`PHYS-OVERRUN`=0, o1heap AV=0, `MmAllocatePhysicalMemoryEx: FAILED`=0,
`BLIT-OOB-GUARD` ≤2. If `BLIT-OOB-GUARD` count changes, the vertex-fetch fix
perturbed the surface path — investigate, don't just accept it.

**Stage 7 — docs.** Update `docs/HANDOFF_NEXT_AGENT.md`: retire priority #1,
record the new top blocker, add the soak logs to the evidence table.

## 6. Risks and gotchas

- **R1 — guest/host vector reversal.** XenonRecomp stores VMX128 registers
  reversed relative to Altivec; its own D3DCOLOR cases compensate with
  `indices[] = {3,0,1,2}` and the comment "handling vector reversal here too",
  while its float16_4 pack applies no permutation. Get this wrong and every lane
  is silently swapped. **Log all four lanes at one site before trusting any math.**
- **R2 — `.research/` and `generated/` are both gitignored.** Any fix that lives
  only there is invisible to the next clone. Commit the patch and/or the TOML.
- **R3 — the `pack`/`shift` permute.** XenonRecomp's D3DCOLOR case collapses
  Xenia's byte permute to `vD.u32[ME] = packed`. All 4 type-2 sites have
  `MB=1, ME=0`, which in Xenia is `MakePermuteMask(0,0,0,1,0,2,1,3)` over
  `(oldVD, packed)` — **not** obviously the same as "write dword 0". Check what
  reads `v63` after `0x821B3814`; if nothing does (the site does
  `vor128 v63,v0,v0` first, so `v63` is a scratch copy), the simplification is
  safe. If something does, implement the permute.
- **R4 — rounding.** Xenia packs 2_10_10_10 by masking/shifting IEEE float bits,
  which truncates. The scalar sketch in §2.1 truncates too. If colours look
  banded or off-by-one, switch to round-to-nearest and compare.
- **R5 — do not "fix" the trap by skipping the instruction.** Returning without
  writing `vD` leaves a stale vector and produces silently wrong vertex data —
  far worse than a clean `int3`, and it would look like progress.
- **R6 — one hook owner per guest address.** Re-check before adding anything;
  `sub_821B3548` and friends are currently unowned but that may have changed.

## 7. Definition of done

- No `0x80000003` vectored exception in the soak log.
- Every added mode has a soak-log line proving it executed (handoff rule:
  *do not claim a gate without a soak log line*). Add a counter + a throttled
  `MCLA_LOG_INFO` per new mode, like the existing `BLIT-CAP` census.
- `BLIT-OOB-GUARD` and the AV-storm numbers unchanged (Stage 6).
- Fix is in **tracked** files (TOML hook entries, or a committed `.patch` plus a
  note on how to build the tool and regenerate).
- `docs/HANDOFF_NEXT_AGENT.md` updated.

## 7b. SPIKE FINDINGS (session 74b) — corrections, do not re-derive

Four things were verified by execution. Three of them **correct §4 above.**

1. **The XenonRecomp binary DOES exist.** §4 Route B step 2 is wrong — my earlier
   `find -maxdepth 3` only looked in `build/` and `build-msvc/`. The working exe is
   `.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe`
   (`rebuild_clang.bat` → `ninja: no work to do`, exit 0, already up to date).
   `build-clang/XenonAnalyse/XenonAnalyse.exe` exists too. **No tool build needed.**

2. **`midasm_hook` DOES accept vector registers — Route A is viable.** Confirmed
   from UnleashedRecomp's shipped config
   `.research/UnleashedRecomp/UnleashedRecompLib/config/SWA.toml`, e.g. line 943:
   ```toml
   [[midasm_hook]]
   name = "WorldMapProjectionMidAsmHook"
   address = 0x82574E00
   registers = ["v63", "v62"]
   ```
   Other examples use `["v127","f24"]`, `["r30","v61"]`, `["v63","v62"]`,
   `["f0","v62"]`, `["v62"]`. So `v63`/`v0` for our trap site is fine. Note these
   examples set **no** `jump_address` / `after_instruction` — those keys are parsed
   (`recompiler_config.cpp:114-132`) but unproven against a `__builtin_debugtrap()`.
   **Still unverified: that `jump_address` actually skips the trap** rather than
   falling through to it. Test that on one site before writing all four.

3. **The config path must be a BARE FILENAME, run from the repo root.**
   `recompiler_config.cpp:5` does
   `directoryPath = configFilePath.substr(0, configFilePath.find_last_of("\\/") + 1)`.
   If the path contains a separator, `directoryPath` becomes e.g. `config/`, and
   line 74 then resolves the switch table as
   `config/.research/XenonRecomp/XenonAnalyse/jump_tables.toml` — which does not
   exist. Passing a bare filename makes `find_last_of` return `npos`, so
   `substr(0, npos+1)` == `substr(0,0)` == `""`, and every relative path resolves
   against the cwd. **So: copy the temp config into the repo root, not `config/`.**
   (`build/game_data/default.xex` and `.research/.../jump_tables.toml` both exist
   and are correct relative to the repo root.)

4. **The header argument is copied VERBATIM into `ppc_context.h`, and the obvious
   source file is NOT the right one.** `recompiler.cpp:2583-2596` emits
   `#pragma once` + `#include "ppc_config.h"` + a blank line, then splices in the
   entire contents of `headerFilePath` and saves it as `ppc_context.h`.
   `.research/XenonRecomp/XenonUtils/ppc_context.h` (703 lines) does **not** match
   the generated `ppc_context.h` (739 lines, body differs after stripping the
   4-line prefix). So the project uses its **own** modified context header, whose
   location is **not yet found**. Until it is, a baseline regeneration cannot be
   byte-compared.
   **To locate it:** search the repo (excluding `generated/` and `.research/`) for a
   file whose first lines are `#pragma once` / `#include "ppc_config.h"` and which
   is ~735 lines — or diff candidates against
   `tail -n +5 generated/ppc_xenon/ppc_context.h`. Alternatively reconstruct the
   input mechanically with that same `tail -n +5`, which guarantees byte-exactness
   without knowing the original path.

**Net effect on the plan:** Route A gets cheaper (no tool build, vector registers
confirmed). Route B's reproducibility gate (§4 step 3) is **still blocked** on
finding the context header from item 4 — that is the single next action.

## 8. Reference locations

| What | Where |
|---|---|
| XenonRecomp pack/unpack cases | `.research/XenonRecomp/XenonRecomp/recompiler.cpp:2011, :2203, :1847` |
| XenonRecomp hook config parsing | `.research/XenonRecomp/XenonRecomp/recompiler_config.cpp:95-138` |
| XenonRecomp build script | `.research/XenonRecomp/rebuild_clang.bat` |
| Project recompiler config | `config/mcla_xenonrecomp.toml` |
| Xenia opcode dispatch | `src/xenia/cpu/ppc/ppc_emit_altivec.cc:2054, :2160, :596` |
| Xenia pack/unpack math | `src/xenia/cpu/backend/x64/x64_seq_vector.cc:2230 (2101010 pack), :2595 (float16_4 unpack)` |
| Xenia VMX128 notes | `docs/ppc/vmx128.txt` in the xenia repo (not yet read) |
| Trapping guest function | `generated/ppc_xenon/ppc_recomp.14.cpp:22989-24138` (`sub_821B3548`), trap at `:23432` |
| Fetch-instruction loop | `generated/ppc_xenon/ppc_recomp.12.cpp:27277` (`sub_821A0800`) |
| Guest image | `build/cache/mcla_pe.bin`, **identity mapped: file offset = VA − 0x82000000**, instruction words **big-endian** |
