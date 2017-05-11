#ifndef _FSQL_KEYWORD_H_
#define _FSQL_KEYWORD_H_

#include <common.h>

using namespace std;

namespace fsql{
  typedef enum fsql_tkn_kind{
    LParen=1, Rparen, Plus, Minus, Multi,
    Divi, Assign, Comma, DblQ, Equal,
    NotEq, Less, LessEq, Great, GreatEq,
    If, Else, End, Print, Ident,
    IntNum, String, Letter, Digit, EofTkn,
    Others,
    Create, Select, Delete, Insert, Replace,
    Table, Where, From, 
    END_list
  } FSQL_TKN_KIND;

  class FSQLKeyword{
  protected:
    string kwd_name;
    FSQL_TKN_KIND key_kind;
  public:
    FSQLKeyword(const string kwd_name, FSQL_TKN_KIND key_kind);
    ~FSQLKeyword();
    FSQL_TKN_KIND GetKind();
    string GetName();
  };
}


#endif

