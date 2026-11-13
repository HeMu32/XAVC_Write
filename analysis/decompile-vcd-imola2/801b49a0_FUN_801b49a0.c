// FUN_801b49a0
// Ghidra address: 801b49a0

undefined4 FUN_801b49a0(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 & 0x3f) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(s__size_t_____ud_body________0x40U_8021174c,
                 s_______________________________sr_802116c8,0xaa);
  }
  for (uVar2 = param_2; uVar2 < param_2 + 0x240; uVar2 = uVar2 + 0x40) {
    cacheOp(0x19,uVar2);
  }
  uVar3 = 0x801b4a04;
  uVar1 = FUN_8005a170(*(undefined1 *)(*(int *)(param_1 + 0x65f4) + 0x7a),
                       *(int *)(param_1 + 0x65f4) + 0x7c,param_2,param_3);
  if ((param_3 & 0x3f) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_8000ae50(s__size_t_____detect_sei________0x_80211720,
                 s_______________________________sr_802116c8,0xb0,uVar3);
  }
  uVar2 = param_3 + 0x40;
  for (; param_3 < uVar2; param_3 = param_3 + 0x40) {
    cacheOp(0x1a,param_3);
  }
  SYNC(0);
  return uVar1;
}

