#include <Servo.h>
#include <SoftwareSerial.h>

// assigning SoftwareSerial port (RX,TX)
const int nBtTx = 3;   
const int nBtRx = 2;   
SoftwareSerial btSerial(nBtRx, nBtTx);

// assigning the integer array data
int nBuf[3] = {};
const int nBufSize = 3;
const int nMinByte = 1;
const int nMaxByte = 254;

// assigning the servo pin address
Servo myServo;
const int nServoPin = 9;

// setting the min-max angle
const int nMinAng = 20;
const int nMaxAng = 160;
const int nTrimAng = (nMinAng + nMaxAng)/(2);

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // setting the bluetooth serial port 
  btSerial.begin(115200);

  // initializing the serial monitor
  Serial.begin(115200);

  // setting the servo pwm pin
  myServo.attach(nServoPin);
  
  // for debugging
  Serial.println("BtModule:Master");
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  // checking the available data size
  if (btSerial.available())
  {
    // reading data
    byte bufIndx = 0;
    while (btSerial.available() > 0) 
    {
      nBuf[bufIndx] = btSerial.read();
      if (bufIndx == nBufSize)
        break;
      else
        bufIndx++;
    }
  }

  // calculating the servo angle from the y-axis joystick
  int nAngle = map(nBuf[1], nMinByte, nMaxByte, nMinAng, nMaxAng);

  Serial.println(nBuf[0]);
  Serial.println(nBuf[1]);
  Serial.println(nBuf[2]);
  Serial.print("\n");

  // controling the servo
  myServo.write(nAngle);
  delay(25);
}
