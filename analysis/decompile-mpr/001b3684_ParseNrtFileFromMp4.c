// mpr::ParseNrtFileFromMp4
// Ghidra address: 001b3684

/* mpr::ParseNrtFileFromMp4(char const*, NrtMetaWrapper*) */

undefined4 mpr::ParseNrtFileFromMp4(char *param_1,NrtMetaWrapper *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 local_74;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [80];
  
  pvVar3 = operator_new__(0x200000);
  local_74 = 0x200000;
  FUN_00341acc(auStack_50);
  iVar1 = Fsys_Stat(param_1,auStack_70);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_00342210(auStack_50,param_1,pvVar3,0x200000,&local_74), iVar1 == 0)) {
    uVar2 = FUN_00353e8c(param_2,pvVar3,local_74);
  }
  else {
    uVar2 = 0xb;
  }
  operator_delete__(pvVar3);
  FUN_00341b6c(auStack_50);
  return uVar2;
}

