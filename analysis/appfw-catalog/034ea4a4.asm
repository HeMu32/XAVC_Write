034ea4a4: ff430ad1 sub sp, sp, #0x290
034ea4a8: fd7bbaa9 stp x29, x30, [sp, #-0x60]!
034ea4ac: fd030091 mov x29, sp
034ea4b0: f35301a9 stp x19, x20, [sp, #0x10]
034ea4b4: f30300aa mov x19, x0
034ea4b8: 002040b9 ldr w0, [x0, #0x20]
034ea4bc: f55b02a9 stp x21, x22, [sp, #0x20]
034ea4c0: f76303a9 stp x23, x24, [sp, #0x30]
034ea4c4: f96b04a9 stp x25, x26, [sp, #0x40]
034ea4c8: fb7305a9 stp x27, x28, [sp, #0x50]
034ea4cc: 80000034 cbz w0, #0x34ea4dc
034ea4d0: 602640b9 ldr w0, [x19, #0x24]
034ea4d4: 1a008052 mov w26, #0
034ea4d8: 802d0034 cbz w0, #0x34eaa88
034ea4dc: 00008012 mov w0, #-1
034ea4e0: bf430179 strh wzr, [x29, #0xa0]
034ea4e4: bf8b0239 strb wzr, [x29, #0xa2]
034ea4e8: a0031829 stp w0, w0, [x29, #0xc0]
034ea4ec: a0cb00b9 str w0, [x29, #0xc8]
034ea4f0: 602a40b9 ldr w0, [x19, #0x28]
034ea4f4: bf7f1629 stp wzr, wzr, [x29, #0xb0]
034ea4f8: 1f040071 cmp w0, #1
034ea4fc: bfbb00b9 str wzr, [x29, #0xb8]
034ea500: 68060054 b.hi #0x34ea5cc
034ea504: e0050054 b.eq #0x34ea5c0
034ea508: 601640b9 ldr w0, [x19, #0x14]
034ea50c: a0b300b9 str w0, [x29, #0xb0]
034ea510: 20008052 mov w0, #1
034ea514: e003002a mov w0, w0
034ea518: b4630491 add x20, x29, #0x118
034ea51c: a04b00f9 str x0, [x29, #0x90]
034ea520: 80522591 add x0, x20, #0x954
034ea524: 150080d2 mov x21, #0
034ea528: 37008052 mov w23, #1
034ea52c: a04700f9 str x0, [x29, #0x88]
034ea530: a04b40f9 ldr x0, [x29, #0x90]
034ea534: bf0200eb cmp x21, x0
034ea538: 60120054 b.eq #0x34ea784
034ea53c: a0030391 add x0, x29, #0xc0
034ea540: 1a008012 mov w26, #-1
034ea544: a04f00f9 str x0, [x29, #0x98]
034ea548: b8830391 add x24, x29, #0xe0
034ea54c: e10314aa mov x1, x20
034ea550: 24008052 mov w4, #1
034ea554: 1a7835b8 str w26, [x0, x21, lsl #2]
034ea558: a0c30291 add x0, x29, #0xb0
034ea55c: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
034ea560: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
034ea564: 197875b8 ldr w25, [x0, x21, lsl #2]
034ea568: e00318aa mov x0, x24
034ea56c: a4e70339 strb w4, [x29, #0xf9]
034ea570: a48300b9 str w4, [x29, #0x80]
034ea574: a4e300b9 str w4, [x29, #0xe0]
034ea578: b9e700b9 str w25, [x29, #0xe4]
034ea57c: b9f300b9 str w25, [x29, #0xf0]
034ea580: c3fc0294 bl #0x35a988c
034ea584: a04b41b9 ldr w0, [x29, #0x148]
034ea588: b62341b9 ldr w22, [x29, #0x120]
034ea58c: 1f000071 cmp w0, #0
034ea590: a48340b9 ldr w4, [x29, #0x80]
034ea594: e3079f1a cset w3, ne
034ea598: df020071 cmp w22, #0
034ea59c: e0179f1a cset w0, eq
034ea5a0: 7c00002a orr w28, w3, w0
034ea5a4: 7c030034 cbz w28, #0x34ea610
034ea5a8: 603240b9 ldr w0, [x19, #0x30]
034ea5ac: 1f000071 cmp w0, #0
034ea5b0: fc029f1a csel w28, w23, wzr, eq
034ea5b4: b5060091 add x21, x21, #1
034ea5b8: f7031c2a mov w23, w28
034ea5bc: ddffff17 b #0x34ea530
034ea5c0: 611a40b9 ldr w1, [x19, #0x18]
034ea5c4: a1b300b9 str w1, [x29, #0xb0]
034ea5c8: d3ffff17 b #0x34ea514
034ea5cc: 00080051 sub w0, w0, #2
034ea5d0: 1f040071 cmp w0, #1
034ea5d4: e8000054 b.hi #0x34ea5f0
034ea5d8: 601640b9 ldr w0, [x19, #0x14]
034ea5dc: a0b300b9 str w0, [x29, #0xb0]
034ea5e0: 601a40b9 ldr w0, [x19, #0x18]
034ea5e4: a0b700b9 str w0, [x29, #0xb4]
034ea5e8: 40008052 mov w0, #2
034ea5ec: caffff17 b #0x34ea514
034ea5f0: 62b700d0 adrp x2, #0x4bd8000
034ea5f4: 60b700d0 adrp x0, #0x4bd8000
034ea5f8: 00f43a91 add x0, x0, #0xebd
034ea5fc: 42c03b91 add x2, x2, #0xef0
034ea600: 21098052 mov w1, #0x49
034ea604: 36850594 bl #0x364badc
034ea608: 00008052 mov w0, #0
034ea60c: c2ffff17 b #0x34ea514
034ea610: e10318aa mov x1, x24
034ea614: e00314aa mov x0, x20
034ea618: bb4741b9 ldr w27, [x29, #0x144]
034ea61c: d6060051 sub w22, w22, #1
034ea620: a48300b9 str w4, [x29, #0x80]
034ea624: bb1b01b9 str w27, [x29, #0x118]
034ea628: bf1f01b9 str wzr, [x29, #0x11c]
034ea62c: bf2301b9 str wzr, [x29, #0x120]
034ea630: e7fc0294 bl #0x35a99cc
034ea634: e00314aa mov x0, x20
034ea638: 023b82d2 mov x2, #0x11d8
034ea63c: 01008052 mov w1, #0
034ea640: b96f1a29 stp w25, w27, [x29, #0xd0]
034ea644: b6db00b9 str w22, [x29, #0xd8]
034ea648: 76aa8897 bl #0x1715020 ; memset@plt
034ea64c: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
034ea650: a0030491 add x0, x29, #0x100
034ea654: bae300b9 str w26, [x29, #0xe0]
034ea658: ba430391 add x26, x29, #0xd0
034ea65c: e10318aa mov x1, x24
034ea660: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
034ea664: 1f7c00a9 stp xzr, xzr, [x0]
034ea668: e0031aaa mov x0, x26
034ea66c: b47700f9 str x20, [x29, #0xe8]
034ea670: bf8b00f9 str xzr, [x29, #0x110]
034ea674: 96fb0294 bl #0x35a94cc
034ea678: a0f340b9 ldr w0, [x29, #0xf0]
034ea67c: 60f9ff35 cbnz w0, #0x34ea5a8
034ea680: a07740f9 ldr x0, [x29, #0xe8]
034ea684: a48340b9 ldr w4, [x29, #0x80]
034ea688: 010040b9 ldr w1, [x0]
034ea68c: e1f8ff35 cbnz w1, #0x34ea5a8
034ea690: a24f40f9 ldr x2, [x29, #0x98]
034ea694: 25338052 mov w5, #0x199
034ea698: a1e340b9 ldr w1, [x29, #0xe0]
034ea69c: 417835b8 str w1, [x2, x21, lsl #2]
034ea6a0: 02c84339 ldrb w2, [x0, #0xf2]
034ea6a4: 01cc4339 ldrb w1, [x0, #0xf3]
034ea6a8: 00d04339 ldrb w0, [x0, #0xf4]
034ea6ac: a5671c29 stp w5, w25, [x29, #0xe0]
034ea6b0: b67f1d29 stp w22, wzr, [x29, #0xe8]
034ea6b4: 62040034 cbz w2, #0x34ea740
034ea6b8: a4f300b9 str w4, [x29, #0xf0]
034ea6bc: 00008012 mov w0, #-1
034ea6c0: 025b81d2 mov x2, #0xad8
034ea6c4: 01008052 mov w1, #0
034ea6c8: bfff1f29 stp wzr, wzr, [x29, #0xfc]
034ea6cc: bb831e29 stp w27, w0, [x29, #0xf4]
034ea6d0: e00314aa mov x0, x20
034ea6d4: 53aa8897 bl #0x1715020 ; memset@plt
034ea6d8: e00318aa mov x0, x24
034ea6dc: e10314aa mov x1, x20
034ea6e0: 9bf30294 bl #0x35a754c
034ea6e4: a03341b9 ldr w0, [x29, #0x130]
034ea6e8: 80040035 cbnz w0, #0x34ea778
034ea6ec: 60b700d0 adrp x0, #0x4bd8000
034ea6f0: a14740f9 ldr x1, [x29, #0x88]
034ea6f4: 00c03b91 add x0, x0, #0xef0
034ea6f8: ad8af297 bl #0x318d1ac
034ea6fc: a01f41b9 ldr w0, [x29, #0x11c]
034ea700: a0000034 cbz w0, #0x34ea714
034ea704: a0ab00b9 str w0, [x29, #0xa8]
034ea708: e1031aaa mov x1, x26
034ea70c: a0a30291 add x0, x29, #0xa8
034ea710: 47f20294 bl #0x35a702c
034ea714: a05f4ab9 ldr w0, [x29, #0xa5c]
034ea718: 1f100071 cmp w0, #4
034ea71c: e1000054 b.ne #0x34ea738
034ea720: a0434ab9 ldr w0, [x29, #0xa40]
034ea724: a0000034 cbz w0, #0x34ea738
034ea728: a0ab00b9 str w0, [x29, #0xa8]
034ea72c: e1031aaa mov x1, x26
034ea730: a0a30291 add x0, x29, #0xa8
034ea734: 3ef20294 bl #0x35a702c
034ea738: fc03172a mov w28, w23
034ea73c: 9effff17 b #0x34ea5b4
034ea740: 80000034 cbz w0, #0x34ea750
034ea744: 80008052 mov w0, #4
034ea748: a0f300b9 str w0, [x29, #0xf0]
034ea74c: dcffff17 b #0x34ea6bc
034ea750: 61000034 cbz w1, #0x34ea75c
034ea754: 40008052 mov w0, #2
034ea758: fcffff17 b #0x34ea748
034ea75c: 62b700d0 adrp x2, #0x4bd8000
034ea760: 60b700d0 adrp x0, #0x4bd8000
034ea764: 42c03b91 add x2, x2, #0xef0
034ea768: 00f43a91 add x0, x0, #0xebd
034ea76c: e1148052 mov w1, #0xa7
034ea770: db840594 bl #0x364badc
034ea774: d2ffff17 b #0x34ea6bc
034ea778: 1ffc0271 cmp w0, #0xbf
034ea77c: c1f1ff54 b.ne #0x34ea5b4
034ea780: eeffff17 b #0x34ea738
034ea784: 1a008052 mov w26, #0
034ea788: 17180034 cbz w23, #0x34eaa88
034ea78c: a0030391 add x0, x29, #0xc0
034ea790: 140080d2 mov x20, #0
034ea794: a04300f9 str x0, [x29, #0x80]
034ea798: a0c30291 add x0, x29, #0xb0
034ea79c: a03f00f9 str x0, [x29, #0x78]
034ea7a0: a0430391 add x0, x29, #0xd0
034ea7a4: a04f00f9 str x0, [x29, #0x98]
034ea7a8: 9f0215eb cmp x20, x21
034ea7ac: a1020054 b.ne #0x34ea800
034ea7b0: b6830291 add x22, x29, #0xa0
034ea7b4: b7c30291 add x23, x29, #0xb0
034ea7b8: 130080d2 mov x19, #0
034ea7bc: 00008052 mov w0, #0
034ea7c0: 7f0214eb cmp x19, x20
034ea7c4: e0140054 b.eq #0x34eaa60
034ea7c8: 756a7638 ldrb w21, [x19, x22]
034ea7cc: 75010034 cbz w21, #0x34ea7f8
034ea7d0: 000280d2 mov x0, #0x10
034ea7d4: 568fe697 bl #0x2e8e52c
034ea7d8: a2308052 mov w2, #0x185
034ea7dc: 020000b9 str w2, [x0]
034ea7e0: e27a73b8 ldr w2, [x23, x19, lsl #2]
034ea7e4: 020400b9 str w2, [x0, #4]
034ea7e8: a2178052 mov w2, #0xbd
034ea7ec: 020800b9 str w2, [x0, #8]
034ea7f0: 0b91e697 bl #0x2e8ec1c
034ea7f4: e003152a mov w0, w21
034ea7f8: 73060091 add x19, x19, #1
034ea7fc: f1ffff17 b #0x34ea7c0
034ea800: a04340f9 ldr x0, [x29, #0x80]
034ea804: 1b7874b8 ldr w27, [x0, x20, lsl #2]
034ea808: 7f070031 cmn w27, #1
034ea80c: a00b0054 b.eq #0x34ea980
034ea810: a03f40f9 ldr x0, [x29, #0x78]
034ea814: b8630491 add x24, x29, #0x118
034ea818: b6830391 add x22, x29, #0xe0
034ea81c: e10318aa mov x1, x24
034ea820: 3c008052 mov w28, #1
034ea824: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
034ea828: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
034ea82c: 197874b8 ldr w25, [x0, x20, lsl #2]
034ea830: e00316aa mov x0, x22
034ea834: bce70339 strb w28, [x29, #0xf9]
034ea838: bc671c29 stp w28, w25, [x29, #0xe0]
034ea83c: b9f300b9 str w25, [x29, #0xf0]
034ea840: 13fc0294 bl #0x35a988c
034ea844: a04b41b9 ldr w0, [x29, #0x148]
034ea848: 1f000071 cmp w0, #0
034ea84c: a02341b9 ldr w0, [x29, #0x120]
034ea850: 0408407a ccmp w0, #0, #4, eq
034ea854: 60090054 b.eq #0x34ea980
034ea858: a04741b9 ldr w0, [x29, #0x144]
034ea85c: a08b00b9 str w0, [x29, #0x88]
034ea860: a0a30291 add x0, x29, #0xa8
034ea864: a04b00f9 str x0, [x29, #0x90]
034ea868: 60f2e797 bl #0x2ee71e8
034ea86c: e00316aa mov x0, x22
034ea870: 5ef2e797 bl #0x2ee71e8
034ea874: bf7700f9 str xzr, [x29, #0xe8]
034ea878: 151fd097 bl #0x28f24cc
034ea87c: 050040b9 ldr w5, [x0]
034ea880: a67740f9 ldr x6, [x29, #0xe8]
034ea884: a56700b9 str w5, [x29, #0x64]
034ea888: a63700f9 str x6, [x29, #0x68]
034ea88c: 101fd097 bl #0x28f24cc
034ea890: a03b00f9 str x0, [x29, #0x70]
034ea894: 131fd097 bl #0x28f24e0
034ea898: bfb30439 strb wzr, [x29, #0x12c]
034ea89c: a68b46a9 ldp x6, x2, [x29, #0x68]
034ea8a0: 21898052 mov w1, #0x449
034ea8a4: a56740b9 ldr w5, [x29, #0x64]
034ea8a8: 840080d2 mov x4, #4
034ea8ac: a28311a9 stp x2, x0, [x29, #0x118]
034ea8b0: 000440f9 ldr x0, [x0, #8]
034ea8b4: a5001c0b add w5, w5, w28
034ea8b8: bfb70439 strb wzr, [x29, #0x12d]
034ea8bc: a57300b9 str w5, [x29, #0x70]
034ea8c0: a12b01b9 str w1, [x29, #0x128]
034ea8c4: a69b00f9 str x6, [x29, #0x130]
034ea8c8: a5d300b9 str w5, [x29, #0xd0]
034ea8cc: a34f40f9 ldr x3, [x29, #0x98]
034ea8d0: c00500b4 cbz x0, #0x34ea988
034ea8d4: e20300aa mov x2, x0
034ea8d8: e00306aa mov x0, x6
034ea8dc: f6f60894 bl #0x37284b4
034ea8e0: a09340f9 ldr x0, [x29, #0x120]
034ea8e4: a57340b9 ldr w5, [x29, #0x70]
034ea8e8: 000440f9 ldr x0, [x0, #8]
034ea8ec: 050000b9 str w5, [x0]
034ea8f0: bcb70439 strb w28, [x29, #0x12d]
034ea8f4: a08f40f9 ldr x0, [x29, #0x118]
034ea8f8: 050000b9 str w5, [x0]
034ea8fc: 20008052 mov w0, #1
034ea900: a0b30439 strb w0, [x29, #0x12c]
034ea904: e00318aa mov x0, x24
034ea908: d9feff97 bl #0x34ea46c
034ea90c: a07740f9 ldr x0, [x29, #0xe8]
034ea910: 400000b4 cbz x0, #0x34ea918
034ea914: c8eb0894 bl #0x3725834
034ea918: e00316aa mov x0, x22
034ea91c: 3c008052 mov w28, #1
034ea920: 69f1e797 bl #0x2ee6ec4
034ea924: a04b40f9 ldr x0, [x29, #0x90]
034ea928: 67f1e797 bl #0x2ee6ec4
034ea92c: bf7300f9 str xzr, [x29, #0xe0]
034ea930: a2030491 add x2, x29, #0x100
034ea934: 20338052 mov w0, #0x199
034ea938: bfeb00b9 str wzr, [x29, #0xe8]
034ea93c: e10316aa mov x1, x22
034ea940: 40700429 stp w0, w28, [x2, #0x20]
034ea944: e00318aa mov x0, x24
034ea948: 596c0329 stp w25, w27, [x2, #0x18]
034ea94c: c0f30294 bl #0x35a784c
034ea950: a0e340b9 ldr w0, [x29, #0xe0]
034ea954: 80000035 cbnz w0, #0x34ea964
034ea958: a0eb40b9 ldr w0, [x29, #0xe8]
034ea95c: 1f080071 cmp w0, #2
034ea960: c1010054 b.ne #0x34ea998
034ea964: 000280d2 mov x0, #0x10
034ea968: f18ee697 bl #0x2e8e52c
034ea96c: a2308052 mov w2, #0x185
034ea970: 02640029 stp w2, w25, [x0]
034ea974: a2178052 mov w2, #0xbd
034ea978: 020800b9 str w2, [x0, #8]
034ea97c: a890e697 bl #0x2e8ec1c
034ea980: 94060091 add x20, x20, #1
034ea984: 89ffff17 b #0x34ea7a8
034ea988: e00306aa mov x0, x6
034ea98c: caf60894 bl #0x37284b4
034ea990: a57340b9 ldr w5, [x29, #0x70]
034ea994: d8ffff17 b #0x34ea8f4
034ea998: e00318aa mov x0, x24
034ea99c: 13f2e797 bl #0x2ee71e8
034ea9a0: b90fd197 bl #0x292e884
034ea9a4: 000040b9 ldr w0, [x0]
034ea9a8: 1f040071 cmp w0, #1
034ea9ac: e1179f1a cset w1, eq
034ea9b0: a19300b9 str w1, [x29, #0x90]
034ea9b4: df08d097 bl #0x28ecd30
034ea9b8: a19340b9 ldr w1, [x29, #0x90]
034ea9bc: 020e80d2 mov x2, #0x70
034ea9c0: e103012a mov w1, w1
034ea9c4: 217c029b mul x1, x1, x2
034ea9c8: 016861b8 ldr w1, [x0, x1]
034ea9cc: a17300b9 str w1, [x29, #0x70]
034ea9d0: a30fd197 bl #0x292e85c
034ea9d4: 020040b9 ldr w2, [x0]
034ea9d8: e00318aa mov x0, x24
034ea9dc: a29300b9 str w2, [x29, #0x90]
034ea9e0: 39f1e797 bl #0x2ee6ec4
034ea9e4: a29340b9 ldr w2, [x29, #0x90]
034ea9e8: a17340b9 ldr w1, [x29, #0x70]
034ea9ec: 7f03026b cmp w27, w2
034ea9f0: 2003417a ccmp w25, w1, #0, eq
034ea9f4: 81000054 b.ne #0x34eaa04
034ea9f8: a0830291 add x0, x29, #0xa0
034ea9fc: 9c6a2038 strb w28, [x20, x0]
034eaa00: e0ffff17 b #0x34ea980
034eaa04: 601240b9 ldr w0, [x19, #0x10]
034eaa08: a14f40f9 ldr x1, [x29, #0x98]
034eaa0c: a02701b9 str w0, [x29, #0x124]
034eaa10: a08b40b9 ldr w0, [x29, #0x88]
034eaa14: bfd300b9 str wzr, [x29, #0xd0]
034eaa18: a02301b9 str w0, [x29, #0x120]
034eaa1c: e00318aa mov x0, x24
034eaa20: b91b01b9 str w25, [x29, #0x118]
034eaa24: bb1f01b9 str w27, [x29, #0x11c]
034eaa28: bf9700f9 str xzr, [x29, #0x128]
034eaa2c: 28f60294 bl #0x35a82cc
034eaa30: 60d24039 ldrb w0, [x19, #0x34]
034eaa34: e0000034 cbz w0, #0x34eaa50
034eaa38: e00316aa mov x0, x22
034eaa3c: 385fc297 bl #0x258271c
034eaa40: e00316aa mov x0, x22
034eaa44: 60d5c597 bl #0x265ffc4
034eaa48: e00316aa mov x0, x22
034eaa4c: 385fc297 bl #0x258272c
034eaa50: a0d340b9 ldr w0, [x29, #0xd0]
034eaa54: 1f000071 cmp w0, #0
034eaa58: 5a13971a csel w26, w26, w23, ne
034eaa5c: c9ffff17 b #0x34ea980
034eaa60: 40010034 cbz w0, #0x34eaa88
034eaa64: a0630491 add x0, x29, #0x118
034eaa68: bf9700f9 str xzr, [x29, #0x128]
034eaa6c: bf3301b9 str wzr, [x29, #0x130]
034eaa70: 1f7c00a9 stp xzr, xzr, [x0]
034eaa74: 004e8052 mov w0, #0x270
034eaa78: 0020a072 movk w0, #0x100, lsl #16
034eaa7c: a01b01b9 str w0, [x29, #0x118]
034eaa80: a0630491 add x0, x29, #0x118
034eaa84: 0d14c197 bl #0x252fab8
034eaa88: a0630491 add x0, x29, #0x118
034eaa8c: bf9700f9 str xzr, [x29, #0x128]
034eaa90: bf3301b9 str wzr, [x29, #0x130]
034eaa94: 1f7c00a9 stp xzr, xzr, [x0]
034eaa98: 60208052 mov w0, #0x103
034eaa9c: 5a000035 cbnz w26, #0x34eaaa4
034eaaa0: 80208052 mov w0, #0x104
034eaaa4: 0020a072 movk w0, #0x100, lsl #16
034eaaa8: a01b01b9 str w0, [x29, #0x118]
034eaaac: a0630491 add x0, x29, #0x118
034eaab0: 0214c197 bl #0x252fab8
034eaab4: f35341a9 ldp x19, x20, [sp, #0x10]
034eaab8: f55b42a9 ldp x21, x22, [sp, #0x20]
034eaabc: f76343a9 ldp x23, x24, [sp, #0x30]
034eaac0: f96b44a9 ldp x25, x26, [sp, #0x40]
034eaac4: fb7345a9 ldp x27, x28, [sp, #0x50]
034eaac8: fd7bc6a8 ldp x29, x30, [sp], #0x60
034eaacc: ff074091 add sp, sp, #1, lsl #12
034eaad0: ff430a91 add sp, sp, #0x290
034eaad4: c0035fd6 ret 
034eaad8: c1280190 adrp x1, #0x5a02000
034eaadc: 211846f9 ldr x1, [x1, #0xc30]
034eaae0: 21400091 add x1, x1, #0x10
034eaae4: 010000f9 str x1, [x0]
034eaae8: bbb0f117 b #0x3156dd4
