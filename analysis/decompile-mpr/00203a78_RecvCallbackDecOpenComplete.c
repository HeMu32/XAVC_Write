// mpr::MoviePlayer::RecvCallbackDecOpenComplete
// Ghidra address: 00203a78

/* mpr::MoviePlayer::RecvCallbackDecOpenComplete(PayloadCodec*) */

void mpr::MoviePlayer::RecvCallbackDecOpenComplete(PayloadCodec *param_1)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  
  local_e = 0xd0;
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2313;
  FUN_001fe840(&local_10,8);
  thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
  if (*(int *)PTR_s_state_00402f48 == 1) {
    iVar1 = SendMovieReaderStart(0);
    if (iVar1 != 0) {
      local_b = 0;
      local_c = 3;
      local_a = 0;
      local_e = 0xd1;
      local_9 = 0;
      local_10 = 0x2313;
      local_8 = iVar1;
      FUN_001fe840(&local_10,0xc);
      FUN_001fe0e8(*(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x90),iVar1);
    }
  }
  else {
    local_c = 4;
    local_e = 0xd2;
    local_b = 0;
    local_a = 0;
    local_9 = 0;
    local_10 = 0x2313;
    FUN_001fe840(&local_10,8);
  }
  thread::normalLock::unlock((normalLock *)PTR_s_moviePlayLock_00402d68);
  local_b = 0;
  local_a = 0;
  local_c = 4;
  local_9 = 0;
  local_10 = 0x2313;
  local_e = 0xdf;
  FUN_001fe840(&local_10,8);
  return;
}

