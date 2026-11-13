// FUN_804f2580
// Ghidra address: 804f2580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_804f2580(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  DAT_802ec258 = FUN_804e6d8c(DAT_802ecba0);
  iVar1 = FUN_804f5f7c(DAT_802ec134);
  if ((iVar1 == 0) && (iVar1 = FUN_804f5f88(DAT_802ec134), iVar1 != 0)) {
    iVar1 = FUN_804f609c(DAT_802ec134);
    uVar2 = (uint)(iVar1 == 0);
  }
  s_NewState_802ec140._0_4_ = uVar2;
  iVar1 = FUN_804e6e18(DAT_802ecba0);
  if (iVar1 == 0) {
    s_NewState_802ec140._4_4_ = FUN_804e6eb8(DAT_802ecb94);
    register0x00000008 = FUN_804e6ec0(DAT_802ecb94);
  }
  else {
    s_NewState_802ec140[4] = '\0';
    s_NewState_802ec140[5] = '\0';
    s_NewState_802ec140[6] = '\0';
    s_NewState_802ec140[7] = '\0';
    register0x00000008 = FUN_804e6d94(DAT_802ecba0);
    register0x00000008 = register0x00000008 + -1;
  }
  DAT_802ec25c = (register0x00000008 - s_NewState_802ec140._4_4_) + 1;
  iVar1 = FUN_804e6f4c(DAT_802ecb94);
  s_SyntaxTop_802ec260._0_4_ = (iVar1 - s_NewState_802ec140._4_4_) + 1;
  s_avcdec_ctrl_cxx_802ec248._8_4_ = DAT_802ec258 * s_SyntaxTop_802ec260._0_4_;
  s_SyntaxTop_802ec260._4_4_ = DAT_802ec25c - s_SyntaxTop_802ec260._0_4_;
  s_avcdec_ctrl_cxx_802ec248._4_4_ = DAT_802ec258 * DAT_802ec25c;
  s_avcdec_ctrl_cxx_802ec248._12_4_ =
       s_avcdec_ctrl_cxx_802ec248._4_4_ - s_avcdec_ctrl_cxx_802ec248._8_4_;
  register0x00000008 = FUN_804e6e30(DAT_802ecba0);
  DAT_802ec130 = FUN_804f6040(DAT_802ec134);
  unique0x1000007f = DAT_802ec130;
  if (4 < DAT_802ec130) {
    unique0x10000083 = DAT_802ec130 - 5;
  }
  iVar1 = FUN_804f5f64(DAT_802ec134);
  PTR_LAB_802ecb98 = (undefined *)(iVar1 * 6);
  DAT_802ec1ec = iVar1 * -6;
  DAT_802ec1e8 = 0x33;
  iVar1 = FUN_804f5f64(DAT_802ec134);
  s__n_<_m_count)_802ec1f0[0] = -0x58;
  s__n_<_m_count)_802ec1f0[1] = '\x05';
  s__n_<_m_count)_802ec1f0[2] = '\0';
  s__n_<_m_count)_802ec1f0[3] = '\0';
  if (iVar1 != 2) {
    s__n_<_m_count)_802ec1f0[0] = 'j';
    s__n_<_m_count)_802ec1f0[1] = '\x01';
    s__n_<_m_count)_802ec1f0[2] = '\0';
    s__n_<_m_count)_802ec1f0[3] = '\0';
  }
  iVar1 = FUN_804f5f64(DAT_802ec134);
  s__n_<_m_count)_802ec1f0[4] = -0x7e;
  s__n_<_m_count)_802ec1f0[5] = 'Z';
  s__n_<_m_count)_802ec1f0[6] = '\0';
  s__n_<_m_count)_802ec1f0[7] = '\0';
  if (iVar1 != 2) {
    s__n_<_m_count)_802ec1f0[4] = -0x60;
    s__n_<_m_count)_802ec1f0[5] = '\x16';
    s__n_<_m_count)_802ec1f0[6] = '\0';
    s__n_<_m_count)_802ec1f0[7] = '\0';
  }
  s_thePoc_802ec27c._0_4_ = ZEXT14(DAT_802ec130 == 2 || DAT_802ec130 == 7);
  register0x0000000c = (uint)(DAT_802ec130 == 0 || DAT_802ec130 == 5);
  s_avcdec_syntax_h_802ec284._0_4_ = ZEXT14(DAT_802ec130 == 1 || DAT_802ec130 == 6);
  iVar1 = FUN_804f5f94(DAT_802ec134);
  if (iVar1 == 0) {
    DAT_802ec13c = FUN_804f5f58(DAT_802ec134);
  }
  else {
    DAT_802ec13c = 0;
  }
  return;
}

