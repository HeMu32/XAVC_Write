// sidb::ConvDefStructLocalTime2SiDBUInt64
// Ghidra address: 001aa87c

/* sidb::ConvDefStructLocalTime2SiDBUInt64(DefStruct::LocalTime const&) */

ulong sidb::ConvDefStructLocalTime2SiDBUInt64(LocalTime *param_1)

{
  ulong uVar1;
  
  if (*(short *)(param_1 + 2) < 0x76d) {
    uVar1 = 0;
  }
  else {
    uVar1 = ((ulong)((int)*(short *)(param_1 + 2) - 0x76c) & 0xff) << 0x24;
  }
  return ((ulong)(byte)param_1[4] & 0xf) << 0x20 | ((ulong)(byte)param_1[5] & 0x1f) << 0x1b |
         ((ulong)(byte)param_1[6] & 0x1f) << 0x16 | ((ulong)(byte)param_1[7] & 0x3f) << 0x10 |
         ((ulong)(byte)param_1[8] & 0x3f) << 10 | (ulong)*(ushort *)(param_1 + 10) & 0x3ff |
         uVar1 | ((ulong)((int)*(short *)param_1 / 0x1e + 0x60) & 0xff) << 0x2c;
}

