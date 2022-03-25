#pragma once

#include <Arduino.h>
#include "Memorable.hpp"
#include <ArduinoLog.h>

const int SIZE = 32; 

class Wifi : public Memorable {
private:
  char ssid[SIZE];
  char password[SIZE];

public:
  Wifi() {}

  Wifi(char ssid[], char password[]) {
    set_ssid(ssid);
    set_password(password);
  }

  void read() {
    EEPROM.readBlock<char>(Memory::WIFI_START, ssid, SIZE);
    EEPROM.readBlock<char>(Memory::WIFI_START + SIZE, password, SIZE);
  }
  void write() {
    EEPROM.writeBlock<char>(Memory::WIFI_START, ssid, SIZE);
    EEPROM.writeBlock<char>(Memory::WIFI_START + SIZE, password, SIZE);
  }

  String get_ssid() {
    return ssid;
  }

  void set_ssid(char ssid[]) {
    if (strlen(ssid) > 32) {
      Log.fatal(F("class WIFI | SID length must be %d max characters\n"),SIZE);
    } else {
      strcpy(this->ssid, ssid);
    }
  }

  String get_password() {
    
    return password;
  }

  void set_password(char password[]) {
    if (strlen(password) > 32) {
      Log.fatal(F("class WIFI | PASSWORD length must be %d max characters\n"), SIZE);
    } else {
      strcpy(this->password, password);
    }
  }

  void print() {
    Log.notice(F("class WIFI | ssid:  %s , password: %s \n"), ssid, password);
  }

};