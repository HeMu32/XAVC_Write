// mpr::UpdateMediaProfileClipStatusInEdit
// Ghidra address: 001ae654

/* mpr::UpdateMediaProfileClipStatusInEdit(unsigned int, sidb::recordInfo&, sidb::ClipStatus) */

undefined4
mpr::UpdateMediaProfileClipStatusInEdit(undefined4 param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_46;
  undefined4 local_44;
  string asStack_40 [8];
  long local_38;
  undefined4 local_20 [8];
  
  FUN_001aa364(asStack_40,&DAT_003d7eaf);
  local_46 = 0;
  local_44 = 0;
  if ((*(char *)(param_2 + 0xc0) == '\0') ||
     (std::__cxx11::string::operator=(asStack_40,(char *)(param_2 + 0xc1)), local_38 == 0)) {
    uVar2 = 2;
  }
  else {
    std::__cxx11::string::string((string *)local_20,asStack_40);
    FUN_001ae1ac((string *)local_20,&local_46);
    std::__cxx11::string::_M_dispose();
    iVar1 = FUN_0028223c(param_1,local_46,&local_44);
    if (iVar1 == 0) {
      ConvClipStatusTypeSidb2Mpf(param_3,(string *)local_20);
      iVar1 = FUN_00282724(param_1,local_44,local_20[0]);
      uVar2 = 0;
      if (iVar1 == 0) goto LAB_001ae698;
    }
    uVar2 = 0xb;
  }
LAB_001ae698:
  std::__cxx11::string::_M_dispose();
  return uVar2;
}

