int led = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  // Serial.write() does the same thing as Serial.print()
  Serial.println("on");
  delay(500);
  digitalWrite(led, LOW);
  Serial.println("off");
  delay(500);

  // PWM (available on pins with '~' next to it)
  // analogWrite(led, 5);
}
