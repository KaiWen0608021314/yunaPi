#include <stdio.h>
#include <wiringPi.h>

int red = 1;
int yellow = 4;
int green = 5;

int main(){
	if(wiringPiSetup() == -1)
		return 0;

	pinMode(red,OUTPUT);
	pinMode(yellow,OUTPUT);
	pinMode(green,OUTPUT);

	int count = 0;
	while(count < 5){
		//綠燈
		digitalWrite(red,0);
		digitalWrite(yellow,0);
		digitalWrite(green,1);
		delay(1000);

		//黃燈
		digitalWrite(red,0);
		digitalWrite(green,0);
		for(int i = 0; i < 5; i++){
			digitalWrite(yellow,1);
			delay(500);
			digitalWrite(yellow,0);
			delay(500);
		}

		//紅燈
		digitalWrite(red,1);
		digitalWrite(yellow,0);
		digitalWrite(green,0);
		delay(1000);

		count++;
	}
	digitalWrite(red,0);
	return 1;
}
