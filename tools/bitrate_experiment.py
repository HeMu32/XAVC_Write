"""Strict, separate admission and parameters for the four-file bitrate diagnostic.

No diagnostic is registered as a camera-qualified Sony profile.
"""
import json
from dataclasses import asdict, dataclass, fields, replace
from datetime import datetime
from pathlib import Path

from sony_profiles import get_profile, manifest_profile


@dataclass(frozen=True)
class ExperimentSpec:
    schema: int
    kind: str
    experiment_id: str
    pair_id: str
    variant: str
    base_profile: str
    coded_bitrate_kbps: int
    hrd_bitrate_kbps: int
    cpb_size_kbits: int
    prof_average_kbps: int
    prof_maximum_kbps: int
    creation_time: str

    @classmethod
    def from_dict(cls, raw):
        if not isinstance(raw, dict) or set(raw) != {f.name for f in fields(cls)}:
            raise ValueError("Experiment spec requires exactly the diagnostic schema fields")
        numeric = ("schema", "coded_bitrate_kbps", "hrd_bitrate_kbps",
                   "cpb_size_kbits", "prof_average_kbps", "prof_maximum_kbps")
        if any(type(raw[k]) is not int for k in numeric):
            raise ValueError("Experiment numeric parameters must be integers, not booleans")
        if any(not isinstance(raw[k], str) or not raw[k].strip()
               for k in set(raw) - set(numeric)):
            raise ValueError("Experiment text fields must be nonempty strings")
        if (raw["schema"] != 1 or raw["kind"] != "bitrate_diagnostic" or
                raw["variant"] not in {"A", "B"} or
                raw["base_profile"] not in {"hd16_2997", "hd25_5994"} or
                any(raw[k] != 4000 for k in
                    ("coded_bitrate_kbps", "hrd_bitrate_kbps", "cpb_size_kbits"))):
            raise ValueError("Unsupported bitrate diagnostic; this round isolates only PROF at 4M")
        baseline = get_profile(raw["base_profile"])
        expected = baseline.bitrate_kbps if raw["variant"] == "A" else 4000
        if (raw["prof_average_kbps"], raw["prof_maximum_kbps"]) != (expected, expected):
            raise ValueError("PROF declarations disagree with diagnostic variant")
        try:
            stamp = datetime.fromisoformat(raw["creation_time"])
            if stamp.utcoffset() is None or stamp.microsecond:
                raise ValueError("Diagnostic timestamp must have timezone and whole seconds")
        except (ValueError, TypeError) as error:
            raise ValueError("Invalid diagnostic creation_time") from error
        return cls(**raw)

    def to_dict(self):
        return asdict(self)

    def coding_profile(self):
        return replace(get_profile(self.base_profile),
                       name="bitrate_diagnostic_" + self.base_profile,
                       bitrate_kbps=self.coded_bitrate_kbps)

    def coding_fields(self):
        return {key: value for key, value in self.to_dict().items()
                if key not in {"variant", "prof_average_kbps", "prof_maximum_kbps"}}

    @property
    def expected_reader_status(self):
        return 3 if (self.base_profile, self.variant) == ("hd16_2997", "B") else 0


def load_spec(path):
    def unique(pairs):
        result = {}
        for key, value in pairs:
            if key in result:
                raise ValueError("Duplicate experiment parameter: " + key)
            result[key] = value
        return result
    return ExperimentSpec.from_dict(json.loads(
        Path(path).read_text(encoding="utf-8"), object_pairs_hook=unique))


def package_spec(manifest):
    if manifest.get("package_kind", "encoded_avc") != "bitrate_diagnostic":
        if any(k in manifest for k in ("experiment_spec", "diagnostic_evidence",
                                      "experiment_spec_path", "experiment_spec_sha256")):
            raise ValueError("Ordinary package may not contain diagnostic parameters or evidence")
        return None
    spec = ExperimentSpec.from_dict(manifest.get("experiment_spec"))
    selected = spec.coding_profile()
    if (manifest.get("sony_profile") != spec.base_profile or
            manifest.get("profile_parameters") != selected.manifest_fields() or
            manifest.get("test_role") != "bitrate_diagnostic" or
            manifest.get("stamp") != spec.creation_time or
            manifest.get("nal_length_size") != 4 or
            manifest.get("umid_mode") != "edius_uuid4" or
            manifest.get("payload_layout") != "structure_template" or
            manifest.get("acquisition") != "rec709" or
            manifest.get("hrd_retiming", {}).get("enabled") is not True):
        raise ValueError("Diagnostic manifest disagrees with experiment or fixed controls")
    return spec


def package_profile(manifest):
    spec = package_spec(manifest)
    return spec.coding_profile() if spec else manifest_profile(manifest)


def require_diagnostic_evidence(report, build, manifest):
    """Recompute both proofs at deployment; never treat a reader failure as a pass."""
    from bitrate_reader_evidence import validate_reader_report
    from compare_bitrate_pair import compare_pair
    from sony_verification import digest
    spec = package_spec(manifest)
    if spec is None:
        return
    build = Path(build).resolve()
    bound = report.get("diagnostic_evidence", {})
    locations = manifest.get("diagnostic_evidence", {})
    if set(locations) != {"peer_build", "pair_report", "reader_report"}:
        raise ValueError("Diagnostic package needs pair and original-reader evidence")
    for key in ("pair_report", "reader_report"):
        path = Path(locations[key]).resolve()
        if bound.get(key + "_sha256") != digest(path):
            raise ValueError("Diagnostic evidence changed: " + key)
    if (digest(manifest["experiment_spec_path"]) != manifest["experiment_spec_sha256"] or
            load_spec(manifest["experiment_spec_path"]) != spec):
        raise ValueError("Diagnostic source spec changed")
    peer = Path(locations["peer_build"]).resolve()
    a, b = (build, peer) if spec.variant == "A" else (peer, build)
    fresh = compare_pair(a, b)
    saved = json.loads(Path(locations["pair_report"]).read_text(encoding="utf-8"))
    if fresh != saved or fresh.get("passed") is not True:
        raise ValueError("Pair proof stale or failed")
    reader = json.loads(Path(locations["reader_report"]).read_text(encoding="utf-8"))
    return validate_reader_report(reader, build / (manifest["clip"] + ".MP4"), spec)
