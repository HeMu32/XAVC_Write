// FUN_80798678
// Ghidra address: 80798678

uint FUN_80798678(int param_1,uint *param_2,uint *param_3,int *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  
  uVar9 = 0;
  puVar7 = *(uint **)(param_1 + 0xc);
  local_40 = *(int *)(param_1 + 8) + 0x19b30;
  uVar5 = puVar7[0x2e];
  local_4c = 0;
  uVar4 = (uVar5 & 0x7ff) >> 3;
  local_44 = *(int *)(param_1 + 4);
  local_3c = 0;
  uVar12 = 0;
  if (uVar4 != 0) {
    uVar1 = puVar7[3];
    uVar12 = 0;
    local_38 = 0;
    uVar11 = 0;
    iVar10 = 0;
    if (uVar4 != 0) {
      puVar8 = puVar7 + 0x31;
      do {
        FUN_8079486c((*puVar7 & 0xff) >> 5,uVar1 + (uVar5 & 7),*puVar8,10,0,(*puVar7 & 0xf) >> 3);
        FUN_80788074(0,puVar7[2]);
        FUN_80794380(&local_50);
        local_48 = local_50;
        uVar2 = FUN_8078f298(local_50 & 0xff);
        if (iVar10 == 0) {
          uVar4 = FUN_80792530(uVar2,&local_4c,&local_48);
          local_3c = local_3c | uVar4;
          *param_2 = *param_2 | local_4c;
        }
        else if ((uVar12 == 0) && (iVar3 = FUN_8079233c(uVar2), uVar12 = uVar9, iVar3 == 0)) {
          uVar12 = 0;
        }
        iVar3 = FUN_80792324(uVar2);
        if (iVar3 == 0) {
          uVar5 = puVar7[0x2e];
        }
        else {
          if (iVar10 == 0) {
            iVar3 = *(int *)(local_40 + 4);
            DAT_807c0b18 = -1;
            DAT_807c0b1c = 0;
          }
          else {
            iVar3 = FUN_80798bd8();
          }
          uVar4 = 0;
          if (iVar3 <= DAT_807c0b18) {
            uVar4 = 1;
            DAT_807c0b1c = DAT_807c0b1c + 1;
            if (DAT_807c0b1c != 1) {
              uVar4 = 3;
            }
          }
          DAT_807c0b18 = iVar3;
          if (uVar4 != 0) {
            uVar5 = *param_5;
            if (uVar12 == 0) {
              uVar12 = uVar9;
            }
            *param_5 = uVar5 | uVar4;
            FUN_80787f3c(0x20,uVar11,iVar10,uVar12,uVar5 | uVar4);
          }
          if ((local_38 < 0x24) && (*param_5 == 0)) {
            puVar6 = (uint *)(local_38 * 8 + local_44 + 0x10);
            *puVar6 = uVar11 & 0xfff | iVar3 << 0xc;
            puVar6[1] = uVar9;
            local_38 = local_38 + 1;
          }
          iVar10 = iVar10 + 1;
          uVar5 = puVar7[0x2e];
        }
        uVar11 = uVar11 + 1;
        uVar9 = uVar9 + (uVar5 & 7) + *puVar8;
        uVar1 = puVar7[3] + uVar9;
        puVar8 = puVar8 + 1;
      } while (uVar11 < (uVar5 & 0x7ff) >> 3);
    }
    if (puVar7[4] != uVar9) {
      FUN_80787c50(puVar7[4],uVar9);
    }
    *param_3 = local_38;
    *param_4 = iVar10;
    uVar4 = 0;
    if ((*param_5 & 1) != 0) {
      uVar4 = uVar12;
    }
    *(uint *)(local_44 + 0xc) = uVar4;
    uVar12 = local_3c;
  }
  return uVar12;
}

