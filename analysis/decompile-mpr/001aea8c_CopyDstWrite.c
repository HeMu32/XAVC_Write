// mpr::CopyDstWrite
// Ghidra address: 001aea8c

/* mpr::CopyDstWrite(void*) */

int mpr::CopyDstWrite(void *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  byte bVar8;
  undefined *puVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  byte bVar16;
  void *pvVar17;
  undefined8 *puVar18;
  undefined8 local_c80;
  uint local_c78 [6];
  set asStack_c60 [32];
  int local_c40 [3];
  undefined8 local_c34;
  undefined4 local_c2c;
  undefined1 local_c1b;
  undefined1 local_c1a;
  undefined1 auStack_c18 [52];
  undefined1 local_be4;
  undefined1 auStack_be0 [52];
  undefined1 local_bac;
  undefined8 local_ba8;
  undefined8 uStack_ba0;
  undefined1 local_b98;
  undefined8 local_b94;
  undefined8 uStack_b8c;
  char local_b80;
  undefined1 auStack_b7f [1079];
  undefined8 local_748;
  undefined4 uStack_740;
  undefined4 local_73c;
  undefined4 uStack_738;
  undefined4 uStack_734;
  undefined4 uStack_730;
  undefined4 local_72c;
  undefined4 uStack_728;
  undefined8 uStack_724;
  undefined8 local_71c;
  undefined8 uStack_714;
  undefined8 local_70c;
  undefined8 uStack_704;
  undefined8 local_6fc;
  undefined8 uStack_6f4;
  undefined4 local_6ec;
  undefined4 uStack_6e8;
  undefined4 uStack_6e4;
  undefined4 uStack_6e0;
  undefined4 local_6dc;
  undefined4 uStack_6d8;
  undefined8 uStack_6d4;
  undefined8 local_6cc [15];
  undefined1 local_650;
  undefined8 local_64d;
  undefined8 uStack_645;
  undefined4 local_63c;
  undefined8 local_638;
  undefined2 local_630;
  undefined4 local_62c;
  undefined1 local_628;
  undefined1 local_627;
  undefined1 local_626;
  recordInfo arStack_620 [12];
  LocalTime aLStack_614 [1556];
  
  uVar15 = 0xffffffff;
  pthread_mutex_lock((pthread_mutex_t *)PTR_s_mutexCopyDst_00402a20);
  puVar9 = PTR_s_copyFsysHandle_Dst_004029d8;
  local_c80 = 0;
  uVar11 = *(uint *)((long)param_1 + 0x10);
  uVar2 = *(uint *)((long)param_1 + 0x14);
  bVar7 = *(byte *)((long)param_1 + 0x48);
  uVar5 = *(uint *)((long)param_1 + 0x18);
  bVar8 = *(byte *)((long)param_1 + 0x49);
  iVar10 = *(int *)((long)param_1 + 0x28);
  uVar3 = *(undefined4 *)((long)param_1 + 0x2c);
  uVar6 = *(undefined4 *)((long)param_1 + 0x15d0);
  uVar1 = *(uint *)((long)param_1 + 0x40);
  uVar4 = *(uint *)((long)param_1 + 0x44);
  pvVar17 = *(void **)((long)param_1 + 0x38);
  if (uVar2 < 4) {
    uVar15 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)uVar2 * 0x80 + 0x7c);
  }
  uVar14 = 0xffffffff;
  if (uVar5 < 4) {
    uVar14 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)uVar5 * 0x80 + 0x7c);
  }
  if (iVar10 == 0) {
LAB_001aeb40:
    bVar16 = 1;
    Fsys_Close(*(undefined8 *)PTR_s_copyFsysHandle_Dst_004029d8);
  }
  else {
    uVar12 = *(undefined8 *)((long)param_1 + 0x20);
    Fsys_Seek(*(undefined8 *)PTR_s_copyFsysHandle_Dst_004029d8,*(undefined8 *)((long)param_1 + 0x30)
              ,0,&local_c80);
    Fsys_Write(*(undefined8 *)puVar9,uVar12,iVar10);
    if (iVar10 < 0x800000) goto LAB_001aeb40;
    bVar16 = 0;
  }
  FUN_003b7968(uVar3);
  if (pvVar17 != (void *)0x0) {
    operator_delete(pvVar17,4);
  }
  if (((bVar16 & bVar7) == 0) || ((bVar8 & (*PTR_sb_copyDstError_00402288 ^ 1)) == 0))
  goto LAB_001aef74;
  sidb::recordInfo::clear((recordInfo *)local_c40);
  iVar10 = sidb::Select(0xffffffff,uVar11,(recordInfo *)local_c40,false);
  puVar9 = PTR_s_recordInfo_004023d8;
  if (iVar10 == 0) {
    *(undefined8 *)(PTR_s_recordInfo_004023d8 + 0xc) = local_c34;
    *(int *)puVar9 = local_c40[0];
    *(undefined4 *)(puVar9 + 0x14) = local_c2c;
    puVar9[0x24] = 0;
    puVar9[0x1c] = 1;
    *(undefined4 *)(puVar9 + 8) = 0;
    puVar9[0x25] = local_c1b;
    *(undefined4 *)(puVar9 + 0x20) = 0;
    puVar9[0x26] = local_c1a;
    memcpy(puVar9 + 0x28,auStack_c18,0x34);
    puVar9[0x5c] = local_be4;
    memcpy(puVar9 + 0x60,auStack_be0,0x34);
    puVar9[0x94] = local_bac;
    *(undefined8 *)(puVar9 + 0x98) = local_ba8;
    *(undefined8 *)(puVar9 + 0xa0) = uStack_ba0;
    puVar9[0xa8] = local_b98;
    *(undefined8 *)(puVar9 + 0xac) = local_b94;
    *(undefined8 *)(puVar9 + 0xb4) = uStack_b8c;
    puVar9[0x5f0] = local_650;
    *(undefined8 *)(puVar9 + 0x5f3) = local_64d;
    *(undefined8 *)(puVar9 + 0x5fb) = uStack_645;
    *(undefined8 *)(puVar9 + 0x608) = local_638;
    *(undefined2 *)(puVar9 + 0x610) = local_630;
    puVar9[0x619] = local_627;
    puVar9[0x61a] = local_626;
    puVar9[0x618] = local_628;
    *(undefined4 *)(puVar9 + 0x614) = local_62c;
    *(undefined4 *)(puVar9 + 0x604) = local_63c;
    if (local_c40[0] == 1) {
      *(ulong *)(puVar9 + 0x504) = CONCAT44(uStack_738,local_73c);
      *(ulong *)(puVar9 + 0x50c) = CONCAT44(uStack_730,uStack_734);
      *(ulong *)(puVar9 + 0x514) = CONCAT44(uStack_728,local_72c);
      *(undefined8 *)(puVar9 + 0x51c) = uStack_724;
      *(undefined8 *)(puVar9 + 0x524) = local_71c;
      *(undefined8 *)(puVar9 + 0x52c) = uStack_714;
      *(undefined8 *)(puVar9 + 0x534) = local_70c;
      *(undefined8 *)(puVar9 + 0x53c) = uStack_704;
      puVar18 = (undefined8 *)(puVar9 + 0x564);
      *(undefined8 *)(puVar9 + 0x544) = local_6fc;
      *(undefined8 *)(puVar9 + 0x54c) = uStack_6f4;
      *(ulong *)(puVar9 + 0x554) = CONCAT44(uStack_6e8,local_6ec);
      *(ulong *)(puVar9 + 0x55c) = CONCAT44(uStack_6e0,uStack_6e4);
      *puVar18 = CONCAT44(uStack_6d8,local_6dc);
      *(undefined8 *)(puVar9 + 0x56c) = uStack_6d4;
      puVar13 = local_6cc;
LAB_001aee54:
      uVar12 = puVar13[1];
      puVar18[2] = *puVar13;
      puVar18[3] = uVar12;
    }
    else if (local_c40[0] == 4) {
      puVar18 = (undefined8 *)(puVar9 + 0x558);
      *(undefined8 *)(puVar9 + 0x4f8) = local_748;
      *(ulong *)(puVar9 + 0x500) = CONCAT44(local_73c,uStack_740);
      *(ulong *)(puVar9 + 0x508) = CONCAT44(uStack_734,uStack_738);
      *(ulong *)(puVar9 + 0x510) = CONCAT44(local_72c,uStack_730);
      *puVar18 = CONCAT44(uStack_6e4,uStack_6e8);
      *(ulong *)(puVar9 + 0x560) = CONCAT44(local_6dc,uStack_6e0);
      puVar13 = (undefined8 *)&uStack_6d8;
      goto LAB_001aee54;
    }
    puVar9 = PTR_s_recordInfo_004023d8;
    iVar10 = sidb::IssueUniqueId(uVar14,(uint *)(PTR_s_recordInfo_004023d8 + 4),false);
    if (iVar10 != 0) {
      *(undefined4 *)(puVar9 + 4) = 0xffffffff;
      goto LAB_001aebb4;
    }
    iVar10 = sidb::Update(0xffffffff,puVar9,false,true);
    if (iVar10 != 0) goto LAB_001aebb4;
    iVar10 = *(int *)puVar9;
    if (iVar10 == 4) {
      uVar12 = 0;
LAB_001aefa4:
      iVar10 = sidb::SetHeaderParam<unsigned_int>
                         (uVar14,uVar12,*(undefined4 *)(PTR_s_recordInfo_004023d8 + 0x4c));
      if (iVar10 != 0) goto LAB_001aebb4;
    }
    else {
      if (iVar10 == 8) {
        uVar12 = 1;
        goto LAB_001aefa4;
      }
      if (iVar10 == 0x10) {
        uVar12 = 2;
        goto LAB_001aefa4;
      }
    }
    SendEvtEditProgress(4,uVar15,uVar1,uVar4);
    puVar9 = PTR_s_recordInfo_004023d8;
    if ((*(int *)PTR_s_recordInfo_004023d8 == 4) && (local_b80 != '\0')) {
      FUN_001aa364(asStack_c60,auStack_b7f);
      FUN_001aa364(arStack_620,puVar9 + 0xc1);
      AddMediaProfileClip((ulong)uVar2,(ulong)uVar5,asStack_c60,arStack_620);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    if ((uVar1 < uVar4) && (*PTR_sb_copyDstError_00402288 == '\0')) goto LAB_001aef74;
  }
  else {
LAB_001aebb4:
    *PTR_sb_copyDstError_00402288 = 1;
  }
  sidb::set::set(asStack_c60);
  local_c78[1] = 0xffff;
  local_c78[2] = 0xffff;
  local_c78[3] = 0xffff;
  local_c78[4] = 0xffff;
  local_c78[0] = uVar14;
  iVar10 = sidb::GetRootSet(1,local_c78,1,0,1,0,asStack_c60);
  if ((iVar10 == 0) && (iVar10 = sidb::set::size(asStack_c60), iVar10 != 0)) {
    sidb::recordInfo::clear(arStack_620);
    iVar10 = sidb::set::size(asStack_c60);
    uVar11 = sidb::set::at(asStack_c60,iVar10 - 1);
    sidb::Select(0xffffffff,uVar11,arStack_620,true);
    uVar12 = sidb::ConvDefStructLocalTime2SiDBUInt64(aLStack_614);
    sidb::SetHeaderParam<unsigned_long>(uVar14,3,uVar12);
  }
  sidb::Flush(uVar14);
  FUN_0023ae28(uVar14);
  SetRecStatus(4,uVar14);
  SendEvtEditFinished(4,uVar15,uVar6,(ulong)(*PTR_sb_copyDstError_00402288 != '\0') << 1);
  sidb::set::~set(asStack_c60);
LAB_001aef74:
  iVar10 = pthread_mutex_unlock((pthread_mutex_t *)PTR_s_mutexCopyDst_00402a20);
  return iVar10;
}

