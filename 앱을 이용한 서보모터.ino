#include<Servo.h>
#include<SoftwareSerial.h>

//RX = 9, TX = 8
SoftwareSerial bluetooth(8, 9);
Servo servo;

void setup() {
  bluetooth.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  servo.attach(7);
}
hnr
int mode = 0;

void loop() {
  if(bluetooth.available())
  {
    int a = bluetooth.read();
    if(a == 49)
    {
      servo.write(179);
    }
    else if(a == 48)
    {
      servo.write(0);
    }
    delay(1000);
  }
}