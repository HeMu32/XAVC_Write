031acb90: ff030cd1 sub sp, sp, #0x300
031acb94: fd7bbaa9 stp x29, x30, [sp, #-0x60]!
031acb98: fd030091 mov x29, sp
031acb9c: f55b02a9 stp x21, x22, [sp, #0x20]
031acba0: b5030c8b add x21, x29, x12
031acba4: f35301a9 stp x19, x20, [sp, #0x10]
031acba8: f30300aa mov x19, x0
031acbac: e00315aa mov x0, x21
031acbb0: f76303a9 stp x23, x24, [sp, #0x30]
031acbb4: f96b04a9 stp x25, x26, [sp, #0x40]
031acbb8: fb2b00f9 str x27, [sp, #0x50]
031acbbc: e0fdff97 bl #0x31ac33c
031acbc0: b49749f9 ldr x20, [x29, #0x1328]
031acbc4: 160ddd97 bl #0x28f001c
031acbc8: f60300aa mov x22, x0
031acbcc: 190ddd97 bl #0x28f0030
031acbd0: bf1b01b9 str wzr, [x29, #0x118]
031acbd4: 0d6896d2 mov x13, #0xb340
031acbd8: 0e6996d2 mov x14, #0xb348
031acbdc: a1030d8b add x1, x29, x13
031acbe0: 0f6a96d2 mov x15, #0xb350
031acbe4: 906a96d2 mov x16, #0xb354
031acbe8: b16a96d2 mov x17, #0xb355
031acbec: 126b96d2 mov x18, #0xb358
031acbf0: 360000f9 str x22, [x1]
031acbf4: a1030e8b add x1, x29, x14
031acbf8: b6630491 add x22, x29, #0x118
031acbfc: 200000f9 str x0, [x1]
031acc00: a1030f8b add x1, x29, x15
031acc04: e0618052 mov w0, #0x30f
031acc08: 200000b9 str w0, [x1]
031acc0c: a003108b add x0, x29, x16
031acc10: e10316aa mov x1, x22
031acc14: 1f000039 strb wzr, [x0]
031acc18: a003118b add x0, x29, x17
031acc1c: 1f000039 strb wzr, [x0]
031acc20: a003128b add x0, x29, x18
031acc24: 140000f9 str x20, [x0]
031acc28: 146896d2 mov x20, #0xb340
031acc2c: b403148b add x20, x29, x20
031acc30: e00314aa mov x0, x20
031acc34: 3dffff97 bl #0x31ac928
031acc38: e00314aa mov x0, x20
031acc3c: 21ffff97 bl #0x31ac8c0
031acc40: e00315aa mov x0, x21
031acc44: c7fdff97 bl #0x31ac360
031acc48: e00315aa mov x0, x21
031acc4c: e10314aa mov x1, x20
031acc50: 9fec0f94 bl #0x35a7ecc
031acc54: 609e43b9 ldr w0, [x19, #0x39c]
031acc58: 80080034 cbz w0, #0x31acd68
031acc5c: 19008012 mov w25, #-1
031acc60: 60aa4e39 ldrb w0, [x19, #0x3aa]
031acc64: 80260035 cbnz w0, #0x31ad134
031acc68: e00314aa mov x0, x20
031acc6c: ac56cf97 bl #0x258271c
031acc70: 612e40b9 ldr w1, [x19, #0x2c]
031acc74: e00314aa mov x0, x20
031acc78: 628e4729 ldp w2, w3, [x19, #0x3c]
031acc7c: de62cf97 bl #0x25857f4
031acc80: f703002a mov w23, w0
031acc84: e00314aa mov x0, x20
031acc88: a956cf97 bl #0x258272c
031acc8c: e00313aa mov x0, x19
031acc90: 70feff97 bl #0x31ac650
031acc94: 1f1c0072 tst w0, #0xff
031acc98: 800f0054 b.eq #0x31ace88
031acc9c: e00314aa mov x0, x20
031acca0: 52e9f497 bl #0x2ee71e8
031acca4: f806de97 bl #0x292e884
031acca8: 000040b9 ldr w0, [x0]
031accac: 1f040071 cmp w0, #1
031accb0: f8179f1a cset w24, eq
031accb4: 1f00dd97 bl #0x28ecd30
031accb8: 010e80d2 mov x1, #0x70
031accbc: 187f019b mul x24, x24, x1
031accc0: 1a6878b8 ldr w26, [x0, x24]
031accc4: e606de97 bl #0x292e85c
031accc8: 180040b9 ldr w24, [x0]
031acccc: e00314aa mov x0, x20
031accd0: 7de8f497 bl #0x2ee6ec4
031accd4: 601640b9 ldr w0, [x19, #0x14]
031accd8: 1f030071 cmp w24, #0
031accdc: 00105a7a ccmp w0, w26, #0, ne
031acce0: e1220054 b.ne #0x31ad13c
031acce4: e00315aa mov x0, x21
031acce8: e10316aa mov x1, x22
031accec: bf9309f9 str xzr, [x29, #0x1320]
031accf0: bf630439 strb wzr, [x29, #0x118]
031accf4: b82313b9 str w24, [x29, #0x1320]
031accf8: f5f00f94 bl #0x35a90cc
031accfc: a0634439 ldrb w0, [x29, #0x118]
031acd00: e0210034 cbz w0, #0x31ad13c
031acd04: 02d00090 adrp x2, #0x4bac000
031acd08: e1c600d0 adrp x1, #0x4a8a000
031acd0c: 00d00090 adrp x0, #0x4bac000
031acd10: a42353b9 ldr w4, [x29, #0x1320]
031acd14: 00ec0991 add x0, x0, #0x27b
031acd18: 42603d91 add x2, x2, #0xf58
031acd1c: 21b43f91 add x1, x1, #0xfed
031acd20: c3148052 mov w3, #0xa6
031acd24: 176896d2 mov x23, #0xb340
031acd28: 186a96d2 mov x24, #0xb350
031acd2c: 196b96d2 mov x25, #0xb358
031acd30: e9e21594 bl #0x37258d4
031acd34: a003178b add x0, x29, x23
031acd38: 1f7c00a9 stp xzr, xzr, [x0]
031acd3c: a003188b add x0, x29, x24
031acd40: 1f0000f9 str xzr, [x0]
031acd44: a003198b add x0, x29, x25
031acd48: 1f0000b9 str wzr, [x0]
031acd4c: 804e8052 mov w0, #0x274
031acd50: 106896d2 mov x16, #0xb340
031acd54: 0020a072 movk w0, #0x100, lsl #16
031acd58: a103108b add x1, x29, x16
031acd5c: 200000b9 str w0, [x1]
031acd60: e00314aa mov x0, x20
031acd64: 60000014 b #0x31acee4
031acd68: 076482d2 mov x7, #0x1320
031acd6c: 086682d2 mov x8, #0x1330
031acd70: a003078b add x0, x29, x7
031acd74: 1f7c00a9 stp xzr, xzr, [x0]
031acd78: a003088b add x0, x29, x8
031acd7c: 1f7c00a9 stp xzr, xzr, [x0]
031acd80: 601e40b9 ldr w0, [x19, #0x1c]
031acd84: a02313b9 str w0, [x29, #0x1320]
031acd88: 602240b9 ldr w0, [x19, #0x20]
031acd8c: a02713b9 str w0, [x29, #0x1324]
031acd90: 602640b9 ldr w0, [x19, #0x24]
031acd94: a02b13b9 str w0, [x29, #0x1328]
031acd98: 601640b9 ldr w0, [x19, #0x14]
031acd9c: a03313b9 str w0, [x29, #0x1330]
031acda0: 609243b9 ldr w0, [x19, #0x390]
031acda4: 2efdf197 bl #0x2e2c25c
031acda8: a03713b9 str w0, [x29, #0x1334]
031acdac: 096782d2 mov x9, #0x1338
031acdb0: 20008052 mov w0, #1
031acdb4: a103098b add x1, x29, x9
031acdb8: 2a6782d2 mov x10, #0x1339
031acdbc: 20000039 strb w0, [x1]
031acdc0: a0030a8b add x0, x29, x10
031acdc4: e10314aa mov x1, x20
031acdc8: 1f000039 strb wzr, [x0]
031acdcc: e00315aa mov x0, x21
031acdd0: aff20f94 bl #0x35a988c
031acdd4: 0b6e96d2 mov x11, #0xb370
031acdd8: a0030b8b add x0, x29, x11
031acddc: 040040b9 ldr w4, [x0]
031acde0: 9f400371 cmp w4, #0xd0
031acde4: 61060054 b.ne #0x31aceb0
031acde8: 17d00090 adrp x23, #0x4bac000
031acdec: e1c600d0 adrp x1, #0x4a8a000
031acdf0: f7623d91 add x23, x23, #0xf58
031acdf4: 00d00090 adrp x0, #0x4bac000
031acdf8: e20317aa mov x2, x23
031acdfc: 21b43f91 add x1, x1, #0xfed
031ace00: 00583791 add x0, x0, #0xdd6
031ace04: e3058052 mov w3, #0x2f
031ace08: b3e21594 bl #0x37258d4
031ace0c: 00d00090 adrp x0, #0x4bac000
031ace10: e20317aa mov x2, x23
031ace14: 006c3491 add x0, x0, #0xd1b
031ace18: 01068052 mov w1, #0x30
031ace1c: 307b1294 bl #0x364badc
031ace20: 856d96d2 mov x5, #0xb36c
031ace24: 066996d2 mov x6, #0xb348
031ace28: a003058b add x0, x29, x5
031ace2c: bb830391 add x27, x29, #0xe0
031ace30: 17008052 mov w23, #0
031ace34: 1a008012 mov w26, #-1
031ace38: 190040b9 ldr w25, [x0]
031ace3c: a003068b add x0, x29, x6
031ace40: 180040b9 ldr w24, [x0]
031ace44: ff02186b cmp w23, w24
031ace48: 20170054 b.eq #0x31ad12c
031ace4c: e00316aa mov x0, x22
031ace50: e10315aa mov x1, x21
031ace54: 0eec0f94 bl #0x35a7e8c
031ace58: 046482d2 mov x4, #0x1320
031ace5c: a003048b add x0, x29, x4
031ace60: 00004039 ldrb w0, [x0]
031ace64: e00f0034 cbz w0, #0x31ad060
031ace68: 02d00090 adrp x2, #0x4bac000
031ace6c: e1c600d0 adrp x1, #0x4a8a000
031ace70: 00d00090 adrp x0, #0x4bac000
031ace74: 42603d91 add x2, x2, #0xf58
031ace78: 21b43f91 add x1, x1, #0xfed
031ace7c: 005c1691 add x0, x0, #0x597
031ace80: e3088052 mov w3, #0x47
031ace84: 94e21594 bl #0x37258d4
031ace88: 116896d2 mov x17, #0xb340
031ace8c: 126a96d2 mov x18, #0xb350
031ace90: a003118b add x0, x29, x17
031ace94: 136b96d2 mov x19, #0xb358
031ace98: 1f7c00a9 stp xzr, xzr, [x0]
031ace9c: a003128b add x0, x29, x18
031acea0: 1f0000f9 str xzr, [x0]
031acea4: a003138b add x0, x29, x19
031acea8: 1f0000b9 str wzr, [x0]
031aceac: 36020014 b #0x31ad784
031aceb0: 84fbff34 cbz w4, #0x31ace20
031aceb4: 02d00090 adrp x2, #0x4bac000
031aceb8: e1c600d0 adrp x1, #0x4a8a000
031acebc: 00d00090 adrp x0, #0x4bac000
031acec0: 42603d91 add x2, x2, #0xf58
031acec4: 21b43f91 add x1, x1, #0xfed
031acec8: 00543891 add x0, x0, #0xe15
031acecc: 83068052 mov w3, #0x34
031aced0: 81e21594 bl #0x37258d4
031aced4: 40038052 mov w0, #0x1a
031aced8: 0020a072 movk w0, #0x100, lsl #16
031acedc: a01b01b9 str w0, [x29, #0x118]
031acee0: e00316aa mov x0, x22
031acee4: f50ace97 bl #0x252fab8
031acee8: e10314aa mov x1, x20
031aceec: e00315aa mov x0, x21
031acef0: a7ef0f94 bl #0x35a8d8c
031acef4: e00315aa mov x0, x21
031acef8: 11fdff97 bl #0x31ac33c
031acefc: b39749f9 ldr x19, [x29, #0x1328]
031acf00: 930bdd97 bl #0x28efd4c
031acf04: f70300aa mov x23, x0
031acf08: 960bdd97 bl #0x28efd60
031acf0c: 0a6896d2 mov x10, #0xb340
031acf10: 0c6996d2 mov x12, #0xb348
031acf14: a1030a8b add x1, x29, x10
031acf18: 0b6a96d2 mov x11, #0xb350
031acf1c: a2030b8b add x2, x29, x11
031acf20: 8d6a96d2 mov x13, #0xb354
031acf24: ae6a96d2 mov x14, #0xb355
031acf28: 0f6b96d2 mov x15, #0xb358
031acf2c: 370000f9 str x23, [x1]
031acf30: a1030c8b add x1, x29, x12
031acf34: 840080d2 mov x4, #4
031acf38: e30316aa mov x3, x22
031acf3c: 200000f9 str x0, [x1]
031acf40: a15f8052 mov w1, #0x2fd
031acf44: 410000b9 str w1, [x2]
031acf48: a2030d8b add x2, x29, x13
031acf4c: 5f000039 strb wzr, [x2]
031acf50: a2030e8b add x2, x29, x14
031acf54: 5f000039 strb wzr, [x2]
031acf58: a2030f8b add x2, x29, x15
031acf5c: 530000f9 str x19, [x2]
031acf60: 020440f9 ldr x2, [x0, #8]
031acf64: bf1b01b9 str wzr, [x29, #0x118]
031acf68: 425a00b4 cbz x2, #0x31adab0
031acf6c: e00313aa mov x0, x19
031acf70: 51ed1594 bl #0x37284b4
031acf74: 086996d2 mov x8, #0xb348
031acf78: a96a96d2 mov x9, #0xb355
031acf7c: a003088b add x0, x29, x8
031acf80: a103098b add x1, x29, x9
031acf84: 000040f9 ldr x0, [x0]
031acf88: 000440f9 ldr x0, [x0, #8]
031acf8c: 1f0000b9 str wzr, [x0]
031acf90: 20008052 mov w0, #1
031acf94: 20000039 strb w0, [x1]
031acf98: 006896d2 mov x0, #0xb340
031acf9c: 816a96d2 mov x1, #0xb354
031acfa0: a003008b add x0, x29, x0
031acfa4: a103018b add x1, x29, x1
031acfa8: 000040f9 ldr x0, [x0]
031acfac: 1f0000b9 str wzr, [x0]
031acfb0: 20008052 mov w0, #1
031acfb4: 20000039 strb w0, [x1]
031acfb8: e00314aa mov x0, x20
031acfbc: 34feff97 bl #0x31ac88c
031acfc0: e00315aa mov x0, x21
031acfc4: e7fcff97 bl #0x31ac360
031acfc8: e00315aa mov x0, x21
031acfcc: dcfcff97 bl #0x31ac33c
031acfd0: b39749f9 ldr x19, [x29, #0x1328]
031acfd4: 120cdd97 bl #0x28f001c
031acfd8: f70300aa mov x23, x0
031acfdc: 150cdd97 bl #0x28f0030
031acfe0: 026896d2 mov x2, #0xb340
031acfe4: 036996d2 mov x3, #0xb348
031acfe8: a103028b add x1, x29, x2
031acfec: 046a96d2 mov x4, #0xb350
031acff0: 856a96d2 mov x5, #0xb354
031acff4: a66a96d2 mov x6, #0xb355
031acff8: 076b96d2 mov x7, #0xb358
031acffc: 370000f9 str x23, [x1]
031ad000: a103038b add x1, x29, x3
031ad004: 200000f9 str x0, [x1]
031ad008: a103048b add x1, x29, x4
031ad00c: e0618052 mov w0, #0x30f
031ad010: 200000b9 str w0, [x1]
031ad014: a003058b add x0, x29, x5
031ad018: e10316aa mov x1, x22
031ad01c: 1f000039 strb wzr, [x0]
031ad020: a003068b add x0, x29, x6
031ad024: 1f000039 strb wzr, [x0]
031ad028: a003078b add x0, x29, x7
031ad02c: 130000f9 str x19, [x0]
031ad030: 20008052 mov w0, #1
031ad034: a01b01b9 str w0, [x29, #0x118]
031ad038: e00314aa mov x0, x20
031ad03c: 3bfeff97 bl #0x31ac928
031ad040: e00314aa mov x0, x20
031ad044: 1ffeff97 bl #0x31ac8c0
031ad048: e00315aa mov x0, x21
031ad04c: c5fcff97 bl #0x31ac360
031ad050: e10314aa mov x1, x20
031ad054: e00315aa mov x0, x21
031ad058: 9deb0f94 bl #0x35a7ecc
031ad05c: eb000014 b #0x31ad408
031ad060: 601640b9 ldr w0, [x19, #0x14]
031ad064: 026682d2 mov x2, #0x1330
031ad068: 036882d2 mov x3, #0x1340
031ad06c: e10315aa mov x1, x21
031ad070: a0671c29 stp w0, w25, [x29, #0xe0]
031ad074: 006482d2 mov x0, #0x1320
031ad078: a003008b add x0, x29, x0
031ad07c: b7eb00b9 str w23, [x29, #0xe8]
031ad080: bfab09f9 str xzr, [x29, #0x1350]
031ad084: 1f7c00a9 stp xzr, xzr, [x0]
031ad088: a003028b add x0, x29, x2
031ad08c: ba2313b9 str w26, [x29, #0x1320]
031ad090: b49709f9 str x20, [x29, #0x1328]
031ad094: 1f7c00a9 stp xzr, xzr, [x0]
031ad098: a003038b add x0, x29, x3
031ad09c: 1f7c00a9 stp xzr, xzr, [x0]
031ad0a0: e0031baa mov x0, x27
031ad0a4: 0af10f94 bl #0x35a94cc
031ad0a8: a43353b9 ldr w4, [x29, #0x1330]
031ad0ac: c4020035 cbnz w4, #0x31ad104
031ad0b0: 1eb597d2 mov x30, #0xbda8
031ad0b4: 61a243b9 ldr w1, [x19, #0x3a0]
031ad0b8: a0031e8b add x0, x29, x30
031ad0bc: 000040b9 ldr w0, [x0]
031ad0c0: 3f00006b cmp w1, w0
031ad0c4: 01030054 b.ne #0x31ad124
031ad0c8: 18070051 sub w24, w24, #1
031ad0cc: ff02186b cmp w23, w24
031ad0d0: 60dcff54 b.eq #0x31acc5c
031ad0d4: 1a6896d2 mov x26, #0xb340
031ad0d8: 9b6896d2 mov x27, #0xb344
031ad0dc: a0031a8b add x0, x29, x26
031ad0e0: f7060011 add w23, w23, #1
031ad0e4: e10315aa mov x1, x21
031ad0e8: 190000b9 str w25, [x0]
031ad0ec: a0031b8b add x0, x29, x27
031ad0f0: 170000b9 str w23, [x0]
031ad0f4: e00314aa mov x0, x20
031ad0f8: a5f10f94 bl #0x35a978c
031ad0fc: b92353b9 ldr w25, [x29, #0x1320]
031ad100: d8feff17 b #0x31acc60
031ad104: e2cf00f0 adrp x2, #0x4bac000
031ad108: e1c600b0 adrp x1, #0x4a8a000
031ad10c: e0c600b0 adrp x0, #0x4a8a000
031ad110: e30b8052 mov w3, #0x5f
031ad114: 42603d91 add x2, x2, #0xf58
031ad118: 21b43f91 add x1, x1, #0xfed
031ad11c: 00403f91 add x0, x0, #0xfd0
031ad120: 6cffff17 b #0x31aced0
031ad124: f7060011 add w23, w23, #1
031ad128: 47ffff17 b #0x31ace44
031ad12c: 17008052 mov w23, #0
031ad130: e6ffff17 b #0x31ad0c8
031ad134: 773e40b9 ldr w23, [x19, #0x3c]
031ad138: d5feff17 b #0x31acc8c
031ad13c: 601640b9 ldr w0, [x19, #0x14]
031ad140: a1a30191 add x1, x29, #0x68
031ad144: bff70139 strb wzr, [x29, #0x7d]
031ad148: a07b00b9 str w0, [x29, #0x78]
031ad14c: 60aa4e39 ldrb w0, [x19, #0x3aa]
031ad150: a0f30139 strb w0, [x29, #0x7c]
031ad154: a0e30191 add x0, x29, #0x78
031ad158: 2deb0f94 bl #0x35a7e0c
031ad15c: 60ae4e39 ldrb w0, [x19, #0x3ab]
031ad160: e0000034 cbz w0, #0x31ad17c
031ad164: e00314aa mov x0, x20
031ad168: 6d55cf97 bl #0x258271c
031ad16c: e00314aa mov x0, x20
031ad170: 95cbd297 bl #0x265ffc4
031ad174: e00314aa mov x0, x20
031ad178: 6d55cf97 bl #0x258272c
031ad17c: a06b40b9 ldr w0, [x29, #0x68]
031ad180: 20260035 cbnz w0, #0x31ad644
031ad184: ff060031 cmn w23, #1
031ad188: 21150054 b.ne #0x31ad42c
031ad18c: 618a4229 ldp w1, w2, [x19, #0x14]
031ad190: e303192a mov w3, w25
031ad194: 60b24e39 ldrb w0, [x19, #0x3ac]
031ad198: 1a6b96d2 mov x26, #0xb358
031ad19c: 1b6896d2 mov x27, #0xb340
031ad1a0: 2fb4fe97 bl #0x315a25c
031ad1a4: e00315aa mov x0, x21
031ad1a8: 65fcff97 bl #0x31ac33c
031ad1ac: b99749f9 ldr x25, [x29, #0x1328]
031ad1b0: 600edd97 bl #0x28f0b30
031ad1b4: f80300aa mov x24, x0
031ad1b8: 630edd97 bl #0x28f0b44
031ad1bc: 611a40b9 ldr w1, [x19, #0x18]
031ad1c0: 0f6996d2 mov x15, #0xb348
031ad1c4: 106a96d2 mov x16, #0xb350
031ad1c8: 916a96d2 mov x17, #0xb354
031ad1cc: b26a96d2 mov x18, #0xb355
031ad1d0: 0e6896d2 mov x14, #0xb340
031ad1d4: e203012a mov w2, w1
031ad1d8: 21580d11 add w1, w1, #0x356
031ad1dc: a3030e8b add x3, x29, x14
031ad1e0: 180b028b add x24, x24, x2, lsl #2
031ad1e4: 0010028b add x0, x0, x2, lsl #4
031ad1e8: a2030f8b add x2, x29, x15
031ad1ec: 780000f9 str x24, [x3]
031ad1f0: 400000f9 str x0, [x2]
031ad1f4: a003108b add x0, x29, x16
031ad1f8: 010000b9 str w1, [x0]
031ad1fc: a003118b add x0, x29, x17
031ad200: e103172a mov w1, w23
031ad204: 1f000039 strb wzr, [x0]
031ad208: a003128b add x0, x29, x18
031ad20c: 1f000039 strb wzr, [x0]
031ad210: a0031a8b add x0, x29, x26
031ad214: 190000f9 str x25, [x0]
031ad218: e00314aa mov x0, x20
031ad21c: f1fdff97 bl #0x31ac9e0
031ad220: e00314aa mov x0, x20
031ad224: e2fdff97 bl #0x31ac9ac
031ad228: e00315aa mov x0, x21
031ad22c: 4dfcff97 bl #0x31ac360
031ad230: e00315aa mov x0, x21
031ad234: 42fcff97 bl #0x31ac33c
031ad238: b99749f9 ldr x25, [x29, #0x1328]
031ad23c: 470edd97 bl #0x28f0b58
031ad240: f80300aa mov x24, x0
031ad244: 4a0edd97 bl #0x28f0b6c
031ad248: 611a40b9 ldr w1, [x19, #0x18]
031ad24c: 1e6996d2 mov x30, #0xb348
031ad250: 046b96d2 mov x4, #0xb358
031ad254: a3031b8b add x3, x29, x27
031ad258: e203012a mov w2, w1
031ad25c: 21640d11 add w1, w1, #0x359
031ad260: 180b028b add x24, x24, x2, lsl #2
031ad264: 0010028b add x0, x0, x2, lsl #4
031ad268: a2031e8b add x2, x29, x30
031ad26c: 780000f9 str x24, [x3]
031ad270: 400000f9 str x0, [x2]
031ad274: 006a96d2 mov x0, #0xb350
031ad278: a003008b add x0, x29, x0
031ad27c: a26a96d2 mov x2, #0xb355
031ad280: 010000b9 str w1, [x0]
031ad284: 816a96d2 mov x1, #0xb354
031ad288: a003018b add x0, x29, x1
031ad28c: e103172a mov w1, w23
031ad290: 1f000039 strb wzr, [x0]
031ad294: a003028b add x0, x29, x2
031ad298: 1f000039 strb wzr, [x0]
031ad29c: a003048b add x0, x29, x4
031ad2a0: 190000f9 str x25, [x0]
031ad2a4: e00314aa mov x0, x20
031ad2a8: f9fdff97 bl #0x31aca8c
031ad2ac: e00314aa mov x0, x20
031ad2b0: eafdff97 bl #0x31aca58
031ad2b4: e00315aa mov x0, x21
031ad2b8: 2afcff97 bl #0x31ac360
031ad2bc: e00315aa mov x0, x21
031ad2c0: 1ffcff97 bl #0x31ac33c
031ad2c4: b39749f9 ldr x19, [x29, #0x1328]
031ad2c8: e70add97 bl #0x28efe64
031ad2cc: f70300aa mov x23, x0
031ad2d0: ea0add97 bl #0x28efe78
031ad2d4: 056896d2 mov x5, #0xb340
031ad2d8: 066996d2 mov x6, #0xb348
031ad2dc: a103058b add x1, x29, x5
031ad2e0: 076a96d2 mov x7, #0xb350
031ad2e4: 886a96d2 mov x8, #0xb354
031ad2e8: a96a96d2 mov x9, #0xb355
031ad2ec: 0a6b96d2 mov x10, #0xb358
031ad2f0: 370000f9 str x23, [x1]
031ad2f4: a103068b add x1, x29, x6
031ad2f8: 200000f9 str x0, [x1]
031ad2fc: a103078b add x1, x29, x7
031ad300: 80608052 mov w0, #0x304
031ad304: 200000b9 str w0, [x1]
031ad308: a003088b add x0, x29, x8
031ad30c: e10316aa mov x1, x22
031ad310: 1f000039 strb wzr, [x0]
031ad314: a003098b add x0, x29, x9
031ad318: 1f000039 strb wzr, [x0]
031ad31c: a0030a8b add x0, x29, x10
031ad320: 130000f9 str x19, [x0]
031ad324: e00314aa mov x0, x20
031ad328: 33008052 mov w19, #1
031ad32c: b31b01b9 str w19, [x29, #0x118]
031ad330: f5fdff97 bl #0x31acb04
031ad334: e00314aa mov x0, x20
031ad338: 6ffdff97 bl #0x31ac8f4
031ad33c: e00315aa mov x0, x21
031ad340: 08fcff97 bl #0x31ac360
031ad344: e00315aa mov x0, x21
031ad348: fdfbff97 bl #0x31ac33c
031ad34c: b79749f9 ldr x23, [x29, #0x1328]
031ad350: 330bdd97 bl #0x28f001c
031ad354: f80300aa mov x24, x0
031ad358: 360bdd97 bl #0x28f0030
031ad35c: b31b01b9 str w19, [x29, #0x118]
031ad360: 0b6896d2 mov x11, #0xb340
031ad364: 0c6996d2 mov x12, #0xb348
031ad368: a1030b8b add x1, x29, x11
031ad36c: 0d6a96d2 mov x13, #0xb350
031ad370: 8e6a96d2 mov x14, #0xb354
031ad374: af6a96d2 mov x15, #0xb355
031ad378: 106b96d2 mov x16, #0xb358
031ad37c: 136896d2 mov x19, #0xb340
031ad380: 380000f9 str x24, [x1]
031ad384: a1030c8b add x1, x29, x12
031ad388: 200000f9 str x0, [x1]
031ad38c: a1030d8b add x1, x29, x13
031ad390: e0618052 mov w0, #0x30f
031ad394: 200000b9 str w0, [x1]
031ad398: a0030e8b add x0, x29, x14
031ad39c: e10316aa mov x1, x22
031ad3a0: 1f000039 strb wzr, [x0]
031ad3a4: a0030f8b add x0, x29, x15
031ad3a8: 1f000039 strb wzr, [x0]
031ad3ac: a003108b add x0, x29, x16
031ad3b0: 170000f9 str x23, [x0]
031ad3b4: e00314aa mov x0, x20
031ad3b8: 5cfdff97 bl #0x31ac928
031ad3bc: e00314aa mov x0, x20
031ad3c0: 40fdff97 bl #0x31ac8c0
031ad3c4: e00315aa mov x0, x21
031ad3c8: 156b96d2 mov x21, #0xb358
031ad3cc: e5fbff97 bl #0x31ac360
031ad3d0: 116896d2 mov x17, #0xb340
031ad3d4: 126a96d2 mov x18, #0xb350
031ad3d8: a003118b add x0, x29, x17
031ad3dc: a103138b add x1, x29, x19
031ad3e0: 1f7c00a9 stp xzr, xzr, [x0]
031ad3e4: a003128b add x0, x29, x18
031ad3e8: 1f0000f9 str xzr, [x0]
031ad3ec: a003158b add x0, x29, x21
031ad3f0: 1f0000b9 str wzr, [x0]
031ad3f4: 20038052 mov w0, #0x19
031ad3f8: 0020a072 movk w0, #0x100, lsl #16
031ad3fc: 200000b9 str w0, [x1]
031ad400: e00314aa mov x0, x20
031ad404: ad09ce97 bl #0x252fab8
031ad408: f35341a9 ldp x19, x20, [sp, #0x10]
031ad40c: f55b42a9 ldp x21, x22, [sp, #0x20]
031ad410: f76343a9 ldp x23, x24, [sp, #0x30]
031ad414: f96b44a9 ldp x25, x26, [sp, #0x40]
031ad418: fb2b40f9 ldr x27, [sp, #0x50]
031ad41c: fd7bc6a8 ldp x29, x30, [sp], #0x60
031ad420: ff574091 add sp, sp, #0x15, lsl #12
031ad424: ff030c91 add sp, sp, #0x300
031ad428: c0035fd6 ret 
031ad42c: 618a4229 ldp w1, w2, [x19, #0x14]
031ad430: e303172a mov w3, w23
031ad434: 60b24e39 ldrb w0, [x19, #0x3ac]
031ad438: 89b3fe97 bl #0x315a25c
031ad43c: e00315aa mov x0, x21
031ad440: bffbff97 bl #0x31ac33c
031ad444: b99749f9 ldr x25, [x29, #0x1328]
031ad448: ba0ddd97 bl #0x28f0b30
031ad44c: f80300aa mov x24, x0
031ad450: bd0ddd97 bl #0x28f0b44
031ad454: 611a40b9 ldr w1, [x19, #0x18]
031ad458: 046a96d2 mov x4, #0xb350
031ad45c: 856a96d2 mov x5, #0xb354
031ad460: a66a96d2 mov x6, #0xb355
031ad464: 076b96d2 mov x7, #0xb358
031ad468: 1e6896d2 mov x30, #0xb340
031ad46c: e203012a mov w2, w1
031ad470: 21580d11 add w1, w1, #0x356
031ad474: a3031e8b add x3, x29, x30
031ad478: 180b028b add x24, x24, x2, lsl #2
031ad47c: 0010028b add x0, x0, x2, lsl #4
031ad480: 026996d2 mov x2, #0xb348
031ad484: a203028b add x2, x29, x2
031ad488: 780000f9 str x24, [x3]
031ad48c: 400000f9 str x0, [x2]
031ad490: a003048b add x0, x29, x4
031ad494: 010000b9 str w1, [x0]
031ad498: a003058b add x0, x29, x5
031ad49c: 01008012 mov w1, #-1
031ad4a0: 1f000039 strb wzr, [x0]
031ad4a4: a003068b add x0, x29, x6
031ad4a8: 1f000039 strb wzr, [x0]
031ad4ac: a003078b add x0, x29, x7
031ad4b0: 190000f9 str x25, [x0]
031ad4b4: e00314aa mov x0, x20
031ad4b8: 4afdff97 bl #0x31ac9e0
031ad4bc: e00314aa mov x0, x20
031ad4c0: 3bfdff97 bl #0x31ac9ac
031ad4c4: e00315aa mov x0, x21
031ad4c8: a6fbff97 bl #0x31ac360
031ad4cc: e00315aa mov x0, x21
031ad4d0: 9bfbff97 bl #0x31ac33c
031ad4d4: b99749f9 ldr x25, [x29, #0x1328]
031ad4d8: a00ddd97 bl #0x28f0b58
031ad4dc: f80300aa mov x24, x0
031ad4e0: a30ddd97 bl #0x28f0b6c
031ad4e4: 611a40b9 ldr w1, [x19, #0x18]
031ad4e8: 096996d2 mov x9, #0xb348
031ad4ec: 0a6a96d2 mov x10, #0xb350
031ad4f0: 8b6a96d2 mov x11, #0xb354
031ad4f4: ac6a96d2 mov x12, #0xb355
031ad4f8: 0d6b96d2 mov x13, #0xb358
031ad4fc: e203012a mov w2, w1
031ad500: 21640d11 add w1, w1, #0x359
031ad504: 086896d2 mov x8, #0xb340
031ad508: 0010028b add x0, x0, x2, lsl #4
031ad50c: 180b028b add x24, x24, x2, lsl #2
031ad510: a203098b add x2, x29, x9
031ad514: a303088b add x3, x29, x8
031ad518: 400000f9 str x0, [x2]
031ad51c: a0030a8b add x0, x29, x10
031ad520: 780000f9 str x24, [x3]
031ad524: 010000b9 str w1, [x0]
031ad528: a0030b8b add x0, x29, x11
031ad52c: 01008012 mov w1, #-1
031ad530: 1f000039 strb wzr, [x0]
031ad534: a0030c8b add x0, x29, x12
031ad538: 1f000039 strb wzr, [x0]
031ad53c: a0030d8b add x0, x29, x13
031ad540: 190000f9 str x25, [x0]
031ad544: e00314aa mov x0, x20
031ad548: 51fdff97 bl #0x31aca8c
031ad54c: e00314aa mov x0, x20
031ad550: 42fdff97 bl #0x31aca58
031ad554: e00315aa mov x0, x21
031ad558: 82fbff97 bl #0x31ac360
031ad55c: 60ce41f9 ldr x0, [x19, #0x398]
031ad560: e00600b5 cbnz x0, #0x31ad63c
031ad564: 601640b9 ldr w0, [x19, #0x14]
031ad568: e10314aa mov x1, x20
031ad56c: b72713b9 str w23, [x29, #0x1324]
031ad570: 1ba498d2 mov x27, #0xc520
031ad574: a02313b9 str w0, [x29, #0x1320]
031ad578: e00315aa mov x0, x21
031ad57c: 04f00f94 bl #0x35a958c
031ad580: a0031b8b add x0, x29, x27
031ad584: 040040b9 ldr w4, [x0]
031ad588: c4010034 cbz w4, #0x31ad5c0
031ad58c: e2cf00f0 adrp x2, #0x4bac000
031ad590: e1c600b0 adrp x1, #0x4a8a000
031ad594: e0cf00f0 adrp x0, #0x4bac000
031ad598: 42603d91 add x2, x2, #0xf58
031ad59c: 00c03691 add x0, x0, #0xdb0
031ad5a0: 21b43f91 add x1, x1, #0xfed
031ad5a4: 631c8052 mov w3, #0xe3
031ad5a8: cbe01594 bl #0x37258d4
031ad5ac: 40038052 mov w0, #0x1a
031ad5b0: 0020a072 movk w0, #0x100, lsl #16
031ad5b4: a02313b9 str w0, [x29, #0x1320]
031ad5b8: e00315aa mov x0, x21
031ad5bc: 4afeff17 b #0x31acee4
031ad5c0: 1ab697d2 mov x26, #0xbdb0
031ad5c4: a0031a8b add x0, x29, x26
031ad5c8: 000040b9 ldr w0, [x0]
031ad5cc: 1f040031 cmn w0, #1
031ad5d0: 61030054 b.ne #0x31ad63c
031ad5d4: e00316aa mov x0, x22
031ad5d8: 986682d2 mov x24, #0x1334
031ad5dc: b96682d2 mov x25, #0x1335
031ad5e0: 57fbff97 bl #0x31ac33c
031ad5e4: b39340f9 ldr x19, [x29, #0x120]
031ad5e8: 1f0add97 bl #0x28efe64
031ad5ec: f70300aa mov x23, x0
031ad5f0: 220add97 bl #0x28efe78
031ad5f4: a09709f9 str x0, [x29, #0x1328]
031ad5f8: 80608052 mov w0, #0x304
031ad5fc: a1830391 add x1, x29, #0xe0
031ad600: b79309f9 str x23, [x29, #0x1320]
031ad604: a03313b9 str w0, [x29, #0x1330]
031ad608: a003188b add x0, x29, x24
031ad60c: b39f09f9 str x19, [x29, #0x1338]
031ad610: 1f000039 strb wzr, [x0]
031ad614: a003198b add x0, x29, x25
031ad618: 1f000039 strb wzr, [x0]
031ad61c: 20008052 mov w0, #1
031ad620: a0e300b9 str w0, [x29, #0xe0]
031ad624: e00315aa mov x0, x21
031ad628: 37fdff97 bl #0x31acb04
031ad62c: e00315aa mov x0, x21
031ad630: b1fcff97 bl #0x31ac8f4
031ad634: e00316aa mov x0, x22
031ad638: 4afbff97 bl #0x31ac360
031ad63c: 20038052 mov w0, #0x19
031ad640: c4fdff17 b #0x31acd50
031ad644: 126896d2 mov x18, #0xb340
031ad648: 601640b9 ldr w0, [x19, #0x14]
031ad64c: a103128b add x1, x29, x18
031ad650: 976896d2 mov x23, #0xb344
031ad654: 200000b9 str w0, [x1]
031ad658: a103178b add x1, x29, x23
031ad65c: 603e40b9 ldr w0, [x19, #0x3c]
031ad660: 200000b9 str w0, [x1]
031ad664: e00314aa mov x0, x20
031ad668: e10316aa mov x1, x22
031ad66c: c8ef0f94 bl #0x35a958c
031ad670: a0fb52b9 ldr w0, [x29, #0x12f8]
031ad674: a0210034 cbz w0, #0x31adaa8
031ad678: 601e40b9 ldr w0, [x19, #0x1c]
031ad67c: bf7f0ca9 stp xzr, xzr, [x29, #0xc0]
031ad680: a0c300b9 str w0, [x29, #0xc0]
031ad684: 602240b9 ldr w0, [x19, #0x20]
031ad688: bf7f0da9 stp xzr, xzr, [x29, #0xd0]
031ad68c: a0c700b9 str w0, [x29, #0xc4]
031ad690: 602640b9 ldr w0, [x19, #0x24]
031ad694: a0cb00b9 str w0, [x29, #0xc8]
031ad698: 601640b9 ldr w0, [x19, #0x14]
031ad69c: a0d300b9 str w0, [x29, #0xd0]
031ad6a0: 609243b9 ldr w0, [x19, #0x390]
031ad6a4: eefaf197 bl #0x2e2c25c
031ad6a8: a0d700b9 str w0, [x29, #0xd4]
031ad6ac: a1830391 add x1, x29, #0xe0
031ad6b0: a0030391 add x0, x29, #0xc0
031ad6b4: bf630339 strb wzr, [x29, #0xd8]
031ad6b8: bf670339 strb wzr, [x29, #0xd9]
031ad6bc: 74f00f94 bl #0x35a988c
031ad6c0: a41341b9 ldr w4, [x29, #0x110]
031ad6c4: 9f400371 cmp w4, #0xd0
031ad6c8: c1040054 b.ne #0x31ad760
031ad6cc: f7cf00f0 adrp x23, #0x4bac000
031ad6d0: e1c600b0 adrp x1, #0x4a8a000
031ad6d4: f7623d91 add x23, x23, #0xf58
031ad6d8: e0cf00f0 adrp x0, #0x4bac000
031ad6dc: e20317aa mov x2, x23
031ad6e0: 21b43f91 add x1, x1, #0xfed
031ad6e4: 00103991 add x0, x0, #0xe44
031ad6e8: 23228052 mov w3, #0x111
031ad6ec: 7ae01594 bl #0x37258d4
031ad6f0: e0cf00f0 adrp x0, #0x4bac000
031ad6f4: e20317aa mov x2, x23
031ad6f8: 006c3491 add x0, x0, #0xd1b
031ad6fc: 41228052 mov w1, #0x112
031ad700: f7781294 bl #0x364badc
031ad704: a00f41b9 ldr w0, [x29, #0x10c]
031ad708: 020494d2 mov x2, #0xa020
031ad70c: 01008052 mov w1, #0
031ad710: 603a00b9 str w0, [x19, #0x38]
031ad714: a0eb40b9 ldr w0, [x29, #0xe8]
031ad718: 604200b9 str w0, [x19, #0x40]
031ad71c: e00315aa mov x0, x21
031ad720: 409e9597 bl #0x1715020 ; memset@plt
031ad724: bf4300f9 str xzr, [x29, #0x80]
031ad728: 601640b9 ldr w0, [x19, #0x14]
031ad72c: bf8b00b9 str wzr, [x29, #0x88]
031ad730: a02313b9 str w0, [x29, #0x1320]
031ad734: 609243b9 ldr w0, [x19, #0x390]
031ad738: a0020034 cbz w0, #0x31ad78c
031ad73c: 1f040071 cmp w0, #1
031ad740: 40060054 b.eq #0x31ad808
031ad744: e2cf00f0 adrp x2, #0x4bac000
031ad748: e0cf00f0 adrp x0, #0x4bac000
031ad74c: 42603d91 add x2, x2, #0xf58
031ad750: 006c3491 add x0, x0, #0xd1b
031ad754: 41268052 mov w1, #0x132
031ad758: e1781294 bl #0x364badc
031ad75c: 16000014 b #0x31ad7b4
031ad760: 24fdff34 cbz w4, #0x31ad704
031ad764: e2cf00f0 adrp x2, #0x4bac000
031ad768: e1c600b0 adrp x1, #0x4a8a000
031ad76c: e0cf00f0 adrp x0, #0x4bac000
031ad770: 42603d91 add x2, x2, #0xf58
031ad774: 21b43f91 add x1, x1, #0xfed
031ad778: 00543891 add x0, x0, #0xe15
031ad77c: c3228052 mov w3, #0x116
031ad780: 55e01594 bl #0x37258d4
031ad784: 40038052 mov w0, #0x1a
031ad788: 72fdff17 b #0x31acd50
031ad78c: 604e4779 ldrh w0, [x19, #0x3a6]
031ad790: 506582d2 mov x16, #0x132a
031ad794: a103108b add x1, x29, x16
031ad798: 716582d2 mov x17, #0x132b
031ad79c: a0532679 strh w0, [x29, #0x1328]
031ad7a0: 60a24e39 ldrb w0, [x19, #0x3a8]
031ad7a4: 20000039 strb w0, [x1]
031ad7a8: a103118b add x1, x29, x17
031ad7ac: 60a64e39 ldrb w0, [x19, #0x3a9]
031ad7b0: 20000039 strb w0, [x1]
031ad7b4: 0eed95d2 mov x14, #0xaf68
031ad7b8: a00f41b9 ldr w0, [x29, #0x10c]
031ad7bc: a1030e8b add x1, x29, x14
031ad7c0: 8fed95d2 mov x15, #0xaf6c
031ad7c4: 37078052 mov w23, #0x39
031ad7c8: 200000b9 str w0, [x1]
031ad7cc: a0030f8b add x0, x29, x15
031ad7d0: a1030291 add x1, x29, #0x80
031ad7d4: 170000b9 str w23, [x0]
031ad7d8: e00315aa mov x0, x21
031ad7dc: 9cef0f94 bl #0x35a964c
031ad7e0: a48b40b9 ldr w4, [x29, #0x88]
031ad7e4: c4010034 cbz w4, #0x31ad81c
031ad7e8: e2cf00f0 adrp x2, #0x4bac000
031ad7ec: e1c600b0 adrp x1, #0x4a8a000
031ad7f0: e0cf00f0 adrp x0, #0x4bac000
031ad7f4: 63278052 mov w3, #0x13b
031ad7f8: 42603d91 add x2, x2, #0xf58
031ad7fc: 21b43f91 add x1, x1, #0xfed
031ad800: 00e83991 add x0, x0, #0xe7a
031ad804: dfffff17 b #0x31ad780
031ad808: 60008052 mov w0, #3
031ad80c: a02713b9 str w0, [x29, #0x1324]
031ad810: 604a4779 ldrh w0, [x19, #0x3a4]
031ad814: a04313b9 str w0, [x29, #0x1340]
031ad818: e7ffff17 b #0x31ad7b4
031ad81c: b8035029 ldp w24, w0, [x29, #0x80]
031ad820: 604200b9 str w0, [x19, #0x40]
031ad824: 60ce41f9 ldr x0, [x19, #0x398]
031ad828: 783a00b9 str w24, [x19, #0x38]
031ad82c: 400600b5 cbnz x0, #0x31ad8f4
031ad830: e00314aa mov x0, x20
031ad834: 020494d2 mov x2, #0xa020
031ad838: 01008052 mov w1, #0
031ad83c: 79a243b9 ldr w25, [x19, #0x3a0]
031ad840: f89d9597 bl #0x1715020 ; memset@plt
031ad844: bf4b00f9 str xzr, [x29, #0x90]
031ad848: 0b6896d2 mov x11, #0xb340
031ad84c: 601640b9 ldr w0, [x19, #0x14]
031ad850: a1030b8b add x1, x29, x11
031ad854: 8c6896d2 mov x12, #0xb344
031ad858: 0d6996d2 mov x13, #0xb348
031ad85c: bf9b00b9 str wzr, [x29, #0x98]
031ad860: 200000b9 str w0, [x1]
031ad864: a1030c8b add x1, x29, x12
031ad868: a0008052 mov w0, #5
031ad86c: 200000b9 str w0, [x1]
031ad870: a0030d8b add x0, x29, x13
031ad874: a1430291 add x1, x29, #0x90
031ad878: 190000b9 str w25, [x0]
031ad87c: a0534091 add x0, x29, #0x14, lsl #12
031ad880: 00203e91 add x0, x0, #0xf88
031ad884: 180000b9 str w24, [x0]
031ad888: a0534091 add x0, x29, #0x14, lsl #12
031ad88c: 00303e91 add x0, x0, #0xf8c
031ad890: 170000b9 str w23, [x0]
031ad894: e00314aa mov x0, x20
031ad898: 6def0f94 bl #0x35a964c
031ad89c: a49b40b9 ldr w4, [x29, #0x98]
031ad8a0: 24020034 cbz w4, #0x31ad8e4
031ad8a4: e2cf00f0 adrp x2, #0x4bac000
031ad8a8: e1c600b0 adrp x1, #0x4a8a000
031ad8ac: e0c600b0 adrp x0, #0x4a8a000
031ad8b0: 42603d91 add x2, x2, #0xf58
031ad8b4: 00842c91 add x0, x0, #0xb21
031ad8b8: 21b43f91 add x1, x1, #0xfed
031ad8bc: c32a8052 mov w3, #0x156
031ad8c0: 05e01594 bl #0x37258d4
031ad8c4: bf7f0aa9 stp xzr, xzr, [x29, #0xa0]
031ad8c8: 40038052 mov w0, #0x1a
031ad8cc: bf5b00f9 str xzr, [x29, #0xb0]
031ad8d0: 0020a072 movk w0, #0x100, lsl #16
031ad8d4: bfbb00b9 str wzr, [x29, #0xb8]
031ad8d8: a0a300b9 str w0, [x29, #0xa0]
031ad8dc: a0830291 add x0, x29, #0xa0
031ad8e0: 81fdff17 b #0x31acee4
031ad8e4: a09340b9 ldr w0, [x29, #0x90]
031ad8e8: 603a00b9 str w0, [x19, #0x38]
031ad8ec: a09740b9 ldr w0, [x29, #0x94]
031ad8f0: 604200b9 str w0, [x19, #0x40]
031ad8f4: 774240b9 ldr w23, [x19, #0x40]
031ad8f8: 570d0034 cbz w23, #0x31adaa0
031ad8fc: fa578a92 mov x26, #-0x52c0
031ad900: f7060051 sub w23, w23, #1
031ad904: b8c30191 add x24, x29, #0x70
031ad908: b9430291 add x25, x29, #0x90
031ad90c: daffbff2 movk x26, #0xfffe, lsl #16
031ad910: 970cf837 tbnz w23, #0x1f, #0x31adaa0
031ad914: 603a40b9 ldr w0, [x19, #0x38]
031ad918: e10318aa mov x1, x24
031ad91c: a05f1229 stp w0, w23, [x29, #0x90]
031ad920: e00319aa mov x0, x25
031ad924: 9aef0f94 bl #0x35a978c
031ad928: 601640b9 ldr w0, [x19, #0x14]
031ad92c: e10314aa mov x1, x20
031ad930: a0a300b9 str w0, [x29, #0xa0]
031ad934: a07340b9 ldr w0, [x29, #0x70]
031ad938: a0a700b9 str w0, [x29, #0xa4]
031ad93c: a0574091 add x0, x29, #0x15, lsl #12
031ad940: 00800d91 add x0, x0, #0x360
031ad944: 00001a8b add x0, x0, x26
031ad948: 11ef0f94 bl #0x35a958c
031ad94c: 0aa498d2 mov x10, #0xc520
031ad950: a0030a8b add x0, x29, x10
031ad954: 000040b9 ldr w0, [x0]
031ad958: 000a0035 cbnz w0, #0x31ada98
031ad95c: 096896d2 mov x9, #0xb340
031ad960: a003098b add x0, x29, x9
031ad964: 030040b9 ldr w3, [x0]
031ad968: 618a4229 ldp w1, w2, [x19, #0x14]
031ad96c: 1a6996d2 mov x26, #0xb348
031ad970: 60b24e39 ldrb w0, [x19, #0x3ac]
031ad974: 1b6a96d2 mov x27, #0xb350
031ad978: 196896d2 mov x25, #0xb340
031ad97c: 38b2fe97 bl #0x315a25c
031ad980: e00315aa mov x0, x21
031ad984: 6efaff97 bl #0x31ac33c
031ad988: b89749f9 ldr x24, [x29, #0x1328]
031ad98c: 690cdd97 bl #0x28f0b30
031ad990: f70300aa mov x23, x0
031ad994: 6c0cdd97 bl #0x28f0b44
031ad998: 611a40b9 ldr w1, [x19, #0x18]
031ad99c: 9e6a96d2 mov x30, #0xb354
031ad9a0: a303198b add x3, x29, x25
031ad9a4: e203012a mov w2, w1
031ad9a8: 21580d11 add w1, w1, #0x356
031ad9ac: f70a028b add x23, x23, x2, lsl #2
031ad9b0: 0010028b add x0, x0, x2, lsl #4
031ad9b4: a2031a8b add x2, x29, x26
031ad9b8: 770000f9 str x23, [x3]
031ad9bc: 400000f9 str x0, [x2]
031ad9c0: a0031b8b add x0, x29, x27
031ad9c4: 010000b9 str w1, [x0]
031ad9c8: a0031e8b add x0, x29, x30
031ad9cc: 016b96d2 mov x1, #0xb358
031ad9d0: 1f000039 strb wzr, [x0]
031ad9d4: a06a96d2 mov x0, #0xb355
031ad9d8: a003008b add x0, x29, x0
031ad9dc: 1f000039 strb wzr, [x0]
031ad9e0: a003018b add x0, x29, x1
031ad9e4: 01008012 mov w1, #-1
031ad9e8: 180000f9 str x24, [x0]
031ad9ec: e00314aa mov x0, x20
031ad9f0: fcfbff97 bl #0x31ac9e0
031ad9f4: e00314aa mov x0, x20
031ad9f8: edfbff97 bl #0x31ac9ac
031ad9fc: e00315aa mov x0, x21
031ada00: 58faff97 bl #0x31ac360
031ada04: e00315aa mov x0, x21
031ada08: 4dfaff97 bl #0x31ac33c
031ada0c: b89749f9 ldr x24, [x29, #0x1328]
031ada10: 520cdd97 bl #0x28f0b58
031ada14: f70300aa mov x23, x0
031ada18: 550cdd97 bl #0x28f0b6c
031ada1c: 611a40b9 ldr w1, [x19, #0x18]
031ada20: 026896d2 mov x2, #0xb340
031ada24: a303028b add x3, x29, x2
031ada28: 046996d2 mov x4, #0xb348
031ada2c: 056a96d2 mov x5, #0xb350
031ada30: 866a96d2 mov x6, #0xb354
031ada34: e203012a mov w2, w1
031ada38: 21640d11 add w1, w1, #0x359
031ada3c: a76a96d2 mov x7, #0xb355
031ada40: 086b96d2 mov x8, #0xb358
031ada44: f70a028b add x23, x23, x2, lsl #2
031ada48: 0010028b add x0, x0, x2, lsl #4
031ada4c: a203048b add x2, x29, x4
031ada50: 770000f9 str x23, [x3]
031ada54: 400000f9 str x0, [x2]
031ada58: a003058b add x0, x29, x5
031ada5c: 010000b9 str w1, [x0]
031ada60: a003068b add x0, x29, x6
031ada64: 01008012 mov w1, #-1
031ada68: 1f000039 strb wzr, [x0]
031ada6c: a003078b add x0, x29, x7
031ada70: 1f000039 strb wzr, [x0]
031ada74: a003088b add x0, x29, x8
031ada78: 180000f9 str x24, [x0]
031ada7c: e00314aa mov x0, x20
031ada80: 03fcff97 bl #0x31aca8c
031ada84: e00314aa mov x0, x20
031ada88: f4fbff97 bl #0x31aca58
031ada8c: e00315aa mov x0, x21
031ada90: 34faff97 bl #0x31ac360
031ada94: fdfcff17 b #0x31ace88
031ada98: f7060051 sub w23, w23, #1
031ada9c: 9dffff17 b #0x31ad910
031adaa0: 03008012 mov w3, #-1
031adaa4: b1ffff17 b #0x31ad968
031adaa8: 633e40b9 ldr w3, [x19, #0x3c]
031adaac: afffff17 b #0x31ad968
031adab0: e20317aa mov x2, x23
031adab4: e00313aa mov x0, x19
031adab8: 7fea1594 bl #0x37284b4
031adabc: 37fdff17 b #0x31acf98
031adac0: 414501b0 adrp x1, #0x5a56000
031adac4: 216041f9 ldr x1, [x1, #0x2c0]
031adac8: 21400091 add x1, x1, #0x10
031adacc: 010000f9 str x1, [x0]
031adad0: c1a4fe17 b #0x3156dd4
