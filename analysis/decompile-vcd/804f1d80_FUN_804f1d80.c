// FUN_804f1d80
// Ghidra address: 804f1d80

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_804f1d80(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  ram0x802ec1e0 = 0;
  DAT_802ec1e4 = 0;
  iVar1 = FUN_804e7548(DAT_802ecba0);
  s__n_<_m_count)_802ec1f0._8_4_ = ZEXT14(iVar1 == 0 && s_avcdec_syntax_h_802ec284._0_4_ == 0);
  iVar1 = FUN_804e74f8(DAT_802ecba0);
  ram0x802ec1fc = 0;
  s_isInit___802ec200[0] = '\0';
  s_isInit___802ec200[1] = '\0';
  s_isInit___802ec200[2] = '\0';
  s_isInit___802ec200[3] = '\0';
  s_isInit___802ec200._4_4_ = iVar1 + 1;
  s__isMember_id___802ec20c._8_4_ = FUN_804e7500(DAT_802ecba0);
  uVar7 = 6;
  if (((((4 < (uint)s__isMember_id___802ec20c._8_4_) &&
        (0x10 < (uint)s__isMember_id___802ec20c._8_4_)) &&
       (0xe70 < (uint)s__isMember_id___802ec20c._8_4_)) &&
      ((((0x20074 < (uint)s__isMember_id___802ec20c._8_4_ &&
         (uVar7 = 6, 0x6b82c < (uint)s__isMember_id___802ec20c._8_4_)) &&
        ((0xe3417 < (uint)s__isMember_id___802ec20c._8_4_ &&
         ((0x1876be < (uint)s__isMember_id___802ec20c._8_4_ &&
          (uVar7 = 7, 0x257f19 < (uint)s__isMember_id___802ec20c._8_4_)))))) &&
       (uVar7 = 8, 0x354a3d < (uint)s__isMember_id___802ec20c._8_4_)))) &&
     (((uVar7 = 9, 0x47dd88 < (uint)s__isMember_id___802ec20c._8_4_ &&
       (uVar7 = 10, 0x5d32a9 < (uint)s__isMember_id___802ec20c._8_4_)) &&
      (uVar7 = 0xb, 0x7550e3 < (uint)s__isMember_id___802ec20c._8_4_)))) {
    uVar7 = 0xc;
  }
  uVar2 = FUN_804e7510(DAT_802ecba0);
  if (uVar2 <= uVar7) {
    uVar7 = FUN_804e7510(DAT_802ecba0);
  }
  register0x00000008 = *(int *)(&DAT_8052eb48 + uVar7 * 4);
  s__isMember_id___802ec20c._0_4_ = s_isInit___802ec200._4_4_ << 6;
  s__isMember_id___802ec20c._4_4_ = s_isInit___802ec200._4_4_ * register0x00000008;
  iVar1 = FUN_804f5f64(DAT_802ec134);
  s_avcdec_syntax_h_802ec284[8] = '\x04';
  s_avcdec_syntax_h_802ec284[9] = '\0';
  s_avcdec_syntax_h_802ec284[10] = '\0';
  s_avcdec_syntax_h_802ec284[0xb] = '\0';
  if (iVar1 != 0) {
    s_avcdec_syntax_h_802ec284[8] = '\x06';
    s_avcdec_syntax_h_802ec284[9] = '\0';
    s_avcdec_syntax_h_802ec284[10] = '\0';
    s_avcdec_syntax_h_802ec284[0xb] = '\0';
  }
  iVar1 = FUN_804e7688(DAT_802ecba0);
  s_ms_____0__802eb4f0._0_4_ = *(undefined4 *)(s__isMember_id___802eb4e0 + iVar1 * 4 + 8);
  s_ms_____0__802eb4f0[4] = FUN_804e7664(DAT_802ecba0);
  s_ms_____0__802eb4f0[5] = FUN_804e7670(DAT_802ecba0);
  register0x00000008 = FUN_804e76a0(DAT_802ecba0);
  DAT_802eb4fc = FUN_804e76a8(DAT_802ecba0);
  DAT_802eb500 = FUN_804e76b8(DAT_802ecba0);
  DAT_802eb504 = FUN_804e76c0(DAT_802ecba0);
  DAT_802eb508 = FUN_804e76c8(DAT_802ecba0);
  DAT_802ec244 = FUN_804e7654(DAT_802ecba0);
  s_avcdec_ctrl_cxx_802ec248._0_4_ = FUN_804e765c(DAT_802ecba0);
  DAT_802ec12c = FUN_804e75f4(DAT_802ecba0);
  if (s_thePoc_802ec27c._0_4_ == 0) {
    register0x00000008 = FUN_804e74b8(DAT_802ecba0);
    uVar7 = register0x00000008 >> 1;
    if (uVar7 < 0x16b) {
      uVar7 = (byte)(&DAT_8052dc94)[uVar7] - 0x18;
    }
    else if (uVar7 < 0x16a1) {
      uVar7 = (uint)(byte)(&DAT_8052dc94)[register0x00000008 >> 5];
    }
    else {
      uVar7 = (byte)(&DAT_8052dc94)[register0x00000008 >> 9] + 0x18;
    }
    DAT_802eb510 = uVar7 + 0xc;
  }
  else {
    DAT_802eb510 = 0;
  }
  uVar3 = FUN_804f5ec8(DAT_802ec134);
  iVar1 = FUN_804f5ed0(uVar3);
  if (iVar1 == 0) {
    iVar1 = FUN_804f5fc0(DAT_802ec134);
    DAT_802eb514 = &DAT_8052eaf0;
    if (iVar1 != 0) {
      DAT_802eb514 = &DAT_8052eab8;
    }
  }
  else {
    DAT_802eb514 = &DAT_8052ea80;
  }
  uVar7 = 0;
  do {
    uVar2 = uVar7 + 1;
    *(undefined1 *)(uVar7 + 0x80534600) = (&DAT_8052e908)[uVar7];
    uVar7 = uVar2;
  } while (uVar2 < 0x41);
  puVar5 = &DAT_80534641;
  uVar7 = 0;
  do {
    puVar6 = &DAT_8052dc94 + uVar7;
    uVar7 = uVar7 + 1;
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
  } while (uVar7 < 0x16b);
  uVar7 = 0;
  do {
    iVar1 = uVar7 * 4;
    puVar4 = &DAT_8052e94c + uVar7;
    uVar7 = uVar7 + 1;
    *(undefined4 *)(iVar1 + -0x7facb854) = *puVar4;
  } while (uVar7 < 0x34);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

