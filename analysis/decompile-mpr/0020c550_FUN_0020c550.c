// FUN_0020c550
// Ghidra address: 0020c550

long FUN_0020c550(long param_1,uchar *param_2,uint *param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  long lVar5;
  long lVar6;
  bool local_2b;
  bool local_2a;
  bool local_29;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  uint local_18 [2];
  undefined8 local_10;
  uchar local_8 [4];
  undefined4 local_4;
  
  memset((void *)(*(long *)(param_1 + 0x1d40) + (ulong)*param_3 * 0x500),0,0x500);
  *(undefined1 *)(*(long *)(param_1 + 0x1d40) + (ulong)*param_3 * 0x500) = 8;
  iVar3 = mpr::RTMetadatSmplDatParser::TransitToQueryMode
                    (*(RTMetadatSmplDatParser **)(param_1 + 0xe8),param_2);
  if (iVar3 == 0) {
    local_2b = false;
    local_2a = false;
    local_28[0] = 0;
    local_20[0] = 0;
    iVar3 = mpr::RTMetadatSmplDatParser::GetBasicMetadataItem
                      (*(RTMetadatSmplDatParser **)(param_1 + 0xe8),0xf001,0x10,&local_29,
                       (uchar *)&local_10);
    if (iVar3 != 0) {
      local_29 = false;
    }
    if (local_29 != false) {
      local_18[0] = 1;
      iVar3 = mpr::TCUBConv::TransitExtTCUBToBasicTCUBMode
                        (*(TCUBConv **)(param_1 + 0xf0),(ExtTCUBToBasicTCUBModeParam *)local_18);
      if ((iVar3 == 0) &&
         (iVar3 = mpr::TCUBConv::ConvertExtTCUBToBasicTCUB
                            (*(TCUBConv **)(param_1 + 0xf0),(uchar *)&local_10,local_8,&local_2b,
                             (uchar *)local_28,&local_2a,(uchar *)local_20), iVar3 != 0)) {
        local_2b = false;
        local_2a = false;
      }
    }
    if (local_2b != false) {
      lVar5 = *(long *)(param_1 + 0x1d40);
      *(undefined1 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x10) = 1;
      *(undefined4 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x40) = local_28[0];
    }
    if (local_2a != false) {
      lVar5 = *(long *)(param_1 + 0x1d40);
      *(undefined1 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x11) = 1;
      *(undefined4 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x44) = local_20[0];
    }
    local_18[0] = local_18[0] & 0xffffff00;
    local_10 = 0;
    _local_8 = 0;
    iVar3 = mpr::RTMetadatSmplDatParser::GetMetadata
                      (*(RTMetadatSmplDatParser **)(param_1 + 0xe8),0,
                       (ExtTCUBToBasicTCUBModeParam *)local_18,&local_10);
    if (iVar3 != 0) {
      local_18[0] = local_18[0] & 0xffffff00;
    }
    if (local_18[0]._0_1_ != (ExtTCUBToBasicTCUBModeParam)0x0) {
      lVar5 = *(long *)(param_1 + 0x1d40);
      *(undefined1 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x12) = 1;
      lVar6 = lVar5 + (ulong)*param_3 * 0x500;
      bVar2 = *(byte *)(lVar6 + 0x48);
      *(byte *)(lVar6 + 0x48) = bVar2 & 0xc0 | bVar2 & 0x1f | ((byte)local_10 & 1) << 5;
      lVar6 = lVar5 + (ulong)*param_3 * 0x500;
      bVar2 = *(byte *)(lVar6 + 0x48);
      *(byte *)(lVar6 + 0x48) = bVar2 & 0x80 | bVar2 & 0x3f | ((byte)local_10 >> 1 & 1) << 6;
      lVar6 = lVar5 + (ulong)*param_3 * 0x500;
      *(byte *)(lVar6 + 0x48) = *(byte *)(lVar6 + 0x48) & 0x7f | ((byte)local_10 >> 2) << 7;
      lVar6 = lVar5 + (ulong)*param_3 * 0x500;
      *(byte *)(lVar6 + 0x49) = *(byte *)(lVar6 + 0x49) & 0x7f | local_10._1_1_ & 0x80;
      lVar6 = lVar5 + (ulong)*param_3 * 0x500;
      *(undefined2 *)(lVar6 + 0x4c) = local_10._4_2_;
      *(undefined2 *)(lVar6 + 0x4e) = local_10._6_2_;
      *(uchar *)(lVar6 + 0x50) = local_8[0];
      *(uchar *)(lVar5 + (ulong)*param_3 * 0x500 + 0x51) = local_8[1];
      *(uchar *)(lVar5 + (ulong)*param_3 * 0x500 + 0x52) = local_8[2];
      *(uchar *)(lVar5 + (ulong)*param_3 * 0x500 + 0x53) = local_8[3];
      *(undefined4 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x54) = local_4;
    }
    local_10 = local_10 & 0xffffffffffffff00;
    pvVar4 = operator_new(0x2f8);
    iVar3 = mpr::RTMetadatSmplDatParser::GetMetadata
                      (*(RTMetadatSmplDatParser **)(param_1 + 0xe8),1,&local_10,pvVar4);
    if ((iVar3 == 0) && ((byte)local_10 != '\0')) {
      memcpy((void *)(*(long *)(param_1 + 0x1d40) + (ulong)*param_3 * 0x500 + 0x60),pvVar4,0x2f8);
    }
    operator_delete(pvVar4,0x2f8);
    local_10 = local_10 & 0xffffffffffffff00;
    pvVar4 = operator_new(0xa8);
    iVar3 = mpr::RTMetadatSmplDatParser::GetMetadata
                      (*(RTMetadatSmplDatParser **)(param_1 + 0xe8),2,&local_10,pvVar4);
    if ((iVar3 == 0) && ((byte)local_10 != '\0')) {
      lVar5 = *(long *)(param_1 + 0x1d40);
      *(undefined1 *)(lVar5 + (ulong)*param_3 * 0x500 + 0x13) = 1;
      memcpy((void *)(lVar5 + (ulong)*param_3 * 0x500 + 0x400),pvVar4,0xa8);
    }
    operator_delete(pvVar4,0xa8);
  }
  uVar1 = *param_3;
  *param_3 = uVar1 + 1;
  return (ulong)(*(uint *)(param_1 + 0x1d48) < uVar1 + 1) << 1;
}

