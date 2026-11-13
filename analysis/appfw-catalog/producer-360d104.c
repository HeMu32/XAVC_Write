// Original ELF VMA 0x360d104; Ghidra bias 0x100000; readOnly project session

void producer_360d104(undefined4 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int aiStack_620 [392];
  
  uVar3 = 0;
  if ((ushort)(*(short *)(param_1 + 2) - 1U) < 5) {
    uVar3 = (&UNK_04d1d368)[(ushort)(*(short *)(param_1 + 2) - 1)];
  }
  producer_3609328(aiStack_620);
  iVar1 = func_0x01816bf0(*param_1,param_1[1],aiStack_620,1);
  if (iVar1 == 0) {
    if (aiStack_620[0] == 1) {
      func_0x01817b90(*param_1,param_1[1],0x1c,uVar3,0,1);
      func_0x01817b90(*param_1,param_1[1],0x1e,uVar3,0,1);
      uVar2 = 0x20;
    }
    else {
      if (aiStack_620[0] != 4) {
        return;
      }
      func_0x01817b90(*param_1,param_1[1],0x23,uVar3,0,1);
      uVar2 = 0x24;
    }
    func_0x01817b90(*param_1,param_1[1],uVar2,uVar3,0,1);
  }
  else {
    func_0x038258d4(&UNK_04d1dee7,&UNK_04c989a0,&UNK_04d204a0,0x359e,iVar1);
  }
  return;
}

