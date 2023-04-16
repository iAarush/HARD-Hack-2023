const int raindropPin = A0; // Uses analog (A0) pin, not digital (D0) pin

void setup() {
  Serial.begin(9600);  
}
void loop() {
  Serial.println(getRaindropAmount());
  delay(500);
}

int getRaindropAmount() {
  int raindropAmount = analogRead(raindropPin);
//  if (raindropAmount < 25)
//    Serial.println("Wet");
//  else
//    Serial.println("Dry");
  return raindropAmount;
}
