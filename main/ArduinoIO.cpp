#define byte uint8_t

#include "ArduinoIO.h"
#include "pins.h"
#include <Wire.h>

OperationMode operation_mode = OperationMode::ADD;

void ArduinoInput::check_for_input()
{
  
}

void ArduinoInput::handle_input(int pin)
{
  
}


ArduinoOutput::ArduinoOutput()
{
  //set number of columns and rows the lcd will have and color of backlight
  m_lcd.begin(NUM_COLS, NUM_ROWS);
  m_lcd.setRGB(BACKLIGHT_R, BACKLIGHT_G, BACKLIGHT_B);
  
  byte up_arrow[8] = { 0b00100, 0b01010, 0b10001, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100 };  
  byte down_arrow[8] = { 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b10001, 0b01010, 0b00100 };

  m_lcd.createChar(1, up_arrow);
  m_lcd.createChar(2, down_arrow);
}

void ArduinoOutput::draw_all()
{
  if (operation_mode == OperationMode::STATUS)
  {
     draw_lcd_status();
  }
  else if (operation_mode == OperationMode::DELETE)
  {
     draw_deletion_screen();
  }
  else if (operation_mode == OperationMode::ADD)
  {
    draw_addition_screen();
  }
}

void ArduinoOutput::draw_lcd_status()
{
  //reset cursor position for printing
  m_lcd.setCursor(0, 0);
  m_lcd.print("ease status");

  
}


void ArduinoOutput::draw_deletion_screen()
{
  m_lcd.setCursor(0, 0);
  m_lcd.write((unsigned char)1);
  m_lcd.print(": DEL ");
  m_lcd.write((unsigned char)2);
  m_lcd.print(": MENU");
  m_lcd.setCursor(1, 0);

  
}
  
void ArduinoOutput::draw_addition_screen()
{
  m_lcd.setCursor(0, 0);
  m_lcd.write((unsigned char)1);
  m_lcd.print(": ADD ");
  m_lcd.write((unsigned char)2);
  m_lcd.print(": MENU");
  m_lcd.setCursor(1, 0);

  auto it = 
}
  
void ArduinoOutput::draw_main_menu()
{
  m_lcd.setCursor(0, 0);
  m_lcd.setCursor(1, 0);
}



