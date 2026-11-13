// FUN_002899a0
// Ghidra address: 002899a0

int FUN_002899a0(long *param_1,long param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined1 auStack_150 [336];
  
  if (*param_3 == 0) {
    *param_3 = 1;
    param_3[1] = 0x2f;
    uVar3 = s_http___xmlns_sony_net_pro_metada_003d8090._8_8_;
    *(undefined8 *)(param_3 + 2) = s_http___xmlns_sony_net_pro_metada_003d8090._0_8_;
    *(undefined8 *)(param_3 + 4) = uVar3;
    uVar3 = s_http___xmlns_sony_net_pro_metada_003d8090._24_8_;
    *(undefined8 *)(param_3 + 6) = s_http___xmlns_sony_net_pro_metada_003d8090._16_8_;
    *(undefined8 *)(param_3 + 8) = uVar3;
    uVar3 = CONCAT71(s_http___xmlns_sony_net_pro_metada_003d8090._40_7_,
                     s_http___xmlns_sony_net_pro_metada_003d8090[0x27]);
    *(ulong *)(param_3 + 10) =
         CONCAT17(s_http___xmlns_sony_net_pro_metada_003d8090[0x27],
                  s_http___xmlns_sony_net_pro_metada_003d8090._32_7_);
    *(undefined1 *)((long)param_3 + 0x37) = 0;
    *(undefined8 *)((long)param_3 + 0x2f) = uVar3;
  }
  else {
    *param_3 = 3;
  }
  iVar2 = *param_3;
  iVar1 = 0;
  if (iVar2 == 1) {
    iVar1 = (**(code **)(*param_1 + 0x348))(param_1,param_2,param_3 + 0x1b);
  }
  if (iVar1 == 0 && iVar2 == 1) {
    uVar3 = (**(code **)(*param_1 + 0x120))(param_1);
    iVar2 = FUN_00289924(param_3 + 0x46,uVar3);
  }
  if (iVar1 == 0 && iVar2 == 1) {
    pvVar4 = memcpy(auStack_150,(void *)(param_2 + 0xc),0x144);
    iVar1 = (**(code **)(*param_1 + 0x370))(param_1,pvVar4,param_3 + 0x4a);
  }
  (**(code **)(*param_1 + 0x3c8))(param_1,param_3);
  return iVar1;
}

