// sidb::ConvVideoParamToVPC
// Ghidra address: 0038d710

/* sidb::ConvVideoParamToVPC(sidb::VideoParam&) */

char sidb::ConvVideoParamToVPC(VideoParam *param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  
  if (*(int *)param_1 == 0) {
    switch(*(undefined4 *)(param_1 + 8)) {
    case 1:
      if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x14) == 0)) {
        bVar2 = *(int *)(param_1 + 4) == 0;
        cVar3 = '\v';
LAB_0038d784:
        if (!bVar2) {
          cVar3 = '\x0e';
        }
        return cVar3;
      }
      break;
    case 2:
      if (*(int *)(param_1 + 0x10) == 0) {
        if (*(int *)(param_1 + 0x14) == 0) {
          cVar3 = '\x0e';
          if (*(int *)(param_1 + 4) == 0) {
            cVar3 = '\x01';
          }
          return cVar3;
        }
      }
      else if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 1)) {
        if (*(int *)(param_1 + 4) == 0) {
          return '\x03';
        }
        bVar2 = *(int *)(param_1 + 4) == 1;
        cVar3 = '\n';
        goto LAB_0038d784;
      }
      break;
    case 3:
      if (*(int *)(param_1 + 0x10) == 0) {
        if (*(int *)(param_1 + 0x14) == 0) {
          cVar3 = '\0';
          if (*(int *)(param_1 + 4) != 0) {
            cVar3 = '\x0e';
          }
          return cVar3;
        }
      }
      else if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 1)) {
        if (*(int *)(param_1 + 4) == 0) {
          return '\x02';
        }
        bVar2 = *(int *)(param_1 + 4) == 1;
        cVar3 = '\t';
        goto LAB_0038d784;
      }
      break;
    case 6:
      if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 1)) {
        bVar2 = *(int *)(param_1 + 4) == 1;
        cVar3 = '\f';
        goto LAB_0038d784;
      }
    }
  }
  else if (*(int *)param_1 == 1) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 3) {
      if (*(int *)(param_1 + 0x10) == 0) {
        if (*(int *)(param_1 + 0x14) == 1) {
          bVar2 = *(int *)(param_1 + 4) == 0;
          cVar3 = '\x05';
          goto LAB_0038d784;
        }
      }
      else if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 1)) {
        bVar2 = *(int *)(param_1 + 4) == 0;
        cVar3 = '\a';
        goto LAB_0038d784;
      }
    }
    else {
      if (iVar1 == 4) {
        if (*(int *)(param_1 + 0x10) == 0) {
          return '\x04';
        }
        return (*(int *)(param_1 + 0x10) != 1) + '\r';
      }
      if (iVar1 == 2) {
        if (*(int *)(param_1 + 0x10) == 0) {
          if (*(int *)(param_1 + 0x14) == 1) {
            bVar2 = *(int *)(param_1 + 4) == 0;
            cVar3 = '\x06';
            goto LAB_0038d784;
          }
        }
        else if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0x14) == 1)) {
          bVar2 = *(int *)(param_1 + 4) == 0;
          cVar3 = '\b';
          goto LAB_0038d784;
        }
      }
    }
  }
  return '\x0e';
}

