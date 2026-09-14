# MCLA-PC PROGRAM GUIDE — doc 1 of 5

Everything an agent needs to work on this repo without re-deriving it: what the
program is, how it is built and run, the guest/host architecture, the census
instrumentation, the address cheat-sheet, and the rules that govern all work.
Live status and history live in the other four docs (see map below).

**Reading order for the 5-doc set:**

| # | Doc | Contains |
|---|-----|----------|
| 1 | `docs/PROGRAM_GUIDE.md` (this) | Stable program knowledge: architecture, build/run, tooling, rules, cheat sheets |
| 2 | `docs/HANDOFF_NEXT_AGENT.md` | Live frontier (top READ-ME-FIRST blocks) + the full chronological session trail, newest first |
| 3 | `docs/ROOT_CAUSE_VALIDATION.md` | The root-cause audit: method (Part 1), report (Part 2), append-only findings ledger F-001… (Part 3) |
| 4 | `docs/EXECUTION_PHASES.md` | Executor protocol (Part A) + Phase 0 and Phase 1 task briefs and run logs |
| 5 | `docs/PLAN_VMX128.md` | VMX128 pack/unpack plan: semantics resolved, Route A (type-2 pack) landed, remaining ops open |

The public pitch also lives in the root `README.md`. `docs/` is gitignored
(`.gitignore:9`) — force-add (`git add -f`) any doc that must survive
`git clean -xdf`; docs have been lost this way before.

**Former filenames** (older text in the trail may still cite them):

| Was | Now |
|---|---|
| `ROOT_CAUSE_VALIDATION_PLAN.md` / `_REPORT.md` / `_FINDINGS.md` | `ROOT_CAUSE_VALIDATION.md` Parts 1 / 2 / 3 |
| `CHEAP_MODEL_EXECUTION_PLAN.md` | `EXECUTION_PHASES.md` Part A |
| `PHASE0_IMPLEMENTATION_SUBPLAN.md` / `PHASE0_EXECUTION_TASK.md` / `PHASE0_EXECUTION_LOG.md` | `EXECUTION_PHASES.md` Phase 0 |
| `PHASE1_EXECUTION_TASK.md` / `PHASE1_EXECUTION_LOG.md` | `EXECUTION_PHASES.md` Phase 1 |

Files cited in historical notes that no longer exist on disk (lost to the
gitignore before being force-added): `docs/BOOT_HANDOFF.md`,
`docs/MCLA_RPF3_Technical_Reference.txt`, `docs/MCLA_REBUILD_PLAN.md`,
`docs/CODEGEN_REPAIR_SUBPLAN.md` (never produced — codegen was cleared).
Their load-bearing facts were folded into this set.

Reading the handoff trail: it is append-only, newest at top, with superseded
blocks kept for context. Later blocks overturn earlier claims (e.g. session 75u
retracts 75r/75s/75t; ledger finding F-023 overturns the "stale lr" claim).
When two statements conflict, the higher/newer one wins.

---

## 1. What this program is

A **native D3D12 renderer rebuild for Midnight Club: LA** (Xbox 360). The
recompiled PPC game code runs untouched as native C++ on the PC; render intent
is captured at the high-level draw boundary and replayed as real D3D12 instead
of emulating the Xenos command processor. Not rexglue-based: no emulation
layer, no SDK wrapper — the game recompiles to native C++ and runs as native
code. Legal: zero game code or assets in the repo; the toolchain consumes a
legally dumped user copy (`build/game_data/`, XEX → `build/cache/mcla_pe.bin`).

What exists: standalone boot host linking the full recompiled image (44,707
function mappings), Xenos shader decode → IR → DXIL translation pipeline, D3D12
backend with PSO cache, device-method capture hooks, render thread owning all
D3D12, offline validators. The live boot frontier moves session to session — always read the
handoff top READ-ME-FIRST block for the current state.

## 2. Repo layout

- `src/kernel`, `src/cpu`, `src/apu`, `src/user` — kernel framework + guest runtime
- `src/renderer` — xenos decode, shader translation (IR→DXIL), texture/vertex decoding, pipeline/resource caches
- `src/` root — boot host (`boot_host.cpp`), device-boundary hooks (`gpu_device.cpp`, `gpu_cp.cpp`, `patches.cpp`, `task_dispatch_trace.cpp`), D3D12 backend, render thread/queue, VFS (`vfs_rpf.cpp`)
- `src/kernel/imports.cpp` — Xbox kernel import implementations (Nt*, Ke*, Xam*)
- `src/kernel/heap.cpp` / `o1heap.c` — physical allocator + SEH wrappers
- `src/dispatch_guard.cpp`, `src/vmx128_pack.cpp` — host sides of midasm hooks
- `generated/ppc_xenon/` — recompiler output (176 TUs + `ppc_func_mapping.cpp`). **Input only, never edited by hand.**
- `config/mcla_xenonrecomp.toml` — canonical recompiler config (incl. `[[midasm_hook]]` entries)
- `.research/XenonRecomp` — the vendored recompiler tool (**gitignored** — commit any patch as a `.patch` in `tools/` or docs)
- `build/` — caches, boot logs (`boot_stdout_*.log`), scratch regens (`build/xr_*`), `build/cache/mcla_pe.bin` (the guest image)
- `third_party/` — SDL3, fmt, spdlog, toml++, dxc, o1heap, xxhash
- `tools/` — helper scripts (`start_idalib_mcp.ps1`, fix_stubs_iter.py, fix_stubs_self.py)

## 3. How to build & run

```bat
:: build (Git Bash on Windows — the MSYS vars are REQUIRED, plain `cmd.exe /c` silently no-ops)
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat

:: kill leftover instance before linking (a running exe locks the link output)
cmd.exe /c "taskkill /F /IM mcla.exe"

:: boot soak with a NEW log name every run (never overwrite 78 / 76y); note the exit code
timeout 120 ./build/mcla.exe > build/boot_stdout_XY.log 2> build/boot_stderr_XY.log
```

Requirements: VS 2022 buildtools (vcvars64), CMake 3.25+, Ninja, clang-cl for
C and C++ (`configure.bat`, then `ninja_build.bat`; delete `build/` when
switching compilers).

Environment gotchas that cost real time:

- `cmd.exe /c foo.bat` from Git Bash path-converts `/c` → use the MSYS vars above.
- `taskkill //F //IM mcla.exe` fails (the tool treats `//` as a UNC path) — go
  through `cmd.exe /c "taskkill /F /IM mcla.exe"`. Same for `grep "// pattern"`.
- The shell `grep` is **ugrep**: a pattern starting with `-` needs `grep -e "-pat"`.
- `build/game_data/mcla extracted cache/` must EXIST (empty is enough) or
  `app.cpp:90` skips `vfs.Initialize` and every `game:\*.rpf` open fails
  (`Cannot load archive 'game:/xarchive_audlo.rpf'` fatal at boot).
- Stale-exe trap: after a failed link, verify `build/mcla.exe` timestamp before
  soaking — two sessions chased ghosts on an old binary. Taskkill before linking.
- Build rule: never build while an old mcla.exe is running.

## 4. The guest image

`build/cache/mcla_pe.bin` is the shipped XEX as an **identity-mapped memory
image**: `file offset = VA − 0x82000000`. Image base `0x82000000`, size
`0x9E0000`, code base `0x82130000` (`src/ppc_config.h`). Instruction words are
**big-endian**. The PE *section table* lies (it claims `.text` PRD `0x12C800`
for VA `0x82130000`; following it lands in zeros) — always use the
identity-mapping offset, e.g. guest `0x8226B450` ↔ file `0x26B450`.

**Raw-byte rule (ledger F-023):** IDA on this raw bin has produced misaligned
disassembly and fictional xrefs (session 75o: IDA claimed 30 callers of
`sub_821E5F48`; a raw bl-scan found 4). Every IDA claim (boundary, branch
target, xref) must be verified against the raw file bytes before acting on it
or citing it. Generated TUs are the other ground truth.

## 5. Recompiler pipeline (XenonRecomp)

- The recompiler tool: `.research/XenonRecomp/build-clang/XenonRecomp/XenonRecomp.exe`
  (exists; rebuild via `.research/XenonRecomp/rebuild_clang.bat`; verify the
  built exe contains the string `JTS-TAILCALL` — a session-78 tool patch that
  makes out-of-span switch-case labels emit tail calls).
- Invocation: run from the **repo root** with the config as a **bare filename**
  (`cp config/mcla_xenonrecomp.toml .` first). A path like `config/...` fails
  SILENTLY (exit 127, empty log) — `recompiler_config.cpp:5` derives the
  relative-path root from the config path, and any separator breaks it.
  Second arg is the context header: `src/ppc_context.h`.
- `src/ppc_context.h` is reconstructed from generated output:
  `tail -n +4 generated/ppc_xenon/ppc_context.h > src/ppc_context.h`
  (round-trip `cmp`-clean; the reconstructed file begins with its own
  `#pragma once`/`#include "ppc_config.h"` — the duplication is faithful).
- Canonical config `config/mcla_xenonrecomp.toml` emits **176 TUs**
  (`ppc_recomp.0..175.cpp`) into `generated/ppc_xenon`. **If you regenerate,
  re-check the TU count against CMakeLists or the build breaks.**
  `config/mcla_xenonrecomp_baseline.toml` (out → `build/xr_baseline`) exists
  for the reproducibility gate.
- **Reproducibility gate before any regen:** run the unmodified tool into a
  scratch out dir and `diff -r` against `generated/ppc_xenon`. If not
  byte-identical (minus known deltas), do NOT regenerate.
- Post-regen checklist (proven in session 78): per-function body diff vs the
  committed tree; stub census (below); boot soak comparing steady-state
  counters (TSLAB-ALLOC ~2125, PARAM-STORE 401, EVENT-CREATE 256).
- The hand-edited **dispatch guard** lives as `src/dispatch_guard.cpp` +
  `[[midasm_hook]]` at `0x8218CC94` in the canonical config (dispatcher
  trampoline `sub_8218CC70` ends in `bctr` through a function-pointer table; a
  NULL/unmapped slot = hard crash). Any regen would silently drop a hand edit
  of generated output — that is why it is a config hook now.
- Broken-stub census (both emitted forms — the old recipe missed 162):
  `grep -hoE 'ERROR:? *0?x?[0-9A-Fa-f]{8}' generated/ppc_xenon/ppc_recomp.*.cpp`
  State as of session 78: **0 broken stubs** (was 1719). Session-78 note:
  44,707 mapping entries, 0 without bodies (link-safe); 33% of functions are
  `.long 0x0` stubs (never-executed code — not a defect, F-022).
- `.research/` and `generated/` are both **gitignored** — any tool patch must
  be committed as a `.patch` file (copy into `tools/` or docs) or the work is
  lost on the next clone.
- Helper scripts: `tools/fix_stubs_iter.py` (parent-extension spans) and
  `tools/fix_stubs_self.py` (self-spans) — the fixed-point loops that grew the
  span set in the canonical TOML.

## 6. Host runtime architecture

- **Boot:** `src/boot_host.cpp` loads the image, installs host hooks, starts
  guest threads (`GuestThread::Start`). Guest PPC runs from `generated/ppc_xenon`.
- **Hooks:** one owner per guest address (Golden Rule 1) via `PPC_FUNC` /
  `GUEST_FUNCTION_HOOK` / dispatcher `SetFunction`. Always check for an
  existing owner before adding another; a regen registers mapping entries for
  everything, so host overrides are strong symbols replacing weak generated ones.
- **Guest memory:** `mcla::kernel::GuestMemoryHeap` with checked big-endian
  accessors; `WriteGuestU32` → `GuestMemoryView` (page-watch capable).
  Watches (`RegisterGuestWatchRange/Value`) + `PageWatchOnWrite` power the
  PHYS-OVERRUN / CDCD-FILL censuses.
- **Host→guest calls:** `GuestToHostFunction` (`src/kernel/function.h:311`)
  builds `newCtx` copying ONLY `r1/r13/fpscr` — guest callbacks invoked this
  way start with whatever lr/r14–r31 the host thread last had. Known and
  considered, but remember it when a callback context looks impossible.
- **Physical memory:** one `MmAllocatePhysicalMemoryEx` pool at boot → o1heap
  arena at guest VA **`0xA0000000`–`0xFFFFFFFF`** (~1.6GB, cap 1,610,612,160).
  Pool16 slabs live inside it (`A0014xxx`). `MclaPhysAllocInfo(addr, …)` /
  `MclaPhysNearestAllocBelow` (`kernel/memory.h`) attribute overruns to the
  allocating site (`s_allocLrMap`, filled by `MmTrackAllocationSize`).
- **Allocator (guest-side, fully mapped):** registry `0x82830B18`; alloc
  dispatch `sub_821C08F8` routes to `m_Allocators[(r6+1)*4]` → the
  **sysMemDualBuddyAllocator** (arenas at `B7xxxxxx`) for default allocs; the
  simple allocator (pool `A0001010..A2E81000`, ~46.5MB) serves direct callers.
  General alloc `sub_821C1BB0` (best-fit, 16 buckets, 16B headers: +0 self,
  +4 size, +8 phys-prev, +12 flags with heap-id + in-use bit, 0xCD debug
  fill); free `sub_821C2AB8` (ownership scan; frees via index i+1; **silently
  drops i==1/3**); tiny-slab `sub_821DE9D8` (size classes 4/8/16/32/64 at
  heap+208..240; **memsets every returned element with 0xCD** — see §9).
- **Critical sections:** guest guard `sub_821C8FE0` skips locking when
  `[cs+0]==0`; our `RtlInitializeCriticalSection` now writes
  `Header.Lock=0xFFFFFFFF` (allocator CS `0x82855A0C` verified locked).
- **VFS:** RPF3 archives (header `0x800`, TOC `0x1000`, 16-byte BE entries;
  `xarchive_cache.rpf` has magic at offset 0 with `0xB116A6AB` TOC-encrypt
  marker at 0x800 — guest decrypts with embedded key, which works in our emu).
  Compression is XMem LZX, not zlib. `NtReadFile` uses positional
  `ReadFileAt` (`vfs_rpf.cpp`) for real RPF handles (positional OVERLAPPED —
  two threads reading one shared-position handle raced before this fix) and
  signals async completion events. Compressed stream inflate hook:
  `sub_821D5E10` (XCompress magic `0x0FF512EF`; unknown magic → skip-fatal).
- **IO contract:** the page-cache submitter expects the Xbox async contract —
  submit → STATUS_PENDING (259) → completion finalizes the slot. Our
  NtReadFile completes synchronously; the `SLOT-READY` hook
  (`sub_821CBE18` "wait for slot": if `[slot+12]==1` write 2 before the wait)
  is the honest equivalent since the IO did complete. `DISCCHK`
  (`sub_821CC1E0`) gets bit31 ("handled/ack") set before the original runs
  when bit30 ("error/media") is set — the fatal fires *inside* the original,
  so the ack must be BEFORE `__imp__`.
- **GPU:** `gpu_device.cpp` / `gpu_cp.cpp` own the device-boundary (submit,
  streams, blits, present swap-table handshake at dev+21624/21628; completion
  processor `sub_824286A0`). Renderer side: `src/renderer/*` (shader
  translator, pipeline/resource caches, vertex decode). Present path:
  `FRAME-END` / `NATIVE-PRESENT` counters; `SignalSchedulerTick` releases a
  semaphore into the tick/dispatcher object every VSYNC.
- **Fatal dispatcher:** guest `sub_821BD618` loads `[0x8285FEA0]`, `bctrl`s
  it, loops forever. Host-overridden (`SetFunction` in `patches.cpp:441`,
  impl `imports.cpp:2818-2873`): prints message + register dump + stack
  chain, `ExitProcess(0x80000003)`. Slot value `0x82130678` is a real guest
  function (returns 0 in r3), not a pad hole (F-007).
- **Task-join table:** count @ `0x8283D1A8`, entries @ `0x8283D1C4`, stride
  28, idx = `(count-1) & tag`, wait word = `entry+12`.

## 7. Known short-circuits in tree (do not stack more without root cause)

| Hook | File | What it does |
|------|------|--------------|
| KDELAY-SC | `gpu_device.cpp` | force `pub0` when wait would spin |
| FENCE-SC + ClearTaskJoinBusy | `gpu_device.cpp` | pre-release ev + clear `entry+12` |
| TASKJOIN-SC | `gpu_device.cpp` `sub_821BD220` | main-thread force busy=0 |
| REBASE-POISON | `task_dispatch_trace.cpp` `sub_821B5A60` | zero `*param` if `0xCD` byte |
| P10-PRE | `task_dispatch_trace.cpp` | skip fatal on poison id, return 0 |
| INFLATE-SKIP / EMPTY / PENDING | `gpu_device.cpp` `sub_821D5E10` | no XCompress → emit 0 / bail / pending-retry |
| TEXCREATE-SC | `patches.cpp` `sub_82177EB0` | r3<0 → 0 (legacy RT unused) |
| SEH o1heap | `kernel/heap.cpp` `SehO1Allocate/Free/Filter` | AV → null / no-op; wrap-safe bounded dumps |
| pow2 align | `kernel/heap.cpp` AllocPhysical | round alignment up |
| NtReleaseSemaphore | `imports.cpp` | `GetKernelObject` like Wait |
| BLIT-OOB-GUARD (s74) | `gpu_device.cpp` `sub_82431A40` | skip blit when `rectW*rectH` provably exceeds the exact tracked alloc — closed the AV storm |
| SLOT-READY (s75w) | `gpu_device.cpp` `sub_821CBE18` | page-cache slot wait: flip state 1→2 when read already completed |
| DISCCHK bit31 ack (s75z) | `gpu_device.cpp` `sub_821CC1E0` | set "handled" bit before original (kills 'Fatal disc error') |
| DICT-HYDRATE (s78, commit 3c8744e) | `gpu_device.cpp` | after 10 factory entries, write them into hash table `0x82839F70` |

Wake-loss fix (create/wait/release wrapper mismatch) is a real bugfix; the rest
are boot life-support. Known poison values: `0xCDCDCDCD` = guest-native
fill-on-alloc (compiled into the shipped image — its presence means an owner
never initialized the field, NOT corruption); `0xDD` = heap free-fill;
`0xFF00FF00`/`0xFFFF00FF` = "missing texture" checkerboard texels, NOT poison.

## 8. Guest address cheat-sheet (verified across sessions)

### Shader system
| What | Where |
|---|---|
| Shader name lookup (r3=name, −1 on miss) | `sub_82189138` (ppc_recomp.9.cpp) |
| Hash helpers | `sub_821C9AB0`, `sub_821C9790` |
| Shader dict hash table (256×4B) | **`0x82839F70`** (phase0 log corrected the earlier `0x827C9F70`) |
| Active dict list head | `0x82839ED0` |
| Lookup-or-insert caller / INSERT | `sub_82189438` / `sub_82188E50` → populate `sub_8218C760` → resolver `sub_821BDF20` → `sub_821CB488` (returns NULL on PC → INSERT fails) |
| Dict factory (10 factory entries) | `sub_8218BF20` via `sub_8218B000` |
| Fatal switch | `byte_827D5C70` = compile-time 0x01, **zero runtime writers** — never patch it |
| Fatal fmt / name strings | `0x8200B358` / `0x82040F0C` ("star_glow") |
| Fatal raiser | `sub_821BD618` → slot `0x8285FEA0` = `0x82130678`; host override `patches.cpp:441` |
| Preload lists | `a:/archive/shaders/{ui,city,cars,characters,effects}/preload.list` |
| star_glow cascade | `embedded:/dcl/<n>.dcl` → `embedded:/<n>.dcl` → `embedded:/fxl_final/<n>.fxc` → mangled archive paths → fatal |

### Device / filesystem (rage fiDevice)
| What | Where |
|---|---|
| Device registry header | `0x82860844` = `{Device** array@+0, u16 count@+4, u16 capacity@+6}` (cap 16 from `0x827D8384`) |
| Registry entry (276 bytes) | `name[262], flag u16@262, nameLen u16@264, device vector {arr@268, cnt@272, cap@274}` |
| GetDevice | `sub_821CB488` (hardcoded prefix checks 7/10/6/6/7/5/4/3 chars, then 276-stride walk, best-prefix `sub_821CAA28`) |
| Mount | `sub_821CB9D8` — only 3 call sites: wrapper `sub_821CBF28` (fires 2×, `a:/archive/`), `sub_821399E0` (0 xrefs), `sub_82139BE0` (via `sub_82135E48`; whole chain never executes — ledger F-034) |
| Handler entry init / memory: sprintf | `sub_821CB760` / `sub_821CB740` (`"memory:$%p,%d,%d:%s"` @ `0x82012A28`; `"memory:"` @ `0x820127D8`) |
| Packfile vtable / embedded vtable | `0x82012BDC` / `0x82012B44`; TOC lookup = vtable+144 `sub_821CBFC0` (returns 0 if `[obj+8]==0`); Open `sub_821CDB88` |
| Page-cache inner stream | read `sub_821CCD58` via wrapper `sub_821CC6F0` (loads `[obj+32]`, bctrl inner vtable+28); 3×32KB slots at inner+296/336/356 |
| "Wait for slot" / kernel read submit | `sub_821CBE18` (SLOT-READY) / `sub_8244F4C0` (RD-SUBMIT), wrapper `sub_821C4F98` |
| fiDeviceMemory RTTI | `0x827D8380` is a **type_info/VFT object** (`.?AVfiDeviceMemory@rage@@`), NOT a holder; `0x827D838C` = dead pointer returned for memory:/embedded: prefixes |

### Streaming / task system
| What | Where |
|---|---|
| Load queue base | `0x82849518` (+ idx*0x6174); producer `sub_821BC868`, worker `sub_821BC910` (single-entered infinite loop), executor `sub_821BC140` (inflate steps lr=`821BC380`) |
| IO credit gate | `0x827D74E0` |
| GPU driver poller (NOT an IO stall) | `sub_8242FB88` — 30ms cadence on tick/dispatcher object `0x40004D7C` (`r26+32`), KeResetEvent on success |
| Post-inflate callback | `[r26+1548]` = `sub_821BC548` → tail `sub_821C9108` → `sub_8244ED10` — a **semaphore release on the archive device, not a memory mount** (F-032) |
| Texture-dict stream slots | 40-byte slot array `0x82860C18`, per-slot 4KB buffer `0x82860DF8+i*0x1000`, free count `0x827C8874` |

### Texture system
| What | Where |
|---|---|
| Named lookup (miss → fatal "Unable to find texture") | `sub_821849C0`; registry hash table `0x82839E2C`; specials `none`/`nonresident` @ `0x82839CF0/CF4` |
| Register / init | `sub_82197598` (pgDictionary register) / `sub_82180A30` (init) |
| Find-or-create / ctor / insert | `sub_82185368`+`sub_82185410` / `sub_82185648` → `sub_821854C8` |
| Texture pitch | `sub_8218DCE8` — host override in `patches.cpp` (jump-table fix; fmt1 → w*4 mattered) |
| Checkerboard fallback / DDS load | `sub_8218ECF8` (32×32, `0xFF00FF00`/`0xFFFF00FF`) / `sub_8218EDA8` ← `sub_8218E090` |

### Vertex fetch / VMX128
| What | Where |
|---|---|
| CPU-side vertex-fetch emulator | `sub_821B3548` (guest `0x821B3548–0x821B3CB8`); fetch-instruction loop `sub_821A0800` |
| `vpkd3d128` type-2 (2_10_10_10) pack | hooked via midasm @ `0x821B3814/3C2C/3E90/4788` → `mcla_Vpkd3d128_type2` (`src/vmx128_pack.cpp`) — landed (Route A) |
| Still unimplemented | `vupkd3d128` type-5 unpack ×94 (`0x822Fxxxx`), type-2 unpack ×1 (`0x821B43D8`), `vcmpbfp128` ×1 (`0x825CEA2C`) — see `PLAN_VMX128.md` |

### Draw path
| What | Where |
|---|---|
| Real draw dispatcher | `sub_82227428` (needs dispatch type `0x20000000`; never seen on loading path) |
| SetStreams / draw wrap / submit | `sub_8241BE78` (writes `dev+12748` count, VB descs `dev+12756`) / `sub_8241C308` (needs r6=IB) / `sub_82420BA8` |
| Real geometry chain | `sub_8217A470` → SetStreams → wrap → submit (all 0 hits while on loading screens) |

### Misc
| What | Where |
|---|---|
| CRT memset | `sub_8244D150` — recompiler special-cases its savegprlr stub, so **every store after any memset return reports lr=`0x8244D158`** until the caller's next bl (same artifact via slab-wrapper unlock `0x821C2AAC`). Guest-LR attribution after memset/leaf calls is VOID — use host backtraces (FFBT) |
| Module base | `sub_82130000` is a real `blr` in the shipped image (not a recompiler gap) |
| Dispatcher trampoline guard | `sub_8218CC70`, hook at `0x8218CC94` (`src/dispatch_guard.cpp`) |
| Known recompiler-gap stub | `sub_8221D9D0` (MISSING-BODY census in `patches.cpp`; never hit in soaks) |
| XCompress magic | `0x0FF512EF`; RSC5 header: `05 'CSR'` at +0, XCompress payload at +0xC, inflate caller does `inLeft = bytesRead − 12` |
| Component-size table (vertex fmt) | `0x8200C0A0` (`2,4,6,8 | 4,8,12,16 | 4,4,4,0…`), second table `0x8200C0E0` |
| Constant vectors (vpkd3d128 type-2 bias) | `0x820100F0` = {3,3,3,3}, `0x82010100` = {−2^−13,…,−3·2^−22} |

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
  or run the venv python on
  `C:/Users/abdul/.local/share/mcp/idamcp-venv/Scripts/idalib_jsonrpc_server.py`
  with arg `-v "E:/mcla pc/build/cache/mcla_pe.bin"`. Do NOT use the SSE
  `idalib_server.py` with the proxy. Useful tools: `get_function_by_address`,
  `decompile_function`, `disassemble_function`, `get_xrefs_to`,
  `list_strings_filter`, `read_memory_bytes`, `data_read_string`.
- **Ghidra MCP** on `:8089` — raw-image recipe: load `PowerPC:BE:64:default`,
  set image base `0x82000000`, **clear `no-return` on the ABI thunks**
  `0x823D91E4/EC/F0/F4/F8/FC` (savegprlr family) or the decompiler truncates
  every function at its prologue, then clear-flow-and-repair.
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
