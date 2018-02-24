//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"

void setup()
{
  //init();
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
//  root = jsonBuffer.createObject();
  
}
void loop()
{
  FridgeGenie::instance()->run();
  delay(200);
}
