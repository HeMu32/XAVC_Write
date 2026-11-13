// mpr::MoviePlayer::ProcInPlayStartCmp
// Ghidra address: 00202188

/* mpr::MoviePlayer::ProcInPlayStartCmp(unsigned int, int, void*, unsigned int, void*) */

void mpr::MoviePlayer::ProcInPlayStartCmp
               (uint param_1,int param_2,void *param_3,uint param_4,void *param_5)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  
  local_c = 4;
  local_b = 0;
  local_e = 0x210;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2313;
  FUN_001fe840(&local_10,8,param_3,param_4);
  iVar1 = SendCodecDecStart();
  if (iVar1 != 0) {
    local_b = 0;
    local_c = 3;
    local_a = 0;
    local_e = 0x211;
    local_9 = 0;
    local_10 = 0x2313;
    local_8 = iVar1;
    FUN_001fe840(&local_10,0xc);
    FUN_001fe0e8(*(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x90),iVar1);
  }
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_10 = 0x2313;
  local_9 = 0;
  local_e = 0x21f;
  FUN_001fe840(&local_10,8);
  return;
}

