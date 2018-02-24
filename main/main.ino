//#include <LiquidCrystal.h>
#include "ArduinoJson.h"

const size_t JSON_SIZE = 300;
StaticJsonBuffer<JSON_SIZE> jsonBuffer;
JsonObject& root;

void setup()
{
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
  root = jsonBuffer.createObject();
}
void loop()
{
  
}
