// FUN_00349a20
// Ghidra address: 00349a20

undefined8 FUN_00349a20(long *param_1,char *param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(param_1 + 1);
  uVar4 = 0;
  do {
    if (uVar1 <= uVar4 || 1 < uVar4) {
      return 0;
    }
    cVar2 = *(char *)(*param_1 + (ulong)uVar4);
    bVar3 = cVar2 - 0x30;
    if (9 < bVar3) {
      if ((byte)(cVar2 + 0xbfU) < 6) {
        bVar3 = cVar2 - 0x37;
      }
      else {
        if (5 < (byte)(cVar2 + 0x9fU)) {
          return 2;
        }
        bVar3 = cVar2 + 0xa9;
      }
    }
    uVar4 = uVar4 + 1;
    *param_2 = bVar3 + *param_2 * '\x10';
  } while( true );
}

