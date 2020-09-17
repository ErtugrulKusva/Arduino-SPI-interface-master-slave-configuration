#include <SPI.h>
//SPI SLAVE ARDUINO

 
char buf [100];
volatile byte pos;
volatile boolean process_it;
 
void setup (void)
{
  Serial.begin (9600); 
  SPCR |= bit (SPE);
 
  pinMode(MISO, OUTPUT);
 
  pos = 0;   
  process_it = false;
  SPI.attachInterrupt();//This function DOES NOT support!! in esp series(esp32, esp8266 eg.)
 
}  
 
ISR (SPI_STC_vect)
{
byte c = SPDR;  
  if (pos < sizeof buf)
    {
    buf [pos++] = c;
 
    if (c == '\n')
      process_it = true;
       
}
}
 
void loop (void)
{
  if (process_it)
    {
    buf [pos] = 0;  
    Serial.println (buf);
    pos = 0;
    process_it = false;
    }  
}
