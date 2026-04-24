#include <Arduino.h>
#include "SensorManager.h"


LiquidCrystal_I2C myLcd(0x27, 16, 2);

SensorManager sensor(2, 11, &myLcd, 5.0);

void setup() {
  Serial.begin(9600);
  sensor.begin(); // izpolzvame "->" zashtoto e ukazatel
  sensor.printInfo();
}

unsigned long lastUpdate = 0;
const long interval = 2000;


void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - lastUpdate >= interval) {
    lastUpdate = currentMillis;
  
  sensor.updateDisplay();
  
  float t = sensor.readTemperature();
  Serial.println(t);
  }
}
