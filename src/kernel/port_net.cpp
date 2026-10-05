// ===========================================================================
// port_net.cpp -- the 18 remaining console networking imports. F-609,
// native-only charter: no emulation, no fakes, no invented network state.
//
// WHAT THIS FILE IS. The real bodies for the eighteen console networking
// exports that were `GUEST_FUNCTION_STUB(__imp__X)` -- an EMPTY PPC_FUNC body
// (src/kernel/function.h:640-641) that left r3 holding whatever the caller
// passed, so the title was reading its own arguments back as results. Each of
// the eighteen below is registered as a GUEST_FUNCTION_HOOK, so each now has a
// body that either does real work or refuses in a counted, named way.
//
// WHAT THIS FILE IS NOT. It is not a socket layer. NetDll_socket in this same
// build returns INVALID_SOCKET unconditionally (imports.cpp:4849-4858,
// measured and correct), so no socket can exist, and every socket-taking entry
// below is in exactly the state the reference implementation handles with its
// `if (!socket) { XThread::SetLastError(0x2736); return -1; }` arm. It is also
// not an Xbox Live session layer: there is no peer to broker to, no title id
// to know, and no console NIC. Nothing here invents a peer address, a
// quality-of-service record, a session key, a title identifier, or a hardware
// address. One entry of the eighteen is REAL (NetDll_WSAGetLastError); the
// other seventeen REFUSE, and each refusal returns a real XOS code and is
// counted on the house cadence.
//
// THE SPLIT IS 1 REAL / 17 REFUSE, and the reason is structural rather than
// stylistic: the host state these functions would have to answer from -- a
// socket table, a Live logon, an XNet broker, a QoS database, a key store --
// does not exist on this host, and inventing the output of a subsystem that
// does not exist is the exact defect this file exists to remove. A refusal is
// therefore not a fallback here; for 17 of 18 it is the only honest answer.
//
// REMOVAL CONDITION FOR EVERYTHING REFUSED HERE. A refusal in this file is
// deleted, one function at a time, exactly when the host state that function
// would have to report actually exists and is authoritative. Concretely:
//   * the five socket entries (getsockname, ioctlsocket, recvfrom, sendto and
//     WSAGetLastError's error half) are deleted when a real socket table
//     exists, i.e. when NetDll_socket can return a live handle instead of
//     INVALID_SOCKET. Until then WSAENOTSOCK is not a policy, it is the truth.
//   * the XNet session entries (XNetConnect, XNetGetConnectStatus,
//     XNetRegisterKey, XNetUnregisterKey, XNetCleanup, XNetQnAddr/
//     XNetServerToInAddr, XNetUnregisterInAddr) are deleted when a second
//     native peer exists that can answer XNet session requests, or the title
//     is run against a real Xbox Live service or a LAN bridge to one. There is
//     no such thing in this tree -- grep before assuming one appeared.
//   * the QoS entries (XNetQosListen, XNetQosLookup, XNetQosRelease) are
//     deleted when a real QoS provider exists to allocate and free XNQOS
//     records. Xenia itself does not have one; see the kStub notes below.
//   * XNetGetEthernetLinkStatus is deleted when the host has a console
//     network interface whose link state is authoritative. A PC's own NIC is
//     NOT that: it is a different device, and reporting it would be the same
//     fabrication wearing a different hat.
//   * XNetLogonGetTitleID is deleted when this build has a title identifier it
//     can read from the running XEX rather than invent.
//
// INTEGRATION (required, and outside this file's ownership). Three things the
// integration stream must do beyond adding this file to the build:
//   1. DELETE the eighteen dead host definitions at imports.cpp:6609-6730.
//      They are at file scope with external linkage, so leaving them in place
//      is an LNK2005 duplicate-symbol error against the eighteen bodies here.
//      Two of them are worse than dead: `NetDll_XNetGetConnectStatus` returned
//      1 ("Connected") and `NetDll_XNetGetEthernetLinkStatus` returned 1 ("Link
//      up") -- fabrications of state this host does not have.
//   2. DELETE `GUEST_FUNCTION_HOOK(__imp__NetDll_WSAGetLastError,
//      NetDll_WSAGetLastError)` at imports.cpp:6861. WSAGetLastError is
//      MEASURED to be the one live hook in the set, not a stub: imports.cpp
//      6652-6659 already documented that its GUEST_FUNCTION_STUB body made the
//      host definition dead code, and the hook at :6861 replaced it. Registering
//      it again here would be two owners of one guest address (AGENTS.md rule
//      4) and a duplicate symbol.
//   3. REPOINT imports.cpp:4835 from `g_netLastError.store(kWsaENotSock, ...)`
//      to `mcla::kernel::netport::SetLastError(kWsaENotSock)`, so the twelve
//      already-ported refusals and the WSAGetLastError that reports them share
//      one cell. Until that line changes, each half of the family reports only
//      its own last error, and that is a real (small) incoherence, not a
//      cosmetic one -- it is the function whose entire job is to tell the title
//      WHY the last call failed.
//
// RELATION TO THE `SYNTH-XNET` BLOCK (imports.cpp:5939-6149). That block is a
// deliberate, labelled fabrication: XNetStartup and XNetGetTitleXnAddr return
// 0 because the boot is fatal otherwise (measured: the single XNetStartup call
// site tests r3 == 0 and fatals on anything else, at 0x821E44F0-0x821E44FC).
// Nothing here contradicts it, and the direction of the disagreement is worth
// stating: SYNTH-XNET hands the title an ALL-ZERO XNADDR, and
// NetDll_XNetXnAddrToInAddr below REFUSES to turn that empty address into an
// in_addr, because converting a zero XNADDR is exactly the operation that would
// have to invent network topology. SYNTH-XNET says "started"; this file says
// "and here is nothing behind it, and here is the error". That is the
// intended direction. It is also off the boot path: XNetGetTitleXnAddr's seven
// measured call sites (0x824E6148, 0x824E61F0, 0x825019B0, 0x82501A28,
// 0x82501AC0) are all RakNet / "is there a network" helpers and none is on it
// (imports.cpp:5979-5988).
//
// ARITY IS MEASURED, NOT ASSUMED. Every signature below was checked against
// the guest's own thunk in generated/ppc/ppc_recomp.82.cpp, because the
// F-609 family bug was a missing leading `caller`/selector argument that made
// each function read the wrong register as its first real argument. Seventeen
// of the eighteen thunks do `li r3,1` (plus an N-deep `mr` shift) before the
// tail call, so seventeen of the eighteen take a leading selector. The
// exception is NetDll_WSAGetLastError: its thunk sub_8244A480 is a bare
// `b 0x827bd204` with no register setup at all (ppc_recomp.82.cpp:6464-6468),
// so it takes ZERO arguments. The other exception is XNetLogonGetTitleID, which
// is not reached through a thunk at all -- the guest `bl 0x827bd304` directly
// with `li r3,9` and `li r3,2` (ppc_recomp.82.cpp:7058-7062, :9088-9092), so
// r3 is the USER INDEX and there is no selector. Each thunk, its shift depth
// and the resulting parameter count are cited on the function it governs.
// ===========================================================================

#include <stdafx.h>
#include <cpu/ppc_context.h>
#include "function.h"
#include "memory.h"
#include "guest_thread.h"
#include "port_net.h"
#include "logging.h"
#include <atomic>
#include <cstdint>

namespace {

// ---------------------------------------------------------------------------
// Codes. Every one is cited to its definition, and every refusal returns a
// value the guest can distinguish from success.
// ---------------------------------------------------------------------------

// WSAENOTSOCK. Xenia sets exactly this literal, under exactly this name, in
// the `!socket` arm at .research/xenia/src/xenia/kernel/xam/xam_net.cc:707,
// 949, 1009 (and :650, 667, 690, 729, 751, 772, 932, 992 for the rest of the
// family). The already-ported twelve use the same literal, imports.cpp:4803.
constexpr uint32_t kWsaENotSock = 0x2736u;

// (uint32_t)-1: SOCKET_ERROR, the return Xenia pairs with kWsaENotSock.
constexpr uint32_t kSocketError = 0xFFFFFFFFu;

// X_ERROR_* are X_RESULT_FROM_WIN32, i.e. the bare Win32 values, not HRESULTs
// -- .research/xenia/src/xenia/xbox.h:84.
constexpr uint32_t kXErrorInvalidParameter = 0x00000057u; // xbox.h:92
constexpr uint32_t kXErrorNotFound = 0x00000490u;        // xbox.h:101
constexpr uint32_t kXErrorNotLoggedOn = 0x000004DDu;     // xbox.h:103
constexpr uint32_t kXErrorFunctionFailed = 0x0000065Bu;  // xbox.h:105

// X_STATUS_INVALID_PARAMETER. xam_net.cc:595 returns this by name from
// XNetQosRelease; xbox.h:51 defines it as 0xC000000D, which src/kernel/xbox.h:428
// also carries as STATUS_INVALID_PARAMETER.
constexpr uint32_t kXStatusInvalidParameter = 0xC000000Du;

// TEB-relative offset of the Win32LastError word -- the real, per-thread XOS
// location of the value WSAGetLastError reports. Mirrors GuestThread::SetLastError,
// which writes TEB+0x160 (src/kernel/guest_thread.cpp:545-546); TEB_OFFSET is
// PCR(0xAB0) + TLS(0x100) = 0xBB0 (guest_thread.cpp:15-22, restated at
// boot_host.cpp:768-772). It is re-derived here rather than imported because
// guest_thread.cpp keeps it in an unnamed namespace, and a second, slightly
// different constant is the same class of bug as the alias that comment is
// about -- so the arithmetic is written out and cited instead.
constexpr uint32_t kTebOffset = 0xBB0u;
constexpr uint32_t kTebWin32LastError = 0x160u;

// The cell port_net.h exposes. Set by every refusal below, read by
// NetDll_WSAGetLastError. Initialised to "no error", which is the honest
// initial state: nothing has failed yet.
std::atomic<uint32_t> g_lastError{0};

// Per-function census. Attempts and outcomes are counted SEPARATELY by house
// rule, so the moment a function grows a second outcome the two diverge and
// the line below says so instead of the comment going stale.
struct NetPortCensus
{
    std::atomic<uint64_t> attempts{0};
    std::atomic<uint64_t> outcomes{0};
};

// One census line, house cadence: first 8, then every 200th. `real` picks the
// marker, so a real implementation and a refusal never share a line shape.
void NetPortCount(NetPortCensus& census, const char* fn, bool real,
                  uint32_t code) {
    const uint64_t n = census.attempts.fetch_add(1, std::memory_order_relaxed) + 1;
    census.outcomes.fetch_add(1, std::memory_order_relaxed);

    if (n > 8 && (n % 200) != 0)
        return;

    const uint32_t glr = g_ppcContext ? static_cast<uint32_t>(g_ppcContext->lr) : 0u;
    const char* marker = real ? mcla::kernel::netport::kRealMarker
                              : mcla::kernel::netport::kRefuseMarker;
    if (real) {
        MCLA_LOG_WARN(
            "{} #{} fn={} -> real answer from host state: value=0x{:X} "
            "(attempts={} outcomes={}) glr={:08X}",
            marker, n, fn, code,
            census.attempts.load(std::memory_order_relaxed),
            census.outcomes.load(std::memory_order_relaxed), glr);
    } else {
        MCLA_LOG_WARN(
            "{} #{} fn={} code=0x{:X} -> refusing; no socket, no Live session, "
            "no QoS provider, no key store, no console NIC on this host; "
            "nothing fabricated (attempts={} outcomes={}) glr={:08X}",
            marker, n, fn, code,
            census.attempts.load(std::memory_order_relaxed),
            census.outcomes.load(std::memory_order_relaxed), glr);
    }
}

// A refusal. Records the error in THREE places and counts it:
//   * the shareable host cell in this file (what port_net.h exposes),
//   * the guest's own per-thread TEB Win32LastError word, through
//     GuestThread::SetLastError -- this is the real XOS location and it is what
//     Xenia's XThread::SetLastError writes (xam_net.cc:707, :949, :1009, ...),
//     so the value is genuinely guest-visible and genuinely per-thread rather
//     than a host fiction,
//   * the census line.
// `errorSet` is the code to record; `ret` is what the caller returns. They are
// separate only for the socket family, where Xenia sets WSAENOTSOCK and
// returns SOCKET_ERROR (-1) -- xam_net.cc:705-709 is exactly that pair.
uint32_t NetPortRefuseAs(NetPortCensus& census, const char* fn,
                         uint32_t errorSet, uint32_t ret) {
    mcla::kernel::netport::SetLastError(errorSet);
    GuestThread::SetLastError(errorSet);
    NetPortCount(census, fn, /*real=*/false, errorSet);
    return ret;
}

// The common case: record the code and return it.
uint32_t NetPortRefuse(NetPortCensus& census, const char* fn, uint32_t code) {
    return NetPortRefuseAs(census, fn, code, code);
}

// The socket family: record WSAENOTSOCK, return SOCKET_ERROR, exactly as
// Xenia's `!socket` arm does.
uint32_t NetPortRefuseSocket(NetPortCensus& census, const char* fn) {
    return NetPortRefuseAs(census, fn, kWsaENotSock, kSocketError);
}

// A NOTE ON GUEST MEMORY, because its absence here is deliberate and not an
// oversight. No function in this file reads or writes a byte of guest memory
// except NetDll_WSAGetLastError, and that one read is the TEB last-error word
// via the checked, big-endian helper. Every other entry's honest answer is a
// refusal that depends on no guest-supplied value at all, so there is nothing
// to read: the guest's sockaddr, XNADDR, QoS blob and key are all DISCARDED on
// purpose, because reading them would imply they were going to be answered
// from. There is no reinterpret_cast on guest data in this file, and no assert
// on a guest-supplied value -- an assert compiles out under the build's
// /DNDEBUG and would turn a guest-controlled value into a host crash. The
// pointer-typed hook arguments below are accepted and ignored for that reason;
// had any of them needed an out-parameter written, the conversion back to a
// guest VA would go through ArgTranslator::HostPtrToGuestVa (function.h:
// 135-152), which is checked in BOTH directions and yields 0 rather than a
// wrapped VA.

// The eighteen censuses. Named, not indexed, so a soak line is attributable
// without a lookup table.
NetPortCensus g_cWsaGetLastError;
NetPortCensus g_cGetsockname;
NetPortCensus g_cIoctlsocket;
NetPortCensus g_cRecvfrom;
NetPortCensus g_cSendto;
NetPortCensus g_cXNetCleanup;
NetPortCensus g_cXNetConnect;
NetPortCensus g_cXNetGetConnectStatus;
NetPortCensus g_cXNetGetEthernetLinkStatus;
NetPortCensus g_cXNetQosListen;
NetPortCensus g_cXNetQosLookup;
NetPortCensus g_cXNetQosRelease;
NetPortCensus g_cXNetRegisterKey;
NetPortCensus g_cXNetServerToInAddr;
NetPortCensus g_cXNetUnregisterInAddr;
NetPortCensus g_cXNetUnregisterKey;
NetPortCensus g_cXNetXnAddrToInAddr;
NetPortCensus g_cXNetLogonGetTitleID;

} // namespace

// ---------------------------------------------------------------------------
// The shareable last-error cell (port_net.h).
// ---------------------------------------------------------------------------
namespace mcla::kernel::netport {

uint32_t LastError() {
    return g_lastError.load(std::memory_order_relaxed);
}

void SetLastError(uint32_t error) {
    g_lastError.store(error, std::memory_order_relaxed);
}

} // namespace mcla::kernel::netport

// ===========================================================================
// 1. NetDll_WSAGetLastError
//    REAL. Xenia: xam_net.cc:291-294 -- `return XThread::GetLastError();`
//    Reason: the answer is a value this host already holds, so returning it is
//    a real answer, not a guess. Two sources, in order of authority: the
//    guest's own per-thread TEB Win32LastError word (the real XOS location, and
//    the per-thread semantics Xenia has), then this file's host cell.
//    ARITY 0 -- MEASURED, and it is the one member of the family with no
//    selector. The guest thunk sub_8244A480 is a bare `b 0x827bd204` with no
//    register setup (generated/ppc/ppc_recomp.82.cpp:6464-6468). Declaring a
//    leading selector here would be the F-609 signature bug, reintroduced.
// ===========================================================================
int NetDll_WSAGetLastError() {
    uint32_t tebError = 0;
    bool fromTeb = false;
    if (g_ppcContext) {
        const uint32_t r13 = g_ppcContext->r13.u32;
        const uint64_t cell = static_cast<uint64_t>(r13) + kTebOffset +
                              kTebWin32LastError;
        if (cell <= 0xFFFFFFFFull) {
            fromTeb = mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(
                static_cast<uint32_t>(cell), &tebError);
        }
    }

    // A TEB word of 0 is indistinguishable from "never failed", so the host
    // cell -- which the refusals in THIS file set -- is the fallback rather
    // than the other way round. It is a single cell, not per-thread; that
    // approximation is the same one imports.cpp:4806-4811 already names.
    const uint32_t value = fromTeb ? tebError : mcla::kernel::netport::LastError();
    NetPortCount(g_cWsaGetLastError, "WSAGetLastError", /*real=*/true, value);
    return static_cast<int>(value);
}

// ===========================================================================
// 2. NetDll_getsockname
//    REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//    (measured: recursive search of .research/xenia for "getsockname" returns
//    nothing), so there is no Xenia body to port and nothing to call a stub.
//    Reason: with no socket there is no local address to report. The old body
//    returned 0 -- a SUCCESSFUL sockaddr_in query, leaving the caller's buffer
//    uninitialised for the guest to read as its own address.
//    ARITY 4 -- thunk sub_8244A378: 3 `mr` shifts (r3->r4->r5->r6) then
//    `li r3,1` (ppc_recomp.82.cpp:~6202). = (selector, s, name, namelen).
// ===========================================================================
uint32_t NetDll_getsockname(uint32_t dllSelector, uint32_t s, void* name,
                            int* namelen) {
    (void)dllSelector; (void)s; (void)name; (void)namelen;
    return NetPortRefuseSocket(g_cGetsockname, "getsockname");
}

// ===========================================================================
// 3. NetDll_ioctlsocket
//    REFUSE. Xenia: xam_net.cc:701-720 -- `LookupObject<XSocket>` then
//    `if (!socket) { XThread::SetLastError(0x2736); return -1; }` at :705-709.
//    Reason: the reference implementation's own no-socket arm, reached,
//    because this host's NetDll_socket cannot produce a handle.
//    ARITY 4 -- thunk sub_8244A340: 3 shifts + `li r3,1`
//    (ppc_recomp.82.cpp:6131-6143), matching Xenia's 4-parameter signature.
//    NOTE: the dead body in imports.cpp:6609 read `s` as the FIRST argument
//    with no selector -- the F-609 bug, still live in that dead code.
// ===========================================================================
uint32_t NetDll_ioctlsocket(uint32_t dllSelector, uint32_t s, int cmd,
                            void* argPtr) {
    (void)dllSelector; (void)s; (void)cmd; (void)argPtr;
    return NetPortRefuseSocket(g_cIoctlsocket, "ioctlsocket");
}

// ===========================================================================
// 4. NetDll_recvfrom
//    REFUSE. Xenia: xam_net.cc:940-951 -- `if (!socket) { SetLastError(0x2736);
//    return -1; }` at :947-951. Reason: no socket, no datagram, and no peer to
//    name. Returning 0 would be the subtlest lie in the set: WinSock reports a
//    0-byte recv as a SUCCESSFUL COMPLETION, so the title would read "the
//    socket delivered a clean zero-length datagram" from a call that read
//    nothing and left its buffer uninitialised.
//    ARITY 7 -- thunk sub_8244A420: 6 shifts + `li r3,1`
//    (ppc_recomp.82.cpp:~6390), matching Xenia's 7-parameter signature
//    exactly. = (selector, s, buf, len, flags, from, fromlen).
//    RELATED: Xenia's separate NetDll_WSARecvFrom (xam_net.cc:296-314) is a
//    hard `return -1` declared kStub/kHighFrequency, for the same reason.
// ===========================================================================
uint32_t NetDll_recvfrom(uint32_t dllSelector, uint32_t s, void* buf, int len,
                         int flags, void* from, int* fromlen) {
    (void)dllSelector; (void)s; (void)buf; (void)len;
    (void)flags; (void)from; (void)fromlen;
    return NetPortRefuseSocket(g_cRecvfrom, "recvfrom");
}

// ===========================================================================
// 5. NetDll_sendto
//    REFUSE. Xenia: xam_net.cc:1000-1016 -- `if (!socket) { SetLastError(0x2736);
//    return -1; }` at :1005-1011. Reason: no socket, and the destination
//    sockaddr is a guest-supplied address this host has no route to. The old
//    body returned `len`, which told the title that `len` bytes had left the
//    machine; not one byte did.
//    ARITY 7 -- thunk sub_8244A458: 6 shifts + `li r3,1`
//    (ppc_recomp.82.cpp:~6436), matching Xenia's 7-parameter signature.
//    = (selector, s, buf, len, flags, to, tolen).
// ===========================================================================
uint32_t NetDll_sendto(uint32_t dllSelector, uint32_t s, const void* buf, int len,
                       int flags, const void* to, int tolen) {
    (void)dllSelector; (void)s; (void)buf; (void)len;
    (void)flags; (void)to; (void)tolen;
    return NetPortRefuseSocket(g_cSendto, "sendto");
}

// ===========================================================================
// 6. NetDll_XNetCleanup
//    REFUSE. Xenia: xam_net.cc:194-204 -- the body is ENTIRELY COMMENTED OUT
//    (`xam->set_xnet(nullptr)`, `delete xnet`) with only a "TODO: Shut down
//    and delete" left, and then `return 0;` at :202. It is declared
//    kImplemented, but nothing is implemented: Xenia's own answer here is
//    "I did nothing, and here is success". Porting that would be porting a
//    stub and calling it a port, so the kImplemented label is NOT taken at face
//    value and the function refuses instead.
//    Reason: there is no XNet to tear down, and reporting success for a
//    teardown that did not happen is the same defect as a success that did no
//    work.
//    ARITY 1 -- thunk sub_8244A558 is `li r3,1` and nothing else
//    (ppc_recomp.82.cpp:6648-6655): the guest passes NO second argument.
//    Xenia's signature is (caller, params) = 2; the measured thunk wins, because
//    r5 is not established by this guest and declaring it would read a register
//    the caller never set.
// ===========================================================================
uint32_t NetDll_XNetCleanup(uint32_t dllSelector) {
    (void)dllSelector;
    return NetPortRefuse(g_cXNetCleanup, "XNetCleanup", kXErrorFunctionFailed);
}

// ===========================================================================
// 7. NetDll_XNetConnect
//    REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//    (measured). Reason: XNet is Xbox Live's session/broker layer. There is no
//    Live service to join and no peer to broker to, so there is no session to
//    establish. The old body returned 0, which is success: the title was told
//    it had a live XNet connection that never existed.
//    Code: X_ERROR_NOT_LOGGED_ON (0x4DD, xbox.h:103) -- the XOS answer for
//    "there is no Live logon", which is the actual state, and non-zero so the
//    guest cannot read it as success.
//    ARITY 2 -- thunk sub_8244A5C0: 1 shift + `li r3,1`
//    (ppc_recomp.82.cpp:~6789) = (selector, xnAddr).
// ===========================================================================
uint32_t NetDll_XNetConnect(uint32_t dllSelector, void* xnAddr) {
    (void)dllSelector; (void)xnAddr;
    return NetPortRefuse(g_cXNetConnect, "XNetConnect", kXErrorNotLoggedOn);
}

// ===========================================================================
// 8. NetDll_XNetGetConnectStatus
//    REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//    (measured). Reason: the status of a session that does not exist is
//    "not connected", and that is a non-zero word in this API's encoding (see
//    Xenia's XnAddrStatus, xam_net.cc:429-450, where non-zero means not
//    available). Returning non-zero is therefore both honest and correctly
//    encoded. The old body returned 1 with the comment "// Connected" -- a
//    fabricated connection, and the single worst fabrication in this file.
//    Code: X_ERROR_NOT_LOGGED_ON (0x4DD, xbox.h:103), non-zero => "not
//    connected" to a guest reading this as a status word.
//    ARITY 2 -- thunk sub_8244A5D0: 1 shift + `li r3,1`
//    (ppc_recomp.82.cpp:~6813) = (selector, xnAddr).
// ===========================================================================
uint32_t NetDll_XNetGetConnectStatus(uint32_t dllSelector, void* xnAddr) {
    (void)dllSelector; (void)xnAddr;
    return NetPortRefuse(g_cXNetGetConnectStatus, "XNetGetConnectStatus",
                         kXErrorNotLoggedOn);
}

// ===========================================================================
// 9. NetDll_XNetGetEthernetLinkStatus
//    REFUSE. Xenia: xam_net.cc:537-540 -- a two-line body, `return 0;`,
//    declared kStub. Xenia's 0 means "no link", and for a host with no console
//    NIC that is the true answer, so Xenia's VALUE is ported. It is still
//    classified REFUSE, and counted as one, because 0 and "never called" are
//    otherwise indistinguishable in a soak -- and a caller that reads 0 as
//    "offline" is being told something true, which is the point, but only if
//    the log shows the call actually happened.
//    The old body returned 1 with the comment "// Link up" -- a fabricated
//    hardware state, and a DIRECT CONTRADICTION of the reference
//    implementation's own answer.
//    ARITY 1 -- thunk sub_8244A680 is `li r3,1` and nothing else
//    (ppc_recomp.82.cpp:6976-6983), matching Xenia's 1-parameter signature.
// ===========================================================================
uint32_t NetDll_XNetGetEthernetLinkStatus(uint32_t dllSelector) {
    (void)dllSelector;
    // 0 = Xenia's own answer (xam_net.cc:538) and the truth here: this host
    // has no console ethernet interface whose link state is authoritative.
    return NetPortRefuse(g_cXNetGetEthernetLinkStatus,
                         "XNetGetEthernetLinkStatus", 0u);
}

// ===========================================================================
// 10. NetDll_XNetQosListen
//     REFUSE. Xenia: xam_net.cc:602-607 -- `return X_ERROR_FUNCTION_FAILED;`,
//     declared kStub. Xenia stubs this one outright, and its value is ported.
//     Reason: QoS is a Live service; there is no provider to listen with, and
//     the `id`/`data` blob the guest passes is a registration request that
//     cannot be honoured. The old body returned 0 -- a successful QoS
//     registration that registered nothing.
//     Code: X_ERROR_FUNCTION_FAILED (0x65B, xbox.h:105) -- Xenia's own value.
//     ARITY 6 -- thunk sub_8244A5E0: 5 shifts + `li r3,1`
//     (ppc_recomp.82.cpp:6845), matching Xenia's 6-parameter signature
//     (caller, id, data, data_size, r7, flags) exactly.
// ===========================================================================
uint32_t NetDll_XNetQosListen(uint32_t dllSelector, void* id, void* data,
                              uint32_t dataSize, uint32_t r7, uint32_t flags) {
    (void)dllSelector; (void)id; (void)data;
    (void)dataSize; (void)r7; (void)flags;
    return NetPortRefuse(g_cXNetQosListen, "XNetQosListen",
                         kXErrorFunctionFailed);
}

// ===========================================================================
// 11. NetDll_XNetQosLookup
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: a lookup allocates an XNQOS record the caller later
//     passes to XNetQosRelease. There is no QoS provider to allocate one from,
//     so the only alternatives are returning success and handing back a pointer
//     to a record that does not exist, or inventing the record. The old body
//     did the first: it returned 0 while leaving `probe` exactly as the guest
//     passed it, so a successful lookup yielded a garbage handle.
//     Code: X_ERROR_FUNCTION_FAILED (0x65B, xbox.h:105) -- the same value
//     Xenia uses for the sibling QosListen.
//     ARITY 8 -- thunk sub_8244A600: 8 `mr` shifts (r3->r4->...->r10, with the
//     old r10 spilled to 84(r1)) plus `li r3,1` (ppc_recomp.82.cpp:6862-6917).
//     That is 8 register slots after the shift, which is the ABI maximum
//     (r3..r10), so the signature is 8 parameters. The 9th argument lives on the
//     stack and is not declared: reading it would need a frame convention this
//     header does not establish, and no refusal below depends on it.
// ===========================================================================
uint32_t NetDll_XNetQosLookup(uint32_t dllSelector, void* xnAddr,
                              uint32_t qosFlags, void* probe, uint32_t arg5,
                              uint32_t arg6, uint32_t arg7, uint32_t arg8) {
    (void)dllSelector; (void)xnAddr; (void)qosFlags; (void)probe;
    (void)arg5; (void)arg6; (void)arg7; (void)arg8;
    return NetPortRefuse(g_cXNetQosLookup, "XNetQosLookup",
                         kXErrorFunctionFailed);
}

// ===========================================================================
// 12. NetDll_XNetQosRelease
//     REFUSE, and the one entry of the eighteen with a genuinely portable arm.
//     Xenia: xam_net.cc:592-600, declared kStub:
//         if (!qos) { return X_STATUS_INVALID_PARAMETER; }
//         SystemHeapFree(qos.guest_address());
//         return 0;
//     The NULL arm is REAL and is ported: a NULL probe is genuinely invalid and
//     Xenia's answer for it needs no host state. The non-NULL arm refuses,
//     because the record would have to be one XNetQosLookup allocated -- and
//     this file refuses every Lookup, so no such record exists to free.
//     Returning 0 there would claim ownership of a record this host never had.
//     Code: NULL probe -> X_STATUS_INVALID_PARAMETER (0xC000000D, xbox.h:51,
//     Xenia's own value); non-NULL probe -> X_ERROR_NOT_FOUND (0x490,
//     xbox.h:101), meaning "no such record", which is the truth.
//     ARITY 2 -- thunk sub_8244A660: 1 shift + `li r3,1`
//     (ppc_recomp.82.cpp:6935) = (selector, qos), matching Xenia's 2.
// ===========================================================================
uint32_t NetDll_XNetQosRelease(uint32_t dllSelector, void* qos) {
    (void)dllSelector;
    if (qos == nullptr) {
        // REAL -- Xenia xam_net.cc:594-596. A NULL probe is genuinely invalid
        // and the answer needs no host state, so this arm is a port and not a
        // refusal. Counted as REAL so a soak can tell it apart from the arm
        // below on the marker alone.
        NetPortCount(g_cXNetQosRelease, "XNetQosRelease[NULL]", /*real=*/true,
                     kXStatusInvalidParameter);
        mcla::kernel::netport::SetLastError(kXStatusInvalidParameter);
        GuestThread::SetLastError(kXStatusInvalidParameter);
        return kXStatusInvalidParameter;
    }
    return NetPortRefuse(g_cXNetQosRelease, "XNetQosRelease",
                         kXErrorNotFound);
}

// ===========================================================================
// 13. NetDll_XNetRegisterKey
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: this registers a Live session key so two peers can
//     find each other. There is no Live service, so there is nothing to
//     register with and no key to hold. The old body returned 0 while copying
//     nothing: the title was told it had a session key it did not have.
//     Code: X_ERROR_FUNCTION_FAILED (0x65B, xbox.h:105).
//     ARITY 3 -- thunk sub_8244A560: 2 shifts + `li r3,1`
//     (ppc_recomp.82.cpp:6670) = (selector, keyType, key).
// ===========================================================================
uint32_t NetDll_XNetRegisterKey(uint32_t dllSelector, uint32_t keyType,
                                void* key, uint32_t keyLen) {
    (void)dllSelector; (void)keyType; (void)key; (void)keyLen;
    return NetPortRefuse(g_cXNetRegisterKey, "XNetRegisterKey",
                         kXErrorFunctionFailed);
}

// ===========================================================================
// 14. NetDll_XNetUnregisterKey
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: nothing was ever registered -- this file refuses
//     every RegisterKey -- so there is no key to unregister, and "no such key"
//     is the exact answer. The old body did nothing at all, silently, which is
//     the defect being removed.
//     Code: X_ERROR_NOT_FOUND (0x490, xbox.h:101).
//     ARITY 2 -- thunk sub_8244A570: 1 shift + `li r3,1`
//     (ppc_recomp.82.cpp:6685) = (selector, keyType).
// ===========================================================================
uint32_t NetDll_XNetUnregisterKey(uint32_t dllSelector, uint32_t keyType) {
    (void)dllSelector; (void)keyType;
    return NetPortRefuse(g_cXNetUnregisterKey, "XNetUnregisterKey",
                         kXErrorNotFound);
}

// ===========================================================================
// 15. NetDll_XNetServerToInAddr
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: this is the one entry in the set whose whole purpose
//     is to produce a PEER ADDRESS. The host has no Live directory, so there is
//     no server to resolve; emitting an in_addr would be inventing network
//     topology, which is the single most dangerous fabrication available here.
//     The old body returned 0 and never touched `inAddr`, so the guest went on
//     to read its own uninitialised stack as a resolved peer address.
//     Code: X_ERROR_NOT_FOUND (0x490, xbox.h:101) -- "no such server".
//     ARITY 4 -- thunk sub_8244A598: 3 shifts + `li r3,1`
//     (ppc_recomp.82.cpp:6741) = (selector, xnAddr, xnkid, inAddr).
// ===========================================================================
uint32_t NetDll_XNetServerToInAddr(uint32_t dllSelector, void* xnAddr,
                                   void* inAddr, void* xnkid) {
    (void)dllSelector; (void)xnAddr; (void)inAddr; (void)xnkid;
    return NetPortRefuse(g_cXNetServerToInAddr, "XNetServerToInAddr",
                         kXErrorNotFound);
}

// ===========================================================================
// 16. NetDll_XNetUnregisterInAddr
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: there is no registered in_addr -- this file refuses
//     every ServerToInAddr/XnAddrToInAddr, and SYNTH-XNET hands the title a
//     zeroed XNADDR (imports.cpp:6123-6148) rather than a resolved one -- so
//     there is nothing to unregister.
//     Code: X_ERROR_NOT_FOUND (0x490, xbox.h:101).
//     ARITY 2 -- thunk sub_8244A5B0: 1 shift + `li r3,1`
//     (ppc_recomp.82.cpp:6765) = (selector, inAddr).
// ===========================================================================
uint32_t NetDll_XNetUnregisterInAddr(uint32_t dllSelector, void* inAddr) {
    (void)dllSelector; (void)inAddr;
    return NetPortRefuse(g_cXNetUnregisterInAddr, "XNetUnregisterInAddr",
                         kXErrorNotFound);
}

// ===========================================================================
// 17. NetDll_XNetXnAddrToInAddr
//     REFUSE. Xenia: xam_net.cc:504-509, DECLARED kStub -- a three-line body
//     that `return 1;` and does not read a single one of its four arguments.
//     This is Xenia stubbing the function outright, and it is reported as such
//     rather than dressed up as a port. Xenia's 1 is its failure value, and it
//     is also the correct answer here: an XNADDR with no IP behind it cannot be
//     converted, and 1 says "conversion failed" without inventing an address.
//     The old body returned 0 -- a SUCCESSFUL conversion, leaving the caller's
//     inAddr uninitialised, which is how a guest ends up dialling a stack
//     address it made up itself.
//     Code: 1, Xenia's own value (xam_net.cc:507).
//     ARITY 4 -- thunk sub_8244A580: 3 shifts + `li r3,1`
//     (ppc_recomp.82.cpp:6713), matching Xenia's 4-parameter signature
//     (caller, xn_addr, xid, in_addr) exactly.
//     CONSISTENCY WITH SYNTH-XNET: XNetGetTitleXnAddr zeroes the caller's
//     XNADDR, so this conversion is handed an empty address and refuses it.
//     SYNTH-XNET claims the handshake succeeded; this says the address behind
//     it is empty. Those are compatible, and the second is the honest half.
// ===========================================================================
uint32_t NetDll_XNetXnAddrToInAddr(uint32_t dllSelector, void* xnAddr,
                                   void* xnkid, void* inAddr) {
    (void)dllSelector; (void)xnAddr; (void)xnkid; (void)inAddr;
    return NetPortRefuse(g_cXNetXnAddrToInAddr, "XNetXnAddrToInAddr", 1u);
}

// ===========================================================================
// 18. XNetLogonGetTitleID
//     REFUSE. Xenia: NO IMPLEMENTATION -- absent from the whole Xenia tree
//     (measured). Reason: this returns a TITLE IDENTIFIER. A title ID is a
//     fact about the running XEX, and inventing one is explicitly out of
//     bounds; there is also no Live logon to ask.
//     THE RETURN VALUE IS THE HONEST PART AND THE TRAP IN THIS ENTRY: it is
//     0, because every non-zero value here would BE a fabricated title
//     identifier. That means the guest stores 0 where it wanted a title ID
//     (it is written straight to the guest stack, ppc_recomp.82.cpp:7063 and
//     :9093), and 0 is indistinguishable from "title id zero". This is the one
//     refusal in the file whose return value does not describe itself, so the
//     refusal is counted loudly and the fact is recorded here rather than left
//     for a reader to infer. Returning an X_ERROR code instead was rejected
//     deliberately: 0x4DD is a perfectly plausible title ID, so an error code
//     in this slot is a fabrication with extra steps.
//     ARITY 1, AND IT IS NOT A SELECTOR -- MEASURED. This entry is not reached
//     through a thunk in the 0x8244A*** table at all. The guest `bl 0x827bd304`
//     directly, twice, with `li r3,9` (ppc_recomp.82.cpp:7058-7062) and
//     `li r3,2` (ppc_recomp.82.cpp:9088-9092). r3 is therefore a USER INDEX,
//     not the leading selector the other seventeen carry, and naming it
//     `dllSelector` would be wrong even though the arity happens to match.
//     (`ppc_xrefs.py xref 0x827BD304` reports "0 site(s) materialising" -- the
//     tool misses these two; the generated code above is the better source and
//     is cited in preference to the tool.)
// ===========================================================================
uint32_t XNetLogonGetTitleID(uint32_t userIndex) {
    // Refusal, counted, and NOT a title id. See the note above.
    return NetPortRefuse(g_cXNetLogonGetTitleID, "XNetLogonGetTitleID", 0u);
}

// ===========================================================================
// REGISTRATION. GUEST_FUNCTION_HOOK expands to a definition of __imp__X
// (src/kernel/function.h:637-638), so every one of these sits at GLOBAL
// SCOPE -- not inside a namespace -- or it would define the wrong symbol.
// Each replaces a GUEST_FUNCTION_STUB whose body was `PPC_FUNC(name) { }`.
// ===========================================================================
GUEST_FUNCTION_HOOK(__imp__NetDll_WSAGetLastError, NetDll_WSAGetLastError);
GUEST_FUNCTION_HOOK(__imp__NetDll_getsockname, NetDll_getsockname);
GUEST_FUNCTION_HOOK(__imp__NetDll_ioctlsocket, NetDll_ioctlsocket);
GUEST_FUNCTION_HOOK(__imp__NetDll_recvfrom, NetDll_recvfrom);
GUEST_FUNCTION_HOOK(__imp__NetDll_sendto, NetDll_sendto);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetCleanup, NetDll_XNetCleanup);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetConnect, NetDll_XNetConnect);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetGetConnectStatus, NetDll_XNetGetConnectStatus);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetGetEthernetLinkStatus, NetDll_XNetGetEthernetLinkStatus);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetQosListen, NetDll_XNetQosListen);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetQosLookup, NetDll_XNetQosLookup);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetQosRelease, NetDll_XNetQosRelease);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetRegisterKey, NetDll_XNetRegisterKey);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetServerToInAddr, NetDll_XNetServerToInAddr);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetUnregisterInAddr, NetDll_XNetUnregisterInAddr);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetUnregisterKey, NetDll_XNetUnregisterKey);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetXnAddrToInAddr, NetDll_XNetXnAddrToInAddr);
GUEST_FUNCTION_HOOK(__imp__XNetLogonGetTitleID, XNetLogonGetTitleID);
