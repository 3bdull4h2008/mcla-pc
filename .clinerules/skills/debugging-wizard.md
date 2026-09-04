---
name: debugging-wizard
description: Crash/stack-trace analysis for MCLA D3D12 renderer
---

# Debugging Wizard — MCLA Native PC GPU

## Purpose
Specialized debugging for D3D12 validation errors, device removal, shader compilation failures, and guest-memory corruption.

## Workflow
1. **Capture context**: D3D12 debug layer output, Tracy zone, guest address
2. **Classify failure**: Validation warning | Device removed | Shader error | OOB access
3. **Reproduce minimally**: Headless `--validate-shaders` mode, single frame
4. **Bisect**: Disable native path → legacy only → verify
5. **Root cause**: Trace to hook capture, translation, or backend

## Loop discipline (playbook T3 + plan §Loop Discipline)
- Max 3 failed hypotheses on one theory → mandatory bisection to last
  known-good run; 2 consecutive regressions → revert + record proven-negative.
- Guest park/stall (not a crash)? Route to `/mcla-stall-forensics` instead.
- End with a RUN receipt in the ledger: trigger | expect | observed | state | next.

## Key Tools
- D3D12 Debug Layer (enabled in RelWithDebInfo)
- Tracy zones for GPU work submission
- RenderDoc/PIX capture for frame analysis
- `ghidra_*` for guest memory forensics

## Common Patterns
| Symptom | Typical Cause |
|---------|---------------|
| `D3D12 ERROR: ID3D12CommandList::DrawInstanced` | Invalid VB/IB binding, stride mismatch |
| `DXGI_ERROR_DEVICE_REMOVED` | GPU timeout, TDR, resource lifetime |
| Shader compile fail | Xenos microcode decode error, IR mismatch |
| Guest OOB read | Hook reading past struct bounds, wrong endian |

## Validation Gates
- All D3D12 warnings treated as errors in CI
- `--validate-shaders --headless` must pass
- Zero security-auditor findings on guest-memory changes