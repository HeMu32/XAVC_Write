// sidb::IncrementArrayBinaryRecordRefCount
// Ghidra address 00391c28; ELF VMA = Ghidra - 0x100000

/* sidb::IncrementArrayBinaryRecordRefCount(unsigned int, sidb::fileStructure*, unsigned int) */

void sidb::IncrementArrayBinaryRecordRefCount(uint param_1,fileStructure *param_2,uint param_3)

{
  fileStructure *pfVar1;
  uint uVar2;
  ulong uVar3;
  
  pfVar1 = param_2 + (ulong)(param_3 * *(int *)(param_2 + 0x30)) + 0x10000;
  *(int *)(pfVar1 + 8) = *(int *)(pfVar1 + 8) + 1;
  uVar2 = *(uint *)(param_2 + 0x34);
  uVar3 = CalcChecksum((uchar *)pfVar1,uVar2);
  *(short *)(pfVar1 + uVar2) = (short)uVar3 + (short)(uVar3 / 0xfff1) * 0xf;
  SetFlushArea(param_1,param_3);
  return;
}

