// FUN_0021f030
// Ghidra address: 0021f030

/* WARNING: Heritage AFTER dead removal. Example location: x0 : 0x00220dd0 */
/* WARNING: Removing unreachable block (ram,0x0021fe84) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_0021f030(XavcsMovieWriter *param_1)

{
  XavcsMovieWriter *pXVar1;
  XavcsMovieWriter *__src;
  string *this;
  normalLock *this_00;
  undefined1 *puVar2;
  XavcsMovieWriter XVar3;
  XavcsMovieWriter XVar4;
  XavcsMovieWriter XVar5;
  XavcsMovieWriter XVar6;
  XavcsMovieWriter XVar7;
  XavcsMovieWriter XVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ulong uVar11;
  bool bVar12;
  undefined *puVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  char cVar21;
  uint uVar22;
  int iVar23;
  int extraout_w0;
  uint extraout_w0_00;
  uint uVar24;
  uint extraout_w0_01;
  uint extraout_w0_02;
  int iVar25;
  undefined4 uVar26;
  uint uVar27;
  int extraout_w0_03;
  int extraout_w0_04;
  int extraout_w0_05;
  int extraout_w0_06;
  void *pvVar28;
  long *plVar29;
  long lVar30;
  void *pvVar31;
  RingBuffer *this_01;
  xavcsMovieMeta *this_02;
  uchar *__ptr;
  ulong uVar32;
  BaseList *pBVar33;
  long lVar34;
  movieManuallyEnteredMeta *pmVar35;
  ostream *this_03;
  void *pvVar36;
  undefined8 uVar37;
  undefined8 *puVar38;
  uint *puVar39;
  long lVar40;
  ulong uVar41;
  long lVar42;
  ulong uVar43;
  ulong uVar44;
  uint uVar45;
  BaseList *pBVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  uint uVar61;
  uint uVar62;
  undefined8 uVar63;
  long lVar64;
  ulong uVar65;
  long lVar66;
  ulong uVar67;
  ulong uVar68;
  ulong uVar69;
  uint uVar70;
  uint uVar71;
  uint uVar72;
  bool *in_stack_ffffffffffffe680;
  undefined4 uVar73;
  XavcsMovieWriter *in_stack_ffffffffffffe688;
  XavcsMovieWriter *in_stack_ffffffffffffe690;
  undefined4 uVar74;
  XavcsMovieWriter *in_stack_ffffffffffffe698;
  undefined4 uVar75;
  movieManuallyEnteredMeta *in_stack_ffffffffffffe6a0;
  undefined4 uVar76;
  undefined4 local_18a8;
  undefined4 local_1878;
  ulong local_1868;
  int local_1860;
  uint local_185c;
  undefined4 local_1850;
  uint local_1848;
  int local_1844;
  undefined4 local_1840;
  ulong local_1838;
  long local_1820;
  uint local_1814;
  bool local_1810;
  long local_1800;
  uint local_17f8;
  int local_17f4;
  long local_17f0;
  uint local_17e8;
  uint local_17e4;
  uint local_17d8;
  uint local_17d4;
  ulong local_17c0;
  int local_17ac;
  undefined1 auStack_17a0 [80];
  undefined1 auStack_1750 [1280];
  undefined1 auStack_1250 [520];
  bool local_1048;
  XavcsMovieWriter local_1047;
  char local_1046;
  char local_1045;
  int local_1044;
  int local_1040;
  int local_103c;
  uint local_1038;
  uint local_1034;
  uint local_1030;
  int local_102c;
  uint local_1028;
  uint local_1024;
  undefined4 local_1020;
  undefined4 local_101c;
  undefined4 local_1018;
  undefined4 local_1014;
  undefined4 local_1010;
  uint local_100c;
  undefined4 local_1008;
  uint local_1004;
  undefined8 *local_1000;
  undefined8 local_ff8;
  long local_ff0;
  long local_fe8;
  undefined8 local_fe0;
  undefined8 local_fd8;
  undefined2 local_fd0;
  undefined2 uStack_fce;
  XavcsMovieWriter XStack_fcc;
  XavcsMovieWriter XStack_fcb;
  XavcsMovieWriter XStack_fca;
  XavcsMovieWriter XStack_fc9;
  undefined2 local_fc8;
  undefined2 local_fc0;
  undefined2 uStack_fbe;
  undefined1 uStack_fbc;
  undefined1 uStack_fbb;
  undefined1 uStack_fba;
  undefined1 uStack_fb9;
  undefined2 local_fb8;
  undefined2 local_fb0;
  undefined2 uStack_fae;
  undefined1 uStack_fac;
  undefined1 uStack_fab;
  undefined1 uStack_faa;
  undefined1 uStack_fa9;
  undefined4 local_fa8;
  uint local_fa0;
  undefined1 local_f9c;
  undefined1 local_f9b;
  undefined1 local_f9a;
  undefined1 local_f99;
  undefined4 local_f98;
  BufferArea_t aBStack_f90 [16];
  BufferArea_t aBStack_f80 [16];
  BufferArea_t aBStack_f70 [16];
  uint local_f60;
  undefined4 uStack_f5c;
  undefined8 uStack_f58;
  undefined8 local_f50;
  undefined8 uStack_f48;
  undefined8 local_f40;
  undefined1 auStack_f38 [8];
  long local_f30;
  uint local_f18 [2];
  undefined1 *local_f10;
  undefined8 local_f08;
  undefined1 local_f00 [16];
  undefined8 local_ef0;
  undefined4 uStack_ee8;
  undefined4 local_ee4;
  undefined4 uStack_ee0;
  uint local_edc;
  undefined4 uStack_ed8;
  undefined4 local_ed4;
  uint local_ed0;
  undefined4 local_ecc;
  uint local_ec8;
  undefined4 uStack_ec4;
  undefined8 local_ec0;
  undefined4 local_eb8;
  undefined1 local_eb0;
  undefined7 uStack_eaf;
  undefined1 uStack_ea8;
  undefined8 uStack_ea7;
  undefined8 local_e9f;
  undefined8 uStack_e97;
  undefined1 *local_e88;
  undefined8 local_e80;
  undefined1 local_e78 [16];
  undefined8 local_e68;
  normalLock anStack_e60 [8];
  undefined8 local_e58;
  undefined8 uStack_e50;
  undefined8 local_e48;
  undefined8 uStack_e40;
  undefined8 local_e38;
  undefined8 uStack_e30;
  undefined8 local_e28;
  undefined8 local_e20;
  undefined4 local_e18;
  int local_e14;
  undefined4 local_e10;
  undefined4 local_e0c;
  uint local_e08;
  uint local_e04;
  undefined4 local_e00;
  undefined4 local_dfc;
  uint local_df8;
  undefined4 local_df4;
  undefined4 local_df0;
  undefined8 local_de8;
  undefined1 local_de0;
  ulong *local_dd8;
  undefined1 auStack_dd0 [8];
  undefined4 local_dc8;
  undefined4 local_dbc;
  ulong local_d80 [10];
  string asStack_d30 [32];
  string asStack_d10 [32];
  string asStack_cf0 [32];
  undefined1 auStack_cd0 [104];
  long local_c68 [13];
  uint local_c00;
  uint local_bfc;
  ulong local_bf8;
  vector<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
  avStack_bf0 [24];
  uint local_bd8;
  long local_bd0;
  int local_bc8;
  vector<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
  avStack_bc0 [24];
  uint local_ba8;
  long local_ba0;
  int local_b98;
  undefined4 local_b94;
  undefined4 local_b90;
  undefined8 local_b88;
  void *local_b80;
  long local_b78;
  uint local_b68;
  uint local_b64;
  ulong local_b60;
  long local_b58;
  long local_b50;
  uint local_b40 [2];
  long local_b38;
  int local_b30;
  long local_b28 [3];
  uint local_b10 [2];
  long local_b08;
  int local_b00;
  undefined4 local_afc;
  undefined4 local_af8;
  ulong local_af0;
  uint local_ae0;
  XavcsMovieWriter local_adc;
  XavcsMovieWriter local_adb;
  XavcsMovieWriter local_ada;
  XavcsMovieWriter local_ad9;
  undefined4 local_ad8;
  undefined4 local_ad4;
  undefined4 local_ad0;
  uint local_acc;
  undefined1 auStack_ac8 [80];
  undefined1 local_a78;
  undefined8 local_a77;
  undefined8 uStack_a6f;
  undefined8 local_a67;
  undefined8 uStack_a5f;
  undefined1 *local_a50;
  undefined8 local_a48;
  undefined1 local_a40 [16];
  undefined4 local_a30;
  undefined4 local_a2c;
  XavcsMovieWriter local_a28;
  undefined1 *local_a20;
  undefined8 local_a18;
  undefined1 local_a10 [16];
  undefined4 local_a00;
  uint local_9fc;
  undefined8 local_9f8;
  undefined8 local_9f0;
  undefined8 local_9e8;
  uint local_9e0;
  uint local_9dc;
  uint local_9d8;
  undefined8 local_9d4;
  undefined8 uStack_9cc;
  undefined8 local_9c4;
  int local_9bc;
  undefined4 local_9b8;
  undefined8 local_9b4;
  undefined4 local_9ac;
  undefined8 local_9a8;
  undefined4 local_9a0;
  undefined1 auStack_99c [128];
  undefined8 local_91c;
  undefined2 local_914;
  undefined8 local_910;
  undefined8 local_908;
  undefined8 uStack_900;
  undefined8 local_8f8;
  undefined8 uStack_8f0;
  undefined1 auStack_8e8 [80];
  undefined1 auStack_898 [104];
  string asStack_830 [32];
  string asStack_810 [32];
  string asStack_7f0 [32];
  undefined4 local_7d0 [2];
  void *local_7c8;
  undefined4 local_798;
  undefined1 auStack_794 [268];
  ulong local_688;
  ulong local_680;
  undefined8 local_678 [64];
  undefined8 local_478;
  undefined8 local_470;
  undefined8 local_468;
  undefined8 local_460;
  undefined8 local_458;
  undefined8 uStack_450;
  uint local_448;
  undefined4 uStack_444;
  ulong local_440;
  undefined8 local_438;
  ulong local_430;
  ulong *local_428;
  void *local_420;
  ulong local_418;
  undefined8 local_410;
  ulong local_408;
  ulong local_400;
  undefined1 auStack_332 [262];
  undefined1 auStack_22c [268];
  void *local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  ulong local_e8;
  XavcsMovieWriter local_e0;
  void *local_d8;
  uint local_d0;
  undefined1 local_cc;
  void *local_c8;
  uint local_c0;
  undefined4 local_bc;
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  ulong local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined4 local_10;
  long local_8;
  
  iVar23 = 0;
  local_478 = (void *)0x401702310;
  FUN_0021777c(&local_478,8);
  do {
    while( true ) {
      do {
        uVar22 = FUN_00219a80(param_1,&local_1044,&local_1000);
        puVar38 = local_1000;
        uVar26 = (undefined4)((ulong)in_stack_ffffffffffffe688 >> 0x20);
        uVar74 = (undefined4)((ulong)in_stack_ffffffffffffe690 >> 0x20);
        uVar75 = (undefined4)((ulong)in_stack_ffffffffffffe698 >> 0x20);
        uVar76 = (undefined4)((ulong)in_stack_ffffffffffffe6a0 >> 0x20);
        local_185c = uVar22 & 0xff;
      } while ((uVar22 & 0xff) == 0);
      if (local_1044 == 0x10000000) break;
      free(local_1000);
    }
    pXVar1 = param_1 + 0x430;
    uVar65 = 0;
    memcpy(pXVar1,local_1000,0x550);
    free(puVar38);
    uVar73 = (undefined4)((ulong)in_stack_ffffffffffffe680 >> 0x20);
    uVar69 = *(ulong *)(param_1 + 0x958);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x434);
    if (*(int *)(param_1 + 0x56c) == 2) {
      if (*(long **)(param_1 + 0x998) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x998) + 8))();
      }
      *(undefined8 *)(param_1 + 0x998) = 0;
      pvVar28 = operator_new(0x20);
      FUN_00206310();
      *(void **)(param_1 + 0x998) = pvVar28;
      uVar65 = (ulong)(*(uint *)(param_1 + 0x928) >> 1);
      FUN_00206328(pvVar28,*(undefined8 *)(param_1 + 0x920),uVar65);
      uVar63 = CONCAT71((int7)((ulong)in_stack_ffffffffffffe680 >> 8),1);
      iVar23 = FUN_002063cc(*(undefined8 *)(param_1 + 0x998),1,*(undefined8 *)(param_1 + 0x8a8),
                            *(undefined4 *)(param_1 + 0x8b0),1,1,*(undefined8 *)(param_1 + 0x848),
                            *(undefined4 *)(param_1 + 0x850),uVar63);
      uVar73 = (undefined4)((ulong)uVar63 >> 0x20);
      if (iVar23 != 0) {
        local_478 = (void *)0x201782310;
        local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
        FUN_0021777c((string *)&local_478,0x10);
        FUN_001fe0e8(uVar69,iVar23);
      }
    }
    lVar40 = *(long *)(param_1 + 0x920) + uVar65;
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x930);
    iVar25 = *(int *)(param_1 + 0x928) - (int)uVar65;
    *(int *)(param_1 + 0x10) = iVar25;
    *(long *)(param_1 + 8) = lVar40;
    plVar29 = (long *)mpr::DmacLib::MakeDmacLib
                                (lVar40,iVar25,lVar40 - *(long *)(param_1 + 0x930),0xffffffff,0);
    lVar40 = *plVar29;
    *(long **)(param_1 + 0x128) = plVar29;
    cVar21 = (**(code **)(lVar40 + 0x30))();
    if (cVar21 == '\0') {
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined8 *)(param_1 + 0x18) = 0;
    }
    pvVar28 = operator_new(0x68);
    FUN_0032a730();
    local_ff8 = 0;
    if (*(int *)(param_1 + 0x574) == 1) {
      uVar27 = (uint)*(ushort *)(param_1 + 0x578);
LAB_0021fe38:
      local_ff8 = CONCAT44((int)pvVar28,uVar27);
    }
    else if (*(int *)(param_1 + 0x574) == 2) {
      uVar27 = *(uint *)(param_1 + 0x580);
      goto LAB_0021fe38;
    }
    XVar3 = param_1[0x5b0];
    plVar29 = *(long **)(param_1 + 0x5f0);
    if (XVar3 == (XavcsMovieWriter)0x0) {
      *(undefined4 *)((long)plVar29 + 0x14) = 0;
      *(undefined4 *)(plVar29 + 3) = 0;
    }
    else {
      *(undefined4 *)(plVar29 + 3) = *(undefined4 *)((long)plVar29 + 0x14);
    }
    *(undefined4 *)((long)plVar29 + 0x1c) = 0;
    local_478 = (char *)0x101812310;
    local_470 = (long *)(ulong)CONCAT14(XVar3,*(undefined4 *)(param_1 + 0x430));
    local_468 = (RingBuffer *)(ulong)*(uint *)((long)plVar29 + 0x14);
    FUN_0021777c((string *)&local_478,0x18);
    local_17ac = 0;
    local_1040 = 0;
    local_103c = 0;
    local_ff0 = 0;
    uVar41 = *(ulong *)(*(long *)(param_1 + 0x5f0) + 0x28);
    uVar65 = *(ulong *)(*(long *)(param_1 + 0x5f0) + 0x38);
    if (uVar41 < uVar65) {
      uVar65 = uVar41;
    }
    lVar40 = uVar65 - 0x18;
    if (XVar3 != (XavcsMovieWriter)0x0) {
      libMp4Signature::ReMmapStreamBuffer
                ((BufferAreaInfo *)(param_1 + 0x848),&local_1040,&local_103c,&local_ff0);
      local_17ac = (int)lVar40;
    }
    FUN_0021b4bc(param_1);
    local_470 = (long *)0x0;
    local_478 = (char *)&local_468;
    local_468 = (RingBuffer *)((ulong)local_468 & 0xffffffffffffff00);
    std::__cxx11::string::operator=((string *)&local_478,(char *)(param_1 + 0x448));
    uVar65 = std::__cxx11::string::find((char *)&local_478,0x3d8131);
    std::__cxx11::string::replace((ulong)&local_478,uVar65 & 0xffffffff,(char *)0x4);
    strncpy((char *)(param_1 + 0x9d0),local_478,0x106);
    __src = param_1 + 0x440;
    std::__cxx11::string::replace((ulong)&local_478,uVar65 & 0xffffffff,(char *)0x4);
    strncpy((char *)(param_1 + 0xad6),local_478,0x106);
    std::__cxx11::string::_M_dispose();
    local_de0 = 0;
    local_e04 = *(uint *)(param_1 + 0x568);
    local_e10 = 0;
    local_e00 = *(undefined4 *)(param_1 + 0x56c);
    local_e20 = *(undefined8 *)(param_1 + 0x54e);
    local_e18 = *(undefined4 *)(param_1 + 0x556);
    local_dfc = *(undefined4 *)(param_1 + 0x570);
    local_e14 = *(int *)(param_1 + 0x560);
    local_df8 = (uint)*(ushort *)(param_1 + 0x578);
    lVar30 = (long)local_e14 * 0x1c;
    local_e0c = *(undefined4 *)(param_1 + 0x564);
    local_e08 = *(uint *)(param_1 + 0x55c);
    local_df4 = 0;
    local_df0 = 0;
    local_de8 = 0;
    local_dd8 = (ulong *)0x0;
    if (*(int *)(PTR_m_vpcSt_00401d98 + lVar30 + 0x18) == 0) {
      if (*(int *)(param_1 + 0x444) == 0) {
        if (*(int *)(PTR_m_vpcSt_00401d98 + lVar30) != 1) {
LAB_0021fe60:
          lVar30 = 1;
        }
        local_e10 = (undefined4)lVar30;
      }
      else if (*(int *)(PTR_m_vpcSt_00401d98 + lVar30) == 0) goto LAB_0021fe60;
    }
    if (param_1[0x5b0] != (XavcsMovieWriter)0x0) {
      local_de0 = 1;
      local_dd8 = (ulong *)FUN_002a8820(*(undefined4 *)(param_1 + 0x5ec));
    }
    local_fe8 = 0;
    local_680 = CONCAT44(local_680._4_4_,0x58415643);
    local_678[0] = 0xa00000;
    pvVar31 = operator_new(800);
    FUN_00322994(pvVar31,(string *)&local_680);
    FUN_00322b18(pvVar31,&local_e20);
    if ((int)pvVar31 == 0) {
      FUN_0032a380(pvVar31,0,0,0,&local_fe8);
    }
    else {
      local_478 = (char *)0x201802310;
      local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
      FUN_0021777c((string *)&local_478,0x10);
      FUN_001fe0e8(uVar69,iVar23);
    }
    FUN_00329434(pvVar31);
    thunk_FUN_00329434(pvVar31);
    operator_delete(pvVar31,800);
    if (XVar3 != (XavcsMovieWriter)0x0) {
      local_fe8 = local_fe8 + 0x18 + lVar40;
    }
    uVar63 = *(undefined8 *)(param_1 + 0x880);
    uVar67 = *(ulong *)(param_1 + 0x878);
    uVar41 = (ulong)*(uint *)(param_1 + 0x910) * (ulong)*(uint *)(param_1 + 0x914);
    uVar65 = 0;
    if (uVar41 != 0) {
      uVar65 = (local_fe8 + -1 + uVar41) / uVar41;
    }
    local_fe8 = uVar65 * uVar41;
    memset((string *)&local_478,0,0x88);
    local_478 = *(char **)(param_1 + 0x108);
    local_470 = (long *)local_e20;
    local_468 = (RingBuffer *)CONCAT44(local_e14,local_e18);
    local_460 = (XavcsMovieWriter *)CONCAT44(local_e0c,local_e10);
    local_458._0_4_ = local_e08;
    local_458._4_4_ = local_e04;
    uStack_450._0_4_ = local_e00;
    uStack_450._4_4_ = local_dfc;
    local_448 = local_df8;
    uStack_444 = local_df4;
    local_440 = CONCAT44(local_440._4_4_,local_df0);
    local_438 = local_de8;
    local_430 = CONCAT71(local_430._1_7_,local_de0);
    local_428 = local_dd8;
    local_420 = pvVar28;
    local_418 = uVar67;
    local_410 = uVar63;
    local_408 = uVar41;
    local_400 = uVar69;
    FUN_00218670(param_1,*(undefined4 *)(param_1 + 0x430),(string *)&local_478);
    memset(local_7d0,0,0x150);
    local_7d0[0] = *(undefined4 *)(param_1 + 0x434);
    local_798 = *(undefined4 *)(param_1 + 0x444);
    local_7c8 = pvVar28;
    local_688 = uVar69;
    memcpy(auStack_794,param_1 + 0x9d0,0x106);
    FUN_002186e0(param_1,*(undefined4 *)(param_1 + 0x430),local_7d0);
    pvVar31 = operator_new(0x38);
    FUN_001fb710();
    *(void **)(param_1 + 0x9a8) = pvVar31;
    pvVar31 = operator_new(0x30);
    thunk_FUN_001fb824(pvVar31,*(undefined8 *)(param_1 + 0x9a8));
    *(void **)(param_1 + 0x9a0) = pvVar31;
    this = (string *)(param_1 + 0xcb8);
    FUN_001fbb08(pvVar31,local_fe8);
    this_01 = *(RingBuffer **)(param_1 + 0x840);
    puVar2 = &DAT_003d7eaf;
    if (*(undefined1 **)(param_1 + 0x5a8) != (undefined1 *)0x0) {
      puVar2 = *(undefined1 **)(param_1 + 0x5a8);
    }
    FUN_0021763c(auStack_f38,puVar2);
    if (local_f30 == 0) {
      std::__cxx11::stringstream::stringstream((stringstream *)&local_478,0x18);
      std::ostream::operator<<((ostream *)&local_468,0xffffffff);
      std::__cxx11::stringbuf::str();
      std::__cxx11::string::operator=(this,(string *)&local_680);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::stringstream::~stringstream((stringstream *)&local_478);
    }
    else {
      std::__cxx11::string::assign((char *)this);
    }
    FUN_00217bc4(auStack_dd0);
    FUN_00217c00(auStack_cd0);
    std::__cxx11::string::string(asStack_d30,(string *)(param_1 + 0xc78));
    std::__cxx11::string::string(asStack_d10,(string *)(param_1 + 0xc98));
    std::__cxx11::string::string(asStack_cf0,this);
    FUN_00217da8(param_1,__src,auStack_dd0,auStack_cd0);
    memset(&local_908,0,0x138);
    memcpy(auStack_8e8,auStack_dd0,0x50);
    memcpy(auStack_898,auStack_cd0,100);
    std::__cxx11::string::string(asStack_830,asStack_d30);
    std::__cxx11::string::string(asStack_810,asStack_d10);
    std::__cxx11::string::string(asStack_7f0,asStack_cf0);
    local_908 = *(undefined8 *)(param_1 + 0x584);
    uStack_900 = *(undefined8 *)(param_1 + 0x58c);
    local_8f8 = *(undefined8 *)(param_1 + 0x594);
    uStack_8f0 = *(undefined8 *)(param_1 + 0x59c);
    pvVar31 = operator_new(0x30);
    FUN_00352de0();
    *(void **)(param_1 + 0x980) = pvVar31;
    FUN_00352e30(pvVar31,&local_908);
    if ((int)pvVar31 != 0) {
      local_478 = (char *)0x201902310;
      local_470 = (long *)CONCAT44((int)pvVar31,*(undefined4 *)(param_1 + 0x430));
      FUN_0021777c((string *)&local_478,0x10);
    }
    this_02 = operator_new(0x5cf0);
    FUN_00207e28();
    in_stack_ffffffffffffe6a0 =
         (movieManuallyEnteredMeta *)CONCAT44(uVar76,*(undefined4 *)(param_1 + 0x974));
    in_stack_ffffffffffffe698 =
         (XavcsMovieWriter *)CONCAT44(uVar75,*(undefined4 *)(param_1 + 0x970));
    in_stack_ffffffffffffe690 =
         (XavcsMovieWriter *)CONCAT44(uVar74,*(undefined4 *)(param_1 + 0x96c));
    in_stack_ffffffffffffe688 =
         (XavcsMovieWriter *)CONCAT44(uVar26,*(undefined4 *)(param_1 + 0x968));
    in_stack_ffffffffffffe680 = (bool *)CONCAT44(uVar73,*(undefined4 *)(param_1 + 0x964));
    xavcsMovieMeta::Init
              (this_02,*(undefined8 *)(param_1 + 0x980),*(undefined4 *)(param_1 + 0x434),
               param_1[0x438],*(undefined4 *)(param_1 + 0x444),*(undefined4 *)(param_1 + 0x55c),
               *(undefined2 *)(param_1 + 0x578),*(undefined4 *)(param_1 + 0x574),
               in_stack_ffffffffffffe680,in_stack_ffffffffffffe688,in_stack_ffffffffffffe690,
               in_stack_ffffffffffffe698,in_stack_ffffffffffffe6a0,&local_1038);
    extraout_w0 = (int)this_02;
    if (extraout_w0 != 0) {
      local_478 = (char *)0x201982310;
      local_470 = (long *)CONCAT44(extraout_w0,*(undefined4 *)(param_1 + 0x430));
      FUN_0021777c((string *)&local_478,0x10);
      FUN_001fe0e8(uVar69,extraout_w0);
    }
    __ptr = malloc((ulong)local_1038);
    pvVar31 = operator_new__(0x1000);
    memset(pvVar31,0,0x1000);
    FUN_001ca628(local_678);
    local_680 = uVar41;
    memcpy(local_678,__src,0x1fe);
    FUN_00218c50(param_1,(string *)&local_680);
    this_00 = (normalLock *)(param_1 + 0x2c28);
    mpr::thread::normalLock::lock(this_00);
    if (param_1[0x2c20] == (XavcsMovieWriter)0x0) {
      param_1[0x2c20] = param_1[0x978];
      *(undefined4 *)(param_1 + 0x2c24) = *(undefined4 *)(param_1 + 0x97c);
    }
    mpr::thread::normalLock::unlock((normalLock *)(param_1 + 0x2c28));
    local_1048 = false;
    local_f50 = 0;
    uStack_f48 = 0;
    local_1047 = (XavcsMovieWriter)0xff;
    local_1034 = 0;
    local_1030 = 0;
    local_102c = 0;
    local_1028 = 0;
    local_1024 = 0;
    local_fe0 = 0;
    local_f40 = 0;
    mpr::pconv::ConvertFrameRateToNumerAndDenom
              (*(undefined4 *)(param_1 + 0x55c),&local_1028,&local_1024);
    uVar65 = (ulong)local_1028;
    uVar67 = (ulong)local_1024;
    local_fe0 = CONCAT44(local_1024,local_1028);
    memset(&local_b88,0,0xa8);
    memset(&local_c00,0,0x78);
    local_fd8 = 0;
    local_afc = 4;
    if (*(int *)(param_1 + 0x56c) != 2) {
      local_afc = 1;
    }
    local_478 = (char *)0x1f4000003e8;
    FUN_0021aab4(__src,(string *)&local_478,&local_ff8,&local_fd8);
    uStack_ed8 = *(undefined4 *)(param_1 + 0x444);
    local_edc = *(uint *)(param_1 + 0x430);
    uStack_ee8 = 0;
    local_ef0 = (undefined8 *)CONCAT44(uStack_ed8,local_edc);
    local_ed0 = (uint)((ulong)(*(long *)(param_1 + 0x850) * 0x32) / 100);
    local_ed4 = 1;
    local_ec0 = 2;
    local_ee4 = (undefined4)local_fd8;
    uStack_ee0 = (undefined4)((ulong)local_fd8 >> 0x20);
    local_470 = (long *)CONCAT44(uStack_ed8,local_edc);
    local_ecc = (undefined4)((ulong)(*(long *)(param_1 + 0x850) * 0x19) / 100);
    local_468 = (RingBuffer *)local_fd8;
    local_eb8 = 0;
    local_478 = (char *)0x105482310;
    local_ec8 = local_edc;
    uStack_ec4 = uStack_ed8;
    FUN_0021777c((string *)&local_478,0x18);
    local_478 = (void *)0x105502310;
    local_470 = local_ef0;
    local_468 = (RingBuffer *)CONCAT44(local_ecc,local_ed0);
    FUN_0021777c((string *)&local_478,0x18);
    puVar13 = PTR_DAT_00401ec0;
    lVar30 = (ulong)*(uint *)(param_1 + 0x430) * 0x18 + (long)*(int *)(param_1 + 0x444) * 0xc;
    *(undefined4 *)(PTR_DAT_00401ec0 + lVar30) = 0;
    iVar23 = *(int *)(param_1 + 0x574);
    *(undefined4 *)(puVar13 + lVar30 + 4) = 0;
    *(undefined4 *)(puVar13 + lVar30 + 8) = 0;
    if (iVar23 == 0) {
LAB_0021fcb0:
      uVar32 = 10000;
    }
    else {
      uVar68 = mpr::pconv::ConvertFrameRateToNumer(*(undefined4 *)(param_1 + 0x55c));
      uVar68 = (uVar68 & 0xffff) * (local_ff8 >> 0x20);
      uVar44 = local_ff8 & 0xffffffff;
      if (uVar68 < uVar44 || uVar68 - uVar44 == 0) goto LAB_0021fcb0;
      uVar32 = 0;
      if (uVar44 != 0) {
        uVar32 = uVar68 / uVar44;
      }
      if (uVar68 - uVar32 * uVar44 != 0) {
        uVar32 = uVar32 + 1;
      }
      uVar32 = uVar32 * 5000;
    }
    uVar68 = 0;
    pBVar33 = memcpy(auStack_1250,__src,0x200);
    FUN_0021add0(param_1,pBVar33,*(undefined4 *)(param_1 + 0x90c),&local_ff8);
    extraout_w0_00 = (uint)pBVar33;
    local_1046 = '\0';
    local_1045 = '\0';
    local_1020 = 0;
    local_101c = 0;
    local_1018 = 0;
    local_1014 = 0;
    local_1010 = 0;
    FUN_0021afb4(param_1,__src,&local_ff8,&local_1020,&local_101c,&local_1018,&local_1014,
                 &local_1010);
    local_1878 = 0;
    local_1868 = 0;
    local_1848 = 0;
    local_1838 = 0;
    local_1820 = 0;
    local_1814 = 0;
    uVar70 = uVar22 & 0xff;
    uVar27 = uVar22 & 0xff;
    local_17f8 = 0;
    local_17f4 = 0;
    local_17f0 = 0;
    local_17e8 = 0;
    local_17e4 = 0;
    local_17d4 = 0;
    uVar62 = 0;
    while (uVar71 = uVar22 & 0xff, local_1048 == false) {
      uVar61 = 0;
      local_1860 = 0;
      bVar12 = false;
      local_17c0 = 0;
      local_fa0 = 0;
      local_f60 = 0;
      local_eb0 = 0;
      uStack_eaf = 0;
      local_e68 = 0;
      local_d80[0] = 0;
      local_c68[0] = 0;
      while ((uVar26 = SUB84(pBVar33,0), CONCAT71(uStack_eaf,local_eb0) < uVar32 &&
             (local_1048 == false))) {
        lVar34 = *(long *)(param_1 + 0x990);
        lVar30 = *(long *)(param_1 + 0x988);
        uVar24 = FUN_0021be3c(param_1,pXVar1,local_1020,local_1018,local_1014,local_1010,uVar69,
                              &local_1045);
        local_17d8 = 0;
        if ((uVar24 & 0xff) == 0) {
          mpr::Codec::GetVideoInfoReadList
                    (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),(vector *)&local_b58);
          if (uVar24 == 0) {
            local_f18[0] = local_f18[0] & 0xffffff00;
            local_ae0 = 0;
            local_a00 = 0;
            mpr::pconv::ConvertFrameRateToNumerAndDenom
                      (*(undefined4 *)(param_1 + 0x55c),&local_ae0,
                       (movieManuallyEnteredMeta *)&local_a00);
            uVar24 = 1;
            if ((*(uint *)(param_1 + 0x560) < 0xd) &&
               ((1L << ((ulong)*(uint *)(param_1 + 0x560) & 0x3f) & 0x1600U) != 0)) {
              uVar24 = 0x1e;
              if (*(uint *)(param_1 + 0x55c) < 0xc) {
                uVar24 = (uint)(byte)(&DAT_003d64b8)[*(uint *)(param_1 + 0x55c)];
              }
            }
            in_stack_ffffffffffffe690 = (XavcsMovieWriter *)&local_f60;
            in_stack_ffffffffffffe688 = &local_1047;
            in_stack_ffffffffffffe680 = (bool *)local_f18;
            pBVar33 = (BaseList *)
                      XavcsMovieWriter::WaitForVideoInfoAccumulation
                                (param_1,(vector *)&local_b58,uVar24,local_ae0,local_a00,&local_e68,
                                 local_b40,&local_1048,in_stack_ffffffffffffe680,
                                 (uchar *)in_stack_ffffffffffffe688,
                                 (uint *)in_stack_ffffffffffffe690);
            if ((int)pBVar33 == 0) {
              if (local_b40[0] != 0) {
                uVar61 = uVar70;
              }
              pBVar33 = (BaseList *)(local_b50 - local_b58);
              local_1860 = (int)((long)pBVar33 >> 5) * -0x55555555;
              FUN_00219b80(&local_ef0);
              if (local_f18[0]._0_1_ == (XavcsMovieWriter)0x0) goto LAB_0021fe18;
              goto LAB_00220404;
            }
            local_478 = (void *)0x201a02310;
            local_470 = (long *)CONCAT44((int)pBVar33,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0x10);
LAB_0022005c:
            uVar26 = SUB84(pBVar33,0);
            FUN_001fe0e8(uVar69,(ulong)pBVar33 & 0xffffffff);
            goto LAB_00220064;
          }
LAB_00220404:
          if (local_1048 != false) {
            FUN_00219b80(&local_ec8,1);
          }
          lVar30 = lVar30 + local_e68;
          local_17c0 = *(ulong *)(local_b58 + 0x18);
          pBVar33 = (BaseList *)((local_b50 - local_b58 >> 5) * -0x5555555555555555);
          for (pBVar46 = (BaseList *)0x0; pBVar46 <= pBVar33 && (long)pBVar33 - (long)pBVar46 != 0;
              pBVar46 = (BaseList *)(ulong)((int)pBVar46 + 1)) {
            cVar21 = *(char *)(local_b58 + (long)pBVar46 * 0x60);
            if ((cVar21 == '\x03' || cVar21 == '\0') || cVar21 == '\x01') {
              uVar44 = *(ulong *)(local_b58 + (long)pBVar46 * 0x60 + 0x18);
              if (uVar44 < local_17c0) {
                local_17c0 = uVar44;
              }
            }
            else if (cVar21 == '\t' || cVar21 == '\x02') break;
          }
          if (local_1820 == 0) {
            local_478 = (void *)0x101a42310;
            local_470 = (long *)CONCAT44((int)(local_17c0 >> 0x20),*(undefined4 *)(param_1 + 0x444))
            ;
            local_468 = (RingBuffer *)(local_17c0 & 0xffffffff);
            FUN_0021777c(&local_478,0x18);
            local_1868 = local_17c0;
          }
          mpr::Codec::GetAudioInfoReadList
                    (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),(vector *)local_b28,
                     *(int *)(param_1 + 0x568) - 3U < 2);
          if ((int)pBVar33 == 0) {
            iVar25 = *(int *)(param_1 + 0x568);
            local_a00 = local_a00 & 0xffffff00;
            iVar23 = 0x5a0;
            if (iVar25 - 3U < 2) {
              iVar23 = 0x400;
            }
            if ((iVar25 == 2) || (uVar24 = 48000, iVar25 == 4)) {
              uVar24 = 96000;
            }
            in_stack_ffffffffffffe698 = (XavcsMovieWriter *)local_b10;
            in_stack_ffffffffffffe690 = (XavcsMovieWriter *)local_d80;
            in_stack_ffffffffffffe688 = param_1 + 0x8a8;
            uVar60 = 0;
            if (uVar24 != 0) {
              uVar60 = (uint)(iVar23 * 90000) / uVar24;
            }
            in_stack_ffffffffffffe680 =
                 (bool *)CONCAT44((int)((ulong)in_stack_ffffffffffffe680 >> 0x20),uVar60);
            in_stack_ffffffffffffe6a0 = (movieManuallyEnteredMeta *)&local_a00;
            pBVar33 = (BaseList *)
                      XavcsMovieWriter::WaitForAudioInfoAccumulation
                                (param_1,iVar25,local_afc,local_b28,local_17c0,lVar30,lVar34,
                                 local_1048,in_stack_ffffffffffffe680,in_stack_ffffffffffffe688,
                                 in_stack_ffffffffffffe690,in_stack_ffffffffffffe698,
                                 (movieManuallyEnteredMeta *)&local_a00,local_c68);
            if ((int)pBVar33 == 0) {
              if (local_a00._0_1_ != (movieManuallyEnteredMeta)0x0) goto LAB_0022063c;
              goto LAB_00220634;
            }
LAB_00220604:
            local_478._0_4_ = CONCAT22((short)pBVar33,0x2310);
            local_478 = (char *)(ulong)CONCAT14(2,(undefined4)local_478);
            local_470 = (long *)CONCAT44((int)pBVar33,*(undefined4 *)(param_1 + 0x430));
            pmVar35 = (movieManuallyEnteredMeta *)&local_478;
LAB_00220620:
            FUN_0021777c(pmVar35,0x10);
            goto LAB_0022005c;
          }
LAB_0022063c:
          uVar44 = local_d80[0];
          mpr::Codec::GetMetaInfoReadList
                    (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),(vector *)&local_b80);
          if ((int)pBVar33 == 0) {
            local_a00 = local_a00 & 0xffffff00;
            pBVar33 = (BaseList *)
                      XavcsMovieWriter::WaitForMetaInfoAccumulation
                                (param_1,(vector *)&local_b80,(vector *)&local_b58,local_b40[0],
                                 local_1048,&local_b68,&local_fa0,(bool *)&local_a00);
            if ((int)pBVar33 != 0) goto LAB_00220604;
            if (local_a00._0_1_ == (movieManuallyEnteredMeta)0x0) goto LAB_00220634;
          }
          if (local_b68 == 0) {
LAB_00220754:
            pvVar36 = memcpy(&local_478,&DAT_003d63f0,0xc0);
            uVar43 = 0;
            do {
              if (*(int *)(uVar43 * 0x10 + (long)pvVar36) == *(int *)(param_1 + 0x55c)) {
                uVar43 = (ulong)(double)(&local_470)[(uVar43 & 0xffffffff) * 2];
                goto LAB_002207a4;
              }
              uVar43 = uVar43 + 1;
            } while (uVar43 != 0xc);
            uVar43 = 0x16e93c;
LAB_002207a4:
            local_1844 = 0;
            for (local_1800 = 0; (int)local_1800 < (int)(local_b50 - local_b58 >> 5) * -0x55555555;
                local_1800 = local_1800 + 1) {
              lVar64 = local_1800 * 0x60;
              lVar66 = local_b58 + lVar64;
              uVar24 = FUN_00217570(*(undefined1 *)(local_b58 + lVar64));
              if ((uVar24 & 0xff) != 0) {
                if (*(char *)(lVar66 + 0x59) != '\0') {
                  XavcsMovieWriter::ConvertMprMarkType2NrtMarkType(param_1);
                  lVar66 = local_b58 + lVar64;
                  if (uVar24 != 0xe) {
                    lVar42 = *(long *)(lVar66 + 0x18);
                    uVar60 = 0;
                    if (uVar43 != 0) {
                      uVar60 = (uint)((((1 - local_1868) + lVar42) * 1000) / uVar43);
                    }
                    if (*(uint *)(param_1 + 0xc04) < uVar60) {
                      uVar63 = *(undefined8 *)(lVar66 + 0x20);
                      uVar26 = XavcsMovieWriter::ConvertMprMarkType2MprEmType
                                         (param_1,*(undefined1 *)(lVar66 + 0x59));
                      cVar21 = XavcsMovieWriter::IsEditAvailable(param_1,0,uVar26);
                      if (cVar21 != '\0') {
                        local_9e0 = local_9e0 & 0xffffff00;
                        local_9f8 = local_9f8 & 0xffffffff00000000;
                        local_9e8 = 0;
                        local_a00 = uVar24;
                        local_9fc = uVar60;
                        local_9f0 = &local_9e0;
                        FUN_00355c8c(*(undefined8 *)(param_1 + 0x980),
                                     (movieManuallyEnteredMeta *)&local_a00);
                        puVar39 = *(uint **)(param_1 + 0xc10);
                        if (puVar39 == *(uint **)(param_1 + 0xc18)) {
                          FUN_0021c728(param_1 + 0xc08,(movieManuallyEnteredMeta *)&local_a00);
                        }
                        else {
                          if (puVar39 != (uint *)0x0) {
                            *puVar39 = local_a00;
                            puVar39[1] = local_9fc;
                            puVar39[2] = (uint)local_9f8;
                            std::__cxx11::string::string
                                      ((string *)(puVar39 + 4),(string *)&local_9f0);
                          }
                          *(long *)(param_1 + 0xc10) = *(long *)(param_1 + 0xc10) + 0x30;
                        }
                        local_adb = (XavcsMovieWriter)0x0;
                        local_ada = (XavcsMovieWriter)0x0;
                        local_adc = (XavcsMovieWriter)0x1;
                        local_ad9 = (XavcsMovieWriter)0x0;
                        *(int *)(param_1 + (long)(int)uVar24 * 4 + 0xbdc) =
                             *(int *)(param_1 + (long)(int)uVar24 * 4 + 0xbdc) + 1;
                        *(uint *)(param_1 + 0xc04) = uVar60;
                        local_ad8 = *(uint *)(param_1 + 0x444);
                        local_ae0 = 0x1a12310;
                        local_ad4 = (int)local_1800;
                        local_ad0 = local_1844 + (int)local_1820;
                        local_acc = (uint)*(byte *)(local_b58 + lVar64);
                        FUN_0021777c(&local_ae0,0x18);
                        local_adb = (XavcsMovieWriter)0x0;
                        local_adc = (XavcsMovieWriter)0x1;
                        local_ad8 = (uint)((ulong)lVar42 >> 0x20);
                        local_1850 = (undefined4)lVar42;
                        local_ae0 = 0x1a22310;
                        local_ad4 = local_1850;
                        local_ad0 = (uint)((ulong)uVar63 >> 0x20);
                        local_18a8 = (undefined4)uVar63;
                        local_acc = local_18a8;
                        local_ada = (XavcsMovieWriter)0x0;
                        local_ad9 = (XavcsMovieWriter)0x0;
                        FUN_0021777c(&local_ae0,0x18);
                        local_adb = (XavcsMovieWriter)0x0;
                        local_ada = (XavcsMovieWriter)0x0;
                        local_1840 = (undefined4)uVar43;
                        local_ad9 = (XavcsMovieWriter)0x0;
                        local_ad4 = local_1840;
                        local_adc = (XavcsMovieWriter)0x1;
                        local_ae0 = 0x1a32310;
                        local_acc = 0;
                        local_ad0 = (uint)*(byte *)(local_b58 + lVar64 + 0x59);
                        local_ad8 = uVar60;
                        FUN_0021777c(&local_ae0,0x18);
                        std::__cxx11::string::_M_dispose();
                      }
                    }
                  }
                }
                local_1844 = local_1844 + 1;
              }
            }
            lVar66 = 0;
            while (((int)lVar66 < (int)((ulong)(local_b78 - (long)local_b80) >> 8) * -0x33333333 &&
                   (local_17f4 != 2))) {
              if ((*(char *)((long)local_b80 + lVar66 * 0x500 + 0x13) != '\0') &&
                 (*(char *)((long)local_b80 + lVar66 * 0x500 + 0x406) != '\0')) {
                cVar21 = *(char *)((long)local_b80 + lVar66 * 0x500 + 0x412);
                if (cVar21 == 'A') {
                  FUN_00209008(this_02,(long)local_b80 + lVar66 * 0x500 + 0x400);
                  local_17f4 = 2;
                }
                else if (cVar21 == 'V') {
                  if (local_17f4 == 0) {
                    FUN_00209008(this_02,(long)local_b80 + lVar66 * 0x500 + 0x400);
                  }
                  local_17f4 = 1;
                }
              }
              lVar66 = lVar66 + 1;
            }
            mpr::BaseList::Clear(*(BaseList **)(param_1 + 0x110));
            pBVar33 = (BaseList *)
                      XavcsMovieWriter::MakeVideoEsList
                                (param_1,*(undefined4 *)(param_1 + 0x444),(vector *)&local_b58,
                                 local_b40[0],*(undefined8 *)(param_1 + 0x110),&local_102c,
                                 *(undefined8 *)(param_1 + 0x8a0));
            if ((int)pBVar33 == 0) {
              mpr::BaseList::Clear(*(BaseList **)(param_1 + 0x118));
              pBVar33 = (BaseList *)
                        XavcsMovieWriter::MakeAudioEsList
                                  (param_1,*(undefined4 *)(param_1 + 0x444),local_b28,local_b10[0],
                                   *(undefined8 *)(param_1 + 0x118),*(undefined8 *)(param_1 + 0x8b8)
                                  );
              if ((int)pBVar33 == 0) {
                uVar26 = mpr::RingBuffer::GetUsedSize(this_01);
                FUN_00219b80(&local_edc,uVar26);
                pBVar33 = *(BaseList **)(param_1 + 0x110);
                mpr::BaseList::GetSize(pBVar33);
                extraout_w0_01 = (uint)pBVar33;
                pBVar33 = *(BaseList **)(param_1 + 0x118);
                mpr::BaseList::GetSize(pBVar33);
                extraout_w0_02 = (uint)pBVar33;
                local_17e8 = local_b68 * local_1038;
                mpr::RingBuffer::GetRemainSize(this_01);
                uVar24 = extraout_w0_01 + extraout_w0_02 + local_17e8;
                local_17d4 = extraout_w0_02;
                uVar62 = extraout_w0_01;
                if (extraout_w0_02 < uVar24) {
LAB_00220634:
                  local_1048 = false;
                  goto LAB_0021fe18;
                }
                if (local_1048 != false) {
                  uVar43 = (ulong)*(uint *)(param_1 + 0x90c);
                  uVar60 = uVar24 + 8;
                  if (XVar3 == (XavcsMovieWriter)0x0) {
                    uVar60 = uVar24;
                  }
                  uVar11 = 0;
                  if (uVar43 != 0) {
                    uVar11 = (uVar68 + uVar60) / uVar43;
                  }
                  pBVar33 = (BaseList *)((uVar68 + uVar60) - uVar11 * uVar43);
                  if (pBVar33 != (BaseList *)0x0) {
                    uVar59 = (uint)pBVar33;
                    iVar23 = *(uint *)(param_1 + 0x90c) - uVar59;
                    mpr::RingBuffer::GetRemainSize(this_01);
                    if (uVar59 < uVar60 + iVar23) {
                      local_9fc = 1;
                      local_a00 = 0x1e12310;
                      local_9f8 = CONCAT44(local_9f8._4_4_,*(undefined4 *)(param_1 + 0x430));
                      mpr::RingBuffer::GetRemainSize(this_01);
                      local_9f8 = CONCAT44(uVar59,(uint)local_9f8);
                      local_9f0 = (uint *)CONCAT44(iVar23,uVar24);
                      FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x18);
                      goto LAB_00220634;
                    }
                  }
                }
                uVar26 = SUB84(pBVar33,0);
                *(long *)(param_1 + 0x988) = lVar30;
                *(ulong *)(param_1 + 0x990) = lVar34 + uVar44;
                local_17d8 = uVar71;
                goto LAB_00220064;
              }
            }
            local_9fc = 2;
            local_a00 = CONCAT22((short)pBVar33,0x2310);
            local_9f8 = CONCAT44((int)pBVar33,*(undefined4 *)(param_1 + 0x430));
            pmVar35 = (movieManuallyEnteredMeta *)&local_a00;
            goto LAB_00220620;
          }
          local_478 = (char *)((ulong)local_478 & 0xffffffff00000000);
          FUN_0020a158(this_02,local_b80,(void *)((long)local_b80 + (ulong)(local_b68 - 1) * 0x500),
                       local_b68,&local_b80,&local_478);
          if ((1 < *(int *)(param_1 + 0x968) - 1U) ||
             (((ulong)local_478 & 0x10000000) != 0 || bVar12)) {
            bVar12 = false;
            goto LAB_00220754;
          }
          local_1048 = false;
          FUN_00218634(param_1,uVar61,&local_eb0,local_b68);
          bVar12 = true;
        }
        else {
          pBVar33 = (BaseList *)FUN_0021c1f0(param_1,pXVar1,&local_1047);
          uVar26 = SUB84(pBVar33,0);
          if (((ulong)pBVar33 & 0xff) != 0) goto LAB_00220064;
          FUN_0021c464(param_1,pXVar1,1);
LAB_0021fe18:
          FUN_00218634(param_1,uVar61,&local_eb0,100);
        }
      }
      local_17d8 = 0;
LAB_00220064:
      local_f18[0] = 0;
      if (local_17d8 == 0) {
        local_478 = (char *)0x101c82310;
        local_470 = (long *)CONCAT44(local_470._4_4_,*(undefined4 *)(param_1 + 0x430));
        mpr::RingBuffer::GetRemainSize(this_01);
        local_470 = (long *)CONCAT44(uVar26,(undefined4)local_470);
        local_468 = (RingBuffer *)(ulong)(uVar62 + local_17e8 + local_17d4);
        FUN_0021777c(&local_478,0x18);
        local_478 = (char *)0x101cb2310;
        local_468 = (RingBuffer *)(CONCAT71(uStack_eaf,local_eb0) & 0xffffffff);
        local_470 = (long *)CONCAT44((int)((uint7)uStack_eaf >> 0x18),
                                     *(undefined4 *)(param_1 + 0x430));
        FUN_0021777c(&local_478,0x18);
        local_478 = (char *)0x101c92310;
        local_470 = (long *)CONCAT44(local_b40[0],*(undefined4 *)(param_1 + 0x430));
        local_468 = (RingBuffer *)CONCAT44(local_b68,local_b10[0]);
        FUN_0021777c(&local_478,0x18);
        local_478 = (char *)0x201ca2310;
        local_470 = (long *)(ulong)CONCAT14(local_1045,*(undefined4 *)(param_1 + 0x430));
        FUN_0021777c(&local_478,0x10);
        FUN_0021c464(param_1,pXVar1,0);
        FUN_00219b80(&local_ef0,0);
        if (local_1045 == '\0') {
          FUN_001fe0e8(uVar69,2);
        }
        local_1048 = true;
        FUN_00219b80(&local_ec8,1);
        local_17e8 = 0;
        local_17d4 = 0;
        uVar62 = 0;
      }
      else {
        mpr::RingBuffer::GetFreeArea(this_01,*(BaseList **)(param_1 + 0x120));
        local_1030 = 0;
        if (uVar27 == 0) {
          local_b30 = 0;
          local_b00 = 0;
        }
        else {
          if ((local_b78 - (long)local_b80 >> 8) * -0x3333333333333333 == 0) {
            local_478 = (void *)0x301d02310;
            local_470 = (long *)CONCAT44(local_470._4_4_,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0xc);
          }
          else {
            local_468 = (RingBuffer *)0x0;
            local_478 = (char *)0x0;
            local_470 = (undefined8 *)0x0;
            local_460 = (XavcsMovieWriter *)((ulong)local_460 & 0xffffffff00000000);
            pvVar36 = memcpy(auStack_1750,local_b80,0x500);
            xavcsMovieMeta::SetFirstMetaForNRT
                      (this_02,pvVar36,&local_1034,&local_f50,(long)&local_478 + 4);
            local_478 = (char *)CONCAT44(local_478._4_4_,local_1034);
            FUN_00218b64(param_1,&local_478);
          }
          local_9e0 = local_9e0 & 0xffffff00;
          local_9fc = 0;
          local_a00 = 10;
          local_9f8 = local_9f8 & 0xffffffff00000000;
          local_9e8 = 0;
          local_9f0 = &local_9e0;
          if (*(int *)(param_1 + 0x960) != 0) {
            std::__cxx11::ostringstream::ostringstream((ostringstream *)&local_478,0x10);
            lVar30 = *(long *)((long)local_478 + -0x18);
            *(undefined8 *)((long)&local_468 + lVar30) = 2;
            this_03 = std::operator<<(lVar30,0x30);
            std::ostream::operator<<(this_03,*(int *)(param_1 + 0x960) + 1);
            local_9fc = 0;
            local_9f8 = local_9f8 & 0xffffffff00000000;
            local_a00 = 0xb;
            std::__cxx11::stringbuf::str();
            std::__cxx11::string::operator=((string *)&local_9f0,(string *)&local_ae0);
            std::__cxx11::string::_M_dispose();
            std::__cxx11::ostringstream::~ostringstream((ostringstream *)&local_478);
          }
          if (local_9f0 != (uint *)0x0) {
            local_478 = (void *)0x501d12310;
            strncpy((char *)&local_470,(char *)local_9f0,0x20);
            local_458._4_4_ = local_458._4_4_ & 0xffffff;
            FUN_0021777c(&local_478,0x28);
          }
          FUN_00355c8c(*(undefined8 *)(param_1 + 0x980),(movieManuallyEnteredMeta *)&local_a00);
          iVar23 = (int)*(ulong *)(local_b28[0] + 8);
          if (*(ulong *)(local_b28[0] + 8) < local_17c0) {
            local_b00 = 0;
            local_b30 = (int)local_17c0 - iVar23;
          }
          else {
            local_b30 = 0;
            local_b00 = iVar23 - (int)local_17c0;
          }
          std::__cxx11::string::_M_dispose();
        }
        if (((byte)XVar3 & local_17ac == 0) != 0) {
          pBVar33 = *(BaseList **)(param_1 + 0x120);
          libMp4Signature::GetChunkHashesTargetData(pBVar33,(ulong)local_17e8,aBStack_f70);
          local_17ac = (int)pBVar33;
        }
        local_478 = (void *)0x0;
        local_470 = (long *)0x0;
        local_468 = (RingBuffer *)0x0;
        XavcsMovieWriter::MakeAudioMetaInfoList
                  (param_1,(vector *)local_b28,local_b10[0],(vector *)&local_b58,local_b40[0],
                   (vector *)&local_478);
        in_stack_ffffffffffffe6a0 = (movieManuallyEnteredMeta *)(param_1 + 0x63a);
        in_stack_ffffffffffffe698 = param_1 + 0x9b8;
        in_stack_ffffffffffffe690 = param_1 + 0x9b0;
        in_stack_ffffffffffffe688 = (XavcsMovieWriter *)local_f18;
        in_stack_ffffffffffffe680 = (bool *)&local_1030;
        local_1810 = SUB41(uVar27,0);
        iVar23 = xavcsMovieMeta::WriteMetaInfo
                           (this_02,(vector *)&local_b80,local_b68,__ptr,local_1038,
                            (vector *)&local_478,local_1810,*(BaseList **)(param_1 + 0x120),
                            (uint *)in_stack_ffffffffffffe680,(uint *)in_stack_ffffffffffffe688,
                            (uchar **)in_stack_ffffffffffffe690,(uint *)in_stack_ffffffffffffe698,
                            in_stack_ffffffffffffe6a0);
        if (iVar23 != 0) {
          local_9fc = 2;
          local_a00 = 0x1d82310;
          local_9f8 = CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
          FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x10);
          FUN_001fe0e8(uVar69,iVar23);
        }
        if (local_478 != (void *)0x0) {
          operator_delete(local_478);
        }
        if (((byte)XVar3 & local_17ac == 0) != 0) {
          pBVar33 = *(BaseList **)(param_1 + 0x120);
          libMp4Signature::GetChunkHashesTargetData(pBVar33,(ulong)uVar62,aBStack_f90);
          local_17ac = (int)pBVar33;
        }
        if (iVar23 == 0) {
          pBVar33 = *(BaseList **)(param_1 + 0x110);
          lVar34 = *(long *)(param_1 + 0x120);
          lVar30 = mpr::Codec::GetEsAddrOffset(2,*(undefined4 *)(param_1 + 0x444));
          iVar23 = XavcsMovieWriter::CreateXferLinkedList
                             ((BaseList *)param_1,pBVar33,lVar34,lVar30,
                              *(DmacLib **)(param_1 + 0x858));
          if (iVar23 != 0) {
            local_478 = (void *)0x201e02310;
            local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0x10);
            FUN_001fe0e8(uVar69,iVar23);
          }
        }
        if (((byte)XVar3 & local_17ac == 0) != 0) {
          pBVar33 = *(BaseList **)(param_1 + 0x120);
          libMp4Signature::GetChunkHashesTargetData(pBVar33,(ulong)local_17d4,aBStack_f80);
          local_17ac = (int)pBVar33;
        }
        if (iVar23 == 0) {
          if (*(int *)(param_1 + 0x56c) == 2) {
            iVar23 = FUN_00206460(*(undefined8 *)(param_1 + 0x998));
            if (iVar23 == 0) {
              uVar27 = 2;
              if (*(uint *)(param_1 + 0x56c) < 5) {
                uVar27 = (uint)(byte)(&DAT_003d64b0)[*(uint *)(param_1 + 0x56c)];
              }
              if ((*(int *)(param_1 + 0x568) == 0) || (uVar63 = 2, *(int *)(param_1 + 0x568) == 3))
              {
                uVar63 = 0;
              }
              in_stack_ffffffffffffe680 =
                   (bool *)CONCAT44((int)((ulong)in_stack_ffffffffffffe680 >> 0x20),uVar27);
              iVar23 = SacAccessor::AddMultiList1toN
                                 (*(SacAccessor **)(param_1 + 0x998),
                                  *(undefined8 *)(param_1 + 0x120),*(undefined8 *)(param_1 + 0x118),
                                  *(undefined8 *)(param_1 + 0x858),*(undefined8 *)(param_1 + 0x8b8),
                                  local_17d4,uVar63,uVar27,in_stack_ffffffffffffe680);
              goto joined_r0x00221860;
            }
            local_478 = (char *)0x201e82310;
            local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0x10);
          }
          else {
            pBVar33 = *(BaseList **)(param_1 + 0x118);
            lVar30 = *(long *)(param_1 + 0x120);
            lVar34 = mpr::Codec::GetEsAddrOffset(3,*(undefined4 *)(param_1 + 0x444));
            iVar23 = XavcsMovieWriter::CreateXferLinkedList
                               ((BaseList *)param_1,pBVar33,lVar30,lVar34,
                                *(DmacLib **)(param_1 + 0x858));
joined_r0x00221860:
            if (iVar23 == 0) goto LAB_0022115c;
            local_478._0_4_ = CONCAT22((short)iVar23,0x2310);
            local_478 = (char *)(ulong)CONCAT14(2,(undefined4)local_478);
            local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0x10);
          }
          FUN_001fe0e8(uVar69,iVar23);
        }
LAB_0022115c:
        local_478 = *(char **)(param_1 + 0x108);
        local_470 = &local_b58;
        local_468 = (RingBuffer *)(ulong)*(uint *)(param_1 + 0x444);
        local_460 = param_1 + 0x130;
        local_458 = param_1 + 0x230;
        uStack_450 = param_1 + 0x330;
        local_448 = (uint)pvVar31;
        uStack_444 = (undefined4)((ulong)pvVar31 >> 0x20);
        local_438 = *(undefined8 *)(param_1 + 0x8a0);
        local_430 = *(ulong *)(param_1 + 0x128);
        local_428 = *(ulong **)(param_1 + 0x938);
        local_420 = *(void **)(param_1 + 0x940);
        local_418 = *(ulong *)(param_1 + 0x948);
        local_440 = uVar69;
        iVar23 = FUN_0021cde0(param_1,*(undefined4 *)(param_1 + 0x430),&local_478);
        if (iVar23 != 0) {
          local_9fc = 2;
          local_a00 = 0x2002310;
          local_9f8 = CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
          FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x10);
          FUN_001fe0e8(uVar69,iVar23);
        }
        if (*(int *)(param_1 + 0x56c) == 2) {
          iVar23 = FUN_0020647c(*(undefined8 *)(param_1 + 0x998));
          if (iVar23 != 0) {
            local_478 = (char *)0x202082310;
            local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
            FUN_0021777c(&local_478,0x10);
            FUN_001fe0e8(uVar69,iVar23);
          }
          if (uVar62 != 0) {
            iVar25 = (**(code **)(**(long **)(param_1 + 0x128) + 0x20))();
joined_r0x002218cc:
            iVar23 = 0;
            if (iVar25 != 0) {
              local_478._0_4_ = CONCAT22((short)iVar25,0x2310);
              local_478 = (char *)(ulong)CONCAT14(2,(undefined4)local_478);
              local_470 = (long *)CONCAT44(iVar25,*(undefined4 *)(param_1 + 0x430));
              FUN_0021777c(&local_478,0x10);
              FUN_001fe0e8(uVar69,iVar25);
              iVar23 = iVar25;
            }
          }
        }
        else if (uVar62 != 0 || local_17d4 != 0) {
          iVar25 = (**(code **)(**(long **)(param_1 + 0x128) + 0x20))();
          goto joined_r0x002218cc;
        }
        mpr::Codec::SetVideoInfoReadIndexCount
                  (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),local_b40[0]);
        if (iVar23 != 0) {
          local_478 = (char *)0x202202310;
          local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
          FUN_0021777c(&local_478,0x10);
          FUN_001fe0e8(uVar69,iVar23);
        }
        FUN_00219b80(&local_ef0,local_1860 - local_b40[0]);
        mpr::Codec::SetAudioInfoReadIndexCount
                  (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),
                   local_b10[0] - (local_c68[0] != 0),
                   (bool)(1 < *(int *)(param_1 + 0x568) - 3U & local_1048));
        if (iVar23 != 0) {
          local_478 = (char *)0x202282310;
          local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
          FUN_0021777c(&local_478,0x10);
          FUN_001fe0e8(uVar69,iVar23);
        }
        mpr::Codec::SetMetaInfoReadIndexCount
                  (*(uint *)(param_1 + 0x444),*(uint *)(param_1 + 0x434),local_fa0);
        if (iVar23 != 0) {
          local_478 = (char *)0x202302310;
          local_470 = (long *)CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
          FUN_0021777c(&local_478,0x10);
          FUN_001fe0e8(uVar69,iVar23);
        }
        mpr::RingBuffer::UseMemory(this_01,uVar62 + local_17d4 + local_f18[0]);
        uVar26 = mpr::RingBuffer::GetUsedSize(this_01);
        FUN_00219b80(&local_edc,uVar26);
        local_b88 = *(undefined8 *)(param_1 + 0x108);
        local_b64 = local_1038;
        local_b60 = local_17f0 + local_fe8;
        local_b38 = local_f18[0] + local_b60;
        local_b08 = local_b38 + (ulong)uVar62;
        local_af8 = *(undefined4 *)(param_1 + 0x568);
        local_af0 = uVar69;
        FUN_0021e678(param_1,*(undefined4 *)(param_1 + 0x430),&local_b88);
        local_c00 = local_b68;
        local_bfc = local_b64;
        local_bf8 = local_b60;
        std::
        vector<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>::
        operator=(avStack_bf0,(vector *)&local_b58);
        local_bd8 = local_b40[0];
        local_bd0 = local_b38;
        local_bc8 = local_b30;
        std::
        vector<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>::
        operator=(avStack_bc0,(vector *)local_b28);
        local_ba8 = local_b10[0];
        local_ba0 = local_b08;
        local_b98 = local_b00;
        local_b94 = local_afc;
        local_b90 = local_af8;
        FUN_0021e30c(param_1,&local_c00);
        local_468 = (RingBuffer *)((ulong)local_468 & 0xffffffffffffff00);
        local_478 = (char *)CONCAT44(local_478._4_4_,local_bfc);
        local_470 = (long *)local_bf8;
        XavcsMovieWriter::WriteFixInfo
                  (param_1,*(undefined4 *)(param_1 + 0x444),local_c00,local_bfc,&local_478);
        uVar27 = (uint)((byte)XVar3 & local_17ac == 0);
        if (uVar27 != 0) {
          lVar30 = *plVar29;
          if (*(int *)(param_1 + 0x444) == 0) {
            in_stack_ffffffffffffe688 =
                 (XavcsMovieWriter *)((ulong)in_stack_ffffffffffffe688 & 0xffffffffffffff00);
            in_stack_ffffffffffffe680 =
                 (bool *)CONCAT44((int)((ulong)in_stack_ffffffffffffe680 >> 0x20),
                                  *(uint *)(param_1 + 0x430));
            libMp4Signature::CalcChunkHashes
                      (aBStack_f70,aBStack_f90,aBStack_f80,(BufferAreaInfo *)(param_1 + 0x848),
                       local_1040,local_ff0,*(int *)(param_1 + 0x56c) == 2,
                       (ChunkHashes_t *)(lVar30 + (ulong)*(uint *)(plVar29 + 3) * 0xd8),
                       *(uint *)(param_1 + 0x430),false);
          }
          else {
            libMp4Signature::CalcChunkHashesProxy
                      (aBStack_f70,aBStack_f90,aBStack_f80,(BufferAreaInfo *)(param_1 + 0x848),
                       local_1040,local_ff0,
                       (ChunkHashesProxy_t *)(lVar30 + (ulong)*(uint *)(plVar29 + 3) * 0x6c),
                       *(uint *)(param_1 + 0x430));
          }
          local_17ac = (int)lVar30;
          uVar27 = 0;
          *(int *)((long)plVar29 + 0x1c) = *(int *)((long)plVar29 + 0x1c) + 1;
          uVar61 = (int)plVar29[3] + 1;
          uVar24 = uVar61 - *(uint *)(plVar29 + 2);
          if (uVar61 < *(uint *)(plVar29 + 2)) {
            uVar24 = uVar61;
          }
          *(uint *)(plVar29 + 3) = uVar24;
        }
      }
      uVar68 = uVar68 + (uVar62 + local_17d4 + local_f18[0]);
      if (((byte)XVar3 & local_1048) != 0) {
        uVar43 = (ulong)*(uint *)(param_1 + 0x90c);
        uVar68 = uVar68 + 8;
        uVar44 = 0;
        if (uVar43 != 0) {
          uVar44 = uVar68 / uVar43;
        }
        lVar30 = uVar68 - uVar44 * uVar43;
        uVar61 = *(uint *)(param_1 + 0x90c) - (int)lVar30;
        if (lVar30 == 0) {
          uVar61 = 0;
        }
        local_1878 = XavcsMovieWriter::CreateFreeBoxHeaderInStreamBuffer(param_1,this_01,uVar61);
      }
      local_470 = (long *)CONCAT44(local_470._4_4_,*(undefined4 *)(param_1 + 0x90c));
      local_460 = (XavcsMovieWriter *)
                  CONCAT44(*(undefined4 *)(param_1 + 0x434),(undefined4)local_460);
      local_458._4_4_ = local_edc;
      uStack_450._0_4_ = uStack_ed8;
      uStack_450._4_4_ = local_ed4;
      local_448 = local_ed0;
      uStack_444 = local_ecc;
      local_460 = (XavcsMovieWriter *)((ulong)local_460 & 0xffffffffffffff00);
      local_458._0_4_ = (uint)local_458 & 0xffffff00;
      local_478 = pvVar28;
      local_468 = this_01;
      while( true ) {
        uVar61 = *(uint *)(param_1 + 0x90c);
        uVar44 = (ulong)uVar61;
        if (uVar68 <= uVar44 && uVar44 != uVar68) break;
        if ((uVar44 == uVar68 & local_1048) != 0) {
          local_460 = (XavcsMovieWriter *)CONCAT71(local_460._1_7_,1);
        }
        if (local_1814 == 0) {
          mpr::VpgManager::StartWrite
                    (*(undefined4 *)(param_1 + 0x430),*(undefined4 *)(param_1 + 0x444),&local_1046);
        }
        if ((local_1046 == '\0') && (local_17f8 = local_17f8 + 1, extraout_w0_00 <= local_17f8)) {
          local_17f8 = 0;
          local_458._0_4_ = CONCAT31(local_458._1_3_,1);
        }
        local_440 = uVar69;
        FUN_00218750(param_1,*(undefined4 *)(param_1 + 0x430),&local_478);
        uVar68 = uVar68 - *(uint *)(param_1 + 0x90c);
        local_1814 = uVar71;
      }
      uVar24 = (uint)local_1048;
      if ((uVar24 != 0) && (uVar68 != 0)) {
        XavcsMovieWriter::FillStreamBuffer(param_1,this_01,uVar61 - (int)uVar68);
        uVar26 = mpr::RingBuffer::GetUsedSize(this_01);
        FUN_00219b80(&local_edc,uVar26);
        local_460 = (XavcsMovieWriter *)CONCAT71(local_460._1_7_,1);
        if (local_1814 == 0) {
          mpr::VpgManager::StartWrite
                    (*(undefined4 *)(param_1 + 0x430),*(undefined4 *)(param_1 + 0x444),&local_1046);
        }
        if (local_1046 == '\0') {
          local_17f8 = 0;
          local_458._0_4_ = CONCAT31(local_458._1_3_,1);
        }
        uVar68 = 0;
        local_440 = uVar69;
        FUN_00218750(param_1,*(undefined4 *)(param_1 + 0x430),&local_478);
        local_1814 = uVar24;
      }
      if (local_17d8 == 0) break;
      uVar44 = (ulong)(uVar62 + local_17d4 + local_f18[0]);
      local_17f0 = local_17f0 + uVar44;
      local_1838 = local_1838 + uVar44;
      local_1820 = local_1820 + (ulong)local_f60;
      pBVar33 = (BaseList *)mpr::Codec::GetEncStatusVideoFrameCounter();
      if ((((local_1848 == 0) && (*(int *)(param_1 + 0x444) == 0)) &&
          (0.0 < (float)uVar65 / (float)uVar67)) &&
         (uVar44 = (ulong)pBVar33 & 0xffffffff,
         pBVar33 = (BaseList *)((ulong)*(ushort *)(param_1 + 0x24) * 0x3c + -0x3c),
         (float)pBVar33 <= (float)uVar44 / ((float)uVar65 / (float)uVar67))) {
        local_9fc = 3;
        local_a00 = 0x2382310;
        local_9f8 = CONCAT44(local_9f8._4_4_,*(undefined4 *)(param_1 + 0x430));
        FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0xc);
        (**(code **)(param_1 + 0x38))
                  (*(undefined8 *)(param_1 + 0x40),0x40000005,0,0,0,*(undefined8 *)(param_1 + 0x48))
        ;
        local_1848 = local_17d8;
      }
      if (local_1048 == false) {
        if (local_17e4 == 0) {
          uVar71 = *(uint *)(param_1 + 0x908);
          if ((uVar71 != 0xffffffff) && (*(int *)(param_1 + 0x444) == 0)) {
            if (((ulong)uVar71 <= local_1838 / 1000000) ||
               (pBVar33 = (BaseList *)((ulong)uVar71 - local_1838 / 1000000),
               pBVar33 < (BaseList *)0x14)) {
              pBVar33 = (BaseList *)FUN_0021b960(param_1,pXVar1,local_101c,uVar69);
              local_17e4 = (uint)pBVar33 & 0xff;
              if (((ulong)pBVar33 & 0xff) == 0) {
                pBVar33 = *(BaseList **)(param_1 + 0x38);
                if (pBVar33 != (BaseList *)0x0) {
                  local_ae0 = *(uint *)(param_1 + 0x430);
                  local_9fc = 3;
                  local_9f8 = CONCAT44(local_9f8._4_4_,local_ae0);
                  local_a00 = 0x2402310;
                  FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0xc);
                  (**(code **)(param_1 + 0x38))
                            (*(undefined8 *)(param_1 + 0x40),0x40000003,0,&local_ae0,0,
                             *(undefined8 *)(param_1 + 0x48));
                }
                goto LAB_00221abc;
              }
              local_1045 = '\x01';
            }
          }
        }
        else {
LAB_00221abc:
          local_17e4 = local_17d8;
        }
      }
      if ((*(int *)(param_1 + 0x444) == 0) && (local_185c != 0)) {
        FUN_0022c6e0(*(undefined4 *)(param_1 + 0x430));
        local_185c = (uint)pBVar33 & 0xff;
      }
    }
    if ((param_1[0xcd8] == (XavcsMovieWriter)0x0) &&
       (uVar27 = FUN_00219b00(param_1,0x10000007), (uVar27 & 0xff) != 0)) {
      FUN_00219a80(param_1,&local_1044,&local_1000);
      FUN_00208090(this_02,*local_1000,*(undefined4 *)(local_1000 + 1),param_1 + 0xcd9,8000,
                   param_1 + 0x2c1c);
      if (uVar27 == 0) {
        if (*(int *)(param_1 + 0x2c1c) != 0) {
          param_1[0xcd8] = (XavcsMovieWriter)0x1;
        }
      }
      else {
        local_478 = (void *)0x212502310;
        local_470 = (long *)CONCAT44(uVar27,*(undefined4 *)(param_1 + 0x434));
        FUN_0021777c(&local_478,0x10);
      }
      free(local_1000);
    }
    if (XVar3 != (XavcsMovieWriter)0x0) {
      libMp4Signature::ReMunmapStreamBuffer
                ((BufferAreaInfo *)(param_1 + 0x848),local_1040,local_103c,local_ff0);
    }
    XVar4 = param_1[0x553];
    pXVar1 = param_1 + 0x54e;
    uVar9 = *(undefined2 *)pXVar1;
    XVar5 = param_1[0x554];
    uVar10 = *(undefined2 *)(param_1 + 0x550);
    uVar27 = *(uint *)pXVar1;
    XVar6 = param_1[0x555];
    XVar7 = param_1[0x552];
    uVar63 = *(undefined8 *)pXVar1;
    XVar8 = param_1[0x556];
    mpr::time::GetLTM((LocalTime *)&local_fb0);
    uVar19 = uStack_fa9;
    uVar18 = uStack_faa;
    uVar17 = uStack_fab;
    uVar16 = uStack_fac;
    uVar15 = uStack_fae;
    uVar14 = local_fb0;
    local_e78[0] = 0;
    local_eb0 = 0;
    local_e80 = 0;
    uVar20 = (undefined1)local_fa8;
    local_e88 = local_e78;
    uStack_eaf = 0;
    uStack_ea8 = 0;
    uStack_ea7 = 0;
    local_e9f = 0;
    uStack_e97 = 0;
    FUN_00217bc4(local_d80);
    FUN_00217c00(local_c68);
    mpr::thread::normalLock::normalLock(anStack_e60,0);
    local_e68 = (local_e68 >> 8 & 0xffffff) << 8;
    mpr::thread::normalLock::lock(this_00);
    local_e58 = *(undefined8 *)(param_1 + 0x2c30);
    uStack_e50 = *(undefined8 *)(param_1 + 0x2c38);
    local_e68 = CONCAT71(local_e68._1_7_,param_1[0x2c20]);
    local_e68 = CONCAT44(*(undefined4 *)(param_1 + 0x2c24),(undefined4)local_e68);
    local_e48 = *(undefined8 *)(param_1 + 0x2c40);
    uStack_e40 = *(undefined8 *)(param_1 + 0x2c48);
    local_e38 = *(undefined8 *)(param_1 + 0x2c50);
    uStack_e30 = *(undefined8 *)(param_1 + 0x2c58);
    local_e28 = *(undefined8 *)(param_1 + 0x2c60);
    param_1[0x2c20] = (XavcsMovieWriter)0x0;
    *(undefined4 *)(param_1 + 0x2c24) = 0;
    mpr::thread::normalLock::unlock(this_00);
    if (param_1[0x438] == (XavcsMovieWriter)0x0) {
      local_d80[0] = local_d80[0] & 0xffffffffffffff00;
    }
    else if (*(int *)(param_1 + 0x444) == 0) {
      FUN_00217da8(param_1,param_1 + 0x640,local_d80,local_c68);
    }
    else {
      local_eb0 = 1;
      FUN_0021ad5c(param_1,param_1 + 0x648,&local_e88);
      uStack_ea7 = *(undefined8 *)(param_1 + 0x78c);
      local_e9f = *(undefined8 *)(param_1 + 0x794);
      uStack_e97 = *(undefined8 *)(param_1 + 0x79c);
      uStack_eaf = (undefined7)*(undefined8 *)(param_1 + 0x784);
      uStack_ea8 = (undefined1)((ulong)*(undefined8 *)(param_1 + 0x784) >> 0x38);
    }
    local_f10 = local_f00;
    local_f00[0] = 0;
    uVar62 = local_f18[0] >> 8;
    local_f18[0] = local_f18[0] & 0xffffff00;
    local_f08 = 0;
    if ((param_1[0x5a5] != (XavcsMovieWriter)0x0) && (param_1[0xc30] != (XavcsMovieWriter)0x0)) {
      local_f18[0] = CONCAT31((int3)uVar62,1);
      std::__cxx11::string::operator=((string *)&local_f10,(char *)(param_1 + 0xc30));
    }
    local_ae0 = 0;
    local_adc = (XavcsMovieWriter)0x0;
    local_adb = (XavcsMovieWriter)0x0;
    local_ada = (XavcsMovieWriter)0x0;
    local_ad9 = (XavcsMovieWriter)0x0;
    local_ad8 = (local_ad8 >> 8 & 0xff) << 8;
    local_ad4 = 0;
    local_ad0._3_1_ = (undefined1)(local_ad0 >> 0x18);
    local_ad0._0_3_ = 0;
    FUN_00217bc4(auStack_ac8);
    local_a50 = local_a40;
    local_a40[0] = 0;
    local_a48 = 0;
    local_a77 = 0;
    uStack_a6f = 0;
    local_a67 = 0;
    uStack_a5f = 0;
    local_a20 = local_a10;
    local_a10[0] = 0;
    local_a30 = 3;
    local_a28 = (XavcsMovieWriter)0x0;
    local_ad8 = CONCAT31(local_ad8._1_3_,XVar8);
    local_a2c = 0;
    local_ad8 = CONCAT22(uVar14,(undefined2)local_ad8);
    local_a18 = 0;
    local_ad4 = CONCAT13(uVar17,CONCAT12(uVar16,uVar15));
    local_ad0._0_3_ = CONCAT12(uVar20,CONCAT11(uVar19,uVar18));
    local_acc = local_102c;
    local_ae0 = uVar27;
    local_adc = XVar7;
    local_adb = XVar4;
    local_ada = XVar5;
    local_ad9 = XVar6;
    memcpy(auStack_ac8,local_d80,0x4d);
    local_a78 = local_eb0;
    lVar30 = 0;
    do {
      lVar34 = lVar30 + 1;
      *(undefined1 *)((long)&local_a77 + lVar30) = *(undefined1 *)((long)&uStack_eaf + lVar30);
      lVar30 = lVar34;
    } while (lVar34 != 0x20);
    std::__cxx11::string::_M_assign((string *)&local_a50);
    local_a30 = 3;
    if ((char)local_e68 != '\0') {
      FUN_0021b218(local_e68._4_4_,&local_478);
      local_a30 = (undefined4)local_478;
    }
    local_a2c = 0;
    local_a28 = local_f18[0]._0_1_;
    std::__cxx11::string::_M_assign((string *)&local_a20);
    uVar37 = *(undefined8 *)(param_1 + 0x980);
    FUN_00353274(uVar37,&local_ae0);
    extraout_w0_03 = (int)uVar37;
    if (extraout_w0_03 != 0) {
      local_478 = (void *)0x202482310;
      local_470 = (long *)CONCAT44(extraout_w0_03,*(undefined4 *)(param_1 + 0x434));
      FUN_0021777c(&local_478,0x10);
    }
    local_100c = 0;
    mpr::pconv::SetUInt32be2le(&local_100c,local_1030);
    uVar37 = *(undefined8 *)(param_1 + 0x980);
    FUN_00353554(uVar37,local_102c + -1,local_100c,2);
    if ((int)uVar37 != 0) {
      local_478 = (void *)0x202502310;
      local_470 = (long *)CONCAT44((int)uVar37,*(undefined4 *)(param_1 + 0x434));
      FUN_0021777c(&local_478,0x10);
    }
    if (param_1[0x5f8] != (XavcsMovieWriter)0x0) {
      local_468 = (RingBuffer *)0x0;
      local_470 = &local_460;
      param_1[0x617] = (XavcsMovieWriter)0x0;
      local_460 = (XavcsMovieWriter *)((ulong)local_460 & 0xffffffffffffff00);
      uStack_450 = (XavcsMovieWriter *)&local_440;
      local_448 = 0;
      uStack_444 = 0;
      local_440 = local_440 & 0xffffffffffffff00;
      local_428 = &local_418;
      local_420 = (void *)0x0;
      local_418 = local_418 & 0xffffffffffffff00;
      local_478 = (char *)((ulong)local_478 & 0xffffffffffffff00);
      local_430 = local_430 & 0xffffffffffffff00;
      std::__cxx11::string::operator=((string *)&uStack_450,(char *)(param_1 + 0x5f8));
      uVar37 = *(undefined8 *)(param_1 + 0x980);
      FUN_00353c20(uVar37,&local_478);
      if ((int)uVar37 != 0) {
        local_9fc = 2;
        local_a00 = 0x2492310;
        local_9f8 = CONCAT44((int)uVar37,*(undefined4 *)(param_1 + 0x434));
        FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x10);
      }
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    if ((XVar3 == (XavcsMovieWriter)0x0) || (*(int *)(param_1 + 0x5ec) != 0)) {
LAB_00222850:
      if (((byte)XVar3 & local_17ac == 0) != 0) {
        local_a00 = 1;
        if (*(int *)(param_1 + 0x5ec) == 0) {
          local_a00 = 0x101;
        }
        local_9fc = CONCAT31(local_9fc._1_3_,param_1[0x5b8]);
        local_9f8 = *(ulong *)(param_1 + 0x5c0);
        uVar37 = *(undefined8 *)(param_1 + 0x980);
        FUN_00353a78(uVar37,(movieManuallyEnteredMeta *)&local_a00);
        extraout_w0_06 = (int)uVar37;
        if (extraout_w0_06 != 0) {
          local_478 = (void *)0x202512310;
          local_470 = (long *)CONCAT44(extraout_w0_06,*(undefined4 *)(param_1 + 0x434));
          FUN_0021777c(&local_478,0x10);
        }
        local_17ac = 0;
      }
    }
    else {
      iVar23 = 0x22;
      do {
        FUN_0021763c(&local_478,param_1 + 0x448);
        FUN_002afde0(&local_478,&local_f60);
        std::__cxx11::string::_M_dispose();
        if ((int)uVar37 == 0) goto LAB_00222850;
        usleep(30000);
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
      local_478 = (void *)0x402522310;
      FUN_0021777c(&local_478,8);
      local_17ac = 2;
    }
    uVar37 = *(undefined8 *)(param_1 + 0x980);
    local_1008 = 0;
    FUN_0035353c(uVar37,*(undefined8 *)(param_1 + 0x918),0x200000,&local_1008);
    extraout_w0_04 = (int)uVar37;
    if (extraout_w0_04 != 0) {
      local_478 = (void *)0x202582310;
      local_470 = (long *)CONCAT44(extraout_w0_04,*(undefined4 *)(param_1 + 0x434));
      FUN_0021777c(&local_478,0x10);
    }
    mpr::VpgManager::StopWrite(*(undefined4 *)(param_1 + 0x430),*(undefined4 *)(param_1 + 0x444));
    local_470 = *(long **)(param_1 + 0x108);
    local_d8 = (void *)0x0;
    local_d0 = 0;
    local_468 = (RingBuffer *)local_17f0;
    local_458._0_4_ = local_fa8;
    uStack_450._0_4_ = (undefined4)*(undefined8 *)(param_1 + 0x918);
    uStack_450._4_4_ = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x918) >> 0x20);
    local_448 = local_1008;
    local_118 = CONCAT44(uStack_ec4,local_ec8);
    uStack_110 = local_ec0;
    local_108 = local_eb8;
    local_100 = *(undefined8 *)(param_1 + 0x860);
    uStack_f8 = *(undefined8 *)(param_1 + 0x868);
    local_f0 = *(undefined8 *)(param_1 + 0x870);
    local_e0 = param_1[0xcd8];
    local_478 = pvVar28;
    local_440 = uVar41;
    local_120 = pvVar31;
    local_e8 = uVar69;
    if (local_e0 != (XavcsMovieWriter)0x0) {
      pvVar28 = operator_new__((ulong)*(uint *)(param_1 + 0x2c1c));
      uVar27 = *(uint *)(param_1 + 0x2c1c);
      local_d8 = memcpy(pvVar28,param_1 + 0xcd9,(ulong)uVar27);
      local_d0 = uVar27;
    }
    local_c8 = (void *)0x0;
    local_c0 = 0;
    local_cc = 0;
    if ((param_1[0x5a5] != (XavcsMovieWriter)0x0) && (param_1[0xc30] != (XavcsMovieWriter)0x0)) {
      pvVar28 = operator_new__((ulong)*(uint *)(param_1 + 0xc70));
      uVar27 = *(uint *)(param_1 + 0xc70);
      local_c8 = memcpy(pvVar28,*(void **)(param_1 + 0xc28),(ulong)uVar27);
      local_cc = 1;
      local_c0 = uVar27;
    }
    local_b8 = *(int *)(param_1 + 0x56c) == 2;
    local_b7 = *(int *)(param_1 + 0x444) != 0;
    local_8 = local_fe8;
    if (XVar3 == (XavcsMovieWriter)0x0) {
      local_b6 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = 0;
      uStack_a8 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      local_40 = 0;
      uStack_38 = 0;
      local_50 = 0;
      uStack_48 = 0;
      local_30 = 0;
      local_28 = 0;
      *(undefined4 *)((long)plVar29 + 0x14) = 0;
      *(undefined4 *)(plVar29 + 3) = 0;
    }
    else {
      if (local_17ac != 0) {
        *(undefined4 *)((long)plVar29 + 0x1c) = 0;
      }
      local_b6 = 1;
      puVar38 = *(undefined8 **)(param_1 + 0x5f0);
      local_b0 = *puVar38;
      uStack_a8 = puVar38[1];
      local_a0 = puVar38[2];
      uStack_98 = puVar38[3];
      local_90 = puVar38[4];
      uStack_88 = puVar38[5];
      local_80 = puVar38[6];
      uStack_78 = puVar38[7];
      local_68 = (ulong)*(uint *)(param_1 + 0x5d8);
      local_60 = *(undefined8 *)(param_1 + 0x5e0);
      local_58 = *(undefined4 *)(param_1 + 0x5b4);
      local_50 = *(undefined8 *)(param_1 + 0x5b8);
      uStack_48 = *(undefined8 *)(param_1 + 0x5c0);
      local_40 = *(undefined8 *)(param_1 + 0x5c8);
      uStack_38 = *(undefined8 *)(param_1 + 0x5d0);
      local_30 = *(undefined8 *)(param_1 + 0x54e);
      local_28 = *(undefined4 *)(param_1 + 0x556);
      local_20 = CONCAT44(uStack_f5c,local_f60);
      uStack_18 = uStack_f58;
      local_10 = *(undefined4 *)(param_1 + 0x5ec);
      *(int *)((long)plVar29 + 0x14) = (int)plVar29[3];
      local_70 = lVar40;
    }
    *(undefined4 *)((long)plVar29 + 0x1c) = 0;
    memcpy(&local_438,param_1 + 0x448,0x106);
    memcpy(auStack_332,param_1 + 0x9d0,0x106);
    memcpy(auStack_22c,param_1 + 0xad6,0x106);
    local_bc = local_1878;
    FUN_002187d0(param_1,*(undefined4 *)(param_1 + 0x430),&local_478);
    free(__ptr);
    if (*(int *)(param_1 + 0x56c) == 2) {
      uVar37 = *(undefined8 *)(param_1 + 0x998);
      FUN_0020643c(uVar37,*(undefined8 *)(param_1 + 0x8a8),1,*(undefined8 *)(param_1 + 0x848));
      extraout_w0_05 = (int)uVar37;
      if (extraout_w0_05 != 0) {
        local_a00 = 0x2602310;
        local_9f8 = CONCAT44(extraout_w0_05,*(undefined4 *)(param_1 + 0x430));
        local_9fc = 2;
        FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x10);
      }
      FUN_00206388(*(undefined8 *)(param_1 + 0x998));
      if (*(long **)(param_1 + 0x998) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x998) + 8))();
      }
      *(undefined8 *)(param_1 + 0x998) = 0;
    }
    pvVar28 = *(void **)(param_1 + 0x9a0);
    if (pvVar28 != (void *)0x0) {
      FUN_001fb8a0(pvVar28);
      operator_delete(pvVar28,0x30);
    }
    pvVar28 = *(void **)(param_1 + 0x9a8);
    *(undefined8 *)(param_1 + 0x9a0) = 0;
    if (pvVar28 != (void *)0x0) {
      FUN_001fb718(pvVar28);
      operator_delete(pvVar28,0x38);
    }
    *(undefined8 *)(param_1 + 0x9a8) = 0;
    if (*(long **)(param_1 + 0x128) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x128) + 8))();
    }
    *(undefined8 *)(param_1 + 0x128) = 0;
    if (*(long *)(param_1 + 0x38) != 0) {
      local_1004 = 0;
      mpr::pconv::SetUInt32be2le(&local_1004,local_1034);
      local_9e0 = 0x3d;
      local_9b4 = 0;
      local_9ac = 0;
      local_9a8 = 0;
      local_9a0 = 0;
      memset(auStack_99c,0,0x80);
      local_914 = 0;
      local_91c = 0;
      local_9f0 = (uint *)(local_fe8 + local_17f0);
      local_910 = 0;
      local_9f8 = *(ulong *)(param_1 + 0x988);
      local_a00 = local_100c;
      local_9d8 = local_100c;
      local_9dc = local_1004;
      uVar27 = 0;
      local_9d4 = local_f50;
      uStack_9cc = uStack_f48;
      local_9c4 = local_f40;
      local_9e8._0_5_ = CONCAT14(local_1047,*(undefined4 *)(param_1 + 0x430));
      local_9b8 = local_1008;
      local_9bc = local_102c;
      local_fc8 = CONCAT11(local_fc8._1_1_,XVar8);
      local_fd0 = uVar9;
      uStack_fce = uVar10;
      XStack_fcc = XVar7;
      XStack_fcb = XVar4;
      XStack_fca = XVar5;
      XStack_fc9 = XVar6;
      FUN_0021999c(param_1,uVar63,local_fc8,&local_9b4);
      uVar61 = 0;
      local_fc0 = uVar14;
      uStack_fbe = uVar15;
      uStack_fbc = uVar16;
      uStack_fbb = uVar17;
      uStack_fba = uVar18;
      uStack_fb9 = uVar19;
      local_fb8 = CONCAT11(local_fb8._1_1_,uVar20);
      FUN_0021999c(param_1,CONCAT17(uVar19,CONCAT16(uVar18,CONCAT15(uVar17,CONCAT14(uVar16,CONCAT22(
                                                  uVar15,uVar14))))),local_fb8,&local_9a8);
      XavcsMovieWriter::ConvertMPFPictureQualityLevel
                (param_1,*(undefined4 *)(param_1 + 0x560),local_dbc,local_dc8,&local_9e0);
      pvVar28 = memcpy(auStack_17a0,auStack_dd0,0x50);
      XavcsMovieWriter::ConvertVideoCodecTypeName
                (param_1,pvVar28,*(undefined4 *)(param_1 + 0x444),auStack_99c);
      uVar65 = local_91c & 0xff;
      uVar52 = 0;
      uVar54 = 0;
      uVar47 = (uint)local_914._1_1_;
      uVar56 = 0;
      uVar58 = 0;
      uVar60 = 0;
      uVar49 = (uint)(byte)local_914;
      uVar51 = (uint)local_91c._7_1_;
      uVar53 = (uint)local_91c._6_1_;
      uVar55 = (uint)local_91c._5_1_;
      uVar45 = 0;
      uVar57 = (uint)local_91c._4_1_;
      uVar48 = 0;
      uVar59 = (uint)local_91c._3_1_;
      uVar50 = 0;
      uVar24 = (uint)local_91c._2_1_;
      uVar62 = (uint)local_91c._1_1_;
      for (puVar39 = *(uint **)(param_1 + 0xc08); puVar39 != *(uint **)(param_1 + 0xc10);
          puVar39 = puVar39 + 0xc) {
        if (*puVar39 < 10) {
          uVar72 = uVar22 & 0xff;
          switch(*puVar39) {
          case 0:
            uVar27 = uVar71;
            uVar62 = uVar71;
            break;
          case 1:
            uVar61 = uVar72;
            uVar24 = uVar72;
            break;
          case 2:
            uVar60 = uVar72;
            uVar59 = uVar72;
            break;
          case 3:
            uVar58 = uVar72;
            uVar57 = uVar72;
            break;
          case 4:
            uVar56 = uVar72;
            uVar55 = uVar72;
            break;
          case 5:
            uVar54 = uVar72;
            uVar53 = uVar72;
            break;
          case 6:
            uVar52 = uVar72;
            uVar51 = uVar72;
            break;
          case 7:
            uVar50 = uVar72;
            uVar49 = uVar72;
            break;
          case 8:
            uVar48 = uVar72;
            uVar47 = uVar72;
            break;
          case 9:
            uVar65 = (ulong)uVar70;
            uVar45 = uVar70;
          }
        }
      }
      if (uVar27 != 0) {
        local_91c._0_2_ = CONCAT11((char)uVar62,(undefined1)local_91c);
      }
      if (uVar61 != 0) {
        local_91c._0_3_ = CONCAT12((char)uVar24,(undefined2)local_91c);
      }
      if (uVar60 != 0) {
        local_91c._0_4_ = CONCAT13((char)uVar59,(undefined3)local_91c);
      }
      if (uVar58 != 0) {
        local_91c._0_5_ = CONCAT14((char)uVar57,(undefined4)local_91c);
      }
      if (uVar56 != 0) {
        local_91c._0_6_ = CONCAT15((char)uVar55,(undefined5)local_91c);
      }
      if (uVar54 != 0) {
        local_91c._0_7_ = CONCAT16((char)uVar53,(undefined6)local_91c);
      }
      if (uVar52 != 0) {
        local_91c = CONCAT17((char)uVar51,(undefined7)local_91c);
      }
      if (uVar50 != 0) {
        local_914 = CONCAT11(local_914._1_1_,(char)uVar49);
      }
      if (uVar48 != 0) {
        local_914 = CONCAT11((char)uVar47,(byte)local_914);
      }
      if (uVar45 != 0) {
        local_91c = CONCAT71(local_91c._1_7_,(char)uVar65);
      }
      local_f9b = 0;
      local_f9a = 0;
      local_f99 = 0;
      local_910 = CONCAT71(local_910._1_7_,(char)local_e68);
      local_910 = CONCAT44(local_e68._4_4_,(undefined4)local_910);
      local_f9c = 3;
      local_fa0 = 0x2682310;
      local_f98 = *(undefined4 *)(param_1 + 0x430);
      FUN_0021777c(&local_fa0,0xc);
      (**(code **)(param_1 + 0x38))
                (*(undefined8 *)(param_1 + 0x40),0x40000001,0,(movieManuallyEnteredMeta *)&local_a00
                 ,0,*(undefined8 *)(param_1 + 0x48));
    }
    *(undefined8 *)(param_1 + 0x108) = 0;
    iVar23 = FUN_00209d00(this_02);
    if (iVar23 != 0) {
      local_9fc = 2;
      local_a00 = 0x2702310;
      local_9f8 = CONCAT44(iVar23,*(undefined4 *)(param_1 + 0x430));
      FUN_0021777c((movieManuallyEnteredMeta *)&local_a00,0x10);
    }
    FUN_00207e84(this_02);
    operator_delete(this_02,0x5cf0);
    *(undefined8 *)(param_1 + 0x980) = 0;
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::_M_dispose();
    mpr::thread::normalLock::~normalLock(anStack_e60);
    std::__cxx11::string::_M_dispose();
    std::
    _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
    ::~_Vector_base((_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
                     *)avStack_bc0);
    std::
    _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
    ::~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                     *)avStack_bf0);
    std::
    _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
    ::~_Vector_base((_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
                     *)local_b28);
    std::
    _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
    ::~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                     *)&local_b58);
    FUN_0021b940(&local_b80);
    FUN_00218604(asStack_830);
    FUN_00218604(asStack_d30);
    std::__cxx11::string::_M_dispose();
  } while( true );
}

