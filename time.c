#include "types.h"
#include "user.h"
#include "date.h"

int stdout = 1;
int stderr = 2;

void convertTime(int time);

int main(int argc, char *argv[])
{
  int realTimeStart = uptime();
  // based on init.c
  int processId = fork();
  if (processId < 0)
  {
    printf(stdout, "time: error executing command\n");
    exit();
  }
  else if (processId == 0)
  {
    exec(argv[1], argv + 1);
    exit();
  }
  else if (processId > 0)
  {
    wait();
  }

  int sysTime = time();
  int realTime = uptime() - realTimeStart;
  int userTime = realTime - sysTime;

  // print time
  convertTime(sysTime);
  convertTime(realTime);
  convertTime(userTime);

  exit();
}

void convertTime(int time)
{
  int seconds = time / 100;
  int miliseconds = time % 100;
  if (miliseconds < 10)
  {
    printf(stdout, "%d.00%ds\n", seconds, miliseconds);
  }
  else if (miliseconds < 100)
  {
    printf(stdout, "%d.0%ds\n", seconds, miliseconds);
  }
  else
  {
    printf(stdout, "%d.%ds\n", seconds, miliseconds);
  }
}