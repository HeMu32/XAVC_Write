// FUN_003543fc
// Ghidra address: 003543fc

undefined4 FUN_003543fc(long param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  int local_190;
  uint local_18c;
  undefined1 local_188 [4];
  undefined4 local_184;
  undefined1 local_180;
  undefined4 local_17c;
  undefined1 local_178;
  undefined4 local_174;
  undefined4 local_170;
  char local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined1 local_160;
  undefined1 *local_158;
  undefined8 uStack_150;
  undefined1 local_148 [16];
  undefined4 local_138;
  char local_134;
  undefined4 local_130;
  int local_12c;
  undefined1 local_128;
  undefined1 *local_120;
  undefined8 uStack_118;
  undefined1 local_110 [16];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined1 auStack_b0 [72];
  char local_68;
  int local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  if (param_2 == (undefined2 *)0x0) {
    iVar2 = 2;
LAB_00354420:
    uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
    return uVar1;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *(undefined4 *)(param_2 + 0x1a) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 1;
  *(undefined1 *)((long)param_2 + 5) = 0;
  *(undefined4 *)(param_2 + 0x1e) = 0x2b;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined4 *)(param_2 + 0x20) = 7;
  *(undefined1 *)((long)param_2 + 7) = 0;
  *(undefined4 *)(param_2 + 0x22) = 5;
  *(undefined1 *)(param_2 + 4) = 0;
  *param_2 = 0;
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 0x16) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  local_60 = 0;
  uStack_58 = 0;
  *(undefined8 *)(param_2 + 5) = 0;
  *(undefined8 *)(param_2 + 9) = 0;
  *(undefined8 *)(param_2 + 0xd) = 0;
  *(undefined8 *)(param_2 + 0x11) = 0;
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uVar3 = *(undefined8 *)(param_1 + 8);
  *(undefined1 *)(param_2 + 0x24) = 0;
  iVar2 = FUN_0033ac78(uVar3);
  if (iVar2 != 0) goto LAB_00354420;
  FUN_00352c80(&local_60);
  iVar2 = FUN_0033ad00(*(undefined8 *)(param_1 + 8),0,&local_60);
  if (iVar2 == 0) {
    if ((char)local_50 != '\0') {
      *(ulong *)(param_2 + 0x1a) = CONCAT44(uStack_48,uStack_4c);
    }
    local_188[0] = 0;
    local_180 = 0;
    local_178 = 0;
    local_184 = 0;
    local_17c = 0;
    local_174 = 0;
    iVar2 = FUN_0033ada8(*(undefined8 *)(param_1 + 8),local_188);
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x1e) = local_184;
      *(undefined4 *)(param_2 + 0x20) = local_17c;
      *(undefined4 *)(param_2 + 0x22) = local_174;
    }
    else if (iVar2 != 1) goto LAB_003544dc;
    local_190 = 0;
    iVar2 = FUN_0033ac68(*(undefined8 *)(param_1 + 8),&local_190);
    if (iVar2 == 0) {
      local_158 = local_148;
      uStack_150 = 0;
      local_148[0] = 0;
      local_16c = '\0';
      local_160 = 0;
      local_170 = 0;
      local_168 = 0;
      uStack_164 = 0;
      iVar2 = FUN_0033ac70(*(undefined8 *)(param_1 + 8),0,&local_170);
      if (iVar2 == 0) {
        if (local_16c != '\0') {
          *(undefined4 *)(param_2 + 0x16) = local_168;
        }
        local_120 = local_110;
        uStack_118 = 0;
        local_110[0] = 0;
        local_134 = '\0';
        local_128 = 0;
        local_138 = 0;
        local_130 = 0;
        local_12c = 0;
        iVar2 = FUN_0033ac70(*(undefined8 *)(param_1 + 8),local_190 + -1,&local_138);
        if (iVar2 == 0) {
          if ((local_134 != '\0') && (local_12c == 2)) {
            *(undefined4 *)(param_2 + 0x18) = local_130;
          }
          FUN_00352c30(&local_100);
          iVar2 = FUN_0033ac50(*(undefined8 *)(param_1 + 8),&local_100);
          if (iVar2 == 0) {
            local_18c = 0;
            *(undefined8 *)(param_2 + 5) = local_100;
            *(undefined8 *)(param_2 + 9) = uStack_f8;
            *(undefined8 *)(param_2 + 0xd) = local_f0;
            *(undefined8 *)(param_2 + 0x11) = uStack_e8;
            iVar2 = FUN_0033ae40(*(undefined8 *)(param_1 + 8),&local_18c);
            if (iVar2 == 0) {
              if (local_18c != 0) {
                for (uVar4 = 0; uVar4 < local_18c; uVar4 = uVar4 + 1) {
                  FUN_00352d18(auStack_b0);
                  iVar2 = FUN_0033ae48(*(undefined8 *)(param_1 + 8),uVar4,auStack_b0);
                  if (iVar2 != 0) {
                    uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
                    std::__cxx11::string::_M_dispose();
                    goto LAB_003546cc;
                  }
                  if ((local_68 != '\0') && (local_64 == 0x10)) {
                    *(undefined1 *)(param_2 + 0x24) = 1;
                    std::__cxx11::string::_M_dispose();
                    break;
                  }
                  std::__cxx11::string::_M_dispose();
                }
              }
              iVar2 = 0;
            }
            else if (iVar2 == 1) {
              iVar2 = 0;
            }
          }
          uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
LAB_003546cc:
          std::__cxx11::string::_M_dispose();
        }
        else {
          uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
        }
        std::__cxx11::string::_M_dispose();
      }
      else {
        uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
      }
      std::__cxx11::string::_M_dispose();
      goto LAB_003544e4;
    }
  }
LAB_003544dc:
  uVar1 = NRTERRCNV::ConvToMPR2(iVar2);
LAB_003544e4:
  std::__cxx11::string::_M_dispose();
  return uVar1;
}

