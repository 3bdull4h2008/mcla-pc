# GPU Tooling MCP — MCLA Native PC GPU

## Purpose
Provides integration with GPU debugging and profiling tools (RenderDoc, PIX) for D3D12 capture analysis and performance optimization.

## RenderDoc MCP
- **Command**: `renderdoc-mcp.exe` (from `rdmcp-venv\Scripts\`)
- **Timeout**: 30s
- **Enabled**: true

### Available Tools (renderdoc_*)
| Tool | Description |
|------|-------------|
| `renderdoc_capture` | Capture a frame from running process |
| `renderdoc_analyze` | Analyze captured frame data |
| `renderdoc_get_drawcalls` | List all draw calls in capture |
| `renderdoc_get_pipeline_state` | Get pipeline state for draw call |
| `renderdoc_get_resources` | Get bound resources (textures, buffers) |
| `renderdoc_get_shaders` | Get shader bytecode and reflection |

## PIX MCP
- **Command**: `pix-mcp.exe`
- **Environment**: `PIXTOOL_PATH` pointing to `pixtool.exe`
- **Timeout**: 30s
- **Enabled**: true

### Available Tools (pix_*)
| Tool | Description |
|------|-------------|
| `pix_capture` | Capture GPU workload via PIX |
| `pix_analyze` | Analyze PIX capture |
| `pix_get_timing` | Get GPU timing data |
| `pix_get_memory` | Get memory allocation stats |
| `pix_get_shader_profiling` | Get shader profiling data |

## Usage Patterns
1. **Frame Capture**: Use `renderdoc_capture` or `pix_capture` on `build/mcla.exe`
2. **Draw Call Analysis**: Inspect native D3D12 draw calls vs Xenos command processor
3. **Shader Validation**: Compare Xenos microcode IR → HLSL output with captured shader bytecode
4. **Performance Profiling**: Use `pix_get_timing` and `pix_get_shader_profiling` for bottlenecks

## Best Practices
- Capture in `RelWithDebInfo` build for debug layer + symbols
- Use `--headless` mode for automated capture
- Correlate PIX GPU timing with Tracy CPU zones
- Export captures to `build/captures/` for CI regression

## Troubleshooting
- **RenderDoc not attaching**: Ensure `renderdoc.dll` is in PATH or use `RENDERDOC_INJECT=1`
- **PIX tool not found**: Verify `PIXTOOL_PATH` in MCP config matches installed PIX version
- **Capture empty**: Check D3D12 debug layer output for device removal/recreation