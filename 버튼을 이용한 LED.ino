void setup() {
  pinMode(11, INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(6,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  int a = digitalRead(11);
  int b = digitalRead(10);
  if(a == 1)
  {
    digitalWrite(13, LOW);
  }
  else if(a == 0)
  {
    digitalWrite(13, HIGH);
  }
  if(b==1)
  {
    digitalWrite(6, LOW);
  }
  else if(b==0)
  {
    digitalWrite(6, HIGH);
  }
}
