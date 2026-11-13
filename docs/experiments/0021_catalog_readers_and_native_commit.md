# Experiment 0021: Catalog Readers And Native Commit Chain

Date: 2026-11-12, Asia/Shanghai.

## Current Physical Result

The user reports C6500-C6508 are currently **not listed**. Decoder playback
was not reached. C6503 is native footage, but is not an admitted playback
control. Positive examples are C6349-C6353, C5861-C5862, C0005 and C0007.
These are examples, not a complete listing inventory.

Playback body, installed firmware and active playback-view settings have not
been established. A sidecar's recording-device model is not the playback body.
No root cause has been established. Do not apply another catalog modification
from a single correlation, including shared array 72 or record byte 6 bit 3.

## Preservation

New read-only snapshot: `backup/snap_20261112T214535`.
It contains 62 copied metadata files and 123 skipped-media inventory entries,
with zero errors. Media contents were not copied; their timestamps and sizes
were inventoried.

`analysis/snapshot-213116-214535.json` finds no metadata hash/file-list changes,
no media size/mtime changes, no active-record changes and no header-word changes
relative to `snap_20261112T213116`. This is not evidence of a successful camera
mount or UI admission. No investigation tool wrote or deleted files on F:.

Closing snapshot `snap_20261112T230700` again has 62 metadata files, 123 media
inventory entries and zero errors. `analysis/snapshot-214535-230700.json`
finds no metadata content/file-list changes, no media size/mtime changes,
and no database active-record/header-word changes across this round.
This is not a hash of all old media or a raw-sector/global filesystem-I/O audit.

## Evidence Levels

Keep these separate:

1. User-observed camera listing.
2. Original firmware instructions executed against an offline snapshot.
3. Static firmware control-flow and relocation evidence.
4. File differences and host-side format checks.
5. Hypotheses requiring additional evidence.

Catalyst playback and ffprobe decoding are not substitutes for item 1.
Passing a helper or record conversion is not full database/UI admission.

## Original Reader Execution

Firmware: `firmware/m4-v602/usr/lib/libmpr.so`, SHA-256
`1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`.
All following firmware addresses are ELF VMAs; Ghidra uses VMA + `0x100000`.

`tools/emulate_sidb_readers.py` executes the original AArch64 bitmap,
checksum, path, binary-record and array-record routines in Unicorn. Only
`memcpy` and `strncpy` are modeled. It has no live-card filesystem access.

Offline snapshots 195043 and 213116 each pass all 19 header checksum regions.
All selected nonzero movie path/video/array references return zero. Optional
zero references are explicitly not called, not claimed accepted by a reader.
Evidence: `analysis/sidb-reader-tests.json`.

Twenty controls per snapshot cover every referenced array/slot pair, including
arrays 63 and 72. Bad record checksum, absent record bitmap and wrong array
subtype return `0x406`. Clearing only the requested slot bit and recomputing the
checksum still returns zero and copies the slot bytes in these cases. Do not
infer slot validation from this helper's name or the host's bitmap checks.

## Complete Original Record Conversion

`tools/emulate_sidb_converter.py` now executes original
`sidb::ConvRecordStructure2RecordInfo`, VMA `0x28e754`, and its original
path/attribute/UMID/date/enum helpers. Its libc boundaries are modeled and
logged. Original guest writes are restricted to emulated stack/output memory.
Relative ELF relocations are applied in emulator memory; code is not patched.

Evidence: `analysis/sidb-original-converter-0021.json`.

- Snapshot 195043: all 40 movies convert, no harness errors.
- Snapshot 214535: all 42 movies convert, no harness errors.
- All called path/binary/array readers return zero for the unmodified inputs.
- Main/NRT/thumbnail paths match the clip numbers, including known positive
  and negative examples. Proxy paths are restored where referenced.
- Fresh output is not the complete output of `sidb::Select`: Select appends
  drive bits and copies runtime on-memory flags separately.

Important negative-control result: the converter propagates corrupted path
record errors, but can still return zero after video-info or UMID-array
reading fails. For example, flipping the checksum of video record 81 or UMID
array 72 makes its nested reader return `0x406`, yet top-level conversion of
C6503 returns zero with missing/default metadata. These controls are now saved
in the report. Therefore a zero converter status alone is insufficient.

## Joined Movie Matrix

`analysis/catalog-listing-matrix-0021.json` joins the current snapshot, user
observations, sidecars, MEDIAPRO materials, media inventory, and original
conversion results. The converter's database SHA-256 must match before joining.

It contains 42 movies: 9 reported listed, 9 reported not listed, and 24 unknown.
All 42 have a MEDIAPRO Material and the persistent bit 4 used by the examined
GetRootSet inclusion condition. These checks do not distinguish the observed
groups. Runtime onmem flags remain unknown, not assumed read from disk.

Persistent byte 6 bit 3 maps to recordInfo offset `0x61a` at original
instructions `0x28e870`-`0x28e878`. It differs between several older and newer
examples. Its semantics and consumers remain unestablished here; no patch to
it is justified. In particular, the real recording-stop writer clears the
recordInfo first and does not visibly set that field in the examined routine.

## Real Recording-Stop Writer

The following is code evidence, not a reconstruction from file diffs:

`mpr::FileQueueStopCmp`, VMA `0xd5390`, in its normal media-present branch:

1. Opens, writes and closes the main NRT sidecar.
2. Calls MediaProfile wrapper `0x1819f8` to add a clip.
3. Performs optional additional sidecar/proxy and cube-file processing.
4. Calls RecordThumbnail when its corresponding flag is set.
5. Calls `mpr::UpdateMovieContentsForSidb`, VMA `0xd4718`.
6. Conditionally calls `sidb::Flush`, then another media helper.

This routine is after the writer's stop callback. It does not by itself prove
when the MP4's last bytes were closed, or that every optional branch executes.
The MediaProfile error branch logs and continues; the caller does not turn
that alone into an immediately established listing verdict.

`UpdateMovieContentsForSidb` clears recordInfo, fills content identity/date,
main/proxy video and audio metadata, stats the media, supplies paths/UMIDs/
other capture metadata, calls `sidb::Update(..., true, false)`, and updates the
packed-date header on success. It is distinct from
`RegisterM4RecordInfoOnSidb` (`0xb9848`), used by filesystem reconciliation.

Evidence:

- `analysis/decompile-mpr/001d5390_FileQueueStopCmp.c`
- `analysis/decompile-mpr/001d4718_UpdateMovieContentsForSidb.c`
- `analysis/native-recording-commit-chain-0021.json`, exact original BL sites.

## MediaProfile Implementation

`analysis/mediapro-vtables-0021.json` resolves six vtables from the original
ELF relocations. Analyst labels are explicitly identified as labels.
`tools/RecoverCatalog.java` temporarily recovers unrecognized functions in
the read-only Ghidra project, exports C/assembly, then discards project changes.

Concrete chain, still not a full mounted-camera trace:

- Wrapper `0x1819f8` dispatches through virtual offset `0x78` to `0x187010`.
- That converts clip info through virtual `0x318` (`0x189fcc`), calls parser
  virtual `0x40`, and updates the in-memory profile on success.
- The parser layers are CommonMediaProfileParser, its Impl, then state objects.
  Their source filenames are embedded in actual error-reporting call sites.
- Parser initialization reaches `0x18bc30`; M4 Impl initializer `0x190000`
  creates three state objects.
- State open routine `0x18e160` opens the profile, obtains size, invokes XML
  reader `0x192bc8`, and treats XML parse error `0xe` as failure.
- XML base reader `0x193fe8` uses `XML_ParserCreate`, installs original element
  callbacks, parses input chunks and returns `0xe` on Expat failure.
- State insertion routine `0x18c98c` serializes material XML, writes/inserts it,
  updates in-memory offsets/counts and drains its output buffer.
- Output helper `0x191d4c` seeks and writes a pending buffer. Its name must
  not be misread as a proven durable disk flush.
- File close helper `0x180cc4` has a `Fsys_Flush` branch according to open-mode
  bits, followed by `Fsys_Close`. Full transaction and backup selection remain
  to be traced through the state-specific virtual methods.

Exports: `analysis/decompile-mediapro/`, `analysis/decompile-mpr/`,
logs `analysis/ghidra-recover-mediapro-0021*.log`.
No repair, deletion, or writer routine was invoked against the card.

## Original Profile Parser Execution

`tools/emulate_mediapro.py` now loads the original M4 MediaProfile class and
the firmware's original AArch64 `libexpat.so.1.6.11` into Unicorn. Expat SHA-256:
`3d1e4818ad4c83228f2cad6496f6e46324c063c91713feb421544394c54be654`.
The XML parser and Sony element callbacks are not host replacements.

The model supplies bounded heap/libc services, a fixed hash-randomization seed,
and read-only virtual Fsys reads/seeks from the saved profile. No native Windows
module, camera service, physical device, or live card is executed. File-write
operations abort; read-only virtual flush/close have no host write side effect.
Constructor/load/query state lives only in emulator memory.

Current snapshot result:

- Original initialization and load both return zero.
- The original object builds 42 material records.
- Original lookup by clip number and original clip-info queries succeed for
  all 42, including C6500-C6508.
- Returned names, normalized URIs and parsed UMIDs match the source XML.
- Original executable sections remain byte-identical after execution.
- A malformed XML control returns load error `0x65`; renaming Material tags
  to an unknown tag yields zero registered materials despite well-formed XML.

Evidence: `analysis/mediapro-original-parser-0021.json`. The joined movie matrix
can bind it by the exact source XML hash. This tests the identified M4 6.02
implementation, not an unestablished firmware/body or the complete mount/UI.

## Actual UI Consumer

The completed appFw sidecar is in `docs/appfw-catalog-notes.md`. The parent
independently reran `verify_routing.py`: 32 caller-state and 10 wrapper cases pass.
Its database/model services are mocked; it is not a 42-clip admission test.

Actual chain: `sequence_update_data_set` -> root wrapper -> sidb, followed by
conditional refinements. The primary root producer permits runtime onmem bit1,
but a later conditional operation `0x16` really applies `COL 0x68 == false`.
This gate is distinct from persistent byte 6 bit4 and byte 6 bit3/recordInfo
`0x61a`. Optional complex filtering also exists.

The failing camera visit's mode fields, enabled predicates, cached sets and
candidate runtime flags have not been captured. The bit's producer remains a
separate investigation. Existence of the conditional gate is not evidence that
it excluded these clips. No new card patch follows from this alone.

## EDIUS Loaded-Writer Follow-Up

The independent EDIUS sidecar obtained a complete read-only runtime module
capture and validated its RTTI/vtables. Its final sealed packet remains at
`analysis/edius-catalog/live-mpeg-47056-20261112T134903Z/runtime-evidence-final.json`.
Raw and normalized-image hashes were independently checked by the parent.
No project/media/export was opened; process background filesystem activity
was not globally traced. EDIUS was left running without terminating user state.

The parent then used a separate no-auto-analysis Ghidra project on the
hash-pinned normalized image. It recovered **17 actual multi-instruction
function bodies**, unlike the earlier interrupted broad auto-analysis.
Source remains an analysis derivative, never an executable replacement.

New static evidence, all following addresses PE RVAs:

- In the same M4 profile/updater implementation at `0x237b80`, branch
  `0x23896c` concatenates the path with `.$$$`, then `0x23897c` calls
  `0x1b89a0` on that temporary path.
- `0x1b89a0` supplies `0x1021` stream flags to `0x440750`. The latter's
  local-file branch calls `SHCreateStreamOnFileW` at `0x4407cb`.
- `0x1b8f50` then invokes XML document virtual offset `0x210` at `0x1b9178`.
  The image's interface IID is `2933bf81-7b36-11d2-b20e-00c04f983e60`;
  local Microsoft SDK `msxml.h` independently identifies slot 66 as
  `IXMLDOMDocument::save`. The header hash is retained in the evidence packet.
- After a successful temporary save, `0x2389c7` calls the original-path
  removal helper `0x43c630`. Its local-backend sink is `DeleteFileW`
  at `0x4a9fa3`.
- The following success branch at `0x238a07` reaches move helper `0x440310`,
  which calls `MoveFileW` at `0x4403e0` for temporary-to-original replacement.
- The branch for a new path saves directly instead of replacing an old path.
  Error cleanup branches also exist.

Evidence: `analysis/edius-catalog/targeted-loaded/evidence.json`, original
assembly and preliminary C under that directory's `decompile/`.
`run.py` reproduces bounded recovery; `summarize.py` checks source identity,
the actual import-call instructions, suffix, IID and SDK save slot.

Limitations: C prototypes/return types inferred without broad analysis can be
incorrect; original assembly governs. Alternate backend branches exist.
This is not an observed export, a complete CExportXAVCS entry-to-commit trace,
a proven durable/atomic transaction, a full MP4/NRT/thumbnail sequence, or an
established Sony DATABASE.BIN writer. Delete then MoveFileW is not an atomic
replacement guarantee. No such deletion or write was invoked on the card.

## Remaining Gates

Before another card write:

1. Identify the playback body/firmware/view context.
2. Obtain the relevant runtime/caller context for the recovered list/filter chain.
3. Trace the relevant MediaProfile state-specific write/commit rules.
4. Cross-check any proposed fix against native writer code, existing positives,
   existing negatives, and a controlled test, preserving current card files.
5. Only after listing succeeds, evaluate generated Cat decoding separately.

The Cat package remains prepared as C6508; its current physical result is
NOT_LISTED. This work has not made it camera-playable.

## Verification

`python -m unittest discover -s tools/tests -q`: **114 tests passed**.
This includes original reader/converter cases, dependency-corruption controls,
original MediaProfile/Expat parsing and negative controls, and evidence-join
identity checks. It is not a camera admission or decoding test.

The appFw sidecar's additional 32 caller-state + 10 root-wrapper routing
cases were independently rerun and passed. Its producer follow-up also passed
572 routing cases covering all 22 direct uint-update sites, including 3 tail
branches. No wholeflag/column 99, 100 or `0x68` producer was established.
These mocked-service routing cases are not included in the 114.
The scoped `git diff --check -- docs tools` found no tracked whitespace issues;
the broader worktree check reports pre-existing trailing whitespace in AGENTS.md,
which was left unchanged.
