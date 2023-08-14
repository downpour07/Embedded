#include<Servo.h>

Servo servo;

void setup() {
  pinMode(7, OUTPUT);
  servo.attach(7);
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(179);
  delay(1000);
}
