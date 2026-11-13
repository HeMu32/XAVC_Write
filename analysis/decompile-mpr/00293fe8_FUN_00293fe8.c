// FUN_00293fe8
// Ghidra address: 00293fe8

int FUN_00293fe8(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 local_18;
  undefined4 local_10;
  char local_c;
  int local_8;
  
  uVar4 = XML_ParserCreate(0);
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  XML_SetUserData(uVar4,param_1);
  XML_SetElementHandler(*(undefined8 *)(param_1 + 0x10),PTR_LAB_00402320,PTR_LAB_00401708);
  do {
    FUN_00291228(&local_18,param_2);
    cVar1 = local_c;
    iVar2 = local_8;
    if (local_8 != 0) goto LAB_002940b0;
    iVar2 = XML_Parse(*(undefined8 *)(param_1 + 0x10),local_18,local_10,local_c);
    if (iVar2 == 0) {
      uVar3 = XML_GetErrorCode(*(undefined8 *)(param_1 + 0x10));
      FUN_00290aa4(4,"xavcIfo_MediaProfileParserImplXmlReaderBase.cpp",0x29,uVar3);
      XML_ParserFree(*(undefined8 *)(param_1 + 0x10));
      return 0xe;
    }
  } while (cVar1 == '\0');
  iVar2 = 0;
LAB_002940b0:
  XML_ParserFree(*(undefined8 *)(param_1 + 0x10));
  return iVar2;
}

