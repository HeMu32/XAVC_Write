// FUN_0032c6e0
// Ghidra address: 0032c6e0

undefined4 FUN_0032c6e0(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_20 [8];
  long local_18;
  
  FUN_00345f70(auStack_20,param_2);
  if (local_18 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = FUN_0032c620(param_1,*(undefined8 *)(param_1 + 0x10),0x12,auStack_20,0);
  }
  std::__cxx11::string::_M_dispose();
  return uVar1;
}

