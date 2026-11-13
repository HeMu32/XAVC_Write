// FUN_00354304
// Ghidra address: 00354304

undefined4 FUN_00354304(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_50 [32];
  char local_30;
  undefined4 local_2c;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = NRTERRCNV::ConvToMPR2(2);
  }
  else {
    FUN_00352c30(auStack_50);
    iVar2 = FUN_0033ac50(*(undefined8 *)(param_1 + 8),auStack_50);
    if (iVar2 == 0) {
      if (local_30 == '\0') {
        local_2c = 3;
      }
      *param_2 = local_2c;
    }
    uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
    std::__cxx11::string::_M_dispose();
  }
  return uVar1;
}

