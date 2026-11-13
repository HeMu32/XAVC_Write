// mpr::MoviePlayer::RecvCallbackStartCmp
// Ghidra address: 0020225c

/* mpr::MoviePlayer::RecvCallbackStartCmp(unsigned int, int, void*, unsigned int, void*) */

void mpr::MoviePlayer::RecvCallbackStartCmp
               (uint param_1,int param_2,void *param_3,uint param_4,void *param_5)

{
  undefined *puVar1;
  ulong uVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  puVar1 = PTR_s_state_00402f48;
  local_c = 3;
  local_e = 0x90;
  local_8 = *(undefined4 *)PTR_s_state_00402f48;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2313;
  FUN_001fe840(&local_10,0xc);
  thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
  if (*(uint *)puVar1 < 9) {
    uVar2 = 1L << ((ulong)*(uint *)puVar1 & 0x3f);
    if ((uVar2 & 0x1c1) == 0) {
      if ((uVar2 & 0x36) == 0) {
        if (((uint)uVar2 >> 3 & 1) != 0) {
          ProcInNextStartCmp(param_1,param_2,param_3,param_4,param_5);
        }
      }
      else {
        ProcInPlayStartCmp(param_1,param_2,param_3,param_4,param_5);
      }
    }
    else {
      local_b = 0;
      local_c = 4;
      local_a = 0;
      local_e = 0x91;
      local_9 = 0;
      local_10 = 0x2313;
      FUN_001fe840(&local_10,8);
    }
  }
  thread::normalLock::unlock((normalLock *)PTR_s_moviePlayLock_00402d68);
  local_b = 0;
  local_a = 0;
  local_c = 4;
  local_9 = 0;
  local_10 = 0x2313;
  local_e = 0x9f;
  FUN_001fe840(&local_10,8);
  return;
}

