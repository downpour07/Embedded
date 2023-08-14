void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
int cnt = 0;
long long int now_time;
void loop() {
  Serial.println("home");
  if(millis() - now_time >= 500)
  {
    now_time = millis();
    if(cnt)
    {
      digitalWrite(13, HIGH);
      cnt = 0;
    }
    else
    {
      digitalWrite(13, LOW);
      cnt = 1;
    }
  }
}