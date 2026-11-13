// sidb::Refine_i<sidb::DirNumberChangeCheckInfo>
// Ghidra address: 00397ec4

/* int sidb::Refine_i<sidb::DirNumberChangeCheckInfo>(unsigned int, sidb::set const&, sidb::COL_ID,
   std::function<bool (sidb::DirNumberChangeCheckInfo)>, sidb::set*) */

int sidb::Refine_i<sidb::DirNumberChangeCheckInfo>
              (undefined8 param_1,set *param_2,undefined4 param_3,long param_4,set *param_5)

{
  undefined *puVar1;
  undefined *this;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  headerStructure *this_00;
  byte local_1b;
  undefined2 local_1a;
  byte local_18 [2];
  undefined2 local_16;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  osal_thread_id();
  local_1b = 0;
  local_1a = 0;
  if (param_5 == (set *)0x0) {
    iVar6 = 0x403;
  }
  else {
    this_00 = (headerStructure *)0x0;
    uVar10 = 0xffffffff;
    uVar7 = 0;
    set::clear(param_5);
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    this = PTR_g_msidconv_00402dc8;
    puVar1 = PTR_gp_db_004017c8;
    for (uVar9 = 0; uVar4 = set::size(param_2), uVar9 < uVar4; uVar9 = uVar9 + 1) {
      uVar5 = set::at(param_2,uVar9);
      uVar4 = uVar5 & 0x1ffff;
      if (((uVar7 ^ uVar5) & 0xff000000) != 0) {
        iVar6 = GetDriveLetterFromUniqueId(uVar5,(char *)&local_1b);
        bVar2 = local_1b;
        if (iVar6 == 0) {
          uVar7 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_1b);
          uVar10 = (ulong)uVar7;
          if (uVar7 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar1 + uVar10 * 8);
            uVar7 = uVar5;
            goto LAB_00398020;
          }
          uVar8 = 0x10;
          local_c = 2;
          uStack_4 = (uint)bVar2;
          local_e = 0x1b4;
        }
        else {
          uVar8 = 0xc;
          local_c = 3;
          local_e = 0x1b3;
        }
        local_9 = 0;
        local_a = 0;
        local_b = 0;
        local_10 = 0x2470;
        iVar6 = 0x403;
        local_8 = uVar5;
        FUN_003896c0(&local_10,uVar8);
        goto LAB_00397fb8;
      }
LAB_00398020:
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar10 * 4) != 3) {
        iVar6 = 0x409;
        goto LAB_00397fb8;
      }
      cVar3 = headerStructure::IsTrueBitmap(this_00,uVar4);
      if (cVar3 != '\0') {
        iVar6 = recordStructureWithFunc<unsigned_short>::GetValue
                          ((recordStructureWithFunc<unsigned_short> *)
                           (this_00 + (ulong)(uVar4 * *(int *)(this_00 + 0x30)) + 0x10000),param_3,
                           uVar4,&local_1a);
        if (iVar6 != 0) goto LAB_00397fb8;
        local_16 = local_1a;
        local_18[0] = local_1b;
        if (*(long *)(param_4 + 0x10) == 0) {
          std::__throw_bad_function_call();
        }
        cVar3 = (**(code **)(param_4 + 0x18))(param_4,local_18);
        if (cVar3 != '\0') {
          set::push_back(param_5,uVar5);
        }
      }
    }
    iVar6 = 0;
LAB_00397fb8:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  return iVar6;
}

