#include <SoftwareSerial.h>

// SoftwareSerial(RX, TX) 형식으로 블루투스 모듈과 교차하여 연결
SoftwareSerial BTserial(2, 3);

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
//#include "Servo.h"
 
MPU6050 mpu;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 

 
int val;
int prevVal;
 
void setup() 
{
    Wire.begin();
    //Serial.begin(38400);
 
    Serial.println("Initialize MPU");
    mpu.initialize();
    
   // Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");


    BTserial.begin(9600); //블루투스 연결 초기화
}
 
void loop() 
{
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
    val = map(ay, -17000, 17000, 0, 179);
    if (val != prevVal)
    {

      if(val <= 100){
        BTserial.write('A');
        delay(500);
      }
      else if(val > 100){
        BTserial.write('B');
        delay(50);
      }

      
     
        prevVal = val;
    }
 

}
