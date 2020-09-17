#include <SPI.h>
 //SPI MASTER ARDUINO
void setup (void)
{
  digitalWrite(SS, HIGH);  
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
} 
 
void loop (void)
{
  char c;
  digitalWrite(SS, LOW);   
 
  for (const char * p = "Hello!\n" ; c = *p; p++)
    SPI.transfer (c);
 
  digitalWrite(SS, HIGH);
 
  delay (1000); 
} 
