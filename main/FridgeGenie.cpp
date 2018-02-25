#include "FridgeGenie.h"

FridgeGenie* FridgeGenie::m_p_instance = nullptr;

FridgeGenie::FridgeGenie() : m_json(m_jsonBuffer.createObject())
{
  // create new json object using ArduinoJson library. These are being assigned to the number of days it takes for the item to expire (int).
  
  m_json["Meat"]["Cooked"]["Poultry"] = 3;
  m_json["Meat"]["Cooked"]["Sausage"] = 3;
  m_json["Meat"]["Uncooked"]["Sausage"] = 42;
  //m_json["Meat"]["Vacuum-packed Dinner"] = 14;
  m_json["Meat"]["Uncooked"]["Bacon"] = 14;
  //m_json["Meat"]["Hot Dogs"] = 14;
  m_json["Meat"]["Uncooked"]["Lunch Meat"] = 14;
  m_json["Meat"]["Cooked"]["Ham"] = 7;
  m_json["Meat"]["Canned"]["Ham"] = 270;
//  m_json["Meat"]["Cooked"]["Ham"]["Shelf-stable"] = 730;
 // m_json["Meat"]["Canned Meat"]["Shelf-stable"] = 730;
  m_json["Meat"]["Uncooked"]["Steaks/Roasts"] = 3;
  m_json["Meat"]["Uncooked"]["Poultry"] = 2;

  m_json["Dairy"]["Butter/Margarine"] = 30;
  m_json["Dairy"]["Buttermilk"] = 7;
  m_json["Dairy"]["Yogurt"] = 1;
  m_json["Dairy"]["Milk"] = 5;

  m_json["Vegetables"]["Artichokes"] = 2;
  m_json["Vegetables"]["Beets"] = 14;
  m_json["Vegetables"]["Asparagus"] = 2;
  m_json["Vegetables"]["Broccoli"] = 3;
  m_json["Vegetables"]["Cucumbers"] = 7;
  m_json["Vegetables"]["Tomatoes"] = 7;
  //ArduinoJson gave me too much trouble. Switched to hardcoding.
  
}

FridgeGenie::~FridgeGenie()
{
  if (m_p_instance != nullptr)
  {
    delete m_p_instance;  
  }
}

void FridgeGenie::run()
{
  m_input.check_for_input();
  m_output.draw_all();
}

FridgeGenie* FridgeGenie::instance()
{
  if (m_p_instance == nullptr)
  {
    m_p_instance = new FridgeGenie();
  }

  return m_p_instance;
}

