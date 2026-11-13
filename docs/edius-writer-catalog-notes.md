# EDIUS 11 Writer And Catalog Investigation

Date: 2026-11-12, Asia/Shanghai.

## Scope And Immediate Result

**Runtime follow-up:** a valid read-only loaded-module capture now exists.
See "Runtime Capture Follow-Up" below for hashes, addresses, verified instruction
anchors, and remaining limits. No complete XAVC-S file-commit sequence is claimed.

The initial bounded, read-only EDIUS investigation was performed alongside the main
C6507 native-control / C6508 Cat-candidate preparation. It did not open or modify
F:, change shared preparation scripts, launch EDIUS/GUI exports, or access shared
Ghidra projects. All generated analysis is under `analysis/edius-catalog/`.

**Do not treat an EDIUS XAVC-S directory export as a proven Sony SD-camera
registration procedure.** The installed MPEG plug-in has strong, specific
XAVC-S directory/catalog implementation indicators, but its protected code has
not been recovered sufficiently to prove the executed file creation and commit
sequence. No write to Sony `DATABASE.BIN` has been established. Absence of that
filename in the scanned strings does not establish absence of such code.

For the pending physical test, preserve the native control and use the main
task's camera-derived catalog procedure consistently for both clips. This
investigation supplies no justified replacement database format or additional
catalog mutation to apply to C6507/C6508.

## Binary Identity

Installed root: `C:\Program Files\Grass Valley\EDIUS 11`.
All following addresses are preferred-image VAs, **not live-process addresses**.
For all three modules, preferred image base is `0x180000000`; RVA = VA - base.

| Module | Bytes | SHA-256 |
| --- | ---: | --- |
| `PlugIn\CtsMpegPlugIn.tpi` | 12,541,416 | `8c39ea4f83e272a083f7cdc90b3bfe9d4e9ae02a49158091a14914ba1b508d81` |
| `PlugIn\CtsMxfPlugIn.tpi` | 8,277,992 | `218dc695afbcb77c893f97995f66bf03ff0330ece02cd45fbb33082dd1475a1a` |
| `cmxfapi.dll` | 1,301,480 | `80b68140daad9dedad3ffa3f8a6cc7854ed17aaf0f9dab090976c500272b60f4` |

`inventory.json` records hashes for 189 installed PE modules. `survey.json`
contains section maps, complete normal/delay imports and exports, and targeted
ASCII/UTF-16LE strings for 30 selected modules. The installation's contents,
rather than generic product documentation, are the evidence for this report.

## XAVC-S MP4 Is Separate From XAVC MXF

### MPEG Plug-In: Specific XAVC-S Export Indicators

High confidence in module identification, not yet in executed catalog behavior:

| VA / RVA | Observed Evidence |
| --- | --- |
| `0x180711520` / `0x711520` | UTF-16 `GrassValley K.K. Exporter Plug-In XAVCS` |
| `0x18094aba0` / `0x94aba0` | RTTI `CExportXAVCS` |
| `0x18094a610` / `0x94a610` | RTTI shared-pointer specialization for `CXAVCSParam` |
| `0x18070fea0` / `0x70fea0` | `CDlgXAVCSDestination` |
| `0x1807105f0` / `0x7105f0` | `CDlgXAVCSExtension` |
| `0x180711cf8` / `0x711cf8` | `MP4 Files (*.MP4)\|*.MP4\|\|` |
| `0x1807126e0` / `0x7126e0` | `C%04d.MP4` numbering template |
| `0x180710000` / `0x710000` | `M4ROOT\MEDIAPRO.XML` |
| `0x180710028` / `0x710028` | `PRIVATE\M4ROOT\MEDIAPRO.XML` |
| `0x180710080` / `0x710080` | `M4ROOT\CLIP\` |
| `0x1807100a0` / `0x7100a0` | `PRIVATE\M4ROOT\CLIP\` |
| `0x180712748` / `0x712748` | `XAVC-M4@1.10.00` |
| `0x180712778` / `0x712778` | `AffordableMemoryCard` |
| `0x1807127a8` / `0x7127a8` | `.$$$` adjacent to exporter-specific path data |
| `0x18094ab30` / `0x94ab30` | RTTI `CPDMediaProfileUpdater` |
| `0x18094afb0` / `0x94afb0` | RTTI `CXdcamExMp4ClipWriter` |

These are substantially more specific than a generic XML filename. Nevertheless,
adjacency/RTTI alone does not prove that a given helper is called by XAVC-S
export or that an existing camera catalog is updated rather than a new export
directory initialized. In particular `.$$$` is **not yet a proven temporary-file
transaction or atomic rename**.

The module exports `Startup_Exporter` at RVA `0x21d710`, `Startup_Importer` at
`0x21ee60`, and `DllGetClassObject` at `0x21d0a0`, alongside shutdown/startup
helpers. Both import and export code coexist here.

### MXF Plug-In And cmxfapi: Do Not Substitute For MP4 Cataloging

`CtsMxfPlugIn.tpi` contains distinct `MXF XAVC Exporter`, `GXF XAVC Exporter`,
`XDCAM XAVC Exporter`, and `XAVC-XD@1.10.00` strings, plus MXF-specific
Intra/Long-GOP settings. It also contains `XAVCS SourceMedia PlugIn`
at VA `0x180585770`, with M4ROOT/XDROOT/PXROOT discovery paths nearby.

Therefore the presence of `\PRIVATE\M4ROOT\MEDIAPRO.XML` at `0x180585940`
in this module is not proof that its MXF exporter authors an ILCE SD catalog.
It may belong to the source-media/browser path; no concrete export call to that
path was recovered in this pass.

`cmxfapi.dll` exposes 18 named `CMXF_*` entry points, including
`CreateFile/Ex`, `CreateInfoFile`, `WriteFile`, `CloseFile`,
`ExportBegin`, `ExportUnit/2`, `ExportEnd/Ex`, and `ExportCancel`.
`CtsMxfPlugIn.tpi` contains `CMXF_WriteFile` at `0x18056be58`;
it does not list cmxfapi as a normal or delay import. Runtime symbol lookup is
plausible, but the protected caller was not traced, so this is not a proven
dynamic-binding call chain.

## Concrete Native Code Traces: cmxfapi Only

Independent headless Ghidra project:
`analysis/edius-catalog/ghidra/edius-cmxf-isolated-v2`.

High confidence in these decompiled native-code relationships:

1. `CMXF_ExportEnd`, RVA `0x12710`, calls `0x1e1f0` at VA
   `0x180012767`, passing the export object, `0`, and null.
2. `CMXF_ExportEndEx`, RVA `0x127d0`, calls the same helper at
   `0x180012834`, forwarding its second argument.
3. `0x1e1f0` checks object field `+0x2dc`, calls `0x204b0` at
   `0x18001e207` if active, then clears that field.
4. `0x204b0` walks the additional linked structures when not cancelling,
   dispatching on tags 3 through 11, calls `0x2f650`, and performs ordered
   virtual calls on objects in an internal vector and an optional additional
   object. This confirms a real finalization/extension-processing stage.
   The second `ExportEndEx` argument is **not established as an output status
   pointer**; its pointee is traversed as tagged linked input structures here.
5. `CMXF_CloseFile`, RVA `0x11ff0`, calls `0x65b10` at VA
   `0x18001204c`. That function can wait on a worker handle, close that handle,
   perform conditional index/finalization work, then return an internal status.
   This API uses `CMxfIndexMaker` RTTI, unlike the `CMxfExport` end API.
6. `CMXF_WriteFile`, RVA `0x12d60`, calls `0x767c0` at
   `0x180012dbf`. The latter copies/queues buffers and uses internal writer
   dispatch; it is not a Sony SD database record writer established by this trace.

Separate, concrete file-I/O sink evidence in the same DLL:

- `0x93c70` -> `0x9f5a0` at `0x180093c99`.
- `0x9f5a0` calls `FlushFileBuffers` for a direct filesystem handle, or uses a
  virtual backend callback for an alternate registered backend.
- `0x9f270` similarly reaches `CreateFileW`, with an alternate backend branch.
- `0xa04b0` reaches `WriteFile`, again through the file abstraction.

The recovered finalizer uses indirect dispatch; this pass **does not join its
specific virtual writer instance to the flush sink**. Consequently these sink
calls establish I/O capability, not an MP4/XML/database durability ordering.

Decompiler output and exact caller/callee refs are retained in:

- `decompile-edius-cmxf-isolated-v2/`
- `decompile-edius-cmxf-isolated-v2-finalizer/`
- `decompile-edius-cmxf-isolated-v2-sinkchain/`

## Sidecars, Thumbnail, Options, And Catalog Gaps

The MPEG module contains:

- `./CLIP/%sM01.XML` at VA `0x1806fa448`;
  `./Clip/%sM01.XML` at `0x1806fa470`.
- `Clip\%sM%02d.XML` at `0x180702ab0`;
  `CLIP\%sM01.XML` at `0x180719748`.
- `NonRealTimeMeta` at `0x1806fa8b0`, multiple Sony NRT namespace versions,
  and `Thumbnail` / `ThumbnailFormat` schema tokens.
- An initial `MediaProfile` XML document at `0x180727b80`,
  Material/UMID XPath expressions at `0x180727ca0`, and
  `MEDIAPRO.BUP` at `0x180738cd8`.

These are retained as **shared-module data, not recovered XAVC-S writer calls**.
The thumbnail-related module data also includes unrelated P2/JPEG code.
No concrete Sony `T01.JPG` authoring call, thumbnail dimensions/encoding,
per-clip NRT finalization sequence, or BUP replacement protocol was established.

Destination, extension, and parameter classes establish configuration surfaces.
Exact option values, profile/bitrate mappings, and how they affect on-card
registration have not been traced; no 25M preset recommendation follows.

No targeted ASCII or ASCII-subset UTF-16LE `DATABASE.BIN` occurrence was found
in the 189 scanned PE modules. This is a bounded negative string-search result,
not proof of non-support: paths can be synthesized, encoded, delegated, or
represented without a literal filename.

## Protected-Code Limitation And Offline Probe

The two large plug-ins cannot be treated as ordinary on-disk native code:

- MPEG entry RVA `0x58fc20` jumps to added code at `0xa21c32`.
- MXF entry RVA `0x489a8c` jumps to added code at `0x7882a6`.
- Both have an additional executable `.text` section. Many original code
  ranges decode as implausible instruction streams. This combination is
  evidence of a transformed/protected code image, not a basis for identifying
  a particular protector or claiming maliciousness.
- A genuine MPEG source-filename ref at `0x18063b1bf` selects a thin function
  at `0x18063b1b0`; its called range `0x180215df0` is not a trustworthy
  recovered implementation.

Initial Ghidra analysis completed, but only this thin source-reference function
was selected by the targeted strings. Capstone direct-xref traces from protected
regions may contain accidental decodes; **do not promote their call lists to
semantic writer evidence**.

An isolated Unicorn probe did not execute Windows APIs or the installed module
natively. Its strict mode stopped before `GetSystemInfo`. A second bounded
mode modeled only GetSystemInfo, VirtualQuery, VirtualProtect and
FlushInstructionCache in emulator memory. It stopped on its 30-second limit
after 36,936,041 instructions; only eight original executable-section bytes had
changed. It did **not** recover the XAVC-S writer.

`CtsMpegPlugIn.tpi.probe-image.dll` is an incomplete **analysis-only** image with
synthetic emulator IAT pointers. Do not load, distribute as an executable
replacement, or use it as an unprotected writer. Its identity and limitations
are in `CtsMpegPlugIn.tpi.memory-stubs.loader-probe.json`.

The interrupted first cmxfapi import was not reused; its project/log are
incomplete. All successful cmxfapi evidence comes from the independent `-v2`
project. No annotations or mutations were made in a shared Ghidra program.

## Actionable Next Evidence

1. Keep C6507's native essence control independent of the Cat encoder. If both
   added clips are unlisted, catalog/discovery remains the first issue.
2. Do not copy EDIUS's `XAVC-M4@1.10.00` or an inferred `.$$$` transaction into
   the current ILCE catalog builder based on string adjacency alone.
3. If a future controlled EDIUS export is authorized, capture filesystem calls
   and read-only loaded module images while exporting to a disposable workspace
   directory, not the card. This can establish whether the writer creates new
   M4ROOT versus updates an existing tree, and whether Sony DATABASE is opened.
4. Specifically log MP4 close, NRT XML write/close, manifest temp/rename/backup,
   thumbnail writes, and flush ordering; record the selected destination options.
   Compare the output with the camera-native before/after catalog snapshots.
5. For further static work, obtain an authorized loaded-code image or a usable
   untransformed build before spending more time decompiling these protected
   plug-ins. MXF finalization alone cannot answer the SD MP4 registration question.

## Files Created

Only this report and `analysis/edius-catalog/` were created/changed by this
investigation. The initial artifact set included Python scripts, a Java Ghidra
script, PE inventory/survey/focused/xref JSON, loader-probe artifacts, independent
Ghidra projects, logs, and targeted decompilations. No main `tools/` file was
edited.

## Runtime Capture Follow-Up

### Scope And Acquisition

On 2026-11-12 no EDIUS process existed at the initial check. The installed
`EDIUS.exe` was started through CUA with the user's authorization. Window
inventory reported **Start Project**; no prior project was opened, no media
was selected, and no export was initiated. Screenshot/accessibility acquisition
failed; a later physical Escape stopped Computer Use. No further GUI action
was performed. EDIUS PID 47056 still existed at the later process-only check.

`capture_loaded_mpeg.py` opened only that EDIUS process with access mask
`0x410 = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ`. It used module enumeration,
ReadProcessMemory and VirtualQueryEx, not a debugger attachment. There was no
WriteProcessMemory, injection, remote thread, suspension, breakpoint, or process
memory protection change. Only the installed MPEG plug-in image was captured,
not arbitrary heap memory. No analysis command or GUI action addressed F: or
loaded either analysis derivative. Application background filesystem I/O was not
instrumented, so no global filesystem-I/O audit is claimed.

Capture directory:
`analysis/edius-catalog/live-mpeg-47056-20261112T134903Z/`.

| Property | Recorded Value |
| --- | --- |
| Capture time, Asia/Shanghai | 2026-11-12 21:49:03.920 to 21:49:07.050 |
| PID | 47056 |
| Loaded module base | `0x7ffc5b300000` |
| Preferred analysis base | `0x180000000` |
| SizeOfImage | 12,577,792 bytes |
| Failed page reads | 0 |
| Raw memory SHA-256 | `f9516794f40a502796ae5b2129d2f77955bc01334987c10f4145910f56300abd` |
| Normalized analysis PE SHA-256 | `b610fd1440b389324c0513219b1930743947d977fe1d4342f489ec95ccbb83f4` |
| Installed file unchanged after capture | true, original SHA-256 retained |

The first `.text` section differs from the installed disk image in **4,839,045
bytes** after relocation normalization. A second read of each executable section
matched the first live read exactly. For example, RVA `0x215df0`, previously an
implausible on-disk instruction stream, now contains a normal stack adjustment,
indirect call, stack restore, and return. This verifies recovery of useful native
code at the inspected locations, **not recovery of every protected function**.

The raw memory image preserves the captured bytes and actual IAT pointers.
The separate `loaded-normalized-pe.bin` is for static analysis only: 28,360
DIR64 relocations were reversed, original IAT entries restored, and the preferred
image base restored. Runtime globals remain possible. Neither derivative is
an executable replacement and neither was loaded.

### Verified RTTI And Code Anchors

All following values are **PE RVAs**, not Sony firmware ELF addresses.
Normalized VA = `0x180000000 + RVA`.
Captured live VA = `0x7ffc5b300000 + RVA`.

| Evidence | PE RVA |
| --- | --- |
| `CExportXAVCS` TypeDescriptor | `0x94ab90` |
| `CExportXAVCS` primary vtable | `0x711800` |
| One function installing its vtables | `0x234480` |
| Its primary vtable reference instruction | `0x234559` |
| `CPDMediaProfileUpdater` TypeDescriptor | `0x94ab20` |
| Updater vtable | `0x711b00` |
| Updater vtable entries, slots 0 through 4 | `0x2356a0`, `0x1c3070`, `0x1c1ab0`, `0x1c4360`, `0x1b86e0` |
| `CPDMediaProfile` base vtable | `0x711ad0` |

These identifications use MSVC Complete Object Locator records whose signature,
TypeDescriptor RVA and self-RVA agree, followed by actual vtable pointers and
code references. They are not based solely on nearby strings.

The following **partial static chain in runtime-captured code** is verified:

1. Function RVA `0x23bf00` calls RVA `0x237b80` at instruction `0x23bf43`,
   after checking an object field at `+0x158`. The returned EAX is checked
   for a negative result.
2. Within `0x237b80`, instruction `0x23853a` loads the base MediaProfile
   vtable; `0x238541` stores it at `[rdi]`.
3. Instruction `0x238556` loads the verified Updater vtable; `0x23855d`
   stores it at `[rdi]`, followed by member initialization. This is concrete
   updater-object setup inside this implementation, not inferred XML writing.
4. On one conditional branch, instructions `0x238606` and `0x23860b`
   prepare RDX and RCX, and `0x238610` calls helper `0x1b86f0`; EAX is
   checked immediately afterward. The helper's file-I/O semantics are not
   established by this evidence packet.
5. Updater vtable slot 3 (`0x1c4360`) calls `0x1bf1a0` at `0x1c43a1`,
   passing R8D = 1 after a reference-management call. It is not yet justified
   to name either function "save", "flush", or "commit".

The complete CExportXAVCS virtual entry-to-this-chain connection and subsequent
filesystem sinks have **not** been established. In particular, these facts do not
show MP4 close, NRT save, MEDIAPRO replacement, thumbnail creation, or SIDB flush,
and do not establish that the chain executed while the process was captured.
No dynamic export/file-operation trace was collected.

### Reproducible Artifacts And Current Obstacle

- `capture.json`: access rights, actual base, regions/protections, per-section
  comparisons, complete-read checks, hashes, and normalization provenance.
- `CtsMpegPlugIn.loaded-memory.bin`: raw module image.
- `CtsMpegPlugIn.loaded-normalized-pe.bin`: non-executable static-analysis derivative.
- `loaded-rtti.json`: recovered class descriptors, secondary vtables and method VAs.
- `loaded-callgraph.json`: direct branches/calls and previously known string,
  import and vtable references in the recovered bytes. This is a static graph.
- `runtime-anchor-disassembly.txt`: inspected instruction ranges including bytes.
- `runtime-evidence-summary.json`: hash-checked evidence packet and explicit non-claims.

Reproduce the packet without opening a process or scanning strings:

```powershell
& 'E:\anaconda3\envs\test311\python.exe' analysis/edius-catalog/runtime_evidence_packet.py analysis/edius-catalog/live-mpeg-47056-20261112T134903Z
```

There was **no process-read/attachment obstacle**. The limiting step was offline
analysis: independent project `edius-live-mpeg-47056` reached its 180-second
automatic-analysis timeout, then entered the targeted script. After Computer Use
was stopped, that headless run was terminated. Its decompile output directory
contains **no function files**, and its project is not a completed analysis.
The earlier report must not be read as having produced runtime-backed Ghidra
decompilations. The code anchors above were read with Capstone from the captured
image and are independently reproducible from the packet.

For the parent 0021 report: this closes the "can loaded EDIUS writer code be
obtained?" question positively and supplies concrete continuation addresses.
It does **not** independently verify, contradict, or replace the firmware-side
recording-end sequence supplied by the parent. Do not equate EDIUS MediaProfile
updater setup with the camera's `UpdateMovieContentsForSidb` or conditional flush.

New scripts for the runtime follow-up are `capture_loaded_mpeg.py`,
`trace_loaded_writer.py`, and `runtime_evidence_packet.py`. Changes remain confined
to `analysis/edius-catalog/` and this note; no main tools or firmware project were
modified.

## Runtime Task Closure

This bounded EDIUS subtask is closed. The final packet is
`analysis/edius-catalog/live-mpeg-47056-20261112T134903Z/runtime-evidence-final.json`.
It seals the raw capture, normalized analysis image, RTTI/call graph, byte-level
anchor disassembly, scripts and this note with SHA-256 values, and records the
final process audit. It does not expand the behavioral claims above.

Verified success: a complete read-only module capture with stable executable
sections, valid class/vtable relationships, and the partial direct-call and
object-setup anchors listed above.

Concrete limit: the complete CExportXAVCS virtual-entry connection and updater
helper-to-filesystem-write semantics remain unverified. The interrupted headless
run produced no decompiled functions; it must not be cited as a successful
runtime decompilation. No EDIUS export or camera-catalog commit was executed.

Temporary capture scripts have exited and closed their process handles.
The independent headless analysis process was already terminated. Final process
inspection found no remaining capture/headless Python or Java helper for this
subtask. The application tree is deliberately retained to preserve any user
state: EDIUS PID **47056**, EHRenderEngine PID **44560**, and EHRenderWorker PIDs
**6316** and **40220**. The final packet contains the process creation dates and
command lines. No existing EDIUS application was killed.

Runtime-phase changes are confined to these new analysis scripts:
`capture_loaded_mpeg.py`, `trace_loaded_writer.py`, `runtime_evidence_packet.py`,
`finalize_runtime_evidence.py`; the `live-mpeg-47056-20261112T134903Z/` capture
directory and evidence artifacts; the independent, incomplete
`edius-live-mpeg-47056` headless project/log/output directory; and this note.
No shared preparation tool, firmware project, installed application, or card
file was modified. No further EDIUS investigation is left running.
