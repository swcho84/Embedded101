#include <Wire.h>

// assigning analog pin layout 
// A0: x-axis, A1: y-axis, A2: vertical switch
#define nJoyX  A0
#define nJoyY  A1
#define nJoySW A2

// joystick status
int nJoy[3] = {0, 0, 0};
const int nJoyMode = 3;
const int nMinJoyAnalog = 16;
const int nMaxJoyAnalog = 1020;
byte myData[3] = {0x98, 0x45, 0x7A};
const int nMinByte = 1;
const int nMaxByte = 254;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // setting the serial port between the arduino and the computer
  Serial.begin(115200);

  // setting the serial port between the arduino and the bluetooth module
  Serial1.begin(115200);

  // for debugging
  Serial.println("BtModule:Slave");

  // initializing the wire library (assinging the address)
  Wire.begin();

  // mapping the pin layout for the joystick
  pinMode(nJoyX, INPUT_PULLUP);
  pinMode(nJoyY, INPUT_PULLUP);
  pinMode(nJoySW, INPUT_PULLUP);      
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  // reading joystick status
  nJoy[0] = analogRead(nJoyX);
  nJoy[1] = analogRead(nJoyY);
  nJoy[2] = analogRead(nJoySW);
    
  // setting the data
  myData[0] = map(nJoy[0], nMinJoyAnalog, nMaxJoyAnalog, nMinByte, nMaxByte);
  myData[1] = map(nJoy[1], nMinJoyAnalog, nMaxJoyAnalog, nMinByte, nMaxByte);
  myData[2] = map(nJoy[2], nMinJoyAnalog, nMaxJoyAnalog, nMinByte, nMaxByte);

  // transmitting data from mega to uno
  Serial1.write(myData, sizeof(myData));

  // for debugging
  delay(25);
}
