#include <unistd.h>        //Needed for I2C port
#include <fcntl.h>          //Needed for I2C port
#include <sys/ioctl.h>      //Needed for I2C port
#include <linux/i2c-dev.h>  //Needed for I2C port
#include <linux/i2c.h>      //Needed for I2C port

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <time.h>

int nInput;
int nAddr = 0x04;

int main(){
    if(wiringPiSetup() == -1)
        return 0;

    int nFD = wiringPiI2CSetup(nAddr);

    while(1){
        printf("請輸入數字(1:開關LED,2:關閉程式)：");
        scanf("%d", &nInput);
        printf("輸入數字為：%d\n", nInput);
        if(nInput == 2){
            break;            
        }
        
        wiringPiI2CWrite(nFD, nInput);
        delay(100);
        int nResult = wiringPiI2CRead(nFD);
        printf("接收結果：%d\n", nResult);
    }
    return 1;
}