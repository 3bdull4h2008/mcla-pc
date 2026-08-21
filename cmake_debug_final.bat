@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if errorlevel 1 (
    echo vcvars64 failed with error %ERRORLEVEL%
    pause
    exit /b 2
)
cd /d "E:\mcla pc"
echo Running cmake...
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo 2>&1
echo CMake exited with code %ERRORLEVEL%
pause