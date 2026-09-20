# mcla-pc

<!-- docs/hero.gif goes here the day we have one; uncomment the block below when it exists
<p align="center"><img src="docs/hero.gif" alt="midnight club la running on pc through the native d3d12 pipeline"></p>
-->

native d3d12 renderer rebuild for midnight club LA

the recompiled ppc game code keeps running untouched, we capture render intent at the high level draw boundary and replay it as real d3d12 instead of letting the xenos command processor handle the gpu. legacy mode stays default until every gate passes.

**not rexglue based.** no emulation layer, no sdk wrapper. the game recompiles to native c++ and runs as native code on your pc. this means native performance, not the overhead you get from rexglue's translation layer.

## what exists rn

- standalone boot host linking the full recompiled image (46k+ function mappings), zero rexglue sdk
- xenos shader decode -> IR -> dxil translation pipeline
- d3d12 backend with pso cache
- offline validators for every phase gate
- boot gets through init into the game main loop
- device-method capture hooks live + render thread owns all d3d12
- shader->PSO pipeline wired: PipelineCache + async DXC worker, root signature, grcFvf input layout

## current status (2026-09-20)

boot gate complete per W36 commits: TLS allocator stable, VEH recovery, GFx loader wired with the correct vtable, zero crashes (UILOAD execution is commit-claimed, not yet re-verified in a soak). last soak opens the real retail packfiles and runs minutes on the loading path. wip: a module reorg (src/common, src/cpu, src/fs, src/rage, src/hooks, tools/validators) currently breaks the build — docs/LONG_TODO_MASTER.md T37.0 has the verified diagnosis. live frontier: docs/LONG_TODO_MASTER.md · chronological trail: docs/HANDOFF_NEXT_AGENT.md

## building

needs vs 2022 buildtools (vcvars64), cmake 3.25+, ninja, clang-cl for both c n c++. delete the build folder when switching compilers

```
configure.bat
ninja_build.bat
build\mcla.exe
```

## repo layout

- `src/` root - boot host, device-boundary hooks (gpu_device, gpu_cp), d3d12 backend, render thread/queue
- `src/kernel`, `src/apu`, `src/user` - kernel framework n guest runtime (xam.cpp = input)
- `src/cpu` - vmx128 host hooks, guest thread, ppc context
- `src/fs` - rpf3 packfile vfs
- `src/rage` - rage asset pipeline
- `src/hooks` - ppc_func hook bodies (split from patches.cpp)
- `src/common` - shared logging/cvar headers
- `src/renderer` - xenos decode, shader translation, texture/vertex decoding, caches
- `tools/validators` - phase-gate validator exes
- `generated/` - recompiler output, input only, never edited by hand
- `third_party/` - sdl3, fmt, spdlog, toml++, dxc, o1heap, xxhash
- `config/` - cmake/xenonrecomp/manifest tomls

## contributing

this project needs help. if you have experience with:
- xbox 360 / xenos gpu emulation
- d3d12 rendering
- ppc recompilation
- kernel/hook frameworks

open a pr or open an issue. dont be shy.

## legal

zero game code or assets live in this repo. bring your own legally dumped copy of midnight club la (xbox 360) and the toolchain consumes that. nothing from the disc is hosted or distributed here, same rules xenia and unleashedrecomp play by.

## credits / influence

this wouldnt exist without these, go check em out:

- [UnleashedRecomp](https://github.com/hedge-dev/UnleashedRecomp) - the kernel framework here mirrors its structure exactly
- [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) - the ppc to c++ recompiler that generates everything in generated/
- [XenosRecomp](https://github.com/hedge-dev/XenosRecomp) - the xenos shader -> hlsl translator blueprint for the offline cache
- [Xenia](https://github.com/xenia-project/xenia) - the reference for xbox 360 kernel and gpu semantics
- [LARecomp](https://github.com/mzzvxm/larecomp) + [BadassBaboon/midnightclub](https://github.com/BadassBaboon/midnightclub) - other teams' mcla recompiles; proof the blockers are solvable + a pile of game-specific intel

much love from JO🇯🇴
abdullah atef alrawashdeh / HTU student
