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
  Serial.begin(9600);
//  HashType<char*,int> hashRawArray[HASH_SIZE];
//  HashMap<char*,int> hashMap = HashMap<char*,int>( hashRawArray , HASH_SIZE );
//  hashMap[0]("Value 1",2000);
//  Serial.print(hashMap.getValueOf("Value 1"));
  
  FoodList m;
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
