// Set up analog temperature sensor
const int thermistorPin = A0;
const double BOARD_RESISTANCE = 10000; // Resistor on board
const double SHC1 = 0.001129148, SHC2 = 0.000234125, SHC3 = 0.0000000876741;  // Steinhart-Hart coeficients for thermistor

// Set up flame sensor
const int flameSensorPin = A1; // Uses analog (A0) pin, not digital (D0) pin

// Set up raindrop sensor
const int raindropPin = A2; // Uses analog (A0) pin, not digital (D0) pin

// Set up light sensor
const int lightSensorPin = A3;

// Set up gas sensor
const int gasSensorPin = A4;

/**
 * Returns the temperature in Kelvin
 */
double getTemperature() {
  int resistance = BOARD_RESISTANCE * (1023.0 / (double) analogRead(thermistorPin) - 1.0); // resistance on thermistor
  double logResistance = log(resistance);
  return 1.0 / (SHC1 + SHC2*logResistance + SHC3*pow(logResistance, 3));
}

/**
 * Returns the closeness of a fire from 0 (very close) to 1023 (no fire)
 */
 int getFireDistance() {
  int distance = analogRead(flameSensorPin);
//  if (distance < 400) {
//    Serial.println("Fire in less than 1.5 ft");
//  } else if (distance < 800) {
//    Serial.println("Fire between 1 and 3 ft");
//  } else {
//    Serial.println("No fire");
//  }
  return distance;
 }

int getRaindropAmount() {
  int raindropAmount = analogRead(raindropPin);
//  if (raindropAmount < 300)
//    Serial.println("Wet");
//  else
//    Serial.println("Dry");
  return raindropAmount;
}

int getBrightness() {
  int brightness = analogRead(lightSensorPin);
//  if (brightness < 10) {
//    Serial.println(" - Dark");
//  } else if (brightness < 200) {
//    Serial.println(" - Dim");
//  } else if (brightness < 500) {
//    Serial.println(" - Light");
//  } else if (brightness < 800) {
//    Serial.println(" - Bright");
//  } else {
//    Serial.println(" - Very bright");
//  }
  return brightness;
}

int getGasAmount() {
  int gasAmount = analogRead(gasSensorPin);
//  if (gasAmount < 400)
//    Serial.println("LPG detected");
//  else
//    Serial.println("No LPG detected");
  return analogRead(gasSensorPin);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Display temperature
  Serial.print("Temperature (K): "); 
  Serial.println(getTemperature());

  // Display fire distance
  Serial.print("Fire distance: ");
  Serial.println(getFireDistance());

  // Display raindrop amount
  Serial.print("Raindrop amount: ");
  Serial.println(getRaindropAmount());

  // Display brightness
  Serial.print("Brightness: ");
  Serial.println(getBrightness());

  // Display gas amount
  Serial.print("Gas amount: ");
  Serial.println(getGasAmount());

  Serial.println();
  delay(500);
}
