# mcla-pc

<!-- hero clip goes here the day we have one. drop docs/hero.gif n uncomment
<p align="center">
  <img src="docs/hero.gif" alt="midnight club la running on pc through the native d3d12 pipeline">
</p>
-->

native d3d12 renderer rebuild for midnight club LA

the recompiled ppc game code keeps running untouched, we capture render intent at the high level draw boundary n replay it as real d3d12 instead of letting the xenos command processor handle the gpu. legacy mode stays default until every gate passes.

**not rexglue based.** no emulation layer, no sdk wrapper. the game recompiles to native c++ and runs as native code on your pc. this means native performance, not the overhead you get from rexglue's translation layer.

## what exists rn

- standalone boot host linking the full recompiled image (46k+ function mappings), zero rexglue sdk
- xenos shader decode -> IR -> dxil translation pipeline
- d3d12 backend with pso cache
- offline validators for every phase gate
- boot gets through init into the game main loop
- device-method capture hooks live + render thread owns all d3d12
- shader->PSO pipeline wired: PipelineCache + async DXC worker, root signature, grcFvf input layout

## current status (2026-09-09)

guest park blocker CLOSED (session 64: spinlock seed 1->0 in VdInitializeEngines + host-side kernel-wrapper identity map). game runs 10+ min in loading screens, zero crashes. see docs/BOOT_HANDOFF.md + docs/handoffs/ for the live trail.

## building

needs vs 2022 buildtools (vcvars64), cmake 3.25+, ninja, clang-cl for both c n c++. delete the build folder when switching compilers

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

zero game code or assets live in this repo. u bring ur own legally dumped copy of midnight club la (xbox 360) n the toolchain consumes that. nothing from the disc is hosted or distributed here, same rules xenia n unleashedrecomp play by.

## credits / influence

this wouldnt exist without these, go check em out:

- [UnleashedRecomp](https://github.com/hedge-dev/UnleashedRecomp) - the kernel framework here mirrors its structure exactly
- [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) - the ppc to c++ recompiler that generates everything in generated/
- [XenosRecomp](https://github.com/hedge-dev/XenosRecomp) - the xenos shader -> hlsl translator blueprint for the offline cache
- [Xenia](https://github.com/xenia-project/xenia) - the reference for xbox 360 kernel and gpu semantics
- [LARecomp](https://github.com/mzzvxm/larecomp) + [BadassBaboon/midnightclub](https://github.com/BadassBaboon/midnightclub) - other teams' mcla recompiles; proof the blockers are solvable + a pile of game-specific intel

much love from JO🇯🇴
abdullah atef alrawashdeh / HTU student
