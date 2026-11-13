// FUN_80796d3c
// Ghidra address: 80796d3c

undefined4 FUN_80796d3c(uint param_1)

{
  undefined2 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  puVar4 = DAT_807c0b00;
  iVar3 = DAT_807c0af8;
  if ((DAT_807c03f0 < 0x10) && (DAT_807c0b00 != (undefined1 *)0x0)) {
    DAT_807c03f4 = DAT_807c03f4 + param_1;
    if (DAT_807c03f4 < 0x241) {
      uVar1 = (undefined2)DAT_807c03f4;
      *(short *)((uint)DAT_807c03f0 * 2 + DAT_807c0af8 + 0x44) = (short)param_1;
      uVar5 = 0;
      *(undefined2 *)(iVar3 + 0x40) = uVar1;
      if (param_1 != 0) {
        do {
          DAT_807c0b00 = puVar4 + 1;
          DAT_807c03e8 = DAT_807c03e8 + 8;
          uVar5 = uVar5 + 1;
          uVar2 = FUN_8079408c(8);
          *puVar4 = uVar2;
          iVar3 = DAT_807c0af8;
          puVar4 = DAT_807c0b00;
        } while (uVar5 < param_1);
      }
    }
    else {
      FUN_80796334(param_1);
      iVar3 = DAT_807c0af8;
    }
    DAT_807c03f0 = DAT_807c03f0 + 1;
    *(byte *)(iVar3 + 0x42) = DAT_807c03f0;
  }
  else {
    FUN_80796334();
  }
  return 1;
}

