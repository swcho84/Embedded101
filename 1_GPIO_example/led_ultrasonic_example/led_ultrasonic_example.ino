// setting the pin number, for the RGB led
const int nRgbR = 8;
const int nRgbG = 6;
const int nRgbB = 7;

// setting the pin number, for the trigger and echo
const int nTrig = 9;
const int nEcho = 10;

// setting the constant variables
const float fSoundSpeed = 340.0f;
const float fCvtCm = 10000.0f;
const float fRoundTrip = 2.0f;

// setting the threshold value
const float fDistThresh = 50.0f; // [cm]

// initialization
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  // setting RGB led pin mode
  pinMode(nRgbR, OUTPUT);
  pinMode(nRgbG, OUTPUT);
  pinMode(nRgbB, OUTPUT);

  // setting ultrasonic sensor
  pinMode(nTrig, OUTPUT);    // trigger pin, output
  pinMode(nEcho, INPUT);     // echo pin, input
}

// recursive loop
void loop() 
{
  // setting variables
  float fDuration = 0.0f; 
  float fDistance = 0.0f;

  // triggering the signal
  digitalWrite(nTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(nTrig, LOW);

  // sensong the distance using the micro ultrasonic sensor
  fDuration = pulseIn(nEcho, HIGH);

  // calculating the distance
  fDistance = (((fSoundSpeed)*(fDuration))/(fCvtCm))/(fRoundTrip);

  // generating the warning sign
  if (fDistance < fDistThresh)
  {
    Serial.println("On:Red, Off:others");
    digitalWrite(nRgbR, HIGH);
    digitalWrite(nRgbG, LOW);
    digitalWrite(nRgbB, LOW);    
  }
  else
  {
    digitalWrite(nRgbR, LOW);
    digitalWrite(nRgbG, HIGH);
    digitalWrite(nRgbB, LOW);    
  }

  // monitoring the distance 
  float fDistMeter = (fDistance)*(0.01f);
  Serial.println("distance: ");
  Serial.println(fDistMeter);
  Serial.println("[m]");
  Serial.println();
  delay(10);
}
