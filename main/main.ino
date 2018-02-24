//#include <LiquidCrystal.h>
#include "ArduinoJson.h"

const size_t JSON_SIZE = 300;
StaticJsonBuffer<JSON_SIZE> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

class FridgeGenie
{
public:
  void run()
  {
    
  }
  void init()
  {
    
  }
  static FridgeGenie* instance()
  {
    
  }
  
  FridgeGenie(FridgeGenie const&) = delete;
  FridgeGenie& operator=(FridgeGenie const&) = delete;
private:
  FridgeGenie* m_p_instance = nullptr;
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

};

void setup()
{
  init();
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
//  root = jsonBuffer.createObject();
  
}
void loop()
{
  
}
