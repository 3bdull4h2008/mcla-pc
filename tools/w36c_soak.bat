@echo off
setlocal
set REXE="E:\mcla pc\tools\rexec.exe"
set TMPDIR=%TEMP%\mcla-w36c

:: Run for 120s
echo Starting 120s soak...
%REXE% --timeout 120 --output "%TMPDIR%" "E:\mcla pc\build\mcla.exe" 2>&1

:: Report
echo.
echo === W36c SOAK REPORT ===
echo File count: 
dir "%TMPDIR%\*.rex" /b 2>nul | find /c /v ""
echo.
