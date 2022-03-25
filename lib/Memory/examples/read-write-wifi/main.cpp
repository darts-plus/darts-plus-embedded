#include "Wifi.hpp"

void setup()
{
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);

  Wifi wifi("TestSSID", "TESTPASSWORD"); // wifi constuctor
  wifi.write(); // write ssid & password to EEPROM

  Wifi wifiTEST; // create empty class
  wifiTEST.read(); // read ssid & password from EEPROM
  wifiTEST.print(); // print information about readed wifi
}

void loop()
{

}