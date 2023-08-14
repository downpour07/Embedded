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
  for(int i = 0; i<9; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

int a = 0;
int toggle = 1;
int j = 0;

void FND_HIGH()
{
  for(int i = 0; i<8; i++)
  {
    digitalWrite(pins[i], (arr[j][i]));
  }
}

void FND_LOW()
{
  for(int i = 0; i<8; i++)
  {
    digitalWrite(pins[i], HIGH);
  }
}

void loop() {
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
  for (int k = 0; k < 256; k++) 
  {
    if (k > a)
    {
      FND_HIGH();
23    }
    delayMicroseconds(20);
  }
}