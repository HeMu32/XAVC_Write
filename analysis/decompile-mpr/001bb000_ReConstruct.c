// mpr::ReConstruct
// Ghidra address: 001bb000

/* mpr::ReConstruct(unsigned int, bool*, sidb::ContentType, bool&) */

int mpr::ReConstruct(uint param_1,bool *param_2,uint param_3,byte *param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_664;
  uint local_660;
  undefined1 auStack_65c [4];
  uint local_658 [6];
  set asStack_640 [32];
  undefined2 local_620;
  undefined2 local_61e;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined1 local_61a;
  undefined1 local_619;
  uint local_618;
  LocalTime aLStack_614 [1556];
  
  local_61c = 3;
  local_620 = 0x2300;
  local_61e = 0xe00;
  local_61b = 0;
  local_61a = 0;
  uVar4 = 0xffffffff;
  local_619 = 0;
  local_618 = param_1;
  FUN_001b7d90((recordInfo *)&local_620,0xc);
  if (param_1 < 4) {
    uVar4 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  local_664 = 0;
  local_660 = 0;
  sidb::set::set(asStack_640);
  local_658[1] = 0xffff;
  local_658[2] = 0xffff;
  local_658[3] = 0xffff;
  local_658[4] = 0xffff;
  *param_4 = 1;
  local_658[0] = uVar4;
  iVar1 = FUN_0023ae90(uVar4,auStack_65c);
  if (((iVar1 == 0) &&
      (((param_3 & 1) == 0 ||
       (iVar1 = RepairDcfInconsistencies(param_1,param_2,&local_664), iVar1 == 0)))) &&
     (((param_3 >> 2 & 1) == 0 ||
      (iVar1 = RepairM4Inconsistencies(param_1,param_2,&local_664,&local_660), iVar1 == 0)))) {
    *param_4 = 0;
    iVar1 = sidb::GetRootSet(1,local_658,1,0,0,0,asStack_640);
    if ((iVar1 == 0) && (iVar1 = sidb::set::size(asStack_640), iVar1 != 0)) {
      uVar2 = sidb::set::at(asStack_640,iVar1 - 1);
      sidb::recordInfo::clear((recordInfo *)&local_620);
      iVar1 = sidb::Select(0xffffffff,uVar2,(recordInfo *)&local_620,true);
      if (iVar1 == 0) {
        uVar3 = sidb::ConvDefStructLocalTime2SiDBUInt64(aLStack_614);
        sidb::SetHeaderParam<unsigned_long>(uVar4,3,uVar3);
      }
    }
  }
  iVar1 = FUN_0023af50(uVar4);
  if (iVar1 == 0) {
    if (((((param_3 >> 2 & 1) == 0) ||
         (iVar1 = sidb::SetHeaderParam<unsigned_int>(uVar4,0,local_660), iVar1 == 0)) &&
        (iVar1 = sidb::Reallocate(uVar4), iVar1 == 0)) && (iVar1 = sidb::Flush(uVar4), iVar1 == 0))
    {
      FUN_0022bc00(param_1,1);
      iVar1 = capidtbl::RemakeCapIdTbl((LocalTime *)0x0);
      if (iVar1 == 0) {
        FUN_00231b90(0);
        FUN_0022d23c(0);
      }
    }
    else {
      iVar1 = 2;
    }
  }
  local_61b = 0;
  local_61c = 3;
  local_61a = 0;
  local_620 = 0x2300;
  local_619 = 0;
  local_61e = 0xe0f;
  local_618 = (uint)*param_4;
  FUN_001b7d90((recordInfo *)&local_620,0xc);
  sidb::set::~set(asStack_640);
  return iVar1;
}

