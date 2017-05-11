#include <fksql.h>
#include <fsql_define.h>

using namespace fsql;
using namespace std;

FSQL::FSQL(){
}

FSQL::~FSQL(){
}


int FSQL::StartSQL(int argc, char* argv[]){
  jyc_log_write(JYC_LOG_NORMAL, "Start fucker_sql");

  int ret = 0;
  string file_contents;
  const char* crnt_pos = NULL;
  FSQLToken* token = NULL;

  InitOpeType();
  InitChType();

  this->OpenNReadSQLFile(argv[1], &file_contents);

  crnt_pos = &(file_contents.c_str()[0]);

  for(token = NextToken(&crnt_pos); token->GetKind() != EofTkn; token = NextToken(&crnt_pos)){
    sleep(1);
    jyc_log_write(JYC_LOG_DEBUG, "%s, %u, %d\n", token->GetText().c_str(), token->GetKind(), token->GetInt());
    fprintf(stdout, "%s, %u, %d\n", token->GetText().c_str(), token->GetKind(), token->GetInt());
  }

  return ret;
}

FSQL_TKN_KIND FSQL::GetTokenKind(string token_txt){
  for (int i = 0; kwd_tbl[i].GetKind() != END_list; i++){
    if ((kwd_tbl[i].GetName().compare(token_txt) == 0))
      return kwd_tbl[i].GetKind();
  }

  if (fsql::ctype[token_txt[0]] == Letter) return Ident;
  if (fsql::ctype[token_txt[0]] == Digit) return IntNum;

  return Others;
}


int FSQL::OpenNReadSQLFile(const char* path, string* file_contents){
  int ret = 0;
  int n_line = 0;
  char buf[8192] = {0};

  printf("path : %s\n", path);
  if ((this->file = fopen(path, "r")) == NULL) {
    printf("file open ok\n");
    jyc_log_write(JYC_LOG_ERROR, "open_n_read_sql_file fopen() failed..");

    ret = -1;
    goto ret;
  }

  while(!feof(file)){
    n_line++;
    fgets(buf, 8192, file);
    printf("buf : %s", buf);
    *file_contents += buf;

    sleep(1);

    if (buf[strlen(buf)-1] != '\n'){
      jyc_log_write(JYC_LOG_ERROR, "%d line was longer than 8192");

      ret = -1;
      goto ret;
    }
  }
  rewind(file);

 ret:
  if (file)
    fclose(file);

  return ret;
}


int FSQL::IsOpe2(char c1, char c2){
  if (c1 == '\0' || c2 == '\0') return 0;
  char ope[3] = {c1, c2, '\0'};
  fprintf(stdout, "ope : %s\n", ope);
  map<string,int>::iterator it = fsql::map_opes.find(ope);
  if(it != fsql::map_opes.end()){
    return 1;
  }
  else{
    return 0;
  }
}


FSQLToken* FSQL::NextToken(const char** pos){
  FSQL_TKN_KIND tok_kind;
  int ch0 = 0, num = 0;
  static int ch = ' ';
  string token_txt = "";
  FSQLToken* tok_ret = NULL;

  printf("called next_token()\n");

  while(isspace(ch = **pos)){
    printf("%c\n", **pos);
    (*pos)++;
  }

  if(ch == NULL){
    return (new FSQLToken(EofTkn, token_txt));
  }  

  printf("next()\n");
  printf("current ch : %c\n", ch);

  switch(fsql::ctype[ch]){
  case Letter:
    fprintf(stdout, "Letter\n");
    for (int i=0; fsql::ctype[ch] == Letter || fsql::ctype[ch] == Digit; ch = *(++(*pos)), i++) {
      token_txt += ch;
    }
    break;

  case Digit:
    fprintf(stdout, "Digit\n");
    for (num = 0; fsql::ctype[ch] == Digit; ch=*(++(*pos))){
      // fprintf(stdout, "char in digit : %c\n", ch);
      num = num * 10 + (ch - '0');
    }

    tok_ret = new FSQLToken(IntNum, token_txt, num);
    return tok_ret;

  case DblQ:
    fprintf(stdout, "DblQ\n");
    for (int i=0, ch = *(++(*pos));
	 ch != EOF && ch != '\n' && ch != '"';
	 ch = *(++(*pos)), i++){
      token_txt += ch;
    }

    if (ch != '"') {
      jyc_log_write(JYC_LOG_ERROR, "double quotes were not closed.");
      exit(1);
    }

    tok_ret = new FSQLToken(String, token_txt);
    return tok_ret;

  default:
    fprintf(stdout, "Default\n");
    token_txt += ch;
    ch0 = ch;
    ch = *(++(*pos));

    fprintf(stdout, "ch0 : %c, ch : %c\n");

    if (this->IsOpe2(ch0, ch)) {
      fprintf(stdout, "Found ope\n");
      token_txt += ch; 
      ch = *(++(*pos));
    }
  }

  tok_kind = GetTokenKind(token_txt);
  if (tok_kind == Others){
    fprintf(stdout, "invalid token (text : %s)", token_txt.c_str());
    jyc_log_write(JYC_LOG_ERROR, "invalid token (text : %s)", token_txt.c_str());
  }

  tok_ret = new FSQLToken(tok_kind, token_txt);
  return tok_ret;
}



