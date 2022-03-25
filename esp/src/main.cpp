#include "Wifi.hpp"

void setup()
{
  Wifi wifi("PLAY-LTE-2020", "H&@#$DSFSDF!@#!@!@");
  wifi.write();

  Wifi test;
  test.read();
  test.print();
}

void loop()
{

}