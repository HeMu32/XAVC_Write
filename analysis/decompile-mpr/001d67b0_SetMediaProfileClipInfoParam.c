// mpr::SetMediaProfileClipInfoParam
// Ghidra address: 001d67b0

/* mpr::SetMediaProfileClipInfoParam(mpr::MovieRecInfo&, mpr::RecMngInfo&,
   LibMediaProfileIf::LibMediaProfile::T_MPF_CLIP_INFO*) */

undefined4
mpr::SetMediaProfileClipInfoParam
          (MovieRecInfo *param_1,RecMngInfo *param_2,T_MPF_CLIP_INFO *param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  long lVar8;
  char local_90;
  undefined1 uStack_8f;
  undefined1 uStack_8e;
  undefined1 uStack_8d;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  char local_80 [128];
  
  builtin_strncpy(local_80,"\x10!p\a\x04",6);
  local_80[6] = 0;
  local_80[7] = 0;
  FUN_001c9f24(local_80,8);
  memset(local_80,0,0x80);
  iVar2 = *(int *)(param_1 + 0x1d0);
  lVar8 = (long)iVar2;
  GetFileNameFromPath((char *)(param_2 + 0x284),local_80);
  memcpy(param_3,local_80,0x80);
  snprintf((char *)(param_3 + 0x80),0x89,"./CLIP/%s",local_80);
  puVar4 = PTR_g_videoParamComb_00401a70;
  *(undefined4 *)(param_3 + 0x10c) = *(undefined4 *)(param_2 + 0x40);
  uVar5 = *(undefined2 *)(puVar4 + lVar8 * 0x18 + 4);
  *(undefined2 *)(param_3 + 0x112) = *(undefined2 *)(puVar4 + lVar8 * 0x18 + 6);
  *(undefined2 *)(param_3 + 0x110) = uVar5;
  uVar6 = GetAudioTypeForMediaPro(*(uint *)(param_1 + 0x1e4));
  *(undefined4 *)(param_3 + 0x114) = uVar6;
  pconv::ConvertFrameRateForCodec(*(undefined4 *)(param_1 + 0x1d8),&local_8c,&local_90,&uStack_8f);
  *(undefined4 *)(param_3 + 0x118) = local_8c;
  param_3[0x11c] = (T_MPF_CLIP_INFO)(local_90 == '\0');
  *(undefined4 *)(param_3 + 0x120) = *(undefined4 *)(param_2 + 100);
  uVar5 = GetAudioOutputChannel((uchar)param_1[0x1e8]);
  *(undefined2 *)(param_3 + 0x124) = uVar5;
  GetVideoAspect(iVar2);
  uVar6 = ConvertVideoAspectForAspectRatio();
  *(undefined4 *)(param_3 + 300) = 0;
  *(undefined4 *)(param_3 + 0x128) = uVar6;
  uVar1 = *(undefined8 *)(param_2 + 0x120);
  *(undefined8 *)(param_3 + 0x130) = *(undefined8 *)(param_2 + 0x118);
  *(undefined8 *)(param_3 + 0x138) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x130);
  *(undefined8 *)(param_3 + 0x140) = *(undefined8 *)(param_2 + 0x128);
  *(undefined8 *)(param_3 + 0x148) = uVar1;
  *(undefined4 *)(param_3 + 0x154) = 3;
  if (param_2[0x10c] != (RecMngInfo)0x0) {
    ConvClipStatusTypeSidb2Mpf(*(undefined4 *)(param_2 + 0x110),&local_88);
    *(undefined4 *)(param_3 + 0x154) = local_88;
  }
  *(undefined8 *)(param_3 + 0x158) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(param_3 + 0x160) = *(undefined8 *)(param_2 + 0x8a8);
  *(undefined4 *)(param_3 + 0x168) = *(undefined4 *)(param_2 + 0x8b0);
  uVar6 = ConvertPictureQualityDefStructToMpr(*(uint *)(param_1 + 0x1d4));
  *(int *)(param_3 + 0x170) = iVar2;
  puVar4 = PTR_g_videoParamComb_00401a70;
  *(undefined4 *)(param_3 + 0x16c) = uVar6;
  uVar6 = ConvertVideoCodecToCodec
                    (*(undefined4 *)(puVar4 + lVar8 * 0x18),
                     *(undefined4 *)(puVar4 + lVar8 * 0x18 + 0x14));
  *(undefined4 *)(param_3 + 0x6a8) = uVar6;
  memcpy(param_3 + 0x6ac,param_2 + 0x80,0x41);
  *(undefined4 *)(param_3 + 0x198) = 2;
  GetFileNameFromPath((char *)(param_2 + 0x490),local_80);
  snprintf((char *)(param_3 + 0x19c),0x89,"./CLIP/%s",local_80);
  *(undefined4 *)(param_3 + 0x228) = 1;
  uVar6 = GetFileNameFromPath((char *)(param_2 + 0x596),local_80);
  snprintf((char *)(param_3 + 0x22c),0x89,"./THMBNL/%s",local_80);
  *(undefined4 *)(param_3 + 0x2b8) = 5;
  if (param_2[0x140] == (RecMngInfo)0x0) {
    *(undefined4 *)(param_3 + 0x46c) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x200);
    *(undefined4 *)(param_3 + 0x46c) = 1;
    uVar6 = GetFileNameFromPath((char *)(param_2 + 0x38a),local_80);
    lVar8 = (long)iVar2 * 0x18;
    snprintf((char *)(param_3 + 0x470),0x89,"./SUB/%s",local_80);
    uVar5 = *(undefined2 *)(puVar4 + lVar8 + 4);
    *(undefined4 *)(param_3 + 0x4fc) = 4;
    *(undefined4 *)(param_3 + 0x500) = *(undefined4 *)(param_2 + 0x180);
    uVar3 = *(undefined2 *)(puVar4 + lVar8 + 6);
    *(undefined2 *)(param_3 + 0x504) = uVar5;
    *(undefined2 *)(param_3 + 0x506) = uVar3;
    uVar7 = GetAudioTypeForMediaPro(*(uint *)(param_1 + 0x214));
    *(undefined4 *)(param_3 + 0x508) = uVar7;
    pconv::ConvertFrameRateForCodec
              (*(undefined4 *)(param_1 + 0x208),&local_88,&uStack_8e,&uStack_8d);
    *(undefined4 *)(param_3 + 0x50c) = local_88;
    uVar5 = GetAudioOutputChannel((uchar)param_1[0x218]);
    *(undefined2 *)(param_3 + 0x510) = uVar5;
    GetVideoAspect(iVar2);
    uVar7 = ConvertVideoAspectForAspectRatio();
    *(undefined4 *)(param_3 + 0x514) = uVar7;
    uVar1 = *(undefined8 *)(param_2 + 0x260);
    *(undefined8 *)(param_3 + 0x518) = *(undefined8 *)(param_2 + 600);
    *(undefined8 *)(param_3 + 0x520) = uVar1;
    uVar1 = *(undefined8 *)(param_2 + 0x270);
    *(undefined8 *)(param_3 + 0x528) = *(undefined8 *)(param_2 + 0x268);
    *(undefined8 *)(param_3 + 0x530) = uVar1;
    uVar7 = ConvertVideoCodecToCodec
                      (*(undefined4 *)(puVar4 + lVar8),*(undefined4 *)(puVar4 + lVar8 + 0x14));
    *(undefined4 *)(param_3 + 0x53c) = uVar7;
    uVar7 = ConvertPictureQualityDefStructToMpr(*(uint *)(param_1 + 0x204));
    *(undefined4 *)(param_3 + 0x540) = uVar7;
    *(int *)(param_3 + 0x544) = iVar2;
    memcpy(param_3 + 0x548,param_2 + 0x1c0,0x41);
  }
  local_83 = 0;
  local_84 = 4;
  local_82 = 0;
  local_81 = 0;
  local_88 = 0x77f2110;
  FUN_001c9f24(&local_88,8);
  return uVar6;
}

