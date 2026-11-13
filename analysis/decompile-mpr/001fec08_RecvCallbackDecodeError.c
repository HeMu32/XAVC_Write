// mpr::MoviePlayer::RecvCallbackDecodeError
// Ghidra address: 001fec08

/* mpr::MoviePlayer::RecvCallbackDecodeError(PayloadCodec*) */

void mpr::MoviePlayer::RecvCallbackDecodeError(PayloadCodec *param_1)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  local_c = 3;
  local_10 = 0x2313;
  local_e = 0x160;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = *(undefined4 *)PTR_s_state_00402f48;
  FUN_001fe840(&local_10,0xc);
  FUN_001fe0e8(*(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x90),2);
  local_10 = 0x2313;
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_e = 0x16f;
  local_9 = 0;
  FUN_001fe840(&local_10,8);
  return;
}

