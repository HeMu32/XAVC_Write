// mpr::MoviePlayer::SendCodecDecStart
// Ghidra address: 00201fec

/* mpr::MoviePlayer::SendCodecDecStart() */

undefined8 mpr::MoviePlayer::SendCodecDecStart(void)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined2 local_58;
  undefined2 local_56;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  int local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  puVar2 = PTR_s_pbStartParam_00401a40;
  local_40 = *(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x70);
  local_48 = 0x203502313;
  FUN_001fe840((AvbbcApi_DecStart *)&local_48,0x10);
  local_8 = 0;
  iVar1 = *(int *)(puVar2 + 0x70);
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (iVar1 == 0) {
    uVar4 = 0x14;
    if (*(int *)(puVar2 + 0x74) != 1) {
      uVar4 = 5;
    }
  }
  else {
    uVar4 = 0xf;
    if (iVar1 != 1) {
      local_53 = 0;
      uVar4 = 5;
      local_54 = 4;
      local_52 = 0;
      local_56 = 0x351;
      local_51 = 0;
      local_58 = 0x2313;
      FUN_001fe840(&local_58,8);
    }
  }
  SetDecStartParam((AvbbcApi_DecStart *)&local_48);
  local_50 = Codec::DecStart((AvbbcApi_DecStart *)&local_48,0x20,uVar4,1,0);
  if (local_50 == 0) {
    local_53 = 0;
    local_54 = 4;
    local_52 = 0;
    local_58 = 0x2313;
    local_51 = 0;
    local_56 = 0x35f;
    FUN_001fe840(&local_58,8);
    uVar3 = 0;
  }
  else {
    local_53 = 0;
    local_54 = 3;
    local_52 = 0;
    local_58 = 0x2313;
    local_51 = 0;
    local_56 = 0x352;
    FUN_001fe840(&local_58,0xc);
    FUN_001fe0e8(*(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x90),2);
    uVar3 = 2;
  }
  return uVar3;
}

