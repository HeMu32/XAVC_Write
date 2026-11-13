// FUN_00295858
// Ghidra address: 00295858

undefined8 FUN_00295858(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  FUN_00292148(param_2,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>",0x26);
  FUN_00294b7c(param_1,param_2);
  FUN_00294614(param_1,param_2);
  FUN_00295128(param_1,param_2,param_3);
  FUN_00294b68(param_1,param_2);
  FUN_00294b7c(param_1,param_2);
  FUN_00294b90(param_1,param_2);
  FUN_00294628(param_1,param_2);
  FUN_00294b68(param_1,param_2);
  FUN_00294b7c(param_1,param_2);
  cVar1 = FUN_00294c5c(param_1,param_3);
  if (cVar1 != '\0') {
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_00294650(param_1,param_2);
    FUN_0029575c(param_1,param_2,"systemId",8,param_3 + 0x128);
    FUN_00294130(param_2,"systemKind",10,param_3 + 0x134);
    FUN_00294130(param_2,"masterVersion",0xd,param_3 + 0x17c);
    FUN_00294b54(param_1,param_2);
    FUN_00294b7c(param_1,param_2);
  }
  cVar1 = FUN_00294c8c(param_1,param_3);
  if (cVar1 != '\0') {
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_00294664(param_1,param_2);
    FUN_00294db0(param_1,param_2,"mediaId",7,param_3 + 0x1c4);
    FUN_0029455c(param_2,"mediaKind",param_3 + 0x1d8);
    FUN_00294130(param_2,"mediaName",9,param_3 + 0x224);
    FUN_00294b54(param_1,param_2);
    FUN_00294b7c(param_1,param_2);
  }
  FUN_00294b90(param_1,param_2);
  FUN_002946f0(param_1,param_2);
  FUN_00294b7c(param_1,param_2);
  FUN_002946dc(param_1,param_2);
  FUN_00294b7c(param_1,param_2);
  cVar1 = FUN_002921c0(param_2);
  uVar2 = 0;
  if (cVar1 != '\0') {
    FUN_00290aa4(5,"xavcIfo_MediaProfileParserImplXmlWriter.cpp",0x131,0xd);
    uVar2 = 0xd;
  }
  return uVar2;
}

