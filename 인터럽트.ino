bool flag = true;

void setup(){
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  attachInterrupt(0,func,FALLING);
}

void loop(){
  digitalWrite(13,flag);
}

void func(){
  flag = !flag;
}