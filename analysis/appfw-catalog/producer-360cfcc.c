// Original ELF VMA 0x360cfcc; Ghidra bias 0x100000; readOnly project session

void appfw_360cfcc(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  
  uVar4 = 0x20;
  uVar1 = param_1[2];
  if (uVar1 != 0x10) {
    if (uVar1 < 0x11) {
      uVar4 = 0x1e;
      if ((uVar1 == 4) || (uVar4 = 0x1f, uVar1 == 8)) goto LAB_0370d018;
      bVar2 = uVar1 == 2;
      uVar4 = 0x1d;
    }
    else {
      uVar4 = 0x23;
      if ((uVar1 == 0x80) || (uVar4 = 0x24, uVar1 == 0x100)) goto LAB_0370d018;
      uVar4 = 0x21;
      bVar2 = uVar1 == 0x20;
    }
    if (!bVar2) {
      uVar4 = 0x1c;
    }
  }
LAB_0370d018:
  uVar5 = 0;
  if ((ushort)(*(short *)(param_1 + 3) - 1U) < 5) {
    uVar5 = (&UNK_04d1d368)[(ushort)(*(short *)(param_1 + 3) - 1)];
  }
  func_0x01817b90(*param_1,param_1[1],uVar4,uVar5,1);
  uVar3 = appfw_3604954();
  *param_2 = uVar3;
  return;
}

