#pragma once

class Memorable {
protected:
  virtual void write() = 0;
  virtual int read() = 0;

  int getAdress() { return adress; }

  template<class T>
  void nextAdress(T var) {
    adress += sizeof(T);
  }
private:
  inline static int adress = 0;
};