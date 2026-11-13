// sidb::SetFlushArea
// Ghidra address: 003913e4

/* sidb::SetFlushArea(unsigned int, unsigned int) */

void sidb::SetFlushArea(uint param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  int iStack_4;
  
  uVar1 = *(int *)(*(long *)(PTR_gp_db_004017c8 + (ulong)param_1 * 8) + 0x30) * param_2;
  local_8 = (uVar1 >> 0xe) + 4;
  piVar3 = &local_8;
  iStack_4 = ((*(int *)(*(long *)(PTR_gp_db_004017c8 + (ulong)param_1 * 8) + 0x30) + uVar1) - 1 >>
             0xe) + 4;
  if (local_8 == iStack_4) {
    puVar2 = PTR_g_flushArea_set_00401ae0 + (ulong)param_1 * 0x30;
  }
  else {
    puVar2 = PTR_g_flushArea_set_00401ae0 + (ulong)param_1 * 0x30;
    FUN_0038fe14(puVar2,piVar3);
    piVar3 = &iStack_4;
  }
  FUN_0038fe14(puVar2,piVar3);
  return;
}

