#ifndef _JYC_LOG_H_
#define _JYC_LOG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>

#define JYC_LOG_NORMAL 0
#define JYC_LOG_WARNING 1
#define JYC_LOG_ERROR 2
#define JYC_LOG_DEBUG 3

static int jyc_log_level = JYC_LOG_ERROR;
static char jyc_log_base_path[8192] = {0};
static char jyc_log_prj_name[8192] = {0};

int jyc_log_init(const char* curr_path, const char* prj_name, int log_lvl);
int jyc_log_write(int level, const char* tmpl_messages, ...);

#endif
