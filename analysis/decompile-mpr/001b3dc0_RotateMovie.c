// mpr::RotateMovie
// Ghidra address: 001b3dc0

/* mpr::RotateMovie(unsigned int, unsigned int, int, sidb::recordInfo&) */

int mpr::RotateMovie(uint param_1,uint param_2,int param_3,recordInfo *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined8 local_438;
  undefined8 local_430;
  undefined8 uStack_428;
  undefined4 local_420 [2];
  undefined8 local_418;
  undefined8 local_410;
  undefined8 uStack_408;
  undefined8 local_400;
  char *local_3f8;
  char *local_3f0;
  undefined8 local_3e8;
  undefined1 auStack_3e0 [30];
  byte local_3c2;
  undefined4 local_3c0 [2];
  undefined8 local_3b8;
  undefined4 local_3b0;
  undefined8 local_3ac;
  undefined8 uStack_3a4;
  undefined8 local_39c;
  undefined8 uStack_394;
  undefined4 local_38c;
  undefined1 auStack_388 [104];
  libXavcMp4 local_320 [8];
  undefined1 auStack_318 [792];
  
  local_410 = 0;
  uStack_408 = 0;
  iVar4 = 0xb;
  local_400 = 0;
  iVar2 = LockEditTargetFiles(param_4,(vector *)&local_410);
  if (iVar2 == 0) {
    local_320[0] = *(libXavcMp4 *)(param_4 + 0xc0);
    local_3f8 = (char *)0x0;
    local_3f0 = (char *)0x0;
    local_3e8 = 0;
    FUN_001aa364(auStack_318,param_4 + 0xc1);
    FUN_001b0fa4(&local_3f8,local_320);
    std::__cxx11::string::_M_dispose();
    local_320[0] = *(libXavcMp4 *)(param_4 + 0x3d5);
    FUN_001aa364(auStack_318,param_4 + 0x3d6);
    FUN_001b0fa4(&local_3f8,local_320);
    std::__cxx11::string::_M_dispose();
    for (pcVar5 = local_3f8; pcVar5 != local_3f0; pcVar5 = pcVar5 + 0x28) {
      if (*pcVar5 != '\0') {
        uVar3 = 0;
        if ((((param_3 != 0) && (uVar3 = 1, param_3 != 0x5a)) && (uVar3 = 2, param_3 != 0xb4)) &&
           (uVar3 = 3, param_3 != 0x10e)) {
          uVar3 = 0xff;
        }
        FUN_0032a730(auStack_388);
        local_420[0] = 0x58415643;
        local_418 = 0xa00000;
        FUN_00322994(local_320,local_420);
        local_38c = 0;
        local_3ac = 0;
        uStack_3a4 = 0;
        local_39c = 0;
        uStack_394 = 0;
        local_430 = 0;
        uStack_428 = 0;
        local_3c0[0] = 0;
        local_3b8 = 0;
        local_3b0 = 0;
        iVar4 = Fsys_Stat(*(undefined8 *)(pcVar5 + 8),auStack_3e0);
        puVar1 = PTR_DAT_00402c30;
        if (iVar4 == -0x7fffffaf) {
          iVar4 = 4;
        }
        else if (iVar4 == 0) {
          if ((local_3c2 & 1) != 0) {
            thread::normalLock::lock((normalLock *)PTR_DAT_00402c30);
            iVar4 = Fsys_Chmod(*(undefined8 *)(pcVar5 + 8),local_3c2 & 0xfe);
            thread::normalLock::unlock((normalLock *)puVar1);
            if (iVar4 != 0) goto LAB_001b3f3c;
          }
          iVar4 = 2;
          FUN_0032a774(auStack_388,0x20000);
          iVar2 = FUN_0032af44(auStack_388,*(undefined8 *)(pcVar5 + 8),3,&local_438);
          if (iVar2 == 0) {
            iVar2 = FUN_0032a380(local_320,auStack_388,1,0,&local_430);
            if (iVar2 == 0) {
              iVar4 = libXavcMp4::Rotate(local_320,uVar3,local_3c0);
              if (iVar4 == 0) {
                Fsys_Seek(local_438,local_3b8,0,&uStack_428);
                Fsys_Write(local_438,&local_3ac,local_3b0);
                iVar4 = 0;
              }
              else {
                iVar4 = 2;
              }
              FUN_00329434(local_320);
            }
            FUN_0032a8b0(auStack_388);
          }
          puVar1 = PTR_DAT_00402c30;
          if ((local_3c2 & 1) != 0) {
            thread::normalLock::lock((normalLock *)PTR_DAT_00402c30);
            iVar2 = Fsys_Chmod(*(undefined8 *)(pcVar5 + 8),local_3c2);
            thread::normalLock::unlock((normalLock *)puVar1);
            if (iVar2 != 0) goto LAB_001b3f3c;
          }
          if (iVar4 == 0) {
            thunk_FUN_00329434(local_320);
            FUN_0032a6ac(auStack_388);
            goto LAB_001b4040;
          }
        }
        else {
LAB_001b3f3c:
          iVar4 = 0xb;
        }
        thunk_FUN_00329434(local_320);
        FUN_0032a6ac(auStack_388);
        goto LAB_001b3f50;
      }
LAB_001b4040:
    }
    iVar4 = RotateStill(param_1,param_2,param_3,param_4,true);
    sidb::PartialUpdate<int>(0xffffffff,param_2,0x19,0,0,0);
    sidb::NotifyChangeEvent(param_1,param_2,3,4,1);
LAB_001b3f50:
    UnlockEditTargetFiles((vector *)&local_410);
    FUN_001aca2c(&local_3f8);
  }
  FUN_001adca0((vector *)&local_410);
  return iVar4;
}

