#include "HX711.h"
#define DOUT  A0
#define CLK  A1
HX711     scale(DOUT, CLK);
float     calibration_factor = 247.60;
int       GRAM=0 ;
int       LedPin1_Ok =12,LedPin2_Pas= 11,LedPin3_Over=10;

void setup() {
  Serial.begin(9600);
  scale.tare();
  scale.set_scale();
  pinMode (LedPin1_Ok,OUTPUT);
  pinMode (LedPin2_Pas,OUTPUT);
  pinMode (LedPin3_Over,OUTPUT);
}

void loop() {
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units(),0;
  Serial.println(GRAM);
  LoadCell_Measure();
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
