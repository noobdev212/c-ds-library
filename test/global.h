#ifndef CDS_GLOBAL_H
#define CDS_GLOBAL_H

#include <stdio.h>
#include <assert.h>
#include <locale.h>

#define AND &&
#define OR ||

// check ndebu if unit test is in use
#ifdef CDS_UNIT_TEST
  #ifdef NDEBUG
    #undef NDEBUG
  #endif
#endif

#define CDS_UTEST_SETUP \
  setlocale(LC_ALL, ""); \
  wchar_t message[] = L"ArrayList: Successful Test Case \u263A"; \
  int test_value_1 = 1; \
  int test_value_2 = 3; \
  unsigned int count; \
  void *ret, *ret_1; // to be used for return values

#endif
