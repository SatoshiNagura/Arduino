#include <DS3232RTC.h>
#define pin_turb 1

//諸変数の定義
time_t t;//時刻のクラス(?)，構造体(?)
float turb_ave = 0;

//諸関数の宣言
void serial_setting();//(1)
void rtc_initial();//(2)
time_t compileTime();//(3)
void Average_Turbility(float *Average);//(4)

void setup(){
  serial_setting();//(1)
  rtc_initial();//(2)
  //アラームを設定
  RTC.setAlarm(ALM1_EVERY_SECOND, 0, 0, 0, 0);
  RTC.alarm(ALARM_1);
}

void loop(){
  if(RTC.alarm(ALARM_1)){
    Average_Turbility(&turb_ave);//(4)
    Serial.println(turb_ave);
  }
  delay(10);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//シリアル通信の初期設定をする関数  (1)
void serial_setting(){
  Serial.begin(9600);//シリアル通信の通信速度を決定
  while(!Serial);//シリアル通信の準備が出来るまで待機
  Serial.println("Hello!");//準備完了
}

//RTCモジュールの初期設定をする関数  (2)
void rtc_initial(){
  RTC.set(compileTime());//RTCモジュールにコンパイル時刻を同期させる (3)
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

//コンパイルした時間を記憶する関数（./.../alarm_ex.inoより引用） (3)
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

//濁度をアナログ値で読み取って平均値を出力するプログラム　(4)
void Average_Turbility(float *Average){
  *Average = 0.0;//出力する平均値の初期化
  int i, N = 10;//繰り返し数を定義
  for(i = 0; i < N; i++){//10回分の平均値とする
    *Average += (float)analogRead(pin_turb);
  }
  *Average /= N;
}
