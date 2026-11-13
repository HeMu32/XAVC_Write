// Ghidra: 0028bc30; ELF VMA = Ghidra - 0x100000

undefined8 FUN_0028bc30(long *param_1,char *param_2)

{
  uint uVar1;
  char cVar2;
  size_t sVar3;
  char *__dest;
  void *pvVar4;
  undefined8 uVar5;
  
  sVar3 = strlen(param_2);
  __dest = operator_new__(0x80);
  param_1[4] = (long)__dest;
  strncpy(__dest,param_2,sVar3 & 0xffffffff);
  uVar1 = *(uint *)(param_1 + 2);
  __dest[sVar3 & 0xffffffff] = '\0';
  pvVar4 = operator_new__((ulong)uVar1 & 0xfffffffc);
  param_1[5] = (long)pvVar4;
  pvVar4 = operator_new(0x28);
  FUN_002911c4(pvVar4,param_1[1],0xb000);
  param_1[6] = (long)pvVar4;
  pvVar4 = operator_new(0x20);
  FUN_00291d00(pvVar4,param_1[1],0xb000);
  param_1[7] = (long)pvVar4;
  pvVar4 = operator_new(0xfc68);
  FUN_00293ac4(pvVar4,param_1[6]);
  param_1[8] = (long)pvVar4;
  pvVar4 = operator_new(1);
  FUN_0029460c();
  param_1[9] = (long)pvVar4;
  pvVar4 = operator_new(0x18);
  FUN_002920f8(pvVar4,0xb000);
  param_1[10] = (long)pvVar4;
  pvVar4 = operator_new(0x18);
  FUN_002920f8(pvVar4,0xb000);
  param_1[0xb] = (long)pvVar4;
  pvVar4 = operator_new(0x48);
  FUN_00291580(pvVar4,param_1[5],(int)param_1[2]);
  param_1[0xc] = (long)pvVar4;
  pvVar4 = operator_new(0xecf4);
  param_1[0xd] = (long)pvVar4;
  if (param_1[5] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x6d;
  }
  else if (param_1[6] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x73;
  }
  else if (param_1[7] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x79;
  }
  else if (param_1[8] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x7f;
  }
  else if (param_1[9] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x85;
  }
  else if (param_1[10] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x8b;
  }
  else if (param_1[0xb] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x91;
  }
  else if (param_1[0xc] == 0) {
    FUN_0028bc28(param_1,2);
    uVar5 = 0x97;
  }
  else {
    cVar2 = FUN_00291400();
    if (cVar2 == '\0') {
      FUN_0028bc28(param_1,2);
      uVar5 = 0x9d;
    }
    else {
      if (param_1[0xd] != 0) {
                    /* WARNING: Could not recover jumptable at 0x0028bec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (**(code **)(*param_1 + 0xa8))(param_1);
        return uVar5;
      }
      FUN_0028bc28(param_1,2);
      uVar5 = 0xa3;
    }
  }
  FUN_00290aa4(1,"xavcIfo_CommonMediaProfileParserImpl.cpp",uVar5);
  return 1;
}

