// Original ELF VMA 0x360d228; Ghidra bias 0x100000; readOnly project session

void appfw_360d228(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  
  uVar4 = 0x2b;
  uVar1 = param_1[2];
  if (uVar1 != 0x10) {
    if (uVar1 < 0x11) {
      uVar4 = 0x29;
      if ((uVar1 == 4) || (uVar4 = 0x2a, uVar1 == 8)) goto LAB_0370d274;
      bVar2 = uVar1 == 2;
      uVar4 = 0x28;
    }
    else {
      uVar4 = 0x2d;
      if (uVar1 == 0x40) goto LAB_0370d274;
      if (uVar1 < 0x41) {
        uVar4 = 0x2c;
        bVar2 = uVar1 == 0x20;
      }
      else {
        uVar4 = 0x2e;
        if (uVar1 == 0x80) goto LAB_0370d274;
        uVar4 = 0x2f;
        bVar2 = uVar1 == 0x100;
      }
    }
    if (!bVar2) {
      uVar4 = 0x27;
    }
  }
LAB_0370d274:
  uVar5 = 0;
  if ((ushort)(*(short *)(param_1 + 3) - 2U) < 7) {
    uVar5 = (&UNK_04d1d370)[(ushort)(*(short *)(param_1 + 3) - 2)];
  }
  func_0x01817b90(*param_1,param_1[1],uVar4,uVar5,1);
  uVar3 = appfw_3604954();
  *param_2 = uVar3;
  return;
}

