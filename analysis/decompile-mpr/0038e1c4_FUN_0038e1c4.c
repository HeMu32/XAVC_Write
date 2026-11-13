// FUN_0038e1c4
// Ghidra address: 0038e1c4

int FUN_0038e1c4(fileStructure *param_1,char param_2,uint param_3,ushort param_4,ushort param_5,
                char *param_6)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  undefined2 local_20;
  char local_1e;
  undefined4 local_10 [4];
  
  iVar1 = sidb::RestorateFilePath(param_1,param_2,param_3,param_6,0x106);
  if (iVar1 == 0) {
    sVar2 = strnlen(param_6,0x106);
    snprintf((char *)&local_20,0x10,"%03d",(ulong)param_4);
    snprintf((char *)local_10,0x10,"%04d",(ulong)param_5);
    lVar3 = (long)(int)sVar2;
    *(undefined2 *)(param_6 + lVar3 + -0x15) = local_20;
    param_6[lVar3 + -0x13] = local_1e;
    *(undefined4 *)(param_6 + lVar3 + -8) = local_10[0];
  }
  return iVar1;
}

