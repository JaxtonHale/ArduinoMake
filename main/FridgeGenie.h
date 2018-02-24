#ifndef FRIDGE_GENIE_H
#define FRIDGE_GENIE_H

#include "ArduinoJson.h"
#include "ArduinoIO.h"

const size_t JSON_SIZE = 300;

class FridgeGenie
{
public:
//constructor
  FridgeGenie();

//destructor (ideally prevents memory leak)
  ~FridgeGenie();

  //runs bunch of other functions. put in arduino loop
  void run();

  //this is part of the singleton implementation
  static FridgeGenie* instance();

//we don't want these functions to be used so we delete them (part of singleton implementation)
  FridgeGenie(FridgeGenie const&) = delete;
  FridgeGenie& operator=(FridgeGenie const&) = delete;
private:
//part of the singleton implementation
   static FridgeGenie* m_p_instance;

   //buffer for the json (see FridgeGenie constructor)
   StaticJsonBuffer<JSON_SIZE> m_jsonBuffer;
   //json object (see FridgeGenie constructor)
   JsonObject& m_json;

//input and output classes for FridgeGenie
   ArduinoInput m_input;
   ArduinoOutput m_output;
};

#endif
