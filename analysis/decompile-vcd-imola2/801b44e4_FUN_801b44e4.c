// FUN_801b44e4
// Ghidra address: 801b44e4

void FUN_801b44e4(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_40 [4];
  short local_30;
  
  uVar4 = 0x801b4514;
  FUN_80059544(param_1 + 0x6374);
  uVar3 = *param_2;
  if (*(int *)(param_1 + 0x426c) != 0) {
    if (*(int *)(param_1 + 17000) < 1) {
                    /* WARNING: Subroutine does not return */
      FUN_8000ae50(s___Fatal___802470e8,s_______________________________co_80211678,0x8f,uVar4);
    }
    iVar2 = **(int **)(param_1 + 0x4264);
    local_40[0] = iVar2;
    if (iVar2 != 0) {
      uVar4 = 0x801b468c;
      local_30 = DAT_80248e1c;
      FUN_8003fb70((int)DAT_80248e1c,0xffffffff);
      cVar1 = *(char *)(iVar2 + 8) + '\x01';
      *(char *)(iVar2 + 8) = cVar1;
      if (cVar1 < '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_m_ref_cnt_0__>_0_802113e0,s_______________________________co_802113f4,0x38,
                     uVar4);
      }
      FUN_8003fb04((int)local_30);
    }
    FUN_801aeb74(local_40,1,uVar3 & 1,(uVar3 & 3) >> 1);
    if (0 < *(int *)(param_1 + 0x426c)) {
      *(int *)(param_1 + 0x426c) = *(int *)(param_1 + 0x426c) + -1;
      FUN_801aea2c();
    }
    FUN_800177e8(param_1 + 0x28);
    uVar4 = 0x801b4578;
    FUN_801b257c(local_40);
  }
  if (*(int *)(param_1 + 0x4150) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(&DAT_802470d4,s_______________________________sr_802116c8,0x6d,uVar4);
  }
  if (*(int *)(param_1 + 0x414c) < 1) {
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(s___Fatal___802470e8,s_______________________________co_80211678,0x8f,uVar4);
  }
  cVar1 = **(char **)(param_1 + 0x4148);
  if (0 < *(int *)(param_1 + 0x4150)) {
    *(int *)(param_1 + 0x4150) = *(int *)(param_1 + 0x4150) + -1;
    FUN_801b34f0(param_1 + 0x4104);
  }
  if (cVar1 == '\x02') {
    if ((byte)(*(char *)(param_1 + 0x40fc) - 2U) < 3) {
      FUN_8002a604(*(undefined4 *)(param_1 + 0x40f8));
    }
    FUN_80043b58(param_1 + 0x4274);
    (**(code **)(**(int **)(param_1 + 0x4058) + 0x10))();
  }
  return;
}

