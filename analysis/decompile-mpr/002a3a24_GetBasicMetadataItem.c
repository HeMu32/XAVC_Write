// mpr::RTMetadatSmplDatParser::GetBasicMetadataItem
// Ghidra address: 002a3a24

/* mpr::RTMetadatSmplDatParser::GetBasicMetadataItem(unsigned short, unsigned short, bool*, unsigned
   char*) */

undefined8 __thiscall
mpr::RTMetadatSmplDatParser::GetBasicMetadataItem
          (RTMetadatSmplDatParser *this,ushort param_1,ushort param_2,bool *param_3,uchar *param_4)

{
  uint uVar1;
  bool bVar2;
  ushort uVar3;
  bool bVar4;
  undefined1 *puVar5;
  
  puVar5 = *(undefined1 **)(this + 0x18);
  do {
    if ((undefined1 *)(*(long *)(this + 8) + (ulong)*(ushort *)(this + 0x10)) <= puVar5) {
      bVar2 = false;
LAB_002a3a94:
      *param_3 = bVar2;
      return 0;
    }
    uVar3 = CONCAT11(puVar5[2],puVar5[3]);
    uVar1 = (uint)uVar3;
    bVar4 = CONCAT11(*puVar5,puVar5[1]) == param_1;
    bVar2 = bVar4 && param_2 == uVar1;
    if (bVar4 && param_2 == uVar1) {
      memcpy(param_4,puVar5 + 4,(ulong)uVar3);
      goto LAB_002a3a94;
    }
    puVar5 = puVar5 + (int)(uVar1 + 4);
  } while( true );
}

