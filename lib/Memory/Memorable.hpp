#pragma once

#include <EEPROM.h>

class Memorable {
public:
  virtual void load() = 0;
  virtual void save() = 0;
};