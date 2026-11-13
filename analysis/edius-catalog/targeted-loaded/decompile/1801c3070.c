// Normalized static image, not an observed export trace.
// Preferred VA 1801c3070
// Disassembly returned true; body bytes 1768

undefined8 loaded_1801c3070(longlong param_1,longlong *param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong ***ppplVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  longlong ****pppplVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  longlong ****pppplVar13;
  ulonglong uVar14;
  longlong ***ppplStackX_8;
  longlong *plStackX_10;
  longlong ***ppplStackX_18;
  longlong ***ppplStackX_20;
  longlong ***ppplStack_a0;
  longlong ***ppplStack_98;
  undefined8 *puStack_90;
  ulonglong uStack_88;
  longlong ***ppplStack_80;
  undefined8 uStack_78;
  longlong ***ppplStack_70;
  longlong ***ppplStack_68;
  longlong ***ppplStack_60;
  longlong ***appplStack_58 [3];
  
  pppplVar13 = (longlong ****)0x0;
  puVar3 = *(undefined8 **)(param_1 + 0x28);
  puVar12 = *(undefined8 **)(param_1 + 0x20);
  plStackX_10 = param_2;
  if (puVar12 != puVar3) {
    do {
      (**(code **)*puVar12)(puVar12,0);
      puVar12 = puVar12 + 2;
    } while (puVar12 != puVar3);
    *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_1 + 0x20);
  }
  if (*param_2 == 0) {
LAB_1801c373c:
    func_0x000180591c10(0x80004003);
  }
  else {
    FUN_180190250(*param_2,&ppplStackX_20);
    ppplVar4 = ppplStackX_20;
    if ((longlong ****)ppplStackX_20 == (longlong ****)0x0) {
      func_0x000180591c10(0x80004003);
      goto LAB_1801c373c;
    }
    ppplStackX_8 = (longlong ***)0x0;
    iVar8 = (*(code *)(*ppplStackX_20)[0x2b])(ppplStackX_20,&ppplStackX_8);
    if (iVar8 < 0) {
      FUN_180591c20(iVar8,ppplVar4,&UNK_1806f7278);
    }
    ppplVar4 = ppplStackX_8;
    pppplVar10 = (longlong ****)func_0x00018058e29a(0x18);
    if (pppplVar10 != (longlong ****)0x0) {
      pppplVar10[1] = (longlong ***)0x0;
      *(undefined4 *)(pppplVar10 + 2) = 1;
      *pppplVar10 = ppplVar4;
      pppplVar13 = pppplVar10;
    }
    ppplStackX_18 = (longlong ***)pppplVar13;
    if (pppplVar13 != (longlong ****)0x0) {
      iVar9 = _wcsicmp(*pppplVar13,&UNK_1806fa0d8);
      LOCK();
      pppplVar10 = pppplVar13 + 2;
      iVar8 = *(int *)pppplVar10;
      *(int *)pppplVar10 = *(int *)pppplVar10 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        if (*pppplVar13 != (longlong ***)0x0) {
          SysFreeString();
          *pppplVar13 = (longlong ***)0x0;
        }
        if (pppplVar13[1] != (longlong ***)0x0) {
          func_0x00018058e2a6();
          pppplVar13[1] = (longlong ***)0x0;
        }
        func_0x00018058eb90(pppplVar13,0x18);
      }
      ppplStackX_18 = (longlong ***)0x0;
      if (iVar9 == 0) {
        __0__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_78);
        ppplStackX_18 = (longlong ***)&ppplStackX_8;
        ppplStackX_8 = ppplStackX_20;
        if ((longlong ****)ppplStackX_20 != (longlong ****)0x0) {
          (*(code *)(*ppplStackX_20)[1])();
        }
        iVar8 = FUN_1801bc2a0(&ppplStackX_8,&UNK_1806fa0f8,&uStack_78,1);
        if (-1 < iVar8) {
          ppplStackX_8 = (longlong ***)((ulonglong)ppplStackX_8 & 0xffffffff00000000);
          ppplStackX_18 = (longlong ***)((ulonglong)ppplStackX_18 & 0xffffffff00000000);
          FUN_1801b6a70(uStack_78,&UNK_1806fa108,&ppplStackX_8,&ppplStackX_18);
          *(uint *)(param_1 + 0x40) = (int)ppplStackX_8 << 0x10 | (uint)(ushort)ppplStackX_18;
        }
        ppplStackX_18 = (longlong ***)&ppplStackX_8;
        ppplStackX_8 = ppplStackX_20;
        if ((longlong ****)ppplStackX_20 != (longlong ****)0x0) {
          (*(code *)(*ppplStackX_20)[1])();
        }
        FUN_1801bc0b0(&ppplStack_a0,&ppplStackX_8,&UNK_1806fa118,0);
        if ((longlong ****)ppplStack_a0 != (longlong ****)0x0) {
          ppplStackX_18 = (longlong ***)&ppplStackX_8;
          ppplStackX_8 = ppplStack_a0;
          (*(code *)(*ppplStack_a0)[1])();
          FUN_1801bc0b0(&ppplStack_70,&ppplStackX_8,&UNK_1806fa130,0);
          if ((longlong ****)ppplStack_70 != (longlong ****)0x0) {
            ppplStackX_18 = (longlong ***)&ppplStackX_8;
            ppplStackX_8 = ppplStack_70;
            (*(code *)(*ppplStack_70)[1])();
            FUN_1801bc2a0(&ppplStackX_8,&UNK_1806fa148,param_1 + 0x38,1);
          }
          ppplStackX_18 = (longlong ***)&ppplStackX_8;
          ppplStackX_8 = ppplStack_a0;
          if ((longlong ****)ppplStack_a0 != (longlong ****)0x0) {
            (*(code *)(*ppplStack_a0)[1])();
          }
          FUN_1801bc0b0(&ppplStack_98,&ppplStackX_8,&UNK_1806fa158,0);
          if ((longlong ****)ppplStack_98 != (longlong ****)0x0) {
            ppplStackX_18 = (longlong ***)&ppplStackX_8;
            ppplStackX_8 = ppplStack_98;
            (*(code *)(*ppplStack_98)[1])();
            FUN_1801bc2a0(&ppplStackX_8,&UNK_1806fa168,param_1 + 0x48,1);
          }
          if (*(int *)(*(longlong *)(param_1 + 0x38) + -0x10) == 0) {
            ppplStackX_18 = (longlong ***)&ppplStackX_8;
            ppplStackX_8 = ppplStack_a0;
            if ((longlong ****)ppplStack_a0 != (longlong ****)0x0) {
              (*(code *)(*ppplStack_a0)[1])();
            }
            FUN_1801bc0b0(appplStack_58,&ppplStackX_8,&UNK_1806fa188,0);
            if ((longlong ****)appplStack_58[0] != (longlong ****)0x0) {
              ppplStackX_18 = (longlong ***)&ppplStackX_8;
              ppplStackX_8 = appplStack_58[0];
              (*(code *)(*appplStack_58[0])[1])();
              FUN_1801bc0b0(&ppplStack_60,&ppplStackX_8,&UNK_1806fa1a0,0);
              if ((longlong ****)ppplStack_60 != (longlong ****)0x0) {
                ppplStack_68 = (longlong ***)&ppplStackX_8;
                ppplStackX_8 = ppplStack_60;
                (*(code *)(*ppplStack_60)[1])();
                FUN_1801bc0b0(&ppplStackX_18,&ppplStackX_8,&UNK_1806fa1b8,0);
                if ((longlong ****)ppplStackX_18 != (longlong ****)0x0) {
                  ppplStack_68 = (longlong ***)&ppplStackX_8;
                  ppplStackX_8 = ppplStackX_18;
                  (*(code *)(*ppplStackX_18)[1])();
                  FUN_1801bc2a0(&ppplStackX_8,&UNK_1806fa1d8,(longlong *)(param_1 + 0x38),1);
                }
                if ((longlong ****)ppplStackX_18 != (longlong ****)0x0) {
                  (*(code *)(*ppplStackX_18)[2])();
                }
              }
              if ((longlong ****)ppplStack_60 != (longlong ****)0x0) {
                (*(code *)(*ppplStack_60)[2])();
              }
            }
            if ((longlong ****)appplStack_58[0] != (longlong ****)0x0) {
              (*(code *)(*appplStack_58[0])[2])();
            }
          }
          if ((longlong ****)ppplStack_98 != (longlong ****)0x0) {
            (*(code *)(*ppplStack_98)[2])();
          }
          if ((longlong ****)ppplStack_70 != (longlong ****)0x0) {
            (*(code *)(*ppplStack_70)[2])();
          }
        }
        ppplStackX_18 = (longlong ***)&ppplStackX_8;
        ppplStackX_8 = ppplStackX_20;
        if ((longlong ****)ppplStackX_20 != (longlong ****)0x0) {
          (*(code *)(*ppplStackX_20)[1])();
        }
        FUN_1801bc0b0(&ppplStack_80,&ppplStackX_8,&UNK_1806fa1e8,0);
        if ((longlong ****)ppplStack_80 != (longlong ****)0x0) {
          ppplStack_68 = (longlong ***)&ppplStackX_18;
          ppplStackX_18 = ppplStack_80;
          (*(code *)(*ppplStack_80)[1])();
          iVar8 = FUN_1801bb8d0(&ppplStackX_18,&UNK_1806fa200);
          uVar14 = (ulonglong)iVar8;
          pppplVar13 = (longlong ****)(param_1 + 0x20);
          ppplVar4 = *pppplVar13;
          if ((ulonglong)(*(longlong *)(param_1 + 0x30) - (longlong)ppplVar4 >> 4) < uVar14) {
            if (0xfffffffffffffff < uVar14) goto LAB_1801c3752;
            lVar5 = *(longlong *)(param_1 + 0x28);
            uVar11 = FUN_18017cf80(uVar14 << 4);
            ppplStack_98 = (longlong ***)pppplVar13;
            puStack_90 = (undefined8 *)uVar11;
            uStack_88 = uVar14;
            FUN_1801be1a0(*pppplVar13,*(undefined8 *)(param_1 + 0x28),uVar11,pppplVar13);
            puStack_90 = (undefined8 *)0x0;
            FUN_1801bf0b0(pppplVar13,uVar11,lVar5 - (longlong)ppplVar4 >> 4,uVar14);
          }
          iVar9 = 0;
          if (0 < iVar8) {
            do {
              ppplStack_68 = (longlong ***)&ppplStackX_8;
              ppplStackX_8 = ppplStack_80;
              if ((longlong ****)ppplStack_80 != (longlong ****)0x0) {
                (*(code *)(*ppplStack_80)[1])();
              }
              FUN_1801bc0b0(&ppplStackX_18,&ppplStackX_8,&UNK_1806fa200,iVar9);
              if ((longlong ****)ppplStackX_18 != (longlong ****)0x0) {
                ppplStack_70 = (longlong ***)&ppplStackX_8;
                ppplStackX_8 = ppplStackX_18;
                (*(code *)(*ppplStackX_18)[1])();
                FUN_1801c3760(param_1,&ppplStack_98,&ppplStackX_8);
                puVar3 = puStack_90;
                if ((puStack_90 != (undefined8 *)0x0) && ((longlong)puStack_90 / 0x70 != 0)) {
                  plVar6 = *(longlong **)(param_1 + 0x28);
                  if (plVar6 == *(longlong **)(param_1 + 0x30)) {
                    FUN_1801be030(param_1 + 0x20,plVar6,&ppplStack_98);
                  }
                  else {
                    *plVar6 = (longlong)&UNK_1806fa078;
                    plVar6[1] = 0;
                    if (puStack_90 != (undefined8 *)0x0) {
                      LOCK();
                      *(int *)(puStack_90 + 1) = *(int *)(puStack_90 + 1) + 1;
                      UNLOCK();
                    }
                    (**(code **)(*plVar6 + 8))(plVar6);
                    plVar6[1] = (longlong)puVar3;
                    *(longlong *)(param_1 + 0x28) = *(longlong *)(param_1 + 0x28) + 0x10;
                  }
                }
                ppplStack_98 = (longlong ***)&UNK_1806fa078;
                if (puStack_90 != (undefined8 *)0x0) {
                  LOCK();
                  piVar1 = (int *)(puStack_90 + 1);
                  iVar2 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if ((iVar2 < 2) && (puStack_90 != (undefined8 *)0x0)) {
                    (**(code **)*puStack_90)(puStack_90,1);
                  }
                  puStack_90 = (undefined8 *)0x0;
                }
              }
              if ((longlong ****)ppplStackX_18 != (longlong ****)0x0) {
                (*(code *)(*ppplStackX_18)[2])();
              }
              iVar9 = iVar9 + 1;
              param_2 = plStackX_10;
            } while (iVar9 < iVar8);
          }
        }
        if ((longlong ****)ppplStack_80 != (longlong ****)0x0) {
          (*(code *)(*ppplStack_80)[2])();
        }
        if ((longlong ****)ppplStack_a0 != (longlong ****)0x0) {
          (*(code *)(*ppplStack_a0)[2])();
        }
        __1__CStringT__WV__StrTraitMFC_DLL__WV__ChTraitsCRT__W_ATL_____ATL__QEAA_XZ(&uStack_78);
        if ((longlong ****)ppplStackX_20 != (longlong ****)0x0) {
          (*(code *)(*ppplStackX_20)[2])();
        }
        if ((longlong *)*param_2 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*param_2 + 0x10))();
        }
        uVar11 = 0;
      }
      else {
        if ((longlong ****)ppplStackX_20 != (longlong ****)0x0) {
          (*(code *)(*ppplStackX_20)[2])();
        }
        if ((longlong *)*param_2 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*param_2 + 0x10))();
        }
        uVar11 = 0x80004005;
      }
      return uVar11;
    }
  }
  func_0x000180591c10(0x8007000e);
LAB_1801c3752:
  FUN_1801bf180();
  pcVar7 = (code *)swi(3);
  uVar11 = (*pcVar7)();
  return uVar11;
}

