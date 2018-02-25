#define byte uint8_t

#include "ArduinoIO.h"
#include "pins.h"
#include <Wire.h>
#include "FridgeGenie.h"

OperationMode operation_mode = OperationMode::ADD;
JsonObject::iterator iter;

void ArduinoInput::check_for_input()
{
  //really messy and bad function zzz
  bool up_pressed = DigitalRead(UP_BUTTON);
  bool down_pressed = DigitalRead(DOWN_BUTTON);
  bool cancel_pressed = DigitalRead(CANCEL_BUTTON);
  bool enter_pressed = DigitalRead(ENTER_BUTTON);

  if (up_pressed) up_pressed();
  if (down_pressed) down_pressed(DOWN_BUTTON);
  if (cancel_pressed) cancel_pressed(CANCEL_BUTTON);
  if (enter_pressed) enter_pressed(ENTER_BUTTON);
}

void ArduinoInput::up_pressed()
{
  
}

void ArduinoInput::down_pressed()
{
  
}

void ArduinoInput::cancel_pressed()
{
  
}

void ArduinoInput::enter_pressed()
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

  FridgeGenie* ptr = FridgeGenie::instance();
  auto it = ptr->m_json.begin();
}
  
void ArduinoOutput::draw_main_menu()
{
  m_lcd.setCursor(0, 0);
  m_lcd.setCursor(1, 0);
}



