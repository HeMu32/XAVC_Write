"""Purpose: exercise original Sony MP4 read-side methods on a local media copy.

Usage: python tools/emulate_xavc_reader.py LOCAL.MP4 --snapshot SNAP
    --output REPORT [--seek-probe --sample-batches 1 --decode-table-probe
    --rtmd-probe --max-runtime-seconds 120].
Design: execute identified library/runtime helpers with modeled libc/Fsys and
    compare selected sample indexes, parameter sets, RTMD and decode tables.
Scope: bounded parser/worker preparation, not hardware submission or full movie
    playback. Emulation timeouts are probe failures, not media rejection proof.
"""
import argparse
import hashlib
import json
import mmap
import struct
import time
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import arm64_const as regs

from emulate_mediapro import HEAP, MediaProfileEmulator
from emulate_sidb_readers import ARGUMENTS, EXPECTED

TRACE_ENTRIES = {0x2279c0: "presentation_boundary_scan", 0x1cf204: "sync_sample_search",
                 0x1cf9d0: "sample_decode_timestamp", 0x1cedb8: "sample_info"}


def audio_gate(properties):
    """Literal predicate from libmpr _open_file, ELF VMA 0x1166d8."""
    values = {offset: struct.unpack_from("<I", properties, offset)[0]
              for offset in (0x34, 0x38, 0x3c, 0x40, 0x44)}
    stereo = (values[0x38] <= 1 and values[0x40] == 1 and
              values[0x34] == 0 and values[0x44] & 255 == 1)
    four_mono = (values[0x38] == 1 and values[0x40] == 2 and
                 values[0x34] == 0 and values[0x44] & 255 == 4)
    return {"accepted_by_literal_property_predicate": (stereo or four_mono) and values[0x3c] == 0,
            "source_elf_vma": "0x1166d8",
            "scope": "Host evaluation of recovered predicate, not execution of complete _open_file",
            "raw_property_fields": {hex(k): v for k, v in values.items()}}


class XavcReaderEmulator(MediaProfileEmulator):
    def __init__(self, firmware, expat, snapshot, data, max_seconds=120):
        self.media = data
        self.steps = []
        self.diagnostics = []
        self.runtime_helpers = []
        self.active_step = None
        self.partial_sample_batches = []
        self.trace_counts = {}
        self.deadline = time.monotonic() + max_seconds
        super().__init__(firmware, expat, snapshot)
        runtime = firmware.parent / "libstdc++.so.6.0.22"
        self.runtime_sha256 = hashlib.sha256(runtime.read_bytes()).hexdigest()
        base = 0x61000000
        with runtime.open("rb") as stream:
            elf = ELFFile(stream)
            segments = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
            pages = set()
            for segment in segments:
                pages.update(range((base + segment["p_vaddr"]) & ~4095,
                                   (base + segment["p_vaddr"] + segment["p_memsz"] + 4095) & ~4095,
                                   4096))
            for page in sorted(pages):
                self.uc.mem_map(page, 4096)
            for segment in segments:
                self.uc.mem_write(base + segment["p_vaddr"], segment.data())
            for section in elf.iter_sections():
                if section["sh_flags"] & 4 and section["sh_type"] != "SHT_NOBITS":
                    self.code_sections.append((base + section["sh_addr"], section.data()))
            for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
                if "_Rb_tree" in symbol.name and symbol["st_value"] and symbol["st_size"]:
                    entry = base + symbol["st_value"]
                    self.definitions[symbol.name] = entry
                    self.runtime_helpers.append({"symbol": symbol.name, "entry": hex(entry)})
            # Only selected pure tree helpers are admitted. Other runtime
            # initialization, TLS and dynamic relocations are not modeled.
        self.ranges.extend((address, address + len(raw)) for address, raw in self.code_sections)
        self.reader = self.allocate(0x400)
        self.file_object = self.allocate(0x100)
        self.path = self.allocate(0x100)
        self.settings = self.allocate(0x20)
        self.output = self.allocate(0x200)
        self.uc.mem_write(self.path, b"A:/PRIVATE/M4ROOT/CLIP/TEST.MP4\0")
        self.uc.mem_write(self.settings, struct.pack("<IIQ", 0x58415643, 0, 0xa00000))

    def on_code(self, uc, address, size, user_data):
        if self.instruction_count & 0x3fff == 0 and time.monotonic() > self.deadline:
            raise TimeoutError(f"Reader probe wall-time budget exhausted during {self.active_step}")
        if address in TRACE_ENTRIES:
            name = TRACE_ENTRIES[address]
            args = [hex(uc.reg_read(reg)) for reg in ARGUMENTS[:7]]
            trace = self.trace_counts.setdefault(name, {"calls": 0, "first_args": args})
            trace["calls"] += 1
            trace["last_args"] = args
        if address == 0x222494:
            pointer, count = [uc.reg_read(reg) for reg in ARGUMENTS[:2]]
            if not 0 < count < 0xfe1:
                raise RuntimeError("Unexpected diagnostic packet length")
            self.diagnostics.append(bytes(uc.mem_read(pointer, count)).hex())
            self.finish_stub(0, "read_side_diagnostic_message_sink")
            return
        name = self.plt.get(address) or self.stubs.get(address)
        if name and name not in self.definitions:
            a, b, c, d = [uc.reg_read(reg) for reg in ARGUMENTS[:4]]
            if name == "Fsys_Open":
                label = self.cstring(a).decode("ascii")
                if label != "A:/PRIVATE/M4ROOT/CLIP/TEST.MP4":
                    raise RuntimeError(f"Unexpected media open: {label}")
                self.handles[0x12340000] = {"data": self.media, "position": 0}
                self.write_output(b, struct.pack("<Q", 0x12340000))
                self.io.append({"operation": name, "path": label, "readonly": True})
                self.finish_stub(0, name)
                return
            if name == "Fsys_Tell":
                self.write_output(b, struct.pack("<Q", self.handles[a]["position"]))
                self.finish_stub(0, name)
                return
            if name in {"pthread_mutex_init", "pthread_mutex_destroy",
                        "pthread_mutex_lock", "pthread_mutex_unlock",
                        "pthread_once", "osal_sem_wait", "osal_sem_post"}:
                # pthread_once cannot be replaced with success without its callback.
                if name == "pthread_once":
                    raise RuntimeError("Original pthread_once callback needs explicit execution")
                self.finish_stub(0, name)
                return
            if name in {"abort", "__assert_fail", "__stack_chk_fail"}:
                raise RuntimeError(f"Guest fatal boundary: {name}")
            if name == "printf":
                self.diagnostics.append({"printf_format": self.cstring(a).decode("ascii", "replace")})
                self.finish_stub(0, "readonly_printf_message_sink")
                return
        super().on_code(uc, address, size, user_data)

    def step(self, label, entry, args, status=True):
        self.active_step = {"label": label, "entry_elf_vma": hex(entry)}
        value = self.invoke(entry, args, limit=30000000)
        self.steps.append({"label": label, "entry_elf_vma": hex(entry),
                           "return_u32": value if status else None,
                           "void_return_ignored": not status})
        return value

    def decode_table_probe(self, video_rows, flags, count, total):
        sample_header = self.allocate(0x20)
        self.uc.mem_write(sample_header, struct.pack("<III4xQ", flags, count, total, video_rows))
        outband_object, outband_bytes = self.allocate(0x40), self.allocate(0x10000)
        items, item_storage, item_cursor = self.allocate(0x20), self.allocate(256 * 24), self.allocate(8)
        self.step("outband_buffer_constructor", 0x107904,
                  [outband_object, outband_bytes, 0x10000], False)
        self.step("outband_list_constructor", 0xfb22c, [items, 256], False)
        status = self.step("original_parameter_set_preparation", 0x11075c,
                           [self.reader, sample_header, outband_object, items,
                            item_storage, 256, item_cursor])
        list_count = self.invoke(0xfb32c, [items])
        if list_count > 256:
            raise RuntimeError("Original parameter-set list exceeded probe capacity")
        parameters = []
        pointer, length = self.allocate(8), self.allocate(8)
        for index in range(list_count):
            self.step("parameter_list_item", 0xfb388, [items, index, pointer, length])
            entry = struct.unpack("<Q", self.uc.mem_read(pointer, 8))[0]
            kind = struct.unpack("<I", self.uc.mem_read(entry, 4))[0]
            value, size = struct.unpack("<QI", self.uc.mem_read(entry + 8, 12))
            if kind not in {0, 2, 3, 4} or size > 0x10000:
                raise RuntimeError("Unexpected original parameter-set descriptor")
            parameters.append({"kind": kind, "size": size,
                               "hex": bytes(self.uc.mem_read(value, size)).hex() if size else ""})
        owner, table, cursor, extra = (self.allocate(0x2000), self.allocate(240 * 64),
                                      self.allocate(8), self.allocate(8))
        self.uc.mem_write(owner + 0x1d20, struct.pack("<QI", table, 240))
        self.uc.mem_write(owner + 0x1d58, struct.pack("<Q", items))
        conversions = []
        if status == 0:
            for index in range(count):
                descriptor = video_rows + index * 64
                config = self.step("original_video_config_table", 0x10c998,
                                   [owner, descriptor, cursor, extra])
                frame = self.step("original_video_frame_table", 0x10c4a4,
                                  [owner, descriptor, cursor])
                conversions.append({"config_return_u32": config, "frame_return_u32": frame})
                if config or frame:
                    break
        table_count = struct.unpack("<I", self.uc.mem_read(cursor, 4))[0]
        if table_count > 240:
            raise RuntimeError("Original video decode-table probe exceeded capacity")
        return {"parameter_preparation_return_u32": status, "parameter_sets": parameters,
                "conversions": conversions, "table_count": table_count,
                "tables": [bytes(self.uc.mem_read(table + i * 64, 64)).hex()
                           for i in range(table_count)],
                "scope": "Original parameter preparation and video table construction, no hardware submission"}

    def sample_probe(self, max_batches, decode_tables=False):
        """Call the original SDK getters used by the read worker."""
        video_cells, audio_cells, meta_cells = [self.allocate(0x20) for _ in range(3)]
        video_rows = self.allocate(0x3c00)
        audio_rows = self.allocate(0x1e00)
        meta_rows = self.allocate(0x1680)
        presentation = self.allocate(0x100)
        batches = []
        self.partial_sample_batches = batches
        new_presentation = True
        for index in range(max_batches):
            if new_presentation:
                status = self.step("presentation_query", 0x228170, [self.reader, presentation])
                if status != 0:
                    return {"batches": batches, "return_u32": status, "stage": "presentation_query"}
            self.uc.mem_write(video_cells, bytes(0x20))
            self.uc.mem_write(video_rows, bytes(0x3c00))
            status = self.step("video_sample_query", 0x226d20,
                               [self.reader, video_cells, video_cells + 4, video_cells + 8,
                                video_rows, 0])
            if status != 0:
                return {"batches": batches, "return_u32": status, "stage": "video_sample_query"}
            flags, count, total = struct.unpack("<III", self.uc.mem_read(video_cells, 12))
            if count > 240:
                raise RuntimeError("Original video getter exceeded bounded worker capacity")
            video = [bytes(self.uc.mem_read(video_rows + i * 0x40, 0x40))
                     for i in range(count)]
            last_index = max((struct.unpack_from("<I", row, 0x38)[0] for row in video), default=0)
            audio = []
            for attempt in range(8):
                self.uc.mem_write(audio_cells, struct.pack("<I", 1) + bytes(28))
                status = self.step("audio_sample_query", 0x228bf0,
                                   [self.reader, last_index, 0, audio_cells,
                                    audio_cells + 4, audio_cells + 8, audio_rows])
                aflags, acount, atotal = struct.unpack("<III", self.uc.mem_read(audio_cells, 12))
                if acount > 240:
                    raise RuntimeError("Original audio getter exceeded bounded worker capacity")
                audio.append({"return_u32": status, "flags": aflags, "count": acount,
                              "total_bytes": atotal,
                              "rows": [bytes(self.uc.mem_read(audio_rows + i * 32, 32)).hex()
                                       for i in range(acount)]})
                if status or aflags & 0xb:
                    break
            else:
                raise RuntimeError("Original audio getter made no bounded flag progress")
            self.uc.mem_write(meta_cells, struct.pack("<I", 1) + bytes(28))
            self.uc.mem_write(meta_rows, bytes(0x1680))
            status = status or self.step(
                "metadata_sample_query", 0x22843c,
                [self.reader, last_index, meta_cells, meta_cells + 4, meta_cells + 8, meta_rows])
            mflags, mcount, mtotal = struct.unpack("<III", self.uc.mem_read(meta_cells, 12))
            if mcount > 240:
                raise RuntimeError("Original metadata getter exceeded bounded worker capacity")
            new_presentation = bool((flags & 1 and audio[-1]["flags"] & 1) or flags & 0x10)
            batches.append({
                "batch": index, "video_flags": flags, "video_count": count, "video_bytes": total,
                "worker_boundary": new_presentation,
                "video_rows": [row.hex() for row in video], "audio": audio,
                "metadata_flags": mflags, "metadata_count": mcount, "metadata_bytes": mtotal,
                "metadata_rows": [bytes(self.uc.mem_read(meta_rows + i * 24, 24)).hex()
                                  for i in range(mcount)],
                "presentation_hex": bytes(self.uc.mem_read(presentation, 0xa0)).hex(),
            })
            if decode_tables and index == 0:
                batches[-1]["decode_table_probe"] = self.decode_table_probe(
                    video_rows, flags, count, total)
            if status:
                return {"batches": batches, "return_u32": status, "stage": "audio_or_metadata_query"}
            if flags & 0x10:
                break
        return {"batches": batches, "return_u32": 0,
                "reached_video_end": bool(batches and batches[-1]["video_flags"] & 0x10),
                "sample_query_scope": "Original getters, first audio track; no decoder submission"}

    def rtmd_probe(self, packets):
        movie_reader = self.allocate(0x2000)
        parser, tc_converter = self.allocate(0x40), self.allocate(0x40)
        table = self.allocate(0x500 * len(packets))
        counter, packet, present, item = [self.allocate(size)
                                          for size in (0x10, 0x10000, 0x10, 0x100)]
        self.step("rtmd_parser_constructor", 0x1a39d8, [parser], False)
        self.step("timecode_converter_constructor", 0x1a5684, [tc_converter], False)
        self.uc.mem_write(movie_reader + 0xe8, struct.pack("<QQ", parser, tc_converter))
        self.uc.mem_write(movie_reader + 0x1d40, struct.pack("<QI", table, len(packets)))
        results = []
        for number, data in packets:
            if len(data) > 0xffff:
                raise ValueError("RTMD probe exceeds original worker's selected sample limit")
            self.uc.mem_write(packet, bytes(0x10000))
            self.uc.mem_write(packet, data)
            self.uc.mem_write(present, bytes(0x10))
            self.uc.mem_write(item, bytes(0x100))
            transit = self.step("rtmd_transit_to_query", 0x1a3b28, [parser, packet])
            basic = self.step("rtmd_basic_timecode_query", 0x1a3a24,
                              [parser, 0xf001, 0x10, present, item])
            has_item = bool(self.uc.mem_read(present, 1)[0])
            basic_item = bytes(self.uc.mem_read(item, 16))
            self.uc.mem_write(counter, bytes(4))
            converted = self.step("original_metadata_decode_table", 0x10c550,
                                  [movie_reader, packet, counter])
            result = bytes(self.uc.mem_read(table, 0x500))
            results.append({"frame_index": number, "sample_sha256": hashlib.sha256(data).hexdigest(),
                            "sample_size": len(data), "transit_return_u32": transit,
                            "basic_query_return_u32": basic, "basic_timecode_present": has_item,
                            "basic_timecode_item_hex": basic_item.hex(),
                            "table_conversion_return_u32": converted,
                            "table_count": struct.unpack("<I", self.uc.mem_read(counter, 4))[0],
                            "table_hex": result.hex()})
        return {"packets": results,
                "scope": "Original metadata parser and table converter for selected packets only"}

    def run_reader(self, seek_probe=False, sample_batches=0, decode_tables=False, seek_mode=0):
        self.step("file_object_constructor", 0x22a730, [self.file_object], False)
        self.step("reader_constructor", 0x222994, [self.reader, self.settings], False)
        result = self.step("file_buffer_setup", 0x22a774, [self.file_object, 0x20000])
        if result == 0:
            result = self.step("readonly_file_open", 0x22af44,
                               [self.file_object, self.path, 1, self.output])
        if result == 0:
            result = self.step("original_mp4_open", 0x22a380,
                               [self.reader, self.file_object, 1, 0, self.output])
        if result == 0:
            result = self.step("original_movie_property_query", 0x228fa8,
                               [self.reader, self.output])
        properties = bytes(self.uc.mem_read(self.output, 0x60))
        seek = None
        if result == 0 and seek_probe:
            parameters = self.allocate(0x20)
            raw = struct.pack("<QIIII", 90000, seek_mode, 0, 0, 0)
            self.uc.mem_write(parameters, raw)
            status = self.step("selected_start_position_probe", 0x227714, [self.reader, parameters])
            seek = {"return_u32": status, "parameter_hex": raw.hex(),
                    "time_90khz": 90000, "mode": seek_mode, "direction": 0, "flags": 0,
                    "physical_camera_parameters_observed": False}
        samples = self.sample_probe(sample_batches, decode_tables) if result == 0 and sample_batches else None
        return {"last_status_u32": result, "movie_property_hex": properties.hex(),
                "audio_gate": audio_gate(properties) if result == 0 else None,
                "selected_seek_probe": seek,
                "sample_probe": samples,
                "reader_state_hex": bytes(self.uc.mem_read(self.reader, 0x320)).hex(),
                "original_executable_sections_unchanged": all(
                    bytes(self.uc.mem_read(address, len(raw))) == raw
                    for address, raw in self.code_sections)}


def validate_sample_probe(media, probe):
    """Compare guest-produced offsets/lengths against an independent BMFF index."""
    from sony_mp4 import MP4
    source = MP4(media)
    try:
        video = next(track for track in source.tracks if track.handler == "vide")
        audio = next(track for track in source.tracks if track.handler == "soun")
        metadata = next(track for track in source.tracks if track.handler == "meta")
        meta_index = {(offset, size) for offset, size in zip(metadata.offsets, metadata.sizes)}
        audio_ranges = [(offset, offset + count * audio.sizes[0])
                        for offset, count in zip(audio.chunks, audio.chunk_samples)]
        seen = []
        checks = {"sdk_status": probe["return_u32"] == 0, "video_rows_match_source": True,
                  "metadata_rows_match_source": True, "audio_rows_within_source_chunks": True,
                  "batch_byte_totals_match_rows": True}
        for batch in probe["batches"]:
            vtotal, mtotal = 0, 0
            for text in batch["video_rows"]:
                row = bytes.fromhex(text)
                size = struct.unpack_from("<I", row)[0]
                offset = struct.unpack_from("<Q", row, 8)[0]
                number = struct.unpack_from("<I", row, 0x1c)[0]
                checks["video_rows_match_source"] &= (
                    1 <= number <= len(video.sizes) and
                    (offset, size) == (video.offsets[number - 1], video.sizes[number - 1]))
                seen.append(number)
                vtotal += size
            for text in batch["metadata_rows"]:
                row = bytes.fromhex(text)
                size, offset = struct.unpack_from("<I", row)[0], struct.unpack_from("<Q", row, 8)[0]
                checks["metadata_rows_match_source"] &= (offset, size) in meta_index
                mtotal += size
            for item in batch["audio"]:
                atotal = 0
                for text in item["rows"]:
                    row = bytes.fromhex(text)
                    size = struct.unpack_from("<I", row)[0]
                    offset = struct.unpack_from("<Q", row, 8)[0]
                    checks["audio_rows_within_source_chunks"] &= (
                        size % 4 == 0 and any(a <= offset <= offset + size <= b
                                             for a, b in audio_ranges))
                    atotal += size
                checks["batch_byte_totals_match_rows"] &= atotal == item["total_bytes"]
            checks["batch_byte_totals_match_rows"] &= (
                vtotal == batch["video_bytes"] and mtotal == batch["metadata_bytes"])
            if "decode_table_probe" in batch:
                tables = batch["decode_table_probe"]
                expected = parameter_sets_from_avcc(video.avcc())
                actual = {kind: [row["hex"] for row in tables["parameter_sets"] if row["kind"] == kind]
                          for kind in (2, 3)}
                checks["original_parameter_sets_match_avcc"] = (
                    expected == actual and tables["parameter_preparation_return_u32"] == 0)
                checks["original_table_conversions_succeeded"] = all(
                    row["config_return_u32"] == row["frame_return_u32"] == 0
                    for row in tables["conversions"])
                frame_tables = [bytes.fromhex(text) for text in tables["tables"]
                                if bytes.fromhex(text)[0] == 0]
                checks["original_frame_tables_match_sdk_descriptors"] = (
                    len(frame_tables) == len(batch["video_rows"]) and all(
                        table[0x10:0x14] == descriptor[0:4] and
                        table[0x18:0x1c] == descriptor[0x10:0x14] and
                        table[0x20:0x24] == descriptor[0x14:0x18]
                        for table, descriptor in zip(
                            frame_tables, [bytes.fromhex(text) for text in batch["video_rows"]])))
        checks["nonempty_ordered_video_samples"] = bool(seen) and seen == sorted(set(seen))
        if probe.get("reached_video_end"):
            checks["all_video_frames_when_end_reported"] = seen == list(range(1, len(video.sizes) + 1))
        return {"checks": checks, "passed": all(checks.values()),
                "video_frames_checked": len(seen), "total_video_frames": len(video.sizes),
                "independent_oracle": "sony_mp4 ISO BMFF sample index, not firmware output"}
    finally:
        source.close()


def parameter_sets_from_avcc(data):
    """Read AVCC's length-delimited SPS/PPS arrays without normalizing bytes."""
    if len(data) < 7 or data[0] != 1:
        raise ValueError("Expected AVCDecoderConfigurationRecord version 1")
    result, position, count = {2: [], 3: []}, 6, data[5] & 31
    for kind in (2, 3):
        if kind == 3:
            if position >= len(data):
                raise ValueError("Missing AVCC PPS count")
            count, position = data[position], position + 1
        for _ in range(count):
            if position + 2 > len(data):
                raise ValueError("Truncated AVCC parameter length")
            size = struct.unpack_from(">H", data, position)[0]
            position += 2
            if not size or position + size > len(data):
                raise ValueError("Truncated AVCC parameter bytes")
            result[kind].append(data[position:position + size].hex())
            position += size
    return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("media")
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--output", required=True)
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--expat", default="firmware/m4-v602/usr/lib/libexpat.so.1.6.11")
    ap.add_argument("--seek-probe", action="store_true")
    ap.add_argument("--sample-batches", type=int, default=0)
    ap.add_argument("--rtmd-probe", action="store_true")
    ap.add_argument("--decode-table-probe", action="store_true")
    ap.add_argument("--max-runtime-seconds", type=int, default=120)
    ap.add_argument("--seek-mode", type=int, choices=(0, 1), default=0)
    args = ap.parse_args()
    if not 0 <= args.sample_batches <= 1000:
        raise ValueError("sample-batches must be 0..1000")
    if args.sample_batches and not args.seek_probe:
        raise ValueError("Use --seek-probe to initialize the original sample cursors")
    if args.decode_table_probe and not args.sample_batches:
        raise ValueError("Decode-table probing requires --sample-batches")
    if not 1 <= args.max_runtime_seconds <= 1800:
        raise ValueError("max-runtime-seconds must be 1..1800")
    media, snapshot, output, firmware, expat = [Path(x).resolve() for x in
                                               (args.media, args.snapshot, args.output,
                                                args.firmware, args.expat)]
    if any(p.drive.upper() == "F:" for p in (media, snapshot, output, firmware, expat)):
        raise ValueError("Only local media and saved snapshots allowed")
    if not (snapshot / "_snapshot.json").is_file() or output == media or snapshot in output.parents:
        raise ValueError("Invalid offline inputs/output")
    report = {"media": str(media), "firmware_sha256": EXPECTED, "card_access": False,
              "scope": "Original MP4 read-side parser, modeled libc/Fsys; not camera playback",
              "root_cause_established": False}
    engine = None
    with media.open("rb") as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
        report["media_sha256"] = hashlib.sha256(data).hexdigest()
        try:
            engine = XavcReaderEmulator(firmware, expat, snapshot, data, args.max_runtime_seconds)
            report["result"] = engine.run_reader(args.seek_probe, args.sample_batches,
                                                args.decode_table_probe, args.seek_mode)
            if report["result"]["sample_probe"] is not None:
                report["sample_index_crosscheck"] = validate_sample_probe(
                    media, report["result"]["sample_probe"])
            if args.rtmd_probe and report["result"]["last_status_u32"] == 0:
                from sony_mp4 import MP4
                source = MP4(media)
                try:
                    track = next(t for t in source.tracks if t.handler == "meta")
                    selected = sorted({0, min(1, len(track.sizes) - 1), len(track.sizes) - 1})
                    packets = [(number, track.sample(number)) for number in selected]
                finally:
                    source.close()
                report["rtmd_probe"] = engine.rtmd_probe(packets)
        except Exception as error:
            report["emulation_error"] = str(error)
            report["error_kind"] = type(error).__name__
        if engine:
            report.update({"steps": engine.steps, "calls": engine.calls, "io": engine.io,
                           "diagnostic_packets": engine.diagnostics,
                           "original_stdcpp_sha256": engine.runtime_sha256,
                           "selected_original_runtime_helpers": engine.runtime_helpers,
                           "heap_bytes_used": engine.heap_cursor - HEAP,
                           "last_instructions": engine.tail, "last_boundaries": engine.boundaries[-30:],
                           "instruction_count": engine.instruction_count,
                           "active_step": engine.active_step})
            report["original_entry_trace"] = engine.trace_counts
            if "emulation_error" in report:
                report["guest_registers_at_failure"] = {
                    f"x{i}": hex(engine.uc.reg_read(getattr(regs, f"UC_ARM64_REG_X{i}")))
                    for i in range(29)}
            if "emulation_error" in report and engine.partial_sample_batches:
                report["partial_sample_batches_not_complete"] = engine.partial_sample_batches
            report["original_executable_sections_unchanged_after_all_probes"] = all(
                bytes(engine.uc.mem_read(address, len(raw))) == raw
                for address, raw in engine.code_sections)
        if hashlib.sha256(data).hexdigest() != report["media_sha256"]:
            raise RuntimeError("Local media changed during execution")
    output.parent.mkdir(parents=True, exist_ok=True)
    result = report.get("result", {})
    report["passed_selected_reader_checks"] = (
        "emulation_error" not in report and result.get("last_status_u32") == 0 and
        report.get("original_executable_sections_unchanged_after_all_probes") is True and
        report.get("sample_index_crosscheck", {"passed": True})["passed"] is True)
    if "rtmd_probe" in report:
        report["passed_selected_reader_checks"] &= all(
            row["transit_return_u32"] == row["basic_query_return_u32"] ==
            row["table_conversion_return_u32"] == 0 and row["basic_timecode_present"] and
            row["table_count"] == 1 for row in report["rtmd_probe"]["packets"])
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    summary = {key: report[key] for key in ("emulation_error", "sample_index_crosscheck")
               if key in report}
    summary["completed_calls"] = len(report.get("steps", []))
    summary["passed_selected_reader_checks"] = report["passed_selected_reader_checks"]
    if "result" in report:
        summary["open_query_status"] = report["result"]["last_status_u32"]
        if report["result"]["sample_probe"]:
            samples = report["result"]["sample_probe"]
            summary["sample_status"] = samples["return_u32"]
            summary["video_end_reached"] = samples.get("reached_video_end")
    if "rtmd_probe" in report:
        summary["rtmd_packets"] = [{key: row[key] for key in
                                   ("frame_index", "transit_return_u32", "basic_timecode_present",
                                    "table_conversion_return_u32")}
                                  for row in report["rtmd_probe"]["packets"]]
    print(json.dumps(summary, indent=2))
    if not report["passed_selected_reader_checks"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
