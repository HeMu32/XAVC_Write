// FUN_0038e01c
// Ghidra address: 0038e01c

int FUN_0038e01c(fileStructure *param_1,char param_2,uint param_3,ushort param_4,int param_5,
                long param_6,char *param_7)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  undefined4 local_1030 [4];
  char acStack_1020 [32];
  char acStack_1000 [4096];
  
  iVar1 = sidb::RestorateFilePath(param_1,param_2,param_3,acStack_1000,0x106);
  if (iVar1 == 0) {
    sVar2 = strnlen(acStack_1000,0x1000);
    snprintf((char *)local_1030,0x10,"%04d",(ulong)param_4);
    *(undefined4 *)(acStack_1000 + (param_5 + (int)sVar2)) = local_1030[0];
    pcVar3 = strstr(acStack_1000,"\\YYYYMMDD\\");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strstr(acStack_1000,"\\YYYYMM\\");
      if (pcVar3 == (char *)0x0) {
        pcVar3 = strstr(acStack_1000,"\\YYYY\\");
        if (pcVar3 == (char *)0x0) {
          strncpy(param_7,acStack_1000,0x106);
          return 0;
        }
        iVar6 = 6;
        sVar2 = 4;
        snprintf(acStack_1020,0x20,"%04u",(long)*(short *)(param_6 + 2));
      }
      else {
        iVar6 = 8;
        sVar2 = 6;
        snprintf(acStack_1020,0x20,"%04u%02u",(long)*(short *)(param_6 + 2),
                 (long)*(char *)(param_6 + 4));
      }
    }
    else {
      iVar6 = 10;
      sVar2 = 8;
      snprintf(acStack_1020,0x20,"%04u%02u%02u",(long)*(short *)(param_6 + 2),
               (long)*(char *)(param_6 + 4),(long)*(char *)(param_6 + 5));
    }
    uVar5 = (long)pcVar3 - (long)acStack_1000;
    pcVar3 = stpncpy(param_7,acStack_1000,uVar5 & 0xffffffff);
    pcVar3 = stpncpy(pcVar3,acStack_1020,sVar2);
    iVar4 = (int)uVar5;
    stpncpy(pcVar3,acStack_1000 + (uint)(iVar6 + iVar4),(ulong)(uint)((0x106 - iVar4) - (int)sVar2))
    ;
  }
  return iVar1;
}

