// FUN_0028cee4
// Ghidra address: 0028cee4

int FUN_0028cee4(long param_1,long param_2,ulong param_3,char param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 local_18;
  undefined4 local_10;
  char local_c;
  int local_8;
  
  FUN_00291210(*(undefined8 *)(param_1 + 0x28),1,param_3,
               *(int *)(*(long *)(param_1 + 0x60) + 0xea7c) - (int)param_3);
  FUN_00291d44(*(undefined8 *)(param_1 + 0x30),param_3 & 0xffffffff);
  lVar6 = *(long *)(param_1 + 0x48);
  if (param_2 == lVar6) {
    lVar6 = *(long *)(param_1 + 0x50);
  }
  do {
    lVar7 = lVar6;
    FUN_00291228(&local_18,*(undefined8 *)(param_1 + 0x28));
    if (local_8 != 0) {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      uVar5 = 0x27d;
      iVar3 = local_8;
      goto LAB_0028cf70;
    }
    FUN_0029213c(lVar7);
    FUN_00292148(lVar7,local_18,local_10);
    cVar1 = FUN_002921c0(lVar7);
    if (cVar1 != '\0') {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",0x285,0xd);
      return 0xd;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x30);
    if (param_4 == '\0') {
      uVar4 = FUN_002921b0(param_2);
      uVar2 = FUN_002921b8(param_2);
      iVar3 = FUN_00291f58(uVar5,uVar4,uVar2);
    }
    else {
      uVar4 = FUN_002921b0(param_2);
      uVar2 = FUN_002921b8(param_2);
      iVar3 = FUN_00291dfc(uVar5,uVar4,uVar2);
    }
    if (iVar3 != 0) {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      uVar5 = 0x292;
      goto LAB_0028cf70;
    }
    lVar6 = param_2;
    param_2 = lVar7;
  } while (local_c == '\0');
  uVar5 = *(undefined8 *)(param_1 + 0x30);
  if (param_4 == '\0') {
    uVar4 = FUN_002921b0(lVar7);
    uVar2 = FUN_002921b8(lVar7);
    iVar3 = FUN_00291f58(uVar5,uVar4,uVar2);
    if (iVar3 != 0) goto LAB_0028d0ac;
    iVar3 = thunk_FUN_00291ea8(*(undefined8 *)(param_1 + 0x30));
  }
  else {
    uVar4 = FUN_002921b0(lVar7);
    uVar2 = FUN_002921b8(lVar7);
    iVar3 = FUN_00291dfc(uVar5,uVar4,uVar2);
    if (iVar3 != 0) {
LAB_0028d0ac:
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      uVar5 = 0x2a7;
      goto LAB_0028cf70;
    }
    iVar3 = FUN_00291d4c(*(undefined8 *)(param_1 + 0x30));
  }
  if (iVar3 == 0) {
    return 0;
  }
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
  uVar5 = 0x2b5;
LAB_0028cf70:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar5,iVar3);
  return iVar3;
}

