// FUN_00323828
// Ghidra address: 00323828

void FUN_00323828(long param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  ulong local_18;
  int local_10 [4];
  
  local_10[0] = 0;
  local_10[1] = 0;
  local_10[2] = 0;
  local_10[3] = 0;
  local_18 = (ulong)param_3;
  if (param_3 == 0x58415643) {
    local_18 = 0x10b1fff58415643;
    if (*(int *)(param_1 + 0x24) == 0x68766331) {
      local_10[2] = 0x6e726173;
      local_10[3] = 0;
    }
    FUN_002d2fcc(param_2,&local_18);
    iVar1 = FUN_00322428();
    if (iVar1 == 0) {
      local_10[0] = 0x58415643;
      local_10[1] = 0x6d703432;
    }
  }
  else {
    iVar1 = 3;
  }
  lVar2 = 0;
  while( true ) {
    if (iVar1 != 0) {
      return;
    }
    if (*(int *)((long)local_10 + lVar2) == 0) break;
    lVar2 = lVar2 + 4;
    FUN_002d3058(*(undefined8 *)(param_1 + 0xb0));
    iVar1 = FUN_00322428();
    if (lVar2 == 0x10) {
      return;
    }
  }
  return;
}

