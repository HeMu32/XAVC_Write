// FUN_0028c98c
// Ghidra address: 0028c98c

int FUN_0028c98c(long *param_1,undefined8 param_2,uint param_3,char param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint *puVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint *puVar9;
  
  iVar2 = (**(code **)(*param_1 + 0x98))(param_1,param_3);
  if (iVar2 != 0) {
    uVar8 = 0x1ed;
    goto LAB_0028c9d0;
  }
  if (*(int *)param_1[0xc] == 0) {
    FUN_0029213c(param_1[9]);
    iVar2 = FUN_00294ba4(param_1[8],param_1[9]);
    if (iVar2 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0x200;
      goto LAB_0028c9d0;
    }
    iVar3 = FUN_002921b8(param_1[9]);
    iVar2 = (**(code **)(*param_1 + 0xb8))
                      (param_1,param_1[9],*(undefined4 *)(param_1[0xc] + 8),param_4);
    if (iVar2 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0x20a;
      goto LAB_0028c9d0;
    }
    lVar4 = param_1[0xc];
    *(int *)(lVar4 + 0xc) = iVar3 + *(int *)(lVar4 + 8);
    *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 8);
    *(int *)(lVar4 + 0xea7c) = *(int *)(lVar4 + 0xea7c) + iVar3;
  }
  FUN_0029213c(param_1[9]);
  iVar2 = FUN_0029552c(param_1[8],param_1[9],param_2);
  if (iVar2 == 0) {
    iVar3 = FUN_002921b8(param_1[9]);
    iVar2 = (**(code **)(*param_1 + 0xb8))
                      (param_1,param_1[9],*(undefined4 *)(param_1[0xc] + (ulong)param_3 * 4 + 0x20),
                       param_4);
    if (iVar2 == 0) {
      puVar5 = (uint *)param_1[0xc];
      if (*puVar5 < 0x3a96) {
        uVar6 = *puVar5 + 1;
        uVar1 = uVar6;
        while (uVar7 = (ulong)uVar1, uVar1 != param_3) {
          uVar1 = uVar1 - 1;
          puVar5[uVar7 + 8] = puVar5[(ulong)uVar1 + 8] + iVar3;
        }
        *puVar5 = uVar6;
      }
      else {
        uVar6 = 0x3a96;
        puVar9 = puVar5 + 0x3a9e;
        while (uVar6 != param_3) {
          uVar6 = uVar6 - 1;
          *puVar9 = puVar5[(ulong)uVar6 + 8] + iVar3;
          puVar9 = puVar9 + -1;
        }
        *(undefined1 *)(puVar5 + 1) = 1;
      }
      puVar5[3] = puVar5[3] + iVar3;
      uVar6 = iVar3 + puVar5[0x3a9f];
      puVar5[0x3a9f] = uVar6;
      if (puVar5[0x3aa0] <= uVar6) {
        puVar5[0x3aa0] = uVar6 + 1;
        if (param_4 == '\0') {
          iVar2 = FUN_00292080(param_1[6],10,1);
        }
        else {
          iVar2 = FUN_00292008();
        }
        if (iVar2 != 0) {
          FUN_0028bc28(param_1[1],2);
          uVar8 = 0x24e;
          goto LAB_0028c9d0;
        }
      }
      iVar2 = FUN_00291d4c(param_1[6]);
      if (iVar2 == 0) {
        FUN_00291c50(param_1[0xb],param_3,param_2);
        return 0;
      }
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0x259;
    }
    else {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0x228;
    }
  }
  else {
    FUN_0028bc28(param_1[1],2);
    uVar8 = 0x21e;
  }
LAB_0028c9d0:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar8,iVar2);
  return iVar2;
}

