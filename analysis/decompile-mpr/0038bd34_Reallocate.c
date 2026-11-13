// sidb::Reallocate
// Ghidra address: 0038bd34

/* sidb::Reallocate(unsigned int) */

undefined4 sidb::Reallocate(uint param_1)

{
  undefined *this;
  ulong uVar1;
  undefined4 uVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  local_e = 0x70;
  local_10 = 0x2470;
  local_c = 3;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = param_1;
  FUN_003896c0(&local_10,0xc);
  osal_thread_id();
  uVar1 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  this = PTR_g_rwlock_004023e0;
  mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
  uVar2 = 0;
  if (*(int *)(PTR_g_dbStatus_004029e8 + (uVar1 & 0xffffffff) * 4) != 3) {
    uVar2 = 0x409;
  }
  mpr::thread::rwLock::unlock((rwLock *)this);
  local_c = 3;
  local_10 = 0x2470;
  local_e = 0x7f;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = uVar2;
  FUN_003896c0(&local_10,0xc);
  return uVar2;
}

