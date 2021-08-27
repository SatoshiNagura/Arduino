void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == 1){
    delay(100);
    digitalWrite(7, 1);
  }
  else{
    digitalWrite(7, 0);
  }
}
