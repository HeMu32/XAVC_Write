// FUN_0032d6e4
// Ghidra address: 0032d6e4

int FUN_0032d6e4(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  long local_28;
  undefined1 auStack_20 [32];
  
  local_28 = FUN_0032ca5c(param_1,*(undefined8 *)(param_1 + 0x10),5,0);
  if (local_28 != 0) {
    if (param_3 == '\0') {
      return 3;
    }
    iVar1 = FUN_0032c7c8(param_1,local_28);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if (local_28 == 0) {
    iVar1 = FUN_0032d5a0(param_1,*(undefined8 *)(param_1 + 0x10),5,1,&local_28);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  FUN_00345f70(auStack_20,param_2);
  iVar1 = FUN_0032c620(param_1,local_28,6,auStack_20,0);
  std::__cxx11::string::_M_dispose();
  return iVar1;
}

