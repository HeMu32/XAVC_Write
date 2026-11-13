// sidb::RestorateArrayBinaryRecord
// Ghidra address: 0038e5ac

/* sidb::RestorateArrayBinaryRecord(sidb::fileStructure const*, sidb::BinaryRecordType, unsigned
   int, unsigned int, unsigned char*, unsigned int) */

undefined8
sidb::RestorateArrayBinaryRecord
          (headerStructure *param_1,uint param_2,uint param_3,int param_4,void *param_5,uint param_6
          )

{
  uint uVar1;
  headerStructure hVar2;
  char cVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  uVar5 = 0x407;
  if (param_5 != (void *)0x0) {
    cVar3 = headerStructure::IsTrueBitmap(param_1,param_3);
    uVar5 = 0x406;
    if (cVar3 != '\0') {
      param_3 = param_3 * *(int *)(param_1 + 0x30);
      uVar1 = *(uint *)(param_1 + 0x34);
      uVar4 = CalcChecksum((uchar *)(param_1 + (ulong)param_3 + 0x10000),uVar1);
      if ((((uint)*(ushort *)(param_1 + (ulong)uVar1 + (ulong)param_3 + 0x10000) ==
            ((int)uVar4 + (int)(uVar4 / 0xfff1) * -0xfff1 & 0xffffU)) &&
          (((byte)param_1[(ulong)param_3 + 0x10000] & 0xf) == 3)) &&
         ((byte)param_1[(ulong)param_3 + 0x10004] == param_2)) {
        hVar2 = param_1[(ulong)param_3 + 0x10005];
        if ((byte)hVar2 == param_6) {
          uVar5 = 0;
          memcpy(param_5,param_1 + (ulong)((uint)(byte)hVar2 * param_4) + (ulong)param_3 + 0x1000c,
                 (ulong)(byte)hVar2);
        }
      }
    }
  }
  return uVar5;
}

