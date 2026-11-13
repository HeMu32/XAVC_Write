// FUN_0033edc8
// Ghidra address: 0033edc8

undefined4 FUN_0033edc8(long param_1,long *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  void *pvVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  ulong uVar14;
  void *__dest;
  long lVar15;
  size_t __n;
  ulong uVar16;
  int local_e0;
  long local_d0;
  undefined1 local_b1;
  string asStack_b0 [8];
  ulong local_a8;
  undefined1 *local_90;
  undefined8 local_88;
  undefined1 local_80 [16];
  undefined4 local_70 [8];
  undefined1 local_50 [4];
  int local_4c;
  undefined4 local_48;
  undefined1 local_44;
  void *local_40;
  undefined1 *local_38;
  undefined1 *local_30;
  int local_28;
  undefined1 local_24;
  undefined1 *local_20;
  undefined8 local_18;
  undefined1 local_10 [16];
  
  local_20 = local_10;
  lVar15 = *param_2;
  bVar3 = false;
  lVar13 = param_2[1];
  bVar4 = false;
  local_10[0] = 0;
  bVar7 = false;
  local_50[0] = 0;
  local_44 = 0;
  local_24 = 0;
  bVar5 = false;
  local_d0 = 0;
  bVar8 = false;
  bVar6 = false;
  local_4c = 0;
  local_48 = 0;
  local_40 = (void *)0x0;
  local_38 = (undefined1 *)0x0;
  local_30 = (undefined1 *)0x0;
  local_28 = 0;
  local_18 = 0;
  do {
    local_e0 = (int)((ulong)(lVar13 - lVar15) >> 5);
    if (local_e0 <= (int)local_d0 * 2) {
      local_70[0] = 0;
      iVar12 = FUN_0033360c(*(undefined8 *)(param_1 + 0x38),0xffffffff,local_50);
      uVar1 = 0;
      if (iVar12 != 0) {
        uVar1 = 8;
      }
      if (bVar4) {
        uVar1 = 8;
      }
      std::__cxx11::string::_M_dispose();
      if (local_40 != (void *)0x0) {
        operator_delete(local_40);
      }
      return uVar1;
    }
    std::__cxx11::string::string(asStack_b0,(string *)(*param_2 + local_d0 * 0x40 + 0x20));
    uVar10 = FUN_0034cd04(*param_2 + local_d0 * 0x40);
    if (uVar10 == 8) {
      if (bVar5) {
        bVar4 = true;
      }
      else {
        std::__cxx11::string::string((string *)local_70,asStack_b0);
        iVar12 = FUN_00349ca4((string *)local_70,&local_48);
        bVar5 = true;
        std::__cxx11::string::_M_dispose();
        if (iVar12 != 0) {
          bVar4 = true;
        }
      }
    }
    else if (uVar10 < 9) {
      if (uVar10 == 4) {
        if (bVar7) {
          bVar4 = true;
        }
        else {
          std::__cxx11::string::string((string *)local_70,asStack_b0);
          local_28 = FUN_0034acd4((string *)local_70);
          bVar7 = true;
          std::__cxx11::string::_M_dispose();
          if (local_28 == 4) {
            bVar4 = true;
          }
        }
      }
      else if (uVar10 == 7) {
        if (bVar8) {
          bVar4 = true;
        }
        else {
          std::__cxx11::string::_M_assign((string *)&local_20);
          local_24 = 1;
          bVar8 = true;
        }
      }
      else {
LAB_0033eebc:
        bVar4 = true;
      }
    }
    else if (uVar10 == 0x16) {
      if (bVar6) {
        bVar4 = true;
      }
      else {
        std::__cxx11::string::string((string *)local_70,asStack_b0);
        local_4c = FUN_0034cba4((string *)local_70);
        std::__cxx11::string::_M_dispose();
        if (local_4c == 3) {
          bVar4 = true;
          local_50[0] = 0;
          bVar6 = true;
        }
        else {
          local_50[0] = 1;
          bVar6 = true;
        }
      }
    }
    else {
      if (uVar10 != 0x17) goto LAB_0033eebc;
      if (bVar3) {
        bVar4 = true;
      }
      else {
        if ((uint)(local_a8 >> 1) < 0xed) {
          local_80[0] = 0;
          local_44 = 1;
          uVar10 = (uint)local_a8;
          local_88 = 0;
          local_90 = local_80;
          for (iVar12 = 0; iVar12 < 0xec && (uint)(iVar12 * 2) < uVar10; iVar12 = iVar12 + 1) {
            local_b1 = 0;
            local_88 = 0;
            *local_90 = 0;
            std::__cxx11::string::substr((ulong)asStack_b0,(ulong)(uint)(iVar12 * 2));
            std::__cxx11::string::append((string *)&local_90);
            std::__cxx11::string::_M_dispose();
            std::__cxx11::string::string((string *)local_70,(string *)&local_90);
            iVar11 = FUN_00349a20((string *)local_70,&local_b1);
            std::__cxx11::string::_M_dispose();
            if (iVar11 != 0) {
              local_44 = 0;
              bVar4 = true;
              break;
            }
            if (local_38 == local_30) {
              uVar14 = (long)local_38 - (long)local_40;
              if (uVar14 == 0xffffffffffffffff) {
                uVar14 = std::__throw_length_error("vector::_M_emplace_back_aux");
              }
              uVar2 = uVar14;
              if (uVar14 == 0) {
                uVar2 = 1;
              }
              uVar2 = uVar14 + uVar2;
              uVar16 = 0xffffffffffffffff;
              if ((uVar2 < uVar14) || (uVar16 = uVar2, uVar2 != 0)) {
                __dest = operator_new(uVar16);
              }
              else {
                uVar16 = 0;
                __dest = (void *)0x0;
              }
              pvVar9 = local_40;
              __n = (long)local_38 - (long)local_40;
              if ((long)__dest + __n != 0) {
                *(undefined1 *)((long)__dest + __n) = local_b1;
              }
              if (__n != 0) {
                __dest = memmove(__dest,local_40,__n);
              }
              if (pvVar9 != (void *)0x0) {
                operator_delete(pvVar9);
              }
              local_30 = (undefined1 *)((long)__dest + uVar16);
              local_40 = __dest;
              local_38 = (undefined1 *)((long)__dest + __n + 1);
            }
            else {
              if (local_38 != (undefined1 *)0x0) {
                *local_38 = local_b1;
              }
              local_38 = local_38 + 1;
            }
          }
          std::__cxx11::string::_M_dispose();
        }
        else {
          bVar4 = true;
        }
        bVar3 = true;
      }
    }
    std::__cxx11::string::_M_dispose();
    local_d0 = local_d0 + 1;
  } while( true );
}

