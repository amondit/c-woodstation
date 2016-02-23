#include<stdio.h>
#include<time.h>

int main() {

  time_t rawtime;
  struct tm * timeinfo;
  char timeBuff[60];
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  if (strftime(timeBuff, sizeof timeBuff, "%H%M%S", timeinfo)) {
        puts(timeBuff);
    } else {
        puts("strftime failed");
    }
  printf ( "Current local time and date: %s", asctime (timeinfo) );
  return 0;
}
