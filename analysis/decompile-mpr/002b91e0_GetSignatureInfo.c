// libMp4Signature::GetSignatureInfo
// Ghidra address: 002b91e0

/* WARNING: Type propagation algorithm not settling */
/* libMp4Signature::GetSignatureInfo(std::__cxx11::string const&, unsigned int, bool&, bool&,
   libMp4Signature::userType_t&, libMp4Signature::BufferArea_t&, mpr::TrustTime&,
   libMp4Signature::BufferArea_t&) */

undefined4
libMp4Signature::GetSignatureInfo
          (string *param_1,uint param_2,bool *param_3,bool *param_4,userType_t *param_5,
          BufferArea_t *param_6,TrustTime *param_7,BufferArea_t *param_8)

{
  uint uVar1;
  uint7 uVar2;
  uint5 uVar3;
  byte bVar4;
  uint *******pppppppuVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  uint *******pppppppuVar14;
  ulong *puVar15;
  void *pvVar16;
  long lVar17;
  undefined2 uVar18;
  uint *puVar19;
  uint *******pppppppuVar20;
  undefined8 uVar21;
  uint *puVar22;
  uint *puVar23;
  long lVar24;
  undefined8 *puVar25;
  undefined1 *puVar26;
  uchar *puVar27;
  ulong uVar28;
  ulong uVar29;
  void *pvVar30;
  long lVar31;
  uint uVar32;
  ulong uVar33;
  char *pcVar34;
  undefined4 uVar35;
  ulong uVar36;
  uint uVar37;
  ulong uVar38;
  uint *local_860;
  int local_854;
  uint *local_850;
  undefined8 *local_848;
  ulong local_838;
  ulong local_830 [3];
  ulong local_818;
  undefined8 local_810;
  long local_808;
  undefined8 local_800;
  uchar *local_7f8;
  long local_7f0;
  undefined8 local_7e8;
  ulong local_7e0;
  long local_7d8;
  undefined8 uStack_7d0;
  undefined1 *local_7c8;
  undefined8 local_7c0;
  undefined1 local_7b8 [16];
  undefined8 local_7a8;
  ulong local_7a0;
  void *local_798 [2];
  undefined8 local_788;
  ulong local_780;
  void *local_778 [2];
  uint *******local_768;
  uint *******local_760;
  uint *******local_758 [2];
  ulong local_748;
  undefined8 local_740;
  undefined8 local_738;
  ulong local_728 [4];
  undefined1 auStack_708 [32];
  undefined1 auStack_6e8 [32];
  undefined1 auStack_6c8 [32];
  undefined8 local_6a8;
  undefined8 local_6a0;
  undefined8 local_698;
  undefined8 uStack_690;
  undefined1 auStack_688 [32];
  undefined1 auStack_668 [32];
  undefined1 auStack_648 [32];
  undefined8 local_628;
  undefined8 local_620;
  uint local_618;
  int iStack_614;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 uStack_608;
  undefined4 local_604;
  undefined4 uStack_600;
  undefined2 local_5fc;
  undefined4 local_5f8;
  undefined4 uStack_5f4;
  undefined4 local_5f0;
  undefined4 uStack_5ec;
  int local_5e8;
  undefined4 local_5e4;
  undefined4 auStack_5b0 [8];
  ulong local_590;
  undefined2 local_580;
  undefined2 uStack_57e;
  undefined1 uStack_57c;
  undefined1 uStack_57b;
  undefined1 uStack_57a;
  undefined1 uStack_579;
  uint local_578;
  uint uStack_574;
  long local_570;
  undefined8 local_568;
  long local_560;
  undefined8 local_558;
  long local_550;
  undefined8 local_548;
  long local_540;
  undefined8 local_538;
  long local_530;
  ulong local_528;
  long local_520;
  undefined8 local_518;
  long local_510;
  undefined8 local_508;
  long local_500;
  undefined8 local_4f8;
  undefined1 auStack_4f0 [16];
  undefined1 auStack_4e0 [8];
  long local_4d8;
  undefined1 auStack_4d0 [32];
  undefined1 auStack_4b0 [32];
  undefined1 auStack_490 [152];
  undefined8 local_3f8;
  undefined8 local_3f0;
  undefined4 local_3e8;
  undefined4 uStack_3e4;
  char local_3d8 [8];
  ulong *local_3d0;
  undefined1 auStack_3c8 [16];
  undefined8 auStack_3b8 [2];
  undefined1 local_3a8;
  undefined1 *local_3a0;
  undefined1 auStack_398 [32];
  undefined1 local_378 [8];
  undefined1 *local_370;
  undefined1 auStack_368 [8];
  ulong local_360;
  undefined8 local_358 [2];
  undefined1 local_348;
  undefined1 *local_340;
  undefined2 local_320;
  undefined2 uStack_31e;
  undefined1 uStack_31c;
  undefined1 uStack_31b;
  undefined1 uStack_31a;
  undefined1 uStack_319;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  void *local_210;
  undefined4 local_208;
  undefined1 local_204;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  
  FUN_00194dd8(0x24a3,0xffff8000,*(undefined8 *)param_1);
  *param_3 = false;
  *param_4 = false;
  *(undefined4 *)param_5 = 1;
  local_830[1] = 0;
  local_830[2] = 0;
  iVar8 = FUN_002b3ae8(param_1,local_830 + 1,param_5);
  if (iVar8 == 0) {
    uStack_31c = 1;
    local_320 = 0x24a3;
    uStack_31b = 0;
    uStack_31e = 0x8002;
    uStack_31a = 0;
    local_318 = (uint)local_830[1];
    uStack_319 = 0;
    local_314 = (undefined4)local_830[2];
    local_30c = 0;
    local_310 = *(undefined4 *)param_5;
    FUN_002b1030(&local_320,0x18);
    if (local_830[2] != 0) {
      *param_3 = true;
    }
    memset(auStack_4d0,0,0xd8);
    uVar9 = mpr::libcrypt::GetDigitalSignitureLicenseType();
    cVar6 = FUN_002a876c();
    bVar4 = 1;
    if (cVar6 != '\0') {
      bVar4 = *param_3 ^ 1;
    }
    uStack_31e = 0x9000;
    uStack_31c = 3;
    uStack_31b = 0;
    uStack_31a = 0;
    uStack_319 = 0;
    local_320 = 0x24a3;
    local_318 = param_2;
    FUN_002b1030(&local_320,0xc);
    memset(&local_3f8,0,0xa8);
    local_808 = 0;
    iVar8 = FUN_002b1158(0x693,&local_3f8,&local_808);
    if (iVar8 == 0) {
      uVar21 = FUN_002b4204(&local_3f8);
      uStack_31c = 3;
      uStack_31b = 0;
      uStack_31e = 0x9600;
      uStack_31a = 0;
      uStack_319 = 0;
      local_320 = 0x24a3;
      local_318 = param_2;
      FUN_002b1030(&local_320,0xc);
      FUN_0032a730(&local_580);
      local_7c8 = (undefined1 *)CONCAT44(local_7c8._4_4_,0x58415643);
      local_7c0 = 0xa00000;
      FUN_00322994(&local_320,&local_7c8);
      iVar8 = FUN_0032a774(&local_580,0x20000);
      if (iVar8 == 0) {
        puVar15 = &local_6a8;
        iVar8 = FUN_0032af44(&local_580,*(undefined8 *)param_1,1,puVar15);
        if (iVar8 == 0) {
          local_6a8 = 0;
          uVar33 = FUN_0032a380(&local_320,&local_580,1,0,puVar15);
          uVar38 = uVar33 & 0xffffffff;
          if ((int)uVar33 == 0) {
            local_618 = 0xff;
            iStack_614 = 3;
            local_620 = local_620 & 0xffffffff;
            local_604 = 3;
            uStack_600 = 0x14d4015;
            local_60c = 0;
            uStack_608 = 0;
            local_5f8 = 0;
            uStack_5f4 = 0;
            local_5f0 = 0;
            uStack_5ec = 0;
            local_5fc = 100;
            local_610 = 1;
            local_5e8 = 1;
            local_5e4 = 1;
            iVar8 = FUN_00328d4c(&local_320,&local_628);
            if (iVar8 == 0) {
              uVar33 = mpr::MoviePlayer::ConvertFrameCountTo90kHz(param_2,local_604);
              if (uVar33 == 0) {
                uVar21 = 0x10;
                local_6a8 = 0x2960524a3;
                local_6a0 = CONCAT44(local_604,param_2);
                goto LAB_002b9878;
              }
              local_854 = 1;
              if (local_5e8 != 1) {
                if (local_5e8 != 2) {
                  uVar2 = 0x3960624a3;
                  local_6a0 = CONCAT44(local_6a0._4_4_,local_5e8);
                  goto LAB_002b9824;
                }
                local_854 = 4;
              }
              local_6a8 = 0x1960724a3;
              uVar32 = (uint)uVar33;
              uVar11 = (uint)(uVar33 >> 0x20);
              local_698 = CONCAT44(local_854,uVar32);
              local_6a0._0_4_ = uVar11;
              local_6a0._4_4_ = uVar32;
              FUN_002b1030(puVar15,0x18);
              iStack_614 = CONCAT13((char)((uint)iStack_614 >> 0x18),0x10000);
              local_620 = 0;
              local_618 = 0;
              local_628 = uVar33;
              iVar8 = FUN_00327714(&local_320,&local_628);
              lVar17 = local_570;
              if (iVar8 == 0) {
                local_628 = 0x1950024a3;
                local_620 = CONCAT44(uVar32,uVar11);
                local_618 = uVar32;
                iStack_614 = local_854;
                FUN_002b1030(&local_628,0x18);
                puVar13 = &local_610;
                local_7a8 = (void **)0x0;
                local_7a0 = local_7a0 & 0xffffffff00000000;
                local_798[0] = (void *)0x0;
                do {
                  puVar13[-4] = 0;
                  *(undefined8 *)(puVar13 + -2) = 0;
                  puVar13[-6] = 1;
                  puVar13[-5] = 0;
                  puVar13 = puVar13 + 6;
                } while (puVar13 != auStack_5b0);
                local_788 = (void **)0x1;
                local_780 = local_780 & 0xffffffff00000000;
                local_778[0] = (void *)0x0;
                local_798[0] = operator_new__(0x3c00);
                local_860 = &local_618;
                do {
                  pvVar16 = operator_new__(0x1e00);
                  puVar19 = local_860 + 6;
                  *(void **)local_860 = pvVar16;
                  local_860 = puVar19;
                } while (puVar19 != (uint *)(&local_628 + (ulong)(local_854 - 1) * 3 + 5));
                local_778[0] = operator_new__(0x1680);
LAB_002b9a64:
                local_838 = local_838 & 0xffffffff00000000;
                local_7a8 = (void **)0x0;
                local_7a0 = local_7a0 & 0xffffffff00000000;
                memset(local_798[0],0,0x3c00);
                uVar29 = FUN_00326d20(&local_320,&local_7a8,(long)&local_7a8 + 4,&local_7a0,
                                      local_798[0],&local_838);
                uVar38 = uVar29 & 0xffffffff;
                if ((int)uVar29 != 0) goto LAB_002b9b10;
                puVar22 = (uint *)((long)local_798[0] + 0x38);
                uVar11 = 0;
                while ((uint *)((long)local_798[0] + ((ulong)local_7a8 >> 0x20) * 0x40 + 0x38) !=
                       puVar22) {
                  puVar23 = puVar22 + 0x10;
                  uVar37 = *puVar22;
                  puVar22 = puVar23;
                  if (uVar11 < uVar37) {
                    uVar11 = uVar37;
                  }
                }
                do {
                  puVar13 = (undefined4 *)((long)&local_628 + 4);
                  iVar8 = 0;
                  do {
                    puVar13[-1] = 1;
                    *puVar13 = 0;
                    puVar13[1] = 0;
                    memset(*(void **)(puVar13 + 3),0,0x1e00);
                    iVar12 = FUN_00328bf0(&local_320,uVar11,iVar8,puVar13 + -1,puVar13,puVar13 + 1,
                                          *(undefined8 *)(puVar13 + 3));
                    if (iVar12 != 0) {
                      local_6a8 = 0x2950524a3;
                      local_6a0 = CONCAT44(iVar12,iVar8);
                      FUN_002b1030(&local_6a8,0x10);
                      goto LAB_002b9bf0;
                    }
                    iVar8 = iVar8 + 1;
                    puVar13 = puVar13 + 6;
                  } while (iVar8 != local_854);
                } while ((local_628 & 0xb) == 0);
                local_788 = (void **)0x1;
                local_780 = local_780 & 0xffffffff00000000;
                memset(local_778[0],0,0x1680);
                uVar29 = FUN_0032843c(&local_320,uVar11,&local_788,(long)&local_788 + 4,&local_780,
                                      local_778[0]);
                if ((int)uVar29 != 0) {
                  local_6a0 = CONCAT44(local_6a0._4_4_,(int)uVar29);
                  local_6a8 = 0x3950624a3;
                  goto LAB_002b9b38;
                }
                uVar28 = 0;
                uVar38 = 0;
                local_768 = (uint *******)0x0;
                local_760 = (uint *******)0x0;
                local_758[0] = (uint *******)0x0;
                while( true ) {
                  pppppppuVar5 = local_760;
                  pppppppuVar14 = local_768;
                  uVar11 = (uint)uVar28;
                  uVar37 = (uint)uVar38;
                  if (local_7a8._4_4_ <= uVar11) break;
                  if (uVar37 == 0) {
                    uVar37 = *(uint *)((long)local_798[0] + uVar28 * 0x40 + 0x10);
                    if ((uVar37 <= uVar33) &&
                       (uVar1 = *(uint *)((long)local_798[0] + uVar28 * 0x40 + 0x38), uVar33 < uVar1
                       )) {
                      local_6a8 = 0x1950724a3;
                      local_698 = CONCAT44(uVar1,uVar37);
                      local_6a0._0_4_ = uVar32;
                      local_6a0._4_4_ = uVar11;
                      FUN_002b1030(&local_6a8,0x18);
                      uVar38 = (ulong)uVar37;
                    }
                  }
                  if (local_760 == local_758[0]) {
                    FUN_0022cbfc(&local_768,(long)local_798[0] + uVar28 * 0x40 + 0x10);
                  }
                  else {
                    if (local_760 != (uint *******)0x0) {
                      *(uint *)local_760 = *(uint *)((long)local_798[0] + uVar28 * 0x40 + 0x10);
                    }
                    local_760 = (uint *******)((long)local_760 + 4);
                  }
                  uVar28 = (ulong)(uVar11 + 1);
                }
                if (uVar37 == 0) {
                  if (local_768 != (uint *******)0x0) {
                    operator_delete(local_768);
                  }
                  if (((((ulong)local_7a8 & 1) == 0) || ((local_628 & 1) == 0)) &&
                     (((uint)local_7a8 >> 4 & 1) == 0)) goto code_r0x002ba32c;
                  puVar27 = (uchar *)0x0;
                  local_6a0 = CONCAT44((undefined4)local_628,(uint)local_7a8);
                  iVar8 = 4;
                  local_6a8 = 0x2950c24a3;
                  FUN_002b1030(&local_6a8,0x10);
                  goto LAB_002b9bf8;
                }
                if (local_768 != local_760) {
                  lVar31 = (long)local_760 - (long)local_768;
                  FUN_002b907c(local_768,local_760,(0x3f - LZCOUNT(lVar31 >> 2)) * 2);
                  if (lVar31 < 0x44) {
                    FUN_00187018(pppppppuVar14,pppppppuVar5);
                  }
                  else {
                    pppppppuVar20 = pppppppuVar14 + 8;
                    FUN_00187018(pppppppuVar14,pppppppuVar20);
                    for (; pppppppuVar5 != pppppppuVar20;
                        pppppppuVar20 = (uint *******)((long)pppppppuVar20 + 4)) {
                      uVar11 = *(uint *)pppppppuVar20;
                      for (pppppppuVar14 = pppppppuVar20;
                          uVar11 < *(uint *)((long)pppppppuVar14 + -4);
                          pppppppuVar14 = (uint *******)((long)pppppppuVar14 + -4)) {
                        *(uint *)pppppppuVar14 = *(uint *)((long)pppppppuVar14 + -4);
                      }
                      *(uint *)pppppppuVar14 = uVar11;
                    }
                  }
                }
                uVar33 = 0;
                pppppppuVar14 = local_768;
                do {
                  if (local_760 == pppppppuVar14) {
                    uVar35 = 0;
                    lVar31 = 0;
LAB_002b9f34:
                    if (bVar4 == 0) {
                      local_748 = local_360;
                      local_738 = local_358[0];
                      local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
                      local_6a8 = 0x3930024a3;
                      local_740 = uVar21;
                      FUN_002b1030(puVar15,0xc);
                      local_830[0] = local_830[0] & 0xffffffff00000000;
                      local_818 = local_818 & 0xffffffff00000000;
                      local_7f8 = (uchar *)0x0;
                      local_728[0] = local_748;
                      local_728[1] = local_740;
                      local_728[2] = local_738;
                      iVar12 = ReMmapStreamBuffer((BufferAreaInfo *)&local_748,(int *)local_830,
                                                  (int *)&local_818,(long *)&local_7f8);
                      if (iVar12 == 0) {
                        local_6a8 = local_748;
                        local_6a0 = local_740;
                        local_698 = local_738;
                        iVar12 = FUN_00187b30(lVar17,*(undefined8 *)((long)local_798[0] + 8),
                                              local_7a0 & 0xffffffff,local_830[0] & 0xffffffff,
                                              local_7f8,puVar15,auStack_4b0);
                        if (iVar12 == 0) {
                          puVar25 = &local_620;
                          puVar26 = auStack_490;
                          iVar12 = 0;
                          do {
                            local_6a8 = local_748;
                            local_6a0 = local_740;
                            local_698 = local_738;
                            iVar10 = FUN_00187b30(lVar17,*(undefined8 *)(puVar25[1] + 8),
                                                  *(undefined4 *)puVar25,local_830[0] & 0xffffffff,
                                                  local_7f8,puVar15,puVar26);
                            if (iVar10 != 0) {
                              uVar21 = 0xc;
                              local_7d8 = CONCAT44(local_7d8._4_4_,iVar12);
                              local_7e0 = 0x3930324a3;
                              goto LAB_002ba0f8;
                            }
                            iVar12 = iVar12 + 1;
                            puVar25 = puVar25 + 3;
                            puVar26 = puVar26 + 0x20;
                          } while (iVar8 != iVar12);
                          iVar12 = FUN_00187b30(lVar17,*(undefined8 *)((long)local_778[0] + 8),
                                                local_780 & 0xffffffff,local_830[0] & 0xffffffff,
                                                local_7f8,local_728,auStack_4d0);
                          iVar8 = 0;
                          if (iVar12 != 0) {
                            uVar21 = 8;
                            local_6a8 = 0x4930424a3;
                            goto LAB_002ba0fc;
                          }
                        }
                        else {
                          uVar21 = 8;
                          local_7e0 = 0x4930224a3;
LAB_002ba0f8:
                          puVar15 = &local_7e0;
LAB_002ba0fc:
                          iVar8 = 2;
                          FUN_002b1030(puVar15,uVar21);
                        }
                        iVar12 = ReMunmapStreamBuffer
                                           ((BufferAreaInfo *)&local_748,(int)local_818,
                                            (int)local_830[0],(long)local_7f8);
                        if (iVar12 != 0) {
                          local_6a8 = 0x4930524a3;
                          FUN_002b1030(&local_6a8,8);
                        }
                        if (iVar8 == 0) {
                          local_748 = local_728[0];
                          local_740 = local_728[1];
                          local_738 = local_728[2];
                        }
                      }
                      else {
                        iVar8 = 2;
                        local_6a8 = 0x4930124a3;
                        FUN_002b1030(puVar15,8);
                      }
                      puVar15 = &local_6a8;
                      local_6a8 = 0x3930f24a3;
                      local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
                      FUN_002b1030(puVar15,0xc);
                      local_6a8 = local_748;
                      if (iVar8 == 0) goto LAB_002ba2c4;
                      local_6a8 = 0x4950924a3;
LAB_002ba05c:
                      puVar27 = (uchar *)0x0;
                      iVar8 = 2;
                      FUN_002b1030(puVar15,8);
                    }
                    else {
                      local_6a8 = local_360;
                      local_6a0 = uVar21;
                      iVar8 = FUN_001878e8(lVar17,*(undefined8 *)((long)local_778[0] + 8),
                                           local_780 & 0xffffffff,&local_6a8);
                      if (iVar8 != 0) {
                        local_728[0] = 0x4950a24a3;
                        puVar15 = local_728;
                        goto LAB_002ba05c;
                      }
LAB_002ba2c4:
                      uVar29 = local_838;
                      puVar27 = (uchar *)(lVar31 + local_6a8);
                      local_6a8 = 0x1950b24a3;
                      local_6a0 = CONCAT44((int)((ulong)puVar27 >> 0x20),(int)local_838);
                      local_698 = CONCAT44(uVar35,(int)puVar27);
                      FUN_002b1030(&local_6a8,0x18);
                      iVar8 = 0;
                    }
                    uVar38 = uVar29 & 0xffffffff;
                    if (local_768 != (uint *******)0x0) {
                      operator_delete(local_768);
                    }
                    goto LAB_002b9bf8;
                  }
                  if (uVar37 == *(uint *)pppppppuVar14) {
                    uVar35 = *(undefined4 *)((long)local_778[0] + uVar33 * 0x18);
                    lVar24 = *(long *)((long)local_778[0] + uVar33 * 0x18 + 8);
                    lVar31 = lVar24 - *(long *)((long)local_778[0] + 8);
                    local_6a8 = 0x1950824a3;
                    local_698 = CONCAT44((int)lVar24,(int)((ulong)lVar24 >> 0x20));
                    local_6a0._0_4_ = uVar32;
                    local_6a0._4_4_ = (uint)uVar33;
                    FUN_002b1030(&local_6a8);
                    goto LAB_002b9f34;
                  }
                  uVar33 = (ulong)((uint)uVar33 + 1);
                  pppppppuVar14 = (uint *******)((long)pppppppuVar14 + 4);
                } while( true );
              }
              local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
              local_6a8 = 0x3960824a3;
              FUN_002b1030(puVar15,0xc);
            }
            else {
              uVar2 = 0x3960424a3;
              local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
LAB_002b9824:
              local_6a8 = (ulong)uVar2;
              uVar21 = 0xc;
LAB_002b9878:
              FUN_002b1030(puVar15,uVar21);
              local_854 = 0;
            }
            puVar27 = (uchar *)0x0;
            goto LAB_002b9888;
          }
          iVar12 = 2;
          local_620 = CONCAT44(local_620._4_4_,(int)uVar33);
          puVar27 = (uchar *)0x0;
          uVar38 = 0;
          local_628 = 0x3960324a3;
          FUN_002b1030(&local_628,0xc);
          local_854 = 0;
          goto LAB_002b9758;
        }
        local_620 = CONCAT44(local_620._4_4_,iVar8);
        uVar38 = 0;
        iVar12 = 2;
        puVar27 = (uchar *)0x0;
        local_628 = 0x3960224a3;
        FUN_002b1030(&local_628,0xc);
        local_854 = 0;
        goto LAB_002b96ec;
      }
      local_620 = CONCAT44(local_620._4_4_,iVar8);
      uVar38 = 0;
      iVar12 = 2;
      puVar27 = (uchar *)0x0;
      local_628 = 0x3960124a3;
      FUN_002b1030(&local_628,0xc);
      local_854 = 0;
      goto LAB_002b94b0;
    }
    uStack_31b = 0;
    uVar38 = 0;
    uStack_31c = 4;
    uStack_31a = 0;
    uStack_31e = 0x9001;
    uStack_319 = 0;
    local_320 = 0x24a3;
    FUN_002b1030(&local_320,8);
    local_854 = 0;
    iVar8 = 2;
    goto LAB_002b93e4;
  }
  uStack_31e = 0x8001;
LAB_002b928c:
  uStack_319 = 0;
  uStack_31a = 0;
  uStack_31b = 0;
  uStack_31c = 4;
  local_320 = 0x24a3;
  FUN_002b1030(&local_320,8);
  *(undefined8 *)(param_8 + 8) = 0;
  uVar9 = 2;
  goto LAB_002b929c;
code_r0x002ba32c:
  local_6a8 = 0x4950d24a3;
  FUN_002b1030(&local_6a8,8);
  goto LAB_002b9a64;
LAB_002b9b10:
  local_6a0 = CONCAT44(local_6a0._4_4_,(int)uVar29);
  local_6a8 = 0x3950424a3;
LAB_002b9b38:
  uVar38 = 0;
  FUN_002b1030(&local_6a8,0xc);
LAB_002b9bf0:
  puVar27 = (uchar *)0x0;
  iVar8 = 2;
LAB_002b9bf8:
  if (local_798[0] != (void *)0x0) {
    operator_delete__(local_798[0]);
  }
  local_798[0] = (void *)0x0;
  local_850 = &local_618;
  do {
    if (*(void **)local_850 != (void *)0x0) {
      operator_delete__(*(void **)local_850);
    }
    puVar22 = local_850 + 6;
    local_850[0] = 0;
    local_850[1] = 0;
    local_850 = puVar22;
  } while (puVar19 != puVar22);
  if (local_778[0] != (void *)0x0) {
    operator_delete__(local_778[0]);
  }
  local_6a8 = 0x3950f24a3;
  local_778[0] = (void *)0x0;
  local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
  FUN_002b1030(&local_6a8,0xc);
  iVar12 = 0;
  if (iVar8 != 0) {
    local_628 = 0x4960924a3;
    FUN_002b1030(&local_628,8);
LAB_002b9888:
    iVar12 = 2;
  }
  FUN_00329434(&local_320);
LAB_002b9758:
  iVar8 = FUN_0032a8b0(&local_580);
  if (iVar8 != 0) {
    local_620 = CONCAT44(local_620._4_4_,iVar8);
    local_628 = 0x3960e24a3;
    FUN_002b1030(&local_628,0xc);
  }
LAB_002b96ec:
  FUN_0032a864(&local_580);
LAB_002b94b0:
  local_628 = 0x3960f24a3;
  local_620 = CONCAT44(local_620._4_4_,iVar12);
  FUN_002b1030(&local_628,0xc);
  thunk_FUN_00329434((RTMetadatSmplDatParser *)&local_320);
  FUN_0032a6ac(&local_580);
  uStack_31b = 0;
  uStack_31a = 0;
  uStack_319 = 0;
  uStack_31c = 4;
  uStack_31e = 0x9003;
  local_320 = 0x24a3;
  if (iVar12 == 0) {
    uStack_31e = 0x9700;
    FUN_002b1030((RTMetadatSmplDatParser *)&local_320,8);
    mpr::RTMetadatSmplDatParser::RTMetadatSmplDatParser((RTMetadatSmplDatParser *)&local_320);
    local_578 = mpr::RTMetadatSmplDatParser::TransitToQueryMode
                          ((RTMetadatSmplDatParser *)&local_320,puVar27);
    if (local_578 == 0) {
      local_6a8 = local_6a8 & 0xffffffffffffff00;
      local_628 = 0;
      local_620 = 0;
      local_578 = mpr::RTMetadatSmplDatParser::GetMetadata
                            ((RTMetadatSmplDatParser *)&local_320,3,&local_6a8,&local_628);
      if (local_578 != 0) {
        uStack_574 = (uint)(byte)local_6a8;
        uVar21 = 0x10;
        uStack_57c = 2;
        uStack_57e = 0x9704;
        goto LAB_002b9570;
      }
      local_578 = (uint)(byte)local_6a8;
      uVar33 = local_628;
      uVar29 = local_620;
      if (local_578 == 0) {
        uVar33 = 0;
        uVar29 = 0;
      }
      uStack_574 = (uint)local_620;
      uStack_57c = 2;
      uStack_57e = 0x9705;
      uStack_57b = 0;
      uStack_57a = 0;
      uStack_579 = 0;
      local_580 = 0x24a3;
      FUN_002b1030(&local_580,0x10);
      local_6a8 = local_6a8 & 0xffffffffffffff00;
      local_628 = 0;
      local_620 = 0;
      local_578 = mpr::RTMetadatSmplDatParser::GetMetadata
                            ((RTMetadatSmplDatParser *)&local_320,4,&local_6a8,&local_628);
      if (local_578 != 0) {
        uStack_574 = (uint)(byte)local_6a8;
        uStack_57e = 0x9706;
        local_580 = 0x24a3;
        uStack_57b = 0;
        uStack_57a = 0;
        uStack_579 = 0;
        uStack_57c = 2;
        FUN_002b1030(&local_580,0x10);
        goto LAB_002b9588;
      }
      local_578 = (uint)(byte)local_6a8;
      uVar28 = local_628;
      uVar36 = local_620;
      if (local_578 == 0) {
        uVar28 = 0;
        uVar36 = 0;
      }
      uStack_574 = (uint)local_620;
      uStack_57c = 2;
      uStack_57b = 0;
      local_580 = 0x24a3;
      uStack_57a = 0;
      uStack_579 = 0;
      uStack_57e = 0x9707;
      FUN_002b1030(&local_580,0x10);
      iVar8 = 0;
    }
    else {
      uStack_57c = 3;
      uStack_57e = 0x9702;
      uVar21 = 0xc;
LAB_002b9570:
      uStack_579 = 0;
      uStack_57a = 0;
      uStack_57b = 0;
      local_580 = 0x24a3;
      uVar29 = 0;
      uVar33 = 0;
      FUN_002b1030(&local_580,uVar21);
LAB_002b9588:
      uVar36 = 0;
      uVar28 = 0;
      iVar8 = 2;
    }
    uStack_57e = 0x970f;
    uStack_57c = 3;
    uStack_57b = 0;
    uStack_57a = 0;
    uStack_579 = 0;
    local_580 = 0x24a3;
    local_578 = iVar8;
    FUN_002b1030(&local_580,0xc);
    mpr::RTMetadatSmplDatParser::~RTMetadatSmplDatParser((RTMetadatSmplDatParser *)&local_320);
    if (iVar8 != 0) {
      uStack_31e = 0x9004;
      goto LAB_002b95f4;
    }
    iVar8 = 0;
    if ((uVar29 != 0) && (uVar36 != 0)) {
      local_580 = 0;
      uStack_57e = 0;
      uVar11 = FUN_002b27f4(uVar33,uVar28,0,&local_580);
      if (uVar11 != 0) {
        uStack_31e = 0x9005;
LAB_002ba564:
        uStack_319 = 0;
        uStack_31a = 0;
        uStack_31b = 0;
        uStack_31c = 3;
        local_320 = 0x24a3;
        local_318 = uVar11;
        FUN_002b1030((RTMetadatSmplDatParser *)&local_320,0xc);
        goto LAB_002ba578;
      }
      if ((ulong)CONCAT22(uStack_57e,local_580) <= *(ulong *)(param_8 + 8)) {
        uVar11 = FUN_002b27f4(uVar33,uVar28,*(undefined8 *)param_8,&local_580);
        if (uVar11 != 0) {
          uStack_31e = 0x9007;
          goto LAB_002ba564;
        }
        uVar11 = CONCAT22(uStack_57e,local_580);
        if (*(ulong *)(param_8 + 8) < (ulong)uVar11) {
          uStack_31e = 0x9008;
          local_314 = (undefined4)*(ulong *)(param_8 + 8);
          local_318 = uVar11;
          goto LAB_002ba5b8;
        }
        *(ulong *)(param_8 + 8) = (ulong)uVar11;
        goto LAB_002b960c;
      }
      uStack_31e = 0x9006;
      local_314 = (undefined4)*(ulong *)(param_8 + 8);
      local_318 = CONCAT22(uStack_57e,local_580);
LAB_002ba5b8:
      uStack_31c = 2;
      uVar21 = 0x10;
      goto LAB_002b95fc;
    }
LAB_002ba578:
    *(undefined8 *)(param_8 + 8) = 0;
  }
  else {
LAB_002b95f4:
    uStack_31c = 4;
    uVar21 = 8;
LAB_002b95fc:
    uStack_319 = 0;
    uStack_31a = 0;
    uStack_31b = 0;
    local_320 = 0x24a3;
    FUN_002b1030((RTMetadatSmplDatParser *)&local_320,uVar21);
    iVar8 = 2;
  }
LAB_002b960c:
  FUN_002b2470((long)&local_3f0 + 4,&local_808);
  if (iVar8 != 0) {
LAB_002b93e4:
    *(undefined8 *)(param_8 + 8) = 0;
  }
  local_848 = &local_3f8;
  uStack_31e = 0x900f;
  uStack_31c = 3;
  uStack_31b = 0;
  uStack_31a = 0;
  uStack_319 = 0;
  local_320 = 0x24a3;
  local_318 = iVar8;
  FUN_002b1030((getCertificateInfoOutParam *)&local_320,0xc);
  if (iVar8 != 0) {
    uStack_31e = 0x8007;
    goto LAB_002b928c;
  }
  if (*param_3 == false) {
LAB_002bba3c:
    *param_4 = true;
  }
  else {
    if (*(int *)param_5 == 1) {
      iVar8 = FUN_002b435c(param_1,uVar9,local_830 + 1,uVar38,auStack_4d0,local_854,param_6,param_7)
      ;
      if (iVar8 == 0) goto LAB_002bba3c;
      uStack_31e = 0x8008;
    }
    else {
      if (*(int *)param_5 != 0) goto LAB_002bba3c;
      uStack_31b = 0;
      uStack_31e = 0x8b00;
      uStack_31c = 4;
      uStack_31a = 0;
      uStack_319 = 0;
      local_320 = 0x24a3;
      FUN_002b1030((getCertificateInfoOutParam *)&local_320,8);
                    /* WARNING: Ignoring partial resolution of indirect */
      local_318._0_2_ = 0;
      uStack_319 = 0;
      uStack_31a = 0;
      uStack_31b = 0;
      uStack_31c = 0;
      uStack_31e = 0;
      local_320 = 0;
      memset((void *)((long)&local_318 + 2),0,0x100);
      local_204 = 0;
      local_210 = (void *)0x0;
      local_208 = 0;
      local_200 = 0;
      uStack_1f8 = 0;
      local_1f0 = 0;
      uStack_1e8 = 0;
      local_1e0 = 0;
      uStack_1d8 = 0;
      local_1d0 = 0;
      uStack_1c8 = 0;
      cVar6 = FUN_002a876c(uVar9);
      if (cVar6 == '\0') {
        iVar8 = 2;
        local_3f0 = CONCAT44(local_3f0._4_4_,uVar9);
        local_3f8 = 0x38b0124a3;
        FUN_002b1030(&local_3f8,0xc);
LAB_002ba7d4:
        *(undefined8 *)(param_6 + 8) = 0;
        *param_7 = (TrustTime)0x0;
      }
      else {
        pvVar16 = operator_new__(0x4000);
        local_210 = pvVar16;
        iVar8 = InfraC2PA::GetCertificateInfo((getCertificateInfoOutParam *)&local_320);
        if (iVar8 == 0) {
          memset(&local_628,0,0xa8);
          local_838 = 0;
          iVar8 = FUN_002b1158(0x684,&local_628,&local_838);
          if (iVar8 != 0) {
            uVar21 = 8;
            local_3f8 = 0x48b0224a3;
            goto LAB_002ba828;
          }
          local_818 = local_590;
          local_810 = FUN_002b4204(&local_628);
          lVar17 = FUN_002b4090(param_1,local_830 + 1,&local_818);
          if ((int)lVar17 == 0) {
            memset(&local_580,0,0xb0);
            iVar8 = FUN_002b6c7c(&local_818,&local_580);
            if (iVar8 != 0) {
              uVar18 = 0x8b04;
LAB_002ba930:
              local_3f8._0_4_ = CONCAT22(uVar18,0x24a3);
              local_3f8 = CONCAT44(4,(undefined4)local_3f8);
              uVar21 = 8;
              goto LAB_002ba938;
            }
            memset(local_728,0,0x80);
            memset(&local_6a8,0,0x80);
            local_3f8 = 0x4831124a3;
            FUN_002b1030(&local_3f8,8);
            lVar17 = 0;
            do {
              lVar31 = lVar17 + 0x20;
              *(undefined8 *)((long)&local_6a8 + lVar17) = 0;
              *(undefined8 *)((long)&local_6a0 + lVar17) = 0;
              *(undefined8 *)((long)&local_698 + lVar17) = 0;
              *(undefined8 *)(auStack_688 + lVar17 + -8) = 0;
              lVar17 = lVar31;
            } while (lVar31 != 0x80);
            local_3f8 = local_818 + local_560;
            local_3f0 = local_558;
            iVar8 = FUN_002a9cdc(&local_3f8,&local_6a8);
            if (iVar8 == 0) {
              local_3f8 = local_818 + local_550;
              local_3f0 = local_548;
              iVar8 = FUN_002a9cdc(&local_3f8,auStack_688);
              if (iVar8 != 0) {
                uVar35 = 2;
                goto LAB_002baa50;
              }
              local_3f8 = local_818 + local_570;
              local_3f0 = local_568;
              iVar8 = FUN_002a9cdc(&local_3f8,auStack_668);
              if (iVar8 != 0) {
                uVar35 = 4;
                goto LAB_002baa50;
              }
              local_3f8 = local_818 + local_520;
              local_3f0 = local_518;
              iVar12 = FUN_002a9cdc(&local_3f8,auStack_648);
              uVar35 = 0;
              iVar8 = 0;
              if (iVar12 != 0) {
                uVar35 = 8;
                goto LAB_002baa50;
              }
            }
            else {
              uVar35 = 1;
LAB_002baa50:
              iVar8 = 2;
            }
            local_3f8 = 0x2831f24a3;
            local_3f0 = CONCAT44(uVar35,iVar8);
            FUN_002b1030(&local_3f8,0x10);
            if (iVar8 != 0) {
              uVar18 = 0x8b05;
              goto LAB_002ba930;
            }
            local_808 = local_818 + local_540;
            local_800 = local_538;
            local_3f8 = 0x4841124a3;
            FUN_002b1030(&local_3f8,8);
            lVar17 = 0;
            do {
              lVar31 = lVar17 + 0x20;
              *(undefined8 *)((long)local_728 + lVar17) = 0;
              *(undefined8 *)((long)local_728 + lVar17 + 8) = 0;
              *(undefined8 *)((long)local_728 + lVar17 + 0x10) = 0;
              *(undefined8 *)((long)local_728 + lVar17 + 0x18) = 0;
              lVar17 = lVar31;
            } while (lVar31 != 0x80);
            local_7c8 = local_7b8;
            local_7c0 = 0;
            local_7b8[0] = 0;
            iVar8 = FUN_002b2f30(&local_808,(BufferArea_t *)&local_7c8,0xffffffffffffffff,1);
            if (iVar8 == 0) {
              local_7a8 = local_798;
              local_7a0 = 0;
              local_798[0] = (void *)((ulong)local_798[0] & 0xffffffffffffff00);
              local_7f8 = (uchar *)0x0;
              local_7f0 = 0;
              local_7e8 = 0;
              local_7e0 = 0;
              local_7d8 = 0;
              uStack_7d0 = 0;
              FUN_002b0d90(&local_748,"\'created_assertions\': [");
              FUN_002b0d90(local_848,"]");
              iVar8 = FUN_002b085c((BufferArea_t *)&local_7c8,&local_748,local_848,&local_7a8,0);
              std::__cxx11::string::_M_dispose();
              std::__cxx11::string::_M_dispose();
              if (iVar8 == 0) {
                uVar33 = 0;
                while (uVar33 < local_7a0) {
                  local_780 = 0;
                  local_778[0] = (void *)((ulong)local_778[0] & 0xffffffffffffff00);
                  local_830[0] = 0;
                  local_788 = local_778;
                  std::__cxx11::string::substr((ulong)&local_7a8,uVar33);
                  FUN_002b0d90(&local_748,"\'hash\': h\'");
                  FUN_002b0d90(local_848,&DAT_003dad82);
                  iVar8 = FUN_002b085c(&local_768,&local_748,local_848,&local_788,local_830);
                  std::__cxx11::string::_M_dispose();
                  std::__cxx11::string::_M_dispose();
                  std::__cxx11::string::_M_dispose();
                  if (iVar8 != 0) {
                    std::__cxx11::string::_M_dispose();
                    break;
                  }
                  FUN_0019ddf0(&local_7f8,&local_788);
                  uVar33 = uVar33 + local_830[0];
                  std::__cxx11::string::_M_dispose();
                }
                uVar33 = 0;
                while (uVar33 < local_7a0) {
                  local_780 = 0;
                  local_778[0] = (void *)((ulong)local_778[0] & 0xffffffffffffff00);
                  local_830[0] = 0;
                  local_788 = local_778;
                  std::__cxx11::string::substr((ulong)&local_7a8,uVar33);
                  FUN_002b0d90(&local_748,&DAT_003dad7b);
                  FUN_002b0d90(local_848,&DAT_003dad82);
                  iVar8 = FUN_002b085c(&local_768,&local_748,local_848,&local_788,local_830);
                  std::__cxx11::string::_M_dispose();
                  std::__cxx11::string::_M_dispose();
                  std::__cxx11::string::_M_dispose();
                  if (iVar8 != 0) {
                    std::__cxx11::string::_M_dispose();
                    break;
                  }
                  FUN_0019ddf0(&local_7e0,&local_788);
                  uVar33 = uVar33 + local_830[0];
                  std::__cxx11::string::_M_dispose();
                }
                uVar33 = (long)(local_7d8 - local_7e0) >> 5;
                iVar8 = (int)uVar33;
                if ((iVar8 == 0) ||
                   (uVar33 = uVar33 & 0xffffffff, uVar33 != local_7f0 - (long)local_7f8 >> 5)) {
                  local_3f0 = CONCAT44((int)(local_7f0 - (long)local_7f8 >> 5),iVar8);
                  uVar21 = 0x10;
                  local_3f8 = 0x2841424a3;
                  goto LAB_002badc8;
                }
                lVar17 = 0;
                std::__cxx11::string::_M_dispose();
                FUN_002b0d90(local_848,"self#jumbf=c2pa.assertions/c2pa.actions.v2");
                local_3d8[0] = '\0';
                local_3d0 = local_728;
                FUN_002b0d90(auStack_3c8,"self#jumbf=c2pa.assertions/c2pa.thumbnail.claim.jpeg");
                local_3a8 = 0;
                local_3a0 = auStack_708;
                FUN_002b0d90(auStack_398,"self#jumbf=c2pa.assertions/c2pa.hash.bmff.v3");
                local_378[0] = 0;
                local_370 = auStack_6e8;
                FUN_002b0d90(auStack_368,"self#jumbf=c2pa.assertions/sony.original.signature");
                local_348 = 0;
                local_340 = auStack_6c8;
                do {
                  pcVar34 = local_3d8;
                  cVar6 = '\0';
                  do {
                    if (*pcVar34 == '\0') {
                      cVar7 = FUN_001ba894(local_7e0 + lVar17,pcVar34 + -0x20);
                      if (cVar7 != '\0') {
                        lVar31 = *(long *)(local_7f8 + lVar17 + 8);
                        if (lVar31 == 0x40) {
                          iVar8 = FUN_002b0bbc(local_7f8 + lVar17,*(undefined8 *)(pcVar34 + 8),0x20)
                          ;
                          if (iVar8 == 0) {
                            *pcVar34 = '\x01';
                            cVar6 = cVar7;
                            goto LAB_002bafd4;
                          }
                          uVar21 = 8;
                          local_748 = 0x4841624a3;
                        }
                        else {
                          local_740 = CONCAT44(local_740._4_4_,(int)lVar31);
                          uVar21 = 0xc;
                          local_748 = 0x3841524a3;
                        }
                        FUN_002b1030(&local_748,uVar21);
                        goto LAB_002bb0b8;
                      }
                    }
LAB_002bafd4:
                    pcVar34 = pcVar34 + 0x30;
                  } while ((char *)&local_318 != pcVar34);
                  if (cVar6 != '\0') {
                    lVar31 = 0;
                    while (local_3d8[lVar31] != '\0') {
                      lVar31 = lVar31 + 0x30;
                      iVar8 = 0;
                      if (lVar31 == 0xc0) goto LAB_002bb000;
                    }
                  }
                  lVar17 = lVar17 + 0x20;
                } while (uVar33 * 0x20 - lVar17 != 0);
LAB_002bb0b8:
                iVar8 = 2;
LAB_002bb000:
                std::__cxx11::string::_M_dispose();
                std::__cxx11::string::_M_dispose();
                std::__cxx11::string::_M_dispose();
                std::__cxx11::string::_M_dispose();
              }
              else {
                uVar21 = 8;
                local_3f8 = 0x4841324a3;
LAB_002badc8:
                FUN_002b1030(&local_3f8,uVar21);
                iVar8 = 2;
                std::__cxx11::string::_M_dispose();
              }
              FUN_0019dce4(&local_7e0);
              FUN_0019dce4(&local_7f8);
            }
            else {
              iVar8 = 2;
              local_3f8 = 0x4841224a3;
              FUN_002b1030(&local_3f8,8);
            }
            local_3f8 = 0x3841f24a3;
            local_3f0 = CONCAT44(local_3f0._4_4_,iVar8);
            FUN_002b1030(&local_3f8,0xc);
            std::__cxx11::string::_M_dispose();
            if (iVar8 != 0) {
              uVar18 = 0x8b06;
              goto LAB_002ba930;
            }
            if (local_4d8 != 0x40) {
              uVar18 = 0x8b08;
              goto LAB_002ba8e4;
            }
            lVar17 = 0;
            local_3f8 = 0x48e1024a3;
            FUN_002b1030(&local_3f8,8);
            do {
              puVar15 = local_728 + lVar17 * 4;
              puVar25 = &local_6a8 + lVar17 * 4;
              iVar8 = memcmp(puVar15,puVar25,0x20);
              if (iVar8 != 0) {
                iVar8 = 2;
                local_3f8 = 0x38e1124a3;
                local_3f0 = CONCAT44(local_3f0._4_4_,(int)lVar17);
                FUN_002b1030(local_848,0xc);
                FUN_002b423c(&DAT_003dad84,puVar15,0x1e);
                FUN_002b423c(&DAT_003dad88,puVar25,0x1e);
                goto LAB_002bb1a0;
              }
              lVar17 = lVar17 + 1;
            } while (lVar17 != 4);
            iVar8 = 0;
LAB_002bb1a0:
            local_3f8 = 0x38e1f24a3;
            local_3f0 = CONCAT44(local_3f0._4_4_,iVar8);
            FUN_002b1030(&local_3f8,0xc);
            uVar18 = 0x8b09;
            if (iVar8 != 0) goto LAB_002ba930;
            local_3f8 = 0x4942024a3;
            FUN_002b1030(&local_3f8,8);
            iVar8 = FUN_00187780(uVar9,&local_818,auStack_4f0,auStack_4e0);
            local_3f8 = 0x3942f24a3;
            local_3f0 = CONCAT44(local_3f0._4_4_,iVar8);
            FUN_002b1030(&local_3f8,0xc);
            uVar18 = 0x8b0a;
            if (iVar8 != 0) goto LAB_002ba930;
            local_3f8 = 0x4943024a3;
            FUN_002b1030(&local_3f8,8);
            local_7f8 = (uchar *)0x0;
            local_7e0 = 0;
            local_7c8 = (undefined1 *)(local_818 + local_540);
            local_7c0 = local_538;
            iVar8 = libMp4SignaturePrivate::CreateC2paSigStructureHashData
                              ((getCertificateInfoOutParam *)&local_320,(BufferArea_t *)&local_7c8,
                               &local_7f8,&local_7e0);
            if (iVar8 == 0) {
              local_778[0] = (void *)((ulong)local_778[0] & 0xffffffffffffff00);
              local_7a8 = (void **)(local_818 + local_530);
              local_780 = 0;
              local_7a0 = local_528;
              local_788 = local_778;
              iVar8 = FUN_002b2f30(&local_7a8,&local_788,0xffffffffffffffff,1);
              if (iVar8 == 0) {
                local_768 = (uint *******)local_758;
                local_758[0] = (uint *******)((ulong)local_758[0] & 0xffffffffffffff00);
                local_760 = (uint *******)0x0;
                FUN_002b0d90(&local_748,"null,h\'");
                FUN_002b0d90(&local_3f8,&DAT_003dad82);
                iVar8 = FUN_002b085c(&local_788,&local_748,&local_3f8,&local_768,0);
                std::__cxx11::string::_M_dispose();
                std::__cxx11::string::_M_dispose();
                if (iVar8 != 0) {
                  uVar21 = 8;
                  uVar3 = 0x4943324a3;
LAB_002bb490:
                  local_3f8 = (ulong)uVar3;
                  pvVar30 = (void *)0x0;
                  uVar33 = 0;
                  FUN_002b1030(&local_3f8,uVar21);
LAB_002bb4a0:
                  std::__cxx11::string::_M_dispose();
                  goto LAB_002bb3f4;
                }
                if (((ulong)local_760 & 1) != 0) {
                  uVar21 = 0xc;
                  uVar3 = 0x3943424a3;
                  local_3f0 = CONCAT44(local_3f0._4_4_,(int)local_760);
                  goto LAB_002bb490;
                }
                uVar33 = (ulong)local_760 >> 1;
                pvVar30 = operator_new__(uVar33);
                iVar8 = FUN_002b0bbc(&local_768,pvVar30,local_760);
                if (iVar8 != 0) {
                  local_3f8 = 0x4943624a3;
                  FUN_002b1030(&local_3f8,8);
                  goto LAB_002bb4a0;
                }
                std::__cxx11::string::_M_dispose();
                std::__cxx11::string::_M_dispose();
                iVar12 = iCrypt_VerifyData(0x20300005,local_7f8,local_7e0,pvVar30,uVar33);
                iVar8 = 0;
                if (iVar12 == 0) goto LAB_002bb2f0;
                local_3f0 = CONCAT44(local_3f0._4_4_,iVar12);
                local_3f8 = 0x3943724a3;
                FUN_002b1030(&local_3f8,0xc);
              }
              else {
                pvVar30 = (void *)0x0;
                uVar33 = 0;
                local_3f8 = 0x4943224a3;
                FUN_002b1030(&local_3f8,8);
LAB_002bb3f4:
                std::__cxx11::string::_M_dispose();
              }
              iVar8 = 2;
            }
            else {
              iVar8 = 2;
              pvVar30 = (void *)0x0;
              uVar33 = 0;
              local_3f8 = 0x3943124a3;
              local_3f0 = CONCAT44(local_3f0._4_4_,2);
              FUN_002b1030(&local_3f8,0xc);
            }
LAB_002bb2f0:
            if (local_7f8 != (uchar *)0x0) {
              operator_delete__(local_7f8);
            }
            local_7f8 = (uchar *)0x0;
            if (pvVar30 != (void *)0x0) {
              operator_delete__(pvVar30);
            }
            local_3f8 = 0x1943f24a3;
            local_3f0 = CONCAT44((int)local_7e0,iVar8);
            local_3e8 = (undefined4)uVar33;
            uStack_3e4 = 0;
            FUN_002b1030(&local_3f8,0x18);
            if (iVar8 != 0) {
              uVar18 = 0x8b20;
              goto LAB_002ba930;
            }
            operator_delete__(pvVar16);
            memset(&local_3f8,0,0xd8);
            lVar17 = local_818 +
                     CONCAT17(uStack_579,
                              CONCAT16(uStack_57a,
                                       CONCAT15(uStack_57b,
                                                CONCAT14(uStack_57c,CONCAT22(uStack_57e,local_580)))
                                      ));
            lVar31 = CONCAT44(uStack_574,local_578) + -1;
            local_6a8 = 0x3870024a3;
            local_6a0 = CONCAT44(local_6a0._4_4_,(int)uVar38);
            FUN_002b1030(&local_6a8,0xc);
            local_748 = 0;
            local_728[0] = CONCAT26(local_728[0]._6_2_,0x656c6b72656d);
            do {
              cVar6 = FUN_002b0960(lVar17,&local_748,lVar31,6,local_728);
              if (cVar6 != '\0') {
                cVar6 = FUN_001872f8(lVar17,&local_748,lVar31);
                if ((((cVar6 == '\0') || (cVar6 = FUN_002b0838(&local_748,lVar31,1), cVar6 == '\0'))
                    || (cVar6 = FUN_002b0838(&local_748,lVar31,4), cVar6 == '\0')) ||
                   ((cVar6 = FUN_002b0838(&local_748,lVar31,7), cVar6 == '\0' ||
                    (cVar6 = FUN_002b0838(&local_748,lVar31,6), cVar6 == '\0')))) goto LAB_002bbabc;
                local_768 = (uint *******)((ulong)local_768 & 0xffffffffffffff00);
                local_728[0] = 0;
                local_6a8 = 0;
                cVar6 = FUN_001870c4(lVar17,&local_748,lVar31,local_728,&local_768,&local_6a8);
                if (((cVar6 == '\0') ||
                    (((char)local_768 != '\0' ||
                     (cVar6 = FUN_002b0838(&local_748,lVar31,7), cVar6 == '\0')))) ||
                   ((cVar6 = FUN_001872f8(lVar17,&local_748,lVar31), cVar6 == '\0' ||
                    ((((cVar6 = FUN_002b0838(&local_748,lVar31,
                                             (ulong)(local_854 + 2) * (ulong)((int)uVar38 - 1) *
                                             0x22), cVar6 == '\0' ||
                       (cVar6 = FUN_002b0838(&local_748,lVar31,2), cVar6 == '\0')) ||
                      (cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,&local_3f8), cVar6 == '\0'
                      )) || ((cVar6 = FUN_002b0838(&local_748,lVar31,2), cVar6 == '\0' ||
                             (cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,local_3d8),
                             cVar6 == '\0')))))))) goto LAB_002bbabc;
                if (local_854 == 4) {
                  cVar6 = FUN_002b0838(&local_748,lVar31,2);
                  if (((cVar6 == '\0') ||
                      (cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,auStack_3b8),
                      cVar6 == '\0')) ||
                     ((cVar6 = FUN_002b0838(&local_748,lVar31,2), cVar6 == '\0' ||
                      (((cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,auStack_398),
                        cVar6 == '\0' || (cVar6 = FUN_002b0838(&local_748,lVar31,2), cVar6 == '\0'))
                       || (cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,local_378),
                          cVar6 == '\0')))))) goto LAB_002bbabc;
                  cVar6 = FUN_002b0838(&local_748,lVar31,2);
                  puVar25 = local_358;
                  if (cVar6 == '\0') goto LAB_002bbabc;
                }
                else {
                  cVar6 = FUN_002b0838(&local_748,lVar31,2);
                  if (cVar6 == '\0') goto LAB_002bbabc;
                  puVar25 = auStack_3b8;
                }
                cVar6 = FUN_002b09c4(lVar17,&local_748,lVar31,0x20,puVar25);
                iVar8 = 0;
                if (cVar6 == '\0') goto LAB_002bbabc;
                goto LAB_002bb8c8;
              }
              cVar6 = FUN_002b0838(&local_748,lVar31,1);
            } while (cVar6 != '\0');
            local_6a8 = 0x4870124a3;
            FUN_002b1030(&local_6a8,8);
LAB_002bbabc:
            iVar8 = 2;
LAB_002bb8c8:
            local_6a8 = 0x2870f24a3;
            local_6a0 = CONCAT44((int)local_748,iVar8);
            FUN_002b1030(&local_6a8,0x10);
            if (iVar8 != 0) {
              uVar21 = 0xc;
              local_6a8 = 0x38b0b24a3;
              local_6a0 = CONCAT44(local_6a0._4_4_,iVar8);
LAB_002bb984:
              pvVar16 = (void *)0x0;
              FUN_002b1030(&local_6a8,uVar21);
              goto LAB_002ba944;
            }
            iVar8 = FUN_001882a8(local_854,auStack_4d0,local_854,&local_3f8);
            if (iVar8 != 0) {
              uVar18 = 0x8b0c;
LAB_002bb93c:
              local_6a8._0_4_ = CONCAT22(uVar18,0x24a3);
              local_6a8 = (ulong)CONCAT24(4,(undefined4)local_6a8);
              uVar21 = 8;
              goto LAB_002bb984;
            }
            local_3f8 = local_818 + local_510;
            local_3f0 = local_508;
            iVar8 = FUN_00187f1c(&local_3f8,param_7);
            if (iVar8 != 0) {
              uVar18 = 0x8b0d;
              goto LAB_002bb93c;
            }
            pvVar16 = (void *)0x0;
            local_3f8 = local_818 + local_500;
            local_3f0 = local_4f8;
            iVar12 = FUN_00187628(&local_3f8,param_6);
            iVar8 = 0;
            if (iVar12 != 0) {
              local_6a8 = 0x48b0e24a3;
              FUN_002b1030(&local_6a8,8);
              goto LAB_002ba944;
            }
          }
          else {
            uVar18 = 0xcb03;
            local_4d8 = lVar17;
LAB_002ba8e4:
            local_3f8._0_4_ = CONCAT22(uVar18,0x24a3);
            local_3f8 = (ulong)CONCAT14(3,(undefined4)local_3f8);
            uVar21 = 0xc;
            local_3f0 = CONCAT44(local_3f0._4_4_,(int)local_4d8);
LAB_002ba938:
            FUN_002b1030(&local_3f8,uVar21);
LAB_002ba944:
            iVar8 = 2;
          }
          FUN_002b2470((long)&local_620 + 4,&local_838);
          if (pvVar16 != (void *)0x0) goto LAB_002ba838;
        }
        else {
          uVar21 = 0xc;
          local_3f8 = 0x38b1024a3;
          local_3f0 = CONCAT44(local_3f0._4_4_,iVar8);
LAB_002ba828:
          iVar8 = 2;
          FUN_002b1030(&local_3f8,uVar21);
LAB_002ba838:
          operator_delete__(pvVar16);
        }
        if (iVar8 != 0) goto LAB_002ba7d4;
      }
      local_3f8 = 0x38b0f24a3;
      local_3f0 = CONCAT44(local_3f0._4_4_,iVar8);
      FUN_002b1030(&local_3f8,0xc);
      if (iVar8 == 0) goto LAB_002bba3c;
      uStack_31e = 0x8009;
    }
    uStack_319 = 0;
    uStack_31a = 0;
    uStack_31b = 0;
    uStack_31c = 4;
    local_320 = 0x24a3;
    FUN_002b1030((getCertificateInfoOutParam *)&local_320,8);
  }
  uVar9 = 0;
  if ((*param_3 != false) && (*param_4 != false)) goto LAB_002ba6c0;
LAB_002b929c:
  *(undefined8 *)(param_6 + 8) = 0;
  *param_7 = (TrustTime)0x0;
LAB_002ba6c0:
  uStack_31b = 0;
  uStack_31c = 3;
  uStack_31a = 0;
  local_320 = 0x24a3;
  uStack_319 = 0;
  uStack_31e = 0x800f;
  local_318 = uVar9;
  FUN_002b1030(&local_320,0xc);
  return uVar9;
}

