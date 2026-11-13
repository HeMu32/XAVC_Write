// mpr::MoviePlayer::SetDecOpenParam
// Ghidra address: 002016f0

/* mpr::MoviePlayer::SetDecOpenParam(AvbbcApi_DecOpen*) */

void mpr::MoviePlayer::SetDecOpenParam(AvbbcApi_DecOpen *param_1)

{
  undefined *puVar1;
  AvbbcApi_DecOpen AVar2;
  undefined8 uVar3;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  undefined4 local_4;
  
  local_e = 0x3f0;
  local_c = 4;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2313;
  FUN_001fe840(&local_10,8);
  puVar1 = PTR_s_buffer_00402480;
  *(undefined8 *)param_1 = *(undefined8 *)PTR_s_buffer_00402480;
  *(uint *)(param_1 + 8) = *(uint *)(puVar1 + 0x10) & 0xffffffe0;
  uVar3 = *(undefined8 *)(puVar1 + 0x80);
  *(undefined2 *)(param_1 + 0x48) = 0x1b3;
  *(undefined8 *)(param_1 + 0x20) = uVar3;
  *(undefined2 *)(param_1 + 0x28) = 0x5a;
  *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(puVar1 + 0x40);
  *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(puVar1 + 0x1c0);
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(puVar1 + 0x1e0);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar1 + 0x20);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(puVar1 + 0x30);
  uVar3 = *(undefined8 *)(puVar1 + 0xa0);
  param_1[0x71] = (AvbbcApi_DecOpen)0x0;
  *(undefined8 *)(param_1 + 0x30) = uVar3;
  *(undefined2 *)(param_1 + 0x38) = 0x80;
  *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(puVar1 + 0x60);
  *(undefined2 *)(param_1 + 0x58) = 0xf0;
  AVar2 = (AvbbcApi_DecOpen)0x26;
  if (*PTR_sb_pbStreaming_00402638 == '\0') {
    AVar2 = (AvbbcApi_DecOpen)0x0;
  }
  param_1[0x70] = AVar2;
  uVar3 = *(undefined8 *)(puVar1 + 0xc0);
  *(undefined2 *)(param_1 + 0x80) = 0x1b3;
  *(undefined8 *)(param_1 + 0x78) = uVar3;
  local_8 = *(uint *)(puVar1 + 0xd0);
  if (local_8 < 0x87f00) {
    local_b = 0;
    local_c = 2;
    local_a = 0;
    local_4 = 0x87f00;
    local_e = 0x3f1;
    local_9 = 0;
    local_10 = 0x2313;
    FUN_001fe840(&local_10,0x10);
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","moviePlayer.cpp",0x120e,
                  "void mpr::MoviePlayer::SetDecOpenParam(mpr::Codec::DecOpenParam*)");
  }
  local_c = 4;
  local_e = 0x3ff;
  local_10 = 0x2313;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  FUN_001fe840(&local_10,8);
  return;
}

