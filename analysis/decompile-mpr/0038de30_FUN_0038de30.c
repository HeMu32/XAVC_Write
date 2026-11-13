// FUN_0038de30
// Ghidra address: 0038de30

int FUN_0038de30(fileStructure *param_1,char param_2,uint param_3,ushort param_4,ushort param_5,
                char param_6,undefined2 *param_7,int param_8,long param_9,char *param_10)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  ulong uVar6;
  char cStack_2038;
  undefined2 local_2037;
  char local_2035;
  undefined2 local_2030;
  char local_202e;
  char acStack_2020 [32];
  char acStack_2000 [4096];
  char acStack_1000 [4096];
  
  iVar2 = sidb::RestorateFilePath(param_1,param_2,param_3,acStack_2000,0x106);
  if (iVar2 == 0) {
    pcVar3 = strstr(acStack_2000,"\\YYMMDD\\");
    if (pcVar3 == (char *)0x0) {
      strncpy(acStack_1000,acStack_2000,0x106);
    }
    else {
      uVar6 = (long)pcVar3 - (long)acStack_2000;
      snprintf(acStack_2020,0x20,"%02u%02u%02u",(ulong)(uint)(int)(*(short *)(param_9 + 2) % 100),
               (long)*(char *)(param_9 + 4),(long)*(char *)(param_9 + 5));
      pcVar3 = stpncpy(acStack_1000,acStack_2000,uVar6 & 0xffffffff);
      pcVar3 = stpncpy(pcVar3,acStack_2020,6);
      iVar5 = (int)uVar6;
      stpncpy(pcVar3,acStack_2000 + (iVar5 + 8),(ulong)(0x100 - iVar5));
    }
    sVar4 = strnlen(acStack_1000,0x1000);
    uVar1 = param_8 + (int)sVar4;
    snprintf((char *)&local_2030,0x10,"%03d",(ulong)param_5);
    *(undefined2 *)(acStack_1000 + uVar1) = local_2030;
    acStack_1000[(ulong)uVar1 + 2] = local_202e;
    acStack_1000[uVar1 + 3] = param_6;
    if ((param_4 - 0x2711 & 0xffff) < 25999) {
      snprintf(&cStack_2038,5,"%c%03d",(ulong)(byte)((char)((int)(param_4 - 10000) / 1000) + 0x41),
               (ulong)(param_4 % 1000));
    }
    *(undefined2 *)(acStack_1000 + (uVar1 + 4)) = local_2037;
    acStack_1000[(ulong)(uVar1 + 4) + 2] = local_2035;
    *(undefined2 *)(acStack_1000 + (uVar1 + 0xe)) = *param_7;
    strncpy(param_10,acStack_1000,0x106);
  }
  return iVar2;
}

