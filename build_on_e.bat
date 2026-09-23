@echo off
rem Build on the E: volume (primary tree since the 09-23 merge).
rem Mirrors build_on_c.bat but with E: paths. rc 2=vcvars, 3=configure.
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if errorlevel 1 exit /b 2
cd /d "E:\mcla pc"
if "%1"=="build" goto build
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo > build_cfg.log 2>&1
if errorlevel 1 exit /b 3
:build
ninja -C build mcla.exe > build_ninja.log 2>&1
exit /b %errorlevel%
