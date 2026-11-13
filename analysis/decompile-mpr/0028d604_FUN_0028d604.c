// FUN_0028d604
// Ghidra address: 0028d604

undefined8 FUN_0028d604(long param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  if (param_2 == (uint *)0x0) {
    uVar4 = 0x4d9;
  }
  else if (param_3 == 0) {
    uVar4 = 0x4de;
  }
  else {
    uVar2 = **(uint **)(param_1 + 0x60);
    if (*param_2 < uVar2) {
      puVar1 = param_2 + (ulong)(param_3 - 1) + 1;
      uVar5 = *param_2;
      do {
        param_2 = param_2 + 1;
        if (param_2 == puVar1) {
          if ((char)(*(uint **)(param_1 + 0x60))[0x3b3c] == '\0') {
            return 0;
          }
          uVar4 = 0x4f8;
          goto LAB_0028d618;
        }
        uVar3 = *param_2;
        if (uVar3 <= uVar5) {
          uVar4 = 0x4ec;
          goto LAB_0028d618;
        }
        uVar5 = uVar3;
      } while (uVar3 < uVar2);
      uVar4 = 0x4f1;
    }
    else {
      uVar4 = 0x4e4;
    }
  }
LAB_0028d618:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar4,0x67);
  return 0x67;
}

