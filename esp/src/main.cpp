#include <Arduino.h>
#include <EEPROMWearLevel.h>

void setup() {
  Serial.begin(9600);
  EEPROMwl.begin(0, 2);
  // write
  EEPROMwl.update(0, 12);
  long var2 = 33333;
  EEPROMwl.put(1, var2);

  // read
  byte var1 = EEPROMwl.read(0);
  Serial.print(F("var1: "));
  Serial.println(var1);

  long var3 = -1;
  EEPROMwl.get(1, var3);
  Serial.print(F("var2: "));
  Serial.println(var3);
}

void loop() {
}
