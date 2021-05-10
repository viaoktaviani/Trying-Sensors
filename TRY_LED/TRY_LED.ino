
int Led_Pin1 = 10, Led_Pin2 = 11, Led_Pin3 = 12;
//int ledstate=10, ledstate2=11, ledstate3=12 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode (Led_Pin1 = 10, OUTPUT);
  pinMode(Led_Pin2 = 11, OUTPUT);
  pinMode(Led_Pin3 = 12, OUTPUT);
//  pinMode (Led_Pin1 = 10, LOW);
//  pinMode(Led_Pin2 = 11, LOW);
//  pinMode(Led_Pin3 = 12, LOW);


}

void loop() {
 digitalWrite (Led_Pin3,HIGH);
 
 
  if (Serial.available()){
    char LED = Serial.read();
    if (LED == 'a')
    {
      digitalWrite (Led_Pin1, HIGH);
       Serial.print(LED);
        Serial.println();}

    else if (LED == 'b')
      digitalWrite (Led_Pin2, HIGH);

    else if (Serial.read() == 'c') {
      digitalWrite (Led_Pin3, HIGH);
       Serial.print(Led_Pin3);
        Serial.println();
    }
    
    else if (Serial.read() == 'd')
       digitalWrite (Led_Pin1,LOW);
      digitalWrite (Led_Pin2,LOW);
      digitalWrite (Led_Pin3,LOW);
  }

}
