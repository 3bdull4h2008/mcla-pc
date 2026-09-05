# MCLA Native PC — Cline Agent Todo List

**Updated:** 2026-09-05 (Session 56 — census done, moving to render thread)  
**Plan:** `docs/MCLA_REBUILD_PLAN.md`  
**Handoff:** `docs/BOOT_HANDOFF.md`  
**Live Frontier:** `docs/handoffs/`

---

## ✅ RESOLVED — Sessions 55-56

| ID | Task | Priority | Status | Notes |
|----|------|----------|--------|-------|
| B1 | **CONFIG-DISPATCH fix** — compiledFuncs map + no-op stub dispatch | 🔴 CRITICAL | ✅ DONE (S55) | Game runs 120+ seconds, zero crashes |
| B2 | **Identify GLOBAL @82839270 initializer** — unused BSS slot | 🔴 CRITICAL | ✅ DONE (S55) | 0x82839270 always zero, no live code writes to it |
| B3 | **Writer-attribution census on 16-byte pool** — root-cause overflow | 🟡 HIGH | ✅ DONE (S56) | 64 false positives (normal init), 0 real overflows detected in slab scan |

---

## 🔴 ACTIVE — P5′ Real Draws via Device Boundary

| ID | Task | Priority | Status | Notes |
|----|------|----------|--------|-------|
| B5 | **P4.5′: Copy queue** — separate D3D12 command queue for streaming uploads | 🔴 CRITICAL | ✅ DONE (S58) | StreamingUpload() on copy queue |
| B6 | **P4.5′: Frame pacing** — render thread owns vsync/present timing | 🟡 HIGH | ✅ DONE (S58) | 30fps target, Sleep-based pacing |
| B7 | **P4.5′: Queue depth monitoring** — track queue fill, drop non-critical cmds | 🟡 HIGH | ✅ DONE (S58) | Warn at 30, drop at 60 |
| B8 | **P5′: Wire device-method hooks** — enqueue DRAW_CAPTURED from hooks | 🔴 CRITICAL | ⏳ IN PROGRESS | hk_sub_82413660 + Hooked_Sub82420BA8 |
| B9 | **P5′: First native triangle** — real Xenos shaders → DXIL pipeline | 🔴 CRITICAL | ⏳ PENDING | After hooks wired |
| B10 | **P5′: PSO management** — create graphics pipeline state objects | 🟡 HIGH | ⏳ PENDING | After first triangle |

---

## 📋 PHASE STATUS (from MCLA_REBUILD_PLAN.md)

| Phase | Description | Status | Gate |
|-------|-------------|--------|------|
| P1 | ABI Migration (XenonRecomp) | ✅ DONE | Build clean |
| P2 | Kernel Framework Foundation (Canonical) | ✅ DONE | phase0_validator 13/13 PASS |
| P3 | Critical Import Implementations | ✅ PASSED 2026-08-22 | Boot → main loop, archives load, VSync 60fps |
| P4′ | Device-Boundary Takeover | ✅ Steps 1-3 done | CP drain + render thread own all D3D12 |
| P4.5′ | Render Thread & Queues | ✅ DONE (S58) | Copy queue + frame pacing + queue depth |
| P5′ | Real Draws via Device Boundary | ⏳ IN PROGRESS | First native triangle with real shaders |
| P5.5′ | Offline Shader Cache | ❌ NOT STARTED | Blocked on P5′ |
| P6′ | Native Default | ❌ NOT STARTING | Blocked on all above |

---

## 🎯 IMMEDIATE NEXT ACTIONS (Session 58+)

### P5′ — Real Draws via Device Boundary (B8-B10)
- [ ] **Wire device-method hooks** — `hk_sub_82413660`, `Hooked_Sub82420BA8` enqueue DRAW_CAPTURED
- [ ] **First native triangle** — real Xenos shaders → DXIL pipeline
- [ ] **PSO management** — create graphics pipeline state objects from Xenos shader hashes
- [ ] **Wire DRAW_CAPTURED** from VdSwap/swap chain to actually draw

### Post-P5′
- [ ] P5.5′: Offline shader cache (Xenos microcode → DXIL at build time)
- [ ] P6: Full graphics pipeline (textures, render targets, state management)

---

## 🔬 RESEARCH / INVESTIGATION QUEUES

| ID | Topic | Agent | Status |
|----|-------|-------|--------|
| R1 | HW kernel ISR → driver-event signaling (vsync ISR @0x82411478 → guest event signal) | `reverser` / `gate-cracker` | ⏳ PENDING |
| R2 | `sub_824569C8` / `sub_824569C4` worker census — what creates the event `C9ADB800`? | `reverser` | ⏳ PENDING |
| R3 | 0xB5800000-class phys alloc semantics — does it return wrong memory for handler table? | `reverser` | ⏳ PENDING |
| R4 | LARecomp vblank interrupt storm fix → apply to our vsync ISR path | `research-scout` | ⏳ PENDING |
| R5 | XenosRecomp DXIL signing pipeline — integrate at build time for P5.5′ | `shader-translator` | ⏳ PENDING |

---

## 🛠 VS CODE IMPROVEMENTS (JUST COMPLETED)

| Item | File | Status |
|------|------|--------|
| Settings (clang-cl, clangd, cmake, terminal, formatting) | `.vscode/settings.json` | ✅ DONE |
| Launch configs (mcla, validators, attach) | `.vscode/launch.json` | ✅ DONE |
| Build tasks (configure, build, run, validators, clean, format) | `.vscode/tasks.json` | ✅ DONE |
| clang-format config (LLVM-based, 4-space, 120-col) | `.clang-format` | ✅ DONE |

**Recommended Extensions to Install:**
- `llvm-vs-code-extensions.vscode-clangd` (C++ LSP)
- `ms-vscode.cmake-tools` (CMake integration)
- `ms-vscode.cpptools` (Debugging)
- `Gruntfuggly.todo-tree` (TODO tracking)
- `vadimcn.vscode-lldb` (Alternative debugger)

---

## 📝 HANDOFF PROTOCOL (Before Context Pressure)

1. **Run `memory-steward`** to persist decisions, assumptions, open questions
2. **Write lossless handoff** to `docs/handoffs/YYYY-MM-DD-session-XX.md` with:
   - Exact addresses, offsets, evidence
   - Census output samples
   - Open questions with reproduction steps
3. **Update `docs/ARCHITECTURE.md`** if phase lands
4. **Commit checkpoint** — worktree has uncommitted census work in patches.cpp (sessions 37-56)

---

## 🏁 VALIDATION COMMANDS

```bash
# Configure
configure.bat

# Build
ninja_build.bat
# or: cmake --build build --config RelWithDebInfo

# Smoke gate (must pass before claiming anything works)
build\mcla.exe --validate-shaders --headless

# Unit validators
build\phase0_validator.exe
build\xenos_decode_validator.exe
build\shader_pipeline_validator.exe
build\phase3_validator.exe
build\texture_decode_test.exe
build\capture_dump_validator.exe
build\xtr_dump_validator.exe
build\backend_validator.exe
```

---

## ⚠️ GOLDEN RULES (Never Violate)

1. **No PM4 in native path** — frame production must not read/write/drain/depend on PM4 ring, doorbell MMIO, or CP behavior
2. **Device-table boundary is THE boundary** — capture render intent by overriding game's D3D-class device methods, never by parsing packets
3. **Guest thread → queue → render thread** — device-method handlers only enqueue; render thread owns ALL D3D12 calls
4. **Offline shader cache first** — Xenos microcode translates at BUILD time
5. **Generated/ is INPUT ONLY** — never patch recompiled sources
6. **One hook owner per guest address** — use composable dispatcher
7. **Hooks capture ONLY** — no D3D12, no side effects, no `rex::graphics::RegisterFile` dependency
8. **Guest pointers = 32-bit guest addresses + bounds** — never raw host pointers; reads through checked `GuestMemoryView` with explicit endian reads
9. **No invented draw/boot data** — every struct field and return value researched before trust
10. **renderer_mode=legacy stays default** until every gate passes

---

*Last updated by Cline agent — Session 58 (P4.5′ done, moving to P5′)*