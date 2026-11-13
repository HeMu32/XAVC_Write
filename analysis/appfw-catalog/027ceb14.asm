027ceb14: ffc31ed1 sub sp, sp, #0x7b0
027ceb18: fd7bbca9 stp x29, x30, [sp, #-0x40]!
027ceb1c: fd030091 mov x29, sp
027ceb20: f35301a9 stp x19, x20, [sp, #0x10]
027ceb24: b3830191 add x19, x29, #0x60
027ceb28: f40300aa mov x20, x0
027ceb2c: e00313aa mov x0, x19
027ceb30: f55b02a9 stp x21, x22, [sp, #0x20]
027ceb34: f503012a mov w21, w1
027ceb38: f76303a9 stp x23, x24, [sp, #0x30]
027ceb3c: ab611c94 bl #0x2ee71e8
027ceb40: f5a40494 bl #0x28f7f14
027ceb44: 160040b9 ldr w22, [x0]
027ceb48: e00313aa mov x0, x19
027ceb4c: de601c94 bl #0x2ee6ec4
027ceb50: df02156b cmp w22, w21
027ceb54: 80000054 b.eq #0x27ceb64
027ceb58: e00314aa mov x0, x20
027ceb5c: 01008052 mov w1, #0
027ceb60: 9ee7f897 bl #0x26089d8
027ceb64: b4430191 add x20, x29, #0x50
027ceb68: b6330191 add x22, x29, #0x4c
027ceb6c: e00314aa mov x0, x20
027ceb70: b5a0c197 bl #0x1836e44
027ceb74: b72f40f9 ldr x23, [x29, #0x58]
027ceb78: e7a40494 bl #0x28f7f14
027ceb7c: f80300aa mov x24, x0
027ceb80: eaa40494 bl #0x28f7f28
027ceb84: 020440f9 ldr x2, [x0, #8]
027ceb88: e1d88052 mov w1, #0x6c7
027ceb8c: bfd30139 strb wzr, [x29, #0x74]
027ceb90: bfd70139 strb wzr, [x29, #0x75]
027ceb94: 840080d2 mov x4, #4
027ceb98: b54f00b9 str w21, [x29, #0x4c]
027ceb9c: e30316aa mov x3, x22
027ceba0: b80306a9 stp x24, x0, [x29, #0x60]
027ceba4: a17300b9 str w1, [x29, #0x70]
027ceba8: b73f00f9 str x23, [x29, #0x78]
027cebac: e20500b4 cbz x2, #0x27cec68
027cebb0: e00317aa mov x0, x23
027cebb4: 40663d94 bl #0x37284b4
027cebb8: a03740f9 ldr x0, [x29, #0x68]
027cebbc: 000440f9 ldr x0, [x0, #8]
027cebc0: 150000b9 str w21, [x0]
027cebc4: 20008052 mov w0, #1
027cebc8: a0d70139 strb w0, [x29, #0x75]
027cebcc: a03340f9 ldr x0, [x29, #0x60]
027cebd0: 150000b9 str w21, [x0]
027cebd4: 20008052 mov w0, #1
027cebd8: 35008052 mov w21, #1
027cebdc: a0d30139 strb w0, [x29, #0x74]
027cebe0: e00313aa mov x0, x19
027cebe4: de8ad397 bl #0x1cb175c
027cebe8: e00314aa mov x0, x20
027cebec: 9fa0c197 bl #0x1836e68
027cebf0: e00314aa mov x0, x20
027cebf4: 94a0c197 bl #0x1836e44
027cebf8: a02f40f9 ldr x0, [x29, #0x58]
027cebfc: e80313aa mov x8, x19
027cec00: cba8f697 bl #0x2578f2c
027cec04: b54f00b9 str w21, [x29, #0x4c]
027cec08: e10316aa mov x1, x22
027cec0c: e00313aa mov x0, x19
027cec10: 0fb9f997 bl #0x263d04c
027cec14: e00313aa mov x0, x19
027cec18: 16d4f797 bl #0x25c3c70
027cec1c: e00314aa mov x0, x20
027cec20: 92a0c197 bl #0x1836e68
027cec24: b5470139 strb w21, [x29, #0x51]
027cec28: e10314aa mov x1, x20
027cec2c: e00313aa mov x0, x19
027cec30: bf430139 strb wzr, [x29, #0x50]
027cec34: bf4b0139 strb wzr, [x29, #0x52]
027cec38: bf5700b9 str wzr, [x29, #0x54]
027cec3c: 3eccf697 bl #0x2581d34
027cec40: e00313aa mov x0, x19
027cec44: 701e3794 bl #0x3596604
027cec48: e00313aa mov x0, x19
027cec4c: adffff97 bl #0x27ceb00
027cec50: f35341a9 ldp x19, x20, [sp, #0x10]
027cec54: f55b42a9 ldp x21, x22, [sp, #0x20]
027cec58: f76343a9 ldp x23, x24, [sp, #0x30]
027cec5c: fd7bc4a8 ldp x29, x30, [sp], #0x40
027cec60: ffc31e91 add sp, sp, #0x7b0
027cec64: c0035fd6 ret 
027cec68: e20318aa mov x2, x24
027cec6c: e00317aa mov x0, x23
027cec70: 11663d94 bl #0x37284b4
027cec74: d6ffff17 b #0x27cebcc
