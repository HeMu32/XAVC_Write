// FUN_00331d84
// Ghidra address: 00331d84

undefined4 FUN_00331d84(long param_1,undefined4 param_2,undefined1 *param_3)

{
  long *plVar1;
  ulong uVar2;
  undefined1 *puVar3;
  void *__src;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  void *__dest;
  size_t __n;
  ulong uVar13;
  undefined1 local_61;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [16];
  undefined1 *local_40;
  undefined8 uStack_38;
  undefined1 local_30 [16];
  string asStack_20 [32];
  
  if (param_3 == (undefined1 *)0x0) {
    uVar8 = 2;
  }
  else if (*(long *)(param_1 + 0x10) == 0) {
    uVar8 = 3;
  }
  else {
    lVar10 = FUN_0032ca5c(param_1,*(long *)(param_1 + 0x10),0xc,0);
    if ((lVar10 != 0) && (lVar10 = FUN_0032ca5c(param_1,lVar10,0x23,param_2), lVar10 != 0)) {
      lVar11 = FUN_0032c960(param_1,lVar10,0x16);
      if (lVar11 == 0) {
        *param_3 = 0;
      }
      else {
        local_40 = local_30;
        uStack_38 = 0;
        local_30[0] = 0;
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)&local_40,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::string(asStack_20,(string *)&local_40);
        uVar8 = FUN_0034cba4(asStack_20);
        *(undefined4 *)(param_3 + 4) = uVar8;
        std::__cxx11::string::_M_dispose();
        *param_3 = 1;
        std::__cxx11::string::_M_dispose();
      }
      lVar11 = FUN_0032c960(param_1,lVar10,8);
      if (lVar11 == 0) {
        uVar8 = 0;
        bVar4 = true;
      }
      else {
        local_40 = local_30;
        uStack_38 = 0;
        local_30[0] = 0;
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)&local_40,asStack_20);
        std::__cxx11::string::_M_dispose();
        local_60 = (undefined1 *)((ulong)local_60._4_4_ << 0x20);
        std::__cxx11::string::string(asStack_20,(string *)&local_40);
        iVar6 = FUN_00349ca4(asStack_20,&local_60);
        std::__cxx11::string::_M_dispose();
        if (iVar6 == 0) {
          *(undefined4 *)(param_3 + 8) = (undefined4)local_60;
          uVar8 = 0;
        }
        else {
          uVar8 = 4;
        }
        std::__cxx11::string::_M_dispose();
        bVar4 = false;
      }
      lVar11 = FUN_0032c960(param_1,lVar10,0x17);
      if (lVar11 == 0) {
        param_3[0xc] = 0;
      }
      else {
        local_60 = local_50;
        local_58 = 0;
        local_50[0] = 0;
        plVar1 = (long *)(param_3 + 0x10);
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)&local_60,asStack_20);
        std::__cxx11::string::_M_dispose();
        local_30[0] = 0;
        local_40 = local_30;
        uStack_38 = 0;
        uVar5 = (uint)local_58;
        for (iVar6 = 0; iVar6 < 0xec && (uint)(iVar6 * 2) < uVar5; iVar6 = iVar6 + 1) {
          local_61 = 0;
          std::__cxx11::string::substr((ulong)&local_60,(ulong)(uint)(iVar6 * 2));
          std::__cxx11::string::assign((string *)&local_40);
          std::__cxx11::string::_M_dispose();
          std::__cxx11::string::string(asStack_20,(string *)&local_40);
          iVar9 = FUN_00349a20(asStack_20,&local_61);
          std::__cxx11::string::_M_dispose();
          if (iVar9 != 0) {
            uVar8 = 5;
            break;
          }
          puVar3 = *(undefined1 **)(param_3 + 0x18);
          if (puVar3 == *(undefined1 **)(param_3 + 0x20)) {
            uVar12 = (long)puVar3 - *plVar1;
            if (uVar12 == 0xffffffffffffffff) {
              uVar12 = std::__throw_length_error("vector::_M_emplace_back_aux");
            }
            uVar2 = uVar12;
            if (uVar12 == 0) {
              uVar2 = 1;
            }
            uVar2 = uVar12 + uVar2;
            uVar13 = 0xffffffffffffffff;
            if ((uVar2 < uVar12) || (uVar13 = uVar2, uVar2 != 0)) {
              __dest = operator_new(uVar13);
            }
            else {
              uVar13 = 0;
              __dest = (void *)0x0;
            }
            __src = (void *)*plVar1;
            __n = *(long *)(param_3 + 0x18) - (long)__src;
            if ((long)__dest + __n != 0) {
              *(undefined1 *)((long)__dest + __n) = local_61;
            }
            if (__n != 0) {
              __dest = memmove(__dest,__src,__n);
            }
            if (__src != (void *)0x0) {
              operator_delete(__src);
            }
            *plVar1 = (long)__dest;
            *(size_t *)(param_3 + 0x18) = (long)__dest + __n + 1;
            *(ulong *)(param_3 + 0x20) = (long)__dest + uVar13;
          }
          else {
            if (puVar3 != (undefined1 *)0x0) {
              *puVar3 = local_61;
            }
            *(long *)(param_3 + 0x18) = *(long *)(param_3 + 0x18) + 1;
          }
        }
        param_3[0xc] = 1;
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      lVar11 = FUN_0032c960(param_1,lVar10,4);
      if (lVar11 == 0) {
        bVar4 = true;
      }
      else {
        local_40 = local_30;
        uStack_38 = 0;
        local_30[0] = 0;
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)&local_40,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::string(asStack_20,(string *)&local_40);
        uVar7 = FUN_0034acd4(asStack_20);
        *(undefined4 *)(param_3 + 0x28) = uVar7;
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      lVar10 = FUN_0032c960(param_1,lVar10,7);
      if (lVar10 != 0) {
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)(param_3 + 0x30),asStack_20);
        std::__cxx11::string::_M_dispose();
        param_3[0x2c] = 1;
      }
      if (!bVar4) {
        return uVar8;
      }
    }
    uVar8 = 1;
  }
  return uVar8;
}

