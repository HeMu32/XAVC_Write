// FUN_8015783c
// Ghidra address: 8015783c

undefined4 FUN_8015783c(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 & 0x3f) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_80006cec(s__size_t_____ud_body________0x40U_8018c4a4,s_avcdec_ctrl_h_802ec26c,0x94);
  }
  for (uVar2 = param_2; uVar2 < param_2 + 0x200; uVar2 = uVar2 + 0x40) {
    cacheOp(0x19,uVar2);
  }
  uVar3 = 0x801578a0;
  uVar1 = FUN_8011b4a0(*(undefined1 *)(*(int *)(param_1 + 0x566c) + 0x7a),
                       *(int *)(param_1 + 0x566c) + 0x7c,param_2,param_3);
  if ((param_3 & 0x3f) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_80006cec(s__size_t_____detect_sei________0x_8018c478,s_avcdec_ctrl_h_802ec26c,0x9a,uVar3);
  }
  uVar2 = param_3 + 0x40;
  for (; param_3 < uVar2; param_3 = param_3 + 0x40) {
    cacheOp(0x1a,param_3);
  }
  SYNC(0);
  return uVar1;
}

