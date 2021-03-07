#include <SoftwareSerial.h>

// (RX,TX)
SoftwareSerial mySerialCom1(12 , 13);
SoftwareSerial mySerialCom2(10 , 11);

// RGB led
const int nRgbR = 7;
const int nRgbG = 8;
const int nRgbB = 9;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  mySerialCom1.begin(115200);
  mySerialCom2.begin(115200);  
  Serial.begin(115200);

  // setting RGB led pin mode
  pinMode(nRgbR, OUTPUT);
  pinMode(nRgbG, OUTPUT);
  pinMode(nRgbB, OUTPUT);  
}

// recursive loop
void loop() 
{
  if (mySerialCom2.read() == 'y')
  {
    Serial.println("On");
    digitalWrite(nRgbR, LOW);
    digitalWrite(nRgbG, HIGH);
    digitalWrite(nRgbB, LOW);
    delay(20);
  }
  else
  {
    digitalWrite(nRgbR, HIGH);
    digitalWrite(nRgbG, LOW);
    digitalWrite(nRgbB, LOW);
    delay(20);
  }

  // put your main code here, to run repeatedly:
  if ((Serial.available()))
  {
    char chData = Serial.read();
    Serial.write(chData);
    mySerialCom1.write(chData);
  }
}
