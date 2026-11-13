# Independent Review: Post-Reader Paths And Next Physical Samples

Date: 2026-11-13, Asia/Shanghai.

## Assessment

A C0007-derived structural-layout comparison is justified as an experiment,
not as a demonstrated repair. It must use matched encoded payloads and a
fixed identity-generation policy. The most useful additional isolated
variable is NAL-length framing: C6510 uses three-byte lengths; both C0007
and C6509 use four-byte lengths. This cannot explain every rejection:
C6509 already has four-byte framing and is physically rejected.

The actual `PlayingMovieErrorCb` is ELF **0x100a90**, not an inferred
similarly named reader helper. Its relocation and original instructions
were checked directly. It dispatches a state-dependent stop, not a
container/codec-specific explanation. No physical failing execution path
or root cause has been established.

## Scope And Evidence

- Read-only investigation of local media, ELF bytes, existing exports,
  reports and snapshot manifests. No access to F:, no new card snapshot,
  no sample generation/deployment, and no shared Ghidra project access.
  The only file written by this review is this report.
- Existing snapshot `snap_20261113T000418` contains 64 metadata copies,
  127 skipped-media inventory entries and zero reported errors. Its
  manifests are historical evidence, not a fresh audit of the current card.
- The current observation record confirms **ILCE-7M4** and C6507-C6510
  listed with normal thumbnails but rejected with "Cannot display".
  C0007's playback success is historical; a fresh playback check is needed.
  Earlier C6507/C6508 visibility ambiguity is not reinterpreted as causation.
- Binary: little-endian AArch64 ELF64 ET_DYN `libmpr.so`, SHA-256
  `1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`.
  Addresses below are ELF VMAs. Export filenames use Ghidra VMA = ELF +
  `0x100000`. Installed camera firmware is not established by this file.
- Local media hashes independently recomputed during this review:

| Local Input | SHA-256 |
|---|---|
| C0007 reference | `8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a` |
| Deployed-package C6509 | `abab47d3650607fcb185b57b1e1b1cca313b8b4d4f38f4161ac0b1c0be48b781` |
| Deployed-package C6510 | `18a2bc5e6a0c5839579304711b9177692494bff501dafecbe1eaf69b89a3890d` |

Methods: pyelftools for ELF symbols/relocations/segments, Capstone for
original AArch64 instructions, the local read-only ISO BMFF parser for
boxes/sample indexes, and in-memory builder comparisons. Python was run
with `-B`; no additional result files or code changes were produced.
Neither an emulator run nor a physical camera test was performed here.

## Error Dispatch: What The Callbacks Actually Say

### Shared Error Context

`FUN_001fe0e8` is ELF **0x0fe0e8**. The export and original instructions agree:

1. Null context returns without dispatch.
2. Status zero logs diagnostic `0x2312/0x51` with value `0xc9`; it does not
   invoke a success callback.
3. Nonzero status acquires the shared lock. An inactive context is logged
   and not dispatched.
4. For an active context, status is stored at **context+8**. Its callback
   at **context+0x10** is fetched and cleared under the lock.
5. After unlocking, the callback receives **context+4's u32 value, status**.
   This is one-shot per installed callback, not proof of a specific failure.

Registration at ELF **0x0fe3bc** stores the callback at context+0x10.
`SendMovieReaderStart` registers the playing callback after its selected
reader-start call returns zero. That is not evidence that all asynchronous
reading, transfer, or decode has completed.

### Verified Playing Callback

Dynamic symbol `_ZN3mpr11MoviePlayer19PlayingMovieErrorCbEjj` has
VMA **0x100a90**, size **180**. `.rela.dyn` at ELF **0x3027f0**
resolves to this symbol; this is the exported `PTR_PlayingMovieErrorCb`
at Ghidra `0x4027f0`.

Selected original instructions:

```text
100a94  mov w0, #3
100a98  mov w1, #0xc       ; incoming callback arguments are not preserved
100ae0  ldr w0, [x19]     ; current player state
100ae4  cmp w0, #1
100ae8  b.eq 0x100b34     ; ProcInPreparationInternalPbStop
100aec  cbz w0, 0x100af8
100af0  cmp w0, #5
100af4  b.ls 0x100b3c     ; ProcInPlayInternalPbStop for states 2..5
```

State 0 and states outside 1..5 take only the common logging/return path.
The two stop entries are **0x1008d4** and **0x1009cc**; both set player
state to 7 and call `SendCodecDecStop`. The preparation-stop path also
contains a `MoviePlayer::Callback` call with status 2.

Therefore the displayed generic error cannot identify a bad MP4, an AVC
syntax rejection, or a hardware-submission failure from this callback
alone. The Chinese UI-string mapping and failing camera state were not
traced. Capture the originating branch and context+8 before the stop path,
not merely entry into this callback.

### Different Origins Converge Here

| Origin, ELF VMA | Observed Static Behavior | Limit |
|---|---|---|
| `RecvCallbackDecodeError`, **0x0fec08** | Logs `0x2313/0x160`; dispatches fixed status **2** through playback-start context | Does not preserve a detailed codec error from its payload in this routine |
| `SendCodecDecStart`, **0x101fec** | Calls `Codec::DecStart`; nonzero result logs `0x352` and dispatches **2** | Synchronous start failure and asynchronous decode error can have the same outer status |
| `_open_file`, **0x1166d8** | Open/property failures dispatch their status; audio predicate dispatches **2**; selected seek error dispatches **4** | A status of 2 is not exclusively a hardware decode failure |
| Read worker, **0x115df8** | Presentation/video/audio/metadata/outband/read failures log underlying status under `0x2311`, IDs `0x1a04..0x1a09`, then dispatch **0xb** | Outer status loses the particular underlying failure |
| Reader owner worker, **0x114ac0** | Drive failure dispatches **0xb**; ready `0x114894` failure dispatches its returned status | These stages are not cleared by open/query success |

These are static routes, not a trace proving which route C6507-C6510 took.

## Beyond Descriptor Construction

The important untested sequence is not just another MP4-open predicate:

```text
0x115df8: SDK descriptors / outband -> raw file reads into ring/list storage
0x114894: queued metadata / presentation preparation -> MakeInfoList 0x10d7d8
0x11358c: Codec ES and information-list free-capacity checks
0x113ee8: ES transfer, PI updates, metadata/video/audio info-table transfer
          -> hardware/platform codec consumption and asynchronous callbacks
```

Specific distinctions from the existing probes:

- `_read_stream_from_file` at **0x110194** rounds the file start down to
  512-byte boundaries, rounds the read span up to 512 bytes and reserves
  ring memory on 4096-byte boundaries. It manages wrapping/list entries.
  Descriptor correctness alone does not exercise these reads or lifetimes.
- **0x11358c** checks aggregate ES capacity and information-list entry
  counts. A false result makes the owner retry; it is not automatically a
  media rejection.
- Video transfer at **0x113900** uses codec output lists and a virtual
  transfer interface through owner+0x1d78. At **0x113a58..0x113a70**
  it writes a **four-byte big-endian length** before out-of-band parameter
  data. Its ordinary frame branch transfers indexed byte spans, without
  a NAL-prefix rewrite visible in that branch.
- **0x113ee8** transfers metadata/video/audio records with strides
  **0x500 / 0x40 / 0x30**, then advances codec information write counts.
  This is beyond constructing those records in scratch memory.
- `TransferInfoTable` at **0x10c414** returns zero both after completing
  its loop and after encountering a destination smaller than the requested
  stride. Original branches at **0x10c474** and **0x10c488** verify this.
  Its status alone is not evidence that all entries were copied.

This is a reason to inspect actual transferred bytes, counts, destination
capacities and completion callbacks, not to claim a runtime buffer defect.
The four-byte outband prefix is also **not** proof that ordinary frame
NALs must use four bytes: the downstream codec's framing contract remains
unverified.

Existing evidence still stops short of that boundary: all 90 C6509 video
descriptors were cross-checked, but its table probe covers the first 30;
C0007 normal descriptors cover only 240/14,170 frames; C0007 and C6510
I-only table probes cover one frame each. Normal-mode budget expiry on
both C0007 and C6510 is an emulator timeout, not a discriminating rejection.

## Exact Offline Differences

The table below was checked against local media, not just descriptive docs.

| Feature | C0007 Historical Reference | C6509 Native Control | C6510 Generated Cat |
|---|---|---|---|
| `ftyp` minor version / final compatible brand | `0x01001fff` / `iso2` | `0x010b1fff` / `iso6` | Same as C6509 |
| First `mdat` payload | **192**, no leading `free` | **131072**, leading `free` size 130880 | Same start/prefix size as C6509 |
| `mdat` allocation | Payload plus framing, no comparable large unused tail | 67,108,880-byte box including a 64 MiB payload allocation | 87,401,025-byte box, no native allocation tail added by builder |
| Trailing `mdat` bytes beyond the final indexed sample | **0** | **60433204** | **0** |
| Top-level order | `ftyp, uuid, mdat, moov, meta` | `ftyp, uuid, free, mdat, moov, meta` | Same order as C6509 |
| Movie-level USMT `uuid` | Absent | Present, 46 bytes | Absent |
| Top-level `meta` children | `hdlr, xml ` | `hdlr, iinf, iloc, idat, xml ` | `hdlr, xml ` |
| RTMD sample size | **1024** | **19456** | **1024** |
| `avcC` length byte / NAL prefix | **0xff / 4 bytes** | **0xff / 4 bytes** | **0xfe / 3 bytes** |
| SPS/PPS arrays | SPS 48 bytes; PPS 87 | SPS 52; PPS 100 and 109 | SPS 54; PPS 5 |
| First access-unit NAL order | `9,6,6,6,5,5,5,5` | `9,6,6,6,6,6,5,5,5,5` | `6,9,6,6,5,5,5,5` |
| First / largest video sample | 100607 / 558605 bytes | 377144 / 377144 | 592726 / 787447 |
| Video `ctts` offsets present | 0,1001,3003 | 0,3003 | 0,1001,2002,3003 |
| Frame count | 14170 | 90 | 1534 |

NAL type 6 before the first AUD in C6510 is an observed ordering
difference, not a proven invalid stream. Larger samples likewise do not
establish a buffer limit. In particular, the `0x87f00` assertion in
`SetDecOpenParam` checks runtime buffer+0xd0, not a file sample length.
Neither sample maximum nor that constant alone establishes decoder capacity.

Important similarities: all three have video timescale 60000 and
1001-tick cadence, audio timescale 48000 and stereo 16-bit `twos`,
video edit media_time 1001, zero audio/metadata edit media_time, and
30-video-frame chunking except the final partial chunk. Their audio and
RTMD sample-description bytes and each corresponding track's 52-byte
USMT UUID are identical. C6510 is a **hybrid rebuilt layout**, not a
byte-faithful native recording or a complete C0007 reproduction.

### Do Not Blindly Copy C0007's PROF

Its child order is **FPRF, APRF, VPRF**, whereas the native reference uses
**FPRF, VPRF, APRF**. More importantly, C0007's VPRF payload starts:

```text
00000000 0000c350 0000c350 003bf0a6 ...
```

The native VPRF starts:

```text
00000000 00000001 61766331 0164002a ...
```

Under the field interpretation used by the current builder, the native
count and `avc1` positions instead contain `0xc350` in C0007. These are
literal byte differences consistent with historical in-place patching;
this review does not establish which reader consumes them or a universal
validity rule. They make C0007 a poor source for an unquestioned "canonical"
PROF descriptor. Keep a correctly constructed, payload-matching descriptor
for new encoded samples; preserve raw bytes only in a faithful reference
control.

## What The Current Structural Switch Actually Tests

The builder was read again after structural options appeared in the shared
working tree. Audited `build_sony_clip.py` SHA-256:
`8bc20ee01b1dec1b4135d0f4245c74881ae430a4024cf1b079527337414dd6a5`.
This observation does not cover later edits by other work.

Using the current pure builder functions, C6510's common sample indexes,
durations, entries and a fixed stamp of 12345, all three rebuilt tracks
and the rebuilt `mvhd` were **byte-identical** with C0007 versus C6359 as
structural template. This comparison used identical chunk offsets; it
did not write a media file or establish camera acceptance.

Consequently:

- `--structure-template` alone does not reconstruct historical coded
  video, original sample tables or original native metadata. In this
  inspected template pair its rebuilt track/header bytes do not differ.
- Together with `--payload-layout structure_template`, the meaningful
  layout changes are chiefly the `ftyp` minor/compatible brand and payload
  placement at 192 instead of 131072, plus consequent chunk offsets.
- PROF still comes from `--camera`; its ordering is not transplanted.
  Both branches regenerate minimal XML metadata and omit movie-level UUID.
- `avcc_normalize` and `normalize_sample` still explicitly select
  three-byte NAL lengths. Choosing C0007's structural template does **not**
  select C0007's four-byte framing or its SPS/PPS.
- `--umid-mode edius_uuid4` changes a separate factor: C0007 has label
  prefix `060A2B340101010501010D2313000000`, versus the native
  `...010D4313000000`. Do not switch UMID policy only on the structural
  arm and then attribute a difference to container layout.
- The inspected builder writes VPRF rate fields as **25000**. A future
  50 Mbps encode is not a properly labeled 50 Mbps control merely because
  its structural source is C0007.

## Concrete Physical-Test Recommendation

Reserve fresh clip IDs through the main workflow; none are asserted free
by this offline review. Preserve existing samples and take the required
card snapshot before any later deployment. No deployment is performed here.

First freshly play the unchanged C0007 on the same 7M4 visit. A normal
thumbnail or listing is not this positive control. Do not use C6503/C6509
as a known-playable control without a positive physical observation.

Recommended small batch, reusing the **same existing C6510 encoded NALs,
PCM and RTMD** rather than re-encoding for each arm:

| Arm | Change | Purpose |
|---|---|---|
| N3 | Retest existing C6510 unchanged | Same-visit failing baseline |
| N4 | Same native-aligned layout and NAL bytes, but every NAL length changes from 3 to 4 bytes; update `avcC`, `stsz`, offsets and box sizes consistently | Isolate packet framing, not AVC coding |
| E4 | Exact same four-byte-framed samples as N4; use the C0007 `ftyp` and compact payload placement | Isolate a clearly named brand/alignment bundle |
| R | Fresh-identity C0007 clone preserving its complete `mdat`, sample tables, AVCC and RTMD; only necessary identity/date/catalog changes | Check the added-package/identity route with historically successful essence |

For R, a full clone avoids introducing GOP trimming and timestamp
reconstruction as extra variables; a short extract needs separate complete
decode/reference validation. Do not require the native-only
`build_native_control.py` device/Rec.709 assumptions to hold for an
EDIUS-origin reference.

For N4/E4 keep the same 25 Mbps encoded payloads, HRD/SEI bytes, SPS/PPS,
CTTS/edit timing, PCM/RTMD samples, acquisition labels, nominal profile
fields and UMID-generation policy. Identity values must be unique, but
their policy and catalog staging mode should match. E4 should retain N4's
proper 25 Mbps PROF descriptor, not C0007's raw VPRF. Do not combine this
with a 50 Mbps re-encode, new SEI filtering or a catalog experiment.
An E3 arm is optional if an interaction between framing and layout must
be tested; it completes the two-by-two design.

Before deployment, verify full source-index bounds; ordered NAL-payload
hash equality across framing changes; byte-identical video samples between
N4/E4; unchanged SPS/PPS, audio/RTMD hashes and timing; complete software
decode; package/sidecar/catalog consistency; and hash-bound manifests.
Record original-reader statuses with scope limits, not acceptance labels.
No expectation of success should substitute for those checks.

Interpret physical results narrowly:

- N4 plays / N3 fails: evidence for framing dependence in this payload
  and packaging context, not a universal explanation for C6509.
- E4 plays / N4 fails: evidence for the brand/alignment bundle. Split
  brand and alignment into separate subsequent tests before naming either
  the cause.
- C0007 plays / R fails: added identity/package/catalog differences remain
  relevant even when essence is retained.
- All new arms fail: does not eliminate container or framing interactions,
  and does not prove x264 is the cause. Continue toward the unobserved
  transfer/codec boundary.

## Remaining Research Boundary

No OSAL/codec callback was captured on the failing camera. Useful future
instrumentation would retain originating `0x2311/0x1a04..0x1a09` statuses,
error-context+8, player state at **0x100a90**, ES transfer return values,
actual output-list capacities/write counts and initial transferred bytes.
Those observations would distinguish branches that the stop callback
otherwise merges. They are proposals, not capabilities demonstrated here.

Missing coverage includes the complete asynchronous worker/ring/DMA path,
normal-mode C6510 traversal, every metadata sample, platform codec setup
and submission, and the application/UI error mapping. The present evidence
supports controlled new tests, not a claimed cause, fix, or playback result.

## Primary Local References

- [Current physical observations](C:/Users/HeMu/Desktop/XAVC_Write/analysis/camera_observations_20261112_233331.json)
- [Shared dispatcher](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/001fe0e8_FUN_001fe0e8.c:18)
- [Decode-error callback](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/001fec08_RecvCallbackDecodeError.c:25)
- [Playing-callback registration](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/0020361c_SendMovieReaderStart.c:210)
- [Original ELF for verified callback and transfer disassembly](C:/Users/HeMu/Desktop/XAVC_Write/firmware/m4-v602/usr/lib/libmpr.so)
- [Reader owner loop](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/00214ac0_FUN_00214ac0.c:208)
- [Read worker](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/00215df8_FUN_00215df8.c:133)
- [Raw ring-buffer file reads](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/00210194__read_stream_from_file.c)
- [Descriptor consumer](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/00214894_FUN_00214894.c)
- [Information-table construction](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/0020d7d8_MakeInfoList.c)
- [Capacity checks](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/0021358c_FUN_0021358c.c)
- [Transfer and codec write-index updates](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/00213ee8_FUN_00213ee8.c)
- [Table-copy status limitation](C:/Users/HeMu/Desktop/XAVC_Write/analysis/decompile-mpr/0020c414_TransferInfoTable.c:21)
- [Inspected builder](C:/Users/HeMu/Desktop/XAVC_Write/tools/build_sony_clip.py)
- [Three-byte framing implementation](C:/Users/HeMu/Desktop/XAVC_Write/tools/avc_sony.py:161)
- [Offline C0007 media](C:/Users/HeMu/Desktop/XAVC_Write/analysis/C0007-reference-0023.MP4)
- [Offline native reference](C:/Users/HeMu/Desktop/XAVC_Write/analysis/C6359-reference-0023.MP4)
- [C6509 package media](C:/Users/HeMu/Desktop/XAVC_Write/output/native-minimal-C6509/C6509.MP4)
- [C6510 package media](C:/Users/HeMu/Desktop/XAVC_Write/output/cat-minimal-C6510/C6510.MP4)
- [Existing bounded-reader evidence and limits](C:/Users/HeMu/Desktop/XAVC_Write/docs/experiments/0024_sample_tables_and_metadata.md)
