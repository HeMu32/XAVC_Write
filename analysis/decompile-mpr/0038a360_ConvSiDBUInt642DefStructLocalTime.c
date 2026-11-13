// sidb::ConvSiDBUInt642DefStructLocalTime
// Ghidra address: 0038a360

/* sidb::ConvSiDBUInt642DefStructLocalTime(unsigned long, signed char, DefStruct::LocalTime*) */

undefined8 sidb::ConvSiDBUInt642DefStructLocalTime(ulong param_1,char param_2,short *param_3)

{
  if (param_3 != (short *)0x0) {
    *param_3 = param_2 * 0x1e;
    param_3[1] = ((ushort)(uint)(param_1 >> 0x24) & 0xff) + 0x76c;
    *(byte *)(param_3 + 2) = (byte)(param_1 >> 0x20) & 0xf;
    *(byte *)((long)param_3 + 5) = (byte)(param_1 >> 0x1b) & 0x1f;
    *(byte *)(param_3 + 3) = (byte)(param_1 >> 0x16) & 0x1f;
    *(byte *)((long)param_3 + 7) = (byte)(param_1 >> 0x10) & 0x3f;
    *(byte *)(param_3 + 4) = (byte)(param_1 >> 10) & 0x3f;
    param_3[5] = (ushort)param_1 & 0x3ff;
    return 0;
  }
  return 0x403;
}

