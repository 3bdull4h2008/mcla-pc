# MCLA-PC Project Memory

## Current Status
- **Phase 1 (ABI Migration):** ✅ DONE
- **Phase 2 (Kernel Framework):** ✅ DONE (13/13 tests passing — verified live 2026-09-03)
- **Phase 3 (Critical Imports):** ✅ PASSED (2026-08-22) — Game boots, archives load, VSync 60fps
- **Phase 4' (Device-Boundary Takeover):** 🔄 IN PROGRESS — Steps 1-2 done (create-hook @`sub_82413588` + packet capture v2 @`sub_82411640`); hooks armed, zero captures because boot blocks earlier; enhanced slab census (session 37) ready for live capture
- **Phase 4.5'–9':** ⏳ PENDING (see revised ladder in `docs/MCLA_REBUILD_PLAN.md`)

## Architecture Summary
- **Goal:** Replace Xbox 360 Xenos GPU command processor with native D3D12 renderer
- **Stack:** C++23, CMake 3.25+, Ninja + clang-cl, D3D12, SDL3, XenonRecomp (46K+ PPC functions)
- **Key Rule:** No PM4 in native path — device-method boundary override only
- **Entry Point:** `_xstart` at guest address `0x821322B8`
- **Image Base:** `0x82000000`, Code Base: `0x82130000`, Code Size: `~6.8MB`

## Key Decisions
1. Identity handles (handle = pointer to KernelObject)
2. Typed-argument hooks (no manual ctx.rN reads)
3. No PM4 in native rendering path
4. Device-method boundary override (not packet parsing)
5. Guest thread → queue → render thread
6. Offline shader cache first
7. D3D12 only (no abstraction layer)

## Build Commands
```batch
configure.bat              # Configure CMake (Ninja + clang-cl)
ninja_build.bat            # Build mcla.exe
build\phase0_validator.exe # Kernel tests (13/13 required)
tools\run_phase_gates.ps1  # Run all gates with regression detection
```

## Critical File Locations
| File | Purpose |
|------|---------|
| `src/kernel/imports.cpp` | All kernel hooks (Nt*, Ke*, Vd*) |
| `src/gpu_device.cpp` | Device boundary hooks |
| `src/native_renderer.cpp` | D3D12 renderer |
| `src/vfs_rpf.cpp` | RPF3 archive VFS |
| `docs/MCLA_REBUILD_PLAN.md` | Master rebuild plan |
| `docs/AGENTS.md` | Agent rules and conventions |
| `config/mcla_xenonrecomp.toml` | PPC recompilation config |

## Current Blocker (Phase 4′ — refreshed 2026-09-05, sessions 33–37)

**Intermittent OOM fatal ~T+15s** in the guest churn heap:
- Fataling heap struct `0x82830CD8`, cap `0x02E7FFF0` (46.5 MB, FIXED — `sub_821C1BB0` has NO grow path)
- Field map (corrected session 36): +76=cap, +84=carved, +152=free; at fatal the heap is ~4% used — session-35 "97-100% full" was a swapped-label artifact
- **Prime suspect:** class allocator `sub_821DE9D8` (ppc_recomp.20.cpp) returning 0 WITHOUT calling C1BB0 when a slab header is inconsistent ([slab+8] count>0 but [slab+12] freelist empty) → C29A0 fast-path raise
- Working hook mechanism = `PPC_FUNC(sub_XXXX)` weak-alias strong def (dispatcher-map SetFunction is NEVER consulted for guest calls); live censuses: OOM-CENSUS, PHYSALLOC-CENSUS, ARENA-CENSUS
- Session-34 also observed the GPU-progress-wait class: steady 30ms poll, ring put advances but progress counter (pc) never advances → legacy CP publication not reaching guest (secondary; fix under freeze line)

**Next (session 40):** Run gate soak → dense census MUST catch crash dispatch → analyze `global8270` value on failing call → trace who should initialize config global → then P4′ step 3 render thread.

History: the old "[0x7FC86544] bit0 park" blocker was superseded (2026-08-24) by the bctrl dispatch crash at `sub_825FDB30` (fully decoded — node-chain walk via data-section vtables; the "raw host pointer 0x7E780000" was arithmetic on ctr=0, myth busted).

## Memory / Ledger Locations
- **Canonical durable ledger:** `.clinerules/memory/memories-*.md` (sessions 4, 24→36)
- **Handoffs:** `docs/handoffs/YYYY-MM-DD-*.md` + `docs/BOOT_HANDOFF.md` (live frontier)
- ⚠️ `.opencode/memory/` is a STALE truncated duplicate (2026-08-30 recovery) — do not write there
- `second_brain_*` MCP has no server in Cline — file ledger only

## Agent Modes (Cline)
| Mode | Use For |
|------|---------|
| `gpu-engineer` | Default — D3D12 implementation |
| `reverser` | PPC/recomp analysis, struct discovery |
| `architect` | System design, phase planning |
| `gate-cracker` | Wait-primitive exit-condition decode, emulation-point ranking |
| `shader-translator` | Xenos microcode → HLSL/DXIL |
| `debugger` | Crash/assert triage |
| `build-specialist` | CMake/toolchain issues |
| `test-engineer` | Offline validators |

## Golden Rules
1. One hook owner per guest address
2. Hooks only capture state (no D3D12 calls)
3. Guest pointers are 32-bit guest addresses (never raw host pointers)
4. Endianness is explicit (ReadU16BE, ReadU32BE)
5. No invented draw data
6. Keep generated/ code unchanged
7. Search before acting — always verify with Ghidra/RenderDoc first

## Last Updated
- 2026-09-05: Session 39 — CONFIG-DISPATCH census v3 (dense 500 calls + GLOBAL@82839270 tracking)
- 2026-09-03: Full doc resync (README/ARCHITECTURE/AGENTS/plan) — statuses, blocker, stale paths, validator counts
- 2026-08-30: Directory cleanup for Cline (rules → `.clinerules/`, handoffs → `docs/handoffs/`)
