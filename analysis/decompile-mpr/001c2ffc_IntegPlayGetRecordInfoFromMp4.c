// mpr::IntegPlayGetRecordInfoFromMp4
// Ghidra address: 001c2ffc

/* mpr::IntegPlayGetRecordInfoFromMp4(std::__cxx11::string, libXavcMp4::MoviePropertyInfo&) */

int mpr::IntegPlayGetRecordInfoFromMp4(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_3b8 [8];
  long local_3b0;
  undefined2 local_3a8;
  undefined2 local_3a6;
  undefined1 local_3a4;
  undefined1 local_3a3;
  undefined1 local_3a2;
  undefined1 local_3a1;
  int local_3a0;
  undefined4 local_398 [2];
  undefined8 local_390;
  undefined1 auStack_388 [104];
  undefined2 local_320;
  undefined2 local_31e;
  undefined1 local_31c;
  undefined1 local_31b;
  undefined1 local_31a;
  undefined1 local_319;
  
  local_31c = 4;
  local_31e = 0x1f9;
  local_31b = 0;
  local_31a = 0;
  local_319 = 0;
  local_320 = 0x2160;
  FUN_001bf858(&local_320,8);
  FUN_0032a730(auStack_388);
  local_3b0 = 0;
  local_398[0] = 0x58415643;
  local_390 = 0xa00000;
  FUN_00322994(&local_320,local_398);
  FUN_0032a774(auStack_388,0x20000);
  iVar2 = FUN_0032af44(auStack_388,*param_1,1,&local_3b0);
  if (iVar2 == 0) {
    iVar2 = FUN_0032a380(&local_320,auStack_388,1,0,auStack_3b8);
    if (iVar2 == 0) {
      iVar2 = FUN_00328d4c(&local_320,param_2);
      if (iVar2 != 0) {
        local_3a3 = 0;
        local_3a4 = 3;
        local_3a2 = 0;
        local_3a6 = 0x1fc;
        local_3a1 = 0;
        local_3a8 = 0x2160;
        local_3a0 = iVar2;
        FUN_001bf858(&local_3a8,0xc);
      }
      FUN_00329434(&local_320);
      goto LAB_001c30dc;
    }
    local_3a6 = 0x1fb;
  }
  else {
    local_3a6 = 0x1fa;
  }
  local_3a1 = 0;
  local_3a2 = 0;
  local_3a3 = 0;
  local_3a4 = 3;
  local_3a8 = 0x2160;
  local_3a0 = iVar2;
  FUN_001bf858(&local_3a8,0xc);
LAB_001c30dc:
  if ((local_3b0 != 0) &&
     ((iVar3 = FUN_0032a8b0(auStack_388), iVar1 = iVar2, iVar2 != 0 || (iVar1 = iVar3, iVar3 != 0)))
     ) {
    iVar2 = iVar1;
    local_3a3 = 0;
    local_3a4 = 3;
    local_3a2 = 0;
    local_3a8 = 0x2160;
    local_3a1 = 0;
    local_3a6 = 0x1fd;
    local_3a0 = iVar2;
    FUN_001bf858(&local_3a8,0xc);
  }
  local_3a4 = 3;
  local_3a3 = 0;
  local_3a8 = 0x2313;
  local_3a2 = 0;
  local_3a6 = 0x1fe;
  local_3a1 = 0;
  local_3a0 = iVar2;
  FUN_001bf858(&local_3a8,0xc);
  thunk_FUN_00329434(&local_320);
  FUN_0032a6ac(auStack_388);
  return iVar2;
}

