#include "MemorableWifi.hpp"

void setup()
{
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);

  MemorableWifi wifi("TestSSID", "TESTPASSWORD"); // wifi constuctor
  wifi.write(); // write ssid & password to EEPROM

  MemorableWifi wifiTEST; // create empty class
  wifiTEST.read(); // read ssid & password from EEPROM
  wifiTEST.print(); // print information about readed wifi
}

void loop()
{

}