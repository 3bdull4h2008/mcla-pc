@echo off
rem Configure + build ONLY the external texture-import validator.
rem Never touches mcla.exe, so it cannot race a boot session's link step.
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if errorlevel 1 exit /b 2
cd /d "E:\mcla pc"
cmake -S . -B build > build_texval_cfg.log 2>&1
if errorlevel 1 exit /b 3
ninja -C build texture_import_validator
exit /b %errorlevel%
