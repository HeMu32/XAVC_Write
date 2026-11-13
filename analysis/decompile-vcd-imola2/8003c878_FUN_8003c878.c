// FUN_8003c878
// Ghidra address: 8003c878

void FUN_8003c878(int *param_1,byte param_2,char *param_3,char param_4)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  undefined4 unaff_retaddr;
  undefined4 uVar12;
  
  cVar3 = *(char *)((int)param_1 + 0x40ff);
  *(char *)((int)param_1 + 0x40ff) = cVar3 + '\x01';
  *param_3 = cVar3;
  if (param_2 == 2) {
    cVar3 = *(char *)((int)param_1 + 0x65b5);
    *(int *)(param_3 + 0x10) = param_1[0x1945];
    bVar1 = *(byte *)(param_1 + 0x196d);
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
LAB_8003c8e4:
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(&DAT_802470d4,s_______________________________sr_80211450,0x237);
      }
      iVar5 = param_1[0x1912];
      cVar3 = *(char *)((int)param_1 + 0x64e9);
    }
    else {
      if (param_2 != 3) goto LAB_8003c8e4;
      cVar3 = *(char *)((int)param_1 + 0x64e9);
      iVar5 = param_1[0x1912] + param_1[0x1945];
    }
    *(int *)(param_3 + 0x10) = iVar5;
    bVar1 = *(byte *)(param_1 + 0x193a);
  }
  uVar10 = (uint)bVar1;
  if (cVar3 == '\0') {
    if (*(char *)((int)param_1 + 0x415e) != '\x01') {
      iVar5 = param_1[0x1912];
LAB_8003d270:
      cVar3 = '\x04';
      if (iVar5 <= param_1[0x1945]) {
        cVar3 = '\x03';
      }
      param_3[3] = cVar3;
      goto LAB_8003c924;
    }
    param_3[3] = '\0';
  }
  else if (*(char *)((int)param_1 + 0x415e) == '\x01') {
    if (uVar10 == 0 || uVar10 == 7) {
      param_3[3] = bVar1;
    }
    else if (uVar10 == 8) {
      param_3[3] = bVar1;
    }
    else {
      param_3[3] = '\0';
    }
  }
  else {
    if (3 < uVar10 - 3) {
      iVar5 = param_1[0x1912];
      goto LAB_8003d270;
    }
    param_3[3] = bVar1;
LAB_8003c924:
    param_3[0x75] = '\x01';
  }
  if (*(char *)((int)param_1 + 0x40f2) == '\0' || *(char *)((int)param_1 + 0x40f2) == '\x04') {
    iVar5 = (**(code **)(**(int **)param_1[0x18dc] + 8))();
    if (iVar5 == 2) {
      param_3[2] = '\0';
    }
    else {
      uVar6 = FUN_8003e080(param_1);
      uVar10 = (*(uint *)(param_1[0x1979] + 8) & 0x3fffffff) >> 0x19;
      if (uVar6 < uVar10) {
        uVar10 = FUN_8003e080(param_1);
      }
      param_3[2] = (char)uVar10;
    }
  }
  else {
    param_3[2] = '\0';
  }
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xfffffeff | (uint)(param_4 != '\0') << 8;
  iVar5 = 0;
  if (param_4 != '\0') {
    iVar5 = 0;
    uVar10 = 0xffffffff;
    if ((uint *)param_1[0x1037] != (uint *)0x0) {
      uVar10 = *(uint *)param_1[0x1037];
    }
    uVar6 = uVar10 + 0x80000000;
    if ((0x1dffffff < uVar10) && (uVar6 = uVar10 + 0xc0000000, 0x1fffffff < uVar6)) {
      uVar6 = 0;
    }
    if (*(int *)(uVar6 + 4) == 0) {
      uVar10 = 0xffffffff;
      if ((uint *)param_1[0x1038] != (uint *)0x0) {
        uVar10 = *(uint *)param_1[0x1038];
      }
      uVar6 = uVar10 + 0x80000000;
      if ((0x1dffffff < uVar10) && (uVar6 = uVar10 + 0xc0000000, 0x1fffffff < uVar6)) {
        uVar6 = 0;
      }
      if (*(int *)(uVar6 + 0x80) != 0) {
        iVar5 = 2;
      }
    }
    else {
      iVar5 = 1;
    }
  }
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xe0001fff | iVar5 << 0xd;
  iVar5 = *param_1;
  *(int *)(param_3 + 0x84) = param_1[0x1912];
  pcVar4 = *(code **)(iVar5 + 0x7c);
  uVar12 = 0x8003c9ec;
  *(int *)(param_3 + 0x88) = param_1[0x1945];
  iVar5 = (*pcVar4)(param_1);
  if (iVar5 == 3) {
    iVar5 = param_1[0x1939];
    iVar7 = param_1[0x192f];
    iVar9 = *(int *)(param_3 + 0x8c);
    *(short *)(param_3 + 0x78) = (short)iVar5;
    piVar11 = param_1 + 0x192f;
    *(short *)(param_3 + 0x76) = (short)iVar5;
    sVar2 = DAT_80248e1c;
    if (iVar9 != iVar7) {
      if (iVar9 == 0) {
        iVar5 = *piVar11;
      }
      else {
        iVar5 = (int)DAT_80248e1c;
        special2(0,0,0,0x26);
        if ((&DAT_8024a55c)[iVar5 * 2] == 0) {
          special2(0,1,0,0x26);
          uVar12 = 0x8003ce58;
          FUN_8005ba04(iVar5,0xffffffff);
          cVar3 = *(char *)(iVar9 + 8);
        }
        else {
          (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + -1;
          special2(0,1,0,0x26);
          cVar3 = *(char *)(iVar9 + 8);
        }
        cVar3 = cVar3 + -1;
        *(char *)(iVar9 + 8) = cVar3;
        if (cVar3 == '\0') {
          piVar8 = *(int **)(iVar9 + 0xc);
          if (piVar8[0xb] != 0) {
            FUN_8006033c(piVar8 + 0xb,iVar9);
            piVar8 = *(int **)(iVar9 + 0xc);
          }
          pcVar4 = *(code **)(*piVar8 + 8);
LAB_8003ca8c:
          uVar12 = 0x8003ca94;
          (*pcVar4)(piVar8,iVar9);
        }
        else if ((cVar3 == '\x01') &&
                (piVar8 = *(int **)(iVar9 + 0xc), *(char *)((int)piVar8 + 6) != '\0')) {
          pcVar4 = *(code **)(*piVar8 + 0x24);
          goto LAB_8003ca8c;
        }
        iVar5 = (int)sVar2;
        special2(0,0,0,0x26);
        if ((&DAT_8024a558)[iVar5 * 2] == 0) {
          (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
          special2(0,1,0,0x26);
          iVar5 = *piVar11;
        }
        else {
          special2(0,1,0,0x26);
          uVar12 = 0x8003ce04;
          FUN_8005b738(iVar5);
          iVar5 = *piVar11;
        }
      }
      *(int *)(param_3 + 0x8c) = iVar5;
      sVar2 = DAT_80248e1c;
      if (iVar5 != 0) {
        iVar7 = (int)DAT_80248e1c;
        special2(0,0,0,0x26);
        if ((&DAT_8024a55c)[iVar7 * 2] == 0) {
          special2(0,1,0,0x26);
          uVar12 = 0x8003cdec;
          FUN_8005ba04(iVar7,0xffffffff);
          cVar3 = *(char *)(iVar5 + 8);
        }
        else {
          (&DAT_8024a55c)[iVar7 * 2] = (&DAT_8024a55c)[iVar7 * 2] + -1;
          special2(0,1,0,0x26);
          cVar3 = *(char *)(iVar5 + 8);
        }
        *(char *)(iVar5 + 8) = cVar3 + '\x01';
        if ((char)(cVar3 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
          FUN_8000ae50(s_m_ref_cnt_0__>_0_802113e0,s_______________________________co_802113f4,0x38,
                       uVar12);
        }
        iVar5 = (int)sVar2;
        special2(0,0,0,0x26);
        if ((&DAT_8024a558)[iVar5 * 2] != 0) {
          special2(0,1,0,0x26);
          FUN_8005b738(iVar5);
          iVar7 = param_1[0x192f];
          goto LAB_8003cb68;
        }
        (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
        special2(0,1,0,0x26);
      }
      iVar7 = param_1[0x192f];
    }
LAB_8003cb68:
    sVar2 = DAT_80248e1c;
    iVar5 = *(int *)(param_3 + 0x90);
    if (iVar5 == iVar7) {
      return;
    }
    if (iVar5 == 0) {
      iVar5 = *piVar11;
    }
    else {
      iVar7 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar7 * 2] == 0) {
        special2(0,1,0,0x26);
        FUN_8005ba04(iVar7,0xffffffff);
        cVar3 = *(char *)(iVar5 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar7 * 2] = (&DAT_8024a55c)[iVar7 * 2] + -1;
        special2(0,1,0,0x26);
        cVar3 = *(char *)(iVar5 + 8);
      }
      cVar3 = cVar3 + -1;
      *(char *)(iVar5 + 8) = cVar3;
      if (cVar3 == '\0') {
        piVar8 = *(int **)(iVar5 + 0xc);
        if (piVar8[0xb] != 0) {
          FUN_8006033c(piVar8 + 0xb,iVar5);
          piVar8 = *(int **)(iVar5 + 0xc);
        }
        pcVar4 = *(code **)(*piVar8 + 8);
LAB_8003cbe8:
        (*pcVar4)(piVar8,iVar5);
      }
      else if ((cVar3 == '\x01') &&
              (piVar8 = *(int **)(iVar5 + 0xc), *(char *)((int)piVar8 + 6) != '\0')) {
        pcVar4 = *(code **)(*piVar8 + 0x24);
        goto LAB_8003cbe8;
      }
      iVar5 = (int)sVar2;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar5 * 2] == 0) {
        (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
        special2(0,1,0,0x26);
        iVar5 = *piVar11;
      }
      else {
        special2(0,1,0,0x26);
        FUN_8005b738(iVar5);
        iVar5 = *piVar11;
      }
    }
    *(int *)(param_3 + 0x90) = iVar5;
    goto LAB_8003cc30;
  }
  iVar5 = param_1[0x196c];
  iVar7 = param_1[0x192f];
  iVar9 = *(int *)(param_3 + 0x8c);
  *(short *)(param_3 + 0x76) = (short)param_1[0x1939];
  piVar11 = param_1 + 0x192f;
  *(short *)(param_3 + 0x78) = (short)iVar5;
  sVar2 = DAT_80248e1c;
  if (iVar9 == iVar7) {
LAB_8003cfc8:
    iVar5 = *(int *)(param_3 + 0x90);
  }
  else {
    if (iVar9 == 0) {
      iVar5 = *piVar11;
    }
    else {
      iVar5 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar5 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar12 = 0x8003d1c0;
        FUN_8005ba04(iVar5,0xffffffff);
        cVar3 = *(char *)(iVar9 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + -1;
        special2(0,1,0,0x26);
        cVar3 = *(char *)(iVar9 + 8);
      }
      cVar3 = cVar3 + -1;
      *(char *)(iVar9 + 8) = cVar3;
      if (cVar3 == '\0') {
        piVar8 = *(int **)(iVar9 + 0xc);
        if (piVar8[0xb] != 0) {
          FUN_8006033c(piVar8 + 0xb,iVar9);
          piVar8 = *(int **)(iVar9 + 0xc);
        }
        pcVar4 = *(code **)(*piVar8 + 8);
LAB_8003cef4:
        uVar12 = 0x8003cefc;
        (*pcVar4)(piVar8,iVar9);
      }
      else if ((cVar3 == '\x01') &&
              (piVar8 = *(int **)(iVar9 + 0xc), *(char *)((int)piVar8 + 6) != '\0')) {
        pcVar4 = *(code **)(*piVar8 + 0x24);
        goto LAB_8003cef4;
      }
      iVar5 = (int)sVar2;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar5 * 2] == 0) {
        (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
        special2(0,1,0,0x26);
        iVar5 = *piVar11;
      }
      else {
        special2(0,1,0,0x26);
        uVar12 = 0x8003d16c;
        FUN_8005b738(iVar5);
        iVar5 = *piVar11;
      }
    }
    *(int *)(param_3 + 0x8c) = iVar5;
    sVar2 = DAT_80248e1c;
    if (iVar5 == 0) goto LAB_8003cfc8;
    iVar7 = (int)DAT_80248e1c;
    special2(0,0,0,0x26);
    if ((&DAT_8024a55c)[iVar7 * 2] == 0) {
      special2(0,1,0,0x26);
      uVar12 = 0x8003d154;
      FUN_8005ba04(iVar7,0xffffffff);
      cVar3 = *(char *)(iVar5 + 8);
    }
    else {
      (&DAT_8024a55c)[iVar7 * 2] = (&DAT_8024a55c)[iVar7 * 2] + -1;
      special2(0,1,0,0x26);
      cVar3 = *(char *)(iVar5 + 8);
    }
    *(char *)(iVar5 + 8) = cVar3 + '\x01';
    if ((char)(cVar3 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s_m_ref_cnt_0__>_0_802113e0,s_______________________________co_802113f4,0x38,
                   uVar12);
    }
    iVar5 = (int)sVar2;
    special2(0,0,0,0x26);
    if ((&DAT_8024a558)[iVar5 * 2] == 0) {
      (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
      special2(0,1,0,0x26);
      goto LAB_8003cfc8;
    }
    special2(0,1,0,0x26);
    FUN_8005b738(iVar5);
    iVar5 = *(int *)(param_3 + 0x90);
  }
  sVar2 = DAT_80248e1c;
  piVar11 = param_1 + 0x1962;
  if (iVar5 == param_1[0x1962]) {
    return;
  }
  if (iVar5 == 0) {
    iVar5 = *piVar11;
  }
  else {
    iVar7 = (int)DAT_80248e1c;
    special2(0,0,0,0x26);
    if ((&DAT_8024a55c)[iVar7 * 2] == 0) {
      special2(0,1,0,0x26);
      FUN_8005ba04(iVar7,0xffffffff);
      cVar3 = *(char *)(iVar5 + 8);
    }
    else {
      (&DAT_8024a55c)[iVar7 * 2] = (&DAT_8024a55c)[iVar7 * 2] + -1;
      special2(0,1,0,0x26);
      cVar3 = *(char *)(iVar5 + 8);
    }
    cVar3 = cVar3 + -1;
    *(char *)(iVar5 + 8) = cVar3;
    if (cVar3 == '\0') {
      piVar8 = *(int **)(iVar5 + 0xc);
      if (piVar8[0xb] != 0) {
        FUN_8006033c(piVar8 + 0xb,iVar5);
        piVar8 = *(int **)(iVar5 + 0xc);
      }
      pcVar4 = *(code **)(*piVar8 + 8);
LAB_8003d050:
      (*pcVar4)(piVar8,iVar5);
    }
    else if ((cVar3 == '\x01') &&
            (piVar8 = *(int **)(iVar5 + 0xc), *(char *)((int)piVar8 + 6) != '\0')) {
      pcVar4 = *(code **)(*piVar8 + 0x24);
      goto LAB_8003d050;
    }
    iVar5 = (int)sVar2;
    special2(0,0,0,0x26);
    if ((&DAT_8024a558)[iVar5 * 2] == 0) {
      (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
      special2(0,1,0,0x26);
      iVar5 = *piVar11;
    }
    else {
      special2(0,1,0,0x26);
      FUN_8005b738(iVar5);
      iVar5 = *piVar11;
    }
  }
  *(int *)(param_3 + 0x90) = iVar5;
LAB_8003cc30:
  sVar2 = DAT_80248e1c;
  if (iVar5 != 0) {
    iVar7 = (int)DAT_80248e1c;
    special2(0,0,0,0x26);
    if ((&DAT_8024a55c)[iVar7 * 2] == 0) {
      special2(0,1,0,0x26);
      unaff_retaddr = 0x8003cd30;
      FUN_8005ba04(iVar7,0xffffffff);
      cVar3 = *(char *)(iVar5 + 8);
    }
    else {
      (&DAT_8024a55c)[iVar7 * 2] = (&DAT_8024a55c)[iVar7 * 2] + -1;
      special2(0,1,0,0x26);
      cVar3 = *(char *)(iVar5 + 8);
    }
    *(char *)(iVar5 + 8) = cVar3 + '\x01';
    if ((char)(cVar3 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s_m_ref_cnt_0__>_0_802113e0,s_______________________________co_802113f4,0x38,
                   unaff_retaddr);
    }
    iVar5 = (int)sVar2;
    special2(0,0,0,0x26);
    if ((&DAT_8024a558)[iVar5 * 2] == 0) {
      (&DAT_8024a55c)[iVar5 * 2] = (&DAT_8024a55c)[iVar5 * 2] + 1;
      special2(0,1,0,0x26);
    }
    else {
      special2(0,1,0,0x26);
      FUN_8005b738(iVar5);
    }
  }
  return;
}

