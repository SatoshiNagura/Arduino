#define sensor 3
#define tone_out 8
#define mspb 500

void family(int pin){
  tone(pin, 743, mspb / 2);
  delay(260);
  tone(pin, 590, mspb / 2);
  delay(260);
  tone(pin, 442, mspb / 2);
  delay(260);
  tone(pin, 590, mspb / 2);
  delay(260);
  tone(pin, 662, mspb / 2);
  delay(260);
  tone(pin, 884, mspb / 2 * 3);
  delay(760);
  //小節の変わり目
  tone(pin, 662, mspb / 2);
  delay(260);
  tone(pin, 743, mspb / 2);
  delay(260);
  tone(pin, 662, mspb / 2);
  delay(260);
  tone(pin, 442, mspb / 2);
  delay(260);
  tone(pin, 590, mspb * 2);
  delay(1010);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(tone_out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensor)){
    delay(100);
    family(tone_out);
  }
}
