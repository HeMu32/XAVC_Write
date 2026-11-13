// sidb::sidbhash::regist
// Ghidra address 0038a6a4; ELF VMA = Ghidra - 0x100000

/* sidb::sidbhash::regist(unsigned short, unsigned int) */

undefined8 __thiscall sidb::sidbhash::regist(sidbhash *this,ushort param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  void *pvVar4;
  uint *puVar5;
  int iVar6;
  ulong uVar7;
  
  if (0x3fc < param_1) {
    return 0x407;
  }
  lVar2 = (ulong)param_1 * 8;
  if (*(long *)(this + lVar2) == 0) {
    pvVar4 = malloc(0x100);
    *(void **)(this + lVar2) = pvVar4;
    puVar5 = memset(pvVar4,0xff,0x100);
    *puVar5 = param_2;
  }
  else {
    uVar7 = 0;
    do {
      pvVar4 = *(void **)(this + lVar2);
      bVar3 = *(int *)((long)pvVar4 + uVar7 * 4) == -1;
      if (bVar3) {
        *(uint *)((long)pvVar4 + uVar7 * 4) = param_2;
      }
      iVar6 = (int)uVar7;
      uVar1 = iVar6 + 1;
      uVar7 = (ulong)uVar1;
      if ((uVar1 & 0x3f) == 0) {
        pvVar4 = realloc(pvVar4,(ulong)(iVar6 + 0x41) << 2);
        *(void **)(this + lVar2) = pvVar4;
        memset((void *)((long)pvVar4 + uVar7 * 4),0xff,0x100);
      }
    } while (!bVar3);
  }
  return 0;
}

