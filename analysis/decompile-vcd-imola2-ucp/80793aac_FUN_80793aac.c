// FUN_80793aac
// Ghidra address: 80793aac

void FUN_80793aac(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1 + -0x120;
  iVar7 = 0;
  do {
    cVar1 = FUN_8079408c(1);
    if (cVar1 == '\0') {
      FUN_80798cc0(param_1,iVar7);
    }
    else {
      if (iVar7 < 6) {
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
          pcVar5 = (char *)(param_1 + iVar7 * 0x10 + uVar6);
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
        FUN_80798c58(param_1,iVar7);
      }
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x40;
  } while (iVar7 < 8);
  return;
}

