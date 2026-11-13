// sidb::PartialUpdate_i<unsigned_char>
// Ghidra address: 0039d3a0

/* int sidb::PartialUpdate_i<unsigned char>(unsigned int, unsigned int, sidb::COL_ID, unsigned char,
   bool, bool) */

int sidb::PartialUpdate_i<unsigned_char>
              (undefined4 param_1,uint param_2,int param_3,byte param_4,char param_5,uint param_6)

{
  normalLock *this;
  long lVar1;
  recordStructureWithFunc<unsigned_char> *prVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined8 uVar11;
  ulong uVar12;
  headerStructure *this_00;
  signed local_25;
  uint local_24;
  ulong local_20;
  undefined2 local_18;
  undefined2 local_16;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  uint uStack_4;
  
  if (param_5 != '\0') {
    local_16 = 0x100;
    local_14 = 1;
    local_18 = 0x2470;
    local_10 = param_1;
    local_c = param_2;
    local_8 = param_3;
    uStack_4 = (uint)param_4;
    FUN_003896c0(&local_18,0x18);
    local_14 = 3;
    local_16 = 0x101;
    local_18 = 0x2470;
    local_10 = param_6 & 0xff;
    FUN_003896c0(&local_18,0xc);
  }
  local_24 = 0xffffffff;
  iVar7 = GetMediaIdFromUniqueId(param_2,&local_24);
  if (iVar7 == 0) {
    uVar8 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,local_24);
    if (uVar8 != 0xffffffff) {
      uVar12 = (ulong)uVar8;
      this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar12 * 8);
      this = (normalLock *)(PTR_g_cancellock_00401410 + uVar12 * 0x40);
      iVar7 = *(int *)(this_00 + 0x30);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar12 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar12 * 4) + 1;
      mpr::thread::normalLock::unlock(this);
      mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar12 * 4) == 3) {
        if (PTR_gb_protected_00401e10[uVar12] == '\0') {
          uVar3 = param_2 & 0x1ffff;
          cVar6 = headerStructure::IsTrueBitmap(this_00,uVar3);
          if (cVar6 == '\0') {
switchD_0039d5e8_default:
            iVar10 = 0x403;
          }
          else {
            iVar5 = 0;
            iVar10 = iVar5;
            if (param_3 < 0x62) {
              prVar2 = (recordStructureWithFunc<unsigned_char> *)
                       (this_00 + (ulong)(uVar3 * iVar7) + 0x10000);
              uVar9 = IsModificationTimeUpdated(param_3);
              if ((param_3 == 0x19) ||
                 (iVar10 = recordStructureWithFunc<unsigned_char>::SetValue(prVar2,param_3,param_4),
                 iVar10 == 0)) {
                uVar9 = param_6 & 0xff & uVar9 & 0xff;
                if (uVar9 != 0 || param_3 == 0x19) {
                  local_25 = (signed)0x0;
                  local_20 = 0;
                  mpr::time::GetLTM((LocalTime *)&local_18);
                  ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18,&local_20,&local_25);
                  prVar2[0x18] = (recordStructureWithFunc<unsigned_char>)
                                 ((byte)prVar2[0x18] & 1 | (char)local_25 << 1);
                  *(uint *)(prVar2 + 0x18) =
                       *(uint *)(prVar2 + 0x18) & 0xff000000 |
                       *(uint *)(prVar2 + 0x18) & 0xfff | ((uint)(local_20 >> 0x20) & 0xfff) << 0xc;
                  *(int *)(prVar2 + 0x1c) = (int)local_20;
                  uVar11 = ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18);
                  *(undefined8 *)(this_00 + 0x8018) = uVar11;
                  uVar12 = CalcChecksum((uchar *)(this_00 + 0x8000),0x3ffc);
                  *(int *)(this_00 + 0xbffc) = (int)uVar12 + (int)(uVar12 / 0xfffffffb) * 5;
                }
                uVar4 = *(uint *)(this_00 + 0x34);
                uVar12 = CalcChecksum((uchar *)prVar2,uVar4);
                *(short *)(this_00 +
                          (ulong)uVar4 + (ulong)(uVar3 * *(int *)(this_00 + 0x30)) + 0x10000) =
                     (short)uVar12 + (short)(uVar12 / 0xfff1) * 0xf;
                SetFlushArea(uVar8,uVar3);
                SetFlushAreaHeader(uVar8);
                iVar10 = iVar5;
                if (uVar9 != 0) {
                  evtRecordChangedParam::evtRecordChangedParam((evtRecordChangedParam *)&local_18);
                  local_14 = local_24;
                  local_10 = 3;
                  local_c = ContentTypeInternal2ContentType((byte)prVar2[7] & 0xf);
                  local_8 = GetChangedParamTypeFromColId(param_3);
                  uStack_4 = param_2;
                  IssueCallbackRecordChanged((evtRecordChangedParam *)&local_18);
                }
              }
            }
            else {
              lVar1 = *(long *)(PTR_gp_onmem_00401cf8 + uVar12 * 8) + (ulong)uVar3 * 4;
              switch(param_3) {
              case 100:
                *(byte *)(*(long *)(PTR_gp_onmem_00401cf8 + uVar12 * 8) + (ulong)uVar3 * 4) =
                     param_4;
                break;
              case 0x65:
                *(byte *)(lVar1 + 1) = param_4;
                break;
              case 0x66:
                *(byte *)(lVar1 + 2) = param_4;
                break;
              case 0x67:
                *(byte *)(lVar1 + 3) = param_4;
                break;
              default:
                goto switchD_0039d5e8_default;
              }
            }
          }
        }
        else {
          iVar10 = 0x408;
        }
      }
      else {
        iVar10 = 0x409;
      }
      mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar8 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar8 * 4) + -1;
      mpr::thread::normalLock::unlock(this);
      goto LAB_0039d498;
    }
  }
  else {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x107;
    local_10 = param_2;
    FUN_003896c0(&local_18,0xc);
  }
  iVar10 = 0x403;
LAB_0039d498:
  if (param_5 != '\0') {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x10f;
    local_10 = iVar10;
    FUN_003896c0(&local_18,0xc);
  }
  return iVar10;
}

