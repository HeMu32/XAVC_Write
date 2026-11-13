// FUN_800b7c64
// Ghidra address: 800b7c64

void FUN_800b7c64(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *local_50 [4];
  short local_40;
  undefined4 local_30;
  
  uVar6 = 3;
  uVar7 = 0x800b7ca0;
  iVar2 = (**(code **)(*param_1 + 0x68))();
  if (iVar2 == 3) {
    iVar2 = param_1[9];
  }
  else {
    uVar6 = 1;
    if (*(int *)param_1[0x1599] << 10 < 0) {
      uVar6 = 2;
    }
    iVar2 = param_1[9];
  }
  local_50[0] = (int *)0x0;
  uVar5 = *(uint *)(iVar2 + 0x1c);
  if (0x1c < uVar5) {
    iVar2 = 0;
    if (uVar5 < 0x11d) {
      iVar2 = (&DAT_80304ed0)[uVar5];
    }
  }
  else {
    iVar2 = (&DAT_80304ed0)[uVar5];
  }
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_80006cec(&DAT_802ec240,s_________________________Src_Comm_8018bf74,0x25,uVar7);
  }
  if (0x1c < uVar5) {
    piVar4 = (int *)0x0;
    if (uVar5 < 0x11d) {
      piVar4 = (int *)(&DAT_80304ed0)[uVar5];
    }
  }
  else {
    piVar4 = (int *)(&DAT_80304ed0)[uVar5];
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_80006cec(&DAT_802ec240,s_________________________Src_Comm_8018bf74,0x25,uVar7);
  }
  uVar7 = (**(code **)(*piVar4 + 8))(piVar4);
  uVar8 = 0x800b7d44;
  iVar2 = FUN_8011f194(local_50,iVar2,uVar7,0,0);
  if (iVar2 == 0) {
    uVar8 = 0x800b7d60;
    FUN_8015243c(local_50,0,0,0);
    iVar2 = param_1[0xeba];
    if (iVar2 != 0x42) {
      if (iVar2 < 0x42) {
        param_1[0xeba] = iVar2 + 1;
        if (param_1[0xeb9] < 0x42) {
          iVar2 = param_1[0xeb9] + 1;
          param_1[0xeb9] = iVar2;
          if (iVar2 != 1) {
            piVar4 = (int *)(param_1[0xeb7] + 4U);
            if (param_1 + 0xeb6 < (int *)(param_1[0xeb7] + 4U)) {
              piVar4 = param_1 + 0xe75;
            }
            param_1[0xeb7] = (int)piVar4;
          }
          puVar3 = (undefined4 *)FUN_8011aab0(4,param_1[0xeb7]);
          *puVar3 = local_50[0];
          if (local_50[0] != (int *)0x0) {
            FUN_8011f854(local_50[0] + 3,1);
            uVar1 = *(undefined1 *)((int)param_1 + 0x39d2);
            goto LAB_800b7dd8;
          }
        }
        uVar1 = *(undefined1 *)((int)param_1 + 0x39d2);
      }
      else {
        uVar1 = *(undefined1 *)((int)param_1 + 0x39d2);
      }
LAB_800b7dd8:
      FUN_800be3f8(param_1 + 0x1532,uVar6,uVar1,*(undefined1 *)((int)param_1 + 0x39d3),
                   param_1 + 0x15b0,param_1[0x1599],param_2,local_50,
                   *(undefined1 *)((int)param_1 + 0x39cd),*(undefined1 *)((int)param_1 + 0x39ce));
      uVar1 = FUN_800b7ffc(param_1,(char)param_1[0x153b]);
      piVar4 = local_50[0];
      *(undefined1 *)((int)param_1 + 0x16) = uVar1;
      if (local_50[0] != (int *)0x0) {
        local_40 = **(short **)(*local_50[0] + 0x20);
        iVar2 = (int)local_40;
        special2(0,0,0,0x26);
        if ((&DAT_802ee8b0)[iVar2 * 2] == 0) {
          special2(0,1,0,0x26);
          local_30 = FUN_800f216c(iVar2,0xffffffff);
        }
        else {
          (&DAT_802ee8b0)[iVar2 * 2] = (&DAT_802ee8b0)[iVar2 * 2] + -1;
          local_30 = 1;
          special2(0,1,0,0x26);
        }
        special2(0,local_30,0,0x24);
        special2(0,0,0,0x26);
        iVar2 = piVar4[3];
        *(char *)(piVar4 + 3) = (char)iVar2 + -1;
        special2(0,local_30,0,0x26);
        FUN_8011c8c4(piVar4,(char)iVar2 + -1);
        iVar2 = (int)local_40;
        special2(0,0,0,0x26);
        if (*(int *)(&DAT_802ee8ac + iVar2 * 8) == 0) {
          (&DAT_802ee8b0)[iVar2 * 2] = (&DAT_802ee8b0)[iVar2 * 2] + 1;
          special2(0,1,0,0x26);
        }
        else {
          special2(0,1,0,0x26);
          FUN_800f1ea0(iVar2);
        }
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_80006cec(&DAT_802ec244,s_avcdec_ctrl_cxx_802ec248,0x45,uVar8);
}

