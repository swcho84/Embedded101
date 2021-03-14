#include <Wire.h>

// assigning the slave address
#define SLAVE   4

// initialization
void setup() 
{
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  i2c_comm();
  delay(100);
}

// generating i2c comm and data processing loop
void i2c_comm()
{
  // requiring 1byte(=8bit) data
  Wire.requestFrom(SLAVE, 1);

  // reading the received data
  char c = Wire.read();

  // for deugging
  Serial.print("from ArduLeo:");
  Serial.println(String(c, DEC));
}
