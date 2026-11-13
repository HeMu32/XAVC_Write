// Normalized static image, not an observed export trace.
// Preferred VA 1801c4360
// Disassembly returned true; body bytes 99

ulonglong loaded_1801c4360(undefined8 param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong *plStackX_18;
  longlong **pplStackX_20;
  
  pplStackX_20 = &plStackX_18;
  plStackX_18 = (longlong *)*param_2;
  if (plStackX_18 != (longlong *)0x0) {
    (**(code **)(*plStackX_18 + 8))();
  }
  uVar1 = loaded_1801bf1a0(param_1,&plStackX_18,1);
  if ((longlong *)*param_2 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_2 + 0x10))();
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}

