// FUN_80043cc0
// Ghidra address: 80043cc0

void FUN_80043cc0(int param_1,int param_2,short param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  puVar4 = (undefined4 *)(param_2 + 0x54);
  iVar7 = 0x3d;
  do {
    iVar7 = iVar7 + -1;
    *puVar4 = DAT_80247120;
    puVar4 = puVar4 + 1;
  } while (-1 < iVar7);
  iVar7 = 0x10;
  do {
    iVar8 = param_1 + 4;
    iVar2 = (**(code **)(*(int *)(param_1 + 4) + 8))(iVar8);
    if (iVar2 != 0) {
      uVar9 = 0x80043d7c;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x5c))(iVar8);
      if (0x3d < uVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_index_<_AVC_MAX_REF_PIC_ADR_INDE_80211a98,
                     s_______________________________sr_80211abc,0x13a,uVar9);
      }
      iVar2 = param_2 + uVar3 * 4;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x30))(iVar8);
      *(uint *)(iVar2 + 0x54) = *(uint *)(iVar2 + 0x54) & 0xffff9fff | (uVar3 & 3) << 0xd;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(iVar8);
      *(uint *)(iVar2 + 0x54) = *(uint *)(iVar2 + 0x54) & 0xffff7fff | (uVar3 & 1) << 0xf;
      sVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x44))(iVar8);
      *(short *)(iVar2 + 0x56) = param_3 - sVar1;
      *(uint *)(iVar2 + 0x54) = *(uint *)(iVar2 + 0x54) & 0xffffefff;
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x44))(iVar8);
      uVar9 = 0x80043e1c;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x60))(iVar8);
      if (0x3d < uVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_8000ae50(s_index_<_AVC_MAX_REF_PIC_ADR_INDE_80211a98,
                     s_______________________________sr_80211abc,0x149,uVar9);
      }
      iVar6 = param_2 + uVar3 * 4;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x30))(iVar8);
      *(uint *)(iVar6 + 0x54) = *(uint *)(iVar6 + 0x54) & 0xffff9fff | (uVar3 & 3) << 0xd;
      uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(iVar8);
      *(uint *)(iVar6 + 0x54) = *(uint *)(iVar6 + 0x54) & 0xffff7fff | (uVar3 & 1) << 0xf;
      sVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x48))(iVar8);
      iVar5 = *(int *)(param_1 + 4);
      *(short *)(iVar6 + 0x56) = param_3 - sVar1;
      iVar8 = (**(code **)(iVar5 + 0x48))(iVar8);
      if (iVar8 < iVar2) {
        uVar3 = *(uint *)(iVar6 + 0x54) | 0x1000;
      }
      else {
        uVar3 = *(uint *)(iVar6 + 0x54) & 0xffffefff;
      }
      *(uint *)(iVar6 + 0x54) = uVar3;
    }
    iVar7 = iVar7 + -1;
    param_1 = param_1 + 0x1f0;
    if (iVar7 < 0) {
      return;
    }
  } while( true );
}

