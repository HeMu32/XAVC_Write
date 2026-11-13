// FUN_002178a4
// Ghidra address: 002178a4

void FUN_002178a4(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_18 [8];
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  int iStack_4;
  
  local_c = 3;
  local_b = 0;
  local_e = 0x310;
  local_8 = param_1[4];
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2310;
  FUN_0021777c(&local_10,0xc);
  uVar1 = mpr::VpgManager::AddOpenFlags(*param_1,param_1[0x12],6);
  iVar2 = FUN_0032af44(*(undefined8 *)(param_1 + 6),param_1 + 0x13,uVar1,auStack_18);
  if (iVar2 != 0) {
    local_b = 0;
    local_c = 2;
    local_a = 0;
    local_e = 0x318;
    local_8 = param_1[4];
    local_9 = 0;
    local_10 = 0x2310;
    iStack_4 = iVar2;
    FUN_0021777c(&local_10,0x10);
    FUN_001fe0e8(*(undefined8 *)(param_1 + 0x56),iVar2);
  }
  local_b = 0;
  local_c = 3;
  local_a = 0;
  local_10 = 0x2310;
  local_9 = 0;
  local_e = 800;
  local_8 = param_1[4];
  FUN_0021777c(&local_10,0xc);
  return;
}

