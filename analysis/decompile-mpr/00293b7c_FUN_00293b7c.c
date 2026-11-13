// FUN_00293b7c
// Ghidra address: 00293b7c

undefined8
FUN_00293b7c(long param_1,void *param_2,uint param_3,undefined8 param_4,undefined4 param_5)

{
  undefined8 uVar1;
  void *local_18 [2];
  int local_8;
  
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_00291210(param_4,1,0,param_5);
  FUN_00291228(local_18,param_4);
  if (local_8 == 0) {
    memcpy(param_2,local_18[0],(ulong)param_3);
    uVar1 = 0;
  }
  else {
    FUN_00290aa4(3,"xavcIfo_MediaProfileParserImplXmlReader.cpp",0x243);
    uVar1 = 0xe;
  }
  return uVar1;
}

