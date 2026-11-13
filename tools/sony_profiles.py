"""Purpose: define explicit AVC 8-bit 4:2:0 SD experiment profiles.

Usage: import PROFILES, get_profile or manifest_profile from sony_profiles;
    CLI tools expose the keys in PROFILES. No own CLI.
Design: centralize resolution, cadence, bitrate, GOP and metadata constants,
    refusing contradictory declared manifest parameters.
Scope: these tested experiment combinations only, not a general Sony profile
    registry, all-input guarantee or independent camera certification.
"""
from dataclasses import dataclass
from fractions import Fraction


@dataclass(frozen=True)
class SonyProfile:
    name: str
    width: int
    height: int
    fps_num: int
    bitrate_kbps: int
    level_idc: int
    gop_frames: int
    half_step: bool
    fps_den: int = 1001

    @property
    def fps(self):
        return Fraction(self.fps_num, self.fps_den)

    @property
    def fps_text(self):
        return f"{self.fps_num}/{self.fps_den}"

    @property
    def xml_fps(self):
        return "59.94p" if self.half_step else "29.97p"

    @property
    def video_codec(self):
        return f"AVC_{self.width}_{self.height}_HP@L{self.level_idc}"

    @property
    def timescale(self):
        return self.fps_num

    @property
    def vui_tick(self):
        return 240000 * self.fps_den // (2 * self.fps_num)

    @property
    def prof_fps(self):
        # Observed C6359 and C0001 values; do not infer their rounding rule.
        return 0x003bf0a6 if self.half_step else 0x001df853

    @property
    def level(self):
        return f"{self.level_idc // 10}.{self.level_idc % 10}"

    def audio_boundary(self, frame):
        if frame < 0:
            raise ValueError("Negative frame count")
        return frame * 48000 * self.fps_den // self.fps_num

    def manifest_fields(self):
        return {
            "name": self.name, "width": self.width, "height": self.height,
            "fps_num": self.fps_num, "fps_den": self.fps_den,
            "nominal_bitrate_kbps": self.bitrate_kbps,
            "vbv_buffer_kbits": self.bitrate_kbps, "level_idc": self.level_idc,
            "pixel_format": "yuv420p", "gop_frames": self.gop_frames,
            "half_step": self.half_step, "nal_length_size": 4,
        }


DEFAULT_PROFILE = "hd25_5994"
PROFILES = {
    p.name: p for p in (
        SonyProfile("hd25_5994", 1920, 1080, 60000, 25000, 42, 30, True),
        SonyProfile("hd50_5994", 1920, 1080, 60000, 50000, 42, 30, True),
        SonyProfile("uhd60_2997", 3840, 2160, 30000, 60000, 51, 15, False),
        SonyProfile("hd50_2997", 1920, 1080, 30000, 50000, 41, 15, False),
        SonyProfile("hd16_2997", 1920, 1080, 30000, 16000, 40, 30, False),
    )
}


def get_profile(name=DEFAULT_PROFILE):
    try:
        return PROFILES[name]
    except (KeyError, TypeError):
        raise ValueError(f"Unsupported Sony profile: {name}") from None


def manifest_profile(manifest):
    """Keep legacy 25M manifests readable, but bind every declared profile field."""
    profile = get_profile(manifest.get("sony_profile", DEFAULT_PROFILE))
    if "profile_parameters" in manifest and manifest["profile_parameters"] != profile.manifest_fields():
        raise ValueError("Manifest profile parameters disagree with selected Sony profile")
    return profile
