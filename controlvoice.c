#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>

int nVoice = 1;
int nControl = 4;

clock_t cTime1 = 0;
clock_t cTime2 = 0;

int main(){

	if(wiringPiSetup() == -1)
		return 0;

	pinMode(nVoice,OUTPUT);
	pinMode(nControl,INPUT);

	int bTime1 = 0;
	int bTime2 = 0;
	int bClick = 0;
	while(1){
		if(digitalRead(nControl) == 1 && bClick == 0){
			if(bTime1 == 0){
				bTime1 = 1;
				bTime2 = 0;
				cTime1 = clock();
				// printf("Time1 = %d\r\n", cTime1);
			}
			else if (bTime2 == 0){
				bTime2 = 1;
				bTime1 = 0;
				cTime2 = clock();
				// printf("Time2 = %d\r\n", cTime2);
			}
			
			if(abs((double)(cTime1 - cTime2)) < 500 && cTime1 != 0 && cTime2 != 0){
				// printf("TimeSub = %d\r\n", abs((double)(cTime1 - cTime2)));
				break;
			}

			digitalWrite(nVoice,1);
			delay(30);
			bClick = 1;
		}
		else if(digitalRead(nControl) == 0) {
				bClick = 0;
				digitalWrite(nVoice,0);
				delay(30);
		}

	}
	digitalWrite(nVoice,0);
	return 1;
}
