# Experiment 0016: Status Propagation And Selected Slice-Order Checks

Date: 2026-11-12, Asia/Shanghai.

## Outcome And Scope

C0008 remains the deployed 1080p 60000/1001 nominal-25-Mbps candidate on F:.
The user's Catalyst playback report is recorded, but is NOT camera playback,
strict conformance, or hardware admission evidence. Catalyst is known from the
user's experience to be substantially more tolerant than the camera.

This experiment did not encode, replace, deploy, or delete any card file.
Snapshot schema was inspected before creating `backup/snap_20261112T175224`:
51 metadata files, 101 skipped-media timestamp entries, no errors.

Closing audit against snapshot 172243 is recorded in
`analysis/card-unchanged-0016.json`: no missing/added files, metadata hash
changes, or media size/write-time changes. This does not content-hash all
original media. The C0008 verifier's 22 package/card checks pass, including
the five package-file readback hashes.

New results:

- Original status-copy/reset ordering was isolated in 24 modeled-boundary
  cases across both MBP copies.
- The parser dispatch function's indirect caller and codec-selector tables
  were recovered. This is not an SD/CFexpress distinction.
- A later slice-index checking path can overwrite the output status with
  bit 31 set. The status word is therefore not simply a fatal boolean.
- FFmpeg parsed every video sample of C0008 and the local generic Cat package;
  both pass the explicitly limited progressive slice-order check.
- The test suite has 42 passing tests. Hardware/camera acceptance is unresolved.

## Image And Address Convention

Image: `firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin`.

SHA-256:
`15e75a9732e2f9904ada1c919c631dac0da57e605ce3daa4c6fb2ebe98982b5b`.

The raw-file mapping is address = offset + 0x80000000, not the ELF mapping
used for libmpr. Core B corresponding addresses are core A +0x1ab000.
The physical camera's installed firmware version remains unestablished.

Only the independent `analysis/ghidra/vcd-imola2-ucp` project was used.
Headless follow-up runs are read-only; temporary function recovery is discarded
when each run closes. No shared MCP project or on-disk firmware was patched.

## Status Word And Wrappers

`TraceVcdStatus.java` records recovered direct references in
`analysis/vcd-status-xrefs.json`. Each status word has 70 direct references
in 34 recovered functions:

| Purpose | MBP A |
|---|---|
| Parser status word | 0x807c0368 |
| Getter | 0x8078e974 |
| Reset to zero | 0x8078e980 |
| Bulk NAL wrapper | 0x807920dc |
| Single-NAL wrapper | 0x80792530 |
| NAL parser dispatcher | 0x80792cf4 |
| Diagnostic record construction | 0x80787a24 |
| Diagnostic ring append | 0x80794ebc |

The sole recovered read-only status consumer is the getter. This search does
not establish the absence of indirect or unrecovered consumers.

The bulk wrapper clears the status, sets up input, parses a NAL loop, then
copies the getter result into argument 3, clears the global, and reports the
copied value to diagnostics.

The single-NAL wrapper clears and sets up input, but copies the getter into
argument 2 BEFORE calling the parser. It subsequently logs that earlier
output value. This ordering is visible in the original instructions.
Do not call it a confirmed firmware bug: setup semantics, operating mode,
and subsequent uses still matter.

In particular, "output zero" from the isolation experiment is conditional on
the setup stubs not generating status. It does not establish that every real
single-NAL invocation returns zero.

## Isolation Experiment

`tools/emulate_vcd_status_flow.py` uses Unicorn MIPS32 24KF and requires the
exact firmware hash. Only a private guest image is changed at seven dependency
entry points per core. The report contains original and replacement bytes for
all fourteen stub locations.

Modeled dependencies include input/setup/drain, parser completion, and the
diagnostic sink. Parser completion injects a chosen mask and a stop byte;
it does not consume real AVC syntax. No Sony device or bit-reader peripheral
is emulated.

Original wrapper/getter/reset instructions remain unchanged. Tests compare
their guest bytes against the original file, and rehash that file.

Six injected masks (0, 4, 0x20, 0x8000, 0x100000, 0xffffffff), two isolated
variants, and two cores give 24 cases:

| Variant | Copied output | Global afterward | Diagnostic argument |
|---|---|---|---|
| Single wrapper | 0 | Injected mask | 0 |
| Seeded bulk epilogue | Injected mask | 0 | Injected mask |

The second variant starts at 0x80792194. Its S0/S5/S7 and saved return-address
stack preconditions are seeded explicitly. It does NOT execute the complete
bulk wrapper or prove that a real parser reaches this state.

Attempting the complete bulk wrapper still produces guest interrupt 20 after
0x80792194 in this harness. That failure was reproduced, not resolved or
converted into a pass. It is not evidence of camera rejection.
Hook callback lists can contain duplicates; they are not instruction counts.

Evidence: `analysis/vcd-status-flow.json`.

## Indirect Dispatch And Completion

A scan of aligned raw words found a pointer to 0x80798344 at 0x807b6f74.
It did not find a direct JAL to that function. Following table references
located the caller at 0x807a6764.

`RecoverVcdDispatch.java` checks original prologue/call words before temporary
function recovery. `TraceVcdDispatch.java` exports table words and recovered
references for both cores to `analysis/vcd-dispatch-table.json`.
Its scanned window is not itself a proof of table boundaries.

The caller extracts bits 5..7 of the input descriptor, passes them to
0x807873f0, then performs two indirect calls:

| Table | Selector result 0 |
|---|---|
| 0x807b6f74 | Parser dispatch 0x80798344 |
| 0x807b6f88 | Follow-up 0x8079861c |

Recovered selector outcomes include input 0 -> index 0, inputs 1/6 -> index 1,
and input 4 -> index 4. Other cases include diagnostics/assertion behavior.
Do not assign unverified codec names to every selector value or reinterpret
these as card types.

The parser dispatch writes output +4 (accumulated status) and +8 (NAL mask).
Its bit-3-set input mode combines single-NAL calls; the other mode calls the
bulk wrapper. A later getter value in the first mode is not itself included
in the final accumulated status in the recovered code.

The caller 0x807a6764 also emits diagnostic records, finalizes an interface,
and posts completion via 0x8079c854. The latter's recovered implementation
has queue storage, waiter and ring-pointer behavior. It is not the video
acceptance decision by itself. The ultimate receiver/status interpretation
has not been recovered.

## Follow-Up Slice Checks

For the applicable bit-3-clear input mode, 0x8079861c calls 0x8079895c.
That routine is conditional on the NAL mask containing 0x22 (types 1/5).
Its recovered paths include:

- A nonzero first parsed slice index causes output status +4 to be set to
  0x80000000.
- It scans further VCL indices and checks ordering. Some problems set separate
  flags; another path ORs 0x80000000 into output status +4.
- It compares further indices with a picture-size result from 0x807914c0.
- It records a bounded slice listing; that bound is not proof that every
  larger slice count is rejected by the camera.

The initial slice parser 0x80790564 stores the first unsigned Exp-Golomb
slice field at state +4. The later index reader 0x80798bd8 also invokes the
unsigned Exp-Golomb interface wrapper. The identification as first_mb_in_slice
follows these syntax positions and uses.

The picture-size function multiplies two accessor results, with conditional
halving. Accessors 0x8079220c/0x80792230/0x80792614 still contain the unsupported
table-index operation. Their raw tails show packed loads, shifts and masks,
but their complete arithmetic is NOT emulated or proved here.

Accordingly, the new checker is explicitly a SELECTED INFERRED PROGRESSIVE
check, using the independent SPS dimensions reported by FFmpeg. It does not
claim to reproduce every firmware branch or prove slice macroblock coverage.

## All-Sample Candidate Check

`tools/check_avc_slice_order.py` uses FFmpeg's `trace_headers` parser, rather
than implementing an AVC decoder. It preserves per-packet boundaries and
compares the number of parsed packets against the MP4 sample table.
It refuses to pass empty/partial traces, ambiguous dimensions, interlaced
syntax, or multiple slice groups.

Supported-case checks: at least one VCL slice per sample, first start zero,
strictly increasing starts, and all starts within the coded picture.
These checks alone do not prove macroblock coverage, HRD consistency, complete
AVC conformance, or hardware compatibility.

Both files have 1534 samples. Every sample has four starts:
`[0, 2040, 4080, 6120]`, within the independently parsed 120 x 68 = 8160
coded macroblock picture.

| File | Evidence |
|---|---|
| Local deployed C0008 package | `analysis/slice-order-c0008.json` and `.log` |
| Local C9999 generic Cat package, not deployed | `analysis/slice-order-generic-cat.json` and `.log` |

C0008 SHA-256 remains
`27ebf88812469b9d5156e32acbfdd189b234ff2712f358d463447792984716b2`.

## Reproduce

```powershell
& 'E:/anaconda3/envs/test311/python.exe' tools/emulate_vcd_status_flow.py --output analysis/vcd-status-flow.json
& 'E:/anaconda3/envs/test311/python.exe' tools/check_avc_slice_order.py output/cat-25m-coherent/C0008.MP4 --output analysis/slice-order-c0008.json
& 'E:/anaconda3/envs/test311/python.exe' tools/check_avc_slice_order.py output/cat-generic-01/C9999.MP4 --output analysis/slice-order-generic-cat.json
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests -v
```

Five status-flow tests and five slice-order tests were added to the previous
32, giving 42 passing tests. They preserve the restricted scope above.
`git diff --check` reports pre-existing trailing whitespace in the user's
`AGENTS.md` change; that unrelated file was left untouched.

## Remaining Gate

Physical C0008 camera playback is still NOT TESTED. The next external evidence
needed is whether the camera lists it, opens it, plays through it, seeks in it,
and plays its audio, including any exact error message.

Further local RE targets are the result's actual receiver, hardware-side
conditions and remaining unsupported instructions. Do not change the deployed
candidate merely to make these partial checks appear more comprehensive.
