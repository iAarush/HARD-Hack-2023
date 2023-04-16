// Set up analog temperature sensor
const int thermistorPin = A0;
const double BOARD_RESISTANCE = 10000; // Resistor on board
const double SHC1 = 0.001129148, SHC2 = 0.000234125, SHC3 = 0.0000000876741;  // Steinhart-Hart coeficients for thermistor

// Set up light sensor
const int lightSensorPin = A1;
int brightness;

// Set up gas sensor
const int gasSensorPin = A2;

// Set up buzzer
const int buzzerPin = 3;

// Set up ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;
//speed of sound in cm/us
float c = 0.0343;

/**
 * Returns the temperature in Kelvin
 */
double getTemperature() {
  int resistance = BOARD_RESISTANCE * (1023.0 / (double) analogRead(thermistorPin) - 1.0); // resistance on thermistor
  double logResistance = log(resistance);
  return 1.0 / (SHC1 + SHC2*logResistance + SHC3*pow(logResistance, 3));
}

int getBrightness() {
  int brightness = analogRead(lightSensorPin);
  return brightness;
}

int getGasAmount() {
  int gasAmount = analogRead(gasSensorPin);
  return gasAmount;
}

double getDistance() {
  digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 return pulseIn(echoPin, HIGH)*c/2;
}

void soundAlarm() {
//  tone(buzzerPin, 1000); // Send 1KHz sound signal
  delay(1000);
  noTone(buzzerPin);
  delay(1000);
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Display temperature
  if (getTemperature() > 373.15) {
    Serial.println("Too hot");
    soundAlarm();
  } else {
    Serial.println("Not hot");
  }

  // Display brightness
  brightness = getBrightness();
  Serial.println(brightness);
//  if (brightness < 10) {
//    Serial.println("Too Dark");
//  } else if (brightness < 200) {
//    Serial.println("Dim");
//  } else if (brightness < 500) {
//    Serial.println("Light");
//  } else {
//    Serial.println("Too bright");
//    soundAlarm();
//  }

  // Display gas amount
   int gasAmount = getGasAmount();
  if (gasAmount < 200) {
    Serial.print("LPG detected: ");
    Serial.print(gasAmount); 
    soundAlarm();
  } else {
    Serial.print("No LPG detected: ");
    Serial.print(gasAmount);
  }
  Serial.println();

  // Display distance
 Serial.print("Distance: ");
  if (getDistance() < 5.0) {
    Serial.println("Too close");
    soundAlarm();
  } else {
    Serial.println("Safe distance");
  }

  Serial.println();
  delay(1000);
}
