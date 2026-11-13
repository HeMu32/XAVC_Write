// FUN_0028d590
// Ghidra address: 0028d590

undefined8 FUN_0028d590(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_2 != 0) {
    if (**(uint **)(param_1 + 0x60) < param_2) {
      uVar1 = 0x4c3;
      goto LAB_0028d5b4;
    }
    if (0x3a95 < param_2) {
      uVar1 = 0x4c8;
      goto LAB_0028d5b4;
    }
  }
  if ((char)(*(uint **)(param_1 + 0x60))[0x3b3c] == '\0') {
    return 0;
  }
  uVar1 = 0x4ce;
LAB_0028d5b4:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar1,0x67);
  return 0x67;
}

