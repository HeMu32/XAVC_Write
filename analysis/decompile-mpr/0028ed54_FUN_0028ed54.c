// FUN_0028ed54
// Ghidra address: 0028ed54

undefined8 FUN_0028ed54(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  
  sVar3 = FUN_0028eba0();
  uVar4 = 0;
  psVar5 = (short *)(param_1 + 0x34);
  while( true ) {
    if (uVar4 == *(uint *)(param_1 + 0xafc60)) {
      return 0x6a;
    }
    if (*psVar5 == sVar3) break;
    uVar4 = uVar4 + 1;
    psVar5 = psVar5 + 0x22;
  }
  if (*(int *)(param_1 + (ulong)uVar4 * 0x44 + 0x2c) == 2) {
    return 0x6b;
  }
  puVar1 = (undefined8 *)(param_1 + (ulong)uVar4 * 0x44 + 0x36);
  uVar2 = puVar1[1];
  *param_3 = *puVar1;
  param_3[1] = uVar2;
  uVar2 = puVar1[3];
  param_3[2] = puVar1[2];
  param_3[3] = uVar2;
  return 0;
}

