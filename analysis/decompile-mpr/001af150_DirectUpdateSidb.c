// mpr::DirectUpdateSidb
// Ghidra address: 001af150

/* mpr::DirectUpdateSidb(mpr::EditType, int, mpr::ContentsList const&, bool&, sidb::recordInfo*) */

undefined8
mpr::DirectUpdateSidb
          (int param_1,int param_2,ContentsList *param_3,undefined1 *param_4,recordInfo *param_5)

{
  DirectEditRequestCounter *this;
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_10;
  uint local_c;
  set *local_8;
  
  iVar2 = GetContensSize(param_3);
  if (iVar2 != 1) {
    return 0;
  }
  ContentsList::Get(param_3,0,&local_8,&local_10);
  if (local_10 == 0xffffffff) {
    local_10 = 0;
  }
  uVar3 = sidb::set::at(local_8,local_10);
  if ((param_5 != (recordInfo *)0x0) &&
     (iVar2 = sidb::Select(0xffffffff,uVar3,param_5,false), iVar2 != 0)) {
    return 2;
  }
  if (param_1 == 1) {
    iVar2 = sidb::PartialUpdate<bool>(0xffffffff,uVar3,10,param_2 == 0,1,0);
    this = (DirectEditRequestCounter *)PTR_s_directProtectReqCnt_00401f18;
  }
  else {
    if (param_1 != 3) {
      if (param_1 != 5) {
        return 3;
      }
      sidb::GetMediaIdFromUniqueId(uVar3,&local_c);
      uVar4 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,local_c);
      cVar1 = IsClipEdit(local_c,uVar3);
      if ((cVar1 == '\0') || (cVar1 = IsMediaRemain(uVar4), cVar1 == '\0')) {
        return 0xb;
      }
      iVar2 = sidb::PartialUpdate<unsigned_int>(0xffffffff,uVar3,0x1b,param_2,1,0);
      if (iVar2 != 0) {
        return 2;
      }
      goto LAB_001af1f4;
    }
    iVar2 = sidb::PartialUpdate<signed_char>(0xffffffff,uVar3,0xb,param_2,1,0);
    this = (DirectEditRequestCounter *)PTR_s_directRatingReqCnt_00401f88;
  }
  if (iVar2 != 0) {
    return 2;
  }
  DirectEditRequestCounter::Request(this,uVar3);
LAB_001af1f4:
  *param_4 = 1;
  return 0;
}

