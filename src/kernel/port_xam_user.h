// ===========================================================================
// port_xam_user.h -- the XAM user / social / task / loader-launch-data port.
//
// WHAT THIS FILE IS. Twenty-four console XAM imports (the task brief says 19;
// the census is 24 -- see the block at the bottom) that were previously
// `GUEST_FUNCTION_STUB(__imp__X)` in src/kernel/imports.cpp, i.e. an EMPTY
// `PPC_FUNC` body, invisible at runtime: the guest's call returned whatever the
// guest itself had last left in r3, and nothing was logged, counted, or
// answered. Each one now has a body that either (a) implements the reference
// contract against state this host genuinely owns, or (b) refuses with the
// real XOS status the reference returns for the situation we are actually in.
// Every body is annotated with the Xenia `file:line` it was read from and the
// word REAL or REFUSE plus one line of reason.
//
// WHAT THIS FILE IS NOT. It is not an Xbox Live client, not an achievements or
// friends or marketplace service, not a dashboard, and not a tile/avatar
// service. This host has no signed-in user, no network, and no Xbox Live
// backend, so every answer of the form "what is user N's relationship to user
// M", "what has this title achieved", "show the friends list" is a question
// with no source in this process. Those are refused, not guessed.
//
// IT CREATES NO PROFILE. The one synthetic user in this host is
// `kXamSynthProfile` (src/kernel/imports.cpp:590, marker `SYNTH-PROFILE`,
// removal trigger at imports.cpp:566-575). It is file-static in an anonymous
// namespace, so it cannot be read directly; the two functions here that need
// it (XamUserGetXUID, XamUserGetName) go through the EXISTING consumer
// `XamUserGetSigninInfo` (imports.cpp:809) rather than declaring a second copy
// of the value. No xuid and no gamertag originates in this file.
//
// REMOVAL CONDITION FOR ANYTHING REFUSED HERE. Every REFUSE below is a
// stand-in for a subsystem that does not exist, and each carries its own
// one-line trigger at its body. The three that are worth stating in one place:
//   * XAMPORT-REFUSE fn=XamShowAchievementsUI / XamShowFriendsUI /
//     XamShowMarketplaceUI / XamShowPlayerReviewUI -> delete the refusal and
//     dispatch a real dashboard dialog the moment a dashboard exists; the
//     marker row goes to zero and `XamIsUIActive` starts telling the truth.
//   * XAMPORT-REFUSE fn=XamReadTileToTexture / XamWriteGamerTile /
//     XamParseGamerTileKey -> delete when a tile store exists. Until then the
//     title must see the refusal, because a zero-filled or 0xFF-filled tile
//     buffer is a picture of a tile that does not exist.
//   * XAMPORT-REFUSE fn=XamUserAreUsersFriends / XamUserCheckPrivilege -> delete
//     when a signed-in profile exists; both currently report "there is nobody
//     to ask", which is true and will stop being true on its own.
//
// HOUSE CONVENTIONS (from the 12 already-ported bodies in imports.cpp):
//   * refusal rows: `n <= 8 || (n % 200) == 0`, attempts and outcomes kept
//     separate, marker prefix `XAMPORT-` unique to this file;
//   * output structs: the caller's guest VA is taken as a `uint32_t` and every
//     byte goes through mcla::kernel::GuestMemoryHeap's checked, endian-
//     explicit helpers (IsValid / ReadU32BE / WriteU32BE / WriteU64BE /
//     WriteBytes). No `reinterpret_cast` of guest data, no `assert` on a guest
//     value, and an out-parameter that is not wholly valid is REFUSED rather
//     than partially written;
//   * overlapped arguments are NOT completed when the operation did not
//     happen, exactly as XamContentDelete (imports.cpp:683) and
//     XamContentGetDeviceState (imports.cpp:763) already do.
//
// NEW SYMBOLS INTRODUCED (AGENTS.md rule 1b). All of them are
// `static`/anonymous-namespace file state in port_xam_user.cpp: the two
// `std::atomic` counter tables, the XamAlloc live-block registry, and the
// loader launch-data vector. No new external (non-static) host symbol is
// declared anywhere in this port except the 24 host bodies below, which
// REPLACE the 24 same-named dead definitions in imports.cpp and must be
// deleted in the same change (see the report's integration list).
// ===========================================================================
#pragma once

#include <cstdint>

// ---------------------------------------------------------------------------
// Status codes. Every value is quoted from the reference's own header,
// .research/xenia/src/xenia/xbox.h, with its line. None of them is invented and
// none of them is a host errno: `ERROR_INVALID_PARAMETER` in particular is a
// Windows value (87) and is NOT what any of these functions returns.
// ---------------------------------------------------------------------------
namespace mcla::port_xam_user {

// Win32-flavoured X_RESULTs (xenia/xbox.h:82-106)
inline constexpr uint32_t kXErrorSuccess = 0x00000000u;        // xbox.h:86
inline constexpr uint32_t kXErrorInvalidHandle = 0x00000006u;   // xbox.h:90
inline constexpr uint32_t kXErrorNoMoreFiles = 0x00000012u;     // xbox.h:91
inline constexpr uint32_t kXErrorInvalidParameter = 0x00000057u;// xbox.h:92
inline constexpr uint32_t kXErrorIoPending = 0x000003E5u;      // xbox.h:99
inline constexpr uint32_t kXErrorNotFound = 0x00000490u;       // xbox.h:101
inline constexpr uint32_t kXErrorNotLoggedOn = 0x000004DDu;    // xbox.h:103
inline constexpr uint32_t kXErrorNoSuchUser = 0x00000525u;     // xbox.h:104
inline constexpr uint32_t kXErrorFunctionFailed = 0x0000065Bu; // xbox.h:105

// NTSTATUS-flavoured (xenia/xbox.h:50-52)
inline constexpr uint32_t kXStatusInvalidHandle = 0xC0000008u; // xbox.h:50
inline constexpr uint32_t kXStatusNoMemory = 0xC0000017u;      // xbox.h:56

// HRESULT-flavoured, i.e. what X_E_* expands to (xenia/xbox.h:110-122).
// XamUserGetXUID/XamUserGetName return X_E_* (negative), not Win32 codes --
// that distinction is load-bearing and is reproduced exactly.
inline constexpr uint32_t kXEInvalidArg = 0x80070057u;          // xbox.h:119
inline constexpr uint32_t kXENoSuchUser = 0x80070525u;         // xbox.h:122

} // namespace mcla::port_xam_user

// ---------------------------------------------------------------------------
// THE 24 HOST BODIES. Global scope, exactly like the 12 already-ported
// functions in imports.cpp (imports.cpp:6365-6392) and the sibling ports in
// this integration batch (src/kernel/port_kobj.cpp:2278-2296), so the
// registration at the bottom of port_xam_user.cpp reads
//
//     GUEST_FUNCTION_HOOK(__imp__XamAlloc, XamAlloc);
//
// and the integration stream's only job is to DELETE the matching
// GUEST_FUNCTION_STUB lines. Every guest pointer argument is a raw 32-bit
// guest VA (uint32_t), never a host pointer, so the checked helpers are the
// only path by which this file can reach guest memory.
// ---------------------------------------------------------------------------

// --- REAL ------------------------------------------------------------------
uint32_t XamAlloc(uint32_t unk, uint32_t size, uint32_t outPtr);
uint32_t XamFree(uint32_t ptr);
uint32_t XamTaskShouldExit(uint32_t r3);
uint32_t XamLoaderSetLaunchData(uint32_t data, uint32_t size);
uint32_t XamLoaderGetLaunchDataSize(uint32_t sizePtr);
uint32_t XamLoaderGetLaunchData(uint32_t bufferPtr, uint32_t bufferSize);
uint32_t XamUserGetName(uint32_t userIndex, uint32_t buffer, uint32_t bufferLen);
uint32_t XamUserGetXUID(uint32_t userIndex, uint32_t typeMask, uint32_t xuidPtr);

// --- REFUSE ----------------------------------------------------------------
uint32_t XamCreateEnumeratorHandle(uint32_t a1, uint32_t a2, uint32_t a3,
                                   uint32_t a4, uint32_t a5, uint32_t a6,
                                   uint32_t a7, uint32_t a8);
uint32_t XamGetPrivateEnumStructureFromHandle(uint32_t handle,
                                             uint32_t outObjectPtr);
uint32_t XamUserCreateAchievementEnumerator(uint32_t titleId, uint32_t userIndex,
                                           uint32_t xuid, uint32_t flags,
                                           uint32_t offset, uint32_t count,
                                           uint32_t bufferSizePtr,
                                           uint32_t handlePtr);
uint32_t XamUserCreateStatsEnumerator(uint32_t r3, uint32_t r4, uint32_t r5,
                                     uint32_t r6, uint32_t r7, uint32_t r8,
                                     uint32_t r9, uint32_t r10);
uint32_t XamTaskCloseHandle(uint32_t handle);
uint32_t XamTaskSchedule(uint32_t callback, uint32_t message, uint32_t unknown,
                         uint32_t handlePtr);
uint32_t XamParseGamerTileKey(uint32_t keyPtr, uint32_t out1, uint32_t out2,
                             uint32_t out3);
uint32_t XamReadTileToTexture(uint32_t unknown, uint32_t titleId, uint32_t r4,
                              uint32_t r5, uint32_t userIndex, uint32_t bufferPtr,
                              uint32_t stride, uint32_t height);uint32_t XamWriteGamerTile(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4,
                          uint32_t a5, uint32_t overlappedPtr);
// NOTE ON THE FIVE XamShow*UI BODIES BELOW. The reference declares NO entry for
// any of these five exports -- they exist only as table rows
// (xenia/xenia/kernel/xam/xam_table.inc:499, :505, :506, :507, :521) with no
// DECLARE_XAM_EXPORT and no `_entry` function anywhere in the tree. In Xenia
// they are UNHANDLED EXPORTS: calling one raises, it does not return a status.
// This port therefore claims NO parameter list for them. Each body takes the
// raw leading GPRs r3..r6, logs them, and returns a status. Nothing is
// inferred from them, so no signature can be wrong.
uint32_t XamShowAchievementsUI(uint32_t r3, uint32_t r4, uint32_t r5,
                               uint32_t r6);
uint32_t XamShowFriendsUI(uint32_t r3, uint32_t r4, uint32_t r5, uint32_t r6);
uint32_t XamShowPlayerReviewUI(uint32_t r3, uint32_t r4, uint32_t r5,
                               uint32_t r6);
uint32_t XamShowMarketplaceUI(uint32_t r3, uint32_t r4, uint32_t r5,
                              uint32_t r6);
uint32_t XamShowGamerCardUIForXUID(uint32_t r3, uint32_t r4, uint32_t r5,
                                   uint32_t r6);
uint32_t XamUserAreUsersFriends(uint32_t userIndex, uint32_t unk1, uint32_t unk2,
                                uint32_t outValue, uint32_t overlappedPtr);
uint32_t XamUserCheckPrivilege(uint32_t userIndex, uint32_t mask,
                               uint32_t outValue);
