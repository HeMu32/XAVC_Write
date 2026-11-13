// FUN_0032a380
// Ghidra address: 0032a380

undefined8
FUN_0032a380(long *param_1,long param_2,int param_3,undefined8 *param_4,undefined8 param_5)

{
  long *plVar1;
  undefined8 uVar2;
  void *pvVar3;
  long lVar4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  param_1[0x14] = param_2;
  if ((long *)*param_1 != (long *)0x0) {
    (**(code **)(*(long *)*param_1 + 8))();
    *param_1 = 0;
  }
  if (param_4 == (undefined8 *)0x0) {
    *param_1 = 0;
  }
  else {
    pvVar3 = operator_new(0x38);
    FUN_0032b404(pvVar3,*param_4,param_4[1]);
    *param_1 = (long)pvVar3;
  }
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  FUN_00323748(param_1,*param_1,&local_70);
  if (param_3 == 0) {
    local_78 = 0;
    uVar2 = 0;
    local_98 = 0;
    local_90 = 0;
    local_88 = 0;
    uStack_80 = 0;
    if (param_4 != (undefined8 *)0x0) {
      uVar2 = param_4[1];
    }
    uVar2 = FUN_003237e8(param_1,(int)param_1[1],uVar2,&local_98);
    if ((int)uVar2 == 0) {
      FUN_002c73ac(&local_70,param_1 + 0x15);
      FUN_002d2ed0(param_1[0x15],&local_98,param_1 + 0x16);
      uVar2 = FUN_00323828(param_1,param_1[0x16],(int)param_1[1]);
      if ((((int)uVar2 == 0) &&
          (uVar2 = FUN_00325fc4(param_1,param_1[0x16],(int)param_1[7]), (int)uVar2 == 0)) &&
         (uVar2 = FUN_003238f4(param_1,param_1[0x16],(int)param_1[1]), (int)uVar2 == 0)) {
        plVar1 = param_1 + 3;
        local_c0 = 0;
        local_bc = 0;
        uVar2 = FUN_00326108(param_1,param_1[0x16],(int)param_1[1],plVar1,&local_bc,param_1 + 0x17,
                             &local_c0);
        if ((int)uVar2 == 0) {
          if ((char)param_1[0xf] != '\0') {
            FUN_002d41f4(param_1[0x16],param_1[0x10]);
            uVar2 = FUN_00322428();
            if ((int)uVar2 != 0) {
              return uVar2;
            }
          }
          local_b0 = 0;
          uStack_a8 = 0;
          local_b8 = 0;
          local_a0 = 0;
          uVar2 = FUN_00324550(param_1,param_1[0x16],plVar1,&local_b8,&local_b0,(long)param_1 + 0xc4
                               ,param_1 + 0x1b);
          if ((int)uVar2 == 0) {
            local_b4 = 0;
            uVar2 = FUN_00326260(param_1,param_1[0x16],plVar1,local_bc,&local_b4,param_1 + 0x1e,
                                 (long)param_1 + 0xf4);
            if (((int)uVar2 == 0) &&
               (uVar2 = FUN_00323ff4(param_1,param_1[0x16],(int)param_1[1],param_5), (int)uVar2 == 0
               )) {
              uVar2 = FUN_00324440(param_1,param_1[0x16],plVar1,(int)param_1[0x17],local_c0,
                                   (long)param_1 + 0xbc);
            }
          }
        }
      }
    }
  }
  else if (param_3 == 1) {
    local_88 = 0;
    local_98 = 0x400000;
    local_90 = 0x43;
    FUN_002c73ac(&local_70,param_1 + 0x15);
    FUN_002c7a34(param_1[0x15],param_1[0x14],&local_98,param_1 + 0x21,&local_b0);
    uVar2 = FUN_00324818(param_1,param_1[0x21],param_1 + 0x22);
    if ((int)uVar2 == 0) {
      local_c0 = local_c0 & 0xffffff00;
      local_bc = local_bc & 0xffffff00;
      local_b8 = local_b8 & 0xffffff00;
      uVar2 = FUN_00324950(param_1,param_1[0x21],&local_b8,&local_c0,&local_bc);
      if ((int)uVar2 == 0) {
        FUN_002c8a04(param_1[0x21],param_1 + 0x2f);
        uVar2 = FUN_00322428();
        if ((int)uVar2 == 0) {
          pvVar3 = operator_new(0x30);
          *(undefined8 *)((long)pvVar3 + 0x10) = 0;
          *(long *)((long)pvVar3 + 0x18) = (long)pvVar3 + 8;
          *(long *)((long)pvVar3 + 0x20) = (long)pvVar3 + 8;
          *(undefined8 *)((long)pvVar3 + 0x28) = 0;
          lVar4 = param_1[0x21];
          *(undefined4 *)((long)pvVar3 + 8) = 0;
          param_1[0x4f] = (long)pvVar3;
          uVar2 = FUN_003299ec(param_1,lVar4,param_1 + 0x39,param_1 + 0x50,param_1 + 0x56);
          if ((int)uVar2 == 0) {
            local_b4 = local_b4 & 0xffffff00;
            uVar2 = FUN_00326618(param_1,param_1[0x21],(int)param_1[0x39],&local_b4,
                                 (long)param_1 + 0x1dc,param_1 + 0x3c);
            if ((int)uVar2 == 0) {
              uVar2 = FUN_00322e44(param_1,param_1[0x21],*(undefined4 *)((long)param_1 + 0x284),
                                   &local_b4,(long)param_1 + 0x2a4);
            }
          }
        }
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

