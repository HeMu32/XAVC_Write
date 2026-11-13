// FUN_0034bf44
// Ghidra address: 0034bf44

undefined4 FUN_0034bf44(undefined8 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  long lVar5;
  
  puVar1 = DAT_004bd450;
  puVar4 = DAT_004bd448;
  for (lVar5 = ((long)DAT_004bd450 - (long)DAT_004bd448 >> 3) * -0x3333333333333333 >> 2; 0 < lVar5;
      lVar5 = lVar5 + -1) {
    cVar2 = FUN_001ba894(puVar4 + 2,param_1);
    if (cVar2 != '\0') goto LAB_0034bfb8;
    cVar2 = FUN_001ba894(puVar4 + 0xc,param_1);
    if (cVar2 != '\0') {
      puVar4 = puVar4 + 10;
      goto LAB_0034bfb8;
    }
    cVar2 = FUN_001ba894(puVar4 + 0x16,param_1);
    if (cVar2 != '\0') {
      puVar4 = puVar4 + 0x14;
      goto LAB_0034bfb8;
    }
    cVar2 = FUN_001ba894(puVar4 + 0x20,param_1);
    if (cVar2 != '\0') {
      puVar4 = puVar4 + 0x1e;
      goto LAB_0034bfb8;
    }
    puVar4 = puVar4 + 0x28;
  }
  lVar5 = ((long)puVar1 - (long)puVar4 >> 3) * -0x3333333333333333;
  if (lVar5 == 2) {
LAB_0034c080:
    cVar2 = FUN_001ba894(puVar4 + 2,param_1);
    if (cVar2 != '\0') goto LAB_0034bfb8;
    puVar4 = puVar4 + 10;
  }
  else {
    if (lVar5 == 3) {
      cVar2 = FUN_001ba894(puVar4 + 2,param_1);
      if (cVar2 != '\0') goto LAB_0034bfb8;
      puVar4 = puVar4 + 10;
      goto LAB_0034c080;
    }
    if (lVar5 != 1) {
      return 0x9a;
    }
  }
  cVar2 = FUN_001ba894(puVar4 + 2,param_1);
  if (cVar2 == '\0') {
    return 0x9a;
  }
LAB_0034bfb8:
  uVar3 = 0x9a;
  if (puVar1 != puVar4) {
    uVar3 = *puVar4;
  }
  return uVar3;
}

