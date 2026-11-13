// FUN_00214894
// Ghidra address: 00214894

int FUN_00214894(XavcsMovieReader *param_1,undefined1 param_2,TransferParams *param_3,int *param_4,
                undefined1 *param_5,char *param_6)

{
  VideoSampleInfo *pVVar1;
  AudioSampleInfo *pAVar2;
  TransferParams TVar3;
  int iVar4;
  uchar *__ptr;
  BaseList *pBVar5;
  uint uVar6;
  uint uStack_c;
  MoviePresentationInfo *local_8;
  
  iVar4 = mpr::BaseList::GetNum(*(BaseList **)(param_1 + 0x1d18));
  if (iVar4 == 0) {
    *param_6 = '\0';
    iVar4 = 0;
  }
  else {
    mpr::BaseList::Get(*(BaseList **)(param_1 + 0x1d18),0,&local_8,&uStack_c);
    pVVar1 = (VideoSampleInfo *)(local_8 + 0xa0);
    pAVar2 = (AudioSampleInfo *)(local_8 + 0xb8);
    if (local_8[0x91] == (MoviePresentationInfo)0x0) {
      *param_5 = 1;
    }
    TVar3 = (TransferParams)FUN_0020c3a0(param_1,pVVar1,pAVar2);
    param_3[0x20] = TVar3;
    iVar4 = 0;
    *param_4 = *(int *)(local_8 + 0xa8);
    for (uVar6 = 0; uVar6 < (byte)local_8[0x9f]; uVar6 = uVar6 + 1 & 0xff) {
      *param_4 = *param_4 + *(int *)(pAVar2 + (ulong)uVar6 * 0x18 + 8);
      iVar4 = iVar4 + *(int *)(pAVar2 + (ulong)uVar6 * 0x18 + 4);
    }
    *param_4 = *param_4 + *(int *)(local_8 + 0x120);
    *(undefined4 *)param_3 = *(undefined4 *)(local_8 + 0xa8);
    param_1[0x4a8] = (XavcsMovieReader)(*(int *)(param_1 + 0x430) == 0 && iVar4 != 0);
    *(uint *)(param_1 + 0x4ac) = (uint)(byte)local_8[0x9f];
    uVar6 = **(uint **)(local_8 + 0x128);
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(undefined4 *)(param_3 + 0x10) = 0;
    __ptr = malloc((ulong)uVar6);
    iVar4 = XavcsMovieReader::GetMetaSampleData
                      (param_1,*(BaseList **)(param_1 + 0x1db0),uVar6,__ptr);
    if (iVar4 == 0) {
      iVar4 = FUN_00214690(param_1,local_8,pVVar1,pAVar2,(MetadataSampleInfo *)(local_8 + 0x118),
                           __ptr,param_2,*param_5,param_3 + 0xc,param_3 + 0x10,param_6,
                           *(undefined8 *)(param_3 + 0x28));
    }
    free(__ptr);
    if ((iVar4 == 0) && (*param_6 != '\0')) {
      pBVar5 = *(BaseList **)(param_1 + 0x1db0);
      *(undefined4 *)(param_3 + 4) = 0;
      *(undefined4 *)(param_3 + 8) = 0;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined4 *)(param_3 + 0x18) = 0;
      *(undefined4 *)(param_3 + 0x1c) = 0;
      uVar6 = mpr::BaseList::GetNum(pBVar5);
      pBVar5 = operator_new(0x20);
      mpr::BaseList::BaseList(pBVar5,uVar6);
      mpr::BaseList::CopyTo(*(BaseList **)(param_1 + 0x1db0),pBVar5);
      iVar4 = XavcsMovieReader::MakeInfoList
                        (param_1,local_8,pVVar1,pAVar2,(MetadataSampleInfo *)(local_8 + 0x118),
                         pBVar5,param_3);
      (**(code **)(*(long *)pBVar5 + 8))(pBVar5);
    }
  }
  return iVar4;
}

