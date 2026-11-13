// Ghidra: 00286448; ELF VMA = Ghidra - 0x100000

undefined8 FUN_00286448(long param_1)

{
  void *__s;
  void *__s_00;
  long lVar1;
  
  usleep(1);
  __s_00 = (void *)(param_1 + 0x28);
  do {
    __s = (void *)((long)__s_00 + 0x20000);
    memset(__s_00,0,0x20000);
    usleep(1);
    __s_00 = __s;
  } while (__s != (void *)(param_1 + 0xa0028));
  memset(__s,0,0x6000);
  *(undefined4 *)(param_1 + 0x28) = 1;
  usleep(1);
  memset((void *)(param_1 + 0xa6028),0,0x9c38);
  usleep(1);
  memset((void *)(param_1 + 0xb0850),0,0x7e4);
  usleep(1);
  memset((void *)(param_1 + 0xb1034),0,0x7e4);
  memset((void *)(param_1 + 0xb1818),0,0x4b8);
  memset((void *)(param_1 + 0xb1cd0),0,0xe994);
  *(undefined4 *)(param_1 + 0xc0664) = 0;
  lVar1 = 0;
  usleep(1);
  do {
    *(undefined1 *)(param_1 + lVar1 * 0x44 + 0x68) = 0;
    if ((uint)lVar1 % 999 == 0) {
      usleep(1);
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 9999);
  *(undefined4 *)(param_1 + 0xafc60) = 0;
  *(undefined4 *)(param_1 + 0xafc64) = 0;
  *(undefined4 *)(param_1 + 0xafc68) = 0;
  *(undefined4 *)(param_1 + 0xafc6c) = 0;
  *(undefined4 *)(param_1 + 0xafc70) = 0;
  FUN_0028643c(param_1 + 0xafc78);
  usleep(1);
  *(undefined1 *)(param_1 + 0xb0848) = 1;
  *(undefined1 *)(param_1 + 0xafc74) = 1;
  *(undefined1 *)(param_1 + 0xafc75) = 1;
  return 0;
}

