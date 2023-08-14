int b = 1;

void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT);
}

void loop() {
  b = digitalRead(9);
  if(b)
  {
    Serial.println("OFF");
  }
  else
  {
    Serial.println("ON");
  }
  delay(500);
}