// Ghidra: 00283924; ELF VMA = Ghidra - 0x100000

void FUN_00283924(long *param_1,int *param_2,char param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (((param_3 == '\0') || (*param_2 != 1)) ||
     (iVar4 = (**(code **)(*param_1 + 0x2c8))(param_1,param_2 + 2), iVar4 != 0)) {
    *(undefined4 *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x2c) = 2;
  }
  else {
    iVar4 = (**(code **)(*param_1 + 0x3e0))(param_1,param_2);
    if (iVar4 == 0) {
      if (param_2[0x94] == 1) {
        uVar2 = *(undefined8 *)(param_2 + 0x97);
        puVar1 = (undefined8 *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x36);
        *puVar1 = *(undefined8 *)(param_2 + 0x95);
        puVar1[1] = uVar2;
        uVar2 = *(undefined8 *)(param_2 + 0x9b);
        puVar1[2] = *(undefined8 *)(param_2 + 0x99);
        puVar1[3] = uVar2;
      }
      else {
        memset((void *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x36),0x30,0x20
              );
      }
      if (param_2[0x7e] == 1) {
        (**(code **)(*param_1 + 0x280))
                  (param_1,param_2 + 0x80,
                   (long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x58,
                   (long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x5c);
      }
      else {
        *(undefined4 *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x58) = 0xff;
      }
      if (param_2[0x52] == 1) {
        uVar3 = *(uint *)(param_1 + 0x15f8c);
        uVar5 = (**(code **)(*param_1 + 0x2b0))(param_1,param_2 + 0x54);
        *(undefined4 *)((long)param_1 + (ulong)uVar3 * 0x44 + 0x60) = uVar5;
      }
      else {
        *(undefined4 *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 0x60) = 8;
      }
      if (param_2[0x85] == 1) {
        *(int *)((long)param_1 + (ulong)*(uint *)(param_1 + 0x15f8c) * 0x44 + 100) = param_2[0x86];
      }
      if (5 < (uint)param_2[0x16e]) {
        *(undefined4 *)(param_1 + 5) = 2;
      }
    }
  }
  *(int *)(param_1 + 0x15f8c) = (int)param_1[0x15f8c] + 1;
  return;
}

