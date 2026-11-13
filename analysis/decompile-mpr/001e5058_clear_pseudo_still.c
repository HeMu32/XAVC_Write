// mpr::stillrecord::clear_pseudo_still
// Ghidra address: 001e5058

/* mpr::stillrecord::clear_pseudo_still(bool) */

undefined4 mpr::stillrecord::clear_pseudo_still(bool param_1)

{
  pthread_mutexattr_t *__attr;
  undefined *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  referer *prVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_658;
  undefined4 local_654;
  undefined4 uStack_650;
  undefined4 local_64c;
  undefined4 uStack_648;
  undefined1 auStack_640 [8];
  referer *local_638;
  char local_630;
  uint local_62c;
  int local_628;
  undefined2 local_620;
  undefined2 local_61e;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined1 local_61a;
  undefined1 local_619;
  
  local_61e = 0x3300;
  local_61c = 4;
  local_61b = 0;
  local_61a = 0;
  local_619 = 0;
  local_620 = 0x2120;
  FUN_001df778((recordInfo *)&local_620,8);
  if (param_1) {
    if (DAT_00486f3c != '\0') {
LAB_001e5138:
      puVar1 = PTR_gp_paramBoard_00402470;
      iVar3 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,
                                  **(uint **)PTR_gp_paramBoard_00402470);
      if (iVar3 == -1) {
        return 3;
      }
      prVar5 = operator_new(0x250);
      __attr = (pthread_mutexattr_t *)(prVar5 + 0x248);
      *(undefined4 *)prVar5 = 0;
      *(undefined4 *)(prVar5 + 4) = 0;
      *(undefined4 *)(prVar5 + 8) = 0;
      *(undefined4 *)(prVar5 + 0xc) = 0;
      *(undefined4 *)(prVar5 + 0x10) = 0;
      *(undefined4 *)(prVar5 + 0x14) = 0;
      pthread_mutexattr_init(__attr);
      pthread_mutexattr_settype(__attr,0);
      pthread_mutex_init((pthread_mutex_t *)(prVar5 + 0x218),__attr);
      local_630 = '\0';
      local_62c = 0;
      local_628 = 0;
      *(int *)PTR_s_count_004017c0 = *(int *)PTR_s_count_004017c0 + 1;
      local_654 = 0xffff;
      uStack_650 = 0xffff;
      local_64c = 0xffff;
      uStack_648 = 0xffff;
      local_658 = **(undefined4 **)puVar1;
      local_638 = prVar5;
      iVar3 = sidb::GetRootSet(1,&local_658,0,0,1,0,auStack_640);
      if (iVar3 == 0) {
        iVar3 = local_628;
        if (local_630 == '\0') {
          iVar3 = *(int *)(local_638 + 0xc);
        }
        for (iVar7 = 0; iVar7 != iVar3; iVar7 = iVar7 + 1) {
          sidb::recordInfo::clear((recordInfo *)&local_620);
          if (local_630 == '\0') {
            uVar4 = sidb::referer::at(local_638,iVar7);
          }
          else {
            uVar4 = local_62c;
            if (iVar7 != 0 || local_628 != 1) {
              uVar4 = 0xffffffff;
            }
          }
          sidb::Select(0xffffffff,uVar4,(recordInfo *)&local_620,true);
          sidb::Delete(0xffffffff,uVar4,true,false);
        }
        DAT_00486f3c = '\0';
        if (!param_1) {
          msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,
                              **(uint **)PTR_gp_paramBoard_00402470);
          FUN_0023748c();
        }
        local_61b = 0;
        local_61c = 4;
        local_61a = 0;
        local_620 = 0x2120;
        local_619 = 0;
        local_61e = 0x3400;
        FUN_001df778((recordInfo *)&local_620,8);
        uVar6 = 0;
      }
      else {
        uVar6 = 3;
      }
      prVar5 = local_638;
      if (local_638 == (referer *)0x0) {
        return uVar6;
      }
      sidb::referer::~referer(local_638);
      operator_delete(prVar5,0x250);
      return uVar6;
    }
    local_61e = 0x3301;
  }
  else {
    cVar2 = IsSetStillCacheForPseudoStill();
    if (cVar2 != '\0') goto LAB_001e5138;
    local_61e = 0x3302;
  }
  local_619 = 0;
  local_61a = 0;
  local_61b = 0;
  local_61c = 4;
  local_620 = 0x2120;
  FUN_001df778((recordInfo *)&local_620,8);
  return 0;
}

