#include <SPI.h>
#include <Servo.h>

// assigning the integer array data
int nBuf[3] = {};
const int nBufSize = 3;
const int nMinByte = 1;
const int nMaxByte = 254;

// for setting spi comm.
volatile byte bytPos = 0;
volatile boolean bProcIt = false;

// assigning the servo pin address
Servo myServo;
const int nServoPin = 9;

// setting the min-max angle
const int nMinAng = 20;
const int nMaxAng = 160;
const int nTrimAng = (nMinAng + nMaxAng)/(2);

void setup (void)
{
  // for the serial monitoring
  Serial.begin(115200);

  // setting the servo pwm pin
  myServo.attach(nServoPin);

  // setting the spi pin
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);

  // 1 MHz speed insted of default 4 MHz
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  // SPE: SPI enable, MSTR: Master-Slave selection, SPIE: SPI interrupt enable
  SPCR |= (1 << SPE);
  SPCR &= ~(1 << MSTR);
  SPCR |= (1 << SPIE);
}

// interrupt function
ISR(SPI_STC_vect)
{
  // receiving data
  byte c = SPDR;

  // checking the data size matching
  if (bytPos < sizeof(nBuf))
  {
    // forwarding data
    nBuf[bytPos++] = c;

    // setting the proc flag
    if (c == nBufSize)
      bProcIt = true;
  }
}

// recursive loop
void loop()
{
  if (bProcIt)
  {
    // calculating the servo angle from the y-axis joystick
    int nAngle = map(nBuf[1], nMinByte, nMaxByte, nMinAng, nMaxAng);
  
    // controling the servo
    myServo.write(nAngle);

    // for data reset
    bytPos = 0;
    bProcIt = false;
  }
}
