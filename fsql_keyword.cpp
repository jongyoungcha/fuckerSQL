#include <fsql_keyword.h>

using namespace std;
using namespace fsql;

FSQLKeyword::FSQLKeyword(const string kwd_name, FSQL_TKN_KIND key_kind){
  this->kwd_name = kwd_name;
  this->key_kind = key_kind;
}

FSQLKeyword::~FSQLKeyword(){}


FSQL_TKN_KIND FSQLKeyword::GetKind(){
  return this->key_kind;
}


string FSQLKeyword::GetName(){
  return this->kwd_name;
}

