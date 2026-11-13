// ELF VMA 0x36077b0; Ghidra bias 0x100000

void appfw_36077b0(undefined8 param_1,undefined8 param_2,ulong param_3)

{
                    /* WARNING: Could not recover jumptable at 0x037077d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((long)(char)(&UNK_04d1c9ec)[param_3 & 0xffffffff] * 4 + 0x37077d8))();
  return;
}

