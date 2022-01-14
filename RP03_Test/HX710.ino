#include "pico.h"

#define HX710_SCK 15
#define HX710_DT 14
unsigned long HX710_Buffer = 0;
unsigned long pressure_init = 0;

/*******************************************************************************
 * Function Definitions
 */
void init_HX710(){
  // HX710 Initiation
  pinMode(HX710_SCK, OUTPUT); 
  pinMode(HX710_DT, INPUT);
  HX710_Buffer = HX710_Read();
  pressure_init = HX710_Buffer/100;    
}

unsigned int get_pressure(){
  // Get pressure reading
  HX710_Buffer = HX710_Read();
  HX710_Buffer = HX710_Buffer/100;

  unsigned long pressure = HX710_Buffer;
  pressure = pressure - pressure_init;

  return pressure;
}

unsigned long HX710_Read()
{
  // Read from HX710
  unsigned long count; 
  unsigned char i;
  bool Flag = 0;
  digitalWrite(HX710_DT, HIGH);
  delayMicroseconds(1);
  digitalWrite(HX710_SCK, LOW);
  delayMicroseconds(1);
  count=0; 
  while(digitalRead(HX710_DT)); 
  for(i=0;i<24;i++)
  {
    digitalWrite(HX710_SCK, HIGH); 
    delayMicroseconds(1);
    count=count<<1; 
    digitalWrite(HX710_SCK, LOW); 
    delayMicroseconds(1);
    if(digitalRead(HX710_DT)){
      count++; 
    }
  } 
  digitalWrite(HX710_SCK, HIGH); 
  count ^= 0x800000; // Get complement per HX710 requirement
  delayMicroseconds(1);
  digitalWrite(HX710_SCK, LOW); 
  delayMicroseconds(1);  
  return(count);
}
