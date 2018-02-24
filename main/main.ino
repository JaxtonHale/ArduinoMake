//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"

class ArduinoInput
{
public:

private:
  
};

class ArduinoOutput
{
public:
  
private:

};

void setup()
{
  //init();
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
//  root = jsonBuffer.createObject();
  
}
void loop()
{
  FridgeGenie::instance()->run();
}
