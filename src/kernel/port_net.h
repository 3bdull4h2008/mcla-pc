#pragma once

// ===========================================================================
// port_net.h -- the 18 remaining console networking imports (F-609, native-only)
//
// WHAT THIS HEADER IS FOR. A private, per-function last-error cell and the
// census vocabulary that src/kernel/port_net.cpp uses to make every refusal in
// that file countable. The 18 hook registrations themselves live in the .cpp,
// because GUEST_FUNCTION_HOOK expands to a definition of __imp__X and must
// therefore sit at global scope.
//
// WHY THE CELL IS EXPOSED. The already-ported twelve socket-family functions
// (src/kernel/imports.cpp:4840-4966) keep their last-error in a file-static
// `g_netLastError` inside an anonymous namespace (imports.cpp:4799-4838), which
// no other translation unit can name. NetDll_WSAGetLastError has to report the
// error those refusals set, so one shared, linkable cell has to exist. This is
// it. Until imports.cpp:4835 is repointed at netport::SetLastError, the two
// halves do NOT share state and each file's WSAGetLastError reports only its
// own half -- see the "INTEGRATION" block in the .cpp; it is a required edit
// and it is the integration stream's, not this file's.
//
// NOT A STUB FILE. Every entry has a body. Nothing here returns success without
// having done the work, and nothing fabricates a peer address, a QoS record, a
// session key, a title identifier, or a hardware address.
// ===========================================================================

#include <cstdint>

namespace mcla::kernel::netport
{

// The per-thread WSA last error, Xenia's `XThread::GetLastError()`
// (xam_net.cc:292) as one host cell. ports to a single cell because the guest
// has no TLS last-error plumbed through the socket family; that approximation
// is the same one imports.cpp:4806-4811 already names.
uint32_t LastError();
void SetLastError(uint32_t error);

// Marker prefixes. Two, so that a real implementation and a refusal are
// distinguishable in ONE line of soak output, without needing the log line and
// the source side by side.
inline constexpr const char* kRealMarker = "NETPORT-REAL";
inline constexpr const char* kRefuseMarker = "NETPORT-REFUSE";

} // namespace mcla::kernel::netport
