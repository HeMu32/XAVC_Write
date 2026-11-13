// sidb::ConvVideoParamToStreamProfile
// Ghidra address: 0038d238

/* sidb::ConvVideoParamToStreamProfile(sidb::VideoParam&) */

undefined1 sidb::ConvVideoParamToStreamProfile(VideoParam *param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (*(int *)param_1 == 0) {
    uVar1 = *(uint *)(param_1 + 8);
    uVar3 = 0;
    if ((uVar1 & 0xfffffffd) != 5) {
      uVar3 = 4;
      if ((*(int *)(param_1 + 0x10) != 1) && (uVar3 = 2, uVar1 != 1)) {
        return (uVar1 != 0xff && uVar1 != 0) && *(int *)(param_1 + 0x10) == 0;
      }
    }
  }
  else if (*(int *)param_1 == 1) {
    iVar2 = *(int *)(param_1 + 8);
    uVar3 = 0;
    if (2 < iVar2 - 5U) {
      uVar3 = 6;
      if (*(int *)(param_1 + 0x10) != 1) {
        uVar3 = 0;
        if ((iVar2 != 0xff && iVar2 != 0) && *(int *)(param_1 + 0x10) == 0) {
          uVar3 = 5;
        }
        return uVar3;
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

