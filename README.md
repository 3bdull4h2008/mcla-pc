# mcla-pc

<!-- hero clip goes here the day we have one. drop docs/hero.gif n uncomment
<p align="center">
  <img src="docs/hero.gif" alt="midnight club la running on pc through the native d3d12 pipeline">
</p>
-->

native d3d12 renderer rebuild for midnight club LA WIP

the idea: the recompiled ppc game code keeps running untouched, we capture render intent at the high level draw boundary n replay it as real d3d12 instead of letting the xenos command processor handle the gpu. legacy mode stays default until every gate passes.

## road map

revised ladder (P4'-P9') lives in docs/MCLA_REBUILD_PLAN.md. legacy mode stays default until every gate passes.

| # | phase | what it means | status |
|---|-------|--------------|--------|
| 1 | abi migration | move everything onto the ppc_func abi with checked guest memory access | done |
| 2 | kernel framework | rebuild the kernel layer to match unleashedrecomp exactly - identity handles, typed arg hooks, lazy wrap | done (13/13 tests) |
| 3 | critical imports | implement the imports boot needs to reach a real present call | passed 2026-08-22 - boots, archives load, vsync 60fps |
| 4' | device-boundary takeover | hook the game's own d3d-class device methods (create/present/state/draw), enqueue render commands | in progress - steps 1-2 done |
| 4.5' | render thread & queues | blocking command queue + copy queue, render thread owns all d3d12 calls | pending |
| 5' | real draws via device boundary | vb/ib/format/shader capture from redirected device methods, pixel-hash parity | pending |
| 5.5' | offline shader cache | offline translate 1,264+ ucode corpus to zstd-embedded dxil keyed by hash | pending |
| 6' | native default | renderer_mode=native default, legacy cp path retired | pending |
| 7'-9' | build env, codegen config, kernel surface | cmake presets, midasm decision, xam surface | pending |

plan summary: each phase has a hard gate with an offline validator proving it before moving on. no claiming anything works unless the validator says so.

## what exists rn

- standalone boot host linking the full recompiled image (46k+ function mappings), zero rexglue sdk
- xenos shader decode -> IR -> dxil translation pipeline
- d3d12 backend with pso cache
- offline validators for every phase gate
- boot gets through init into the game main loop
- device-method capture hooks live (P4' steps 1-2: create-hook + packet capture v2), armed and waiting on the boot blocker

## current blocker (2026-09-03)

intermittent OOM fatal ~T+15s from the guest churn heap (heap struct 0x82830CD8,
46.5MB fixed cap, no grow path) - prime suspect is the class allocator
sub_821DE9D8 returning 0 on an inconsistent slab header. kernel-role work only
(freeze line: no PM4, no manual seeding, no opcode expansion). see
docs/BOOT_HANDOFF.md + docs/handoffs/ for the live trail.

## building

needs vs buildtools (vcvars64), cmake 3.25+, ninja, clang-cl for both c n c++. delete the build folder when switching compilers

```
configure.bat
ninja_build.bat
build\mcla.exe
```

## repo layout

- `src/kernel`, `src/cpu`, `src/apu`, `src/user` - kernel framework n guest runtime
- `src/renderer` - xenos decode, shader translation, texture/vertex decoding, caches
- `src/` root - boot host, device-boundary hooks, d3d12 backend, render thread/queue, vfs
- `generated/` - recompiler output, input only, never edited by hand
- `third_party/` - sdl3, fmt, spdlog, toml++, dxc, simde
- `config/` - cmake/xenonrecomp/manifest tomls

## legal

zero game code or assets live in this repo. u bring ur own legally dumped copy of midnight club la (xbox 360) n the toolchain consumes that. nothing from the disc is hosted or distributed here, same rules xenia n unleashedrecomp play by.

## credits / influence

this wouldnt exist without these, go check em out:

- [UnleashedRecomp](https://github.com/hedge-dev/UnleashedRecomp) - the kernel framework here mirrors its structure exactly
- [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) - the ppc to c++ recompiler that generates everything in generated/
- [XenosRecomp](https://github.com/hedge-dev/XenosRecomp) - the xenos shader -> hlsl translator blueprint for the offline cache
- [Xenia](https://github.com/xenia-project/xenia) - the reference for xbox 360 kernel and gpu semantics
- [LARecomp](https://github.com/mzzvxm/larecomp) + [BadassBaboon/midnightclub](https://github.com/BadassBaboon/midnightclub) - other teams' mcla recompiles (rexglue); proof the blockers are solvable + a pile of game-specific intel we cite in the plan

much love from JO🇯🇴
abdullah atef alrawashdeh / HTU student