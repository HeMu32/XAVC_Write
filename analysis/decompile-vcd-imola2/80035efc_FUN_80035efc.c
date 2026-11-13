// FUN_80035efc
// Ghidra address: 80035efc

void FUN_80035efc(int *param_1,byte *param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  int *piVar5;
  code *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  short sVar9;
  int *piVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  undefined4 uVar15;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  
  *(byte *)(param_1 + 0x32) = param_2[1];
  bVar3 = param_2[2];
  *(undefined1 *)((int)param_1 + 0x59) = 3;
  *(byte *)((int)param_1 + 0xc9) = bVar3;
  param_1[0x19] = param_1[0x19] & 0xfffffffcU | *param_2 & 3;
  uVar15 = 0x80035f68;
  piVar5 = (int *)(**(code **)(*param_1 + 0x140))();
  sVar11 = DAT_80248e1c;
  iVar12 = *piVar5;
  iVar13 = param_1[0x29];
  if (iVar13 != iVar12) {
    if (iVar13 != 0) {
      iVar12 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar12 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar15 = 0x800369a8;
        FUN_8005ba04(iVar12,0xffffffff);
        cVar2 = *(char *)(iVar13 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar13 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar13 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar10 = *(int **)(iVar13 + 0xc);
        if (piVar10[0xb] != 0) {
          FUN_8006033c(piVar10 + 0xb,iVar13);
          piVar10 = *(int **)(iVar13 + 0xc);
        }
        pcVar6 = *(code **)(*piVar10 + 8);
LAB_80035fec:
        uVar15 = 0x80035ff4;
        (*pcVar6)(piVar10,iVar13);
      }
      else if ((cVar2 == '\x01') &&
              (piVar10 = *(int **)(iVar13 + 0xc), *(char *)((int)piVar10 + 6) != '\0')) {
        pcVar6 = *(code **)(*piVar10 + 0x24);
        goto LAB_80035fec;
      }
      iVar12 = (int)sVar11;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar12 * 2] == 0) {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
        special2(0,1,0,0x26);
        iVar12 = *piVar5;
      }
      else {
        special2(0,1,0,0x26);
        uVar15 = 0x80036954;
        FUN_8005b738(iVar12);
        iVar12 = *piVar5;
      }
    }
    param_1[0x29] = iVar12;
    sVar11 = DAT_80248e1c;
    if (iVar12 != 0) {
      iVar13 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar13 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar15 = 0x8003693c;
        FUN_8005ba04(iVar13,0xffffffff);
        cVar2 = *(char *)(iVar12 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar13 * 2] = (&DAT_8024a55c)[iVar13 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar12 + 8);
      }
      *(char *)(iVar12 + 8) = cVar2 + '\x01';
      if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_m_ref_cnt_0__>_0_802110a0,s_______________________________co_802110b4,0x38,
                     uVar15);
      }
      iVar12 = (int)sVar11;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar12 * 2] == 0) {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
        special2(0,1,0,0x26);
      }
      else {
        special2(0,1,0,0x26);
        FUN_8005b738(iVar12);
      }
    }
  }
  iVar12 = FUN_8005a338(param_1);
  param_1[0x2a] = iVar12;
  uVar15 = 0x800360e0;
  piVar5 = (int *)(**(code **)(*param_1 + 0x144))(param_1);
  sVar11 = DAT_80248e1c;
  iVar12 = *piVar5;
  iVar13 = param_1[0x2b];
  if (iVar13 != iVar12) {
    if (iVar13 != 0) {
      iVar12 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar12 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar15 = 0x800368e8;
        FUN_8005ba04(iVar12,0xffffffff);
        cVar2 = *(char *)(iVar13 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar13 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar13 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar10 = *(int **)(iVar13 + 0xc);
        if (piVar10[0xb] != 0) {
          FUN_8006033c(piVar10 + 0xb,iVar13);
          piVar10 = *(int **)(iVar13 + 0xc);
        }
        pcVar6 = *(code **)(*piVar10 + 8);
LAB_80036164:
        uVar15 = 0x8003616c;
        (*pcVar6)(piVar10,iVar13);
      }
      else if ((cVar2 == '\x01') &&
              (piVar10 = *(int **)(iVar13 + 0xc), *(char *)((int)piVar10 + 6) != '\0')) {
        pcVar6 = *(code **)(*piVar10 + 0x24);
        goto LAB_80036164;
      }
      iVar12 = (int)sVar11;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar12 * 2] == 0) {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
        special2(0,1,0,0x26);
        iVar12 = *piVar5;
      }
      else {
        special2(0,1,0,0x26);
        uVar15 = 0x80036894;
        FUN_8005b738(iVar12);
        iVar12 = *piVar5;
      }
    }
    param_1[0x2b] = iVar12;
    sVar11 = DAT_80248e1c;
    if (iVar12 != 0) {
      iVar13 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar13 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar15 = 0x8003687c;
        FUN_8005ba04(iVar13,0xffffffff);
        cVar2 = *(char *)(iVar12 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar13 * 2] = (&DAT_8024a55c)[iVar13 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar12 + 8);
      }
      *(char *)(iVar12 + 8) = cVar2 + '\x01';
      if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_m_ref_cnt_0__>_0_802110a0,s_______________________________co_802110b4,0x38,
                     uVar15);
      }
      iVar12 = (int)sVar11;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar12 * 2] == 0) {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
        special2(0,1,0,0x26);
      }
      else {
        special2(0,1,0,0x26);
        FUN_8005b738(iVar12);
      }
    }
  }
  iVar12 = FUN_8005a370(param_1);
  param_1[0x2c] = iVar12;
  param_1[0x30] = -1;
  param_1[0x2d] = -1;
  param_1[0x2e] = -1;
  param_1[0x2f] = -1;
  puVar7 = *(undefined4 **)(param_2 + 4);
  *(undefined2 *)((int)param_1 + 0x62) = 0;
  uVar15 = *puVar7;
  sVar11 = (short)puVar7[1];
  *(short *)((int)param_1 + 0x5e) = sVar11;
  *(ushort *)(param_1 + 0x18) = sVar11 + 0xfU & 0xfff0;
  *(short *)(param_1 + 0x17) = (short)uVar15;
  (**(code **)(*param_1 + 0x54))(&local_50,param_1,*param_2);
  param_1[0x1f] = local_50;
  param_1[0x20] = local_4c;
  param_1[0x21] = local_48;
  param_1[0x22] = local_44;
  param_1[0x23] = local_40;
  uVar15 = 0x800362d0;
  FUN_80036ae0(&local_50,param_1,*param_2);
  param_1[0x25] = local_4c;
  param_1[0x24] = local_50;
  param_1[0x26] = local_48;
  param_1[0x27] = local_44;
  param_1[0x28] = local_40;
  cVar2 = *(char *)(*(int *)(param_2 + 4) + 0x50);
  cVar1 = *(char *)(*(int *)(param_2 + 4) + 0x51);
  if (cVar2 == '\b' && cVar1 == '\b') {
    uVar8 = param_1[0x19];
    iVar12 = 0;
  }
  else if (cVar2 == '\n' && cVar1 == '\n') {
    uVar8 = param_1[0x19];
    iVar12 = 1;
  }
  else {
    if (cVar2 != '\f' || cVar1 != '\f') {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s___unsupported_bit_depth__80211128,s_______________________________sr_80211144,
                   0x10b,uVar15);
    }
    uVar8 = param_1[0x19];
    iVar12 = 2;
  }
  param_1[0x19] = uVar8 & 0xfffffff3 | iVar12 << 2;
  param_1[0x19] =
       param_1[0x19] & 0xffffff0fU | (uint)(*(char *)(*(int *)(param_2 + 4) + 0x52) == '\x02') << 4;
  sVar11 = DAT_80248e1c;
  iVar12 = param_1[0x31];
  pbVar14 = param_2 + 8;
  if (iVar12 == *(int *)(param_2 + 8)) {
LAB_800364b8:
    bVar3 = *param_2;
  }
  else {
    if (iVar12 == 0) {
      iVar12 = *(int *)pbVar14;
    }
    else {
      iVar13 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar13 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar15 = 0x800367b4;
        FUN_8005ba04(iVar13,0xffffffff);
        cVar2 = *(char *)(iVar12 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar13 * 2] = (&DAT_8024a55c)[iVar13 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar12 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar12 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar5 = *(int **)(iVar12 + 0xc);
        if (piVar5[0xb] != 0) {
          FUN_8006033c(piVar5 + 0xb,iVar12);
          piVar5 = *(int **)(iVar12 + 0xc);
        }
        pcVar6 = *(code **)(*piVar5 + 8);
LAB_800363e4:
        uVar15 = 0x800363ec;
        (*pcVar6)(piVar5,iVar12);
      }
      else if ((cVar2 == '\x01') &&
              (piVar5 = *(int **)(iVar12 + 0xc), *(char *)((int)piVar5 + 6) != '\0')) {
        pcVar6 = *(code **)(*piVar5 + 0x24);
        goto LAB_800363e4;
      }
      iVar12 = (int)sVar11;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar12 * 2] == 0) {
        (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
        special2(0,1,0,0x26);
        iVar12 = *(int *)pbVar14;
      }
      else {
        special2(0,1,0,0x26);
        uVar15 = 0x80036760;
        FUN_8005b738(iVar12);
        iVar12 = *(int *)pbVar14;
      }
    }
    param_1[0x31] = iVar12;
    sVar11 = DAT_80248e1c;
    if (iVar12 == 0) goto LAB_800364b8;
    iVar13 = (int)DAT_80248e1c;
    special2(0,0,0,0x26);
    if ((&DAT_8024a55c)[iVar13 * 2] == 0) {
      special2(0,1,0,0x26);
      uVar15 = 0x80036748;
      FUN_8005ba04(iVar13,0xffffffff);
      cVar2 = *(char *)(iVar12 + 8);
    }
    else {
      (&DAT_8024a55c)[iVar13 * 2] = (&DAT_8024a55c)[iVar13 * 2] + -1;
      special2(0,1,0,0x26);
      cVar2 = *(char *)(iVar12 + 8);
    }
    *(char *)(iVar12 + 8) = cVar2 + '\x01';
    if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s_m_ref_cnt_0__>_0_802110a0,s_______________________________co_802110b4,0x38,
                   uVar15);
    }
    iVar12 = (int)sVar11;
    special2(0,0,0,0x26);
    if ((&DAT_8024a558)[iVar12 * 2] == 0) {
      (&DAT_8024a55c)[iVar12 * 2] = (&DAT_8024a55c)[iVar12 * 2] + 1;
      special2(0,1,0,0x26);
      goto LAB_800364b8;
    }
    special2(0,1,0,0x26);
    FUN_8005b738(iVar12);
    bVar3 = *param_2;
  }
  *(byte *)((int)param_1 + 0xca) = bVar3;
  uVar4 = (**(code **)(*param_1 + 0x14c))(param_1);
  *(undefined1 *)((int)param_1 + 0xcb) = uVar4;
  bVar3 = param_2[0xc];
  param_1[0x35] = *(int *)(param_2 + 0x10);
  iVar12 = *(int *)(param_2 + 0x14);
  *(bool *)(param_1 + 0x33) = bVar3 != 0;
  param_1[0x36] = iVar12;
  bVar3 = param_2[3];
  *(undefined1 *)((int)param_1 + 0xcd) = 0;
  param_1[0x19] = param_1[0x19] & 0xffffe1ffU | (bVar3 & 0xf) << 9;
  if (param_2[0x18] == 0) {
    if (param_2[0x19] != 0) {
      uVar4 = 1;
      goto LAB_80036514;
    }
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  else {
    uVar4 = 2;
LAB_80036514:
    *(undefined1 *)(param_1 + 0x1d) = uVar4;
  }
  iVar12 = 0x10 << (*(byte *)(*(int *)(param_2 + 4) + 0x53) & 0x1f);
  if ((iVar12 == 0x10) || ((uVar4 = 1, iVar12 != 0x20 && (uVar4 = 2, iVar12 != 0x40)))) {
    *(undefined1 *)((int)param_1 + 0x75) = 0;
  }
  else {
    *(undefined1 *)((int)param_1 + 0x75) = uVar4;
  }
  iVar12 = *(int *)(param_2 + 4);
  bVar3 = *(byte *)(iVar12 + 0x52);
  sVar11 = 2;
  if (bVar3 == 1) {
LAB_80036580:
    sVar9 = sVar11;
    sVar11 = (short)*(undefined4 *)(iVar12 + 0x14);
  }
  else {
    if (bVar3 < 2) {
      sVar11 = 1;
      if (bVar3 != 0) {
        sVar11 = 0;
      }
      goto LAB_80036580;
    }
    sVar9 = 1;
    sVar11 = 1;
    if (bVar3 == 2) goto LAB_80036580;
    if (bVar3 != 3) {
      sVar11 = 0;
      goto LAB_80036580;
    }
    sVar11 = (short)*(undefined4 *)(iVar12 + 0x14);
  }
  *(short *)(param_1 + 0x1b) = sVar9 * sVar11;
  bVar3 = *(byte *)(iVar12 + 0x52);
  sVar11 = 2;
  if (bVar3 != 1) {
    if (bVar3 < 2) {
      sVar11 = 1;
      if (bVar3 != 0) {
        sVar11 = 0;
      }
    }
    else {
      sVar9 = 1;
      sVar11 = 1;
      if (bVar3 != 2) {
        if (bVar3 == 3) {
          sVar11 = (short)*(undefined4 *)(iVar12 + 0x18);
          goto LAB_800365c8;
        }
        sVar11 = 0;
      }
    }
  }
  sVar9 = sVar11;
  sVar11 = (short)*(undefined4 *)(iVar12 + 0x18);
LAB_800365c8:
  *(short *)((int)param_1 + 0x6e) = sVar9 * sVar11;
  bVar3 = *(byte *)(iVar12 + 0x52);
  sVar11 = 2;
  if (bVar3 != 1) {
    if (bVar3 < 2) {
      sVar11 = 1;
      if (bVar3 != 0) {
        sVar11 = 0;
      }
    }
    else if ((bVar3 != 2) && (sVar11 = 1, bVar3 != 3)) {
      sVar11 = 0;
    }
  }
  *(short *)(param_1 + 0x1c) = sVar11 * (short)*(undefined4 *)(iVar12 + 0xc);
  bVar3 = *(byte *)(iVar12 + 0x52);
  sVar11 = 2;
  if (bVar3 != 1) {
    if (bVar3 < 2) {
      sVar11 = 1;
      if (bVar3 != 0) {
        sVar11 = 0;
      }
    }
    else if ((bVar3 != 2) && (sVar11 = 1, bVar3 != 3)) {
      sVar11 = 0;
    }
  }
  uVar15 = *(undefined4 *)(iVar12 + 0x10);
  *(undefined2 *)((int)param_1 + 0xce) = 0;
  *(undefined1 *)((int)param_1 + 0x7a) = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  *(short *)((int)param_1 + 0x72) = sVar11 * (short)uVar15;
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  param_1[0x1a] = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)((int)param_1 + 0x79) = 0;
  return;
}

