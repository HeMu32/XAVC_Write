// FUN_0028ce40
// Ghidra address: 0028ce40

int FUN_0028ce40(undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4)

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
      uVar2 = 0x50e;
      iVar1 = local_8;
LAB_0028ce88:
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar2,iVar1);
      return iVar1;
    }
    if (param_4 == '\0') {
      iVar1 = FUN_00291f58(param_2,local_18,local_10);
    }
    else {
      iVar1 = FUN_00291dfc();
    }
    if (iVar1 != 0) {
      uVar2 = 0x51a;
      goto LAB_0028ce88;
    }
    if (local_c != '\0') {
      return 0;
    }
  } while( true );
}

