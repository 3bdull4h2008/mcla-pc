#pragma once

#include <cstddef>
#include "app.h"

namespace mcla::renderer::hooks {

using SubmitObserver = void (*)(mcla::native::PPCContext& ctx, uint8_t* base);

bool AddBeforeSubmitObserver(SubmitObserver observer);
void DispatchBeforeSubmit(mcla::native::PPCContext& ctx, uint8_t* base);
size_t BeforeSubmitObserverCount();

bool VerifySubmitObserverOrderingForTests();

}  // namespace mcla::renderer::hooks