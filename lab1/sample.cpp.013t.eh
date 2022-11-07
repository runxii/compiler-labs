
;; Function main (main, funcdef_no=1731, decl_uid=44210, cgraph_uid=465, symbol_order=495)

int main ()
{
  struct basic_ostream & D.49118;
  int f;
  int n;
  int i;
  int D.49116;

  std::basic_istream<char>::operator>> (&cin, &n);
  i = 2;
  f = 1;
  goto <D.44270>;
  <D.44271>:
  f = f * i;
  i = i + 1;
  <D.44270>:
  n.0_1 = n;
  if (i <= n.0_1) goto <D.44271>; else goto <D.44269>;
  <D.44269>:
  D.49118 = std::basic_ostream<char>::operator<< (&cout, f);
  _2 = D.49118;
  std::basic_ostream<char>::operator<< (_2, endl);
  n = {CLOBBER};
  D.49116 = 0;
  goto <D.49117>;
  <D.49117>:
  return D.49116;
  <D.49119>:
  n = {CLOBBER};
  resx 1
}



;; Function __static_initialization_and_destruction_0 (_Z41__static_initialization_and_destruction_0ii, funcdef_no=2231, decl_uid=49108, cgraph_uid=965, symbol_order=1022)

void __static_initialization_and_destruction_0 (int __initialize_p, int __priority)
{
  if (__initialize_p == 1) goto <D.49121>; else goto <D.49122>;
  <D.49121>:
  if (__priority == 65535) goto <D.49123>; else goto <D.49124>;
  <D.49123>:
  std::ios_base::Init::Init (&__ioinit);
  __cxxabiv1::__cxa_atexit (__dt_comp , &__ioinit, &__dso_handle);
  goto <D.49125>;
  <D.49124>:
  <D.49125>:
  goto <D.49126>;
  <D.49122>:
  <D.49126>:
  return;
}



;; Function _GLOBAL__sub_I_main (_GLOBAL__sub_I_main, funcdef_no=2232, decl_uid=49114, cgraph_uid=966, symbol_order=1141)

void _GLOBAL__sub_I_main ()
{
  __static_initialization_and_destruction_0 (1, 65535);
  return;
}


