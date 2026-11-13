// mpr::DeleteMediaProfileClip
// Ghidra address: 001ae380

/* mpr::DeleteMediaProfileClip(unsigned int, std::__cxx11::string) */

void mpr::DeleteMediaProfileClip(undefined4 param_1,string *param_2)

{
  undefined2 local_22;
  undefined4 local_20 [8];
  
  local_22 = 0;
  std::__cxx11::string::string((string *)local_20,param_2);
  FUN_001ae1ac((string *)local_20,&local_22);
  std::__cxx11::string::_M_dispose();
  local_20[0] = 0xffffffff;
  FUN_0028223c(param_1,local_22,(string *)local_20);
  FUN_0028233c(param_1,(string *)local_20,1);
  return;
}

