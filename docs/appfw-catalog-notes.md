# appFw Playback Catalog Consumer: Bounded Offline Evidence

Date: 2026-11-12. This is a consumer-chain result, **not an explanation of the
current listing failure**.

## Scope And Preservation

- No F: access, no card snapshot or card writes. The explicit offline-only
  instruction superseded the normal pre-analysis card snapshot procedure.
- New files are confined to `analysis/appfw-catalog/` and this document.
  No main tools, shared Ghidra projects, or original binaries were edited.
- Source: `firmware/m4-v602/usr/lib/appFw.so`, 98,212,632 bytes, AArch64,
  little-endian ELF shared object, SHA-256
  `1e1b9202eaa69198f20df03dbfdab2f103b206cc4ebcd2e7bd817e6a710018a2`.
- All addresses below are **original ELF VMAs**. This independent Ghidra
  project uses **ELF VMA + 0x100000**, including data addresses in its C output.
- Project: `analysis/appfw-catalog/catalog.gpr`. Imported with `-noanalysis`;
  only selected functions were created/decompiled. Original `.eh_frame`
  contains only 344 FDEs and does not bound the principal wrappers here.
  Their boundaries were recovered from instructions, direct calls, and
  relocation targets. Broad reconnaissance ranges in `callers.json` are
  candidates, not a fully recovered function map.
- Primary evidence: `analysis/appfw-catalog/reviewed-evidence.json`,
  selected `.asm`/`.c` exports, and `routing-execution.json`.

## Actual Consumer Chain

The `libmpr` eight-byte `MprIf::GetEntryInfoList` stub is not used as evidence
for this UI chain.

| Stage | ELF VMA | Evidence / role |
|---|---:|---|
| UI-side callers | `0x27ceb14`, `0x27d1424`, `0x27d37bc` | Construct/update a sequence object via `0x2581d34`, then call `0x3596604` |
| Enabled sequence entry | `0x3596604` | Tests object `+0x90`; direct `BL 0x359529c` at `0x359662c` |
| Dataset update body | `0x359529c` | Embedded logs identify `sequence_update_data_set`, root datasets and playback counts |
| Main root tracing wrapper | `0x35a924c` | Direct `BL 0x3611020` at `0x35a9274` |
| Main root producer | `0x3611020` | `BL sidb::GetRootSet(count, ids, type, b0, b1, b2, set*)` at `0x36110b4` |
| Additional root producer | `0x35a928c -> 0x36110e8` | Non-representative root, `GetRootSet` at `0x361117c` |
| GeneralPlayback wrapper | `0x35a988c -> 0x3611774` | Separate reusable playback-root API; `GetRootSet` at `0x3611808` |
| Refine tracing wrapper | `0x35a964c` | Direct `BL 0x361f6bc` at `0x35a9674` |
| Refine dispatcher | `0x361f6bc` | Operation from request `+4`, source/destination handles at `+0x9c48/+0x9c4c` |
| Complex-filter builder | `0x3155838` | Builds operation `0x14/0x15` requests from enabled UI filter fields |
| Complex predicate | `0x3616fb4 -> 0x361615c` | Actual unique-ID predicate passed to imported `sidb::ComplexRefine` |

`0x3596604.c` has a misleading PIC/call-flow warning around the logger.
Use its original assembly, which unambiguously calls the dataset body and
returns, rather than trusting that particular decompilation's control flow.

## Root Request: Concrete Arguments

For `0x3611020`, the input request is `x0`, output is `x1`.

| Input field | Actual use |
|---|---|
| `+0x00` u32 | Count, passed in `w0` |
| `+0x04`, `+0x08` u32 | First two media IDs copied to a zero-initialized local ID array; its address goes in `x1` |
| `+0x14` u32 | Model root type mapped through bytes `00 01 05 06 07` at `0x4c1d378`, passed in `w2` |
| `+0x1c` byte | `w3`: require persistent content-record byte 6 bit4 |
| `+0x20` u32 | If exactly 1, overrides root type to 5 |
| `+0x24` byte | `w4`: include entries whose runtime on-memory bit1 is set |
| fixed 0 | `w5`: cancellation flag |
| fixed `0x8a9a180` | `x6`: result set; output handle `+0x2c` is 0 |

Invalid model root types default to sidb type 1 in this wrapper.
Its output `+8` is set size, `+0x30` is translated error status.

`0x3611774` maps model types `0,1,2,3,4` to sidb types `0,1,5,6,7`
using an actual jump table. It passes request bytes `+0x18/+0x19`
as `w3/w4`, fixes `w5=0`, writes set `0x8a9aeb0`, and returns handle 8.
The name is established by its assertion string at `0x4c20180`:
`infra_wrapper_mpr::detail::sidb_GetRootSetGeneralPlayback(...)`.
The name does **not** mean that all callers use the same Boolean flags.

### Main UI Producer Values

The dataset body constructs its main request at `0x35952e8..0x3595340`:

```text
count / media_ids <- object +0x18 / +0x1c / +0x20
model_root_type  <- get_rootset_type_from_order(object+0x38)
override         <- object+0x70
require_bit4     <- G
include_onmem1   <- true
cancellable     <- false
G = (object.byte[0x7c] == 0
     && object.u32[0x74] == 0
     && object.u32[0x78] == 1)
```

The gate is the complete original leaf function `0x3594a94..0x3594ab4`.
The order mapper `0x2e2c25c` maps order 0 to model type 1, order 1 to model
type 4; invalid orders assert then return model type 0.
Thus, absent the override, normal orders select sidb types 1 or 7.
`object+0x70 == 1` instead forces sidb type 5.

When `G` is true, the body can also call `0x36110e8` through `0x35a928c`
at `0x359543c`. This alternate producer forces `require_bit4=false`,
passes include-onmem from request `+0x1c` (set to true by this caller),
and returns handle 1 for set `0x8a9af10`.
Root rebuilding is skipped when object byte `+0x10 != 0` and byte
`+0x12 == 0`; downstream processing can therefore operate on cached sets.

## What Sidb Root Types Mean

Cross-checked against the original `libmpr.so` `GetRootSet` at `0x2a8760`,
not inferred from names:

- Common scan checks bitmap occupancy, record kind low nibble = 0,
  content type membership, valid media slot and database status = 3.
- `w3 != 0` requires **persistent raw record[6] bit4**.
- `w4 == 0` excludes **runtime gp_onmem[slot][record_index*4] bit1**.
  These are different storage locations and flags.
- Types 0/1/7 accept internal content types `{1,2,3}`.
  Type 5 accepts `{2,3}`; type 6 accepts `{1}`.
- Type 0 pushes IDs directly; types 1/5 use the date-view key,
  column `0x5c`; types 6/7 order by column 7. Type 7 handles multiple
  media sets separately before appending. Types 2/3/4 use other ordering keys.
- `ContentTypeInternal2ContentType`, ELF `0x28ab6c`, maps internal 1 to
  public 1, internal 2/3 to public 4, otherwise 0.

These root predicates do not inspect AVC slices or `RecordInfo+0x61a`.

## A Later Real On-Memory Filter

Root inclusion is **not the end of filtering**.
When `object.u32[0x84] == 0 && object.byte[0x10] != 0`, the update body
constructs operation `0x16` and calls the Refine wrapper:

- Main-root request: `0x359561c..0x3595690`.
- An extra analogous refinement is built for the alternate root when `G`
  is true, before the main-root refinement.
- Entire request size `0xa020` is zeroed.
- Operation `request.u32[4] = 0x16`.
- Source dataset handle at `+0x9c48`; output `+0x9c4c = 0x39`.
- **Comparison byte `request[8]` remains zero.**

Dispatcher switch table `0x4c1cfc8`, entry `0x16`, reaches `0x3622f50`.
That branch copies byte `request[8]` into a Boolean predicate and selects
column `0x68`. Shared call `0x36200f0` invokes:

```text
sidb::Refine<bool>(media_context, source_set,
                   COL_ID(0x68), byte_equals(false), destination_set)
```

The predicate invoke is original `0x3603908`:
`ldrb w0,[x0]; ldrb w1,[x1]; cmp w1,w0; cset w0,eq; ret`.
Its function-pointer relocation is GOT `0x59f6128 -> 0x3603908`.
The original libmpr on-memory Boolean reader at `0x28b3f4`
returns `(onmem_byte >> 1) & 1` for column `0x68`.
Therefore this branch really retains **on-memory bit1 == 0**.

Important correction to an intermediate hypothesis: the value returned by
`0x2ee59c8(0x1bd4)` is stored at **request+0xa018**, not request+8.
It is not this predicate's comparison value. Its exact property semantics
are not established here.

Output handle `0x39` is a scratch-selection sentinel, not a sidb column:
`0x3604370` maps it to `0x8a9a758 + operation*0x20`; other handles use
`0x3604010`. For operation `0x16`, the scratch set is `0x8a9aa18`.

## Other Actual Refinements

When object bytes `+0x94` and `+0x11` are both nonzero,
`0x3595704..0x3595718` calls:

```text
0x3155838(object+0x408, source_handle, 0x39, true, true)
```

The builder selects operation `(arg4 != 0) + 0x14`, thus `0x15` here.
It copies enabled date/group, content-category, format-mask, rating,
protection and transfer/mark filter parameters into the dispatcher request.
Examples of exact builder switch values:

- `input+0x194` values 0/1 select category masks 1/2.
- When the associated enable and category conditions hold,
  `input+0x19c` values 0..6 map to
  `{1,2,4,8,0x10,0x20,0x40}`.
- The movie-oriented branch is conditional, not an unconditional codec gate.
  Not every numeric mask was given a human-readable format name in this pass.

Dispatcher operations `0x14/0x15` share target `0x362129c` and call imported
`sidb::ComplexRefine` using callback adapter `0x3616fb4`, which tail-branches
to `0x361615c`. This callback evaluates optional predicate collections with
short-circuit rejection. Its category tests compare public content-type
column 0 with 1 and 4. **The leading object word `0xf` is not column 0xf**:
original `EquivalenceFunc<uint>::operator()` at libmpr `0x2a177c` reads the
column from predicate object `+4`.

Other modes observed directly in this same dataset update:

| Operation | Sidb behavior in `0x361f6bc` |
|---|---|
| `5/6/9` | `Refine<uint>` on column 2, comparison capture from request `+8` |
| `7/8` | `Refine<uint>` on column 2 with a collected-value predicate |
| `0x16` | `Refine<bool>` on runtime column `0x68`, as above |
| `0x1e` | `Refine<uint>` on column `0x5b` (media ID), captured request `+8`; explicit destination handle at request `+0xc` |

The update body subsequently publishes root handles/counts and playback
state through model properties, including IDs `0x1a5..0x1a8`.
Set membership/index checks also occur before choosing a playback item.
This is a multi-stage dataset pipeline, not just `GetRootSetGeneralPlayback`.

## Verification

`verify_routing.py` executes original appFw instructions with Unicorn:

- 32 controlled caller-state cases through `0x359529c`, stopping at
  `0x35956cc` after root/on-memory routing.
- 10 cases through original `0x3611020` to the imported root call.
- Assertions verify root type overrides, exact Boolean registers, conditional
  mode-`0x16` construction, zero comparison byte, and independence from the
  deliberately varied mock `0x1bd4` return.
- The caller cases use byte `object+0x12 = 1` to exercise root rebuilds;
  cached-set behavior was read statically, not covered by these cases.

**Database, logging, and model services are mocked.** Counts such as 42 in
this harness are test fixtures, not admission results for the 42 real movies.
This is separate from the parent's original-converter/reader tests.

Reproduction, from the workspace with `test311`:

```powershell
& 'E:/anaconda3/envs/test311/python.exe' analysis/appfw-catalog/verify_routing.py
& 'E:/anaconda3/envs/test311/python.exe' analysis/appfw-catalog/collect_evidence.py
```

## Unknowns And Integration

1. The actual runtime values of object fields `+0x10/+0x12/+0x70/+0x74/
   +0x78/+0x7c/+0x84/+0x94`, filter enables, source handles, and each
   candidate's on-memory bit1 were not captured. Numeric conditions above
   must not be converted into an assertion that the failing visit hit them.
2. No writer of on-memory bit1 was established in appFw. The completed
   direct-PLT survey has 19 BL and 3 tail B sites for `PartialUpdate<uint>`;
   inspected fixed and computed column families extend through
   `0x1c..0x33`, not 99/100/`0x68` (see the producer follow-up below).
   This negative result does not exclude indirect, inlined, or whole-record
   updates, or writers in other modules.
3. The complex filter's caller fields and callback were recovered, but its
   entire format-mask vocabulary and the current UI selections were not.
   A successful raw record conversion does not by itself establish passing
   these later predicates.
4. Parent reports all 42 movies have Mediapro Material, persistent bit4 = 1,
   and original nested readers returning 0. Thus this work does not identify
   persistent bit4 or reader failures as discriminators for this test round.
5. Parent also established raw record[6] bit3 -> `RecordInfo+0x61a`.
   That persistent bit is **not** raw bit4 and **not** runtime on-memory bit1.
   Its semantic label is unresolved. No root cause is assigned to `0x61a`,
   array72, or correlated positive/negative values.
6. Parent's converter can return 0 despite failed optional metadata readers;
   use its per-reader instrumentation. Parent's native completion path and
   MediaPro backend work remain independent evidence, not contradicted or
   replaced by this sidecar.

Completed result: a concrete UI producer -> wrapper -> sidb root/filter
chain, including a genuine conditional runtime `COL 0x68 == false` gate.
Not completed: proving which stage, if any, excluded the current clips.

## Follow-Up: Bounded Wholeflag Producer Search

This follow-up searched the **same appFw image**, not the already completed
root/refine consumer graph. The existing offline Ghidra project was opened
with `-noanalysis -readOnly`; analysis changes were discarded. New artifacts
have the `analysis/appfw-catalog/producer*` prefix. No F: access, parent-tool
edits, or original-binary edits occurred.

### Result

**No evidence-backed producer that sets recordInfo+0x61c bit1 was found
in this bounded appFw pass.** One genuine recordInfo write was established:
its initializer clears the entire word to zero. This is not a source of
bit1 becoming true and does not establish any write into sidb's live
on-memory table.

Dynamic-symbol and PLT inspection found:

- No defined or imported `sidb::Update` symbol.
- No defined or imported `sidb::GetValue` symbol.
- One `sidb::PartialUpdate` specialization:
  `PartialUpdate<unsigned int>(uint,uint,COL_ID,uint,bool,bool)`.
- No `PartialUpdate<unsigned char>` or `PartialUpdate<bool>` symbol.
- Exact byte-string searches for the mangled Update/GetValue prefixes,
  `whole_flag`, `wholeFlag`, `wholeflag`, and `onMemoryColumn` returned no
  matches. This does not rule out hidden/inlined implementations or
  indirect/dynamically resolved entry points.

### Complete Direct PartialUpdate Coverage

The scan included both `BL` and tail `B`, correcting the earlier BL-only
coverage statement. It found **19 BL + 3 B = 22 sites**, all targeting the
uint specialization at PLT `0x1717b90`.

| Original entry / region | Observed column family | Relevant evidence |
|---|---|---|
| `0x360cfcc`, leaf `0x360d08c` | `0x1c..0x24` | Format-mask branches select fixed columns; direct call and tail call |
| `0x360d104` | `0x1c/0x1e/0x20`, or `0x23/0x24` | Assertion/log label `sidb_PartialUpdateForFtpResultReset` |
| `0x360d228`, leaf `0x360d2f8` | `0x27..0x33` across the two entries | Additional `0x800/0x1000` cases select `0x32/0x33` in the leaf |
| `0x360d3c0` | `0x27..0x33` | Log label `sidb_PartialUpdateForSendToSmartphoneResultReset` |
| `0x360d598` | `0x32`, then `0x33` | BL `0x360d5bc`, tail B `0x360d5dc` |

In particular, **none of these routes selects uint column 99 (`0x63`),
u8 column 100 (`0x64`), or Boolean column `0x68`**.
The previous report's `0x1c..0x32` description was incomplete:
`0x33` is also present. This does not change the negative wholeflag result.

`producer_verify.py` runs original helper instructions under Unicorn with
Select/property-getter/PartialUpdate service effects explicitly mocked.
**572 routing cases cover all 22/22 sites**, including tail calls and reset
branches. This verifies argument construction, not database mutation or
camera behavior. The concrete per-entry column sets and sites are saved in
`producer-verification.json`.

Decompiler caveat: `producer-360d598.c` loses the second update after a
misidentified PIC call. The original `producer-0360d598.asm` and execution
trace show both updates; use those as the authority.

### recordInfo+0x61c Access Checks

The numeric-offset scan examined **8,542,706 aligned words** in `.text`
(`0x17187c0`, size `0x20967c8`). It selected integer
unsigned-immediate load/store encodings whose access spans byte `+0x61c`,
including wider accesses starting at `+0x618`.
It recorded **414 offset candidates**, not 414 typed recordInfo accesses.
Stack locations, unrelated framework objects, and unconfirmed instruction
boundaries are included in that candidate count.

Only seven bounded functions/regions were exported/decompiled for this
follow-up: the five PartialUpdate owner regions, recordInfo initializer,
and the sole exact non-stack byte-store candidate.

- **Actual recordInfo initializer**: `0x3609328..0x36094e4`.
  Instruction `0x3609454`, bytes `1f1c06b9`, is
  `str wzr,[x0,#0x61c]`. The same initializer independently clears
  bytes `+0x618/+0x619/+0x61a` at `0x3609430/34/38`.
  Its use before imported `sidb::Select` is visible in the existing bounded
  appFw export at Select call `0x3612528`.
  Original-instruction execution starting from all-ones storage confirms
  the word at `+0x61c` becomes zero.
- **Rejected offset collision**: `0x18950d8` is
  `strb w2,[x0,#0x61c]`, but `0x18950bc` first computes
  `x0 = x19 + 0x3000`. The actual enclosing-object offset is `+0x361c`,
  set to 1. Adjacent accesses and the enclosing `0x189505c` routine show
  a much larger object, not an established sidb recordInfo base.
  It is not evidence of wholeflag bit1 production.

The semantic distinction remains: recordInfo `+0x61c` carries the runtime
wholeflag word in the sidb path; its bit1 corresponds to the previously
established on-memory Boolean column `0x68`. This pass adds **no stronger
semantic name** for that bit and identifies no operation that sets it.
It must not be conflated with persistent raw record[6] bit3/bit4 or
RecordInfo `+0x61a`.

### Search Limits

The direct-link negative result is stronger than the numeric-offset search.
The latter is not an exhaustive, typed store analysis. It does not establish
coverage of rebased pointers (`base+0x600`, then `+0x1c`), register-offset
stores, paired/SIMD stores, copies, aggregate assignments, or all indirect
calls. The binary imports `dlsym`; absence of a named direct import is not
proof of absence of every possible runtime route.

Producers inside libmpr or other modules, and runtime captures of the
actual wholeflag transitions, remain outside this appFw-only pass.
No current listing failure is attributed to this flag, `0x61a`, or array72.

Reproduction:

```powershell
& 'E:/anaconda3/envs/test311/python.exe' analysis/appfw-catalog/producer_survey.py
& 'E:/anaconda3/envs/test311/python.exe' analysis/appfw-catalog/producer_headless.py
& 'E:/anaconda3/envs/test311/python.exe' analysis/appfw-catalog/producer_verify.py
```

### Parent Tail-Call Scan Cross-Check

The parent's `analysis/mpr-catalog-tailcalls-0021.json` was read as an
independent cross-check; the parent scanner was not rerun. Its appFw
`branch_kind: b` entries agree with this producer pass:

| Tail B site | Destination | Column evidence |
|---|---|---|
| `0x360d0dc` | `PartialUpdate<uint>` PLT `0x1717b90` | Format-dependent `0x1c..0x24` family |
| `0x360d364` | Same | Format-dependent `0x27..0x33` family |
| `0x360d5dc` | Same | `mov w2,#0x33` at `0x360d5d8` |

The producer-relevant libmpr tail entries are template forwarders from
`PartialUpdate<T>` to `PartialUpdate_i<T>`; they do not provide a new
column-selecting caller or a wholeflag producer. Neither scan adds
evidence for columns 99/100/`0x68`. The direct-call coverage boundary is
therefore B+BL, while the previously listed indirect/inlined/rebased-store
limitations remain unchanged. No additional execution tests were needed
for this documentary cross-check.
