//depends on time.h
#include <time.h>

int wait_millis(int min, int max){
  struct timespec ts;
    int milliseconds= rand()%(max-min)+min;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
  return 0;
}
