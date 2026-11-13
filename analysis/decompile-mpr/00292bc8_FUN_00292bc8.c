// FUN_00292bc8
// Ghidra address: 00292bc8

undefined8 FUN_00292bc8(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  *(undefined8 *)(param_1 + 0x38) = param_2;
  *(undefined8 *)(param_1 + 0x40) = param_3;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_00291210(*(undefined8 *)(param_1 + 8),0,0,0);
  *(undefined1 *)(param_1 + 0x48) = 0;
  *(undefined1 *)(param_1 + 0x49) = 0;
  *(undefined1 *)(param_1 + 0x4a) = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  iVar1 = FUN_00293fe8(param_1 + 0x10,*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x28) != 0) {
      return 0xe;
    }
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = 0x59;
  }
  else {
    uVar2 = 0x50;
  }
  FUN_00290aa4(3,"xavcIfo_MediaProfileParserImplXmlReader.cpp",uVar2,iVar1);
  return 0xe;
}

