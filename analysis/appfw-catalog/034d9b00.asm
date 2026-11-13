034d9b00: ff2b40d1 sub sp, sp, #0xa, lsl #12
034d9b04: ff8303d1 sub sp, sp, #0xe0
034d9b08: fd7bbca9 stp x29, x30, [sp, #-0x40]!
034d9b0c: fd030091 mov x29, sp
034d9b10: f35301a9 stp x19, x20, [sp, #0x10]
034d9b14: f30300aa mov x19, x0
034d9b18: f55b02a9 stp x21, x22, [sp, #0x20]
034d9b1c: f71b00f9 str x23, [sp, #0x30]
034d9b20: 1f4800f9 str xzr, [x0, #0x90]
034d9b24: 00004339 ldrb w0, [x0, #0xc0]
034d9b28: 80200034 cbz w0, #0x34d9f38
034d9b2c: b6c30191 add x22, x29, #0x70
034d9b30: 821180d2 mov x2, #0x8c
034d9b34: e00316aa mov x0, x22
034d9b38: 01008052 mov w1, #0
034d9b3c: b5430191 add x21, x29, #0x50
034d9b40: b4030491 add x20, x29, #0x100
034d9b44: 37ed8897 bl #0x1715020 ; memset@plt
034d9b48: bf430139 strb wzr, [x29, #0x50]
034d9b4c: 60de4aa9 ldp x0, x23, [x19, #0xa8]
034d9b50: e10315aa mov x1, x21
034d9b54: a08300f9 str x0, [x29, #0x100]
034d9b58: e00314aa mov x0, x20
034d9b5c: 2c340394 bl #0x35a6c0c
034d9b60: bfab00f9 str xzr, [x29, #0x150]
034d9b64: a1030491 add x1, x29, #0x100
034d9b68: a0434139 ldrb w0, [x29, #0x50]
034d9b6c: a0430139 strb w0, [x29, #0x50]
034d9b70: e00315aa mov x0, x21
034d9b74: 3f7c00a9 stp xzr, xzr, [x1]
034d9b78: a1430491 add x1, x29, #0x110
034d9b7c: 3f7c00a9 stp xzr, xzr, [x1]
034d9b80: a1830491 add x1, x29, #0x120
034d9b84: 3f7c00a9 stp xzr, xzr, [x1]
034d9b88: a1c30491 add x1, x29, #0x130
034d9b8c: 3f7c00a9 stp xzr, xzr, [x1]
034d9b90: a1030591 add x1, x29, #0x140
034d9b94: 3f7c00a9 stp xzr, xzr, [x1]
034d9b98: e10314aa mov x1, x20
034d9b9c: 2c340394 bl #0x35a6c4c
034d9ba0: bf2b00f9 str xzr, [x29, #0x50]
034d9ba4: a1530491 add x1, x29, #0x114
034d9ba8: a0e30191 add x0, x29, #0x78
034d9bac: 220c40a9 ldp x2, x3, [x1]
034d9bb0: 020c00a9 stp x2, x3, [x0]
034d9bb4: 220c41a9 ldp x2, x3, [x1, #0x10]
034d9bb8: 020c01a9 stp x2, x3, [x0, #0x10]
034d9bbc: 220c42a9 ldp x2, x3, [x1, #0x20]
034d9bc0: 020c02a9 stp x2, x3, [x0, #0x20]
034d9bc4: 220c43a9 ldp x2, x3, [x1, #0x30]
034d9bc8: e10314aa mov x1, x20
034d9bcc: 020c03a9 stp x2, x3, [x0, #0x30]
034d9bd0: a0030491 add x0, x29, #0x100
034d9bd4: bf8b00f9 str xzr, [x29, #0x110]
034d9bd8: bf1b01b9 str wzr, [x29, #0x118]
034d9bdc: 1f7c00a9 stp xzr, xzr, [x0]
034d9be0: 60a640b9 ldr w0, [x19, #0xa4]
034d9be4: a05300b9 str w0, [x29, #0x50]
034d9be8: e00315aa mov x0, x21
034d9bec: 883f0394 bl #0x35a9a0c
034d9bf0: 643640f9 ldr x4, [x19, #0x68]
034d9bf4: 031280d2 mov x3, #0x90
034d9bf8: a0230491 add x0, x29, #0x108
034d9bfc: 614640b9 ldr w1, [x19, #0x44]
034d9c00: 9f3c02f1 cmp x4, #0x8f
034d9c04: 634a00f9 str x3, [x19, #0x90]
034d9c08: 061c40a9 ldp x6, x7, [x0]
034d9c0c: 69050054 b.ls #0x34d9cb8
034d9c10: 603e40f9 ldr x0, [x19, #0x78]
034d9c14: 820c8052 mov w2, #0x64
034d9c18: 211c0012 and w1, w1, #0xff
034d9c1c: b73b00f9 str x23, [x29, #0x70]
034d9c20: a1fb00b9 str w1, [x29, #0xf8]
034d9c24: e10316aa mov x1, x22
034d9c28: 020000b9 str w2, [x0]
034d9c2c: a2e30291 add x2, x29, #0xb8
034d9c30: 603e40f9 ldr x0, [x19, #0x78]
034d9c34: 461c00a9 stp x6, x7, [x2]
034d9c38: 821180d2 mov x2, #0x8c
034d9c3c: 00100091 add x0, x0, #4
034d9c40: 58ed8897 bl #0x17151a0 ; memcpy@plt
034d9c44: bf7f05a9 stp xzr, xzr, [x29, #0x50]
034d9c48: 20008052 mov w0, #1
034d9c4c: 61a640b9 ldr w1, [x19, #0xa4]
034d9c50: bf6b00b9 str wzr, [x29, #0x68]
034d9c54: a0070a29 stp w0, w1, [x29, #0x50]
034d9c58: a1030c29 stp w1, w0, [x29, #0x60]
034d9c5c: e10314aa mov x1, x20
034d9c60: a0ab0139 strb w0, [x29, #0x6a]
034d9c64: e00315aa mov x0, x21
034d9c68: 293f0394 bl #0x35a990c
034d9c6c: a33341b9 ldr w3, [x29, #0x130]
034d9c70: 23030034 cbz w3, #0x34d9cd4
034d9c74: 7f600371 cmp w3, #0xd8
034d9c78: e1b70090 adrp x1, #0x4bd5000
034d9c7c: a1090054 b.ne #0x34d9db0
034d9c80: c0b700d0 adrp x0, #0x4bd3000
034d9c84: 21802391 add x1, x1, #0x8e0
034d9c88: 00383391 add x0, x0, #0xcce
034d9c8c: c2208052 mov w2, #0x106
034d9c90: 112f0994 bl #0x37258d4
034d9c94: 20038452 mov w0, #0x2019
034d9c98: 60460179 strh w0, [x19, #0xa2]
034d9c9c: f35341a9 ldp x19, x20, [sp, #0x10]
034d9ca0: f55b42a9 ldp x21, x22, [sp, #0x20]
034d9ca4: f71b40f9 ldr x23, [sp, #0x30]
034d9ca8: fd7bc4a8 ldp x29, x30, [sp], #0x40
034d9cac: ff2b4091 add sp, sp, #0xa, lsl #12
034d9cb0: ff830391 add sp, sp, #0xe0
034d9cb4: c0035fd6 ret 
034d9cb8: 621d8052 mov w2, #0xeb
034d9cbc: e1b70090 adrp x1, #0x4bd5000
034d9cc0: c0b700d0 adrp x0, #0x4bd3000
034d9cc4: 21802391 add x1, x1, #0x8e0
034d9cc8: 00e82991 add x0, x0, #0xa7a
034d9ccc: 022f0994 bl #0x37258d4
034d9cd0: 3d000014 b #0x34d9dc4
034d9cd4: 771e40f9 ldr x23, [x19, #0x38]
034d9cd8: b62f41b9 ldr w22, [x29, #0x12c]
034d9cdc: 970700b5 cbnz x23, #0x34d9dcc
034d9ce0: 60a640b9 ldr w0, [x19, #0xa4]
034d9ce4: 03a993d2 mov x3, #0x9d48
034d9ce8: 84a993d2 mov x4, #0x9d4c
034d9cec: e10315aa mov x1, x21
034d9cf0: a00301b9 str w0, [x29, #0x100]
034d9cf4: 20038052 mov w0, #0x19
034d9cf8: a00701b9 str w0, [x29, #0x104]
034d9cfc: a003038b add x0, x29, x3
034d9d00: 160000b9 str w22, [x0]
034d9d04: a003048b add x0, x29, x4
034d9d08: 160000b9 str w22, [x0]
034d9d0c: e00314aa mov x0, x20
034d9d10: 4f3e0394 bl #0x35a964c
034d9d14: a35b40b9 ldr w3, [x29, #0x58]
034d9d18: c2238052 mov w2, #0x11e
034d9d1c: 830d0035 cbnz w3, #0x34d9ecc
034d9d20: a05340b9 ldr w0, [x29, #0x50]
034d9d24: e10314aa mov x1, x20
034d9d28: bf0301b9 str wzr, [x29, #0x100]
034d9d2c: 60c600b9 str w0, [x19, #0xc4]
034d9d30: a05300b9 str w0, [x29, #0x50]
034d9d34: e00315aa mov x0, x21
034d9d38: a53e0394 bl #0x35a97cc
034d9d3c: a00341b9 ldr w0, [x29, #0x100]
034d9d40: 60ca00b9 str w0, [x19, #0xc8]
034d9d44: 604240b9 ldr w0, [x19, #0x40]
034d9d48: 61ca40b9 ldr w1, [x19, #0xc8]
034d9d4c: 3f00006b cmp w1, w0
034d9d50: 49000054 b.ls #0x34d9d58
034d9d54: 60ca00b9 str w0, [x19, #0xc8]
034d9d58: 604a40f9 ldr x0, [x19, #0x90]
034d9d5c: 643640f9 ldr x4, [x19, #0x68]
034d9d60: 03100091 add x3, x0, #4
034d9d64: 7f0004eb cmp x3, x4
034d9d68: 634a00f9 str x3, [x19, #0x90]
034d9d6c: 280e0054 b.hi #0x34d9f30
034d9d70: 613e40f9 ldr x1, [x19, #0x78]
034d9d74: 62ca40b9 ldr w2, [x19, #0xc8]
034d9d78: 226820b8 str w2, [x1, x0]
034d9d7c: 604a40f9 ldr x0, [x19, #0x90]
034d9d80: 604600f9 str x0, [x19, #0x88]
034d9d84: 60ca40b9 ldr w0, [x19, #0xc8]
034d9d88: a0f8ff34 cbz w0, #0x34d9c9c
034d9d8c: e00313aa mov x0, x19
034d9d90: eefaff97 bl #0x34d8948
034d9d94: 614640f9 ldr x1, [x19, #0x88]
034d9d98: 2000008b add x0, x1, x0
034d9d9c: 604600f9 str x0, [x19, #0x88]
034d9da0: e00313aa mov x0, x19
034d9da4: f9fdff97 bl #0x34d9588
034d9da8: 7f020339 strb wzr, [x19, #0xc0]
034d9dac: bcffff17 b #0x34d9c9c
034d9db0: c0b700d0 adrp x0, #0x4bd3000
034d9db4: 21802391 add x1, x1, #0x8e0
034d9db8: 003c3491 add x0, x0, #0xd0f
034d9dbc: 82218052 mov w2, #0x10c
034d9dc0: c52e0994 bl #0x37258d4
034d9dc4: a0038452 mov w0, #0x201d
034d9dc8: b4ffff17 b #0x34d9c98
034d9dcc: 604a40b9 ldr w0, [x19, #0x48]
034d9dd0: 1f0440f2 tst x0, #3
034d9dd4: e1010054 b.ne #0x34d9e10
034d9dd8: e00314aa mov x0, x20
034d9ddc: bf0301b9 str wzr, [x29, #0x100]
034d9de0: 57f50a94 bl #0x379733c
034d9de4: a1078279 ldrsh x1, [x29, #0x102]
034d9de8: a0038279 ldrsh x0, [x29, #0x100]
034d9dec: 0000018b add x0, x0, x1
034d9df0: 014c9dd2 mov x1, #0xea60
034d9df4: 007c019b mul x0, x0, x1
034d9df8: 1f0000f1 cmp x0, #0
034d9dfc: 0000178b add x0, x0, x23
034d9e00: 2d070054 b.le #0x34d9ee4
034d9e04: ff0200eb cmp x23, x0
034d9e08: 88070054 b.hi #0x34d9ef8
034d9e0c: f70300aa mov x23, x0
034d9e10: e10317aa mov x1, x23
034d9e14: e00313aa mov x0, x19
034d9e18: b8fbff97 bl #0x34d8cf8
034d9e1c: 027c50d3 ubfx x2, x0, #0x10, #0x10
034d9e20: a2870079 strh w2, [x29, #0x42]
034d9e24: 02bc60d3 ubfx x2, x0, #0x20, #0x10
034d9e28: a28b0079 strh w2, [x29, #0x44]
034d9e2c: 033c0053 uxth w3, w0
034d9e30: 02fc70d3 lsr x2, x0, #0x30
034d9e34: a1930079 strh w1, [x29, #0x48]
034d9e38: 7fac2171 cmp w3, #0x86b
034d9e3c: 217c50d3 ubfx x1, x1, #0x10, #0x10
034d9e40: a0830079 strh w0, [x29, #0x40]
034d9e44: a28f0079 strh w2, [x29, #0x46]
034d9e48: a1970079 strh w1, [x29, #0x4a]
034d9e4c: 2c060054 b.gt #0x34d9f10
034d9e50: e00314aa mov x0, x20
034d9e54: 020494d2 mov x2, #0xa020
034d9e58: 01008052 mov w1, #0
034d9e5c: 71ec8897 bl #0x1715020 ; memset@plt
034d9e60: bf2b00f9 str xzr, [x29, #0x50]
034d9e64: 60a640b9 ldr w0, [x19, #0xa4]
034d9e68: 81a993d2 mov x1, #0x9d4c
034d9e6c: bf5b00b9 str wzr, [x29, #0x58]
034d9e70: a00301b9 str w0, [x29, #0x100]
034d9e74: 60038052 mov w0, #0x1b
034d9e78: a00701b9 str w0, [x29, #0x104]
034d9e7c: a02340f9 ldr x0, [x29, #0x40]
034d9e80: a08700f9 str x0, [x29, #0x108]
034d9e84: a04b40b9 ldr w0, [x29, #0x48]
034d9e88: a01301b9 str w0, [x29, #0x110]
034d9e8c: 00a993d2 mov x0, #0x9d48
034d9e90: a003008b add x0, x29, x0
034d9e94: 160000b9 str w22, [x0]
034d9e98: a003018b add x0, x29, x1
034d9e9c: 160000b9 str w22, [x0]
034d9ea0: 807a8352 mov w0, #0x1bd4
034d9ea4: c92ee897 bl #0x2ee59c8
034d9ea8: 022394d2 mov x2, #0xa118
034d9eac: a103028b add x1, x29, x2
034d9eb0: 20000039 strb w0, [x1]
034d9eb4: e10315aa mov x1, x21
034d9eb8: e00314aa mov x0, x20
034d9ebc: e43d0394 bl #0x35a964c
034d9ec0: a35b40b9 ldr w3, [x29, #0x58]
034d9ec4: e3010034 cbz w3, #0x34d9f00
034d9ec8: 822b8052 mov w2, #0x15c
034d9ecc: e1b70090 adrp x1, #0x4bd5000
034d9ed0: e0b70090 adrp x0, #0x4bd5000
034d9ed4: 21802391 add x1, x1, #0x8e0
034d9ed8: 00341e91 add x0, x0, #0x78d
034d9edc: 7e2e0994 bl #0x37258d4
034d9ee0: 6dffff17 b #0x34d9c94
034d9ee4: 40f9ff54 b.eq #0x34d9e0c
034d9ee8: ff0200eb cmp x23, x0
034d9eec: 02f9ff54 b.hs #0x34d9e0c
034d9ef0: 170080d2 mov x23, #0
034d9ef4: c7ffff17 b #0x34d9e10
034d9ef8: 17008092 mov x23, #-1
034d9efc: c5ffff17 b #0x34d9e10
034d9f00: a05340b9 ldr w0, [x29, #0x50]
034d9f04: 60c600b9 str w0, [x19, #0xc4]
034d9f08: a05740b9 ldr w0, [x29, #0x54]
034d9f0c: 8dffff17 b #0x34d9d40
034d9f10: e1b70090 adrp x1, #0x4bd5000
034d9f14: e0b70090 adrp x0, #0x4bd5000
034d9f18: 21802391 add x1, x1, #0x8e0
034d9f1c: 00981e91 add x0, x0, #0x7a6
034d9f20: 022d8052 mov w2, #0x168
034d9f24: 6c2e0994 bl #0x37258d4
034d9f28: 7fca00b9 str wzr, [x19, #0xc8]
034d9f2c: 86ffff17 b #0x34d9d44
034d9f30: e22f8052 mov w2, #0x17f
034d9f34: 62ffff17 b #0x34d9cbc
034d9f38: 61de41f9 ldr x1, [x19, #0x3b8]
034d9f3c: 010200b4 cbz x1, #0x34d9f7c
034d9f40: 74da41f9 ldr x20, [x19, #0x3b0]
034d9f44: 63420391 add x3, x19, #0xd0
034d9f48: 753640f9 ldr x21, [x19, #0x68]
034d9f4c: 940201cb sub x20, x20, x1
034d9f50: 603e40f9 ldr x0, [x19, #0x78]
034d9f54: 9f0215eb cmp x20, x21
034d9f58: 88010054 b.hi #0x34d9f88
034d9f5c: e20314aa mov x2, x20
034d9f60: 6100018b add x1, x3, x1
034d9f64: 8fec8897 bl #0x17151a0 ; memcpy@plt
034d9f68: 7fda01f9 str xzr, [x19, #0x3b0]
034d9f6c: 604a40f9 ldr x0, [x19, #0x90]
034d9f70: 7fde01f9 str xzr, [x19, #0x3b8]
034d9f74: 1400148b add x20, x0, x20
034d9f78: 744a00f9 str x20, [x19, #0x90]
034d9f7c: e00313aa mov x0, x19
034d9f80: 82fdff97 bl #0x34d9588
034d9f84: 46ffff17 b #0x34d9c9c
034d9f88: e20315aa mov x2, x21
034d9f8c: 6100018b add x1, x3, x1
034d9f90: 84ec8897 bl #0x17151a0 ; memcpy@plt
034d9f94: 604a40f9 ldr x0, [x19, #0x90]
034d9f98: 0000158b add x0, x0, x21
034d9f9c: 604a00f9 str x0, [x19, #0x90]
034d9fa0: 60de41f9 ldr x0, [x19, #0x3b8]
034d9fa4: 1500158b add x21, x0, x21
034d9fa8: 75de01f9 str x21, [x19, #0x3b8]
034d9fac: 3cffff17 b #0x34d9c9c
034d9fb0: ff0301d1 sub sp, sp, #0x40
034d9fb4: 220f8052 mov w2, #0x79
034d9fb8: fd7b01a9 stp x29, x30, [sp, #0x10]
034d9fbc: fd430091 add x29, sp, #0x10
034d9fc0: f35302a9 stp x19, x20, [sp, #0x20]
034d9fc4: f40300aa mov x20, x0
034d9fc8: 202840b9 ldr w0, [x1, #0x28]
034d9fcc: f30301aa mov x19, x1
034d9fd0: f55b03a9 stp x21, x22, [sp, #0x30]
034d9fd4: f5b70090 adrp x21, #0x4bd5000
034d9fd8: 360040b9 ldr w22, [x1]
034d9fdc: b5422891 add x21, x21, #0xa10
034d9fe0: e00300b9 str w0, [sp]
034d9fe4: c0b700d0 adrp x0, #0x4bd3000
034d9fe8: e303162a mov w3, w22
034d9fec: 00a42a91 add x0, x0, #0xaa9
034d9ff0: 648e40b8 ldr w4, [x19, #8]!
034d9ff4: 251841a9 ldp x5, x6, [x1, #0x10]
034d9ff8: 271040f9 ldr x7, [x1, #0x20]
034d9ffc: e10315aa mov x1, x21
034da000: 352e0994 bl #0x37258d4
034da004: 620e40a9 ldp x2, x3, [x19]
034da008: 611240f9 ldr x1, [x19, #0x20]
034da00c: 820e05a9 stp x2, x3, [x20, #0x50]
034da010: 620e41a9 ldp x2, x3, [x19, #0x10]
034da014: 813a00f9 str x1, [x20, #0x70]
034da018: 820e06a9 stp x2, x3, [x20, #0x60]
034da01c: 36010034 cbz w22, #0x34da040
034da020: df060071 cmp w22, #1
034da024: 60020054 b.eq #0x34da070
034da028: c0b700f0 adrp x0, #0x4bd5000
034da02c: e20315aa mov x2, x21
034da030: 00082091 add x0, x0, #0x802
034da034: a1128052 mov w1, #0x95
034da038: a9c60594 bl #0x364badc
034da03c: 08000014 b #0x34da05c
034da040: 80ba40b9 ldr w0, [x20, #0xb8]
034da044: 1f040071 cmp w0, #1
034da048: a0000054 b.eq #0x34da05c
034da04c: e00314aa mov x0, x20
034da050: acfeff97 bl #0x34d9b00
034da054: e00314aa mov x0, x20
034da058: b5faff97 bl #0x34d8b2c
034da05c: bf030091 mov sp, x29
034da060: f35341a9 ldp x19, x20, [sp, #0x10]
034da064: f55b42a9 ldp x21, x22, [sp, #0x20]
034da068: fd7bc3a8 ldp x29, x30, [sp], #0x30
034da06c: c0035fd6 ret 
034da070: e00314aa mov x0, x20
034da074: effaff97 bl #0x34d8c30
034da078: f9ffff17 b #0x34da05c
