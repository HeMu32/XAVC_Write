// sidb::SetFlushAreaHeader
// Ghidra address: 0038ff20

/* sidb::SetFlushAreaHeader(unsigned int) */

void sidb::SetFlushAreaHeader(uint param_1)

{
  undefined *puVar1;
  uint local_4;
  
  puVar1 = PTR_g_flushArea_set_00401ae0 + (ulong)param_1 * 0x30;
  for (local_4 = 0; local_4 < 4; local_4 = local_4 + 1) {
    FUN_0038fe14(puVar1,&local_4);
  }
  return;
}

