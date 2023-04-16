int lightMonitor = 750;
int random_variable;
int static_variable = 500;

void setup() {
  // put your setup code here, to run once:
  //pinMode(A0, INPUT);
  
  //digitalWrite(IN2_PIN, LOW); 


  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // reads the input on analog pin A0 (value between 0 and 1023)
  //int lightMonitor = analogRead(A0);
  lightMonitor = analogRead(A0);

  //Serial.print("Analog reading: ");
  Serial.print(lightMonitor);   // the raw analog reading
  Serial.println(",");

  // We'll have a few threshholds, qualitatively determined
  /*
  if (lightMonitor < 10) {
    Serial.println(" - Dark");
  } else if (lightMonitor < 200) {
    Serial.println(" - Dim");
  } else if (lightMonitor < 500) {
    Serial.println(" - Light");
  } else if (lightMonitor < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
*/

/*
  random_variable = random(0, 1000);

  Serial.print("Variable_1:");
  Serial.print(random_variable);
  Serial.print(",");
  Serial.print("Variable_2:");
  Serial.println(static_variable);
*/

  delay(1000);
}