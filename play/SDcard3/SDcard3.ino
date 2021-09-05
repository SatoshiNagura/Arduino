/*
SDカードに読み込んだ濁度を記録するプログラム
また，容量が一定以上になれば異なるファイルを作成してそちらに保存するようにする
*/
#include <SD.h>
#include <SPI.h>
#include <DS3232RTC.h>
#define pin_turb 1

//諸変数を定義
const int sdcs = 4;
File f_out;//濁度を記録するファイル
float turb_ave;//濁度(10回平均)の値

//諸関数を定義
void serial_setting();//(1)
void sd_setting();//(2)
void rtc_initial();//(3)
time_t compileTime();//(4)
void Average_Turbility(float *Average);//(5)
///////////////////////////////
///////////////////////////////
void setup(){
  serial_setting();//シリアル通信の開始
  sd_setting();//SDカードの書き込み準備
  rtc_initial();//RTCの開始
}
void loop(){

}
////////////////////////////////
////////////////////////////////
//シリアル通信の初期設定をする関数  (1)
void serial_setting(){
  Serial.begin(9600);//シリアル通信の通信速度を決定
  while(!Serial);//シリアル通信の準備が出来るまで待機
  Serial.println("Serial Start!");//準備完了
}

//SDカードの初期設定  (2)
void sd_setting(){
  while(!SD.begin(sdcs));
  Serial.println("SD start!");
  f_out = SD.open("sample1.csv", FILE_WRITE);
  while(!f_out);
  Serial.println("sample1.csv Start!");
  f_out.printf("time,turbility\n");
}

//RTCモジュールの初期設定 (3)
void rtc_initial(){
  RTC.set(compileTime());//RTCモジュールにコンパイル時刻を同期させる (4)
  setSyncProvider(RTC.get);//RTCモジュールから時刻を取得
  if(timeStatus() != timeSet){//取得した時刻とarduinoの時刻が異なれば失敗を表示。
    Serial.println("×");
  }
  else{
    Serial.println(now());
  }
  //アラーム機能の初期無効化
  RTC.setAlarm(ALM1_MATCH_DATE, 0, 0, 0, 1);
  RTC.setAlarm(ALM2_MATCH_DATE, 0, 0, 0, 1);
  RTC.alarm(ALARM_1);
  RTC.alarm(ALARM_2);
  RTC.alarmInterrupt(ALARM_1, false);//アラーム無効
  RTC.alarmInterrupt(ALARM_2, false);
  RTC.squareWave(SQWAVE_NONE);//pinへsqwの入力を無効
}

//コンパイルした時間を記憶する関数（./.../alarm_ex.inoより引用） (4)
// function to return the compile date and time as a time_t value
time_t compileTime(){
    const time_t FUDGE(10);    //fudge factor to allow for upload time, etc. (seconds, YMMV)
    const char *compDate = __DATE__, *compTime = __TIME__, *months = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char compMon[4], *m;

    strncpy(compMon, compDate, 3);
    compMon[3] = '\0';
    m = strstr(months, compMon);

    tmElements_t tm;
    tm.Month = ((m - months) / 3 + 1);
    tm.Day = atoi(compDate + 4);
    tm.Year = atoi(compDate + 7) - 1970;
    tm.Hour = atoi(compTime);
    tm.Minute = atoi(compTime + 3);
    tm.Second = atoi(compTime + 6);

    time_t t = makeTime(tm);
    return t + FUDGE;        //add fudge factor to allow for compile time
}

//濁度をアナログ値で読み取って平均値を出力するプログラム　(5)
void Average_Turbility(float *Average){
  *Average = 0.0;//出力する平均値の初期化
  int i, N = 10;//繰り返し数を定義
  for(i = 0; i < N; i++){//10回分の平均値とする
    *Average += (float)analogRead(pin_turb);
  }
  *Average /= N;
}
