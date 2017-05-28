#include <SoftwareSerial.h>
#include<MsTimer2.h>
SoftwareSerial BTserial(2, 3); // RX | TX
int LED1 = 12; // LED 연결 핀
int LED2 = 7;
boolean state1 = false; // 현재 LED의 상태
boolean state2 = false;

char c ;

void timeOut(){
     pinMode(6, INPUT);
     pinMode(7, INPUT);
  }
void setup() 
{
    
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
    Serial.flush();                           
  //  Serial.println(">> ");                
  //pinMode(13, INPUT);
    
    BTserial.begin(9600);  
    Serial.println("BTserial started at 38400");


//BTSerial.begin(9600); // 블루투스 연결 초기화
 // pinMode(LED1, OUTPUT); // LED 연결 핀을 출력으로 설정
  //pinMode(LED2, OUTPUT);
  //pinMode(8, OUTPUT);
  //pinMode(9, OUTPUT);
  //pinMode(10,OUTPUT);
  //digitalWrite(9,HIGH);
  //digitalWrite(10, LOW);
  //digitalWrite(10,HIGH);
  //digitalWrite(LED1, LOW); // LED는 꺼진 상태로 시작
  //digitalWrite(LED2, LOW);
  
}
 
void loop()
{   
     //BTserial.listen();

 if (BTserial.available()){ // 마스터로부터 데이터 수신
    char ch = BTserial.read();
   
    switch(ch){ // ‘A’를 수신한 경우 첫 번째 LED 반전
      
            case 'L': //좌
            pinMode(6, OUTPUT);
            MsTimer2::set(500, timeOut); // 5000ms period
            MsTimer2::start();
            
            break;

            case 'R': //우앞
            pinMode(7, OUTPUT);
            MsTimer2::set(500, timeOut); // 5000ms period
            MsTimer2::start();
            break;
    }
    /*else if(ch == 'B'){ // ‘B’를 수신한 경우 두 번째 LED 반전
      state2 = !state2;
      digitalWrite(LED2, state1);
}*/
}
     
  if (Serial.available()>0)  // if (BTserial.available())//
    {  
        //c = BTserial.read();
        c = Serial.read();  
        Serial.write(c);

  //      switch(c){
  //          case 'F': //앞
  //           state1 = !state1;
  //           digitalWrite(LED1, state1);
  //          break;
  
          switch(c){
             
             case 'B': //뒤
            pinMode(5, OUTPUT);
            delay(330);
            pinMode(5, INPUT);
            break;
             
             case 'F': //앞
            // state1 = !state1;
            // digitalWrite(LED1, state1);
            pinMode(4, OUTPUT);
            delay(250);
            pinMode(4, INPUT);
            break;

/*
            case 'B': //뒤
            pinMode(5, OUTPUT);
            delay(330);
            pinMode(5, INPUT);
            break;*/
          }

 //             case 'B': //뒤
  //            digitalWrite(9,LOW);
//              digitalWrite(10,HIGH);
 //             break;
 //         }         
    } 
}
