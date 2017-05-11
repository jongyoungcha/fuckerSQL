#ifndef _FSQL_H_
#define _FSQL_H_

#include <common.h>
#include <jyc_log.h>
#include <fsql_define.h>
#include <fsql_token.h>
/* #include <fsql_keyword.h> */

using namespace std;
using namespace fsql;

namespace fsql{
  class FSQL{
  protected:
    FILE* file;
    vector<string> vec_lines;

    FSQL_TKN_KIND GetTokenKind(string token_txt);
 
    int OpenNReadSQLFile(const char* path, string* file_contents);

    int IsOpe2(char c1, char c2);

    FSQLToken* NextToken(const char** pos);

  public:
    FSQL();
    ~FSQL();
    int StartSQL(int argc, char* argv[]);
  };
}



#endif































