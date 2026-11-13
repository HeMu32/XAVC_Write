031f7a4c: fd7bbba9 stp x29, x30, [sp, #-0x50]!
031f7a50: fd030091 mov x29, sp
031f7a54: f55b02a9 stp x21, x22, [sp, #0x20]
031f7a58: 35008052 mov w21, #1
031f7a5c: f96b04a9 stp x25, x26, [sp, #0x40]
031f7a60: f90300aa mov x25, x0
031f7a64: 001440b9 ldr w0, [x0, #0x14]
031f7a68: b6c30191 add x22, x29, #0x70
031f7a6c: f76303a9 stp x23, x24, [sp, #0x30]
031f7a70: b7c30291 add x23, x29, #0xb0
031f7a74: bf7f07a9 stp xzr, xzr, [x29, #0x70]
031f7a78: e10317aa mov x1, x23
031f7a7c: bf4300f9 str xzr, [x29, #0x80]
031f7a80: b8430291 add x24, x29, #0x90
031f7a84: b5030e29 stp w21, w0, [x29, #0x70]
031f7a88: a08300b9 str w0, [x29, #0x80]
031f7a8c: e00316aa mov x0, x22
031f7a90: f35301a9 stp x19, x20, [sp, #0x10]
031f7a94: b4830191 add x20, x29, #0x60
031f7a98: bf7f0ba9 stp xzr, xzr, [x29, #0xb0]
031f7a9c: b3730191 add x19, x29, #0x5c
031f7aa0: bf7f0ca9 stp xzr, xzr, [x29, #0xc0]
031f7aa4: bf7f0da9 stp xzr, xzr, [x29, #0xd0]
031f7aa8: bf8b00b9 str wzr, [x29, #0x88]
031f7aac: bfe300b9 str wzr, [x29, #0xe0]
031f7ab0: 67c70e94 bl #0x35a984c
031f7ab4: a0e340b9 ldr w0, [x29, #0xe0]
031f7ab8: c0080035 cbnz w0, #0x31f7bd0
031f7abc: e00317aa mov x0, x23
031f7ac0: 020494d2 mov x2, #0xa020
031f7ac4: 01008052 mov w1, #0
031f7ac8: badf40b9 ldr w26, [x29, #0xdc]
031f7acc: 55759497 bl #0x1715020 ; memset@plt
031f7ad0: bf3300f9 str xzr, [x29, #0x60]
031f7ad4: 809f93d2 mov x0, #0x9cfc
031f7ad8: 029f93d2 mov x2, #0x9cf8
031f7adc: a103008b add x1, x29, x0
031f7ae0: 201740b9 ldr w0, [x25, #0x14]
031f7ae4: bf6b00b9 str wzr, [x29, #0x68]
031f7ae8: a0b300b9 str w0, [x29, #0xb0]
031f7aec: 00028052 mov w0, #0x10
031f7af0: a0b700b9 str w0, [x29, #0xb4]
031f7af4: e0378352 mov w0, #0x19bf
031f7af8: a0bb00b9 str w0, [x29, #0xb8]
031f7afc: 80018052 mov w0, #0xc
031f7b00: a0bf00b9 str w0, [x29, #0xbc]
031f7b04: a003028b add x0, x29, x2
031f7b08: 1a0000b9 str w26, [x0]
031f7b0c: 20078052 mov w0, #0x39
031f7b10: 200000b9 str w0, [x1]
031f7b14: e10314aa mov x1, x20
031f7b18: e00317aa mov x0, x23
031f7b1c: ccc60e94 bl #0x35a964c
031f7b20: e00316aa mov x0, x22
031f7b24: b1bdf397 bl #0x2ee71e8
031f7b28: bf3f00f9 str xzr, [x29, #0x78]
031f7b2c: d695dc97 bl #0x291d284
031f7b30: f70300aa mov x23, x0
031f7b34: d995dc97 bl #0x291d298
031f7b38: b46740b9 ldr w20, [x29, #0x64]
031f7b3c: 020440f9 ldr x2, [x0, #8]
031f7b40: 61c88352 mov w1, #0x1e43
031f7b44: bf930239 strb wzr, [x29, #0xa4]
031f7b48: 840080d2 mov x4, #4
031f7b4c: bf970239 strb wzr, [x29, #0xa5]
031f7b50: e30313aa mov x3, x19
031f7b54: b45f00b9 str w20, [x29, #0x5c]
031f7b58: b70309a9 stp x23, x0, [x29, #0x90]
031f7b5c: a1a300b9 str w1, [x29, #0xa0]
031f7b60: bf5700f9 str xzr, [x29, #0xa8]
031f7b64: e20200b4 cbz x2, #0x31f7bc0
031f7b68: 000080d2 mov x0, #0
031f7b6c: 52c21494 bl #0x37284b4
031f7b70: a04f40f9 ldr x0, [x29, #0x98]
031f7b74: 000440f9 ldr x0, [x0, #8]
031f7b78: 140000b9 str w20, [x0]
031f7b7c: b5970239 strb w21, [x29, #0xa5]
031f7b80: a04b40f9 ldr x0, [x29, #0x90]
031f7b84: 140000b9 str w20, [x0]
031f7b88: 20008052 mov w0, #1
031f7b8c: a0930239 strb w0, [x29, #0xa4]
031f7b90: e00318aa mov x0, x24
031f7b94: 9fffff97 bl #0x31f7a10
031f7b98: e00316aa mov x0, x22
031f7b9c: 92ffff97 bl #0x31f79e4
031f7ba0: f35341a9 ldp x19, x20, [sp, #0x10]
031f7ba4: f55b42a9 ldp x21, x22, [sp, #0x20]
031f7ba8: f76343a9 ldp x23, x24, [sp, #0x30]
031f7bac: f96b44a9 ldp x25, x26, [sp, #0x40]
031f7bb0: fd7bc5a8 ldp x29, x30, [sp], #0x50
031f7bb4: ff2b4091 add sp, sp, #0xa, lsl #12
031f7bb8: ff030291 add sp, sp, #0x80
031f7bbc: c0035fd6 ret 
031f7bc0: e20317aa mov x2, x23
031f7bc4: 000080d2 mov x0, #0
031f7bc8: 3bc21494 bl #0x37284b4
031f7bcc: edffff17 b #0x31f7b80
031f7bd0: 01ce00b0 adrp x1, #0x4bb8000
031f7bd4: 00ce00b0 adrp x0, #0x4bb8000
031f7bd8: 21a01491 add x1, x1, #0x528
031f7bdc: 00101491 add x0, x0, #0x504
031f7be0: a2048052 mov w2, #0x25
031f7be4: 3cb71494 bl #0x37258d4
031f7be8: e00314aa mov x0, x20
031f7bec: 7fbdf397 bl #0x2ee71e8
031f7bf0: bf3700f9 str xzr, [x29, #0x68]
031f7bf4: a495dc97 bl #0x291d284
031f7bf8: f60300aa mov x22, x0
031f7bfc: a795dc97 bl #0x291d298
031f7c00: 020440f9 ldr x2, [x0, #8]
031f7c04: 61c88352 mov w1, #0x1e43
031f7c08: bf930239 strb wzr, [x29, #0xa4]
031f7c0c: bf970239 strb wzr, [x29, #0xa5]
031f7c10: 840080d2 mov x4, #4
031f7c14: bf5f00b9 str wzr, [x29, #0x5c]
031f7c18: e30313aa mov x3, x19
031f7c1c: b60309a9 stp x22, x0, [x29, #0x90]
031f7c20: a1a300b9 str w1, [x29, #0xa0]
031f7c24: bf5700f9 str xzr, [x29, #0xa8]
031f7c28: e20100b4 cbz x2, #0x31f7c64
031f7c2c: 000080d2 mov x0, #0
031f7c30: 21c21494 bl #0x37284b4
031f7c34: a04f40f9 ldr x0, [x29, #0x98]
031f7c38: 000440f9 ldr x0, [x0, #8]
031f7c3c: 1f0000b9 str wzr, [x0]
031f7c40: b5970239 strb w21, [x29, #0xa5]
031f7c44: a04b40f9 ldr x0, [x29, #0x90]
031f7c48: 1f0000b9 str wzr, [x0]
031f7c4c: 20008052 mov w0, #1
031f7c50: a0930239 strb w0, [x29, #0xa4]
031f7c54: e00318aa mov x0, x24
031f7c58: 6effff97 bl #0x31f7a10
031f7c5c: e00314aa mov x0, x20
031f7c60: cfffff17 b #0x31f7b9c
031f7c64: e20316aa mov x2, x22
031f7c68: 000080d2 mov x0, #0
031f7c6c: 12c21494 bl #0x37284b4
031f7c70: f5ffff17 b #0x31f7c44
031f7c74: e13f01b0 adrp x1, #0x59f4000
031f7c78: 21dc41f9 ldr x1, [x1, #0x3b8]
031f7c7c: 21400091 add x1, x1, #0x10
031f7c80: 010000f9 str x1, [x0]
031f7c84: 547cfd17 b #0x3156dd4
