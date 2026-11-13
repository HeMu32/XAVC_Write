034bca14: ff0313d1 sub sp, sp, #0x4c0
034bca18: fd7bbaa9 stp x29, x30, [sp, #-0x60]!
034bca1c: fd030091 mov x29, sp
034bca20: f55b02a9 stp x21, x22, [sp, #0x20]
034bca24: b503058b add x21, x29, x5
034bca28: f35301a9 stp x19, x20, [sp, #0x10]
034bca2c: f40300aa mov x20, x0
034bca30: e00315aa mov x0, x21
034bca34: f96b04a9 stp x25, x26, [sp, #0x40]
034bca38: f76303a9 stp x23, x24, [sp, #0x30]
034bca3c: b7c30391 add x23, x29, #0xf0
034bca40: fb7305a9 stp x27, x28, [sp, #0x50]
034bca44: 99b800f0 adrp x25, #0x4bcf000
034bca48: 49ffff97 bl #0x34bc76c
034bca4c: b38349f9 ldr x19, [x29, #0x1300]
034bca50: 73cdd097 bl #0x28f001c
034bca54: f60300aa mov x22, x0
034bca58: 76cdd097 bl #0x28f0030
034bca5c: a08712f9 str x0, [x29, #0x2508]
034bca60: e0618052 mov w0, #0x30f
034bca64: 87a284d2 mov x7, #0x2514
034bca68: a8a284d2 mov x8, #0x2515
034bca6c: 06a084d2 mov x6, #0x2500
034bca70: a01325b9 str w0, [x29, #0x2510]
034bca74: a003078b add x0, x29, x7
034bca78: b38f12f9 str x19, [x29, #0x2518]
034bca7c: b303068b add x19, x29, x6
034bca80: e10317aa mov x1, x23
034bca84: b68312f9 str x22, [x29, #0x2500]
034bca88: 1f000039 strb wzr, [x0]
034bca8c: a003088b add x0, x29, x8
034bca90: bff300b9 str wzr, [x29, #0xf0]
034bca94: 7aae00d0 adrp x26, #0x4a8a000
034bca98: 1f000039 strb wzr, [x0]
034bca9c: e00313aa mov x0, x19
034bcaa0: 6effff97 bl #0x34bc858
034bcaa4: e00313aa mov x0, x19
034bcaa8: 52ffff97 bl #0x34bc7f0
034bcaac: e00315aa mov x0, x21
034bcab0: 38ffff97 bl #0x34bc790
034bcab4: e10313aa mov x1, x19
034bcab8: e00315aa mov x0, x21
034bcabc: 04ad0394 bl #0x35a7ecc
034bcac0: e00313aa mov x0, x19
034bcac4: 1617c397 bl #0x258271c
034bcac8: 812a40b9 ldr w1, [x20, #0x28]
034bcacc: e00313aa mov x0, x19
034bcad0: 820e4629 ldp w2, w3, [x20, #0x30]
034bcad4: 4823c397 bl #0x25857f4
034bcad8: f603002a mov w22, w0
034bcadc: e00313aa mov x0, x19
034bcae0: 1317c397 bl #0x258272c
034bcae4: bf3b00f9 str xzr, [x29, #0x70]
034bcae8: 802240b9 ldr w0, [x20, #0x20]
034bcaec: a1830191 add x1, x29, #0x60
034bcaf0: a07300b9 str w0, [x29, #0x70]
034bcaf4: a0c30191 add x0, x29, #0x70
034bcaf8: c5ac0394 bl #0x35a7e0c
034bcafc: a06340b9 ldr w0, [x29, #0x60]
034bcb00: e0080035 cbnz w0, #0x34bcc1c
034bcb04: 80b800f0 adrp x0, #0x4bcf000
034bcb08: 22e32791 add x2, x25, #0x9f8
034bcb0c: 41b73f91 add x1, x26, #0xfed
034bcb10: 00c82391 add x0, x0, #0x8f2
034bcb14: 43058052 mov w3, #0x2a
034bcb18: 6fa30994 bl #0x37258d4
034bcb1c: e00315aa mov x0, x21
034bcb20: 13ffff97 bl #0x34bc76c
034bcb24: b98349f9 ldr x25, [x29, #0x1300]
034bcb28: 7cc1d097 bl #0x28ed118
034bcb2c: f80300aa mov x24, x0
034bcb30: 7fc1d097 bl #0x28ed12c
034bcb34: b98f12f9 str x25, [x29, #0x2518]
034bcb38: 812640b9 ldr w1, [x20, #0x24]
034bcb3c: e203012a mov w2, w1
034bcb40: 21700611 add w1, w1, #0x19c
034bcb44: a11325b9 str w1, [x29, #0x2510]
034bcb48: a1a284d2 mov x1, #0x2515
034bcb4c: 0010028b add x0, x0, x2, lsl #4
034bcb50: 180b028b add x24, x24, x2, lsl #2
034bcb54: a08712f9 str x0, [x29, #0x2508]
034bcb58: 80a284d2 mov x0, #0x2514
034bcb5c: a003008b add x0, x29, x0
034bcb60: b88312f9 str x24, [x29, #0x2500]
034bcb64: 1f000039 strb wzr, [x0]
034bcb68: a003018b add x0, x29, x1
034bcb6c: e103162a mov w1, w22
034bcb70: 1f000039 strb wzr, [x0]
034bcb74: e00313aa mov x0, x19
034bcb78: 66ffff97 bl #0x34bc910
034bcb7c: e00313aa mov x0, x19
034bcb80: 57ffff97 bl #0x34bc8dc
034bcb84: e00315aa mov x0, x21
034bcb88: 02ffff97 bl #0x34bc790
034bcb8c: e00315aa mov x0, x21
034bcb90: f7feff97 bl #0x34bc76c
034bcb94: b48349f9 ldr x20, [x29, #0x1300]
034bcb98: 6fd9d197 bl #0x2933154
034bcb9c: f60300aa mov x22, x0
034bcba0: 72d9d197 bl #0x2933168
034bcba4: a08712f9 str x0, [x29, #0x2508]
034bcba8: a0f78652 mov w0, #0x37bd
034bcbac: 82a284d2 mov x2, #0x2514
034bcbb0: a3a284d2 mov x3, #0x2515
034bcbb4: e10317aa mov x1, x23
034bcbb8: a01325b9 str w0, [x29, #0x2510]
034bcbbc: a003028b add x0, x29, x2
034bcbc0: b68312f9 str x22, [x29, #0x2500]
034bcbc4: b48f12f9 str x20, [x29, #0x2518]
034bcbc8: 1f000039 strb wzr, [x0]
034bcbcc: a003038b add x0, x29, x3
034bcbd0: 1f000039 strb wzr, [x0]
034bcbd4: 40008052 mov w0, #2
034bcbd8: a0f300b9 str w0, [x29, #0xf0]
034bcbdc: e00313aa mov x0, x19
034bcbe0: 6affff97 bl #0x34bc988
034bcbe4: e00313aa mov x0, x19
034bcbe8: 0fffff97 bl #0x34bc824
034bcbec: e00315aa mov x0, x21
034bcbf0: e8feff97 bl #0x34bc790
034bcbf4: bf8b12f9 str xzr, [x29, #0x2510]
034bcbf8: 04a084d2 mov x4, #0x2500
034bcbfc: bf1b25b9 str wzr, [x29, #0x2518]
034bcc00: a003048b add x0, x29, x4
034bcc04: 1f7c00a9 stp xzr, xzr, [x0]
034bcc08: 20038052 mov w0, #0x19
034bcc0c: 0020a072 movk w0, #0x100, lsl #16
034bcc10: a00325b9 str w0, [x29, #0x2500]
034bcc14: e00313aa mov x0, x19
034bcc18: 85000014 b #0x34bce2c
034bcc1c: 36e32791 add x22, x25, #0x9f8
034bcc20: 58b73f91 add x24, x26, #0xfed
034bcc24: 80b800f0 adrp x0, #0x4bcf000
034bcc28: e20316aa mov x2, x22
034bcc2c: e10318aa mov x1, x24
034bcc30: 00742491 add x0, x0, #0x91d
034bcc34: 43068052 mov w3, #0x32
034bcc38: 27a30994 bl #0x37258d4
034bcc3c: a46340b9 ldr w4, [x29, #0x60]
034bcc40: 80b800f0 adrp x0, #0x4bcf000
034bcc44: e20316aa mov x2, x22
034bcc48: e10318aa mov x1, x24
034bcc4c: 00f02091 add x0, x0, #0x83c
034bcc50: 63068052 mov w3, #0x33
034bcc54: 20a30994 bl #0x37258d4
034bcc58: 802240b9 ldr w0, [x20, #0x20]
034bcc5c: e10317aa mov x1, x23
034bcc60: a00325b9 str w0, [x29, #0x2500]
034bcc64: 803240b9 ldr w0, [x20, #0x30]
034bcc68: a00725b9 str w0, [x29, #0x2504]
034bcc6c: e00313aa mov x0, x19
034bcc70: 47b20394 bl #0x35a958c
034bcc74: a0d352b9 ldr w0, [x29, #0x12d0]
034bcc78: 40220034 cbz w0, #0x34bd0c0
034bcc7c: e00315aa mov x0, x21
034bcc80: bbfeff97 bl #0x34bc76c
034bcc84: bb8349f9 ldr x27, [x29, #0x1300]
034bcc88: 33d9d197 bl #0x2933154
034bcc8c: fc0300aa mov x28, x0
034bcc90: 36d9d197 bl #0x2933168
034bcc94: a08712f9 str x0, [x29, #0x2508]
034bcc98: a0f78652 mov w0, #0x37bd
034bcc9c: 92a284d2 mov x18, #0x2514
034bcca0: bea284d2 mov x30, #0x2515
034bcca4: bb8f12f9 str x27, [x29, #0x2518]
034bcca8: a01325b9 str w0, [x29, #0x2510]
034bccac: a003128b add x0, x29, x18
034bccb0: bbe30291 add x27, x29, #0xb8
034bccb4: bc8312f9 str x28, [x29, #0x2500]
034bccb8: e1031baa mov x1, x27
034bccbc: 5c008052 mov w28, #2
034bccc0: 1f000039 strb wzr, [x0]
034bccc4: a0031e8b add x0, x29, x30
034bccc8: bcbb00b9 str w28, [x29, #0xb8]
034bcccc: 1f000039 strb wzr, [x0]
034bccd0: e00313aa mov x0, x19
034bccd4: 2dffff97 bl #0x34bc988
034bccd8: e00313aa mov x0, x19
034bccdc: d2feff97 bl #0x34bc824
034bcce0: e00315aa mov x0, x21
034bcce4: abfeff97 bl #0x34bc790
034bcce8: a0630291 add x0, x29, #0x98
034bccec: e1031baa mov x1, x27
034bccf0: 1f7c00a9 stp xzr, xzr, [x0]
034bccf4: a0a30291 add x0, x29, #0xa8
034bccf8: 1f7c00a9 stp xzr, xzr, [x0]
034bccfc: 802240b9 ldr w0, [x20, #0x20]
034bcd00: a0731529 stp w0, w28, [x29, #0xa8]
034bcd04: a0630291 add x0, x29, #0x98
034bcd08: e1b20394 bl #0x35a988c
034bcd0c: a4eb40b9 ldr w4, [x29, #0xe8]
034bcd10: 9f400371 cmp w4, #0xd0
034bcd14: 21130054 b.ne #0x34bcf78
034bcd18: 80b70090 adrp x0, #0x4bac000
034bcd1c: e20316aa mov x2, x22
034bcd20: e10318aa mov x1, x24
034bcd24: 00103991 add x0, x0, #0xe44
034bcd28: 83098052 mov w3, #0x4c
034bcd2c: eaa20994 bl #0x37258d4
034bcd30: 80b800f0 adrp x0, #0x4bcf000
034bcd34: e20316aa mov x2, x22
034bcd38: 00242591 add x0, x0, #0x949
034bcd3c: a1098052 mov w1, #0x4d
034bcd40: 673b0694 bl #0x364badc
034bcd44: a0c340b9 ldr w0, [x29, #0xc0]
034bcd48: 020494d2 mov x2, #0xa020
034bcd4c: b6e740b9 ldr w22, [x29, #0xe4]
034bcd50: 01008052 mov w1, #0
034bcd54: 803600b9 str w0, [x20, #0x34]
034bcd58: e00313aa mov x0, x19
034bcd5c: 962e00b9 str w22, [x20, #0x2c]
034bcd60: b0608997 bl #0x1715020 ; memset@plt
034bcd64: bf4700f9 str xzr, [x29, #0x88]
034bcd68: 0ca184d2 mov x12, #0x2508
034bcd6c: 802240b9 ldr w0, [x20, #0x20]
034bcd70: a1030c8b add x1, x29, x12
034bcd74: 4da184d2 mov x13, #0x250a
034bcd78: a00325b9 str w0, [x29, #0x2500]
034bcd7c: 6ea184d2 mov x14, #0x250b
034bcd80: 80ca4079 ldrh w0, [x20, #0x64]
034bcd84: 0f2998d2 mov x15, #0xc148
034bcd88: 902998d2 mov x16, #0xc14c
034bcd8c: bf9300b9 str wzr, [x29, #0x90]
034bcd90: 20000079 strh w0, [x1]
034bcd94: a1030d8b add x1, x29, x13
034bcd98: 809a4139 ldrb w0, [x20, #0x66]
034bcd9c: 20000039 strb w0, [x1]
034bcda0: a1030e8b add x1, x29, x14
034bcda4: 809e4139 ldrb w0, [x20, #0x67]
034bcda8: 20000039 strb w0, [x1]
034bcdac: a0030f8b add x0, x29, x15
034bcdb0: a103108b add x1, x29, x16
034bcdb4: 160000b9 str w22, [x0]
034bcdb8: 20078052 mov w0, #0x39
034bcdbc: 200000b9 str w0, [x1]
034bcdc0: 807a8352 mov w0, #0x1bd4
034bcdc4: 01a3e897 bl #0x2ee59c8
034bcdc8: 11a398d2 mov x17, #0xc518
034bcdcc: a103118b add x1, x29, x17
034bcdd0: 20000039 strb w0, [x1]
034bcdd4: a1230291 add x1, x29, #0x88
034bcdd8: e00313aa mov x0, x19
034bcddc: 1cb20394 bl #0x35a964c
034bcde0: a49340b9 ldr w4, [x29, #0x90]
034bcde4: e40e0034 cbz w4, #0x34bcfc0
034bcde8: 80b800f0 adrp x0, #0x4bcf000
034bcdec: 22e32791 add x2, x25, #0x9f8
034bcdf0: 00d82591 add x0, x0, #0x976
034bcdf4: 41b73f91 add x1, x26, #0xfed
034bcdf8: 630d8052 mov w3, #0x6b
034bcdfc: b6a20994 bl #0x37258d4
034bce00: bf8709f9 str xzr, [x29, #0x1308]
034bce04: 0b5f82d2 mov x11, #0x12f8
034bce08: bf1313b9 str wzr, [x29, #0x1310]
034bce0c: a0030b8b add x0, x29, x11
034bce10: 1f7c00a9 stp xzr, xzr, [x0]
034bce14: 40038052 mov w0, #0x1a
034bce18: 0020a072 movk w0, #0x100, lsl #16
034bce1c: a0fb12b9 str w0, [x29, #0x12f8]
034bce20: a06340b9 ldr w0, [x29, #0x60]
034bce24: a00713b9 str w0, [x29, #0x1304]
034bce28: e00315aa mov x0, x21
034bce2c: 23cbc197 bl #0x252fab8
034bce30: e10313aa mov x1, x19
034bce34: e00315aa mov x0, x21
034bce38: d5af0394 bl #0x35a8d8c
034bce3c: e00315aa mov x0, x21
034bce40: 4bfeff97 bl #0x34bc76c
034bce44: b48349f9 ldr x20, [x29, #0x1300]
034bce48: c1cbd097 bl #0x28efd4c
034bce4c: f60300aa mov x22, x0
034bce50: c4cbd097 bl #0x28efd60
034bce54: 85a284d2 mov x5, #0x2514
034bce58: a6a284d2 mov x6, #0x2515
034bce5c: a203058b add x2, x29, x5
034bce60: a15f8052 mov w1, #0x2fd
034bce64: 840080d2 mov x4, #4
034bce68: e30317aa mov x3, x23
034bce6c: 5f000039 strb wzr, [x2]
034bce70: a203068b add x2, x29, x6
034bce74: 5f000039 strb wzr, [x2]
034bce78: 020440f9 ldr x2, [x0, #8]
034bce7c: bff300b9 str wzr, [x29, #0xf0]
034bce80: b68312f9 str x22, [x29, #0x2500]
034bce84: a08712f9 str x0, [x29, #0x2508]
034bce88: a11325b9 str w1, [x29, #0x2510]
034bce8c: b48f12f9 str x20, [x29, #0x2518]
034bce90: 821200b4 cbz x2, #0x34bd0e0
034bce94: e00314aa mov x0, x20
034bce98: 87ad0994 bl #0x37284b4
034bce9c: a08752f9 ldr x0, [x29, #0x2508]
034bcea0: a4a284d2 mov x4, #0x2515
034bcea4: a103048b add x1, x29, x4
034bcea8: 000440f9 ldr x0, [x0, #8]
034bceac: 1f0000b9 str wzr, [x0]
034bceb0: 20008052 mov w0, #1
034bceb4: 20000039 strb w0, [x1]
034bceb8: 80a284d2 mov x0, #0x2514
034bcebc: a103008b add x1, x29, x0
034bcec0: a08352f9 ldr x0, [x29, #0x2500]
034bcec4: 1f0000b9 str wzr, [x0]
034bcec8: 20008052 mov w0, #1
034bcecc: 20000039 strb w0, [x1]
034bced0: e00313aa mov x0, x19
034bced4: 3afeff97 bl #0x34bc7bc
034bced8: e00315aa mov x0, x21
034bcedc: 2dfeff97 bl #0x34bc790
034bcee0: e00315aa mov x0, x21
034bcee4: 22feff97 bl #0x34bc76c
034bcee8: b48349f9 ldr x20, [x29, #0x1300]
034bceec: 4cccd097 bl #0x28f001c
034bcef0: f60300aa mov x22, x0
034bcef4: 4fccd097 bl #0x28f0030
034bcef8: a08712f9 str x0, [x29, #0x2508]
034bcefc: e0618052 mov w0, #0x30f
034bcf00: 82a284d2 mov x2, #0x2514
034bcf04: a3a284d2 mov x3, #0x2515
034bcf08: e10317aa mov x1, x23
034bcf0c: a01325b9 str w0, [x29, #0x2510]
034bcf10: a003028b add x0, x29, x2
034bcf14: b68312f9 str x22, [x29, #0x2500]
034bcf18: b48f12f9 str x20, [x29, #0x2518]
034bcf1c: 1f000039 strb wzr, [x0]
034bcf20: a003038b add x0, x29, x3
034bcf24: 1f000039 strb wzr, [x0]
034bcf28: 20008052 mov w0, #1
034bcf2c: a0f300b9 str w0, [x29, #0xf0]
034bcf30: e00313aa mov x0, x19
034bcf34: 49feff97 bl #0x34bc858
034bcf38: e00313aa mov x0, x19
034bcf3c: 2dfeff97 bl #0x34bc7f0
034bcf40: e00315aa mov x0, x21
034bcf44: 13feff97 bl #0x34bc790
034bcf48: e10313aa mov x1, x19
034bcf4c: e00315aa mov x0, x21
034bcf50: dfab0394 bl #0x35a7ecc
034bcf54: f35341a9 ldp x19, x20, [sp, #0x10]
034bcf58: f55b42a9 ldp x21, x22, [sp, #0x20]
034bcf5c: f76343a9 ldp x23, x24, [sp, #0x30]
034bcf60: f96b44a9 ldp x25, x26, [sp, #0x40]
034bcf64: fb7345a9 ldp x27, x28, [sp, #0x50]
034bcf68: fd7bc6a8 ldp x29, x30, [sp], #0x60
034bcf6c: ff334091 add sp, sp, #0xc, lsl #12
034bcf70: ff031391 add sp, sp, #0x4c0
034bcf74: c0035fd6 ret 
034bcf78: 64eeff34 cbz w4, #0x34bcd44
034bcf7c: 80b70090 adrp x0, #0x4bac000
034bcf80: e20316aa mov x2, x22
034bcf84: e10318aa mov x1, x24
034bcf88: 00543891 add x0, x0, #0xe15
034bcf8c: 230a8052 mov w3, #0x51
034bcf90: 51a20994 bl #0x37258d4
034bcf94: 07a084d2 mov x7, #0x2500
034bcf98: a003078b add x0, x29, x7
034bcf9c: 1f7c00a9 stp xzr, xzr, [x0]
034bcfa0: 40038052 mov w0, #0x1a
034bcfa4: 0020a072 movk w0, #0x100, lsl #16
034bcfa8: bf8b12f9 str xzr, [x29, #0x2510]
034bcfac: bf1b25b9 str wzr, [x29, #0x2518]
034bcfb0: a00325b9 str w0, [x29, #0x2500]
034bcfb4: a06340b9 ldr w0, [x29, #0x60]
034bcfb8: a00f25b9 str w0, [x29, #0x250c]
034bcfbc: 16ffff17 b #0x34bcc14
034bcfc0: a05b5129 ldp w0, w22, [x29, #0x88]
034bcfc4: b8a30191 add x24, x29, #0x68
034bcfc8: 963600b9 str w22, [x20, #0x34]
034bcfcc: bbe30191 add x27, x29, #0x78
034bcfd0: fc939892 mov x28, #-0xc4a0
034bcfd4: 802e00b9 str w0, [x20, #0x2c]
034bcfd8: d6060051 sub w22, w22, #1
034bcfdc: f606f837 tbnz w22, #0x1f, #0x34bd0b8
034bcfe0: 802e40b9 ldr w0, [x20, #0x2c]
034bcfe4: e10318aa mov x1, x24
034bcfe8: a05b0f29 stp w0, w22, [x29, #0x78]
034bcfec: e0031baa mov x0, x27
034bcff0: e7b10394 bl #0x35a978c
034bcff4: 802240b9 ldr w0, [x20, #0x20]
034bcff8: 0aa498d2 mov x10, #0xc520
034bcffc: e10315aa mov x1, x21
034bd000: a08300b9 str w0, [x29, #0x80]
034bd004: a06b40b9 ldr w0, [x29, #0x68]
034bd008: a08700b9 str w0, [x29, #0x84]
034bd00c: a0030a8b add x0, x29, x10
034bd010: 00001c8b add x0, x0, x28
034bd014: 5eb10394 bl #0x35a958c
034bd018: a0db64b9 ldr w0, [x29, #0x24d8]
034bd01c: a0040035 cbnz w0, #0x34bd0b0
034bd020: 80b800d0 adrp x0, #0x4bcf000
034bd024: 22e32791 add x2, x25, #0x9f8
034bd028: 41b73f91 add x1, x26, #0xfed
034bd02c: 00742691 add x0, x0, #0x99d
034bd030: 43108052 mov w3, #0x82
034bd034: 28a20994 bl #0x37258d4
034bd038: b6fb52b9 ldr w22, [x29, #0x12f8]
034bd03c: e00315aa mov x0, x21
034bd040: cbfdff97 bl #0x34bc76c
034bd044: b98349f9 ldr x25, [x29, #0x1300]
034bd048: 34c0d097 bl #0x28ed118
034bd04c: f80300aa mov x24, x0
034bd050: 37c0d097 bl #0x28ed12c
034bd054: b98f12f9 str x25, [x29, #0x2518]
034bd058: 822640b9 ldr w2, [x20, #0x24]
034bd05c: 88a284d2 mov x8, #0x2514
034bd060: a9a284d2 mov x9, #0x2515
034bd064: e103162a mov w1, w22
034bd068: e303022a mov w3, w2
034bd06c: 42700611 add w2, w2, #0x19c
034bd070: a21325b9 str w2, [x29, #0x2510]
034bd074: 0010038b add x0, x0, x3, lsl #4
034bd078: 180b038b add x24, x24, x3, lsl #2
034bd07c: a08712f9 str x0, [x29, #0x2508]
034bd080: a003088b add x0, x29, x8
034bd084: b88312f9 str x24, [x29, #0x2500]
034bd088: 1f000039 strb wzr, [x0]
034bd08c: a003098b add x0, x29, x9
034bd090: 1f000039 strb wzr, [x0]
034bd094: e00313aa mov x0, x19
034bd098: 1efeff97 bl #0x34bc910
034bd09c: e00313aa mov x0, x19
034bd0a0: 0ffeff97 bl #0x34bc8dc
034bd0a4: e00315aa mov x0, x21
034bd0a8: bafdff97 bl #0x34bc790
034bd0ac: baffff17 b #0x34bcf94
034bd0b0: d6060051 sub w22, w22, #1
034bd0b4: caffff17 b #0x34bcfdc
034bd0b8: 16008012 mov w22, #-1
034bd0bc: e0ffff17 b #0x34bd03c
034bd0c0: 80b800d0 adrp x0, #0x4bcf000
034bd0c4: e20316aa mov x2, x22
034bd0c8: e10318aa mov x1, x24
034bd0cc: 00002791 add x0, x0, #0x9c0
034bd0d0: 63118052 mov w3, #0x8b
034bd0d4: 00a20994 bl #0x37258d4
034bd0d8: 963240b9 ldr w22, [x20, #0x30]
034bd0dc: d8ffff17 b #0x34bd03c
034bd0e0: e20316aa mov x2, x22
034bd0e4: e00314aa mov x0, x20
034bd0e8: f3ac0994 bl #0x37284b4
034bd0ec: 73ffff17 b #0x34bceb8
034bd0f0: c0035fd6 ret 
