void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

int a;
int toggle;

void loop() {
  int a = 255 - analogRead(A0);
  if (a > 50) {
    digitalWrite(13, HIGH);
    Serial.println(a);
    for (int i = 0; i < 256; i++) {
      if (i > a)
        digitalWrite(13, LOW);
      delayMicroseconds(20);
    }
  }
}