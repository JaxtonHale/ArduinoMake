//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"
#include "pins.h"
//#include "HashMap.h"
#include "FoodList.h"
//const int MENU_LCD_PIN = 1

//const byte HASH_SIZE = 30;
void setup()
{
  //set up pins
  pinMode(Pin::UP_BUTTON, INPUT);
  pinMode(Pin::DOWN_BUTTON, INPUT);
  pinMode(Pin::CANCEL_BUTTON, INPUT);
  pinMode(Pin::ENTER_BUTTON, INPUT);
  
//  FoodList m;
//  cycle_print(m.get_bool_array());

  
}
//void cycle_print(bool* a)
//{
//  for(int i = 0; i<30; i++)
//  {  
//    Serial.println(a[i]);
//  }
//}
void loop()
{
  FridgeGenie::instance()->run();
  delay(200);
}
