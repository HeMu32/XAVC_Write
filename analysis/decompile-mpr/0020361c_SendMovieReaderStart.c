// mpr::MoviePlayer::SendMovieReaderStart
// Ghidra address: 0020361c

/* mpr::MoviePlayer::SendMovieReaderStart(signed char) */

int mpr::MoviePlayer::SendMovieReaderStart(char param_1)

{
  undefined *puVar1;
  undefined1 uVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined2 local_818;
  undefined2 local_816;
  undefined1 local_814;
  undefined1 local_813;
  undefined1 local_812;
  undefined1 local_811;
  int local_810;
  undefined4 uStack_80c;
  char *local_808;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined8 local_7f8;
  char *local_7e8;
  undefined4 local_7e0;
  undefined4 uStack_7dc;
  undefined8 local_7d8;
  undefined *local_7c8;
  undefined8 uStack_7c0;
  undefined4 local_7b8;
  undefined4 local_7b4;
  undefined4 local_7b0;
  undefined4 local_7ac;
  undefined8 local_7a8;
  undefined4 local_7a0;
  undefined8 local_798;
  undefined1 *local_790;
  undefined8 uStack_788;
  undefined1 local_780 [16];
  undefined1 local_770;
  undefined1 *local_768;
  undefined8 local_760;
  undefined1 local_758 [16];
  undefined1 *local_748;
  undefined8 local_740;
  undefined1 local_738 [16];
  undefined4 local_728;
  undefined4 local_724;
  undefined8 local_720;
  undefined4 local_718;
  undefined4 local_714;
  undefined4 local_710;
  undefined1 local_70c;
  undefined1 local_70b;
  undefined1 local_70a;
  undefined1 local_709;
  undefined8 local_708;
  undefined4 local_700;
  undefined8 local_6f8;
  undefined8 local_6f0;
  undefined4 local_6e8;
  undefined8 local_6e0;
  undefined8 local_6d8;
  undefined1 local_6d0;
  undefined4 local_6cc;
  char acStack_6c8 [262];
  undefined1 local_5c2;
  char acStack_5c1 [262];
  char acStack_4bb [263];
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined8 local_3a8;
  undefined4 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined1 local_394;
  undefined1 local_393;
  undefined1 local_392;
  undefined1 local_391;
  undefined8 local_390;
  undefined4 local_388;
  undefined1 local_384;
  undefined2 local_380;
  undefined2 uStack_37e;
  undefined1 uStack_37c;
  undefined1 uStack_37b;
  undefined1 uStack_37a;
  undefined1 uStack_379;
  int local_378;
  undefined4 local_374;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 local_8;
  
  uStack_37c = 4;
  uStack_37e = 800;
  uStack_37b = 0;
  uStack_37a = 0;
  uStack_379 = 0;
  local_380 = 0x2313;
  FUN_001fe840((string *)&local_380,8);
  local_7b4 = 0xf0;
  local_798 = *(undefined8 *)(PTR_s_buffer_00402480 + 0x118);
  local_7a0 = *(undefined4 *)(PTR_s_buffer_00402480 + 0x110);
  local_7a8 = *(undefined8 *)(PTR_s_buffer_00402480 + 0x100);
  local_7c8 = PTR_CallbackPointForMovieReader_004012a8;
  uStack_7c0 = 0;
  local_7b8 = 0x1b3;
  local_7b0 = 0x1b3;
  local_7ac = 0x100;
  iVar3 = FUN_0020b890(*(undefined8 *)PTR_xavcsMovieReader_00402100,&local_7c8);
  puVar1 = PTR_piSyncInfo_00402f78;
  if (iVar3 == 0) {
    if (*(long *)PTR_piSyncInfo_00402f78 == 0) {
      pvVar4 = operator_new(0x610);
      FUN_001f8394(pvVar4,0x5a);
      *(void **)puVar1 = pvVar4;
    }
    local_790 = local_780;
    uStack_788 = 0;
    local_768 = local_758;
    local_748 = local_738;
    local_780[0] = 0;
    local_758[0] = 0;
    local_738[0] = 0;
    local_760 = 0;
    local_740 = 0;
    std::__cxx11::string::operator=((string *)&local_790,"");
    local_770 = 0;
    std::__cxx11::string::operator=((string *)&local_768,"");
    std::__cxx11::string::operator=((string *)&local_748,"");
    local_70c = 0;
    local_70b = 0;
    local_718 = 2;
    local_70a = 0;
    local_709 = 0;
    local_6d0 = 0;
    local_728 = 0;
    local_724 = 0;
    local_720 = 0;
    local_714 = 0;
    local_710 = 0;
    local_708 = 0;
    local_700 = 0;
    local_6f8 = 0;
    local_6f0 = 0;
    local_6e8 = 0;
    local_6e0 = 0;
    local_6d8 = 0;
    local_6cc = 0;
    SetMovieReaderStartParam((string *)&local_790,(int)param_1);
    std::__cxx11::string::string((string *)&local_808,(string *)&local_790);
    uVar2 = local_770;
    std::__cxx11::string::string((string *)&local_7e8,(string *)&local_768);
    std::__cxx11::string::string((string *)&local_380,(string *)&local_748);
    local_5c2 = uVar2;
    local_3b4 = local_728;
    local_391 = local_709;
    local_3b0 = local_724;
    local_3a8 = local_720;
    local_390 = local_6d8;
    local_3a0 = local_718;
    local_388 = local_6cc;
    local_39c = local_714;
    local_384 = local_6d0;
    local_392 = local_70a;
    local_394 = local_70c;
    local_393 = local_70b;
    local_398 = local_710;
    strncpy(acStack_6c8,local_808,0x105);
    strncpy(acStack_5c1,local_7e8,0x105);
    strncpy(acStack_4bb,
            (char *)CONCAT17(uStack_379,
                             CONCAT16(uStack_37a,
                                      CONCAT15(uStack_37b,
                                               CONCAT14(uStack_37c,CONCAT22(uStack_37e,local_380))))
                            ),0x105);
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    puVar1 = PTR_s_pbStartParam_00401a40;
    strncpy(acStack_6c8,*(char **)PTR_s_pbStartParam_00401a40,0x105);
    strncpy(acStack_5c1,*(char **)(puVar1 + 0x28),0x105);
    strncpy(acStack_4bb,*(char **)(puVar1 + 0x48),0x105);
    local_808 = (char *)local_708;
    uVar5 = *(undefined8 *)PTR_piSyncInfo_00402f78;
    local_800 = local_700;
    local_7f8 = local_6f8;
    local_7e8 = (char *)local_6f0;
    local_7e0 = local_6e8;
    local_7d8 = local_6e0;
    memcpy((string *)&local_380,acStack_6c8,0x348);
    uStack_30 = CONCAT44(uStack_7fc,local_800);
    local_38 = local_808;
    local_28 = local_7f8;
    uStack_18 = CONCAT44(uStack_7dc,local_7e0);
    local_20 = local_7e8;
    local_10 = local_7d8;
    local_8 = uVar5;
    if (param_1 != 2) {
      Codec::ResetDecPointer();
    }
    iVar3 = FUN_00212e1c(*(undefined8 *)PTR_xavcsMovieReader_00402100,(string *)&local_380);
    if (iVar3 == 0) {
      FUN_001fe3bc(*(undefined8 *)(PTR_s_pbStartParam_00401a40 + 0x90),
                   PTR_PlayingMovieErrorCb_004027f0);
      uVar5 = 8;
      local_814 = 4;
      local_816 = 0x32f;
    }
    else {
      uVar5 = 0x10;
      local_814 = 2;
      local_816 = 0x322;
      uStack_80c = 0xf80;
      local_810 = iVar3;
    }
    local_811 = 0;
    local_812 = 0;
    local_813 = 0;
    local_818 = 0x2313;
    FUN_001fe840(&local_818,uVar5);
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
  }
  else {
    uStack_37b = 0;
    uStack_37c = 2;
    uStack_37a = 0;
    uStack_37e = 0x321;
    uStack_379 = 0;
    local_374 = 0xf46;
    local_380 = 0x2313;
    local_378 = iVar3;
    FUN_001fe840((string *)&local_380,0x10);
  }
  return iVar3;
}

