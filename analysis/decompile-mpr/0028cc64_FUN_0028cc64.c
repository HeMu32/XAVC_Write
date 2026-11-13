// FUN_0028cc64
// Ghidra address: 0028cc64

int FUN_0028cc64(long param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint *puVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint *puVar8;
  
  if (**(int **)(param_1 + 0x60) == 0) {
    FUN_0029213c(*(undefined8 *)(param_1 + 0x48));
    FUN_00294ba4(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x48));
    iVar2 = FUN_002921b8(*(undefined8 *)(param_1 + 0x48));
    lVar3 = *(long *)(param_1 + 0x60);
    *(int *)(lVar3 + 0xc) = iVar2 + *(int *)(lVar3 + 8);
    *(int *)(lVar3 + 0x20) = *(int *)(lVar3 + 8);
    *(int *)(lVar3 + 0xea7c) = *(int *)(lVar3 + 0xea7c) + iVar2;
  }
  FUN_0029213c(*(undefined8 *)(param_1 + 0x48));
  FUN_0029552c(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x48),param_2);
  iVar2 = FUN_002921b8(*(undefined8 *)(param_1 + 0x48));
  puVar4 = *(uint **)(param_1 + 0x60);
  if (*puVar4 < 0x3a96) {
    uVar5 = *puVar4 + 1;
    uVar1 = uVar5;
    while (uVar6 = (ulong)uVar1, uVar1 != param_3) {
      uVar1 = uVar1 - 1;
      puVar4[uVar6 + 8] = puVar4[(ulong)uVar1 + 8] + iVar2;
    }
    *puVar4 = uVar5;
  }
  else {
    uVar5 = 0x3a96;
    puVar8 = puVar4 + 0x3a9e;
    while (uVar5 != param_3) {
      uVar5 = uVar5 - 1;
      *puVar8 = puVar4[(ulong)uVar5 + 8] + iVar2;
      puVar8 = puVar8 + -1;
    }
    *(undefined1 *)(puVar4 + 1) = 1;
  }
  puVar4[3] = puVar4[3] + iVar2;
  uVar5 = iVar2 + puVar4[0x3a9f];
  puVar4[0x3a9f] = uVar5;
  if (puVar4[0x3aa0] <= uVar5) {
    puVar4[0x3aa0] = uVar5 + 1;
    iVar2 = FUN_00292008(param_4,10,1);
    if (iVar2 != 0) {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      uVar7 = 0x5a6;
      goto LAB_0028cdcc;
    }
  }
  iVar2 = FUN_00291d4c(param_4);
  if (iVar2 == 0) {
    FUN_00291c50(*(undefined8 *)(param_1 + 0x58),param_3,param_2);
    return 0;
  }
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
  uVar7 = 0x5b1;
LAB_0028cdcc:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar7,iVar2);
  return iVar2;
}

