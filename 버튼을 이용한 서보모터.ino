#include<Servo.h>
#include<SoftwareSerial.h>

Servo servo;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  servo.attach(7);
}

int mode = 0;
int b = 0;

void loop() {
  b = digitalRead(6);
  if(!b)
  {
    mode = !mode;
  }
  if(mode)
  {
    servo.write(179);
  }
  else
  {
    servo.write(0);
  }
  delay(1000);
}