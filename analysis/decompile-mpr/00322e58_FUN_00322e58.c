// FUN_00322e58
// Ghidra address: 00322e58

void FUN_00322e58(long param_1,int param_2,undefined8 param_3,undefined4 param_4,undefined8 param_5)

{
  uint __line;
  undefined2 local_18 [2];
  int local_14;
  undefined8 local_10;
  undefined4 local_8;
  
  local_10 = param_5;
  local_8 = param_4;
  if (*(int *)(param_1 + 0x24) == 0x61766331) {
    if (param_2 == 0) {
      FUN_002d7268(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8),
                   *(undefined4 *)(param_1 + 0xbc),&local_10);
    }
    else {
      if (param_2 != 1) {
        sleep(1);
        __line = 0x20f;
        goto LAB_00322ed8;
      }
      FUN_002d7370(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8),
                   *(undefined4 *)(param_1 + 0xbc));
    }
  }
  else {
    if (*(int *)(param_1 + 0x24) != 0x68766331) {
      sleep(1);
      __line = 0x232;
LAB_00322ed8:
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","libXavcMp4.cpp",__line,
                    "uint32_t libXavcMp4::AddParameterSet(libXavcMp4::ParameterSetType, uint32_t, uint32_t, void*)"
                   );
    }
    local_14 = 0;
    local_18[0] = 1;
    if (param_2 == 1) {
      local_18[0] = 0x2201;
      local_14 = *(int *)(param_1 + 0x100);
    }
    else if (param_2 == 0) {
      local_18[0] = 0x2101;
      local_14 = *(int *)(param_1 + 0xfc);
    }
    else {
      if (param_2 != 2) {
        sleep(1);
        __line = 0x21f;
        goto LAB_00322ed8;
      }
      local_18[0] = 0x2001;
      local_14 = *(int *)(param_1 + 0xf8);
    }
    if (local_14 == -1) {
      FUN_002d7710(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8),
                   *(undefined4 *)(param_1 + 0xbc),local_18,&local_14);
      if (param_2 == 1) {
        *(int *)(param_1 + 0x100) = local_14;
      }
      else if (param_2 == 0) {
        *(int *)(param_1 + 0xfc) = local_14;
      }
      else {
        if (param_2 != 2) {
          sleep(1);
          __line = 0x22a;
          goto LAB_00322ed8;
        }
        *(int *)(param_1 + 0xf8) = local_14;
      }
    }
    FUN_002d77ec(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8),
                 *(undefined4 *)(param_1 + 0xbc),local_14,&local_10);
  }
  FUN_00322428();
  return;
}

