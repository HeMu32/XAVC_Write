// Normalized static image, not an observed export trace.
// Preferred VA 1802352b0
// Disassembly returned true; body bytes 134

undefined8 loaded_1802352b0(undefined8 param_1,longlong *param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  uVar2 = _GetManager___CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEBAPEAUIAtlStringMgr_2_XZ
                    (param_2);
  __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_PEAUIAtlStringMgr_1__Z
            (param_1,uVar2);
  if (param_3 != 0) {
    uVar1 = func_0x000180591eea(param_3);
  }
  _Concatenate___CSimpleStringT__W_00_ATL__KAXAEAV12_PEB_WH1H_Z
            (param_1,*param_2,*(undefined4 *)(*param_2 + -0x10),param_3,uVar1);
  return param_1;
}

