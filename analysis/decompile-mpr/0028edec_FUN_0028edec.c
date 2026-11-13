// FUN_0028edec
// Ghidra address: 0028edec

undefined8 FUN_0028edec(long param_1,undefined8 param_2,int *param_3)

{
  short sVar1;
  short sVar2;
  undefined8 uVar3;
  int iVar4;
  short *psVar5;
  
  *param_3 = -1;
  if (*(int *)(param_1 + 0xafc60) == 0) {
LAB_0028ee5c:
    uVar3 = 0x69;
  }
  else {
    sVar2 = FUN_0028eba0();
    iVar4 = 0;
    psVar5 = (short *)(param_1 + 0x34);
    do {
      if (*(int *)(param_1 + 0xafc60) == iVar4) goto LAB_0028ee5c;
      sVar1 = *psVar5;
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 0x22;
    } while (sVar1 != sVar2);
    uVar3 = 0;
    *param_3 = iVar4;
  }
  return uVar3;
}

