// FUN_80043f00
// Ghidra address: 80043f00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043f00(int param_1,int param_2,int param_3,uint *param_4,char param_5,char param_6)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = _DAT_be000064;
  bVar3 = false;
  if ((*(uint *)(*(int *)(param_3 + 0x88) + 0x10) & 0x100000) != 0) {
    bVar3 = (*(uint *)(*(int *)(param_3 + 0x88) + 0x19b30) & 0x100000) == 0;
  }
  if (*(int *)(param_1 + 0x50) < 1) {
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(s___Fatal___80247130,s_______________________________co_80211b74,0x8f);
  }
  bVar1 = **(byte **)(param_1 + 0x4c);
  if (bVar1 != 1) {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined4 *)(param_2 + 0x68) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x5c) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x60) = 0xffffffff;
        *(undefined4 *)(param_2 + 100) = 0xffffffff;
        return;
      }
    }
    else if (bVar1 == 2) {
      iVar6 = *(int *)(param_3 + 0x114) >> 0xc;
      if (bVar3) {
        uVar7 = *param_4;
        uVar5 = iVar6 << 5;
      }
      else {
        uVar7 = *param_4;
        uVar5 = iVar6 << 4;
      }
      if (uVar7 == 0) {
        trap(7);
      }
      *(short *)(param_2 + 8) = (short)(uVar5 / uVar7 >> (param_6 != '\0' && param_5 == '\0'));
      *(int *)(param_2 + 0x5c) = *(int *)(param_3 + 0xd4) - iVar4;
      iVar4 = _DAT_be000064;
      iVar6 = *(int *)(param_3 + 0xdc);
      *(short *)(param_2 + 10) = *(short *)(param_2 + 6) - *(short *)(param_2 + 8);
      iVar6 = iVar6 - iVar4;
      goto LAB_80044044;
    }
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(&DAT_80247124,s_______________________________sr_80211b18,0x3e);
  }
  iVar6 = *(int *)(param_3 + 0xd4);
  uVar2 = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(param_2 + 8) = 0;
  *(int *)(param_2 + 0x5c) = iVar6 - iVar4;
  iVar4 = _DAT_be000064;
  iVar6 = *(int *)(param_3 + 0xdc);
  *(undefined2 *)(param_2 + 10) = uVar2;
  iVar6 = iVar6 - iVar4;
LAB_80044044:
  *(int *)(param_2 + 0x60) = iVar6;
  *(int *)(param_2 + 100) = *(int *)(param_3 + 0xd8) - _DAT_be000064;
  *(int *)(param_2 + 0x68) = *(int *)(param_3 + 0xe0) - _DAT_be000064;
  return;
}

