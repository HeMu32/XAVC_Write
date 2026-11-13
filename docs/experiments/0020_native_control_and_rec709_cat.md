# Experiment 0020: Native Control And Rec.709 Cat

Date: 2026-11-12, Asia/Shanghai.

## Current Result

Subsequent camera result, reported by the user on 2026-11-12:
**C6507 and C6508 are not listed**. The user also confirms that native
C6500-C6506 are currently not listed. C6503 therefore cannot be treated as
a confirmed visible/playable reference. See `analysis/camera_observations_20261112.json`
for the non-exhaustive positive examples and the limits of this observation.
The NOT_TESTED language below is the earlier deployment checkpoint, not
the current listing result. Playback was not reached for unlisted clips.
No root cause has been established from these observations.

Historical deployment checkpoint: two new clips were on the SD card.
Desktop/local verification and card readback passed. Camera listing and
playback had not yet been tested at that checkpoint; the current result
is **NOT LISTED**, as stated above.
Earlier C0008/C0009 listing failures remain valid evidence; this deployment
does not retroactively change their result.

| Clip | Purpose | Frames / Duration | Local Package |
|---|---|---|---|
| C6507 | New-identity copy of native C6503, retaining native coded samples | 90 / 1.5015 s | `output/native-control-C6507` |
| C6508 | Cat, newly color-converted and encoded, native-style catalog reuse | 1534 / 25.592233 s | `output/cat-rec709-C6508` |

Both are AVC High@4.2, 1920x1080, 60000/1001, 8-bit 4:2:0, nominal 25M,
with 48 kHz stereo 16-bit big-endian PCM.
C6508's measured video average is 25.294075 Mbps, not exactly 25.000000.

C6507 SHA-256:
`87e49bcb2d8f79536413dcc22498c780587d550cbd7fc98e23e545812afa3764`.
C6508 SHA-256:
`98ecfd98ea21dfa8c53f76452cf01aa2c8a2b2f84b6b9a28df72190127899a01`.

No original or previous test clip was replaced or deleted. The six new
MP4/XML/JPG files and the final two catalogs were read back and match
their verified local hashes. All old metadata hashes other than those
two catalogs, and all old-media sizes/write times, remain unchanged.
Original C6503 was additionally rehashed and matches its captured source hash.

Authoritative preservation report:
`analysis/C6507-C6508-card-audit.json`.
It does not hash every old media file or raw exFAT sectors.

## Test Order

Safely eject the card through the operating system before camera use.
Do not format or invoke database recovery as part of this controlled test.

1. Confirm that original C6503 is visible/playable on the tested body.
2. Look for **C6507**, the 1.5-second native-codec copy.
3. Look for **C6508**, the approximately 25.6-second Cat clip.
4. Report listing/thumbnail separately from playback, sound, and seeking.
   Exact error text is optional; absence from the list is already a
   meaningful result. Record which body was used.

If C6507 is invisible too, the added identity/catalog/list-filter path is
still suspect despite known native coded samples. This is not a pure
single-variable database test: new UMID, NRT dates and container dates are
also part of the new-identity control. If only C6508 fails, compare the
generated media/metadata path against the admitted native control before
making more card changes.

## Native Control

`build_native_control.py` retains C6503's entire `mdat`, including its
native tail allocation; video, audio and rtmd samples; track/sample tables;
AVC configuration; thumbnail; and original timecodes.
It changes UMID/NRT identity and dates plus container creation/update dates.
The preserved camera/lens/sensor metadata describes the source recording,
not a new physical camera capture.

Fresh decoding confirms all 90 frames and timestamps match C6503.
All track samples, configuration/sample tables and complete mdat are
compared byte-for-byte, and the native source XML is bound to its snapshot.

The selected generated-AVC timing checker does not support the native
source's pic_struct syntax. Rather than editing native syntax to satisfy
that checker, verification uses an explicit `native_control` profile
requiring exact native data/configuration and source identity.
This profile cannot satisfy the encoded-AVC writer contract.
C6508 still requires all generated-AVC timing, slice-order and selected
CPB checks; none was waived.

## Cat Color Correction

A first local C6508 preparation reused the old Cat base. A fresh stream
probe then found that base's transfer characteristic was BT.470M/gamma22,
matching the source input, not Rec.709. It was not deployed.
The earlier local `output/cat-native-catalog-C6508` is superseded evidence,
not the current card C6508.

The actual Cat source is HEVC 3840x2160 with BT.709 matrix/primaries,
BT.470M transfer, limited range. The current `encode_xavc.py` driver
explicitly transforms transfer/matrix/primaries/range to BT.709, scales
to 1920x1080 and encodes the 25M base:
`output/cat-rec709-base-C6508/base.mov`.

The new packaged stream's range/matrix/transfer/primaries all agree with
the Rec.709 NRT acquisition declaration and catalog parameter bytes.
The verifier now probes this relationship instead of trusting a label.
Fresh full decoding produces 1534 frame hashes/timestamps matching the
new encoded base; PCM audio matches that base. This is a packaging
round trip, not a claim of pixel identity with the unscaled HEVC input.

All selected timing, four-slice ordering, and CBR/CPB checks pass.
These remain selected checks, not a complete certification or camera test.
The new package uses native C6503 for container templates and minimal
generated EDIUS-style rtmd, without fabricated camera/lens/sensor data.

## Native-Style Catalog Changes

The stager was updated from always allocating three records to:

- Allocate a content record from the content cursor, preserving generation.
- Search/reuse the matching 40-byte video parameter record.
- Search/reuse an occupied matching UMID array entry; otherwise fill only
  a free entry in the current array, or allocate an array when necessary.
- Increment the whole-array reference count and recompute checksums.
- Maintain content cursor, counts, and packed header time fields.
- Leave unknown header parameter 0 at 0x8000 unchanged.

For this round, **both clips reuse video attribute record 81 and array
72 / slot 1**, as do the native Rec.709 references.
No new attribute, path, or UMID-array record was needed.

Across the pair, the only new active indices are 88 and 89.
Every old content/path/attribute record is byte-identical.
Array 72's old slots and bitmap are unchanged; its refcount changes 9 -> 11.
The content cursor changes 86 -> 89 (index 87 was already occupied).
Movie count changes 40 -> 42, still count remains 23.
All 19 header checksums and all non-root record checksums pass.

`validate_catalog_changes` validates the complete database byte surface,
including inactive storage and header fields, and rejects changes outside
the declared allocation/reference/time/count/checksum areas.
The stager conservatively refuses allocation wraparound, high record IDs,
or inactive slots containing residual bytes; these are not claimed supported.

## Verification Contract

Verification schema is now **3**. Encoded and byte-preserving native
profiles are distinct. Both bind acquisition XML/catalog evidence; a
Rec.709 package also requires measured stream-color agreement.
Writers reject older reports and profile/acquisition mismatches.
The unit suite has 91 passing tests at this checkpoint.

Final Cat verification, including card readback:
`output/cat-rec709-C6508/verification.json`,
fresh run `verification_runs/run-qq97awcr/`.
Native control verification:
`output/native-control-C6507/verification.json`.
Its intermediate catalog belongs to the first deployment; the final
combined catalog belongs to C6508's transaction. The combined audit
handles that deployment ordering explicitly.

## Snapshots And Diffs

| Snapshot | Purpose | Metadata / skipped media |
|---|---|---|
| `snap_20261112T204143` | Initial round baseline | 60 / 119 |
| `snap_20261112T205613` | Immediately before C6507 write | 60 / 119 |
| `snap_20261112T205636` | After C6507 / before C6508 staging | 61 / 121 |
| `snap_20261112T210736` | Immediately before C6508 write | 61 / 121 |
| `snap_20261112T210906` | Final post-write snapshot | 62 / 123 |

All snapshots have zero reported errors.
Combined delta: `analysis/C6507-C6508-deployment-diff.json`.
Both `deployment.json` files report deployed, deleted=[], and no
unexpected old-file changes.

## EDIUS Parallel Investigation

See `docs/edius-writer-catalog-notes.md` for the bounded installed-plugin
survey and actual static-analysis limitations. The XAVC-S plugin has
M4ROOT/MediaProfile/NRT material, but no recovered binary SD catalog
writer chain. No EDIUS-derived database patch was applied.

The physical admission/playback objective remains active and unproven.
