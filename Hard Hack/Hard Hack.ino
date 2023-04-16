// include libraries
#include <Servo.h>

// initialize constants, variables, and objects
const int trigPin = 9;
const int echoPin = 10;


const int ledPin = 8;


float duration, distance;
float trigger_distance = 10;


int openAngle = 180;
int angle =0;
int angleInc = 36;
int angleDif = 0;


//speed of sound in cm/us
float c = 0.0343;


Servo servo1, servo2;
int servo1_Pin = 11; //change later lol
int servo2_Pin = 12;
int pos1 = 0;
int pos2 = 0;


void setup() {
 servo1.attach(servo1_Pin);
 servo2.attach(servo2_Pin);
 pinMode(trigPin, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(echoPin, INPUT);


 //start Serial communication
 Serial.begin(9600);      
}


void loop() {
 // OUTPUT BURST //
 //starting trigPin low
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 // "burst" output
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
  // DETECT INPUT //
 /* pulseIn() waits to see when echoPin is targetState (aka HIGH),
 which occurs when sound waves hit the receiver, then stores
 the time value how long this is true for
 */
 duration = pulseIn(echoPin, HIGH);
 distance = duration*c/2;
 Serial.println("Distance: "+ String(distance));


 swivel();
 delay(100);
  // CONTROL //
 if(distance <= trigger_distance){
   //turn wheels
   //drive backwards
   //turn wheels back
   //drive forwards

 }
    
} //close loop


void swivel(){
 if (angle>=openAngle){
   angleDif = -angleInc;
 }
 else if (angle<angleInc){
   angleDif = angleInc;
 }
 angle += angleDif;
 servo1.write(angle);

 }
