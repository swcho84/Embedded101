#include <SPI.h>

int nSSarduUno = 53;
int nSSeeProm = 42;

// initialization
void setup (void)
{
  // put your setup code here, to run once:
  pinMode(nSSarduUno, OUTPUT);
  pinMode(nSSeeProm, OUTPUT);
  digitalWrite(nSSarduUno, HIGH);
  digitalWrite(nSSeeProm, HIGH);
  SPI.begin();

  // 1 MHz speed insted of default 4 MHz
  SPI.setClockDivider(SPI_CLOCK_DIV16);  
}

// recursive loop
void loop (void)
{
  // put your main code here, to run repeatedly:
  // assigning the string data
  const char *p = "Hello, world\n";

  // enable Slave Select
  digitalWrite(nSSarduUno, LOW);

  // send test string
  for (int i = 0; i < strlen(p); i++)
    SPI.transfer(p[i]);

  // disable Slave Select
  digitalWrite(nSSarduUno, HIGH);

  // for debugging
  delay (1000);
}
