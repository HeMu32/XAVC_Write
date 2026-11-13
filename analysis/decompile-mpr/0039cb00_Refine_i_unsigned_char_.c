// sidb::Refine_i<unsigned_char>
// Ghidra address: 0039cb00

/* int sidb::Refine_i<unsigned char>(unsigned int, sidb::set const&, sidb::COL_ID,
   std::function<bool (unsigned char)>, sidb::set*) */

int sidb::Refine_i<unsigned_char>
              (undefined8 param_1,set *param_2,int param_3,undefined8 param_4,set *param_5)

{
  bool bVar1;
  undefined *puVar2;
  undefined *this;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  headerStructure *this_00;
  uint uVar11;
  ulong uVar12;
  undefined8 local_16;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint uStack_4;
  
  iVar7 = 0x403;
  osal_thread_id();
  local_16._1_1_ = 0;
  if (param_5 != (set *)0x0) {
    this_00 = (headerStructure *)0x0;
    uVar12 = 0xffffffff;
    uVar8 = 0;
    set::clear(param_5);
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    this = PTR_g_msidconv_00402dc8;
    puVar2 = PTR_gp_db_004017c8;
    for (uVar11 = 0; uVar5 = set::size(param_2), uVar11 < uVar5; uVar11 = uVar11 + 1) {
      uVar6 = set::at(param_2,uVar11);
      uVar5 = uVar6 & 0x1ffff;
      if (((uVar8 ^ uVar6) & 0xff000000) != 0) {
        iVar7 = GetDriveLetterFromUniqueId(uVar6,(char *)((long)&local_16 + 1));
        bVar3 = local_16._1_1_;
        if (iVar7 == 0) {
          uVar8 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)this,local_16._1_1_);
          uVar12 = (ulong)uVar8;
          if (uVar8 != 0xffffffff) {
            this_00 = *(headerStructure **)(puVar2 + uVar12 * 8);
            uVar8 = uVar6;
            goto LAB_0039cc78;
          }
          uVar10 = 0x10;
          local_c = 2;
          uStack_4 = (uint)bVar3;
          local_e = 0x146;
        }
        else {
          local_e = 0x145;
LAB_0039cbdc:
          local_c = 3;
          uVar10 = 0xc;
        }
        local_9 = 0;
        local_a = 0;
        local_b = 0;
        local_16._6_2_ = 0x2470;
        iVar7 = 0x403;
        local_8 = uVar6;
        FUN_003896c0((long)&local_16 + 6,uVar10);
        goto LAB_0039cc40;
      }
LAB_0039cc78:
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar12 * 4) != 3) {
        iVar7 = 0x409;
        goto LAB_0039cc40;
      }
      cVar4 = headerStructure::IsTrueBitmap(this_00,uVar5);
      if (cVar4 != '\0') {
        if (param_3 == 0x5b) {
          local_16._2_4_ = 0xffffffff;
          iVar7 = GetMediaIdFromUniqueId(uVar6,(uint *)((long)&local_16 + 2));
          if (iVar7 != 0) {
            local_e = 0x147;
            goto LAB_0039cbdc;
          }
          local_16._0_1_ = (sidb *)local_16._2_4_;
        }
        else {
          if (param_3 < 0x5d) {
            iVar7 = recordStructureWithFunc<unsigned_char>::GetValue
                              ((recordStructureWithFunc<unsigned_char> *)
                               (this_00 + (ulong)(uVar5 * *(int *)(this_00 + 0x30)) + 0x10000),
                               param_3,(ulong)uVar5);
          }
          else if (param_3 < 0x62) {
            iVar7 = recordStructureBinaryWithFunc<unsigned_char>::GetValue
                              ((recordStructureBinaryWithFunc<unsigned_char> *)
                               (this_00 + (ulong)(uVar5 * *(int *)(this_00 + 0x30)) + 0x10000),
                               this_00,param_3,uVar5,&local_16);
            if (param_3 == 0x5f) {
              local_16._0_1_ = (sidb *)sidb2defStruct_GopStructure((sidb *)local_16);
            }
            else if (param_3 == 0x60) {
              uVar9 = (ulong)(byte)(sidb *)local_16;
              bVar1 = (byte)(sidb *)local_16 < 9;
              local_16._0_1_ = (sidb *)0x0;
              if (bVar1) {
                    /* WARNING: Load size is inaccurate */
                local_16._0_1_ = *(sidb **)(&DAT_003e61d8 + uVar9);
              }
            }
            else if (param_3 == 0x5e) {
              uVar5 = (uint)(byte)(sidb *)local_16;
              local_16._0_1_ = (sidb *)0xff;
              if (uVar5 - 2 < 7) {
                    /* WARNING: Load size is inaccurate */
                local_16._0_1_ = *(sidb **)(&DAT_003e61d0 + (uVar5 - 2));
              }
            }
          }
          else {
            iVar7 = onMemoryColumnWithFunc<unsigned_char>::GetValue
                              ((onMemoryColumnWithFunc<unsigned_char> *)
                               (*(long *)(PTR_gp_onmem_00401cf8 + uVar12 * 8) + (ulong)uVar5 * 4),
                               param_3,&local_16);
          }
          if (iVar7 != 0) goto LAB_0039cc40;
        }
        cVar4 = FUN_00394420(param_4,(undefined1)(sidb *)local_16);
        if (cVar4 != '\0') {
          set::push_back(param_5,uVar6);
        }
      }
    }
    iVar7 = 0;
LAB_0039cc40:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  return iVar7;
}

