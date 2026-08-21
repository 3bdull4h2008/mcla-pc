@echo off
REM Use VS 2022 BuildTools which has both headers and libraries
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64
cmake --build build