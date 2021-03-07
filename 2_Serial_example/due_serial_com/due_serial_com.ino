// setting the pin number, for switch
const int nSwitch = 2;

// settomg the flag value
int nFlag = 0;

// initialization
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);  

  // pin: switch
  pinMode(nSwitch, INPUT);
}

// recursive loop
void loop() 
{
  // generating the switch value
  long switchVal = pulseIn(nSwitch, HIGH);
  if (switchVal > 0)
    nFlag = 1;
  else
    nFlag = 0;

  // writing the trigger variable to serial2 port
  switch(nFlag)
  {
    case 1:
    {
      Serial.println("switch:ON");
      char chYes = 'y';
      Serial2.write(chYes);
      break;
    }
    default:
    {
      char chNo = 'n';
      Serial2.write(chNo);        
      break;
    }
  }  

  // reading the string variable from serial1 port
  if ((Serial1.available()))
    Serial.write(Serial1.read());
}
