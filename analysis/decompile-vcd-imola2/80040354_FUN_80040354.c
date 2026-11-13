// FUN_80040354
// Ghidra address: 80040354

void FUN_80040354(int *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  int *piVar7;
  code *pcVar8;
  undefined2 uVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  int iVar16;
  byte *pbVar17;
  bool bVar18;
  undefined4 uVar19;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  
  bVar18 = false;
  iVar6 = (**(code **)(*param_1 + 0x128))();
  if (iVar6 != 0) {
    bVar18 = param_2[1] == 0;
  }
  piVar15 = param_1 + 0x4e;
  if (*param_2 != 2) {
    piVar15 = param_1 + 0x1b;
  }
  *(byte *)(piVar15 + 0x1c) = param_2[0x10];
  bVar1 = param_2[0x11];
  *(undefined1 *)((int)piVar15 + 1) = 2;
  *(byte *)((int)piVar15 + 0x71) = bVar1;
  piVar15[3] = piVar15[3] & 0xfffffffcU | *param_2 & 3;
  uVar19 = 0x800403f4;
  piVar7 = (int *)(**(code **)(*param_1 + 0x140))(param_1);
  sVar10 = DAT_80248e1c;
  iVar6 = *piVar7;
  iVar16 = piVar15[0x13];
  if (iVar16 != iVar6) {
    if (iVar16 != 0) {
      iVar6 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar6 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar19 = 0x80040f10;
        FUN_8005ba04(iVar6,0xffffffff);
        cVar2 = *(char *)(iVar16 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar16 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar16 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar13 = *(int **)(iVar16 + 0xc);
        if (piVar13[0xb] != 0) {
          FUN_8006033c(piVar13 + 0xb,iVar16);
          piVar13 = *(int **)(iVar16 + 0xc);
        }
        pcVar8 = *(code **)(*piVar13 + 8);
LAB_80040478:
        uVar19 = 0x80040480;
        (*pcVar8)(piVar13,iVar16);
      }
      else if ((cVar2 == '\x01') &&
              (piVar13 = *(int **)(iVar16 + 0xc), *(char *)((int)piVar13 + 6) != '\0')) {
        pcVar8 = *(code **)(*piVar13 + 0x24);
        goto LAB_80040478;
      }
      iVar6 = (int)sVar10;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar6 * 2] == 0) {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
        special2(0,1,0,0x26);
        iVar6 = *piVar7;
      }
      else {
        special2(0,1,0,0x26);
        uVar19 = 0x80040ebc;
        FUN_8005b738(iVar6);
        iVar6 = *piVar7;
      }
    }
    piVar15[0x13] = iVar6;
    sVar10 = DAT_80248e1c;
    if (iVar6 != 0) {
      iVar16 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar16 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar19 = 0x80040ea4;
        FUN_8005ba04(iVar16,0xffffffff);
        cVar2 = *(char *)(iVar6 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar16 * 2] = (&DAT_8024a55c)[iVar16 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar6 + 8);
      }
      *(char *)(iVar6 + 8) = cVar2 + '\x01';
      if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_m_ref_cnt_0__>_0_8021181c,s_______________________________co_80211830,0x38,
                     uVar19);
      }
      iVar6 = (int)sVar10;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar6 * 2] == 0) {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
        special2(0,1,0,0x26);
      }
      else {
        special2(0,1,0,0x26);
        FUN_8005b738(iVar6);
      }
    }
  }
  iVar6 = FUN_8005a338(param_1);
  piVar15[0x14] = iVar6;
  sVar10 = DAT_80248e1c;
  if (param_2[1] == 0) {
    uVar19 = 0x80040c30;
    piVar7 = (int *)(**(code **)(*param_1 + 0x144))(param_1);
    sVar10 = DAT_80248e1c;
    iVar6 = *piVar7;
    iVar16 = piVar15[0x15];
    if (iVar16 != iVar6) {
      if (iVar16 != 0) {
        iVar6 = (int)DAT_80248e1c;
        special2(0,0,0,0x26);
        if ((&DAT_8024a55c)[iVar6 * 2] == 0) {
          special2(0,1,0,0x26);
          uVar19 = 0x80040e50;
          FUN_8005ba04(iVar6,0xffffffff);
          cVar2 = *(char *)(iVar16 + 8);
        }
        else {
          (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + -1;
          special2(0,1,0,0x26);
          cVar2 = *(char *)(iVar16 + 8);
        }
        cVar2 = cVar2 + -1;
        *(char *)(iVar16 + 8) = cVar2;
        if (cVar2 == '\0') {
          piVar13 = *(int **)(iVar16 + 0xc);
          if (piVar13[0xb] != 0) {
            FUN_8006033c(piVar13 + 0xb,iVar16);
            piVar13 = *(int **)(iVar16 + 0xc);
          }
          pcVar8 = *(code **)(*piVar13 + 8);
LAB_80040cb4:
          uVar19 = 0x80040cbc;
          (*pcVar8)(piVar13,iVar16);
        }
        else if ((cVar2 == '\x01') &&
                (piVar13 = *(int **)(iVar16 + 0xc), *(char *)((int)piVar13 + 6) != '\0')) {
          pcVar8 = *(code **)(*piVar13 + 0x24);
          goto LAB_80040cb4;
        }
        iVar6 = (int)sVar10;
        special2(0,0,0,0x26);
        if ((&DAT_8024a558)[iVar6 * 2] == 0) {
          (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
          special2(0,1,0,0x26);
          iVar6 = *piVar7;
        }
        else {
          special2(0,1,0,0x26);
          uVar19 = 0x80040dfc;
          FUN_8005b738(iVar6);
          iVar6 = *piVar7;
        }
      }
      piVar15[0x15] = iVar6;
      sVar10 = DAT_80248e1c;
      if (iVar6 != 0) {
        iVar16 = (int)DAT_80248e1c;
        special2(0,0,0,0x26);
        if ((&DAT_8024a55c)[iVar16 * 2] == 0) {
          special2(0,1,0,0x26);
          uVar19 = 0x80040de4;
          FUN_8005ba04(iVar16,0xffffffff);
          cVar2 = *(char *)(iVar6 + 8);
        }
        else {
          (&DAT_8024a55c)[iVar16 * 2] = (&DAT_8024a55c)[iVar16 * 2] + -1;
          special2(0,1,0,0x26);
          cVar2 = *(char *)(iVar6 + 8);
        }
        *(char *)(iVar6 + 8) = cVar2 + '\x01';
        if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
          FUN_8000ae50(s_m_ref_cnt_0__>_0_8021181c,s_______________________________co_80211830,0x38,
                       uVar19);
        }
        iVar6 = (int)sVar10;
        special2(0,0,0,0x26);
        if ((&DAT_8024a558)[iVar6 * 2] == 0) {
          (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
          special2(0,1,0,0x26);
        }
        else {
          special2(0,1,0,0x26);
          FUN_8005b738(iVar6);
        }
      }
    }
    iVar6 = FUN_8005a370(param_1);
    piVar15[0x16] = iVar6;
  }
  else {
    iVar6 = piVar15[0x15];
    if (iVar6 != 0) {
      iVar16 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar16 * 2] == 0) {
        special2(0,1,0,0x26);
        FUN_8005ba04(iVar16,0xffffffff);
        cVar2 = *(char *)(iVar6 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar16 * 2] = (&DAT_8024a55c)[iVar16 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar6 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar6 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar7 = *(int **)(iVar6 + 0xc);
        if (piVar7[0xb] != 0) {
          FUN_8006033c(piVar7 + 0xb,iVar6);
          piVar7 = *(int **)(iVar6 + 0xc);
        }
        pcVar8 = *(code **)(*piVar7 + 8);
LAB_800405dc:
        (*pcVar8)(piVar7,iVar6);
      }
      else if ((cVar2 == '\x01') &&
              (piVar7 = *(int **)(iVar6 + 0xc), *(char *)((int)piVar7 + 6) != '\0')) {
        pcVar8 = *(code **)(*piVar7 + 0x24);
        goto LAB_800405dc;
      }
      iVar6 = (int)sVar10;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar6 * 2] == 0) {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
        special2(0,1,0,0x26);
        piVar15[0x15] = 0;
      }
      else {
        special2(0,1,0,0x26);
        FUN_8005b738(iVar6);
        piVar15[0x15] = 0;
      }
    }
    piVar15[0x16] = -1;
  }
  piVar15[0x1a] = -1;
  piVar15[0x17] = -1;
  pbVar17 = param_2 + 0xc;
  piVar15[0x18] = -1;
  piVar15[0x19] = -1;
  (**(code **)(*param_1 + 0x54))(&local_50,param_1,*param_2);
  piVar15[9] = local_50;
  piVar15[10] = local_4c;
  piVar15[0xb] = local_48;
  piVar15[0xc] = local_44;
  piVar15[0xd] = local_40;
  uVar19 = 0x80040698;
  FUN_800413fc(&local_50,param_1,*param_2);
  iVar16 = piVar15[0x1b];
  iVar6 = *(int *)(param_2 + 0xc);
  piVar15[0xe] = local_50;
  piVar15[0xf] = local_4c;
  piVar15[0x10] = local_48;
  piVar15[0x11] = local_44;
  piVar15[0x12] = local_40;
  sVar10 = DAT_80248e1c;
  if (iVar16 == iVar6) {
LAB_80040818:
    iVar6 = *param_1;
  }
  else {
    if (iVar16 == 0) {
      iVar6 = *(int *)pbVar17;
    }
    else {
      iVar6 = (int)DAT_80248e1c;
      special2(0,0,0,0x26);
      if ((&DAT_8024a55c)[iVar6 * 2] == 0) {
        special2(0,1,0,0x26);
        uVar19 = 0x80040bac;
        FUN_8005ba04(iVar6,0xffffffff);
        cVar2 = *(char *)(iVar16 + 8);
      }
      else {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + -1;
        special2(0,1,0,0x26);
        cVar2 = *(char *)(iVar16 + 8);
      }
      cVar2 = cVar2 + -1;
      *(char *)(iVar16 + 8) = cVar2;
      if (cVar2 == '\0') {
        piVar7 = *(int **)(iVar16 + 0xc);
        if (piVar7[0xb] != 0) {
          FUN_8006033c(piVar7 + 0xb,iVar16);
          piVar7 = *(int **)(iVar16 + 0xc);
        }
        pcVar8 = *(code **)(*piVar7 + 8);
LAB_80040740:
        uVar19 = 0x80040748;
        (*pcVar8)(piVar7,iVar16);
      }
      else if ((cVar2 == '\x01') &&
              (piVar7 = *(int **)(iVar16 + 0xc), *(char *)((int)piVar7 + 6) != '\0')) {
        pcVar8 = *(code **)(*piVar7 + 0x24);
        goto LAB_80040740;
      }
      iVar6 = (int)sVar10;
      special2(0,0,0,0x26);
      if ((&DAT_8024a558)[iVar6 * 2] == 0) {
        (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
        special2(0,1,0,0x26);
        iVar6 = *(int *)pbVar17;
      }
      else {
        special2(0,1,0,0x26);
        uVar19 = 0x80040b58;
        FUN_8005b738(iVar6);
        iVar6 = *(int *)pbVar17;
      }
    }
    piVar15[0x1b] = iVar6;
    sVar10 = DAT_80248e1c;
    if (iVar6 == 0) goto LAB_80040818;
    iVar16 = (int)DAT_80248e1c;
    special2(0,0,0,0x26);
    if ((&DAT_8024a55c)[iVar16 * 2] == 0) {
      special2(0,1,0,0x26);
      uVar19 = 0x80040b40;
      FUN_8005ba04(iVar16,0xffffffff);
      cVar2 = *(char *)(iVar6 + 8);
    }
    else {
      (&DAT_8024a55c)[iVar16 * 2] = (&DAT_8024a55c)[iVar16 * 2] + -1;
      special2(0,1,0,0x26);
      cVar2 = *(char *)(iVar6 + 8);
    }
    *(char *)(iVar6 + 8) = cVar2 + '\x01';
    if ((char)(cVar2 + '\x01') < '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s_m_ref_cnt_0__>_0_8021181c,s_______________________________co_80211830,0x38,
                   uVar19);
    }
    iVar6 = (int)sVar10;
    special2(0,0,0,0x26);
    if ((&DAT_8024a558)[iVar6 * 2] == 0) {
      (&DAT_8024a55c)[iVar6 * 2] = (&DAT_8024a55c)[iVar6 * 2] + 1;
      special2(0,1,0,0x26);
      goto LAB_80040818;
    }
    special2(0,1,0,0x26);
    FUN_8005b738(iVar6);
    iVar6 = *param_1;
  }
  iVar6 = (**(code **)(iVar6 + 0x128))(param_1);
  piVar7 = *(int **)(param_2 + 4);
  if (iVar6 == 0) {
    uVar11 = piVar7[1] << 3;
  }
  else {
    uVar11 = piVar7[1] << 4;
  }
  iVar6 = *piVar7;
  uVar9 = (undefined2)(uVar11 >> bVar18);
  *(undefined2 *)((int)piVar15 + 6) = uVar9;
  *(undefined2 *)(piVar15 + 2) = uVar9;
  *(short *)(piVar15 + 1) = (short)(iVar6 << 4);
  *(undefined2 *)((int)piVar15 + 10) = 0;
  uVar12 = piVar15[3];
  uVar11 = (uint)(*(char *)((int)piVar7 + 0x22) == '\n') << 2;
  piVar15[3] = uVar12 & 0xfffffff3 | uVar11;
  piVar15[3] = uVar12 & 0xffffff03 | uVar11 |
               (uint)(*(char *)(*(int *)(param_2 + 4) + 0x21) == '\x02') << 4;
  iVar6 = *(int *)(param_2 + 4);
  bVar1 = *(byte *)(iVar6 + 0x21);
  if (bVar1 == 0) {
    bVar1 = *(byte *)(iVar6 + 0x1c);
LAB_800408b4:
    uVar5 = 2 - bVar1;
  }
  else {
    if (*(char *)(iVar6 + 0x23) != '\0') {
      bVar1 = *(byte *)(iVar6 + 0x1c);
      goto LAB_800408b4;
    }
    sVar10 = 1;
    if (bVar1 != 2) {
      bVar4 = 3;
      sVar10 = 1;
      if (bVar1 < 3) {
        sVar10 = 2;
        bVar4 = 1;
      }
      if (bVar1 != bVar4) {
        sVar10 = 0;
      }
    }
    uVar5 = sVar10 * (2 - (ushort)*(byte *)(iVar6 + 0x1c));
  }
  *(ushort *)(piVar15 + 5) = (short)*(undefined4 *)(iVar6 + 0x14) * (uVar5 & 0xff);
  bVar1 = *(byte *)(iVar6 + 0x21);
  if (bVar1 == 0) {
    bVar1 = *(byte *)(iVar6 + 0x1c);
  }
  else {
    if (*(char *)(iVar6 + 0x23) == '\0') {
      sVar10 = 1;
      if (bVar1 != 2) {
        bVar4 = 3;
        sVar10 = 1;
        if (bVar1 < 3) {
          sVar10 = 2;
          bVar4 = 1;
        }
        if (bVar1 != bVar4) {
          sVar10 = 0;
        }
      }
      uVar5 = sVar10 * (2 - (ushort)*(byte *)(iVar6 + 0x1c));
      goto LAB_800408f8;
    }
    bVar1 = *(byte *)(iVar6 + 0x1c);
  }
  uVar5 = 2 - bVar1;
LAB_800408f8:
  *(ushort *)((int)piVar15 + 0x16) = (short)*(undefined4 *)(iVar6 + 0x18) * (uVar5 & 0xff);
  bVar1 = *(byte *)(iVar6 + 0x21);
  if (bVar1 == 0) {
    sVar10 = 1;
  }
  else if (*(char *)(iVar6 + 0x23) == '\0') {
    sVar10 = 2;
    if (bVar1 != 2) {
      if (bVar1 < 3) {
        bVar4 = 1;
      }
      else {
        sVar10 = 1;
        bVar4 = 3;
      }
      if (bVar1 != bVar4) {
        sVar10 = 0;
      }
    }
  }
  else {
    sVar10 = 1;
  }
  *(short *)(piVar15 + 6) = (short)*(undefined4 *)(iVar6 + 0xc) * sVar10;
  bVar1 = *(byte *)(iVar6 + 0x21);
  if (bVar1 == 0) {
    sVar10 = 1;
  }
  else if (*(char *)(iVar6 + 0x23) == '\0') {
    sVar10 = 2;
    if (bVar1 != 2) {
      if (bVar1 < 3) {
        bVar4 = 1;
      }
      else {
        sVar10 = 1;
        bVar4 = 3;
      }
      if (bVar1 != bVar4) {
        sVar10 = 0;
      }
    }
  }
  else {
    sVar10 = 1;
  }
  *(short *)((int)piVar15 + 0x1a) = (short)*(undefined4 *)(iVar6 + 0x10) * sVar10;
  *(byte *)((int)piVar15 + 0x72) = *param_2;
  uVar3 = (**(code **)(*param_1 + 0x14c))(param_1);
  *(undefined1 *)((int)piVar15 + 0x73) = uVar3;
  puVar14 = *(uint **)(param_2 + 8);
  piVar15[0x1f] = *(int *)(param_2 + 0x14);
  piVar15[0x20] = *(int *)(param_2 + 0x18);
  *(bool *)(piVar15 + 0x1d) = (*puVar14 & 3) != 0;
  piVar15[3] = piVar15[3] & 0xffffe1ffU | (param_2[0x12] & 0xf) << 9;
  bVar1 = param_2[1];
  *(undefined2 *)(piVar15 + 0x1e) = 0;
  *(bool *)((int)piVar15 + 0x75) = bVar1 == 0;
  *(undefined1 *)(piVar15 + 7) = 0;
  *(undefined1 *)((int)piVar15 + 0x1d) = 0;
  *(undefined1 *)piVar15 = 0;
  *(undefined1 *)((int)piVar15 + 2) = 0;
  *(undefined1 *)((int)piVar15 + 3) = 0;
  piVar15[4] = 0;
  *(undefined2 *)((int)piVar15 + 0x76) = 0;
  return;
}

