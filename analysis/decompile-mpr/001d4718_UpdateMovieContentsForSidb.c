// mpr::UpdateMovieContentsForSidb
// Ghidra address: 001d4718

/* mpr::UpdateMovieContentsForSidb(unsigned int, mpr::movie_stopCmp_t&) */

undefined8 mpr::UpdateMovieContentsForSidb(uint param_1,movie_stopCmp_t *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined2 local_650;
  undefined2 local_64e;
  undefined1 local_64c;
  undefined1 local_64b;
  undefined1 local_64a;
  undefined1 local_649;
  undefined4 local_648;
  int iStack_644;
  undefined8 local_640;
  undefined8 local_638;
  undefined8 local_630;
  undefined8 uStack_628;
  undefined4 local_620;
  undefined4 local_61c;
  undefined4 local_618;
  undefined8 local_614;
  undefined4 local_60c;
  undefined2 local_608;
  undefined2 local_606;
  undefined1 local_604;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5fa;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined4 local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 local_5e0;
  undefined2 local_5dc;
  undefined2 local_5da;
  undefined4 local_5d8;
  undefined4 local_5d4;
  undefined4 local_5d0;
  undefined4 local_5cc;
  undefined4 local_5c8;
  movie_stopCmp_t local_5c4;
  undefined4 local_5c0;
  undefined4 local_5bc;
  undefined4 local_5b8;
  undefined4 local_5b4;
  undefined4 local_5b0;
  undefined4 local_5ac;
  undefined4 local_5a8;
  undefined2 local_5a4;
  undefined2 local_5a2;
  undefined4 local_5a0;
  undefined4 local_59c;
  undefined4 local_598;
  undefined4 local_594;
  undefined4 local_590;
  movie_stopCmp_t local_58c;
  undefined4 local_588;
  undefined4 local_584;
  undefined4 local_580;
  undefined4 local_57c;
  movie_stopCmp_t local_578;
  undefined4 local_574;
  undefined4 local_570;
  undefined4 local_56c;
  undefined4 local_568;
  undefined1 local_560;
  char acStack_55f [262];
  undefined1 local_459;
  char acStack_458 [262];
  undefined1 local_352;
  char acStack_351 [262];
  movie_stopCmp_t local_24b;
  char acStack_24a [266];
  undefined8 local_140;
  undefined8 local_138;
  ulong local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_1c;
  undefined8 local_18;
  undefined2 local_10;
  int local_c;
  undefined1 local_8;
  
  uVar5 = 0xffffffff;
  local_620 = 0x8d02110;
  local_61c = 4;
  FUN_001c9f24((recordInfo *)&local_620,8);
  if (param_1 < 4) {
    uVar5 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  sidb::recordInfo::clear((recordInfo *)&local_620);
  sidb::recordInfo::clear((recordInfo *)&local_620);
  local_608 = 0;
  local_606 = 0;
  local_5fc = 0;
  local_620 = 4;
  local_61c = *(undefined4 *)(param_2 + 0x15ac);
  local_5fb = 0;
  local_618 = 0;
  local_614 = *(ulong *)(param_2 + 0x624);
  local_60c = *(uint *)(param_2 + 0x62c) & 0xffff;
  local_604 = 1;
  local_5fa = 1;
  local_5f8 = GetVideoCodec(*(undefined4 *)(param_2 + 0x1468));
  local_5f4 = GetGopStructure(*(undefined4 *)(param_2 + 0x1468));
  local_5f0 = GetVideoResolution(*(undefined4 *)(param_2 + 0x1468));
  local_5ec = GetVideoAspect(*(undefined4 *)(param_2 + 0x1468));
  local_5e8 = GetColorFormat(*(undefined4 *)(param_2 + 0x1468));
  local_5e4 = GetVideoBitDepth(*(undefined4 *)(param_2 + 0x1468));
  local_5e0 = *(undefined4 *)(param_2 + 0x1470);
  uVar1 = pconv::GetVideoBitrate(*(undefined4 *)(param_2 + 0x146c));
  local_5dc = (undefined2)(uVar1 / 1000);
  local_5da = *(undefined2 *)(param_2 + 0x147c);
  local_5d8 = *(undefined4 *)(param_2 + 0x14f4);
  local_5d4 = *(undefined4 *)(param_2 + 0x14f8);
  local_5d0 = *(undefined4 *)(param_2 + 0x1500);
  local_5cc = *(undefined4 *)(param_2 + 0x1508);
  local_5c8 = *(undefined4 *)(param_2 + 0x1510);
  local_58c = param_2[0x1595];
  local_588 = GetAudioCodec(*(undefined4 *)(param_2 + 0x1474));
  local_584 = GetAudioBitLength(*(undefined4 *)(param_2 + 0x1474));
  local_580 = GetAudioSamplingRate(*(undefined4 *)(param_2 + 0x1474));
  local_57c = *(undefined4 *)(param_2 + 0x1478);
  local_5c4 = param_2[0x1594];
  if (local_5c4 != (movie_stopCmp_t)0x0) {
    local_5c0 = GetVideoCodec(*(undefined4 *)(param_2 + 0x14dc));
    local_5bc = GetGopStructure(*(undefined4 *)(param_2 + 0x14dc));
    local_5b8 = GetVideoResolution(*(undefined4 *)(param_2 + 0x14dc));
    local_5b4 = GetVideoAspect(*(undefined4 *)(param_2 + 0x14dc));
    local_5b0 = GetColorFormat(*(undefined4 *)(param_2 + 0x14dc));
    local_5ac = GetVideoBitDepth(*(undefined4 *)(param_2 + 0x14dc));
    local_5a8 = *(undefined4 *)(param_2 + 0x14e0);
    uVar1 = pconv::GetVideoBitrate(*(undefined4 *)(param_2 + 0x14e4));
    local_5a4 = (undefined2)(uVar1 / 1000);
    local_5a2 = *(undefined2 *)(param_2 + 0x14f0);
    local_5a0 = *(undefined4 *)(param_2 + 0x1514);
    local_59c = *(undefined4 *)(param_2 + 0x1518);
    local_598 = *(undefined4 *)(param_2 + 0x1520);
    local_594 = *(undefined4 *)(param_2 + 0x1528);
    local_590 = *(undefined4 *)(param_2 + 0x1530);
    local_578 = param_2[0x1595];
    local_574 = GetAudioCodec(*(undefined4 *)(param_2 + 0x14e8));
    local_570 = GetAudioBitLength(*(undefined4 *)(param_2 + 0x14e8));
    local_56c = GetAudioSamplingRate(*(undefined4 *)(param_2 + 0x14e8));
    local_568 = *(undefined4 *)(param_2 + 0x14ec);
  }
  puVar3 = &local_640;
  local_560 = 1;
  strncpy(acStack_55f,(char *)param_2,0x105);
  local_640 = 0;
  local_638 = 0;
  local_630 = 0;
  uStack_628 = 0;
  iVar2 = Fsys_Stat(param_2,puVar3);
  if (iVar2 == 0) {
    local_459 = 1;
    local_140 = local_640;
    strncpy(acStack_458,(char *)(param_2 + 0x20c),0x105);
    local_352 = 1;
    strncpy(acStack_351,(char *)(param_2 + 0x312),0x105);
    local_138 = 0;
    local_24b = param_2[0x1594];
    if (local_24b != (movie_stopCmp_t)0x0) {
      strncpy(acStack_24a,(char *)(param_2 + 0x106),0x105);
      local_640 = 0;
      local_638 = 0;
      local_630 = 0;
      uStack_628 = 0;
      iVar2 = Fsys_Stat(param_2 + 0x106,puVar3);
      if (iVar2 != 0) {
        local_64e = 0x8db;
        goto LAB_001d49d4;
      }
      local_138 = local_640;
      local_c8 = *(undefined8 *)(param_2 + 0x1554);
      uStack_c0 = *(undefined8 *)(param_2 + 0x155c);
      local_b8 = *(undefined8 *)(param_2 + 0x1564);
      uStack_b0 = *(undefined8 *)(param_2 + 0x156c);
    }
    if (*(char *)(*(long *)(param_2 + 0x658) + 5) != '\0') {
      local_130 = (ulong)*(uint *)(*(long *)(param_2 + 0x658) + 0xc);
    }
    local_128 = *(undefined8 *)(param_2 + 0x1534);
    uStack_120 = *(undefined8 *)(param_2 + 0x153c);
    local_118 = *(undefined8 *)(param_2 + 0x1544);
    uStack_110 = *(undefined8 *)(param_2 + 0x154c);
    local_e8 = *(undefined8 *)(param_2 + 0x1574);
    uStack_e0 = *(undefined8 *)(param_2 + 0x157c);
    local_d8 = *(undefined8 *)(param_2 + 0x1584);
    uStack_d0 = *(undefined8 *)(param_2 + 0x158c);
    FUN_001c9e90(puVar3,param_2);
    iVar2 = FUN_002283d4(puVar3);
    std::__cxx11::string::_M_dispose();
    local_1c = 0;
    if (iVar2 != 2) {
      iVar2 = 1;
    }
    if (param_2[0x15b4] != (movie_stopCmp_t)0x0) {
      local_1c = *(undefined4 *)(param_2 + 0x15b8);
    }
    local_18 = *(undefined8 *)(param_2 + 0x15a0);
    local_10 = *(undefined2 *)(param_2 + 0x15a8);
    if ((param_2[0x147e] == (movie_stopCmp_t)0x0) || (param_2[0x1499] == (movie_stopCmp_t)0x0)) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
    local_c = iVar2;
    iVar2 = sidb::Update(0xffffffff,(recordInfo *)&local_620,true,false);
    if (iVar2 == 0) {
      uVar4 = 0;
      if (0x76c < local_614._2_2_) {
        uVar4 = ((ulong)((int)local_614._2_2_ - 0x76c) & 0xff) << 0x24;
      }
      sidb::SetHeaderParam<unsigned_long>
                (uVar5,3,(local_614 >> 0x20 & 0xf) << 0x20 | (local_614 >> 0x28 & 0x1f) << 0x1b |
                         (local_614 >> 0x30 & 0x1f) << 0x16 | (local_614 >> 0x38 & 0x3f) << 0x10 |
                         ((ulong)(byte)local_60c & 0x3f) << 10 | (ulong)local_60c._2_2_ & 0x3ff |
                         ((ulong)((int)(short)local_614 / 0x1e + 0x60) & 0xff) << 0x2c | uVar4);
      local_640 = 0x408df2110;
      FUN_001c9f24(puVar3,8);
      return 0;
    }
    local_638 = CONCAT44(iVar2,uVar5);
    local_640 = 0x208d32110;
  }
  else {
    local_64e = 0x8da;
LAB_001d49d4:
    local_649 = 0;
    local_64a = 0;
    local_64b = 0;
    local_64c = 2;
    local_650 = 0x2110;
    puVar3 = (undefined8 *)&local_650;
    local_648 = uVar5;
    iStack_644 = iVar2;
  }
  FUN_001c9f24(puVar3,0x10);
  return 2;
}

