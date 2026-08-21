# Coding Standards — MCLA Native PC GPU

## Language & Toolchain
- **C++23** with `clang-cl` (MSVC-compatible), `/utf-8`, `NOMINMAX`
- CMake 3.25+, Ninja generator
- No exceptions, no RTTI; prefer `std::expected` / error codes
- `constexpr` by default; `[[nodiscard]]` on all fallible functions

## Memory Safety (Guest ↔ Host)
1. **Guest pointers are 32-bit addresses with bounds** — never raw host pointers
2. All guest reads go through checked helpers (`GuestMemory::read<T>()`)
3. **Endianness is explicit**: `ReadU16BE`, `ReadU32BE`, `ReadF32BE` — no `reinterpret_cast`
4. Use `GuestSpan<T>` for bounded ranges; validate `offset + size ≤ guest_ram_size`
5. Zero host allocations inside hot paths; use arena/frame allocators

## Hooks & Dispatch
- **One hook owner per guest address** — use the composable dispatcher
- Hooks **only capture state** — no D3D12 calls, no `rex::graphics::RegisterFile` dependency
- Hook return: `HookResult::Continue` | `HookResult::Override` (with captured payload)
- Register hook chains in `src/hooks/registry.cpp` only

## Renderer Abstraction
- Default mode = `legacy` (Xenos command processor) until phase gates pass
- Native path: capture draw intent at high-level boundary → translate → D3D12
- No invented draw data — unknown capture fields must be researched
- Shaders: Xenos microcode → IR → HLSL/DXIL via offline tooling

## D3D12 Conventions
- Explicit resource states; barriers batched per frame
- Descriptor heaps: CBV/SRV/UAV (tier 1), Sampler (separate), RTV/DSV
- Root signatures: static samplers in signature; push constants via 32-bit root constants
- Pipeline state objects cached by `PipelineKey` (hash of VS/PS/RS/DS/BS/IB/VB layout)

## Logging & Diagnostics
- `spdlog` with `fmt` — structured logging: `logger->info("draw: idx={} instances={}", idx, count)`
- Tracy zones for all GPU work submission (`FrameMark`, `ZoneScopedN`)
- D3D12 debug layer enabled in `RelWithDebInfo`; treat warnings as errors

## Formatting
- `clang-format` (project `.clang-format`) — run before commit
- 4-space indent, 120-col, braces on same line
- Includes: system → third-party → project; alphabetical within group

## Testing
- Offline validators under `build/` (shader corpus, IR dumps, manifest checks)
- Smoke gate: `build/mcla.exe --validate-shaders --headless`
- No runtime tests in CI; validation is offline / corpus-based