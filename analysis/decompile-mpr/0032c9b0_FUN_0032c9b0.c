// FUN_0032c9b0
// Ghidra address: 0032c9b0

undefined8 FUN_0032c9b0(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 extraout_w1;
  string asStack_40 [32];
  string asStack_20 [32];
  
  if (param_2 != (undefined8 *)0x0) {
    if ((*(long *)(param_1 + 0x10) == 0) ||
       (lVar2 = FUN_0032c960(param_1,*(long *)(param_1 + 0x10),0x12), lVar2 == 0)) {
      uVar1 = 5;
    }
    else {
      FUN_00337e2c(asStack_40);
      std::__cxx11::string::string(asStack_20,asStack_40);
      uVar1 = FUN_0035150c(asStack_20);
      *(undefined1 *)(param_2 + 1) = extraout_w1;
      *param_2 = uVar1;
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}

