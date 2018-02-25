//#include <rgb_lcd.h>
//#include <Grove_LED_Bar.h>

#ifndef ARDUINO_IO_H
#define ARDUINO_IO_H

#include "rgb_lcd.h"

//enum class to store modes of operation 
enum class OperationMode
{
  STATUS,
  DELETE,
  ADD,
  MENU
};

//global variable - messy - oh well
extern OperationMode operation_mode;

const int days_until_expiration_cutoff;

//typedef rgb_color unsigned int;

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

  rgb_lcd m_lcd;

  const unsigned int BACKLIGHT_R = 255;
  const unsigned int BACKLIGHT_G = 255;
  const unsigned int BACKLIGHT_B = 255;

  const size_t NUM_COLS = 16;
  const size_t NUM_ROWS = 2;

//display stuff on the lcd "fridge status" screen
  void draw_lcd_status();

//display deletion menu for removing items from the active items hashmap
  void draw_deletion_screen();
  
//display addition menu for adding items to the active items hashmap
  void draw_addition_screen();

//display main menu
  void draw_main_menu();

};

#endif
