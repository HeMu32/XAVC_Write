# Experiment 0019: Native SD Catalog Cross-Check

Date: 2026-11-12, Asia/Shanghai.

## Status And Scope

The user reports that the added candidates are **not listed in the camera's
playback UI**. This is not an observed decoder rejection. C0008 playing in
Catalyst does not establish camera listing or playback.

This experiment took the requested post-recording snapshot first and then
performed read-only analysis. No F: file was created, replaced, or deleted.
No database recovery, formatting, or candidate deployment was performed.

The broad encoding/playback objective remains incomplete. This report
cross-confirms observed native catalog writes; it does not claim the cause
of the candidates' invisibility has been established.

## Authoritative Snapshot Pair

| Snapshot | Metadata copies | Skipped media inventory | Errors |
|---|---:|---:|---:|
| `backup/snap_20261112T194201` (before recordings) | 52 | 103 | 0 |
| `backup/snap_20261112T195043` (after recordings) | 60 | 119 | 0 |

Media contents are deliberately excluded. Their sizes and timestamps are
inventoried; unchanged inventory is not proof of unchanged media contents.

Reproducible comparison: `analysis/sd-native-round-crosscheck.json`.
The earlier `sd-native-round-diff.json` remains the initial observation,
without the later UMID precision interpretation.

Only two existing metadata files changed:
`PRIVATE/DATABASE/DATABASE.BIN` and `PRIVATE/M4ROOT/MEDIAPRO.XML`.
Eight sidecars, eight MP4s, and eight thumbnails were added, with no missing
files or old-media size/write-time changes. AVF_INFO/AVF_ESCP did not change.

Database SHA-256 before:
`f0dcdaaa2034d1bc5b557863efa8569722f2a6cf1c9580f9c65ca60a66d54736`.
After:
`38a90dcfb1f2de1351611204dfc56668ed7a0ef0606d1c71edad452ce446dc67`.
Its size remains 9,670,656 bytes; 563 bytes changed.
All 19 header checksums and all 84 non-root active record checksums pass.

## New Native References

Times below are local +08:00, on November 12, 2026.

| Clip | Body | Start | Frames | Sidecar format | Movie / attributes |
|---|---|---|---:|---|---|
| C6499 | ILCE-7M4 | 19:44:21 | 15 | UHD AVC 4:2:2 10-bit, 29.97p | 73 / 74 |
| C6500 | ILCE-7M4 | 19:44:41 | 90 | HD AVC High@4.2, 59.94p, 50M | 75 / 62 reused |
| C6501 | ILCE-7M4 | 19:44:50 | 60 | HD AVC High@4.0, 29.97p, 16M | 76 / 77 |
| C6502 | ILCE-7M4 | 19:45:00 | 90 | HD AVC High@4.2, 59.94p, 25M | 78 / 79 |
| C6503 | ILCE-7M4 | 19:45:15 | 90 | HD AVC High@4.2, 59.94p, 25M | 80 / 81 |
| C6504 | ILCE-7M4 | 19:45:44 | 60 | HD AVC 4:2:2 10-bit, 59.94p | 82 / 83 |
| C6505 | ILCE-7RM5 | 19:45:58 | 30 | UHD HEVC 4:2:2 10-bit, 59.94p | 84 / 85 |
| C6506 | ILCE-7RM5 | 19:46:11 | 180 | HD AVC High@5.1, 119.88p | 86 / 87 |

Bitrates 16/25/50M in this table come from the database video parameters,
not the sidecar codec name alone. Read-only ffprobe confirms C6502/C6503:
1920x1080, High@4.2, 60000/1001, 90 frames, duration 1.501500 seconds,
24,822,787 / 24,702,401 video bits/s respectively.
C6502 is reported as yuvj420p (full range), C6503 as yuv420p.
They are useful distinct acquisition/color references, not interchangeable
proof that arbitrary re-encoded data will pass.

## Native Allocation And References

Active records increased 70 -> 85: eight content records and seven binary
video-parameter records. The **only old record changed is array record 72**.
C0008/C0009 movie records and their MEDIAPRO entries were retained unchanged.
This proves their disk entries survived the recording round, not that the
camera presented them to the user.

Array 72 existed for C0009 before recording:

- Record type 3, subtype 2, entry size 32.
- Slot bitmap at +6: 1 -> 7; whole-record reference count at +8: 1 -> 9.
- Slot 0 remains C0009's masked UMID.
- Slot 1 is used by all six new M4 clips.
- Slot 2 is used by both new RM5 clips.
- Slots 0 and 1 have identical masked payloads. The reason the first native
  insertion did not deduplicate against slot 0 is not yet established.

`CreateArrayBinaryRecord` (Ghidra 0039267c) first tries a free slot in the
array named by its header pointer. It allocates a new array only if needed.
`SearchArrayBinaryRecord` (0038e3c0) compares masked binary payloads;
`IncrementArrayBinaryRecordRefCount` (00391c28) increments +8 and checksums.
The observed shared references and refcount agree with these operations.

No additional sentinel or path record appeared in this batch despite
body/mode/reboot changes. This does not exclude transient writes or prove
which recording followed which reboot; there are only two disk snapshots.
Historical "INDEX/sentinel" assumptions based on misaligned record offsets
must not be used to invent extra records.

## Header And MEDIAPRO

| Offset | Before -> after | Interpretation |
|---|---|---|
| 0x7c44 | 72 -> 86 | Last content allocation cursor, not highest occupied record |
| 0x7c4c | 72 -> 72 | Current UMID array allocation pointer |
| 0x7c80 | 55 -> 63 | Content count |
| 0x7c84 | 23 -> 23 | Still count |
| 0x7c88 | 32 -> 40 | Movie count |
| 0x8000 | 0xffffffff -> 0x41b90403 | Header parameter 0; meaning still unresolved |
| 0x8010 | updated | Header time parameter 3 |
| 0x8018 | updated | Header time parameter 4 / modification time |

`IssueUniqueId` (00390f3c) updates 0x7c44 when allocating a content ID;
binary attribute allocation does not make this field equal the highest
record index. This explains cursor 86 while attribute record 87 is active.
0x7c40 is a generation value, advanced on allocation wrap, not a clip count.

The final header times decode as 19:46:11.000 and 19:46:13.937 +08:00.
Unlike content-record dates, these u64 fields contain timezone in bits
44..51 with a 0x60 bias. `ConvDefStructLocalTime2SiDBUInt64` at 001aa87c
and `SetHeaderParam` confirm their representation. `Update` (00393bb8)
sets 0x8018 and recomputes the 0xbffc checksum.
These are **not a separate on-disk clip index**. Whether any stale value
participates in higher-level admission remains unproven.

MEDIAPRO changed from 32 -> 40 Materials with exactly eight additions.
No old Material changed semantically, and none was removed.
Root createdAt became `2026-11-12T19:46:13+08:00`; version stayed 2.30.

## UMID Precision: Correction To The Initial Suspicion

The initial comparison found that the current restorer did not reproduce
native sidecar UMIDs exactly. That is **not evidence that its arithmetic
is wrong or that an exact UMID mismatch causes invisibility**.

All eight new native content records store creation time with zero
milliseconds. Their sidecar UMID counters are each reproduced exactly by
the existing firmware-derived arithmetic at a unique subsecond value:

| Clip | Recovered milliseconds within recorded second |
|---|---:|
| C6499 | 801 |
| C6500 | 294 |
| C6501 | 731 |
| C6502 | 396 |
| C6503 | 661 |
| C6504 | 508 |
| C6505 | 328 |
| C6506 | 525 |

The prefix, instance, date, discriminator, and node bytes agree.
Older native reference C6359 similarly fits 237 ms.
Original AArch64 instructions at 003cd954 retain the unusual hour
multiplier and unsigned multiply/divide; they were not changed to a
presumed standard time-counter formula.

The inverse converter's assembly at 0038f374..0038f3cc loads the UMID
array and calls RestorateUMID with LocalTime derived from record+0x10.
`mpr::GetRecordInfo` (001de778) explicitly sets recordInfo's millisecond
member at +0x16 to zero while copying creation date from NRT metadata.
Together with the native samples, this supports a lossy reconstruction
path rather than exact sidecar-UMID equality as a universal requirement.

This diagnoses the observed discrepancy; it does not prove the camera's
complete UMID matching policy. Earlier historical clips are not all explained
by this narrow model and were not silently normalized or edited.
The synthetic package verifier's exact round-trip remains a conservative
self-consistency check, **not a camera-visibility oracle**.

## Candidate Cross-Checks And Remaining Gap

C0008/C0009 and new native clips use the same three path references
31/30/29 (MP4/XML/JPG), no proxy reference, content type 2, and word04=2.
Their restored paths are correct for their respective clip numbers.
The path chains and record checksums pass.

The candidates' 40-byte video parameter payloads differ from C6502 only
at payload+17..19 (record+27..29): candidates have unspecified acquisition
values 00/00/00, C6502 has 55/35/03. Their bitrate, codec, resolution,
frame-rate and audio parameter bytes otherwise match. These color bytes
were deliberately cleared previously; copying them back without matching
the media/XML would not be a justified fix.

Differences in the current stager:

- It always allocates three records instead of searching/reusing attributes
  and the current UMID array.
- It sets 0x7c44 to the final support record rather than the movie record.
- It leaves header parameters 0 and time parameters 3/4 unchanged.
- Its checks demonstrate local construction consistency, not UI admission.

These differences are now grounded in native behavior, but none is yet
isolated as a necessary cause of the listing failure. The firmware's
allocator can skip occupied records; a non-native cursor alone is not
proof that a content record is undiscoverable.

`GetRootSet` (003a8760) scans the bitmap/content type, optionally checks
record+6 bit4, and checks a **runtime on-memory flag** when the corresponding
include flag is false. It does not require a separate persistent INDEX
record. Candidates and new native records have bit4 set.
`Select` (0038f550) validates the record checksum before restoring its data.
Higher-level format refiners and the runtime flag's producers remain to
be traced before treating these base predicates as full UI eligibility.

Next investigation is the population of the on-memory exclusion flag and
the root-set-to-playback format filtering/refresh path. With C6502/C6503,
there is now a matching native profile for that comparison. No additional
codec patch or card write is warranted merely by desktop decode success.

## Reproduction And Preservation

```powershell
& 'E:/anaconda3/envs/test311/python.exe' tools/compare_sd_snapshots.py backup/snap_20261112T194201 backup/snap_20261112T195043 --output analysis/sd-native-round-crosscheck.json
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests
& 'E:/anaconda3/envs/test311/python.exe' tools/audit_card_snapshot.py --card F:/ --snapshot backup/snap_20261112T195043 --output analysis/card-unchanged-native-round-final.json
```

76 tests pass. New tests use literal native dates, UMIDs, and complete
M4/RM5 records/array bytes, not only encoder-generated round trips.
The literal record/array fixtures were also checked byte-for-byte against
the saved snapshot. All headless processing used the existing independent
project in read-only mode; no firmware was executed or flashed.

Final preservation audit: `analysis/card-unchanged-native-round-final.json`.
As with the snapshot method, it hashes metadata and checks media sizes and
write times, not all media contents or raw exFAT sectors.
