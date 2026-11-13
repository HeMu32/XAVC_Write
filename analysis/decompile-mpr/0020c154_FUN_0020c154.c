// FUN_0020c154
// Ghidra address: 0020c154

undefined8 FUN_0020c154(long param_1,undefined8 param_2,undefined1 *param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined4 local_15e0;
  undefined1 local_15dc;
  undefined4 local_15d8;
  undefined8 local_15d0;
  long local_15c8;
  long local_15c0;
  long local_15b8;
  long local_15b0;
  long lStack_15a8;
  undefined8 local_15a0;
  undefined8 local_1598;
  undefined8 local_1590;
  undefined4 local_1588;
  long local_1580;
  undefined8 local_1578;
  undefined8 local_1570;
  undefined8 local_1568;
  undefined8 local_1560;
  undefined8 local_1558;
  undefined1 *local_1550;
  long local_1548;
  long local_1540;
  undefined8 local_1538;
  undefined4 local_10;
  undefined *local_8;
  
  uVar1 = *(uint *)(param_1 + 0x1d10);
  *param_3 = 0;
  lVar3 = (ulong)uVar1 * 0x138;
  memset((void *)(param_1 + lVar3 + 0x4b0),0,0xa0);
  lVar2 = param_1 + (ulong)uVar1 * 0x138;
  *(undefined4 *)(lVar2 + 0x550) = 0;
  *(undefined4 *)(lVar2 + 0x554) = 0;
  *(undefined4 *)(lVar2 + 0x558) = 0;
  memset(*(void **)(lVar2 + 0x560),0,0x3c00);
  for (lVar2 = param_1 + lVar3 + 0x568; lVar2 != param_1 + lVar3 + 0x5c8; lVar2 = lVar2 + 0x18) {
    FUN_0020b11c(lVar2);
  }
  lVar2 = param_1 + (ulong)uVar1 * 0x138;
  *(undefined4 *)(lVar2 + 0x5c8) = 1;
  *(undefined4 *)(lVar2 + 0x5cc) = 0;
  *(undefined4 *)(lVar2 + 0x5d0) = 0;
  memset(*(void **)(lVar2 + 0x5d8),0,0x1680);
  *(undefined4 *)(lVar2 + 0x5e0) = 0;
  local_15dc = 0;
  local_15d8 = 0;
  memset(&local_15d0,0,0x15c0);
  local_15e0 = *(undefined4 *)(param_1 + 0x420);
  local_15d0 = *(undefined8 *)(param_1 + 0xe0);
  local_10 = 0;
  lVar2 = (ulong)*(uint *)(param_1 + 0x1d10) * 0x138;
  local_15c8 = param_1 + lVar2 + 0x4b0;
  local_15c0 = param_1 + lVar2 + 0x550;
  local_15b8 = param_1 + lVar2 + 0x568;
  local_15b0 = param_1 + lVar2 + 0x5c8;
  lStack_15a8 = param_1 + lVar2 + 0x5e0;
  local_15a0 = *(undefined8 *)(param_1 + 0x1d70);
  local_1598 = *(undefined8 *)(param_1 + 0x1d58);
  local_1590 = *(undefined8 *)(param_1 + 0x1d60);
  local_1588 = *(undefined4 *)(param_1 + 0x1d6c);
  local_1580 = param_1 + 0x1d68;
  local_1570 = *(undefined8 *)(param_1 + 0x1d98);
  local_1568 = *(undefined8 *)(param_1 + 0x1da0);
  local_1560 = *(undefined8 *)(param_1 + 0x1da8);
  local_1558 = *(undefined8 *)(param_1 + 0x1db0);
  local_1548 = param_1 + 0x28;
  local_1540 = param_1 + 0x78;
  local_1538 = *(undefined8 *)(param_1 + 0x440);
  local_8 = PTR_FUN_00401ba8;
  local_1578 = param_2;
  local_1550 = param_3;
  FUN_00194008(&local_15e0);
  return 0;
}

