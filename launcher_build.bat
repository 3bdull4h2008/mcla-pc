@echo off
call "E:\mcla pc\ninja_build.bat" > "E:\mcla pc\build_out.txt" 2>&1
echo EXIT=%ERRORLEVEL% >> "E:\mcla pc\build_out.txt"
