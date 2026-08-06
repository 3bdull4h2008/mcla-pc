# MCLA Coding Standards & Brand Voice

Applies to every agent session in this repo. Shorter than AGENTS.md is not a
target **here** — this file holds the detail so AGENTS.md stays lean.

## C++ / language

- C++23, `NOMINMAX`, MSVC `/utf-8`. Built with Ninja + clang-cl.
- Headers: include-what-you-use. Keep `.h` light; prefer `cpp` for logic.
- No exceptions in hot paths by default; the target uses `/EHa /GS-` — do not
  reintroduce fragile assumptions about stack layout.
- Prefer value semantics and RAII over raw `new/delete`. Use `std::span` for
  bounded views, never bare pointers to guest data.
- Do not add comments that restate the code; explain *why* where non-obvious.

## Guest memory & endianness (hard rules)

- Represent guest pointers as **32-bit guest addresses + bounds**, never host
  pointers. Type them `GuestAddr` / `GuestPtr<T>`.
- All guest reads go through the checked `GuestMemoryView` helper.
- Endianness is explicit at the boundary: `ReadU16BE`, `ReadU32BE`,
  `ReadF32BE`. **No `reinterpret_cast` on guest data**, ever.
- Every validated struct field must be backed by generated code or live
  capture evidence. Extend the documented `MclaGpuContext` only when a field is
  proven.

## Renderer ownership

- `NativeRenderer` is the *only* component that creates D3D12 resources,
  command lists, or pipeline state objects.
- Hooks capture and normalize state only. They must **not** call D3D12 and must
  **not** depend on `rex::graphics::RegisterFile`.
- A `DrawPacket` snapshots all state needed to execute; it never retains
  mutable pointers into the guest context.
- One hook owner per guest address. Compose observers via the dispatcher.
- A frame is native *or* legacy, never mixed — except an explicit
  capture-only mode.

## Validation discipline

- Every unsupported resource/format/state/shader emits a **deduplicated**
  diagnostic keyed by the feature, including capture frame + draw sequence.
- No invented draw counts, topology, or state. Unknown data is researched, not
  defaulted.
- A path is **not native** if it calls the Xenos command processor, submits
  PM4, or relies on guessed draw data.

## Brand voice

- Direct, evidence-based, concise technical prose.
- Report what was changed, what was verified, and what remains unknown.
- Say "native renderer" only when the path is actually native; otherwise say
  "compatibility/legacy path" or "experimental".
- Prefer "the validation gate requires/asserts" over "I think".
- Record unresolved guest-structure assumptions explicitly in handoffs; never
  bury them.

## Logging / diagnostics

- Low-noise in normal runs (e.g. one aggregate summary per N frames), verbose
  diagnostics behind flags (`native_renderer_trace = off|frames|all`).
- Log keys for unsupported features so cross-session dedup works.