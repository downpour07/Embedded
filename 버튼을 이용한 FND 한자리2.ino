int pins[8] = {2,3,4,5,6,7,8,9};
int arr[10][8] = {
  {0,0,0,0,0,0,1,1},
  {1,0,0,1,1,1,1,1},
  {0,0,1,0,0,1,0,1},
  {0,0,0,0,1,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,1,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,0,0,1,1,0,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,1,0,0,1}
};

void setup() {
  pinMode(11, INPUT);
  for(int i = 0; i<9; i++)
  {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
}

int b = 0;
int j = 0;

void loop() {
  b = digitalRead(11);
  if(1)
  {
    for(int i = 0; i<8; i++)
    {
      digitalWrite(pins[i], (arr[j][i]));
    }
    if(!b)
    {
      j = j;
    }
    else
    {
      j++;
      if(j==10)
      {
        j = 0;
      }
    }
    delay(1000);
  }
}