031edfe8: ff032cd1 sub sp, sp, #0xb00
031edfec: fd7bbaa9 stp x29, x30, [sp, #-0x60]!
031edff0: fd030091 mov x29, sp
031edff4: f35301a9 stp x19, x20, [sp, #0x10]
031edff8: f30300aa mov x19, x0
031edffc: 002040b9 ldr w0, [x0, #0x20]
031ee000: b403098b add x20, x29, x9
031ee004: f76303a9 stp x23, x24, [sp, #0x30]
031ee008: b7030391 add x23, x29, #0xc0
031ee00c: b8c30291 add x24, x29, #0xb0
031ee010: a0b300b9 str w0, [x29, #0xb0]
031ee014: e10317aa mov x1, x23
031ee018: e00318aa mov x0, x24
031ee01c: f55b02a9 stp x21, x22, [sp, #0x20]
031ee020: f96b04a9 stp x25, x26, [sp, #0x40]
031ee024: fb7305a9 stp x27, x28, [sp, #0x50]
031ee028: b46700f9 str x20, [x29, #0xc8]
031ee02c: f8e40e94 bl #0x35a740c
031ee030: a4c340b9 ldr w4, [x29, #0xc0]
031ee034: a4030034 cbz w4, #0x31ee0a8
031ee038: 42ce0090 adrp x2, #0x4bb6000
031ee03c: e1c40090 adrp x1, #0x4a8a000
031ee040: 40ce0090 adrp x0, #0x4bb6000
031ee044: 42a01191 add x2, x2, #0x468
031ee048: 00400f91 add x0, x0, #0x3d0
031ee04c: 21b43f91 add x1, x1, #0xfed
031ee050: 03048052 mov w3, #0x20
031ee054: 20de1494 bl #0x37258d4
031ee058: bf8f00f9 str xzr, [x29, #0x118]
031ee05c: a0230491 add x0, x29, #0x108
031ee060: bf2301b9 str wzr, [x29, #0x120]
031ee064: 1f7c00a9 stp xzr, xzr, [x0]
031ee068: 80408052 mov w0, #0x204
031ee06c: 0020a072 movk w0, #0x100, lsl #16
031ee070: a00b01b9 str w0, [x29, #0x108]
031ee074: a0230491 add x0, x29, #0x108
031ee078: 9006cd97 bl #0x252fab8
031ee07c: 600a40f9 ldr x0, [x19, #0x10]
031ee080: 7ee2f397 bl #0x2ee6a78
031ee084: f35341a9 ldp x19, x20, [sp, #0x10]
031ee088: f55b42a9 ldp x21, x22, [sp, #0x20]
031ee08c: f76343a9 ldp x23, x24, [sp, #0x30]
031ee090: f96b44a9 ldp x25, x26, [sp, #0x40]
031ee094: fb7345a9 ldp x27, x28, [sp, #0x50]
031ee098: fd7bc6a8 ldp x29, x30, [sp], #0x60
031ee09c: ffe34191 add sp, sp, #0x78, lsl #12
031ee0a0: ff032c91 add sp, sp, #0xb00
031ee0a4: c0035fd6 ret 
031ee0a8: a0c740b9 ldr w0, [x29, #0xc4]
031ee0ac: b5430391 add x21, x29, #0xd0
031ee0b0: fc0314aa mov x28, x20
031ee0b4: b6230491 add x22, x29, #0x108
031ee0b8: a08700b9 str w0, [x29, #0x84]
031ee0bc: e00315aa mov x0, x21
031ee0c0: 1b008052 mov w27, #0
031ee0c4: 39008052 mov w25, #1
031ee0c8: 77ffff97 bl #0x31edea4
031ee0cc: a0e34191 add x0, x29, #0x78, lsl #12
031ee0d0: 63f20091 add x3, x19, #0x3c
031ee0d4: 00802d91 add x0, x0, #0xb60
031ee0d8: a04700f9 str x0, [x29, #0x88]
031ee0dc: 800b40b9 ldr w0, [x28, #8]
031ee0e0: 600000b9 str w0, [x3]
031ee0e4: 80034039 ldrb w0, [x28]
031ee0e8: a0080034 cbz w0, #0x31ee1fc
031ee0ec: a06f40f9 ldr x0, [x29, #0xd8]
031ee0f0: e80316aa mov x8, x22
031ee0f4: a33f00f9 str x3, [x29, #0x78]
031ee0f8: 57ffff97 bl #0x31ede54
031ee0fc: b9730439 strb w25, [x29, #0x11c]
031ee100: 00448052 mov w0, #0x220
031ee104: 82034039 ldrb w2, [x28]
031ee108: 7a7fa09b umull x26, w27, w0
031ee10c: a08740f9 ldr x0, [x29, #0x108]
031ee110: 02683a38 strb w2, [x0, x26]
031ee114: e00316aa mov x0, x22
031ee118: 77ffff97 bl #0x31edef4
031ee11c: a06f40f9 ldr x0, [x29, #0xd8]
031ee120: e80316aa mov x8, x22
031ee124: 4cffff97 bl #0x31ede54
031ee128: b9730439 strb w25, [x29, #0x11c]
031ee12c: a08740f9 ldr x0, [x29, #0x108]
031ee130: 82074039 ldrb w2, [x28, #1]
031ee134: 00001a8b add x0, x0, x26
031ee138: 02040039 strb w2, [x0, #1]
031ee13c: e00316aa mov x0, x22
031ee140: 6dffff97 bl #0x31edef4
031ee144: a06f40f9 ldr x0, [x29, #0xd8]
031ee148: e80316aa mov x8, x22
031ee14c: 42ffff97 bl #0x31ede54
031ee150: b9730439 strb w25, [x29, #0x11c]
031ee154: a08740f9 ldr x0, [x29, #0x108]
031ee158: 820740b9 ldr w2, [x28, #4]
031ee15c: 00001a8b add x0, x0, x26
031ee160: 020400b9 str w2, [x0, #4]
031ee164: e00316aa mov x0, x22
031ee168: 63ffff97 bl #0x31edef4
031ee16c: a06f40f9 ldr x0, [x29, #0xd8]
031ee170: e80316aa mov x8, x22
031ee174: 38ffff97 bl #0x31ede54
031ee178: b9730439 strb w25, [x29, #0x11c]
031ee17c: a08740f9 ldr x0, [x29, #0x108]
031ee180: 820b40b9 ldr w2, [x28, #8]
031ee184: 00001a8b add x0, x0, x26
031ee188: 020800b9 str w2, [x0, #8]
031ee18c: e00316aa mov x0, x22
031ee190: 59ffff97 bl #0x31edef4
031ee194: a33f40f9 ldr x3, [x29, #0x78]
031ee198: 020080d2 mov x2, #0
031ee19c: a06f40f9 ldr x0, [x29, #0xd8]
031ee1a0: e80316aa mov x8, x22
031ee1a4: a33700f9 str x3, [x29, #0x68]
031ee1a8: a23f00f9 str x2, [x29, #0x78]
031ee1ac: 2affff97 bl #0x31ede54
031ee1b0: b9730439 strb w25, [x29, #0x11c]
031ee1b4: a23f40f9 ldr x2, [x29, #0x78]
031ee1b8: a08740f9 ldr x0, [x29, #0x108]
031ee1bc: 8403028b add x4, x28, x2
031ee1c0: 00001a8b add x0, x0, x26
031ee1c4: a43b00f9 str x4, [x29, #0x70]
031ee1c8: 00c0228b add x0, x0, w2, sxtw
031ee1cc: 85304039 ldrb w5, [x4, #0xc]
031ee1d0: 05300039 strb w5, [x0, #0xc]
031ee1d4: e00316aa mov x0, x22
031ee1d8: 47ffff97 bl #0x31edef4
031ee1dc: a39346a9 ldp x3, x4, [x29, #0x68]
031ee1e0: 80304039 ldrb w0, [x4, #0xc]
031ee1e4: a0000034 cbz w0, #0x31ee1f8
031ee1e8: a23f40f9 ldr x2, [x29, #0x78]
031ee1ec: 42040091 add x2, x2, #1
031ee1f0: 5f3400f1 cmp x2, #0xd
031ee1f4: 41fdff54 b.ne #0x31ee19c
031ee1f8: 7b070011 add w27, w27, #1
031ee1fc: a04740f9 ldr x0, [x29, #0x88]
031ee200: 9c830891 add x28, x28, #0x220
031ee204: 63200091 add x3, x3, #8
031ee208: 9f0300eb cmp x28, x0
031ee20c: 81f6ff54 b.ne #0x31ee0dc
031ee210: b6230491 add x22, x29, #0x108
031ee214: e00316aa mov x0, x22
031ee218: 4151ce97 bl #0x258271c
031ee21c: 611a40b9 ldr w1, [x19, #0x18]
031ee220: e00316aa mov x0, x22
031ee224: a2c740b9 ldr w2, [x29, #0xc4]
031ee228: 6228d497 bl #0x26f83b0
031ee22c: e00316aa mov x0, x22
031ee230: 3f51ce97 bl #0x258272c
031ee234: e00315aa mov x0, x21
031ee238: 24ffff97 bl #0x31edec8
031ee23c: 602a40b9 ldr w0, [x19, #0x28]
031ee240: 00080051 sub w0, w0, #2
031ee244: 1f040071 cmp w0, #1
031ee248: a8120054 b.hi #0x31ee49c
031ee24c: 602640b9 ldr w0, [x19, #0x24]
031ee250: e10318aa mov x1, x24
031ee254: b45f00f9 str x20, [x29, #0xb8]
031ee258: a0a300b9 str w0, [x29, #0xa0]
031ee25c: a0830291 add x0, x29, #0xa0
031ee260: 6be40e94 bl #0x35a740c
031ee264: a4b340b9 ldr w4, [x29, #0xb0]
031ee268: 44020034 cbz w4, #0x31ee2b0
031ee26c: 42ce0090 adrp x2, #0x4bb6000
031ee270: e1c40090 adrp x1, #0x4a8a000
031ee274: 40ce0090 adrp x0, #0x4bb6000
031ee278: 42a01191 add x2, x2, #0x468
031ee27c: 00400f91 add x0, x0, #0x3d0
031ee280: 21b43f91 add x1, x1, #0xfed
031ee284: a3098052 mov w3, #0x4d
031ee288: 93dd1494 bl #0x37258d4
031ee28c: bf8f00f9 str xzr, [x29, #0x118]
031ee290: a0230491 add x0, x29, #0x108
031ee294: bf2301b9 str wzr, [x29, #0x120]
031ee298: 1f7c00a9 stp xzr, xzr, [x0]
031ee29c: 80408052 mov w0, #0x204
031ee2a0: 0020a072 movk w0, #0x100, lsl #16
031ee2a4: a00b01b9 str w0, [x29, #0x108]
031ee2a8: e00316aa mov x0, x22
031ee2ac: 73ffff17 b #0x31ee078
031ee2b0: bb630291 add x27, x29, #0x98
031ee2b4: 190080d2 mov x25, #0
031ee2b8: e0031baa mov x0, x27
031ee2bc: cbe3f397 bl #0x2ee71e8
031ee2c0: e00317aa mov x0, x23
031ee2c4: f8feff97 bl #0x31edea4
031ee2c8: 275c82d2 mov x7, #0x12e1
031ee2cc: 885c82d2 mov x8, #0x12e4
031ee2d0: a003078b add x0, x29, x7
031ee2d4: bc03088b add x28, x29, x8
031ee2d8: a04700f9 str x0, [x29, #0x88]
031ee2dc: d8feff97 bl #0x31ede3c
031ee2e0: 206b6038 ldrb w0, [x25, x0]
031ee2e4: 80070034 cbz w0, #0x31ee3d4
031ee2e8: 82220091 add x2, x20, #8
031ee2ec: 1a0080d2 mov x26, #0
031ee2f0: 40805f38 ldurb w0, [x2, #-8]
031ee2f4: 80120034 cbz w0, #0x31ee544
031ee2f8: a23f00f9 str x2, [x29, #0x78]
031ee2fc: d0feff97 bl #0x31ede3c
031ee300: a23f40f9 ldr x2, [x29, #0x78]
031ee304: 2003008b add x0, x25, x0
031ee308: 010840b9 ldr w1, [x0, #8]
031ee30c: 400040b9 ldr w0, [x2]
031ee310: 3f00006b cmp w1, w0
031ee314: 81110054 b.ne #0x31ee544
031ee318: c9feff97 bl #0x31ede3c
031ee31c: 2003008b add x0, x25, x0
031ee320: 03300091 add x3, x0, #0xc
031ee324: a33f00f9 str x3, [x29, #0x78]
031ee328: c5feff97 bl #0x31ede3c
031ee32c: 2003008b add x0, x25, x0
031ee330: 00300091 add x0, x0, #0xc
031ee334: 0fa19497 bl #0x1716770 ; strlen@plt
031ee338: 820180d2 mov x2, #0xc
031ee33c: 01448052 mov w1, #0x220
031ee340: a33f40f9 ldr x3, [x29, #0x78]
031ee344: 410ba19b umaddl x1, w26, w1, x2
031ee348: e20300aa mov x2, x0
031ee34c: e00303aa mov x0, x3
031ee350: 8102018b add x1, x20, x1
031ee354: b3a69497 bl #0x1717e20 ; strncmp@plt
031ee358: 200d0035 cbnz w0, #0x31ee4fc
031ee35c: b8feff97 bl #0x31ede3c
031ee360: 2003008b add x0, x25, x0
031ee364: 00044039 ldrb w0, [x0, #1]
031ee368: 60030034 cbz w0, #0x31ee3d4
031ee36c: a06740f9 ldr x0, [x29, #0xc8]
031ee370: e80316aa mov x8, x22
031ee374: b8feff97 bl #0x31ede54
031ee378: 004480d2 mov x0, #0x220
031ee37c: 21008052 mov w1, #1
031ee380: 5a7f009b mul x26, x26, x0
031ee384: a04740f9 ldr x0, [x29, #0x88]
031ee388: a1730439 strb w1, [x29, #0x11c]
031ee38c: a17b00b9 str w1, [x29, #0x78]
031ee390: 02687a38 ldrb w2, [x0, x26]
031ee394: a08740f9 ldr x0, [x29, #0x108]
031ee398: 0000198b add x0, x0, x25
031ee39c: 02040039 strb w2, [x0, #1]
031ee3a0: e00316aa mov x0, x22
031ee3a4: d4feff97 bl #0x31edef4
031ee3a8: a06740f9 ldr x0, [x29, #0xc8]
031ee3ac: e80316aa mov x8, x22
031ee3b0: a9feff97 bl #0x31ede54
031ee3b4: a17b40b9 ldr w1, [x29, #0x78]
031ee3b8: a08740f9 ldr x0, [x29, #0x108]
031ee3bc: a1730439 strb w1, [x29, #0x11c]
031ee3c0: 816b7ab8 ldr w1, [x28, x26]
031ee3c4: 0000198b add x0, x0, x25
031ee3c8: 010400b9 str w1, [x0, #4]
031ee3cc: e00316aa mov x0, x22
031ee3d0: c9feff97 bl #0x31edef4
031ee3d4: 39830891 add x25, x25, #0x220
031ee3d8: 20df41d1 sub x0, x25, #0x77, lsl #12
031ee3dc: 000022f1 subs x0, x0, #0x880
031ee3e0: e1f7ff54 b.ne #0x31ee2dc
031ee3e4: e00316aa mov x0, x22
031ee3e8: cd50ce97 bl #0x258271c
031ee3ec: 611e40b9 ldr w1, [x19, #0x1c]
031ee3f0: e00316aa mov x0, x22
031ee3f4: a2b740b9 ldr w2, [x29, #0xb4]
031ee3f8: ee27d497 bl #0x26f83b0
031ee3fc: e00316aa mov x0, x22
031ee400: cb50ce97 bl #0x258272c
031ee404: a0b740b9 ldr w0, [x29, #0xb4]
031ee408: 20040035 cbnz w0, #0x31ee48c
031ee40c: e00315aa mov x0, x21
031ee410: a5feff97 bl #0x31edea4
031ee414: b96f40f9 ldr x25, [x29, #0xd8]
031ee418: f30ddc97 bl #0x28f1be4
031ee41c: fa0300aa mov x26, x0
031ee420: f60ddc97 bl #0x28f1bf8
031ee424: 020440f9 ldr x2, [x0, #8]
031ee428: a1788052 mov w1, #0x3c5
031ee42c: bf730439 strb wzr, [x29, #0x11c]
031ee430: bf770439 strb wzr, [x29, #0x11d]
031ee434: a3a30291 add x3, x29, #0xa8
031ee438: bfab00b9 str wzr, [x29, #0xa8]
031ee43c: 840080d2 mov x4, #4
031ee440: ba8310a9 stp x26, x0, [x29, #0x108]
031ee444: a11b01b9 str w1, [x29, #0x118]
031ee448: b99300f9 str x25, [x29, #0x120]
031ee44c: 820a00b4 cbz x2, #0x31ee59c
031ee450: e00319aa mov x0, x25
031ee454: 18e81494 bl #0x37284b4
031ee458: a08b40f9 ldr x0, [x29, #0x110]
031ee45c: 000440f9 ldr x0, [x0, #8]
031ee460: 1f0000b9 str wzr, [x0]
031ee464: 20008052 mov w0, #1
031ee468: a0770439 strb w0, [x29, #0x11d]
031ee46c: a08740f9 ldr x0, [x29, #0x108]
031ee470: 1f0000b9 str wzr, [x0]
031ee474: 20008052 mov w0, #1
031ee478: a0730439 strb w0, [x29, #0x11c]
031ee47c: e00316aa mov x0, x22
031ee480: b1feff97 bl #0x31edf44
031ee484: e00315aa mov x0, x21
031ee488: 90feff97 bl #0x31edec8
031ee48c: e00317aa mov x0, x23
031ee490: 8efeff97 bl #0x31edec8
031ee494: e0031baa mov x0, x27
031ee498: 8be2f397 bl #0x2ee6ec4
031ee49c: e00314aa mov x0, x20
031ee4a0: 52e3f397 bl #0x2ee71e8
031ee4a4: d00ddc97 bl #0x28f1be4
031ee4a8: 190040b9 ldr w25, [x0]
031ee4ac: e00314aa mov x0, x20
031ee4b0: 85e2f397 bl #0x2ee6ec4
031ee4b4: 3f070071 cmp w25, #1
031ee4b8: 21deff54 b.ne #0x31ee07c
031ee4bc: 602240b9 ldr w0, [x19, #0x20]
031ee4c0: e10316aa mov x1, x22
031ee4c4: a0b300b9 str w0, [x29, #0xb0]
031ee4c8: e00318aa mov x0, x24
031ee4cc: e0e30e94 bl #0x35a744c
031ee4d0: a40b41b9 ldr w4, [x29, #0x108]
031ee4d4: c4060034 cbz w4, #0x31ee5ac
031ee4d8: 42ce0090 adrp x2, #0x4bb6000
031ee4dc: e1c40090 adrp x1, #0x4a8a000
031ee4e0: 40ce0090 adrp x0, #0x4bb6000
031ee4e4: 42a01191 add x2, x2, #0x468
031ee4e8: 21b43f91 add x1, x1, #0xfed
031ee4ec: 00f00f91 add x0, x0, #0x3fc
031ee4f0: 03148052 mov w3, #0xa0
031ee4f4: f8dc1494 bl #0x37258d4
031ee4f8: e1feff17 b #0x31ee07c
031ee4fc: a06740f9 ldr x0, [x29, #0xc8]
031ee500: e80316aa mov x8, x22
031ee504: 3a008052 mov w26, #1
031ee508: 53feff97 bl #0x31ede54
031ee50c: ba730439 strb w26, [x29, #0x11c]
031ee510: a08740f9 ldr x0, [x29, #0x108]
031ee514: 0000198b add x0, x0, x25
031ee518: 1f040039 strb wzr, [x0, #1]
031ee51c: e00316aa mov x0, x22
031ee520: 75feff97 bl #0x31edef4
031ee524: a06740f9 ldr x0, [x29, #0xc8]
031ee528: e80316aa mov x8, x22
031ee52c: 4afeff97 bl #0x31ede54
031ee530: ba730439 strb w26, [x29, #0x11c]
031ee534: a08740f9 ldr x0, [x29, #0x108]
031ee538: 81008052 mov w1, #4
031ee53c: 0000198b add x0, x0, x25
031ee540: a2ffff17 b #0x31ee3c8
031ee544: 5a070011 add w26, w26, #1
031ee548: 42800891 add x2, x2, #0x220
031ee54c: 5f130e71 cmp w26, #0x384
031ee550: 01edff54 b.ne #0x31ee2f0
031ee554: a06740f9 ldr x0, [x29, #0xc8]
031ee558: e80316aa mov x8, x22
031ee55c: 3a008052 mov w26, #1
031ee560: 3dfeff97 bl #0x31ede54
031ee564: ba730439 strb w26, [x29, #0x11c]
031ee568: a08740f9 ldr x0, [x29, #0x108]
031ee56c: 0000198b add x0, x0, x25
031ee570: 1f040039 strb wzr, [x0, #1]
031ee574: e00316aa mov x0, x22
031ee578: 5ffeff97 bl #0x31edef4
031ee57c: a06740f9 ldr x0, [x29, #0xc8]
031ee580: e80316aa mov x8, x22
031ee584: 34feff97 bl #0x31ede54
031ee588: ba730439 strb w26, [x29, #0x11c]
031ee58c: a08740f9 ldr x0, [x29, #0x108]
031ee590: a1008052 mov w1, #5
031ee594: 0000198b add x0, x0, x25
031ee598: 8cffff17 b #0x31ee3c8
031ee59c: e2031aaa mov x2, x26
031ee5a0: e00319aa mov x0, x25
031ee5a4: c4e71494 bl #0x37284b4
031ee5a8: b1ffff17 b #0x31ee46c
031ee5ac: b9a30291 add x25, x29, #0xa8
031ee5b0: 1a0080d2 mov x26, #0
031ee5b4: e00319aa mov x0, x25
031ee5b8: 0ce3f397 bl #0x2ee71e8
031ee5bc: e00315aa mov x0, x21
031ee5c0: 39feff97 bl #0x31edea4
031ee5c4: 1efeff97 bl #0x31ede3c
031ee5c8: 406b6038 ldrb w0, [x26, x0]
031ee5cc: 40090034 cbz w0, #0x31ee6f4
031ee5d0: 1bfeff97 bl #0x31ede3c
031ee5d4: 4003008b add x0, x26, x0
031ee5d8: 010840b9 ldr w1, [x0, #8]
031ee5dc: a01f41b9 ldr w0, [x29, #0x11c]
031ee5e0: 3f00006b cmp w1, w0
031ee5e4: 81080054 b.ne #0x31ee6f4
031ee5e8: bb6f40f9 ldr x27, [x29, #0xd8]
031ee5ec: fc81dc97 bl #0x290eddc
031ee5f0: fc0300aa mov x28, x0
031ee5f4: ff81dc97 bl #0x290edf0
031ee5f8: 855e82d2 mov x5, #0x12f4
031ee5fc: a65e82d2 mov x6, #0x12f5
031ee600: a203058b add x2, x29, x5
031ee604: 61e48252 mov w1, #0x1723
031ee608: ba1f41b9 ldr w26, [x29, #0x11c]
031ee60c: 840080d2 mov x4, #4
031ee610: e30317aa mov x3, x23
031ee614: 5f000039 strb wzr, [x2]
031ee618: a203068b add x2, x29, x6
031ee61c: 5f000039 strb wzr, [x2]
031ee620: 020440f9 ldr x2, [x0, #8]
031ee624: bac300b9 str w26, [x29, #0xc0]
031ee628: bc7309f9 str x28, [x29, #0x12e0]
031ee62c: a07709f9 str x0, [x29, #0x12e8]
031ee630: a1f312b9 str w1, [x29, #0x12f0]
031ee634: bb7f09f9 str x27, [x29, #0x12f8]
031ee638: 620500b4 cbz x2, #0x31ee6e4
031ee63c: e0031baa mov x0, x27
031ee640: 9de71494 bl #0x37284b4
031ee644: a07749f9 ldr x0, [x29, #0x12e8]
031ee648: a45e82d2 mov x4, #0x12f5
031ee64c: a103048b add x1, x29, x4
031ee650: 000440f9 ldr x0, [x0, #8]
031ee654: 1a0000b9 str w26, [x0]
031ee658: 20008052 mov w0, #1
031ee65c: 20000039 strb w0, [x1]
031ee660: a07349f9 ldr x0, [x29, #0x12e0]
031ee664: 835e82d2 mov x3, #0x12f4
031ee668: a103038b add x1, x29, x3
031ee66c: 1a0000b9 str w26, [x0]
031ee670: 20008052 mov w0, #1
031ee674: 20000039 strb w0, [x1]
031ee678: e00314aa mov x0, x20
031ee67c: 3ffeff97 bl #0x31edf78
031ee680: e00315aa mov x0, x21
031ee684: 3b008052 mov w27, #1
031ee688: 10feff97 bl #0x31edec8
031ee68c: e00319aa mov x0, x25
031ee690: 0de2f397 bl #0x2ee6ec4
031ee694: bfa30339 strb wzr, [x29, #0xe8]
031ee698: 602240b9 ldr w0, [x19, #0x20]
031ee69c: e10314aa mov x1, x20
031ee6a0: bfa70339 strb wzr, [x29, #0xe9]
031ee6a4: bb031a29 stp w27, w0, [x29, #0xd0]
031ee6a8: a0e300b9 str w0, [x29, #0xe0]
031ee6ac: 60008052 mov w0, #3
031ee6b0: a0e700b9 str w0, [x29, #0xe4]
031ee6b4: e00315aa mov x0, x21
031ee6b8: 75ec0e94 bl #0x35a988c
031ee6bc: a41353b9 ldr w4, [x29, #0x1310]
031ee6c0: 44020034 cbz w4, #0x31ee708
031ee6c4: 42ce0090 adrp x2, #0x4bb6000
031ee6c8: e1c40090 adrp x1, #0x4a8a000
031ee6cc: 40ce0090 adrp x0, #0x4bb6000
031ee6d0: 83188052 mov w3, #0xc4
031ee6d4: 42a01191 add x2, x2, #0x468
031ee6d8: 21b43f91 add x1, x1, #0xfed
031ee6dc: 00e81091 add x0, x0, #0x43a
031ee6e0: 85ffff17 b #0x31ee4f4
031ee6e4: e2031caa mov x2, x28
031ee6e8: e0031baa mov x0, x27
031ee6ec: 72e71494 bl #0x37284b4
031ee6f0: dcffff17 b #0x31ee660
031ee6f4: 5a830891 add x26, x26, #0x220
031ee6f8: 40df41d1 sub x0, x26, #0x77, lsl #12
031ee6fc: 000022f1 subs x0, x0, #0x880
031ee700: 21f6ff54 b.ne #0x31ee5c4
031ee704: dfffff17 b #0x31ee680
031ee708: a00f53b9 ldr w0, [x29, #0x130c]
031ee70c: 602e00b9 str w0, [x19, #0x2c]
031ee710: e00317aa mov x0, x23
031ee714: e4fdff97 bl #0x31edea4
031ee718: bc6740f9 ldr x28, [x29, #0xc8]
031ee71c: e3fadb97 bl #0x28ed2a8
031ee720: a04700f9 str x0, [x29, #0x88]
031ee724: e6fadb97 bl #0x28ed2bc
031ee728: ba0f53b9 ldr w26, [x29, #0x130c]
031ee72c: a24740f9 ldr x2, [x29, #0x88]
031ee730: 61358052 mov w1, #0x1ab
031ee734: bf730439 strb wzr, [x29, #0x11c]
031ee738: 840080d2 mov x4, #4
031ee73c: a28310a9 stp x2, x0, [x29, #0x108]
031ee740: e30318aa mov x3, x24
031ee744: 000040f9 ldr x0, [x0]
031ee748: bf770439 strb wzr, [x29, #0x11d]
031ee74c: a11b01b9 str w1, [x29, #0x118]
031ee750: bc9300f9 str x28, [x29, #0x120]
031ee754: bab300b9 str w26, [x29, #0xb0]
031ee758: c00a00b4 cbz x0, #0x31ee8b0
031ee75c: e20300aa mov x2, x0
031ee760: e0031caa mov x0, x28
031ee764: 54e71494 bl #0x37284b4
031ee768: a08b40f9 ldr x0, [x29, #0x110]
031ee76c: 000040f9 ldr x0, [x0]
031ee770: 1a0000b9 str w26, [x0]
031ee774: bb770439 strb w27, [x29, #0x11d]
031ee778: a08740f9 ldr x0, [x29, #0x108]
031ee77c: 1a0000b9 str w26, [x0]
031ee780: 20008052 mov w0, #1
031ee784: a0730439 strb w0, [x29, #0x11c]
031ee788: e00316aa mov x0, x22
031ee78c: 08feff97 bl #0x31edfac
031ee790: e00317aa mov x0, x23
031ee794: cdfdff97 bl #0x31edec8
031ee798: a0eb52b9 ldr w0, [x29, #0x12e8]
031ee79c: 020494d2 mov x2, #0xa020
031ee7a0: 01008052 mov w1, #0
031ee7a4: 603a00b9 str w0, [x19, #0x38]
031ee7a8: e00314aa mov x0, x20
031ee7ac: 1d9a9497 bl #0x1715020 ; memset@plt
031ee7b0: bf5b00f9 str xzr, [x29, #0xb0]
031ee7b4: 602240b9 ldr w0, [x19, #0x20]
031ee7b8: 01e595d2 mov x1, #0xaf28
031ee7bc: a103018b add x1, x29, x1
031ee7c0: 82e595d2 mov x2, #0xaf2c
031ee7c4: a0e312b9 str w0, [x29, #0x12e0]
031ee7c8: 80008052 mov w0, #4
031ee7cc: bfbb00b9 str wzr, [x29, #0xb8]
031ee7d0: a0e712b9 str w0, [x29, #0x12e4]
031ee7d4: 602e40b9 ldr w0, [x19, #0x2c]
031ee7d8: 200000b9 str w0, [x1]
031ee7dc: a103028b add x1, x29, x2
031ee7e0: 20078052 mov w0, #0x39
031ee7e4: 200000b9 str w0, [x1]
031ee7e8: e00314aa mov x0, x20
031ee7ec: e10318aa mov x1, x24
031ee7f0: 97eb0e94 bl #0x35a964c
031ee7f4: a0bb40b9 ldr w0, [x29, #0xb8]
031ee7f8: 60c4ff35 cbnz w0, #0x31ee084
031ee7fc: a0b740b9 ldr w0, [x29, #0xb4]
031ee800: fc579192 mov x28, #-0x8ac0
031ee804: bb630291 add x27, x29, #0x98
031ee808: 1a008052 mov w26, #0
031ee80c: a08b00b9 str w0, [x29, #0x88]
031ee810: a0430291 add x0, x29, #0x90
031ee814: 03008052 mov w3, #0
031ee818: 18008052 mov w24, #0
031ee81c: 1cffbff2 movk x28, #0xfff8, lsl #16
031ee820: a03f00f9 str x0, [x29, #0x78]
031ee824: a08b40b9 ldr w0, [x29, #0x88]
031ee828: a37300b9 str w3, [x29, #0x70]
031ee82c: 5f03006b cmp w26, w0
031ee830: a0080054 b.eq #0x31ee944
031ee834: 602240b9 ldr w0, [x19, #0x20]
031ee838: e10315aa mov x1, x21
031ee83c: bf7f0da9 stp xzr, xzr, [x29, #0xd0]
031ee840: a0c300b9 str w0, [x29, #0xc0]
031ee844: a0b340b9 ldr w0, [x29, #0xb0]
031ee848: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
031ee84c: a0c700b9 str w0, [x29, #0xc4]
031ee850: 00008012 mov w0, #-1
031ee854: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
031ee858: a0d300b9 str w0, [x29, #0xd0]
031ee85c: e00317aa mov x0, x23
031ee860: bacb00b9 str w26, [x29, #0xc8]
031ee864: b66f00f9 str x22, [x29, #0xd8]
031ee868: bf8300f9 str xzr, [x29, #0x100]
031ee86c: 18eb0e94 bl #0x35a94cc
031ee870: a0e340b9 ldr w0, [x29, #0xe0]
031ee874: 80c0ff35 cbnz w0, #0x31ee084
031ee878: a37340b9 ldr w3, [x29, #0x70]
031ee87c: 01008052 mov w1, #0
031ee880: a56f40f9 ldr x5, [x29, #0xd8]
031ee884: 60ce238b add x0, x19, w3, sxtw #3
031ee888: 00f00091 add x0, x0, #0x3c
031ee88c: 2400030b add w4, w1, w3
031ee890: 9f0c0e71 cmp w4, #0x383
031ee894: 48010054 b.hi #0x31ee8bc
031ee898: 078440b8 ldr w7, [x0], #8
031ee89c: a6804079 ldrh w6, [x5, #0x40]
031ee8a0: ff00066b cmp w7, w6
031ee8a4: c0000054 b.eq #0x31ee8bc
031ee8a8: 21040011 add w1, w1, #1
031ee8ac: f8ffff17 b #0x31ee88c
031ee8b0: e0031caa mov x0, x28
031ee8b4: 00e71494 bl #0x37284b4
031ee8b8: b0ffff17 b #0x31ee778
031ee8bc: a0b740b9 ldr w0, [x29, #0xb4]
031ee8c0: 00040051 sub w0, w0, #1
031ee8c4: 5f03006b cmp w26, w0
031ee8c8: a2030054 b.hs #0x31ee93c
031ee8cc: 40070011 add w0, w26, #1
031ee8d0: a13f40f9 ldr x1, [x29, #0x78]
031ee8d4: a09f00b9 str w0, [x29, #0x9c]
031ee8d8: a0b340b9 ldr w0, [x29, #0xb0]
031ee8dc: a47300b9 str w4, [x29, #0x70]
031ee8e0: a09b00b9 str w0, [x29, #0x98]
031ee8e4: e0031baa mov x0, x27
031ee8e8: a9eb0e94 bl #0x35a978c
031ee8ec: a09340b9 ldr w0, [x29, #0x90]
031ee8f0: e10319aa mov x1, x25
031ee8f4: a0a700b9 str w0, [x29, #0xa4]
031ee8f8: 602e40b9 ldr w0, [x19, #0x2c]
031ee8fc: a0a300b9 str w0, [x29, #0xa0]
031ee900: a0e34191 add x0, x29, #0x78, lsl #12
031ee904: 00802d91 add x0, x0, #0xb60
031ee908: 00001c8b add x0, x0, x28
031ee90c: 90eb0e94 bl #0x35a974c
031ee910: a47340b9 ldr w4, [x29, #0x70]
031ee914: a0ab40b9 ldr w0, [x29, #0xa8]
031ee918: 61ce248b add x1, x19, w4, sxtw #3
031ee91c: 83040011 add w3, w4, #1
031ee920: 1800184b sub w24, w0, w24
031ee924: 7f0c0e71 cmp w3, #0x383
031ee928: 384000b9 str w24, [x1, #0x40]
031ee92c: cc000054 b.gt #0x31ee944
031ee930: 5a070011 add w26, w26, #1
031ee934: f803002a mov w24, w0
031ee938: bbffff17 b #0x31ee824
031ee93c: 603a40b9 ldr w0, [x19, #0x38]
031ee940: f6ffff17 b #0x31ee918
031ee944: e00315aa mov x0, x21
031ee948: 180080d2 mov x24, #0
031ee94c: 1c008052 mov w28, #0
031ee950: 9a0780d2 mov x26, #0x3c
031ee954: 3b008052 mov w27, #1
031ee958: 24e2f397 bl #0x2ee71e8
031ee95c: e00316aa mov x0, x22
031ee960: 51fdff97 bl #0x31edea4
031ee964: a08740b9 ldr w0, [x29, #0x84]
031ee968: 1f00186b cmp w0, w24
031ee96c: ad040054 b.le #0x31eea00
031ee970: 004480d2 mov x0, #0x220
031ee974: 44cf3c8b add x4, x26, w28, sxtw #3
031ee978: 6402048b add x4, x19, x4
031ee97c: f9031c2a mov w25, w28
031ee980: 177f009b mul x23, x24, x0
031ee984: 20031c4b sub w0, w25, w28
031ee988: 3f0f0e71 cmp w25, #0x383
031ee98c: a43f00f9 str x4, [x29, #0x78]
031ee990: a08b00b9 str w0, [x29, #0x88]
031ee994: a8020054 b.hi #0x31ee9e8
031ee998: 29fdff97 bl #0x31ede3c
031ee99c: e002008b add x0, x23, x0
031ee9a0: a43f40f9 ldr x4, [x29, #0x78]
031ee9a4: 010840b9 ldr w1, [x0, #8]
031ee9a8: 808440b8 ldr w0, [x4], #8
031ee9ac: 3f00006b cmp w1, w0
031ee9b0: 21030054 b.ne #0x31eea14
031ee9b4: a08b40f9 ldr x0, [x29, #0x110]
031ee9b8: e80314aa mov x8, x20
031ee9bc: 26fdff97 bl #0x31ede54
031ee9c0: 805e82d2 mov x0, #0x12f4
031ee9c4: 624e398b add x2, x19, w25, uxtw #3
031ee9c8: a003008b add x0, x29, x0
031ee9cc: 1b000039 strb w27, [x0]
031ee9d0: a07349f9 ldr x0, [x29, #0x12e0]
031ee9d4: 1700178b add x23, x0, x23
031ee9d8: 404040b9 ldr w0, [x2, #0x40]
031ee9dc: e01e00b9 str w0, [x23, #0x1c]
031ee9e0: e00314aa mov x0, x20
031ee9e4: 44fdff97 bl #0x31edef4
031ee9e8: a08b40b9 ldr w0, [x29, #0x88]
031ee9ec: 18070091 add x24, x24, #1
031ee9f0: 9c03000b add w28, w28, w0
031ee9f4: 9c070011 add w28, w28, #1
031ee9f8: 9f0f0e71 cmp w28, #0x383
031ee9fc: 4dfbff54 b.le #0x31ee964
031eea00: e00316aa mov x0, x22
031eea04: 31fdff97 bl #0x31edec8
031eea08: e00315aa mov x0, x21
031eea0c: 2ee1f397 bl #0x2ee6ec4
031eea10: 9bfdff17 b #0x31ee07c
031eea14: 39070011 add w25, w25, #1
031eea18: dbffff17 b #0x31ee984
031eea1c: 014301f0 adrp x1, #0x5a51000
031eea20: 210440f9 ldr x1, [x1, #8]
031eea24: 21400091 add x1, x1, #0x10
031eea28: 010000f9 str x1, [x0]
031eea2c: eaa0fd17 b #0x3156dd4
