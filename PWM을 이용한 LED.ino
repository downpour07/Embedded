int a = 0;
int toggle = 1;

void setup()
{
  pinMode(6, OUTPUT);
}

void loop() 
{
  digitalWrite(6, HIGH);
  if (a > 255) 
  {
    toggle = 0;
  }
  else if(a < 0)
  {
    toggle = 1;
  }
  if(toggle)
  {
    a+=1;
  }
  else
  {
    a-=1;
  }
  for (int i = 0; i < 256; i++) 
  {
    if (i > a)
      digitalWrite(6, LOW);
    delayMicroseconds(20);
  }
}
