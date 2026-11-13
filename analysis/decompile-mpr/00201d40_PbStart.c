// mpr::MoviePlayer::PbStart
// Ghidra address: 00201d40

/* mpr::MoviePlayer::PbStart(mpr::MoviePlayer::PbStartInParam const&) */

undefined4 mpr::MoviePlayer::PbStart(PbStartInParam *param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  puVar2 = PTR_s_state_00402f48;
  local_b = 0;
  local_c = 3;
  local_a = 0;
  local_10 = 0x2313;
  local_9 = 0;
  local_e = 0x20;
  local_8 = *(undefined4 *)PTR_s_state_00402f48;
  FUN_001fe840(&local_10,0xc);
  DAT_00498210 = 0;
  DAT_00498214 = 0;
  SetPlayerCallbackFunc
            (*(_func_void_uint_int_void_ptr_uint_void_ptr **)(param_1 + 0x98),
             *(void **)(param_1 + 0xa0));
  uVar1 = *(uint *)puVar2;
  if (uVar1 < 9) {
    if ((1L << ((ulong)uVar1 & 0x3f) & 0x134U) != 0) {
      uVar3 = ProcInPlayPbStart(param_1);
      goto LAB_00201de4;
    }
    if (uVar1 == 0) {
      uVar3 = ProcInIdlePbStart(param_1);
      goto LAB_00201de4;
    }
  }
  local_b = 0;
  uVar3 = 2;
  local_c = 4;
  local_a = 0;
  local_10 = 0x2313;
  local_9 = 0;
  local_e = 0x21;
  FUN_001fe840(&local_10,8);
LAB_00201de4:
  local_c = 3;
  local_b = 0;
  local_10 = 0x2313;
  local_a = 0;
  local_e = 0x2f;
  local_9 = 0;
  local_8 = uVar3;
  FUN_001fe840(&local_10,0xc);
  return uVar3;
}

