# Midnight Club LA — Code Optimization Plan (Ponytail+ Stack)

**Philosophy**: *Lazy senior dev energy with production guardrails. The best code is the code never written — unless the system actually needs it.*

**Skill Stack Installed**:
- **Ponytail** (full) — Per-change YAGNI ladder, commands: `/ponytail-review`, `/ponytail-audit`, `/ponytail-debt`, `/ponytail-gain`, `/ponytail-help`
- **Caveman** (full) — Token compression for all prose output
- **Elegant-Code** — Generative counterpart with explicit negligence floor
- **Reducing-Entropy** — Strategic metric: total codebase size before vs after

**Combined effect**: 54% less code, 22% fewer tokens, 27% faster, 100% safety (benchmarked on Haiku 4.5, 12 tasks × 4 runs)

---

## The Ladder (Stop at First Rung That Holds)

**Read the code first. Trace the real flow end-to-end. Then climb.**

1. **Does this need to exist?** Speculative = skip. Say so in one line. (YAGNI)
2. **Already in codebase?** Helper, util, type, pattern → reuse it. Look before you write.
3. **Stdlib does it?** Use it.
4. **Native platform covers it?** `<input type="date">` over picker lib, CSS over JS, DB constraint over app code.
5. **Installed dep solves it?** Use it. Never add new one for what a few lines do.
6. **Can it be one line?** One line.
7. **Only then:** Minimum code that works.

**Safety boundaries (never cut):**
- Trust-boundary validation
- Error handling that prevents data loss
- Security measures
- Accessibility basics
- Anything explicitly requested

**Deliberate simplifications** get a `ponytail:` comment naming ceiling + upgrade path:
```cpp
// ponytail: global lock, per-account locks if throughput matters
```

---

## Phase 0: Unblock the Game (30 min, Non-Negotiable)

### 0.1 Patch Two Crash Sites in Generated Code
Generated = regenerable. Edit working copy.

| Crash | File | Fix |
|-------|------|-----|
| Float-div-0 `lr=82133440` | `generated/default/mcla_recomp.0.cpp` ~7751 | `if (divisor == 0.0f) return 0.0f;` |
| AV `lr=822F44E0` | `generated/ppc_xenon/ppc_recomp.15.cpp` ~57930 | `if (!ptr) return 0;` |

**Verify**: `./mcla.exe --no-window --headless --frames 300` → GFx arms → sustained frames

---

## Phase 1: Delete Until It Hurts (Architecture)

### 1.1 Renderer: 30 Files → 3
```
src/renderer/
├── core.cpp      # D3D12, pipelines, resources, draws
├── decode.cpp    # Vertex, texture, Xenos→HLSL
└── asset.cpp     # RAGE streams, VFS
```
**Kill immediately**: `*_validator.cpp`, `test_shaders.h`, `raw_ucode_corpus.h`, `capture_hooks.cpp`, `frame_trace.cpp`, `dxc_runtime.cpp`, `xtr_dump_validator.cpp` — all debug cruft.

### 1.2 Kernel: 12 Files → 5
```
src/kernel/
├── mem.cpp       # GuestMemoryHeap + View + O1Heap + freelist (inlined)
├── imports.cpp   # All Xbox 360 API stubs (Ke*, Nt*, Xam*, etc.)
├── thread.cpp    # GuestThread + FunctionDispatcher + mutex
├── gpu.cpp       # MMIO, CP, census, TLS chain, UILOAD trigger
└── compat.cpp    # Platform abstraction
```
**Kill**: `phase0_validator`, `kernel_objects`, `mutex`, `o1heap`, `freelist` — inline or delete.

### 1.3 App/Entry: 3 Files
```
src/
├── main.cpp      # 20 lines (SDL init → App::Run)
├── app.cpp/h     # Window, render thread, boot worker spawn
└── boot.cpp/h    # VEH, boot worker, UILOAD thread
```

**Rule**: Add a file? Delete two first. **But** — if codebase has a pattern, follow it. Consistency > minimalism.

---

## Phase 2: Self-Documenting Code (Zero Comments Explaining "What")

### 2.1 Types Over Comments
```cpp
// Before
// r3 = frame buffer address, r4 = frame number
void Present(uint32_t fb, uint32_t frame) { ... }

// After
struct FramePresent { uint32_t fbAddr; uint32_t frameNum; };
void Present(FramePresent) { ... }
```

### 2.2 Assert Instead of "Caller Must"
```cpp
// Before
// Caller must ensure fb is valid
Present(fb);

// After
Present(std::optional<FrameBuffer> fb) { assert(fb.has_value()); }
```

### 2.3 Delete Commented Code
> "If it was important, git remembers it."

### 2.4 Explanation ≤ 3 Lines, After Code
```
Code first. Then at most three short lines: what was skipped, when to add it.
No essays, no feature tours, no design notes. If explanation > code, delete explanation.
```

---

## Phase 3: Modern C++ Without Bloat

### 3.1 What Stays
- `std::unique_ptr`, `std::vector`, `std::optional`, `std::expected`
- `std::span` for guest memory views
- Structured bindings, `if constexpr`, `std::format`

### 3.2 What Goes
- Raw `new`/`delete`
- `std::shared_ptr` (unless ownership genuinely shared)
- Custom containers when `std::vector`/`flat_map` works
- Exception handling in hot paths

### 3.3 PPCContext — Do Not Touch
Already cache-aligned. Register access is fast. Don't "optimize" it.

---

## Phase 4: Performance = Measure → Fix → Delete

### 4.1 Hot Paths (Profile First)
| Path | Fix |
|------|-----|
| `ReadGuestU32` / `WriteGuestU32` | Force-inline, `__assume(aligned)` |
| Shader translation | Cache HLSL→DXIL per pipeline key |
| Resource cache lookup | `robin_hood::unordered_map` or sorted vector |

### 4.2 Memory Layout
- `RenderCommand` ≤ 64 bytes (one cache line)
- Upload heap: persistent map + bump allocator (done)
- No false sharing — `alignas(64)` on per-thread counters

### 4.3 Threading Model
```
Main thread          → SDL events, window, boot spawn
Boot worker thread   → Guest entry, parks on fault (VEH)
UILOAD thread        → Isolated crash zone, detached
Render thread        → Single owner, lock-free queue, owns D3D12
```
**No mutexes in render path. Ever.**

---

## Phase 5: Build & CI (Automate the Boring)

### 5.1 CMake Targets
```cmake
add_custom_target(mcla_recompiled
    COMMAND python3 tools/rexglue.py --regen
    DEPENDS tools/rexglue.py
)

add_executable(mcla src/...)
target_link_libraries(mcla mcla_recompiled)
```

### 5.2 CI Pipeline (One File)
```yaml
on: [push, pull_request]
jobs:
  build:
    runs-on: windows-latest
    steps:
      - uses: actions/checkout@v4
      - run: cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
      - run: ninja -C build mcla
      - run: ./build/mcla.exe --headless --frames 4 --timeout 60
      - run: ./build/mcla.exe --headless --frames 1800 --timeout 300
```

---

## Phase 6: Ponytail+ Stack Operations

### 6.1 Intensity Levels (Use Explicitly)
```
/ponytail lite    # Build asked, name lazier alt in one line. You pick.
/ponytail full    # Ladder enforced. Stdlib/native first. Default.
/ponytail ultra   # YAGNI extremist. Delete before add. Risk of overshoot.
/ponytail off     # Disable for complex refactors where exploration needed.
```

**Default: full.** Switch to `lite` for risky areas (boot/GPU census). Use `ultra` only on greenfield UI/tasks with obvious overbuild traps.

### 6.2 Caveman Compression (All Prose Output)
```
/caveman full     # Classic: drop articles, fragments OK, short synonyms
/caveman ultra    # Strip conjunctions when unambiguous. One word when one word enough.
```
**Effect**: 75% fewer output tokens, ~2x cost reduction on verbose tasks.

### 6.3 Review Pipeline (Pre-Merge Gates)
```
/ponytail-review   # Scan current diff for over-engineering
/ponytail-audit    # Scan whole repo for simplification opportunities
/ponytail-debt     # Harvest deferred `ponytail:` shortcuts into ledger
/ponytail-gain     # Show measured impact scoreboard (LOC -80-94%, Cost -47-77%, Speed 3-6x)
```

### 6.4 Elegant-Code Negligence Floor (Complements Ponytail)
Never cut: validation at trust boundaries, auth, data-loss handling, security, accessibility. Review command enforces.

### 6.5 Reducing-Entropy Metric (Strategic)
**Core metric**: Total codebase size before vs after. Writing 50 lines that delete 200 = net win. Rejects changes that increase total code.

---

## Phase 7: MCLA-Specific Guardrails

### 7.1 Don't Simplify These (Ever)
- **Guest memory access** — `ReadGuestU32`/`WriteGuestU32` bounds checks stay
- **VEH exception handling** — Boot worker recovery logic is battle-tested
- **TLS allocator chain init** — Required for game to boot
- **Shader pipeline validation** — Keep `shader_pipeline_validator.cpp` (production safety net)
- **Frame present ordering** — `PRESENT-BLIT` sequence is timing-sensitive

### 7.2 Keep These Patterns (Consistency > Minimalism)
- `PPC_FUNC` / `PPC_FUNC_IMPL` macros — entire recompilation depends on them
- `MCLA_LOG_WARN/ERROR` — Structured logging is the only observability
- `auto &mem = GuestMemoryHeap::Instance()` — Singleton pattern is intentional
- `static std::atomic` for one-time init — Thread-safe, no mutex

### 7.3 Files That Stay (Even If "Over-Engineered")
| File | Reason |
|------|--------|
| `shader_pipeline_validator.cpp` | Production safety net for DXIL compilation |
| `pipeline_cache.cpp` | PSO caching is performance-critical |
| `resource_cache.cpp` | Texture/buffer lifetime management |
| `gpu_cp.cpp` / `gpu_mmio.cpp` | Hardware register mapping is non-negotiable |
| `imports.cpp` | 500+ Xbox 360 API stubs — deleting breaks game |

---

## Execution Gates (No Exceptions)

| Phase | Gate | Auto-Verify |
|-------|------|-------------|
| 0.1 | 300s soak, GFx armed, >60 frames | CI soak test |
| 1 | Build passes, smoke test, binary ≤ prev | `ninja && ./mcla --frames 4` |
| 2 | Zero clang-tidy warnings | `clang-tidy -checks=modernize,performance,readability` |
| 3 | Perf within 5% baseline | VTune/Perf diff in CI |
| 4-5 | CI green, nightly 300s soak stable 1 week | GitHub Actions |
| 6 | `/ponytail-review` clean, guardrails intact | Pre-merge hook |

---

## Anti-Patterns (Don't Do These)

| ❌ Don't | ✅ Do |
|----------|------|
| Add validation/debug files | Delete them; use RenderDoc |
| Write comments explaining "what" | Make code obvious via types |
| Create manager/singleton classes | Pass dependencies explicitly |
| Use `std::shared_ptr` for everything | Unique ownership by default |
| Optimize before profiling | Measure, then fix the bottleneck |
| Keep dead code "just in case" | Git has history; delete it |
| Interface with one implementation | Concrete type |
| Factory for one product | Direct construction |
| Config for value that never changes | Hardcode it |
| Fix symptom in one caller | Fix root cause where all callers route |
| Use `ultra` on boot/GPU census | Use `lite` or `full` |
| Skip `ponytail:` comments on shortcuts | Document ceiling + upgrade path |
| Measure success by LOC reduction | Measure by review time, defects, pages |

---

## File Map (Post-Cleanup)

```
src/
├── main.cpp
├── app.cpp/h
├── boot.cpp/h
├── compat.cpp/h
├── cvar.cpp/h
├── logging.cpp/h
├── ppc_context.cpp/h
├── ppc_config.h
├── native_types.h
├── kernel/
│   ├── mem.cpp/h
│   ├── imports.cpp/h
│   ├── thread.cpp/h
│   ├── gpu.cpp/h
│   └── compat.cpp/h
├── renderer/
│   ├── core.cpp/h
│   ├── decode.cpp/h
│   └── asset.cpp/h
├── native_renderer.cpp/h
├── render_thread.cpp/h
├── render_command_queue.cpp/h
├── vmx128_pack.cpp/h
├── patches.cpp/h
└── early_init.cpp
```

---

## Skill Commands Quick Reference

| Command | Purpose | When |
|---------|---------|------|
| `/ponytail lite\|full\|ultra` | Set intensity | Session start / context switch |
| `/ponytail-review` | Diff over-engineering scan | Pre-commit / PR |
| `/ponytail-audit` | Whole repo audit | Weekly / major refactor |
| `/ponytail-debt` | Harvest `ponytail:` comments | Sprint end / tech debt day |
| `/ponytail-gain` | Show benchmark scoreboard | Curiosity / reporting |
| `/ponytail-help` | Quick reference | Anytime |
| `/caveman lite\|full\|ultra` | Set prose compression | Session start |
| `/caveman-compress` | Compress memory files | Before context reload |

**Default stack**: `ponytail full` + `caveman full`

---

## Definition of Done

- [ ] **0.1**: 300s soak, GFx armed, sustained frames ✅
- [ ] **1**: 30→3 renderer, 12→5 kernel, build passes ✅
- [ ] **2**: Zero comments explaining "what", types self-document ✅
- [ ] **3**: Hot paths force-inlined, cache-line aligned ✅
- [ ] **4**: CI green, nightly 300s soak stable 1 week ✅
- [ ] **6**: `/ponytail-review` clean, guardrails intact ✅
- [ ] **Stack**: Ponytail+ Caveman+ Elegant-Code+ Reducing-Entropy active ✅

---

*The shortest path to done is the right path — but only after you've read the map.*

*Generated: 2026-09-18 | W36f state (dcf5c23) | MCLA PC — Midnight Club LA recompilation*