#include <stdio.h>
#include <wiringPi.h>

int led[8] = {1,4,5,6,26,27,28,29};

int main(){
	if(wiringPiSetup() == -1)
		return 0;

	for(int i = 0; i < 8; i++)
		pinMode(led[i],OUTPUT);

	int count = 0;
	while(count < 5){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(i == j)
					digitalWrite(led[i],1);
				else
					digitalWrite(led[j],0);
			}
			delay(500);
		}
		count++;
	}
	for(int i = 0; i < 8; i++)
		digitalWrite(led[i],0);

	return 1;
}
