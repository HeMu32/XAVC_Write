// FUN_003299ec
// Ghidra address: 003299ec

/* WARNING: Type propagation algorithm not settling */

int FUN_003299ec(long param_1,undefined8 param_2,uint *param_3,uint *param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined2 uVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_194 [3];
  undefined8 local_188;
  int local_180 [2];
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined1 auStack_158 [8];
  int local_150;
  undefined1 auStack_148 [16];
  undefined8 local_138;
  uint local_130;
  uint local_12c;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_194[0] = 0;
  FUN_002c8f64(param_2,local_194);
  iVar6 = FUN_00322428();
  if (iVar6 != 0) {
    local_58 = CONCAT44(local_58._4_4_,iVar6);
    local_60 = 0x301002301;
    FUN_00322494(&local_60,0xc);
  }
  uVar12 = 0x61766331;
  uVar13 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  uVar11 = 0;
  *param_4 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_a8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  for (uVar10 = 1; uVar10 <= local_194[0]; uVar10 = uVar10 + 1) {
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    uStack_28 = 0;
    local_20 = 0;
    uStack_18 = 0;
    local_10 = 0;
    uStack_8 = 0;
    FUN_002c8ffc(param_2,uVar10,&local_60);
    iVar6 = FUN_00322428();
    uVar3 = uVar13;
    uVar4 = uVar11;
    if (iVar6 == 0) {
      if ((local_60 & 1) != 0) {
        local_118 = 0;
        local_128 = 0;
        uStack_120 = 0;
        FUN_002c91e4(param_2,uVar10,&local_128);
        iVar6 = FUN_00322428();
        if (iVar6 != 0) {
          uVar8 = 0x102;
          goto LAB_00329b48;
        }
        if (((int)local_128 != 0x76696465) &&
           ((int)local_128 != 0x736f756e && (int)local_128 != 0x6d657461)) goto LAB_00329b60;
        local_194[1] = 0;
        local_188 = 0;
        FUN_002c9658(param_2,uVar10,0,&local_188);
        iVar6 = FUN_00322428();
        if (iVar6 == 0) {
          FUN_002c9a60(param_2,local_188,local_194 + 1,auStack_148,local_180);
          iVar6 = FUN_00322428();
          if (iVar6 == 0) {
            FUN_002c9630(param_2,local_188);
            local_188 = 0;
            if (local_180[0] != 1 && local_180[0] != 0x10) goto LAB_00329b60;
            local_194[2] = 0;
            local_178 = 0;
            FUN_002c9284(param_2,uVar10);
            FUN_002cbe98(param_2,uVar10,&local_178);
            iVar6 = FUN_00322428();
            if (iVar6 == 0) {
              FUN_002cbfb4(param_2,local_178,local_194 + 2);
              iVar6 = FUN_00322428();
              if (iVar6 != 0) {
                local_98 = CONCAT44(local_98._4_4_,iVar6);
                local_a0 = 0x301062301;
                uVar9 = 0xc;
                goto LAB_00329d0c;
              }
              if (local_194[2] != 0) {
                local_168 = 0;
                local_160 = 0;
                local_100 = 0;
                local_a0 = 0;
                local_98 = 0;
                local_f8 = 0;
                local_70 = 0;
                local_90 = 0;
                uStack_88 = 0;
                local_68 = 0;
                local_80 = 0;
                uStack_78 = 0;
                local_110 = 0;
                local_108 = 0;
                if ((int)local_128 == 0x76696465) {
                  FUN_002cc004(param_2,local_178,1,&local_a0);
                  iVar6 = FUN_00322428();
                  if (iVar6 == 0) {
                    if ((int)local_a0 == 2) {
                      uVar12 = 0x61766331;
                    }
                    else {
                      if ((int)local_a0 != 0xb) goto LAB_00329d14;
                      uVar12 = 0x68766331;
                    }
                    uVar1 = (undefined4)local_98;
                    goto LAB_00329e30;
                  }
                  local_138._2_2_ = 0x107;
LAB_00329df4:
                  local_12c = 1;
                  local_130 = iVar6;
                }
                else {
                  if ((int)local_128 == 0x736f756e) {
                    FUN_002cc160(param_2,local_178,1,&local_110);
                    iVar6 = FUN_00322428();
                    if (iVar6 != 0) {
                      local_138._2_2_ = 0x108;
                      goto LAB_00329df4;
                    }
                    bVar5 = (int)local_110 == 3;
                    uVar1 = (undefined4)local_108;
                  }
                  else {
                    if ((int)local_128 != 0x6d657461) goto LAB_00329d14;
                    FUN_002cc8a8(param_2,local_178,1,&local_168);
                    iVar6 = FUN_00322428();
                    if (iVar6 != 0) {
                      local_138._2_2_ = 0x109;
                      goto LAB_00329df4;
                    }
                    bVar5 = (int)local_168 == 6;
                    uVar1 = local_160;
                  }
                  if (!bVar5) goto LAB_00329d14;
LAB_00329e30:
                  local_170 = 0;
                  FUN_002cbb5c(param_2,uVar10,&local_170);
                  iVar6 = FUN_00322428();
                  if (iVar6 == 0) {
                    FUN_002cbc8c(param_2,local_170,uVar1,auStack_158);
                    FUN_002cbb34(param_2,local_170);
                    local_170 = 0;
                    FUN_002cbe70(param_2,local_178);
                    local_178 = 0;
                    if (local_150 == 0) {
                      uVar4 = uVar10;
                      uVar2 = uVar11;
                      if ((int)local_128 == 0x76696465) {
joined_r0x00329e9c:
                        if (uVar2 != 0) {
LAB_00329ea0:
                          FUN_002c93d0(param_2,uVar10);
                          uVar3 = uVar13;
                          uVar4 = uVar11;
                        }
                      }
                      else {
                        if ((int)local_128 != 0x736f756e) {
                          uVar4 = uVar11;
                          uVar3 = uVar10;
                          uVar2 = uVar13;
                          if ((int)local_128 == 0x6d657461) goto joined_r0x00329e9c;
                          goto LAB_00329ea0;
                        }
                        uVar13 = *param_4;
                        if (3 < uVar13) {
                          local_138._5_1_ = 0;
                          local_138._4_1_ = 3;
                          local_138._6_1_ = 0;
                          local_138._0_2_ = 0x2301;
                          local_138._7_1_ = 0;
                          local_138._2_2_ = 0x114;
                          local_130 = uVar13;
                          FUN_00322494(&local_138,0xc);
                          *param_4 = 0;
                          return 5;
                        }
                        uVar4 = uVar11;
                        if (param_4[(ulong)uVar13 + 1] == 0) {
                          param_4[(ulong)uVar13 + 1] = uVar10;
                          *param_4 = uVar13 + 1;
                        }
                      }
                    }
                    goto LAB_00329b60;
                  }
                  local_138._2_2_ = 0x10a;
                  local_130 = iVar6;
                  local_12c = uVar10;
                }
                local_138._7_1_ = 0;
                local_138._6_1_ = 0;
                local_138._5_1_ = 0;
                local_138._4_1_ = 2;
                local_138._0_2_ = 0x2301;
                uVar9 = 0x10;
                puVar7 = &local_138;
                goto LAB_00329d10;
              }
            }
            else {
              local_a0 = 0x201052301;
              uVar9 = 0x10;
              local_98 = CONCAT44(uVar10,iVar6);
LAB_00329d0c:
              puVar7 = &local_a0;
LAB_00329d10:
              FUN_00322494(puVar7,uVar9);
            }
LAB_00329d14:
            FUN_002cbe70(param_2,local_178);
            goto LAB_00329b60;
          }
          uVar8 = 0x104;
        }
        else {
          uVar8 = 0x103;
        }
        local_a0._0_4_ = CONCAT22(uVar8,0x2301);
        local_a0 = (ulong)CONCAT24(2,(int)local_a0);
        local_98 = CONCAT44(uVar10,iVar6);
        FUN_00322494(&local_a0,0x10);
        FUN_002c9630(param_2,local_188);
      }
    }
    else {
      uVar8 = 0x101;
LAB_00329b48:
      local_a0._0_4_ = CONCAT22(uVar8,0x2301);
      local_a0 = (ulong)CONCAT24(2,(int)local_a0);
      local_98 = CONCAT44(uVar10,iVar6);
      FUN_00322494(&local_a0,0x10);
    }
LAB_00329b60:
    uVar11 = uVar4;
    uVar13 = uVar3;
  }
  *param_3 = uVar11;
  *param_5 = uVar13;
  FUN_002c9120(param_2,uVar11,&local_c8);
  iVar6 = FUN_00322428();
  if (iVar6 == 0) {
    uVar10 = param_4[1];
    param_3[1] = (uint)local_b8;
    FUN_002c9120(param_2,uVar10,&local_c8);
    iVar6 = FUN_00322428();
    if (iVar6 == 0) {
      uVar10 = *param_5;
      param_4[6] = (uint)local_b8;
      FUN_002c9120(param_2,uVar10,&local_c8);
      iVar6 = FUN_00322428();
      if (iVar6 != 0) {
        local_60 = 0x2010d2301;
        local_58._0_4_ = iVar6;
LAB_0032a16c:
        uVar10 = *param_5;
        goto LAB_0032a0c0;
      }
      uVar10 = *param_3;
      param_5[1] = (uint)local_b8;
      FUN_002ced48(*(undefined8 *)(param_1 + 0x108),uVar10,param_3 + 2);
      iVar6 = FUN_00322428();
      if (iVar6 != 0) {
        uVar8 = 0x10e;
        local_58._0_4_ = iVar6;
        goto LAB_0032a0b4;
      }
      FUN_002ced48(*(undefined8 *)(param_1 + 0x108),param_4[1],param_4 + 7);
      iVar6 = FUN_00322428();
      if (iVar6 == 0) {
        FUN_002c8510(param_2,1,&local_f0);
        iVar6 = FUN_00322428();
        if (iVar6 != 0) {
          uVar9 = 0xc;
          local_58 = CONCAT44(local_58._4_4_,iVar6);
          local_60 = 0x301102301;
          goto LAB_0032a244;
        }
        param_3[3] = CONCAT22((undefined2)local_d8,local_d8._2_2_);
        param_3[4] = uVar12;
        FUN_002cbe98(param_2,*param_3,param_3 + 0x26);
        iVar6 = FUN_00322428();
        if (iVar6 != 0) {
          uVar8 = 0x111;
          local_58._0_4_ = iVar6;
          goto LAB_0032a0b4;
        }
        FUN_002cbe98(param_2,param_4[1],param_4 + 10);
        iVar6 = FUN_00322428();
        if (iVar6 == 0) {
          FUN_002cbe98(param_2,*param_5,param_5 + 2);
          iVar6 = FUN_00322428();
          if (iVar6 == 0) {
            FUN_00324ad4(param_1,*(undefined4 *)(param_1 + 0x1d8),1,*(undefined8 *)(param_1 + 0x260)
                         ,param_3 + 0x28);
            FUN_002cedb8(param_2,*param_3,1,0,param_3 + 8,0);
            iVar6 = FUN_00322428();
            FUN_00329664(param_1,param_2,*param_3,param_3[2],*(undefined8 *)(param_3 + 0x2c));
            return iVar6;
          }
          local_60 = 0x201132301;
          local_58._0_4_ = iVar6;
          goto LAB_0032a16c;
        }
        uVar8 = 0x112;
        local_58._0_4_ = iVar6;
      }
      else {
        uVar8 = 0x10f;
        local_58._0_4_ = iVar6;
      }
    }
    else {
      uVar8 = 0x10c;
      local_58._0_4_ = iVar6;
    }
    local_60._0_4_ = CONCAT22(uVar8,0x2301);
    local_60 = CONCAT44(2,(undefined4)local_60);
    uVar10 = param_4[1];
  }
  else {
    uVar8 = 0x10b;
    local_58._0_4_ = iVar6;
LAB_0032a0b4:
    local_60._0_4_ = CONCAT22(uVar8,0x2301);
    local_60 = CONCAT44(2,(undefined4)local_60);
    uVar10 = *param_3;
  }
LAB_0032a0c0:
  uVar9 = 0x10;
  local_58 = CONCAT44(uVar10,(int)local_58);
  iVar6 = (int)local_58;
LAB_0032a244:
  FUN_00322494(&local_60,uVar9);
  return iVar6;
}

