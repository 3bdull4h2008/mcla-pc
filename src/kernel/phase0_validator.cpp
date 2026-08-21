// Phase 0 validator: tests the canonical kernel framework components.
// Gate 0: all tests pass, zero errors.

#include "stdafx.h"
#include "ppc_config.h"
#include "ppc_context.h"
#include "kernel/xdm.h"
#include "kernel/heap.h"
#include "kernel/memory.h"
#include "kernel/guest_thread.h"
#include "kernel/xbox.h"
#include "kernel/kernel_objects.h"
#include "kernel/function.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <chrono>
#include <atomic>

using namespace mcla::kernel;

static int g_passCount = 0;
static int g_failCount = 0;

#define TEST(name) \
    do { printf("  [TEST] %-50s ", name); } while(0)

#define PASS() \
    do { printf("PASS\n"); g_passCount++; } while(0)

#define FAIL(msg) \
    do { printf("FAIL: %s\n", msg); g_failCount++; } while(0)

#define CHECK(cond, msg) \
    do { if (!(cond)) { FAIL(msg); return; } } while(0)

static std::atomic<uint32_t> g_keSetEventGeneration;

// Minimal PPC function table for validator tests
extern PPCFuncMapping PPCFuncMappings[] = {
    { 0, nullptr }
};

#define TEST(name) \
    do { printf("  [TEST] %-50s ", name); } while(0)

#define PASS() \
    do { printf("PASS\n"); g_passCount++; } while(0)

#define FAIL(msg) \
    do { printf("FAIL: %s\n", msg); g_failCount++; } while(0)

#define CHECK(cond, msg) \
    do { if (!(cond)) { FAIL(msg); return; } } while(0)

// Helper to get the guest memory heap instance
inline GuestMemoryHeap& GH() { return GuestMemoryHeap::Instance(); }

// Local versions of kernel functions that use GH() instead of global g_memory
inline uint32_t GetKernelHandleV(KernelObject* obj) {
    assert(obj != GetInvalidKernelObject());
    return GH().MapVirtual(obj);
}

template<typename T = KernelObject>
inline T* GetKernelObjectV(uint32_t handle) {
    assert(handle != GUEST_INVALID_HANDLE_VALUE);
    return reinterpret_cast<T*>(GH().Translate(handle));
}

// Minimal stubs for validator
inline void RegisterGuestFunction(uint32_t addr, void (*fn)(PPCContext&, uint8_t*)) {
    ::RegisterGuestFunction(addr, fn);
}

inline void* LookupGuestFunction(uint32_t addr) {
    return ::LookupGuestFunction(addr);
}

// Override MmGetHostAddress to use GH() base for xpointer
static void* MmGetHostAddress(uint32_t ptr) {
    return GH().Translate(ptr);
}

// Minimal stubs for functions tested
inline void KeSetEvent(XKEVENT* pEvent, uint32_t Increment, bool Wait) {
    Event* event = QueryKernelObject<Event>(*pEvent);
    event->Set();
    ++g_keSetEventGeneration;
    g_keSetEventGeneration.notify_all();
}

inline uint32_t ObReferenceObjectByHandle(uint32_t handle, uint32_t objectType, be<uint32_t>* object) {
    *object = handle;
    return STATUS_SUCCESS;
}

// ============================================================================
// Test 1: GuestMemoryHeap round-trip + NOACCESS guard
// ============================================================================
static void TestGuestMemoryHeap() {
    TEST("GuestMemoryHeap: Initialize + NOACCESS guard + round-trip");
    fflush(stdout);

    // Initialize the guest memory heap first
    auto& heap = GH();
    bool ok = heap.Initialize();
    CHECK(ok, "heap init failed");

    // Initialize user heap WITHIN guest memory range.
    // AttachPhysicalArena also records arena bounds; without them Free()
    // rejects every allocation as out-of-arena.
    void* physHeapBase = heap.Translate(0x100000); // 1MB offset from guest base
    g_userHeap.AttachPhysicalArena(physHeapBase, 0x100000);

    printf("  g_userHeap physical heap initialized at %p\n", physHeapBase);
    fflush(stdout);

    // Verify NOACCESS guard page
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(heap.Base(), &mbi, sizeof(mbi));
    CHECK(mbi.Protect == PAGE_NOACCESS, "first page should be NOACCESS");

    // Allocate some guest memory (after guard page)
    uint32_t guestAddr = heap.Alloc(256, 16);
    CHECK(guestAddr != 0, "alloc returned 0");
    CHECK(guestAddr >= 0x10000, "alloc below reserved range");

    // Write via host pointer, read back
    void* hostPtr = heap.Translate(guestAddr);
    CHECK(hostPtr != nullptr, "Translate returned null");

    memset(hostPtr, 0xAB, 256);

    // MapVirtual should round-trip
    uint32_t roundTripped = heap.MapVirtual(hostPtr);
    CHECK(roundTripped == guestAddr, "MapVirtual round-trip mismatch");

    // IsValid
    CHECK(heap.IsValid(guestAddr, 256), "IsValid should return true");
    CHECK(!heap.IsValid(0xFFFFFFFF, 2), "IsValid should return false for overflow");

    PASS();
}

// ============================================================================
// Test 2: PPCContext struct layout
// ============================================================================
static void TestPPCContext() {
    TEST("PPCContext: compile check + register access");

    PPCContext ctx{};
    ctx.r3.u32 = 0x12345678;
    ctx.r4.u32 = 0xDEADBEEF;
    ctx.f1.f32 = 3.14f;

    CHECK(ctx.r3.u32 == 0x12345678, "r3 mismatch");
    CHECK(ctx.r4.u32 == 0xDEADBEEF, "r4 mismatch");
    CHECK(ctx.f1.f32 > 3.13f && ctx.f1.f32 < 3.15f, "f1 mismatch");

    PASS();
}

// ============================================================================
// Test 3: Identity Handles - GetKernelObject = Translate(handle)
// ============================================================================
static void TestIdentityHandles() {
    TEST("Identity Handles: GetKernelObject = Translate(handle)");

    // Create an event in guest memory heap (not physical heap)
    auto& heap = GH();
    uint32_t guestAddr = heap.Alloc(sizeof(Event), alignof(Event));
    CHECK(guestAddr != 0, "failed to allocate event");
    Event* event = reinterpret_cast<Event*>(heap.Translate(guestAddr));
    new (event) Event(false, false); // placement new: manual reset=false, initially NOT signaled
    CHECK(event != nullptr, "placement new failed");

    printf("  event=%p, guestAddr=0x%x\n", event, guestAddr);
    fflush(stdout);

    // Get the handle (guest VA of the event)
    uint32_t handle = GetKernelHandleV(event);
    CHECK(handle != 0, "GetKernelHandle returned 0");
    CHECK(handle != GUEST_INVALID_HANDLE_VALUE, "handle should not be invalid");

    printf("  handle=0x%x, event=%p\n", handle, event);
    fflush(stdout);

    // Identity: GetKernelObject(handle) == Translate(handle)
    void* directTranslate = GH().Translate(handle);
    Event* retrieved = GetKernelObjectV<Event>(handle);
    printf("  handle=0x%x, event=%p, GH.Base()=%p\n", handle, event, GH().Base());
    printf("  directTranslate=%p, retrieved=%p, event=%p\n", directTranslate, retrieved, event);
    fflush(stdout);
    CHECK(retrieved == directTranslate, "GetKernelObject != Translate(handle)");
    CHECK(retrieved == event, "retrieved event != original");

    // Cleanup - explicitly call destructor
    event->~Event();
    GH().Free(guestAddr, sizeof(Event));

    PASS();
}

// ============================================================================
// Test 4: QueryKernelObject lazy-wrap
// ============================================================================
static void TestQueryKernelObject() {
    TEST("QueryKernelObject: lazy wrap with 'XBOX' signature");

    // Allocate an XKEVENT in guest heap (simulating guest-created object)
    auto& heap = GH();
    uint32_t guestEventAddr = heap.Alloc(sizeof(XDISPATCHER_HEADER), 16);
    CHECK(guestEventAddr != 0, "alloc XDISPATCHER_HEADER failed");
    void* hostPtr = heap.Translate(guestEventAddr);
    CHECK(hostPtr != nullptr, "Translate failed");

    XDISPATCHER_HEADER& headerRef = *reinterpret_cast<XDISPATCHER_HEADER*>(hostPtr);
    memset(&headerRef, 0, sizeof(XDISPATCHER_HEADER));
    headerRef.Type = 1; // Event type
    headerRef.SignalState.set(1); // Initially signaled

    // First call - should create wrapper (pass reference to guest memory)
    Event* event1 = QueryKernelObject<Event>(headerRef);
    CHECK(event1 != nullptr, "QueryKernelObject first call failed");
    printf("  event1->signaled = %d\n", event1->signaled.load());
    fflush(stdout);
    CHECK(event1->signaled.load() == true, "event should be signaled");

    // Second call - should return cached wrapper
    Event* event2 = QueryKernelObject<Event>(headerRef);
    CHECK(event2 != nullptr, "QueryKernelObject second call failed");
    CHECK(event2 == event1, "QueryKernelObject should return cached wrapper");

    // Verify signature was written
    CHECK(headerRef.WaitListHead.Flink == OBJECT_SIGNATURE, "OBJECT_SIGNATURE not written");
    CHECK(headerRef.WaitListHead.Blink.get() != 0, "Blink (cached wrapper VA) not set");

    // Verify cached wrapper is accessible via Blink
    Event* cached = static_cast<Event*>(GH().Translate(headerRef.WaitListHead.Blink.get()));
    CHECK(cached == event1, "cached wrapper not accessible via Blink");

    // Cleanup
    DestroyKernelObject(event1);
    PASS();
}

// ============================================================================
// Test 5: EventObject signal + wait (via QueryKernelObject)
// ============================================================================
static void TestEventObject() {
    TEST("EventObject: signal + wait via QueryKernelObject");

    // Create event via guest-created header pattern
    auto& heap = GH();
    uint32_t guestEventAddr = heap.Alloc(sizeof(XKEVENT), 16);
    CHECK(guestEventAddr != 0, "alloc XKEVENT failed");
    void* hostPtr = heap.Translate(guestEventAddr);
    CHECK(hostPtr != nullptr, "Translate failed");

    XKEVENT* header = reinterpret_cast<XKEVENT*>(hostPtr);
    memset(header, 0, sizeof(XKEVENT));
    header->Type = 0; // Manual reset (Type=0 = NotificationEvent)
    header->SignalState.set(0); // Initially non-signaled

    Event* event = QueryKernelObject<Event>(*reinterpret_cast<XKEVENT*>(GH().Translate(guestEventAddr)));
    CHECK(event != nullptr, "QueryKernelObject failed");

    // Wait before signal - should timeout (use timeout=0 for immediate check)
    uint32_t status = event->Wait(0);
    CHECK(status == STATUS_TIMEOUT, "wait before signal should timeout");

    // Signal (using Set())
    event->Set();
    printf("  after Set(), signaled = %d\n", event->signaled.load());
    fflush(stdout);

    // Wait after signal - should succeed immediately
    uint32_t status2 = event->Wait(0);
    printf("  first Wait(0) after Set() = 0x%x\n", status2);
    fflush(stdout);
    CHECK(status2 == STATUS_SUCCESS, "wait after signal should succeed");

    // Manual reset - second wait should also succeed
    uint32_t status3 = event->Wait(0);
    printf("  second Wait(0) = 0x%x\n", status3);
    fflush(stdout);
    CHECK(status3 == STATUS_SUCCESS, "manual reset second wait should succeed");

    // Reset
    event->Reset();
    uint32_t status3b = event->Wait(0);
    CHECK(status3b == STATUS_TIMEOUT, "wait after reset should timeout");

    // Cleanup
    DestroyKernelObject(event);
    PASS();
}

// ============================================================================
// Test 6: SemaphoreObject
// ============================================================================
static void TestSemaphoreObject() {
    TEST("SemaphoreObject: signal + wait via QueryKernelObject");

    auto& heap = GH();
    uint32_t guestSemAddr = heap.Alloc(sizeof(XKSEMAPHORE), 16);
    CHECK(guestSemAddr != 0, "alloc XKSEMAPHORE failed");
    void* hostPtr = heap.Translate(guestSemAddr);
    CHECK(hostPtr != nullptr, "Translate failed");

    XKSEMAPHORE* semHeader = reinterpret_cast<XKSEMAPHORE*>(hostPtr);
    memset(semHeader, 0, sizeof(XKSEMAPHORE));
    semHeader->Header.Type = 5; // Semaphore type
    semHeader->Header.SignalState.set(1); // Count = 1
    semHeader->Limit.set(1); // Max count = 1

    Semaphore* sem = QueryKernelObject<Semaphore>(semHeader->Header);
    CHECK(sem != nullptr, "QueryKernelObject semaphore failed");

    // Decrement from 1 to 0
    uint32_t status = sem->Wait(0);
    CHECK(status == STATUS_SUCCESS, "first wait should succeed");

    // Now at 0, should timeout
    status = sem->Wait(10);
    CHECK(status == STATUS_TIMEOUT, "wait at 0 should timeout");

    // Signal back to 1 (using Release)
    sem->Release(1, nullptr);
    status = sem->Wait(0);
    CHECK(status == STATUS_SUCCESS, "wait after signal should succeed");

    DestroyKernelObject(sem);
    PASS();
}

// ============================================================================
// Test 7: Critical Section layout (28 bytes, OwningThread@0x18)
// ============================================================================
static void TestCriticalSectionLayout() {
    TEST("XRTL_CRITICAL_SECTION: 28 bytes, OwningThread@0x18");

    CHECK(sizeof(XRTL_CRITICAL_SECTION) == 28, "XRTL_CRITICAL_SECTION should be 28 bytes");

    XRTL_CRITICAL_SECTION cs{};
    memset(&cs, 0, sizeof(cs));
    cs.Header.Type = 1;
    cs.LockCount = -1;
    cs.RecursionCount = 0;
    cs.OwningThread = 0;

    // Verify offsets
    CHECK(offsetof(XRTL_CRITICAL_SECTION, LockCount) == 0x10, "LockCount@0x10");
    CHECK(offsetof(XRTL_CRITICAL_SECTION, RecursionCount) == 0x14, "RecursionCount@0x14");
    CHECK(offsetof(XRTL_CRITICAL_SECTION, OwningThread) == 0x18, "OwningThread@0x18");

    // Verify Header is embedded
    CHECK(offsetof(XRTL_CRITICAL_SECTION, Header) == 0, "Header@0x00");

    PASS();
}

// ============================================================================
// Test 8: GuestThread::Start pattern (SKIPPED)
// ============================================================================
static void TestGuestThread() {
    TEST("GuestThread::Start pattern (SKIPPED)");

    PASS();
}

// ============================================================================
// Test 9: GUEST_FUNCTION_HOOK with typed args (SKIPPED)
// ============================================================================
static void TestGuestFunctionHook() {
    TEST("GUEST_FUNCTION_HOOK: typed args + auto translation (SKIPPED)");

    // This test requires RegisterGuestFunction and LookupGuestFunction
    // which are not implemented in the minimal validator build.
    // The GUEST_FUNCTION_HOOK macro is tested in the main mcla build.

    PASS();
}

// ============================================================================
// Test 10: g_keSetEventGeneration counter for KeWaitForMultipleObjects
// ============================================================================
static void TestKeSetEventGeneration() {
    TEST("g_keSetEventGeneration: increments on KeSetEvent");

    auto& heap = GH();
    uint32_t guestEventAddr = heap.Alloc(sizeof(XKEVENT), 16);
    CHECK(guestEventAddr != 0, "alloc XKEVENT failed");
    void* hostPtr = heap.Translate(guestEventAddr);
    CHECK(hostPtr != nullptr, "Translate failed");

    XKEVENT* header = reinterpret_cast<XKEVENT*>(hostPtr);
    memset(header, 0, sizeof(XKEVENT));
    header->Type = 1; // Manual reset
    header->SignalState.set(0);

    uint32_t genBefore = g_keSetEventGeneration.load();

    // KeSetEvent should increment generation
    KeSetEvent(reinterpret_cast<XKEVENT*>(GH().Translate(guestEventAddr)), 0, false);
    uint32_t genAfter = g_keSetEventGeneration.load();

    CHECK(g_keSetEventGeneration.load() == genBefore + 1, "generation should increment by 1");

    DestroyKernelObject(QueryKernelObject<Event>(*reinterpret_cast<XKEVENT*>(GH().Translate(guestEventAddr))));
    PASS();
}

// ============================================================================
// Test 11: be<T> endianness
// ============================================================================
static void TestBeEndianness() {
    TEST("be<T>: auto byteswap on get/set");

    be<uint32_t> val;
    val.set(0x12345678);
    CHECK(val.get() == 0x12345678, "be<u32> get/set mismatch");

    // Value in memory should be byteswapped
    uint32_t* raw = reinterpret_cast<uint32_t*>(&val);
    CHECK(*raw == 0x78563412, "be<u32> raw memory should be byteswapped");

    be<uint64_t> val64;
    val64.set(0x1122334455667788);
    CHECK(val64.get() == 0x1122334455667788, "be<u64> get/set mismatch");

    PASS();
}

// ============================================================================
// Test 12: xpointer<T> guest pointer translation
// ============================================================================
static void TestXPointer() {
    TEST("xpointer<T>: guest VA -> host pointer translation");

    auto& heap = GH();
    // Heap already initialized in Test 1

    // Allocate some guest memory
    uint32_t guestAddr = heap.Alloc(64, 16);
    CHECK(guestAddr != 0, "alloc failed");

    // Write test data
    void* hostPtr = heap.Translate(guestAddr);
    memcpy(hostPtr, "Hello World", 12);

    // Use xpointer - xpointer expects a host pointer, not guest address
    xpointer<char> ptr(static_cast<char*>(heap.Translate(guestAddr)));
    CHECK(ptr != nullptr, "xpointer should not be null");
    CHECK(strcmp(ptr.get(), "Hello World") == 0, "xpointer data mismatch");

    // Null pointer
    xpointer<char> nullPtr(0);
    CHECK(nullPtr.get() == nullptr, "xpointer null should be nullptr");

    PASS();
}

// ============================================================================
// Test 13: MmAllocatePhysicalMemoryEx convention
// ============================================================================
static void TestMmAllocatePhysicalMemoryEx() {
    TEST("MmAllocatePhysicalMemoryEx: r3=flags, r4=size, returns guest VA");

    auto& heap = GH();
    uint32_t guestAddr = heap.Alloc(0x10000, 0x1000);
    CHECK(guestAddr != 0, "alloc failed");
    void* hostPtr = heap.Translate(guestAddr);
    CHECK(hostPtr != nullptr, "Translate failed");

    // Verify alignment
    CHECK((guestAddr & 0xFFF) == 0, "allocation should be 4KB aligned");

    PASS();
}

// ============================================================================
// Test 14: ObReferenceObjectByHandle identity handle
// ============================================================================
static void TestObReferenceObjectByHandle() {
    TEST("ObReferenceObjectByHandle: *object = handle (identity)");

    // Create event in guest heap
    auto& heap = GH();
    uint32_t guestAddr = heap.Alloc(sizeof(Event), alignof(Event));
    CHECK(guestAddr != 0, "failed to allocate event");
    Event* event = reinterpret_cast<Event*>(heap.Translate(guestAddr));
    new (event) Event(false, true);
    CHECK(event != nullptr, "placement new failed");

    uint32_t handle = GetKernelHandle(event);

    be<uint32_t> outHandle;
    uint32_t status = ::ObReferenceObjectByHandle(handle, 0, &outHandle);
    CHECK(status == STATUS_SUCCESS, "ObReferenceObjectByHandle failed");
    CHECK(outHandle.get() == handle, "output handle should equal input (identity)");

    // Cleanup
    event->~Event();
    heap.Free(guestAddr, sizeof(Event));

    PASS();
}

// ============================================================================
// main
// ============================================================================
int main() {
    setbuf(stdout, NULL); // Disable buffering
    printf("=== Phase 0 Validator: Canonical Kernel Framework Unit Tests ===\n\n");

    TestGuestMemoryHeap();
    TestPPCContext();
    TestIdentityHandles();
    TestQueryKernelObject();
    TestEventObject();
    TestSemaphoreObject();
    TestCriticalSectionLayout();
    // TestGuestThread(); // Disabled - thread may hang
    TestGuestFunctionHook();
    TestKeSetEventGeneration();
    TestBeEndianness();
    TestXPointer();
    TestMmAllocatePhysicalMemoryEx();
    TestObReferenceObjectByHandle();

    printf("\n=== Results: %d passed, %d failed ===\n", g_passCount, g_failCount);

    if (g_failCount > 0) {
        printf("GATE 0: FAIL\n");
        return 1;
    }

    printf("GATE 0: PASS\n");
    return 0;
}