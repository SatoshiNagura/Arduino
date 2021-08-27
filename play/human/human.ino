#define sensor 8
#define led 12

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensor)){//センサーが検知したらLEDが光り続ける
   delay(10);
   digitalWrite(led, 1);
  }
  else{//検知しなくなれば点滅するようになる。
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    delay(200);
  }
}
