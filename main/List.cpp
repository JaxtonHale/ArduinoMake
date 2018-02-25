#ifndef LIST_CPP
#define LIST_CPP
#include "List.h"

template <class T>
//i = starting array, min = minimum size, increment = amount list increases in size, EMPTY_OBJECT = object used for comparison of whether or not empty
List<T>::List(T* i, int min, int increment, T EMPTY_OBJECT)
{
  items = i;
  this->min = min;
  int i_size = sizeof(i)/sizeof(i[0]);
  size = min > i_size ? min : i_size;
  this->increment = increment;
  this->EMPTY_OBJECT = EMPTY_OBJECT;
}
template <class T>
List<T>::~List()
{
  delete [] items;
}
template <class T>
T List<T>::get(int i)
{
  return items[i];
}
template <class T>
void List<T>::set(int i, T item)
{
  ensure_size(i);
  items[i] = item;
}
template <class T>
void List<T>::add(T item)
{
  items[next_index()] = item;
}
template <class T>
int List<T>::next_index()
{
  for(int i = 0; i<size; i++)
  {
    if(items[i]==EMPTY_OBJECT)
    {
      return i;
    }
  }
}
template <class T>
int List<T>::get_size()
{
  return size;
}
template <class T>
int List<T>::get_increment()
{
  return increment;
}
template <class T>
void List<T>::set_increment(int inc)
{
  increment = inc;
}
template <class T>
void List<T>::ensure_size(int i)
{
  while(size<i)
  {
    bump_size();
  }
}
template <class T>
void List<T>::bump_size()
{
  T* new_items = new T[size+increment];
  size+=increment;
}
#endif
