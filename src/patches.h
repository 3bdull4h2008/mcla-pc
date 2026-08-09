#pragma once
#include <rex/ppc/context.h>
#include <rex/system/function_dispatcher.h>

void mcla_ApplyPatches(rex::runtime::FunctionDispatcher* dispatcher);

// Overwrite an import-library JMP thunk ("jmp [rip+disp]") with a
// 12-byte "mov rax, imm64; jmp rax" detour and return the target of the
// original JMP (the real function in the DLL).  Generated recompiled code
// calls __imp__* imports via a DIRECT relative call to the thunk, which
// bypasses FunctionDispatcher::SetFunction; this detour intercepts all
// call paths.  Returns nullptr on failure.
PPCFunc* mcla_DetourImportThunk(uint8_t* thunk, PPCFunc* hook);

REX_FUNC(sub_82554080_stub);
REX_FUNC(hk_press_start_shim);
