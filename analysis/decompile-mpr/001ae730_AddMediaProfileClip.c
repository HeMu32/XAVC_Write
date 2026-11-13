// mpr::AddMediaProfileClip
// Ghidra address: 001ae730

/* mpr::AddMediaProfileClip(unsigned int, unsigned int, std::__cxx11::string, std::__cxx11::string)
    */

void mpr::AddMediaProfileClip(undefined4 param_1,undefined4 param_2,string *param_3,string *param_4)

{
  string *__dest;
  istream *piVar1;
  char *__dest_00;
  uint uVar2;
  undefined2 local_8f6;
  undefined4 local_8f4;
  long local_8f0;
  long lStack_8e8;
  undefined8 local_8e0;
  char *local_8d8 [4];
  string asStack_8b8 [32];
  undefined1 *local_898;
  undefined8 uStack_890;
  undefined1 local_888 [16];
  istream aiStack_878 [392];
  string asStack_6f0 [128];
  char acStack_670 [280];
  uint local_558;
  char acStack_554 [720];
  uint local_284;
  string asStack_280 [640];
  
  local_8f6 = 0;
  std::__cxx11::string::string(asStack_6f0,param_3);
  FUN_001ae1ac(asStack_6f0,&local_8f6);
  std::__cxx11::string::_M_dispose();
  local_8f4 = 0xffffffff;
  FUN_0028223c(param_1,local_8f6,&local_8f4);
  memset(asStack_6f0,0,0x6f0);
  FUN_00281f48(param_1,local_8f4,asStack_6f0);
  memset(asStack_6f0,0,0x80);
  FUN_001aa364((string *)local_8d8,&DAT_003d7eaf);
  std::__cxx11::string::string(asStack_8b8,param_4);
  local_8f0 = 0;
  lStack_8e8 = 0;
  local_8e0 = 0;
  std::__cxx11::stringstream::stringstream((stringstream *)aiStack_878,asStack_8b8,0x18);
  local_888[0] = 0;
  local_898 = local_888;
  uStack_890 = 0;
  while (piVar1 = std::getline<char,std::char_traits<char>,std::allocator<char>>
                            (aiStack_878,(string *)&local_898,'/'),
        (*(uint *)(piVar1 + *(long *)(*(long *)piVar1 + -0x18) + 0x20) & 5) == 0) {
    FUN_0019ddf0(&local_8f0,(string *)&local_898);
  }
  uVar2 = 0;
  FUN_001ac14c(&local_8f0,(lStack_8e8 - local_8f0 >> 5) + -1);
  std::__cxx11::string::_M_assign((string *)local_8d8);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::stringstream::~stringstream((stringstream *)aiStack_878);
  FUN_0019dce4(&local_8f0);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::substr((ulong)local_8d8,0);
  strncpy((char *)asStack_6f0,local_8d8[0],0x7f);
  memset(acStack_670,0,0x89);
  std::__cxx11::string::insert((ulong)local_8d8,(char *)0x0);
  __dest_00 = acStack_554;
  strncpy(acStack_670,local_8d8[0],0x88);
  do {
    if (local_558 <= uVar2) {
      for (uVar2 = 0; uVar2 < local_284; uVar2 = uVar2 + 1) {
        __dest = asStack_6f0 + (ulong)uVar2 * 0x11c + 0x470;
        memset(__dest,0,0x89);
        FUN_001aa364(aiStack_878,local_898);
        std::__cxx11::string::operator=((string *)local_8d8,(string *)aiStack_878);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::insert((ulong)local_8d8,(char *)0x0);
        std::__cxx11::string::append((char *)local_8d8);
        strncpy((char *)__dest,local_8d8[0],0x88);
      }
      FUN_002819f8(param_2,asStack_6f0);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      return;
    }
    memset(__dest_00,0,0x89);
    FUN_001aa364(aiStack_878,local_898);
    std::__cxx11::string::operator=((string *)local_8d8,(string *)aiStack_878);
    std::__cxx11::string::_M_dispose();
    if (*(int *)(__dest_00 + 0x8c) == 1) {
      std::__cxx11::string::insert((ulong)local_8d8,(char *)0x0);
LAB_001aea0c:
      std::__cxx11::string::append((char *)local_8d8);
      strncpy(__dest_00,local_8d8[0],0x88);
    }
    else if (*(int *)(__dest_00 + 0x8c) == 5) {
      std::__cxx11::string::insert((ulong)local_8d8,(char *)0x0);
      goto LAB_001aea0c;
    }
    uVar2 = uVar2 + 1;
    __dest_00 = __dest_00 + 0x90;
  } while( true );
}

