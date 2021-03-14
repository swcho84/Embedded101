#include <Wire.h>

// assigning the slave address
#define SLAVE    4

// assigning counter 
byte counter = 0;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  // intializing the wire library (assinging the address)
  Wire.begin(SLAVE);
  Serial.begin(115200);

  // assigning the loop when receiving the request from the master
  Wire.onRequest(sendToMaster);
}

// recursive loop
void loop() 
{
}

// assigning the loop for the data sending
void sendToMaster()
{
  // sending the data to the master
  Wire.write(++counter);

  // for debugging
  Serial.print("Curr. Counter(slave_leo):");
  Serial.println(counter);  
}
