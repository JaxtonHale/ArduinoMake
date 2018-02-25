#include "FoodList.h"
#define SIZE 30
FoodData* food_datas = new FoodData[SIZE];

FoodList::FoodList()
{
  clear_bool();
}
FoodList::~FoodList()
{
  delete [] food_datas;
}

int FoodList::add_item(FoodData& fi)
{

  fi.id = next_free_id();
  food_datas[fi.id] = fi;
  return fi.id;
}

int FoodList::put_item(int id, FoodData fi)
{
  food_datas[id] = fi;
}

int FoodList::remove_item(FoodData fi)
{
  for(int i = 0; i<SIZE; i++)
  {
    if(food_datas[i]==fi)
    {
      food_datas[i]=0;
    }
  }
}

int FoodList::remove_item(int id)
{
  food_datas[id]=0;
}

int FoodList::next_free_id()
{
  for(int i = 0; i<SIZE; i++)
  {
    if(food_datas[i]==0)
    {
      return i;
    }
  }
}

bool FoodList::is_free(int id)
{
  if(food_datas[id]==0)return true;
}

FoodData* FoodList::get_bool_array()
{
  return food_datas;
}

void FoodList::clear_bool()
{
  for(int i = 0; i<SIZE; i++)
  {
    food_datas[i]=0;
  }
}

