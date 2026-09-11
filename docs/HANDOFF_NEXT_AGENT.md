# HANDOFF — next agent, read this first

**Date:** 2026-09-11 (session 75e — IDA MCP)  
**Goal:** Midnight Club LA native D3D12 renderer — working game with visible frames.  
**Repo:** `E:\mcla pc` (do not delete; overlay notes in `audit-clean/`).

---

## PLAIN STATUS (vibe-coder summary)

**Where we are:** The game boots, shows loading screens, and can present
frames on your GPU. It does **not** draw the actual 3D world yet.

**What got fixed this week:**
1. A crash that killed the process on a missing CPU vector instruction
   (`vpkd3d128`) — implemented, trap is gone.
2. Heap corruption storm from a bad blit — already closed last session.

**What's still broken (in order):**
1. **Textures never finish loading.** The game opens "texture dictionaries"
   (packs of named images) but never *fills* them. Every lookup like
   `"car_paint"` misses and falls back to a dummy 32×32 texture with no ID.
   That's the `0xCDCDCDCD` spam in the logs.
2. Because assets never finish, the game **stays on loading screens** and
   never binds vertex buffers → `DRAW_INDEXED` stays 0 → no world geometry.
3. Only dummy HUD draws run (`sub_8217B7B0`). The real draw path
   (`82227428` with type `0x20000000`) never fires.

**What to work on next:** Named-texture INSERT never runs.
- Insert = `sub_82185468` → hash `0x82839E2C`
- `globaltex.list` exists on disk (cars, 575 bytes) but preload
  (`82185A40`) is **not a recompiled entry** — IDA put it inside
  `sub_82185648`, but the TU has no `loc_82185A40` label (not a branch
  target). That whole file-preload path is unreachable from compiled code.
- `sub_82185648` **does** run (TEXLOAD ×3) but only as individual creates:
  `"Not Implemented"`, `"uiOverlay"`, `"uiOverlayDepth"` — not the bulk list.
- Dictionary objects after register (`TEXDICT-OBJ` dump) are **empty shells**
  (`[0,0,0,1,0,0,0,0]` etc). Some later ones have a small linked pointer.
- So: containers open, contents never filled. Next is the `.xtd` / RSC
  parse that should write the name table into the dict before register.

### RSC5 / XCompress layout (session 75g addendum)

Sample `vnyl_tears_05.xtd` (1227 bytes):
```
0000: 05 43 53 52          version 5 + "CSR"  (= RSC5)
0004: 00 00 00 09 c8 08 00 10
000c: 0f f5 12 ef          XCompress magic 0x0FF512EF
```
XCompress payload starts at **+0xC**. The inflate caller already does
`inLeft = bytesRead - 12` (header skip). INFLATE #1 sees real magic and
passes through. After a small file is consumed, the next refill returns 0
→ `inLeft = -12` → we INFLATE-SKIP (that part is EOF, not a format bug).

`.xtd` files are **never opened by path** in soak — only RPF packfiles
(`xarchive_audlo.rpf`, `xarchive_cache.rpf`). Texture data comes from
inside those archives. Empty dicts are whatever `8218B000` registers,
not necessarily a finished `.xtd` load.

**How to run / check:**
```bat
ninja_build.bat
build\mcla.exe
:: logs in boot_stdout_*.log — look for TEXINSERT, TEXDICT, REBASE-POISON, DRAW_INDEXED
```
**RE tools:** IDA MCP on `127.0.0.1:8745` (preferred) · Ghidra on `:8089` ·
generated TUs are the decompiled game code (never edit `generated/`).

---

## SESSION 75E — IDA MCP UP; DICTIONARY REGISTER RUNS BUT LOOKUPS STILL MISS

### IDA setup (now live)
```powershell
# already listening on 127.0.0.1:8745, proxy connected
ida-pro_check_connection  # OK, mcla_pe.bin base 0x82000000
```
Start script: `tools/start_idalib_mcp.ps1` (or `idalib_jsonrpc_server.py`).
Use IDA for xrefs/Hex-Rays; generated TUs remain ground truth when bounds are wrong.

### Texture dictionary path (IDA Hex-Rays)

| Addr | Role |
|---|---|
| `sub_821849C0` | named lookup: `"none"` → `0x82839CF0`; else hash `sub_82183E80(&0x82839E2C)`; else walk dict list `0x82839ED0`; miss → fatal `"Unable to find texture '%s' in any active texture dictionary!"` @ `0x82009E20` |
| `sub_82197598` | **pgDictionary register** — `*(entry+8)=oldHead; head=entry` into `0x82839ED0` |
| `sub_8218B000` | mapped caller of 82197598 (census hook) |
| RTTI | `rage::pgDictionary<rage::grcTexture>` @ `0x827DC77C` |

`sub_82197598` is **not** in `ppc_func_mapping.cpp` (no `__imp__`) — cannot `PPC_FUNC` it.
Census lives on `sub_8218B000`.

### Soak `boot_stdout_c75f.log` (70s)

| Marker | Hits |
|---|---|
| `TEXDICT-CALLER` `8218B000` | **10** (r4 always `82860C18`, r3 = pool16 A0110xxx) |
| `TEXINIT` / `GFXINIT` | 2 / 1 (none/nonresident specials still OK) |
| `REBASE-POISON` | 12 (named textures still miss) |
| `DRAWDISP` / `DRAW_INDEXED` | 0 / 0 |

**Dictionaries register.** Named lookups still miss → dictionary *contents*
are empty (inflate never filled the pgDictionary body), not a register bug.

### Next (ranked)
1. Who should populate a loaded `pgDictionary<grcTexture>` (name table +
   texture objects) after inflate — likely another `8218Bxxx` / `8219xxxx`
   sibling once the RSC body is valid.
2. Confirm inflate of the **texture** archive (not audlo) actually produces
   non-empty output.
3. Still no world draws (`82227428` dispatch `0x20000000`).

---

## SESSION 75D — TEXINIT RUNS; NAMED REGISTRY FILL STILL MISSING

### Ghidra MCP (live on :8089, program `mcla_pe.bin` base `0x82000000`)

Workflow that works on this raw image:
1. `ghidra_load_program` with `PowerPC:BE:64:default`
2. `ghidra_set_image_base 0x82000000`
3. **Clear `no-return` on ABI thunks** `0x823D91E4/EC/F0/F4/F8/FC` (savegprlr family) — without this the decompiler truncates every function at the prologue
4. `ghidra_clear_flow_and_repair` on the range, then `decompile_function`

### Texture registry (decoded)

| Addr | Role |
|---|---|
| `sub_821811C0` | name lookup: special-string compare vs `"none"` @ `0x82009E18`, else hash `sub_82180680(table=0x82839E2C)` + linked list walk |
| `sub_82180680` | hash find (`FUN_821C95A0` / `FUN_823DB730`) |
| `sub_82180A30` | **init**: memset `0x82839D08`, creates `"none"`/`"nonresident"` objects into `0x82839CF0/CF4` |
| `sub_82177248` | sole caller of `82180A30` |
| `sub_82177948` | graphics-init bundle (`82177248` + more) |

Strings at `0x82009DFC`: `"Not Implemented"` / `"nonresident"` / `"none"` / `"Unable to find texture '%s'"`.

### Soak `boot_stdout_c75e.log` (80s)

| Marker | Hits |
|---|---|
| `GFXINIT-census` `82177948` | **1** |
| `TEXINIT-CALLER` `82177248` | **1** |
| `TEXINIT-census` `82180A30` | **1** |
| `REBASE-POISON` | 32 (named textures still miss) |
| `DRAWDISP` `82227428` | **0** |
| `DRAW_INDEXED` | 0 |

**Special-name init DOES run.** Fallbacks for `none`/`nonresident` exist. Named
textures still miss the hash table → 64-byte CDCDCDCD objects → REBASE-POISON.

### Still open
1. **Who inserts into hash table `0x82839E2C`?** (named .xtd load → register)
2. Why `82227428` never sees dispatch `0x20000000` (world draws).
3. Do not add more short-circuits.

### Census in tree
SETSTREAMS / DRAWWRAP / DRAWDISP / LOADGATE / TEXINIT / GFXINIT +
SUBMIT lr/streams/vb0 + INFLATE-SKIP head dump.

---

## SESSION 75C — LOADING GATE MAPPED (still no world draws)

### New census (log-only, soak `boot_stdout_c75d.log`)

| Marker | Hits | Meaning |
|---|---|---|
| `DRAWDISP-census` `sub_82227428` | **0** | real-draw dispatcher **never entered** |
| `LOADGATE-census` `sub_82178F38` | **0** | first gate inside SetStreams path **never entered** |
| `SETSTREAMS` / `DRAWWRAP` | 0 | bind + draw wrap dead (as 75b) |
| `sub_82420BA8` | 2 | dummy only (`lr=8217BB10`, streams=0) |
| `FRAME-END` / `NATIVE-PRESENT` | 3 / 4 | loading-screen HUD path healthy |

**Conclusion:** the process never leaves the loading-screen render path.
World-geometry submission (`82227428` → `0x20000000` branch → `8217A470`) is
unreached. Presents work because loading HUD uses the dummy submit.

### Inflate `-12` / magic `525DE064` (NOT the geometry gate)

Explore + soak (`INFLATE-SKIP` with `inPtr`/`head=` dump):
- Caller `sub_821BC140` sets `inLeft = bytesRead - 12` (header skip).
- Short/zero async read on `xarchive_audlo.rpf` (LO-res **audio**, 1.3GB)
  → `inLeft = -12` → we peek OOB and see random bytes (`525DE064…`).
- `525DE064` is **not** a format magic (0 hits in src/ + generated/).
- Do **not** treat INFLATE-SKIP as the root gate. The 8242FC1C wait is
  the healthy GPU-worker tick (`40004D7C`), not a load stall.

### What still blocks a working game

1. **Complete resource registration** so lookups stop creating CDCDCDCD
   64-byte texture objects (`prodLr=821853AC` / `8218542C`). That is the
   session-73 root: loaders never run, not a corruptor.
2. Only after that will `82227428` see the `0x20000000` dispatch type and
   stream bind can run → `DRAW_INDEXED` can go >0.
3. Optional later: short-read on audio archive (`821BC334`) if audlo load
   actually matters for boot completion.

### Ranked next probes

1. Texture registry fill: who should write obj+4 after `sub_82184F58`
   fallback create — find the loader that never runs (inflate/XCompress
   resource body → register).
2. Census `sub_825F48E8` (other SetStreams site) + `sub_82312FEC` mode/`0x1000` bit.
3. Do not add more short-circuits.

### Census left in tree
`SETSTREAMS`/`DRAWWRAP`/`SETSTREAMS-CALLER`/`DRAWDISP`/`LOADGATE` +
`SUBMIT` lr/streams/vb0 + richer `INFLATE-SKIP` head dump.
Ghidra/IDA MCP still optional; TUs + explore are enough for this path.

---

## SESSION 75B — DRAW_INDEXED MAPPED (still 0, but now we know why)

### Real vs dummy draw paths (TU-mapped + soak-proven)

| Path | Chain | Status |
|---|---|---|
| **Real geometry** | `sub_8217A470` → `sub_8241BE78` SetStreams (writes `dev+12748` count + VB descs at `dev+12756`) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8` | **NEVER RUNS** (0 hits on all three) |
| **Dummy/HUD** | `sub_8217B7B0` (lr=`8217BB10`) → `sub_82420BA8` with **r5=0, streams=0** | the only 20BA8 hits in soak |

Evidence: `boot_stdout_c75.log` — `SETSTREAMS-census`=0, `DRAWWRAP-census`=0,
`SETSTREAMS-CALLER`=0, `SUBMIT-census #1/#2 lr=8217BB10 streams=0 vb0=[0,0,0]`.
Presents still land (FRAME-END=3, NATIVE-PRESENT=4). Still in loading.

**Conclusion:** `DRAW_INDEXED=0` is a **symptom of never leaving loading /
 never binding streams**, not a draw-builder bug. Next work is the loader
 path (inflate / resource init / CDCDCDCD initializers), not more GPU hooks.

### Census left in tree (log-only)
- `SUBMIT-census` now logs `lr=` + `streams=` + `vb0=[base,stride,size]` (`dev+12748/12756`)
- `SETSTREAMS-census` `sub_8241BE78`
- `DRAWWRAP-census` `sub_8241C308`
- `SETSTREAMS-CALLER` `sub_8217A470`

### Workflow notes (token-efficient RE)
- Generated TUs are ground truth; Ghidra/IDA MCP are optional xref tools.
- Ghidra headless launcher: `C:\Users\abdul\.config\opencode\ghidra-mcp\run-ghidra-mcp-headless.bat`
  (not running this session). IDA needs Edit→Plugins→MCP.
- Explore subagent for caller mapping; keep main window for decisions + edits.

---

## SESSION 75 — VMX128 TYPE-2 PACK LANDED (trap no longer kills boot)

### What was implemented (Route A, plan `docs/PLAN_VMX128.md`)

`vpkd3d128` SH=2 MB=1 ME=0 (PACK_TYPE_UINT_2101010) is now handled by
midasm hooks + a host function, not by XenonRecomp's `__builtin_debugtrap()`.

| Piece | Where |
|---|---|
| TOML hooks (4 sites) | `config/mcla_xenonrecomp.toml` `[[midasm_hook]]` @ `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` |
| Host impl | `src/vmx128_pack.cpp` `mcla_Vpkd3d128_type2` |
| CMake | `CMakeLists.txt` adds `src/vmx128_pack.cpp` |
| Reconstructed header | `src/ppc_context.h` (`tail -n +4` recipe, roundtrip `cmp`-clean) |

**Semantics (corrected from plan §2.1).** Type 2 does **not** take raw
[-1,1] floats. The guest pre-biases into the IEEE bits of a value near 3.0
(constant vectors at `0x820100F0` = `{3,3,3,3}` and `0x82010100` =
`{-2^-13,-2^-13,-2^-13,-3*2^-22}`; `vnmsubfp v0,v12,v13,v0`). Xenia's
`EmitUINT_2101010` clamps those bits to
`[0x403FFE01, 0x404001FF]` (XYZ) / `[0x40400000, 0x40400003]` (W) and ANDs
with `0x3FF` / `0x3`. Host lane order is reversed (D3DCOLOR convention):
`host.f32[0]=W, [1]=Z, [2]=Y, [3]=X`. Consumer after the trap
(`stvx128` + `lwz 156(r1)` through `VectorMaskL`) reads **`vD.u32[0]`** —
ME=0 write is sufficient.

**Emitted shape** (verified in `build/xr_hooks/ppc_recomp.14.cpp`):
```
mcla_Vpkd3d128_type2(v63, ctx.v0);
goto loc_821B3818;          // skips the dead __builtin_debugtrap()
```

### Regen reproducibility (plan §4 Route B step 3 — DONE)

Unmodified tool `.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe`,
bare config filename from repo root, header `src/ppc_context.h`:
- **181/183** files byte-identical to `generated/ppc_xenon/`.
- `ppc_context.h`: trailing newline only.
- `ppc_recomp.10.cpp`: **hand safety patch inside `sub_8218CC70`**
  (indirect-branch targetFn/basePtr validation) that the recompiler does
  not emit. **Do not full-replace that file** or the session-38 null-dispatch
  AV returns.

Surgical install used: regen with hooks into `build/xr_hooks`, copy **only**
`ppc_recomp.14.cpp` over `generated/ppc_xenon/`. Everything else untouched.

### Soak evidence (session 75)

| Run | Result |
|---|---|
| `boot_stdout_vmx1.log` | exit ~35s on **new** early fatal `Resource '%s': %s` `legals/legals` (poison family B, lr=`825EF1DC`). **Not deterministic.** |
| `boot_stdout_vmx2.log` | 90s soak, still running when killed. FRAME-END=3 NATIVE-PRESENT=4 SWAP-COMP=9. **No `0x80000003`.** |
| `boot_stdout_vmx3.log` | 180s soak, still running. Same present counts. DRAW_INDEXED=0. No VMX128 trap. |

**Gate: no `0x80000003` in any session-75 soak.** The session-74 terminal
event is gone.

**NOT yet proven executed:** `VMX128-PACK` counter stayed 0 — the
vertex-fetch format-10 path was never reached. Hypothesis: in the session-74
guard run that trap was reached *because* of the fmtEnum=0 blit overrun
chain; with `BLIT-OOB-GUARD`=0 this run never enters that path. The hooks
are in the binary and will fire when it does. Do not claim the pack is
runtime-validated until a soak contains a `VMX128-PACK` line.

### Still open after this session

1. **`DRAW_INDEXED`=0** — still the real frontier. SUBMIT r5 empty; likely
   gated on loaders actually initializing surfaces (CDCDCDCD → use-sites).
2. **Poison family B** — `legals/legals` fatal at `825EF1DC` (soak1). Same
   class as meshtextures; `P5-MISSFIX` logs but does not skip this site.
3. **Type-2 unpack / type-5 unpack / vcmpbfp128** — still unimplemented;
   only needed if those paths are reached.
4. Continuous present soak past 4 — SWAP-COMP=9 matches the s74 baseline;
   not independently re-verified for more presents.

---

## SESSION 74 — HEAP AV STORM CLOSED (handoff item 1 CLOSED). NEW BLOCKER: UNIMPLEMENTED VMX128 OPS

### The corruptor was a blit overrun, not a poison pointer

Full chain, every step backed by a soak-log line (`boot_stdout_blit3.log` →
`boot_stdout_guard.log`):

1. `sub_82182FA0` (surface copy/update) calls the copy-rect wrapper
   `sub_824321E0` with **`dstW=512 dstH=640 fmtEnum=0x0 flag=1`**. Compare the
   7 legitimate mip-chain blits in the same run: `256×256 fmtEnum=0x30 flag=0
   tileShift=0..6`. `fmtEnum=0` is the invalid/uninitialized D3DFORMAT (falls
   through `sub_8240F2A8` to a 1×1-block default); `flag=1` selects the
   direct-copy path that skips `sub_82432D30`, leaving `origin=0`.
2. That reaches the tiled 2D blit `sub_82431A40` as `dst=CAEBB000
   rect=[0,0,512,640] fmt=0`. **The copy extent is purely RECT-driven**
   (`rows=y1-y0`, `per-row=x1-x0`) — it writes `need=0x50000` BYTES. The
   format/bpp in `r10` only sizes an internal staging alloc and is *never*
   multiplied into the copy size. (I got this wrong first and computed
   `w*h*4`; the observed gaps proved bytes, not dwords.)
3. The destination's tracked allocation is only **`size=0xA000`** → overrun of
   **`0x46000` (286 KB)**, landing exactly on the arena allocation frontier
   (`0xCAEC5000 − 0xA0000000 ≈ allocated=720,152,320`), i.e. on o1heap's
   **free** fragments. First probe hit: `PHYS-OVERRUN @ CAEC5004 gap=0x4`
   (dst end = `0xCAEBB000+0xA000`).
4. The bytes copied are `0xCDCDCDCD` — every `BLIT-SRC` descriptor dump is
   pure poison (one leaks ASCII `73746172 5F676C6F 7700` = **"star_glow"**),
   i.e. the source surface was never initialized. Fragment headers then read
   back as poison: `rax=0x337373737373737` = `0xCDCDCDCDCDCDCDCD >> 6`
   (`log2Floor(header.size/64)` in `unbin()`), `rcx=r11=0xCDCDCDCDCDCDCDCD`
   (`next_free`).
5. `unbin()` derefs poison → AV → `SehO1Allocate` swallows it, returns null →
   `MmAllocatePhysicalMemoryEx: FAILED ... allocated=720152320 cap=1610612160
   oomCount=0` (**not** a genuine OOM) → guest gets `E_OUTOFMEMORY` →
   `TEXCREATE-SC` converts it to success → guest derefs a null texture →
   fatal read of guest `0x00000000` → exit 139.
   Timing: overruns `21.933–21.943` → first o1heap AV `21.953` → first alloc
   FAILED `21.960`.
6. `o1heapDoInvariantsHold` never fired (0 hits) — it only validates
   bin/mask/diagnostics consistency and never walks fragment headers. That is
   why the poison went undetected until allocation time.
7. `HEAPHDR-STORE = 0`: no guest store touches `A0000000..A0000800`, so the
   `O1HeapInstance` (bins/mask) is never directly scribbled. Corruption is
   exclusively in fragment headers deeper in the arena.

**Correction to the session-73 handoff:** `0x82431D18` was recorded as "inside
`sub_82431A40` (kernel/XAM territory, filling big 0xCA-0xAF buffers — XAM debug
fill, harmless noise)". Wrong. Both `0x82431D18` and `0x82431A40` are
**memcpy** (`bl 0x823DA950`) inside a tiled 2D surface blit, and that blit *is*
the corruptor.

### Mitigation landed: `BLIT-OOB-GUARD`

`src/gpu_device.cpp` now owns `PPC_FUNC(sub_82431A40)` and
`PPC_FUNC(sub_824321E0)`. The former skips the guest blit body **only** when
the overrun is provable — i.e. the destination matches a tracked allocation
*exactly* and `rectW*rectH > allocSize`. Every legitimate blit (#1–#7) fits
its allocation and is untouched.

Measured, guard run vs the immediately preceding run:

| Marker | before | after guard |
|---|---|---|
| exit code | 139 (segfault) | **3** |
| `PHYS-OVERRUN` | 64 | **0** |
| o1heap AV | 34 genuine (+68 cascading) | **0** |
| `MmAllocatePhysicalMemoryEx: FAILED` | 34 | **0** |
| `TEXCREATE-SC` | 1 | **0** |
| `REBASE-POISON` | 61 | **229** (boot ran far past the old ceiling) |

Two blits were guarded, both `fmt=00000000`:
`dst=CAEBB000 size=0xa000 need=0x50000 overrunBy=0x46000 rect=[0,0,512,640] src=A02B6570`,
and `dst=CAEDD000 size=0x1000 need=0x8000 overrunBy=0x7000 rect=[0,0,256,128] src=A02B6790`.

**This is a labelled mitigation, not a fix.** The guard is only sound because
the allocation match is exact. The faithful fix is upstream: make the source
surface initialize (consistent with the session-73 rule — *killing CDCDCDCD =
making the loaders run, NOT more zeroing at use-sites*), so that `fmtEnum`,
`dstW`/`dstH` and the destination size agree. Still open: why does
`sub_82182FA0` pass `fmtEnum=0x0` with `512×640` against a `0xA000`
destination? `fmtEnum` is genuinely zero, not `0xCD` (`clrlwi r6,r3,26` of
`0xCDCDCDCD` would yield `0x0D`), so the field was zeroed or never set —
possibly a side effect of the `REBASE-POISON` short-circuit, whose count rose
61→229.

### Also fixed this session: `SehO1Filter` cascading AVs (real bugfix)

`src/kernel/heap.cpp`. The old guard
`if (gbase && fault >= lo && fault + 64 < lo + 0x100000000ull)` **wraps** for
wild pointers, so it passed for `0xFFFFFFFFFFFFFFF8` and the diagnostic dump
then dereferenced `p[-4]` *inside the filter* — 2 cascading AVs per real one.
Replaced with an unsigned offset test (`off = fault - lo; off < 0x100000000ull`)
plus an `off >= 32 && off + 40 <= 4GB` bound on the dump. Result: 102 AV log
lines → 34 genuine, 0 secondary; log shrank 22887 → 18492 lines.

### NEW #1 BLOCKER: unimplemented VMX128 instructions (host `int3`)

The guarded run ends 10 ms later on `code=0x80000003` — **EXCEPTION_BREAKPOINT,
not corruption**. XenonRecomp emits `__builtin_debugtrap()` for VMX128 modes it
does not implement, so the guest hits a host `int3`.

```
lr=821B37F4 r3=0000000C r4=00000003 r5=00000004 r6=00000001
r7=8200C0A0 r8=A02B6DB0 r9=00000003
 [ 4] __imp__sub_821B3548 +0x172B      [10] __imp__sub_826137A0 +0x638
 [ 5] __imp__sub_821A0800 +0x164C      [11] __imp__sub_82613970 +0x75
 [ 6] __imp__sub_821917A8 +0x3B80      [12] __imp__sub_82611738 +0xFD
 [ 7] __imp__sub_82192150 +0x2B5       [13] __imp__sub_8249CC00 +0x6A
 [ 8] __imp__sub_82192448 +0x29D
 [ 9] __imp__sub_82612B00 +0x1C5
```

Decoded (all verified against raw bytes + generated TUs):

- **The trap is `vpkd3d128 v63,v0,2,1,0` at guest `0x821B3814`**
  (`ppc_recomp.14.cpp:23432`). `lr=0x821B37F4` is **stale** — it is the return
  address of the last guest `bl 0x8218FEB8` at `0x821B37F0`. There is no failed
  comparison: the *successful* format-10 path runs into the unimplemented pack.
- **`r7=0x8200C0A0` is NOT a string.** It is a component-size-per-format dword
  table in `.rdata` (`2,4,6,8 | 4,8,12,16 | 4,4,4,0…`), loaded via
  `addi r24,r9,-16224`. A second table sits at `0x8200C0E0`. No ASCII within
  ±256 bytes.
- **`sub_821B3548` is not an assert printer.** It is a **VMX128 vertex-fetch
  instruction emulator** (guest `0x821B3548`–`0x821B3CB8`,
  `ppc_recomp.14.cpp:22989–24138`). Args: `r3`=fetch-descriptor struct
  (`+4`→sub-desc, `+16`→64-bit VMX128 instr held in `r31`), `r4`=vertex index,
  `r5`=const floats, `r6`=byte index. `r3=0xC` at the trap is the **return
  value of `sub_8218FEB8`** (a bitfield extractor, `ppc_recomp.11.cpp:7603`),
  not an error code.
- Caller `sub_821A0800` (`ppc_recomp.12.cpp:27277`) loops over fetch
  instructions. `sub_821917A8` (`ppc_recomp.11.cpp:11652`) reaches it only via
  `mtctr/bctrl`. `sub_82192448` allocates a 1184-byte object. Subsystem =
  **CPU-side software fetch-shader / vertex-format unpack** — which is very
  likely upstream of priority #2 (`DRAW_INDEXED`=0).
- **Zero existing host hooks** on `821B3548` / `821A0800` / `821917A8` /
  `82192150` / `82192448` / `821B37F4`. All are free to own.

**Census of the gap** (`grep -B1 __builtin_debugtrap()` over `generated/`, and
independently by scanning `build/cache/mcla_pe.bin` `.text` for the VMX128
opcodes — the two agree):

| Instruction | Trap sites | Guest sites | Status |
|---|---|---|---|
| `vupkd3d128` UIMM=4 (SH=1, 2 shorts) | — | 443 | implemented |
| `vupkd3d128` UIMM=20 (SH=5) | **94** | 94 | MISSING — first at `0x822F1B80`, all in `0x822Fxxxx` |
| `vupkd3d128` UIMM=0 (SH=0, D3D color) | — | 1 | implemented |
| `vupkd3d128` UIMM=8 (SH=2) | **1** | 1 | MISSING — `0x821B43D8` |
| `vpkd3d128` SH=0 MB=1 (D3D color) | — | 58 | implemented |
| `vpkd3d128` SH=5 MB=2 ME=2 (float16_4) | — | 47 | implemented |
| `vpkd3d128` SH=5 MB=3 ME=0 | — | 20 | emits float16 path (warns, no trap) |
| `vpkd3d128` SH=2 MB=1 ME=0 | **4** | 4 | MISSING — `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` |
| `vcmpbfp128` | **1** | 1 | MISSING — `0x825CEA2C` |

Note the two `vpkd3d128 SH=3 MB=1 ME=3` / `SH=0 MB=3` variants appear in the
raw scan but produce **no** debugtrap in `generated/` — they are either outside
a recompiled function or misdecoded data. Don't chase them.

**Field layout (derived from `thirdparty/disasm/ppc-dis.c:2517-2536`):**
`vupkd3d128` operands are `{VD128, VB128, UIMM}` where UIMM = bits 16-20.
XenonRecomp switches on `UIMM >> 2`, i.e. **bits 18-20 = the same `SH` field
`vpkd3d128` uses** (`VD3D0`), and bits 16-17 = `MB` (`VD3D1`). So
`UIMM=0/4/8/20` ⇔ `SH=0/1/2/5`. **`SH=5` is already the float16_4 *pack* mode,
so `SH=5` unpack is almost certainly float16_4 unpack** — that is the natural
counterpart for the 94 missing sites and the single highest-value thing to
implement. `SH=2` remains unidentified for both directions; all 5 `SH=2` sites
live in the vertex-fetch emulator, so read that module's branches (it
dispatches on a 4-bit format field, `(instr>>52)&0xF`, with `cmpwi cr6,r9,10`
guarding the trapping path) rather than guessing.

**Where to implement.** `.research/XenonRecomp/XenonRecomp/recompiler.cpp`:
`case PPC_INST_VPKD3D128` at :2011, `case PPC_INST_VUPKD3D128` at :2203,
`case PPC_INST_VCMPBFP128` at :1847 — each has a `default:` that emits the
debugtrap. Config: `config/mcla_xenonrecomp.toml` (full recompile, 179 TUs).
Entry point: `XenonRecomp [input TOML] [PPC context header]`.

**BLOCKERS on that route, verified this session:**
- `.research/` is **gitignored** (`.gitignore:22`) — any XenonRecomp edit is
  local-only and will NOT survive a clone. If you patch the recompiler, copy the
  patch into `docs/` or `tools/` as a `.patch` file and commit *that*.
- **No XenonRecomp binary exists.** `build/` and `build-msvc/` have CMake caches
  and `build.ninja` but no `.exe`. You must build the tool first
  (`rebuild_clang.bat` exists at `.research/XenonRecomp/`).
- **Before regenerating, prove reproducibility:** run the unmodified tool into a
  temp `out_directory_path` and diff against `generated/ppc_xenon`. If it does
  not reproduce byte-for-byte, do NOT regenerate — the diff would swamp your
  change and could regress boot. Fall back to per-function `PPC_FUNC` overrides
  of the affected guest functions instead.

Cheaper alternative if regen is not reproducible: the 5 `SH=2` traps and the
1 `SH=5` unpack trap in `0x821Bxxxx` are all in the vertex-fetch emulator's few
functions — those specific functions can be overridden host-side. The 94
`SH=5` sites in `0x822Fxxxx` cannot reasonably be hand-rewritten.

### Unchanged after the guard
`DRAW_INDEXED`=0, `SUBMIT`=14, `FRAME-END`=2, `NATIVE-PRESENT`=4,
`SWAP-COMP`=9, `INFLATE-EMPTY`=8.

---

## SESSION 73 — ROOT CAUSE OF `0xCDCDCDCD` FOUND (handoff item 1 CLOSED)

The "corruptor" does not exist. The 0xCD is **guest-native fill-on-alloc**,
compiled into the shipped image:

1. **Fill mechanism (static + runtime proven).** The tiny-slab allocator
   `sub_821DE9D8` memsets every returned element before handing it out:
   common tail at `loc_821DEAFC` (ppc_recomp.20.cpp): `li r4,205; lhz
   r5,4(classHead)  # elemsize; mr r3,node; bl memset(0x823D9890)` — on the
   freelist-pop path AND the fresh-slab refill path. Runtime watch
   (`CDCD-FILL ... lr=821DEB0C`) confirms it live. Two startup fills of the
   1352-byte global at `0x8283C5E0` exist too (`sub_8218C9A8` body, memset
   returns `0x8218C9D4`/`0x8218CCCC`; re-armed at runtime by `sub_8217A068`).
   The heap also free-fills with `0xDD` (seen in POISON-DUMP).
2. **Same fill runs on retail HW** (it is in the shipped XEX). So a
   `CDCDCDCD` field read at a use-site = **a field its owner never
   initialized** — i.e. an initializer/loader that runs on HW but not in our
   emu. Stop hunting a writer; hunt the skipped init step.
3. **Poisoned object family A — texture objects (meshtextures fatal).**
   `sub_82185368`/`sub_82185410` are find-or-create-by-name: on lookup miss
   they `sub_82130528(64)` (RAGE small-alloc → 64-byte element, 0xCD-filled)
   and init via `sub_82184F58` (compares name to "none"/"nonresident",
   builds a 32×32 fallback texture, stores handle at obj+32) — **never
   writes obj+4**, the resource-id field later rebased by
   `sub_821B5A60` (consumer `sub_821D2970`, lr `821D29A0`). Producer LRs
   captured in soak: `821853AC`/`8218542C`.
4. **Poisoned object family B — 112-byte resource objects (A0106xxx
   params).** POISON-DUMP shows records `vtable=0x820131A4 @+0, body +4..+5F
   all CDCD, trailing 0xDD free fill`. The vtable sits next to the string
   `Resource '%s': %s (ptr=%p)` (0x82013167). Ctor writes only the vtable;
   the loader that fills the body never runs in our emu.
5. **Conclusion:** killing CDCDCDCD = making the **loaders run** (real
   XCompress inflate, real texture creation/registration) — NOT more
   zeroing at use-sites. The existing REBASE-POISON / P10-PRE zeroing stays
   as boot life-support until then.

### New instrumentation left in tree (all census-only, no behavior change)
- `TSLAB-ALLOC` / `TSLAB-OWNER` (patches.cpp, `sub_821DE9D8` +
  `sub_821C29A0` wrappers): element → (caller LR, elemsize) rings;
  `mcla_SlimTslabFind` (patches.h) resolves producer at use-sites.
- `CDCD-FILL` value watch (`RegisterGuestWatchValue(0xCDCDCDCD)` in
  boot_host.cpp; census in gpu_cp.cpp `PageWatchOnWrite`). `WriteU8`/`WriteU16BE`
  now route byte/halfword 0xCD stores into the watch for registered ranges.
- `PARAM-STORE` probe ranges (A0106000-A0107000, A0197E00-A0197F00) +
  `POISON-DUMP` record dump on first 3 REBASE-POISON hits.

---

## What worked before (session 72 baseline, unchanged this session)

| Milestone | Evidence |
|-----------|----------|
| Boot past KDELAY stall | `SLEEP60270` count 0 |
| Past meshtextures fatal | `REBASE-POISON` + D890 skip |
| Ring-B consumers drain | `PUSH pIdx` 0→1 |
| D3D12 backend up | RTX 3070, 1280×720, test pipeline |
| **Native present** | `FRAME-END` ×9+, `NATIVE-PRESENT` ×6 |
| Depth backup fatal gone | `TEXCREATE-SC` ×1, fatal count 0 |

**Not working (as of session 74):** the AV storm is gone but the process now
dies in ~1s on an unimplemented VMX128 instruction (see SESSION 74, priority
1); `DRAW_INDEXED` = 0 (empty VB/IB); `CDCDCDCD` still poisons object fields.

---

## Architecture (read before changing hooks)

- Guest PPC runs from `generated/ppc_xenon/` (never edit). Image loaded
  from `build/cache/mcla_pe.bin`.
- Host hooks: one owner per guest address (Golden Rule 1). Check
  `PPC_FUNC` / `GUEST_FUNCTION_HOOK` / `SetFunction` before adding another.
- Guest memory: `mcla::kernel::GuestMemoryHeap` (checked BE accessors).
  `WriteGuestU32` → `GuestMemoryView` (page-watch).
- Physical o1heap arena: guest VA **`0xA0000000`**–`0xFFFFFFFF` (1.6GB).
  Pool16 slabs live inside it (`A0014xxx`).
- Task-join table: count @ `0x8283D1A8`, entries @ `0x8283D1C4`, stride 28,
  idx = `(count-1) & tag`. Wait word = `entry+12`.
- XCompress magic: `0x0FF512EF`. Unknown magic → skip-fatal, emit 0.

---

## Short-circuits in tree (do not stack more without root cause)

| Hook | File | What it does |
|------|------|----------------|
| KDELAY-SC | `gpu_device.cpp` E98 | force `pub0` when wait would spin |
| FENCE-SC + ClearTaskJoinBusy | `gpu_device.cpp` | pre-release ev + clear `entry+12` |
| TASKJOIN-SC | `gpu_device.cpp` `sub_821BD220` | main-thread force busy=0 |
| REBASE-POISON | `task_dispatch_trace.cpp` `sub_821B5A60` | zero `*param` if `0xCD` byte |
| P10-PRE | `task_dispatch_trace.cpp` D890 | skip fatal on poison id, return 0 |
| INFLATE-SKIP / EMPTY | `gpu_device.cpp` `sub_821D5E10` | no XCompress → emit 0 / bail |
| TEXCREATE-SC | `patches.cpp` `sub_82177EB0` | r3<0 → 0 (legacy RT unused) |
| SEH o1heap | `heap.cpp` `SehO1Allocate/Free` | AV → null / no-op |
| pow2 align | `heap.cpp` AllocPhysical | round alignment up |
| NtReleaseSemaphore | `imports.cpp` | `GetKernelObject` like Wait |
| **BLIT-OOB-GUARD** (s74) | `gpu_device.cpp` `sub_82431A40` | skip blit when `rectW*rectH` provably exceeds the exact tracked alloc — this is what closed the AV storm |

**Wake-loss fix is a real bugfix** (create/wait/release wrapper mismatch).
The rest are boot-life support until `CDCDCDCD` is killed.

---

## Next steps (priority order — updated session 74)

### 1. Unimplemented VMX128 ops (THE remaining blocker)
> **A full execution plan is written and ready: [`docs/PLAN_VMX128.md`](PLAN_VMX128.md).**
> It resolves the instruction semantics (against Xenia), censuses every trap
> site, ranks three implementation routes and lays out staged soak gates.
> Start there — do not re-derive the semantics.

The guest dies on a host `int3` from `__builtin_debugtrap()`. Full census,
field layout, trap address and the three route options (patch-and-regen vs
midasm-hook vs host override) are in **SESSION 74** above and in the plan. Semantics are now **confirmed**, not conjectural: the mode selector is
`type = IMM >> 2`, so `vpkd3d128 SH=2` is a **2_10_10_10 pack** and
`vupkd3d128 UIMM=20` is a **FLOAT16_4 unpack**. Fix order is
`vpkd3d128 SH=2` first (4 sites — this is what actually kills the boot, at
`0x821B3814`), then re-triage; only reach for the 94 FLOAT16_4 sites if the
boot gets as far as `0x822Fxxxx`.
**Prove regen reproducibility before regenerating** (plan §4 Route B step 3).
That gate is **unblocked as of session 74c** — plan §7b items 4 and 5 give a
byte-exact `src/ppc_context.h` reconstruction recipe (`tail -n +4
generated/ppc_xenon/ppc_context.h`, round-trip `cmp`-clean) and note that
`config/mcla_xenonrecomp_baseline.toml` already exists and is correct (one line
differs from the authoritative config). `build/xr_baseline/` is **empty** — a
prior run failed to produce output; fix the invocation (bare config filename from
the repo root), do not re-derive the config or hunt for the header again.

### 2. Real draws (P5')
- `SUBMIT-census sub_82420BA8` has `r5=0` (VB/IB empty). Find who fills
  `r5`/`r6` in the device-boundary path. `DRAW_INDEXED` must go >0.
- Likely gated by (1): the trapping module *is* the CPU-side vertex
  fetch/format unpack (`sub_821A0800` loops fetch instructions). Expect
  vertex data to start flowing once those instructions run.
- Then pixel-hash validator (`phase3_validator`).

### 3. Upstream root cause of the blit size mismatch (retire `BLIT-OOB-GUARD`)
Why does `sub_82182FA0` pass `fmtEnum=0x0` with `dstW=512 dstH=640` against a
destination allocated as only `0xA000`? The good blits allocate exactly
`w×h×bpp` (256×256×4 = `0x40000`); `0xA000` cannot be expressed as
`512×640×bpp` for any bpp, so the *destination* was sized for something else —
either the dims/format are stale or the buffer was under-allocated. Trace the
allocator of `dst` via `MclaPhysAllocInfo`'s `allocLr` field (now logged as
`allocLr=` on every `BLIT-CAP` line).

### 4. Continuous presents — mechanically closed (commit `079f94a`), unverified
- Root cause was the swap-table handshake: dev+21624/21628 counters, 2 slots
  reserved per kick (guest writes ZERO, HW fills timestamps LE), completion
  processor `sub_824286A0` advances only when slot `(completed+1&7)+16` is
  non-zero, gated by rlwinm-bit26 of `sub_82458030` (kernel-populated status
  chain our emu never wrote). Both emulation points live in gpu_device.cpp
  (`SWAP-STATUS` / `SWAP-FILL` / `SWAP-COMP` log lines).
- The guard run only reached `NATIVE-PRESENT`=4 before the VMX128 trap, so a
  long present soak is still outstanding. Re-verify after (1).

### 5. Poison family B (lower priority, now understood)
- The 112-byte vtable objects (`vtable 0x820131A4`) get their body from a
  loader that never runs. Use `TSLAB-OWNER`/`PARAM-STORE` in a soak to find
  who allocates them (owner LR) once the inflate path is fixed; the
  initializer is probably upstream of the same data dependency.

---

## How to run

```bat
cd /d "E:\mcla pc"
ninja_build.bat
build\mcla.exe
```

Logs: `boot_stdout_*.log` in repo root. Kill leftover `mcla.exe` before
relink (handoff rule).

**Git Bash on Windows — gotchas that cost real time this session:**
- `cmd.exe /c ninja_build.bat` **silently does nothing** (exit 0, only the cmd
  banner) because Git Bash path-converts `/c`. Always use:
  `MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat`
- The tool rejects any command containing `//F`, `//` or `"// ..."` as a UNC
  path. So `taskkill //F //IM mcla.exe` fails — use
  `cmd.exe /c "taskkill /F /IM mcla.exe"`. Likewise a `grep -o "// pattern"`
  trips it; match without the leading `//`.

**Decoding guest addresses in the image.** `build/cache/mcla_pe.bin` is an
**identity-mapped memory image**: `file offset = VA − 0x82000000`. The PE
*section table* disagrees (it claims `.text` PRD `0x12C800` for VA
`0x82130000`) and following it lands you in zeros — file `0x12C800` is all
zero, while file `0x1B3548` holds `sub_821B3548`'s real first instructions.
Instruction words are **big-endian**.

**IDA MCP:** `powershell -File tools\start_idalib_mcp.ps1` then
`check_connection`. Do not use SSE `idalib_server.py` with the proxy.

**Ghidra:** already connected (`mcla_pe.bin`). Prefer generated TUs as
ground truth; IDA function starts on this raw bin are unreliable.

---

## Do not

- Do not pop stash `session33-audlo-forensics-...` (regresses boot).
- Do not edit `generated/`.
- Do not add a second hook on an address that already has `PPC_FUNC`.
- Do not copy raw non-XCompress bytes into inflate output (causes
  `0x7E780000` AV).
- Do not claim a gate without a soak log line.

---

## Evidence files

| File | What it shows |
|------|----------------|
| `boot_stdout_blit3.log` | pre-guard run: `BLIT-CAP`/`BLIT-SRC`/`BLITWRAP` census, the `nearestAlloc=CAEBB000 size=0xa000 gap=0x4` smoking gun, 64 `PHYS-OVERRUN`, 34 genuine o1heap AVs, exit 139 |
| `boot_stdout_guard.log` | **post-guard run: exit 3, zero PHYS-OVERRUN, zero o1heap AV, zero alloc FAILED**, 2 `BLIT-OOB-GUARD` hits, `REBASE-POISON` ×229, terminal `0x80000003` VMX128 trap |
| `boot_stdout_cdcd74.log` | REBASE-POISON prod=Y prodLr=821853AC/8218542C; CDCD-FILL LR census |
| `boot_stdout_cdcd75.log` | PARAM-STORE probe: A0106xxx written with real param data (lr=821CB1C8) |
| `boot_stdout_cdcd76.log` | POISON-DUMP records (vtable 0x820131A4, body CDCD, 0xDD free fill); INFLATE-EMPTY ×1663; AV rva 0xF3868 |
| `boot_stdout_texsc2.log` | depth fatal 0; AV storm (session 72) |
| `boot_stdout_rootcd.log` | watch armed; INFLATE-EMPTY; no A000 write (session 72) |
| `docs/BOOT_HANDOFF.md` | full session trail |
| `audit-clean/HONEST_ASSESSMENT.md` | why the tree looks messy |

**Session-74 instrumentation left in tree** (all census-only except the guard):
- `BLIT-CAP` / `BLIT-SRC` / `BLIT-OOB-GUARD` — `gpu_device.cpp`,
  `PPC_FUNC(sub_82431A40)`: dst/src/pitch/fmt/rect/wh/srcOrigin/lr plus
  `alloc`/`size`/`allocLr`/`exact`/`need`/`overrunBy`, and an 8-dword dump of
  the source descriptor.
- `BLITWRAP` — `gpu_device.cpp`, `PPC_FUNC(sub_824321E0)`: the copy-rect
  wrapper's dstW/dstH/tileShift/fmtEnum/flag/dstBase/origin/src/lr + alloc.
- `PHYS-OVERRUN` enrichment — `gpu_cp.cpp` `PageWatchOnWrite`: now also
  reports the nearest allocation below the faulting address and the gap.
- `mcla::kernel::MclaPhysAllocInfo(addr,&base,&size,&lr,&exact)` and
  `MclaPhysNearestAllocBelow` — `imports.cpp`, declared in `kernel/memory.h`.
  `MmTrackAllocationSize` now also records the requesting guest LR in
  `s_allocLrMap`. This is what makes an overrun attributable to the site that
  under-allocated the buffer.
- `SehO1Filter` — `heap.cpp`: wrap-safe guest-address test + bounded fragment
  header dump (`[fa-32] … [fa+24]`).

## Task board
Check `task` list: ~~T39 (CDCDCDCD root)~~ root-caused s73; ~~T40 (heap watch
→ AV storm)~~ **CLOSED s74** (blit overrun found, `BLIT-OOB-GUARD` landed);
**NEW: implement `vupkd3d128`/`vpkd3d128` VMX128 modes (s74 #1 blocker)**;
T36 (long soak DRAW_INDEXED), T28 (pool16/UAF — superseded by the
fill-on-alloc finding), T9/T18 (optional IDA dual-source).
