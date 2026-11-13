// FUN_0028c7a8
// Ghidra address: 0028c7a8

void FUN_0028c7a8(long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = FUN_00291434(*(undefined8 *)(param_1 + 0x10),param_3);
  if ((cVar1 != '\0') &&
     (cVar1 = FUN_00291914(*(undefined8 *)(param_1 + 0x10),param_2,param_3), cVar1 == '\0')) {
    FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x47,0);
  }
                    /* WARNING: Could not recover jumptable at 0x0028c82c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(param_1 + 8) + 0x10))(*(long **)(param_1 + 8),param_3,param_4);
  return;
}

