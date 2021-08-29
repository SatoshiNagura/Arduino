#include <DS3232RTC.h>

//pin番号の定義
#define SQW_pin 2

//諸変数の定義
volatile bool caughtAlarm = false;
int alarmCout = 0;

void serial_setting();//(1)
void time_setting();//(2)

void setup(){
  serial_setting();//(1)
  time_setting();//(2)
}

void loop(){
}

//シリアル通信の初期設定をする関数  (1)
void serial_setting(){
  Serial.begin(9600);//シリアル通信の通信速度を決定
  while(!Serial);//シリアル通信の準備が出来るまで待機
  Serial.println("Hello!");//準備完了
}

//RTCモジュールの初期設定をする関数  (2)
void time_setting(){
  setTime(14, 00, 00, 29, 8, 2021);//Arduinoに現在時刻を打ち込む
  RTC.set(now());//RTCモジュールに時刻を同期させる
  setSyncProvider(RTC.get);//RTCモジュールから時刻を取得
  if(timeStatus() != timeSet){//取得した時刻とarduinoの時刻が異なれば失敗を表示。
    Serial.println("×");
  }
  else{
    Serial.println(now());
  }
}
