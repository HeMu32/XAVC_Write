// FUN_0029552c
// Ghidra address: 0029552c

undefined8 FUN_0029552c(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  
  FUN_00294b7c();
  FUN_00294b90(param_1,param_2);
  FUN_00294b90(param_1,param_2);
  FUN_0029468c(param_1,param_2);
  FUN_00295238(param_1,param_2,param_3);
  FUN_00294b68(param_1,param_2);
  FUN_00294b7c(param_1,param_2);
  puVar4 = (undefined8 *)(param_3 + 0x288);
  for (uVar3 = 0; uVar3 < *(uint *)(param_3 + 0x284); uVar3 = uVar3 + 1) {
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_002946a0(param_1,param_2);
    FUN_00294fa8(param_1,param_2,*puVar4);
    FUN_00294b54(param_1,param_2);
    FUN_00294b7c(param_1,param_2);
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined8 *)(param_3 + 0x5a8);
  for (uVar3 = 0; uVar3 < *(uint *)(param_3 + 0x5a0); uVar3 = uVar3 + 1) {
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_002946b4(param_1,param_2);
    FUN_00294fa8(param_1,param_2,*puVar4);
    FUN_00294b54(param_1,param_2);
    FUN_00294b7c(param_1,param_2);
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = 0; uVar3 < *(uint *)(param_3 + 0x5b8); uVar3 = uVar3 + 1) {
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_00294b90(param_1,param_2);
    FUN_002946c8(param_1,param_2);
    FUN_00295444(param_1,param_2,*(undefined8 *)(param_3 + (ulong)uVar3 * 8 + 0x5c0));
    FUN_00294b54(param_1,param_2);
    FUN_00294b7c(param_1,param_2);
  }
  FUN_00294b90(param_1,param_2);
  FUN_00294b90(param_1,param_2);
  FUN_00294754(param_1,param_2);
  cVar1 = FUN_002921c0(param_2);
  uVar2 = 0;
  if (cVar1 != '\0') {
    FUN_00290aa4(5,"xavcIfo_MediaProfileParserImplXmlWriter.cpp",0x182,0xd);
    uVar2 = 0xd;
  }
  return uVar2;
}

