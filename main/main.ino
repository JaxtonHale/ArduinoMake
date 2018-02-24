//#include <LiquidCrystal.h>
#include "ArduinoJson.h"

const size_t JSON_SIZE = 300;
StaticJsonBuffer<JSON_SIZE> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

class FridgeGenie
{
public:
  void run();
private:
  
};

class ArduinoInput
{
public:

private:
  
};

class ArduinoOutput
{
public:

private:

}

void setup()
{
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
//  root = jsonBuffer.createObject();
  
}
void loop()
{
  
}
