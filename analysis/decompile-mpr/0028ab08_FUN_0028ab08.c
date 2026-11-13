// FUN_0028ab08
// Ghidra address: 0028ab08

int FUN_0028ab08(long *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  long *plVar2;
  
  if (param_1[1] == 0) {
    iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,param_4);
    if ((iVar1 == 0) && (plVar2 = (long *)param_1[1], plVar2 != (long *)0x0)) {
      iVar1 = (**(code **)(*plVar2 + 0x10))(plVar2,param_3);
      if (iVar1 != 0) {
        FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x25,iVar1);
      }
    }
    else {
      iVar1 = 1;
      FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x1f,1);
    }
  }
  else {
    iVar1 = 0xb;
    FUN_00290aa4(0,"xavcIfo_CommonMediaProfileParser.cpp",0x17,0xb);
  }
  return iVar1;
}

