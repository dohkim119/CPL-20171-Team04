/*
#include <SoftwareSerial.h>

// SoftwareSerial(RX, TX) 형식으로 블루투스 모듈과 교차하여 연결
SoftwareSerial BTSerial(2, 3);
int LED1 = 13; // LED 연결 핀
//int LED2 = 10;

boolean state1 = false; // 현재 LED의 상태
//boolean state2 = false;


void timeOut(){
     pinMode(6, INPUT);
     pinMode(7, INPUT);
  }

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600); // 블루투스 연결 초기화
  pinMode(LED1, OUTPUT); // LED 연결 핀을 출력으로 설정
  //pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW); // LED는 꺼진 상태로 시작
  //digitalWrite(LED1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()){ // 마스터로부터 데이터 수신
    char ch = BTSerial.read();
   
    if(ch == 'A'){ // ‘A’를 수신한 경우 첫 번째 LED 반전
      state1 = !state1;
      digitalWrite(LED1, state1);
    }
    else if(ch == 'B'){ // ‘B’를 수신한 경우 두 번째 LED 반전
      state1 = !state1;
      digitalWrite(LED1, state1);
}
}
}
*/
#include <SoftwareSerial.h>
//#include<MsTimer2.h>
SoftwareSerial BTserial(2, 3);

int LED1 = 12; // LED 연결 핀
int LED2 = 7;
boolean state1 = false; // 현재 LED의 상태
boolean state2 = false;

char c ;


  
void setup() 
{
    
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
    Serial.flush();                           
  //  Serial.println(">> ");                

    
    BTserial.begin(9600);  
    Serial.println("BTserial started at 38400");


//BTSerial.begin(9600); // 블루투스 연결 초기화

}
 
void loop()
{   
     BTserial.listen();

 if (BTserial.available()) {// 마스터로부터 데이터 수신
    char ch = BTserial.read();
   
    if(ch == 'A'){ // ‘A’를 수신한 경우 첫 번째 LED 반전
      state2 = !state2;
      digitalWrite(LED2, state2);
    }
    /*else if(ch == 'B'){ // ‘B’를 수신한 경우 두 번째 LED 반전
      state2 = !state2;
      digitalWrite(LED2, state1);
}*/


/******************
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

 */
}     
  if (Serial.available())  // if (BTserial.available())//
    {  
        //c = BTserial.read();
        c = Serial.read();  
        Serial.write(c);

        switch(c){
            case 'F': //앞
            // state1 = !state1;
            // digitalWrite(LED1, state1);
            pinMode(9, OUTPUT);
            delay(200);
            pinMode(9, INPUT);
            break;


            case 'B': //뒤
            pinMode(10, OUTPUT);
            delay(200);
            pinMode(10, INPUT);
            break;
/*
           case 'D': //뒤
            state1 = !state1;
      digitalWrite(LED1, state1);
            break;
*/

/*

      case 'A': //뒤
            state2 = !state2;
      digitalWrite(LED2, state2);
            break;
            
*/




          }
         
          
    }
 
     
   
/*   
 *    
 *    
if (Serial.available())
    {
        c =  Serial.read();
 
        // mirror the commands back to the serial monitor
        // makes it easy to follow the commands
        Serial.write(c);   
        BTserial.write(c);  
    }
 */
}



