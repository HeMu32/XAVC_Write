# Experiment 0018: Fresh Verification And The Physical Camera Gate

Date: 2026-11-12, Asia/Shanghai.

## Subsequent User Evidence

Superseded status: the user subsequently reported that the added candidates
do **not appear in the camera playback list**. Treat this as a listing
failure, not merely an unperformed playback test or an observed decode error.
Experiment 0019 records the requested before/after native recording snapshots
and read-only catalog cross-check. The original checkpoint below is retained
as history; it is not the current diagnosis or reason to stop investigation.

## Current Result

C0009 remains deployed, unchanged:
`F:/PRIVATE/M4ROOT/CLIP/C0009.MP4`.

SHA-256:
`67392a22ff8ba52193b896178afbce2c11d2cfc42180292a6ec96fcb429eee97`.

Physical camera playback is still **NOT TESTED**. This goal is not complete.
No card file was written, replaced or deleted during this continuation.

Snapshot `backup/snap_20261112T191052` contains 52 metadata files and 103
skipped-media timestamp entries, with no errors. The read-only comparison
against the post-deployment snapshot 190318 reports no added/missing files,
metadata hash changes, or media size/write-time changes:
`analysis/card-unchanged-0018.json`.
It does not hash every original media file.

## Verification Gap Closed

The old package verifier compared existing frame-hash files and did not
automatically run the new SEI/container, progressive slice-order and selected
CPB checks. Both writers accepted its top-level `passed` field and file hashes.
That left the new requirements dependent on manual command sequencing.

`sony_verification.py` now provides the common contract:

- Re-decode the actual base and packaged video into new, isolated proof
  directories. Do not reuse older `base.framemd5` or clip frame-hash files.
- Require nonempty, expected-count frame hashes AND timestamps to match.
- Run timing, slice and selected CPB checkers automatically.
- Bind each checker's result to the actual package video SHA-256.
- Rehash base/media after these operations to detect changes during checking.
- Require verification schema 2, all required check names, and literal boolean
  true values before either additive deployment or owned-clip revision.

Existing package-file hash and card-state safeguards remain in the writers.
Old verification reports must be regenerated; this does not itself rewrite
the media or card.

The checks remain local evidence, not full H.264/XAVC certification, complete
firmware execution, or a replacement for physical playback.

## Tests And Actual Run

The suite now has **68 passing unit tests**. New coverage includes rejection
of legacy/incomplete/nonboolean reports, empty successful decoder output,
decoder failure despite valid-looking cached frames, stale checker hashes,
and separation of process logs from the checkers' own trace files.

The first real integration run exposed a log-path collision: the outer
runner and the timing checker both used `timing.log`. The child's trace
hash changed, so the CPB checker refused it. This failed run is retained in
`output/cat-25m-hrd/verification_runs/run-zk04xirc/`.
The collision was fixed by using distinct `*-process.log` files, not by
weakening the hash check.

The successful real run is:
`output/cat-25m-hrd/verification_runs/run-cdle2ghc/`.

All five subprocesses exited zero. All 1534 newly decoded frame hashes and
timestamps match the base. The 26 package/card checks pass, including all
five deployed-file readback hashes.
The authoritative current report is
`output/cat-25m-hrd/verification.json`, schema 2.

```powershell
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests
& 'E:/anaconda3/envs/test311/python.exe' tools/verify_sony_package.py --build output/cat-25m-hrd --card F:/
```

## Available Device Evidence

Windows identifies F: as disk 4, `Exascend EXACS_SD`, USB, online.
The present-device query found Bluetooth records for two Sony camera names
and a remote-desktop camera bus, but no Sony USB camera device.
Bluetooth registration/presence is not evidence of a live or usable
physical-camera playback connection. No BLE command or camera setting was
changed, and the card was not ejected automatically.

The native C6359 sidecar identifies its recording device as ILCE-7M4.
This supports the model relevance of the M4 firmware material, but does not
establish the target camera's currently installed firmware version.

## Completion And Blocker Audit

The same unresolved external gate was recorded in the three consecutive
continuations represented by experiments 0016, 0017 and 0018:
there is no observed physical-camera playback result.

The preceding continuation made substantive progress by retiming HRD and
deploying C0009. This continuation also made progress by making fresh media
checks mandatory and verifying them end to end. Neither is a verified wait
for a live camera test, and neither satisfies the final playback requirement.

The objective remains intact: Sony-side admission and playback of the
requested FFmpeg-generated 1080p59.94 25M 4:2:0 media on an SD card.
Further unobserved candidate changes or repetition of desktop checks cannot
establish that result. The remaining hardware-specific uncertainties cannot
be resolved by declaring these local checks equivalent to camera acceptance.

At this point the concrete required external action is to safely move the
SD card from the computer to the target camera and test **C0009**:
listing/thumbnail, full playback, audio, and seeking. Retain C0008 as the
comparison. Record any exact error and the camera model/firmware version.
Do not format the card or use database recovery as part of an uncontrolled
test. After camera access, take a fresh snapshot before making further changes.

The task should remain uncompleted and wait for that user/hardware evidence.
