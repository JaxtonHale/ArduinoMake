#define byte uint8_t

#include "ArduinoIO.h"
#include "Arduino.h"
#include "pins.h"
#include <Wire.h>
#include "FridgeGenie.h"

OperationMode G::operation_mode = OperationMode::ADD;
JsonObject::iterator G::iter;
String G::active_item;

void ArduinoInput::check_for_input()
{
  //really messy and bad function zzz
  
  if (digitalRead(Pin::UP_BUTTON)) up_pressed();
  if (digitalRead(Pin::DOWN_BUTTON)) down_pressed();
  if (digitalRead(Pin::CANCEL_BUTTON)) cancel_pressed();
  if (digitalRead(Pin::ENTER_BUTTON)) enter_pressed();
}

void ArduinoInput::up_pressed()
{
 // G::iter--;
}

void ArduinoInput::down_pressed()
{
  G::iter++;
}

void ArduinoInput::cancel_pressed()
{
  
}

void ArduinoInput::enter_pressed()
{
    JsonObject& subheaders = (FridgeGenie::instance())->m_json[G::iter->key()];
    G::active_item += G::iter->key();
    G:iter++;
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
 
  
  if (G::operation_mode == OperationMode::STATUS)
  {
     draw_lcd_status();
  }
  else if (G::operation_mode == OperationMode::DELETE)
  {
     draw_deletion_screen();
  }
  else if (G::operation_mode == OperationMode::ADD)
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
  if (m_old_operation_mode != G::operation_mode)
  {
    FridgeGenie* ptr = FridgeGenie::instance();
    G::iter = ptr->m_json.begin(); 
    m_old_operation_mode = G::operation_mode;
  }
  
  m_lcd.setCursor(0, 0);
  m_lcd.write((unsigned char)1);
  m_lcd.print(": DEL ");
  m_lcd.write((unsigned char)2);
  m_lcd.print(": MENU");
  m_lcd.setCursor(1, 0);

  
}
  
void ArduinoOutput::draw_addition_screen()
{
  if (m_old_operation_mode != G::operation_mode)
  {
    FridgeGenie* ptr = FridgeGenie::instance();
    G::iter = ptr->m_json.begin(); 
    m_old_operation_mode = G::operation_mode;

    
  }
  
  m_lcd.setCursor(0, 0);
  m_lcd.write((unsigned char)1);
  m_lcd.print(": ADD ");
  m_lcd.write((unsigned char)2);
  m_lcd.print(": MENU");
  m_lcd.setCursor(1, 0);

 
}
  
void ArduinoOutput::draw_main_menu()
{
  m_lcd.setCursor(0, 0);
  m_lcd.setCursor(1, 0);
}



