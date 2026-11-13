// FUN_002869d8
// Ghidra address: 002869d8

undefined8 FUN_002869d8(long param_1,long param_2,char *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  size_t sVar6;
  undefined8 uVar7;
  ulong __n;
  int iVar8;
  undefined1 auStack_1000 [4096];
  
  pcVar3 = strstr((char *)(param_2 + 1),"</Properties>");
  if (pcVar3 == (char *)0x0) {
    return 0x65;
  }
  pcVar4 = strchr(pcVar3,0x3e);
  pcVar3 = pcVar4 + 1;
  memset(auStack_1000,0,0x1000);
  pcVar5 = strstr(pcVar3,"<Contents>");
  if (pcVar5 == (char *)0x0) {
    sVar6 = strlen(pcVar3);
    if ((uint)sVar6 < 0x1001) {
      memcpy(auStack_1000,pcVar3,sVar6 & 0xffffffff);
      uVar2 = s_<Contents>_003d7e60._8_4_;
      *(undefined8 *)(pcVar4 + 1) = s_<Contents>_003d7e60._0_8_;
      *(undefined4 *)(pcVar4 + 9) = uVar2;
      pcVar3 = pcVar4 + 0xd;
      uVar7 = CONCAT53(s_<_Contents>_003d7e6d._8_5_,s_<_Contents>_003d7e6d._5_3_);
      *(ulong *)(pcVar4 + 0xd) = CONCAT35(s_<_Contents>_003d7e6d._5_3_,s_<_Contents>_003d7e6d._0_5_)
      ;
      *(undefined8 *)(pcVar4 + 0x12) = uVar7;
      memcpy(pcVar4 + 0x1a,auStack_1000,sVar6 & 0xffffffff);
      pcVar4 = pcVar4 + 0x1a;
      goto LAB_00286ae4;
    }
LAB_00286a64:
    uVar7 = 0x67;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xafc60);
    for (iVar8 = 0; pcVar4 = pcVar3, iVar8 != iVar1; iVar8 = iVar8 + 1) {
      if (pcVar3 == (char *)0x0) {
        pcVar4 = (char *)0x0;
        break;
      }
      pcVar4 = strstr(pcVar3,"</Material>");
      if (pcVar4 == (char *)0x0) break;
      pcVar3 = pcVar4 + 0xb;
    }
LAB_00286ae4:
    memset(auStack_1000,0,0x1000);
    if (pcVar4 != (char *)0x0) {
      pcVar4 = strstr(pcVar4,"</MediaProfile>");
      sVar6 = strlen(param_3);
      if ((0x1000 < (uint)(pcVar4 + (0xf - (long)pcVar3))) ||
         ((ulong)param_4 - (long)(pcVar4 + (0xf - param_2)) < sVar6)) goto LAB_00286a64;
      __n = (ulong)(pcVar4 + (0xf - (long)pcVar3)) & 0xffffffff;
      memcpy(auStack_1000,pcVar3,__n);
      memcpy(pcVar3,param_3,sVar6);
      memcpy(pcVar3 + sVar6,auStack_1000,__n);
    }
    uVar7 = 0;
  }
  return uVar7;
}

