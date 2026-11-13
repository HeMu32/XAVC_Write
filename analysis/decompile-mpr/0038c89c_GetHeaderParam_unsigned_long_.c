// sidb::GetHeaderParam<unsigned_long>
// Ghidra address: 0038c89c

/* int sidb::GetHeaderParam<unsigned long>(unsigned int, sidb::HEADER_ID, unsigned long*) */

int sidb::GetHeaderParam<unsigned_long>(uint param_1,undefined4 param_2,ulong *param_3)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  undefined4 uStack_4;
  
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
  uVar1 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  osal_thread_id();
  if (param_3 == (ulong *)0x0 || uVar1 == 0xffffffff) goto LAB_0038c98c;
  iVar3 = 0x409;
  mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
  if (*(int *)(PTR_g_dbStatus_004029e8 + (ulong)uVar1 * 4) - 2U < 2) {
    iVar3 = 0x403;
    switch(param_2) {
    case 0:
      uVar2 = (ulong)*(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8000);
      break;
    case 1:
      uVar2 = (ulong)*(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8004);
      break;
    case 2:
      uVar2 = (ulong)*(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8008);
      break;
    case 3:
      uVar2 = *(ulong *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8010);
      break;
    case 4:
      uVar2 = *(ulong *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8018);
      break;
    default:
      goto switchD_0038c96c_default;
    }
    iVar3 = 0;
    *param_3 = uVar2;
  }
switchD_0038c96c_default:
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_0038c98c:
  local_b = 0;
  local_c = 2;
  local_a = 0;
  local_10 = 0x2470;
  local_9 = 0;
  local_e = 0x9f;
  uStack_4 = (undefined4)*param_3;
  local_8 = iVar3;
  FUN_003896c0(&local_10,0x10);
  return iVar3;
}

