// Normalized static image, not an observed export trace.
// Preferred VA 180237b80
// Disassembly returned true; body bytes 4205

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_180237b80(longlong param_1,longlong *param_2)

{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 ****ppppuVar6;
  code *pcVar7;
  undefined8 ****ppppuVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined8 *****pppppuVar14;
  undefined8 *****pppppuVar15;
  undefined8 *****pppppuVar16;
  undefined8 ****ppppuVar17;
  longlong *plVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  undefined8 ******ppppppuVar22;
  undefined8 *puVar23;
  ulonglong uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined1 auStack_2a8 [32];
  undefined8 uStack_288;
  undefined8 *****pppppuStack_278;
  undefined8 ****ppppuStack_270;
  undefined8 ****ppppuStack_268;
  undefined8 ****ppppuStack_260;
  undefined *puStack_258;
  undefined8 *puStack_250;
  undefined4 uStack_248;
  undefined4 uStack_244;
  uint uStack_240;
  undefined4 uStack_23c;
  undefined8 *****pppppuStack_238;
  longlong *plStack_230;
  int iStack_228;
  undefined4 uStack_224;
  int iStack_220;
  longlong *plStack_218;
  undefined8 ****ppppuStack_210;
  undefined4 *puStack_208;
  undefined *puStack_200;
  longlong lStack_1f8;
  longlong lStack_1f0;
  longlong lStack_1e8;
  byte abStack_1e0 [4];
  undefined4 uStack_1dc;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 ****ppppuStack_1c0;
  undefined8 uStack_1b8;
  undefined1 auStack_1b0 [8];
  undefined8 uStack_1a8;
  undefined8 *****pppppuStack_1a0;
  undefined8 ****ppppuStack_198;
  ulonglong uStack_190;
  undefined8 ****ppppuStack_188;
  undefined8 *****pppppuStack_180;
  undefined8 ****ppppuStack_178;
  ulonglong uStack_170;
  undefined8 ****ppppuStack_168;
  undefined8 ****ppppuStack_160;
  undefined1 auStack_158 [272];
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18092d280 ^ (ulonglong)auStack_2a8;
  uVar25 = 0;
  uStack_248 = 0;
  ppppuStack_268 = *(undefined8 *****)(param_1 + 0x178);
  ppppuStack_260 = (undefined8 ****)(longlong)*(int *)(ppppuStack_268 + -2);
  FUN_180431bd0(auStack_158,&ppppuStack_268,1);
  puVar13 = (undefined8 *)func_0x000180433d70(auStack_158,&pppppuStack_180);
  __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_PEB_W_Z
            (&uStack_1b8,*puVar13);
  puVar13 = (undefined8 *)FUN_180434550(auStack_158,&pppppuStack_180,0,0);
  __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_PEB_W_Z
            (&ppppuStack_1c0,*puVar13);
  ppppuStack_260 = (undefined8 ****)(longlong)*(int *)(ppppuStack_1c0 + -2);
  ppppuStack_268 = ppppuStack_1c0;
  FUN_180434bc0(&pppppuStack_180,&ppppuStack_268,0);
  uStack_248 = 2;
  pppppuStack_278 = &pppppuStack_180;
  if (7 < ppppuStack_168) {
    pppppuStack_278 = pppppuStack_180;
  }
  ppppuStack_270 = (undefined8 ****)uStack_170;
  FUN_180432340(&pppppuStack_1a0,&pppppuStack_278);
  uStack_248 = 6;
  ppppppuVar22 = &pppppuStack_1a0;
  if (7 < ppppuStack_188) {
    ppppppuVar22 = (undefined8 ******)pppppuStack_1a0;
  }
  __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_PEB_W_Z
            (&uStack_1c8,ppppppuVar22);
  uStack_248 = 2;
  if (7 < ppppuStack_188) {
    if ((0xfff < (longlong)ppppuStack_188 * 2 + 2U) &&
       (0x1f < (ulonglong)((longlong)pppppuStack_1a0 + (-8 - (longlong)pppppuStack_1a0[-1])))) {
      uStack_288 = 0;
      _invoke_watson(0,0,0,0);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    func_0x00018058eb90();
  }
  uStack_190 = _DAT_1806f4460;
  ppppuStack_188 = _UNK_1806f4468;
  pppppuStack_1a0 = (undefined8 *****)((ulonglong)pppppuStack_1a0 & 0xffffffffffff0000);
  uStack_248 = 0;
  if (7 < ppppuStack_168) {
    if ((0xfff < (longlong)ppppuStack_168 * 2 + 2U) &&
       (0x1f < (ulonglong)((longlong)pppppuStack_180 + (-8 - (longlong)pppppuStack_180[-1])))) {
      uStack_288 = 0;
      _invoke_watson(0,0,0,0);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    func_0x00018058eb90();
  }
  uStack_170 = _DAT_1806f4460;
  ppppuStack_168 = _UNK_1806f4468;
  pppppuStack_180 = (undefined8 *****)((ulonglong)pppppuStack_180 & 0xffffffffffff0000);
  puVar13 = (undefined8 *)FUN_1801ce920(&uStack_240,uStack_1b8,0,1);
  ppppuStack_268 = (undefined8 ****)*puVar13;
  ppppuStack_260 = (undefined8 ****)(longlong)*(int *)(ppppuStack_268 + -2);
  ppppuStack_270 = (undefined8 ****)(longlong)*(int *)(ppppuStack_1c0 + -2);
  pppppuStack_278 = (undefined8 *****)ppppuStack_1c0;
  FUN_180433160(&pppppuStack_1a0,&pppppuStack_278,&ppppuStack_268);
  ppppuVar17 = ppppuStack_188;
  pppppuVar14 = pppppuStack_1a0;
  pppppuStack_180 = pppppuStack_1a0;
  ppppuStack_178 = ppppuStack_198;
  uStack_170 = uStack_190;
  ppppuStack_168 = ppppuStack_188;
  uStack_248 = 8;
  uStack_190 = 0;
  ppppuStack_188 = (undefined8 *****)0x7;
  pppppuStack_1a0 = (undefined8 *****)((ulonglong)pppppuStack_1a0 & 0xffffffffffff0000);
  ppppppuVar22 = &pppppuStack_180;
  if ((undefined8 *****)0x7 < ppppuVar17) {
    ppppppuVar22 = (undefined8 ******)pppppuVar14;
  }
  __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_PEB_W_Z
            (&uStack_1d0,ppppppuVar22);
  uStack_248 = 0;
  if ((undefined8 *****)0x7 < ppppuStack_168) {
    if ((0xfff < (longlong)ppppuStack_168 * 2 + 2U) &&
       (0x1f < (ulonglong)((longlong)pppppuStack_180 + (-8 - (longlong)pppppuStack_180[-1])))) {
      uStack_288 = 0;
      _invoke_watson(0,0,0,0);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    func_0x00018058eb90();
  }
  uStack_170 = _DAT_1806f4460;
  ppppuStack_168 = _UNK_1806f4468;
  pppppuStack_180 = (undefined8 *****)((ulonglong)pppppuStack_180 & 0xffffffffffff0000);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_240);
  FUN_1801ce9c0(&pppppuStack_238,uStack_1c8,2);
  FUN_1801cd6e0(&uStack_1d8,param_1 + 0x1a0,0x20);
  iVar12 = *(int *)(param_1 + 0xa4);
  plStack_230 = (longlong *)0x0;
  plVar18 = (longlong *)((longlong)*(int *)(*(longlong *)(param_1 + 0x20) + 0xc) + 0x20 + param_1);
  iStack_228 = iVar12;
  (**(code **)(*plVar18 + 0x80))(plVar18,&plStack_230);
  plStack_218 = (longlong *)0x0;
  plVar18 = (longlong *)((longlong)*(int *)(*(longlong *)(param_1 + 0x20) + 0xc) + 0x20 + param_1);
  (**(code **)(*plVar18 + 0x88))(plVar18,&plStack_218);
  (**(code **)(*plStack_230 + 0x48))(plStack_230,auStack_1b0);
  iVar10 = (**(code **)(*plStack_230 + 0x50))();
  uStack_224 = FUN_1801cd7d0(auStack_1b0,iVar10 == 2);
  (**(code **)(*plStack_230 + 0x20))(plStack_230,&uStack_1a8);
  iVar10 = FUN_18023a0b0(plStack_230);
  sVar2 = *(short *)(param_1 + 0x208);
  if (iVar10 == 0) {
    if (sVar2 == 0x29) {
      uVar26 = 0x220509;
    }
    else if (sVar2 == 0x2a) {
      uVar26 = 0x320509;
    }
    else {
      if (sVar2 != 0x33) goto LAB_180238b4d;
      uVar26 = 0x520509;
    }
  }
  else if (sVar2 == 0x33) {
    uVar26 = 0x52050b;
  }
  else if (sVar2 == 0x34) {
    uVar26 = 0x62050b;
  }
  else {
    if (sVar2 != 0x32) goto LAB_180238b4d;
    uVar26 = 0x42050b;
  }
  uStack_244 = 0;
  iVar10 = (**(code **)(*plStack_218 + 0x30))();
  if (*(int *)(*(longlong *)(param_1 + 400) + 0x14) == 0) {
    if (iVar10 == 0x10) {
      uStack_244 = 0x11;
      uVar25 = 0x11;
    }
    else if (iVar10 == 0x18) {
      uStack_244 = 0x21;
      uVar25 = 0x21;
    }
  }
  else if (iVar10 == 0x10) {
    uStack_244 = 0x12;
    uVar25 = 0x12;
  }
  else {
    uStack_244 = uVar25;
    if (iVar10 == 0x18) {
      uStack_244 = 0x22;
      uVar25 = uStack_244;
    }
  }
  iVar10 = (**(code **)(*plStack_218 + 0x20))();
  uVar24 = (ulonglong)iVar10;
  uStack_1dc = *(undefined4 *)(param_1 + 0x160);
  uStack_240 = *(uint *)(param_1 + 0x164);
  iStack_220 = iVar10;
  pppppuStack_1a0 = (undefined8 *****)func_0x00018058e29a(0x208);
  if ((undefined8 ******)pppppuStack_1a0 == (undefined8 ******)0x0) {
    puVar13 = (undefined8 *)0x0;
  }
  else {
    puVar13 = (undefined8 *)FUN_1801c59a0(pppppuStack_1a0);
  }
  puStack_258 = &UNK_180712700;
  puStack_250 = (undefined8 *)0x0;
  if (puVar13 != (undefined8 *)0x0) {
    LOCK();
    *(int *)(puVar13 + 1) = *(int *)(puVar13 + 1) + 1;
    UNLOCK();
  }
  (*_UNK_180712708)(&puStack_258);
  *(undefined4 *)(puVar13 + 0x3f) = 0x20000;
  *(undefined4 *)((longlong)puVar13 + 0x1fc) = 1;
  puStack_250 = puVar13;
  __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
            (puVar13 + 4,uStack_1d8);
  *(int *)(puStack_250 + 5) = iVar12;
  *(undefined4 *)((longlong)puStack_250 + 0x2c) = 0;
  *(undefined4 *)(puStack_250 + 6) = uVar26;
  *(undefined4 *)((longlong)puStack_250 + 0x34) = uStack_224;
  *(undefined4 *)((longlong)puStack_250 + 0x3c) = 2;
  ppppuStack_210 = (undefined8 *****)0x0;
  puStack_208 = (undefined4 *)0x0;
  puStack_200 = (undefined *)0x0;
  if (iVar10 != 0) {
    if (0x3fffffffffffffff < uVar24) {
      FUN_180192b30();
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    pppppuStack_1a0 = (undefined8 ******)(uVar24 * 4);
    pppppuVar14 = (undefined8 *****)FUN_18017cf80();
    pppppuStack_180 = &ppppuStack_210;
    ppppuStack_178 = pppppuVar14;
    uStack_170 = uVar24;
    ppppuStack_168 = pppppuVar14;
    ppppuStack_160 = pppppuVar14;
    abStack_1e0[0] = 0;
    abStack_1e0[1] = 0;
    abStack_1e0[2] = 0;
    abStack_1e0[3] = 0;
    lVar19 = 0;
    do {
      lVar20 = lVar19 + 1;
      if (*(byte *)((longlong)&uStack_244 + lVar19) != abStack_1e0[lVar19]) {
        uVar11 = -(uint)(*(byte *)((longlong)&uStack_244 + lVar19) < abStack_1e0[lVar19]) | 1;
        goto LAB_18023816d;
      }
      lVar19 = lVar20;
    } while (lVar20 != 4);
    uVar11 = 0;
LAB_18023816d:
    if (uVar11 == 0) {
      func_0x000180591e96(pppppuVar14,0,uVar24 * 4);
      ppppppuVar22 = (undefined8 ******)(uVar24 * 4);
    }
    else {
      pppppuVar16 = pppppuVar14;
      for (uVar21 = uVar24 & 0x3fffffffffffffff; ppppppuVar22 = (undefined8 ******)pppppuStack_1a0,
          uVar21 != 0; uVar21 = uVar21 - 1) {
        *(undefined4 *)pppppuVar16 = uVar25;
        pppppuVar16 = (undefined8 *****)((longlong)pppppuVar16 + 4);
      }
    }
    ppppuStack_160 = (undefined8 ****)((longlong)pppppuVar14 + uVar24 * 4);
    func_0x000180591e90(pppppuVar14,ppppuStack_210,(longlong)puStack_208 - (longlong)ppppuStack_210)
    ;
    ppppuStack_178 = (undefined8 *****)0x0;
    if ((undefined8 *****)ppppuStack_210 != (undefined8 *****)0x0) {
      if ((0xfff < ((longlong)puStack_200 - (longlong)ppppuStack_210 & 0xfffffffffffffffcU)) &&
         (0x1f < (ulonglong)((longlong)ppppuStack_210 + (-8 - (longlong)ppppuStack_210[-1])))) {
        uStack_288 = 0;
        _invoke_watson(0,0,0,0);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      func_0x00018058eb90();
    }
    puStack_208 = (undefined4 *)((longlong)pppppuVar14 + uVar24 * 4);
    puStack_200 = (undefined *)((longlong)pppppuVar14 + (longlong)ppppppuVar22);
    iVar10 = iStack_220;
    ppppuStack_210 = pppppuVar14;
  }
  FUN_18018da90(puStack_250 + 10,&ppppuStack_210);
  *(int *)(puStack_250 + 0xd) = iVar10;
  uVar4 = *(undefined8 *)(param_1 + 0x1c8);
  puStack_250[0x3c] = *(undefined8 *)(param_1 + 0x1c0);
  puStack_250[0x3d] = uVar4;
  puStack_250[0x3e] = uStack_1a8;
  *(undefined4 *)(puStack_250 + 0x17) = uStack_1dc;
  puStack_250[0x18] = (ulonglong)uStack_240;
  if ((*(longlong *)(param_1 + 0x228) == 0) ||
     (*(int *)(*(longlong *)(param_1 + 0x228) + 0x10) != 2)) {
    pppppuStack_1a0 = (undefined8 *****)func_0x00018058e29a(0x18);
    if ((undefined8 ******)pppppuStack_1a0 == (undefined8 ******)0x0) {
      ppppppuVar22 = (undefined8 ******)0x0;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x23c);
      *pppppuStack_1a0 = (undefined8 ****)&UNK_1806fa848;
      *(int *)(pppppuStack_1a0 + 1) = iStack_228 + -1;
      *(undefined4 *)((longlong)pppppuStack_1a0 + 0xc) = uVar3;
      *(undefined4 *)(pppppuStack_1a0 + 2) = 2;
      ppppppuVar22 = (undefined8 ******)pppppuStack_1a0;
    }
    FUN_180234030(param_1 + 0x228,ppppppuVar22);
  }
  puVar13 = (undefined8 *)(param_1 + 0x210);
  ppppppuVar22 = *(undefined8 *******)(param_1 + 0x218);
  if (ppppppuVar22 == *(undefined8 *******)(param_1 + 0x220)) {
    FUN_1801c5320(puVar13,ppppppuVar22,param_1 + 0x228);
  }
  else {
    *ppppppuVar22 = *(undefined8 ******)(param_1 + 0x228);
    pppppuVar14 = *(undefined8 ******)(param_1 + 0x230);
    ppppppuVar22[1] = pppppuVar14;
    if (pppppuVar14 != (undefined8 *****)0x0) {
      LOCK();
      *(int *)(pppppuVar14 + 1) = *(int *)(pppppuVar14 + 1) + 1;
      UNLOCK();
    }
    *(longlong *)(param_1 + 0x218) = *(longlong *)(param_1 + 0x218) + 0x10;
    pppppuStack_1a0 = ppppppuVar22;
  }
  puVar23 = puStack_250 + 0x1e;
  if (puVar13 != puVar23) {
    uVar4 = *puVar13;
    *puVar13 = *puVar23;
    *puVar23 = uVar4;
    uVar4 = *(undefined8 *)(param_1 + 0x218);
    *(undefined8 *)(param_1 + 0x218) = puStack_250[0x1f];
    puStack_250[0x1f] = uVar4;
    uVar4 = *(undefined8 *)(param_1 + 0x220);
    *(undefined8 *)(param_1 + 0x220) = puStack_250[0x20];
    puStack_250[0x20] = uVar4;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x38) + -0x10) != 0) {
    __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
              (puStack_250 + 0xe);
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x20) + -0x10) != 0) {
    __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
              (puStack_250 + 0xf);
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x28) + -0x10) != 0) {
    __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
              (puStack_250 + 0x10);
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x30) + -0x10) != 0) {
    __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
              (puStack_250 + 0x11);
  }
  if (param_2 != (longlong *)0x0) {
    lStack_1f8 = 0;
    lStack_1f0 = 0;
    lStack_1e8 = 0;
    iVar12 = FUN_1801b8b20(puStack_250,&lStack_1f8);
    if ((-1 < iVar12) && (param_2 != &lStack_1f8)) {
      lVar19 = *param_2;
      *param_2 = lStack_1f8;
      lVar20 = param_2[1];
      param_2[1] = lStack_1f0;
      lVar5 = param_2[2];
      param_2[2] = lStack_1e8;
      lStack_1f8 = lVar19;
      lStack_1f0 = lVar20;
      lStack_1e8 = lVar5;
    }
    if (lStack_1f8 != 0) {
      if ((0xfff < (ulonglong)(lStack_1e8 - lStack_1f8)) &&
         (0x1f < (lStack_1f8 - *(longlong *)(lStack_1f8 + -8)) - 8U)) {
        uStack_288 = 0;
        _invoke_watson(0,0,0,0);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      func_0x00018058eb90();
      lStack_1f8 = 0;
      lStack_1f0 = 0;
      lStack_1e8 = 0;
    }
  }
  pppppuVar14 = (undefined8 *****)0x0;
  iVar12 = FUN_1801b89a0(puStack_250,uStack_1d0);
  if (-1 < iVar12) {
    __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_AEBV01__Z
              (param_1 + 0x180,&uStack_1d0);
    pppppuVar15 = (undefined8 *****)func_0x00018058e29a(0x98);
    pppppuVar16 = pppppuVar14;
    pppppuStack_1a0 = pppppuVar15;
    if (pppppuVar15 != (undefined8 *****)0x0) {
      FUN_1801cd640(pppppuVar15,1);
      *pppppuVar15 = (undefined8 ****)&UNK_1807117b0;
      pppppuVar15[4] = (undefined8 ****)0x0;
      pppppuVar15[5] = (undefined8 ****)0x0;
      pppppuVar15[6] = (undefined8 ****)0x0;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(pppppuVar15 + 7);
      *pppppuVar15 = (undefined8 ****)&UNK_180711ad0;
      *(undefined4 *)(pppppuVar15 + 8) = 0x2000a;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(pppppuVar15 + 9);
      *pppppuVar15 = (undefined8 ****)&UNK_180711b00;
      pppppuVar15[10] = (undefined8 ****)0x0;
      pppppuVar15[0xb] = (undefined8 ****)0x0;
      pppppuVar15[0xc] = (undefined8 ****)0x0;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(pppppuVar15 + 0xd)
      ;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(pppppuVar15 + 0xe)
      ;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(pppppuVar15 + 0xf)
      ;
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ
                (pppppuVar15 + 0x10);
      __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ
                (pppppuVar15 + 0x11);
      *(undefined1 *)(pppppuVar15 + 0x12) = 1;
      pppppuVar16 = pppppuVar15;
    }
    ppppuStack_268 = (undefined8 ****)&UNK_180712728;
    ppppuStack_260 = (undefined8 ****)0x0;
    if (pppppuVar16 != (undefined8 *****)0x0) {
      LOCK();
      *(int *)(pppppuVar16 + 1) = *(int *)(pppppuVar16 + 1) + 1;
      UNLOCK();
    }
    (*_UNK_180712730)(&ppppuStack_268);
    ppppuStack_198 = (undefined8 ****)(longlong)*(int *)(pppppuStack_238 + -2);
    pppppuStack_1a0 = pppppuStack_238;
    ppppuStack_260 = pppppuVar16;
    cVar9 = FUN_18043f520(&pppppuStack_1a0);
    if (cVar9 == '\0') {
      *(undefined4 *)(ppppuStack_260 + 8) = 0x2000a;
      FUN_180413de0(&pppppuStack_1a0);
      ppppuVar17 = ppppuStack_260;
      ppppppuVar22 = &pppppuStack_1a0;
      if ((undefined8 *****)0x7 < ppppuStack_188) {
        ppppppuVar22 = (undefined8 ******)pppppuStack_1a0;
      }
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuStack_260 + 0xd,ppppppuVar22);
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuVar17 + 0xe,&UNK_180712768);
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuVar17 + 9,&UNK_180712748);
      FUN_1804138c0(&pppppuStack_180,uStack_1c8);
      ppppuVar17 = ppppuStack_260;
      ppppppuVar22 = &pppppuStack_180;
      if ((undefined8 *****)0x7 < ppppuStack_168) {
        ppppppuVar22 = (undefined8 ******)pppppuStack_180;
      }
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuStack_260 + 0xf,ppppppuVar22);
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuVar17 + 0x10,&UNK_180712778);
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuVar17 + 0x11,0);
      if ((undefined8 *****)0x7 < ppppuStack_168) {
        if ((0xfff < (longlong)ppppuStack_168 * 2 + 2U) &&
           ((undefined *)0x1f <
            (undefined *)((longlong)pppppuStack_180 + (-8 - (longlong)pppppuStack_180[-1])))) {
          uStack_288 = 0;
          _invoke_watson(0,0,0,0);
          pcVar7 = (code *)swi(3);
          (*pcVar7)();
          return;
        }
        func_0x00018058eb90();
      }
      uStack_170 = _DAT_1806f4460;
      ppppuStack_168 = _UNK_1806f4468;
      pppppuStack_180 = (undefined8 *****)((ulonglong)pppppuStack_180 & 0xffffffffffff0000);
      if ((undefined8 *****)0x7 < ppppuStack_188) {
        if ((0xfff < (longlong)ppppuStack_188 * 2 + 2U) &&
           ((undefined *)0x1f <
            (undefined *)((longlong)pppppuStack_1a0 + (-8 - (longlong)pppppuStack_1a0[-1])))) {
          uStack_288 = 0;
          _invoke_watson(0,0,0,0);
          pcVar7 = (code *)swi(3);
          (*pcVar7)();
          return;
        }
        func_0x00018058eb90();
      }
      uStack_190 = _DAT_1806f4460;
      ppppuStack_188 = _UNK_1806f4468;
      pppppuStack_1a0 = (undefined8 *****)((ulonglong)pppppuStack_1a0 & 0xffffffffffff0000);
LAB_180238793:
      pppppuVar16 = (undefined8 *****)func_0x00018058e29a(0x98);
      pppppuStack_1a0 = pppppuVar16;
      if (pppppuVar16 != (undefined8 *****)0x0) {
        FUN_1801bd740(pppppuVar16);
        *pppppuVar16 = (undefined8 ****)&UNK_1806fa0a0;
        __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ
                  (pppppuVar16 + 0xe);
        __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ
                  (pppppuVar16 + 0xf);
        __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ
                  (pppppuVar16 + 0x10);
        pppppuVar16[0x11] = (undefined8 ****)0x0;
        pppppuVar16[0x12] = (undefined8 ****)0x0;
        ppppuVar17 = (undefined8 ****)func_0x00018058e29a(0x18);
        *ppppuVar17 = ppppuVar17;
        ppppuVar17[1] = ppppuVar17;
        pppppuVar16[0x11] = ppppuVar17;
        pppppuVar14 = pppppuVar16;
      }
      pppppuStack_278 = (undefined8 *****)&UNK_1806fa078;
      ppppuStack_270 = (undefined8 ****)0x0;
      if (pppppuVar14 != (undefined8 *****)0x0) {
        LOCK();
        *(int *)(pppppuVar14 + 1) = *(int *)(pppppuVar14 + 1) + 1;
        UNLOCK();
      }
      (*_UNK_1806fa080)(&pppppuStack_278);
      ppppuStack_270 = pppppuVar14;
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (pppppuVar14 + 2,uStack_1b8);
      __4__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAAEAV01_PEB_W_Z
                (ppppuStack_270 + 3,uStack_1d8);
      *(int *)(ppppuStack_270 + 5) = iStack_228;
      *(undefined4 *)(ppppuStack_270 + 0xc) = 2;
      *(undefined4 *)(ppppuStack_270 + 4) = uVar26;
      *(undefined4 *)((longlong)ppppuStack_270 + 0x24) = uStack_224;
      *(undefined4 *)((longlong)ppppuStack_270 + 0x2c) = 2;
      FUN_1801bd970(ppppuStack_270,uVar25);
      ppppuVar8 = ppppuStack_260;
      ppppuVar17 = ppppuStack_270;
      *(int *)(ppppuStack_270 + 10) = iStack_220;
      pppppuStack_1a0 = (undefined8 *****)&UNK_1806fa078;
      ppppuStack_198 = (undefined8 ****)0x0;
      if ((undefined8 *****)ppppuStack_270 != (undefined8 *****)0x0) {
        LOCK();
        *(int *)(ppppuStack_270 + 1) = *(int *)(ppppuStack_270 + 1) + 1;
        UNLOCK();
      }
      (*_UNK_1806fa080)(&pppppuStack_1a0);
      ppppuStack_198 = ppppuVar17;
      ppppuVar6 = (undefined8 ****)ppppuVar8[0xb];
      if (ppppuVar6 == (undefined8 ****)ppppuVar8[0xc]) {
        FUN_180233c40(ppppuVar8 + 10,ppppuVar6,&pppppuStack_1a0);
      }
      else {
        *ppppuVar6 = (undefined8 ***)&UNK_1806fa078;
        ppppuVar6[1] = (undefined8 ***)0x0;
        if ((undefined8 *****)ppppuVar17 != (undefined8 *****)0x0) {
          LOCK();
          *(int *)(ppppuVar17 + 1) = *(int *)(ppppuVar17 + 1) + 1;
          UNLOCK();
        }
        (*(code *)(*ppppuVar6)[1])(ppppuVar6);
        ppppuVar6[1] = ppppuVar17;
        ppppuVar8[0xb] = ppppuVar8[0xb] + 2;
      }
      pppppuStack_1a0 = (undefined8 *****)&UNK_1806fa078;
      if ((undefined8 *****)ppppuStack_198 != (undefined8 *****)0x0) {
        LOCK();
        pppppuVar14 = (undefined8 *****)(ppppuStack_198 + 1);
        iVar12 = *(int *)pppppuVar14;
        *(int *)pppppuVar14 = *(int *)pppppuVar14 + -1;
        UNLOCK();
        if ((iVar12 < 2) && ((undefined8 *****)ppppuStack_198 != (undefined8 *****)0x0)) {
          (*(code *)**ppppuStack_198)(ppppuStack_198,1);
        }
        ppppuStack_198 = (undefined8 *****)0x0;
      }
      if (cVar9 == '\0') {
        iVar12 = FUN_1801b89a0(ppppuStack_260,pppppuStack_238);
        if (iVar12 < 0) {
          ppppuStack_178 = (undefined8 ****)(longlong)*(int *)(pppppuStack_238 + -2);
          pppppuStack_180 = pppppuStack_238;
          FUN_18043c630(&pppppuStack_180,0);
        }
      }
      else {
        FUN_1802352b0(&uStack_240,&pppppuStack_238,&UNK_1807127a8);
        iVar12 = FUN_1801b89a0(ppppuStack_260,CONCAT44(uStack_23c,uStack_240));
        if (iVar12 < 0) {
          pppppuStack_1a0 = (undefined8 *****)CONCAT44(uStack_23c,uStack_240);
          ppppuStack_198 = (undefined8 ****)(longlong)*(int *)(pppppuStack_1a0 + -2);
          FUN_18043c630(&pppppuStack_1a0,0);
LAB_1802389a7:
          __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_240);
        }
        else {
          ppppuStack_198 = (undefined8 ****)(longlong)*(int *)(pppppuStack_238 + -2);
          pppppuStack_1a0 = pppppuStack_238;
          iVar12 = FUN_18043c630(&pppppuStack_1a0,0);
          if (iVar12 < 0) {
            __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_240)
            ;
          }
          else {
            ppppuStack_198 = (undefined8 ****)(longlong)*(int *)(pppppuStack_238 + -2);
            pppppuStack_1a0 = pppppuStack_238;
            pppppuStack_180 = (undefined8 *****)CONCAT44(uStack_23c,uStack_240);
            ppppuStack_178 = (undefined8 ****)(longlong)*(int *)(pppppuStack_180 + -2);
            iVar12 = FUN_180440310(&pppppuStack_180,&pppppuStack_1a0);
            if (-1 < iVar12) goto LAB_1802389a7;
            __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_240)
            ;
          }
        }
      }
      pppppuStack_278 = (undefined8 *****)&UNK_1806fa078;
      if ((undefined8 *****)ppppuStack_270 != (undefined8 *****)0x0) {
        LOCK();
        pppppuVar14 = (undefined8 *****)(ppppuStack_270 + 1);
        iVar12 = *(int *)pppppuVar14;
        *(int *)pppppuVar14 = *(int *)pppppuVar14 + -1;
        UNLOCK();
        if ((iVar12 < 2) && ((undefined8 *****)ppppuStack_270 != (undefined8 *****)0x0)) {
          (*(code *)**ppppuStack_270)(ppppuStack_270,1);
        }
        ppppuStack_270 = (undefined8 *****)0x0;
      }
    }
    else {
      iVar12 = FUN_1801b86f0(ppppuStack_260,pppppuStack_238);
      if (-1 < iVar12) goto LAB_180238793;
    }
    ppppuStack_268 = (undefined8 ****)&UNK_180712728;
    if ((undefined8 *****)ppppuStack_260 != (undefined8 *****)0x0) {
      LOCK();
      pppppuVar14 = (undefined8 *****)(ppppuStack_260 + 1);
      iVar12 = *(int *)pppppuVar14;
      *(int *)pppppuVar14 = *(int *)pppppuVar14 + -1;
      UNLOCK();
      if ((iVar12 < 2) && ((undefined8 *****)ppppuStack_260 != (undefined8 *****)0x0)) {
        (*(code *)**ppppuStack_260)(ppppuStack_260,1);
      }
      ppppuStack_260 = (undefined8 *****)0x0;
    }
  }
  if ((undefined8 *****)ppppuStack_210 != (undefined8 *****)0x0) {
    if ((0xfff < ((longlong)puStack_200 - (longlong)ppppuStack_210 & 0xfffffffffffffffcU)) &&
       (0x1f < (ulonglong)((longlong)ppppuStack_210 + (-8 - (longlong)ppppuStack_210[-1])))) {
      uStack_288 = 0;
      _invoke_watson(0,0,0,0);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    func_0x00018058eb90();
    ppppuStack_210 = (undefined8 *****)0x0;
    puStack_208 = (undefined4 *)0x0;
    puStack_200 = (undefined *)0x0;
  }
  puStack_258 = &UNK_180712700;
  if (puStack_250 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puStack_250 + 1);
    iVar12 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar12 < 2) && (puStack_250 != (undefined8 *)0x0)) {
      (**(code **)*puStack_250)(puStack_250,1);
    }
    puStack_250 = (undefined8 *)0x0;
  }
LAB_180238b4d:
  if (plStack_218 != (longlong *)0x0) {
    (**(code **)(*plStack_218 + 0x10))();
  }
  if (plStack_230 != (longlong *)0x0) {
    (**(code **)(*plStack_230 + 0x10))();
  }
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_1d8);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&pppppuStack_238);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_1d0);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_1c8);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&ppppuStack_1c0);
  __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_1b8);
  FUN_180432230(auStack_158);
  FUN_18058f0f0(uStack_48 ^ (ulonglong)auStack_2a8);
  return;
}

