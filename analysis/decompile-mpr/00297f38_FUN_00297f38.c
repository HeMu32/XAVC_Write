// FUN_00297f38
// Ghidra address: 00297f38

int FUN_00297f38(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_18;
  undefined4 local_10;
  char local_c;
  int local_8;
  
  do {
    FUN_00291228(&local_18,param_3);
    if (local_8 != 0) {
      uVar2 = 0x1fc;
      iVar1 = local_8;
LAB_00297f70:
      FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",uVar2,iVar1);
      return iVar1;
    }
    iVar1 = FUN_00291f58(param_2,local_18,local_10);
    if (iVar1 != 0) {
      uVar2 = 0x202;
      goto LAB_00297f70;
    }
    if (local_c != '\0') {
      return 0;
    }
  } while( true );
}

