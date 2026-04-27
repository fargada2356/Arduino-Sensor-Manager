#include <Arduino.h>
#include "SensorManager.h"


LiquidCrystal_I2C myLcd(0x27, 16, 2);


SensorManager sensor(2, 11, &myLcd, 5.0, "fargada2356-github");

void setup() {
  myLcd.init();
  myLcd.backlight();
  Serial.begin(9600);
  sensor.begin(); 
  sensor.printInfo();
}

unsigned long lastUpdate = 0;
const long interval = 2000;


void loop() {
  sensor.updateDisplay();
  unsigned long currentMillis = millis();
  if(currentMillis - lastUpdate >= interval) {
    lastUpdate = currentMillis;

    float t = sensor.readTemperature();
    Serial.println(t);
  }
  
}
