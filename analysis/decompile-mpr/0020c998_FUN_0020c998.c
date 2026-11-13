// FUN_0020c998
// Ghidra address: 0020c998

long FUN_0020c998(long param_1,long param_2,uint *param_3,int *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  uint local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  if ((*(char *)(param_2 + 0x2b) == '\0') && (*(char *)(param_2 + 0x2c) == '\0')) {
    iVar8 = 0;
    lVar7 = 0;
  }
  else {
    iVar8 = 0;
    for (uVar9 = 0; uVar6 = mpr::BaseList::GetNum(*(BaseList **)(param_1 + 0x1d58)), uVar9 < uVar6;
        uVar9 = uVar9 + 1) {
      mpr::BaseList::Get(*(BaseList **)(param_1 + 0x1d58),uVar9,&local_8,&local_c);
      iVar2 = *local_8;
      if (((iVar2 == 2) || (iVar2 == 3)) || (iVar2 == 4)) {
        iVar8 = iVar8 + local_8[4] + 4;
      }
      else if (iVar2 == 0) break;
    }
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x1d20) + (ulong)*param_3 * 0x40);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    uVar9 = *param_3;
    lVar5 = (ulong)uVar9 * 0x40;
    lVar7 = *(long *)(param_1 + 0x1d20) + lVar5;
    *(undefined1 *)(*(long *)(param_1 + 0x1d20) + lVar5) = 1;
    *(undefined1 *)(lVar7 + 2) = 1;
    bVar4 = *(byte *)(param_2 + 0x2a);
    *(byte *)(lVar7 + 1) = *(byte *)(lVar7 + 1) | 0xc;
    *(byte *)(lVar7 + 3) = *(byte *)(lVar7 + 3) & 0xfe | bVar4 & 1;
    uVar3 = *(undefined4 *)(param_2 + 0x10);
    *(undefined8 *)(lVar7 + 8) = 0;
    *(undefined4 *)(lVar7 + 0x18) = uVar3;
    *(undefined4 *)(lVar7 + 0x1c) = 0;
    uVar3 = *(undefined4 *)(param_2 + 0x14);
    *(int *)(lVar7 + 0x10) = iVar8;
    *(undefined4 *)(lVar7 + 0x20) = uVar3;
    *(undefined4 *)(lVar7 + 0x24) = 0;
    uVar9 = uVar9 + 1;
    *param_3 = uVar9;
    lVar7 = (ulong)(*(uint *)(param_1 + 0x1d28) < uVar9) << 1;
  }
  *param_4 = iVar8;
  return lVar7;
}

