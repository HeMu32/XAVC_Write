// sidb::Refine_i<sidb::MovieFormat>
// Ghidra address: 0038d2f8

/* int sidb::Refine_i<sidb::MovieFormat>(unsigned int, sidb::set const&, sidb::COL_ID,
   std::function<bool (sidb::MovieFormat)>, sidb::set*) */

int sidb::Refine_i<sidb::MovieFormat>
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
  fileStructure *pfVar9;
  fileStructure *extraout_x1;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  headerStructure *this_00;
  uint local_5c;
  uint local_58;
  sidb *local_54;
  byte local_41;
  undefined2 *local_40;
  uint local_38;
  undefined4 uStack_34;
  uint local_30;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_20;
  uint local_1c;
  
  local_24 = 2;
  local_28 = 0x2470;
  local_26 = 400;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = param_1;
  local_1c = param_3;
  FUN_003896c0(&local_28,0x10);
  osal_thread_id();
  local_41 = 0;
  if (param_5 == (set *)0x0) {
    iVar6 = 0x403;
  }
  else {
    uVar11 = 0;
    uVar10 = 0;
    this_00 = (headerStructure *)0x0;
    uVar12 = 0xffffffff;
    set::clear(param_5);
    iVar6 = 0;
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    this = PTR_g_msidconv_00402dc8;
    puVar1 = PTR_gp_db_004017c8;
    local_5c = 0;
    local_58 = 0;
    local_54._0_4_ = (sidb *)0x0;
LAB_0038d3c0:
    uVar4 = set::size(param_2);
    if (uVar10 < uVar4) {
      uVar5 = set::at(param_2,uVar10);
      uVar4 = uVar5 & 0x1ffff;
      if (((local_5c ^ uVar5) & 0xff000000) == 0) {
LAB_0038d4a0:
        cVar3 = headerStructure::IsTrueBitmap(this_00,uVar4);
        if (cVar3 != '\0') {
          iVar6 = 0x403;
          if (param_3 != 0x61) goto LAB_0038d508;
          pfVar9 = *(fileStructure **)(PTR_gp_db_004017c8 + uVar12 * 8);
          local_40 = &local_28;
          if ((byte)(((byte)this_00[(ulong)(uVar4 * *(int *)(this_00 + 0x30)) + 0x10007] & 0xf) - 2)
              < 2) goto LAB_0038d560;
          do {
            uVar11 = 0;
            local_58 = 0;
            local_54._0_4_ = (sidb *)0x0;
            while( true ) {
              iVar6 = 0;
LAB_0038d508:
              uVar4 = 0xff;
              if (local_58 - 2 < 7) {
                uVar4 = (uint)(byte)(&DAT_003e61d0)[local_58 - 2];
              }
              uStack_34 = sidb2defStruct_GopStructure(local_54._0_4_);
              local_30 = 0;
              if (uVar11 < 9) {
                local_30 = (uint)(byte)(&DAT_003e61d8)[uVar11];
              }
              local_38 = uVar4;
              if (*(long *)(param_4 + 0x10) != 0) {
                cVar3 = (**(code **)(param_4 + 0x18))(param_4,&local_38);
                if (cVar3 != '\0') {
                  set::push_back(param_5,uVar5);
                }
                uVar10 = uVar10 + 1;
                goto LAB_0038d3c0;
              }
              std::__throw_bad_function_call();
              pfVar9 = extraout_x1;
LAB_0038d560:
              iVar6 = recordStructureBinaryWithFunc<sidb::MovieFormatInternal>::
                      GetValue(sidb::fileStructure*,sidb::COL_ID,unsigned_int,sidb::MovieFormatInternal*)
                      ::{lambda(sidb::fileStructure*,unsigned_int)#1}::operator()
                                ((_lambda_sidb__fileStructure__unsigned_int__1_ *)&local_40,pfVar9,
                                 uVar4);
              if (iVar6 != 0) break;
              uVar11 = local_1c & 0xff;
              local_58 = local_20 >> 0x10 & 0xff;
              local_54._0_4_ = (sidb *)(local_20 >> 0x18);
            }
          } while( true );
        }
        iVar6 = 0x407;
      }
      else {
        iVar6 = GetDriveLetterFromUniqueId(uVar5,(char *)&local_41);
        bVar2 = local_41;
        if (iVar6 == 0) {
          uVar7 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_41);
          uVar12 = (ulong)uVar7;
          if (uVar7 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar1 + uVar12 * 8);
            local_5c = uVar5;
            goto LAB_0038d4a0;
          }
          uVar8 = 0x10;
          local_24 = 2;
          local_1c = (uint)bVar2;
          local_26 = 0x196;
        }
        else {
          uVar8 = 0xc;
          local_24 = 3;
          local_26 = 0x195;
        }
        local_21 = 0;
        local_22 = 0;
        local_23 = 0;
        local_28 = 0x2470;
        iVar6 = 0x403;
        local_20 = uVar5;
        FUN_003896c0(&local_28,uVar8);
      }
    }
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  local_23 = 0;
  local_24 = 2;
  local_22 = 0;
  local_28 = 0x2470;
  local_21 = 0;
  local_26 = 0x19f;
  local_20 = iVar6;
  local_1c = set::size(param_5);
  FUN_003896c0(&local_28,0x10);
  return iVar6;
}

