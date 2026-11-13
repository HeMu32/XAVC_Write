// sidb::Refine_i<DefStruct::LocalTime>
// Ghidra address: 0038f7a0

/* int sidb::Refine_i<DefStruct::LocalTime>(unsigned int, sidb::set const&, sidb::COL_ID,
   std::function<bool (DefStruct::LocalTime)>, sidb::set*) */

int sidb::Refine_i<DefStruct::LocalTime>
              (uint param_1,set *param_2,uint param_3,long param_4,set *param_5)

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
  headerStructure *this_00;
  uint uVar9;
  ulong uVar10;
  uint local_644;
  byte local_631;
  undefined2 local_630;
  undefined2 local_62e;
  undefined1 local_62c;
  undefined1 local_62b;
  undefined1 local_62a;
  undefined1 local_629;
  undefined1 local_628;
  undefined2 local_626;
  undefined2 local_620;
  undefined2 local_61e;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined1 local_61a;
  undefined1 local_619;
  uint local_618;
  undefined4 local_614;
  undefined1 local_610;
  undefined1 local_60f;
  undefined1 local_60e;
  undefined1 local_60d;
  undefined1 local_60c;
  undefined2 local_60a;
  
  local_61c = 2;
  local_620 = 0x2470;
  local_61e = 0x150;
  local_61b = 0;
  local_61a = 0;
  local_619 = 0;
  local_618 = param_1;
  local_614 = param_3;
  FUN_003896c0((recordInfo *)&local_620,0x10);
  osal_thread_id();
  local_631 = 0;
  if (param_5 == (set *)0x0) {
    iVar6 = 0x403;
  }
  else {
    this_00 = (headerStructure *)0x0;
    uVar10 = 0xffffffff;
    set::clear(param_5);
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    this = PTR_g_msidconv_00402dc8;
    puVar1 = PTR_gp_db_004017c8;
    local_644 = 0;
    for (uVar9 = 0; uVar4 = set::size(param_2), uVar9 < uVar4; uVar9 = uVar9 + 1) {
      uVar5 = set::at(param_2,uVar9);
      uVar4 = uVar5 & 0x1ffff;
      if (((local_644 ^ uVar5) & 0xff000000) != 0) {
        iVar6 = GetDriveLetterFromUniqueId(uVar5,(char *)&local_631);
        bVar2 = local_631;
        if (iVar6 == 0) {
          uVar7 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_631);
          uVar10 = (ulong)uVar7;
          if (uVar7 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar1 + uVar10 * 8);
            local_644 = uVar5;
            goto LAB_0038f938;
          }
          uVar8 = 0x10;
          local_61c = 2;
          local_614 = (uint)bVar2;
          local_61e = 0x156;
        }
        else {
          uVar8 = 0xc;
          local_61c = 3;
          local_61e = 0x155;
        }
        local_619 = 0;
        local_61a = 0;
        local_61b = 0;
        local_620 = 0x2470;
        local_618 = uVar5;
        FUN_003896c0((recordInfo *)&local_620,uVar8);
LAB_0038f8cc:
        iVar6 = 0x403;
        goto LAB_0038f8d0;
      }
LAB_0038f938:
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar10 * 4) != 3) {
        iVar6 = 0x409;
        goto LAB_0038f8d0;
      }
      cVar3 = headerStructure::IsTrueBitmap(this_00,uVar4);
      if (cVar3 == '\0') {
        iVar6 = 0x407;
        goto LAB_0038f8d0;
      }
      recordInfo::clear((recordInfo *)&local_620);
      ConvRecordStructure2RecordInfo
                ((fileStructure *)this_00,local_631,uVar4,
                 (recordStructure *)(this_00 + (ulong)(uVar4 * *(int *)(this_00 + 0x30)) + 0x10000),
                 (recordInfo *)&local_620);
      if (param_3 != 3) goto LAB_0038f8cc;
      local_626 = local_60a;
      local_630 = (undefined2)local_614;
      local_62e = local_614._2_2_;
      local_62c = local_610;
      local_62b = local_60f;
      local_62a = local_60e;
      local_629 = local_60d;
      local_628 = local_60c;
      if (*(long *)(param_4 + 0x10) == 0) {
        std::__throw_bad_function_call();
      }
      cVar3 = (**(code **)(param_4 + 0x18))(param_4,&local_630);
      if (cVar3 != '\0') {
        set::push_back(param_5,uVar5);
      }
    }
    iVar6 = 0;
LAB_0038f8d0:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  local_61b = 0;
  local_61c = 2;
  local_61a = 0;
  local_620 = 0x2470;
  local_619 = 0;
  local_61e = 0x15f;
  local_618 = iVar6;
  local_614 = set::size(param_5);
  FUN_003896c0((recordInfo *)&local_620,0x10);
  return iVar6;
}

