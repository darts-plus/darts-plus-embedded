#pragma once

#include <Arduino.h>
#include "Memorable.hpp"
#include <ArduinoLog.h>

const int SIZE = 32; 

class MemorableWifi : public Memorable {
public:
  MemorableWifi() = default;

  MemorableWifi(char ssid[], char password[]);

  void read() override;
  void write() override;
  const char* get_ssid() const;
  void set_ssid(char new_ssid[]);
  const char* get_password() const;
  void set_password(char new_password[]);

  void print();
private:
  char ssid[SIZE];
  char password[SIZE];
};
