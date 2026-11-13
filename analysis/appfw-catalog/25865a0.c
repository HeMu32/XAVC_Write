// ELF VMA 0x25865a0; Ghidra bias 0x100000

void appfw_25865a0(undefined8 param_1,undefined4 param_2,undefined2 *param_3,undefined1 *param_4,
                  undefined1 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uStack_1220;
  undefined4 uStack_121c;
  undefined4 uStack_1218;
  undefined8 uStack_1210;
  undefined1 *puStack_1208;
  undefined8 uStack_1200;
  ulong uStack_11f8;
  undefined8 uStack_11f0;
  undefined8 uStack_11e8;
  undefined8 uStack_11e0;
  undefined1 auStack_11d8 [44];
  undefined4 uStack_11ac;
  int iStack_11a8;
  
  if ((param_4 == (undefined1 *)0x0 || param_5 == (undefined1 *)0x0) || param_3 == (undefined2 *)0x0
     ) {
    func_0x0374badc(&UNK_04b8b1a8,0x4f06,&UNK_04b8eb58);
  }
  func_0x02fe71e8(&uStack_1220);
  iVar2 = func_0x02686054(param_1);
  lVar4 = func_0x029ecd30();
  uVar1 = *(undefined4 *)(lVar4 + (long)iVar2 * 0x70);
  piVar5 = (int *)func_0x029f80a4();
  if (*piVar5 == 0) {
    puVar6 = (undefined4 *)func_0x029ed1b8();
    uStack_121c = *puVar6;
  }
  else {
    uStack_1210 = 0;
    puStack_1208 = (undefined1 *)0x0;
    uStack_1200 = 0;
    uStack_11f8 = 0;
    uVar3 = func_0x032594ac((long)&uStack_1210 + 4,1);
    uStack_1210 = CONCAT44(uStack_1210._4_4_,uVar3);
    uStack_11f8 = uStack_11f8 & 0xffffffffffff0000;
    uStack_1200 = CONCAT44(1,uVar1);
    appfw_35a988c(&uStack_1210,auStack_11d8);
    uStack_121c = uStack_11ac;
    if (iStack_11a8 != 0) {
      func_0x038258d4(&UNK_04b8904f,uVar1,iStack_11a8,0x4f2e);
      lVar4 = func_0x02a07874();
      *param_3 = (short)*(undefined4 *)(lVar4 + 0x10);
      lVar4 = func_0x02a0789c();
      *param_4 = (char)*(undefined4 *)(lVar4 + 0x10);
      lVar4 = func_0x02a078c4();
      *param_5 = (char)*(undefined4 *)(lVar4 + 0x10);
      func_0x02fe6ec4(&uStack_1220);
      return;
    }
  }
  func_0x02fe6ec4(&uStack_1220);
  uStack_1200 = 0;
  uStack_11f8 = 0;
  uStack_1210 = 0xffffffff;
  uStack_11f0 = 0;
  uStack_11e8 = 0;
  uStack_11e0 = 0;
  uStack_1220 = uVar1;
  uStack_1218 = param_2;
  puStack_1208 = auStack_11d8;
  func_0x036a94cc(&uStack_1220,&uStack_1210);
  if ((int)uStack_1200 == 0) {
    *param_3 = *(undefined2 *)(puStack_1208 + 0x28);
    *param_4 = puStack_1208[0x2a];
    *param_5 = puStack_1208[0x2b];
  }
  else {
    *param_3 = 0x7e5;
    *param_4 = 1;
    *param_5 = 1;
    func_0x038258d4(&UNK_04b8ac84,uStack_1220,uStack_1218,0x4f4a);
  }
  return;
}

