# Experiment 0023: Listed But Cannot Display

Investigation crossed midnight: 2026-11-12 to 2026-11-13, Asia/Shanghai.

Follow-up: the user confirms the playback body is **7M4**, and asks not
to prioritize compatibility differences between bodies. That identity is
now established. Installed firmware remains unknown, but is not a reason
to stop this analysis or divert its main line to between-body differences.

## Physical Result And Evidence Preservation

Latest user report: C6507, C6508, C6509 and C6510 are all listed;
their thumbnails are normal; none plays. The camera displays the Chinese
message meaning "Cannot display".

C6507/C6508 were previously reported not listed. The user explicitly
cannot tell whether they were missed earlier or became visible later.
Consequently, this is not proof that experiment 0022 changed visibility.
C6509/C6510's first physical test establishes listing, not playback.
Neither full nor observed-minimal catalog representation has yielded a
successful playback result for these four samples.

Latest observation record:
`analysis/camera_observations_20261112_233331.json`.
The earlier observation JSON is deliberately preserved unchanged because
deployed transaction evidence hashes it. New CLI analyses default to the
new record. Historical reports are not silently rewritten as new evidence.
All four package camera-result files record the latest physical failure.

Return snapshot: `backup/snap_20261112T233331`, 64 metadata / 127 media
inventory entries, zero errors. Comparison with pre-camera snapshot
232817: no metadata hash/list changes, media size/write-time changes,
database-record changes, or header-word changes.
Evidence: `analysis/snapshot-232817-233331-camera-return.json`.

All four selected card media hashes still match their deployed manifests:

| Clip | SHA-256 |
|---|---|
| C6507 | `87e49bcb2d8f79536413dcc22498c780587d550cbd7fc98e23e545812afa3764` |
| C6508 | `98ecfd98ea21dfa8c53f76452cf01aa2c8a2b2f84b6b9a28df72190127899a01` |
| C6509 | `abab47d3650607fcb185b57b1e1b1cca313b8b4d4f38f4161ac0b1c0be48b781` |
| C6510 | `18a2bc5e6a0c5839579304711b9177692494bff501dafecbe1eaf69b89a3890d` |

No card file was written or deleted during this investigation.
Local read-only media references were copied for offline analysis.
This preservation check is not a full-media-card hash or raw-sector image.
Closing snapshot: `backup/snap_20261113T000057`, again 64 metadata /
127 media inventory entries and zero errors.
`analysis/card-unchanged-0023.json` confirms no added/missing files,
changed metadata hashes, or old-media size/write-time changes relative
to snapshot 233331.

## New Original MP4 Reader Execution

`tools/emulate_xavc_reader.py` extends the existing bounded AArch64 model
to the original read-side libXavcMp4 code embedded in `libmpr.so`.

Firmware SHA-256:
`1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`.
All addresses below are ELF VMAs; Ghidra exports add `0x100000`.

| Entry | Narrow role |
|---|---|
| 0x22a730 | Original buffered-file object constructor |
| 0x222994 | Original libXavcMp4 object constructor |
| 0x22a774 | Original buffer setup |
| 0x22af44 | Original read-open wrapper |
| 0x22a380 | Original MP4 open/track-discovery path, mode 1 |
| 0x228fa8 | Original movie-property query used by playback open |
| 0x227714 | Original seek/start-position helper |

The host supplies bounded allocation/libc, single-thread lock boundaries,
and a virtual read/seek filesystem mapped to exactly one offline media
copy. Writes, unexpected paths, unknown services, assertions and
instruction-budget exhaustion abort. No firmware instructions run natively
on Windows, and no hardware decoder or device register is modeled.

The actual firmware `libstdc++.so.6.0.22` supplies pure red-black-tree
helper bodies required by the MP4 reader; these are not replaced by
success stubs. Its hash and admitted helper entries are in each report.
Full libstdc++ startup, TLS and unrelated runtime relocations are not modeled.
Original executable sections are checked byte-for-byte after execution.

The diagnostic-message sink at 0x222494 is explicitly modeled: it
captures the original packet and returns success without sending OSAL
messages. Static export shows message allocation, timestamp/copy/send,
not a media parser. Logs are retained, not interpreted as a camera trace.
The neighboring 0x222428 status translator executes original instructions.
It must not be mistaken for a zero-argument error getter because of
incomplete decompiler prototypes.

## Results

Reports: `analysis/xavc-reader-{clip}-0023.json`.

| Local input | Original open | Property query | Selected start-position probe |
|---|---|---|---|
| C0007 historical successful reference | 0 | 0 | 0 |
| C6359 native reference, physical result unknown | 0 | 0 | Not run |
| C6509 native-essence control, physical playback rejected | 0 | 0 | 0 |
| C6510 generated Cat, physical playback rejected | 0 | 0 | 0 |

The C0007 input is a local whole-file copy, not a zero-filled placeholder
or a truncated container. C6509/C6510 are the hash-bound local deployed
packages, not remuxed substitutes.

The selected seek probe uses an explicitly supplied tuple: timestamp
90000 in 90 kHz units, mode 0, direction 0, zero remaining flags.
These are not observed parameters from the failing camera. Success
is only for this modeled call, not arbitrary seek/playback modes.

Original C6509/C6510 property outputs both contain profile `0x0164002a`,
nominal bitrate 25 at property offset 0x2c, and the expected 90 / 1534
frames at offset 0x30. This verifies real parsing of the supplied media,
not simply calling a constant-return helper.

The separately recovered `_open_file`, VMA 0x1166d8, calls original MP4
open and property query, checks an audio-layout predicate, then invokes
the seek helper and additional metadata/thread work. The actual predicate
is evaluated literally against the returned property bytes by `audio_gate`.
C6509/C6510 satisfy it. This predicate evaluation is host code, not an
execution of the whole `_open_file` function or the physical failure path.

Negative controls in `tools/tests/test_xavc_reader_emulation.py`:

- A truncated/zero-filled movie is rejected before the property query.
- Renaming the actual moov box to free produces rejection before the query.
- Original executable bytes remain unchanged after these controls.
- Unsupported audio codec/rate/layout fields fail the literal predicate.

These controls establish rejection behavior for the tested corruptions,
not complete parser conformance or complete production-environment fidelity.

## What This Does Not Establish

The camera's exact failing stage and root cause remain unknown. Passing
MP4 open/query/one seek on M4 6.02 code does not clear the complete reader,
UI/platform admission, asynchronous read/table submission, metadata
processing, hardware decode, or the unspecified playback body/firmware.
Normal thumbnails do not establish any of those paths.

C6507/C6509 retain native coded samples, but their original C6503 source
has not been confirmed playable on the tested body. They cannot yet be
used to eliminate native format compatibility or qualify as a playable
positive control. The C0007 historical success must also be distinguished
from a fresh same-body playback observation.

The playback body has since been confirmed as 7M4. Continue tracing the
post-query read/table/error callback paths on that basis, without
prioritizing between-body compatibility differences. The original
C6500-C6506 playback observations would still help qualify native controls,
but their absence does not block further offline work. Do not infer a root cause
from nominal bitrate, one metadata field or one successful helper call.

## Verification

Full unit suite: **123 tests passed**, including the new reader controls.
Existing 120 tests continue to pass. No physical playback succeeded.
The three focused reader tests passed again after adding the explicit
start-position probe assertion. Scoped whitespace checking passed.
The overall target remains unachieved.
