@echo off
REM Use VS 2026 BuildTools for Windows SDK paths, but link against VS 2022 static runtime
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64
cmake --build build