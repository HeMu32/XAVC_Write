// ELF VMA 0x3594ab8; Ghidra bias 0x100000

bool appfw_3594ab8(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  int aiStack_8 [2];
  
  uStack_10 = param_3;
  uStack_c = param_2;
  func_0x036a974c(&uStack_10,aiStack_8);
  return aiStack_8[0] != -1;
}

