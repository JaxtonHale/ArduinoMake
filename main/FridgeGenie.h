#ifndef FRIDGE_GENIE_H
#define FRIDGE_GENIE_H

#include "ArduinoJson.h"

const size_t JSON_SIZE = 300;

class FridgeGenie
{
public:
  FridgeGenie();
  ~FridgeGenie();
  
  void run();
  static FridgeGenie* instance();

  FridgeGenie(FridgeGenie const&) = delete;
  FridgeGenie& operator=(FridgeGenie const&) = delete;
private:
   static FridgeGenie* m_p_instance;
   
   StaticJsonBuffer<JSON_SIZE> m_jsonBuffer;
   JsonObject& m_json;
};

#endif
