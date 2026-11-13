// Normalized static image, not an observed export trace.
// Preferred VA 1801c1ab0
// Disassembly returned true; body bytes 5556

ulonglong loaded_1801c1ab0(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong ****pppplVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  longlong ******pppppplVar8;
  longlong *****ppppplVar9;
  longlong *****ppppplVar10;
  longlong ******pppppplVar11;
  longlong ******pppppplVar12;
  ulonglong uVar13;
  longlong ******pppppplVar14;
  int aiStackX_18 [2];
  longlong *****ppppplStackX_20;
  longlong *****ppppplStack_108;
  longlong *****ppppplStack_100;
  longlong *****ppppplStack_f8;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  longlong *****ppppplStack_d8;
  longlong *****ppppplStack_d0;
  longlong *****ppppplStack_c8;
  longlong *****ppppplStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 uStack_a8;
  undefined4 uStack_98;
  longlong ****pppplStack_90;
  longlong *****ppppplStack_88;
  longlong lStack_80;
  longlong *****ppppplStack_78;
  longlong *****ppppplStack_70;
  longlong ***ppplStack_68;
  longlong *****ppppplStack_60;
  longlong lStack_58;
  longlong *****ppppplStack_50;
  longlong ****pppplStack_48;
  
  pppppplVar14 = (longlong ******)0x0;
  uStack_98 = 0;
  aiStackX_18[0] = 0;
  lVar1 = *param_2;
  if (lVar1 == 0) goto LAB_1801c2f04;
  ppppplStack_f8 = (longlong *****)&ppppplStackX_20;
  pppppplVar8 = (longlong ******)func_0x00018058e29a(0x18);
  pppppplVar11 = pppppplVar14;
  ppppplStack_100 = (longlong *****)pppppplVar8;
  if (pppppplVar8 != (longlong ******)0x0) {
    pppppplVar8[1] = (longlong *****)0x0;
    *(undefined4 *)(pppppplVar8 + 2) = 1;
    ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa0d8);
    *pppppplVar8 = ppppplVar9;
    pppppplVar11 = pppppplVar8;
    if (ppppplVar9 != (longlong *****)0x0) goto LAB_1801c1b37;
LAB_1801c2dc5:
    func_0x000180591c10(0x8007000e);
LAB_1801c2dd0:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ddb:
    func_0x000180591c10(0x8007000e);
LAB_1801c2de6:
    func_0x000180591c10(0x8007000e);
LAB_1801c2df1:
    func_0x000180591c10(0x8007000e);
LAB_1801c2dfc:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e07:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e12:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e1d:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e28:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e33:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e3e:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e49:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e54:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e5f:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e6a:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e75:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e80:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e8b:
    func_0x000180591c10(0x8007000e);
LAB_1801c2e96:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ea1:
    func_0x000180591c10(0x8007000e);
LAB_1801c2eac:
    func_0x000180591c10(0x8007000e);
LAB_1801c2eb7:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ec2:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ecd:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ed8:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ee3:
    func_0x000180591c10(0x8007000e);
LAB_1801c2eee:
    func_0x000180591c10(0x8007000e);
LAB_1801c2ef9:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f04:
    func_0x000180591c10(0x80004003);
    pcVar3 = (code *)swi(3);
    uVar13 = (*pcVar3)();
    return uVar13;
  }
LAB_1801c1b37:
  ppppplStackX_20 = (longlong *****)pppppplVar11;
  if (pppppplVar11 == (longlong ******)0x0) {
    func_0x000180591c10(0x8007000e);
LAB_1801c2f1a:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f25:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f30:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f3b:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f46:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f51:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f5c:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f67:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f72:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f7d:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f88:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f93:
    func_0x000180591c10(0x8007000e);
LAB_1801c2f9e:
    func_0x000180591c10(0x8007000e);
  }
  else {
    FUN_18019cbc0(lVar1,&ppppplStack_c8,&ppppplStackX_20);
    ppppplVar9 = ppppplStack_c8;
    if ((longlong ******)ppppplStack_c8 == (longlong ******)0x0) {
      func_0x000180591c10(0x80004003);
      goto LAB_1801c2dc5;
    }
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    uStack_e8 = SysAllocString(&UNK_1806fa4a0);
    if (uStack_e8 == 0) goto LAB_1801c2f1a;
    ppppplStackX_20 = (longlong *****)&ppppplStack_108;
    pppppplVar8 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar11 = pppppplVar14;
    ppppplStack_f8 = (longlong *****)pppppplVar8;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar8[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar8 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806f8360);
      *pppppplVar8 = ppppplVar10;
      pppppplVar11 = pppppplVar8;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2dd0;
    }
    ppppplStack_108 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f25;
    FUN_1801bd650(ppppplVar9,&ppppplStack_108,&uStack_f0);
    VariantClear(&uStack_f0);
    FUN_1801bb5d0(&lStack_58,0);
    ppppplVar9 = ppppplStack_c8;
    if ((longlong ******)ppppplStack_c8 == (longlong ******)0x0) goto LAB_1801c3059;
    pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
    if (pppppplVar11 == (longlong ******)0x0) {
      pppppplVar11 = (longlong ******)0x0;
    }
    else {
      pppppplVar11[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar11 + 2) = 1;
      ppppplStackX_20 = (longlong *****)pppppplVar11;
      ppppplVar10 = (longlong *****)SysAllocString(lStack_58);
      *pppppplVar11 = ppppplVar10;
      if ((ppppplVar10 == (longlong *****)0x0) && (lStack_58 != 0)) goto LAB_1801c2ddb;
    }
    ppppplStackX_20 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f30;
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    ppppplVar10 = *pppppplVar11;
    if (ppppplVar10 != (longlong *****)0x0) {
      uVar6 = SysStringByteLen(ppppplVar10);
      uStack_e8 = SysAllocStringByteLen(ppppplVar10,uVar6);
      if (uStack_e8 != 0) goto LAB_1801c1c7b;
      goto LAB_1801c2df1;
    }
    uStack_e8 = 0;
LAB_1801c1c7b:
    ppppplStack_f8 = (longlong *****)&ppppplStack_d8;
    pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar8 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar12;
    if (pppppplVar12 != (longlong ******)0x0) {
      pppppplVar12[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar12 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806fa500);
      *pppppplVar12 = ppppplVar10;
      pppppplVar8 = pppppplVar12;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2de6;
    }
    ppppplStack_d8 = (longlong *****)pppppplVar8;
    if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2f3b;
    ppppplStack_100 = (longlong *****)&ppppplStack_d8;
    pppppplVar12 = pppppplVar14;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar12 = (longlong ******)*pppppplVar8;
    }
    uStack_b8 = uStack_f0;
    uStack_b4 = uStack_ec;
    uStack_b0 = (undefined4)uStack_e8;
    uStack_ac = uStack_e8._4_4_;
    uStack_a8 = uStack_e0;
    iVar5 = (*(code *)(*ppppplVar9)[0x2d])(ppppplVar9,pppppplVar12,&uStack_b8);
    if (iVar5 < 0) {
      FUN_180591c20(iVar5,ppppplVar9,&UNK_1806f7278);
    }
    FUN_18018d480(&ppppplStack_d8);
    VariantClear(&uStack_f0);
    LOCK();
    pppppplVar8 = pppppplVar11 + 2;
    iVar5 = *(int *)pppppplVar8;
    *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      if (*pppppplVar11 != (longlong *****)0x0) {
        SysFreeString();
        *pppppplVar11 = (longlong *****)0x0;
      }
      if (pppppplVar11[1] != (longlong *****)0x0) {
        func_0x00018058e2a6();
        pppppplVar11[1] = (longlong *****)0x0;
      }
      func_0x00018058eb90(pppppplVar11,0x18);
    }
    ppppplStackX_20 = (longlong *****)0x0;
    __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&lStack_80);
    _Format___CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAAXPEB_WZZ
              (&lStack_80,&UNK_1806fa108,*(uint *)(param_1 + 0x40) >> 0x10,
               *(uint *)(param_1 + 0x40) & 0xffff);
    ppppplVar9 = ppppplStack_c8;
    if ((longlong ******)ppppplStack_c8 == (longlong ******)0x0) {
LAB_1801c304e:
      func_0x000180591c10(0x80004003);
LAB_1801c3059:
      func_0x000180591c10(0x80004003);
      pcVar3 = (code *)swi(3);
      uVar13 = (*pcVar3)();
      return uVar13;
    }
    pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
    if (pppppplVar11 == (longlong ******)0x0) {
      pppppplVar11 = (longlong ******)0x0;
    }
    else {
      pppppplVar11[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar11 + 2) = 1;
      ppppplStackX_20 = (longlong *****)pppppplVar11;
      ppppplVar10 = (longlong *****)SysAllocString(lStack_80);
      *pppppplVar11 = ppppplVar10;
      if ((ppppplVar10 == (longlong *****)0x0) && (lStack_80 != 0)) goto LAB_1801c2dfc;
    }
    ppppplStackX_20 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f46;
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    ppppplVar10 = *pppppplVar11;
    if (ppppplVar10 != (longlong *****)0x0) {
      uVar6 = SysStringByteLen(ppppplVar10);
      uStack_e8 = SysAllocStringByteLen(ppppplVar10,uVar6);
      if (uStack_e8 != 0) goto LAB_1801c1e47;
      goto LAB_1801c2e12;
    }
    uStack_e8 = 0;
LAB_1801c1e47:
    ppppplStack_f8 = (longlong *****)&ppppplStack_d8;
    pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar8 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar12;
    if (pppppplVar12 != (longlong ******)0x0) {
      pppppplVar12[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar12 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806fa0f8);
      *pppppplVar12 = ppppplVar10;
      pppppplVar8 = pppppplVar12;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2e07;
    }
    ppppplStack_d8 = (longlong *****)pppppplVar8;
    if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2f51;
    ppppplStack_100 = (longlong *****)&ppppplStack_d8;
    pppppplVar12 = pppppplVar14;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar12 = (longlong ******)*pppppplVar8;
    }
    uStack_b8 = uStack_f0;
    uStack_b4 = uStack_ec;
    uStack_b0 = (undefined4)uStack_e8;
    uStack_ac = uStack_e8._4_4_;
    uStack_a8 = uStack_e0;
    iVar5 = (*(code *)(*ppppplVar9)[0x2d])(ppppplVar9,pppppplVar12,&uStack_b8);
    if (iVar5 < 0) {
      FUN_180591c20(iVar5,ppppplVar9,&UNK_1806f7278);
    }
    FUN_18018d480(&ppppplStack_d8);
    VariantClear(&uStack_f0);
    LOCK();
    pppppplVar8 = pppppplVar11 + 2;
    iVar5 = *(int *)pppppplVar8;
    *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      if (*pppppplVar11 != (longlong *****)0x0) {
        SysFreeString();
        *pppppplVar11 = (longlong *****)0x0;
      }
      if (pppppplVar11[1] != (longlong *****)0x0) {
        func_0x00018058e2a6();
        pppppplVar11[1] = (longlong *****)0x0;
      }
      func_0x00018058eb90(pppppplVar11,0x18);
    }
    ppppplStack_f8 = (longlong *****)&ppppplStackX_20;
    ppppplStackX_20 = ppppplStack_c8;
    if ((longlong ******)ppppplStack_c8 != (longlong ******)0x0) {
      (*(code *)(*ppppplStack_c8)[1])();
    }
    ppppplStack_100 = (longlong *****)&ppppplStack_108;
    ppppplStack_108 = (longlong *****)*param_2;
    if ((longlong ******)ppppplStack_108 != (longlong ******)0x0) {
      (*(code *)(*ppppplStack_108)[1])();
    }
    FUN_1801ba780(&ppppplStack_108,&ppppplStackX_20);
    pppplStack_48 = (longlong ****)aiStackX_18;
    aiStackX_18[0] = aiStackX_18[0] + 1;
    ppppplStack_f8 = (longlong *****)&ppppplStack_70;
    pppppplVar8 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar11 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar8;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar8[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar8 + 2) = 1;
      ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa118);
      *pppppplVar8 = ppppplVar9;
      pppppplVar11 = pppppplVar8;
      if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2e1d;
    }
    ppppplStack_70 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f5c;
    ppppplStackX_20 = (longlong *****)&ppplStack_68;
    ppplStack_68 = (longlong ***)*param_2;
    if ((longlong ****)ppplStack_68 != (longlong ****)0x0) {
      (*(code *)(*ppplStack_68)[1])();
    }
    FUN_1801baf70(&ppppplStack_88,&ppplStack_68,&ppppplStack_70,1,0);
    ppppplStack_50 = (longlong *****)aiStackX_18;
    aiStackX_18[0] = aiStackX_18[0] + 1;
    ppppplStackX_20 = (longlong *****)&ppppplStack_60;
    pppppplVar8 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar11 = pppppplVar14;
    ppppplStack_f8 = (longlong *****)pppppplVar8;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar8[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar8 + 2) = 1;
      ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa158);
      *pppppplVar8 = ppppplVar9;
      pppppplVar11 = pppppplVar8;
      if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2e28;
    }
    ppppplStack_60 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f67;
    ppppplStack_f8 = (longlong *****)&ppppplStack_78;
    ppppplStack_78 = (longlong *****)*param_2;
    if ((longlong ******)ppppplStack_78 != (longlong ******)0x0) {
      (*(code *)(*ppppplStack_78)[1])();
    }
    FUN_1801baf70(&ppppplStack_d8,&ppppplStack_78,&ppppplStack_60,0,0);
    ppppplVar9 = ppppplStack_d8;
    if ((longlong ******)ppppplStack_d8 == (longlong ******)0x0) {
      func_0x000180591c10(0x80004003);
      goto LAB_1801c304e;
    }
    lVar1 = *(longlong *)(param_1 + 0x68);
    pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
    if (pppppplVar11 == (longlong ******)0x0) {
      pppppplVar11 = (longlong ******)0x0;
    }
    else {
      pppppplVar11[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar11 + 2) = 1;
      ppppplStackX_20 = (longlong *****)pppppplVar11;
      ppppplVar10 = (longlong *****)SysAllocString(lVar1);
      *pppppplVar11 = ppppplVar10;
      if ((ppppplVar10 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2e33;
    }
    ppppplStackX_20 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f72;
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    ppppplVar10 = *pppppplVar11;
    if (ppppplVar10 != (longlong *****)0x0) {
      uVar6 = SysStringByteLen(ppppplVar10);
      uStack_e8 = SysAllocStringByteLen(ppppplVar10,uVar6);
      if (uStack_e8 != 0) goto LAB_1801c215d;
      goto LAB_1801c2e49;
    }
    uStack_e8 = 0;
LAB_1801c215d:
    ppppplStack_f8 = (longlong *****)&ppppplStack_108;
    pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar8 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar12;
    if (pppppplVar12 != (longlong ******)0x0) {
      pppppplVar12[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar12 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806fa518);
      *pppppplVar12 = ppppplVar10;
      pppppplVar8 = pppppplVar12;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2e3e;
    }
    ppppplStack_108 = (longlong *****)pppppplVar8;
    if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2f7d;
    ppppplStack_100 = (longlong *****)&ppppplStack_108;
    pppppplVar12 = pppppplVar14;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar12 = (longlong ******)*pppppplVar8;
    }
    uStack_b8 = uStack_f0;
    uStack_b4 = uStack_ec;
    uStack_b0 = (undefined4)uStack_e8;
    uStack_ac = uStack_e8._4_4_;
    uStack_a8 = uStack_e0;
    iVar5 = (*(code *)(*ppppplVar9)[0x2d])(ppppplVar9,pppppplVar12,&uStack_b8);
    if (iVar5 < 0) {
      FUN_180591c20(iVar5,ppppplVar9,&UNK_1806f7278);
    }
    FUN_18018d480(&ppppplStack_108);
    VariantClear(&uStack_f0);
    LOCK();
    pppppplVar8 = pppppplVar11 + 2;
    iVar5 = *(int *)pppppplVar8;
    *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      if (*pppppplVar11 != (longlong *****)0x0) {
        SysFreeString();
        *pppppplVar11 = (longlong *****)0x0;
      }
      if (pppppplVar11[1] != (longlong *****)0x0) {
        func_0x00018058e2a6();
        pppppplVar11[1] = (longlong *****)0x0;
      }
      func_0x00018058eb90(pppppplVar11,0x18);
    }
    ppppplVar9 = ppppplStack_d8;
    ppppplStackX_20 = (longlong *****)0x0;
    if ((longlong ******)ppppplStack_d8 == (longlong ******)0x0) goto LAB_1801c3038;
    lVar1 = *(longlong *)(param_1 + 0x70);
    pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
    if (pppppplVar11 == (longlong ******)0x0) {
      pppppplVar11 = (longlong ******)0x0;
    }
    else {
      pppppplVar11[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar11 + 2) = 1;
      ppppplStackX_20 = (longlong *****)pppppplVar11;
      ppppplVar10 = (longlong *****)SysAllocString(lVar1);
      *pppppplVar11 = ppppplVar10;
      if ((ppppplVar10 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2e54;
    }
    ppppplStackX_20 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f88;
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    ppppplVar10 = *pppppplVar11;
    if (ppppplVar10 != (longlong *****)0x0) {
      uVar6 = SysStringByteLen(ppppplVar10);
      uStack_e8 = SysAllocStringByteLen(ppppplVar10,uVar6);
      if (uStack_e8 != 0) goto LAB_1801c2300;
      goto LAB_1801c2e6a;
    }
    uStack_e8 = 0;
LAB_1801c2300:
    ppppplStack_f8 = (longlong *****)&ppppplStack_108;
    pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar8 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar12;
    if (pppppplVar12 != (longlong ******)0x0) {
      pppppplVar12[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar12 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806fa530);
      *pppppplVar12 = ppppplVar10;
      pppppplVar8 = pppppplVar12;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2e5f;
    }
    ppppplStack_108 = (longlong *****)pppppplVar8;
    if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2f93;
    ppppplStack_100 = (longlong *****)&ppppplStack_108;
    pppppplVar12 = pppppplVar14;
    if (pppppplVar8 != (longlong ******)0x0) {
      pppppplVar12 = (longlong ******)*pppppplVar8;
    }
    uStack_b8 = uStack_f0;
    uStack_b4 = uStack_ec;
    uStack_b0 = (undefined4)uStack_e8;
    uStack_ac = uStack_e8._4_4_;
    uStack_a8 = uStack_e0;
    iVar5 = (*(code *)(*ppppplVar9)[0x2d])(ppppplVar9,pppppplVar12,&uStack_b8);
    if (iVar5 < 0) {
      FUN_180591c20(iVar5,ppppplVar9,&UNK_1806f7278);
    }
    FUN_18018d480(&ppppplStack_108);
    VariantClear(&uStack_f0);
    LOCK();
    pppppplVar8 = pppppplVar11 + 2;
    iVar5 = *(int *)pppppplVar8;
    *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      if (*pppppplVar11 != (longlong *****)0x0) {
        SysFreeString();
        *pppppplVar11 = (longlong *****)0x0;
      }
      if (pppppplVar11[1] != (longlong *****)0x0) {
        func_0x00018058e2a6();
        pppppplVar11[1] = (longlong *****)0x0;
      }
      func_0x00018058eb90(pppppplVar11,0x18);
    }
    ppppplVar9 = ppppplStack_d8;
    ppppplStackX_20 = (longlong *****)0x0;
    lVar1 = *(longlong *)(param_1 + 0x48);
    if (*(int *)(lVar1 + -0x10) == 0) {
LAB_1801c25db:
      iVar5 = aiStackX_18[0];
      ppppplStack_f8 = (longlong *****)&ppppplStackX_20;
      ppppplStackX_20 = ppppplStack_d8;
      if ((longlong ******)ppppplStack_d8 != (longlong ******)0x0) {
        (*(code *)(*ppppplStack_d8)[1])();
      }
      ppppplStack_d0 = (longlong *****)&ppppplStack_108;
      ppppplStack_108 = ppppplStack_88;
      if ((longlong ******)ppppplStack_88 != (longlong ******)0x0) {
        (*(code *)(*ppppplStack_88)[1])();
      }
      ppppplStack_c0 = (longlong *****)&ppppplStack_100;
      ppppplStack_100 = (longlong *****)*param_2;
      if ((longlong ******)ppppplStack_100 != (longlong ******)0x0) {
        (*(code *)(*ppppplStack_100)[1])();
      }
      FUN_1801ba1e0(&ppppplStack_100,&ppppplStack_108,&ppppplStackX_20,iVar5);
      ppppplStack_c0 = (longlong *****)&ppppplStack_100;
      pppppplVar8 = (longlong ******)func_0x00018058e29a(0x18);
      pppppplVar11 = pppppplVar14;
      ppppplStack_d0 = (longlong *****)pppppplVar8;
      if (pppppplVar8 != (longlong ******)0x0) {
        pppppplVar8[1] = (longlong *****)0x0;
        *(undefined4 *)(pppppplVar8 + 2) = 1;
        ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa130);
        *pppppplVar8 = ppppplVar9;
        pppppplVar11 = pppppplVar8;
        if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2e96;
      }
      ppppplStack_100 = (longlong *****)pppppplVar11;
      if (pppppplVar11 == (longlong ******)0x0) {
        func_0x000180591c10(0x8007000e);
LAB_1801c2fca:
        func_0x000180591c10(0x8007000e);
LAB_1801c2fd5:
        func_0x000180591c10(0x8007000e);
LAB_1801c2fe0:
        func_0x000180591c10(0x8007000e);
LAB_1801c2feb:
        func_0x000180591c10(0x8007000e);
LAB_1801c2ff6:
        func_0x000180591c10(0x8007000e);
LAB_1801c3001:
        func_0x000180591c10(0x8007000e);
LAB_1801c300c:
        func_0x000180591c10(0x80004003);
      }
      else {
        ppppplStackX_20 = (longlong *****)&ppppplStack_f8;
        ppppplStack_f8 = (longlong *****)*param_2;
        if ((longlong ******)ppppplStack_f8 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_f8)[1])();
        }
        FUN_1801baf70(&pppplStack_90,&ppppplStack_f8,&ppppplStack_100,0,0);
        pppplVar4 = pppplStack_90;
        if ((longlong *****)pppplStack_90 == (longlong *****)0x0) {
          func_0x000180591c10(0x80004003);
LAB_1801c3038:
          func_0x000180591c10(0x80004003);
          pcVar3 = (code *)swi(3);
          uVar13 = (*pcVar3)();
          return uVar13;
        }
        lVar1 = *(longlong *)(param_1 + 0x78);
        pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
        if (pppppplVar11 == (longlong ******)0x0) {
          pppppplVar11 = (longlong ******)0x0;
        }
        else {
          pppppplVar11[1] = (longlong *****)0x0;
          *(undefined4 *)(pppppplVar11 + 2) = 1;
          ppppplStackX_20 = (longlong *****)pppppplVar11;
          ppppplVar9 = (longlong *****)SysAllocString(lVar1);
          *pppppplVar11 = ppppplVar9;
          if ((ppppplVar9 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2ea1;
        }
        ppppplStackX_20 = (longlong *****)pppppplVar11;
        if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2fca;
        uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
        ppppplVar9 = *pppppplVar11;
        if (ppppplVar9 != (longlong *****)0x0) {
          uVar6 = SysStringByteLen(ppppplVar9);
          uStack_e8 = SysAllocStringByteLen(ppppplVar9,uVar6);
          if (uStack_e8 != 0) goto LAB_1801c2750;
          goto LAB_1801c2eb7;
        }
        uStack_e8 = 0;
LAB_1801c2750:
        ppppplStack_c0 = (longlong *****)&ppppplStack_108;
        pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
        pppppplVar8 = pppppplVar14;
        ppppplStack_d0 = (longlong *****)pppppplVar12;
        if (pppppplVar12 != (longlong ******)0x0) {
          pppppplVar12[1] = (longlong *****)0x0;
          *(undefined4 *)(pppppplVar12 + 2) = 1;
          ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa148);
          *pppppplVar12 = ppppplVar9;
          pppppplVar8 = pppppplVar12;
          if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2eac;
        }
        ppppplStack_108 = (longlong *****)pppppplVar8;
        if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2fd5;
        ppppplStack_d0 = (longlong *****)&ppppplStack_108;
        pppppplVar12 = pppppplVar14;
        if (pppppplVar8 != (longlong ******)0x0) {
          pppppplVar12 = (longlong ******)*pppppplVar8;
        }
        uStack_b8 = uStack_f0;
        uStack_b4 = uStack_ec;
        uStack_b0 = (undefined4)uStack_e8;
        uStack_ac = uStack_e8._4_4_;
        uStack_a8 = uStack_e0;
        iVar5 = (*(code *)(*pppplVar4)[0x2d])(pppplVar4,pppppplVar12,&uStack_b8);
        if (iVar5 < 0) {
          FUN_180591c20(iVar5,pppplVar4,&UNK_1806f7278);
        }
        FUN_18018d480(&ppppplStack_108);
        VariantClear(&uStack_f0);
        LOCK();
        pppppplVar8 = pppppplVar11 + 2;
        iVar5 = *(int *)pppppplVar8;
        *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          if (*pppppplVar11 != (longlong *****)0x0) {
            SysFreeString();
            *pppppplVar11 = (longlong *****)0x0;
          }
          if (pppppplVar11[1] != (longlong *****)0x0) {
            func_0x00018058e2a6();
            pppppplVar11[1] = (longlong *****)0x0;
          }
          func_0x00018058eb90(pppppplVar11,0x18);
        }
        pppplVar4 = pppplStack_90;
        ppppplStackX_20 = (longlong *****)0x0;
        if ((longlong *****)pppplStack_90 == (longlong *****)0x0) goto LAB_1801c3022;
        lVar1 = *(longlong *)(param_1 + 0x80);
        pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
        if (pppppplVar11 == (longlong ******)0x0) {
          pppppplVar11 = (longlong ******)0x0;
        }
        else {
          pppppplVar11[1] = (longlong *****)0x0;
          *(undefined4 *)(pppppplVar11 + 2) = 1;
          ppppplStackX_20 = (longlong *****)pppppplVar11;
          ppppplVar9 = (longlong *****)SysAllocString(lVar1);
          *pppppplVar11 = ppppplVar9;
          if ((ppppplVar9 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2ec2;
        }
        ppppplStackX_20 = (longlong *****)pppppplVar11;
        if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2fe0;
        uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
        ppppplVar9 = *pppppplVar11;
        if (ppppplVar9 != (longlong *****)0x0) {
          uVar6 = SysStringByteLen(ppppplVar9);
          uStack_e8 = SysAllocStringByteLen(ppppplVar9,uVar6);
          if (uStack_e8 != 0) goto LAB_1801c28f3;
          goto LAB_1801c2ed8;
        }
        uStack_e8 = 0;
LAB_1801c28f3:
        ppppplStack_c0 = (longlong *****)&ppppplStack_108;
        pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
        pppppplVar8 = pppppplVar14;
        ppppplStack_d0 = (longlong *****)pppppplVar12;
        if (pppppplVar12 != (longlong ******)0x0) {
          pppppplVar12[1] = (longlong *****)0x0;
          *(undefined4 *)(pppppplVar12 + 2) = 1;
          ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa548);
          *pppppplVar12 = ppppplVar9;
          pppppplVar8 = pppppplVar12;
          if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2ecd;
        }
        ppppplStack_108 = (longlong *****)pppppplVar8;
        if (pppppplVar8 == (longlong ******)0x0) goto LAB_1801c2feb;
        ppppplStack_d0 = (longlong *****)&ppppplStack_108;
        pppppplVar12 = pppppplVar14;
        if (pppppplVar8 != (longlong ******)0x0) {
          pppppplVar12 = (longlong ******)*pppppplVar8;
        }
        uStack_b8 = uStack_f0;
        uStack_b4 = uStack_ec;
        uStack_b0 = (undefined4)uStack_e8;
        uStack_ac = uStack_e8._4_4_;
        uStack_a8 = uStack_e0;
        iVar5 = (*(code *)(*pppplVar4)[0x2d])(pppplVar4,pppppplVar12,&uStack_b8);
        if (iVar5 < 0) {
          FUN_180591c20(iVar5,pppplVar4,&UNK_1806f7278);
        }
        FUN_18018d480(&ppppplStack_108);
        VariantClear(&uStack_f0);
        LOCK();
        pppppplVar8 = pppppplVar11 + 2;
        iVar5 = *(int *)pppppplVar8;
        *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          if (*pppppplVar11 != (longlong *****)0x0) {
            SysFreeString();
            *pppppplVar11 = (longlong *****)0x0;
          }
          if (pppppplVar11[1] != (longlong *****)0x0) {
            func_0x00018058e2a6();
            pppppplVar11[1] = (longlong *****)0x0;
          }
          func_0x00018058eb90(pppppplVar11,0x18);
        }
        pppplVar4 = pppplStack_90;
        ppppplStackX_20 = (longlong *****)0x0;
        lVar1 = *(longlong *)(param_1 + 0x88);
        if (*(int *)(lVar1 + -0x10) != 0) {
          if ((longlong *****)pppplStack_90 != (longlong *****)0x0) {
            pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
            if (pppppplVar11 == (longlong ******)0x0) {
              pppppplVar11 = (longlong ******)0x0;
            }
            else {
              pppppplVar11[1] = (longlong *****)0x0;
              *(undefined4 *)(pppppplVar11 + 2) = 1;
              ppppplStackX_20 = (longlong *****)pppppplVar11;
              ppppplVar9 = (longlong *****)SysAllocString(lVar1);
              *pppppplVar11 = ppppplVar9;
              if ((ppppplVar9 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2ee3;
            }
            ppppplStackX_20 = (longlong *****)pppppplVar11;
            if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2ff6;
            uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
            ppppplVar9 = *pppppplVar11;
            if (ppppplVar9 != (longlong *****)0x0) {
              uVar6 = SysStringByteLen(ppppplVar9);
              uStack_e8 = SysAllocStringByteLen(ppppplVar9,uVar6);
              if (uStack_e8 != 0) goto LAB_1801c2aa0;
              goto LAB_1801c2ef9;
            }
            uStack_e8 = 0;
LAB_1801c2aa0:
            ppppplStack_c0 = (longlong *****)&ppppplStack_108;
            pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
            pppppplVar8 = pppppplVar14;
            ppppplStack_d0 = (longlong *****)pppppplVar12;
            if (pppppplVar12 != (longlong ******)0x0) {
              pppppplVar12[1] = (longlong *****)0x0;
              *(undefined4 *)(pppppplVar12 + 2) = 1;
              ppppplVar9 = (longlong *****)SysAllocString(&UNK_1806fa560);
              *pppppplVar12 = ppppplVar9;
              pppppplVar8 = pppppplVar12;
              if (ppppplVar9 == (longlong *****)0x0) goto LAB_1801c2eee;
            }
            ppppplStack_108 = (longlong *****)pppppplVar8;
            if (pppppplVar8 != (longlong ******)0x0) {
              ppppplStack_d0 = (longlong *****)&ppppplStack_108;
              if (pppppplVar8 != (longlong ******)0x0) {
                pppppplVar14 = (longlong ******)*pppppplVar8;
              }
              uStack_b8 = uStack_f0;
              uStack_b4 = uStack_ec;
              uStack_b0 = (undefined4)uStack_e8;
              uStack_ac = uStack_e8._4_4_;
              uStack_a8 = uStack_e0;
              iVar5 = (*(code *)(*pppplVar4)[0x2d])(pppplVar4,pppppplVar14,&uStack_b8);
              if (iVar5 < 0) {
                FUN_180591c20(iVar5,pppplVar4,&UNK_1806f7278);
              }
              FUN_18018d480(&ppppplStack_108);
              VariantClear(&uStack_f0);
              LOCK();
              pppppplVar14 = pppppplVar11 + 2;
              iVar5 = *(int *)pppppplVar14;
              *(int *)pppppplVar14 = *(int *)pppppplVar14 + -1;
              UNLOCK();
              if (iVar5 == 1) {
                if (*pppppplVar11 != (longlong *****)0x0) {
                  SysFreeString();
                  *pppppplVar11 = (longlong *****)0x0;
                }
                if (pppppplVar11[1] != (longlong *****)0x0) {
                  func_0x00018058e2a6();
                  pppppplVar11[1] = (longlong *****)0x0;
                }
                func_0x00018058eb90(pppppplVar11,0x18);
              }
              goto LAB_1801c2bca;
            }
            goto LAB_1801c3001;
          }
          goto LAB_1801c300c;
        }
LAB_1801c2bca:
        iVar5 = aiStackX_18[0];
        ppppplStack_c0 = (longlong *****)&ppppplStackX_20;
        ppppplStackX_20 = (longlong *****)pppplStack_90;
        if ((longlong *****)pppplStack_90 != (longlong *****)0x0) {
          (*(code *)(*pppplStack_90)[1])();
        }
        ppppplStack_d0 = (longlong *****)&ppppplStack_f8;
        ppppplStack_f8 = ppppplStack_88;
        if ((longlong ******)ppppplStack_88 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_88)[1])();
        }
        ppppplStack_78 = (longlong *****)&ppppplStack_100;
        ppppplStack_100 = (longlong *****)*param_2;
        if (ppppplStack_100 != (longlong *****)0x0) {
          (*(code *)(*ppppplStack_100)[1])();
        }
        FUN_1801ba1e0(&ppppplStack_100,&ppppplStack_f8,&ppppplStackX_20,iVar5);
        if ((longlong *****)pppplStack_90 != (longlong *****)0x0) {
          (*(code *)(*pppplStack_90)[2])();
        }
        if ((longlong ******)ppppplStack_d8 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_d8)[2])();
        }
        iVar5 = aiStackX_18[0] + -1;
        ppppplStack_c0 = (longlong *****)&ppppplStackX_20;
        ppppplStackX_20 = ppppplStack_88;
        aiStackX_18[0] = iVar5;
        if ((longlong ******)ppppplStack_88 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_88)[1])();
        }
        ppppplStack_d0 = (longlong *****)&ppppplStack_f8;
        ppppplStack_f8 = ppppplStack_c8;
        if ((longlong ******)ppppplStack_c8 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_c8)[1])();
        }
        ppppplStack_50 = (longlong *****)&ppppplStack_100;
        ppppplStack_100 = (longlong *****)*param_2;
        if ((longlong ******)ppppplStack_100 != (longlong ******)0x0) {
          (*(code *)(*ppppplStack_100)[1])();
        }
        FUN_1801ba1e0(&ppppplStack_100,&ppppplStack_f8,&ppppplStackX_20,iVar5);
        plVar2 = (longlong *)*param_2;
        if (plVar2 != (longlong *)0x0) {
          ppppplStackX_20 = (longlong *****)0x0;
          iVar5 = (**(code **)(*plVar2 + 0xa8))(plVar2,ppppplStack_c8,&ppppplStackX_20);
          if (iVar5 < 0) {
            FUN_180591c20(iVar5,plVar2,&UNK_1806f7288);
          }
          uStack_98 = 0;
          if (ppppplStackX_20 != (longlong *****)0x0) {
            (*(code *)(*ppppplStackX_20)[2])();
          }
          ppppplStack_c0 = (longlong *****)&ppppplStackX_20;
          ppppplStackX_20 = (longlong *****)*param_2;
          if (ppppplStackX_20 != (longlong *****)0x0) {
            (*(code *)(*ppppplStackX_20)[1])();
          }
          uVar7 = loaded_1801bf1a0(param_1,&ppppplStackX_20,0);
          if ((longlong ******)ppppplStack_88 != (longlong ******)0x0) {
            (*(code *)(*ppppplStack_88)[2])();
          }
          aiStackX_18[0] = aiStackX_18[0] + -1;
          __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&lStack_80);
          __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&lStack_58);
          if ((longlong ******)ppppplStack_c8 != (longlong ******)0x0) {
            (*(code *)(*ppppplStack_c8)[2])();
          }
          if ((longlong *)*param_2 != (longlong *)0x0) {
            (**(code **)(*(longlong *)*param_2 + 0x10))();
          }
          return (ulonglong)uVar7;
        }
      }
      func_0x000180591c10(0x80004003);
LAB_1801c3022:
      func_0x000180591c10(0x80004003);
      pcVar3 = (code *)swi(3);
      uVar13 = (*pcVar3)();
      return uVar13;
    }
    if ((longlong ******)ppppplStack_d8 == (longlong ******)0x0) goto LAB_1801c2fb4;
    pppppplVar11 = (longlong ******)func_0x00018058e29a(0x18);
    if (pppppplVar11 == (longlong ******)0x0) {
      pppppplVar11 = (longlong ******)0x0;
    }
    else {
      pppppplVar11[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar11 + 2) = 1;
      ppppplStackX_20 = (longlong *****)pppppplVar11;
      ppppplVar10 = (longlong *****)SysAllocString(lVar1);
      *pppppplVar11 = ppppplVar10;
      if ((ppppplVar10 == (longlong *****)0x0) && (lVar1 != 0)) goto LAB_1801c2e75;
    }
    ppppplStackX_20 = (longlong *****)pppppplVar11;
    if (pppppplVar11 == (longlong ******)0x0) goto LAB_1801c2f9e;
    uStack_f0 = CONCAT22(uStack_f0._2_2_,8);
    ppppplVar10 = *pppppplVar11;
    if (ppppplVar10 != (longlong *****)0x0) {
      uVar6 = SysStringByteLen(ppppplVar10);
      uStack_e8 = SysAllocStringByteLen(ppppplVar10,uVar6);
      if (uStack_e8 != 0) goto LAB_1801c24ad;
      goto LAB_1801c2e8b;
    }
    uStack_e8 = 0;
LAB_1801c24ad:
    ppppplStack_f8 = (longlong *****)&ppppplStack_108;
    pppppplVar12 = (longlong ******)func_0x00018058e29a(0x18);
    pppppplVar8 = pppppplVar14;
    ppppplStack_100 = (longlong *****)pppppplVar12;
    if (pppppplVar12 != (longlong ******)0x0) {
      pppppplVar12[1] = (longlong *****)0x0;
      *(undefined4 *)(pppppplVar12 + 2) = 1;
      ppppplVar10 = (longlong *****)SysAllocString(&UNK_1806fa168);
      *pppppplVar12 = ppppplVar10;
      pppppplVar8 = pppppplVar12;
      if (ppppplVar10 == (longlong *****)0x0) goto LAB_1801c2e80;
    }
    ppppplStack_108 = (longlong *****)pppppplVar8;
    if (pppppplVar8 != (longlong ******)0x0) {
      ppppplStack_100 = (longlong *****)&ppppplStack_108;
      pppppplVar12 = pppppplVar14;
      if (pppppplVar8 != (longlong ******)0x0) {
        pppppplVar12 = (longlong ******)*pppppplVar8;
      }
      uStack_b8 = uStack_f0;
      uStack_b4 = uStack_ec;
      uStack_b0 = (undefined4)uStack_e8;
      uStack_ac = uStack_e8._4_4_;
      uStack_a8 = uStack_e0;
      iVar5 = (*(code *)(*ppppplVar9)[0x2d])(ppppplVar9,pppppplVar12,&uStack_b8);
      if (iVar5 < 0) {
        FUN_180591c20(iVar5,ppppplVar9,&UNK_1806f7278);
      }
      FUN_18018d480(&ppppplStack_108);
      VariantClear(&uStack_f0);
      LOCK();
      pppppplVar8 = pppppplVar11 + 2;
      iVar5 = *(int *)pppppplVar8;
      *(int *)pppppplVar8 = *(int *)pppppplVar8 + -1;
      UNLOCK();
      if (iVar5 == 1) {
        if (*pppppplVar11 != (longlong *****)0x0) {
          SysFreeString();
          *pppppplVar11 = (longlong *****)0x0;
        }
        if (pppppplVar11[1] != (longlong *****)0x0) {
          func_0x00018058e2a6();
          pppppplVar11[1] = (longlong *****)0x0;
        }
        func_0x00018058eb90(pppppplVar11,0x18);
      }
      goto LAB_1801c25db;
    }
  }
  func_0x000180591c10(0x8007000e);
LAB_1801c2fb4:
  func_0x000180591c10(0x80004003);
  pcVar3 = (code *)swi(3);
  uVar13 = (*pcVar3)();
  return uVar13;
}

