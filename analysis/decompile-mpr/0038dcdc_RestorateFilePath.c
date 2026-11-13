// sidb::RestorateFilePath
// Ghidra address: 0038dcdc

/* sidb::RestorateFilePath(sidb::fileStructure const*, char, unsigned int, char*, unsigned int) */

undefined8
sidb::RestorateFilePath(fileStructure *param_1,char param_2,uint param_3,char *param_4,uint param_5)

{
  uint uVar1;
  ushort uVar2;
  char cVar3;
  ulong uVar4;
  fileStructure *pfVar5;
  ulong uVar6;
  
  if (param_4 == (char *)0x0) {
    return 0x407;
  }
  cVar3 = headerStructure::IsTrueBitmap((headerStructure *)param_1,param_3);
  if ((cVar3 != '\0') &&
     (uVar4 = (ulong)(param_3 * *(int *)(param_1 + 0x30)),
     ((byte)param_1[uVar4 + 0x10000] & 0xf) == 1)) {
    uVar6 = 0;
    if (param_2 != '\0') {
      *param_4 = param_2;
      uVar6 = 2;
      param_4[1] = ':';
    }
    while( true ) {
      pfVar5 = param_1 + uVar4 + 0x10000;
      if (param_3 == 0xffffffff) {
        param_4[uVar6] = '\0';
        return 0;
      }
      cVar3 = headerStructure::IsTrueBitmap((headerStructure *)param_1,param_3);
      if (cVar3 == '\0') {
        return 0x406;
      }
      if (((byte)*pfVar5 & 0xf) != 1) {
        return 0x406;
      }
      uVar2 = *(ushort *)(pfVar5 + 8);
      if (param_5 <= (uint)(uVar2 >> 1) + (int)uVar6) break;
      uVar1 = *(uint *)(param_1 + 0x34);
      uVar4 = CalcChecksum((uchar *)pfVar5,uVar1);
      if ((uint)*(ushort *)(pfVar5 + uVar1) !=
          ((int)uVar4 + (int)(uVar4 / 0xfff1) * -0xfff1 & 0xffffU)) {
        return 0x406;
      }
      strncpy(param_4 + uVar6,(char *)(pfVar5 + 10),(ulong)(uVar2 >> 1));
      param_3 = *(uint *)(pfVar5 + 4);
      uVar6 = (ulong)((int)uVar6 + (uint)(*(ushort *)(pfVar5 + 8) >> 1));
      uVar4 = (ulong)(param_3 * *(int *)(param_1 + 0x30));
    }
    *param_4 = '\0';
  }
  return 0x406;
}

