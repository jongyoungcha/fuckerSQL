#include <fsql_token.h>

using namespace std;
using namespace fsql;

FSQLToken::FSQLToken(FSQL_TKN_KIND kind, string text, int int_val){
  this->kind = kind;
  this->text = text;
  this->int_val = int_val;
}


FSQLToken::~FSQLToken(){}

string FSQLToken::GetText(){
  return this->text;
}


FSQL_TKN_KIND FSQLToken::GetKind(){
  return this->kind;
}

int FSQLToken::GetInt(){
  return this->int_val;
}

