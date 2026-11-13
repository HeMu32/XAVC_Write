// ELF VMA 0x359529c; Ghidra bias 0x100000

void appfw_359529c(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  ulong *puVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 *puVar16;
  undefined1 auVar17 [16];
  undefined1 uStack_6badd;
  undefined4 uStack_6badc;
  undefined4 uStack_6bad8;
  undefined4 uStack_6bad4;
  undefined8 uStack_6bad0;
  undefined8 uStack_6bac8;
  undefined8 uStack_6bac0;
  long *plStack_6bab8;
  undefined4 uStack_6bab0;
  undefined1 uStack_6baac;
  undefined1 uStack_6baab;
  undefined8 uStack_6baa8;
  undefined8 uStack_6baa0;
  ulong uStack_6ba98;
  undefined8 uStack_6ba90;
  undefined8 uStack_6ba88;
  ulong uStack_6ba80;
  undefined4 uStack_6ba78;
  undefined4 uStack_6b030;
  undefined4 uStack_61e58;
  undefined4 uStack_61e54;
  undefined1 uStack_61a88;
  undefined8 uStack_61a80;
  undefined8 uStack_61a78;
  undefined8 uStack_61a70;
  ulong uStack_61a68;
  ulong uStack_61a60;
  undefined4 uStack_61a58;
  undefined4 uStack_61a54;
  int iStack_61a50;
  undefined4 uStack_57e38;
  undefined4 uStack_57e34;
  undefined1 uStack_57a68;
  
  uStack_6badd = 0;
  if ((*(char *)(param_1 + 0x10) == '\0') || (*(char *)(param_1 + 0x12) != '\0')) {
    uStack_6baa0 = *(undefined4 **)(param_1 + 0x18);
    uStack_6ba98 = CONCAT44(uStack_6ba98._4_4_,*(undefined4 *)(param_1 + 0x20));
    uStack_6ba90 = CONCAT44(uStack_6ba90._4_4_,*(undefined4 *)(param_1 + 0x30));
    uVar6 = appfw_2e2c25c(*(undefined4 *)(param_1 + 0x38));
    uStack_6ba90 = CONCAT44(uVar6,(undefined4)uStack_6ba90);
    uVar4 = appfw_3594a94(param_1,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                          *(undefined1 *)(param_1 + 0x7c));
    uStack_6ba88._0_5_ = CONCAT14(uVar4,(undefined4)uStack_6ba88);
    uStack_6ba80 = CONCAT35(uStack_6ba80._5_3_,0x100000000);
    uStack_6ba80 = CONCAT44(uStack_6ba80._4_4_,*(undefined4 *)(param_1 + 0x70));
    appfw_35a924c(&uStack_6baa0,&uStack_61a80);
    if (iStack_61a50 == 0) {
      uStack_6badc = uStack_61a54;
      *(undefined4 *)(param_1 + 0x48) = (undefined4)uStack_61a78;
      goto LAB_03695374;
    }
    puVar16 = &uStack_6bad0;
    func_0x02fe71e8(puVar16);
    uStack_6bac8 = 0;
    func_0x03694a18(&uStack_6bac0,0);
    uStack_6baac = 1;
    *(undefined4 *)(uStack_6bac0 + 1) = 0;
    func_0x03694fd0(&uStack_6bac0);
    uVar3 = uStack_6bac8;
    puVar9 = (ulong *)func_0x029ed1e0();
    plStack_6bab8 = (long *)func_0x029ed1f4();
    uStack_6baac = 0;
    uStack_6baab = 0;
    uStack_6bad4 = 0;
    uStack_6bab0 = 0x1a6;
    uStack_6baa8 = uVar3;
    uStack_6bac0 = puVar9;
    if (plStack_6bab8[1] == 0) {
      func_0x038284b4(uVar3,0x1a6,puVar9,&uStack_6bad4,4);
    }
    else {
      func_0x038284b4(uVar3,0x1a6,plStack_6bab8[1],&uStack_6bad4,4);
      *(undefined4 *)plStack_6bab8[1] = 0;
      uStack_6baab = 1;
    }
    *(undefined4 *)uStack_6bac0 = 0;
    uStack_6baac = 1;
    func_0x03695050(&uStack_6bac0);
  }
  else {
    uStack_6badc = 0;
LAB_03695374:
    cVar5 = func_0x03259610();
    if ((cVar5 != '\0') &&
       ((*(char *)(param_1 + 0x10) == '\0' || (*(char *)(param_1 + 0x12) != '\0')))) {
      uStack_61a80 = (undefined4 *)CONCAT44(*(undefined4 *)(param_1 + 0x28),2);
      uStack_61a78 = (long *)CONCAT44(uStack_61a78._4_4_,*(undefined4 *)(param_1 + 0x2c));
      appfw_35a92cc(&uStack_61a80,&uStack_6baa0);
    }
    cVar5 = appfw_3594a94(param_1,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                          *(undefined1 *)(param_1 + 0x7c));
    if (cVar5 == '\0') {
      uVar6 = *(undefined4 *)(param_1 + 0x48);
      uVar15 = uStack_6badc;
    }
    else if ((*(char *)(param_1 + 0x10) == '\0') || (*(char *)(param_1 + 0x12) != '\0')) {
      uStack_6baa0 = *(undefined4 **)(param_1 + 0x18);
      uStack_6ba98 = CONCAT44(uStack_6ba98._4_4_,*(undefined4 *)(param_1 + 0x20));
      uStack_6ba90 = CONCAT44(uStack_6ba90._4_4_,*(undefined4 *)(param_1 + 0x30));
      uVar6 = appfw_2e2c25c(*(undefined4 *)(param_1 + 0x38));
      uStack_6ba90 = CONCAT44(uVar6,(undefined4)uStack_6ba90);
      uStack_6ba88._0_5_ = CONCAT14(1,*(undefined4 *)(param_1 + 0x70));
      appfw_35a928c(&uStack_6baa0,&uStack_61a80);
      if (iStack_61a50 != 0) goto LAB_03695510;
      uVar6 = (undefined4)uStack_61a78;
      uVar15 = uStack_61a54;
    }
    else {
      uVar15 = 1;
      uVar6 = *(undefined4 *)(param_1 + 0x80);
    }
    if ((*(int *)(param_1 + 0x84) == 0) && (*(char *)(param_1 + 0x10) != '\0')) {
      cVar5 = appfw_3594a94(param_1,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                            *(undefined1 *)(param_1 + 0x7c));
      if (cVar5 != '\0') {
        uVar15 = 1;
        func_0x01815020(&uStack_61a80,0,0xa020);
        uStack_6baa0 = (undefined4 *)0x0;
        uStack_6ba98 = uStack_6ba98 & 0xffffffff00000000;
        uStack_57e38 = 1;
        uStack_57e34 = 0x39;
        uStack_61a80 = (undefined4 *)CONCAT44(0x16,*(undefined4 *)(param_1 + 0x30));
        uStack_57a68 = func_0x02fe59c8(0x1bd4);
        func_0x036a964c(&uStack_61a80,&uStack_6baa0);
        uVar6 = uStack_6baa0._4_4_;
        if ((int)uStack_6ba98 != 0) goto LAB_03695510;
      }
      func_0x01815020(&uStack_61a80,0,0xa020);
      uStack_6baa0 = (undefined4 *)0x0;
      uStack_6ba98 = uStack_6ba98 & 0xffffffff00000000;
      uStack_57e38 = uStack_6badc;
      uStack_57e34 = 0x39;
      uStack_61a80 = (undefined4 *)CONCAT44(0x16,*(undefined4 *)(param_1 + 0x30));
      uStack_57a68 = func_0x02fe59c8(0x1bd4);
      func_0x036a964c(&uStack_61a80,&uStack_6baa0);
      if ((int)uStack_6ba98 != 0) goto LAB_03695510;
      uStack_6badc = (undefined4)uStack_6baa0;
      *(undefined4 *)(param_1 + 0x48) = uStack_6baa0._4_4_;
      cVar5 = appfw_3594a94(param_1,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                            *(undefined1 *)(param_1 + 0x7c));
      if (cVar5 == '\0') {
        uVar6 = *(undefined4 *)(param_1 + 0x48);
        uVar15 = uStack_6badc;
      }
    }
    puVar16 = &uStack_6bac0;
    uVar14 = uVar6;
    if ((*(char *)(param_1 + 0x94) != '\0') && (*(char *)(param_1 + 0x11) != '\0')) {
      uStack_6bad8 = 0xffffffff;
      func_0x03694c44(param_1,uVar15,uVar6,*(undefined4 *)(param_1 + 0x6c),&uStack_61a80,
                      &uStack_6bad8);
      auVar17 = appfw_3155838(param_1 + 0x408,uVar15,0x39,1);
      uVar15 = auVar17._4_4_;
      uVar14 = auVar17._8_4_;
      uStack_6bac8 = CONCAT44(uStack_6bac8._4_4_,uVar14);
      uStack_6bad0._0_4_ = auVar17._0_4_;
      uStack_6bad0._4_4_ = uVar15;
      func_0x02fe71e8(puVar16);
      plStack_6bab8 = (long *)0x0;
      puVar8 = (undefined4 *)func_0x02a22aa4();
      uStack_6ba98 = func_0x02a22ab8();
      uStack_6ba90._4_4_ = (uint)(uStack_6ba90 >> 0x20) & 0xffff0000;
      uStack_6ba90 = CONCAT44(uStack_6ba90._4_4_,0x2554);
      uStack_6ba88 = 0;
      uStack_6bad4 = uVar14;
      uStack_6baa0 = puVar8;
      if (*(long *)(uStack_6ba98 + 8) == 0) {
        func_0x038284b4(0,0x2554,puVar8,&uStack_6bad4,4);
      }
      else {
        func_0x038284b4(0,0x2554,*(long *)(uStack_6ba98 + 8),&uStack_6bad4,4);
        **(undefined4 **)(uStack_6ba98 + 8) = uVar14;
        uStack_6ba90._0_6_ = CONCAT15(1,(undefined5)uStack_6ba90);
      }
      *uStack_6baa0 = uVar14;
      uStack_6ba90._0_5_ = CONCAT14(1,(undefined4)uStack_6ba90);
      func_0x036950ec(&uStack_6baa0);
      func_0x03694a68(puVar16);
      func_0x038258d4(&UNK_04cf7223,uVar15);
      func_0x038258d4(&UNK_04cf726a,auVar17._8_8_ & 0xffffffff);
      cVar5 = appfw_3594a94(param_1,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                            *(undefined1 *)(param_1 + 0x7c));
      if (cVar5 == '\0') {
        *(undefined4 *)(param_1 + 0x48) = uVar14;
        uStack_6badc = uVar15;
      }
      else {
        func_0x01815020(&uStack_6baa0,0,0xa020);
        uStack_6bac0 = (ulong *)0x0;
        plStack_6bab8 = (long *)((ulong)plStack_6bab8 & 0xffffffff00000000);
        uStack_6baa0 = (undefined4 *)CONCAT44(7,*(undefined4 *)(param_1 + 0x30));
        uStack_61e54 = 0x39;
        uStack_61e58 = uVar15;
        uStack_61a88 = func_0x02fe59c8(0x1bd4);
        func_0x036a964c(&uStack_6baa0,puVar16);
        uStack_6badc = (undefined4)uStack_6bac0;
        *(undefined4 *)(param_1 + 0x48) = uStack_6bac0._4_4_;
      }
      func_0x038258d4(&UNK_04cf72b1,uStack_6badc);
      func_0x038258d4(&UNK_04cf72f0,*(undefined4 *)(param_1 + 0x48));
      uStack_6baa0 = (undefined4 *)CONCAT44(uStack_6baa0._4_4_,0xffffffff);
      func_0x03694cac(param_1,uVar15,auVar17._8_8_ & 0xffffffff,&uStack_61a80,uStack_6bad8,uVar6,
                      *(undefined4 *)(param_1 + 0x6c),&uStack_6baa0,&uStack_6badd);
      *(undefined4 *)(param_1 + 0x6c) = (undefined4)uStack_6baa0;
    }
    if (*(int *)(param_1 + 0x6c) == -1) {
      if (*(int *)(param_1 + 0x18) == 2) {
        iVar7 = func_0x03694e18(param_1,uStack_6badc);
        if (iVar7 != -1) {
          uStack_6baa0 = (undefined4 *)CONCAT44(iVar7,uStack_6badc);
          *(int *)(param_1 + 0x6c) = iVar7;
          uStack_6badd = 1;
          func_0x036a974c(&uStack_6baa0,&uStack_61a80);
          *(undefined4 *)(param_1 + 0x40) = (undefined4)uStack_61a80;
          goto LAB_03695914;
        }
        iVar7 = *(int *)(param_1 + 0x48) + -1;
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(param_1 + 0x40) = iVar7;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x48) + -1;
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(param_1 + 0x40) = iVar7;
      }
      uStack_6badd = 1;
      uStack_61a80 = (undefined4 *)CONCAT44(iVar7,uStack_6badc);
      func_0x036a978c(&uStack_61a80,&uStack_6baa0);
      *(undefined4 *)(param_1 + 0x6c) = (undefined4)uStack_6baa0;
    }
LAB_03695914:
    if (*(char *)(param_1 + 0x7c) != '\0') {
      uStack_61a80 = (undefined4 *)
                     CONCAT44(*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x30));
      func_0x036a958c(&uStack_61a80,&uStack_6baa0);
      func_0x01815020(&uStack_61a80,0,0xa020);
      uStack_6bac0 = (ulong *)0x0;
      plStack_6bab8 = (long *)((ulong)plStack_6bab8 & 0xffffffff00000000);
      uStack_61a80 = (undefined4 *)CONCAT44(5,*(undefined4 *)(param_1 + 0x30));
      uStack_61a78 = (long *)CONCAT44(uStack_61a78._4_4_,uStack_6b030);
      uStack_57e38 = uStack_6badc;
      uStack_57e34 = 0x39;
      uStack_57a68 = func_0x02fe59c8(0x1bd4);
      func_0x036a964c(&uStack_61a80,puVar16);
      if ((int)plStack_6bab8 != 0) goto LAB_03695510;
      *(undefined4 *)(param_1 + 0x48) = uStack_6bac0._4_4_;
      uStack_6badc = (undefined4)uStack_6bac0;
      uVar14 = uStack_6bac0._4_4_;
      uVar15 = (undefined4)uStack_6bac0;
    }
    uStack_61a80 = (undefined4 *)CONCAT44(4,uVar15);
    func_0x036a9bcc(&uStack_61a80,&uStack_6baa0);
    uVar6 = *(undefined4 *)(param_1 + 0x28);
    func_0x01815020(&uStack_61a80,0,0xa020);
    uStack_6baa0 = (undefined4 *)0x0;
    uStack_6ba98 = uStack_6ba98 & 0xffffffff00000000;
    uStack_61a80 = (undefined4 *)CONCAT44(0x1e,*(undefined4 *)(param_1 + 0x30));
    uStack_61a78 = (long *)CONCAT44(5,uVar6);
    uStack_57e34 = 5;
    uStack_57e38 = uVar15;
    uStack_57a68 = func_0x02fe59c8(0x1bd4);
    func_0x036a964c(&uStack_61a80,&uStack_6baa0);
    uVar6 = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x50) = uStack_6baa0._4_4_;
    func_0x01815020(&uStack_61a80,0,0xa020);
    uStack_6baa0 = (undefined4 *)0x0;
    uStack_6ba98 = uStack_6ba98 & 0xffffffff00000000;
    uStack_61a80 = (undefined4 *)CONCAT44(0x1e,*(undefined4 *)(param_1 + 0x30));
    uStack_61a78 = (long *)CONCAT44(6,uVar6);
    uStack_57e34 = 6;
    uStack_57e38 = uVar15;
    uStack_57a68 = func_0x02fe59c8(0x1bd4);
    func_0x036a964c(&uStack_61a80,&uStack_6baa0);
    *(undefined4 *)(param_1 + 0x58) = uStack_6baa0._4_4_;
    cVar5 = func_0x03694ab8(param_1,*(undefined4 *)(param_1 + 0x6c),uStack_6badc);
    if (cVar5 == '\0') {
      func_0x03694ae4(param_1,*(undefined4 *)(param_1 + 0x6c),&uStack_6badc,param_1 + 0x40,
                      param_1 + 0x6c);
    }
    else {
      uStack_6baa0 = (undefined4 *)CONCAT44(*(undefined4 *)(param_1 + 0x6c),uStack_6badc);
      func_0x036a974c(&uStack_6baa0,&uStack_61a80);
      *(undefined4 *)(param_1 + 0x40) = (undefined4)uStack_61a80;
    }
    cVar5 = func_0x03694ab8(param_1,*(undefined4 *)(param_1 + 0x6c),uStack_6badc);
    func_0x02fe71e8(&uStack_6bad0);
    uStack_6bac8 = 0;
    puVar8 = (undefined4 *)func_0x029ed1b8();
    uStack_61a78 = (long *)func_0x029ed1cc();
    uVar6 = uStack_6badc;
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x1a5);
    uStack_61a68 = 0;
    uStack_6baa0 = (undefined4 *)CONCAT44(uStack_6baa0._4_4_,uStack_6badc);
    uStack_61a80 = puVar8;
    if (*uStack_61a78 == 0) {
      func_0x038284b4(0,0x1a5,puVar8,&uStack_6baa0,4);
    }
    else {
      func_0x038284b4(0,0x1a5,*uStack_61a78,&uStack_6baa0,4);
      *(undefined4 *)*uStack_61a78 = uVar6;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *uStack_61a80 = uVar6;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x0369501c(&uStack_61a80);
    uVar3 = uStack_6bac8;
    puVar8 = (undefined4 *)func_0x029ed1e0();
    uStack_61a78 = (long *)func_0x029ed1f4();
    uVar6 = *(undefined4 *)(param_1 + 0x48);
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x1a6);
    uStack_61a68 = uVar3;
    uStack_6baa0 = (undefined4 *)CONCAT44(uStack_6baa0._4_4_,uVar6);
    uStack_61a80 = puVar8;
    if (*(long *)((long)uStack_61a78 + 8) == 0) {
      func_0x038284b4(uVar3,0x1a6,puVar8,&uStack_6baa0,4);
    }
    else {
      func_0x038284b4(uVar3,0x1a6,*(long *)((long)uStack_61a78 + 8),&uStack_6baa0,4);
      **(undefined4 **)((long)uStack_61a78 + 8) = uVar6;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *uStack_61a80 = uVar6;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x03695050(&uStack_61a80);
    uVar3 = uStack_6bac8;
    puVar8 = (undefined4 *)func_0x029ed208();
    uStack_61a78 = (long *)func_0x029ed21c();
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x1a7);
    uStack_61a68 = uVar3;
    uStack_6baa0 = (undefined4 *)CONCAT44(uStack_6baa0._4_4_,uVar15);
    uStack_61a80 = puVar8;
    if (*uStack_61a78 == 0) {
      func_0x038284b4(uVar3,0x1a7,puVar8,&uStack_6baa0,4);
    }
    else {
      func_0x038284b4(uVar3,0x1a7,*uStack_61a78,&uStack_6baa0,4);
      *(undefined4 *)*uStack_61a78 = uVar15;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *uStack_61a80 = uVar15;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x03695084(&uStack_61a80);
    uVar3 = uStack_6bac8;
    puVar8 = (undefined4 *)func_0x029ed230();
    uStack_61a78 = (long *)func_0x029ed244();
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x1a8);
    uStack_61a68 = uVar3;
    uStack_6baa0 = (undefined4 *)CONCAT44(uStack_6baa0._4_4_,uVar14);
    uStack_61a80 = puVar8;
    if (*(long *)((long)uStack_61a78 + 8) == 0) {
      func_0x038284b4(uVar3,0x1a8,puVar8,&uStack_6baa0,4);
    }
    else {
      func_0x038284b4(uVar3,0x1a8,*(long *)((long)uStack_61a78 + 8),&uStack_6baa0,4);
      **(undefined4 **)((long)uStack_61a78 + 8) = uVar14;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *uStack_61a80 = uVar14;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x036950b8(&uStack_61a80);
    uVar3 = uStack_6bac8;
    puVar8 = (undefined4 *)func_0x02a23274();
    uStack_61a78 = (long *)func_0x02a23288();
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x264c);
    uStack_61a68 = uVar3;
    uStack_6baa0 = (undefined4 *)((ulong)uStack_6baa0 & 0xffffffffffffff00);
    uStack_61a80 = puVar8;
    if (uStack_61a78[1] == 0) {
      func_0x038284b4(uVar3,0x264c,puVar8,&uStack_6baa0,1);
    }
    else {
      func_0x038284b4(uVar3,0x264c,uStack_61a78[1],&uStack_6baa0,1);
      *(undefined1 *)uStack_61a78[1] = 0;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *(undefined1 *)uStack_61a80 = 0;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x03695154(&uStack_61a80);
    if ((cVar5 == '\0') && (*(int *)(param_1 + 0x48) != 0)) {
      func_0x03694a18(&uStack_61a80,uStack_6bac8);
      uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
      uStack_61a80[2] = *(undefined4 *)(param_1 + 0x48);
      func_0x03694fd0(&uStack_61a80);
      func_0x03694a18(&uStack_61a80,uStack_6bac8);
      uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
      uStack_61a80[4] = *(undefined4 *)(param_1 + 0x50);
      func_0x03694fd0(&uStack_61a80);
      func_0x03694a18(&uStack_61a80,uStack_6bac8);
      uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
      uStack_61a80[6] = *(undefined4 *)(param_1 + 0x58);
      func_0x03694fd0(&uStack_61a80);
      uStack_6badd = 1;
    }
    else {
      func_0x03694a18(puVar16,uStack_6bac8);
      uStack_6ba78 = *(undefined4 *)(param_1 + 0x68);
      uStack_6ba80 = *(ulong *)(param_1 + 0x60);
      uStack_6baa0 = *(undefined4 **)(param_1 + 0x40);
      uStack_6ba98 = *(ulong *)(param_1 + 0x48);
      uStack_6ba90 = *(ulong *)(param_1 + 0x50);
      uStack_6ba88 = *(ulong *)(param_1 + 0x58);
      uStack_61a80 = uStack_6baa0;
      uStack_61a78 = (long *)uStack_6ba98;
      uStack_61a70 = uStack_6ba90;
      uStack_61a68 = uStack_6ba88;
      uStack_61a60 = uStack_6ba80;
      uStack_61a58 = uStack_6ba78;
      if (*plStack_6bab8 == 0) {
        func_0x038284b4(uStack_6baa8,uStack_6bab0,uStack_6bac0,&uStack_61a80,0x2c);
      }
      else {
        func_0x038284b4(uStack_6baa8,uStack_6bab0,*plStack_6bab8,&uStack_61a80,0x2c);
        puVar9 = (ulong *)*plStack_6bab8;
        *puVar9 = (ulong)uStack_6baa0;
        puVar9[1] = uStack_6ba98;
        puVar9[2] = uStack_6ba90;
        puVar9[3] = uStack_6ba88;
        puVar9[4] = uStack_6ba80;
        *(undefined4 *)(puVar9 + 5) = uStack_6ba78;
        uStack_6baab = 1;
      }
      *uStack_6bac0 = (ulong)uStack_6baa0;
      uStack_6bac0[1] = uStack_6ba98;
      uStack_6bac0[2] = uStack_6ba90;
      uStack_6bac0[3] = uStack_6ba88;
      uStack_6bac0[4] = uStack_6ba80;
      *(undefined4 *)(uStack_6bac0 + 5) = uStack_6ba78;
      uStack_6baac = 1;
      func_0x03694fd0(puVar16);
      uVar3 = uStack_6bac8;
      lVar10 = func_0x029ed118();
      lVar11 = func_0x029ed12c();
      uVar2 = *(uint *)(param_1 + 0x34);
      uVar1 = uVar2 + 0x19c;
      uStack_61a80 = (undefined4 *)(lVar10 + (ulong)uVar2 * 4);
      uVar6 = *(undefined4 *)(param_1 + 0x6c);
      lVar10 = (ulong)uVar2 * 0x10;
      uStack_61a78 = (long *)(lVar11 + lVar10);
      lVar10 = *(long *)(lVar11 + lVar10);
      uStack_61a70._0_6_ = (uint6)uVar1;
      uStack_61a68 = uVar3;
      uStack_6bac0 = (ulong *)CONCAT44(uStack_6bac0._4_4_,uVar6);
      if (lVar10 == 0) {
        func_0x038284b4(uVar3,uVar1,uStack_61a80,puVar16,4);
      }
      else {
        func_0x038284b4(uVar3,uVar1,lVar10,puVar16,4);
        *(undefined4 *)*uStack_61a78 = uVar6;
        uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
      }
      *uStack_61a80 = uVar6;
      uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
      func_0x036951bc(&uStack_61a80);
      uVar3 = uStack_6bac8;
      uVar12 = func_0x02a2342c();
      uStack_61a78 = (long *)func_0x02a23440();
      uStack_61a70._0_6_ = 0x2657;
      uStack_61a68 = uVar3;
      uStack_61a80 = (undefined4 *)uVar12;
      func_0x036951f0(&uStack_61a80,*(undefined4 *)(param_1 + 0x6c));
      func_0x03695120(&uStack_61a80);
      uVar3 = uStack_6bac8;
      lVar10 = func_0x029ed140();
      lVar11 = func_0x029ed154();
      uVar2 = *(uint *)(param_1 + 0x34);
      uVar1 = uVar2 + 0x19f;
      uStack_61a80 = (undefined4 *)(lVar10 + (ulong)uVar2 * 4);
      lVar10 = (ulong)uVar2 * 0x10;
      uStack_61a78 = (long *)(lVar11 + lVar10);
      uVar6 = *(undefined4 *)(param_1 + 0x40);
      lVar10 = *(long *)(lVar11 + lVar10);
      uStack_61a70._0_6_ = (uint6)uVar1;
      uStack_61a68 = uVar3;
      uStack_6bac0 = (ulong *)CONCAT44(uStack_6bac0._4_4_,uVar6);
      if (lVar10 == 0) {
        func_0x038284b4(uVar3,uVar1,uStack_61a80,puVar16,4);
      }
      else {
        func_0x038284b4(uVar3,uVar1,lVar10,puVar16,4);
        *(undefined4 *)*uStack_61a78 = uVar6;
        uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
      }
      *uStack_61a80 = uVar6;
      uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
      func_0x03695268(&uStack_61a80);
      func_0x018160b0(&UNK_04cf732f,*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x48))
      ;
    }
    func_0x03694a68(&uStack_6bad0);
    if (cVar5 == '\0') {
      *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
      func_0x0268271c(&uStack_61a80);
      func_0x027523b4(&uStack_61a80,*(undefined4 *)(param_1 + 0x30));
      func_0x0268272c(&uStack_61a80);
      uVar6 = 0xffffffff;
      if (*(int *)(param_1 + 0x48) != 0) {
        uStack_6bac0 = (ulong *)((ulong)uStack_6bac0 & 0xffffffff00000000);
        uStack_61a80 = (undefined4 *)CONCAT44(*(int *)(param_1 + 0x48) + -1,uStack_6badc);
        func_0x036a978c(&uStack_61a80,puVar16);
        uVar6 = (undefined4)uStack_6bac0;
      }
      func_0x02fe71e8(puVar16);
      plStack_6bab8 = (long *)0x0;
      puVar8 = (undefined4 *)func_0x02a2342c();
      uStack_61a78 = (long *)func_0x02a23440();
      uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x2657);
      uStack_61a68 = 0;
      uStack_61a80 = puVar8;
      func_0x036951f0(&uStack_61a80,uVar6);
      func_0x03695120(&uStack_61a80);
      func_0x03694a68(puVar16);
    }
    func_0x02fe71e8(puVar16);
    plStack_6bab8 = (long *)0x0;
    puVar13 = (undefined1 *)func_0x02a232c4();
    uStack_61a78 = (long *)func_0x02a232d8();
    uVar4 = uStack_6badd;
    uStack_61a70 = CONCAT26(uStack_61a70._6_2_,0x264e);
    uStack_61a68 = 0;
    uStack_6bad0._0_4_ = CONCAT31(uStack_6bad0._1_3_,uStack_6badd);
    uStack_61a80 = (undefined4 *)puVar13;
    if (*(long *)((long)uStack_61a78 + 8) == 0) {
      func_0x038284b4(0,0x264e,puVar13,&uStack_6bad0,1);
    }
    else {
      func_0x038284b4(0,0x264e,*(long *)((long)uStack_61a78 + 8),&uStack_6bad0,1);
      **(undefined1 **)((long)uStack_61a78 + 8) = uVar4;
      uStack_61a70._0_6_ = CONCAT15(1,(undefined5)uStack_61a70);
    }
    *(undefined1 *)uStack_61a80 = uVar4;
    uStack_61a70._0_5_ = CONCAT14(1,(undefined4)uStack_61a70);
    func_0x03695188(&uStack_61a80);
  }
  func_0x03694a68(puVar16);
LAB_03695510:
  func_0x03694fa0(param_1);
  return;
}

