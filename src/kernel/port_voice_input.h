#pragma once
//
// port_voice_input.h - native replacements for the seven console voice /
// console-key / input imports that used to be empty GUEST_FUNCTION_STUB bodies
// in src/kernel/imports.cpp.
//
// WHAT THIS IS. Seven countable, non-fabricating host bodies. Each one answers
// a guest import with a value the host can actually justify, and each one logs
// a numbered marker (`VOIPORT-ATTEMPT` / `VOIPORT-REFUSE` / `VOIPORT-BADPTR`)
// so a soak can count refusals per function instead of guessing at them.
//
// WHAT THIS IS NOT. It is not a voice stack. It is not a crypto provider. It is
// not a second input backend. Every body here REFUSES. Nothing in this file
// invents a voice handle, an audio packet, a headset, a signature, or a
// signature-verification verdict - see port_voice_input.cpp for the
// per-function reference citation and the single-line reason for each refusal.
//
// SIGNATURE DISCIPLINE. Every argument is taken as a `uint32_t` guest VA, never
// as a pointer. `ArgTranslator::GetValue` (src/kernel/function.h:331, the
// non-pointer overload) hands an integer argument through untouched, so no host
// pointer is ever formed for guest data anywhere in this translation unit and
// there is nothing here that could be `reinterpret_cast`ed over guest bytes.
// Out-parameters are touched only through `ArgTranslator::IsGuestVa` +
// `ArgTranslator::WriteGuestU32` (src/kernel/function.h:100, :113), and an
// invalid guest pointer causes a refusal, never a partial struct write.
//
// HOST SYMBOL NAMES. The bodies are named `VoiPort*`, not `XamVoice*` /
// `XeKeys*`. src/kernel/imports.cpp still carries global-scope placeholder
// definitions for five of these (`void XamVoiceCreate() { LOG_UTILITY("!!! STUB
// !!!"); }` and four siblings, imports.cpp:6755, :6762-:6765). If this file
// defined the same names, forgetting to delete those would be a duplicate
// external symbol at link time. With a distinct prefix, a partial integration
// leaves harmless dead code behind instead of breaking the build.
//
// REMOVAL CONDITION (applies to every refusal below). Each body is a refusal
// because the host has no state to answer from. Each becomes a real body when
// the corresponding state exists and is observable:
//
//   XamVoiceCreate / XamVoiceClose / XamVoiceSubmitPacket
//       A voice object table + an audio capture backend. Today the host has
//       neither: there is no capture device, no encoder, no transport, and no
//       way to receive a packet, so there is nothing to accept and nothing to
//       submit.
//   XamVoiceHeadsetPresent
//       Real headset-presence detection. Nothing in this tree can observe a
//       headset, so the honest answer is "no headset" - not the reference's
//       unconditional "yes".
//   XeKeysConsolePrivateKeySign / XeKeysConsoleSignatureVerification
//       A console private key. An Xbox 360's key is per-console, extracted from
//       that console's fuses, and is not a build input. Without it there is
//       nothing to sign with and nothing to verify against, and a function that
//       answers either question without a key is a forgery, not an
//       implementation. NOTE: this is a game emulator, not an authentication
//       system - there is no remote party to fool and no trust boundary here,
//       so refusing is the correct and safe direction, not merely the cautious
//       one. A "verification" that always returns success is a
//       security-relevant lie and is not acceptable in this tree at any point.
//   XamInputGetKeystrokeEx
//       A keystroke QUEUE. The project has gamepad STATE (a main-thread
//       snapshot, src/kernel/xam.cpp:362-377) and not an event queue; see the
//       long comment on VoiPortXamInputGetKeystrokeEx for the measured reason
//       why a snapshot cannot be one. When a keystroke queue exists, this body
//       becomes a single dequeue-and-validate, and it must plug into the
//       existing input path in src/kernel/xam.cpp - not beside it.
//

#include <cstdint>

namespace mcla::kernel::voi {

// ---- XOS result codes ------------------------------------------------------
// Xenia's X_ERROR_* macros are `((X_RESULT)(x))` - a bare cast with no
// 0x80000000 failure bit (.research/xenia/src/xenia/xbox.h:84, :89, :90, :101,
// :106). The real Xbox 360 returns the HRESULT form. This file returns the
// HRESULT form, which is non-zero AND negative, so it fails a title's
// `!= 0` test and a title's `< 0` test alike. The three guests that test these
// returns test them for NEGATIVE (see the per-function notes in the .cpp), and
// Xenia's positive literals would read as success on this guest.
inline constexpr uint32_t kXErrorAccessDenied = 0x80000005u;
inline constexpr uint32_t kXErrorInvalidHandle = 0x80000006u;
inline constexpr uint32_t kXErrorNotFound = 0x80000490u;
inline constexpr uint32_t kXErrorEmpty = 0x800010D2u;

// Voice. `outVoicePtrVa` is a guest VA for a guest dword handle out-param.
uint32_t VoiPortXamVoiceCreate(uint32_t unk1, uint32_t unk2, uint32_t outVoicePtrVa);
uint32_t VoiPortXamVoiceClose(uint32_t voicePtrVa);
uint32_t VoiPortXamVoiceHeadsetPresent(uint32_t voicePtrVa);
uint32_t VoiPortXamVoiceSubmitPacket(uint32_t voicePtrVa, uint32_t bufferPtrVa,
                                     uint32_t dataSize, uint32_t flags);

// Console keys. Both refuse; neither writes to an out-buffer.
uint32_t VoiPortXeKeysConsolePrivateKeySign(uint32_t outSigPtrVa, uint32_t dataPtrVa,
                                            uint32_t dataSize, uint32_t keyIndex);
uint32_t VoiPortXeKeysConsoleSignatureVerification(uint32_t dataPtrVa, uint32_t sigPtrVa,
                                                   uint32_t outVerifiedPtrVa,
                                                   uint32_t sigSize);

// Input.
uint32_t VoiPortXamInputGetKeystrokeEx(uint32_t userIndexPtrVa, uint32_t flags,
                                       uint32_t keystrokePtrVa);

} // namespace mcla::kernel::voi
