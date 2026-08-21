# mcla-pc

native d3d12 renderer rebuild for midnight club la + proof that the recompiled xbox 360 code can boot n run on pc.

how it works: the recompiled ppc game code keeps running like normal, we capture the render intent at the high level draw boundary n replay it as proper native d3d12. no more xenos command processor doing the gpu work. legacy mode stays the default until every phase gate passes, thats the rule.

## where its at (from the rebuild plan)

- **phase 1 - abi migration** - done. everything moved to the ppc_func abi with checked guest memory access
- **phase 2 - kernel framework** - core done, rebuilt to match the unleashedrecomp canonical framework exactly (identity handles, typed arg hooks, lazy wrap, the whole thing). currently blocked on a crt linkage fight between msvc n clang-cl objects
- **phase 3 - critical imports** - blocked on 2, waiting
- **phase 4 - gpu context n present chain** - pending
- **phase 5 - real vertex/index capture** - pending (draws rn are synthetic only)
- **phase 6 - native goes default, legacy retires** - pending

boot status so far: guest code gets all the way through init into the game main loop, which is already kinda crazy. not claiming anything deeper than what the gates prove tho.

## wut exists rn

- standalone boot host, links the full recompiled image (46k+ function mappings), zero rexglue sdk
- xenos shader decode -> IR -> dxil translation pipeline
- d3d12 backend (device, pso cache, synthetic triangle gang)
- a validator exe for basically every phase gate so nothing gets claimed without proof

## building

needs vs buildtools (vcvars64), cmake 3.25+, ninja, n clang-cl for BOTH c n c++. delete the build folder if u switch compilers, it will haunt u otherwise

```
configure.bat
ninja_build.bat
build\mcla.exe
```

## repo layout

- `src/kernel`, `src/cpu`, `src/apu`, `src/user` - kernel framework n guest runtime
- `src/renderer` - xenos decode, shader translation, texture/vertex decoding, caches
- `generated/` - recompiler output. its INPUT not source, nobody touches this
- `third_party/` - sdl3, fmt, spdlog, toml++, dxc, simde. no rexglue, it got banned

wip, phase 2 era. lets go homie
