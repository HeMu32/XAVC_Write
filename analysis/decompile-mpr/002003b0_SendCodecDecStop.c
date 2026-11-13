// mpr::MoviePlayer::SendCodecDecStop
// Ghidra address: 002003b0

/* mpr::MoviePlayer::SendCodecDecStop() */

undefined8 mpr::MoviePlayer::SendCodecDecStop(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  
  local_e = 0x370;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2313;
  local_c = 4;
  FUN_001fe840(&local_10,8);
  if (*(int *)(PTR_s_pbStartParam_00401a40 + 0x70) == 0) {
    uVar1 = 0x14;
    if (*(int *)(PTR_s_pbStartParam_00401a40 + 0x74) != 1) {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 0xf;
    if (*(int *)(PTR_s_pbStartParam_00401a40 + 0x70) != 1) {
      local_c = 4;
      local_e = 0x371;
      local_b = 0;
      local_a = 0;
      local_9 = 0;
      local_10 = 0x2313;
      FUN_001fe840(&local_10,8);
      uVar1 = 5;
    }
  }
  local_8 = Codec::DecStop(0x20,uVar1,1,0);
  if (local_8 == 0) {
    local_b = 0;
    local_c = 4;
    local_a = 0;
    local_10 = 0x2313;
    local_9 = 0;
    local_e = 0x37f;
    FUN_001fe840(&local_10,8);
    uVar2 = 0;
  }
  else {
    local_b = 0;
    local_c = 3;
    local_a = 0;
    local_10 = 0x2313;
    local_9 = 0;
    local_e = 0x372;
    FUN_001fe840(&local_10,0xc);
    FUN_001fe0e8(*(undefined8 *)(PTR_s_pbStopParam_00402fd0 + 8),2);
    uVar2 = 2;
  }
  return uVar2;
}

