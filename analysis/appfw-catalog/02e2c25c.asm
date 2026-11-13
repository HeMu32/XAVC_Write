02e2c25c: 00020034 cbz w0, #0x2e2c29c
02e2c260: e103002a mov w1, w0
02e2c264: 80008052 mov w0, #4
02e2c268: 3f040071 cmp w1, #1
02e2c26c: c0010054 b.eq #0x2e2c2a4
02e2c270: fd7bbfa9 stp x29, x30, [sp, #-0x10]!
02e2c274: 42e700d0 adrp x2, #0x4b16000
02e2c278: 20e600b0 adrp x0, #0x4af1000
02e2c27c: 42002a91 add x2, x2, #0xa80
02e2c280: fd030091 mov x29, sp
02e2c284: 00842b91 add x0, x0, #0xae1
02e2c288: 01758352 mov w1, #0x1ba8
02e2c28c: 147e2094 bl #0x364badc
02e2c290: 00008052 mov w0, #0
02e2c294: fd7bc1a8 ldp x29, x30, [sp], #0x10
02e2c298: c0035fd6 ret 
02e2c29c: 20008052 mov w0, #1
02e2c2a0: c0035fd6 ret 
02e2c2a4: c0035fd6 ret 
02e2c2a8: 1f740071 cmp w0, #0x1d
02e2c2ac: 28020054 b.hi #0x2e2c2f0
02e2c2b0: 220080d2 mov x2, #1
02e2c2b4: 03808fd2 mov x3, #0x7c00
02e2c2b8: 4120c09a lsl x1, x2, x0
02e2c2bc: 23e0a7f2 movk x3, #0x3f01, lsl #16
02e2c2c0: 3f0003ea tst x1, x3
02e2c2c4: 40008052 mov w0, #2
02e2c2c8: a1020054 b.ne #0x2e2c31c
02e2c2cc: e30380d2 mov x3, #0x1f
02e2c2d0: 00008052 mov w0, #0
02e2c2d4: c31fa0f2 movk x3, #0xfe, lsl #16
02e2c2d8: 3f0003ea tst x1, x3
02e2c2dc: 01020054 b.ne #0x2e2c31c
02e2c2e0: e003022a mov w0, w2
02e2c2e4: 027c90d2 mov x2, #0x83e0
02e2c2e8: 3f0002ea tst x1, x2
02e2c2ec: 81010054 b.ne #0x2e2c31c
