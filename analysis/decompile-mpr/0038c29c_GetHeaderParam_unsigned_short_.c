// sidb::GetHeaderParam<unsigned_short>
// Ghidra address: 0038c29c

/* int sidb::GetHeaderParam<unsigned short>(unsigned int, sidb::HEADER_ID, unsigned short*) */

int sidb::GetHeaderParam<unsigned_short>(uint param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
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
  if (param_3 == (ushort *)0x0 || uVar2 == 0xffffffff) goto LAB_0038c38c;
  iVar3 = 0x409;
  mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
  if (*(int *)(PTR_g_dbStatus_004029e8 + (ulong)uVar2 * 4) - 2U < 2) {
    iVar3 = 0x403;
    switch(param_2) {
    case 0:
      uVar1 = (ushort)*(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8000);
      break;
    case 1:
      uVar1 = (ushort)*(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8004);
      break;
    case 2:
      uVar1 = (ushort)*(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8008);
      break;
    case 3:
      uVar1 = (ushort)*(undefined8 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8010);
      break;
    case 4:
      uVar1 = (ushort)*(undefined8 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar2 * 8) + 0x8018);
      break;
    default:
      goto switchD_0038c36c_default;
    }
    *param_3 = uVar1;
    iVar3 = 0;
  }
switchD_0038c36c_default:
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_0038c38c:
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

