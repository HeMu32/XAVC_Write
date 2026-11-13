// FUN_0020c4a4
// Ghidra address: 0020c4a4

long FUN_0020c4a4(long param_1,undefined4 *param_2,uint *param_3)

{
  undefined8 *puVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  long lVar9;
  
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x1d20) + (ulong)*param_3 * 0x40);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  uVar3 = *param_3;
  lVar9 = (ulong)uVar3 * 0x40;
  bVar8 = *(byte *)((long)param_2 + 0x2a);
  iVar4 = param_2[4];
  lVar2 = *(long *)(param_1 + 0x1d20) + lVar9;
  *(undefined1 *)(*(long *)(param_1 + 0x1d20) + lVar9) = 0;
  iVar5 = param_2[5];
  *(byte *)(lVar2 + 1) =
       *(byte *)(lVar2 + 1) & 0xf0 | *(byte *)(lVar2 + 1) & 3 | ((iVar4 != iVar5) + '\x02') * '\x04'
  ;
  *(undefined1 *)(lVar2 + 2) = 1;
  *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) & 0xfe | bVar8 & 1;
  uVar6 = *param_2;
  uVar7 = param_2[7];
  *(int *)(lVar2 + 0x20) = iVar5;
  *(undefined4 *)(lVar2 + 0x24) = 0;
  *(undefined4 *)(lVar2 + 0x38) = uVar7;
  uVar3 = uVar3 + 1;
  *(undefined1 *)(lVar2 + 0x34) = 1;
  *(undefined8 *)(lVar2 + 8) = 0;
  *(undefined4 *)(lVar2 + 0x10) = uVar6;
  *(int *)(lVar2 + 0x18) = iVar4;
  *(undefined4 *)(lVar2 + 0x1c) = 0;
  *(undefined1 *)(lVar2 + 0x2a) = 0xff;
  *param_3 = uVar3;
  return (ulong)(*(uint *)(param_1 + 0x1d28) < uVar3) << 1;
}

