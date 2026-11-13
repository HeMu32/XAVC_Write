// ELF VMA 0x36111b4; Ghidra bias 0x100000

void appfw_36111b4(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uStack_20;
  ulong auStack_18 [2];
  undefined4 uStack_8;
  
  uStack_20 = 0x8b9a1b8;
  func_0x0193b6d4();
  if (*param_1 == 2) {
    auStack_18[1] = 0;
    uStack_8 = 0;
    auStack_18[0] = (ulong)(uint)param_1[1];
    iVar3 = 0;
    func_0x01817290(1,auStack_18,0,0,1,0,0x8b9aed0);
    iVar1 = func_0x03704954();
    if (iVar1 == 0) {
      uVar2 = func_0x03709708(0x8b9aed0);
      func_0x038258d4(&UNK_04d1d94f,uVar2);
      uStack_8 = 0;
      auStack_18[1] = 0;
      auStack_18[0] = (ulong)(uint)param_1[2];
      func_0x01817290(1,auStack_18,0,0,1,0,0x8b9aef0);
      iVar3 = func_0x03704954();
      if (iVar3 == 0) {
        uVar2 = func_0x03709708(0x8b9aef0);
        func_0x038258d4(&UNK_04d1d982,uVar2);
      }
    }
    if (iVar3 != 0 || iVar1 != 0) {
      func_0x038258d4(&UNK_04d1d9b5,iVar1,iVar3);
      func_0x03709604(0x8b9aed0);
      func_0x03709604(0x8b9aef0);
      if (iVar1 != 0) {
        iVar3 = iVar1;
      }
      goto LAB_037111f4;
    }
  }
  iVar3 = 0;
LAB_037111f4:
  *param_2 = iVar3;
  func_0x0193b730(&uStack_20);
  return;
}

