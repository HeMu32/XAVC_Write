// FUN_00292c68
// Ghidra address: 00292c68

undefined8 FUN_00292c68(long param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_00291210(*(undefined8 *)(param_1 + 8),1);
  iVar1 = FUN_00293fe8(param_1 + 0x10,*(undefined8 *)(param_1 + 8));
  *param_2 = param_1 + 0xf680;
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = 0x70;
  }
  else {
    uVar2 = 0x6b;
  }
  FUN_00290aa4(3,"xavcIfo_MediaProfileParserImplXmlReader.cpp",uVar2,iVar1);
  return 0xe;
}

