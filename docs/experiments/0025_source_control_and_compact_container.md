# Experiment 0025: Source Control And Compact Container

Date: 2026-11-13, Asia/Shanghai. Playback body: user-confirmed ILCE-7M4.

Operational instructions and the complete file/field edit inventory:
[SD XAVC-S reproduction runbook](C:/Users/HeMu/Desktop/XAVC_Write/docs/sd-xavcs-reproduction.md).

## Question And Limits

The user asks for files on the SD card for a physical test after research.
C6507-C6510 are listed with normal thumbnails but fail playback with
"Cannot display". No root cause has been established. This round does not
prioritize differences between bodies and does not equate desktop decoding
or selected firmware execution with physical acceptance.

Experiment 0024's complete tool suite finished with 127 passing tests.
Its selected read/table/metadata results remain bounded as documented there.
It did not emulate hardware stream submission or recover an actual error trace.

## Preserved Baseline

Snapshot `backup/snap_20261113T005344`: 64 metadata files, 127 media inventory
entries, zero errors. `analysis/snapshot-000418-005344-0025.json` finds no
metadata, media size/write-time, active-record or database-header changes.

The complete local C0007 reference and the current card C0007 both hash to
`8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a`.
Historical successful playback comes from the user's supplied task/workspace
instructions, not a fresh retest on this visit. This distinction is recorded
and hash-bound in `analysis/historical-playback-C0007-0025.json`.

C0007's observed PROF has earlier patched fields in positions which the
current valid-profile writer treats as codec/profile bytes. Its stored
descriptor is **not** promoted to a syntactically valid 50M profile.
The source control preserves those bytes, rather than silently repairing them.
This observation alone does not explain any playback failure.

## Controlled Samples

### C6511: Historical Source Content Control

Built source control: all C0007 coded samples, mdat, sample tables,
sample descriptions, RTMD, timecodes and PROF preserved. Only identity,
NRT dates and container creation/modification times may change.
It is neither a native-camera control nor a fresh verified positive control.
Its nominal historical format is 1080p59.94, 50M, 8-bit 4:2:0.
It has 14170 frames / 236.402833 seconds. The full source is retained;
no GOP extraction, trimming or timeline reconstruction is introduced.

The explicit `source_control` verification profile requires source identity,
sidecar and historical-observation hashes, all track payloads/configurations,
exact PROF bytes, fresh full frame decoding and PCM comparison.
An independent reconstruction check limits container changes to identity/dates.
The existing native-control and encoded-AVC contracts are not waived.
Embedded XML and sidecar serializations are preserved independently,
including the original embedded terminator and each file's newline style.
Their source relationship is semantic, not falsely asserted byte-identical.

### C6512: Cat 25M Compact Container

Local package: `output/cat-compact-C6512`.
Input encoding is the existing Rec.709 Cat encode
`output/cat-rec709-base-C6508/base.mov`, not the older gamma22 encoding.
It remains 1534 frames, 60000/1001 fps, 1080p, nominal25M,
High@4.2, 8-bit420, stereo 48k PCM16BE.

Compared with C6510, this package selects C0007 for ftyp/track/mvhd
structure, uses the observed EDIUS UUID4-type UMID label, and puts the
first mdat payload at 192 rather than 131072. The valid25M PROF descriptor
still comes from the local native-template package; the opaque historical
C0007 PROF is **not** transplanted into this encoded target.
This is a bundled structural comparison, not a single-variable causality test.

`analysis/cat-coded-content-0025.json` confirms all 1534 video samples'
configuration/timing, all non-SEI NALs and non-buffering-period SEI payloads
are unchanged; zero buffering-period payloads changed, 6136 VCL NALs compared.
Additional complete-track and catalog checks are recorded separately.

`analysis/xavc-reader-C6512-ionly-0025.json` passes the selected original
MP4 open/query, first I-only descriptor, parameter preparation and decode
table conversion, plus RTMD frames0/1/1533. It is not continuous playback,
not a full descriptor traversal and not hardware decoding.

### Complete Cat Matrix

Independent reviews are recorded in `analysis/agent-container-review-0025.md`
and `analysis/agent-post-reader-0025.md`. They establish that USMT, tref,
track fixed fields and all 1534 RTMD samples already agree between the
historical source and C6510 where applicable. These are not new fixes.
They also confirm the real 3/4-byte NAL-prefix distinction. C6509 already
uses four-byte lengths and fails physical playback, so this is not a
universal explanation of all rejections.

The final local test matrix has a common UUID4 identity-generation policy,
the same minimal catalog representation and a common valid25M PROF:

| Clip | Package | Brand / First Payload | NAL Prefix |
|---|---|---|---|
| C6512 | cat-compact-C6512, diagnostic control | EDIUS iso2 / 192 | 3 bytes |
| C6513 | cat-aligned3-C6513, diagnostic control | native-style iso6 / 131072 | 3 bytes |
| C6514 | cat-aligned4-C6514, candidate | native-style iso6 / 131072 | 4 bytes |
| C6515 | cat-compact4-C6515, candidate | EDIUS iso2 / 192 | 4 bytes |

All are 1534 frames / 25.592233 seconds. Identity values and dates must be
unique/truthful, not held equal across clips. No VCL, SPS/PPS, AUD, SEI,
composition-time, PCM or RTMD data are silently changed by the prefix test.
`avcC`'s length field, every length prefix, sample sizes and affected offsets
are rebuilt consistently. The two layout arms preserve exact whole mdats.

`analysis/reframe-C6512-C6515-0025.json` compares every ordered NAL, including
every SEI payload. It confirms exactly 9257 NALs / 9257 added length bytes,
and the independently predicted canonical four-byte video hash:
`35797e8924d0f06585aae629c92025aedef2c4e3aa322ea3a8fe54d4d52786ec`.
`analysis/repack-C6512-C6513-0025.json` and
`analysis/repack-C6515-C6514-0025.json` confirm all indexed video/audio/RTMD
payloads and whole mdat bytes match within each layout comparison.

This separates framing from a **brand/alignment bundle**; it does not yet
separate brand from alignment. Nor do fresh identities constitute a
same-file repeatability test. Interpret any physical result accordingly.

### Qualification Correction

The local camera-native control and historical C0007 use four-byte NAL
lengths. The earlier generator instead unconditionally emitted three-byte
lengths. That is a concrete mismatch, not evidence of a universal cause:
the four-byte native C6509 also fails physical playback.

A commentary asserted a standards restriction and attached an invalid
reference. That citation and its claimed verified-standard basis are
withdrawn. Attempts to obtain the exact normative passage did not succeed;
the original MPEG schema inspected describes a two-bit field but does not
itself establish its permitted semantic values. No normative conclusion
is derived from that schema or from recollection.

The conservative, evidence-backed change is to default the generator to
four-byte framing matching both observed sources. Three-byte generation
requires an explicit diagnostic-control option. `encoded_avc` candidates
must pass the four-byte qualification check; a distinct `framing_control`
profile retains all other media checks and explicitly makes no standards
conformance claim. Neither profile establishes complete camera acceptance.

C6512 was written before this qualification correction. Its local manifest
was then reclassified as a diagnostic control and freshly reverified with
card readback. No C6512 card bytes were changed by that reclassification.
C6513 is similarly a diagnostic control, not a target-format success claim.
These two remain useful paired diagnostic samples, not the preferred
four-byte candidate outputs.

## Post-Reader Research

The independent original-byte review identifies `PlayingMovieErrorCb` at
ELF0x100a90 and verifies its GLOB_DAT relocation. It dispatches state-dependent
stops after several origins converge; it does not identify a specific bad
container/codec condition from the generic UI message. The untested boundary
includes ring-buffer reads, actual ES/info-list transfers, platform codec
consumption and asynchronous callback origin. A zero result from the table
transfer routine is not sufficient evidence that all entries were copied.
No actual failure trace, runtime buffer defect or root cause is claimed.

## Catalog And Write Policy

All five packages use the already observed C0007 minimal catalog representation,
including its absent video parameters/UMID/timecodes. It is not mislabelled
as a fully populated native record. Every old record is to remain byte-exact.
Original firmware record conversion and MEDIAPRO parsing must pass on each
staged catalog before writing. Deployments are additive, with fresh snapshots,
exclusive new-asset creation, durable streaming writes and readback hashes.
Only DATABASE.BIN and MEDIAPRO.XML may be updated; no file is deleted.

## Status

**The user confirms physical playback success for C6511, C6514 and C6515.**
C6512/C6513 list with normal thumbnails but reject playback with
"Cannot display". C0007 is reconfirmed continuously normal.
The requested Cat 1080p59.94 nominal25M 8-bit420 SD playback milestone is
achieved on the user-confirmed 7M4. Seeking, complete-duration playback
and audio are not separately established by the report.

See the result section below. Preparation-time verification/audit JSON
files retain their original NOT_TESTED fields: they describe evidence
available before the physical visit, not an attempted rollback of this result.

Final full test run: **153 tests passed in 217.567 seconds**.
The independent comparator review found a PCM/RTMD boundary-check gap;
it is fixed and has a regression test. Both actual reframe comparisons
pass the stronger boundary and complete payload checks.

Deployment order was C6511, C6512, C6513, C6514, C6515. Each subsequent
catalog was staged from the actual post-deployment snapshot, never by
applying an old baseline over a newer transaction. Each original-firmware
catalog verification passed with 45,46,47,48,49 movies respectively.

Pre-write snapshots captured by the deployment tool:

| Clip | Snapshot | Media SHA-256 |
|---|---|---|
| C6511 | snap_20261113T012102 | 8a03d292450ad6c0710f7b8fc97933038336f51f5f2793ccc91c0252578f0e3e |
| C6512 | snap_20261113T012418 | 896b9764bb859a673dc5b455ca8acda78e3640146fbadf42eca5dbbac6054c72 |
| C6513 | snap_20261113T013639 | 19ce27470536e4ea21afb3ee9c484362698c91d698df20fd5aee7167019f5c3f |
| C6514 | snap_20261113T013915 | a3317b18f2c35d31dcdb3f3a5dd35f38164cc36c87c8bc7567a3e8098575a375 |
| C6515 | snap_20261113T014150 | f6815df190cda04a3dcd500aba0df6c4ac1859f22838297b337c3b2f1b0f63e5 |

Each deployment reports successful durable write/readback, no deletion,
no unexpected existing-file changes. The cumulative read-only audit
`analysis/sd-test-round-0025.json` passes every check: exactly 15 new assets,
no missing old file, only the two intended catalog files updated, and all
new asset/final catalog hashes agree with their verified local packages.

Closing snapshot `backup/snap_20261113T014211`: 69 metadata files / 137 media
inventory entries, zero errors. Comparison
`analysis/snapshot-005344-014211-0025.json` confirms:

- Active records 89 -> 94; movies 44 -> 49.
- Only new content records92..96 activated, no old record changed/deactivated.
- Existing MEDIAPRO materials preserved; five additions, no removals.
- No old media size/write-time changes. Old media are not all content-hashed.
- The original card C0007's full hash was rechecked and still equals the
  initial `8b0d2c...f773a` reference.

Final card catalog hashes:

```text
DATABASE.BIN b58873b8067c0f55e13ab10f595d7455a4d35212517197ddf5700847a8802ba9
MEDIAPRO.XML 29a502ced0e29bb9f0d7f72a11802b37bc710c8b957c6aecc2b70cda6fb71820
```

The final 49-movie original-firmware proof's two hashes were explicitly
compared with the live card and match. Its converted set includes all five
new clip IDs. All five clips also have selected first-I-only/read-table/
parameter-set/RTMD original-code reports; these retain their stated limited
scope and are not normal continuous playback or hardware tests.

Physical test sheet: `analysis/camera-test-round-0025.json`.
Suggested order: unchanged C0007, source control C6511, candidates C6514/C6515,
then diagnostic controls C6513/C6512. Record listing, thumbnail, playback,
seeking and any available exact error separately. No proactive catalog
repair/rebuild or original-clip replacement was performed.

## Physical Result And Bounded Conclusion

Direct user report, 2026-11-13:

| Clip | Framing / Layout | Physical Result |
|---|---|---|
| C0007 | Existing source | User reconfirms continuously normal |
| C6511 | Source-preserved 4-byte control | Normal playback |
| C6512 | 3-byte / compact iso2 | Listed, normal thumbnail, cannot display |
| C6513 | 3-byte / aligned iso6 | Listed, normal thumbnail, cannot display |
| C6514 | 4-byte / aligned iso6 | Normal playback |
| C6515 | 4-byte / compact iso2 | Normal playback |

Machine-readable source observations are stored in
`analysis/camera-observations-0025-result.json`, the test sheet is updated,
and each new package has a separate `camera-result.json`. These bind the
reported clip IDs to the pre-visit verified/deployed media hashes. The card
was not stated to be connected again, so this result-recording turn neither
reads nor writes it and makes no post-visit hash or snapshot claim.

The two matched pairs now provide crossed physical evidence:

- C6513 -> C6514: aligned layout, 3-byte failure / 4-byte success.
- C6512 -> C6515: compact layout, 3-byte failure / 4-byte success.
- Full per-sample comparison proves identical ordered NAL contents, all SEI,
  SPS/PPS apart from AVCC's length declaration, video composition/sync/cadence,
  PCM payload and RTMD payload/boundaries. Prefix width, matching sample sizes,
  affected offsets and unique identity/date fields change as documented.

Thus, for this Cat encoding and SD catalog workflow, the coherent four-byte
NAL-length framing bundle resolves playback in both tested layouts. No VCL
re-encode, EDIUS coded-sample substitution or replacement of existing clips
was required. Both layouts can work for these samples, so the tested
brand/alignment bundle is not a necessary blocker once four-byte framing is
used. The observed minimal catalog supports both listing and playback here;
the 3-byte failures occur after listing/thumbnail presentation.

This is not a claim that all historical failures have one cause. In particular,
C6507/C6509 are separate four-byte native-content controls with prior failure
reports, not retested successes in this message. Nor does this establish a
normative ISO clause, universal acceptance of arbitrary encodings or the exact
hardware rejection branch. Successful playback implies listing for the
successful IDs, but their thumbnail appearance, seeking, full-duration
completion and audio are not separately reported and are not fabricated.

The generator already defaults to four-byte framing. Candidate admission
requires it, while three-byte generation remains explicit diagnostic mode.
The verified Cat SD-card encode/package/catalog/deploy/playback path is now
physically demonstrated; broader input coverage remains separate work.
