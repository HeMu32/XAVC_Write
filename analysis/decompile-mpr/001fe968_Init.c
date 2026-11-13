// mpr::MoviePlayer::Init
// Ghidra address: 001fe968

/* mpr::MoviePlayer::Init(mpr::MoviePlayer::InitInParam const&, mpr::MoviePlayer::InitOutParam*) */

undefined8 mpr::MoviePlayer::Init(InitInParam *param_1,InitOutParam *param_2)

{
  undefined *puVar1;
  void *pvVar2;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_4 = 4;
  local_3 = 0;
  local_8 = 0x2313;
  local_2 = 0;
  local_6 = 0x10;
  local_1 = 0;
  FUN_001fe840(&local_8,8);
  Codec::SetCbFuncForPlayMovie
            ((_func_void_IntFactor_PayloadCodec_ptr *)PTR_CallbackPointForCodec_00401a88);
  puVar1 = PTR_xavcsMovieReader_00402100;
  if (*(long *)PTR_xavcsMovieReader_00402100 == 0) {
    pvVar2 = operator_new(0x1e70);
    FUN_0020b420();
    *(void **)puVar1 = pvVar2;
  }
  puVar1 = PTR_s_vpiSyncInfoList_00402310;
  FUN_001b45a4(PTR_s_vpiSyncInfoList_00402310);
  FUN_001b45a4(puVar1 + 0x5e8);
  FUN_001b45a4(puVar1 + 0xbd0);
  FUN_001b45a4(puVar1 + 0x11b8);
  puVar1 = PTR_s_vpiSyncInfoTemp_00401740;
  FUN_001b45a4(PTR_s_vpiSyncInfoTemp_00401740);
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  *(undefined **)PTR_sp_vpiSyncInfo_00401668 = puVar1;
  local_4 = 4;
  local_8 = 0x2313;
  local_6 = 0x1f;
  FUN_001fe840(&local_8,8);
  return 0;
}

