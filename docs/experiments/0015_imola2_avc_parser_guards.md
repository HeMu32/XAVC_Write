# Experiment 0015: imola2 AVC Parser And Measured Scalar Guards

Date: 2026-11-12, Asia/Shanghai.

## Status

**C0008 is unchanged on F:. Physical camera playback is still NOT tested.**

Subsequent user report, 2026-11-12: C0008 plays in Catalyst. The user explicitly
warns that Catalyst's compatibility/error tolerance far exceeds the camera's.
Record this only as desktop playback evidence, not as a firmware admission
test, proof of strict bitstream conformance, or progress through the physical
camera playback gate. Repeating that desktop test is not the next validation.

This continuation did not encode, deploy, replace or delete any card file.
Before analysis, inspected snapshot 161740 and created
`backup/snap_20261112T164652`: 51 metadata files, 101 media timestamp entries,
no errors.

Final audit: `analysis/card-unchanged-0015.json` reports no added/missing files,
no metadata hash changes, and no media size/write-time changes. This is a coarse
audit for original media, not a content-hash check of every original clip.
All 22 C0008 package/card checks pass again, including all five readback hashes;
the video remains SHA-256
`27ebf88812469b9d5156e32acbfdd189b234ff2712f358d463447792984716b2`.

The previous turn made concrete progress (new imola2 analysis, driver tests,
and primary variant evidence). This turn follows the actual parser, not more
repetition of those checks. The goal is not complete: no result below is a
substitute for physical camera playback.

## Primary Image

Input: `firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin`.

- Build string: `SW_VER_46_21_02_0______________`.
- SHA-256: `15e75a9732e2f9904ada1c919c631dac0da57e605ce3daa4c6fb2ebe98982b5b`.
- Source/variant evidence remains in experiment 0014 and
  `analysis/vcd-survey-multicore.json`.
- This is M4 6.02 firmware material, not proof of the physical camera's currently
  installed firmware version.

## Multiple GP Contexts

The raw image contains additional MIPS startup sequences, not just SPU startup.
For each row, actual instructions load GP/SP, clear a BSS range and transfer
to the listed entry. The raw-offset correspondence is corroborated by those
same instructions and their linked targets.

| Context | Startup address | GP | SP | Main transfer | BSS start |
|---|---|---|---|---|---|
| SPU | 0x80009300 | 0x8024eb58 | 0x8070b100 | 0x8005c34c | 0x80248e08 |
| MBP A | 0x80714300 | 0x807bf0e0 | 0x808b6100 | 0x8079da80 | 0x807c0628 |
| MBP B | 0x808bf300 | 0x8096a0e0 | 0x80a61100 | 0x80948a80 | 0x8096b628 |

Within these contexts, address = `0x80000000 + raw file offset`.
MBP B's corresponding code/data is displaced by 0x1ab000 from MBP A.
Its actual guard behavior was checked independently below, not presumed equal.

`survey_vcd.py` records the GP-load instruction bytes and startup disassembly.
`PrepareVcd.java` now seeds separate GP ranges and entry points in independent
projects. The earlier one-GP interpretation of late code was insufficient.
This does not establish every image region/overlay or the runtime core schedule.

## Analysis-Only Instruction Model

Stock MIPS32 decoding stops at repeated words such as:

| Raw word | Analysis alias | Observed use |
|---|---|---|
| 0x68e60360 | ucp_read7 a2,0x360 | Poll a status bit |
| 0xb0f00360 | ucp_write7 0x360,s0 | Issue an interface command |
| 0x68e40362 | ucp_read7 a0,0x362 | Read a result into a GPR |
| 0xb0e00361 | ucp_write7 0x361,zero | Acknowledge/reset interface state |

`firmware/tools/sony_ucp/sony_ucp32le.slaspec` extends the installed stock MIPS
language only for primary opcode 0x1a/0x2c with rs=7. Reads produce an opaque
P-code user-operation result; writes retain an opaque side effect.
These are analyst-assigned aliases, NOT verified vendor mnemonics.

The extension deliberately does NOT implement device behavior, status values,
timing, a bit-reader peripheral, DMA, caches, pixel decoding, or other unknown
instructions. It must not be described as a Sony ISA specification or an
operational hardware emulator.

`install_ucp_language.py --apply` compiled and registered the separate language
`MIPS:LE:32:sony-ucp-opaque` in the installed Ghidra MIPS language directory.
It did not replace stock MIPS sources or existing projects. Source, definition
and compiled hashes are in `analysis/ucp-language-install.json`.

`ValidateUcp.java` checks the four original instruction words, their decode,
the immediate selector in P-code, and read/write output behavior.
`analysis/ucp-instruction-check.json` passes. That verifies model wiring, not
the hypothesized hardware semantics.

Independent project: `analysis/ghidra/vcd-imola2-ucp`.
Exports: `analysis/decompile-vcd-imola2-ucp/`.
Other unsupported instructions still cause truncation in some functions.
Those failures remain visible; do not treat every export as complete.

## Parser Paths Recovered

All addresses below are raw-image MIPS addresses, **not** the +0x100000
ELF convention used by libmpr/libInfraAvbbc.

| Address | Identification by field/call sequence |
|---|---|
| 0x8079408c | Fixed-width bit-read interface wrapper; waits for ready, sends requested width, returns interface result |
| 0x80794188 | Interface wrapper issuing command 0x3e; used at unsigned Exp-Golomb syntax positions |
| 0x807941d8 | Interface wrapper issuing command 0x3f; used at signed Exp-Golomb syntax positions |
| 0x80792e90 | AVC SPS parsing: profile, constraints, level, IDs, chroma/depth, POC, reference count, dimensions/crop, VUI |
| 0x80793420 | AVC PPS parsing: IDs, entropy/FMO, references, prediction, QP, deblock/constrained/redundant flags, optional extension |
| 0x807936c4 | AVC VUI parsing: aspect/color/timing, NAL/VCL HRD presence, picture structure and restrictions |
| 0x80793c2c | HRD syntax loop and delay-width parsing |
| 0x80790fd0 | NAL/slice orchestration and call order |
| 0x80790564 | Clears 0x24 bytes of slice state, then parses initial slice fields |
| 0x80790634 / 0x80790998 | Further slice-header syntax |
| 0x80790ecc | Conditional deblocking parameter parse |

The identity of SPS/PPS/VUI follows the ordered syntax fields and widths, not
just source-file-name strings. The hardware encoding of the bit-reader commands
is still inferred from these uses, not measured on a device.

## Correcting The Historical Deblocking Claim

The successful C0007-style repair remains an observed historical result.
It does NOT establish a universal requirement that
`deblocking_filter_control_present_flag` must be 1.

The M4 6.02 path recovered here shows:

1. PPS parser 0x80793420 reads the deblocking flag and stores it in bit 0
   of the word at PPS +8, without a force-to-1 guard at that point.
2. Getter 0x807929e8 ends with a load of PPS +8 and `andi ...,1`.
   Its table-index operation is still an unsupported instruction; no exact
   arithmetic semantics are claimed for that operation.
3. Slice-tail parser 0x80790ecc calls that getter. Only a nonzero result causes
   reading disable_deblocking_filter_idc and, when applicable, the two offsets.
4. The 0x80790fd0 path first calls 0x80790564, which invokes the zero helper
   0x807924b8 with length 0x24. This includes the deblock state word at +0x20.
   Thus this path does not merely leave those absent fields uninitialized.

This is evidence against using the old "confirmed necessary" statement as a
general firmware rule. It does not prove all later hardware paths accept all
flag-0 streams, establish the old camera's firmware version, or isolate the
other simultaneous changes made in the historical experiment.
The deployed candidate keeps flag 1; no stream was changed on this new evidence.

Similarly, VUI wrappers 0x8078f254 and 0x8078f25c simply return the NAL/VCL HRD
presence bits. The VUI parser conditionally parses each HRD. These functions
do not enforce presence of both. Necessity elsewhere remains unproven.

## Execute The Original Scalar Helpers

`tools/emulate_vcd_guards.py` executes only selected hardware-free leaf functions
using Unicorn's MIPS32 engine. The script:

- Requires the exact image hash above.
- Maps a private in-memory image and scratch stack; no guest OS, filesystem,
  host API, camera or network is exposed.
- Uses the actual GP and original function addresses for each MBP copy.
- Stops each call after at most 200 instructions and requires return to a sentinel.
- Permits only the expected status-word write; unexpected writes stop the run.
- Does not patch instructions, emulate custom Sony operations, or substitute
  Python implementations of the helpers.

Each copy ran **639 cases across 18 helpers**. Outputs and status words match
between the two copies. `analysis/vcd-guard-emulation.json` preserves all results.
Seven focused new tests assert selected boundary outcomes from the actual
instructions; the full test suite now has **32 passing tests**.

Selected no-correction inputs, based on measured helpers and their parser calls:

| Field | Helper A | Measured no-correction condition |
|---|---|---|
| profile_idc | 0x8078eff4 | 66, 77, 100, 110, 122 among 8-bit inputs |
| chroma_format_idc | 0x8078f0c4 | 1 or 2 |
| seq_parameter_set_id | 0x8078f0a0 | 0..31 |
| pic_parameter_set_id | 0x8078ee7c | 0..255 |
| num_slice_groups_minus1 | 0x8078eea0 | 0 |
| redundant_pic_cnt_present_flag | 0x8078efa8 | 0 |
| default active reference index minus1, L0/L1 | 0x8078eebc / 0x8078eee4 | 0..31 |
| log2_max_frame_num_minus4 | 0x8078f13c | 0..12 |
| pic_order_cnt_type | 0x8078f160 | 0..2 |
| log2_max_pic_order_cnt_lsb_minus4 | 0x8078f184 | 0..12 |
| pic_width_in_mbs_minus1 | 0x8078f1cc | 5..511 |
| chroma_qp_index_offset | 0x8078ef7c | -12..12 |
| second_chroma_qp_index_offset | 0x8078efc8 | -12..12 |

The width range is a scalar parser guard, NOT a promise that the camera
decodes every resulting width, height, rate, profile or level combination.
The level helper 0x8078f04c checks decimal tens <=6 and ones <=3, else substitutes
52 and sets a status bit. This is not a complete normative AVC level validator.

Unsupported values often set bits in the word at 0x807c0368 and substitute a
fallback rather than returning a fatal error. The eventual interpretation of
that word has not been fully traced. Say "corrected/flagged by this helper",
not "universally rejected by the camera".

Both candidate traces (`avc-coherent-all-sei.json` for C0008 and
`avc-generic-cat-all-sei.json` for local C9999) contain all 18 selected fields.
Every one passes its measured helper unchanged with status word zero.
Their trace hashes and coverage are recorded. Missing fields are reported,
and an empty trace cannot yield a passing selected-guard result.

## Reproduce

```powershell
& 'E:/anaconda3/envs/test311/python.exe' tools/install_ucp_language.py --apply
& 'E:/anaconda3/envs/test311/python.exe' tools/emulate_vcd_guards.py --trace analysis/avc-coherent-all-sei.json --trace analysis/avc-generic-cat-all-sei.json --output analysis/vcd-guard-emulation.json
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests -v
```

The first command adds only the separate language. The second and third are
local-only and never write a card. Existing-language source mismatch is refused
by the installer.

Ghidra import and follow-up logs use separate names so subsequent exports do
not overwrite the import evidence. Examples:
`analysis/ghidra-vcd-imola2-ucp-import.log`,
`analysis/ghidra-vcd-imola2-ucp-gates.log`,
`analysis/ghidra-vcd-imola2-ucp-slice-state.log`.

## Still Required

Physical C0008 playback remains the immediate external gate.
Also unresolved: full hardware admission/status propagation, remaining custom
instructions, HRD timing semantics, physical-camera firmware/build matching,
and isolation of the historical repair's simultaneous variables.
No conclusion here is CFexpress-specific or a claim of XAVC certification.
