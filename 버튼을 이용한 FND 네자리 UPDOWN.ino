int pins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int arr[10][8] = {
  { 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 1, 1, 1, 1, 1 },
  { 0, 0, 1, 0, 0, 1, 0, 1 },
  { 0, 0, 0, 0, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 0, 1, 0, 0, 1, 0, 0, 1 },
  { 0, 1, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 1, 0, 0, 1 }
};

void setup() {
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
}

void func(int a) {
  int index[4];
  for (int i = 3; i >= 0; i--) {
    index[i] = a % 10;
    a = a / 10;
  }
  for (int j = 10; j < 14; j++) {
    for (int i = 10; i < 14; i++) {
      digitalWrite(i, LOW);
    }
    digitalWrite(j, HIGH);
    for (int i = 0; i < 8; i++) {
      digitalWrite(pins[i], arr[index[j % 10]][i]);
    }
    delay(1);
  }
}

int cnt = 0;
int result = 0;
int mode = 1;
unsigned long long int now_time = 0;
int bb = 0;

void loop() {
  int b = digitalRead(A0);
  if (!b) {
    if (!bb) {
      mode = !mode;
      bb = 1;
    }
  } else {
    bb = 0;
  }
  if (millis() - now_time >= 1000) {
    now_time = millis();
    if (mode) {
      result++;
    } else {
      result--;
    }
  }

  if (60 == result) {
    result = 100;
  }
  else if(result == 10000)
  {
    result = 0;
  }
  func(result);
}