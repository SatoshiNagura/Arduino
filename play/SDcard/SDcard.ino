#include <SD.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;
const int cspin = 4;
/*
void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Serial Start.");
  if(!card.init(SPI_HALF_SPEED, cspin)){
    Serial.println("Failed.");
  }
  else{
    Serial.println("Successed.");
  }
  Serial.println();
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
}*/

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Serial Start.");
  while(SD.begin(cspin));
  Serial.println("SD card.");
}

void loop(){}
