// FUN_00294ba4
// Ghidra address: 00294ba4

undefined8 FUN_00294ba4(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_00294b7c();
  FUN_00294b90(param_1,param_2);
  FUN_0029463c(param_1,param_2);
  FUN_00294b68(param_1,param_2);
  uVar2 = FUN_002921b8(param_2);
  *param_3 = uVar2;
  FUN_00294b7c(param_1,param_2);
  FUN_00294b90(param_1,param_2);
  FUN_00294704(param_1,param_2);
  cVar1 = FUN_002921c0(param_2);
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
    FUN_00290aa4(5,"xavcIfo_MediaProfileParserImplXmlWriter.cpp",0x146,0xd);
    uVar3 = 0xd;
  }
  return uVar3;
}

