// ===========================================================================
// port_xam_user.cpp -- see port_xam_user.h for the full charter, the status
// table, and the removal conditions. Read that first; it is the contract this
// file is written against.
//
// Everything below is one of two things, and the word REAL or REFUSE plus the
// Xenia `file:line` is on every body:
//
//   REAL   -- the host genuinely owns the state the reference reads, so the
//             reference's own code path is reproduced. 8 of 24.
//   REFUSE -- the reference has no state to read here, so the real XOS status
//             for the situation we are actually in is returned, counted, and
//             logged under `XAMPORT-REFUSE`. 16 of 24.
//
// The census marker for this file is `XAMPORT-` (refusals) and `XAMPORT-REAL-`
// (implemented paths). A soak that sees zero `XAMPORT-REFUSE` rows is not
// evidence that these work; it is evidence the title never asked.
// ===========================================================================

#include <stdafx.h>

#include <cpu/ppc_context.h>

#include "function.h"
#include "memory.h"
#include "xbox.h"
#include "port_xam_user.h"
#include "logging.h"

#include <atomic>
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

using mcla::kernel::GuestMemoryHeap;

// ---------------------------------------------------------------------------
// THE ONE PROFILE SOURCE, REACHED THROUGH ITS OWN CONSUMER.
//
// `kXamSynthProfile` (src/kernel/imports.cpp:590) is file-static in an
// anonymous namespace, so it has no symbol this translation unit could link
// against. `XamUserGetSigninInfo` (imports.cpp:809) is at global scope and
// already IS a consumer of that same constant: it fills a host-side
// XUSER_SIGNIN_INFO from it, emits the `SYNTH-PROFILE fabricated` marker with
// the written removal trigger (imports.cpp:566-575), and returns
// X_ERROR_NO_SUCH_USER for any non-zero slot.
//
// Calling it is how this file reads the existing profile instead of declaring a
// second copy of its xuid and its name. NO new profile source is created here,
// and the forward declaration below adds NO new external symbol: it names a
// function that already exists.
// ---------------------------------------------------------------------------
uint32_t XamUserGetSigninInfo(uint32_t userIndex, uint32_t flags,
                              XUSER_SIGNIN_INFO* info);

namespace {

using namespace mcla::port_xam_user;

// ---------------------------------------------------------------------------
// The guest LR, for attribution. Read exactly the way boot_host.cpp:117 reads
// it, through the accessor, so this file never needs to reason about whether
// the thread-local context is alive.
// ---------------------------------------------------------------------------
inline uint32_t Glr() {
  if (const PPCContext* pc = GetPPCContext())
    return static_cast<uint32_t>(pc->lr);
  return 0u;
}

// ---------------------------------------------------------------------------
// THE CENSUS. One counter per function, shared by both outcomes, so a soak can
// separate "the title asked and we answered" from "the title asked and we
// refused" without arithmetic across files. House pattern for the log gate is
// `n <= 8 || (n % 200) == 0` (imports.cpp:605, :643, :694, :766, :1016).
// ---------------------------------------------------------------------------
enum Fn : size_t {
  kXamAlloc = 0,
  kXamFree,
  kXamCreateEnumeratorHandle,
  kXamGetPrivateEnumStructureFromHandle,
  kXamUserCreateAchievementEnumerator,
  kXamUserCreateStatsEnumerator,
  kXamTaskCloseHandle,
  kXamTaskSchedule,
  kXamTaskShouldExit,
  kXamLoaderGetLaunchData,
  kXamLoaderGetLaunchDataSize,
  kXamLoaderSetLaunchData,
  kXamParseGamerTileKey,
  kXamReadTileToTexture,
  kXamWriteGamerTile,
  kXamShowAchievementsUI,
  kXamShowFriendsUI,
  kXamShowPlayerReviewUI,
  kXamShowMarketplaceUI,
  kXamShowGamerCardUIForXUID,
  kXamUserAreUsersFriends,
  kXamUserCheckPrivilege,
  kXamUserGetName,
  kXamUserGetXUID,
  kFnCount
};

const char* const kFnName[kFnCount] = {
    "XamAlloc",
    "XamFree",
    "XamCreateEnumeratorHandle",
    "XamGetPrivateEnumStructureFromHandle",
    "XamUserCreateAchievementEnumerator",
    "XamUserCreateStatsEnumerator",
    "XamTaskCloseHandle",
    "XamTaskSchedule",
    "XamTaskShouldExit",
    "XamLoaderGetLaunchData",
    "XamLoaderGetLaunchDataSize",
    "XamLoaderSetLaunchData",
    "XamParseGamerTileKey",
    "XamReadTileToTexture",
    "XamWriteGamerTile",
    "XamShowAchievementsUI",
    "XamShowFriendsUI",
    "XamShowPlayerReviewUI",
    "XamShowMarketplaceUI",
    "XamShowGamerCardUIForXUID",
    "XamUserAreUsersFriends",
    "XamUserCheckPrivilege",
    "XamUserGetName",
    "XamUserGetXUID",
};

struct Counters {
  std::atomic<uint64_t> attempts{0};
  std::atomic<uint64_t> refusals{0};
};
Counters g_counters[kFnCount];

// A refusal: the situation is real, the answer is the reference's own status
// for it, and the row is countable. `code` is echoed numerically AND the name
// is echoed, so a soak never has to know the table to read the row.
uint32_t Refuse(Fn fn, uint32_t code, const char* why, uint32_t detail) {
  const uint64_t n = g_counters[fn].attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  const uint64_t r = g_counters[fn].refusals.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN(
        "XAMPORT-REFUSE #{:04} fn={} code=0x{:08X} arg={:08X} attempts={} "
        "refusals={} -- {} glr={:08X}",
        n, kFnName[fn], code, detail, n, r, why, Glr());
  }
  return code;
}

// An implemented path, counted the same way so REAL and REFUSE rows for one
// function are directly comparable.
uint32_t Real(Fn fn, uint32_t code, const char* what, uint32_t detail) {
  const uint64_t n = g_counters[fn].attempts.fetch_add(
                         1, std::memory_order_relaxed) +
                     1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_INFO("XAMPORT-REAL-OK #{:04} fn={} code=0x{:08X} arg={:08X} -- {} "
                  "glr={:08X}",
                  n, kFnName[fn], code, detail, what, Glr());
  }
  return code;
}

// ---------------------------------------------------------------------------
// The ONE out-parameter write helper, so no body can invent a second way to
// reach guest memory. It refuses (returns false, writes NOTHING) unless the
// WHOLE range is valid -- the "refuse rather than write a partial struct" rule.
// `GuestMemoryHeap::IsValid` is the range check (memory.h:46); the writes go
// through the checked, endian-explicit accessors (memory.h:102-106).
// ---------------------------------------------------------------------------
bool PutU32(uint32_t va, uint32_t value) {
  if (va == 0 || !GuestMemoryHeap::Instance().IsValid(va, 4))
    return false;
  return GuestMemoryHeap::Instance().WriteU32BE(va, value);
}

bool PutU64(uint32_t va, uint64_t value) {
  if (va == 0 || !GuestMemoryHeap::Instance().IsValid(va, 8))
    return false;
  return GuestMemoryHeap::Instance().WriteU64BE(va, value);
}

bool PutBytes(uint32_t va, const void* src, uint32_t size) {
  if (va == 0 || size == 0)
    return false;
  if (!GuestMemoryHeap::Instance().IsValid(va, size))
    return false;
  return GuestMemoryHeap::Instance().WriteBytes(va, src, size);
}

// ---------------------------------------------------------------------------
// XamAlloc / XamFree LIVE-BLOCK REGISTRY. `GuestMemoryHeap::Free`
// (memory.cpp:346-356) takes a size it does not use and hands the pointer
// straight to `g_userHeap.Free`, and `GetKernelHandle`-style lookups elsewhere
// will happily translate an arbitrary guest VA into an object. So a Free that
// did not first ask "did I hand this out?" would be an arbitrary free driven by
// guest data. The registry is what makes XamFree a real inverse of XamAlloc.
//
// File-static (AGENTS.md rule 1b: no new external symbol).
// ---------------------------------------------------------------------------
std::mutex g_allocMutex;
std::unordered_map<uint32_t, uint32_t> g_allocLive; // guest VA -> bytes requested
std::atomic<uint64_t> g_allocCalls{0};
std::atomic<uint64_t> g_freeCalls{0};
std::atomic<uint64_t> g_allocLiveCount{0};

// ---------------------------------------------------------------------------
// LOADER LAUNCH DATA. This host has no dashboard, no argv, and no second title,
// so nothing has ever set launch data and the initial state below is not a
// guess -- it is the truth. XamLoaderSetLaunchData is the only writer, and it
// stores exactly the bytes the title handed over, so the pair
// (Set -> Size/Get) is a real round trip rather than an invented blob.
//
// REMOVAL TRIGGER: delete this block, and make XamLoaderGetLaunchDataSize
// return kXErrorNotFound unconditionally, the moment a real launch-data source
// exists in this tree (a command line, a dashboard hand-off, a second-title
// launch path). Until then, "no launch data" is a fact, not a default.
// ---------------------------------------------------------------------------
std::mutex g_launchDataMutex;
std::vector<uint8_t> g_launchData;
bool g_launchDataPresent = false;
std::atomic<uint64_t> g_launchDataSets{0};

} // namespace

// ===========================================================================
// REAL (8 of 24)
// ===========================================================================

// XamAlloc -- REAL.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_info.cc:324-333
//     uint32_t ptr = kernel_state()->memory()->SystemHeapAlloc(size);
//     *out_ptr = ptr;
//     return X_ERROR_SUCCESS;
// The host genuinely owns an allocator: `GuestMemoryHeap::Alloc` is the same
// arena the guest's own __xtl_alloc draws from (imports.cpp:53-59), so the
// pointer returned is a real, addressable, freeable guest address.
//
// The reference's `assert_true(unk == 0)` (xam_info.cc:325) is NOT reproduced:
// this charter forbids asserting on a guest value. A non-zero first argument
// is counted and refused instead.
// `size == 0` is refused with STATUS_NO_MEMORY rather than returning a
// zero-size block: `AllocPhysical(0)` has no defined meaning here and a
// non-zero pointer the guest then writes through would be a wild write.
uint32_t XamAlloc(uint32_t unk, uint32_t size, uint32_t outPtr) {
  if (outPtr == 0 || !GuestMemoryHeap::Instance().IsValid(outPtr, 4)) {
    return Refuse(kXamAlloc, kXErrorInvalidParameter,
                  "out-pointer is not a valid guest dword; nothing written",
                  outPtr);
  }
  if (unk != 0) {
    return Refuse(kXamAlloc, kXErrorInvalidParameter,
                  "first argument is not 0; the reference asserts this and this "
                  "port refuses instead of asserting on a guest value",
                  unk);
  }
  if (size == 0) {
    return Refuse(kXamAlloc, kXStatusNoMemory,
                  "zero-size allocation refused: no block, no pointer written",
                  size);
  }
  // size + 7 rounded up so a guest that over-reads by a few bytes stays inside
  // the block; the reference does not do this, but it is strictly safer and
  // cannot change the address the guest sees.
  const uint32_t want = (size + 7u) & ~7u;
  const uint32_t va = GuestMemoryHeap::Instance().Alloc(want, 8);
  if (va == 0) {
    return Refuse(kXamAlloc, kXStatusNoMemory,
                  "the arena returned 0; out-pointer left untouched", size);
  }
  {
    std::lock_guard<std::mutex> lock(g_allocMutex);
    g_allocLive[va] = want;
  }
  g_allocLiveCount.fetch_add(1, std::memory_order_relaxed);
  const uint64_t n = g_allocCalls.fetch_add(1, std::memory_order_relaxed) + 1;
  if (!PutU32(outPtr, va)) {
    // The block exists but the caller cannot be told where. Free it rather
    // than leak it, and say so.
    {
      std::lock_guard<std::mutex> lock(g_allocMutex);
      g_allocLive.erase(va);
    }
    GuestMemoryHeap::Instance().Free(va, want);
    g_allocLiveCount.fetch_sub(1, std::memory_order_relaxed);
    return Refuse(kXamAlloc, kXErrorInvalidParameter,
                  "out-pointer rejected at write time; block released again",
                  va);
  }
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_INFO("XAMPORT-REAL-OK XamAlloc #{:04} va={:08X} size={} "
                  "live={} glr={:08X}",
                  n, va, want,
                  g_allocLiveCount.load(std::memory_order_relaxed), Glr());
  }
  return Real(kXamAlloc, kXErrorSuccess, "real arena allocation", va);
}

// XamFree -- REAL.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_info.cc:336-340
//     kernel_state()->memory()->SystemHeapFree(ptr.guest_address());
//     return X_ERROR_SUCCESS;
// Same allocator, and the registry above is what makes this an inverse rather
// than a wild free: a pointer this port did not hand out is refused with
// X_ERROR_INVALID_HANDLE (xenia/xbox.h:90) instead of being released. The
// reference has no such check because Xenia's SystemHeapFree is a heap that
// can answer "was this mine"; this one cannot, so it is asked.
uint32_t XamFree(uint32_t ptr) {
  if (ptr == 0) {
    return Refuse(kXamFree, kXErrorInvalidHandle,
                  "null pointer; nothing freed", 0);
  }
  uint32_t want = 0;
  {
    std::lock_guard<std::mutex> lock(g_allocMutex);
    auto it = g_allocLive.find(ptr);
    if (it == g_allocLive.end()) {
      return Refuse(kXamFree, kXErrorInvalidHandle,
                    "pointer was not handed out by XamAlloc; refused rather "
                    "than released, because GuestMemoryHeap::Free "
                    "(memory.cpp:346) would free whatever the guest named",
                    ptr);
    }
    want = it->second;
    g_allocLive.erase(it);
  }
  GuestMemoryHeap::Instance().Free(ptr, want);
  g_allocLiveCount.fetch_sub(1, std::memory_order_relaxed);
  const uint64_t n = g_freeCalls.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_INFO("XAMPORT-REAL-OK XamFree #{:04} va={:08X} size={} live={} "
                  "glr={:08X}",
                  n, ptr, want, g_allocLiveCount.load(std::memory_order_relaxed),
                  Glr());
  }
  return Real(kXamFree, kXErrorSuccess, "released a block this port allocated",
              ptr);
}

// XamTaskShouldExit -- REAL.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_task.cc:72-73
//     dword_result_t XamTaskShouldExit_entry(dword_t r3) { return 0; }
//     DECLARE_XAM_EXPORT2(XamTaskShouldExit, kNone, kStub, kSketchy);
// Xenia marks this kStub, and so is this -- but a stub here is not a dodge,
// because 0 is the TRUE answer: nothing in this host has ever asked a task to
// exit. There is no shutdown signal, no title-termination path, and no
// XamTaskCloseHandle that could retire one (it refuses, below). Returning 0 is
// answering from real state, not inventing state. The body exists so that the
// answer is asserted once, counted, and attributed to a guest LR instead of
// being whatever the guest left in r3.
uint32_t XamTaskShouldExit(uint32_t r3) {
  (void)r3;
  return Real(kXamTaskShouldExit, 0u,
              "no exit has ever been requested for any task on this host, so "
              "the truthful answer is 0 (xam_task.cc:72)",
              r3);
}

// XamLoaderSetLaunchData -- REAL.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_info.cc:247-254
//     loader_data.launch_data_present = size ? true : false;
//     loader_data.launch_data.resize(size);
//     std::memcpy(loader_data.launch_data.data(), data, size);
//     return 0;
// The blob is not invented: it is the bytes the title itself supplied, copied
// verbatim into the one host store that XamLoaderGetLaunchData/Size read. This
// makes the three loader functions a coherent round trip where the honest
// initial state is "absent" -- and absent is the truth here, because this
// process has no dashboard, no command line and no second title.
uint32_t XamLoaderSetLaunchData(uint32_t data, uint32_t size) {
  std::vector<uint8_t> blob;
  if (size != 0) {
    if (data == 0 || !GuestMemoryHeap::Instance().IsValid(data, size)) {
      return Refuse(kXamLoaderSetLaunchData, kXErrorInvalidParameter,
                    "source range is not wholly valid; store left unchanged",
                    data);
    }
    blob.resize(size);
    if (!GuestMemoryHeap::Instance().ReadBytes(data, blob.data(), size)) {
      return Refuse(kXamLoaderSetLaunchData, kXErrorInvalidParameter,
                    "source range could not be read; store left unchanged", data);
    }
  }
  {
    std::lock_guard<std::mutex> lock(g_launchDataMutex);
    g_launchData.swap(blob);
    g_launchDataPresent = (size != 0);
  }
  const uint64_t n = g_launchDataSets.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_INFO("XAMPORT-REAL-OK XamLoaderSetLaunchData #{:04} size={} "
                  "present={} glr={:08X}",
                  n, size, size != 0 ? 1 : 0, Glr());
  }
  return Real(kXamLoaderSetLaunchData, 0u,
              "stored exactly the bytes the title supplied; nothing invented",
              size);
}

// XamLoaderGetLaunchDataSize -- REAL (and REFUSE on the absent path).
// Reference: .research/xenia/src/xenia/kernel/xam/xam_info.cc:257-271
//     if (!size_ptr) return X_ERROR_INVALID_PARAMETER;
//     if (!loader_data.launch_data_present) { *size_ptr = 0; return X_ERROR_NOT_FOUND; }
//     *size_ptr = loader_data.launch_data.size();
//     return X_ERROR_SUCCESS;
// Both of Xenia's arms are reproduced. Note the absent arm WRITES 0 before
// returning X_ERROR_NOT_FOUND (xam_info.cc:265-266): that is not a
// fabrication, it is the truthful size of nothing, and it spares the guest its
// own uninitialised stack value. The refusal marker fires on that arm only.
uint32_t XamLoaderGetLaunchDataSize(uint32_t sizePtr) {
  if (sizePtr == 0 || !GuestMemoryHeap::Instance().IsValid(sizePtr, 4)) {
    return Refuse(kXamLoaderGetLaunchDataSize, kXErrorInvalidParameter,
                  "size out-pointer is not a valid guest dword; nothing written",
                  sizePtr);
  }
  bool present = false;
  uint32_t size = 0;
  {
    std::lock_guard<std::mutex> lock(g_launchDataMutex);
    present = g_launchDataPresent;
    size = static_cast<uint32_t>(g_launchData.size());
  }
  if (!present) {
    // xam_info.cc:265-266 -- the truthful zero, then the truthful status.
    if (!PutU32(sizePtr, 0)) {
      return Refuse(kXamLoaderGetLaunchDataSize, kXErrorInvalidParameter,
                    "size out-pointer rejected at write time", sizePtr);
    }
    return Refuse(kXamLoaderGetLaunchDataSize, kXErrorNotFound,
                  "no launch data has ever been set on this host (no dashboard, "
                  "no command line, no second title); wrote the truthful 0 per "
                  "xam_info.cc:265",
                  size);
  }
  if (!PutU32(sizePtr, size)) {
    return Refuse(kXamLoaderGetLaunchDataSize, kXErrorInvalidParameter,
                  "size out-pointer rejected at write time", sizePtr);
  }
  return Real(kXamLoaderGetLaunchDataSize, kXErrorSuccess,
              "reported the size the title itself stored", size);
}

// XamLoaderGetLaunchData -- REAL (and REFUSE on the absent path).
// Reference: .research/xenia/src/xenia/kernel/xam/xam_info.cc:274-286
//     if (!loader_data.launch_data_present) return X_ERROR_NOT_FOUND;
//     copy_size = min(launch_data.size(), buffer_size);
//     memcpy(buffer_ptr, launch_data.data(), copy_size);
//     return X_ERROR_SUCCESS;
// The absent arm writes NOTHING and returns X_ERROR_NOT_FOUND. That is the
// whole point: the reference's copy is a copy of what the title put in, and
// when there is nothing, there is no copy to make. The truncation at
// `min(size, buffer_size)` is the reference's own, reproduced.
uint32_t XamLoaderGetLaunchData(uint32_t bufferPtr, uint32_t bufferSize) {
  std::vector<uint8_t> blob;
  {
    std::lock_guard<std::mutex> lock(g_launchDataMutex);
    if (!g_launchDataPresent) {
      return Refuse(kXamLoaderGetLaunchData, kXErrorNotFound,
                    "no launch data has ever been set on this host; 0 bytes "
                    "written (xam_info.cc:278-280)",
                    bufferPtr);
    }
    blob = g_launchData;
  }
  const uint32_t copy =
      blob.size() < bufferSize ? static_cast<uint32_t>(blob.size()) : bufferSize;
  if (copy != 0 && !PutBytes(bufferPtr, blob.data(), copy)) {
    return Refuse(kXamLoaderGetLaunchData, kXErrorInvalidParameter,
                  "caller buffer is not wholly valid; refused rather than "
                  "partially written",
                  bufferPtr);
  }
  return Real(kXamLoaderGetLaunchData, kXErrorSuccess,
              "copied back only what the title itself stored", copy);
}

// XamUserGetName -- REAL, AND IT READS THE EXISTING LABELLED PROFILE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:105-120
//     if (user_index >= 4) return X_E_INVALIDARG;             // :107-109
//     if (user_index)       return X_E_NO_SUCH_USER;          // :111-113
//     copy_truncating(buffer, user_profile->name(), min(buffer_len, 16));
//     return X_ERROR_SUCCESS;                                 // :119
// WHY THIS IS REAL AND NOT A SECOND FABRICATION. The one synthetic user in
// this host is `kXamSynthProfile` (imports.cpp:590) and it is file-static in an
// anonymous namespace, so it cannot be read from here and this file does NOT
// redeclare its value. Instead this body calls the EXISTING consumer
// `XamUserGetSigninInfo` (imports.cpp:809) -- which is the same profile, under
// the same `SYNTH-PROFILE fabricated` marker and the same written removal
// trigger (imports.cpp:566-575) -- and copies the name out of the host-side
// struct it fills. There is exactly one profile source in this process and it
// is that one.
//
// The truncation is the reference's: at most 16 bytes, always NUL terminated
// (Xenia's `copy_truncating`, which is a truncating strcpy). The >= 4 bound is
// the reference's and is honoured explicitly, because `XamUserGetSigninInfo`
// treats every non-zero slot alike and does not itself implement the >= 4 arm.
// The two X_E_* codes are HRESULTs (xenia/xbox.h:119, :122), i.e. NEGATIVE, and
// they are returned as such -- a Win32 0x57 here would be a different answer
// from the reference.
uint32_t XamUserGetName(uint32_t userIndex, uint32_t buffer,
                        uint32_t bufferLen) {
  if (userIndex >= 4) {
    return Refuse(kXamUserGetName, kXEInvalidArg,
                  "slot >= 4 is X_E_INVALIDARG per xam_user.cc:107-109", userIndex);
  }
  if (userIndex != 0) {
    return Refuse(kXamUserGetName, kXENoSuchUser,
                  "only slot 0 can hold a profile; xam_user.cc:111-113",
                  userIndex);
  }
  if (bufferLen == 0) {
    return Refuse(kXamUserGetName, kXEInvalidArg,
                  "zero-length buffer; nothing written", bufferLen);
  }
  // xam_user.cc:117-118 -- min(buffer_len, 16), and always room for the NUL.
  const uint32_t cap = bufferLen < 16 ? bufferLen : 16;
  if (!GuestMemoryHeap::Instance().IsValid(buffer, cap)) {
    return Refuse(kXamUserGetName, kXEInvalidArg,
                  "caller buffer is not wholly valid; refused rather than "
                  "partially written",
                  buffer);
  }
  XUSER_SIGNIN_INFO info; // host-local; never guest memory, so no cast on it
  const uint32_t rc = XamUserGetSigninInfo(0, 0, &info);
  if (rc != 0) {
    return Refuse(kXamUserGetName, kXEInvalidArg,
                  "the existing profile source refused to answer", rc);
  }
  char name[sizeof(info.Name) + 1];
  std::memcpy(name, info.Name, sizeof(info.Name));
  name[sizeof(info.Name)] = '\0';
  const size_t len = std::strlen(name);
  const size_t copy = len < cap - 1 ? len : cap - 1;
  if (!PutBytes(buffer, name, static_cast<uint32_t>(copy) + 1)) {
    return Refuse(kXamUserGetName, kXEInvalidArg,
                  "caller buffer rejected at write time", buffer);
  }
  return Real(kXamUserGetName, 0u,
              "name read from the existing labelled synthetic profile via its "
              "own accessor XamUserGetSigninInfo (imports.cpp:809); no second "
              "value originates here",
              static_cast<uint32_t>(copy));
}

// XamUserGetXUID -- REAL, AND IT READS THE EXISTING LABELLED PROFILE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:29-57
//     assert_true(type_mask == 1|2|3|4|7);                  // :31-32
//     if (!xuid_ptr) return X_E_INVALIDARG;                  // :33-35
//     result = X_E_NO_SUCH_USER; xuid = 0;                   // :36-37
//     if (user_index < 4 && user_index == 0) { ... }         // :38-51
//     else if (user_index >= 4) result = X_E_INVALIDARG;     // :52-54
//     *xuid_ptr = xuid;  return result;                      // :55-56
// THREE THINGS WORTH NAMING.
// 1. The reference's `assert_true` on `type_mask` (xam_user.cc:31) is NOT
//    reproduced -- asserting on a guest value is forbidden. An out-of-set mask
//    is counted and refused with the same X_E_INVALIDARG the reference returns
//    for its other bad argument.
// 2. The online/offline profile branch (xam_user.cc:42-50) is NOT reproduced
//    and does not need to be: both arms assign `user_profile->xuid()` and
//    X_E_SUCCESS, so the branch is behaviourally identical and there is no
//    profile TYPE to invent. The xuid comes from the existing labelled profile
//    through the same accessor XamUserGetName uses.
// 3. `*xuid_ptr = 0` happens on EVERY refusal (xam_user.cc:55 is unconditional),
//    so the guest is not left reading its own uninitialised 64-bit slot. When
//    the slot itself is not wholly valid, nothing is written.
uint32_t XamUserGetXUID(uint32_t userIndex, uint32_t typeMask, uint32_t xuidPtr) {
  if (xuidPtr == 0 || !GuestMemoryHeap::Instance().IsValid(xuidPtr, 8)) {
    return Refuse(kXamUserGetXUID, kXEInvalidArg,
                  "xuid out-pointer is not a valid guest qword; nothing written",
                  xuidPtr);
  }
  if (typeMask != 1 && typeMask != 2 && typeMask != 3 && typeMask != 4 &&
      typeMask != 7) {
    // xam_user.cc:31-32 asserts this. Refused, not asserted.
    (void)PutU64(xuidPtr, 0); // xam_user.cc:55 -- unconditional
    return Refuse(kXamUserGetXUID, kXEInvalidArg,
                  "type_mask is outside {1,2,3,4,7}; the reference asserts this "
                  "and this port refuses instead of asserting on a guest value "
                  "(xam_user.cc:31-32). Wrote the truthful 0 per :55",
                  typeMask);
  }
  if (userIndex >= 4) {
    (void)PutU64(xuidPtr, 0); // xam_user.cc:55
    return Refuse(kXamUserGetXUID, kXEInvalidArg,
                  "slot >= 4 is X_E_INVALIDARG per xam_user.cc:52-54; wrote the "
                  "truthful 0 per :55",
                  userIndex);
  }
  if (userIndex != 0) {
    (void)PutU64(xuidPtr, 0); // xam_user.cc:36-37, :55
    return Refuse(kXamUserGetXUID, kXENoSuchUser,
                  "only slot 0 can hold a profile; X_E_NO_SUCH_USER per "
                  "xam_user.cc:36-37; wrote the truthful 0 per :55",
                  userIndex);
  }
  XUSER_SIGNIN_INFO info; // host-local
  const uint32_t rc = XamUserGetSigninInfo(0, 0, &info);
  if (rc != 0) {
    (void)PutU64(xuidPtr, 0);
    return Refuse(kXamUserGetXUID, kXEInvalidArg,
                  "the existing profile source refused to answer; wrote the "
                  "truthful 0",
                  rc);
  }
  if (!PutU64(xuidPtr, static_cast<uint64_t>(info.xuid.get()))) {
    return Refuse(kXamUserGetXUID, kXEInvalidArg,
                  "xuid out-pointer rejected at write time", xuidPtr);
  }
  return Real(kXamUserGetXUID, 0u,
              "xuid read from the existing labelled synthetic profile via its "
              "own accessor XamUserGetSigninInfo (imports.cpp:809); no second "
              "value originates here",
              userIndex);
}

// ===========================================================================
// REFUSE (16 of 24)
// ===========================================================================

// XamCreateEnumeratorHandle -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_enum.cc:86-91
//     dword_result_t XamCreateEnumeratorHandle_entry(unknown_t ... x8) {
//       return X_ERROR_INVALID_PARAMETER;
//     }
//     DECLARE_XAM_EXPORT1(XamCreateEnumeratorHandle, kNone, kStub);
// The reference itself answers INVALID_PARAMETER unconditionally, and that
// happens to be the truth here as well: this host has no XEnumerator factory
// of any kind, so there is no factory to call. This is a refusal that
// reproduces the reference's own refusal rather than inventing one, and it is
// still counted -- a zero here would mean "an enumerator was created".
uint32_t XamCreateEnumeratorHandle(uint32_t a1, uint32_t a2, uint32_t a3,
                                   uint32_t a4, uint32_t a5, uint32_t a6,
                                   uint32_t a7, uint32_t a8) {
  (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8;
  return Refuse(kXamCreateEnumeratorHandle, kXErrorInvalidParameter,
                "this host has no XEnumerator factory and no enumerator object "
                "table; the reference also returns X_ERROR_INVALID_PARAMETER "
                "unconditionally (xam_enum.cc:86-91), so no handle was created",
                a1);
}

// XamGetPrivateEnumStructureFromHandle -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_enum.cc:94-110
//     auto e = kernel_state()->object_table()->LookupObject<XEnumerator>(handle);
//     if (!e) { return X_STATUS_INVALID_HANDLE; }
//     e->RetainHandle();
//     if (out_object_ptr.guest_address()) *out_object_ptr = e->guest_object();
//     return X_STATUS_SUCCESS;
// The lookup is the whole body, and here it always fails: there is no
// XEnumerator in this process, so no handle can name one. X_STATUS_INVALID_HANDLE
// (0xC0000008, xenia/xbox.h:50) is the reference's own not-found answer, not a
// substitute. Nothing is written to the out-pointer -- the reference writes a
// real guest object address on success and this port has none to write. Note
// the handle the guest holds is 0 in practice, because the sibling
// `XamContentCreateEnumerator` (src/kernel/xam.cpp:219) never creates one;
// that is a separate finding and is not fixed from here.
uint32_t XamGetPrivateEnumStructureFromHandle(uint32_t handle,
                                             uint32_t outObjectPtr) {
  (void)outObjectPtr;
  return Refuse(kXamGetPrivateEnumStructureFromHandle, kXStatusInvalidHandle,
                "no XEnumerator object exists on this host, so the reference's "
                "LookupObject<XEnumerator> (xam_enum.cc:96) has nothing to find; "
                "no reference was taken and no guest object address written",
                handle);
}

// XamUserCreateAchievementEnumerator -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:649-702
//     ... *buffer_size_ptr = entry_size * count;
//     ... db = kernel_state()->title_xdbf();
//     if (db.is_valid()) { for (entry : db.GetAchievements()) e->AppendItem(...); }
//     *handle_ptr = e->handle(); return X_ERROR_SUCCESS;
// Every value in that body comes from the title's own XDBF achievement table
// (xam_user.cc:677-698) read through `kernel_state()->title_xdbf()`. This host
// has no XDBF and no achievements service, so there is no table, no image id,
// no gamerscore and no label text. Writing the size the reference would compute
// (xam_user.cc:666-668) would be a plausible-looking buffer size for a list that
// does not exist, and the guest would then size a read around a fiction -- so
// NEITHER out-parameter is written. X_ERROR_FUNCTION_FAILED (xenia/xbox.h:105)
// is the honest "this subsystem is not here" answer.
//
// REMOVAL TRIGGER: delete this refusal when an XDBF reader and an achievement
// store exist in this tree. The `XAMPORT-REFUSE fn=XamUserCreateAchievement-
// Enumerator` row is the handle.
uint32_t XamUserCreateAchievementEnumerator(uint32_t titleId, uint32_t userIndex,
                                           uint32_t xuid, uint32_t flags,
                                           uint32_t offset, uint32_t count,
                                           uint32_t bufferSizePtr,
                                           uint32_t handlePtr) {
  (void)titleId; (void)userIndex; (void)xuid; (void)flags; (void)offset;
  (void)bufferSizePtr; (void)handlePtr;
  return Refuse(kXamUserCreateAchievementEnumerator, kXErrorFunctionFailed,
                "no XDBF achievement table and no achievements service on this "
                "host, so xam_user.cc:677-698 has nothing to read; neither the "
                "buffer size (:666-668) nor the handle (:700) was written",
                count);
}

// XamUserCreateStatsEnumerator -- REFUSE.
// Reference: NONE. This export exists only as a table row --
// .research/xenia/src/xenia/kernel/xam/xam_table.inc:555 -- with no
// DECLARE_XAM_EXPORT and no `_entry` anywhere in the tree, so Xenia does not
// implement it at all: on Xenia this call RAISES (an unhandled export) rather
// than returning. Returning X_ERROR_FUNCTION_FAILED is therefore strictly
// better than the reference, not a divergence from it, and it is the honest
// answer: stats are an Xbox Live service and there is no network here. No
// handle and no buffer size is written.
//
// REMOVAL TRIGGER: delete when a stats service exists; the marker row is the
// handle.
uint32_t XamUserCreateStatsEnumerator(uint32_t r3, uint32_t r4, uint32_t r5,
                                      uint32_t r6, uint32_t r7, uint32_t r8,
                                      uint32_t r9, uint32_t r10) {
  (void)r4; (void)r5; (void)r6; (void)r7; (void)r8; (void)r9; (void)r10;
  return Refuse(kXamUserCreateStatsEnumerator, kXErrorFunctionFailed,
                "the reference has NO implementation of this export "
                "(xam_table.inc:555 only; no DECLARE_XAM_EXPORT, no _entry), so "
                "Xenia raises here; stats are an Xbox Live service and this "
                "host has no network. No handle and no buffer size written",
                r3);
}

// XamTaskCloseHandle -- REFUSE.
// Reference: NONE, same as above (xam_table.inc:230 is the only mention).
// More importantly there is nothing to close and no safe way to close it.
// XamTaskSchedule below refuses, so this port never mints a task handle; and
// the only host close path, `DestroyKernelObject(uint32_t)`
// (src/kernel/xdm.cpp:25-30), resolves the handle through `GetKernelObject`
// (xdm.h:57-78) whose LAST RESORT is `reinterpret_cast<T*>(raw)` on any
// translated guest address. A guest-supplied handle would therefore be an
// arbitrary heap free driven by guest data, including a free of a live
// GuestThreadHandle whose host thread is still running guest code inside it.
// X_ERROR_INVALID_HANDLE (xenia/xbox.h:90) is the honest answer: there is no
// such handle, and this port declines to make one up.
//
// REMOVAL TRIGGER: implement a real task-handle registry first, then make
// CloseHandle look the handle up in THAT registry -- never in the kernel object
// table -- before deleting this refusal.
uint32_t XamTaskCloseHandle(uint32_t handle) {
  return Refuse(kXamTaskCloseHandle, kXErrorInvalidHandle,
                "no task handle exists to close (XamTaskSchedule refuses), and "
                "DestroyKernelObject(uint32_t) (xdm.cpp:25-30) would release "
                "whatever guest address it were handed via the raw fallback at "
                "xdm.h:76; declined rather than free guest-named memory",
                handle);
}

// XamTaskSchedule -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_task.cc:42-69
//     *handle_ptr = 12345;                                  // :46
//     auto thread = object_ref<XThread>(new XThread(..., callback, message, ...));
//     ... return X_STATUS_SUCCESS;                           // :68
// This host CAN start a guest thread -- `GuestThread::Start` is what
// NtCreateThread already uses (imports.cpp:5885) -- and that is exactly why the
// refusal is the right call rather than the timid one. What the reference is
// really doing is establishing a TASK: a handle (`12345`, a literal) whose
// lifetime is managed by XamTaskCloseHandle and whose exit is polled by
// XamTaskShouldExit. Two of those three legs cannot be built honestly here
// (CloseHandle above, and there is no task object to hold the state), so
// porting the thread half alone would hand the title a live host thread plus a
// handle it can never close and an exit signal that is structurally always
// zero. That is a fabricated lifecycle wearing a real thread.
//
// THE RETURN VALUE IS THE ONE MEASURED RISK, AND IT IS BENIGN. The single
// guest call site is `bl 0x827bd384` at guest 0x8244EB28
// (generated/ppc_xenon/ppc_recomp.80.cpp:12230-12238), which reads
//     ctx.lr = 0x8244EB2C; __imp__XamTaskSchedule(ctx, base);
//     cmpwi r3,0 / blt 0x8244eb64
// i.e. it branches on r3 SIGNED-negative. The empty stub left r3 holding the
// guest's own first argument (a positive callback address, `addi r3,r10,-6856`
// at ppc_recomp.80.cpp:12229), so `blt` was NOT taken. X_ERROR_FUNCTION_FAILED
// (0x0000065B, xenia/xbox.h:105) is also positive, so the branch is unchanged.
// A negative status here WOULD have flipped it, which is why this one is
// deliberately a Win32 code and not an HRESULT.
//
// REMOVAL TRIGGER: a task-handle registry + a real XamTaskCloseHandle.
uint32_t XamTaskSchedule(uint32_t callback, uint32_t message, uint32_t unknown,
                         uint32_t handlePtr) {
  (void)message; (void)unknown; (void)handlePtr;
  return Refuse(kXamTaskSchedule, kXErrorFunctionFailed,
                "no task object exists on this host; the reference's handle is "
                "the literal 12345 (xam_task.cc:46) and its two siblings "
                "(CloseHandle, and a pollable exit) are not implementable, so "
                "starting the thread half alone would fabricate a lifecycle. "
                "Positive status: the guest's `blt` at 0x8244EB2C+4 is "
                "unchanged from the empty stub",
                callback);
}

// XamParseGamerTileKey -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:706-713
//     *out1_ptr = 0xC0DE0001;
//     *out2_ptr = 0xC0DE0002;
//     *out3_ptr = 0xC0DE0003;
//     return X_ERROR_SUCCESS;
// Three magic constants and SUCCESS. That is a fabricated tile key presented as
// a lookup, and it is precisely the shape the already-found bug took elsewhere
// in this port (XamLoaderMediaGetInfo writing 16 bytes to r4 instead of to the
// caller's buffer, imports.cpp:986-1027). Here NOTHING is written: not to the
// three out-pointers, and not to the key pointer. The reference also
// dereferences all four without a single null check; this port checks every
// range and refuses rather than partially writing. The title will see
// X_ERROR_NOT_FOUND and will read its own uninitialised out-pointers -- that is
// the honest outcome and it is stated rather than papered over.
//
// REMOVAL TRIGGER: a gamer-tile key store.
uint32_t XamParseGamerTileKey(uint32_t keyPtr, uint32_t out1, uint32_t out2,
                              uint32_t out3) {
  (void)out1; (void)out2; (void)out3;
  return Refuse(kXamParseGamerTileKey, kXErrorNotFound,
                "no gamer-tile key store on this host, so xam_user.cc:709-711 "
                "would be three invented constants returned as SUCCESS; wrote "
                "nothing to any of the four pointers (the title will read its "
                "own uninitialised values, which is the honest outcome)",
                keyPtr);
}

// XamReadTileToTexture -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:716-735
//     if (!tile_id) return X_ERROR_INVALID_PARAMETER;
//     std::memset(buffer_ptr, 0xFF, size_t(stride) * size_t(height));
//     if (overlapped_ptr) { CompleteOverlappedImmediate(SUCCESS); return IO_PENDING; }
//     return X_ERROR_SUCCESS;
// The reference fills the caller's texture buffer with 0xFF and calls it
// success. 0xFF is not a tile, and this host has no tile store, no avatar
// service and no network to fetch one from -- so writing stride*height bytes
// would be manufacturing a picture of an avatar and telling the title it is
// real. Nothing is written to the buffer and the overlapped is NOT completed
// (XamContentDelete at imports.cpp:683 and XamContentGetDeviceState at
// imports.cpp:763 set that precedent): the read did not happen, so completing
// would assert that it did.
//
// ON THE SIGNATURE: the reference's third parameter is a `qword_t tile_id`
// (xam_user.cc:718), which under this ABI occupies a GPR PAIR, so the whole
// parameter list no longer lines up with r3..r10 and the ninth argument (the
// overlapped) is not in a register at all. This port therefore does not claim a
// parameter mapping: it takes the raw GPRs, logs them, and writes nothing. The
// two middle words (r4, r5) are the pair the reference calls tile_id, in EABI
// order, and are reported as raw halves because nothing here depends on which
// half is which.
//
// REMOVAL TRIGGER: a tile store.
uint32_t XamReadTileToTexture(uint32_t unknown, uint32_t titleId, uint32_t r4,
                              uint32_t r5, uint32_t userIndex, uint32_t bufferPtr,
                              uint32_t stride, uint32_t height) {
  (void)unknown; (void)titleId; (void)r4; (void)r5; (void)userIndex;
  (void)stride; (void)height;
  return Refuse(kXamReadTileToTexture, kXErrorNotFound,
                "no tile store, no avatar service and no network on this host; "
                "the reference memsets stride*height bytes to 0xFF and returns "
                "SUCCESS (xam_user.cc:726-727), which would manufacture a "
                "texture from a tile that does not exist. 0 bytes written and "
                "the overlapped was NOT completed",
                bufferPtr);
}

// XamWriteGamerTile -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:738-747
//     if (overlapped_ptr) { CompleteOverlappedImmediate(SUCCESS); return IO_PENDING; }
//     return X_ERROR_SUCCESS;
// Success for a write that never happened. This port writes nothing and
// deliberately does NOT complete the overlapped, so a guest that polls
// `Overlapped->InternalStatus` for a value other than STATUS_PENDING will keep
// waiting rather than be told a tile was stored. That wait is the correct
// consequence of a refusal and the guest can observe it; the alternative --
// completing with SUCCESS -- is the lie this port exists to remove.
//
// REMOVAL TRIGGER: a tile store.
uint32_t XamWriteGamerTile(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4,
                          uint32_t a5, uint32_t overlappedPtr) {
  (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
  return Refuse(kXamWriteGamerTile, kXErrorNotFound,
                "no tile store on this host; the reference completes the "
                "overlapped with SUCCESS (xam_user.cc:741-744) for a write that "
                "does not happen here. Nothing written, and the overlapped was "
                "NOT completed, so a polling guest keeps waiting",
                overlappedPtr);
}

// XamShowAchievementsUI -- REFUSE.
// Reference: NONE. Table row only -- xam_table.inc:505. No DECLARE_XAM_EXPORT,
// no `_entry`: on Xenia this export is unhandled and the call RAISES.
// For contrast, the two dialog APIs the reference DOES implement
// (XamShowMessageBoxUI at xam_ui.cc:268, XamShowKeyboardUI at xam_ui.cc:408)
// both go through `xeXamDispatchDialog` (xam_ui.cc:68-109), which constructs
// an ImGui dialog, hands it to the UI thread, BLOCKS on a fence until the user
// closes it, and brackets the whole thing with XN_SYS_UI true/false
// broadcasts. This host has no dashboard and no achievement service to show, so
// there is no dialog to construct and no user to close it.
//
// The status is X_ERROR_NOT_LOGGED_ON (0x000004DD, xenia/xbox.h:103): it is the
// reference's own code for exactly this family -- xam_user.cc:486 returns it
// from XamUserAreUsersFriends when there is no signed-in profile -- and it says
// the true thing, which is that there is nobody to show achievements for.
//
// WHAT THE TITLE EXPERIENCES: XamShow*UI returning X_ERROR_NOT_LOGGED_ON
// instead of opening a dialog. A title that blocks on the call will not block;
// a title that ignores the return will simply never see a dialog and will
// carry on without one. No XN_SYS_UI notification is broadcast, so
// `XamIsUIActive`-style polling stays at 0, which is true.
//
// REMOVAL TRIGGER: a dashboard. Then dispatch a real dialog and bracket it
// with XamNotifyEnqueueEvent(9, true) / (9, false) exactly as xam_ui.cc:74 and
// :98 do.
uint32_t XamShowAchievementsUI(uint32_t r3, uint32_t r4, uint32_t r5,
                               uint32_t r6) {
  (void)r4; (void)r5; (void)r6;
  return Refuse(kXamShowAchievementsUI, kXErrorNotLoggedOn,
                "no dashboard and no achievements service on this host, and the "
                "reference has no implementation (xam_table.inc:505 only -- on "
                "Xenia this raises). NO UI WAS SHOWN and no XN_SYS_UI was "
                "broadcast; NOT_LOGGED_ON is the reference's own code for this "
                "family (xam_user.cc:486)",
                r3);
}

// XamShowFriendsUI -- REFUSE.
// Reference: NONE. Table row only -- xam_table.inc:499. Same shape and same
// reasoning as XamShowAchievementsUI above: a friends list needs a friends
// service, and there is no network and no signed-in user in this process. NO UI
// WAS SHOWN. REMOVAL TRIGGER: a dashboard plus a friends service.
uint32_t XamShowFriendsUI(uint32_t r3, uint32_t r4, uint32_t r5, uint32_t r6) {
  (void)r4; (void)r5; (void)r6;
  return Refuse(kXamShowFriendsUI, kXErrorNotLoggedOn,
                "no dashboard and no friends service on this host, and the "
                "reference has no implementation (xam_table.inc:499 only). NO UI "
                "WAS SHOWN and no XN_SYS_UI was broadcast",
                r3);
}

// XamShowPlayerReviewUI -- REFUSE.
// Reference: NONE. Table row only -- xam_table.inc:506. A player review is
// authored against a live Live service; there is none. NO UI WAS SHOWN.
// REMOVAL TRIGGER: a dashboard plus a review service.
uint32_t XamShowPlayerReviewUI(uint32_t r3, uint32_t r4, uint32_t r5,
                               uint32_t r6) {
  (void)r4; (void)r5; (void)r6;
  return Refuse(kXamShowPlayerReviewUI, kXErrorNotLoggedOn,
                "no dashboard and no review service on this host, and the "
                "reference has no implementation (xam_table.inc:506 only). NO UI "
                "WAS SHOWN and no XN_SYS_UI was broadcast",
                r3);
}

// XamShowMarketplaceUI -- REFUSE.
// Reference: NONE. Table row only -- xam_table.inc:507. The marketplace is the
// dashboard's store; there is no store. NO UI WAS SHOWN.
// REMOVAL TRIGGER: a dashboard.
uint32_t XamShowMarketplaceUI(uint32_t r3, uint32_t r4, uint32_t r5,
                              uint32_t r6) {
  (void)r4; (void)r5; (void)r6;
  return Refuse(kXamShowMarketplaceUI, kXErrorNotLoggedOn,
                "no dashboard and no marketplace on this host, and the "
                "reference has no implementation (xam_table.inc:507 only). NO UI "
                "WAS SHOWN and no XN_SYS_UI was broadcast",
                r3);
}

// XamShowGamerCardUIForXUID -- REFUSE.
// Reference: NONE. Table row only -- xam_table.inc:521. This one is slightly
// different from its four siblings and gets its own code: the function is
// being asked for the card of a SPECIFIC XUID, and the truthful answer to
// "show me the card for this gamer" when there is no such gamer and no gamer
// service is X_ERROR_NOT_FOUND (0x00000490, xenia/xbox.h:101) -- not
// NOT_LOGGED_ON, which would be answering a different question. NO UI WAS
// SHOWN. REMOVAL TRIGGER: a dashboard plus a gamer-card service.
uint32_t XamShowGamerCardUIForXUID(uint32_t r3, uint32_t r4, uint32_t r5,
                                   uint32_t r6) {
  (void)r4; (void)r5; (void)r6;
  return Refuse(kXamShowGamerCardUIForXUID, kXErrorNotFound,
                "no dashboard, no gamer-card service and no such XUID on this "
                "host, and the reference has no implementation (xam_table.inc:"
                "521 only). NO UI WAS SHOWN and no XN_SYS_UI was broadcast. "
                "r4:r5 are the reference's 64-bit xuid argument as an EABI "
                "register pair (xam_table.inc:521 names the export only; no "
                "parameter list is claimed)",
                r3);
}

// XamUserAreUsersFriends -- REFUSE.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:474-516
//     if (user_index == 0) {
//       if (user_profile->signin_state() == 0) result = X_ERROR_NOT_LOGGED_ON;
//       else { are_friends = 0; result = X_ERROR_SUCCESS; }
//     }
//     if (out_value) { *out_value = result == SUCCESS ? are_friends : 0; return result; }
//     else if (overlapped_ptr) { CompleteOverlappedImmediateEx(...); return IO_PENDING; }
// This host has no signed-in profile -- the profile that does exist is the
// labelled synthetic one, and it is not a Live account with a friends list --
// and no network, so the relationship the caller is asking about does not
// exist here. X_ERROR_NOT_LOGGED_ON (xenia/xbox.h:103) is the reference's own
// code for the not-signed-in case, taken from xam_user.cc:486.
//
// WHAT IS AND IS NOT WRITTEN. `*out_value = 0` IS written, because the
// reference writes it on the failure path too (xam_user.cc:501) and because
// leaving the guest's uninitialised dword in place is worse than a truthful
// zero. It is zero, NOT a relationship: the refusal row is what distinguishes
// "not friends" from "no such answer". The overlapped is deliberately NOT
// completed: the reference completes it with X_ERROR_FUNCTION_FAILED
// (xam_user.cc:505-509) on its own failure path, and completing it here would
// tell a polling guest that a friends query completed. The return is the real
// status, not X_ERROR_IO_PENDING.
//
// NOTE: the guest may well be satisfied by the failure and continue, but a
// title that treats IO_PENDING as the only failure will now take a different
// branch. That is the intended, visible consequence of an honest refusal.
//
// REMOVAL TRIGGER: a signed-in profile with a friends service.
uint32_t XamUserAreUsersFriends(uint32_t userIndex, uint32_t unk1, uint32_t unk2,
                                uint32_t outValue, uint32_t overlappedPtr) {
  (void)unk1; (void)unk2; (void)overlappedPtr;
  if (userIndex >= 4) {
    if (outValue != 0) {
      (void)PutU32(outValue, 0); // xam_user.cc:501
    }
    return Refuse(kXamUserAreUsersFriends, kXErrorInvalidParameter,
                  "slot >= 4 is X_ERROR_INVALID_PARAMETER per xam_user.cc:480-481",
                  userIndex);
  }
  if (outValue != 0 && !PutU32(outValue, 0)) {
    return Refuse(kXamUserAreUsersFriends, kXErrorInvalidParameter,
                  "out_value is not a valid guest dword; nothing written",
                  outValue);
  }
  return Refuse(kXamUserAreUsersFriends, kXErrorNotLoggedOn,
                "no signed-in Live profile and no friends service on this host, "
                "so there is no relationship to answer about; "
                "X_ERROR_NOT_LOGGED_ON is the reference's own code for this "
                "case (xam_user.cc:486). Wrote the truthful out_value=0 per "
                ":501 and did NOT complete the overlapped (the reference "
                "completes it on its own failure path at :505-509)",
                userIndex);
}

// XamUserCheckPrivilege -- REFUSE, AND THE ALTERNATIVE IS WRITTEN DOWN.
// Reference: .research/xenia/src/xenia/kernel/xam/xam_user.cc:398-414
//     if (user_index != 0xFF) {
//       if (user_index >= 4) return X_ERROR_INVALID_PARAMETER;
//       if (user_index)       return X_ERROR_NO_SUCH_USER;
//     }
//     *out_value = 0;   // "If we deny everything, games should hopefully not
//     return X_ERROR_SUCCESS;   //  try to do stuff."  (:411-413)
// DECLARE_XAM_EXPORT1(XamUserCheckPrivilege, kUserProfiles, kStub);
// THE ARGUMENT FOR REFUSAL. Reproducing the reference verbatim would mean
// returning SUCCESS for a privilege check performed against an account that
// does not exist, and SUCCESS asserts that the check completed. The reference
// can afford that because it has a real profile whose signin state it could
// read; this host has none. X_ERROR_NOT_LOGGED_ON (xenia/xbox.h:103) is the
// true answer, and it is the same code Xenia itself uses for this family when
// there is no profile (xam_user.cc:486).
//
// THE ARGUMENT AGAINST, so the decision is reversible in one line: the
// reference's deny-everything value of 0 grants NOTHING -- the charter forbids
// fabricating a privilege GRANT, and this fabricates no grant -- and 0 is
// reproduced unconditionally below, so the out-parameter is right either way.
// A reviewer who prefers strict reference parity changes one constant.
//
// REACHABILITY, which is why this is not academic: the guest reaches this
// import from the profile slot-scan fallback at guest 0x82457680
// (documented at imports.cpp:553-556) -- the path taken precisely when no
// signed-in slot matches -- so the refusal is on a live road. The out_value is
// written 0 on every arm, which is the reference's own value and is the safe
// direction (deny). Nothing is granted.
//
// REMOVAL TRIGGER: a signed-in profile. Then the question has an answer and
// this refusal goes away.
uint32_t XamUserCheckPrivilege(uint32_t userIndex, uint32_t mask,
                               uint32_t outValue) {
  if (outValue != 0 && !PutU32(outValue, 0)) {
    return Refuse(kXamUserCheckPrivilege, kXErrorInvalidParameter,
                  "out_value is not a valid guest dword; nothing written",
                  outValue);
  }
  if (userIndex != 0xFFu) {
    if (userIndex >= 4) {
      return Refuse(kXamUserCheckPrivilege, kXErrorInvalidParameter,
                    "slot >= 4 is X_ERROR_INVALID_PARAMETER per xam_user.cc:402-404",
                    userIndex);
    }
    if (userIndex != 0) {
      return Refuse(kXamUserCheckPrivilege, kXErrorNoSuchUser,
                    "only slot 0 can hold a profile; X_ERROR_NO_SUCH_USER per "
                    "xam_user.cc:406-408",
                    userIndex);
    }
  }
  return Refuse(kXamUserCheckPrivilege, kXErrorNotLoggedOn,
                "no signed-in account on this host, so no privilege can be "
                "confirmed; returning SUCCESS would assert the check completed. "
                "out_value=0 is the reference's own deny-everything value "
                "(xam_user.cc:412) and grants nothing. REACHABLE from the "
                "no-signed-in-slot fallback at guest 0x82457680",
                mask);
}

// ===========================================================================
// REGISTRATION.
//
// The form is the one every already-ported function in imports.cpp uses --
// e.g. imports.cpp:6441 `GUEST_FUNCTION_HOOK(__imp__RtlCompareMemoryUlong,
// RtlCompareMemoryUlong)`, and the 12 F-609 bodies at imports.cpp:6365-6392 --
// and it is the form the sibling ports in this integration batch also use
// (src/kernel/port_kobj.cpp:2278-2296). The integration stream therefore only
// has to DELETE the matching GUEST_FUNCTION_STUB lines; it does not have to
// write a single registration line, which is what makes "exactly one
// definition of each __imp_ thunk" a property of this file rather than of the
// integration's care.
//
// FAILURE MODE IF THE DELETIONS ARE INCOMPLETE: a leftover
// `GUEST_FUNCTION_STUB(__imp__XamAlloc)` is a second definition of the same
// `PPC_FUNC(__imp__XamAlloc)` symbol and the LINK FAILS LOUDLY (duplicate
// symbol). It cannot silently revert to an empty body. The same is true of a
// leftover dead `void XamAlloc()` at imports.cpp:6735: it is a distinct symbol,
// it is never registered, and it is now unreferenced -- it must still be
// deleted, because its `void` return type disagrees with the `uint32_t` this
// port defines under the same name and the two cannot both compile into the
// program.
// ===========================================================================
GUEST_FUNCTION_HOOK(__imp__XamAlloc, XamAlloc);
GUEST_FUNCTION_HOOK(__imp__XamFree, XamFree);
GUEST_FUNCTION_HOOK(__imp__XamTaskShouldExit, XamTaskShouldExit);
GUEST_FUNCTION_HOOK(__imp__XamLoaderSetLaunchData, XamLoaderSetLaunchData);
GUEST_FUNCTION_HOOK(__imp__XamLoaderGetLaunchDataSize, XamLoaderGetLaunchDataSize);
GUEST_FUNCTION_HOOK(__imp__XamLoaderGetLaunchData, XamLoaderGetLaunchData);
GUEST_FUNCTION_HOOK(__imp__XamUserGetName, XamUserGetName);
GUEST_FUNCTION_HOOK(__imp__XamUserGetXUID, XamUserGetXUID);

GUEST_FUNCTION_HOOK(__imp__XamCreateEnumeratorHandle, XamCreateEnumeratorHandle);
GUEST_FUNCTION_HOOK(__imp__XamGetPrivateEnumStructureFromHandle,
                    XamGetPrivateEnumStructureFromHandle);
GUEST_FUNCTION_HOOK(__imp__XamUserCreateAchievementEnumerator,
                    XamUserCreateAchievementEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamUserCreateStatsEnumerator,
                    XamUserCreateStatsEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamTaskCloseHandle, XamTaskCloseHandle);
GUEST_FUNCTION_HOOK(__imp__XamTaskSchedule, XamTaskSchedule);
GUEST_FUNCTION_HOOK(__imp__XamParseGamerTileKey, XamParseGamerTileKey);
GUEST_FUNCTION_HOOK(__imp__XamReadTileToTexture, XamReadTileToTexture);
GUEST_FUNCTION_HOOK(__imp__XamWriteGamerTile, XamWriteGamerTile);
GUEST_FUNCTION_HOOK(__imp__XamShowAchievementsUI, XamShowAchievementsUI);
GUEST_FUNCTION_HOOK(__imp__XamShowFriendsUI, XamShowFriendsUI);
GUEST_FUNCTION_HOOK(__imp__XamShowPlayerReviewUI, XamShowPlayerReviewUI);
GUEST_FUNCTION_HOOK(__imp__XamShowMarketplaceUI, XamShowMarketplaceUI);
GUEST_FUNCTION_HOOK(__imp__XamShowGamerCardUIForXUID, XamShowGamerCardUIForXUID);
GUEST_FUNCTION_HOOK(__imp__XamUserAreUsersFriends, XamUserAreUsersFriends);
GUEST_FUNCTION_HOOK(__imp__XamUserCheckPrivilege, XamUserCheckPrivilege);
