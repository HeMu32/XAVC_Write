// sidb::ContentTypeInternal2ContentType
// Ghidra address: 0038ab6c

/* sidb::ContentTypeInternal2ContentType(sidb::ContentTypeInternal) */

undefined8 sidb::ContentTypeInternal2ContentType(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 != 1) {
    if ((uVar1 != 0) && (uVar1 < 4)) {
      return 4;
    }
    param_1 = 0;
  }
  return param_1;
}

