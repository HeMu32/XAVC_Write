# Independent Container Pair Review 0025

Date: 2026-11-13. Read-only review of the two offline inputs and the proposed
C6511/C6512 experiment. No card access, shared-tool edits, or candidate generation.
This document is the review's only output file.

## Findings First

1. **A real, actionable packaging difference is NAL length-prefix width.**
   C0007 uses four bytes (`avcC[4]=0xff`); C6510 uses three (`0xfe`).
   All video samples in both inputs parse completely using their declared
   widths. An EDIUS-convention C6512 should use four-byte lengths if that
   convention is part of the experiment. Changing the configuration byte
   alone is incorrect: rewrite every sample prefix, update `stsz`, and
   rebuild every chunk offset. Keep every NAL byte and its ordering.
   This difference is not established as the physical playback failure.
2. **USMT and tref are already matched, not missing features in C6510.**
   All three per-track USMT UUID boxes and metadata `tref/cdsc -> track 1`
   are byte-identical between these exact inputs. The first 1534 RTMD
   samples also match byte-for-byte. Reusing them is appropriate, but
   adding/replacing them cannot be described as a new discriminator here.
3. **Keep C6511's opaque source PROF exact; do not transplant it into C6512.**
   The source VPRF is demonstrably patched/opaque, with rate-like values
   in count/codec/profile positions. C6511's purpose is preservation of
   the historically successful source, not conformance repair.
   Keeping syntactically valid 25M PROF for C6512 is a sound explicit
   exception to matching the source container.
4. **Do not transplant EDIUS ctts, sync indices, SPS/PPS, or NRT duration
   into the Cat stream.** These must describe the actual Cat samples.
   Matching container conventions does not mean copying source tables
   that belong to a different encoding and duration.
5. **Keep `source_control` distinct from `native_control`.**
   C0007's embedded XML has no Sony Device claim. Its historical success
   does not make it camera-native. A source-preservation profile should
   have source-specific invariants and must not relax the ordinary 25M
   candidate verification gates.

## Inputs And Evidence Scope

Inputs independently opened read-only with the existing `sony_mp4.MP4`
parser, supplemented by direct field decoding, box-byte comparisons,
hashes, complete video NAL walking and chunk-interval checks:

| Item | Historical C0007 | Existing Cat C6510 |
|---|---|---|
| Path | `analysis/C0007-reference-0023.MP4` | `output/cat-minimal-C6510/C6510.MP4` |
| Bytes | 1,421,462,765 | 87,550,884 |
| SHA-256 | `8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a` | `18a2bc5e6a0c5839579304711b9177692494bff501dafecbe1eaf69b89a3890d` |
| Video / RTMD frames | 14170 | 1534 |
| Video duration, ticks / 60000 | 14184170 | 1535534 |
| PCM stereo sample frames / 48000 | 11347336 | 1228427 |

`analysis/container-pair-0025.json` is consistent with these inputs.
Its empty `meta_hex` arrays mean **no moov-contained meta was found by that
particular query**. Both files have a trailing **top-level** meta box with
embedded NRT XML. Empty arrays must not be interpreted as absent metadata.

The camera observations are supplied evidence: C6507-C6510 list and have
normal thumbnails but fail physical playback; C0007 has historical playback
success. I did not reproduce either physical result or test the new pair.
No claim is made that a presently unbuilt/finalized C6511/C6512 passes.

## Complete Relevant Structural Comparison

### Top-Level Layout

| Field | C0007 | C6510 |
|---|---|---|
| Box order | ftyp, PROF UUID, mdat, moov, meta | ftyp, PROF UUID, free, mdat, moov, meta |
| ftyp size / major / compatibility | 28 / XAVC / XAVC, mp42, iso2 | 28 / XAVC / XAVC, mp42, iso6 |
| ftyp minor version | `0x01001fff` | `0x010b1fff` |
| PROF UUID start / size | 28 / 148 | 28 / 148 |
| free | absent | start 176, size 130880 |
| mdat start / header bytes | 176 / 16 | 131056 / 16 |
| First mdat payload byte | 192 | 131072 |
| First video byte | 30912 | 161792 |
| First audio byte | 908273 | 1563253 |
| moov start / size | 1421319804 / 141689 | 87532081 / 17349 |
| trailing meta start / size | 1421461493 / 1272 | 87549430 / 1454 |

Both use one extended-size mdat, even though neither file needs >4 GiB
offsets. Both keep moov after mdat and use 32-bit `stco`, not `co64`.
There are no additional top-level boxes in either parsed tree.

For compact C6512, first RTMD data at 192 and first video at 30912 follow
directly from the existing 30 x 1024-byte first RTMD chunk. Removing only
the leading free box changes the prefix by -130880 bytes; converting NAL
prefixes additionally changes later positions non-uniformly. **Do not
apply one constant subtraction to old stco entries after reframing.**

### Track Skeleton And Fixed Fields

Both files have the same order and IDs:

```text
track 1 vide/avc1: tkhd, edts, mdia, USMT UUID
track 2 soun/twos: tkhd, edts, mdia, USMT UUID
track 3 meta/rtmd: tkhd, tref, edts, mdia, USMT UUID
```

Independently established equalities:

- Movie timescale 60000, identity matrices, rate/volume fields and next
  track ID 4 match. Movie-header differences are dates and duration.
- For each track, `tkhd` matches after masking creation/modification times
  and duration. Flags are 7; track IDs, audio volume/alternate group,
  display width/height and all remaining header bytes match.
- Each `mdhd` matches after masking dates and duration. Timescales are
  60000/48000/60000, and language/predefined fields match.
- All three media `hdlr` boxes, names and reserved fields match exactly.
  Top-level NRT `hdlr` also matches exactly.
- `vmhd`, `smhd`, `nmhd`, and each self-contained `dinf/dref/url ` match
  exactly. Every sample description's data-reference index is 1.
- The 78-byte fixed VisualSampleEntry payload is identical, including
  1920x1080, resolution, compressor name and depth. Its only child is
  avcC in both. No differing colr/btrt/pasp/clap child was found.
- The complete twos and rtmd sample entries match exactly: stereo 16-bit
  PCM, 48000 Hz, 4 bytes per audio sample frame; rtmd entry size 16.
- Each track has one version-0 elst, rate 1.0. Video media_time is 1001;
  audio and metadata media_time are 0. After masking segment duration,
  each matching elst is identical.
- All three USMT UUID types are
  `55534d5421d24fcebb88695cfac9c740`, each box size 52 with MTDT child.
  Video/audio boxes match one another; the metadata variant differs
  internally as expected. Both variants match across the two files.
- Metadata tref contains one cdsc child with track ID 1 in both.
- Neither parsed moov has an extra moov-level udta/meta/UUID structure.

These equalities mean that "EDIUS track conventions" are largely already
present in C6510. Preserve them, but do not claim all are newly introduced.

### Sample Tables, Interleaving And Timing

| Table / invariant | C0007 | C6510 |
|---|---|---|
| Video and RTMD stts | all 1001 ticks | all 1001 ticks |
| Audio stts / constant stsz | 1 tick / 4 bytes | 1 tick / 4 bytes |
| RTMD constant stsz | 1024 bytes | 1024 bytes |
| Chunk count per track | 473 | 52 |
| Video/RTMD stsc | `(1,30,1),(473,10,1)` | `(1,30,1),(52,4,1)` |
| Audio stsc | `(1,24024,1),(473,8008,1)` | `(1,24024,1),(52,3203,1)` |
| Physical chunk order | RTMD, video, audio, repeated | same |
| Video sync cadence | 1,31,61,...; 473 entries | same cadence; 52 entries |
| ctts version | 0 | 0 |
| Distinct ctts offsets | 0,1001,3003 | 0,1001,2002,3003 |
| ctts rows | 9447 | 1074 |

All chunk intervals, sorted physically, are contiguous from mdat payload
start to end in **both files**: no gaps, overlaps or unreferenced mdat
bytes were found. Sample-table counts and duration sums passed the local
parser. Difference in moov size is primarily sample/table cardinality,
not evidence of missing required track metadata.

The source's first presentation timestamps, before edit application, are
`3003,1001,2002,6006,4004,5005,...`; Cat starts
`1001,4004,2002,3003,7007,5005,...`. The source's ctts must not replace
Cat's ctts: composition ordering is bound to the encoded picture sequence.
Likewise preserve Cat sync indices, per-sample durations and edits.

C6510 audio has `floor(1534*1001*48000/60000)=1228427` sample frames.
Its fractional residual is 0.2 audio sample, not a whole video-frame
desynchronization. Do not pad/trim it differently merely to mimic the
source's integer-duration case.

### avcC And Non-VCL Framing Boundary

Both have configuration version 1, AVC High level 4.2 and one SPS/PPS.
Configuration payload sizes are 150 bytes for C0007, 74 bytes for C6510.
Source SPS/PPS lengths are 48/87; Cat lengths are 54/5. These contents
belong to different encodings and are not interchangeable.

Complete sample walking found:

| Item | C0007 | C6510 |
|---|---|---|
| Declared/used NAL prefix bytes | 4 | 3 |
| Total NALs | 85966 | 9257 |
| NAL type counts | 9:14170, 6:15116, 5:1892, 1:54788 | 9:1534, 6:1587, 5:208, 1:5928 |
| First sample starts with | AUD, then SEI | user-data SEI, then AUD |
| Parsing errors / trailing sample bytes | none | none |

NAL order/SEI differences are **bitstream-side differences**, even though
some NALs are non-VCL. Do not silently remove Cat's encoder user-data SEI,
reorder its AUD, replace SEI or substitute parameter sets as part of a
"container-only" experiment. Such changes would require a separately
declared variant. Local decoder acceptance is not proof of camera
acceptance for either framing.

For a pure 3 -> 4 byte C6512 reframe, without adding/removing/changing NALs:

- Total video sample bytes increase by exactly 9257:
  80916485 -> **80925742**.
- Total referenced mdat bytes increase:
  87401009 -> **87410266**.
- With payload start 192, unchanged audio/RTMD, no other mdat additions:
  mdat end / moov start should be **87410458**.
- Rebuilt sample-stream SHA-256 should equal Cat's canonical sequence of
  four-byte NAL lengths plus original NAL bytes:
  `35797e8924d0f06585aae629c92025aedef2c4e3aa322ea3a8fe54d4d52786ec`.

These are falsifiable expectations, not measurements of the new candidate.
The original three-byte Cat sample-stream SHA-256 is
`3689edddac093690456bef79c81f10457d46b4bb007d686cfb9664d9fb1779a3`.
Update each stsz by its own NAL count and rebuild all stco values from
the actual output layout. stts/ctts/stss/stsc should remain Cat-bound.

### PROF: Deliberate Exception, Not A Repair Claim

Both UUIDs have the same type, size 148, FullBox flags and child count 3.
FPRF and APRF child bytes match; child order differs:

```text
C0007: FPRF, APRF, VPRF
C6510: FPRF, VPRF, APRF
```

The eleven big-endian VPRF u32 words are:

```text
source: 0,50000,50000,3928230,3928230,50000,50000,3928230,3928230,125830200,65537
Cat:    0,1,0x61766331,0x0164002a,0x00030002,25000,25000,3928230,3928230,125830200,65537
```

Thus C0007's source bytes are not a normal codec/profile descriptor to
reuse for the 25M Cat. For C6511, preserve this exact opaque source UUID.
For C6512, retain the valid C6503-derived 25M VPRF as proposed, and verify
its codec/profile/rate/dimensions against the final Cat stream.

If matching source child order is intended, reorder the valid child
boxes without copying opaque VPRF fields. Otherwise explicitly record
that PROF order remains native-style. Neither choice is demonstrated
necessary for playback here.

### RTMD, NRT XML And Identity

C6510's entire 1534-sample RTMD sequence equals C0007 samples 0..1533.
The first RTMD sample SHA-256 is
`dd2f35164c20c2daafb98534563e2d4a5884ae8c73351320a6e9cd9fc145e7af`.
Changing RTMD to "use the EDIUS seed" would therefore not create a new
difference if the same packet generator/cadence is retained.

NRT differences, beyond frames/dates:

- Source XML has `standalone="no"`, additional lib/xsi namespace
  declarations, different whitespace/newline serialization and a terminal
  NUL. It lacks RecordingMode, AcquisitionRecord and Device.
- Cat adds RecordingMode normal/cacheRec false and explicit Rec.709
  acquisition items. These are not reflected by differing USMT boxes.
- Both identify 59.94p AVC_1920_1080_HP@L42, stereo LPCM16, tcFps 30 with
  halfStep true, the same timecode start and matching dimensions/aspect.
  Their timecode endpoints belong to their respective frame counts.
- Source UMID label is `060a2b340101010501010d2313000000`; its remaining
  16 bytes decode as a UUID version 4. Cat's existing label instead uses
  `...0d43...` and the camera-style material encoding.

"UUID4 UMID" should mean the source-compatible material-number convention,
not inventing a new UUID box. New identities must be unique and agree
between embedded XML, sidecar, manifest and MEDIAPRO. The source UMID was
found only as ASCII in trailing XML, not as a binary/ASCII token inside
mdat. This supports retaining mdat untouched for C6511, but is not a
general proof that all possible identity encodings were exhaustively found.

Do not make arbitrary UUID4 material bytes pass a native
creation-time-derived UMID reconstruction check. The current
observed-minimal catalog deliberately omits that array representation;
verify the actual declared representation and MEDIAPRO/XML identity.
Do not fabricate a restored-UMID check result for omitted data.

For C6512 retain truthful Rec.709 NRT/SPS declarations unless explicitly
testing their removal as another variable. Its new UUID4 identity and
compact/brand/framing changes already make this a combined experiment.

## Required Verification Before The Pair Is Called Ready

### C6511 Source Preservation

1. Bind the source hash and historical playback observation. Record that
   historical success is not a fresh physical pass of the new identity.
2. Entire mdat, including header/layout and every payload byte, must be
   exact. Payload-only SHA-256 baseline:
   `88b0e70d6b255daf258a39aba4082bcfa79516f4f6a58c6d0b846e74d08318e9`.
3. All track IDs/order, sample entries/configuration, sizes, chunk offsets,
   stts/ctts/stss/stsc, edits, USMT and tref must remain exact.
   If creation/modification timestamps are changed in mvhd/tkhd/mdhd,
   whitelist those precise fields; do not simultaneously claim literal
   whole-track byte identity. No duration/timescale "normalization."
4. ftyp and the complete source PROF must be exact. Preserve the layout
   with payload at 192, not the camera-aligned 131072 layout.
5. Embedded/sidecar XML must agree; semantic changes must be limited to
   new TargetMaterial identity and declared date changes. Retain source
   duration, timecodes and absence of invented camera acquisition data.
6. Use dedicated source_control checks, not native-control provenance or
   ordinary generated-25M PROF checks. Scope the opaque-PROF exception to
   the hash-bound source-control case only.

### C6512 Cat Essence Preservation And Structural Match

1. Bind C6510 and C0007 template hashes; bind the chosen C6503 PROF source.
   State the actual differences in a manifest, including prefix width.
2. Per-sample NAL lists must be byte-for-byte and order-for-order identical
   to C6510, including AUD/SEI; assert no dropped/duplicated sample or NAL.
   Keep SPS/PPS and avcC extension bytes except the intended length field.
3. Audio and every RTMD sample must remain exact; do not derive copied
   source counts/tables from the 14170-frame stream.
4. Reparse every sample and chunk after writing. Check bounds, description
   IDs, no overlaps/gaps, sum(stts)==mdhd.duration, ctts count, sync ranges,
   edit units, and exact media/movie timescales.
5. Validate compact placement and ftyp minor/compatibility explicitly.
   Assert existing USMT/tref byte equality rather than checking presence.
6. Keep valid 25M PROF, correct actual-frame durations and truthful colors.
   Keep classification/identity/catalog checks separate from AVC checks.
7. Fresh decode/frame/timestamp/audio comparisons should use final output,
   not only prior C6510 verification. Also retain exact NAL/sample evidence;
   identical decoded pixels alone cannot establish bitstream preservation.

For both: retain separate evidence for listing, thumbnail, opening,
first frame, sustained playback and seeking. Existing offline read-side
parser success is useful but does not imply hardware submission/decoding.
No card action was performed in this review.

## Interpretation Limits

- C6511 success would demonstrate current replay of a reidentified,
  source-preserved historical stream under the new catalog, not arbitrary
  input encoding or the correctness of every Cat coding choice.
- C6511 failure would not disprove historical success or uniquely indict
  the old stream; identity/catalog/current-camera conditions changed.
- C6512 success would support the **combined packaging/identity** revision.
  USMT/tref/RTMD already match, so they cannot be individually credited.
- C6512 failure would not prove a VCL defect. It still differs from C6511
  in coded/configuration/NAL-order details and intentionally in PROF.
- The pair is a useful source-preservation control plus a combined Cat
  packaging test, not a clean one-variable codec-versus-container proof.
  No root cause is asserted.

## Implemented Matrix Review (2026-11-13)

Read-only review of the implemented C6512..C6515 artifacts and the three
requested tools. No card access, candidate generation, deployment, or source
edits were performed. This section is a scoped preservation/code review,
not full package admission or a hardware-playback result.

### Findings

1. **[P2] Reframing comparator does not prove PCM/RTMD sample boundaries.**
   `tools/compare_nal_reframe.py:26` compares track sample counts and
   cadence; lines 31..33 compare concatenated audio/metadata payload hashes
   and sample entries, but do not compare their sample-size sequences.
   An in-memory negative fixture changed the first two C6512 RTMD sizes
   from 1024/1024 to 1023/1025 and rebuilt within-chunk sample offsets.
   Individual sample bytes then differed, but chunk concatenation, sample
   count and timing remained unchanged. With these parsed models supplied
   to `compare()`, it still returned `passed=true`, including
   `audio_and_metadata_payloads_exact=true`.
   This is a demonstrated checker false positive, not a finding that any
   current candidate has damaged RTMD. Compare PCM/RTMD sample sizes as
   well as payload hashes, preserving a ConstantSizes fast path, and add
   this negative regression case. `sony_verification.py:115` already has
   the appropriate size comparison in its native-payload fallback.

2. **Matrix interpretation: alignment is coupled to structure/ftyp.**
   `build_sony_clip.py:174` selects the track/header structure;
   line 216 copies its ftyp, while line 226 independently selects payload
   placement. The actual compact candidates use C0007 structure and
   EDIUS ftyp, whereas aligned candidates use native-control C6507
   structure and camera ftyp. Thus these artifacts do not isolate
   alignment versus prefix width. Either hold the structure template
   constant for an alignment-only experiment, or name the first factor
   "container style" and explicitly include template/ftyp plus placement.
   Playback differences must not be attributed to alignment alone.

### Actual Matrix

| Clip | Output directory | First mdat payload | NAL prefix bytes | ftyp minor / relevant brand |
| --- | --- | ---: | ---: | --- |
| C6512 | output/cat-compact-C6512 | 192 | 3 | 0x01001fff / iso2 |
| C6513 | output/cat-aligned3-C6513 | 131072 | 3 | 0x010b1fff / iso6 |
| C6514 | output/cat-aligned4-C6514 | 131072 | 4 | 0x010b1fff / iso6 |
| C6515 | output/cat-compact4-C6515 | 192 | 4 | 0x01001fff / iso2 |

The clip/directory names correctly describe measured placement and width,
subject to the coupled-factor limitation above. C6512 predates the
manifest's `nal_length_size` field: its width is established by avcC and
complete sample parsing, not a manifest declaration. The other three
manifests declare their measured widths.

All four have source-compatible UMID labels and UUID-version-4 material
numbers. Their complete PROF boxes have identical SHA-256:
`eedb1c777de8d263ad0cb42d4fa1005655761eee141eee45be9714285e5ed914`.
This is the valid 25M profile, not the opaque historical C0007 PROF.

### Completed Offline Checks

- Compared every candidate with C6510 using `compare_nal_reframe.compare`
  without writing comparison reports. All passed ordered per-sample NAL
  equality, including SEI, sample counts/timing/configuration checks, and
  audio/metadata stream preservation. Current PCM/RTMD sample boundaries
  also match; the synthetic failure above concerns missing enforcement.
- All candidates contain the same 9257 ordered NAL units. Width-3 video
  sample bytes have delta 0; width-4 candidates have delta +9257.
  Canonical four-byte-prefix video-stream SHA-256 is
  `35797e8924d0f06585aae629c92025aedef2c4e3aa322ea3a8fe54d4d52786ec`.
- Media SHA-256 values match their respective build manifests:
  C6512 `896b9764bb859a673dc5b455ca8acda78e3640146fbadf42eca5dbbac6054c72`;
  C6513 `19ce27470536e4ea21afb3ee9c484362698c91d698df20fd5aee7167019f5c3f`;
  C6514 `a3317b18f2c35d31dcdb3f3a5dd35f38164cc36c87c8bc7567a3e8098575a375`;
  C6515 `f6815df190cda04a3dcd500aba0df6c4ac1859f22838297b337c3b2f1b0f63e5`.
- `python -B -m unittest discover -s tools/tests -p test_pair_controls.py -v`:
  5 passed. Corresponding `test_sony_verification.py` run: 15 passed.
- Guard-buffer tests rejected any payload slice larger than 1 MiB.
  `equal_ranges` compared a 3 MiB+7-byte range with four slices, maximum
  1048576 bytes. `track_payload_hash` handled three million constant-size
  PCM samples with twelve slices, maximum 1048576 bytes.
- `native_payload_checks(C0007, C0007, "source")` returned all three checks
  true, exercising source self-comparison and the exact-mdat fast path.

No defect was found in the reviewed bounded payload reads, per-sample
NAL reframing, avcC width update, or current-verification admission
contract for these valid artifacts. This does not cover arbitrary
malformed inputs or replace final fresh decode/frame/timestamp/audio,
container-index, identity/catalog and package-hash validation.
C6511 was not part of this implemented-matrix review.

### Reviewed Source Versions

Conclusions bind these SHA-256 versions, rechecked before appending:

- `tools/build_sony_clip.py`:
  `067daba70794a2457a117105b572940ad5f716f0ba486d4cfed416367ca0ea6d`
- `tools/compare_nal_reframe.py`:
  `564581fd72adfd0ea3710395980f060ea34e26deb77d1b82d5f90fdb6e563afc`
- `tools/sony_verification.py`:
  `21e6ee96fc7dd22f53f8456109c55355c317ea78f965edf0275b3f61ba10075d`

No playback root cause is established and no deployment approval is
implied by these preservation checks.
