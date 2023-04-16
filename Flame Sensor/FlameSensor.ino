const int flameSensorPin = A0; // Uses analog (A0) pin, not digital (D0) pin

void setup()  {
  Serial.begin(9600);  
}

void loop() {
  // read the sensor on analog A0:
  Serial.println(getFireDistance());
  delay(500);
}

/**
 * Returns the closeness of a fire from 0 (very close) to 1023 (no fire)
 */
 int getFireDistance() {
  int distance = analogRead(flameSensorPin);
//  if (distance < 41) {
//    Serial.println("Fire in less than 1.5 ft");
//  } else if (distance < 82) {
//    Serial.println("Fire between 1 and 3 ft");
//  } else {
//    Serial.println("No fire");
//  }
  return distance;
 }
