int motor_1 = 5;
int motor_2 = 4;
int en = 3;
int type = 1;
int a = 0;

void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(en, OUTPUT);
}

void loop() {
  digitalWrite(motor_1, HIGH);
  digitalWrite(motor_2, LOW);
  digitalWrite(en, HIGH);  
  if(a > 255)
  {
    type = 0;
  }
  else if(a < 0)
  {
    type = 1;
  }
  if(type)
  {
    a+=1;
  }
  else
  {
    a-=1;
  }
  for(int i = 0; i<256; i++)
  {
    if(i>a)
    {
      digitalWrite(en, LOW);
    }
    delayMicroseconds(50);
  }
}