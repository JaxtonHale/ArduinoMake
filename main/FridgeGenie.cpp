#include "FridgeGenie.h"

FridgeGenie* FridgeGenie::m_p_instance = nullptr;

FridgeGenie::FridgeGenie() : m_json(m_jsonBuffer.createObject())
{
  m_json["Meat"]["Poultry"]["Cooked"] = 3;
  m_json["Meat"]["Sausage"]["Cooked"] = 3;
  m_json["Meat"]["Sausage"]["Uncooked"] = 42;
  m_json["Meat"]["Vacuum-packed Dinner"] = 14;
  m_json["Meat"]["Bacon"] = 14;
  m_json["Meat"]["Hot Dogs"] = 14;
  m_json["Meat"]["Lunch Meat"] = 14;
  m_json["Meat"]["Ham"]["Cooked"] = 7;
  m_json["Meat"]["Ham"]["Canned"] = 270;
  m_json["Meat"]["Ham"]["Cooked"]["Shelf-stable"] = 730;
  m_json["Meat"]["Canned Meat"]["Shelf-stable"] = 730;
  m_json["Meat"]["Steaks/Roasts"] = 3;
  m_json["Meat"]["Chicken/Turkey/Game Birds"] = 2;

  m_json["Dairy"]["Butter/Margarine"] = 30;
  m_json["Dairy"]["Buttermilk"] = 7;
  m_json["Dairy"]["Yogurt"] = 1;
  m_json["Dairy"]["Milk"]["Fluid"] = 5;

  m_json["Vegetables"]["Artichokes"] = 2;
  m_json["Vegetables"]["Beets"] = 14;
  m_json["Vegetables"]["Asparagus"] = 2;
  m_json["Vegetables"]["Broccoli"] = 3;
  m_json["Vegetables"]["Cucumbers"] = 7;
  m_json["Vegetables"]["Tomatoes"] = 7;
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

