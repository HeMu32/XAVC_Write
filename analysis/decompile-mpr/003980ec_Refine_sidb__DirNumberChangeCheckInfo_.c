// sidb::Refine<sidb::DirNumberChangeCheckInfo>
// Ghidra address: 003980ec

/* int sidb::Refine<sidb::DirNumberChangeCheckInfo>(unsigned int, sidb::set const&, sidb::COL_ID,
   std::function<bool (sidb::DirNumberChangeCheckInfo)>, sidb::set*) */

int sidb::Refine<sidb::DirNumberChangeCheckInfo>
              (undefined4 param_1,undefined8 param_2,undefined4 param_3,long param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined1 auStack_20 [16];
  undefined8 local_10;
  undefined8 local_8;
  
  local_10 = 0;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(auStack_20,param_4,2);
    local_8 = *(undefined8 *)(param_4 + 0x18);
    local_10 = *(undefined8 *)(param_4 + 0x10);
  }
  iVar1 = Refine_i<sidb::DirNumberChangeCheckInfo>(param_1,param_2,param_3,auStack_20,param_5);
  FUN_001aa68c(auStack_20);
  return iVar1;
}

