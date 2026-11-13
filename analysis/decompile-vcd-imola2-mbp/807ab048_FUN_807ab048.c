// FUN_807ab048
// Ghidra address: 807ab048

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_807ab048(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint *puVar5;
  short sVar6;
  
  puVar5 = *(uint **)(param_1 + 8);
  *puVar5 = *puVar5 & 0x5fffffff;
LAB_807ab088:
  do {
    iVar2 = FUN_80794318();
    if ((iVar2 - 1U & 0xff) < 0xaf || iVar2 == 0xff) {
      iVar2 = 1;
    }
  } while (iVar2 == 0xb4);
  if (iVar2 < 0xb5) {
    if (iVar2 == 1) {
      return 0;
    }
    if (iVar2 < 2) goto LAB_807ab1f0;
    if (iVar2 == 0xb2) {
      FUN_807acb00();
      if (((DAT_807c05dd < 0x10) && (_DAT_807c05e0 < 0x200)) &&
         (sVar6 = 0, puVar4 = DAT_807c0b90, DAT_807c0b90 != (undefined1 *)0x0)) {
        do {
          DAT_807c0b90 = puVar4 + 1;
          _DAT_807c05e0 = _DAT_807c05e0 + 1;
          sVar6 = sVar6 + 1;
          uVar1 = FUN_8079408c(8);
          *puVar4 = uVar1;
          iVar2 = FUN_807945c4();
          if (iVar2 != 0) break;
          puVar4 = DAT_807c0b90;
        } while (_DAT_807c05e0 < 0x200);
        uVar3 = (uint)DAT_807c05dd;
        DAT_807c05dd = DAT_807c05dd + 1;
        *(short *)(uVar3 * 2 + *(int *)(param_1 + 8) + 0x1e8) = sVar6;
      }
      goto LAB_807ab13c;
    }
    if (iVar2 != 0xb3) goto LAB_807ab088;
    *puVar5 = *puVar5 & 0xafffffff | 0x20000000;
    FUN_807ac4b4(param_1);
    FUN_807ad094(param_1);
    FUN_807abb5c(param_1);
    FUN_807abb38(param_1);
    FUN_807acb00();
    FUN_807ac5b4(param_1);
  }
  else {
    if (iVar2 < 0xb8) {
      if (iVar2 < 0xb6) {
        FUN_807acb00();
        uVar1 = FUN_8079408c(4);
        FUN_807ab414(uVar1,param_1);
        goto LAB_807ab13c;
      }
      goto LAB_807ab088;
    }
    if (iVar2 != 0xb8) goto LAB_807ab088;
    *puVar5 = *puVar5 | 0x80000000;
    FUN_807acb00();
    FUN_807ad0a0(param_1);
  }
  goto LAB_807ab13c;
LAB_807ab1f0:
  if (iVar2 != 0) goto LAB_807ab088;
  FUN_807abb38(param_1);
  FUN_807acb00();
  FUN_807ab508(param_1);
LAB_807ab13c:
  FUN_807aca74();
  goto LAB_807ab088;
}

