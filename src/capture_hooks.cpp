#include "capture_hooks.h"
#include "renderer_mode.h"
#include "logging.h"
#include "kernel/memory.h"
#include "gpu_cp.h"

#include <chrono>
#include <algorithm>
#include <atomic>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <filesystem>

namespace mcla::native {

namespace {
static DrawPacketAccumulator g_accumulator;

uint64_t Fnv1a64(const void* data, size_t size, uint64_t hash = 14695981039346656037ULL) {
    const uint8_t* bytes = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; ++i) {
        hash ^= bytes[i];
        hash *= 1099511628211ULL;
    }
    return hash;
}

uint32_t AssembleBE32(const uint8_t* bytes) {
    return (static_cast<uint32_t>(bytes[0]) << 24) |
           (static_cast<uint32_t>(bytes[1]) << 16) |
           (static_cast<uint32_t>(bytes[2]) << 8) |
           static_cast<uint32_t>(bytes[3]);
}

// ---------------------------------------------------------------------------
// F-649: DrawPacket::textureDescriptors[] -- WHERE THE BOUND TEXTURES ACTUALLY
// ARE, and why the list is still empty.
//
// THE LAYOUT (measured, not recalled). A bound texture on a Xenos draw is NOT a
// field of the drawable: Xenia reads it out of the register file, slot by slot.
//   * .research/xenia/src/xenia/gpu/xenos.h:1184-1285 -- xe_gpu_texture_fetch_t,
//     `static_assert_size(..., sizeof(uint32_t) * 6)` at :1285. So a descriptor
//     is 6 dwords / 24 bytes, not 4.
//   * xenos.h:1109 -- kTextureFetchConstantCount = 32 slots.
//   * .research/xenia/src/xenia/gpu/register_file.h:69-77 -- GetTextureFetch(index)
//     memcpy's from values[XE_GPU_REG_SHADER_CONSTANT_FETCH_00_0 + 6*index].
//   * .research/xenia/src/xenia/gpu/registers.h / register_table.inc:2697-2888 --
//     that window is SHADER_CONSTANT_FETCH_00_0 .. _31_5; the 0x4800 base is the
//     one already carried in this tree at src/gpu_cp.cpp:96-98
//     (kRegFetchVbFirst/kRegFetchVbLast, 0x4800..0x48C0 exclusive).
//   * xenos.h:1194 + texture_decode.cpp:1200 -- the discriminator: dword_0 bits
//     [1:0] == 2 (FetchConstantType::kTexture, enum at xenos.h:1102-1107). The
//     OTHER types in the same 6-dword slot are the vertex fetch constants
//     (xenos.h:1110, kVertexFetchConstantCount = 3 * 32) -- which is why the
//     window cannot be scanned blindly for "non-zero slots"; src/gpu_cp.cpp:152-154
//     already says out loud that a non-kVertex slot in that window is a
//     "texture/loop constant landing in the same window".
//   * Field offsets within the descriptor, all from xenos.h:1193-1283 and already
//     re-decoded bit-for-bit by native::DecodeGuestTextureDescriptor
//     (renderer/texture_decode.cpp:1185+): dword_0 +0 type, +2/+4/+6/+8 sign,
//     +10/+13/+16 clamp, +22 pitch, +31 tiled; dword_1 +0 format, +6 endianness,
//     +10 stacked, +12 base_address>>12; dword_2 the size union (xenos.h:1233-1250,
//     "Size is stored with 1 subtracted from each component", :1232); dword_4 +2
//     mip_min_level, +6 mip_max_level; dword_5 +9 dimension, +11 packed_mips,
//     +12 mip_address>>12.
//
// WHAT THIS FUNCTION DOES WITH THAT. `fetchWindow` is a HOST copy of the 32x6
// dword register window (host dwords in host order -- the register file is a host
// array, not guest memory, so there is no endianness to declare here and no
// guest pointer to check).
//
// CORRECTION (F-649, measured 2026-09-30). The note above this paragraph used
// to read: "`nullptr` is the honest current value, because the only live
// register file is file-static inside src/gpu_cp.cpp (g_xenosReg) and
// src/gpu_cp.h exposes no accessor." THAT PREMISE IS STALE AND IT WAS WRONG.
// F-647 already opened the file: `bool CpReadGuestRegisters(const uint32_t*,
// uint32_t, uint32_t* values, uint32_t* present)` is declared at
// src/gpu_cp.h:107-108 and defined at src/gpu_cp.cpp:3586-3613, read-only, with
// per-register PRESENCE. So the window is reachable from this translation unit
// today, and passing `nullptr` was not honesty -- it was an uncited assumption
// acting as a fact, which is the exact failure class rule 14 exists to stop.
// The nullptr branch is retained below (a source that cannot be read must still
// refuse LOUDLY) but it is no longer the path this file takes.
//
// IS THE WINDOW EMPTY, OR UNREAD? Measured, and it is EMPTY, on both phases of
// the same build -- the two causes have opposite fixes and only one is present:
//
//   instrument                                        build/w662      build/w669
//   CP-FETCHVB rows (src/gpu_cp.cpp:482-496)            8,279             0
//   distinct CP-REG-HI bases >= 0x2000 (:602-618)          27              0
//   PM4_SET_CONSTANT packets (CP-SETCONST, :1598)          --             0
//
// CpRegPoke (src/gpu_cp.cpp:462) is the SINGLE choke point every register write
// passes through -- the TYPE-0 path at :584 and the PM4_SET_CONSTANT path at
// :1584 both call it -- and it emits CP-FETCHVB for every accepted write whose
// index lands in [0x4800, 0x48C0). Its log is bounded (`w <= 8 || w % 200`),
// so ZERO rows is a proof of ZERO writes, not a cap artefact. CP-REG-HI is the
// stronger control because it is NOT counter-capped: one row per DISTINCT base,
// "so an absent line really means the guest never wrote that base" (:598-601).
// w662 lists 27 bases including 4800; w669 lists none at all. Conclusion: in
// this phase the guest never wrote the window. Nothing is unread. A capture
// defect would have to show writes landing in g_xenosReg with the row missing,
// and the choke point makes that impossible.
//
// The window's extent is also re-derived here rather than taken from the
// message text: register_table.inc names SHADER_CONSTANT_FETCH_00_0 at 0x4800
// and SHADER_CONSTANT_FETCH_31_5 at 0x48BF, i.e. 32 slots x 6 dwords = 192
// dwords, 0x4800..0x48BF inclusive, 0x48C0 exclusive -- which is exactly
// src/gpu_cp.cpp:114-115. SIX REGISTERS PER SLOT IS VERIFIED, from two
// independent statements in the reference and not from the message: (a)
// `static_assert_size(xe_gpu_texture_fetch_t, sizeof(uint32_t) * 6)` at
// xenos.h:1285, and (b) register_file.h:73-74, which memcpy's from
// values[XE_GPU_REG_SHADER_CONSTANT_FETCH_00_0 + (sizeof(fetch) /
// sizeof(uint32_t)) * index] -- the stride is literally `sizeof(union)/4`.
// `6*i` is right, and it is also the reason one 6-dword window has to carry
// both the 2-dword vertex form (xenos.h:1127) and the 6-dword texture form.
//
// The discriminator is FetchConstantType (xenos.h:1102-1107), an enum, NOT
// magic 2: kInvalidTexture=0, kInvalidVertex=1, kTexture=2, kVertex=3. The
// value is compared by name below so a reordering of that enum cannot silently
// turn a vertex slot into a texture. Observed consequence on real data: the
// w662 window writes carry dword_0 = 0x06658CBF / 0x1000001A, and
// 0x06658CBF & 3 == 3 == kVertex -- so even the phase that DID populate the
// window was writing VERTEX fetch constants into it, not texture descriptors.
//
// So this reads the window for real, counts OCCUPANCY separately from the
// refusal, refuses by NAME instead of truncating or defaulting, and separates
// three causes that previously all read as one number: the window is empty /
// the window was read and its texture slots were rejected / no texture was
// ever bound. It never invents a descriptor and never guesses a field offset.
// ---------------------------------------------------------------------------

constexpr uint32_t kFetchSlotDwords = 6;       // xenos.h:1285 + register_file.h:73-74
constexpr uint32_t kFetchSlotCount = 32;       // xenos.h:1109
constexpr uint32_t kMaxTextureDescriptors = 16;  // DrawPacket::textureDescriptors[16]
constexpr uint32_t kFetchWindowBase = 0x4800u;   // register_table.inc SHADER_CONSTANT_FETCH_00_0
constexpr uint32_t kFetchWindowDwords = kFetchSlotCount * kFetchSlotDwords;  // 192 == 0x48C0-0x4800
// xenos.h:1102-1107. Spelled out rather than written as a bare 2 so that a
// change to that enum is a compile-visible mismatch, not a silent mis-decode.
constexpr uint32_t kFetchConstantTypeTexture = 2u;
constexpr uint32_t kFetchConstantTypeVertex = 3u;

// F-649: attempts vs successes, deliberately separate. A soak must be able to
// tell "the guest bound no texture" (attempts 0) from "textures were bound and
// none were captured" (attempts > 0, successes 0) -- the single distinction this
// list has never been able to make because it was never written at all.
uint64_t g_textureDescAttempts = 0;
uint64_t g_textureDescSuccesses = 0;
uint64_t g_textureDescNoWindow = 0;
uint64_t g_textureDescOverBind = 0;

// F-649 (2026-09-30): the THREE-CAUSE CENSUS. 774 identical TEXDESC rows in
// build/w669.log were three different facts wearing one number, and a soak
// could not separate them. Each cause now owns a counter of its own, they are
// mutually exclusive per read, and the three sum to g_texWindowReads:
//   empty   - the accessor was called and NO dword of the 192-dword window has
//             ever been poked. (Measured on w669: this is the whole 774.)
//   notex   - the window IS occupied but no slot decodes to kTexture, so the
//             window carries vertex/loop constants instead. (This is what w662
//             was: dword_0 & 3 == 3 == kVertex.)
//   refused - the window was read and DID yield kTexture slot(s), and they are
//             still not bound, because no 24-byte snapshot address is derivable.
// `reads` is separate from `attempts` so a source that could not be read at all
// shows up as attempts > reads instead of masquerading as "empty".
uint64_t g_texWindowReads = 0;
uint64_t g_texWindowEmpty = 0;
uint64_t g_texWindowNotex = 0;
uint64_t g_texWindowRefused = 0;   // == g_textureDescSuccesses, kept as a distinct name
uint64_t g_texPresentDwords = 0;  // cumulative dwords of the window ever written
uint64_t g_texSlotsTotal = 0;     // cumulative kTexture slots seen
uint64_t g_texVertexSlotsTotal = 0;  // cumulative kVertex slots seen (the other tenant)
uint64_t g_texMaxPresentDwords = 0;  // high-water occupancy of the 192-dword window
uint64_t g_texFrames = 0;
uint64_t g_texFramesNoAttempt = 0;  // frames that ended without one OnDrawBuild

constexpr uint64_t kTexDescLogFirst = 8;
constexpr uint64_t kTexDescLogEvery = 200;
inline bool ShouldLogTexDesc(uint64_t n) {
    return n <= kTexDescLogFirst || (n % kTexDescLogEvery) == 0;
}

// The register indices of the whole window, built once at compile time so the
// hot path is 192 relaxed atomic loads and no arithmetic per dword.
struct FetchWindowIndexTable {
    uint32_t idx[kFetchWindowDwords];
    constexpr FetchWindowIndexTable() : idx{} {
        for (uint32_t i = 0; i < kFetchWindowDwords; ++i) idx[i] = kFetchWindowBase + i;
    }
};
constexpr FetchWindowIndexTable kFetchWindowIndices{};

// Scratch for the export. 64-byte aligned so the 192-dword value/presence reads
// do not straddle lines unnecessarily. NOT thread_local: the file's only other
// mutable state (g_accumulator) is likewise a single object, and the one caller
// is the capture path. CpReadGuestRegisters is documented "consistent per
// register, not across registers" (src/gpu_cp.cpp:3576-3578) -- correct here,
// because a torn read would need the CP thread to be mid-poke of the window
// while a draw is captured, and a torn read can only move the occupancy COUNT,
// never manufacture a kTexture slot the guest did not write.
alignas(64) uint32_t g_fetchWindowValues[kFetchWindowDwords];
alignas(64) uint32_t g_fetchWindowPresent[kFetchWindowDwords];

// Reads the live register file. Returns the number of dwords of the 192-dword
// window that have EVER been poked. `texSlots`/`vertexSlots` count the two
// FetchConstantType discriminants of interest. `ok` is CpReadGuestRegisters'
// own return, forwarded so a failed read stays distinguishable from an empty
// window instead of collapsing into it.
using mcla::gpu::CpReadGuestRegisters;  // src/gpu_cp.h:5 namespace mcla::gpu (as render_thread.cpp:633)
uint32_t ReadGuestFetchWindow(uint32_t* texSlots, uint32_t* vertexSlots, bool* ok) {
    *texSlots = 0;
    *vertexSlots = 0;
    // CpReadGuestRegisters returns false only when every requested index was out
    // of the register file, and these indices are compile-time constants, so it
    // is a fixed true in this build. It is checked and reported rather than
    // asserted: a future narrowing of kXenosRegCount would then degrade into
    // the named "source unreadable" refusal below, which is the correct
    // behaviour, instead of into a silent zero window.
    *ok = CpReadGuestRegisters(kFetchWindowIndices.idx, kFetchWindowDwords,
                               g_fetchWindowValues, g_fetchWindowPresent);
    if (!*ok) return 0;

    uint32_t presentCount = 0;
    for (uint32_t slot = 0; slot < kFetchSlotCount; ++slot) {
        const uint32_t d0 = g_fetchWindowValues[slot * kFetchSlotDwords];
        // Only a slot whose dword_0 was actually WRITTEN may be classified. A
        // never-written dword_0 reads 0 == kInvalidTexture, so without this test
        // an empty window would report 32 texture slots -- the exact "an
        // unwritten register decodes as a legal zero" defect F-647 exists to
        // prevent, one layer up.
        if (!g_fetchWindowPresent[slot * kFetchSlotDwords]) continue;
        switch (d0 & 3u) {
            case kFetchConstantTypeTexture: ++*texSlots; break;
            case kFetchConstantTypeVertex:  ++*vertexSlots; break;
            default: break;  // kInvalidTexture / kInvalidVertex: not a descriptor
        }
    }
    for (uint32_t i = 0; i < kFetchWindowDwords; ++i) {
        if (g_fetchWindowPresent[i]) ++presentCount;
    }
    return presentCount;
}

// The cumulative census, one row per bounded step. Every number a soak needs to
// tell the three causes apart is on this single line, and the per-cause rows
// below name WHICH cause fired rather than leaving a soak to subtract.
void LogTexDescCensus(uint64_t n) {
    MCLA_LOG_WARN(
        "TEXDESC-CENSUS #{} attempts={} windowReads={} empty={} notex={} refused={} "
        "noWindow={} overBind={} | occupancy: presentDwords={}/{} (max {}) "
        "texSlotsTotal={} vertexSlotsTotal={}",
        n, g_textureDescAttempts, g_texWindowReads, g_texWindowEmpty,
        g_texWindowNotex, g_texWindowRefused, g_textureDescNoWindow,
        g_textureDescOverBind, g_texPresentDwords, kFetchWindowDwords,
        g_texMaxPresentDwords, g_texSlotsTotal, g_texVertexSlotsTotal);
}

// `fetchWindow` may be null, and then the source is treated as UNREADABLE --
// which is a different fact from "readable and empty", and is counted as such.
// `fetchPresent` is the matching per-dword presence array; a null `fetchWindow`
// makes it irrelevant. Returns the number of descriptor slots written.
uint32_t CaptureTextureDescriptors(const uint32_t* fetchWindow,
                                   const uint32_t* fetchPresent, DrawPacket& packet) {
    // Reset first, unconditionally. These fields are zero-initialised once and
    // m_currentPacket is reused across draws, so without this a draw that binds
    // nothing inherits the PREVIOUS draw's list -- which would read as a texture
    // bound that was never bound.
    packet.textureCount = 0;
    for (uint32_t i = 0; i < kMaxTextureDescriptors; ++i) packet.textureDescriptors[i] = 0;

    ++g_textureDescAttempts;

    if (fetchWindow == nullptr) {
        const uint64_t n = ++g_textureDescNoWindow;
        if (ShouldLogTexDesc(n)) {
            // LOUD AND STILL CORRECT, but the reason is no longer the stale one.
            // It now names the one thing that is actually true when this fires:
            // the read of the register file FAILED, which is not the same as the
            // window being empty. Kept as MCLA_LOG_ERROR -- a bound texture with
            // no descriptor must never be defaulted, and nothing here may soften
            // this into a warning.
            MCLA_LOG_ERROR("TEXDESC refused #{}: the Xenos register file could not be READ "
                           "(CpReadGuestRegisters, src/gpu_cp.h:107, returned false), so the "
                           "fetch-constant window 0x4800..0x48BF ({} dwords = 32 slots x 6, "
                           "xenos.h:1285 + register_file.h:73-74) is UNKNOWN -- not empty. "
                           "DrawPacket::textureDescriptors[] stays EMPTY and textureCount == 0. "
                           "attempts={} windowReads={} empty={} refused={}: this is a read "
                           "failure, which attempts>windowReads is the signature of.",
                           n, kFetchWindowDwords, g_textureDescAttempts, g_texWindowReads,
                           g_texWindowEmpty, g_texWindowRefused);
        }
        return 0;
    }

    uint32_t found = 0;
    for (uint32_t slot = 0; slot < kFetchSlotCount; ++slot) {
        const uint32_t* d = fetchWindow + slot * kFetchSlotDwords;
        // xenos.h:1194: dword_0 bits [1:0] is FetchConstantType, and the enum
        // value is 2 for kTexture (xenos.h:1102-1107) -- compared against the
        // named constant, not a bare literal.
        if ((d[0] & 3u) != kFetchConstantTypeTexture) continue;
        // Presence is required, for the reason in ReadGuestFetchWindow: a
        // never-written dword_0 is 0 and would decode as kInvalidTexture, which
        // is not a texture and must not be counted as one.
        if (fetchPresent != nullptr && !fetchPresent[slot * kFetchSlotDwords]) continue;

        if (found >= kMaxTextureDescriptors) {
            // Refuse by name, do not truncate and do not write past the end.
            const uint64_t n = ++g_textureDescOverBind;
            if (ShouldLogTexDesc(n)) {
                MCLA_LOG_ERROR("TEXDESC refused #{}: guest bound more than {} textures; slot {} "
                               "(t{}) and beyond are NOT captured and the first {} are kept. "
                               "textureCount is left at {} -- the draw binds only those {}.",
                               n, kMaxTextureDescriptors, slot, slot, kMaxTextureDescriptors,
                               kMaxTextureDescriptors, kMaxTextureDescriptors);
            }
            break;
        }

        // DrawPacket::textureDescriptors[i] is 32 bits, so it cannot hold the
        // 24-byte descriptor. Per renderer/texture_decode.cpp:1154-1156 and
        // d3d12_backend.h:216-221 the backend consumes a 24-BYTE SNAPSHOT handed
        // over by the producer, and textureDescriptors[i] is documented as that
        // snapshot's guest address. There is no guest-addressable copy of a
        // register-file slot on this hardware, so there is nothing honest to
        // store here yet: a fabricated address would bind the wrong texture,
        // which renders a wrong image with no error anywhere.
        //
        // The slot's decode is therefore deliberately NOT performed from guessed
        // bytes. What IS recorded is the count, because "the window had N kTexture
        // slots" is the fact that tells the next stream whether the register file
        // is worth plumbing at all.
        ++found;
    }

    // `found` is the measurement that survives even though no snapshot address
    // can be stored: it says the window, when it is finally plumbed, is worth
    // plumbing for this draw. Logged only when non-zero, under the same bound.
    if (found != 0) {
        const uint64_t n = ++g_textureDescSuccesses;
        ++g_texWindowRefused;
        if (ShouldLogTexDesc(n)) {
            MCLA_LOG_ERROR("TEXDESC refused #{}: window WAS read and DID yield {} kTexture "
                           "slot(s) (t0..t{}, 6 dwords each per xenos.h:1285), but no 24-byte "
                           "snapshot address is derivable, so textureCount stays 0 and the draw "
                           "binds NOTHING. This is the read-and-rejected cause, NOT the empty "
                           "window: empty={} notex={} refused={} presentDwords={}/{}.",
                           n, found, found - 1, g_texWindowEmpty, g_texWindowNotex,
                           g_texWindowRefused, g_texPresentDwords, kFetchWindowDwords);
        }
    }

    packet.textureCount = 0;  // no snapshot address is derivable yet; see above
    return packet.textureCount;
}

// F-649: the per-draw entry point. Reads the window FIRST so that occupancy is
// a number in its own right and the walk below can never be the thing that
// decides whether the window was empty.
void BindGuestTextureDescriptors(DrawPacket& packet) {
    const uint32_t attemptNo = g_textureDescAttempts + 1u;  // for the cadence only

    uint32_t texSlots = 0;
    uint32_t vertexSlots = 0;
    bool readOk = false;
    const uint32_t presentCount = ReadGuestFetchWindow(&texSlots, &vertexSlots, &readOk);

    ++g_texWindowReads;
    g_texPresentDwords += presentCount;
    g_texSlotsTotal += texSlots;
    g_texVertexSlotsTotal += vertexSlots;
    if (presentCount > g_texMaxPresentDwords) g_texMaxPresentDwords = presentCount;

    if (readOk) {
        if (presentCount == 0) {
            ++g_texWindowEmpty;
            if (ShouldLogTexDesc(g_texWindowEmpty)) {
                MCLA_LOG_ERROR(
                    "TEXDESC refused #{}: fetch-constant window 0x4800..0x48BF is EMPTY -- 0 of "
                    "its {} dwords has EVER been written (CpReadGuestRegisters presence, "
                    "src/gpu_cp.h:107). textureCount 0, nothing bound. The window is not "
                    "unreadable and not mis-decoded: the guest has not populated it at this "
                    "point of its own pipeline. attempts={} windowReads={} empty={} notex={} "
                    "refused={}.",
                    g_texWindowEmpty, kFetchWindowDwords, g_textureDescAttempts,
                    g_texWindowReads, g_texWindowEmpty, g_texWindowNotex, g_texWindowRefused);
            }
        } else if (texSlots == 0) {
            ++g_texWindowNotex;
            if (ShouldLogTexDesc(g_texWindowNotex)) {
                MCLA_LOG_ERROR(
                    "TEXDESC refused #{}: window 0x4800..0x48BF is OCCUPIED "
                    "(presentDwords={}/{}) but 0 slots decode to FetchConstantType::kTexture -- "
                    "{} slot(s) decode to kVertex instead, so this window is carrying "
                    "vertex/loop fetch constants, not texture descriptors (xenos.h:1102-1107; "
                    "one 6-dword slot serves both forms). textureCount 0. attempts={} "
                    "windowReads={} empty={} notex={} refused={}.",
                    g_texWindowNotex, presentCount, kFetchWindowDwords, vertexSlots,
                    g_textureDescAttempts, g_texWindowReads, g_texWindowEmpty,
                    g_texWindowNotex, g_texWindowRefused);
            }
        }
    }

    // A failed read passes nullptr, which is the ONLY way the "source unreadable"
    // refusal in CaptureTextureDescriptors can fire. That is deliberate: the
    // unreadable case must never be counted as the empty case, or the three-way
    // census would collapse back to two.
    const uint32_t* window = readOk ? g_fetchWindowValues : nullptr;
    const uint32_t* present = readOk ? g_fetchWindowPresent : nullptr;
    CaptureTextureDescriptors(window, present, packet);

    if (ShouldLogTexDesc(attemptNo)) LogTexDescCensus(attemptNo);
}

} // namespace

DrawPacketAccumulator* GetDrawAccumulator() {
    return &g_accumulator;
}

DrawPacketAccumulator::DrawPacketAccumulator() = default;
DrawPacketAccumulator::~DrawPacketAccumulator() = default;

void DrawPacketAccumulator::Initialize(uint8_t* base, uint32_t size) {
    m_memoryView.SetMemoryBase(base, size);
}

void DrawPacketAccumulator::SetCaptureEnabled(bool enabled, const std::filesystem::path& tracePath) {
    m_captureEnabled = enabled;
    if (m_captureEnabled && !tracePath.empty()) {
        m_writer.Open(tracePath);
        m_shaderDumpDir = tracePath.parent_path() / "shaders";
        m_memDumpDir = tracePath.parent_path() / "guestmem";
        m_dumpedRanges.clear();
    } else {
        m_writer.Close();
        m_shaderDumpDir.clear();
        m_memDumpDir.clear();
    }
}

void DrawPacketAccumulator::OnStateSetup(::MclaGpuContext* gpuCtx, uint32_t srcStateAddr) {
    if (!gpuCtx) return;

    if (!srcStateAddr || !m_memoryView.IsValidRange(srcStateAddr, 128)) {
        m_lastCaptureFailed = true;
        return;
    }

    bool ok = true;
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 108, &m_currentPacket.colorTargets[0]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 112, &m_currentPacket.colorTargets[1]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 116, &m_currentPacket.colorTargets[2]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 120, &m_currentPacket.colorTargets[3]);
    ok &= m_memoryView.ReadU32BE(srcStateAddr + 124, &m_currentPacket.depthTarget);
    if (!ok) m_lastCaptureFailed = true;
}

void DrawPacketAccumulator::OnDrawBuild(::MclaGpuContext* gpuCtx, ::PPCContext& ctx) {
    if (!gpuCtx) return;

    uint32_t drawFlags = ctx.r4.u32;
    uint32_t primType = drawFlags & 7;

    m_currentPacket.primType = primType;
    m_currentPacket.drawFlags = drawFlags;
    m_currentPacket.startIndex = 0;
    m_currentPacket.indexCount = gpuCtx->drawVertexCount;
    m_currentPacket.baseVertex = 0;

    const uint32_t indexField = (drawFlags >> 4) & 0x7;
    switch (indexField) {
        case 0x1: m_currentPacket.indexType = 0; break;
        case 0x5: m_currentPacket.indexType = 1; break;
        case 0x7: m_currentPacket.indexType = 2; break;
        default:
            m_currentPacket.indexType = 0;
            m_lastCaptureFailed = true;
            break;
    }

    m_currentPacket.paClipCntl = gpuCtx->paClipCntl;
    m_currentPacket.paSuScModeCntl = gpuCtx->paSuScModeCntl;
    m_currentPacket.paClVteCntl = gpuCtx->paClVteCntl;

    // F-649: bound textures. The register window that carries them IS reachable
    // -- CpReadGuestRegisters (src/gpu_cp.h:107) opened it at F-647 -- so this
    // no longer passes a standing nullptr. It reads the window, records the
    // window's OCCUPANCY as a number in its own right, and refuses by name
    // rather than leaving textureCount silently at whatever the previous draw
    // left. Every other field of the packet is still live.
    BindGuestTextureDescriptors(m_currentPacket);

    m_currentPacket.sqVsProgram = gpuCtx->sqVsProgram;
    m_currentPacket.sqVsConst = gpuCtx->sqVsConst;
    m_currentPacket.sqPsProgram = gpuCtx->sqPsProgram;
    m_currentPacket.sqPsConst = gpuCtx->sqPsConst;

    m_currentPacket.viewportTL = gpuCtx->rbSurfaceInfoP2;
    m_currentPacket.viewportBR = gpuCtx->rbSurfaceInfoP3;
    m_currentPacket.scissorTL = gpuCtx->rbSurfaceInfoP4;
    m_currentPacket.scissorBR = gpuCtx->rbSurfaceInfoP5;

    uint32_t vbPtr = ctx.r7.u32;
    m_currentPacket.vertexStreamCount = 0;
    if (vbPtr) {
        if (m_memoryView.IsValidRange(vbPtr, 16)) {
            uint32_t streamAddr = 0;
            uint32_t stride = 0;
            if (m_memoryView.ReadU32BE(vbPtr, &streamAddr) &&
                m_memoryView.ReadU32BE(vbPtr + 4, &stride)) {
                m_currentPacket.vertexStreams[0].guestAddress = streamAddr;
                m_currentPacket.vertexStreams[0].stride = stride;
                m_currentPacket.vertexStreams[0].offset = 0;
                m_currentPacket.vertexStreams[0].format = 0;
                m_currentPacket.vertexStreamCount = 1;
            } else {
                m_lastCaptureFailed = true;
            }
        } else {
            m_lastCaptureFailed = true;
        }
    }

    constexpr uint32_t kDrawableOffset = 10896;
    uint32_t drawablePtr = 0;
    uint32_t gpuCtxGuestAddr = mcla::kernel::g_memory.MapVirtual(gpuCtx);
    if (m_memoryView.IsValidRange(gpuCtxGuestAddr + kDrawableOffset, 4)) {
        m_memoryView.ReadU32BE(gpuCtxGuestAddr + kDrawableOffset, &drawablePtr);
    }

    constexpr uint32_t kDrawableShaderGroupOff[] = { 0x28, 0x30, 0x38, 0x20 };
    constexpr uint32_t kShaderGroupVDeclOff[]  = { 0x10, 0x18, 0x20, 0x08 };
    constexpr uint32_t kVDeclFvfOff[]          = { 0x10, 0x20, 0x30, 0x08, 0x40 };

    uint32_t fvfMask = 0;
    uint8_t fvfSize = 0, flags = 0, dynamicOrder = 0, channelCount = 0;
    uint64_t types = 0;
    bool gotFvf = false;

    for (uint32_t dsg : kDrawableShaderGroupOff) {
        if (!drawablePtr) break;
        uint32_t shaderGroupPtr = 0;
        if (!m_memoryView.IsValidRange(drawablePtr + dsg, 4)) continue;
        if (!m_memoryView.ReadU32BE(drawablePtr + dsg, &shaderGroupPtr) || !shaderGroupPtr) continue;

        for (uint32_t sgv : kShaderGroupVDeclOff) {
            if (!shaderGroupPtr) break;
            uint32_t vdeclPtr = 0;
            if (!m_memoryView.IsValidRange(shaderGroupPtr + sgv, 4)) continue;
            if (!m_memoryView.ReadU32BE(shaderGroupPtr + sgv, &vdeclPtr) || !vdeclPtr) continue;

            for (uint32_t vfo : kVDeclFvfOff) {
                if (!vdeclPtr) break;
                if (!m_memoryView.IsValidRange(vdeclPtr + vfo, 16)) continue;
                uint32_t mask = 0;
                uint8_t size = 0, fl = 0, dyn = 0, chcnt = 0;
                uint64_t ty = 0;
                if (m_memoryView.ReadU32BE(vdeclPtr + vfo + 0, &mask) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 4, &size) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 5, &fl) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 6, &dyn) &&
                    m_memoryView.ReadU8(vdeclPtr + vfo + 7, &chcnt) &&
                    m_memoryView.ReadU64BE(vdeclPtr + vfo + 8, &ty)) {
                    if (mask != 0 && size != 0 && ty != 0) {
                        fvfMask = mask;
                        fvfSize = size;
                        flags = fl;
                        dynamicOrder = dyn;
                        channelCount = chcnt;
                        types = ty;
                        gotFvf = true;
                        break;
                    }
                }
            }
            if (gotFvf) break;
        }
        if (gotFvf) break;
    }

    if (gotFvf) {
        m_currentPacket.grcFvf.fvfMask = fvfMask;
        m_currentPacket.grcFvf.fvfSize = fvfSize;
        m_currentPacket.grcFvf.flags = flags;
        m_currentPacket.grcFvf.dynamicOrder = dynamicOrder;
        m_currentPacket.grcFvf.channelCount = channelCount;
        m_currentPacket.grcFvf.types = types;
        m_currentPacket.hasGrcFvf = 1;
    }
}

void DrawPacketAccumulator::OnSubmit(::MclaGpuContext* gpuCtx, uint32_t) {
    if (!gpuCtx) return;

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    uint64_t timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now).count();

    DrawPacket packet = m_currentPacket;
    packet.frameIndex = m_frameIndex;
    packet.sequenceNum = m_sequenceNum++;
    packet.drawInFrame = m_drawInFrame++;
    packet.cpuTimestamp = timestamp;

    packet.stateHash = ComputeStateHash(packet);
    packet.isValid = ValidatePacket(packet) ? 1 : 0;

    if (m_lastCaptureFailed) {
        packet.isValid = 0;
        packet.validationFlags |= (1u << 18);
    }
    m_lastCaptureFailed = false;

    m_totalCapturedDraws++;
    if (packet.isValid) {
        m_validPackets++;
        m_lastPacket = packet;
        m_lastPacketValid = true;
    } else {
        m_invalidPackets++;
        m_lastPacketValid = false;
    }

    if (m_captureEnabled) {
        if (!m_shaderDumpDir.empty()) {
            std::error_code ec;
            std::filesystem::create_directories(m_shaderDumpDir, ec);
            if (packet.sqVsProgram) DumpShaderIfNew(packet.sqVsProgram, true, m_shaderDumpDir);
            if (packet.sqPsProgram) DumpShaderIfNew(packet.sqPsProgram, false, m_shaderDumpDir);
        }
        if (!m_memDumpDir.empty()) {
            std::error_code ec;
            std::filesystem::create_directories(m_memDumpDir, ec);
            DumpPacketGuestMemory(packet, m_memDumpDir);
        }
        if (m_writer.IsOpen()) {
            m_writer.WritePacket(packet);
        } else {
            m_droppedPackets++;
        }
    }
}

void DrawPacketAccumulator::OnFrameEnd() {
    // F-649: the per-frame row exists to make the THIRD cause observable. The
    // two per-draw causes are both emitted from inside OnDrawBuild, so a phase in
    // which the guest binds NO texture emits neither -- and "no texture was ever
    // bound" was previously indistinguishable from "the window was empty" purely
    // because the number that would have shown it was never incremented. A frame
    // that ends with no attempt at all now says so, on its own row, and names the
    // cumulative attempts so a soak can compare the two directly. Bounded by the
    // same n <= K || (n % 200) == 0 rule as everything else in this file.
    //
    // KNOWN LIMIT, stated rather than left to be discovered: this row is driven by
    // the present path (src/gpu_device.cpp:4781, the only caller), so in a run
    // where the guest PAUSES before the first present -- which is what
    // build/w669.log does, at 05:54:20 FATAL-SOFT -- this marker is legitimately
    // ZERO and the per-draw rows carry the census alone. Zero TEXDESC-FRAME is
    // therefore evidence about the present path, not about textures.
    const uint64_t n = ++g_texFrames;
    const bool noAttemptThisFrame = (m_drawInFrame == 0);
    if (noAttemptThisFrame) ++g_texFramesNoAttempt;
    if (ShouldLogTexDesc(n)) {
        MCLA_LOG_WARN(
            "TEXDESC-FRAME #{} frame={} drawsThisFrame={} attemptedThisFrame={} | cumulative: "
            "attempts={} windowReads={} empty={} notex={} refused={} noWindow={} overBind={} | "
            "occupancy: presentDwords={}/{} (max {}) texSlotsTotal={} vertexSlotsTotal={} | "
            "framesWithNoAttempt={}/{}",
            n, m_frameIndex, m_drawInFrame, noAttemptThisFrame ? 0u : 1u,
            g_textureDescAttempts, g_texWindowReads, g_texWindowEmpty, g_texWindowNotex,
            g_texWindowRefused, g_textureDescNoWindow, g_textureDescOverBind,
            g_texPresentDwords, kFetchWindowDwords, g_texMaxPresentDwords, g_texSlotsTotal,
            g_texVertexSlotsTotal, g_texFramesNoAttempt, g_texFrames);
    }
    m_frameIndex++;
    m_drawInFrame = 0;
    m_lastPacketValid = false;
    m_lastPacket = {};
}

void DrawPacketAccumulator::DumpShaderIfNew(uint32_t guestAddr, bool isVertex,
                                            const std::filesystem::path& dir) {
    auto& seen = isVertex ? m_dumpedVs : m_dumpedPs;
    if (guestAddr == 0 || seen.count(guestAddr) != 0) return;
    seen.insert(guestAddr);

    constexpr uint32_t kMaxBytes = 0x8000;
    constexpr uint32_t kChunk = 0x1000;

    char name[64];
    std::snprintf(name, sizeof(name), "%s_%08X.bin", isVertex ? "vs" : "ps", guestAddr);
    std::filesystem::path outPath = dir / name;

    std::ofstream out(outPath, std::ios::binary);
    if (!out.is_open()) return;

    std::vector<uint8_t> chunk(kChunk);
    uint32_t written = 0;
    while (written < kMaxBytes) {
        const uint32_t want = std::min(kChunk, kMaxBytes - written);
        if (!m_memoryView.IsValidRange(guestAddr + written, want)) break;
        if (!m_memoryView.ReadBytes(guestAddr + written, chunk.data(), want)) break;
        out.write(reinterpret_cast<const char*>(chunk.data()), want);
        written += want;
    }
    out.close();

    MCLA_LOG_INFO("ShaderDump: {} ({}) -> {} ({} bytes)", name,
                isVertex ? "VS" : "PS", outPath.string(), written);
}

void DrawPacketAccumulator::DumpPacketGuestMemory(const DrawPacket& packet,
                                                  const std::filesystem::path& dir) {
    auto dumpRange = [&](uint32_t guestAddr, uint32_t size, const char* tag) {
        if (!guestAddr || size == 0) return;
        GuestDumpKey key{ guestAddr, size };
        if (!m_dumpedRanges.insert(key).second) return;

        if (!m_memoryView.IsValidRange(guestAddr, size)) {
            MCLA_LOG_WARN("GuestMemDump: range invalid addr=0x{:08X} size={}", guestAddr, size);
            return;
        }

        char name[96];
        std::snprintf(name, sizeof(name), "%s_%08X_%06X.bin", tag, guestAddr, size);
        std::ofstream out(dir / name, std::ios::binary);
        if (!out.is_open()) return;

        std::vector<uint8_t> chunk(0x1000);
        uint32_t written = 0;
        while (written < size) {
            const uint32_t want = std::min<uint32_t>(0x1000, size - written);
            if (!m_memoryView.ReadBytes(guestAddr + written, chunk.data(), want)) break;
            out.write(reinterpret_cast<const char*>(chunk.data()), want);
            written += want;
        }
        out.close();
        MCLA_LOG_INFO("GuestMemDump: {} addr=0x{:08X} size={} -> {} ({} bytes)",
                    tag, guestAddr, size, (dir / name).string(), written);
    };

    for (uint32_t i = 0; i < packet.vertexStreamCount; ++i) {
        const auto& s = packet.vertexStreams[i];
        const uint32_t stride = s.stride ? s.stride : 32;
        const uint32_t maxBytes = stride * (packet.indexCount > 0 ? packet.indexCount : 1);
        const uint32_t dumpBytes = std::min(maxBytes, 0x10000u);
        dumpRange(s.guestAddress, dumpBytes, "vb");
    }
    if (packet.indexBufferAddress && packet.indexBufferSize) {
        dumpRange(packet.indexBufferAddress, packet.indexBufferSize, "ib");
    }
}

uint64_t DrawPacketAccumulator::ComputeStateHash(const DrawPacket& packet) const {
    uint64_t hash = 14695981039346656037ULL;
    hash = Fnv1a64(&packet.primType, sizeof(packet.primType), hash);
    hash = Fnv1a64(&packet.indexCount, sizeof(packet.indexCount), hash);
    hash = Fnv1a64(packet.colorTargets, sizeof(packet.colorTargets), hash);
    hash = Fnv1a64(&packet.depthTarget, sizeof(packet.depthTarget), hash);
    hash = Fnv1a64(&packet.sqVsProgram, sizeof(packet.sqVsProgram), hash);
    hash = Fnv1a64(&packet.sqPsProgram, sizeof(packet.sqPsProgram), hash);
    return hash;
}

bool DrawPacketAccumulator::ValidatePacket(DrawPacket& packet) const {
    uint32_t flags = 0;
    bool valid = true;

    if (packet.sqVsProgram && !m_memoryView.IsValidRange(packet.sqVsProgram, 4)) {
        flags |= (1 << 0);
        valid = false;
    }
    if (packet.sqPsProgram && !m_memoryView.IsValidRange(packet.sqPsProgram, 4)) {
        flags |= (1 << 1);
        valid = false;
    }

    for (uint32_t i = 0; i < packet.vertexStreamCount; ++i) {
        if (packet.vertexStreams[i].guestAddress &&
            !m_memoryView.IsValidRange(packet.vertexStreams[i].guestAddress, 4)) {
            flags |= (1 << (2 + i));
            valid = false;
        }
    }

    // F-611: a packet that names NO geometry must not report itself valid. The
    // old validator only asked whether the addresses it HAPPENED to hold were
    // readable, and a packet holding none is trivially readable - so every
    // degenerate submission counted as a captured, valid draw. That is the
    // capture-side twin of the defect the CP bridge refuses at
    // (DRAW-CP-REFUSE vb-missing), and it is the failure class this project has
    // already been burned by: a submission that "worked" because something else
    // was drawn. Bits 0..17 are the per-address checks above and 18 is the
    // capture-failed latch in OnSubmit, so 19/20 are the next free pair.
    // MEASURED on the boot path: 12 DRAW-GATE lines, all "dummy", vb=00000000
    // stride 0 - exactly this shape.
    if (packet.vertexStreamCount == 0) {
        flags |= (1 << 19);
        valid = false;
    }
    if (packet.indexCount == 0) {
        flags |= (1 << 20);
        valid = false;
    }
    if ((flags & ((1u << 19) | (1u << 20))) != 0) {
        // Bounded (n <= 8 || n % 200 == 0), and only for the NEW diagnosis, so
        // the cap does not mask a recurrence of the old ones.
        static std::atomic<uint32_t> s_nogeom{0};
        const uint32_t n = s_nogeom.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 200) == 0) {
            MCLA_LOG_WARN("CAPTURE-NO-GEOM #{} flags={:06X} streams={} "
                          "indexCount={} vbPtr-is-zero={} - submission names no "
                          "geometry, so it cannot be drawn (was counted valid)",
                          n, flags, packet.vertexStreamCount, packet.indexCount,
                          packet.vertexStreams[0].guestAddress == 0 ? 1 : 0);
        }
    }

    packet.validationFlags = flags;
    return valid;
}

} // namespace mcla::native

// ---------------------------------------------------------------------------
// Capture hook for the guest render-state setter sub_82413950. PPC_FUNC here is
// a strong definition overriding the recompiled weak symbol, and it still calls
// the original afterwards - a pass-through capture, not a short-circuit.
// The hook logs a rate-limited CAPTURE-SET_RS line (first 20 firings, then every
// 2000th) and enqueues a SET_RENDER_STATE command on g_commandQueue; the render
// thread's SET_RENDER_STATE handler currently only logs the command, so this
// path issues no D3D12 calls.
// Signature: func(r3=device, r4=renderStateValue)
// ---------------------------------------------------------------------------

#include "render_queue.h"
#include "kernel/memory.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include <cpu/ppc_context.h>

PPC_FUNC_IMPL(__imp__sub_82413950);
static std::atomic<uint32_t> s_hSetRS{0};

PPC_FUNC(sub_82413950)
{
    const uint32_t n = s_hSetRS.fetch_add(1) + 1;
    const uint32_t dev = ctx.r3.u32;
    const uint32_t value = ctx.r4.u32;

    if (n <= 20 || (n % 2000) == 0)
        MCLA_LOG_INFO("CAPTURE-SET_RS sub_82413950 #{} dev={:08X} value={:08X}", n, dev, value);

    mcla::native::RenderCommand cmd;
    cmd.type = mcla::native::RenderCommand::SET_RENDER_STATE;
    cmd.data = mcla::native::SetRenderStateCommand{ dev, value };
    mcla::native::g_commandQueue.push(cmd);

    __imp__sub_82413950(ctx, base);
}
