#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <wiringPi.h>

clock_t time1 = 0,time2 = 0;
int n = 0;
int control = 25;
int led[8] = {1,4,5,6,26,27,28,29};
int num[][8] = {
       //a,b,c,d,e,f,g,dp
	{1,1,1,1,1,1,0,0},
	{0,1,1,0,0,0,0,1},
	{1,1,0,1,1,0,1,0},
	{1,1,1,1,0,0,1,1},
	{0,1,1,0,0,1,1,0},
	{1,0,1,1,0,1,1,1},
	{1,0,1,1,1,1,1,0},
	{1,1,1,0,0,0,0,1},
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,0,1,1,1}};


int main(){
	if(wiringPiSetup() == -1)
		return 0;

	pinMode(control,INPUT);
	for(int i = 0; i < 8; i++)
		pinMode(led[i],OUTPUT);

	int nCount = 0;
	int bCountAdd = 0;
	int nBreak = 0;
	int btime1 = 0;
	int btime2 = 0;
	while(nBreak == 0){
		if(digitalRead(control) == 0){
			if(n % 2 == 0 && btime1 == 0){
				btime1 = 1;
				time1 = clock();
				//printf("time1 = %d\r\n",time1);
			}
			else if(n % 2 == 1 && btime2 == 0){
				btime2 = 1;
				time2  = clock();
				//printf("time2 = %d\r\n",time2);
			}

			if(abs((double)(time1 - time2)/1000) < 500){
				nBreak == 1;
				break;
			}

			for(int i = 0; i < 8; i++){
				digitalWrite(led[i],num[nCount][i]);
			}
			delay(30);
			bCountAdd = 1;
		}
		else{
			if(bCountAdd == 1){
				bCountAdd = 0;
				nCount++;
				n++;
				btime1 = 0;
				btime2 = 0;
				if(nCount >= 10)
					nCount = 0;
			}
		}
	}
	for(int i = 0; i < 8; i++)
		digitalWrite(led[i],0);
	return 1;
}
