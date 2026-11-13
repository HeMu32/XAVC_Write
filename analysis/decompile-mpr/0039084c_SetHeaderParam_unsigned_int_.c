// sidb::SetHeaderParam<unsigned_int>
// Ghidra address: 0039084c

/* int sidb::SetHeaderParam<unsigned int>(unsigned int, sidb::HEADER_ID, unsigned int) */

int sidb::SetHeaderParam<unsigned_int>(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  undefined4 uStack_c;
  uint local_8;
  undefined4 uStack_4;
  
  local_14 = 1;
  local_18 = 0x2470;
  local_16 = 0xa0;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  uStack_4 = 0;
  local_10 = param_1;
  uStack_c = param_2;
  local_8 = param_3;
  FUN_003896c0(&local_18,0x18);
  iVar4 = 0x403;
  uVar1 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  osal_thread_id();
  if (uVar1 == 0xffffffff) goto LAB_0039096c;
  iVar4 = 0x409;
  mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
  if (*(int *)(PTR_g_dbStatus_004029e8 + (ulong)uVar1 * 4) - 2U < 2) {
    iVar4 = 0x403;
    switch(param_2) {
    case 0:
      *(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8000) = param_3;
      break;
    case 1:
      *(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8004) = param_3;
      break;
    case 2:
      *(uint *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8008) = param_3;
      break;
    case 3:
      *(ulong *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8010) = (ulong)param_3;
      break;
    case 4:
      *(ulong *)(*(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8) + 0x8018) = (ulong)param_3;
      break;
    default:
      goto switchD_00390918_default;
    }
    iVar4 = 0;
switchD_00390918_default:
    lVar3 = *(long *)(PTR_gp_db_004017c8 + (ulong)uVar1 * 8);
    uVar2 = CalcChecksum((uchar *)(lVar3 + 0x8000),0x3ffc);
    *(int *)(lVar3 + 0xbffc) = (int)uVar2 + (int)(uVar2 / 0xfffffffb) * 5;
    SetFlushAreaHeader(uVar1);
  }
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
LAB_0039096c:
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

