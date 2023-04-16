/*
// Basic Bluetooth sketch HC-05_02
// Connect the HC-05 module and communicate using the serial monitor

// The HC-05 defaults to communication mode when first powered on.
// The default baud rate for communication mode is 9600
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.

// Based on http://www.martyncurrey.com/arduino-with-hc-05-bluetooth-module-in-slave-mode/
 
char c = ' ';
String s;
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");

    pinMode(13, OUTPUT);
 
    // HC-05 default serial speed for communication mode is 9600
    BTserial.begin(9600);  
}

void loop()
{
 
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);

        if (c == '\r' || c == '\n') {
          s = "";
        }
        else {
          s = s + c;
          Serial.print("#");
          Serial.print(s);
          Serial.println("#");
          if (s == "ON" || s == "on") {
            digitalWrite(13, HIGH);
          }
          else if (s == "OFF" || s == "off") {
            digitalWrite(13, LOW);
          }
        }
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);
    }
 
} // close loop
*/