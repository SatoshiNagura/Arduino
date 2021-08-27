//シリアル通信
/*
パソコンからはアスキーコードと呼ばれる文字データが送られる。
このアスキーデータから数値を取り出して計算する。
*/
char data_a = 0, data_b = 0, sum = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//ビットレートの設定
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    if(count == 0){
      data_a = Serial.read();//データを受信
      
      Serial.write("data_a = ");//データを送信
      Serial.write(data_a);
      Serial.write("\n");
      
      data_a &= 0x0F;//数値に変換
      count = 1;//1回目の受信終了
    }
    else{
      data_b = Serial.read();
      
      Serial.write("data_b = ");
      Serial.write(data_b);
      Serial.write("\n");

      data_b &= 0x0F;
      sum = data_a + data_b;//送られた数値の和をとる
      Serial.write("sum = ");
      Serial.write(sum | 0x30);//アスキーコードに変換して送信
      Serial.write("\n");      
    }
  }
}
