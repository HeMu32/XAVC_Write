// ELF VMA 0x3596604; Ghidra bias 0x100000

/* WARNING: Possible PIC construction at 0x03696624: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x03696628) */

void appfw_3596604(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                  long param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                  undefined8 param_13,undefined8 param_14,undefined8 param_15,undefined8 param_16)

{
  undefined4 uVar1;
  undefined1 *puStack_220;
  undefined1 *puStack_218;
  undefined1 *puStack_210;
  undefined8 uStack_208;
  undefined1 *puStack_200;
  undefined1 *puStack_1f8;
  undefined1 *puStack_1f0;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined1 auStack_1e0 [256];
  undefined8 uStack_e0;
  undefined8 uStack_d0;
  undefined8 uStack_c0;
  undefined8 uStack_b0;
  undefined8 uStack_a0;
  undefined8 uStack_90;
  undefined8 uStack_80;
  undefined8 uStack_70;
  undefined1 auStack_60 [8];
  ulong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uStack_58 = (ulong)*(uint *)(param_9 + 0x90);
  if (*(uint *)(param_9 + 0x90) != 0) {
    puStack_220 = &stack0xffffffffffffffe0;
    puStack_210 = auStack_60;
    uStack_1e8 = 0xffffffc8;
    uStack_1e4 = 0xffffff80;
    uStack_208 = 0xffffff80ffffffc8;
    puStack_218 = puStack_220;
    puStack_200 = puStack_220;
    puStack_1f8 = puStack_220;
    puStack_1f0 = puStack_210;
    uStack_e0 = param_1;
    uStack_d0 = param_2;
    uStack_c0 = param_3;
    uStack_b0 = param_4;
    uStack_a0 = param_5;
    uStack_90 = param_6;
    uStack_80 = param_7;
    uStack_70 = param_8;
    uStack_50 = param_11;
    uStack_48 = param_12;
    uStack_40 = param_13;
    uStack_38 = param_14;
    uStack_30 = param_15;
    uStack_28 = param_16;
    func_0x018158c0(auStack_1e0,0x100,&UNK_04cf73ad,&puStack_220);
    uVar1 = func_0x01816770(auStack_1e0);
    func_0x03824f4c(2,auStack_1e0,uVar1);
    return;
  }
  return;
}

