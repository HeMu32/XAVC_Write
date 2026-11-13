// FUN_001fe0e8
// Ghidra address: 001fe0e8

void FUN_001fe0e8(char *param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  if (param_1 != (char *)0x0) {
    if (param_2 == 0) {
      local_b = 0;
      local_c = 3;
      local_a = 0;
      local_10 = 0x2312;
      local_9 = 0;
      local_e = 0x51;
      local_8 = 0xc9;
      FUN_001fdddc(&local_10,0xc);
    }
    else {
      mpr::thread::normalLock::lock((normalLock *)&DAT_00495ba0);
      local_8 = *(undefined4 *)(param_1 + 4);
      if (*param_1 == '\0') {
        local_c = 3;
        local_10 = 0x2312;
        uVar2 = 0;
        pcVar1 = (code *)0x0;
        local_e = 0x52;
        local_b = 0;
        local_a = 0;
        local_9 = 0;
        FUN_001fdddc(&local_10,0xc);
      }
      else {
        local_c = 3;
        local_10 = 0x2312;
        *(int *)(param_1 + 8) = param_2;
        uVar2 = 0;
        local_e = 0x53;
        local_b = 0;
        local_a = 0;
        local_9 = 0;
        FUN_001fdddc(&local_10,0xc);
        pcVar1 = *(code **)(param_1 + 0x10);
        if (pcVar1 != (code *)0x0) {
          uVar2 = *(undefined4 *)(param_1 + 4);
          param_1[0x10] = '\0';
          param_1[0x11] = '\0';
          param_1[0x12] = '\0';
          param_1[0x13] = '\0';
          param_1[0x14] = '\0';
          param_1[0x15] = '\0';
          param_1[0x16] = '\0';
          param_1[0x17] = '\0';
        }
      }
      mpr::thread::normalLock::unlock((normalLock *)&DAT_00495ba0);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(uVar2,param_2);
      }
    }
    return;
  }
  return;
}

