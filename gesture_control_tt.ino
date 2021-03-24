#include<SPI.h>

#include"Wire.h"



#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 






#include "Wire.h" 


const int MPU_ADDR = 0x68;

int16_t accelerometer_x, accelerometer_y, accelerometer_z;
int aX,aY,aZ;


char tmp_str[7];

char* convert_int16_to_str(int16_t i)
{ 
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void setup() {
  
  Serial.begin(9600);
  BTserial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B); 
  Wire.write(0); 
  Wire.endTransmission(true);




}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_ADDR, 7*2, true); 
  

  accelerometer_y = Wire.read()<<8 | Wire.read(); 
  accelerometer_x = Wire.read()<<8 | Wire.read(); 
  accelerometer_z = Wire.read()<<8 | Wire.read(); 




  aX = (accelerometer_x / 16384.0)*90;
  aY = (accelerometer_y / 16384.0)*90; 
  aZ = (accelerometer_z / 16384.0)*90;



  aX=aX+180;
  aY=aY+180;

    if(aX<0 && aZ<0)
  {
    aX=-180-aX;
  }
    if(aX>0 && aZ<0)
  {
    aX=180-aX;
  }
  if(aY<0 && aZ<0)
  {
    aY=-180-aY;
  }
    if(aY>0 && aZ<0)
  {
    aY=180-aY;
  }
  







  Serial.print("|##| position(deg) | aX = "); Serial.print(aX);
  Serial.print(" | aY = "); Serial.print(aY);




  
  Serial.println();


  // delay
  delay(5);

if(aX<-50 && aY<-40)
{
BTserial.println("t");
}
if(aX>40 && aY<-40)
{
BTserial.println("g");
}
if(aX>40 && aY>60)
{
BTserial.println("h");
}
if(aX<-50 && aY>60)
{
BTserial.println("y");
}



if(aX<-50)
{
BTserial.println("w");
}
if(aY<-40)
{
BTserial.println("a");
}
if(aX>40)
{
BTserial.println("s");
}
if(aY>60)
{
BTserial.println("d");
}




}
