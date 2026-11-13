// sidb::ConvDefStructLocalTime2SiDBUInt64
// Ghidra address: 001b7ecc

/* sidb::ConvDefStructLocalTime2SiDBUInt64(DefStruct::LocalTime const&, unsigned long*, signed
   char*) */

undefined8
sidb::ConvDefStructLocalTime2SiDBUInt64(LocalTime *param_1,ulong *param_2,signed *param_3)

{
  short sVar1;
  ulong uVar2;
  
  if (param_2 == (ulong *)0x0 || param_3 == (signed *)0x0) {
    return 0x403;
  }
  uVar2 = 0;
  if (0x76c < *(short *)(param_1 + 2)) {
    uVar2 = ((ulong)((int)*(short *)(param_1 + 2) - 0x76c) & 0xff) << 0x24;
  }
  sVar1 = *(short *)param_1;
  *param_2 = ((ulong)(byte)param_1[4] & 0xf) << 0x20 | ((ulong)(byte)param_1[5] & 0x1f) << 0x1b |
             ((ulong)(byte)param_1[6] & 0x1f) << 0x16 | ((ulong)(byte)param_1[7] & 0x3f) << 0x10 |
             ((ulong)(byte)param_1[8] & 0x3f) << 10 | (ulong)*(ushort *)(param_1 + 10) & 0x3ff |
             uVar2;
  *param_3 = SUB41((int)sVar1 / 0x1e,0);
  return 0;
}

