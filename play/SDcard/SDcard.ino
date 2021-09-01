#include <SD.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;
const int cspin = 4;
uint32_t volumesize;

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
  while(!SD.begin(cspin));
  Serial.println("Hello SD Card.");
  */
  //SDクラスの中のSd2Cardクラスを使った呼び出し
  while(!card.init(SPI_HALF_SPEED, cspin));
  Serial.print("Card type: ");

  //SDカードの種類を出力
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

    //SDカードのパーティションの形式を出力
    //SDカードのパーティションがFAT16,32で規定されていないとはじかれる
    while(!volume.init(card));
    Serial.print("volume type is FAT");
    Serial.println(volume.fatType(), DEC);
    Serial.print("Clusters: ");
    volumesize = volume.clusterCount();
    Serial.println(volumesize);
    Serial.print("Blocks x Cluster: ");
    volumesize = volume.blocksPerCluster();
    Serial.println(volumesize);
    Serial.print("Total Blocks: ");
    volumesize *= volume.clusterCount();
    Serial.println(volumesize);

    //SDカードの容量を出力
    volumesize /= 2;//2blockで1KByte
    Serial.print("volume size (KB): ");
    Serial.println(volumesize);
    volumesize /= 1024;
    Serial.print("volume size (MB): ");
    Serial.println(volumesize);
    volumesize /= 1024;
    Serial.print("volume size (GB): ");
    Serial.println(volumesize);

    //SDカードの中身について出力するプログラム
    root.openRoot(volume);
    root.ls(LS_R | LS_DATE | LS_SIZE);
    root.close();
}
