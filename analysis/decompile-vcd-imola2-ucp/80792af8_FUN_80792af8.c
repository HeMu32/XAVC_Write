// FUN_80792af8
// Ghidra address: 80792af8

void FUN_80792af8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  if (param_4 * 2 == -6) goto LAB_80792c00;
  iVar8 = param_1 + -0x120;
  do {
    cVar1 = FUN_8079408c(1);
    if (cVar1 == '\0') {
      if (param_3 == 0) {
        FUN_80798cc0(param_1,uVar7);
      }
      else {
        FUN_80798cf4(param_1,param_2,uVar7);
      }
    }
    else {
      if (uVar7 < 6) {
        cVar3 = '\b';
        bVar4 = false;
        uVar6 = 0;
        cVar1 = '\b';
        do {
          if (cVar3 != '\0') {
            cVar3 = FUN_807941d8();
            cVar3 = cVar1 + cVar3;
            bVar4 = uVar6 == 0 && cVar3 == '\0';
          }
          pcVar5 = (char *)(param_1 + uVar7 * 0x10 + uVar6);
          uVar6 = uVar6 + 1;
          cVar2 = cVar3;
          if (cVar3 == '\0') {
            cVar2 = cVar1;
          }
          *pcVar5 = cVar2;
          cVar1 = cVar2;
        } while (uVar6 < 0x10);
      }
      else {
        cVar3 = '\b';
        bVar4 = false;
        uVar6 = 0;
        cVar1 = '\b';
        do {
          if (cVar3 != '\0') {
            cVar3 = FUN_807941d8();
            cVar3 = cVar1 + cVar3;
            bVar4 = uVar6 == 0 && cVar3 == '\0';
          }
          pcVar5 = (char *)(iVar8 + uVar6);
          uVar6 = uVar6 + 1;
          cVar2 = cVar3;
          if (cVar3 == '\0') {
            cVar2 = cVar1;
          }
          *pcVar5 = cVar2;
          cVar1 = cVar2;
        } while (uVar6 < 0x40);
      }
      if (bVar4) {
        FUN_80798c58(param_1,uVar7);
      }
    }
    uVar7 = uVar7 + 1;
    iVar8 = iVar8 + 0x40;
  } while (uVar7 < param_4 * 2 + 6U);
  while (uVar7 < 8) {
LAB_80792c00:
    if (param_3 == 0) {
      FUN_80798cc0(param_1,uVar7);
      uVar7 = uVar7 + 1;
    }
    else {
      FUN_80798cf4(param_1,param_2,uVar7);
      uVar7 = uVar7 + 1;
    }
  }
  return;
}

