// Basic Bluetooth sketch HC-05_02
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on.
// The default baud rate for communication mode is 9600
//
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 
 
char c = ' ';

#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
 
    // HC-05 default serial speed for commincation mode is 9600
    BTserial.begin(9600);  

    motor1.setSpeed(255);
    motor2.setSpeed(255);
}
 
void loop()
{
 
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);
    
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
   // if (Serial.available())
    //{
      //  c =  Serial.read();
       // BTserial.write(c);  
    //}

     switch(c)
{
case 'w':
motor1.run(FORWARD);
motor2.run(FORWARD);

break;


case 'a':
motor1.run(BACKWARD);
motor2.run(FORWARD);

break;


case 's':
motor1.run(BACKWARD);
motor2.run(BACKWARD);

break;


case 'd':
motor1.run(FORWARD);
motor2.run(BACKWARD);

break;


case 't':
motor1.run(RELEASE);
motor2.run(FORWARD);

break;


case 'y':
motor1.run(FORWARD);
motor2.run(RELEASE);

break;


case 'g':
motor1.run(RELEASE);
motor2.run(BACKWARD);


break;


case 'h':
motor1.run(BACKWARD);
motor2.run(RELEASE);

break;


  
}
    }
    else
    {
      motor1.run(RELEASE);
motor2.run(RELEASE);
    }
 
}
