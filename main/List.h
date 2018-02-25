#ifndef LIST_H
#define LIST_H
template <class T>
class List
{
public:
  List(T* i, int min=5, int increment=5, const T EMPTY_OBJECT=0);
  ~List();
  T get(int i);
  void set(int i, T item);
  void set_increment(int inc);
  void add(T item);
  int get_size();
  int get_increment();

private:
  void bump_size();
  void ensure_size(int i);
  int next_index();
  T* items;
  T EMPTY_OBJECT;
  int min;
  int increment;
  int size;
};

#include "List.cpp"

#endif
