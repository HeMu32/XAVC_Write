// FUN_0028d500
// Ghidra address: 0028d500

int FUN_0028d500(long param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  
  iVar1 = FUN_00293b7c(*(undefined8 *)(param_1 + 0x38));
  if (iVar1 == 0) {
    pcVar2 = strstr(param_2,"</MediaProfile>");
    if ((pcVar2 == (char *)0x0) || ((long)(ulong)param_3 <= (long)(pcVar2 + (0xf - (long)param_2))))
    {
      iVar1 = 0x65;
    }
    else {
      pcVar2[0xf] = '\0';
      sVar3 = strlen(param_2);
      *(int *)(*(long *)(param_1 + 0x60) + 0xea80) = (int)sVar3;
    }
  }
  return iVar1;
}

