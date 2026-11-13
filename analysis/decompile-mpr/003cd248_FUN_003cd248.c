// FUN_003cd248
// Ghidra address: 003cd248

undefined1  [16] FUN_003cd248(short *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  
  uVar2 = (uint)(char)param_1[1];
  uVar1 = (uint)*param_1;
  if ((char)param_1[1] < '\x03') {
    uVar1 = uVar1 - 1;
    uVar2 = uVar2 + 0xc;
  }
  auVar3._0_8_ = ((double)(int)*(char *)((long)param_1 + 3) +
                  (double)(long)((double)uVar1 * DAT_003e9cb8) +
                  (double)(long)(((double)uVar2 + 1.0) * DAT_003e9cc0) +
                  (double)(int)(char)param_1[2] / 24.0 + DAT_003e9cc8 +
                 (double)(int)((2 - uVar1 / 100) + ((int)(uVar1 / 100) >> 2))) - DAT_003e9cd0;
  auVar3._8_8_ = 0;
  return auVar3;
}

