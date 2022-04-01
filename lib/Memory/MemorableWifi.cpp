#include "MemorableWifi.hpp"

MemorableWifi::MemorableWifi(char new_ssid[], char new_password[]) {
    set_ssid(new_ssid);
    set_password(new_password);
  }

void MemorableWifi::load() {
  EEPROM.begin(SIZE * 2);
  for (int i = 0; i < SIZE; i++) {
    ssid[i] = EEPROM.read(i);
    password[i] = EEPROM.read(SIZE + i);
  }
}

void MemorableWifi::save() {
  EEPROM.begin(SIZE * 2);
  for (int i = 0; i < SIZE; i++) {
    EEPROM.write(i, ssid[i]);
    EEPROM.write(SIZE + i, password[i]);
  }
  if (EEPROM.commit()) {
    Log.infoln("class MemorableWifi | EEPROM successfully committed");
  } else {
    Log.fatalln("class MemorableWifi | ERROR! EEPROM commit failed");
  }
}

const char* MemorableWifi::get_ssid() const {
  return ssid;
}

void MemorableWifi::set_ssid(char new_ssid[]) {
  if (strlen(new_ssid) > 32) {
    Log.fatal(F("class MemorableWifi | SID length must be %d max characters\n"),SIZE);
  } else {
    strcpy(ssid, new_ssid);
  }
}

const char* MemorableWifi::get_password() const {
  return password;
}

void MemorableWifi::set_password(char new_password[]) {
  if (strlen(new_password) > 32) {
    Log.fatal(F("class MemorableWifi | PASSWORD length must be %d max characters\n"), SIZE);
  } else {
    strcpy(password, new_password);
  }
}

void MemorableWifi::print() {
  Log.notice(F("class MemorableWifi | ssid:  %s , password: %s \n"), ssid, password);
}