// FUN_0032f0a0
// Ghidra address: 0032f0a0

undefined8 FUN_0032f0a0(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined1 extraout_w1;
  undefined8 uVar2;
  string asStack_40 [32];
  string asStack_20 [32];
  
  if (param_2 != (undefined8 *)0x0) {
    uVar2 = 5;
    if (*(long *)(param_1 + 0x10) != 0) {
      lVar1 = FUN_0032ca5c(param_1,*(long *)(param_1 + 0x10),4,0);
      if ((lVar1 == 0) || (lVar1 = FUN_0032c960(param_1,lVar1,6), lVar1 == 0)) {
        uVar2 = 1;
      }
      else {
        FUN_00337e2c(asStack_40);
        std::__cxx11::string::string(asStack_20,asStack_40);
        uVar2 = FUN_0035150c(asStack_20);
        *(undefined1 *)(param_2 + 1) = extraout_w1;
        *param_2 = uVar2;
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  return 2;
}

