// mpr::RepairM4Inconsistencies
// Ghidra address 001b9340; ELF VMA = Ghidra - 0x100000

/* mpr::RepairM4Inconsistencies(unsigned int, bool*, unsigned int&, unsigned int&) */

undefined4 mpr::RepairM4Inconsistencies(uint param_1,bool *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  evtRepairProgressParam aeStack_680 [4];
  undefined4 local_67c;
  int iStack_678;
  undefined4 local_670;
  undefined4 uStack_66c;
  undefined4 local_668;
  undefined4 uStack_664;
  undefined4 local_660;
  char local_658 [16];
  undefined4 local_648;
  undefined4 local_644;
  set asStack_640 [32];
  recordInfo arStack_620 [26];
  undefined2 local_606;
  uint local_5d4;
  char local_560;
  char local_459;
  char local_352;
  char acStack_351 [262];
  char local_24b;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_c;
  undefined1 local_7;
  char local_6;
  
  uVar5 = 0xffffffff;
  if (param_1 < 4) {
    uVar5 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  sidb::set::set(asStack_640);
  uStack_66c = 0xffff;
  local_668 = 0xffff;
  uStack_664 = 0xffff;
  local_660 = 0xffff;
  local_670 = uVar5;
  iVar1 = sidb::GetRootSet(1,&local_670,5,0,1,0,asStack_640);
  if (iVar1 == 0) {
    for (uVar4 = 0; uVar2 = sidb::set::size(asStack_640), uVar3 = 0, uVar4 < uVar2;
        uVar4 = uVar4 + 1) {
      sidb::recordInfo::clear(arStack_620);
      if ((param_2 != (bool *)0x0) && (*param_2 != false)) {
        uVar3 = 1;
        break;
      }
      uVar2 = sidb::set::at(asStack_640,uVar4);
      iVar1 = sidb::Select(0xffffffff,uVar2,arStack_620,false);
      if (iVar1 != 0) goto LAB_001b95a8;
      if (local_6 != '\0') {
        iVar1 = GetRecordInfo(param_1,arStack_620);
        if ((iVar1 == 0) &&
           ((*param_4 = local_5d4, local_352 == '\0' ||
            (iVar1 = stillplay::getRecordInfo(param_1,acStack_351,arStack_620,true), iVar1 == 0))))
        {
          local_6 = '\0';
          local_7 = 1;
          if (local_c == 1) {
            iVar1 = FUN_0023b078(uVar5,local_606,local_658);
            if (iVar1 != 0) goto LAB_001b9554;
            if (local_658[0] != '\0') {
              if (local_560 != '\0') {
                local_a8 = local_648;
              }
              if (local_24b != '\0') {
                local_a4 = local_644;
              }
              if (local_352 != '\0') {
                local_a0 = 0;
              }
              if (local_459 != '\0') {
                local_9c = 0;
              }
            }
          }
          iVar1 = sidb::Update(0xffffffff,arStack_620,false,true);
        }
        else {
LAB_001b9554:
          uVar2 = sidb::set::at(asStack_640,uVar4);
          iVar1 = sidb::Delete(0xffffffff,uVar2,false,false);
        }
        if (iVar1 != 0) goto LAB_001b95a8;
        uVar2 = *param_3;
        *param_3 = uVar2 + 1;
        if ((uVar2 + 1) % 100 == 0) {
          evtRepairProgressParam::evtRepairProgressParam(aeStack_680);
          iStack_678 = (int)((double)*param_3 * DAT_003d39f8);
          local_67c = uVar5;
          SetIssueEvent(0x1027,aeStack_680,0xc);
        }
      }
    }
  }
  else {
LAB_001b95a8:
    uVar3 = 2;
  }
  sidb::set::~set(asStack_640);
  return uVar3;
}

