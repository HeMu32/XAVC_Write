// mpr::GetRecordInfoFromMp4
// Ghidra address 001de3d8; ELF VMA = Ghidra - 0x100000

/* mpr::GetRecordInfoFromMp4(char const*, libXavcMp4::MoviePropertyInfo&) */

int mpr::GetRecordInfoFromMp4(char *param_1,MoviePropertyInfo *param_2)

{
  int iVar1;
  int iVar2;
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
  local_320 = 0x2110;
  local_31b = 0;
  local_31e = 0x140;
  local_31a = 0;
  local_319 = 0;
  FUN_001c9f24(&local_320,8);
  FUN_0032a730(auStack_388);
  local_3b0 = 0;
  local_398[0] = 0x58415643;
  local_390 = 0xa00000;
  FUN_00322994(&local_320,local_398);
  FUN_0032a774(auStack_388,0x20000);
  iVar1 = FUN_0032af44(auStack_388,param_1,1,&local_3b0);
  if ((iVar1 == 0) && (iVar1 = FUN_0032a380(&local_320,auStack_388,1,0,auStack_3b8), iVar1 == 0)) {
    iVar1 = FUN_00328fa8(&local_320,param_2);
    FUN_00329434(&local_320);
  }
  if ((local_3b0 != 0) && (iVar2 = FUN_0032a8b0(auStack_388), iVar1 == 0)) {
    iVar1 = iVar2;
  }
  local_3a4 = 3;
  local_3a3 = 0;
  local_3a8 = 0x2110;
  local_3a2 = 0;
  local_3a6 = 0x14f;
  local_3a1 = 0;
  local_3a0 = iVar1;
  FUN_001c9f24(&local_3a8,0xc);
  thunk_FUN_00329434(&local_320);
  FUN_0032a6ac(auStack_388);
  return iVar1;
}

