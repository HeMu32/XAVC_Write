// ELF VMA 0x318db78; Ghidra bias 0x100000

void appfw_318db78(long param_1)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auVar4 [16];
  undefined4 uStack_8c;
  undefined1 auStack_88 [8];
  undefined8 uStack_80;
  undefined8 uStack_78;
  ulong uStack_70;
  ulong uStack_68;
  undefined8 uStack_60;
  undefined4 *puStack_58;
  long lStack_50;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  long lStack_30;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined8 uStack_20;
  undefined4 uStack_c;
  int iStack_8;
  
  func_0x02fe71e8(auStack_88);
  uStack_80 = 0;
  uStack_60 = 0;
  uStack_78 = *(undefined8 *)(param_1 + 0x1c);
  uStack_70 = (ulong)*(uint *)(param_1 + 0x24);
  uStack_68 = (ulong)*(uint *)(param_1 + 0x14);
  appfw_35a988c(&uStack_78,&puStack_38);
  uVar1 = uStack_80;
  if (iStack_8 == 0) {
    puVar2 = (undefined4 *)func_0x02a22acc();
    lStack_50 = func_0x02a22ae0();
    uStack_44 = 0;
    uStack_43 = 0;
    uStack_8c = (undefined4)lStack_30;
    uStack_48 = 0x2555;
    uStack_40 = uVar1;
    puStack_58 = puVar2;
    if (*(long *)(lStack_50 + 8) == 0) {
      func_0x038284b4(uVar1,0x2555,puVar2,&uStack_8c,4);
    }
    else {
      func_0x038284b4(uVar1,0x2555,*(long *)(lStack_50 + 8),&uStack_8c,4);
      **(undefined4 **)(lStack_50 + 8) = (undefined4)lStack_30;
      uStack_43 = 1;
    }
    *puStack_58 = (undefined4)lStack_30;
    uStack_44 = 1;
    func_0x0328db44(&puStack_58);
    auVar4 = appfw_3155838(param_1 + 0x3a8,uStack_c,0x39,0,1);
    uVar1 = uStack_80;
    puStack_58 = auVar4._0_8_;
    uVar3 = auVar4._8_4_;
    lStack_50 = CONCAT44(lStack_50._4_4_,uVar3);
    puVar2 = (undefined4 *)func_0x02a22aa4();
    lStack_30 = func_0x02a22ab8();
    uStack_24 = 0;
    uStack_23 = 0;
    uStack_78 = CONCAT44(uStack_78._4_4_,uVar3);
    uStack_28 = 0x2554;
    uStack_20 = uVar1;
    puStack_38 = puVar2;
    if (*(long *)(lStack_30 + 8) == 0) {
      func_0x038284b4(uVar1,0x2554,puVar2,&uStack_78,4);
    }
    else {
      func_0x038284b4(uVar1,0x2554,*(long *)(lStack_30 + 8),&uStack_78,4);
      **(undefined4 **)(lStack_30 + 8) = uVar3;
      uStack_23 = 1;
    }
    *puStack_38 = uVar3;
    uStack_24 = 1;
    func_0x0328db10(&puStack_38);
    func_0x038258d4(&UNK_04ca8595,auVar4._8_8_ & 0xffffffff);
  }
  else {
    puVar2 = (undefined4 *)func_0x02a22acc();
    lStack_50 = func_0x02a22ae0();
    uStack_44 = 0;
    uStack_43 = 0;
    uStack_8c = 0;
    uStack_48 = 0x2555;
    uStack_40 = uVar1;
    puStack_58 = puVar2;
    if (*(long *)(lStack_50 + 8) == 0) {
      func_0x038284b4(uVar1,0x2555,puVar2,&uStack_8c,4);
    }
    else {
      func_0x038284b4(uVar1,0x2555,*(long *)(lStack_50 + 8),&uStack_8c,4);
      **(undefined4 **)(lStack_50 + 8) = 0;
      uStack_43 = 1;
    }
    *puStack_58 = 0;
    uStack_44 = 1;
    func_0x0328db44(&puStack_58);
  }
  func_0x0328dad4(auStack_88);
  return;
}

