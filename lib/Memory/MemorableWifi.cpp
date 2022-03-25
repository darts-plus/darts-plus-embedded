#include "MemorableWifi.hpp"

MemorableWifi::MemorableWifi(char new_ssid[], char new_password[]) {
    set_ssid(new_ssid);
    set_password(new_password);
  }

void MemorableWifi::read() {
  EEPROM.readBlock<char>(Memory::WIFI_START, ssid, SIZE);
  EEPROM.readBlock<char>(Memory::WIFI_START + SIZE, password, SIZE);
}

void MemorableWifi::write() {
  EEPROM.writeBlock<char>(Memory::WIFI_START, ssid, SIZE);
  EEPROM.writeBlock<char>(Memory::WIFI_START + SIZE, password, SIZE);
}

const char* MemorableWifi::get_ssid() const {
  return ssid;
}

void MemorableWifi::set_ssid(char new_ssid[]) {
  if (strlen(new_ssid) > 32) {
    Log.fatal(F("class WIFI | SID length must be %d max characters\n"),SIZE);
  } else {
    strcpy(ssid, new_ssid);
  }
}

const char* MemorableWifi::get_password() const {
  return password;
}

void MemorableWifi::set_password(char new_password[]) {
  if (strlen(new_password) > 32) {
    Log.fatal(F("class WIFI | PASSWORD length must be %d max characters\n"), SIZE);
  } else {
    strcpy(password, new_password);
  }
}

void MemorableWifi::print() {
  Log.notice(F("class WIFI | ssid:  %s , password: %s \n"), ssid, password);
}