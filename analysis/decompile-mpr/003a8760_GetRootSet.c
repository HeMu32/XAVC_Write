// sidb::GetRootSet
// Ghidra address: 003a8760

/* sidb::GetRootSet(unsigned int, unsigned int*, sidb::ROOT_SET_TYPE, bool, bool, bool, sidb::set*)
    */

undefined4
sidb::GetRootSet(int param_1,undefined4 *param_2,uint param_3,uint param_4,uint param_5,uint param_6
                ,set *param_7)

{
  pthread_mutexattr_t *__attr;
  uint uVar1;
  undefined *puVar2;
  undefined *this;
  char cVar3;
  uint uVar4;
  uint uVar5;
  referer *prVar6;
  ulong uVar7;
  undefined8 *puVar8;
  uint *puVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  ulong uVar12;
  set *this_00;
  long lVar13;
  ulong uVar14;
  headerStructure *this_01;
  undefined4 local_80 [2];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  uint *local_50;
  uint *puStack_48;
  undefined8 local_40;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  int local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 uStack_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined8 local_18;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  local_1e = 0x130;
  local_10 = param_2[1];
  local_20 = 0x2470;
  local_1c = 1;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_18 = (referer *)CONCAT44(*param_2,param_1);
  local_c = param_3;
  FUN_003896c0((set *)&local_20,0x18);
  local_20 = 0x2470;
  local_1e = 0x131;
  local_1c = 1;
  local_1b = 0;
  local_18 = (referer *)(CONCAT44(param_5,param_4) & 0xff000000ff);
  local_1a = 0;
  local_19 = 0;
  local_10 = param_6 & 0xff;
  local_c = (uint)param_7;
  FUN_003896c0((set *)&local_20,0x18);
  osal_thread_id();
  prVar6 = operator_new(0x250);
  __attr = (pthread_mutexattr_t *)(prVar6 + 0x248);
  *(undefined4 *)prVar6 = 0;
  *(undefined4 *)(prVar6 + 4) = 0;
  *(undefined4 *)(prVar6 + 8) = 0;
  *(undefined4 *)(prVar6 + 0xc) = 0;
  *(undefined4 *)(prVar6 + 0x10) = 0;
  *(undefined4 *)(prVar6 + 0x14) = 0;
  pthread_mutexattr_init(__attr);
  pthread_mutexattr_settype(__attr,0);
  pthread_mutex_init((pthread_mutex_t *)(prVar6 + 0x218),__attr);
  local_10 = local_10 & 0xffffff00;
  local_c = 0;
  local_8 = 0;
  *(int *)PTR_s_count_004017c0 = *(int *)PTR_s_count_004017c0 + 1;
  local_18 = prVar6;
  if ((param_1 - 1U < 4) && (param_7 != (set *)0x0)) {
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    local_50 = (uint *)0x0;
    puStack_48 = (uint *)0x0;
    local_40 = 0;
    local_70 = DAT_003e61a0;
    local_68 = DAT_003e61a8;
    local_58 = DAT_003e61a8;
    local_60 = DAT_003e61a0;
    local_80[0] = 1;
    local_78 = 2;
    local_74 = 3;
    if (param_3 < 8) {
      switch(param_3) {
      case 0:
      case 7:
        puVar8 = &local_70;
        uVar4 = 3;
        break;
      default:
        uVar4 = 3;
        puVar8 = &local_60;
        break;
      case 5:
        uVar4 = 2;
        puVar8 = (undefined8 *)&local_78;
        break;
      case 6:
        uVar4 = 1;
        puVar8 = (undefined8 *)local_80;
      }
      EqualToMulti<sidb::ContentTypeInternal>::SetCondition
                ((EqualToMulti<sidb::ContentTypeInternal> *)&local_50,(ContentTypeInternal *)puVar8,
                 uVar4);
      this = PTR_g_msidconv_00402dc8;
      lVar13 = 0;
      this_00 = (set *)0x0;
      do {
        uVar4 = mpr::msidconv::GetSlotID((msidconv *)this,param_2[lVar13]);
        uVar12 = (ulong)uVar4;
        local_33 = 0;
        local_34 = 1;
        local_32 = 0;
        local_38 = 0x2470;
        local_31 = 0;
        local_36 = 0x132;
        local_2c = param_2[lVar13];
        uStack_24 = 0;
        local_30 = (int)lVar13;
        local_28 = uVar4;
        FUN_003896c0(&local_38,0x18);
        if (uVar4 == 0xffffffff) goto switchD_003a8c00_default;
        if (*(int *)(PTR_g_dbStatus_004029e8 + uVar12 * 4) != 3) {
          uVar11 = 0x409;
          goto LAB_003a8ad8;
        }
        this_01 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar12 * 8);
        if (lVar13 == 0) {
          set::clear(param_7);
          this_00 = param_7;
        }
        else if (param_3 == 7) {
          set::clear((set *)&local_20);
          this_00 = (set *)&local_20;
        }
        puVar2 = PTR_g_GetRootSetCancelRequestCount_00401788;
        uVar14 = 0;
        while (uVar5 = (uint)uVar14, uVar5 < *(uint *)(this_01 + 0x44)) {
          if (((param_6 & 0xff) != 0) && (*(int *)(puVar2 + (ulong)uVar4 * 4) != 0)) {
            uVar11 = 0x40b;
            set::clear(param_7);
            goto LAB_003a8ad8;
          }
          cVar3 = headerStructure::IsTrueBitmap(this_01,uVar5);
          if ((((cVar3 == '\0') ||
               (uVar7 = (ulong)(uVar5 * *(int *)(this_01 + 0x30)),
               ((byte)this_01[uVar7 + 0x10000] & 0xf) != 0)) ||
              (((param_4 & 0xff) != 0 && (((byte)this_01[uVar7 + 0x10006] >> 4 & 1) == 0)))) ||
             (((param_5 & 0xff) == 0 &&
              ((*(byte *)(*(long *)(PTR_gp_onmem_00401cf8 + (ulong)uVar4 * 8) + uVar14 * 4) >> 1 & 1
               ) != 0)))) goto LAB_003a8c10;
          puVar9 = local_50;
          do {
            if (puStack_48 == puVar9) goto LAB_003a8c10;
            uVar1 = *puVar9;
            puVar9 = puVar9 + 1;
          } while (((byte)this_01[uVar7 + 0x10007] & 0xf) != uVar1);
          if ((3 < uVar4) || (PTR_g_msidconv_00402dc8[uVar12 * 0x80] == 0)) {
            set::clear(param_7);
            goto switchD_003a8c00_default;
          }
          switch(param_3) {
          case 0:
            set::push_back(this_00,uVar5 | (uint)(byte)PTR_g_msidconv_00402dc8[uVar12 * 0x80] <<
                                           0x18 |
                                   (uint)(*(ushort *)(this_01 + uVar7 + 0x10004) >> 1) << 0x11);
            break;
          case 1:
          case 5:
            InsertUniqueIdBasedOnValue<sidb::ForDateViewValue>(this_00,uVar4,0x5c);
            break;
          case 2:
            uVar10 = 4;
            goto LAB_003a8c1c;
          case 3:
            InsertUniqueIdBasedOnValue<unsigned_long>(this_00,uVar4,0x19);
            break;
          case 4:
            uVar10 = 0x1a;
LAB_003a8c1c:
            InsertUniqueIdBasedOnValue<sidb::UtcTimeValue>(this_00,uVar4,uVar10);
            break;
          case 6:
          case 7:
            InsertUniqueIdBasedOnValue<unsigned_int>(this_00,uVar4,7);
            break;
          default:
            goto switchD_003a8c00_default;
          }
LAB_003a8c10:
          uVar14 = (ulong)(uVar5 + 1);
        }
        if ((int)lVar13 != 0 && param_3 == 7) {
          for (uVar4 = 0; uVar5 = set::size((set *)&local_20), uVar4 < uVar5; uVar4 = uVar4 + 1) {
            uVar5 = set::at((set *)&local_20,uVar4);
            set::push_back(param_7,uVar5);
          }
        }
        lVar13 = lVar13 + 1;
      } while (lVar13 != (ulong)(param_1 - 1U) + 1);
      if (local_50 != (uint *)0x0) {
        operator_delete(local_50);
      }
      uVar11 = 0;
    }
    else {
switchD_003a8c00_default:
      uVar11 = 0x403;
LAB_003a8ad8:
      if (local_50 != (uint *)0x0) {
        operator_delete(local_50);
      }
    }
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
  else {
    local_34 = 1;
    uVar11 = 0x403;
    local_38 = 0x2470;
    local_33 = 0;
    local_36 = 0x13a;
    local_32 = 0;
    local_31 = 0;
    local_2c = SUB84(param_2,0);
    uStack_24 = 0;
    local_30 = param_1;
    local_28 = (uint)param_7;
    FUN_003896c0(&local_38,0x18);
  }
  local_33 = 0;
  local_32 = 0;
  local_34 = 2;
  local_31 = 0;
  local_38 = 0x2470;
  local_36 = 0x13f;
  local_30 = uVar11;
  local_2c = set::size(param_7);
  FUN_003896c0(&local_38,0x10);
  prVar6 = local_18;
  if (local_18 != (referer *)0x0) {
    referer::~referer(local_18);
    operator_delete(prVar6,0x250);
  }
  return uVar11;
}

