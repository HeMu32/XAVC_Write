// FUN_180093790
// VA 180093790

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_180093790(undefined8 *param_1,undefined8 *param_2,DWORD param_3,DWORD param_4,
             LPSECURITY_ATTRIBUTES param_5,DWORD param_6,DWORD param_7,HANDLE param_8)

{
  undefined *puVar1;
  ulonglong uVar2;
  HANDLE pvVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  wchar_t *pwVar7;
  void *_Memory;
  wchar_t *******pppppppwVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined1 auStackY_138 [32];
  undefined1 local_f8 [8];
  uint local_f0;
  undefined8 *local_e8;
  undefined8 *local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 *local_c0;
  undefined1 *local_b8;
  undefined1 local_b0;
  undefined8 *local_a8;
  wchar_t ******local_a0;
  undefined8 uStack_98;
  undefined *local_90;
  ulonglong uStack_88;
  wchar_t local_80;
  undefined6 uStack_7e;
  ulonglong uStack_68;
  ulonglong local_60;
  
  local_60 = DAT_18012b700 ^ (ulonglong)auStackY_138;
  uVar10 = 0;
  local_f0 = 0;
  local_d0 = *param_2;
  local_c8 = param_2[1];
  local_e8 = param_1;
  local_e0 = param_2;
  local_a8 = param_1;
  FUN_180093730((undefined8 *)&local_80,&local_d0);
  pwVar7 = &local_80;
  if (7 < uStack_68) {
    pwVar7 = (wchar_t *)CONCAT62(uStack_7e,local_80);
  }
  pvVar3 = FUN_18009f270(pwVar7,param_3,param_4,param_5,param_6,param_7,param_8);
  if (pvVar3 == (HANDLE)0xffffffffffffffff) {
    *local_e8 = 0;
    local_e8[1] = 0;
    local_f0 = 1;
    if (uStack_68 < 8) {
      return local_e8;
    }
    _Memory = (void *)CONCAT62(uStack_7e,local_80);
    puVar9 = local_e8;
    if (uStack_68 * 2 + 2 < 0x1000) goto LAB_180093893;
    lVar4 = (longlong)_Memory - (longlong)*(void **)((longlong)_Memory + -8);
    _Memory = *(void **)((longlong)_Memory + -8);
  }
  else {
    puVar5 = (undefined8 *)FUN_1800baa00(0x28);
    local_d8 = puVar5;
    if (puVar5 == (undefined8 *)0x0) {
      puVar5 = (undefined8 *)0x0;
    }
    else {
      local_a0 = (wchar_t ******)0x0;
      uStack_98 = 0;
      local_90 = (undefined *)0x0;
      uStack_88 = 0;
      FUN_180005090(&local_a0,(void *)*local_e0,local_e0[1]);
      uVar10 = 2;
      local_f0 = 2;
      pppppppwVar8 = &local_a0;
      if (7 < uStack_88) {
        pppppppwVar8 = (wchar_t *******)local_a0;
      }
      puVar5 = FUN_1800934f0(puVar5,pvVar3,(wchar_t *)pppppppwVar8);
    }
    puVar9 = local_e8;
    puVar6 = (undefined8 *)0x0;
    *local_e8 = 0;
    local_e8[1] = 0;
    local_b8 = local_f8;
    local_b0 = 1;
    local_c0 = puVar5;
    local_d8 = (undefined8 *)FUN_1800baa00(0x18);
    if (local_d8 != (undefined8 *)0x0) {
      *local_d8 = 0;
      local_d8[1] = 0;
      *(undefined4 *)(local_d8 + 1) = 1;
      *(undefined4 *)((longlong)local_d8 + 0xc) = 1;
      *local_d8 = std::
                  _Ref_count_resource<CtsHandle*___ptr64,`class_std::shared_ptr<CtsHandle>___cdecl_CtsFileUtil::detail::_CreateFile(std::basic_string_view<wchar_t,std::char_traits<wchar_t>_>_const&___ptr64,unsigned_long,unsigned_long,_SECURITY_ATTRIBUTES*___ptr64,unsigned_long,unsigned_long,void*___ptr64)'::`2'::<lambda_1>_>
                  ::vftable;
      local_d8[2] = puVar5;
      puVar6 = local_d8;
    }
    *puVar9 = puVar5;
    puVar9[1] = puVar6;
    uVar2 = _UNK_1800ce4e8;
    puVar1 = PTR_1800ce4e0;
    local_b0 = 0;
    local_f0 = uVar10 | 1;
    if (uVar10 != 0) {
      local_f0 = 1;
      if (7 < uStack_88) {
        pppppppwVar8 = (wchar_t *******)local_a0;
        if ((0xfff < uStack_88 * 2 + 2) &&
           (pppppppwVar8 = (wchar_t *******)local_a0[-1],
           0x1f < (ulonglong)((longlong)local_a0 + (-8 - (longlong)pppppppwVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        free(pppppppwVar8);
      }
      local_90 = puVar1;
      uStack_88 = uVar2;
      local_a0 = (wchar_t ******)((ulonglong)local_a0 & 0xffffffffffff0000);
    }
    if (uStack_68 < 8) {
      return puVar9;
    }
    _Memory = (void *)CONCAT62(uStack_7e,local_80);
    if (uStack_68 * 2 + 2 < 0x1000) goto LAB_180093893;
    lVar4 = (longlong)_Memory - (longlong)*(void **)((longlong)_Memory + -8);
    _Memory = *(void **)((longlong)_Memory + -8);
  }
  if (0x1f < lVar4 - 8U) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
LAB_180093893:
  free(_Memory);
  return puVar9;
}

