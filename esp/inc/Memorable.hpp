#pragma once

#include <EEPROMex.h>
#include <EEPROMVar.h>

const int START = 0;
const int SIZE = 32;

class Memorable {
public:
  virtual void read();
  virtual void write();
};