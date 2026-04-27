#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <DHT.h>
#include <LiquidCrystal_I2C.h>

class SensorManager {

  private:

      DHT _dht; // dolnata cherta e za orientaciq che e private promenliva
      float _lastTemp;
      LiquidCrystal_I2C* _lcd;
      uint8_t _pin; // tip za pin
      float _voltage; // tip za voltaj 5000 milivolta ~ 5 volta
      uint8_t _displayMode = 0; // 0 = Температура, 1 = Влажност
      unsigned long _lastModeSwap = 0; // Кога последно сме сменили екрана
      unsigned long _swapInterval = 3000; // Сменяме на всеки 3 секунди
      String _githubUser = "fargada2356";



  public:
  
      SensorManager(uint8_t pin, uint8_t type, LiquidCrystal_I2C* lcdPtr, float voltage, String user);
      void begin();
      void printInfo();
      void updateDisplay();
      float readTemperature();

};


#endif 