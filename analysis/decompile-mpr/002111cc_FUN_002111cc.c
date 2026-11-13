// FUN_002111cc
// Ghidra address: 002111cc

int FUN_002111cc(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  RingBuffer *pRVar5;
  uint uVar6;
  ulong uVar7;
  undefined2 local_15f0;
  undefined2 local_15ee;
  undefined1 local_15ec;
  undefined1 local_15eb;
  undefined1 local_15ea;
  undefined1 local_15e9;
  int local_15e8;
  undefined4 local_15e0;
  undefined1 local_15dc;
  undefined4 local_15d8;
  undefined8 local_15d0;
  long local_15c8;
  undefined8 local_15c0;
  long local_15b0;
  long local_15a8;
  long local_15a0;
  undefined8 local_1598;
  long local_1590;
  undefined4 local_10;
  undefined *local_8;
  
  FUN_00211034(param_1,*(undefined4 *)(param_1 + 0x420),param_3,0,0);
  FUN_00210abc(param_1,param_3,0);
  FUN_00210abc(param_1,param_3 + 0x10,0);
  local_15dc = 0;
  local_15d8 = 0;
  memset(&local_15d0,0,0x15c0);
  local_15e0 = *(undefined4 *)(param_1 + 0x420);
  local_15c0 = *(undefined8 *)(param_1 + 0xe0);
  local_15c8 = param_1 + 0x108;
  local_15a8 = param_1 + 0x28;
  local_15a0 = param_1 + 0x78;
  local_1590 = param_1 + 0x1e10;
  local_10 = 0;
  local_8 = PTR_FUN_00401b00;
  local_15d0 = param_2;
  local_15b0 = local_15c8;
  local_1598 = param_4;
  FUN_00194008(&local_15e0);
  uVar7 = *(ulong *)(param_1 + 0x450);
  lVar1 = 0;
  if ((uVar7 & 0xfff) != 0) {
    lVar1 = 0x1000;
  }
  lVar1 = lVar1 + (uVar7 & 0xfffffffffffff000);
  uVar6 = *(uint *)(param_1 + 0x458) & 0xfffff000;
  *(long *)(param_1 + 0x1db8) = lVar1;
  if (uVar7 + *(uint *)(param_1 + 0x458) < (ulong)uVar6 + lVar1) {
    uVar6 = uVar6 - 0x1000;
  }
  *(uint *)(param_1 + 0x1dc0) = uVar6;
  uVar2 = *(undefined8 *)(param_1 + 0x1db8);
  uVar3 = *(undefined8 *)(param_1 + 0x1dc0);
  pRVar5 = operator_new(0x48);
  mpr::RingBuffer::RingBuffer(pRVar5,uVar2,uVar3);
  *(RingBuffer **)(param_1 + 0x1d98) = pRVar5;
  iVar4 = *(int *)(param_1 + 0x1dc0);
  *(uint *)(param_1 + 0x1dc8) = iVar4 - (uint)(iVar4 << 1) / 0xb & 0xfff00000;
  iVar4 = FUN_002063cc(*(undefined8 *)(param_1 + 0x100),1,*(undefined8 *)(param_1 + 0x1db8),iVar4,1,
                       1,*(undefined8 *)(param_1 + 0x468),*(undefined4 *)(param_1 + 0x470),1);
  if (iVar4 != 0) {
    local_15eb = 0;
    local_15ec = 3;
    local_15ea = 0;
    local_15f0 = 0x2311;
    local_15e9 = 0;
    local_15ee = 0x901;
    local_15e8 = iVar4;
    FUN_0020aff4(&local_15f0,0xc);
    FUN_001fe0e8(*(undefined8 *)(param_1 + 0x440),iVar4);
  }
  *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)(param_1 + 0x480);
  *(undefined1 *)(param_1 + 0x4a9) = *(undefined1 *)(param_1 + 0x43e);
  return iVar4;
}

