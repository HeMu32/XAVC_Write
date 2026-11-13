// Ghidra: 0028e0d0; ELF VMA = Ghidra - 0x100000

int FUN_0028e0d0(long param_1)

{
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  
  FUN_00291490(*(undefined8 *)(param_1 + 0x58));
  usleep(1);
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  *(undefined1 *)(puVar2 + 1) = 0;
  *puVar2 = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  memset(puVar2 + 8,0,0xea5c);
  usleep(1);
  lVar3 = *(long *)(param_1 + 0x60);
  *(undefined4 *)(lVar3 + 0xea7c) = 0;
  *(undefined4 *)(lVar3 + 0xea80) = 0;
  memset((void *)(lVar3 + 0xea84),0,0x26c);
  *(undefined1 *)(*(long *)(param_1 + 0x60) + 0xecf0) = 0;
  iVar1 = usleep(1);
  return iVar1;
}

