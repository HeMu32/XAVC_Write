// mpr::CopyDstCancel
// Ghidra address: 001ab7f8

/* mpr::CopyDstCancel(void*) */

void mpr::CopyDstCancel(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint local_658 [6];
  set asStack_640 [32];
  int local_620 [3];
  LocalTime aLStack_614 [64];
  undefined4 local_5d4;
  
  uVar9 = 0xffffffff;
  pthread_mutex_lock((pthread_mutex_t *)PTR_s_mutexCopyDst_00402a20);
  if (*(uint *)((long)param_1 + 0x10) < 4) {
    uVar9 = *(undefined4 *)
             (PTR_g_msidconv_00401cd8 + (ulong)*(uint *)((long)param_1 + 0x10) * 0x80 + 0x7c);
  }
  uVar7 = 0xffffffff;
  if (*(uint *)param_1 < 4) {
    uVar7 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)*(uint *)param_1 * 0x80 + 0x7c);
  }
  uVar1 = *(undefined4 *)((long)param_1 + 0x15d0);
  local_658[1] = 0xffff;
  local_658[2] = 0xffff;
  local_658[3] = 0xffff;
  local_658[4] = 0xffff;
  local_658[0] = uVar7;
  sidb::set::set(asStack_640);
  sidb::recordInfo::clear((recordInfo *)local_620);
  iVar2 = sidb::GetRootSet(1,local_658,5,0,1,0,asStack_640);
  if (iVar2 == 0) {
    uVar5 = 0;
    uVar8 = 0;
    while (uVar3 = sidb::set::size(asStack_640), uVar5 < uVar3) {
      uVar3 = uVar5 + 1;
      uVar4 = sidb::set::at(asStack_640,uVar5);
      uVar5 = uVar3;
      if (uVar8 < uVar4) {
        uVar8 = uVar4;
      }
    }
    iVar2 = sidb::Select(0xffffffff,uVar8,(recordInfo *)local_620,true);
    if ((iVar2 == 0) && (local_620[0] == 4)) {
      sidb::SetHeaderParam<unsigned_int>(uVar7,0,local_5d4);
    }
  }
  sidb::set::clear(asStack_640);
  sidb::recordInfo::clear((recordInfo *)local_620);
  iVar2 = sidb::GetRootSet(1,local_658,1,0,1,0,asStack_640);
  if ((iVar2 == 0) && (iVar2 = sidb::set::size(asStack_640), iVar2 != 0)) {
    uVar5 = sidb::set::at(asStack_640,iVar2 - 1);
    sidb::Select(0xffffffff,uVar5,(recordInfo *)local_620,true);
    uVar6 = sidb::ConvDefStructLocalTime2SiDBUInt64(aLStack_614);
    sidb::SetHeaderParam<unsigned_long>(uVar7,3,uVar6);
  }
  sidb::Flush(uVar7);
  FUN_0023ae28(uVar7);
  SetRecStatus(4,uVar7);
  SendEvtEditFinished(4,uVar9,uVar1,1);
  pthread_mutex_unlock((pthread_mutex_t *)PTR_s_mutexCopyDst_00402a20);
  sidb::set::~set(asStack_640);
  return;
}

