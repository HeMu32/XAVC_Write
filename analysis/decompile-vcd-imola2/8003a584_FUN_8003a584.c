// FUN_8003a584
// Ghidra address: 8003a584

void FUN_8003a584(int *param_1)

{
  undefined2 uVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined1 local_50;
  undefined1 local_4f;
  int *local_4c;
  int local_48;
  int local_44;
  undefined1 local_40;
  undefined1 local_3f;
  byte local_3e;
  undefined4 local_3c;
  int local_38;
  short local_30;
  
  iVar11 = 3;
  if (*(char *)((int)param_1 + 0x415e) != '\x01') {
    iVar11 = (**(code **)(*param_1 + 0x7c))();
    if (iVar11 == 3) {
      iVar11 = (**(code **)(*param_1 + 100))(param_1);
    }
    else {
      iVar11 = 1;
      if (*(int *)param_1[0x197b] << 10 < 0) {
        iVar11 = 2;
      }
    }
  }
  local_44 = 0;
  uVar1 = *(undefined2 *)(param_1[9] + 0x28);
  uVar4 = FUN_8005e47c(uVar1);
  uVar5 = FUN_8005e504(uVar1);
  if (uVar5 == 0) {
    trap(7);
  }
  iVar8 = (int)DAT_80248e1c;
  local_30 = DAT_80248e1c;
  special2(0,0,0,0x26);
  if ((&DAT_8024a55c)[iVar8 * 2] == 0) {
    special2(0,1,0,0x26);
    FUN_8005ba04(iVar8,0xffffffff);
  }
  else {
    (&DAT_8024a55c)[iVar8 * 2] = (&DAT_8024a55c)[iVar8 * 2] + -1;
    special2(0,1,0,0x26);
  }
  iVar8 = local_44;
  if (local_44 != 0) {
    cVar2 = *(char *)(local_44 + 8) + -1;
    *(char *)(local_44 + 8) = cVar2;
    if (cVar2 == '\0') {
      piVar9 = *(int **)(local_44 + 0xc);
      if (piVar9[0xb] != 0) {
        FUN_8006033c(piVar9 + 0xb,local_44);
        piVar9 = *(int **)(iVar8 + 0xc);
      }
      pcVar6 = *(code **)(*piVar9 + 8);
    }
    else {
      if ((cVar2 != '\x01') ||
         (piVar9 = *(int **)(local_44 + 0xc), *(char *)((int)piVar9 + 6) == '\0'))
      goto LAB_8003a6ac;
      pcVar6 = *(code **)(*piVar9 + 0x24);
    }
    (*pcVar6)(piVar9,iVar8);
  }
LAB_8003a6ac:
  uVar12 = 0x8003a6b4;
  local_44 = FUN_8005ef3c(uVar1,uVar4 / uVar5);
  iVar8 = -0x4efdffff;
  if (local_44 != 0) {
    iVar8 = 0;
  }
  iVar10 = (int)local_30;
  special2(0,0,0,0x26);
  if ((&DAT_8024a558)[iVar10 * 2] == 0) {
    (&DAT_8024a55c)[iVar10 * 2] = (&DAT_8024a55c)[iVar10 * 2] + 1;
    special2(0,1,0,0x26);
  }
  else {
    special2(0,1,0,0x26);
    uVar12 = 0x8003aad4;
    FUN_8005b738(iVar10);
  }
  if (iVar8 != 0) {
LAB_8003aaa4:
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(&DAT_802470d4,s_______________________________sr_80211450,0x4a,uVar12);
  }
  uVar12 = 0x8003a714;
  FUN_801aeb74(&local_44,0,0,0);
  iVar8 = param_1[0x109b];
  if (iVar8 == 0x40) goto LAB_8003aaa4;
  if (iVar8 < 0x40) {
    param_1[0x109b] = iVar8 + 1;
    if (param_1[0x109a] < 0x40) {
      iVar8 = param_1[0x109a] + 1;
      param_1[0x109a] = iVar8;
      if (iVar8 != 1) {
        piVar9 = (int *)(param_1[0x1098] + 4U);
        if (param_1 + 0x1097 < (int *)(param_1[0x1098] + 4U)) {
          piVar9 = param_1 + 0x1058;
        }
        param_1[0x1098] = (int)piVar9;
      }
      piVar9 = (int *)FUN_80069c90(4,param_1[0x1098]);
      iVar8 = local_44;
      *piVar9 = local_44;
      if (local_44 != 0) {
        uVar12 = 0x8003aa14;
        local_30 = DAT_80248e1c;
        FUN_8003fb70((int)DAT_80248e1c,0xffffffff);
        cVar2 = *(char *)(iVar8 + 8) + '\x01';
        *(char *)(iVar8 + 8) = cVar2;
        if (cVar2 < '\x01') {
                    /* WARNING: Subroutine does not return */
          FUN_8000ae50(s_m_ref_cnt_0__>_0_802113e0,s_______________________________co_802113f4,0x38,
                       uVar12);
        }
        iVar8 = (int)local_30;
        special2(0,0,0,0x26);
        if ((&DAT_8024a558)[iVar8 * 2] == 0) {
          (&DAT_8024a55c)[iVar8 * 2] = (&DAT_8024a55c)[iVar8 * 2] + 1;
          special2(0,1,0,0x26);
          puVar7 = (uint *)param_1[0x1038];
        }
        else {
          special2(0,1,0,0x26);
          FUN_8005b738(iVar8);
          puVar7 = (uint *)param_1[0x1038];
        }
        goto LAB_8003a78c;
      }
    }
    puVar7 = (uint *)param_1[0x1038];
  }
  else {
    puVar7 = (uint *)param_1[0x1038];
  }
LAB_8003a78c:
  uVar4 = 0xffffffff;
  if (puVar7 != (uint *)0x0) {
    uVar4 = *puVar7;
  }
  uVar5 = uVar4 + 0x80000000;
  if (0x1dffffff < uVar4) {
    uVar5 = 0;
    if (uVar4 + 0xc0000000 < 0x20000000) {
      uVar5 = uVar4 + 0xc0000000;
    }
  }
  local_4f = *(undefined1 *)((int)param_1 + 0x415e);
  local_40 = *(undefined1 *)((int)param_1 + 0x40fd);
  local_3f = *(undefined1 *)((int)param_1 + 0x40fe);
  local_50 = (undefined1)iVar11;
  local_48 = param_1[0x197b];
  local_3e = (byte)((uint)(**(int **)(uVar5 + 0x8c) << 0x14) >> 0x1c);
  local_3c = *(undefined4 *)(&DAT_802430a4 + param_1[0x1035] * 8);
  local_4c = param_1 + 0x1992;
  iVar8 = (**(code **)(*param_1 + 0x7c))(param_1);
  if (iVar8 == 3) {
    local_38 = *(int *)(&DAT_802430a8 + param_1[0x1035] * 8);
  }
  else {
    local_38 = *(int *)(&DAT_802430a8 + param_1[0x1035] * 8) << 1;
  }
  FUN_80040354(param_1 + 0x18f9,&local_50);
  piVar9 = param_1 + 0x1947;
  if (iVar11 != 2) {
    piVar9 = param_1 + 0x1914;
  }
  FUN_80043f00(param_1 + 0x18dd,piVar9,uVar5,param_1 + 0x1992,*(undefined1 *)((int)param_1 + 0x415e)
               ,*(char *)((int)param_1 + 0x641a) != '\0');
  uVar3 = FUN_8003ab48(param_1,(char)param_1[0x1902]);
  iVar11 = local_44;
  *(undefined1 *)((int)param_1 + 0x16) = uVar3;
  if (local_44 == 0) {
    return;
  }
  iVar8 = (int)DAT_80248e1c;
  local_30 = DAT_80248e1c;
  special2(0,0,0,0x26);
  if ((&DAT_8024a55c)[iVar8 * 2] == 0) {
    special2(0,1,0,0x26);
    FUN_8005ba04(iVar8,0xffffffff);
    cVar2 = *(char *)(iVar11 + 8);
  }
  else {
    (&DAT_8024a55c)[iVar8 * 2] = (&DAT_8024a55c)[iVar8 * 2] + -1;
    special2(0,1,0,0x26);
    cVar2 = *(char *)(local_44 + 8);
  }
  cVar2 = cVar2 + -1;
  *(char *)(iVar11 + 8) = cVar2;
  if (cVar2 == '\0') {
    piVar9 = *(int **)(iVar11 + 0xc);
    if (piVar9[0xb] != 0) {
      FUN_8006033c(piVar9 + 0xb,iVar11);
      piVar9 = *(int **)(iVar11 + 0xc);
    }
    pcVar6 = *(code **)(*piVar9 + 8);
  }
  else {
    iVar8 = (int)local_30;
    if ((cVar2 != '\x01') || (piVar9 = *(int **)(iVar11 + 0xc), *(char *)((int)piVar9 + 6) == '\0'))
    goto LAB_8003a924;
    pcVar6 = *(code **)(*piVar9 + 0x24);
  }
  (*pcVar6)(piVar9,iVar11);
  iVar8 = (int)local_30;
LAB_8003a924:
  special2(0,0,0,0x26);
  if ((&DAT_8024a558)[iVar8 * 2] == 0) {
    (&DAT_8024a55c)[iVar8 * 2] = (&DAT_8024a55c)[iVar8 * 2] + 1;
    special2(0,1,0,0x26);
  }
  else {
    special2(0,1,0,0x26);
    FUN_8005b738(iVar8);
  }
  return;
}

