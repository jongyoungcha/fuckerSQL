#ifndef _FSQL_DEFINE_H_
#define _FSQL_DEFINE_H_

#include <common.h>
#include <fsql_keyword.h>

using namespace std;

namespace fsql{
  extern FSQLKeyword kwd_tbl[];
  extern FSQL_TKN_KIND ctype[256];
  extern map<string, int> map_opes;
  extern void InitChType();
  extern void InitOpeType();
  extern int test_extern;
}

#endif
