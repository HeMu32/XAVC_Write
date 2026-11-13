// mpr::ClipStatusMovie
// Ghidra address: 001b39a0

/* mpr::ClipStatusMovie(unsigned int, unsigned int, sidb::ClipStatus, sidb::recordInfo&, bool,
   sidb::ClipStatus) */

int mpr::ClipStatusMovie
              (uint param_1,undefined4 param_2,uint param_3,recordInfo *param_4,byte param_5,
              undefined4 param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  NrtMetaWrapper *pNVar5;
  bool *pbVar6;
  ulong local_c0;
  bool *local_b8;
  bool *local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  char *local_88;
  long local_80;
  char *local_68;
  long local_60;
  char *local_48 [4];
  ulong local_28;
  string asStack_20 [32];
  
  uVar2 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,param_1);
  FUN_001aa364((string *)&local_88,&DAT_003d7eaf);
  FUN_001aa364((string *)&local_68,&DAT_003d7eaf);
  FUN_001aa364((string *)local_48,&DAT_003d7eaf);
  local_b8 = (bool *)0x0;
  local_b0 = (bool *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (param_3 < 4) {
    iVar3 = LockEditTargetFiles(param_4,(vector *)&uStack_a0);
    if ((iVar3 == 0) && (cVar1 = IsMediaRemain(uVar2), cVar1 != '\0')) {
      pNVar5 = operator_new(0x30);
      FUN_00352de0();
      if (param_4[0xc0] != '\0') {
        std::__cxx11::string::operator=((string *)&local_88,param_4 + 0xc1);
      }
      if (param_4[0x1c7] != '\0') {
        std::__cxx11::string::operator=((string *)&local_68,param_4 + 0x1c8);
      }
      if (param_4[0x3d5] != '\0') {
        std::__cxx11::string::operator=((string *)local_48,param_4 + 0x3d6);
      }
      if ((local_60 == 0) || (local_80 == 0)) {
        iVar3 = 2;
      }
      else {
        local_28 = local_28 & 0xffffffffffffff00;
        std::__cxx11::string::string(asStack_20,(string *)&local_88);
        FUN_001b0fa4(&local_b8,&local_28);
        std::__cxx11::string::_M_dispose();
        local_28 = local_28 & 0xffffffffffffff00;
        std::__cxx11::string::string(asStack_20,(string *)&local_68);
        FUN_001b0fa4(&local_b8,&local_28);
        std::__cxx11::string::_M_dispose();
        pbVar6 = local_b8;
        if (param_4[0x3d5] != '\0') {
          local_28 = local_28 & 0xffffffffffffff00;
          std::__cxx11::string::string(asStack_20,(string *)local_48);
          FUN_001b0fa4(&local_b8,&local_28);
          std::__cxx11::string::_M_dispose();
          pbVar6 = local_b8;
        }
        do {
          if (local_b0 == pbVar6) {
            iVar3 = ParseNrtFile(local_68,pNVar5);
            if (iVar3 == 0) {
              if (param_3 == 0) {
                iVar3 = FUN_00354388(pNVar5);
              }
              else {
                ConvClipStatusTypeSidb2NrtDef(param_3,&local_28);
                iVar3 = FUN_003539f0(pNVar5,local_28 & 0xffffffff);
              }
              if (iVar3 != 0) goto LAB_001b3a4c;
              iVar3 = UpdateNrtFile(local_88,(bool)param_4[0x3d5],local_48[0],local_68,pNVar5);
              if ((iVar3 == 0) &&
                 (iVar3 = UpdateMediaProfileClipStatusInEdit(uVar2,param_4,param_3), iVar3 == 0)) {
                local_c0 = 0;
                local_28 = 0;
                iVar3 = GetFileSize(param_4 + 0xc1,&local_c0);
                if ((iVar3 != 0) ||
                   ((param_4[0x3d5] != '\0' &&
                    (iVar3 = GetFileSize(param_4 + 0x3d6,&local_28), iVar3 != 0)))) {
                  iVar3 = 0xb;
                  pbVar6 = local_b8;
                  goto LAB_001b3c10;
                }
                if ((param_5 != 0) ||
                   (iVar3 = sidb::PartialUpdate<unsigned_int>(0xffffffff,param_2,0x1b,param_3,1,0),
                   iVar3 == 0)) {
                  iVar3 = sidb::PartialUpdate<unsigned_long>(0xffffffff,param_2,0x57,local_c0,1,0);
                  if ((iVar3 == 0) &&
                     (((param_4[0x3d5] == '\0' ||
                       (iVar3 = sidb::PartialUpdate<unsigned_long>
                                          (0xffffffff,param_2,0x58,local_28,1,0), iVar3 == 0)) &&
                      (iVar3 = sidb::PartialUpdate<int>(0xffffffff,param_2,0x19,0,1,0), iVar3 == 0))
                     )) {
                    iVar3 = sidb::NotifyChangeEvent(param_1,param_2,3,0x10,1);
                    param_5 = param_5 | iVar3 == 0;
                  }
                  iVar3 = 0;
                  pbVar6 = local_b8;
                  if (param_5 != 0) goto LAB_001b3c10;
                }
                iVar3 = 2;
                pbVar6 = local_b8;
                goto LAB_001b3c10;
              }
            }
            break;
          }
          iVar3 = UnsetReadOnlyAttribute(*(char **)(pbVar6 + 8),pbVar6);
          pbVar6 = pbVar6 + 0x28;
        } while (iVar3 == 0);
      }
    }
    else {
      pNVar5 = (NrtMetaWrapper *)0x0;
LAB_001b3a4c:
      iVar3 = 0xb;
    }
  }
  else {
    pNVar5 = (NrtMetaWrapper *)0x0;
    iVar3 = 3;
  }
  pbVar6 = local_b8;
  if (param_5 != 0) {
    sidb::PartialUpdate<unsigned_int>(param_1,param_2,0x1b,param_6,1,0);
    pbVar6 = local_b8;
  }
LAB_001b3c10:
  for (; pbVar6 != local_b0; pbVar6 = pbVar6 + 0x28) {
    if ((*pbVar6 != false) &&
       (iVar4 = SetReadOnlyAttribute(*(char **)(pbVar6 + 8)), iVar3 == 0 && iVar4 != 0)) {
      iVar3 = iVar4;
    }
  }
  if (pNVar5 != (NrtMetaWrapper *)0x0) {
    (**(code **)(*(long *)pNVar5 + 8))(pNVar5);
  }
  UnlockEditTargetFiles((vector *)&uStack_a0);
  FUN_001adca0((vector *)&uStack_a0);
  FUN_001aca2c(&local_b8);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  return iVar3;
}

