// mpr::ParseNrtFile
// Ghidra address: 001abce0

/* mpr::ParseNrtFile(char const*, NrtMetaWrapper*) */

undefined4 mpr::ParseNrtFile(char *param_1,NrtMetaWrapper *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  void *__ptr;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_28 = 0;
  iVar2 = Fsys_Stat(param_1,&local_20);
  if ((iVar2 == 0) && (iVar2 = Fsys_Open(param_1,&local_28,1), uVar1 = local_20, iVar2 == 0)) {
    __ptr = malloc(CONCAT44(uStack_1c,local_20));
    uVar3 = 0xb;
    iVar2 = Fsys_Read(local_28,__ptr,uVar1);
    if (-1 < iVar2) {
      uVar3 = FUN_00353e8c(param_2,__ptr,local_20);
    }
    free(__ptr);
    iVar2 = Fsys_Close(local_28);
    if (iVar2 == 0) {
      return uVar3;
    }
  }
  return 0xb;
}

