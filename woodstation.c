#include "woodstation.h"

int main() {

	time_t displayedRawTime;
	time ( &displayedRawTime );
	char timeBuff[60];
	
	while(1){
		time_t rawtime;
		time ( &rawtime );
		if (difftime(rawtime, displayedRawTime) != 0) {
			struct tm * timeinfo;
			timeinfo = localtime ( &rawtime );
			if (strftime(timeBuff, sizeof timeBuff, "%H%M%S", timeinfo)) {
				puts(timeBuff);
				displayedRawTime = rawtime;
			} else {
				puts("strftime failed");
			}
		}
		nanosleep((const struct timespec[]){{0, 50000000L}}, NULL); /* sleep for 0.05s */
	}
	return 0;
}
