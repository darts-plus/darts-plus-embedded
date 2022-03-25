#pragma once

#include <EEPROMex.h>
#include <EEPROMVar.h>

namespace Memory {
  const int WIFI_START = 0x0;
}


class Memorable {
public:
  virtual void read() = 0;
  virtual void write() = 0;
};