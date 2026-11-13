"""Purpose: inspect the supported ISO BMFF structures used by XAVC experiments.

Usage: python tools/sony_mp4.py LOCAL.MP4 [OTHER.MP4] [--output REPORT.json];
    import MP4/Track for read-only sample indexing and box/fullbox for builders.
Design: memory-map files, enforce box bounds and expose explicit track tables
    and efficient constant/uniform sample sequences.
Scope: intentionally narrow BMFF layouts, not a universal media parser/decoder.
    Callers must close mapped inputs; inspection does not prove Sony conformance.
"""
import argparse
import json
import mmap
import struct
from bisect import bisect_right
from collections.abc import Sequence
from dataclasses import dataclass
from pathlib import Path


class ConstantSizes(Sequence):
    def __init__(self, size, count):
        if size < 0 or count < 0:
            raise ValueError("Negative size or count")
        self.size, self.count = size, count

    def __len__(self):
        return self.count

    def __getitem__(self, index):
        if isinstance(index, slice):
            return ConstantSizes(self.size, len(range(*index.indices(self.count))))
        if index < 0:
            index += self.count
        if not 0 <= index < self.count:
            raise IndexError(index)
        return self.size


class UniformOffsets(Sequence):
    def __init__(self, chunks, counts, size):
        self.chunks, self.size = chunks, size
        self.starts = [0]
        for count in counts:
            self.starts.append(self.starts[-1] + count)

    def __len__(self):
        return self.starts[-1]

    def __getitem__(self, index):
        if isinstance(index, slice):
            return [self[i] for i in range(*index.indices(len(self)))]
        if index < 0:
            index += len(self)
        if not 0 <= index < len(self):
            raise IndexError(index)
        chunk = bisect_right(self.starts, index) - 1
        return self.chunks[chunk] + (index - self.starts[chunk]) * self.size


def u32(b, p=0):
    return struct.unpack_from(">I", b, p)[0]


def box(kind, payload):
    return struct.pack(">I4s", len(payload) + 8, kind.encode("ascii")) + payload


def fullbox(kind, payload, flags=0):
    return box(kind, struct.pack(">I", flags) + payload)


@dataclass
class Box:
    start: int
    size: int
    kind: str
    header: int

    @property
    def data(self):
        return self.start + self.header

    @property
    def end(self):
        return self.start + self.size


class MP4:
    def __init__(self, path):
        self.path = Path(path)
        self.file = self.path.open("rb")
        self.buf = mmap.mmap(self.file.fileno(), 0, access=mmap.ACCESS_READ)
        self.top = self.boxes(0, len(self.buf))
        self.moov = self.one(self.top, "moov")
        self.tracks = [Track(self, b) for b in self.children(self.moov) if b.kind == "trak"]

    def close(self):
        self.buf.close()
        self.file.close()

    def boxes(self, start, end):
        result = []
        p = start
        while p < end:
            if end - p < 8:
                raise ValueError(f"Trailing bytes at {p:x}")
            size, kind = struct.unpack_from(">I4s", self.buf, p)
            header = 8
            if size == 1:
                size = struct.unpack_from(">Q", self.buf, p + 8)[0]
                header = 16
            elif size == 0:
                size = end - p
            if size < header or p + size > end:
                raise ValueError(f"Invalid {kind!r} at {p:x}, size={size}")
            result.append(Box(p, size, kind.decode("ascii", errors="replace"), header))
            p += size
        return result

    def children(self, b, skip=0):
        return self.boxes(b.data + skip, b.end)

    @staticmethod
    def one(boxes, kind):
        matches = [b for b in boxes if b.kind == kind]
        if len(matches) != 1:
            raise ValueError(f"Expected one {kind}, got {len(matches)}")
        return matches[0]

    def child(self, parent, kind, skip=0):
        return self.one(self.children(parent, skip), kind)

    def raw(self, b):
        return self.buf[b.start:b.end]

    def payload(self, b):
        return self.buf[b.data:b.end]


class Track:
    def __init__(self, m, b):
        self.m, self.box = m, b
        self.mdia = m.child(b, "mdia")
        self.mdhd = m.child(self.mdia, "mdhd")
        md = m.payload(self.mdhd)
        self.timescale = u32(md, 20 if md[0] else 12)
        self.duration = struct.unpack_from(">Q", md, 24)[0] if md[0] else u32(md, 16)
        self.handler = m.payload(m.child(self.mdia, "hdlr"))[8:12].decode("ascii")
        self.stbl = m.child(m.child(self.mdia, "minf"), "stbl")
        self.tables = {x.kind: x for x in m.children(self.stbl)}
        stsd = self.tables["stsd"]
        self.entries = m.children(stsd, 8)
        if len(self.entries) != 1:
            raise ValueError("Multiple sample descriptions not supported")
        self.entry = self.entries[0]
        self.codec = self.entry.kind
        sz = m.payload(self.tables["stsz"])
        uniform, count = struct.unpack_from(">II", sz, 4)
        self.sizes = ConstantSizes(uniform, count) if uniform else list(
            struct.unpack_from(f">{count}I", sz, 12))
        self.stts = self.rows("stts", 2)
        if sum(x[0] for x in self.stts) != count:
            raise ValueError("stts/stsz count mismatch")
        if sum(x[0] * x[1] for x in self.stts) != self.duration:
            raise ValueError("stts/mdhd duration mismatch")
        self.ctts = self.rows("ctts", 2) if "ctts" in self.tables else []
        self.sync = [x[0] for x in self.rows("stss", 1)] if "stss" in self.tables else []
        co = "co64" if "co64" in self.tables else "stco"
        payload = m.payload(self.tables[co])
        n = u32(payload, 4)
        self.chunks = list(struct.unpack_from(f">{n}{'Q' if co == 'co64' else 'I'}", payload, 8))
        sc = self.rows("stsc", 3)
        self.offsets, self.chunk_samples = [], []
        sample, j = 0, 0
        mdats = [x for x in m.top if x.kind == "mdat"]
        for i, offset in enumerate(self.chunks, 1):
            while j + 1 < len(sc) and sc[j + 1][0] <= i:
                j += 1
            if not sc or sc[0][0] != 1 or sc[j][2] != 1:
                raise ValueError("Invalid sample-to-chunk")
            per = sc[j][1]
            if not per:
                raise ValueError("Empty chunk")
            self.chunk_samples.append(per)
            if sample + per > count:
                raise ValueError("Too many chunk samples")
            end = offset + (uniform * per if uniform else sum(self.sizes[sample:sample + per]))
            if not any(x.data <= offset <= end <= x.end for x in mdats):
                raise ValueError(f"Chunk outside mdat: {offset:x}..{end:x}")
            if not uniform:
                for size in self.sizes[sample:sample + per]:
                    self.offsets.append(offset)
                    offset += size
            sample += per
        if sample != count:
            raise ValueError("Incomplete sample-to-chunk mapping")
        if uniform:
            self.offsets = UniformOffsets(self.chunks, self.chunk_samples, uniform)

    def rows(self, name, width):
        p = self.m.payload(self.tables[name])
        n = u32(p, 4)
        if len(p) != 8 + n * width * 4:
            raise ValueError(f"Invalid {name} length")
        signed = name == "ctts" and p[0] == 1
        fmt = ">" + ("Ii" if signed else "I" * width)
        return [struct.unpack_from(fmt, p, 8 + i * width * 4) for i in range(n)]

    def sample(self, index):
        p = self.offsets[index]
        return self.m.buf[p:p + self.sizes[index]]

    def avcc(self):
        if self.codec != "avc1":
            raise ValueError("Not AVC")
        return self.m.payload(self.m.child(self.entry, "avcC", 78))

    def summary(self):
        result = {"handler": self.handler, "codec": self.codec, "timescale": self.timescale,
                  "duration": self.duration, "samples": len(self.sizes), "chunks": len(self.chunks),
                  "stts": self.stts, "ctts_rows": len(self.ctts), "sync_first": self.sync[:12],
                  "sample_size_first": list(self.sizes[:12]), "offset_first": self.offsets[:3],
                  "entry_hex": self.m.raw(self.entry).hex()}
        if self.codec == "avc1":
            result["avcc_hex"] = self.avcc().hex()
        return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("paths", nargs="+")
    ap.add_argument("--output")
    args = ap.parse_args()
    result = []
    for path in args.paths:
        m = MP4(path)
        report = {"path": str(m.path), "top": [vars(x) for x in m.top],
                  "tracks": [x.summary() for x in m.tracks]}
        report["prof"] = [m.raw(b).hex() for b in m.top if b.kind == "uuid"]
        meta = [x for x in m.children(m.moov) if x.kind == "meta"]
        report["meta_hex"] = [m.raw(x).hex() for x in meta]
        result.append(report)
        m.close()
    text = json.dumps(result, indent=2)
    if args.output:
        dst = Path(args.output)
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_text(text, encoding="utf-8")
        print(dst)
    else:
        print(text)


if __name__ == "__main__":
    main()
