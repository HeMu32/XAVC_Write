// FUN_00297fc8
// Ghidra address: 00297fc8

int FUN_00297fc8(long param_1,long param_2,ulong param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined8 local_18;
  undefined4 local_10;
  char local_c;
  int local_8;
  
  FUN_00291210(*(undefined8 *)(param_1 + 0x28),1,param_3,
               *(int *)(*(long *)(param_1 + 0x60) + 0xea7c) - (int)param_3);
  FUN_00291d44(*(undefined8 *)(param_1 + 0x30),param_3 & 0xffffffff);
  lVar7 = *(long *)(param_1 + 0x48);
  if (param_2 == lVar7) {
    lVar7 = *(long *)(param_1 + 0x50);
  }
  while( true ) {
    lVar8 = lVar7;
    FUN_00291228(&local_18,*(undefined8 *)(param_1 + 0x28));
    if (local_8 != 0) {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      uVar5 = 0x143;
      iVar4 = local_8;
      goto LAB_0029804c;
    }
    FUN_0029213c(lVar8);
    FUN_00292148(lVar8,local_18,local_10);
    cVar1 = FUN_002921c0(lVar8);
    if (cVar1 != '\0') {
      FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
      FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",0x14b,0xd);
      return 0xd;
    }
    uVar6 = *(undefined8 *)(param_1 + 0x30);
    uVar5 = FUN_002921b0(param_2);
    uVar3 = FUN_002921b8(param_2);
    iVar4 = FUN_00291f58(uVar6,uVar5,uVar3);
    if (iVar4 != 0) break;
    lVar7 = param_2;
    param_2 = lVar8;
    if (local_c != '\0') {
      uVar6 = *(undefined8 *)(param_1 + 0x30);
      uVar5 = FUN_002921b0(lVar8);
      uVar3 = FUN_002921b8(lVar8);
      iVar4 = FUN_00291f58(uVar6,uVar5,uVar3);
      iVar2 = 0;
      if (iVar4 != 0) {
        FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
        uVar5 = 0x161;
LAB_0029804c:
        FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",uVar5,iVar4);
        iVar2 = iVar4;
      }
      return iVar2;
    }
  }
  FUN_0028bc28(*(undefined8 *)(param_1 + 8),2);
  uVar5 = 0x152;
  goto LAB_0029804c;
}

