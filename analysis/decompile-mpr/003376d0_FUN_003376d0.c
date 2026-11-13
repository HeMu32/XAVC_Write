// FUN_003376d0
// Ghidra address: 003376d0

void FUN_003376d0(long *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  long lVar5;
  undefined1 auStack_e0 [32];
  undefined1 auStack_c0 [32];
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [32];
  undefined4 local_20 [8];
  
  puVar1 = PTR_DAT_004029d0 + 0x10;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = (long)puVar1;
  param_1[1] = 0;
  pvVar4 = operator_new(8);
  FUN_0032b534();
  param_1[1] = (long)pvVar4;
  uVar2 = FUN_0032b470(pvVar4);
  uVar3 = (**(code **)(*(long *)param_1[1] + 0x30))();
  pvVar4 = operator_new(0x38);
  FUN_00338db0(pvVar4,uVar2,uVar3);
  param_1[3] = (long)pvVar4;
  lVar5 = FUN_00338828(pvVar4);
  param_1[2] = lVar5;
  if (lVar5 != 0) {
    FUN_00347bc0(auStack_e0,0);
    FUN_00337f34(param_1[2],auStack_e0);
    FUN_00337f44(param_1[2],0);
    lVar5 = FUN_0033875c(param_1[3]);
    if (lVar5 != 0) {
      FUN_00347ce4(auStack_c0,0);
      FUN_00337da0(lVar5,auStack_c0);
      local_20[0] = 2;
      FUN_00346204(auStack_a0,local_20);
      FUN_00337da8(lVar5,auStack_a0);
      FUN_00338bd4(param_1[2],lVar5);
      lVar5 = FUN_0033875c(param_1[3]);
      if (lVar5 != 0) {
        FUN_00347ce4(auStack_80,1);
        FUN_00337da0(lVar5,auStack_80);
        local_20[0] = 1;
        FUN_00346338(auStack_60,local_20);
        FUN_00337da8(lVar5,auStack_60);
        FUN_00338bd4(param_1[2],lVar5);
        lVar5 = FUN_0033875c(param_1[3]);
        if (lVar5 != 0) {
          FUN_00347ce4(auStack_40,2);
          FUN_00337da0(lVar5,auStack_40);
          FUN_0032c3e0(local_20,"http://www.w3.org/2001/XMLSchema-instance");
          FUN_00337da8(lVar5,local_20);
          FUN_00338bd4(param_1[2],lVar5);
          std::__cxx11::string::_M_dispose();
          std::__cxx11::string::_M_dispose();
        }
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    std::__cxx11::string::_M_dispose();
  }
  return;
}

