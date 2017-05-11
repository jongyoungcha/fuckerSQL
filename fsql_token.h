#ifndef _FSQL_TOKEN_H_
#define _FSQL_TOKEN_H_

#include <common.h>
#include <fsql_define.h>

using namespace std;

namespace fsql{
  class FSQLToken{
  public:
    FSQLToken(FSQL_TKN_KIND kind, string text, int = -1);

    ~FSQLToken();

    string GetText();

    FSQL_TKN_KIND GetKind();

    int GetInt();

  protected:
    FSQL_TKN_KIND kind;
    string text;
    int int_val;

  };
}


#endif
