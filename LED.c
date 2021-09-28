#include <stdio.h>
#include <wiringPi.h>

int led = 1;

int main(void){

	if(wiringPiSetup() == -1)
		return 0;

	pinMode(led,OUTPUT);

	while(1){
		digitalWrite(led,1);
		delay(500);

		digitalWrite(led,0);
		delay(500);
	}
	return 1;
}
