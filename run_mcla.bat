@echo off
cd /d "%~dp0build"
if not exist "cache\mcla.toml" (
  echo renderer_mode = native> "cache\mcla.toml"
)
echo Starting MCLA (native D3D12). Close the window or Ctrl+C to quit.
mcla.exe
