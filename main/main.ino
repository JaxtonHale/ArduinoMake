const int button = 2;       // connect a button
const int buzzer = 4;       // connect a buzzer
const int light = 3;
const int funnylight = A0;

#include "Grove_LED_Bar.h"
Grove_LED_Bar bar(9, 8, true);

void setup()
{
    pinMode(button, INPUT); //set button as an INPUT device
    pinMode(buzzer, OUTPUT);   //set LED as an OUTPUT device
    pinMode(light, OUTPUT);
    pinMode(funnylight, OUTPUT);
    

   bar.begin();
}
void loop()
{
  //bar.setLevel(1);
  /*
   
   
    int btn = digitalRead(button); //read the status of the button
    digitalWrite(buzzer, btn);
    digitalWrite(light, btn);
   // digitalWrite(funnylight, 0);
    delay(10);
    */

    for(int i=0; i<=10; i++)
    {
//      bar.setLevel(i);
      delay(100);
    }
    
}
