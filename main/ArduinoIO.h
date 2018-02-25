//#include <rgb_lcd.h>
//#include <Grove_LED_Bar.h>

#include "ArduinoJson.h"

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
extern int active_item;
extern char* add_menu_options[];
extern char* add_menu_options_meat[];
extern char* add_menu_options_meat_cooked[];
extern char* add_menu_options_meat_uncooked[];
extern char* add_menu_options_meat_canned[];
extern char* add_menu_options_vegetables[];
extern char* add_menu_options_dairy[];

extern char* selected_menu[];

//for status screen - used as cutoff to determine number of items close to expiration
const int days_until_expiration_cutoff;

//typedef rgb_color unsigned int;


//Read the json data in so we don't have to keep iterating...
void read_json();

//class to handle arduino input 
class ArduinoInput
{
public:
//checks a few of the pins for input (eg: button press)
  void check_for_input();
  
private:
//called by check_for_input ... handles the input and performs the appropriate operations
//  void handle_input(int pin);

  

//up button press
  void up_pressed();
//down button press
  void down_pressed();
//cancel button press
  void cancel_pressed();
//enter button press
  void enter_pressed();
};

//class that manages some things related to output, including printing to LCD
class ArduinoOutput
{
public:

//constructor

  ArduinoOutput();

//display stuff on all the lcd screens (calls other functions)
  void draw_all();
  
private:
/*
 old operation mode so we can see when the operation mode has changed.
 ideally this would let us determine when mode has been switched and reiterate over the appropriate data structure
 what I mean is that if we just switched to DELETE mode, we iterate over the already added items in the FridgeGenie hashmap.
 However, if it is in ADD mode it would iterate over the food list from the JSON. The idea isn't really fleshed out though...
 */

  OperationMode m_old_operation_mode;
  
  //object for the lcd
  rgb_lcd m_lcd;

//backlight rgb color values
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
