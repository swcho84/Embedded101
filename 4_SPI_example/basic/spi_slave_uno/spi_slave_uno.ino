#include <SPI.h>

// assigning the string data
char chBuf[100];

// for interrupt
volatile byte bytPos = 0;
volatile boolean bProcIt = false;

// initialization
void setup (void)
{
  // for serial monitoring
  Serial.begin(115200);

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
  byte c = SPDR;
  if (bytPos < sizeof(chBuf))
  {
    chBuf[bytPos++] = c;
    if (c == '\n')
      bProcIt = true;
  }
}

// recursive loop
void loop()
{
  if (bProcIt)
  {
    chBuf[bytPos] = 0;
    Serial.print(chBuf);
    bytPos = 0;
    bProcIt = false;
  }
}
