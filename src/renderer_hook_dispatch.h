#pragma once

#include <cstddef>

#include <rex/ppc/context.h>

namespace mcla::renderer::hooks {

// Observers are called before the sole owner of GfxCmdBufSubmit chains to the
// generated PPC function. They must not alter the call chain.
using SubmitObserver = void (*)(::PPCContext& ctx, uint8_t* base);

bool AddBeforeSubmitObserver(SubmitObserver observer);
void DispatchBeforeSubmit(::PPCContext& ctx, uint8_t* base);
size_t BeforeSubmitObserverCount();

// A tiny self-test used by the debug startup assertion and available to a
// focused unit-test target if one is added later.
bool VerifySubmitObserverOrderingForTests();

}  // namespace mcla::renderer::hooks
