// ELF VMA 0x35a984c; Ghidra bias 0x100000

void appfw_35a984c(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  long lVar2;
  undefined4 uVar3;
  
  func_0x03828730(0x10,0x9b);
  appfw_361166c(param_1,param_2);
  lVar2 = func_0x038286f8(0x90288f8,&stack0xfffffffffffffff8);
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar3 = 3;
  }
  bVar1 = func_0x03826a7c();
  func_0x03824f4c(uVar3,&stack0xfffffffffffffff0,6);
  if (bVar1 != 0xff) {
    func_0x0193b6d4();
    lVar2 = ((ulong)CONCAT24(0x9b,CONCAT22(0x10,(ushort)bVar1)) & 0xff) * 2;
    *(undefined2 *)(lVar2 + 0x9028564) = 0xffff;
    *(undefined2 *)(lVar2 + 0x9028654) = 0xffff;
    func_0x0193b730(&stack0xfffffffffffffff8);
  }
  return;
}

