// FUN_800b9c4c
// Ghidra address: 800b9c4c

void FUN_800b9c4c(int param_1,byte param_2,char *param_3,char param_4)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_retaddr;
  
  cVar2 = *(char *)(param_1 + 0x39cf);
  *(char *)(param_1 + 0x39cf) = cVar2 + '\x01';
  *param_3 = cVar2;
  if (param_2 == 2) {
    cVar2 = *(char *)(param_1 + 0x5641);
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_1 + 0x55cc);
    bVar1 = *(byte *)(param_1 + 0x5640);
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
LAB_800b9cb8:
                    /* WARNING: Subroutine does not return */
        FUN_80006cec(&DAT_802ec244,s_avcdec_ctrl_cxx_802ec248,0x213);
      }
      iVar4 = *(int *)(param_1 + 0x552c);
      cVar2 = *(char *)(param_1 + 0x55a1);
    }
    else {
      if (param_2 != 3) goto LAB_800b9cb8;
      cVar2 = *(char *)(param_1 + 0x55a1);
      iVar4 = *(int *)(param_1 + 0x552c) + *(int *)(param_1 + 0x55cc);
    }
    *(int *)(param_3 + 0x14) = iVar4;
    bVar1 = *(byte *)(param_1 + 0x55a0);
  }
  uVar9 = (uint)bVar1;
  if (cVar2 == '\0') {
    if (*(char *)(param_1 + 0x39d2) == '\x01') {
      param_3[3] = '\0';
      goto LAB_800b9d08;
    }
    iVar4 = *(int *)(param_1 + 0x552c);
LAB_800b9e94:
    cVar2 = '\x04';
    if (iVar4 <= *(int *)(param_1 + 0x55cc)) {
      cVar2 = '\x03';
    }
    param_3[3] = cVar2;
  }
  else {
    if (*(char *)(param_1 + 0x39d2) == '\x01') {
      if (uVar9 == 0 || uVar9 == 7) {
        param_3[3] = bVar1;
      }
      else if (uVar9 == 8) {
        param_3[3] = bVar1;
      }
      else {
        param_3[3] = '\0';
      }
      goto LAB_800b9d08;
    }
    if (3 < uVar9 - 3) {
      iVar4 = *(int *)(param_1 + 0x552c);
      goto LAB_800b9e94;
    }
    param_3[3] = bVar1;
  }
  *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x2000000;
LAB_800b9d08:
  if (*(char *)(param_1 + 0x39c2) == '\0' || *(char *)(param_1 + 0x39c2) == '\x04') {
    unaff_retaddr = 0x800b9e50;
    iVar4 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x54c0) + 8))();
    if (iVar4 == 2) {
      param_3[2] = '\0';
    }
    else {
      unaff_retaddr = 0x800b9e64;
      uVar8 = FUN_800baca8(param_1);
      uVar9 = (*(uint *)(*(int *)(param_1 + 0x565c) + 4) & 0x3fffffff) >> 0x19;
      if (uVar8 < uVar9) {
        unaff_retaddr = 0x800b9e8c;
        uVar9 = FUN_800baca8(param_1);
      }
      param_3[2] = (char)uVar9;
    }
  }
  else {
    param_3[2] = '\0';
  }
  *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) & 0xfeffffff | (uint)(param_4 != '\0') << 0x18;
  uVar7 = 0;
  if (param_4 != '\0') {
    uVar7 = 0;
    if (*(int *)(param_1 + 0x39ac) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_80006cec(&DAT_802ec258,s_________________________Src_Comm_8018bf74,99,unaff_retaddr);
    }
    uVar8 = *(uint *)(*(int *)(param_1 + 0x39ac) + 4);
    uVar9 = uVar8 + 0x80000000;
    if (0x3fffffff < uVar8) {
      uVar9 = uVar8 & 0x1fffffff;
    }
    if (*(int *)(uVar9 + 4) == 0) {
      if (*(int *)(param_1 + 0x39b0) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_80006cec(&DAT_802ec258,s_________________________Src_Comm_8018bf74,99,unaff_retaddr);
      }
      uVar9 = *(uint *)(*(int *)(param_1 + 0x39b0) + 4);
      piVar6 = (int *)(uVar9 + 0x80000000);
      if (0x3fffffff < uVar9) {
        piVar6 = (int *)(uVar9 & 0x1fffffff);
      }
      if (*piVar6 != 0) {
        uVar7 = 2;
      }
    }
    else {
      uVar7 = 1;
    }
  }
  uVar3 = *(undefined4 *)(param_1 + 0x563c);
  uVar5 = *(undefined4 *)(param_1 + 0x559c);
  *(undefined2 *)(param_3 + 0xc) = uVar7;
  *(short *)(param_3 + 0x60) = (short)uVar3;
  *(short *)(param_3 + 0x5e) = (short)uVar5;
  return;
}

