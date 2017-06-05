#include <SoftwareSerial.h>
#include<MsTimer2.h>
char c ;
char ch;

void timeOut(){
     pinMode(6, INPUT);
     pinMode(7, INPUT);
  }
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
    Serial.flush();                           
    BTserial.begin(9600);  
    Serial.println("BTserial started at 38400");
}
 
void loop()
{   
 if (BTserial.available()){ //  데이터 수신
    char ch = BTserial.read();
   Serial.println(ch);
    switch(ch){  
      
            case 'L': //좌
            pinMode(6, OUTPUT);
            MsTimer2::set(500, timeOut); 
            MsTimer2::start();          
            break;

            case 'R': //우
            pinMode(7, OUTPUT);
            MsTimer2::set(500, timeOut);
            MsTimer2::start();
            break;
    }
}
     
  if (Serial.available()>0)  // if (BTserial.available())//
    {  
        //c = BTserial.read();
        c = Serial.read();  
        Serial.write(c);

          switch(c){
             
             case 'B': //뒤
            pinMode(5, OUTPUT);
            delay(200);
            pinMode(5, INPUT);
            break;
             
             case 'F': //앞
            pinMode(4, OUTPUT);
            delay(200);
            pinMode(4, INPUT);
            break;

          }       
    } 
}
