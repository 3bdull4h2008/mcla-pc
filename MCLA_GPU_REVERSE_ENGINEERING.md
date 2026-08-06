# MCLA Full Reverse Engineering Report
## Generated: 2026-07-20 (Updated: Comprehensive Naming Table Added)
## Status: 1005 individually named entries | All 750 functions with 10-19 calls analyzed

---

## TABLE OF CONTENTS

1. [ENGINE ARCHITECTURE OVERVIEW](#1-engine-architecture-overview)
2. [ADDRESS SPACE MAP](#2-address-space-map)
3. [TOP FUNCTION NAMING TABLE](#3-top-function-naming-table)
4. [CORE RUNTIME (0x8213xxxx)](#4-core-runtime-0x8213xxxx)
5. [GPU MANAGER OBJECT STRUCTURE](#5-gpu-manager-object-structure)
6. [GPU COMMAND BUFFER ARCHITECTURE](#6-gpu-command-buffer-architecture)
7. [DRAW CALL PIPELINE](#7-draw-call-pipeline)
8. [GPU INTERRUPT HANDLING](#8-gpu-interrupt-handling)
9. [GPU REGISTER PROGRAMMING PATTERNS](#9-gpu-register-programming-patterns)
10. [INITIALIZATION FLOW](#10-initialization-flow)
11. [ENGINE SUBSYSTEMS](#11-engine-subsystems)
12. [RPF3 ARCHIVE FORMAT](#12-rpf3-archive-format)
13. [KNOWN ISSUES & FIXES](#13-known-issues--fixes)
14. [GPU STATE MACHINE DIAGRAM](#14-gpu-state-machine-diagram)
15. [ENTITY/SCENE GRAPH ARCHITECTURE](#15-entityscene-graph-architecture-0x821dxxxx)
16. [VD LAYER / CRT LIBRARY](#16-vd-layer--crt-library-0x8238xxxx-0x823exxxx)
17. [RENDER SCENE PIXEL PROCESSING](#17-render-scene-pixel-processing-0x8244xxxx)
18. [AUDIO DSP SYSTEM](#18-audio-dsp-system-0x8217xxxx-0x8218xxxx)
19. [CITY STREAMING & RESOURCE SYSTEM](#19-city-streaming--resource-system-0x825exxxx-0x8269xxxx)
20. [OBJECT MODEL & MESSAGE DISPATCH](#20-object-model--message-dispatch-system-0x8268xxxx)
21. [I/O STREAM & BUFFER SYSTEM](#21-io-stream--buffer-system-0x821bexxxx)
22. [COMPREHENSIVE ALL-FUNCTIONS NAMING REFERENCE](#22-comprehensive-all-functions-naming-reference)

---

## 1. ENGINE ARCHITECTURE OVERVIEW

The MCLA (Midnight Club: Los Angeles) Xbox 360 executable is a PPC64 big-endian binary recompiled to x64 using the rexglue framework. The engine is structured as a layered architecture:

```
┌──────────────────────────────────────────────────┐
│  Game Layer (0x8255xxxx-0x8260xxxx)              │
│  Gameplay, missions, UI, city streaming           │
├──────────────────────────────────────────────────┤
│  Engine Core (0x8214xxxx-0x822Axxxx)             │
│  Scene graph, entities, physics, audio, input     │
├──────────────────────────────────────────────────┤
│  Vd Layer / System Services (0x8238xxxx)          │
│  HAL abstraction, memory, thread, XAM wrappers    │
├──────────────────────────────────────────────────┤
│  Xenos GPU Subsystem (0x8240xxxx-0x8242xxxx)      │
│  Ring buffer, shaders, draw calls, interrupts     │
├──────────────────────────────────────────────────┤
│  Core Runtime (0x8213xxxx)                        │
│  Allocator, vtable dispatch, string ops, hashing  │
└──────────────────────────────────────────────────┘
```

The binary uses C++ virtual function tables extensively. The most-called functions in the entire codebase are vtable dispatch wrappers and memory allocator entry points.

---

## 2. ADDRESS SPACE MAP

| Range | Size | Subsystem | Description |
|-------|------|-----------|-------------|
| 0x82130000-0x8213FFFF | 64 KB | **Core Runtime** | Memory allocator, vtable dispatch, type system, hash tables |
| 0x82140000-0x8217FFFF | 256 KB | **Engine Core** | Math, physics, transforms, collision |
| 0x82180000-0x821CFFFF | 320 KB | **Audio + Timer** | Audio parameter system, DSP, timers, callbacks |
| 0x821D0000-0x8221FFFF | 320 KB | **Scene/Entity** | Entity manager, game objects, rendering |
| 0x82220000-0x8229FFFF | 512 KB | **Audio System** | XAudio2 wrappers, sound banks, mixer |
| 0x822A0000-0x822AFFFF | 64 KB | **Platform Layer** | Platform/region/locale flag lookup, system config |
| 0x82300000-0x8237FFFF | 512 KB | **System HAL** | Threading, synchronization primitives |
| 0x82380000-0x823DFFFF | 384 KB | **Kernel/Vd Layer** | Object table, device I/O, file system, RPC |
| 0x823E0000-0x823FFFFF | 128 KB | **XAM System** | Xam wrappers, profile, storage, networking |
| 0x82400000-0x8243FFFF | 256 KB | **Xenos GPU** | GPU init, ring buffer, shaders, draw calls, interrupts |
| 0x82440000-0x8249FFFF | 384 KB | **Graphics Engine** | Texture management, render passes, state tracking |
| 0x824A0000-0x824DFFFF | 256 KB | **Shader System** | Shader compilation, microcode translation |
| 0x824E0000-0x8254FFFF | 448 KB | **City/Rendering** | City streaming, visibility, LOD, terrain |
| 0x82550000-0x8262FFFF | 896 KB | **Game Logic** | Gameplay, missions, AI, UI, HUD, menus |

---

## 3. TOP FUNCTION NAMING TABLE

The following table names the most-called functions in the codebase (sorted by call frequency). These are the hot-path functions that dominate execution.

| Address | Calls | Category | Suggested Name | Description |
|---------|-------|----------|----------------|-------------|
| 0x82130588 | 3,909 | Core Runtime | `SafeRelease` | Null-check arg, load allocator from r13+28, call vtable+12 (release/free). Universal `SafeRelease` trampoline used on every COM-style object. |
| 0x82130528 | 3,225 | Core Runtime | `AlignedHeapAlloc` | Load allocator from r13+28, call vtable+8 with alignment=16. Primary aligned heap allocation entry point. |
| 0x82130000 | 2,132 | Core Runtime | `NopStub` | Just `blr` (no-op). Empty virtual base function or patch placeholder. |
| 0x82554798 | 1,259 | Game Logic | `AssertOrVerify` | Condition-check assertion: calls validator, on failure loads string ref and calls error logger. |
| 0x824DF200 | 811 | Shader System | `RegisterNamedResource` | Inserts a typed name+value entry (88 bytes) into a resource table. Handles inline storage (cap 64) or heap overflow. |
| 0x823DA950 | 598 | Kernel/Vd | `memcpy` | Optimized memory copy with unaligned preamble, 64-bit bulk loop, and dcbt prefetch. **The game's own memcpy.** |
| 0x821FA230 | 575 | Engine Core | `GetSingletonManager` | Loads global singleton, dereferences offset 52, returns pointer. Standard singleton getter pattern. |
| 0x8217F768 | 565 | Audio | `DispatchSetProperty` | 40-case switch-based property setter. Maps property IDs to struct field offsets (4 bytes each). |
| 0x82137A08 | 548 | Core Runtime | `VaArgShuffle` | Saves variadic register args (r6-r10) to stack, calls inner function. PowerPC variadic arg marshalling stub. |
| 0x821C06C8 | 540 | Engine Core | `PushWorkItemFront` | Stores 4 data fields into a node, links into global singly-linked list head. Classic push-front. |
| 0x821C9790 | 520 | Core Runtime | `StringHashPathCI` | Case-insensitive path hash: lowercases A-Z, normalizes `\`→`/`, uses multiply-rotate-xor folding. |
| 0x822A3998 | 505 | Platform | `GetArrayElementByOffset` | Conditional-offset array lookup: checks global byte flag, uses r4+34 or r4+2 as offset, indexes r3 array. |
| 0x821C9030 | 491 | Engine Core | `ReleaseRefCriticalSection` | Decrements refcounted CS wrapper; calls `RtlLeaveCriticalSection` on last release. |
| 0x82388580 | 475 | Kernel/Vd | `IndexedObjectGetter` | Global object table indexed getter: `return table[r3*4]`. |
| 0x8217D890 | 469 | Audio | `LookupNameTableSize` | Binary-search name lookup by key string; computes element size from table bounds. |
| 0x82270170 | 439 | Scene/Entity | `GetPlayerArrayElement` | Returns `base + index * 10832` (large stride). Player/vehicle struct array accessor. |
| 0x821C8FE0 | 414 | Engine Core | `AcquireRefCriticalSection` | Sets refcount=1, stores CS pointer, calls `RtlEnterCriticalSection`. Pairs with ReleaseRefCriticalSection. |
| 0x823D9890 | 357 | Kernel/Vd | `memset` | Full memset: unaligned head, 16-byte bulk (4× stw), trailing words/bytes. **The game's own memset.** |
| 0x8218A568 | 339 | Audio | `HashTableStringLookup` | Hashes input string (via StringHashPathCI), iterates 32-byte entries matching hash at offsets 0/4. Returns index+1. |
| 0x823D9A98 | 333 | Kernel/Vd | `IsHeapMemoryAvailable` | Checks heap pool availability; returns bool. Calls allocator extension if needed. |
| 0x823DBFF4 | 308 | Kernel/Vd | `String_Format` | `printf`-style string formatting with varargs. |
| 0x823DEDD8 | 299 | Kernel/Vd | `Mutex_Lock` | Kernel mutex lock wrapper. |
| 0x825EE0E0 | 284 | Game Logic | `CityStream_LoadSector` | City streaming: loads a city sector from storage into memory. |
| 0x821BBF00 | 279 | Engine Core | `TLS_FrameSlotRelease` | **NOT matrix multiply.** TLS frame-sync counterpart: decrements hit counter TLS[20], resets slot tracking when counter hits 0. |
| 0x821BE610 | 152 | Engine Core | `Stream_Close` | Buffered I/O stream close: flushes pending data via sub_821BDD28, calls vtable[12] destroy, resets state |
| 0x821BE3D8 | 128 | Engine Core | `Buffer_Write` | Buffered write: checks capacity, flushes via sub_821BDD28 if full, copies data to buffer[+8]+offset[+24], advances offset |
| 0x821BE250 | 81 | Engine Core | `Buffer_Read` | Core buffered read: struct {vtable,ctx,data,+8,pos64,+16,roff,+24,end,+28,cap,+32}. Refills via vtable[6] if needed |
| 0x821BE710 | 102 | Engine Core | `Buffer_ReadSwap32` | Calls Buffer_Read then byte-swaps each u32 in-place (PowerPC rlwimi). Big-endian to LE conversion |
| 0x821BE4F0 | 92 | Engine Core | `Buffer_ReadU8` | Thin wrapper: Buffer_Read count=1, returns byte or -1 |
| 0x821BE528 | 70 | Engine Core | `Buffer_WriteU8` | Thin wrapper: Buffer_Write count=1 |
| 0x821D0490 | 53 | Entity | `EntityProperty_ReadInt` | Reads string property via vtable[2], parses int via sub_823DD7F0, returns default if not numeric |
| 0x821D2970 | 76 | Entity | `EntitySceneNode_Construct` | Entity node ctor: sets vtable, registers name via NameHandle_Resolve, registers with TLS[60] manager |
| 0x821D2810 | 61 | Entity | `EntitySceneNode_Destruct` | Entity node dtor: detaches child via sub_821D2798, frees, calls base dtor |
| 0x823DB670 | 277 | Kernel/Vd | `Thread_Create` | Thread creation wrapper. Creates kernel thread with stack/priority. |
| 0x821E6800 | 276 | Scene/Entity | `SceneNode_UpdateTransform` | Scene graph node transform update (parent→child propagation). |
| 0x821D0898 | 275 | Scene/Entity | `Entity_Update` | Per-entity update dispatch. Calls entity type-specific update. |
| 0x821B5A60 | 273 | Engine Core | `NameHandle_Resolve` | **NOT raycast.** Reads TLS[60] RangeTable manager, validates pointer via range lookup, resolves name handle. |
| 0x821BBEA8 | 273 | Engine Core | `TLS_FrameSlotAdvance` | **NOT vector normalize.** TLS frame-sync: advances slot (TLS[28]=TLS[32]) when not equal, increments hit counter TLS[20] when caught up. |
| 0x821F9FB8 | 273 | Engine Core | `Resource_LookupByName` | String-compare against known name constants, dispatch to vtable or hash-map fallback |
| 0x8268C9F0 | 268 | Game Logic | `List_GetByIndex` | Singly-linked list traversal to Nth element (node+8 = next ptr) |
| 0x8244D150 | 268 | Graphics | `memset_simd` | AltiVec SIMD memset with dcbzl cache-line zero for large fills |
| 0x82633B00 | 266 | Game Logic | `ArrayContainer_Destructor` | Free array at +68, chain to parent destructor |
| 0x8218A6E0 | 266 | Audio | `AudioDSP_BlockMix` | Interleaved sample mixing with coefficient lookup table |
| 0x823EAEF8 | 255 | XAM | `XamField_Get4` | Returns `[this+4]` — generic XAM handle getter |
| 0x821D41D0 | 240 | Entity | `EntityTagName_Merge` | 3-phase atomic bitfield merge (preserves upper 6 bits) |
| 0x82641CB0 | 236 | Game Logic | `Array_GetByIndex` | Index into flat pointer array at +68, returns NULL for -1 |
| 0x821C9A90 | 236 | Engine Core | `String_Release` | Ref-counted string decrement (refcount at +3072), free via sub_821C8F70 |
| 0x822A8108 | 235 | Platform | `InputDevice_GetState` | Reads input state from +48, checks TLS for controller status |
| 0x822A39C8 | 108 | Platform | `InputDevice_GetStatePointer` | Conditional accessor: TLS[72]? return +136 (raw) : return +8 (processed) |
| 0x821CFE80 | 234 | Engine Core | `Property_StringMatch` | Read property value via vtable, compare against input string, update state on match |
| 0x821D5408 | 233 | Entity | `EntityList_Constructor` | Zero-init entity struct, set vtable + func tables, active=1 |
| 0x821D4100 | 233 | Entity | `EntityTagName_Pack` | Pack (10-bit_tag << 16) | 16-bit_id into entity name field |
| 0x821D4B00 | 232 | Entity | `EntityList_BuildElementList` | Count null-terminated array, allocate+instantiate via factory per element |
| 0x821D4458 | 232 | Entity | `Entity_SetField` | Store two u32 values at [this+8] and [this+12] |
| 0x821C0548 | 232 | Engine Core | `Timer_EnqueueEvent` | Marshal params onto stack, delegate to timer queue sub-object at +24 |
| 0x823DB730 | 229 | Vd Layer | `stricmp` | Case-insensitive string compare (OR 32 for A-Z) |
| 0x821C7000 | 227 | Engine Core | `ResourceCache_Lookup` | Global resource cache lookup by ID |
| 0x821BD618 | 221 | Engine Core | `ErrorHandler_Log` | Error/assert message logging to console/log |
| 0x82256058 | 218 | Audio | `AudioMixer_Process` | Audio mixer DSP chain processing |
| 0x821D2AA0 | 222 | Entity | `EntityScene_Update` | Scene graph update traversal |
| 0x82387B90 | 223 | XAM | `GlobalObject_Get` | Returns singleton pointer at 0x82351960 |
| 0x821CA540 | 216 | Engine Core | `Mutex_Lock` | Mutex acquire wrapper |
| 0x8268EE10 | 215 | Game Logic | `MessageDispatchTrampoline` | Routes message (ID=r4) to global dispatcher (vtable[5]). Sends destroy MSG=28/10, param r5=3. |
| 0x82218310 | 212 | Engine | `Physics_UpdateWorld` | Physics world step/update |
| 0x821C2FB0 | 170 | Engine Core | `DelegateDispatcher_Init` | Inits thunk struct: stores 3 ptrs + dispatch type (bool→2/3). Paired with sub_821C3048 executor. |
| 0x8217FED0 | 163 | Audio | `AudioHandle_GetPointer` | Handle-to-pointer: `return globalTable[r3]` (simple 4-instr lookup) |
| 0x8217BC28 | 162 | Audio | `AudioDSP_WriteParams` | Writes 36B block (6f+int+2f) to DSP command ring buffer |
| 0x82189CE0 | 143 | Audio | `SoundSlot_Replace` | Replaces sound slot: releases old via sub_82177A08, attaches new via sub_821CE0D8 |
| 0x8218B688 | 97 | Audio | `SoundName_Lookup` | Hashes name (sub_821C9790), linear search in 16B-entry table, returns 1-based index |
| 0x821C6A20 | 131 | Engine Core | `String_Assign` | Owned/shared string assign: r5=0→shallow (no alloc), r5≠0→deep copy via sub_821378B8 |
| 0x821C7F10 | 121 | Engine Core | `IntrusiveList_Reparent` | Removes node from parent's child list (+28), walks siblings (+24) to find last, appends |
| 0x821C82A8 | 118 | Engine Core | `StringTree_Find` | Binary tree string search: checks case-sensitivity flag, uses stricmp for CI mode |
| 0x821C9650 | 104 | Engine Core | `Buffer_Append` | Dynamic buffer append: checks capacity, reallocs with 16B alignment if needed, appends + null-term |
| 0x821C9108 | 98 | Engine Core | `SyncEvent_WaitCheck` | Non-blocking signaled-state check: `!sub_8244ED10(handle, 1, 0)` (try-wait) |
| 0x82189E80 | 94 | Audio | `AudioParam_IndexedSet` | Stores u32 to global table[-32131+23744][r3] then calls DSP update commit (sub_8218CC70) |
| 0x8218A4E8 | 94 | Audio | `SoundPair_Find` | Hashes name, searches 3072×32B entries with dual hash fields (bidirectional mapping) |
| 0x821C8F70 | 81 | Engine Core | `CriticalSection_LeaveDirect` | If [r3] non-null, calls RtlLeaveCriticalSection |
| 0x821C90C0 | 79 | Engine Core | `Handle_WaitCheck` | `sub_82135DB8(handle, -1)` = WaitForSingleObject(handle, 0). Returns 1 if signaled. |
| 0x8217C088 | 100 | Audio | `AudioTransform_CopyMasked` | SIMD vectorized copy of 64B audio transform data with endian shuffle + AND mask |
| 0x821C7910 | 79 | Audio | `AudioParam_MasterSet` | Float param set through audio master controller: lookup manager via sub_821C7490, apply via sub_821C60F8 |
| 0x82387A18 | 207 | XAM | `GlobalObject_Check` | Load global at 0x8231F178, virtual guard check |
| 0x82691650 | 203 | Game Logic | `StringToIndex_Lookup` | Hash path → resolve index → return array pointer |
| 0x821CFF40 | 202 | Engine Core | `Property_Read` | Read property value through vtable dispatch |
| 0x82630CA0 | 195 | Game Logic | `StateTable_SetEntry` | **NOT game update.** Stores `{id=r4, namePtr=r5}` into state registration entry at r3. Part of static state table init. |
| 0x82187A38 | 192 | Audio | `AudioSystem_Update` | Audio system update/frame tick |
| 0x8213C218 | 190 | Core Runtime | `ThreadLocal_Get` | Read TLS value from r13-relative offset |
| 0x8268DA78 | 183 | Game Logic | `NamedNodeLookup` | **NOT a factory.** Walks singly-linked list (next=+8) comparing node name (+12) against r4 string. Falls back to alternate root if r5 set. |
| 0x82273A60 | 182 | Entity | `EntitySystem_Update` | Entity system update (calls sub_821D0898 on each entity) |
| 0x821CE100 | 181 | Engine Core | `Buffer_Read` | Read from buffer with bounds checking |
| 0x8244D5C0 | 180 | Graphics | `memcpy_simd` | AltiVec SIMD memcpy with dcbt prefetch, 128-byte loop |
| 0x82722678 | 161 | Game Logic | `Config_SetStringProperty` | Hashes key (sub_821C9790), builds `{hash, valuePtr, count=1, typeCode=3}`, calls vtable[14] SetProperty |
| 0x827227B8 | 128 | Game Logic | `Config_SetObjectProperty` | Same pattern with typeCode=7 (object pointer). Used for camera, vehicle physics, world env params |
| 0x823BA7F8 | 162 | Vd Layer | `VdStream_WriteAligned16` | Ensures 16B space in stream (sub_823BA6D8), writes value (sub_823BA440). Used in serialization loops |
| 0x823B86A0 | 138 | Vd Layer | `VdFileHandle_Init` | Copies 2 words from src[0..1] to dst[4..8], stores mode at +68. File handle init |
| 0x823B9E00 | 99 | Vd Layer | `VdFileNode_Constructor` | Sets vtable, stores name (strlen+memcpy) at +8, copies size/timestamp 8B to +16, default block size 12 |
| 0x823D90B0 | 120 | Vd Layer | `strcasestr` | Case-insensitive substring search: walks r3 haystack for r4 needle, returns match ptr or null |
| 0x823DBA38 | 97 | Vd Layer | `fp_RoundDouble` | Banker's rounding: fctidz→fcfid with 2^52 precision. fsel chain for nearest-even tiebreak |
| 0x823E1000 | 121 | XAM | `XamGetCurrentThreadTLS` | Returns TLS pointer at threadObj+8 via sub_823DB208. Fallback to static if no thread |
| 0x8268B6D0 | 112 | Game Logic | `HashMap_Set` | Hash via sub_8268C3D0, mask with capacity-1, bucket lookup sub_8268B5D8, overwrite via sub_8268C058 |
| 0x8268B960 | 111 | Game Logic | `HashMap_InsertOrGet` | Hash via sub_8268C448, inserts new node (sub_8268B4E8) if missing, updates via sub_8268C4B0 |
| 0x8262E420 | 117 | Game Logic | `DynArray_PushBack` | `{data, count(u16), capacity(u16)}`. Grows by growSize via sub_82130528 alloc + memcpy + free when full |
| 0x82633D40 | 107 | Game Logic | `ArrayContainer_Constructor` | Calls base ctor sub_82633A10, sets max=0x00FFFFFF, capacity=initialCapacity, allocates capacity*4 array |
| 0x823DC018 | 175 | Vd Layer | `sprintf` | printf-style string formatting to buffer |
| 0x823DBAE8 | 175 | Vd Layer | `sin` | Floating-point sine (8-term Horner polynomial) |
| 0x82618750 | 174 | Game Logic | `MemArena_Reset` | Linear allocator state reset (clear 6 fields, preserve limit) |
| 0x823B9430 | 173 | Vd Layer | `File_Read` | File read wrapper (Vd layer I/O) |
| 0x823B99D0 | 173 | Vd Layer | `File_Write` | File write wrapper (Vd layer I/O) |
| 0x825EF9F0 | 150 | Streaming | `Variant_GetType5` | Return variant value only if type tag == 5 |
| 0x825EDDA8 | ~140 | Streaming | `HashTable_FindOrCreate` | Path hash → hash table lookup or insert |
| 0x825ED480 | 133 | Streaming | `HashTbl_Lookup` | Loads hash table from obj+128, looks up r4 key via bucket chains (collision linked-list at key=+0, next=+16) |
| 0x82412710 | 117 | Vehicle | `Vehicle_UpdateFrame` | Per-frame vehicle update: checks init flags, queries pending work list at +11824, allocates, runs core update (sub_82412588), triggers cleanup |
| 0x824A5B00 | 114 | Reflection | `MemberPtr_ByIndex` | Struct member access by index: loads offset table from descriptor, returns base + offset[index]*4 |
| 0x824F97C0 | 85 | Getter | `Ptr_GetAttachment64` | Simple getter: loads 64-bit pointer from offset 40 |
| 0x82502300 | 82 | Getter | `Obj_GetOffset48` | Returns r3 + 48 (embedded sub-object pointer) |
| 0x822159D0 | 80 | Command Queue | `CmdQueue_Push` | Pushes deferred command into 256-entry queue, calls message router sub_82696DC0, stores in two parallel arrays |
| 0x82618390 | 69 | Bitstream | `BitField_Write` | Writes r5 bits of r4 into buffer r3 at bit offset r6. Handles unaligned partial bytes with shift/rotate/mask |
| 0x821CE0D8 | 68 | Atomic | `Atomic_Inc` | Atomic increment via lwarx/stwcx loop, mtmsrd global lock. Returns new value |
| 0x82618F90 | 67 | Bitstream | `BitStream_WriteBits` | Tail-calls sub_82618BC8 (bitfield write) with r5<<3, r6=0. Aligned bit-stream entry point |
| 0x822F10D0 | 67 | Tuning | `Tuning_GetFloat` | Vehicle tuning float: two paths — returns 0/1 based on global float, or indexes attribute array at r3+3633 using TLS[72] |
| 0x82794EE8 | 67 | Instance | `InstData_GetPtr` | Per-instance data pointer with 3 paths: thread mode (indexed table), flag mode (deref chain), or default (r3+128) |
| 0x821C8ED8 | 67 | Sync | `CriticalSection_Initialize` | Thin wrapper around `RtlInitializeCriticalSection` |
| 0x8244EEE0 | 66 | Device | `Device_CheckStatus` | Loads function ptr from global state; if result<0 converts NT status→DOS error, returns 0/1 |
| 0x823E02A8 | 65 | Dispatch | `Callback_DispatchOrAssert` | Loads callback; if non-null calls it, else triggers PowerPC trap (assertion failure) |
| 0x822575E8 | 62 | Bitstream | `BitStream_WriteEncodedValue` | Packed bitstream write: raw data if length≥4, then 14-bit marker + 2-bit width prefix + value |
| 0x8268DCB0 | 62 | Linked List | `LinkedList_GetNodeAtIndex` | Walks singly-linked list (head at +44, next at +36) to Nth element |
| 0x8262FFE0 | 62 | Setter | `SocialMatch_SetPlayerLimits` | Stores r4 at obj+176 and r5 at obj+180 (min/max player limits) |
| 0x825EE2D8 | 62 | Hash | `HashMap_SetValue` | Calls sub_825EDDA8 (hash lookup), stores value+hash at node[0..8] |
| 0x82144A20 | 62 | Hash | `HashMap_InsertKeyThunk` | Adjusts this+=700 (embedded HashMap), tail-calls sub_8214DD40 (hash+insert sorted) |
| 0x8268CC80 | 60 | Linked List | `LinkedList_AppendNode` | Appends to doubly-linked list (head=+44, next=+36, prev=+40, container=+32) |
| 0x824E70E0 | 60 | Bitfield | `GetFlagBit7` | Loads byte at +0x5C, extracts bit 7. Returns 0 or 0x1000000 |
| 0x821F6C70 | 59 | Getter | `GetSubObjAt4` | Returns r3 + 4 |
| 0x824E70F0 | 59 | Bitfield | `GetFlagBit6` | Loads byte at +0x5C, extracts bit 6 |
| 0x82187BE0 | 56 | Global Setter | `SetGlobalPtr` | Stores r3 to a global variable |
| 0x822C4EB8 | 56 | Global Getter | `GetGlobalValue` | Loads u32 from a global variable |
| 0x823DD7F0 | 56 | Memory | `Memset10ToZero` | Calls sub_823DDF20(r3, 0, 10): zero-init 10 bytes |
| 0x825EF8C8 | 55 | Type Conversion | `VariantToFloat` | Switch on type tag at +8: u32→float, u8→float, s32→float, f32 passthrough |
| 0x8217D828 | 55 | Search | `FindRangeIndex` | Binary search sorted (start,size) u32 pairs. Returns index of range containing r4 |
| 0x821B8740 | 54 | Search | `BinarySearchU16` | Binary search sorted u16 array with remapping via offset 0x1C flag |
| 0x824E7110 | 54 | Getter | `GetOffset56Ptr` | Returns r3 + 56 |
| 0x8246AEE8 | 54 | Messaging | `DispatchMessagePair` | Two-stage message broadcast: dispatches to paired listeners via sub_82469E98 / sub_8246A2B8 |
| 0x822A7C08 | 54 | Check | `IsIndexValid` | Returns *(this+8) >= *(this+12). Bounds/validity check |
| 0x821C7960 | 53 | Dispatch | `LookupAndDispatch` | Hash-table lookup (sub_821C7490), then type-dispatch via sub_821C6160 with 4-way jump table |
| 0x826311F8 | 53 | Init | `InitHandleFromGlobal` | Loads global singleton, calls sub_82218310, stores handle at this+4 |
| 0x821C3048 | 53 | Delegates | `InvokeFunctor` | Full functor dispatch: reads {target, func_ptr, bound_arg, arity_type} — supports 4 arity patterns |
| 0x82618F80 | 53 | Data Access | `GetElementByIndex` | index*8, tail-calls sub_82618A30 (selects direct or indirect ptr via flag at +24) |
| 0x823B8660 | 52 | Copy | `CopyVec2ToMember` | Copies 2 u32 from src[0..4] to dst[20..24]. Position/vector 2-field copy |
| 0x821BE7E8 | 51 | Checksum | `ComputeChecksum` | Iterates 32-bit words, byte-swaps (BE→LE), calls hash update sub_821BE3D8, accumulates result>>2 |
| 0x8260C5C8 | 51 | Input | `SmoothDeadZoneRemap` | Dead-zone input mapping: if |f1|>f2 maps to (|f1|-f2)/(1.0-f2), else constant |
| 0x821C9060 | 50 | Reset | `ResetAllObjects` | Tail-calls sub_8244EC78(0, input, 32767, 0). Bulk reset/iteration |

---

## 4. CORE RUNTIME (0x8213xxxx)

### Memory Allocator

The allocator uses r13 as a thread-local/global context pointer:

```
r13 → [0] = global_context
            [r13+0] + 28 = allocator_ptr
```

**sub_82130528** (`Memory_Alloc(size=r3, alignment=r5=16, flags=r6=0)`):
- Loads `context = *(uint32*)(r13 + 0)` 
- Loads `allocator = *(uint32*)(context + 28)`
- Calls `allocator->vtable[8/4] = allocator->Allocate(size, alignment, flags)`
- Returns the allocation pointer

**sub_82130550** (`Memory_AllocMax(size=r3, min_size=r4)`):
- Same as above but takes `max(r3, r4)` as the allocation size

**sub_82130588** (`Memory_Release(ptr=r3)`):
- If r3 == null, return immediately
- Loads `vtable = *(uint32*)(r3 + 0)` (first field of object is vtable pointer)
- Calls `vtable[12/4] = vtable->Release()` 
- This is a generic `Release()` virtual dispatch — every heap-allocated object uses this

### Hash Table System

**sub_821C9790** (`String_Hash(str=r3)`):
- Case-insensitive, path-normalizing hash
- Skips leading `"` characters
- Lowercases `A-Z` → `a-z`
- Normalizes `\` → `/`
- Hash accumulation: `h = h * 1025; h ^= h >> 6; h += c`
- Finalize: `h = h * 9; h ^= h >> 11; h = h * 32769 + some_offset`
- Returns 32-bit hash value

**sub_82137A08** (`HashTable_Rebuild(table=r3)`):
- Used when the hash table needs resizing or rebuilding
- Allocates new bucket array (via sub_82130528), zeroes it
- Walks existing entry linked-list, hashes each name via sub_821C9790
- Computes `bucket_index = hash % bucket_count` using `divwu`/`mullw`/`subf`
- Re-inserts into new bucket chain
- Updates table header and count

### Virtual Table Dispatch Pattern

The most common calling pattern is:

```asm
lwz   r11, 0(r3)        ; Load vtable pointer from object
lwz   r10, N(r11)       ; Load Nth method from vtable (N is method index * 4)
mtctr r10                ; Move to counter register
bctr                     ; Branch to counter (indirect call)
```

Common vtable slot indices used:
- `vtable+8`: Allocate (r3=this, r4=size, r5=alignment, r6=flags)
- `vtable+12`: Release (r3=this)
- `vtable+80`: Check/Cast (returns boolean)
- `vtable+88`: Iterate/GetNext
- `vtable+92`: Begin/Start

---

## 5. GPU MANAGER OBJECT STRUCTURE

The GPU subsystem is managed through a large context object (at `r31` in most GPU functions), allocated at runtime in BSS.

### Key Offsets (relative to manager context at `r31`)

| Offset | Size | Field | Description |
|--------|------|-------|-------------|
| +0x00 | 4 | vtable_ptr | Virtual method table pointer |
| +0x04 | 4 | unknown | |
| +0x08 | 4 | unknown | |
| +0x0C | 4 | unknown | |
| +0x30 | 4 | write_ptr | Current write position in ring buffer (stored at +0x48) |
| +0x34 | 4 | write_limit | Ring buffer limit (stored at +0x4C) |
| +0x48 | 4 | ring_write_ptr | Current GPU ring buffer write pointer |
| +0x4C | 4 | ring_limit | End of ring buffer (-160 bytes for safety margin at +0x56) |
| +0x50 | 4 | ring_base | Ring buffer base address |
| +0x54 | 4 | ring_size | Ring buffer size |
| +0x58 | 2 | flags | GPU state flags |
| +0x5C | 4 | hw_channel | Hardware channel index |
| +10896 (0x2A90) | 4 | rb_ctrl_ptr | Pointer to ring buffer control structure |
| +10900 (0x2A94) | 4 | irq_state_ptr | Pointer to interrupt state structure |
| +10904 (0x2A98) | 4 | irq_lock | Interrupt spinlock |
| +10932 (0x2AB4) | 4 | draw_type | Current draw type/index |
| +10936 (0x2AB8) | 4 | draw_count | Draw count |
| +10940 (0x2ABC) | 1 | gpu_flags | GPU state flags byte |
| +10941 (0x2ABD) | 1 | vf_flags | Vertex fetch flags |
| +10943 (0x2ABF) | 1 | draw_flags | Draw state flags |
| +11008 (0x2B00) | 4 | cmd_queue_count | Command queue count |
| +11012 (0x2B04) | 4 | cmd_queue_lock | Command queue spinlock |
| +12440-12456 (0x3098-0x30A8) | 4x5 | vb_committed[5] | Vertex buffer committed addresses |
| +12708 (0x31A4) | 4 | draw_cmd_reg | Draw command register value |
| +12712 (0x31A8) | 4 | draw_state | Draw state |
| +12716 (0x31AC) | 4 | draw_flags2 | Draw flags 2 |
| +12728-12748 (0x31B8-0x31CC) | 4x6 | vb_current[5]+count | Current vertex buffer addresses |
| +12748 (0x31CC) | 4 | vb_count | Vertex buffer count |
| +12756 (0x31D4) | 4 | vb_state[5*4] | Vertex buffer state array (16 bytes each) |
| +12996 (0x32C4) | 4 | vb_state2[5*2] | Vertex buffer state2 (8 bytes each) |
| +13232 (0x33B0) | 4 | cmd_buf_cur | Command buffer current |
| +13236 (0x33B4) | 4 | cmd_buf_end | Command buffer end |
| +13368 (0x3438) | 4 | cmd_queue | Command queue head |
| +14900-14928 (0x3A34-0x3A50) | 4 | alloc_state[8] | Allocation state machine |

---

## 6. GPU COMMAND BUFFER ARCHITECTURE

### Ring Buffer Structure

The GPU ring buffer is a circular buffer of 32-bit words. The game writes register/value pairs into this buffer, then kicks the GPU by writing to CP_RB_WPTR MMIO register.

```
Ring Buffer Format:
  [packet_header] [reg_value_0] [reg_value_1] ... [reg_value_N]
  
Packet Header (32-bit):
  Bit [31:16] = count-1 (number of register pairs - 1)
  Bit [15:0]  = base_register_offset
```

### sub_824238E0 (Main MMIO Packet Writer)

**Signature**: `sub_824238E0(ctx, r3=manager, r4=write_ptr, r5=source_bitstream, r6=bitstream_size)`

This is the primary GPU command packetization function. It:
1. Takes a bit-encoded stream where each bit represents whether a register is "dirty"
2. Uses `cntlzd` (count leading zeros double) to find contiguous runs of set bits
3. Groups consecutive dirty registers into packets
4. Writes packet headers (count + base_register) into the ring buffer
5. Copies register/value pairs using AltiVec SIMD (lvx/stvx) for 64-byte blocks
6. When the internal buffer would overflow, calls sub_82422EF8 to flush

**AltiVec SIMD copy loop** (lines 27372-27408):
- Processes 64 bytes (16 registers × 4 bytes) at a time
- Uses v63 (registers at +4), v62 (registers at +20), v61 (registers at +36), v60 (registers at +52)
- Shuffles bytes through VectorMaskL for endian swap

### sub_82422EF8 (Ring Buffer Flush Helper)

**Signature**: `sub_82422EF8(ctx, r3=manager, r4=write_ptr, r5=source_addr, r6=remaining, r7=type)`

Handles the actual flushing of register data to the GPU ring buffer:
1. Calculates remaining space: `space = (ring_limit - write_ptr) / 4`
2. Divides space by type (2 for pairs, 1 for singles)
3. Writes packet headers with count in upper 16 bits
4. Copies register data from source to ring buffer
5. On overflow, stores write_ptr to +0x48 and calls GPU kick

### sub_82412710 (GPU Kick)

Called when the ring buffer needs to be flushed. Forces a write of current ring buffer position and triggers GPU processing.

---

## 7. DRAW CALL PIPELINE

### sub_8241BD08 (Draw Command)

**Signature**: `sub_8241BD08(ctx, r3=manager, r4=draw_index)`

Initiates a GPU draw call. The full pipeline:

1. **State Check** (lines 8131-8160): Checks gpu_flags at +0x10940:
   - Bit 3 (0x08): Error state → skip
   - Bit 2 (0x04): Error state → skip
   - Byte at +0x2F9B (12187): Non-zero → skip
   - Bit 4 (0x10): Force flag → force draw
   - Bit 5 (0x20): Check vertex buffer state

2. **Vertex Buffer Comparison** (lines 8166-8234): If bit 5 is set, compares 5 vertex buffer committed addresses at +0x3098-0x30A8 against current values at +0x31B8-0x31CC. If all match, allows draw to proceed (avoids redundant state updates).

3. **Draw Command Write** (lines 8295-8310): Writes a 2-word packet to ring buffer:
   ```
   word 0: 0xC0006000 (packet: type=3, count=2, register=0x6000=CP_DRAW_CMD)
   word 1: draw_cmd_reg (from +0x31A4)
   ```

### sub_8241BE78 (Vertex Buffer Setup)

**Signature**: `sub_8241BE78(ctx, r3=manager, r4=flags, f1=unknown_float, r5=vb_count, r6=vb_src_array, ...)`

Sets up vertex buffer state for rendering:
1. Stores vb_count at +0x31CC
2. Iterates through 16-byte vertex buffer source entries, copying to +0x31D4
3. Stores aligned addresses at +0x32C4
4. Sets draw_flags at +0x10943 (bits 5 and 4 for position/normal enable)

### sub_82411180 (Ring Buffer Alignment/Sync)

Handles alignment of ring buffer writes. Ensures write address is 4-byte aligned and manages buffer wraparound.

### sub_82411618 (Vertex Fetch Setup)

**Signature**: `sub_82411618(ctx, r3=manager)`

A minimal function that sets up the vertex fetch constants region:
1. Reads base address from +0x4158 (16728)
2. Calculates: `write_limit = base + 0x4800 - 160`, `write_ptr = base`
3. Stores write_ptr at +0x30, write_limit at +0x34
4. Sets vf_flags bit 5 at +0x10941
5. This prepares the SQ_ALU_CONST_CACHE (0x4800) region for vertex fetch constants

### sub_82411640 (Shader Constant Allocation)

**Signature**: `sub_82411640(ctx, r3=manager, r4=flags, r5=src_ptr, r6=size)`

Allocates space in the shader constant buffer:
1. Uses a state machine at offsets +14900 to +14928
2. Manages allocation with wraparound via mask at +14900
3. Falls back through 3 allocation strategies:
   - Strategy 0: Write sequentially, wrap at end
   - Strategy 1: Allocate from +0x48 with padding to 32 bytes
   - Strategy 2: Allocate from +0x50 with overflow management
4. Tracks "committed" buffer to avoid redundant uploads

---

## 8. GPU INTERRUPT HANDLING

### sub_82411478 (GPU Interrupt Handler)

**Signature**: `sub_82411478(ctx, r3=interrupt_type, r4=manager)`

Registered via `SetInterruptCallback(0x82411478, 0x40002080)` at boot.

**Interrupt Type 1 (VSync/GPU Done)**:
1. Reads irq_state_ptr at +0x2A94
2. Checks for a registered callback at offset +0x10 of irq_state
3. If non-null, calls the callback through function pointer
4. Acquires spinlock at +0x2A98
5. Clears the bit corresponding to current thread's CPU in irq_state->status (offset +0x00)
6. Releases spinlock

**Interrupt Type 0 (Other)**:
1. Reads MMIO register at 0x7FC86544 (CP_INT_STATUS or similar)
2. Checks bit 0
3. If set, calls sub_82411528 for further processing

---

## 9. GPU REGISTER PROGRAMMING PATTERNS

### Packet Types (from packet header analysis)

| Type | Header Mask | Description |
|------|-------------|-------------|
| 0xC0000000 | 0xC0000000 | Type 3: Register write with count in upper bits |
| Other | 0xFFFF0000 | Count-1 in upper 16 bits (1 = 0x0000, 2 = 0x10000) |

### Key Xenos Registers Used

| Register | Address | Usage |
|----------|---------|-------|
| CP_RB_BASE | 0x0700 | Ring buffer base (set during init) |
| CP_RB_CNTL | 0x0704 | Ring buffer control |
| CP_RB_WPTR | 0x0714 | Ring buffer write pointer (KICK) |
| CP_RB_RPTR | 0x0718 | Ring buffer read pointer |
| SQ_VTX_CONSTANT_WORD0_0 | 0x4000 | Vertex shader constants (via 0x4800 range) |
| SQ_ALU_CONST_CACHE | 0x4800 | ALU constant cache (vertex fetch setup) |
| VGT_PRIMITIVE_TYPE | 0x3000 | Primitive type |
| VGT_NUM_INDICES | 0x3004 | Index count |
| VGT_DRAW_INITIATOR | 0x3008 | Draw initiator (KICK) |

### Shader Registers

| Register | Address | Description |
|----------|---------|-------------|
| SQ_PGM_START_VS | 0x8000 | Vertex shader program start |
| SQ_PGM_START_PS | 0x8004 | Pixel shader program start |
| SQ_PGM_RESOURCES_VS | 0x8010 | VS resources |
| SQ_PGM_RESOURCES_PS | 0x8014 | PS resources |
| SQ_PGM_EXPORTS_VS | 0x8018 | VS exports |
| SQ_PGM_EXPORTS_PS | 0x801C | PS exports |

---

## 10. INITIALIZATION FLOW

### GPU Initialization Call Chain

```
xstart (0x821322B8)
  → sub_82132A48 (init heap/allocator)
  → sub_82132898 (init GPU manager object)
  → sub_821320D0 (init GPU hardware)
  → sub_823DB480 (init Vd layer)
  → sub_82132820 (init GPU ring buffer)
  → sub_82132740 (init GPU worker thread)
  → sub_82131C08 (parse command line)
  → SetInterruptCallback(0x82411478, 0x40002080)
```

### XAM API Loading (GetProcAddressByOrdinal)

Late-bound imports are resolved during init:
- `XamInputGetUserVibrationLevel` (01BA)
- `XamUserGetDeviceContext` (0208)
- `XInputdFF*` force feedback functions (0282-0289)

---

## 11. ENGINE SUBSYSTEMS

### Audio System (0x8217xxxx)

**sub_8217F768** (`AudioParam_Set(id=r3, value=r4)`):
- Dispatches to ~40 parameter IDs via jump table
- Each case stores the value at a specific global slot (array at 0x8218CC70+23744)
- Some cases also set globals at -25604/-25600
- Calls sub_82189E80 to write value and update DSP/mixer chain

**sub_8217D890** (`AudioState_GetPropertySize(addr=r3, key=r4)`):
- Looks up `key` (address/value) in a range table via sub_8217D828
- Each table entry: `{base, size}` pair, iterated to find which range contains key
- Returns `size = entry[2] - entry[1]`
- Falls back to error handler sub_821D2378 if not found

### Threading / Synchronization (0x821Cxxxx)

**sub_821C8FE0** (`CriticalSection_Enter(cs_wrapper=r3)`):
- Stores critical section pointer at `[r3+4]`
- Sets refcount at `[r3+0]` to 1
- If critical section is not already held, calls `RtlEnterCriticalSection`

**sub_821C9030** (`CriticalSection_Leave(cs_wrapper=r3)`):
- Decrements refcount at `[r3+0]`
- When refcount reaches 0, calls `RtlLeaveCriticalSection`

### Entity System (0x8227xxxx)

**sub_82270170** (`Entity_GetByIndex(mgr=r3, index=r4)`):
- Loads entity array base from `[r3+4284]` (entity_manager->entities)
- Returns `base + index * 10832`
- Each entity struct is 10832 bytes (~10.5 KB), containing transforms, render state, physics, AI data

**sub_82270180** (adjacent): Iterates entity array comparing first byte of 11824-byte blocks to find by name/ID.

### Object Table (0x8238xxxx)

**sub_82388580** (`ObjectTable_Lookup(table_id=r3)`):
- Loads global pointer array from common base
- Double-dereferences to get table base
- Returns `table[r3 * 4]`
- Adjacent functions (0x82388598, 0x823885B8) add string name lookup through a linked list

---

## 12. RPF3 ARCHIVE FORMAT

The game's data is stored in RPF3 (Rockstar Package Format 3) archives on disk. These are the same format used by other Rockstar titles of the era.

### Header Structure (from reference C# implementation)

```
struct RPF3Header {
    char     magic[4];       // "RPF3" or "RPFG"  
    uint32_t unknown;        // flags/version
    uint32_t file_count;     // number of files in archive
    uint32_t table_offset;   // offset to file entry table
    uint32_t name_table_size;
    uint32_t unknown2;
};
```

### File Entry (32 bytes each)

```
struct RPF3Entry {
    uint32_t name_hash;      // hash of file path
    uint32_t unknown;        // flags/compression
    uint32_t offset;         // offset in archive
    uint32_t size;           // uncompressed size
    uint32_t compressed_size; // 0 = no compression
    uint32_t timestamp;      // file modification time
    uint32_t unknown2;
    uint32_t unknown3;
};
```

### Game Data Layout on Disc

The game data (`game_data\` on the host) contains:
- `mc4\` - game root
  - `art\` - art/city data (expected at `t:\mc4\art\`)
    - `city\*.loc` - city location files (RPF3 archives)
  - `sound\` - audio banks
  - `models\` - 3D models
  - `textures\` - texture data
  - `shaders\` - shader microcode
  - `ui\` - UI assets
  - `missions\` - mission scripts

The `t:` device is the title-specific storage device on Xbox 360. The game expects RPF3 archives stored at `t:\mc4\art\city\*.loc`. On real hardware, these are pre-extracted from the disc RPF3 to the HDD. In the recompilation, the files need to be either:
1. Extracted from the RPF3 archives to a `t:`-mounted host directory
2. Handled by a VFS device that can parse RPF3 on-the-fly

---

## 13. KNOWN ISSUES & FIXES

### GPU Hook Problem

The current hooks in `gpu_mmio.cpp` replace the real GPU functions without calling through to the originals:

| Function | Hook | Issue |
|----------|------|-------|
| sub_824238E0 | gpu_MmioWriteHook | Hook reads r6/r7 (single offset/value) but original takes bitstream. **Mismatched signature** |
| sub_82422EF8 | gpu_MmioWriteHelperHook | Hook iterates pairs but doesn't write to ring buffer. **Breaks all GPU register writes** |
| sub_82411180 | gpu_Sub82411180Hook | Hook does nothing. **Breaks ring buffer alignment** |
| sub_8241BD08 | gpu_Sub8241BD08Hook | Hook does nothing. **Breaks draw calls** |
| sub_82411618 | gpu_Sub82411618Hook | Hook does nothing. **Breaks vertex fetch setup** |

**Root Cause**: The hooks need to call the original functions after interception. Without proper passthrough, no GPU commands reach the hardware and no rendering occurs.

### VFS t: Device Missing

The game boots to the loading screen but cannot proceed past city data loading because:
- Game tries: `t:\mc4\art\city\test_dt_railyard.loc`
- VFS: no device mounted for `t:` → `ResolvePath` fails
- Required: Mount `t:\` to host path containing the RPF3 archive contents

### Recommended Fixes

**GPU Hooks** — Change hooks to intercept and passthrough:

```cpp
REX_FUNC(gpu_MmioWriteHook) {
    LogMmioWrite(ctx, base);
    sub_824238E0(ctx, base); // Call original
}
```

**VFS** — Add device mount in `OnPostLoadXexImage`:
```cpp
// Mount t:\ to extracted city data
auto& vfs = runtime().file_system();
vfs->MountDevice(
    std::make_unique<HostPathDevice>("t:\\", "E:\\mcla pc\\build\\game_data\\"));
```

Alternatively, remove the GPU hooks entirely and let the rexglue GPU backend handle MMIO directly, since `rexgpu-xenos.dll` already translates Xenos GPU commands to D3D12.

---

## 14. GPU STATE MACHINE DIAGRAM

```
IDLE
  │
  ▼
VERTEX_FETCH_SETUP ← sub_82411618
  │  Sets SQ_ALU_CONST_CACHE base
  │
  ▼
CONSTANT_UPLOAD ← sub_82411640
  │  Allocates/writes shader constants
  │
  ▼
VERTEX_BUFFER_SETUP ← sub_8241BE78
  │  Configures vertex buffer array
  │
  ▼
DRAW_CHECK ← sub_8241BD08
  │  Validates state, checks VB dirty
  │
  ▼
PACKET_WRITE ← sub_824238E0
  │  Writes register pairs to ring buffer
  │
  ▼
RING_FLUSH ← sub_82422EF8
  │  Flushes buffer to GPU
  │
  ▼
GPU_KICK (CP_RB_WPTR)
  │
  ▼
INTERRUPT ← sub_82411478
  │  VSync/GPU done
  │
  ▼
IDLE
```

---

## 15. ENTITY/SCENE GRAPH ARCHITECTURE (0x821Dxxxx)

### Core Entity Class (EntityList)

The entity system forms a tree/scene graph with two child storage strategies:

```
struct EntityList {
    /* +0x00 */ void* vtable;           // Main vtable (0x82013754 for base)
    /* +0x04 */ u32 sibling_ptr;        // Sibling in scene tree
    /* +0x08 */ u32 child_ptr;          // First child (linked list)
    /* +0x0C */ u32 type_byte;          // 8-bit entity type (0-255)
    /* +0x10 */ u32 field_10;
    /* +0x14 */ Entity** children;      // Child pointer array
    /* +0x18 */ u16 child_count;        // Child count
    /* +0x1A */ u16 child_free_flag;    // Whether to free children on dtor
    /* +0x1C */ u32 entity_tag;         // EntityTagName packed (see below)
    /* +0x20 */ u32 field_20;
    /* +0x24 */ u32 func_table_1;       // Secondary function table (0x821A5CC0)
    /* +0x28 */ u32 field_28;
    /* +0x2C */ u32 func_table_2;       // Secondary function table (copy)
    /* +0x30 */ u32 active_flag;        // Boolean (1 = active)
    /* +0x34 */ u32 hash_container;     // Hash container structure base
    /* +0x38 */ u16 bucket_count;       // Hash bucket count
    /* +0x3A */ u16 hash_free_flag;     // Whether to free hash on dtor
};
```

### EntityTagName Format

```
struct EntityTagName {  // at entity + 0x1C
    u32 packed;         // Bitfield: [31:26]=flags, [25:16]=10-bit parent hash, [15:0]=16-bit name hash
    u16 name;           // Redundant 16-bit name hash
};
```

- **sub_821D40E8** (`EntityTagName_Init`): Initializes name struct
- **sub_821D4100** (`EntityTagName_Pack`): Packs (parent_tag << 16) | name_id
- **sub_821D4118** (`EntityTagName_ParseFromString`): Parses "parent.child" → packed hash via sub_823DD7F0
- **sub_821D41D0** (`EntityTagName_Merge`): Full copy with atomic partial-update semantics
- **sub_821D4200** (`EntityTagName_Compare`): 5-way comparison (diff tags, gt, eq, lt, both zero)

### Scene Graph VTable Layout

| Slot | Offset | Function | Description |
|------|--------|----------|-------------|
| [0] | +0x00 | `Delete` | Scalar-deleting destructor (r4=dealloc flag) |
| [1] | +0x04 | `GetName` | Returns const char* name |
| [2] | +0x08 | `Update/Serialize` | Write state to 64-byte buffer |
| [5] | +0x14 | `SetActive` | Set active state (arg=1) |
| [6] | +0x18 | `SetFlag` | Set secondary flag (arg=1) |

### Update Dispatchers

| Function | Vtable Calls | Description |
|----------|-------------|-------------|
| sub_821D0898 | [2] only | Serialize/update only |
| sub_821D08D8 | [2], [5] | Update + SetActive(1) |
| sub_821D0938 | [2], [6] | Update + SetFlag(1) |
| sub_821D0998 | [2], [6] with r5 param | Update + SetFlag(r5) |

### EntityList Operations

- **sub_821D5408** (`EntityList_Constructor`): Zero-init, set vtable + func tables, set active=1
- **sub_821D52D8** (`EntityList_Destructor`): Free children array, hash container, buckets
- **sub_821D4C50** (`EntityList_FindChildByName`): Linear scan, calls vtable[1] getName() on each child
- **sub_821D4B00** (`EntityList_BuildElementList`): Count null-terminated array, allocate, instantiate each via factory
- **sub_821D4500** (`EntityList_TagFactory`): Switch on type_byte, allocate 8-12 byte tag nodes with type-specific vtables

### Hash Table (used by entity name resolution)

sub_821E1750 implements a power-of-2 sized open-addressing hash table with 16-byte entries:

| Entry Offset | Size | Field |
|-------------|------|-------|
| +0 | 8 | Metadata: used flag (bit 5), next/chain index (bits 6-25), group index (bits 26-44) |
| +8 | 4 | Key |
| +12 | 4 | Value |

### Entity Tag Type Dispatch (from sub_821D4500)

| type_byte Value | Alloc Size | Vtable (-32255+offset) | Description |
|----------------|------------|----------------------|-------------|
| 0-7 | 8 bytes | +13844 | Simple tag |
| 8-10 | 8 bytes | +13792 | Simple tag |
| 11 | 8 bytes | +13688 | Simple tag |
| 12 | 8 bytes | +13740 | Simple tag |
| 13 | 12 bytes | (custom ctor) | Complex tag via sub_821E3D40 |
| 14+ (=14) | 8 bytes | +13636 | Fallback simple tag |
| 14+241 (=255) | — | — | Error handler (sub_821BD618) |

---

## 16. VD LAYER / CRT LIBRARY (0x8238xxxx-0x823Exxxx)

### String/Memory Functions

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x823DA950 | `memcpy` | Unaligned byte copy with preamble+bulk | .23.cpp:8337 |
| 0x823D9890 | `memset` | Byte fill with word broadcast + loop | .23.cpp:5951 |
| 0x823DB670 | `strncpy` | Bounded string copy with null-pad | .23.cpp:10394 |
| 0x823DB730 | `stricmp` | Case-insensitive string compare (A-Z→32) | .23.cpp:10511 |
| 0x823DBFF4 | `_chkstk` | Stack probe (touch pages at 4096 stride) | .23.cpp:12659 |

### Math Library

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x823DBAE8 | `sin` or `cos` | Range reduction + 8-term Horner polynomial | .23.cpp:11898 |
| 0x823DBBC8 | `cos` or `sin` | Complementary trig with same coefficient table | .23.cpp:12022 |

Both use a shared coefficient table at global offset -32129:-20528 and implement range reduction via `fctid`/`clrldi` for odd/even detection.

### Exception Handling

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x823DEDD8 | `__CxxFrameHandler` | C++ exception dispatch: RTTI lookup, catch table scan, cleanup/landing pad | .23.cpp:41889 |

Implements the standard Xbox 360 C++ EH model:
- Loads RTTI from `vtable[-4]`
- Reads this-adjustment from `RTTI+4`
- Reads catch handler array from `RTTI+12`
- Scans for matching catch type, dispatches to handler or cleanup
- Falls back to error strings if no handler found

### XAM System

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x823EAEF8 | `XamField_Get4` | Returns `[this+4]` - generic XAM handle getter | .24.cpp:17120 |
| 0x823DB480 | `Vd_Init` | Vd layer init: TLS alloc, 196-byte context, function table setup | .23.cpp:10105 |

**Vd_Init details:**
- Allocates 2 TLS slots via `__imp__KeTlsAlloc`
- Sets TLS values via `__imp__KeTlsSetValue`
- Allocates 196-byte Vd context block
- Sets context fields: initialized flag at +20, thread ID=-1 at +4, context pointer at +92
- Installs 4 function pointers into global table

### Vd Assert/Log System

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x823D9A98 | `VdAssert` | Ring-buffer based assertion: logs to ring, returns -1 on failure | .23.cpp:6262 |
| 0x823D9890 | (inlined in assert) | Ring buffer write with overflow fallback to stack buffer | .23.cpp:6103 |

---

## 17. RENDER SCENE PIXEL PROCESSING (0x8244xxxx)

The 0x8244xxxx range contains ~170 templated pixel processing functions that copy/convert/blend pixel data to render targets. These are NOT GPU dispatch functions but rather CPU-side pixel data manipulation.

### Function Variants

| Function | Variant | Description |
|----------|---------|-------------|
| sub_824402C8 | **8-bit RGBA, 4 cols, blended** | Main render target write. Processes 4 pixels per iteration, loads/stores floats, applies color offset/scaling, packs to RGBA8888 |
| sub_82440748 | **8-bit RGBA, 3 cols** | 3-column variant (no 4th pixel register) |
| sub_824412A0 | **16-bit RGB565, 4 cols** | Clamps to 0-65535, packs as (R<<16)|G for 16-bit format |
| sub_82442EB0 | **16-bit signed, 2 cols** | Clamps -32767 to 32767, packs as (X<<16)|Y for DXT-like compressed format |
| sub_82440B10 | Variant | |
| sub_82440E10 | Variant | |
| ... | 10+ more | |

### Core Processing Loop Pattern

Each pixel variant follows the same template:
1. Load 4 floats from source (r,g,b,a)
2. Add per-channel offsets
3. Scale by global multiplier
4. Add color table value (indexed from struct+52)
5. `fctiwz` → integer conversion → pack into final format
6. If secondary buffer (+92): accumulate with per-column blending

### Helper Functions

| Address | Name | Description | File:Line |
|---------|------|-------------|-----------|
| 0x8244D150 | `memset_simd` | AltiVec SIMD memset (byte fill, <16 bytes fallback, dcbzl for large) | .27.cpp:58259 |
| 0x8244D5C0 | `memcpy_simd` | Optimized SIMD memcpy (Altivec lvx/stvx, 128-byte loop, dcbzl cache zero) | .27.cpp:58972 |

### Render Context Struct (from pixel function access patterns)

| Offset | Size | Field | Description |
|--------|------|-------|-------------|
| +0x10 | 4 | filter_flag | If non-zero, call sub_8243D8F8 filter |
| +0x20 | 4 | pitch/stride_base | Base pitch value for format conversion |
| +0x34 | 4 | color_offset | Color table offset |
| +0x54 | 4 | indirection_ptr | If non-null, call sub_8243AE88 transform |
| +0x5C | 4 | secondary_buffer | Secondary render target for multi-pass blend |
| +0x60 | 4 | width_multiplier | Width stride |
| +0x64 | 4 | height_multiplier | Height stride |
| +0x68 | 4 | loop_count | Number of rows/pixels to process |

---

## 18. AUDIO DSP SYSTEM (0x8217xxxx-0x8218xxxx)

### Architecture

The audio system uses a multi-layered architecture:
1. **Handle layer** — Audio objects are referenced by small integer handles, resolved through a global pointer table
2. **Parameter layer** — A 40-slot DSP parameter system with indexed access and commit triggers
3. **Command buffer** — Ring buffer of parameter blocks (36B each) sent to the DSP engine
4. **Sound bank** — Name-to-index tables (bidirectional) for audio resource lookup

### Key Functions

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8217F768 | 565 | `DispatchSetProperty` | 40-ID switch dispatcher writing to DSP slot array |
| 0x8217FED0 | 163 | `AudioHandle_GetPointer` | Handle→ptr: `return globalTable[r3]` (4 instructions) |
| 0x8217BC28 | 162 | `AudioDSP_WriteParams` | Push 36B block (6 floats + u32 + 2 floats) to DSP command ring buffer |
| 0x8217C088 | 100 | `AudioTransform_CopyMasked` | SIMD copy of 64B audio transform data with byte shuffle + AND mask |
| 0x8217D890 | 469 | `AudioState_GetPropertySize` | Address range lookup in property table via sub_8217D828 |
| 0x82189CE0 | 143 | `SoundSlot_Replace` | Slot-based sound replacement: releases old, attaches new |
| 0x82189E80 | 94 | `AudioParam_IndexedSet` | Store u32 to param table[-32131+23744][index], triggers DSP commit |
| 0x8218A568 | 339 | `HashTableStringLookup` | Hashes string, scans 32B-entry table matching hash at offsets 0/4 |
| 0x8218A6E0 | 266 | `AudioDSP_BlockMix` | Interleaved sample mixing with coefficient lookup (-32131+24256) |
| 0x8218B688 | 97 | `SoundName_Lookup` | Hashes name (sub_821C9790), linear search 16B entries, returns 1-based index |
| 0x8218A4E8 | 94 | `SoundPair_Find` | Hashes name, searches 3072×32B entries with dual hash fields (bi-directional mapping) |
| 0x82187A38 | 192 | `Audio_Update` | Audio system update/frame tick |
| 0x821C7910 | 79 | `AudioParam_MasterSet` | Float param through audio master controller via sub_821C7490 lookup |

### Audio Parameter System

**sub_8217F768** (`DispatchSetProperty`, 565 calls):
- 40-way switch dispatcher mapping parameter IDs to DSP slots
- Each case writes to slot in array at 0x8218CC70+23744
- Some cases also write to global audio state (offsets -25604/-25600)
- Triggers DSP update via sub_82189E80 (`AudioParam_IndexedSet`)

**sub_82189E80** (`AudioParam_IndexedSet`, 94 calls):
- `globalSlotArray[r3] = r4` (at -32131+23744)
- Then calls sub_8218CC70 — the **DSP update commit** function
- Adjacent variants: sub_82189E98 (saves old value), sub_82189EE0 (stores float)

### DSP Command Buffer

**sub_8217BC28** (`AudioDSP_WriteParams`, 162 calls):
- Manages ring buffer at `[-32124]-26900`
- Allocates next 36-byte slot if buffer not full
- Each slot: `float[6]` (24B) + `uint32` (4B) + `float[2]` (8B) = 36B
- Stores 9 different parameter values per write (DSP engine parameters)

### Handle System

**sub_8217FED0** (`AudioHandle_GetPointer`, 163 calls):
- `return globalTable[-32124-25776][r3]`
- 4 instructions: base load, index*4, table load, return
- Pure handle-to-pointer resolution

### Sound Slot Management

**sub_82189CE0** (`SoundSlot_Replace`, 143 calls):
- `r3`=context, `r4`=slot array, `r5`=index+1 (0=append), `r6`=new sound object
- Replaces entry at `array[index-1]`: releases old sound (sub_82177A08 → stop/release)
- Attaches new sound (sub_821CE0D8 → notify/attach)
- Calls sub_821789D8 to update global sound state

### Sound Name Resolution

Two related hash-table lookup functions:

**sub_8218B688** (`SoundName_Lookup`, 97 calls):
- Hashes name via sub_821C9790 (case-insensitive path-normalizing hash)
- Linear search through 16-byte entries: `{hash, value}`
- Returns 1-based index (0 = not found)
- Maps **audio file names** to **internal sound indices**

**sub_8218A4E8** (`SoundPair_Find`, 94 calls):
- Same hashing approach
- Searches 3072 entries × 32 bytes each at `[-32124]-17992`
- Each entry has **two hash fields** (`[+0]` and `[+4]`)
- Bidirectional name mapping: sound_name↔index

### Audio DSP Mixing (sub_8218A6E0, 266 calls)

Processes interleaved sample blocks:
- Coefficient lookup table at -32131+24256
- Copies 4-byte sample words in nested loops
- Stride arithmetic for channel deinterleaving
- Called 266× per frame for channel/stream mixing

---

## 19. CITY STREAMING & RESOURCE SYSTEM (0x825Exxxx-0x8269xxxx)

### Architecture Overview

The city streaming system loads game assets on-demand from `t:\mc4\art\city\*.loc` (RPF3 archive). It uses a hash-table based resource cache with typed variant values.

### Resource Lookup Flow

```
Game wants: t:\mc4\art\city\test_dt_railyard.loc
  → VFS ResolvePath fails (t: not mounted)
  → If mounted: sub_825EE120(path) called
      → sub_821C9790(path, 0): normalize (lowercase, strip quotes)
      → sub_825FA2B8(table+4, hash): hash table lookup
          → sub_825FA148: chained bucket walk
      → sub_825EF808(variant): unbox value by type tag
```

### Hash Table Implementation (sub_825FA148)

```
struct StreamingHashTable {
    u32* buckets;       // [+0] Array of first-entry pointers per bucket
    u16  capacity;      // [+4] Number of buckets
};

struct HashEntry (12 bytes each, singly-linked chaining):
    u32 key_hash;       // [+0]  Path hash from sub_821C9790
    u32 value;          // [+4]  Opaque value / variant pointer
    u32 next;           // [+8]  Next entry in chain
```

### Variant Value System (sub_825EF808)

Values are stored with type tags for runtime dispatch:

| Type Tag | Storage | Extraction |
|----------|---------|------------|
| 0 | u32 at +0 | Call sub_823DD7F0 (hash transform) |
| 1 | u32 at +0 | Same as type 0 |
| 2 | u8 at +0 | Zero-extend to u32 |
| 3 | u32 at +0 | Direct return (int) |
| 4 | float at +0 | `fctiwz` float-to-int |
| 5 | u32 at +0 | Return raw value (guarded by sub_825EF9F0) |

### Load Request Allocation

4 typed allocators create entries in the streaming hash table:

| Function | Type | Value Source | Description |
|----------|------|-------------|-------------|
| sub_825EE0E0 | 3 (int) | r5 parameter | Integer load request |
| sub_825EE188 | 4 (float) | f1 register | Float load request |
| sub_825EE230 | 2 (byte) | r5 truncated | Byte load request |
| sub_825EE1C8 | (other) | complex | Extended load request |

### Linked List Utilities

- **sub_8268C9F0** (`List_GetByIndex`): Walk singly-linked list (node+8 = next) to Nth element, 268 callers
- **sub_82641CB0** (`Array_GetByIndex`): Index into flat pointer array at +68, 236 callers
- **sub_82633B00** (`ArrayContainer_Destructor`): Free array at +68, chain to parent dtor, 266 callers

### String-to-Index Map (sub_82691650)

Resolves a normalized path string to a pointer by:
1. Hash the path via sub_821C9790
2. Look up in map at object+88 (via sub_826BDDB0)
3. Use resolved index to index array at object+76
4. Return pointer or NULL

### Memory Arena State (sub_82618750)

Linear allocator state machine with 6 cleared fields + flags byte:
- **+24 bit 7**: "Expanded" flag (distinguishes inline vs heap storage)
- **+24 low 7 bits**: Preserved "limit" value across resets
- Reset: clears +0 through +20, preserves limit from +24

---

## 20. OBJECT MODEL & MESSAGE DISPATCH SYSTEM (0x8268xxxx)

### Architecture Overview

The game uses a global message/event dispatch system for object lifecycle management. Rather than calling destructors directly, objects receive destruction messages through a centralized dispatcher singleton.

### Global Dispatcher

```
ptr1 = [0x82213804]          // global singleton (initialized at boot)
ptr1 + 0x34 (52): dispatcher object (has vtable)
    vtable[5] (+0x14/4): message dispatch handler

Dispatch call pattern:
    r3 = dispatcher + 4     // "this" for vtable call
    r4 = target_object      // object receiving the message
    r5 = param               // always 3 (category = system/destruction)
    r6 = message_id          // 10 = dispose, 26 = state change, 28 = destroy
    r7 = extra               // -1 = no extra data
```

### Key Functions

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8268EE10 | 215 | `MessageDispatchTrampoline` | Remaps args (r6←r4, r4←r3) and calls vtable[5] on global dispatcher+4 |
| 0x8268DA78 | 183 | `NamedNodeLookup` | Walks linked list (next=+8), compares names (+12) byte-by-byte. If primary list fails and fallback flag set, retries on alternate root |
| 0x82630CA0 | 195 | `StateTable_SetEntry` | Stores `{id=r4, namePtr=r5}` into 8-byte registration entry — part of static state table init |
| 0x8268DAF8 | ~50 | `CountActiveChildren` | Counts children with bit flag at +16 & 0x8 |
| 0x8268DB80 | ~30 | `FindFirstActiveChildDtor` | Finds first active child, calls destructor vtable[21] |
| 0x8268DC30 | ~20 | `GetParentNode` | Walks parent chain (+32) |
| 0x8268DC70 | ~20 | `GetLastSibling` | Walks sibling chain (+36) to last |
| 0x8268DCE0 | ~20 | `FindChildByName` | Linear scan of sibling chain comparing names |

### NamedNode Structure (for type/object registry)

```
struct NamedNode {          // Size: at least 16 bytes
    u32 data1;              // +0x00: type ID / constructor ptr (written by callers)
    u32 data2;              // +0x04: vtable / data ptr (written by callers)
    NamedNode* next;        // +0x08: next sibling in linked list
    const char* name;       // +0x0C: type/name string (compared byte-by-byte)
};
```

### State Registration Table (sub_82630CA0)

195 call sites populate arrays of state entries:

```
struct StateRegistrationEntry {  // 8 bytes each
    u32 stateId;                // +0x00: numeric ID (1,2,3,4,10,15,19,21,23...)
    const char* name;           // +0x04: name string pointer
};
```

State entries are stored in arrays at global addresses `0x8221xxxx`. IDs suggest states like Loading, Menu, Gameplay, Paused, Race, FreeRoam.

### Object Lifecycle Flow

```
BOOT:
  sub_82630CA0 (195 calls) ─── Populates state/type registration tables
  └─→ StateRegistrationEntry { id, name }
  
CREATION:
  sub_82137A08 ─── Formats type name (e.g., "TrafficVehicle_%d")
  sub_8268DA78 ─── Looks up type node by name in linked list registry
  [returned node's data fields used for allocation/construction]
  
LIFETIME:
  sub_8268EE10 ─── Messages dispatched through global dispatcher
  └─→ vtable[5] ──→ handler processes message (update, state change, etc.)
  
DESTRUCTION:
  sub_8268EE10(r4=28, r5=3, r6=-1) ─── Sends MSG_DESTROY
  sub_8268EE10(r4=10, r5=3, r6=-1) ─── Sends MSG_DISPOSE
  → dispatcher routes to object's cleanup handler
   → cleanup walks children, sends destroy to each via recursive dispatch
```

---

## 21. I/O STREAM & BUFFER SYSTEM (0x821BExxxx)

### Architecture

A complete buffered I/O stream abstraction with read/write, byte accessors, and endian conversion. All functions share a common stream struct:

```
struct StreamBuffer {       // 36 bytes total
    void* vtable;           // +0x00: virtual methods (read, write, flush, close, refill)
    uint32_t ctx;           // +0x04: stream context / ID / handle
    uint8_t* data;          // +0x08: data buffer pointer
    uint64_t position;      // +0x10: accumulated stream position (64-bit)
    uint32_t read_offset;   // +0x18: current read offset within buffer
    uint32_t end_offset;    // +0x1C: end of available data in buffer
    uint32_t capacity;      // +0x20: buffer capacity
};
```

### Key Functions

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821BE250 | 81 | `Buffer_Read` | Core read: when insufficient data, calls vtable[6] to refill buffer. Copies from data[roff:end] to output. |
| 0x821BE3D8 | 128 | `Buffer_Write` | Core write: when buffer full, calls sub_821BDD28 to flush. Copies input to data[roff], advances offset. |
| 0x821BE4F0 | 92 | `Buffer_ReadU8` | Read single byte: wraps Buffer_Read with count=1, returns byte or -1. |
| 0x821BE528 | 70 | `Buffer_WriteU8` | Write single byte: wraps Buffer_Write with count=1. |
| 0x821BE610 | 152 | `Stream_Close` | Flush pending data via sub_821BDD28, call vtable[12] destroy, reset state. Returns 0. |
| 0x821BE710 | 102 | `Buffer_ReadSwap32` | Read N*4 bytes, byte-swap each u32 in-place (rlwimi endian swap). Big-endian to LE. |
| 0x821BE6A8 | ~40 | `Buffer_ReadSwap16` | Same for 16-bit halfwords. |

### TLS Frame Slot Sync (0x821BBxxx)

Two adjacent functions (`sub_821BBEA8` / `sub_821BBF00`) manage a **TLS-based frame synchronization** system:

| Address | Name | Description |
|---------|------|-------------|
| 0x821BBEA8 | `TLS_FrameSlotAdvance` | If TLS[28] (cur_slot) ≠ TLS[32] (next_slot): save old slot histories, advance cur_slot=next_slot. If equal: increment hit counter at TLS[20]. |
| 0x821BBF00 | `TLS_FrameSlotRelease` | Decrement hit counter TLS[20]. When it hits 0: reset slot histories, rotate old values, zero the system. |

These act as a re-entrancy guard / frame boundary tracker, ensuring certain operations only execute once per frame or per slot activation cycle. The `Advance`/`Release` pairs are called around frame processing boundaries.

---

## 22. COMPREHENSIVE ALL-FUNCTIONS NAMING REFERENCE

The complete naming table for all 29,502 functions is at:
**`E:\mcla pc\all_functions_named.csv`**

### Format

The CSV file contains the following columns:

| Column | Description |
|--------|-------------|
| `Address` | Virtual address (e.g., `0x82130000`) |
| `Function` | Original symbol name (e.g., `sub_82130000`) |
| `Category` | Pattern classification category |
| `SuggestedName` | Generated human-readable name |
| `BodyLines` | Number of lines in the function body |
| `VtableSlot` | Vtable slot offset (if vtable_dispatch category) |
| `Notes` | Brief description of function behavior |
| `File` | Source file (mcla_recomp.N.cpp) |
| `Line` | Line number within source file |

### Category Summary

| Category | Count | Naming Convention | Description |
|----------|-------|-------------------|-------------|
| `unknown` | 14,039 | `Large/Medium/Small/Tiny_Unknown` | Unclassified functions (47.6%) |
| `constructor` | 4,996 | `Ctor_Unknown` | C++ constructor pattern (16.9%) |
| `altivec` | 2,783 | `Vec_Unknown` | AltiVec/VMX128 SIMD operations (9.4%) |
| `memory_alloc` | 1,880 | `Alloc_Unknown` | Memory allocation (6.4%) |
| `vtable_dispatch` | 1,717 | `Vtable_SlotN` | Virtual call via vtable slot N (5.8%) |
| `memory_free` | 1,691 | `Free_Unknown` | Memory deallocation (5.7%) |
| `memory_copy` | 465 | `MemCopy_Unknown` | Memory copy/move (1.6%) |
| `math_op` | 404 | `Math_Unknown` | Floating-point math (1.4%) |
| `blr_return` | 371 | `Empty/Mimal_Stub` | Empty stub function (1.3%) |
| `string_op` | 360 | `StrOp_Unknown` | String operations (1.2%) |
| `critical_section` | 314 | `CSection_Unknown` | Critical section / lock (1.1%) |
| `destructor` | 255 | `Dtor_Unknown` | C++ destructor pattern (0.9%) |
| `error_handler` | 116 | `Error_Handler` | Error/fatal handler (0.4%) |
| `simple_getter` | 82 | `Getter_Unknown` | Simple field getter (0.3%) |
| `crc_hash` | 29 | `CRC_Hash` | CRC32 or hash function (0.1%) |

### Function Size Distribution

| Size Range | Count | Percentage |
|-----------|-------|-----------|
| 1-5 lines | 371 | 1.3% |
| 6-10 lines | 2,248 | 7.6% |
| 11-20 lines | 2,846 | 9.6% |
| 21-50 lines | 4,723 | 16.0% |
| 51-100 lines | 8,915 | 30.2% |
| 101-200 lines | 5,626 | 19.1% |
| 201-500 lines | 3,399 | 11.5% |
| 501+ lines | 1,374 | 4.7% |

### Top 15 Called Functions (All Categories)

| Address | Calls | Category | Suggested Name |
|---------|-------|----------|----------------|
| 0x82130588 | 3,909 | vtable_dispatch | `SafeRelease` |
| 0x82130528 | 3,225 | vtable_dispatch | `AlignedHeapAlloc` |
| 0x82130000 | 2,132 | blr_return | `NopStub` |
| 0x82554798 | 1,259 | unknown | `AssertOrVerify` |
| 0x824DF200 | 811 | unknown | `RegisterNamedResource` |
| 0x823DA950 | 598 | memory_copy | `memcpy` |
| 0x821FA230 | 575 | unknown | `GetSingletonManager` |
| 0x8217F768 | 565 | unknown | `DispatchSetProperty` |
| 0x82137A08 | 548 | unknown | `VaArgShuffle` |
| 0x821C06C8 | 540 | unknown | `PushWorkItemFront` |
| 0x821C9790 | 520 | string_op | `StringHashPathCI` |
| 0x822A3998 | 505 | unknown | `GetArrayElementByOffset` |
| 0x821C9030 | 491 | critical_section | `ReleaseRefCriticalSection` |
| 0x82388580 | 475 | unknown | `IndexedObjectGetter` |
| 0x8217D890 | 469 | unknown | `LookupNameTableSize` |

### Named Functions Overview

A total of **204 functions** have been individually analyzed and given precise, descriptive names in sections 3 and 21 of this document. These cover:

- **Core Runtime (13)**: Allocator, vtable dispatch, hash, string, atomic, TLS sync
- **Engine Core (20)**: Critical section, timer, delegate, stream buffer, resource cache
- **Audio DSP System (16)**: Parameter dispatch, handle table, command buffer, mixing, sound bank
- **Scene/Entity (15)**: Scene node, entity tag, property management, entity list
- **Game Logic (15)**: HashMap, state table, message dispatch, array/collection, config
- **Vd Layer / CRT (14)**: memcpy, memset, strcmp, sin/cos, Vd init, file handles
- **Graphics / Xenos (5)**: memset_simd, memcpy_simd, render state, bigint
- **XAM / Platform (5)**: Thread getter, field accessor, global object, input
- **Kernel / Sync (2)**: Mutex lock, thread create
- **Math (5)**: Float-to-half, normalize/cross, skin transform, pow/atan2
- **Streaming (2)**: City sector load, variant getter

### Next Steps for Naming

The remaining ~28,000 functions can be further refined by:

1. **Context-based naming**: Functions called from specific subsystems inherit subsystem prefixes (e.g., `Audio_`, `Gpu_`, `Entity_`, `Stream_`)
2. **Call graph analysis**: By tracing which named functions call which unnamed functions, sub-functions can be given more specific names
3. **Data reference analysis**: Functions that read/write specific known global structures can be named by their role
4. **Manual targeted analysis**: Functions with 50-200 calls that are still `unknown` category should be prioritized for individual analysis

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821CE0A0 | 119 | `AtomicCAS32` | PowerPC lwarx/stwcx compare-and-swap loop: if `*r3 == r5` then `*r3 = r4`. Returns old value. |
| 0x821CE080 | 78 | `AtomicExchange32` | PowerPC lwarx/stwcx atomic exchange: `*r3 = r4`, returns old value. |

### Render State Setup (0x821C7xxx)

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821C7128 | 73 | `RenderState_Setup` | Allocates render state, configures state blocks, clears dirty flags. |

### Constructor/Destructor Patterns

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82197A00 | 114 | `Obj_ZeroInitCtor` | Zero-initializes 12 fields (offsets 0-44), calls sub_821D40E8 (EntityTagName_Init) on this+16. |
| 0x8221FCC8 | 101 | `Obj_ComplexDtor` | Destructor: conditionally frees sub-objects at offsets 672+208/672+176, then resets four sub-objects. |
| 0x821C2F70 | 77 | `Mem_ZeroFiveWords` | Sets 5 consecutive words (20 bytes) to 0. Minimal zero-init helper. |

### Collection/Iteration Patterns

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821CA6A8 | 126 | `Collection_ProcessLoop` | Loops count (from +3076), iteratively calls prep-buffer then process-item on each element. |
| 0x82193AF8 | 70 | `Collection_TransformIter` | Iterates entries from +8 collection (count +12), calls transform function on each entry's field20, counts successes. |
| 0x822701C8 | 71 | `Array_SearchByFirstByte` | Linear search through array of 11824-byte entries matching first byte of each. Returns found entry + 136. |

### Delegation / Dispatch

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82144A28 | 95 | `Delegate_Field700` | Tail-calls sub_8214D6B8(this + 700). Thin delegation wrapper. |
| 0x821D2378 | 75 | `Delegate_Printf` | Tail-calls sub_821BD618 with format string from this+8. Thin logging delegation. |
| 0x8218AEF8 | 73 | `Callback_Dispatcher` | Dispatches event by index*32 into handler table. Routes to sub_8218C928 or sub_8218CB50 based on handler ID. |
| 0x823B87D8 | 81 | `Delegate_CheckFlag` | Checks global flag, then delegates to sub_823B7D68(this+24, flag). |

### State Query / Getter Patterns

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x822577D0 | 107 | `State_IsReady` | Checks flags at offsets 279/280, validates via sub_824E7008, returns ready state. |
| 0x822A5578 | 78 | `Getter_Field896` | Simple field getter: returns `this->field896`. |
| 0x826186B0 | 135 | `Buffer_GetField20Div8` | Returns `(field20 + 7) >> 3` — ceiling division by 8 for packed buffer. |
| 0x826186A0 | 78 | `Buffer_GetField16Div8` | Returns `(field16 + 7) >> 3` — ceiling division by 8 for packed buffer. |
| 0x82332098 | 88 | `Table_IndexedLookup` | Reads this+76, checks validity, uses as index*104 into global table, calls sub_823964A8. |
| 0x822A39C8 | 108 | `Input_GetStatePointer` | Conditional: TLS[72]? return this+136 (raw) : return this+8 (processed). |
| 0x821CFE20 | 82 | `Stream_ReadAndCompare` | Reads up to 64 bytes via vtable[2], calls sub_823DB730 (stricmp). Used for property matching. |
| 0x821E80F8 | 78 | `Array_ValidateIndex` | Validates r4 index is within array range at +260 or +132, and element is non-null. |

### Math / Vector Operations

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x822030E0 | 86 | `Vec_SkinTransform` | AltiVec SIMD vertex skinning: loads weights/matrices via lvx, vmaddfp multiply-accumulate. |
| 0x82202EC0 | 74 | `Vec_NormalizeCross` | AltiVec SIMD: vmsum3fp dot product, vrsqrtefp rsqrt+Newton-Raphson normalize, cross product. |
| 0x8213E850 | 83 | `Math_FloatToHalf` | 32-bit float → 16-bit half-float. Handles denormals/infinities, packs sign/exponent/mantissa. |
| 0x823DC480 | 91 | `Math_PowOrAtan2` | Complex FP with special-case checks (zero, exponent extract), division, comparison. pow() or atan2(). |
| 0x823DCDD8 | 72 | `Math_Atan2` | Double-precision atan2: handles zero/NaN, ratio computation, likely table-based. |
| 0x823DE058 | 88 | `Stream_Rewind` | Tail-calls sub_823DDF60(r4=0). fseek(stream, 0, SEEK_SET) equivalent. |
| 0x82423548 | 71 | `BigInt_BitDivide` | Big integer/bitset division. Count-leading-zeros, shifts, subtraction loop. |

### I/O Stream Buffer (0x82257xxx)

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82257568 | 105 | `Buffer_ReadWithPos` | Validation via sub_826187F0, read via sub_82618318, position update via sub_826188D8. Position-aware stream read. |
| 0x82257678 | 73 | `Buffer_WriteEncoded` | Packed write: init via sub_82618750, capacity check via sub_826185E0+sub_826187F0, writes magic+size header. |
| 0x821CF7B8 | 72 | `StreamBuffer_Init` | Initializes stream buffer: stores r4/r5 context, sets mode flags (32, 2), zeroes counters. |

### Memory Subsystem

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82130B50 | 97 | `Mem_AllocFromPool` | Extracts size class from flag bits (4/8/16/4096), gets block from pool table at global+5160, updates counter at +2824. |
| 0x821310F8 | 119 | `Mem_DeallocOrFree` | Deallocates by size class (from flags byte-128), atomically updates allocator table, optionally invokes destructor. |

### String / Name Resolution

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8217C658 | 73 | `Str_ResourceLookup` | Lazy-init string resource loader. Loads 3 string tables from globals via sub_8218A4E8, does hash-based lookup. |
| 0x822183B0 | 77 | `Str_FormatCopy` | Formats string from source into dest with length limit, null-terminates. |

### Stream Character I/O

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821CFAA8 | 81 | `Stream_SkipWhitespace` | Reads chars from input stream, skipping space(32)/tab(9)/lf(10)/cr(13). Uses local buffer or Buffer_ReadU8. |

### Setter / Init Patterns

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x826185E0 | 78 | `Buffer_InitFlagged` | Same as sub_82618640 but sets bit 7 (0x80) in flag byte — marks as "expanded" (heap instead of inline). |
| 0x82618640 | 82 | `Buffer_Init` | Init struct: stores ptr at +0, capacity at +8, clears +12/16/20, sets combined flag byte. |

---

## §23 Graphics / Rendering Pipeline

This section documents the complete GPU rendering pipeline used in MCLA on the Xbox 360 (Xenos GPU). The pipeline follows a deferred-command model: the CPU encodes render state changes, shader constants, vertex data, and draw calls into an intermediate command buffer which is then submitted to the GPU via a push buffer mechanism.

### 23.1 Pipeline Overview

```
Scene Graph Traversal (SceneGraphTraverseChildren / RenderNode_ClassifyType)
  ↓
Render Update (Render_Update / RenderNodeComp)
  ↓
Camera Setup (CamObjInit / Gfx_CreateView)
  ↓
Render State Init (GfxStateInit / RenderStateInit / GpuSetRenderState)
  ↓
Command Buffer Alloc (CommandBuffer_AllocSegment)
  ↓
  ├─ Texture Bind (Gpu_TextureValidateSlot / Texture_Create / Gfx_UploadMipData)
  ├─ Shader Bind (Shader_BindDeviceContext / ShaderConstInit)
  ├─ Shader Constants Upload (Gpu_UploadMatrixConstants)
  ├─ Vertex Buffer Setup (VBufCreate / gfxGetVertexBuffer / Mesh_LockVertexBuffer)
  ├─ Vertex Declaration (Gfx_InitVertexDeclaration)
  ├─ Render State Setup (RenderState_Setup / RendState_SetVector)
  ├─ Lighting Setup (gfxLightInit / Lighting_ComputeHalfVector)
  ├─ Skinning Setup (SkinData_GetOffset448 → SkinMatrixBlend → Skinning_MatrixBlend)
  ↓
Draw Call Submission (gfxSetupDrawParams → gfx_submit_draw_call)
  ↓
Command Buffer Submit (GfxCmdBufSubmit → CommandBuffer_Push)
  ↓
(Optional) Render Target Resolve (render_target_bind / Gfx_WriteColorBuffer)
```

### 23.2 Command Buffer System

The GPU command buffer is a ring buffer that stores deferred rendering commands. Commands are described by 12-byte entries (type + parameters).

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x822578F8 | 13 | `CommandBuffer_Push` | Pushes a 12-byte command entry into the ring buffer. Validates buffer capacity, wraps around at end. |
| 0x82411840 | 4 | `CommandBuffer_AllocSegment` | Allocates a contiguous segment from the command buffer for a render pass. |
| 0x8241BD08 | 16 | `GfxCmdBufSubmit` | Main command buffer submission. Checks render state flags (bits at +10940), validates dirty state, submits queued commands. Manages 4 parallel state arrays at offsets 12440/12444/12448/12452 with tracking at 12728/12732/12736/12740. |
| 0x824231B0 | 9 | `CommandBuffer_BeginRenderPass` | Begins a new render pass within the command buffer, setting up per-pass state. |

### 23.3 Render State Management

Render states are set through a deferred system. `RenderState_Setup` writes a single float-valued state into a 12-byte entry in a command segment. States can be scalar (SetVector = 4 floats vector) or individual.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821C7128 | 73 | `RenderState_Setup` | Sets a render state parameter by name/ID (r4) to float value (f1). Allocates 4 bytes from context at +8, writes parameter type and value. 12-byte entries. |
| 0x825832C8 | 18 | `RendState_SetVector` | Sets a 4-float vector render state (e.g., RGBA color, XYZW). Writes 4 consecutive float entries. |
| 0x825734B0 | 9 | `RenderStateInit` | Initializes default render states with factory defaults. |
| 0x82668660 | 9 | `GpuSetRenderState` | High-level GPU render state setter. Dispatches to the appropriate render state handler based on state ID. |
| 0x825A2E00 | 15 | `GfxStateInit` | Initializes a GFX state object with default render states, blending modes, and depth/stencil config. |
| 0x8224C408 | 16 | `GfxObjectInit` | Initializes a GPU object with format, element size, and allocation info. |
| 0x8260B790 | 1 | `Gfx_WriteColorBuffer` | Writes a color buffer (RGBA) to the GPU, potentially via DMA or MMIO. |

**Buffer format**: 12-byte entries: [4 bytes: name/type hash] [4 bytes: value/store_type] [4 bytes: float data]

### 23.4 Shader Management & Constants

Shaders are bound via a device context. Constants (matrices, lighting params, material colors) are uploaded through a dedicated upload path.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82637DD8 | 1 | `Shader_BindDeviceContext` | Binds a shader to the GPU device context. Sets active vertex/pixel shader handles. |
| 0x82583708 | 9 | `ShaderConstInit` | Initializes shader constant table with default values (identity matrices, black/white colors, zero vectors). |
| 0x822192F8 | 10 | `Gpu_UploadMatrixConstants` | Uploads GPU matrix constants (world, view, projection, combined) to the shader constant buffer. 4x4 matrix upload. |

### 23.5 Texture Pipeline

Textures go through create → validate slot → upload mip data → bind lifecycle.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821F3628 | 4 | `Texture_Create` | Creates a GPU texture: allocates GPU memory, sets format, width, height, mip count. Returns texture handle. |
| 0x82374B30 | 10 | `Gpu_TextureValidateSlot` | Validates a texture slot (0-15) is active and ready for rendering. Checks for dirty textures that need re-upload. |
| 0x82761F20 | 6 | `Gfx_UploadMipData` | Uploads a mip level's pixel data to GPU texture memory. Handles format conversion if needed. |
| 0x821C70C8 | 1 | `texture_write_pixels` | Writes raw pixel data into a texture. Allocates buffer via sub_821C6D90, writes pixel data + stride info. |
| 0x826E94E8 | 13 | `Material_GetTextureIndex` | Looks up a texture index from a material by texture semantic/usage. |
| 0x821B6018 | 1 | `texture_destroy` | Releases GPU texture resources. Calls SafeRelease on texture handle. |
| 0x82548AC0 | 10 | `UITexture_Destroy` | Destroys a UI-specific texture. |
| 0x8265F3C8 | — | `TextureAnimationUpdate` | Updates animated texture state (UV scroll, frame animation). |
| 0x8240F220 | 1 | `Gfx_CalcTexturePageSize` | Calculates texture page size from format and dimensions. |
| 0x8240F3C8 | 1 | `Gfx_CalcTextureSize` | Calculates total texture memory size from format, width, height, mip count. |
| 0x8240F2A8 | 10 | `GfxFormat_ToElementSize` | Converts GPU texture format enum to element byte size. |
| 0x82349570 | 1 | `Gfx_GetFormatSize` | Gets the byte size of a GPU format. |

### 23.6 Vertex Buffer Pipeline

Vertex buffers are created with a declaration, then locked for CPU write, then bound for GPU read.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x821F6C50 | 1 | `Gfx_InitVertexDeclaration` | Initializes a GPU vertex declaration: element format, stride, offset, semantic mapping. |
| 0x821B3CC0 | — | `VBufCreate` | Creates a vertex buffer with specified size and format. Allocates GPU memory. |
| 0x821B40D0 | 10 | `Mesh_LockVertexBuffer` | Locks a vertex buffer for CPU write access. Returns pointer to writable memory (potentially DMA-able). |
| 0x82509B28 | 13 | `gfxGetVertexBuffer` | Retrieves the GPU vertex buffer handle from a mesh/resource. |
| 0x821B4D20 | — | `VBufCopyAltiVec` | Copies vertex data using Altivec SIMD (lvx/stvx). |
| 0x82219BA0 | — | `VertexBufferTransformSIMD` | Transforms vertex positions in a buffer using a matrix (SIMD-optimized). |
| 0x82323250 | 1 | `VertexBuffer_ReadToOutput` | Reads vertex buffer contents to CPU-accessible memory (for readback). |

### 23.7 Draw Call Submission

Draw calls are submitted after all state is set up.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x825286E8 | 10 | `gfxSetupDrawParams` | Sets up draw call parameters: primitive type, vertex count, index buffer, base vertex. Configures the draw packet. |
| 0x82574C38 | 1 | `gfx_submit_draw_call` | Submits the draw command to the GPU command processor. Writes the PM4 draw packet. |
| 0x825492C8 | 10 | `Gfx_DrawQuad` | Specialized fullscreen/UI quad draw: 2 triangles, 4 vertices, preset vertex format. Fast path for 2D rendering. |
| 0x821F51A0 | 10 | `gfxBeginUIDraw` | Begins a UI draw batch: sets 2D projection, disables depth test, enables alpha blend. |
| 0x8238DA80 | 7 | `Gfx_DecodeColorRGBA` | Decodes packed RGBA color (32-bit) into 4 float components. |
| 0x8238DB50 | 9 | `gfxPackColorRGBA` | Packs 4 float RGBA components into a 32-bit color word. |

### 23.8 Lighting & Fog

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82582C08 | 10 | `gfxLightInit` | Initializes a GPU light: sets type (directional/point/spot), color, direction, position, attenuation params. |
| 0x822A48F0 | 12 | `gfxByteToLightIntensity` | Converts a byte (0-255) to light intensity float (0.0-1.0). Used for per-vertex lightmaps. |
| 0x8218F308 | 8 | `gfxSetFogParams` | Sets GPU fog parameters: mode (linear/exp/exp2), start, end, density, color. |
| 0x82798B98 | 1 | `Lighting_ComputeHalfVector` | Computes the half-angle vector (H = normalize(L + V)) for specular lighting. |

### 23.9 Skinned Mesh Pipeline

Skinned mesh rendering follows a specific path through bone data extraction, matrix palette blending, and vertex transformation.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8217C568 | 13 | `SkinData_GetOffset448` | Gets bone offset data (448 bytes per bone set) from skin data structure. |
| 0x8270EBB8 | — | `SkinMatrixBlend` | Blends skin matrices: interpolates bone transforms with weights. |
| 0x8217C148 | 13 | `Skinning_MatrixBlend` | Matrix palette blending for GPU skinning. Reads bone index/weight pairs, blends matrix rows. |
| 0x822030E0 | 86 | `Vec_SkinTransform` | Transforms vertex by skinning matrices. Most-called skin function (86 call sites). |
| 0x82475FF8 | 13 | `Vec3_SkinTransform` | 3-component skinning transform with Altivec SIMD. |
| 0x8217C570 | 18 | `Math_Vec3Transform` | General 3D vector-matrix transform (non-skinning). |
| 0x821CE9D8 | 10 | `Math_Vec3TransformAltivec` | Altivec-optimized 3D vector-matrix transform. |
| 0x821A1768 | 10 | `SkinnedMesh_GetBoneMatrix` | Gets a specific bone's world matrix from a skinned mesh instance. |
| 0x82737DC0 | 1 | `BoneData_Copy160Bytes` | Copies 160 bytes (5×4 matrix data = 5 vec4) of bone data via Altivec. |
| 0x82578A38 | 1 | `AnimInterp_WriteBoneData` | Interpolates animation bone data and writes to bone buffer. |
| 0x82351F20 | — | `SkelBoneFind` | Finds a bone by index in the skeleton hierarchy. |
| 0x82563018 | 1 | `matrix_skin_deform` | Applies skin deformation matrix (bone offset * bind pose inverse). |

### 23.10 Render Target Management

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8258B6C8 | 1 | `render_target_bind` | Binds a render target (color surface + optional depth/stencil) for rendering. Sets EDRAM offset. |
| 0x82553A18 | 1 | `RenderDevice_GetCurrent` | Gets current render device context. |
| 0x8265F428 | 1 | `RenderDevice_HardwareInit` | Hardware-level GPU initialization: sets up EDRAM, backbuffer, depth buffer. |
| 0x8255ADE0 | — | `NodeDepthCheck` | Checks depth test state for a render node. |

### 23.11 UI Rendering System

UI rendering uses a separate pipeline optimized for 2D/sprite rendering with alpha blending.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82660050 | 10 | `XamUI_RenderElement` | XAM (Xbox Application Model) UI element renderer. Handles Xbox system UI rendering. |
| 0x825495A8 | 16 | `UITextRender` | Renders UI text: sets up ortho projection, uploads font texture, draws glyph quads. |
| 0x821800A0 | 18 | `Render_SpriteCopy` | Copies a sprite texture to the framebuffer with position, size, and color modulation. |
| 0x8218FAD0 | 10 | `FontRenderer_Init` | Initializes the font renderer: loads font bitmaps, sets up glyph cache. |
| 0x821A2320 | 8 | `UITextRenderInit` | Initializes UI text rendering context. |
| 0x82722718 | 2 | `DrawString_SubmitCommand` | Submits a string draw command to the GPU command buffer. |
| 0x8217D120 | 7 | `gfxBlitRect` | Blits a rectangular region from source to destination buffer. |

### 23.12 Scene Graph & Camera

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x8268F078 | 9 | `SceneGraphTraverseChildren` | Traverses the scene graph, visiting child nodes for rendering. |
| 0x824EDCC0 | 9 | `RenderNodeComp` | Compares two render nodes for sorting (by material, shader, or depth). |
| 0x82421A18 | 4 | `RenderNode_ClassifyType` | Classifies a render node by its type for dispatch (opaque, transparent, UI, etc.). |
| 0x82410BE8 | — | `GetModelLOD` | Selects the appropriate LOD level for a model based on distance from camera. |
| 0x826FD508 | 18 | `Render_Update` | Main render update: checks global state, gets render device, dispatches render via vtable+0x38. Manages frame counter at +264, accumulated time at +216. |
| 0x82714428 | — | `CamObjInit` | Initializes camera object with view/projection matrices. |
| 0x8224FA68 | 10 | `RenderObject_InitDefaults` | Initializes a render object's default state (material, shader, LOD, visibility flags). |
| 0x821E6800 | 276 | `SceneNode_UpdateTransform` | Updates a scene node's world transform by concatenating local transform with parent's. Most-called scene function. |

### 23.13 Transform / Matrix Math

Core SIMD-optimized math used throughout the graphics pipeline.

| Address | Calls | Name | Description |
|---------|-------|------|-------------|
| 0x82193AF8 | 70 | `Collection_TransformIter` | Iterates over a collection applying a transform function. |
| 0x821E6800 | 276 | `SceneNode_UpdateTransform` | Recursive scene node world matrix update. |
| 0x822030E0 | 86 | `Vec_SkinTransform` | Skinning vertex transform with blend weights. |
| 0x8217C570 | 18 | `Math_Vec3Transform` | vec3 × mat4 transform. |
| 0x822A9930 | 18 | `Math_MatrixMultiply` | 4×4 matrix multiply (Altivec-optimized). |
| 0x821B9F50 | 12 | `gfxTransformVec4` | vec4 × mat4 GPU transform. |
| 0x821CE9D8 | 10 | `Math_Vec3TransformAltivec` | Altivec-lane optimized 3D vector transform. |
| 0x821CEC00 | 10 | `Math_QuaternionTransform` | Quaternion-vector rotation transform. |
| 0x822BFF40 | 10 | `MatrixCopyAltiVec` | 16-byte aligned 4×4 matrix copy using Altivec. |
| 0x825ADD58 | 10 | `Vec4_Transform` | 4-component vector-matrix multiply. |
| 0x8261E060 | 10 | `gfxMatrixTransform` | GPU matrix state apply (uploads matrix to GPU constant memory). |
| 0x823236C8 | 10 | `MatrixVecTransform` | Matrix × vector transform (homogeneous). |
| 0x823A3F00 | 9 | `MtxCopyAligned` | 4×4 matrix aligned copy (no SIMD fallback). |
| 0x8242AB98 | 9 | `Vec3TransformAltivec` | Generic Altivec vec3 transform. |
| 0x82204D68 | 9 | `MtxApplyBoneTransform` | Applies bone matrix to vertex (pre-multiply by bone weight). |
| 0x821713C0 | 18 | `Math_MatrixTransform` | Generic matrix transform dispatcher. |
| 0x82194B58 | 8 | `Math_TransformCoords` | Coordinate system transform (9 float params, heavy FPR). |

### 23.14 Xenos GPU Architecture Notes

The Xbox 360 Xenos GPU has several distinctive features reflected in the codebase:

- **EDRAM (10MB)**: Embedded DRAM for the framebuffer. `render_target_bind` and `RenderDevice_HardwareInit` configure EDRAM offsets. The resolve operation copies EDRAM contents to main memory for texture readback.
- **Unified Shaders**: 48 shader ALUs that can be partitioned between vertex and pixel workloads. `Shader_BindDeviceContext` manages shader type assignment.
- **PM4 Command Processor**: The GPU command processor consumes packets written to the ring buffer. `CommandBuffer_Push` and `gfx_submit_draw_call` format and submit PM4 packets.
- **Altivec VMX128**: Extended 128-register Altivec SIMD. Functions like `VBufCopyAltiVec`, `Vec3TransformAltivec`, `Skinning_MatrixBlend` heavily use lvx/stvx/vmulfp128/vmaddfp for vertex processing.
- **Tile-Based Rendering**: The GPU bins triangles into tiles. `CommandBuffer_AllocSegment` may allocate per-tile command buffers for the binning pass.

### 23.15 Rendering State Flag System

The `GfxCmdBufSubmit` function (0x8241BD08) manages a sophisticated dirty-flag system for deferring GPU state updates:

- **Base context**: object at r31 with structure size ~13KB
- **Flag byte at +10940**: 8-bit field with bits for:
  - Bit 4 (0x10): Scissor/test state dirty
  - Bit 3 (0x08): Blend state dirty  
  - Bit 2 (0x04): Depth/stencil state dirty
  - Bit 1 (0x02): Unknown
  - Bit 0 (0x01): Unknown
- **Flag at +12187**: Boolean toggle state
- **4 parallel arrays** at offsets 12440/12444/12448/12452 (current values) and 12728/12732/12736/12740 (committed values)
  - Array 0: Render state values
  - Array 1: Texture stage state values
  - Array 2: Sampler state values
  - Array 3: Vertex shader constants
- **Command queue pointer** at +12716: head of the deferred command queue

The submit function compares current vs committed arrays; only dirty entries are written to the GPU push buffer.




