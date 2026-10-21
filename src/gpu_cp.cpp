#include "gpu_cp.h"

#include "render_queue.h"
#include <windows.h>
#include <dbghelp.h>

#include "boot_host.h"  // F-680: TranslatePhysViewToPoolVa - the ONE view->pool rule
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "guest_memory.h"
#include "kernel/heap_arena.h"  // F-412: kPhysArenaBeginVa, so this probe follows the pool
#include "kernel/memory.h"
#include "logging.h"
// F-818: defined in src/kernel/imports.cpp beside the registration it reads
// (VdSetGraphicsInterruptCallback's file-scope atomics). Declared here rather
// than in a header because gpu_cp.cpp is its only caller.
void VdDispatchGraphicsInterrupt(uint32_t cpuMask);
#include <cpu/ppc_context.h>


#include <atomic>
#include <chrono>  // F-651(3): the PM4_WAIT_REG_MEM spin budget (steady_clock)
#include <cstdio>  // F-647: std::snprintf into the CP-REGS-EXPORT fixed buffer
#include <cstdlib>
#include <cstring>  // F-632: std::strcmp on the refusal-reason literals
#include <intrin.h>  // F-784: _ReturnAddress() for the T44 wipe-watch host attribution
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_set>
#include <vector>

namespace mcla::gpu {

namespace {

// XGPU register window (Xenia: GraphicsSystem::Initialize maps phys
// 0x7FC80000..0x7FC8FFFF, register index = offset/4).
constexpr uint32_t kMmioBase = 0x7FC80000u;
constexpr uint32_t kMmioSize = 0x00010000u;
constexpr uint32_t kMmioMask = 0xFFFF0000u;

// CP_RB_WPTR: the ring doorbell. Guest stores the new write-pointer dword
// index here (verified guest site: ppc_recomp.75.cpp:15012-15015, sub_82411928's
// PPC_MM_STORE_U32(0x7FC80000 + 1812) - the sole doorbell-ringer module-wide).
constexpr uint32_t kWptrByteOffset = 0x01C5u * 4u; // 0x714

// Xenia treats this value as "no doorbell rung yet".
constexpr uint32_t kWptrSentinel = 0xBAADF00Du;

// Register-file shadow over the 64 KB MMIO window (xenia persists writes and
// serves unhandled reads from it, graphics_system.cc:207-223).
constexpr size_t kMmioRegCount = kMmioSize / 4u;
std::atomic<uint32_t> g_regShadow[kMmioRegCount]{};

// ---------------------------------------------------------------------------
// T40.6 step 3 - the Xenos register file. A Type-0 packet used to be logged
// and its payload dwords thrown away, and there was no handler at all for
// 0x21 PM4_REG_RMW / 0x2B PM4_IM_LOAD_IMMEDIATE, so no draw could ever be
// parameterised from state. Indices aliasing the MMIO shadow are mirrored so
// guest read-back still agrees.
// ---------------------------------------------------------------------------
// Xenos register indices: the base index we poke comes off a TYPE-0 header
// masked with `packet & 0x7FFF` (15 bits, command_processor.cc:651) and the
// COUNT field with `0x3FFF` (:641). We used to mask the BASE with 0x3FFF too,
// which made every register at 0x4000+ unreachable through TYPE-0 while it
// stayed reachable through SET_CONSTANT2 (0x55, raw 16-bit index) - an
// inconsistency, not a narrower hardware field. F-610: base is 15 bits.
// (F-090, still true: the file used to be 0x2000 wide while CpRegPoke returned
// BEFORE bumping g_xenosRegWrites, so writes aimed at 0x2000..0x3FFF vanished.
// Measured in w42a.log: bases 0x200D, 0x2080, 0x2100, 0x2104, 0x2180, 0x2200,
// 0x2203, 0x2204, 0x2208, 0x2280, 0x2293, 0x2302, 0x2312 - the whole
// RB_/PA_/VGT_/SQ_PROGRAM_CNTL block, i.e. all 3D state.)
// PM4_REG_RMW's index field is 13-bit (upstream masks 0x1FFF at
// command_processor.cc:1050-1065 - we match it). The file itself is
// 0x5003 dwords wide upstream (register_file.h:40 `kRegisterCount`).
constexpr uint32_t kXenosRegCount = 0x5003u;

// F-610: base-register field width of a TYPE-0 header (command_processor.cc:651)
// and the TYPE-0 payload cap. The cap is NOT upstream - Xenia writes all
// `count` payload dwords (count is a 14-bit field, so up to 16384). Ours is
// retained only to bound the per-packet poke loop, and it is now LOUD: every
// packet that hits it prints CP-T0-CAP naming the op and the dropped count, so
// a soak can prove it never fires on real traffic. Zero occurrences of
// CP-T0-CAP in a soak is the evidence; silence is not.
constexpr uint32_t kType0BaseMask = 0x7FFFu;
constexpr uint32_t kType0PayloadCap = 0x40u;

// Register indices for the WriteRegister side effects below, verbatim from
// xenia src/xenia/gpu/register_table.inc (the XE_GPU_REG_* enum is generated
// from it; no other source carries these numbers).
constexpr uint32_t kRegScratchUmsk = 0x01DCu;        // register_table.inc:40
constexpr uint32_t kRegScratchAddr = 0x01DDu;        // register_table.inc:39
constexpr uint32_t kRegScratchReg0 = 0x0578u;        // register_table.inc:56
constexpr uint32_t kRegScratchReg7 = 0x057Fu;        // register_table.inc:63
constexpr uint32_t kRegCoherStatusHost = 0x0A31u;    // register_table.inc:91
// registers.h:88 COHER_STATUS_HOST.status is bit 31. Declared here, beside the
// register index, because CpRegPoke needs it and is defined far above the
// PM4_WAIT_REG_MEM block that also needs it.
constexpr uint32_t kCoherStatusBit = 0x80000000u;
constexpr uint32_t kRegDcLutRwIndex = 0x1922u;       // register_table.inc:433
constexpr uint32_t kRegDcLutSeqColor = 0x1923u;      // register_table.inc:440
constexpr uint32_t kRegDcLutPwlData = 0x1924u;       // register_table.inc:448
constexpr uint32_t kRegDcLut30Color = 0x1925u;       // register_table.inc:452
constexpr uint32_t kRegDcLutWriteEnMask = 0x1927u;   // register_table.inc:461
constexpr uint32_t kRegDcLutLast = kRegDcLutWriteEnMask;

// F-611: the fetch/VB constant block. PM4_SET_CONSTANT type 1 writes
// index+0x4800 (CpExecSetConstant, `case 1: index += 0x4800u`; upstream
// command_processor.cc:1428-1475), and register_table.inc:2697-2888 names that
// window SHADER_CONSTANT_FETCH_00_0 .. SHADER_CONSTANT_FETCH_31_5 - 192 dwords,
// 6 per fetch slot, 32 slots. It is the block that carries the vertex-buffer
// descriptors for a draw.
//
// It is worth being precise about WHY the block is not a list of vertex buffer
// addresses this CP can read: on the Xenos the descriptors are COMPUTED by the
// fetch-shader PROGRAM (SQ_PROGRAM_CNTL, register 0x2180, selects it) out of
// these constants - the registers hold fetch instructions, not addresses. So no
// amount of peeking here yields a VB VA until that program is executed, and
// until then the honest answer to "where is the vertex data" is a refusal, not
// a scan. g_fetchVbWrites is the cheap boolean that replaces the seven
// fixed-index peek the CP-DRAW-STATE line used to do (F-115a: "peeking seven
// fixed ids was not enough to find it"): it watches the whole 192-dword block
// for the price of one compare per poke.
constexpr uint32_t kRegFetchVbFirst = 0x4800u;
constexpr uint32_t kRegFetchVbLast = 0x48C0u; // exclusive

// F-610 census counters. Every one is a soak-visible zero/nonzero gate; see the
// marker names at each site.
std::atomic<uint32_t> g_scratchWritebacks{0};
std::atomic<uint32_t> g_coherDirty{0};
std::atomic<uint32_t> g_gammaLutWrites{0};
std::atomic<uint32_t> g_type0CapHits{0};
std::atomic<uint32_t> g_type0WriteOne{0};
std::atomic<uint32_t> g_type0OutOfFile{0};
std::atomic<uint32_t> g_setConstCapHits{0};
std::atomic<uint32_t> g_memWritePackets{0};
std::atomic<uint32_t> g_memWriteDwords{0};
std::atomic<uint32_t> g_memWritePayloadMiss{0};
// F-XXX: PM4_COND_WRITE (0x45) census. NEW SYMBOLS, listed for rule 1b:
//   g_condWriteSeen        - packets decoded (the body was readable)
//   g_condWriteMatched     - the predicate evaluated TRUE
//   g_condWriteNotMatched  - the predicate evaluated FALSE (nothing written)
//   g_condWriteRegWritten  - a REGISTER write landed (CpRegPoke)
//   g_condWriteMemWritten  - a MEMORY write landed
//   g_condWriteShortBody   - the packet had fewer than the six body dwords
//   g_condWriteUnreadable  - a body dword could not be read
//   g_condWritePollRefused - the POLL target could not be evaluated at all
//   g_condWriteRegRefused  - the WRITE target was a register index outside the
//                            0x5003-dword file (the reference logs and returns)
//   g_condWriteMemRefused  - the WRITE target was a physical address with no
//                            pool byte in this tree
std::atomic<uint32_t> g_condWriteSeen{0};
std::atomic<uint32_t> g_condWriteMatched{0};
std::atomic<uint32_t> g_condWriteNotMatched{0};
std::atomic<uint32_t> g_condWriteRegWritten{0};
std::atomic<uint32_t> g_condWriteMemWritten{0};
std::atomic<uint32_t> g_condWriteShortBody{0};
std::atomic<uint32_t> g_condWriteUnreadable{0};
std::atomic<uint32_t> g_condWritePollRefused{0};
std::atomic<uint32_t> g_condWriteRegRefused{0};
std::atomic<uint32_t> g_condWriteMemRefused{0};
std::atomic<uint32_t> g_xenosReg[kXenosRegCount]{};
// F-647: the "was this register EVER WRITTEN" bit, one per register. The value
// array above cannot answer that question: g_xenosReg[i] is 0 both before the
// first poke and after a poke of the literal 0, and those are different facts.
// F-646's consumer (renderer::PipelineStateInputs::registersPresent,
// renderer/pipeline_cache.h:113) is built entirely on that distinction --
// DecodeGuestRenderState refuses kRefuseNoPaClipCntl when the BIT is clear, so
// a producer that hands over a value without the bit makes an unwritten
// register decode as a legal zero (PA_SU_SC_MODE_CNTL=0 is a real, DIFFERENT
// rasteriser: solid triangles, both faces, CCW).
//
// One bit per index, stored as atomic words so a concurrent reader can never
// see a torn word, and set AFTER the value store (release) so a reader that
// sees the bit is guaranteed to see the value. See CpReadGuestRegisters.
constexpr uint32_t kXenosRegPresentWords = (kXenosRegCount + 31u) / 32u;
std::atomic<uint32_t> g_xenosRegPresent[kXenosRegPresentWords]{};
std::atomic<uint32_t> g_xenosRegWrites{0};
// Accepted pokes at index >= the old 0x2000 bound: non-zero is the proof the
// widen took effect (F-090).
std::atomic<uint32_t> g_xenosRegHiWrites{0};
// F-611: accepted pokes landing in the fetch/VB constant block 0x4800..0x48BF.
// MEASURED ZERO in build/w654.log - and so are PM4_SET_CONSTANT (0x2D) and
// PM4_SET_CONSTANT2 (0x55) themselves, which are the only packets that write
// it. This counter is the binary the next step is gated on: the first non-zero
// value means the guest has begun describing vertex buffers, and the vertex
// descriptor decode becomes a live problem rather than a hypothetical one.
std::atomic<uint32_t> g_fetchVbWrites{0};

// F-611: the CP draw bridge's refusal census. One counter per named reason, so
// a soak says WHICH piece is missing instead of only that something was. Every
// one is reported by the bounded CP-DRAW-REFUSE line in CpBridgeDraw.
std::atomic<uint32_t> g_bridgeNoIndexBuffer{0};  // source_select != kDMA
std::atomic<uint32_t> g_bridgeEmptyIndex{0};     // kDMA, but num_words == 0
std::atomic<uint32_t> g_bridgeIndexWrap{0};      // base + bytes leaves 4 GiB
std::atomic<uint32_t> g_bridgeIndexUnreadable{0};// not in the guest window
std::atomic<uint32_t> g_bridgeNoVbDesc{0};       // fetch/VB block never written
std::atomic<uint32_t> g_bridgeEnqueued{0};       // reached the render thread
// F-612: the three refusal reasons that F-611 had no counter for, so a draw
// could not say WHICH piece of the pipeline was missing. Each is its own row
// in the same bounded CP-DRAW-REFUSE census, and each is a distinct question:
//   no-vertex-fetch-const - the block WAS written, but no slot decodes to
//       FetchConstantType::kVertex, so the writes were texture/loop constants
//       landing in the same window, not a vertex stream.
//   microcode-absent - a kVertex slot EXISTS, but no PM4_IM_LOAD has ever
//       delivered a vertex program, so the per-attribute binding is unknown.
//   microcode-unsupported - F-612 row, now STRUCTURALLY ZERO and kept only so
//       the counter stays greppable. F-632 decodes the packet that carries
//       stride/format/swizzle (it was never absent, only mis-pathed), and the
//       live rows are the two below.
//   vfetch-none - a kVertex slot exists, microcode was captured and walked, but
//       the program executes no ucode::FetchOpcode::kVertexFetch.
//   vfetch-unreadable - it DOES execute one, but its fetch-constant slot did
//       not resolve to FetchConstantType::kVertex in the 0x4800 block.
std::atomic<uint32_t> g_bridgeNoVbFetchConst{0}; // block written, 0 kVertex slots
std::atomic<uint32_t> g_bridgeNoMicrocode{0};    // kVertex slot, 0 vertex programs
std::atomic<uint32_t> g_bridgeMicrocodeUnsup{0}; // decoded as far as this tree allows

// ---------------------------------------------------------------------------
// F-612: the microcode PM4_IM_LOAD (0x27) carries, and the vertex descriptor
// the fetch/VB constant block (0x4800..0x48BF) actually holds.
//
// WHAT PM4_IM_LOAD CARRIES - established from the reference, not assumed.
// command_processor.cc:1528-1557 ExecutePacketType3_IM_LOAD reads exactly two
// argument dwords and then a guest-addressed block:
//   addr_type  = ReadAndSwap<uint32>();  (:1534)
//   shader_type= addr_type & 0x3;        (:1535)  ShaderType kVertex=0/kPixel=1
//   addr       = addr_type & ~0x3;       (:1536)  a GUEST ADDRESS
//   start_size = ReadAndSwap<uint32>();  (:1537)
//   start      = start_size >> 16;       (:1538)  upstream asserts start==0
//   size_dwords= start_size & 0xFFFF;    (:1539)  LENGTH, in dwords
//   LoadShader(shader_type, addr, TranslatePhysical(addr), size_dwords) (:1543)
// So it is a POINTER, not register state and not a body embedded in the packet.
// (0x2B PM4_IM_LOAD_IMMEDIATE, command_processor.cc:1559-1590, is the embedded
// variant: dword0 = shader_type, dword1 = start_size, then size_dwords
// in-packet dwords at read_ptr. That one is decoded below too.)
//
// It is NOT a header we parse and throw the body away from. LoadShader
// (pipeline_cache.cc:842-866) takes a raw host pointer plus a dword count and
// hashes the whole thing; the register count comes from SQ_PROGRAM_CNTL
// .vs_num_reg / .ps_num_reg (registers.h:127-150, used pipeline_cache.cc:879
// and :913), never from a header inside the program. So the previous behaviour
// threw away the WHOLE program, header or not - that is the hole, and this is
// the fix: capture it and keep it.
//
// WHERE THE PROGRAM LIVES: `size_dwords` dwords at guest address `addr`. It is
// a physical address upstream (TranslatePhysical); in this flat guest window the
// physical form resolves through CpPhysToPoolVa (F-680) and BOTH that pool byte
// and the raw physical value are probed, and the one that is actually readable
// is reported - measured, not assumed.
// The microcode is stored in the guest's own big-endian words, so every dword
// read here is ReadU32BE. (Whether the Xenos expects those words byte-swapped
// on load is NOT settled by this file and is not relied on anywhere below -
// no instruction field is decoded, so the question cannot change a result.)
//
// WHAT THE FETCH SHADER IS - and the premise correction. The brief asserts the
// fetch shader is a register-packet stream. What this checkout supports:
//   * xenos.h:28-29 "the microcode consists of triples of 32-bit words" -
//     confirmed, and shader_interpreter.cc:96 indexes it as &ucode_[3 * n].
//   * A control-flow packet's `sequence()` bit selects, per executed
//     instruction, a FETCH packet (shader_interpreter.cc:97-105) or an ALU
//     packet (:115), and the fetch packet is dispatched on
//     `ucode::FetchOpcode::kVertexFetch` (:105).
//   * There is NO separate fetch-shader program in this reference. The
//     vertex-fetch instructions live INSIDE the vertex program that
//     PM4_IM_LOAD(type=0) loads; Xenia runs that program on the host
//     (shader_interpreter.cc) rather than modelling a fetch unit. The
//     address-in-registers formula the brief asks for is
//     shader_interpreter.cc:1013-1014:
//        vfetch_address_dwords = instr.stride() * vertex_index + fetch.address
//     with the read bounds [fetch.address, fetch.address + fetch.size)
//     (:1033,:1042) and the endian swap at :1048.
//   * THE SEAM: stride(), offset(), data_format() and dest_swizzle() live in
//     ucode::VertexFetchInstruction, declared in xenia/base/ucode/ucode.h.
//     That directory is NOT in this checkout
//     (.research/xenia/src/xenia/base/ucode does not exist - re-checked 09-28;
//     .gitmodules lists only third_party/*), so their bit positions cannot be
//     read here. Guessing them would be exactly the fabricated layout the
//     charter (F-609) forbids, so CpNoteMicrocodeUnsupported refuses BY NAME.
//     Everything upstream of the seam IS implemented below.
//
// F-612 census counters. Every one is a soak-visible zero/nonzero gate.
std::atomic<uint32_t> g_imLoadVertex{0};      // type 0, program CAPTURED
std::atomic<uint32_t> g_imLoadPixel{0};       // type 1, program CAPTURED
std::atomic<uint32_t> g_imLoadImmediate{0};   // 0x2B, program captured in-packet
std::atomic<uint32_t> g_imLoadBadType{0};     // shader_type > 1 (upstream: return false)
std::atomic<uint32_t> g_imLoadUnreadable{0};  // no readable form of `addr`
std::atomic<uint32_t> g_imLoadZeroSize{0};    // size_dwords == 0
std::atomic<uint32_t> g_imLoadStartSet{0};    // start != 0 (upstream asserts)
std::atomic<uint32_t> g_imLoadTruncated{0};   // size_dwords > capture window
std::atomic<uint32_t> g_imLoadDwords{0};      // total microcode dwords captured
std::atomic<uint32_t> g_microcodeUnsup{0};    // the kVertexFetch seam refusals
std::atomic<uint32_t> g_fetchVbSlots{0};      // slots decoding to FetchConstantType::kVertex
std::atomic<uint32_t> g_fetchVbDecoded{0};    // successful descriptor decodes
std::atomic<uint32_t> g_fetchVbNoVertex{0};   // block written, 0 kVertex slots
std::atomic<uint32_t> g_fetchVbUndecodable{0};// kVertex slot whose range is outside guest
std::atomic<uint32_t> g_t3Unhandled{0};       // ALL unhandled Type-3 packets
// F-651: the 0x3E / 0x3C / 0x58 counter set. Attempts and successes are
// SEPARATE counters on purpose (a "handled" total that mixes them cannot say
// whether a refusal grew), and each opcode's refusals have their own reason
// counter. All of them print on the CP-DRAW-CENSUS row below.
std::atomic<uint32_t> g_r2mSeen{0};        // 0x3E PM4_REG_TO_MEM executed
std::atomic<uint32_t> g_r2mWritten{0};     //   ...stores actually issued
std::atomic<uint32_t> g_r2mSame{0};        //   ...destination already held it
std::atomic<uint32_t> g_r2mRefusedReg{0};  //   reg index outside the 0x5003 file
std::atomic<uint32_t> g_r2mUnreadable{0};  //   packet body or destination unreadable
std::atomic<uint32_t> g_waitRegMemSeen{0}; // 0x3C PM4_WAIT_REG_MEM ISSUED (was: refused)
std::atomic<uint32_t> g_waitRegMemReg{0};  //   ...the wait targets a REGISTER
std::atomic<uint32_t> g_waitRegMemMem{0};  //   ...the wait targets guest MEMORY
// F-651(3) supersedes the REFUSAL above. The wait is now EXECUTED against the
// same register file / guest memory the guest itself wrote, and the four
// outcomes the brief demands a soak be able to separate are four SEPARATE
// counters, because "issued" alone cannot tell a fence that passed from a fence
// that was given up on. A timed-out wait is NEVER counted as satisfied and the
// packet stream is PARKED (rptr not advanced) - see CpExecWaitRegMem.
std::atomic<uint32_t> g_waitRegMemSat{0};     // predicate held -> returned true
std::atomic<uint32_t> g_waitRegMemSatSpin{0}; //   ...only after >=1 yield/sleep
std::atomic<uint32_t> g_waitRegMemTimeout{0}; // budget expired -> PARKED, not advanced
std::atomic<uint32_t> g_waitRegMemNeverWritten{0}; // timed out AND no writer exists
// timed out AND a writer DID store to this byte, but the stored value does not
// satisfy the predicate. This is a THIRD outcome, distinct from both a satisfied
// wait and g_waitRegMemNeverWritten, and it is the one w700.log's freeze is: see
// CP-WAITREG-WRITER-MISMATCH and the address-space note at the CpMemWriteDestSeen
// call in CpExecWaitRegMem.
std::atomic<uint32_t> g_waitRegMemWriterMismatch{0};
// 0x54 PM4_INTERRUPT packets DECODED (see kPm4Interrupt for the measurement and
// for why the dispatch is refused). Counted per packet, unbounded - it is the
// exact number of interrupts this host has read and deliberately not honoured,
// which is a statement about the stream and not about any effect.
std::atomic<uint32_t> g_interruptSeen{0};
std::atomic<uint32_t> g_waitRegMemUnmatchable{0};  // wait_info&7 == 0 (kNever)
std::atomic<uint32_t> g_waitRegMemUnreadable{0};   // body or poll target unreadable
std::atomic<uint32_t> g_waitRegMemEndianSwap{0};   // memory poll whose value was byte-swapped
// F-680: a memory-form poll target with no pool byte in this tree. Its own
// counter because it is a DIFFERENT failure from g_waitRegMemUnreadable - the
// address resolved fine, there is simply no byte behind it - and folding the two
// would make "the guest asked for memory this tree does not have" read as "a
// read failed".
std::atomic<uint32_t> g_waitRegMemNoPoolByte{0};
std::atomic<uint32_t> g_waitRegMemSpins{0};        // total poll iterations across all waits
std::atomic<uint64_t> g_waitRegMemWaitedMs{0};     // total time spent inside waits
// MakeCoherent (command_processor.cc:486-524). The ONLY thing the reference
// does is clear COHER_STATUS_HOST.status; :518 is a TODO for the resource
// cache, i.e. upstream has no flush either. `Cleared` = the dirty bit was set
// and we zeroed it; `Noop` = it was already clear and the reference returns at
// :505-507 without touching anything.
std::atomic<uint32_t> g_coherentCleared{0};
std::atomic<uint32_t> g_coherentNoop{0};
// Set by CpExecWaitRegMem when it gives up, cleared by each walker before it
// calls the decoder. A walker that sees it set does NOT advance its cursor:
// that is the park, and it is what makes "wait timed out" distinguishable from
// "wait satisfied" in the cursor as well as in the counters.
std::atomic<uint32_t> g_waitRegMemParkPending{0};
std::atomic<uint32_t> g_waitRegMemParked{0};
// "Has any implemented writer ever stored to this guest byte address?" - a
// 256-entry most-recent-destination ring fed by every store this file issues
// (PM4_MEM_WRITE, PM4_REG_TO_MEM, PM4_EVENT_WRITE_SHD, scratch writeback).
// A miss means "not among the last 256 distinct destinations", which is a
// statement about the TABLE, not proof the guest has no writer; the rows that
// use it say so in words.
constexpr uint32_t kMemWriteDestSlots = 256u;
std::atomic<uint32_t> g_memWriteDest[kMemWriteDestSlots]{};
std::atomic<uint32_t> g_memWriteDestNext{0};
std::atomic<uint64_t> g_memWriteDestStores{0};
// Ring-walk opcode census. opCount[128] in DrainIndirectBuffer covers the
// INDIRECT path only, and MEASURED (build/w677.log) 3040/3040 of its rows carry
// t3=0 with walked == 2*t0 - the signature of an all-zero buffer - so it can
// never see a Type-3 packet. The ring is where the guest actually submits, and
// it had NO per-opcode census at all. This is that census.
std::atomic<uint32_t> g_ringOpCount[128]{};
std::atomic<uint64_t> g_ringDrainWalks{0};
std::atomic<uint64_t> g_ringT3Total{0};
std::atomic<uint64_t> g_ringT3Delegated{0};
std::atomic<uint64_t> g_ringT3WrapRefused{0};
// Defined with the PM4_WAIT_REG_MEM block, far below; used by the three store
// sites that feed it (PM4_REG_TO_MEM, PM4_EVENT_WRITE_SHD, PM4_MEM_WRITE).
void CpNoteMemWriteDest(uint32_t byteAddr);
// F-746: the SAME ring, plus the VALUE each store published. g_memWriteDest
// answers "did any implemented writer touch this byte", which is all
// CP-WAITREG-WRITER-MISMATCH can say; on its own that row cannot separate "a
// writer fired and left the wrong number" from "nothing this host implements
// can ever leave the wanted number here", and those two want opposite next
// steps. The value ring is a PURE ADDITION with its own index counter and its
// own store counter: g_memWriteDest / g_memWriteDestNext / g_memWriteDestStores
// are untouched, because they are printed by tracked markers
// (CP-WAITREG-WRITER-MISMATCH's `stores=`, CP-SCRATCH-WB-ADDR's trailing
// `stores=`) whose formats must not move.
constexpr uint32_t kMemWriteValSlots = 256u;
std::atomic<uint32_t> g_memWriteValDest[kMemWriteValSlots]{};
std::atomic<uint32_t> g_memWriteValWord[kMemWriteValSlots]{};
std::atomic<uint32_t> g_memWriteValNext{0};
std::atomic<uint64_t> g_memWriteValStores{0};
void CpNoteMemWriteValue(uint32_t byteAddr, uint32_t value);
uint32_t CpMemWriteValuesSeen(uint32_t byteAddr, uint32_t *out, uint32_t maxOut);
std::atomic<uint32_t> g_waitRegMemWriterValues{0};  // CP-WAITREG-WRITER-VALUES
std::atomic<uint32_t> g_waitRegMemPktBytes{0};     // CP-WAITREG-PKTBYTES
std::atomic<uint32_t> g_shdSeen{0};        // 0x58 PM4_EVENT_WRITE_SHD executed
std::atomic<uint32_t> g_shdWritten{0};     //   ...literal-value form stored
std::atomic<uint32_t> g_shdNoCounter{0};   //   ...counter form refused (no counter)
std::atomic<uint32_t> g_shdUnreadable{0};  //   ...body or destination refused
// 0x46 PM4_EVENT_WRITE. Kept SEPARATE from the 0x58 counters on purpose: 0x46
// and 0x58 are different packets with different arities, and the whole point of
// the 0x46 pair is that it has NO memory-write counter to report.
std::atomic<uint32_t> g_ewSeen{0};          // 0x46 PM4_EVENT_WRITE executed
std::atomic<uint32_t> g_ewPoked{0};         //   ...count==1 register poke issued
std::atomic<uint32_t> g_ewRefusedMulti{0};  //   ...count>1 refused (no such layout)
std::atomic<uint32_t> g_ewUnreadable{0};    //   ...operand dword unreadable
// F-632: the two bridge gate rows that replaced F-612's single
// what=microcode-unsupported. Kept APART because the fixes differ: no
// vfetch in the program is a program/walk question, an unresolvable slot is a
// register-block question.
std::atomic<uint32_t> g_bridgeVfetchNone{0};        // no kVertexFetch executed
std::atomic<uint32_t> g_bridgeVfetchUnreadable{0};  // found, slot unresolvable
// F-632: the microcode-program census. The two refusal reasons are kept APART
// because they have different fixes: no-instruction means the walk is wrong or
// the program is not a vertex program; unreadable means the walk found the
// instruction but could not resolve it to a fetch-constant slot.
std::atomic<uint32_t> g_vfetchNone{0};        // program walked, 0 kVertexFetch found
std::atomic<uint32_t> g_vfetchUnreadable{0};  // kVertexFetch found, fields unresolvable
std::atomic<uint32_t> g_vfetchFound{0};       // kVertexFetch instructions decoded
std::atomic<uint32_t> g_vfetchDecoded{0};     // full descriptors (stride+format) built
std::atomic<uint32_t> g_vfetchTrunc{0};       // exec address outside the capture window
std::atomic<uint32_t> g_vfetchStride0{0};     // decoded, but stride() == 0 dwords
std::atomic<uint32_t> g_vfetchBadFmt{0};      // 6-bit format is not in xenos.h:602-619

// One decoded SHADER_CONSTANT_FETCH vertex slot - the real, non-fabricated
// part of the vertex descriptor. Layout is upstream's, verbatim
// (xenos.h:1113-1127, read through register_file.h:59-67 GetVertexFetch, which
// memcpy's 2 dwords from register 0x4800 + 2*index and asserts index < 96):
//   dword_0 = { type : 2, address : 30 }   address in DWORDS
//   dword_1 = { endian : 2, size : 24 }    size in WORDS
// 32 six-dword groups of 3 such slots = 96 slots, 192 dwords,
// register_table.inc:2697-2888 (SHADER_CONSTANT_FETCH_00_0 .. _31_5).
// `address`/`size` scaling is upstream's own arithmetic, not ours:
// d3d12_command_processor.cc:2231-2232 requests
//   RequestRange(vfetch_constant.address << 2, vfetch_constant.size << 2)
// and draw_util.cc:837-840 reads at fetch.address * sizeof(uint32_t).
struct CpVertexFetchSlot {
  uint32_t index = 0;      // fetch-constant slot [0,95]
  uint32_t type = 0;       // FetchConstantType (xenos.h:1102-1107)
  uint32_t address = 0;    // dwords
  uint32_t sizeWords = 0;  // words
  uint32_t endian = 0;     // 2 bits
  uint32_t physBase = 0;   // address << 2
  uint32_t vaBase = 0;     // F-680: CpPhysToPoolVa(physBase), the pool byte
  uint64_t sizeBytes = 0;  // sizeWords << 2
};

std::atomic<uint32_t> g_microcodeHave{0};   // bit0 = vertex, bit1 = pixel

// F-612: the draw bridge may only enqueue geometry when the WHOLE descriptor is
// known. Base, length and endian are decoded (CpDecodeVertexFetchSlots).
// F-632: stride, format, offset and swizzle are now decoded too, from the
// captured program, by CpDecodeVertexDescriptor below, using the real
// ucode::VertexFetchInstruction layout read out of
// .research/xenia/src/xenia/gpu/ucode.h. Every field below is cited to a line
// in that header. This is a named constant, not a deleted block, so the removal
// trigger stays greppable: it flips on a MEASURED decode, never to turn a soak
// green.
constexpr bool kCpVertexDescriptorComplete = true;

// The captured program, kept - this is what F-612 was asked to stop throwing
// away. Two images (vertex, pixel) because upstream keys active_vertex_shader_
// and active_pixel_shader_ separately (command_processor.cc:1545-1555).
constexpr uint32_t kMicrocodeCaptureDwords = 1024u;
struct CpMicrocodeImage {
  uint32_t present = 0;   // 0 = never loaded
  uint32_t type = 0;      // ShaderType (xenos.h:33-36)
  uint32_t srcPhys = 0;   // the address the PM4_IM_LOAD carried
  uint32_t srcVA = 0;     // the form that was actually readable
  uint32_t vaIsKernel = 0;// 1 = srcVA == CpPhysToPoolVa(srcPhys), the pool byte
  uint32_t totalDwords = 0;  // size_dwords from the header (may exceed the capture)
  uint32_t captured = 0;     // dwords actually retained
  // F-652: 1 = PM4_IM_LOAD_IMMEDIATE (0x2B, command_processor.cc:1559-1590), so
  // the body was INSIDE the packet and srcPhys is 0. This has to be its own
  // field because `srcPhys == 0` CANNOT be the discriminator: a pointer-based
  // PM4_IM_LOAD whose addr_type is exactly 0 names guest address 0 with stage
  // kVertex (addr = addr_type & ~0x3, :1536), which is a legal - and in this
  // flat window, readable - program address. Deriving "embedded" from a zero
  // address would mislabel it and would reintroduce exactly the plausible-but-
  // wrong shader this struct exists to prevent.
  uint32_t embedded = 0;
  uint32_t dwords[kMicrocodeCaptureDwords]{};
};
std::mutex g_microcodeMutex;
CpMicrocodeImage g_microcode[2]{}; // [0] = kVertex, [1] = kPixel

// F-694: what the LAST CpSnapshotDrawState call actually put in each stage's
// CpShaderProgram::body, so the draw-path row can report the SHIPPED length
// instead of the DECLARED one. The numbers are three different questions:
//   dwords    - dwords written into body[] on the last copy. This is the number
//               that proves the bytes crossed, and the only one a translator
//               may act on. It is written for the ABSENT stage too, as 0, so a
//               stage that never loaded is distinguishable on the row from one
//               that loaded an empty program.
//   cap       - kCpShaderBodyDwords, named on the row so a reader does not have
//               to find the header to know what dwords is bounded BY.
//   truncated - CUMULATIVE count of copies where img.captured > cap, i.e. the
//               program did not fit. Falsifier for the cap: any non-zero value
//               means kCpShaderBodyDwords is refusing a real program and must be
//               RAISED. Never to be "fixed" by relaxing the consumer's check.
// `embedded` counts copies of a PM4_IM_LOAD_IMMEDIATE body, because for the
// pointer form (0x27) the bytes are in guest memory at guestAddr and body[] is
// legitimately all zeroes - a zero body is not a failed copy.
struct CpShipBodyStage {
  uint32_t dwords = 0;     // shipped on the last copy
  uint32_t cap = 0;        // the bound it was clamped to
  uint32_t truncated = 0;  // cumulative count of copies that did not fit
  uint32_t embedded = 0;   // cumulative count of 0x2B (body-in-packet) copies
};
// Written only by the CP thread inside CpSnapshotDrawState, under
// g_microcodeMutex; read only by the CP thread immediately after, in the same
// call's caller. No atomic and no second lock: it is per-draw scratch that
// never outlives the statement pair, and a reader on another thread would be
// reading a value that is already stale by construction (the next draw
// overwrites it) - which is why nothing outside this file may consult it.
static CpShipBodyStage s_shipBody[2]{};

// Defined below, next to the other address helpers; declared here because
// CpExecImLoad and the fetch-constant decoder both need it and both sit above
// the definition.
inline uint32_t PhysToKernelVA(uint32_t addr);

// ---------------------------------------------------------------------------
// F-680: THE ONE TRANSLATION RULE. `pa | 0xC0000000` was a GUESS at the inverse
// of the guest's EA->PA transform, and in this tree it is wrong in the one
// direction that fails silently: it returns an address nobody wrote, so the CP
// reads ZEROS instead of raising.
//
// MEASURED, all three links, and none of them inferred:
//
//  1. THE GUEST'S OWN INVERSE IS THE A VIEW, NOT THE C VIEW. Decompiled guest
//     sub_824199B0 (tools/ida_dump.py, 0x82419A10; the PM4_WAIT_REG_MEM builder,
//     `*v5++ = -1073464320` = 0xC0043C00 at 0x82419B2C and `*v5++ = 1401` at
//     0x82419A1C) computes its memory-form poll target as
//         ((((*(DWORD*)(a1+10900) + 4) >> 20) + 512) & 0x1000)
//         + ((*(DWORD*)(a1+10900) + 4) & 0x1FFFFFFF) | 2;
//     `x & 0x1FFFFFFF` strips exactly the three high bits that distinguish the
//     A view (0xA0000000 = 1010b) from the rest of the window, so for any
//     window VA `v` the guest's EA->PA is `v & 0x1FFFFFFF` and its inverse is
//     `pa | 0xA0000000`. Same 0x13 wait_info (= mem form, cmp=eq), same
//     `v5[3]=1 / v5[4]=-1 / *v5=256` tail, as the captured packets.
//
//  2. THE A VIEW *IS* THE POOL, AND THE C VIEW IS NOT. boot_host.cpp's own
//     alias probe, MEASURED in build/w679.log:50 (once per boot, before any
//     guest thread exists):
//         F640-PHYSALIAS phase=init mech=PARTIAL(alias-broken)
//         canary_shared_views=1/3 probe_pa=10400000 probe_pool_va=B0400000
//     1 of 3 views shares the pool byte. boot_host.cpp:3909-3916 derives the
//     mechanism off that count: 3 would mean view-alias(MAPPED), 0 would mean
//     flat-window, and 1 is the PARTIAL case the file names rather than rounds
//     off - and 1 is exactly "the A view is the pool" (`A_view_is_pool` in the
//     same row), because kPhysArenaBeginVa (0xA0400000) IS the A view's base
//     plus the 4 MiB F-391 headroom (heap_arena.h:56, boot_host.cpp:194-197).
//     So `pa | 0xC0000000` is 0x20000000 ABOVE the byte, inside the pool's live
//     tail for pa < 4 MiB and inside nothing-at-all-writable above it.
//
//  3. IT SILENTLY READ ZEROS, AND THE BUILDER'S BYTES ARE INTACT. Same soak,
//     same timestamps, offset identical modulo 0x20000000:
//       15:28:44.436 PKT-CAP #0008 ... win=B7C8A340 n=11 | 00000A31 02000000
//                00010A2F 00001000 196E2000 C0043C00 00000003 00000A31 ...
//       15:28:44.436 CP: INDIRECT_BUFFER #5 @ D7C8A340 dwords=11 depth=0 |
//                win[0..7]=00000000 x8 | win+0x200[0..7]=00000000 x8
//     win=B7C8A340 is `pw.addr`, the window the guest's own reserver
//     sub_82411640 returned (gpu_device.cpp:3725 `ctx.r3.u32`) and the guest
//     then filled; D7C8A340 = B7C8A340 | 0x20000000. The ten nonzero dwords on
//     the A side include the PM4_WAIT_REG_MEM header C0043C00, which is why
//     `CP: IB-OPC-CENSUS` reads t3=0 and walked==2*t0 on 8/8 rows: a zero header
//     has hdr>>30==0, i.e. TYPE-0 count 0, so the walk is 2 dwords per packet
//     and no Type-3 header is ever reached. All four CP-WAITREG-* markers,
//     `CP: RING A PARKED`, `CP-DRAW-CENSUS` and `CP-DRAW-BRIDGE` are 0 in
//     w679.log (byte-counted; all four literals verified present in src/, so
//     those zeros are measurements, not dead markers).
//
// THE MECHANISM IS NOT OURS TO REINVENT: boot_host.h:201 declares
// `PhysViewResult TranslatePhysViewToPoolVa(uint32_t viewVa, uint32_t* outPoolVa)`
// and boot_host.cpp:3843 defines it over `F640MapViewToPool` (boot_host.cpp:
// 217-232), whose arithmetic is `poolVa = kPhysArenaBeginVa + (pa - 0x400000)`
// with `pa = viewVa - viewBase` -- i.e. for pa >= 4 MiB, `poolVa == pa | 0xA0000000`,
// which is link 1's inverse exactly. It returns kMapped / kNoPoolByte /
// kNotAView and it NEVER falls back to the untranslated view address, which for
// pa < 4 MiB is the pool's own live tail (native_renderer.cpp:194-208 says why
// falling back there is the one failure mode with no error anywhere). So the
// refusal is honoured here too: a physical address with no pool byte is a MISS,
// counted and named, never silently redirected.
//
// CALL SITES AND THEIR CLASSIFICATION (every `PhysToKernelVA` in this file):
//   :1140 / :1167  CpVertexFetchSlot::vaBase from a fetch constant's ADDRESS
//                  field (a 30-bit DWORD count, `physBase = address << 2`,
//                  d3d12_command_processor.cc:2231) - a guest PHYSICAL address,
//                  same defect, routed through the rule. Predicted effect:
//                  UNMEASURED (zero draws have ever reached this code).
//   :1504          CpExecImLoad's first probe of a PM4_IM_LOAD body. Same defect;
//                  the pool form now wins the probe and the existing raw-physical
//                  fallback at :1511-1514 is KEPT, so the probe-both behaviour
//                  (and its `vaIsKernel` field's meaning) cannot regress.
//   :2417          the MEMORY form of PM4_WAIT_REG_MEM's poll target - same
//                  defect, and the guest demonstrably builds that form
//                  (wait_info=0x13, link 1). Part of this same single fix.
//   :3516 / :4018  PM4_INDIRECT_BUFFER's list pointer, ring path and nested-IB
//                  path - THE SITE THAT MATTERS (link 3). Both now go through one
//                  helper so the two cannot drift again.
//   :4466          CpEnableRPtrWriteBack's publish target. LEFT ALONE, and the
//                  reason is measured incompleteness, not a claim that the C view
//                  exists: there is no measurement of which view the guest's
//                  rptr waiter polls. `WAIT[KWFSO] ... rptrWB=0019
//                  wb@D840B2BC=00000019` LOOKS like proof and is not - that field
//                  is a HOST read of CpPrimaryWritebackVA() (imports.cpp:
// 4978-4981), so it only proves we can read our own write, which F-057(1)
//                  already retired as ring-progress evidence. Changing a
//                  guest-visible publish target with no such measurement could
//                  break the only writeback path currently observed to work, so
//                  it needs its own census first. See the report.
// ---------------------------------------------------------------------------

// F-680 counters. ATTEMPTS and OUTCOMES are separate counters, the F-640 shape
// (boot_host.cpp:250-254): a `refused=0` printed beside `calls=0` is not a
// measurement, and this row exists so that reading can never be taken.
std::atomic<uint64_t> g_cpPoolXlateCalls{0};
std::atomic<uint64_t> g_cpPoolXlateOk{0};
std::atomic<uint64_t> g_cpPoolXlateRefused{0};

// F-680: a guest PHYSICAL address -> the flat-window VA the builder actually
// wrote. Returns 0 when this tree has no pool byte for it; 0 can never be a pool
// address (the pool starts at kPhysArenaBeginVa), so 0 is an unambiguous
// refusal and no caller has to guess which it got.
uint32_t CpPhysToPoolVa(uint32_t pa, const char *site) {
  const uint64_t n =
      g_cpPoolXlateCalls.fetch_add(1, std::memory_order_relaxed) + 1u;
  // NOT a console physical address (>= kConsolePhysicalBytes): PhysToKernelVA
  // passed such values through UNCHANGED, and so does this. Keeping the
  // pass-through identical is deliberate - it means no caller silently changes
  // address CLASS, only the view a real physical address is presented in. The
  // fetch-constant ADDRESS field is 30 dwords wide, so its `<< 2` can exceed
  // kConsolePhysicalBytes and it does (see :1140).
  if (pa >= mcla::kernel::kConsolePhysicalBytes) {
    return pa;
  }
  uint32_t poolVa = 0;
  // The console's own published view form (what PhysToKernelVA used to invent),
  // handed to the one function that knows this tree's window. Native_renderer
  // :246-249 does exactly this, so there is one mechanism and one refusal
  // counter set for the whole project.
  const mcla::boot::PhysViewResult r =
      mcla::boot::TranslatePhysViewToPoolVa(pa | 0xC0000000u, &poolVa);
  if (r == mcla::boot::PhysViewResult::kMapped) {
    g_cpPoolXlateOk.fetch_add(1, std::memory_order_relaxed);
    return poolVa;
  }
  const uint64_t d =
      g_cpPoolXlateRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP: POOL-XLATE-REFUSED #{} site={} pa={:08X} view={:08X} reason={} "
        "calls={} ok={} refused={} - this tree has NO pool byte for it. NOT "
        "redirected to the untranslated view: for pa<0x400000 that address is "
        "the pool's own live tail (F-640, boot_host.cpp:219-228). Access "
        "dropped.",
        d, site, pa, pa | 0xC0000000u,
        r == mcla::boot::PhysViewResult::kNoPoolByte ? "NO_POOL_BYTE"
                                                      : "NOT_A_VIEW",
        n, g_cpPoolXlateOk.load(std::memory_order_relaxed), d);
  }
  return 0u;
}

// T41.4c (B4, F-115a): the last 64 accepted pokes, in order. AUTO-source draws
// (CP-DRAW src=2) carry no vertex-buffer descriptor argument at all -- the
// observed builder call passes a literal `li r5,0` -- so whatever VB/IB/shader
// state such a draw uses can only come from this register batch. Peeking seven
// fixed ids was not enough to find it; F-611 replaced the guessing with a watch
// on the one block that can hold the answer (g_fetchVbWrites).
// F-605: DRAW-MARKER pipe proof. The auto draw class (op36/src2) carries no
// vertex data and none is tracked, so the first pipe milestone draws a
// synthetic quad per submission (see DrawMarkerCommand). Kill-switch: F-610
// made push() non-blocking and sheddable, so the marker can no longer park the
// guest - at CommandQueue::kShedDepth (60) a sheddable marker is refused and
// counted by QUEUE-SHED, and the render thread sheds it on dequeue. The
// submission condition (src == 2, both draw opcodes) and the sequence number it
// carries are UNCHANGED by F-611, so marker counts stay comparable with w654.log.
constexpr bool kCpDrawMarkerPipe = true;
struct CpRegTraceEntry {
  uint32_t index;
  uint32_t value;
};
constexpr uint32_t kCpTraceSize = 64u;
std::atomic<uint32_t> g_cpTracePos{0};
CpRegTraceEntry g_cpTrace[kCpTraceSize]{};

inline uint32_t CpRegPeek(uint32_t index) {
  if (index >= kXenosRegCount) return 0u;
  return g_xenosReg[index].load(std::memory_order_relaxed);
}

// F-610: the parts of Xenia's CommandProcessor::WriteRegister
// (command_processor.cc:331-484) that are HOST-side and therefore ours to
// implement, called from CpRegPoke after the value is in the file.
//
// (1) Scratch-register writeback, :344-352. A write to SCRATCH_REG0..7 while
//     the matching SCRATCH_UMSK bit is set is ALSO stored to
//     SCRATCH_ADDR + n*4 with store_and_swap<uint32> (base/memory.h:431),
//     which in our big-endian guest view is a plain WriteU32BE. This is
//     guest-visible: it is how the title reads back the interrupt-sync /
//     present-interval scratch words (:578 interrupt sync, :579 present
//     interval, register_table.inc:56-63) after the CP has published them.
//
// F-720 (2026-10-02): `dest` IS A GUEST PHYSICAL ADDRESS, and the store below
// puts it in the WRONG ADDRESS SPACE. Both halves are measured, not inferred;
// the references are quoted because the two answers come from them and from
// nothing else in this file.
//
// WHAT `dest` IS. command_processor.cc:349-351 verbatim:
//     uint32_t scratch_addr = regs.values[XE_GPU_REG_SCRATCH_ADDR];
//     uint32_t mem_addr = scratch_addr + (scratch_reg * 4);
//     xe::store_and_swap<uint32_t>(memory_->TranslatePhysical(mem_addr), value);
// `mem_addr` goes to TranslatePhysical, which is NOT a guest-virtual address:
// .research/xenia/src/xenia/memory.h:336-340 is
//     TranslatePhysical(pa) { return physical_membase_ + (pa & 0x1FFFFFFF); }
// and memory.cc:158 puts physical_membase_ at mapping_base_ + 0x100000000 --
// "physical memory is a SEPARATE host region ABOVE the 4 GiB guest mapping, not
// a slice of guest virtual space". Guest VIRTUAL 0x1840B284 is in the
// v00000000 heap (memory.cc:161-162) and is NOT physical 0x1840B284. So the
// byte the reference writes is the physical byte, and it is not the byte this
// host's `dest` addresses.
//
// WHERE THAT PHYSICAL BYTE IS IN THIS TREE. The pool is presented at guest VA
// [kPhysArenaBeginVa, kPhysArenaEndVa) = [0xA0400000, 0xC0400000) -- derived, not
// typed: heap_arena.h:56 / :119-136 with the static_asserts, and MEASURED in the
// log under audit at byte offset 3497:
//   F640-PHYSALIAS phase=init mech=PARTIAL(alias-broken) canary_shared_views=1/3
//   probe_pa=10400000 probe_pool_va=B0400000 ... A_view_is_pool=1
//   pool=[A0400000..C0400000) pool_phys=[00400000..20400000)
// and by the wait's own translation one row later:
//   F640-CVIEW-TRANSLATE #21 view=C16M view_va=D840B284 pool_va=B840B284
//   pa=1840B284
// poolVa = kPhysArenaBeginVa + (pa - 0x400000) (boot_host.cpp:225-226). For
// pa = 0x1840B284 that is 0xB840B284, which is also `pa | 0xA0000000` -- the
// guest's own EA->PA inverse, decompiled out of sub_824199B0 and recorded at
// :481-491. 0x1840B284 and 0xB840B284 are 0xA0000000 apart and are DIFFERENT
// bytes of this tree's one flat 4 GiB window (kernel/memory.h:18-19, :39-40,
// :124-126: Translate is base+addr, and both addresses are in range).
//
// MEASURED PROOF THAT THEY ARE, from the harness under
// %TEMP%\opencode\gpu_cp_work (real CpScratchWriteback, real wait poll loop,
// real ReadU32BE/WriteU32BE, real memory, every block spliced byte-for-byte):
//     MEASURED write landed at VA : 1840B284
//     MEASURED poll  read   at VA : B840B284
//     SAME BYTE?                  : NO
//     raw (ReadU32BE at pollVA)   : 00000000
// and build/w700.log agrees on its own row, 784 ms later:
//     CP-WAITREG-TIMEOUT #1 ... poll=1840B286 pollVA=B840B284 ref=00000001
//     value=00000000 raw=00000000
// i.e. the byte the poll reads is still ZERO after the writeback stored 1 next
// door at flat 0x1840B284. `CP-SCRATCH-WB #2 ... val=00000001 umsk=00020037
// STORED` is not a lie about having stored; it stored to the wrong byte.
//
// THIS IS NOT ONE SITE. Every guest-PHYSICAL-addressed store in this file is
// flat at the physical address, because they were written to mirror each other
// and never to a space:
//   :683  CpScratchWriteback   SCRATCH_ADDR+slot*4   command_processor.cc:351
//   :2589 CpExecRegToMem 0x3E  packet's mem word     command_processor.cc:1084-1086
//   :3157 CpExecEventWriteShd  packet's address word command_processor.cc:1213-1214
//   :3307 ExecuteMemWrite 0x3D packet's write_addr   command_processor.cc:1092-1108
//   :2587 is the READ half of :2589 and must move with it, or the F-651
//   idempotence probe compares a pool byte nobody wrote against a flat byte
//   nobody wrote and every one of the 17.5M 0x3E packets/soak stores.
// The remaining WriteU32BE sites in this file (:2183, :4986, :5141, :5424) take
// guest VIRTUAL pointers out of TLS or out of the guest context block, and
// :2389 / :5278 / :5328 publish the rptr writeback at the `| 0xC0000000` form,
// which is the DELIBERATE exception documented at :552-562 and :2237-2245 with
// the reason (no measurement of which view the guest's rptr waiter polls).
//
// AND FIXING THE SPACE ALONE WOULD NOT UNFREEZE ANYTHING. The wait's READ side
// is off by one full byte swap, independently. command_processor.cc:971-983
// GpuSwaps the RAW HOST LOAD; this file does
// `mem.ReadU32BE(pollVA, &rawSeen)` (:2927) then `GpuSwap32(rawSeen, poll & 3)`
// (:2948), and ReadU32BE is ALREADY a byte swap (kernel/memory.cpp:221-222:
// `*outVal = Swap32(beVal)`).
//
// F-721 RE-MEASURED THIS TABLE, AND HALF OF IT WAS WRONG - INCLUDING THE CLAIM
// IN THE LAST SENTENCE. The conclusion below ("they never agree") SURVIVED; the
// numbers, the "write sides are right" claim, and the "nothing is moved here"
// decision did not. Kept as a correction, not deleted, because a reader who
// trusts the old table would be wrong in exactly the way this file was.
//
// WHAT WAS WRONG, and where the right numbers come from. The old table's
// `this-file value` column is a hand-derived GpuSwap32 of the GUEST word; the
// honest measurement has to start from the BYTES. The reference's scratch store
// is store_and_swap<uint32_t> (command_processor.cc:351, base/memory.h:431-433)
// = `*ptr = byte_swap(value)`, so on this LE host it leaves 0x01000000 in memory
// for a stored 0x00000001; the poll then loads that RAW (cc:978) and applies ONE
// GpuSwap (cc:982-983). Measured, harness_gate2.cpp, every function spliced from
// this file and from .research/xenia:
//     sel  bytes at poll   REFERENCE read   tree read (was)
//     0    01000000        01000000         00000001   NO
//     1    01000000        00010000         00000100   NO
//     2    01000000        00000001         01000000   NO   <- w702.log (poll&3=2)
//     3    01000000        00000100         00000001   NO
// So: 4/4 disagreed, as claimed - but the old table's e=0 and e=3 REFERENCE
// values (00000001, 01000000) were both wrong, and its `ref.value` for e=3
// repeated e=0's. The corrected e=3 reference value is 00000100, because
// k16in32 swaps half words (xenos.h:1065-1067).
//
// "THE WRITE SIDES ARE RIGHT" WAS ALSO WRONG, and that is the expensive half.
// It is true for the SCRATCH writeback alone: there WriteU32BE IS
// store_and_swap, and the harness measures 4/4 agreement. It is FALSE for all
// three PM4 stores. The reference's 0x3E / 0x3D / 0x58 store is
// `xe::store<uint32_t>(ptr, GpuSwap(data, endian))` (cc:1086, 1102, 1214), and
// xe::store<uint32_t> is a PLAIN host store (base/memory.h:374-376) - it adds no
// swap of its own. WriteU32BE adds Swap32 (kernel/memory.cpp:351). Measured 4/4
// disagreement on all four selectors: the tree was leaving Swap32(reference
// bytes) for every PM4 store.
//
// F-746, AND THIS IS THE MORE EXPENSIVE HALF: THE HALF ABOVE WAS MEASURED ON A
// PRIMITIVE THAT WAS NOT THE ONE IN USE. "WriteU32BE adds Swap32" is true, but
// after F-721 these three sites no longer call WriteU32BE - they call
// CpWriteU32Raw, which is `WriteU32BE(va, CpByteSwap32(X))` (:2854-2857), so
// CpWriteU32Raw's X *is* the host dword and there is no swap left to remove.
// Measured directly, harness scenario C0: CpWriteU32Raw(va, X) leaves host
// dword == X, 4/4 values. F-721 then put a CpByteSwap32 INSIDE that argument at
// 0x3E and 0x3D, so those two ended up one Swap32 too many - 0/4 store-byte
// agreement and 0/4 round trip, i.e. WORSE than the pre-F-721 state it claimed
// to fix. 0x58 passes GpuSwap32 in with no CpByteSwap32 and was right all along
// (4/4, unchanged). Corrected at 0x3E and 0x3D by F-746; the harness is the
// evidence, and it is the same harness file the claim above cites.
//
// WHICH IS WHY BOTH SIDES HAD TO MOVE. Correcting only the poll read REGRESSES
// the 0x3E/0x3D/0x58 round trip by 4/4 (harness section 3b): with the store's
// extra Swap32 left in place, the poll reads that Swap32 instead of cancelling
// it. A space-only fix would not have unfrozen anything either - it moves the
// symptom - but neither would a space+read fix without the write half.
// F-746 NOTE: that sentence is right about the READ half and wrong about the
// WRITE half - the write half did not need "fixing" here at all; it needed
// UNDOING once CpWriteU32Raw existed. Measured, not argued: scenario C went from
// 8 failures to 0 across the four selectors x four writers.
//
// The comment that stood at the old :2942-2947, calling ReadU32BE-then-GpuSwap32
// "the mirror of upstream's read-then-GpuSwap on a little-endian host", was a
// GLOSS and it was wrong: ReadU32BE is not the raw host load, it is the
// byte-reversed one.
//
// F-721 MOVED IT, AND THIS PARAGRAPH IS WHY THAT WAS NOT DONE BEFORE. Its two
// stated reasons were: (a) no single-variable attribution is available in a dirty
// tree (rule 1a), and (b) a space-only fix would move the symptom rather than
// unfreeze anything. Reason (b) is why this landed as ONE change covering BOTH
// defects and all seven sites rather than as the space half alone - measured, not
// assumed: with the write in the pool and the poll read still double-swapping,
// the fence compares 0x01000000 against ref 0x00000001 and still times out.
// Reason (a) still stands as a LIMITATION and is not solved by this change: the
// tree is dirty across ~45 files, so if the next soak does not show the freeze
// lifting, this change is not the proved cause - it is the best-supported
// candidate, and the harness (not the soak) is what establishes its mechanism.
// What was landed before, and is kept: the missing CpNoteMemWriteDest
// registration (the reason CP-WAITREG-NEVERWRITTEN could claim no writer exists)
// and the bounded census row below.
// (2) COHER_STATUS_HOST, :358-361. OR bit 31 (registers.h:88 `status`) into
//     the stored value: the coherency request is pending, so a later
//     WAIT_REG_MEM must block on it.
//     F-651(3) SUPERSEDES the rest of this paragraph. It used to read "We do not
//     implement MakeCoherent ... The bit is still set so the register reads back
//     truthfully" - and that combination is exactly why the fence could never
//     complete: this host set the bit and nothing could clear it. MakeCoherent
//     is now implemented (CpMakeCoherent, from command_processor.cc:486-524)
//     and is called from inside the 0x3C poll at :985-988, so the dirty bit
//     that WriteRegister sets is the bit MakeCoherent clears. See its own
//     comment for exactly what is and is not modelled.
//     On the flush itself: there is nothing to flush, since every store into
//     guest memory in this file is already host-ordered and immediately
//     visible to guest loads - and the reference models no flush either
//     (command_processor.cc:518 is a TODO for the resource cache). The bit is
//     still set here, truthfully, because the coherency request IS pending; it
//     is cleared by MakeCoherent when a wait actually polls for it, which is
//     the reference's own sequence and not a shortcut.
// (3) The gamma LUT (DC_LUT_*, :363-481) is NOT implemented. See
//     CpNoteGammaLutWrite below.
void CpScratchWriteback(uint32_t slot, uint32_t value) {
  const uint32_t umsk =
      g_xenosReg[kRegScratchUmsk].load(std::memory_order_relaxed);
  if (((1u << slot) & umsk) == 0u) {
    return;
  }
  const uint32_t dest =
      g_xenosReg[kRegScratchAddr].load(std::memory_order_relaxed) + slot * 4u;
  // F-721: `dest` is a guest PHYSICAL address (command_processor.cc:349-351 hands
  // it to memory_->TranslatePhysical) and it goes to the POOL, not to the flat
  // window at the physical number. This is the writer named in w702.log's freeze
  // (`CP-SCRATCH-WB dest=1840B284 val=00000001`, 784 ms before the wait polls
  // 1840B286): the store landed on flat 0x1840B284 while the wait - correctly -
  // polls the pool byte 0xB840B284, so the byte it read was still zero and the
  // ring parked for 156 s.
  //
  // GATE 3, settled by measurement rather than by arithmetic: the reference's
  // TranslatePhysical and this tree's pool are the SAME MAPPING, not two. In
  // .research/xenia/src/xenia/memory.cc:216-274 `map_info` maps BOTH the
  // 0xA0000000-0xBFFFFFFF window AND the 0x100000000-0x11FFFFFFF "physical raw"
  // window onto the SAME file offset (target_address 0x100000000), and :158 puts
  // physical_membase_ at mapping_base_ + 0x100000000 - the base of that second
  // view. So TranslatePhysical(pa) and the guest's own A-view address
  // (pa | 0xA0000000) are two ALIASES of one file mapping, by construction.
  // This tree's poolVa = kPhysArenaBeginVa + (pa - 0x400000) (boot_host.cpp:225-226)
  // is 0xA0400000 + (pa - 0x400000), which for every pa >= 0x400000 EQUALS
  // pa | 0xA0000000 - the A view, measured in w700.log as canary_shared_views=1/3
  // A_view_is_pool=1. Moving a store here therefore moves it to the byte the
  // reference's own poll reads, not to some other mapping.
  const uint32_t destVa = CpPhysToPoolVa(dest, "SCRATCH-WB");
  // The scratch writeback's BYTE ORDER is already correct and is deliberately
  // not changed: command_processor.cc:351 uses store_and_swap<uint32_t>
  // (base/memory.h:431-433), which is exactly WriteU32BE (kernel/memory.cpp:351).
  // Measured 4/4 agreement on all `poll & 3` selectors - the one writer here
  // whose bytes match the reference today. Only its ADDRESS moved.
  //
  // A refusal does NOT return early. It falls through with ok=false so the
  // bounded CP-SCRATCH-WB row below still fires for this attempt: returning here
  // would silently delete a row from a tracked marker's cadence, and the row's
  // own text already has a not-stored state ("WRITE-FAILED") to report it in.
  // There is no fallback store - destVa==0 means this tree has no pool byte for
  // that physical address, and CP: POOL-XLATE-REFUSED above has already printed
  // the reason and the attempt index under site=SCRATCH-WB.
  const bool ok =
      destVa != 0u &&
      mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(destVa, value);
  // F-720: THIS SITE NEVER REGISTERED ITS DESTINATION, and that is why
  // CP-WAITREG-NEVERWRITTEN could assert "no writer this host implements could
  // have produced the value" (:3010-3017) about a byte a writer had just
  // published to. The three sibling PM4 stores register (CpExecRegToMem :2591,
  // CpExecEventWriteShd :3159, ExecuteMemWrite :3308); this one did not, so the
  // 256-entry ring could never answer for it.
  //
  // `dest` goes in the SAME UNITS the query side uses, which is the guest
  // PHYSICAL address -- CpExecWaitRegMem looks up `pollByte` (:2827, :2905), not
  // the pool VA. Registering a pool VA here would restore the 0xA0000000 units
  // mismatch a previous fix removed from the query side.
  //
  // REGISTRATION ONLY. It cannot satisfy a wait and cannot unsatisfy one: the
  // predicate is evaluated from mem.ReadU32BE(pollVA, ...) at :2927 and from
  // nothing else, so the worst this can do is move the TIMED OUT row from
  // CP-WAITREG-NEVERWRITTEN to CP-WAITREG-WRITER-MISMATCH (:3037-3048). Both
  // rows end in the same place: g_waitRegMemParked + NOT advancing rptr.
  //
  // Registered only when the store was ACCEPTED, which is what this ring means
  // by "a store this file makes" (:2887-2889). ExecuteMemWrite (:3308)
  // registers unconditionally even though it discards the WriteU32BE result;
  // that is a wider claim than this row's text supports, and it is left alone
  // rather than silently changed.
  if (ok) {
    CpNoteMemWriteDest(dest);
    // F-746: the value goes in the units the WAIT compares in. This store is
    // `store_and_swap` (command_processor.cc:351), i.e. it leaves Swap32(value)
    // in memory and the poll applies ONE GpuSwap for its own `poll & 3`. For the
    // selector this host measured on every wait in build/w703.log - poll & 3 == 2,
    // k8in32, a full byte swap, and the guest hard-codes it at 0x82419A48 /
    // 0x82419B54 (`ori r11,r11,2`, raw word 616B0002) - those two swaps cancel
    // and the poll reads `value` back unchanged. `value` is therefore the number
    // to record, and this is stated rather than assumed: the harness under
    // %TEMP%\opencode\cpwait_work measures it for all four selectors.
    CpNoteMemWriteValue(dest, value);
  }
  const uint32_t n = g_scratchWritebacks.fetch_add(1, std::memory_order_relaxed) + 1;
  // F-813: the old bound was `n <= 8 || (n % 200) == 0`, which makes n=9..199 INVISIBLE. The
  // counter demonstrably passes 200 and 400 (both rows exist in w800-w805), so a `slot=0
  // val=00000000` store inside that window would be a silent miss -- and that one row is the
  // discriminator between H1/H3 (host drops or mis-reads the guest's clear) and H2 (the guest
  // never clears its own fence). CENSUS ONLY: the row's format and the code below it are
  // unchanged; only the firing bound widens. A capped printer's count is a cadence, not a total
  // (F-651), and this is the one place in the park chain where the cap hid the deciding fact.
  if (n <= 400 || (n % 200) == 0) {
    MCLA_LOG_WARN("CP-SCRATCH-WB #{} reg={:04X} slot={} dest={:08X} "
                  "val={:08X} umsk={:08X} {}", n, kRegScratchReg0 + slot, slot,
                  dest, value, umsk, ok ? "STORED" : "WRITE-FAILED");
    // F-720, NEW ROW, NEW NAME. CENSUS: NOTHING BELOW THIS POINT IS CHANGED BY
    // IT, and the row above keeps its exact format and its exact firing bound
    // (both untouched -- a soak may diff the multiset of MCLA_LOG_* literals).
    //
    // The three fields a reader needs and cannot otherwise get from this row:
    //   destPhys    the address the store was ISSUED to. `dest` is the guest
    //                PHYSICAL address (command_processor.cc:349-351 hands it to
    //                memory_->TranslatePhysical), and TranslatePhysical is
    //                physical_membase_ + (pa & 0x1FFFFFFF) -- NOT a guest
    //                virtual address (.research/xenia/src/xenia/memory.h:336-340).
    //   space       the ADDRESS SPACE the store actually used: FLAT, i.e. this
    //                tree's one 4 GiB window at the guest PHYSICAL number.
    //                The reference's space is PHYSICAL, presented in this tree
    //                at guest VA 0xA0000000 + pa -- the console's OWN identity
    //                for a physical byte, because the A view's base IS the
    //                physical heap's base on the console (xenia memory.cc:171-180:
    //                one 512 MiB physical heap at physical 0, aliased into the
    //                0xA/0xC/0xE views). The one implementation of that rule in
    //                this tree is F640MapViewToPool (src/boot_host.cpp:312-328):
    //                poolVa = kPhysLowRegionVa + pa.
    //                (F-640/B2, 2026-10-21: the text this replaces said
    //                `kPhysArenaBeginVa + (pa - 0x400000)`, boot_host.cpp:225-226,
    //                which was the PRE-B2 rule. The tree no longer does that, so
    //                the row must not print that arithmetic either.)
    //   val         the word stored, verbatim.
    //
    // `poolByte` is printed as the DERIVED number only and is deliberately NOT
    // computed by calling CpPhysToPoolVa: that call increments F640's counters
    // and, for the first 32 attempts, PRINTS F640-CVIEW-TRANSLATE rows
    // (boot_host.cpp:4026-4078), so a census must not move another marker's
    // contents. The arithmetic is reproduced from the same two constants and is
    // checked against the wait's own pollVA whenever the two rows are adjacent.
    //
    // FALSIFIERS, both one soak: F-721 MOVED this store, so `space=POOL` on
    // every row is now the EXPECTED reading and `space=FLAT` on any row means
    // the move did not happen for that slot - i.e. it falsifies the move, not
    // the other way round. The inverse of the falsifier this row was born with.
    // `onPollByte=` only says the two numbers coincide; it does NOT claim the
    // wait can satisfy on its own - F-721 also corrected the wait's READ side
    // (byte order), which was a second and independent defect.
    // poolByte, DERIVED from the same rule the real path uses, and with the
    // SAME refusal predicate, because a printed number that the real path
    // would refuse to produce is exactly the kind of number that gets quoted
    // later as a measurement.
    //
    // F-640/B2 (2026-10-21, fix_present2): THE RULE, READ FROM THE ONE
    // IMPLEMENTATION (src/boot_host.cpp:312-328, F640MapViewToPool), not
    // restated: a console PHYSICAL address maps to its pool byte as
    //     poolVa = kPhysLowRegionVa + pa          (0xA0000000 + pa)
    // for EVERY pa in the console's physical window [0, 0x20000000) -- the A
    // view's base IS the physical heap's base on the console (xenia
    // memory.cc:171-180), so this is the hardware's mapping and not a host
    // invention. The old arithmetic in this row was
    //     poolByte = kPhysArenaBeginVa + (pa - 0x400000)
    // which is the PRE-B2 rule: it refused every pa < 4 MiB (the console's low
    // region) and printed poolByte=00000000 poolHasByte=0 for it, i.e. it
    // printed a number the real path would never produce. For pa >= 4 MiB the
    // two forms are the SAME number (0xA0400000 + (pa - 0x400000) ==
    // 0xA0000000 + pa), so only the low region changed -- and the low region is
    // exactly where the guest's own fetch constants live (physical 0 and
    // 0x1FE0FC, CP-FETCHVB-DECODE in build/w852.log).
    //
    // THE BELT is the allocator's upper bound (kPhysArenaEndVa), the same one
    // F640MapViewToPool applies. With kConsolePhysicalBytes = 0x20000000 and
    // kPhysLowRegionVa = 0xA0000000 the sum can never reach kPhysArenaEndVa
    // (0xC0400000), so the belt is inert for an in-window pa and the refusal
    // predicate is exactly the console's window.
    const uint32_t poolByte =
        (dest < mcla::kernel::kConsolePhysicalBytes)
            ? (mcla::boot::kPhysLowRegionVa + dest)
            : 0u;
    const bool poolHasByte =
        (poolByte >= mcla::boot::kPhysLowRegionVa) &&
        (poolByte < mcla::kernel::kPhysArenaEndVa);
    MCLA_LOG_WARN("CP-SCRATCH-WB-ADDR #{} reg={:04X} slot={} destPhys={:08X} "
                  "space={} stored={} poolByte={:08X} poolHasByte={} "
                  "onPollByte={} val={:08X} || scratchWB={} stores={} - "
                  "CENSUS, NO CHANGE: destPhys is a GUEST PHYSICAL address "
                  "(Xenia command_processor.cc:351 hands it to "
                  "memory_->TranslatePhysical, and .research/xenia/src/xenia/"
                  "memory.h:336-340 defines that as physical_membase_ + "
                  "(pa & 0x1FFFFFFF), NOT a guest virtual address), and "
                  "space=FLAT is this tree's single 4 GiB window at that "
                  "number. The reference's space is the PHYSICAL byte, "
                  "presented in this tree at poolByte (0xA0000000 + pa, the "
                  "console's own identity for a physical byte -- the A view's "
                  "base IS the physical heap's base, xenia memory.cc:171-180; "
                  "the one implementation is F640MapViewToPool, "
                  "src/boot_host.cpp:312-328, poolVa = kPhysLowRegionVa + pa). "
                  "Those two are 0xA0000000 apart and are DIFFERENT bytes of one window. "
                  "onPollByte=1 only says the numbers coincide. Destination "
                  "now registered with CpNoteMemWriteDest in guest-physical "
                  "units so CP-WAITREG-NEVERWRITTEN can no longer claim no "
                  "writer exists; NOTHING was moved, and no wait outcome "
                  "changes. F-721 UPDATE: the store DID move - space=POOL and "
                  "it lands on poolByte - so the NO-MOVED sentence above "
                  "describes the tree this row was born in, not this one. The "
                  "field set, order and count are unchanged, which is what "
                  "keeps a multiset diff of the row meaningful",
                  n, kRegScratchReg0 + slot, slot, dest, "POOL", ok ? 1 : 0,
                  poolByte, poolHasByte ? 1 : 0,
                  (poolHasByte && dest == poolByte) ? 1 : 0, value, n,
                  g_memWriteDestStores.load(std::memory_order_relaxed));
  }
}

// F-610: the gamma LUT (command_processor.cc:363-481) is NOT built. It is
// three coupled state machines (a 256-entry color10 table, a 128-entry PWL
// base/delta table, and a per-register component cursor gamma_ramp_rw_component_
// that DC_LUT_RW_INDEX resets) whose only consumer is Xenia's
// OnGammaRamp256EntryTableValueWritten / OnGammaRampPWLValueWritten, i.e. the
// D3D12 1D-lookup upload that lives in the renderer's gamma path - a file this
// agent does not own. Faking a table the GPU never reads would be exactly the
// "fake" the native-only charter (F-609) forbids, so this is a CENSUS instead:
// every DC_LUT_* poke is registered and reported, and a nonzero
// CP-GAMMA-LUT-UNMODELED count tells the owner that gamma needs modelling.
void CpNoteGammaLutWrite(uint32_t index, uint32_t value) {
  const char *name = "?";
  switch (index) {
  case kRegDcLutRwIndex:     name = "DC_LUT_RW_INDEX"; break;
  case kRegDcLutSeqColor:    name = "DC_LUT_SEQ_COLOR"; break;
  case kRegDcLutPwlData:     name = "DC_LUT_PWL_DATA"; break;
  case kRegDcLut30Color:     name = "DC_LUT_30_COLOR"; break;
  case kRegDcLutWriteEnMask: name = "DC_LUT_WRITE_EN_MASK"; break;
  default: break;
  }
  const uint32_t n =
      g_gammaLutWrites.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("CP-GAMMA-LUT-UNMODELED #{} reg={:04X} ({}) val={:08X} "
                  "rwIndex={:04X} writeEn={:04X} (register stored; LUT NOT "
                  "built - gamma would be unmodelled)", n, index, name, value,
                  g_xenosReg[kRegDcLutRwIndex].load(std::memory_order_relaxed),
                  g_xenosReg[kRegDcLutWriteEnMask].load(std::memory_order_relaxed));
  }
}

inline void CpRegPoke(uint32_t index, uint32_t value) {
  if (index >= kXenosRegCount) {
    return;
  }
  const uint32_t tp =
      g_cpTracePos.fetch_add(1, std::memory_order_relaxed) % kCpTraceSize;
  g_cpTrace[tp] = {index, value};
  g_xenosReg[index].store(value, std::memory_order_relaxed);
  // F-647: mark presence AFTER the value, release-ordered. A reader that
  // observes this bit is then guaranteed to observe the value above, so
  // "present" can never be paired with a stale/zero word. This is the only
  // place presence is set; nothing else in the file claims a register was
  // written, which is what keeps CP-DRAW-REGS (a 64-entry ring that skips
  // zeros) from being mistaken for a presence census.
  g_xenosRegPresent[index >> 5].fetch_or(1u << (index & 31u),
                                          std::memory_order_release);
  g_xenosRegWrites.fetch_add(1, std::memory_order_relaxed);
  if (index >= 0x2000u) {
    g_xenosRegHiWrites.fetch_add(1, std::memory_order_relaxed);
  }
  if (index >= kRegFetchVbFirst && index < kRegFetchVbLast) {
    const uint32_t w =
        g_fetchVbWrites.fetch_add(1, std::memory_order_relaxed) + 1u;
    // F-612: the gate the next stream needs, as a NAMED COUNTED row. Until now
    // g_fetchVbWrites was only ever read by the draw bridge and the state dump,
    // so "the block was never written" was an inference from an absent counter
    // rather than something a soak could see. `CP-FETCHVB #N` is the positive
    // evidence; a soak with ZERO of these lines proves the absence, and the
    // first one turns the F-611 diagnosis into a live decode problem.
    if (w <= 8u || (w % 200u) == 0u) {
      MCLA_LOG_WARN("CP-FETCHVB #{} reg={:04X} val={:08X} (fetch/VB block "
                    "0x4800-0x48BF writes={})",
                    w, index, value, w);
    }
  }
  if (index < kMmioRegCount) {
    g_regShadow[index].store(value, std::memory_order_relaxed);
  }

  // ---- F-610: WriteRegister side effects (command_processor.cc:344-361) ----
  if (index >= kRegScratchReg0 && index <= kRegScratchReg7) {
    CpScratchWriteback(index - kRegScratchReg0, value);
  } else if (index == kRegCoherStatusHost) {
    // COHER_STATUS_HOST.status is bit 31 (registers.h:88). It is set on write
    // (command_processor.cc:358-361) and cleared by CpMakeCoherent, which the
    // 0x3C poll calls from inside its own loop (:985-988). Both halves now
    // exist: the previous state, where this host set the bit and nothing could
    // ever clear it, made the fence a hang by construction.
    const uint32_t dirty = value | kCoherStatusBit;
    g_xenosReg[index].store(dirty, std::memory_order_relaxed);
    if (index < kMmioRegCount) {
      g_regShadow[index].store(dirty, std::memory_order_relaxed);
    }
    const uint32_t n = g_coherDirty.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
      MCLA_LOG_WARN("CP-COHER-DIRTY #{} val={:08X} -> {:08X}", n, value, dirty);
    }
  } else if (index >= kRegDcLutRwIndex && index <= kRegDcLutLast) {
    CpNoteGammaLutWrite(index, value);
  }
}

// F-610: a TYPE-0 whose computed target index falls outside the 0x5003-dword
// file. Xenia refuses exactly this way (command_processor.cc:333-336 logs and
// returns), so parity means a LOUD refusal, never a write to the wrong
// register. CP-T0-REFUSE must be absent from a soak for the widened 15-bit
// base to be provably harmless.
void CpNoteType0Refused(uint32_t target, uint32_t base, uint32_t i,
                        uint32_t count, bool writeOne) {
  const uint32_t n = g_type0OutOfFile.fetch_add(1, std::memory_order_relaxed) + 1;
  if (n <= 8 || (n % 200) == 0) {
    MCLA_LOG_WARN("CP-T0-REFUSE #{} target={:04X} base={:04X} i={} count={} "
                  "writeOne={} (out of 0x5003-dword register file - NOT "
                  "written, as upstream)", n, target, base, i, count,
                  writeOne ? 1 : 0);
  }
}

// F-610: the TYPE-0 payload cap fired. Names the op so a soak can attribute
// truncation, and the exact number of payload dwords that were dropped.
void CpNoteType0Cap(const char *op, uint32_t base, uint32_t count,
                    uint32_t stored, bool writeOne) {
  const uint32_t n = g_type0CapHits.fetch_add(1, std::memory_order_relaxed) + 1;
  MCLA_LOG_WARN("CP-T0-CAP #{} op={} base={:04X} count={} stored={} "
                "TRUNCATED={} writeOne={} (cap {} dwords)", n, op, base, count,
                stored, count - stored, writeOne ? 1 : 0, kType0PayloadCap);
}

// F-610: shared TYPE-0 core, so the indirect-buffer path and the ring path
// cannot drift apart again (they had two independent copies of the base mask
// and only the IB copy had any payload logging). `nextWord(&out)` yields
// payload dword `i` from the packet STREAM: linear inside an indirect buffer,
// wrap-around inside the circular ring.
template <typename NextWord>
void CpType0Apply(const char *op, uint32_t header, uint32_t count,
                  NextWord &&nextWord) {
  // 15-bit base (command_processor.cc:651) + the bit-15 alternate encoding
  // (:652,:655 `write_one_reg` - every payload dword goes to the SAME register
  // instead of base+i). Xenia composes base_index from `packet & 0x7FFF`
  // BEFORE looking at bit 15, so a bit-15 packet always names an index in
  // 0x8000..0xFFFF and is dropped by its own bounds check (:333). We keep
  // that composition (parity) but make the drop loud via CpNoteType0Refused,
  // so a TYPE-0 with bit 15 set can never alias a low register.
  const uint32_t base = header & kType0BaseMask;
  const bool writeOne = ((header >> 15) & 0x1u) != 0u;
  if (writeOne) {
    const uint32_t n =
        g_type0WriteOne.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
      MCLA_LOG_WARN("CP-T0-ONE #{} op={} base={:04X} count={} (bit15 alternate "
                    "encoding)", n, op, base, count);
    }
  }
  const uint32_t limit = (count < kType0PayloadCap) ? count : kType0PayloadCap;
  uint32_t consumed = 0; // payload dwords taken off the stream
  uint32_t written = 0;
  for (uint32_t i = 0; i < limit; ++i) {
    uint32_t v = 0;
    if (!nextWord(&v)) {
      break;
    }
    ++consumed;
    const uint32_t target = writeOne ? base : (base + i);
    if (target >= kXenosRegCount) {
      CpNoteType0Refused(target, base, i, count, writeOne);
      continue;
    }
    CpRegPoke(target, v);
    ++written;
  }
  if (count > consumed) {
    CpNoteType0Cap(op, base, count, consumed, writeOne);
  }
  static std::atomic<uint32_t> s_t0{0};
  const uint32_t n = s_t0.fetch_add(1) + 1;
  if (n <= 40 || (n % 250) == 0) {
    MCLA_LOG_WARN("CP-REG-T0 #{} op={} base={:04X} n={} written={} val={:08X} "
                  "writes={}", n, op, base, consumed, written,
                  written ? CpRegPeek(base) : 0u,
                  g_xenosRegWrites.load(std::memory_order_relaxed));
  }
  // F-090 proof-of-widen, deduplicated by base and NOT counter-capped: one
  // line per distinct register base at/above the old 0x2000 bound, which used
  // to be dropped. So an absent line really means the guest never wrote that
  // base (unlike CP-REG-T0, whose cap makes its zeros meaningless).
  if (base + consumed > 0x2000u) {
    static uint32_t seenBase[64] = {};
    static uint32_t seenN = 0;
    bool dup = false;
    for (uint32_t i = 0; i < seenN; ++i) {
      if (seenBase[i] == base) {
        dup = true;
        break;
      }
    }
    if (!dup && seenN < 64u) {
      seenBase[seenN++] = base;
      MCLA_LOG_WARN("CP-REG-HI #{} op={} base={:04X} n={} val={:08X} "
                    "hiWrites={}", seenN, op, base, consumed,
                    written ? CpRegPeek(base) : 0u,
                    g_xenosRegHiWrites.load(std::memory_order_relaxed));
    }
  }
}

void CpType0Write(uint32_t header, uint32_t byteAddr, uint32_t count) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t p = byteAddr + 4u;
  CpType0Apply("IB", header, count, [&](uint32_t *out) {
    if (!mem.ReadU32BE(p, out)) {
      return false;
    }
    p += 4u;
    return true;
  });
}

bool CpExecRegRmw(uint32_t byteAddr, uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t info = 0, andMask = 0, orMask = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &info) ||
      !mem.ReadU32BE(byteAddr + 8u, &andMask) ||
      !mem.ReadU32BE(byteAddr + 12u, &orMask)) {
    return false;
  }
  const uint32_t idx = info & 0x1FFFu;
  uint32_t value = CpRegPeek(idx);
  if ((info >> 31) & 0x1u) value &= CpRegPeek(andMask & 0x1FFFu);
  else                      value &= andMask;
  if ((info >> 30) & 0x1u) value |= CpRegPeek(orMask & 0x1FFFu);
  else                      value |= orMask;
  CpRegPoke(idx, value);
  static std::atomic<uint32_t> s_rmw{0};
  const uint32_t n = s_rmw.fetch_add(1) + 1;
  if (n <= 40 || (n % 250) == 0) {
    MCLA_LOG_WARN("CP-REG-RMW #{} idx={:03X} and={:08X} or={:08X} -> {:08X} "
                  "(info={:08X})", n, idx, andMask, orMask, value, info);
  }
  outAdvance = 4u;
  return true;
}

// F-632: THE SEAM IS CLOSED, AND IT WAS NEVER MISSING.
//
// A previous comment here (F-612) claimed the header declaring the
// vertex-fetch instruction - "xenia/base/ucode/ucode.h" - was ABSENT from this
// checkout, and refused with CP-MICROCODE-UNSUPPORTED pkt=kVertexFetch. That was
// a path error: the file is
//   .research/xenia/src/xenia/gpu/ucode.h   (81,762 bytes, measured)
// under the `gpu/` namespace, not `base/ucode/`. Every field it refused to read
// is declared there, and the includes are real (gpu/shader_interpreter.h:22,
// gpu/shader.h:26, gpu/draw_extent_estimator.cc:21, gpu/shader_translator.h:22,
// gpu/dxbc_shader_translator.h:23). The two refusal reasons are now DISTINCT,
// because they have different fixes.
//
// ---------------------------------------------------------------------------
// ucode::VertexFetchInstruction - 3 dwords, verbatim from gpu/ucode.h:745-777,
// with the three anonymous structs in declaration order packing dword_0,
// dword_1, dword_2 (ucode.h:780 static_asserts sizeof == 3*4).
//
//   dword_0  (ucode.h:747-759, 32 bits exactly)
//     bits  0.. 4  FetchOpcode   opcode_value : 5      <- kVertexFetch == 0
//     bits  5..10  uint32_t      src_reg : 6
//     bit      11  uint32_t      src_reg_am : 1
//     bits 12..17  uint32_t      dst_reg : 6
//     bit      18  uint32_t      dst_reg_am : 1
//     bit      19  uint32_t      must_be_one : 1
//     bits 20..24  uint32_t      const_index : 5
//     bits 25..26  uint32_t      const_index_sel : 2
//     bits 27..29  uint32_t      prefetch_count : 3     (value is count-1)
//     bits 30..31  uint32_t      src_swiz : 2
//   dword_1  (ucode.h:761-771, 32 bits exactly)
//     bits  0..11  uint32_t      dst_swiz : 12           <- dest_swizzle()
//     bit      12  uint32_t      fomat_comp_all : 1      [sic] is_signed()
//     bit      13  uint32_t      num_format_all : 1     is_normalized()
//     bit      14  SignedRepeatingFractionMode signed_rf_mode_all : 1
//     bit      15  uint32_t      is_index_rounded : 1
//     bits 16..21  xenos::VertexFormat format : 6       <- data_format()
//     bits 22..23  uint32_t      reserved2 : 2
//     bits 24..29  int32_t       exp_adjust : 6         (signed, [-32,31])
//     bit      30  uint32_t      is_mini_fetch : 1
//     bit      31  uint32_t      is_predicated : 1
//   dword_2  (ucode.h:773-775, 32 bits exactly)
//     bits  0.. 7  uint32_t      stride : 8              <- stride(), DWORDS
//     bits  8..30  int32_t       offset : 23             <- offset(), DWORDS
//     bit      31  uint32_t      pred_condition : 1
//
// UNITS - this is the field the old refusal got wrong, and it is the one that
// would have silently rendered vertices from the wrong offset with no error:
// `stride` is a Dword count, not a byte count (ucode.h:737 "Dword stride,
// [0, 255]"), and `offset` is a Dword offset (ucode.h:741 "Dword offset,
// [-4194304, 4194303]"). The interpreter keeps everything in dwords:
//   vfetch_address_dwords = instr.stride() * vertex_index + fetch_constant.address
//       (shader_interpreter.cc:1013-1014)
//   dword_0_address_dwords = int32(vfetch_address_dwords) + instr.offset()
//       (shader_interpreter.cc:1034-1035)
//   bounds: dword_address >= fetch_constant.address && < address + size
//       (shader_interpreter.cc:1033 for the end, :1042-1043 for the test)
//   the endian swap is applied to the DWORD read at that dword index
//       (shader_interpreter.cc:1048, xenos::GpuSwap)
// so the conversion to bytes happens exactly once, here: strideBytes = stride*4
// and offsetBytes = offset*4. A guest fetch constant's `address` is likewise
// dwords (xenos.h:1120 "address in dwords") and is scaled by <<2 only at the
// byte-range boundary (d3d12_command_processor.cc:2231-2232).
//
// The fetch-constant slot is const_index*3 + const_index_sel
// (ucode.h:705-707), which is why the block is 96 slots and not 32: the 2-bit
// select picks one of three 8-byte constants per 5-bit index, matching
// xenos.h:1110 kVertexFetchConstantCount = 3 * 32 and register_file.h:60's
// `index < 96`.
//
// METHOD - how to know which of the two words at a given program slot is the
// FETCH word and which is the ALU word. The program is triples of 32-bit words
// indexed at &ucode_[3*n] (xenia/gpu/shader_interpreter.cc:95-96, and
// xenia.h:28-29), and selection is per-execution, from the enclosing control
// flow instruction's sequence field:
//   if ((cf_exec.sequence() >> (exec_index << 1)) & 0b01) -> FETCH word
//   else                                                   -> ALU word
//       (shader_interpreter.cc:97)
// and only the fetch word is examined for a vertex fetch:
//   if (fetch_instr.opcode() == ucode::FetchOpcode::kVertexFetch) (…cc:105)
// Note the opcode test is against ZERO (ucode.h:531-532
// `kVertexFetch = 0`), not against a nonzero opcode. The 6-bit `format` field
// is a DIFFERENT bitfield (ucode.h:766) and 0 there means
// xenos::VertexFormat::kUndefined (xenos.h:603) - see the DecodeVertexFetch
// note in the F-632 merge report; conflating the two is a category error.
//
// ControlFlowInstruction is 2 dwords (ucode.h:508-518) with the 4-bit opcode
// in dword_1 bits 12..15 (ucode.h:512-516). ControlFlowExecInstruction packs
// (ucode.h:238-243):
//   dword_0 bits  0..11 address_ : 12, 12..14 count_ : 3,
//                bit 15 is_yield_ : 1, 16..27 sequence_ : 12, 28..31 vc_hi_ : 4
//   dword_1 bits  0.. 1 vc_lo_ : 2, ... 30..31 opcode_ : 4
// The exec-bearing opcodes are kExec=1, kExecEnd=2, kCondExec=3,
// kCondExecEnd=4, kCondExecPred=5, kCondExecPredEnd=6 (ucode.h:96-130);
// kLoopStart=7 and above do not execute an instruction list.
constexpr uint32_t kCpCfExecFirst = 1u;  // ucode.h:96
constexpr uint32_t kCpCfExecLast = 6u;   // ucode.h:130
constexpr uint32_t kCpFetchOpcodeVertexFetch = 0u;  // ucode.h:532

// One decoded vfetch, as a member of the program (not of a draw).
//
// F-649: `dstReg`/`srcReg`/`srcSwizzle`/`predCondition`/`indexRounded` were NOT
// decoded here before this change, and the omission carried a comment claiming
// the per-attribute decode "is the renderer's job (src/renderer/
// vertex_decode.*)". That file exists and does own the vf -> component/DXGI
// mapping, but it does NOT read dst_reg: `dstRegister` is decoded on the
// renderer side by src/renderer/xenos_microcode.h's DecodedInstruction, a
// DIFFERENT struct fed by a DIFFERENT walk, and none of it reached
// DrawCapturedCommand at all. The deferral therefore named an owner that did
// not cover the field. The fields are DECODED HERE now because the bits are
// right here in dword_0; the SEMANTIC they do not carry (VertexFetchInstruction
// has NO element-index field - see the full layout at :927-957) is still the
// parser's job and is NOT invented.
struct CpVertexFetchInstr {
  uint32_t execBlock = 0;  // which CF_EXEC referenced it
  uint32_t execIndex = 0;  // position within that exec
  uint32_t slotIndex = 0;  // fetch_constant_index() = idx*3 + sel, [0,95]
  uint32_t opcode = 0;     // 5-bit; 0 == kVertexFetch
  uint32_t formatXenos = 0;// 6-bit xenos::VertexFormat
  uint32_t strideDwords = 0;// 8-bit, DWORDS (ucode.h:773)
  int32_t offsetDwords = 0; // 23-bit signed, DWORDS (ucode.h:774)
  uint32_t destSwizzle = 0; // 12-bit (ucode.h:761)
  // F-649: dword_0's register half (ucode.h:747-759). `dstReg` is the field
  // this change exists for: dest(), ucode.h:709, dword_0 bits 12..17.
  uint32_t dstReg = 0;      // 6-bit, dword_0[12..17]
  uint32_t dstRegAm = 0;    // 1-bit, dword_0[18]
  uint32_t srcReg = 0;      // 6-bit, dword_0[5..10]
  uint32_t srcRegAm = 0;    // 1-bit, dword_0[11]
  uint32_t srcSwizzle = 0;  // 2-bit, dword_0[30..31] (absolute, one component)
  uint32_t isMiniFetch = 0;
  uint32_t isPredicated = 0;
  uint32_t conditional = 0;// 1 = inside a kCondExec* block (may not run)
  // F-649: the two predicate operands, so a consumer can tell WHICH side of the
  // comparison this fetch is on rather than re-deriving it from the CF word.
  uint32_t predCondition = 0; // 1-bit, dword_2[31]
  uint32_t indexRounded = 0;  // 1-bit, dword_1[15]
};

// The complete vertex descriptor the render path is waiting for.
struct CpVertexDescriptor {
  uint32_t slotIndex = 0;      // fetch-constant slot the vfetch bound to
  uint32_t baseVa = 0;         // guest VA of the stream (from the slot)
  uint32_t sizeBytes = 0;      // from the slot (sizeWords << 2)
  uint32_t strideBytes = 0;    // stride() * 4   (ucode.h:773, dwords)
  int32_t offsetBytes = 0;     // offset() * 4   (ucode.h:774, dwords)
  uint32_t formatXenos = 0;    // 6-bit (ucode.h:766)
  uint32_t dxgiFormat = 0;     // mapped, see CpXenosFormatToDxgi
  uint32_t destSwizzle = 0;    // 12-bit (ucode.h:761)
  uint32_t vertexCount = 0;    // VGT_DRAW_INITIATOR.num_indices for indexed draws
  uint32_t endian = 0;         // from the slot (xenos.h:1122)
  uint32_t miniFetch = 0;      // vfetch_mini vs vfetch_full
  uint32_t predicated = 0;
  // F-649: the fetch instruction's own register half, carried so the consumer
  // can name WHICH register each fetch writes instead of re-walking the
  // microcode body it already had. Provenance is dword_0 (ucode.h:747-759),
  // read at the decode site; `elementIndex` is POSITIONAL (the `made` counter),
  // because the instruction carries no element-index field.
  uint32_t elementIndex = 0;   // ordinal among the program's fetches
  uint32_t dstReg = 0;         // dword_0[12..17]; dest(), ucode.h:709
  uint32_t dstRegAm = 0;       // dword_0[18]
  uint32_t srcReg = 0;         // dword_0[5..10]; src(), ucode.h:714
  uint32_t srcRegAm = 0;       // dword_0[11]
  uint32_t srcSwizzle = 0;     // dword_0[30..31]
  uint32_t predCondition = 0;  // dword_2[31]
  uint32_t indexRounded = 0;   // dword_1[15]
  uint32_t conditional = 0;    // 1 = enclosing CF was kCondExec* (may not run)
  // F-632: false means the 6-bit format is not one of the 16 named in
  // xenos.h:602-619 (kUndefined=0 included). dxgiFormat is then 0 and MUST NOT
  // be used to build an input layout - a mapped 0 would read as a valid format.
  bool isKnownFormat = false;
};

// xenos::VertexFormat (xenos.h:602-619) -> DXGI_FORMAT_*.
//
// VERIFIED, NOT ASSUMED: every value below was read out of the installed SDK
// header, not typed from memory, because this project has twice shipped
// hand-written format tables that disagreed with the SDK and both times the
// failure was silent.
//   C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\shared\dxgiformat.h
// line numbers in the trailing comments are that file's line numbers.
uint32_t CpXenosFormatToDxgi(uint32_t fmt, bool *known) {
  *known = true;
  switch (fmt) {
    // gpu/xenos.h:604  k_8_8_8_8
    case 6:  return 28;  // DXGI_FORMAT_R8G8B8A8_UNORM      (dxgiformat.h:41)
    // gpu/xenos.h:605  k_2_10_10_10
    case 7:  return 24;  // DXGI_FORMAT_R10G10B10A2_UNORM   (dxgiformat.h:37)
    // gpu/xenos.h:606  k_10_11_11  - 32-bit float-packed, 3 components
    case 16: return 26;  // DXGI_FORMAT_R11G11B10_FLOAT     (dxgiformat.h:39)
    // gpu/xenos.h:607  k_11_11_10  - same container
    case 17: return 26;  // DXGI_FORMAT_R11G11B10_FLOAT     (dxgiformat.h:39)
    // gpu/xenos.h:608  k_16_16
    case 25: return 35;  // DXGI_FORMAT_R16G16_UNORM        (dxgiformat.h:35)
    // gpu/xenos.h:609  k_16_16_16_16
    case 26: return 11;  // DXGI_FORMAT_R16G16B16A16_UNORM  (dxgiformat.h:11)
    // gpu/xenos.h:610  k_16_16_FLOAT
    case 31: return 34;  // DXGI_FORMAT_R16G16_FLOAT        (dxgiformat.h:34)
    // gpu/xenos.h:611  k_16_16_16_16_FLOAT
    case 32: return 10;  // DXGI_FORMAT_R16G16B16A16_FLOAT  (dxgiformat.h:10)
    // gpu/xenos.h:612  k_32
    case 33: return 42;  // DXGI_FORMAT_R32_UINT            (dxgiformat.h:42)
    // gpu/xenos.h:613  k_32_32
    case 34: return 17;  // DXGI_FORMAT_R32G32_UINT         (dxgiformat.h:17)
    // gpu/xenos.h:614  k_32_32_32_32
    case 35: return 3;   // DXGI_FORMAT_R32G32B32A32_UINT   (dxgiformat.h:3)
    // gpu/xenos.h:615  k_32_FLOAT
    case 36: return 41;  // DXGI_FORMAT_R32_FLOAT           (dxgiformat.h:41)
    // gpu/xenos.h:616  k_32_32_FLOAT
    case 37: return 16;  // DXGI_FORMAT_R32G32_FLOAT        (dxgiformat.h:16)
    // gpu/xenos.h:617  k_32_32_32_32_FLOAT
    case 38: return 2;   // DXGI_FORMAT_R32G32B32A32_FLOAT  (dxgiformat.h:2)
    // gpu/xenos.h:618  k_32_32_32_FLOAT
    case 57: return 6;   // DXGI_FORMAT_R32G32B32_FLOAT     (dxgiformat.h:6)
    default:
      // gpu/xenos.h:603 kUndefined = 0, and any code absent from :602-619.
      *known = false;
      return 0u;
  }
}

// F-648: the TIGHT byte size of an xenos::VertexFormat, in bytes.
//
// Derived from the reference, not invented. xenos::GetVertexFormatNeededWords
// (xenos.h:648-673) returns the number of 32-bit WORDS a fetch of that format
// occupies for the components actually used, and this is that value times 4 -
// the same dword->byte conversion CpDecodeVertexDescriptor already applies to
// stride() (src/gpu_cp.cpp, "ucode.h:773 is DWORDS").
//
// It is the TIGHT size, which is deliberately NOT the stride. A vfetch's stride
// is the per-vertex ADVANCE of the stream while its format is the element that
// one instruction fetches, so stride > format is ordinary and expected: the
// remaining dwords of the vertex are fetched by the program's OTHER vfetch
// instructions or are padding. The invariant that must hold is therefore
// strideBytes >= formatBytes, and that is exactly what render_thread.cpp checks
// (src/render_thread.cpp, `vb-fmt-stride`), so a decode that produced an
// impossible pair is refused by name instead of drawn.
//
// MEASURED in build/w662.log over all 1,472 CP-DRAW-BRIDGE rows, two shapes:
//   1,468 rows  stride=8  vf=37 (k_32_32_FLOAT)      -> 2 words =  8 bytes
//       4 rows  stride=28 vf=57 (k_32_32_32_FLOAT)   -> 3 words = 12 bytes
// Both satisfy stride >= format. Returns 0 for kUndefined and for any code
// outside the named set, so 0 can be used as "no size" without a second test.
uint32_t CpXenosFormatBytes(uint32_t fmt) {
  switch (fmt) {
    case 6:  return 4;   // k_8_8_8_8        (xenos.h:604)
    case 7:  return 4;   // k_2_10_10_10     (xenos.h:605)
    case 16: return 4;   // k_10_11_11       (xenos.h:606) 32-bit float-packed
    case 17: return 4;   // k_11_11_10       (xenos.h:607) same container
    case 25: return 4;   // k_16_16          (xenos.h:608)
    case 26: return 8;   // k_16_16_16_16    (xenos.h:609)
    case 31: return 4;   // k_16_16_FLOAT    (xenos.h:610)
    case 32: return 8;   // k_16_16_16_16_FLOAT (xenos.h:611)
    case 33: return 4;   // k_32             (xenos.h:612)
    case 34: return 8;   // k_32_32          (xenos.h:613)
    case 35: return 16;  // k_32_32_32_32    (xenos.h:614)
    case 36: return 4;   // k_32_FLOAT       (xenos.h:615)
    case 37: return 8;   // k_32_32_FLOAT    (xenos.h:616)
    case 38: return 16;  // k_32_32_32_32_FLOAT (xenos.h:617)
    case 57: return 12;  // k_32_32_32_FLOAT (xenos.h:618)
    default: return 0u;  // kUndefined (xenos.h:603) and anything unnamed
  }
}

const char *CpXenosFormatName(uint32_t fmt) {
  switch (fmt) {
    case 0:  return "kUndefined";
    case 6:  return "k_8_8_8_8";
    case 7:  return "k_2_10_10_10";
    case 16: return "k_10_11_11";
    case 17: return "k_11_11_10";
    case 25: return "k_16_16";
    case 26: return "k_16_16_16_16";
    case 31: return "k_16_16_FLOAT";
    case 32: return "k_16_16_16_16_FLOAT";
    case 33: return "k_32";
    case 34: return "k_32_32";
    case 35: return "k_32_32_32_32";
    case 36: return "k_32_FLOAT";
    case 37: return "k_32_32_FLOAT";
    case 38: return "k_32_32_32_32_FLOAT";
    case 57: return "k_32_32_32_FLOAT";
    default: return "kUnknown";
  }
}

// Sign-extend the 23-bit signed `offset` field at dword_2 bits 8..30
// (ucode.h:774). Written as shifts, not as a cast of a masked word, because a
// plain `>>` on a signed 23-bit field would be implementation-defined for the
// fill; this is exact and the width is pinned by the mask.
inline int32_t CpSignExtend23(uint32_t v) {
  const uint32_t b = v & 0x007FFFFFu;
  return (b & 0x00400000u) ? (static_cast<int32_t>(b) - 0x00800000) 
                           : static_cast<int32_t>(b);
}

// Walk the captured vertex program and collect every kVertexFetch instruction
// that the sequencer would actually execute as a FETCH word.
//
// This is a STATIC walk of the instruction stream, not an execution: it visits
// every CF_EXEC/kCondExec* block in program order and inspects the words the
// sequence bits mark as fetch words. It does not evaluate predicates, so a
// vfetch inside a predicated block is reported with conditional=1 rather than
// silently treated as unconditional. `blocks`/`found` are out-params so the
// caller can tell "no exec blocks at all" (the walk is wrong) from "exec blocks
// but no vfetch" (not a vertex program) - the two have different fixes.
uint32_t CpDecodeVertexFetchProgram(CpVertexFetchInstr *out, uint32_t maxOut,
                                    uint32_t *blocksOut) {
  uint32_t blocks = 0u;
  if (blocksOut != nullptr) {
    *blocksOut = 0u;
  }
  std::lock_guard<std::mutex> lock(g_microcodeMutex);
  if (!g_microcode[0].present || g_microcode[0].captured == 0u) {
    return 0u;
  }
  const uint32_t *w = g_microcode[0].dwords;
  const uint32_t capDwords = g_microcode[0].captured;
  const uint32_t slots = capDwords / 3u;  // one triple per program slot
  uint32_t found = 0u;
  for (uint32_t s = 0u; s + 1u < slots; ++s) {
    // ControlFlowInstruction = 2 dwords (ucode.h:508-518, static_assert :518);
    // opcode is dword_1 bits 12..15 (ucode.h:512-516). Read from the pair at
    // the slot, matching how the interpreter walks the same array.
    const uint32_t cf0 = w[2u * s];
    const uint32_t cf1 = w[2u * s + 1u];
    const uint32_t cfOp = (cf1 >> 12) & 0xFu;
    if (cfOp < kCpCfExecFirst || cfOp > kCpCfExecLast) {
      continue;
    }
    ++blocks;
    const uint32_t addr = cf0 & 0xFFFu;            // address_ : 12
    const uint32_t count = (cf0 >> 12) & 0x7u;     // count_ : 3
    const uint32_t seq = (cf0 >> 16) & 0xFFFu;      // sequence_ : 12
    for (uint32_t e = 0u; e < count; ++e) {
      if (((seq >> (e << 1)) & 0x1u) == 0u) {
        continue;  // ALU word, not a fetch word (shader_interpreter.cc:97)
      }
      const uint32_t a = addr + e;
      if (a >= slots) {
        // The exec names a program slot past the capture window. Counted, never
        // read - the triple is not in hand.
        g_vfetchTrunc.fetch_add(1, std::memory_order_relaxed);
        continue;
      }
      const uint32_t *t = &w[3u * a];  // &ucode_[3*n] (…cc:95-96)
      const uint32_t op = t[0] & 0x1Fu;  // opcode_value : 5 (ucode.h:747)
      if (op != kCpFetchOpcodeVertexFetch) {
        continue;  // texture fetch etc. (…cc:105, :107-113)
      }
      if (found >= maxOut) {
        break;
      }
      CpVertexFetchInstr &v = out[found];
      v.execBlock = s;
      v.execIndex = e;
      v.opcode = op;
      // fetch_constant_index() = const_index*3 + const_index_sel
      // (ucode.h:705-707); both fields are guest-supplied so the sum is
      // bounds-checked against the 96 the block actually has (ucode.h:1110,
      // register_file.h:60) instead of asserted.
      const uint32_t ci = (t[0] >> 20) & 0x1Fu;   // const_index : 5
      const uint32_t cs = (t[0] >> 25) & 0x3u;    // const_index_sel : 2
      const uint32_t merged = ci * 3u + cs;
      v.slotIndex = (merged < 96u) ? merged : 95u;  // clamp, do not assert
      // F-649: dword_0's register half (ucode.h:747-759), the fields this walk
      // used to skip. `dst_reg` is bits 12..17 - the SAME dword the const_index
      // read above comes from, so this costs no new read and cannot disagree
      // with it about which word it is.
      // MEASURED against build/w689.log (raw bodies at 12:50:44.501): for the
      // three vfetch words the guest issued, bit 19 (`must_be_one`) is 1 on all
      // three, which is the hardware's own consistency check on this layout.
      // dword_0 was 0x30081000 (dst_reg=1), 0x00080000 (dst_reg=0) and
      // 0x00080000 (dst_reg=0) respectively.
      v.srcReg = (t[0] >> 5) & 0x3Fu;       // src_reg : 6
      v.srcRegAm = (t[0] >> 11) & 0x1u;     // src_reg_am : 1
      v.dstReg = (t[0] >> 12) & 0x3Fu;      // dst_reg : 6
      v.dstRegAm = (t[0] >> 18) & 0x1u;     // dst_reg_am : 1
      v.srcSwizzle = (t[0] >> 30) & 0x3u;   // src_swiz : 2
      v.formatXenos = (t[1] >> 16) & 0x3Fu;  // format : 6 (ucode.h:766)
      v.strideDwords = t[2] & 0xFFu;         // stride : 8 (ucode.h:773)
      v.offsetDwords = CpSignExtend23(t[2] >> 8);  // offset : 23 (ucode.h:774)
      v.destSwizzle = t[1] & 0xFFFu;         // dst_swiz : 12 (ucode.h:761)
      v.indexRounded = (t[1] >> 15) & 0x1u;  // is_index_rounded : 1 (ucode.h:765)
      v.isMiniFetch = (t[1] >> 30) & 0x1u;   // ucode.h:769
      v.isPredicated = (t[1] >> 31) & 0x1u;  // ucode.h:770
      v.predCondition = (t[2] >> 31) & 0x1u; // pred_condition : 1 (ucode.h:775)
      v.conditional = (cfOp == 2u) ? 0u : 1u;  // kExecEnd is unconditional too
      ++found;
    }
  }
  if (blocksOut != nullptr) {
    *blocksOut = blocks;
  }
  return found;
}

// The two refusals, kept APART. `reason` is one of:
//   "no-instruction"  - the program was walked end to end and no
//                       kVertexFetch word was executed as a fetch word.
//   "unreadable"      - one or more kVertexFetch words WERE found, but the
//                       fields could not be resolved to a descriptor.
// The old single "pkt=" reason conflated these; a soak that counted it could
// not tell a walk bug from an undecodable instruction.
void CpNoteMicrocodeUnsupported(const char *reason, uint32_t slot,
                                uint32_t physBase, uint32_t sizeWords) {
  // The g_vfetchUnreadable counter is NOT bumped here: it is already
  // incremented once per unresolvable instruction inside
  // CpDecodeVertexDescriptor, so bumping it again at refusal level would count
  // the same failure twice and make the census lie about its own magnitude.
  // This uses a private counter purely to bound the log.
  static std::atomic<uint32_t> s_none{0};
  static std::atomic<uint32_t> s_unreadable{0};
  const bool unreadable = (std::strcmp(reason, "unreadable") == 0);
  std::atomic<uint32_t> &logCounter = unreadable ? s_unreadable : s_none;
  if (!unreadable) {
    g_vfetchNone.fetch_add(1, std::memory_order_relaxed);
  }
  const uint32_t n = logCounter.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP-MICROCODE-UNSUPPORTED #{} reason={} slot={} base={:08X} "
        "sizeWords={} - reason=no-instruction means the captured program was "
        "walked and NO ucode::FetchOpcode::kVertexFetch (==0, ucode.h:532) was "
        "found among the fetch words; reason=unreadable means one WAS found but "
        "its stride/format/offset could not be resolved. The field layout is "
        "gpu/ucode.h:745-777 (stride:8 dword_2[0..7], offset:23 dword_2[8..30], "
        "format:6 dword_1[16..21], dst_swiz:12 dword_1[0..11]).",
        n, reason, slot, physBase, sizeWords);
  }
  // F-612 tracker, preserved: the historical single counter is still bumped so
  // its gate line keeps its meaning. It is no longer the thing a soak reads -
  // g_vfetchNone and g_vfetchUnreadable are, and they are not equal to each
  // other or to this sum.
  g_microcodeUnsup.fetch_add(1, std::memory_order_relaxed);
}

// F-612: decode the fetch/VB constant block into vertex descriptors. Layout is
// upstream's own, read through the same accessor upstream uses
// (register_file.h:59-67 GetVertexFetch: 2 dwords from register
// 0x4800 + 2*index, index < 96). Returns the number of slots that decode to
// FetchConstantType::kVertex and were written into `out`.
uint32_t CpDecodeVertexFetchSlots(CpVertexFetchSlot *out, uint32_t maxOut) {
  // A slot is only claimed if the guest has written it. g_xenosReg starts zeroed
  // and is never cleared, so "unwritten" and "written as 0" are the same thing
  // on this hardware path - which is exactly what a kInvalidVertex slot
  // (type 1) means, so no slot is distinguished by a written-bit here.
  uint32_t found = 0;
  for (uint32_t i = 0; i < 96u; ++i) {
    const uint32_t d0 = CpRegPeek(kRegFetchVbFirst + 2u * i);
    const uint32_t d1 = CpRegPeek(kRegFetchVbFirst + 2u * i + 1u);
    const uint32_t type = d0 & 0x3u;            // xenos.h:1119
    if (type != 3u) {                            // FetchConstantType::kVertex
      continue;                                  // (xenos.h:1106)
    }
    if (found >= maxOut) {
      break;
    }
    CpVertexFetchSlot &s = out[found];
    s.index = i;
    s.type = type;
    s.address = d0 >> 2;                         // 30-bit, in DWORDS (xenos.h:1120)
    s.endian = d1 & 0x3u;                        // (xenos.h:1122)
    s.sizeWords = (d1 >> 2) & 0x00FFFFFFu;       // 24-bit, in WORDS (xenos.h:1123)
    s.physBase = s.address << 2;                 // d3d12_command_processor.cc:2231
    // F-680: `physBase` is a guest PHYSICAL address, so it goes through the one
    // view->pool rule, not through `| 0xC0000000`. See CpPhysToPoolVa's header
    // for the three measured links and for the call-site classification.
    s.vaBase = CpPhysToPoolVa(s.physBase, "FETCHVB-CONSTANTS");
    s.sizeBytes = static_cast<uint64_t>(s.sizeWords) << 2;
    ++found;
  }
  return found;
}

// F-632: read ONE fetch-constant slot by its raw index. CpDecodeVertexFetchSlots
// above compacts to only the kVertex slots, so it cannot answer "what is slot
// 17" - and a vfetch names its slot by index (ucode.h:705-707), so the join has
// to be by index, not by position in a compacted list.
bool CpReadVertexFetchSlot(uint32_t index, CpVertexFetchSlot *out) {
  if (index >= 96u) {  // register_file.h:60 asserts index < 96; we clamp instead
    return false;
  }
  const uint32_t d0 = CpRegPeek(kRegFetchVbFirst + 2u * index);
  const uint32_t d1 = CpRegPeek(kRegFetchVbFirst + 2u * index + 1u);
  const uint32_t type = d0 & 0x3u;      // xenos.h:1119
  if (type != 3u) {                    // FetchConstantType::kVertex (xenos.h:1106)
    return false;
  }
  out->index = index;
  out->type = type;
  out->address = d0 >> 2;                        // 30-bit DWORDS (xenos.h:1120)
  out->endian = d1 & 0x3u;                       // (xenos.h:1122)
  out->sizeWords = (d1 >> 2) & 0x00FFFFFFu;      // 24-bit WORDS (xenos.h:1123)
  out->physBase = out->address << 2;             // d3d12_command_processor.cc:2231
  // F-680: same rule as CpDecodeVertexFetchSlots above - one translation, both
  // decoders, so the compacted list and the by-index read cannot name different
  // addresses for the same slot.
  out->vaBase = CpPhysToPoolVa(out->physBase, "FETCHVB-SLOT");
  out->sizeBytes = static_cast<uint64_t>(out->sizeWords) << 2;
  return true;
}

// F-632: join a decoded vfetch to its fetch-constant slot and produce the
// complete descriptor. This is the function the render path has been waiting
// for since F-612. Every field's provenance, in order:
//
//   baseVa / sizeBytes / endian  <- the fetch CONSTANT (register block
//       0x4800-0x48BF, read through the same accessors upstream reads it with,
//       register_file.h:59-67), joined by slotIndex.
//   strideBytes                  <- instr.stride() * 4. stride() is 8 bits
//       (ucode.h:773) and is a DWORD count (ucode.h:737), the dword the
//       interpreter actually indexes with (…cc:1013-1014). The *4 is the only
//       place the dword->byte conversion happens.
//   offsetBytes                  <- instr.offset() * 4. 23-bit signed
//       (ucode.h:774, dwords per ucode.h:741), sign-extended, added to the
//       address by the interpreter at …cc:1034-1035.
//   formatXenos / dxgiFormat     <- instr.data_format(), 6 bits (ucode.h:766),
//       xenos::VertexFormat (xenos.h:602-619), mapped by
//       CpXenosFormatToDxgi against the installed SDK.
//   destSwizzle                  <- instr.dest_swizzle(), 12 bits (ucode.h:761).
//   vertexCount                  <- the DRAW's index count, NOT the program. A
//       program does not know how many vertices a draw will feed it; that is
//       VGT_DRAW_INITIATOR.num_indices, which the bridge already holds.
//
// Returns the number of descriptors written. `why` is stamped on the log line
// only.
//
// F-649 CORRECTION. This comment used to read:
//
//   "Note what is NOT here: the vfetch's own `dst_reg`/`dest()` and the
//    per-component `num_format_all`/`signed_rf_mode_all` decodes are not folded
//    into the descriptor - this describes the STREAM, and the attribute-level
//    decode is the renderer's job (src/renderer/vertex_decode.*)."
//
// The claim was CHECKED and it was FALSE as a deferral, though true as a
// statement about this file's contents:
//   * `src/renderer/vertex_decode.*` EXISTS and does own the vf -> component /
//     DXGI mapping (DecodeVertexFormat, VertexFormatDesc). But it does NOT read
//     dst_reg anywhere - the whole point of the deferral was to leave the
//     attribute decode there, and dst_reg is the attribute's destination.
//   * `dst_reg` IS decoded on the renderer side, but into a DIFFERENT struct:
//     src/renderer/xenos_microcode.h's DecodedInstruction::dstRegister, fed by a
//     DIFFERENT walk of the same microcode.
//   * NEITHER of those fed DrawCapturedCommand, so the field reached no consumer
//     at all. Deferring it to an owner that does not carry it is not a
//     deferral; it is a drop.
//
// So dst_reg (and the rest of dword_0) is decoded HERE now, because the bits
// are in the word this function already reads. What is STILL deliberately not
// done here, and remains the parser's job, is turning dst_reg into a NAME: the
// instruction carries no element index and no semantic, so this descriptor can
// say "fetch 1 wrote register 1 with format 57" and nothing more. Inventing
// "POSITION" from a register number would be exactly the F-609 fabrication the
// charter forbids, and the reference does not do it either - it takes its
// interpolant set from SQ_INTERPOLATOR_CNTL
// (.research/xenia/src/xenia/gpu/d3d12/pipeline_cache.cc:882 and :915).
uint32_t CpDecodeVertexDescriptor(CpVertexDescriptor *out, uint32_t maxOut,
                                  uint32_t vertexCount, const char *why,
                                  uint32_t *blocksOut) {
  CpVertexFetchInstr instrs[32];
  const uint32_t n = CpDecodeVertexFetchProgram(instrs, 32u, blocksOut);
  if (n == 0u) {
    return 0u;
  }
  g_vfetchFound.fetch_add(n, std::memory_order_relaxed);
  uint32_t made = 0u;
  static std::atomic<uint32_t> s_desc{0};
  const uint32_t d = s_desc.fetch_add(1, std::memory_order_relaxed) + 1u;
  for (uint32_t i = 0u; i < n; ++i) {
    const CpVertexFetchInstr &v = instrs[i];
    CpVertexFetchSlot slot;
    if (!CpReadVertexFetchSlot(v.slotIndex, &slot)) {
      // Found the instruction but cannot resolve its slot. Different fix from
      // "no instruction", so it is counted apart (g_vfetchUnreadable).
      const uint32_t c =
          g_vfetchUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
      if (c <= 8u || (c % 200u) == 0u) {
        MCLA_LOG_WARN(
            "CP-FETCHVB-INSTR #{} why={} vfetch={} slot={} could-not-resolve - "
            "a kVertexFetch was decoded (opcode=0, ucode.h:532) naming the "
            "fetch-constant slot above, but that slot does not decode to "
            "FetchConstantType::kVertex (xenos.h:1106) in the 0x4800 block.",
            c, why, i, v.slotIndex);
      }
      continue;
    }
    if (made >= maxOut) {
      break;
    }
    CpVertexDescriptor &o = out[made];
    o.slotIndex = v.slotIndex;
    o.baseVa = slot.vaBase;
    o.sizeBytes = static_cast<uint32_t>(slot.sizeBytes);
    o.strideBytes = v.strideDwords * 4u;  // ucode.h:773 is DWORDS (ucode.h:737)
    o.offsetBytes = v.offsetDwords * 4;   // ucode.h:774 is DWORDS (ucode.h:741)
    o.formatXenos = v.formatXenos;
    o.dxgiFormat = CpXenosFormatToDxgi(v.formatXenos, &o.isKnownFormat);
    o.destSwizzle = v.destSwizzle;
    o.vertexCount = vertexCount;
    o.endian = slot.endian;
    o.miniFetch = v.isMiniFetch;
    o.predicated = v.isPredicated;
    // F-649: the register half, carried rather than dropped. `elementIndex` is
    // `made` BEFORE the increment, so it is the fetch's ordinal among the
    // program's fetches in program order - POSITIONAL, because the instruction
    // has no element-index field (ucode.h:745-777 is the complete struct).
    o.elementIndex = made;
    o.dstReg = v.dstReg;
    o.dstRegAm = v.dstRegAm;
    o.srcReg = v.srcReg;
    o.srcRegAm = v.srcRegAm;
    o.srcSwizzle = v.srcSwizzle;
    o.predCondition = v.predCondition;
    o.indexRounded = v.indexRounded;
    o.conditional = v.conditional;
    ++made;
    if (v.strideDwords == 0u) {
      g_vfetchStride0.fetch_add(1, std::memory_order_relaxed);
    }
    if (!o.isKnownFormat) {
      g_vfetchBadFmt.fetch_add(1, std::memory_order_relaxed);
    }
    if (d <= 8u || (d % 200u) == 0u) {
      MCLA_LOG_WARN(
          "CP-FETCHVB-DESC #{} why={} instr={} execBlock={} execIndex={} "
          "slot={} vaBase={:08X} physBase={:08X} sizeBytes={} "
          "strideDwords={} strideBytes={} offsetDwords={} offsetBytes={} "
          "vf={}({}) dxgi={} dstSwizzle={:03X} miniFetch={} predicated={} "
          "conditional={} vertexCount={} endian={}",
          d, why, i, v.execBlock, v.execIndex, v.slotIndex, o.baseVa,
          slot.physBase, o.sizeBytes, v.strideDwords, o.strideBytes,
          v.offsetDwords, o.offsetBytes, v.formatXenos,
          CpXenosFormatName(v.formatXenos), o.dxgiFormat, o.destSwizzle,
          v.isMiniFetch, v.isPredicated, v.conditional, vertexCount, o.endian);
    }
    g_vfetchDecoded.fetch_add(1, std::memory_order_relaxed);
  }
  return made;
}

// F-612: report the decoded descriptor for every kVertex slot. This is the real
// deliverable the render path is waiting for: base address (physical and the
// kernel-VA form the guest can actually be read through), byte length, and the
// endian swap - all upstream's own arithmetic, cited at each use.
void CpReportVertexFetchSlots(const char *why) {
  const uint32_t nFetch =
      g_fetchVbWrites.load(std::memory_order_relaxed);
  if (nFetch == 0u) {
    const uint32_t n =
        g_fetchVbNoVertex.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (n <= 8u || (n % 200u) == 0u) {
      MCLA_LOG_WARN(
          "CP-FETCHVB-DECODE #{} why={} slots=0 fetchVbWrites=0 - the block "
          "0x4800-0x48BF has never been written, so there is no vertex "
          "descriptor to decode. NOT a scan result; an absent fact.",
          n, why);
    }
    return;
  }
  CpVertexFetchSlot slots[8];
  const uint32_t n = CpDecodeVertexFetchSlots(slots, 8u);
  g_fetchVbSlots.fetch_add(n, std::memory_order_relaxed);
  if (n == 0u) {
    const uint32_t c =
        g_fetchVbNoVertex.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (c <= 8u || (c % 200u) == 0u) {
      MCLA_LOG_WARN(
          "CP-FETCHVB-DECODE #{} why={} slots=0 fetchVbWrites={} - the block "
          "IS written, but no slot decodes to FetchConstantType::kVertex, so "
          "these are texture/loop constants sharing the window, not a vertex "
          "stream.",
          c, why, nFetch);
    }
    return;
  }
  static std::atomic<uint32_t> s_dec{0};
  const uint32_t d = s_dec.fetch_add(1, std::memory_order_relaxed) + 1u;
  for (uint32_t i = 0; i < n; ++i) {
    const CpVertexFetchSlot &s = slots[i];
    if (d <= 8u || (d % 200u) == 0u) {
      MCLA_LOG_WARN(
          "CP-FETCHVB-DECODE #{} why={} slot={} endian={} physBase={:08X} "
          "vaBase={:08X} sizeWords={} sizeBytes={} addressInDwords={} "
          "count=UNKNOWN stride=UNKNOWN format=UNKNOWN",
          d, why, s.index, s.endian, s.physBase, s.vaBase, s.sizeWords,
          s.sizeBytes, s.address);
    }
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const bool inRange =
        (s.sizeBytes == 0u) || mem.IsValid(s.vaBase, s.sizeBytes);
    if (inRange) {
      g_fetchVbDecoded.fetch_add(1, std::memory_order_relaxed);
    } else {
      const uint32_t c =
          g_fetchVbUndecodable.fetch_add(1, std::memory_order_relaxed) + 1u;
      if (c <= 8u || (c % 200u) == 0u) {
        MCLA_LOG_WARN("CP-FETCHVB-OUT-OF-RANGE #{} slot={} vaBase={:08X} "
                      "sizeBytes={} (descriptor decoded but the range is not "
                      "in the guest window - NOT read)",
                      c, s.index, s.vaBase, s.sizeBytes);
      }
    }
  }
  // F-632: the named seam is closed. Where F-612 stopped here, the program is
  // now walked and the vfetch joined to the slot (CpDecodeVertexDescriptor), so
  // this path emits CP-FETCHVB-DESC rather than a refusal. The two refusal
  // reasons are still reachable and still counted SEPARATELY, and the
  // "nothing was found" case is now distinguishable from the "found but
  // unresolvable" case.
  if (!(g_microcodeHave.load(std::memory_order_relaxed) & 0x1u)) {
    return; // microcode-absent is reported by the draw bridge, not here.
  }
  uint32_t blocks = 0u;
  CpVertexDescriptor desc[8];
  // vertexCount is UNKNOWN on this path: this report runs off the fetch-constant
  // block, which no draw count has reached yet. The bridge fills the real one.
  // Zero is the honest value - the descriptor is still complete as a STREAM
  // description, and a zero count is not read as "one vertex".
  const uint32_t nDesc = CpDecodeVertexDescriptor(desc, 8u, 0u, why, &blocks);
  if (nDesc == 0u) {
    // Distinguish the two failures. blocks==0 means the walk found no exec
    // block at all, which points at the walk or at a non-vertex program; a
    // non-zero block count with zero descriptors means the program really has
    // no kVertexFetch, OR that its slots did not resolve - and that second case
    // is already counted inside CpDecodeVertexDescriptor as unreadable.
    if (blocks == 0u) {
      CpNoteMicrocodeUnsupported("no-instruction", slots[0].index,
                                 slots[0].physBase, slots[0].sizeWords);
    } else {
      // blocks>0, no descriptor: either no vfetch word, or every one of them
      // failed to resolve. The unreadable counter tells them apart downstream.
      if (g_vfetchUnreadable.load(std::memory_order_relaxed) == 0u) {
        CpNoteMicrocodeUnsupported("no-instruction", slots[0].index,
                                   slots[0].physBase, slots[0].sizeWords);
      }
    }
  }
}

// F-612: distinct-program census. The guest loads several programs (measured
// build/w658.log: vertex size_dwords of 24, 27 and 15, pixel 9), so a per-packet
// log cannot say how many there are. This prints one line the FIRST time a
// (type, dword count, first two body dwords) triple is seen, so the set of
// programs is countable without a flood - and a suppressed repeat stays
// countable because the total is on every line.
void CpNoteMicrocodeIdentity(uint32_t type, uint32_t total, uint32_t w0,
                             uint32_t w1) {
  struct Seen { uint32_t type, total, w0, w1; };
  static Seen seen[32]{};
  static uint32_t seenN = 0;
  for (uint32_t i = 0; i < seenN; ++i) {
    if (seen[i].type == type && seen[i].total == total && seen[i].w0 == w0 &&
        seen[i].w1 == w1) {
      return;
    }
  }
  if (seenN >= 32u) {
    return;
  }
  seen[seenN] = {type, total, w0, w1};
  const uint32_t id = ++seenN;
  MCLA_LOG_WARN(
      "CP-MICROCODE #{} shader={} totalDwords={} triples={} first={:08X} "
      "{:08X} distinct={} (F-612: the program is CAPTURED and retained, not "
      "discarded; no instruction field is decoded here)",
      id, type, total, total / 3u, w0, w1, seenN);
}

// F-612: PM4_IM_LOAD (0x27, pointer form) and PM4_IM_LOAD_IMMEDIATE (0x2B,
// embedded form). Both are implemented; the previous code read two dwords,
// printed them, and dropped the program on the floor.
//
// MEASURED (build/w658.log, 128 MB, 1,001,196 lines): opcode 0x27 has ZERO
// occurrences - the `CP-T3-CENSUS` table for that soak lists only 0x3E, 0x3C,
// 0x58, 0x60, 0x3B, 0x54, 0x46, 0x62, 0x61, 0x63, 0x7F, 0x45 - and 0x2B is
// dispatched, so it never reaches the census. Every CP-IM-LOAD line in that
// log is therefore 0x2B, i.e. the program is EMBEDDED IN THE PACKET. The
// arithmetic confirms it: `count=26 size_dwords=24` gives 1 header + 2 argument
// dwords + 24 body dwords = 27 = count+1, and `count=11 size_dwords=9` gives
// 12 = count+1. Under the 0x27 reading the address field would be the first
// argument dword, and it reads 0 and 1 - the shader type, not a pointer.
//
// So the program lives in the STREAM for the form actually observed, and at a
// guest address for the pointer form. Both are captured; the source is named on
// every line so a soak can prove which one fired. Upstream requires
// `count - 2 >= size_dwords` (command_processor.cc:1573) - enforced here as a
// BOUNDED refusal, never an assert on a guest-supplied value.
bool CpExecImLoad(uint32_t byteAddr, uint32_t count, uint32_t &outAdvance,
                  bool immediate) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t d0 = 0, hdr1 = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &d0) ||
      !mem.ReadU32BE(byteAddr + 8u, &hdr1)) {
    return false;
  }
  // 0x27 (:1534-1536): shader_type = addr_type & 0x3, addr = addr_type & ~0x3.
  // 0x2B (:1567):     shader_type = dword0 (the WHOLE dword upstream; the low
  //                   2 bits are what the enum can express, and masking is
  //                   what makes a 3 or larger value a countable refusal
  //                   rather than an unvalidated cast).
  const uint32_t type = d0 & 0x3u;
  const uint32_t srcPhys = immediate ? 0u : (d0 & ~0x3u);
  const uint32_t start = hdr1 >> 16;
  const uint32_t sizeDwords = hdr1 & 0xFFFFu;

  static std::atomic<uint32_t> s_im{0};
  const uint32_t n = s_im.fetch_add(1, std::memory_order_relaxed) + 1u;

  // Upstream: `assert_true(start == 0)` (:1540, :1571). A guest-supplied value
  // is never asserted on here - it is counted, and the load is refused loudly
  // because honouring a non-zero start would mean interpreting the body at an
  // offset upstream never validates.
  if (start != 0u) {
    g_imLoadStartSet.fetch_add(1, std::memory_order_relaxed);
    if (n <= 8u || (n % 50u) == 0u) {
      MCLA_LOG_WARN("CP-IM-LOAD #{} op=0x{:02X} start={} (non-zero: upstream "
                    "asserts start==0, command_processor.cc:1540,:1571) - "
                    "program NOT loaded",
                    n, immediate ? 0x2Bu : 0x27u, start);
    }
    outAdvance = count + 1u;
    return true;
  }
  if (type > 1u) {
    g_imLoadBadType.fetch_add(1, std::memory_order_relaxed);
    if (n <= 8u || (n % 50u) == 0u) {
      MCLA_LOG_WARN("CP-IM-LOAD #{} op=0x{:02X} shader_type={} (only 0=kVertex "
                    "and 1=kPixel exist, xenos.h:33-36; upstream returns false, "
                    ":1552-1554) - program NOT loaded",
                    n, immediate ? 0x2Bu : 0x27u, type);
    }
    outAdvance = count + 1u;
    return true;
  }
  if (sizeDwords == 0u) {
    g_imLoadZeroSize.fetch_add(1, std::memory_order_relaxed);
    if (n <= 8u || (n % 50u) == 0u) {
      MCLA_LOG_WARN("CP-IM-LOAD #{} op=0x{:02X} shader={} size_dwords=0 "
                    "(empty program) - nothing captured",
                    n, immediate ? 0x2Bu : 0x27u, type);
    }
    outAdvance = count + 1u;
    return true;
  }

  // Resolve WHERE the body is and prove it readable before capturing.
  uint32_t bodyAddr = 0;   // address actually read
  uint32_t shownAddr = 0;  // the address as the packet carried it
  bool kernelForm = false;
  bool ok = false;
  if (immediate) {
    // Embedded: 1 header dword + 2 argument dwords, then the program
    // (command_processor.cc:1574-1576 reads it at reader->read_ptr()).
    bodyAddr = byteAddr + 12u;
    shownAddr = 0u;
    // Upstream's own bound, :1573 - a body that does not fit the packet is not
    // a truncated read, it is a malformed packet.
    if (count >= 2u && (count - 2u) >= sizeDwords) {
      const uint64_t end = static_cast<uint64_t>(bodyAddr) +
                           (static_cast<uint64_t>(sizeDwords) << 2);
      if (end <= 0x100000000ull) {
        ok = mem.IsValid(bodyAddr, static_cast<size_t>(sizeDwords) << 2);
      }
    }
    if (!ok && n <= 8u) {
      MCLA_LOG_WARN("CP-IM-LOAD #{} op=0x2B shader={} size_dwords={} "
                    "packet_count={} at {:08X} - body does not fit the packet "
                    "or is unreadable; NOT captured",
                    n, type, sizeDwords, count, bodyAddr);
    }
  } else {
    shownAddr = srcPhys;
    // F-680: probe the pool byte first. `| 0xC0000000` was the wrong view and
    // this tree's flat window ACCEPTS a read there (it is inside the 4 GiB
    // reservation), so `mem.IsValid` used to say yes to an address holding
    // zeros and the capture below silently produced an all-zero program. The
    // raw-physical probe is KEPT as the second arm: it is what recovered the
    // programs on the traffic measured so far, and `kernelForm` still reports
    // which arm won, so removing it would be a regression dressed as a fix.
    const uint32_t kernel = CpPhysToPoolVa(srcPhys, "IM-LOAD");
    const uint64_t bytes = static_cast<uint64_t>(sizeDwords) << 2;
    const uint64_t end = static_cast<uint64_t>(srcPhys) + bytes;
    const bool poolArm = (kernel != 0u) && (kernel != srcPhys) &&
                         end <= 0x100000000ull &&
                         mem.IsValid(kernel, static_cast<size_t>(bytes));
    if (poolArm) {
      bodyAddr = kernel;
      kernelForm = true;
      ok = true;
    } else if (end <= 0x100000000ull &&
               mem.IsValid(srcPhys, static_cast<size_t>(bytes))) {
      bodyAddr = srcPhys;
      ok = true;
    }
    if (!ok && n <= 8u) {
      MCLA_LOG_WARN("CP-IM-LOAD #{} op=0x27 shader={} phys={:08X} "
                    "size_dwords={} - neither the pool byte {:08X} nor the raw "
                    "physical {:08X} is readable for {} bytes; NOT captured",
                    n, type, srcPhys, sizeDwords, kernel, srcPhys, sizeDwords);
    }
  }
  if (!ok) {
    g_imLoadUnreadable.fetch_add(1, std::memory_order_relaxed);
    outAdvance = count + 1u;
    return true;
  }

  // Capture. Never discard.
  const uint32_t want =
      (sizeDwords < kMicrocodeCaptureDwords) ? sizeDwords : kMicrocodeCaptureDwords;
  CpMicrocodeImage img{};
  img.present = 1u;
  img.type = type;
  img.srcPhys = shownAddr;
  img.srcVA = bodyAddr;
  img.vaIsKernel = kernelForm ? 1u : 0u;
  img.totalDwords = sizeDwords;
  img.embedded = immediate ? 1u : 0u;
  uint32_t captured = 0;
  for (uint32_t i = 0; i < want; ++i) {
    uint32_t w = 0;
    if (!mem.ReadU32BE(bodyAddr + i * 4u, &w)) {
      break;
    }
    img.dwords[i] = w;
    ++captured;
  }
  img.captured = captured;
  if (sizeDwords > want) {
    g_imLoadTruncated.fetch_add(1, std::memory_order_relaxed);
  }
  {
    std::lock_guard<std::mutex> lock(g_microcodeMutex);
    g_microcode[type] = img;
  }
  g_imLoadDwords.fetch_add(captured, std::memory_order_relaxed);
  if (type == 0u) {
    g_imLoadVertex.fetch_add(1, std::memory_order_relaxed);
    g_microcodeHave.fetch_or(0x1u, std::memory_order_relaxed);
  } else {
    g_imLoadPixel.fetch_add(1, std::memory_order_relaxed);
    g_microcodeHave.fetch_or(0x2u, std::memory_order_relaxed);
  }
  if (immediate) {
    g_imLoadImmediate.fetch_add(1, std::memory_order_relaxed);
  }
  CpNoteMicrocodeIdentity(type, sizeDwords,
                          captured > 0u ? img.dwords[0] : 0u,
                          captured > 1u ? img.dwords[1] : 0u);

  // F-612: CP-IM-LOAD now reports the CAPTURE, not just the header. The
  // pre-F-612 line named only the header, which is why a reader could not tell
  // whether the body had been read. First 8 packets in full, then a bounded
  // periodic line, so the row stays countable instead of flooding.
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP-IM-LOAD #{} op=0x{:02X} shader={} rawArg0={:08X} totalDwords={} "
        "triples={} captured={} at {:08X} (phys={:08X} kernelForm={}) "
        "first={:08X} {:08X} {:08X} vertexLoads={} pixelLoads={} unreadable={} "
        "zeroSize={} startSet={} truncated={}",
        n, immediate ? 0x2Bu : 0x27u, type, d0, sizeDwords, sizeDwords / 3u,
        captured, bodyAddr, shownAddr, kernelForm ? 1 : 0,
        captured > 0u ? img.dwords[0] : 0u, captured > 1u ? img.dwords[1] : 0u,
        captured > 2u ? img.dwords[2] : 0u,
        g_imLoadVertex.load(std::memory_order_relaxed),
        g_imLoadPixel.load(std::memory_order_relaxed),
        g_imLoadUnreadable.load(std::memory_order_relaxed),
        g_imLoadZeroSize.load(std::memory_order_relaxed),
        g_imLoadStartSet.load(std::memory_order_relaxed),
        g_imLoadTruncated.load(std::memory_order_relaxed));

    // F-612(b): the FULL captured body, on a NEW marker. The CP-IM-LOAD row above
    // is left byte-identical and names only dwords[0..2]; the CP-MICROCODE
    // census row (:1581) names only dwords[0..1]. Neither is in
    // tools/soak_census.py's tracked set (measured: 240 markers, 218 of them
    // parsed from PROGRAM_GUIDE sec 9; CP-IM-LOAD and CP-MICROCODE are in
    // neither the guide nor the hand batteries), so neither was extended - a
    // new marker carries the new evidence and the old rows stay byte-stable.
    //
    // WHY A FULL BODY AND NOT A WIDER HEAD: identity is not a head signature.
    // In the P2 pixel program the dwords past the head are CODE. Decoded with
    // this tree's own decoder (src/renderer/xenos_microcode.cpp:124-243, walked
    // as xenos_shader_ir.cpp:57-90 does), ComputeControlFlowByteBound = 12, so
    // the CF region is bytes 0-11 (Alloc(a=0,c=0), ExecEnd(a=1,c=1,seq=000)) and
    // exactly ONE instruction executes at bytes 12-23 with isFetch=0,
    // vectorOpcode=(w2>>24)&0x1F = Mad, scalarOpcode=(w0>>26)&0x3F =
    // RetainPrev, exportData=(w0>>15)&1 = 1 - a pixel export. A 3-dword window
    // cannot reach it, and 30052003 00001200 occurs 119x in the 2,733,492-byte
    // archive corpus with C2000000 following all 119 times and C4000000 never.
    //
    // TRUNCATION POLICY, and why it cannot be silent: the hex field is clamped
    // to kCpShaderBodyDumpDwords and the CLAMP IS PART OF THE ROW, twice over -
    // printDwords is how many dwords are actually in `body`, and printOmitted
    // is how many valid dwords of `captured` are NOT. There is no path on
    // which a clamped body can read as a complete one: printOmitted != 0 is
    // visible on the line, and captured/totalDwords are on the same line, so a
    // reader can always recompute what was withheld. Silent truncation would be
    // worse than the 3-dword print it replaces, because a 12-byte window at
    // least LOOKS short.
    //
    // WHY 64: the largest program measured so far is 27 dwords (build/w683.log
    // CP-IM-LOAD #3, totalDwords=27 captured=27), so 64 dwords clears every
    // measured program with 2.4x headroom while bounding the row at 64*9-1 =
    // 575 hex chars. A measured program that ever exceeds it is not silently
    // lost - printOmitted names the shortfall, which is the falsifier for this
    // constant: a non-zero printOmitted on any row means 64 is too small.
    //
    // CONTAINER CONSTANTS: this producer knows NONE of vsize / psize /
    // physicalOffset. PM4_IM_LOAD carries only start (hdr1>>16) and
    // sizeDwords (hdr1 & 0xFFFF) - command_processor.cc:1540 for 0x27 and
    // :1571 for 0x2B read no container header, and the 0x102A1100 container
    // lives in the guest image, not in the packet. So no field here is a
    // substituted zero for one of them; the byte-domain of the one container
    // constant this path DOES have is published as capturedBytes. Measured
    // correspondence, offered as a correspondence and not as a definition: the
    // P2 capture (totalDwords=9, captured=9, capturedBytes=36) matches the
    // container at guest VA 0x82803CF4 whose header parses (offset = VA -
    // 0x82000000 = 0x803CF4 in build/cache/mcla_pe.bin) as flags=102A1100,
    // vsize=248, psize=100, so=212, physicalOffset=64, shaderSize=36, and whose
    // body is 00000000 1001C400 22000000 C88FC000 00C06C6C 8B00FFFF 4E4A0000
    // 76E577D9 5AB27CFD - the 9 dwords this row prints.
    //
    // CADENCE: deliberately the SAME gate as the CP-IM-LOAD row it sits inside,
    // so the two are co-gated and every body line has a header line above it at
    // the same `#`, and so the added volume is exactly the rows below rather
    // than a second burst with its own shape. House rule "first N, then every
    // Mth": first 8, then every 200th. Not a hard cap - a hard cap once made a
    // burst unmeasurable (F-054). A sample must never read as the whole, so the
    // cumulative load count is on the row (`loads=`, the sum of the two per-stage
    // counters, which between them increment once per successful capture).
    constexpr uint32_t kCpShaderBodyDumpDwords = 64u;
    const char *stageName = (type == 0u) ? "kVertex" : "kPixel";
    const uint32_t printN =
        (captured < kCpShaderBodyDumpDwords) ? captured : kCpShaderBodyDumpDwords;
    std::string hexBody;
    hexBody.reserve(static_cast<size_t>(printN) * 9u);
    for (uint32_t i = 0; i < printN; ++i) {
      // %08x, not {:08X}: the body field is lowercase hex by contract. The
      // surrounding row's other hex fields keep the uppercase form they already
      // had, so no existing field's spelling moved.
      char word[9];
      std::snprintf(word, sizeof(word), "%08x", img.dwords[i]);
      if (i != 0u) {
        hexBody.push_back(' ');
      }
      hexBody.append(word, 8);
    }
    MCLA_LOG_WARN(
        "CP-SHADER-BODY #{} op=0x{:02X} stage={} totalDwords={} captured={} "
        "capturedBytes={} captureTruncated={} printDwords={} printOmitted={} "
        "loads={} at={:08X} phys={:08X} kernelForm={} embedded={} body=[{}]",
        n, immediate ? 0x2Bu : 0x27u, stageName, sizeDwords, captured,
        captured * 4u, captured < sizeDwords ? 1 : 0, printN,
        captured - printN,
        g_imLoadVertex.load(std::memory_order_relaxed) +
            g_imLoadPixel.load(std::memory_order_relaxed),
        bodyAddr, shownAddr, kernelForm ? 1 : 0, immediate ? 1 : 0, hexBody);
  }
  outAdvance = count + 1u;
  return true;
}

// F-612: does a vertex program exist, and how big is it? Read under the mutex so
// a concurrent vblank drain cannot see a half-written image.
uint32_t CpVertexMicrocodeDwords() {
  std::lock_guard<std::mutex> lock(g_microcodeMutex);
  return g_microcode[0].present ? g_microcode[0].captured : 0u;
}



// Type-3 opcodes we give special treatment (values per xenia gpu/xenos.h).
constexpr uint32_t kPm4XeSwap = 0x64; // Xenia-invented swap packet
constexpr uint32_t kPm4SetConstant = 0x2D;  // xenos.h:1607 load constant block
constexpr uint32_t kPm4SetConstant2 = 0x55; // xenos.h:1608 INCR_UPDATE_STATE

// F-606: SET_CONSTANT family (Xenia command_processor.cc:1428-1475, exact).
// 0x2D: arg0 = offset_type (index=&0x7FF, type=(>>16)&0xFF -> 0:+0x4000 ALU,
// 1:+0x4800 FETCH/VB, 2:+0x4900 BOOL, 3:+0x4908 LOOP, 4:+0x2000 REGISTERS),
// then count-1 data dwords poked at index++. 0x55: arg0 = raw index (no type
// split), then count-1 pokes. Out-of-file indices (>=0x5003) are DROPPED by
// CpRegPoke and counted, never asserted. Reads capped at 2048 dwords; the
// stream ALWAYS advances count+1 (a false return would desync-abort the whole
// indirect buffer per :843-846, worse than a partial capture).
// F-610: that 2048 cap is not upstream (Xenia writes all count-1 dwords,
// command_processor.cc:1458-1462) and is now LOUD - every packet that hits it
// prints CP-SETC-CAP naming the op and the dropped count. A soak with zero
// CP-SETC-CAP proves the cap never fires on real traffic.
bool CpExecSetConstant(uint32_t byteAddr, uint32_t count, bool isTwo,
                       uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t offType = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &offType)) {
    return false;
  }
  uint32_t index = 0, type = 0;
  if (isTwo) {
    index = offType & 0xFFFFu;
    type = 9; // no type split; sentinel for the log line
  } else {
    index = offType & 0x7FFu;
    type = (offType >> 16) & 0xFFu;
    switch (type) {
    case 0: index += 0x4000u; break;
    case 1: index += 0x4800u; break;
    case 2: index += 0x4900u; break;
    case 3: index += 0x4908u; break;
    case 4: index += 0x2000u; break;
    default: break; // unknown type: log below, still advance
    }
  }
  uint32_t stored = 0, dropped = 0;
  const uint32_t nData = (count > 0u) ? count - 1u : 0u;
  const uint32_t nCap = (nData > 2048u) ? 2048u : nData;
  for (uint32_t i = 0; i < nCap; ++i) {
    uint32_t data = 0;
    if (!mem.ReadU32BE(byteAddr + 8u + i * 4u, &data)) {
      break;
    }
    const uint32_t idx = index + i;
    if (idx < kXenosRegCount) {
      CpRegPoke(idx, data);
      ++stored;
    } else {
      ++dropped;
    }
  }
  static std::atomic<uint32_t> s_sc{0};
  const uint32_t n = s_sc.fetch_add(1) + 1;
  if (nData > nCap) {
    const uint32_t cn = g_setConstCapHits.fetch_add(1, std::memory_order_relaxed) + 1;
    MCLA_LOG_WARN("CP-SETC-CAP #{} {} type={} base={:04X} ndata={} stored={} "
                  "TRUNCATED={} (cap 2048 dwords)", cn, isTwo ? "2" : "1",
                  type, index, nData, stored, nData - nCap);
  }
  if (n <= 12 || (n % 500) == 0) {
    MCLA_LOG_WARN("CP-SETCONST #{} {} type={} base={:04X} ndata={} stored={} "
                  "dropped={} first={:08X}",
                  n, isTwo ? "2" : "1", type, index, nData, stored, dropped,
                  (stored > 0u) ? CpRegPeek(index) : 0u);
  }
  outAdvance = count + 1u;
  return true;
}

// ---------------------------------------------------------------------------
// Per-ring state (2026-08-25). Replaces the former singleton descriptor
// {g_ringBase, g_ringCapDwords, g_rptrIndex, g_writebackAddr}.
//
// Guest ring identity = EXACT (baseGuestVA, capacityDwords) pair as passed to
// VdInitializeRingBuffer. Never keyed by writeback address or capacity alone.
//
// Runtime evidence (build/cache/mcla.log 00:51:22.789 + generated
// ppc_recomp.75.cpp:17946-17994): the guest's only genuine registration is
// sub_82412A60: init(MmGetPhysicalAddress(ring), log2) followed by
// enableWB(phys(dev[+10896]ctx + 60), blockLog2). The write-back address is a
// PHYSICAL address (< 0x20001000); guest waiters poll the same word through
// its kernel-VA alias PA | 0xC0000000 (= C701C4BC for PA 0701C4BC). We store
// both forms and publish to the VA form - that is where guest memory lives.
struct RingState {
  // Identity (immutable after creation).
  uint32_t baseGuestVA = 0;
  uint32_t capDwords = 0;

  // Stable diagnostic name ("A", "B", ... assigned at creation).
  char id = '?';

  std::atomic<uint32_t> rptrIndex{0}; // read pointer, dword index
  std::atomic<uint32_t> lastDoorbellWptr{0xFFFFFFFFu}; // newest accepted wptr
  std::atomic<uint32_t> writebackVA{0};  // publish target (guest-VA form)
  std::atomic<uint32_t> writebackRaw{0}; // exactly what the caller passed
  std::atomic<bool> initialized{false};
  std::atomic<bool> writebackEnabled{false};
  std::atomic<bool> draining{false}; // single-drain guard per ring

  uint64_t EndByte() const { return baseGuestVA + uint64_t(capDwords) * 4u; }
};

constexpr size_t kMaxRings = 4;
constexpr uint32_t kInvalidSlot = 0xFFFFFFFFu;
RingState g_rings[kMaxRings];
std::mutex g_ringMutex; // guards registry structure (create/bind)
std::atomic<uint32_t> g_primarySlot{
    kInvalidSlot};                     // doorbell target (most recent init/WB)
std::atomic<uint32_t> g_nextRingId{0}; // 'A', 'B', ...

std::atomic<uint32_t> g_pushWatermark{0}; // consumed-through VA (driver space)
std::atomic<uint32_t> g_progressBlk{0}; // submitting thread's *(r13+256) block

// ---------------------------------------------------------------------------
// DIAGNOSTIC deferred-consumption experiment (2026-08-25).
// Default OFF: cp_deferred_consume_experiment=1 enables. When OFF, every
// path below is byte-for-byte the pre-experiment behavior.
//
// Problem being tested (mcla_perring.log 08:01 run): CaptureWindow credited
// window consumption at RESERVE time (KICK #2 pc 40 -> 131133 in one call),
// so by fence-creation time zero backlog remained and F98's delta stayed 0
// forever. On HW the kernel CP drains submitted work ASYNCHRONOUSLY after
// the kick; F98's delta>=5000 measures exactly that outstanding drain.
//
// Cursors kept strictly separate:
//   producedEnd  - driver-space endVA through which the guest has SUBMITTED
//                  (fed by reservations; cross-checked vs primary ring wptr)
//   consumedEnd  - driver-space endVA the host consumer has accounted
//   g_pushWatermark - guest-visible consumed watermark (pub mirrors)
//   XTEB+0x58    - per-thread progress, advanced ONLY by real consumption
// ---------------------------------------------------------------------------
struct PendingConsume {
  uint32_t startVA;
  uint32_t endVA;
  uint32_t dwords;
};
std::mutex g_pendingMutex;
std::vector<PendingConsume> g_pendingWindows;
std::atomic<uint32_t> g_producedEnd{0};
std::atomic<uint32_t> g_consumedEnd{0};

// Batched progress publication (deferred experiment): real consumption
// credits accumulate here and are flushed to the guest-visible XTEB+0x58
// ONCE per vblank, mirroring the kernel's batched ISR publication cadence.
// This makes fences observe consumption as a post-fence batch regardless of
// when within the frame the CP actually fetched the data.
std::atomic<uint32_t> g_progressPending{0};
void AccumProgress(uint32_t dwords) {
  if (dwords != 0) {
    g_progressPending.fetch_add(dwords, std::memory_order_relaxed);
  }
}
uint32_t FlushProgressAtVblank() {
  const uint32_t add = g_progressPending.exchange(0, std::memory_order_acq_rel);
  if (add == 0) {
    return 0;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  if (blk == 0) {
    static std::atomic<uint32_t> s_flushNoBlk{0};
    const uint32_t nb = s_flushNoBlk.fetch_add(1) + 1;
    if (nb <= 8 || (nb % 500) == 0) {
      MCLA_LOG_WARN("CP: PROGRESS-FLUSH #{} blk=0 (no TLS page and no "
                    "cached submitter block) - retrying later",
                    nb);
    }
    g_progressPending.fetch_add(add, std::memory_order_relaxed); // retry later
    return 0;
  }
  uint32_t cur = 0;
  if (mem.ReadU32BE(blk + 88, &cur)) {
    (void)mem.WriteU32BE(blk + 88, cur + add);
  }
  static std::atomic<uint32_t> s_flush{0};
  const uint32_t n = s_flush.fetch_add(1) + 1;
  if (n <= 12 || (n % 200) == 0) {
    MCLA_LOG_INFO("CP: PROGRESS-FLUSH #{} +{} -> {}", n, add, cur + add);
  }
  return add;
}

std::atomic<int> g_deferredMode{0}; // 0=unresolved, 1=off, 2=on
std::atomic<uint32_t> g_pendingRingWptr{
    0xFFFFFFFFu}; // doorbell deferred to vblank

// System-command-buffer state (kernel-acceptance boundary, 2026-08-25).
// g_gpuIdAddr = address the guest registered via
// VdSetSystemCommandBufferGpuIdentifierAddress (= &subctx[8]).
// g_scbToken  = opaque identifier handed out by VdGetSystemCommandBuffer;
// advances ONLY when real deferred consumption is credited, so repeated
// calls are stable while nothing is consumed (guest treats it opaquely).
std::atomic<uint32_t> g_gpuIdAddr{0};
std::atomic<uint32_t> g_scbToken{1};

void ScbNoteConsumption() {
  g_scbToken.fetch_add(1, std::memory_order_relaxed);
}

bool DeferredConsumeEnabled() {
  int mode = g_deferredMode.load(std::memory_order_acquire);
  if (mode != 0) {
    return mode == 2;
  }
  const char *e = std::getenv("cp_deferred_consume_experiment");
  const bool on = e != nullptr && e[0] == '1';
  if (g_deferredMode.compare_exchange_strong(mode, on ? 2 : 1)) {
    MCLA_LOG_WARN("CP: deferred-consumption experiment {} (diagnostic only)",
                  on ? "ENABLED" : "disabled");
  }
  return on;
}

// Physical -> kernel-virtual alias (X360: kernel maps phys windows at
// +0xC0000000; generated EA->PA transform is the inverse). Values at or
// above the kernel window are returned unchanged.
//
// F-680: THAT COMMENT IS A MODEL OF THE CONSOLE, NOT OF THIS TREE, and where the
// two differ this tree follows the measurement. The console aliases the C view
// onto the pool; this tree has one flat 4 GiB window and its alias probe reads
// `canary_shared_views=1/3` (build/w679.log:50), i.e. only the A view is the
// pool. So for every address where a pool byte exists, `| 0xC0000000` names an
// address 0x20000000 above it - inside the pool's live tail below 4 MiB, and
// simply unwritten above that - and because the flat window ACCEPTS reads
// anywhere, the failure is silent zeros rather than a refusal.
//
// ONE CALL SITE REMAINS: CpEnableRPtrWriteBack's publish target (:4736), and it
// is left on this transform DELIBERATELY, not because the C view exists here.
// There is no measurement of which view the guest's rptr waiter polls, and the
// field that looks like one - `WAIT[KWFSO] ... rptrWB=0019
// wb@D840B2BC=00000019` - is a HOST read of CpPrimaryWritebackVA()
// (imports.cpp:4978-4981), so it only proves we can read our own write, which
// F-057(1) already retired as ring-progress evidence. Every address that must
// reach the pool goes through CpPhysToPoolVa instead; see that function's header
// for the full call-site classification and the three measured links.
// DO NOT ADD CALL SITES HERE. Add them to CpPhysToPoolVa.
inline uint32_t PhysToKernelVA(uint32_t addr) {
  return addr < 0x20000000u ? (addr | 0xC0000000u) : addr;
}

int FindRingSlotLocked(uint32_t base, uint32_t capDwords) {
  for (size_t i = 0; i < kMaxRings; ++i) {
    const RingState &r = g_rings[i];
    if (r.initialized.load(std::memory_order_acquire) &&
        r.baseGuestVA == base && r.capDwords == capDwords) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

// Ring whose window [base, base+cap*4) contains byte address va, else nullptr.
RingState *RingContainingVA(uint32_t va) {
  for (auto &r : g_rings) {
    if (!r.initialized.load(std::memory_order_acquire))
      continue;
    if (va >= r.baseGuestVA && va < r.EndByte())
      return &r;
  }
  return nullptr;
}

// REJECTED HYPOTHESIS (2026-08-25, kept as evidence): GPU_ctx+0x30 was
// guessed to be a wrap-aliased ring cursor ("~65KB past ring base, wraps",
// BOOT_HANDOFF). Measured twice across boots the cursor sits at
// base + 2*ringSpan + ~0x13C/0x23C (mcla.log 07:06 C601C5BC, 00:51-era
// C62346BC vs C6224480) - i.e. just past TWO ring spans. That is a different
// driver arena's cursor, NOT ring-owned under any wrap rule. Strict window
// containment stays; consuming those cursors would be fabrication.
RingState *RingOwningCursorVA(uint32_t va) { return RingContainingVA(va); }

// Primary ring = the one the guest most recently initialized (and, if a WB
// was enabled afterwards, that one). The Xenos hardware CP has exactly ONE
// primary ring doorbell (CP_RB_WPTR); repeated VdInitializeRingBuffer calls
// reprogram it. This mirrors that without inventing multi-ring ownership.
RingState *PrimaryRing() {
  const uint32_t slot = g_primarySlot.load(std::memory_order_acquire);
  if (slot >= kMaxRings)
    return nullptr;
  RingState &r = g_rings[slot];
  return r.initialized.load(std::memory_order_acquire) ? &r : nullptr;
}

// All GuestDevices seen driving the ring (the two census hooks attach:
// sub_82411218 ring-wait at gpu_device.cpp:4692, sub_82411E98 fence-wait at
// :4760 - there is no create-hook attacher). MCLA binds a SECOND GuestDevice
// (A0009100) of the same class at create (sub_82413588); waiters poll THEIR
// OWN dev[+10896] ctx, so mirror maintenance must cover every device, not just
// the last attacher.
constexpr size_t kMaxDevices = 4;
std::atomic<uint32_t> g_devices[kMaxDevices]{};
static std::atomic<uint32_t> s_attachedCount{0};

template <typename Fn> void ForEachDevice(Fn &&fn) {
  for (auto &slot : g_devices) {
    if (const uint32_t dev = slot.load(std::memory_order_relaxed); dev != 0) {
      fn(dev);
    }
  }
}

std::atomic<uint64_t> g_drainCount{0};
std::atomic<uint64_t> g_swapCount{0};
std::atomic<uint64_t> g_doorbellCount{0};

uint32_t ReadRingU32(const RingState &ring, uint32_t dwordIndex) {
  const uint32_t addr = ring.baseGuestVA + dwordIndex * 4u;
  uint32_t v = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(addr, &v);
  return v;
}

// Phase-6 diagnostic: writeback target unexpectedly overlapping a ring body
// is logged loudly but NOT rejected (HW programs CP_RB_RPTR_ADDR as given;
// fabricating an error would be worse than surfacing the fact).
void WarnWritebackOverlap(RingState &ring) {
  const uint32_t wb = ring.writebackVA.load(std::memory_order_relaxed);
  if (wb == 0)
    return;
  for (auto &other : g_rings) {
    if (!other.initialized.load(std::memory_order_acquire))
      continue;
    if (wb >= other.baseGuestVA && wb < other.EndByte()) {
      static std::atomic<bool> warned{false};
      if (!warned.exchange(true)) {
        MCLA_LOG_WARN("CP: RING {} writeback {:08X} lies inside RING {} "
                      "body [{:08X},{:08X}) - rptr publishes will land "
                      "in ring memory",
                      ring.id, wb, other.id, other.baseGuestVA,
                      other.EndByte());
      }
      return;
    }
  }
}

void SyncConsumptionMirrors(uint32_t mark);

// ---------------------------------------------------------------------------
// Guest publication contract (IDA-proven 2026-08-26,
// .research/mcla_rex_contract):
//   dev[10908] "put"    - window counter, init 3, guest sub_82411CD0 advances
//                         +2 per reserved window at 0x82411DA8 (only +2 writer).
//   *(dev[10896]) "pub" - consumed-window counter, init 1 (sub_824162D8 GPU-ctx
//                         init). On HW the kernel/GPU side publishes completion
//                         here; the only in-image writers are the ring-register
//                         block (pub = put-2 at 0x82412D20, inside sub_82412A60)
//                         and the abort paths (sub_82411CD0's dev[10941]&2
//                         killbit branch, C18 = sub_82425C18 recovery = put-2).
//   sub_82411E98(dev,N) blocks until pub >= N; healthy fences exit via this
//   check. F98's delta>=5000 -> C18 path is stall recovery only and TRAPS
//   (twi 31) when dev[13432]==0, so it must stay dormant.
// Therefore we publish COUNTS (prev+2 per completed window, clamped to live
// put), never VAs. Writing the consumed-through VA (old behavior) made
// (put-needed) < (put-pub) permanently true under u32 wraparound -> E98
// spins forever with pub=0xC60xxxxx against put=7..9.
// ---------------------------------------------------------------------------
namespace {
struct GuestPub {
  uint32_t dev;
  uint32_t count;
};
std::mutex g_pubMutex;
std::vector<GuestPub> g_pubStates;
} // namespace

void PublishRptr(RingState &ring) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t rptr = ring.rptrIndex.load(std::memory_order_relaxed);
  const uint32_t wb = ring.writebackVA.load(std::memory_order_relaxed);
  if (ring.writebackEnabled.load(std::memory_order_acquire) && wb != 0) {
    // w18: monotonic publish. After an idle REINIT the guest put cursor can
    // sit above the reset rptr; writing rptr=0 would re-park the KWFSO
    // rptrWB poll. Never move the published watermark backwards.
    uint32_t cur = 0;
    (void)mem.ReadU32BE(wb, &cur);
    const uint32_t publish = (rptr >= cur) ? rptr : cur;
    if (publish != cur)
      (void)mem.WriteU32BE(wb, publish);
  }
}

// T40.6 step 1: per-opcode Type-3 census. The logger this replaces reported each
// opcode < 0x20 once and collapsed EVERY opcode >= 0x20 into a single line -
// exactly the range the draw packets live in (PM4_DRAW_INDX = 0x22,
// PM4_DRAW_INDX_2 = 0x36, xenos.h:1600-1601), so no soak could say what the
// stream actually holds. Now the first 3 hits of each opcode print their
// argument dwords and later hits report a running total. LOG-ONLY: it consumes
// nothing and changes no packet's advance.
void LogType3Unhandled(uint32_t opcode, uint32_t count, uint32_t headerAddr,
                       int depth) {
  static std::atomic<uint32_t> totals[128]{};
  const uint32_t idx = opcode & 0x7Fu;
  const uint32_t n = totals[idx].fetch_add(1, std::memory_order_relaxed) + 1u;
  const uint32_t all =
      g_t3Unhandled.fetch_add(1, std::memory_order_relaxed) + 1u;
  // F-612: the always-countable row. CP-T3-CENSUS is deliberately spammy
  // (first 3 + every 512nd), which makes a SINGLE opcode's count readable but
  // leaves the total across all unhandled opcodes - the number the draw census
  // needs in order to say "microcode absent" versus "something upstream of the
  // microcode was never implemented" - only inferrable. This prints it every
  // 4096 hits, so a suppressed repeat is still a countable row. The
  // 18465-line 0x3E flood in build/w658.log is the reason the cap exists.
  if (all <= 8u || (all % 4096u) == 0u) {
    MCLA_LOG_WARN("CP-T3-UNHANDLED op=0x{:02X} thisOp={} allUnhandled={} "
                  "(a soak reaching this line has a packet this CP does not "
                  "implement; see CP-T3-CENSUS for the per-opcode breakdown)",
                  idx, n, all);
  }
  if (n > 3u && (n % 512u) != 0u) {
    return;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t a[6] = {0, 0, 0, 0, 0, 0};
  for (uint32_t i = 0; i < 6u && i < count; ++i)
    (void)mem.ReadU32BE(headerAddr + 4u + i * 4u, &a[i]);
  MCLA_LOG_WARN("CP-T3-CENSUS op=0x{:02X} #{} count={} depth={} addr={:08X} "
                "args={:08X} {:08X} {:08X} {:08X} {:08X} {:08X}",
                idx, n, count, depth, headerAddr, a[0], a[1], a[2], a[3], a[4],
                a[5]);
}

// PM4 TYPE3 opcode values (xenia gpu/xenos.h PM4 enum).
constexpr uint32_t kPm4MeInit = 0x48;         // initialize CP micro-engine
constexpr uint32_t kPm4IndirectBuffer = 0x3F; // indirect buffer dispatch
constexpr uint32_t kPm4MemWrite = 0x3D;       // write N dwords to memory
// F-612: both microcode loads. 0x27 is the pointer form
// (command_processor.cc:1528-1557) and 0x2B the embedded form (:1559-1590);
// only 0x2B was dispatched, and both discarded the program.
constexpr uint32_t kPm4ImLoad = 0x27;         // load sequencer IM (pointer)
constexpr uint32_t kPm4ImLoadImmediate = 0x2B;// load sequencer IM (embedded)
constexpr uint32_t kPm4DrawIndx = 0x22;   // fetch index buffer and draw
constexpr uint32_t kPm4DrawIndx2 = 0x36;  // draw with indices supplied in packet
// F-651: the three that share the MEM_WRITE-shaped path. Named from the enum,
// not from the opcode value: xenos.h:1581 = 0x3c, :1588 = 0x3e, :1595 = 0x58.
constexpr uint32_t kPm4RegToMem = 0x3E;       // read register in chip, write to memory
constexpr uint32_t kPm4WaitRegMem = 0x3C;     // wait until a register/mem is a value
constexpr uint32_t kPm4EventWriteShd = 0x58;  // generate a VS|PS_done event
constexpr uint32_t kPm4EventWrite = 0x46;     // generate an event that writes on completion
// F-721: the four TILING bin registers and the state-invalidation packet.
// Names and values from xenia gpu/xenos.h:1630-1633 (0x60/0x61/0x62/0x63) and
// :1614 (0x3B). These are the last of the thirteen opcodes this file's
// CP-T3-UNHANDLED row was still counting.
constexpr uint32_t kPm4InvalidateState = 0x3B;  // selective invalidation of state ptrs
constexpr uint32_t kPm4SetBinMaskLo = 0x60;     // low 32 bits of the PFP BIN_MASK
constexpr uint32_t kPm4SetBinMaskHi = 0x61;     // high 32 bits of the PFP BIN_MASK
constexpr uint32_t kPm4SetBinSelectLo = 0x62;   // low 32 bits of the PFP BIN_SELECT
constexpr uint32_t kPm4SetBinSelectHi = 0x63;   // high 32 bits of the PFP BIN_SELECT
// F-XXX: 0x45 PM4_COND_WRITE. xenos gpu/xenos.h:1592 -
//   `PM4_COND_WRITE = 0x45,   // conditional write to memory or register`
// This was the ONLY opcode the GUEST actually emits that the host did not
// decode: 8 packets per boot, MEASURED in build/w842.log and build/run845.txt
// (`CP-T3-UNHANDLED op=0x45 thisOp=1..8`, `CP-T3-CENSUS op=0x45 #1..#3`).
// The decoder lives at CpExecCondWrite, below; the console's layout and the
// guest's own operand words are cited there.
constexpr uint32_t kPm4CondWrite = 0x45;        // conditional write to memory or register
// 0x54 PM4_INTERRUPT. The LAST opcode the unhandled-row was still counting, and
// the only one left in it: xenos.h:1622 `PM4_INTERRUPT = 0x54, // generate
// interrupt from the command stream`. DECODED, NOT DISPATCHED - the split is
// measured, and the refusal is deliberate. Read this before "fixing" it.
//
// MEASURED, build/w722.log (8,163,069 bytes, 51,390 lines, the newest build/*.log
// at 2026-10-05 01:39:40, i.e. NOT this session's run - I did not boot the game):
//   01:37:24.754  CP-T3-UNHANDLED op=0x54 thisOp=1 allUnhandled=1
//   01:37:24.754  CP-T3-CENSUS op=0x54 #1 count=1 depth=0 addr=B7C0A8C4
//                 args=00000004 00000000 00000000 00000000 00000000 00000000
// `allUnhandled=1` - ONE unhandled type-3 packet in the whole soak, and it is
// this one. So "0 occurrences" was never true for this log; the census row was
// there to be read.
//
// THE PACKET, FROM RAW WORDS. Header 0xC0005400, one operand dword 0x00000004,
// two dwords total, at B7C0A8C4. Every field is recoverable without guessing:
//   addr B7C0A8C4 is dword 401 of the window CP: IB-OPC-CENSUS #9 names
//     (win=B7C0A280; 0xB7C0A8C4 - 0xB7C0A280 = 0x644 = 401*4 - arithmetic, not
//     an assumption). `op=0x54` and `count=1` from the row are this file's own
//     decode of that header: type = hdr>>30 = 3, count = ((hdr>>16)&0x3FFF)+1 = 1,
//     opcode = (hdr>>8)&0x7F = 0x54, so bits 31:16 are C000 and the only bit
//     left undetermined is bit 0, the predicate. It is NOT observable from this
//     log (CP-PREDICATE-SKIP is 0 in w722.log, but that is because BIN_MASK and
//     BIN_SELECT both end at 0x00000000FFFFFFFF so any_pass is always true - the
//     gate could not have fired either way). The header is therefore 0xC0005400
//     or 0xC0005401 and this handler is identical under both, because the
//     predicate gate above sits BEFORE the switch and reads the same word.
//   The layout is cross-checked against raw words this log does print for other
//     packets: C0006000 (CP: INDIRECT_BUFFER #7 win[0..7]) decodes to opcode 0x60,
//     which is xenos.h:1630 PM4_SET_BIN_MASK_LO, and C0043C00
//     (CP-WAITREG-PKTBYTES) decodes to 0x3C = PM4_WAIT_REG_MEM with 5 operand
//     dwords - which is exactly the b1..b5 that row prints.
//   operand 0x00000004 IS the reference's `cpu_mask`
//     (command_processor.cc:906, the first and only reader value), so the
//     handover's `DispatchInterruptCallback(1, 2)` is reproduced by the guest's
//     own dword: 0x4 has bit 2 set, and the reference's loop at
//     command_processor.cc:907-911 dispatches (1, n) for each set bit n.
//
// WHY IT IS ON THE CRITICAL PATH - and why that does not make it the fix. IB #9's
// walk reached dword 401 and fired this packet at 01:37:24.754; the walk then
// reached dword 405, where CP[IB]: desync at dword 405 aborted the buffer
// (CpExecWaitRegMem returns false at :3696 on timeout, which is the only way
// that row can print) and CP: RING A PARKED followed in the same millisecond.
// That parking packet is CP-WAITREG-TIMEOUT #1: is_memory=1, pollVA=B840B280,
// ref=00000000, mask=FFFFFFFF, value=00000004, waited=2001ms. So this packet is
// 4 dwords / 2 packets upstream of the stall, executed 2001 ms before it.
//
// WHY THE DISPATCH IS REFUSED (F-609, and the 0x64 precedent is not the reason
// here - 0x64 is unmeasured, this is measured; the reason is that the reference's
// dispatch needs an observable this host cannot produce). Measured from raw
// reference code:
//   command_processor.cc:900-913  ExecutePacketType3_INTERRUPT reads one operand
//     and calls graphics_system_->DispatchInterruptCallback(1, n).
//   graphics_system.cc:241-261    that returns immediately if no callback is
//     registered (:242-244), else does thread->SetActiveCpu(cpu) and
//     processor_->ExecuteInterrupt(...) - i.e. it CALLS GUEST CODE.
// The guest HAS registered one: build/w722.log lines 1487 and 2513 both read
// `VdSetGraphicsInterruptCallback: callback=0x82411478 user=0x40002080`, twice,
// the second at 01:37:24.364 - 390 ms before this packet. So the reference would
// NOT take the early return, and reproducing it means executing guest function
// 0x82411478 with r3=1 and r4=0x40002080.
// Read from generated/ppc_xenon/ppc_recomp.75.cpp:14055-14115 (the recompiler's
// own rendering of those bytes), that function's ONLY stores on the source==1
// path are: an indirect call through `*(obj+16)` with argument `*(obj+20)`, and a
// read-modify-write of ONE 32-bit word at `*(u32*)(*(u32*)(0x40002080 + 10900))`
// clearing bit `1 << *(u8*)(r13 + 268)`. Two things follow, and neither is
// measurable here:
//   1. The word it writes is behind a runtime pointer chain. Nothing in any log
//      prints 0x40002080+10900's value, so whether that word is the byte the
//      park waits on (0x1840B280) is UNKNOWN, not merely unimplemented. Writing
//      0 there would be inventing the satisfier - the exact thing F-609 forbids,
//      and the thing CP-WAITREG-WRITER-VALUES already says in words: "the
//      satisfier is not in this PM4 stream and widening the comparison would be a
//      fabrication".
//   2. `*(u8*)(r13 + 268)` is the CURRENT CPU NUMBER. The reference guarantees it
//      by calling SetActiveCpu first. This tree has exactly one host->guest call
//      facility and it is unreachable from here: MclaXcCallGuest
//      (src/gpu_device.cpp:7388) is `static`, in another translation unit, and
//      hardcodes r13=0x8F200000 / lr=0x821BC380 / r1=0x006D8EC0 - a context with
//      no measured CPU number in it. Calling it from a CP thread that has none is
//      not a census hook; it is a fabricated execution context.
// So: the packet is decoded and consumed exactly as the reference consumes it
// (the reference does not AdvanceRead inside the handler - the caller does, at
// the top of its own loop), and the interrupt itself is refused BY NAME in the
// row below. `CP-INTERRUPT` is a NEW, unregistered row (tools/soak_census.py is
// another agent's file, so it is deliberately NOT added to the marker table
// here); the exact per-packet 0x54 count survives in the opcode histogram the
// indirect-buffer census already prints, which is filled from the header word
// before this switch is reached and is untouched by this case.
constexpr uint32_t kPm4Interrupt = 0x54;        // generate an interrupt from the stream

// F-721: the two 64-bit bin registers, and the ONLY thing that reads them.
//
// The reference keeps them as CommandProcessor members initialised to
// 0xFFFFFFFF (gpu/command_processor.h:284-285, quoted because the initial value
// is load-bearing here) and merges each half with the packet's dword
// (gpu/command_processor.cc:793-814). Their one reader is the PREDICATE gate at
// gpu/command_processor.cc:708-715:
//     if (packet & 1) {
//       bool any_pass = (bin_select_ & bin_mask_) != 0;
//       if (!any_pass || opcode == PM4_XE_SWAP) { reader->AdvanceRead(...); return true; }
//     }
// so 0x60-0x63 are NOT self-contained: implementing the four writes without the
// gate would leave two registers nothing reads, which is the fake-this-row
// anti-pattern. Both halves are implemented here.
//
// WHY THE DEFAULTS MAKE THE GATE FREE AT BOOT: with both registers 0xFFFFFFFF,
// (bin_select_ & bin_mask_) = 0xFFFFFFFF != 0, so any_pass is true and NO
// packet is skipped - identical to this tree's behaviour before F-721. The gate
// can only begin skipping after the guest itself writes 0x60-0x63, which is
// also when real hardware begins applying it. Every skip is counted and named
// (CP-PREDICATE-SKIP) so a soak can see it rather than infer it.
std::atomic<uint64_t> g_binMask{0xFFFFFFFFull};
std::atomic<uint64_t> g_binSelect{0xFFFFFFFFull};
// F-721 census counters. Bounded rows below; see CP-BINREG and CP-PREDICATE-SKIP.
std::atomic<uint32_t> g_binRegWrites{0};      // 0x60-0x63 executed
std::atomic<uint32_t> g_predicateSkips{0};    // packets skipped by the gate
std::atomic<uint32_t> g_predicateGated{0};    // packets that HAD the predicate bit
std::atomic<uint32_t> g_invalidateState{0};   // 0x3B consumed
constexpr uint32_t kRegVgtEventInitiator = 0x21F9u; // register_table.inc:530

// VGT_DRAW_INITIATOR field positions (xenia gpu/registers.h:311-330, index
// 0x21FC per register_table.inc:533):
// prim_type +0 (6), source_select +6 (2: kDMA/kImmediate/kAutoIndex),
// index_size +11 (1), num_indices +16 (16).
inline uint32_t DrawInitiatorField(uint32_t v, uint32_t shift, uint32_t bits) {
  return (v >> shift) & ((1u << bits) - 1u);
}

// GpuSwap mirror (xenia gpu/xenos.h:1052-1069, the uint32_t overload):
// endianness encoded in the low bits of PM4 memory addresses.
inline uint32_t GpuSwap32(uint32_t value, uint32_t endianBits) {
  switch (endianBits & 0x3) {
  case 1: // k8in16: swap bytes in half words
    return ((value << 8) & 0xFF00FF00u) | ((value >> 8) & 0x00FF00FFu);
  case 2: // k8in32: swap all bytes
    return ((value >> 24) & 0xFFu) | ((value >> 8) & 0xFF00u) |
           ((value << 8) & 0xFF0000u) | ((value << 24) & 0xFF000000u);
  case 3: // k16in32: swap half words
    // F-721: THIS ARM WAS MISSING. The `default:` below used to swallow
    // selector 3, so a `poll & 3 == 3` (and every 0x3E/0x3D/0x58 store whose
    // address carries those two bits) got NO swap where xenos.h:1065-1067
    // swaps half words. Measured in the F-721 harness: 0 of 4 selectors agreed
    // with the reference before this arm, 4 of 4 after.
    return ((value >> 16) & 0xFFFFu) | (value << 16);
  default: // kNone
    return value;
  }
}

// xe::byte_swap. xenos.h:1062-1064's own comment on the k8in32 arm is "we are
// likely doing two swaps here" - it IS a plain 32-bit byte swap, i.e. the same
// value mcla::kernel::Swap32 produces (kernel/memory.h:126). Named so the two
// RAW host accesses below read as raw instead of looking like a double swap.
inline uint32_t CpByteSwap32(uint32_t v) { return GpuSwap32(v, 2u); }

// F-721: RAW 32-bit host access at a guest VA - bytes go down / come up exactly
// as they are, with no endian translation in either direction.
//
// WHY, MEASURED. command_processor.cc:971-973 binds
//   `const volatile uint32_t& value_ref = *(const uint32_t*)(TranslatePhysical(poll & ~3))`
// and :978 loads it RAW; the ONLY transformation anywhere on that path is the
// single GpuSwap at :982-983. ReadU32BE is not that load - it returns Swap32 of
// it (kernel/memory.cpp:221-222 `*outVal = Swap32(beVal)`), so the old
// ReadU32BE-then-GpuSwap32 pair applied TWO swaps. The harness under
// %TEMP%\opencode\gpu_cp_work (harness_gate2.cpp, every function spliced
// byte-for-byte from this file and from .research/xenia) measured 8/8
// disagreements with the reference - all four `poll & 3` selectors, both writer
// kinds.
//
// The WRITE side has the mirror defect and the SAME one: the reference's PM4
// stores are `xe::store<uint32_t>` (base/memory.h:374-376) = a PLAIN host store
// of `GpuSwap(data, endian)`, while WriteU32BE adds Swap32 on top
// (kernel/memory.cpp:351). Measured 4/4 disagreements - so "the write sides are
// fine" was a gloss; only the SCRATCH writeback is byte-correct today, because
// there the reference uses `store_and_swap` (base/memory.h:431-433), which is
// exactly WriteU32BE (also 4/4 agreement, measured).
//
// BOTH SIDES MOVE TOGETHER, and that is measured rather than stylistic: with the
// poll read corrected but the PM4 store left alone, the 0x3E/0x3D/0x58 round
// trip REGRESSES 4/4 (harness section 3b), because the poll would then read the
// store's extra Swap32 instead of cancelling it. The scratch writeback is not
// touched by either change.
//
// F-746, THE PART THAT MATTERS AND THAT THE PARAGRAPH ABOVE GETS WRONG: this
// helper's contract is that ITS ARGUMENT IS THE HOST DWORD, and that is now
// MEASURED rather than argued (harness scenario C0, %TEMP%\opencode\cpwait_work:
// CpWriteU32Raw(va, X) leaves host dword == X for 4/4 values). It cancels
// WriteU32BE's own Swap32. So "WriteU32BE adds Swap32, therefore compensate" -
// the reasoning the paragraph above uses - does NOT apply to a caller of THIS
// function: the compensation had already happened inside it. F-721 then
// compensated a second time at 0x3E and 0x3D, and those two sites were left one
// Swap32 away from the reference: 0/4 store-byte agreement and 0/4 round trip,
// measured. 0x58 passes GpuSwap32 straight in and was correct throughout.
// Corrected at 0x3E and 0x3D; 4/4 and 4/4 after. Nothing about the scratch
// writeback or the poll read changes.
inline bool CpWriteU32Raw(uint32_t guestVa, uint32_t rawValue) {
  return mcla::kernel::GuestMemoryHeap::Instance().WriteU32BE(
      guestVa, CpByteSwap32(rawValue));
}

inline bool CpReadU32Raw(uint32_t guestVa, uint32_t *outRaw) {
  uint32_t beVal = 0;
  if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(guestVa, &beVal)) {
    return false;
  }
  *outRaw = CpByteSwap32(beVal);
  return true;
}

// ===========================================================================
// F-651: PM4_REG_TO_MEM (0x3E) - the 17.5-million-packet flood - and the two
// packets that share its path, PM4_WAIT_REG_MEM (0x3C) and
// PM4_EVENT_WRITE_SHD (0x58). Read from the reference, not from the name.
//
// MEASURED (build/w661.log, 180 s, 790k lines, zero crashes). The per-opcode
// totals below are read off the `CP-T3-CENSUS ... #N` COUNTER, not off the
// printed row count: LogType3Unhandled prints only the first 3 hits and then
// every 512th, so the printed rows are a 1-in-512 SAMPLE and a row count is
// not a packet count.
//   0x3E  17,556,480 packets  (97,536/s) - 80.2% of the 21,884,928 unhandled
//   0x3C   1,521,152 packets
//   0x58   1,082,368 packets
//
// PREMISE CORRECTIONS to the brief, all measured, none of which change the
// conclusion but two of which change the numbers a soak must be judged on:
//  (a) "21,884,928 packets" for 0x3E is the ALL-unhandled total (the
//      CP-T3-UNHANDLED row's own allUnhandled= field). 0x3E's own count is
//      17,556,480. It is 80.2% of the flood, not 100% of it.
//  (b) "at least 2,286 distinct register addresses" reads the census wrong.
//      2,286 is how many PRINTED rows each hot pair contributes
//      (34,293 sampled / 15 hot pairs = 2,286.2). The distinct (register,
//      address) count is 18 - 15 hot, 3 one-shot - over 18 distinct register
//      indices. So the redundancy is not 9,500x; it is 1,170,432x.
//  (c) "0x1005 is SHADER_CONSTANT_005_X, register_table.inc:668" is wrong
//      twice. register_table.inc:668 is 0x4014. 0x1005 is HZ_PERFCOUNTER0_HI
//      (register_table.inc:278). 17 of the 18 indices this stream uses are not
//      named in the 2,670-entry partial table at all.
//  (d) 0x58 is NOT a wait. It is a write, with no loop (see below). It
//      manufactures a token that a LATER 0x3C observes; the two are related,
//      but only 0x3C can hang.
// ===========================================================================

// --- F-651 (1) PM4_REG_TO_MEM 0x3E -----------------------------------------
// Layout, verbatim from ExecutePacketType3_REG_TO_MEM
// (.research/xenia/src/xenia/gpu/command_processor.cc:1069-1090). The reader is
// already past the header, so these are body dwords 1 and 2:
//   body dword 1 = reg_addr (:1075) - a RAW register index, NOT masked. The
//     reference asserts reg_addr < RegisterFile::kRegisterCount (:1080), and
//     kRegisterCount is 0x5003 dwords (register_file.h:40) - the same width as
//     this file's kXenosRegCount (src/gpu_cp.cpp:70).
//   body dword 2 = mem_addr (:1076) - low 2 bits are the xenos::Endian
//     selector (:1083); the remainder is a GUEST PHYSICAL address, because
//     mem_addr &= ~0x3 and the store is xe::store(memory_->
//     TranslatePhysical(mem_addr), ...) (:1084-1086).
// GRANULARITY: exactly ONE 32-bit dword per packet. There is no length field
// and no loop - `count` is 2 on every measured row and carries no payload
// beyond these two words.
// ENDIANNESS: the register value is GpuSwap'd by mem_addr & 0x3 BEFORE the
// store (:1085) - the same GpuSwap32 mirror this file already uses for
// PM4_MEM_WRITE. MEASURED: all 18 distinct pairs in w661 carry mem_addr & 3
// == 2 == k8in32, i.e. a full 32-bit byte swap on every packet of the flood.
// WHAT IT WRITES: register_file_->values[reg_addr] (:1081) - the last-written
// register SHADOW, not a decoded register name. CpRegPeek is that same shadow
// (src/gpu_cp.cpp:363-366), so this is a raw read, not a fabrication: 17 of
// 18 indices are unnamed in the partial table, but the reference never names
// them either. `count == 2` upstream is assumed by both this host and the
// reference (:1073 "Count is 2"), and the count is a 14-bit header field
// (:2564) that the guest is not observed to under-fill, so a short packet is
// refused rather than read past.
//
// THE DESTINATION IS GUEST PHYSICAL, and this file already has the checked
// helper for it. ExecuteMemWrite above stores to the same physical window
// through GuestMemoryHeap::WriteU32BE with no PhysToKernelVA, and its own
// comment (src/gpu_cp.cpp:2005-2011) records that this is a deliberate,
// logged choice rather than an accident. REG_TO_MEM reuses that exact path, so
// it inherits its convention instead of inventing a third one. No
// reinterpret_cast, no assert on a guest-supplied value: ReadU32BE /
// WriteU32BE are the checked, endian-explicit accessors, and a refusal
// (out-of-file register, unreadable body, refused store) is counted by name.
bool CpExecRegToMem(uint32_t byteAddr, uint32_t count, uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n = g_r2mSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  outAdvance = count + 1u;
  if (count < 2u) {
    return true; // no body to read; upstream's count is never this small
  }
  uint32_t regAddr = 0, memWord = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &regAddr) ||
      !mem.ReadU32BE(byteAddr + 8u, &memWord)) {
    g_r2mUnreadable.fetch_add(1, std::memory_order_relaxed);
    return true;
  }
  if (regAddr >= kXenosRegCount) {
    // command_processor.cc:1080-1081 asserts here. This host does not assert on
    // a guest-supplied value: CpRegPeek returns 0 for an out-of-file index
    // (:364), and publishing that 0 to a guest address would be a value the
    // register file does not hold. Refused by name and counted instead.
    const uint32_t r =
        g_r2mRefusedReg.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (r <= 8u || (r % 200u) == 0u) {
      MCLA_LOG_WARN("CP-REG2MEM-REFUSE #{} reg={:08X} is outside the "
                    "{:X}-dword register file (command_processor.cc:1080 "
                    "asserts; CpRegPeek would answer 0). NOTHING stored - "
                    "upstream's assert is a host crash, ours is a count",
                    r, regAddr, kXenosRegCount);
    }
    return true;
  }
  const uint32_t value = CpRegPeek(regAddr);
  const uint32_t dst = memWord & ~0x3u;
  // F-721: `memWord` is a guest PHYSICAL address (command_processor.cc:1076 reads
  // it and :1086 hands it to memory_->TranslatePhysical), so the store goes to
  // the POOL byte. Byte order moves WITH it, and both halves have to: the
  // reference's 0x3E store is `xe::store<uint32_t>(TranslatePhysical(mem_addr),
  // GpuSwap(reg_val, endianness))` (cc:1083-1086), and xe::store<uint32_t> is a
  // PLAIN host store (base/memory.h:374-376) - no Swap32 of its own. WriteU32BE
  // adds one (kernel/memory.cpp:351), which the F-721 harness measured as a 4/4
  // disagreement with the reference on all four `mem_addr & 3` selectors. That
  // half cannot be left behind: with the poll read corrected and this store
  // unchanged, the round trip through this very packet REGRESSES 4/4 (harness
  // section 3b), because the poll would read the extra Swap32 instead of
  // cancelling it.
  const uint32_t dstVa = CpPhysToPoolVa(dst, "REG2MEM");
  // F-746 CORRECTS F-721 HERE, AND MEASURED. F-721 wrapped this in
  // CpByteSwap32 on top of GpuSwap32 and claimed 4/4 agreement; that was wrong.
  // Harness: %TEMP%\opencode\cpwait_work, scenario C0 + C.
  //
  // THE CONTRACT IS CpWriteU32Raw's, and it is now measured directly (C0):
  // CpWriteU32Raw(va, X) leaves the HOST DWORD at va equal to X. It is
  // WriteU32BE(va, CpByteSwap32(X)) (:2854-2857) and WriteU32BE already applies
  // Swap32 on the way down (kernel/memory.cpp:346-352), so the two cancel and
  // there is no endian translation left to undo. A further CpByteSwap32
  // therefore leaves Swap32 one time too many - measured, all four selectors.
  //
  // WHAT THE REFERENCE LEAVES: xe::store<uint32_t>(TranslatePhysical(mem_addr),
  // GpuSwap(reg_val, endianness)) - command_processor.cc:1083-1086 with
  // xe::store<uint32_t> a PLAIN host store (base/memory.h:373-376) - so the host
  // dword is exactly GpuSwap(reg_val, endian), with no further swap. The poll
  // then agrees too: it applies ONE GpuSwap to the host word (:978-983) and
  // every selector's GpuSwap is an involution, so the reference's own 0x3E round
  // trip returns reg_val. Measured 4/4 here after the fix, 0/4 before.
  //
  // 0x58 (CpExecEventWriteShd) and the scratch writeback were already right and
  // are NOT touched: 0x58 passes GpuSwap32 in with no CpByteSwap32, which is
  // what agreement actually requires. The scratch writeback uses WriteU32BE
  // directly (store_and_swap, :351) and is selector-independent.
  const uint32_t swapped = GpuSwap32(value, memWord & 0x3u);
  // F-651 idempotence. The measured redundancy is 1,170,432x (17,556,480
  // packets over 15 hot (reg,address) pairs), so the question is not whether
  // this window is rewritten but whether the value ever changes. It is
  // answered by READING the destination rather than by a per-address cache: a
  // cache would be wrong the moment anything else wrote that dword, and a read
  // is one checked guest access in place of a store. The store is what has to
  // be avoided - this window is the one the guest is concurrently polling
  // (that is what produces the 97,536/s cadence), and every store into it
  // invalidates a line the guest holds. Skipping the redundant ones keeps
  // that traffic a share instead of an invalidation.
  //
  // F-721: the probe reads dstVa, the SAME byte the store below writes. Before
  // the move it read flat `dst` while the store wrote flat `dst` too - but the
  // wait polls the POOL byte, so the probe was answering a question about a
  // dword no writer and no waiter agreed on. Read and write now name one byte.
  uint32_t cur = 0;
  if (dstVa == 0u) {
    // Refused: this tree has no pool byte for that physical address, nothing
    // stored, NO fallback to the untranslated view - and CP: POOL-XLATE-REFUSED
    // above already printed why, under site=REG2MEM. Falling through rather
    // than returning keeps the bounded CP-REG2MEM row firing for this attempt,
    // so a refusal cannot quietly delete a row from a tracked marker's cadence.
    g_r2mUnreadable.fetch_add(1, std::memory_order_relaxed);
  } else if (CpReadU32Raw(dstVa, &cur) && cur == swapped) {
    g_r2mSame.fetch_add(1, std::memory_order_relaxed);
  } else if (CpWriteU32Raw(dstVa, swapped)) {
    g_r2mWritten.fetch_add(1, std::memory_order_relaxed);
    CpNoteMemWriteDest(dst);
    // F-746: record what the POLL will read, not the register value. This store
    // is `xe::store<uint32_t>(ptr, GpuSwap(reg, endian))` (cc:1083-1086), a
    // PLAIN host store (base/memory.h:374-376), so the poll - which applies one
    // GpuSwap of its own (cc:982-983) - reads back `CpRegPeek(regAddr)` for all
    // four selectors. Same reasoning as the scratch site, different store shape.
    CpNoteMemWriteValue(dst, value);
  } else {
    g_r2mUnreadable.fetch_add(1, std::memory_order_relaxed);
  }
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN("CP-REG2MEM #{} reg={:04X} dst={:08X} endian={} "
                  "regValue={:08X} stored={:08X} || seen={} written={} "
                  "already-equal={} refused-reg={} unreadable={}",
                  n, regAddr, dst, memWord & 0x3u, value, swapped,
                  g_r2mSeen.load(std::memory_order_relaxed),
                  g_r2mWritten.load(std::memory_order_relaxed),
                  g_r2mSame.load(std::memory_order_relaxed),
                  g_r2mRefusedReg.load(std::memory_order_relaxed),
                  g_r2mUnreadable.load(std::memory_order_relaxed));
  }
  return true;
}

// ---------------------------------------------------------------------------
// F-XXX: PM4_COND_WRITE (0x45) - EXECUTED (was: unhandled, and the only
// guest-emitted opcode the host did not decode).
//
// WHAT THE GUEST EMITS. MEASURED, build/w842.log AND build/run845.txt (both
// 2026-10-21, identical shape):
//   CP-T3-UNHANDLED op=0x45 thisOp=1 .. thisOp=8      (8 rows per log)
//   CP-T3-CENSUS op=0x45 #1 count=6 depth=0 addr=B72EC850
//     args=00000007 00001925 00000000 FFFFFFFF 00001922 00000001
//   CP-T3-CENSUS op=0x45 #2 count=6 depth=0 addr=B72EC874
//     args=00000007 00001925 00100401 FFFFFFFF 00001922 00000002
//   CP-T3-CENSUS op=0x45 #3 count=6 depth=0 addr=B72EC898
//     args=00000007 00001925 00300C03 FFFFFFFF 00001922 00000003
// So: eight packets, six body dwords each, and the `ref` word of packet N is
// exactly the value the guest had just written to DC_LUT_30_COLOR
// (CP-GAMMA-LUT-UNMODELED #3/#4/#5 carry 00000000 / 00100401 / 00300C03).
//
// THE CONSOLE'S LAYOUT (guest facts; xenos gpu/xenos.h:1592 names the opcode,
// command_processor.cc:1110-1175 is the reference's own decoder). Six body
// dwords, in this order:
//   1 wait_info      (:1114) bits 0..2 = the comparison selector (the SAME
//                            seven-arm switch the reference uses for
//                            PM4_WAIT_REG_MEM, :1134-1159 == :990-1014);
//                            bit 4 (0x10) = the POLL target is MEMORY, else a
//                            REGISTER index (:1121-1131); bit 8 (0x100) = the
//                            WRITE target is MEMORY, else a REGISTER index
//                            (:1162-1171).
//   2 poll_reg_addr  (:1115) register index, or - in the memory form - a guest
//                            PHYSICAL address whose low two bits select the
//                            endianness (:1123-1124).
//   3 ref            (:1116)   4 mask (:1117)
//   5 write_reg_addr (:1118) register index, or (memory form) a guest PHYSICAL
//                            address + endianness selector (:1164-1165).
//   6 write_data     (:1119)
// The predicate is evaluated ONCE - this packet does NOT spin (that is 0x3C,
// command_processor.cc:977-1037). On a match the reference performs the write
// (:1160-1172) and returns true.
//
// WHAT THE GUEST'S EIGHT PACKETS DECODE TO, under that layout:
//   wait_info = 0x00000007 -> selector 7 = "Always" (:1156-1157) -> ALWAYS
//     matched. The poll is therefore irrelevant to the outcome, and this host
//     still evaluates it, because the reference does.
//   poll = 0x00001925 = DC_LUT_30_COLOR  (register_table.inc:452)
//   write target = 0x00001922 = DC_LUT_RW_INDEX (register_table.inc:433)
//   write_data = 1, 2, 3, ... 8
// So the console ADVANCES the gamma-ramp read/write index by one per packet.
// DC_LUT_RW_INDEX is the register that selects which LUT entry the sequential
// colour writes land on: register_table.inc:424-433 ("the index in 0:7 is
// just increased monotonically ... the index is 8-bit"), and the console's
// WriteRegister side effect for it is `gamma_ramp_rw_component_ = 0`
// (command_processor.cc:363-367) - it resets the R/G/B component cursor.
// This host has NO gamma table (F-610: the LUT is a census, not a model), so
// there is no component cursor to reset; the REGISTER is what the console
// changes and what this handler now changes.
//
// THE HOST'S BEHAVIOUR BEFORE THIS CHANGE: 0x45 fell through to `default:`
// (the switch's unhandled arm), so the packet was skipped, counted, and the
// stream continued. DC_LUT_RW_INDEX therefore stayed at whatever the guest
// last wrote there (0) for the whole boot - and the host's OWN census row
// says so: `CP-GAMMA-LUT-UNMODELED #1 reg=1922 (DC_LUT_RW_INDEX) val=00000000
// rwIndex=0000` and every later row also reads rwIndex=0000 (9/9 rows in
// build/w842.log, 9/9 in build/run845.txt).
//
// FALSIFIER (A): after this change CP-GAMMA-LUT-UNMODELED must STOP reading
// rwIndex=0000 - the row for the 0x1922 write must read rwIndex=0001, and the
// 0x1925 rows that come AFTER it must read 0001, 0002, 0003 (the console's
// index after each 0x45). The rows that PRECEDE the first 0x45 legitimately
// still read 0000 - they are the guest's own writes, before the cursor has
// moved, and a row that read 0000 there would be a defect. If the 0x1922 row
// still reads 0000, this handler did not run, or its register write did not
// land.
//
// WHAT IS NOT CHANGED HERE: the DC_LUT_30_COLOR auto-increment. The console
// ALSO bumps DC_LUT_RW_INDEX by one on every DC_LUT_30_COLOR write
// (command_processor.cc:448-477, `++new_gamma_ramp_rw_index.rw_index` and a
// recursive WriteRegister). That is a WriteRegister side effect on a
// DIFFERENT packet (the guest's own TYPE-0 write to 0x1925), and this change
// does not touch that path: the brief scopes this fix to the 0x45 decode, and
// "do not change the fallback behaviour of any other path" is the rule.
// It is recorded here as a KNOWN, DELIBERATE remaining divergence, and the
// console's index after a 0x1925 write is therefore NOT the console's index.
// ---------------------------------------------------------------------------
bool CpExecCondWrite(uint32_t byteAddr, uint32_t count, uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n = g_condWriteSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  // The stream always advances count+1, exactly as every other handler in this
  // file: a false return aborts the whole indirect buffer (DrainIndirectBuffer
  // at :6230, "desync at dword {} - aborting buffer"), which is worse than a
  // partial execution.
  outAdvance = count + 1u;
  if (count < 6u) {
    // The reference reads six words unconditionally (:1114-1119); upstream's
    // count is never this small. Refuse rather than read past the packet:
    // consumed, NOTHING written, NOT counted matched.
    const uint32_t r =
        g_condWriteShortBody.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (r <= 8u || (r % 200u) == 0u) {
      MCLA_LOG_WARN("CP-CONDWRITE-SHORT #{} count={} - the six body dwords "
                    "(command_processor.cc:1114-1119) are not all present; "
                    "consumed, NOTHING written, NOT counted matched",
                    r, count);
    }
    return true;
  }
  uint32_t body[6] = {0, 0, 0, 0, 0, 0};
  for (uint32_t i = 0; i < 6u; ++i) {
    if (!mem.ReadU32BE(byteAddr + 4u + i * 4u, &body[i])) {
      const uint32_t r =
          g_condWriteUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
      if (r <= 8u || (r % 200u) == 0u) {
        MCLA_LOG_WARN("CP-CONDWRITE-UNREADABLE #{} body dword {} - consumed, "
                      "NOTHING written, NOT counted matched",
                      r, i);
      }
      return true;
    }
  }
  const uint32_t waitInfo = body[0], pollAddr = body[1], ref = body[2],
                 mask = body[3], writeReg = body[4], writeData = body[5];
  const bool pollIsMemory = (waitInfo & 0x10u) != 0u;
  const bool writeIsMemory = (waitInfo & 0x100u) != 0u;
  static const char *const kCondWriteCmp[8] = {"never", "lt", "le", "eq",
                                              "ne",    "ge", "gt", "always"};

  // ---- the poll, in the reference's two forms (:1120-1132) ----------------
  uint32_t value = 0;
  uint32_t pollVA = 0;
  if (pollIsMemory) {
    const uint32_t pollByte = pollAddr & ~0x3u;
    pollVA = CpPhysToPoolVa(pollByte, "COND-WRITE");
    uint32_t raw = 0;
    if (pollVA == 0u || !CpReadU32Raw(pollVA, &raw)) {
      // No pool byte, or the byte is unreadable: the predicate CANNOT be
      // evaluated, so nothing is written. Refused by name and counted; this is
      // NOT "the predicate was false".
      const uint32_t r =
          g_condWritePollRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
      MCLA_LOG_WARN("CP-CONDWRITE-POLLREFUSED #{} poll={:08X} pollVA={:08X} "
                    "is_memory=1 - no pool byte / unreadable, so the predicate "
                    "cannot be evaluated. Consumed, NOTHING written, NOT counted "
                    "matched (see CP: POOL-XLATE-REFUSED). pollRefused={}",
                    r, pollAddr, pollVA, r);
      return true;
    }
    // F-721: ONE GpuSwap on the RAW host load, exactly as the reference does
    // (:978-983) and exactly as this file's PM4_WAIT_REG_MEM does (:3932).
    value = GpuSwap32(raw, pollAddr & 0x3u);
  } else {
    if (pollAddr >= kXenosRegCount) {
      // The reference asserts poll_reg_addr < RegisterFile::kRegisterCount
      // (:1130) and kRegisterCount is 0x5003 dwords (register_file.h:40) -
      // the same width as this file's kXenosRegCount. This host does not
      // assert on a guest-supplied value: the predicate is not evaluated,
      // nothing is written, and the refusal is counted.
      const uint32_t r =
          g_condWritePollRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
      MCLA_LOG_WARN("CP-CONDWRITE-POLLREFUSED #{} poll={:08X} is outside the "
                    "{:X}-dword register file (command_processor.cc:1130 "
                    "asserts; CpRegPeek would answer 0). Consumed, NOTHING "
                    "written, NOT counted matched. pollRefused={}",
                    r, pollAddr, kXenosRegCount, r);
      return true;
    }
    // The reference reads the register SHADOW, not a decoded name
    // (:1131 `value = register_file_->values[poll_reg_addr]`), and
    // CpRegPeek is that same shadow.
    value = CpRegPeek(pollAddr);
  }

  // ---- the predicate, the reference's seven arms, verbatim (:1134-1159) ---
  bool matched = false;
  switch (waitInfo & 0x7u) {
  case 0x0: matched = false; break;                              // Never
  case 0x1: matched = (value & mask) < ref; break;                // Less than
  case 0x2: matched = (value & mask) <= ref; break;               // Less or equal
  case 0x3: matched = (value & mask) == ref; break;               // Equal
  case 0x4: matched = (value & mask) != ref; break;               // Not equal
  case 0x5: matched = (value & mask) >= ref; break;               // Greater or eq
  case 0x6: matched = (value & mask) > ref; break;                // Greater than
  default:  matched = true; break;                                // Always
  }

  if (!matched) {
    const uint32_t r =
        g_condWriteNotMatched.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (r <= 8u || (r % 200u) == 0u) {
      MCLA_LOG_WARN("CP-CONDWRITE-NOTMATCHED #{} waitInfo={:08X} cmp={} "
                    "value={:08X} ref={:08X} mask={:08X} - the predicate is "
                    "FALSE, so the reference writes NOTHING (:1160-1172). "
                    "Consumed, NOT counted matched. notMatched={}",
                    r, waitInfo, kCondWriteCmp[waitInfo & 0x7u], value, ref,
                    mask, r);
    }
    return true;
  }
  g_condWriteMatched.fetch_add(1, std::memory_order_relaxed);

  // ---- the write, in the reference's two forms (:1160-1172) --------------
  if (writeIsMemory) {
    const uint32_t dst = writeReg & ~0x3u;
    const uint32_t dstVa = CpPhysToPoolVa(dst, "COND-WRITE");
    if (dstVa == 0u) {
      const uint32_t r =
          g_condWriteMemRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
      MCLA_LOG_WARN("CP-CONDWRITE-MEMREFUSED #{} dst={:08X} - no pool byte for "
                    "that physical address in this tree, so NOTHING stored (see "
                    "CP: POOL-XLATE-REFUSED). memRefused={}",
                    r, dst, r);
      return true;
    }
    // The reference stores `xe::store<uint32_t>(TranslatePhysical(addr),
    // GpuSwap(write_data, endianness))` (:1166-1167): a PLAIN host store of
    // the GpuSwap'd word. This file's CpWriteU32Raw is the measured contract
    // for exactly that (see its header at :3022 and the 0x3E site at
    // :3173/:3199), so the same one swap is applied here and nowhere else.
    const uint32_t swapped = GpuSwap32(writeData, writeReg & 0x3u);
    if (CpWriteU32Raw(dstVa, swapped)) {
      g_condWriteMemWritten.fetch_add(1, std::memory_order_relaxed);
      // The same two notifications every other store in this file makes, so a
      // later PM4_WAIT_REG_MEM can see this writer (CpMemWriteDestSeen /
      // CpMemWriteValuesSeen).
      CpNoteMemWriteDest(dst);
      CpNoteMemWriteValue(dst, writeData);
    } else {
      const uint32_t r =
          g_condWriteUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
      MCLA_LOG_WARN("CP-CONDWRITE-UNREADABLE #{} dst={:08X} - the store was "
                    "refused, NOTHING stored", r, dst);
    }
  } else {
    if (writeReg >= kXenosRegCount) {
      // WriteRegister refuses an out-of-file index with a log and a return
      // (:333-337). Same rule here: nothing written, counted by name.
      const uint32_t r =
          g_condWriteRegRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
      MCLA_LOG_WARN("CP-CONDWRITE-REGREFUSED #{} reg={:08X} is outside the "
                    "{:X}-dword register file - NOTHING written "
                    "(command_processor.cc:333-337 logs and returns). "
                    "regRefused={}",
                    r, writeReg, kXenosRegCount, r);
      return true;
    }
    // THE CONSOLE'S WRITE, on the console's own path: WriteRegister
    // (:1171) -> register_file_->values[index] = value. This file's
    // CpRegPoke is that store PLUS the file's own side effects (presence bit,
    // trace ring, scratch writeback, COHER dirty bit, the DC_LUT census at
    // :1117-1119) - and the DC_LUT census is exactly where the console's
    // index change becomes visible.
    CpRegPoke(writeReg, writeData);
    g_condWriteRegWritten.fetch_add(1, std::memory_order_relaxed);
  }

  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN("CP-CONDWRITE #{} waitInfo={:08X} cmp={} poll={:08X} "
                  "pollIsMemory={} pollVA={:08X} value={:08X} ref={:08X} "
                  "mask={:08X} writeReg={:08X} writeIsMemory={} "
                  "writeData={:08X} didMatch={} || seen={} matched={} "
                  "regWritten={} memWritten={} notMatched={} short={} "
                  "unreadable={} pollRefused={} regRefused={} memRefused={}",
                  n, waitInfo, kCondWriteCmp[waitInfo & 0x7u], pollAddr,
                  pollIsMemory ? 1 : 0, pollVA, value, ref, mask, writeReg,
                  writeIsMemory ? 1 : 0, writeData, matched ? 1 : 0,
                  g_condWriteSeen.load(std::memory_order_relaxed),
                  g_condWriteMatched.load(std::memory_order_relaxed),
                  g_condWriteRegWritten.load(std::memory_order_relaxed),
                  g_condWriteMemWritten.load(std::memory_order_relaxed),
                  g_condWriteNotMatched.load(std::memory_order_relaxed),
                  g_condWriteShortBody.load(std::memory_order_relaxed),
                  g_condWriteUnreadable.load(std::memory_order_relaxed),
                  g_condWritePollRefused.load(std::memory_order_relaxed),
                  g_condWriteRegRefused.load(std::memory_order_relaxed),
                  g_condWriteMemRefused.load(std::memory_order_relaxed));
  }
  return true;
}

// --- F-651 (2) PM4_WAIT_REG_MEM 0x3C - EXECUTED (was: REFUSED, not armed) ---
// ExecutePacketType3_WAIT_REG_MEM (command_processor.cc:955-1040), body dwords
// in the order the reference reads them:
//   1 = wait_info (:962)  bit 4 (0x10) = is_memory (:968); bits 0..2 = the
//       comparison selector (:990-1014)
//   2 = poll_addr (:963)  a REGISTER index when is_memory == 0, else a GUEST
//       PHYSICAL address, masked & ~3 (:973)
//   3 = ref  (:964)   4 = mask (:965)   5 = wait (:966)
// Then `do { ... } while (!matched)` (:977-1037): it SPINS until the predicate
// holds, and the only exits are the predicate or !worker_running_ (:1029-1032).
// wait >= 0x100 means "sleep wait/0x100 ms" (:1024), not "give up".
//
// PACKET LAYOUT, MEASURED FROM THE GUEST'S OWN RAW BYTES (not from a doc, and
// not from a decompiler - ppc_disasm.py, offset = VA - 0x82000000):
//   sub_82421CA0, instruction 0x82421E28 (fn 0x82421CA0+0x188) builds the
//   register form with, in order:
//     0x82421E28 ori  r7,r10,3C00     (r10 already = 0xC0040000 from 0x82421E1C
//                                       lis r7,C004) -> header 0xC0043C00
//     0x82421E2C li   r7,3            -> wait_info  = 0x00000003
//     0x82421E30 li   r6,2609         -> poll       = 0x00000A31
//     0x82421E34 li   r5,0            -> ref        = 0x00000000
//     0x82421E3C lis  r4,8000         -> mask       = 0x80000000
//     0x82421E40 li   r30,8           -> wait       = 0x00000008
//   and the five payload dwords are stored in that order. So:
//     header 0xC0043C00 : type3, opcode 0x3C, count = (0xC004 & 0x3FFF)+1 = 5.
//   This is byte-for-byte the packet captured in build/w677.log, PKT-CAP #0006
//   at win=B7C8A2BC: "C0043C00 00000003 00000A31 00000000 80000000 00000008".
//   The memory form is built the same way at 0x82419A08/0x82419A10
//   (sub_824199B0+0x60) with wait_info = 0x13 (li r9,19 at 0x82419A0C):
//   bit 4 set = is_memory, bits 0..2 = 3 = kEqual. Six other
//   `ori rA,rS,0x3C00` sites exist, all 4-aligned, all measured with
//   tools/ppc_xrefs.py fn:
//     0x82411FA4 sub_82411F68+0x3c   0x82419A10 sub_824199B0+0x60
//     0x82419B24 sub_824199B0+0x174  0x82419D40 sub_82419CB8+0x88
//     0x8241DF98 sub_8241DE08+0x190  0x82420F2C sub_82420BA8+0x384
//     0x8242190C sub_82420BA8+0xd64  0x82421E28 sub_82421CA0+0x188
//   (`ori rA,rS,0x3C00` also matches 0x82232227, which is NOT 4-aligned: it is
//   inside data, not code.)
//
// 0x22 (PM4_DRAW_INDX) IS NOT SUPPORTED ON THE ASSUMPTION IT OCCURS, because it
// does not. Whole-image scan of build/cache/mcla_pe.bin (offset = VA -
// 0x82000000) for `ori rA,rS,0x2200` over all 32x32 register pairs: 4 raw
// matches, ALL AT ONE ADDRESS (0x82086F6B), which is not 4-aligned and which
// ppc_disasm.py renders as ASCII text ("...stant object ..."), i.e. data - so
// ZERO instruction sites. The guest emits 0x36 (PM4_DRAW_INDX_2), built
// `lis rA,C000` + `ori rA,rA,3600`; the 4-aligned `ori ..,0x3600` sites
// measured are 0x824217C8, 0x82417614, 0x8242255C, 0x8242283C, 0x824278D0
// (the last two confirmed by ppc_xrefs.py fn -> sub_824225E0+0x254 /
// sub_82427898+0x30). kPm4DrawIndx stays declared and dispatched because the
// opcode exists in the reference; it is never synthesised, and 0x36 is what
// the bridge must actually handle.
//
// WHAT THE CONSOLE'S COHERENCE ACTUALLY GUARANTEES. Read from the reference,
// not invented. MakeCoherent (command_processor.cc:486-524) does exactly three
// things: return immediately if COHER_STATUS_HOST.status (bit 31,
// registers.h:88) is clear (:505-507); XELOGD the COHER_BASE_HOST..+SIZE_HOST
// range and the VC/TC action (:519-520); and write
// regs_volatile[COHER_STATUS_HOST] = 0 (:523). The resource-cache
// notification is a TODO at :518, so upstream has NO flush either - the
// hardware cache flush (VC/TC) is what the console does and is not observable
// on this host, and the only CPU-visible effect the reference produces is the
// dirty bit going to zero. That is reproduced here verbatim and NOTHING MORE is
// added: no invented cache, no synchronisation primitive, no synthesised
// value. The comment this replaces was right that the bit is set by our own
// CpRegPoke (command_processor.cc:358-361) - but the same reference CLEARS it
// from inside the wait's own poll (:985-988), which is the missing half.
//
// ESCAPE POLICY. The reference has no timeout: its only escape is
// !worker_running_ (:1029-1032), i.e. the OS killing the thread. On this host
// nothing can do that, so an unsatisfiable wait would wedge the guest thread
// and the boot. The policy is therefore:
//   * poll with the reference's own cadence - wait >= 0x100 -> sleep
//     wait/256 ms (:1018-1025), else yield (:1034). The guest's own wait field
//     is 8, i.e. the YIELD branch, so this is a yield-spin, never a hot loop.
//   * re-evaluate the predicate every iteration, so a value published by
//     another thread is picked up; the value is READ, never written.
//   * bound the wait by wall clock (kWaitRegMemBudgetMs, default 2000 ms,
//     overridable with cp_wait_regmem_ms). A bound is needed because the only
//     writer of a polled location on this host is the SAME thread that is
//     spinning, so a wait whose value nothing else can move is provably
//     unsatisfiable and spinning is pure latency.
//   * on expiry: DO NOT RETURN TRUE. Returning true would advance the stream
//     over a predicate that is false, which is the "silently proceeds" fake
//     the native-only charter (F-609) forbids and which a soak could not
//     distinguish from a satisfied fence. Instead set
//     g_waitRegMemParkPending, which makes the walker leave its cursor where it
//     is, and report. The stream stops visibly; nothing is fabricated.
//
// The four markers a soak needs are therefore distinct literals:
//   CP-WAITREG-ISSUED / CP-WAITREG-SATISFIED / CP-WAITREG-TIMEOUT /
//   CP-WAITREG-NEVERWRITTEN, each carrying all running counters.
constexpr uint32_t kRegCoherBaseHost = 0x0A32u; // registers.h COHER_BASE_HOST
constexpr uint32_t kRegCoherSizeHost = 0x0A33u; // registers.h COHER_SIZE_HOST
constexpr uint32_t kWaitRegMemBudgetMs = 2000u;

uint32_t CpWaitRegMemBudgetMs() {
  static const uint32_t v = [] {
    const char *e = std::getenv("cp_wait_regmem_ms");
    if (e) {
      const long x = std::strtol(e, nullptr, 10);
      if (x > 0 && x < 600000)
        return static_cast<uint32_t>(x);
    }
    return kWaitRegMemBudgetMs;
  }();
  return v;
}

inline bool CpRegPresent(uint32_t index) {
  if (index >= kXenosRegCount)
    return false;
  return (g_xenosRegPresent[index >> 5].load(std::memory_order_acquire) &
          (1u << (index & 31u))) != 0u;
}

void CpNoteMemWriteDest(uint32_t byteAddr) {
  const uint32_t i =
      g_memWriteDestNext.fetch_add(1, std::memory_order_relaxed) %
      kMemWriteDestSlots;
  g_memWriteDest[i].store(byteAddr, std::memory_order_relaxed);
  g_memWriteDestStores.fetch_add(1, std::memory_order_relaxed);
}

bool CpMemWriteDestSeen(uint32_t byteAddr) {
  for (uint32_t i = 0; i < kMemWriteDestSlots; ++i) {
    if (g_memWriteDest[i].load(std::memory_order_relaxed) == byteAddr)
      return true;
  }
  return false;
}

// F-746. Records the (destination, WORD AS THE WAIT WILL SEE IT) pair for every
// store this file makes. The word recorded is the post-GpuSwap32 value the
// reference's own poll would compute for the selector that store used, because
// that is the number a later PM4_WAIT_REG_MEM compares against `ref` - so a row
// built from this ring is directly comparable to `ref` with no further
// arithmetic and no guess about which endianness applies.
//
// NOTHING HERE CAN SATISFY OR UNSATISFY A WAIT. The predicate is evaluated from
// CpReadU32Raw(pollVA) and from nothing else, exactly as before; this ring is
// read only on the timeout path, to let the refusal NAME what it is refusing
// instead of shrugging. Registration happens on the same condition as
// CpNoteMemWriteDest (the store was accepted), and the scratch site is the only
// one gated on `ok`.
//
// NEW SYMBOLS, listed for rule 1b: CpNoteMemWriteValue, CpMemWriteValuesSeen,
// g_memWriteValDest, g_memWriteValWord, g_memWriteValNext, g_memWriteValStores,
// kMemWriteValSlots, g_waitRegMemWriterValues, g_waitRegMemPktBytes.
void CpNoteMemWriteValue(uint32_t byteAddr, uint32_t value) {
  const uint32_t i =
      g_memWriteValNext.fetch_add(1, std::memory_order_relaxed) %
      kMemWriteValSlots;
  g_memWriteValDest[i].store(byteAddr, std::memory_order_relaxed);
  g_memWriteValWord[i].store(value, std::memory_order_relaxed);
  g_memWriteValStores.fetch_add(1, std::memory_order_relaxed);
}

// Distinct values this host has published at `byteAddr`, most recent first, up
// to `maxOut`. Returns how many slots were filled. The slot count is the honest
// bound: a ring of N slots can hold N pairs, so a byte that has been written
// more than N times may have older values overwritten. The caller prints the
// bound rather than implying completeness.
uint32_t CpMemWriteValuesSeen(uint32_t byteAddr, uint32_t *out, uint32_t maxOut) {
  if (out == nullptr || maxOut == 0u)
    return 0u;
  uint32_t n = 0;
  // Walk the ring newest-first: the newest pair is the one the poll would have
  // read had nothing else run since.
  for (uint32_t k = 0; k < kMemWriteValSlots && n < maxOut; ++k) {
    const uint32_t i = (g_memWriteValNext.load(std::memory_order_relaxed) +
                        kMemWriteValSlots - 1u - k) %
                       kMemWriteValSlots;
    if (g_memWriteValDest[i].load(std::memory_order_relaxed) != byteAddr)
      continue;
    const uint32_t v = g_memWriteValWord[i].load(std::memory_order_relaxed);
    bool dup = false;
    for (uint32_t j = 0; j < n; ++j) {
      if (out[j] == v) {
        dup = true;
        break;
      }
    }
    if (!dup)
      out[n++] = v;
  }
  return n;
}

// command_processor.cc:486-524, reproduced exactly and no further. The only
// store is the dirty-bit clear at :523; the COHER_BASE_HOST/COHER_SIZE_HOST
// range and the VC/TC/PGLB action are REPORTED (:519-520), never acted on,
// because upstream does not act on them either (:518 is a TODO).
void CpMakeCoherent(const char *from) {
  const uint32_t status = CpRegPeek(kRegCoherStatusHost);
  if ((status & kCoherStatusBit) == 0u) {
    const uint32_t k = g_coherentNoop.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (k <= 8u || (k % 200u) == 0u) {
      MCLA_LOG_WARN("CP-COHERENT #{} NOOP from={} status={:08X} (status bit "
                    "already clear; command_processor.cc:505-507 returns here "
                    "without touching anything)",
                    k, from, status);
    }
    return;
  }
  const uint32_t base = CpRegPeek(kRegCoherBaseHost);
  const uint32_t size = CpRegPeek(kRegCoherSizeHost);
  const char *action = "N/A";
  if ((status & 0x03000000u) == 0x03000000u)
    action = "VC | TC";
  else if (status & 0x02000000u)
    action = "TC";
  else if (status & 0x01000000u)
    action = "VC";
  else if (status & 0x04000000u)
    action = "PGLB";
  const uint32_t k = g_coherentCleared.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (k <= 8u || (k % 200u) == 0u) {
    MCLA_LOG_WARN("CP-COHERENT #{} CLEAR from={} {:08X}->{:08X} base={:08X} "
                  "size={:08X}b action={} - COHER_STATUS_HOST.status (bit 31, "
                  "registers.h:88) zeroed, the whole of MakeCoherent "
                  "(command_processor.cc:523). The VC/TC cache invalidate is "
                  "hardware and is NOT modelled; upstream does not model it "
                  "either (:518 TODO)",
                  k, from, status, 0u, base, size, action);
  }
  g_xenosReg[kRegCoherStatusHost].store(0u, std::memory_order_relaxed);
  if (kRegCoherStatusHost < kMmioRegCount) {
    g_regShadow[kRegCoherStatusHost].store(0u, std::memory_order_relaxed);
  }
}

// `next(&out)` yields payload dword i (0-based) of THIS packet from wherever
// the packet lives (linear guest memory for an indirect buffer, the ring's own
// arithmetic for a ring packet) so one implementation serves both and the two
// cannot drift. Returns false when the dword cannot be read.
template <typename NextWord>
bool CpExecWaitRegMem(const char *from, uint32_t count, uint32_t headerWord,
                      NextWord &&next, uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n =
      g_waitRegMemSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  outAdvance = count + 1u;
  if (count < 5u) {
    // Upstream's count is never this small (:962-966 reads five words). Refuse
    // rather than read past the packet; consumed, no predicate claimed.
    const uint32_t r =
        g_waitRegMemUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (r <= 8u || (r % 200u) == 0u) {
      MCLA_LOG_WARN("CP-WAITREG-ISSUED #{} from={} count={} SHORT BODY - the "
                    "five body dwords (command_processor.cc:962-966) are not "
                    "all present; consumed, NOT counted satisfied",
                    r, from, count);
    }
    return true;
  }
  uint32_t body[5] = {0, 0, 0, 0, 0};
  for (uint32_t i = 0; i < 5u; ++i) {
    if (!next(&body[i])) {
      const uint32_t r =
          g_waitRegMemUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
      if (r <= 8u || (r % 200u) == 0u) {
        MCLA_LOG_WARN("CP-WAITREG-ISSUED #{} from={} hdr={:08X} body dword {} "
                      "UNREADABLE - consumed, NOT counted satisfied",
                      r, from, headerWord, i);
      }
      return true;
    }
  }
  const uint32_t waitInfo = body[0], poll = body[1], ref = body[2],
                 mask = body[3], wait = body[4];
  const bool isMemory = (waitInfo & 0x10u) != 0u;
  (isMemory ? g_waitRegMemMem : g_waitRegMemReg)
      .fetch_add(1, std::memory_order_relaxed);
  static const char *const kCmp[8] = {"never", "lt",     "le",  "eq",
                                      "ne",    "ge",     "gt",  "always"};
  const uint32_t pollByte = poll & ~0x3u;
  // F-680: the MEMORY form's poll target is a guest PHYSICAL address, so it goes
  // through the one view->pool rule. This site is part of the SAME fix as the
  // indirect-buffer pointer, not a second change: both were `| 0xC0000000`, both
  // therefore read the same 0x20000000-above-the-pool address, and both fed
  // heads full of zeros. The guest demonstrably builds this form - sub_824199B0
  // emits wait_info=0x13 (bit 4 set = memory) - so the arm is reachable, not
  // hypothetical.
  const uint32_t pollVA =
      isMemory ? CpPhysToPoolVa(pollByte, "WAIT-REG-MEM") : poll;
  if (isMemory && pollVA == 0u) {
    // NO FALLBACK, and no silent spin: address 0 is a perfectly readable byte of
    // this flat window, so polling it would return 0, fail the predicate and
    // burn the whole budget to reach "timed out" - a wrong answer with no error
    // anywhere. Refuse explicitly instead, consumed and NOT counted satisfied,
    // exactly like the UNREADABLE arm below. `CP: POOL-XLATE-REFUSED` carries the
    // full reason and the attempt index.
    const uint32_t r =
        g_waitRegMemNoPoolByte.fetch_add(1, std::memory_order_relaxed) + 1u;
    MCLA_LOG_WARN("CP-WAITREG-NOPOOLBYTE #{} from={} waitInfo={:08X} cmp={} "
                  "poll={:08X} ref={:08X} mask={:08X} - this tree has no pool "
                  "byte for that physical address, so the predicate cannot be "
                  "evaluated. Consumed, NOT counted satisfied, NOT parked (see "
                  "CP: POOL-XLATE-REFUSED). noPoolByte={} issued={}",
                  r, from, waitInfo, kCmp[waitInfo & 0x7u], poll, ref, mask, r,
                  g_waitRegMemSeen.load(std::memory_order_relaxed));
    return true;
  }
  if (n <= 8u || (n % 200u) == 0u) {
    // F-746, NEW ROW, NEW NAME, CENSUS: nothing above or below this block
    // changes. The CP-WAITREG-ISSUED row keeps its exact field set, order and
    // count, and the firing bound `n <= 8 || n % 200 == 0` is the SAME one, so a
    // soak can still multiset-diff the two together.
    //
    // WHY IT EXISTS. build/w703.log decided every field of the failing wait
    // EXCEPT the one that mattered: the log carries `ref=00000000` but not the
    // packet's bytes, so "is that 0 the number the guest put in body dword 3?"
    // could not be answered from the log at all - only from the guest's own
    // builder. This row closes that gap for the NEXT soak by printing the six
    // reader values verbatim.
    //
    // WHAT THE SIX NUMBERS ARE, exactly. They are what the reader handed the
    // decoder, i.e. a big-endian 32-bit read of guest memory with Swap32 applied
    // - the same value `RingBuffer::ReadAndSwap<uint32_t>()` returns to the
    // reference at command_processor.cc:962-966. They are NOT the bytes in memory
    // and NOT the host's little-endian image of them; a row can be re-derived
    // from them by writing them big-endian, and the decode below is re-derived
    // from them by the same five assignments the code performs.
    const uint32_t p =
        g_waitRegMemPktBytes.fetch_add(1, std::memory_order_relaxed) + 1u;
    MCLA_LOG_WARN("CP-WAITREG-PKTBYTES #{} from={} n={} hdr={:08X} b1={:08X} "
                  "b2={:08X} b3={:08X} b4={:08X} b5={:08X} - the six reader "
                  "values of this packet verbatim, in stream order. b1..b5 are "
                  "what command_processor.cc:962-966 reads: wait_info, "
                  "poll_addr, ref, mask, wait. hdr must be type3 (top two bits "
                  "11), opcode 0x3C (bits 15:8) and count 4 (bits 27:16) for "
                  "those five to be this packet's body at all",
                  p, from, n, headerWord, body[0], body[1], body[2], body[3],
                  body[4]);
    MCLA_LOG_WARN("CP-WAITREG-ISSUED #{} from={} hdr={:08X} waitInfo={:08X} "
                  "is_memory={} cmp={} poll={:08X} pollVA={:08X} ref={:08X} "
                  "mask={:08X} wait={:08X} || seen={} reg={} mem={}",
                  n, from, headerWord, waitInfo, isMemory ? 1 : 0,
                  kCmp[waitInfo & 0x7u], poll, pollVA, ref, mask, wait,
                  g_waitRegMemSeen.load(std::memory_order_relaxed),
                  g_waitRegMemReg.load(std::memory_order_relaxed),
                  g_waitRegMemMem.load(std::memory_order_relaxed));
  }

  // wait_info & 7 == 0 is CompareFunction::kNever: the reference's switch arm
  // sets matched = false unconditionally (:991-992) and its only exit is the
  // predicate or !worker_running_. Spinning on it can never succeed, so it is
  // reported and parked immediately instead of burning the budget to reach the
  // same answer.
  if ((waitInfo & 0x7u) == 0u) {
    const uint32_t r =
        g_waitRegMemUnmatchable.fetch_add(1, std::memory_order_relaxed) + 1u;
    MCLA_LOG_WARN("CP-WAITREG-NEVERWRITTEN #{} from={} waitInfo={:08X} "
                  "cmp=never - command_processor.cc:991-992 can never set "
                  "matched, so this predicate is unsatisfiable BY CONSTRUCTION "
                  "(not by a missing writer). PARKED: rptr NOT advanced",
                  r, from, waitInfo);
    g_waitRegMemParked.fetch_add(1, std::memory_order_relaxed);
    g_waitRegMemParkPending.store(1u, std::memory_order_relaxed);
    return false;
  }

  // "Is there a writer at all?" - answered from what this file has actually
  // issued, never guessed. A REGISTER is written iff its presence bit is set
  // (set by CpRegPoke at :476-477 and by nothing else in the file). GUEST
  // MEMORY is checked against the 256-entry most-recent-destination ring fed
  // by every store this file makes, so a miss is "not among those", which the
  // row says in words rather than dressing up as proof.
  //
  // ADDRESS SPACE (measured fix). Both CpNoteMemWriteDest callers pass a GUEST
  // PHYSICAL address: CpExecEventWriteShd passes `address & ~3` (:3097, the
  // packet's own address word) and ExecuteMemWrite passes `addr & ~3` (:3152).
  // The lookup below used to be handed `pollVA`, which is the flat-window POOL VA
  // - so the ring was filled with 0x1840B284 and searched for 0xB840B284, 0xA0000000
  // apart, and could NEVER match. That made `memDestSeen=0` a GUARANTEED FALSE
  // NEGATIVE, and with it the whole CP-WAITREG-NEVERWRITTEN claim "no writer this
  // host implements could have produced the value". w700.log refutes that on its
  // own next line: `CP-EVENTSHD #1 ... dst=1840B284 written=1` at 06:13:25.071 is
  // a writer this host implements, storing to the byte the wait polls 784 ms
  // later. `pollByte` is the same guest physical address, so both sides of the
  // comparison are now in ONE address space. Nothing about the wait's OUTCOME
  // changes: this only decides which diagnosis row prints.
  const bool regWritten = isMemory ? false : CpRegPresent(poll);
  const bool memWritten = isMemory ? CpMemWriteDestSeen(pollByte) : false;
  const bool anyWriter = isMemory ? memWritten : regWritten;

  const auto t0 = std::chrono::steady_clock::now();
  const uint32_t budgetMs = CpWaitRegMemBudgetMs();
  uint64_t spins = 0;
  uint32_t value = 0;
  uint32_t rawSeen = 0;
  bool matched = false;
  bool timedOut = false;
  for (;;) {
    ++spins;
    if (!isMemory) {
      // command_processor.cc:985-988: a register poll of COHER_STATUS_HOST runs
      // MakeCoherent INSIDE the poll and then RE-READS the register. That
      // re-read is what makes the fence satisfiable, and it is the step this
      // host was missing.
      if (poll == kRegCoherStatusHost) {
        CpMakeCoherent(from);
      }
      value = CpRegPeek(poll);
    } else {
      if (!CpReadU32Raw(pollVA, &rawSeen)) {
        const uint32_t r =
            g_waitRegMemUnreadable.fetch_add(1, std::memory_order_relaxed) + 1u;
        MCLA_LOG_WARN("CP-WAITREG-ISSUED #{} from={} pollVA={:08X} UNREADABLE "
                      "after {} spin(s) - consumed, NOT counted satisfied",
                      r, from, pollVA, spins);
        g_waitRegMemSpins.fetch_add(spins, std::memory_order_relaxed);
        g_waitRegMemWaitedMs.fetch_add(
            static_cast<uint64_t>(
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - t0)
                    .count()),
            std::memory_order_relaxed);
        return true;
      }
      // F-721: GpuSwap ONCE, on the RAW host load, exactly as
      // command_processor.cc:978-983 does. This used to be
      // `mem.ReadU32BE(pollVA, &rawSeen)` followed by `GpuSwap32(rawSeen, poll & 3)`,
      // and ReadU32BE ALREADY byte-swaps (kernel/memory.cpp:221-222), so the pair
      // swapped twice. The comment that stood here called that "the mirror of
      // upstream's read-then-GpuSwap on a little-endian host"; that was a GLOSS
      // and it is wrong - the raw host load is not what ReadU32BE returns. The
      // measured consequence for w702.log's own row: with the writer's 1 in the
      // polled dword and poll&3==2, the reference reads 00000001 (== ref, so the
      // fence PASSES) and this host read 01000000 (!= ref, so it TIMED OUT and
      // parked the ring). `raw=` still reports the raw host dword so a soak can
      // falsify this the same way it could before.
      value = GpuSwap32(rawSeen, poll & 0x3u);
      if ((poll & 0x3u) != 0u) {
        g_waitRegMemEndianSwap.fetch_add(1, std::memory_order_relaxed);
      }
    }
    switch (waitInfo & 0x7u) {
    case 0x0: matched = false; break;
    case 0x1: matched = (value & mask) < ref; break;
    case 0x2: matched = (value & mask) <= ref; break;
    case 0x3: matched = (value & mask) == ref; break;
    case 0x4: matched = (value & mask) != ref; break;
    case 0x5: matched = (value & mask) >= ref; break;
    case 0x6: matched = (value & mask) > ref; break;
    default: matched = true; break;
    }
    if (matched)
      break;
    const auto elapsedMs = static_cast<uint32_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0)
            .count());
    if (elapsedMs >= budgetMs) {
      timedOut = true;
      break;
    }
    if (wait >= 0x100u) {
      std::this_thread::sleep_for(std::chrono::milliseconds(wait / 0x100u));
    } else {
      std::this_thread::yield();
    }
  }
  const uint32_t waitedMs = static_cast<uint32_t>(
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::steady_clock::now() - t0)
          .count());
  g_waitRegMemSpins.fetch_add(spins, std::memory_order_relaxed);
  g_waitRegMemWaitedMs.fetch_add(waitedMs, std::memory_order_relaxed);

  if (timedOut) {
    const uint32_t r =
        g_waitRegMemTimeout.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (r <= 8u || (r % 200u) == 0u) {
      MCLA_LOG_WARN("CP-WAITREG-TIMEOUT #{} from={} hdr={:08X} waitInfo={:08X} "
                    "is_memory={} cmp={} poll={:08X} pollVA={:08X} ref={:08X} "
                    "mask={:08X} wait={:08X} value={:08X} raw={:08X} "
                    "spins={} waited={}ms budget={}ms || issued={} "
                    "satisfied={} satAfterSpin={} timedOut={} - PREDICATE FALSE. "
                    "NOT advanced and NOT counted satisfied: returning true "
                    "here would be a silent proceed",
                    r, from, headerWord, waitInfo, isMemory ? 1 : 0,
                    kCmp[waitInfo & 0x7u], poll, pollVA, ref, mask, wait, value,
                    rawSeen, spins, waitedMs, budgetMs,
                    g_waitRegMemSeen.load(std::memory_order_relaxed),
                    g_waitRegMemSat.load(std::memory_order_relaxed),
                    g_waitRegMemSatSpin.load(std::memory_order_relaxed),
                    g_waitRegMemTimeout.load(std::memory_order_relaxed));
    }
    if (!anyWriter) {
      const uint32_t w = g_waitRegMemNeverWritten.fetch_add(
                             1, std::memory_order_relaxed) +
                         1u;
      if (w <= 8u || (w % 200u) == 0u) {
        MCLA_LOG_WARN("CP-WAITREG-NEVERWRITTEN #{} from={} target={} is_memory={} "
                      "regPresent={} memDestSeen={} - timed out AND no writer "
                      "this host implements could have produced the value "
                      "(register: presence bit clear; memory: not among the "
                      "last {} distinct store destinations, stores={})",
                      w, from, pollVA, isMemory ? 1 : 0, regWritten ? 1 : 0,
                      memWritten ? 1 : 0, kMemWriteDestSlots,
                      g_memWriteDestStores.load(std::memory_order_relaxed));
      }
    } else {
      // NEW ROW, NEW NAME. Falsified CP-WAITREG-NEVERWRITTEN's own text for this
      // case: a writer DID run at the polled byte. This host does NOT publish the
      // word that writer stored - that word is whichever packet reached it, and
      // the only honest statement available here is "a writer fired, the value it
      // left does not satisfy the predicate". Naming the word would mean
      // inventing it (F-609).
      //
      // w700.log is this case exactly: CP-EVENTSHD #1 stored to guest physical
      // 0x1840B284 at 06:13:25.071, and CP-WAITREG #6 polls that same byte at
      // 06:13:25.855 for 1. The store is ALSO not reaching the polled byte as a
      // like-for-like, which is a separate defect this row does not claim to fix:
      // the store goes to the flat guest view at the guest PHYSICAL address
      // (:3098) while the poll goes to the POOL VA (:2899), 0xA0000000 apart.
      const uint32_t w = g_waitRegMemWriterMismatch.fetch_add(
                             1, std::memory_order_relaxed) +
                         1u;
      if (w <= 8u || (w % 200u) == 0u) {
        MCLA_LOG_WARN("CP-WAITREG-WRITER-MISMATCH #{} from={} pollVA={:08X} "
                      "pollPhys={:08X} is_memory={} cmp={} value={:08X} "
                      "ref={:08X} mask={:08X} stores={} - a writer this host "
                      "implements DID store to this guest byte (it is among the "
                      "last {} distinct store destinations), but the value it "
                      "left does not satisfy the predicate, so this wait still "
                      "TIMED OUT and STILL PARKED; it is NOT counted satisfied "
                      "and rptr is NOT advanced",
                      w, from, pollVA, pollByte, isMemory ? 1 : 0,
                      kCmp[waitInfo & 0x7u], value, ref, mask,
                      g_memWriteDestStores.load(std::memory_order_relaxed),
                      kMemWriteDestSlots);
      }
      // F-746, NEW ROW, NEW NAME, CENSUS. CP-WAITREG-WRITER-MISMATCH above is
      // UNCHANGED - same fields, same order, same bound, same counter. This row
      // is added AFTER it, inside the same `else` (a writer did fire), and it
      // returns nothing and skips nothing: the two g_waitRegMemParked /
      // g_waitRegMemParkPending lines below run exactly as before, for this row
      // as for every other path.
      //
      // WHAT IT ADDS, and why the sibling row could not. "A writer fired and left
      // the wrong number" and "no writer this host implements can ever leave the
      // wanted number HERE" call for opposite next steps - hunt a clobbering
      // store, versus stop looking for one - and CP-WAITREG-WRITER-MISMATCH's
      // text, correctly, claims only the first half of the first statement. The
      // distinction is answerable without inventing anything, because this file
      // knows every word it has published and to where: the (dest, value) ring
      // fed at all four store sites. So the row prints the distinct words this
      // host has put at this byte and says, in words, whether the predicate's
      // target is among them.
      //
      // MEASURED CASE THIS ROW EXISTS FOR, build/w703.log. Byte 0x1840B280
      // (pool 0xB840B280) received 0x00000003 (CP-EVENTSHD #2) and 0x00000004
      // (CP-SCRATCH-WB-ADDR #5, reg 0578 slot 0); CP-MEMWRITE and CP-REG2MEM
      // printed ZERO rows against `n <= 12` / `n <= 8` bounds, so those two
      // handlers never ran even once; CP: IB-OPC-CENSUS #9's opcode list for the
      // parked indirect buffer carries no 0x3D, 0x3E or 0x58 at all. A wait then
      // wanted 0x00000000 there. `distinct=` would have read 2 with
      // `refAmong=0`, and the honest sentence is the one this row prints:
      // nothing here ever published the wanted word. No store was dropped - none
      // was attempted.
      if (isMemory) {
        // Zero-initialised: the row prints eight v-slots unconditionally so the
        // field count never depends on the data, which means every slot past
        // `distinct` MUST be defined. An earlier version of this row left them
        // uninitialised and the harness printed stack garbage there (v2..v7 =
        // 1FD5F638 ...) - caught by the harness, not by a soak.
        uint32_t seen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        const uint32_t nv =
            CpMemWriteValuesSeen(pollByte, seen, static_cast<uint32_t>(8));
        bool refAmong = false;
        for (uint32_t i = 0; i < nv; ++i) {
          if ((seen[i] & mask) == ref) {
            refAmong = true;
            break;
          }
        }
        const uint32_t v =
            g_waitRegMemWriterValues.fetch_add(1, std::memory_order_relaxed) + 1u;
        // Printed as `v0..v7=` with unused slots left as 0 and `distinct=` giving
        // the real count, so the field count never depends on the data - a
        // varying argument count in one format string is exactly the trap an fmt
        // extra argument hides silently.
        MCLA_LOG_WARN("CP-WAITREG-WRITER-VALUES #{} from={} pollPhys={:08X} "
                      "cmp={} ref={:08X} mask={:08X} value={:08X} distinct={} "
                      "refAmong={} v0={:08X} v1={:08X} v2={:08X} v3={:08X} "
                      "v4={:08X} v5={:08X} v6={:08X} v7={:08X} ringSlots={} "
                      "ringStores={} - v0..v7 are the DISTINCT words this host "
                      "has ever published at this guest byte, newest first, each "
                      "already in the units the poll compares (the store's own "
                      "GpuSwap cancelled by the poll's, command_processor.cc:982 "
                      "-983 against :1085 / :1101 / :1213 / :351); distinct is "
                      "how many of the eight slots are real. refAmong=0 means the "
                      "word this predicate wants is NOT among them, i.e. NO store "
                      "this file implements has ever produced it here - the "
                      "satisfier is not in this PM4 stream and widening the "
                      "comparison would be a fabrication. ringSlots is the honest "
                      "bound on completeness: a byte written more than that many "
                      "times can have older words overwritten. STILL PARKED: not "
                      "counted satisfied, rptr NOT advanced",
                      v, from, pollByte, kCmp[waitInfo & 0x7u], ref, mask, value,
                      nv, refAmong ? 1 : 0, seen[0], seen[1], seen[2], seen[3],
                      seen[4], seen[5], seen[6], seen[7], kMemWriteValSlots,
                      g_memWriteValStores.load(std::memory_order_relaxed));
      }
    }
    g_waitRegMemParked.fetch_add(1, std::memory_order_relaxed);
    g_waitRegMemParkPending.store(1u, std::memory_order_relaxed);
    return false;
  }

  g_waitRegMemSat.fetch_add(1, std::memory_order_relaxed);
  if (spins > 1u) {
    g_waitRegMemSatSpin.fetch_add(1, std::memory_order_relaxed);
  }
  const uint32_t s =
      g_waitRegMemSat.load(std::memory_order_relaxed);
  if (s <= 8u || (s % 200u) == 0u) {
    MCLA_LOG_WARN("CP-WAITREG-SATISFIED #{} from={} hdr={:08X} is_memory={} "
                  "cmp={} poll={:08X} pollVA={:08X} ref={:08X} mask={:08X} "
                  "value={:08X} spins={} waited={}ms || issued={} reg={} "
                  "mem={} satisfied={} satAfterSpin={} timedOut={} "
                  "neverWritten={} coherCleared={} coherNoop={}",
                  s, from, headerWord, isMemory ? 1 : 0, kCmp[waitInfo & 0x7u],
                  poll, pollVA, ref, mask, value, spins, waitedMs,
                  g_waitRegMemSeen.load(std::memory_order_relaxed),
                  g_waitRegMemReg.load(std::memory_order_relaxed),
                  g_waitRegMemMem.load(std::memory_order_relaxed),
                  g_waitRegMemSat.load(std::memory_order_relaxed),
                  g_waitRegMemSatSpin.load(std::memory_order_relaxed),
                  g_waitRegMemTimeout.load(std::memory_order_relaxed),
                  g_waitRegMemNeverWritten.load(std::memory_order_relaxed),
                  g_coherentCleared.load(std::memory_order_relaxed),
                  g_coherentNoop.load(std::memory_order_relaxed));
  }
  return true;
}

bool CpExecWaitRegMemAt(uint32_t byteAddr, uint32_t count, uint32_t &outAdvance) {
  uint32_t hdr = 0;
  (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(byteAddr, &hdr);
  uint32_t p = byteAddr + 4u;
  return CpExecWaitRegMem(
      "IB", count, hdr,
      [&](uint32_t *out) {
        if (!mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(p, out))
          return false;
        p += 4u;
        return true;
      },
      outAdvance);
}

// --- F-651 (3) PM4_EVENT_WRITE_SHD 0x58 - LITERAL FORM ONLY ----------------
// ExecutePacketType3_EVENT_WRITE_SHD (command_processor.cc:1194-1217):
//   1 = initiator (:1198)  -> WriteRegister(VGT_EVENT_INITIATOR, initiator &
//       0x3F) (:1202; the register is 0x21F9, register_table.inc:530)
//   2 = address   (:1199)  low 2 bits = endian (:1211), rest = guest
//       physical, & ~3 (:1212)
//   3 = value     (:1200)  GpuSwap'd and stored to
//       TranslatePhysical(address) (:1213-1214)
// GRANULARITY: one 32-bit dword. This is a WRITE, not a wait - there is no
// loop and it returns true (:1216). It manufactures the token that a LATER
// PM4_WAIT_REG_MEM reads back; only that later packet can block.
// THE VALUE IS SELECTED BY initiator bit 31 (:1203-1210):
//   bit31 SET   -> data_value = counter_, the CommandProcessor's own event
//                  counter (:1206, incremented at :939 - a vblank/event counter
//                  this host has no model of)
//   bit31 CLEAR -> data_value = the packet's own `value` word (:1209)
// MEASURED (w661.log: 1,082,368 packets, 298 distinct bodies, 18 distinct
// destinations spanning 0x075D8C80..0x0B1A739C): 1,582 of 2,117 sampled rows
// take the counter form - and every one of those 1,582 carries value=DEADBEEF,
// i.e. the word is a placeholder the guest never meant. 535 take the literal
// form, with 283 distinct value words.
// DECISION: the literal form is implemented exactly - it is a plain checked
// store of a guest-supplied word, with nothing to invent. The counter form is
// REFUSED and counted: there is no vblank counter in this host, and both 0 and
// DEADBEEF would be an invented value published into guest memory (F-609). The
// VGT_EVENT_INITIATOR writeback is issued for BOTH forms because it is
// independent of the value selector and is a real register write; 0x21F9 is
// above kRegDcLutLast (0x1927) and below kXenosRegCount (0x5003), so CpRegPoke
// reaches it with no other side effect.
bool CpExecEventWriteShd(uint32_t byteAddr, uint32_t count,
                         uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n = g_shdSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  outAdvance = count + 1u;
  if (count < 3u) {
    return true;
  }
  uint32_t initiator = 0, address = 0, value = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &initiator) ||
      !mem.ReadU32BE(byteAddr + 8u, &address) ||
      !mem.ReadU32BE(byteAddr + 12u, &value)) {
    g_shdUnreadable.fetch_add(1, std::memory_order_relaxed);
    return true;
  }
  CpRegPoke(kRegVgtEventInitiator, initiator & 0x3Fu);
  if ((initiator & 0x80000000u) != 0u) {
    const uint32_t c =
        g_shdNoCounter.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (c <= 8u || (c % 200u) == 0u) {
      MCLA_LOG_WARN("CP-EVENTSHD-REFUSE #{} dst={:08X} initiator={:08X} - the "
                    "counter form needs the CP event counter "
                    "(command_processor.cc:1206 counter_); this host has no "
                    "such counter, so NOTHING stored. The packet's value word "
                    "is {:08X}, a guest placeholder, not a substitute",
                    c, address & ~0x3u, initiator, value);
    }
    return true;
  }
  const uint32_t dst = address & ~0x3u;
  // F-721: `address` is a guest PHYSICAL address (command_processor.cc:1211-1214
  // masks it and hands it to memory_->TranslatePhysical), so the store goes to
  // the POOL byte. Byte order moves with it for the same measured reason as
  // 0x3E: the reference is `xe::store<uint32_t>(ptr, GpuSwap(data, endian))`
  // (base/memory.h:374-376 = a plain host store), while WriteU32BE adds Swap32
  // (kernel/memory.cpp:351) - 4/4 disagreement measured on all four selectors.
  // 0x58, BY MEASUREMENT (F-746). Byte order moves with it for the same reason
  // as 0x3E: the reference is `xe::store<uint32_t>(ptr, GpuSwap(data, endian))`
  // (base/memory.h:374-376 = a plain host store) while WriteU32BE adds Swap32
  // (kernel/memory.cpp:351) - 4/4 disagreement measured on all four selectors.
  // AND THIS SITE IS ALREADY RIGHT: it passes GpuSwap32 to CpWriteU32Raw with no
  // CpByteSwap32, which is what agreement requires. Do NOT "fix" 0x58 to match
  // 0x3E/0x3D - those two had an extra swap and were corrected, this one did
  // not. Harness scenario C: 0x58 4/4 before this session's change and after.
  const uint32_t dstVa = CpPhysToPoolVa(dst, "EVENTSHD");
  if (dstVa == 0u) {
    // Refused, nothing stored, no fallback; CP: POOL-XLATE-REFUSED above already
    // printed why under site=EVENTSHD. Falls through so the bounded CP-EVENTSHD
    // row still fires for this attempt rather than losing a row from a tracked
    // marker's cadence.
    g_shdUnreadable.fetch_add(1, std::memory_order_relaxed);
  } else if (CpWriteU32Raw(dstVa, GpuSwap32(value, address & 0x3u))) {
    g_shdWritten.fetch_add(1, std::memory_order_relaxed);
    CpNoteMemWriteDest(dst);
    // F-746: this store is `xe::store<uint32_t>(ptr, GpuSwap(data, endian))`
    // (cc:1213-1214) - a PLAIN host store - so the poll's own single GpuSwap
    // (cc:982-983) cancels it and the poll reads the packet's `value` back for
    // all four selectors. Record the number the poll will see.
    CpNoteMemWriteValue(dst, value);
  } else {
    g_shdUnreadable.fetch_add(1, std::memory_order_relaxed);
  }
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN("CP-EVENTSHD #{} initiator={:08X} dst={:08X} endian={} "
                  "value={:08X} || seen={} written={} no-counter={} "
                  "unreadable={}",
                  n, initiator, dst, address & 0x3u, value,
                  g_shdSeen.load(std::memory_order_relaxed),
                  g_shdWritten.load(std::memory_order_relaxed),
                  g_shdNoCounter.load(std::memory_order_relaxed),
                  g_shdUnreadable.load(std::memory_order_relaxed));
  }
  return true;
}

// --- PM4_EVENT_WRITE (xenos.h:1594 = 0x46) ---------------------------------
// ExecutePacketType3_EVENT_WRITE (command_processor.cc:1177-1192):
//   initiator = reader->ReadAndSwap<uint32_t>();                    // :1181
//   WriteRegister(XE_GPU_REG_VGT_EVENT_INITIATOR, initiator & 0x3F); // :1183
//   if (count == 1) {
//     // Just an event flag? Where does this write?                  // :1185
//   } else {
//     assert_always();                                              // :1188
//     reader->AdvanceRead((count - 1) * sizeof(uint32_t));           // :1189
//   }
//
// COUNT CONVENTION (identical in both trees, so "count==1" means the same
// thing here as there): command_processor.cc:688 and this file's :4220 both
// compute `((hdr>>16)&0x3FFF)+1`, and the reference traces `1 + count` dwords
// (:702) after already consuming the header at :609 -- so `count` COUNTS
// OPERAND DWORDS and EXCLUDES the header. count==1 therefore means "header +
// exactly ONE operand dword", and the reference's own :2786-equivalent guard
// (this file's :2786, `count < 5u`) reads the same way.
//
// WHAT THE count==1 FORM IS, MEASURED FROM THE GUEST'S OWN PACKET --
// build/w700.log L7501, emitted by the pre-existing `default:` arm
// (LogType3Unhandled, :2416-2423), which reads up to 6 operand dwords verbatim:
//   CP-T3-CENSUS op=0x46 #1 count=1 depth=0 addr=B7C0A7E4
//                  args=00000006 00000000 00000000 00000000 00000000 00000000
// One operand, and it is 0x00000006.
//
// THE DECISIVE FACT, AND IT IS NOT INTERPRETATION: the count==1 form has NO
// ADDRESS OPERAND AND NO VALUE OPERAND. The reference's count==1 arm (:1184-
// 1185) is an EMPTY BLOCK whose own comment asks "Just an event flag? Where
// does this write?" -- i.e. upstream records that it does not write, and does
// not guess where. packet_disassembler.cc:208-214 independently confirms the
// arity: EVENT_WRITE reads exactly ONE dword (`initiator`), against three for
// EVENT_WRITE_SHD (:216-224 = initiator/address/value).
//
// CONSEQUENCE FOR THE PARK -- STATED SO NOBODY RE-DERIVES IT: this opcode CANNOT
// be the writer that satisfies the pending wait. build/w700.log L7519
// (CP-WAITREG-ISSUED #6) wants pollVA=B840B284 (pool view, :2827-2828) ==
// ref=0x00000001. This packet carries no address, so no address can be
// computed; and the single word it does carry is 0x00000006, which is
// `initiator`, not a value -- and 0x06 != 0x01 regardless. Implementing a
// writer here would require inventing an address the packet does not contain,
// which is exactly the F-609 fabrication this file refuses elsewhere (see
// CP-EVENTSHD-REFUSE, :3139). So NOTHING is stored, and the wait stays parked.
//
// WHAT IS IMPLEMENTED, because it is real and documented: the one side effect
// the reference performs unconditionally (:1183), a VGT_EVENT_INITIATOR
// register poke. 0x21F9 is above kRegDcLutLast (0x1927) and below
// kXenosRegCount (0x5003), so CpRegPoke reaches it with no other side effect --
// the same argument already recorded for the 0x58 path at :3116-3118.
// count>1 is REFUSED BY NAME and counted: upstream assert_always()s there
// (:1188), so its layout is genuinely unknown to the reference and this host
// will not invent one.
bool CpExecEventWrite(uint32_t byteAddr, uint32_t count,
                      uint32_t &outAdvance) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  const uint32_t n = g_ewSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  outAdvance = count + 1u;
  if (count < 1u) {
    return true;
  }
  uint32_t initiator = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &initiator)) {
    g_ewUnreadable.fetch_add(1, std::memory_order_relaxed);
    return true;
  }
  if (count > 1u) {
    const uint32_t c =
        g_ewRefusedMulti.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (c <= 8u || (c % 200u) == 0u) {
      MCLA_LOG_WARN("CP-EVENTWRITE-MULTI #{} op=0x46 count={} initiator={:08X} - "
                    "REFUSED, nothing stored: command_processor.cc:1188 "
                    "assert_always()s on the count>1 form, so its address/value "
                    "layout is UNKNOWN upstream and will not be guessed here. "
                    "Consumed {} dwords",
                    c, count, initiator, count + 1u);
    }
    return true;
  }
  CpRegPoke(kRegVgtEventInitiator, initiator & 0x3Fu);
  g_ewPoked.fetch_add(1, std::memory_order_relaxed);
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN("CP-EVENTWRITE #{} op=0x46 count={} initiator={:08X} "
                  "vgtInitiator={:08X} addrWritten=NONE valueWritten=NONE || "
                  "seen={} poked={} refusedMulti={} unreadable={} - the count==1 "
                  "form carries NO address and NO value operand "
                  "(command_processor.cc:1184-1185 is an empty block; "
                  "packet_disassembler.cc:208-214 reads 1 dword), so NOTHING was "
                  "stored and this opcode cannot satisfy a PM4_WAIT_REG_MEM",
                  n, count, initiator, initiator & 0x3Fu,
                  g_ewSeen.load(std::memory_order_relaxed),
                  g_ewPoked.load(std::memory_order_relaxed),
                  g_ewRefusedMulti.load(std::memory_order_relaxed),
                  g_ewUnreadable.load(std::memory_order_relaxed));
  }
  return true;
}

// PM4_MEM_WRITE (xenos.h:1589 = 0x3D), Xenia
// ExecutePacketType3_MEM_WRITE (command_processor.cc:1092-1108):
//   uint32_t write_addr  = reader->ReadAndSwap<uint32_t>();   // packet dword 1
//   for (i = 0; i < count - 1; i++) {
//     uint32_t write_data = reader->ReadAndSwap<uint32_t>(); // packet dwords 2..count
//     endianness = write_addr & 0x3;  addr = write_addr & ~0x3;
//     xe::store(memory_->TranslatePhysical(addr), GpuSwap(write_data, endianness));
//     write_addr += 4;                 // advances INCLUDING its flag bits
//   }
//
// F-610, the top defect: our old ExecuteMemWrite took only the DESTINATION and
// read its payload back out of the destination with ReadU32BE(addr) - a
// self-read, byte-swap, write-back. The payload was never the packet's, so
// every MEM_WRITE the title issued (fence values, constants) silently no-opped.
// The payload must come from the reader, which is a different object on each
// path: contiguous guest memory inside an indirect buffer, wrap-around inside
// the circular ring. `nextWord(&out)` abstracts exactly that, so the two call
// sites cannot drift back apart. Templated on the reader, so no per-packet
// allocation and the loop stays inlinable.
template <typename NextWord>
void ExecuteMemWrite(const char *op, uint32_t wordAddr, uint32_t count,
                     NextWord &&nextWord) {
  // F-721: the `mem` local this used to open with is gone. Every store below
  // goes through CpWriteU32Raw, which owns its own heap handle, and the packet
  // body arrives through `nextWord` - so nothing in this function names the heap
  // any more. Left in place it would be an unused binding.
  uint32_t addr = wordAddr;
  uint32_t written = 0, first = 0;
  // F-610, and F-721 on top. The destination is a GPU PHYSICAL address upstream
  // (command_processor.cc:1100-1102 masks write_addr and hands it to
  // memory_->TranslatePhysical), so it goes to the POOL byte - the last of the
  // four guest-physical stores in this file, and the only one whose own comment
  // used to argue for leaving it flat. That argument is settled by measurement:
  // the reference's 0x3D store is
  // `xe::store<uint32_t>(TranslatePhysical(addr), GpuSwap(write_data, endianness))`
  // (cc:1099-1102) and xe::store<uint32_t> is a PLAIN host store
  // (base/memory.h:374-376), so the host dword it leaves is exactly
  // GpuSwap(write_data, `write_addr & 3`). All four stores moved to the pool
  // together and that part stands.
  //
  // F-746 CORRECTS THE BYTE-ORDER HALF OF THAT MOVE, for 0x3D and 0x3E only. The
  // F-721 text here and at :2844 claimed 4/4 disagreement from the pool move; the
  // harness measured the pool move and the byte order as ONE change and they do
  // not have the same sign. Once a store goes through CpWriteU32Raw - which is
  // `WriteU32BE(va, CpByteSwap32(X))` (:2854-2857) against WriteU32BE's own
  // Swap32 (kernel/memory.cpp:346-352) - the two cancel and X IS the host dword
  // (measured directly, harness scenario C0). The extra CpByteSwap32 that
  // F-721 added at this site and at 0x3E therefore left Swap32 one time too
  // many: 0/4 store-byte agreement and 0/4 round trip before, 4/4 and 4/4 after.
  // 0x58 never had the extra swap and was never wrong.
  for (uint32_t i = 1; i < count; ++i) {
    uint32_t data = 0;
    if (!nextWord(&data)) {
      break;
    }
    if (written == 0) {
      first = data;
    }
    const uint32_t rawAddr = addr & ~0x3u;
    const uint32_t dstVa = CpPhysToPoolVa(rawAddr, "MEM-WRITE");
    if (dstVa == 0u) {
      // Refused, nothing stored, no fallback to the untranslated view.
      // CP: POOL-XLATE-REFUSED above already printed why under site=MEM-WRITE.
      // The packet is still consumed (addr advances) so the stream stays in
      // step with the ring, exactly as the unreadable-payload `break` does.
      addr += 4;
      ++written;
      continue;
    }
    // F-746 CORRECTS F-721 HERE, SAME MEASUREMENT AS CpExecRegToMem (which
    // cites this one). The reference's 0x3D store is
    // xe::store<uint32_t>(TranslatePhysical(addr), GpuSwap(write_data,
    // endianness)) - command_processor.cc:1099-1102, base/memory.h:373-376 - a
    // PLAIN host store, so the host dword is exactly GpuSwap(data, addr & 3).
    // CpWriteU32Raw already leaves its argument as the host dword (measured,
    // harness scenario C0), so NO extra CpByteSwap32 belongs here. With it, this
    // site left Swap32 of the reference's word at all four selectors and the
    // 0x3D round trip failed 4/4; without it, both are 4/4.
    const uint32_t swapped = GpuSwap32(data, addr & 0x3);
    (void)CpWriteU32Raw(dstVa, swapped);
    CpNoteMemWriteDest(rawAddr);
    // F-746: `data` is the packet's own payload word, the store is a plain host
    // store of GpuSwap(data, addr & 3) (cc:1099-1102), and the poll applies one
    // GpuSwap of its own - so the poll reads `data` back for all four selectors.
    // Record the number the poll will see.
    CpNoteMemWriteValue(rawAddr, data);
    addr += 4;
    ++written;
  }
  const uint32_t n = g_memWritePackets.fetch_add(1, std::memory_order_relaxed) + 1;
  g_memWriteDwords.fetch_add(written, std::memory_order_relaxed);
  if (written == 0u) {
    const uint32_t m =
        g_memWritePayloadMiss.fetch_add(1, std::memory_order_relaxed) + 1;
    MCLA_LOG_WARN("CP-MEMWRITE-EMPTY #{} op={} dest={:08X} count={} payload "
                  "UNREADABLE (nothing stored)", m, op, wordAddr & ~0x3u, count);
  }
  // F-610: the destination is a GPU PHYSICAL address upstream
  // (memory_->TranslatePhysical, :1102). We hand it to the flat guest view
  // unchanged, exactly as the pre-F-610 code did, because this file's store
  // destinations have no measured landing site yet - and F-680 sharpened rather
  // than settled that: the IB list pointer and the wait's memory poll were both
  // resolved through CpPhysToPoolVa because both had MEASURED bytes on the A
  // side (w679.log PKT-CAP vs CP: INDIRECT_BUFFER), while this destination has
  // no such pair. Applying the rule here without that measurement would be a
  // guess in the other direction. The one-shot warning below is the census that
  // resolves it.
  //
  // F-721 SUPERSEDES the paragraph above, and the row below with it. That text
  // argued for leaving this store flat for want of a measurement; the
  // measurement now exists in the other direction - the reference writes this
  // destination through TranslatePhysical (cc:1099-1102) and the wait polls a
  // pool byte, so flat and pool are two different dwords and only one of them
  // is ever read. This store now goes through CpPhysToPoolVa, like the other
  // three guest-physical stores. The `dest=` field below is still the GUEST
  // PHYSICAL number (unchanged, and unchanged in meaning); the one-shot row
  // still fires on the same condition, so it is still a valid census of "a
  // 0x3D destination below the physical window exists".
  if (wordAddr < 0x20000000u) {
    static std::atomic<bool> warnedPhys{0};
    if (!warnedPhys.exchange(true)) {
      MCLA_LOG_WARN("CP-MEMWRITE-DEST-PHYS #{} op={} dest={:08X} is below the "
                    "0x20000000 physical window - SUPERSEDED BY F-721: this "
                    "destination now goes through CpPhysToPoolVa to the POOL "
                    "byte, NOT the flat guest view. The condition that fires "
                    "this row (dest < 0x20000000) is unchanged, so the row is "
                    "still a true census of how many 0x3D destinations are "
                    "below the window; only the sentence about where they are "
                    "written is now out of date",
                    n, op, wordAddr);
    }
  }
  if (n <= 12 || (n % 200) == 0) {
    MCLA_LOG_WARN("CP-MEMWRITE #{} op={} dest={:08X} count={} stored={} "
                  "first={:08X} totalDwords={}", n, op, wordAddr & ~0x3u, count,
                  written, first,
                  g_memWriteDwords.load(std::memory_order_relaxed));
  }
}

// ---------------------------------------------------------------------------
// F-611: the CP -> render-thread draw bridge.
//
// What a PM4 draw actually yields, decoded to upstream's own arithmetic, and an
// explicit countable refusal for every field it does not.
//
// MEASURED on the reachable stream (build/w654.log, a 2-minute boot, 4140
// submissions counted off the CP-DRAW-STATE line): 4116 carry
// VGT_DRAW_INITIATOR=0x00030088 and 24 carry 0x00010081. Decoded per
// registers.h:311-330 that is 100% source_select=kAutoIndex (xenos.h:742-746) -
// prim_type 8 (kRectangleList) with 3 indices, and prim_type 1 (kPointList)
// with 1 index. source_select=kDMA, the ONLY class that carries a guest
// index-buffer address, has ZERO occurrences, and so do PM4_SET_CONSTANT (0x2D)
// and PM4_SET_CONSTANT2 (0x55) - 0 CP-SETCONST lines - which is why nothing has
// ever written the fetch/VB constant block (0 CP writes, counted by
// g_fetchVbWrites). The parallel guest-hook path agrees: 12 DRAW-GATE lines,
// all "dummy", vb=00000000, stride 0.
//
// So the honest shape of this feature today is: implement kDMA exactly as
// upstream so it is correct the day the guest issues one, and REFUSE the classes
// that provably have no geometry by name. A refusal that says "no index buffer,
// source_select is kAutoIndex" is a correct result (F-609, native-only charter,
// no fakes); a synthesised quad is not - and the F-605 DRAW_MARKER synthetic is
// already on the wire for exactly that pipe-liveness proof, labelled as such
// with a written removal trigger (render_queue.h:139-144).
//
// The vertex gate is a SELF-LIFTING one, not a hand-flipped switch: it refuses
// only while g_fetchVbWrites == 0, so the first guest that writes the fetch/VB
// constant block starts producing real DRAW_CAPTURED commands with no code
// change and no second round trip.
//
// F-633 SUPERSEDES TWO SENTENCES ABOVE, and they are left in place as the
// record they were:
//   "REFUSE the classes that provably have no geometry by name" - the kAutoIndex
//   class was refused on that basis and that basis was wrong. It HAS geometry:
//   the guest writes the 0x4800 fetch window 1,755,456 times in build/w661.log
//   (g_fetchVbWrites), 438,863 of 438,863 vfetch instructions decode with
//   none=0 unreadable=0, and 292,575 CP-FETCHVB-DESC rows carry a real base,
//   length, stride and format. An empty index buffer is not an empty vertex
//   stream.
//   "A refusal that says 'no index buffer, source_select is kAutoIndex' is a
//   correct result (F-609, native-only charter, no fakes)" - F-609 forbids
//   FAKES, and it does not forbid a draw the guest actually issued. The
//   reference draws this class (command_processor.cc:1380-1384). A refusal
//   standing in for a draw the reference performs is a fake of the missing
//   thing. F-605's DRAW_MARKER remains the synthetic, still labelled as one,
//   and this change does not touch it.
// The F-611 measurement itself (100% kAutoIndex, 0 CP-SETCONST) was a snapshot
// taken before the guest's first write to the fetch window; the census rows that
// supersede it are the ones in CP-DRAW-CENSUS above.
// ---------------------------------------------------------------------------
// F-652: fill the two shader-program descriptors and the raster-state snapshot
// for one draw, from state this translation unit owns and this THREAD wrote.
//
// WHY NOT CpReadGuestRegisters (src/gpu_cp.cpp, F-647's export): that function
// answers "has this index EVER been poked", which is a process-lifetime fact.
// The rasteriser state a DRAW is judged on is the value at the instant the draw
// was submitted; a register the guest rewrote four draws later must not be
// credited to this one, and one this draw never received must not be decoded
// from the leftover. So the snapshot reads the same two arrays (values and the
// per-index presence bitmap) directly, at the enqueue site, on the CP thread
// that did the writes - which also makes the read consistent with the write in
// a way the cross-thread export cannot promise (F-647 documents "consistent per
// register, not across registers").
//
// LOCK ORDERING: the microcode window's mutex is taken and released INSIDE this
// function, and nothing else is held when it is taken, so this stays compatible
// with F-647's stated rule (the seqlock, if one is ever added, must be
// outermost, and no caller may hold g_microcodeMutex across a register export -
// this function holds it across nothing but two field copies).
void CpSnapshotDrawState(mcla::native::CpShaderProgram &vs,
                         mcla::native::CpShaderProgram &ps,
                         mcla::native::CpRenderStateSnapshot &rs) {
  vs = {};
  ps = {};
  rs = {};

  // The two program images. Locked, copied, unlocked: no guest bytes are read
  // here and nothing is dereferenced, so the critical section is the scalar
  // copies below plus at most kCpShaderBodyDwords dwords per stage.
  //
  // F-694: the program BODY now crosses with the scalars, from the SAME
  // img.dwords[] CpExecImLoad filled with mem.ReadU32BE (:1710), still under the
  // SAME g_microcodeMutex that guards the image store (:1721-1722) - so a draw
  // cannot pair one stage's body with another stage's scalars. Nothing is
  // dereferenced and no guest address is touched: this is a copy out of an
  // already-captured image, which is what makes it safe to widen the critical
  // section rather than widening the lock's scope.
  {
    std::lock_guard<std::mutex> lock(g_microcodeMutex);
    for (uint32_t stage = 0; stage < 2u; ++stage) {
      const CpMicrocodeImage &img = g_microcode[stage];
      mcla::native::CpShaderProgram &dst = (stage == 0u) ? vs : ps;
      if (!img.present) {
        // kCpShaderAddrAbsent: NOT guestAddr == 0. Address 0 is a readable page
        // in this flat guest window, so a zero here would be the most plausible
        // wrong shader there is.
        dst.addrSpace = mcla::native::kCpShaderAddrAbsent;
        // body[] stays as `vs = {}` / `ps = {}` left it: all zeroes. Stated
        // rather than assumed - the absent stage must not carry a body.
        s_shipBody[stage].dwords = 0u;
        s_shipBody[stage].cap = mcla::native::kCpShaderBodyDwords;
        continue;
      }
      dst.present = 1u;
      dst.guestAddr = img.srcPhys;
      dst.dwords = img.totalDwords;
      dst.captured = img.captured;
      dst.embedded = img.embedded;
      // Which form of the address the producer verified READABLE. 0 is not an
      // option here: CpExecImLoad stores srcVA only after a successful read.
      dst.addrSpace = img.vaIsKernel ? mcla::native::kCpShaderAddrKernel
                                     : mcla::native::kCpShaderAddrGuest;

      // F-694: the body. EXACTLY min(captured, cap) dwords, and never more -
      // see the tail argument below. `captured` is the number of dwords
      // CpExecImLoad actually READ (:1707-1716), so it - not `totalDwords`,
      // which is only what the header DECLARED - is the count of dwords that
      // exist. Copying `totalDwords` would ship uninitialised words whenever
      // the read loop broke early.
      const uint32_t cap = mcla::native::kCpShaderBodyDwords;
      const uint32_t n = (img.captured < cap) ? img.captured : cap;
      for (uint32_t i = 0; i < n; ++i) {
        dst.body[i] = img.dwords[i];
      }
      // THE STALE TAIL, and why it is already zero rather than memset here.
      // Two independent facts, both MEASURED, and the second one is load-bearing
      // so it is repeated at the definition:
      //   (1) SOURCE. CpExecImLoad builds a FRESH `CpMicrocodeImage img{}`
      //       (:1699) and stores it WHOLE (`g_microcode[type] = img`, :1722), so
      //       dwords[captured..kMicrocodeCaptureDwords) is zero on every store,
      //       not leftover from the previous program for that stage.
      //   (2) DESTINATION. `vs = {}` / `ps = {}` (:3055-3056) value-initialise
      //       the WHOLE struct including the 256-dword body, so dst.body[n..cap)
      //       is zero BEFORE this loop runs.
      // A shorter re-upload therefore cannot ship the previous longer program's
      // tail: the loop writes only [0, n) and everything from n onward is still
      // the zeros `= {}` put there. PROVED by executing the two mechanisms
      // against a 27-dword store followed by a 9-dword store (the two sizes
      // CP-IM-LOAD reports in build/w682.log): tail non-zero count 0 both
      // times, and 247 with the `= {}` removed - i.e. the probe can SEE a stale
      // tail, so its 0 is a measurement and not a tautology.
      // CONSEQUENCE IF (2) IS EVER REMOVED: this loop becomes a stale-tail
      // source. That is the falsifier, and it is a one-line revert: drop the
      // `= {}` and the tail is whatever the last draw put there.
      s_shipBody[stage].dwords = n;
      s_shipBody[stage].cap = cap;
      if (img.captured > cap) {
        // The program did not fit the array. NOT clamped silently and NOT
        // refused here: the consumer owns the refusal (render_queue.h's
        // validity contract requires it to test captured <= cap), so the
        // producer's whole job is to make the fact COUNTABLE.
        s_shipBody[stage].truncated += 1u;
      }
      if (img.embedded != 0u) {
        s_shipBody[stage].embedded += 1u;
      }
    }
  }

  // The raster/clip/viewport/bias registers, values + presence.
//   F-723: nine entries now (RB_COLOR_INFO added at 0x2001). The loop below is
//   unchanged and needs no edit: it iterates kCpSnapRegCount and derives
//   presence from g_xenosRegPresent, so a new index participates in the
//   presence-bit discipline automatically.
  static constexpr uint32_t kSnapIndices[mcla::native::kCpSnapRegCount] = {
      kCpRegPaClipCntl,        // 0x2204
      kCpRegPaSuScModeCntl,    // 0x2205
      kCpRegPaClVteCntl,       // 0x2206
      0x2380u,                // PA_SU_POLY_OFFSET_FRONT_SCALE
      0x2381u,                // PA_SU_POLY_OFFSET_FRONT_OFFSET
      0x2382u,                // PA_SU_POLY_OFFSET_BACK_SCALE
      0x2383u,                // PA_SU_POLY_OFFSET_BACK_OFFSET
      0x2002u,                // RB_DEPTH_INFO
      0x2001u,                // RB_COLOR_INFO (F-723)
  };
  for (uint32_t i = 0; i < mcla::native::kCpSnapRegCount; ++i) {
    const uint32_t idx = kSnapIndices[i];
    // Bound-checked, never asserted: idx is a compile-time constant but the
    // presence word is only valid below kXenosRegPresentWords, and a guest value
    // is not what decides that here - a future edit adding an index is.
    if (idx >= kXenosRegCount) {
      rs.regs[i] = 0u;
      continue;
    }
    const uint32_t word =
        g_xenosRegPresent[idx >> 5].load(std::memory_order_acquire);
    if (word & (1u << (idx & 31u))) {
      rs.presentMask |= (1u << i);
    }
    rs.regs[i] = g_xenosReg[idx].load(std::memory_order_relaxed);
  }
}

namespace {

// Reads the (base,size) pairs and the presence census of the ALU window.
void CpShaderConstantState(CpShaderConstantInfo &out) {
  // ONE export call for the two registers, so the CP-REGS-EXPORT row and this
  // snapshot are the same read.
  static constexpr uint32_t kIdx[2] = {kCpRegSqVsConst, kCpRegSqPsConst};
  uint32_t val[2] = {0, 0};
  uint32_t pres[2] = {0, 0};
  (void)CpReadGuestRegisters(kIdx, 2u, val, pres);
  out.vsRegPresent = pres[0] != 0u;
  out.psRegPresent = pres[1] != 0u;
  out.vsBase = val[0] & 0x1FFu;            // registers.h:259  base : 9 at +0
  out.vsSize = (val[0] >> 12) & 0x1FFu;    // registers.h:262  size : 9 at +12
  out.psBase = val[1] & 0x1FFu;
  out.psSize = (val[1] >> 12) & 0x1FFu;
  // The presence census over the ALU window: the window is word-aligned
  // (0x4000 and 0x4800 are both multiples of 32), so no bit masking is needed
  // at either end.
  uint32_t present = 0;
  constexpr uint32_t kFirstWord = kCpShaderConstantRegBase >> 5;
  constexpr uint32_t kLastWord =
      (kCpShaderConstantRegBase + kCpShaderConstantDwords) >> 5;
  for (uint32_t w = kFirstWord; w < kLastWord; ++w) {
    uint32_t bits = g_xenosRegPresent[w].load(std::memory_order_acquire);
    while (bits != 0u) {
      bits &= (bits - 1u);  // clear the lowest set bit
      ++present;
    }
  }
  out.aluDwordsPresent = present;
}

// Writes one float4 of the console's array, BIG-ENDIAN, at `out`.
void CpWriteShaderConstantFloat4(uint8_t *out, uint32_t entry) {
  const uint32_t reg = kCpShaderConstantRegBase + 4u * entry;
  for (uint32_t c = 0; c < 4u; ++c) {
    const uint32_t v = g_xenosReg[reg + c].load(std::memory_order_relaxed);
    out[c * 4u + 0u] = static_cast<uint8_t>(v >> 24);
    out[c * 4u + 1u] = static_cast<uint8_t>(v >> 16);
    out[c * 4u + 2u] = static_cast<uint8_t>(v >> 8);
    out[c * 4u + 3u] = static_cast<uint8_t>(v);
  }
}

}  // namespace

void CpBridgeDraw(uint32_t seq, uint32_t opcode, uint32_t di, uint32_t prim,
                  uint32_t src, uint32_t idxSize, uint32_t numIdx,
                  uint32_t dmaBase, uint32_t dmaSize) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  // VGT_DMA_SIZE: num_words : 24 at +0, swap_mode : 2 at +30 (registers.h:301-309).
  const uint32_t dmaWords = dmaSize & 0x00FFFFFFu;
  const uint32_t dmaSwap = (dmaSize >> 30) & 0x3u;
  // index element size (command_processor.cc:1336-1339).
  const uint32_t idxBytes = (idxSize != 0u) ? 4u : 2u;
  // index_buffer_info, resolved upstream's way (:1342-1346).
  const uint32_t ibVa = dmaBase & ~(idxBytes - 1u);
  const uint32_t ibBytes = dmaWords * idxBytes;
  const uint32_t fetchVbWrites =
      g_fetchVbWrites.load(std::memory_order_relaxed);

  // One bounded, fully identified refusal line per reason, so a soak can count
  // the reason and not just the fact. std::string_view so a reason can be
  // assembled from parts (F-612's microcode-unsupported row names the captured
  // program size) without a copy per draw; the string literals below convert
  // implicitly and unchanged.
  auto refuse = [&](const char *what, std::atomic<uint32_t> &counter,
                    std::string_view detail) {
    const uint32_t n = counter.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 200) == 0) {
      MCLA_LOG_WARN("CP-DRAW-REFUSE #{} what={} op=0x{:02X} src={} prim={} "
                    "numIdx={} idxFmt={} idxVa={:08X} idxBytes={} swap={} "
                    "initiator={:08X} fetchVbWrites={} {}",
                    n, what, opcode, src, prim, numIdx, idxSize, ibVa, ibBytes,
                    dmaSwap, di, fetchVbWrites, detail);
    }
  };

  // F-612: the census row a soak actually reads. Every counter the bridge keeps
  // is printed here, INCLUDING the ones whose per-reason log line is suppressed
  // (the refuse() lambda prints 8 then every 200th, so a suppressed
  // `what=microcode-absent` row is NOT countable on its own - a deleted
  // evidence row, which is worse than a flood). Bounding the log must not bound
  // the census, so the totals live here and are printed every 200th draw.
  static std::atomic<uint32_t> s_census{0};
  // F-633: two refusals that only exist because source_select stopped being a
  // refusal (see the isIndexed block below). They are declared HERE, next to
  // s_census, rather than with the F-611/F-612 counters above, so this change
  // stays inside the draw-bridge region.
  //   vfetch-mini-only - the program decoded vfetch instructions, but every one
  //       of them was a vfetch_mini, so there is no full fetch to name a stream
  //       from. A vfetch_mini reuses the address its vfetch_full computed
  //       (ucode.h:701-702) and its stride() is not applicable at all
  //       (ucode.h:737-739), so it must never become desc[0].
  //   vfetch-stride0   - the stream IS a vfetch_full, and its stride() really is
  //       0 dwords. That is a real zero-stride stream, which cannot be addressed
  //       per vertex, so the draw refuses rather than mis-draw (F-609). This is
  //       NOT the same thing as the census column stride0=, which counts EVERY
  //       decoded instruction with stride()==0 including the legal vfetch_mini
  //       continuations - 146,288 of them in build/w661.log against 4 CP-
  //       FETCHVB-DESC rows with miniFetch=1.
  static std::atomic<uint32_t> g_bridgeMiniOnly{0};
  static std::atomic<uint32_t> g_bridgeStride0{0};
  // F-648: vfetch-multi - the program decoded MORE THAN ONE full vfetch, so it
  // describes more than one stream. Each full fetch binds its own fetch-constant
  // slot and therefore its own guest base address and stride, so a single
  // (vbBase, vbStride, vbFormat) triple cannot describe the program: taking the
  // first would silently pick one attribute's buffer out of several and call it
  // the vertex stream, which is the substitution F-609 forbids. Refused by name
  // instead, and the count is on the CP-DRAW-CENSUS row.
  //
  // MEASURED ZERO: build/w662.log carries 1,472 CP-DRAW-BRIDGE rows and every
  // one has nFull=1 (1,468 rows nDesc=1; 4 rows nDesc=2, and those second
  // descriptors are vfetch_mini, which reuse the full fetch's address -
  // ucode.h:701-702, :737-739). So this gate costs nothing on the measured
  // stream and closes the silent-pick hole for any future program.
  static std::atomic<uint32_t> g_bridgeVfetchMulti{0};
  // F-652: the shader programs this draw selects. ATTEMPTS and OUTCOMES are
  // separate counters per stage, because "no draw ever carried a program" and
  // "every draw carried one" must be distinguishable from the log alone - the
  // two both read as a zero program address otherwise.
  //   progVsPresent / progPsPresent  - the draw carried a program address for
  //                                    this stage (the address is non-zero AND
  //                                    the stage's capture is present).
  //   progVsAbsent  / progPsAbsent   - no PM4_IM_LOAD had delivered this stage,
  //                                    so the draw is refused downstream.
  //   progVsEmbedded / progPsEmbedded - PM4_IM_LOAD_IMMEDIATE (0x2B): the body
  //                                    was IN the packet, so there is NO guest
  //                                    address to carry. Counted apart because a
  //                                    program that exists and a program with an
  //                                    address are different facts.
  std::atomic<uint32_t> g_bridgeProgVsPresent{0};
  std::atomic<uint32_t> g_bridgeProgPsPresent{0};
  std::atomic<uint32_t> g_bridgeProgVsAbsent{0};
  std::atomic<uint32_t> g_bridgeProgPsAbsent{0};
  std::atomic<uint32_t> g_bridgeProgVsEmbedded{0};
  std::atomic<uint32_t> g_bridgeProgPsEmbedded{0};
  // F-652: raster/clip/viewport register COVERAGE per draw, counted by bit over
  // the CpSnapshotReg set. One independent counter per slot so a soak can read
  // "which register never arrived" straight off the census row, with no bit maths
  // and no dependence on the log line surviving its 200-row bound.
  // F-723: the array is sized by kCpSnapRegCount, so it grew from 8 to 9 with
  // the enum and no counter was renamed or reindexed.
  std::atomic<uint32_t> g_bridgeSnapCover[mcla::native::kCpSnapRegCount] = {};
  const uint32_t cn = s_census.fetch_add(1, std::memory_order_relaxed) + 1u;
  // WHY snapCover CAN READ ALL-ZERO WHILE CP-DRAW-BRIDGE READS rsPresent=187 -
  // measured on build/w700.log, NOT a disagreement between two producers. Both
  // read the SAME dc.rasterState.presentMask (the bridge at :4011-4014 and the
  // rsPresent field at :4040), and 0x187 = bits 0,1,2,7,8 = kCpSnapPaClipCntl,
  // PaSuScModeCntl, PaClVteCntl, DepthInfo(0x2002) and ColorInfo(0x2001)
  // (render_queue.h:420-447) - the first, second, third, eighth and ninth of the
  // nine snapCover buckets. They cannot disagree about one mask.
  // They differ in WHEN: this row's cadence is the first four draws, and in
  // w700.log all four CP-DRAW-CENSUS rows print at 06:13:25.068-070, while the
  // first CP-DRAW-BRIDGE (the first enqueue, and the only thing that ever bumps
  // g_bridgeSnapCover) prints at 06:13:25.854. So every census row predates the
  // first enqueue and a legitimately-zero counter is what it read.
  // A reader must pair these two rows by TIME, not by draw. Do not "fix" this by
  // reading presentMask directly here: that would make the row claim coverage for
  // draws this CP refused, which is the F-609 fabrication.
  if (cn <= 4u || (cn % 200u) == 0u) {
    CpVertexFetchSlot probe[1];
    // Probed with a ONE-slot buffer, so this is a presence flag for slot 0 and
    // NOT a slot count. The real running total is vbSlotsTotal below; printing
    // the capped probe as a count would understate a partially written block.
    const uint32_t slot0 = CpDecodeVertexFetchSlots(probe, 1u);
    MCLA_LOG_WARN(
        "CP-DRAW-CENSUS #{} src={} prim={} | no-index-buffer={} "
        "empty-index-buffer={} index-range-wrap={} index-unreadable={} "
        "no-vb-desc={} no-vertex-fetch-const={} microcode-absent={} "
        "vfetch-none={} vfetch-unreadable={} microcode-unsupported={} "
        "vfetch-mini-only={} vfetch-stride0={} vfetch-multi={} "
        "enqueued={} || fetchVbWrites={} "
        "vbSlot0Present={} vbSlotsTotal={} vbDecoded={} vbUndecodable={} "
        "fetchVbNoVertex={} || vfetch(found={} decoded={} none={} unreadable={} "
        "trunc={} stride0={} badFmt={}) || imLoad(vertex={} pixel={} immediate={} "
        "unreadable={} zeroSize={} startSet={} truncated={} dwords={}) "
        "ucodeVertexDwords={} || t3Unhandled={} scratchWB={} coherDirty={} || "
        "reg2mem(seen={} written={} same={} refuseReg={} unreadable={}) "
        "waitRegMem(seen={} reg={} mem={} sat={} satSpin={} timedOut={} "
        "neverWritten={} unmatchable={} unreadable={} spins={} waitedMs={} "
        "parked={} coherCleared={} coherNoop={}) "
        "eventShd(seen={} written={} "
        "noCounter={} unreadable={}) || prog(vs={} vsAbsent={} vsEmbedded={} "
        "ps={} psAbsent={} psEmbedded={}) || snapCover(2204={} 2205={} 2206={} "
        // F-723: `2001=` is APPENDED at the very END of this group. No existing
        // field moved, renamed or changed type: `snapCover(...)` closes with
        // `2002={})` today and closes with `2002={} 2001={})` after this. That is
        // the only sanctioned shape for new evidence on a tracked row (new name,
        // or append at the very END) -- CP-DRAW-CENSUS is re-parsed by
        // tools/soak_census.py via PROGRAM_GUIDE sec 9, so renaming or
        // re-ordering a field would change a tracked format.
        "2380={} 2381={} 2382={} 2383={} 2002={} 2001={})",
        cn, src, prim,
        g_bridgeNoIndexBuffer.load(std::memory_order_relaxed),
        g_bridgeEmptyIndex.load(std::memory_order_relaxed),
        g_bridgeIndexWrap.load(std::memory_order_relaxed),
        g_bridgeIndexUnreadable.load(std::memory_order_relaxed),
        g_bridgeNoVbDesc.load(std::memory_order_relaxed),
        g_bridgeNoVbFetchConst.load(std::memory_order_relaxed),
        g_bridgeNoMicrocode.load(std::memory_order_relaxed),
        g_bridgeVfetchNone.load(std::memory_order_relaxed),
        g_bridgeVfetchUnreadable.load(std::memory_order_relaxed),
        g_bridgeMicrocodeUnsup.load(std::memory_order_relaxed),
        g_bridgeMiniOnly.load(std::memory_order_relaxed),
        g_bridgeStride0.load(std::memory_order_relaxed),
        g_bridgeVfetchMulti.load(std::memory_order_relaxed),
        g_bridgeEnqueued.load(std::memory_order_relaxed), fetchVbWrites,
        slot0, g_fetchVbSlots.load(std::memory_order_relaxed),
        g_fetchVbDecoded.load(std::memory_order_relaxed),
        g_fetchVbUndecodable.load(std::memory_order_relaxed),
        g_fetchVbNoVertex.load(std::memory_order_relaxed),
        g_vfetchFound.load(std::memory_order_relaxed),
        g_vfetchDecoded.load(std::memory_order_relaxed),
        g_vfetchNone.load(std::memory_order_relaxed),
        g_vfetchUnreadable.load(std::memory_order_relaxed),
        g_vfetchTrunc.load(std::memory_order_relaxed),
        g_vfetchStride0.load(std::memory_order_relaxed),
        g_vfetchBadFmt.load(std::memory_order_relaxed),
        g_imLoadVertex.load(std::memory_order_relaxed),
        g_imLoadPixel.load(std::memory_order_relaxed),
        g_imLoadImmediate.load(std::memory_order_relaxed),
        g_imLoadUnreadable.load(std::memory_order_relaxed),
        g_imLoadZeroSize.load(std::memory_order_relaxed),
        g_imLoadStartSet.load(std::memory_order_relaxed),
        g_imLoadTruncated.load(std::memory_order_relaxed),
        g_imLoadDwords.load(std::memory_order_relaxed),
        CpVertexMicrocodeDwords(), g_t3Unhandled.load(std::memory_order_relaxed),
        g_scratchWritebacks.load(std::memory_order_relaxed),
        g_coherDirty.load(std::memory_order_relaxed),
        // F-651: the 0x3E / 0x3C / 0x58 counters are on this row too, so the
        // authoritative census still prints every total after these opcodes
        // stopped falling into the `default:` arm. Bounding a LOG must not
        // bound a CENSUS.
        g_r2mSeen.load(std::memory_order_relaxed),
        g_r2mWritten.load(std::memory_order_relaxed),
        g_r2mSame.load(std::memory_order_relaxed),
        g_r2mRefusedReg.load(std::memory_order_relaxed),
        g_r2mUnreadable.load(std::memory_order_relaxed),
        g_waitRegMemSeen.load(std::memory_order_relaxed),
        g_waitRegMemReg.load(std::memory_order_relaxed),
        g_waitRegMemMem.load(std::memory_order_relaxed),
        g_waitRegMemSat.load(std::memory_order_relaxed),
        g_waitRegMemSatSpin.load(std::memory_order_relaxed),
        g_waitRegMemTimeout.load(std::memory_order_relaxed),
        g_waitRegMemNeverWritten.load(std::memory_order_relaxed),
        g_waitRegMemUnmatchable.load(std::memory_order_relaxed),
        g_waitRegMemUnreadable.load(std::memory_order_relaxed),
        g_waitRegMemSpins.load(std::memory_order_relaxed),
        g_waitRegMemWaitedMs.load(std::memory_order_relaxed),
        g_waitRegMemParked.load(std::memory_order_relaxed),
        g_coherentCleared.load(std::memory_order_relaxed),
        g_coherentNoop.load(std::memory_order_relaxed),
        g_shdSeen.load(std::memory_order_relaxed),
        g_shdWritten.load(std::memory_order_relaxed),
        g_shdNoCounter.load(std::memory_order_relaxed),
        g_shdUnreadable.load(std::memory_order_relaxed),
        // F-652: the shader-program census. `vs`/`ps` are draws that carried a
        // program address; `*Absent` are draws that carried none (a refusal);
        // `*Embedded` are draws whose program came from the packet body.
        g_bridgeProgVsPresent.load(std::memory_order_relaxed),
        g_bridgeProgVsAbsent.load(std::memory_order_relaxed),
        g_bridgeProgVsEmbedded.load(std::memory_order_relaxed),
        g_bridgeProgPsPresent.load(std::memory_order_relaxed),
        g_bridgeProgPsAbsent.load(std::memory_order_relaxed),
        g_bridgeProgPsEmbedded.load(std::memory_order_relaxed),
        // F-652: per-register raster-state COVERAGE, one counter per
        // CpSnapshotReg. A zero here means "the guest never wrote this register",
        // which is what renderer::PipelineStateInputs::registersPresent has to
        // know and must never learn from a value.
        g_bridgeSnapCover[mcla::native::kCpSnapPaClipCntl].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPaSuScModeCntl].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPaClVteCntl].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPolyOffFrontScale].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPolyOffFrontOffset].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPolyOffBackScale].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapPolyOffBackOffset].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapDepthInfo].load(std::memory_order_relaxed),
        g_bridgeSnapCover[mcla::native::kCpSnapColorInfo].load(std::memory_order_relaxed));
  }

  // F-612: the descriptor dump runs for EVERY draw class. It self-bounds
  // internally (8 then every 200th), so this costs one 96-slot decode per draw
  // and produces a countable row either way. Without this the descriptor would
  // only ever be reported for kDMA draws - which this guest has never issued.
  // F-633: the sentence that used to end "...including the kAutoIndex class that
  // returns before the gate ladder" is superseded. kAutoIndex no longer returns
  // before the ladder; it IS the ladder's normal input.
  CpReportVertexFetchSlots("draw");

  // F-XXX: THE CONSOLE'S SHADER-CONSTANT STATE, measured on the CP side, once
  // per draw. This row exists because the CONSUMER of the constants
  // (src/render_thread.cpp's FillGuestConstantBank) reads the WRONG SOURCE -
  // guest memory at the raw SQ_VS_CONST value instead of the register file -
  // and this row is the independent measurement of what the CONSOLE's model
  // says, so the two can be compared in the SAME log.
  //
  // IT IS A NEW ROW, not a new field on CP-DRAW-CENSUS: that row is re-parsed
  // by tools/soak_census.py, so its field set stays as it is.
  //
  // THE NUMBERS: `vsBase`/`vsSize` are the (base, size) pair decoded out of
  // SQ_VS_CONST (registers.h:256-266), `psBase`/`psSize` out of SQ_PS_CONST
  // (:270-281); `aluDwordsPresent` counts the dwords of the ALU array
  // (0x4000..0x47FF) the guest has EVER written. The console's `cN` for the
  // vertex stage is array entry (vsBase + N) and for the pixel stage
  // (psBase + N) (shader_interpreter.cc:260-284).
  {
    static std::atomic<uint32_t> g_shaderConstCensus{0};
    const uint32_t scn =
        g_shaderConstCensus.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (scn <= 8u || (scn % 200u) == 0u) {
      CpShaderConstantInfo info;
      CpShaderConstantState(info);
      MCLA_LOG_WARN(
          "CP-SHADERCONST #{} vsRegPresent={} vsBase={} vsSize={} "
          "psRegPresent={} psBase={} psSize={} aluDwordsPresent={} "
          "aluDwords={} | console: cN(vs)=array[vsBase+N], cN(ps)="
          "array[psBase+N] (shader_interpreter.cc:260-284)",
          scn, info.vsRegPresent ? 1 : 0, info.vsBase, info.vsSize,
          info.psRegPresent ? 1 : 0, info.psBase, info.psSize,
          info.aluDwordsPresent, kCpShaderConstantDwords);
    }
  }

  // F-633: source_select is NOT a refusal by itself, and the old
  //   if (src != 0u) { refuse("no-index-buffer", ...); return; }
  // was the single reason 100.00% of the reachable stream (build/w661.log:
  // no-index-buffer=292599 of 292600 draws, enqueued=0) never produced a draw,
  // and it sat ABOVE the entire vertex-gate ladder, so eight reasons that should
  // have been exercised were unreachable rather than passing. A reason that can
  // never fire is not a check.
  //
  // The guest is not wrong and the reference is not missing: the reachable
  // stream is 100% source_select=kAutoIndex (2), and upstream DRAWS that class
  // non-indexed. command_processor.cc:1357-1361 sets index_buffer_info.guest_base
  // = 0 and .length = 0, :1308 leaves is_indexed = false, and :1380-1384 calls
  // IssueDraw(prim_type, num_indices, /*index_buffer=*/nullptr, ...). The
  // indices are implicit 0..num_indices-1.
  //
  // isIndexed is the index-buffer premise the whole ladder is built on. A
  // non-indexed draw has ibBytes == 0 BY CONSTRUCTION - no index buffer exists -
  // so the three index-buffer conditions below are conditioned on it, and the
  // kDMA case that SHOULD have an index buffer and does not keeps its own named
  // refusal (empty-index-buffer, VGT_DMA_SIZE.num_words == 0), which is a
  // different condition from this one.
  const bool isIndexed = (src == 0u);  // SourceSelect::kDMA
  if (src != 0u && src != 2u) {
    // kImmediate (1) and the invalid class (3). Upstream declines both too:
    // kImmediate logs and sets draw_succeeded = 0 (:1348-1356), and the default
    // arm sets draw_succeeded = 0 + assert_unhandled_case (:1362-1366), so no
    // draw is issued there either. This is now the ONLY member of the old
    // `src != 0u` family that is still refused, which is what the
    // no-index-buffer counter measures; its declaration comment above
    // (src/gpu_cp.cpp:160) still reads "source_select != kDMA" and is
    // superseded by this one. Measured zero on this stream: every w661 row is
    // src=2, so this refusal is reachable code, not a live gate.
    refuse("no-index-buffer", g_bridgeNoIndexBuffer,
           src == 1u
               ? "- source_select is kImmediate: unsupported upstream too "
                 "(command_processor.cc:1348-1356, draw_succeeded = 0). The VGT "
                 "immediate-data field is not decoded anywhere in this tree."
               : "- source_select is the invalid class 3: upstream takes the "
                 "default arm, draw_succeeded = 0 (command_processor.cc:"
                 "1362-1366). NOT treated as kAutoIndex, because upstream does "
                 "not either.");
    return;
  }

  if (isIndexed && ibBytes == 0u) {
    // A draw that SHOULD have an index buffer and does not. A kAutoIndex draw
    // reaching this line with ibBytes == 0 is correct, not a defect, which is
    // why the condition is isIndexed and not ibBytes.
    refuse("empty-index-buffer", g_bridgeEmptyIndex,
           "- kDMA draw with VGT_DMA_SIZE.num_words == 0: no index elements.");
    return;
  }
  // 64-bit: ibVa + ibBytes must stay inside the flat 4 GiB guest window. A
  // wrapped 32-bit sum would pass IsValid() and read the wrong guest page.
  // Both values are 0 for a non-indexed draw (upstream's guest_base/length),
  // so the check is vacuous there and is stated as kDMA-only rather than left
  // to read as a test that silently passed.
  if (isIndexed &&
      static_cast<uint64_t>(ibVa) + static_cast<uint64_t>(ibBytes) >
          0x100000000ull) {
    refuse("index-range-wrap", g_bridgeIndexWrap,
           "- VGT_DMA_BASE + VGT_DMA_SIZE.num_words*elemSize leaves the 4 GiB "
             "guest window (would wrap); NOT read.");
    return;
  }
  if (isIndexed && !mem.IsValid(ibVa, ibBytes)) {
    refuse("index-unreadable", g_bridgeIndexUnreadable,
           "- resolved index buffer is outside the guest window.");
    return;
  }
  // F-612, the self-lifting vertex gate - now a LADDER of four distinct
  // refusals, so the census can say WHICH piece is missing instead of
  // conflating them. F-611 collapsed "block never written" and "descriptor
  // decoded but stride unknown" into one row; those are different bugs with
  // different owners, and the second one is the expected steady state even in
  // a good soak.
  //
  // F-612 ALSO CORRECTS the F-611 comment that stood here, which asserted the
  // 0x4800 block "holds fetch INSTRUCTIONS" whose addresses are produced by
  // running a fetch-shader program. That is not what the block holds, and the
  // reference says so directly: register_file.h:59-67 hands out the entries as
  // xe_gpu_vertex_fetch_t, d3d12_command_processor.cc:2231-2232 turns one into
  // a byte range with `address << 2` / `size << 2`, and draw_util.cc:831-840
  // reads three real vertices straight out of slot 0 for the resolve path. The
  // block holds the BUFFER ADDRESS, LENGTH and ENDIAN. What is missing from it
  // is per-attribute stride/format/swizzle, and that lives in the vertex
  // microcode's vfetch packet (shader_interpreter.cc:1013-1014). So the
  // addresses were always here and were never being read; that is a decoding
  // bug, not a missing execution engine.
  CpVertexFetchSlot slots[8];
  const uint32_t nSlots = CpDecodeVertexFetchSlots(slots, 8u);
  if (fetchVbWrites == 0u) {
    refuse("no-vb-desc", g_bridgeNoVbDesc,
           "- index buffer validated, but the fetch/VB constant block "
             "0x4800-0x48BF has ZERO writes, so the guest has never described a "
             "vertex buffer. That block holds the fetch CONSTANTS "
             "(SHADER_CONSTANT_FETCH_00_0 .. _31_5, register_table.inc:2697+); "
             "nothing in it was written, so no descriptor exists.");
    return;
  }
  if (nSlots == 0u) {
    refuse("no-vertex-fetch-const", g_bridgeNoVbFetchConst,
           "- the fetch/VB block IS written (fetchVbWrites>0) but no slot "
             "decodes to FetchConstantType::kVertex (xenos.h:1106), so the "
             "writes are texture/loop constants sharing the window, not a "
             "vertex stream.");
    return;
  }
  const uint32_t ucodeDwords = CpVertexMicrocodeDwords();
  if (ucodeDwords == 0u) {
    refuse("microcode-absent", g_bridgeNoMicrocode,
           "- a kVertex fetch constant EXISTS and is decoded (base, length and "
             "endian are known) but no PM4_IM_LOAD has delivered a vertex "
             "program, so no attribute is bound to a stride or a format.");
    return;
  }
  // F-632: the gate F-612 could not pass. Walk the captured program, join the
  // vfetch to its fetch-constant slot, and require a descriptor whose stride is
  // a MEASURED value. The two remaining failure modes get DIFFERENT what= rows
  // because they have different fixes:
  //   vfetch-none        - the program executes no kVertexFetch at all
  //   vfetch-unreadable  - it does, but its slot does not resolve to kVertex
  uint32_t blocks = 0u;
  CpVertexDescriptor desc[8];
  const uint32_t nDesc =
      CpDecodeVertexDescriptor(desc, 8u, numIdx, "bridge", &blocks);
  if (nDesc == 0u) {
    if (blocks == 0u) {
      refuse("vfetch-none", g_bridgeVfetchNone,
             "- a kVertex fetch constant is decoded and a vertex program of " +
                 std::to_string(ucodeDwords) +
                 " dwords is captured, but the walk found NO exec block (no "
                 "kExec/kCondExec among the control-flow words), so no fetch word "
                 "could be selected. Either the walk is wrong or this is not a "
                 "vertex program. CP-MICROCODE-UNSUPPORTED "
                 "reason=no-instruction.");
      CpNoteMicrocodeUnsupported("no-instruction", slots[0].index,
                                 slots[0].physBase, slots[0].sizeWords);
    } else if (g_vfetchUnreadable.load(std::memory_order_relaxed) > 0u) {
      refuse("vfetch-unreadable", g_bridgeVfetchUnreadable,
             "- exec blocks were found and a kVertexFetch WAS decoded, but its "
               "fetch-constant slot did not resolve to FetchConstantType::kVertex "
               "in the 0x4800 block. NO descriptor is emitted. See "
               "CP-FETCHVB-INSTR could-not-resolve.");
      CpNoteMicrocodeUnsupported("unreadable", slots[0].index,
                                 slots[0].physBase, slots[0].sizeWords);
    } else {
      refuse("vfetch-none", g_bridgeVfetchNone,
             "- " + std::to_string(blocks) +
                 " exec block(s) walked, every fetch word examined, and none had "
                 "opcode 0 (ucode::FetchOpcode::kVertexFetch, ucode.h:532). This "
                 "program does not fetch vertices. CP-MICROCODE-UNSUPPORTED "
                 "reason=no-instruction.");
      CpNoteMicrocodeUnsupported("no-instruction", slots[0].index,
                                 slots[0].physBase, slots[0].sizeWords);
    }
    return;
  }

  // F-633: a vfetch_mini is NOT a vertex stream, and desc[0] must never be one.
  // ucode.h scopes the addressing fields to vfetch_full explicitly:
  //   fetch_constant_index() - "Applicable only to vfetch_full (the address from
  //     vfetch_full is reused in vfetch_mini)" (ucode.h:701-702)
  //   src() / is_src_relative() / is_index_rounded() - same scoping (ucode.h:707-
  //     709, :733-735)
  //   stride() - "Applicable only to vfetch_full" (ucode.h:737-739)
  //   offset()  - the dword added to the address the full fetch computed
  //     (ucode.h:740-741)
  // So a mini fetch's stride() == 0 is a LEGAL encoding of "the next dword(s) of
  // the register the full fetch just read", not a zero-stride draw. Emitting one
  // as desc[0] would hand the render thread vbStride = 0 and a swapped-in
  // address, which is exactly the substitution F-609 forbids.
  //
  // MEASURED in build/w661.log: 1,471 CP-FETCHVB-DESC rows with miniFetch=0 and
  // 4 with miniFetch=1, and ZERO rows where instr=0 was itself a mini fetch. The
  // mini rows are always the SECOND vfetch of the same program (instr=1,
  // strideDwords=0 offsetDwords=3), following a full fetch of stride 7 dwords =
  // 28 bytes at offset 0 on the same slot. So skipping them changes nothing in
  // the observed stream and is what keeps the zero-stride draw out of it.
  const CpVertexDescriptor *stream = nullptr;
  uint32_t nFull = 0u;
  for (uint32_t i = 0u; i < nDesc; ++i) {
    if (desc[i].miniFetch != 0u) {
      continue;
    }
    ++nFull;
    if (stream == nullptr) {
      stream = &desc[i];
    }
  }
  if (stream == nullptr) {
    refuse("vfetch-mini-only", g_bridgeMiniOnly,
           "- " + std::to_string(nDesc) +
               " descriptor(s) decoded, every one a vfetch_mini (opcode 0 with "
               "the is_mini_fetch bit set, ucode.h:769 - the bit gpu_cp.cpp:920 "
               "reads as t[1] bit 30). A mini fetch reuses the address its "
               "vfetch_full computed and its stride()/offset() do not apply "
               "(ucode.h:701-702, :737-739), so there is no stream to name. NOT "
               "drawn as a zero-stride stream.");
    return;
  }
  // F-648: more than one FULL vfetch means more than one stream, and one
  // command struct cannot carry several. Refused rather than picking the first
  // silently. See the g_bridgeVfetchMulti declaration for the measurement.
  if (nFull > 1u) {
    refuse("vfetch-multi", g_bridgeVfetchMulti,
           "- " + std::to_string(nFull) +
               " full (non-mini) vfetch instructions decoded, each bound to its "
               "own fetch-constant slot and therefore its own guest base address "
               "and stride. One (vbBase, vbStride, vbFormat) triple cannot "
               "describe them, so the first is NOT taken as 'the' stream.");
    return;
  }
  // A FULL fetch whose stride really is 0 dwords is a different thing: there is
  // no per-vertex advance, so a draw cannot be configured. Refused by name
  // rather than drawn with a substituted buffer (F-609).
  if (stream->strideBytes == 0u) {
    refuse("vfetch-stride0", g_bridgeStride0,
           "- slot " + std::to_string(stream->slotIndex) +
               " decodes to a vfetch_full whose stride() is 0 dwords, so "
               "consecutive vertices are not addressable. Measured, not "
               "assumed; NOT drawn as a zero-stride stream.");
    return;
  }

  // ---- F-747: THE VERTEX STREAM'S BYTE ORDER. Refused, because the transform
  // the guest's own fetch constant asks for cannot be applied downstream.
  //
  // WHAT IS MEASURED. On the live stream (build/w708.log, 08:39:32.974) the
  // fetch constant for the stream's slot reads endianness = 2, i.e.
  // xenos::Endian::k8in32 (xenos.h:196, and the uint32_t overload at
  // xenos.h:1061-1064 whose k8in32 arm is xe::byte_swap, i.e. a full 32-bit
  // reversal). GpuSwap32 in this file mirrors that arm exactly
  // (gpu_cp.cpp:2823-2825).
  //
  // WHY THAT MEANS THE HOST MUST REVERSE EVERY DWORD. The guest's memory image
  // holds its words big-endian and this file's register reads prove it rather
  // than assume it: CP-FETCHVB #1 in w708.log prints `reg=4800 val=17C8A2BF`,
  // which is the architected address 0x17C8A2BC OR the two endian bits, read
  // through CpType0Write -> mem.ReadU32BE (gpu_cp.cpp:1211-1217). A host-order
  // read of the same four bytes would have printed BFA2C817. Two independent
  // paths agree on 0x17C8A2BC: this one, and F640-CVIEW-TRANSLATE, which
  // derives it as view_va(0xD7C8A2BC) - the C16M base (boot_host.cpp:4052-4053).
  //
  // THE REFERENCE'S OWN ARITHMETIC, WHICH IS THE SHAPE THAT IS MISSING HERE:
  //   .research/xenia/src/xenia/gpu/shader_interpreter.cc:1031-1032 loads the
  //   dword RAW as a host uint32_t and :1048-1049 then applies
  //   `xenos::GpuSwap(memory_dwords[...], fetch_constant.endian)`. The same
  //   two-step shape is at draw_util.cc:839-849 (`GpuSwap(vertices_guest[i],
  //   fetch.endian)`). Raw load, then the guest-stated swap, on every dword.
  //
  // WHAT THIS TREE DOES INSTEAD, MEASURED: the consumer copies the stream
  // verbatim - `mem.ReadBytes(dc.vbBase, vb.data(), dc.vbSize)`, no endian
  // translation - and the backend reads
  // those bytes straight into a host float (`memcpy(&f, vp + l * 4u, 4)` at
  // src/d3d12_backend.cpp:2975). So every float lane arrives byte-reversed.
  // On the measured stream that is the whole difference between the two
  // readings of vertex 0 lane 0: the host reads 0x000000BF = 2.68e-43, a
  // denormal no guest ever writes as a position, and the architected reading is
  // 0xBF000000 = -0.5 exactly.
  //
  // WHY IT IS REFUSED HERE AND NOT APPLIED. Applying it needs the selector, and
  // the selector does not cross the queue boundary: CpVertexElement has no
  // endianness member and CpVertexFormat's four fields (xenos, dxgi, bytes,
  // known) are spoken for - both in src/render_queue.h, which this session does
  // not own. Note the asymmetry this leaves: the INDEX half has the same
  // problem solved (dc.ibSwap rides the command and XenosIndexElement /
  // TranscodeXenosIndices apply it), and the VERTEX half has no ibSwap
  // equivalent. So the draw is refused BY NAME rather than issued with a
  // byte-reversed vertex stream, which would rasterise guest geometry the
  // guest never described. Nothing here substitutes a value: base, length,
  // stride and the selector are all printed on the refusal line itself, so the
  // stream stays fully measured even though it is not drawn.
  // F-751 SUPERSEDES THE BLANKET REFUSAL THAT STOOD HERE.
  //
  // It existed because the selector could not cross the queue boundary:
  // CpVertexElement had no endianness member and CpVertexFormat's four
  // fields (xenos, dxgi, bytes, known) were spoken for - both in
  // src/render_queue.h. So the draw was refused BY NAME rather than issued
  // with a byte-reversed vertex stream, which would have rasterised guest
  // geometry the guest never described.
  //
  // F-751 CLOSED THAT GAP. render_queue.h now carries
  // CpVertexElement::endianness (last member, defaulted to
  // kCpVertexEndianNone), the element loop below fills it
  // (`el.endianness = e.endian`), and the consumer applies the guest's own
  // transform: src/render_thread.cpp:2170-2250 reads the per-element
  // selectors, refuses a disagreement between them (vb-endian-split),
  // refuses anything outside the four architected values
  // (vb-endian-unknown), and only then applies CpGpuSwap32 to every whole
  // dword of the copy it read - the reference's raw-load-then-swap two-step
  // at shader_interpreter.cc:1031-1032 and :1048-1049.
  //
  // SO WHAT REMAINS HERE IS THE WIDTH CHECK AND NOTHING ELSE. The guest
  // field is 2 bits (xenos.h:1122), so 0..3 is every guest-stated value. A
  // value outside that is a PRODUCER bug, not a guest one, and is refused by
  // name rather than masked - masking would pick a byte order nobody stated.
  // endian=0 is NOT refused and never was: it is a guest stating no
  // transform, which is a real, drawable stream.
  if (stream->endian > 3u) {
    static std::atomic<uint32_t> g_bridgeVbEndian{0};
    refuse("vb-endian-unarchitected", g_bridgeVbEndian,
           "- fetch-constant slot " + std::to_string(stream->slotIndex) +
               " carries endianness=" + std::to_string(stream->endian) +
               " (k8in32, xenos.h:196 / :1061-1064), so every 32-bit word of "
               "this stream is stored by the guest big-endian and must be "
               "byte-reversed before a host float can read it. The reference "
               "reverses it: raw dword load at shader_interpreter.cc:1031-1032 "
               "then GpuSwap(dword, fetch_constant.endian) at :1048-1049, the "
               "same shape at draw_util.cc:839-849. This tree copies the "
               "stream verbatim (mem.ReadBytes in the DRAW_CAPTURED case, "
               "src/render_thread.cpp:2131) and the backend reads those bytes "
               "straight into a host float "
               "(src/d3d12_backend.cpp:2975), so every lane arrives reversed: "
               "vertex 0 lane 0 reads 0x000000BF = 2.68e-43 where the "
               "architected value is 0xBF000000 = -0.5. The selector now "
               "crosses the queue boundary (CpVertexElement::endianness, "
               "render_queue.h, filled at the element loop below) and the "
               "index half's equivalent already works (dc.ibSwap), so the "
               "vertex half now matches it. This line fires only for a "
               "selector OUTSIDE the guest's 2-bit field, which is a producer "
               "value rather than a guest one. NOT masked, and no value is "
               "substituted. base=" +
               std::to_string(stream->baseVa) +
               " size=" + std::to_string(stream->sizeBytes) +
               " stride=" + std::to_string(stream->strideBytes) +
               " elements=" + std::to_string(nDesc) + ".");
    return;
  }

  // F-632: the descriptor is complete, so the enqueue is REACHABLE. This is a
  // named constant rather than a bare return so the dead path stays visible,
  // and one word reverses it.
  // F-648 SUPERSEDES the F-632 sentence that stood here, which read "The FIRST
  // FULL descriptor is the stream descriptor ... Taking the first and SAYING SO
  // (nFull is on the log line) beats picking one silently." Saying so is not
  // enough: the command still carried ONE base/stride/format triple, so a
  // multi-stream program would have had one of its attributes' buffers silently
  // presented as the vertex stream. nFull > 1 is now REFUSED (vfetch-multi)
  // above, so a command that exists always carries the whole of what the
  // program described. Measured nFull == 1 on all 1,472 rows of build/w662.log.
  // F-633: "first" is "first non-mini" - see the vfetch_mini note above.
  const CpVertexDescriptor &d0 = *stream;
  if (kCpVertexDescriptorComplete) {
    mcla::native::RenderCommand cmd;
    cmd.type = mcla::native::RenderCommand::DRAW_CAPTURED;
    auto &dc = cmd.data.emplace<mcla::native::DrawCapturedCommand>();
    dc.vbBase = d0.baseVa;         // F-612 kept the real decoded base.
    dc.vbSize = d0.sizeBytes;
    // F-632: the field that was a hard 0 under F-612. Real, from
    // instr.stride() * 4 - a DWORD count (ucode.h:737, width :773) scaled to
    // bytes exactly once, here. NOT a placeholder.
    dc.vbStride = d0.strideBytes;
    // F-648: the vertex format, CARRIED rather than printed. F-632 decoded
    // d0.dxgiFormat correctly and only put it on the CP-DRAW-BRIDGE line, so
    // nothing about the format reached the consumer and the draw path had a
    // stride with no format to build an input layout from. `bytes` is the tight
    // size of the format (CpXenosFormatBytes) so the consumer can check the
    // format/stride pair without re-deriving a format enum it does not own;
    // known == 0 makes the zero-initialised state a refusal, never a default.
    dc.vbFormat.xenos = d0.formatXenos;
    dc.vbFormat.dxgi = d0.dxgiFormat;
    dc.vbFormat.bytes = CpXenosFormatBytes(d0.formatXenos);
    dc.vbFormat.known = d0.isKnownFormat ? 1u : 0u;
    dc.vbDescCount = nDesc;
    dc.vbFullCount = nFull;
    // F-649: carry EVERY fetch the program declared, not just element 0's
    // summary. Before this the command stopped at the queue boundary: a second
    // fetch's format, destination register and swizzle were all decoded above
    // and then dropped on the floor, so the consumer had one (base, stride,
    // format) triple and no way to obtain the rest. Elements are copied in
    // program order, so `elementIndex` is a stable key for them.
    //
    // The loop is bounded by kCpVertexElementMax, which is 8 - the same bound
    // as `desc[8]` and the maxOut passed above - so this cannot overflow and
    // cannot disagree with the producer's own array about how many exist.
    dc.vbElementCount = 0u;
    for (uint32_t i = 0u; i < nDesc; ++i) {
      if (dc.vbElementCount >= mcla::native::kCpVertexElementMax) {
        break;
      }
      const CpVertexDescriptor &e = desc[i];
      mcla::native::CpVertexElement &el = dc.vbElements[dc.vbElementCount];
      el.elementIndex = e.elementIndex;
      el.dstReg = e.dstReg;
      el.dstRegAm = e.dstRegAm;
      el.srcReg = e.srcReg;
      el.srcRegAm = e.srcRegAm;
      el.srcSwizzle = e.srcSwizzle;
      el.dstSwizzle = e.destSwizzle;
      el.slotIndex = e.slotIndex;
      el.strideBytes = e.strideBytes;
      el.offsetBytes = e.offsetBytes;
      el.miniFetch = e.miniFetch;
      el.predicated = e.predicated;
      el.conditional = e.conditional;
      el.predCondition = e.predCondition;
      el.indexRounded = e.indexRounded;
      // F-751: the fetch constant's byte-order selector, CARRIED. The
      // consumer's byte-order model lives at src/render_thread.cpp:2170-2250
      // (reads dc.vbElements[fe].endianness, refuses a split, refuses an
      // unarchitected value, then applies CpGpuSwap32 to every whole dword of
      // the copy it read). Until this line existed the field was
      // kCpVertexEndianNone on every element, so that whole model was dead code
      // and every float lane arrived byte-reversed.
      //
      // The value is the raw 2-bit guest field (`xe_gpu_vertex_fetch_t`'s
      // `Endian endian : 2`, xenos.h:1122), decoded at gpu_cp.cpp:1705 and
      // :1735 onto CpVertexDescriptor::endian (:1393) via :1843, and printed on
      // CP-FETCHVB-DESC (:1877). All 8 CP-FETCHVB-DECODE and all 6
      // CP-FETCHVB-DESC rows in build/w708.log carry endian=2 (k8in32), which
      // is why this is load-bearing on the live path and not a hypothetical.
      //
      // It is the raw selector, NOT a normalised enum, and 0 means both "kNone"
      // and "not filled" - both of which mean NO SWAP, which is the safe
      // direction for an unfilled field to fail in.
      el.endianness = e.endian;
      // Reuses the ONE vf->DXGI table via CpXenosFormatToDxgi/CpXenosFormatBytes
      // (now declared in render_queue.h so a consumer can call them too), rather
      // than carrying a second copy of the mapping.
      el.fmt.xenos = e.formatXenos;
      el.fmt.dxgi = e.dxgiFormat;
      el.fmt.bytes = CpXenosFormatBytes(e.formatXenos);
      el.fmt.known = e.isKnownFormat ? 1u : 0u;
      ++dc.vbElementCount;
    }
    // F-633: for kAutoIndex these are upstream's guest_base = 0 and length = 0
    // (command_processor.cc:1357-1361) passed through untouched - there is no
    // index buffer and no substituted one. dc.numIndices below is the VERTEX
    // count for that class, which is what IssueDraw receives upstream (:1381).
    dc.ibBase = ibVa;
    dc.ibSize = ibBytes;
    dc.frameId = 0u;  // no guest frame counter exists in the CP; the render
                      // thread's own present count is the frame authority.
    dc.ibFmt = idxSize;
    dc.ibSwap = dmaSwap;
    dc.numIndices = numIdx;
    dc.idxOffset = CpRegPeek(0x02102u); // VGT_INDX_OFFSET, register_table.inc:503
    dc.primitiveTopology = prim;
    dc.sourceSelect = src;
    dc.cpSeq = seq;
    dc.opcode = opcode;
    dc.initiator = di;
    dc.psoHash = 0u; // no executed shader program to hash; see render_queue.h.
    // F-652: the shader programs and the raster-state registers, snapshotted
    // HERE, at the moment the draw is enqueued, out of state this thread owns.
    // Before this the command carried none of it: the consumer could not name
    // which program a draw selected, and could not tell a guest register that
    // arrived from one that was never written.
    CpSnapshotDrawState(dc.vsProgram, dc.psProgram, dc.rasterState);

    // F-652: program census, per draw, with the OUTCOME counted apart from the
    // attempt. Each stage gets its own counter so "carried a vertex program
    // address", "carried a pixel program address" and "no stage had ever been
    // loaded" are three different readings of one row rather than three zeroes.
    const bool vsHasAddr =
        (dc.vsProgram.present != 0u && dc.vsProgram.embedded == 0u);
    const bool psHasAddr =
        (dc.psProgram.present != 0u && dc.psProgram.embedded == 0u);
    (vsHasAddr ? g_bridgeProgVsPresent : g_bridgeProgVsAbsent)
        .fetch_add(1, std::memory_order_relaxed);
    (psHasAddr ? g_bridgeProgPsPresent : g_bridgeProgPsAbsent)
        .fetch_add(1, std::memory_order_relaxed);
    if (dc.vsProgram.embedded != 0u) {
      g_bridgeProgVsEmbedded.fetch_add(1, std::memory_order_relaxed);
    }
    if (dc.psProgram.embedded != 0u) {
      g_bridgeProgPsEmbedded.fetch_add(1, std::memory_order_relaxed);
    }
    for (uint32_t i = 0; i < mcla::native::kCpSnapRegCount; ++i) {
      if (dc.rasterState.presentMask & (1u << i)) {
        g_bridgeSnapCover[i].fetch_add(1, std::memory_order_relaxed);
      }
    }

    mcla::native::g_commandQueue.push(std::move(cmd));
    const uint32_t n =
        g_bridgeEnqueued.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (n <= 8u || (n % 200u) == 0u) {
      // F-633: indexed= is on the line because ib={:08X}+{} is 0+0 for the
      // kAutoIndex class and a reader cannot tell "no index buffer, by
      // construction" from "an index buffer that failed to resolve".
      // F-652: the program half rides the SAME bounded row rather than adding
      // one per draw, because bounding a log must not bound a census - the
      // counters above are the authority and these columns are the sample.
      // F-694: bodyVs=/bodyPs= are APPENDED AT THE END, after the existing
      // `-> render thread` text, and no byte above them moved. soak_census.py
      // counts CP-DRAW-BRIDGE as a matching LINE, not by field position, so
      // appending cannot change an existing count; a mid-row insert would have
      // put a new field where a reader expects the old one. `bodyVs` is dwords
      // SHIPPED and is NOT vsProg's trailing `d`, which is the DECLARED length
      // (img.totalDwords): the two differ exactly when the producer's read loop
      // stopped short, so a soak comparing them proves the body crossed rather
      // than the packet header being echoed back.
      MCLA_LOG_WARN("CP-DRAW-BRIDGE #{} op=0x{:02X} prim={} numIdx={} "
                    "vb={:08X}+{} stride={} fmtB={} ib={:08X}+{} elem={}B "
                    "swap={} idxOff={:08X} vf={} dxgi={} vbOff={} swiz={:03X} "
                    "nDesc={} nFull={} indexed={} | vsProg={:08X}/sp{}/{}d "
                    "psProg={:08X}/sp{}/{}d rsPresent={:08X} -> render thread"
                    " bodyVs={}/{} bodyPs={}/{} bodyTruncVs={} bodyTruncPs={}",
                    n, opcode, prim, numIdx, dc.vbBase, dc.vbSize, dc.vbStride,
                    dc.vbFormat.bytes, ibVa, ibBytes, idxBytes, dmaSwap,
                    dc.idxOffset, d0.formatXenos, d0.dxgiFormat, d0.offsetBytes,
                    d0.destSwizzle, nDesc, nFull, isIndexed ? 1u : 0u,
                    dc.vsProgram.guestAddr, dc.vsProgram.addrSpace,
                    dc.vsProgram.dwords, dc.psProgram.guestAddr,
                    dc.psProgram.addrSpace, dc.psProgram.dwords,
                    dc.rasterState.presentMask,
                    s_shipBody[0].dwords, s_shipBody[0].cap,
                    s_shipBody[1].dwords, s_shipBody[1].cap,
                    s_shipBody[0].truncated, s_shipBody[1].truncated);
      // F-649: the per-fetch element rows, on a NEW literal so none of the 244
      // tracked markers changes shape or count. One row per carried element,
      // inside the SAME bounded guard as CP-DRAW-BRIDGE above, so this cannot
      // turn a bounded log into an unbounded one.
      //
      // `dstReg` is the field that was missing: VertexFetchInstruction::dest()
      // (ucode.h:709), dword_0 bits 12..17. `elem` is the fetch's ORDINAL, not
      // a decoded field - see CpVertexElement in render_queue.h. `elemFull` is
      // the is_mini_fetch bit, kept separate from `nFull` (the whole command's
      // non-mini count) because the two are different questions.
      for (uint32_t ei = 0u; ei < dc.vbElementCount; ++ei) {
        const mcla::native::CpVertexElement &el = dc.vbElements[ei];
        MCLA_LOG_WARN(
            "CP-FETCHVB-ELEM #{} elem={}/{} dstReg={} dstAm={} srcReg={} "
            "srcAm={} srcSwiz={} dstSwiz={:03X} slot={} vf={} dxgi={} "
            "fmtB={} known={} strideB={} offB={} mini={} pred={} cond={} "
            "predCond={} idxRnd={}",
            n, el.elementIndex, dc.vbElementCount, el.dstReg, el.dstRegAm,
            el.srcReg, el.srcRegAm, el.srcSwizzle, el.dstSwizzle, el.slotIndex,
            el.fmt.xenos, el.fmt.dxgi, el.fmt.bytes, el.fmt.known,
            el.strideBytes, el.offsetBytes, el.miniFetch, el.predicated,
            el.conditional, el.predCondition, el.indexRounded);
      }
    }
  }
}

// Linear indirect-buffer executor (xenia ExecuteIndirectBuffer :575-593):
// contiguous guest memory holding the same packet encoding as the primary
// ring. Depth-guarded against runaway nesting.
void DrainIndirectBuffer(uint32_t byteAddr, uint32_t dwordCount, int depth);

// F-680: PM4_INDIRECT_BUFFER's list pointer -> the pool -> walk it. BOTH the ring
// path and the nested-IB path call THIS, so the two can no longer disagree about
// which view a physical list pointer lives in - they used to each call
// PhysToKernelVA separately, which is how one path could be fixed while the other
// kept reading zeros.
//
// It also carries `CP: IB-POOL-ALIAS`, the marker that decides whether the rule
// is right, on a NEW literal so `tools/soak_census.py`'s existing rows keep their
// exact shape. It prints, for one indirect buffer and in one line:
//   pa        the raw physical pointer the packet actually carried
//   cpRead    the address the CP used to read (pa | 0xC0000000) - what the
//             defect produced
//   poolRead  the address the CP reads now, and the one the builder wrote
//   aView     pa | 0xA0000000, the MEASURED guest EA->PA inverse, printed
//             separately so the identity is CHECKED in the log rather than
//             asserted in a comment (`aViewEqPool`)
//   cpHead / poolHead   the first 4 dwords at each
//   match     whether the two views' first 4 dwords agree - the alias question
//             itself. 0 is the EXPECTED post-fix answer in this tree; 1 would
//             mean the C view really does alias the pool, which would refute the
//             whole premise and must be taken at face value, not rounded off.
//   cpReadable / poolReadable  distinguish "the views differ" from "I could not
//             read one of them", which the ???????? convention below also encodes.
void CpDrainIndirectBufferByPhys(uint32_t listPtr, uint32_t listLen, int depth) {
  const uint32_t poolVa = CpPhysToPoolVa(listPtr, "INDIRECT_BUFFER");
  const uint32_t listLenMasked = listLen & 0xFFFFFu;

  static std::atomic<uint32_t> s_ibAliasSeen{0};
  const uint32_t an =
      s_ibAliasSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (an <= 4u || (an % 200u) == 0u) {
    auto &m = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t cpView = listPtr | 0xC0000000u;  // what PhysToKernelVA gave
    const uint32_t aView = listPtr | 0xA0000000u;   // the guest's own inverse
    uint32_t c[4] = {0, 0, 0, 0}, b[4] = {0, 0, 0, 0};
    bool cOk = true, bOk = (poolVa != 0u);
    for (uint32_t i = 0; i < 4u; ++i) {
      cOk &= m.ReadU32BE(cpView + i * 4u, &c[i]);
      if (bOk)
        bOk = m.ReadU32BE(poolVa + i * 4u, &b[i]);
    }
    const bool match = cOk && bOk && c[0] == b[0] && c[1] == b[1] &&
                       c[2] == b[2] && c[3] == b[3];
    // A failed read prints ???????? and never a zero: a zero here would be
    // indistinguishable from a MEASURED zero, which is the whole trap this file
    // exists to close (the same convention DrainIndirectBuffer's INDIRECT_BUFFER
    // row uses for its two probe windows).
    const auto quad = [](const uint32_t *w, bool ok) {
      std::string s;
      for (uint32_t i = 0; i < 4u; ++i) {
        if (i)
          s += ' ';
        s += ok ? fmt::format("{:08X}", w[i]) : std::string("????????");
      }
      return s;
    };
    MCLA_LOG_WARN(
        "CP: IB-POOL-ALIAS #{} depth={} pa={:08X} cpRead={:08X} poolRead={:08X} "
        "aView={:08X} aViewEqPool={} dwords={} cpHead={} poolHead={} match={} "
        "cpReadable={} poolReadable={} resolve={} xlateCalls={} xlateOk={} "
        "xlateRefused={}",
        an, depth, listPtr, cpView, poolVa, aView,
        (poolVa != 0u && poolVa == aView) ? 1 : 0, listLenMasked, quad(c, cOk),
        quad(b, bOk), match ? 1 : 0, cOk ? 1 : 0, bOk ? 1 : 0,
        poolVa ? "MAPPED" : "REFUSED",
        g_cpPoolXlateCalls.load(std::memory_order_relaxed),
        g_cpPoolXlateOk.load(std::memory_order_relaxed),
        g_cpPoolXlateRefused.load(std::memory_order_relaxed));
  }

  if (poolVa == 0u) {
    // Refused, and already counted + named by CP: POOL-XLATE-REFUSED. Walking
    // address 0 would be a fabricated stream, so nothing is walked.
    return;
  }
  DrainIndirectBuffer(poolVa & ~0x3u, listLenMasked, depth);
}

// PHASE-4 DIAGNOSTIC (cp_ib_trace=1): classify every packet inside an
// indirect-buffer walk so we know what the CP actually executes there.
bool IbTraceEnabled() {
  static const bool on = [] {
    const char *e = std::getenv("cp_ib_trace");
    return e != nullptr && e[0] == '1';
  }();
  return on;
}

// F-721: PM4_INVALIDATE_STATE (0x3B), from the reference verbatim.
// gpu/command_processor.cc:1592-1599 is the whole handler:
//   bool CommandProcessor::ExecutePacketType3_INVALIDATE_STATE(reader, packet,
//                                                                count) {
//     // selective invalidation of state pointers
//     /*uint32_t mask =*/reader->ReadAndSwap<uint32_t>();   // :1596
//     // driver_->InvalidateState(mask);                    // :1597 - commented OUT
//     return true;                                          // :1598
//   }
// The operand is READ AND DISCARDED even in the reference: the only line that
// would have consumed it is commented out there too. So the faithful behaviour
// is "consume one operand dword, change nothing", and this host says so rather
// than inventing a mask table nothing can act on. Field position: the mask is
// packet dword 1, i.e. guest address byteAddr + 4.
bool CpExecInvalidateState(uint32_t byteAddr, uint32_t count,
                           uint32_t &outAdvanceDwords) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  outAdvanceDwords = count + 1u;
  if (count < 1u) {
    return true;  // no operand present; nothing to read, nothing claimed
  }
  uint32_t mask = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &mask)) {
    // Unreadable body: consumed, NOT counted as an invalidation.
    return true;
  }
  const uint32_t n = g_invalidateState.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP-INVALIDATE-STATE #{} mask={:08X} - operand READ AND DISCARDED, "
        "nothing invalidated: command_processor.cc:1597's "
        "driver_->InvalidateState(mask) is COMMENTED OUT in the reference "
        "too, so this host is not skipping work the reference does || seen={} "
        "binMask={:016X} binSelect={:016X}",
        n, mask, n, g_binMask.load(std::memory_order_relaxed),
        g_binSelect.load(std::memory_order_relaxed));
  }
  return true;
}

// F-721: PM4_SET_BIN_MASK_LO / _HI and PM4_SET_BIN_SELECT_LO / _HI
// (0x60/0x61/0x62/0x63). Transcribed field-for-field from
// gpu/command_processor.cc:793-814, which is the entire reference implementation
// of all four - there is no helper and no register file behind them:
//     case PM4_SET_BIN_MASK_LO:   value = ReadAndSwap(); bin_mask_   = (bin_mask_   & 0xFFFFFFFF00000000ull) | value;              break;  // :793-797
//     case PM4_SET_BIN_MASK_HI:   value = ReadAndSwap(); bin_mask_   = (bin_mask_   & 0xFFFFFFFFull) | (uint64_t(value) << 32);    break;  // :798-803
//     case PM4_SET_BIN_SELECT_LO: value = ReadAndSwap(); bin_select_ = (bin_select_ & 0xFFFFFFFF00000000ull) | value;              break;  // :804-808
//     case PM4_SET_BIN_SELECT_HI: value = ReadAndSwap(); bin_select_ = (bin_select_ & 0xFFFFFFFFull) | (uint64_t(value) << 32);    break;  // :809-814
// Field position for all four: the value is packet dword 1, guest address
// byteAddr + 4. Each packet is ONE operand; count is 1 for the observed stream
// and the merge is a read-modify-write of the other half either way.
bool CpExecSetBinReg(uint32_t opcode, uint32_t byteAddr, uint32_t count,
                     uint32_t &outAdvanceDwords) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  outAdvanceDwords = count + 1u;
  if (count < 1u) {
    return true;
  }
  uint32_t value = 0;
  if (!mem.ReadU32BE(byteAddr + 4u, &value)) {
    // Unreadable body: consumed, register NOT modified. The reference would read
    // from the ring buffer and always succeed; here a refused read must not
    // silently merge a zero, so the register keeps the half it already had.
    return true;
  }
  const bool isMask = (opcode == kPm4SetBinMaskLo || opcode == kPm4SetBinMaskHi);
  const bool isLo = (opcode == kPm4SetBinMaskLo || opcode == kPm4SetBinSelectLo);
  std::atomic<uint64_t> &reg = isMask ? g_binMask : g_binSelect;
  const uint64_t old = reg.load(std::memory_order_relaxed);
  // The two merge shapes are the reference's own expressions, including which
  // half is preserved: LO keeps 0xFFFFFFFF00000000, HI keeps 0xFFFFFFFF.
  const uint64_t merged =
      isLo ? ((old & 0xFFFFFFFF00000000ull) | (uint64_t)value)
           : ((old & 0xFFFFFFFFull) | (static_cast<uint64_t>(value) << 32));
  reg.store(merged, std::memory_order_relaxed);
  const uint32_t n = g_binRegWrites.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP-BINREG #{} op={:02X} name={} value={:08X} old={:016X} "
        "new={:016X} - {} half of the 64-bit PFP {} register, merged exactly as "
        "command_processor.cc:{} does (LO preserves the high half, HI the low "
        "half). READER: the predicate gate at command_processor.cc:708-709, "
        "which skips a packet whose header bit 0 is set when "
        "(binSelect & binMask)==0 - implemented in DrainPacketAt || writes={}",
        n, opcode, isMask ? "BIN_MASK" : "BIN_SELECT", value, old, merged,
        isLo ? "LOW" : "HIGH", isMask ? "BIN_MASK" : "BIN_SELECT",
        isMask ? (isLo ? "793-797" : "798-803") : (isLo ? "804-808" : "809-814"),
        n);
  }
  return true;
}

// 0x54 PM4_INTERRUPT. Field position is the reference's own, one reader value:
// `uint32_t cpu_mask = reader->ReadAndSwap<uint32_t>();` at
// command_processor.cc:906 - the FIRST operand dword, byteAddr + 4. The
// reference's loop then runs over n in [0, 6) and dispatches (1, n) for every set
// bit (command_processor.cc:907-911), which is why `cpus` below is printed as a
// six-bit set rather than a count: six is the reference's own bound, and a mask
// with bit 6 or above set selects nothing the reference would act on.
//
// WHAT THIS DOES NOT DO, deliberately: it does not call the guest. The reference
// would run graphics_system.cc:241-261, which is a guest-code call, and this
// build cannot supply its execution context (r13's CPU number, the IRQL, the
// stack, and the runtime value of the pointer chain its only store goes through)
// without inventing all four. The full measurement and the refusal are on
// kPm4Interrupt above; the short form is that the satisfier for the wait this
// packet precedes is not in the PM4 stream, and guessing it is a fabrication.
//
// The advance is the reference's own shape. ExecutePacketType3_INTERRUPT does not
// call AdvanceRead - the reference's caller does, at the top of its own loop, by
// `count * sizeof(uint32_t)` - so a handler that returns true and leaves
// `count + 1` for the caller is the faithful transcription, and it is the same
// value the unhandled path already used. A refusal to read the operand must not
// change that: the packet is consumed either way, and nothing is invented when
// the operand is unreadable (the row then reports mask=0, i.e. "no CPU index was
// named", which is what an absent operand says).
bool CpExecInterrupt(uint32_t byteAddr, uint32_t count, uint32_t header,
                     uint32_t &outAdvanceDwords) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  outAdvanceDwords = count + 1u;
  uint32_t cpuMask = 0;
  const bool read = mem.ReadU32BE(byteAddr + 4u, &cpuMask);
  // The reference's own bound: `for (int n = 0; n < 6; n++)`
  // (command_processor.cc:907). Bits above 5 name no CPU index it would act on,
  // and are kept in `rawMask` so a soak can see that the packet carried them.
  uint32_t cpus = 0;
  for (uint32_t n = 0; n < 6u; ++n) {
    if (cpuMask & (1u << n)) {
      cpus |= (1u << n);
    }
  }
  const uint32_t n = g_interruptSeen.fetch_add(1, std::memory_order_relaxed) + 1u;
  // Census cadence, same shape as the sibling register rows (CP-BINREG uses
  // `n <= 8u || (n % 200u) == 0u`): bounded so a flood cannot own the log. The
  // exact per-packet count does not depend on this bound - the opcode histogram
  // in the indirect-buffer census is filled from the header word, before this
  // switch, and counts every 0x54 whether or not a row prints here.
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP-INTERRUPT #{} hdr={:08X} mask={:08X} cpus={:08X} operands={} "
        "read={} - decoded from the packet's own words: mask is operand dword 1 "
        "(command_processor.cc:906) and cpus is the set of CPU indices its loop "
        "at :907-911 would pass as the second argument to "
        "graphics_system.cc:241. F-818: NOW DISPATCHED via "
        "VdDispatchGraphicsInterrupt (imports.cpp) -- the consumer's r3==1 arm "
        "is fully measured (0x82411490-0x824114FC) and clears the "
        "PM4_WAIT_REG_MEM fence byte at [mb+0], which is what un-parks ring A. "
        "The handler does not advance the reader, the caller does.",
        n, header, cpuMask, cpus, count, read ? 1 : 0);
  }
  // F-818 (FENCECLEAR, ROOT CAUSE): the reference dispatches the registered graphics-interrupt
  // callback per set CPU bit -- command_processor.cc:900-913 -> DispatchInterruptCallback(1, n)
  // -> graphics_system.cc:241-261 with SetActiveCpu at :253. We consumed 0x54 as a deliberate
  // no-op, so the 10th PM4_WAIT_REG_MEM, the first whose satisfier is NOT the CP itself,
  // timed out and parked ring A on every boot (F-813: 144 parks, ref=0 while the byte held 4).
  // The old "NOT DISPATCHED BY NAME" note is superseded: everything it called unmeasurable is
  // now measured -- the registration (callback=0x82411478 user=0x40002080), the consumer's
  // r3==1 arm down to the fence RMW, and the call machinery (63/63 clean VSYNC-ISR rows on
  // this same consumer). Dispatched bits only, and only when the operand was readable.
  if (read && cpus != 0) {
    VdDispatchGraphicsInterrupt(cpus);
  }
  return true;
}

// F-XXX: THE CONSOLE'S SWAP PACKET, DECODED. One row, one shape, whichever path
// the packet arrived on (the ring ladder's legacy arm, or the packet handler
// below). The payload is the console's own layout
// (xenia src/xenia/kernel/xboxkrnl/xboxkrnl_video.cc:426-433):
//   [0] the 'SWAP' fourcc, [1] the front buffer's PHYSICAL address,
//   [2] width, [3] height.
//
// IT IS DECODED AND PUBLISHED, NOT DISPATCHED: this host's display engine is
// the D3D12 present path (D3D12Backend::ResolveGuestRenderTarget ->
// PresentOwnedFrame), so there is no PM4-driven scan-out here. What the row
// proves is that the console's swap event actually reached the CP.
static void LogXeSwap(uint32_t magic, uint32_t fb, uint32_t width, uint32_t height) {
  constexpr uint32_t kSwapMagic = 0x53574150u;  // 'SWAP' (xenos.h:31)
  const uint64_t n = g_swapCount.fetch_add(1) + 1;
  if (n <= 10 || (n % 300) == 0) {
    MCLA_LOG_INFO("CP: XE_SWAP #{} magic={:08X} magicOk={} fb={:08X} {}x{}", n,
                  magic, magic == kSwapMagic ? 1 : 0, fb, width, height);
  }
}

bool DrainPacketAt(uint32_t byteAddr, int depth, uint32_t &outAdvanceDwords) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t header = 0;
  if (!mem.ReadU32BE(byteAddr, &header)) {
    return false;
  }

  const uint32_t type = header >> 30;
  if (type == 2) {
    outAdvanceDwords = 1; // TYPE-2 filler NOP
    return true;
  }

  if (type == 0) {
    const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
    static std::atomic<uint32_t> ibType0Seen{0};
    if (ibType0Seen.fetch_add(1) < 8) {
      MCLA_LOG_INFO("CP[IB]: TYPE0 base={:04X} count={} writeOne={}",
                    header & kType0BaseMask, count,
                    ((header >> 15) & 0x1u) ? 1 : 0);
    }
    CpType0Write(header, byteAddr, count);
    outAdvanceDwords = count + 1u;
    return true;
  }

  if (type != 3) {
    MCLA_LOG_WARN("CP[IB]: unsupported packet type={} at {:08X}", type,
                  byteAddr);
    return false;
  }

  const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
  const uint32_t opcode = (header >> 8) & 0x7Fu;

  // F-721: the PFP predicate gate, from gpu/command_processor.cc:705-715, placed
  // where the reference places it - after the header is decoded and before the
  // opcode switch, so it applies to EVERY type-3 packet including the ones this
  // file handles by name.
  //     if (packet & 1) {                                  // :708
  //       bool any_pass = (bin_select_ & bin_mask_) != 0;   // :709
  //       if (!any_pass || opcode == PM4_XE_SWAP) {          // :710
  //         reader->AdvanceRead(count * sizeof(uint32_t));  // :711
  //         return true;                                    // :713
  //       }
  //     }
  // Bit 0 of the header is the predicate bit (`packet` in the reference is the
  // whole header word; this file's `header` is the same word, read at :4710).
  // With the 0xFFFFFFFF defaults (command_processor.h:284-285) any_pass is
  // always true here, so this is a no-op until the guest writes 0x60-0x63.
  if ((header & 1u) != 0u) {
    g_predicateGated.fetch_add(1, std::memory_order_relaxed);
    const uint64_t mask = g_binMask.load(std::memory_order_relaxed);
    const uint64_t sel = g_binSelect.load(std::memory_order_relaxed);
    const bool anyPass = ((sel & mask) != 0u);
    if (!anyPass && opcode != kPm4XeSwap) {
      const uint32_t n =
          g_predicateSkips.fetch_add(1, std::memory_order_relaxed) + 1u;
      if (n <= 8u || (n % 200u) == 0u) {
        MCLA_LOG_WARN(
            "CP-PREDICATE-SKIP #{} opcode={:02X} count={} hdr={:08X} "
            "binMask={:016X} binSelect={:016X} and={:016X} - (binSelect & "
            "binMask)==0, so command_processor.cc:710 skips this packet "
            "WITHOUT executing it. Packet consumed, rptr NOT advanced over "
            "any operand || gated={} skips={}",
            n, opcode, count, header, mask, sel, sel & mask,
            g_predicateGated.load(std::memory_order_relaxed), n);
      }
      outAdvanceDwords = count + 1u;
      return true;
    }
  }

  switch (opcode) {
  case kPm4IndirectBuffer: {
    if (depth >= 4) {
      MCLA_LOG_WARN("CP[IB]: nested INDIRECT_BUFFER beyond depth limit");
      return false;
    }
    uint32_t listPtr = 0, listLen = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &listPtr) ||
        !mem.ReadU32BE(byteAddr + 8, &listLen)) {
      return false;
    }
    // F-680: the list pointer is a guest PHYSICAL address and this tree's flat
    // window does not alias the C view onto the pool, so `| 0xC0000000` walked
    // zeros. Resolved through the one rule (CpDrainIndirectBufferByPhys), which
    // is shared with the ring path below.
    CpDrainIndirectBufferByPhys(listPtr, listLen, depth + 1);
    outAdvanceDwords = count + 1u;
    return true;
  }
  case kPm4MeInit: {
    static std::atomic<uint32_t> meInitSeen{0};
    if (meInitSeen.fetch_add(1) < 4) {
      MCLA_LOG_INFO("CP[IB]: ME_INIT count={}", count);
    }
    outAdvanceDwords = count + 1u;
    return true;
  }
  case kPm4MemWrite: {
    uint32_t wordAddr = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &wordAddr)) {
      return false;
    }
    // F-610: payload comes from the packet STREAM (body dwords 1..count-1 ==
    // byteAddr+8 .. byteAddr+4+count*4), not from the destination.
    uint32_t p = byteAddr + 8u;
    ExecuteMemWrite("IB", wordAddr, count, [&](uint32_t *out) {
      if (!mem.ReadU32BE(p, out)) {
        return false;
      }
      p += 4u;
      return true;
    });
    outAdvanceDwords = count + 1u;
    return true;
  }
  case kPm4DrawIndx:
  case kPm4DrawIndx2: {
    // T40.6: the draw packets. The first argument dword is VGT_DRAW_INITIATOR;
    // kDMA draws carry VGT_DMA_BASE + VGT_DMA_SIZE after it, kAutoIndex draws
    // carry nothing (indices are implicit 0..num_indices-1).
    // F-611: CpBridgeDraw below now hands the resolved state to the render
    // thread, or refuses it by name. It still does NOT paint: the Xenos register
    // file does not describe a vertex buffer for any class observed so far (see
    // CpBridgeDraw's header for the measurement). Advancing `count + 1` keeps
    // the stream in sync exactly as the old skip-everything default did.
    uint32_t di = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &di)) {
      return false;
    }
    const uint32_t prim = DrawInitiatorField(di, 0, 6);
    const uint32_t src = DrawInitiatorField(di, 6, 2);
    const uint32_t idxSize = DrawInitiatorField(di, 11, 1);
    const uint32_t numIdx = DrawInitiatorField(di, 16, 16);
    uint32_t dmaBase = 0, dmaSize = 0;
    if (src == 0 && count >= 3) { // SourceSelect::kDMA
      (void)mem.ReadU32BE(byteAddr + 8, &dmaBase);
      (void)mem.ReadU32BE(byteAddr + 12, &dmaSize);
    }
    // F-606: Xenia parity (command_processor.cc:1300-1334): the draw call
    // WriteRegisters VGT_DMA_BASE/SIZE/DRAW_INITIATOR. Mirrors the draw's own
    // params so later peeks see the last submission (zeros for auto class).
    CpRegPoke(0x21FAu, dmaBase);
    CpRegPoke(0x21FBu, dmaSize);
    CpRegPoke(0x21FCu, di);
    static std::atomic<uint32_t> s_drawSeen{0};
    const uint32_t n = s_drawSeen.fetch_add(1) + 1;
    // F-605: DRAW-MARKER pipe proof. Enqueue one synthetic marker per auto
    // draw (the only observed class: op36/src2, prim 1/8, 1-3 implicit
    // indices). No guest memory touched, no state changed - the marker
    // carries submission identity only; the handler draws CPU-side quads.
    if (kCpDrawMarkerPipe && src == 2u &&
        (opcode == kPm4DrawIndx || opcode == kPm4DrawIndx2)) {
      mcla::native::RenderCommand cmd;
      cmd.type = mcla::native::RenderCommand::DRAW_MARKER;
      auto &mk = cmd.data.emplace<mcla::native::DrawMarkerCommand>();
      mk.seq = n;
      mk.prim = prim;
      mk.numIdx = numIdx;
      mcla::native::g_commandQueue.push(std::move(cmd));
    }
    // F-611: the bridge. Decodes nothing new - it takes the fields above and
    // resolves them to guest addresses exactly as upstream does, then either
    // enqueues a real DRAW_CAPTURED or refuses by name. Called for EVERY draw
    // class, so the refusal census is a complete statement about what the
    // reachable stream can and cannot produce.
    CpBridgeDraw(n, opcode, di, prim, src, idxSize, numIdx, dmaBase, dmaSize);
    if (n <= 24 || (n % 64) == 0) {
      uint32_t hdr = 0;
      (void)mem.ReadU32BE(byteAddr, &hdr);
      MCLA_LOG_WARN("CP-DRAW #{} op=0x{:02X} src={} prim={} numIdx={} "
                    "idxSize={} dmaBase={:08X} dmaSize={:08X} initiator={:08X} "
                    "hdr={:08X} at {:08X}",
                    n, opcode, src, prim, numIdx, idxSize, dmaBase, dmaSize, di,
                    hdr, byteAddr);
    }
    // F-611: this line was UNBOUNDED - 4140 copies in the 2-minute soak
    // build/w654.log, ~20% of a 21 MB log, for a state snapshot that only
    // changes when a register does. Bounded now, and the seven fixed-index
    // peek it carries is demoted to what it always was: a guess (F-115a). The
    // authoritative vertex-side answer is g_fetchVbWrites, reported by
    // CP-DRAW-REFUSE and the CP-DRAW-BRIDGE line.
    if (n <= 8 || (n % 200) == 0) {
      MCLA_LOG_WARN("CP-DRAW-STATE #{} initiator={:08X} writes={} r08B={:08X} "
                    "r08C={:08X} r0DD={:08X} r0D2={:08X} r0A2={:08X} "
                    "r1DC={:08X} r1DD={:08X} fetchVbWrites={}",
                    n, di, g_xenosRegWrites.load(std::memory_order_relaxed),
                    CpRegPeek(0x08Bu), CpRegPeek(0x08Cu), CpRegPeek(0x0DDu),
                    CpRegPeek(0x0D2u), CpRegPeek(0x0A2u), CpRegPeek(0x1DCu),
                    CpRegPeek(0x1DDu),
                    g_fetchVbWrites.load(std::memory_order_relaxed));
    }
    // T41.4c: the whole batch this draw was preceded by, in write order, so the
    // AUTO-source VB/IB candidates are identifiable instead of guessed at
    // (F-115a). Non-zero values only; `PTR?` marks a value >= 0x40000000, i.e.
    // address-shaped in the guest VA space (F-115b read r0081=80010000 PTR?
    // this way).
    if (n <= 3) {
      const uint32_t total = g_cpTracePos.load(std::memory_order_relaxed);
      const uint32_t first =
          total > kCpTraceSize ? total - kCpTraceSize : 0u;
      for (uint32_t i = first; i < total; ++i) {
        const CpRegTraceEntry &e = g_cpTrace[i % kCpTraceSize];
        if (e.value == 0u)
          continue;
        MCLA_LOG_WARN("CP-DRAW-REGS #{} [{:02}/{:02}] r{:04X}={:08X} {}", n,
                      i - first, total - first, e.index, e.value,
                      (e.value >= 0x40000000u) ? "PTR?" : "");
      }
    }
    outAdvanceDwords = count + 1u;
    return true;
  }
  case 0x21:  // PM4_REG_RMW
    return CpExecRegRmw(byteAddr, outAdvanceDwords);
  // F-651: 0x3E was 80.2% of all unhandled Type-3 packets in build/w661.log
  // (17,556,480 of 21,884,928). 0x3C and 0x58 are the two packets on the same
  // path. SUPERSESSION: 0x3C is now EXECUTED (CpExecWaitRegMem, with
  // MakeCoherent reproduced from command_processor.cc:486-524), not refused;
  // 0x58 keeps its literal-form-only handling and its by-name counter form
  // refusal, which is unrelated to the fence.
  case kPm4RegToMem:  // PM4_REG_TO_MEM (register -> guest physical memory)
    return CpExecRegToMem(byteAddr, count, outAdvanceDwords);
  case kPm4WaitRegMem:  // PM4_WAIT_REG_MEM (fence; EXECUTED, bounded, parks)
    return CpExecWaitRegMemAt(byteAddr, count, outAdvanceDwords);
  case kPm4EventWriteShd:  // PM4_EVENT_WRITE_SHD (token write; literal form)
    return CpExecEventWriteShd(byteAddr, count, outAdvanceDwords);
  // 0x46 PM4_EVENT_WRITE. NOT a memory writer in the count==1 form -- see
  // CpExecEventWrite's header. It performs the VGT_EVENT_INITIATOR poke and
  // stores nothing; routing it here rather than to `default:` is what stops it
  // being counted as an unhandled Type-3 opcode, which it now is not.
  case kPm4EventWrite:  // PM4_EVENT_WRITE (register poke only; no memory write)
    return CpExecEventWrite(byteAddr, count, outAdvanceDwords);
  case kPm4ImLoad:  // PM4_IM_LOAD (pointer form)
    return CpExecImLoad(byteAddr, count, outAdvanceDwords, false);
  case kPm4ImLoadImmediate:  // PM4_IM_LOAD_IMMEDIATE (embedded form)
    return CpExecImLoad(byteAddr, count, outAdvanceDwords, true);
  case kPm4SetConstant:  // PM4_SET_CONSTANT (fetch/VB block lives here)
    return CpExecSetConstant(byteAddr, count, false, outAdvanceDwords);
  case kPm4SetConstant2:  // PM4_SET_CONSTANT2 (raw-index writes)
    return CpExecSetConstant(byteAddr, count, true, outAdvanceDwords);
  // F-721: the last five opcodes CP-T3-UNHANDLED was still counting. w701.log
  // listed exactly 0x3B x3, 0x60 x2, 0x61, 0x62, 0x63 = 8 rows; each now has a
  // handler whose every field position is cited above. 0x3B consumes its operand
  // and changes nothing (the reference's own invalidate call is commented out),
  // and 0x60-0x63 feed the two bin registers that the predicate gate above
  // reads - so none of these five writes state that nothing consumes.
  case kPm4InvalidateState:  // PM4_INVALIDATE_STATE (cc:1592-1599)
    return CpExecInvalidateState(byteAddr, count, outAdvanceDwords);
  case kPm4SetBinMaskLo:   // PM4_SET_BIN_MASK_LO   (cc:793-797)
  case kPm4SetBinMaskHi:   // PM4_SET_BIN_MASK_HI   (cc:798-803)
  case kPm4SetBinSelectLo: // PM4_SET_BIN_SELECT_LO (cc:804-808)
  case kPm4SetBinSelectHi: // PM4_SET_BIN_SELECT_HI (cc:809-814)
    return CpExecSetBinReg(opcode, byteAddr, count, outAdvanceDwords);
  // 0x54 PM4_INTERRUPT (xenos.h:1622). DECODED, NOT DISPATCHED - the split and
  // the evidence are on kPm4Interrupt. Placed here, before `default:`, so the
  // predicate gate above it applies to this packet exactly as it applies to the
  // unhandled path it replaces, and so the two paths keep the SAME advance:
  // `count + 1` appears in `default:` below unchanged, and appears again inside
  // CpExecInterrupt. That equality is the whole claim this case makes, and it is
  // what the harness in the handoff report checks by shearing either copy.
  case kPm4Interrupt:  // PM4_INTERRUPT (cc:900-913; field at cc:906)
    return CpExecInterrupt(byteAddr, count, header, outAdvanceDwords);
  // F-XXX: 0x45 PM4_COND_WRITE. The ONLY opcode the guest actually emits that
  // this switch did not decode (MEASURED: 8 packets per boot, `CP-T3-UNHANDLED
  // op=0x45 thisOp=1..8` in build/w842.log and build/run845.txt). The
  // decoder, the console's six-dword layout and the falsifier are on
  // CpExecCondWrite, above. Placed here, before `default:`, so the predicate
  // gate above applies to this packet exactly as it applies to every packet
  // it replaces, and so the advance is the same `count + 1` the unhandled arm
  // used - the stream cannot drift by one dword because of this change.
  case kPm4CondWrite:  // PM4_COND_WRITE (cc:1110-1175)
    return CpExecCondWrite(byteAddr, count, outAdvanceDwords);
  // F-XXX: 0x64 PM4_XE_SWAP -- THE CONSOLE'S SWAP TO THE DISPLAY ENGINE.
  //
  // It was DECODED but UNREACHABLE: the packet had no case here, so it fell
  // into `default:` (counted as an unhandled Type-3) and the `CP: XE_SWAP` row
  // in the ring ladder could only be reached by a packet that WRAPS the ring
  // end. build/w854.log therefore carries 0 `CP: XE_SWAP` rows -- and there was
  // nothing to decode, because the host never emitted the packet either
  // (CpEmitXeSwap, and the VdSwap hook that calls it).
  //
  // The payload is the console's own (xboxkrnl_video.cc:426-433):
  //   [0] 'SWAP' fourcc, [1] the front buffer's PHYSICAL address,
  //   [2] width, [3] height.
  case kPm4XeSwap: {
    uint32_t magic = 0, fb = 0, w = 0, h = 0;
    if (!mem.ReadU32BE(byteAddr + 4, &magic) ||
        !mem.ReadU32BE(byteAddr + 8, &fb) ||
        !mem.ReadU32BE(byteAddr + 12, &w) ||
        !mem.ReadU32BE(byteAddr + 16, &h)) {
      return false;
    }
    LogXeSwap(magic, fb, w, h);
    outAdvanceDwords = count + 1u;
    return true;
  }
  default:
    LogType3Unhandled(opcode, count, byteAddr, depth);
    outAdvanceDwords = count + 1u;
    return true;
  }
}

// Credit pending windows whose bytes an executed INDIRECT_BUFFER range
// actually covered. Called from DrainIndirectBuffer - i.e. consumption is
// credited when the content REALLY executes, never at reservation time.
// credited when the content REALLY executes, never at reservation time.
void CreditDeferredRange(uint32_t startVA, uint32_t endVA) {
  std::vector<PendingConsume> done;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    auto it = std::remove_if(g_pendingWindows.begin(), g_pendingWindows.end(),
                             [&](const PendingConsume &w) {
                               if (w.startVA >= startVA && w.endVA <= endVA) {
                                 done.push_back(w);
                                 return true;
                               }
                               return false;
                             });
    g_pendingWindows.erase(it, g_pendingWindows.end());
  }
  if (done.empty()) {
    return;
  }

  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  uint32_t credited = 0;
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  uint32_t pcBefore = 0;
  if (blk != 0) {
    uint32_t cur = 0;
    if (mem.ReadU32BE(blk + 88, &cur)) {
      pcBefore = cur;
    }
  }
  for (const auto &w : done) {
    credited += w.dwords;
  }
  if (credited != 0) {
    ScbNoteConsumption();
  }
  // Real consumption covered these windows - publish their completion
  // counts to the guest (E98 wait contract).
  CpAdvanceGuestPublication(static_cast<uint32_t>(done.size()));
  if (blk != 0 && credited != 0) {
    AccumProgress(credited);
  }

  static std::atomic<uint32_t> s_creditCount{0};
  const uint32_t n = s_creditCount.fetch_add(1) + 1;
  if (n <= 16 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: DEFER-CREDIT #{:04} range [{:08X},{:08X}) windows={} "
                  "credited={} pc {}->{}",
                  n, startVA, endVA, done.size(), credited, pcBefore,
                  pcBefore + credited);
  }
}
void DrainIndirectBuffer(uint32_t byteAddr, uint32_t dwordCount, int depth) {
  constexpr uint32_t kMaxDwords = 0x100000u; // hard stop vs runaway streams
  const uint32_t limited = dwordCount > kMaxDwords ? kMaxDwords : dwordCount;

  // Change 2 (falsification probe, measurement only): the read window's first
  // 8 dwords AND the same 8 dwords at +0x200, so a soak can separate
  // "this window is genuinely zero" from "we read the wrong offset". Neither
  // side is synthesized: both are straight GuestMemoryHeap reads, and an
  // unreadable dword prints as ???????? rather than 00000000 so a failed read
  // can never masquerade as a measured zero. Same line, same marker, extended
  // cadence: the original first-12 gate is preserved and a low periodic tail
  // (every 500th) is added so the answer is available at steady state and not
  // only in the first 6 seconds (w675.log: all 12 rows land by 09:18:39).
  static std::atomic<uint32_t> ibEnterSeen{0};
  const uint32_t ibN = ibEnterSeen.fetch_add(1) + 1u;
  if (ibN <= 12u || (ibN % 500u) == 0u) {
    auto &ibMem = mcla::kernel::GuestMemoryHeap::Instance();
    std::string head, plus;
    head.reserve(80);
    plus.reserve(80);
    for (uint32_t i = 0; i < 8u; ++i) {
      uint32_t w0 = 0, w1 = 0;
      const bool ok0 = ibMem.ReadU32BE(byteAddr + i * 4u, &w0);
      const bool ok1 = ibMem.ReadU32BE(byteAddr + 0x200u + i * 4u, &w1);
      if (i)
        head += ' ';
      if (i)
        plus += ' ';
      head += ok0 ? fmt::format("{:08X}", w0) : std::string("????????");
      plus += ok1 ? fmt::format("{:08X}", w1) : std::string("????????");
    }
    MCLA_LOG_INFO("CP: INDIRECT_BUFFER #{} @ {:08X} dwords={} depth={} | "
                  "win[0..7]={} | win+0x200[0..7]={}",
                  ibN, byteAddr, limited, depth, head, plus);
  }

  uint32_t p = 0;
  // MEASURED DEFECT, DELIBERATELY NOT FIXED HERE: walked= can exceed dwords= by
  // exactly one. w700.log CP: IB-OPC-CENSUS #7 reads dwords=1038134
  // walked=1038135. Cause: the TYPE-0 arm advances `count + 1u` with no clamp
  // against `limited`, so a packet starting on the LAST valid dword walks one past
  // the declared end. It is not merely cosmetic: CpType0Write then touches the
  // register payload dword at index `limited`, which is OUTSIDE the buffer the IB
  // packet declared. It is bounded to one dword, it is NOT the freeze (that is the
  // WAIT_REG_MEM park), and clamping `p` here would silently change the
  // AccumProgress(p) credit accounting below and the CreditDeferredRange span, so
  // the clamp belongs with its own measurement, not in this fix.
  const bool trace = IbTraceEnabled() && depth == 0;
  uint32_t tCounts[4] = {0, 0, 0, 0};
  uint32_t opCount[128] = {};
  uint32_t nonzeroType3 = 0, firstT3Off = 0, firstT3Hdr = 0;
  while (p < limited) {
    if (trace) {
      uint32_t hdrProbe = 0;
      if (mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(byteAddr + p * 4u,
                                                              &hdrProbe)) {
        const uint32_t ty = hdrProbe >> 30;
        tCounts[ty < 4 ? ty : 3]++;
        if (ty == 3) {
          const uint32_t op = (hdrProbe >> 8) & 0x7Fu;
          if (op < 128)
            opCount[op]++;
          if (op != 0) {
            if (nonzeroType3 == 0) {
              firstT3Off = p;
              firstT3Hdr = hdrProbe;
            }
            nonzeroType3++;
          }
        }
      }
    }
    uint32_t advance = 0;
    if (!DrainPacketAt(byteAddr + p * 4, depth, advance)) {
      MCLA_LOG_WARN("CP[IB]: desync at dword {} - aborting buffer", p);
      break;
    }
    p += advance;
  }

  // WHY opCount[128] PRINTED NOTHING ON 3004/3004 ROWS - MEASURED, not guessed.
  // The array is NOT dead: it is filled at :3743-3745 and printed at :3806. It
  // was empty because the fill is gated on `ty == 3` and MEASURED on all 3040
  // `CP: IB-OPC-CENSUS` rows of build/w677.log every row reads t3=0 with
  // walked == 2*t0 (row 1: dwords=11 t0=6 walked=12; row 2: dwords=64 t0=32
  // walked=64), and trace=1 on 3040/3040 rows. walked == 2*t0 is the signature
  // of an ALL-ZERO buffer: hdr>>30 == 0 makes every dword look like a TYPE-0
  // header of count 0, so the walk is 2 dwords per packet and no header ever
  // reaches the `ty == 3` arm. The rows are honest; the population they walked
  // is empty. The 0x3C flood the census was built to name is NOT here - it is
  // in the RING (w677 PKT-CAP #0006 win=B7C8A2BC carries C0043C00), and the
  // ring walk had NO opcode census at all. That is the gap now filled:
  // g_ringOpCount, fed by DrainRing, printed as `CP: RING-OPC-CENSUS`.
  //
  // Change 1 (measurement only): opCount[] has been computed above and
  // discarded. Emit it, non-zero entries only, so the T3 population this walk
  // actually saw has a per-opcode breakdown instead of a single "other" total.
  // Cadence mirrors the PKT-CAP summary row (n<=32 || n%100==0) so a soak can
  // read the two next to each other; the counter is the IB walk index, NOT the
  // PKT-CAP descriptor index (those are different atomics in different files -
  // gpu_device.cpp owns g_pktCap), so the rows are ordered/interleaved, not
  // index-matched. ibTotal is cumulative precisely so a reader can pair them.
  //
  // `trace` is printed because opCount[] is filled ONLY under the cp_ib_trace
  // gate (and depth==0). Without that field an all-zero row is ambiguous
  // between "no Type-3 packets were seen" and "the census never ran" - the
  // F-057(6) dead-marker trap. trace=0 means this row is NOT evidence of an
  // empty population; only trace=1 rows are.
  static std::atomic<uint32_t> ibCensusSeen{0};
  static std::atomic<uint64_t> ibWalkTotal{0};
  const uint32_t cn = ibCensusSeen.fetch_add(1) + 1u;
  ibWalkTotal.fetch_add(1, std::memory_order_relaxed);
  if (cn <= 32u || (cn % 100u) == 0u) {
    std::string ops;
    ops.reserve(512);
    uint32_t t3Total = 0;
    for (uint32_t i = 0; i < 128u; ++i) {
      if (opCount[i] == 0)
        continue;
      ops += fmt::format(" op=0x{:02X} count={}", i, opCount[i]);
      t3Total += opCount[i];
    }
    MCLA_LOG_INFO("CP: IB-OPC-CENSUS #{} ibTotal={} win={:08X} dwords={} "
                  "depth={} trace={} walked={} t0={} t1={} t2={} t3={} "
                  "nonzeroT3={} firstT3Off={} firstT3Hdr={:08X} ||{}",
                  cn, ibWalkTotal.load(std::memory_order_relaxed), byteAddr,
                  limited, depth, trace ? 1 : 0, p, tCounts[0], tCounts[1],
                  tCounts[2], t3Total, nonzeroType3, firstT3Off, firstT3Hdr,
                  ops);
  }

  // Deferred experiment: this range's content has now actually executed.
  // Credit any pending reservation windows fully contained in it.
  if (DeferredConsumeEnabled()) {
    CreditDeferredRange(byteAddr, byteAddr + limited * 4u);
  }

  // EXPERIMENT A (cp_deferred_consume_experiment=1): XTEB+0x58 counts
  // dwords FETCHED BY THE CP - ring and indirect content alike. Evidence
  // (mcla_ibtrace.log 14:08): the driver enqueues a 1,019,567-dword
  // zero-padded INDIRECT_BUFFER immediately before parking on the 5000
  // threshold - a unit that only makes sense as fetched-dword accounting.
  // Credit the walked span at depth 0 only (nested content is part of the
  // parent span; double-fetch not modeled). Real consumption only.
  if (DeferredConsumeEnabled() && p != 0) {
    AccumProgress(p);
    static std::atomic<uint32_t> s_ibCredit{0};
    const uint32_t nIb = s_ibCredit.fetch_add(1) + 1;
    if (nIb <= 12 || (nIb % 200) == 0) {
      MCLA_LOG_INFO("CP: IB-CREDIT #{} base={:08X} credited={} dwords", nIb,
                    byteAddr, p);
    }
  }
}

// Drain packets from rptr up to wptr (both dword indices mod cap) for THE
// ring identified by the doorbell/wptr source. Synchronous on the calling
// thread; per-ring draining guard keeps a concurrent vblank drain out.
void DrainRing(RingState &ring, uint32_t wptr, const char *source) {
  const uint32_t cap = ring.capDwords;
  if (cap == 0 || wptr >= cap) {
    // Phase-6: wptr outside owning ring window.
    static std::atomic<bool> warnedBadWptr{false};
    if (!warnedBadWptr.exchange(true)) {
      MCLA_LOG_WARN("CP: RING {} doorbell wptr={:08X} rejected (cap={})",
                    ring.id, wptr, cap);
    }
    return;
  }

  uint32_t rptr = ring.rptrIndex.load(std::memory_order_relaxed);
  const uint32_t startRptr = rptr;
  uint32_t guard = cap * 2u + 16u; // hard stop against runaway streams

  // RING-SPAN (log-only, no behaviour change): the pending ring window has
  // never been dumped raw. Every ring measurement so far is an aggregate
  // (DRAIN's `consumed`, VDRAIN-CENSUS's sameWptr), which cannot distinguish
  // "the guest wrote real PM4 packets" from "the guest wrote zeros we then
  // decode as TYPE-0 no-ops" - the same ambiguity that made CP: IB-OPC-CENSUS
  // read as 437 'real' TYPE-0 writes on an all-zero indirect buffer (zero has
  // hdr>>30 == 0, so it scores as TYPE-0). Print the first few RAW dwords of
  // the pending span so the ring's actual content is on the record.
  // Bounded to the first 32 non-empty drains and 8 dwords each.
  if (rptr != wptr) {
    static std::atomic<uint32_t> ringSpanSeen{0};
    const uint32_t rn = ringSpanSeen.fetch_add(1) + 1u;
    if (rn <= 32u) {
      std::string raw;
      raw.reserve(160);
      const uint32_t span = (wptr + cap - rptr) % cap;
      const uint32_t shown = (span < 8u) ? span : 8u;
      for (uint32_t i = 0; i < shown; ++i) {
        if (i)
          raw += ' ';
        raw += fmt::format("{:08X}", ReadRingU32(ring, (rptr + i) % cap));
      }
      MCLA_LOG_INFO("CP: RING {} SPAN #{} rptr={:04X} wptr={:04X} span={} "
                    "raw[0..{}]={}",
                    ring.id, rn, rptr, wptr, span, shown, raw);
    }
  }

  while (rptr != wptr && guard--) {
    const uint32_t header = ReadRingU32(ring, rptr);
    const uint32_t type = header >> 30;

    if (type == 2) {
      // TYPE-2 filler NOP (0x80000000).
      rptr = (rptr + 1u) % cap;
      continue;
    }

    if (type == 3) {
      const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
      const uint32_t opcode = (header >> 8) & 0x7Fu;
      if (opcode < 128u) {
        g_ringOpCount[opcode].fetch_add(1, std::memory_order_relaxed);
        g_ringT3Total.fetch_add(1, std::memory_order_relaxed);
      }
      // F-651(3): the ring is where the guest actually submits. Before this,
      // a 0x3C arriving here fell to LogType3Unhandled and the fence was
      // simply not there - which is why build/w677.log can carry 13,085,934
      // `other_t3` packets (every one of them 0x3C, per PKT-CAP #0006's
      // C0043C00) and still have ZERO CP-WAITREGMEM rows. A ring packet that
      // does not wrap the ring end is CONTIGUOUS in guest memory, so the whole
      // shared decoder - DrainPacketAt, every opcode in it - runs on it
      // verbatim, with no copy and no synthesised dword. A packet that WOULD
      // wrap is refused by name and counted: reading it linearly would read
      // bytes that are not the packet, which is the one thing this must not do.
      if (rptr + count + 1u <= cap) {
        g_waitRegMemParkPending.store(0u, std::memory_order_relaxed);
        uint32_t advance = 0;
        g_ringT3Delegated.fetch_add(1, std::memory_order_relaxed);
        if (DrainPacketAt(ring.baseGuestVA + rptr * 4u, -1, advance) &&
            advance != 0u &&
            g_waitRegMemParkPending.load(std::memory_order_relaxed) == 0u) {
          rptr = (rptr + advance) % cap;
          continue;
        }
        if (g_waitRegMemParkPending.load(std::memory_order_relaxed) != 0u) {
          // An unsatisfied 0x3C PARKED this walk. rptr is NOT advanced and
          // rptr is NOT published: the guest keeps seeing the packet it asked
          // us to wait on, which is a visible stall rather than a fabricated
          // completion. Say so once per ring so the row is countable.
          const uint32_t p = g_waitRegMemParked.fetch_add(1,
                                                         std::memory_order_relaxed) +
                              1u;
          MCLA_LOG_ERROR("CP: RING {} PARKED at rptr={:04X} header={:08X} on an "
                         "unsatisfied PM4_WAIT_REG_MEM (op=0x3C) - rptr NOT "
                         "advanced, NOT published; see CP-WAITREG-TIMEOUT / "
                         "CP-WAITREG-NEVERWRITTEN. parkEvents={}",
                         ring.id, rptr, header, p);
          return; // leave rptr where it is; PublishRptr is not reached
        }
        // Decode refused or made no progress: fall through to the legacy
        // per-opcode handling below rather than skipping the dwords.
      } else {
        const uint64_t wr =
            g_ringT3WrapRefused.fetch_add(1, std::memory_order_relaxed) + 1u;
        if (wr <= 8u || (wr % 200u) == 0u) {
          MCLA_LOG_WARN("CP: RING {} type3 op=0x{:02X} count={} at rptr={:04X} "
                        "WOULD WRAP the ring end (cap={} dwords) - NOT decoded: "
                        "a linear read would return bytes that are not this "
                        "packet. Falls through to the legacy ladder. "
                        "wrapRefused={}",
                        ring.id, opcode, count, rptr, cap, wr);
        }
      }

      if (opcode == kPm4XeSwap && count >= 4) {
        // Payload: [0]="SWAP fourcc, [1]=frontbuffer phys,
        // [2]=width, [3]=height (xenia xboxkrnl_video.cc VdSwap).
        // F-XXX: routed through the SAME row the packet handler uses, so a
        // packet that wraps the ring end and one that does not are counted
        // and printed identically (one counter, one shape).
        const uint32_t magic = ReadRingU32(ring, (rptr + 1u) % cap);
        const uint32_t fb = ReadRingU32(ring, (rptr + 2u) % cap);
        const uint32_t width = ReadRingU32(ring, (rptr + 3u) % cap);
        const uint32_t height = ReadRingU32(ring, (rptr + 4u) % cap);
        LogXeSwap(magic, fb, width, height);
      } else if (opcode == kPm4IndirectBuffer && count >= 2) {
        // PM4_INDIRECT_BUFFER (xenia :943-953): [list_ptr, list_len]
        // - execute the referenced buffer's packets now.
        uint32_t listPtr = ReadRingU32(ring, (rptr + 1u) % cap);
        uint32_t listLen = ReadRingU32(ring, (rptr + 2u) % cap);
        // PM4_INDIRECT_BUFFER carries a PHYSICAL list pointer (Xenia maps it
        // through physical memory). F-058's `| 0xC0000000` made real register
        // offsets + nested IBs appear, and it was WRONG: it is 0x20000000 above
        // the pool byte, and this flat window accepts a read there, so the walk
        // saw zeros (F-680; measured in build/w679.log - see
        // CpDrainIndirectBufferByPhys). Resolved through the one rule, shared
        // with the nested-IB path so the two cannot drift.
        CpDrainIndirectBufferByPhys(listPtr, listLen, 0);
      } else if (opcode == kPm4MeInit) {
        // PM4_ME_INIT (xenia :880-890): CP micro-engine init -
        // consumes count dwords of ME binary; no memory side effects.
        static std::atomic<uint32_t> meInitSeen{0};
        if (meInitSeen.fetch_add(1) < 4) {
          MCLA_LOG_INFO("CP: ME_INIT count={}", count);
        }
      } else if (opcode == kPm4MemWrite && count >= 2) {
        // PM4_MEM_WRITE (command_processor.cc:1092-1108): the destination is
        // ring dword +1, the payload is ring dwords +2..+count. F-610: the
        // payload used to be read back out of the DESTINATION, so nothing was
        // ever stored.
        const uint32_t wordAddr = ReadRingU32(ring, (rptr + 1u) % cap);
        uint32_t k = rptr + 2u;
        ExecuteMemWrite("RING", wordAddr, count, [&](uint32_t *out) {
          *out = ReadRingU32(ring, k % cap);
          ++k;
          return true;
        });
      } else {
        LogType3Unhandled(opcode, count, ring.baseGuestVA + rptr * 4u, -1);
      }

      rptr = (rptr + count + 1u) % cap;
      continue;
    }

    if (type == 0) {
      // TYPE-0: write `count` consecutive registers from a base index.
      // F-610: 15-bit base + the bit-15 alternate encoding, shared with the
      // indirect-buffer path through CpType0Apply. The ring is circular, so
      // the payload comes from ReadRingU32 rather than a linear guest read -
      // the reader is the only thing that differs between the two paths.
      const uint32_t count = ((header >> 16) & 0x3FFFu) + 1u;
      static std::atomic<uint32_t> type0Seen{0};
      if (type0Seen.fetch_add(1) < 8) {
        MCLA_LOG_INFO("CP: TYPE0 base={:04X} count={} writeOne={}",
                      header & kType0BaseMask, count,
                      ((header >> 15) & 0x1u) ? 1 : 0);
      }
      uint32_t k = rptr + 1u;
      CpType0Apply("RING", header, count, [&](uint32_t *out) {
        *out = ReadRingU32(ring, k % cap);
        ++k;
        return true;
      });
      rptr = (rptr + count + 1u) % cap;
      continue;
    }

    // TYPE-1 or garbage: refusing to guess - drop to wptr so the
    // submitter unsticks, and say so loudly exactly once.
    static std::atomic<bool> warnedDesync{false};
    if (!warnedDesync.exchange(true)) {
      MCLA_LOG_ERROR("CP: RING {} desync at rptr={} header={:08X} - dropping "
                     "to wptr {:04X}",
                     ring.id, rptr, header, wptr);
    }
    rptr = wptr;
    break;
  }

  ring.rptrIndex.store(rptr, std::memory_order_relaxed);
  ring.lastDoorbellWptr.store(wptr, std::memory_order_relaxed);
  PublishRptr(ring);
  g_drainCount.fetch_add(1);

  // CP: RING-OPC-CENSUS - the census the IB walk could not provide. Same shape
  // as `CP: IB-OPC-CENSUS` and the same reason for existing: opCount[] there is
  // filled only for `ty == 3`, and 3040/3040 rows of build/w677.log read t3=0
  // with walked == 2*t0, i.e. that walk only ever saw zero-filled buffers. The
  // 13,085,934 `other_t3` packets the PKT-CAP summary reports are in the ring,
  // so this is the row that can finally name them. `delegated` counts packets
  // handed to the shared decoder above and `wrapRefused` those deliberately not
  // decoded; a reader can therefore tell "not present" from "not decoded".
  {
    const uint64_t w = g_ringDrainWalks.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (w <= 32u || (w % 100u) == 0u) {
      std::string ops;
      ops.reserve(512);
      uint64_t t3 = 0;
      for (uint32_t i = 0; i < 128u; ++i) {
        const uint32_t c =
            g_ringOpCount[i].load(std::memory_order_relaxed);
        if (c == 0)
          continue;
        ops += fmt::format(" op=0x{:02X} count={}", i, c);
        t3 += c;
      }
      MCLA_LOG_INFO("CP: RING-OPC-CENSUS #{} walks={} t3={} delegated={} "
                    "wrapRefused={} ||{}",
                    w, g_ringDrainWalks.load(std::memory_order_relaxed), t3,
                    g_ringT3Delegated.load(std::memory_order_relaxed),
                    g_ringT3WrapRefused.load(std::memory_order_relaxed), ops);
    }
  }

  // Kernel-side role: the real kernel CP consumer bumps the submitting
  // thread's GPU progress counter (*(r13+256)+88) as ring data is consumed;
  // sub_82412F98 busy-returns until it advanced >=5000 past the snapshot
  // (75.cpp:18449-18571). We run synchronously ON the submitter thread
  // (doorbell store), so its own PPC context is live here. Increment is
  // exactly the dwords consumed this drain - derived, not invented.
  if (const uint32_t advanced = (rptr - startRptr + cap) % cap; advanced != 0) {
    if (DeferredConsumeEnabled()) {
      // Batched publication: flushed once per vblank.
      AccumProgress(advanced);
      if (PPCContext *ctx0 = GetPPCContext()) {
        const uint32_t tls0 = ctx0->r13.u32;
        uint32_t blk0 = 0;
        auto &mem0 = mcla::kernel::GuestMemoryHeap::Instance();
        if (tls0 != 0 && mem0.ReadU32BE(tls0 + 256, &blk0) && blk0 != 0) {
          g_progressBlk.store(blk0, std::memory_order_relaxed);
        }
      }
    } else if (PPCContext *ctx = GetPPCContext()) {
      auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
      const uint32_t tls = ctx->r13.u32;
      uint32_t blk = 0;
      if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0) {
        g_progressBlk.store(blk, std::memory_order_relaxed);
        uint32_t cur = 0;
        if (mem.ReadU32BE(blk + 88, &cur)) {
          (void)mem.WriteU32BE(blk + 88, cur + advanced);
        }
      }
    }
  }
}

} // namespace

// F-647: the register-file export. The Xenos register file (g_xenosReg) was
// file-scope inside the anonymous namespace above, so NOTHING outside this
// translation unit could read it -- which is what stalled F-646's consumer:
// renderer::PipelineStateInputs::registersPresent (renderer/pipeline_cache.h:
// 113) needs to know which of PA_CL_CLIP_CNTL / PA_SU_SC_MODE_CNTL /
// PA_CL_VTE_CNTL (0x2204/0x2205/0x2206) actually arrived with a draw, and the
// values DO arrive (measured build/w660.log + w661.log, `CP-DRAW-REGS` rows
// r2204=00010000 r2205=00010000 r2206=00000300), but there was no path out of
// the file. This is that path, and it is the narrowest one that can work:
//
//   * READ-ONLY. There is no CpWriteGuestRegisters and no non-const reference
//     to g_xenosReg escapes this function; g_xenosReg stays anonymous-namespace
//     internal state. The consumer physically cannot write the register file.
//   * PER-REGISTER PRESENCE, not a value. `present` out-param is non-zero iff
//     that index has ever been poked (F-647 bitmap above). A caller that gets
//     present=0 MUST treat `value` as meaningless -- it is the initialiser 0,
//     not the guest's 0. This is the fact that keeps a never-written register
//     from decoding as a legal zero value (F-646).
//   * COUNTED and named. One bounded CP-REGS-EXPORT row per call, with a
//     per-register hit count, so a soak can answer "did the render thread ever
//     actually ask for the register file, and did all three arrive" instead of
//     inferring it from the absence of a marker.
//
// LOCK ORDERING (stated so the next reader cannot deadlock): there is NO lock
// here, and that is deliberate, not an omission. g_xenosReg is already an array
// of std::atomic<uint32_t> and presence is an array of atomic words, so a
// single-register read is a load and needs no mutual exclusion -- exactly as
// the file's own hot-path readers already treat it (CpRegPeek, the CP-DRAW-STATE
// line, CpScratchWriteback all do relaxed atomic loads with no lock). Adding a
// mutex here would have had to be taken on the CpRegPoke side too, and that
// would put a lock on the hottest path in the command processor, for no
// correctness gain the atomics do not already provide.
//
// The alternative was a seqlock (odd/even counter around the whole array) to
// make MULTI-register reads mutually consistent. It is NOT used: the CP has
// exactly one writer (the command-processor thread) and the only multi-register
// callers read 0x2204..0x2206, which a single TYPE-0 packet writes in
// sequence (w660 CP-DRAW-REGS shows all three adjacent at trace positions
// 30/31/32). The API is therefore documented as "consistent per register, not
// across registers"; a caller that needs cross-register atomicity must add a
// seqlock then, and the comment here is the place that says so.
//
// If a seqlock IS added later the ordering rule is fixed: the seqlock counter
// is the OUTERMOST lock on both sides, and no caller may hold g_microcodeMutex
// (the microcode window, written under its own lock at the g_microcode store in
// CpExecImLoad) across a call to this function. This function takes no other
// lock, so it is already safe to call while holding g_microcodeMutex; that is
// the one direction that is currently reachable and it is deliberate.
bool CpReadGuestRegisters(const uint32_t *indices, uint32_t count,
                          uint32_t *values, uint32_t *present) {
  static std::atomic<uint64_t> s_regExportCalls{0};
  static std::atomic<uint64_t> s_regExportRegs{0};
  static std::atomic<uint64_t> s_regExportPresent{0};
  static std::atomic<uint64_t> s_regExportOob{0};

  uint32_t hits = 0;
  uint32_t oob = 0;
  for (uint32_t i = 0; i < count; ++i) {
    const uint32_t idx = indices[i];
    if (idx >= kXenosRegCount) {
      // A guest-supplied index can never reach here (indices are compile-time
      // constants at every call site), but the bound is checked and COUNTED
      // rather than asserted -- an assert on a value that could in principle
      // come from guest state is exactly what this project forbids.
      if (values) values[i] = 0u;
      if (present) present[i] = 0u;
      ++oob;
      continue;
    }
    const uint32_t word =
        g_xenosRegPresent[idx >> 5].load(std::memory_order_acquire);
    const bool isPresent = (word & (1u << (idx & 31u))) != 0u;
    if (values) values[i] = g_xenosReg[idx].load(std::memory_order_relaxed);
    if (present) present[i] = isPresent ? 1u : 0u;
    if (isPresent) ++hits;
  }

  const uint64_t calls =
      s_regExportCalls.fetch_add(1, std::memory_order_relaxed) + 1u;
  s_regExportRegs.fetch_add(count, std::memory_order_relaxed);
  s_regExportPresent.fetch_add(hits, std::memory_order_relaxed);
  s_regExportOob.fetch_add(oob, std::memory_order_relaxed);

  // House pattern: n <= K || (n % 200) == 0. K = 8 (the file's usual 8 for
  // state that stops changing) and every 200th after, so a long soak still
  // gets a countable row without the 4140-copy flood F-611 removed from
  // CP-DRAW. The tail of the row is the running totals, so a soak can read
  // attempts and per-register outcomes SEPARATELY: `present={}/{}` is
  // hits/requested, and the trailing presentTotal/regsTotal is the same
  // fraction over the whole run.
  if (calls <= 8u || (calls % 200u) == 0u) {
    char regs[192] = {};
    size_t at = 0;
    for (uint32_t i = 0; i < count && at + 24 < sizeof(regs); ++i) {
      const int w = std::snprintf(
          regs + at, sizeof(regs) - at, "%s%04X=%08X%s", i ? " " : "", indices[i],
          values ? values[i] : 0u, (present && present[i]) ? "*" : "!");
      if (w < 0) break;
      at += static_cast<size_t>(w);
    }
    MCLA_LOG_WARN(
        "CP-REGS-EXPORT #{} regs={} present={}/{} oob={} | {} "
        "| totals calls={} regs={} present={}",
        static_cast<uint32_t>(calls), count, hits, count,
        static_cast<uint32_t>(oob), regs,
        s_regExportCalls.load(std::memory_order_relaxed),
        s_regExportRegs.load(std::memory_order_relaxed),
        s_regExportPresent.load(std::memory_order_relaxed));
  }
  return oob == 0u;
}

// ---------------------------------------------------------------------------
// F-XXX: the guest's render target and its copy, decoded from the Xenos
// register file. See src/gpu_cp.h for the guest-byte citations (the PE image
// at VA 0x827ED1C8 / 0x827ED498 / 0x827EDB4C, and the running values in
// build/w842.log's CP-REG-HI rows).
//
// EVERY FIELD COMES FROM THE REGISTER FILE. There is no fallback value and no
// "sane default": a register the guest never wrote reads back as the
// initialiser zero, which is what the guest's state actually is, and the
// consumer decides whether a zero pitch is usable.
//
// THE FIELD LAYOUTS ARE Xenia's, quoted at the consumer:
//   RB_SURFACE_INFO    registers.h:670-680
//   RB_COLOR_INFO      registers.h:736-752
//   PA_SC_SCREEN_SCISSOR_BR registers.h:598-608
//   RB_MODECONTROL     registers.h:660-668
//   RB_COPY_CONTROL    registers.h:853-868
// ---------------------------------------------------------------------------
CpGuestRenderTarget CpGuestRenderTargetInfo() {
  // ONE export call, so the snapshot is one array read and the CP-REGS-EXPORT
  // row can show the same words the consumer used.
  static constexpr uint32_t kIdx[8] = {
      kCpRegRbSurfaceInfo,   kCpRegRbColorInfo,     kCpRegPaScScreenScissorBr,
      kCpRegRbModeControl,   kCpRegRbCopyControl,   kCpRegRbCopyDestBase,
      kCpRegRbCopyDestPitch, kCpRegRbCopyDestInfo};
  uint32_t val[8] = {0};
  uint32_t pres[8] = {0};
  (void)CpReadGuestRegisters(kIdx, 8u, val, pres);

  const uint32_t surface = val[0];
  const uint32_t color = val[1];
  const uint32_t scissor = val[2];
  const uint32_t mode = val[3];
  const uint32_t copyControl = val[4];
  const uint32_t copyDestBase = val[5];
  const uint32_t copyDestPitch = val[6];
  const uint32_t copyDestInfo = val[7];

  CpGuestRenderTarget out;
  out.surfacePitch = surface & 0x3FFFu;          // +0  14 bits, pixels
  out.msaaSamples = (surface >> 16) & 0x3u;       // +16 2 bits
  out.hizPitch = (surface >> 18) & 0x3FFFu;      // +18 14 bits
  out.colorBase = color & 0x7FFu;               // +0  11 bits, EDRAM tiles
  out.colorFormat = (color >> 16) & 0xFu;        // +16 4 bits
  out.scissorBrX = scissor & 0x7FFFu;            // +0  15 bits, signed
  out.scissorBrY = (scissor >> 16) & 0x7FFFu;    // +16 15 bits, signed
  out.edramMode = mode & 0x7u;                   // +0  3 bits
  out.copyControl = copyControl;
  out.copyDestBase = copyDestBase;
  out.copyDestPitch = copyDestPitch;
  out.copyDestInfo = copyDestInfo;
  return out;
}

// ---------------------------------------------------------------------------
// F-XXX: THE CONSOLE'S SWAP PACKET, WRITTEN INTO THE GUEST'S OWN PM4 STREAM.
// (The declaration and the console's own words are in src/gpu_cp.h.)
//
// THE PACKET NUMBERS, all from the console:
//   PM4_XE_SWAP = 0x64                      (xenos.h:1624; kPm4XeSwap at :2381)
//   XE_GPU_REG_SHADER_CONSTANT_FETCH_00_0 = 0x4800 (register_table.inc:2697)
//   kSwapSignature = 'SWAP' = 0x53574150     (xenos.h:31; base/memory.h:479-483)
// and the two header forms (xenos.h:1637-1664):
//   MakePacketType0(index, count) = ((count - 1) << 16) | (index & 0x7FFF)
//   MakePacketType3(opcode, count) = (3 << 30) | ((count - 1) << 16) | (op << 8)
//   MakePacketType2()               = (2 << 30)
// The host's own TYPE-0/TYPE-3 decoders agree with those forms exactly
// (count = ((header >> 16) & 0x3FFF) + 1, base = header & 0x7FFF,
// opcode = (header >> 8) & 0x7F: DrainPacketAt:5889-5891 and :5907).
//
// THE ORDER IS THE CONSOLE'S: the fetch constant first (it tells the display
// engine what the front buffer's layout is -- tiled bit, pitch, size), then
// the swap. The guest's own frame puts the kCopy draw into the EDRAM copy
// unit BEFORE this, and the guest reserves this ring block at the END of the
// frame's packets (the guest's own bytes: 0x82419A0A0 `li r4,64` ->
// 0x82419A0A8 `bl 0x82412928`, the 64-word reservation, and
// 0x82419A0E8 `addi r11,r30,256` -> 0x82419A0EC `stw r11,48(r31)`, the guest
// advancing its own ring write pointer by 256 bytes AFTER the call).
// So the packets land after the frame's draws and before the flip.
//
// THE 63, NOT 64: the reference writes 64 dwords FROM buffer_ptr
// (xboxkrnl_video.cc:407-434), and the guest passed buffer_ptr = reserved+4
// (0x82419A0E0 `addi r3,r30,4`) out of a 64-WORD reservation whose end the
// guest publishes as reserved+256. 64 dwords from reserved+4 would run FOUR
// BYTES PAST the guest's own reservation, so the host writes the 63 dwords
// that fit: the 12 packet dwords plus 51 NOP2. The four bytes BEFORE
// buffer_ptr are the guest's own block header and are not touched -- exactly
// as on the console, where the reference does not write them either.
// ---------------------------------------------------------------------------
bool CpEmitXeSwap(uint32_t ringVa, const uint32_t fetch[6], uint32_t physAddr,
                  uint32_t width, uint32_t height) {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  if (ringVa == 0u || fetch == nullptr) {
    return false;
  }

  constexpr uint32_t kFetchReg = 0x4800u;      // XE_GPU_REG_SHADER_CONSTANT_FETCH_00_0
  constexpr uint32_t kSwapOpcode = 0x64u;      // PM4_XE_SWAP
  constexpr uint32_t kSwapMagic = 0x53574150u;  // 'SWAP'
  constexpr uint32_t kNop2 = 0x80000000u;       // MakePacketType2()
  constexpr uint32_t kPacketDwords = 12u;       // 1 + 6 (TYPE-0) + 1 + 4 (TYPE-3)
  constexpr uint32_t kFillDwords = 63u;         // 64 words minus the guest's header word

  uint32_t pkt[kPacketDwords];
  pkt[0] = ((6u - 1u) << 16) | kFetchReg;  // MakePacketType0(kFetchReg, 6)
  // The console replaces the fetch constant's base_address -- the CPU VIRTUAL
  // address the header carries -- with the PHYSICAL one
  // (xboxkrnl_video.cc:385-387: `gpu_fetch.base_address =
  // frontbuffer_physical_address >> 12;`). base_address is dword_1's top 20
  // bits (xenos.h:1230), so the physical address goes back where it was.
  pkt[1] = fetch[0];
  pkt[2] = (fetch[1] & 0x00000FFFu) | (physAddr & 0xFFFFF000u);
  pkt[3] = fetch[2];
  pkt[4] = fetch[3];
  pkt[5] = fetch[4];
  pkt[6] = fetch[5];
  pkt[7] = (3u << 30) | ((4u - 1u) << 16) | (kSwapOpcode << 8);  // MakePacketType3
  pkt[8] = kSwapMagic;
  pkt[9] = physAddr;
  pkt[10] = width;
  pkt[11] = height;

  uint32_t written = 0;
  for (uint32_t i = 0; i < kFillDwords; ++i) {
    const uint32_t v = (i < kPacketDwords) ? pkt[i] : kNop2;
    if (!mem.WriteU32BE(ringVa + i * 4u, v)) {
      break;
    }
    ++written;
  }
  const bool ok = (written == kFillDwords);

  // F-XXX: the emission census. `emitOk` counts the writes that landed and
  // `emitCalls` the attempts, so a zero of either is a measurement and not a
  // silence (F-057(6): a tracked marker whose producer never ran reports
  // zero and means nothing). The row is bounded: the first 8 and every 200th.
  static std::atomic<uint64_t> g_xeSwapEmitCalls{0};
  static std::atomic<uint64_t> g_xeSwapEmitOk{0};
  const uint64_t n = g_xeSwapEmitCalls.fetch_add(1, std::memory_order_relaxed) + 1u;
  if (ok) {
    g_xeSwapEmitOk.fetch_add(1, std::memory_order_relaxed);
  }
  if (n <= 8u || (n % 200u) == 0u) {
    MCLA_LOG_WARN(
        "CP: XE_SWAP-EMIT #{} ring={:08X} dwords={}/{} ok={} magic={:08X} "
        "fb={:08X} wh={}x{} fetchD1={:08X} emitOk={}/{}",
        n, ringVa, written, kFillDwords, ok ? 1 : 0, kSwapMagic, physAddr, width,
        height, fetch[1], g_xeSwapEmitOk.load(std::memory_order_relaxed),
        g_xeSwapEmitCalls.load(std::memory_order_relaxed));
  }
  return ok;
}

// ---------------------------------------------------------------------------
// F-XXX: THE CONSOLE'S SHADER-CONSTANT MODEL, produced here.
//
// The full citation of the console's layout, the guest's own bytes and the
// host's divergence is on the DECLARATION in src/gpu_cp.h (the header is the
// place a consumer reads first). What follows is the PRODUCER.
//
// THE THREE FACTS THIS FILE USES, and where each comes from:
//   1. The array is 512 float4 at register 0x4000 (register_table.inc:648,
//      SHADER_CONSTANT_000_X; 0x4000..0x47FF = 2048 dwords).
//   2. `cN` of a stage = the array entry (base_stage + N), zero when
//      N > size_stage or (base_stage + N) >= 512
//      (shader_interpreter.cc:260-284).
//   3. base/size come from SQ_VS_CONST (0x2307) / SQ_PS_CONST (0x2308) as
//      (bits 0..8, bits 12..20) with size = vec4 count MINUS ONE
//      (registers.h:256-281).
//
// NEW SYMBOLS, listed for rule 1b: CpShaderConstantRegBase, CpShaderConstantCount,
// CpShaderConstantDwords, CpShaderConstantBytes, CpShaderStage,
// CpShaderConstantInfo, CpBuildShaderConstantBank, CpBuildShaderConstantArray,
// CpShaderConstantState, g_shaderConstCensus (all declared in src/gpu_cp.h
// except the last two, which are file-local to this TU).
//
// BYTE ORDER. The register file holds the guest's words as host uint32 values
// (already byte-swapped out of the guest's big-endian stream by ReadU32BE), so
// the big-endian bytes the packer expects are RE-ASSEMBLED here, once, at the
// producer. The host's single endian site (renderer::PackXenosConstantBank,
// pipeline_cache.cpp:1317-1351) then swaps them back. This is not a second
// endian site: it is the same single swap, moved to the producer that owns
// the data.
//
// PRESENCE. The console reads the register SHADOW (shader_interpreter.cc:282
// reads register_file_[...]), so an entry the guest never wrote reads back as
// ZERO on the console - and that is the console's state, not a missing value.
// The presence COUNT is reported separately (aluDwordsPresent) so a consumer
// can say "the array is all zeros" AND "the guest never wrote it", which are
// two different facts.
//
// The two helpers it needs (CpShaderConstantState, CpWriteShaderConstantFloat4)
// are defined ABOVE CpBridgeDraw, because the draw bridge's CP-SHADERCONST
// census row calls the first one.

bool CpBuildShaderConstantBank(CpShaderStage stage, uint8_t *out,
                                uint32_t outBytes, CpShaderConstantInfo *info) {
  if (out == nullptr || outBytes < 16u) {
    return false;
  }
  CpShaderConstantInfo local{};
  CpShaderConstantInfo &inf = (info != nullptr) ? *info : local;
  CpShaderConstantState(inf);
  const bool pixel = (stage == CpShaderStage::kPixel);
  const uint32_t base = pixel ? inf.psBase : inf.vsBase;
  const uint32_t size = pixel ? inf.psSize : inf.vsSize;
  const uint32_t entries = outBytes / 16u;
  // Zeros first: the console returns ZEROS for every cN outside the stage's
  // window (shader_interpreter.cc:267-269 and :277-279), so the tail of the
  // bank must be zeros and not whatever the previous frame left there.
  std::memset(out, 0, entries * 16u);
  uint32_t filled = 0;
  for (uint32_t i = 0; i < entries; ++i) {
    if (i > size) {
      break;  // the console's own "index > size -> zeros" rule
    }
    const uint32_t idx = base + i;
    if (idx >= kCpShaderConstantCount) {
      break;  // the console's own "index >= 512 -> zeros" rule
    }
    CpWriteShaderConstantFloat4(out + i * 16u, idx);
    ++filled;
  }
  inf.entriesFilled = filled;
  return true;
}

bool CpBuildShaderConstantArray(uint8_t *out, uint32_t outBytes,
                                 CpShaderConstantInfo *info) {
  if (out == nullptr || outBytes < 16u) {
    return false;
  }
  CpShaderConstantInfo local{};
  CpShaderConstantInfo &inf = (info != nullptr) ? *info : local;
  CpShaderConstantState(inf);
  const uint32_t entries = outBytes / 16u;
  std::memset(out, 0, entries * 16u);
  uint32_t filled = 0;
  for (uint32_t i = 0; i < entries; ++i) {
    if (i >= kCpShaderConstantCount) {
      break;
    }
    CpWriteShaderConstantFloat4(out + i * 16u, i);
    ++filled;
  }
  inf.entriesFilled = filled;
  return true;
}


// Advance guest publication counter (subctx+0) for all tracked devices.
// Used to unblock guest fence waits when CP is idle but guest thinks work is pending.
void CpAdvanceGuestPublication(uint32_t windowsCompleted) {
  if (windowsCompleted == 0) {
    return;
  }
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
  std::lock_guard<std::mutex> lock(g_pubMutex);
  ForEachDevice([&](uint32_t dev) {
    uint32_t subctx = 0;
    if (!mem.ReadU32BE(dev + 10896, &subctx) || subctx == 0) {
      return;
    }
    uint32_t put = 0;
    (void)mem.ReadU32BE(dev + 10908, &put);
    GuestPub *st = nullptr;
    for (auto &s : g_pubStates) {
      if (s.dev == dev) {
        st = &s;
        break;
      }
    }
    if (st == nullptr) {
      uint32_t seed = 0;
      (void)mem.ReadU32BE(subctx, &seed);
      g_pubStates.push_back({dev, seed});
      st = &g_pubStates.back();
    }
    uint32_t next = st->count + 2u * windowsCompleted;
    if (next < st->count || next > put) next = put;  // overflow guard
    if (next != st->count) {
      const uint32_t prev = st->count;
      st->count = next;
      (void)mem.WriteU32BE(subctx + 0, next);
      static std::atomic<uint32_t> s_pubLog{0};
      const uint32_t n = s_pubLog.fetch_add(1) + 1;
      if (n <= 24 || (n % 500) == 0) {
        MCLA_LOG_INFO("CP: GUEST-PUB #{} dev={:08X} pub {}->{} put={}", n, dev,
                      prev, next, put);
      }
    }
  });
}

bool CpDeferredConsumeEnabled() { return DeferredConsumeEnabled(); }

void CpDeferredSnapshot(uint32_t *producedEnd, uint32_t *consumedEnd,
                        uint32_t *outstandingDwords, uint32_t *pendingWindows) {
  uint32_t outstanding = 0;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    for (const auto &w : g_pendingWindows) {
      outstanding += w.dwords;
    }
    if (pendingWindows) {
      *pendingWindows = static_cast<uint32_t>(g_pendingWindows.size());
    }
  }
  if (producedEnd)
    *producedEnd = g_producedEnd.load(std::memory_order_relaxed);
  if (consumedEnd)
    *consumedEnd = g_consumedEnd.load(std::memory_order_relaxed);
  if (outstandingDwords)
    *outstandingDwords = outstanding;
}

uint32_t CpScbToken() { return g_scbToken.load(std::memory_order_relaxed); }

uint32_t CpGpuIdentifierAddress() {
  return g_gpuIdAddr.load(std::memory_order_relaxed);
}

void CpRegisterGpuIdentifierAddress(uint32_t addr) {
  g_gpuIdAddr.store(addr, std::memory_order_relaxed);
}

void CpInitializeRingBuffer(uint32_t physAddr, uint32_t sizeLog2) {
  // Phase-6 diagnostic: ring capacity derives from 1u<<(sizeLog2+3) bytes;
  // log2 values >= 29 would overflow the dword math. Observed guests pass
  // 12..19. Diagnose and refuse - never guess a capacity.
  if (sizeLog2 > 28) {
    MCLA_LOG_ERROR("CP: VdInitializeRingBuffer base={:08X} sizeLog2={} "
                   "out of range (>28) - REJECTED",
                   physAddr, sizeLog2);
    return;
  }

  const uint32_t sizeBytes = 1u << (sizeLog2 + 3); // log2 of quadwords
  const uint32_t capDwords = sizeBytes >> 2;

  std::lock_guard<std::mutex> lock(g_ringMutex);

  RingState *ring = nullptr;
  int slot = FindRingSlotLocked(physAddr, capDwords);
  if (slot < 0) {
    // NEW RING: claim a free slot.
    for (size_t i = 0; i < kMaxRings; ++i) {
      if (!g_rings[i].initialized.load(std::memory_order_acquire)) {
        slot = static_cast<int>(i);
        break;
      }
    }
    if (slot < 0) {
      MCLA_LOG_ERROR("CP: ring registry full - VdInitializeRingBuffer "
                     "base={:08X} cap={} REJECTED",
                     physAddr, capDwords);
      return;
    }
    ring = &g_rings[slot];
    ring->baseGuestVA = physAddr;
    ring->capDwords = capDwords;
    ring->id = static_cast<char>('A' + g_nextRingId.fetch_add(1) % 26);
    ring->rptrIndex.store(0, std::memory_order_relaxed);
    ring->lastDoorbellWptr.store(0xFFFFFFFFu, std::memory_order_relaxed);
    ring->writebackVA.store(0, std::memory_order_relaxed);
    ring->writebackRaw.store(0, std::memory_order_relaxed);
    ring->writebackEnabled.store(false, std::memory_order_relaxed);
    ring->initialized.store(true, std::memory_order_release);

    // Phase-6: overlapping ring identities (same body, different key).
    for (auto &other : g_rings) {
      if (&other == ring || !other.initialized.load(std::memory_order_acquire))
        continue;
      const bool overlap =
          physAddr < other.EndByte() && other.baseGuestVA < ring->EndByte();
      if (overlap) {
        MCLA_LOG_WARN("CP: RING {} [{:08X},{:08X}) overlaps RING {} "
                      "[{:08X},{:08X}) - guest re-used ring memory with "
                      "a different identity",
                      ring->id, ring->baseGuestVA, ring->EndByte(), other.id,
                      other.baseGuestVA, other.EndByte());
      }
    }

    // New registration becomes the doorbell target (HW: one primary ring,
    // reprogramming it switches the CP over).
    g_primarySlot.store(static_cast<uint32_t>(slot), std::memory_order_release);
    MCLA_LOG_INFO("CP: RING {} NEW base={:08X} cap={} dwords", ring->id,
                  physAddr, capDwords);
  } else {
    // REINITIALIZATION OF AN EXISTING RING. Do not blindly reset an
    // active ring: preserve rptr when work is pending (doorbell wptr not
    // fully consumed); reset only when the ring is quiescent.
    ring = &g_rings[slot];
    const uint32_t rptr = ring->rptrIndex.load(std::memory_order_acquire);
    const uint32_t lastWptr =
        ring->lastDoorbellWptr.load(std::memory_order_acquire);
    const bool quiescent = lastWptr == 0xFFFFFFFFu || rptr == lastWptr;
    g_primarySlot.store(static_cast<uint32_t>(slot), std::memory_order_release);
    if (quiescent) {
      ring->rptrIndex.store(0, std::memory_order_relaxed);
      ring->lastDoorbellWptr.store(0xFFFFFFFFu, std::memory_order_relaxed);
      // w18 CENSUS: guest put (gpuCtx+10908) vs writeback after idle REINIT.
      // If put > 0 the guest still waits on rptrWB >= put; writeback 0 after
      // a rptr reset parks that wait forever (primaryWptr=FFFFFFFF stall).
      uint32_t gpuCtx = 0, guestPut = 0, wbVa = ring->writebackVA.load();
      auto &memR = mcla::kernel::GuestMemoryHeap::Instance();
      (void)memR.ReadU32BE(0x82839254u, &gpuCtx);
      if (gpuCtx != 0)
        (void)memR.ReadU32BE(gpuCtx + 10908u, &guestPut);
      MCLA_LOG_INFO("CP: RING {} REINIT (idle) base={:08X} cap={} - rptr "
                    "reset lastRptr={:04X} lastWptr={:08X} guestPut={} "
                    "wb={:08X}",
                    ring->id, physAddr, capDwords, rptr, lastWptr, guestPut,
                    wbVa);
      // FAITHFUL FIX: if the guest already credited GPU progress (put>0)
      // before the reinit, publish that watermark to the writeback VA so
      // sub_82411218's rptrWB poll can exit. New submissions start from
      // rptr=0; the put cursor is the guest's own count of completed windows.
      if (guestPut != 0 && wbVa != 0) {
        (void)memR.WriteU32BE(wbVa, guestPut);
        MCLA_LOG_WARN("CP: RING {} REINIT writeback {:08X} 0 -> guestPut "
                      "{} (unpark KWFSO rptrWB poll)",
                      ring->id, wbVa, guestPut);
      }
    } else {
      // Phase-5/6: re-init of an ACTIVE ring - retain its state.
      MCLA_LOG_WARN("CP: RING {} REINIT while ACTIVE base={:08X} cap={} "
                    "rptr={} pendingWptr={} - state RETAINED",
                    ring->id, physAddr, capDwords, rptr, lastWptr);
    }
  }
}

void CpEnableRPtrWriteBack(uint32_t rptrWritebackAddr, uint32_t blockSizeLog2) {
  (void)
      blockSizeLog2; // update frequency - not honored yet (matches xenia TODO)

  std::lock_guard<std::mutex> lock(g_ringMutex);
  RingState *ring = PrimaryRing();
  if (!ring) {
    // Phase-6: WB referencing a ring without RingState.
    MCLA_LOG_WARN("CP: rptr writeback {:08X} arrived before any ring init",
                  rptrWritebackAddr);
    return;
  }

  // The genuine guest call site passes PHYS(subctx+60) (< 0x20001000).
  // Guest waiters poll the same word through its kernel-VA alias, which is
  // where our flat guest-memory view lives - publish to the VA form and
  // keep the raw value for diagnostics.
  const uint32_t vaForm = PhysToKernelVA(rptrWritebackAddr);
  ring->writebackRaw.store(rptrWritebackAddr, std::memory_order_relaxed);
  ring->writebackVA.store(vaForm, std::memory_order_relaxed);
  ring->writebackEnabled.store(true, std::memory_order_release);
  g_primarySlot.store(FindRingSlotLocked(ring->baseGuestVA, ring->capDwords),
                      std::memory_order_release);

  WarnWritebackOverlap(*ring);

  if (vaForm != 0) {
    // w18: after an idle REINIT the guest may still hold put>0 from the
    // prior phase. Publishing 0 leaves the rptrWB poll parked; publish the
    // guest put watermark when it is ahead of 0 so the wait can complete.
    uint32_t guestPut = 0, gpuCtx = 0;
    auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
    (void)memP.ReadU32BE(0x82839254u, &gpuCtx);
    if (gpuCtx != 0)
      (void)memP.ReadU32BE(gpuCtx + 10908u, &guestPut);
    const uint32_t publish = guestPut ? guestPut : 0u;
    (void)memP.WriteU32BE(vaForm, publish);
    if (publish != 0) {
      MCLA_LOG_WARN("CP: RING {} rptr writeback @ {:08X} publish={} "
                    "(guest put; unpark after reinit)",
                    ring->id, vaForm, publish);
    }
  }
  if (vaForm != rptrWritebackAddr) {
    MCLA_LOG_INFO("CP: RING {} rptr writeback raw={:08X} (phys) -> publish @ "
                  "{:08X} (kernel VA)",
                  ring->id, rptrWritebackAddr, vaForm);
  } else {
    MCLA_LOG_INFO("CP: RING {} rptr writeback @ {:08X}", ring->id, vaForm);
  }
}

uint32_t CpPrimaryWritebackVA() {
  const uint32_t slot = g_primarySlot.load(std::memory_order_acquire);
  if (slot >= kMaxRings) {
    return 0;
  }
  const RingState &r = g_rings[slot];
  if (!r.writebackEnabled.load(std::memory_order_acquire)) {
    return 0;
  }
  return r.writebackVA.load(std::memory_order_relaxed);
}

void CpAttachDriverCtx(uint32_t devVA) {
  if (devVA == 0) {
    return;
  }
  for (auto &slot : g_devices) {
    if (slot.load(std::memory_order_relaxed) == devVA) {
      return; // already registered
    }
  }
  for (auto &slot : g_devices) {
    uint32_t expected = 0;
    if (slot.compare_exchange_strong(expected, devVA,
                                     std::memory_order_relaxed)) {
      const uint32_t n = s_attachedCount.fetch_add(1) + 1;
      MCLA_LOG_INFO("CP: attached GuestDevice {:08X} ({}/{})", devVA, n,
                    kMaxDevices);
      if (n == kMaxDevices) {
        MCLA_LOG_WARN("CP: device registry full - further devices untracked");
      }
      return;
    }
  }
}

void CpConsumePushWindow(uint32_t endVA, uint32_t dwords) {
  if (DeferredConsumeEnabled()) {
    // Experiment: record the submitted range; do NOT credit consumption.
    // The vblank-paced consumer credits it once the driver's production
    // cursor (PrimaryRing lastDoorbellWptr) actually covers the range.
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    const uint32_t prevEnd = g_producedEnd.load(std::memory_order_relaxed);
    if (endVA > prevEnd) {
      if (g_pendingWindows.size() >= 4096) {
        g_pendingWindows.erase(g_pendingWindows.begin());
      }
      g_pendingWindows.push_back({prevEnd, endVA, dwords});
      g_producedEnd.store(endVA, std::memory_order_relaxed);
      // Bound sanity: production between vblanks is frame-sized; a
      // pathological pile-up means the consumer is not running.
      if (g_pendingWindows.size() > 4096) {
        static std::atomic<bool> warned{false};
        if (!warned.exchange(true)) {
          MCLA_LOG_WARN("CP: DEFER pending windows > 4096 - consumer "
                        "not draining?");
        }
      }
    }
    return;
  }

  // Monotonic: windows may be captured slightly out of order.
  uint32_t prev = g_pushWatermark.load(std::memory_order_relaxed);
  while (endVA > prev && !g_pushWatermark.compare_exchange_weak(
                             prev, endVA, std::memory_order_relaxed)) {
  }

  if (dwords == 0)
    return;
  // One captured window = one completed push-buffer window for the guest
  // publication contract (eager mode credits at capture).
  CpAdvanceGuestPublication(1);
  if (PPCContext *ctx = GetPPCContext()) {
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    const uint32_t tls = ctx->r13.u32;
    uint32_t blk = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &blk) && blk != 0) {
      uint32_t cur = 0;
      if (mem.ReadU32BE(blk + 88, &cur)) {
        (void)mem.WriteU32BE(blk + 88, cur + dwords);
      }
    }
  }
}

// VBLANK-PACED CONSUMER (deferred-consumption experiment). Credits only
// ranges the driver has actually produced (via PrimaryRing lastDoorbellWptr),
// then publishes the consumed watermark and advances progress by EXACTLY
// those dwords - never a forced amount. Runs once per vblank from
// CpVblankDrainToWptr; no-op unless the experiment flag is on.
void ConsumePendingAtVblank() {
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  RingState *ring = PrimaryRing();
  if (!ring) {
    return;
  }
  const uint32_t wptrIdx =
      ring->lastDoorbellWptr.load(std::memory_order_relaxed);
  if (wptrIdx == 0xFFFFFFFFu) {
    return;
  }
  // Convert dword wptr index to byte VA in the ring's address space.
  const uint32_t producedVA =
      ring->baseGuestVA + wptrIdx * 4u;

  std::vector<PendingConsume> ready;
  {
    std::lock_guard<std::mutex> lock(g_pendingMutex);
    size_t count = 0;
    while (count < g_pendingWindows.size() &&
           g_pendingWindows[count].endVA <= producedVA) {
      ready.push_back(g_pendingWindows[count]);
      count++;
    }
    g_pendingWindows.erase(g_pendingWindows.begin(),
                           g_pendingWindows.begin() + count);
  }
  if (ready.empty()) {
    return;
  }

  uint32_t credited = 0, lastEnd = 0;
  for (const auto &w : ready) {
    credited += w.dwords;
    lastEnd = w.endVA;
  }

  // Guest-visible consumed watermark (monotonic advance only).
  uint32_t prevMark = g_pushWatermark.load(std::memory_order_relaxed);
  while (lastEnd > prevMark &&
         !g_pushWatermark.compare_exchange_weak(prevMark, lastEnd,
                                                std::memory_order_relaxed)) {
  }
  g_consumedEnd.store(lastEnd, std::memory_order_relaxed);
  ScbNoteConsumption();
  CpAdvanceGuestPublication(static_cast<uint32_t>(ready.size()));

  // Progress attribution: same block the eager path credited. All
  // synthesized threads share the boot-host r13 page, so the live vsync
  // context and the cached submitter block resolve to the same field.
  uint32_t blk = 0;
  if (const PPCContext *c = GetPPCContext()) {
    const uint32_t tls = c->r13.u32;
    uint32_t b = 0;
    if (tls != 0 && mem.ReadU32BE(tls + 256, &b)) {
      blk = b;
    }
  }
  if (blk == 0) {
    blk = g_progressBlk.load(std::memory_order_relaxed);
  }
  uint32_t pcBefore = 0;
  if (blk != 0) {
    uint32_t cur = 0;
    if (mem.ReadU32BE(blk + 88, &cur)) {
      pcBefore = cur;
      AccumProgress(credited);
    }
  }

  static std::atomic<uint32_t> s_deferCount{0};
  const uint32_t n = s_deferCount.fetch_add(1) + 1;
  uint32_t outstandingNow = 0, pendN = 0;
  CpDeferredSnapshot(nullptr, nullptr, &outstandingNow, &pendN);
  if (n <= 24 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: DEFER-CONSUME #{} produced={:08X} consumed->{:08X} "
                  "windows={} credited={} outstanding={} pendN={} "
                  "pc {}->{}",
                  n, producedVA, lastEnd, ready.size(), credited,
                  outstandingNow, pendN, pcBefore, pcBefore + credited);
  }
}

// VDRAIN CENSUS (2026-08-31 session 35): the hot WAIT census shows pc=0
// forever while this function produces no VDRAIN lines at all - meaning it
// exits early on some branch, but every early-exit here is silent. Count each
// reason and surface the ring registry state; log-only, no behavior change.
static std::atomic<uint32_t> s_vdInvocations{0};
static std::atomic<uint32_t> s_vdNoCtx{0};
static std::atomic<uint32_t> s_vdNoCtx30{0};
static std::atomic<uint32_t> s_vdNoRing{0};
static std::atomic<uint32_t> s_vdSameWptr{0};
static std::atomic<uint32_t> s_vdBusy{0};
static std::atomic<uint32_t> s_vdRejected{0};

void CpVblankDrainToWptr() {
  const uint32_t vdN = s_vdInvocations.fetch_add(1) + 1;
  if (vdN <= 16 || (vdN % 500) == 0) {
    auto &memC = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t gpuCtxC = 0, ctx30Val = 0;
    (void)memC.ReadU32BE(0x82839254u, &gpuCtxC);
    if (gpuCtxC != 0) {
      (void)memC.ReadU32BE(gpuCtxC + 0x30u, &ctx30Val);
    }
    RingState *pring = PrimaryRing();
    const uint32_t primaryWptr =
        pring ? pring->lastDoorbellWptr.load(std::memory_order_relaxed)
              : 0xFFFFFFFFu;
    std::string ringDump;
    {
      std::lock_guard<std::mutex> dumpLock(g_ringMutex);
      for (size_t i = 0; i < kMaxRings; ++i) {
        const RingState &r = g_rings[i];
        if (!r.initialized.load(std::memory_order_acquire))
          continue;
        ringDump += fmt::format(
            " {}[base={:08X} cap={} rptr={:04X} db={:08X} wb={:08X}]", r.id,
            r.baseGuestVA, r.capDwords,
            r.rptrIndex.load(std::memory_order_relaxed),
            r.lastDoorbellWptr.load(std::memory_order_relaxed),
            r.writebackVA.load(std::memory_order_relaxed));
      }
    }
    MCLA_LOG_INFO("CP: VDRAIN-CENSUS #{} def={} gpuCtx={:08X} ctx+30={:08X} "
                  "primaryWptr={:08X} "
                  "doorbells={} drains={} swaps={} exits[noCtx={} noCtx30={} "
                  "noRing={} sameWptr={} busy={} rejected={}]{}",
                  vdN, DeferredConsumeEnabled() ? 1 : 0, gpuCtxC, ctx30Val,
                  primaryWptr,
                  g_doorbellCount.load(std::memory_order_relaxed),
                  g_drainCount.load(std::memory_order_relaxed),
                  g_swapCount.load(std::memory_order_relaxed),
                  s_vdNoCtx.load(std::memory_order_relaxed),
                  s_vdNoCtx30.load(std::memory_order_relaxed),
                  s_vdNoRing.load(std::memory_order_relaxed),
                  s_vdSameWptr.load(std::memory_order_relaxed),
                  s_vdBusy.load(std::memory_order_relaxed),
                  s_vdRejected.load(std::memory_order_relaxed), ringDump);
    // Session 75m: gate-flag probe. dword_828309A0 gates the DLC/streamables
    // predicate at 0x821342F8 - not a function entry in the current decode, it
    // sits inside sub_821342B8 (== "flag != 0 && device-poll >= 2"); the whole
    // streamables path never activates, so watch it + neighbors.
    if ((vdN % 100) == 1) {
      uint32_t flag = 0, g1 = 0, g2 = 0, g3 = 0, ioCredits = 0;
      auto &memP = mcla::kernel::GuestMemoryHeap::Instance();
      memP.ReadU32BE(0x828309A0u, &flag);
      memP.ReadU32BE(0x8283099Cu, &g1);
      memP.ReadU32BE(0x828309A4u, &g2);
      memP.ReadU32BE(0x828309A8u, &g3);
      memP.ReadU32BE(0x827D74E0u, &ioCredits);
      MCLA_LOG_INFO("GATE-PROBE #{:04X} [828309A0]={:08X} [A4]={:08X} "
                    "[A8]={:08X} [9C]={:08X} IOCREDITS[827D74E0]={:08X}",
                    vdN, flag, g2, g3, g1, ioCredits);
      // Session 75q: dump the first join-table entries — entry+8 is the
      // stream object whose vtable+28 read returns 0 for batch-2 streams.
      uint32_t jcount = 0, jentries = 0;
      memP.ReadU32BE(0x8283D1A8u, &jcount);
      memP.ReadU32BE(0x8283D1C4u, &jentries);
      if (jentries != 0 && jcount != 0) {
        for (uint32_t ji = 0; ji < 6 && ji < jcount; ++ji) {
          uint32_t eBase = jentries + ji * 28u;
          uint32_t key = 0, obj = 0, busy = 0, vt = 0, rd = 0;
          memP.ReadU32BE(eBase + 0, &key);
          memP.ReadU32BE(eBase + 8, &obj);
          memP.ReadU32BE(eBase + 12, &busy);
          if (obj != 0) {
            memP.ReadU32BE(obj, &vt);
            if (vt != 0) memP.ReadU32BE(vt + 28, &rd);
          }
          MCLA_LOG_INFO("JOIN[{}] @ {:08X} key={:08X} obj={:08X} busy={:08X} "
                        "vt={:08X} readFn={:08X}",
                        ji, eBase, key, obj, busy, vt, rd);
        }
      }
    }
  }
  // Deferred-consumption experiment: credit submitted-but-unconsumed
  // driver windows here, paced by vblank, before the ring-drain duty.
  if (DeferredConsumeEnabled()) {
    ConsumePendingAtVblank();

    // Drain the doorbell ring deferred from MMIO stores this frame.
    const uint32_t pendingW =
        g_pendingRingWptr.exchange(0xFFFFFFFFu, std::memory_order_acq_rel);
    if (pendingW != 0xFFFFFFFFu) {
      if (RingState *pring = PrimaryRing()) {
        if (!pring->draining.exchange(true)) {
          const uint32_t startR =
              pring->rptrIndex.load(std::memory_order_relaxed);
          DrainRing(*pring, pendingW, "vblank-deferred");
          const uint32_t endR =
              pring->rptrIndex.load(std::memory_order_relaxed);
          MCLA_LOG_INFO("CP: RING {} VDRAIN-DEFERRED rptr {:04X}->{:04X} "
                        "wptr={:04X} consumed={}",
                        pring->id, startR, endR, pendingW,
                        (endR - startR + pring->capDwords) % pring->capDwords);
          pring->draining.store(false, std::memory_order_release);
        }
      }
    }

    // Single batched publication point per vblank.
    FlushProgressAtVblank();
  }
  // Kernel-role vblank duty (2026-08-24, REWRITTEN 2026-09-08).
  //
  // ROOT CAUSE of 1492+ noRing exits: GPU_ctx+0x30 contains command buffer
  // pointers (ME/PFP init buffers, e.g. C601C4FC/C609C5E8/C601C5BC), NOT
  // ring buffer cursors. Those addresses fall OUTSIDE Ring A's window
  // (C600C500–C6014500), so RingOwningCursorVA always returned nullptr.
  // The REJECTED HYPOTHESIS comment (gpu_cp.cpp:375) confirmed this.
  //
  // On real HW the kernel CP reads the write pointer from the CP_RB_WPTR
  // register (doorbell MMIO 0x7FC80714). Our doorbell handler already
  // tracks this in PrimaryRing()->lastDoorbellWptr. Use that directly.
  //
  // Progress/publication are consequences of real consumption only:
  //  - PublishRptr (inside DrainRing) publishes the consumed watermark.
  //  - DrainRing's consumed-dword accounting advances XTEB+88 progress.
  auto &mem = mcla::kernel::GuestMemoryHeap::Instance();

  RingState *ring = PrimaryRing();
  if (!ring) {
    s_vdNoRing.fetch_add(1, std::memory_order_relaxed);
    return; // no ring registered yet
  }

  const uint32_t wptr =
      ring->lastDoorbellWptr.load(std::memory_order_relaxed);
  if (wptr == 0xFFFFFFFFu) {
    s_vdNoCtx30.fetch_add(1, std::memory_order_relaxed);
    return; // no doorbell has been rung yet
  }

  const uint32_t cap = ring->capDwords;
  const uint32_t oldRptr = ring->rptrIndex.load(std::memory_order_relaxed);
  if (wptr == oldRptr) {
    s_vdSameWptr.fetch_add(1, std::memory_order_relaxed);
    return; // nothing produced: zero consumption, zero publication
  }

  // Single-drain guard per ring: DrainRing was designed for the synchronous
  // submitter thread; a concurrent doorbell drain must not interleave.
  if (ring->draining.exchange(true)) {
    s_vdBusy.fetch_add(1, std::memory_order_relaxed);
    return;
  }

  uint32_t probeDev = 0, pubBefore = 0;
  ForEachDevice([&](uint32_t dev) {
    if (probeDev != 0)
      return;
    uint32_t subctx = 0;
    probeDev = dev;
    if (mem.ReadU32BE(dev + 10896, &subctx) && subctx != 0)
      (void)mem.ReadU32BE(subctx, &pubBefore);
  });

  const uint64_t drainsBefore = g_drainCount.load(std::memory_order_relaxed);
  DrainRing(*ring, wptr, "vblank");
  const bool ran = g_drainCount.load(std::memory_order_relaxed) != drainsBefore;
  if (!ran) {
    s_vdRejected.fetch_add(1, std::memory_order_relaxed);
    ring->draining.store(false, std::memory_order_release);
    return; // rejected/desync: nothing consumed, nothing published
  }

  const uint32_t newRptr = ring->rptrIndex.load(std::memory_order_relaxed);
  const uint32_t consumed = (newRptr - oldRptr + cap) % cap;

  // ADVANCE PUBLICATION: DrainRing processes ring data but does NOT call
  // CpAdvanceGuestPublication. The game's sub_82411E98 waits on
  // *(subctx+0) >= needed (consumed-window COUNT). During loading, the
  // capture path (sub_82411640 -> CpConsumePushWindow) may not run, so
  // pub freezes while put grows. Publish 1 window per drain cycle if any
  // data was consumed. CpAdvanceGuestPublication clamps to put, so
  // over-publishing is safe.
  if (consumed > 0) {
    CpAdvanceGuestPublication(1);
  }

  uint32_t pubAfter = 0;
  {
    uint32_t subctx = 0;
    if (probeDev != 0 && mem.ReadU32BE(probeDev + 10896, &subctx) &&
        subctx != 0)
      (void)mem.ReadU32BE(subctx, &pubAfter);
  }

  static std::atomic<uint32_t> s_vdrain{0};
  const uint32_t n = s_vdrain.fetch_add(1) + 1;
  if (n <= 24 || (n % 500) == 0) {
    MCLA_LOG_INFO("CP: VDRAIN #{} RING {} base={:08X} cap={} dev={:08X} "
                  "wptr={:04X} rptr {:04X}->{:04X} consumed={} "
                  "wb={:08X} pub {:X}->{}",
                  n, ring->id, ring->baseGuestVA, cap, probeDev, wptr,
                  oldRptr, newRptr, consumed,
                  ring->writebackVA.load(std::memory_order_relaxed), pubBefore,
                  pubAfter);
  }
  ring->draining.store(false, std::memory_order_release);
}

bool CpMmioWrite(uint32_t guestAddr, uint32_t value) {
  if ((guestAddr & kMmioMask) != kMmioBase) {
    return false;
  }

  const uint32_t offset = guestAddr - kMmioBase;
  if (offset == kWptrByteOffset) {
    // Log every doorbell including the sentinel: a silent sentinel store
    // vs a missing store are different failure modes.
    const uint64_t n = g_doorbellCount.fetch_add(1) + 1;

    // Phase-4 routing: the doorbell register carries only the wptr index
    // (HW has ONE primary ring). Drain THAT ring's state; never another
    // ring's base/cap/rptr/writeback.
    RingState *ring = PrimaryRing();
    const uint32_t rptrBefore =
        ring ? ring->rptrIndex.load(std::memory_order_relaxed) : 0;
    if (n <= 16 || (n % 500) == 0) {
      if (ring) {
        MCLA_LOG_INFO(
            "CP: doorbell RING {} base={:08X} cap={} wptr={:08X} (rptr={})",
            ring->id, ring->baseGuestVA, ring->capDwords, value, rptrBefore);
      } else {
        MCLA_LOG_WARN("CP: doorbell wptr={:08X} with NO registered ring",
                      value);
      }
    }
    if (value != kWptrSentinel) {
      // Deferred experiment: the doorbell only MARKS production on HW;
      // the CP fetches asynchronously. Record the target and let the
      // vblank consumer perform the actual drain + accounting.
      if (DeferredConsumeEnabled()) {
        uint32_t prevW = g_pendingRingWptr.load(std::memory_order_relaxed);
        while (prevW == 0xFFFFFFFFu || value > prevW) {
          if (g_pendingRingWptr.compare_exchange_weak(
                  prevW, value, std::memory_order_relaxed)) {
            break;
          }
        }
        const uint64_t n2 = g_doorbellCount.load(std::memory_order_relaxed);
        if (n2 <= 16) {
          MCLA_LOG_INFO("CP: DOORBELL-DEFER RING {} wptr={:04X} "
                        "(drain deferred to vblank)",
                        ring ? ring->id : '?', value);
        }
        return true;
      }
      // Bounded wait on the per-ring drain guard: losing this wptr
      // would stall the submitter until its NEXT doorbell.
      bool acquired = false;
      if (ring) {
        for (int spin = 0; spin < 64; ++spin) {
          if (!ring->draining.exchange(true)) {
            acquired = true;
            break;
          }
          std::this_thread::yield();
        }
        if (!acquired) {
          static std::atomic<bool> warnedBusy{false};
          if (!warnedBusy.exchange(true)) {
            MCLA_LOG_WARN("CP: RING {} drain guard held - doorbell "
                          "wptr={:08X} deferred to next submission",
                          ring->id, value);
          }
        }
      }
      if (ring && acquired) {
        const uint32_t startRptr =
            ring->rptrIndex.load(std::memory_order_relaxed);
        uint32_t callerLr = 0;
        if (const PPCContext *c = GetPPCContext())
          callerLr = static_cast<uint32_t>(c->lr);
        DrainRing(*ring, value, "doorbell");
        const uint32_t endRptr =
            ring->rptrIndex.load(std::memory_order_relaxed);
        const uint32_t consumed =
            (endRptr - startRptr + ring->capDwords) % ring->capDwords;
        // ADVANCE PUBLICATION: same as VSYNC drain path. The game's
        // sub_82411E98 waits on *(subctx+0) >= needed. Without this,
        // the doorbell drain processes ring data but pub never advances.
        if (consumed > 0) {
          CpAdvanceGuestPublication(1);
        }
        // Phase-4 trace: full per-ring drain record.
        if (n <= 16 || (n % 500) == 0) {
          MCLA_LOG_INFO("CP: RING {} DRAIN src=doorbell base={:08X} cap={} "
                        "rptr {:04X}->{:04X} wptr={:04X} consumed={} wb={:08X} "
                        "published={} lr={:08X}",
                        ring->id, ring->baseGuestVA, ring->capDwords, startRptr,
                        endRptr, value, consumed,
                        ring->writebackVA.load(std::memory_order_relaxed),
                        consumed != 0, callerLr);
        }
        ring->draining.store(false, std::memory_order_release);
      } else if (!ring) {
        static std::atomic<bool> warnedNoRing{false};
        if (!warnedNoRing.exchange(true)) {
          MCLA_LOG_WARN("CP: doorbell dropped - no RingState yet "
                        "(wptr={:08X})",
                        value);
        }
      }
    }
    return true;
  }

  // Xenia persists every register write in its register file and serves
  // later reads from it (GraphicsSystem::WriteRegister,
  // graphics_system.cc:207-223). Mirroring that: store into the shadow so
  // guest read-back sees what it wrote (interrupt-enable bits included).
  const uint32_t regIndex = offset >> 2;
  if (regIndex < kMmioRegCount) {
    g_regShadow[regIndex].store(value, std::memory_order_relaxed);
  }

  // First-touch-per-register logging (low regs index < 32 are tracked by
  // bitmask and log once each; higher indices have no bit to set, so they log
  // the first store and then 1 per 200 - not every store).
  static std::atomic<uint32_t> regSeenMask{0};
  const uint32_t bit = regIndex < 32 ? (1u << regIndex) : 0;
  if (!bit || !(regSeenMask.fetch_or(bit) & bit)) {
    static std::atomic<uint32_t> highRegLogCount{0};
    if (bit || (highRegLogCount.fetch_add(1) % 200) == 0) {
      MCLA_LOG_INFO("CP: MMIO write reg={:04X} offset={:04X} value={:08X}",
                    regIndex, offset, value);
    }
  }
  return true;
}

bool CpMmioRead(uint32_t guestAddr, uint32_t *outValue) {
  if ((guestAddr & kMmioMask) != kMmioBase) {
    return false;
  }

  const uint32_t offset = guestAddr - kMmioBase;
  const uint32_t regIndex = offset >> 2;

  // Per-register first-read logging for EVERY read (hardcoded + shadow):
  // the old warn-once-global flag hid all poll addresses after the first.
  {
    static std::atomic<uint32_t> slotReg[16]{};
    static std::atomic<uint32_t> slotBusy[16]{};
    const uint32_t slot = regIndex % 16;
    uint32_t expected = 0;
    bool wasEmpty = slotBusy[slot].load(std::memory_order_relaxed) == 0;
    if (wasEmpty && slotBusy[slot].compare_exchange_strong(
                        expected, 1u, std::memory_order_relaxed)) {
      slotReg[slot].store(regIndex, std::memory_order_relaxed);
      MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (first touch)",
                    regIndex, offset);
    } else if (!wasEmpty &&
               slotReg[slot].load(std::memory_order_relaxed) != regIndex) {
      // Slot occupied by another reg: rotate once per 500 distinct-ish
      // events so rare regs still surface without spamming hot polls.
      static std::atomic<uint32_t> rotateCounter{0};
      if ((rotateCounter.fetch_add(1, std::memory_order_relaxed) % 500) == 0) {
        slotReg[slot].store(regIndex, std::memory_order_relaxed);
        MCLA_LOG_WARN("CP: MMIO read reg={:04X} offset={:04X} (rotate)",
                      regIndex, offset);
      }
    }
  }

  // Hardcoded status reads, mirroring xenia GraphicsSystem::ReadRegister
  // (graphics_system.cc:184-201) - values verbatim from that switch.
  // Reg 0x1951 bit0 = vblank pending - the game's own vsync ISR gates its
  // flip-request processor on exactly this word
  // ([0x7FC80000+0x6544]&1, ppc_recomp.75.cpp:14151-14156 inside sub_82411478,
  // the VSync callback registered by imports.cpp); answering 0
  // starves the present path.
  switch (regIndex) {
  case 0x0F00: // RB_EDRAM_TIMING (graphics_system.cc:186)
    *outValue = 0x08100748u;
    return true;
  case 0x0F01: // RB_BC_CONTROL (graphics_system.cc:188)
    *outValue = 0x0000200Eu;
    return true;
  case 0x194C: // R500_D1MODE_V_COUNTER (graphics_system.cc:189-190)
    *outValue = 0x000002D0u;
    return true;
  case 0x1951: // interrupt status: vblank pending (graphics_system.cc:191-192)
    *outValue = 1u;
    return true;
  case 0x1961: // AVIVO_D1MODE_VIEWPORT_SIZE 1280x720
               // (graphics_system.cc:193-196)
    *outValue = 0x050002D0u;
    return true;
  default:
    break;
  }

  // Everything else: last written value (xenia register-file fallback,
  // graphics_system.cc:204 register_file_.values[r] return), 0 when never
  // written.
  if (regIndex < kMmioRegCount) {
    *outValue = g_regShadow[regIndex].load(std::memory_order_relaxed);
  } else {
    *outValue = 0;
  }
  return true;
}

uint64_t CpSwapCount() { return g_swapCount.load(std::memory_order_relaxed); }
uint64_t CpDrainCount() { return g_drainCount.load(std::memory_order_relaxed); }

// PAGE-WATCH (session 24): attribution probes for the async-task work buffer
// at guest 0x50000000 - called from GuestMemoryView checked accessors.
// F-375: F-374's guard page caught 16+ consecutive dwords written starting at guest 0x20000 --
// which is where the HOST keeps its user-heap o1heap instance (src/kernel/heap.cpp:247
// `Heap::Init` binds the arena at kUserHeapArenaVa).
// F-375 read the writer as the guest's own memcpy (recompiled sub_823DA950); F-383/F-384 retired
// that reading as a nearest-preceding-PUBLIC artifact and resolved the burst to the title's own
// allocator sub_82397060 filling 16-byte free-list entries at our arena base. Either way it is the
// writer behind F-370's dead allocator and uncreated thread #16. What the guard cannot say is the
// argument set: r3=dst, r4=src, r5=len, i.e. whether 0x20000 arrived as a destination from a
// caller whose buffer-pointer field actually holds a size. Read-only, own counter, capped at 8
// (the burst is 16 dwords).
void HeapInstanceStoreReport(uint32_t guestAddr, uint32_t value) {
  static std::atomic<uint32_t> s_hi{0};
  const uint32_t n = s_hi.fetch_add(1) + 1;
  if (n > 8) return;
  uint32_t lr = 0, sp = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r13 = 0;
  if (const PPCContext *c = GetPPCContext()) {
    lr = static_cast<uint32_t>(c->lr);
    sp = c->r1.u32;
    r3 = c->r3.u32;
    r4 = c->r4.u32;
    r5 = c->r5.u32;
    r6 = c->r6.u32;
    r7 = c->r7.u32;
    r13 = c->r13.u32;
  }
  MCLA_LOG_ERROR("F375-HEAPSTORE #{} guest={:08X} val={:08X} lr={:08X} sp={:08X} r3={:08X} "
                 "r4={:08X} r5={:08X} r6={:08X} r7={:08X} r13={:08X}",
                 n, guestAddr, value, lr, sp, r3, r4, r5, r6, r7, r13);
  if (n == 1 && r13 != 0) {
    // F-389 (T41.67): the writer's allocator is resolved by the XTL thunk `sub_82130528` as
    //     lwz r11,0(r13) / li r10,28 / lwzx r3,r10,r11 / lwz r9,0(r3) / lwz r8,8(r9) / bctr
    // -- object = [[r13]+28], method = [object+8], and `li r5,16` there is the 16-byte entry stride
    // the F374 rows show. Print both dereferences so the supplier of the base is named at the event
    // instead of inferred from the disassembly.
    auto &gt = mcla::kernel::GuestMemoryHeap::Instance();
    uint32_t vec = 0, obj = 0, meth = 0, fn = 0;
    (void)gt.ReadU32BE(r13, &vec);
    if (vec != 0 && vec != 0xCDCDCDCDu) {
      (void)gt.ReadU32BE(vec + 28u, &obj);
      if (obj != 0 && obj != 0xCDCDCDCDu) {
        (void)gt.ReadU32BE(obj, &meth);
        if (meth != 0 && meth != 0xCDCDCDCDu)
          (void)gt.ReadU32BE(meth + 8u, &fn);
      }
    }
    MCLA_LOG_ERROR(
        "F389-XTLCHAIN r13={:08X} [r13]={:08X} obj=[[r13]+28]={:08X} vt=[obj]={:08X} "
        "allocFn=[vt+8]={:08X}",
        r13, vec, obj, meth, fn);
    // F-389b: `sub_821C08F8` is only a dispatcher -- `addi r11,r6,1 / rlwinm r10,r11,*4 /
    // lwzx r3,r10,r3 / lwz r9,0(r3) / lwz r8,8(r9) / bctr`, i.e. the real allocator object is
    // `[bank + (r6+1)*4]` and its method is `[obj+8]` (the existing 76j census documents r6=0 -> the
    // dual-buddy bank). Dump that object's head so the region it allocates FROM is readable at the
    // event: if its base is guest 0x20000 it is OUR user-heap arena, which is the last link T41.67
    // needs. r6 is unknown at store time, so index 1 (`(0+1)*4`) is the one printed.
    uint32_t bank = obj, a1 = 0, vt1 = 0, fn1 = 0, w[8] = {0};
    if (bank != 0 && bank != 0xCDCDCDCDu) {
      (void)gt.ReadU32BE(bank + 4u, &a1);
      if (a1 != 0 && a1 != 0xCDCDCDCDu) {
        (void)gt.ReadU32BE(a1, &vt1);
        if (vt1 != 0 && vt1 != 0xCDCDCDCDu)
          (void)gt.ReadU32BE(vt1 + 8u, &fn1);
        for (uint32_t i = 0; i < 8; ++i)
          (void)gt.ReadU32BE(a1 + i * 4u, &w[i]);
      }
    }
    MCLA_LOG_ERROR("F389-BANK bank={:08X} alloc=[bank+4]={:08X} vt={:08X} fn={:08X} "
                   "head=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                   bank, a1, vt1, fn1, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7]);
  }
  if (n == 1) {
    // F-379: ctx->lr names only the innermost return address, and the guest stack above sp is empty
    // (F-378: every word but the back-chain read 00000000), so the caller chain has to come from the
    // host side. Every recompiled guest function is a PUBLIC __imp__sub_X in the link map, so a host
    // return address resolves offline to the guest function that owns it:
    //     python tools/host_rva_resolve.py build/mcla.map <rva> <rva> ...
    void *frames[20] = {};
    const WORD nf = RtlCaptureStackBackTrace(0, 20, frames, nullptr);
    const uintptr_t mb = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    for (WORD i = 0; i < nf; ++i) {
      const uintptr_t f = reinterpret_cast<uintptr_t>(frames[i]);
      const uintptr_t rva = mb ? f - mb : f;
      const bool inModule = mb && f >= mb && f < mb + 0x08000000u;
      MCLA_LOG_ERROR("F379-HEAPSTORE-BT frame={}/{} rva={:x} inmod={}", static_cast<int>(i),
                     static_cast<int>(nf), static_cast<unsigned long long>(rva),
                     inModule ? 1 : 0);
    }

    // F-383: F-382 settled the question the symbol lookup could not. The guest memcpy WAS hooked and
    // its live-entry control fired (F382-MEMCPY-LIVE calls=1), yet not one memcpy in the whole boot
    // had a destination inside 0x10000..0x30000 -- so "the writer is the recompiled sub_823DA950" was
    // an artifact of nearest-preceding PUBLIC symbol resolution (no PDB here, so generated statics are
    // invisible to the map). The unwind table is complete without symbols, so ask it directly: the
    // containing function's real start, resolved offline with
    //     python tools/host_rva_resolve.py build/mcla.map <owner_rva>
    if (nf > 3) {
      DWORD64 ib = 0;
      const uintptr_t f3 = reinterpret_cast<uintptr_t>(frames[3]);
      const uintptr_t mb3 = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
      const PRUNTIME_FUNCTION rf = RtlLookupFunctionEntry((DWORD64)f3, &ib, nullptr);
      MCLA_LOG_ERROR("F383-WRITEROWNER frame3={:x} owner={:x} off={:x} have={}",
                     static_cast<unsigned long long>(mb3 ? f3 - mb3 : f3),
                     static_cast<unsigned long long>(rf && ib ? (mb3 ? ib + rf->BeginAddress - mb3
                                                                      : ib + rf->BeginAddress)
                                                              : 0),
                     static_cast<unsigned long long>(rf ? f3 - (ib + rf->BeginAddress) : 0),
                     rf ? 1 : 0);
    }

    // F-381: F-379's host backtrace put this burst inside OUR OWN Path A driver
    // (MclaJob2DecompressAndDistribute -> MclaXcDecodeFullStream -> guest sub_8244FF20 ->
    // sub_82460420 -> sub_82461010 -> guest memcpy sub_823DA950), and F-380 showed the xmem state the
    // decoder uses was zeroed by our warm-context soft-reset immediately before. sub_82461010 forms
    // its copy destination as   lwz r27,12276(r31) / lwz r29,12280(r31) / add r3,r29,r27 / bl memcpy
    // -- base pointer + cursor. If our reset wiped the BASE, dst degenerates to 0 + cursor, and the
    // first watched address above that null-based block is exactly 0x20000. Read the state back at
    // the store: [12276]==0 with [12280]==0x20000 proves it, and the low-VA sample shows whether the
    // bytes also landed at 0x0.. (unwatched until now). ctx is the value F380-XCRESET printed in this
    // same boot; the head check keeps a wrong constant from being read as a result.
    static constexpr uint32_t kXcCtx = 0x4000FD80u;
    {
      auto &gm = mcla::kernel::GuestMemoryHeap::Instance();
      uint32_t c4 = 0, c8 = 0;
      (void)gm.ReadU32BE(kXcCtx + 4u, &c4);
      (void)gm.ReadU32BE(kXcCtx + 8u, &c8);
      uint32_t st[11] = {0};
      for (uint32_t i = 0; i < 11; ++i)
        (void)gm.ReadU32BE(kXcCtx + 20u + 12264u + i * 4u, &st[i]);
      MCLA_LOG_ERROR("F381-XCSTATE ctx={:08X} c4={:08X} c8={:08X} st=[{:08X} {:08X} {:08X} {:08X} "
                     "{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                     kXcCtx, c4, c8, st[0], st[1], st[2], st[3], st[4], st[5], st[6], st[7], st[8],
                     st[9], st[10]);
      uint32_t low[8] = {0};
      for (uint32_t i = 0; i < 8; ++i)
        (void)gm.ReadU32BE(i * 4u, &low[i]);
      MCLA_LOG_ERROR("F381-LOWVA head=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} {:08X}]",
                     low[0], low[1], low[2], low[3], low[4], low[5], low[6], low[7]);
    }

    // F-378: the destination is arena-RELATIVE (F-377: move the arena, the writes follow), so the
    // question is not "which constant" but "whose frame computed it". The burst happens inside the
    // guest's own memcpy, so the interesting callers are only reachable through the saved link
    // registers on the guest stack -- dump them once, classified. A word is called "code" only if
    // it lies in the loaded image range (0x82000000..0x82800000); everything else is printed as a
    // raw value, because that is the one thing that could make an arena-relative 0x20000 visible.
    static constexpr uint32_t kRecBase = 0x8284AD68u;
    static constexpr uint32_t kRecSize = 1556u;
    auto &mem = mcla::kernel::GuestMemoryHeap::Instance();
    for (uint32_t i = 0; i < 8; ++i) {
      const uint32_t rec = kRecBase + i * kRecSize;
      uint32_t f0 = 0, f4 = 0, f8 = 0, f24 = 0, f1540 = 0, f1548 = 0;
      (void)mem.ReadU32BE(rec + 0u, &f0);
      (void)mem.ReadU32BE(rec + 4u, &f4);
      (void)mem.ReadU32BE(rec + 8u, &f8);
      (void)mem.ReadU32BE(rec + 24u, &f24);
      (void)mem.ReadU32BE(rec + 1540u, &f1540);
      (void)mem.ReadU32BE(rec + 1548u, &f1548);
      MCLA_LOG_ERROR("F376-REC #{} rec={:08X} [+0]={:08X} [+4]={:08X} [+8]={:08X} [+24]={:08X} "
                     "[+1540]={:08X} [+1548]={:08X}{}",
                     i, rec, f0, f4, f8, f24, f1540, f1548, (r3 == rec) ? " <=r3" : "");
    }
    if (sp != 0) {
      for (uint32_t i = 0; i < 24; ++i) {
        uint32_t w = 0;
        if (!mem.ReadU32BE(sp + i * 4u, &w)) break;
        const bool code = w >= 0x82000000u && w < 0x82800000u;
        MCLA_LOG_ERROR("F378-HEAPSTACK #{} sp={:08X} [{}]=+{:#x} {:08X} {}", i, sp, i, i * 4u, w,
                       code ? "CODE?" : "raw");
      }
    }
  }
}

// ===========================================================================
// F-784 T44 WIPE WATCH -- who zeroes the two o1heap free-fragment headers?
// ===========================================================================
// F-783 measured TWO free-fragment headers inside the physical arena reading
// all-zero out of the read-only PHYS-BINPROBE walker in w745c: bin 8's card at
// 0xBDA2A000 and bin 19's at 0xBE135000, both printing
// `head=0 min=0 max=0 prev=0 next=0 len=1 used=0 found_bin=-1` while 34.97 MiB
// of the arena was free and the 413-byte request was refused with oom=1.
// F-783 also killed the three candidate explanations then on the table (the old
// game write, a VirtualProtect-style reset, a wrong-length zero-on-allocate), so
// the question is now purely empirical: which store writes those two addresses?
//
// THE INSTRUMENT. Every guest store that crosses the checked accessors in
// guest_memory.cpp (WriteU8 / WriteU16BE / WriteU32BE / WriteU64BE /
// WriteBytes -- the chokepoint both direct `stw` loops and bulk copies must
// cross; see the F-777 note at guest_memory.cpp:72-75) asks
// `T44WipeOverlaps(addr, len)` first and, on a hit, reports op, the value
// written, a PRE-copy snapshot of what was there, the guest lr/sp and the host
// return address. Phase 1 armed the two exact 4 KB pages from w745c; **w746
// proved that too narrow**, and phase 2 armed bands (below) plus a copy-level
// extent hook in gpu_device.cpp (T44-WIPE-MEMCPY).
//
// W746 -- WHAT PHASE 1 ACTUALLY MEASURED (all from build/w746.log):
//   * Positive control PASSED: `T44-WIPE-SELFTEST pages=[BDA2A000,BE135000]
//     read=2/2 ... rows=6 expect_rows=6`, and the six rows' `host=` fields
//     resolve with tools/host_rva_resolve.py --base 0x7FF639EE0000 to
//     `T44WipeSelfTest+0xc9` and neighbours. The chain fires, and the host
//     attribution resolves (LT rule 19 satisfied on both axes).
//   * The armed pages were the WRONG pages: this run's PHYS-BINPROBE #1..#4
//     read the broken cards at `gva=BDA1F000` and `gva=BE12A000`, i.e. **both
//     moved by exactly -0xB000** from w745c's BDA2A000/BE135000. Run-to-run
//     address stability is therefore REFUTED, not merely unverified: a 4 KB
//     arm watches two addresses nobody writes.
//   * A 3,152-byte zero sweep DID land on the stale page: 394 `op=U64 val=0`
//     stores, `BDA2A000..~BDA2AC50`, 06:28:39.778..40.002, `lr=821BE3BC`
//     (= sub_821BE250+0x16c, the return address of `bl 0x823DA950` per the
//     F-774 raw check at gpu_device.cpp:25455-25457) and 16 host lanes
//     `__imp__sub_823DA950 +0x2df..+0x699` -- the identical 16-site signature
//     F-778 recorded for the zeroed o1heap instances. `pre=0` on every row, so
//     it destroyed nothing live where it was watched, and it started at/above
//     BDA2A000 while this run's card sat 0xB000 lower: **not yet attributable
//     to the wipe**, only recorded.
//
// WHAT SILENCE MEANS -- READ THIS BEFORE QUOTING A ZERO. These functions are
// only reached by writes that go through the checked accessors. A raw
// host-pointer write (our own allocator's free-list surgery, a host memset on a
// host pointer) never gets here -- F-374 established exactly that limitation for
// the registered watch ranges. So zero T44 rows excludes accessor-routed writes
// to the armed BANDS and nothing else; it is NOT evidence the cards went
// unwritten. The complementary instrument is the run's own read-only
// PHYS-BINPROBE walker (src/kernel/heap.cpp NotePhysBinProbe), and the
// copy-level T44-WIPE-MEMCPY rows report a sweep's whole dst/src/len even when
// the per-store rows are capped.
//
// ROW POLICY (F-054 log quality; a 4 MB band is busy arena, so emitting every
// hit would spend the budget on texture traffic). `seq` counts EVERY hit; a row
// is attempted only for: the first hit of each band (band liveness + it makes
// the selftest's rows the first thing printed, so printer health is on the
// page), a WIPE hit (`val==0` with `preN>0` and `pre!=0` -- a zero store that
// destroyed live data, which is the signature we are hunting), and every
// 65536th hit as a cadence. Emitted rows are then capped at 400 + every 4096th.
// PHASE 3 (w747): that cap printed 477 of >=315,392 candidates, so the cap itself
// became the top hazard -- see kT44PrioPages below. Card-page hits take a separate
// path with a per-page budget this cap does not reach, and every probe now prints
// T44-TOTALS so silence arrives as a count rather than as an absence.

// PHASE 2 BANDS. 4 MB around each measured card cluster -- 90x the observed
// 0xB000 drift, and still only 1.6% of the 512 MiB arena. Index 0 = the bin-8
// cluster (w746 card BDA1F000, w745c card BDA2A000); index 1 = the bin-19
// cluster (w746 card BE12A000, w745c card BE135000).
constexpr uint32_t kT44WipeBands[2][2] = {
    {0xBD800000u, 0xBDC00000u},
    {0xBE000000u, 0xBE400000u},
};
constexpr uint32_t kT44WipeNumBands = 2u;
// PHASE 3 -- THE PRIORITY PAGES. w747 measured the CAP rather than the writer, and that is now
// the load-bearing fact about this instrument: `T44WipeNote` only prints for n<=400 or n%4096==0,
// `n` reached **315,392**, and 477 rows reached the log (= 400 + 77 multiples of 4096). So a hit
// on a card address had a ~0.15% chance of printing, and w747's "0 rows in either card window"
// is UNINTERPRETABLE rather than a zero -- exactly the LT-rule-19 shape, arriving as a cap instead
// of a blind printer. These four pages are the union of every card address this run family's own
// PHYS-BINPROBE has printed:
//   BDA1F000 / BE12A000 -- w746 AND w747 (stable across both builds),
//   BDA2A000 / BE135000 -- w745c, still in the family, still the boot-time control.
// A hit overlapping one of them counts per page, is pushed into a 16-entry ring that the probe
// dumps, and PRINTS under a per-page budget (first 128 rows of that page, then every 256th) that
// the band cap cannot touch. `kind=prio` rows still carry val/pre/pre_n, so a wipe is read off the
// row itself: val=0 with pre!=0 and pre_n>0.
constexpr uint32_t kT44PrioPages[4] = {0xBDA1F000u, 0xBE12A000u, 0xBDA2A000u, 0xBE135000u};
constexpr uint32_t kT44NumPrioPages = 4u;

// Every hit, suppressed or not. The selftest reads it before/after to prove the
// chain fired (LT rule 19): a zero with no selftest delta is blindness.
static std::atomic<uint32_t> s_t44WipeHits{0};
// Per-band hit counters; the first hit of each band always emits a row.
static std::atomic<uint32_t> s_t44BandHits[kT44WipeNumBands]{};
// PHASE 3 per-page counters (hit and emitted-row counts), so a probe row can STATE coverage.
static std::atomic<uint32_t> s_t44PrioHits[kT44NumPrioPages]{};
static std::atomic<uint32_t> s_t44PrioRows[kT44NumPrioPages]{};
static std::atomic<uint32_t> s_t44PrioWipes{0};
// Emitted rows for the band arm (was a function-local static in T44WipeNote; file scope now so
// T44WipeTotalsLine can print it alongside the hit totals).
static std::atomic<uint32_t> s_t44BandRows{0};

// PHASE 3 RING. The row budget above is generous but finite; the ring is what makes the TAIL
// observable -- the last 16 priority hits as they stood when PHYS-BINPROBE fired, cap or no cap.
// Written under a seqlock (seq odd while a slot is being filled, even once published) so a dump
// taken concurrently with a store cannot report a torn record as fact.
struct T44PrioRec
{
    uint32_t seq;        // 0 = never written; odd = being written; even = published
    const char* op;
    uint32_t addr;
    uint32_t len;
    uint64_t val;
    uint64_t pre;
    uint32_t preN;
    uint32_t lr;
    uint32_t sp;
    uint32_t band;
    uint32_t prio;
    uint32_t seqn;       // global hit counter at the time
    uint32_t pad;
    const void* host;
};
constexpr uint32_t kT44PrioRingN = 16u;
static T44PrioRec s_t44PrioRing[kT44PrioRingN]{};
static std::atomic<uint32_t> s_t44PrioRingNext{0};

// Band index containing guestAddr, or -1. -1 IS truthy, so every caller must
// compare `>= 0` rather than test the result (same trap as HeapInstanceStoreHit).
int T44WipeBandOf(uint32_t guestAddr) {
  for (uint32_t i = 0; i < kT44WipeNumBands; ++i)
    if (guestAddr >= kT44WipeBands[i][0] && guestAddr < kT44WipeBands[i][1])
      return (int)i;
  return -1;
}

bool T44WipeOverlaps(uint32_t guestAddr, uint32_t len) {
  if (len == 0) return false;
  const uint64_t end = static_cast<uint64_t>(guestAddr) + len;
  for (uint32_t i = 0; i < kT44WipeNumBands; ++i) {
    const uint64_t lo = kT44WipeBands[i][0];
    if (guestAddr < kT44WipeBands[i][1] && lo < end) return true;
  }
  return false;
}

// SPAN form: also reports where the overlap starts and how many bytes of it
// there are, so a bulk copy can snapshot exactly the bytes it is about to
// overwrite (start address alone cannot say which bytes those are).
bool T44WipeSpan(uint32_t guestAddr, uint32_t len, uint32_t* outStart,
                 uint32_t* outLen) {
  if (len == 0) return false;
  const uint64_t end = static_cast<uint64_t>(guestAddr) + len;
  for (uint32_t i = 0; i < kT44WipeNumBands; ++i) {
    const uint64_t lo = kT44WipeBands[i][0];
    const uint64_t hi = kT44WipeBands[i][1];
    if (guestAddr < hi && lo < end) {
      const uint64_t s = guestAddr > lo ? guestAddr : lo;
      const uint64_t e = end < hi ? end : hi;
      if (outStart) *outStart = static_cast<uint32_t>(s);
      if (outLen) *outLen = static_cast<uint32_t>(e - s);
      return true;
    }
  }
  return false;
}

uint32_t T44WipeHits() { return s_t44WipeHits.load(std::memory_order_relaxed); }

// PRIORITY ARM (phase 3). Page-granular overlap against kT44PrioPages; -1 when the address is
// only in a band. Returns the page index so the caller can count per page.
int T44WipePrioOf(uint32_t guestAddr, uint32_t len)
{
    if (len == 0u) return -1;
    const uint64_t end = static_cast<uint64_t>(guestAddr) + len;
    for (uint32_t i = 0; i < kT44NumPrioPages; ++i)
    {
        const uint64_t lo = kT44PrioPages[i];
        if (guestAddr < (lo + 0x1000u) && lo < end) return (int)i;
    }
    return -1;
}

// Seqlock push: publish `seq` odd, fill, publish even. A reader that sees an odd value, a zero,
// or a value that changed across its copy discards the record instead of quoting it.
void T44WipePrioRingPush(const char* op, uint32_t addr, uint32_t len, uint64_t val, uint64_t pre,
                         uint32_t preN, uint32_t seqn, uint32_t band, uint32_t prio,
                         const void* host)
{
    const uint32_t slot =
        s_t44PrioRingNext.fetch_add(1, std::memory_order_relaxed) % kT44PrioRingN;
    T44PrioRec& r = s_t44PrioRing[slot];
    // The marker is a plain field in a copyable struct; atomic_ref is what makes the seqlock a
    // seqlock rather than a plain read-modify-write race (C++20, and every access below goes
    // through a reference, so no plain access to `seq` exists anywhere).
    std::atomic_ref<uint32_t> mark(r.seq);
    uint32_t lr = 0, sp = 0;
    if (const PPCContext* c = GetPPCContext())
    {
        lr = static_cast<uint32_t>(c->lr);
        sp = c->r1.u32;
    }
    const uint32_t s0 = mark.load(std::memory_order_relaxed);
    mark.store(s0 + 1u, std::memory_order_release);
    r.op = op;
    r.addr = addr;
    r.len = len;
    r.val = val;
    r.pre = pre;
    r.preN = preN;
    r.lr = lr;
    r.sp = sp;
    r.band = band;
    r.prio = prio;
    r.seqn = seqn;
    r.host = host;
    mark.store(s0 + 2u, std::memory_order_release);
}

// The probe-time coverage line. Its whole purpose is to make a SILENT run interpretable: it pairs
// every probe row with how many hits each armed band and each armed card page took, so
// "no T44-WIPE-STORE row for this address" can be read as a count instead of argued from absence.
// One row per PHYS-BINPROBE (4 per w747-shaped soak), so it costs nothing against F-054.
void T44WipeTotalsLine(uint32_t probeN)
{
    MCLA_LOG_WARN(
        "T44-TOTALS probe#{} hits={} band0={} band1={} band_rows={} "
        "prio_pages=[{:08X},{:08X},{:08X},{:08X}] prio_hits=[{},{},{},{}] "
        "prio_rows=[{},{},{},{}] prio_wipes={} ring_next={}",
        probeN, T44WipeHits(), s_t44BandHits[0].load(std::memory_order_relaxed),
        s_t44BandHits[1].load(std::memory_order_relaxed),
        s_t44BandRows.load(std::memory_order_relaxed), kT44PrioPages[0], kT44PrioPages[1],
        kT44PrioPages[2], kT44PrioPages[3], s_t44PrioHits[0].load(std::memory_order_relaxed),
        s_t44PrioHits[1].load(std::memory_order_relaxed),
        s_t44PrioHits[2].load(std::memory_order_relaxed),
        s_t44PrioHits[3].load(std::memory_order_relaxed),
        s_t44PrioRows[0].load(std::memory_order_relaxed),
        s_t44PrioRows[1].load(std::memory_order_relaxed),
        s_t44PrioRows[2].load(std::memory_order_relaxed),
        s_t44PrioRows[3].load(std::memory_order_relaxed),
        s_t44PrioWipes.load(std::memory_order_relaxed),
        s_t44PrioRingNext.load(std::memory_order_relaxed));

    // The ring tail, so the probe row and the last writes to those pages sit next to each other.
    for (uint32_t i = 0; i < kT44PrioRingN; ++i)
    {
        T44PrioRec& r = s_t44PrioRing[i];
        std::atomic_ref<uint32_t> mark(r.seq);
        const uint32_t s1 = mark.load(std::memory_order_acquire);
        if (s1 == 0u || (s1 & 1u) != 0u) continue; // never written, or mid-write
        const T44PrioRec c = r;                    // copy, then re-check for a tear
        if (mark.load(std::memory_order_acquire) != s1) continue;
        MCLA_LOG_WARN(
            "T44-PRIO-RING #{} slot={} kind={} op={} @ {:08X} len={} val={:X} pre={:X} "
            "pre_n={} band={} prio={} lr={:08X} sp={:08X} host={} seq={}",
            i, i, (c.preN > 0u && c.val == 0u && c.pre != 0u) ? "wipe" : "hit", c.op, c.addr,
            c.len, c.val, c.pre, c.preN, c.band, c.prio, c.lr, c.sp, c.host, c.seqn);
    }
}

// `pre` is the value read at the destination BEFORE the store (memory order,
// big-endian as the guest sees it); `preN` is how many bytes of it were
// captured -- 0 means this path did not snapshot (the PageWatchOnWrite arm),
// so a `preN=0` row can never be read as "the destination was zero".
void T44WipeNote(const char* op, uint32_t guestAddr, uint32_t len, uint64_t val,
                 uint64_t pre, uint32_t preN, const void* hostPc) {
  const uint32_t seq = s_t44WipeHits.fetch_add(1, std::memory_order_relaxed) + 1;
  const int band = T44WipeBandOf(guestAddr);
  // The signature being hunted: a zero store that overwrote nonzero data.
  const bool wipe = (preN > 0u && val == 0u && pre != 0u);
  bool first = false;
  if (band >= 0)
    first = (s_t44BandHits[band].fetch_add(1, std::memory_order_relaxed) == 0);
  uint32_t lr = 0, sp = 0;
  if (const PPCContext* c = GetPPCContext()) {
    lr = static_cast<uint32_t>(c->lr);
    sp = c->r1.u32;
  }

  // PHASE 3 PRIORITY ARM. Evaluated before the band arm so a card-page hit can never be
  // swallowed by it: it is counted per page, always pushed to the ring, and printed under the
  // page's OWN budget (first 128 rows of that page, then every 256th) -- `n > 400 && n % 4096`
  // below does not apply to these. `first` was already consumed above, so band liveness still
  // prints when a card page holds the band's very first hit.
  if (const int prio = T44WipePrioOf(guestAddr, len); prio >= 0) {
    s_t44PrioHits[prio].fetch_add(1, std::memory_order_relaxed);
    if (wipe) s_t44PrioWipes.fetch_add(1, std::memory_order_relaxed);
    T44WipePrioRingPush(op, guestAddr, len, val, pre, preN, seq,
                        static_cast<uint32_t>(band), static_cast<uint32_t>(prio), hostPc);
    const uint32_t r = s_t44PrioRows[prio].fetch_add(1, std::memory_order_relaxed) + 1;
    if (r > 128u && (r % 256u) != 0u) return;
    MCLA_LOG_WARN("T44-WIPE-STORE #{:04} kind=prio band={} page={} op={} @ {:08X} len={} "
                  "val={:X} pre={:X} pre_n={} lr={:08X} sp={:08X} host={} seq={}",
                  r, band, prio, op, guestAddr, len, val, pre, preN, lr, sp, hostPc, seq);
    return;
  }

  const bool cadence = (seq % 65536u) == 0u;
  if (!(wipe || first || cadence)) return;
  const uint32_t n = s_t44BandRows.fetch_add(1) + 1;
  if (n > 400u && (n % 4096u) != 0u) return;
  MCLA_LOG_WARN("T44-WIPE-STORE #{:04} kind={} band={} op={} @ {:08X} len={} "
                "val={:X} pre={:X} pre_n={} lr={:08X} sp={:08X} host={} seq={}",
                n, wipe ? "wipe" : (first ? "first" : "cadence"), band, op,
                guestAddr, len, val, pre, preN, lr, sp, hostPc, seq);
}

// LT rule 19 POSITIVE CONTROL. A silent T44-WIPE-STORE only means something if
// this run ALSO printed T44-WIPE-SELFTEST with a nonzero hits= delta: for each
// of the four armed card pages it reads a dword, a byte and a 16-byte span and
// writes the very same bytes back through the checked accessors, so the arena is
// byte-identical afterwards while the accessor -> overlap -> note chain is
// forced to fire 12 times. Those writes land on `kind=prio` rows, so the
// PRIORITY PRINTER phase 3 depends on is proven on the page, and two of the four
// are the very addresses w747's probe reported broken (BDA1F000 / BE12A000) --
// the control covers the addresses under investigation rather than only a
// convenient stand-in. The row also prints each page's first two dwords as they
// stood at boot: the only baseline for "was this header always zero or did it get
// zeroed" the run will ever have. If the addresses cannot be read this early in
// boot the line says so (read=0/4, hits=0) and the run's silence stays
// uninterpretable rather than looking like a result.
void T44WipeSelfTest() {
  mcla::native::GuestMemoryView& mem = mcla::native::GetActiveGuestMemoryView();
  const uint32_t seq0 = T44WipeHits();
  uint32_t readOk = 0, wrote32 = 0, wroteU8 = 0, wroteBulk = 0;
  uint32_t hdr[kT44NumPrioPages][2] = {};
  for (uint32_t i = 0; i < kT44NumPrioPages; ++i) {
    const uint32_t page = kT44PrioPages[i];
    uint32_t w0 = 0, w1 = 0;
    const bool r0 = mem.ReadU32BE(page, &w0);
    const bool r1 = mem.ReadU32BE(page + 4u, &w1);
    hdr[i][0] = w0;
    hdr[i][1] = w1;
    if (r0 && r1) ++readOk;
    if (r0 && mem.WriteU32BE(page, w0)) ++wrote32;      // byte-identical
    uint8_t b = 0;
    if (mem.ReadU8(page + 8u, &b) && mem.WriteU8(page + 8u, b)) ++wroteU8;
    uint8_t buf[16] = {};
    if (mem.ReadBytes(page + 0x10u, buf, sizeof(buf)) &&
        mem.WriteBytes(page + 0x10u, buf, sizeof(buf)))
      ++wroteBulk;
  }
  MCLA_LOG_WARN("T44-WIPE-SELFTEST bands=[{:08X},{:08X})+[{:08X},{:08X}) "
                "prio=[{:08X},{:08X},{:08X},{:08X}] read={}/4 "
                "hdr=[{:08X},{:08X}][{:08X},{:08X}][{:08X},{:08X}][{:08X},{:08X}] "
                "w32={} wu8={} wbulk={} hits={} expect_hits=12",
                kT44WipeBands[0][0], kT44WipeBands[0][1], kT44WipeBands[1][0],
                kT44WipeBands[1][1], kT44PrioPages[0], kT44PrioPages[1],
                kT44PrioPages[2], kT44PrioPages[3], readOk, hdr[0][0], hdr[0][1],
                hdr[1][0], hdr[1][1], hdr[2][0], hdr[2][1], hdr[3][0], hdr[3][1],
                wrote32, wroteU8, wroteBulk, T44WipeHits() - seq0);
}

void PageWatchOnWrite(uint32_t guestAddr, uint32_t value) {
  static std::atomic<uint32_t> s_watchWrites{0};

  // F-784 T44 WIPE WATCH. Two o1heap free-fragment headers were measured
  // zeroed inside the physical arena (F-783: w745c cards BDA2A000/BE135000;
  // w746 cards BDA1F000/BE12A000 -- both moved -0xB000, so the arm is a 4 MB
  // BAND pair now, see kT44WipeBands above, and the analysis still compares
  // this run's own PHYS-BINPROBE `gva` against those bands before believing any
  // silence). This arm is the FALLBACK path: it only runs when a range or value
  // watch already fired, and it carries no `pre` (pre_n=0 below), so the
  // accessor arms in guest_memory.cpp are the primary rows. Fall through so the
  // existing CDCD-FILL / PHYS-OVERRUN / RSC-REF arms keep their rows.
  if (T44WipeOverlaps(guestAddr, 4u))
    T44WipeNote("PW", guestAddr, 4u, value, 0, 0, _ReturnAddress());
  // (pre=0 pre_n=0 -- this path does not snapshot the prior value; the
  // accessor arms in guest_memory.cpp do, and those are the primary rows.)

  // F-141 CENSUS ONLY (read-only; armed in boot_host.cpp for these two values).
  // The renderer's resource "pointers" at this frontier are non-addresses
  // (F-137/F-140): 0x80010000 is the value the AUTO draw's packet puts in CP
  // register 0x81 and the object sub_82184458 fixs up, and 0x00020037 is
  // r01DC, dereferenced as a descriptor by sub_82185190. Name the guest store
  // that materialises them, so the producer is read off the log instead of
  // deduced. Given its own counter because the generic PAGEWATCH W report
  // shares one budget (F-453: 64 rows overall, 4 per address stripe).
  if (value == 0x80010000u || value == 0x00020037u) {
    static std::atomic<uint32_t> s_refStores{0};
    const uint32_t rn = s_refStores.fetch_add(1) + 1;
    if (rn <= 40) {
      uint32_t lr = 0, sp = 0;
      if (const PPCContext *c = GetPPCContext()) {
        lr = static_cast<uint32_t>(c->lr);
        sp = c->r1.u32;
      }
      MCLA_LOG_WARN("RSC-REF-STORE #{:03} @ {:08X} = {:08X} lr={:08X} "
                    "sp={:08X}",
                    rn, guestAddr, value, lr, sp);
    }
    return;
  }

  // SESSION 73: 0xCDCDCDCD store census. Static decode says the guest fills
  // memory with 0xCD in exactly these places: sub_821DE9D8's fill-on-alloc
  // tail (memset return addr 0x821DEB0C) and two startup fills of the
  // 1352-byte global at 0x8283C5E0 (memset returns 0x8218C9D4/0x8218CCCC).
  // The guest memset is a leaf (never saves LR), so ctx.lr at store time is
  // the memset CALLER - any LR outside the set above is a new fill site.
  if (value == 0xCDCDCDCDu) {
    static std::atomic<uint32_t> s_cdcdStores{0};
    const uint32_t n = s_cdcdStores.fetch_add(1) + 1;
    if (n <= 24 || (n % 20000) == 0) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("CDCD-FILL #{:09} @ {:08X} = CDCDCDCD lr={:08X}", n,
                    guestAddr, lr);
    }
    // SESSION 73 overrun probe: a 0xCD store inside the physical arena that
    // no handed-out allocation covers is writing o1heap metadata / free
    // space — the AV-storm corruptor. Page-granular check cache; the scan
    // only runs once per 4KB page.
    //
    // F-412: the gate used to read `>= 0xA0000000u`, which after F-391 is a
    // SUPERSET of our arena (pool now begins at kPhysArenaBeginVa = 0xA0400000, see
    // src/kernel/heap_arena.h:40). Stores in the title-heap watch ranges armed at the
    // time (0xA0018028 - which this same F-412 pass moved to 0xA0418028, 0xA008261C,
    // 0xA0106xxx, 0xB7B6xxxx) can never be
    // MclaPhysRangeEverAllocated -- we never owned them -- so they were counted as our-arena
    // overruns and burned the 64-row cap. Follow the constant, like HEAPHDR-STORE below.
    if (guestAddr >= mcla::kernel::kPhysArenaBeginVa) {
      static std::mutex s_pgMtx;
      static std::unordered_set<uint32_t> s_checkedPages;
      const uint32_t page = guestAddr >> 12;
      bool report = false;
      {
        std::lock_guard<std::mutex> lock(s_pgMtx);
        report = s_checkedPages.insert(page).second;
      }
      if (report) {
        if (!mcla::kernel::MclaPhysRangeEverAllocated(guestAddr)) {
          static std::atomic<uint32_t> s_overruns{0};
          const uint32_t ov = s_overruns.fetch_add(1) + 1;
          if (ov <= 64) {
            uint32_t lr = 0;
            if (const PPCContext *c = GetPPCContext())
              lr = static_cast<uint32_t>(c->lr);
            uint32_t nb = 0, ns = 0;
            const bool haveNb =
                mcla::kernel::MclaPhysNearestAllocBelow(guestAddr, &nb, &ns);
            MCLA_LOG_WARN("PHYS-OVERRUN #{:03} @ {:08X} = CDCDCDCD lr={:08X} "
                          "nearestAlloc={} size={:#x} gap={:#x}",
                          ov, guestAddr, lr,
                          haveNb ? nb : 0u, haveNb ? ns : 0u,
                          haveNb ? (guestAddr - (nb + ns)) : 0u);
          }
        }
      }
    }
    return;
  }

  // SESSION 76j: the device-registry holder (A0018028..30) and entry0's
  // device-vector (A008261C..24) get scribbled with the kernel "uninitialized"
  // pattern FF00FF00 right before the GetDevice crash. The guest LR here is
  // misleading (slab-wrapper return site), so capture the HOST callstack once.
  // F-412: the holder moved with the title XTL heap when F-391 shifted the physical pool to
  // kPhysArenaBeginVa (0xA0400000): w430 `F389-BANK head=[... A0401010 A0401000 ... A042FFC0]`
  // vs w403 `A0001010/A0001000/A002FFC0`, i.e. +0x400000. The second window
  // (0xA008261C..24) is left armed at its old address on purpose: it sits in the now-unowned gap
  // 0xA0030000..0xA0400000, and w430 has 0 FFBT rows, so it is armed-but-inert, not a false hit.
  if (value == 0xFF00FF00u &&
      ((guestAddr >= 0xA0418028u && guestAddr < 0xA0418030u) ||
       (guestAddr >= 0xA008261Cu && guestAddr < 0xA0082624u))) {
    static std::atomic<uint32_t> s_ffbt{0};
    if (s_ffbt.fetch_add(1) < 1) {
      SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
      static std::once_flag symOnce76j;
      std::call_once(symOnce76j, []() {
        SymInitialize(GetCurrentProcess(), nullptr, TRUE);
      });
      void *frames[16] = {};
      const USHORT nCap = CaptureStackBackTrace(0, 16, frames, nullptr);
      for (USHORT fi = 0; fi < nCap; ++fi) {
        alignas(8) char scratch[sizeof(SYMBOL_INFO) + 160];
        SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
        si->SizeOfStruct = sizeof(SYMBOL_INFO);
        si->MaxNameLen = 159;
        DWORD64 disp = 0;
        char nameBuf[200];
        const char *name = "???";
        if (SymFromAddr(GetCurrentProcess(), (DWORD64)frames[fi], &disp, si)) {
          snprintf(nameBuf, sizeof(nameBuf), "%s+0x%llx", si->Name,
                   (unsigned long long)disp);
          name = nameBuf;
        }
        MCLA_LOG_WARN("FFBT frame {:02d} {} {}", fi, (void *)frames[fi], name);
      }
    }
  }

  // SESSION 73 probe: the un-attributed poison-param regions (REBASE-POISON
  // params A01064B4/524/594/604/66D4 stride 0x70, and A0197Exx stride 0x70)
  // saw ZERO 0xCDCDCDCD value-watch hits, so either their fill bypasses the
  // checked accessors or they were never guest-written this run. These
  // ranges are registered as watch ranges in boot_host, so any guest store
  // here lands on this probe. Capped logging.
  if ((guestAddr >= 0xA0106000u && guestAddr < 0xA0107000u) ||
      (guestAddr >= 0xA0197E00u && guestAddr < 0xA0197F00u)) {
    static std::atomic<uint32_t> s_paramProbe{0};
    const uint32_t pn = s_paramProbe.fetch_add(1) + 1;
    if (pn <= 400 || (pn % 5000) == 0) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("PARAM-STORE #{:06} @ {:08X} = {:08X} lr={:08X}", pn,
                    guestAddr, value, lr);
    }
    return;
  }

  // SESSION 73 probe: the o1heap instance + first physical fragments. The instance is
  // host-only memory — ANY guest store here is the heap corruptor. Logged with guest LR
  // attribution.
  //
  // F-412: F-391 moved the physical pool to kPhysArenaBeginVa (was 0xA0000000, which sits
  // inside the title's own XTL heap) and the range armed in boot_host.cpp followed it, but this
  // test did not — it stayed on the old band and became unreachable. That zero is not evidence
  // of health: HEAPHDR-STORE printed its 200-row cap in EVERY soak w394..w405 and exactly 0 in
  // w406..w420, and the path it falls through to (PAGEWATCH W below) only ever prints its first
  // 16 rows, which w418/w419/w420 show already spent on 0x828CD0xx. So after F-391 a guest store
  // of the shape `@ <phys base> = <base+4>` had no logging route at all. Follow the constant.
  // This branch returns before the 16-row PAGEWATCH cap, so it stays the uncapped channel.
  // F-774: the window was [base, base+0x800) and the cap was `hn <= 200 || hn % 5000 == 0`.
  // Those two constants made the probe STRUCTURALLY BLIND to the only question it exists to
  // answer. A 0x800 window holds 512 stride-4 addresses, so a single ascending zero-fill pass
  // can produce at most 512 in-window stores -- `hn` can never reach 5000, and the `% 5000` arm
  // is dead code. w737 printed exactly rows #1..#200 (A0400000..A040031C, contiguous, all zero,
  // all lr=821BE3BC) and then nothing, which reads as "the sweep stopped at 0x320 bytes" but is
  // equally consistent with "the sweep ran on for megabytes and the cap ate it". An agent this
  // session inferred the former and proposed a 32 KB arena offset on the strength of it; that
  // inference is unsound and the offset would be a guess. This is LT rule 19 / F-412 again: a
  // zero from an instrument is not a result until the instrument is shown able to fire.
  //
  // F-774 CORRECTION -- widening the window below did NOT make this probe able to answer, and
  // w738 proves it. This branch only runs from PageWatchOnWrite, which only runs for addresses
  // inside a range armed by RegisterGuestWatchRange; boot_host.cpp:3207-3208 arms
  // [kPhysArenaBeginVa, kPhysArenaBeginVa + 0x800), i.e. 2 KB. So guestAddr can never reach
  // base+0x800 here and the 1 MB bound is unreachable. Measured in w738: 202 rows, #1..#200 then
  // #256 then #512, the last being `#000512 @ A04007FC` -- the final dword of the ARMED range,
  // with the log's own positive control `WATCH: range armed [A0400000,A0400800)` at w738.log:35.
  // 512 is therefore the armed capacity, not the sweep length. What is actually established:
  // the fill is contiguous stride-4 and covers at least the whole 2 KB; above A0400800 this
  // branch is blind by construction and no row count from it can bound anything.
  // The instrument that can answer lives at the memcpy hook instead (gpu_device.cpp,
  // F774-PHYS-MEMCPY in PPC_FUNC(sub_823DA950)): it sees dst/len directly, is not gated by any
  // armed range, and reads the real PPCContext rather than GetPPCContext().
  if (guestAddr >= mcla::kernel::kPhysArenaBeginVa &&
      guestAddr < mcla::kernel::kPhysArenaBeginVa + 0x100000u) {
    static std::atomic<uint32_t> s_heapHdrStores{0};
    const uint32_t hn = s_heapHdrStores.fetch_add(1) + 1;
    if (hn <= 200 || (hn % 256) == 0) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("HEAPHDR-STORE #{:06} @ {:08X} = {:08X} lr={:08X}", hn,
                    guestAddr, value, lr);
    }
    return;
  }

  // F-441 (T41.93): is the title's boot-worker queue EVER written? The worker spins on
  // `a1[15] == a1[14]` and the census reads the queue words as 0 (`W36b-QUEUE qWrite=0 qRead=0
  // delta=0`, w435 and w440), and no code in the image materialises 0x40004B40/0x40004D5C as an
  // address (searched: the only `lis r?,16384` sites use it as a 0x40000000 *value*, and the
  // `+19264` hits resolve to 0x82834B40/0x82044B40), so the object pointer is runtime-supplied and
  // static search cannot name the poster. This watch names it dynamically or proves none writes.
  // Separate counter, because the shared PAGEWATCH cap below is already spent by other ranges.
  if (guestAddr >= 0x40004B40u && guestAddr < 0x40004DC0u) {
    static std::atomic<uint32_t> s_qStores{0};
    const uint32_t qn = s_qStores.fetch_add(1) + 1;
    if (qn <= 32 || (qn % 500) == 0) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("F441-QUEUE-STORE #{:05} @ {:08X} = {:08X} lr={:08X}", qn, guestAddr, value,
                    lr);
    }
    return;
  }

  const uint32_t n = s_watchWrites.fetch_add(1) + 1;
  // F-453: the old `n <= 16` was a SHARED lifetime cap, so one burst spent it. Both
  // w423 and w430 print exactly 16 `PAGEWATCH W` rows at boot +0.66 s (all
  // 0x828CD0xx, all lr=821327F8) and then cannot print again for the rest of the
  // soak - later stores are invisible, not absent, which is how F-401 §2 read
  // "recorded every store ... nothing else". Two-level budget instead: a per-address
  // stripe (one routine stamping a table of N distinct addresses still gets N rows,
  // but no single address can monopolise the window) plus a raised shared window
  // with the file's own periodic tail row. Both bounded - no unbounded logging
  // (do-not class F-054).
  static std::atomic<uint32_t> s_watchStripe[1024] = {};
  if (n <= 64 || (n % 5000) == 0) {
    if (s_watchStripe[(guestAddr >> 4) & 0x3FFu].fetch_add(1) < 4) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("PAGEWATCH W #{:03} @ {:08X} = {:08X} lr={:08X}", n,
                    guestAddr, value, lr);
    }
  }
}

void PageWatchOnRead(uint32_t guestAddr, uint32_t value) {
  // F-440 (T41.92): the question this answers is whether ANY guest code ever reads the
  // {handler, msgid} registry. `PPC_LOAD_U32` is `mcla::native::ReadGuestU32`
  // (src/ppc_context.h:57 -> src/guest_memory.h:84), so every recompiled guest load really does pass
  // through this accessor -- which is what makes a read-watch a valid instrument here at all, and it
  // is why the registry probe gets its own counter instead of sharing the 8-row global cap below.
  // Range = 0x82102AA0..0x82118000: the pair table IDA read at 0x82102aa0 (gate 0x82131008 ->
  // msgid 0x40003B03) plus the two arrays F-439 found beyond F-358's census limit -- 0x82115F60
  // (GFx wrapper 0x82482F78 -> 0x40001405) and 0x82117820 (GFx ctor 0x824C6F08 -> 0x40001905).
  if (guestAddr >= 0x82102AA0u && guestAddr < 0x82118000u) {
    static std::atomic<uint32_t> s_regReads{0};
    const uint32_t rn = s_regReads.fetch_add(1) + 1;
    if (rn <= 24 || (rn % 500) == 0) {
      uint32_t lr = 0;
      if (const PPCContext *c = GetPPCContext())
        lr = static_cast<uint32_t>(c->lr);
      MCLA_LOG_WARN("F440-REGREAD #{:06} @ {:08X} -> {:08X} lr={:08X}", rn, guestAddr, value, lr);
    }
    return;
  }
  static std::atomic<uint32_t> s_watchReads{0};
  const uint32_t n = s_watchReads.fetch_add(1) + 1;
  if (n <= 8) {
    uint32_t lr = 0;
    if (const PPCContext *c = GetPPCContext())
      lr = static_cast<uint32_t>(c->lr);
    MCLA_LOG_WARN("PAGEWATCH R #{:02} @ {:08X} -> {:08X} lr={:08X}", n,
                  guestAddr, value, lr);
  }
}

void CpInstallMmioRouting() {
  mcla::native::SetGpuMmioHandlers(&CpMmioWrite, &CpMmioRead);
  MCLA_LOG_INFO("CP: MMIO routing installed (XGPU window 0x7FC80000)");
}

} // namespace mcla::gpu
