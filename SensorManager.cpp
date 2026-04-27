#include "SensorManager.h"

SensorManager::SensorManager(uint8_t pin, uint8_t type, LiquidCrystal_I2C* lcdPtr, float voltage, String user) : _dht(pin, type), _lcd(lcdPtr), _githubUser(user) {

  _lcd = lcdPtr;
  _githubUser = user;
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

  unsigned long currentMillis = millis();

  // proverka dali e vreme za smqna na ekran
  if (currentMillis - _lastModeSwap >= _swapInterval) {
    _lastModeSwap = currentMillis;
    _displayMode++;
    if(_displayMode > 2) _displayMode = 0; // vrushtame nachalo
    _lcd->clear(); // tuk e edinstvenoto mqsto, kudeto chistim, zashtoto smenqme celiqt kontekst
  }

  _lcd->setCursor(0, 0);
  if(_displayMode == 0) {
  _lcd->print("----- TEMP -----");
  _lcd->setCursor(0, 1);
  _lcd->print("Value: ");
  _lcd->print(readTemperature());
  _lcd->print(" C");
  }
  else if (_displayMode == 1) {
  _lcd->print("----- HUMID -----");
  _lcd->setCursor(0, 1);
  _lcd->print("Value: ");
  _lcd->print(_dht.readHumidity());
  _lcd->print(" %");
  }
  else if(_displayMode == 2) {
  _lcd->setCursor(0, 0);
  _lcd->print("Dev: ");
  _lcd->print(_githubUser);
  _lcd->setCursor(0, 1);
  _lcd->print("Status: Coding");
  }
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