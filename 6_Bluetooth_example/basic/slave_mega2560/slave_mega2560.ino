int nCounter = 0;

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
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  if (Serial1.available())
  {
    // receiving the data from the master
    byte byteData = Serial1.read();

    // for debugging
    Serial.print("FromMaster:\n");
    Serial.println(byteData);

    // sending the ack to the master
    int btAck = 99;
    Serial1.write(btAck);

    // for debugging
    Serial.print("ToMaster:\n");
    Serial.println(btAck);
  }
 
  delay(500);
}
