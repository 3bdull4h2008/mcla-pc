// port_voice_input.cpp - seven console voice / console-key / input imports.
//
// Replaces the empty `GUEST_FUNCTION_STUB(__imp__X)` bodies that these imports
// carried in src/kernel/imports.cpp. An empty stub body returns whatever the
// context happened to hold in r3 and logs nothing countable, so a title calling
// one of these had no defined behaviour and no evidence in the log. Every body
// here returns a value the host can defend and logs a numbered marker.
//
// HEADLINE: 0 real, 7 refuse. Six of the seven write nothing to guest memory at
// all. The seventh (XamVoiceCreate) writes exactly one field - a zeroed handle
// out-param - which is the reference's own documented behaviour and is what
// stops the guest from carrying a phantom voice handle forward.
//
// ===========================================================================
// THE FETCH OUTCOME (read this before trusting the "ReXGlue implements what
// Xenia stubs" claim)
// ===========================================================================
// The brief's coverage audit says a second reference - ReXGlue - implements
// these four voice functions where Xenia marks them as stubs, and gave the path
// https://raw.githubusercontent.com/RealOrLawn/rexglue/main/... That path does
// not exist: `RealOrLawn/rexglue` returns HTTP 404 from the GitHub API root, so
// the repository is not public under that name. The real project is the
// `rexglue` ORGANISATION's `rexglue-sdk` repo, and the file was fetched from
//     https://raw.githubusercontent.com/rexglue/rexglue-sdk/main/src/kernel/xam/xam_voice.cpp
//
// THE CLAIM IS REFUTED BY THE FETCH. ReXGlue's xam_voice.cpp is Xenia's
// xam_voice.cc with the namespace changed and DECLARE_XAM_EXPORT* replaced by
// REX_EXPORT*. Diffing the entry bodies: XamVoiceCreate, XamVoiceClose and
// XamVoiceHeadsetPresent are line-for-line the same as Xenia's, and
// XamVoiceSubmitPacket - which Xenia does not define at all - is
// `REX_EXPORT_STUB(__imp__XamVoiceSubmitPacket);` on the last line of ReXGlue's
// file. ReXGlue STUBS IT TOO. So there is no second opinion on voice to fetch,
// and this port is a refusal on the evidence of BOTH references agreeing, not a
// gap in the reference set. What the fetch settled: (a) that a coverage audit
// scored "Xenia = stub" as "ReXGlue = implemented" without comparing bodies;
// (b) that the honest ceiling for all four voice functions is refusal, not a
// port. Anyone re-running that audit should re-score it against the bodies.
//
// Both references are Xenia-derived and BSD-2-Clause, and this file cites them
// for INTENDED BEHAVIOUR only. No `rex::` code, no `rex::` architecture, and no
// ReXGlue SDK dependency is used or introduced (project constraint; see
// AGENTS.md "Non-negotiable project constraints"). Nothing from either
// reference is copied; each body is an independent refusal with its own code.
//
// ===========================================================================
// WHY THE RETURN VALUES ARE NOT THE REFERENCES' LITERALS
// ===========================================================================
// Three of these guests test the returned value for NEGATIVE, and one tests it
// for EQUAL-TO-ZERO, and Xenia's X_ERROR_* macros are a bare cast with no
// 0x80000000 failure bit (.research/xenia/src/xenia/xbox.h:84, so
// X_ERROR_ACCESS_DENIED is the positive literal 0x5). Porting those literals
// verbatim would make this guest read a refusal as a success. The deviations
// are deliberate, measured, and cited per function below:
//
//   XamVoiceCreate                    guest: `if (r29 < 0)`   -> needs NEGATIVE
//   XamVoiceSubmitPacket              guest: `if (cr0.lt)`     -> needs NEGATIVE
//   XeKeysConsoleSignatureVerification guest: `if (r3 == 0)`    -> needs NON-ZERO
//   XamVoiceHeadsetPresent            guest: `if (r3 == 0)`    -> BOOLEAN, 0 = PRESENT
//
// The XamVoiceHeadsetPresent case is the sharpest one. The reference returns 0,
// which on this guest means "a headset IS present". Porting that would
// fabricate a headset. This file returns 1 - "no headset" - which is the truth
// and is a different observable outcome from the reference's.
//
// ===========================================================================
// A LOGGING CONSTRAINT WORTH WRITING DOWN (cost a compile cycle)
// ===========================================================================
// mcla::log::Warn takes a `fmt::format_string<Args...>` (src/common/logging.h:76),
// which is a consteval-checked type. It accepts a `const` lvalue argument
// (that is what the `const uint32_t n = ...` house pattern in src/kernel/xam.cpp
// relies on) but REJECTS a non-const lvalue: passing a by-value helper parameter
// on to fmt makes Args deduce to `uint32_t&` and the consteval constructor
// fails with "call to consteval function 'fmt::fstring<...>' is not a constant
// expression". Every format argument below is therefore a prvalue or a
// `const` local, and every marker string is a literal - which also keeps
// `VOIPORT-REFUSE` greppable as a whole-token anchor for the soak gate.
// ===========================================================================

#include <stdafx.h>

#include "port_voice_input.h"

#include "function.h"
#include "logging.h"
#include "xam.h"

#include <atomic>

namespace mcla::kernel::voi {
namespace {

// ---------------------------------------------------------------------------
// House refusal counters, one pair per function, so a soak's census is per
// function rather than a single lumped total that cannot say which import is
// being hit. Attempts and outcomes are SEPARATE counters: "the guest never
// called this" and "the guest called it and was refused every time" are
// different facts and a soak must be able to tell them apart.
// ---------------------------------------------------------------------------

std::atomic<uint32_t> g_voiceCreateAtk{0};
std::atomic<uint32_t> g_voiceCreateRef{0};
std::atomic<uint32_t> g_voiceCloseAtk{0};
std::atomic<uint32_t> g_voiceCloseRef{0};
std::atomic<uint32_t> g_voiceHeadsetAtk{0};
std::atomic<uint32_t> g_voiceHeadsetRef{0};
std::atomic<uint32_t> g_voiceSubmitAtk{0};
std::atomic<uint32_t> g_voiceSubmitRef{0};
std::atomic<uint32_t> g_keySignAtk{0};
std::atomic<uint32_t> g_keySignRef{0};
std::atomic<uint32_t> g_keyVerifyAtk{0};
std::atomic<uint32_t> g_keyVerifyRef{0};
std::atomic<uint32_t> g_keystrokeAtk{0};
std::atomic<uint32_t> g_keystrokeRef{0};
std::atomic<uint32_t> g_keystrokeBadPtr{0};

// Throttling, the house `n <= K || (n % 200) == 0` shape. Print the first few
// of each so a short soak still records them, then every 200th. The atomic is
// still incremented on every call, so a refusal that is not printed is still
// counted - the log thins out, the census does not.
constexpr uint32_t kLogFirst = 8;
constexpr uint32_t kLogEvery = 200;

bool Throttle(uint32_t n) noexcept
{
    return n <= kLogFirst || (n % kLogEvery) == 0;
}

uint32_t Bump(std::atomic<uint32_t>& c) noexcept
{
    return c.fetch_add(1, std::memory_order_relaxed) + 1;
}

} // namespace

// ===========================================================================
// 1. XamVoiceCreate                                    *** REFUSE ***
// Reference: .research/xenia/src/xenia/kernel/xam/xam_voice.cc:26-33
// ReXGlue:   src/kernel/xam/xam_voice.cpp:31-37 (same body, fetched)
// Reason:    there is no voice object to create - the host has no capture
//            device, no encoder and no transport, so any handle handed back
//            would name an object that does not exist.
//
// This is the ONE body in the file that writes to guest memory, and it writes
// exactly what the reference writes: a zeroed out-pointer. That is not a
// fabrication, it is the absence of one, and this guest depends on it. Measured
// at generated/default/mcla_recomp.55.cpp:45057-45074: the guest saves r3,
// tests it, and at loc_82751900 reads the out-param back (`lwz r3,0(r28)`) and
// skips XamVoiceClose when it is zero. A non-zeroed out-param here is what
// manufactures a phantom handle and a phantom teardown.
//
// DEVIATION, deliberate: the reference returns X_ERROR_ACCESS_DENIED, which in
// Xenia is the POSITIVE literal 0x5 (xbox.h:84 is a bare cast). The guest
// branches on `if (ctx.cr0.lt)` (generated/default/mcla_recomp.55.cpp:45063),
// so 0x5 would fall through to the success path at loc_827518A4 and the title
// would proceed as though a voice engine had started. Returning the real XOS
// HRESULT 0x80000005 is negative, so the guest takes its error path.
// ===========================================================================
uint32_t VoiPortXamVoiceCreate(uint32_t unk1, uint32_t unk2, uint32_t outVoicePtrVa)
{
    (void)unk1;  // 0 on this guest    (generated/default/mcla_recomp.55.cpp:45052)
    (void)unk2;  // 0xF on this guest (generated/default/mcla_recomp.55.cpp:45053)

    const uint32_t n = Bump(g_voiceCreateAtk);

    // All-or-nothing, checked, endian-explicit. A guest pointer that is not a
    // committed guest range gets a refusal and NO write - never a partial
    // struct, and never a raw store to an address the guest chose.
    bool wrote = false;
    if (outVoicePtrVa != 0 && ArgTranslator::IsGuestVa(outVoicePtrVa, sizeof(uint32_t)))
    {
        wrote = ArgTranslator::WriteGuestU32(outVoicePtrVa, 0);
    }
    else
    {
        const uint32_t b = Bump(g_keystrokeBadPtr);
        (void)b;  // counted, not separately reported; see XamInputGetKeystrokeEx
    }

    const uint32_t r = Bump(g_voiceCreateRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XamVoiceCreate code=0x{:08X} - no voice "
                      "backend on this host; out-handle {}",
                      r, kXErrorAccessDenied, wrote ? "zeroed (not fabricated)" : "NOT written");
    }
    if (Throttle(n) && n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XamVoiceCreate -> 0x{:08X}", n, kXErrorAccessDenied);
    }
    return kXErrorAccessDenied;
}

// ===========================================================================
// 2. XamVoiceClose                                     *** REFUSE ***
// Reference: .research/xenia/src/xenia/kernel/xam/xam_voice.cc:35-36  -> `return 0`
// ReXGlue:   src/kernel/xam/xam_voice.cpp:39-41 (same body, fetched)
// Reason:    there is no voice object to close - VoiPortXamVoiceCreate never
//            hands one out, so "closed successfully" would be a fabricated
//            lifecycle event.
//
// RISK: none. All three call sites discard the return value, measured in the
// recompiled consumer: generated/default/mcla_recomp.55.cpp:44081 (next
// instruction is a store, r3 unused), :44908 (next is `li r11,0`, r3 unused)
// and :45132 (next is `li r11,0`, r3 unused). Two of the three are guarded by a
// null check on the handle the guest is holding, so with VoiPortXamVoiceCreate
// zeroing that handle, this function is not even reached on the create-failure
// path. Refusing therefore costs the title nothing here.
// ===========================================================================
uint32_t VoiPortXamVoiceClose(uint32_t voicePtrVa)
{
    (void)voicePtrVa;

    const uint32_t n = Bump(g_voiceCloseAtk);
    const uint32_t r = Bump(g_voiceCloseRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XamVoiceClose code=0x{:08X} - no voice object "
                      "exists; all 3 call sites discard r3", r, kXErrorInvalidHandle);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XamVoiceClose -> 0x{:08X}", n, kXErrorInvalidHandle);
    }
    return kXErrorInvalidHandle;
}

// ===========================================================================
// 3. XamVoiceHeadsetPresent                             *** REFUSE ***
// Reference: .research/xenia/src/xenia/kernel/xam/xam_voice.cc:38-39  -> `return 0`
// ReXGlue:   src/kernel/xam/xam_voice.cpp:43-45 (same body, fetched)
// Reason:    nothing in this tree can observe a headset, and 0 does not mean
//            "unknown" to this guest - it means "a headset IS plugged in".
//
// MEASURED CONTRACT: this is a BOOLEAN, not an HRESULT. The caller compares the
// result for EQUALITY against zero and sets two "there is audio hardware" flags
// when it matches (generated/default/mcla_recomp.55.cpp:43037-43050):
//     __imp__XamVoiceHeadsetPresent(ctx, base);
//     ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
//     if (ctx.cr6.eq) goto loc_82750BA8;   // -> r28 = 1, r27 = 1
// So the reference's unconditional `return 0` is an unconditional claim that a
// headset is attached. Porting it verbatim would fabricate headset presence -
// one of the specific fabrications this file exists to prevent.
//
// Returning 1 (absent) is the only honest answer available: there is no capture
// path on this host, so there is provably no headset in use. Any non-zero value
// is equivalent to this guest, which only tests equality with zero.
// ===========================================================================
uint32_t VoiPortXamVoiceHeadsetPresent(uint32_t voicePtrVa)
{
    (void)voicePtrVa;

    // NOT an XOS error code: this parameter is a boolean and 0 means PRESENT.
    // 1 = no headset, which is the truth and is what this guest's equality test
    // needs in order not to report phantom capture hardware.
    constexpr uint32_t kNoHeadset = 1u;

    const uint32_t n = Bump(g_voiceHeadsetAtk);
    const uint32_t r = Bump(g_voiceHeadsetRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XamVoiceHeadsetPresent code=0x{:08X} - no "
                      "capture hardware on this host; 0 would assert a headset IS present",
                      r, kNoHeadset);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XamVoiceHeadsetPresent -> 0x{:08X}", n, kNoHeadset);
    }
    return kNoHeadset;
}

// ===========================================================================
// 4. XamVoiceSubmitPacket                               *** REFUSE ***
// Reference: NOT IMPLEMENTED IN EITHER REFERENCE. Absent from Xenia's
//            xam_voice.cc entirely; `REX_EXPORT_STUB(__imp__XamVoiceSubmitPacket);`
//            in ReXGlue's src/kernel/xam/xam_voice.cpp (last line, fetched).
// Reason:    submitting a packet requires a captured packet. There is no
//            capture device, so there is nothing to submit and the buffer the
//            guest passes is not read.
//
// DEVIATION, deliberate and forced: the guest tests the return for NEGATIVE
// (`if (ctx.cr0.lt) goto loc_8275160C`, generated/default/mcla_recomp.55.cpp:
// 44639-44643). There is no reference literal to be faithful to here at all, so
// this is a free choice - and it must be negative, or the title continues down
// the "my packet was delivered" path. kXErrorInvalidHandle is the accurate code:
// the voice object whose transport would carry the packet was never created.
// The buffer is NOT read and NOT freed. Freeing it would be a use-after-free
// waiting to happen; the guest owns that allocation.
// ===========================================================================
uint32_t VoiPortXamVoiceSubmitPacket(uint32_t voicePtrVa, uint32_t bufferPtrVa,
                                     uint32_t dataSize, uint32_t flags)
{
    (void)voicePtrVa;
    (void)bufferPtrVa;
    (void)dataSize;
    (void)flags;

    const uint32_t n = Bump(g_voiceSubmitAtk);
    const uint32_t r = Bump(g_voiceSubmitRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XamVoiceSubmitPacket code=0x{:08X} - REFERENCE "
                      "STUBS IT (ReXGlue REX_EXPORT_STUB); no capture device, packet buffer "
                      "not read", r, kXErrorInvalidHandle);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XamVoiceSubmitPacket -> 0x{:08X}", n,
                      kXErrorInvalidHandle);
    }
    return kXErrorInvalidHandle;
}

// ===========================================================================
// 5. XeKeysConsolePrivateKeySign                        *** REFUSE ***
// Reference: NOT IMPLEMENTED. Declared in Xenia's export table only -
//            .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_table.inc:612
//            (ordinal 0x00000256) - with no `_entry` body anywhere in
//            xboxkrnl_crypt.cc. The sibling XeKeys functions that DO have bodies
//            (XeKeysHmacSha, XeKeysAesCbcUsingKey, XeKeysObscureKey,
//            XeKeysHmacShaUsingKey) are at xboxkrnl_crypt.cc:611, :636, :655,
//            :667, and none of them is this one.
// Reason:    there is no console private key on this host. Signing without one
//            means emitting bytes that look like a console signature and are
//            not one.
//
// WHAT THIS DELIBERATELY DOES NOT DO: it does not write to the out-signature
// buffer. Zero fabricated signatures. A signature buffer left untouched plus a
// non-zero return is the only combination a caller can act on safely - the
// caller must not read the buffer, and the zeroed-looking alternative would be
// indistinguishable from a real all-zero signature.
//
// SCOPE NOTE, so this refusal is not misread: this is a game emulator, not an
// authentication system. There is no remote party, no trust boundary and no
// key material to leak. Refusing is still the correct direction - it is what
// makes the guest's own failure path reachable - but the motivation here is
// honesty about the host's state, not defence against an attacker.
// ===========================================================================
uint32_t VoiPortXeKeysConsolePrivateKeySign(uint32_t outSigPtrVa, uint32_t dataPtrVa,
                                            uint32_t dataSize, uint32_t keyIndex)
{
    (void)outSigPtrVa;
    (void)dataPtrVa;
    (void)dataSize;
    (void)keyIndex;

    // Nothing is read and nothing is written - not even a length. A caller that
    // ignores the return would find an untouched buffer, which is the honest
    // state of a signature that was never produced.
    const uint32_t n = Bump(g_keySignAtk);
    const uint32_t r = Bump(g_keySignRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XeKeysConsolePrivateKeySign code=0x{:08X} - "
                      "REFERENCE STUBS IT; no console private key exists on this host, "
                      "out-signature buffer not written", r, kXErrorNotFound);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XeKeysConsolePrivateKeySign -> 0x{:08X}", n,
                      kXErrorNotFound);
    }
    return kXErrorNotFound;
}

// ===========================================================================
// 6. XeKeysConsoleSignatureVerification                 *** REFUSE ***
// Reference: NOT IMPLEMENTED. Table entry only -
//            .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_table.inc:613
//            (ordinal 0x00000257). No `_entry` body exists.
// Reason:    verifying a console signature needs the console public key that
//            corresponds to the private key, and this host has neither.
//
// THIS IS THE FUNCTION WHERE A "RETURN SUCCESS" STUB WOULD BE A LIE THAT
// MATTERS. A signature-verification that always reports "valid" is not a stub,
// it is a false statement about a security property, and it is the specific
// outcome this file must never produce.
//
// MEASURED CONSUMER, generated/default/mcla_recomp.27.cpp:59636-59640:
//     __imp__XeKeysConsoleSignatureVerification(ctx, base);
//     ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
//     if (ctx.cr0.eq) goto loc_8244DA28;    // r3 == 0  =>  "signature accepted"
// So 0 is the ACCEPT verdict on this guest. kXErrorNotFound is non-zero, which
// drives the guest to its reject path at loc_8244DA18. Refusing is therefore
// not merely honest, it is the safe direction on the one function where the two
// could differ.
//
// The out-verdict buffer is NOT written, for the same reason as above: an
// untouched buffer plus a non-zero return cannot be misread as "verified".
// ===========================================================================
uint32_t VoiPortXeKeysConsoleSignatureVerification(uint32_t dataPtrVa, uint32_t sigPtrVa,
                                                   uint32_t outVerifiedPtrVa, uint32_t sigSize)
{
    (void)dataPtrVa;
    (void)sigPtrVa;
    (void)outVerifiedPtrVa;
    (void)sigSize;

    const uint32_t n = Bump(g_keyVerifyAtk);
    const uint32_t r = Bump(g_keyVerifyRef);
    if (Throttle(r))
    {
        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XeKeysConsoleSignatureVerification code=0x{:08X} - "
                      "REFERENCE STUBS IT; no console key pair exists, so no verdict is "
                      "issued - 0 would assert a VALID signature", r, kXErrorNotFound);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XeKeysConsoleSignatureVerification -> 0x{:08X}",
                      n, kXErrorNotFound);
    }
    return kXErrorNotFound;
}

// ===========================================================================
// 7. XamInputGetKeystrokeEx                             *** REFUSE ***
// Reference: .research/xenia/src/xenia/kernel/xam/xam_input.cc:155-180
//            (DECLARE_XAM_EXPORT1(..., kInput, kImplemented) - Xenia really does
//            implement this one) and ReXGlue src/kernel/xam/xam_input.cpp:161-181
//            (same body, fetched). Xenia backs it with a real queue:
//            .research/xenia/src/xenia/hid/input_system.cc:79-85 calls into an
//            input driver's GetKeystroke.
// Reason:    THE HOST HAS NO KEYSTROKE QUEUE. This is a refusal because of what
//            the host does NOT have, and it was measured, not assumed.
//
// ---- the measurement ----
// A case-insensitive search of every C/C++ file under src/ for "keystroke"
// returns exactly two hits, and both are the placeholder this file replaces:
// src/kernel/imports.cpp:6755 (`void XamInputGetKeystrokeEx() { LOG_UTILITY("!!! STUB !!!"); }`)
// and src/kernel/imports.cpp:6892 (`GUEST_FUNCTION_STUB(__imp__XamInputGetKeystrokeEx);`).
// There is no queue, no VK table, no event queue, no producer, and no consumer.
//
// ---- what the project DOES have, and why it is not a queue ----
// The project's input path is real and is the one to reuse - it was read before
// this body was written and nothing here bypasses or duplicates it:
//   * src/kernel/xam.h:33-35, implemented at src/kernel/xam.cpp:868, :941, :1019
//     - XamInputGetCapabilities / GetState / SetState over real SDL3 gamepads.
//   * src/kernel/xam.h:45-55 - XamInputInit / GamepadAdded / GamepadRemoved /
//     Poll / Shutdown / PortCount / PortDevice: the controller census.
//   * The state it keeps is a PortSnapshot (src/kernel/xam.cpp:362-377): current
//     buttons, triggers, sticks, a monotonic packet number, the device name and
//     guid. It is a LEVEL, not an EVENT STREAM.
//
// A snapshot cannot honestly answer a keystroke query, and the gap is
// structural, not a matter of plumbing:
//   * X_INPUT_KEYSTROKE is an event: virtual_key, unicode, flags
//     (KEYDOWN/KEYUP/REPEAT), user_index, hid_code - 8 bytes,
//     .research/xenia/src/xenia/hid/input.h:91-98 (static_assert_size 8). The
//     snapshot has no virtual key, no unicode, no key-up edge and no hid_code.
//     Deriving them would mean inventing a VK mapping that exists nowhere here.
//   * The host's keyboard is consumed as GAMEPAD buttons, not as keys. The
//     labelled fallback in src/kernel/xam.cpp:593-606 maps SDL scancodes to
//     XAMINPUT_GAMEPAD_* bits. There is no keystroke translation table to reuse,
//     and building one here would be the "second input backend" that makes two
//     paths drift apart.
//   * A press-and-release entirely between two main-thread samples is
//     UNOBSERVABLE from a snapshot. The snapshot is published once per
//     main-loop tick by XamInputPoll (src/kernel/xam.cpp:813-837), so any
//     keystroke shorter than a tick would be silently lost - reported as "no
//     keystroke", which is indistinguishable from a correct answer. That is the
//     worst possible failure mode for a queue API.
//
// kXErrorEmpty (0x800010D2, X_ERROR_EMPTY - .research/xenia/src/xenia/xbox.h:106)
// is the correct and truthful answer: the keystroke queue is empty. It is empty
// permanently, and permanently-empty is honestly reported as empty rather than
// dressed up with a fabricated key event.
//
// Nothing is written to the 8-byte X_INPUT_KEYSTROKE, and the user-index pointer
// is not written back either. The reference only writes the user index on
// success (xam_input.cc:174-177: `if (XSUCCEEDED(result)) *user_index_ptr = ...`),
// so leaving both untouched on refusal is the contract, not an omission.
//
// The pointers are still VALIDATED, so a soak can distinguish "refused because
// the queue is empty" from "refused because the guest handed us a bad pointer".
//
// ---- reuse, not duplication ----
// This file adds no input backend and opens no device. It queries the existing
// census read-only so the refusal log records which controller the title
// actually has, proving the refusal is about keystrokes and not about input in
// general. The one thing a future real keystroke queue must do is land in
// src/kernel/xam.cpp beside XamInputGetState, so there stays one input path.
// ===========================================================================
uint32_t VoiPortXamInputGetKeystrokeEx(uint32_t userIndexPtrVa, uint32_t flags,
                                       uint32_t keystrokePtrVa)
{
    (void)flags;

    const uint32_t n = Bump(g_keystrokeAtk);

    // Validate, do not dereference. `IsGuestVa` is the checked range test
    // (src/kernel/function.h:100 -> GuestMemoryHeap::IsValid,
    // src/kernel/memory.h:46) and it also rejects the 0..0xFFF PAGE_NOACCESS
    // null guard, so a guest-chosen address is never trusted. Sizes are from
    // the reference: the user index is a guest dword, the keystroke is an
    // 8-byte X_INPUT_KEYSTROKE (.research/xenia/src/xenia/hid/input.h:91-98).
    constexpr uint32_t kUserIndexSize = 4;
    constexpr uint32_t kKeystrokeSize = 8;

    const bool userIdxOk =
        userIndexPtrVa != 0 && ArgTranslator::IsGuestVa(userIndexPtrVa, kUserIndexSize);
    const bool strokeOk =
        keystrokePtrVa != 0 && ArgTranslator::IsGuestVa(keystrokePtrVa, kKeystrokeSize);
    const bool pointersOk = userIdxOk && strokeOk;

    if (!pointersOk)
    {
        const uint32_t b = Bump(g_keystrokeBadPtr);
        if (Throttle(b))
        {
            MCLA_LOG_WARN("VOIPORT-BADPTR #{} fn=XamInputGetKeystrokeEx userIdxVa=0x{:08X} "
                          "keystrokeVa=0x{:08X} - out of the guest window; nothing written",
                          b, userIndexPtrVa, keystrokePtrVa);
        }
    }

    const uint32_t r = Bump(g_keystrokeRef);
    if (Throttle(r))
    {
        // Read-only view of the EXISTING controller census (src/kernel/xam.h:54-55,
        // implemented src/kernel/xam.cpp:839-866). Not a second backend: it opens
        // nothing and samples nothing, it only reports what the one input path
        // already knows.
        const uint32_t ports = XamInputPortCount();
        uint32_t realPads = 0;
        for (uint32_t p = 0; p < ports; ++p)
        {
            char name[64] = {};
            uint32_t instance = 0;
            if (XamInputPortDevice(p, name, sizeof(name), &instance))
                ++realPads;
        }

        MCLA_LOG_WARN("VOIPORT-REFUSE #{} fn=XamInputGetKeystrokeEx code=0x{:08X} - NO "
                      "KEYSTROKE QUEUE in this host (measured: the only 'keystroke' hits "
                      "under src/ were the two stub lines being replaced); existing input "
                      "path: {}/{} ports with a real device; keystroke struct + user-index "
                      "left untouched; ptrs_ok={}",
                      r, kXErrorEmpty, realPads, ports, pointersOk ? 1 : 0);
    }
    if (n <= kLogFirst)
    {
        MCLA_LOG_INFO("VOIPORT-ATTEMPT #{} fn=XamInputGetKeystrokeEx -> 0x{:08X}", n,
                      kXErrorEmpty);
    }
    return kXErrorEmpty;
}

} // namespace mcla::kernel::voi

// ===========================================================================
// Registration. Form copied from the already-ported imports in
// src/kernel/imports.cpp:6523-6525 (GUEST_FUNCTION_HOOK(__imp__XamInputGetState,
// XamInputGetState)), which is the template the brief points at. The
// GUEST_FUNCTION_STUB(__imp__X) lines this replaces are at imports.cpp:6892,
// :6901-:6904 and :6906-:6907, and the integration stream deletes them.
//
// One owner per guest address, checked with
//     python tools/addr_owners.py --check <hexVA>
// which was run for all seven before this file was written: each VA reported
// exactly 1 site (the generated map), so none of these was already owned
// anywhere else. CAVEAT the integration stream must not skip: tools/addr_owners.py
// does NOT match the GUEST_FUNCTION_STUB spelling (it indexes PPC_FUNC /
// GUEST_FUNCTION_HOOK / SetFunction / GetFunction - see the tool's own header at
// tools/addr_owners.py:22-24), so it will not warn about a leftover
// GUEST_FUNCTION_STUB. Delete them by hand; the prefixed host names here mean a
// miss leaves dead code rather than a duplicate symbol.
// ===========================================================================
GUEST_FUNCTION_HOOK(__imp__XamInputGetKeystrokeEx,
                    mcla::kernel::voi::VoiPortXamInputGetKeystrokeEx);
GUEST_FUNCTION_HOOK(__imp__XamVoiceClose, mcla::kernel::voi::VoiPortXamVoiceClose);
GUEST_FUNCTION_HOOK(__imp__XamVoiceCreate, mcla::kernel::voi::VoiPortXamVoiceCreate);
GUEST_FUNCTION_HOOK(__imp__XamVoiceHeadsetPresent,
                    mcla::kernel::voi::VoiPortXamVoiceHeadsetPresent);
GUEST_FUNCTION_HOOK(__imp__XamVoiceSubmitPacket,
                    mcla::kernel::voi::VoiPortXamVoiceSubmitPacket);
GUEST_FUNCTION_HOOK(__imp__XeKeysConsolePrivateKeySign,
                    mcla::kernel::voi::VoiPortXeKeysConsolePrivateKeySign);
GUEST_FUNCTION_HOOK(__imp__XeKeysConsoleSignatureVerification,
                    mcla::kernel::voi::VoiPortXeKeysConsoleSignatureVerification);
