01c14cec: fd7bbea9 stp x29, x30, [sp, #-0x20]!
01c14cf0: a1ee01d0 adrp x1, #0x59ea000
01c14cf4: fd030091 mov x29, sp
01c14cf8: a2830091 add x2, x29, #0x20
01c14cfc: 21d444f9 ldr x1, [x1, #0x9a8]
01c14d00: 21400091 add x1, x1, #0x10
01c14d04: 418c1ff8 str x1, [x2, #-8]!
01c14d08: e103002a mov w1, w0
01c14d0c: e00302aa mov x0, x2
01c14d10: 7bbcff97 bl #0x1c03efc
01c14d14: fd7bc2a8 ldp x29, x30, [sp], #0x20
01c14d18: c0035fd6 ret 
