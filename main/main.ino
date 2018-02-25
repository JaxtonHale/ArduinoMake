//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"
#include "pins.h"

//const int MENU_LCD_PIN = 1


void setup()
{
  //init();
  //StaticJsonBuffer<JSON_SIZE> jsonBuffer;
//  root = jsonBuffer.createObject();
  //pinMode(Pin::MENU_LCD, OUTPUT);
  //pinMode(Pin::STATUS_LCD, OUTPUT);
}
void loop()
{
  FridgeGenie::instance()->run();
  delay(200);
}
