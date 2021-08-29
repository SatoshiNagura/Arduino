#include "RTClib.h"

RTC_DS3231 RTC;

void setup() {
  RTC.begin();
  RTC.adjust(DateTime(2021, 8, 25, 16, 27, 30));
  Serial.begin(9600);
  Serial.println("Hello!");
  pinMode(8, OUTPUT);
}

int day, hour, minute, second;
DateTime now;

void loop() {
  now = RTC.now();
  day = now.day();
  hour = now.hour();
  minute = now.minute();
  second = now.second();
  
  if(second%10 == 0){
    Serial.println(now.unixtime() / 86400L);
    digitalWrite(8, 1);
  }
  else{
    digitalWrite(8, 0);
  }
  delay(991);
}
