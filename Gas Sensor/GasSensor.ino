// Detects LPG (Liquefied Petroleum Gas) / propane autogas
const int gasSensorPin=A0; // Uses the analog pin, not the digital pin

void setup()
{  
  Serial.begin(9600);           
 }

void loop()
{
  Serial.println(getGasAmount());
  delay(500); 
}

int getGasAmount() {
  int gasAmount = analogRead(gasSensorPin);
  if (gasAmount < 400)
    Serial.println("LPG detected");
  else
    Serial.println("No LPG detected");
  return analogRead(gasSensorPin);
}
