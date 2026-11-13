// Ghidra: 0028efa0; ELF VMA = Ghidra - 0x100000

void FUN_0028efa0(long *param_1,long param_2)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  char *__s2;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined1 auStack_80 [128];
  
  __s2 = (char *)((long)param_1 + 0x36);
  for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x15f8c); uVar5 = uVar5 + 1) {
    if (__s2[0x32] == '\0') {
      plVar4 = (long *)(param_2 + 0x288);
      for (uVar6 = 0; uVar6 < *(uint *)(param_2 + 0x284); uVar6 = uVar6 + 1) {
        lVar7 = *plVar4;
        if (*(int *)(lVar7 + 0xa8) == 1) {
          memset(auStack_80,0,0x80);
          iVar3 = (**(code **)(*param_1 + 0x1c8))(param_1,lVar7 + 0xb0,auStack_80);
          if ((iVar3 == 0) &&
             (sVar2 = FUN_0028eba0(param_1,auStack_80), *(short *)(__s2 + -2) == sVar2)) {
            if ((*(int *)(*plVar4 + 0x238) == 1) &&
               (iVar3 = strcmp((char *)(*plVar4 + 0x23c),__s2), iVar3 == 0)) {
              uVar1 = *(undefined4 *)((long)param_1 + 0xafc64);
              __s2[0x32] = '\x01';
              *(undefined4 *)(__s2 + 0x36) = uVar1;
            }
          }
        }
        plVar4 = plVar4 + 1;
      }
    }
    __s2 = __s2 + 0x44;
  }
  return;
}

