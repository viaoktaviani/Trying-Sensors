int Buzzer= 14;

void setup() {
pinMode(Buzzer,OUTPUT);
}

void loop() {
digitalWrite (14,HIGH);
delay(50);
digitalWrite(14,LOW);
delay(50);
}
