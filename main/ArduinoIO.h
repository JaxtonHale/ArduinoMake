#ifndef ARDUINO_IO_H
#define ARDUINO_IO_H

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
//display stuff on all the lcd screens (calls other functions)
  void draw_all();
  
private:

//display stuff on the lcd "fridge status" screen
  void draw_lcd_status();

//display stuff on the lcd menu screen
  void draw_lcd_menu();
};

#endif
