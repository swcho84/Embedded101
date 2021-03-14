#include <Wire.h>

// assigning analog pin layout 
// A0: x-axis, A1: y-axis, A2: vertical switch
#define nJoyX  A0
#define nJoyY  A1
#define nJoySW A2

// assigning the slave address
#define SLAVE  4

// joystick status
int nJoy[3] = {0, 0, 0};
const int nJoyMode = 3;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // intializing the wire library (assinging the address)
  Wire.begin();
  Serial.begin(115200);

  // mapping the pin layout for the joystick
  pinMode(nJoyX, INPUT_PULLUP);
  pinMode(nJoyY, INPUT_PULLUP);
  pinMode(nJoySW, INPUT_PULLUP);    
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  i2c_comm();
}

// generating i2c comm and data processing loop
void i2c_comm()
{
  // reading joystick status
  nJoy[0] = analogRead(nJoyX);
  nJoy[1] = analogRead(nJoyY);
  nJoy[2] = analogRead(nJoySW);
  
  // sending the data to slave
  Wire.beginTransmission(SLAVE);
  Wire.write(nJoy[0] >> 8);
  Wire.write(nJoy[0] & 0xFF);
  Wire.endTransmission(SLAVE);
  delay(100);
  Wire.beginTransmission(SLAVE);
  Wire.write(nJoy[1] >> 8);
  Wire.write(nJoy[1] & 0xFF);
  Wire.endTransmission(SLAVE);
  delay(100);  
  Wire.beginTransmission(SLAVE);
  Wire.write(nJoy[2] >> 8);
  Wire.write(nJoy[2] & 0xFF);
  Wire.endTransmission(SLAVE);
  delay(100);
    
  // for deugging
  Serial.print("Sending::(X,y,sw):\n");
  for (int i = 0; i < nJoyMode; i++)
    Serial.println(nJoy[i]); 
  Serial.print("\n\n");  
}
