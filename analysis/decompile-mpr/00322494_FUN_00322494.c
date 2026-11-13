// FUN_00322494
// Ghidra address: 00322494

int FUN_00322494(void *param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 *local_8;
  
  iVar2 = -0x400;
  if ((param_2 < 0xfe1 && param_2 != 0) && param_1 != (void *)0x0) {
    iVar2 = osal_valloc_msg_wait(0x8f013a,&local_8,param_2 + 0x20,0);
    puVar1 = local_8;
    if (iVar2 == 0) {
      *local_8 = 2;
      *(undefined4 *)(local_8 + 2) = 0;
      *(int *)(local_8 + 4) = param_2;
      local_8[1] = 0x3c;
      FUN_003221e8(local_8 + 8);
      memcpy(puVar1 + 0xc,param_1,(long)param_2);
      osal_set_msg_src(local_8,0x8f013a);
      iVar2 = osal_snd_msg(0x8f013a,local_8);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar3 = osal_valloc_msg_wait(0x8f0313,&local_8,0x20,0);
    if (iVar3 == 0) {
      *local_8 = 0xf;
      *(undefined4 *)(local_8 + 2) = 0;
      *(undefined4 *)(local_8 + 4) = 0;
      local_8[1] = 0x3c;
      FUN_003221e8();
      osal_set_msg_src(local_8,0x8f013a);
      osal_snd_sync_msg(0x8f0313,local_8);
      osal_free_msg(0x8f0313,local_8);
    }
  }
  return iVar2;
}

