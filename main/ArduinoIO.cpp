#include "ArduinoIO.h"
//#include "DateTime.h"
//#include "DateTimeStrings.h"

void ArduinoInput::check_for_input()
{
  
}

void ArduinoInput::handle_input(int pin)
{
  
}


ArduinoOutput::ArduinoOutput()
{
  //set number of columns and rows the lcd will have and color of backlight
  m_status_lcd.begin(NUM_COLS, NUM_ROWS);
  m_status_lcd.setRGB(BACKLIGHT_R, BACKLIGHT_G, BACKLIGHT_B);
  

  //same thing as above but for menu lcd
  m_menu_lcd.begin(NUM_COLS, NUM_ROWS);
  m_menu_lcd.setRGB(BACKLIGHT_R, BACKLIGHT_G, BACKLIGHT_B);
}

void ArduinoOutput::draw_all()
{
  draw_lcd_status();
  draw_lcd_menu();
}

void ArduinoOutput::draw_lcd_status()
{
  //reset cursor position for printing
  m_status_lcd.setCursor(0, 0);
}
void ArduinoOutput::draw_lcd_menu()
{
  //reset cursor position for printing
  m_status_lcd.setCursor(0, 0); 
}




