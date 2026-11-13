034f3990: fd7bb6a9 stp x29, x30, [sp, #-0xa0]!
034f3994: fd030091 mov x29, sp
034f3998: f55b02a9 stp x21, x22, [sp, #0x20]
034f399c: f60300aa mov x22, x0
034f39a0: a0230191 add x0, x29, #0x48
034f39a4: f35301a9 stp x19, x20, [sp, #0x10]
034f39a8: f76303a9 stp x23, x24, [sp, #0x30]
034f39ac: b3a30191 add x19, x29, #0x68
034f39b0: bf2f00f9 str xzr, [x29, #0x58]
034f39b4: b4230191 add x20, x29, #0x48
034f39b8: 1f7c00a9 stp xzr, xzr, [x0]
034f39bc: 20008052 mov w0, #1
034f39c0: e10313aa mov x1, x19
034f39c4: bf6300b9 str wzr, [x29, #0x60]
034f39c8: a04b00b9 str w0, [x29, #0x48]
034f39cc: 15008052 mov w21, #0
034f39d0: c01640b9 ldr w0, [x22, #0x14]
034f39d4: bf9b00b9 str wzr, [x29, #0x98]
034f39d8: a04f00b9 str w0, [x29, #0x4c]
034f39dc: a05b00b9 str w0, [x29, #0x58]
034f39e0: a0a30191 add x0, x29, #0x68
034f39e4: 1f7c00a9 stp xzr, xzr, [x0]
034f39e8: a0e30191 add x0, x29, #0x78
034f39ec: 1f7c00a9 stp xzr, xzr, [x0]
034f39f0: a0230291 add x0, x29, #0x88
034f39f4: 1f7c00a9 stp xzr, xzr, [x0]
034f39f8: e00314aa mov x0, x20
034f39fc: 94d70294 bl #0x35a984c
034f3a00: b87340b9 ldr w24, [x29, #0x70]
034f3a04: b79740b9 ldr w23, [x29, #0x94]
034f3a08: bf02186b cmp w21, w24
034f3a0c: 00020054 b.eq #0x34f3a4c
034f3a10: e10314aa mov x1, x20
034f3a14: e00313aa mov x0, x19
034f3a18: b7570d29 stp w23, w21, [x29, #0x68]
034f3a1c: b5060011 add w21, w21, #1
034f3a20: bf4b00b9 str wzr, [x29, #0x48]
034f3a24: 5ad70294 bl #0x35a978c
034f3a28: bf7300b9 str wzr, [x29, #0x70]
034f3a2c: c01640b9 ldr w0, [x22, #0x14]
034f3a30: e10314aa mov x1, x20
034f3a34: a06b00b9 str w0, [x29, #0x68]
034f3a38: a04b40b9 ldr w0, [x29, #0x48]
034f3a3c: a06f00b9 str w0, [x29, #0x6c]
034f3a40: e00313aa mov x0, x19
034f3a44: 52d60294 bl #0x35a938c
034f3a48: f0ffff17 b #0x34f3a08
034f3a4c: c01640b9 ldr w0, [x22, #0x14]
034f3a50: e10313aa mov x1, x19
034f3a54: bf6b00b9 str wzr, [x29, #0x68]
034f3a58: a04b00b9 str w0, [x29, #0x48]
034f3a5c: e00314aa mov x0, x20
034f3a60: 7bd30294 bl #0x35a884c
034f3a64: bf3f00f9 str xzr, [x29, #0x78]
034f3a68: a0a30191 add x0, x29, #0x68
034f3a6c: bf8300b9 str wzr, [x29, #0x80]
034f3a70: 1f7c00a9 stp xzr, xzr, [x0]
034f3a74: e01f8052 mov w0, #0xff
034f3a78: 0020a072 movk w0, #0x100, lsl #16
034f3a7c: a06b00b9 str w0, [x29, #0x68]
034f3a80: e00313aa mov x0, x19
034f3a84: 0df0c097 bl #0x252fab8
034f3a88: f35341a9 ldp x19, x20, [sp, #0x10]
034f3a8c: f55b42a9 ldp x21, x22, [sp, #0x20]
034f3a90: f76343a9 ldp x23, x24, [sp, #0x30]
034f3a94: fd7bcaa8 ldp x29, x30, [sp], #0xa0
034f3a98: c0035fd6 ret 
034f3a9c: 212a01d0 adrp x1, #0x5a39000
034f3aa0: 215c47f9 ldr x1, [x1, #0xeb8]
034f3aa4: 21400091 add x1, x1, #0x10
034f3aa8: 010000f9 str x1, [x0]
034f3aac: ca8cf117 b #0x3156dd4
