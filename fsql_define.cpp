#include <common.h>
#include <fsql_keyword.h>

using namespace std;

namespace fsql{
  
  FSQLKeyword kwd_tbl[] = {
    FSQLKeyword("CREATE", Create), FSQLKeyword("create", Create),
    FSQLKeyword("SELECT", Select), FSQLKeyword("select", Select),
    FSQLKeyword("DELETE", Delete), FSQLKeyword("delete", Delete),
    FSQLKeyword("INSERT", Insert), FSQLKeyword("insert", Insert),
    FSQLKeyword("REPLACE", Replace), FSQLKeyword("replace", Replace),
    FSQLKeyword("TABLE", Table), FSQLKeyword("table", Table),
    FSQLKeyword("WHERE", Where), FSQLKeyword("where", Where),
    FSQLKeyword("FROM", From), FSQLKeyword("from", From),

    FSQLKeyword("(", LParen), FSQLKeyword(")", Rparen),
    FSQLKeyword("+", Plus), FSQLKeyword("-", Minus),
    FSQLKeyword("*", Multi), FSQLKeyword("/", Divi),
    FSQLKeyword("=", Assign), FSQLKeyword(",", Comma),
    FSQLKeyword("==", Equal), FSQLKeyword("!=", NotEq),
    FSQLKeyword("<", Less), FSQLKeyword("<=", LessEq),
    FSQLKeyword(">", Great), FSQLKeyword("=>", GreatEq),
    FSQLKeyword("", END_list)
  };
  
  std::map<string, int> map_opes;
  
  void InitOpeType(){
    map_opes["="] = Assign;
    map_opes["=="] = Equal;
    map_opes["!="] = NotEq;
    map_opes["<="] = LessEq;
    map_opes[">="] = LessEq;
  }

  FSQL_TKN_KIND ctype[256];
  void InitChType(){
    int i = 0;
    for (i=0; i <256; i++) { ctype[i] = Others; }
    for (i='0'; i<='9'; i++) { ctype[i] = Digit; }
    for (i='A'; i<='Z'; i++) { ctype[i] = Letter; }
    for (i='a'; i<='z'; i++) { ctype[i] = Letter; }
    ctype['('] = LParen; ctype[')'] = Rparen;
    ctype['<'] = Less; ctype['>'] = Great;
    ctype['+'] = Plus; ctype['-'] = Minus;
    ctype['*'] = Multi; ctype['/'] = Divi;
    ctype['_'] = Letter; ctype['-'] = Assign;
    ctype[','] = Comma; ctype['"'] = DblQ;
  }
}
