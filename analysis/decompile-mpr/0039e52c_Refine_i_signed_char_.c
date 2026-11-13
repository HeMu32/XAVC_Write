// sidb::Refine_i<signed_char>
// Ghidra address: 0039e52c

/* int sidb::Refine_i<signed char>(unsigned int, sidb::set const&, sidb::COL_ID, std::function<bool
   (signed char)>, sidb::set*) */

int sidb::Refine_i<signed_char>
              (undefined8 param_1,set *param_2,int param_3,undefined8 param_4,set *param_5)

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
  undefined1 local_16;
  byte local_15;
  uint local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  iVar6 = 0x403;
  osal_thread_id();
  local_15 = 0;
  if (param_5 != (set *)0x0) {
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
        iVar6 = GetDriveLetterFromUniqueId(uVar5,(char *)&local_15);
        bVar2 = local_15;
        if (iVar6 == 0) {
          uVar7 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_15);
          uVar10 = (ulong)uVar7;
          if (uVar7 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar1 + uVar10 * 8);
            uVar7 = uVar5;
            goto LAB_0039e67c;
          }
          uVar8 = 0x10;
          local_c = 2;
          uStack_4 = (uint)bVar2;
          local_e = 0x146;
        }
        else {
          local_e = 0x145;
LAB_0039e608:
          local_c = 3;
          uVar8 = 0xc;
        }
        local_9 = 0;
        local_a = 0;
        local_b = 0;
        local_10 = 0x2470;
        local_8 = uVar5;
        FUN_003896c0(&local_10,uVar8);
LAB_0039e668:
        iVar6 = 0x403;
        goto LAB_0039e744;
      }
LAB_0039e67c:
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar10 * 4) != 3) {
        iVar6 = 0x409;
        goto LAB_0039e744;
      }
      cVar3 = headerStructure::IsTrueBitmap(this_00,uVar4);
      if (cVar3 != '\0') {
        if (param_3 == 0x5b) {
          local_14 = 0xffffffff;
          iVar6 = GetMediaIdFromUniqueId(uVar5,&local_14);
          if (iVar6 != 0) {
            local_e = 0x147;
            goto LAB_0039e608;
          }
          local_16 = (undefined1)local_14;
        }
        else {
          if (param_3 < 0x5d) {
            iVar6 = recordStructureWithFunc<signed_char>::GetValue
                              ((recordStructureWithFunc<signed_char> *)
                               (this_00 + (ulong)(uVar4 * *(int *)(this_00 + 0x30)) + 0x10000),
                               param_3,uVar4,&local_16);
          }
          else {
            if (0x61 < param_3) goto LAB_0039e668;
            iVar6 = recordStructureBinaryWithFunc<signed_char>::GetValue
                              ((recordStructureBinaryWithFunc<signed_char> *)
                               (this_00 + (ulong)(uVar4 * *(int *)(this_00 + 0x30)) + 0x10000),
                               this_00,param_3,uVar4,&local_16);
          }
          if (iVar6 != 0) goto LAB_0039e744;
        }
        cVar3 = FUN_0039444c(param_4,local_16);
        if (cVar3 != '\0') {
          set::push_back(param_5,uVar5);
        }
      }
    }
    iVar6 = 0;
LAB_0039e744:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  return iVar6;
}

