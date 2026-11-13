// FUN_00325424
// Ghidra address: 00325424

void FUN_00325424(long param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5)

{
  int iVar1;
  uint __line;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x260);
  if (*(int *)(param_1 + 0x1d8) == 0x61766331) {
    if (param_2 == 0) {
      FUN_002cd028(*(undefined8 *)(param_1 + 0x108),uVar3);
    }
    else {
      if (param_2 != 1) {
        sleep(1);
        __line = 0x6e2;
LAB_00325474:
                    /* WARNING: Subroutine does not return */
        __assert_fail("0","libXavcMp4.cpp",__line,
                      "int libXavcMp4::GetParameterSetSize(libXavcMp4::ParameterSetType, uint32_t, uint32_t, uint32_t*)"
                     );
      }
      FUN_002cd0d4(*(undefined8 *)(param_1 + 0x108),uVar3);
    }
  }
  else {
    if (param_2 == 1) {
      uVar2 = 0x22;
    }
    else if (param_2 == 0) {
      uVar2 = 0x21;
    }
    else {
      if (param_2 != 2) {
        sleep(1);
        __line = 0x6ec;
        goto LAB_00325474;
      }
      uVar2 = 0x20;
    }
    iVar1 = FUN_00325358(param_1,uVar3,param_3,uVar2);
    if (iVar1 != 0) {
      return;
    }
    FUN_002cd930(*(undefined8 *)(param_1 + 0x108),uVar3,param_3,0,param_4,param_5);
  }
  FUN_00322428();
  return;
}

