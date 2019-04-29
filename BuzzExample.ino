//BME66 DEMO CODE
#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  drv.begin();
  
  drv.selectLibrary(1);

  drv.setMode(DRV2605_MODE_INTTRIG); 
}

uint8_t effect = 16;

int potpin = 0;
int val;


void loop() {

  drv.setWaveform(0, effect);
  drv.setWaveform(1, 0);      

  val = analogRead(potpin); 
  val = map(val, 0, 1023, 1, 6);
  
  drv.go();

  delay(500 * val);
  Serial.print("Freq: ");
  Serial.print(500 * val);
  Serial.println(" ms");
}
