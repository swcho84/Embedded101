#include <Servo.h>
#include <Wire.h>

// assigning analog pin layout 
// A0: x-axis, A1: y-axis, A2: vertical switch
#define nJoyX  A0
#define nJoyY  A1
#define nJoySW A2

// assigning the servo pin address
Servo myServo;
int nServoPin = 11;

// setting the min-max angle
const int nMinAng = 20;
const int nMaxAng = 160;
const int nTrimAng = (nMinAng + nMaxAng)/(2);

// joystick status
int nJoy[3] = {0, 0, 0};
const int nJoyMode = 3;
const int nMinJoyAnalog = 16;
const int nMaxJoyAnalog = 1020;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // initializing the serial monitor
  Serial.begin(115200);  
  
  // initializing the wire library (assinging the address)
  Wire.begin();

  // mapping the pin layout for the joystick
  pinMode(nJoyX, INPUT_PULLUP);
  pinMode(nJoyY, INPUT_PULLUP);
  pinMode(nJoySW, INPUT_PULLUP);  
    
  // setting the servo pwm pin
  myServo.attach(nServoPin);

  // setting the servo trim angle
  myServo.write(nTrimAng);
  delay(1000);
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  // reading joystick status
  nJoy[0] = analogRead(nJoyX);
  nJoy[1] = analogRead(nJoyY);
  nJoy[2] = analogRead(nJoySW);

  // for deugging
  Serial.print("Sending::(X,y,sw):\n");
  for (int i = 0; i < nJoyMode; i++)
    Serial.println(nJoy[i]); 
  Serial.print("\n\n");

  // calculating the servo angle from the y-axis joystick
  int nAngle = map(nJoy[1], nMinJoyAnalog, nMaxJoyAnalog, nMinAng, nMaxAng);

  // controling the servo
  myServo.write(nAngle);
  delay(15);

  // for debugging
  Serial.print("servo angle:\n");
  Serial.println(nAngle);
  Serial.print("\n\n");  
}
