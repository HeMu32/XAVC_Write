// sidb::Update
// Ghidra address: 00393bb8

/* sidb::Update(unsigned int, sidb::recordInfo const&, bool, bool) */

int sidb::Update(uint param_1,recordInfo *param_2,bool param_3,bool param_4)

{
  normalLock *this;
  recordStructure *prVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  recordStructure rVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined8 uVar12;
  long lVar13;
  headerStructure *this_00;
  ulong uVar14;
  uint local_64c;
  undefined2 local_648;
  undefined2 local_646;
  undefined1 local_644;
  undefined1 local_643;
  undefined1 local_642;
  undefined1 local_641;
  uint local_640;
  evtRecordChangedParam aeStack_638 [4];
  uint local_634;
  undefined4 local_630;
  int local_62c;
  uint local_628;
  uint local_624;
  int local_620;
  uint local_61c;
  uint local_618;
  undefined4 local_614;
  uint local_610;
  undefined4 local_60c;
  byte local_5fc;
  char local_5fb;
  LocalTime aLStack_3c [32];
  uint local_1c;
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte local_10;
  byte local_f;
  undefined4 local_c;
  undefined4 local_4;
  
  if (param_3) {
    local_614 = *(undefined4 *)(param_2 + 4);
    local_620 = 0xf02470;
    local_61c = 1;
    local_60c = 0;
    local_618 = param_1;
    local_610 = (uint)param_4;
    FUN_003896c0(&local_620,0x18);
  }
  osal_thread_id();
  local_64c = 0xffffffff;
  memcpy(&local_620,param_2,0x620);
  evtRecordChangedParam::evtRecordChangedParam(aeStack_638);
  uVar2 = local_61c;
  iVar8 = GetMediaIdFromUniqueId(local_61c,&local_64c);
  if (iVar8 != 0) {
    local_643 = 0;
    iVar8 = 0x403;
    local_644 = 3;
    local_642 = 0;
    local_648 = 0x2470;
    local_641 = 0;
    local_646 = 0xf6;
    local_640 = local_61c;
    FUN_003896c0(&local_648,0xc);
    goto LAB_00393cb8;
  }
  iVar8 = 0x403;
  uVar9 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,local_64c);
  if (uVar9 == 0xffffffff) goto LAB_00393cb8;
  uVar2 = uVar2 & 0x1ffff;
  if (uVar2 == 0) goto LAB_00393cb8;
  uVar14 = (ulong)uVar9;
  iVar8 = 0x409;
  this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar14 * 8);
  this = (normalLock *)(PTR_g_cancellock_00401410 + uVar14 * 0x40);
  iVar3 = *(int *)(this_00 + 0x30);
  mpr::thread::normalLock::lock(this);
  *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar14 * 4) =
       *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar14 * 4) + 1;
  mpr::thread::normalLock::unlock(this);
  mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
  if ((*(int *)(PTR_g_dbStatus_004029e8 + uVar14 * 4) == 3) &&
     (iVar8 = 0x408, PTR_gb_protected_00401e10[uVar14] == '\0')) {
    iVar8 = 0x403;
    cVar7 = headerStructure::IsTrueBitmap(this_00,uVar2);
    if (cVar7 != '\0') {
      prVar1 = (recordStructure *)(this_00 + (ulong)(uVar2 * iVar3) + 0x10000);
      bVar6 = *(byte *)(*(long *)(PTR_gp_onmem_00401cf8 + uVar14 * 8) + (ulong)uVar2 * 4);
      mpr::time::GetLTM(aLStack_3c);
      if ((bVar6 & 1) == 0) {
        rVar5 = prVar1[7];
        uVar11 = ContentType2ContentTypeInternal(local_620,local_c);
        if (((byte)rVar5 & 0xf) != uVar11) {
          DecrementContentNum(uVar9,(byte)rVar5 & 0xf);
          uVar10 = ContentType2ContentTypeInternal(local_620,local_c);
          IncrementContentNum(uVar9,uVar10);
        }
        uVar4 = (uint)local_5fc ^ (byte)prVar1[4] & 1;
        uVar11 = uVar4 | 2;
        if ((int)local_5fb == (int)((long)((ulong)(byte)prVar1[7] << 0x38) >> 0x3c)) {
          uVar11 = uVar4;
        }
        if (local_620 == 4) {
          rVar5 = prVar1[0x6e];
          if ((((((local_18 != ((byte)rVar5 & 1)) || (local_17 != ((byte)rVar5 >> 1 & 1))) ||
                (local_16 != ((byte)rVar5 >> 2 & 1))) ||
               ((local_15 != ((byte)rVar5 >> 3 & 1) || (local_14 != ((byte)rVar5 >> 4 & 1))))) ||
              ((local_13 != ((byte)rVar5 >> 5 & 1) ||
               ((local_12 != ((byte)rVar5 >> 6 & 1) || (local_11 != (byte)rVar5 >> 7)))))) ||
             ((local_10 != ((byte)prVar1[0x6f] & 1) || (local_f != ((byte)prVar1[0x6f] >> 1 & 1)))))
          {
            uVar11 = uVar11 | 8;
          }
          if (local_1c != (byte)prVar1[0x5c] >> 6) {
            uVar11 = uVar11 | 0x10;
            goto LAB_00393e30;
          }
        }
        if (uVar11 == 0) {
          uVar11 = 0x20;
        }
      }
      else {
        uVar11 = 0;
        uVar10 = ContentType2ContentTypeInternal(local_620,local_c);
        IncrementContentNum(uVar9,uVar10);
      }
LAB_00393e30:
      iVar8 = ConvRecordInfo2RecordStructure(uVar9,(recordInfo *)&local_620,aLStack_3c,prVar1);
      if (iVar8 == 0) {
        lVar13 = *(long *)(PTR_gp_onmem_00401cf8 + (ulong)uVar9 * 8);
        *(undefined4 *)(lVar13 + (ulong)uVar2 * 4) = local_4;
        *(byte *)(lVar13 + (ulong)uVar2 * 4) = (byte)local_4 & 0xfe;
        uVar12 = ConvDefStructLocalTime2SiDBUInt64(aLStack_3c);
        *(undefined8 *)(this_00 + 0x8018) = uVar12;
        uVar14 = CalcChecksum((uchar *)(this_00 + 0x8000),0x3ffc);
        *(int *)(this_00 + 0xbffc) = (int)uVar14 + (int)(uVar14 / 0xfffffffb) * 5;
        uVar4 = *(uint *)(this_00 + 0x34);
        uVar14 = CalcChecksum((uchar *)prVar1,uVar4);
        *(short *)(this_00 + (ulong)uVar4 + (ulong)(uVar2 * *(int *)(this_00 + 0x30)) + 0x10000) =
             (short)uVar14 + (short)(uVar14 / 0xfff1) * 0xf;
        uVar14 = CalcChecksum((uchar *)(this_00 + 0x7c40),0x3bc);
        *(int *)(this_00 + 0x7ffc) = (int)uVar14 + (int)(uVar14 / 0xfffffffb) * 5;
        SetFlushArea(uVar9,uVar2);
        SetFlushAreaHeader(uVar9);
        if ((param_4 != 0) && ((bVar6 & 1) != 0 || uVar11 != 0)) {
          local_634 = local_64c;
          local_630 = 3;
          if ((bVar6 & 1) != 0) {
            local_630 = 1;
          }
          local_62c = local_620;
          local_624 = local_61c;
          local_628 = uVar11;
          IssueCallbackRecordChanged(aeStack_638);
        }
      }
    }
  }
  mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  mpr::thread::normalLock::lock(this);
  *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar9 * 4) =
       *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar9 * 4) + -1;
  mpr::thread::normalLock::unlock(this);
LAB_00393cb8:
  if (param_3) {
    local_643 = 0;
    local_644 = 3;
    local_642 = 0;
    local_648 = 0x2470;
    local_641 = 0;
    local_646 = 0xff;
    local_640 = iVar8;
    FUN_003896c0(&local_648,0xc);
  }
  return iVar8;
}

