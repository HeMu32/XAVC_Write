// ELF VMA 0x3594cac; Ghidra bias 0x100000

void appfw_3594cac(long param_1,undefined4 param_2,int param_3,long param_4,int param_5,uint param_6
                  ,undefined4 param_7,undefined4 *param_8,undefined1 *param_9)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int aiStack_8 [2];
  
  lVar2 = (long)param_5;
  uStack_10 = param_2;
  uStack_c = param_7;
  func_0x036a974c(&uStack_10,aiStack_8);
  if ((param_6 == 0 || param_5 == -1) || param_3 == 0) {
LAB_03694d0c:
    *param_8 = 0xffffffff;
    return;
  }
  if (aiStack_8[0] != -1) {
    *param_8 = param_7;
    return;
  }
  *param_9 = 1;
  lVar4 = lVar2;
  if (*(int *)(param_1 + 0x14) < 0) {
    do {
      if ((int)lVar4 < 0) goto LAB_03694dec;
      uVar3 = *(undefined4 *)(param_4 + lVar4 * 4);
      lVar4 = lVar4 + -1;
      cVar1 = appfw_3594ab8(param_1,uVar3,param_2);
    } while (cVar1 == '\0');
  }
  else {
    do {
      if (param_6 <= (uint)lVar4) goto LAB_03694d9c;
      uVar3 = *(undefined4 *)(param_4 + lVar4 * 4);
      lVar4 = lVar4 + 1;
      cVar1 = appfw_3594ab8(param_1,uVar3,param_2);
    } while (cVar1 == '\0');
  }
LAB_03694d80:
  func_0x038258d4(&UNK_04cf7368,param_7,uVar3);
  *param_8 = uVar3;
  return;
  while( true ) {
    uVar3 = *(undefined4 *)(param_4 + lVar2 * 4);
    lVar2 = lVar2 + 1;
    cVar1 = appfw_3594ab8(param_1,uVar3,param_2);
    if (cVar1 != '\0') break;
LAB_03694dec:
    if (param_6 <= (uint)lVar2) goto LAB_03694d0c;
  }
  goto LAB_03694d80;
  while( true ) {
    uVar3 = *(undefined4 *)(param_4 + lVar2 * 4);
    lVar2 = lVar2 + -1;
    cVar1 = appfw_3594ab8(param_1,uVar3,param_2);
    if (cVar1 != '\0') break;
LAB_03694d9c:
    if ((int)lVar2 < 0) goto LAB_03694d0c;
  }
  goto LAB_03694d80;
}

