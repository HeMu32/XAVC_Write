// sidb::CalcChecksum
// Ghidra address: 0038b45c

/* sidb::CalcChecksum(unsigned char const*, unsigned int) */

long sidb::CalcChecksum(uchar *param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  uchar uVar4;
  long local_8;
  
  local_8 = 0;
  if (param_2 == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = 0;
    for (uVar2 = 0; uVar2 < param_2 >> 3; uVar2 = (ulong)((int)uVar2 + 1)) {
      lVar1 = lVar1 + *(long *)(param_1 + uVar2 * 8);
    }
    if ((param_2 & 7) != 0) {
      lVar3 = 0;
      do {
        uVar4 = '\0';
        if ((uint)lVar3 < (param_2 & 7)) {
          uVar4 = param_1[((ulong)param_2 & 0xfffffffffffffff8) + lVar3];
        }
        *(uchar *)((long)&local_8 + lVar3) = uVar4;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 8);
      lVar1 = lVar1 + local_8;
    }
  }
  return lVar1;
}

