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

### 4.1 IDA address mapping (per-section delta)

IDA's DB is loaded through the **PE section table (which lies)**, so an IDA address is NOT a guest
VA: **IDA_addr = true_VA + delta**, i.e. **true_VA = IDA_addr − delta**. Ranges below are *IDA*
addresses; delta = section RVA − PointerToRawData (`.text` 0x130000−0x12C800 = 0x3800,
`.data` 0x7D0000−0x7C9A00 = 0x6600):

| region | IDA range | delta to subtract |
|---|---|---|
| `.rdata`, `.pdata`, BINKBSS, imports (true VA < 0x82130000) | `< 0x82130000` | **0** |
| `.text` / BINK (guest code) | `0x82130000 .. 0x827D0000` | **+0x3800** |
| `.data` and above | `>= 0x827D0000` | **+0x6600** |
| `.tls` / `.idata` (never needed for guest code) | — | +0x120400 / +0x121800 |

Ground truth stays the raw image: `build/cache/mcla_pe.bin` — raw PPC-BE, MD5
`3f2510c154af5da2236c4522198c4f0e`, size `0x9E0000`, machine `0x1F2` POWERPCBE, ImageBase
`0x82000000`, SectionAlignment `0x10000`, FileAlignment `0x200` (re-read 2026-09-27). So keep the
§4 identity map (`file offset = true_VA − 0x82000000`) and read bytes from the bin's real file
offset — **never** trust a section's VA (existing rule **F-023**, §4 above; not repeated here).

Verified this session against the raw bin:
- string `Required grmShaderGroupVar '%s' not found.` — IDA `0x8200c4c4` = file `0xC4C4` = true VA → delta **0**;
- IDA `0x82464810` bytes `7d8802a6 4bf781b1` byte-match generated `sub_82461010`
  (`generated/ppc_xenon/ppc_recomp.82.cpp:12113`, file `0x461010`) → delta **0x3800**;
- IDA `0x827D0000` = file `0x7C9A00` = true VA `0x827C9A00` → delta **0x6600**.

Cross-check discipline for any finding: every body read from IDA is byte-compared against
`generated/ppc_xenon/ppc_recomp.*.cpp`; every xref is cross-checked against a raw `bl`-scan of
`mcla_pe.bin` (opcode 18, target = pc + signext(LI)); and **subtract 0x3800 from any IDA address
before citing it in a finding**. IDA is a hypothesis until the bytes agree (§10).

IDA MCP used this session: `http://127.0.0.1:8745/mcp`, a live idalib instance — **attach** to it
(POST, `Accept: application/json, text/event-stream`, keep `Mcp-Session-Id`; §10/F-350). **Never**
launch `tools/ida-bridge.py` while it is listening: it `taskkill`s `idalib-mcp.exe` (rule 11).

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
- **Physical:** one pool → o1heap arena **`0xA0400000`–`0xFFFFFFFF`** (~1.5 GB; F-391 moved its base
  up from `0xA0000000`, because the title's own XTL dual-buddy allocator lives at
  `0xA0001000..0xA002FFC0` and was overwriting our fragment headers — see `kPhysArenaBeginVa` in
  `src/kernel/heap_arena.h`);
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
| `F374-HEAPGUARD` / `F374-HEAPSTORE` / `F375-HEAPSTORE` | `src/boot_host.cpp` (F-374 block: `HeapGuardHandle`, `HeapGuardArm/Disarm` + the public wrappers), `src/kernel/heap.cpp` (`HeapGuardWindow` RAII inside `Alloc`/`Free`), `src/guest_memory.cpp` (`ReportHeapInstanceStore`), `src/gpu_cp.cpp` (`HeapInstanceStoreReport`) | **READ-ONLY INSTRUMENT WITH ONE REAL BEHAVIOUR RISK.** A guard page over the guest user heap's first page (host `g_base+0x20000`) names whoever writes the allocator header. The page is writable only while a `Heap::Alloc`/`Free` is in flight, and every arm is validated by a deliberate SELFTEST read (the F-100 rule). THE RISK: the handler claims ANY `C0000005` on that page and returns `EXCEPTION_CONTINUE_EXECUTION`, so a genuine crash inside the arena's first 4 KB is absorbed as a trip instead of reaching the VEH census. Measured cost: 3 trips/boot, `LISTLINE`/`C0000005`/`Fatal error` unchanged (F-374/F-375) | 3 |
| `F370-THREAD-CTX-NULL` | `src/kernel/guest_thread.cpp:22-36` (+ the matching refusal in `GuestThread::Start`, `:157-159`) | **MITIGATION of our own bug (F-370).** `g_userHeap.Alloc(0x40E70)` can return null (it did, once the user-heap header at guest `0x20000` was corrupted) and the ctor used to `memset` the result regardless → write through `null+0x20` → host `C0000005` that killed the calling thread (`w373`). Now the failure is logged and the entry point is not run. It does **not** fabricate a context: the thread still does not exist, so this is a clearer failure, not a fix for the corruption. Cap 16 then every 100 | 1 in `w374`/`w375`/`w376` |
| `F370-HEAP-HDR` / `F370-HEAP-BIG` | `src/kernel/heap.cpp:121-215` (bracket), `:287`/`:317` + Free's user-heap branch (call sites) | **READ-ONLY census.** `capacity` is constant, so comparing the `O1HeapInstance` against the value captured at `Heap::Init` on `pre-alloc`/`post-alloc`/`post-free` brackets any header corruption to one operation (or, as in F-370, proves it happens outside every heap call). `HEAP-BIG` records every ≥256 KiB user-heap allocation with `cap/used/peak/oom` and a module-relative `caller_rva`, which `python tools/host_rva_resolve.py build/mcla.map <rva>` turns into a host symbol | HDR 1, BIG 16 in `w376` |
| `F373-HEAP-GOLDEN` / `F373-HEAP-RAW` | `src/kernel/heap.cpp` (`CheckHeapHeader`): the first 40 bytes of the o1heap instance dumped while healthy (the positive control -- `read_ok=true` plus the golden `cap`) and again at the failure (`retrans`/`moved` show the page never changed; `phys_same` excludes a copy of the other arena). **Those 40 bytes are `bins[]`, NOT `capacity`/`allocated`** -- `src/kernel/o1heap.c:133-138` puts the diagnostics at `+0x208` (F-373, corrected by F-375) | 1+1 |
| `F374-HEAPSTORE` / `F375-HEAPSTORE` | `src/guest_memory.cpp`, `src/gpu_cp.cpp` | the checked writer whose destination fell inside guest `0x20000..0x20240` (the host heap instance), with `caller_rva` (name it through `tools/host_rva_resolve.py`), then the guest argument window for the same store: `lr`, `sp`, `r3..r7`, `r13` | 16 / 8 |
| `F386-PHYSFREE` / `F388-PHYSGUARD`(-`BT`) | `src/kernel/heap.cpp:417-500` (validates all 64 physical-heap bin heads on every `AllocPhysical`, then samples `Fragment::next_free` links round-robin, 8 nodes/call), `src/boot_host.cpp` (F-388: guard page over the PHYSICAL instance at guest `0xA0000000`, armed/disarmed with the same window; its handler prints a host backtrace because the faulting thread publishes no `PPCContext`) | **READ-ONLY INSTRUMENTS, BOTH CURRENTLY UNABLE TO ANSWER -- KNOWN DEFECT.** `F386` printed 0 rows in `w398`/`w399` while `o1heapAllocate+0x98` AVs once per boot, and `F388`'s trips resolve to `o1heapAllocate+0xb9 <- SehO1Allocate <- Heap::AllocPhysical` (our own allocator). Reason: the arm/disarm pair flips ONE global flag shared by both heaps and all threads, so another thread's `HeapGuardArm()` re-arms mid-operation. Until that becomes a depth counter, a `F388` trip is not evidence of a foreign writer and an `F386` zero is not evidence of a clean heap (F-386) | 0 rows / 3 own-writer trips in `w400` |
| `F389-XTLCHAIN` / `F389-BANK` / `F390-SEHPASS` | `src/gpu_cp.cpp` (fires with the first store into the watched heap page: dereferences the title's XTL allocator chain `[[r13]+28] -> [obj] -> [vt+8]`, then the dispatcher's bank object `[[bank]+4]` and its 8-word head), `src/boot_host.cpp` (F-390: the VEH returns `EXCEPTION_CONTINUE_SEARCH` when the faulting function IS `o1heapAllocate`/`o1heapFree`, so the pre-existing `SehO1*` SEH absorbs it instead of the thread being parked), `src/kernel/heap.h` (F-390b: `Alloc<T>`/`AllocPhysical<T>` null checks) | **CENSUS + TWO REAL FIXES.** `F389-BANK` is what closed T41.67: the title's allocator region is guest `0xA0001000..0xA002FFC0`, i.e. inside the host physical arena as previously bound at `0xA0000000` -> `kPhysArenaBeginVa = 0xA0400000`. A `F390-SEHPASS` row means the allocator hit a poisoned pointer and survived; in `w406` there are none and no `o1heapAllocate` AV. Read a zero of these only together with the `F388-PHYSGUARD SELFTEST` row, which proves the probe is still looking at the arena's current page | 1 chain + 1 bank row (`w403`), 1 SEHPASS (`w404`), 0 + 0 (`w406`) |
| `F380-XCRESET` / `F380-XCPOST` / `F381-XCSTATE` / `F381-LOWVA` / `F382-MEMCPY(-LIVE)` / `F383-WRITEROWNER` / `F379-HEAPSTORE-BT` / `F378-HEAPSTACK` | `src/gpu_device.cpp:5579`/`:5651` (xmem state before/after each soft-reset and after each window), `src/gpu_cp.cpp:1866-1949` (host backtrace, unwind-table owner, state at store time, low-VA sample, guest stack words), `src/gpu_device.cpp:17159-17177` (guest `sub_823DA950` = memcpy hook, **log-only, span-filtered**) | **READ-ONLY CENSUS + ONE REAL HOOK.** All of it exists to answer "who writes the host heap header at guest `0x20000`", and F-383 is the answer: our own Path A driver. The hook overrides the generated weak alias (same mechanism as `sub_82193AF8`), prints `dst/src/len/lr/sp/tid` only when a copy *spans* `0x20000..0x20240`, and carries its own positive control (`F382-MEMCPY-LIVE`). **The one behaviour-bearing line in the group is `MclaXcSoftResetStream` (`src/gpu_device.cpp:5464-5479`) -- that is a FIX, not a mitigation (F-383).** | 16 BT rows, 1 state row, 1-5 hook rows per boot (`w389`..`w394`) |
| `kF393NoHijackNonUi` | `src/gpu_device.cpp:1072` (flag), `:11174-11188` (gate body) | **EXPERIMENT SWITCH, currently `false` — measured and REJECTED (F-393).** When true it returns from the `inLeft == 0` leg, before any retry bookkeeping, for every dest whose `AssignPackageForDest` package is not a UI .xsf container: no record write at all, so the title takes its own async read (`ppc_recomp.14.cpp:19047` -> `loc_821BC2F0`/`loc_821BC310`). It did break the 6,747,400-entry spin in `sub_821BC140` (down to 231,518 entries, `READWRAP` 1,742 -> 463,018) and it cost the garage 917,504 -> 143,069 durable bytes, because `inLeft == 0` is a property of the ONE shared record `st=006D8F20` and cannot be decided per destination. Census marker `F393-SERVE-SKIP`. | 484 (`w407`, flag on), 0 (`w408`, flag off) |
| `F370-SEMA` | `src/gpu_device.cpp` (`F370SemaRow`, called from the `sub_82135DC0`/`sub_82135DB8` wait hooks and the `sub_821C9108` release hook), registry in `src/boot_host.cpp` (F-370 block) fed by `imports.cpp::NtCreateSemaphore` | **READ-ONLY census.** One row per `WAIT`/`RETURNED`/`RELEASE` on any semaphore created with a non-zero initial count (i.e. a permit pool / job limiter), with `init=`, `x=` (timeout arg, or the returned status), `tid=` and the caller `lr=`. **Budget is per handle** (24 then every 200) because the first version shared one cap of 80 and the busiest handle took 83 of 84 rows, leaving the handle under investigation at zero | 33 in `w376` |
| `F369-SHGRP-SOFT` | `src/gpu_device.cpp:17121-17138` (inside the F-142 binder hook, which opens at `:17059`) | **MITIGATION (F-369, user-directed).** Clears `sub_82193AF8(group,name,required)`'s `required` argument, so a shader-group variable that the group does not declare returns through the guest's own non-fatal exit `loc_82193BAC` (`r3=0`) instead of calling the fatal dispatcher `sub_821BD618`, whose host override parks the calling thread forever (`src/kernel/imports.cpp:3028`). Narrow by construction: `r5` is written once and read once in that body (`ppc_recomp.10.cpp:17741`/`:17804`) and that read only gates the fatal, and a *present* name reaches the same success work either way, so no successful binding is masked. Every application is logged by name — in `w373` there are exactly **2**: `skinningData` and `effectFade` | 2 |
| `kF368HostDispatchGate` | `src/gpu_device.cpp:2047` | **EXPERIMENT SWITCH, currently `false`.** When true, the alive path of `PPC_FUNC(sub_821873E8)` calls `dispatchBootGateOnce()` (`:2254`), i.e. the host forces `sub_82131008` (the UI-load gate) itself on a detached thread, seed-free. User-approved 2026-09-26 and **still un-run**: it is held off because with it ON, a non-zero `W35-BOOT-GATE` would be our own dispatch rather than proof the guest reached `0x821315F4`. Flip it only for a dedicated soak | 0 |
| `BE710-SLOT` | `src/gpu_device.cpp:11484` | answers a device Read from the host slot table, `ctx.r3=served/4; return` — `__imp__sub_821BE710` never runs | 49 |
| `kInflateIntervene` (`src/gpu_device.cpp:7085`) | **EXPERIMENT SWITCH, currently `true` = current behaviour.** Set to `false` and `PPC_FUNC(sub_821D5E10)` performs **no** state rewrite at all: it chains straight to the guest's own `zlibInflater::InflateBegin`. Measured (F-182, `w189`): `INFLATE-ENTER 149→1`, `XMEM 40→1`, the guest's own `not in XCompress format` assert becomes visible - but `Fatal error 0→2`, `FATAL-SOFT 0→2`, `GFx 5→1`, so the re-point is load-bearing and the switch stays on. Use it as the removal test whenever the inflate hook is suspected |
| `kServeFromXCompressHead` (`src/gpu_device.cpp:315`) | **MITIGATION-candidate switch, currently `false`.** When true, an RSC5-framed member is served from `pkg+0x0C` instead of `pkg+0x00`, so the stream begins with the XCompress magic `0x0FF512EF` that `InflateBegin` tests. Measured (F-183, `w190`): **zero effect** - identical to `w189` on all 18 markers, so the stream the guest checks is not the XSF-served body. Kept as a switch because it is the only handle on that framing |
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
| `kF463AbstainNestedRpf` (F-463, **false**) | src/gpu_device.cpp:1618 plant site, marker `F463-SERVE-ABSTAIN` | scoped experiment: suppress the host plant for nested packfiles (`preload/xarchive_*.rpf`) so the title's own read is the only thing that can decrypt a member. Measured INERT for its gate in `w465` vs `w457`/`w460` (`BDF20 #600 tune/...lst ret=0` in both) and reverted; the branch stays for reuse | 18 (`w465` ON) / 0 (`w466` OFF) |
| `kF465GarageReindex` (F-465, **false**) | `src/gpu_device.cpp` inside the Path B enqueue census (after the `PATHB-REC` dump) | ordering construction: copy the garage's job-array record to a free index (0x20) and re-point its 1556-byte job object at that index. Measured NON-APPLICABLE in `w468` — `F465-REINDEX-SKIP … slotFound=00000000`: no job object in the `0x82849B2C + k*0x614` ring carries the garage handle `0x8001`, so the garage has a record but no dispatchable object. Compiled out at flag-off (marker string absent from the binary), so read the source | 1 skip (`w468` ON) / 0 (flag OFF) |
| `kF474NoPrematureJoinClear` (F-474, **false**) | two sites: the fence-side call `src/gpu_device.cpp:4707` (`ClearTaskJoinBusy`, defined `:4626`) and the join-side force-clear `:4748`; marker `TASKJOIN-SC` | session-72 mitigation that zeroes a record's `+12` join wait word so `sub_821BD220` returns instead of spinning. F-474 tested whether *we* are prematurely releasing streamer records: with both sites disarmed (`w479`) `TASKJOIN-SC` = 0 and the record re-stamping is UNCHANGED, while the boot loses 2 of 7 jobs (`GFx` 13 -> 7, 146k -> 27k lines) and the job-completion callback still fires once. Refuted, so the mitigation stays armed; control `w480` reproduces `w477` (7 SC rows). Source retained as a warning | 0 (OFF) / 7 (`w479` ON) |
| `kF468AlignRecordIndex` (F-468, **false**) | `src/gpu_device.cpp` inside the Path B enqueue census (after the `PATHB-REC` dump), markers `F468-ALIGN` / `F468-ALIGN-SKIP` | attempted fix for F-467's index mismatch: copy each UI record to its queue-tag index. Measured NON-EFFECTIVE at the gate and REGRESSIVE (`w471`: `INFLATE` 5,065 -> 306,926, `LZX-FRAME` 32 -> 3, `F442-SECTION` 14 -> 3) because the copy runs 22 ms before the guest fills `+4` — `F468-ALIGN #2 … remain=0`. Reverted; `w473` re-soak equals `w460` on every marker. Source retained as a warning, compiled out at flag-off | 4 (`w471` ON) / 0 (OFF) |
| `INFLATE-J2-WIN-CONT-SKIP` | `:7354` | abandons the guest's continuation walk | 1 |
| `kHostLzxDecode` / `MclaHostXcDecodePackage` | `src/gpu_device.cpp:323` / `:4114` (use `:804-810`) | **MITIGATION, Path A (F-188; F-189/F-190).** Host libmspack LZX of an RSC5+XCompress UI package inside `HostServeUiBody` so UI `.xsf` serve expanded without guest inflate/`0x82461530`. Path B (`sub_821E5E58` descriptors) dropped after F-187. Refuses partial (w199 32KB/143069 → `XSF-LZX-FAIL`); concats multi-frame XC before one `lzxd`. Lists stay DEFLATE/`RawInflate`. Pass = `XSF-LZX >= 4` + `W34-NOGFX` falling | `XSF-LZX` 4 UI / `XSF-LZX-FAIL` in `w199` |

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
`3c8744e` — stays till INSERT clean) · **`kF432SkipZeroCountGrow` / F432-SC** (`src/gpu_device.cpp:17469` flag,
`:17519-17525` gate: returns from `sub_82397060` without running its body when `r4 == 0`, because that
degenerate count makes its free-list link loop run 2^32-1 times writing `[X+12]=X+16` across all 4 GB —
F-432; measured `w431`: `C0000005` 4→0, `F379-HEAPSTORE-BT` 19→0, garage durable −65,536, `nGfx` unchanged at 0,
so it is life-support for the heap, NOT a route to GFx) · **`kF434BreakNoProgressSpin` / F434-SC**
(`src/gpu_device.cpp:1088-1097` flag, `:11007-11042` gate: after 64 consecutive no-progress sightings
of the *same* `(st, consumed)` with `0 < inLeft < 256`, `outLeft > 0`, `produced == 0`, write the
caller loop's own stream-complete key `[st+0]=0 / [st+16]=0` — the same drain `INFLATE-UNSTUCK` already
performs, which is gated on `produced > 0` and therefore unreachable for a non-UI stream. `w432`:
`INFLATE-ENTER` 117,229 → 2,378 rows, **`BC140-REC` 5 → 7** (two new streamer records reach
`sub_821BC140` for the first time), `W34-GFX-CENSUS` 3 → 6 rows now reading `vt=82085364 nLiveDest=4
tagNv=2`, garage durable back to 872,032. **`nGfx`/`GFX-CTOR` stay 0 — the GFx loader ctor still never
runs.** Trades a spin for a short container: the drained dest keeps whatever was already in it).
 Wake-loss identity fix = real bugfix.
Poison values: `0xCDCDCDCD` = guest fill-on-alloc (uninitialized, NOT
corruption) · `0xDD` = free-fill · `0xFF00FF00`/`0xFFFF00FF` = missing-texture
texels, NOT poison.

`kPathBHostFullDecode` (F-297, **ON by default**, `src/gpu_device.cpp:440`;
labels `PATHB-HOSTDECODE`, `PATHB-HOSTDECODE-TOP`, `PATHB-HOSTDECODE-TOP-SKIP`,
`PATHB-HOSTDECODE-FAIL`; plus `PATHB-HOSTVERIFY`, a log-only one-shot readback
that digests the whole written body and re-checks it against guest memory, F-299)
— Path A host XMem/raw-LZX decode of the 4 UI `.xsf` (`src/xmem_lzx.h`) written
straight into the guest dest, at the top of the inflate handler and at the
corrupt-serve leg. It **bypasses the guest's own inflate** for those containers
and drains `outLeft` (the caller-loop complete key), so it is a short-circuit, not
a fix: it exists because the guest's progressive streamer only ever delivers
window 1 and every guest-decoder re-entry collapses boot (F-288, F-290, F-293).
Targeted by the *dynamic* dest→package map + a package-offset allowlist, so a
flag-OFF boot never routes through it. Refuses to complete a container that does
not fit its dest room. Verified `w271` and `w272`: 3 of 4 byte-exact, `C0000005`
0, every structural marker +0 vs `w270`; `nGfx` still 0 (the GFx gate is
upstream). See F-295 and the ledger's F-297 entry.

`kUiXsfChunkFeed` (F-318, **ON by default**, `src/gpu_device.cpp:589`; helper
`MclaUiXsfChunkOpen`) — **not** a decode short-circuit: it changes our *abort
policy*. Three edits, all keyed on the dynamic dest→package map plus the stable
UI `.xsf` package offsets: skip the B7 no-progress backup-drain for a UI `.xsf`
dest whose walk is still open, refill on every empty retry instead of only
`retries == 3`, and give it the 400-retry budget instead of 24. Named as a
mitigation because it removes an abort that our own code added (do-not #9), and it
is bounded by `retries < 400` and `walk < PackageSizeAt` (after which the drain
resumes). **Supersedes the sentence above: the guest streamer is not limited to
window 1 — **⚠ two claims in that paragraph were later superseded:** the stall after window 1
is NOT a partial-window leftover and `PackageSizeAt`'s `0x40000` fallback is NOT the
binding limit — see F-320 (the guest walks its own readlist slots; the feed is keyed
on the inflate state) and F-321 §3 (the bound is now
`MclaUiXsfWalkCeil` = RSC5 `+0x10` + a window, and input stops at the same place
either way).** `kUiServeAdvance` stays **OFF**
(F-315's `ls.pos += consumed` double-counts a *cumulative* field and livelocked
`w275`; see F-318 §1).

`kUiXsfFrameServe` (F-327, **OFF**, `src/gpu_device.cpp:8442`) serves whole container frames
instead of fixed 0x8000 slices, and `kUiXsfClearResume` (F-333, **OFF**, `:631`) additionally
clears the frame driver's per-frame resume pair when it does. **These two are a registered,
tested-and-reverted pair, not a lead:** ON together they did clear the latch and did walk the
garage's real frame table (offsets 0 / 0x2564 / 0x39BA / 0x46CA, frames of 9572 / 5206 / 3344
/ 4072 B) but coverage got WORSE, 63,072 → 43,732, with ~89,000 failing frames and
`INFLATE-ENTER` 4,890 → 17,703 (`w307`, reverted and re-verified in `w308`). The lesson is
F-333 §3: the LZX decode is one continuous bit stream, so moving `src` under the driver is
wrong in both directions, and the surviving Path B design is to extend the buffer the guest is
already pointing at (`UI_INFLATE_PLAN.md` §5 step 1).

**F-341 A/B on `kUiXsfChunkFeed` (ON, `src/gpu_device.cpp:589`): turning the UI refill off reproduced `w322`'s fingerprint (`UIXSF-LOCATE` 0, `PEND` 2) and left durable coverage identical - garage 63,072, raceeditor 143,069/143,069 - so this serve is INERT with respect to the deliverable and the default stays ON for want of a positive reason to move it (two 120 s soaks under-sample retirement behaviour, F-315/F-325).**

`kUiXsfLocate` (**ON**, `src/gpu_device.cpp:642`) is log-only: it locates the stream's
current input buffer inside its own package image and prints whether our bookkeeping
agrees. It exists because F-333 could not say whether the data was missing or our
position model was wrong, and its first finding (F-334) is that at the refill the guest's
`inPtr` is stack-resident (`st + 0x20`), which withdrew the plan's §5 step 1.

`kUiXsfAppendWindow` (**OFF**, `src/gpu_device.cpp:660`) is F-335's tested-and-reverted
append-only window: it gives a stream one buffer sized for its container, fills it
forward, and touches `st+4` only on the first install. Registered as a **closed**
intervention — it worked mechanically and the decode did not move, because the guest
re-arms its inflate record every call (see `UIXSF-APPEND`'s `re-pointed=1`). The next
candidate is a per-stream codec-ctx re-init (`sub_82460F88` / `sub_82461840`), not
another window shape.

`kUiXsfPrivateCtx` (**OFF**, `src/gpu_device.cpp:674`) implements plan step 1c: open a
private codec context per UI .xsf stream by replaying the guest's own Open call
`sub_82461378(0x8EFFF990, 1, block, 0x3492E)` and republish the stream's `*obj` (the slot
is `0x8283D1B0`, and it held the shared `0x4000FD80`). Registered as a **tested and
reverted** intervention: the mechanism was observed working and the boot then went
shallower (27,760 lines vs 58,119, `INFLATE-ENTER` 32 vs 4,901) because `Alloc(0x35000)`
returned `0xCAF28300` — the same address `XSF-HOSTSERVE` uses. Retry only after the
context was placed at an address asserted disjoint from every serve window (F-338) and it did NOT help: the slot is a per-JOB record, so any write to it changes every stream in that job. F-339 built exactly that pair, keyed on `st`, and it did not help either: `st` is per-job as well, so no key exists at this layer. Per-stream isolation has to be constructed in the guest's job loop (task #15), which is why the flag is off.

`kUiXsfSerializeCtx` (**OFF**, `src/gpu_device.cpp:731`) lets one UI container hold the shared codec context at a time, keyed on the package offset, with a 40-stall cap so it can never livelock. Measured null (F-340). The reason it was tried: `*obj` turns out to be a field of a **global** streamer object (`0x8283D190 + 0x20 = 0x8283D1B0`, `ppc_recomp.14.cpp:18844-18874`), i.e. one context for the whole streamer — the measured form of the “one shared decoder” idea whose earlier address was wrong. **F-340 also changes how to read the coverage marker: `still_present` varies across boots for the same binary (121,946 vs 63,072), so one soak is not evidence of a coverage change.**

`kUiXsfPerPkgCtx` (**OFF**, `src/gpu_device.cpp:761`) is F-342: one private codec context per UI package, opened with the guest's own `sub_82461378` replay and published into the streamer's context slot for entries whose destination binds to that package, with the captured original restored for everything else. Registered as a **tested and reverted** intervention, and the most informative of the three: the swap succeeds once and the decoder then produces nothing at all (`LZX-FRAME failtotal` 0, `INFLATE-ENTER` 32 vs 4,901), because that slot is the streamer's **live** current-context field, not an inflate argument. Do not re-try any variant that writes it — isolate upstream (arm one container at a time) or give each descriptor its own pointer field.

`kUiXsfClearResumeEvery` (**OFF**) + `kUiXsfFrameServe` (**OFF**) - F-343's completion of F-333: clear the frame driver's `[S+12276]`/`[S+12280]`/`[S+12272]` on every entry whose destination binds to a UI .xsf package (F-333 cleared them once, which the per-call re-arming made stale). Registered as **tested and reverted, and it upgrades F-333's verdict**: same 43,732 coverage, with `cumprod` 196,608 vs ~917,504 and `failtotal` 70,483 vs ~5,280 - uncapped tallies outside the coverage band, so the regression is real. **The driver's walk state is the continuous bit stream's position: respect it, do not erase it.**  `kUiXsfStreamHeadServe` (**OFF**, `src/gpu_device.cpp:473`) is F-347: serve a UI `.xsf` stream's first window from its XCompress sub-header (`pkg+0x0C`) instead of the container head, and zero the shared record's `consumed` so the guest's own preamble check runs. Registered as **tested and reverted**: the check provably fires (`XMEM-SRCHEAD` shows `src +8`, `srcSz 32768→32760`) and durable coverage is bit-identical (`63,072`, `first_bad=00008000`). Do not re-run it as a pairing with `kUiXsfFrameServe` — that combination is measured worse twice over (F-333, F-343). `kUiXsfWholeStreamWindow` (**OFF**, F-349) hands one inflate call the whole container (`st+4` written once, a 2 MB `s_wsBuf` kept separate from the legacy `s_hsBuf`). Registered as **tested, refuted by its own success and reverted**: the 1,07 MB presentation demonstrably landed (`INFLATE-HOSTSERVE-PEND … got=1098825 whole=1`) and frame 10 failed identically, while `INFLATE-ENTER` ran 106,697 times vs 4,901 and the garage's late reverify never printed — a livelock, not progress. Do not re-try feeding more input; F-348/F-349 together show the driver's walk, not its supply, is the blocker. `kUiXsfChunkedHostFill` (**ON**, `src/gpu_device.cpp:506`) + `kUiXsfFillDryRun`
(**false**, `:9011`) + `kUiXsfFillOwnSlots` (**true**, `:9022`) are F-350's placement:
Path A writes the oversized garage container across the guest's requested dest chain.
Registered as a **behaviour change that is kept**, with its own limit: the walk stays
inside the anchor's readlist (F-351 crossed tables, wrote credits' byte-exact
destination `B7801000`, and was withdrawn), and `kUiXsfFillOwnSlots` overwrites a slot
only when it belongs to this container's chain, is not claimed by another UI package,
and does not already equal the golden bytes. `kUiXsfCompareGuestCopy` (**ON**, log-only, `:455`) is the F-346 comparator; it perturbs nothing (`w335` vs `w334`: every tracked marker `+0`).
`kUiXsfHoldCtx` (**OFF**) is F-344's last hook-layer mechanism - skipping competing containers' inflate calls to hold the context - and it is a measured null (5 holds, 0 handovers, baseline everywhere); its first run's apparent `failtotal` win was a stalled boot, which is why `LZX-FRAME` must be read beside `INFLATE-ENTER`.

`kUiXsfGoldenFill` (F-323, **ON by default**) — **the third and most invasive host
write: it fills guest slots the guest never filled.** Find the slot mapped to a UI
`.xsf` package whose head equals golden offset 0 (the anchor), take the container's
virtual start as `anchor.vbase`, and write
`golden[slot.vbase - anchor.vbase]` into every inventoried slot inside that span.
Two protections are load-bearing: only slots that are currently poison/zero are
written (`UIXSF-GOLDEN-FILL-SKIP reason=NOT_UNTOUCHED`), which matters because
**`vbase` is per-job — the garage's job and raceeditor's job both start at
`0x50000000`**, so without it this would clobber a verified container; and one pass
per package per shot. Measured `w293`: garage `slots_written=4 bytes_written=819200`
= golden `[0, 0xC8000)` = 76.8 % of 1,066,057, of which **262,144 bytes are
certifiable as distinct** by the hunter (the container's 0x40000 blocks repeat, so a
needle match cannot tell them apart) — up from 32,768. **Every GFx marker stayed +0:
this buys decompressed-state presence, nothing downstream.**

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

>**F-437 CORRECTION (verified 01:3x): `nGfx` has never been a working GFx loader-object counter. `sub_824C6F08` writes `[obj+0]=0x820736DC` and then calls `sub_82482008`, which unconditionally overwrites `[obj+0]` with `0x8206DFAC` before the ctor returns (`ppc_recomp.94.cpp:3558-3571`, `ppc_recomp.87.cpp:16270+`) -- and the four scan bands miss the region loader objects are allocated in (`w433` forced one to `CF622D00`). The scan now accepts both vtable families (`src/gpu_device.cpp:7006-7016`); `w434` still reads 0 with zero `W34-GFX-MOVIE`/`W34-LIFE-KEYDEFER` rows, which is the band result. **Read `nGfx=0` as "not counted", never as "does not exist"** (T41.91 / task #58).**

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
| `PATHB-HOSTDECODE` / `-TOP` / `-TOP-SKIP` / `-FAIL` | the Path A host XMem/raw-LZX decode of a UI `.xsf` (`kPathBHostFullDecode`, `src/gpu_device.cpp:440`). `-TOP` = fired at the top of the inflate handler (`:7775`), bare = fired at the corrupt-serve leg (`:8993`); both print `dest`/`pkg`/`path` (1=single stream, 2=shared per-frame walk)/`unc`/`wrote`/`room`. `-TOP-SKIP`/`-FAIL` mean the container was **left to the guest** — either it does not fit the dest room (garage, 1066057 > a 256 KiB window) or the decode/load failed — and are not errors. Target selection is the dynamic `g_destPkgOff` map (`PeekPackageForDest`/`IsUiXsfPkg`, `:311-345`), never literal dest addresses (F-297). Decoder byte-exactness is guarded at build time by `ninja -C build check_xmem_lzx`. |
| `INFLATE-HOSTSERVE-PEND` (**census use added by F-318** — no new literal) | the per-dest 32 KiB package refill in the `inLeft == 0` block (`src/gpu_device.cpp`, the `hsThisRetry` branch). Its trailing `(pkg=… walk=… pkgSz=… serve=N)` fields are **the only honest garage-frontier metric**: `walk` advancing `00000000→00020000` with `serve=1→5` means the guest consumed five consecutive windows of `pkg=64980000`, which had never happened in any prior soak (`grep -l "pkg=64980000 walk=00008000" build/w*.log` → `w279.log` only). `-STOP`/`-CAP`/`-DONE`/`-FAIL` are the pre-existing bounds (head not RSC5/XC at walk 0; `walkPos+0x8000 > pkgSz+0x8000`; `serves >= ceil(pkgSz/0x8000)`). Count this marker, do not count `nGfx` (F-314) or line totals (F-072). |
| `UIXSF-SLOT-VERIFY` | **F-321 — the decompress deliverable's real verifier.** `MclaUiXsfVerifySlot` (called from the `sub_821D5510` FLUSH census on every call, one verdict per dest) re-derives the container with `mcla_lzx::host_decode_ui_xsf`, finds the dest's first 64 bytes in it, and compares forward: `goldoff`/`goldsize`/`compared`/`mismatch`/`firstbad`. `mismatch=0 goldoff=0` ⇒ that dest holds the container byte-exact from its start. A dest whose head is not in the golden prints `HEAD NOT IN GOLDEN`. **Built-in positive control: the Path A-written containers report `mismatch=0` in the same run**, so a non-zero result elsewhere is not a comparator artifact. w285: raceeditor/policecam×2/credits all exact over full length; garage `firstbad=00008000` = one window correct, then divergence. |
| `slotcov=` (**field**, on `FLUSH sub_821D5510` / `INFLATE-UNSTUCK` / `INFLATE-J2-DRAIN-B7`) | F-321: non-poison, non-zero words over the dest's first 4 KiB **at retirement** (max 1024; `4294967295` = not a UI `.xsf` dest, so ignore it). Fixes the `XMEM-UIHEAD` blind spot — that marker dumps on the *first* XMem call, so it reads a window about to be filled and cannot say "how full did it get". Coverage only: **occupancy, not correctness — always pair it with `UIXSF-SLOT-VERIFY`.** |
| `UIXSF-GOLDEN-REVERIFY` | **F-324 — the number to quote for "is it in guest memory".** `MclaUiXsfReverify` re-reads every recorded fill claim from guest memory and compares it to the golden **at the claimed offset**, merging overlapping claims so no byte counts twice: `claimed / still_present / pct / first_bad`. This is stronger than the hunter's needle search and it retires F-323's caveat — repeating blocks defeat a *search*, not an offset-anchored *compare*. w295: garage `claimed=1066057 still_present=1066057 pct=100`. Use `MclaUiXsfLateReverify` (F-325: every 1,000th `sub_821D5E10` entry) for the survival question — an early-only reverify proved the bytes **landed**, and the late samples showed the guest re-using the same slots for other streams, dropping the garage from 100 % to 64.9 %. NB `PRESENT` in a census is a substring collision with this row's `still_present=`, not a marker. |
| `UIXSF-GOLDEN-HUNT` / `-SUMMARY` | **F-322 — where in guest memory is each container, byte for byte.** `MclaUiXsfGoldenHunt` scans the slot inventory (`MclaUiXsfNoteSlot`, fed from the same `{vbase,pbase,size}` triplets the `PSTREAM` census reads) against the package's golden decode. Per-slot line = `slot[i]=pbase goldoff= compared= mismatch=`; the SUMMARY carries the honesty fields **`nmap / scanned / skip_range / skip_poison / skip_read / anchor / anchor_in_map`** — required, because the first version hunted `g_mclaRebaseMap` and printed `slots_matched=0` for all four packages *including one already proved byte-exact*, which is an instrument failure and not a finding. `bytes_exactly_covered` is a MERGED interval union (F-323), not a sum: garage.xsf's 0x40000 blocks repeat, so 4 matching slots certify 262,144 DISTINCT bytes, not 819,200. |
| `UIXSF-PRIVCTX` | **F-337/F-338 (flag now OFF)** — the per-stream codec-context experiment: `alloc raw=X..Y ctx=Z` (the doubled, disjoint allocation), `opened private ctx=Z (shared is 4000FD80)`, `obj=S *obj=C priv=P` and `obj=S ctx C -> P`. It is how we learned the context slot is `0x8283D1B0` and that it is **per-job**, which is why the flag is off. A zero here means the flag is OFF, not that the mechanism was unreachable. F-339 then added the paired publish/restore keyed on `st` and BOTH branches printed zero -- the binding applied to every stream of the job, which is what closes the avenue: `st` is per-job too. |
| `XMEM-OPEN-CENSUS` | **F-336** — counts the guest's codec-context Open path: hooks `sub_82461378` (the Open wrapper, `ppc_recomp.82.cpp:14590`), its single caller `sub_82460370`, and `sub_82460420` as a **fired control**. Prints `site= r3= r4= r5=` plus the running `[wrapper= caller= control=]` triple, so the caps cannot hide a count. **The finding: two opens per boot** (`r5=4000FD80`, `400446C0`) against thousands of container calls — i.e. one codec context is shared by every stream, which is the common cause behind the whole serve family's null results. |
| `UIXSF-APPEND` | **F-335 (flag now OFF)** — one append-only input window per UI .xsf stream: `OPENED buf= cap= base=` on allocation, then `walk pos appended filled inLeft st0 re-pointed` per refill. Its `re-pointed=1` on a later call is what refuted the design — the guest's `st+4` had returned to its own stack scratch, so the window could not hold continuity. **A zero for this marker now means the flag is OFF, not that the mechanism was not reached.** |
| `UIXSF-CTX-OWNER` | **F-340 (flag now OFF)** — serialisation of the one shared codec context: the first UI container to need it claims it (`pkg=` the package offset, never a dest address) and non-owners are refused a refill for up to 40 entries (`defer this stream (stall n/40)`), after which ownership hands over. Registered as a **measured null**: in the run where it engaged the garage stayed at 63,072 and `failtotal` at ~5,279. It also produced the session's important instrument finding — see `still_present` and F-340 §3. |
| `UIXSF-LOCATE` | **F-334** — answers “where in the package IS the guest's current input buffer?” Reads 16 bytes at the stream's input position (or the 16 ending at it when `inLeft == 0`), scans 4 MB of that stream's own package image for them, and prints `found_at` / `want_walk` / `walk` / `AGREE` / `delta`. It is what falsified §5 step 1 of the plan: all six firings in `w310` read `inPtr = st + 0x20` with `inLeft=0` and **NOT IN PACKAGE**, i.e. the guest's input pointer at the refill is inside its own stack record. ≤6 lines per inflate state, every early return prints (a silent guard on a frontier probe reads as a negative — w309). |
| `UIXSF-HOLD-CTX` | **F-344 (flag now OFF)** — context-ownership experiment: `pkg=X takes the context` / `pkg=Y blocked by owner X run=N (blocked=M)` / `hand over X -> Y (blocked=M)`. Skipping a container's inflate call is the only hook-layer action that actually protects the shared walk state, and it measured nothing. **Read it beside `INFLATE-ENTER` and the late-reverify sample count**: the unbounded version produced `failtotal` 6 only because the boot managed 40 entries. |
| `XMEM-CTX` | **F-331** — the frame driver's own state, snapshotted pre/post around `sub_8244FF20` in `src/gpu_device.cpp`. `ctx` is the codec context (`4000FD80` in every soak so far), `codec` must read 1 for the guest's own gate to pass, `frames` (`ctx+11992`) and `ctxprod` (`ctx+11044`) are the decoder's cumulative counters, `leftover` (`ctx+12292`) marks the staging-deferral path. **`frames` rising while `ctxprod` is flat is the signature of silently-failing frames** (F-331 §6) — the container call above still returns `ret=00000000`. Same gate as `XMEM-SZPTR` (`n<=24` or ≤8 per dest), so a missing line is not a zero count. |
| `UIXSF-GUESTCOPY-REG` | **F-346** — one line per UI `.xsf` open, recording that the guest's own whole-container copy is at `buf` with `size` (keyed by the package offset its path names). It is the precondition for the comparator below: if this prints 0, `UIXSF-GUESTCOPY` cannot print anything and its zero means nothing. |
| `PATHB-HOSTDECODE-CHAIN` | **F-354** — every distinct destination the guest requests for a UI package, with its room AND the guest's own inflate record (`inLeft inPtr consumed exp outLeft produced`) at that moment. It is what bounded the objective: **each of the four containers receives exactly two destinations** (262,144–393,216 B), unchanged at 300 s, so a container larger than that budget cannot be made resident by placement at all. Also the instrument that exposes record re-use: a garage request arriving with `exp=19337` (policecam's size) and `inPtr` on the stack means the shared record was taken by another container. Capped at 24 destinations per package. | | `UIXSF-GUESTCOPY` | **F-346** — `src/gpu_device.cpp:517`, log-only. Compares the window just read out of `xarchive_cache.rpf` against the guest's in-memory copy of the same container at the same package offset: `pkg= walk= cmp= diff= firstdiff= match= ours_at_first= guest_at_first= guest_head= guest_buf= guest_size=`. Capped at 6 lines per package (a capped zero here means the package was never served, not that it mismatched). **Result: `match=1` everywhere**, which is what closed serve content as a cause of the UI inflate gap. `guest_head` is the guard against reading a recycled buffer as a mismatch. |
| `PATHB-HOSTDECODE-CHUNK` | **F-350** — one line per chunk as Path A places an oversized container across the guest's own destination chain: `dest= pkg= wrote= placed=/goldsize room= claims= present= final=`. **`present=` is a readback of every claim from guest memory compared to the decoded body**, so it survives the F-308 trap (a marker echoing its own write is not a measurement). `PATHB-HOSTDECODE-CHUNK-DONE` = the whole body is already placed, `-CAP` = 64 dests reached (the chain is not advancing). |
| `PATHB-ENQ-EXTRA` | **F-357** — one line per *repeat* `sub_821FDD50` enqueue of an already-requested container, printed only while `kUiXsfMultiEnqueue` is on (now **false**, the mechanism is closed). `pass= pkg= unc= prim= ret= out=[… …]`: `prim=` is the destination the primary call stored in its out slot, read **before** any repeat runs, so a hook that reuses that slot cannot hide it. Measured result: `ret=00000000 out=[00000000 00000000]` with `prim=B7AC1000` = the loader refuses and invents nothing (F-354's ceiling is not request-side). |
| `F358-TITLE-INIT` / `-POST` | **F-358** — log-only census hook on the title's own init body `sub_82135150` (`src/task_dispatch_trace.cpp`): `lr= r1= r3= r13=` on entry, `r3=` after the passthrough. Cap prints the first 8, so any count ≤8 is complete. Measured: fires **once**, returns **1** — the guest does reach title init, so anything downstream of it that never happened is a consumer problem, not an init problem. |
| `F358-821873E8-ALIVE` | **F-358** — the alive-path counter inside `PPC_FUNC(sub_821873E8)` (`src/gpu_device.cpp:2059`): `#<alive> of <hits> hits r13= tlsTable= slot12= lr=`. It exists because that hook has only two exits and the *other* one carries the host's sole dispatch of the UI-load gate `sub_82131008`, whose printers (`FIX-821873E8`, `W35-BOOT-GATE`) read 0. Measured: every hit takes the alive exit with `slot12=82830B18` → the gate dispatch is unreachable, not pending. Cap first 8. |
| `F360-REGCB` / `-POST` | **F-360** — log-only census on `sub_82131508`, the function that **registers** the UI-load callback: at guest `0x821315F4` it forms `0x82131008` with `lis`+`addi` and passes it to `sub_821C2FD8(&stack_out, fn)`, then `sub_82305690(r30, result, 0)` (`ppc_recomp.0.cpp:3616-3633`). Prints `#n tid= lr= r3= r13= r1=` on entry and `r3=` after. Measured: entered **once** per boot (`lr=82131B5C`), and **`-POST` never prints** — which is *not* proof of a hang: this code family returns via `JUMPOUT` tail jumps that bypass a hook's post-call code, and the same `tid` is seen active 2.5 s later in `PUSH sub_821BC868`. Use it as "reached", never as "did not finish". Cap first 8. |
| `F361-BOOTOBJ` | **F-361** — read-only check of the boot object the UI-load callback would be registered into: `[0x8288B9E8]`, then `obj+88..+104`, printed at the `PATHB2` site so it is independent of the registering function's own hook. `sub_82305690` copies a 20-byte descriptor there with the function pointer at **+92**, so `got+92=00000000` means the registration never landed. Measured: all four samples zero while `F360-REGCB` shows the registering function entered and the byte at `obj+4` is 0 (the copier's "already initialised" escape ruled out) — which localises the failure to **inside `sub_82131508`, before guest `0x821315F4`**. Cap first 4. |
| `F364-ALLOC` | **F-363** — lr-filtered probes (`lr ∈ [0x822C2EA8,0x822C3000)`) on the inside of `sub_822C2EA8`: `ALLOCFN`(`sub_821BD3C8`), `SINGLE1`, `CONVERGE`, `PRECOND`, `SIDE-A`/`SIDE-B` (mutually exclusive arms of a two-way test). Prints `ENTER ret= tid= r3= r4= r5=` and `RETURN r3=`. Measured: the 17,000-byte request **succeeds** (`r3=C9AA4A00`), so a host allocation limit is not the blocker; the sequence runs to `SIDE-A` and then into the descriptor builder. Caps first 8. |
| `F365-COPIER` | **F-363** — the decisive one. `sub_82305690` returns 1 in r3, so its object pointer must be captured *before* the call; this probe does that and reads `obj+88/+92/+104` on both sides. Measured: `desc[+4]=821FC008`, `before obj+92=00000000` → `AFTER obj+92=821FC008 obj+104=00000001`. That proves the registration machinery works in our build, and that `F361-BOOTOBJ`'s zeros are an *early* sample rather than an absence. Cap first 8. |
| `F362-SEQ` | **F-362** — four lr-filtered probes on the internal calls of `sub_82131508` (`F362_PROBE` in `src/task_dispatch_trace.cpp`): A `sub_82322C78`, B `sub_822C4EB8`, C `sub_822E5B00` (the call right before the registration), D `sub_821C2FD8` (the descriptor builder). Each prints `ENTER`/`RETURN` with its return address. The `lr ∈ [0x82131508,0x8213178C)` filter is what keeps hot callees from flooding it, so a line means "called from inside that function". Measured: A enters **and returns**; B, C, D never appear — which bounds the UI-load bypass to `0x8213152C..` the next call site, and rules out both a hang inside A and an overwritten registration (F-361). Caps first 8. |
| `UIXSF-LAYOUT-AUDIT` | **F-352** — log-only, once per package. For each slot of the anchor's own readlist it compares guest memory against the decoded container at BOTH candidate offsets — sequential continuation (`modelA`) and `vbase - anchorVbase` (`modelB`) — and prints per-slot match counts plus a total `winner=`. Because F-320 established `vbase(k+1)==vbase(k)+size(k)`, the models coincide inside a table and `TIE` is the expected, informative answer; a non-TIE would mean a size gap or a block jump. A zero here means the inventory has no slot at the anchor, not that placement failed. |
| `XMEM-SRCHEAD` | **F-346** — the first 4 big-endian words at the `src` the guest is about to inflate from, plus its `srcSz`, inside `PPC_FUNC(sub_8244FF20)` (`src/gpu_device.cpp:3169`). 12 lines, only when `srcSz >= 16`. This is the marker that distinguishes "a stream that begins with its own preamble" (`0FF512EF` / `05435352`) from a mid-stream continuation, and it settled `*srcSize(out)` = **bytes consumed** (`src` advances by exactly it). |
**Filtering `soak_census.py` output (F-353 — this cost a false neutrality claim).** A
flagged row (non-zero delta) is printed as `MARKER NEW BASE +N <<`, i.e. **6 whitespace
fields, while a `+0` row has 4.** So `awk 'NF==4 && $4!="+0"'` returns nothing *always* and
must never be used to argue "no marker differs"; the correct form is
`awk 'NF>=5 && $4!="+0"'`. Cite a neutrality claim only with (a) the corrected filter,
(b) the structural/fault markers named with their counts (`C0000005`, `C0000003`,
`Fatal error`, `FATAL-SOFT`, `VEH`, `FENCE`, `TASKJOIN`, `REBASE-POISON`, `P10-PRE`,
`DISCCHK`, `LISTLINE`, `GFx`, `W34-GFX-CENSUS`), and (c) one same-behaviour control pair
to bound the noise of any throughput marker quoted (`INFLATE`, `PUT=`, `rptrWB`,
`PRESENT` move by themselves across boots of an identical binary).

| `LZX-FRAME` | **F-332** — one line per call of the guest's per-frame LZX decode `sub_82461B98` (`generated/ppc_xenon/ppc_recomp.82.cpp:15846`), hooked at `src/gpu_device.cpp`. `S` is the decoder state base (`ctx+20`); `frameIdx` `S+11972`, `type` `S+11984` (3-bit; only 1/2/3 legal), `fsize` `S+11980` (24-bit declared frame size), `srcp` `S+11012` (input cursor), `bitbuf` `S+11952`, `cumprod` `S+11024`, and `ret` is the frame's byte count or **−1**. `failtotal` is the uncapped failure tally. **F-348 extended it with the decoder's own walk state**, read after the frame so it describes what the next frame resumes from: `stag=[base pos left]` (`S+12264/12268/12272`), `savedcur` (`S+12276`), `frameoff` (`S+12280`), `srcEnd` (`S+11016`), plus derived `inStag`/`pastEnd`. The loadable identity is `srcEnd - srcp - 4` = **input bytes the caller presented to this frame** (`sub_82461530` sets `srcEnd = src + available + 4`, `ppc_recomp.82.cpp:14906`,`:14918-14920`). Caps: first 16 frames, first 24 failures, a tally every 500 — so **its line count is a throughput artefact, not progress** (45 lines in `w335`/`w338`, 239 in `w337` on behaviour-identical binaries). **This is the first marker in the tree that can see a decompression failure at all** — everything above it reports S_OK. |
| `UIXSF-RESUME-CLEAR` / `-SKIP` | **F-333 (flag now OFF)** — fired when the refill zeroed the frame driver's per-frame resume pair (`[ctx+20+12276]` saved cursor, `[ctx+20+12280]` **byte offset inside the current frame**, not a header counter — F-332 §3) while installing a frame-aligned window, guarded on `[ctx+4]==1`. `-SKIP` means the guard rejected the ctx, so the latch was left set. Kept as the record of that intervention; it measured 63,072 → 43,732 and is OFF. |
| `UIXSF-DIVERGE` / `-SHIFT` | **F-330 — classifies WHY a guest-produced container stops, which is what decides the next fix.** At the first mismatch recorded by `UIXSF-GOLDEN-REVERIFY` it reads 32 bytes from the guest's slot, prints them against the golden's 32 bytes at the same container offset, and searches the golden over `±4 KiB`: a hit prints `IS A SHIFT` + `UIXSF-DIVERGE-SHIFT shift=K` (⇒ our slicing/alignment), a miss prints `NOT-IN-GOLDEN-NEIGHBOURHOOD` (⇒ decoder state). Those two need opposite fixes, so guessing between them costs soaks; w304 gave `at=00008000 … NOT-IN-GOLDEN-NEIGHBOURHOOD`, and the golden bytes there (`44495500`) also showed the decoded container is a sequence of 0x8000-aligned "DIU" blocks. Read-only. |
| `UIXSF-GOLDEN-FILL` / `-SUMMARY` / `-SKIP` | **F-323 — NAMED MITIGATION (`kUiXsfGoldenFill`), the `kPathBHostFullDecode` dest-write mechanism extended from one dest to a slot run.** Writes `golden[slot.vbase - anchor.vbase]` into each slot of the anchor's virtual span, where the anchor is the slot mapped to the package whose head matches golden offset 0. `gold_span=[lo,hi)` is the admissible coverage number (distinct bytes actually written). `-SKIP reason=NOT_UNTOUCHED` is the protection that keeps already-real content intact — it fired for raceeditor's slots, which share `vbase 0x50000000` with the garage's job because **vbase is per-job, not global**. w293: garage `slots_written=4 bytes_written=819200 gold_span=[0,0xC8000)` with every structural marker +0. |
| `DPC-INS-CENSUS` / `DPC-SIBLING-CENSUS` | **F-309: the DPC producer is measurably never entered** (log-only hooks in `src/gpu_device.cpp` just before the W36e block, on guest `sub_8242FD00` = the KeInsertQueueDpc-shaped ring appender, and on `sub_8242F870` as the control). `w274`: **producer 0, sibling ≥12** at ~60 Hz with `r3=40004D5C` — the boot worker's own DPC queue context — so the queue is serviced continuously and nothing ever appends to it. **Both are needed together: a zero from `DPC-INS-CENSUS` is only meaningful because the sibling proves the hook mechanism is live in that neighbourhood** (F-057(6) / F-100's positive-control rule). Reach is via the `{handler,msgid}` registry at `0x82113A90..0x82113ADC`, where `8242FD00` is paired with **msgid `0x40002204`** — NOT `0x40003B03` (that is the gate `82131008`, paired at `0x82102AC0`). **Do not re-derive this from caller counts:** `bl`/`b` scans show the running place-pass `sub_825EF100` with 1 caller and the dead `sub_822C0980` also with 1, so caller count does not discriminate here (F-309 §1). Probe is neutral: every structural marker +0 vs `w273`. |
| `FDBF8-BUILD` / `RSC-PLACE-ARR-GATE` / `REBASE-TABLE` | **container-descriptor census — and a cautionary tale: `[arr]!=0` is NOT a frontier metric** (`sub_825FDBF8` hook at `src/task_dispatch_trace.cpp:1108`, gate at `src/gpu_device.cpp:10072`, publisher at `:4074-4102`). `FDBF8-BUILD` prints the swfC container object's fields: `[obj+12]` is an entry-array **cursor** FDBF8 advances by a length, `[obj+16]` a `u16` count. **F-307 proposed "lines where `[arr]` dereferences non-zero" as the honest signal and F-308 refuted it**: in `w193`/`w248` the value was written by our own mitigation `W30-ARR-FIX` (`gpu_device.cpp:5408`) onto a `CDCDCDCD` buffer, and where it resolved 7 times `UILOAD-census`/`MOVIE-CTOR`/`nGfx` were all still **0** — exactly as in the boots where it resolved 0. **A hook on a guest function still reports host-written bytes, so before trusting any counter, grep its field names against the `Write*` calls that target the same guest offset** (and note `W30-ARR-FIX` is one of the 64 mitigation labels `tools/mitigation_audit.py` finds unregistered in §7 — F-047). `REBASE-TABLE @… n=7 (D828-form vbase/pbase/size)` proves the region table is published and correct: header `nmap<<16` → the two summed `lhz` at `8217D838`, 12-byte entries at `+4` = `8217D878`, `Invalid fixup`=0 (F-307 §1). |
| `PATHB-HOSTVERIFY` | **F-299 full-buffer residency proof for a host-decoded UI `.xsf`** (`UiDecVerifyReadback`, `src/gpu_device.cpp:4028`, called once per dest from the `D2308-buf` census site `:9681`). `want=` is the FNV-1a digest of the decoded body taken at write time (`UiDecRecordExpect`, `:365`), `got=` is the digest of `unc` bytes re-read from guest memory later in the same boot; `match=true` means the **whole** container is still byte-identical in guest memory, which `BUF-HEAD`'s 16 bytes cannot show. Log-only, one-shot per dest, and it changes no behaviour — proven zero frontier delta (`w273` vs `w271`: every structural marker +0). `read=FAIL` means the guest-memory read failed, not that the content differs. |
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
| `SHGRP-VARS` | the shader-group variable binder `sub_82193AF8(group,name,required)` (`src/gpu_device.cpp:17059`-ff, the `:12395` in this row's old text is pre-F-369): group, its vtable/array/`lhz [group+12]` count, the wanted name as ASCII and the first two entries' names. Raised the `Required grmShaderGroupVar '%s' not found.` fatal that is the frontier in w147-w154 (F-142…F-144) and the park that F-368/F-369 removed. Read-only, cap 80 |
| `F369-SHGRP-SOFT` | the same hook, one line per lookup whose `required` flag the host cleared (`src/gpu_device.cpp:17135`), printing `want=`, `group=`, `req=1 -> 0` and the caller `lr`. Its appearance means the guest's shader-var fatal was avoided; its ABSENCE while `SHGRP-VARS req=1` prints would mean the mitigation silently stopped working. Cap first 16 then every 200 (F-369, `w373`: 2 rows) |
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
| `XSF-LZX` / `XSF-LZX-FAIL` | F-188 Path A: host libmspack LZX expand of an RSC5+XCompress UI package inside `HostServeUiBody` (`MclaHostXcDecodePackage`). Success emits `XSF-LZX pkgSz=… wantOut=… produced=… frames=…`; total failure emits `XSF-LZX-FAIL`. **`XSF-LZX >= 4` with `W34-NOGFX` falling is the Path A pass signal.** Lists never take this path (they stay DEFLATE/`RawInflate`) |
| `REQFILL sub_821867A0` | F-173, corrected by F-174: one line per call to a guest 28-byte streamer-request **builder** (`src/gpu_device.cpp:8418`-ff, registers-only, cap `n <= 24 || n % 2000`). It fires **twice per boot**, returns slot ids 3 and 4, has exactly ONE caller (`sub_82187150+0x1A8`), and its only non-pointer argument (`r5`) is 0 both times. **It is NOT the writer of the pool `sub_821BC140` reads** - its destination array is the caller's own `r1+224 + idx*28` - so do not cite it as the origin of the zero inflate length. Keep this hook register-only: a census in this subsystem once AV'd its consumer by reading guest memory (`ENQ sub_821BCB10` note)|
| `INFLATE-ENTER` / `READWRAP` | the two lines that together diagnose the inflate door: `INFLATE-ENTER st= in= inPtr= consumed= outPtr= lr=` (our `sub_821D5E10` hook, `src/gpu_device.cpp:7067`-ff) and `READWRAP sub_821CC6F0 r3= r4=[4 words] r5= r6= r7= ret= r1in= lr=` (`:10276`-ff, the packfile device's Read wrapper). `lr=821BC334` on a READWRAP line means the read came from the streamer's inflate loop; **`r7=0` there is the F-172 finding**. `st+0 = 0xFFFFFFF4` with `st+4 = stack+12` is what a zero-byte read produces after the guest's own priming arithmetic - do not read those as real sizes
| `STREAM-OPEN sub_821BCE68` | F-177: one line per `pgStreamer::Open` (registers-only, cap `n <= 24 || n % 500`). **7 firings per boot**, returning handle ids `0,1,2,3,4,0x8004,0x10004`; `r5` is the value read from `RSC5+0x04` (27/9/5442), and Open stores `dev->vtable[+84](dev)` into `record+4` - the length `sub_821BC140` later reads. Pair it with `REQDUMP d[0]` / `ENQ a0` to see which three requests actually execute. The `memory:` device's `+84` is the shared `li r3,0` stub (`0x821A5CC0`, which we force to 0 at `src/gpu_device.cpp:12642`-ff), so a zero length there is ours, not the archive's |
| `STUB-SLOT` / `STUB-SLOT-TALLY` | per-`lr` tally inside the shared no-op vtable stub `sub_821A5CC0` (`li r3,0; blr`, thirteen slots of `0x82012918` point at it; we override it at `src/gpu_device.cpp:12642`-ff). One line per newly-seen `lr` (max 16) + the first 12 calls. w186: **four** callers per boot - `8217784C`, `8218C82C` (the device+88 case the override exists for), `821BE67C`, and the hot `82177EF8`. Any vtable slot you implement must be checked against this list, because those thirteen slots are indistinguishable by address (F-178) |
| **Hazard: `INFLATE-ENTER` and `READWRAP` count a timed spin** | their totals depend on how many iterations fit in the soak timeout, so a logging footprint moves them without any change in guest progress (`w185`→`w186`: 149→82 and 278→138 with all 17 structural counters identical). They are not admissibility evidence and not progress evidence - use `LISTLINE`/`TYPINIT`/`GETDEV`/`CP-DRAW`/`PRESENT`/`DRAW_INDEXED`/`C0000005`/`SEEK-DEAD`/`Fatal error`/`FATAL-SOFT`/`DICTLOOKUP`/`[error]` instead (F-178) |
| `BC140-REC` | F-180: the 28-byte streamer record `sub_821BC140` actually indexes, read before its body runs (`n <= 8`, all reads checked; INLINE-EXEC fires 3x/boot so it is free). `base = [[0x8283D190+52]]`, `rec = base + ([slot+0] & (cap-1))*28` with `cap = [0x8283D190+24]` = 0x8000. Layout: `{+0 index|generation<<15, +4 BYTE COUNT, +8 device, +12 flag, +16 package ID, +20 entry offset, +24 package offset}`. w187: the count is 240,531 and 10,799 for two generations and **0 for the legals one** - that zero is what makes the inflate read 0 bytes (F-172) |
| `PARK-UNWIND` | F-394: `src/boot_host.cpp:1536-1580` `ParkUnwindCapture` + its print at `:1951`. The honest replacement for `PARK-SAMPLE nf=`: `RtlLookupFunctionEntry` + `RtlVirtualUnwind` on the suspended boot worker, printing **module RVAs** (`owner=<entry_rva>+<off>`, `rip=[f0,f1,…]`) because this build has no PDB and `NearestFunctionName` was ~94 KB off. Print cap `pu<=12 || pu%40==0`. Resolve with `python tools/host_rva_resolve.py build/mcla.map <rva>…` using the load base from that soak's own `PARK-SAMPLE base=` line. `frames=0` = no table entry for the RIP; `frames=1` = lookup fine, first unwind produced no advance (now recorded, so this should be rare); both are results, not silence. | 17 (`w411`, 120 s), 25 (`w412`, 300 s) |
| `kF406SkipFabricatedServe` | `src/gpu_device.cpp:1086` (flag), `:11292-11305` (gate) | **FIX, IN TREE AND VALIDATED 2/2 soaks (F-406).** Skips the host inflate-record write for a dest with **no stream-owned package** (`MclaUiXsfStreamPkg(st, outPtr) == 0`) — i.e. exactly the 4 KiB filler packages `AssignPackageForDest` invents (`0x1284000..0x1295000` in `w406`), which F-393 proved lock `sub_821BC140`'s inflate leg. The containers keep being served (`INFLATE-HOSTSERVE-PEND` 3 rows: `64980000`, `64CA3000`, `6496F000`). Effect: `BC140-REC` 3 -> **5** (new readlists `8284AD68 RLC=4`, `8284B37C RLC=7`), garage `still_present` flat at 917,504, `C0000005` 4, `LISTLINE` 171. **Not** F-393's predicate: `IsUiXsfPkg(AssignPackageForDest(...))` was false for the garage dest too and cost it 774 KB — read F-393 alongside F-406. | 5 records (`w418`, `w419`) |
| `F406-SERVE-SKIP` | fires once per skipped fabricated serve; cap `k <= 16 || k % 256 == 0` **so a low row count is the cap, not the volume** (F-406). Prints `st/outPtr/outLeft/guessPkg/lr/tid`. | 16 (`w418`/`w419`) |
| `F409-FILL-GUARD` | F-410: replaces the merged `UIXSF-GOLDEN-FILL-SKIP reason=PROTECTED(claimed_or_golden)` string, which could not distinguish a foreign claim from an already-correct slot. Prints `pkg/slot/vbase/goldoff/size/reason/claimPkg/claimVerified` with `reason` one of `CLAIMED_OTHER_VERIFIED`, `CLAIMED_OTHER_UNVERIFIED`, `GOLDEN_ALREADY_PRESENT` (code `src/gpu_device.cpp:9467-9519`, `UiDecExpect` at `:358-363`). Cap `k <= 24 || k % 64 == 0` — a row count is the cap, not the volume. **The F-408 slot-aliasing theory died here: `w423` printed `GOLDEN_ALREADY_PRESENT claimPkg=00000000` on all five refusals.** | 5 (`w423`) |
| `F447-REFILL` | F-447: one row per config-stream refill (`sub_821BE4F0`, called when the tokenizer's buffer is exhausted). Prints `obj`, `got` (byte value, or -1 = the 1-byte read returned nothing), a cumulative `eof` tally, `lr`, `tid`. `w450`: ~1,024 calls, `eof` 684, the -1s on `0x82860C40/0x82860C68` while the sibling `0x82860C18` reads real delimiter bytes — that contrast is the control. Cap `k <= 64 || k % 512 == 0`, so the counters not the rows are the quantity | 105 rows / eof 684 (`w450`) |
| `F442-SECTION` | F-443: one row per config-section lookup (`sub_821CFF40`), printing the queried name, the container's vptr/vtable slots, `ret` and a running `hits` tally. **`w445` = 14 rows, all `ret=0`, `hits=0`** — five consumers (`shadinggroup`/`Manufacturer`/`Vehicle`/`sample`/`City`) all query an empty stack container, which is why clause (b) is ordering/parse and not content. Cap `k <= 200 || k % 1000 == 0`, so 14 is the true boot total | 14 (`w444`, `w445`) |
| `F456-STREAMID` | F-456: one row per config-section lookup, printed from the same `sub_821CFF40` hook as `F442-SECTION`, giving the **reader object's own identity fields**: `dev`/`handle` at `[inner+0]/[+4]` (the convention `sub_821BE610` uses), the buffer `base`, `pos`/`len`, the eight words at `[inner+0x30..+0x4C]`, and any of them that dereferences to a printable string. `w457` = **14 rows, every one `dev=C64AC100 handle=00000000 base=82861DF8`**, which refuted F-455's `h=0` lead (the four `shadinggroup` rows hold correct text); compare with `BE250-SLOT`, which serves the same object as `h=1`. Cap `k <= 40`, so 14 is the true boot total | 14 (`w457`) |
| `F457-MEMBLK` | F-457: one row per `memory:$` re-open the guest itself composes (printed at the `sub_821BE0C8` site, next to `BE0C8`/`BE0C8-RET`), dumping the wrapped block's 32-byte head in hex + ASCII with the full `pth`, so a block's container type and origin file are readable. `w460` = 81 rows: **0 RSC5/XMem heads, 0 tune paths**, and the only plaintext head is a mid-token shaders-list tail — this is what closed the Path A extension to config text. Cap `n <= 80 || n % 100 == 0` | 81 (`w460`) |
| `POST-EXEC-START` | printed immediately after `__imp__sub_821BC140(ctx, base)` (`src/gpu_device.cpp:12826-12850`) with the pre-call slot snapshot, so it is the exit half of the dispatch bracket. Fields since F-471/F-472/F-474: `pre=<ms>` = OUR host work inside the hook before the guest body (0 ms on all four UI jobs), `guest=<ms>` = the title's own `sub_821BC140` (21-1,662 ms), `rlcAfter`/`cbAfter` = the job slot's `[+1540]` read-list count and `[+1548]` callback re-read after the body (`rlcAfter` matching the pre-call `RLC` is what excluded the count-0 branch in F-474). Pair it with `BC140-REC` for entry and `RELSEMA … lr=821BC538` for the completion callback — 7 rows/boot, uncapped | 7 (`w480`) |
| `F469-RECSNAP` | F-469: one row per streamer queue push, printed read-only from `PPC_FUNC(sub_821BC868)` (`src/gpu_device.cpp:13853-13878`) just before the `PUSH` line, dumping records 0..5 of the array at `[0x8283D190+52]` as `[idx id/+4 length/+24 pkgoff]`. It is the instrument that settled the F-186 enqueue question: `[slot+0]` (printed as `tag`) is a **handle = `(gen << 15) | record_index`**, every push stamps both index `tag&0x7FFF` and index `tag&0x7FFF − 1`, and re-stamping happens 22-30 ms after creation — before most jobs dispatch. 7 rows/boot, uncapped, no guest write | 7 (`w475`) |
| `F441-QUEUE-STORE` | F-441: store-watch on the title boot-worker queue `0x40004B40..0x40004DC0` (`src/gpu_cp.cpp:2169-2188`, armed `src/boot_host.cpp:1850-1853`). `w441` = 45 rows, **all value 0, all lr=8241356C** = the return after `bl 0x823d9890` (a memset), i.e. object construction only — no post ever happens. Cap `n <= 32 || n % 500 == 0` | 45 (`w441`) |
| `F440-REGREAD` | F-440: read-watch on the whole `{handler, msgid}` registry `0x82102AA0..0x82118000` (`src/gpu_cp.cpp:2180-2198`, armed `src/boot_host.cpp:1841-1848`); prints `@addr -> value lr`. **`w440`: 0 rows**, while the same path logged 8 guest-attributed `PAGEWATCH R` rows from other ranges — that pairing is the control that makes the zero mean "never read", not "probe dead". Cap `n <= 24 || n % 500 == 0` | 0 (`w440`) |
| `F438-GFXCTOR` | F-438: one row per **construction** of a GFx loader object (`sub_824C6F08`, the only routine that installs the loader vtable pair). It exists because `nGfx` never counted them (F-437): read `obj/vt0/vt672/movie` + the caller `lr` captured before the call. Cap `k <= 16 || k % 64 == 0`. **A zero here is the first falsifiable statement the project has had about GFx objects existing** — the old scan could not have found one even if it did | 0 (`w435`, normal boot), **1 (`w436`, control with the host gate on)** — the control is what makes the zero mean something |
| `F434-SPIN-BREAK` | F-434: one row per guest no-progress inflate spin it drains (`st/outPtr/inLeft/outLeft/consumed/magic`). **Uncapped, and the count is the quantity: `w432` = 1 row.** A rising count means a *new* stream is starving, which is a different bug than the one this fixed | 1 (`w432`) |
| `F432-GROW-SKIP` | F-433: one row per `sub_82397060` entry with `r4 == 0` that is returned from without executing (gate `src/gpu_device.cpp:17519-17525`). **Uncapped on purpose** — the whole boot produced 3 rows in `w431`, and the count IS the quantity: it says how many degenerate grow calls the boot worker reached, which is the clearest available signal that the worker got further than the store storm used to let it | 3 (`w431`), 0 (`w430`, flag off) |
| `F393-SERVE-SKIP` | F-393: fires once per `inLeft == 0` entry on a dest whose assigned package is not a UI .xsf container, **only while `kF393NoHijackNonUi` is true** (it is false now, so a zero is the expected reading, not a broken probe — print cap is `k <= 32 || k % 512 == 0`). Its purpose was to prove the host serve, not the guest, was holding `sub_821BC140`: with it on, `INFLATE-ENTER`'s max serial fell 6,747,400 -> 231,518 and `READWRAP` rose 1,742 -> 463,018, while `INFLATE-HOSTSERVE-PEND` went 25 -> 0 | 484 (`w407`), 0 (`w408`) |
| `F382-MEMCPY` / `F379-HEAPSTORE-BT` | F-379..F-383: the two lines that named our own Path A driver as the writer of the host heap header. `F382-MEMCPY` prints the *real* `dst/src/len/lr/sp` of any guest copy whose span crosses `0x20000..0x20240`, read off the context in play (the hook's own `ctx`, not `GetPPCContext()`, which is a different context whenever the guest is driven from host code). `F379-HEAPSTORE-BT` prints the host return-address chain as RVAs; name them with `python tools/host_rva_resolve.py build/mcla.map <rva>...`. Always pair with `F382-MEMCPY-LIVE` before believing a zero (`w392` printed 0 rows because the filter tested the base, not the span) |
| `VECTORED exception code=0x406D1388` | benign Windows SetThreadName exception from host code — not guest |

## 10. RE tooling

- **IDA MCP** on `127.0.0.1:8745`. **Two ways in, and the safe one is usually not the configured one.**
  **F-350 SUPERSEDES the rest of this bullet — three facts, now all implemented in
  `tools/ida_rpc.py`.** (a) Analyze **`build/cache/mcla_pe.bin`**, *not*
  `build/game_data/default.xex`: on the .xex the loader dies with
  `RuntimeError: failed to analyze input file` (verified 09-26 11:04). The working database
  answers `get_metadata` with `base 0x82000000 size 0xad3000 md5 3f2510c1…`.
  (b) **`ida-pro-mcp.exe --transport stdio` is a dead end** — it forwards `tools/call` without
  the `Accept` pair and the server replies `-32600 Not Acceptable`; `tools/list` succeeds, which
  is what makes it look alive. (c) The JSON-RPC answer is streamed back as **SSE on the same
  response**, so `read()` yields an empty string and looks like a broken server — read lines
  until a `data:` payload.
  Start when nothing is listening (`tasklist | grep -i idalib` first, rule 11):
  `"C:/Users/abdul/.local/share/mcp/idamcp-venv/Scripts/idalib-mcp.exe" -v "E:/mcla pc/build/cache/mcla_pe.bin"`,
  then `python tools/ida_rpc.py list` (48 tools) ·
  `python tools/ida_rpc.py call decompile_function '{"address":"0x821BC140"}'` ·
  `call get_xrefs_to '{"address":"0x82461378"}'`. Verified end to end 09-26 11:11.
  `ida-bridge.py` also runs `taskkill /F /IM idalib-mcp.exe`, so never start it against a live
  server. The old instructions below are kept as trail.
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
