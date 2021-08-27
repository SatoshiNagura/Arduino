#define pin_out 13
#define mspb 700


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(pin_out, 442, mspb / 2);
  delay(360);
  tone(pin_out, 351, mspb / 2);
  delay(360);
  tone(pin_out, 263, mspb / 2);
  delay(360);
  tone(pin_out, 351, mspb / 2);
  delay(360);
  tone(pin_out, 394, mspb / 2);
  delay(360);
  tone(pin_out, 526, mspb / 2 * 3);
  delay(1060);
  //小節の変わり目
  tone(pin_out, 394, mspb / 2);
  delay(360);
  tone(pin_out, 442, mspb / 2);
  delay(360);
  tone(pin_out, 394, mspb / 2);
  delay(360);
  tone(pin_out, 263, mspb / 2);
  delay(360);
  tone(pin_out, 351, mspb * 2);
  delay(1410);
  //終わり
}
