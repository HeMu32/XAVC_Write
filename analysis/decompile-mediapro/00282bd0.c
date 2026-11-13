// Ghidra: 00282bd0; ELF VMA = Ghidra - 0x100000

undefined8 catalog_00282bd0(long param_1,int param_2)

{
  if (param_2 != 10) {
    if (param_2 < 0xb) {
      if (param_2 == 0) {
        return 0;
      }
      if (param_2 == 3) goto LAB_00282c18;
    }
    else {
      if (param_2 == 0xe) {
        *(undefined4 *)(param_1 + 0x28) = 1;
        return 0x65;
      }
      if (param_2 == 0x11) {
        *(undefined4 *)(param_1 + 0x28) = 2;
        return 0;
      }
    }
    return 0x6c;
  }
LAB_00282c18:
  *(undefined4 *)(param_1 + 0x28) = 1;
  return 0x66;
}

