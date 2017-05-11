#include <common.h>
#include <jyc_log.h>
#include <fksql.h>

using namespace std;
using namespace fsql;

int main(int argc, char* argv[])
{
  if (argc != 2){
    perror("arguments count should be 2.");
    return 0;
  }

  jyc_log_init("./", "fucker_sql", JYC_LOG_DEBUG);

  printf("===============\n");
  printf("Start fuckerSQL\n");
  printf("===============\n");

  FSQL fsql;
  fsql.StartSQL(argc, argv);

  return 0;
}

