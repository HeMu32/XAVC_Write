// FUN_00349b1c
// Ghidra address: 00349b1c

int FUN_00349b1c(ulong param_1,uint param_2,long param_3)

{
  int iVar1;
  ulong uVar2;
  undefined1 local_41;
  undefined1 *local_40;
  undefined8 local_38;
  undefined1 local_30 [16];
  string asStack_20 [32];
  
  iVar1 = 2;
  if ((ulong)(param_2 << 1) == *(ulong *)(param_1 + 8)) {
    local_40 = local_30;
    local_30[0] = 0;
    local_41 = 0;
    local_38 = 0;
    for (uVar2 = 0; (uVar2 != param_2 && (uVar2 != (param_2 & 0x7fffffff))); uVar2 = uVar2 + 1) {
      local_38 = 0;
      *local_40 = 0;
      std::__cxx11::string::substr(param_1,uVar2 << 1);
      std::__cxx11::string::append((string *)&local_40);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::string(asStack_20,(string *)&local_40);
      iVar1 = FUN_00349a20(asStack_20,&local_41);
      std::__cxx11::string::_M_dispose();
      if (iVar1 != 0) goto LAB_00349bfc;
      *(undefined1 *)(param_3 + uVar2) = local_41;
    }
    iVar1 = 0;
LAB_00349bfc:
    std::__cxx11::string::_M_dispose();
  }
  return iVar1;
}

