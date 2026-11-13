031eed14: ff8302d1 sub sp, sp, #0xa0
031eed18: fd7bbaa9 stp x29, x30, [sp, #-0x60]!
031eed1c: fd030091 mov x29, sp
031eed20: f35301a9 stp x19, x20, [sp, #0x10]
031eed24: b4830391 add x20, x29, #0xe0
031eed28: f55b02a9 stp x21, x22, [sp, #0x20]
031eed2c: b5030391 add x21, x29, #0xc0
031eed30: f30300aa mov x19, x0
031eed34: e10314aa mov x1, x20
031eed38: e00315aa mov x0, x21
031eed3c: f76303a9 stp x23, x24, [sp, #0x30]
031eed40: f96b04a9 stp x25, x26, [sp, #0x40]
031eed44: fb7305a9 stp x27, x28, [sp, #0x50]
031eed48: bf070179 strh wzr, [x29, #0x82]
031eed4c: c8f70e94 bl #0x35acc6c
031eed50: 77424039 ldrb w23, [x19, #0x10]
031eed54: b95b4ea9 ldp x25, x22, [x29, #0xe0]
031eed58: fb03172a mov w27, w23
031eed5c: b94700f9 str x25, [x29, #0x88]
031eed60: f7120035 cbnz w23, #0x31eefbc
031eed64: e00315aa mov x0, x21
031eed68: bb830291 add x27, x29, #0xa0
031eed6c: fa988252 mov w26, #0x14c7
031eed70: 1ee1f397 bl #0x2ee71e8
031eed74: bf6700f9 str xzr, [x29, #0xc8]
031eed78: ca75dc97 bl #0x290c4a0
031eed7c: f80300aa mov x24, x0
031eed80: cd75dc97 bl #0x290c4b4
031eed84: b8030ea9 stp x24, x0, [x29, #0xe0]
031eed88: e1031baa mov x1, x27
031eed8c: e00314aa mov x0, x20
031eed90: bfd30339 strb wzr, [x29, #0xf4]
031eed94: 38008052 mov w24, #1
031eed98: bfd70339 strb wzr, [x29, #0xf5]
031eed9c: bfa300b9 str wzr, [x29, #0xa0]
031eeda0: baf300b9 str w26, [x29, #0xf0]
031eeda4: bf7f00f9 str xzr, [x29, #0xf8]
031eeda8: b9ffff97 bl #0x31eec8c
031eedac: e00314aa mov x0, x20
031eedb0: aaffff97 bl #0x31eec58
031eedb4: e00315aa mov x0, x21
031eedb8: 28ffff97 bl #0x31eea58
031eedbc: bf7f0aa9 stp xzr, xzr, [x29, #0xa0]
031eedc0: 601a40b9 ldr w0, [x19, #0x18]
031eedc4: e10314aa mov x1, x20
031eedc8: bf5b00f9 str xzr, [x29, #0xb0]
031eedcc: b8031429 stp w24, w0, [x29, #0xa0]
031eedd0: a0b300b9 str w0, [x29, #0xb0]
031eedd4: a0030491 add x0, x29, #0x100
031eedd8: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
031eeddc: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
031eede0: 1f7c00a9 stp xzr, xzr, [x0]
031eede4: e0031baa mov x0, x27
031eede8: bfbb00b9 str wzr, [x29, #0xb8]
031eedec: bf1301b9 str wzr, [x29, #0x110]
031eedf0: 97ea0e94 bl #0x35a984c
031eedf4: a01341b9 ldr w0, [x29, #0x110]
031eedf8: 60120035 cbnz w0, #0x31ef044
031eedfc: a00f41b9 ldr w0, [x29, #0x10c]
031eee00: 020494d2 mov x2, #0xa020
031eee04: 01008052 mov w1, #0
031eee08: 9c008052 mov w28, #4
031eee0c: a07f00b9 str w0, [x29, #0x7c]
031eee10: e00314aa mov x0, x20
031eee14: d63e0053 uxth w22, w22
031eee18: 82989497 bl #0x1715020 ; memset@plt
031eee1c: bf6300f9 str xzr, [x29, #0xc0]
031eee20: 86028052 mov w6, #0x14
031eee24: 601a40b9 ldr w0, [x19, #0x18]
031eee28: a17f40b9 ldr w1, [x29, #0x7c]
031eee2c: 25078052 mov w5, #0x39
031eee30: a01b1c29 stp w0, w6, [x29, #0xe0]
031eee34: 00a593d2 mov x0, #0x9d28
031eee38: a003008b add x0, x29, x0
031eee3c: 021994d2 mov x2, #0xa0c8
031eee40: 831a94d2 mov x3, #0xa0d4
031eee44: a57b00b9 str w5, [x29, #0x78]
031eee48: 44008052 mov w4, #2
031eee4c: bfcb00b9 str wzr, [x29, #0xc8]
031eee50: 010000b9 str w1, [x0]
031eee54: 81a593d2 mov x1, #0x9d2c
031eee58: a003018b add x0, x29, x1
031eee5c: e10315aa mov x1, x21
031eee60: a6930d29 stp w6, w4, [x29, #0x6c]
031eee64: 050000b9 str w5, [x0]
031eee68: a003028b add x0, x29, x2
031eee6c: 851994d2 mov x5, #0xa0cc
031eee70: 18000039 strb w24, [x0]
031eee74: a003038b add x0, x29, x3
031eee78: 1c0000b9 str w28, [x0]
031eee7c: a003058b add x0, x29, x5
031eee80: 040000b9 str w4, [x0]
031eee84: e00314aa mov x0, x20
031eee88: f1e90e94 bl #0x35a964c
031eee8c: a10b5829 ldp w1, w2, [x29, #0xc0]
031eee90: e3031c2a mov w3, w28
031eee94: e00313aa mov x0, x19
031eee98: fbfeff97 bl #0x31eea84
031eee9c: fc03002a mov w28, w0
031eeea0: e00314aa mov x0, x20
031eeea4: 020494d2 mov x2, #0xa020
031eeea8: 01008052 mov w1, #0
031eeeac: 5d989497 bl #0x1715020 ; memset@plt
031eeeb0: bf6300f9 str xzr, [x29, #0xc0]
031eeeb4: a6934d29 ldp w6, w4, [x29, #0x6c]
031eeeb8: 87a593d2 mov x7, #0x9d2c
031eeebc: 601a40b9 ldr w0, [x19, #0x18]
031eeec0: 081994d2 mov x8, #0xa0c8
031eeec4: a5074f29 ldp w5, w1, [x29, #0x78]
031eeec8: a01b1c29 stp w0, w6, [x29, #0xe0]
031eeecc: 06a593d2 mov x6, #0x9d28
031eeed0: 891a94d2 mov x9, #0xa0d4
031eeed4: a003068b add x0, x29, x6
031eeed8: 03018052 mov w3, #8
031eeedc: 8a1994d2 mov x10, #0xa0cc
031eeee0: bfcb00b9 str wzr, [x29, #0xc8]
031eeee4: a37f00b9 str w3, [x29, #0x7c]
031eeee8: 010000b9 str w1, [x0]
031eeeec: a003078b add x0, x29, x7
031eeef0: e10315aa mov x1, x21
031eeef4: 050000b9 str w5, [x0]
031eeef8: a003088b add x0, x29, x8
031eeefc: 18000039 strb w24, [x0]
031eef00: a003098b add x0, x29, x9
031eef04: 030000b9 str w3, [x0]
031eef08: a0030a8b add x0, x29, x10
031eef0c: 040000b9 str w4, [x0]
031eef10: e00314aa mov x0, x20
031eef14: cee90e94 bl #0x35a964c
031eef18: a37f40b9 ldr w3, [x29, #0x7c]
031eef1c: e00313aa mov x0, x19
031eef20: a10b5829 ldp w1, w2, [x29, #0xc0]
031eef24: d8feff97 bl #0x31eea84
031eef28: a07f00b9 str w0, [x29, #0x7c]
031eef2c: e00315aa mov x0, x21
031eef30: aee0f397 bl #0x2ee71e8
031eef34: bf6700f9 str xzr, [x29, #0xc8]
031eef38: 5a75dc97 bl #0x290c4a0
031eef3c: a03b00f9 str x0, [x29, #0x70]
031eef40: 5d75dc97 bl #0x290c4b4
031eef44: b8a300b9 str w24, [x29, #0xa0]
031eef48: a13b40f9 ldr x1, [x29, #0x70]
031eef4c: b8230291 add x24, x29, #0x88
031eef50: baf300b9 str w26, [x29, #0xf0]
031eef54: ba0b0291 add x26, x29, #0x82
031eef58: a1030ea9 stp x1, x0, [x29, #0xe0]
031eef5c: e1031baa mov x1, x27
031eef60: e00314aa mov x0, x20
031eef64: bfd30339 strb wzr, [x29, #0xf4]
031eef68: bfd70339 strb wzr, [x29, #0xf5]
031eef6c: bf7f00f9 str xzr, [x29, #0xf8]
031eef70: 47ffff97 bl #0x31eec8c
031eef74: e00314aa mov x0, x20
031eef78: 38ffff97 bl #0x31eec58
031eef7c: e00315aa mov x0, x21
031eef80: b6feff97 bl #0x31eea58
031eef84: a27f40b9 ldr w2, [x29, #0x7c]
031eef88: 40ce0090 adrp x0, #0x4bb6000
031eef8c: e1031c2a mov w1, w28
031eef90: 00481391 add x0, x0, #0x4d2
031eef94: 50da1494 bl #0x37258d4
031eef98: 613a4079 ldrh w1, [x19, #0x1c]
031eef9c: e403162a mov w4, w22
031eefa0: e3031aaa mov x3, x26
031eefa4: e20318aa mov x2, x24
031eefa8: e00313aa mov x0, x19
031eefac: 0dffff97 bl #0x31eebe0
031eefb0: 1f1c0072 tst w0, #0xff
031eefb4: 61070054 b.ne #0x31ef0a0
031eefb8: 3b008052 mov w27, #1
031eefbc: a0030491 add x0, x29, #0x100
031eefc0: bf7f0ea9 stp xzr, xzr, [x29, #0xe0]
031eefc4: bf7f0fa9 stp xzr, xzr, [x29, #0xf0]
031eefc8: bf8b00f9 str xzr, [x29, #0x110]
031eefcc: 1f7c00a9 stp xzr, xzr, [x0]
031eefd0: 80008052 mov w0, #4
031eefd4: a0e300b9 str w0, [x29, #0xe0]
031eefd8: a0028052 mov w0, #0x15
031eefdc: a0eb00b9 str w0, [x29, #0xe8]
031eefe0: 170a0034 cbz w23, #0x31ef120
031eefe4: 60424039 ldrb w0, [x19, #0x10]
031eefe8: 00000052 eor w0, w0, #1
031eefec: 7f03006a tst w27, w0
031eeff0: 80090054 b.eq #0x31ef120
031eeff4: a04740f9 ldr x0, [x29, #0x88]
031eeff8: b97b00f9 str x25, [x29, #0xf0]
031eeffc: 190019cb sub x25, x0, x25
031ef000: 20ce00f0 adrp x0, #0x4bb6000
031ef004: 00ac1391 add x0, x0, #0x4eb
031ef008: b97f00f9 str x25, [x29, #0xf8]
031ef00c: 32da1494 bl #0x37258d4
031ef010: bfc300b9 str wzr, [x29, #0xc0]
031ef014: e10315aa mov x1, x21
031ef018: e00314aa mov x0, x20
031ef01c: c4f50e94 bl #0x35ac72c
031ef020: f35341a9 ldp x19, x20, [sp, #0x10]
031ef024: f55b42a9 ldp x21, x22, [sp, #0x20]
031ef028: f76343a9 ldp x23, x24, [sp, #0x30]
031ef02c: f96b44a9 ldp x25, x26, [sp, #0x40]
031ef030: fb7345a9 ldp x27, x28, [sp, #0x50]
031ef034: fd7bc6a8 ldp x29, x30, [sp], #0x60
031ef038: ff2b4091 add sp, sp, #0xa, lsl #12
031ef03c: ff830291 add sp, sp, #0xa0
031ef040: c0035fd6 ret 
031ef044: b6430291 add x22, x29, #0x90
031ef048: e00316aa mov x0, x22
031ef04c: 67e0f397 bl #0x2ee71e8
031ef050: bf4f00f9 str xzr, [x29, #0x98]
031ef054: 1375dc97 bl #0x290c4a0
031ef058: fb0300aa mov x27, x0
031ef05c: 1675dc97 bl #0x290c4b4
031ef060: bb030ca9 stp x27, x0, [x29, #0xc0]
031ef064: a1130291 add x1, x29, #0x84
031ef068: e00315aa mov x0, x21
031ef06c: bf530339 strb wzr, [x29, #0xd4]
031ef070: fb03172a mov w27, w23
031ef074: bf570339 strb wzr, [x29, #0xd5]
031ef078: f703182a mov w23, w24
031ef07c: b88700b9 str w24, [x29, #0x84]
031ef080: bad300b9 str w26, [x29, #0xd0]
031ef084: bf6f00f9 str xzr, [x29, #0xd8]
031ef088: 01ffff97 bl #0x31eec8c
031ef08c: e00315aa mov x0, x21
031ef090: f2feff97 bl #0x31eec58
031ef094: e00316aa mov x0, x22
031ef098: 70feff97 bl #0x31eea58
031ef09c: c8ffff17 b #0x31eefbc
031ef0a0: 617a4039 ldrb w1, [x19, #0x1e]
031ef0a4: e403162a mov w4, w22
031ef0a8: e3031aaa mov x3, x26
031ef0ac: e20318aa mov x2, x24
031ef0b0: e00313aa mov x0, x19
031ef0b4: dafeff97 bl #0x31eec1c
031ef0b8: 1f1c0072 tst w0, #0xff
031ef0bc: e0f7ff54 b.eq #0x31eefb8
031ef0c0: 617e4039 ldrb w1, [x19, #0x1f]
031ef0c4: e403162a mov w4, w22
031ef0c8: e3031aaa mov x3, x26
031ef0cc: e20318aa mov x2, x24
031ef0d0: e00313aa mov x0, x19
031ef0d4: d2feff97 bl #0x31eec1c
031ef0d8: 1f1c0072 tst w0, #0xff
031ef0dc: e0f6ff54 b.eq #0x31eefb8
031ef0e0: e403162a mov w4, w22
031ef0e4: e3031aaa mov x3, x26
031ef0e8: e20318aa mov x2, x24
031ef0ec: e1031c2a mov w1, w28
031ef0f0: e00313aa mov x0, x19
031ef0f4: adfeff97 bl #0x31eeba8
031ef0f8: 1b1c0053 uxtb w27, w0
031ef0fc: fbf5ff34 cbz w27, #0x31eefb8
031ef100: a17f40b9 ldr w1, [x29, #0x7c]
031ef104: e403162a mov w4, w22
031ef108: e3031aaa mov x3, x26
031ef10c: e20318aa mov x2, x24
031ef110: e00313aa mov x0, x19
031ef114: a5feff97 bl #0x31eeba8
031ef118: 171c0053 uxtb w23, w0
031ef11c: a8ffff17 b #0x31eefbc
031ef120: 20008052 mov w0, #1
031ef124: a0ef00b9 str w0, [x29, #0xec]
031ef128: 20ce00f0 adrp x0, #0x4bb6000
031ef12c: 00041491 add x0, x0, #0x501
031ef130: b7ffff17 b #0x31ef00c
031ef134: 614201b0 adrp x1, #0x5a3c000
031ef138: 212040f9 ldr x1, [x1, #0x40]
031ef13c: 21400091 add x1, x1, #0x10
031ef140: 010000f9 str x1, [x0]
031ef144: 249ffd17 b #0x3156dd4
