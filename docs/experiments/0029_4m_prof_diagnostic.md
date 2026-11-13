# 0029: 4Mbps / PROF paired diagnostic

## Scope and status

2026-11-13. Four **experimental**, not camera-qualified profiles. The five
ordinary profiles in `sony_profiles.PROFILES` are unchanged. Physical listing,
thumbnail, playback, audio, complete duration and seek remain separate
observations. No physical outcome is predicted by the software verdict.

Preparation/deployment complete. Subsequent database repair and0031 correction
are now recorded below. Historical deployment/pair reports are not rewritten.
Final regression: **283 tests passed**, 226.531s,
`analysis/0029-regression-complete.log`. Earlier278/279-test runs also passed.
The four added summary-binding tests reject a passing audit from a different
card, baseline, package order/hash or incomplete readback. No card changes
were made for this reporting-only hardening.
Final audit: `analysis/sd-test-round-0029.json`, all six checks passed.

| Test | Clip | Base control | FPS | Coded / NAL HRD / VCL HRD / CPB | PROF average / maximum |
|---|---|---|---|---|---|
| 29-A | C6521 | C6520, hd16_2997 | 30000/1001 | 4Mbps / 4Mbps / 4Mbps / 4Mbit | 16000 / 16000 kbps |
| 29-B | C6522 | C6520, hd16_2997 | 30000/1001 | same payload as 29-A | 4000 / 4000 kbps |
| 59-A | C6523 | C6515, hd25_5994 | 60000/1001 | 4Mbps / 4Mbps / 4Mbps / 4Mbit | 25000 / 25000 kbps |
| 59-B | C6524 | C6515, hd25_5994 | 60000/1001 | same payload as 59-A | 4000 / 4000 kbps |

Both cadences retain 1920x1080, High, 8-bit 4:2:0, GOP30, B2,
no B-pyramid, ref2, four slices, closed GOP, Rec.709 limited range,
four-byte AVC NAL lengths, dual CBR HRD and retimed buffering-period SEI.
29p retains level4.0; 59p retains level4.2.

Exactly two full Cat encodes were made. Duration is 25.592233333 seconds:
767 / 1534 frames, respectively. All four have 1,228,427 stereo PCM16BE
samples per channel at 48kHz, without trimming or added silence during packaging.
All four creation timestamps are `2026-11-13T17:03:26+08:00`.

## Baseline and allocation

- Initial snapshot: `backup/snap_20261113T165324`, 73 metadata files,
  145 skipped-media inventory entries, zero errors.
- Comparison with `backup/snap_20261113T153706`: no metadata or media
  size/write-time changes; 117 old active database records unchanged.
- C6521-C6524 were selected only after checking all current card filenames,
  database movie records and MEDIAPRO URIs. These were actually unused.
- C6520 SHA256:
  `bd191099d30e7bc3921a0f4f3e18aba71d095f924d20458180fbf2a67e9f377b`
- C6515 SHA256:
  `f6815df190cda04a3dcd500aba0df6c4ac1859f22838297b337c3b2f1b0f63e5`
- Allocation uses only each current snapshot's repaired database.
  `backup/snap_20261113T135135` supplies only the sparse descriptor template,
  with hash-bound, identical live path/support dependencies. Empty support
  record28 is reused. No historical database is restored.

The first four local catalog previews all used the initial snapshot solely
to check all four media packages before any write. These previews are not
four cumulative transactions. After each actual deployment, the following
package is re-staged against a new readback snapshot and fully reverified.

## Evidence and interpretation

`analysis/0029-pair-29.json` and `analysis/0029-pair-59.json` bind manifests,
source specs, shared encoder bases/assumptions, MP4, XML and thumbnails.
Both complete `mdat` boxes, all three track payload hashes, `avcC`,
sample descriptions/tables/mappings and complete `moov` are equal within
each pair. Exact full-file masks allow only parsed VPRF payload offsets
20/24 and the parsed TargetMaterial UMID attribute. Both pairs have
33 changed MP4 bytes (four actual PROF bytes, 29 UMID bytes) and 29 changed
sidecar XML bytes, with zero unexpected changes. Thumbnails are identical
within each pair.

| FPS | Video samples including lengths | All NALs without lengths | VCL only | Filler only | 1s peak video |
|---|---|---|---|---|---|
| 29.97p | 4.022107Mbps | 4.016303Mbps | 3.971634Mbps | 0.042403Mbps | 4.318744Mbps |
| 59.94p | 4.049350Mbps | 4.037775Mbps | 4.032998Mbps | 0Mbps | 4.534152Mbps |

These are measured finite-file rates, not an assertion of exactly 4,000,000
bits in every one-second window. Windows charge whole access units whose
DTS is in `[start, start+1s)`; tails are zero padded to one second.
PCM, RTMD and container overhead are additional to video bitrate.
Both NAL and VCL CPB schedules pass the selected existing checker.
No universal minimum bitrate or necessity of every HRD field is established.
Actual sync sample positions match C6520/C6515, beginning1,31,61.
The parsed slice histograms are exactly767/1534 samples with four slices each;
both SPSs declare max_num_ref_frames2, max_num_reorder_frames1 and
max_dec_frame_buffering2.

Raw original-reader reports are `analysis/0029-reader-C6521.json` through
`C6524.json`. Firmware executable sections are unchanged:

| Clip | Original property-query status | Original selected-reader verdict |
|---|---|---|
| C6521 | 0 | true |
| C6522 | **3** | **false** |
| C6523 | 0 | true |
| C6524 | 0 | true |

C6522's failure is preserved verbatim. The diagnostic assessment accepts
only that precise, predeclared rejection at
`original_movie_property_query`, ELF VMA `0x228fa8`, after all earlier
status-returning calls returned0. Emulator failure, timeout, a different
call/status, changed executable bytes or missing evidence are never waived.
Successful SDK probes check one video sample against an independent sample
index, parameter sets, selected frame tables and RTMD first/second/last.
They are **not** full hardware decode tests. Full FFmpeg decoding and
frame/timestamp/PCM comparison are separately performed for all four.

## Reproduction

Run from the workspace using `E:\anaconda3\envs\test311\python.exe`.
The commands below are templates, not authorization to overwrite these IDs.
For another round choose four unused IDs, fresh output directories, fresh
spec/report paths and a common new creation timestamp.

1. Confirm the card is F:, capture `tools/card_snapshot.py --card F:/ --output backup`,
   inspect `_snapshot.json` for zero errors, compare against the previous
   snapshot, check filenames/DB/MEDIAPRO occupancy and old control hashes.
2. Create the four explicit JSON specs. This round's complete examples are
   `analysis/0029-{29,59}-{A,B}.json`. The schema records the baseline profile,
   coded bitrate, HRD bitrate, CPB capacity and each PROF declaration separately.
   Unknown fields, malformed numeric values, contradictory variants, other
   rates/profiles and a timestamp without timezone are refused.
3. Encode once for each cadence:

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/encode_xavc.py Cat_25-12-25.mp4 --output output/bitrate-0029-29/encode --experiment-spec analysis/0029-29-A.json --threads 6
& 'E:\anaconda3\envs\test311\python.exe' tools/encode_xavc.py Cat_25-12-25.mp4 --output output/bitrate-0029-59/encode --experiment-spec analysis/0029-59-A.json --threads 6
```

4. Build A/B from the **same** base.mov for each cadence. Example 29-A:

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/build_sony_clip.py --base output/bitrate-0029-29/encode/base.mov --camera analysis/C6359-reference-0023.MP4 --edius analysis/C0001-reference-0026.MP4 --structure-template analysis/C0001-reference-0026.MP4 --umid-mode edius_uuid4 --payload-layout structure_template --acquisition rec709 --experiment-spec analysis/0029-29-A.json --clip C6521 --output output/bitrate-0029-29/A --diagnostic-peer output/bitrate-0029-29/B --pair-report analysis/0029-pair-29.json --reader-report analysis/0029-reader-C6521.json
```

For29-B use the same base/camera/EDIUS/structure template, B spec, C6522,
output `/B`, reciprocal peer `/A`, shared pair report and C6522 reader report.
For59-A/B use `output/bitrate-0029-59/encode/base.mov`,
`analysis/C0007-reference-0023.MP4` as **both** EDIUS and structure template,
59 specs, C6523/C6524 and corresponding 59 paths.

The builder edits only the local MP4/XML/manifest. It normalizes SPS VUI
and dual HRD, retimes SEI, rebuilds four-byte NAL framing and sample tables,
retains the encoded VCL and PCM, generates RTMD, sets identical dates,
allocates UUID4 UMIDs and writes explicit PROF declarations. B reuses the
same normalization input/settings, so payload identity is checked, not assumed.

5. Generate A thumbnails with `tools/build_sony_thumbnail.py --clip MP4`;
   copy each local A thumbnail to its B filename using `Copy-Item`.
6. Run `tools/compare_bitrate_pair.py --a A_PACKAGE --b B_PACKAGE --output PAIR_REPORT`.
   This report is independent of catalog staging, so fresh allocation does not
   invalidate pair evidence.
7. Run `tools/bitrate_reader_evidence.py --media MP4 --experiment-spec SPEC
   --snapshot SNAP --output READER_REPORT`. It invokes the original emulator
   with seek-mode1, sample-batches1, decode-table and RTMD probes, preserves the
   original raw verdict, and writes a separate assessment. This round invoked
   the equivalent emulator command directly before validating the raw reports.
8. Run the full regression suite:
   `python -m unittest discover -s tools/tests -v`.
9. Stage and verify **one current cumulative transaction at a time**:

```powershell
python tools/stage_sd_catalog.py --snapshot CURRENT_SNAPSHOT --build PACKAGE --template-number 7 --catalog-representation observed_minimal --template-snapshot backup/snap_20261113T135135
python tools/verify_sony_package.py --build PACKAGE --experiment-spec SPEC
python tools/verify_staged_catalog_firmware.py --build PACKAGE
python tools/deploy_sd_clip.py --card F:/ --build PACKAGE --allow-diagnostic
python tools/deploy_sd_clip.py --card F:/ --build PACKAGE --allow-diagnostic --apply
python tools/card_snapshot.py --card F:/ --output backup
```

If an initial local preview `catalog/` exists, stage again with
`--archive-local-stage` to preserve it and create the new current stage.
Dependency or stale-baseline failure means stop. Do not restore the historical
database. The deployer creates new clip assets exclusively, updates only both
catalogs, fsyncs and hashes every written resource, and checks old resources.
Never delete card files to retry a partial transaction.

Actual cumulative staging/readback chain:

| Clip | Allocation snapshot | New DB record | Post-write snapshot |
|---|---|---|---|
| C6521 | snap_20261113T165324 | 120 | snap_20261113T171735 |
| C6522 | snap_20261113T171735 | 121 | snap_20261113T172037 |
| C6523 | snap_20261113T172037 | 122 | snap_20261113T172412 |
| C6524 | snap_20261113T172412 | 123 | snap_20261113T172719 |

The deployer also captured immediate pre-write snapshots171723,172022,
172401 and172705. Every snapshot completed with zero errors.
Final snapshot has77 metadata files and153 media inventory entries.
Only12 new assets and two changed catalogs were found. All117 original
database records are bit exact; active records117->121, movies53->57.
Old metadata outside both catalogs is hash-identical; old media size and
write time are unchanged. Only selected old media (C6520/C6515) were
rehashed, not all old MP4/JPG bytes.

Final DATABASE.BIN SHA256:
`89fed18ee745c739ee59ef11e0aecc1a4d0a3a16f13c8ae75748e5b9dd27888a`

Final MEDIAPRO.XML SHA256:
`be8be1daf9cfc3cdc9215ff912745e8f9a0d1c0acb12af439db3d6ea2ca1cb00`

Repeat step9 in order29-A,29-B,59-A,59-B, each time using the just-captured
snapshot. Then run `audit_sd_test_round.py --allow-diagnostic` over the
ordered packages; compare initial/final snapshots and all old DB records;
rehash C6520/C6515. Final report:
`analysis/camera-test-round-0029.json`, generated by
`tools/summarize_bitrate_round.py`, contains exact evidence hashes and the
actual snapshot chain. `analysis/sd-test-round-0029.json` is the final audit.

## Camera Test

Check unchanged C6520 and C6515 first, then C6521, C6522, C6523, C6524.
For each, independently record: listed, thumbnail, starts playback, completes
about25.6s, audio, seek and any message. Distinguish "not listed" from
"cannot display". Do not repair the database mid-round unless explicitly
recorded as another intervention.

- A plays, B fails: same low-rate payload with different PROF behaves differently;
  supports declaration/classification involvement, not a low-rate picture failure.
- Both play: physical success evidence for that frame rate and 4M declaration.
- Both fail: not proof of a minimum hardware bitrate; retain HRD timing,
  other admission paths and hardware behavior as unseparated hypotheses.
- A fails, B plays: record the reverse result and investigate without imposing
  the expected pattern.

Do not append unplanned files in response to a failure in this round.

## First Physical Feedback Before Database Repair

2026-11-13 user report: `6521~6524只有6522无法播放.`

- C6521 / 29-A: playback success, user reported.
- C6522 / 29-B: unable to play, user reported. Listing state, thumbnail,
  exact failure stage and camera message were not separately reported.
- C6523 / 59-A and C6524 / 59-B: playback success, user reported.
- Complete duration, audio and seek remain unreported for all four.

Recorded in `analysis/camera-observations-0029-before-repair.json`.
The original preparation report retains its historical NOT_TESTED state.
All four card MP4 hashes were freshly checked and still match the prepared
files. Before the user's planned database repair, snapshot
`backup/snap_20261113T180914` captured77 metadata files and153 skipped-media
inventory entries, with zero errors. No card files were written by the agent.

That was the end-of-round status at the time. Subsequent evidence:

## Database Repair and0031 Follow-up

After repair, the user reported C6520/C6521 were no longer listed, while
previously playable other clips remained playable. Snapshots independently
showed that DATABASE dropped C6520/21/22 records without changing their media,
sidecars or MEDIAPRO. See0031 for the complete evidence and limits.

The29p XML name was incorrectly generated as `HP@L40`, while the original
firmware and native C6501 use `HP@L4`. Original code tests on the same XML
with only this name changed switch basic-information extraction from3 to0;
the reverse mutation of normal C6519 switches0 to3.
This is separate from C6522's original MP4 PROF property-query rejection.

On2026-11-14 the user confirmed corrected/re-cataloged C6520/C6521 are listed.
Corrected-file playback and survival of another repair were not separately
reported. Preserve the first playback feedback and original pair hashes.
The corrected C6521 file has a different whole-file hash, but identical media
payloads. Source: `analysis/camera-observations-0031-result.json`.

A later fresh snapshot for0032 contains a new sparse C6522 record129.
That is a catalog observation, not new physical listing/playback feedback.
Actual rate control is libx264's existing mechanism; this project configures
it and separately adjusts Sony metadata/timing. No new rate controller or
general minimum bitrate has been established.

## Second Repair Follow-up: 0033 / 2026-11-14

After corrected C0010 was reported playable, the user performed another repair.
The new snapshot keeps all58 movie numbers. Corrected C6521 and C6520 stay
at records128/127 and are populated with16M/29.97p support131, alongside
C0010 at130. C6522 moves from129 to132 but remains sparse, with its original
L40 XML and4M declaration unchanged. Slot removal is not clip removal.
Selected complete media hashes remain unchanged. This strengthens the
XML-correction/catalog-rebuild evidence, not a claim about a universal minimum
bitrate. Post-repair physical listing/playback remains unreported.
See `0033_second_repair_observation.md`; no card files were modified this round.
