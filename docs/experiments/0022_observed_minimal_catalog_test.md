# Experiment 0022: Observed Minimal Catalog Test

Date: 2026-11-12, Asia/Shanghai.

## Status

Subsequent physical result: C6509 and C6510 are listed, their thumbnails
are normal, and both reject playback with the camera message "Cannot
display". C6507/C6508 are also listed with the same playback rejection.
The user cannot distinguish an earlier visibility oversight from a later
state change for C6507/C6508. Do not credit this experiment with causing
their visibility. Latest observations:
`analysis/camera_observations_20261112_233331.json`.

The paragraphs below describe the historical deployment checkpoint.

Both C6509 and C6510 have been deployed with durable readback and no
unexpected existing-file changes.
Physical listing and playback are NOT_TESTED.
No root cause is established. This is a controlled alternative catalog
representation, not a claim to have reconstructed the native writer.

## Preservation Baseline

`backup/snap_20261112T231514`: 62 metadata files, 123 media inventory
entries, zero errors. Compared with `snap_20261112T230700`, no metadata
content/file-set, media size/mtime, database-record or header-word changes.
Comparison: `analysis/snapshot-230700-231514.json`.

Media contents are excluded from snapshots. The preservation audit is
metadata hashes plus old-media sizes/write times, not a full-card image.
No deletion or replacement of an existing clip is permitted.

## Samples

| Clip | Media | Duration | Package |
|---|---|---|---|
| C6509 | New-identity copy of native C6503 | 90 frames / 1.5015 s | `output/native-minimal-C6509` |
| C6510 | Existing Rec.709 Cat encode, repackaged | 1534 frames / 25.592233 s | `output/cat-minimal-C6510` |

Both are 1920x1080, 60000/1001p, AVC High@4.2, 8-bit 4:2:0, nominal
25 Mbps, with 48 kHz stereo 16-bit PCM. Native C6509 measures about
24.7024 Mbps; Cat C6510 measures about 25.2941 Mbps.

C6503 and C6507 are NOT_LISTED, so C6509 is not a known-visible positive
control. Its purpose is to hold native coded samples constant across an
alternative catalog representation. C6510 similarly uses the already
prepared Cat base, not a new encode with unrelated parameter changes.

Independent `native_payload_checks` comparisons found the entire mdat,
every track's coded samples, sample entry, timing/sample tables and media
duration byte-identical for both C6507 -> C6509 and C6508 -> C6510.
New UMIDs, NRT creation/update dates and container header dates remain
differences. Clip numbers also differ. This is not a single-field test.

## Catalog Design

All nine user-reported visible examples use content byte 6 = 0x18,
sparse video attribute record 28, no UMID-array reference, and zero
catalog timecodes. The examined negative examples use a different
group of representations. This is correlation, not a causal finding.
Both forms passed the earlier original firmware helpers.

The new explicit `observed_minimal` staging mode copies the content
descriptor of user-confirmed listed C0007, keeping its unknown fields,
paths, sparse attribute reference and optional-metadata omissions.
Only new identity/number/dates/file-size/checksum fields are substituted.
Existing records, including every UMID array, remain byte-identical.
MEDIAPRO gains a normal Material with the new identity; embedded NRT,
sidecar and that Material retain matching, nonduplicated UMIDs.

Record 28 is not claimed to describe actual video parameters. It is
shared by visible examples with different resolutions/codecs. Catalog
UMID/video/timecode omissions are explicitly reported, not represented
as matching the media. Acquisition remains genuinely Rec.709 in the
stream and NRT; the sparse catalog does not specify it.

Verification schema 4 admits this mode only with explicit representation
agreement, an exact rebuild, an observation-hash-bound positive template,
and preservation checks. Encoded AVC still requires fresh frame hashes,
audio equality, SEI timing, progressive slice order and selected CPB
checks. Native controls still require original-source identity and exact
mdat, configuration and track payloads.

The verification now binds the exact baseline database/profile hashes,
transaction, build manifest and all five deployable files. Every writer
requires the complete hash-key set, rejecting incomplete or stale package
bindings. Optional-metadata omissions are derived from the verified mode.
Old schema-3 reports require fresh verification before any new write.

## Verification And Deployment

- First full suite: 119 tests passed.
- Final full suite after hash-binding changes: **120 tests passed**.
- Additional complete-package hash-binding test: 14 focused verification
  tests passed, including refusal of omitted keys and changed transactions.
- C6509 fresh verification passed all 29 checks.
- C6509 original firmware staged-catalog checks passed for 43 movies,
  including every called nested reader and all original profile queries.
- C6510 fresh verification passed all 28 checks, including fresh decode
  hashes, SEI/container timing, slice order and selected CBR/CPB checks.
- Final staged catalog passed original firmware checks for all 44 movies.
  Each nested reader returned success; all original profile queries
  succeeded. This does not emulate mounting, the UI or the decoder.
- C6509 deployment pre-write snapshot: `snap_20261112T232603`.
- After C6509 snapshot: `snap_20261112T232616`, 63 metadata / 125 media
  inventory entries, zero errors.
- C6509 allocates record 90; C6510 stages record 91. Both reuse sparse
  attribute 28. No existing record or UMID-array reference count changes.
- C6510 deployment pre-write snapshot: `snap_20261112T232803`.
- Final snapshot: `snap_20261112T232817`, 64 metadata / 127 media
  inventory entries, zero errors.
- Final combined audit: `analysis/C6509-C6510-card-audit.json`, passed.
  All six new assets and both final catalogs match verified hashes;
  all prior metadata other than the two catalogs is unchanged; all
  prior media size/write-time inventory entries are unchanged.
- Snapshot delta: `analysis/C6509-C6510-deployment-diff.json`.
  Active records 87 -> 89; added records 90 and 91; changed/deactivated
  existing records: none. Movie count 42 -> 44; still count unchanged.
- No files were deleted, and no old clip assets were replaced.
- Scoped `git diff --check -- docs tools` passed.

Media SHA-256:

- C6509: `abab47d3650607fcb185b57b1e1b1cca313b8b4d4f38f4161ac0b1c0be48b781`.
- C6510: `18a2bc5e6a0c5839579304711b9177692494bff501dafecbe1eaf69b89a3890d`.

Both package `camera-result.json` files remain NOT_TESTED until a physical
camera result is supplied. Preparation complete does not mean the overall
camera-playback objective has been achieved.

## Camera Test

Safely eject using the operating system. Do not format, reconstruct,
repair the database or record new footage during the initial check.

1. Confirm an old positive example, preferably C0007 or C6349, still
   appears on the same body and playback view.
2. Find C6509 (about 1.5 s), record listing and thumbnail separately.
3. Find C6510 (Cat, about 25.6 s), record listing and thumbnail separately.
4. For anything listed, test playback, sound and seeking.
5. Report the body used and each sample's listing/playback result.

Exact error wording is optional. If neither appears, that is NOT_LISTED,
not a decoder failure. If either appears, the result supports further
isolation of this bundle of differences; it does not identify one flag,
UMID handling or an individual field as the root cause.

Firmware helper success is not full mount/UI/decoder success. Only the
user's physical camera check can resolve this round's admission result.
