void setup(){
  Serial.begin(9600);
}

void loop(){
  int Sensor_value = analogRead(1);
  Serial.println(Sensor_value);
  delay(1000);
}
