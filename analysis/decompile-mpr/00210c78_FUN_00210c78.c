// FUN_00210c78
// Ghidra address: 00210c78

undefined8 FUN_00210c78(long param_1,undefined8 param_2,undefined8 param_3,byte param_4)

{
  undefined2 local_15e8;
  undefined2 local_15e6;
  undefined1 local_15e4;
  undefined1 local_15e3;
  undefined1 local_15e2;
  undefined1 local_15e1;
  undefined4 local_15e0;
  undefined1 local_15dc;
  undefined1 local_15db;
  undefined1 local_15da;
  undefined1 local_15d9;
  uint local_15d8;
  undefined8 local_15d0;
  undefined8 local_15c8;
  undefined8 local_15c0;
  undefined8 local_15b8;
  undefined8 local_15b0;
  undefined8 local_15a8;
  undefined4 local_15a0;
  long local_1598;
  undefined8 local_1590;
  undefined8 local_1588;
  long local_1580;
  long local_1578;
  undefined8 local_1570;
  long local_1568;
  long lStack_1560;
  byte local_1558;
  undefined4 local_10;
  undefined *local_8;
  
  local_15dc = 3;
  local_15e0 = 0xc002311;
  local_15d8 = (uint)param_4;
  local_15db = 0;
  local_15da = 0;
  local_15d9 = 0;
  FUN_0020aff4(&local_15e0,0xc);
  FUN_00210abc(param_1,param_3,0xffffffff);
  local_15dc = 0;
  local_15d8 = 0;
  memset(&local_15d0,0,0x15c0);
  local_15e0 = *(undefined4 *)(param_1 + 0x420);
  local_15d0 = *(undefined8 *)(param_1 + 0x1da0);
  local_10 = 0;
  local_15c8 = *(undefined8 *)(param_1 + 0x1da8);
  local_15c0 = *(undefined8 *)(param_1 + 0x1db0);
  local_15b0 = *(undefined8 *)(param_1 + 0x1d58);
  local_15b8 = *(undefined8 *)(param_1 + 0x1d70);
  local_15a8 = *(undefined8 *)(param_1 + 0x1d60);
  local_15a0 = *(undefined4 *)(param_1 + 0x1d6c);
  local_1598 = param_1 + 0x1d68;
  local_1588 = *(undefined8 *)(param_1 + 0xe0);
  local_1580 = param_1 + 0x28;
  local_1578 = param_1 + 0x78;
  local_1570 = *(undefined8 *)(param_1 + 0x440);
  local_1568 = param_1 + 0x108;
  lStack_1560 = param_1 + 0x1e10;
  local_8 = PTR_FUN_004025f8;
  local_1590 = param_2;
  local_1558 = param_4;
  FUN_00194008(&local_15e0);
  local_15e8 = 0x2311;
  local_15e3 = 0;
  local_15e4 = 4;
  local_15e2 = 0;
  local_15e6 = 0xc01;
  local_15e1 = 0;
  FUN_0020aff4(&local_15e8,8);
  return 0;
}

