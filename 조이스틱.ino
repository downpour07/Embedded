int x;
int y;
int z;
void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  x = analogRead(14);
  y = analogRead(15);
  z = digitalRead(9);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  delay(500);
}
