034f3ba0: ff0301d1 sub sp, sp, #0x40
034f3ba4: fd7bbca9 stp x29, x30, [sp, #-0x40]!
034f3ba8: fd030091 mov x29, sp
034f3bac: f55b02a9 stp x21, x22, [sp, #0x20]
034f3bb0: f50300aa mov x21, x0
034f3bb4: 20008052 mov w0, #1
034f3bb8: f35301a9 stp x19, x20, [sp, #0x10]
034f3bbc: bf7f04a9 stp xzr, xzr, [x29, #0x40]
034f3bc0: b3830191 add x19, x29, #0x60
034f3bc4: a04300b9 str w0, [x29, #0x40]
034f3bc8: b4030191 add x20, x29, #0x40
034f3bcc: a02240b9 ldr w0, [x21, #0x20]
034f3bd0: e10313aa mov x1, x19
034f3bd4: bf2b00f9 str xzr, [x29, #0x50]
034f3bd8: a04700b9 str w0, [x29, #0x44]
034f3bdc: a05300b9 str w0, [x29, #0x50]
034f3be0: e00314aa mov x0, x20
034f3be4: f76303a9 stp x23, x24, [sp, #0x30]
034f3be8: bf7f06a9 stp xzr, xzr, [x29, #0x60]
034f3bec: bf7f07a9 stp xzr, xzr, [x29, #0x70]
034f3bf0: bf7f08a9 stp xzr, xzr, [x29, #0x80]
034f3bf4: bf5b00b9 str wzr, [x29, #0x58]
034f3bf8: bf9300b9 str wzr, [x29, #0x90]
034f3bfc: 14d70294 bl #0x35a984c
034f3c00: a09340b9 ldr w0, [x29, #0x90]
034f3c04: 20060035 cbnz w0, #0x34f3cc8
034f3c08: e00313aa mov x0, x19
034f3c0c: 020494d2 mov x2, #0xa020
034f3c10: 01008052 mov w1, #0
034f3c14: b68f40b9 ldr w22, [x29, #0x8c]
034f3c18: 02858897 bl #0x1715020 ; memset@plt
034f3c1c: bf2300f9 str xzr, [x29, #0x40]
034f3c20: 809593d2 mov x0, #0x9cac
034f3c24: 029593d2 mov x2, #0x9ca8
034f3c28: a103008b add x1, x29, x0
034f3c2c: a02240b9 ldr w0, [x21, #0x20]
034f3c30: bf4b00b9 str wzr, [x29, #0x48]
034f3c34: a06300b9 str w0, [x29, #0x60]
034f3c38: 00028052 mov w0, #0x10
034f3c3c: a06700b9 str w0, [x29, #0x64]
034f3c40: e0378352 mov w0, #0x19bf
034f3c44: a06b00b9 str w0, [x29, #0x68]
034f3c48: 80018052 mov w0, #0xc
034f3c4c: a06f00b9 str w0, [x29, #0x6c]
034f3c50: a003028b add x0, x29, x2
034f3c54: 160000b9 str w22, [x0]
034f3c58: 20078052 mov w0, #0x39
034f3c5c: 16008052 mov w22, #0
034f3c60: 200000b9 str w0, [x1]
034f3c64: 807a8352 mov w0, #0x1bd4
034f3c68: 58c7e797 bl #0x2ee59c8
034f3c6c: 030f94d2 mov x3, #0xa078
034f3c70: a103038b add x1, x29, x3
034f3c74: 20000039 strb w0, [x1]
034f3c78: e10314aa mov x1, x20
034f3c7c: e00313aa mov x0, x19
034f3c80: 73d60294 bl #0x35a964c
034f3c84: b7634829 ldp w23, w24, [x29, #0x40]
034f3c88: df02186b cmp w22, w24
034f3c8c: 80030054 b.eq #0x34f3cfc
034f3c90: e10314aa mov x1, x20
034f3c94: e00313aa mov x0, x19
034f3c98: b75b0c29 stp w23, w22, [x29, #0x60]
034f3c9c: d6060011 add w22, w22, #1
034f3ca0: bf4300b9 str wzr, [x29, #0x40]
034f3ca4: bad60294 bl #0x35a978c
034f3ca8: a02240b9 ldr w0, [x21, #0x20]
034f3cac: e10314aa mov x1, x20
034f3cb0: a06300b9 str w0, [x29, #0x60]
034f3cb4: a04340b9 ldr w0, [x29, #0x40]
034f3cb8: a06700b9 str w0, [x29, #0x64]
034f3cbc: e00313aa mov x0, x19
034f3cc0: e3d50294 bl #0x35a944c
034f3cc4: f1ffff17 b #0x34f3c88
034f3cc8: 21b700f0 adrp x1, #0x4bda000
034f3ccc: 20b600b0 adrp x0, #0x4bb8000
034f3cd0: 21603a91 add x1, x1, #0xe98
034f3cd4: 00101491 add x0, x0, #0x504
034f3cd8: 020c8052 mov w2, #0x60
034f3cdc: fec60894 bl #0x37258d4
034f3ce0: f35341a9 ldp x19, x20, [sp, #0x10]
034f3ce4: f55b42a9 ldp x21, x22, [sp, #0x20]
034f3ce8: f76343a9 ldp x23, x24, [sp, #0x30]
034f3cec: fd7bc4a8 ldp x29, x30, [sp], #0x40
034f3cf0: ff2b4091 add sp, sp, #0xa, lsl #12
034f3cf4: ff030191 add sp, sp, #0x40
034f3cf8: c0035fd6 ret 
034f3cfc: a02240b9 ldr w0, [x21, #0x20]
034f3d00: e10313aa mov x1, x19
034f3d04: bf6300b9 str wzr, [x29, #0x60]
034f3d08: a04300b9 str w0, [x29, #0x40]
034f3d0c: e00314aa mov x0, x20
034f3d10: cfd20294 bl #0x35a884c
034f3d14: f3ffff17 b #0x34f3ce0
034f3d18: ff4f40d1 sub sp, sp, #0x13, lsl #12
034f3d1c: 20008052 mov w0, #1
034f3d20: ffc331d1 sub sp, sp, #0xc70
034f3d24: 0a9293d2 mov x10, #0x9c90
034f3d28: 0b9493d2 mov x11, #0x9ca0
034f3d2c: 0c9693d2 mov x12, #0x9cb0
034f3d30: 0d9893d2 mov x13, #0x9cc0
034f3d34: 099293d2 mov x9, #0x9c90
