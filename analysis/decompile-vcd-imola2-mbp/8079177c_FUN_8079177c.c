// FUN_8079177c
// Ghidra address: 8079177c

/* WARNING: Removing unreachable block (ram,0x80791920) */
/* WARNING: Removing unreachable block (ram,0x80791a0c) */
/* WARNING: Removing unreachable block (ram,0x80791894) */
/* WARNING: Removing unreachable block (ram,0x80791a74) */

void FUN_8079177c(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  uint uVar8;
  undefined4 uVar9;
  
  DAT_807c0a90 = (undefined *)(param_1 + 0x1ec);
  uVar8 = *(byte *)(DAT_807c0a98 + 0x1e) + 1;
  uVar2 = *(byte *)(DAT_807c0a98 + 0x1f) + 1;
  if (DAT_807c0a90 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_80745808(&DAT_807c03a8,s_________________________src_ipsx_807afcd8,0x1b3);
  }
  DAT_807c0a94 = (undefined4 *)(param_1 + 0x26c);
  if (DAT_807c0a94 != (undefined4 *)0x0) {
    iVar3 = FUN_80791398();
    if ((iVar3 == 0) && (iVar4 = FUN_80791400(), iVar3 = DAT_807c0a98, iVar4 == 0)) {
      uVar5 = FUN_8079408c(1);
      uVar9 = 0x8079181c;
      *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffffe | uVar5 & 1;
      iVar3 = FUN_807913bc();
      if (iVar3 == 0) {
        iVar3 = FUN_807913dc();
        if (iVar3 != 0) {
          if (uVar8 != 0) {
            uVar5 = 1;
            do {
              bVar1 = uVar5 < uVar8;
              uVar5 = uVar5 + 1;
            } while (bVar1);
          }
          if ((*(uint *)(DAT_807c0a98 + 0x20) & 1) != 0) {
            FUN_80791dac(0,param_1 + 0x1ec,uVar8);
            DAT_807c0a90 = &DAT_80833998;
            if (uVar8 != 0) {
              uVar5 = 1;
              do {
                bVar1 = uVar5 < uVar8;
                uVar5 = uVar5 + 1;
              } while (bVar1);
            }
          }
          iVar3 = DAT_807c0a98;
          uVar8 = FUN_8079408c(1);
          *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffffd | (uVar8 & 1) << 1;
          if (uVar2 != 0) {
            uVar8 = 1;
            do {
              bVar1 = uVar8 < uVar2;
              uVar8 = uVar8 + 1;
            } while (bVar1);
          }
          if (*(int *)(DAT_807c0a98 + 0x20) << 0x1e < 0) {
            FUN_80791dac(1,param_1 + 0x26c,uVar2);
            DAT_807c0a94 = &DAT_80833a18;
            if (uVar2 != 0) {
              for (uVar8 = 1; uVar8 < uVar2; uVar8 = uVar8 + 1) {
              }
            }
          }
        }
      }
      else {
        if (uVar8 != 0) {
          for (uVar2 = 1; uVar2 < uVar8; uVar2 = uVar2 + 1) {
          }
        }
        puVar7 = (undefined *)(param_1 + 0x16c);
        if ((*(uint *)(DAT_807c0a98 + 0x20) & 1) == 0) {
          DAT_807c0a90 = puVar7;
          if (puVar7 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_80745808(&DAT_807c03a8,s_________________________src_ipsx_807afcd8,0x1b3,uVar9);
          }
        }
        else {
          FUN_80791dac(0,param_1 + 0x16c,uVar8);
          DAT_807c0a90 = &DAT_80833998;
          if (uVar8 != 0) {
            uVar2 = 1;
            do {
              bVar1 = uVar2 < uVar8;
              uVar2 = uVar2 + 1;
            } while (bVar1);
          }
        }
        uVar9 = DAT_807c03a0;
        puVar6 = &DAT_80833a18;
        iVar3 = 0x1f;
        do {
          iVar3 = iVar3 + -1;
          *puVar6 = uVar9;
          puVar6 = puVar6 + 1;
        } while (-1 < iVar3);
        DAT_807c0a94 = &DAT_80833a18;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_80745808(&DAT_807c03a8,s_________________________src_ipsx_807afcd8,0x1b3);
}

