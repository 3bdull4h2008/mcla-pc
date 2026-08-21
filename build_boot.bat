@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
ninja -C "E:\mcla pc\build" -v CMakeFiles/mcla.dir/src/boot_host.cpp.obj
