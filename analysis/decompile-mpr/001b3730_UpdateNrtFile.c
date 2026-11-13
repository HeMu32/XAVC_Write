// mpr::UpdateNrtFile
// Ghidra address: 001b3730

/* mpr::UpdateNrtFile(char const*, bool, char const*, char const*, NrtMetaWrapper*) */

undefined4
mpr::UpdateNrtFile(char *param_1,bool param_2,char *param_3,char *param_4,NrtMetaWrapper *param_5)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 uVar4;
  int local_f8;
  undefined4 local_f4;
  long local_f0;
  long local_e8;
  long local_e0;
  int local_d8;
  undefined4 uStack_d4;
  undefined8 local_d0 [6];
  undefined1 auStack_a0 [80];
  undefined1 auStack_50 [80];
  
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  iVar1 = Fsys_Open(param_1,&local_f0,1);
  if (((((iVar1 != 0) || (iVar1 = Fsys_Lock(local_f0,6), iVar1 != 0)) ||
       (iVar1 = Fsys_Open(param_4,&local_e8,1), iVar1 != 0)) ||
      (iVar1 = Fsys_Lock(local_e8,6), iVar1 != 0)) ||
     ((param_2 &&
      ((iVar1 = Fsys_Open(param_3,&local_e0,1), iVar1 != 0 ||
       (iVar1 = Fsys_Lock(local_e0,6), iVar1 != 0)))))) {
    uVar4 = 0xb;
  }
  else {
    pvVar2 = operator_new__(0x200000);
    local_f8 = 0;
    pvVar3 = operator_new__(0x200000);
    local_f4 = 0;
    FUN_00341acc(auStack_a0);
    FUN_00341acc(auStack_50);
    iVar1 = FUN_0035353c(param_5,pvVar2,0x200000,&local_f8);
    if (iVar1 == 0) {
      uVar4 = 0;
      if (local_f8 != 0) {
        local_d0[0] = 0;
        Fsys_Open(param_4,&local_d8,2);
        Fsys_FTruncate(CONCAT44(uStack_d4,local_d8),0);
        Fsys_Seek(CONCAT44(uStack_d4,local_d8),0,0,local_d0);
        Fsys_Write(CONCAT44(uStack_d4,local_d8),pvVar2,local_f8);
        Fsys_Flush(CONCAT44(uStack_d4,local_d8));
        Fsys_Close(CONCAT44(uStack_d4,local_d8));
        FUN_003423e8(auStack_a0,param_1,pvVar2,local_f8,0);
      }
    }
    else {
      uVar4 = 2;
    }
    if (param_2) {
      FUN_00352de0((NrtMetaWrapper *)local_d0);
      ParseNrtFileFromMp4(param_3,(NrtMetaWrapper *)local_d0);
      local_d8 = 3;
      FUN_00354304(param_5);
      if (local_d8 == 3) {
        FUN_00354388();
      }
      else {
        FUN_003539f0((NrtMetaWrapper *)local_d0);
      }
      FUN_0035353c((NrtMetaWrapper *)local_d0,pvVar3,0x200000,&local_f4);
      FUN_003423e8(auStack_50,param_3,pvVar3,local_f4,1);
      FUN_00352bb4((NrtMetaWrapper *)local_d0);
    }
    FUN_00342580(auStack_a0);
    operator_delete__(pvVar2);
    operator_delete__(pvVar3);
    FUN_00341b6c(auStack_50);
    FUN_00341b6c(auStack_a0);
  }
  if (local_f0 != 0) {
    Fsys_Close();
    local_f0 = 0;
  }
  if (local_e8 != 0) {
    Fsys_Close();
    local_e8 = 0;
  }
  if (local_e0 != 0) {
    Fsys_Close();
  }
  return uVar4;
}

