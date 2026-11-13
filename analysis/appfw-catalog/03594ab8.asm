03594ab8: fd7bbea9 stp x29, x30, [sp, #-0x20]!
03594abc: fd030091 mov x29, sp
03594ac0: a0430091 add x0, x29, #0x10
03594ac4: a2070229 stp w2, w1, [x29, #0x10]
03594ac8: a1630091 add x1, x29, #0x18
03594acc: 20530094 bl #0x35a974c
03594ad0: a01b40b9 ldr w0, [x29, #0x18]
03594ad4: fd7bc2a8 ldp x29, x30, [sp], #0x20
03594ad8: 1f040031 cmn w0, #1
03594adc: e0079f1a cset w0, ne
03594ae0: c0035fd6 ret 
