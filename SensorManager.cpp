#include "SensorManager.h"

SensorManager::SensorManager(uint8_t pin, uint8_t type, LiquidCrystal_I2C* lcdPtr, float voltage) : _dht(pin, type), _lcd(lcdPtr) {

  _pin = pin;
  _voltage = voltage;

}

void SensorManager::printInfo() {

  _lcd->setCursor(0, 0);
  _lcd->print("Pin:");
  _lcd->print(_pin);
  _lcd->setCursor(0,1);
  _lcd->print("Volt:");
  _lcd->print(_voltage);
  _lcd->print("Hello!");

}

void SensorManager::updateDisplay() {

  _lcd->setCursor(0, 0);
  _lcd->print("Temp: ");
  _lcd->print(readTemperature());
  _lcd->print("C    ");

  _lcd->setCursor(0, 1);
  _lcd->print("Hum:  ");
  _lcd->print(_dht.readHumidity());
  _lcd->print("%    ");

}

void SensorManager::begin() {
  _dht.begin();
  _lcd->init();
  _lcd->backlight();
}


float SensorManager::readTemperature() {
  _lastTemp = _dht.readTemperature();
  return _lastTemp;
}