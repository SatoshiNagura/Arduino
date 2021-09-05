#define light 2//LEDのpinの番号
#define switch_on 7 //LEDをonにするスイッチ
#define switch_off 8 //LEDをoffにするスイッチ

volatile int i = 0;

/*
void func_on(){
  noInterrupts();//割り込み停止
  i = 1;
  interrupts();//割り込み開始
}*/
void func_off(){
  delay(10);
  i = 1;
  Serial.println("Hello");
}


void setup() {
  pinMode(switch_on, INPUT);
  pinMode(light, OUTPUT);
  Serial.begin(9600);
  /*
  pinMode(switch_off, INPUT);
  //pin番号（実際のピン番号の認識をさせるための関数を使用），割り込み時に呼び出される関数，割り込みが発生するトリガーを引数に取る。
  attachInterrupt(digitalPinToInterrupt(switch_off), func_on, FALLING);*/
  attachInterrupt(digitalPinToInterrupt(switch_on), func_off, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(light, i);
  delay(1);
}
