#ifndef ARDUINO_IO_H
#define ARDUINO_IO_H

class ArduinoInput
{
public:
  void check_for_input();
private:
  void handle_input(int pin);
};

class ArduinoOutput
{
public:
  void draw_lcd_status();
  void draw_lcd_menu();
private:

};

#endif
