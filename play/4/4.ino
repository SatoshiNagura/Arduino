/*AD変換プログラム*/

#include<LiquidCrystal.h>

int data = 0;//AD変換したいデータ
float volt = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);//ディスプレイの表示列・行数の指定。
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();//ディスプレイ表示の初期化
  data = analogRead(1);//AD変換
  lcd.setCursor(0, 0);//カーソルの位置を指定
  lcd.print("A/D data=");
  lcd.print(data, DEC);//データを10進数で表示
  lcd.print(" ");
  
  volt = (float)data * 5 / 1023;//変換データから，入力電圧を求める。
  lcd.setCursor(0, 1);//カーソルを下の段へ
  lcd.print("V=");
  lcd.print(volt, DEC);
  delay(1000);
}
