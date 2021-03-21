#include <Servo.h>

// assigning the servo pin address
Servo myServo;
int nServoPin = 11;

// setting the min-max angle
int nMin = 20;
int nMax = 160;
int nTrim = (nMin + nMax)/(2);

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // setting the servo pwm pin
  myServo.attach(nServoPin);

  // setting the servo trim angle
  myServo.write(nTrim);
  delay(1000);
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  // finding the servo min-max angle  
  for (int nAngle = nMin; nAngle <= nMax; nAngle++)
  {
    myServo.write(nAngle);
    delay(15);
  }
  delay(1000);  
  for (int nAngle = nMax; nAngle >= nMin; nAngle--)
  {
    myServo.write(nAngle);
    delay(15);
  }
  delay(1000);    
}
