// FUN_00292b14
// Ghidra address: 00292b14

int FUN_00292b14(undefined8 param_1,int *param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  
  if (*param_2 == 0) {
    *param_2 = 1;
    sVar4 = strlen(param_3);
    if ((int)sVar4 == 0x40) {
      lVar5 = 0;
      do {
        iVar2 = FUN_001b8088(*param_3);
        iVar3 = FUN_001b8088(param_3[1]);
        if (iVar2 == -1 || iVar3 == -1) {
          iVar2 = 2;
          goto LAB_00292ba4;
        }
        lVar1 = lVar5 + 1;
        param_3 = param_3 + 2;
        *(char *)((long)param_2 + lVar5 + 4) = (char)iVar3 + (char)iVar2 * '\x10';
        lVar5 = lVar1;
      } while (lVar1 != 0x20);
      goto LAB_00292b8c;
    }
    iVar2 = 4;
  }
  else {
    iVar2 = 3;
  }
LAB_00292ba4:
  *param_2 = iVar2;
LAB_00292b8c:
  return *param_2;
}

