// FUN_80799d9c
// Ghidra address: 80799d9c

undefined4 FUN_80799d9c(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = DAT_807c0b44;
  iVar2 = DAT_807c0b3c;
  if ((DAT_807c0439 < 0x10) && (DAT_807c0b44 != (undefined1 *)0x0)) {
    DAT_807c043c = DAT_807c043c + param_1;
    if (DAT_807c043c < 0x241) {
      *(short *)((uint)DAT_807c0439 * 2 + DAT_807c0b3c + 0x7c) = (short)param_1;
      *(undefined2 *)(iVar2 + 0x78) = (undefined2)DAT_807c043c;
      if (0 < param_1) {
        do {
          DAT_807c0b44 = puVar3 + 1;
          DAT_807c0430 = DAT_807c0430 + 8;
          param_1 = param_1 + -1;
          uVar1 = FUN_8079408c(8);
          *puVar3 = uVar1;
          iVar2 = DAT_807c0b3c;
          puVar3 = DAT_807c0b44;
        } while (param_1 != 0);
      }
    }
    else {
      FUN_80798fc4();
      iVar2 = DAT_807c0b3c;
    }
    DAT_807c0439 = DAT_807c0439 + 1;
    *(byte *)(iVar2 + 0x7a) = DAT_807c0439;
  }
  else {
    FUN_80798fc4();
  }
  return 1;
}

