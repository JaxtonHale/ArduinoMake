//#include <LiquidCrystal.h>
#include "ArduinoJson.h"
#include "FridgeGenie.h"
#include "pins.h"
#include "HashMap.h"
//const int MENU_LCD_PIN = 1

const byte HASH_SIZE = 30;
void setup()
{
  Serial.begin(9600);
  HashType<char*,int> hashRawArray[HASH_SIZE];
  HashMap<char*,int> hashMap = HashMap<char*,int>( hashRawArray , HASH_SIZE );

  hashMap[0]("Value 1",2000);
  
  Serial.print(hashMap.getValueOf("Value 1"));

  //set up pins
  pinMode(Pin::UP_BUTTON, INPUT);
  pinMode(Pin::DOWN_BUTTON, INPUT);
  pinMode(Pin::CANCEL_BUTTON, INPUT);
  pinMode(Pin::ENTER_BUTTON, INPUT);
}
void loop()
{
  FridgeGenie::instance()->run();
  delay(200);
}
