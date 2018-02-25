#ifndef FOOD_MAP_H
#define FOOD_MAP_H
#include "FridgeGenie.h"
//#include "HashMap.h"
//  HashType<char*,int> hashRawArray[HASH_SIZE];
//  HashMap<char*,int> hashMap = HashMap<char*,int>( hashRawArray , HASH_SIZE );
//  hashMap[0]("Value 1",2000);
class FoodList
{
  public:
    FoodList();
    ~FoodList();
    int add_item(FoodData& fi);
    int put_item(int id, FoodData fi);
    int remove_item(FoodData fi);
    int remove_item(int id);
    int next_free_id();
    bool is_free(int id);
    FoodData* get_bool_array();
  private:
    void clear_bool();
};
#endif
