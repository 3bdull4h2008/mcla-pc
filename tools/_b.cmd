@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
cmake --build build 2>&1 | findstr /i "error"
echo BUILD_EXIT=%ERRORLEVEL%
