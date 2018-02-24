//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"



//JsonObject& root = jsonBuffer.createObject();
/*
class FridgeGenie
{
public:
  FridgeGenie()
  {

  }
  void run()
  {
    
  }
  static FridgeGenie* instance()
  {
    if (m_p_instance == nullptr)
    {
      m_p_instance = new FridgeGenie(); 
    }
    return m_p_instance;
  }
  
  FridgeGenie(FridgeGenie const&) = delete;
  FridgeGenie& operator=(FridgeGenie const&) = delete;
  
private:
  static FridgeGenie* m_p_instance;
};
*/
//FridgeGenie* FridgeGenie::m_p_instance = nullptr;

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
  FridgeGenie::instance();
}
