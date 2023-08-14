int clockPin = 6;
int latchPin = 5;
int dataPin = 4;
int a = 0;
int arr[8] = {1,0,1,0,1,0,1,0};
int brr[8] = {0,1,0,1,0,1,0,1};

void func(int x)
{
  digitalWrite(clockPin, LOW);
  if(a)
  {
    digitalWrite(dataPin, arr[x]);
  }
  else
  {
    digitalWrite(dataPin, brr[x]);
  }
  digitalWrite(clockPin, HIGH);
}

void reset() {
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, HIGH);
}

void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
}

void loop() {
  for(int i = 0; i<8; i++)
  {
    func(i);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(500);
  }
  a = !a;
  for(int i = 0; i<8; i++)
  {
    reset();
  }
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  delay(500);
}
