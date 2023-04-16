//Analog temperature sensor
const int thermistorPin = A0;
const double BOARD_RESISTANCE = 10000; // Resistor on board
const double SHC1 = 0.001129148, SHC2 = 0.000234125, SHC3 = 0.0000000876741;  // Steinhart-Hart coeficients for thermistor
double resistance, logResistance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Temperature: "); 
  Serial.print(getTemperature() - 273.15);
  Serial.println(" C");
  getTemperature();
  delay(500);
}

/**
 * Returns the temperature in Kelvin
 */
double getTemperature() {
  resistance = BOARD_RESISTANCE * (1023.0 / (double) analogRead(thermistorPin) - 1.0); // resistance on thermistor
  logResistance = log(resistance);
  return 1.0 / (SHC1 + SHC2*logResistance + SHC3*pow(logResistance, 3));
}
