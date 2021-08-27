#include <Servo.h>
/*
attach(ピン番号)
・役割
Servo関数を使うピンを設定する
・使い方
Servo myservo;
myservo.attach(3);

write(角度)
・役割
角度（0~180°）に応じたPWM制御を実行する。
イメージは指定した角度までPWMをし続ける。
・使い方
myservo.write(0);
myservo.write(180);
*/

Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
  delay(1000);//delayがないと，読み込み速度に対してモータの速度が追いつかなくて，誤作動を起こす。
  myservo.write(120);
  delay(1000);
}
