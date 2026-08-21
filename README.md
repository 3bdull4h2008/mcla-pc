# mcla-pc

<!-- hero clip goes here the day we have one. drop docs/hero.gif n uncomment
<p align="center">
  <img src="docs/hero.gif" alt="midnight club la running on pc through the native d3d12 pipeline">
</p>
-->

native d3d12 renderer rebuild for midnight club LA WIP

the idea: the recompiled ppc game code keeps running untouched, we capture render intent at the high level draw boundary n replay it as real d3d12 instead of letting the xenos command processor handle the gpu. legacy mode stays default until every gate passes.

## road map

| # | phase | what it means | status |
|---|-------|--------------|--------|
| 1 | abi migration | move everything onto the ppc_func abi with checked guest memory access | done |
| 2 | kernel framework | rebuild the kernel layer to match unleashedrecomp exactly - identity handles, typed arg hooks, lazy wrap | core done, blocked on msvc/clang-cl crt linkage |
| 3 | critical imports | implement the imports boot needs to reach a real present call | blocked on 2 |
| 4 | gpu context | vsync -> command buffer -> present chain firing on its own, no manual seeding | pending |
| 5 | draw capture | replace synthetic draws with real captured guest vertex/index data | pending |
| 6 | native default | renderer_mode=native becomes default, legacy path retired | pending |

plan summary: each phase has a hard gate with an offline validator proving it before moving on. no claiming anything works unless the validator says so.

## what exists rn

- standalone boot host linking the full recompiled image (46k+ function mappings), zero rexglue sdk
- xenos shader decode -> IR -> dxil translation pipeline
- d3d12 backend with pso cache
- offline validators for every phase gate
- boot gets through init into the game main loop

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
- `generated/` - recompiler output, input only, never edited by hand
- `third_party/` - sdl3, fmt, spdlog, toml++, dxc, simde

## legal

zero game code or assets live in this repo. u bring ur own legally dumped copy of midnight club la (xbox 360) n the toolchain consumes that. nothing from the disc is hosted or distributed here, same rules xenia n unleashedrecomp play by.

## credits / influence

this wouldnt exist without these, go check em out:

- [UnleashedRecomp](https://github.com/hedge-dev/UnleashedRecomp) - the kernel framework here mirrors its structure exactly
- [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) - the ppc to c++ recompiler that generates everything in generated/
- [Xenia](https://github.com/xenia-project/xenia) - the reference for xbox 360 kernel and gpu semantics

much love from JO🇯🇴
abdullah atef alrawashdeh / HTU student