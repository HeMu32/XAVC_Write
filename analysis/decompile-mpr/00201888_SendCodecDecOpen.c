// mpr::MoviePlayer::SendCodecDecOpen
// Ghidra address: 00201888

/* mpr::MoviePlayer::SendCodecDecOpen() */

undefined8 mpr::MoviePlayer::SendCodecDecOpen(void)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  int local_98;
  undefined2 local_90;
  undefined2 local_8e;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined4 local_88;
  undefined4 local_84;
  
  puVar2 = PTR_s_pbStartParam_00401a40;
  local_8c = 2;
  local_8e = 0x340;
  local_8b = 0;
  local_8a = 0;
  local_88 = *(undefined4 *)(PTR_s_pbStartParam_00401a40 + 0x70);
  local_89 = 0;
  local_84 = *(undefined4 *)(PTR_s_pbStartParam_00401a40 + 0x74);
  local_90 = 0x2313;
  FUN_001fe840((AvbbcApi_DecOpen *)&local_90,0x10);
  memset((AvbbcApi_DecOpen *)&local_90,0,0x90);
  iVar1 = *(int *)(puVar2 + 0x70);
  if (iVar1 == 0) {
    uVar4 = 0x14;
    if (*(int *)(puVar2 + 0x74) != 1) {
      uVar4 = 5;
    }
  }
  else {
    if (iVar1 != 1) {
      uVar3 = 8;
      local_9c = 4;
      local_9e = 0x341;
      goto LAB_00201994;
    }
    uVar4 = 0xf;
  }
  SetDecOpenParam((AvbbcApi_DecOpen *)&local_90);
  local_98 = Codec::DecOpen((AvbbcApi_DecOpen *)&local_90,0x20,uVar4,1,0);
  if (local_98 == 0) {
    local_9b = 0;
    local_9c = 4;
    local_9a = 0;
    local_a0 = 0x2313;
    local_99 = 0;
    local_9e = 0x34f;
    FUN_001fe840(&local_a0,8);
    return 0;
  }
  local_9c = 3;
  local_9e = 0x342;
  uVar3 = 0xc;
LAB_00201994:
  local_99 = 0;
  local_9a = 0;
  local_9b = 0;
  local_a0 = 0x2313;
  FUN_001fe840(&local_a0,uVar3);
  return 2;
}

