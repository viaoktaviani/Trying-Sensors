#include "HX711.h"
#define DOUT  A0
#define CLK  A1
HX711 scale(DOUT, CLK);
float calibration_factor = 247.60;
int GRAM = 0;
int LedPin1_Ok =12,LedPin2_Pas= 11,LedPin3_Over=10;

void setup() {
  Serial.begin(9600);
  Serial.println("tekan a,s,d,f untuk menaikan calibration_factor ke 10,100,1000,10000");
  Serial.println("tekan z,x,c,v untuk menurunkan calibration_factor ke 10,100,1000,10000");
  Serial.println("Tekan T untuk Tare");
  scale.set_scale();
  scale.tare();
  long zero_factor = scale.read_average();
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  delay(1000);
}

void loop() {
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units(), 2;
  Serial.print("Reading: ");
  Serial.print(GRAM);
  Serial.print(" Gram");
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  LoadCell_Measure();

  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a')
      calibration_factor += 0.1;
    else if (temp == '-' || temp == 'z')
      calibration_factor -= 0.1;
    else if (temp == 's')
      calibration_factor += 10;
    else if (temp == 'x')
      calibration_factor -= 10;
    else if (temp == 'd')
      calibration_factor += 100;
    else if (temp == 'c')
      calibration_factor -= 100;
    else if (temp == 'f')
      calibration_factor += 1000;
    else if (temp == 'v')
      calibration_factor -= 1000;
    else if (temp == 't')
      scale.tare();
  }
}

void LoadCell_Measure()
{
  if ((GRAM >= 0)&&(GRAM<=1500)); digitalWrite (LedPin1_Ok,HIGH);
  if((GRAM >1500)&&(GRAM<=2000)){
    digitalWrite (LedPin1_Ok,LOW);
    digitalWrite (LedPin2_Pas,!digitalRead (LedPin2_Pas));
  }
  if (GRAM >2000); digitalWrite (LedPin3_Over,!digitalRead (LedPin3_Over));
  
}
