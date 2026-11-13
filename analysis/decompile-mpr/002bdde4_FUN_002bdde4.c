// FUN_002bdde4
// Ghidra address: 002bdde4

ulong FUN_002bdde4(undefined8 param_1,int param_2)

{
  undefined1 *puVar1;
  _func_ios_base_ptr_ios_base_ptr *p_Var2;
  undefined1 *local_1a0 [2];
  undefined1 auStack_190 [16];
  istream aiStack_180 [152];
  uint local_e8;
  
  local_1a0[0] = auStack_190;
  std::__cxx11::string::_M_construct((ulong)local_1a0,'\x01');
  std::__cxx11::istringstream::istringstream((istringstream *)aiStack_180,local_1a0,8);
  std::__cxx11::string::_M_dispose();
  p_Var2 = (_func_ios_base_ptr_ios_base_ptr *)PTR_LAB_00401d00;
  if ((param_2 == 8) ||
     (p_Var2 = (_func_ios_base_ptr_ios_base_ptr *)PTR_FUN_00402ee0, param_2 == 0x10)) {
    std::istream::operator>>(aiStack_180,p_Var2);
  }
  std::istream::operator>>(aiStack_180,(long *)local_1a0);
  puVar1 = local_1a0[0];
  if ((local_e8 & 5) != 0) {
    puVar1 = (undefined1 *)0xffffffffffffffff;
  }
  std::__cxx11::istringstream::~istringstream((istringstream *)aiStack_180);
  return (ulong)puVar1 & 0xffffffff;
}

