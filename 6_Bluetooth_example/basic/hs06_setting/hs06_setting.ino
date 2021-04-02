// 시리얼통신 라이브러리 호출
#include <SoftwareSerial.h> 

// 실제 블루투스 모듈의 rx/tx의 핀을 아두이노에 반대로 꽂기
int blueTx = 3;   // Tx (보내는핀 설정)
int blueRx = 2;   // Rx (받는핀 설정)

// 시리얼 통신을 위한 객체선언
SoftwareSerial mySerial(blueRx, blueTx);  
 
void setup() 
{
  // DEFAULT: 9600
  Serial.begin(115200);   // 시리얼모니터
  mySerial.begin(115200); // 블루투스 시리얼
  Serial.println("ATcommand");   
}

// AT command를 활용하여 블루투스 모듈을 셋팅하기 위한 코드
void loop()
{
  if (mySerial.available()) {       
    Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }
}
