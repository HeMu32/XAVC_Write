// sidb::SetHeaderParam<unsigned_long>
// Ghidra address: 00390bc4

/* int sidb::SetHeaderParam<unsigned long>(unsigned int, sidb::HEADER_ID, unsigned long) */

int sidb::SetHeaderParam<unsigned_long>(uint param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_14 = 1;
  local_18 = 0x2470;
  local_16 = 0xa0;
  uVar3 = (undefined4)param_3;
  uStack_4 = 0;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  local_10 = param_1;
  uStack_c = param_2;
  local_8 = uVar3;
  FUN_003896c0(&local_18,0x18);
  iVar4 = 0x403;
  uVar1 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  osal_thread_id();
  if (uVar1 == 0xffffffff) goto LAB_00390ce4;
  iVar4 = 0x409;
  mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
  if (*(int *)(PTR_g_dbStatus_004029e8 + (ulong)uVar1 * 4) - 2U < 2) {
    iVar4 = 0x403;
    switch(param_2) {
    case 0:
      *(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8000) = uVar3;
      break;
    case 1:
      *(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8004) = uVar3;
      break;
    case 2:
      *(undefined4 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8008) = uVar3;
      break;
    case 3:
      *(undefined8 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8010) = param_3;
      break;
    case 4:
      *(undefined8 *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8018) = param_3;
      break;
    default:
      goto switchD_00390c90_default;
    }
    iVar4 = 0;
switchD_00390c90_default:
    lVar5 = *(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8);
    uVar2 = CalcChecksum((uchar *)(lVar5 + 0x8000),0x3ffc);
    *(int *)(lVar5 + 0xbffc) = (int)uVar2 + (int)(uVar2 / 0xfffffffb) * 5;
    SetFlushAreaHeader(uVar1);
  }
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_00390ce4:
  local_14 = 3;
  local_13 = 0;
  local_18 = 0x2470;
  local_12 = 0;
  local_16 = 0xaf;
  local_11 = 0;
  local_10 = iVar4;
  FUN_003896c0(&local_18,0xc);
  return iVar4;
}

