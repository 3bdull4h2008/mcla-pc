#pragma once

#include <cpu/ppc_context.h>
#include <array>
#include <atomic>
#include <cstring>
#include "xbox.h"
#include "memory.h"
#include <logging.h>

// ===========================================================================
// CALL-ABI CONTRACT (F-611) - read before adding a host->guest entry point.
//
// This build makes the recompiler treat CTR, XER, the reservation register,
// CR0-7, r0/r2/r11/r12, r14-r31, f0, f14-f31 and v14-v127 as zero-initialised
// FUNCTION-LOCALS that never travel in PPCContext: config/mcla_xenonrecomp.toml
// :15-20 sets ctr/xer/reserved/cr/non_argument/non_volatile _as_local, which
// makes recompiler.cpp:2608-2631 emit `PPCRegister ctr{}; PPCCRRegister cr0{};
// PPCRegister r14{}; ...` ahead of every function body and makes
// .research/XenonRecomp/XenonUtils/ppc_context.h:307-344 / :350-371 / :390-444
// delete the matching PPCContext members. What survives in PPCContext - and
// therefore what a host-initiated entry MUST supply - is exactly:
//
//   r1       guest stack pointer (callee frame, 8-byte aligned)
//   r13      thread-context / PCR base (TLS at r13+0, TEB at r13+0x100)
//   r3..r10 integer args 1..8 (r3 is also the return slot)
//   f1..f13  double args 1..13
//   v0..v13  vector args 1..14
//   lr       link register (see below)
//   msr      0x200A000 by default: FP+VMX enabled
//   fpscr    FP status, read-modify-write across the call
//
// `blr` is emitted as a plain `return;` (recompiler.cpp:863-865) and `bl` as
// `ctx.lr = base+4; target(ctx,base);` (:848-853), so the C++ frame IS the
// return path and a guest `blr` never reads ctx.lr. lr is carried anyway:
// `mflr` compiles to a load of ctx.lr and `savegprlr 14` (toml:6-7) stores it
// into guest memory, so an indeterminate lr at a host-initiated entry writes
// host stack garbage into the guest stack, and a later `restgprlr 14` promotes
// that same garbage to a return address.
//
// Every context this file creates is VALUE-initialised, because the
// non-argument members above (r4..r10, f1..f13, v0..v13, lr) are otherwise
// indeterminate: a default-initialised `PPCContext` gives the callee whatever
// was in this frame's stack memory. The previous "NOTE: No need for zero
// initialization, has lots of unnecessary code generation" was wrong on both
// counts - with the *_as_local config there is little left to zero, and
// correctness of every host-initiated entry depends on it.
//
// The NOT-carried registers (ctr, xer, reserved, cr0-7, r0/r2/r11/r12, r14-r31,
// f0, f14-f31, v14-v127) read as zero at a host-initiated entry, which is
// exactly what the recompiled guest sees when IT calls the function. That is
// wrong only where the callee reads a register the ABI says its CALLER
// initialised - for a guest entry point that is a callee bug, not a host
// obligation. Concretely: a host entry cannot hand a callee a CTR set by a
// `mtctr` the host never executed, and must not expect one.
// ===========================================================================

template <typename R, typename... T>
constexpr std::tuple<T...> function_args(R(*)(T...)) noexcept
{
    return std::tuple<T...>();
}

template<auto V>
static constexpr decltype(V) constant_v = V;

template<typename T>
static constexpr bool is_precise_v = std::is_same_v<T, float> || std::is_same_v<T, double>;

template<auto Func>
struct arg_count_t
{
    static constexpr size_t value = std::tuple_size_v<decltype(function_args(Func))>;
};

template<typename TCallable, int I = 0, typename ...TArgs>
std::enable_if_t<(I >= sizeof...(TArgs)), void> _tuple_for(std::tuple<TArgs...>&, const TCallable& callable) noexcept
{

}

template<typename TCallable, int I = 0, typename ...TArgs>
std::enable_if_t<(I < sizeof...(TArgs)), void> _tuple_for(std::tuple<TArgs...>& tpl, const TCallable& callable) noexcept
{
    callable(std::get<I>(tpl), I);

    _tuple_for<TCallable, I + 1>(tpl, callable);
}

struct ArgTranslator
{
    // ---- checked guest-memory primitives (F-611) ---------------------------
    // Everything below used to be a raw `reinterpret_cast` on `base + guestVa`.
    // The guest window is 4 GiB of host VirtualAlloc (memory.h:13-15), so that
    // is an unchecked read/write at an address the GUEST chose; the first 4 KiB
    // is a deliberate PAGE_NOACCESS null guard (memory.cpp:316-322, the F-122
    // lesson) that a raw cast walks straight into. All guest access now goes
    // through GuestMemoryHeap: IsValid() for the range (which also rejects the
    // guard) and the endian-explicit Read/WriteU32BE for the payload.
    static bool IsGuestVa(uint32_t va, size_t size) noexcept
    {
        return mcla::kernel::GuestMemoryHeap::Instance().IsValid(va, size);
    }

    static bool ReadGuestU32(uint32_t va, uint32_t* out) noexcept
    {
        if (!out)
            return false;

        return mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(va, out);
    }

    static bool WriteGuestU32(uint32_t va, uint32_t value) noexcept
    {
        return mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(va, value);
    }

    // Guest VA -> host pointer, checked. Returns nullptr for NULL, for the
    // null guard, and for anything outside the window. This replaces
    // `reinterpret_cast<T>(base + v)`: that expression produced a host pointer
    // INSIDE the window for a guest VA of 0x8FFFFFFF and a wild pointer
    // entirely outside it for anything larger, and handed both to the host
    // function as if they were valid.
    static void* GuestPtr(uint32_t va) noexcept
    {
        if (!IsGuestVa(va, 1))
            return nullptr;

        return mcla::kernel::GuestMemoryHeap::Instance().Translate(va);
    }

    // Host pointer -> guest VA, checked in BOTH directions. `Memory::MapVirtual`
    // (memory.h:163-168) asserts IsInMemoryRange and then subtracts anyway, so
    // out of release builds a foreign pointer became a wrapped VA.
    static uint32_t HostPtrToGuestVa(const void* host) noexcept
    {
        if (!host)
            return 0;

        if (!mcla::kernel::g_memory.IsInMemoryRange(host))
        {
            static std::atomic<uint32_t> s_oobRet{0};
            const uint32_t n = s_oobRet.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 8 || (n % 1000) == 0)
                MCLA_LOG_WARN("F611-RET-OOB #{} host={} base={} - returning guest "
                              "NULL instead of a wrapped VA",
                              n, host, static_cast<const void*>(mcla::kernel::g_memory.base));
            return 0;
        }

        return mcla::kernel::g_memory.MapVirtual(host);
    }

    // Stack-passed integer argument (the 9th and beyond). The guest caller
    // pushes these above its own frame, so the callee-visible slot is
    // r1 + 0x54 + (arg-8)*8 by this header's ABI assumption; computed in 64-bit
    // so a hostile r1 cannot wrap the sum back into the window. MEASURED
    // 2026-09-28: the widest GUEST_FUNCTION_HOOK target in the tree takes 4
    // parameters (NetDll_send/NetDll_recv, imports.cpp:3526/3518), so this path
    // is unreachable for every hook registered today - it is kept correct
    // rather than deleted so the first 9-argument import is not a wild read.
    static uint32_t StackArgVa(const PPCContext& ctx, size_t arg) noexcept
    {
        const uint64_t va = static_cast<uint64_t>(ctx.r1.u32) + 0x54 +
                            (static_cast<uint64_t>(arg - 8) * 8);
        return va <= 0xFFFFFFFFull ? static_cast<uint32_t>(va) : 0;
    }

    static uint64_t GetIntegerArgumentValue(const PPCContext& ctx, uint8_t* base, size_t arg) noexcept
    {
        if (arg <= 7)
        {
            switch (arg)
            {
                case 0: return ctx.r3.u32;
                case 1: return ctx.r4.u32;
                case 2: return ctx.r5.u32;
                case 3: return ctx.r6.u32;
                case 4: return ctx.r7.u32;
                case 5: return ctx.r8.u32;
                case 6: return ctx.r9.u32;
                case 7: return ctx.r10.u32;
                default: break;
            }
        }

        const uint32_t va = StackArgVa(ctx, arg);
        uint32_t value = 0;
        if (va != 0 && ReadGuestU32(va, &value))
            return value;

        // Unreachable for every hook registered today (see StackArgVa). Named
        // rather than asserted: a guest that hands us a bogus r1 must not take
        // the host down, and the log says which slot could not be read.
        static std::atomic<uint32_t> s_badStackArg{0};
        const uint32_t n = s_badStackArg.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 1000) == 0)
            MCLA_LOG_WARN("F611-STACKARG-READ #{} arg={} r1={:08X} va={:08X} "
                          "base={} - passing 0",
                          n, arg, static_cast<uint32_t>(ctx.r1.u32), va,
                          static_cast<const void*>(base));
        return 0;
    }

    static double GetPrecisionArgumentValue(const PPCContext& ctx, uint8_t* base, size_t arg) noexcept
    {
        switch (arg)
        {
            case 0: return ctx.f1.f64;
            case 1: return ctx.f2.f64;
            case 2: return ctx.f3.f64;
            case 3: return ctx.f4.f64;
            case 4: return ctx.f5.f64;
            case 5: return ctx.f6.f64;
            case 6: return ctx.f7.f64;
            case 7: return ctx.f8.f64;
            case 8: return ctx.f9.f64;
            case 9: return ctx.f10.f64;
            case 10: return ctx.f11.f64;
            case 11: return ctx.f12.f64;
            case 12: return ctx.f13.f64;
            [[unlikely]] default: break;
        }

        // 14th FP argument and beyond: the guest puts FP stack arguments below
        // the integer ones, so this is the integer slot of arg+8 read as a BE
        // double. Measured 2026-09-28: no registered hook takes more than 4
        // parameters, so this is dead today; it is implemented (not left as a
        // silent 0) so the first 14-FP-argument import is not a silent zero.
        const uint32_t va = StackArgVa(ctx, arg + 8);
        uint64_t bits = 0;
        if (va != 0 && mcla::kernel::GuestMemoryHeap::Instance().IsValid(va, 8) &&
            mcla::kernel::GuestMemoryHeap::Instance().ReadU64BE(va, &bits))
        {
            double d = 0;
            std::memcpy(&d, &bits, sizeof(d));
            return d;
        }

        static std::atomic<uint32_t> s_badFpGet{0};
        const uint32_t n = s_badFpGet.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 1000) == 0)
            MCLA_LOG_WARN("F611-FPSTACKARG-READ #{} arg={} r1={:08X} va={:08X} - "
                          "passing 0",
                          n, arg, static_cast<uint32_t>(ctx.r1.u32), va);
        return 0;
    }

    static void SetIntegerArgumentValue(PPCContext& ctx, uint8_t* base, size_t arg, uint64_t value) noexcept
    {
        if (arg <= 7)
        {
            switch (arg)
            {
                case 0: ctx.r3.u64 = value; return;
                case 1: ctx.r4.u64 = value; return;
                case 2: ctx.r5.u64 = value; return;
                case 3: ctx.r6.u64 = value; return;
                case 4: ctx.r7.u64 = value; return;
                case 5: ctx.r8.u64 = value; return;
                case 6: ctx.r9.u64 = value; return;
                case 7: ctx.r10.u64 = value; return;
                [[unlikely]] default: break;
            }
        }

        // The 9th integer argument and beyond live in the guest's own frame
        // area, so they are stored through the same checked, endian-explicit
        // path the reader uses (mirrored slot, see StackArgVa). The old
        // `assert(arg < 7 && ...)` was unreachable-when-true: this branch is
        // only reached with arg >= 8, so the condition is always false, which
        // under the build's /DNDEBUG (compile_commands.json) meant the argument
        // was silently DROPPED and the host callee ran on a stale register.
        const uint32_t va = StackArgVa(ctx, arg);
        if (va != 0 && WriteGuestU32(va, static_cast<uint32_t>(value)))
            return;

        static std::atomic<uint32_t> s_badStackPush{0};
        const uint32_t n = s_badStackPush.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 1000) == 0)
            MCLA_LOG_WARN("F611-STACKARG-WRITE #{} arg={} r1={:08X} va={:08X} - "
                          "argument NOT delivered to the guest",
                          n, arg, static_cast<uint32_t>(ctx.r1.u32), va);
    }

    static void SetPrecisionArgumentValue(PPCContext& ctx, uint8_t* base, size_t arg, double value) noexcept
    {
        switch (arg)
        {
            case 0: ctx.f1.f64 = value; return;
            case 1: ctx.f2.f64 = value; return;
            case 2: ctx.f3.f64 = value; return;
            case 3: ctx.f4.f64 = value; return;
            case 4: ctx.f5.f64 = value; return;
            case 5: ctx.f6.f64 = value; return;
            case 6: ctx.f7.f64 = value; return;
            case 7: ctx.f8.f64 = value; return;
            case 8: ctx.f9.f64 = value; return;
            case 9: ctx.f10.f64 = value; return;
            case 10: ctx.f11.f64 = value; return;
            case 11: ctx.f12.f64 = value; return;
            case 12: ctx.f13.f64 = value; return;
            [[unlikely]] default: break;
        }

        // The 14th FP argument and beyond. FP stack arguments sit BELOW the
        // integer ones in the EABI parameter save area (8 GPR slots, then 13
        // FPR slots), so this is the integer slot of arg+8 computed by
        // StackArgVa, widened to a BE double. The old `assert(arg < 12)` here
        // was also unreachable-true and, under the build's /DNDEBUG, silently
        // dropped the argument.
        const uint32_t va = StackArgVa(ctx, arg + 8);
        if (va != 0 && mcla::kernel::GuestMemoryHeap::Instance().IsValid(va, 8))
        {
            uint64_t bits = 0;
            static_assert(sizeof(bits) == sizeof(value));
            std::memcpy(&bits, &value, sizeof(bits));
            if (mcla::kernel::GuestMemoryHeap::Instance().WriteU64BE(va, bits))
                return;
        }

        static std::atomic<uint32_t> s_badFpPush{0};
        const uint32_t n = s_badFpPush.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 1000) == 0)
            MCLA_LOG_WARN("F611-FPSTACKARG-WRITE #{} arg={} r1={:08X} va={:08X} - "
                          "argument NOT delivered to the guest",
                          n, arg, static_cast<uint32_t>(ctx.r1.u32), va);
    }

    template<typename T>
    static std::enable_if_t<!std::is_pointer_v<T>, T> GetValue(PPCContext& ctx, uint8_t* base, size_t idx) noexcept
    {
        if constexpr (is_precise_v<T>)
        {
            return static_cast<T>(GetPrecisionArgumentValue(ctx, base, idx));
        }
        else
        {
            return static_cast<T>(GetIntegerArgumentValue(ctx, base, idx));
        }
    }

    // Guest VA -> host pointer for a POINTER argument. This is the live path for
    // every import that takes an out-parameter (`be<uint32_t>*` etc), and it
    // used to be `reinterpret_cast<T>(base + v)` with no range check at all: a
    // guest VA of 0x8FFFFFFF produced a host pointer inside the window, and
    // anything larger produced a pointer entirely outside it, both handed to
    // the host function as valid. Now an out-of-window VA - including the
    // 0..0xFFF PAGE_NOACCESS null guard, memory.cpp:316-322 - becomes nullptr,
    // which is what a host callee can actually survive.
    template<typename T>
    static std::enable_if_t<std::is_pointer_v<T>, T> GetValue(PPCContext& ctx, uint8_t* base, size_t idx) noexcept
    {
        const auto v = GetIntegerArgumentValue(ctx, base, idx);
        if (!v)
        {
            return nullptr;
        }

        void* host = GuestPtr(static_cast<uint32_t>(v));
        if (host == nullptr)
        {
            static std::atomic<uint32_t> s_badArgPtr{0};
            const uint32_t n = s_badArgPtr.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 8 || (n % 1000) == 0)
                MCLA_LOG_WARN("F611-ARGPTR #{} arg={} guestVa={:08X} - passing "
                              "nullptr to the host callee",
                              n, idx, static_cast<uint32_t>(v));
            return nullptr;
        }

        return static_cast<T>(host);
    }

    template<typename T>
    static std::enable_if_t<!std::is_pointer_v<T>, void> SetValue(PPCContext& ctx, uint8_t* base, size_t idx, T value) noexcept
    {
        if constexpr (is_precise_v<T>)
        {
            SetPrecisionArgumentValue(ctx, base, idx, value);
        }
        else if constexpr (std::is_null_pointer_v<T>)
        {
            SetIntegerArgumentValue(ctx, base, idx, 0);
        }
        else if constexpr (std::is_pointer_v<T>)
        {
            SetIntegerArgumentValue(ctx, base, idx, HostPtrToGuestVa(value));
        }
        else
        {
            SetIntegerArgumentValue(ctx, base, idx, value);
        }
    }

    template<typename T>
    static std::enable_if_t<std::is_pointer_v<T>, void> SetValue(PPCContext& ctx, uint8_t* base, size_t idx, T value) noexcept
    {
        // Host pointer -> guest VA, checked in-window (HostPtrToGuestVa) instead
        // of `Memory::MapVirtual`, which asserts IsInMemoryRange and then
        // subtracts anyway - a no-op check once /DNDEBUG compiles the assert out.
        SetIntegerArgumentValue(ctx, base, idx, HostPtrToGuestVa((const void*)value));
    }
};

struct Argument
{
    int type{};
    int ordinal{};
};

template<typename T1>
constexpr std::array<Argument, std::tuple_size_v<T1>> GatherFunctionArguments(const T1& tpl)
{
    std::array<Argument, std::tuple_size_v<T1>> args{};

    int floatOrdinal{};
    size_t i{};

    if constexpr (!args.empty())
    {
        std::apply([&](const auto& first, const auto&... rest)
            {
                auto append = [&]<typename T2>(const T2& v)
                {
                    if constexpr (is_precise_v<T2>)
                    {
                        args[i] = { 1, floatOrdinal++ };
                    }
                    else
                    {
                        args[i] = { 0, static_cast<int>(i) }; // what the fuck
                    }

                    i++;
                };

                append(first);
                (append(rest), ...);
            }, tpl);
    }

    return args;
}

template<auto Func>
constexpr std::array<Argument, arg_count_t<Func>::value> GatherFunctionArguments()
{
    return GatherFunctionArguments(function_args(Func));
}

template<auto Func, size_t I>
struct arg_ordinal_t
{
    static constexpr size_t value = GatherFunctionArguments<Func>()[I].ordinal;
};

template<auto Func, int I = 0, typename ...TArgs>
void _translate_args_to_host(PPCContext& ctx, uint8_t* base, std::tuple<TArgs...>&) noexcept
    requires (I >= sizeof...(TArgs))
{
}

template <auto Func, int I = 0, typename ...TArgs>
std::enable_if_t<(I < sizeof...(TArgs)), void> _translate_args_to_host(PPCContext& ctx, uint8_t* base, std::tuple<TArgs...>& tpl) noexcept
{
    using T = std::tuple_element_t<I, std::remove_reference_t<decltype(tpl)>>;
    std::get<I>(tpl) = ArgTranslator::GetValue<T>(ctx, base, arg_ordinal_t<Func, I>::value);

    _translate_args_to_host<Func, I + 1>(ctx, base, tpl);
}

template<int I = 0, typename ...TArgs>
void _translate_args_to_guest(PPCContext& ctx, uint8_t* base, std::tuple<TArgs...>&) noexcept
    requires (I >= sizeof...(TArgs))
{
}

template <int I = 0, typename ...TArgs>
std::enable_if_t<(I < sizeof...(TArgs)), void> _translate_args_to_guest(PPCContext& ctx, uint8_t* base, std::tuple<TArgs...>& tpl) noexcept
{
    using T = std::tuple_element_t<I, std::remove_reference_t<decltype(tpl)>>;
    ArgTranslator::SetValue<T>(ctx, base, GatherFunctionArguments(std::tuple<TArgs...>{})[I].ordinal, std::get<I>(tpl));

    _translate_args_to_guest<I + 1>(ctx, base, tpl);
}

template<auto Func>
PPC_FUNC(HostToGuestFunction)
{
    using ret_t = decltype(std::apply(Func, function_args(Func)));

    auto args = function_args(Func);
    _translate_args_to_host<Func>(ctx, base, args);

    if constexpr (std::is_same_v<ret_t, void>)
    {
        std::apply(Func, args);
    }
    else
    {
        auto v = std::apply(Func, args);

        if constexpr (std::is_pointer<ret_t>())
        {
            // Guest VA from a host pointer, checked in both directions. The old
            // `reinterpret_cast<size_t>(v) - reinterpret_cast<size_t>(base)`
            // (function.h:506 before this change) is an unchecked 64-bit
            // subtraction truncated to 32 bits: a host pointer outside the
            // 4 GiB window produced a plausible-looking guest VA, and the
            // guest then dereferenced whatever that VA happened to be.
            ctx.r3.u64 = ArgTranslator::HostPtrToGuestVa(v);
        }
        else if constexpr (is_precise_v<ret_t>)
        {
            ctx.f1.f64 = v;
        }
        else
        {
            ctx.r3.u64 = (uint64_t)v;
        }
    }
}

// Re-publishes the caller's context even if the callee (or a host hook it
// called) leaves by exception. Without this, a throw between the two
// SetPPCContext calls left the thread-local pointing at `newCtx`, a dead stack
// object of this frame - the next hand-written import reading g_ppcContext->r13
// would use freed stack. /EHa is on for this TU (compile_commands.json), so
// guest->host->guest re-entry can throw.
struct ScopedPPCContext
{
    PPCContext& saved;
    ScopedPPCContext(PPCContext& current, PPCContext& next) : saved(current)
    {
        SetPPCContext(next);
    }
    ~ScopedPPCContext()
    {
        SetPPCContext(saved);
    }
    ScopedPPCContext(const ScopedPPCContext&) = delete;
    ScopedPPCContext& operator=(const ScopedPPCContext&) = delete;
};

template<typename T, typename TFunction, typename... TArgs>
T GuestToHostFunction(const TFunction& func, TArgs&&... argv)
{
    auto args = std::make_tuple(std::forward<TArgs>(argv)...);
    auto& currentCtx = *GetPPCContext();

    // F-611 carriage contract: see the block at the top of this file. The three
    // copies that existed (r1/r13/fpscr) were not enough, and the
    // default-initialised `PPCContext` was worse than "not enough": every
    // member the *_as_local config leaves in the context (lr, r4..r10, f1..f13,
    // v0..v13) held whatever this frame's stack memory happened to contain.
    //
    //   - r1, r13, fpscr: carried as before. fpscr is volatile and
    //     read-modify-write, so it is copied back below.
    //   - msr: carried. It is the only switch that decides FP vs integer
    //     access in the recompiled loads/stores, and the default 0x200A000
    //     (FP+VMX on) is not necessarily the state the caller is in.
    //   - lr: carried. `blr` does not read it (recompiler.cpp:863-865) but
    //     `mflr` and `savegprlr 14` (toml:6-7) do, and a host-initiated entry
    //     has no caller frame, so the caller's lr is the only honest value.
    //   - everything else stays 0: those are either the argument registers
    //     written immediately below, or function-locals in the callee that
    //     this layer is not permitted to invent (no emulated CTR/XER/CR).
    PPCContext newCtx{}; // value-init: zero + msr default, NOT default-init
    newCtx.r1 = currentCtx.r1;
    newCtx.r13 = currentCtx.r13;
    newCtx.fpscr = currentCtx.fpscr;
    newCtx.msr = currentCtx.msr;
    newCtx.lr = currentCtx.lr;

    _translate_args_to_guest(newCtx, mcla::kernel::g_memory.base, args);

    {
        ScopedPPCContext scope(currentCtx, newCtx);

        if constexpr (std::is_function_v<TFunction>)
            func(newCtx, mcla::kernel::g_memory.base);
        else
        {
            auto* guestFn = mcla::kernel::g_memory.FindFunction(func);
            if (guestFn == nullptr)
            {
                // Not a crash and not a silent garbage return: the target is not
                // in the recompiled function table, which is a census fact
                // worth naming. r3/f1 keep their zeroed values.
                static std::atomic<uint32_t> s_unmapped{0};
                const uint32_t n = s_unmapped.fetch_add(1, std::memory_order_relaxed) + 1;
                if (n <= 8 || (n % 1000) == 0)
                    MCLA_LOG_WARN("F611-NOFUNC #{} guest={:08X} - no host function "
                                  "to call; the guest sees a zeroed r3/f1",
                                  n, static_cast<uint32_t>(func));
                return T{};
            }
            guestFn(newCtx, mcla::kernel::g_memory.base);
        }
    } // caller's context is re-published here (also on an exceptional exit)

    currentCtx.fpscr = newCtx.fpscr;

    if constexpr (std::is_pointer_v<T>)
    {
        // Guest VA -> host pointer, CHECKED. `g_memory.Translate` is the
        // unchecked `base + offset` (memory.h:157-161) and asserts the range,
        // so under the build's /DNDEBUG an out-of-window r3 became a wild host
        // pointer inside the returned value.
        void* host = ArgTranslator::GuestPtr(newCtx.r3.u32);
        if (host == nullptr && newCtx.r3.u32 != 0)
        {
            static std::atomic<uint32_t> s_badRet{0};
            const uint32_t n = s_badRet.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 8 || (n % 1000) == 0)
                MCLA_LOG_WARN("F611-RET-PTR #{} guestVa={:08X} - returning nullptr "
                              "to the host caller",
                              n, static_cast<uint32_t>(newCtx.r3.u32));
        }
        return static_cast<T>(host);
    }
    else if constexpr (is_precise_v<T>)
    {
        return static_cast<T>(newCtx.f1.f64);
    }
    else if constexpr (std::is_integral_v<T>)
    {
        return static_cast<T>(newCtx.r3.u64);
    }
    else
    {
        static_assert(std::is_void_v<T>, "Unsupported return type.");
    }
}

#define GUEST_FUNCTION_HOOK(subroutine, function) \
    PPC_FUNC(subroutine) { HostToGuestFunction<function>(ctx, base); }

#define GUEST_FUNCTION_STUB(subroutine) \
    PPC_FUNC(subroutine) { }
