"""Independent Sony XML codec-name oracle for the currently modeled profiles.

Literal spellings recovered from libmpr ELF 0x8cff4 / table at 0x3bd448;
lookup at 0x24bf44 returns 0x9a for unknown names, rejected at 0x23d394.
This is intentionally not derived from SonyProfile.video_codec.
"""

SONY_XML_AVC_HIGH_NAMES = {
    (1920, 1080, 40): "AVC_1920_1080_HP@L4",
    (1920, 1080, 41): "AVC_1920_1080_HP@L41",
    (1920, 1080, 42): "AVC_1920_1080_HP@L42",
    (3840, 2160, 51): "AVC_3840_2160_HP@L51",
}


def codec_name_matches(value, profile):
    expected = SONY_XML_AVC_HIGH_NAMES.get(
        (profile.width, profile.height, profile.level_idc))
    return expected is not None and value == expected


def nrt_codec_matches(root, profile):
    nodes = [node for node in root.iter()
             if node.tag.rsplit("}", 1)[-1] == "VideoFrame"]
    return len(nodes) == 1 and codec_name_matches(nodes[0].get("videoCodec"), profile)
