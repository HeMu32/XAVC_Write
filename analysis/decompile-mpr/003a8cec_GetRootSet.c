// sidb::GetRootSet
// Ghidra address: 003a8cec

/* sidb::GetRootSet(unsigned int, sidb::ROOT_SET_TYPE, bool, bool, bool, sidb::set*) */

void sidb::GetRootSet(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined8 param_6)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_14 = 0xffff;
  uStack_10 = 0xffff;
  local_c = 0xffff;
  uStack_8 = 0xffff;
  local_18 = param_1;
  GetRootSet(1,&local_18,param_2,param_3,param_4,param_5,param_6);
  return;
}

