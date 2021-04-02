#include <SoftwareSerial.h>

// assigning SoftwareSerial port (RX,TX)
const int nBtTx = 3;   
const int nBtRx = 2;   
SoftwareSerial btSerial(nBtRx, nBtTx);

// for test data
int nCounter = 0;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // setting the bluetooth serial port 
  btSerial.begin(115200);

  // initializing the serial monitor
  Serial.begin(115200);

  // for debugging
  Serial.println("BtModule:Master");
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:

  // for debugging
  Serial.print("ToSlave:\n");
  Serial.print(nCounter);
  Serial.print("\n");

  // sending the data to the slave
  btSerial.write(nCounter);

  // resetting data
  if (nCounter == 255)
    nCounter = 0;
  else
    nCounter++;

  // checking the available data size
  if (btSerial.available())
  {
    // receiving the data from the slave    
    byte byteData = btSerial.read();

    // for debugging
    Serial.print("FromSlave:\n");
    Serial.print(byteData);
    Serial.print("\n");
  }

  delay(500);
}
