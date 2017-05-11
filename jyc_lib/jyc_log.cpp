#include "jyc_log.h"

int jyc_log_init(const char* curr_path, const char* prj_name, int log_lvl){
  int ret = 0;
  if (curr_path) {
    strncpy(jyc_log_base_path, curr_path, 8192);
    fprintf(stdout, "[jyc-log] log path : %s)\n", curr_path);

    if (access(curr_path, F_OK) == -1){
      fprintf(stderr, "[jyc-log] log path is not existing (curr_path : %s)\n", curr_path);
      ret =-1;
      goto ret;
    }
  }

  if (prj_name) {
    strncpy(jyc_log_prj_name, prj_name, 8192);
    fprintf(stdout, "[jyc-log] project name : %s)\n", prj_name);
  }

  jyc_log_level = log_lvl;

 ret:
  return ret;
}


int jyc_log_write(int level, const char* tmpl_messages, ...){
  int ret = 0;
  FILE* file = NULL;
  time_t cur_time;
  struct tm *ptm;
  char file_path[8192] = {0};
  char buf[8192] = {0};
  char messages[8192] = {0};
  va_list argptr;

  cur_time = time((time_t *)0);

  ptm = localtime(&cur_time);

  if (strcmp(jyc_log_base_path, "") && strcmp(jyc_log_prj_name, ""))
  {
    snprintf(file_path, 8192, "%s/[%d-%d-%d]%s.log", jyc_log_base_path, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_year+1900, jyc_log_prj_name);

  }
  else
  {
    fprintf(stderr, "[jyc-log] A base path, and project name was not initialized...");
    ret = -1;
    goto ret;
  }

  va_start(argptr, tmpl_messages);
  vsprintf(messages, tmpl_messages, argptr);
  va_end(argptr);

  snprintf(buf, 8192, "[%d/%d/%d %d:%d:%d] %s\n", ptm->tm_mon+1, ptm->tm_mday, ptm->tm_year+1900, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, messages);

  if (level <= jyc_log_level){
    if((file = fopen(file_path, "a+")) == NULL){
      perror("[jyc-log] fopen() log file was failed.");
      ret = -1;
      goto ret;
    }
    else{
      fputs(buf, file);
    }
  }

 ret:
  if(file) fclose(file);
  return ret;
}
