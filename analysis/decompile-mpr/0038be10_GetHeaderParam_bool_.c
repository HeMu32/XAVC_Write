// sidb::GetHeaderParam<bool>
// Ghidra address: 0038be10

/* int sidb::GetHeaderParam<bool>(unsigned int, sidb::HEADER_ID, bool*) */

int sidb::GetHeaderParam<bool>(uint param_1,undefined4 param_2,byte *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  local_c = 2;
  local_10 = 0x2470;
  local_e = 0x90;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = param_1;
  uStack_4 = param_2;
  FUN_003896c0(&local_10,0x10);
  iVar3 = 0x403;
  uVar2 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  osal_thread_id();
  if (param_3 == (byte *)0x0 || uVar2 == 0xffffffff) goto LAB_0038bf08;
  iVar3 = 0x409;
  mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
  if (1 < *(int *)(PTR_g_dbStatus_004029e8 + (ulong)uVar2 * 4) - 2U) goto switchD_0038bee0_default;
  iVar3 = 0x403;
  switch(param_2) {
  case 0:
    iVar3 = *(int *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8000);
    break;
  case 1:
    iVar3 = *(int *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8004);
    break;
  case 2:
    iVar3 = *(int *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8008);
    break;
  case 3:
    lVar4 = *(long *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8010);
    goto LAB_0038bf84;
  case 4:
    lVar4 = *(long *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8018);
LAB_0038bf84:
    bVar1 = lVar4 == 0;
    goto LAB_0038bef4;
  default:
    goto switchD_0038bee0_default;
  }
  bVar1 = iVar3 == 0;
LAB_0038bef4:
  iVar3 = 0;
  *param_3 = !bVar1;
switchD_0038bee0_default:
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_0038bf08:
  local_b = 0;
  local_c = 2;
  local_a = 0;
  local_10 = 0x2470;
  local_9 = 0;
  local_e = 0x9f;
  uStack_4 = (uint)*param_3;
  local_8 = iVar3;
  FUN_003896c0(&local_10,0x10);
  return iVar3;
}

