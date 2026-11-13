// FUN_8079895c
// Ghidra address: 8079895c

void FUN_8079895c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_40;
  uint local_3c;
  
  puVar9 = *(uint **)(param_1 + 4);
  if ((puVar9[2] & 0x22) != 0) {
    iVar8 = *(int *)(param_1 + 8);
    puVar9[4] = puVar9[4] & 0xfffff000;
    uVar2 = DAT_807c0410;
    puVar9[4] = *(int *)(iVar8 + 0x19b34) << 0xc;
    puVar9[5] = uVar2;
    uVar2 = 0x80000000;
    if (*(int *)(iVar8 + 0x19b34) == 0) {
      local_3c = FUN_807914c0();
      uVar3 = FUN_8077fe78();
      uVar10 = 1;
      uVar12 = 1;
      uVar11 = 0;
      puVar7 = puVar9 + 2;
      uVar2 = 0xffffffff;
      do {
        FUN_80794380(&local_40);
        uVar1 = local_40;
        if ((local_40 & 0xff) == uVar3) break;
        uVar4 = FUN_8078f298(local_40 & 0xff);
        iVar8 = FUN_80792324(uVar4);
        if (iVar8 == 0) {
          uVar5 = uVar2;
          if (puVar9[3] == 0) {
            puVar9[3] = (uVar1 >> 8) - 0x15;
          }
        }
        else {
          uVar5 = FUN_80798bd8();
          if (uVar10 == 0) {
            DAT_807c0b18 = 0xffffffff;
            DAT_807c0b1c = 0;
          }
          uVar6 = 0;
          if ((int)uVar5 <= (int)DAT_807c0b18) {
            uVar6 = 1;
            DAT_807c0b1c = DAT_807c0b1c + 1;
            if (DAT_807c0b1c != 1) {
              uVar6 = 3;
            }
          }
          DAT_807c0b18 = uVar5;
          if (uVar6 != 0) {
            uVar11 = uVar11 | uVar6;
            uVar2 = 0xffffffff;
            if (puVar9[3] == 0) {
              puVar9[3] = (uVar1 >> 8) - 0x15;
            }
            FUN_80787f3c(0x20,0,uVar10,puVar9[3],uVar11);
          }
          if (uVar11 == 0) {
            uVar12 = uVar12 + 1;
            if ((int)uVar5 <= (int)uVar2 || local_3c <= uVar5) {
              uVar2 = puVar9[1] | 0x80000000;
              goto LAB_807989dc;
            }
            if (uVar10 < 0x24) {
              puVar7[4] = uVar10 & 0xfff | uVar5 << 0xc;
              puVar7[5] = uVar1 >> 8;
            }
            uVar10 = uVar10 + 1;
            puVar7 = puVar7 + 2;
          }
          else {
            uVar12 = uVar12 + 1;
            uVar5 = uVar2;
          }
        }
        uVar2 = uVar5;
      } while (uVar10 < 0x48);
      uVar2 = 0x24;
      if (uVar10 < 0x25) {
        uVar2 = uVar10;
      }
      *puVar9 = *puVar9 & 0xfff00009 | (uVar12 & 0xff) << 0xc | (uVar2 & 0xff) << 4 |
                (uVar11 & 1) << 1;
      for (puVar7 = (uint *)((uint)puVar9 & 0xffffffc0); puVar7 < puVar9 + 0x4c;
          puVar7 = puVar7 + 0x10) {
        cacheOp(0x1a,puVar7);
      }
      SYNC(0);
    }
    else {
LAB_807989dc:
      puVar9[1] = uVar2;
    }
  }
  return;
}

