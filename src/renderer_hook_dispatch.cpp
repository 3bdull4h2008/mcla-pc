#include "renderer_hook_dispatch.h"
#include "logging.h"

#include <array>
#include <mutex>

namespace mcla::renderer::hooks {
namespace {

constexpr size_t kMaxSubmitObservers = 8;
std::array<SubmitObserver, kMaxSubmitObservers> g_submitObservers{};
size_t g_submitObserverCount = 0;
std::mutex g_submitObserverMutex;

void RunObservers(const SubmitObserver* observers, size_t count,
                  mcla::native::PPCContext& ctx, uint8_t* base) {
    for (size_t i = 0; i < count; ++i) {
        observers[i](ctx, base);
    }
}

uint32_t g_testOrder = 0;

void TestObserverOne(mcla::native::PPCContext&, uint8_t*) {
    g_testOrder = g_testOrder * 10 + 1;
}

void TestObserverTwo(mcla::native::PPCContext&, uint8_t*) {
    g_testOrder = g_testOrder * 10 + 2;
}

}  // namespace

bool AddBeforeSubmitObserver(SubmitObserver observer) {
    if (!observer) return false;

    std::scoped_lock lock(g_submitObserverMutex);
    for (size_t i = 0; i < g_submitObserverCount; ++i) {
        if (g_submitObservers[i] == observer) return true;
    }
    if (g_submitObserverCount == g_submitObservers.size()) {
        MCLA_LOG_ERROR("Renderer submit observer capacity ({}) exhausted",
                     g_submitObservers.size());
        return false;
    }

    g_submitObservers[g_submitObserverCount++] = observer;
    return true;
}

void DispatchBeforeSubmit(mcla::native::PPCContext& ctx, uint8_t* base) {
    std::array<SubmitObserver, kMaxSubmitObservers> observers{};
    size_t count = 0;
    {
        std::scoped_lock lock(g_submitObserverMutex);
        count = g_submitObserverCount;
        for (size_t i = 0; i < count; ++i) observers[i] = g_submitObservers[i];
    }
    RunObservers(observers.data(), count, ctx, base);
}

size_t BeforeSubmitObserverCount() {
    std::scoped_lock lock(g_submitObserverMutex);
    return g_submitObserverCount;
}

bool VerifySubmitObserverOrderingForTests() {
    const std::array<SubmitObserver, 2> observers{TestObserverOne, TestObserverTwo};
    mcla::native::PPCContext context{};
    uint8_t dummyBase = 0;
    g_testOrder = 0;
    RunObservers(observers.data(), observers.size(), context, &dummyBase);
    return g_testOrder == 12;
}

}  // namespace mcla::renderer::hooks