// Original ELF VMA 0x360d3c0; Ghidra bias 0x100000; readOnly project session

void producer_360d3c0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int aiStack_620 [392];
  
  producer_3609328(aiStack_620);
  iVar2 = func_0x01816bf0(*param_1,param_1[1],aiStack_620,1);
  if (iVar2 != 0) {
    func_0x038258d4(&UNK_04d1dee7,&UNK_04c989a0,&UNK_04d20888,0x3625,iVar2);
    return;
  }
  if (aiStack_620[0] == 1) {
    func_0x01817b90(*param_1,param_1[1],0x27,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x28,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x29,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x2a,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x2b,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x2c,0,0,1);
    uVar3 = 0x2d;
  }
  else {
    if (aiStack_620[0] != 4) {
      return;
    }
    func_0x01817b90(*param_1,param_1[1],0x2e,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x2f,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x30,0,0,1);
    func_0x01817b90(*param_1,param_1[1],0x31,0,0,1);
    cVar1 = func_0x02fe59b8(0x274);
    if ((cVar1 == '\0') && (cVar1 = func_0x02fe59b8(699), cVar1 == '\0')) {
      return;
    }
    func_0x01817b90(*param_1,param_1[1],0x32,0,0,1);
    uVar3 = 0x33;
  }
  func_0x01817b90(*param_1,param_1[1],uVar3,0,0,1);
  return;
}

