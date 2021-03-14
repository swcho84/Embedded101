#include <Wire.h>

// assigning the slave address
#define SLAVE    4

// assigning the data size
const int nDataSize = 3;
int nReceive[3] = {0, 0, 0};
int nCounter = 0;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // intializing the wire library (assinging the address)
  Wire.begin(SLAVE);
  Serial.begin(115200);

  // assigning the loop when receiving the request from the master
  Wire.onReceive(receiveFromMaster);
}

// recursive loop
void loop() 
{
}

// assigning the loop for the data sending
void receiveFromMaster()
{
  // sending the data to the master
  byte r1 = Wire.read();
  byte r2 = Wire.read();
  int value = (r1 << 8) + r2;
  nReceive[nCounter] = value; 

  if (nCounter == 2)
  {
    // for debugging
    Serial.print("Curr. Receive(from ArduDueMaster):\n");
    for (int i = 0; i < nDataSize; i++)
    {
      Serial.print(i);
      Serial.print(": ");
      Serial.println(nReceive[i]);   
    }    
    nCounter = 0;
  }
  else
    nCounter++;
}
