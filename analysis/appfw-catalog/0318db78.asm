0318db78: fd7bb1a9 stp x29, x30, [sp, #-0xf0]!
0318db7c: fd030091 mov x29, sp
0318db80: f76303a9 stp x23, x24, [sp, #0x30]
0318db84: b7a30191 add x23, x29, #0x68
0318db88: f35301a9 stp x19, x20, [sp, #0x10]
0318db8c: f40300aa mov x20, x0
0318db90: e00317aa mov x0, x23
0318db94: f96b04a9 stp x25, x26, [sp, #0x40]
0318db98: f55b02a9 stp x21, x22, [sp, #0x20]
0318db9c: b9e30291 add x25, x29, #0xb8
0318dba0: fb7305a9 stp x27, x28, [sp, #0x50]
0318dba4: b8e30191 add x24, x29, #0x78
0318dba8: 9065f597 bl #0x2ee71e8
0318dbac: bf3b00f9 str xzr, [x29, #0x70]
0318dbb0: a0e30191 add x0, x29, #0x78
0318dbb4: e10319aa mov x1, x25
0318dbb8: b5930191 add x21, x29, #0x64
0318dbbc: ba630291 add x26, x29, #0x98
0318dbc0: 1f7c00a9 stp xzr, xzr, [x0]
0318dbc4: a0230291 add x0, x29, #0x88
0318dbc8: 1f7c00a9 stp xzr, xzr, [x0]
0318dbcc: 801e40b9 ldr w0, [x20, #0x1c]
0318dbd0: a07b00b9 str w0, [x29, #0x78]
0318dbd4: 802240b9 ldr w0, [x20, #0x20]
0318dbd8: a07f00b9 str w0, [x29, #0x7c]
0318dbdc: 802640b9 ldr w0, [x20, #0x24]
0318dbe0: a08300b9 str w0, [x29, #0x80]
0318dbe4: 801640b9 ldr w0, [x20, #0x14]
0318dbe8: a08b00b9 str w0, [x29, #0x88]
0318dbec: e00318aa mov x0, x24
0318dbf0: 276f1094 bl #0x35a988c
0318dbf4: b33b40f9 ldr x19, [x29, #0x70]
0318dbf8: a0eb40b9 ldr w0, [x29, #0xe8]
0318dbfc: 200b0035 cbnz w0, #0x318dd60
0318dc00: bbe740b9 ldr w27, [x29, #0xe4]
0318dc04: b253de97 bl #0x2922acc
0318dc08: fc0300aa mov x28, x0
0318dc0c: b553de97 bl #0x2922ae0
0318dc10: a1aa8452 mov w1, #0x2555
0318dc14: 020440f9 ldr x2, [x0, #8]
0318dc18: b6c340b9 ldr w22, [x29, #0xc0]
0318dc1c: 840080d2 mov x4, #4
0318dc20: bfb30239 strb wzr, [x29, #0xac]
0318dc24: e30315aa mov x3, x21
0318dc28: bfb70239 strb wzr, [x29, #0xad]
0318dc2c: b66700b9 str w22, [x29, #0x64]
0318dc30: bc8309a9 stp x28, x0, [x29, #0x98]
0318dc34: a1ab00b9 str w1, [x29, #0xa8]
0318dc38: b35b00f9 str x19, [x29, #0xb0]
0318dc3c: 220800b4 cbz x2, #0x318dd40
0318dc40: e00313aa mov x0, x19
0318dc44: 1c6a1694 bl #0x37284b4
0318dc48: a05340f9 ldr x0, [x29, #0xa0]
0318dc4c: 000440f9 ldr x0, [x0, #8]
0318dc50: 160000b9 str w22, [x0]
0318dc54: 20008052 mov w0, #1
0318dc58: a0b70239 strb w0, [x29, #0xad]
0318dc5c: a04f40f9 ldr x0, [x29, #0x98]
0318dc60: 35008052 mov w21, #1
0318dc64: 160000b9 str w22, [x0]
0318dc68: e0031aaa mov x0, x26
0318dc6c: b5b30239 strb w21, [x29, #0xac]
0318dc70: b5ffff97 bl #0x318db44
0318dc74: e403152a mov w4, w21
0318dc78: 80a20e91 add x0, x20, #0x3a8
0318dc7c: e1031b2a mov w1, w27
0318dc80: 03008052 mov w3, #0
0318dc84: 22078052 mov w2, #0x39
0318dc88: ec1eff97 bl #0x3155838
0318dc8c: a09b00b9 str w0, [x29, #0x98]
0318dc90: 00fc60d3 lsr x0, x0, #0x20
0318dc94: f30301aa mov x19, x1
0318dc98: a1a300b9 str w1, [x29, #0xa0]
0318dc9c: b43b40f9 ldr x20, [x29, #0x70]
0318dca0: a09f00b9 str w0, [x29, #0x9c]
0318dca4: 8053de97 bl #0x2922aa4
0318dca8: f60300aa mov x22, x0
0318dcac: 8353de97 bl #0x2922ab8
0318dcb0: 81aa8452 mov w1, #0x2554
0318dcb4: 020440f9 ldr x2, [x0, #8]
0318dcb8: bf330339 strb wzr, [x29, #0xcc]
0318dcbc: 840080d2 mov x4, #4
0318dcc0: bf370339 strb wzr, [x29, #0xcd]
0318dcc4: e30318aa mov x3, x24
0318dcc8: b37b00b9 str w19, [x29, #0x78]
0318dccc: b6830ba9 stp x22, x0, [x29, #0xb8]
0318dcd0: a1cb00b9 str w1, [x29, #0xc8]
0318dcd4: b46b00f9 str x20, [x29, #0xd0]
0318dcd8: c20300b4 cbz x2, #0x318dd50
0318dcdc: e00314aa mov x0, x20
0318dce0: f5691694 bl #0x37284b4
0318dce4: a06340f9 ldr x0, [x29, #0xc0]
0318dce8: 000440f9 ldr x0, [x0, #8]
0318dcec: 130000b9 str w19, [x0]
0318dcf0: b5370339 strb w21, [x29, #0xcd]
0318dcf4: a05f40f9 ldr x0, [x29, #0xb8]
0318dcf8: 130000b9 str w19, [x0]
0318dcfc: 20008052 mov w0, #1
0318dd00: a0330339 strb w0, [x29, #0xcc]
0318dd04: e00319aa mov x0, x25
0318dd08: 82ffff97 bl #0x318db10
0318dd0c: c0d000f0 adrp x0, #0x4ba8000
0318dd10: e103132a mov w1, w19
0318dd14: 00541691 add x0, x0, #0x595
0318dd18: ef5e1694 bl #0x37258d4
0318dd1c: e00317aa mov x0, x23
0318dd20: 6dffff97 bl #0x318dad4
0318dd24: f35341a9 ldp x19, x20, [sp, #0x10]
0318dd28: f55b42a9 ldp x21, x22, [sp, #0x20]
0318dd2c: f76343a9 ldp x23, x24, [sp, #0x30]
0318dd30: f96b44a9 ldp x25, x26, [sp, #0x40]
0318dd34: fb7345a9 ldp x27, x28, [sp, #0x50]
0318dd38: fd7bcfa8 ldp x29, x30, [sp], #0xf0
0318dd3c: c0035fd6 ret 
0318dd40: e2031caa mov x2, x28
0318dd44: e00313aa mov x0, x19
0318dd48: db691694 bl #0x37284b4
0318dd4c: c4ffff17 b #0x318dc5c
0318dd50: e20316aa mov x2, x22
0318dd54: e00314aa mov x0, x20
0318dd58: d7691694 bl #0x37284b4
0318dd5c: e6ffff17 b #0x318dcf4
0318dd60: 5b53de97 bl #0x2922acc
0318dd64: f40300aa mov x20, x0
0318dd68: 5e53de97 bl #0x2922ae0
0318dd6c: 020440f9 ldr x2, [x0, #8]
0318dd70: a1aa8452 mov w1, #0x2555
0318dd74: bfb30239 strb wzr, [x29, #0xac]
0318dd78: bfb70239 strb wzr, [x29, #0xad]
0318dd7c: 840080d2 mov x4, #4
0318dd80: bf6700b9 str wzr, [x29, #0x64]
0318dd84: e30315aa mov x3, x21
0318dd88: b48309a9 stp x20, x0, [x29, #0x98]
0318dd8c: a1ab00b9 str w1, [x29, #0xa8]
0318dd90: b35b00f9 str x19, [x29, #0xb0]
0318dd94: e20100b4 cbz x2, #0x318ddd0
0318dd98: e00313aa mov x0, x19
0318dd9c: c6691694 bl #0x37284b4
0318dda0: a05340f9 ldr x0, [x29, #0xa0]
0318dda4: 000440f9 ldr x0, [x0, #8]
0318dda8: 1f0000b9 str wzr, [x0]
0318ddac: 20008052 mov w0, #1
0318ddb0: a0b70239 strb w0, [x29, #0xad]
0318ddb4: a04f40f9 ldr x0, [x29, #0x98]
0318ddb8: 1f0000b9 str wzr, [x0]
0318ddbc: 20008052 mov w0, #1
0318ddc0: a0b30239 strb w0, [x29, #0xac]
0318ddc4: e0031aaa mov x0, x26
0318ddc8: 5fffff97 bl #0x318db44
0318ddcc: d4ffff17 b #0x318dd1c
0318ddd0: e20314aa mov x2, x20
0318ddd4: e00313aa mov x0, x19
0318ddd8: b7691694 bl #0x37284b4
0318dddc: f6ffff17 b #0x318ddb4
0318dde0: a2000034 cbz w2, #0x318ddf4
0318dde4: 5f040071 cmp w2, #1
0318dde8: a0000054 b.eq #0x318ddfc
0318ddec: 00008052 mov w0, #0
0318ddf0: c0035fd6 ret 
0318ddf4: a14101f0 adrp x1, #0x59c4000
0318ddf8: 21002d91 add x1, x1, #0xb40
0318ddfc: 010000f9 str x1, [x0]
0318de00: fbffff17 b #0x318ddec
0318de04: a2000034 cbz w2, #0x318de18
0318de08: 5f040071 cmp w2, #1
0318de0c: a0000054 b.eq #0x318de20
0318de10: 00008052 mov w0, #0
0318de14: c0035fd6 ret 
0318de18: a14101f0 adrp x1, #0x59c4000
0318de1c: 21c02c91 add x1, x1, #0xb30
0318de20: 010000f9 str x1, [x0]
0318de24: fbffff17 b #0x318de10
