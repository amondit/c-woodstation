#include "woodstation.h"

static const int timeDisplayBaseAddresses[6][2]=
{
		{0,2},	//H
		{14,2},	//H
		{28,2},	//m
		{0,3},	//m
		{14,3},	//s
		{28,3}	//s
};

static const int dateDisplayBaseAddresses[8][2]=
{
		{1,0},	//D
		{15,0},	//D
		{29,0},	//M
		{1,1},	//M
		{15,1},	//Y
		{29,1},	//Y
		{1,2},	//Y
		{29,1}	//Y
};

static const int sevenSegmentDigits[10][7]=
{
		{1, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 0, 0, 0, 0},
		{1, 1, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 1},
		{0, 1, 1, 0, 0, 1, 1},
		{1, 0, 1, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1}
};
static const int spaceCharacter[7] = {0, 0, 0, 0, 0, 0, 0};
static const int minusCharacter[7] = {0, 0, 0, 0, 0, 0, 1};


void writeDisplayCharacterAtIndex(int* sevenSegmentCharBitSequence, int baseAddr, int bitIndex){
	if (!sevenSegmentCharBitSequence)
		return;
	int writeAddr = baseAddr;
	for (int i = 0; i < 7; ++i) {

	}
}

void updateTimeDisplay(char* newTime){
	if (!newTime)
		return;
	int iValue = 0;
	char cValue = '0';
	int characterMap[7] = {0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 6; ++i) {
		cValue = newTime[i];
		iValue = atoi(&cValue);
		printf("%d\n",iValue);
	}
}


int main() {

	time_t displayedRawTime;
	time ( &displayedRawTime );
	char timeBuff[60];
	
	while(1){
		time_t rawtime;
		time ( &rawtime );

		//Compare last displayed time, if it has changed wrt current time, we need to update display

		if (difftime(rawtime, displayedRawTime) != 0) {
			struct tm * timeinfo;
			timeinfo = localtime ( &rawtime );
			if (strftime(timeBuff, sizeof timeBuff, "%H%M%S", timeinfo)) {
				updateTimeDisplay(timeBuff);
				displayedRawTime = rawtime;
			} else {
				puts("strftime failed");
			}
		}
		nanosleep((const struct timespec[]){{0, 50000000L}}, NULL); /* sleep for 0.05s */
	}
	return 0;
}
