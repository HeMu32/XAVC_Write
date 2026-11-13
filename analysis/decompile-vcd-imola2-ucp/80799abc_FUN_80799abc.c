// FUN_80799abc
// Ghidra address: 80799abc

undefined4 FUN_80799abc(void)

{
  int *piVar1;
  uint *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_807c0b40;
  piVar1 = DAT_807c0b38;
  if (DAT_807c0438 == '\0') {
    FUN_80798fc4();
  }
  else {
    *DAT_807c0b38 = 1;
    *puVar2 = *puVar2 | 0x1000000;
    iVar4 = FUN_80799324();
    *piVar1 = iVar4;
    piVar1 = DAT_807c0b38;
    DAT_807c0430 = DAT_807c0430 + 1;
    uVar5 = FUN_8079408c(1);
    piVar1[1] = piVar1[1] & 0xfffffffeU | uVar5 & 1;
    piVar1 = DAT_807c0b38;
    if ((DAT_807c0b38[1] & 1U) == 0) {
      DAT_807c0430 = DAT_807c0430 + 7;
      uVar5 = FUN_8079408c(7);
      piVar1[1] = piVar1[1] & 0xffffff01U | (uVar5 & 0x7f) << 1;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xfffffeffU | (uVar5 & 1) << 8;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 6;
      uVar5 = FUN_8079408c(6);
      piVar1[1] = piVar1[1] & 0xffff81ffU | (uVar5 & 0x3f) << 9;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xffff7fffU | (uVar5 & 1) << 0xf;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xfffeffffU | (uVar5 & 1) << 0x10;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xfffdffffU | (uVar5 & 1) << 0x11;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xfffbffffU | (uVar5 & 1) << 0x12;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xfff7ffffU | (uVar5 & 1) << 0x13;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      uVar5 = FUN_8079408c(1);
      piVar1[1] = piVar1[1] & 0xffefffffU | (uVar5 & 1) << 0x14;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 4;
      uVar5 = FUN_8079408c(4);
      piVar1[1] = piVar1[1] & 0xfe1fffffU | (uVar5 & 0xf) << 0x15;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 4;
      uVar5 = FUN_8079408c(4);
      piVar1[1] = piVar1[1] & 0xe1ffffffU | (uVar5 & 0xf) << 0x19;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 4;
      uVar5 = FUN_8079408c(4);
      piVar1[2] = piVar1[2] & 0xfffffff0U | uVar5 & 0xf;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 4;
      uVar5 = FUN_8079408c(4);
      piVar1[2] = piVar1[2] & 0xffffff0fU | (uVar5 & 0xf) << 4;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 8;
      uVar3 = FUN_8079408c(8);
      *(undefined1 *)((int)piVar1 + 9) = uVar3;
      piVar1 = DAT_807c0b38;
      uVar5 = FUN_80799324();
      piVar1[2] = piVar1[2] & 0x8000ffffU | (uVar5 & 0x7fff) << 0x10;
      piVar1 = DAT_807c0b38;
      DAT_807c0430 = DAT_807c0430 + 1;
      iVar4 = FUN_8079408c(1);
      piVar1[2] = piVar1[2] & 0x7fffffffU | iVar4 << 0x1f;
      iVar4 = *DAT_807c0b38;
    }
    else {
      iVar4 = *DAT_807c0b38;
    }
    if (iVar4 == 0) {
      DAT_807c0438 = '\0';
    }
  }
  return 1;
}

