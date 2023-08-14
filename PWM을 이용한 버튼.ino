int a = 0;
int type = 1;
int bb = 0;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  int b = digitalRead(9);
  if (!b) {
    if (!bb) {
      type = !type;
      bb = 1;
    }
  } else {
    bb = 0;
  }
  if (type) {
    a += 1;
  } else {
    a -= 1;
  }
  if (a > 255) {
    a = 255;
  }
  if (a < 0) {
    a = -1;
  }
  for (int i = 0; i < 256; i++) {
    if (i > a) {
      digitalWrite(13, LOW);
    }
    delayMicroseconds(20);
  }
}
