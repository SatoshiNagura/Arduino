#include <SD.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;
const int cspin = 4;

void serial_setting();//(1)
void sd_setting();//(2)

void setup(){
  serial_setting();//(1)
  sd_setting();//(2)
}

void loop(){}
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

//(1) シリアル通信の初期設定
void serial_setting(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Serial Start.");
}

//(2) sdカードの初期設定
void sd_setting(){
  /*begin()関数を使った呼び出し
  while(SD.begin(cspin));
  Serial.println("Hello SD Card.");
  */
  //SDクラスの中のSd2Cardクラスを使った呼び出し
  while(!card.init(SPI_HALF_SPEED, cspin));
  Serial.println("Successed.");
  Serial.print("Card type: ");
  switch(card.type()){
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1.");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2.");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC.");
      break;
    default:
      Serial.println("Unknown.");
}
