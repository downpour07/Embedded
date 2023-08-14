int motor_1 = 5;
int motor_2 = 4;
int en = 3;

int a = 0;
int x;
int y;
int z;

void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, func, FALLING);
}

void func(){
  digitalWrite(motor_1, HIGH);
  digitalWrite(motor_2, HIGH);
}

void loop() {
  x = analogRead(14);
  y = analogRead(15);

  if (x > 700) {
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);
  } else if (x < 300) {
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, HIGH);
  }
  if (y < 300) {
    a += 1;
  } else if (y > 700) {
    a -= 1;
  }
  if (a > 255) {
    a = 255;
  }
  if (a < 0) {
    a = 0;
  }
  analogWrite(en, a);
}