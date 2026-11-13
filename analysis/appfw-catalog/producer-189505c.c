// Original ELF VMA 0x189505c; Ghidra bias 0x100000; readOnly project session

/* WARNING: Removing unreachable block (ram,0x01955f78) */
/* WARNING: Removing unreachable block (ram,0x01955fe0) */

void producer_189505c(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  long lVar6;
  
  puVar5 = PTR_DAT_05b409e0;
  plVar1 = (long *)(param_1 + 0x3410);
  *(undefined8 *)(param_1 + 0x35f8) = *(undefined8 *)(param_1 + 0x1e0);
  *(undefined8 *)(param_1 + 0x3600) = *(undefined8 *)(param_1 + 0x1e8);
  lVar6 = (long)*(int *)(param_1 + 0xb20) * 0x10;
  *(undefined4 *)(param_1 + 0x3618) = 0;
  uVar4 = *(undefined4 *)(puVar5 + lVar6);
  uVar2 = *(undefined4 *)(puVar5 + lVar6 + 4);
  uVar3 = *(undefined4 *)(puVar5 + lVar6 + 8);
  *(undefined4 *)(param_1 + 0x3614) = *(undefined4 *)(puVar5 + lVar6 + 0xc);
  *(undefined4 *)(param_1 + 0x35f0) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(param_1 + 0x3608) = uVar4;
  *(undefined4 *)(param_1 + 0x360c) = uVar2;
  *(undefined4 *)(param_1 + 0x3610) = uVar3;
  *(undefined1 *)(param_1 + 0x361c) = 1;
  *(undefined1 *)(param_1 + 0x361d) = *(undefined1 *)(param_1 + 0x205);
  func_0x01956d44(param_1 + 0x3628);
  *(undefined4 *)(param_1 + 0x3620) = *(undefined4 *)(param_1 + 0x518);
  func_0x019afcf4(plVar1);
  if (*(long *)(param_1 + 0xb10) == 0) {
    *(undefined4 *)(param_1 + 0x3624) = *(undefined4 *)(param_1 + 0x820);
    func_0x018151a0(param_1 + 0x3628,param_1 + 0x824,0x2e8);
  }
  else {
    *(long *)(param_1 + 0x3910) = *(long *)(param_1 + 0xb10);
  }
  *(undefined1 *)(param_1 + 0x3919) = *(undefined1 *)(param_1 + 0xbf1);
  *(undefined1 *)(param_1 + 0x3918) = *(undefined1 *)(param_1 + 0xbf0);
  *(undefined4 *)(param_1 + 0x391c) = *(undefined4 *)(param_1 + 0xb70);
  *(undefined4 *)(param_1 + 0x3920) = *(undefined4 *)(param_1 + 0xb74);
  if (*(char *)(param_1 + 0x361c) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x019b02d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x30))(plVar1,3);
    return;
  }
  (**(code **)(*plVar1 + 0x30))(plVar1,0);
  func_0x019afe58(plVar1);
  func_0x019aff88(plVar1);
  func_0x019b007c(plVar1);
  func_0x019b01fc(plVar1);
  if (*(char *)(param_1 + 0x3918) == '\0') {
    return;
  }
  lVar6 = func_0x01816d80();
  if (lVar6 != 0) {
    return;
  }
  if (*(long *)(param_1 + 0x35d0) == 0) {
    func_0x0374badc(&UNK_038d4dc2,0x77,&UNK_038d4dd8);
  }
  (**(code **)(**(long **)(param_1 + 0x35d0) + 8))
            (*(long **)(param_1 + 0x35d0),&stack0xffffffffffffffd8);
  return;
}

