// sidb::RestorateArrayBinaryRecordForLoad
// Ghidra address: 0038e50c

/* sidb::RestorateArrayBinaryRecordForLoad(sidb::fileStructure const*, unsigned int, unsigned int,
   unsigned char*, unsigned int*) */

undefined8
sidb::RestorateArrayBinaryRecordForLoad
          (fileStructure *param_1,uint param_2,uint param_3,uchar *param_4,uint *param_5)

{
  fileStructure fVar1;
  char cVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_5 != (uint *)0x0 && param_4 != (uchar *)0x0) {
    cVar2 = headerStructure::IsTrueBitmap((headerStructure *)param_1,param_2);
    uVar3 = 0x406;
    if (cVar2 != '\0') {
      uVar4 = (ulong)(param_2 * *(int *)(param_1 + 0x30));
      fVar1 = param_1[uVar4 + 0x10005];
      *param_5 = (uint)(byte)fVar1;
      memcpy(param_4,param_1 + (ulong)((byte)param_1[uVar4 + 0x10005] * param_3) + uVar4 + 0x1000c,
             (ulong)(byte)fVar1);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x407;
}

