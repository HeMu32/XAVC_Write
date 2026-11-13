// FUN_003cd954
// Ghidra address: 003cd954

void FUN_003cd954(undefined8 param_1,undefined1 *param_2)

{
  ulong uVar1;
  char cVar2;
  uint uVar3;
  double dVar4;
  undefined1 auStack_10 [4];
  char local_c;
  char local_b;
  char local_a;
  short local_8;
  
  FUN_003cd6c8(param_1,0,auStack_10);
  uVar1 = (((long)local_8 +
           (ulong)(uint)((int)local_a + ((int)local_b + local_c * 0xe10) * 0x3c) * 1000) *
          0xffffffff) / 0x15180;
  *param_2 = (char)uVar1;
  param_2[1] = (char)(uVar1 >> 8);
  param_2[2] = (char)(uVar1 >> 0x10);
  param_2[3] = (char)(uVar1 >> 0x18);
  dVar4 = (double)FUN_003cd248(auStack_10);
  uVar3 = (uint)dVar4;
  cVar2 = (char)(uVar3 / 10);
  param_2[4] = (char)uVar3 + cVar2 * -10 | (cVar2 + (char)((uVar3 / 10) / 10) * -10) * '\x10';
  param_2[5] = (char)(uVar3 / 100) + (char)((uVar3 / 100) / 10) * -10 |
               ((char)(uVar3 / 1000) + (char)((uVar3 / 1000) / 10) * -10) * '\x10';
  param_2[6] = (char)(uVar3 / 10000) + (char)((uVar3 / 10000) / 10) * -10 |
               ((char)(uVar3 / 100000) + (char)((uVar3 / 100000) / 10) * -10) * '\x10';
  return;
}

