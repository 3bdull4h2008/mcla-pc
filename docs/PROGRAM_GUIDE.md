# MCLA-PC PROGRAM GUIDE

Stable knowledge (build/run, arch, census, cheat sheets, rules). Queue:
`LONG_TODO_MASTER.md`; frontier: `HANDOFF_NEXT_AGENT.md` top. Compressed
2026-09-20; full text `git show 8f07a39:docs/<file>`. `docs/` is gitignored:
**`git add -f` docs**. Old names merged here: `ROOT_CAUSE_*_{PLAN,REPORT,
FINDINGS}.md`, `CHEAP_MODEL_*.md`, `PHASE0/1_*` → `EXECUTION_PHASES.md`. Lost
pre-force-add (facts folded in): `BOOT_HANDOFF.md`, `MCLA_RPF3_*.txt`,
`MCLA_REBUILD_PLAN.md`, `CODEGEN_REPAIR_SUBPLAN.md` (never produced — codegen
cleared). Newer wins on conflict (75u > 75r/s/t; F-023 > "stale lr").

---

## 1. What this program is

Native D3D12 renderer rebuild for Midnight Club: LA (Xbox 360). Recompiled PPC
runs untouched as native C++; intent is captured at the draw boundary and replayed
as D3D12 (no Xenos CP emulation, no rexglue). Zero game code/assets in repo;
toolchain consumes a legally dumped copy (`build/game_data/`, XEX → `build/cache/mcla_pe.bin`).

What exists: boot host linking the full image (44,707 mappings), Xenos decode →
IR → DXIL pipeline, D3D12 backend + PSO cache, device-method capture hooks,
render thread owning all D3D12, offline validators. Frontier moves — handoff
live block is the only current status.

## 2. Repo layout

- `src/` root — boot host (`boot_host.cpp`), device hooks (`gpu_device.cpp`
  monolith; splits in flight → `src/hooks/`), D3D12 backend, render thread/queue.
  One hook owner per guest address.
- `src/hooks/` — PPC_FUNC bodies (`alloc_census.cpp`, `config_dispatch.cpp`)
- `src/cpu/` — `vmx128_pack.cpp`, `guest_thread.h`, `ppc_context.h`
- `src/fs/` — `vfs_rpf.cpp/h` (RPF3 packfile VFS) · `src/rage/` — asset pipeline
- `src/kernel`, `src/apu`, `src/user` — kernel framework + guest runtime
  (`imports.cpp` = Nt*/Ke*/Xam*; `heap.cpp`/`o1heap.c` = physical allocator + SEH)
- `src/renderer` — xenos decode, shader IR→DXIL, texture/vertex decode, caches
- `tools/validators/` — phase-gate exes · `generated/ppc_xenon/` — 176 TUs, input only
- `config/mcla_xenonrecomp.toml` — canonical config (incl. `[[midasm_hook]]`)
- `.research/XenonRecomp` — vendored tool (gitignored; commit patches as `.patch`)
- `build/` — caches, boot logs, `cache/mcla_pe.bin` (guest image)
- `third_party/` — SDL3, fmt, spdlog, toml++, dxc, o1heap, xxhash

## 3. Build / run (Git Bash; MSVC)

```bat
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat
cmd.exe /c "taskkill /F /IM mcla.exe"   :: before link AND after soak
timeout 120 ./build/mcla.exe > build/w37a.log 2> build/w37a_err.log  :: new name every run
```

VS 2022 buildtools, CMake 3.25+, Ninja, clang-cl (`configure.bat`; delete
`build/` on compiler switch). Gotchas: `//F //IM` fails (UNC); ugrep needs
`grep -e "-pat"`; `build/game_data/mcla extracted cache/` must exist (empty
OK) or `app.cpp:90` skips VFS init; verify `mcla.exe` mtime moved; newest
`build/*.log` < ~2 min = another session live, stand down (docs-only safe).

## 4. The guest image

`build/cache/mcla_pe.bin` = shipped XEX as **identity-mapped image**
(`file offset = VA − 0x82000000`; base `0x82000000`, code `0x82130000`,
`src/ppc_config.h`; words **big-endian**). PE section table lies (`.text` PRD
`0x12C800` lands in zeros) — always use identity offset (`0x8226B450` ↔
`0x26B450`). **Raw-byte rule (F-023):** verify every IDA claim (boundary,
branch, xref) vs raw bytes — 75o: IDA claimed 30 callers of `sub_821E5F48`,
raw bl-scan found 4. Generated TUs = other ground truth.

## 5. Recompiler pipeline (XenonRecomp)

- Tool: `.research/XenonRecomp/build-clang/…/XenonRecomp.exe` (has `JTS-TAILCALL`).
  Run from **repo root** with a **bare filename** (`cp
  config/mcla_xenonrecomp.toml .` first); `config/…` fails SILENTLY (exit 127,
  `recompiler_config.cpp:5`). 2nd arg: `src/ppc_context.h` (`tail -n +4
  generated/…/ppc_context.h`, `cmp`-clean). Config emits **176 TUs** — re-check
  vs CMakeLists.
- **Gate:** regen unmodified tool to scratch, `diff -r` vs `generated/`; not
  identical (minus known deltas) = do NOT regen, never into the tree. Then:
  per-function diff, stub census, soak (TSLAB-ALLOC ~2125, PARAM-STORE 401,
  EVENT-CREATE 256).
- Dispatch guard = `src/dispatch_guard.cpp` + `[[midasm_hook]]` @ `0x8218CC94`
  (`sub_8218CC70` ends `bctr` via fn-ptr table; NULL slot = crash).
- Stub census (both forms — old recipe missed 162):
  `grep -hoE 'ERROR:? *0?x?[0-9A-Fa-f]{8}' generated/ppc_xenon/*.cpp` — s78:
  **0 broken** (was 1719); 44,707 mappings link-safe; 33% `.long 0x0` =
  never-executed, not a defect (F-022).
- `.research/` + `generated/` gitignored → tool patches committed as `.patch`.
  Helpers: `tools/fix_stubs_{iter,self}.py` (span fixed-point loops).

## 6. Host runtime architecture

- **Boot:** `src/boot_host.cpp` loads image, installs hooks, starts guests.
- **Hooks:** one owner per address (`PPC_FUNC`/`GUEST_FUNCTION_HOOK`/`SetFunction` —
  grep first); host overrides are strong symbols over weak generated ones.
- **Guest memory:** `GuestMemoryHeap` BE accessors; watches power PHYS-OVERRUN/CDCD-FILL.
- **Host→guest** `GuestToHostFunction` (`function.h:311`) copies ONLY `r1/r13/fpscr` —
  callbacks inherit stale lr/r14–r31.
- **Physical:** one pool → o1heap arena **`0xA0000000`–`0xFFFFFFFF`** (~1.6 GB);
  pool16 inside (`A0014xxx`). `MclaPhysAllocInfo`/`NearestAllocBelow` attribute overruns.
- **Guest alloc:** registry `0x82830B18`, dispatch `sub_821C08F8` →
  **sysMemDualBuddyAllocator** (`B7xxxxxx`); simple pool `A0001010..A2E81000`
  for direct callers. General `sub_821C1BB0` (16 buckets, 16 B headers, 0xCD fill);
  free `sub_821C2AB8` (**drops i==1/3**); tiny-slab `sub_821DE9D8` (4/8/16/32/64,
  **memsets 0xCD** — §9). CS guard `sub_821C8FE0` skips `[cs+0]==0`; ours writes
  `Lock=0xFFFFFFFF` (`0x82855A0C` locked).
- **VFS (RPF3:** hdr `0x800`, TOC `0x1000`, 16 B BE; LZX, not zlib;
  `xarchive_cache.rpf` TOC-encrypt `0xB116A6AB` @0x800, guest decrypts):
  positional `ReadFileAt` (shared-handle race fixed), async events; inflate
  `sub_821D5E10` (`0x0FF512EF`; unknown → skip-fatal).
- **IO contract:** Xbox submit → PENDING(259) → completion; ours completes
  sync — `SLOT-READY` (`sub_821CBE18`: `[slot+12] 1→2`) is the honest
  equivalent; `DISCCHK` (`sub_821CC1E0`) sets bit31 ack BEFORE `__imp__` when
  bit30 set.
- **GPU:** `gpu_device/gpu_cp` own the boundary (submit/streams/blits, swap-table
  handshake dev+21624/21628, completion `sub_824286A0`); renderer =
  `src/renderer/*`; `FRAME-END`/`NATIVE-PRESENT`;
  `SignalSchedulerTick` → VSYNC semaphore.
- **Fatal dispatcher** `sub_821BD618` → `[0x8285FEA0]`, loops; host override
  (`patches.cpp:441`, `imports.cpp:2818-2873`): dump + `ExitProcess(0x80000003)`;
  slot `0x82130678` is real (F-007). **Task-join table:** cnt `0x8283D1A8`,
  entries `0x8283D1C4`, stride 28, wait = `entry+12`.

## 7. Short-circuits in tree (life-support — do not stack more without root cause)

KDELAY-SC (force `pub0`) · FENCE-SC + ClearTaskJoinBusy · TASKJOIN-SC
(`sub_821BD220` main-thread busy=0) · REBASE-POISON (`sub_821B5A60` zero `*param`
on `0xCD`) · P10-PRE (poison-id skip) · INFLATE-SKIP/EMPTY/PENDING (no XCompress
→ 0/bail/retry) · TEXCREATE-SC (`sub_82177EB0` r3<0→0) · SEH o1heap (AV→null) ·
pow2 align · NtReleaseSemaphore (Wait-like resolve) · BLIT-OOB-GUARD (skip
overrun blit — closed s74 AV storm) · SLOT-READY (`sub_821CBE18` 1→2) ·
DISCCHK bit31 pre-ack · DICT-HYDRATE (hash `0x82839F70` after 10 factory hits,
`3c8744e` — stays till INSERT clean). Wake-loss identity fix = real bugfix.
Poison values: `0xCDCDCDCD` = guest fill-on-alloc (uninitialized, NOT
corruption) · `0xDD` = free-fill · `0xFF00FF00`/`0xFFFF00FF` = missing-texture
texels, NOT poison.

## 8. Cheat-sheet (verified; `0xCDCDCDCD` = uninitialized, not corruption)

Shader: lookup `sub_82189138` (r3=name, −1 miss; recomp.9) · hash helpers
`sub_821C9AB0/9790` · dict table **`0x82839F70`** (256×4B; `0x827C9F70` was wrong)
· list `0x82839ED0` · register path `82189438/88E50 → 8218C760 → resolver
821BDF20 → 821CB488` (NULL on PC → INSERT fails) · factory `8218BF20` via
`8218B000` (10 entries) · fatal switch `byte_827D5C70` = 0x01, 0 runtime
writers, never patch · fatal `821BD618 → [0x8285FEA0]=0x82130678` (host
`patches.cpp:441`) · preload `a:/archive/shaders/{ui,city,cars,characters,
effects}/preload.list` · star_glow cascade `embedded:/dcl → embedded:/ →
embedded:/fxl_final → mangled archive → fatal` · fmt `0x8200B358`.
Device/fs: registry `0x82860844` (`Device**@+0, u16 cnt@+4, cap@+6`; cap 16;
entry 276 B: name[262], flag@262, len@264, vector@268) · GetDevice
`sub_821CB488` (prefix checks then 276-walk, best-prefix `821CAA28`) · Mount
`821CB9D8` (3 sites; non-archive chain never runs, F-034; MOUNT76=2) · mem
vtable `0x82012918` (+0 AE50 exists/size, +4 AFB8 open `memory:`-only, +16
CB070 insert=EMB76, +80 CB400; base `0x8201206C` open=stub) · static
Device*/dead-ptr `0x827D838C`; **`0x827D8380` = fiDeviceMemory type_info/VFT,
NOT a holder** · name list head `0x82860AF8` (`{name,buf,size,next}`;
ins `821D22E8`, lookup `821D2308`) · packfile `0x82012BDC`/embedded
`0x82012B44`; TOC=vtable+144 `821CBFC0` (0 if `[obj+8]==0`); Open `821CDB88` ·
`memory:` strings `0x82012A28/0x820127D8` · RPF3 hdr `0x800` TOC `0x1000` 16 B
BE · stream fetch `8244F4C0` (RD-SUBMIT), wrapper `821C4F98`.
Streaming/tasks: queue `0x82849518` (+idx*0x6174); prod `821BC868`, worker
`821BC910` (infinite), exec `821BC140` (inflate lr `821BC380`) · credit gate
`0x827D74E0` · GPU poller `8242FB88` (30 ms tick `0x40004D7C`, NOT IO stall) ·
post-inflate `[r26+1548]=821BC548 → 821C9108 → 8244ED10` = sema release, NOT
mount (F-032) · dict slots `0x82860C18` (40 B) + 4 KB buf `0x82860DF8+i*0x1000`,
free `0x827C8874`.
Texture: lookup `821849C0` (miss → fatal), table `0x82839E2C`, specials
`0x82839CF0/CF4` · register `82197598` (no PPC_FUNC — census caller `8218B000`)
· init `82180A30` · find/create `82185368+82185410`, ctor `82185648 → 821854C8`
· pitch `8218DCE8` (host override, fmt1→w*4) · checkerboard `8218ECF8` (32×32),
DDS `8218EDA8 ← 8218E090`.
Vertex/VMX128 (§5): emulator `821B3548` (`…3548–3CB8`), loop `821A0800` ·
type-2 pack hooked @`821B3814/3C2C/3E90/4788` → `mcla_Vpkd3d128_type2` ·
open: type-5 unpack ×94 (`822Fxxxx`), type-2 ×1 (`821B43D8`), `vcmpbfp128` ×1
(`825CEA2C`) — `PLAN_VMX128.md`.
Draw: dispatcher `82227428` (needs type `0x20000000`; never on loading path) ·
SetStreams `8241BE78` (cnt `dev+12748`, VB `dev+12756`) / wrap `8241C308`
(needs r6=IB) / submit `82420BA8`; geometry `8217A470 → …` (0 hits on loading);
only live submit = dummy/HUD `8217B7B0` (r5=0). Swap handshake `dev+21624/21628`
(guest writes ZERO, HW fills LE timestamps; completion `824286A0` needs slot
`(completed+1&7)+16`). Task-join: cnt `0x8283D1A8`, entries `0x8283D1C4`,
stride 28, wait `entry+12`.
Misc: memset `8244D150` — **lr `0x8244D158` after it (and `0x821C2AAC` after
slab unlock) is a sticky-LR artifact; LR attribution VOID there, use FFBT** ·
`sub_82130000` = real `blr`, not a gap · dispatch guard `8218CC70` (hook
`0x8218CC94`, `dispatch_guard.cpp`) · gap stub `8221D9D0` (MISSING-BODY, never
hit) · XCompress `0x0FF512EF`; RSC5 `05'CSR'+0`, payload +0xC (`inLeft=read−12`)
· vfmt sizes `0x8200C0A0/0x8200C0E0` · vpkd bias `{3,3,3,3}`@`0x820100F0`,
`{−2^−13,…}`@`0x82010100`. sprintf `821CB760/821CB740`; inner-stream read `821CCD58` via `821CC6F0` ([obj+32]→inner+28; 3×32KB @+296/336/356).

## 9. Census / marker inventory (log-line vocabulary)

All census hooks are log-only unless noted. Files: `gpu_device.cpp` (device
boundary + inflation + blits + dict), `patches.cpp` (allocation + misc),
`task_dispatch_trace.cpp` (poison), `gpu_cp.cpp` (page watches), `boot_host.cpp`
(watches/crash filter), `imports.cpp` (kernel calls), `heap.cpp` (physical
allocs). The log line `mcla_patch_groups = 'all'` confirms censuses armed.

| Marker | Hook / meaning |
|---|---|
| `GETDEV` (+`-E0`/`-E1`) | fiDevice::GetDevice (`sub_821CB488`); dumps handler table `0x82860844`, entries, devices, lockFlag |
| `MOUNT76` | fiDevice::Mount (`sub_821CB9D8`): path, dev, vtable, lr |
| `EMB76` | embedded-device vtable method (`sub_821CB070`, capped 12) |
| `TOC76` / `TOC76-RET` | packfile TOC lookup (`sub_821CBFC0`) entry + return with elapsed time |
| `BOOTPATH` | boot-init package processing (`sub_82187820`) with descriptor dump |
| `INFLATE` / `-SKIP` / `-EMPTY` / `-PENDING` | inflate hook (`sub_821D5E10`): magic, sizes, retries |
| `SLOT-READY` | page-cache slot wait (`sub_821CBE18`) state flip |
| `DISCCHK` | disc-error polarity check (`sub_821CC1E0`) |
| `BLIT-CAP` / `BLIT-SRC` / `BLITWRAP` / `BLIT-OOB-GUARD` | tiled surface blits (`sub_82431A40`/`sub_824321E0`) + overrun guard (guard changes behavior) |
| `DICTFACT` | shader-dict factory (`sub_8218BF20`) with stream-slot name dump |
| `TEXDICT-CALLER` / `DICT-HYDRATE` / `DICTLOOKUP` | dict registration (`sub_8218B000`), hash-table hydration, lookup census (`sub_82189138`) |
| `PRELOAD-CTX` / `POST-EXEC` | post-inflate callback context (streamCnt, cbPtr, arcDev, bufPtr) |
| `REQ` / `REQDUMP` / `COMPLETE` / `RELSEMA` | streaming queue requests, executor completions, semaphore releases |
| `JOIN` / `PAGESLOT` / `RD-SUBMIT` / `READWRAP` | join-table dump, page-cache slot states, kernel read submits, stream reads |
| `WAIT` / `WAKE` | KeWaitForSingleObject/KeResetEvent (KWFSO) with object, status, lr |
| `TICK-PROBE` | VSYNC semaphore release into the tick object |
| `NFS-CENSUS` | file reads served by VFS |
| `REBASE-POISON` / `P10-PRE` | poison param zeroing / poison-id skip (`task_dispatch_trace.cpp`) |
| `TSLAB-ALLOC` / `TSLAB-OWNER` / `CDCD-FILL` | tiny-slab producer attribution + 0xCD-fill watch |
| `PARAM-STORE` / `POISON-DUMP` | watch probes on param ranges (`A0106xxx`) |
| `PHYS-OVERRUN` / `FFBT` | physical overrun (with nearest-alloc + gap) / one-shot host callstack on poison stores (`gpu_cp.cpp`) |
| `GEN76-ALLOC/FREE` / `BUDDY76-*` / `HEAP76` / `WIN76-*` | allocator censuses (general/buddy/arena/ownership) |
| `TEXCREATE-SC` / `MISSING-BODY` | legacy-RT short-circuit / recompiler-gap stub census |
| `GLOBTEX-BOOT` / `TEXINIT` / `GFXINIT` / `TEXINSERT(2)` / `DICTREQ` / `STREAMTEX` / `UILOAD` | texture-path censuses |
| `DRAWDISP` / `SETSTREAMS` / `DRAWWRAP` / `SUBMIT` / `LOADGATE` / `DRAW-SEAM` | draw-path censuses |
| `FRAME-END` / `NATIVE-PRESENT` / `VSYNC-ISR` / `SWAP-COMP` / `SWAP-STATUS` / `SWAP-FILL` | present-path counters + swap-table handshake |
| `GATE-PROBE` / `DICTSLOT-ALLOC` | IO-credit gate probe (`0x827D74E0`) / slot allocator |
| `VECTORED exception code=0x406D1388` | benign Windows SetThreadName exception from host code — not guest |

## 10. RE tooling

- **IDA MCP** on `127.0.0.1:8745` (program `mcla_pe.bin`, base `0x82000000`).
  Start: `powershell -File tools\start_idalib_mcp.ps1` then `check_connection`;
  or run the venv python (path in `tools\start_idalib_mcp.ps1`)
  with arg `-v "E:/mcla pc/build/cache/mcla_pe.bin"`. Do NOT use the SSE
  `idalib_server.py` with the proxy. Useful tools: `get_function_by_address`,
  `decompile_function`, `disassemble_function`, `get_xrefs_to`,
  `list_strings_filter`, `read_memory_bytes`, `data_read_string`.
- Ghidra RETIRED.
- Generated TUs are ground truth for bodies; IDA function starts are
  unreliable on this raw bin; IDA xrefs must be bl-scan-verified (§4).
- Host crash attribution: llvm-symbolizer + PDB for host RVAs; `FFBT` census
  for guest-side stores; the emu's crash filter (`boot_host.cpp`) can scan
  guest memory for a needle value.
- Find subagent useful for caller mapping; keep the main window for decisions.

## 11. Rules that govern all work

1. **One hook owner per guest address.** Check `PPC_FUNC` /
   `GUEST_FUNCTION_HOOK` / `SetFunction` before adding anything.
2. **Never edit `generated/`.** Never run the recompiler into the project
   tree; regen only after the reproducibility gate (§5).
3. **No gate claim without a soak log line.** Evidence = log line +
   timestamp, raw file words (offset = VA − 0x82000000), or file:line.
4. **Root cause over symptom.** `CDCDCDCD` at a use-site = an initializer
   that never ran — make the loader run; do NOT zero at use-sites, do NOT
   patch `byte_827D5C70`, do NOT poke the shader dictionary from host code,
   do NOT stub the fatal.
5. **Do not stack short-circuits** (§7) without proving the root cause first.
6. **"Field never written / value garbage" bug → grep ERROR stubs first**
   (`grep -n "ERROR: 0x" generated/ppc_xenon/ppc_recomp.N.cpp` on the involved
   functions) and check the executed-path stub census — silent stub returns
   have caused weeks of misdiagnosis (texture pitch → heap overwrite).
7. **Default modifiable files** for executor phases: `src/patches.cpp`,
   `src/gpu_device.cpp`, `src/kernel/*.cpp|h`, `CMakeLists.txt` (only for a
   new source file), plus docs. **Forbidden:** `generated/**`,
   `config/mcla_xenonrecomp.toml`, `src/ppc_context.h`, `src/ppc_config.h`,
   `.research/**`, `src/dispatch_guard.cpp`.
8. **Boot logs:** one per experiment, new name every time
   (`build/boot_stdout_pXX.log`), never overwrite 78/76y; note exit codes;
   preserve existing logs.
9. **Do not** pop stash `session33-audlo-forensics-…` (regresses boot); do not
   copy raw non-XCompress bytes into inflate output (causes the `0x7E780000`
   AV signature); do not add a second hook on a `PPC_FUNC`-owned address.
10. **Every claim classified A–I / P0–P4** in the findings ledger
    (`ROOT_CAUSE_VALIDATION.md` Part 3 for classes and format; append
    findings there, continuing F-###).
11. **Commit hygiene seen so far:** docs are gitignored — force-add; tool
    patches must be committed as `.patch` files; one commit per landed fix
    with the fix named in the message.

## 12. Verification battery (per landed fix)

- Boot ×2 into fresh logs; both must survive ≥ the old failure point.
- Fatal gone or moved to a NEW, documented frontier (guest address, message,
  timestamp).
- Steady-state counters within sane range of baseline (TSLAB-ALLOC ~2125,
  EVENT-CREATE ~256; they may legitimately grow if boot advanced further).
- No new `[error]` classes; no PHYS-OVERRUN; REBASE-POISON not exploding.
- `git diff` reviewed hunk-by-hunk; every hunk traces to a written design.
- Anti-cheat self-check (from Phase 0): did any change make the guest do
  something the PPC binary doesn't say? Is every raw-word citation from the
  file? If you deleted your fix, would the bug still reproduce? Could the fix
  mask a different divergence?
