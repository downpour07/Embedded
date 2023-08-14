int latchPin = 5;

int clockPin = 6;
int dataPin = 4;

byte leds = 0; // LED 출력 패턴을 저장

void setup()
{
  // 74HC595 제어용 핀 3개 세팅
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  leds = 0; // LED 모두 OFF

  updateShiftRegister(); // LED OFF 출력

  delay(500);

  for (int i = 0; i < 8; i++)
  {
    // LED를 하나씩 점등
    bitSet(leds, i); 
    updateShiftRegister();

    delay(500);
  }
}

// 래치핀을 OFF 한 후에 데이터핀을 통해 데이터를 쓰고 다시 래치핀을 ON
// 데이터핀과 클럭핀 제어는 아두이노 내장함수 shiftOut() 함수를 사용
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
