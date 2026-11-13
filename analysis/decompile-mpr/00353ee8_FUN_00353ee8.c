// FUN_00353ee8
// Ghidra address: 00353ee8

undefined4 FUN_00353ee8(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_60 [30];
  char local_42;
  undefined8 local_40;
  undefined4 local_34;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar1 = NRTERRCNV::ConvToMPR2(2);
  }
  else {
    *(undefined4 *)((long)param_2 + 4) = 0;
    *(undefined4 *)((long)param_2 + 0xc) = 0;
    FUN_00352c80(auStack_60);
    iVar2 = FUN_0033ad00(*(undefined8 *)(param_1 + 8),0,auStack_60);
    if (iVar2 == 0) {
      if (local_42 != '\0') {
        *param_2 = local_40;
      }
      uVar3 = FUN_00350880(local_34);
      param_2[1] = uVar3;
    }
    uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
    std::__cxx11::string::_M_dispose();
  }
  return uVar1;
}

