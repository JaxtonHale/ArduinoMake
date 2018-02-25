#define byte uint8_t

#include "ArduinoIO.h"
#include "Arduino.h"
#include "pins.h"
#include <Wire.h>
#include "FridgeGenie.h"
#include "List.h"

//sorry this is semi incomplete
//No worries bro
char* default_vals = new char[5];
List<char> food_list(default_vals, 5, 5, default_vals[0]);
OperationMode operation_mode = OperationMode::STATUS;
int active_item = 0;
int menu_size = 0;

char* add_menu_options[] = {"Meat","Vegetables","Dairy"};
char* add_menu_options_meat[] = {"Cooked", "Uncooked", "Canned"};
char* add_menu_options_vegetables[] = {"Artichokes", "Beets", "Asparagus", "Broccoli", "Cucumbers", "Tomatoes"};
char* add_menu_options_dairy[] = {"Butter/Margarine", "Buttermilk", "Yogurt", "Milk"};
//char* add_menu_options_ars[][3] = {*add_menu_options_meat, *add_menu_options_vegetables, *add_menu_options_dairy};
char* add_menu_options_meat_cooked[] = {"Ham", "Poultry", "Sausage"};
char* add_menu_options_meat_uncooked[] = {"Steaks/Roasts", "Poultry", "Sausage", "Bacon", "Lunch Meat"};
char* add_menu_options_meat_canned[] = {"Ham"};

char* selected_menu[20];


//JsonObject::iterator G::iter;
void read_json()
{
    //Hardcoding for now
    
//  FridgeGenie* ptr = FridgeGenie::instance();
//  JsonObject::iterator iter;  
//  for(iter = ptr->m_json.begin(); iter != ptr->m_json.end(); iter++)
//  {
//    Serial.println("This prints");
//  }
//  for(int i = 0; i<ptr->m_json.size(); i++)
//  {
//    food_list.add(iter->key);
//    iter++;
//  }
}

void ArduinoInput::check_for_input()
{
  //really messy and bad function zzz
  //*a finely written function
  if (digitalRead(Pin::UP_BUTTON)) up_pressed();
  if (digitalRead(Pin::DOWN_BUTTON)) down_pressed();
  if (digitalRead(Pin::CANCEL_BUTTON)) cancel_pressed();
  if (digitalRead(Pin::ENTER_BUTTON)) enter_pressed();
}

void ArduinoInput::up_pressed()
{
  if(operation_mode == OperationMode::STATUS)
  {
    operation_mode = OperationMode::ADD;
    active_item = 0;
  }
  if(operation_mode == OperationMode::ADD)
  {
    if(active_item==0)
    {
      active_item = menu_size-1;
    }
    else
    {
      active_item--;
    }
  }
}

void ArduinoInput::down_pressed()
{
  if(operation_mode == OperationMode::STATUS)
  {
    operation_mode = OperationMode::ADD;
    active_item = 0;
  }
  if(operation_mode == OperationMode::ADD)
  {
    if(active_item==menu_size-1)
    {
      active_item = 0;
    }
    else
    {
      active_item++;
    }
  }
}

void ArduinoInput::cancel_pressed()
{
  if(operation_mode == OperationMode::STATUS)
  {
    operation_mode = OperationMode::ADD;
    active_item = 0;
  }
  if(operation_mode == OperationMode::ADD)
  {
    if(menu_size==0)
    {
      
    }
    if(selected_menu[0] == "Meat")
    {
      memcpy(selected_menu, add_menu_options, sizeof(add_menu_options));
      menu_size = sizeof(add_menu_options)/sizeof(add_menu_options[0]);
      active_item = 0;
      return;
    }
    else if(selected_menu[0] == "Cooked")
    {
      memcpy(selected_menu, add_menu_options_meat, sizeof(add_menu_options_meat));
      menu_size = sizeof(add_menu_options_meat)/sizeof(add_menu_options_meat[0]);
      active_item = 0;
      return;
    }
  }
}

void ArduinoInput::enter_pressed()
{
  //temp
  if(operation_mode == OperationMode::STATUS)
  {
    operation_mode = OperationMode::ADD;
    active_item = 0;
  }
  if(operation_mode == OperationMode::ADD)
  {
    if(menu_size==0)
    {
      memcpy(selected_menu, add_menu_options, sizeof(add_menu_options));
      menu_size = sizeof(add_menu_options)/sizeof(add_menu_options[0]);
      active_item = 0;
      return;
    }
    if(selected_menu[0] == "Meat")
    {
      if(active_item == 0)
      {
        memcpy(selected_menu, add_menu_options_meat, sizeof(add_menu_options_meat));
        menu_size = sizeof(add_menu_options_meat)/sizeof(add_menu_options_meat[0]);
        active_item = 0;
      }
      else if(active_item == 1)
      {
        memcpy(selected_menu, add_menu_options_vegetables, sizeof(add_menu_options_vegetables));
        menu_size = sizeof(add_menu_options_vegetables)/sizeof(add_menu_options_vegetables[0]);
        active_item = 0;
      }
      else if(active_item == 2)
      {
        memcpy(selected_menu, add_menu_options_dairy, sizeof(add_menu_options_dairy));
        menu_size = sizeof(add_menu_options_dairy)/sizeof(add_menu_options_dairy[0]);
        active_item = 0;
      }
    }
    else if(selected_menu[0] == "Cooked")
    {
      if(active_item == 0)
      {
        memcpy(selected_menu, add_menu_options_meat_cooked, sizeof(add_menu_options_meat_cooked));
        menu_size = sizeof(add_menu_options_meat_cooked)/sizeof(add_menu_options_meat_cooked[0]);
        active_item = 0;
      }
      else if(active_item == 1)
      {
        memcpy(selected_menu, add_menu_options_meat_uncooked, sizeof(add_menu_options_meat_uncooked));
        menu_size = sizeof(add_menu_options_meat_uncooked)/sizeof(add_menu_options_meat_uncooked[0]);
        active_item = 0;
      }
      else if(active_item == 2)
      {
        memcpy(selected_menu, add_menu_options_meat_canned, sizeof(add_menu_options_meat_canned));
        menu_size = sizeof(add_menu_options_meat_canned)/sizeof(add_menu_options_meat_canned[0]);
        active_item = 0;
      }
    }
  }
//    JsonObject& subheaders = (FridgeGenie::instance())->m_json[iter->key];
//    active_item == iter->key;
//    ++iter;
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
  m_lcd.print("9:03AM 2/25/2018");

  
}


void ArduinoOutput::draw_deletion_screen()
{
  if (m_old_operation_mode != operation_mode)
  {
//    FridgeGenie* ptr = FridgeGenie::instance();
//    iter = ptr->m_json.begin(); 
//    m_old_operation_mode = operation_mode;
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
  if (m_old_operation_mode != operation_mode)
  {
    
//    FridgeGenie* ptr = FridgeGenie::instance();
//    iter = ptr->m_json.begin(); 
    m_old_operation_mode = operation_mode;  
  }
  
  m_lcd.setCursor(0, 0);
  m_lcd.write((unsigned char)1);
  m_lcd.print(": ADD ");
  m_lcd.write((unsigned char)2);
  m_lcd.print(": MENU");
  m_lcd.setCursor(0, 1);

  
  m_lcd.print(selected_menu[active_item]);
  m_lcd.print("         ");
  
 
}
  
void ArduinoOutput::draw_main_menu()
{
  m_lcd.setCursor(0, 0);
  m_lcd.setCursor(1, 0);
}



