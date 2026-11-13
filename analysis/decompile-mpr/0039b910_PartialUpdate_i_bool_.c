// sidb::PartialUpdate_i<bool>
// Ghidra address: 0039b910

/* int sidb::PartialUpdate_i<bool>(unsigned int, unsigned int, sidb::COL_ID, bool, bool, bool) */

int sidb::PartialUpdate_i<bool>
              (undefined4 param_1,uint param_2,int param_3,byte param_4,char param_5,uint param_6)

{
  normalLock *this;
  recordStructureWithFunc<bool> *prVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  undefined8 uVar11;
  byte bVar12;
  ulong uVar13;
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
  
  uVar9 = (uint)param_4;
  if (param_5 != '\0') {
    local_16 = 0x100;
    local_14 = 1;
    local_18 = 0x2470;
    local_10 = param_1;
    local_c = param_2;
    local_8 = param_3;
    uStack_4 = uVar9;
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
      uVar13 = (ulong)uVar8;
      this_00 = *(headerStructure **)(PTR_gp_db_004017c8 + uVar13 * 8);
      this = (normalLock *)(PTR_g_cancellock_00401410 + uVar13 * 0x40);
      iVar7 = *(int *)(this_00 + 0x30);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar13 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + uVar13 * 4) + 1;
      mpr::thread::normalLock::unlock(this);
      mpr::thread::rwLock::wrlock((rwLock *)PTR_g_rwlock_004023e0);
      if (*(int *)(PTR_g_dbStatus_004029e8 + uVar13 * 4) == 3) {
        if (PTR_gb_protected_00401e10[uVar13] == '\0') {
          uVar2 = param_2 & 0x1ffff;
          cVar6 = headerStructure::IsTrueBitmap(this_00,uVar2);
          if (cVar6 == '\0') {
switchD_0039bb54_caseD_6a:
            iVar7 = 0x403;
          }
          else {
            iVar5 = 0;
            if (param_3 < 0x62) {
              prVar1 = (recordStructureWithFunc<bool> *)(this_00 + (ulong)(uVar2 * iVar7) + 0x10000)
              ;
              uVar9 = IsModificationTimeUpdated(param_3);
              if ((param_3 == 0x19) ||
                 (iVar7 = recordStructureWithFunc<bool>::SetValue(prVar1,param_3,param_4),
                 iVar7 == 0)) {
                uVar9 = param_6 & 0xff & uVar9 & 0xff;
                if (uVar9 != 0 || param_3 == 0x19) {
                  local_25 = (signed)0x0;
                  local_20 = 0;
                  mpr::time::GetLTM((LocalTime *)&local_18);
                  ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18,&local_20,&local_25);
                  prVar1[0x18] = (recordStructureWithFunc<bool>)
                                 ((byte)prVar1[0x18] & 1 | (char)local_25 << 1);
                  *(uint *)(prVar1 + 0x18) =
                       *(uint *)(prVar1 + 0x18) & 0xff000000 |
                       *(uint *)(prVar1 + 0x18) & 0xfff | ((uint)(local_20 >> 0x20) & 0xfff) << 0xc;
                  *(int *)(prVar1 + 0x1c) = (int)local_20;
                  uVar11 = ConvDefStructLocalTime2SiDBUInt64((LocalTime *)&local_18);
                  *(undefined8 *)(this_00 + 0x8018) = uVar11;
                  uVar13 = CalcChecksum((uchar *)(this_00 + 0x8000),0x3ffc);
                  *(int *)(this_00 + 0xbffc) = (int)uVar13 + (int)(uVar13 / 0xfffffffb) * 5;
                }
                uVar3 = *(uint *)(this_00 + 0x34);
                uVar13 = CalcChecksum((uchar *)prVar1,uVar3);
                *(short *)(this_00 +
                          (ulong)uVar3 + (ulong)(uVar2 * *(int *)(this_00 + 0x30)) + 0x10000) =
                     (short)uVar13 + (short)(uVar13 / 0xfff1) * 0xf;
                SetFlushArea(uVar8,uVar2);
                SetFlushAreaHeader(uVar8);
                iVar7 = iVar5;
                if (uVar9 != 0) {
                  evtRecordChangedParam::evtRecordChangedParam((evtRecordChangedParam *)&local_18);
                  local_14 = local_24;
                  local_10 = 3;
                  local_c = ContentTypeInternal2ContentType((byte)prVar1[7] & 0xf);
                  local_8 = GetChangedParamTypeFromColId(param_3);
                  uStack_4 = param_2;
                  IssueCallbackRecordChanged((evtRecordChangedParam *)&local_18);
                }
              }
            }
            else {
              lVar4 = (ulong)uVar2 * 4;
              lVar10 = *(long *)(PTR_gp_onmem_00401cf8 + uVar13 * 8);
              switch(param_3) {
              case 0x68:
                bVar12 = *(byte *)(lVar10 + lVar4) & 0xfc |
                         *(byte *)(lVar10 + lVar4) & 1 | (byte)((uVar9 & 1) << 1);
                break;
              case 0x69:
                bVar12 = *(byte *)(lVar10 + lVar4) & 0xf0 |
                         *(byte *)(lVar10 + lVar4) & 7 | (byte)((uVar9 & 1) << 3);
                break;
              default:
                goto switchD_0039bb54_caseD_6a;
              case 0x6b:
                bVar12 = *(byte *)(lVar10 + lVar4) & 0xf8 |
                         *(byte *)(lVar10 + lVar4) & 3 | (byte)((uVar9 & 1) << 2);
                break;
              case 0x6c:
                bVar12 = *(byte *)(lVar10 + lVar4) & 0xe0 |
                         *(byte *)(lVar10 + lVar4) & 0xf | (byte)((uVar9 & 1) << 4);
              }
              *(byte *)(lVar10 + lVar4) = bVar12;
              iVar7 = iVar5;
            }
          }
        }
        else {
          iVar7 = 0x408;
        }
      }
      else {
        iVar7 = 0x409;
      }
      mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
      mpr::thread::normalLock::lock(this);
      *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar8 * 4) =
           *(int *)(PTR_g_GetRootSetCancelRequestCount_00401788 + (ulong)uVar8 * 4) + -1;
      mpr::thread::normalLock::unlock(this);
      goto LAB_0039ba08;
    }
  }
  else {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x107;
    local_10 = param_2;
    FUN_003896c0(&local_18,0xc);
  }
  iVar7 = 0x403;
LAB_0039ba08:
  if (param_5 != '\0') {
    local_14 = 3;
    local_18 = 0x2470;
    local_16 = 0x10f;
    local_10 = iVar7;
    FUN_003896c0(&local_18,0xc);
  }
  return iVar7;
}

