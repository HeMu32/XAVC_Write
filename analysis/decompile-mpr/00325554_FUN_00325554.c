// FUN_00325554
// Ghidra address: 00325554

void FUN_00325554(long param_1,int param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  int iVar1;
  uint __line;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = *(undefined8 *)(param_1 + 0x260);
  local_8 = 0;
  uVar4 = param_3 & 0xffffffff;
  uVar5 = param_4 & 0xffffffff;
  if (*(int *)(param_1 + 0x1d8) == 0x61766331) {
    if (param_2 == 0) {
      FUN_002cd028(*(undefined8 *)(param_1 + 0x108),uVar3,param_3,param_4,&local_8);
      iVar1 = FUN_00322428();
      if (iVar1 != 0) {
        return;
      }
      FUN_002cd234(*(undefined8 *)(param_1 + 0x108),uVar3,uVar4,uVar5,local_8,param_5);
    }
    else {
      if (param_2 != 1) {
        sleep(1);
        __line = 0x710;
LAB_003255b8:
                    /* WARNING: Subroutine does not return */
        __assert_fail("0","libXavcMp4.cpp",__line,
                      "int libXavcMp4::GetParameterSet(libXavcMp4::ParameterSetType, uint32_t, uint32_t, uint8_t*)"
                     );
      }
      FUN_002cd0d4(*(undefined8 *)(param_1 + 0x108),uVar3);
      iVar1 = FUN_00322428();
      if (iVar1 != 0) {
        return;
      }
      FUN_002cd340(*(undefined8 *)(param_1 + 0x108),uVar3,uVar4,uVar5,local_8,param_5);
    }
    FUN_00322428();
    return;
  }
  if (param_2 == 1) {
    uVar2 = 0x22;
  }
  else if (param_2 == 0) {
    uVar2 = 0x21;
  }
  else {
    if (param_2 != 2) {
      sleep(1);
      __line = 0x71b;
      goto LAB_003255b8;
    }
    uVar2 = 0x20;
  }
  iVar1 = FUN_00325358(param_1,uVar3,uVar4,uVar2);
  local_4 = 0;
  if (iVar1 == 0) {
    FUN_002cd930(*(undefined8 *)(param_1 + 0x108),uVar3,uVar4,0,uVar5,&local_4);
    iVar1 = FUN_00322428();
    if (iVar1 == 0) {
      FUN_002cda14(*(undefined8 *)(param_1 + 0x108),uVar3,uVar4,0,uVar5,local_4,param_5);
    }
  }
  return;
}

