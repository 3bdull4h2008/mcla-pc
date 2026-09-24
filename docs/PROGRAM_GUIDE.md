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
  Helpers: `fix_stubs_{iter,self}.py` **at the repo root** (verified 19:25 — not `tools/`; they are
  untracked junk per `LONG_TODO_MASTER` T37.1, so re-check before relying on them),
  span fixed-point loops.

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
  equivalent; `DISCCHK` (`sub_821CC1E0`) sets bit31 BEFORE `__imp__` when bit30
  set — **F-112 says what those bits are**: the word is the RPF3 TOC record's
  4th dword (every cache-packfile record has bit30), bit30 = "bytes not resident,
  do the disc read", bit31 = "the read completed". Forcing it skips the guest's
  own read submission (`sub_821DEE40(io,2)` returns -3 on ours; r3<0 is exactly
  its `Fatal disc error` condition), so it is a mitigation, not the mechanism.
- **GPU:** `gpu_device/gpu_cp` own the boundary (submit/streams/blits, swap-table
  handshake dev+21624/21628, completion `sub_824286A0`); renderer =
  `src/renderer/*`; `FRAME-END`/`NATIVE-PRESENT`;
  `SignalSchedulerTick` → VSYNC semaphore.
- **Fatal dispatcher** `sub_821BD618` → `[0x8285FEA0]`, loops; host override
  (`patches.cpp:441`, `imports.cpp:2818-2873`): dump + `ExitProcess(0x80000003)`;
  slot `0x82130678` is real (F-007). **Task-join table:** cnt `0x8283D1A8`,
  entries `0x8283D1C4`, stride 28, wait = `entry+12`.

## §7-ADDENDUM (2026-09-23, F-091 §7) — guest-affecting mitigations registered NOWHERE (read first)

The table below still lists 13 entries; `src/` currently carries **80** mitigation-shaped labels, and
**135 guest-affecting lines per 120 s soak** belong to mitigations that are in neither this section nor
`tools/soak_census.py`'s tracked list. Fire counts are from `build/w43a.log`.

| label | site | effect on the guest | fires |
|---|---|---|---|
| `BE710-SLOT` | `src/gpu_device.cpp:11484` | answers a device Read from the host slot table, `ctx.r3=served/4; return` — `__imp__sub_821BE710` never runs | 49 |
| `BE710-DEAD` / `BE710-MAGIC` | `src/gpu_device.cpp:12326` / `:12336` | **MITIGATION, load-bearing (F-127).** For a stream whose `[+0]` device is dead, the host writes `0x61786772` (`'axgr'` = the `rgxa` effect magic) straight into the caller's destination word and returns 1. That word is exactly what `sub_8218C760`'s rage-effect gate compares (`lwz r7,80(r1)` / `r8 = 0x61786772`; mismatch ⇒ `'Old version of rage effect found. You need to recompile your shaders!'`, `lr=8218C864`) — so **the frontier passes that gate only because of this write.** Conversion target (F-127 §5): have the `fxl_final/rage_im.fxc` stream deliver the magic at the read position. The gate is reached for the first time with real archive bodies (`w117`/`w124`/`w125`: `lr=8218C864` 0 → 31-33). **F-128 corrections/control:** it fires **166 times per boot, not 2** — every served effect body, all through the one reused wrapper slot (`obj=82860C68`, `stream=82905500` constant, `sbuf` changing); and withholding it (`kBe710MagicWrite = false`, one build flag) produces `BE710-MAGIC-OFF` 1 line then `Old version of rage effect found` with `LISTLINE 167→1`, `GETDEV 694→196` — so the mitigation is proved load-bearing by removal (`w128` ON vs `w130` OFF). No delivered body carries the magic (measured heads `696D6541`, `ED5B0F70`, `95564D6C`, `ED5C0D70`×2, `ED5B0D8C`), so the real gap is the `.fxc` transform, not the read position | **166** |
| `XSF-POSTOPEN-SERVE` | `:10450` | registers a host-served body and publishes its size into guest memory (`:10470` writes `[tocEntry+4]`) | 31 |
| `P5-PHYS` | `src/task_dispatch_trace.cpp:606` | "already physical, skip fatal": `ctx.r3=0; return` | 24 |
| `JOB2-PKG-SERVE` | `src/gpu_device.cpp:6765` | host inflates the job-2 package and returns without running `sub_821D5E10` | 22 |
| `PKG-SUBST` | `:562` | substitutes a host package body for the TOC offset (`Alloc` + `WriteBytes` into guest) | 19 |
| `P10-GATE` | `src/task_dispatch_trace.cpp:855` | rebase-map miss → `ctx.r3=0; return` (delta 0) | 17 |
| `BE250-SLOT` | `src/gpu_device.cpp:11720` | slot-table read serve (same shape as `BE710-SLOT`) | 25 |
| `BE250-MEM` / `BE250-MEM-BADPTR` | `src/gpu_device.cpp:11677` / `:11700` | `MemoryStreamServeRead` serves a read for a wrapper whose `[+0]` device is dead, assuming the `MakeMemoryStream` shape (`+4`=buf, `+8`=size, `+24`=cursor). On a **guest-native** buffered wrapper that shape is wrong (`+4` is a handle, `+8` is the buffer) and `buf+pos` wraps into the null guard page — that is F-122's 50 AVs. The refusal (`BADPTR`) names the object and returns -1, exactly what the AV used to collapse to | 1 / 55 in `w115` |
| `SLOT-RECYCLE` | `src/gpu_device.cpp:11652` (`GuestSlotTableInsert`) | first recycle branch: reuse a device slot whose body the guest has read to its last byte (`[slot+8] pos >= [slot+4] size`). Fires about once per boot because the served-registry path never advances `pos` — which is why `SLOT-RECYCLE-SHARED` below exists | 1 in `w146`/`w147` |
| `SLOT-RECYCLE-SHARED` | `src/gpu_device.cpp:11652` | MITIGATION, load-bearing since F-135. The host registers its served bodies in the guest's 15-entry device slot table at `0x82860740` and had no release path, so from the 16th body on `MakeMemoryStream` fell back to handing the guest a **pointer** as its handle — which the guest's own `GetSize`/`Seek` contract rejects with -1, and `sub_821BE8D8` then allocates and reads that -1 (F-134's 4 GB storm). Reuses the index this same host path last handed out; sound only because every `MakeMemoryStream` stream already shares the one static object `kMemStreamSlot` | 24 in `w147` |
| `GuestMemoryHeap::IsValid` guard-page clause | `src/kernel/memory.cpp:321` | rejects `guestAddr < 4096` — the first page is `PAGE_NOACCESS` by design (`:218`), and without this the "checked" helpers passed a near-null pointer straight into `memcpy` and relied on SEH to survive it (F-122) | — |
| `FDA90-GATE` | `src/task_dispatch_trace.cpp:380` | skips a fixup dispatch (`return`) | 12 |
| `(dev,handle)` served-body fallback | `src/gpu_device.cpp:668-690` | **loose match returns one file's body for another** — offers `legals.xsf` as the body of all five `shaders/*/preload.list` (`BE8D8-PACK #2-#6`). Its sibling, the **`w3` index, is DELETED (F-126)**: the TOC record's 4th dword is a flags word shared by 52 distinct records (`40000061`), so it can never be a file identity. Lookups are exact-by-`tocEntry` plus log-only loose keys now, measured frontier-neutral (`w127` vs `w115`) | 5 |
| `W30-ARR-FIX` / `W31-ARR-FIX` / `PLACE-ARR-PRE` / `PLACE-ARR-FIX` | `:4465` / `:4720` / `:8971` / `:8981` | rewrite guest child arrays (incl. a synthesised array at hard-coded `0xB7B41000`) then call the guest place | 2/1/1/1 |
| `D2308-INS-SKIP` | `:8348` | skips the guest's `EmbeddedListInsert` name registration | 2 |
| `AFB76-HIT` | `:11039` | serves a body straight out of guest `.data` (legitimate for `rage_im`; sets `ctx.r3`, guest open not run) | 1 |
| `FATAL-SOFT` / `FATAL-SOFT-RESOURCE-PARK` | `src/kernel/imports.cpp:2990` / `:3010` | a guest `Fatal` is soft-parked (`return`), so the window survives and the boot "continues" | 2 / 1 |
| `READWRAP-SERVE` | `src/gpu_device.cpp:9818` | credits a refill + `ctx.r3=…; return` (no `__imp__sub_821CC6F0`) | 1 (`w42a` 0) |
| `INFLATE-J2-WIN-CONT-SKIP` | `:7354` | abandons the guest's continuation walk | 1 |

Registered-but-dead (§7 names them, they fire 0×): `INFLATE-SKIP`, `INFLATE-EMPTY`, `TEXCREATE-SC`,
`SLOT-READY`, `BLIT-OOB-GUARD`. §7 entries that are prose rather than labels (so no tool can verify them):
`SEH o1heap`, `pow2 align`, `NtReleaseSemaphore` "Wait-like resolve". `DICT-HYDRATE` is registered without
its second printer at `:2087`. Full measurement: ledger **F-091 §7**.

## 7. Short-circuits in tree (life-support — do not stack more without root cause)

KDELAY-SC (force `pub0`) · FENCE-SC + ClearTaskJoinBusy · TASKJOIN-SC
(`sub_821BD220` main-thread busy=0) · REBASE-POISON (`sub_821B5A60` zero `*param`
on `0xCD`) · P10-PRE (poison-id skip) · INFLATE-SKIP/EMPTY/PENDING (no XCompress
→ 0/bail/retry) · TEXCREATE-SC (`sub_82177EB0` r3<0→0) · SEH o1heap (AV→null) ·
pow2 align · NtReleaseSemaphore (Wait-like resolve) · BLIT-OOB-GUARD (skip
overrun blit — closed s74 AV storm) · SLOT-READY (`sub_821CBE18` 1→2) ·
DISCCHK bit31 pre-ack (F-112: = "pretend the record's bytes are already
resident", skipping the guest's own disc read for every cache-packfile record; load-
bearing — w100/w101 without it die at 4,528 lines vs 17,868) · DICT-HYDRATE (hash `0x82839F70` after 10 factory hits,
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
| `DISCCHK` / `DISCCHK2` | disc-error check (`sub_821CC1E0`): `DISCCHK2` dumps `strm/fobj/len/rec/size/offs/flags/route=` (route = the executed bit30×bit31 decision, F-112) — `n <= 40 \|\| (n % 200) == 0` |
| `DISCCHK2-WAIT` / `-RES` | the guest's own completion call inside the disc-read block (`sub_821DEE40(io, 2)`) and its return value; **only observable with `kDiscChkForcedAck = false`**, so their zero in a normal soak means the mitigation is firing, not that the path is dead |
| `PARK-STACK` | the boot worker's guest frame chain at each `PARK-SAMPLE` heartbeat (`f0..f7` = return addresses, resolved offline against `ppc_func_mapping.cpp`). Reads `g_bootWorkerCtx`, NOT `g_faultCtx` — that one is `thread_local` and null on the sampler thread (F-119) |
| `HB-FLICKER` | the 33 ms heartbeat present (`render_thread.cpp` PRESENT case, `swapInfo=0`). Split out of `RenderThread: PRESENT` in T41.4b because soak_census counts lines: `w103` had 2,880+ heartbeats and **0** guest presents on that counter — the guest's real swaps show as `NATIVE-PRESENT` (4 per soak) |
| `BLIT-CAP` / `BLIT-SRC` / `BLITWRAP` / `BLIT-OOB-GUARD` | tiled surface blits (`sub_82431A40`/`sub_824321E0`) + overrun guard (guard changes behavior) |
| `DICTFACT` | shader-dict factory (`sub_8218BF20`) with stream-slot name dump |
| `TEXDICT-CALLER` / `DICT-HYDRATE` / `DICTLOOKUP` | dict registration (`sub_8218B000`), hash-table hydration, lookup census (`sub_82189138`) |
| `PRELOAD-CTX` / `POST-EXEC` | post-inflate callback context (streamCnt, cbPtr, arcDev, bufPtr) |
| `REQ` / `REQDUMP` / `COMPLETE` / `RELSEMA` | streaming queue requests, executor completions, semaphore releases. **Read `REQDUMP`'s dwords as records, not scalars**: `d[0]` is the request-slot index that `sub_821BC140` multiplies by 28, and `d[1..]` are 3-dword `{virtual src, dst, size}` records (F-173). `PRELOAD-CTX`'s `arcDev=CA327100` is a **semaphore handle**, not a device (F-172) |
| `JOIN` / `PAGESLOT` / `RD-SUBMIT` / `READWRAP` | join-table dump, page-cache slot states, kernel read submits, stream reads. **`RD-SUBMIT` is the soak-mode check (F-123): `== 4` means the run stalled at the 382,976-byte archive TOC read (`NFS-CENSUS[Read] … evt=00000000`) and is VOID for every purpose; `>= 24` means the guest got past it** — half the runs of the same exe stall, so never conclude from a single soak |
| `WAIT` / `WAKE` | KeWaitForSingleObject/KeResetEvent (KWFSO) with object, status, lr. The `WAIT` line's `put=`/`rptrWB=`/`wb@XXXXXXXX=` fields are a **census of the waiter's view**: since T40.4 the write-back word is read through `CpPrimaryWritebackVA()` (the CP's own publish target) instead of a hard-coded address that was 4 bytes wrong for soaks (F-057(1)). `wb@00000000=` means no write-back is enabled, not a stalled ring. |
| `CP-T3-CENSUS` | unhandled PM4 Type-3 opcode, first 3 per opcode with argument dwords, then a running total (`src/gpu_cp.cpp:351-367`). Replaced a logger that collapsed every opcode `>= 0x20` — the whole draw range — into one line (F-059). Names: `xenos.h` PM4 enum. |
| `CP-DRAW` | decoded `PM4_DRAW_INDX` (0x22) / `PM4_DRAW_INDX_2` (0x36): `VGT_DRAW_INITIATOR` split into `src`/`prim`/`numIdx`/`idxSize` plus `dmaBase`/`dmaSize` for kDMA (`src/gpu_cp.cpp:496-531`, fields per `registers.h:311-326`). **Census only — it does not render**; `DRAW_INDEXED` is a different, still-starved path. |
| `MSGCHAIN` / `MSGBISECT` | The F-060/F-061/F-063 boot-init chain census (`src/gpu_device.cpp:9450-9560`): every hook **chains** to `__imp__` (log-only), prints its `r3`, `lr`, a guest stack back-chain and `[0x8287E26C]`/`[0x82839F68]`/`[0x8287E064]`. `MSGBISECT 5-822FBAF8 RETURN` is the line that says the `star_glow` effect init completed. Numbers are matched-LINE counts like everything here — one `RETURN` missing is the whole finding. |
| `GATE-STACK` / `GATE-WAIT` | The forced boot gate's own host thread (`src/gpu_device.cpp:1097+`): the guest stack it runs on (from `g_userHeap`, never the phys o1heap — that caused 3 bogus `AllocPhysical` nulls) and the value of `[0x8287E26C]` after it waited up to 500 ms for the guest to publish its singleton. |
| `D3070-SKIP` / `D3070-RUN` | `sub_821D3070` buffer guard (`src/gpu_device.cpp:11516+`). SKIP = object/block unusable; RUN = the call was passed to the guest. Since F-063 the `r4 & 0x8000` flag test no longer forces a SKIP, so a SKIP now genuinely means a dead object. |
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
| `SHGRP-VARS` | the shader-group variable binder `sub_82193AF8(group,name,required)` (`src/gpu_device.cpp:12395`-ff): group, its vtable/array/`lhz [group+12]` count, the wanted name as ASCII and the first two entries' names. Raised the `Required grmShaderGroupVar 'skinningData' not found.` fatal that is the frontier in w147-w154 (F-142…F-144). Read-only, cap 80 |
| `TYPINIT` / `TYPINIT-RET` | `sub_826113A8` entry+return (`src/gpu_device.cpp:12476`-ff) — the only writer of the `[object+8]` group. Prints the object, its vtable, `+8`/`+12`, the requested parent name, `[0x827D7770+3072]`/`[+3076]` and `[0x8288E054]`. w152: 4 calls ('entity' x3, 'entity.type' x1), every one returning 0 with `+8` left at the ctor's zero and the scan bound at 1 (F-144) |
| `PATHMGR-OPEN` | the resource **path** manager's own open attempts: `sub_821BDF20` calls whose return address is `0x821CA708`, i.e. inside `sub_821CA6A8`'s per-mount candidate loop (`src/gpu_device.cpp:12040`-ff, inside the existing BDF20 census). Prints the composed `a:/archive/...` path, flags, the guest's return and `lr`. First 60 plus any path containing `entity` or `.type`. **`ret` is a pointer-or-null, not an errno**: `0` and `0x82864048`/`0x82864068` (static wrappers) both occur, so read a `.dcl` pair (long form fails, short form succeeds) before calling one of them "the failure" |
| `LISTLINE` | **the frontier counter** - `sub_82188E50` prints one line per token the `.list` text reader gets (`src/gpu_device.cpp:10754`-ff): `#n`, `r3` (reader), `lr`, `read=` (bytes the reader took) and `text=`. Uncapped, so its total is a real progress measure: 167 was the pre-F-135 wall, **171 is the current frontier** (w160/w161). When it drops, diff WHICH tokens are missing before concluding anything - w164-w166 all lost the same last four (`embedded:/rage_shadowdepth`, `rage_blendshadows`, `rage_shadowcollector`, `rmptfx_collision`), which is what identified F-135's recycle as the regressed stage (F-157) |
| `SLOT-REG` | `MakeMemoryStream` publishing `{buf,size,pos=0,flag=0}` into the guest's own device handle table at `0x82860740 + idx*16` and returning the **index** (`src/gpu_device.cpp:11808`-ff). Cap `n <= 24 || n % 200 == 0`, so a small count is not a small number of serves |
| `SLOT-RECYCLE` / `SLOT-RECYCLE-SHARED` / `SLOT-TABLE-FULL` | the three tiers of F-135's MITIGATION for that 15-entry table never releasing an entry (recycle a slot the guest read to its end; else reuse the index this host path last handed out; else report the table full and let the pointer fallback happen). Same `n <= 24 || %200` cap. `SLOT-TABLE-FULL > 0` is the pre-F-135 `size=0xffffffff` precondition - `src/gpu_device.cpp:11741`/`:11768`/`:11777` |
| `DEVCLAIM` | `sub_821CDB88` claiming a path for a device (`src/gpu_device.cpp:10470`); the print predicate is widened to `n <= 96 || path contains 'entity' || '.type'` so the entity.type chain is visible without a rebuild. **`r3=0` is not a decline** - the caller loop stops on `r4 != -1` |
| `BE0C8` / `-FIX` / `-SKIP` / `-RET` | the guest's `sub_821BE0C8` stream re-open, host-completed for `memory:$<buf>,<size>,0:<path>` strings (`src/gpu_device.cpp:12326`-ff). `-RET stream=` prints the **slot index** returned, not an object pointer - F-157 measured that returning an object here loses `LISTLINE`/`TYPINIT`/`FACTORY`/`DICTLOOKUP` in three independent builds, so the index is correct for this branch's consumers. `-FIX` invents the re-open string when the path is empty |
| `REALIZE-CAST` / `REALIZE-WRAP` | `sub_821CFE80(reader, key, 0)` census, gated on `lr == 0x82611048` (`src/gpu_device.cpp:12636`/`:12661`): the reader object, vtable, name pointer, stream, `+8`/`+20`, cursor, token count, the key compared, the return, then the reader's 32-byte buffer as ASCII + hex, the token, and the wrapper's `dev/h/buf/cur/end/cap/avail`. This is how F-149 proved the `Version:` test was failing on raw-DEFLATE bytes (`buf='isreV'`) - and `end=0x1E5` on the wrap line is the signature that the F-149 span expansion reached the guest |
| `SEEK-DEAD` | `sub_821BE568` entered with a stream that is not a live object (`src/gpu_device.cpp:12709`-ff): `obj/dev/h/cur/end/cap/seekto/lr`, one checked read per call (F-125). `obj=00000001 lr=82191100` is the F-157 fingerprint of our own index return reaching the guest's device Seek; it precedes the single frontier `C0000005` |
| `SLOT-CLOSE` | the guest's OWN handle-release routine `sub_821CB2A0` (installed by us at memory-device vtable+44) - `src/gpu_device.cpp:12729`-ff prints `r3`(wrapper), `r4`(handle) and the slot's `[buf,size,pos,flag]` *before* running the original. Cap `n <= 40 || n % 500`. It decoded 0 in `w167` (nothing called it) and 6 in `w168` (F-160). **`flag=00` is deliberate**: the routine frees `[entry+0]` only when that byte is non-zero |
| `BE8D8-CLOSE` | proof that F-160's release went through guest code rather than our old hand-written clear: prints `h`, the slot address and `entry0_after` (must be `00000000`) from `src/gpu_device.cpp:12153`-ff. Cap `n <= 24 || n % 200` |
| `BE8D8-CALLER` / `BE8D8-CALLERS` | caller tally on `sub_821BE8D8` (`src/gpu_device.cpp:12126`-ff): one line per newly-seen `lr`, plus a `lr:count[...]` summary every 200 calls. Added because the older `n <= 24` predicate could only ever show `lr=8218C804` and so could neither confirm nor refute F-157's attribution. w170 result: 5 callers, and the dereferencing one (`lr=82191070`, `sub_82191040`) runs exactly once per boot |
| `BE0C8-OBJ` | the F-163 scoped return: `sub_821BE0C8` handing back a guest-shaped stream OBJECT (`+0` device, `+4` slot index, `+8` buf, `+28`/`+32` size) instead of the slot index - but only while the `sub_821BE8D8` hook's one-shot latch is set, i.e. only for the caller that dereferences it. Expect ~4 lines/boot (one per entity realization), each with `obj=`, `h=`, `buf=`, `size=`. **Compare with F-153/F-155/F-156: the same object shape applied to all 179 re-opens loses `LISTLINE`/`TYPINIT`/`FACTORY`/`DICTLOOKUP`** |
| `XSF-BIND` | what size the packfile device actually bound for a member: `path`/`dev`/`h`/`wrap`/`tocEntry`/**`size`**/`buf` (`src/gpu_device.cpp:11388`-ff, cap `n <= 16 || n % 8 == 0`, so a low count is not a low number of binds). This is the instrument that found F-165: six container members each printed `size=32768`. From F-171 on, the four UI `.xsf` must show their own declared lengths (credits 29,655 / garage 1,066,057 / policecam 19,337 / raceeditor 143,069) - if they show the same number again, the per-record package selection has regressed |
| `PKG-SUBST` / `CC6F0-PKGSUBST` / `XSF-HOSTSERVE` | the three places a host-side plaintext RSC5 window replaces archive bytes: `src/gpu_device.cpp:763` (TOC-census serve), `:10075` (the `sub_821CC6F0` read/continuation path), `:786` (body handed to the guest). Read the `pkg=` **set**, not the count: F-171's fix is visible as seven distinct packages where every `.xsf` used to receive legals' `000A0000`. `:10032`-`10036` still prefers the path-substring map and validates nothing, so a `CC6F0-PKGSUBST` line is not yet evidence the right package was used |
| `XSF-INFLATE` | the host expansion of an RSC5/Xcompress body (`src/gpu_device.cpp:682`-ff), keyed on the path so per-file success is visible. **0 in every soak through `w181`** while whole, ID-verified packages are being handed over - that is the current menu blocker (F-170/F-171): the payload behind `RSC5+0x0C == 0x0FF512EF` is not raw deflate in any framing tried over `+0x14..+0x2F`. `swfCMD` staying 0 is downstream of this, not independent evidence |
| `REQFILL sub_821867A0` | F-173, corrected by F-174: one line per call to a guest 28-byte streamer-request **builder** (`src/gpu_device.cpp:8418`-ff, registers-only, cap `n <= 24 || n % 2000`). It fires **twice per boot**, returns slot ids 3 and 4, has exactly ONE caller (`sub_82187150+0x1A8`), and its only non-pointer argument (`r5`) is 0 both times. **It is NOT the writer of the pool `sub_821BC140` reads** - its destination array is the caller's own `r1+224 + idx*28` - so do not cite it as the origin of the zero inflate length. Keep this hook register-only: a census in this subsystem once AV'd its consumer by reading guest memory (`ENQ sub_821BCB10` note)|
| `INFLATE-ENTER` / `READWRAP` | the two lines that together diagnose the inflate door: `INFLATE-ENTER st= in= inPtr= consumed= outPtr= lr=` (our `sub_821D5E10` hook, `src/gpu_device.cpp:7067`-ff) and `READWRAP sub_821CC6F0 r3= r4=[4 words] r5= r6= r7= ret= r1in= lr=` (`:10276`-ff, the packfile device's Read wrapper). `lr=821BC334` on a READWRAP line means the read came from the streamer's inflate loop; **`r7=0` there is the F-172 finding**. `st+0 = 0xFFFFFFF4` with `st+4 = stack+12` is what a zero-byte read produces after the guest's own priming arithmetic - do not read those as real sizes
| `STREAM-OPEN sub_821BCE68` | F-177: one line per `pgStreamer::Open` (registers-only, cap `n <= 24 || n % 500`). **7 firings per boot**, returning handle ids `0,1,2,3,4,0x8004,0x10004`; `r5` is the value read from `RSC5+0x04` (27/9/5442), and Open stores `dev->vtable[+84](dev)` into `record+4` - the length `sub_821BC140` later reads. Pair it with `REQDUMP d[0]` / `ENQ a0` to see which three requests actually execute. The `memory:` device's `+84` is the shared `li r3,0` stub (`0x821A5CC0`, which we force to 0 at `src/gpu_device.cpp:12642`-ff), so a zero length there is ours, not the archive's |
| `STUB-SLOT` / `STUB-SLOT-TALLY` | per-`lr` tally inside the shared no-op vtable stub `sub_821A5CC0` (`li r3,0; blr`, thirteen slots of `0x82012918` point at it; we override it at `src/gpu_device.cpp:12642`-ff). One line per newly-seen `lr` (max 16) + the first 12 calls. w186: **four** callers per boot - `8217784C`, `8218C82C` (the device+88 case the override exists for), `821BE67C`, and the hot `82177EF8`. Any vtable slot you implement must be checked against this list, because those thirteen slots are indistinguishable by address (F-178) |
| **Hazard: `INFLATE-ENTER` and `READWRAP` count a timed spin** | their totals depend on how many iterations fit in the soak timeout, so a logging footprint moves them without any change in guest progress (`w185`→`w186`: 149→82 and 278→138 with all 17 structural counters identical). They are not admissibility evidence and not progress evidence - use `LISTLINE`/`TYPINIT`/`GETDEV`/`CP-DRAW`/`PRESENT`/`DRAW_INDEXED`/`C0000005`/`SEEK-DEAD`/`Fatal error`/`FATAL-SOFT`/`DICTLOOKUP`/`[error]` instead (F-178) |
| `BC140-REC` | F-180: the 28-byte streamer record `sub_821BC140` actually indexes, read before its body runs (`n <= 8`, all reads checked; INLINE-EXEC fires 3x/boot so it is free). `base = [[0x8283D190+52]]`, `rec = base + ([slot+0] & (cap-1))*28` with `cap = [0x8283D190+24]` = 0x8000. Layout: `{+0 index|generation<<15, +4 BYTE COUNT, +8 device, +12 flag, +16 package ID, +20 entry offset, +24 package offset}`. w187: the count is 240,531 and 10,799 for two generations and **0 for the legals one** - that zero is what makes the inflate read 0 bytes (F-172) |
| `VECTORED exception code=0x406D1388` | benign Windows SetThreadName exception from host code — not guest |

## 10. RE tooling

- **IDA MCP** on `127.0.0.1:8745`. **Two ways in, and the safe one is usually not the configured one.**
  `idalib-mcp.exe "<workspace>\build\game_data\default.xex"` already serves MCP over HTTP there, so if
  a process by that name exists, **attach to it** (POST `/mcp` with
  `Accept: application/json, text/event-stream`, keep the `Mcp-Session-Id`, then `initialize` →
  `notifications/initialized` → `tools/list` / `tools/call`; 47 tools, `get_metadata` gives
  `base 0x82000000 size 0xad3000 md5 062233a2…`). Do **not** start `ida-bridge.py` in that case —
  its line 25 is `taskkill /F /IM idalib-mcp.exe`, which destroys another session's IDB (rule 11,
  and `LONG_TODO_MASTER` §8.8). Only when nothing is listening is the bridge the way in
  (`tools/start_idalib_mcp.ps1`, or the venv python with `-v "E:/mcla pc/build/cache/mcla_pe.bin"`).
  Do NOT use the SSE `idalib_server.py` with the proxy. Useful tools: `get_function_by_address`,
  `decompile_function`, `disassemble_function`, `get_xrefs_to`, `list_strings_filter`,
  `read_memory_bytes`, `data_read_string`. Remember §4/§10: an IDA xref list is a hypothesis until the
  generated TUs and raw words agree — F-060/F-061 were both built by pairing `get_xrefs_to` with
  `grep` over `generated/ppc_xenon`, and F-062 refuted a TLS theory that IDA's output supported.
- Ghidra RETIRED.
- Generated TUs are ground truth for bodies; IDA function starts are
  unreliable on this raw bin; IDA xrefs must be bl-scan-verified (§4).
- Host crash attribution: llvm-symbolizer + PDB for host RVAs; `FFBT` census
  for guest-side stores; the emu's crash filter (`boot_host.cpp`) can scan
  guest memory for a needle value.
- Find subagent useful for caller mapping; keep the main window for decisions.

Host PCs are now nameable (F-120): `CMakeLists.txt` links `mcla` with `/MAP`, so every
build emits `build/mcla.map` (~149k public symbols). Resolve a logged `rawrip` as
`rva = rawrip - <PARK-SAMPLE base=…>` then take the greatest symbol rva ≤ it (the map's `Rva+Base`
column minus the 0x140000000 exe preferred base). `NearestFunctionName` still prints `host 0x…`
because it does not read the map — resolve offline for now. A PDB is NOT produced (no `/Zi`, and
adding compile flags risks the known clang-19/STL breakage).

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
