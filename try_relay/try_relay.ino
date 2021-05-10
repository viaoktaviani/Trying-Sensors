int relay=27;
int outputrelay;

void setup() {
Serial.begin(9600);
pinMode (outputrelay,OUTPUT);
  
}

void loop() {
digitalWrite(outputrelay, HIGH);
delay(5000);
digitalWrite(outputrelay, LOW);
delay(5000);
}
