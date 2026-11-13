// FUN_0032af44
// Ghidra address: 0032af44

undefined8 FUN_0032af44(long param_1,undefined1 *param_2,uint param_3,undefined8 *param_4)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  uVar2 = Fsys_Open(param_2,param_1 + 0x10);
  if ((int)uVar2 == 0) {
    if ((param_3 & 1) == 0) {
      if ((param_3 >> 1 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x58) = 0;
        *(undefined8 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0;
      }
LAB_0032b030:
      *(uint *)(param_1 + 0x18) = param_3;
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined1 *)(param_1 + 8) = *param_2;
      *param_4 = *(undefined8 *)(param_1 + 0x10);
      return 0;
    }
    lVar3 = FUN_0032aeb8(param_1);
    *(long *)(param_1 + 0x20) = lVar3;
    if (lVar3 == 0) {
      Fsys_Close(*(undefined8 *)(param_1 + 0x10));
      *(undefined8 *)(param_1 + 0x10) = 0;
      uVar4 = 0xda;
      uVar2 = 2;
    }
    else {
      uVar1 = Fsys_Read(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x38),
                        *(undefined4 *)(param_1 + 0x30));
      uVar2 = (ulong)uVar1;
      if (-1 < (int)uVar1) {
        *(uint *)(param_1 + 0x50) = uVar1;
        *(long *)(param_1 + 0x28) = (long)(int)uVar1;
        goto LAB_0032b030;
      }
      Fsys_Close(*(undefined8 *)(param_1 + 0x10));
      *(undefined8 *)(param_1 + 0x10) = 0;
      uVar4 = 0xe3;
    }
  }
  else {
    uVar4 = 0xd0;
  }
  uVar4 = FUN_0032a6f4(uVar2,&DAT_003dba68,uVar4);
  return uVar4;
}

