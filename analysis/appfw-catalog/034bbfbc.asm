034bbfbc: ffc30ad1 sub sp, sp, #0x2b0
034bbfc0: fd7bbba9 stp x29, x30, [sp, #-0x50]!
034bbfc4: fd030091 mov x29, sp
034bbfc8: f96b04a9 stp x25, x26, [sp, #0x40]
034bbfcc: 1a5c82d2 mov x26, #0x12e0
034bbfd0: f35301a9 stp x19, x20, [sp, #0x10]
034bbfd4: b3031a8b add x19, x29, x26
034bbfd8: f55b02a9 stp x21, x22, [sp, #0x20]
034bbfdc: b5630391 add x21, x29, #0xd8
034bbfe0: e10313aa mov x1, x19
034bbfe4: f40300aa mov x20, x0
034bbfe8: e00315aa mov x0, x21
034bbfec: f76303a9 stp x23, x24, [sp, #0x30]
034bbff0: b8830291 add x24, x29, #0xa0
034bbff4: b6af0394 bl #0x35a7ecc
034bbff8: e00315aa mov x0, x21
034bbffc: 2cffff97 bl #0x34bbcac
034bc000: b67340f9 ldr x22, [x29, #0xe0]
034bc004: 06d0d097 bl #0x28f001c
034bc008: f70300aa mov x23, x0
034bc00c: 09d0d097 bl #0x28f0030
034bc010: a07709f9 str x0, [x29, #0x12e8]
034bc014: e0618052 mov w0, #0x30f
034bc018: 9e5e82d2 mov x30, #0x12f4
034bc01c: e10318aa mov x1, x24
034bc020: b77309f9 str x23, [x29, #0x12e0]
034bc024: a0f312b9 str w0, [x29, #0x12f0]
034bc028: a0031e8b add x0, x29, x30
034bc02c: b67f09f9 str x22, [x29, #0x12f8]
034bc030: 36078052 mov w22, #0x39
034bc034: bfa300b9 str wzr, [x29, #0xa0]
034bc038: 97018052 mov w23, #0xc
034bc03c: 1f000039 strb wzr, [x0]
034bc040: a05e82d2 mov x0, #0x12f5
034bc044: a003008b add x0, x29, x0
034bc048: 1f000039 strb wzr, [x0]
034bc04c: e00313aa mov x0, x19
034bc050: 38ffff97 bl #0x34bbd30
034bc054: e00313aa mov x0, x19
034bc058: 29ffff97 bl #0x34bbcfc
034bc05c: e00315aa mov x0, x21
034bc060: 1cffff97 bl #0x34bbcd0
034bc064: e10313aa mov x1, x19
034bc068: e00315aa mov x0, x21
034bc06c: 38b30394 bl #0x35a8d4c
034bc070: e00313aa mov x0, x19
034bc074: 020494d2 mov x2, #0xa020
034bc078: 01008052 mov w1, #0
034bc07c: e9638997 bl #0x1715020 ; memset@plt
034bc080: bf5300f9 str xzr, [x29, #0xa0]
034bc084: 801640b9 ldr w0, [x20, #0x14]
034bc088: 015d82d2 mov x1, #0x12e8
034bc08c: a103018b add x1, x29, x1
034bc090: 02e595d2 mov x2, #0xaf28
034bc094: a0e312b9 str w0, [x29, #0x12e0]
034bc098: 20008052 mov w0, #1
034bc09c: 83e595d2 mov x3, #0xaf2c
034bc0a0: bfab00b9 str wzr, [x29, #0xa8]
034bc0a4: 20000039 strb w0, [x1]
034bc0a8: a103028b add x1, x29, x2
034bc0ac: 802a40b9 ldr w0, [x20, #0x28]
034bc0b0: b7e712b9 str w23, [x29, #0x12e4]
034bc0b4: 200000b9 str w0, [x1]
034bc0b8: a003038b add x0, x29, x3
034bc0bc: 160000b9 str w22, [x0]
034bc0c0: 807a8352 mov w0, #0x1bd4
034bc0c4: 41a6e897 bl #0x2ee59c8
034bc0c8: 045f96d2 mov x4, #0xb2f8
034bc0cc: a103048b add x1, x29, x4
034bc0d0: 20000039 strb w0, [x1]
034bc0d4: e10318aa mov x1, x24
034bc0d8: e00313aa mov x0, x19
034bc0dc: 5cb50394 bl #0x35a964c
034bc0e0: a4ab40b9 ldr w4, [x29, #0xa8]
034bc0e4: a4040035 cbnz w4, #0x34bc178
034bc0e8: a0a740b9 ldr w0, [x29, #0xa4]
034bc0ec: 020494d2 mov x2, #0xa020
034bc0f0: 01008052 mov w1, #0
034bc0f4: 195f96d2 mov x25, #0xb2f8
034bc0f8: 803600b9 str w0, [x20, #0x34]
034bc0fc: e00313aa mov x0, x19
034bc100: c8638997 bl #0x1715020 ; memset@plt
034bc104: b7e712b9 str w23, [x29, #0x12e4]
034bc108: 12e595d2 mov x18, #0xaf28
034bc10c: 801640b9 ldr w0, [x20, #0x14]
034bc110: a103128b add x1, x29, x18
034bc114: 97e595d2 mov x23, #0xaf2c
034bc118: a0e312b9 str w0, [x29, #0x12e0]
034bc11c: 802a40b9 ldr w0, [x20, #0x28]
034bc120: bf5300f9 str xzr, [x29, #0xa0]
034bc124: 200000b9 str w0, [x1]
034bc128: a003178b add x0, x29, x23
034bc12c: bfab00b9 str wzr, [x29, #0xa8]
034bc130: 160000b9 str w22, [x0]
034bc134: 807a8352 mov w0, #0x1bd4
034bc138: 24a6e897 bl #0x2ee59c8
034bc13c: a103198b add x1, x29, x25
034bc140: 20000039 strb w0, [x1]
034bc144: e10318aa mov x1, x24
034bc148: e00313aa mov x0, x19
034bc14c: 40b50394 bl #0x35a964c
034bc150: a4ab40b9 ldr w4, [x29, #0xa8]
034bc154: e4080034 cbz w4, #0x34bc270
034bc158: 82b800f0 adrp x2, #0x4bcf000
034bc15c: 61ae00d0 adrp x1, #0x4a8a000
034bc160: 80b800f0 adrp x0, #0x4bcf000
034bc164: e3098052 mov w3, #0x4f
034bc168: 42202291 add x2, x2, #0x888
034bc16c: 21b43f91 add x1, x1, #0xfed
034bc170: 00c01f91 add x0, x0, #0x7f0
034bc174: 08000014 b #0x34bc194
034bc178: 82b800f0 adrp x2, #0x4bcf000
034bc17c: 61ae00d0 adrp x1, #0x4a8a000
034bc180: 80b70090 adrp x0, #0x4bac000
034bc184: 42202291 add x2, x2, #0x888
034bc188: 21b43f91 add x1, x1, #0xfed
034bc18c: 00580991 add x0, x0, #0x256
034bc190: 23068052 mov w3, #0x31
034bc194: d0a50994 bl #0x37258d4
034bc198: a0630391 add x0, x29, #0xd8
034bc19c: 1f7c00a9 stp xzr, xzr, [x0]
034bc1a0: 40038052 mov w0, #0x1a
034bc1a4: 0020a072 movk w0, #0x100, lsl #16
034bc1a8: bf7700f9 str xzr, [x29, #0xe8]
034bc1ac: bff300b9 str wzr, [x29, #0xf0]
034bc1b0: a0db00b9 str w0, [x29, #0xd8]
034bc1b4: a0ab40b9 ldr w0, [x29, #0xa8]
034bc1b8: a0e700b9 str w0, [x29, #0xe4]
034bc1bc: e00315aa mov x0, x21
034bc1c0: 3ecec197 bl #0x252fab8
034bc1c4: e10313aa mov x1, x19
034bc1c8: e00315aa mov x0, x21
034bc1cc: f0b20394 bl #0x35a8d8c
034bc1d0: e00315aa mov x0, x21
034bc1d4: b6feff97 bl #0x34bbcac
034bc1d8: b47340f9 ldr x20, [x29, #0xe0]
034bc1dc: 90cfd097 bl #0x28f001c
034bc1e0: f60300aa mov x22, x0
034bc1e4: 93cfd097 bl #0x28f0030
034bc1e8: a07709f9 str x0, [x29, #0x12e8]
034bc1ec: e0618052 mov w0, #0x30f
034bc1f0: a25e82d2 mov x2, #0x12f5
034bc1f4: e10318aa mov x1, x24
034bc1f8: b67309f9 str x22, [x29, #0x12e0]
034bc1fc: a0f312b9 str w0, [x29, #0x12f0]
034bc200: 805e82d2 mov x0, #0x12f4
034bc204: a003008b add x0, x29, x0
034bc208: b47f09f9 str x20, [x29, #0x12f8]
034bc20c: 1f000039 strb wzr, [x0]
034bc210: a003028b add x0, x29, x2
034bc214: 1f000039 strb wzr, [x0]
034bc218: 20008052 mov w0, #1
034bc21c: a0a300b9 str w0, [x29, #0xa0]
034bc220: e00313aa mov x0, x19
034bc224: c3feff97 bl #0x34bbd30
034bc228: e00313aa mov x0, x19
034bc22c: b4feff97 bl #0x34bbcfc
034bc230: e00315aa mov x0, x21
034bc234: a7feff97 bl #0x34bbcd0
034bc238: e10313aa mov x1, x19
034bc23c: e00315aa mov x0, x21
034bc240: 23af0394 bl #0x35a7ecc
034bc244: e1008052 mov w1, #7
034bc248: 00018052 mov w0, #8
034bc24c: 0ecdc297 bl #0x256f684
034bc250: f35341a9 ldp x19, x20, [sp, #0x10]
034bc254: f55b42a9 ldp x21, x22, [sp, #0x20]
034bc258: f76343a9 ldp x23, x24, [sp, #0x30]
034bc25c: f96b44a9 ldp x25, x26, [sp, #0x40]
034bc260: fd7bc5a8 ldp x29, x30, [sp], #0x50
034bc264: ff2f4091 add sp, sp, #0xb, lsl #12
034bc268: ffc30a91 add sp, sp, #0x2b0
034bc26c: c0035fd6 ret 
034bc270: a0a340b9 ldr w0, [x29, #0xa0]
034bc274: b9030291 add x25, x29, #0x80
034bc278: e10319aa mov x1, x25
034bc27c: a07f1b29 stp w0, wzr, [x29, #0xd8]
034bc280: e00315aa mov x0, x21
034bc284: e2b20394 bl #0x35a8e0c
034bc288: bf3300f9 str xzr, [x29, #0x60]
034bc28c: 801640b9 ldr w0, [x20, #0x14]
034bc290: a1430191 add x1, x29, #0x50
034bc294: a06300b9 str w0, [x29, #0x60]
034bc298: a0830191 add x0, x29, #0x60
034bc29c: dcae0394 bl #0x35a7e0c
034bc2a0: a45340b9 ldr w4, [x29, #0x50]
034bc2a4: 24130034 cbz w4, #0x34bc508
034bc2a8: 96b800f0 adrp x22, #0x4bcf000
034bc2ac: 77ae00d0 adrp x23, #0x4a8a000
034bc2b0: d6222291 add x22, x22, #0x888
034bc2b4: f7b63f91 add x23, x23, #0xfed
034bc2b8: 80b800f0 adrp x0, #0x4bcf000
034bc2bc: e20316aa mov x2, x22
034bc2c0: e10317aa mov x1, x23
034bc2c4: 00f02091 add x0, x0, #0x83c
034bc2c8: 830e8052 mov w3, #0x74
034bc2cc: 82a50994 bl #0x37258d4
034bc2d0: bf7f09a9 stp xzr, xzr, [x29, #0x90]
034bc2d4: 801640b9 ldr w0, [x20, #0x14]
034bc2d8: e10318aa mov x1, x24
034bc2dc: bf7f08a9 stp xzr, xzr, [x29, #0x80]
034bc2e0: a09300b9 str w0, [x29, #0x90]
034bc2e4: 40008052 mov w0, #2
034bc2e8: a09700b9 str w0, [x29, #0x94]
034bc2ec: e00319aa mov x0, x25
034bc2f0: 67b50394 bl #0x35a988c
034bc2f4: a4d340b9 ldr w4, [x29, #0xd0]
034bc2f8: 9f400371 cmp w4, #0xd0
034bc2fc: c11e0054 b.ne #0x34bc6d4
034bc300: 80b70090 adrp x0, #0x4bac000
034bc304: e20316aa mov x2, x22
034bc308: e10317aa mov x1, x23
034bc30c: 00103991 add x0, x0, #0xe44
034bc310: e30f8052 mov w3, #0x7f
034bc314: 70a50994 bl #0x37258d4
034bc318: 80b800f0 adrp x0, #0x4bcf000
034bc31c: e20316aa mov x2, x22
034bc320: 005c2191 add x0, x0, #0x857
034bc324: 01108052 mov w1, #0x80
034bc328: ed3d0694 bl #0x364badc
034bc32c: a0cf40b9 ldr w0, [x29, #0xcc]
034bc330: e10315aa mov x1, x21
034bc334: b6c30191 add x22, x29, #0x70
034bc338: 802e00b9 str w0, [x20, #0x2c]
034bc33c: a0ab40b9 ldr w0, [x29, #0xa8]
034bc340: 803200b9 str w0, [x20, #0x30]
034bc344: 801640b9 ldr w0, [x20, #0x14]
034bc348: a0e312b9 str w0, [x29, #0x12e0]
034bc34c: 802640b9 ldr w0, [x20, #0x24]
034bc350: a0e712b9 str w0, [x29, #0x12e4]
034bc354: e00313aa mov x0, x19
034bc358: 8db40394 bl #0x35a958c
034bc35c: a0bb52b9 ldr w0, [x29, #0x12b8]
034bc360: 001e0034 cbz w0, #0x34bc720
034bc364: 973240b9 ldr w23, [x20, #0x30]
034bc368: b9630191 add x25, x29, #0x58
034bc36c: baa30191 add x26, x29, #0x68
034bc370: f7060051 sub w23, w23, #1
034bc374: b71df837 tbnz w23, #0x1f, #0x34bc728
034bc378: 802e40b9 ldr w0, [x20, #0x2c]
034bc37c: e10319aa mov x1, x25
034bc380: a05f0d29 stp w0, w23, [x29, #0x68]
034bc384: e0031aaa mov x0, x26
034bc388: 01b50394 bl #0x35a978c
034bc38c: 801640b9 ldr w0, [x20, #0x14]
034bc390: e10313aa mov x1, x19
034bc394: a07300b9 str w0, [x29, #0x70]
034bc398: a05b40b9 ldr w0, [x29, #0x58]
034bc39c: a07700b9 str w0, [x29, #0x74]
034bc3a0: e00316aa mov x0, x22
034bc3a4: 7ab40394 bl #0x35a958c
034bc3a8: a0c364b9 ldr w0, [x29, #0x24c0]
034bc3ac: 601b0035 cbnz w0, #0x34bc718
034bc3b0: b7e352b9 ldr w23, [x29, #0x12e0]
034bc3b4: e00316aa mov x0, x22
034bc3b8: 3dfeff97 bl #0x34bbcac
034bc3bc: ba3f40f9 ldr x26, [x29, #0x78]
034bc3c0: 56c3d097 bl #0x28ed118
034bc3c4: f90300aa mov x25, x0
034bc3c8: 59c3d097 bl #0x28ed12c
034bc3cc: ba7f09f9 str x26, [x29, #0x12f8]
034bc3d0: 821a40b9 ldr w2, [x20, #0x18]
034bc3d4: 845e82d2 mov x4, #0x12f4
034bc3d8: a55e82d2 mov x5, #0x12f5
034bc3dc: e103172a mov w1, w23
034bc3e0: e303022a mov w3, w2
034bc3e4: 42700611 add w2, w2, #0x19c
034bc3e8: a2f312b9 str w2, [x29, #0x12f0]
034bc3ec: 0010038b add x0, x0, x3, lsl #4
034bc3f0: 390b038b add x25, x25, x3, lsl #2
034bc3f4: a07709f9 str x0, [x29, #0x12e8]
034bc3f8: a003048b add x0, x29, x4
034bc3fc: b97309f9 str x25, [x29, #0x12e0]
034bc400: 1f000039 strb wzr, [x0]
034bc404: a003058b add x0, x29, x5
034bc408: 1f000039 strb wzr, [x0]
034bc40c: e00313aa mov x0, x19
034bc410: 76feff97 bl #0x34bbde8
034bc414: e00313aa mov x0, x19
034bc418: 67feff97 bl #0x34bbdb4
034bc41c: e00316aa mov x0, x22
034bc420: 2cfeff97 bl #0x34bbcd0
034bc424: e00316aa mov x0, x22
034bc428: 21feff97 bl #0x34bbcac
034bc42c: b93f40f9 ldr x25, [x29, #0x78]
034bc430: c0d1d097 bl #0x28f0b30
034bc434: f70300aa mov x23, x0
034bc438: c3d1d097 bl #0x28f0b44
034bc43c: b97f09f9 str x25, [x29, #0x12f8]
034bc440: 811a40b9 ldr w1, [x20, #0x18]
034bc444: 865e82d2 mov x6, #0x12f4
034bc448: a75e82d2 mov x7, #0x12f5
034bc44c: e203012a mov w2, w1
034bc450: 21580d11 add w1, w1, #0x356
034bc454: a1f312b9 str w1, [x29, #0x12f0]
034bc458: 01008012 mov w1, #-1
034bc45c: 0010028b add x0, x0, x2, lsl #4
034bc460: f70a028b add x23, x23, x2, lsl #2
034bc464: a07709f9 str x0, [x29, #0x12e8]
034bc468: a003068b add x0, x29, x6
034bc46c: b77309f9 str x23, [x29, #0x12e0]
034bc470: 1f000039 strb wzr, [x0]
034bc474: a003078b add x0, x29, x7
034bc478: 1f000039 strb wzr, [x0]
034bc47c: e00313aa mov x0, x19
034bc480: 85feff97 bl #0x34bbe94
034bc484: e00313aa mov x0, x19
034bc488: 76feff97 bl #0x34bbe60
034bc48c: e00316aa mov x0, x22
034bc490: 10feff97 bl #0x34bbcd0
034bc494: e00316aa mov x0, x22
034bc498: 05feff97 bl #0x34bbcac
034bc49c: b93f40f9 ldr x25, [x29, #0x78]
034bc4a0: aed1d097 bl #0x28f0b58
034bc4a4: f70300aa mov x23, x0
034bc4a8: b1d1d097 bl #0x28f0b6c
034bc4ac: b97f09f9 str x25, [x29, #0x12f8]
034bc4b0: 811a40b9 ldr w1, [x20, #0x18]
034bc4b4: 885e82d2 mov x8, #0x12f4
034bc4b8: a95e82d2 mov x9, #0x12f5
034bc4bc: e203012a mov w2, w1
034bc4c0: 21640d11 add w1, w1, #0x359
034bc4c4: a1f312b9 str w1, [x29, #0x12f0]
034bc4c8: 01008012 mov w1, #-1
034bc4cc: 0010028b add x0, x0, x2, lsl #4
034bc4d0: f70a028b add x23, x23, x2, lsl #2
034bc4d4: a07709f9 str x0, [x29, #0x12e8]
034bc4d8: a003088b add x0, x29, x8
034bc4dc: b77309f9 str x23, [x29, #0x12e0]
034bc4e0: 1f000039 strb wzr, [x0]
034bc4e4: a003098b add x0, x29, x9
034bc4e8: 1f000039 strb wzr, [x0]
034bc4ec: e00313aa mov x0, x19
034bc4f0: 94feff97 bl #0x34bbf40
034bc4f4: e00313aa mov x0, x19
034bc4f8: 85feff97 bl #0x34bbf0c
034bc4fc: e00316aa mov x0, x22
034bc500: f4fdff97 bl #0x34bbcd0
034bc504: 7b000014 b #0x34bc6f0
034bc508: e00315aa mov x0, x21
034bc50c: e8fdff97 bl #0x34bbcac
034bc510: b77340f9 ldr x23, [x29, #0xe0]
034bc514: 01c3d097 bl #0x28ed118
034bc518: f60300aa mov x22, x0
034bc51c: 04c3d097 bl #0x28ed12c
034bc520: b77f09f9 str x23, [x29, #0x12f8]
034bc524: 811a40b9 ldr w1, [x20, #0x18]
034bc528: 8c5e82d2 mov x12, #0x12f4
034bc52c: ad5e82d2 mov x13, #0x12f5
034bc530: e203012a mov w2, w1
034bc534: 21700611 add w1, w1, #0x19c
034bc538: a1f312b9 str w1, [x29, #0x12f0]
034bc53c: 01008012 mov w1, #-1
034bc540: 0010028b add x0, x0, x2, lsl #4
034bc544: d60a028b add x22, x22, x2, lsl #2
034bc548: a07709f9 str x0, [x29, #0x12e8]
034bc54c: a0030c8b add x0, x29, x12
034bc550: b67309f9 str x22, [x29, #0x12e0]
034bc554: 1f000039 strb wzr, [x0]
034bc558: a0030d8b add x0, x29, x13
034bc55c: 1f000039 strb wzr, [x0]
034bc560: e00313aa mov x0, x19
034bc564: 21feff97 bl #0x34bbde8
034bc568: e00313aa mov x0, x19
034bc56c: 12feff97 bl #0x34bbdb4
034bc570: e00315aa mov x0, x21
034bc574: d7fdff97 bl #0x34bbcd0
034bc578: e00315aa mov x0, x21
034bc57c: ccfdff97 bl #0x34bbcac
034bc580: b77340f9 ldr x23, [x29, #0xe0]
034bc584: 6bd1d097 bl #0x28f0b30
034bc588: f60300aa mov x22, x0
034bc58c: 6ed1d097 bl #0x28f0b44
034bc590: b77f09f9 str x23, [x29, #0x12f8]
034bc594: 811a40b9 ldr w1, [x20, #0x18]
034bc598: 8e5e82d2 mov x14, #0x12f4
034bc59c: af5e82d2 mov x15, #0x12f5
034bc5a0: e203012a mov w2, w1
034bc5a4: 21580d11 add w1, w1, #0x356
034bc5a8: a1f312b9 str w1, [x29, #0x12f0]
034bc5ac: 01008012 mov w1, #-1
034bc5b0: 0010028b add x0, x0, x2, lsl #4
034bc5b4: d60a028b add x22, x22, x2, lsl #2
034bc5b8: a07709f9 str x0, [x29, #0x12e8]
034bc5bc: a0030e8b add x0, x29, x14
034bc5c0: b67309f9 str x22, [x29, #0x12e0]
034bc5c4: 1f000039 strb wzr, [x0]
034bc5c8: a0030f8b add x0, x29, x15
034bc5cc: 1f000039 strb wzr, [x0]
034bc5d0: e00313aa mov x0, x19
034bc5d4: 30feff97 bl #0x34bbe94
034bc5d8: e00313aa mov x0, x19
034bc5dc: 21feff97 bl #0x34bbe60
034bc5e0: e00315aa mov x0, x21
034bc5e4: bbfdff97 bl #0x34bbcd0
034bc5e8: e00315aa mov x0, x21
034bc5ec: b0fdff97 bl #0x34bbcac
034bc5f0: b77340f9 ldr x23, [x29, #0xe0]
034bc5f4: 59d1d097 bl #0x28f0b58
034bc5f8: f60300aa mov x22, x0
034bc5fc: 5cd1d097 bl #0x28f0b6c
034bc600: b77f09f9 str x23, [x29, #0x12f8]
034bc604: 811a40b9 ldr w1, [x20, #0x18]
034bc608: 905e82d2 mov x16, #0x12f4
034bc60c: b15e82d2 mov x17, #0x12f5
034bc610: e203012a mov w2, w1
034bc614: 21640d11 add w1, w1, #0x359
034bc618: a1f312b9 str w1, [x29, #0x12f0]
034bc61c: 01008012 mov w1, #-1
034bc620: 0010028b add x0, x0, x2, lsl #4
034bc624: d60a028b add x22, x22, x2, lsl #2
034bc628: a07709f9 str x0, [x29, #0x12e8]
034bc62c: a003108b add x0, x29, x16
034bc630: b67309f9 str x22, [x29, #0x12e0]
034bc634: 1f000039 strb wzr, [x0]
034bc638: a003118b add x0, x29, x17
034bc63c: 1f000039 strb wzr, [x0]
034bc640: e00313aa mov x0, x19
034bc644: 3ffeff97 bl #0x34bbf40
034bc648: e00313aa mov x0, x19
034bc64c: 30feff97 bl #0x34bbf0c
034bc650: e00315aa mov x0, x21
034bc654: 9ffdff97 bl #0x34bbcd0
034bc658: 843640b9 ldr w4, [x20, #0x34]
034bc65c: 64010035 cbnz w4, #0x34bc688
034bc660: 0b5c82d2 mov x11, #0x12e0
034bc664: bf7b09f9 str xzr, [x29, #0x12f0]
034bc668: a0030b8b add x0, x29, x11
034bc66c: bffb12b9 str wzr, [x29, #0x12f8]
034bc670: 1f7c00a9 stp xzr, xzr, [x0]
034bc674: 20038052 mov w0, #0x19
034bc678: 0020a072 movk w0, #0x100, lsl #16
034bc67c: a0e312b9 str w0, [x29, #0x12e0]
034bc680: e00313aa mov x0, x19
034bc684: cffeff17 b #0x34bc1c0
034bc688: 82b800f0 adrp x2, #0x4bcf000
034bc68c: 61ae00d0 adrp x1, #0x4a8a000
034bc690: 80b800f0 adrp x0, #0x4bcf000
034bc694: 42202291 add x2, x2, #0x888
034bc698: 00642091 add x0, x0, #0x819
034bc69c: 21b43f91 add x1, x1, #0xfed
034bc6a0: 830d8052 mov w3, #0x6c
034bc6a4: 8ca40994 bl #0x37258d4
034bc6a8: bf7b09f9 str xzr, [x29, #0x12f0]
034bc6ac: 0a5c82d2 mov x10, #0x12e0
034bc6b0: bffb12b9 str wzr, [x29, #0x12f8]
034bc6b4: a0030a8b add x0, x29, x10
034bc6b8: 1f7c00a9 stp xzr, xzr, [x0]
034bc6bc: 40038052 mov w0, #0x1a
034bc6c0: 0020a072 movk w0, #0x100, lsl #16
034bc6c4: a0e312b9 str w0, [x29, #0x12e0]
034bc6c8: a0178052 mov w0, #0xbd
034bc6cc: a0ef12b9 str w0, [x29, #0x12ec]
034bc6d0: ecffff17 b #0x34bc680
034bc6d4: c4e2ff34 cbz w4, #0x34bc32c
034bc6d8: 80b70090 adrp x0, #0x4bac000
034bc6dc: e20316aa mov x2, x22
034bc6e0: e10317aa mov x1, x23
034bc6e4: 00543891 add x0, x0, #0xe15
034bc6e8: 83108052 mov w3, #0x84
034bc6ec: 7aa40994 bl #0x37258d4
034bc6f0: 035c82d2 mov x3, #0x12e0
034bc6f4: a003038b add x0, x29, x3
034bc6f8: 1f7c00a9 stp xzr, xzr, [x0]
034bc6fc: 40038052 mov w0, #0x1a
034bc700: 0020a072 movk w0, #0x100, lsl #16
034bc704: bf7b09f9 str xzr, [x29, #0x12f0]
034bc708: bffb12b9 str wzr, [x29, #0x12f8]
034bc70c: a0e312b9 str w0, [x29, #0x12e0]
034bc710: a05340b9 ldr w0, [x29, #0x50]
034bc714: eeffff17 b #0x34bc6cc
034bc718: f7060051 sub w23, w23, #1
034bc71c: 16ffff17 b #0x34bc374
034bc720: 972640b9 ldr w23, [x20, #0x24]
034bc724: 24ffff17 b #0x34bc3b4
034bc728: 17008012 mov w23, #-1
034bc72c: 22ffff17 b #0x34bc3b4
034bc730: 812b0190 adrp x1, #0x5a2c000
034bc734: 215c41f9 ldr x1, [x1, #0x2b8]
034bc738: 21400091 add x1, x1, #0x10
034bc73c: 010000f9 str x1, [x0]
034bc740: a569f217 b #0x3156dd4
