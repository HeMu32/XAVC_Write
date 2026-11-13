034f3d18: ff4f40d1 sub sp, sp, #0x13, lsl #12
034f3d1c: 20008052 mov w0, #1
034f3d20: ffc331d1 sub sp, sp, #0xc70
034f3d24: 0a9293d2 mov x10, #0x9c90
034f3d28: 0b9493d2 mov x11, #0x9ca0
034f3d2c: 0c9693d2 mov x12, #0x9cb0
034f3d30: 0d9893d2 mov x13, #0x9cc0
034f3d34: 099293d2 mov x9, #0x9c90
034f3d38: fd7bbca9 stp x29, x30, [sp, #-0x40]!
034f3d3c: fd030091 mov x29, sp
034f3d40: f35301a9 stp x19, x20, [sp, #0x10]
034f3d44: b403098b add x20, x29, x9
034f3d48: f55b02a9 stp x21, x22, [sp, #0x20]
034f3d4c: b3430191 add x19, x29, #0x50
034f3d50: bf7f05a9 stp xzr, xzr, [x29, #0x50]
034f3d54: f503012a mov w21, w1
034f3d58: a0070a29 stp w0, w1, [x29, #0x50]
034f3d5c: a0030a8b add x0, x29, x10
034f3d60: f76303a9 stp x23, x24, [sp, #0x30]
034f3d64: bf3300f9 str xzr, [x29, #0x60]
034f3d68: 1f7c00a9 stp xzr, xzr, [x0]
034f3d6c: a0030b8b add x0, x29, x11
034f3d70: a16300b9 str w1, [x29, #0x60]
034f3d74: e10314aa mov x1, x20
034f3d78: bf6b00b9 str wzr, [x29, #0x68]
034f3d7c: 1f7c00a9 stp xzr, xzr, [x0]
034f3d80: a0030c8b add x0, x29, x12
034f3d84: 1f7c00a9 stp xzr, xzr, [x0]
034f3d88: a0030d8b add x0, x29, x13
034f3d8c: 1f0000b9 str wzr, [x0]
034f3d90: e00313aa mov x0, x19
034f3d94: aed60294 bl #0x35a984c
034f3d98: 0e9893d2 mov x14, #0x9cc0
034f3d9c: a0030e8b add x0, x29, x14
034f3da0: 000040b9 ldr w0, [x0]
034f3da4: e0080035 cbnz w0, #0x34f3ec0
034f3da8: 859793d2 mov x5, #0x9cbc
034f3dac: 028893d2 mov x2, #0x9c40
034f3db0: a003058b add x0, x29, x5
034f3db4: 01008052 mov w1, #0
034f3db8: 160040b9 ldr w22, [x0]
034f3dbc: e00313aa mov x0, x19
034f3dc0: 98848897 bl #0x1715020 ; memset@plt
034f3dc4: e00314aa mov x0, x20
034f3dc8: 020494d2 mov x2, #0xa020
034f3dcc: 01008052 mov w1, #0
034f3dd0: 94848897 bl #0x1715020 ; memset@plt
034f3dd4: bf2300f9 str xzr, [x29, #0x40]
034f3dd8: 069293d2 mov x6, #0x9c90
034f3ddc: 879293d2 mov x7, #0x9c94
034f3de0: a003068b add x0, x29, x6
034f3de4: a103078b add x1, x29, x7
034f3de8: 089393d2 mov x8, #0x9c98
034f3dec: 028893d2 mov x2, #0x9c40
034f3df0: bf4b00b9 str wzr, [x29, #0x48]
034f3df4: 150000b9 str w21, [x0]
034f3df8: 00028052 mov w0, #0x10
034f3dfc: 200000b9 str w0, [x1]
034f3e00: 00008352 mov w0, #0x1800
034f3e04: e10313aa mov x1, x19
034f3e08: a05300b9 str w0, [x29, #0x50]
034f3e0c: 80018052 mov w0, #0xc
034f3e10: a05700b9 str w0, [x29, #0x54]
034f3e14: a003088b add x0, x29, x8
034f3e18: e2848897 bl #0x17151a0 ; memcpy@plt
034f3e1c: a04f4091 add x0, x29, #0x13, lsl #12
034f3e20: a14f4091 add x1, x29, #0x13, lsl #12
034f3e24: 00602391 add x0, x0, #0x8d8
034f3e28: 21702391 add x1, x1, #0x8dc
034f3e2c: 160000b9 str w22, [x0]
034f3e30: 20078052 mov w0, #0x39
034f3e34: 16008052 mov w22, #0
034f3e38: 200000b9 str w0, [x1]
034f3e3c: 807a8352 mov w0, #0x1bd4
034f3e40: e2c6e797 bl #0x2ee59c8
034f3e44: a14f4091 add x1, x29, #0x13, lsl #12
034f3e48: 21a03291 add x1, x1, #0xca8
034f3e4c: 20000039 strb w0, [x1]
034f3e50: a1030191 add x1, x29, #0x40
034f3e54: e00314aa mov x0, x20
034f3e58: fdd50294 bl #0x35a964c
034f3e5c: b7634829 ldp w23, w24, [x29, #0x40]
034f3e60: df02186b cmp w22, w24
034f3e64: 80040054 b.eq #0x34f3ef4
034f3e68: 019293d2 mov x1, #0x9c90
034f3e6c: 829293d2 mov x2, #0x9c94
034f3e70: a003018b add x0, x29, x1
034f3e74: e10313aa mov x1, x19
034f3e78: bf5300b9 str wzr, [x29, #0x50]
034f3e7c: 170000b9 str w23, [x0]
034f3e80: a003028b add x0, x29, x2
034f3e84: 160000b9 str w22, [x0]
034f3e88: e00314aa mov x0, x20
034f3e8c: d6060011 add w22, w22, #1
034f3e90: 3fd60294 bl #0x35a978c
034f3e94: 039293d2 mov x3, #0x9c90
034f3e98: 849293d2 mov x4, #0x9c94
034f3e9c: a003038b add x0, x29, x3
034f3ea0: a103048b add x1, x29, x4
034f3ea4: 150000b9 str w21, [x0]
034f3ea8: a05340b9 ldr w0, [x29, #0x50]
034f3eac: 200000b9 str w0, [x1]
034f3eb0: e10313aa mov x1, x19
034f3eb4: e00314aa mov x0, x20
034f3eb8: 75d50294 bl #0x35a948c
034f3ebc: e9ffff17 b #0x34f3e60
034f3ec0: 21b700f0 adrp x1, #0x4bda000
034f3ec4: 20b600b0 adrp x0, #0x4bb8000
034f3ec8: 21c03b91 add x1, x1, #0xef0
034f3ecc: 00101491 add x0, x0, #0x504
034f3ed0: 62168052 mov w2, #0xb3
034f3ed4: 80c60894 bl #0x37258d4
034f3ed8: f35341a9 ldp x19, x20, [sp, #0x10]
034f3edc: f55b42a9 ldp x21, x22, [sp, #0x20]
034f3ee0: f76343a9 ldp x23, x24, [sp, #0x30]
034f3ee4: fd7bc4a8 ldp x29, x30, [sp], #0x40
034f3ee8: ff4f4091 add sp, sp, #0x13, lsl #12
034f3eec: ffc33191 add sp, sp, #0xc70
034f3ef0: c0035fd6 ret 
034f3ef4: 009293d2 mov x0, #0x9c90
034f3ef8: e10314aa mov x1, x20
034f3efc: a003008b add x0, x29, x0
034f3f00: b55300b9 str w21, [x29, #0x50]
034f3f04: 1f0000b9 str wzr, [x0]
034f3f08: e00313aa mov x0, x19
034f3f0c: 50d20294 bl #0x35a884c
034f3f10: f2ffff17 b #0x34f3ed8
