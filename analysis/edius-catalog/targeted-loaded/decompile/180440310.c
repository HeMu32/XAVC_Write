// Normalized static image, not an observed export trace.
// Preferred VA 180440310
// Disassembly returned true; body bytes 294

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void loaded_180440310(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStack_278 [32];
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined1 auStack_248 [16];
  undefined1 auStack_238 [272];
  undefined1 auStack_128 [272];
  ulonglong uStack_18;
  
  uStack_18 = _DAT_18092d280 ^ (ulonglong)auStack_278;
  uStack_258 = *param_1;
  uStack_250 = param_1[1];
  FUN_180431bd0(auStack_128,&uStack_258,1);
  uStack_258 = *param_2;
  uStack_250 = param_2[1];
  FUN_180431bd0(auStack_238,&uStack_258,1);
  puVar3 = (undefined8 *)FUN_180434550(auStack_238,auStack_248,0,0);
  uStack_258 = *puVar3;
  uStack_250 = func_0x000180591eea();
  iVar2 = FUN_18043bbe0(&uStack_258);
  if (-1 < iVar2) {
    puVar3 = (undefined8 *)FUN_180434110(auStack_238,auStack_248,1);
    uVar1 = *puVar3;
    puVar3 = (undefined8 *)FUN_180434110(auStack_128,&uStack_258,1);
    iVar2 = MoveFileW(*puVar3,uVar1);
    if (iVar2 == 0) {
      GetLastError();
    }
  }
  FUN_180432230(auStack_238);
  FUN_180432230(auStack_128);
  FUN_18058f0f0(uStack_18 ^ (ulonglong)auStack_278);
  return;
}

