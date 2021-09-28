#include <stdio.h>
#include <wiringPi.h>

int gpio[8] = {1,4,5,6,26,27,28,29};
int num[][8] = {
       //a,b,c,d,e,f,g,DP
	{1,1,1,1,1,1,0,0},
	{0,1,1,0,0,0,0,1},
	{1,1,0,1,1,0,1,0},
	{1,1,1,1,0,0,1,1},
	{0,1,1,0,0,1,1,0},
	{1,0,1,1,0,1,1,0},
	{1,0,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1,0}};

int main(){
	if(wiringPiSetup() == -1)
		return 0;

	for(int i = 0; i < 8; i++)
		pinMode(gpio[i],OUTPUT);

	int count = 0;
	while(count < 2){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 8; j++){
				digitalWrite(gpio[j],num[i][j]);
			}
			delay(1500);
		}
	count++;
	}

	for(int i = 0; i < 8; i++)
		digitalWrite(gpio[i],0);
}
