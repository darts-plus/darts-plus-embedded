#include <EEPROMex.h>
#include <EEPROMVar.h>

void setup()
{
  Serial.begin(9600); 
  delay(100); 
  EEPROMVar<float> eepromFloat(5.5);
  EEPROMVar<double> eepromDouble(1.33356);
  EEPROMVar<char> eepromChar('H');
  eepromFloat.save(); 
  eepromDouble.save();
  eepromChar.save();
  Serial.println(eepromFloat.getAddress());
  Serial.println(eepromDouble.getAddress());
  Serial.println(eepromChar.getAddress());
  Serial.println(eepromFloat);
  Serial.println(eepromDouble);
  Serial.println(eepromChar);
}

void loop()
{

}