// sidb::ComplexRefine
// Ghidra address: 00394118

/* sidb::ComplexRefine(unsigned int, sidb::set const&, std::function<bool (unsigned int)>,
   sidb::set*) */

undefined4 sidb::ComplexRefine(uint param_1,set *param_2,undefined8 param_3,set *param_4)

{
  undefined *puVar1;
  undefined *this;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  uint uVar9;
  ulong uVar10;
  headerStructure *this_00;
  byte local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint local_4;
  
  local_c = 3;
  local_10 = 0x2470;
  local_e = 0x160;
  uVar8 = 0x403;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = param_1;
  FUN_003896c0(&local_10,0xc);
  osal_thread_id();
  local_11 = 0;
  if (param_4 != (set *)0x0) {
    this_00 = (headerStructure *)0x0;
    uVar10 = 0xffffffff;
    set::clear(param_4);
    uVar6 = 0;
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    this = PTR_g_msidconv_00402dc8;
    puVar1 = PTR_gp_db_004017c8;
    for (uVar9 = 0; uVar4 = set::size(param_2), uVar9 < uVar4; uVar9 = uVar9 + 1) {
      uVar4 = set::at(param_2,uVar9);
      if (((uVar6 ^ uVar4) & 0xff000000) != 0) {
        iVar5 = GetDriveLetterFromUniqueId(uVar4,(char *)&local_11);
        bVar2 = local_11;
        if (iVar5 == 0) {
          uVar6 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_11);
          uVar10 = (ulong)uVar6;
          if (uVar6 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar1 + uVar10 * 8);
            uVar6 = uVar4;
            goto LAB_003942fc;
          }
          uVar7 = 0x10;
          local_c = 2;
          local_4 = (uint)bVar2;
          local_e = 0x166;
        }
        else {
          uVar7 = 0xc;
          local_c = 3;
          local_e = 0x165;
        }
        local_9 = 0;
        local_a = 0;
        local_b = 0;
        local_10 = 0x2470;
        uVar8 = 0x403;
        local_8 = uVar4;
        FUN_003896c0(&local_10,uVar7);
        goto LAB_00394240;
      }
LAB_003942fc:
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar10 * 4) != 3) {
        uVar8 = 0x409;
        goto LAB_00394240;
      }
      cVar3 = headerStructure::IsTrueBitmap(this_00,uVar4 & 0x1ffff);
      if ((cVar3 != '\0') && (cVar3 = FUN_003940ec(param_3,uVar4), cVar3 != '\0')) {
        set::push_back(param_4,uVar4);
      }
    }
    uVar8 = 0;
LAB_00394240:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  local_b = 0;
  local_c = 2;
  local_a = 0;
  local_10 = 0x2470;
  local_9 = 0;
  local_e = 0x16f;
  local_8 = uVar8;
  local_4 = set::size(param_4);
  FUN_003896c0(&local_10,0x10);
  return uVar8;
}

