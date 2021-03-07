// setting the pin number, for the single led
const int nSingleLed[4] = {2, 3, 4, 5};
const int nNumLed = 4;

// setting the pin number, for the RGB led
const int nRgbR = 8;
const int nRgbG = 6;
const int nRgbB = 7;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  // setting led pin mode, array output
  for (int i = 0; i < nNumLed; i++)
    pinMode(nSingleLed[i], OUTPUT); 

  // setting RGB led pin mode, output
  pinMode(nRgbR, OUTPUT);
  pinMode(nRgbG, OUTPUT);
  pinMode(nRgbB, OUTPUT);
}

// recursive loop
void loop() 
{
  // put your main code here, to run repeatedly:
  // controlling single LED array
  for (int i = nSingleLed[0]; i <= (nSingleLed[3]); i++)
  {
    GenLEDctrl(i);
    delay(1000);
  }

  // controlling RGB LED, single-to-single type
  Serial.println("On:Red, Off:others");
  digitalWrite(nRgbR, HIGH);
  digitalWrite(nRgbG, LOW);
  digitalWrite(nRgbB, LOW);
  delay(1000);  

  // controlling RGB LED, single-to-single type
  Serial.println("On:Green, Off:others");
  digitalWrite(nRgbR, LOW);
  digitalWrite(nRgbG, HIGH);
  digitalWrite(nRgbB, LOW);
  delay(1000);    

  // controlling RGB LED, single-to-single type
  Serial.println("On:Blue, Off:others");
  digitalWrite(nRgbR, LOW);
  digitalWrite(nRgbG, LOW);
  digitalWrite(nRgbB, HIGH);
  delay(1000);

  // off all LED 
  Serial.println("On:None, Off:all");
  digitalWrite(nRgbR, LOW);
  digitalWrite(nRgbG, LOW);
  digitalWrite(nRgbB, LOW);
  for (int j = 0; j < nNumLed; j++)
    digitalWrite(nSingleLed[j], LOW);      
  delay(1000);
}

// controlling single LED array
void GenLEDctrl(int nLed)
{
  for (int j = 0; j < nNumLed; j++)
  {
    if (nSingleLed[j] == nLed)
      digitalWrite(nSingleLed[j], HIGH);
    else
      digitalWrite(nSingleLed[j], LOW);      
  }
}
