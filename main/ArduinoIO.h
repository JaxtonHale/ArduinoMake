//#include <rgb_lcd.h>
//#include <Grove_LED_Bar.h>

#ifndef ARDUINO_IO_H
#define ARDUINO_IO_H

#include "rgb_lcd.h"

typedef rgb_color unsigned int;

class ArduinoInput
{
public:
//checks a few of the pins for input (eg: button press)
  void check_for_input();
  
private:
//called by check_for_input ... handles the input and performs the appropriate operations
  void handle_input(int pin);
};

class ArduinoOutput
{
public:

//constructor

  ArduinoOutput();

//display stuff on all the lcd screens (calls other functions)
  void draw_all();
  
private:

  rgb_lcd m_status_lcd;
  rgb_lcd m_menu_lcd;

  const rgb_color BACKLIGHT_R = 255;
  const rgb_color BACKLIGHT_G = 255;
  const rgb_color BACKLIGHT_B = 255;

  const size_t NUM_COLS = 16;
  const size_t NUM_ROWS = 2;

//display stuff on the lcd "fridge status" screen
  void draw_lcd_status();

//display stuff on the lcd menu screen
  void draw_lcd_menu();

};

#endif
