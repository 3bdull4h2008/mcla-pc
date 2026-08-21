# mcla-pc

native d3d12 renderer rebuild for midnight club la.

the recompiled ppc code keeps running like normal, but instead of letting the old xenos command processor do all the gpu work, we catch the draw intent at a high level boundary n run it as proper native d3d12. legacy mode is still default until everything passes the phase gates, so dont panic if it looks like nothing changed at first lol

## wut it does rn

- boot path runs standalone (no rexglue runtime needed anymore)
- pm4 capture hooks on the draw boundary
- xenos microcode -> IR -> dxil shader translation pipeline
- texture + vertex decoding
- guest memory access with bounds checks (no raw pointer crimes)

## building

needs vs2022 or vs2026, cmake 3.25+, ninja n clang-cl

```
configure.bat
cmake --build build
build/mcla.exe
```

## repo layout (short version)

- `src/` - app, hooks, d3d12 backend, kernel/cpu/apu stuff
- `src/renderer/` - shader translation, caches, decoders
- `generated/` - recompiler output, dont touch this, its input not source
- `third_party/` - sdl3, fmt, spdlog, toml++, dxc

## status

work in progress, phase 2 era. check the plans folder... ok there is no plans folder here u didnt see anything

lets go homie
