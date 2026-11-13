# Workspace cleanup 2026-11-13

Scope: local workspace only. The camera card was not accessed or modified.

## Evidence retained

- `output/generic-smoke-05/report.json` records the final six-case generic
  encoder result and per-case media hashes.
- `docs/experiments/0014_generic_encoder_and_decoder_chain.md` and
  `docs/experiments/0017_cbr_hrd_retiming.md` retain the experiment narrative.
- Physically confirmed deploy packages remain under
  `output/profiles-0026-deploy/C6517`, `output/profiles-0026-deploy/C6518`,
  and `output/cat-compact4-C6515`.
- Verification reports, manifests, catalog transactions, camera results,
  snapshots, firmware probes, docs, tools, and source references are retained.

## Removal criteria

Remove only generated diagnostic media/log trees whose result is already
captured by a retained report, or byte-identical copies whose verified source
and verification hashes remain present. Never use a filename alone as proof.

## First removal batch

The historical generic smoke runs `generic-smoke-03` and `generic-smoke-05`
contain regenerable fixtures, encoded media, trace logs, and framemd5 outputs.
The final passing summaries are retained as `report.json`; source code and
documentation remain. These runs were never deployed to the camera.

Applied: 14 items, 1,375,540,849 bytes (about 1.28 GiB). Removed the six
case directories from each run and the two offline MP4s that were byte-identical
to the retained physically-tested deploy packages C6517/C6518.
Machine record: `analysis/workspace-cleanup-20261113.json`.

## Second removal batch

The earlier `generic-smoke-01` and `generic-smoke-02` case directories are also
regenerable. Their `report.json` summaries and all source/documentation remain.
Applied: 11 items, 113,343,213 bytes (about 108 MiB).
Machine record: `analysis/workspace-cleanup-20261113-batch2.json`.

## Deliberately retained

- `output/source-control-C6511/C6511.MP4` is not byte-identical to C0007. Its
  verification and firmware-reader evidence still reference this exact file.
- C6508/C6509/C6510 and C6512/C6513 media are historical physical-result
  evidence ("listed but cannot display") and remain referenced by analysis.
- `output/cat-25m`, `cat-25m-coherent`, `cat-25m-hrd`, and `cat-generic-01`
  remain because reports and analysis JSON bind their exact media hashes.
- Deploy `verification_runs` remain because `verification.json` binds their
  evidence paths and hashes; removing them would make success packages
  non-self-contained.
- All snapshots remain. A full file-set hash comparison shows distinct metadata
  content even where DATABASE.BIN and MEDIAPRO.XML match. The comparison is in
  `analysis/snapshot-cleanup-groups-20261113.json`.
- Ghidra projects remain as useful working evidence alongside decompiled text.
- Firmware, tools, docs, references, and source input remain untouched.

